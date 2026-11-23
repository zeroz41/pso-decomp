#include "types.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TUnk_804A2260.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/weapon/TUnk_804A2358.h"
#include "pso/technique/TTecFoie.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_8012121C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/effect/item/TItemEffLavis.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/TUnk_8012AF00.h"

struct Hit_80124C90 { u8 pad0[4]; Vec *pos; };

struct Part_80124C90 { u8 pad0[0x1C]; Vec v; u8 pad28[4]; };

struct Tgt_80124C90 { u8 pad0[0xA4]; Part_80124C90 *parts; };

struct Pl_80124C90 { u8 pad0[0x38]; Vec pos38; u8 pad44[0x60 - 0x44]; s32 angle; u8 pad64[0x2FC - 0x64]; Vec pos; };

struct Me_80124C90 { u8 pad0[0xF0]; Pl_80124C90 *pl; u8 padf4[0x1E4 - 0xF4]; f32 scale; };

extern "C" {
Hit_80124C90 *csnVector(void *, void *, int);
}
extern "C" {
f32 *get_weapon_range_record(void *, s32);
s32 transform_point_by_current_matrix(void *, void *);
void TUnk_804A2260::sub_80124C90() {
    Me_80124C90 *me = (Me_80124C90 *)this;
    TUnk_8012AF00 *ext;
    Vec *pos;
    TUnk_8012AF50 *e;
    Tgt_80124C90 *t;
    s32 found;
    Unk_8010340C atk;
    s32 i;
    Hit_80124C90 *hit;
    ext = ((TObjPlayer *)(me->pl))->get_extended_state();
    if (ext == NULL) {
        return;
    }
    found = 0;
    pos = &me->pl->pos;
    Vec dst = *pos;
    if (ext->get_captured_target_count() != 0) {
        e = ext->get_captured_target_entry(ext->get_captured_target_count() - 1);
        t = (Tgt_80124C90 *)resolve_hittable_target(e->get_uid(), e->get_captured_target_collider_index());
        if (t != NULL) {
            Part_80124C90 *pp = &t->parts[e->get_captured_target_collider_index()];
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
    for (i = 0; i != ext->get_captured_target_count(); i++) {
        e = ext->get_captured_target_entry(i);
        t = (Tgt_80124C90 *)resolve_hittable_target(e->get_uid(), e->get_captured_target_collider_index());
        if (t != NULL) {
            Part_80124C90 *part = &t->parts[e->get_captured_target_collider_index()];
            TUnk_8012AF50 *e2 = ext->get_captured_target_entry(i);
            atk.reserved = 0;
            atk.kind = 1;
            atk.source = ((TObjBase *)(me->pl))->get_entity_id();
            atk.target = ((TObjBase *)(t))->get_entity_id();
            atk.weapon = this->get_item_id();
            atk.collider = e2->get_captured_target_collider_index();
            atk.damage = ((TObjPlayer *)me->pl)->query_extended_state();
            spawn_item_attacker(tl_05, &me->pl->pos38, (s32)(xyz_distance(pos, &part->v) / me->scale), &atk);
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
void TUnk_804A2260::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        if (((TObjPlayer *)((u8 *)this->owner + 0x7CC))->get_stage_strike_count() == 0) {
            ((TItemWeapon *)this)->drain_owner_hp_fraction(0.05f);
            sub_80124C90();
        }
    } else {
        ((TItemWeapon *)this)->update_active_game_effect();
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

TItem *TObjPlayer::create_state_80125154(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A2260(tl_05, item);
    }
    return NULL;
}


s16 TObjPlayer::get_stage_strike_count() { return *(s16*)((char*)this + 0x12); }

