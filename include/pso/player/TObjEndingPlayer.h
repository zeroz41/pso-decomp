#ifndef PSO_PLAYER_TOBJENDINGPLAYER_H
#define PSO_PLAYER_TOBJENDINGPLAYER_H
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyInventory.h"
#include "pso/player/PlayerTaskEffects.h"

class TPlyCharData;

// The record TObjEndingPlayer::create fills from a TPlyCharData and builds the
// player from (inferred role: the ending sequence's player snapshot).
// The weapon and mag copy_equipped_weapon_and_mag copies out of the inventory.
struct EquippedWeaponAndMag {
    TPlyInventoryItem items[2];  // TObjEndingPlayer::assign_lobby_slot_if_flagged

    EquippedWeaponAndMag();
};

// Where the ending player's motion starts.
struct EndingMotionStart {
    s16 pad_0;
    f32 frame;  // the motion frame the player starts at

    EndingMotionStart();
};

struct EndingPlayerRecord {
    u8 visual[0x50];                 // copy_player_visual_record
    EquippedWeaponAndMag equipment;
    player_stats stats;              // copied from the TPlyCharData
    ArrivalOverride pose;            // position and angle
    EndingMotionStart motion;

    EndingPlayerRecord();
};
LAYOUT_ASSERT(EndingPlayerRecord_size, sizeof(EndingPlayerRecord) == 0xC8);

class TObjEndingPlayer : public TObjPlayer {
public:
    TObjEndingPlayer(TObject *parent, EndingPlayerRecord *src);
    virtual ~TObjEndingPlayer();
    virtual void run_task();
    virtual void render();
    static TObjEndingPlayer *create(TPlyCharData *data);
    int set_position_from(void *pos);
    void set_animation_default(s16 index);
    void set_animation_from_data(s32 picture);
    void assign_lobby_slot_if_flagged(TPlyInventoryItem *item);
};
LAYOUT_ASSERT(TObjEndingPlayer_size, sizeof(TObjEndingPlayer) == 0xDB8);

// The ending scene's load and release hooks for the players' motion data.
void create_player_ending_motion();
void free_player_ending_motion();

#endif
