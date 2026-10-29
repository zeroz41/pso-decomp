#include "pso/player/PlayerAttackParams.h"
#include "types.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/object/obj_band.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneGibbles.h"
#include "pso/misc/TTecZonde.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneMoja.h"

extern "C" {
f32 random_ratio__9TObjCharaFv(s32);
extern const f32 lbl_805D9BE0;
s32 spawn_particle_effect(s32, s32);
struct Vec_800ACB58 { f32 x, y, z; };
s32 apply_actor_gravity(void *, int, f32);
}
void move_with_wall_slide(u8 *arg0);
extern "C" {
void queue_destruction__7TObjectFv(void *arg0);
s32 spawn_dead_spot_scale15(void *, int);
s32 advance_animation_playback(void *);
s32 play_sound_effect(s32, void *, int, int);
s32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix_from(void *);
s32 pop_matrix(void);
extern u8 identity_matrix[];
extern const f32 lbl_805D9BE4;
extern const f32 lbl_805D9BE8;
extern const f32 lbl_805D9BEC;
extern const f32 lbl_805D9BF0;
extern const f32 lbl_805D9BF4;
extern const f32 lbl_805D9BF8;
void TObjPlayer::clamp_stat_354() {
    extern f32 lbl_805D9BD8;
    extern f32 lbl_805D9BDC;
    f32 lo = lbl_805D9BD8;
    if (this->m_354 < lo) {
        this->m_354 = lo;
    } else if (lbl_805D9BDC < this->m_354) {
        this->m_354 = (f32) lbl_805D9BDC;
    }
    *(s32 *)&this->m_374 = (s32) this->m_354;
}
void TObjEneMoja::select_rare_variant() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    temp_r0 = (this->variant);
    if (temp_r0 >= 1) {
        (this->variant) = 1;
        ((TObjEnemy *)arg0)->set_param(2);
        ((TObjEneMoja *)arg0)->bindModel(2);
        return;
    }
    if (temp_r0 <= 0) {
        if (random_ratio__9TObjCharaFv((s32) arg0) < lbl_805D9BE0) {
            (this->variant) = 1;
            ((TObjEnemy *)arg0)->set_param(2);
            ((TObjEneMoja *)arg0)->bindModel(2);
            return;
        }
        (this->variant) = 0;
        ((TObjEnemy *)arg0)->set_param(1);
        ((TObjEneMoja *)arg0)->bindModel(1);
    }
}
void TObjEneMoja::update_death_state() {
    u8 *arg0 = (u8 *)this;
    extern const f32 lbl_805D9BD8;
    Vec_800ACB58 v;

    advance_animation_playback(arg0);
    if (objInBand((GameObj *)arg0, (f32)lbl_805D9BD8) != 0) {
        play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x3A809)), (u8 *)&this->position, 0, 0);
    }
    if (objInBand((GameObj *)arg0, (f32)lbl_805D9BE4) != 0) {
        v.x = lbl_805D9BD8;
        v.y = lbl_805D9BE8;
        v.z = lbl_805D9BEC * *(f32 *)(this->m_2b0 + 0x10);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, this->rotation_y);
        rotate_vector_by_matrix(0, &v, &v);
        pop_matrix();
        vec3_add_to(&v, (u8 *)&this->position);
        play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x3AD03)), &v, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x300);
        spawn_particle_effect((s32) &v, 0xF0);
        spawn_dead_spot_scale15(&v, 0x14);
        ((TObjPlayer *)(&v))->spawn_effect_at_ground(0x32);
    }
    if (this->m_c0 < lbl_805D9BEC * (lbl_805D9BF0 * this->m_c8)) {
        move_with_wall_slide(arg0);
        (*(f32 *)&this->unk_308) *= lbl_805D9BEC;
        this->m_310 *= lbl_805D9BEC;
    } else if (!((this->actorFlags) & 0x800000)) {
        apply_actor_gravity(arg0, 0, lbl_805D9BD8);
    }
    this->sinkOffset -= lbl_805D9BF4;
    if (this->sinkOffset < lbl_805D9BF8) {
        queue_destruction__7TObjectFv(arg0);
    }
}

void TObjEneMoja::vfunc_63() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r6;
    if ((s16) this->mode != 9) {
        this->mode = 9;
        this->m_b8 = 7;
        temp_r6 = (u8 *)this->bodies;
        *(s32 *)((s8 *)temp_r6 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r6 + 0x18) & 0xFFFF7FFE);
        spawn_particle_effect((s32)(arg0 + 0x2FC), 0xF1);
        ((TObjPlayer *)arg0)->refresh_lobby_state();
        ((TObjEnemy *)arg0)->send_entity_set_flags();
        this->appearance = 0;
    }
}

extern const f32 lbl_805D9BD8;

void TObjPlayer::update_ground_effect() {
    u8 *temp_r4;

    ((s32 (*)())advance_animation_playback)();
    if (objInBand((GameObj *)(this), lbl_805D9BD8) != 0) {
        ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)((TObjEnemy *)(this))->remap_sound_for_area((s32)(0x3A807)), (void *) (((u8 *)this) + 0x38), 0, 0);
        TObjPlayer::play_effect_if_v2(-0x300);
    }
    this->m_310 = (f32) lbl_805D9BD8;
    *(f32 *)&this->unk_308 = (f32) lbl_805D9BD8;
    apply_actor_gravity(this, 0, lbl_805D9BD8);
    this->update_collisions();
    if ((u32) this->m_b4 != 8U) {
        this->actorFlags = (s32) (this->actorFlags & 0xFBFFF9FF);
        temp_r4 = (unsigned char *) (this->bodies);
        *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFBFFFFFF);
        this->m_33e = (s16) this->hp;
        *(s32 *)&this->unk_388 = 0;
    }
}
}

#include "pso/TParticleCtrl.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TTecFoie.h"
#include "pso/misc/TTecGiBarta.h"
#include "pso/misc/TTecMegid.h"
#include "pso/object/TObjFish.h"

typedef struct MojaCollision_800ADE48 {
    u8 pad[0x18];
    u32 flags;
} MojaCollision_800ADE48;

typedef struct Moja_800ADE48 {
    u8 pad0[0x30];
    u32 flags;
    u8 pad34[0xA4 - 0x34];
    MojaCollision_800ADE48 *collision;
    u8 padA8[0xB8 - 0xA8];
    s16 action;
    u8 padBA[0x326 - 0xBA];
    s16 mode;
    s16 phase;
    u8 pad32A[0x374 - 0x32A];
    s32 f374;
    u8 pad378[0x380 - 0x378];
    s32 attack_kind;
} Moja_800ADE48;

struct Vec_800AE18C { f32 x, y, z; };

struct Vec_800AEE54 { f32 x, y, z; };

struct V398Base_800ADAAC { char pad[0x18]; };

struct V398_800ADAAC : V398Base_800ADAAC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(void *, void *);
};

struct Vec_800ADAAC { f32 x, y, z; };

struct VBase_18_247a8e { char pad[0x18]; };

struct VObj_18_247a8e : VBase_18_247a8e {
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
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual s32 m20(void *, f32);
    virtual void m21();
    virtual void m22();
    virtual s32 m23(void *);
};

struct Vec_800ACFE8 { f32 x, y, z; };
struct Hit_800ACFE8 { s32 a; f32 b; };
struct VBase_800ACFE8 { u8 pad[0x18]; };
struct VObj_800ACFE8 : VBase_800ACFE8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(void *, Hit_800ACFE8, s32, s32, s32);
    virtual void m22();
    virtual void m23(void *);
};
struct Sub_800ACFE8 { u8 pad[0x18]; u32 f18; };
struct Obj_800ACFE8 {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0x38 - 0x34];
    Vec_800ACFE8 f38;
    u8 pad44[0xA4 - 0x44];
    Sub_800ACFE8 *fA4;
    u8 padA8[0xB4 - 0xA8];
    u32 fB4;
    u8 padB8[0xC8 - 0xB8];
    f32 fC8;
    u8 padCC[0x290 - 0xCC];
    Vec_800ACFE8 f290;
    Vec_800ACFE8 f29C;
    u8 *f2A8;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec_800ACFE8 f2FC;
    u8 pad308[0x318 - 0x308];
    s32 f318;
    u8 pad31C[0x328 - 0x31C];
    s16 f328;
    u8 pad32A[0x33C - 0x32A];
    s16 f33C;
    u8 pad33E[0x378 - 0x33E];
    f32 f378;
    u8 pad37C[0x384 - 0x37C];
    s32 f384;
};

