#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/darkfalz/TBoss4Fade.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz_8004C93C.h"
#include "pso/object/ending/TObjOnlineEnding_802E4B80.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/system/vector.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/boss/darkfalz/TObjDFHorming.h"
#include "pso/enemy/TObjEnemy.h"
#include <stddef.h>
#include "pso/enemy/BattleParameters.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/boss/darkfalz/TBoss4Type1.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/PlayerSlots.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>


#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/boss/darkfalz/TBoss4Thanks_8035C8F0.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/object/TObjControl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby_8030A834.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixVector.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/darkfalz/TBoss4Type3_800524E8.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on

// One arena zone of the fight (push_players_out_of_zone): players farther than radius from the center of
// the zone being entered who stand inside another zone land at landing, spread from it along their offset
// from that zone's center.
struct DarkFalzPushZone { Vec center; f32 radius; Vec landing; f32 spread; };

const char *darkfalz_dat_model_names[] = {
    "df_event_tower.nj",
    "df_rikomiraju_body.nj",
    "df1_anzen.nj",
    "df1_s_body.nj",
    "df1_s_da_heada.nj",
    "df1_s_db_heada.nj",
    "df1_s_dc_heada.nj",
    "df1_s_dodai.nj",
    "df1_s_simobe.nj",
    "df1_s_waist.nj",
    "df2_s_body.nj",
    "df2_s_dodai1.nj",
    "df3_s_body.nj",
    "df3_s_wing.nj",
    "df3_sl_body.nj",
    "df3_sl_wing.nj",
    "fd_obj813_face.nj",
    "fd_obj813_flower01.nj",
    "rico_ring3_rico_ring.nj",
    NULL,
};

const char *darkfalz_dat_motion_names[] = {
    "beaml_df1_s_body.njm",
    "beaml_df1_s_root.njm",
    "beaml_df2_s_body.njm",
    "beaml_df2_s_dodai1.njm",
    "beamr_df1_s_body.njm",
    "beamr_df1_s_root.njm",
    "beamr_df2_s_body.njm",
    "beamr_df2_s_dodai1.njm",
    "damage_df1_s_body.njm",
    "damage_df1_s_da_heada.njm",
    "damage_df1_s_dodai.njm",
    "damage_df1_s_root.njm",
    "damage_df2_s_body.njm",
    "damage_df2_s_dodai1.njm",
    "damage_df3_s_body.njm",
    "damage_df3_s_wing.njm",
    "damage_df3_s1_wing.njm",
    "dead_df2_s_body.njm",
    "dead_df2_s_dodai1.njm",
    "dead_df3_s_body.njm",
    "dead1_df1_s_body.njm",
    "dead1_df1_s_da_heada.njm",
    "dead1_df1_s_root.njm",
    "df_rikomiraju_body.njm",
    "df1op_df1_s_body.njm",
    "df1op_df1_s_da_heada.njm",
    "df2op_df1_s_body.njm",
    "df2op_df1_s_da_heada.njm",
    "df2op_df2_s_body.njm",
    "df2op_df2_s_dodai1.njm",
    "df3_op_df2_s_body.njm",
    "df3_op_df2_s_dodai1.njm",
    "df3_op_df3_s_body.njm",
    "df3_op_df3_s_wing.njm",
    "df3_op_df3_s1_wing.njm",
    "df3dead_df_rikomiraju_body.njm",
    "df3dead_df3_s_body.njm",
    "dwntec_df3_s_body.njm",
    "fd_obj813_face.njm",
    "fd_obj813_flower01.njm",
    "haki_df1_s_da_heada.njm",
    "haki_df1_s_root.njm",
    "hakiin_df1_s_da_heada.njm",
    "hakiin_df1_s_root.njm",
    "hakiout_df1_s_da_heada.njm",
    "hakiout_df1_s_root.njm",
    "hoe_df1_s_body.njm",
    "hoe_df1_s_da_heada.njm",
    "hoe_df2_s_body.njm",
    "hoe_df2_s_dodai1.njm",
    "jisin_df2_s_body.njm",
    "jisin_df2_s_dodai1.njm",
    "jyousyou_df3_s_body.njm",
    "jyousyou_df3_s_wing.njm",
    "jyousyou_df3_s1_wing.njm",
    "kakou_df3_s_body.njm",
    "kakou_df3_s_wing.njm",
    "kakou_df3_s1_wing.njm",
    "laser_df3_s_body.njm",
    "laser_df3_s_wing.njm",
    "laser_df3_s1_wing.njm",
    "lhassya_df1_s_body.njm",
    "lhassya_df2_s_body.njm",
    "lhassya_df2_s_dodai1.njm",
    "lkiri_df3_s_body.njm",
    "lkiri_df3_s_wing.njm",
    "lkiri_df3_s1_wing.njm",
    "ltame_df1_s_body.njm",
    "ltame_df2_s_body.njm",
    "rico_ring3_rico_ring.njm",
    "ricoult1_df_rikomiraju_body.njm",
    "ricoult2_df_rikomiraju_body.njm",
    "rkiri_df3_s_body.njm",
    "rkiri_df3_s_wing.njm",
    "rkiri_df3_s1_wing.njm",
    "uptec_df3_s_body.njm",
    "wait_df1_s_body.njm",
    "wait_df1_s_da_heada.njm",
    "wait_df1_s_dodai.njm",
    "wait_df1_s_root.njm",
    "wait_df1_s_waist.njm",
    "wait_df2_s_body.njm",
    "wait_df2_s_dodai1.njm",
    "wait_df3_s_body.njm",
    "wait_df3_s_wing.njm",
    "wait_df3_s1_wing.njm",
    "wing_df2_s_body.njm",
    "wing_df2_s_dodai1.njm",
    "wing_wing_root.njm",
    "yubi_df3_s_body.njm",
    NULL,
};

