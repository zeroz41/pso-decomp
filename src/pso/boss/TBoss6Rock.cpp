#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/boss/TUnk_804F1280.h"
#include "pso/boss/TBoss6Rock.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TLobby.h"

struct RecoveredGlobal_80353E10_TBoss6Rock__data_80543778 {
    s32 value;
    u8 remaining[0x7C];
};

struct RecoveredGlobal_80353DC4_TBoss6Rock__data_80543778 {
    s32 value;
    u8 remaining[0x7C];
};

struct RecoveredGlobal_80354148_TBoss6Rock__data_80479258 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_80354148_TBoss6Rock__data_80543778 {
    s32 value;
    u8 remaining[0x7C];
};

struct Rock_80353EDC { u8 pad[0xb8]; s32 b8; u8 pad2[4]; s32 c0; u8 pad3[4]; s32 state; };

struct Rock_80353EA4 { u8 pad[0xc8]; s32 state; };

struct R_80353E5C { u8 pad0[0xC4]; s32 fC4; s32 fC8; };

struct Vec_80353B7C { f32 x, y, z; };

struct R_80353B7C { u8 pad0[4]; f32 f4; f32 f8; };

struct Vec_80353C60 { f32 x, y, z; };

struct Vec_80353A14 { f32 x, y, z; };

struct E_803546B0 { s32 id; f32 f4; u8 pad8[0xC]; };

struct R_803546B0 {
    u8 pad0[0x38];
    u8 f38[0x5C - 0x38];
    s32 f5C;
    s32 f60;
    s32 f64;
    u8 pad68[0xB4 - 0x68];
    s32 fB4;
    u8 padB8[0xC4 - 0xB8];
    s32 fC4;
    u8 padC8[0xE4 - 0xC8];
    u32 fE4;
};

struct Vec_80353F5C
{
  f32 x;
  f32 y;
  f32 z;
};

struct Blk_80353F5C
{
  Vec_80353F5C v0;
  Vec_80353F5C v1;
  Vec_80353F5C v2;
  Vec_80353F5C v3;
  s32 a;
  s32 b;
};

struct Elem_80353F5C
{
  u8 pad[8];
  f32 f8;
  f32 fc;
  s32 x;
};

struct Obj_80353F5C
{
  u8 pad[0xB0];
  u32 h;
  s32 idx;
};

extern "C" {
void TBoss6Rock__sub_803542E8(TBoss6Rock *rock, s32 landed);
extern const f32 TBoss6Rock__data_805DFF48;
extern const f32 TBoss6Rock__data_805DFF4C;
extern const f32 lbl_805DFF98;
extern const f32 lbl_805DFFA4;
extern RecoveredGlobal_80353E10_TBoss6Rock__data_80543778 TBoss6Rock__instance_table;
u8 is_rock_state_2__10TBoss6RockFi(s32 arg0);
s32 rand();
extern const f32 lbl_805DFF68;
extern const f32 lbl_805DFF6C;
extern const f32 lbl_805DFF70;
extern const f32 lbl_805DFF74;
extern const f32 lbl_805DFF78;
s32 play_sound_effect(s32, u32, int, s32);
extern const f32 TBoss6Rock__data_805DFF50;
extern const f32 lbl_805DFF54;
extern const f32 lbl_805DFF94;
extern const f32 lbl_805DFF9C;
extern const f32 lbl_805DFFA0;
extern RecoveredGlobal_80354148_TBoss6Rock__data_80479258 TBoss6Rock__data_80479258;
extern u8 TBoss6Rock__rock_point_table[];
f32 vector_length(void *);
void subtract_vector(void *, void *);
void vec3_add_to(void *, void *);
void normalize_vector(void *);
extern const f32 TBoss6Rock__data_805DFF5C;
extern const f32 lbl_805DFF60;
extern const f32 lbl_805DFF64;
extern u8 *TBoss6Rock__data_805D6EF8;
extern const f32 lbl_805DFF58;
s32 TBoss6Rock__sub_80353A14(s32 arg0, Vec_80353A14 *out, f32 *outR);
s32 get_bml_model(int, int);
s32 TBoss6PlotFalz__sub_802AB6CC(void *, f32);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern int TBoss6Rock__data_805D6EF0;
extern int TBoss6Rock__data_805D6EF4;
u32 create__10TObjMapCsnFl(void *, void *, f32);
extern u8 lbl_80479280[];
int TBoss6Rock__sub_80353A04(void);
int TBoss6Rock__sub_80353A0C(void);
void __ct__7TObjectFP7TObject(void *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void *__nw__7TObjectFUl(int);
int is_active__10TBoss6RockFv(void*);

void TBoss6Rock::set_target(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 farg0) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)&this->entity_id = arg1;
    if ((s32) *(s32 *)&this->entity_id != 0) {
        VecCopy((Vec *)(arg0 + 0x20), (const Vec *)((const void *)(arg2)));
        ((TObjPlayer *)(arg0 + 0x30))->copy_xyz((void *)arg3);
        *(f32 *)&this->m_2c = farg0;
        *(s32 *)((s8 *)arg0 + 0x3C) = arg4;
        *(s32 *)((s8 *)arg0 + 0x40) = arg5;
    }
}

