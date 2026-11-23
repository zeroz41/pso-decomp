#ifndef PSO_EFFECT_ENEMY_TENEEFFHAMON_H
#define PSO_EFFECT_ENEMY_TENEEFFHAMON_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include <dolphin/mtx/GeoTypes.h>

struct NJS_TEXLIST;

// One ripple ring of the Dark Gunner (spawn_hamon_effects): the fish model,
// grown by scale_rate and faded by alpha_rate each frame once delay runs out.
class TEneEffHamon : public TObject {
public:
    TEneEffHamon(const Vec *position, s32 duration, s32 delay, f32 size);
    virtual ~TEneEffHamon();
    virtual void run_task();
    virtual void render();
    static void init_fish_effects();
    // Empty: the fish model and texlist point into DarkGunner's bml, which
    // cleanup_effects frees itself.
    static void free_fish_effects();

    static const char *class_name;
    static NJS_OBJECT *fish_model;
    static NJS_TEXLIST *fish_texlist;

    Vec position;
    s32 rotation_x;
    s32 rotation_y;
    s32 rotation_z;
    f32 scale;
    u8 pad_38[0x8];
    f32 size;
    f32 scale_rate;  // 1 / duration
    f32 alpha_rate;  // -0.9 / duration
    s32 delay;       // frames before it starts
    NJS_ARGB color;
};

#endif
