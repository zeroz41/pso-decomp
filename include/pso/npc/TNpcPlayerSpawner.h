#ifndef PSO_NPC_TNPCPLAYERSPAWNER_H
#define PSO_NPC_TNPCPLAYERSPAWNER_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

// Made by TNpcTalkTrigger when the local player comes near: waits for
// npcplayerchar.dat to load, then its destructor creates the NPC player in
// slot and teleports it to position.
class TNpcPlayerSpawner : public TObject {
public:
    TNpcPlayerSpawner(const Vec *position, s32 heading, s32 slot, s32 record, s32 mode, TObject *parent);
    virtual ~TNpcPlayerSpawner();
    virtual void run_task();
    Vec position;
    s32 heading;
    int load_state;  // request_file_read status, 1 once loaded
    u16 slot;
    s32 record;      // TNpcPlayer::build_npc_player_record argument
    s32 mode;        // 1: injured pose and quest control flag
};
LAYOUT_ASSERT(TNpcPlayerSpawner_size, sizeof(TNpcPlayerSpawner) == 0x3C);

#endif
