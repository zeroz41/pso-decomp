#ifndef PSO_EFFECT_TBGLIGHTNINGCTRL_H
#define PSO_EFFECT_TBGLIGHTNINGCTRL_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TBGLightningCtrl : public TObjBase {
    virtual ~TBGLightningCtrl();
    void spawn_lightning_at_angle(s32);
    virtual void run_task();
    virtual void render();
    u32 m_90;
    static void destroy_instance();
};

LAYOUT_ASSERT(TBGLightningCtrl_size, sizeof(TBGLightningCtrl) == 0x94);

extern "C" {
void *TBGLightningCtrl__create(void *arg0);
u8 *TBGLightningCtrl__ct(u8 *arg0, saddr parent, saddr set_data);
void bind_lightning_texture(void);
u8 *__ct__12TBGLightningFv(u8 *arg0, void *parent, s32 arg2, f32 farg0);
void *__dt__16TBGLightningCtrlFv(void *arg0, s16 arg1);
u8 *create__12TBGLightningFiif(saddr arg0, s32 arg1, f32 farg0);
}
void load_bg_lightning(void);
extern "C" {
void render__12TBGLightningFv(s32 arg0);
void run_task__12TBGLightningFv(void *arg0);
void run_task__16TBGLightningCtrlFv(void *arg0);
void spawn_lightning_at_angle__16TBGLightningCtrlFl(TBGLightningCtrl *arg0, s32 arg1);
}
void submit_particle_quad(void *arg0, f32 *p, f32 *d, s32 c);

#endif
