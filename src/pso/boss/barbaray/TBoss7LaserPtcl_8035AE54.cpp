#include "types.h"
#include "pso/system/vector.h"
#include "pso/unk/text_80087278.h"

struct RecoveredGlobal_8035AE54_lbl_804F1C88 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
void *create_timed_particle_emitter(void *owner, s32 id, s32 b, s32 c);
extern s32 __vt__13TUnk_804F1C88[];
u8 *TBoss7LaserPtcl__sub_8035AE54(u8 *arg0, s32 arg1, s32 arg2);
void TBoss7LaserPtcl__sub_8035AF0C(void);
void TBoss7LaserPtcl__sub_8035AF10(void);
void TBoss7LaserPtcl__sub_8035AF14(void);
}

typedef char RecoveredGlobal_8035AE54_lbl_804F1C88_size[sizeof(RecoveredGlobal_8035AE54_lbl_804F1C88) == 0x18 ? 1 : -1];
u8 *TBoss7LaserPtcl__sub_8035AE54(u8 *object, s32 arg1, s32 arg2) {
    __ct__7TObjectFP7TObject((void *)object, (void *)arg1);
    *(s32 **)((s8 *)object + 0x18) = &(*(RecoveredGlobal_8035AE54_lbl_804F1C88 *)&__vt__13TUnk_804F1C88).value;
    *(f32 *)((s8 *)object + 0x34) = 0.0f;
    *(f32 *)((s8 *)object + 0x38) = 0.0f;
    *(f32 *)((s8 *)object + 0x3C) = 0.0f;
    *(f32 *)((s8 *)object + 0x40) = 0.0f;
    *(f32 *)((s8 *)object + 0x44) = 0.0f;
    *(s32 *)((s8 *)object + 0x48) = 0;
    *(s32 *)((s8 *)object + 0x4C) = 0x11F07;
    *(f32 *)((s8 *)object + 0x50) = 0.0f;
    *(f32 *)((s8 *)object + 0x54) = 0.0f;
    *(f32 *)((s8 *)object + 0x58) = 0.0f;
    *(f32 *)((s8 *)object + 0x5C) = 0.0f;
    *(u8 **)((s8 *)object + 0x1C) = (unsigned char *) (object + 0x34);
    *(s32 *)((s8 *)object + 0x20) = 1;
    VecCopy((Vec *)(object + 0x24), (const Vec *)(arg2));
    spawn_particle_effect((object + 0x24), 0x211);
    create_timed_particle_emitter((object + 0x24), 0x213, 0, 0x1E);
    return object;
}

void TBoss7LaserPtcl__sub_8035AF0C(void) {  }
void TBoss7LaserPtcl__sub_8035AF10(void) {  }
void TBoss7LaserPtcl__sub_8035AF14(void) {  }
