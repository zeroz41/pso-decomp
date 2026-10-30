#ifndef PSO_ENEMY_TOBJENEDOLMOLM_H
#define PSO_ENEMY_TOBJENEDOLMOLM_H

#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/enemy/TUnk_80493450.h"

struct TObjEneDolmOlm : public TUnk_80493450 {
    virtual ~TObjEneDolmOlm();
    virtual void run_task();
    virtual void render();
    s32 render_model_if_visible();
    void check_path_ahead(s32, f32);
    void sub_80301148();
    virtual void vfunc_60();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_83();
    virtual void request_stand_action();
    virtual void vfunc_101();
    virtual void vfunc_100();
    virtual void vfunc_98();
    virtual void vfunc_97();
    virtual void vfunc_96();
    virtual void vfunc_95();
    virtual void vfunc_94();
    virtual void vfunc_93();

    MaterialOpacityFade fade;

    u32 m_3c4;
    u32 m_3c8;
    u8 unk_3CC[0x4];
    f32 m_3d0;
    u8 unk_3D4[0x4];
    void* m_3d8;
    u8 _pad3DC[0x8];
    u32 m_3e4;
    void load_params_from_table(s32 i);
    static void load_shared_resources();
    static void free_shared_resources();
    static void toggle_effect_render();
    void advance_position();
    void init_body_sub();
    static void reset_count();
};

typedef char TObjEneDolmOlmFadeOffset[offsetof(TObjEneDolmOlm, fade) == 0x3A8 ? 1 : -1];

typedef char TObjEneDolmOlm_size[sizeof(TObjEneDolmOlm) == 0x3E8 ? 1 : -1];

extern "C" {
void *TObjEneDolmOlm__create(void *arg0);
u8 *TObjEneDolmOlm__ct(u8 *arg0, s32 arg1, s32 arg2);
s32 TObjEneDolmOlm__sub_80300CF0(void);
s32 TObjEneDolmOlm__sub_8030177C(void *arg0_);
s32 TObjEneDolmOlm__sub_80301C3C(void *arg0_);
void run_task__14TObjEneDolmOlmFv(u8 *arg0_);
}

#endif
