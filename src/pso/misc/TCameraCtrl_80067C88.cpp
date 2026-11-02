#include "types.h"
#include "pso/misc/TUnk_80488E00.h"
#include "pso/misc/TUnk_804887F8.h"
#include "pso/misc/TCameraCtrl.h"

extern "C" {

int construct_view_controller__11TCameraCtrlFPv(void);

    extern unsigned char lbl_804887F8[];
void*TUnk_804887F8::init() { construct_view_controller__11TCameraCtrlFPv(); *(int*)((char*)this + 0x18) = (int)lbl_804887F8; this->m_38 = 21; this->m_58 = 0.65f; this->m_114 = 0; (*(int *)((u8 *)this + 0x110)) = 0; return this; }

void TUnk_80488E00::vfunc_14(s32 v) { this->m_10c = v; }

}
