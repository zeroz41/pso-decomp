#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/vector.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TUnk_804F0A00.h"
#include "pso/weapon/TUnk_804F0AF8.h"
#include "pso/weapon/TUnk_804F0908.h"
#include "pso/weapon/TUnk_804F0810.h"
#include "pso/player/TUnk_804A2548.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/item/TUnk_804F0BF0.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/render_util.h"
#include "pso/effect/item/TUnk_804F0C08.h"
#include "pso/effect/item/TItemEffPG.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/item/TUnk_804E355C.h"
#include "pso/player/TObjPlayer_801AF2F0.h"

struct Base_8034EFDC { char pad[0x18]; };
struct VObj_8034EFDC : Base_8034EFDC {
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
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63(s32, void *);
};


struct Elem_80125628 { u8 pad[0x1c]; u8 f1c[0x2c - 0x1c]; };

struct Obj_80125628 { u8 pad[0xa4]; Elem_80125628 *elems; };

struct Ctx_80125628 { Obj_80125628 *obj; s32 idx; };

struct P_8034F020 { u8 pad0[0x1F8]; s32 f1F8; };

typedef struct SlicerLaunchData_8012D9C8 {
    u16 player; u16 pad;
    void *textures; void *model; u32 weapon;
    s16 kind, stage; f32 multiplier; f32 color[4];
    s32 facing, spin; f32 first[3], second[3];
} SlicerLaunchData_8012D9C8;

struct Elem_8034F204 { u8 x[0x2C]; };

struct Tbl_8034F204 { u8 pad[0x1C]; Elem_8034F204 arr[1]; };


struct RecoveredGlobal_8034FCF0_lbl_804F0BF0 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
u8 *TObjPlayer__sub_8034F1AC(u8 *item);
s32 rotate_matrix_z(s32, s32);
void init_slicer_launch_state(void *arg0);
u16 get_entity_id(void *);
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);
s16 get_validated_attack_stage(u8 *arg0);
f32 query_extended_state__10TObjPlayerFv(void *);
void get_weapon_color__11TItemWeaponFPv(f32 *, void *);
u8 *create__10TTecSlicerFPUs(SlicerLaunchData_8012D9C8 *);
extern const f32 lbl_805DFDF8;
s32 spawn_particle_effect(void *, s32);
void *find_entity_by_id(s32);
void *__nw__7TObjectFUl(u32);
void create_fire_explosion_effect(void *, f32, void *, int, void *);
void *TObjPlayer__sub_802E449C(void *a0);
extern const f32 lbl_805DFE00;
s32 rotate_matrix_x(s32, s32);
void draw_weapon_at_joint(s32 arg0, s8 arg1);
void TItemEffPG__begin_visual_fade(void *p);
void *create_particle_emitter(void *pos, s32 id);
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__13TUnk_804F0BF0[];
s32 get_render_pass__9TMainTaskFv();
s32 all_parents_unqueued_for_destruction__7TObjectFv();
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
extern s32 saved_model_draw_color[];
extern s32 model_material_color[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
void __dl__7TObjectFPv(void *);
}

// Built with -inline off,deferred: functions are written last to first, so
// the vtables come out 0810, 0908, 0A00, 0AF8, 0BF0, 0C08, 0C28 as in the original.
// The functions from 0x8034FE28 on were a separate unit; their literals continue
// this TU's .sdata2 pool at 0x805DFE14 (a 4-mod-8 address, so no TU starts there).

extern "C" {
const char *TItemEffPG__name = "TItemEffPG";
}

S_8035016C *S_8035016C::init_params() {
    TObjPlayer__sub_802E451C(this);
    hits = 10;
    pad_28 = 50.0f;
    required_charge = 1.0f;
    pad_30 = 2.5f;
    return this;
}

void TItemEffPG::create(void *arg0, void *arg1) {
    new TItemEffPG((TObject *)arg0, (S_8035016C *)arg1);
}

