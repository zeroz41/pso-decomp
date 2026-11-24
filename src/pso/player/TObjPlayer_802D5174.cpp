// The TUnk_804E23F0 weapon family: TUnk_804E1BB0 and TUnk_804E23F0 with the
// seven TUnk_804E23F0 subclasses that create_object_by_type picks from the
// item code, 0x802D5108-0x802D6348. One TU: its vtables and jump table fill
// .data 0x804E1BB0-0x804E24F0 in text order, which -inline off,deferred only
// gives with the source written last to first (as below).
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/player/TObjPlayer_802D5174.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/vector.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemLoad.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/item/TItemEffNeedle.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/object/trap/TOTrap.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/effect/item/TItemWpnCardEffect.h"
#include "pso/unk/text_80120908.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804E1BB0.h"
#include "pso/unk/text_80120D50.h"
#include "pso/weapon/TUnk_804E1CA8.h"
#include "pso/weapon/TUnk_804E1E08.h"
#include "pso/weapon/TUnk_804E1F04.h"
#include "pso/weapon/TUnk_804E2000.h"
#include "pso/weapon/TUnk_804E20FC.h"
#include "pso/weapon/TUnk_804E21F8.h"
#include "pso/weapon/TUnk_804E22F4.h"
#include "pso/weapon/TUnk_804E23F0.h"
#include "pso/unk/text_803D96A8.h"

struct W_802D5B78 { s32 a; s32 b; s32 c; };

extern "C" {
void spawn_hit_particles__10TObjPlayerFiPv(saddr pos, const Vec *dir);
void get_weapon_color__11TItemWeaponFPv(void *, void *);
s32 rotate_matrix_about_axis(int, void *, int);
void set_matrix_identity(u8 *matrix);
}

TUnk_804E23F0::~TUnk_804E23F0() {}

TUnk_804E22F4::~TUnk_804E22F4() {}

TUnk_804E21F8::~TUnk_804E21F8() {}

TUnk_804E20FC::~TUnk_804E20FC() {}

TUnk_804E2000::~TUnk_804E2000() {}

TUnk_804E1F04::~TUnk_804E1F04() {}

TUnk_804E1E08::~TUnk_804E1E08() {}

TItem *TObjPlayer::create_object_by_type(u8 *item) {
    if (item != NULL) {
        switch (item[1]) {
        case 0x8C:
            switch (item[2]) {
            case 0:
                break;
            case 1:
                return new TUnk_804E1F04(tl_05, item);
            case 2:
                return new TUnk_804E22F4(tl_05, item);
            case 3:
                return new TUnk_804E21F8(tl_05, item);
            }
            break;
        case 0x93:
            return new TUnk_804E2000(tl_05, item);
        case 0xA4:
            return new TUnk_804E20FC(tl_05, item);
        case 0x96:
            return new TUnk_804E1CA8(tl_05, item);
        }
        return new TUnk_804E1E08(tl_05, item);
    }
    return NULL;
}

TUnk_804E23F0::TUnk_804E23F0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(3);
    pad_1f8 = 0;
    effect_id = 445;
    pad_204 = (void *)start_wall_card;
    pad_208 = (void *)TObjPlayer::create_network_object;
    pad_200 = 4.0f;
}

void TUnk_804E23F0::reserved_53() {
    if (test_weapon_flags(0x01000000) == 0) {
        draw_weapon_model();
    }
}

void TUnk_804E23F0::vfunc_60() {
    if (TObjPlayer::get_player_list() == 0) {
        NJS_POINT3 offset = { 0.0f, 0.0f, 0.5f };
        post_translate_matrix(&offset.x);
        rotate_matrix_x(0, 0x18E3);
        if (pad_1f8 & 1) {
            push_matrix();
            rotate_matrix_x(0, 0x2AAA);
            draw_model();
            pop_matrix();
            push_matrix();
            rotate_matrix_x(0, -0x2AAA);
            draw_model();
            pop_matrix();
        }
    }
}

