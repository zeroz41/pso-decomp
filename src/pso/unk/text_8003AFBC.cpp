#include "types.h"
#include "pso/boss/TBoss8Dragon_8002CC48.h"
#include "pso/unk/text_8003AFBC.h"
#include "pso/system/vector.h"

struct RecoveredGlobal_8003AFBC___vt__19TObjBoss2RaftSplash { s32 value; u8 remaining[0x14]; };

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
s32 rand(void);
extern RecoveredGlobal_8003AFBC___vt__19TObjBoss2RaftSplash __vt__19TObjBoss2RaftSplash;
extern s32 lbl_805D2700;
extern const f32 lbl_805D85B0;
u8 *TObjBoss2RaftSplash__ct(u8 *object, u8 *arg1, u8 *arg2, u8 *arg3, s32 arg4) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__19TObjBoss2RaftSplash.value;
    *(s32 *)((s8 *)object + 0) = (s32) lbl_805D2700;
    *(f32 *)((s8 *)object + 0x20) = (f32) (lbl_805D85B0 * (3.0f + rand_signed_unit()));
    *(f32 *)((s8 *)object + 0x1C) = (f32) (*(f32 *)((s8 *)object + 0x20) * (3.0517578e-05f * (f32) rand()));
    VecCopy((Vec *)(object + 0x28), (const Vec *)arg2);
    VecCopy((Vec *)(object + 0x34), (const Vec *)arg3);
    *(s32 *)((s8 *)object + 0x24) = arg4;
    return object;
}

}
