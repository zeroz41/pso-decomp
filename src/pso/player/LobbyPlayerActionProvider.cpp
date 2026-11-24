#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/player/PlayerActionProvider.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/LobbyPlayerActionProvider.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResource.h"

const TObjMotionAction lobby_male_actions[56] = {
    {MOTION_MODE_LOOP, -1, 0, 0.9f, 0x1},
    {MOTION_MODE_LOOP, -1, 1, 1.4f, ACTION_INTERPOLATE | 0x2},
    {MOTION_MODE_LOOP, -1, 2, 0.8f, ACTION_INTERPOLATE | 0x2},
    {MOTION_MODE_LOOP, -1, 3, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_LOOP, -1, 4, 1.0f, ACTION_INTERPOLATE | 0x2},
    {MOTION_MODE_LOOP, -1, 5, 0.8f, ACTION_INTERPOLATE | 0x2},
    {MOTION_MODE_ONCE, -1, 6, 1.4f, ACTION_INTERPOLATE | 0x40},
    {MOTION_MODE_ONCE, -1, 7, 3.7f, ACTION_INTERPOLATE | 0x40},
    {MOTION_MODE_ONCE, -1, 8, 1.3f, ACTION_INTERPOLATE | 0x400},
    {MOTION_MODE_ONCE, -1, 9, 3.0f, ACTION_INTERPOLATE | 0x10},
    {MOTION_MODE_ONCE, -1, 10, 1.2f, ACTION_INTERPOLATE | 0x4},
    {MOTION_MODE_ONCE, -1, 11, 1.1f, ACTION_INTERPOLATE | 0x4},
    {MOTION_MODE_ONCE, -1, 12, 1.3f, ACTION_INTERPOLATE | 0x4},
    {MOTION_MODE_ONCE, -1, 13, 1.4f, ACTION_INTERPOLATE | 0x4},
    {MOTION_MODE_ONCE, -1, 14, 1.5f, ACTION_INTERPOLATE | 0x4},
    {MOTION_MODE_ONCE, -1, 15, 1.5f, ACTION_INTERPOLATE | 0x4},
    {MOTION_MODE_ONCE, -1, 16, 1.4f, ACTION_INTERPOLATE | 0x8},
    {MOTION_MODE_ONCE, -1, 17, 1.4f, ACTION_INTERPOLATE | 0x8},
    {MOTION_MODE_ONCE, -1, 18, 1.0f, 0x80},
    {MOTION_MODE_ONCE, -1, 19, 0.8f, 0x1},
    {MOTION_MODE_ONCE, -1, 20, 1.0f, ACTION_INTERPOLATE | 0x8},
    {MOTION_MODE_ONCE, -1, 21, 1.0f, ACTION_INTERPOLATE | 0x8},
    {MOTION_MODE_ONCE, -1, 22, 1.0f, ACTION_INTERPOLATE | 0x8},
    {MOTION_MODE_ONCE, -1, 23, 1.0f, ACTION_INTERPOLATE | 0x8},
    {MOTION_MODE_ONCE, -1, 24, 1.0f, ACTION_INTERPOLATE | 0x8},
    {MOTION_MODE_ONCE, -1, 25, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 26, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 27, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 28, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 29, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 30, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 31, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 32, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 33, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 34, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 35, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 36, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 37, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 38, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 39, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 40, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 41, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 42, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 43, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 44, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 45, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 46, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 47, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_CHAIN, 54, 48, 1.0f, ACTION_INTERPOLATE | 0x10000001},
    {MOTION_MODE_CHAIN, 55, 49, 1.0f, ACTION_INTERPOLATE | 0x10000001},
    {MOTION_MODE_ONCE, -1, 50, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 51, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 52, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 53, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_LOOP, -1, 54, 0.7f, ACTION_INTERPOLATE | 0x10000001},
    {MOTION_MODE_LOOP, -1, 55, 0.7f, ACTION_INTERPOLATE | 0x10000001},
};
const TObjMotionAction lobby_female_actions[56] = {
    {MOTION_MODE_LOOP, -1, 0, 1.0f, 0x1},
    {MOTION_MODE_LOOP, -1, 1, 1.0f, ACTION_INTERPOLATE | 0x2},
    {MOTION_MODE_LOOP, -1, 2, 0.8f, ACTION_INTERPOLATE | 0x2},
    {MOTION_MODE_LOOP, -1, 3, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_LOOP, -1, 4, 1.0f, ACTION_INTERPOLATE | 0x2},
    {MOTION_MODE_LOOP, -1, 5, 0.8f, ACTION_INTERPOLATE | 0x2},
    {MOTION_MODE_ONCE, -1, 6, 1.5f, ACTION_INTERPOLATE | 0x40},
    {MOTION_MODE_ONCE, -1, 7, 3.7f, ACTION_INTERPOLATE | 0x40},
    {MOTION_MODE_ONCE, -1, 8, 1.3f, ACTION_INTERPOLATE | 0x400},
    {MOTION_MODE_ONCE, -1, 9, 3.0f, ACTION_INTERPOLATE | 0x10},
    {MOTION_MODE_ONCE, -1, 10, 1.4f, ACTION_INTERPOLATE | 0x4},
    {MOTION_MODE_ONCE, -1, 11, 1.1f, ACTION_INTERPOLATE | 0x4},
    {MOTION_MODE_ONCE, -1, 12, 1.3f, ACTION_INTERPOLATE | 0x4},
    {MOTION_MODE_ONCE, -1, 13, 1.4f, ACTION_INTERPOLATE | 0x4},
    {MOTION_MODE_ONCE, -1, 14, 1.5f, ACTION_INTERPOLATE | 0x4},
    {MOTION_MODE_ONCE, -1, 15, 1.7f, ACTION_INTERPOLATE | 0x4},
    {MOTION_MODE_ONCE, -1, 16, 1.4f, ACTION_INTERPOLATE | 0x8},
    {MOTION_MODE_ONCE, -1, 17, 1.4f, ACTION_INTERPOLATE | 0x8},
    {MOTION_MODE_ONCE, -1, 18, 1.0f, 0x80},
    {MOTION_MODE_ONCE, -1, 19, 0.8f, 0x1},
    {MOTION_MODE_ONCE, -1, 20, 1.0f, ACTION_INTERPOLATE | 0x8},
    {MOTION_MODE_ONCE, -1, 21, 1.0f, ACTION_INTERPOLATE | 0x8},
    {MOTION_MODE_ONCE, -1, 22, 1.0f, ACTION_INTERPOLATE | 0x8},
    {MOTION_MODE_ONCE, -1, 23, 1.0f, ACTION_INTERPOLATE | 0x8},
    {MOTION_MODE_ONCE, -1, 24, 1.0f, ACTION_INTERPOLATE | 0x8},
    {MOTION_MODE_ONCE, -1, 25, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 26, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 27, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 28, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 29, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 30, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 31, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 32, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 33, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 34, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 35, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 36, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 37, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 38, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 39, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 40, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 41, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 42, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 43, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 44, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 45, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 46, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 47, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_CHAIN, 54, 48, 1.0f, ACTION_INTERPOLATE | 0x10000001},
    {MOTION_MODE_CHAIN, 55, 49, 1.0f, ACTION_INTERPOLATE | 0x10000001},
    {MOTION_MODE_ONCE, -1, 50, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 51, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 52, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_ONCE, -1, 53, 1.0f, ACTION_INTERPOLATE | 0x1},
    {MOTION_MODE_LOOP, -1, 54, 0.7f, ACTION_INTERPOLATE | 0x10000001},
    {MOTION_MODE_LOOP, -1, 55, 0.7f, ACTION_INTERPOLATE | 0x10000001},
};
const s32 lobby_male_motion_files[56] = {
    201, 200, 207, 201, 200, 207, 202, 204,
    109, 199, 196, 153, 91, 155, 178, 173,
    194, 126, 205, 174, 187, 137, 206, 164,
    87, 208, 209, 210, 211, 212, 213, 214,
    215, 216, 217, 218, 219, 220, 221, 222,
    223, 224, 225, 226, 227, 228, 229, 230,
    231, 232, 233, 234, 235, 236, 237, 238,
};
const s32 lobby_female_motion_files[56] = {
    335, 412, 416, 487, 506, 508, 359, 413,
    340, 411, 408, 369, 321, 371, 389, 384,
    406, 357, 414, 385, 399, 363, 415, 341,
    317, 417, 418, 419, 420, 421, 422, 423,
    424, 425, 426, 427, 428, 429, 430, 431,
    432, 433, 434, 435, 436, 437, 438, 439,
    440, 441, 233, 234, 235, 236, 442, 443,
};
const TObjMotionAction * lobby_male_action_tables[19] = {
    lobby_male_actions, lobby_male_actions, lobby_male_actions, lobby_male_actions,
    lobby_male_actions, lobby_male_actions, lobby_male_actions, lobby_male_actions,
    lobby_male_actions, lobby_male_actions, lobby_male_actions, lobby_male_actions,
    lobby_male_actions, lobby_male_actions, lobby_male_actions, lobby_male_actions,
    lobby_male_actions, lobby_male_actions, lobby_male_actions,
};
const TObjMotionAction * lobby_female_action_tables[19] = {
    lobby_female_actions, lobby_female_actions, lobby_female_actions, lobby_female_actions,
    lobby_female_actions, lobby_female_actions, lobby_female_actions, lobby_female_actions,
    lobby_female_actions, lobby_female_actions, lobby_female_actions, lobby_female_actions,
    lobby_female_actions, lobby_female_actions, lobby_female_actions, lobby_female_actions,
    lobby_female_actions, lobby_female_actions, lobby_female_actions,
};
__declspec(section ".data") const TObjMotionAction ** lobby_action_tables[2] = {
    lobby_male_action_tables, lobby_female_action_tables,
};
const s32 * lobby_male_motion_file_tables[19] = {
    lobby_male_motion_files, lobby_male_motion_files, lobby_male_motion_files, lobby_male_motion_files,
    lobby_male_motion_files, lobby_male_motion_files, lobby_male_motion_files, lobby_male_motion_files,
    lobby_male_motion_files, lobby_male_motion_files, lobby_male_motion_files, lobby_male_motion_files,
    lobby_male_motion_files, lobby_male_motion_files, lobby_male_motion_files, lobby_male_motion_files,
    lobby_male_motion_files, lobby_male_motion_files, lobby_male_motion_files,
};
const s32 * lobby_female_motion_file_tables[19] = {
    lobby_female_motion_files, lobby_female_motion_files, lobby_female_motion_files, lobby_female_motion_files,
    lobby_female_motion_files, lobby_female_motion_files, lobby_female_motion_files, lobby_female_motion_files,
    lobby_female_motion_files, lobby_female_motion_files, lobby_female_motion_files, lobby_female_motion_files,
    lobby_female_motion_files, lobby_female_motion_files, lobby_female_motion_files, lobby_female_motion_files,
    lobby_female_motion_files, lobby_female_motion_files, lobby_female_motion_files,
};
__declspec(section ".data") const s32 ** town_player_motion_clip_index_tables[2] = {
    lobby_male_motion_file_tables, lobby_female_motion_file_tables,
};

