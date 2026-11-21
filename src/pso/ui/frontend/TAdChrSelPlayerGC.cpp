#include "types.h"
#include "pso/ui/TUnk_804E3008.h"
#include "pso/ui/frontend/TAdPlyStatusGC.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

extern "C" { extern char lbl_804728D0[]; }
const char *lbl_805D3F78 = lbl_804728D0;
extern "C" {

s32 sub_802E0CB0__13TUnk_804E3008Fv(void *, s32);


void TUnk_804E3008::sub_802E0F58(s32 arg1) {
    this->m_name = lbl_805D3F78;
    state = 0;
    this->m_100 = 0;
    this->m_110 = 0;
    *(s32 *)((s8 *)this + 0x104) = arg1;
    this->m_170 = 0;
    *(s32 *)&this->joint_matrices = (saddr)mem_alloc(0xC00);
    TAdPlyStatusGC::get_instance((saddr)this, (s32)arg1);
    sub_802E0CB0__13TUnk_804E3008Fv(this, *(s32 *)((s8 *)this + 0x104));
}

}