void TUnk_804E23F0::emit_marker_effects() {
    Vec pos;
    owner->get_anim_node_position(0x30, &pos);
    if (owner->attack_state.get_validated_attack_stage() == 2) {
        fire_shot_at_target(&pos, item_model, 0);
        fire_shot_at_target(&pos, item_model, 0x1555);
        fire_shot_at_target(&pos, item_model, -0x1555);
    } else {
        fire_shot_at_target(&pos, item_model, 0);
    }
    vfunc_62(&pos);
}

void TUnk_804E23F0::vfunc_62(Vec *pos) {
    if (get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->create_item_eff_cane(this, -1, effect_id);
    }
}

void TUnk_804E23F0::update_weapon() {
    if (get_attack_stage() == 2) {
        pad_1f8 |= 1;
    } else {
        pad_1f8 &= ~1;
    }
}

void TUnk_804E23F0::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    NJS_ARGB color;
    desc->scale = pad_200;
    desc->spin[2] = 0xC000;
    desc->flags |= 2;
    get_weapon_color__11TItemWeaponFPv(&color, this);
    copy_argb(&desc->color, &color);
    desc->hit_effect = pad_208;
    desc->wall_effect = pad_204;
}

#pragma push
#pragma fp_contract on

void TObjPlayer__sub_802D5B78(const ActorBodyHit *hit, Vec *out, Vec *direction) {
    s32 *wsrc;
    s32 a;
    s32 b;
    s32 c;
    W_802D5B78 w;
    // Copy the input words before normalization so the output may alias it.
    wsrc = (s32 *)direction;
    c = wsrc[0];
    a = c;
    b = wsrc[1];
    c = wsrc[2];
    w.a = a;
    w.b = b;
    w.c = c;
    normalize_vector((Vec *)&w);
    const CollisionBody *body = &hit->target->bodies[hit->body];
    const f32 radius = body->radius;
    out->x = body->center.x - (*(f32 *)&w.a) * radius;
    out->y = body->center.y - (*(f32 *)&w.b) * radius;
    out->z = body->center.z - (*(f32 *)&w.c) * radius;
}

#pragma pop

void TObjPlayer::spawn_item() {
    NJS_OBJECT *model;
    NJS_TEXLIST *texture;
    TParticleCtrl *particle;

    particle = spawn_particle_effect(((Vec *)this), 0x1BF);
    if (particle != NULL) {
        TItemLoad::get_item_model(0xD, &model);
        TItemLoad::get_item_texture_list(0xD, &texture);
        attach_particle_model(particle, model, texture, 0, 0, 1.0f);
        particle->set_scale(10.0f, 10.0f);
    }
}

TUnk_804E1E08::TUnk_804E1E08(TObject *parent, u8 *item) : TUnk_804E23F0(parent, item) {
    pad_200 = 5.0f;
}

TUnk_804E1F04::TUnk_804E1F04(TObject *parent, u8 *item) : TUnk_804E23F0(parent, item) {
    effect_id = 341;
    pad_204 = (void *)start_red_wall_card;
    pad_208 = (void *)TObjPlayer::create_aux_object;
}

TUnk_804E22F4::TUnk_804E22F4(TObject *parent, u8 *item) : TUnk_804E23F0(parent, item) {
    effect_id = 447;
    pad_204 = (void *)TObjPlayer::alloc_and_init;
    pad_208 = (void *)TObjPlayer::create_and_init_effect;
}

void TUnk_804E22F4::vfunc_62(Vec *pos) {
    ((TObjPlayer *)pos)->spawn_item();
}

TUnk_804E21F8::TUnk_804E21F8(TObject *parent, u8 *item) : TUnk_804E23F0(parent, item) {
    s32 i;
    Vec *origin;
    pad_248 = 0;
    pad_24a = 0;
    origin = pad_20c;
    for (i = 0; i < 5; i++) {
        origin->x = 0.0f;
        origin->y = 0.0f;
        origin->z = 0.0f;
        origin++;
    }
    pad_204 = (void *)TObjPlayer::alloc_and_init;
    pad_208 = (void *)TObjPlayer::create_and_init_effect;
}

