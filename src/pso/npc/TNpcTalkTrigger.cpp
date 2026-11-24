#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/npc/TNpcTalkTrigger.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/npc/TNpcPlayerSpawner.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/client_id.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer_801BDF5C.h"
#include "pso/player/TObjPlayer_801C7430.h"
#include "pso/player/TObjPlayer_801AF2F0.h"

CollisionBody npc_player_collision_body_part = {{0.0f, 5.0f, 0.0f}, 7.0f, 50.0f, 0, 0x30003, {0.0f, 0.0f, 0.0f}, 0.0f};

int npc_proximity_target_id = -1;

#pragma defer_codegen on
int hashi_versus2_flag;


// The quest opcodes p_noncol and p_col.
extern "C" {
void clear_hashi_versus2_flag(void) { hashi_versus2_flag = 0; }

void set_hashi_versus2_flag(void) { hashi_versus2_flag = 1; }
}

void set_player_quest_control_flag(TObjPlayer *player) {
    player->set_state_flags(0x8000);
}


void reset_npc_proximity_target_on_floor_load(void) { npc_proximity_target_id = -1; }

void reset_npc_proximity_target_on_floor_free(void) { npc_proximity_target_id = -1; }

void *TLobby::create_npc(void *set_data) {
    return new TNpcTalkTrigger(tl_05, set_data);
}

TNpcTalkTrigger::TNpcTalkTrigger(TObject *parent, void *set_data) : TObjCollidable(parent) {
    apply_object_set_data(set_data);
    npc_slot = 3;
    record = set_params[0];
    spawned = 0;
    init_collision_body_parts(this, &npc_player_collision_body_part, 1);
    register_object_by_id();
}

TNpcTalkTrigger::~TNpcTalkTrigger() {
    unregister_object_by_id();
    free_collision_body_parts(this);
    if (npc_slot != 0xFFFF) {
        TObjPlayer *player = get_player_by_client_id(npc_slot);
        if (player != NULL) {
            delete player;
        }
    }
}

void TNpcTalkTrigger::run_task() {
    TObjPlayer *player;
    if (npc_proximity_target_id == set_params[2]) {
        queue_destruction();
        return;
    }
    player = get_player_by_client_id(local_client_id);
    if (player == NULL) {
        return;
    }
    if (horizontal_distance_squared(&position, &player->position) <= scale.x * scale.x) {
        set_indexed_flags(0, 1);
        if (spawned == 0) {
            spawned = 1;
            new TNpcPlayerSpawner(&position, rotation_y, npc_slot, record, set_params[1], tl_07);
        }
    } else {
        player = get_player_by_client_id(npc_slot);
        if (player != NULL && spawned == 1 && player->is_inactive() == 1) {
            clear_player_status_flag(0, 1);
            spawned = 0;
            player = get_player_by_client_id(npc_slot);
            if (player != NULL) {
                player->TObject::queue_destruction();
            }
        }
    }
}

void TNpcTalkTrigger::render() {  }

void set_npc_proximity_target_id(int id) { npc_proximity_target_id = id; }


TNpcPlayerSpawner::TNpcPlayerSpawner(const Vec *position, s32 heading, s32 slot, s32 record, s32 mode, TObject *parent)
    : TObject(parent) {
    VecCopy(&this->position, position);
    this->heading = heading;
    this->slot = slot;
    this->record = record;
    load_state = 0;
    this->mode = mode;
    TNpcPlayer::ensure_rock_singleton();
    TLobby::request_file_read("npcplayerchar.dat", npc_player_char_data_buffer, (s32 *)&load_state, (void **)0);
}

TNpcPlayerSpawner::~TNpcPlayerSpawner() {
    TObjPlayer *player = create_player_object(slot, 6, TNpcPlayer::build_npc_player_record(record));
    if (player != NULL) {
        player->control_state = 6;
        if (mode == 1) {
            queue_player_injured_pose(player);
            set_player_quest_control_flag(player);
        }
        send_6x24_teleport_player(slot, &position, heading);
    }
}

void TNpcPlayerSpawner::run_task() { if (this->load_state == 1) { queue_destruction(); } }
