#include "pso/player/PlayerRequirementStats.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/unk/TUnk_804DDD28.h"
#include "pso/system/NinjaTypes.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/PlayerScaleState.h"
#include "pso/render/ChunkMaterialState.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/network/TPlyOnCountOver.h"
#include "pso/system/data/FlagWord.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/TPlyOnCreated.h"
#include "pso/player/TPlayerSoul.h"
#include "pso/player/TPlayerReadyCallback.h"
#include "pso/player/TPlayerLevelFeedback.h"
#include "pso/player/TPlayerLobbyMarker.h"
#include "types.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/object/base/TObjBase.h"



extern "C" {
s32 is_on_current_floor__10TObjPlayerFi(TObjPlayer *player);

}


#include "pso/player/TPlayerParticleOwner.h"
#include "pso/effect/particle/TParticleCtrl.h"


extern "C" {

s32 test_flags_any(s32 *flags, s32 mask);
s32 is_flag30_8_set__10TObjPlayerFi(saddr);


}


extern "C" {
void handle_6x87_shrink_player(const PlayerShrinkPacket* input);
void handle_6x88_restore_shrunken_player(const PlayerRestoreSizePacket* input);
}


extern "C" {
BOOL fn_801C6F2C(u8 *arg0);
s32 TObjPlayer__sub_801BF914(s32);
s32 translate_matrix_vec3(s32, s32);
s32 draw_chunk_object();
s32 TObjPlayer__sub_801C6DAC(u8 *target);
}


#include "pso/system/THeap.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/player/TForceOperate.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/MovementHistory.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"


#undef get_player_by_client_id


#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/system/vector.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/ui/font/TFontSmallLobby_801C013C.h"
#include "pso/network/protocol/subcommand_validation_player.h"
#include "pso/unk/text_8020C354.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/camera/TCameraFollow.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/PlayerTaskEffects.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/effect/TEffect.h"
#include "pso/ui/hud/TMainCursor_8013DF5C.h"
#include "pso/network/client_id.h"
#include "pso/player/TObjPlayer_80011014.h"


extern "C" {
}
void update_player_appear_fade(u8 *arg0);
void reset_player_appearance_opacity(void *a0);
void save_render_material_state(u8 *arg0);

// The marker colours, indexed by TPlayerLobbyMarker::get_material_index().
extern const NJS_ARGB player_lobby_marker_color_table[13] = {
    { 1.0f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 0.0f, 0.0f },
    { 1.0f, 0.0f, 0.0f, 1.0f },
    { 1.0f, 0.0f, 1.0f, 0.0f },
    { 1.0f, 1.0f, 1.0f, 0.0f },
    { 1.0f, 1.0f, 0.0f, 1.0f },
    { 1.0f, 0.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 0.5f, 0.0f },
    { 1.0f, 1.0f, 0.5f, 0.8f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 0.0f, 0.0f, 0.0f },
};

extern const char TPlyOnCreated__class_name_string[] = "TPlyOnCreated";
extern const char TPlyOnCountOver__class_name_string[] = "TPlyOnCountOver";
extern const char TForceOperate__class_name_string[] = "TForceOperate";

const char *TPlyOnCreated__name = TPlyOnCreated__class_name_string;
const char *TPlyOnCountOver__name = TPlyOnCountOver__class_name_string;
const char *TForceOperate__name = TForceOperate__class_name_string;

#pragma defer_codegen on

extern "C" {
extern void *__vt__18TPlayerLobbyMarker[6];
void __ct__7TObjectFP7TObject(TObject *object, TObject *parent);

TPlayerLobbyMarker *__ct__18TPlayerLobbyMarkerFP7TObjectsSc(TPlayerLobbyMarker *marker, TObject *parent, s16 player_id, s8 material_index) {
    __ct__7TObjectFP7TObject(marker, parent);
    *(void ***)((u8 *)marker + 0x18) = __vt__18TPlayerLobbyMarker;
    *(s8 *)&marker->material_index = material_index;
    *(s8 *)&marker->flags = 0;
    *(s16 *)&marker->player_id = player_id;
    marker->rotation = 0;
    return marker;
}
}


u16 PlayerScaleState::get_actor_id() { return actor_id; }


void PlayerCameraOffset::set(f32 x, f32 y, f32 z) { this->x = x; this->y = y; this->z = z; }


