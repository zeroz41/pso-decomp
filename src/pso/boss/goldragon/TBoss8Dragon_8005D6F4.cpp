#include "types.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

int TBoss5Gryphon::get_flag_bit6() { return (this->m_4c0 >> 6) & 0x1; }