struct Vec_800AE7F4 { f32 x, y, z; };

struct Hit_800AE7F4 {
    s32 type; s32 power; s32 c; f32 fpow;
    Hit_800AE7F4(f32 f) { type = 0; fpow = f; power = *(s32 *)&fpow; c = 0; }
};

struct VBase_800AE7F4 { char pad[0x18]; };

struct VObj_800AE7F4 : VBase_800AE7F4 {
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
    virtual void m21(void *, const Hit_800AE7F4 &, s32, s32, s32);
    virtual void m22();
    virtual void m23(void *);
};

struct Col_800AE7F4 { u8 pad[0x18]; u32 flags; };

struct Moja_800AE7F4 {
    u8 pad0[0x30];
    u32 flags;
    u8 pad34[0x38 - 0x34];
    Vec_800AE7F4 pos;
    u8 pad44[0x50 - 0x44];
    Vec_800AE7F4 home;
    u8 pad5C[0x60 - 0x5C];
    s32 angle;
    u8 pad64[0xA4 - 0x64];
    Col_800AE7F4 *collision;
    u8 padA8[0xB4 - 0xA8];
    u32 fB4;
    u8 padB8[0xC8 - 0xB8];
    f32 fC8;
    u8 padCC[0x290 - 0xCC];
    Vec_800AE7F4 from;
    Vec_800AE7F4 dest;
    u8 pad2A8[0x2FC - 0x2A8];
    Vec_800AE7F4 center;
    Vec_800AE7F4 vel;
    u8 pad314[0x328 - 0x314];
    s16 phase;
    u8 pad32A[0x33C - 0x32A];
    s16 f33C;
    u8 pad33E[0x374 - 0x33E];
    s32 f374;
    f32 speed;
    u8 pad37C[0x384 - 0x37C];
    s32 f384;
};

struct Vec_800AF080 { f32 x, y, z; };

struct FadeBase_800AF080 { u8 pad[0x14]; };

struct Fade_800AF080 : FadeBase_800AF080 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void m6(); virtual void m7();
    u32 f18;
};

struct Body_800AF080 { u8 pad[0x39C]; Fade_800AF080 fades[4]; };

struct EneBase_800AF080 { u8 pad[0x18]; };

struct Ene_800AF080 : EneBase_800AF080 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual s32 m9(f32, f32, f32);
};

struct Vec_800AE450 { f32 x, y, z; };

struct Hit_800AE450 {
    s32 type; s32 power; s32 c; f32 fpow;
    Hit_800AE450(f32 f) { type = 0; fpow = f; power = *(s32 *)&fpow; c = 0; }
};

struct VBase_800AE450 { char pad[0x18]; };

struct VObj_800AE450 : VBase_800AE450 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(void *, const Hit_800AE450 &, s32, s32, s32);
    virtual void m22();
    virtual void m23(void *);
};

struct Col_800AE450 { u8 pad[0x18]; u32 flags; };

struct Turn_800AE450 { u8 pad[8]; s32 step; };

struct Moja_800AE450 {
    u8 pad0[0x30];
    u32 flags;
    u8 pad34[0x38 - 0x34];
    Vec_800AE450 pos;
    u8 pad44[0x50 - 0x44];
    Vec_800AE450 home;
    u8 pad5C[0x60 - 0x5C];
    s32 angle;
    u8 pad64[0xA4 - 0x64];
    Col_800AE450 *collision;
    u8 padA8[0xB4 - 0xA8];
    u32 fB4;
    s16 fB8;
    u8 padBA[0xC8 - 0xBA];
    f32 fC8;
    u8 padCC[0x290 - 0xCC];
    Vec_800AE450 from;
    Vec_800AE450 dest;
    u8 pad2A8[0x2FC - 0x2A8];
    Vec_800AE450 center;
    Vec_800AE450 vel;
    u8 pad314[0x328 - 0x314];
    s16 phase;
    u8 pad32A[0x33C - 0x32A];
    s16 f33C;
    u8 pad33E[0x350 - 0x33E];
    Turn_800AE450 *turn;
    u8 pad354[0x374 - 0x354];
    s32 f374;
    f32 speed;
    u8 pad37C[0x384 - 0x37C];
    s32 f384;
};

struct Ang_800AD3D8 { s32 x, y, z; };

struct TgtBase_800AD3D8 { u8 pad[0x18]; };

struct Tgt_800AD3D8 : TgtBase_800AD3D8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(void *, Hit_800ACFE8, s32, s32, s32);
    u8 pad1C[0x2FC - 0x1C];
    Vec_800AE18C pos;
};

struct MojaInfo_800AD3D8 { u8 pad0[4]; f32 speed; s32 turn; };

struct Moja_800AD3D8 {
    u8 pad0[0x30];
    u32 flags;
    u8 pad34[0x60 - 0x34];
    s32 rot_y;
    u8 pad64[0xB4 - 0x64];
    u32 anim_state;
    s16 anim;
    u8 padBA[0x2A8 - 0xBA];
    Tgt_800AD3D8 *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec_800AE18C pos;
    u8 pad308[0x318 - 0x308];
    u32 f318;
    u8 pad31C[0x328 - 0x31C];
    s16 phase;
    u8 pad32A[0x338 - 0x32A];
    u16 target_id;
    u8 pad33A[2];
    s16 timer;
    u8 pad33E[0x350 - 0x33E];
    MojaInfo_800AD3D8 *info;
    u8 pad354[0x368 - 0x354];
    s32 kind;
    u8 pad36C[0x384 - 0x36C];
    s32 count;
};

typedef struct Info_800AEBB8 {
    u8 pad0[4];
    f32 f4;
    s32 f8;
} Info_800AEBB8;

typedef struct Moja_800AEBB8 {
    u8 pad0[0x50];
    Vec_800AE18C pos;
    u8 pad5C[0x2FC - 0x5C];
    Vec_800AE18C f2FC;
    u8 pad308[0x328 - 0x308];
    s16 phase;
    u8 pad32A[0x350 - 0x32A];
    Info_800AEBB8 *info;
    u8 pad354[0x374 - 0x354];
    s32 f374;
} Moja_800AEBB8;