void TUnk_804E21F8::on_equipped() {
    pad_248 = 0;
    pad_24a = 0;
    pad_24c = 5.0f + TObjPlayer__sub_8017A1A4(owner, 0);
    pad_250 = 0;
    sub_802D577C();
}

void TUnk_804E21F8::update_weapon() {
    s16 frames;
    s16 count;
    frames = pad_248;
    frames += 1;
    pad_248 = frames;
    if (frames == 0x96) {
        count = pad_24a;
        if (count < 5) {
            pad_24a = count + 1;
            send_activate_effect(pad_24a);
        }
        pad_248 = 0;
    }
    sub_802D577C();
}

__declspec(section ".rodata") Vec lbl_8047259C = { 0 };
__declspec(section ".rodata") Vec player_pb_zero_vec_block = { 0 };
void TUnk_804E21F8::sub_802D577C() {
    Vec *axis_base;
    Vec *point_base;
    Vec *origin;
    f32 *center;
    s32 tilt;
    s16 n;
    s32 angle;
    s32 step;
    s32 tilt_step;
    s32 count;
    n = pad_24a;
    if (n != 0) {
        angle = pad_250;
        count = n;
        origin = pad_20c;
        center = &owner->body_center.x;
        point_base = &lbl_8047259C;
        axis_base = &player_pb_zero_vec_block;
        tilt = 0x31C7;
        step = 0x10000 / n;
        tilt_step = 0x238E / n;
        while (count != 0) {
            Vec point = *point_base;
            point.z = pad_24c;
            Vec axis = *axis_base;
            axis.x = cos_table_lookup(tilt);
            axis.y = sin_table_lookup(tilt);
            push_matrix();
            set_matrix_identity(0);
            post_translate_matrix(center);
            rotate_matrix_about_axis(0, &axis, angle);
            transform_point_by_current_matrix(&point.x, origin);
            pop_matrix();
            angle += step;
            tilt += tilt_step;
            count--;
            origin++;
        }
        pad_250 += 0x38E;
    }
}

void TUnk_804E21F8::activate_effect(s32 count) {
    if (count < 5) {
        pad_24a = count;
    }
}

void TUnk_804E21F8::reserved_53() {
    Vec *origin;
    s32 n;
    draw_weapon_model();
    if (is_hidden() == 0) {
        n = pad_24a;
        origin = pad_20c;
        while (n != 0) {
            push_matrix();
            post_translate_matrix(&(origin++)->x);
            rotate_matrix_x(0, -0x4000);
            draw_ginja_object(item_model);
            pop_matrix();
            n--;
        }
    }
}

void TUnk_804E21F8::emit_marker_effects() {
    Vec *origin;
    s32 angle;
    s32 step;
    s32 n;
    s32 count;
    origin = pad_20c;
    count = pad_24a;
    n = count;
    angle = pad_250 - owner->rotation_y;
    step = 0x10000 / count;
    while (n != 0) {
        fire_shot_at_target(origin++, item_model, angle);
        angle += step;
        n--;
    }
    vfunc_62(&owner->body_center);
    pad_24a = 0;
    pad_248 = 0x87;
}

void TUnk_804E21F8::vfunc_62(Vec *pos) {
    ((TObjPlayer *)pos)->spawn_item();
}

void TUnk_804E21F8::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    TUnk_804E23F0::init_weapon_effect_descriptor(desc);
    desc->speed = 5.0f;
}

TUnk_804E2000::TUnk_804E2000(TObject *parent, u8 *item) : TUnk_804E23F0(parent, item) {
    effect_id = 341;
    pad_208 = (void *)TObjPlayer::spawn_hit_particles_at;
    pad_204 = (void *)TObjPlayer::spawn_hit_particles_at_vec;
}