void TUnk_804F1280::render() {
    u8 *arg0 = (u8 *)this;
    if (((s32) *(s32 *)((s8 *)arg0 + 0x1C) != 0) && (TBoss6PlotFalz__sub_802AB6CC(arg0 + 0x20, (f32) (this->m_2c - TBoss6Rock__data_805DFF48)) != 0)) {
        push_matrix();
        post_translate_matrix(arg0 + 0x20);
        rotate_matrix_y(0, this->m_34);
        rotate_matrix_x(0, (int) (*(s32 *)&this->unk_30));
        rotate_matrix_z(0, (int) (*(s32 *)&this->unk_38));
        TObjFish::set_global_param(this->m_3c);
        TBoss6PlotFalz::set_fade_material_color(TBoss6Rock__data_805DFF4C);
        draw_ginja_object((void *)(*(s32 *)&this->unk_40));
        TObjFish::reset_fish_globals();
        pop_matrix();
    }
}

void TUnk_804F1280::run_task() { if (is_active__10TBoss6RockFv(this) == 0) { *(int*)((char*)this + 0x1c) = 0; queue_destruction__7TObjectFv(this); } }

extern s32 lbl_804F1280[];

void *TUnk_804F1280::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804F1280;
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void *TUnk_804F1280::init_object(void *) {
    __ct__7TObjectFP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804F1280;
    *(u32 *)&(*(u16 *)((u8 *)this + 0x1C)) = 0;
    return this;
}

extern void *tl_06;

void *TBoss6Rock::create() {
    void *o = __nw__7TObjectFUl(0x44);
    if (o != NULL) {
        o = ((TUnk_804F1280 *)o)->init_object(tl_06);
    }
    return o;
}

int TBoss6Rock__sub_80353A04(void) {  return TBoss6Rock__data_805D6EF4; }

int TBoss6Rock__sub_80353A0C(void) {  return TBoss6Rock__data_805D6EF0; }

typedef char RecoveredGlobal_80353E10_TBoss6Rock__data_80543778_size[sizeof(RecoveredGlobal_80353E10_TBoss6Rock__data_80543778) == 0x80 ? 1 : -1];

typedef char RecoveredGlobal_80353DC4_TBoss6Rock__data_80543778_size[sizeof(RecoveredGlobal_80353DC4_TBoss6Rock__data_80543778) == 0x80 ? 1 : -1];

