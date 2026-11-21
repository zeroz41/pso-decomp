#ifndef PSO_PLAYER_TUNK_804C4540_H
#define PSO_PLAYER_TUNK_804C4540_H
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyInventory.h"

class TPlyCharData;

// The record TUnk_804C4540::create fills from a TPlyCharData and builds the
// player from (inferred role: the ending sequence's player snapshot). Its
// constructor is 0x801D8A4C (spelled TObjPlayer::init_inventory for now).
struct TUnk_801D8A4C {
    u8 visual[0x50];             // copy_player_visual_record
    TPlyInventoryItem items[2];  // TObjPlayer::assign_lobby_slot_if_flagged
    u8 stats[0x24];              // TLobby::copy_data from the TPlyDispData
    u8 pose[0x14];               // position and angle
    s16 pad_C0;
    f32 frame;                   // the motion frame the player starts at
};
LAYOUT_ASSERT(TUnk_801D8A4C_size, sizeof(TUnk_801D8A4C) == 0xC8);

class TUnk_804C4540 : public TObjPlayer {
public:
    TUnk_804C4540(TObject *parent, TUnk_801D8A4C *src);
    virtual ~TUnk_804C4540();
    virtual void run_task();
    virtual void render();
    static TUnk_804C4540 *create(TPlyCharData *data);
    int set_position_from(void *pos);
    void set_animation_default(s16 index);
};
LAYOUT_ASSERT(TUnk_804C4540_size, sizeof(TUnk_804C4540) == 0xDB8);

#endif
