#ifndef PSO_OBJECT_WARP_TOBJWARPBOSSMULTI_H
#define PSO_OBJECT_WARP_TOBJWARPBOSSMULTI_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct AnimationMotion;

struct TObjWarpBossMulti : public TObjAreaWarp {
    TObjWarpBossMulti(TObject *parent, void *set_data);
    virtual ~TObjWarpBossMulti();
    virtual void debug_print_area_num();
    void render();
    void run_task();
    void *create();
    void init_warp_params();
    void update();
    static s32 is_lobby_active();
    static s32 get_boss_warp_flag();
    static void notify_player(void *arg0, s32 arg1);
    static int is_flag_clear(void* p);
    // Field names follow the get_boss_warp_* getters init_warp_params stores; the rest are inferred.
    s32 player_in_range[4];         // per player slot: a local player stands within warp_range + 25 (run_task)
    s32 base_model;                 // get_boss_warp_base_model(), drawn with model_handle's textures
    s32 confirmation_model;         // get_boss_warp_confirmation_model(), drawn with motion while state == 0
    s32 warp_model;                 // get_boss_warp_model(), drawn with bml_motion while state == 1
    AnimationMotion *motion;        // get_boss_warp_motion()
    AnimationMotion *bml_motion;    // get_boss_warp_bml_motion()
    s32 model_handle;               // get_boss_warp_model_handle(): textures of base_model
    s32 effect_textures;            // fn_8019F9AC(): textures of the two animated models
    s32 state;                      // 1 once the key_id floor switch is set: the warp is usable
    s32 key_id;                     // floor switch, printed as "<- KEY ID : %d"; -1 for none
    f32 frame;                      // animation frame, + frame_step per run_task
    f32 frame_step;                 // 4.0
};

typedef char TObjWarpBossMulti_size[sizeof(TObjWarpBossMulti) == 0x100 ? 1 : -1];
#endif
