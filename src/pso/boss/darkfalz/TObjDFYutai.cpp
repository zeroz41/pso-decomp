#include "pso/boss/darkfalz/TObjDFYutai.h"

TObjDFYutai::~TObjDFYutai() {}

#include "types.h"

extern "C" {


extern s32 TObjDFYutai__name;
extern const f32 lbl_805D8A30;
extern const f32 lbl_805D8A34;

}
TObjDFYutai::TObjDFYutai(s32 arg1, s32 arg2, s16 arg3) : TObject((TObject *)arg1) {
    *(s32 *)((s8 *)this + 0) = (s32) TObjDFYutai__name;
    *(s32 *)((s8 *)this + 0x1C) = arg2;
    *(s16 *)((s8 *)this + 0x20) = arg3;
    switch (*(s32 *)((s8 *)this + 0x1C)) {
    case 0:
        *(f32 *)((s8 *)this + 0x24) = (f32) lbl_805D8A34;
        *(f32 *)((s8 *)this + 0x28) = -0.011111111f;
        break;
    case 1:
        *(f32 *)((s8 *)this + 0x24) = (f32) lbl_805D8A30;
        *(f32 *)((s8 *)this + 0x28) = 0.016666668f;
        break;
    case 2:
        *(f32 *)((s8 *)this + 0x24) = (f32) lbl_805D8A34;
        *(f32 *)((s8 *)this + 0x28) = -0.11111111f;
        break;
    }
}
