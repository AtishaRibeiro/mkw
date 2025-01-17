#include "Mii.hpp"

namespace System {

void Mii::init(s32 num) {
  this->_4 = num;
  this->_8 = 0;
  this->_9 = -1;
  this->_A4 = 0;
  this->_60 = (unkStruct){0xB8, 0x40, 0x30, 0xFF};
  this->_64 = 0;
  this->_C = 6;
  this->_A5 = 0;
  this->_A6 = 0;
}

} // namespace System