extern "C" {
s32 update_movement_status__9TObjCharaFv();
s32 update_action_hold_status__9TObjCharaFv();

f32 enemy_pursue_point(void *, s32, Vec_800AE18C *, void *, f32, f32);
s32 select_enemy_destination(void *, Vec_800AE18C *, int);
s32 copy_position_if_valid__10TObjPlayerFii(void *, Vec_800AE18C *);

f32 horizontal_distance_squared(int, void *);

extern u8 **lbl_805D50D4;
extern const f32 lbl_805D9C34;
extern const f32 lbl_805D9C38;
u16 find_nearest_visible_player(void *, int, f32);
s32 check_path_obstructed(void *, void *);
u8 *get_player_data__10TObjPlayerFi(s32);
s32 obj_testFlags30__14TObjCollidableFUl(void *, int);
s32 get_entity_id(void *);
s32 get_current_floor();
u32 csnVector(void *, void *, int);
u8 *get_enemy_entity(u16);
void *get_player_by_client_id(s32 i);
s32 subtract_vector(void *, void *);
extern s32 lbl_8043B0B4[];
extern s32 registered_player_count;
extern s32 lbl_805D5870;
void acquire_target__11TObjEneMojaFPv(u8 *arg0);
s32 TObjPlayer__sub_800ACA0C(void *);

void update_attack_jump__11TObjEneMojaFv(Obj_800ACFE8 *);
struct Moja_800AE450;
s32 submit_cursor_candidate(void *, int);
s32 minimap_render_dot(void *, int, int, int, f32);
extern const f32 lbl_805D9BDC;

f32 calc_xz_distance_sq(void *, void *, Vec_800AE18C *);
f32 atan2_float(f32, f32);
s32 angle_difference_abs(s32, s32);
extern const f64 lbl_8043B0C8[];
extern u32 *lbl_805D50CC;
extern const f32 lbl_805D9C1C;
extern const f32 lbl_805D9C30;

s32 obj_is_hit_receivable();
s32 lookup_entry_by_value__10TObjPlayerFPvf(void *);

s32 mult_vec_array__10TObjPlayerFUll(int, int, void *, int);
void set_matrix_identity(u8 *arg0);
s32 push_matrix();

s32 post_translate_matrix(void *);
extern void *lbl_805D50DC;
extern const f32 lbl_805D9C04;
extern const f32 lbl_805D9C28;
extern const f32 lbl_805D9C2C;
s32 calc_velocity_toward_destination(void *, Vec_800ACFE8, Vec_800ACFE8, f32);
s16 get_attack_params_atp_min(s32);
s32 is_split_screen();
f32 newton_sqrtf(f32);

extern s32 local_client_id;
extern s32 lbl_805D5868;
extern const f32 lbl_805D9C00;
extern const f32 lbl_805D9C08;
extern const f32 lbl_805D9C0C;

void pop_matrices(s32);

extern const f32 lbl_805D9C3C;
extern const f32 lbl_805D9C40;
extern const f32 lbl_805D9C44;
extern const f32 lbl_805D9C48;
void update_appearance_jump__11TObjEneMojaFv(Moja_800AE7F4 *self);
s32 render_with_position_override__9TObjEnemyFPUcl(void *, f32 *, s32, f32);
s32 get_camera_mode__11TCameraCtrlFv();
s32 update__15RenderFadeStateFv(void *, s32, s32, s32);
s32 restore_scene_lighting(s32, s32);
s32 select_actor_lighting(void *);
s32 defer_render__7TObjectFv(void *);
s32 translate_matrix(s32, f32, f32, f32);

s32 draw_chunk_object(s32);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
extern const f32 lbl_805D9C50;
extern const f32 lbl_805D9C54;
extern const f32 lbl_805D9C58;
void render__11TObjEneMojaFv(u8 *arg0);

s32 approach_angle_limited(s32, s32, s32);

extern Vec_800AE450 lbl_8050BEE0;
void update_appearance_drop__11TObjEneMojaFv(Moja_800AE450 *self);

s32 enemy_turn_toward_dest(void *, s32);
void enemy_set_heading_velocity(TObjEnemy *arg0, s32 arg1, f32 farg0);

void *__nw__7TObjectFUl(u32);
void *spawn_directional_particle(void *pos, void *dir, s32 id);

extern s32 game_difficulty_selection;
extern s32 tl_07;
extern const f32 lbl_805D9C10;
extern const f32 lbl_805D9C14;
extern const f32 lbl_805D9C18;
extern const f32 lbl_805D9C20;
extern const f32 lbl_805D9C24;
void enemy_wander_home__9TObjEnemyFlfff(void *, s32, f32, f32, f32);

extern const f32 lbl_805D9C4C;
}

void TObjEneMoja::vfunc_62() {
    MojaCollisionState *moja_collision_state;

    switch (mode) {
    case 4:
        (this->actorFlags) = (s32) ((this->actorFlags) & 0xF9FFF9FF);
        moja_collision_state = (*(MojaCollisionState * *)&this->bodies);
        moja_collision_state->flags = (s32) (moja_collision_state->flags & 0xFBFFFFFF);
        referenceHp = (s16) hp;
        roar = 0;
        break;
    default:
        mode = 8;
    case 8:
        m_b8 = 6;
        (this->actorFlags) = (s32) ((this->actorFlags) & 0xFFDBFFFF);
        break;
    }
    appearance = 0;
}

extern const s32 lbl_805D9BFC;

void TObjPlayer::update_invincibility() {
    s16 temp_r4;

    ((s32 (*)())advance_animation_playback)();
    if (!(this->actorFlags & 0x800000)) {
        ((s32 (*)(void *, s32, f32))apply_actor_gravity)(this, 0, lbl_805D9BD8);
    }
    update_collisions();
    temp_r4 = *(s16 *)&this->unk_33C;
    *(s16 *)&this->unk_33C = (temp_r4 - 1);
    if (temp_r4 < 0) {
        this->actorFlags &= 0xFFFFFEFF;
        *(s32 *)((s8 *)this->bodies + 0x18) |= lbl_805D9BFC;
        *(s16 *)&this->unk_33C = (s16) *(s16 *)((s8 *)this + 0x33A);
        this->m_33e = (s16) this->hp;
    }
}

void TObjEneMoja::vfunc_61() {
    s32 gbits;

    switch (mode) {
    case 4:
        (this->actorFlags) &= 0xFFFFFEFF;
        ((*(MojaCollisionState * *)&this->bodies))->flags |= lbl_805D9BFC;
        referenceHp = (s16) hp;
        roar = 0;
        break;
    default:
        mode = 7;
        (this->timer) = 0xF;
    case 7:
        m_b8 = 0;
        (this->actorFlags) = (s32) ((this->actorFlags) & 0xFF9BFFFF);
        break;
    }
    appearance = 0;
}

void update_attack_jump__11TObjEneMojaFv(Obj_800ACFE8 *arg0) {
    Vec_800ACFE8 delta;
    u8 *p;
    s32 i;
    f32 d;

    arg0->f30 |= 0x06000000;
    arg0->fA4->f18 &= ~1;
    ((s32 (*)(void *))advance_animation_playback)(arg0);
    switch (arg0->f328) {
    case 0:
    default:
        ((s32 (*)(void *, s32, f32))apply_actor_gravity)(arg0, 0, lbl_805D9BD8);
        if (objInBand((GameObj *)arg0, (f32)lbl_805D9C00) != 0) {
            if (arg0->f2A8 != NULL) {
                Vec_800ACFE8 dest = *(Vec_800ACFE8 *)(arg0->f2A8 + 0x2FC);
                if (select_enemy_destination(arg0, (Vec_800AE18C *)&dest, 1) != 0) {
                    Vec_800ACFE8 pos = arg0->f2FC;
                    copy_position_if_valid__10TObjPlayerFii(arg0, (Vec_800AE18C *)&pos);
                    VecCopy((Vec *)&delta, (const Vec *)&arg0->f29C);
                    subtract_vector(&delta, &arg0->f2FC);
                    arg0->f378 = lbl_805D9BF8 + newton_sqrtf(delta.x * delta.x + delta.z * delta.z);
                    arg0->f378 = arg0->f378 / (lbl_805D9C04 / arg0->fC8);
                    arg0->f328 = 1;
                } else {
                    arg0->f328 = 2;
                }
            } else {
                arg0->f328 = 2;
            }
            ((s32 (*)(void *, int))spawn_particle_effect)(&arg0->f38, 0xF3);
            ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x3A802)), &arg0->f38, 0, 0);
        }
        break;
    case 1:
        calc_velocity_toward_destination(arg0, arg0->f290, arg0->f29C, arg0->f378);
        move_with_wall_slide((u8 *)arg0);
        if (objInBand((GameObj *)arg0, (f32)lbl_805D9C08) != 0) {
            arg0->f328 = 2;
            for (i = 0; i < lbl_805D5868; i++) {
                p = get_player_data__10TObjPlayerFi(i);
                if (p == NULL || (u16)get_entity_id(p) >= 0x1000) {
                    break;
                }
                if (((s32 (*)(void *))obj_is_hit_receivable)(p) != 0) {
                    d = horizontal_distance_squared((s32)(p + 0x2FC), &arg0->f2FC);
                    if (d <= ((AttackParams *)(arg0->f318))->get_damage_radius() * ((AttackParams *)(arg0->f318))->get_damage_radius()) {
                        Hit_800ACFE8 hit;
                        hit.a = 0;
                        hit.b = get_attack_params_atp_min(arg0->f318);
                        ((VObj_800ACFE8 *)p)->m21(arg0, hit, 0, -1, -1);
                        ((VObj_800ACFE8 *)p)->m23(arg0);
                    }
                    if (d <= lbl_805D9C0C && is_split_screen() == 0 && local_client_id == (u16)get_entity_id(p)) {
                        TCameraCtrl::set_shake_preset(0);
                    }
                }
            }
            ((s32 (*)(void *, int))spawn_particle_effect)(&arg0->f38, 0xCB);
            ((s32 (*)(void *, int))spawn_particle_effect)(&arg0->f38, 0xF0);
            ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x3AD03)), &arg0->f38, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x300);
        }
        break;
    case 2:
        ((s32 (*)(void *, s32, f32))apply_actor_gravity)(arg0, 0, lbl_805D9BD8);
        if (arg0->fB4 != 4) {
            arg0->f30 &= ~0x06200000;
            arg0->fA4->f18 |= 1;
            arg0->f384 = -1;
            arg0->f33C = 0;
        }
        break;
    }
}

