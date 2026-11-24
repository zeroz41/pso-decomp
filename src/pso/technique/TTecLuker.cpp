#include "pso/player/PlayerState.h"
#include "pso/system/SoundEffect.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/unk/text_803D96A8.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/network/protocol/protocol_types.h"

#include "pso/player/TObjPlayer.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/player/TObjPlayer_801D3554.h"
#include "pso/unk/TUnk_804CC9D4.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "types.h"
#include "pso/unk/text_8023601C.h"
#include "pso/map/FloorArea.h"
#include "pso/object/base/TObjChara.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/technique/TTecLuker.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/TUnk_804CCA0C.h"
#include "pso/unk/TUnk_804CC990.h"
#include "pso/system/byteswap.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/technique/TTecCircle.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/item/TItemList.h"
#include "pso/player/TPlyItem.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/system/SoundEffect.h"
#include "pso/network/client_id.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/math/MatrixVector.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/particle/TTelepipeMarker.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

struct Stack_802340E4 {
    s32 sp8;
    u16 spC;
    s16 spE;
    s32 sp10;
    s32 sp14;
    u8 pad_18[0x8];
    s32 sp20;
};

struct O_802340A0 { u16 h0; u16 h2; s32 w4; f32 f8; f32 fc; f32 f10; s32 w14; };

struct Player_80233E78 { u8 pad[0x838]; Vec pipe_pos; s32 pipe_heading; u8 arrival[4]; };

struct Rec_8023402C { u16 owner; s16 floor; s32 section; Vec pos; s32 heading; };

struct Pkt_802341B0 { u8 hdr[4]; Rec_8023402C rec; };

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
s32 init_collision_body_parts(void *, void *, int);
bool TTecLuker__sub_8023401C(u8 *arg0);
}
// The collision body every telepipe field collider starts from: a 0.01 sphere.
CollisionBody telepipe_field_collision_body_template = {
    {0.0f, 0.0f, 0.0f}, 0.01f, 0.0f, 0, 0x8031F0B, {0.0f, 0.0f, 0.0f}, 0.0f};
u8 TTecLuker__visit_counts[4] = { 0, 0, 0, 0 };
void reset_telepipe_visit_counts(void);
extern "C" {
void TTecLuker__sub_80234F08(void);
void reset_telepipe_record(O_802340A0 *o);
void TTecLuker__sub_80234F48(void);
void set_state__9TTecLukerFl(void *p, s32 v);
static const s32 telepipe_visual_template_table[12][3] = {
    { 177, 178, 176 },
    { 177, 178, 176 },
    { 177, 178, 176 },
    { 176, 177, 178 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
};
static const s32 telepipe_owner_tint_table[12] = {
    0x00FFB2B2, 0x0099FFB2, 0x00FFFFB2, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
const char *TTecLuker__name = "TTecLuker";
static const Vec lbl_8044D72C = { 0.0f, 0.0f, 0.2f };
static const Vec telepipe_town_position_table[4] = {
    { -312.0f, 0.0f, -113.0f },
    { -306.0f, 0.0f, -135.0f },
    { -285.0f, 0.0f, -172.0f },
    { -249.0f, 0.0f, -190.0f },
};
static const Vec telepipe_town_position_table_b[4] = {
    { 270.0f, -30.0f, -220.0f },
    { 300.0f, -30.0f, -220.0f },
    { 330.0f, -30.0f, -215.0f },
    { 360.0f, -30.0f, -185.0f },
};
static const s32 telepipe_town_heading_table[4] = { 16384, 16384, 16384, 16384 };
const Vec *consume_telepipe_arrival(u16 slot, s32 *heading);
s16 get_field_2__9TTecLukerFPv(void* p);
s32 get_current_floor(void);
void restore_floor_telepipes(void);
s32 telepipe_record_differs(Rec_8023402C *r, s16 floor, Vec *p, u16 unused);
s32 is_split_screen();
u8 *find_entity_by_id(u16);
void handle_6x68_set_telepipe_state(Pkt_802341B0 *pkt);
f32 horizontal_distance_squared(void *, void *);
s32 free_collision_body_parts(void *);
s32 submit_cursor_candidate(void *, s32);
}
extern u8 identity_matrix[];
void init_telepipe_packet_header(void* p);
void create_quest_telepipe_for_client(u16 client);
void write_telepipe_record(u8 *arg0, u16 arg1, s16 arg2, u8 *arg3, s32 arg4);
s32 are_players_gathered_near(void *arg0, s32 *arg1, f32 range);
int fn_80235078(void *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0x0) == 2);
}

