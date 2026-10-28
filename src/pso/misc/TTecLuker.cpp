#include "pso/protocol/protocol_types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "types.h"
extern "C" void *__dt__13TUnk_804CC148Fv(void *, s16);
#include "pso/misc/TUnk_804CCA0C.h"
#include "pso/misc/TUnk_804CC990.h"
#include "pso/system/byteswap.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TTecLuker.h"
#include "pso/effect/TUnk_804CC148.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TUnk_804CC9D4.h"

struct BaseM_80234C90_80233B38 { char pad[0x24]; };
struct VM_80234C90_80233B38 : BaseM_80234C90_80233B38 { virtual void m0(int); };

struct Stack_802340E4 {
    s32 sp8;
    u16 spC;
    s16 spE;
    s32 sp10;
    s32 sp14;
    u8 pad_18[0x8];
    s32 sp20;
};

struct RecoveredGlobal_80233B9C_lbl_804CC990 { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_80233B9C_lbl_804CC990_size[sizeof(RecoveredGlobal_80233B9C_lbl_804CC990) == 0x18 ? 1 : -1];

struct RecoveredGlobal_80233D18_lbl_804CC9A8 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_80233D18_lbl_804CC9D4 {
    s32 value;
    u8 remaining[0x34];
};

#include "pso/effect/TechniqueChargeEmitter.h"
#include "pso/TItemList.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"

struct O_802340A0 { u16 h0; u16 h2; s32 w4; f32 f8; f32 fc; f32 f10; s32 w14; };

struct Vec_80233E78 { f32 x, y, z; };

struct Player_80233E78 { u8 pad[0x838]; Vec_80233E78 pipe_pos; s32 pipe_heading; u8 arrival[4]; };

struct Vec_8023402C { f32 x, y, z; };

struct Rec_8023402C { u16 owner; s16 floor; s32 section; Vec_8023402C pos; s32 heading; };

struct Vec_802347B4 { f32 x, y, z; };

struct Pipe_802347B4 {
    u8 pad[0x1c];
    u8 *player;
    u8 pad20[0xd0];
    void *collider;
    s16 floor;
    u16 traveller;
    void *visual;
    Vec_802347B4 pos;
    s32 phase;
};

struct Obj_8023448C {
    u8 pad0[0x18];
    void *vt;
    u32 kids[3];
    u32 f28;
};

struct Pkt_802341B0 { u8 hdr[4]; Rec_8023402C rec; };

struct Vec_80234D50 { f32 x, y, z; };

struct Owner_80234D50 {
    u8 pad0[0x38];
    Vec_80234D50 pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0x838 - 0x64];
    Vec_80234D50 pipe_pos;
};

struct Luker_80234D50 {
    s32 f0;
    u8 pad4[0x18 - 0x4];
    void *vt;
    Owner_80234D50 *owner;
    u8 pad20[0xB4 - 0x20];
    u16 owner_id;
    u8 padb6[0xEC - 0xB6];
    void *fx;
    s32 fF0;
    s16 fF4;
    u16 fF6;
    s32 fF8;
    Vec_80234D50 pos;
    s32 f108;
    s32 f10C;
};

struct Vec_802342A4
{
  f32 x;
  f32 y;
  f32 z;
};

struct Obj_802342A4
{
  u8 pad0[0x18];
  void *vt;
  u32 kids[3];
  void *f28;
  Vec_802342A4 pos;
};

struct V3_8023453C
{
  f32 x;
  f32 y;
  f32 z;
};

struct Hit_8023453C
{
  u8 pad[4];
  void *pos;
};

struct Fx_8023453C
{
  u8 pad0[0x18];
  void *vt;
  u32 kids[3];
  void *f28;
  V3_8023453C pos;
  V3_8023453C pos2;
};

struct P_802346F8 { s32 t; f32 v; };

struct VBase_802346F8 { char pad[0x18]; };

struct VObj_802346F8 : VBase_802346F8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual s32 m21(s32, P_802346F8, s32, s32, s32);
};