#define arg0 ((u8 *)self_800ADAAC)

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
#define self ((Moja_800AD3D8 *)self_800AD3D8)
s32 TObjEneMoja::update_technique_state(void *self_800AD3D8) {
    Vec_800AE18C dir;
    Vec_800AE18C pos;
    Ang_800AD3D8 ang;
    s32 ang2;
    void *obj;
    u8 *p;
    s32 a;
    u16 id;
    id = self->target_id;
    if (id < 0x1000) {
        p = (u8 *)get_player_by_client_id(id);
        if (p != NULL && ((TObjPlayer *)p)->get_field_3e4() == get_current_floor() &&
            ((TObjBase *)self)->get_room() == ((TObjBase *)p)->get_room()) {
            self->target = (Tgt_800AD3D8 *) p;
        } else {
            self->target = NULL;
        }
    } else if (id < 0x4000) {
        self->target = (Tgt_800AD3D8 *) get_enemy_entity(id);
    } else {
        self->target_id = 0xFFFF;
        self->target = NULL;
    }
    ((s32 (*)(void *)) advance_animation_playback)(self);
    switch (self->phase) {
    case 0:
    default:
        if (self->target == NULL) {
            self->phase = 2;
            self->count = -1;
            self->flags &= 0xFFDFFFFF;
        } else {
            Vec_800AE18C dest = self->target->pos;
            if (select_enemy_destination(self, &dest, 1) != 0) {
                Vec_800AE18C cur = self->pos;
                copy_position_if_valid__10TObjPlayerFii(self, &cur);
                a = enemy_turn_toward_dest(self, self->info->turn);
                enemy_set_heading_velocity((TObjEnemy *)((u8 *)self), self->rot_y, self->info->speed);
                move_with_wall_slide((u8 *)self);
            } else {
                VecCopy((Vec *)&dir, (const Vec *)&self->target->pos);
                subtract_vector(&dir, &self->pos);
                a = ((TObjEnemy *)self)->turn_toward_direction(self->info->turn, (Vec *)&dir);
            }
            if (a < 0x100) {
                self->phase = 1;
                self->anim = 4;
            } else {
                self->anim = 2;
            }
        }
        break;
    case 1:
        if (objInBand((GameObj *)self, (f32)lbl_805D9C10) != 0) {
            pos.x = lbl_805D9BD8;
            pos.y = lbl_805D9C14;
            pos.z = lbl_805D9C18;
            ((s32 (*)(void *))push_matrix_from)(identity_matrix);
            rotate_matrix_y(0, self->rot_y);
            ((s32 (*)(int, void *, void *))rotate_vector_by_matrix)(0, &pos, &pos);
            pop_matrices(1);
            ((void (*)(void *, void *))vec3_add_to)(&pos, &self->pos);
            if (self->target != NULL) {
                VecCopy((Vec *)&dir, (const Vec *)&self->target->pos);
                subtract_vector(&dir, &self->pos);
                ang2 = ((TObjEnemy *)self)->turn_toward_direction(self->info->turn, (Vec *)&dir);
            } else {
                ang2 = ((AttackParams *)(self->f318))->get_attack_angle();
            }
            if (game_difficulty_selection == 3) {
                switch (self->kind) {
                case 1:
                    if (ang2 < ((AttackParams *)(self->f318))->get_attack_angle() / 2 && self->target != NULL) {
                        TTecMegid::create((s32)self, (s32)&pos, (s32)&self->target->pos, (s32)(((TObjEneMoja *)self)->calc_technique_level()));
                    } else {
                        TTecMegid::create_ex((s32)self, (s32)&pos, self->rot_y, (s32)(((TObjEneMoja *)self)->calc_technique_level()));
                    }
                    ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *) 0x4002A60B, &pos, 0, 0);
                    break;
                default:
                    ((s32 (*)(void *, int))spawn_particle_effect)(&pos, 0xB9);
                    ((s32 (*)(void *, int))spawn_particle_effect)(&pos, 0xBA);
                    if (ang2 < ((AttackParams *)(self->f318))->get_attack_angle() / 2) {
                        if (((TObjBoss2Tunnel *)(&dir))->update_scale() < lbl_805D9C1C) {
                            dir.y = dir.x = lbl_805D9BD8;
                            dir.z = lbl_805D9BDC;
                            ((s32 (*)(void *))push_matrix_from)(identity_matrix);
                            rotate_matrix_y(0, self->rot_y);
                            ((s32 (*)(int, void *, void *))rotate_vector_by_matrix)(0, &dir, &dir);
                            ((s32 (*)())pop_matrix)();
                        }
                        if (self->target != NULL) {
                            Hit_800ACFE8 hit;
                            hit.a = 3;
                            hit.b = lbl_805D9C08 * (f32) ((TObjEneMoja *)self)->calc_technique_level() + lbl_805D9C20;
                            self->target->m21(self, hit, 0, -1, -1);
                        }
                    } else {
                        dir.y = dir.x = lbl_805D9BD8;
                        dir.z = lbl_805D9BDC;
                        ((s32 (*)(void *))push_matrix_from)(identity_matrix);
                        rotate_matrix_y(0, self->rot_y);
                        ((s32 (*)(int, void *, void *))rotate_vector_by_matrix)(0, &dir, &dir);
                        ((s32 (*)())pop_matrix)();
                    }
                    obj = __nw__7TObjectFUl(0x260);
                    if (obj != NULL) {
                        ((TTecZonde *)obj)->construct_bolt_effect((u8 *)tl_07, (u8 *)&pos, (u8 *)&dir, 0x14000000, 20, (f32)(((AttackParams *)(self->f318))->get_attack_range()), (f32)lbl_805D9C24);
                    }
                    ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *) 0x4002A408, &pos, 0, 0);
                    break;
                }
            } else {
                switch (self->kind) {
                case 1:
                    ((TTecGiBarta *)self)->create_ex(&pos, (void *)self->rot_y, (void *)(((TObjEneMoja *)self)->calc_technique_level()));
                    break;
                default:
                    if (ang2 < ((AttackParams *)(self->f318))->get_attack_angle() / 2 && self->target != NULL) {
                        TTecFoie::create_ex((void *)self, &pos, &self->target->pos, (void *)(((TObjEneMoja *)self)->calc_technique_level()));
                    } else {
                        TTecFoie::create((void *)self, &pos, (void *)self->rot_y, (void *)(((TObjEneMoja *)self)->calc_technique_level()));
                    }
                    break;
                }
                dir.y = dir.x = lbl_805D9BD8;
                dir.z = lbl_805D9BDC;
                ((s32 (*)(void *))push_matrix_from)(identity_matrix);
                rotate_matrix_y(0, self->rot_y);
                ((s32 (*)(int, void *, void *))rotate_vector_by_matrix)(0, &dir, &dir);
                pop_matrices(1);
                {
                    f32 xx = dir.x * dir.x;
                    f32 yy = dir.y * dir.y;
                    ang.x = (s32) (lbl_8043B0C8[0] * atan2_float(dir.z, newton_sqrtf(xx + yy)));
                }
                ang.y = 0;
                ang.z = -(s32) (lbl_8043B0C8[0] * atan2_float(dir.x, dir.y));
                spawn_directional_particle(&pos, &ang, 0xCC);
                ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)((TObjEnemy *)(self))->remap_sound_for_area((s32)(0x3E405)), &pos, 0, 0);
            }
        }
        if (self->anim_state != 4) {
            self->phase = 2;
            self->timer = 30;
        }
        break;
    case 2:
        self->count++;
        if (self->count >= 2) {
            self->count = -1;
            self->flags &= 0xFFDFFFFF;
        } else {
            self->phase = 0;
            self->timer = 0;
        }
        break;
    }
    ((s32 (*)(void *, s32, f32))apply_actor_gravity)(self, 0, lbl_805D9BD8);
    ((TObjPlayer *)self)->update_collisions();
}
#undef self
#pragma pop

