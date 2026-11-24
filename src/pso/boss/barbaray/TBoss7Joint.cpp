#include "types.h"
#include <stddef.h>
#include "pso/boss/barbaray/TBoss7Joint.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/system/SoundEffect.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/TLobby.h"
#include "pso/boss/dragon/TBoss1DragonColli.h"
#include "pso/system/vector.h"
#include "pso/boss/barbaray/TBoss7DeRolLeC.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/barbaray/TBoss7JointBreakUp.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/hud/TRaderMapCore.h"


extern const f32 lbl_805DE9F0;


int TBoss7Joint::is_part_active() { return part_flags & 0x1; }

void TBoss7Joint::init_boss_stats() {
    part_flags = part_flags | 1;
    reload_stats_keep_hp_tp(TLobby::register_boss(0x10), TLobby::dispatch_shared_handler_b(0xF), TLobby::register_object(0x10));
    hp = 0x4E20;
    hpmax = 0x4E20;
    new TBoss7JointBreakUp(this, &position, index);
    play_sound_effect(0x3A312, &position, 0, 0);
}

void TBoss7Joint::enable_body_collision() {
    if (bodies->flags & 6) {
        TObjEneDD::enable_body_collision();
        return;
    }
    TObjEneDD::disable_body_collision();
}

void TBoss7Joint::update_body_colliders() {
    f32 y = position.y;
    if (y < (lbl_805DE9F0 - 50.0f)) {
        bodies->flags &= ~7;
    } else if (y >= 30.0f) {
        bodies->flags |= 5;
        bodies->flags &= ~2;
    } else {
        bodies->flags |= 3;
        bodies->flags &= ~4;
    }
    transform_part_positions();
}

// The joint's one collision body (init_params copies it), then its class name.
extern const CollisionBody boss7_joint_collision_body_desc = { { 0.0f, 0.0f, 0.0f }, 50.0f, 0.0f, 0, 0x8003 };
const char *TBoss7Joint__name = "TBoss7Joint";

void TBoss7Joint::store_position() {
    VecCopy(&body_center, &position);
    VecCopy(&center, &body_center);
}

void TBoss7Joint::run_hit_reaction() {
    s32 damage = hpmax - hp;
    if (is_part_active() != 0U) {
        TBoss7DeRolLeC::spawn_offset_particle(&position, 15.0f, 12.0f);
        static_cast<TBoss7DeRolLeC *>(m_up)->apply_damage_and_set_effect(damage, attacker_id);
    } else {
        shell_hp -= damage;
        if (shell_hp <= 0) {
            shell_hp = 0;
            init_boss_stats();
        }
    }
    hp = (s16)hpmax;
    static_cast<TBoss7DeRolLeC *>(m_up)->set_flag_800();
    clear_attack_receipts();
}

void TBoss7Joint::run_task() {
    if (TObjPlayer::check_demo_mode() == 0) {
        VecCopy(&position, source_position);
        update_status_effects();
        store_position();
        update_body_colliders();
        if (bodies->flags & 1) {
            submit_default_cursor_candidate();
            add_radar_scaled_marker(&position, -0x5DB4, 1, 1, 1.2f);
        }
    }
}

TBoss7Joint::~TBoss7Joint() {
    clear_collision_bodies();
}

// The table init_params hands to TObjEneDD at +0x350; only its first word (225.0) is a float.
struct Boss7JointParams {
    f32 pad_0;
    s32 pad_4;
    s32 pad_8;
    s32 pad_C[4];
};
Boss7JointParams boss7_joint_params = { 225.0f, 0, 0x600 };

#pragma opt_common_subs off
s32 TBoss7Joint::init_params() {
    init_position_vectors();
    copy_collision_body(&collision_body, &boss7_joint_collision_body_desc);
    set_collision_body(&collision_body);
    transform_part_positions();
    reset_hp(TLobby::register_boss(0x10), TLobby::dispatch_shared_handler_b(0xF), TLobby::register_object(0x10));
    hp = 0x4E20;
    hpmax = 0x4E20;
    set_state_flag_2();
    movementParameters = &boss7_joint_params;
    referenceHp = hpmax;
    wall_reach = 3.0f;
    clear_intangible();
    part_flags = 0;
    return shell_hp = TBoss7Joint_get_shell_max_hp();
}

TBoss7Joint::TBoss7Joint(TObject *parent, u16 id, s16 set_index, Vec *position, s32 index) : TObjEneDD(parent) {
    m_name = TBoss7Joint__name;
    init_common_from(static_cast<TObjBase *>(parent));
    entity_id = id;
    this->set_index = set_index;
    source_position = position;
    this->index = index;
    initialize_enemy_state(0x49);
    init_params();
}

void TBoss7Joint::dispatch_action(u32, s32) {  }
void TBoss7Joint::refresh_target() {  }

void TBoss7Joint::run_death_reaction() { this->actorFlags &= 0xfffff7ff; }

void TBoss7Joint::run_miss_reaction() {  }
void TBoss7Joint::apply_poison_status() {  }
void TBoss7Joint::apply_paralysis() {  }
void TBoss7Joint::apply_slow_status() {  }
void TBoss7Joint::apply_confusion_status() {  }
void TBoss7Joint::apply_movement_ailment(s32) {  }
void TBoss7Joint::apply_shock_status() {  }
void TBoss7Joint::clear_harmful_statuses() {  }
