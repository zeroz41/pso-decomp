#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/trap/TOTrap.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"

struct Obj_80178CF8 {
    u8 pad[0x38];
    f32 pos[3];
    u8 pad44[0x84 - 0x44];
    s32 x84;
    u8 pad88[0x2A8 - 0x88];
    u8 *target;
    u8 pad2ac[0x326 - 0x2AC];
    s16 state;
    u8 pad328[0x334 - 0x328];
    f32 x334;
    f32 range;
    u16 idx;
};

struct Obj_80178E10 { u8 pad0[0x2A8]; u8 *target; u8 pad1[0x7A]; s16 state; u8 pad2[0xC]; f32 range; u8 pad3[4]; u16 idx; };

extern "C" {
s32 is_locally_controlled__10TObjPlayerFPv(int);
s32 get_entity_id(u32);

extern u32 trap_scale_factor_table[];
extern s32 game_difficulty_selection;
s32 fn_80171314(void *);
u16 find_nearest_visible_player(void *, int, f32);
s32 calc_attach_pos__9TObjCharaFv();
f32 horizontal_distance_squared(void *, void *);
struct Base_80178EF8_80178BC0 { char pad[0x18]; };
struct VObj_80178EF8_80178BC0 : Base_80178EF8_80178BC0 {
#define VM(n) virtual void m##n();
    VM(0)VM(1)VM(2)VM(3)VM(4)VM(5)VM(6)VM(7)VM(8)VM(9)
    VM(10)VM(11)VM(12)VM(13)VM(14)VM(15)VM(16)VM(17)VM(18)VM(19)
    VM(20)VM(21)VM(22)VM(23)VM(24)VM(25)VM(26)VM(27)VM(28)VM(29)
    VM(30)VM(31)VM(32)VM(33)VM(34)VM(35)VM(36)VM(37)VM(38)VM(39)
    VM(40)VM(41)VM(42)VM(43)VM(44)VM(45)VM(46)VM(47)VM(48)VM(49)
    VM(50)VM(51)VM(52)VM(53)VM(54)VM(55)VM(56)VM(57)VM(58)VM(59)
    VM(60)VM(61)VM(62)VM(63)VM(64)VM(65)VM(66)VM(67)VM(68)VM(69)
    VM(70)VM(71)VM(72)VM(73)VM(74)VM(75)VM(76)VM(77)VM(78)VM(79)
    VM(80)VM(81)VM(82)
    virtual void m83();
#undef VM
};

f32 TOTrap::scale_by_table_value(f32 farg0) {
    u32 v[4];
    v[0] = trap_scale_factor_table[0];
    v[1] = trap_scale_factor_table[1];
    v[2] = trap_scale_factor_table[2];
    v[3] = trap_scale_factor_table[3];
    return farg0 * ((f32*)v)[game_difficulty_selection];
}

void TOTrap::vfunc_89() {  }

s32 TOTrap::is_any_player_matching_stat() {
    s32 i;
    void *p;
    for (i = 0; i < 4; i++) {
        p = ((void *)get_player_by_client_id(i));
        if (p != 0) {
            if (((s16)((TObjBase *)p)->get_room() == (s16)get_room()) && (fn_80171314(p) != 0)) {
                return 1;
            }
        }
    }
    return 0;
}

void TOTrap::vfunc_82() {
    s32 temp_r31;

    calc_attach_pos();
    refresh_collision_body_centers();
    if ((s32) this->set_params[0] < 0) {
        u32 p;
        this->receive_physical_attack(this->target, 1.0f);
        p = *(u32 *)&this->target;
        if (p != 0U) {
            u32 v = (u16) get_entity_id(p);
            if (v < 0x1000U) {
                temp_r31 = (s32)get_player_by_client_id(v);
                if ((is_locally_controlled__10TObjPlayerFPv(temp_r31) != 0) && (((TLobby *)temp_r31)->check_player_flag1() != 0)) {
                    TObjPlayer::send_code_45_1(temp_r31);
                }
            }
        }
    }
    submit_cursor_candidate(this, -1);
}

void TOTrap::vfunc_81() {
    u8 *pl;
    Obj_80178CF8 *self = (Obj_80178CF8 *)this;
    calc_attach_pos__9TObjCharaFv();
    this->player = find_nearest_visible_player(self, 0, this->range);
    if (this->player != 0xFFFF) {
        pl = (u8 *)get_player_by_client_id(this->player);
        this->target = pl;
        if (this->target != 0) {
            if (horizontal_distance_squared(this->target + 0x38, self->pos) < this->dist * this->dist) {
                this->mode = 3;
                if (is_locally_controlled__10TObjPlayerFPv((int)pl) != 0) {
                    ((void (*)(f32, void *, void *, s32, int))send_6x2C_impose_hold)(this->dist, pl, self->pos, this->set_params[0], 0);
                }
            } else {
                this->player = 0xFFFF;
                this->target = 0;
            }
        }
    } else {
        this->target = 0;
    }
}

void TOTrap::submit_cursor_and_notify() {
    u8 *arg0 = (u8 *)this;
    submit_cursor_candidate(arg0, -1);
    this->find_target_player();
}

void TOTrap::find_target_player() {
    Obj_80178E10 *arg0 = (Obj_80178E10 *)this;
    calc_attach_pos();
    this->player = find_nearest_visible_player(arg0, 0, this->range);
    if (this->player != (u16)0xFFFF) {
        this->target = (u8 *)get_player_by_client_id(this->player);
        if (this->target != 0) {
            if (horizontal_distance_squared(this->target + 0x38, (u8 *)arg0 + 0x38) < this->range * this->range) {
                this->mode = 2;
            }
        } else {
            this->player = 0xFFFF;
            this->target = 0;
        }
    } else {
        this->target = 0;
    }
}

void TOTrap::play_sounds() {
    s32 arg0 = (s32)this;
    spawn_particle_effect((void *)(arg0 + 0x2FC), 0x45);
    spawn_particle_effect((void *)(arg0 + 0x2FC), 0x46);
}

void TOTrap::vfunc_6(s16 *arg1, s32 arg2) {
    if ((s16) *arg1 == 4) {
        if (arg2 == 1) {
            ((VObj_80178EF8_80178BC0 *)this)->m83();
        }
        set_flag8();
        queue_destruction__7TObjectFv(this);
    }
}

f32 TOTrap::receive_physical_attack(void *arg1, f32) {
  s16 sp8;
  s32 temp_r3_2;
  u16 temp_r3;
  if ((((this->entity_id) >= 0x4000U) && (((u32) (*((u32 *) (((s8 *) ((u8 *)this)) + 0x80)))) != 0U)) && (access_object_saved_state(&sp8, 1) != 0))
  {
    this->mode = 4;
    sp8 = this->mode;
    access_object_saved_state(&sp8, 0);
    send_object_state_update(&sp8);
    if (arg1 != 0U)
    {
      temp_r3 = get_entity_id((u32)((void *) arg1));
      if (temp_r3 < 0x1000U)
      {
        temp_r3_2 = (s32)get_player_by_client_id(((int) ((s32) temp_r3)));
        if (((temp_r3_2 != 0) && (is_locally_controlled__10TObjPlayerFPv((int)((int) temp_r3_2)) != 0)) && (((TLobby *)((long long) temp_r3_2))->check_player_flag1() != 0))
        {
          TObjPlayer::send_code_45_1((s32)((int) temp_r3_2));
        }
      }
    }
  }
  return 0.0f;
}

void TOTrap::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        this->vfunc_88();
        return;
    }
    if (TObjPlayer::is_any_teammate_in_state() == 0) {
        this->vfunc_84();
        switch (this->mode) {
        case 0:
            if (this->is_any_player_matching_stat() != 0) {
                this->mode = 1;
            }
            this->find_target_player();
            return;
        case 1:
            this->submit_cursor_and_notify();
            return;
        case 2:
            this->vfunc_81();
            return;
        case 3:
            this->vfunc_82();
            break;
        }
    }
}

}

#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/object/trap/TOTrap.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 post_translate_matrix(void *);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();

struct TOTrapBase { char pad[0x18]; };
struct TOTrapVObj : TOTrapBase {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};
#pragma explicit_unused_unused_members on
void TOTrap::render() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::is_any_teammate_in_state() == 0) {
        this->m_340 = ((TOTrapVObj*)arg0)->m8(4e+02f, 2e+01f);
        if (this->m_340 == 1) {
            push_matrix();
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            TObjFish::set_global_param(this->texlist);
            if (TObjPlayer::check_demo_mode() == 1) {
                draw_chunk_object(this->model);
            } else {
                draw_model_motion((void *)this->model, (void *)this->current_motion, this->frame);
            }
            pop_matrix();
        }
    }
}

}


extern "C" {
extern const char *lbl_805D3198;
}

TOTrap::~TOTrap() {}

TOTrap::TOTrap(TObject *parent) : TObjChara(parent) {
    m_name = lbl_805D3198;
    range = dist = 0.0f;
    player = 0xFFFF;
    m_340 = 1;
}

void TOTrap::vfunc_84() {}

void TOTrap::vfunc_86() {}

void TOTrap::vfunc_88() {}
