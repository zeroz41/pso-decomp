#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TQuestManager.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/network/TGameProtocol.h"
#include "pso/object/collision/TOAttackableCol.h"
#include "pso/map/FloorPopulation.h"
#include "types.h"
#include "pso/system/byteswap.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/system/task/TObject.h"
#include "pso/object/fence/TOBarrierEnergy01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/TLobby.h"
#include "pso/quest/TQuestThread.h"
#include "pso/player/PlayerCommands.h"


#include "pso/system/task/TMainTask.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/network/protocol/SubcommandHandlers.h"
#include "pso/object/base/TObjCollidable.h"
#include "pso/quest/QuestFloorDesignation.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/base/ActorCollision.h"


#pragma readonly_strings on

CollisionBody attackable_col_collision_parts = {{0.0f, 0.0f, 0.0f}, 5.0f, 0.0f, 0, 0x38003, {0.0f, 0.0f, 0.0f}, 0.0f};
const char *attackable_col_name = "TOAttackableCol";





// Inferred: run_demo_task (run_task calls it in demo mode).
void TOAttackableCol::run_task_stub() {  }

void TOAttackableCol::init_params() {
    s32 hits;
    s32 switch_value;
    s32 done_value;

    this->hits_left = (this->set_params[0] + 1);
    hits = this->hits_left;
    if (hits < 1) {
        this->hits_left = 1;
    } else if (hits > 0x100) {
        this->hits_left = 0x100;
    }
    this->script_kind = (s32) this->set_params[1];
    if ((s32) this->script_kind < 0) {
        this->script_kind = 0;
    }
    this->label = (s32) this->set_params[2];
    if ((s32) this->label < 0) {
        this->label = 0;
    }
    this->required_switch = (s32) this->scale.x;
    switch_value = this->required_switch;
    if ((switch_value < 0) || (switch_value >= 0x100)) {
        this->required_switch = -1;
    }
    if (this->scale.y < 0.0f) {
        set_indexed_flags(0, 0x08000000);
    } else {
        clear_player_status_flag(0, 0x08000000);
    }
    if ((s32) this->label == 0) {
        this->done_switch = (s32) this->scale.z;
        done_value = this->done_switch;
        if ((done_value < 0) || (done_value >= 0x100)) {
            this->done_switch = -1;
        }
    } else {
        this->done_switch = -1;
    }
}

void handle_6x91_update_attackable_col_state(G_UpdateAttackableColState_6x91 *command) {
    TOAttackableCol *col;
    s32 mode;

    if (command != NULL) {
        command->bswap();
        if (command->header.entity_id != 0xFFFF && command->header.entity_id >= 0x4000) {
            col = (TOAttackableCol *)find_entity_by_id(command->header.entity_id);
            if (col != NULL) {
                if (col->check_value_equals(attackable_col_name) != 0) {
                    QuestObjectEntry saved;
                    switch (command->is_destroyed) {
                    case 0:
                        mode = col->mode;
                        if (mode != 1) {
                            if ((mode >= 1) || (mode < 0)) {
                                col->mode = 0;
                            }
                            if (command->remaining_hits < col->get_hits_left()) {
                                col->set_hits_left(command->remaining_hits);
                            }
                        }
                        break;
                    case 1:
                        if (col->mode != 1) {
                            col->mode = 1;
                            col->handle_6x91_update_state();
                        }
                        break;
                    }
                    saved.flags = col->mode;
                    col->apply_saved_state(&saved.flags, 0);
                }
            } else {
                QuestObjectEntry entry = quest_object_entries[command->object_index];
                entry.flags = command->flags;
                set_quest_object_entry(command->object_index, &entry);
            }
            if (command->should_set == 1 && command->switch_flag_num < 0x100 && command->floor < 18) {
                set_floor_switch_flag(command->switch_flag_num, command->floor);
            }
        }
    }
}

