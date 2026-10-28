#include "pso/misc/TLobby_801E43E4.h"
#include "types.h"
#include "pso/system/byteswap.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjChara.h"
#include "pso/misc/TOAttackableCol.h"
#include "pso/TObject.h"
#include "pso/misc/TOBarrierEnergy01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TLobby.h"

void set_floor_switch_flag(u32 id, s16 floor);

struct RecoveredGlobal_80157AD8_lbl_804AF9A8 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_80157AD8___vt__15TOAttackableCol {
    s32 value;
    u8 remaining[0x138];
};

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
void *__nw__7TObjectFUl(int);
void *fn_80157CA8(void *arg0);
void TOAttackableCol__sub_80157310(void *_w0);
u8 is_current_floor_switch_set(int);
volatile int is_locally_controlled__10TObjPlayerFPv(void *);
u16 get_entity_id(void *);
void *spawn_particle_effect(void *pos, s32 id);
u8 *__ct__12TQuestThreadFv(u8 *arg0, s32 arg1, s32 arg2);
extern u32 quest_mission_manager;
extern u32 quest_area_manager;
extern s32 tl_00;
extern const f32 lbl_805DB2C8;
s32 __ct__9TObjCharaFP7TObject(void *, int);
s32 obj_setFlags30(void *, int);
s32 init_collision_body_parts(void *, void *, int);
extern RecoveredGlobal_80157AD8_lbl_804AF9A8 TOAttackableCol__collision_parts;
extern s32 __vt__15TOAttackableCol[];
extern s32 lbl_805D2E98;
extern s32 tl_05;
extern const f32 lbl_805DB2CC;
extern const f32 lbl_805DB2D0;
u8 *TOAttackableCol__ct(u8 *arg0, s32 arg1);
s32 get_current_floor(void);
void TOAttackableCol__sub_80157C20(void* p, s32 v);
s32 TOAttackableCol__sub_80157C28(void* p);
void *__dt__15TOAttackableColFv(void *arg0, s16 arg1);
s32 free_collision_body_parts(void *);
s32 submit_cursor_candidate(void *, s32);
s32 __dl__7TObjectFPv(void *);
int bswap_header__6TLobbyFv(void*);
int clear_player_status_flag__14TObjCollidableFlUl(void*, int, int);
void queue_destruction__7TObjectFv(void *arg0);
void *find_entity_by_id(u16 id);
s32 check_value_equals__13TUnk_804B6C24Fl(void *, s32);
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
    this->m_344 = (s32) *(s32 *)&this->set_params[2];
    if ((s32) this->m_344 < 0) {
        this->m_344 = 0;
    }
    this->m_34c = (s32) this->scale.x;
    temp_r0_2 = this->m_34c;
    if ((temp_r0_2 < 0) || (temp_r0_2 >= 0x100)) {
        this->m_34c = -1;
    }
    if (this->scale.y < lbl_805DB2C8) {
        set_indexed_flags(0, 0x08000000);
    } else {
        clear_player_status_flag__14TObjCollidableFlUl(this, 0, 0x08000000);
    }
    if ((s32) this->m_344 == 0) {
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
                if (check_value_equals__13TUnk_804B6C24Fl(col, lbl_805D2E98) != 0) {
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

int TOAttackableCol::send_state_change(u16 state) {
    Obj_801575AC *self = (Obj_801575AC *)this;
    Msg_801575AC msg;
    s16 id;
    u8 *parent;
    id = this->mode;
    ((TObjCollidable *)self)->access_object_saved_state(&id, 0);
    parent = *(u8 * *)&this->set_entry;
    if (parent != NULL) {
        fn_80157CA8(&msg);
        msg.room = this->entity_id;
        msg.id = id;
        msg.type = *(s16 *)(parent + 4);
        msg.state = state;
        msg.f0E = this->m_33c;
        if (this->m_344 == 0 && self->f348 >= 0 && state == 1) {
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
    s16 sp8;
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
    sp8 = this->mode;
    ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 0);
}

int TOAttackableCol::handle_6x91_update_state() { return clear_player_status_flag__14TObjCollidableFlUl(this, 0, 1); }

f32 TOAttackableCol::apply_hit(s32 arg1) {
    u8 *arg0 = (u8 *)this;
  s32 temp_r0;
  s32 temp_r0_2;
  s32 var_r30;
  u32 temp_r3;
  u32 temp_r3_2;
  u32 var_r0;
  u32 var_r0_2;
  var_r30 = 0;
  if (((arg1 != 0) && (get_entity_id((void *) arg1) < 4U)) && (is_locally_controlled__10TObjPlayerFPv((void *) arg1) != 0))
  {
    var_r30 = 1;
  }
  if (var_r30 != 0)
  {
    temp_r0 = this->m_34c;
    if (((temp_r0 >= 0) && (temp_r0 < 0x100)) && (is_current_floor_switch_set((int) ((u16) temp_r0)) == 0))
    {
      return lbl_805DB2C8;
    }
    this->m_33c = (s32) ((this->m_33c) - 1);
    if (((s32)this->m_33c) <= 0)
    {
      this->m_33c = 0;
      send_state_change((u16)(1));
      if ((this->m_344) > 0)
      {
        temp_r0_2 = *((s32 *) (((s8 *) arg0) + 0x340));
        if ((((temp_r0_2 >= 0x64) && (temp_r0_2 < 0x3E8)) && (((u32) quest_mission_manager) != 0U)) && (((TObject *)quest_mission_manager)->all_parents_unqueued_for_destruction() != 0))
        {
          temp_r3 = ((u32)__nw__7TObjectFUl(0x194));
          var_r0 = temp_r3;
          if (var_r0 != 0U)
          {
            var_r0 = (u32)__ct__12TQuestThreadFv((u8 *)temp_r3, quest_mission_manager, this->m_344);
          }
          if (var_r0 != 0U)
          {
            ((TObject *)var_r0)->set_parent((TObject *)tl_00);
          }
        }
        else
          if ((((u32) quest_area_manager) != 0U) && (((TObject *)quest_area_manager)->all_parents_unqueued_for_destruction() != 0))
        {
          temp_r3_2 = ((u32)__nw__7TObjectFUl(0x194));
          var_r0_2 = temp_r3_2;
          if (var_r0_2 != 0U)
          {
            var_r0_2 = (u32)__ct__12TQuestThreadFv((u8 *)temp_r3_2, quest_area_manager, this->m_344);
          }
          if (var_r0_2 != 0U)
          {
            ((TObject *)var_r0_2)->set_parent((TObject *)tl_00);
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
  spawn_particle_effect(((u8 *)&this->position), 0x1D0);
  spawn_particle_effect(((u8 *)&this->position), 1);
  return lbl_805DB2C8;
}

void TOAttackableCol::release() { set_flag8(); queue_destruction__7TObjectFv(this); }
void TOAttackableCol::check_door_trigger() {
    s32 temp_r0;
    s32 temp_r0_2;

    temp_r0 = this->m_34c;
    if (((temp_r0 < 0) || (temp_r0 >= 0x100) || (is_current_floor_switch_set((u16) temp_r0) == 1)) && ((submit_cursor_candidate(this, -1), (((s32) *(s32 *)&this->m_33c > 0) == 0)) || (((s32) this->m_344 == 0) && (temp_r0_2 = *(s32 *)&this->unk_348, ((temp_r0_2 < 0) == 0)) && (temp_r0_2 < 0x100) && (is_current_floor_switch_set((u16) temp_r0_2) == 1)))) {
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
    o = __nw__7TObjectFUl(0x350);
    if (o != NULL) {
        o = TOAttackableCol__ct((u8 *)o, (s32)arg0);
    }
    return o;
}

void *__dt__15TOAttackableColFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TOAttackableCol;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TObjChara *)arg0)->destroy_motion_object(0);
        if ((s16) arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80157AD8_lbl_804AF9A8_size[sizeof(RecoveredGlobal_80157AD8_lbl_804AF9A8) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_80157AD8___vt__15TOAttackableCol_size[sizeof(RecoveredGlobal_80157AD8___vt__15TOAttackableCol) == 0x13C ? 1 : -1];
u8 *TOAttackableCol__ct(u8 *arg0, s32 arg1) {
    __ct__9TObjCharaFP7TObject(arg0, tl_05);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80157AD8___vt__15TOAttackableCol *)&__vt__15TOAttackableCol).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D2E98;
    ((TOAttackableCol *)(arg0))->apply_object_set_data((void *)arg1);
    ((TObjChara *)arg0)->calc_attach_pos();
    obj_setFlags30(arg0, 0x60000000);
    init_collision_body_parts(arg0, &TOAttackableCol__collision_parts.value, 1);
    ((TObjCollidable *)arg0)->set_indexed_flags(0, 0x718);
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TOAttackableCol *)arg0)->mode = 0;
    *(f32 *)((s8 *)arg0 + 0x334) = (f32) lbl_805DB2CC;
    ((TOAttackableCol *)arg0)->m_338 = (f32) lbl_805DB2D0;
    ((TOAttackableCol *)arg0)->init_params();
    return arg0;
}

s32 TOAttackableCol::try_start_action(s32, s32) { return 1; }

s32 TOAttackableCol::roll_physical_accuracy(void *, s32, f32) { return 1; }

s32 TOAttackableCol::select_melee_contact_body(void *, f32) { return 1; }

int TOAttackableCol::calc_distance_accuracy_penalty(void *, void *, void *, float) { return 1; }

f32 TOAttackableCol::receive_physical_attack(void *_w1, f32) { return this->apply_hit((s32)_w1); }

f32 TOAttackableCol::receive_direct_attack(void *_w1, DirectAttackPayload, void *, s32, s32) { return this->apply_hit((s32)_w1); }

f32 TOAttackableCol::receive_weapon_special_attack(void *_w1, void *) { return this->apply_hit((s32)_w1); }

void TOAttackableCol::apply_knockback_from_attacker(u8 *) {  }

void TOAttackableCol__sub_80157C20(void* p, s32 v) { *(s32*)((char*)p + 0x33c) = v; }
s32 TOAttackableCol__sub_80157C28(void* p) { return *(s32*)((char*)p + 0x33c); }
void TOAttackableCol::bswap_state() { bswap_header__6TLobbyFv(this); bswap_16((u16 *)((char*)this + 0xc)); bswap_16((u16 *)((char*)this + 0xe)); bswap_16((u16 *)((char*)this + 0x10)); }
void TOAttackableCol::broadcast_state() { bswap_state(); send_subcommand((u8 *)this); }

void *fn_80157CA8(void *barrier_energy01) {
    ((TOBarrierEnergy01 *)barrier_energy01)->init();
    *(u16 *)((s8 *)barrier_energy01 + 0xC) = 0;
    *(u16 *)((s8 *)barrier_energy01 + 0xE) = 0;
    *(u8 *)((s8 *)barrier_energy01 + 0x0) = 145;
    *(u8 *)((s8 *)barrier_energy01 + 0x1) = 5;
    return barrier_energy01;
}

}
