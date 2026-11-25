#ifndef PSO_PLAYER_TOBJENDINGPLAYER_H
#define PSO_PLAYER_TOBJENDINGPLAYER_H
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyInventory.h"

class TPlyCharData;

// The record TObjEndingPlayer::create fills from a TPlyCharData and builds the
// player from (inferred role: the ending sequence's player snapshot).
struct EndingPlayerRecord {
    u8 visual[0x50];             // copy_player_visual_record
    TPlyInventoryItem items[2];  // TObjPlayer::assign_lobby_slot_if_flagged
    u8 stats[0x24];              // TLobby::copy_data from the TPlyDispData
    u8 pose[0x14];               // position and angle
    s16 pad_C0;
    f32 frame;                   // the motion frame the player starts at

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
};
LAYOUT_ASSERT(TObjEndingPlayer_size, sizeof(TObjEndingPlayer) == 0xDB8);

#endif
