#ifndef PSO_TECHNIQUE_TTECSLICER_H
#define PSO_TECHNIQUE_TTECSLICER_H
#include "types.h"
#include <stddef.h>
#include "pso/object/base/TObjMotion.h"
#include "pso/system/data/FlagWord.h"

// The targets a slicer has captured, visited in order (fn_8023B590 adds one,
// get_next_captured_target hands out the next).
struct TTecSlicerTargets_8023B454 {
    u16 ids[10];
    s8 parts[10];
    s8 count;
    s8 idx;
    TTecSlicerTargets_8023B454();
    ~TTecSlicerTargets_8023B454();
};

class TTecSlicer : public TObjBase {
public:
    TTecSlicer(u16 *launch, void *player, Vec *position, int angle);
    virtual ~TTecSlicer();
    virtual void run_task();
    virtual void render();
    void set_launch_midpoint(void *, void *, void *);
    static saddr create(u16* launch);

    f32 direction[3];
    f32 origin[3];
    f32 destination[3];
    f32 speed, range, radius;
    FlagWord flags;
    u16 targetId;
    u8 targetPart, paddingC7;
    TTecSlicerTargets_8023B454 capturedTargets;
    TTecSlicerTargets_8023B454 secondaryTargets;
    void* currentWeapon;
    void* currentPlayer;
    void* model;
    u16 playerId, padding116;
    u32 weaponHandle;
    s16 attackKind, comboStage;
    f32 damageMultiplier;
    void* star;
    f32 argb[4];
    s32 spinVelocity;
    s32 useColorOverride;
    void *get_field_110();
    s16 get_remain_count();
    void destroy_if_set();
    void deliver_target_hit();
    void advance_position();
    static void init_launch_angles(s32 *arg0, s32 *arg1, s32 arg2);
    void update();
};
LAYOUT_ASSERT(SlicerSize, sizeof(TTecSlicer)==0x140);
LAYOUT_ASSERT(SlicerPosition, offsetof(TTecSlicer,position)==0x38);
LAYOUT_ASSERT(SlicerDirection, offsetof(TTecSlicer,direction)==0x90);
LAYOUT_ASSERT(SlicerCapturedTargets, offsetof(TTecSlicer,capturedTargets)==0xC8);
LAYOUT_ASSERT(SlicerColor, offsetof(TTecSlicer,argb)==0x128);
#endif
