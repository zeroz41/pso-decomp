#include "types.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802E0064.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"

extern "C" {
s32 TAdMultiPlyChrSelectGC__sub_802DFFE8();

void TAdMultiPlyChrSelectGC::set_field_4ec(s32 v) { *(s32*)((char*)this + 0x4ec) = v; }

    extern int multi_ply_chr_select_active_player;
    extern int TAdMultiPlyChrSelectGC__selected_slot;

void TAdMultiPlyChrSelectGC__sub_802E006C(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)arg0 + 0x4F4) = arg1;
    *(s32 *)((s8 *)arg0 + 0x4F0) = arg2;
}

void TAdMultiPlyChrSelectGC::restore_selection() { TAdMultiPlyChrSelectGC__selected_slot = multi_ply_chr_select_active_player; }

void TAdMultiPlyChrSelectGC::update_field_4E8() {
    *(s32 *)((s8 *)this + 0x4E8) = TAdMultiPlyChrSelectGC__sub_802DFFE8();
}
s32 TAdMultiPlyChrSelectGC::get_field_0x530() { return *(s32*)((char*)this + 0x530); }
void TAdMultiPlyChrSelectGC::set_field_1c(s32 v) { this->m_1c = v; }
s32 TAdMultiPlyChrSelectGC::get_mode() { return this->m_1c; }

    extern int lbl_805D6E78;

s32 TAdMultiPlyChrSelectGC::is_state_closing() {
    TAdMultiPlyChrSelectGC *self = this;
    switch (self->m_1c) {
    case 6:
    case 8:
    case 9:
    case 10:
    case 11:
        return 1;
    }
    return 0;
}

int TAdMultiPlyChrSelectGC::get_global_state() {  return lbl_805D6E78; }

    extern int lbl_805D384C;
int TAdMultiPlyChrSelectGC::get_select_flag() {  return lbl_805D384C; }

}