extern "C" {

void TOAttackableCol::send_state_change(u16 state) {
    G_UpdateAttackableColState_6x91 msg;
    s16 id;
    FloorObjectSetRow *parent;
    id = this->mode;
    access_object_saved_state(&id, 0);
    parent = (FloorObjectSetRow *)this->set_entry;
    if (parent != NULL) {
        init_6x91_subcommand(&msg);
        msg.header.entity_id = this->entity_id;
        msg.flags = id;
        msg.object_index = parent->placement.set_index;
        msg.is_destroyed = state;
        msg.remaining_hits = this->hits_left;
        if (this->label == 0 && this->done_switch >= 0 && state == 1) {
            msg.switch_flag_num = this->done_switch;
            msg.should_set = 1;
        } else {
            msg.should_set = 0;
            msg.switch_flag_num = 0;
        }
        msg.floor = get_current_floor();
        msg.send();
    }
}

void TOAttackableCol::apply_saved_state(s16 *state, s32 live) {
    s16 mode;
    s32 mode_value;
    if (state != NULL) {
        this->mode = (s16) *state;
    }
    mode_value = this->mode;
    if (mode_value != 1) {
        if ((mode_value >= 1) || (mode_value < 0)) {
            this->mode = 0;
        }
    } else {
        this->hits_left = 0;
        if (live != 0) {
            handle_6x91_update_state();
        }
    }
    mode = this->mode;
    access_object_saved_state(&mode, 0);
}

void TOAttackableCol::handle_6x91_update_state() { clear_player_status_flag(0, 1); }

f32 TOAttackableCol::apply_hit(TObjBase *player) {
  s32 id;
  s32 kind;
  s32 is_local_player;
  u32 unused1;
  u32 unused2;
  TObject *thread_a;
  TObject *thread_b;
  is_local_player = 0;
  if (((player != 0) && (player->get_entity_id() < 4U)) && (((TObjChara *)player)->is_locally_controlled() != 0))
  {
    is_local_player = 1;
  }
  if (is_local_player != 0)
  {
    id = this->required_switch;
    if (((id >= 0) && (id < 0x100)) && (is_current_floor_switch_set(((u16) id)) == 0))
    {
      return 0.0f;
    }
    this->hits_left = (s32) ((this->hits_left) - 1);
    if (((s32)this->hits_left) <= 0)
    {
      this->hits_left = 0;
      send_state_change((u16)(1));
      if ((this->label) > 0)
      {
        kind = script_kind;
        if ((((kind >= 0x64) && (kind < 0x3E8)) && ((quest_mission_manager) != 0U)) && (quest_mission_manager->all_parents_unqueued_for_destruction() != 0))
        {
          thread_a = new TQuestThread(quest_mission_manager, this->label);
          if (thread_a != 0U)
          {
            thread_a->set_parent(tl_00);
          }
        }
        else
          if (((quest_area_manager) != 0U) && (quest_area_manager->all_parents_unqueued_for_destruction() != 0))
        {
          thread_b = new TQuestThread(quest_area_manager, this->label);
          if (thread_b != 0U)
          {
            thread_b->set_parent(tl_00);
          }
        }
      }
    }
    else
    {
      send_state_change((u16)(0));
    }
  }
  spawn_particle_effect(&this->position, 0x1D0);
  spawn_particle_effect(&this->position, 1);
  return 0.0f;
}

void TOAttackableCol::release() { set_flag8(); queue_destruction(); }
void TOAttackableCol::check_door_trigger() {
    s32 required;
    s32 done_switch;

    required = this->required_switch;
    if (((required < 0) || (required >= 0x100) || (is_current_floor_switch_set((u16) required) == 1)) && ((submit_cursor_candidate(this, -1), (((s32) this->hits_left > 0) == 0)) || (((s32) this->label == 0) && (done_switch = this->done_switch, ((done_switch < 0) == 0)) && (done_switch < 0x100) && (is_current_floor_switch_set((u16) done_switch) == 1)))) {
        this->hits_left = 0;
        send_state_change((u16)(1));
    }
}

void TOAttackableCol::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        run_task_stub();
        return;
    }
    switch (this->mode) {
    default:
        this->mode = 0;
    case 0:
        check_door_trigger();
        return;
    case 1:
        release();
        return;
    }
}

void TOAttackableCol::render() {  }

void *TOAttackableCol::create(void *set_data) {
    void *o;
    o = new TOAttackableCol(set_data);
    return o;
}

}
TOAttackableCol::~TOAttackableCol() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}


TOAttackableCol::TOAttackableCol(void *set_data) : TObjChara(tl_05) {
    m_name = attackable_col_name;
    apply_object_set_data(set_data);
    calc_attach_pos();
    set_actor_flags(0x60000000);
    init_collision_body_parts(this, &attackable_col_collision_parts, 1);
    set_indexed_flags(0, 0x718);
    ((TObjPlayer *)this)->register_object_by_id();
    this->mode = 0;
    *(f32 *)((s8 *)this + 0x334) = 500.0f;
    this->m_338 = 50.0f;
    this->init_params();
}

s32 TOAttackableCol::try_start_action(TObjChara *, s32, f32) { return 1; }

s32 TOAttackableCol::roll_physical_accuracy(TObjChara *, s32, f32) { return 1; }

s32 TOAttackableCol::select_melee_contact_body(TObjChara *, f32) { return 1; }

int TOAttackableCol::calc_distance_accuracy_penalty(TObjChara *, CollisionBody *, const Vec *, float) { return 1; }

f32 TOAttackableCol::receive_physical_attack(TObjChara *player, f32) { return this->apply_hit(player); }

f32 TOAttackableCol::receive_direct_attack(TObjBase *player, DirectAttackPayload, CollisionBody *, s32, s32) { return this->apply_hit(player); }

f32 TOAttackableCol::receive_weapon_special_attack(TObjChara *player, CollisionBody *) { return this->apply_hit(player); }

void TOAttackableCol::apply_knockback_from_attacker(TObjBase *, f32) {  }

// Inferred: set_hits_left / get_hits_left.
void TOAttackableCol::set_hits_left(s32 v) { hits_left = v; }
s32 TOAttackableCol::get_hits_left() { return hits_left; }
void G_UpdateAttackableColState_6x91::bswap() {
    G_UpdateObjectState_6x0B::bswap();
    bswap_16(&is_destroyed);
    bswap_16(&remaining_hits);
    bswap_16(&switch_flag_num);
}
void G_UpdateAttackableColState_6x91::send() { bswap(); send_subcommand(this); }

G_UpdateAttackableColState_6x91 *init_6x91_subcommand(G_UpdateAttackableColState_6x91 *msg) {
    init_collision_subcommand_header(msg);
    msg->is_destroyed = 0;
    msg->remaining_hits = 0;
    msg->header.subcommand = 0x91;
    msg->header.size = 5;
    return msg;
}

