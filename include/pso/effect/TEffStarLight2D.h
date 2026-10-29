#ifndef PSO_TEFFSTARLIGHT2D_H
#define PSO_TEFFSTARLIGHT2D_H
#include "pso/TObject.h"
#include "types.h"
#include "pso/misc/TLobby_801E2F94.h"
#include <dolphin/mtx/GeoTypes.h>

union StarLightColor {
    struct { u8 a, r, g, b; } channels;
    u32 packed;
};

struct StarLightParameters {
    f32 width;
    f32 speed;
    StarLightColor color;
    s32 blend_mode;
    f32 alpha_step;
};

class TEffStarLight2D : public TObject {
public:
    TEffStarLight2D(void *arg1, void *arg2, TObject *arg3);
    virtual ~TEffStarLight2D();
    virtual void render();
    virtual void run_task();
public:
    void copy_from_subobject(void* a1);
    void copy_from(void* q);
    void copy_position(const Vec *position);
    void queue_child_destruction();
    void draw_segment(ColorLineVertex *a, ColorLineVertex *b,
                      ColorLineVertex *c, ColorLineVertex *d, s32 index);

    ColorLineVertex screen_position;
    ColorLineVertex previous_screen_position;
    Vec position;
    StarLightParameters parameters;
};

typedef char StarLightColorSize[sizeof(StarLightColor) == 4 ? 1 : -1];
typedef char StarLightParametersSize[sizeof(StarLightParameters) == 0x14 ? 1 : -1];
typedef char TEffStarLight2DSize[sizeof(TEffStarLight2D) == 0x4C ? 1 : -1];

#endif