TItemEffPG::TItemEffPG(TObject *parent, S_8035016C *params) : TUnk_804E355C(parent, params) {
    void *visual;
    m_name = TItemEffPG__name;
    pad_C4 = params->pad_28;
    if (50.0f < pad_C4) {
        pad_C4 = 50.0f;
    }
    m_c8 = params->pad_30;
    required_charge = params->required_charge;
    pad_B0 *= 3.0f;
    visual = operator new(0x68);
    if (visual != NULL) {
        visual = TItemEffPG__visual_ct((u8 *)visual, (u8 *)this, (u8 *)params);
    }
    m_d0 = (u32)visual;
}

TItemEffPG::~TItemEffPG() {}

void TItemEffPG::run_task() {
    f32 temp_f1;
    f32 temp_f1_2;
    s32 var_r31;

    var_r31 = 1;
    if (has_game_join_id() == 0) {
        var_r31 = 0;
    }
    if (this->vfunc_7() == 0) {
        var_r31 = 0;
    }
    if (var_r31 != 0) {
        temp_f1 = this->body.radius;
        if (temp_f1 < this->pad_C4) {
            this->body.radius = (f32) (temp_f1 + this->m_c8);
            temp_f1_2 = this->pad_C4;
            if (temp_f1_2 < this->body.radius) {
                this->body.radius = temp_f1_2;
            }
        }
        check_hits();
        return;
    }
    if ((u32) this->m_down == 0U) {
        queue_destruction__7TObjectFv(this);
        disallow_rendering__7TObjectFv(this);
        return;
    }
    if ((u32) this->m_d0 != 0U) {
        TItemEffPG__begin_visual_fade(*(void * *)&this->m_d0);
        this->m_d0 = 0U;
    }
}

s32 TItemEffPG::vfunc_7() {
    TObjPlayer *player = get_player_by_client_id(client_id);
    if (player == NULL) {
        return 0;
    }
    if (player->get_photon_blast_charge() < required_charge) {
        return 0;
    }
    player->vfunc_76(required_charge);
    return 1;
}

void TItemEffPG::create(void *parent, void *params, void *count) {
    new TUnk_804F0C08((TObject *)parent, (S_8035016C *)params, (s32)count);
}

TUnk_804F0C08::TUnk_804F0C08(TObject *parent, S_8035016C *params, s32 count) : TItemEffPG(parent, params) {
    pad_D4 = count;
}

TUnk_804F0C08::~TUnk_804F0C08() {}

s32 TUnk_804F0C08::vfunc_7() {
    s32 temp_r4;

    temp_r4 = this->pad_D4;
    if (temp_r4 > 0) {
        this->pad_D4 = (temp_r4 - 1);
        return 1;
    }
    return 0;
}

typedef char RecoveredGlobal_8034FCF0_lbl_804F0BF0_size[sizeof(RecoveredGlobal_8034FCF0_lbl_804F0BF0) == 0x18 ? 1 : -1];
u8 *TItemEffPG__visual_ct(u8 *arg0, u8 *arg1, u8 *arg2) {
    f32 temp_f1;
    __ct__7TObjectFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8034FCF0_lbl_804F0BF0 *)&__vt__13TUnk_804F0BF0).value;
    *(s32 *)((s8 *)arg0 + 0x1C) = (s32) *(s32 *)((s8 *)arg2 + 0x18);
    *(s32 *)((s8 *)arg0 + 0x20) = (s32) *(s32 *)((s8 *)arg2 + 0x34);
    *(s32 *)((s8 *)arg0 + 0x24) = (s32) *(s32 *)((s8 *)arg2 + 0x38);
    *(f32 *)((s8 *)arg0 + 0x54) = (f32) *(f32 *)((s8 *)arg2 + 0x30);
    *(f32 *)((s8 *)arg0 + 0x44) = (f32) *(f32 *)((s8 *)arg2 + 0x28);
    VecCopy((Vec *)(arg0 + 0x5C), (const Vec *)arg2);
    temp_f1 = *(f32 *)((s8 *)arg2 + 0xC);
    ((TUnk_804F0BF0 *)arg0)->m_50 = temp_f1;
    *(f32 *)((s8 *)arg0 + 0x4C) = temp_f1;
    ((TUnk_804F0BF0 *)arg0)->m_48 = temp_f1;
    *(s32 *)((s8 *)arg0 + 0x3C) = 0;
    ((TUnk_804F0BF0 *)arg0)->m_40 = 0;
    ((TUnk_804F0BF0 *)arg0)->m_28 = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x2C) = 0.0f;
    ((TUnk_804F0BF0 *)arg0)->m_30 = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x34) = 0.0f;
    *(s32 *)((s8 *)arg0 + 0x38) = (s32)create_particle_emitter((arg0 + 0x5C), 0x83);
    ((TUnk_804F0BF0 *)arg0)->m_58 = 0;
    return arg0;
}