void clear_pipe_interaction_latch(void* p);
s32 get_pipe_interaction_latch(void* p);
extern "C" {
void TTecLuker__sub_8023503C(void* p);
void TTecLuker__sub_80235048(void* p);
int TTecLuker__sub_80235054(void* p);
int fn_80235078(void *arg0);
u32 get_player_by_client_id(s32);
s32 play_sound_effect(int, void *, int, int);
s32 __ct__7TObjectFP7TObject(void *, void *);
extern s32 recovery_technique_charge_vtable[];
u8 *construct_resta_charge_sound(u8 *arg0, s32 arg1, s32 arg2);
s32 obj_setFlags30(void *, int);
s32 init_collision_body_parts(void *, void *, int);
s32 __ct__13TUnk_804AF8A0FP7TObject(void *, void *);
extern RecoveredGlobal_80233D18_lbl_804CC9A8 telepipe_field_collision_body_template;
extern s32 telepipe_field_collider_vtable[];
bool TTecLuker__sub_8023401C(u8 *arg0);
extern u32 recovery_technique_charge_particle_ids[];
void* spawn_particle_effect(float*,u32);
s32 queue_destruction__7TObjectFv(void *);
void TTecLuker__updateRecoveryTechniqueCharge(TechniqueChargeEmitter* state);
extern u8 TTecLuker__visit_counts[4];
void reset_telepipe_visit_counts(void);
void TTecLuker__sub_80234F08(void);
extern const f32 lbl_805DC85C;
void reset_telepipe_record(O_802340A0 *o);
void TTecLuker__sub_80234F48(void);
s32 TObjPlayer__sub_801BFFA0(void *p);
void set_state__9TTecLukerFl(void *p, s32 v);
extern s32 telepipe_town_heading_table[];
extern Vec_80233E78 telepipe_town_position_table[];
extern Vec_80233E78 telepipe_town_position_table_b[];
Vec_80233E78 *consume_telepipe_arrival(u16 slot, s32 *heading);
s16 get_field_2__9TTecLukerFPv(void* p);
s32 get_current_floor(void);
void restore_floor_telepipes(void);
f32 vector_length(void *);
extern const f32 lbl_805DC860;
s32 telepipe_record_differs(Rec_8023402C *r, s16 floor, Vec_8023402C *p, u16 unused);
void *__nw__7TObjectFUl(int);
s32 obj_getField1c(void *);
s32 get_stat_by_key_state__13TUnk_804B9870Fv(void *);
extern s32 tl_07;
extern s32 tl_05;
void __dt__7TObjectFv(void *, int);
void __dl__7TObjectFPv(void *);
extern u8 lbl_804CCA0C[];
Obj_8023448C *__dt__13TUnk_804CCA0CFv(Obj_8023448C *arg0, s16 arg1);
s32 is_split_screen();
u8 *find_entity_by_id(u16);
extern s32 local_client_id;
void handle_6x68_set_telepipe_state(Pkt_802341B0 *pkt);
void *alloc__23TAdSinglePlyChrSelectGCFv(u32);
s32 construct_area_technique_base(void *, void *, void *);
s32 matrix_mult_vec(int, void *, void *);
s32 rotate_matrix_y(int, s32);
s32 push_matrix_from(void *);
s32 pop_matrices(int);
extern Vec_80234D50 lbl_8044D72C;
extern void* __vt__9TTecLuker[];
extern u8 identity_matrix[];
extern s32 lbl_805D37E4;
extern const f32 lbl_805DC878;
void *TTecLuker__ct(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
s32 mark_area_change_pending();
s32 obj_isState3_324__13TUnk_804806E8Fv(void *);
s32 play_effect_default__10TObjPlayerFii(void *, s32);
s32 send_6x21_inter_level_warp(void *, s32);
s32 get_floor_map_terrain(s32);
s32 play_persistent_sound(s32, void *, void *, s32, s32);
s32 set_area__6TLobbyFl(s32 *, s32, s32);
void run_task__9TTecLukerFv(u8 *arg0);
f32 horizontal_distance_squared(void *, void *);
extern s32 camera_ctrl_instance;
extern const f32 lbl_805DC864;
extern const f32 lbl_805DC868;
Hit_8023453C *csnVecterUnder(void *, s32);
u32 spawn_continuous_particle_effect_with_flags(void *, s32, s32);
}
void init_telepipe_packet_header(void* p);
void create_quest_telepipe_for_client(u16 arg0);
void write_telepipe_record(u8 *arg0, u16 arg1, s16 arg2, u8 *arg3, s32 arg4);
void start_placement_search(s32 arg0, s32 arg1, s32 arg2);
s32 are_players_gathered_near(void *arg0, s32 *arg1, f32 range);
void offset_point_toward_camera(u8 *arg0, u8 *arg1, f32 farg0);
extern s32 lbl_80515BA0[];
extern const f32 lbl_805DC858;
u8 *create_telepipe_marker(u8 *arg0, s32 arg1, s8 arg2, s8 arg3, s32 arg4, s32 arg5, s32 arg6, f32 farg0, f32 farg1);
extern s32 telepipe_visual_template_table[][3];
extern s32 telepipe_owner_tint_table[];
extern s32 tl_particlemodel;
extern const f32 lbl_805DC86C;
extern const f32 lbl_805DC870;
extern const f32 lbl_805DC874;
extern "C" {
void *create_telepipe_visual(void *self, Vec_802347B4 *pos, u32 id, s32 res);
void *__dt__13TUnk_804CC9D4Fv(void *arg0, s16 arg1);
void *__dt__9TTecLukerFv(TTecLuker *arg0, s16 arg1);
void stop_sound_request(s32 idx);
s32 free_collision_body_parts(void *);
s32 submit_cursor_candidate(void *, s32);

void TTecLuker__updateRecoveryTechniqueCharge(TechniqueChargeEmitter* state) {
    ++state->age;
    if(state->age%10==0) {
        for(int i=0;i<2;++i)spawn_particle_effect(state->position,recovery_technique_charge_particle_ids[i]);
    }
    if(!((TObjPlayer *)(state->actor))->check_flag_0x80())queue_destruction__7TObjectFv(state);
    else if(state->age>=180)queue_destruction__7TObjectFv(state);
}

void *TTecLuker::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = recovery_technique_charge_vtable;
        stop_sound_request((s32)(*(void **)((s8 *)this + 0x30)));
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

u8 *construct_resta_charge_sound(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__7TObjectFP7TObject((void *)arg0, (void *)arg2);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80233B9C_lbl_804CC990 *)&recovery_technique_charge_vtable).value;
    *(s32 *)((s8 *)arg0 + 0x1C) = arg1;
    VecCopy((Vec *)(arg0 + 0x20), (const Vec *)((int) (*(s32 *)((s8 *)arg0 + 0x1C) + 0x2FC)));
    ((TUnk_804CC990 *)arg0)->m_2c = 0;
    *(s32 *)((s8 *)arg0 + 0x30) = play_sound_effect(0x4002BC20, arg0 + 0x20, 0, 0);
    return arg0;
}