s32 TObjEneMoja::update_punch_attack(void *self_800ADAAC) {
    Vec_800ADAAC sp14;
    Vec_800ADAAC sp8;
    f32 temp_f1;
    s32 t;
    s32 n;
    s32 i;
    u8 *p;
    V398_800ADAAC *o;
    s32 e;
    switch (*(s16 *)(arg0 + 0x328)) {
    case 0:
        ((TObjEnemy *)arg0)->sub_800A7798(*(f32 *)lbl_805D50D4[*(s32 *)(arg0 + 0x368)]);
        *(s16 *)(arg0 + 0x328) = 1;
    case 1:
        ((s32 (*)(void *))advance_animation_playback)(arg0);
        if (objInBand((GameObj *)arg0, (f32)lbl_805D9C28) != 0) {
            ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x3AD04)), arg0 + 0x38, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x300);
        }
        if (objInBand((GameObj *)arg0, (f32)lbl_805D9C04) != 0) {
            t = obj_testFlags30__14TObjCollidableFUl(arg0, 0x10);
            n = registered_player_count;
            if (t != 0) {
                n += lbl_805D5870;
            }
            for (i = 0; i < n; i++) {
                p = get_player_data__10TObjPlayerFi(i);
                if (p == NULL || p == arg0) {
                    break;
                }
                if ((obj_is_hit_receivable() != 0) && !(*(s32 *)(p + 0x30) & 0x02000800) && (((VObj_18_247a8e *)p)->m18(arg0, lbl_805D9BDC) != 0)) {
                    ((VObj_18_247a8e *)p)->m20(arg0, lbl_805D9BDC);
                    ((VObj_18_247a8e *)p)->m23(arg0);
                    if (lbl_805D9BEC < ((f32 (*)(void *))random_ratio__9TObjCharaFv)(arg0)) {
                        *(s32 *)(arg0 + 0x388) = 1;
                    }
                }
            }
        }
        if ((lbl_805D9C28 <= *(f32 *)(arg0 + 0xC0)) && (*(f32 *)(arg0 + 0xC0) <= lbl_805D9C2C)) {
            e = lookup_entry_by_value__10TObjPlayerFPvf(lbl_805D50DC);
            if (e != 0) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(arg0 + 0x38);
                rotate_matrix_y(0, *(s32 *)(arg0 + 0x60));
                mult_vec_array__10TObjPlayerFUll(0, e, &sp8, 2);
                ((s32 (*)())pop_matrix)();
                o = *(V398_800ADAAC **)(arg0 + 0x398);
                if (o != NULL) {
                    o->m4(&sp8, &sp14);
                }
            }
        }
        if (*(u32 *)(arg0 + 0xB4) != 4U) {
            *(s32 *)(arg0 + 0x384) += 1;
            *(s16 *)(arg0 + 0x328) = 2;
            switch (*(s32 *)(arg0 + 0x388)) {
            case 1:
                *(s16 *)(arg0 + 0xB8) = 1;
                *(s16 *)(arg0 + 0x33C) = 0;
                break;
            default:
                *(s16 *)(arg0 + 0xB8) = 0;
                *(s16 *)(arg0 + 0x33C) = (s16)((f32 *)lbl_805D50D4[*(s32 *)(arg0 + 0x368)])[1];
                break;
            }
        }
        break;
    case 2:
        ((s32 (*)(void *))advance_animation_playback)(arg0);
        if ((objInBand((GameObj *)arg0, (f32)lbl_805D9BD8) != 0) && (*(s32 *)(arg0 + 0x388) == 1)) {
            ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x3AD0A)), arg0 + 0x38, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x200);
        }
        if (*(u32 *)(arg0 + 0xB4) != 0x20U) {
            if ((f32)--*(s16 *)(arg0 + 0x33C) < lbl_805D9BD8) {
                *(s16 *)(arg0 + 0x33C) = 0;
                *(s16 *)(arg0 + 0x328) = 1;
                *(s32 *)(arg0 + 0x388) = 0;
                *(u16 *)(arg0 + 0x338) = 0xFFFF;
                *(s32 *)(arg0 + 0x2A8) = 0;
                if (*(s32 *)(arg0 + 0x384) >= 3) {
                    *(s32 *)(arg0 + 0x384) = -1;
                }
                *(s32 *)(arg0 + 0x30) &= 0xFFDFFFFF;
            }
        }
        break;
    }
    ((s32 (*)(void *, s32, f32))apply_actor_gravity)(arg0, 0, lbl_805D9BD8);
    ((TObjPlayer *)arg0)->update_collisions();
}
#undef arg0

void TObjEneMoja::vfunc_60() {
    Moja_800ADE48 *self = (Moja_800ADE48 *)this;
    switch (self->attack_kind) {
    case 2:
        self->mode = 6;
        self->action = 5;
        break;
    case 1:
        self->mode = 5;
        self->action = 2;
        break;
    case 0:
    default:
        self->mode = 4;
        self->action = 3;
        break;
    }
    self->phase = 0;
    self->flags |= 0x200000;
    self->flags &= 0xF9FBFFFF;
    self->collision->flags |= 1;
    self->f374 = 0;
}

