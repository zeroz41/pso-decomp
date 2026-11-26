#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"
#include "pso/system/memory.h"
#include "pso/network/TLobby.h"
#include "pso/system/task/TObject.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowCheckBox.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/frontend/TAdVIConfigGC.h"
#include <string.h>
#include "pso/system/vector.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/network/client_id.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/TLogo.h"
#include "pso/render/gjSystem.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXFrameBuffer.h>
#include <dolphin/os/OSRtc.h>
#include <dolphin/vi.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/NinjaUtil.h"

struct Name_80307D00 { char s[0x18]; };

// The block init() fills: who of the party stands within radius of a spot (warps; the
// name WarpPartyCheck is inferred).
struct WarpPartyCheck {
    f32 radius_sq;
    s32 member_count;      // TLobby::count_members() when the window was last built
    Vec center;
    s32 all_in_range;
    s32 any_in_range;
    s32 confirmed_mask;    // in_range_mask of the last pass that left someone out
    s32 in_range_mask;     // bit per client
    TWindowCheckBox *win;  // the player-name check boxes
    Name_80307D00 names[4];
};

// Ticks the names of the players on this floor within the radius init() set (in the
// window open_player_names_window made) and records which of them are in range.
#pragma push
#pragma fp_contract on
void update_players_in_range(WarpPartyCheck *check) {
    TObjPlayer *player;
    s32 i;
    check->all_in_range = 1;
    check->any_in_range = 0;
    check->in_range_mask = 0;
    if (check->win != NULL) {
        i = 0;
        do {
            player = get_player_by_client_id(i);
            if (player != NULL) {
                if ((get_current_floor() == player->get_floor()) && (xz_distance_squared(&player->position, &check->center) <= check->radius_sq)) {
                    check->win->advance_matching_entries(1, i);
                    check->in_range_mask |= 1 << i;
                    check->any_in_range = 1;
                } else {
                    check->win->advance_matching_entries(0, i);
                    check->in_range_mask &= ~(1 << i);
                    check->all_in_range = 0;
                }
            } else {
                check->win->advance_matching_entries(0, i);
            }
            i += 1;
        } while (i < 4);
    }
    if (check->all_in_range == 0) {
        check->confirmed_mask = check->in_range_mask;
    }
}
#pragma pop


#pragma readonly_strings on



s32 logo_clear_flag = 1;
const char *TAdVIConfigGC::class_name = "TAdVIConfigGC";
extern "C" {
__declspec(section ".data") NJS_POINT2 player_names_window_pos = {229.0f, 104.0f};

void TAdVIConfigGC::open_player_names_window() {
    s32 i;
    TObjPlayer *p;
    if (((WarpPartyCheck *)this)->win != 0) {
        ((TWindowBase *)(((WarpPartyCheck *)this)->win))->close();
        ((WarpPartyCheck *)this)->win = 0;
    }
    ((WarpPartyCheck *)this)->win = create_check_box_window_on_layer(get_window_layout_position(0x5A), &player_names_window_pos, (s32)local_client_id);
    if (((WarpPartyCheck *)this)->win != 0) {
        ((WarpPartyCheck *)this)->win->disable_input();
        ((WarpPartyCheck *)this)->win->set_close_flag();
        for (i = 0; i < 4; i++) {
            p = get_player_by_client_id(i);
            if (p != NULL) {
                strncpy(((WarpPartyCheck *)this)->names[i].s, p->appearance.name, 0x17);
                ((WarpPartyCheck *)this)->names[i].s[0x17] = 0;
                ((WarpPartyCheck *)this)->win->dispatch_without_flags((((WarpPartyCheck *)this)->names[i].s), i);
            } else {
                ((WarpPartyCheck *)this)->names[i].s[0] = 0;
                ((WarpPartyCheck *)this)->win->dispatch_without_flags((((WarpPartyCheck *)this)->names[i].s), i);
            }
        }
    }
}

s32 TAdVIConfigGC::get_field_14() { return *(s32 *)&this->m_down; }

void TAdVIConfigGC::update_visibility() {
    s32 flags;
    u8 *quest_vm_down_load_server;
    flags = TLobby::count_members();
    if ((s32) *(s32 *)&this->m_flags != flags) {
        *(s32 *)&this->m_flags = flags;
        open_player_names_window();
    }
    update_players_in_range((WarpPartyCheck *)this);
    quest_vm_down_load_server = (u8 *)(*(u8 * *)&this->exit_state);
    if (quest_vm_down_load_server != NULL) {
        if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x18) != 0) {
            ((TObject *)quest_vm_down_load_server)->clear_update_suspension();
            ((TObject *)(*(u8 * *)&this->exit_state))->allow_rendering();
            return;
        }
        ((TObject *)quest_vm_down_load_server)->suspend_update();
        ((TObject *)(*(u8 * *)&this->exit_state))->disallow_rendering();
    }
}

