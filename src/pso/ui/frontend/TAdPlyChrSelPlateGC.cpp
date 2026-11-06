#include "pso/ui/frontend/TAdPlyChrSelPlateGC.h"

TAdPlyChrSelPlateGC::~TAdPlyChrSelPlateGC() {}

#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
extern "C" {
struct Q_802C5040 { s8 b[4]; };
struct Arg_802C5040 { u8 pad0[0xC]; s32 f0C; };
struct S_802C5040 {
    s32 f0;
    u8 pad4[0x14];
    void *vt;
    u8 pad1c[0x224 - 0x1C];
    s32 f224;
    s32 a[32];
    f32 fl[32];
    Q_802C5040 c[32];
    u8 pad3A8[4];
    s32 f3AC;
    s32 f3B0;
};
extern u8 __vt__19TAdPlyChrSelPlateGC[];
extern s32 TAdPlyChrSelPlateGC__name;
extern const f32 lbl_805DE54C;
void __ct__7TObjectFP7TObject(void *);

S_802C5040 *__ct__19TAdPlyChrSelPlateGCFv(S_802C5040 *arg0, s32 arg1, Arg_802C5040 *arg2) {
    s32 i;
    __ct__7TObjectFP7TObject(arg0);
    arg0->vt = __vt__19TAdPlyChrSelPlateGC;
    arg0->f0 = TAdPlyChrSelPlateGC__name;
    arg0->f3B0 = arg2->f0C;
    arg0->f3AC = -1;
    arg0->f224 = 0;
    for (i = 0; i < 0x20; i++) {
        arg0->a[i] = 0;
        arg0->fl[i] = lbl_805DE54C;
        arg0->c[i].b[0] = 0;
        arg0->c[i].b[1] = 0;
        arg0->c[i].b[2] = 0;
        arg0->c[i].b[3] = 0;
    }
    ((TWindowSubSymbolChatPartsSet *)((u8 *)arg0 + 0x21C))->copy_vec2(arg2);
    ((TAdChrMoveEffectGC *)((u8 *)arg0 + 0x3A8))->copy4((u8 *)arg2 + 8);
    return arg0;
}
}