BmlResourceDescriptor darkfalz_dat_resource_descriptor = {
    "darkfalz_dat.bml", darkfalz_dat_model_names, darkfalz_dat_motion_names, 19, 90,
};

const char *TBoss4DarkFalz__name = "TBoss4DarkFalz";

// Read-only start positions (.rodata) of sub_8004B8F8 and sub_8004B7DC. Declared const, the visible
// definition lets CodeWarrior hoist the copy above the stmw in both users, so they are placed explicitly.
__declspec(section ".rodata") Vec dark_falz_player_ring_center_origin = { 0.0f, 10.0f, 0.0f };
__declspec(section ".rodata") Vec dark_falz_player_ring_center = { 10000.0f, 10.0f, 0.0f };

Vec dark_falz_zako_ring_origin_vec = { 0.0f, -13.0f, 0.0f };

DarkFalzPushZone dark_falz_push_zone_table[3] = {
    { { -10000.0f, 0.0f, 0.0f }, 750.0f, { -10000.0f, 0.0f, 200.0f }, 50.0f },
    { { 0.0f, 0.0f, 0.0f }, 750.0f, { 0.0f, 0.0f, 0.0f }, 50.0f },
    { { 10000.0f, 0.0f, 0.0f }, 750.0f, { 10000.0f, 0.0f, 0.0f }, 200.0f },
};


extern "C" {
s32 subtract_vector(void *, void *);
f32 xyz_distance(void *, void *);

void TBoss4DarkFalz::push_players_out_of_zone(s32 zone) {
    Vec v;
    DarkFalzPushZone *entered;
    Vec *landing;
    s32 i;
    TObjPlayer *player;
    s32 j;
    CollisionBody *body;
    DarkFalzPushZone *other;
    f32 radius;
    f32 spread;
    f32 other_radius;
    entered = &dark_falz_push_zone_table[zone];
    radius = dark_falz_push_zone_table[zone].radius;
    spread = dark_falz_push_zone_table[zone].spread;
    landing = &dark_falz_push_zone_table[zone].landing;
    for (i = registered_player_count + registered_enemy_count; i < lbl_805D5868; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player == NULL) continue;
        body = player->bodies;
        if (body == NULL || !(body->flags & 0x20000)) continue;
        if (xyz_distance(entered, &player->position) <= radius) continue;
        for (j = 0; j < 3; j++) {
            other = &dark_falz_push_zone_table[j];
            other_radius = dark_falz_push_zone_table[j].radius;
            if (j != zone && !(xyz_distance(&player->position, other) > other_radius)) {
                VecCopy(&v, &player->position);
                subtract_vector(&v, other);
                v.y = 0.0f;
                if (vector_length(&v) <= 0.01f) {
                    v.x = 0.0f;
                    v.z = 1.0f;
                } else {
                    normalize_vector(&v);
                }
                break;
            }
        }
        if (j != 3) {
            v.x = v.x * spread;
            v.z = v.z * spread;
            v.y = 7.5f;
            vec3_add_to(&v, landing);
            VecCopy(&player->position, &v);
            player->refresh_collision_body_centers();
        }
    }
}


