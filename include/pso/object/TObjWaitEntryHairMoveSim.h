#ifndef PSO_OBJECT_TOBJWAITENTRYHAIRMOVESIM_H
#define PSO_OBJECT_TOBJWAITENTRYHAIRMOVESIM_H

#include "types.h"

#include "pso/system/task/TObject.h"
#include "pso/object/TObjEZBoneRotBase.h"

class TObjPlayer;
struct TObjHMSRopeSpec;
struct TObjHMSColliderSpec;

// Which hair effect a class gets: the first entry of its class whose hair or head
// index matches picks the model to swing (bone rotation) or to hang a rope from.
struct HairEffectEntry {
    s8 class_id;               // entries are sorted by class; -1 ends the table
    s8 head_model_hair;        // hair index that swings the head model
    s8 hair_model_hair;        // hair index that swings the hair model
    s8 attachment_model_head;  // head index that swings the attachment model
    EZBoneRotDesc *bone_rotation;
    TObjHMSRopeSpec *rope_spec;  // TObjPlayer::create_hairmove's specs when there is no bone rotation
    TObjHMSColliderSpec *collider_spec;
};
LAYOUT_ASSERT(HairEffectEntrySize, sizeof(HairEffectEntry) == 0x10);

class TObjWaitEntryHairMoveSim : public TObject {
public:
    TObjWaitEntryHairMoveSim(TObjPlayer *player);
    virtual ~TObjWaitEntryHairMoveSim();
    virtual void run_task();
    void create_hair_effects();
    static s32 get_move_done_result(TObjPlayer *player);
    static int is_move_done(TObjPlayer *player);
    static s32 is_level_in_table(TObjPlayer *player);
    static void hair_model_stub(NJS_OBJECT *model);

    TObjPlayer *player;
};
LAYOUT_ASSERT(TObjWaitEntryHairMoveSimSize, sizeof(TObjWaitEntryHairMoveSim) == 0x20);

// Starts the hair (or tail) simulation that fits the player's model, if any.
TObject *create_hair_move_sim(TObjPlayer *player);


#endif
