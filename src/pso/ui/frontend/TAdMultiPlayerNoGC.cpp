#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/frontend/TAdMultiPlayerNoGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/render/GinjaTexture.h"
#include "pso/unk/TLobby.h"

// The original reads current_language as const here (the load is scheduled
// above the stores of the copied tables); the same view as six other units.
extern "C" const s32 current_language;

GinjaTextureEntry player_ad_texture_entry = { "f128_player_ad", 0, NULL };
__declspec(section ".data") GinjaTextureList player_ad_texture_list = { &player_ad_texture_entry, 1 };
GinjaTextureEntry player_ad_eng_texture_entry = { "f128_player_ad_eng", 0, NULL };
__declspec(section ".data") GinjaTextureList player_ad_eng_texture_list = { &player_ad_eng_texture_entry, 1 };
const char *TAdMultiPlayerNoGC__name = "TAdMultiPlayerNoGC";
GinjaTextureList *player_ad_texture_list_ptr;

// Built with deferred inlining: functions are written in the reverse of
// their address order.
#pragma fp_contract on

void TLobby::update_menu_cursor_selection() {
    TLobby::update_menu_cursor();
    const char *names[5] = {
        "f128_player_ad", "f128_player_ad_eng", "f128_player_ad_eng",
        "f128_player_ad_eng", "f128_player_ad_eng",
    };
    GinjaTextureList *lists[5] = {
        &player_ad_texture_list, &player_ad_eng_texture_list, &player_ad_eng_texture_list,
        &player_ad_eng_texture_list, &player_ad_eng_texture_list,
    };
    GinjaTextureList *list = lists[current_language];
    player_ad_texture_list_ptr = list;
    TLobby__sub_8023E4B4((s32)names[current_language], (s32)list);
}

void TLobby::free_global_object() {
    if (player_ad_texture_list_ptr != NULL) {
        release_texture_list(player_ad_texture_list_ptr);
        player_ad_texture_list_ptr = NULL;
    }
}

TAdMultiPlayerNoGC::TAdMultiPlayerNoGC(TObject *parent, s32 player_count, u32 slot, u32 player_no)
    : TObject(parent) {
    m_name = TAdMultiPlayerNoGC__name;
    switch (player_count) {
    case 2:
        x = slot * 0x130 + 0x68;
        break;
    case 3:
        x = slot * 0xCB + 0x35;
        break;
    case 4:
        x = slot * 0x98 + 0x1C;
        break;
    default:
        queue_destruction();
        return;
    }
    y = 112.0f;
    this->player_no = player_no;
    quad[0] = x;
    quad[1] = y;
    quad[2] = 128.0f + x;
    quad[3] = 22.0f + y;
    quad[4] = 0.0f;
    quad[5] = 22.0f * this->player_no / 128.0f;
    quad[6] = 1.0f;
    quad[7] = (22.0f * this->player_no + 22.0f) / 128.0f;
}

TAdMultiPlayerNoGC::~TAdMultiPlayerNoGC() {}

void TAdMultiPlayerNoGC::run_task() {}

void TAdMultiPlayerNoGC::render() {
    if (TMainTask::get_render_pass() != 1) {
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 10);
        render_status();
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
    }
}

void TAdMultiPlayerNoGC::render_status() {
    begin_screen_draw(1);
    TObjFish::set_global_param((s32)player_ad_texture_list_ptr);
    set_draw_texture_and_color(0, -1);
    draw_textured_quad_at_depth(quad, 0.25f);
    TWindowSubStatusDisp::get_player();
}