void TUnk_804CC9D4::interact(s32) { this->m_b0 = 1; }

void TTecLuker::update_player_target() {
    u8 *arg0 = (u8 *)this;
    if (is_split_screen() != 0) {
        if ((s32) this->m_ac != 0) {
            submit_cursor_candidate(arg0, -1);
            return;
        }
        if (are_players_gathered_near(arg0 + 0x38, 0, lbl_805DC858) != 0) {
            submit_cursor_candidate(arg0, -1);
        }
    } else {
        submit_cursor_candidate(arg0, -1);
    }
}

void *__dt__13TUnk_804CC9D4Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = telepipe_field_collider_vtable;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804CC9D4 *)arg0)->m_b0 = 0;
        __dt__13TUnk_804AF8A0Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80233D18_lbl_804CC9A8_size[sizeof(RecoveredGlobal_80233D18_lbl_804CC9A8) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_80233D18_lbl_804CC9D4_size[sizeof(RecoveredGlobal_80233D18_lbl_804CC9D4) == 0x38 ? 1 : -1];
u8 *TTecLuker::construct_field_collider(s32 arg1, s32 arg2, s32 ac) {
    __ct__13TUnk_804AF8A0FP7TObject(this, (void *)arg2);
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = &(*(RecoveredGlobal_80233D18_lbl_804CC9D4 *)&telepipe_field_collider_vtable).value;
    VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)(arg1));
    init_collision_body_parts(this, &telepipe_field_collision_body_template.value, 1);
    obj_setFlags30(this, 0x40000000);
    ((TObjPlayer *)((u8 *)this))->reset_photon_effect();
    ((TUnk_804CC9D4 *)this)->cursor_action.set_telepipe();
    *(s32 *)&this->unk_B0 = 0;
    this->m_ac = ac;
    return ((u8 *)this);
}

void TTecLuker::apply_all_players() {
    s32 var_r31;
    u32 player;

    var_r31 = 0;
    do {
        player = get_player_by_client_id(var_r31);
        if (player != 0U) {
            reset_telepipe_record((O_802340A0 *)(player + 0x830));
        }
        var_r31 += 1;
    } while (var_r31 < 4);
}

void TTecLuker::create_for_player(int arg0, s32 arg1) {
    u32 r = get_player_by_client_id((s32)((u16)arg0));
    if (r != 0U) {
        ((TTecLuker *)r)->create((void *)arg1, (void *)arg1, (void *)(0xA));
    }
}
}

void create_quest_telepipe_for_client(u16 arg0) {
    u8 *player;
    player = (u8 *)(((s32)get_player_by_client_id((s32)((u32) arg0))));
    if (player != NULL) {
        ((TTecLuker *)player)->create(player + 0x38, player + 0x2FC, NULL);
    }
}

Vec_80233E78 *consume_telepipe_arrival(u16 slot, s32 *heading) {
    Player_80233E78 *p;
    u16 owner;
    if (slot >= 4) {
        return 0;
    }
    p = (Player_80233E78 *)get_player_by_client_id(slot);
    if (p != 0) {
        owner = TObjPlayer__sub_801BFFA0(p->arrival);
        if (owner == 0xffff) {
            return 0;
        }
        set_state__9TTecLukerFl(p->arrival, 0xffff);
        if (TOKeyMachine01::get_global_state() == 0) {
            *heading = telepipe_town_heading_table[slot];
            return &telepipe_town_position_table[slot];
        }
        if (TOKeyMachine01::get_global_state() == 0x12) {
            *heading = telepipe_town_heading_table[slot];
            return &telepipe_town_position_table_b[slot];
        }
        p = (Player_80233E78 *)get_player_by_client_id(owner);
        if (p == 0) {
            return 0;
        }
        *heading = p->pipe_heading;
        return &p->pipe_pos;
    }
    return 0;
}

