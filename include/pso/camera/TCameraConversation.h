#ifndef PSO_CAMERA_TCAMERACONVERSATION_H
#define PSO_CAMERA_TCAMERACONVERSATION_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

struct NpcCameraDestination {
    Vec position;
    Vec target;
};

// Conversation camera poses, indexed by the NPC or counter that starts one.
extern const NpcCameraDestination fixed_npc_camera_destination_table[20];

// Set once a conversation camera holds its pose; the fixed camera clears it.
extern s32 fixed_npc_camera_active;

// Started when the player talks to an NPC or a service counter: switches to the
// fixed camera (mode 9) from the current view, then eases the pose each frame
// toward one row of fixed_npc_camera_destination_table. Destroying it gives the
// players their cameras back.
class TCameraConversation : public TObject {
public:
    TCameraConversation(s32 view, s32 destination, TObject *parent);
    virtual ~TCameraConversation();
    virtual void run_task();
    Vec position;
    Vec target;
    s32 destination;
};
LAYOUT_ASSERT(TCameraConversation_size, sizeof(TCameraConversation) == 0x38);

// camera_override_flags (TCameraFollow.h).
s32 get_camera_override_flags();

// The local player's conversation camera, or NULL in split screen.
TCameraConversation *create_conversation_camera(s32 destination);

// The local player's body collision, switched off while an NPC talks to them and
// back on after.
void deactivate_local_player_collision();
void activate_local_player_collision();

#endif
