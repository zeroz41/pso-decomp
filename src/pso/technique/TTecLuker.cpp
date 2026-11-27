#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/PlayerState.h"
#include "pso/system/data/FlagWord.h"
#include "pso/system/SoundEffect.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/MatrixStack.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/player/LocalClientId.h"
#include "pso/network/protocol/protocol_types.h"

#include "pso/player/TObjPlayer.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/player/TPlyItem.h"
#include "pso/technique/TTelepipeSelectField.h"
#include "pso/network/TGameProtocol.h"
#include "types.h"
#include "pso/object/TActorLight.h"
#include "pso/map/FloorArea.h"
#include "pso/object/base/TObjChara.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/technique/TTecLuker.h"
#include "pso/system/MatrixStack.h"
#include "pso/technique/TTelepipeEffect.h"
#include "pso/technique/TTecLightCharge.h"
#include "pso/system/byteswap.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/technique/TTecCircle.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/item/TItemList.h"
#include "pso/player/TPlyItem.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/map/FloorMapSelection.h"
#include "pso/system/SoundEffect.h"
#include "pso/network/client_id.h"
#include "pso/render/DebugFont.h"
#include "pso/math/MatrixReflect.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/math/MatrixVector.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/particle/TTelepipeMarker.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"
#include "pso/render/render_util.h"
#include "pso/player/PlayerSlots.h"
#include "pso/render/gjSystem.h"
#include "pso/object/TObjLuker.h"
#include "pso/player/PlayerCommands.h"
#include "pso/object/base/ActorCollision.h"



// The collision body every telepipe field collider starts from: a 0.01 sphere.
CollisionBody telepipe_field_collision_body_template = {
    {0.0f, 0.0f, 0.0f}, 0.01f, 0.0f, 0, 0x8031F0B, {0.0f, 0.0f, 0.0f}, 0.0f};
u8 TTecLuker::visit_counts[4] = { 0, 0, 0, 0 };
void reset_telepipe_visit_counts(void);
extern "C" {
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
}
const char *TTecLuker::name = "TTecLuker";
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
s32 PlacementSlot::is_placed() { return (u8)(state == 2); }

s32 PlacementQueue::is_first_slot_placed() { return slots[0].is_placed(); }

void TTelepipeMarker::hide() { visible = 0; }

void TTelepipeMarker::show() { visible = 1; }

G_SetTelepipeState_6x68::G_SetTelepipeState_6x68() {
    header.subcommand = 0x68;
    header.size = 7;
}

void G_SetTelepipeState_6x68::bswap() {
    header.bswap();
    bswap_16(&state.owner_client_id);
    bswap_16((u16 *)&state.floor);
    bswap_16((u16 *)&state.room_id);  // only the high half: the room id is swapped as 16 bits
    bswap_32((u32 *)&state.pos.x);
    bswap_32((u32 *)&state.pos.y);
    bswap_32((u32 *)&state.pos.z);
    bswap_32(&state.angle_y);
}

void G_SetTelepipeState_6x68::send() {
    bswap();
    send_subcommand(this);
}

s32 TTelepipeSelectField::get_interacted() { return interacted; }

void TTelepipeSelectField::clear_interacted() { interacted = 0; }

s32 TelepipeState::get_floor() { return floor; }

void CursorAction::set_telepipe() { kind = CURSOR_ACTION_TELEPIPE; }

void TTecLuker::reset_visit_counts_on_floor_load() {
    s32 i;
    for (i = 0; i < 4; i++) {
        TTecLuker::visit_counts[i] = 0;
    }
}

void reset_telepipe_visit_counts(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        TTecLuker::visit_counts[i] = 0;
    }
}

void TTecLuker::reset_visit_counts_on_floor_free() {
    s32 i;
    for (i = 0; i < 4; i++) {
        TTecLuker::visit_counts[i] = 0;
    }
}