TUnk_804F0BF0::~TUnk_804F0BF0() {
    if (this->m_38 != NULL) { queue_destruction__7TObjectFv(this->m_38); *(s32 *)((s8 *)this + 0x38) = 0; }
}

void TUnk_804F0BF0::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    *(s32 *)((s8 *)arg0 + 0x3C) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C) + 0x71C);
    *(s32 *)((s8 *)arg0 + 0x40) = (s32) (*(s32 *)((s8 *)arg0 + 0x40) - 0xE38);
    if ((s32) *(s32 *)((s8 *)arg0 + 0x58) == 0) {
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x50);
        if (temp_f1 < *(f32 *)((s8 *)arg0 + 0x44)) {
            *(f32 *)((s8 *)arg0 + 0x50) = (f32) (temp_f1 + *(f32 *)((s8 *)arg0 + 0x54));
            temp_f1_2 = *(f32 *)((s8 *)arg0 + 0x44);
            if (temp_f1_2 < *(f32 *)((s8 *)arg0 + 0x50)) {
                *(f32 *)((s8 *)arg0 + 0x50) = temp_f1_2;
            }
        }
        temp_f0 = *(f32 *)((s8 *)arg0 + 0x50);
        *(f32 *)((s8 *)arg0 + 0x4C) = temp_f0;
        *(f32 *)((s8 *)arg0 + 0x48) = temp_f0;
    } else {
        temp_f1_3 = *(f32 *)((s8 *)arg0 + 0x28);
        if (temp_f1_3 <= -1.0f) {
            queue_destruction__7TObjectFv(arg0);
            disallow_rendering__7TObjectFv((TObject *)arg0);
        } else {
            *(f32 *)((s8 *)arg0 + 0x28) = (f32) (temp_f1_3 - 0.06666667f);
        }
    }
    play_persistent_sound(0x4001A343, (s32)arg0, (u32)(arg0 + 0x5C), 0, 0);
}

void TUnk_804F0BF0::render() {
    u8 *arg0 = (u8 *)this;
    if (all_parents_unqueued_for_destruction__7TObjectFv() == 0 || find_equipped_item((int) (*(s32 *)((s8 *)arg0 + 0x1C))) == 0U) {
        return;
    }
    {
        if (((void *) this->m_20 != NULL) && (get_render_pass__9TMainTaskFv() == 1)) {
            set_draw_list_mask(3);
            saved_model_render_flags = model_render_flags;
            saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
            saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
            copy_argb((NJS_ARGB *)saved_model_draw_color, (NJS_ARGB *)model_material_color);
            model_render_flags |= 0x20;
            set_constant_material((const NJS_ARGB *)((arg0 + 0x28)));
            TParticleCtrl::begin_effect_render();
            TObjFish::set_global_param((int) (*(s32 *)((s8 *)arg0 + 0x24)));
            push_matrix();
            post_translate_matrix((u8 *)&this->unk_5C);
            push_matrix();
            rotate_matrix_y(0, (int) (*(s32 *)((s8 *)arg0 + 0x3C)));
            scale_current_matrix((u8 *)&this->m_48);
            draw_ginja_model((*(s32 *)(this->m_20 + 4)));
            pop_matrix();
            push_matrix();
            rotate_matrix_y(0, this->m_40);
            scale_current_matrix((u8 *)&this->m_48);
            draw_ginja_model((*(s32 *)((s8 *)(*(void **)(this->m_20 + 0x2C)) + 4)));
            pop_matrix();
            pop_matrix();
            TParticleCtrl::end_effect_render();
            copy_argb((NJS_ARGB *)model_material_color, (NJS_ARGB *)saved_model_draw_color);
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            model_render_flags = saved_model_render_flags;
        }
    }
}