int TTecLuker__sub_80235054(void* p) { return fn_80235078((void *)((char*)p + 0x4)); }

void TTecLuker__sub_80235048(void* p) { *(s32*)((char*)p + 0x38) = 0; }

void TTecLuker__sub_8023503C(void* p) { *(s32*)((char*)p + 0x38) = 1; }

void init_telepipe_packet_header(void* p) { *(u8*)((char*)p + 0x0) = 104; *(u8*)((char*)p + 0x1) = 7; }

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

void TTecLuker::send_swapped_telepipe_packet() { byteswap_telepipe_packet(); send_subcommand((u8 *)this); }

s32 get_pipe_interaction_latch(void* p) { return *(s32*)((char*)p + 0xb0); }

void clear_pipe_interaction_latch(void* p) { *(s32*)((char*)p + 0xb0) = 0; }

s16 get_field_2__9TTecLukerFPv(void* p) { return *(s16*)((char*)p + 0x2); }

void CursorAction::set_telepipe() { kind = CURSOR_ACTION_TELEPIPE; }

void TTecLuker__sub_80234F48(void) {
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

void TTecLuker__sub_80234F08(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        TTecLuker__visit_counts[i] = 0;
    }
}

TTecLuker::TTecLuker(saddr source, Vec *pos, Vec *target, s32 level) : TTecCircle(source, pos, target, level) {
    m_name = TTecLuker__name;
    phase = 0;
    warp_frames = 0;
    field = NULL;
    visual = NULL;
    floor = get_current_floor();
    placement = NULL;
    if (this->source != 0) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
    traveller = local_client_id;
    if (is_split_screen() == 0 && sourceId != local_client_id) {
        VecCopy(&pipe_pos, (const Vec *)((u8 *)this->source + 0x838));
    } else {
        traveller = sourceId;
        if (level == 10) {
            VecCopy(&pipe_pos, target);
        } else {
            placement = new TUnk_804C4450;
            if (placement != NULL) {
                Vec v = lbl_8044D72C;
                TObjBase *owner;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, ((TObjBase *)this->source)->rotation_y);
                matrix_mult_vec(0, &v, &v);
                pop_matrices(1);
                owner = (TObjBase *)this->source;
                v.x += owner->position.x;
                v.y += 20.0f + owner->position.y;
                v.z += owner->position.z;
                start_placement_search(placement, &v, owner);
            }
        }
    }
    play_sound_effect(0x4002A818, &position, 0, 0);
}

TTecLuker::~TTecLuker() {
    if (visual != NULL) {
        visual->queue_destruction();
        visual = NULL;
    }
    if (placement != NULL) {
        delete placement;
        placement = NULL;
    }
    if (field != NULL) {
        field->queue_destruction();
        field = NULL;
    }
    field = NULL;
}