#pragma push
#pragma fp_contract on
s32 TBoss6Rock__sub_80353A14(s32 arg0, Vec_80353A14 *out, f32 *outR) {
    u8 *rec;
    f32 r;
    f32 d;
    f32 s;
    Vec_80353A14 a;
    Vec_80353A14 b;
    Vec_80353A14 c;
    if (TBoss6Rock::is_rock_valid(arg0) == 0) {
        return 0;
    }
    if (TBoss6Rock__data_805D6EF8 == NULL) {
        return 0;
    }
    rec = TBoss6Rock::get_rock_entry(arg0);
    if (rec == NULL) {
        return 0;
    }
    r = *(f32 *)(rec + 4);
    VecCopy((Vec *)&a, (const Vec *)(TBoss6Rock__data_805D6EF8 + 0x38));
    a.y = TBoss6Rock__data_805DFF50;
    VecCopy((Vec *)&b, (const Vec *)(&((Vec_80353A14 *)TBoss6Rock__rock_point_table)[arg0]));
    VecCopy((Vec *)&c, (const Vec *)&b);
    subtract_vector(&c, &a);
    d = vector_length(&c);
    if (d <= lbl_805DFF54) {
        return 0;
    }
    if (d > lbl_805DFF58) {
        d = lbl_805DFF58;
    }
    normalize_vector(&c);
    s = r - r * (1.0f - (d - 100.0f) / 100.0f);
    c.x *= s;
    c.z *= s;
    vec3_add_to(&c, &b);
    VecCopy((Vec *)out, (const Vec *)&c);
    *outR = r;
    return 1;
}
#pragma pop

void TBoss6Rock::break_rocks_in_radius(f32 r) {
    Vec_80353B7C v;
    s32 i;
    R_80353B7C *p;
    for (i = 0; i < 0x20; i++) {
        p = (R_80353B7C *)TBoss6Rock::get_rock_entry(i);
        if (p != NULL && ((s32 (*)(s32))is_rock_state_2__10TBoss6RockFi)(i) != 0 && !(((Vec_80353B7C *)this)->y > r + p->f8)) {
            f32 lim = r + p->f4;
            VecCopy((Vec *)&v, (const Vec *)(&((Vec_80353B7C *)TBoss6Rock__rock_point_table)[i]));
            subtract_vector(&v, this);
            v.y = TBoss6Rock__data_805DFF50;
            if (vector_length(&v) <= lim) {
                TBoss6Rock::clear_rock_state(i);
            }
        }
    }
}

s32 TBoss6Rock::push_out_of_rocks(f32 r) {
    Vec_80353C60 v;
    s32 hit;
    s32 i;
    f32 y = TBoss6Rock__data_805DFF50;
    f32 lim = lbl_805DFF60 + r;
    hit = 0;
    for (i = 0; i < 0x20; i++) {
        f32 d;
        VecCopy((Vec *)&v, (const Vec *)this);
        subtract_vector(&v, &((Vec_80353C60 *)TBoss6Rock__rock_point_table)[i]);
        v.y = y;
        d = vector_length(&v);
        if (!(d >= lim)) {
            if (d <= lbl_805DFF64) {
                v.x = TBoss6Rock__data_805DFF5C;
            }
            normalize_vector(&v);
            v.x *= lim;
            v.z *= lim;
            vec3_add_to(this, &v);
            hit = 1;
        }
    }
    return hit;
}

s32 TBoss6Rock::get_point(s32 arg0, s32 arg1, f32 *arg2) {
    if (TBoss6Rock::is_rock_valid(arg0) == 0) {
        return 0;
    }
    VecCopy((Vec *)(arg1), (const Vec *)((const void *)((void *) ((u8 *)&TBoss6Rock__rock_point_table + (arg0 * 0xC)))));
    *(f32 *)((s8 *)arg2 + 0) = *(f32 *)((s8 *)(TBoss6Rock::get_rock_entry(arg0)) + 4);
    return 1;
}

