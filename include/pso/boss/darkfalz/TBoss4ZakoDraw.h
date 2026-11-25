#ifndef PSO_BOSS_DARKFALZ_TBOSS4ZAKODRAW_H
#define PSO_BOSS_DARKFALZ_TBOSS4ZAKODRAW_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss4ZakoDraw : public TObject {
public:
    explicit TBoss4ZakoDraw(TObject *parent);
    virtual ~TBoss4ZakoDraw();
    virtual void run_task();
    virtual void render();
    // Draws the zako queued for this frame, clipped to the view.
    static void draw_queued();
    static const char *class_name;
    static s32 draw_buffer_index;
    static s32 rotation_phase;
};

// .sdata2 constants of the zako draw (TBoss4ZakoDraw.cpp); names inferred from the uses.
extern const u32 zako_model_render_flags;
extern const f32 zako_draw_height;
extern const f32 zako_min_height;
extern const f32 zako_fade_distance;
extern const f32 zako_fade_full;
extern const f32 zako_fade_color;

#endif
