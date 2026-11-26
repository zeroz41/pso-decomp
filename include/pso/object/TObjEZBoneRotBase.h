#ifndef PSO_OBJECT_TOBJEZBONEROTBASE_H
#define PSO_OBJECT_TOBJEZBONEROTBASE_H

#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"

// One bone the rotation touches: the bone's index in the model and the axis
// its angle is swung about (scaled by the sine of the phase).
struct EZBoneRotKey {
    s32 bone;
    f32 axis[3];
};

struct EZBoneRotDesc {
    s32 amplitude;               // angle swing of the first bone
    s32 phase_step;              // added to the phase every frame it is active
    s32 child_phase_offset;      // phase lag of each child bone
    f32 child_amplitude_scale;   // each child swings by this fraction of its parent
    EZBoneRotKey *keys;          // terminated by a negative bone index
};

// Swings the bones of a model tree back and forth; the Player subclass drives
// the swing from what the player is doing.
class TObjEZBoneRotBase : public TObject {
public:
    TObjEZBoneRotBase(TObject *parent, NJS_OBJECT *root, EZBoneRotDesc *desc);
    virtual ~TObjEZBoneRotBase();
    // Records the bones' current angles in saved_angles.
    void save_bone_angles();
    void save_bone_angles_recursive(NJS_OBJECT *bone);

    NJS_OBJECT *root;
    EZBoneRotDesc *desc;
    s32 saved_angles[8][3];     // the keyed bones' rest angles
    s32 phase;
    s32 bone_index;             // the walk's counter through the model tree
    EZBoneRotKey *key;          // the walk's current key
    s32 (*saved_cursor)[3];     // the walk's slot in saved_angles
    f32 scale;                  // 0 at rest, 1 fully swinging
};

LAYOUT_ASSERT(TObjEZBoneRotBase_size, sizeof(TObjEZBoneRotBase) == 0x98);

#endif