s32 TObjDFHorming::is_boss_active() {
    int active;

    active = 0;
    if (TBoss4DarkFalz::get_type3_instance() != NULL) {
        if (TBoss4DarkFalz::get_type3_instance()->get_action_state() != 3) {
            if (TBoss4DarkFalz::get_type3_instance()->get_action_state() != 2) {
                active = 1;
            }
        }
    }
    return (u8)active;
}

s32 TBoss4DarkFalz::is_state_ready() {
    int ready;

    ready = 0;
    if (get_type2_instance() != NULL) {
        if (get_type2_instance()->get_phase() != 3) {
            if (get_type2_instance()->get_phase() != 2) {
                ready = 1;
            }
        }
    }
    return (u8)ready;
}

s32 TBoss4DarkFalz::is_active() {
    int active;

    active = 0;
    if (TBoss4DarkFalz::get_instance() != NULL) {
        if (TBoss4DarkFalz::get_instance()->get_state() != 3) {
            if (TBoss4DarkFalz::get_instance()->get_state() != 4) {
                active = 1;
            }
        }
    }
    return (u8)active;
}
u16 TBoss4Type3::pick_random_target_player() {
    u16 buf[4];
    s32 n;
    s32 i;
    TObjPlayer *p;
    n = 0;
    for (i = 0; i < registered_player_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != NULL && is_player_in_boss_area(p->get_entity_id()) != 0) {
            buf[n++] = p->get_entity_id();
            if (n >= 4) {
                break;
            }
        }
    }
    if (n == 0) {
        return (u16)(0xFFFF);
    }
    return (u16)(buf[(s32)(((f32)n - 0.01f) * (3.0517578e-05f * (f32)rand()))]);
}

}

TBoss4DarkFalzSetEntry dark_falz_set_entry;

extern "C" {
extern s32 local_client_id;

void release_all_players_control_lock(void);
}

