#include "types.h"
#include "pso/object/TObjAreaWarp.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/object/TObjWarpJung.h"
#include "pso/object/TObjWarpJungMain.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/object/TObjCityMainWarp.h"
#include "pso/object/TObjFish.h"

struct VBase_18_8019FB8C { char pad[0x18]; };

struct VObj_18_8019FB8C : VBase_18_8019FB8C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

extern "C" {
s32 get_bml_model(s32, s32);
s32 free_children__12TObjDoorJungFPv(s32, u16);
s32 scroll_ginja_mesh_uvs(s32, s32, s32, u16, s32);
s32 PPCSync();
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_ginja_object(void *child);
s32 draw_ginja_model_with_motion(s32, s32, f32);
extern s32 warp_jung_beam_models[];
extern s32 actor_frame_tick;
extern s32 TObjWarpJung__beam_bml_resource;
extern void *warp_jung_beam_motion;
extern int warp_jung_model_handle;
extern s32 lbl_805D5CB4;
extern s32 warp_jung_beam_mesh_node;
extern s32 warp_jung_beam_entry_index;
extern s32 lbl_805D5CC0;
extern s32 lbl_805D5CC4;
extern const f32 lbl_805DC040;
extern const f32 lbl_805DC044;
s32 get_localized_text_entry(s32, s32);
s32 request_active_window_close();
s32 align_menu_entry_positions(u32);
s32 forward_trade_action_default__16TObjCityMainWarpFPviii(u32, s32, s32, s32);
u32 create_window_menu(s32, s32, s16);
s32 get_window_layout_position(s32);
extern s32 jungle_warp_destination_text_ids[];
void TObjWarpJungMain__vt13(TObjWarpJungMain *arg0, s16 arg1);
struct RecoveredGlobal_8019FCFC_lbl_804B9658 {
    s32 value;
    u8 remaining[0x8];
};

typedef char RecoveredGlobal_8019FCFC_lbl_804B9658_size[sizeof(RecoveredGlobal_8019FCFC_lbl_804B9658) == 0xC ? 1 : -1];

struct VObjBase_801A0070_more_8019fe60_1 { char pad[0x18]; };

struct VObj_801A0070_more_8019fe60_1 : VObjBase_801A0070_more_8019fe60_1 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Obj_8019FF24 {
    s32 f0;
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
    s32 f0;
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

f32 fabs_float(f32);
void queue_destruction__7TObjectFv(void *);
int confirm_area_transfer__12TObjAreaWarpFPvi(void*);
u8 *__dt__12TObjAreaWarpFv(u8 *arg0, s16 arg1);
void *TObjAreaWarp__ct(void *arg0);
int vfunc_14__12TObjWarpBaseFv(void*);
s32 TObjWarpJungMain__vt16(TObjWarpJungMain *arg0);
void * __dt__16TObjWarpJungMainFv(void *arg0, s16 arg1);
void * TObjWarpJung__create(void *arg0);
void * __dt__12TObjWarpJungFv(void *arg0, s16 arg1);
Obj_801A0224 * TObjWarpJung__ct(Obj_801A0224 *self);
s32 TObjWarpJung__sub_801A0404(s32);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);
void * init__13TAdVIConfigGCFf(void *, void *, f32);
s32 get_game_play_mode(void);

extern s32 __vt__12TObjWarpJung[];
extern s32 __vt__16TObjWarpJungMain[];
extern RecoveredGlobal_8019FCFC_lbl_804B9658 jungle_warp_destination_ids;
extern s32 lbl_805D3498;
extern s32 lbl_805D349C;
extern const f32 lbl_805DC048;
extern const f32 lbl_805DC04C;
extern const f32 lbl_805DC050;
extern const f32 lbl_805DC054;
extern void *tl_05;

void TObjWarpJungMain::render() {
    VObj_18_8019FB8C *arg0 = (VObj_18_8019FB8C *)this;
    s32 i;
    if (arg0->m8(lbl_805DC040, lbl_805DC044) != 0) {
        if (actor_frame_tick != lbl_805D5CB4) {
            lbl_805D5CB4 = actor_frame_tick;
            if (lbl_805D5CC4 >= 0) {
                scroll_ginja_mesh_uvs(warp_jung_beam_mesh_node, 0, 5, lbl_805D5CC4, 1);
            }
            PPCSync();
        }
        switch (*(s32 *)((s8 *)arg0 + 0x8C)) {
        case 0:
            if (warp_jung_beam_entry_index >= 0) {
                for (i = 0; i < 6; i++) {
                    free_children__12TObjDoorJungFPv(warp_jung_beam_models[i], warp_jung_beam_entry_index);
                }
            }
            break;
        case 1:
            if (lbl_805D5CC0 >= 0) {
                for (i = 0; i < 6; i++) {
                    free_children__12TObjDoorJungFPv(warp_jung_beam_models[i], lbl_805D5CC0);
                }
            }
            break;
        }
        TObjFish::set_global_param((s32)((void *)warp_jung_model_handle));
        push_matrix();
        post_translate_matrix((u8 *)arg0 + 0x38);
        rotate_matrix_y(0, *(s32 *)((s8 *)arg0 + 0x60));
        draw_ginja_object((void *)(get_bml_model(TObjWarpJung__beam_bml_resource, 0)));
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion(get_bml_model(TObjWarpJung__beam_bml_resource, 1), *(s32 *)&warp_jung_beam_motion, *(f32 *)((s8 *)arg0 + 0xC4));
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

s32 TObjWarpJungMain__vt16(TObjWarpJungMain *warp_jung_main) {
    u8 *window_menu;
    window_menu = (u8 *)(*(u8 **)((s8 *)warp_jung_main + 0xB0));
    if ((window_menu != NULL) && (((TWindowMenu *)window_menu)->is_decided() != 0)) {
        warp_jung_main->m_bc = (s32) *(s32 *)((s8 *)&jungle_warp_destination_ids.value + (((TWindowMenu *)(*(u8 **)((s8 *)warp_jung_main + 0xB0)))->get_selected_value() * 4));
        return 1;
    }
    return 0;
}

void TObjWarpJungMain::confirm_area_transfer(s32) { confirm_area_transfer__12TObjAreaWarpFPvi(this); }

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
    u8 *arg0 = (u8 *)this;
  this->m_c4 = (f32) ((this->m_c4) + lbl_805DC048);
  if ((this->m_c4) > ((f32) (((*((s32 *) (((s8 *) (*(u8 * *)&warp_jung_beam_motion)) + 4))) - 1) & 0xFFFFFFFF)))
  {
    this->m_c4 = (f32) lbl_805DC04C;
  }
  ((TObjAreaWarp *)arg0)->handle_area_selection();
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
    self->f0 = lbl_805D349C;
    self->fC4 = lbl_805DC04C;
    self->f8C = fabs_float(self->f8C % 2);
    if (get_game_play_mode() == 1 && self->f8C == 0) {
        queue_destruction__7TObjectFv(self);
        return self;
    }
    self->fAC = lbl_805DC050;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        void *p = ::operator new(0x88);
        if (p != NULL) {
            p = init__13TAdVIConfigGCFf(p, self->f38, lbl_805DC054);
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
    u8 *arg0 = (u8 *)this;

    if (((VObj_801A0070_more_8019fe60_1*)arg0)->m8(lbl_805DC040, lbl_805DC044) != 0) {
        if (TObjWarpJung::update_warp_display() != 0) {
            PPCSync();
        }
        switch (this->set_params[2]) {
        case 0:
            TObjWarpJung__sub_801A0404(0);
            break;
        case 1:
            TObjWarpJung__sub_801A0404(1);
            break;
        }
        TObjWarpJung::set_global_render_param();
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjWarpJung::render_warp(0);
        TParticleCtrl::begin_effect_render();
        TObjWarpJung::render_warp_effect(1, (s32) this->m_c4);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TObjWarpJung::confirm_area_transfer(s32) { confirm_area_transfer__12TObjAreaWarpFPvi(this); }

void TObjWarpJung::run_task() {
    u8 *arg0 = (u8 *)this;
  this->m_c4 = (f32) ((this->m_c4) + lbl_805DC048);
  if ((this->m_c4) > ((f32) (((*((s32 *) (((s8 *) (*(u8 * *)&warp_jung_beam_motion)) + 4))) - 1) & 0xFFFFFFFF)))
  {
    this->m_c4 = (f32) lbl_805DC04C;
  }
  ((TObjAreaWarp *)arg0)->handle_area_selection();
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
    self->f0 = lbl_805D3498;
    self->fC4 = lbl_805DC04C;
    self->f8C = fabs_float(self->f8C % 2);
    if (get_game_play_mode() == 1 && self->f8C == 1) {
        queue_destruction__7TObjectFv(self);
        return self;
    }
    self->fAC = lbl_805DC050;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        void *p = ::operator new(0x88);
        if (p != NULL) {
            p = init__13TAdVIConfigGCFf(p, self->f38, lbl_805DC054);
        }
        self->fC0 = p;
    } else {
        self->fC0 = NULL;
    }
    return self;
}

f32 TObjWarpJung::get_static_field4_as_float() {
    return (f32) *(u32 *)((s8 *)warp_jung_beam_motion + 4);
}

void TObjWarpJung::set_global_render_param() { TObjFish::set_global_param(warp_jung_model_handle); }

void TObjWarpJung::render_warp_effect(s32 arg0, s32 arg1) {
    s32 bml_model;

    bml_model = get_bml_model(TObjWarpJung__beam_bml_resource, arg0);
    draw_ginja_model_with_motion(bml_model, (*(s32 *)&warp_jung_beam_motion), (f32) arg1);
}

}
