import argparse
from dataclasses import dataclass
from pathlib import Path
import re
import sys
from typing import Generator, Optional

from elftools.elf.elffile import ELFFile
from elftools.elf.sections import StringTableSection, Symbol as ELFSymbol

from mkwutil.lib.symbols import Symbol, SymbolsList


MATCH_DOLLAR_THING = re.compile(r"^\w+\$\d+$")


def process_symbol(sym: ELFSymbol, strtab: StringTableSection) -> Optional[Symbol]:
    sym_type = sym.entry["st_info"]["type"]
    sym_bind = sym.entry["st_info"]["bind"]
    sym_name = strtab.get_string(sym["st_name"])
    sym_shndx = sym.entry["st_shndx"]
    if len(sym_name) == 0:
        return
    if not sym_type in ("STT_FUNC", "STT_OBJECT"):
        return
    if sym_shndx != 1:
        return
    if not sym_bind in ("STB_GLOBAL", "STB_WEAK"):
        return
    # Output
    addr = sym["st_value"] + 0x8051_03B4
    if not (0x8000_0000 <= addr < 0x8100_0000):
        return
    size = sym["st_size"]
    return Symbol(addr, sym_name, size)


def symbols_from_elf(elf: ELFFile) -> SymbolsList:
    strtab = elf.get_section_by_name(".strtab")  # String table
    symtab = elf.get_section_by_name(".symtab")  # Symbol table

    symbols = SymbolsList()

    for elf_sym in symtab.iter_symbols():
        sym = process_symbol(elf_sym, strtab)
        if not sym:
            continue
        symbols.put(sym)

    return symbols


def process_elf(elf: ELFFile, out):
    symbols = symbols_from_elf(elf)
    symbols.write_to(out)


def main():
    parser = argparse.ArgumentParser(
        description="Dumps symbols in ELF to symbols.txt format"
    )
    parser.add_argument("elf", type=Path)
    parser.add_argument(
        "-o",
        "--output",
        type=Path,
        required=False,
        help="Path to output symbol list to",
    )
    args = parser.parse_args()

    with open(args.elf, "rb") as file:
        elf = ELFFile(file)
        if args.output:
            with open(args.output, "w", newline="") as out_file:
                process_elf(elf, out_file)
        else:
            process_elf(elf, sys.stdout)


if __name__ == "__main__":
    main()