typedef s32 (*GetField2_80233F8C)(void *);
void restore_floor_telepipes(void) {
    s32 area = TOKeyMachine01::get_global_state();
    s32 i;
    if (area == 15 || area == 0 || area == 18) {
        return;
    }
    for (i = 0; i < 4; i++) {
        u8 *p = (u8 *)get_player_by_client_id(i);
        if (p != 0) {
            if (((GetField2_80233F8C)get_field_2__9TTecLukerFPv)(p + 0x830) == get_current_floor()) {
                ((TTecLuker *)p)->create(p + 0x38, p + 0x838, (void *)10);
            }
        }
    }
}

bool TTecLuker__sub_8023401C(u8 *arg0) {
    return *(s16 *)((s8 *)arg0 + 2) != 0;
}

s32 telepipe_record_differs(Rec_8023402C *r, s16 floor, Vec_8023402C *p, u16 unused) {
    Vec_8023402C d;
    if (r->floor == floor) {
        d.x = r->pos.x - p->x;
        d.y = lbl_805DC85C;
        d.z = r->pos.z - p->z;
        if (vector_length(&d) < lbl_805DC860) {
            return 0;
        }
    }
    return 1;
}

void reset_telepipe_record(O_802340A0 *o) {
    o->h0 = 0xffff;
    o->w4 = 0;
    o->h2 = 0;
    o->f8 = lbl_805DC85C;
    o->fc = lbl_805DC85C;
    o->f10 = lbl_805DC85C;
    o->w14 = 0;
}

void TTecLuker::init_fields(s16 name) {
    *(s16 *)&this->m_name = name;
    *(s16 *)((s8 *)this + 2) = 0;
    *(s32 *)&this->m_flags = 0;
}

void TTecLuker::send_telepipe_packet() {
    u8 *arg0 = (u8 *)this;
    Stack_802340E4 stack;
    init_telepipe_packet_header(&stack.sp8);
    stack.spC = *(u16 *)&this->m_name;
    stack.sp10 = *(s32 *)&this->m_flags;
    stack.spE = *(s16 *)((s8 *)arg0 + 2);
    VecCopy((Vec *)(&stack.sp14), (const Vec *)(arg0 + 8));
    stack.sp20 = *(s32 *)&this->m_down;
    ((TTecLuker *)(&stack.sp8))->send_swapped_telepipe_packet();
}

void write_telepipe_record(u8 *arg0, u16 arg1, s16 arg2, u8 *arg3, s32 arg4) {
    u8 *player;
    *(u16 *)((s8 *)arg0 + 0) = arg1;
    *(s16 *)((s8 *)arg0 + 2) = arg2;
    VecCopy((Vec *)(arg0 + 8), (const Vec *)arg3);
    *(s32 *)((s8 *)arg0 + 4) = arg4;
    if (arg1 <= 4U) {
        player = (u8 *)(((s32)get_player_by_client_id((s32)((u32) arg1))));
        if (player != NULL) {
            *(s32 *)((s8 *)arg0 + 0x14) = (s32) *(s32 *)((s8 *)player + 0x60);
        }
    }
}

void handle_6x68_set_telepipe_state(Pkt_802341B0 *pkt) {
    u8 *player;
    Rec_8023402C *rec;
    u32 other;
    u32 local;
    ((TTecLuker *)pkt)->byteswap_telepipe_packet();
    if (pkt->rec.owner == 0xffff) {
        return;
    }
    player = find_entity_by_id(pkt->rec.owner);
    if (player == 0) {
        return;
    }
    if (pkt->rec.owner >= 4) {
        return;
    }
    rec = (Rec_8023402C *)(player + 0x830);
    if (telepipe_record_differs(rec, pkt->rec.floor, &pkt->rec.pos, pkt->rec.owner) == 0) {
        return;
    }
    write_telepipe_record((u8 *)rec, pkt->rec.owner, pkt->rec.floor, (u8 *)&pkt->rec.pos, pkt->rec.section);
    if (is_split_screen() == 0 && pkt->rec.owner == local_client_id) {
        return;
    }
    other = get_player_by_client_id(pkt->rec.owner);
    local = get_player_by_client_id(local_client_id);
    if (other != 0 && local != 0) {
        if (((TObjPlayer *)other)->get_field_3e4() == ((TObjPlayer *)local)->get_field_3e4()) {
            ((TTecLuker *)player)->create(player + 0x38, player + 0x38, 0);
        }
    }
}

