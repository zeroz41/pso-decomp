#include "types.h"
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
#include "pso/system/BmlResourceLoad.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/NinjaTypes.h"
#include "pso/player/TObjPlayer_80011014.h"

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
s32 warp_jung_model_handle;
s32 lbl_805D5CB4; // actor_frame_tick of the last UV scroll (inferred)
void *warp_jung_beam_mesh_node;
s32 warp_jung_beam_entry_index; // texture entry "ts064_beam_aka"
s32 lbl_805D5CC0;               // texture entry "ts064_beam_ao"
s32 lbl_805D5CC4;               // texture entry "ts032_warp_nakalight"
void *warp_jung_beam_models[6];
// The texture entry names load_warp_beam_resources looks up.
extern const char lbl_80446718[];
extern const char lbl_80446728[];
extern const char lbl_80446738[];

extern "C" {
s32 PPCSync();
s32 rotate_matrix_y(s32, s32);
s32 get_localized_text_entry(s32, s32);
s32 request_active_window_close();
s32 align_menu_entry_positions(u32);
s32 forward_trade_action_default__16TObjCityMainWarpFPviii(u32, s32, s32, s32);
u32 create_window_menu(s32, s32, s16);
s32 get_window_layout_position(s32);
void TObjWarpJungMain__vt13(TObjWarpJungMain *arg0, s16 arg1);

struct Obj_8019FF24 {
    const char *f0;
    u8 pad4[0x18 - 4];
    void *vt18;
    u8 pad1C[0x38 - 0x1C];
    u8 f38[0x8C - 0x38];
    s32 f8C;
    u8 pad90[0xAC - 0x90];
    f32 fAC;
    u8 padB0[0xC0 - 0xB0];
    void *fC0;
    f32 fC4;
};

struct Obj_801A0224 {
    const char *f0;
    u8 pad4[0x18 - 4];
    void *vt18;
    u8 pad1C[0x38 - 0x1C];
    u8 f38[0x8C - 0x38];
    s32 f8C;
    u8 pad90[0xAC - 0x90];
    f32 fAC;
    u8 padB0[0xC0 - 0xB0];
    void *fC0;
    f32 fC4;
};

void queue_destruction__7TObjectFv(void *);
u8 *__dt__12TObjAreaWarpFv(u8 *arg0, s16 arg1);
void *TObjAreaWarp__ct(void *arg0);
int vfunc_14__12TObjWarpBaseFv(void*);
s32 TObjWarpJungMain__vt16(TObjWarpJungMain *arg0);
void * __dt__16TObjWarpJungMainFv(void *arg0, s16 arg1);
void * TObjWarpJung__create(void *arg0);
void * __dt__12TObjWarpJungFv(void *arg0, s16 arg1);
Obj_801A0224 * TObjWarpJung__ct(Obj_801A0224 *self);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);
void * init__13TAdVIConfigGCFf(void *, void *, f32);
s32 get_game_play_mode(void);

extern s32 __vt__12TObjWarpJung[];
extern s32 __vt__16TObjWarpJungMain[];
extern void *tl_05;