void TTecLuker::run_task() {
    struct { f32 x, y, z; } position;
    u16 owner_id;
    u16 entity_id;
    u16 temp_r5;
    u8 *temp_r29;
    TObjPlayer *player;
    u8 *owner;
    TUnk_804C4450 *tgt;
    source = (uaddr)find_entity_by_id(sourceId);
    owner = (u8 *)source;
    if (owner == NULL) {
        queue_destruction();
        return;
    }
    switch (phase) {
    case 0:
        entity_id = ((TObjBase *)(owner))->get_entity_id();
        if (entity_id != 0xFFFFU) {
            if (entity_id > 0xCU) {
                phase = 4;
                return;
            }
            tgt = placement;
            if (tgt == NULL) {
                setup_telepipe_field();
                return;
            }
            if (TTecLuker__sub_80235054(tgt) != 0) {
                VecCopy(&pipe_pos, &((TObjBase *)source)->position);
                if ((telepipe_record_differs((Rec_8023402C *)((u8 *)source + 0x830), floor, &pipe_pos, traveller) == 0) && ((s8) TTecLuker__visit_counts[sourceId] >= 1)) {
                    queue_destruction();
                    return;
                }
                setup_telepipe_field();
            }
        }
        break;
    case 1:
        temp_r5 = sourceId;
        if (temp_r5 < 4U) {
            TTecLuker__visit_counts[temp_r5] = TTecLuker__visit_counts[temp_r5] + 1;
        }
        if (telepipe_record_differs((Rec_8023402C *)((u8 *)source + 0x830), floor, &pipe_pos, traveller) != 0) {
            queue_destruction();
            return;
        }
        play_persistent_sound(0x4002B219, this, &pipe_pos, 0, 0);
        if (field == NULL) {
            queue_destruction();
            return;
        }
        if ((get_player_by_client_id(traveller) != NULL) && (get_pipe_interaction_latch(field) != 0) && (are_players_gathered_near(&pipe_pos, 0, 10.0f) != 0)) {
            offset_point_toward_camera(&pipe_pos, (Vec *)&position, 10.0f);
            spawn_particle_effect((const Vec *)&position, 0xB3);
            player = get_player_by_client_id(traveller);
            if (player != NULL) {
                send_impose_hold(player, 0xA);
                play_sound_effect(0x40022D1A, &player->position, 0, 0);
            }
            TWindowCtrl::init_all_slots();
            phase = 2;
            return;
        }
        break;
    case 2:
        warp_frames = warp_frames + 1;
        if (warp_frames > 0xA) {
            phase = 3;
            return;
        }
        break;
    case 3:
        owner_id = ((TObjBase *)(owner))->get_entity_id();
        temp_r29 = (u8 *)get_player_by_client_id(traveller);
        if ((is_split_screen() == 0) && (temp_r29 != NULL)) {
            if (*(s32 *)((s8 *)temp_r29 + 0x30) & 0x800) {
                phase = 1;
                TWindowCtrl::init_all_slots2();
                if (field == NULL) {
                    queue_destruction();
                    return;
                }
                clear_pipe_interaction_latch(field);
                warp_frames = 0;
                return;
            }
            set_state__9TTecLukerFl(temp_r29 + 0x848, owner_id);
            if (TLobby::get_instance() == 1) {
                send_6x21_inter_level_warp((TObjPlayer *)temp_r29, 0);
            } else {
                send_6x21_inter_level_warp((TObjPlayer *)temp_r29, 0);
            }
            goto block_43;
        }
block_43:
        {
        s32 i;
        u8 *p;
        i = 0;
        do {
            p = (u8 *)get_player_by_client_id(i);
            if (p != NULL) {
                if (is_split_screen() != 0) {
                    set_state__9TTecLukerFl(p + 0x848, owner_id);
                    if (TLobby::get_instance() == 1) {
                        send_6x21_inter_level_warp((TObjPlayer *)p, 0);
                    } else {
                        send_6x21_inter_level_warp((TObjPlayer *)p, 0);
                    }
                } else if (((TObjChara *)p)->obj_isState3_324() != 0) {
                    set_state__9TTecLukerFl(p + 0x848, owner_id);
                    if (TLobby::get_instance() == 1) {
                        send_6x21_inter_level_warp((TObjPlayer *)p, 0);
                    } else {
                        send_6x21_inter_level_warp((TObjPlayer *)p, 0);
                    }
                }
            }
            i += 1;
        } while (i < 4);
        }
        if (is_split_screen() != 0) {
            TWindowCtrl::init_all_slots2();
        }
        floor_transition_state.set_next_floor(0, get_floor_map_terrain(0));
        mark_area_change_pending();
        return;
    case 4:
        queue_destruction();
        break;
    }
}

void TTecLuker::setup_telepipe_field() {
    s32 id = ((TObjBase *)source)->get_entity_id();
    visual = new TUnk_804CCA0C(&pipe_pos, id, tl_07);
    phase = 1;
    if (field != NULL) {
        field->set_position_from(&pipe_pos);
    } else {
        field = new TUnk_804CC9D4(&pipe_pos, tl_05, 0);
    }
    if (traveller == ((TObjBase *)source)->get_entity_id()) {
        s16 room;
        floor = get_current_floor();
        room = (s32)((TObjBase *)source)->get_room();
        write_telepipe_record((u8 *)source + 0x830, ((TObjBase *)source)->get_entity_id(), floor, (u8 *)&pipe_pos, room);
        ((TTecLuker *)((u8 *)source + 0x830))->send_telepipe_packet();
    }
}

void TTecLuker::create(void *pos, void *target, void *level) {
    new TTecLuker((saddr)this, (Vec *)pos, (Vec *)target, (saddr)level);
}

void TTecLuker::vfunc_6(void *o_arg) {
    VObj_802346F8 *o = (VObj_802346F8 *)o_arg;
    P_802346F8 d;
    d.t = 0xE;
    d.v = 10.0f;
    o->m21(source, d, 0, -1, -1);
}

