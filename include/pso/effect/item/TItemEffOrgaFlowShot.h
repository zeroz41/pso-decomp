#ifndef PSO_EFFECT_ITEM_TITEMEFFORGAFLOWSHOT_H
#define PSO_EFFECT_ITEM_TITEMEFFORGAFLOWSHOT_H

#include "types.h"
#include "pso/item/TUnk_804E355C.h"
#include "pso/system/TrailStrip.h"

// The spawn parameters TUnk_804F14A8::emit_marker_effects fills after
// reset_defaults and hands to create.
struct OrgaFlowShotParams : S_802E451C {
    OrgaFlowShotParams *reset_defaults();
    s32 rotation_y;
    Vec joints[5];
};

// A wave of light swept forward from five weapon joints, hitting what it crosses.
class TItemEffOrgaFlowShot : public TUnk_804E355C {
public:
    TItemEffOrgaFlowShot(TObject *parent, OrgaFlowShotParams *params);
    virtual ~TItemEffOrgaFlowShot();
    virtual void run_task();
    virtual void render();
    void bswap_6xAD_subordinate_action();
    void update_segments();
    void update_position_from_velocity();
    static void create(void *parent, void *params);
    static const char *class_name;

    // Pairs: a point pushed forward by length, then the spine point (joints 0 to 4,
    // the outer two following head_dir and tail_dir) it is pushed from.
    TrailStripVertex trail[10];
    Vec head_dir;       // params joint 0 - joint 1, normalized
    Vec tail_dir;       // params joint 4 - joint 3, normalized
    Vec forward;        // sin and cos of angle
    s32 angle;          // params->rotation_y
    f32 max_length;
    f32 length;         // grows by 50 a frame up to max_length
    f32 spread;         // then grows by 0.6 a frame up to max_spread
    f32 max_spread;     // 3 times the distance between joints 0 and 1
    s32 linger_frames;  // counted down by run_task once spread is full
};

LAYOUT_ASSERT(TItemEffOrgaFlowShot_size, sizeof(TItemEffOrgaFlowShot) == 0x1A0);
#endif