Vec *PlayerCameraOffset::get() { return this; }


void PlayerMoveSpeed::set_run_counter(s32 v) { run_counter = v; }


void PlayerMoveSpeed::set_unscaled_speed(f32 v) { unscaled_speed = v; }


void PlayerMoveSpeed::set_speed(f32 v) { speed = v; }


void TPlayerSoul::set_player_id(u16 value) { player_id = value; }

void TPlayerSoul::set_particle(TParticleCtrl*value) { particle = value; }


int BattleMusicState::is_quest_held() { return test_flags_any(&flags, 2); }


int BattleMusicState::set_lock_flag() { return test_flags_any(&flags, 1); }


void BattleMusicState::clear_target_lock_flag() { ((FlagWord *)&flags)->clear(1); }


void BattleMusicState::set_lock_timer(s32 v) { timer = v; }


BOOL fn_801C6F2C(u8 *arg0) {
    return *(s32 *)((s8 *)arg0 + 4) == 1;
}


TForceOperate::~TForceOperate() {}


s32 ContactSurfaceState::get_contact_surface_type() {
    if (has_grass_ground_flag() != 0) {
        return 1;
    }
    if (has_water_ground_flag() != 0) {
        return 2;
    }
    if (test_flag_8() != 0) {
        return 3;
    }
    return set_action_flag16() != 0 ? 4 : 0;
}


void *TUnk_804DDD28::operator new(size_t size) { return obj_heap->heap_alloc(size); }


void TUnk_804DDD28::operator delete(void *p) { obj_heap->heap_free(p); }


s32 TObjPlayer__sub_801C6DAC(u8 *target) {
    *(u8 **)((s8 *)target + 4) = (u8 *)get_player_by_client_id(get_client_id(target));
    if (*(u8 **)((s8 *)target + 4) != NULL) {
        return 1;
    }
    return 0;
}


TPlayerLobbyMarker *TObjPlayer::create_lobby_marker(s16 client, s8 material_index) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player == NULL) {
        return NULL;
    }
    return new TPlayerLobbyMarker(player, client, material_index);
}


void TPlayerLobbyMarker::run_task() { rotation += 0x800; }