s32 TObjEneMoja::is_target_in_attack_range() {
    s32 angd;
    s32 lim;
    s32 i;
    f32 sq;
    f32 dist;
    f32 radius;
    u8 *t;
    u8 *c;
    Vec_800AE18C d;
    if (this->mode > 1 && (t = this->target) != NULL &&
        this->m_318 != 0 && !(*(u32 *)((s8 *)t + 0x30) & 0x02000800)) {
        dist = calc_xz_distance_sq(this, t, &d);
        angd = angle_difference_abs(this->rotation_y,
                                    (s32)(lbl_8043B0C8[0] * atan2_float(d.x, d.z)));
        c = *(u8 **)(this->target + 0xA4);
        if (c != NULL) {
            radius = *(f32 *)((s8 *)c + 0xC);
        } else {
            radius = lbl_805D9BE8;
        }
        for (i = 0; i < 3; i++) {
            this->m_318 = lbl_805D50CC[i + (this->variant) * 3];
            sq = (radius + ((AttackParams *)(this->m_318))->get_attack_range()) *
                 (radius + ((AttackParams *)(this->m_318))->get_attack_range());
            lim = ((AttackParams *)(this->m_318))->get_attack_angle();
            if (dist <= sq && angd <= lim) {
                this->attack = i;
                switch (this->attack) {
                case 0:
                    if (this->attackSequence == -1) {
                        this->attackSequence = 0;
                    }
                    return 1;
                case 1:
                    if (this->attackSequence != -1 && !(this->techniqueChance < lbl_805D9C1C)) {
                        if (((f32 (*)(void *))random_ratio__9TObjCharaFv)(this) < this->techniqueChance) {
                            return 1;
                        }
                        this->attackSequence = -1;
                        {
                            Vec_800AE18C v = *(Vec_800AE18C *)(((u8 *)this) + 0x2FC);
                            select_enemy_destination(this, &v, 1);
                        }
                        {
                            Vec_800AE18C v2 = *(Vec_800AE18C *)(((u8 *)this) + 0x2FC);
                            copy_position_if_valid__10TObjPlayerFii(this, &v2);
                        }
                    }
                    break;
                case 2:
                    if (this->attackSequence != -1) {
                        if (lbl_805D9C30 < dist && ((f32 (*)(void *))random_ratio__9TObjCharaFv)(this) < this->jumpChance) {
                            return 1;
                        }
                        this->attackSequence = -1;
                        {
                            Vec_800AE18C v = *(Vec_800AE18C *)(((u8 *)this) + 0x2FC);
                            select_enemy_destination(this, &v, 1);
                        }
                        {
                            Vec_800AE18C v2 = *(Vec_800AE18C *)(((u8 *)this) + 0x2FC);
                            copy_position_if_valid__10TObjPlayerFii(this, &v2);
                        }
                    }
                    break;
                }
            }
        }
    }
    return 0;
}

s32 TObjEneMoja::update_approach_state() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f0_2;
    u8 *temp_r4;
    u8 *temp_r7;
    switch (this->phase) {
    case 0:
        ((s32 (*)(void *, s32, f32))apply_actor_gravity)((void *) arg0, 0, lbl_805D9BD8);
        if (objInBand((GameObj *)(arg0), (f32)lbl_805D9BD8) != 0) {
            ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x3AD0A)), (u8 *)&this->position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x200);
        }
        if (this->m_b4 != 0x20U) {
            ((TObjEnemy *)arg0)->sub_800A7798(*(f32 *)((s8 *)lbl_805D50D4[(*(s32 *)&this->variant)] + 0xC));
            this->m_b8 = 2;
            {
            Vec_800AE18C v = *(Vec_800AE18C *)(this->target + 0x2FC);
            if (select_enemy_destination(arg0, &v, 1) != 0) {
                Vec_800AE18C v2 = *(Vec_800AE18C *)(arg0 + 0x2FC);
                copy_position_if_valid__10TObjPlayerFii(arg0, &v2);
            }
            }
            this->phase = 1;
            this->roar = 0;
            (*(s16 *)&this->timer) = 0x96;
        }
        break;
    case 1:
    default:
        temp_r7 = this->target;
        if (temp_r7 != NULL) {
            Vec_800AE18C v3 = *(Vec_800AE18C *)(temp_r7 + 0x2FC);
            temp_r4 = lbl_805D50D4[(*(s32 *)&this->variant)];
            if (*(f32 *)((s8 *)((*(u8 * *)&this->movementParameters)) + 0) * *(f32 *)((s8 *)((*(u8 * *)&this->movementParameters)) + 0) < enemy_pursue_point(arg0, *(s32 *)((s8 *)((*(u8 * *)&this->movementParameters)) + 8), &v3, temp_r4, *(f32 *)((s8 *)temp_r4 + 8), lbl_805D9BF0)) {
                this->target = NULL;
            }
            if (horizontal_distance_squared((int)(arg0 + 0x29C), (void *)(arg0 + 0x38)) < (*(f32 *)((s8 *)((*(u8 * *)&this->movementParameters)) + 4) + *(f32 *)((s8 *)(*(u8 * *)&this->bodies) + 0xC)) * (*(f32 *)((s8 *)((*(u8 * *)&this->movementParameters)) + 4) + *(f32 *)((s8 *)(*(u8 * *)&this->bodies) + 0xC))
                || --(*(s16 *)&this->timer) < 0) {
                this->attackSequence = 0;
            }
        }
        if (objInBand((GameObj *)(arg0), (f32)lbl_805D9C34) != 0 || objInBand((GameObj *)(arg0), (f32)((f32)lbl_805D9C38)) != 0) {
            ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x3A801)), (u8 *)&this->position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x400);
        }
        break;
    }
    ((s32 (*)(void *)) advance_animation_playback)(arg0);
    ((TObjPlayer *)arg0)->update_collisions();
}

void TObjEneMoja::vfunc_59() {
    MojaCollisionState *moja_collision_state;

    if ((s16) mode != 3) {
        mode = 3;
        switch ((s32) roar) {
        case 1:
            phase = 0;
            m_b8 = 1;
            break;
        default:
            phase = 0;
            m_b8 = 2;
            break;
        }
        attackSequence = -1;
        (this->actorFlags) = (s32) ((this->actorFlags) & 0xF9FBFFFF);
        moja_collision_state = (*(MojaCollisionState * *)&this->bodies);
        moja_collision_state->flags = (s32) (moja_collision_state->flags | 1);
        appearance = 0;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
void update_appearance_drop__11TObjEneMojaFv(Moja_800AE450 *self) {
    f32 ticks;
    f32 dist;
    VObj_800AE450 *p;
    s32 i;
    self->flags |= 0x06000000;
    self->collision->flags &= ~1;
    ((s32 (*)(void *))advance_animation_playback)(self);
    switch (self->phase) {
    case 0:
    default:
        VecCopy((Vec *)&lbl_8050BEE0, (const Vec *)&self->home);
        subtract_vector(&lbl_8050BEE0, &self->pos);
        self->angle = approach_angle_limited(self->angle,
            (s32)(lbl_8043B0C8[0] * atan2_float(lbl_8050BEE0.x, lbl_8050BEE0.z)),
            self->turn->step);
        if (self->angle >= self->turn->step) {
            return;
        }
        self->fB8 = 5;
        if (objInBand((GameObj *)self, (f32)lbl_805D9C00) == 0) {
            return;
        }
        VecCopy((Vec *)&self->dest, (const Vec *)&self->home);
        VecCopy((Vec *)&self->from, (const Vec *)&self->pos);
        self->speed = newton_sqrtf(lbl_8050BEE0.x * lbl_8050BEE0.x + lbl_8050BEE0.z * lbl_8050BEE0.z);
        ticks = lbl_805D9C04 / self->fC8;
        self->speed = self->speed / ticks;
        ((s32 (*)(void *, Vec_800AE450, Vec_800AE450, f32))calc_velocity_toward_destination)(self, self->from, self->dest, self->speed);
        self->vel.y = lbl_8050BEE0.y / ticks;
        self->phase = 1;
        break;
    case 1:
        self->pos.x += self->vel.x;
        self->pos.y += self->vel.y;
        self->pos.z += self->vel.z;
        if (objInBand((GameObj *)self, (f32)lbl_805D9C08) == 0) {
            return;
        }
        self->phase = 2;
        for (i = 0; i < lbl_805D5868; i++) {
            p = (VObj_800AE450 *)get_player_data__10TObjPlayerFi(i);
            if (p == NULL) {
                break;
            }
            if ((u16)get_entity_id(p) >= 0x1000) {
                break;
            }
            if (((s32 (*)(void *))obj_is_hit_receivable)(p) != 0) {
                dist = horizontal_distance_squared((int)((u8 *)p + 0x2FC), &self->center);
                if (dist <= lbl_805D9C3C) {
                    p->m21(self, Hit_800AE450(lbl_805D9C40), 0, -1, -1);
                    p->m23(self);
                }
                if (dist <= lbl_805D9C0C && !is_split_screen() && local_client_id == (u16)get_entity_id(p)) {
                    TCameraCtrl::set_shake_preset(0);
                }
            }
        }
        ((s32 (*)(void *, int))spawn_particle_effect)(&self->pos, 0xCB);
        ((s32 (*)(void *, int))spawn_particle_effect)(&self->pos, 0xF0);
        ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)((TObjEnemy *)(self))->remap_sound_for_area((s32)(0x3AD03)), &self->pos, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x300);
        break;
    case 2:
        ((s32 (*)(void *, s32, f32))apply_actor_gravity)(self, 0, lbl_805D9BD8);
        if (self->fB4 != 4) {
            self->flags &= 0xF9DFFFFF;
            self->collision->flags |= 1;
            self->f384 = -1;
            self->f33C = 0;
            self->f374 = 0;
        }
        break;
    }
}
#pragma pop

