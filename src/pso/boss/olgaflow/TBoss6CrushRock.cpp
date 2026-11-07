#include "pso/boss/olgaflow/TBoss6CrushRock.h"
#include "pso/system/vector.h"
#include "pso/boss/olgaflow/TBoss6Rock.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>

TBoss6CrushRock::~TBoss6CrushRock() {}

#include "types.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/boss/olgaflow/TBoss6CrushPtcl.h"

struct RecoveredGlobal_8035A1A4___vt__15TBoss6CrushRock {
    s32 value;
    u8 remaining[0x14];
};

struct Vec_8035A460 { f32 x, y, z; };

extern "C" {
s32 get_bml_model(int, void *);
s32 __ct__7TObjectFP7TObject(void *, void *);
int TBoss6Rock__sub_80353A04(void);
int TBoss6Rock__sub_80353A0C(void);
extern RecoveredGlobal_8035A1A4___vt__15TBoss6CrushRock __vt__15TBoss6CrushRock;
extern s32 TBoss6CrushRock__name;
void *__nw__7TObjectFUl(int);
extern s32 tl_02;
extern s32 TBoss6PlotFalz__instance;

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
typedef char RecoveredGlobal_8035A1A4___vt__15TBoss6CrushRock_size[sizeof(RecoveredGlobal_8035A1A4___vt__15TBoss6CrushRock) == 0x18 ? 1 : -1];
u8 *__ct__15TBoss6CrushRockFv(u8 *object, s32 arg1, s32 arg2, s32 arg3) {
    __ct__7TObjectFP7TObject((void *)object, (void *)arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__15TBoss6CrushRock.value;
    *(s32 *)((s8 *)object + 0) = (s32) TBoss6CrushRock__name;
    *(s32 *)((s8 *)object + 0x1C) = get_bml_model((int) (TBoss6Rock__sub_80353A0C()), (void *)arg3);
    *(s32 *)((s8 *)object + 0x20) = TBoss6Rock__sub_80353A04();
    VecCopy((Vec *)(object + 0x24), (const Vec *)(arg2));
    *(f32 *)((s8 *)object + 0x30) = (f32) (0.5f * ((0.000030517578f * (f32) rand()) - 0.5f));
    *(f32 *)((s8 *)object + 0x34) = (f32) (0.5f * ((0.000030517578f * (f32) rand()) - 0.5f));
    *(f32 *)((s8 *)object + 0x38) = (f32) (0.5f * ((0.000030517578f * (f32) rand()) - 0.5f));
    *(s32 *)((s8 *)object + 0x3C) = (s32) (65535.0f * (0.000030517578f * (f32) rand()));
    *(s32 *)((s8 *)object + 0x40) = (s32) (65535.0f * (0.000030517578f * (f32) rand()));
    *(s32 *)((s8 *)object + 0x44) = (s32) (65535.0f * (0.000030517578f * (f32) rand()));
    *(s32 *)((s8 *)object + 0x48) = (s32) (4096.0f * ((0.000030517578f * (f32) rand()) - 0.5f));
    *(s32 *)((s8 *)object + 0x4C) = (s32) (4096.0f * ((0.000030517578f * (f32) rand()) - 0.5f));
    *(s32 *)((s8 *)object + 0x50) = (s32) (4096.0f * ((0.000030517578f * (f32) rand()) - 0.5f));
    return object;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TBoss6Rock::spawn_crush_rocks(s32 kind) {
    f32 radius;
    s32 base;
    s32 n;
    s32 i;
    s32 j;

    if (TBoss6CrushRock::is_falz_alive() == 0) {
        return;
    }
    ((TBoss6CrushPtcl *)this)->create();
    radius = 7.5f;
    base = 5;
    n = 2;
    if ((u32)TBoss6PlotFalz::get_hp() == 0) {
        return;
    }
    switch (kind) {
    case 0:
        break;
    case 1:
        radius = 15.0f;
        base = 1;
        n = 3;
        break;
    }
    for (i = 0; i < 0x12 / n; i++) {
        for (j = 0; j < n; j++) {
            Vec_8035A460 p = *((Vec_8035A460 *)this);
            s32 angle = (s32)(65535.0f * (0.000030517578f * (f32)rand()));
            p.x += radius * sin_table_lookup(angle);
            p.y += 35.0f * (0.000030517578f * (f32)rand());
            p.z += radius * cos_table_lookup(angle);
            u8 *o = (u8 *)__nw__7TObjectFUl(0x54);
            if (o != NULL) {
                ((u8 *(*)(u8 *, s32, Vec_8035A460 *, s32))__ct__15TBoss6CrushRockFv)(o, tl_02, &p, base + j);
            }
        }
    }
}
#pragma pop

s32 TBoss6PlotFalz::get_hp() {
    return TBoss6PlotFalz__instance;
}

extern char TBoss6CrushRock__class_name_string[];
s32 TBoss6CrushRock__name = (s32)TBoss6CrushRock__class_name_string;

}