u8 is_rock_state_2__10TBoss6RockFi(s32 arg0) {
    u8 *temp_r3;
    if ((arg0 < 0) || (arg0 >= 0x20)) {
        return 0U;
    }
    temp_r3 = (u8 *)(*(s32 *)((s8 *)(&(*(RecoveredGlobal_80353DC4_TBoss6Rock__data_80543778 *)&TBoss6Rock__instance_table).value) + (arg0 * 4)));
    if (temp_r3 == NULL) {
        return 0U;
    }
    return (u8) (*(s32 *)((s8 *)temp_r3 + 0xC8) == 2);
}

s32 TBoss6Rock::is_rock_valid(s32 arg0) {
    u8 *temp_r3;
    if ((arg0 < 0) || (arg0 >= 0x20)) {
        return 0U;
    }
    temp_r3 = (u8 *)(*(s32 *)((s8 *)&TBoss6Rock__instance_table.value + (arg0 * 4)));
    if (temp_r3 == NULL) {
        return 0U;
    }
    return (u8) (*(s32 *)((s8 *)temp_r3 + 0xC4) == 2);
}

void TBoss6Rock::reset_rock_state(s32 arg0) {
    R_80353E5C *r;
    if (arg0 < 0 || arg0 >= 0x20) {
        return;
    }
    r = ((R_80353E5C * *)&TBoss6Rock__instance_table)[arg0];
    if (r == NULL || r->fC4 != 2) {
        return;
    }
    r->fC8 = 0;
}

void TBoss6Rock::clear_rock_state(s32 i) {
    Rock_80353EA4 *p;
    if (i < 0 || i >= 0x20) {
        return;
    }
    p = ((Rock_80353EA4 **)&TBoss6Rock__instance_table)[i];
    if (p != NULL) {
        p->state = 0;
    }
}

void TBoss6Rock::set_rock_target(s32 i, s32 a, s32 b) {
    Rock_80353EDC *p;
    if (i < 0 || i >= 0x20) {
        return;
    }
    p = ((Rock_80353EDC **)&TBoss6Rock__instance_table)[i];
    if (p != NULL) {
        p->state = 2;
        p->b8 = a;
        p->c0 = b;
    }
}

void TBoss6Rock::release_object() { if (*(unsigned int *)&this->m_b0 != 0) { queue_destruction__7TObjectFv(*(void* *)&this->m_b0); *(int *)&this->m_b0 = 0; } }

typedef struct Blk_80353F5C Blk_80353F5C;
typedef struct Elem_80353F5C Elem_80353F5C;
typedef struct Obj_80353F5C Obj_80353F5C;
typedef struct Vec_80353F5C Vec_80353F5C;
void TBoss6Rock::sub_80353F5C() {
    Obj_80353F5C *o = (Obj_80353F5C *)this;
  Elem_80353F5C *new_var;
  Blk_80353F5C blk;
  u8 *new_var2;
  Elem_80353F5C *e;
 do { } while (0);
  if (this->m_b0 == 0)
  {
    VecCopy((Vec *)&blk.v1, (const Vec *)(((u8 *) o) + 0xD4));
    ((TObjPlayer *)(&blk.v2))->copy_xyz(lbl_80479280);
    new_var2 = (u8 *) ((Elem_80353F5C *)&TBoss6Rock__data_80479258);
    new_var2 = (this->m_b4 * 0x14) + new_var2;
    new_var = (Elem_80353F5C *) new_var2;
    e = new_var;
    blk.a = 2;
    blk.b = 0;
    blk.v3.z = e->fc;
    blk.v3.x = e->fc;
    blk.v3.y = e->f8;
    this->m_b0 = create__10TObjMapCsnFl(&blk, e, e->fc);
  }
}