typedef struct Obj_802342A4 Obj_802342A4;
typedef struct Vec_802342A4 Vec_802342A4;
void TUnk_804CCA0C::run_task() {
    Obj_802342A4 *self = (Obj_802342A4 *)this;
  f32 d;
  f32 best;
  s32 j;
  s32 i;
  s32 st;
  u32 pl;
  best = lbl_805DC864;
  j = TOKeyMachine01::get_global_state();
  st = j;
  if ((st == 0) || (st == 0x12))
  {
    return;
  }
  if (is_split_screen() != 0)
  {
    for (j = 0; j < 4; j++)
    {
      pl = get_player_by_client_id(j);
      if (pl != 0)
      {
        d = horizontal_distance_squared(&self->pos, (void *)(pl + 0x38));
        if (d <= best)
        {
          best = d;
        }
      }
    }
    if (best >= lbl_805DC868)
    {
      for (i = 0; i < 3; i++)
      {
        if (TTecLuker::is_parents_unqueued(self->kids[i]) != 0)
        {
          ((TParticleCtrl *)(self->kids[i]))->enable();
          if (this->m_28 != 0)
          {
            TTecLuker__sub_80235048(this->m_28);
          }
        }
      }
      return;
    }
    for (i = 0; i < 3; i++)
    {
      if (TTecLuker::is_parents_unqueued(self->kids[i]) != 0)
      {
        ((TParticleCtrl *)(self->kids[i]))->clear_active_flag();
        if (this->m_28 != 0)
        {
          TTecLuker__sub_8023503C(this->m_28);
        }
      }
    }
    return;
  }
  if (horizontal_distance_squared(&self->pos, (void *)(camera_ctrl_instance + 0x178)) >= lbl_805DC868)
  {
    for (i = 0; i < 3; i++)
    {
      if (TTecLuker::is_parents_unqueued(self->kids[i]) != 0)
      {
        ((TParticleCtrl *)(self->kids[i]))->enable();
        if (this->m_28 != 0)
        {
          TTecLuker__sub_80235048(this->m_28);
        }
      }
    }
    return;
  }
  for (i = 0; i < 3; i++)
  {
    if (TTecLuker::is_parents_unqueued(self->kids[i]) != 0)
    {
      ((TParticleCtrl *)(self->kids[i]))->clear_active_flag();
      if (this->m_28 != 0)
      {
        TTecLuker__sub_8023503C(this->m_28);
      }
    }
  }
}

