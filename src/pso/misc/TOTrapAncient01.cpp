#include "types.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TOTrap_801791EC.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_800D7BFC.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjChara.h"
#include "pso/misc/TOTrapAncient02R.h"
#include "pso/misc/TOTrap.h"
#include "pso/misc/TOTrapAncient01.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TMotorcycle.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"

struct RecoveredGlobal_80179E34_lbl_804B4834
{
  s32 value;
  u8 remaining[0xC];
};

struct E_8017A1A4 { u8 pad[0xc]; f32 f; u8 pad2[0x2c - 0x10]; };

struct Obj_8017A1A4 { u8 pad[0xa4]; E_8017A1A4 *arr; };

struct Self_80179EC0 { u8 pad[0x18]; s32 *vt; u8 pad1c[0x358 - 0x1C]; u8 arr[4][0x1C]; };

struct Self_80179F40 { u8 pad[0x358]; u8 arr[4][0x1C]; };

struct VBase_801797D4 { char pad[0x18]; };

struct VObj_801797D4 : VBase_801797D4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20(s32, f32);
    virtual void m21(void *, void *, s32, s32, s32);
    virtual void m22();
    virtual void m23(void *, f32);
};

struct Ent_801797D4 { u8 pad[0xC]; f32 fC; };

struct Pair_801797D4 { s32 a; s32 b; };

struct Trap_801797D4 : VObj_801797D4 {
    u8 pad1C[0xA4 - 0x1C];
    Ent_801797D4 *fA4;
    u8 padA8[0x2A8 - 0xA8];
    s32 f2A8;
    u8 pad2AC[0x344 - 0x2AC];
    Pair_801797D4 f344;
    u8 pad34C[0x354 - 0x34C];
    f32 f354;
};

struct Vec_80179B8C { f32 x, y, z; };

struct Node_80179B8C { u8 pad0[4]; s32 f4; u8 mtx[0x2C - 8]; Node_80179B8C *child; };

struct FadeBase_80179B8C { char pad[0x14]; };

struct Fade_80179B8C : FadeBase_80179B8C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    u8 pad18[4];
};

struct VBase_80179B8C { char pad[0x18]; };

