#ifndef PSO_EFFECT_TBGLIGHTNINGCTRL_H
#define PSO_EFFECT_TBGLIGHTNINGCTRL_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

// One strike: a flash and an animated bolt, gone after 12 frames.
class TBGLightning : public TObject {
public:
    TBGLightning(TObject *parent, Vec *pos, f32 size);
    virtual ~TBGLightning();
    virtual void run_task();
    virtual void render();
    void draw_bolt(Vec *dir);
    void draw_flash(Vec *dir);
    static TBGLightning *create(TObject *parent, Vec *pos, f32 size);
    static const char *class_name;
    static const s32 bolt_first_texture[3];

    s8 bolt_set;    // which of the two bolt animations in bg_lightning.gvm
    s8 frame;
    Vec position;
    f32 size;
};

LAYOUT_ASSERT(TBGLightning_size, sizeof(TBGLightning) == 0x30);

// Background lightning placed by a map: every few frames it strikes at a random
// angle on a circle around the controller (radius scale.x, height scale.y).
struct TBGLightningCtrl : public TObjBase {
    TBGLightningCtrl(TObject *parent, void *set_data);
    virtual ~TBGLightningCtrl();
    void spawn_lightning_at_angle(s32 angle);
    virtual void run_task();
    virtual void render();
    s32 strike_timer;   // frames until the next strike
    static void *create(void *set_data);
    static void destroy_instance();
    static const char *class_name;
};

LAYOUT_ASSERT(TBGLightningCtrl_size, sizeof(TBGLightningCtrl) == 0x94);

void bind_lightning_texture(void);
void load_bg_lightning(void);
void submit_particle_quad(void *owner, f32 *pos, f32 *extent, s32 color);

#endif
