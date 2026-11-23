#ifndef PSO_UI_FRONTEND_TADRICORING_H
#define PSO_UI_FRONTEND_TADRICORING_H
#include "pso/system/task/TObject.h"
#include "pso/system/data/FlagWord.h"
#include <dolphin/mtx.h>
#include <stddef.h>
struct NJS_OBJECT;
struct NJS_TEXLIST;
class TAdRicoRing : public TObject {
public:
    TAdRicoRing(TObject *parent);
    virtual ~TAdRicoRing();
    virtual void run_task();
    virtual void render();
    void set_scale4(f32 value);
    void update_position();
    void start_fade(f32 duration);
    void start_anim(f32 duration);
    void sub_8001BED0(f32 value);
    f32 scale[4];
    FlagWord flags;
    s32 angular_velocity;
    f32 target_scale;
    f32 scale_step[4];
    s32 angular_acceleration;
    NJS_OBJECT *model;
    NJS_TEXLIST *textures;
    u32 unknown_54;
    Vec position;
    s32 angles[3];
};
LAYOUT_ASSERT(TAdRicoRing_size, sizeof(TAdRicoRing) == 0x70);
LAYOUT_ASSERT(TAdRicoRing_flags_offset, offsetof(TAdRicoRing, flags) == 0x2C);
LAYOUT_ASSERT(TAdRicoRing_model_offset, offsetof(TAdRicoRing, model) == 0x4C);
LAYOUT_ASSERT(TAdRicoRing_position_offset, offsetof(TAdRicoRing, position) == 0x58);
#endif