extern "C" {
s32 is_local_client_floor_leader();
s32 get_main_phase();

s32 TBoss4DarkFalz::alloc_child_ids(s16 *set_index_out, s16 *entity_id_out) {
    s32 n = next_child_index;
    if ((n < 1) || (n > 0x1FE)) {
        return 0;
    }
    if (n > 0x1FD) {
        return 0;
    }
    *set_index_out = set_index + n;
    *entity_id_out = entity_id + next_child_index;
    next_child_index = next_child_index + 1;
    return 1;
}

void TBoss4DarkFalz::reset_child_ids() { this->next_child_index = 1; }

s32 TBoss4DarkFalz::count_active_players() {
    s32 count = 0;
    s32 i;
    for (i = 0; i < registered_player_count; i++) {
        if (TObjPlayer::get_player_data(i) != 0) {
            count++;
        }
    }
    if (count == 0 || count > 4) {
        return 1;
    }
    return count;
}

int TBoss4DarkFalz::is_ending_or_split_screen() {
    u8 result;

    result = 0;
    if ((get_main_phase() == 0xF) || (is_split_screen() != 0)) {
        result = 1;
    }
    return result;
}
s32 TBoss4DarkFalz::sub_8004B07C() { return 0; }

void TBoss4DarkFalz::run_state_update() {
    TBoss4DarkFalzHandler action = dark_falz_state_table[state_index].update;
    if (action != 0) {
        (this->*action)();
    }
}

void TBoss4DarkFalz::run_state_leader_update() {
    TBoss4DarkFalzHandler action = dark_falz_state_table[state_index].update_leader;
    if (action != 0) {
        (this->*action)();
    }
}

void TBoss4DarkFalz::send_code_25_4(s32 arg) {
    G_DarkFalzActions_6x19 cmd;
    cmd.init();
    cmd.header.client_id = entity_id;
    cmd.state = -1;
    cmd.form_action = arg;
    cmd.send();
}

void TBoss4DarkFalz::send_action_packet(s32 arg) {
    G_DarkFalzActions_6x19 cmd;
    cmd.init();
    cmd.header.client_id = entity_id;
    cmd.state = arg;
    cmd.form_action = -1;
    cmd.send();
}

void TBoss4DarkFalz::change_state(s32 state) {
    if (state < 0 || state >= 16) {
        return;
    }
    if (state_index != -1) {
        TBoss4DarkFalzHandler action = dark_falz_state_table[state_index].leave;
        if (action != 0) {
            (this->*action)();
        }
    }
    state_index = state;
    TBoss4DarkFalzHandler action = dark_falz_state_table[state_index].enter;
    if (action != 0) {
        (this->*action)();
    }
}

void TBoss4DarkFalz::update_visible_flag() {
    if (is_local_client_floor_leader() != 0) {
        this->not_floor_leader = 0;
        return;
    }
    this->not_floor_leader = 1;
}

s32 TBoss4DarkFalz::calc_rate_from_field() {
    s32 count = active_player_count;
    if (count > 0) {
        return 0x10000 / count;
    }
    return 0;
}

s32 TBoss4DarkFalz::is_timer_expired() {
    s32 losses_per_player;

    losses_per_player = TLobby::dispatch_shared_handler_a(0x35)->values.integers[0];
    if ((losses_per_player < 1) || (losses_per_player > 0x13)) {
        losses_per_player = 2;
    }
    if (this->minions_lost >= (s32) (losses_per_player * this->active_player_count)) {
        return 1;
    }
    return 0;
}

#pragma fp_contract on
void TBoss4DarkFalz::spawn_zako_rings() {
    TBoss4ZakoSetData p;
    f32 r;
    f32 dr;
    s32 j;
    s32 n;
    s32 ang;
    s32 step;
    s32 i;
    p.owner = this;
    r = 28.571428f;
    dr = 57.142857f;
    copy_set_entry(&p.set_index, &dark_falz_set_entry);
    p.unk_0C = 1;
    if (game_difficulty_selection == 3) {
        r *= 1.25f;
        dr *= 1.25f;
    }
    for (j = 0; j < 4; j++) {
        n = (j * 2 + 1) * 5;
        ang = 0;
        step = 0x10000 / n;
        for (i = 0; i < n; i++) {
            if (alloc_child_ids(&p.set_index, &p.entity_id) == 0) {
                return;
            }
            VecCopy(&p.position, &dark_falz_zako_ring_origin_vec);
            p.position.x += r * sin_table_lookup(ang);
            p.position.z += r * cos_table_lookup(ang);
            TBoss4Zako::create(&p);
            ang += step;
        }
        r += dr;
    }
}

/* The 0x40-byte set entry as copy_set_entry copies it: position, rotation and the parameter
 * block as blocks, the rest field by field. */
struct SetEntryWords3 { u32 w[3]; };
struct SetEntryWords5 { u32 w[5]; };
struct SetEntryCopy {
  s16 set_index;
  s16 kind;
  s16 unknown_04;
  u16 entity_id;
  s16 room;
  s16 wave;
  s16 unknown_0C;
  s16 unknown_0E;
  struct SetEntryWords3 position;
  struct SetEntryWords3 rotation;
  struct SetEntryWords5 params;
  s16 param_3C;
  s16 param_3E;
};

#pragma push
#pragma cplusplus off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void copy_set_entry(void *arg0p, void *arg1p) {
#define o ((struct SetEntryCopy *)arg0p)
#define s ((struct SetEntryCopy *)arg1p)
  struct SetEntryCopy *new_var;
  struct SetEntryCopy *new_var2;
  struct SetEntryWords5 *dc = &o->params;
  struct SetEntryWords5 *sc = &s->params;
  o->set_index = s->set_index;
  new_var2 = (new_var = o);
  new_var2->kind = s->kind;
  o->unknown_04 = s->unknown_04;
  new_var->entity_id = s->entity_id;
  o->room = s->room;
  o->wave = s->wave;
  new_var->unknown_0C = s->unknown_0C;
  o->unknown_0E = s->unknown_0E;
  new_var->position = s->position;
  o->rotation = s->rotation;
  *dc = *sc;
  new_var->param_3C = s->param_3C;
  o->param_3E = s->param_3E;
}
#undef o
#undef s
#pragma pop

