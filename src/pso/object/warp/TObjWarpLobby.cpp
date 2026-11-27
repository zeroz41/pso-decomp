#include "pso/animation/ActorAnimationState.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/BmlResourceLoad.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/object/warp/TObjWarpLobby.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/system/MatrixStack.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/render/TextureState.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/DebugFont.h"
#include "pso/system/task/TObject.h"
#include "pso/network/TLobby.h"
#include "pso/network/client_id.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixReflect.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowComCardFollower.h"

#pragma readonly_strings on

// The lobby names of the warp's menu, one per lobby.
const char *warp_lobby_directory_label_table[15] = {
    "LOBBY-01", "LOBBY-02", "LOBBY-03", "LOBBY-04", "LOBBY-05",
    "LOBBY-06", "LOBBY-07", "LOBBY-08", "LOBBY-09", "LOBBY-10",
    "LOBBY-11", "LOBBY-12", "LOBBY-13", "LOBBY-14", "LOBBY-15",
};
__declspec(section ".data") const char *bm_obj_lobby_warp_model_names[2] = {"de_obj_citybeam.gj", NULL};
__declspec(section ".data") const char *bm_obj_lobby_warp_motion_names[2] = {"de_obj_citybeam.njm", NULL};
BmlResourceDescriptor warp_lobby_resource_descriptor = {
    "bm_obj_lobby_warp.bml", bm_obj_lobby_warp_model_names, bm_obj_lobby_warp_motion_names, 1, 1,
};
const char *TObjWarpLobby::class_name = "TObjWarpLobby";
BmlResource *lobby_warp_bml_resource;


void TObjWarpLobby::debug_print_area_num() {
    s32 base;
    TObjAreaWarp::debug_print_area_num();
    if ((s32) this->set_params[1] < 0) {
        this->set_params[1] = 0;
    }
    if ((s32) this->set_params[1] > 1) {
        this->set_params[1] = 1;
    }
    switch (this->set_params[1]) {
    case 0:
        show_beam = 1;
        break;
    case 1:
        show_beam = 0;
        break;
    default:
        show_beam = 1;
        break;
    }
    set_debug_text_color(0xFF00FF);
    debug_printf_at(0x130021, "<- BEAM DISP ON/OFF");
    set_debug_text_color(0xF0F0F0FF);
}


extern "C" {

NJS_TEXLIST *lobby_warp_textures;

void TObjWarpLobby::open_lobby_menu() {
    NJS_POINT2 position;
    s32 i;
    position.x = 4.5e+02f;
    position.y = 1e+02f;
    this->menu_window = create_window_menu_default(&position, 0xF);
    for (i = 0; i < 0xF; i++) {
        this->menu_window->add_text_entry(warp_lobby_directory_label_table[i], 6, i);
    }
    this->menu_window->calc_window_size();
    align_menu_entry_positions(this->menu_window);
    this->menu_window->set_flag70_bit10();
    request_active_window_close();
}

void TObjWarpLobby::render() {
    if ((show_beam != 0) && (this->update_object_view_visibility(4e+02f, 2e+01f) != 0)) {
        set_texture_list(lobby_warp_textures);
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(0, this->rotation_y);
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion((NJS_OBJECT *)lobby_warp_bml_resource->models[0].model, lobby_warp_bml_resource->motions[0].motion, this->beam_frame);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}



}

void TObjWarpLobby::run_task() {
    s32 selected_menu_value;
    beam_frame += 4.0f;
    if ((f32) (beam_motion->nbFrame - 1) < beam_frame) {
        beam_frame = 0.0f;
    }
    beam_phase += 336.0f;
    if ((find_warp_player_in_range(this, (u16)local_client_id, warp_range) != NULL) && (is_warp_enabled() != 0)) {
        if ((menu_window == NULL) && (TLobby::is_idle() != 0)) {
            open_lobby_menu();
        }
        if ((menu_window != NULL) && (menu_window->is_decided() != 0)) {
            selected_menu_value = menu_window->get_selected_value();
            if (menu_window != NULL) {
                menu_window->queue_destruction();
                menu_window = NULL;
                TWindowCtrl::clear_flag();
            }
            TLobby::send_room_change(selected_menu_value);
        }
    } else if (menu_window != NULL) {
        menu_window->close();
        menu_window = NULL;
        TWindowCtrl::clear_flag();
    }
}

TObjWarpLobby::~TObjWarpLobby() {
}


TObjWarpLobby::TObjWarpLobby(TObject *parent, void *set_data) : TObjAreaWarp(parent, set_data) {

    m_name = class_name;
    this->beam_frame = 0.0f;
    beam_phase = 0.0f;
    this->menu_window = NULL;
    pad_D0 = 0;
    pad_D4 = 0;
    beam_motion = lobby_warp_bml_resource->motions[0].motion;
    pad_DC = 0;
    if ((s32) set_params[1] < 0) {
        set_params[1] = 0;
    }
    if ((s32) set_params[1] > 1) {
        set_params[1] = 1;
    }
    switch (set_params[1]) {
    case 0:
        show_beam = 1;
        break;
    case 1:
        show_beam = 0;
        break;
    default:
        show_beam = 1;
        break;
    }
}


void TObjWarpLobby::release_static() {
    delete lobby_warp_bml_resource;
    lobby_warp_bml_resource = NULL;
}

void TObjWarpLobby::load_resources() {
    BmlResource *resource = new BmlResource(1, &warp_lobby_resource_descriptor, 0, 0, NULL);
    lobby_warp_bml_resource = resource;
    lobby_warp_textures = lobby_warp_bml_resource->models[0].texlist;
}