#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
TUnk_804CCA0C::TUnk_804CCA0C(Vec *at, u32 id, TObject *parent) : TObject(parent) {
  Vec v;
  Vec v2;
  long long off;
  CsnHit *hit;
  const s32 *row;
  s32 i;
  const u8 *pt;
  VecCopy(&pos, at);
  hit = csnVecterUnder(&pos, 0x100);
  VecCopy(&ground_pos, &pos);
  if (hit != 0)
  {
    VecCopy(&ground_pos, &hit->contact->point);
  }
  row = telepipe_visual_template_table[id];
  off = id * 4;
  pt = (const u8 *) telepipe_owner_tint_table;
  for (i = 0; i < 3; i++)
  {
    switch (i)
    {
      case 2:
        VecCopy((Vec *)&v, &ground_pos);
        v.y += 1.8f;
        particles[i] = spawn_continuous_particle_effect_with_flags(&v, row[i], 0x40);
        if ((particles[i] != 0) && (id != 3))
      {
        particles[i]->set_tint_color(*((s32 *) (pt + off)));
      }
        break;
      default:
        particles[i] = spawn_continuous_particle_effect_with_flags(&ground_pos, row[i], 0x40);
        if ((particles[i] != 0) && (id != 3))
      {
        particles[i]->set_tint_color(*((s32 *) (pt + off)));
      }
        break;
    }
  }
  VecCopy((Vec *)&v2, &pos);
  v2.y += 15.0f;
  if (is_split_screen() == 0)
  {
    marker = new TTelepipeMarker(&v2, 0x1F, 4, tl_particlemodel, 0, 0, 1.9f, 1.9f);
  }
  else
  {
    marker = 0;
  }
}
#pragma pop

TUnk_804CCA0C::~TUnk_804CCA0C() {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (TTecLuker::is_parents_unqueued((uaddr)particles[i]) != 0) {
            particles[i]->queue_destruction();
            particles[i] = NULL;
        }
    }
    if (marker != NULL) {
        ((TObject *)marker)->queue_destruction();
        marker = NULL;
    }
}

void TUnk_804CCA0C::run_task() {
  f32 d;
  f32 best;
  s32 j;
  s32 i;
  s32 st;
  uaddr pl;
  best = 10000.0f;
  j = get_current_floor_area();
  st = j;
  if ((st == 0) || (st == 0x12))
  {
    return;
  }
  if (is_split_screen() != 0)
  {
    for (j = 0; j < 4; j++)
    {
      pl = (uaddr)get_player_by_client_id(j);
      if (pl != 0)
      {
        d = horizontal_distance_squared(&pos, (void *)(pl + 0x38));
        if (d <= best)
        {
          best = d;
        }
      }
    }
    if (best >= 102400.0f)
    {
      for (i = 0; i < 3; i++)
      {
        if (TTecLuker::is_parents_unqueued((uaddr)particles[i]) != 0)
        {
          particles[i]->enable();
          if (marker != 0)
          {
            TTecLuker__sub_80235048(marker);
          }
        }
      }
      return;
    }
    for (i = 0; i < 3; i++)
    {
      if (TTecLuker::is_parents_unqueued((uaddr)particles[i]) != 0)
      {
        particles[i]->clear_active_flag();
        if (marker != 0)
        {
          TTecLuker__sub_8023503C(marker);
        }
      }
    }
    return;
  }
  if (horizontal_distance_squared(&pos, &camera_ctrl_instance->pos) >= 102400.0f)
  {
    for (i = 0; i < 3; i++)
    {
      if (TTecLuker::is_parents_unqueued((uaddr)particles[i]) != 0)
      {
        particles[i]->enable();
        if (marker != 0)
        {
          TTecLuker__sub_80235048(marker);
        }
      }
    }
    return;
  }
  for (i = 0; i < 3; i++)
  {
    if (TTecLuker::is_parents_unqueued((uaddr)particles[i]) != 0)
    {
      particles[i]->clear_active_flag();
      if (marker != 0)
      {
        TTecLuker__sub_8023503C(marker);
      }
    }
  }
}

void handle_6x68_set_telepipe_state(Pkt_802341B0 *pkt) {
    u8 *player;
    Rec_8023402C *rec;
    uaddr other;
    uaddr local;
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
    other = (uaddr)get_player_by_client_id(pkt->rec.owner);
    local = (uaddr)get_player_by_client_id(local_client_id);
    if (other != 0 && local != 0) {
        if (((TObjPlayer *)other)->get_floor() == ((TObjPlayer *)local)->get_floor()) {
            ((TTecLuker *)player)->create(player + 0x38, player + 0x38, 0);
        }
    }
}

