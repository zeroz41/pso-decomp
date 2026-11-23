#include "pso/system/BmlAccessors.h"
#include "pso/render/GinjaMaterialTextureSlot.h"
#include "pso/render/GinjaTexture.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/WindowMenuFactory.h"
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/warp/TObjAreaWarp.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/object/warp/TObjWarpJung.h"
#include "pso/object/warp/TObjWarpJungMain.h"
#include "pso/object/door/TObjDoorJung.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaModel.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/NinjaTypes.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/task/TObject.h"
#include "pso/object/warp/TObjWarpBase.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/frontend/TAdVIConfigGC.h"

const char *bm_obj_warp_jung_model_names[3] = { "fe_obj_warp_dodai.gj", "fe_obj_warp_jogo_light.gj", NULL };
__declspec(section ".data") const char *bm_obj_warp_jung_motion_names[2] = { "fe_obj_warp_jogo_light.njm", NULL };
BmlResourceDescriptor jungle_warp_beam_resource_descriptor = {
    "bm_obj_warp_jung.bml", bm_obj_warp_jung_model_names, bm_obj_warp_jung_motion_names, 2, 1,
};
const char *TObjWarpJung__name = "TObjWarpJung";
const char *TObjWarpJungMain__name = "TObjWarpJungMain";
// Text ids (group 9) of the three menu entries, and the area each one warps to.
s32 jungle_warp_destination_text_ids[3] = { 0x16, 0x18, 0x19 };
s32 jungle_warp_destination_ids[3] = { 6, 8, 9 };

// The beam archive and what load_warp_beam_resources picks out of it.
BmlResource *TObjWarpJung__beam_bml_resource;
AnimationMotion *warp_jung_beam_motion;
NJS_TEXLIST *warp_jung_textures;
s32 warp_jung_last_scroll_tick; // actor_frame_tick of the last UV scroll (inferred)
GinjaModel *warp_jung_beam_uv_model;
s32 warp_jung_beam_entry_index; // texture entry "ts064_beam_aka"
s32 warp_jung_beam_blue_tex_entry;               // texture entry "ts064_beam_ao"
s32 warp_jung_nakalight_tex_entry;               // texture entry "ts032_warp_nakalight"
GinjaModel *warp_jung_beam_models[6];
// The texture entry names load_warp_beam_resources looks up.

