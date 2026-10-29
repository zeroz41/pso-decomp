#include "types.h"
#include "pso/ui/TUnk_804E3008.h"
#include "pso/ui/TAdPlyStatusGC.h"

extern "C" {

void *mem_alloc(u32 size);
s32 sub_802E0CB0__13TUnk_804E3008Fv(void *, s32);

extern s32 lbl_805D3F78;

void TUnk_804E3008::sub_802E0F58(s32 arg1) {
    *(s32 *)&this->m_name = (s32) lbl_805D3F78;
    *(s32 *)((s8 *)this + 0xFC) = 0;
    this->m_100 = 0;
    this->m_110 = 0;
    *(s32 *)((s8 *)this + 0x104) = arg1;
    this->m_170 = 0;
    *(s32 *)&this->joint_matrices = (s32)mem_alloc(0xC00);
    TAdPlyStatusGC::get_instance((s32)this, (s32)arg1);
    sub_802E0CB0__13TUnk_804E3008Fv(this, *(s32 *)((s8 *)this + 0x104));
}

}
