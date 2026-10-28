#include "types.h"
#include "pso/boss/TBoss6Rock_8035477C.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/boss/TBoss6Rock.h"
#include "pso/player/TObjPlayer.h"
extern "C" void *__ct__14TObjCollidableFP7TObject(void *, s32);

struct RecoveredGlobal_80354948___vt__10TBoss6Rock {
    s32 value;
    u8 remaining[0x34];
};

struct RecoveredGlobal_80354948_TBoss6Rock__data_805437F8 {
    s32 value;
    u8 remaining[0x17C];
};

struct RecoveredGlobal_803548B4___vt__10TBoss6Rock {
    s32 value;
    u8 remaining[0x34];
};

struct RecoveredGlobal_803548B4_TBoss6Rock__data_80543778 {
    s32 value;
    u8 remaining[0x7C];
};

extern "C" {
s32 create__10TBoss6RockFv();
extern RecoveredGlobal_80354948___vt__10TBoss6Rock __vt__10TBoss6Rock;
extern RecoveredGlobal_80354948_TBoss6Rock__data_805437F8 TBoss6Rock__rock_point_table;
extern s32 lbl_805D438C;
void __dl__7TObjectFPv(s32);
extern RecoveredGlobal_803548B4_TBoss6Rock__data_80543778 TBoss6Rock__instance_table;
void *__nw__7TObjectFUl(int);
int is_active__10TBoss6RockFv(void*);

void TBoss6Rock::render() { if (is_active__10TBoss6RockFv(this) != 0) { draw_model(); } }

/* Per-kind rock parameters: model id, then the target radius passed to set_target. */
struct RockKindParams {
    s32 model_id;
    f32 target_radius;
    f32 unk_08[3];
};
extern const RockKindParams TBoss6Rock__data_80479258[2];
extern s32 TBoss6Rock__data_805D6EF0;
extern s32 TBoss6Rock__data_805D6EF4;
int query_teammate_state__9TObjEneDDFv();
s32 get_bml_model(s32 bml, s32 index);

void TBoss6Rock::run_task() {
    if (is_active__10TBoss6RockFv(this) == 0) {
        queue_destruction();
        return;
    }
    if (query_teammate_state__9TObjEneDDFv() != 0) {
        return;
    }
    switch (m_c4) {
    case 0:
        init_spin_params();
        break;
    case 1:
        update_fall();
        break;
    case 2:
        break_and_release();
        break;
    }
    if (m_e4 != 0) {
        s32 model = get_bml_model(TBoss6Rock__data_805D6EF0, TBoss6Rock__data_80479258[m_b4].model_id);
        u64 pos = (s32)&position;
        ((TBoss6Rock *)m_e4)->set_target(m_c4 != 0, (s32)pos, (s32)&rotation_x, TBoss6Rock__data_805D6EF4, model,
                                          TBoss6Rock__data_80479258[m_b4].target_radius);
    }
}

extern void *tl_02;

typedef char RecoveredGlobal_80354948___vt__10TBoss6Rock_size[sizeof(RecoveredGlobal_80354948___vt__10TBoss6Rock) == 0x38 ? 1 : -1];
typedef char RecoveredGlobal_80354948_TBoss6Rock__data_805437F8_size[sizeof(RecoveredGlobal_80354948_TBoss6Rock__data_805437F8) == 0x180 ? 1 : -1];

typedef char RecoveredGlobal_803548B4___vt__10TBoss6Rock_size[sizeof(RecoveredGlobal_803548B4___vt__10TBoss6Rock) == 0x38 ? 1 : -1];
typedef char RecoveredGlobal_803548B4_TBoss6Rock__data_80543778_size[sizeof(RecoveredGlobal_803548B4_TBoss6Rock__data_80543778) == 0x80 ? 1 : -1];
u8 *__dt__10TBoss6RockFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_803548B4___vt__10TBoss6Rock *)&__vt__10TBoss6Rock).value;
        if ((s32) ((TBoss6Rock *)arg0)->m_c4 != 0) {
            ((TBoss6Rock *)(arg0 + 0xD4))->spawn_crush_rocks(((TBoss6Rock *)arg0)->m_b4);
        }
        ((TBoss6Rock *)arg0)->release_object();
        *(s32 *)((s8 *)&TBoss6Rock__instance_table.value + (((TBoss6Rock *)arg0)->m_ac * 4)) = 0;
        __dt__14TObjCollidableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

u8 *TBoss6Rock__ct(TBoss6Rock *boss6_rock, s32 arg1, s32 arg2) {
    __ct__14TObjCollidableFP7TObject(boss6_rock, arg1);
    *(s32 **)((s8 *)boss6_rock + 0x18) = &__vt__10TBoss6Rock.value;
    *(s32 *)((s8 *)boss6_rock + 0) = (s32) lbl_805D438C;
    boss6_rock->m_ac = arg2;
    VecCopy((Vec *)((u8 *)boss6_rock + 0xD4), (const Vec *)((u8 *)&TBoss6Rock__rock_point_table.value + (boss6_rock->m_ac * 0xC)));
    boss6_rock->m_b8 = 0;
    boss6_rock->m_b4 = 0;
    boss6_rock->m_c0 = 0;
    boss6_rock->m_bc = 0;
    boss6_rock->m_b0 = 0;
    boss6_rock->randomize_motion();
    boss6_rock->m_c8 = 0;
    boss6_rock->m_c4 = 0;
    boss6_rock->m_e4 = create__10TBoss6RockFv();
    return (u8 *)boss6_rock;
}

void *TBoss6Rock::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xE8);
    if (o != NULL) {
        o = TBoss6Rock__ct((TBoss6Rock *)((u8 *)o), (s32)tl_02, (s32)arg0);
    }
    return o;
}

}