void TItemEffPG__begin_visual_fade(void* p) { *(s32*)((char*)p + 0x58) = 1; }

u8 *TItemEffPG::create() {
    if (this != NULL) {
        return (u8 *)new TUnk_804F0AF8(tl_05, (u8 *)this);
    }
    return NULL;
}

TUnk_804F0AF8::TUnk_804F0AF8(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(1);
    unk_1F8 = -30947;
    m_1fc = -7281;
}

TUnk_804F0AF8::~TUnk_804F0AF8() {}

void TUnk_804F0AF8::update_attack() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (s32)((void*)((void*)16384)), (s32)((void*)((void*)0))); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1fc), (s32)((void*)((void*)3640)), (s32)((void*)((void*)0))); }

void TUnk_804F0AF8::update_idle() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (s32)((void*)((void*)-8192)), (s32)((void*)((void*)-30947))); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1fc), (s32)((void*)((void*)-1820)), (s32)((void*)((void*)-7281))); }

void TUnk_804F0AF8::reserved_53() { draw_weapon_at_joint((s32)this, (s8)((void*)49)); update_trail_slot(0); update_trail_slot(1); }

void TUnk_804F0AF8::vfunc_60() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 2:
        rotate_matrix_z(0, *(s32 *)&this->unk_1F8);
        return;
    case 8:
        rotate_matrix_z(0, this->m_1fc);
        return;
    }
}

u8 *TObjPlayer::create_gi_gue_bazooka(s32 arg0) {
    if (arg0 != 0) {
        return (u8 *)new TUnk_804F0A00(tl_05, (u8 *)arg0);
    }
    return NULL;
}

TUnk_804F0A00::TUnk_804F0A00(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x8000);
    unk_1F8 = -0x1C71;
    m_1fc = -0x1555;
    unk_200 = 0x238E;
}

TUnk_804F0A00::~TUnk_804F0A00() {}

void TUnk_804F0A00::update_attack() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (s32)((void*)((void*)-3640)), (s32)((void*)((void*)0))); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1fc), (s32)((void*)((void*)2730)), (s32)((void*)((void*)0))); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x200), (s32)((void*)((void*)-1820)), (s32)((void*)((void*)0))); }

void TUnk_804F0A00::update_idle() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (s32)((void*)((void*)1820)), (s32)((void*)((void*)7281))); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1fc), (s32)((void*)((void*)-1820)), (s32)((void*)((void*)-5461))); TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x200), (s32)((void*)((void*)1820)), (s32)((void*)((void*)9102))); }

void TUnk_804F0A00::vfunc_60() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 2:
        rotate_matrix_x(0, *(s32 *)&this->unk_1F8);
        return;
    case 3:
        rotate_matrix_x(0, this->m_1fc);
        return;
    case 5:
        rotate_matrix_z(0, *(s32 *)&this->unk_200);
        return;
    case 4:
        rotate_matrix_z(0, -*(s32 *)&this->unk_200);
        return;
    }
}

void TUnk_804F0A00::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    desc->pad_74 = (void *)TObjPlayer::spawn_fire_explosion_at_item;
    desc->pad_70 = (void *)TObjPlayer::spawn_fire_explosion_for_item;
    desc->flags |= 0x80;
}

s32 TObjPlayer::spawn_fire_explosion(u32 a0, s32 a1) {
    S_802E449C info;
    void *o;
    TObjPlayer__sub_802E449C(&info);
    ((TObjPlayer *)a0)->fill_status_info(&info);
    VecCopy(&info.position, (const Vec *)a1);
    info.hits = 10;
    new TUnk_804A2548(tl_05, &info);
    o = __nw__7TObjectFUl(0x64);
    if (o != NULL) {
        create_fire_explosion_effect(o, lbl_805DFE00, &info, 0, tl_particle);
    }
}

void TObjPlayer::spawn_fire_explosion_at_item(s32 arg0, s32 arg1) {
    Ctx_80125628 *ctx = (Ctx_80125628 *)arg1;
    u32 p = (u32)find_item_by_id(arg0);
    if (p != 0U) {
        TObjPlayer::spawn_fire_explosion(p, (s32)((s32)ctx->obj->elems[ctx->idx].f1c));
    }
}

