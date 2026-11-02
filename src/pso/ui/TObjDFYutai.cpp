#include "pso/TObjDFYutai.h"
#include "pso/ui/TObjDFYutai.h"

TObjDFYutai::~TObjDFYutai() {}

#include "types.h"

extern "C" {

s32 __ct__7TObjectFP7TObject();

extern void *__vt__11TObjDFYutai[];
extern s32 TObjDFYutai__name;
extern const f32 lbl_805D8A30;
extern const f32 lbl_805D8A34;

void *__ct__11TObjDFYutaiFv(void *arg0, s32 arg1, s32 arg2, s16 arg3) {

    __ct__7TObjectFP7TObject();
    *(void **)((s8 *)arg0 + 0x18) = __vt__11TObjDFYutai;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjDFYutai__name;
    *(s32 *)((s8 *)arg0 + 0x1C) = arg2;
    *(s16 *)((s8 *)arg0 + 0x20) = arg3;
    switch (*(s32 *)((s8 *)arg0 + 0x1C)) {
    case 0:
        *(f32 *)((s8 *)arg0 + 0x24) = (f32) lbl_805D8A34;
        *(f32 *)((s8 *)arg0 + 0x28) = -0.011111111f;
        break;
    case 1:
        *(f32 *)((s8 *)arg0 + 0x24) = (f32) lbl_805D8A30;
        *(f32 *)((s8 *)arg0 + 0x28) = 0.016666668f;
        break;
    case 2:
        *(f32 *)((s8 *)arg0 + 0x24) = (f32) lbl_805D8A34;
        *(f32 *)((s8 *)arg0 + 0x28) = -0.11111111f;
        break;
    }
    return arg0;
}

}
