#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5Pillar.h"
#include "pso/boss/galgryphon/TObjBoss5PillarDemo.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"

#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

struct RecoveredGlobal_8028B60C___vt__15TObjBoss5Pillar {
    s32 value;
    u8 remaining[0x14];
};

struct Info_8028B488 { u8 pad[4]; u32 frames; };

struct Pillar_8028B488 {
    u8 pad[0x1C];
    s32 state;
    f32 frame;
    f32 speed;
    s32 timer;
    u8 pad2[0x38 - 0x2C];
    void *smokeParent;
    u8 pad3[0x40 - 0x3C];
    Info_8028B488 *info;
    u8 pad4[0x48 - 0x44];
    void *smoke;
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__15TObjBoss5Pillar[];
const char *lbl_805D3B40 = "TObjBoss5Pillar";
extern u8 *lbl_805D4DD8;
void fn_8028AE1C(void *);
s32 post_translate_matrix(void *);
s32 draw_ginja_model_with_motion(int, int, f32);
s32 push_matrix();

extern s32 boss5_common_texture_list;

void TObjBoss5Pillar::render() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::is_any_teammate_in_state() == 0) {
        push_matrix();
        TObjFish::set_global_param(boss5_common_texture_list);
        post_translate_matrix((u8 *)&this->m_2c);
        if ((s32) this->m_1c != 3) {
            fn_8028ADDC((void *)this->m_48);
            draw_ginja_model_with_motion(this->m_38, this->m_40, (f32) (*(f32 *)((s8 *)arg0 + 0x20)));
            TObjBoss5PillarDemo__sub_8028ADB0((this->m_48));
        }
        draw_ginja_model_with_motion(this->m_3c, this->m_44, (f32) (*(f32 *)((s8 *)arg0 + 0x20)));
        pop_matrix();
    }
}

void TObjBoss5Pillar::run_task() {
    Pillar_8028B488 *arg0 = (Pillar_8028B488 *)this;
    u32 last;
    switch (arg0->state) {
    case 0:
        break;
    case 1:
        if (arg0->smoke == NULL) {
            arg0->smoke = TObjBoss5Pillar::create_smoke(arg0, arg0->smokeParent);
        }
        arg0->frame += arg0->speed;
        last = arg0->info->frames - 1;
        if ((f32)last <= arg0->frame) {
            arg0->frame = (f32)last;
            arg0->state = 2;
        }
        break;
    case 2:
        if (arg0->smoke != NULL) {
            fn_8028AE1C(arg0->smoke);
        }
        if (arg0->timer++ > 0x1E) {
            if (arg0->smoke != NULL) {
                ((TObject *)arg0->smoke)->queue_destruction();
                arg0->smoke = NULL;
            }
            arg0->state = 3;
        }
        break;
    case 3:
        break;
    }
}

}
TObjBoss5Pillar::~TObjBoss5Pillar() {
    if (*(void **)((s8 *)this + 0x48) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x48)))->queue_destruction(); this->m_48 = 0; }
}

typedef char RecoveredGlobal_8028B60C___vt__15TObjBoss5Pillar_size[sizeof(RecoveredGlobal_8028B60C___vt__15TObjBoss5Pillar) == 0x18 ? 1 : -1];
u8 *TObjBoss5Pillar__ct(TObjBoss5Pillar *boss5_pillar, u8 *arg1, u8 *arg2) {
    __ct__7TObjectFP7TObject(boss5_pillar, arg1);
    *(s32 **)((s8 *)boss5_pillar + 0x18) = &(*(RecoveredGlobal_8028B60C___vt__15TObjBoss5Pillar *)&__vt__15TObjBoss5Pillar).value;
    *(const char **)((s8 *)boss5_pillar + 0) = lbl_805D3B40;
    VecCopy((Vec *)((u8 *)boss5_pillar + 0x2C), (const Vec *)arg2);
    boss5_pillar->m_1c = 0;
    *(f32 *)((s8 *)boss5_pillar + 0x20) = 0.0f;
    boss5_pillar->m_24 = 1.0f;
    boss5_pillar->m_28 = 0;
    boss5_pillar->m_48 = 0;
    boss5_pillar->m_38 = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)lbl_805D4DD8 + 0x42C)) + 8);
    boss5_pillar->m_3c = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)lbl_805D4DD8 + 0x42C)) + 0x18);
    boss5_pillar->m_40 = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)lbl_805D4DD8 + 0x430)) + 0x14);
    boss5_pillar->m_44 = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)lbl_805D4DD8 + 0x430)) + 0x1C);
    return (u8 *)boss5_pillar;
}