void TObjPlayer::spawn_hit_particles_at(s32 arg0, saddr hit, saddr dir) {
    Vec pos;
    TObjPlayer__sub_802D5B78(reinterpret_cast<const ActorBodyHit *>(hit), &pos, reinterpret_cast<Vec *>(dir));
    spawn_hit_particles__10TObjPlayerFiPv((saddr)&pos, (const Vec *)dir);
}

void TObjPlayer::spawn_hit_particles_at_vec(s32 arg0, saddr arg1, saddr dir) {
    Vec pos;
    VecCopy(&pos, (const Vec *)arg1);
    spawn_hit_particles__10TObjPlayerFiPv((saddr)&pos, (const Vec *)dir);
}

extern const f64 lbl_804725B8[1] = { 10430.38043493439 };
void spawn_hit_particles__10TObjPlayerFiPv(saddr pos, const Vec *dir) {
    s32 angles[3];
    create_timed_particle_emitter((void *)pos, 0x1EF, 0, 0xF);
    angles[0] = 0;
    angles[1] = (s32)(lbl_804725B8[0] * atan2_float(dir->x, dir->z));
    angles[2] = 0;
    {
        TParticleCtrl *particle = create_timed_particle_emitter_with_angles((void *)pos, angles, 0x1B8, 0, 0xF, 4);
        if (particle != NULL) {
            particle->set_scale(1.5f, 1.5f);
        }
    }
}

TUnk_804E20FC::TUnk_804E20FC(TObject *parent, u8 *item) : TUnk_804E23F0(parent, item) {
    pad_200 = 1.0f;
    pad_204 = (void *)create_needle_pos_effect;
    pad_208 = (void *)create_needle_effect;
}

void TUnk_804E20FC::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    TUnk_804E23F0::init_weapon_effect_descriptor(desc);
    desc->spin[0] = 0x8000;
}

TUnk_804E1CA8::TUnk_804E1CA8(TObject *parent, u8 *item) : TUnk_804E23F0(parent, item) {
    pad_200 = 5.0f;
    set_weapon_flags(32);
    pad_208 = (void *)TObjPlayer::do_action_447_from_packet;
    pad_204 = (void *)create_needle_pos_effect;
}

void TUnk_804E1CA8::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    TUnk_804E23F0::init_weapon_effect_descriptor(desc);
    if (is_mode_two_and_ready() != 0) {
        ((TItemWeapon *)this)->drain_owner_hp_fraction(0.07f);
        desc->hits = 10;
        desc->model = second_model;
        desc->scale = 1.0f;
    }
}

void TObjPlayer::do_action_447_from_packet(void *item, void *hit, void *dir) {
    Vec pos;
    TObjPlayer__sub_802D5B78(static_cast<const ActorBodyHit *>(hit), &pos, static_cast<Vec *>(dir));
    ((TObjPlayer *)&pos)->do_action_447();
}

void *TObjPlayer::do_action_447() {
    return spawn_particle_effect((const Vec *)this, 447);
}

TUnk_804E1CA8::~TUnk_804E1CA8() {}

