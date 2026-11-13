#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/TChCrTagPlBack.h"

extern "C" {

int TChCrTagPlBack__vt4(void);
int render__14TChCrTagPlBackFv(void* p);
void __dl__7TObjectFPv(void *);
void render_shadows__7TObjectFv(void *);
TChCrTagPlBack *__dt__14TChCrTagPlBackFv(TChCrTagPlBack *tag, s16 free);
extern void *__vt__14TChCrTagPlBack[6];

void TChCrTagPlBack::render() { draw_frame(); }
int TChCrTagPlBack__vt4(void) { return 0; }
TChCrTagPlBack *__dt__14TChCrTagPlBackFv(TChCrTagPlBack *tag, s16 free) {
    if (tag != NULL) {
        *(void ***)((u8 *)tag + 0x18) = __vt__14TChCrTagPlBack;
        __dt__8TChCrTagFv(tag, 0);
        if (free > 0) {
            __dl__7TObjectFPv(tag);
        }
    }
    return tag;
}

void *__vt__14TChCrTagPlBack[6] = {
    0, 0, (void *)__dt__14TChCrTagPlBackFv, (void *)update_fade__8TChCrTagFPv,
    (void *)render__14TChCrTagPlBackFv, (void *)render_shadows__7TObjectFv,
};

extern const f32 lbl_805DDFE4;
extern const f32 lbl_805DDFE8;

}

TChCrTagPlBack::TChCrTagPlBack(TObject *parent, void *arg) : TChCrTag(parent, arg) {
    m_name = TChCrTagPlBack__name;
    m_28 = lbl_805DDFE4;
    m_2c = lbl_805DDFE8;
    m_34 = lbl_805DDFE4;
    m_38 = lbl_805DDFE8;
}

extern "C" {

void *TChCrTagPlBack::create(void *arg0) {
    return new TChCrTagPlBack(tl_03, arg0);
}

void *TChCrTagPlBack::create_default() { return TChCrTagPlBack::create(NULL); }

extern const f32 lbl_805DDFF0;
extern const f32 lbl_805DDFF4;

void TChCrTagPlBack::get_position_offset(void *arg1) {
    void *temp_r3;
    void *temp_r5;

    temp_r5 = *(void **)((s8 *)this + 0x28);
    if (temp_r5 != NULL) {
        *(f32 *)((s8 *)arg1 + 0) = (f32) ((*(f32 *)((s8 *)temp_r5 + 0x30) + *(f32 *)((s8 *)temp_r5 + 0x38)) - lbl_805DDFF0);
        temp_r3 = *(void **)((s8 *)this + 0x28);
        *(f32 *)((s8 *)arg1 + 4) = (f32) ((*(f32 *)((s8 *)temp_r3 + 0x34) + *(f32 *)((s8 *)temp_r3 + 0x3C)) - lbl_805DDFF4);
    }
}

}
