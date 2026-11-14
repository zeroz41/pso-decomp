#include "types.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TUnk_804A2260.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804A2358.h"
#include "pso/technique/TTecFoie.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_8012121C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801542CC.h"

struct Hit_80124C90 { u8 pad0[4]; Vec *pos; };

struct Atk_80124C90 { s32 a; s32 b; s32 d8; s16 id0; s16 id1; s16 idx; s16 pad; f32 f; };

struct Part_80124C90 { u8 pad0[0x1C]; Vec v; u8 pad28[4]; };

struct Tgt_80124C90 { u8 pad0[0xA4]; Part_80124C90 *parts; };

struct Pl_80124C90 { u8 pad0[0x38]; Vec pos38; u8 pad44[0x60 - 0x44]; s32 angle; u8 pad64[0x2FC - 0x64]; Vec pos; };

struct Me_80124C90 { u8 pad0[0xF0]; Pl_80124C90 *pl; u8 padf4[0x1E4 - 0xF4]; f32 scale; };

extern "C" {
s16 get_entity_id(void *);
Hit_80124C90 *csnVector(void *, void *, int);
}
void spawn_item_attacker(s32 arg0, u32 arg1, s32 arg2, u8 *arg3);
extern "C" {
void create_lavis_shot(void *, void *, void *, f32);
f32 *get_weapon_range_record(void *, s32);
void *get_captured_target_entry(void *, s32);
s32 transform_point_by_current_matrix(void *, void *);
f32 xyz_distance(void *, void *);
void TUnk_804A2260::sub_80124C90() {
    Me_80124C90 *me = (Me_80124C90 *)this;
    void *ext;
    Vec *pos;
    void *e;
    Tgt_80124C90 *t;
    s32 found;
    Atk_80124C90 atk;
    s32 i;
    Hit_80124C90 *hit;
    ext = ((TObjPlayer *)(me->pl))->get_extended_state();
    if (ext == NULL) {
        return;
    }
    found = 0;
    pos = &me->pl->pos;
    Vec dst = *pos;
    if (get_captured_target_count((s32 *)ext) != 0) {
        e = get_captured_target_entry(ext, get_captured_target_count((s32 *)ext) - 1);
        t = (Tgt_80124C90 *)resolve_hittable_target(((TObjPlayer *)e)->get_uid(), get_captured_target_collider_index(e));
        if (t != NULL) {
            Part_80124C90 *pp = &t->parts[get_captured_target_collider_index(e)];
            VecCopy((Vec *)&dst, (const Vec *)&pp->v);
            found = 1;
        }
    }
    if (found == 0) {
        Vec off;
        push_matrix_from(identity_matrix);
        f32 *r1 = get_weapon_range_record(this, 2);
        off.x = off.y = 0.0f;
        off.z = *r1;
        rotate_matrix_y(0, me->pl->angle);
        transform_point_by_current_matrix(&off, &dst);
        pop_matrix();
        vec3_add_to(&dst, pos);
    }
    hit = csnVector(pos, &dst, 0x8100);
    if (hit != NULL) {
        xyz_distance(pos, hit->pos);
    } else {
        xyz_distance(pos, &dst);
    }
    for (i = 0; i != get_captured_target_count((s32 *)ext); i++) {
        e = get_captured_target_entry(ext, i);
        t = (Tgt_80124C90 *)resolve_hittable_target(((TObjPlayer *)e)->get_uid(), get_captured_target_collider_index(e));
        if (t != NULL) {
            Part_80124C90 *part = &t->parts[get_captured_target_collider_index(e)];
            void *e2 = get_captured_target_entry(ext, i);
            atk.a = 0;
            atk.b = 1;
            atk.id0 = get_entity_id(me->pl);
            atk.id1 = get_entity_id(t);
            atk.d8 = ((TItem *)((u8 *)this))->get_item_id();
            atk.idx = get_captured_target_collider_index(e2);
            atk.f = ((TObjPlayer *)me->pl)->query_extended_state();
            spawn_item_attacker((s32)tl_05, (u32)&me->pl->pos38, (s32)(xyz_distance(pos, &part->v) / me->scale), (u8 *)&atk);
        }
    }
    {
        f32 *rec = get_weapon_range_record(this, 2);
        s32 ang = me->pl->angle;
        Vec o;
        Vec v;
        for (i = 0; i != 4; i++, ang += 0x4000) {
            push_matrix_from(identity_matrix);
            v.x = v.y = 0.0f;
            v.z = *rec;
            rotate_matrix_y(0, ang);
            transform_point_by_current_matrix(&v, &o);
            vec3_add_to(&o, pos);
            pop_matrix();
            hit = csnVector(pos, &o, 0x8100);
            if (hit != NULL) {
                VecCopy((Vec *)&o, (const Vec *)hit->pos);
            }
            create_lavis_shot(this, pos, &o, xyz_distance(pos, &o) / me->scale);
        }
    }
}
}

extern "C" {

void TUnk_804A2260::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        if (((TObjPlayer *)((u8 *)this->owner + 0x7CC))->get_stage_strike_count() == 0) {
            ((TObjPlayer *)this)->drain_owner_hp_fraction(0.05f);
            sub_80124C90();
        }
    } else {
        ((TObjPlayer *)this)->update_active_game_effect();
    }
}

void TUnk_804A2260::vfunc_60() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 1:
        TItem::begin_effect_render();
        rotate_matrix_z(NULL, rotation_z);
        return;
    case 4:
        TItem::begin_effect_render();
        rotate_matrix_z(NULL, -rotation_z);
        return;
    }
}

void TUnk_804A2260::update_weapon() {
    rotation_z += 0xAAA;
}

}

TUnk_804A2260::~TUnk_804A2260() {

}

TUnk_804A2260::TUnk_804A2260(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x100022);
    shot_speed = 10.0f;
    rotation_z = 0;
}

u8 *TObjPlayer::create_state_80125154(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A2260(tl_05, item);
    }
    return NULL;
}

extern "C" {


s16 TObjPlayer::get_stage_strike_count() { return *(s16*)((char*)this + 0x12); }

}