// TUnk_804E1BB0's vtable stays a data table. CW emits the vtable of the TU's
// last key function ahead of create_object_by_type's jump table and every
// other one after it, and the original has both 1BB0 and 1CA8 ahead of the
// table: only one of them can be the compiler's (TUnk_804E1CA8's is).
extern "C" void *__dt__13TUnk_804E1BB0Fv(void *arg0, s16 arg1);
extern "C" void run_task__5TItemFv();
extern "C" void render__5TItemFv();
extern "C" void render_shadows__5TItemFv();
extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void reset_motion_fields__14TObjCollidableFv();
extern "C" void get_center__11TItemWeaponFv();
extern "C" int update_object_view_visibility__5TItemFff(void *p);
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void get_name__5TItemFv();
extern "C" void interact__5TItemFUs();
extern "C" void update_owned__11TItemWeaponFv();
extern "C" void update_in_inventory__5TItemFv();
extern "C" void update_equipped__11TItemWeaponFv();
extern "C" void activate_effect__11TItemWeaponFl();
extern "C" void write_item_data__11TItemWeaponFP9TItemData();
extern "C" void set_attach_slot__14TItemEquipBaseFSc();
extern "C" void equip__14TItemEquipBaseFv();
extern "C" void unequip__14TItemEquipBaseFv();
extern "C" void add_equip_stats__14TItemEquipBaseFl();
extern "C" void remove_equip_stats__14TItemEquipBaseFl();
extern "C" void subtract_item_stat_bonus__14TItemEquipBaseFllPs();
extern "C" void subtract_equip_stats__14TItemEquipBaseFPvPsPs();
extern "C" void render_equipped__11TItemWeaponFv();
extern "C" void render_equipped_shadow__11TItemWeaponFv();
extern "C" void render_equipped_deferred__11TItemWeaponFv();
extern "C" void destroy__14TItemEquipBaseFv();
extern "C" void perform_action__11TItemWeaponFv();
extern "C" void use__5TItemFv();
extern "C" void get_attack_flags__11TItemWeaponFv();
extern "C" s8 get_attach_slot__14TItemEquipBaseFv(TItemEquipBase *arg0);
extern "C" void refresh_special__11TItemWeaponFv();
extern "C" void is_identified__11TItemWeaponFv();
extern "C" int get_amount__5TItemFv(void);
extern "C" int remove_amount__5TItemFl(void);
extern "C" int add_amount__5TItemFl(void);
extern "C" int get_slot_count__5TItemFv(void);
extern "C" void add_slot__5TItemFv();
extern "C" int feed__5TItemFP9TItemData(void);
extern "C" void snap_to_owner__5TItemFv();
extern "C" u8 get_motion_type__11TItemWeaponFv(void *p);
extern "C" void on_equip__11TItemWeaponFv();
extern "C" void on_unequip__11TItemWeaponFv();
extern "C" void request_equipped_model__11TItemWeaponFv();
extern "C" void release_model__11TItemWeaponFv();
extern "C" void apply_owner_bonuses__11TItemWeaponFv();
extern "C" void remove_owner_bonuses__11TItemWeaponFv();
extern "C" void on_model_loaded__11TItemWeaponFv();
extern "C" void launch_shot__11TItemWeaponFPUclll();
extern "C" void emit_marker_effects__11TItemWeaponFv();
extern "C" void update_attack__11TItemWeaponFv();
extern "C" void update_idle__11TItemWeaponFv();
extern "C" void reserved_53__13TUnk_804E1BB0Fv(s32 arg0);
extern "C" void update_weapon__11TItemWeaponFv();
extern "C" void on_equipped__11TItemWeaponFv();
extern "C" void on_unequipped__11TItemWeaponFv();
extern "C" void init_weapon_effect_descriptor__11TItemWeaponFP13Desc_8011E5C4();
extern "C" void vfunc_60__11TItemWeaponFv();
extern "C" void deliver_hit__11TItemWeaponFP10TObjPlayerP9TObjCharalfl();
void *lbl_804E1BB0[62] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__13TUnk_804E1BB0Fv, (void *)&run_task__5TItemFv,
    (void *)&render__5TItemFv, (void *)&render_shadows__5TItemFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__14TObjCollidableFv, (void *)&get_center__11TItemWeaponFv, (void *)&update_object_view_visibility__5TItemFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__5TItemFv, (void *)&interact__5TItemFUs, (void *)&update_owned__11TItemWeaponFv, (void *)&update_in_inventory__5TItemFv,
    (void *)&update_equipped__11TItemWeaponFv, (void *)&activate_effect__11TItemWeaponFl, (void *)&write_item_data__11TItemWeaponFP9TItemData, (void *)&set_attach_slot__14TItemEquipBaseFSc,
    (void *)&equip__14TItemEquipBaseFv, (void *)&unequip__14TItemEquipBaseFv, (void *)&add_equip_stats__14TItemEquipBaseFl, (void *)&remove_equip_stats__14TItemEquipBaseFl,
    (void *)&subtract_item_stat_bonus__14TItemEquipBaseFllPs, (void *)&subtract_equip_stats__14TItemEquipBaseFPvPsPs, (void *)&render_equipped__11TItemWeaponFv, (void *)&render_equipped_shadow__11TItemWeaponFv,
    (void *)&render_equipped_deferred__11TItemWeaponFv, (void *)&destroy__14TItemEquipBaseFv, (void *)&perform_action__11TItemWeaponFv, (void *)&use__5TItemFv,
    (void *)&get_attack_flags__11TItemWeaponFv, (void *)&get_attach_slot__14TItemEquipBaseFv, (void *)&refresh_special__11TItemWeaponFv, (void *)&is_identified__11TItemWeaponFv,
    (void *)&get_amount__5TItemFv, (void *)&remove_amount__5TItemFl, (void *)&add_amount__5TItemFl, (void *)&get_slot_count__5TItemFv,
    (void *)&add_slot__5TItemFv, (void *)&feed__5TItemFP9TItemData, (void *)&snap_to_owner__5TItemFv, (void *)&get_motion_type__11TItemWeaponFv,
    (void *)&on_equip__11TItemWeaponFv, (void *)&on_unequip__11TItemWeaponFv, (void *)&request_equipped_model__11TItemWeaponFv, (void *)&release_model__11TItemWeaponFv,
    (void *)&apply_owner_bonuses__11TItemWeaponFv, (void *)&remove_owner_bonuses__11TItemWeaponFv, (void *)&on_model_loaded__11TItemWeaponFv, (void *)&launch_shot__11TItemWeaponFPUclll,
    (void *)&emit_marker_effects__11TItemWeaponFv, (void *)&update_attack__11TItemWeaponFv, (void *)&update_idle__11TItemWeaponFv, (void *)&reserved_53__13TUnk_804E1BB0Fv,
    (void *)&update_weapon__11TItemWeaponFv, (void *)&on_equipped__11TItemWeaponFv, (void *)&on_unequipped__11TItemWeaponFv, (void *)&init_weapon_effect_descriptor__11TItemWeaponFP13Desc_8011E5C4,
    (void *)&vfunc_60__11TItemWeaponFv, (void *)&deliver_hit__11TItemWeaponFP10TObjPlayerP9TObjCharalfl,
};

