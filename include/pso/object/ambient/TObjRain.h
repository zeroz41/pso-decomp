#ifndef PSO_OBJECT_AMBIENT_TOBJRAIN_H
#define PSO_OBJECT_AMBIENT_TOBJRAIN_H
#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/system/vector.h"
#include <stddef.h>

class TObjRain : public TObject {
public:
    TObjRain(TObject *parent, u32 count);
    virtual ~TObjRain();
    void update_drops();
    virtual void run_task();
    virtual void render();
    void draw_streaks();
    void init_drops();

    struct Drop {
        s32 active;
        Vec position;
        Vec velocity;
        f32 floor_y;
    };
    Drop drops[16];
    u32 count;
};

LAYOUT_ASSERT(TObjRainDropSize, sizeof(TObjRain::Drop) == 0x20);
LAYOUT_ASSERT(TObjRainDropsOffset, offsetof(TObjRain, drops) == 0x1C);
LAYOUT_ASSERT(TObjRainCountOffset, offsetof(TObjRain, count) == 0x21C);
LAYOUT_ASSERT(TObjRainSize, sizeof(TObjRain) == 0x220);

#endif
