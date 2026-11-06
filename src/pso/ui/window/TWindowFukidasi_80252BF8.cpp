#include "types.h"
#include "pso/ui/window/TUnk_804CF0B8.h"
#include "pso/ui/window/TWindowFukidasi.h"
#include "pso/ui/window/TWindowGetComCard.h"

void TUnk_804CF0B8::set_flag2c_bit100() { this->m_2c |= 0x100; }
void TUnk_804CF0B8::clear_flag2c_bit200() { this->m_2c &= 0xfffffdff; }
void TUnk_804CF0B8::set_flag2c_bit200() { this->m_2c |= 0x200; }
void TUnk_804CF0B8::clear_flag2c_bit100() { this->m_2c &= 0xfffffeff; }
