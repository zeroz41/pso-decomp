#include "types.h"
#include <stddef.h>
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802C6F88.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/TAdMultiPlyChrSelectTransitionGC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/network/TLobby.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "pso/ui/frontend/TAdTitleTexGC.h"


s32 TAdMultiPlyChrSelectGC::get_field_20() { return state; }

TAdMultiPlyChrSelectGC *TAdMultiPlyChrSelectGC::get_state() {  return TAdMultiPlyChrSelectGC::instance; }

    extern int plyplt_anim_ctrl_instance;
saddr TAdMultiPlyChrSelectGC::get_selected_slot() {  return plyplt_anim_ctrl_instance; }

int TAdMultiPlyChrSelectGC::get_global_6700() {  return (saddr)menu_selection_cursor_texture_list; }

NJS_TEXLIST *get_player_tex_texture_list(void) {  return player_tex_texture_list_ptr; }


TAdMultiPlyChrSelectTransitionGC *multi_chr_select_transition_instance;

extern "C" void update_transition_anim_if_active(void *, void *) {
    if (multi_chr_select_transition_instance != NULL) {
        multi_chr_select_transition_instance->update_transition_anim();
    }
}

void TAdMultiPlyChrSelectTransitionGC::update_transition_anim() {
    f32 fade1;
    f32 fade0;
    s32 timer;
    s32 elapsed;

    timer = this->timer;
    if (timer <= 0x96) {
        fade0 = 1.0f;
        fade1 = (15.0f - (f32) timer) / 15.0f;
    } else {
        elapsed = timer - 0x96;
        fade1 = 1.0f;
        fade0 = (15.0f - (f32) elapsed) / 15.0f;
    }
    draw_play_time_clock(this->position0X, this->position0Y, -1.5f, fade0);
    draw_lobby_location_text(this->position1X, this->position1Y, -1.5f, fade1);
}

void TAdMultiPlyChrSelectTransitionGC::render() {  }

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
void TAdMultiPlyChrSelectTransitionGC::run_task() {
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

TAdMultiPlyChrSelectTransitionGC::~TAdMultiPlyChrSelectTransitionGC() {
    if (this->callback != NULL) {
        this->callback->close();
        this->callback = NULL;
    }
    if (this->statusWindow != NULL) {
        this->statusWindow->close();
        this->statusWindow = NULL;
    }
    multi_chr_select_transition_instance = NULL;
}

TAdMultiPlyChrSelectTransitionGC::TAdMultiPlyChrSelectTransitionGC(TObject *parent, s32 client) : TObject(parent) {
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
    multi_chr_select_transition_instance = this;
    this->statusWindow = new TWindowSubStatusDisp(this->client);
    this->callback = (TWindowBase *)create_callback_at_zero_vec2(update_transition_anim_if_active);
}
