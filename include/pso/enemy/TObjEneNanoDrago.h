#ifndef PSO_ENEMY_TOBJENENANODRAGO_H
#define PSO_ENEMY_TOBJENENANODRAGO_H

#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/misc/RenderFadeState.h"

struct NanoDragoMovementParams {
    f32 detectionRadius;
    f32 baseSpeed;
    s32 turnSpeed;
    s32 unknown[4];
};

struct TObjEneNanoDrago : public TObjEnemyCustom {
    TObjEneNanoDrago(TObject *parent, void *setData);
    virtual ~TObjEneNanoDrago();
    virtual void run_task();
    virtual void render();
    virtual s32 update_action_hold_status();
    virtual void vfunc_61();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_58();
    virtual void vfunc_62();
    virtual void vfunc_63();
    void capture_beam_origins();
    void add_target_in_front_arc(TObjChara *candidate);
    void update_fade_in_state();
    void trigger_hit_camera_shake(u32 target);
    void request_growth();
    void spawn_beam_particle(s32 index);
    void find_open_direction(Vec *direction);
    void update_attack_parameters();
    s32 collect_beam_targets();
    void spawn_targeted_beam(s32 arg1);
    void update_dying_state();
    void update_knockback_state();
    void update_flight_state();
    void update_multi_beam_state();
    void update_single_beam_state();
    void run_demo_task();
    void wander_around(Vec *center, f32 radius);
    void dispatch_action_state();
    void update_idle_state();
    void update_proximity_state();
    void begin_hidden_flight();
    void load_entry_params_nanodrago(s32);
    void sub_800D9BBC();
    void update_growth_state();
    void update_circling_state();
    static void load_resources();
    static void free_resources();
    static void *create(void *setData);

    s16 growth_count;
    Vec moveDestination;
    Vec beamOrigins[2];
    s32 beamTargetCount;
    u16 beamTargetIds[12];
    s32 circlingAngle;
    f32 wanderDistance;
    f32 speed;
    s32 cameraShakeCooldown;
    s32 alternateBeam;
    f32 sinkingOffset;
    MaterialOpacityFade appearFade;
    f32 flightHeight;
    f32 descentSpeed;
    RenderFadeState cameraFades[4];
};

typedef char TObjEneNanoDrago_size[sizeof(TObjEneNanoDrago) == 0x47C ? 1 : -1];
#endif