void TObjWarpJungMain::render() {
    s32 i;
    if (update_object_view_visibility(550.0f, 40.0f) != 0) {
        if (actor_frame_tick != lbl_805D5CB4) {
            lbl_805D5CB4 = actor_frame_tick;
            if (lbl_805D5CC4 >= 0) {
                scroll_ginja_mesh_uvs(warp_jung_beam_mesh_node, 0, 5, lbl_805D5CC4, 1);
            }
            PPCSync();
        }
        switch (set_params[2]) {
        case 0:
            if (warp_jung_beam_entry_index >= 0) {
                for (i = 0; i < 6; i++) {
                    ((TObjDoorJung *)warp_jung_beam_models[i])->free_children((void *)(warp_jung_beam_entry_index & 0xFFFF));
                }
            }
            break;
        case 1:
            if (lbl_805D5CC0 >= 0) {
                for (i = 0; i < 6; i++) {
                    ((TObjDoorJung *)warp_jung_beam_models[i])->free_children((void *)(lbl_805D5CC0 & 0xFFFF));
                }
            }
            break;
        }
        TObjFish::set_global_param(warp_jung_model_handle);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        draw_ginja_object((void *)get_bml_model(TObjWarpJung__beam_bml_resource, 0));
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion((void *)get_bml_model(TObjWarpJung__beam_bml_resource, 1), warp_jung_beam_motion, m_c4);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

s32 TObjWarpJungMain__vt16(TObjWarpJungMain *warp_jung_main) {
    u8 *window_menu;
    window_menu = (u8 *)(*(u8 **)((s8 *)warp_jung_main + 0xB0));
    if ((window_menu != NULL) && (((TWindowMenu *)window_menu)->is_decided() != 0)) {
        warp_jung_main->m_bc = jungle_warp_destination_ids[((TWindowMenu *)(*(u8 **)((s8 *)warp_jung_main + 0xB0)))->get_selected_value()];
        return 1;
    }
    return 0;
}

void TObjWarpJungMain::confirm_area_transfer(s32 arg1) { TObjAreaWarp::confirm_area_transfer(arg1); }

void TObjWarpJungMain::vfunc_14() { vfunc_14__12TObjWarpBaseFv(this); TWindowCtrl::clear_flag(); }

void TObjWarpJungMain__vt13(TObjWarpJungMain *warp_jung_main, s16 arg1) {
    s32 i;
    if ((u32) warp_jung_main->m_b0 == 0U) {
        warp_jung_main->m_b0 = create_window_menu(get_window_layout_position(0x32), 3, arg1);
        for (i = 0; i < 3; i++) {
            forward_trade_action_default__16TObjCityMainWarpFPviii(warp_jung_main->m_b0, get_localized_text_entry(9, jungle_warp_destination_text_ids[i]), 0xE, i);
        }
        ((TWindowSubComCard *)(warp_jung_main->m_b0))->calc_window_size();
        align_menu_entry_positions(warp_jung_main->m_b0);
        ((TWindowSubComCardList *)(warp_jung_main->m_b0))->set_flag70_bit10();
        ((TLobby *)(warp_jung_main->m_b0))->set_loss_flag();
        request_active_window_close();
        warp_jung_main->m_b8 = arg1;
    }
}

void TObjWarpJungMain::run_task() {
    m_c4 += 4.0f;
    if (m_c4 > (f32)(warp_jung_beam_motion->frameCount - 1)) {
        m_c4 = 0.0f;
    }
    handle_area_selection();
}

void *__dt__16TObjWarpJungMainFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TObjWarpJungMain;
        __dt__12TObjAreaWarpFv((u8 *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

Obj_8019FF24 *TObjWarpJungMain__ct(Obj_8019FF24 *self) {
    TObjAreaWarp__ct(self);
    self->vt18 = __vt__16TObjWarpJungMain;
    self->f0 = TObjWarpJungMain__name;
    self->fC4 = 0.0f;
    self->f8C = fabs_float(self->f8C % 2);
    if (get_game_play_mode() == 1 && self->f8C == 0) {
        queue_destruction__7TObjectFv(self);
        return self;
    }
    self->fAC = 15.0f;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        void *p = ::operator new(0x88);
        if (p != NULL) {
            p = init__13TAdVIConfigGCFf(p, self->f38, 20.0f);
        }
        self->fC0 = p;
    } else {
        self->fC0 = NULL;
    }
    return self;
}

void *TObjWarpJung__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xC8);
    if (o != NULL) {
        o = ((void * (*)(void *, void *, void *))TObjWarpJung__ct)(o, tl_05, arg0);
    }
    return o;
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

void TObjWarpJung::confirm_area_transfer(s32 arg1) { TObjAreaWarp::confirm_area_transfer(arg1); }

void TObjWarpJung::run_task() {
    beam_frame += 4.0f;
    if (beam_frame > (f32)(warp_jung_beam_motion->frameCount - 1)) {
        beam_frame = 0.0f;
    }
    handle_area_selection();
}

void *__dt__12TObjWarpJungFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjWarpJung;
        __dt__12TObjAreaWarpFv((u8 *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

Obj_801A0224 *TObjWarpJung__ct(Obj_801A0224 *self) {
    TObjAreaWarp__ct(self);
    self->vt18 = __vt__12TObjWarpJung;
    self->f0 = TObjWarpJung__name;
    self->fC4 = 0.0f;
    self->f8C = fabs_float(self->f8C % 2);
    if (get_game_play_mode() == 1 && self->f8C == 1) {
        queue_destruction__7TObjectFv(self);
        return self;
    }
    self->fAC = 15.0f;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        void *p = ::operator new(0x88);
        if (p != NULL) {
            p = init__13TAdVIConfigGCFf(p, self->f38, 20.0f);
        }
        self->fC0 = p;
    } else {
        self->fC0 = NULL;
    }
    return self;
}

}

f32 TObjWarpJung::get_static_field4_as_float() {
    return (f32)warp_jung_beam_motion->frameCount;
}

void TObjWarpJung::set_global_render_param() { TObjFish::set_global_param(warp_jung_model_handle); }

void TObjWarpJung::render_warp_effect(s32 model_index, s32 frame) {
    draw_ginja_model_with_motion((void *)get_bml_model(TObjWarpJung__beam_bml_resource, model_index), warp_jung_beam_motion, (f32)frame);
}

void TObjWarpJung::render_warp(s32 model_index) {
    draw_ginja_object((void *)get_bml_model(TObjWarpJung__beam_bml_resource, model_index));
}

s32 TObjWarpJung__sub_801A0404(s32 arg0) {
    s32 i;
    switch (arg0) {
    case 0:
        if (warp_jung_beam_entry_index >= 0) {
            for (i = 0; i < 6; i++) {
                ((TObjDoorJung *)warp_jung_beam_models[i])->free_children((void *)(warp_jung_beam_entry_index & 0xFFFF));
            }
        }
        break;
    case 1:
        if (lbl_805D5CC0 >= 0) {
            for (i = 0; i < 6; i++) {
                ((TObjDoorJung *)warp_jung_beam_models[i])->free_children((void *)(lbl_805D5CC0 & 0xFFFF));
            }
        }
        break;
    }
    return 1;
}

s32 TObjWarpJung::update_warp_display() {
    if (actor_frame_tick != lbl_805D5CB4) {
        lbl_805D5CB4 = actor_frame_tick;
        if (lbl_805D5CC4 >= 0) {
            scroll_ginja_mesh_uvs(warp_jung_beam_mesh_node, 0, 5, lbl_805D5CC4, 1);
            return 1;
        }
    }
    return 0;
}

void free_warp_jung_beam_resources(void) {
    s32 i;
    TLobby__sub_8001FE7C(TObjWarpJung__beam_bml_resource, 1);
    TObjWarpJung__beam_bml_resource = NULL;
    warp_jung_beam_motion = NULL;
    warp_jung_model_handle = 0;
    for (i = 0; i < 6; i++) {
        warp_jung_beam_models[i] = NULL;
    }
}

void load_warp_beam_resources(void) {
    NJS_OBJECT *root;
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 5, &jungle_warp_beam_resource_descriptor, 0, 0, 0);
    }
    TObjWarpJung__beam_bml_resource = resource;
    warp_jung_beam_motion = get_bml_motion(resource, 0);
    warp_jung_model_handle = TObjFish__sub_8001EDB0(TObjWarpJung__beam_bml_resource, 0);
    root = ((NJS_OBJECT *)get_bml_model(TObjWarpJung__beam_bml_resource, 1))->child;
    warp_jung_beam_models[0] = root->child->model;
    warp_jung_beam_models[1] = root->child->sibling->model;
    warp_jung_beam_models[2] = root->child->sibling->sibling->model;
    warp_jung_beam_models[3] = root->child->sibling->sibling->sibling->model;
    warp_jung_beam_models[4] = root->child->sibling->sibling->sibling->sibling->model;
    warp_jung_beam_models[5] = root->sibling->model;
    warp_jung_beam_mesh_node = root->sibling->sibling->sibling->model;
    lbl_805D5CB4 = 0;
    warp_jung_beam_entry_index = ((TObjDoorJung *)warp_jung_model_handle)->find_entry_by_name(lbl_80446718);
    lbl_805D5CC0 = ((TObjDoorJung *)warp_jung_model_handle)->find_entry_by_name(lbl_80446728);
    lbl_805D5CC4 = ((TObjDoorJung *)warp_jung_model_handle)->find_entry_by_name(lbl_80446738);
}