#pragma push
#pragma fp_contract on
void TBoss6Rock::randomize_motion() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)&this->rotation_x = (s32) (lbl_805DFF68 * ((lbl_805DFF6C * (f32) rand()) - TBoss6Rock__data_805DFF4C));
    this->rotation_y = (s32) (lbl_805DFF70 * (lbl_805DFF6C * (f32) rand()));
    this->rotation_z = (s32) (lbl_805DFF68 * ((lbl_805DFF6C * (f32) rand()) - TBoss6Rock__data_805DFF4C));
    this->m_d0 = (s32) (lbl_805DFF74 * ((lbl_805DFF6C * (f32) rand()) - TBoss6Rock__data_805DFF4C));
    VecCopy((Vec *)((void *)(arg0 + 0x38)), (const Vec *)((const void *)((void *)(arg0 + 0xD4))));
    *(f32 *)((s8 *)arg0 + 0x3C) = (f32) lbl_805DFF78;
}
#pragma pop

#pragma push
#pragma peephole off
typedef char RecoveredGlobal_80354148_TBoss6Rock__data_80479258_size[sizeof(RecoveredGlobal_80354148_TBoss6Rock__data_80479258) == 0x28 ? 1 : -1];
typedef char RecoveredGlobal_80354148_TBoss6Rock__data_80543778_size[sizeof(RecoveredGlobal_80354148_TBoss6Rock__data_80543778) == 0x80 ? 1 : -1];
u8 *TBoss6Rock::get_rock_entry(s32 arg0) {
    if ((arg0 < 0) || (arg0 >= 0x20)) {
        return NULL;
    }
    return (u8 *)&TBoss6Rock__data_80479258.value + (*(s32 *)((s8 *)(*(u8 **)((s8 *)((u8 *)(&(*(RecoveredGlobal_80354148_TBoss6Rock__data_80543778 *)&TBoss6Rock__instance_table).value) + (arg0 * 4)) + 0)) + 0xB4) * 0x14);
}
#pragma pop

extern "C" {
void TBoss6PlotFalz__sub_802AC724(void *, void *);
extern s32 lbl_805D6EFC;
extern const f32 lbl_805DFF8C;
extern const f32 lbl_805DFF90;
}

void TBoss6Rock__sub_803542E8(TBoss6Rock *rock, s32 landed) {
    s32 count;
    E_803546B0 *entries;
    s32 i;
    TObjPlayer *player;
    f32 radius;
    f32 dist;
    Vec d;

    if (landed == 0) {
        rock->m_e0++;
        if (rock->m_e0 & 1) {
            return;
        }
    }
    count = TLobby::get_game_mode();
    entries = (E_803546B0 *)&TBoss6Rock__data_80479258;
    radius = entries[rock->m_b4].f4;
    if (landed != 0) {
        radius += lbl_805DFF8C;
    }
    for (i = 0; i < count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (((TBoss6PlotFalz *)player)->is_active() == 0) {
            continue;
        }
        VecCopy(&d, (const Vec *)player->position);
        subtract_vector(&d, &rock->m_d4);
        d.y = TBoss6Rock__data_805DFF50;
        dist = vector_length(&d);
        if (dist >= radius) {
            continue;
        }
        if (dist <= lbl_805DFF64) {
            d.x = TBoss6Rock__data_805DFF5C;
        }
        normalize_vector(&d);
        d.x *= radius;
        d.z *= radius;
        vec3_add_to(&d, &rock->m_d4);
        TBoss6PlotFalz__sub_802AC724(player, &d);
        if (landed != 0) {
            DirectAttackPayload h;
            s32 damage = TBoss6PlotFalz::rand_vary_count(lbl_805D6EFC, lbl_805DFF90);
            h.kind = 0;
            h.power = damage;
            player->receive_direct_attack(TBoss6Rock__data_805D6EF8, h, 0, -1, -1);
        }
    }
}

