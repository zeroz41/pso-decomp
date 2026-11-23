#ifndef PSO_SYSTEM_SCENE_TSCENESORA_H
#define PSO_SYSTEM_SCENE_TSCENESORA_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct AnimationMotion;
struct NJS_TEXLIST;

struct TSceneSora : public TObjBase {
    TSceneSora(TObject *parent);
    virtual ~TSceneSora();
    NJS_OBJECT *sky_model;
    AnimationMotion *sky_motion;
    NJS_TEXLIST *sky_textures;
    virtual void render();
    virtual void run_task();
    static void create_instance();
    static void load_sky_resources();
    f32 motion_step;
    f32 m_a0;
    s32 get_state();
    static void set_scene_flag(int scene_flag);
    static void copy_reflection_vec(u8 *arg0);
    static TSceneSora *instance;
    static s32 sky_active_flag; // 0 while something else draws the sky
};

LAYOUT_ASSERT(TSceneSora_motion_offset, offsetof(TSceneSora, sky_motion) == 0x94);
LAYOUT_ASSERT(TSceneSora_frame_offset, offsetof(TSceneSora, m_a0) == 0xA0);
LAYOUT_ASSERT(TSceneSora_size, sizeof(TSceneSora) == 0xA4);
void prepare_adventure_maps(void);
extern "C" void TLobby__sub_802075F4(void);
#endif