void write_telepipe_record(u8 *arg0, u16 arg1, s16 arg2, u8 *arg3, s32 arg4) {
    u8 *player;
    *(u16 *)((s8 *)arg0 + 0) = arg1;
    *(s16 *)((s8 *)arg0 + 2) = arg2;
    VecCopy((Vec *)(arg0 + 8), (const Vec *)arg3);
    *(s32 *)((s8 *)arg0 + 4) = arg4;
    if (arg1 <= 4U) {
        player = (u8 *)get_player_by_client_id((s32)((u32) arg1));
        if (player != NULL) {
            *(s32 *)((s8 *)arg0 + 0x14) = (s32) *(s32 *)((s8 *)player + 0x60);
        }
    }
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

void TTecLuker::init_fields(s16 name) {
    *(s16 *)&this->m_name = name;
    *(s16 *)((s8 *)this + 2) = 0;
    *(s32 *)&this->m_flags = 0;
}

void reset_telepipe_record(O_802340A0 *o) {
    o->h0 = 0xffff;
    o->w4 = 0;
    o->h2 = 0;
    o->f8 = 0.0f;
    o->fc = 0.0f;
    o->f10 = 0.0f;
    o->w14 = 0;
}

s32 telepipe_record_differs(Rec_8023402C *r, s16 floor, Vec *p, u16 unused) {
    Vec d;
    if (r->floor == floor) {
        d.x = r->pos.x - p->x;
        d.y = 0.0f;
        d.z = r->pos.z - p->z;
        if (vector_length(&d) < 0.2f) {
            return 0;
        }
    }
    return 1;
}

bool TTecLuker__sub_8023401C(u8 *arg0) {
    return *(s16 *)((s8 *)arg0 + 2) != 0;
}

typedef s32 (*GetField2_80233F8C)(void *);
void restore_floor_telepipes(void) {
    s32 area = get_current_floor_area();
    s32 i;
    if (area == AREA_LOBBY || area == AREA_PIONEER2_EP1 || area == AREA_PIONEER2_EP2) {
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

const Vec *consume_telepipe_arrival(u16 slot, s32 *heading) {
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
        ((TTecLuker *)p->arrival)->set_state(0xffff);
        if (get_current_floor_area() == AREA_PIONEER2_EP1) {
            *heading = telepipe_town_heading_table[slot];
            return &telepipe_town_position_table[slot];
        }
        if (get_current_floor_area() == AREA_PIONEER2_EP2) {
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

void create_quest_telepipe_for_client(u16 client) {
    u8 *player;
    player = (u8 *)get_player_by_client_id((s32)((u32) client));
    if (player != NULL) {
        ((TTecLuker *)player)->create(player + 0x38, player + 0x2FC, NULL);
    }
}

void TTecLuker::create_for_player(int arg0, saddr arg1) {
    uaddr r = (uaddr)get_player_by_client_id((s32)((u16)arg0));
    if (r != 0U) {
        ((TTecLuker *)r)->create((void *)arg1, (void *)arg1, (void *)(0xA));
    }
}

void TTecLuker::apply_all_players() {
    s32 i;
    uaddr player;

    i = 0;
    do {
        player = (uaddr)get_player_by_client_id(i);
        if (player != 0U) {
            reset_telepipe_record((O_802340A0 *)(player + 0x830));
        }
        i += 1;
    } while (i < 4);
}

TUnk_804CC9D4::TUnk_804CC9D4(Vec *pos, TObject *parent, s32 always) : TObjCollidable(parent) {
    VecCopy(&position, pos);
    init_collision_body_parts(this, &telepipe_field_collision_body_template, 1);
    set_actor_flags(0x40000000);
    register_object_by_id();
    cursor_action.set_telepipe();
    interacted = 0;
    always_selectable = always;
}

TUnk_804CC9D4::~TUnk_804CC9D4() {
    unregister_object_by_id();
    free_collision_body_parts(this);
    interacted = 0;
}

void TUnk_804CC9D4::run_task() {
    if (is_split_screen() != 0) {
        if (always_selectable != 0) {
            submit_cursor_candidate(this, -1);
            return;
        }
        if (are_players_gathered_near(&position, 0, 10.0f) != 0) {
            submit_cursor_candidate(this, -1);
        }
    } else {
        submit_cursor_candidate(this, -1);
    }
}

void TUnk_804CC9D4::interact(u16) { interacted = 1; }
