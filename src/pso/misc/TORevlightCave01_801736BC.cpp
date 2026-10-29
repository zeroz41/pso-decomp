#include "types.h"
#include "pso/misc/TORevlightCave01_801736BC.h"
#include "pso/misc/TORevlightCave01.h"

extern "C" {
extern const char *TORevlightCave01__name;
extern void *TORevlightCave01__static_model_resource;
extern const f32 lbl_805DB960;
extern const f32 lbl_805DB964;
extern const f32 lbl_805DB968;
extern const f32 lbl_805DB96C;
}

TORevlightCave01::TORevlightCave01(TObject *parent, void *set_data) : TUnk_804AFBF8(parent) {
    m_name = TORevlightCave01__name;
    apply_object_set_data(set_data);
    model = *(void **)((s8 *)(*(void **)((s8 *)TORevlightCave01__static_model_resource + 0x42C)) + 8);
    texlist = *(s32 *)((s8 *)(*(void **)((s8 *)TORevlightCave01__static_model_resource + 0x42C)) + 0xC);
    motion = *(AnimationMotion **)((s8 *)(*(void **)((s8 *)TORevlightCave01__static_model_resource + 0x430)) + 4);
    m_b8 = lbl_805DB960;
    animation_end_frame = (f32)motion->frameCount - lbl_805DB964;
    m_c0 = lbl_805DB968;
    model_radius = *(f32 *)((s8 *)(*(void **)((s8 *)model + 4)) + 0x14);
    m_c8 = 0;
    m_cc = (s32)(lbl_805DB96C * scale.x);
}
