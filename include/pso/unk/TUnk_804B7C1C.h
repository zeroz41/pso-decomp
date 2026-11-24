#ifndef PSO_UNK_TUNK_804B7C1C_H
#define PSO_UNK_TUNK_804B7C1C_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

// The NPC placed by the quest opcode npc_talk_pl (TLobby::create_npc): while
// the local player is within scale.x of it, a TNpcPlayerSpawner brings the
// NPC player into npc_slot; once that player is inactive again and the local
// player has left, the NPC player is removed. set_params[0] is the NPC record,
// set_params[1] the spawn mode and set_params[2] the id npc_talk_kill names.
class TUnk_804B7C1C : public TObjCollidable {
public:
    TUnk_804B7C1C(TObject *parent, void *set_data);
    virtual ~TUnk_804B7C1C();
    virtual void render();
    virtual void run_task();
    u16 npc_slot;  // the client slot the NPC player takes
    u8 pad_ae[0x2];
    s32 record;    // TNpcPlayer::build_npc_player_record argument
    s32 spawned;   // 1 while the NPC player is out
};
LAYOUT_ASSERT(TUnk_804B7C1C_size, sizeof(TUnk_804B7C1C) == 0xB8);

#endif
