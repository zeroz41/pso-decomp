#ifndef PSO_TECHNIQUE_TTECSLICER_H
#define PSO_TECHNIQUE_TTECSLICER_H
#include "types.h"
#include <stddef.h>
#include "pso/object/base/TObjMotion.h"
#include "pso/system/data/FlagWord.h"
#include "pso/system/NinjaTypes.h"

class TObjPlayer;
class TEffStarLight2D;
struct TItemWeapon;
struct SlicerLaunchState;

// The targets a slicer has captured, visited in order: add_target enters
// one, get_next_captured_target hands out the next one still alive.
struct SlicerTargetList {
    u16 ids[10];
    s8 parts[10];  // the collision body locked on
    s8 count;
    s8 idx;
    SlicerTargetList();
    ~SlicerTargetList();
    s32 get_next_captured_target(Vec *out_pos, u16 *out_id, s8 *out_part, f32 *out_radius);
    void add_target(u16 id, s8 part);
};

// The blade a slicer-type weapon throws: it flies from target to target of
// the owner's captured list, hitting each, and leaves a TSlicerHistory
// afterimage every frame.
class TTecSlicer : public TObjBase {
public:
    TTecSlicer(SlicerLaunchState *launch, TObjPlayer *player, Vec *position, int angle);
    virtual ~TTecSlicer();
    virtual void run_task();
    virtual void render();
    void set_launch_midpoint(TObjPlayer *player, Vec *first, Vec *second);
    static TTecSlicer *create(SlicerLaunchState *launch);

    static const char *class_name;

    Vec direction;
    Vec origin;       // where it was thrown; hits land within range of it
    Vec destination;  // the target it flies at
    f32 speed, range, radius;
    FlagWord flags;  // 1 no target left, 2 done
    u16 targetId;
    s8 targetPart;
    u8 paddingC7;
    SlicerTargetList capturedTargets;
    SlicerTargetList secondaryTargets;
    TItemWeapon *currentWeapon;  // looked up again every frame
    TObjPlayer *currentPlayer;
    NJS_OBJECT *model;
    u16 playerId, padding116;
    u32 weaponHandle;
    s16 attackKind, comboStage;
    f32 damageMultiplier;
    TEffStarLight2D *star;
    NJS_ARGB argb;
    s32 spinVelocity;
    s32 useColorOverride;
    NJS_OBJECT *get_model();
    s16 get_remain_count();
    static void destroy_if_set(TObject *object);
    void deliver_target_hit();
    void destroy_on_collision();
    void advance_position();
    void init_launch_angles(TObjPlayer *player, s32 angle);
    void update();
};
LAYOUT_ASSERT(SlicerSize, sizeof(TTecSlicer)==0x140);
LAYOUT_ASSERT(SlicerPosition, offsetof(TTecSlicer,position)==0x38);
LAYOUT_ASSERT(SlicerDirection, offsetof(TTecSlicer,direction)==0x90);
LAYOUT_ASSERT(SlicerCapturedTargets, offsetof(TTecSlicer,capturedTargets)==0xC8);
LAYOUT_ASSERT(SlicerColor, offsetof(TTecSlicer,argb)==0x128);
#endif