BmlMotionEntry lobby_male_motions[56];
BmlMotionEntry lobby_female_motions[56];

u8 *lobby_action_motion_buffer;
FlagWord lobby_loaded_motion_sets;

int LobbyPlayerActionProvider::get_run_action() {
    s32 t = ((TObjPlayer *)this)->is_handle_valid();
    s32 r = 2;
    if (t == 2) {
        r = 5;
    }
    return r;
}

int LobbyPlayerActionProvider::get_walk_action() {
    s32 t = ((TObjPlayer *)this)->is_handle_valid();
    s32 r = 1;
    if (t == 2) {
        r = 4;
    }
    return r;
}

int LobbyPlayerActionProvider::get_idle_action() {
    return ((((TObjPlayer *)this)->is_handle_valid() - 2) == 0) ? 3 : 0;
}

u8 *LobbyPlayerActionProvider::get_cell_address(s32 set, s32 slot) {
    return lobby_action_motion_buffer + ((slot + (set * get_motion_count())) << 0xE);
}

int LobbyPlayerActionProvider::get_gender(s32 body_type) {
    switch (body_type) {
    case 0:
    case 3:
        return 0;
    case 1:
    case 2:
    case 4:
    case 5:
        return 1;
    default:
        return 0;
    }
}

int LobbyPlayerActionProvider::get_gender() {
    return get_gender(((TObjPlayer *)this)->is_handle_valid());
}