void update_appearance_jump__11TObjEneMojaFv(Moja_800AE7F4 *self) {
    Vec_800AE7F4 off;
    Vec_800AE7F4 tmp;
    Vec_800AE7F4 delta;
    f32 ticks;
    f32 dist;
    VObj_800AE7F4 *p;
    s32 i;
    self->flags |= 0x06000000;
    self->collision->flags &= ~1;
    ((s32 (*)(void *))advance_animation_playback)(self);
    switch (self->phase) {
    case 0:
    default:
        off.x = lbl_805D9BD8;
        off.y = lbl_805D9C44;
        off.z = lbl_805D9C48;
        ((s32 (*)(void *))push_matrix_from)(identity_matrix);
        rotate_matrix_y(0, self->angle);
        ((s32 (*)(int, void *, void *))rotate_vector_by_matrix)(0, &off, &off);
        pop_matrices(1);
        VecCopy((Vec *)&tmp, (const Vec *)&self->home);
        subtract_vector(&tmp, &off);
        VecCopy((Vec *)&self->pos, (const Vec *)&tmp);
        if (objInBand((GameObj *)self, (f32)lbl_805D9C00) == 0) {
            return;
        }
        VecCopy((Vec *)&self->dest, (const Vec *)&self->home);
        VecCopy((Vec *)&self->from, (const Vec *)&self->pos);
        VecCopy((Vec *)&delta, (const Vec *)&self->dest);
        subtract_vector(&delta, &self->pos);
        self->angle = (s32)(lbl_8043B0C8[0] * atan2_float(delta.x, delta.z));
        self->speed = newton_sqrtf(delta.x * delta.x + delta.z * delta.z);
        ticks = lbl_805D9C04 / self->fC8;
        self->speed = self->speed / ticks;
        ((s32 (*)(void *, Vec_800AE7F4, Vec_800AE7F4, f32))calc_velocity_toward_destination)(self, self->from, self->dest, self->speed);
        self->vel.y = delta.y / ticks;
        self->phase = 1;
        break;
    case 1:
        self->pos.x += self->vel.x;
        self->pos.y += self->vel.y;
        self->pos.z += self->vel.z;
        if (objInBand((GameObj *)self, (f32)lbl_805D9C08) == 0) {
            return;
        }
        self->phase = 2;
        for (i = 0; i < lbl_805D5868; i++) {
            p = (VObj_800AE7F4 *)get_player_data__10TObjPlayerFi(i);
            if (p == NULL) {
                break;
            }
            if ((u16)get_entity_id(p) >= 0x1000) {
                break;
            }
            if (((s32 (*)(void *))obj_is_hit_receivable)(p) != 0) {
                dist = horizontal_distance_squared((int)((u8 *)p + 0x2FC), &self->center);
                if (dist <= lbl_805D9C3C) {
                    p->m21(self, Hit_800AE7F4(lbl_805D9C40), 0, -1, -1);
                    p->m23(self);
                }
                if (dist <= lbl_805D9C0C && !is_split_screen() && local_client_id == (u16)get_entity_id(p)) {
                    TCameraCtrl::set_shake_preset(0);
                }
            }
        }
        ((s32 (*)(void *, int))spawn_particle_effect)(&self->pos, 0xCB);
        ((s32 (*)(void *, int))spawn_particle_effect)(&self->pos, 0xF0);
        ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)((TObjEnemy *)(self))->remap_sound_for_area((s32)(0x3AD03)), &self->pos, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x300);
        break;
    case 2:
        ((s32 (*)(void *, s32, f32))apply_actor_gravity)(self, 0, lbl_805D9BD8);
        if (self->fB4 != 4) {
            self->flags &= 0xF9DFFFFF;
            self->collision->flags |= 1;
            self->f384 = -1;
            self->f33C = 0;
            self->f374 = 0;
        }
        break;
    }
}
#pragma pop

void TObjEneMoja::update_idle_state() {
    Moja_800AEBB8 *self = (Moja_800AEBB8 *)this;
    switch (self->phase) {
    case 0:
    default: {
        Vec_800AE18C dest = self->pos;
        if (select_enemy_destination(self, &dest, 7) != 0) {
            Vec_800AE18C cur = self->f2FC;
            copy_position_if_valid__10TObjPlayerFii(self, &cur);
        }
        switch (self->f374) {
        case 0:
            self->phase = 1;
            break;
        }
        break;
    }
    case 1:
        ((s32 (*)())advance_animation_playback)();
        ((void (*)(f32, void *, s32, f32, f32)) enemy_wander_home__9TObjEnemyFlfff)(self->info->f4, self, self->info->f8, lbl_805D9C4C, lbl_805D9C4C);
        break;
    }
    ((TObjCollidable *)self)->refresh_collision_body_centers();
    ((TObjBase *)self)->obj_clearFlags30(0x200000);
}

void TObjEneMoja::vfunc_58() {
    s32 temp_r0;

    temp_r0 = mode;
    if ((temp_r0 >= 3) || (temp_r0 < 0)) {
        phase = 0;
        roar = 1;
        (this->actorFlags) = (s32) ((this->actorFlags) | 0x40000);
    }
    switch (appearance) {
    case 0:
        mode = 0;
        m_b8 = 2;
        return;
    case 1:
        mode = 1;
        m_b8 = 5;
        return;
    default:
        mode = 0;
        m_b8 = 0;
        return;
    }
}

