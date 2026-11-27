#ifndef PSO_OBJECT_ENDING_TOBJONLINEENDING_H
#define PSO_OBJECT_ENDING_TOBJONLINEENDING_H

#include "types.h"
#include <stddef.h>
#include "pso/object/base/TObjMotion.h"

struct TWindowChallengeResult;

struct NJS_MOTION;
struct NJS_TEXLIST;
struct NJS_OBJECT;

struct OnlineEndingPlayerPlacement {
    Vec position;
    s32 yaw;
    f32 scale;
};

struct OnlineEndingPlayer {
    s32 active;
    u16 id;
    char name[0x12];
    const Vec *position;
    s32 yaw;
    f32 scale;
    NJS_MOTION *motion;
};

LAYOUT_ASSERT(OnlineEndingPlayerSize, sizeof(OnlineEndingPlayer) == 0x28);

struct TObjOnlineEnding : public TObjBase {
    TObjOnlineEnding(TObject *parent);
    virtual ~TObjOnlineEnding();
    virtual void render();
    virtual void run_task();
    NJS_OBJECT *scene_model;
    NJS_TEXLIST *scene_textures;
    NJS_MOTION *scene_motion;
    s32 ending_variant;
    s32 ending_area;
    s32 scene_state;
    OnlineEndingPlayer players[4];
    s32 player_count;
    s32 elapsed_frames;
    static s32 get_card_window_value();
    static int get_instance();
    static void *get_attack_entry(int index);
    void close_window();
    void create_result_window();
    static void *create(void *parent);
    f32 scene_frame;
    TWindowChallengeResult *result_window;
};

LAYOUT_ASSERT(TObjOnlineEnding_size, sizeof(TObjOnlineEnding) == 0x158);
LAYOUT_ASSERT(OnlineEndingPlayersOffset, offsetof(TObjOnlineEnding, players) == 0xA8);
LAYOUT_ASSERT(OnlineEndingPlayerCountOffset, offsetof(TObjOnlineEnding, player_count) == 0x148);
LAYOUT_ASSERT(OnlineEndingResultWindowOffset, offsetof(TObjOnlineEnding, result_window) == 0x154);

extern int player_unique_pair_entry_count;
extern ActorBodyHit player_unique_pair_entries[16];

void load_online_ending_resource();

#endif