void *__dt__13TUnk_804E1BB0Fv(void *item, s16 arg1) {
    if (item != NULL) {
        *(void ***)((s8 *)item + 0x18) = lbl_804E1BB0;
        __dt__11TItemWeaponFv(item, 0);
        if (arg1 > 0) {
            TItem::operator delete(item);
        }
    }
    return item;
}

TItem *TUnk_804E1BB0::create(u8 *item) {
    if (item != NULL) {
        TUnk_804E1BB0 *weapon = (TUnk_804E1BB0 *)TItem::operator new(0x1F8);
        if (weapon != NULL) {
            weapon = (TUnk_804E1BB0 *)weapon->init_state_513(tl_05, item);
        }
        return weapon;
    }
    return NULL;
}

void *TUnk_804E1BB0::init_state_513(TObject *parent, u8 *item) {
    __ct__11TItemWeaponFP7TObjectPUc((TItemWeapon *)this, parent, item);
    *(void ***)((s8 *)this + 0x18) = lbl_804E1BB0;
    set_weapon_flags(513);
    return this;
}

void TUnk_804E1BB0::reserved_53() {
    u32 second_model;
    u32 temp_r31;
    saddr arg0 = (saddr)this;
    draw_weapon_at_joint(arg0, 0x30);
    ((TItemWeapon *)arg0)->update_trail_slot(0);
    second_model = (uaddr)((TItemWeapon *)arg0)->second_model;
    temp_r31 = *(u32 *)((s8 *)arg0 + 0xF4);
    if (second_model != 0U) {
        *(u32 *)((s8 *)arg0 + 0xF4) = second_model;
    }
    draw_weapon_at_joint(arg0, 0x23);
    ((TItemWeapon *)arg0)->update_trail_slot(1);
    *(u32 *)((s8 *)arg0 + 0xF4) = temp_r31;
}
