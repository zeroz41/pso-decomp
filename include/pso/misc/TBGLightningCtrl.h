#ifndef PSO_MISC_TBGLIGHTNINGCTRL_H
#define PSO_MISC_TBGLIGHTNINGCTRL_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TBGLightningCtrl : public TObjBase {
    virtual ~TBGLightningCtrl();
    void spawn_lightning_at_angle(s32);
    virtual void run_task();
    virtual void render();
    u32 m_90;
    static void destroy_instance();
};

typedef char TBGLightningCtrl_size[sizeof(TBGLightningCtrl) == 0x94 ? 1 : -1];

extern "C" {
void *TBGLightningCtrl__create(void *arg0);
u8 *TBGLightningCtrl__ct(u8 *arg0, s32 parent, s32 arg2);
void TBGLightningCtrl__sub_802A9A08(void);
u8 *__ct__12TBGLightningFv(u8 *arg0, void *arg1, s32 arg2, f32 farg0);
void *__dt__16TBGLightningCtrlFv(void *arg0, s16 arg1);
u8 *create__12TBGLightningFiif(s32 arg0, s32 arg1, f32 farg0);
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
