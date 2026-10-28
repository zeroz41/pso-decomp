#include "pso/TAdDrawLineTask.h"
#include "pso/ui/TAdDrawLineCtrl.h"
#include "pso/ui/TAdDrawLineTask.h"
#include "pso/TObject.h"
#include "pso/player/TObjPlayer_80141D1C.h"

TAdDrawLineTask::~TAdDrawLineTask() {}

#include "types.h"
#include "pso/object/TObjLuker.h"

extern "C" {

int draw_projected_line_strip__10TObjPlayerFPvii(void*, void*, void*);
s32 allow_rendering__7TObjectFv();

void render__15TAdDrawLineTaskFv(void* p) { set_default_alpha_blend(); draw_projected_line_strip__10TObjPlayerFPvii((char*)p + 0x64, (void*)4, (void*)1); }

extern const f32 lbl_805D7DD8;

void run_task__15TAdDrawLineTaskFv(void *object) {
    allow_rendering__7TObjectFv();
    if ((lbl_805D7DD8 + *(f32 *)((s8 *)object + 0x4C)) < *(f32 *)((s8 *)object + 0x50)) {
        *(u8 *)((s8 *)object + 0xA6) = (u8) (*(u8 *)((s8 *)object + 0xA6) + *(u8 *)((s8 *)object + 0x62));
        *(u8 *)((s8 *)object + 0xA5) = (u8) (*(u8 *)((s8 *)object + 0xA5) + *(u8 *)((s8 *)object + 0x61));
        *(u8 *)((s8 *)object + 0xA4) = (u8) (*(u8 *)((s8 *)object + 0xA4) + *(u8 *)((s8 *)object + 0x60));
        *(u8 *)((s8 *)object + 0xA7) = (u8) (*(u8 *)((s8 *)object + 0xA7) + *(u8 *)((s8 *)object + 0x63));
        *(f32 *)((s8 *)object + 0x84) = (f32) (*(f32 *)((s8 *)object + 0x84) + *(f32 *)((s8 *)object + 0x54));
        *(f32 *)((s8 *)object + 0x88) = (f32) (*(f32 *)((s8 *)object + 0x88) + *(f32 *)((s8 *)object + 0x58));
        *(f32 *)((s8 *)object + 0x8C) = (f32) (*(f32 *)((s8 *)object + 0x8C) + *(f32 *)((s8 *)object + 0x5C));
        *(s32 *)((s8 *)object + 0x90) = (s32) *(s32 *)((s8 *)object + 0xA4);
        *(f32 *)((s8 *)object + 0x94) = (f32) (*(f32 *)((s8 *)object + 0x94) + *(f32 *)((s8 *)object + 0x54));
        *(f32 *)((s8 *)object + 0x98) = (f32) (*(f32 *)((s8 *)object + 0x98) + *(f32 *)((s8 *)object + 0x58));
        *(f32 *)((s8 *)object + 0x9C) = (f32) (*(f32 *)((s8 *)object + 0x9C) + *(f32 *)((s8 *)object + 0x5C));
        *(s32 *)((s8 *)object + 0xA0) = (s32) *(s32 *)((s8 *)object + 0xA4);
        *(f32 *)((s8 *)object + 0x4C) = (f32) (*(f32 *)((s8 *)object + 0x4C) + lbl_805D7DD8);
        return;
    }
    *(f32 *)((s8 *)object + 0x84) = (f32) (*(f32 *)((s8 *)object + 0x34) + *(f32 *)((s8 *)object + 0xA8));
    *(f32 *)((s8 *)object + 0x88) = (f32) (*(f32 *)((s8 *)object + 0x38) + *(f32 *)((s8 *)object + 0xAC));
    *(f32 *)((s8 *)object + 0x8C) = (f32) *(f32 *)((s8 *)object + 0x3C);
    *(s32 *)((s8 *)object + 0x90) = (s32) *(s32 *)((s8 *)object + 0x40);
    *(f32 *)((s8 *)object + 0x94) = (f32) (*(f32 *)((s8 *)object + 0x34) - *(f32 *)((s8 *)object + 0xA8));
    *(f32 *)((s8 *)object + 0x98) = (f32) (*(f32 *)((s8 *)object + 0x38) - *(f32 *)((s8 *)object + 0xAC));
    *(f32 *)((s8 *)object + 0x9C) = (f32) *(f32 *)((s8 *)object + 0x3C);
    *(s32 *)((s8 *)object + 0xA0) = (s32) *(s32 *)((s8 *)object + 0x40);
    {
        u32 temp = *(u32 *)((s8 *)object + 0x1C);
        if (temp != 0U) {
            ((TAdDrawLineCtrl *)temp)->sub_80019B08(*(s32 *)((s8 *)object + 0x20));
        }
    }
    ((TObject *)object)->suspend_update();
}

}
