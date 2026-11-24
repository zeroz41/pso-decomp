#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TUnk_804C8678.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/object/collision/TOAttackableCol.h"
#include "types.h"
#include "pso/system/byteswap.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/system/task/TObject.h"
#include "pso/object/fence/TOBarrierEnergy01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestThread.h"
#include "pso/player/TObjPlayer_801AF2F0.h"


#include "pso/system/task/TMainTask.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"


#pragma readonly_strings on

CollisionBody TOAttackableCol__collision_parts = {{0.0f, 0.0f, 0.0f}, 5.0f, 0.0f, 0, 0x38003, {0.0f, 0.0f, 0.0f}, 0.0f};
const char *TOAttackableCol__name = "TOAttackableCol";

void set_floor_switch_flag(u32 id, s16 floor);


struct Msg_801575AC {
    u16 cmd;
    u16 room;
    s32 id;
    s32 type;
    u16 state;
    u16 f0E;
    u16 f10;
    u8 flag;
    s8 player;
};

struct SetEntry_80157454 { s16 id; s16 value; };

struct Obj_801575AC {
    u8 pad0[0x1C];
    u16 room;
    u8 pad1E[0x80 - 0x1E];
    u8 *parent;
    u8 pad84[0x326 - 0x84];
    s16 id;
    u8 pad328[0x33C - 0x328];
    s32 f33C;
    s32 f340;
    s32 f344;
    s32 f348;
};