BmlMotionEntry *LobbyPlayerActionProvider::get_current_motion_list() {
    return get_motion_list(((TObjPlayer *)this)->is_handle_valid());
}

BmlMotionEntry *LobbyPlayerActionProvider::get_motion_list(s32 body_type) {
    switch (get_gender(body_type)) {
    case 0:
        return lobby_male_motions;
    case 1:
        return lobby_female_motions;
    default:
        return NULL;
    }
}

int LobbyPlayerActionProvider::get_motion_file(s32 body_type, s32 motion_type, s32 slot) {
    return town_player_motion_clip_index_tables[body_type][motion_type][slot];
}

const s32 *LobbyPlayerActionProvider::get_motion_files(s32 body_type, s32 motion_type) {
    if (is_valid_body_type(body_type) == 0) {
        return NULL;
    }
    if (is_valid_motion_type(motion_type) != 0) {
        return town_player_motion_clip_index_tables[body_type][motion_type];
    }
    return NULL;
}

const TObjMotionAction *LobbyPlayerActionProvider::get_motion_actions(s32 body_type, s32) {
    s32 gender = get_gender(body_type);
    if (is_valid_body_type(gender) != 0) {
        return *lobby_action_tables[gender];
    }
    return NULL;
}

int LobbyPlayerActionProvider::load_motion_set(s32, s32, s32) { return 1; }