extern "C" {
s32 PPCSync();
saddr get_localized_text_entry(s32, s32);
void request_active_window_close(void);
s32 get_window_layout_position(s32);

s32 get_game_play_mode(void);

void TObjWarpJungMain::render() {
    s32 i;
    if (update_object_view_visibility(550.0f, 40.0f) != 0) {
        if (actor_frame_tick != warp_jung_last_scroll_tick) {
            warp_jung_last_scroll_tick = actor_frame_tick;
            if (warp_jung_nakalight_tex_entry >= 0) {
                scroll_ginja_mesh_uvs(warp_jung_beam_uv_model, 0, 5, warp_jung_nakalight_tex_entry, 1);
            }
            PPCSync();
        }
        switch (set_params[2]) {
        case 0:
            if (warp_jung_beam_entry_index >= 0) {
                for (i = 0; i < 6; i++) {
                    set_ginja_model_texture_slot(warp_jung_beam_models[i], (warp_jung_beam_entry_index & 0xFFFF));
                }
            }
            break;
        case 1:
            if (warp_jung_beam_blue_tex_entry >= 0) {
                for (i = 0; i < 6; i++) {
                    set_ginja_model_texture_slot(warp_jung_beam_models[i], (warp_jung_beam_blue_tex_entry & 0xFFFF));
                }
            }
            break;
        }
        TObjFish::set_global_param(warp_jung_textures);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        draw_ginja_object((void *)get_bml_model((BmlResource *)TObjWarpJung__beam_bml_resource, 0));
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion((void *)get_bml_model((BmlResource *)TObjWarpJung__beam_bml_resource, 1), warp_jung_beam_motion, m_c4);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

// Returns 1 once the destination menu is decided, with dest_floor set to the chosen area.
s32 TObjWarpJungMain::is_choice_confirmed_by(s32) {
    if (menu_window != 0 && ((TWindowMenu *)menu_window)->is_decided() != 0) {
        dest_floor = jungle_warp_destination_ids[((TWindowMenu *)menu_window)->get_selected_value()];
        return 1;
    }
    return 0;
}

void TObjWarpJungMain::confirm_area_transfer(TObjPlayer *player) { TObjAreaWarp::confirm_area_transfer(player); }

void TObjWarpJungMain::close_menu() { TObjWarpBase::close_menu(); TWindowCtrl::clear_flag(); }

// Opens the three-entry destination menu for the player with this client id.
void TObjWarpJungMain::open_confirm_window(s32 client_id) {
    s32 i;
    if (menu_window == 0) {
        menu_window = (saddr)create_window_menu((saddr)get_window_layout_position(0x32), 3, client_id);
        for (i = 0; i < 3; i++) {
            ((TWindowMenu *)menu_window)->add_text_entry(get_localized_text_entry(9, jungle_warp_destination_text_ids[i]), 0xE, i);
        }
        ((TWindowMenu *)menu_window)->calc_window_size();
        align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(menu_window));
        ((TWindowMenu *)menu_window)->set_flag70_bit10();
        ((TWindowMenu *)menu_window)->set_loss_flag();
        request_active_window_close();
        user_client_id = client_id;
    }
}

void TObjWarpJungMain::run_task() {
    m_c4 += 4.0f;
    if (m_c4 > (warp_jung_beam_motion->frameCount - 1)) {
        m_c4 = 0.0f;
    }
    handle_area_selection();
}

TObjWarpJungMain::~TObjWarpJungMain() {}

TObjWarpJungMain::TObjWarpJungMain(TObject *parent, void *set_data) : TObjAreaWarp(parent, set_data) {
    m_name = TObjWarpJungMain__name;
    m_c4 = 0.0f;
    set_params[2] = fabs_float(set_params[2] % 2);
    if (get_game_play_mode() == 1 && set_params[2] == 0) {
        this->queue_destruction();
        return;
    }
    warp_range = 15.0f;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        void *p = ::operator new(0x88);
        if (p != NULL) {
            p = ((TAdVIConfigGC *)p)->init(&position, 20.0f);
        }
        vi_config = (TAdVIConfigGC *)p;
    } else {
        vi_config = NULL;
    }
}

void *TObjWarpJung::create(void *set_data) {
    return new TObjWarpJung(tl_05, set_data);
}

void TObjWarpJung::render() {
    if (update_object_view_visibility(550.0f, 40.0f) != 0) {
        if (TObjWarpJung::update_warp_display() != 0) {
            PPCSync();
        }
        switch (set_params[2]) {
        case 0:
            TObjWarpJung__sub_801A0404(0);
            break;
        case 1:
            TObjWarpJung__sub_801A0404(1);
            break;
        }
        TObjWarpJung::set_global_render_param();
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        TObjWarpJung::render_warp(0);
        TParticleCtrl::begin_effect_render();
        TObjWarpJung::render_warp_effect(1, (s32)beam_frame);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TObjWarpJung::confirm_area_transfer(TObjPlayer *player) { TObjAreaWarp::confirm_area_transfer(player); }

void TObjWarpJung::run_task() {
    beam_frame += 4.0f;
    if (beam_frame > (warp_jung_beam_motion->frameCount - 1)) {
        beam_frame = 0.0f;
    }
    handle_area_selection();
}

TObjWarpJung::~TObjWarpJung() {}

TObjWarpJung::TObjWarpJung(TObject *parent, void *set_data) : TObjAreaWarp(parent, set_data) {
    m_name = TObjWarpJung__name;
    beam_frame = 0.0f;
    set_params[2] = fabs_float(set_params[2] % 2);
    if (get_game_play_mode() == 1 && set_params[2] == 1) {
        this->queue_destruction();
        return;
    }
    warp_range = 15.0f;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        void *p = ::operator new(0x88);
        if (p != NULL) {
            p = ((TAdVIConfigGC *)p)->init(&position, 20.0f);
        }
        vi_config = (TAdVIConfigGC *)p;
    } else {
        vi_config = NULL;
    }
}

}

f32 TObjWarpJung::get_static_field4_as_float() {
    return (f32)warp_jung_beam_motion->frameCount;
}

void TObjWarpJung::set_global_render_param() { TObjFish::set_global_param(warp_jung_textures); }

void TObjWarpJung::render_warp_effect(s32 model_index, s32 frame) {
    draw_ginja_model_with_motion((void *)get_bml_model((BmlResource *)TObjWarpJung__beam_bml_resource, model_index), warp_jung_beam_motion, (f32)frame);
}

void TObjWarpJung::render_warp(s32 model_index) {
    draw_ginja_object((void *)get_bml_model((BmlResource *)TObjWarpJung__beam_bml_resource, model_index));
}

s32 TObjWarpJung__sub_801A0404(s32 arg0) {
    s32 i;
    switch (arg0) {
    case 0:
        if (warp_jung_beam_entry_index >= 0) {
            for (i = 0; i < 6; i++) {
                set_ginja_model_texture_slot(warp_jung_beam_models[i], (warp_jung_beam_entry_index & 0xFFFF));
            }
        }
        break;
    case 1:
        if (warp_jung_beam_blue_tex_entry >= 0) {
            for (i = 0; i < 6; i++) {
                set_ginja_model_texture_slot(warp_jung_beam_models[i], (warp_jung_beam_blue_tex_entry & 0xFFFF));
            }
        }
        break;
    }
    return 1;
}

s32 TObjWarpJung::update_warp_display() {
    if (actor_frame_tick != warp_jung_last_scroll_tick) {
        warp_jung_last_scroll_tick = actor_frame_tick;
        if (warp_jung_nakalight_tex_entry >= 0) {
            scroll_ginja_mesh_uvs(warp_jung_beam_uv_model, 0, 5, warp_jung_nakalight_tex_entry, 1);
            return 1;
        }
    }
    return 0;
}

void free_warp_jung_beam_resources(void) {
    s32 i;
    delete TObjWarpJung__beam_bml_resource;
    TObjWarpJung__beam_bml_resource = NULL;
    warp_jung_beam_motion = NULL;
    warp_jung_textures = NULL;
    for (i = 0; i < 6; i++) {
        warp_jung_beam_models[i] = NULL;
    }
}

void load_warp_beam_resources(void) {
    NJS_OBJECT *root;
    BmlResource *resource = new BmlResource(5, &jungle_warp_beam_resource_descriptor, 0, 0, NULL);
    TObjWarpJung__beam_bml_resource = resource;
    warp_jung_beam_motion = get_bml_motion(resource, 0);
    warp_jung_textures = get_bml_texlist((BmlResource *)TObjWarpJung__beam_bml_resource, 0);
    root = ((NJS_OBJECT *)get_bml_model((BmlResource *)TObjWarpJung__beam_bml_resource, 1))->child;
    warp_jung_beam_models[0] = (GinjaModel *)root->child->model;
    warp_jung_beam_models[1] = (GinjaModel *)root->child->sibling->model;
    warp_jung_beam_models[2] = (GinjaModel *)root->child->sibling->sibling->model;
    warp_jung_beam_models[3] = (GinjaModel *)root->child->sibling->sibling->sibling->model;
    warp_jung_beam_models[4] = (GinjaModel *)root->child->sibling->sibling->sibling->sibling->model;
    warp_jung_beam_models[5] = (GinjaModel *)root->sibling->model;
    warp_jung_beam_uv_model = (GinjaModel *)root->sibling->sibling->sibling->model;
    warp_jung_last_scroll_tick = 0;
    warp_jung_beam_entry_index = find_texture_entry_by_name(warp_jung_textures, "ts064_beam_aka");
    warp_jung_beam_blue_tex_entry = find_texture_entry_by_name(warp_jung_textures, "ts064_beam_ao");
    warp_jung_nakalight_tex_entry = find_texture_entry_by_name(warp_jung_textures, "ts032_warp_nakalight");
}

void TObjWarpJungMain::debug_print_area_num() {}
