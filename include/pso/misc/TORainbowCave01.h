#ifndef PSO_MISC_TORAINBOWCAVE01_H
#define PSO_MISC_TORAINBOWCAVE01_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

class TORainbowCave01 : public TObjMapObject {
public:
    TORainbowCave01(TObject *parent, void *set_data);
    virtual ~TORainbowCave01();
    virtual void run_task();
    virtual void render();
    s32 is_player_in_range(f32 range_sq);
    void init_light_params();
    static void *create(void *set_data);
    static void free_static_data();
    static void load_resource_instance();
    f32 fade_step;  // added to or taken from fade each frame
    f32 fade;       // 0 = shown, -1 = hidden; the constant material's alpha
    f32 range_sq;   // squared horizontal distance the player hides it within
    Vec model_scale;
};

typedef char TORainbowCave01_size[sizeof(TORainbowCave01) == 0xE0 ? 1 : -1];
#endif