TTecLuker::TTecLuker(TObjBase *source, Vec *pos, Vec *target, s32 level) : TTecCircle(source, pos, target, level) {
    m_name = TTecLuker::name;
    phase = 0;
    warp_frames = 0;
    field = NULL;
    visual = NULL;
    floor = get_current_floor();
    placement = NULL;
    if (this->source != NULL) {
        sourceId = this->source->get_entity_id();
    }
    traveller = local_client_id;
    if (is_split_screen() == 0 && sourceId != local_client_id) {
        VecCopy(&pipe_pos, &((TObjPlayer *)this->source)->telepipe.state.pos);
    } else {
        traveller = sourceId;
        if (level == 10) {
            VecCopy(&pipe_pos, target);
        } else {
            placement = new PositionPlacementQueue;
            if (placement != NULL) {
                Vec v = lbl_8044D72C;
                TObjBase *owner;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, this->source->rotation_y);
                matrix_mult_vec(0, &v, &v);
                pop_matrices(1);
                owner = this->source;
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
    u16 visit_slot;
    TObjPlayer *traveller_player;
    TObjPlayer *player;
    TObjBase *owner;
    PositionPlacementQueue *queue;
    source = find_entity_by_id(sourceId);
    owner = source;
    if (owner == NULL) {
        queue_destruction();
        return;
    }
    switch (phase) {
    case 0:
        entity_id = owner->get_entity_id();
        if (entity_id != 0xFFFFU) {
            if (entity_id > 0xCU) {
                phase = 4;
                return;
            }
            queue = placement;
            if (queue == NULL) {
                setup_telepipe_field();
                return;
            }
            if (queue->is_first_slot_placed() != 0) {
                VecCopy(&pipe_pos, &source->position);
                if ((telepipe_record_differs(&((TObjPlayer *)source)->telepipe.state, floor, &pipe_pos, traveller) == 0) && ((s8) TTecLuker::visit_counts[sourceId] >= 1)) {
                    queue_destruction();
                    return;
                }
                setup_telepipe_field();
            }
        }
        break;
    case 1:
        visit_slot = sourceId;
        if (visit_slot < 4U) {
            TTecLuker::visit_counts[visit_slot] = TTecLuker::visit_counts[visit_slot] + 1;
        }
        if (telepipe_record_differs(&((TObjPlayer *)source)->telepipe.state, floor, &pipe_pos, traveller) != 0) {
            queue_destruction();
            return;
        }
        play_persistent_sound(0x4002B219, this, &pipe_pos, 0, 0);
        if (field == NULL) {
            queue_destruction();
            return;
        }
        if ((get_player_by_client_id(traveller) != NULL) && (field->get_interacted() != 0) && (are_players_gathered_near(&pipe_pos, 0, 10.0f) != 0)) {
            offset_point_toward_camera(&pipe_pos, (Vec *)&position, 10.0f);
            spawn_particle_effect((const Vec *)&position, 0xB3);
            player = get_player_by_client_id(traveller);
            if (player != NULL) {
                send_impose_hold(player, 0xA);
                play_sound_effect(0x40022D1A, &player->position, 0, 0);
            }
            TWindowCtrl::suppress_all_slots();
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
        owner_id = owner->get_entity_id();
        traveller_player = get_player_by_client_id(traveller);
        if ((is_split_screen() == 0) && (traveller_player != NULL)) {
            if (traveller_player->actorFlags & 0x800) {
                phase = 1;
                TWindowCtrl::unsuppress_all_slots();
                if (field == NULL) {
                    queue_destruction();
                    return;
                }
                field->clear_interacted();
                warp_frames = 0;
                return;
            }
            traveller_player->telepipe.flags.set_bits(owner_id);
            if (TLobby::get_instance() == 1) {
                send_6x21_inter_level_warp(traveller_player, 0);
            } else {
                send_6x21_inter_level_warp(traveller_player, 0);
            }
            goto block_43;
        }
block_43:
        {
        s32 i;
        TObjPlayer *p;
        i = 0;
        do {
            p = get_player_by_client_id(i);
            if (p != NULL) {
                if (is_split_screen() != 0) {
                    p->telepipe.flags.set_bits(owner_id);
                    if (TLobby::get_instance() == 1) {
                        send_6x21_inter_level_warp(p, 0);
                    } else {
                        send_6x21_inter_level_warp(p, 0);
                    }
                } else if (p->obj_isState3_324() != 0) {
                    p->telepipe.flags.set_bits(owner_id);
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
            TWindowCtrl::unsuppress_all_slots();
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
    s32 id = source->get_entity_id();
    visual = new TTelepipeEffect(&pipe_pos, id, tl_07);
    phase = 1;
    if (field != NULL) {
        field->set_position_from(&pipe_pos);
    } else {
        field = new TTelepipeSelectField(&pipe_pos, tl_05, 0);
    }
    if (traveller == source->get_entity_id()) {
        s16 room;
        floor = get_current_floor();
        room = (s32)source->get_room();
        write_telepipe_record(&((TObjPlayer *)source)->telepipe.state, source->get_entity_id(), floor, &pipe_pos, room);
        ((TObjPlayer *)source)->telepipe.state.send_telepipe_packet();
    }
}

void TTecLuker::create(TObjBase *source, Vec *pos, Vec *target, s32 level) {
    new TTecLuker(source, pos, target, level);
}

void TTecLuker::apply_to_target(TObjChara *target) {
    DirectAttackPayload hit;
    hit.kind = 0xE;
    hit.power = 10.0f;
    target->receive_direct_attack(source, hit, 0, -1, -1);
}

#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
TTelepipeEffect::TTelepipeEffect(Vec *at, u32 id, TObject *parent) : TObject(parent) {
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
        VecCopy(&v, &ground_pos);
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
  VecCopy(&v2, &pos);
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

TTelepipeEffect::~TTelepipeEffect() {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (TTecLuker::is_parents_unqueued(particles[i]) != 0) {
            particles[i]->queue_destruction();
            particles[i] = NULL;
        }
    }
    if (marker != NULL) {
        marker->queue_destruction();
        marker = NULL;
    }
}

void TTelepipeEffect::run_task() {
  f32 dist_sq;
  f32 nearest_sq;
  s32 j;
  s32 i;
  s32 area;
  TObjBase *player;
  nearest_sq = 10000.0f;
  j = get_current_floor_area();
  area = j;
  if ((area == 0) || (area == 0x12))
  {
    return;
  }
  if (is_split_screen() != 0)
  {
    for (j = 0; j < 4; j++)
    {
      player = get_player_by_client_id(j);
      if (player != 0)
      {
        dist_sq = horizontal_distance_squared(&pos, &player->position);
        if (dist_sq <= nearest_sq)
        {
          nearest_sq = dist_sq;
        }
      }
    }
    if (nearest_sq >= 102400.0f)
    {
      for (i = 0; i < 3; i++)
      {
        if (TTecLuker::is_parents_unqueued(particles[i]) != 0)
        {
          particles[i]->enable();
          if (marker != 0)
          {
            marker->hide();
          }
        }
      }
      return;
    }
    for (i = 0; i < 3; i++)
    {
      if (TTecLuker::is_parents_unqueued(particles[i]) != 0)
      {
        particles[i]->clear_active_flag();
        if (marker != 0)
        {
          marker->show();
        }
      }
    }
    return;
  }
  if (horizontal_distance_squared(&pos, &camera_ctrl_instance->pos) >= 102400.0f)
  {
    for (i = 0; i < 3; i++)
    {
      if (TTecLuker::is_parents_unqueued(particles[i]) != 0)
      {
        particles[i]->enable();
        if (marker != 0)
        {
          marker->hide();
        }
      }
    }
    return;
  }
  for (i = 0; i < 3; i++)
  {
    if (TTecLuker::is_parents_unqueued(particles[i]) != 0)
    {
      particles[i]->clear_active_flag();
      if (marker != 0)
      {
        marker->show();
      }
    }
  }
}

void handle_6x68_set_telepipe_state(G_SetTelepipeState_6x68 *command) {
    TObjPlayer *player;
    TelepipeState *rec;
    TObjPlayer *other;
    TObjPlayer *local;
    command->bswap();
    if (command->state.owner_client_id == 0xffff) {
        return;
    }
    player = (TObjPlayer *)find_entity_by_id(command->state.owner_client_id);
    if (player == 0) {
        return;
    }
    if (command->state.owner_client_id >= 4) {
        return;
    }
    rec = &player->telepipe.state;
    if (telepipe_record_differs(rec, command->state.floor, &command->state.pos, command->state.owner_client_id) == 0) {
        return;
    }
    write_telepipe_record(rec, command->state.owner_client_id, command->state.floor, &command->state.pos, command->state.room_id);
    if (is_split_screen() == 0 && command->state.owner_client_id == local_client_id) {
        return;
    }
    other = get_player_by_client_id(command->state.owner_client_id);
    local = get_player_by_client_id(local_client_id);
    if (other != 0 && local != 0) {
        if (other->get_floor() == local->get_floor()) {
            TTecLuker::create(player, &player->position, &player->position, 0);
        }
    }
}

void write_telepipe_record(TelepipeState *record, u16 owner, s16 floor, const Vec *pos, s32 room) {
    TObjPlayer *player;
    record->owner_client_id = owner;
    record->floor = floor;
    VecCopy(&record->pos, pos);
    record->room_id = room;
    if (owner <= 4U) {
        player = get_player_by_client_id((s32)((u32) owner));
        if (player != NULL) {
            record->angle_y = player->rotation_y;
        }
    }
}

void TelepipeState::send_telepipe_packet() {
    G_SetTelepipeState_6x68 packet;
    packet.state.owner_client_id = owner_client_id;
    packet.state.room_id = room_id;
    packet.state.floor = floor;
    VecCopy(&packet.state.pos, &pos);
    packet.state.angle_y = angle_y;
    packet.send();
}

void TelepipeState::init_fields(u16 owner) {
    owner_client_id = owner;
    floor = 0;
    room_id = 0;
}

void TelepipeState::reset() {
    owner_client_id = 0xffff;
    room_id = 0;
    floor = 0;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    angle_y = 0;
}

s32 telepipe_record_differs(TelepipeState *r, s16 floor, Vec *p, u16 unused) {
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

s32 PlayerTelepipe::is_placed() {
    if (state.floor != 0) {
        return 1;
    }
    return 0;
}

void restore_floor_telepipes(void) {
    s32 area = get_current_floor_area();
    s32 i;
    if (area == AREA_LOBBY || area == AREA_PIONEER2_EP1 || area == AREA_PIONEER2_EP2) {
        return;
    }
    for (i = 0; i < 4; i++) {
        TObjPlayer *p = get_player_by_client_id(i);
        if (p != 0) {
            if (p->telepipe.state.get_floor() == get_current_floor()) {
                TTecLuker::create(p, &p->position, &p->telepipe.state.pos, 10);
            }
        }
    }
}

const Vec *consume_telepipe_arrival(u16 slot, s32 *heading) {
    TObjPlayer *p;
    u16 owner;
    if (slot >= 4) {
        return 0;
    }
    p = get_player_by_client_id(slot);
    if (p != 0) {
        owner = p->telepipe.flags.get_bits();
        if (owner == 0xffff) {
            return 0;
        }
        p->telepipe.flags.set_bits(0xffff);
        if (get_current_floor_area() == AREA_PIONEER2_EP1) {
            *heading = telepipe_town_heading_table[slot];
            return &telepipe_town_position_table[slot];
        }
        if (get_current_floor_area() == AREA_PIONEER2_EP2) {
            *heading = telepipe_town_heading_table[slot];
            return &telepipe_town_position_table_b[slot];
        }
        p = get_player_by_client_id(owner);
        if (p == 0) {
            return 0;
        }
        *heading = p->telepipe.state.angle_y;
        return &p->telepipe.state.pos;
    }
    return 0;
}

void create_quest_telepipe_for_client(u16 client) {
    TObjPlayer *player;
    player = get_player_by_client_id((s32)((u32) client));
    if (player != NULL) {
        TTecLuker::create(player, &player->position, &player->body_center, 0);
    }
}

void TTecLuker::create_for_player(int client, Vec *pos) {
    TObjPlayer *player = get_player_by_client_id((s32)((u16)client));
    if (player != NULL) {
        TTecLuker::create(player, pos, pos, 0xA);
    }
}

void TTecLuker::apply_all_players() {
    s32 i;
    TObjPlayer *player;

    i = 0;
    do {
        player = get_player_by_client_id(i);
        if (player != NULL) {
            player->telepipe.state.reset();
        }
        i += 1;
    } while (i < 4);
}

TTelepipeSelectField::TTelepipeSelectField(Vec *pos, TObject *parent, s32 always) : TObjCollidable(parent) {
    VecCopy(&position, pos);
    init_collision_body_parts(this, &telepipe_field_collision_body_template, 1);
    set_actor_flags(0x40000000);
    register_object_by_id();
    cursor_action.set_telepipe();
    interacted = 0;
    always_selectable = always;
}

TTelepipeSelectField::~TTelepipeSelectField() {
    unregister_object_by_id();
    free_collision_body_parts(this);
    interacted = 0;
}

void TTelepipeSelectField::run_task() {
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

void TTelepipeSelectField::interact(u16) { interacted = 1; }
