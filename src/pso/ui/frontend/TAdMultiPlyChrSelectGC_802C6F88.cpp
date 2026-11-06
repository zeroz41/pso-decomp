#include "types.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802C6F88.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"

extern "C" {

s32 TAdMultiPlyChrSelectGC::get_field_20() { return this->m_20; }

    extern int TAdMultiPlyChrSelectGC__instance;
int TAdMultiPlyChrSelectGC::get_state() {  return TAdMultiPlyChrSelectGC__instance; }

    extern int plyplt_anim_ctrl_instance;
int TAdMultiPlyChrSelectGC::get_selected_slot() {  return plyplt_anim_ctrl_instance; }

    extern int menu_selection_cursor_texture_list;
int TAdMultiPlyChrSelectGC::get_global_6700() {  return menu_selection_cursor_texture_list; }

    extern int lbl_805D6668;
int TAdMultiPlyChrSelectGC__sub_802C6FA8(void) {  return lbl_805D6668; }

extern u32 lbl_805D67E8;

void TAdMultiPlyChrSelectGC::update_transition_anim_if_active() {
    if ((u32) lbl_805D67E8 != 0U) {
        ((TAdMultiPlyChrSelectGC *)lbl_805D67E8)->update_transition_anim();
    }
}


void TAdMultiPlyChrSelectGC::update_transition_anim() {
    f32 var_f31;
    f32 var_f4;
    s32 temp_r3;
    s32 temp_r3_2;

    temp_r3 = *(s32 *)&this->m_40;
    if (temp_r3 <= 0x96) {
        var_f4 = 1.0f;
        var_f31 = (15.0f - (f32) temp_r3) / 15.0f;
    } else {
        temp_r3_2 = temp_r3 - 0x96;
        var_f31 = 1.0f;
        var_f4 = (15.0f - (f32) temp_r3_2) / 15.0f;
    }
    TLobby__sub_8001EA5C(*(f32 *)&this->m_1c, *(f32 *)&this->m_20, -1.5f, var_f4);
    TLobby__sub_8001E998(this->m_2c, *(f32 *)&this->unk_30, -1.5f, var_f31);
}

}