void TBoss6Rock::break_and_release() {
    u8 *arg0 = (u8 *)this;
    TBoss6Rock__sub_803542E8(this, 0);
    if ((s32) this->m_bc == 1) {
        this->m_c8 = 0;
    }
    if ((s32) this->m_c8 != 2) {
        ((TBoss6Rock *)(arg0 + 0xD4))->spawn_crush_rocks(this->m_b4);
        play_sound_effect(0x4006AB1F, (u32)(arg0 + 0x38), 0, 0);
        release_object();
        randomize_motion();
        this->m_c4 = 0;
    }
}
#pragma fp_contract on

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TBoss6Rock::update_fall() {
    u8 *arg0 = (u8 *)this;
    f32 var_f1;
    f32 var_f2;
    var_f1 = lbl_805DFF94;
    var_f2 = lbl_805DFF98;
    this->rotation_y = (s32) (this->rotation_y + this->m_d0);
    if ((s32) this->m_bc == 1) {
        var_f1 = lbl_805DFF9C;
        var_f2 = lbl_805DFFA0;
    }
    *(f32 *)&this->unk_CC = (f32) (*(f32 *)&this->unk_CC + var_f1);
    if (*(f32 *)&this->unk_CC < var_f2) {
        *(f32 *)&this->unk_CC = var_f2;
    }
    *(f32 *)((s8 *)arg0 + 0x3C) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C) + *(f32 *)&this->unk_CC);
    if (*(f32 *)((s8 *)arg0 + 0x3C) <= TBoss6Rock__data_805DFF50) {
        *(f32 *)((s8 *)arg0 + 0x3C) = (f32) TBoss6Rock__data_805DFF50;
        *(f32 *)&this->unk_CC = (f32) TBoss6Rock__data_805DFF50;
        TBoss6Rock__sub_803542E8(this, 1);
        ((TBoss6Rock *)arg0)->sub_80353F5C();
        play_sound_effect(0x4006B51E, (u32)(arg0 + 0x38), 0, 0);
        spawn_particle_effect(((u8 *)&this->position), 0x220);
        spawn_particle_effect(((u8 *)&this->position), 0x222);
        TBoss6PlotFalz::apply_radial_effect_to_players((u8 *)&this->position, 0xC0, 0xF, lbl_805DFF54);
        this->m_c4 = 2;
    }
}
#pragma pop

void TBoss6Rock::init_spin_params() {
  s32 temp_r4;
  if (((s32)this->m_c8) != 0)
  {
    f32 k = TBoss6Rock__data_805DFF4C;
    f32 s = lbl_805DFF98;
    if ((TBoss6Rock__data_805DFF4C && TBoss6Rock__data_805DFF4C) && TBoss6Rock__data_805DFF4C)
    {
    }
    temp_r4 = this->m_ac;
    *((f32 *) (((s8 *) this) + 0xCC)) = (f32) (s * ((k * (((f32) (temp_r4 & 3)) / TBoss6Rock__data_805DFF48)) + (k * (((f32) temp_r4) * lbl_805DFFA4))));
    this->m_c4 = 1;
    this->m_b4 = (s32)this->m_b8;
    this->m_bc = (s32)this->m_c0;
  }
}
void TBoss6Rock::draw_model() {
    R_803546B0 *arg0 = (R_803546B0 *)this;
    if (arg0->fC4 == 0) {
        return;
    }
    if (arg0->fE4 != 0) {
        u8 *t = (u8 *)&TBoss6Rock__data_80479258;
        t = t + arg0->fB4 * 0x14;
        E_803546B0 *e = (E_803546B0 *)t;
        if (((s32 (*)(void *, void *, f32))TBoss6PlotFalz__sub_802AB6CC)(arg0->f38, e, e->f4 - TBoss6Rock__data_805DFF48) != 0) {
            return;
        }
    }
    push_matrix();
    post_translate_matrix(arg0->f38);
    rotate_matrix_y(0, arg0->f60);
    rotate_matrix_x(0, arg0->f5C);
    rotate_matrix_z(0, arg0->f64);
    TObjFish::set_global_param((*(s32 *)&TBoss6Rock__data_805D6EF4));
    draw_ginja_object((void *)(get_bml_model((*(s32 *)&TBoss6Rock__data_805D6EF0), ((E_803546B0 *)&TBoss6Rock__data_80479258)[arg0->fB4].id)));
    pop_matrix();
}

}
