#include "types.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

int TBoss5Gryphon::get_flag_bit6() { return (this->flags >> 6) & 0x1; }