struct VObj_80179B8C : VBase_80179B8C {
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

struct Trap_80179B8C : VObj_80179B8C {
    u8 pad1C[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    Node_80179B8C *model;
    u8 pos38[0x60 - 0x38];
    s32 f60;
    u8 pad64[0x6C - 0x64];
    f32 f6C;
    u8 pad70[0x340 - 0x70];
    s32 f340;
    u8 pad344[0x358 - 0x344];
    Fade_80179B8C fades[4];
};

extern "C" {
void receive_physical_attack__6TOTrapFPvf(void *, void *, f32);
u16 get_entity_id(void *);
void obj_clear_flag30_20000(void *arg0);
s32 check_player_flag1__6TLobbyFv();
void *get_player_by_client_id(s32 i);
extern s32 local_client_id;
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80179E34_lbl_804B4834 bm_o_trap_ancient01_resource_descriptor;
extern u32 TOTrapAncient01__bml_resource;
extern const f32 TOTrapAncient01__data_805DBA4C;
extern const f32 lbl_805DBA5C;
f32 TObjPlayer__sub_8017A1A4(Obj_8017A1A4 *self, s32 i);
s32 free_collision_body_parts(void *);
s32 __destroy_arr(void *, void *, int, int);
void __dl__7TObjectFPv(void *);
extern s32 __vt__15TOTrapAncient01[];
Self_80179EC0 *__dt__15TOTrapAncient01Fv(Self_80179EC0 *self, s16 flag);
s32 init_collision_body_parts(void *, void *, int);
void TOTrap__ct(void *, void *, void *);
void __construct_array(void *, void *, void *, int, int);
void __ct__15RenderFadeStateFv(void *);
extern s32 lbl_804B4844[];
extern s32 TOTrapAncient01__class_name;
extern const f32 lbl_805DBA54;
extern const f32 lbl_805DBA6C;
extern const f32 lbl_805DBA74;
VObj_801797D4 *get_battle_param__10TObjPlayerFi(s32);
s32 obj_is_hit_receivable(void *);
s32 check_value_equals__13TUnk_804B6C24Fl(void *, s32);
void submit_cursor_candidate(void *, s32);
void play_persistent_sound(s32, void *, void *, s32, s32);
extern s32 lbl_805D3530;
extern const f32 lbl_805DBA48;
s32 is_split_screen();
s32 get_camera_mode__11TCameraCtrlFv();
void update__15RenderFadeStateFv(void *);
s32 rand(void);
int rotate_matrix_y(int, int);
int push_matrix();
int pop_matrix();
int post_translate_matrix(void *);
int draw_ginja_model(int);
void translate_matrix(s32, f32, f32, f32);
extern s32 model_render_flags;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern const f32 lbl_805DBA58;
extern const f32 lbl_805DBA60;
extern const f32 lbl_805DBA64;
extern const f32 lbl_805DBA68;
void render__15TOTrapAncient01Fv(Trap_80179B8C *self);
void TLobby__sub_8001FE7C(void*, int);
void fn_80141CF0(void *, void *, void *);
void TOTrapAncient02R__sub_80154D78(void *);
void *__nw__7TObjectFUl(int);
s32 is_current_room(void *);

void TOTrap::apply_knockback_from_attacker(u8 *, f32) {  }
void TOTrapAncient01::vfunc_86() {  }
void TOTrapAncient01::vfunc_88() {  }

void TOTrapAncient01::vfunc_6(s16 *arg1, s32 arg2) {
    if ((s16) *arg1 == 4) {
        if (arg2 == 1) {
            this->play_sounds();
        }
        this->release_trapped_player();
        set_flag8();
        queue_destruction__7TObjectFv(this);
    }
}

void TOTrapAncient01::release_trapped_player() {
    s32 temp_r3;
    s32 temp_r3_2;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        if (this->target != NULL) {
            temp_r3 = (s32)get_player_by_client_id((get_entity_id(this->target)));
            if (temp_r3 != 0) {
                if (check_player_flag1__6TLobbyFv() != 0) {
                    TObjPlayer::send_code_45_1(temp_r3);
                }
                obj_clear_flag30_20000((void *)temp_r3);
            }
        }
    } else if ((this->target != NULL) && ((s32) local_client_id == (s32) get_entity_id(this->target))) {
        temp_r3_2 = (s32)get_player_by_client_id(local_client_id);
        if (temp_r3_2 != 0) {
            if (check_player_flag1__6TLobbyFv() != 0) {
                TObjPlayer::send_code_45_1(temp_r3_2);
            }
            obj_clear_flag30_20000((void *)temp_r3_2);
        }
    }
}

f32 TOTrapAncient01::receive_physical_attack(void *arg1, f32 farg0) {
    this->release_trapped_player();
    receive_physical_attack__6TOTrapFPvf(this, arg1, farg0);
}

void TOTrapAncient01::vfunc_84() {  }

extern void *tl_05;

void TOTrapAncient01::vfunc_82() {
    s32 i;
    VObj_801797D4 *p;
    this->calc_attach_pos();
    ((Trap_801797D4 *)this)->f354 -= lbl_805DBA48;
    if (((Trap_801797D4 *)this)->f354 < TOTrapAncient01__data_805DBA4C) {
        ((Trap_801797D4 *)this)->fA4->fC = lbl_805DBA54;
        set_indexed_flags(0, 0x100);
        TObjPlayer::init_all_slots();
        ((TObjPlayer *)this)->check_object_collisions();
        for (i = 0; i < 16; i++) {
            p = get_battle_param__10TObjPlayerFi(i);
            if (p == 0) {
                break;
            }
            if (obj_is_hit_receivable(p) == 0) {
                break;
            }
            if (check_value_equals__13TUnk_804B6C24Fl(p, lbl_805D3530) == 0) {
                break;
            }
            {
            Pair_801797D4 v = ((Trap_801797D4 *)this)->f344;
            p->m21(this, &v, 0, -1, -1);
            }
            if (((Trap_801797D4 *)this)->f344.a < 5) {
                p->m23(((Trap_801797D4 *)this), TOTrapAncient01__data_805DBA4C);
            }
        }
        ((Trap_801797D4 *)this)->m20(((Trap_801797D4 *)this)->f2A8, lbl_805DBA48);
    }
    submit_cursor_candidate(((Trap_801797D4 *)this), -1);
    switch (get_current_floor_area()) {
    case AREA_RUINS1:
    case AREA_RUINS2:
    case AREA_RUINS3:
        play_persistent_sound(0x4004C618, ((Trap_801797D4 *)this), (u8 *)((Trap_801797D4 *)this) + 0x38, 0, 0);
        break;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_persistent_sound(0x4004C610, ((Trap_801797D4 *)this), (u8 *)((Trap_801797D4 *)this) + 0x38, 0, 0);
        break;
    case AREA_PIONEER2_EP1:
        return;
    case AREA_FOREST1:
        break;
    case AREA_FOREST2:
        return;
    case AREA_CAVE1:
        break;
    case AREA_CAVE2:
        return;
    case AREA_CAVE3:
        break;
    case AREA_MINE1:
        return;
    case AREA_MINE2:
        break;
    case AREA_DRAGON:
        break;
    case AREA_DE_ROL_LE:
        return;
    case AREA_VOL_OPT:
        break;
    case AREA_DARK_FALZ:
        return;
    case AREA_LOBBY:
        break;
    case AREA_BATTLE1:
        return;
    case AREA_BATTLE2:
        break;
    case AREA_PIONEER2_EP2:
        return;
    case AREA_VR_TEMPLE_ALPHA:
        break;
    case AREA_VR_TEMPLE_BETA:
        return;
    }
}

#pragma push
#pragma opt_lifetimes off
#pragma fp_contract on
void render__15TOTrapAncient01Fv(Trap_80179B8C *self) {
    Fade_80179B8C *fade;
    Node_80179B8C *n;
    s32 i;
    Vec_80179B8C v;
    i = 0;
    if (is_split_screen() != 0) {
        i = get_camera_mode__11TCameraCtrlFv();
    }
    fade = &self->fades[i];
    update__15RenderFadeStateFv(fade);
    self->f340 = self->m8(lbl_805DBA58, lbl_805DBA5C);
    if (self->f340 == 1) {
        if (((RenderFadeState *)fade)->updateFromCamera((const f32*)(self->pos38)) == 1) {
            saved_model_render_flags = model_render_flags;
            saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
            saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
            fade->m6();
        }
        push_matrix();
        post_translate_matrix(self->pos38);
        rotate_matrix_y(0, self->f60);
        if (TObjPlayer::check_demo_mode() != 1 && self->f6C <= TOTrapAncient01__data_805DBA4C) {
            v.x = lbl_805DBA60 * (lbl_805DBA64 * (f32)rand()) - lbl_805DBA68;
            v.y = TOTrapAncient01__data_805DBA4C;
            v.z = lbl_805DBA60 * (lbl_805DBA64 * (f32)rand()) - lbl_805DBA68;
            post_translate_matrix(&v);
        }
        TObjFish::set_global_param(self->f24);
        n = self->model;
        push_matrix();
        translate_matrix(0, TOTrapAncient01__data_805DBA4C, self->f6C, TOTrapAncient01__data_805DBA4C);
        post_translate_matrix(n->mtx);
        draw_ginja_model(self->model->f4);
        n = n->child;
        push_matrix();
        post_translate_matrix(n->mtx);
        TParticleCtrl::begin_effect_render();
        draw_ginja_model(n->f4);
        TParticleCtrl::end_effect_render();
        pop_matrix();
        pop_matrix();
        pop_matrix();
        if (((RenderFadeState *)fade)->updateFromCamera((const f32*)(self->pos38)) == 1) {
            fade->m7();
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            model_render_flags = saved_model_render_flags;
        }
    }
}
#pragma pop

void *TOTrapAncient01::create() {
    void *o = __nw__7TObjectFUl(0x3C8);
    if (o != NULL) {
        o = TOTrapAncient01__ct(o, tl_05, this);
    }
    return o;
}

void TOTrapAncient01::release_static_resource() {
    if ((u32) TOTrapAncient01__bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOTrapAncient01__bml_resource, 1);
        TOTrapAncient01__bml_resource = 0U;
    }
}

extern s32 scratch_vec[];
extern s32 trap_ancient_light_color[];

typedef struct RecoveredGlobal_80179E34_lbl_804B4834 RecoveredGlobal_80179E34_lbl_804B4834;
void TOTrapAncient01::load_resources() {
  s32 temp_r31;
  int new_var;
  s32 temp_r3;
  s32 var_r0;
  temp_r3 = (int)::operator new(0x440);
  var_r0 = temp_r3;
  temp_r31 = var_r0;
  new_var = 0;
  if (temp_r31 != new_var)
  {
    var_r0 = (long) load_resource_from_descriptor((void *) temp_r3, 1, &bm_o_trap_ancient01_resource_descriptor.value, 0, 0, 0);
  }
  (*(u8 * *)&TOTrapAncient01__bml_resource) = (unsigned char *) ((void *) var_r0);
  temp_r31 = TObjFish__sub_8001EDB0((void *) var_r0, 3);
  TMotorcycle::add_entry(0x39, (int) get_bml_model((*(u8 * *)&TOTrapAncient01__bml_resource), 3), (int) temp_r31, (f32) lbl_805DBA5C, (f32) TOTrapAncient01__data_805DBA4C);
}

Self_80179EC0 *__dt__15TOTrapAncient01Fv(Self_80179EC0 *self, s16 flag) {
    if (self != 0) {
        self->vt = __vt__15TOTrapAncient01;
        ((TObjCollidable *)self)->unregister_object_by_id();
        free_collision_body_parts(self);
        __destroy_arr(self->arr, (void *)__dt__15RenderFadeStateFv, 0x1C, 4);
        __dt__6TOTrapFv(self, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}

#pragma push
#pragma fp_contract on
#define self ((u8 *)arg0)
void *TOTrapAncient01__ct(void *arg0, void *arg1, void *arg2) {
    s32 i;
    TOTrap__ct(arg0, arg1, arg2);
    *(s32 **)((s8 *)self + 0x18) = __vt__15TOTrapAncient01;
    __construct_array(self + 0x358, (void *)__ct__15RenderFadeStateFv, (void *)__dt__15RenderFadeStateFv, 0x1C, 4);
    *(s32 *)((s8 *)self + 0) = TOTrapAncient01__class_name;
    ((TOTrapAncient01 *)arg0)->apply_object_set_data((void *)((s32)arg2));
    ((TObjPlayer *)arg0)->init_position_vectors();
    ((TObjChara *)arg0)->calc_attach_pos();
    *(s32 *)((s8 *)self + 0x34) = get_bml_model((void *)TOTrapAncient01__bml_resource, 3);
    *(s32 *)((s8 *)self + 0x24) = TObjFish__sub_8001EDB0((void *)TOTrapAncient01__bml_resource, 3);
    *(s16 *)((s8 *)self + 0x326) = 0;
    *(f32 *)((s8 *)self + 0x334) = 0.5f * *(f32 *)((s8 *)self + 0x68) + 30.0f;
    if (*(f32 *)((s8 *)self + 0x6C) < 0.0f) {
        *(f32 *)((s8 *)self + 0x6C) = 0.0f;
    }
    if (*(f32 *)((s8 *)self + 0x70) < 1.0f) {
        *(f32 *)((s8 *)self + 0x70) = 1.0f;
    }
    *(f32 *)((s8 *)self + 0x34C) = -*(f32 *)((s8 *)self + 0x6C) / *(f32 *)((s8 *)self + 0x70);
    *(f32 *)((s8 *)self + 0x350) = lbl_805DBA6C + (f32)*(s32 *)((s8 *)self + 0x8C);
    if (get_main_phase() == 0xE) {
        *(f32 *)((s8 *)self + 0x350) *= lbl_805DBA74;
    }
    if (*(f32 *)((s8 *)self + 0x350) < 0.0f) {
        *(f32 *)((s8 *)self + 0x350) = 0.0f;
    }
    *(f32 *)((s8 *)self + 0x354) = *(f32 *)((s8 *)self + 0x350);
    if (*(s32 *)((s8 *)self + 0x84) < 0) {
        *(s32 *)((s8 *)self + 0x84) = 0;
    }
    *(f32 *)((s8 *)self + 0x348) = ((TOTrapAncient01 *)arg0)->vfunc_87((f32)*(s32 *)((s8 *)self + 0x84));
    if (*(s32 *)((s8 *)self + 0x88) < 0) {
        *(s32 *)((s8 *)self + 0x88) = 0;
    } else if (*(s32 *)((s8 *)self + 0x88) > 5) {
        *(s32 *)((s8 *)self + 0x88) = 5;
    }
    *(s32 *)((s8 *)self + 0x344) = *(s32 *)((s8 *)self + 0x88);
    *(f32 *)((s8 *)self + 0x338) = lbl_805DBA54;
    *(u16 *)((s8 *)self + 0x33C) = 0xFFFF;
    init_collision_body_parts(arg0, lbl_804B4844, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    *(u32 *)((s8 *)self + 0x30) |= 0x60040000;
    ((TObjChara *)arg0)->get_or_assign_entity_id(0);
    ((TObjPlayer *)arg0)->register_object_by_id();
    for (i = 0; i < 4; i++) {
        ((RenderFadeState *)(((Self_80179F40 *)arg0)->arr[i]))->activate_and_dispatch();
    }
    return arg0;
}
#undef self
#pragma pop

f32 TObjPlayer__sub_8017A1A4(Obj_8017A1A4 *self, s32 i) {
    return self->arr[i].f;
}

void TOTrapAncient02R::vfunc_86() {
    s32 x;
    x = is_current_room(this);
    if (x == 1) {
        fn_80141CF0((void *)((char *)this + 80), scratch_vec, trap_ancient_light_color);
        TOTrapAncient02R__sub_80154D78(this);
    }
}

}
