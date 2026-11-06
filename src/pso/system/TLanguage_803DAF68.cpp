#include "types.h"
#include "pso/system/TLanguage.h"

struct Ent_803DAF70 { s32 a; s32 b; u8 *p; };

struct Tbl_803DAF70 { Ent_803DAF70 *arr; };

struct G_803DAF70 { u8 pad[0x20]; Tbl_803DAF70 *f20; };

extern u8 *current_render_context;

void TLanguage::set_index(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 8) = arg1;
}
#pragma push
#pragma scheduling off
#pragma peephole off
void TLanguage::set_entry_index(s32 i, s32 x) {
    ((TLanguage *)(((G_803DAF70 *)current_render_context)->f20->arr[i].p))->set_index(x);
}
#pragma pop
