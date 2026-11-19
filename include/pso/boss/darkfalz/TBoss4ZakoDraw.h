#ifndef PSO_BOSS_DARKFALZ_TBOSS4ZAKODRAW_H
#define PSO_BOSS_DARKFALZ_TBOSS4ZAKODRAW_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss4ZakoDraw : public TObject {
public:
    virtual ~TBoss4ZakoDraw();
    virtual void run_task();
    virtual void render();
public:
    static void render();
};

// boss4_zako_draw_buffers: layout known from its uses only.
struct Boss4ZakoDrawBuffers { s32 value; u8 remaining[0xF04]; };
extern Boss4ZakoDrawBuffers boss4_zako_draw_buffers;

// .sdata2 constants of the zako draw (TBoss4ZakoDraw.cpp); names inferred from the uses.
extern const u32 zako_model_render_flags;
extern const f32 zako_draw_height;
extern const f32 zako_min_height;
extern const f32 zako_fade_distance;
extern const f32 zako_fade_full;
extern const f32 zako_fade_color;

#endif