int LobbyPlayerActionProvider::load_motions(s32) {
    if (male_motions_loaded() == 0) {
        set_male_motions_loaded();
        load_action_motion_pairs(0, 0, 0);
    }
    if (female_motions_loaded() == 0) {
        set_female_motions_loaded();
        load_action_motion_pairs(1, 1, 0);
    }
    return 1;
}

void free_lobby_action_motion_buffer() {
    if (lobby_action_motion_buffer != NULL) {
        mem_free(lobby_action_motion_buffer);
        lobby_action_motion_buffer = NULL;
    }
}

u8 *alloc_lobby_action_motion_buffer() {
    return lobby_action_motion_buffer = (u8 *)mem_alloc(0x1C0000);
}

void release_lobby_player_actions() {
    TPlyPhotonChair::free_static_model();
    free_lobby_action_motion_buffer();
    set_player_action_provider_selector(0);
    LobbyPlayerActionProvider::clear_loaded_motions();
}

void init_lobby_player_actions() {
    set_player_action_provider_selector(0);
    if (alloc_lobby_action_motion_buffer() == NULL) {
        set_player_action_provider_selector(1);
        return;
    }
    TPlyPhotonChair::load_resources();
}

LobbyPlayerActionProvider::~LobbyPlayerActionProvider() {}

LobbyPlayerActionProvider::LobbyPlayerActionProvider() {}
