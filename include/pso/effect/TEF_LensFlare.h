#ifndef PSO_MISC_TEF_LENSFLARE_H
#define PSO_MISC_TEF_LENSFLARE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

// One reflected flare element: a sprite drawn on the line from the light's
// screen position to the screen centre (names inferred from render()).
struct LensFlareElement {
    s32 sprite;      // index into the particle sprite table
    f32 position;    // 0 at the light, 1 at the screen centre
    f32 size;
    f32 shrink;      // how much of the size goes as the light leaves the view centre
    f32 brightness;
    f32 pad_14;      // -10.0, -10.1, ... -10.9 in the table; render() never reads it
};

struct TEF_LensFlare : public TObjBase {
    virtual ~TEF_LensFlare();
    virtual void render();
    virtual void run_task();
    int is_player_near(f32 farg0);
    LensFlareElement *elements;  // 0x90, the table render() draws 9 of
};

typedef char TEF_LensFlare_size[sizeof(TEF_LensFlare) == 0x94 ? 1 : -1];
#endif
