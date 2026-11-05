#include "types.h"
#include "pso/enemy/TObjEneBalClaw.h"

void TObjEneBalClaw::set_attack_distance_flag() { this->m_388 |= 0x10000; }
int TObjEneBalClaw::get_flag_0x388_b24() { return (m_388 >> 24) & 0x1; }
