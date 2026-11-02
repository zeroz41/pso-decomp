#include "types.h"
#include "pso/TObject.h"
#include "pso/TChCrTagPlBack.h"

extern "C" {

int TChCrTagPlBack__vt4(void);
int render__14TChCrTagPlBackFv(void* p);
void *__dt__8TChCrTagFv(void *self, s16 arg1);
void __dl__7TObjectFPv(void *);
void update_fade__8TChCrTagFPv(u8 *arg0);
void render_shadows__7TObjectFv(void *);
void *__dt__14TChCrTagPlBackFv(void *self, s16 arg1);
extern void *__vt__14TChCrTagPlBack[6];

void TChCrTagPlBack::render() { draw_frame(); }
int TChCrTagPlBack__vt4(void) { return 0; }
void *__dt__14TChCrTagPlBackFv(void *self, s16 arg1) {
    if (self != NULL) {
        *(void ***)((u8 *)self + 0x18) = __vt__14TChCrTagPlBack;
        __dt__8TChCrTagFv(self, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}

void *__vt__14TChCrTagPlBack[6] = {
    0, 0, (void *)__dt__14TChCrTagPlBackFv, (void *)update_fade__8TChCrTagFPv,
    (void *)render__14TChCrTagPlBackFv, (void *)render_shadows__7TObjectFv,
};

void *__ct__14TChCrTagPlBackFv(void *arg0);
void __ct__8TChCrTagFP7TObjectPv(void *);

extern const f32 lbl_805DDFE4;
extern const f32 lbl_805DDFE8;

void *__ct__14TChCrTagPlBackFv(void *ch_cr_tag_pl_back) {
    __ct__8TChCrTagFP7TObjectPv(ch_cr_tag_pl_back);
    *(void ***)((s8 *)ch_cr_tag_pl_back + 0x18) = __vt__14TChCrTagPlBack;
    ((TChCrTagPlBack *)ch_cr_tag_pl_back)->m_name = TChCrTagPlBack__name;
    *(f32 *)((s8 *)ch_cr_tag_pl_back + 0x28) = lbl_805DDFE4;
    *(f32 *)((s8 *)ch_cr_tag_pl_back + 0x2C) = lbl_805DDFE8;
    *(f32 *)((s8 *)ch_cr_tag_pl_back + 0x34) = lbl_805DDFE4;
    *(f32 *)((s8 *)ch_cr_tag_pl_back + 0x38) = lbl_805DDFE8;
    return ch_cr_tag_pl_back;
}

#define __ct__14TChCrTagPlBackFv (*(void * (*)(void *, void *, void *))&__ct__14TChCrTagPlBackFv)

void *__nw__7TObjectFUl(int);

extern void *tl_03;

void *TChCrTagPlBack::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x3C);
    if (o != NULL) {
        o = __ct__14TChCrTagPlBackFv(o, tl_03, arg0);
    }
    return o;
}

void *TChCrTagPlBack::create_default() { return TChCrTagPlBack::create((void *)((void*)(0))); }

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

#undef __ct__14TChCrTagPlBackFv
