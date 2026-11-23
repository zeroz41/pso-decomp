#ifndef PSO_OBJECT_WARP_TOBJWARPBOSSMULTI_H
#define PSO_OBJECT_WARP_TOBJWARPBOSSMULTI_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct AnimationMotion;
struct NJS_TEXLIST;
struct NJS_OBJECT;

// The boss warp's models, motions and texture lists from bm_obj_warpboss.bml (or its _ancient /
// _jungle variant by area), loaded by load_boss_warp_resources; defined in TObjWarpBossMulti.cpp.
void load_boss_warp_resources();
NJS_OBJECT *get_boss_warp_base_model(void);
NJS_OBJECT *get_boss_warp_confirmation_model(void);
NJS_OBJECT *get_boss_warp_model(void);
AnimationMotion *get_boss_warp_motion(void);
AnimationMotion *get_boss_warp_bml_motion(void);
NJS_TEXLIST *get_boss_warp_base_textures(void);
extern "C" {
NJS_TEXLIST *get_boss_warp_effect_textures(void);
}

struct TObjWarpBossMulti : public TObjAreaWarp {
    TObjWarpBossMulti(TObject *parent, void *set_data);
    virtual ~TObjWarpBossMulti();
    virtual void debug_print_area_num();
    void render();
    void run_task();
    static void *create(void *set_data);
    void init_warp_params();
    void update();
    static s32 is_lobby_active();
    static s32 get_boss_warp_flag();
    static void notify_player(void *arg0, s32 local_client_id);
    static int is_flag_clear(void* p);
    // Field names follow the get_boss_warp_* getters init_warp_params stores; the rest are inferred.
    s32 player_in_range[4];         // per player slot: a local player stands within warp_range + 25 (run_task)
    NJS_OBJECT *base_model;                 // get_boss_warp_base_model(), drawn with model_handle's textures
    NJS_OBJECT *confirmation_model;         // get_boss_warp_confirmation_model(), drawn with motion while state == 0
    NJS_OBJECT *warp_model;                 // get_boss_warp_model(), drawn with bml_motion while state == 1
    AnimationMotion *motion;        // get_boss_warp_motion()
    AnimationMotion *bml_motion;    // get_boss_warp_bml_motion()
    NJS_TEXLIST *model_handle;               // get_boss_warp_base_textures(): textures of base_model
    NJS_TEXLIST *effect_textures;            // get_boss_warp_effect_textures(): textures of the two animated models
    s32 state;                      // 1 once the key_id floor switch is set: the warp is usable
    s32 key_id;                     // floor switch, printed as "<- KEY ID : %d"; -1 for none
    f32 frame;                      // animation frame, + frame_step per run_task
    f32 frame_step;                 // 4.0
};

LAYOUT_ASSERT(TObjWarpBossMulti_size, sizeof(TObjWarpBossMulti) == 0x100);

void handle_6x6A_set_boss_warp_flags(void *packet);
#endif
