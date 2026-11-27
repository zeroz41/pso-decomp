#ifndef PSO_SYSTEM_SCENE_TSCENESORA_H
#define PSO_SYSTEM_SCENE_TSCENESORA_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct NJS_MOTION;
struct NJS_TEXLIST;
struct BmlResource;

struct TSceneSora : public TObjBase {
    TSceneSora(TObject *parent);
    virtual ~TSceneSora();
    NJS_OBJECT *sky_model;
    NJS_MOTION *sky_motion;
    NJS_TEXLIST *sky_textures;
    virtual void render();
    virtual void run_task();
    static void create_instance();
    static void load_sky_resources();
    static void release_sky_scene();
    f32 motion_step;
    f32 m_a0;
    static TSceneSora *instance;
    static s32 sky_active_flag; // 0 while something else draws the sky
    static const char *name;
    // The floor's sky model (and motion when the floor has one); NULL on floors without a sky.
    static BmlResource *sky_bml_resource;
    static s32 has_sky_motion;
};

LAYOUT_ASSERT(TSceneSora_motion_offset, offsetof(TSceneSora, sky_motion) == 0x94);
LAYOUT_ASSERT(TSceneSora_frame_offset, offsetof(TSceneSora, m_a0) == 0xA0);
LAYOUT_ASSERT(TSceneSora_size, sizeof(TSceneSora) == 0xA4);
void prepare_adventure_maps(void);
// Release hook paired with prepare_adventure_maps in offline_game_scene_callbacks.
void release_adventure_maps(void);

struct SceneTableEntry { s32 f0; char *name; };

#endif