Obj_8023448C *__dt__13TUnk_804CCA0CFv(Obj_8023448C *arg0, s16 arg1) {
    s32 i;
    u32 z;
    if (arg0 != NULL) {
        i = 0;
        z = 0;
        arg0->vt = lbl_804CCA0C;
        do {
            if (TTecLuker::is_parents_unqueued(arg0->kids[i]) != 0) {
                queue_destruction__7TObjectFv((void *)arg0->kids[i]);
                arg0->kids[i] = z;
            }
            i++;
        } while (i < 3);
        if (arg0->f28 != 0) {
            queue_destruction__7TObjectFv((void *)arg0->f28);
            arg0->f28 = 0;
        }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
typedef struct Fx_8023453C Fx_8023453C;
typedef struct Hit_8023453C Hit_8023453C;
typedef struct V3_8023453C V3_8023453C;
typedef struct Vec_802347B4 Vec_802347B4;
struct Vec_802347B4;
void *create_telepipe_visual(void *self, Vec_802347B4 *pos, u32 id, s32 res) {
  V3_8023453C v;
  V3_8023453C v2;
  long long off;
  Hit_8023453C *hit;
  void *p;
  s32 *row;
  s32 i;
  u8 *pt;
  __ct__7TObjectFP7TObject(self, (void *) res);
  ((Fx_8023453C *) self)->vt = lbl_804CCA0C;
  VecCopy((Vec *)(&((Fx_8023453C *) self)->pos), (const Vec *)pos);
  hit = csnVecterUnder(&((Fx_8023453C *) self)->pos, 0x100);
  VecCopy((Vec *)(&((Fx_8023453C *) self)->pos2), (const Vec *)(&((Fx_8023453C *) self)->pos));
  if (hit != 0)
  {
    VecCopy((Vec *)(&((Fx_8023453C *) self)->pos2), (const Vec *)hit->pos);
  }
  row = telepipe_visual_template_table[id];
  off = id * 4;
  pt = (u8 *) telepipe_owner_tint_table;
  for (i = 0; i < 3; i++)
  {
    switch (i)
    {
      case 2:
        VecCopy((Vec *)&v, (const Vec *)(&((Fx_8023453C *) self)->pos2));
        v.y += lbl_805DC86C;
        ((Fx_8023453C *) self)->kids[i] = spawn_continuous_particle_effect_with_flags(&v, row[i], 0x40);
        if ((((Fx_8023453C *) self)->kids[i] != 0) && (id != 3))
      {
        ((TParticleCtrl *)(((Fx_8023453C *) self)->kids[i]))->set_tint_color(*((s32 *) (pt + off)));
      }
        break;
      default:
        ((Fx_8023453C *) self)->kids[i] = spawn_continuous_particle_effect_with_flags(&((Fx_8023453C *) self)->pos2, row[i], 0x40);
        if ((((Fx_8023453C *) self)->kids[i] != 0) && (id != 3))
      {
        ((TParticleCtrl *)(((Fx_8023453C *) self)->kids[i]))->set_tint_color(*((s32 *) (pt + off)));
      }
        break;
    }
  }
  VecCopy((Vec *)&v2, (const Vec *)(&((Fx_8023453C *) self)->pos));
  v2.y += lbl_805DC870;
  if (is_split_screen() == 0)
  {
    p = __nw__7TObjectFUl(0x44);
    if (p != 0)
    {
      p = create_telepipe_marker((u8 *)p, (s32)&v2, (s8)(0x1F), (s8)(4), (s32)tl_particlemodel, 0, 0, (f32)lbl_805DC874, (f32)lbl_805DC874);
    }
    ((Fx_8023453C *) self)->f28 = p;
  }
  else
  {
    ((Fx_8023453C *) self)->f28 = 0;
  }
  return self;
}
#pragma pop

void TTecLuker::vfunc_6(void *o_arg) {
    TTecLuker *self = this;
    VObj_802346F8 *o = (VObj_802346F8 *)o_arg;
    P_802346F8 d;
    d.t = 0xE;
    d.v = lbl_805DC858;
    o->m21(self->source, d, 0, -1, -1);
}

void TTecLuker::create(void *arg1, void *arg2, void *arg3) {
    void *o;
    o = __nw__7TObjectFUl(0x110);
    if (o != NULL) {
        TTecLuker__ct(o, this, arg1, arg2, arg3);
    }
}

typedef void (*Write_802347B4)(u8 *, s32, s16, u8 *, s32);
void TTecLuker::setup_telepipe_field() {
    Pipe_802347B4 *s = (Pipe_802347B4 *)this;
    u16 id = obj_getField1c(s->player);
    void *v = __nw__7TObjectFUl(0x44);
    if (v != 0) {
        v = create_telepipe_visual(v, (Vec_802347B4 *)(&s->pos), id, tl_07);
    }
    s->visual = v;
    s->phase = 1;
    if (s->collider != 0) {
        ((TUnk_804B9870 *)(s->collider))->set_position_from(&s->pos);
    } else {
        u8 *c = (u8 *)__nw__7TObjectFUl(0xb4);
        if (c != 0) {
            c = ((TTecLuker *)c)->construct_field_collider((s32)&s->pos, tl_05, 0);
        }
        s->collider = c;
    }
    if (s->traveller == (u16)obj_getField1c(s->player)) {
        s16 h;
        s->floor = get_current_floor();
        h = get_stat_by_key_state__13TUnk_804B9870Fv(s->player);
        ((Write_802347B4)write_telepipe_record)(s->player + 0x830, obj_getField1c(s->player), s->floor, (u8 *)&s->pos, h);
        ((TTecLuker *)(s->player + 0x830))->send_telepipe_packet();
    }
}

struct Rec_8023402C;
struct Vec_8023402C;
struct Pipe_802347B4;
void run_task__9TTecLukerFv(u8 *arg0) {
    struct { f32 x, y, z; } sp8;
    s32 temp_r30;
    u16 temp_r3;
    u16 temp_r5;
    s32 var_r29;
    u8 *temp_r29;
    u8 *player;
    u8 *owner;
    u8 *tgt;
    u16 st;
    *(u8 **)((s8 *)arg0 + 0x1C) = find_entity_by_id(((TTecLuker *)arg0)->m_b4);
    owner = *(u8 **)((s8 *)arg0 + 0x1C);
    if (owner == NULL) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    switch (((TTecLuker *)arg0)->m_108) {
    case 0:
        temp_r3 = obj_getField1c(owner);
        if (temp_r3 != 0xFFFFU) {
            if (temp_r3 > 0xCU) {
                ((TTecLuker *)arg0)->m_108 = 4;
                return;
            }
            tgt = *(u8 **)((s8 *)arg0 + 0xEC);
            if (tgt == NULL) {
                ((TTecLuker *)arg0)->setup_telepipe_field();
                return;
            }
            if (TTecLuker__sub_80235054(tgt) != 0) {
                VecCopy((Vec *)(arg0 + 0xFC), (const Vec *)(*(u8 **)((s8 *)arg0 + 0x1C) + 0x38));
                if ((telepipe_record_differs((Rec_8023402C *)(*(u8 **)((s8 *)arg0 + 0x1C) + 0x830), ((TTecLuker *)arg0)->m_f4, (Vec_8023402C *)(arg0 + 0xFC), ((TTecLuker *)arg0)->m_f6) == 0) && ((s8) *(TTecLuker__visit_counts + ((TTecLuker *)arg0)->m_b4) >= 1)) {
                    queue_destruction__7TObjectFv(arg0);
                    return;
                }
                ((TTecLuker *)arg0)->setup_telepipe_field();
            }
        }
        break;
    case 1:
        temp_r5 = ((TTecLuker *)arg0)->m_b4;
        if (temp_r5 < 4U) {
            *(TTecLuker__visit_counts + temp_r5) = *(TTecLuker__visit_counts + temp_r5) + 1;
        }
        if (telepipe_record_differs((Rec_8023402C *)(*(u8 **)((s8 *)arg0 + 0x1C) + 0x830), ((TTecLuker *)arg0)->m_f4, (Vec_8023402C *)(arg0 + 0xFC), ((TTecLuker *)arg0)->m_f6) != 0) {
            queue_destruction__7TObjectFv(arg0);
            return;
        }
        play_persistent_sound(0x4002B219, arg0, arg0 + 0xFC, 0, 0);
        if ((u32) ((TTecLuker *)arg0)->m_f0 == 0U) {
            queue_destruction__7TObjectFv(arg0);
            return;
        }
        if ((get_player_by_client_id(((TTecLuker *)arg0)->m_f6) != 0) && (get_pipe_interaction_latch(*(void **)((s8 *)arg0 + 0xF0)) != 0) && (are_players_gathered_near(arg0 + 0xFC, 0, lbl_805DC858) != 0)) {
            offset_point_toward_camera(arg0 + 0xFC, (u8 *)((s32 *) &sp8), (f32)lbl_805DC858);
            spawn_particle_effect((float *) &sp8, 0xB3);
            player = (u8 *)get_player_by_client_id(((TTecLuker *)arg0)->m_f6);
            if (player != NULL) {
                play_effect_default__10TObjPlayerFii(player, 0xA);
                play_sound_effect(0x40022D1A, player + 0x38, 0, 0);
            }
            TWindowCtrl::init_all_slots();
            ((TTecLuker *)arg0)->m_108 = 2;
            return;
        }
        break;
    case 2:
        ((TTecLuker *)arg0)->m_10c = (s32) (((TTecLuker *)arg0)->m_10c + 1);
        if ((s32) ((TTecLuker *)arg0)->m_10c > 0xA) {
            ((TTecLuker *)arg0)->m_108 = 3;
            return;
        }
        break;
    case 3:
        temp_r30 = obj_getField1c(owner);
        temp_r29 = (u8 *)get_player_by_client_id(((TTecLuker *)arg0)->m_f6);
        if ((is_split_screen() == 0) && (temp_r29 != NULL)) {
            if (*(s32 *)((s8 *)temp_r29 + 0x30) & 0x800) {
                ((TTecLuker *)arg0)->m_108 = 1;
                TWindowCtrl::init_all_slots2();
                if ((u32) ((TTecLuker *)arg0)->m_f0 == 0U) {
                    queue_destruction__7TObjectFv(arg0);
                    return;
                }
                clear_pipe_interaction_latch((void*)(*(void **)((s8 *)arg0 + 0xF0)));
                ((TTecLuker *)arg0)->m_10c = 0;
                return;
            }
            ((void (*)(void *, u16))set_state__9TTecLukerFl)(temp_r29 + 0x848, temp_r30);
            if (TLobby::get_instance() == 1) {
                send_6x21_inter_level_warp(temp_r29, 0);
            } else {
                send_6x21_inter_level_warp(temp_r29, 0);
            }
            goto block_43;
        }
block_43:
        {
        s32 i;
        u16 st2;
        u8 *p;
        i = 0;
        st2 = (u16) temp_r30;
        do {
            p = (u8 *)get_player_by_client_id(i);
            if (p != NULL) {
                if (is_split_screen() != 0) {
                    ((void (*)(void *, u16))set_state__9TTecLukerFl)(p + 0x848, st2);
                    if (TLobby::get_instance() == 1) {
                        send_6x21_inter_level_warp(p, 0);
                    } else {
                        send_6x21_inter_level_warp(p, 0);
                    }
                } else if (obj_isState3_324__13TUnk_804806E8Fv(p) != 0) {
                    ((void (*)(void *, u16))set_state__9TTecLukerFl)(p + 0x848, st2);
                    if (TLobby::get_instance() == 1) {
                        send_6x21_inter_level_warp(p, 0);
                    } else {
                        send_6x21_inter_level_warp(p, 0);
                    }
                }
            }
            i += 1;
        } while (i < 4);
        }
        if (is_split_screen() != 0) {
            TWindowCtrl::init_all_slots2();
        }
        set_area__6TLobbyFl(lbl_80515BA0, 0, get_floor_map_terrain(0));
        mark_area_change_pending();
        return;
    case 4:
        queue_destruction__7TObjectFv(arg0);
        break;
    }
}

void *__dt__9TTecLukerFv(TTecLuker *arg0, s16 arg1) {
    s32 temp_cr0_eq;
    void *temp_r3;

    if (arg0 != NULL) {
        *(void **)((s8 *)arg0 + 0x18) = (void *) __vt__9TTecLuker;
        if ((u32) arg0->m_f8 != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xF8));
            arg0->m_f8 = 0U;
        }
        temp_r3 = *(void **)((s8 *)arg0 + 0xEC);
        if (temp_r3 != NULL) {
            if (temp_r3 != NULL) {
                ((struct VM_80234C90_80233B38 *) temp_r3)->m0(1);
            }
            *(void **)((s8 *)arg0 + 0xEC) = NULL;
        }
        if ((u32) arg0->m_f0 != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xF0));
            arg0->m_f0 = 0U;
        }
        arg0->m_f0 = 0U;
        __dt__13TUnk_804CC148Fv((void *)((TUnk_804CC148 *)arg0), 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#define L ((Luker_80234D50 *)arg0)
void *TTecLuker__ct(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    Owner_80234D50 *o;
    void *p;
    construct_area_technique_base(arg0, arg1, arg2);
    L->vt = __vt__9TTecLuker;
    L->f0 = lbl_805D37E4;
    L->f108 = 0;
    L->f10C = 0;
    L->fF0 = 0;
    L->fF8 = 0;
    L->fF4 = get_current_floor();
    L->fx = NULL;
    if (L->owner != NULL) {
        L->owner_id = obj_getField1c(L->owner);
    }
    L->fF6 = local_client_id;
    if (is_split_screen() == 0 && L->owner_id != local_client_id) {
        VecCopy((Vec *)&L->pos, (const Vec *)&L->owner->pipe_pos);
    } else {
        L->fF6 = L->owner_id;
        if ((s32)arg4 == 0xA) {
            VecCopy((Vec *)&L->pos, (const Vec *)arg3);
        } else {
            p = alloc__23TAdSinglePlyChrSelectGCFv(0xA8);
            if (p != NULL) {
                p = ((TItemList *)p)->init_array();
            }
            L->fx = p;
            if (L->fx != NULL) {
                Vec_80234D50 v = lbl_8044D72C;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, L->owner->f60);
                matrix_mult_vec(0, &v, &v);
                pop_matrices(1);
                o = L->owner;
                v.x += o->pos.x;
                v.y += lbl_805DC878 + o->pos.y;
                v.z += o->pos.z;
                start_placement_search((s32)L->fx, (s32)&v, (s32)o);
            }
        }
    }
    play_sound_effect(0x4002A818, (u8 *)arg0 + 0x20, 0, 0);
    return arg0;
}
#undef L