void *destroy__13TAdVIConfigGCFPvs(void *config, s16 delete_flag) {
    if (config != NULL) {
        if ((u32) *(u32 *)((s8 *)config + 0x24) != 0U) {
            ((TObject *)(*(void **)((s8 *)config + 0x24)))->clear_update_suspension();
            ((TObject *)((void *)(*(uaddr *)((s8 *)config + 0x24))))->allow_rendering();
            ((TWindowBase *)(*(uaddr *)((s8 *)config + 0x24)))->close();
            *(u32 *)((s8 *)config + 0x24) = 0U;
        }
        if (delete_flag > 0) {
            ::operator delete(config);
        }
    }
    return config;
}

extern "C" {

u8 *TAdVIConfigGC::init(const Vec *position, f32 radius) {
    u8 *base = (u8 *)this;
    VecCopy((Vec *)&this->m_prev, position);
    *(f32 *)&this->m_name = (f32) (radius * radius);
    this->exit_state = 0;
    memset((u8 *)&this->state_frames, 0, 0x60);
    *(s32 *)&this->m_flags = TLobby::count_members();
    this->m_down = 0;
    *(s32 *)((s8 *)base + 0x18) = 0;
    ((TAdVIConfigGC *)base)->open_player_names_window();
    this->state = 0;
    return base;
}

}

void TAdVIConfigGC::render() {
    render_dialog();
}


void TAdVIConfigGC::mark_answered() {
    this->answered = 1;
    logo_clear_flag = 0;
}

void TAdVIConfigGC::enable_progressive_mode() {
    OSSetProgressiveMode(1);
    active_gx_render_mode = &GXNtsc480Prog;
    VIConfigure(&GXNtsc480Prog);
    VIFlush();
    VIWaitForRetrace();
    VIWaitForRetrace();
}

void TAdVIConfigGC::disable_progressive_mode() { OSSetProgressiveMode(0); }
const char *TAdVIConfigGC::get_message_text() { return get_localized_text_entry(29, 0); }

void TAdVIConfigGC::on_cancel() {
    disable_progressive_mode();
    mark_answered();
}

void TAdVIConfigGC::on_accept() {
    if (VIGetDTVStatus() != 0) {
        enable_progressive_mode();
    }
    mark_answered();
}

void TAdVIConfigGC::run_task() {
    run_dialog();
}


TAdVIConfigGC::~TAdVIConfigGC() {

}


TAdVIConfigGC::TAdVIConfigGC(TObject *parent) : TAdYesNoBaseGC(parent) {
    m_name = TAdVIConfigGC::class_name;
    set_default_choice(0);
    answered = 0;
}

}

// Sits between the TAdVIConfigGC constructor and the TAdYesNoBaseGC::on_yes_chosen/9 copies that end this unit.
s32 TLogo::check_progressive_ready() {
    if (VIGetDTVStatus() == 0U) {
        TAdVIConfigGC::disable_progressive_mode();
        return 0;
    }
    if ((OSGetProgressiveMode() != 1U) && (test_previous_buttons_packed(&controller_physical_port_bank.controllers[0], 2) == 0)) {
        TAdVIConfigGC::disable_progressive_mode();
        return 0;
    }
    return 1;
}