void TBoss4DarkFalz::spawn_defeat_effects() {
    Vec v;
    TObjPlayer *p;
    s32 i;
    f32 k;
    if (TBoss4Thanks__sub_8035C96C() != 0) {
        play_sound_effect(0x40033231, 0, 0, 0);
        k = 12.5f;
        for (i = 0; i < registered_player_count; i++) {
            p = TObjPlayer::get_player_data(i);
            if (p != 0 && p->get_area() == 0xE) {
                VecCopy(&v, &p->position);
                v.y += k;
                spawn_particle_effect(&v, 0x28);
            }
        }
    }
}

#pragma inline_depth(4)
#pragma dont_inline off
#pragma auto_inline on
void TBoss4DarkFalz::handle_defeat() {
    TObjPlayer *p;

    spawn_defeat_effects();
    if (is_split_screen() != 0) {
        distribute_experience();
    } else {
        p = get_player_by_client_id((u16)local_client_id);
        if (p != 0) {
            Vec save = body_center;
            VecCopy(&body_center, &p->body_center);
            distribute_experience();
            VecCopy(&body_center, &save);
        }
    }
    {
        s32 flags[3];
        flags[0] = 0x800;
        send_6x0A_enemy_state(flags);
        exchange_object_state(flags, 0);
        apply_enemy_state(flags);
    }
    send_entity_set_flags();
    queue_destruction();
}

void TBoss4DarkFalz::set_fade(s32 color, f32 alpha) {
    if (fade != NULL && !(alpha <= 0.0f)) {
        if (alpha > 1.0f) {
            alpha = 1.0f;
        }
        fade->set_fade(color, alpha);
    }
}
void TBoss4DarkFalz::refresh_player_equipment() {
    s32 i;
    TObjPlayer *p;
    for (i = 0; i < registered_player_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != 0) {
            if (p->get_area() == 0xE) {
                p->refresh_equipment_slot();
            }
        }
    }
}

#pragma fp_contract on
void TBoss4DarkFalz::place_players_on_ring() {
    Vec base = dark_falz_player_ring_center;
    s32 rate;
    s32 ang;
    s32 i;
    TObjPlayer *p;
    rate = calc_rate_from_field();
    ang = 0;
    for (i = 0; i < registered_player_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != NULL && p->get_area() == 0xE) {
            Vec v = base;
            v.x += 2.5e+02f * sin_table_lookup(ang);
            v.z += 2.5e+02f * cos_table_lookup(ang);
            p->set_position_from(&v);
            p->save_previous_position();
            p->get_rotation()->yaw = ang + 0x8000;
            p->refresh_equipment_slot();
            if (TObjPlayer::is_locally_controlled(p) != 0) {
                reset_cameras_to_actor(p, 0);
            }
            ang += rate;
        }
    }
}

#pragma fp_contract on
void TBoss4DarkFalz::place_players_for_demo() {
    Vec base = dark_falz_player_ring_center_origin;
    s32 rate;
    s32 ang;
    s32 i;
    TObjPlayer *p;
    rate = calc_rate_from_field();
    ang = rate / 2;
    for (i = 0; i < registered_player_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != NULL && p->get_area() == 0xE) {
            Vec v = base;
            v.x += 12.5f * sin_table_lookup(ang);
            v.z += 12.5f * cos_table_lookup(ang);
            p->set_position_from(&v);
            p->save_previous_position();
            p->get_rotation()->yaw = 0x8000;
            p->refresh_equipment_slot();
            if (TObjPlayer::is_locally_controlled(p) != 0) {
                reset_cameras_to_actor(p, 0);
            }
            ang += rate;
        }
    }
}

