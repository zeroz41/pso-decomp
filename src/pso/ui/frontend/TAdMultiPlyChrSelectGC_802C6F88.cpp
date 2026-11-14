#include "types.h"
#include <stddef.h>
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802C6F88.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/TUnk_804E0B28.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby.h"

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

TWindowBase *TWindowSubStatusDisp__ct(void *storage, s32 client);
TWindowBase *update_display__20TWindowSubSymbolChatFl(void (*callback)());

}

TUnk_804E0B28 *lbl_805D67E8;

void TUnk_804E0B28::update_transition_anim_if_active() {
    if (lbl_805D67E8 != NULL) {
        lbl_805D67E8->update_transition_anim();
    }
}

void TUnk_804E0B28::update_transition_anim() {
    f32 var_f31;
    f32 var_f4;
    s32 temp_r3;
    s32 temp_r3_2;

    temp_r3 = this->timer;
    if (temp_r3 <= 0x96) {
        var_f4 = 1.0f;
        var_f31 = (15.0f - (f32) temp_r3) / 15.0f;
    } else {
        temp_r3_2 = temp_r3 - 0x96;
        var_f31 = 1.0f;
        var_f4 = (15.0f - (f32) temp_r3_2) / 15.0f;
    }
    TLobby__sub_8001EA5C(this->position0X, this->position0Y, -1.5f, var_f4);
    TLobby__sub_8001E998(this->position1X, this->position1Y, -1.5f, var_f31);
}

void TUnk_804E0B28::render() {  }

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
void TUnk_804E0B28::run_task() {
    this->position0X = 0.1f * (this->target0X - this->position0X) + this->position0X;
    this->position0Y = 0.1f * (this->target0Y - this->position0Y) + this->position0Y;
    this->position1X = 0.1f * (this->target1X - this->position1X) + this->position1X;
    this->position1Y = 0.1f * (this->target1Y - this->position1Y) + this->position1Y;
    if (get_main_phase() == 15) {
        switch (this->timer) {
        case 150:
            this->position1X = 650.0f;
            this->position1Y = 425.0f;
            this->target1X = 616.0f + TLobby::calc_result_offset();
            this->target1Y = 425.0f;
            break;
        case 300:
            this->position0X = 650.0f;
            this->position0Y = 425.0f;
            this->target0X = 616.0f + TLobby::calc_phase_offset();
            this->target0Y = 425.0f;
            this->timer = 0;
            break;
        }
        ++this->timer;
    }
}
#pragma pop

TUnk_804E0B28::~TUnk_804E0B28() {
    if (this->callback != NULL) {
        this->callback->close();
        this->callback = NULL;
    }
    if (this->statusWindow != NULL) {
        this->statusWindow->close();
        this->statusWindow = NULL;
    }
    lbl_805D67E8 = NULL;
}

TUnk_804E0B28::TUnk_804E0B28(TObject *parent, s32 client) : TObject(parent) {
    this->parent = parent;
    this->position0X = 650.0f;
    this->position0Y = 425.0f;
    this->target0X = 616.0f + TLobby::calc_phase_offset();
    this->target0Y = 425.0f;
    this->position1X = 650.0f;
    this->position1Y = 425.0f;
    this->target1X = 650.0f;
    this->target1Y = 425.0f;
    this->client = client;
    this->timer = 0;
    lbl_805D67E8 = this;
    TWindowBase *window = (TWindowBase *)TObject::operator new(0x74);
    if (window) {
        window = TWindowSubStatusDisp__ct(window, this->client);
    }
    this->statusWindow = window;
    this->callback = update_display__20TWindowSubSymbolChatFl(update_transition_anim_if_active);
}
