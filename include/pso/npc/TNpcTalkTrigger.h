#ifndef PSO_NPC_TNPCTALKTRIGGER_H
#define PSO_NPC_TNPCTALKTRIGGER_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjPlayer;

// The NPC placed by the quest opcode npc_talk_pl (TLobby::create_npc): while
// the local player is within scale.x of it, a TNpcPlayerSpawner brings the
// NPC player into npc_slot; once that player is inactive again and the local
// player has left, the NPC player is removed. set_params[0] is the NPC record,
// set_params[1] the spawn mode and set_params[2] the id npc_talk_kill names.
class TNpcTalkTrigger : public TObjCollidable {
public:
    TNpcTalkTrigger(TObject *parent, void *set_data);
    virtual ~TNpcTalkTrigger();
    virtual void render();
    virtual void run_task();
    u16 npc_slot;  // the client slot the NPC player takes
    u8 pad_ae[0x2];
    s32 record;    // TNpcPlayer::build_npc_player_record argument
    s32 spawned;   // 1 while the NPC player is out
};
LAYOUT_ASSERT(TNpcTalkTrigger_size, sizeof(TNpcTalkTrigger) == 0xB8);

// npc_talk_kill: every trigger whose set_params[2] is id removes itself.
void set_npc_proximity_target_id(int id);
// The floor load and release callbacks: no trigger is being removed.
void reset_npc_proximity_target_on_floor_load(void);
void reset_npc_proximity_target_on_floor_free(void);
// Puts the player under quest control (state flag 0x8000).
void set_player_quest_control_flag(TObjPlayer *player);

#endif