void TBoss4DarkFalz::end_player_camera_pans() {
    s32 i;
    void *p;
    TWindowCtrl::init_all_slots2();
    for (i = 0; i < registered_player_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != 0) {
            ((TObjPlayer *)p)->end_camera_pan();
        }
    }
    release_all_players_control_lock();
}
void TBoss4DarkFalz::freeze_all_players() {
    s32 i;
    void *p;
    TWindowCtrl::init_all_slots();
    for (i = 0; i < registered_player_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != 0) {
            ((TObjPlayer *)p)->start_freeze();
        }
    }
}
#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
void TBoss4DarkFalz::update_roar_sound_timer() {
    s32 state;
    s32 timer;
    state = this->state_index;
    if (state >= 9 || state < 4) {
        return;
    }
    {
        timer = this->roar_timer - 1;
        this->roar_timer = timer;
        if (timer < 0) {
            if ((3.0517578e-05f * (f32) rand()) < 0.5f) {
                play_sound_effect(0x3A300, 0, 0, 0);
            } else {
                play_sound_effect(0x3A801, 0, 0, 0);
            }
            {
                f32 r = 3.0517578e-05f * (f32) rand();
                this->roar_timer = (s32) ((3e+02f * r) + 3e+02f);
            }
        }
    }
}
}
#pragma pop

#pragma push
#pragma fp_contract on

#pragma pop

// back to the unit's -inline off defaults after TObjDFHorming's inline pragmas
#pragma dont_inline on
#pragma auto_inline off
#pragma fp_contract off


extern "C" {

void TBoss4DarkFalz::render() {  }

void TBoss4DarkFalz::run_task() {
    if ((state_index != 0) && (TObjPlayer::check_demo_mode() != 0)) {
        change_state(0);
    }
    if (TObjEneDD::query_teammate_state() == 0) {
        update_visible_flag();
        if (not_floor_leader == 0) {
            run_state_leader_update();
        }
        run_state_update();
        update_roar_sound_timer();
    }
}

void TBoss4DarkFalz::run_death_reaction() {  }
}
void init_music_sequencer(s32 program);
BmlResource *darkfalz_dat_resource;
TBoss4Type1 *TBoss4DarkFalz__type1_instance;
TBoss4Type2 *TBoss4DarkFalz__type2_instance;
TBoss4Type3 *TBoss4DarkFalz__type3_instance;
s32 dark_falz_form_index;
s32 boss4_type2_rafoie_level;
s32 boss4_type2_rabarta_level;
TBoss4DarkFalz *dark_falz_controller_instance;
TBoss4DarkFalz::~TBoss4DarkFalz() {
    TBoss4Fade *object;
    switch (state_index) {
    case 10:
    case 14:
    case 15:
        this->send_entity_set_flags();
        break;
    }
    end_player_camera_pans();
    restore_player_cameras();
    if (TBoss4DarkFalz::is_ending_or_split_screen() == 0) {
        TLobby::stop_audio_streams();
    }
    object = fade;
    if (object != NULL) {
        object->queue_destruction();
        fade = NULL;
    }
    if (TBoss4DarkFalz__type1_instance != NULL) {
        TBoss4DarkFalz__type1_instance->queue_destruction();
        TBoss4DarkFalz__type1_instance = NULL;
    }
    if (TBoss4DarkFalz__type2_instance != NULL) {
        TBoss4DarkFalz__type2_instance->queue_destruction();
        TBoss4DarkFalz__type2_instance = NULL;
    }
    if (TBoss4DarkFalz__type3_instance != NULL) {
        TBoss4DarkFalz__type3_instance->queue_destruction();
        TBoss4DarkFalz__type3_instance = NULL;
    }
    dark_falz_controller_instance = 0;
}


