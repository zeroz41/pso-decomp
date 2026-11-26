#ifndef PSO_OBJECT_SEABED_TOBJSUISOCHIP_H
#define PSO_OBJECT_SEABED_TOBJSUISOCHIP_H
#include "pso/object/TObjChip.h"
#include "types.h"

class TObjBase;

// A debris chip of the seabed tanks (TObjSeabedSuisoBrakable,
// TOTrapSeabed01): drawn around its owner's position and turn.
class TObjSuisoChip : public TObjChip {
public:
    TObjSuisoChip(TObjBase *owner, TObjChipSpawnParams *params);
    TObjSuisoChip(TObjBase *owner, TObjChipParams *params);
    virtual ~TObjSuisoChip();
    virtual s32 is_finished();
    virtual s32 is_in_view(Vec *center, f32 max_depth, f32 radius);
    virtual void draw_ginja_chips();

    static const char *class_name;

    Vec origin;      // the owner's position
    s32 rotation_y;  // the owner's y turn
    s32 pad_244;     // 1 hides the chips in draw_ginja_chips
    s32 pad_248;
};

LAYOUT_ASSERT(TObjSuisoChip_size, sizeof(TObjSuisoChip) == 0x24C);

// One kind of TObjSeabedSuiso_CH.
struct SeabedSuisoKind {
    s32 model;         // model index in the tank archive
    s32 motion;        // motion index, -1 for none
    f32 motion_speed;  // frames per update
    s32 particle;      // particle effect id, -1 for none
    f32 view_range;
    f32 model_radius;
};

// One piece of a broken tank: its model and where it sits on the tank.
struct SeabedSuisoPiece {
    s32 model;  // model index in the tank archive, -1 ends the set
    Vec pos;
};

// The whole tank of one TObjSeabedSuisoBrakable kind and the chips it
// breaks into.
struct SeabedSuisoBreakSet {
    SeabedSuisoPiece whole;
    SeabedSuisoPiece chips[17];
};

#endif