extern "C" {
void *init_6x91_subcommand(void *barrier_energy01);
void TOAttackableCol__sub_80157310(void *_w0);
s32 init_collision_body_parts(void *, void *, int);
s32 get_current_floor(void);
void TOAttackableCol__sub_80157C20(void* p, s32 v);
s32 TOAttackableCol__sub_80157C28(void* p);
s32 free_collision_body_parts(void *);
extern SetEntry_80157454 *quest_object_entries;

void TOAttackableCol__sub_80157310(void * _w0) {  }

void TOAttackableCol::init_params() {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;

    *(s32 *)&this->m_33c = (this->set_params[0] + 1);
    temp_r0 = *(s32 *)&this->m_33c;
    if (temp_r0 < 1) {
        *(s32 *)&this->m_33c = 1;
    } else if (temp_r0 > 0x100) {
        *(s32 *)&this->m_33c = 0x100;
    }
    *(s32 *)&this->unk_340 = (s32) *(s32 *)&this->set_params[1];
    if ((s32) *(s32 *)&this->unk_340 < 0) {
        *(s32 *)&this->unk_340 = 0;
    }
    this->label = (s32) *(s32 *)&this->set_params[2];
    if ((s32) this->label < 0) {
        this->label = 0;
    }
    this->m_34c = (s32) this->scale.x;
    temp_r0_2 = this->m_34c;
    if ((temp_r0_2 < 0) || (temp_r0_2 >= 0x100)) {
        this->m_34c = -1;
    }
    if (this->scale.y < 0.0f) {
        set_indexed_flags(0, 0x08000000);
    } else {
        clear_player_status_flag(0, 0x08000000);
    }
    if ((s32) this->label == 0) {
        *(s32 *)&this->unk_348 = (s32) this->scale.z;
        temp_r0_3 = *(s32 *)&this->unk_348;
        if ((temp_r0_3 < 0) || (temp_r0_3 >= 0x100)) {
            *(s32 *)&this->unk_348 = -1;
        }
    } else {
        *(s32 *)&this->unk_348 = -1;
    }
}

void handle_6x91_update_attackable_col_state(Msg_801575AC *msg) {
    TOAttackableCol *col;
    s32 mode;

    if (msg != NULL) {
        ((TOAttackableCol *)msg)->bswap_state();
        if (msg->room != 0xFFFF && msg->room >= 0x4000) {
            col = (TOAttackableCol *)find_entity_by_id(msg->room);
            if (col != NULL) {
                if (reinterpret_cast<TObject *>(col)->check_value_equals(TOAttackableCol__name) != 0) {
                    SetEntry_80157454 saved;
                    switch (msg->state) {
                    case 0:
                        mode = col->mode;
                        if (mode != 1) {
                            if ((mode >= 1) || (mode < 0)) {
                                col->mode = 0;
                            }
                            if (msg->f0E < TOAttackableCol__sub_80157C28(col)) {
                                TOAttackableCol__sub_80157C20(col, msg->f0E);
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
                    saved.id = col->mode;
                    col->vfunc_6(&saved.id, 0);
                }
            } else {
                SetEntry_80157454 entry = quest_object_entries[msg->type];
                entry.id = msg->id;
                TLobby::apply_table_entry(msg->type, &entry);
            }
            if (msg->flag == 1 && msg->f10 < 0x100 && msg->player < 18) {
                set_floor_switch_flag(msg->f10, msg->player);
            }
        }
    }
}

void TOAttackableCol::send_state_change(u16 state) {
    Obj_801575AC *self = (Obj_801575AC *)this;
    Msg_801575AC msg;
    s16 id;
    u8 *parent;
    id = this->mode;
    ((TObjCollidable *)self)->access_object_saved_state(&id, 0);
    parent = *(u8 * *)&this->set_entry;
    if (parent != NULL) {
        init_6x91_subcommand(&msg);
        msg.room = this->entity_id;
        msg.id = id;
        msg.type = *(s16 *)(parent + 4);
        msg.state = state;
        msg.f0E = this->m_33c;
        if (this->label == 0 && self->f348 >= 0 && state == 1) {
            msg.f10 = self->f348;
            msg.flag = 1;
        } else {
            msg.flag = 0;
            msg.f10 = 0;
        }
        msg.player = get_current_floor();
        ((TOAttackableCol *)(&msg))->broadcast_state();
    }
}

void TOAttackableCol::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    s16 mode;
    s32 temp_r0;
    if (arg1 != NULL) {
        this->mode = (s16) *arg1;
    }
    temp_r0 = this->mode;
    if (temp_r0 != 1) {
        if ((temp_r0 >= 1) || (temp_r0 < 0)) {
            this->mode = 0;
        }
    } else {
        this->m_33c = 0;
        if (arg2 != 0) {
            ((TOAttackableCol *)arg0)->handle_6x91_update_state();
        }
    }
    mode = this->mode;
    ((TObjCollidable *)arg0)->access_object_saved_state(&mode, 0);
}

void TOAttackableCol::handle_6x91_update_state() { clear_player_status_flag(0, 1); }

f32 TOAttackableCol::apply_hit(saddr player) {
    u8 *arg0 = (u8 *)this;
  s32 id;
  s32 temp_r0_2;
  s32 var_r30;
  u32 temp_r3;
  u32 temp_r3_2;
  uaddr var_r0;
  uaddr var_r0_2;
  var_r30 = 0;
  if (((player != 0) && (((TObjBase *)player)->get_entity_id() < 4U)) && (TObjPlayer::is_locally_controlled((void *) player) != 0))
  {
    var_r30 = 1;
  }
  if (var_r30 != 0)
  {
    id = this->m_34c;
    if (((id >= 0) && (id < 0x100)) && (is_current_floor_switch_set(((u16) id)) == 0))
    {
      return 0.0f;
    }
    this->m_33c = (s32) ((this->m_33c) - 1);
    if (((s32)this->m_33c) <= 0)
    {
      this->m_33c = 0;
      send_state_change((u16)(1));
      if ((this->label) > 0)
      {
        temp_r0_2 = *((s32 *) (((s8 *) arg0) + 0x340));
        if ((((temp_r0_2 >= 0x64) && (temp_r0_2 < 0x3E8)) && ((quest_mission_manager) != 0U)) && (quest_mission_manager->all_parents_unqueued_for_destruction() != 0))
        {
          var_r0 = (uaddr)new TQuestThread(quest_mission_manager, this->label);
          if (var_r0 != 0U)
          {
            ((TObject *)var_r0)->set_parent(tl_00);
          }
        }
        else
          if (((quest_area_manager) != 0U) && (quest_area_manager->all_parents_unqueued_for_destruction() != 0))
        {
          var_r0_2 = (uaddr)new TQuestThread(quest_area_manager, this->label);
          if (var_r0_2 != 0U)
          {
            ((TObject *)var_r0_2)->set_parent(tl_00);
          }
        }
      }
    }
    else
    {
      send_state_change((u16)(0));
    }
    goto block_26;
  }
  block_26:
  spawn_particle_effect(&this->position, 0x1D0);
  spawn_particle_effect(&this->position, 1);
  return 0.0f;
}

void TOAttackableCol::release() { set_flag8(); queue_destruction(); }
void TOAttackableCol::check_door_trigger() {
    s32 temp_r0;
    s32 temp_r0_2;

    temp_r0 = this->m_34c;
    if (((temp_r0 < 0) || (temp_r0 >= 0x100) || (is_current_floor_switch_set((u16) temp_r0) == 1)) && ((submit_cursor_candidate(this, -1), (((s32) *(s32 *)&this->m_33c > 0) == 0)) || (((s32) this->label == 0) && (temp_r0_2 = *(s32 *)&this->unk_348, ((temp_r0_2 < 0) == 0)) && (temp_r0_2 < 0x100) && (is_current_floor_switch_set((u16) temp_r0_2) == 1)))) {
        this->m_33c = 0;
        send_state_change((u16)(1));
    }
}

void TOAttackableCol::run_task() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() == 1) {
        TOAttackableCol__sub_80157310((arg0));
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

void *TOAttackableCol::create(void *arg0) {
    void *o;
    o = (void *)new TOAttackableCol((saddr)arg0);
    return o;
}

}
TOAttackableCol::~TOAttackableCol() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}


TOAttackableCol::TOAttackableCol(saddr set_data) : TObjChara(tl_05) {
    ((TObject *)this)->m_name = TOAttackableCol__name;
    ((TOAttackableCol *)(((u8 *)this)))->apply_object_set_data((void *)set_data);
    ((TObjChara *)this)->calc_attach_pos();
    set_actor_flags(0x60000000);
    init_collision_body_parts(((u8 *)this), &TOAttackableCol__collision_parts, 1);
    ((TObjCollidable *)this)->set_indexed_flags(0, 0x718);
    ((TObjPlayer *)this)->register_object_by_id();
    this->mode = 0;
    *(f32 *)((s8 *)this + 0x334) = 500.0f;
    this->m_338 = 50.0f;
    this->init_params();
}

s32 TOAttackableCol::try_start_action(s32, s32) { return 1; }

s32 TOAttackableCol::roll_physical_accuracy(void *, s32, f32) { return 1; }

s32 TOAttackableCol::select_melee_contact_body(void *, f32) { return 1; }

int TOAttackableCol::calc_distance_accuracy_penalty(void *, void *, void *, float) { return 1; }

f32 TOAttackableCol::receive_physical_attack(void *player, f32) { return this->apply_hit((saddr)player); }

f32 TOAttackableCol::receive_direct_attack(void *player, DirectAttackPayload, void *, s32, s32) { return this->apply_hit((saddr)player); }

f32 TOAttackableCol::receive_weapon_special_attack(void *player, void *) { return this->apply_hit((saddr)player); }

void TOAttackableCol::apply_knockback_from_attacker(u8 *, f32) {  }

void TOAttackableCol__sub_80157C20(void* p, s32 v) { *(s32*)((char*)p + 0x33c) = v; }
s32 TOAttackableCol__sub_80157C28(void* p) { return *(s32*)((char*)p + 0x33c); }
void TOAttackableCol::bswap_state() { ((TLobby *)this)->bswap_header(); bswap_16((u16 *)((char*)this + 0xc)); bswap_16((u16 *)((char*)this + 0xe)); bswap_16((u16 *)((char*)this + 0x10)); }
void TOAttackableCol::broadcast_state() { bswap_state(); send_subcommand((u8 *)this); }

void *init_6x91_subcommand(void *barrier_energy01) {
    init_collision_subcommand_header(barrier_energy01);
    *(u16 *)((s8 *)barrier_energy01 + 0xC) = 0;
    *(u16 *)((s8 *)barrier_energy01 + 0xE) = 0;
    *(u8 *)((s8 *)barrier_energy01 + 0x0) = 145;
    *(u8 *)((s8 *)barrier_energy01 + 0x1) = 5;
    return barrier_energy01;
}

