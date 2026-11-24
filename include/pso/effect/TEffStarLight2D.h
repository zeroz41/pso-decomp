#ifndef PSO_TEFFSTARLIGHT2D_H
#define PSO_TEFFSTARLIGHT2D_H
#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/render/ColorLineList.h"
#include <stddef.h>
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
    void copy_from(StarLightParameters *source);
};

class TEffStarLight2D : public TObject {
public:
    static const char *class_name;
    TEffStarLight2D(Vec *position, StarLightParameters *parameters, TObject *parent);
    virtual ~TEffStarLight2D();
    virtual void render();
    virtual void run_task();
public:
    void set_parameters(StarLightParameters *source);
    void copy_position(const Vec *position);
    void queue_child_destruction();
    void draw_segment(ColorLineVertex *a, ColorLineVertex *b,
                      ColorLineVertex *c, ColorLineVertex *d, s32 index);

    ColorLineVertex screen_position;
    ColorLineVertex previous_screen_position;
    Vec position;
    StarLightParameters parameters;
};

LAYOUT_ASSERT(StarLightColorSize, sizeof(StarLightColor) == 4);
LAYOUT_ASSERT(StarLightParametersSize, sizeof(StarLightParameters) == 0x14);
LAYOUT_ASSERT(TEffStarLight2DSize, sizeof(TEffStarLight2D) == 0x4C);
LAYOUT_ASSERT(StarLightPositionOffset, offsetof(TEffStarLight2D, position) == 0x2C);
LAYOUT_ASSERT(StarLightParametersOffset, offsetof(TEffStarLight2D, parameters) == 0x38);

#endif
