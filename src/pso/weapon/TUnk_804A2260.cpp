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
#include "pso/player/CapturedTargetList.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer_801D2E20.h"

extern "C" f32 *get_weapon_range_record(void *, s32);

void TUnk_804A2260::sub_80124C90() {
    CapturedTargetList *ext;
    Vec *pos;
    CapturedTarget *e;
    TObjChara *t;
    s32 found;
    DelayedWeaponHit atk;
    s32 i;
    CsnHit *hit;
    ext = (CapturedTargetList *)owner->get_extended_state();
    if (ext == NULL) {
        return;
    }
    found = 0;
    pos = &owner->body_center;
    Vec dst = *pos;
    if (ext->get_captured_target_count() != 0) {
        e = ext->get_captured_target_entry(ext->get_captured_target_count() - 1);
        t = resolve_hittable_target(e->get_uid(), e->get_captured_target_collider_index());
        if (t != NULL) {
            CollisionBody *pp = &t->bodies[e->get_captured_target_collider_index()];
            VecCopy(&dst, &pp->center);
            found = 1;
        }
    }
    if (found == 0) {
        Vec off;
        push_matrix_from(identity_matrix);
        f32 *r1 = get_weapon_range_record(this, 2);
        off.x = off.y = 0.0f;
        off.z = *r1;
        rotate_matrix_y(0, owner->rotation_y);
        transform_point_by_current_matrix(&off.x, &dst);
        pop_matrix();
        vec3_add_to(&dst, pos);
    }
    hit = csnVector(pos, &dst, 0x8100);
    if (hit != NULL) {
        xyz_distance(pos, &hit->contact->point);
    } else {
        xyz_distance(pos, &dst);
    }
    for (i = 0; i != ext->get_captured_target_count(); i++) {
        e = ext->get_captured_target_entry(i);
        t = resolve_hittable_target(e->get_uid(), e->get_captured_target_collider_index());
        if (t != NULL) {
            CollisionBody *part = &t->bodies[e->get_captured_target_collider_index()];
            CapturedTarget *e2 = ext->get_captured_target_entry(i);
            atk.reserved = 0;
            atk.kind = 1;
            atk.source = owner->get_entity_id();
            atk.target = t->get_entity_id();
            atk.weapon = get_item_id();
            atk.collider = e2->get_captured_target_collider_index();
            atk.damage = owner->query_extended_state();
            spawn_item_attacker(tl_05, &owner->position, (s32)(xyz_distance(pos, &part->center) / shot_speed), &atk);
        }
    }
    {
        f32 *rec = get_weapon_range_record(this, 2);
        s32 ang = owner->rotation_y;
        Vec o;
        Vec v;
        for (i = 0; i != 4; i++, ang += 0x4000) {
            push_matrix_from(identity_matrix);
            v.x = v.y = 0.0f;
            v.z = *rec;
            rotate_matrix_y(0, ang);
            transform_point_by_current_matrix(&v.x, &o);
            vec3_add_to(&o, pos);
            pop_matrix();
            hit = csnVector(pos, &o, 0x8100);
            if (hit != NULL) {
                VecCopy(&o, &hit->contact->point);
            }
            create_lavis_shot(this, pos, &o, xyz_distance(pos, &o) / shot_speed);
        }
    }
}
void TUnk_804A2260::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        if (((TObjPlayer *)&owner->attack_state)->get_stage_strike_count() == 0) {
            drain_owner_hp_fraction(0.05f);
            sub_80124C90();
        }
    } else {
        update_active_game_effect();
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


s16 TObjPlayer::get_stage_strike_count() { return ((s16 *)this)[9]; }

