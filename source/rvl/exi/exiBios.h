#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80167e78..0x80167f68
UNKNOWN_FUNCTION(SetExiInterruptMask);
// PAL: 0x80167f68..0x801681e4
UNKNOWN_FUNCTION(EXIImm);
// PAL: 0x801681e4..0x80168288
UNKNOWN_FUNCTION(EXIImmEx);
// PAL: 0x80168288..0x80168380
UNKNOWN_FUNCTION(EXIDma);
// PAL: 0x80168380..0x801685fc
UNKNOWN_FUNCTION(EXISync);
// PAL: 0x801685fc..0x80168680
UNKNOWN_FUNCTION(EXISetExiCallback);
// PAL: 0x80168680..0x80168800
UNKNOWN_FUNCTION(__EXIProbe);
// PAL: 0x80168800..0x80168918
UNKNOWN_FUNCTION(EXIAttach);
// PAL: 0x80168918..0x801689d0
UNKNOWN_FUNCTION(EXIDetach);
// PAL: 0x801689d0..0x80168b00
UNKNOWN_FUNCTION(EXISelect);
// PAL: 0x80168b00..0x80168c00
UNKNOWN_FUNCTION(EXIDeselect);
// PAL: 0x80168c00..0x80168cb8
UNKNOWN_FUNCTION(EXIIntrruptHandler);
// PAL: 0x80168cb8..0x80168ed0
UNKNOWN_FUNCTION(TCIntrruptHandler);
// PAL: 0x80168ed0..0x80168fa0
UNKNOWN_FUNCTION(EXTIntrruptHandler);
// PAL: 0x80168fa0..0x80169164
UNKNOWN_FUNCTION(EXIInit);
// PAL: 0x80169164..0x80169260
UNKNOWN_FUNCTION(EXILock);
// PAL: 0x80169260..0x80169338
UNKNOWN_FUNCTION(EXIUnlock);
// PAL: 0x80169338..0x80169360
UNKNOWN_FUNCTION(UnlockedHandler);
// PAL: 0x80169360..0x8016970c
UNKNOWN_FUNCTION(EXIGetID);

#ifdef __cplusplus
}
#endif