void TObjPlayer::spawn_fire_explosion_for_item(s32 arg0, s32 arg1) {
    u32 temp_r3 = (u32)find_item_by_id(arg0);
    if (temp_r3 != 0U) {
        TObjPlayer::spawn_fire_explosion(temp_r3, arg1);
    }
}

u8 *TObjPlayer::create_rappys_fan() {
    if (this != NULL) {
        return (u8 *)new TUnk_804F0908(tl_05, (u8 *)this);
    }
    return NULL;
}

TUnk_804F0908::TUnk_804F0908(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    hit_callback = (WeaponHitCallback)TObjPlayer::spawn_particle_at_entity_slot;
    set_weapon_flags(2);
}

TUnk_804F0908::~TUnk_804F0908() {}

void TUnk_804F0908::emit_marker_effects() {
    f32 tmp[4];
    SlicerLaunchData_8012D9C8 launch;
    u8 *t;
    init_slicer_launch_state(&launch);
    launch.player = get_entity_id(*(u8 **)&owner);
    launch.weapon = get_item_id();
    launch.textures = *(void **)((s8 *)this + 0x24);
    launch.model = *(void **)((s8 *)this + 0x188);
    launch.kind = TObjPlayer__sub_801D2F4C((s16 *)(*(u8 **)&owner + 0x7CC));
    launch.stage = get_validated_attack_stage(*(u8 **)&owner + 0x7CC);
    launch.multiplier = query_extended_state__10TObjPlayerFv(*(u8 **)&owner);
    get_weapon_color__11TItemWeaponFPv(tmp, this);
    copy_argb((NJS_ARGB *)launch.color, (NJS_ARGB *)tmp);
    launch.facing = *(s32 *)((s8 *)(*(u8 **)&owner) + 0x60);
    launch.spin = 0;
    get_joint_position(3, launch.first);
    get_joint_position(2, launch.second);
    t = create__10TTecSlicerFPUs(&launch);
    if (t != NULL) {
        *(s32 *)((s8 *)t + 0x5C) += 0x4000;
        *(f32 *)((s8 *)t + 0x68) = lbl_805DFDF8;
        *(f32 *)((s8 *)t + 0x6C) = lbl_805DFDF8;
        *(f32 *)((s8 *)t + 0x70) = lbl_805DFDF8;
        *(s32 *)((s8 *)t + 0x13C) = 0;
    }
}

void TObjPlayer::spawn_particle_at_entity_slot(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *temp_r5;
    void *entity;
    entity = find_entity_by_id(arg2);
    if (entity != NULL) {
        temp_r5 = *(u8 **)((s8 *)entity + 0xA4);
        if ((temp_r5 != NULL) && (arg3 < (s32) *(s32 *)((s8 *)entity + 0xA8))) {
            spawn_particle_effect(&((Tbl_8034F204 *)temp_r5)->arr[arg3], 0x1BF);
        }
    }
}

u8 *TObjPlayer__sub_8034F1AC(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804F0810(tl_05, item);
    }
    return NULL;
}

TUnk_804F0810::TUnk_804F0810(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(1);
    unk_1F8 = 13653;
}

TUnk_804F0810::~TUnk_804F0810() {}

void TUnk_804F0810::update_attack() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (s32)((void*)(-4551)), (s32)((void*)(0))); }
void TUnk_804F0810::update_idle() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (s32)((void*)(1820)), (s32)((void*)(13653))); }
void TUnk_804F0810::reserved_53() { draw_weapon_at_joint((s32)this, (s8)((void*)49)); update_trail_slot(0); update_trail_slot(1); }

void TUnk_804F0810::vfunc_60() {
    switch (TObjPlayer::get_player_list()) {
    case 1:
        ((s32)rotate_matrix_z(0, (s32)(((P_8034F020 *)this)->f1F8)));
        break;
    }
}

void TUnk_804F0810::emit_marker_effects() {
    u8 sp8[0x18];
    struct VObj_8034EFDC *o = (struct VObj_8034EFDC *)this->owner;
    o->m63(0x30, sp8);
    spawn_particle_effect(sp8, 0x1D0);
}