TBoss4DarkFalz::TBoss4DarkFalz(TObject *parent, TBoss4DarkFalzSetEntry *set_data) : TObjEnemy(parent) {
    m_name = TBoss4DarkFalz__name;
    reset_child_ids();
    if (set_data->kind != 0x200) {
        return;
    }
    dark_falz_controller_instance = this;
    apply_set_data(set_data);
    copy_set_entry(&dark_falz_set_entry, set_data);
    dark_falz_set_entry.kind = 0;
    clear_lobby_object_state();
    VecCopy(&prev_position, VecCopy(&home_position, VecCopy(&center, &position)));
    VecCopy(&body_center, &position);
    velocity.x = velocity.y = velocity.z = 0.0f;
    target = 0;
    if (game_difficulty_selection == 0) {
        bind_enemy_combat_stats(TLobby::register_boss(0x37), TLobby::dispatch_shared_handler_b(0x37), TLobby::register_object(0x37));
    } else {
        bind_enemy_combat_stats(TLobby::register_boss(0x38), TLobby::dispatch_shared_handler_b(0x38), TLobby::register_object(0x38));
    }
    register_entity_by_id(this);
    actorFlags |= 0x02000000;
    update_visible_flag();
    active_player_count = count_active_players();
    TBoss4DarkFalz__type1_instance = 0;
    TBoss4DarkFalz__type2_instance = 0;
    TBoss4DarkFalz__type3_instance = 0;
    intro_tower = NULL;
    fade = create_boss4_fade();
    minions_spawned = 0;
    minions_lost = 0;
    fn_8030A83C(this);
    init_music_sequencer(4);
    dark_falz_form_index = 0;
    roar_timer = 0;
    boss4_type2_rafoie_level = ((TBoss4Type2Params *)TLobby::dispatch_shared_handler_a(0x36))->rafoie_level;
    if (boss4_type2_rafoie_level < 0 || boss4_type2_rafoie_level > 0xE) {
        boss4_type2_rafoie_level = 0;
    }
    boss4_type2_rabarta_level = ((TBoss4Type2Params *)TLobby::dispatch_shared_handler_a(0x36))->rabarta_level;
    if (boss4_type2_rabarta_level < 0 || boss4_type2_rabarta_level > 0xE) {
        boss4_type2_rabarta_level = 0;
    }
    push_players_out_of_zone(0);
    state_index = -1;
    change_state(1);
}

void handle_6x19_dark_falz_actions(G_DarkFalzActions_6x19 *cmd) {
    TBoss4DarkFalz *boss;
    s32 arg;
    cmd->bswap();
    boss = (TBoss4DarkFalz *)get_enemy_entity(cmd->header.client_id);
    if (boss == NULL) {
        return;
    }
    if (cmd->state != -1 && cmd->state >= 0 && cmd->state < 16 &&
        cmd->state != boss->get_phase()) {
        boss->change_state(cmd->state);
    }
    arg = cmd->form_action;
    if (arg == -1) {
        return;
    }
    switch (boss->get_phase()) {
    case 5:
    case 6:
        if (TBoss4DarkFalz__type1_instance != NULL) {
            TBoss4DarkFalz__type1_instance->apply_packed_state(arg);
        }
        break;
    case 7:
    case 8:
    case 9:
        if (TBoss4DarkFalz__type2_instance != NULL) {
            TBoss4DarkFalz__type2_instance->apply_packed_state(arg);
        }
        break;
    case 12:
    case 13:
    case 14:
        if (TBoss4DarkFalz__type3_instance != NULL) {
            TBoss4DarkFalz__type3_instance->apply_packed_state(arg);
        }
        break;
    }
}

void TBoss4DarkFalz::cleanup_global() {
    TBoss4DarkFalz::free_global_instance();
    release_uro_link();
    delete darkfalz_dat_resource;
    darkfalz_dat_resource = NULL;
}

void TBoss4DarkFalz::load_resources() {
    BmlResource *resource = new BmlResource(5, &darkfalz_dat_resource_descriptor, 0, 0, NULL);
    darkfalz_dat_resource = resource;
    if (resource != NULL) {
        TBoss4DarkFalz::init_uro_link();
        fn_802E52AC();
    }
}

TBoss4DarkFalz *TBoss4DarkFalz::create(saddr set_data) {
    return new TBoss4DarkFalz(new TObjControl(tl_04), (TBoss4DarkFalzSetEntry *)set_data);
}

s32 TBoss4DarkFalz::get_phase() { return state_index; }

BmlResource *TBoss4Uro::get_instance_count() { return darkfalz_dat_resource; }