void TTecLuker__sub_80234F08(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        TTecLuker__visit_counts[i] = 0;
    }
}

void reset_telepipe_visit_counts(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        TTecLuker__visit_counts[i] = 0;
    }
}

void TTecLuker__sub_80234F48(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        TTecLuker__visit_counts[i] = 0;
    }
}

void CursorAction::set_telepipe() { kind = CURSOR_ACTION_TELEPIPE; }
s16 get_field_2__9TTecLukerFPv(void* p) { return *(s16*)((char*)p + 0x2); }

void clear_pipe_interaction_latch(void* p) { *(s32*)((char*)p + 0xb0) = 0; }

s32 get_pipe_interaction_latch(void* p) { return *(s32*)((char*)p + 0xb0); }

void TTecLuker::send_swapped_telepipe_packet() { byteswap_telepipe_packet(); send_subcommand((u8 *)this); }

void TTecLuker::byteswap_telepipe_packet() {
    ((G_ClientIDHeader *)this)->bswap();
    bswap_16((u16 *)((void *)((char *)this + 4)));
    bswap_16((u16 *)((void *)((char *)this + 6)));
    bswap_16((u16 *)((void *)((char *)this + 8)));
    bswap_32((u32 *)((void *)((char *)this + 12)));
    bswap_32((u32 *)((void *)((char *)this + 16)));
    bswap_32((u32 *)((void *)((char *)this + 20)));
    bswap_32((u32 *)((void *)((char *)this + 24)));
}

void init_telepipe_packet_header(void* p) { *(u8*)((char*)p + 0x0) = 104; *(u8*)((char*)p + 0x1) = 7; }

void TTecLuker__sub_8023503C(void* p) { *(s32*)((char*)p + 0x38) = 1; }

void TTecLuker__sub_80235048(void* p) { *(s32*)((char*)p + 0x38) = 0; }

int TTecLuker__sub_80235054(void* p) { return fn_80235078((void *)((char*)p + 0x4)); }
int fn_80235078(void *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0x0) == 2);
}
