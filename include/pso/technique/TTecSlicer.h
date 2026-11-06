#ifndef PSO_TECHNIQUE_TTECSLICER_H
#define PSO_TECHNIQUE_TTECSLICER_H
#include "types.h"
#include <stddef.h>

struct TTecSlicer {
    void set_launch_midpoint(void *, void *, void *);
    void run_task();
    static s32 create(u16* launch);

    u8 base[0x24];
    u32 textureHandle;
    u8 unk_28[0x8];
    void * m_30;
    u8 unk_34[0x4];
    f32 position[3];
    f32 previousPosition[3];
    u8 unknown50[0xC];
    s32 spin, yaw, roll;
    f32 scale[3];
    u8 unknown74[0x1C];
    f32 direction[3];
    f32 origin[3];
    f32 destination[3];
    f32 speed, range, radius;
    u32 flags;
    u16 targetId;
    u8 targetPart, paddingC7;
    u8 capturedTargets[0x20];
    u8 secondaryTargets[0x20];
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
    s32 get_field_110();
    s16 get_remain_count();
    void destroy_if_set();
    static s32 dt(s32 arg0, s16 arg1);
    void *dt(s16 arg1);
    void reset_fields_1e();
    void deliver_target_hit();
    void advance_position();
    static void init_launch_angles(s32 *arg0, s32 *arg1, s32 arg2);
    void update();
    void render();
};
typedef char SlicerSize[(sizeof(TTecSlicer)==0x140)?1:-1];
typedef char SlicerPosition[(offsetof(TTecSlicer,position)==0x38)?1:-1];
typedef char SlicerDirection[(offsetof(TTecSlicer,direction)==0x90)?1:-1];
typedef char SlicerCapturedTargets[(offsetof(TTecSlicer,capturedTargets)==0xC8)?1:-1];
typedef char SlicerColor[(offsetof(TTecSlicer,argb)==0x128)?1:-1];
#endif
