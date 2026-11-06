#include "types.h"
#include "pso/ui/window/TWindowSubCustomSelect_80275D84.h"
#include "pso/ui/window/TWindowSubCustomSelect.h"
#include "pso/ui/window/TWindowSubCustomEquip.h"

int TWindowSubCustomSelect::is_active() { return this->m_73 & 0x1; }
int fn_80275D90(void* p) { return *(u8*)((char*)p + 0x73) & 0x2; }