void TPlayerLobbyMarker::render() {
    saddr player;
    player = (saddr)get_player_by_client_id(player_id);
    if ((player != 0) && (((TObject *)player)->all_parents_unqueued_for_destruction() != 0) && (get_material_index() != 0) && (((TObjPlayer *)player)->is_body_collision_inactive() == 0)) {
        push_matrix();
        TParticleCtrl::begin_effect_render();
        saved_model_render_flags = model_render_flags;
        copy_argb(&saved_model_draw_color, &model_material_color);
        TObjFish::set_global_param(&shared_effect_texture_list);
        model_render_flags |= 0x11;
        translate_matrix_vec3(0, TObjPlayer__sub_801BF914(player + 0x84C));
        rotate_matrix_y(NULL, camera_ctrl_instance->yaw + rotation);
        scale_matrix(NULL, 1.3f, 1.3f, 1.3f);
        set_constant_material(&player_lobby_marker_color_table[get_material_index()]);
        TMainCursor::get_cursor_state();
        draw_chunk_object();
        copy_argb(&model_material_color, &saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

u8 TPlayerLobbyMarker::get_material_index() {
    if (material_index >= 0xD) material_index = 0;
    return material_index;
}


void PlayerScaleState::request_shrink() {
    TObjPlayer* player = get_player_by_client_id(get_actor_id());
    if (!player || !((TObjChara *)player)->obj_isState2_324()) {
        if (local_client_id == get_actor_id())
            update_camera();
        PlayerShrinkPacket packet;
        packet.header.client_id = get_actor_id();
        packet.scalar = scalar;
        packet.send();
    }
}


void PlayerScaleState::shrink(f32 scalar) {
    flags.set(1);
    this->scalar = scalar;
}


void handle_6x87_shrink_player(const PlayerShrinkPacket* input) {
    PlayerShrinkPacket packet;
    packet.copy_from(input);
    packet.bswap();
    if (validate_6x87_shrink_player(&packet.header)) {
        TObjPlayer* player = get_player_by_client_id(packet.header.client_id);
        if (player && TObjPlayer::check_camera_mode())
            player->scale_state.shrink(packet.scalar);
    }
}


void PlayerScaleState::request_size_restore() {
    TObjPlayer* player = get_player_by_client_id(get_actor_id());
    if (!player || !((TObjChara *)player)->obj_isState2_324()) {
        PlayerRestoreSizePacket packet;
        packet.header.client_id = get_actor_id();
        packet.send();
    }
}


void PlayerScaleState::clear_shrink_flag() { flags.clear(1); }


void handle_6x88_restore_shrunken_player(const PlayerRestoreSizePacket* input) {
    PlayerRestoreSizePacket packet;
    packet.copy_from(input);
    bswap_g_client_id_header(&packet.header);
    if (validate_6x88_restore_shrunken_player(&packet.header)) {
        TObjPlayer* player = get_player_by_client_id(packet.header.client_id);
        if (player && TObjPlayer::check_camera_mode())
            player->scale_state.clear_shrink_flag();
    }
}


void PlayerScaleState::update_camera() {
  camera.position.set(0.0f, 0.6f * (25.43f * get_scalar()), 45.42f * get_scalar());
  camera.target.set(0.0f, 19.8f * get_scalar(), -5.0f);
  request_follow_camera_offsets(camera.target.get(), camera.position.get(), 0xFFFF);
}


void PlayerMoveSpeed::reset() {
    set_speed(1.0f);
    set_run_counter(0);
}


f32 PlayerMoveSpeed::calc_speed(TObjPlayer *player) {
    return calc_speed(player, 1.0f);
}


f32 PlayerMoveSpeed::calc_speed(TObjPlayer *player, f32 speed) {
    if (is_flag30_8_set__10TObjPlayerFi((saddr)player) != 0) {
        speed *= 0.5f;
    } else if (test_flags_any(&flags.bits, 8) != 0) {
        speed *= 0.75f;
    }
    set_unscaled_speed(speed);
    if (player->scale_state.is_scaled() != 0) {
        speed *= player->scale_state.get_scalar();
    }
    return speed;
}


void PlayerMoveSpeed::update(TObjPlayer *player) { set_speed(calc_speed(player)); }


void PlayerMoveSpeed::update(TObjPlayer *player, f32 speed) { set_speed(calc_speed(player, speed)); }


saddr TObjPlayer::get_slot_value(void *equipped_items, int slot) {
    if (slot < 0 || slot >= 13) {
        return 0;
    }
    return ((s32 *)equipped_items)[slot];
}


TPlayerParticleOwner::TPlayerParticleOwner(TObject* parent) : TObject(parent) {
    player_id = 0xFFFF;
    particle = 0;
}

TPlayerParticleOwner::~TPlayerParticleOwner() {
    TParticleCtrl* value = get_particle();
    if (value != 0) {
        value->queue_destruction();
    }
}

TParticleCtrl* TPlayerParticleOwner::get_particle() {
    if (particle != 0 && ((TUnk_804B6C24 *)particle)->check_value_equals((saddr)TParticleCtrl::class_name) == 0) {
        particle = 0;
    }
    return particle;
}

TObjPlayer*TPlayerSoul::get_player() {
    return (TObjPlayer*)get_player_by_client_id(player_id);
}

void TObjPlayer::revive_or_spawn_marker() {
    if ((check_flag_0x8000() != 0) || (obj_isState3_324() != 0) || (is_script_controlled() != 0)) {
        clear_flag_8000();
        return;
    }
    new TPlayerSoul(tl_06, get_entity_id());
}

TPlayerSoul::TPlayerSoul(TObject* parent, u16 id) : TPlayerParticleOwner(parent) {
    set_player_id(id);
    TObjPlayer* player = get_player();
    if (player != 0) {
        TParticleCtrl* value = (TParticleCtrl *)create_particle_emitter((char*)player + 0x2FC, 0xAF);
        if (value != 0) {
            set_particle(value);
        } else {
            queue_destruction();
            return;
        }
    }
}

TPlayerSoul::~TPlayerSoul() {}

void TPlayerSoul::run_task() {
    TObjPlayer *player;
    TParticleCtrl *particle;
    Vec pos;
    player = get_player();
    if (player != NULL && player->test_action_mask(0x8000) != 0 && is_current_area_item_enabled() != 0 &&
        is_on_current_floor__10TObjPlayerFi(player) != 0) {
        particle = get_particle();
        if (particle != 0) {
            player->get_anim_node_position(1, &pos);
            pos.y += 10.0f;
            particle->set_position(&pos);
        }
    } else {
        queue_destruction();
    }
}

void TObjPlayer::new_child_object(u16 player_id) {
    new TPlayerLevelFeedback(tl_07, player_id);
}

TPlayerLevelFeedback::TPlayerLevelFeedback(TObject* parent, u16 id) : TObject(parent) {
    uaddr player;
    player_id = id;
    timer = 10;
    player = (uaddr)get_player_by_client_id(player_id);
    if (player != 0) {
        player = (uaddr)spawn_particle_effect_with_flags((const Vec *)(player + 0x2FC), 0x23, 0x10);
        if (player != 0) ((TParticleCtrl *)player)->set_owner_id(player_id);
    }
}

TPlayerLevelFeedback::~TPlayerLevelFeedback() {}

void TPlayerLevelFeedback::run_task() {
    s32 remaining;
    uaddr player;
    uaddr emitter;
    remaining = timer - 1;
    timer = remaining;
    if (remaining < 0) {
        player = (uaddr)get_player_by_client_id(player_id);
        if (player != 0) {
            emitter = (uaddr)spawn_particle_effect_with_flags((const Vec *)(player + 0x2FC), 0x20, 0x10);
            if (emitter != 0) ((TParticleCtrl *)emitter)->set_owner_id(player_id);
        }
        queue_destruction();
    }
}


void TPlayerReadyCallback::run_task() {
    TObjPlayer* player = (TObjPlayer*)get_player_by_client_id(player_id);
    if (player != NULL && player->model_load_flags == 0) {
        void (*fn)(TObjPlayer*) = callback;
        if (fn != NULL) {
            fn(player);
        }
        queue_destruction();
    }
}

void *TPlyOnCreated::create(s32 client, int (*callback)(void *)) {
    return new TPlyOnCreated(client, callback);
}

TPlyOnCreated::TPlyOnCreated(s32 client, int (*callback)(void *)) : TObject(tl_06) {
    m_name = TPlyOnCreated__name;
    player_id = client;
    this->callback = callback;
}

void TPlyOnCreated::run_task() {
    TObjPlayer *player = get_player_by_client_id(player_id);
    if (player != NULL) {
        int (*fn)(void *) = callback;
        if (fn != NULL) {
            fn(player);
        }
        queue_destruction();
    }
}

void *TPlyOnCountOver::create(u16 player_id, s16 count, void (*callback)(TObjPlayer *)) {
    return new TPlyOnCountOver(player_id, count, callback);
}

TPlyOnCountOver::TPlyOnCountOver(u16 player_id, s16 count, void (*callback)(TObjPlayer *)) : TObject(tl_06) {
    m_name = TPlyOnCountOver__name;
    this->player_id = player_id;
    this->count = count;
    this->callback = callback;
}

void TPlyOnCountOver::run_task() {
    TObjPlayer *player = get_player_by_client_id(player_id);
    if (player == NULL) {
        queue_destruction();
        return;
    }
    if (--count < 0) {
        void (*fn)(TObjPlayer *) = callback;
        if (fn != NULL) {
            fn(player);
        }
        queue_destruction();
    }
}

void clear_movement_history(MovementHistory *history) {
    s32 i;
    MovementHistoryEntry *entry;
    history->index = 0;
    entry = history->entries;
    for (i = 0; i < 16; i++) {
        entry->z = 0.0f;
        entry->x = 0.0f;
        entry++;
    }
}


void set_arrival_override_pos(u16 slot, s32 heading, const Vec *pos) {
    TObjPlayer__arrival_override_table[slot].active = 1;
    TObjPlayer__arrival_override_table[slot].heading = heading;
    VecCopy(&TObjPlayer__arrival_override_table[slot].pos, pos);
}

#pragma push
#pragma opt_common_subs off
void set_arrival_override_coords(u16 slot, s32 heading, f32 x, f32 y, f32 z) {
    s32 offset;
    ArrivalOverride *entry;
    offset = slot * sizeof(ArrivalOverride);
    ((ArrivalOverride *)((u8 *)TObjPlayer__arrival_override_table + offset))->active = 1;
    entry = (ArrivalOverride *)((u8 *)TObjPlayer__arrival_override_table + offset);
    entry->heading = heading;
    entry->pos.x = x;
    entry->pos.y = y;
    entry->pos.z = z;
}
#pragma pop

void set_params__10TObjPlayerFPvPvPviPv(void *out, void *player, player_stats *base_stats, AttackParams *attack_stats, ActorParamBlock *resistance_stats) {
    s16 defense;

    *(s16 *)((s8 *)out + 0) = (s16) (base_stats->stats.atp + get_attack_params_atp_max(attack_stats));
    defense = base_stats->stats.dfp;
    *(s16 *)((s8 *)out + 2) = (s16) (defense + resistance_stats->value_1c);
    *(s16 *)((s8 *)out + 4) = (s16) base_stats->stats.mst;
    *(s16 *)((s8 *)out + 6) = (s16) (0.1f * (f32) (base_stats->stats.ata + ((AttackParams *)(saddr)attack_stats)->get_ata()));
    *(s16 *)((s8 *)out + 8) = (s16) (base_stats->stats.evp + resistance_stats->values[0]);
    *(s16 *)((s8 *)out + 0xA) = (s16) base_stats->stats.lck;
    *(s16 *)((s8 *)out + 0xC) = (s16) resistance_stats->values[1];
    *(s16 *)((s8 *)out + 0xE) = (s16) resistance_stats->values[2];
    *(s16 *)((s8 *)out + 0x10) = (s16) resistance_stats->values[3];
    *(s16 *)((s8 *)out + 0x12) = (s16) resistance_stats->values[4];
    *(s16 *)((s8 *)out + 0x14) = (s16) resistance_stats->values[5];
}

void init_shield_params(void *out, void *player, player_stats *base_stats, AttackParams *attack_stats, ActorParamBlock *resistance_stats) {
    set_params__10TObjPlayerFPvPvPviPv(out, player, base_stats, attack_stats, resistance_stats);
    *(s16 *)((s8 *)out + 0x16) = ((TObjChara *)player)->get_hpmax();
    *(s16 *)((s8 *)out + 0x18) = obj_getS16_2BA((u8 *)player);
}

void TObjPlayer::calc_pos_delta(void *other, void *delta) {
    *(s16 *)((s8 *)delta + 0) = (s16) (*(s16 *)((s8 *)other + 0) - *(s16 *)((s8 *)this + 0));
    *(s16 *)((s8 *)delta + 2) = (s16) (*(s16 *)((s8 *)other + 2) - *(s16 *)((s8 *)this + 2));
    *(s16 *)((s8 *)delta + 4) = (s16) (*(s16 *)((s8 *)other + 4) - *(s16 *)&this->m_flags);
    *(s16 *)((s8 *)delta + 6) = (s16) (*(s16 *)((s8 *)other + 6) - *(s16 *)&this->m_id);
    *(s16 *)((s8 *)delta + 8) = (s16) (*(s16 *)((s8 *)other + 8) - *(s16 *)((s8 *)this + 8));
    *(s16 *)((s8 *)delta + 0xA) = (s16) (*(s16 *)((s8 *)other + 0xA) - *(s16 *)((s8 *)this + 0xA));
    *(s16 *)((s8 *)delta + 0x16) = (s16) (*(s16 *)((s8 *)other + 0x16) - *(s16 *)((s8 *)this + 0x16));
    *(s16 *)((s8 *)delta + 0x18) = (s16) (*(s16 *)((s8 *)other + 0x18) - *(s16 *)((s8 *)this + 0x18));
}

#pragma fp_contract on
void TObjPlayer::copy_offset_position(void *chara) {
    f32 temp_f2;

    temp_f2 = ((TObjPlayer *)chara)->get_stats()->proportions;
    *(f32 *)((s8 *)this + 0) = (f32) ((TObjPlayer *)chara)->position.x;
    *(f32 *)((s8 *)this + 4) = (f32) ((1.2f * temp_f2) + ((TObjPlayer *)chara)->position.y);
    *(f32 *)((s8 *)this + 8) = (f32) ((TObjPlayer *)chara)->position.z;
}

s32 TObjPlayer::decrement_clamp(s32 *value, s32 amount) {
    *value -= amount;
    if (*value < 0) {
        *value = 0;
        return 0;
    }
    return 1;
}

void BattleMusicState::update_target_lock(TObjPlayer *player) {
    if (is_quest_held() == 0) {
        if (is_room_free_of_active_enemies(get_current_floor(), player->get_room()) != 0) {
            if (set_lock_flag() != 0) {
                clear_target_lock_flag();
                set_lock_timer(0x5A);
                return;
            }
            if (tick_battle_music_timer() == 0) {
                reset_ring();
            }
        } else if (set_lock_flag() == 0) {
            clear_target_lock();
        }
    }
}

s32 BattleMusicState::tick_battle_music_timer() {
    if (timer < 0) {
        return 1;
    }
    return --timer < 0 ? 0 : 1;
}

void BattleMusicState::clear_target_lock() { ((FlagWord *)&flags)->set(1); TLobby::set_target_id(1); }

void BattleMusicState::reset_ring() { ((FlagWord *)&flags)->clear(1); set_lock_timer(-1); TLobby::set_target_id(0); }

void TObjPlayer::set_vec4_const() { *(float*)((char*)this + 0x1c) = 1.0f; *(float *)&this->m_20 = 1.0f; *(float *)&this->texlist = 1.0f; *(float *)&this->room = 1.0f; }

void save_render_material_state(u8 *state) {
    *(s32 *)((s8 *)state + 0) = (s32) model_render_flags;
    *(s32 *)((s8 *)state + 4) = (s32) chunk_polygon_flags_and_mask;
    *(s32 *)((s8 *)state + 8) = (s32) chunk_polygon_flags_or_mask;
    copy_argb((NJS_ARGB *)(state + 0xC), &model_material_color);
}

void TObjPlayer::write_ids() { set_model_render_flags((saddr)this->m_name); set_chunk_material_override_pair((saddr)(*(void**)((char*)this + 0x4)), (saddr)this->m_prev); set_constant_material((const NJS_ARGB *)(((char*)this + 0xc))); }

void reset_player_appearance_opacity(void* a0) { *(float*)((char*)a0 + 0x1c) = 1.0f; }

void TObjPlayer::enter_battle_state() {
    saddr player;

    player = (saddr)get_player_by_client_id(*(u16 *)((s8 *)this + 0));
    if ((player != 0) && (fn_801C6F2C((u8 *)this) == 0)) {
        *(s32 *)((s8 *)this + 4) = 0;
        ((TObjPlayer *)player)->deactivate_body_collision();
        *(s16 *)((s8 *)this + 2) = 4;
    }
}

#pragma push
#pragma opt_common_subs off
void update_player_appear_fade(u8 *arg0) {
    f32 var_f31;
    u8 *player;
    player = (u8 *)(get_player_by_client_id(*(u16 *)((s8 *)arg0 + 0)));
    if (player != NULL) {
        switch (*(s32 *)((s8 *)arg0 + 4)) {
        case 2:
        default:
            break;
        case 0:
            if ((((TObjPlayer *)player)->is_inactive() != 0) && (((TObjPlayer *)player)->check_flag_40000() == 0) && (((TObjPlayer *)player)->check_flag_04000000() != 0) && (is_on_current_floor__10TObjPlayerFi((TObjPlayer *)player) != 0)) {
                if (--*(s16 *)((s8 *)arg0 + 2) < 0) {
                    if (TCameraCtrl::get_mode() != 0) {
                        ((TObjPlayer *)player)->render_material_state.alpha = 1.0f;
                        *(s32 *)((s8 *)arg0 + 4) = 2;
                        return;
                    }
                    *(s32 *)((s8 *)arg0 + 4) = 1;
                    ((TObjPlayer *)player)->activate_body_collision();
                    if (((TObjCollidable *)player)->test_actor_flags(0x800) == 0) {
                        TObjPlayer::spawn_appearance_effect((int) (*(u16 *)((s8 *)arg0 + 0)));
                    }
                    ((TObjPlayer *)player)->render_material_state.alpha = 0.0f;
                    ((TObjPlayer *)player)->refresh_equipment_slot();
                    return;
                }
            }
            break;
        case 1:
            var_f31 = ((TObjPlayer *)player)->render_material_state.alpha;
            var_f31 += 0.1f;
            if (var_f31 >= 1.0f) {
                var_f31 = 1.0f;
                *(s32 *)((s8 *)arg0 + 4) = 2;
                ((TObjPlayer *)player)->set_visible_flag();
                ((TObjPlayer *)player)->activate_body_collision();
            }
            ((TObjPlayer *)player)->render_material_state.alpha = var_f31;
            break;
        }
    }
}
#pragma pop

void PlayerDeathSink::update_offset() { offset = height * progress; }

#pragma push
#pragma opt_common_subs off
void PlayerDeathSink::calc_height(TObjPlayer *player) {
    Vec node;
    player->get_anim_node_position(1, &node);
    height = (1.0f + player->position.y) - node.y;
    if (height > 3.0f) {
        height = 3.0f;
    }
    if (height < -4.0f) {
        height = -4.0f;
    }
}
#pragma pop

TForceOperate::TForceOperate(TObject *parent, u16 id) : TObject(parent) {
    m_name = TForceOperate__name;
    m_1c.set_field_0(id);
}

void TForceOperate::run_task() {
    void *state;
    TObjCollidable *entity;

    if (TObjPlayer__sub_801C6DAC((u8 *)&m_1c) != 0) {
        state = (void *)((TMainCursor *)(&m_1c))->get_state();
        if ((((TObjPlayer *)state)->is_target_valid() != 0) && (((TObjPlayer *)state)->has_action_palette_entry() != 0)) {
            entity = find_entity_by_id(((TMainCursor *)&((TObjPlayer *)state)->lock_on_cursor->selection.target)->get_id());
            if (entity != NULL) {
                entity->interact(((TObjBase *)((saddr)state))->get_entity_id());
                queue_destruction();
            }
        }
    }
}

#pragma defer_codegen off

int ContactSurfaceState::set_action_flag16() { return test_flags_any(&word.bits, 16); }


int ContactSurfaceState::test_flag_8() { return test_flags_any(&word.bits, 8); }


int ContactSurfaceState::has_grass_ground_flag() { return test_flags_any(&word.bits, 2); }


#pragma defer_codegen on
TPlayerReadyCallback::~TPlayerReadyCallback() {}

TPlyOnCreated::~TPlyOnCreated() {}

TPlyOnCountOver::~TPlyOnCountOver() {}

#pragma defer_codegen off

TPlayerLobbyMarker::~TPlayerLobbyMarker() {}

void TObjPlayer::set_visible_flag() { set_state_flags(0x200000); }
s32 TObjPlayer::check_flag_04000000() { return check_flag((saddr)((void*)4194304)); }
void TObjPlayer::clear_flag_8000() { clear_state_flags((saddr)((void*)32768)); }
s32 TObjPlayer::check_flag_0x8000() { return check_flag(0x8000); }
PlayerRestoreSizePacket *PlayerRestoreSizePacket::copy_from(const PlayerRestoreSizePacket *src) {
    copy_subcommand_header(this, (void *)src);
    return this;
}

PlayerRestoreSizePacket::PlayerRestoreSizePacket() {
    header.subcommand = 0x88;
    header.size = 1;
}

void PlayerRestoreSizePacket::send() {
    bswap_g_client_id_header(this);
    send_subcommand(this);
}

void PlayerShrinkPacket::bswap() {
    header.bswap();
    bswap_32((u32 *)&scalar);
}

PlayerShrinkPacket *PlayerShrinkPacket::copy_from(const PlayerShrinkPacket *src) {
    copy_subcommand_header(this, (void *)src);
    scalar = src->scalar;
    return this;
}

PlayerShrinkPacket::PlayerShrinkPacket() {
    scalar = 1.0f;
    header.subcommand = 0x87;
    header.size = 2;
}

void PlayerShrinkPacket::send() {
    bswap();
    send_subcommand(this);
}
u16 TObjPlayer::interpolate_angle(void *unused, u16 from, u16 to, s32 *step) {
    s16 diff;
    s32 turn;
    diff = (s16)((u16)to - from);
    if (diff > -0x3000 && diff < 0x3000) {
        turn = (diff >> 4) - (diff >> 5);
    } else {
        turn = diff >> 4;
    }
    *step = turn;
    return (u16)(from + turn);
}