s32 TObjEneMoja::update_movement_status() {
    void *temp_r3;
    if (update_movement_status__9TObjCharaFv() != 0) {
        switch (this->mode) {
        case 0:
        case 1:
            this->mode = 0;
            this->phase = 0;
            this->roar = 1;
            this->attackSequence = -1;
            (this->timer) = 0;
            this->appearance = 0;
            this->m_b8 = 2;
            obj_clearFlags30(0x06040000);
            temp_r3 = this->bodies;
            *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) | 1);
            break;
        }
        return 1;
    }
    return 0;
}
s32 TObjEneMoja::update_action_hold_status() {
    void *temp_r3;
    if (update_action_hold_status__9TObjCharaFv() != 0) {
        switch (this->mode) {
        case 0:
        case 1:
            this->mode = 0;
            this->phase = 0;
            this->roar = 1;
            this->attackSequence = -1;
            (this->timer) = 0;
            this->appearance = 0;
            this->m_b8 = 2;
            obj_clearFlags30(0x06040000);
            temp_r3 = this->bodies;
            *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) | 1);
            break;
        }
        return 1;
    }
    return 0;
}
void acquire_target__11TObjEneMojaFPv(u8 *arg0) {
    s32 best_id;
    s32 i;
    s32 id;
    u8 *p;
    f32 best;
    f32 d;
    u8 *q;
    u16 tid;
    if (((TObjEneMoja *)arg0)->appearance != 1 && ((((TObjEneMoja *)arg0)->mode != 0 && ((TObjEneMoja *)arg0)->target == NULL) || ((TObjEneMoja *)(arg0))->is_actor_cadence_frame(0x1E) != 0)) {
        if (obj_testFlags30__14TObjCollidableFUl(arg0, 0x10) != 0) {
            i = 0;
            best_id = 0xFFFF;
            Vec_800AEE54 v = *(Vec_800AEE54 *)lbl_8043B0B4;
            best = *(f32 *)((s8 *)(((TObjEneMoja *)arg0)->movementParameters) + 0) * *(f32 *)((s8 *)(((TObjEneMoja *)arg0)->movementParameters) + 0);
            for (; i < registered_player_count + lbl_805D5870; i++) {
                p = get_player_data__10TObjPlayerFi(i);
                if (p == NULL) {
                    break;
                }
                id = get_entity_id(p);
                if ((u16)id < 0x4000 && (u16)id != ((TObjEneMoja *)arg0)->entity_id && !(*(s32 *)((s8 *)p + 0x30) & 0x02000800)) {
                    f32 xx;
                    f32 zz;
                    VecCopy((Vec *)&v, (const Vec *)(p + 0x2FC));
                    subtract_vector(&v, arg0 + 0x2FC);
                    xx = v.x * v.x;
                    zz = v.z * v.z;
                    d = xx + zz;
                    if (d < best && check_path_obstructed(arg0, p + 0x2FC) != 1 && csnVector(arg0 + 0x2FC, p + 0x2FC, -1) == 0U) {
                        best_id = id;
                        best = d;
                    }
                }
            }
            ((TObjEneMoja *)arg0)->targetId = best_id;
        } else {
            ((TObjEneMoja *)arg0)->targetId = find_nearest_visible_player(arg0, 0, *(f32 *)((s8 *)(((TObjEneMoja *)arg0)->movementParameters) + 0));
        }
        tid = ((TObjEneMoja *)arg0)->targetId;
        if (tid < 0x1000U) {
            q = (u8 *)get_player_by_client_id(tid);
            if (q != NULL) {
                if (((TObjPlayer *)q)->get_field_3e4() == get_current_floor()) {
                    ((TObjEneMoja *)arg0)->target = q;
                    return;
                }
            }
            ((TObjEneMoja *)arg0)->target = NULL;
            return;
        }
        if (tid < 0x4000U) {
            ((TObjEneMoja *)arg0)->target = get_enemy_entity(tid);
            return;
        }
        ((TObjEneMoja *)arg0)->targetId = 0xFFFFU;
        ((TObjEneMoja *)arg0)->target = NULL;
    }
}

void render__11TObjEneMojaFv(u8 *arg0) {
    Vec_800AF080 pos;
    Fade_800AF080 *fade;
    s32 cam;
    s32 vis;
    s32 draw;
    s32 id;
    cam = 0;
    if (is_split_screen() != 0) {
        cam = get_camera_mode__11TCameraCtrlFv();
    }
    vis = ((Ene_800AF080 *)arg0)->m9(lbl_805D9C50, lbl_805D9C54, lbl_805D9BF0);
    if (vis == 0) {
        return;
    }
    select_actor_lighting(arg0);
    TObjFish::set_global_param(((TObjEneMoja *)arg0)->texlist);
    id = model_render_flags;
    fade = &((Body_800AF080 *)arg0)->fades[cam];
    saved_model_render_flags = id;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags = id | 1;
    update__15RenderFadeStateFv(fade, chunk_polygon_flags_or_mask, chunk_polygon_flags_and_mask, id);
    draw = 1;
    if (((RenderFadeState *)fade)->updateFromCamera((const f32*)(arg0 + 0x38)) == 1) {
        fade->m6();
        if (defer_render__7TObjectFv(arg0) != 0) {
            draw = 0;
        } else {
            model_render_flags &= ~1;
        }
    }
    if (draw != 0) {
        TObjPlayer::set_global_flag();
        push_matrix();
        translate_matrix(0, lbl_805D9BD8, ((TObjEneMoja *)arg0)->sinkOffset, lbl_805D9BD8);
        post_translate_matrix(arg0 + 0x38);
        rotate_matrix_y(0, (int)(((TObjEneMoja *)arg0)->rotation_y));
        if (TObjPlayer::check_demo_mode() == 1) {
            draw_chunk_object(*(s32 *)((s8 *)arg0 + 0x34));
        } else {
            TObjPlayer::toggle_particle_effect();
            if (vis == 1) {
                ((TObjMotion *)arg0)->draw();
            } else {
                ((TObjEnemy *)arg0)->render_world_model();
            }
            TParticleCtrl::end_effect_render();
        }
        ((s32 (*)())pop_matrix)();
        TObjPlayer::clear_global_state();
    }
    model_render_flags &= ~1;
    if (((RenderFadeState *)fade)->updateFromCamera((const f32*)(arg0 + 0x38)) == 1) {
        fade->m7();
    }
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    model_render_flags = saved_model_render_flags;
    restore_scene_lighting(saved_chunk_polygon_flags_or_mask, saved_chunk_polygon_flags_and_mask);
    switch (((TObjEneMoja *)arg0)->mode) {
    case 0:
    case 1:
    case 9:
        break;
    default:
        pos.x = lbl_805D9C58;
        pos.y = lbl_805D9BDC;
        pos.z = lbl_805D9C58;
        render_with_position_override__9TObjEnemyFPUcl(arg0, &pos.x, 0, lbl_805D9C58);
        break;
    }
}

void TObjEneMoja::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    s16 temp_r0;
    s32 temp_r30;
    u16 temp_r3;
    u8 *temp_r3_2;
    u8 *temp_r4;
    if (TObjPlayer::check_demo_mode() == 1) {
        TObjPlayer__sub_800ACA0C(arg0);
        return;
    }
    temp_r3 = this->targetId;
    if (temp_r3 < 0x1000U) {
        temp_r3_2 = (u8 *)(get_player_by_client_id(temp_r3));
        if (temp_r3_2 != NULL) {
            if (((TObjPlayer *)temp_r3_2)->get_field_3e4() == get_current_floor()) {
                this->target = temp_r3_2;
                goto done;
            }
        }
        this->target = NULL;
    done:;
    } else if (temp_r3 < 0x4000U) {
        this->target = get_enemy_entity(temp_r3);
    } else {
        this->targetId = 0xFFFFU;
        this->target = NULL;
    }
    {
        switch (this->mode) {
        case 0:
            update_idle_state();
            break;
        case 1:
            update_appearance_jump__11TObjEneMojaFv((Moja_800AE7F4 *)(arg0));
            break;
        case 2:
            update_appearance_drop__11TObjEneMojaFv((Moja_800AE450 *)((Moja_800AE450 *) (arg0)));
            break;
        case 3:
            update_approach_state();
            break;
        case 4:
            TObjEneMoja::update_punch_attack(arg0);
            break;
        case 5:
            TObjEneMoja::update_technique_state(arg0);
            break;
        case 6:
            update_attack_jump__11TObjEneMojaFv((Obj_800ACFE8 *) (arg0));
            break;
        case 7:
            ((TObjPlayer *)arg0)->update_invincibility();
            break;
        case 8:
            ((TObjPlayer *)arg0)->update_ground_effect();
            break;
        case 9:
            update_death_state();
            break;
        }
    }
    ((TObjEnemy *)arg0)->update_prev_position();
    ((TBoss3VoloptHiraisin *)arg0)->copy_position();
    submit_cursor_candidate(arg0, -1);
    temp_r4 = this->target;
    if ((temp_r4 != NULL) && (*(s32 *)((s8 *)temp_r4 + 0x30) & 0x02000800)) {
        this->attackSequence = -1;
        (this->timer) = 0;
        (this->actorFlags) = (s32) ((this->actorFlags) & 0xFFDFFFFF);
        this->target = NULL;
    }
    temp_f1 = this->m_2b4;
    this->m_2b4 = (f32) (temp_f1 + lbl_805D9BDC);
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0, temp_f1);
}
