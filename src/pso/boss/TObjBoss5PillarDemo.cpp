#include "types.h"
#include "pso/boss/TObjBoss5PillarDemo.h"
#include "pso/boss/TObjBoss5Pillar.h"
#include "pso/system/ModelDrawContext.h"

#include "pso/misc/TNowLoading.h"
#include "pso/effect/TParticleCtrl.h"

struct Pd_8028ACE8 { u8 pad[0x1C]; s32 count; void **a; void **b; };

extern "C" {
s32 __nw__7TObjectFUl(int);
extern void *lbl_805D4DD8;
extern s32 tl_02;
extern s32 __vt__19TObjBoss5PillarDemo[];
extern s32 lbl_805D3B28;
void transform_to_view__11TCameraCtrlFii(s32 arg0, s32 arg1);
extern u8 lbl_80450CDC[];
extern s32 boss5_pillar_demo_index;
void TObjBoss5PillarDemo__sub_8028ACE8(Pd_8028ACE8 *arg0, void* _w1);
s32 clear_child_target_refs(s32, s32);
s32 clear_chain_flags(s32, s32);

void TObjBoss5PillarDemo__sub_8028AB38(void) {
    void *temp_r4;

    if ((void *) lbl_805D4DD8 != NULL) {
        temp_r4 = *(void **)((s8 *)lbl_805D4DD8 + 0x42C);
        clear_child_target_refs(*(s32 *)((s8 *)temp_r4 + 0x78), *(s32 *)((s8 *)temp_r4 + 0x68));
    }
}

void TObjBoss5PillarDemo::update_active_pillar() {
    void *temp_r4;

    if ((void *) lbl_805D4DD8 != NULL) {
        temp_r4 = *(void **)((s8 *)lbl_805D4DD8 + 0x42C);
        clear_chain_flags(*(s32 *)((s8 *)temp_r4 + 0x78), *(s32 *)((s8 *)temp_r4 + 0x68));
    }
}

}
TObjBoss5PillarDemo::~TObjBoss5PillarDemo() {

}

u8 *TObjBoss5PillarDemo__ct(TObjBoss5PillarDemo *boss5_pillar_demo, s32 arg1, s32 arg2) {
    TObjBoss5Pillar__ct((boss5_pillar_demo), (u8 *)arg1, (u8 *)arg2);
    *(s32 **)((s8 *)boss5_pillar_demo + 0x18) = __vt__19TObjBoss5PillarDemo;
    *(s32 *)((s8 *)boss5_pillar_demo + 0) = lbl_805D3B28;
    boss5_pillar_demo->m_24 = 0.5f;
    boss5_pillar_demo->m_38 = *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&lbl_805D4DD8) + 0x42C)) + 0x38);
    boss5_pillar_demo->m_3c = *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&lbl_805D4DD8) + 0x42C)) + 0x48);
    boss5_pillar_demo->m_40 = *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&lbl_805D4DD8) + 0x430)) + 4);
    boss5_pillar_demo->m_44 = *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&lbl_805D4DD8) + 0x430)) + 0xC);
    return (u8 *)boss5_pillar_demo;
}

s32 TObjBoss5PillarDemo::create() {
    s32 temp_r31;
    s32 boss5_pillar_demo;
    s32 var_r0;
    temp_r31 = *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&lbl_805D4DD8) + 0x42C)) + 0x38);
    boss5_pillar_demo = __nw__7TObjectFUl(0x4C);
    var_r0 = boss5_pillar_demo;
    if (var_r0 != 0) {
        var_r0 = ((s32)TObjBoss5PillarDemo__ct((TObjBoss5PillarDemo *)((u8 *)boss5_pillar_demo), (s32)tl_02, temp_r31 + 8));
    }
    return var_r0;
}

void TObjBoss5PillarDemo__sub_8028ACE0(void) {  }
void TObjBoss5PillarDemo__sub_8028ACE4(void) {  }

extern void *boss5_pillar_demo_ptr;

void TObjBoss5PillarDemo__sub_8028ACE8(Pd_8028ACE8 *arg0, void* _w1) {
    f32 sp[3];
    s32 idx;
    idx = boss5_pillar_demo_index - 1;
    boss5_pillar_demo_index += 1;
    if (idx >= 0 && idx < arg0->count) {
        transform_to_view__11TCameraCtrlFii((s32)lbl_80450CDC, (s32)sp);
        if (arg0->a != NULL && arg0->a[idx] != NULL) {
            ((TParticleCtrl *)arg0->a[idx])->set_position(sp);
        }
        if (arg0->b != NULL && arg0->b[idx] != NULL) {
            ((TParticleCtrl *)arg0->b[idx])->set_position(sp);
        }
    }
}

void TObjBoss5PillarDemo__sub_8028AD88(void* a0) { TObjBoss5PillarDemo__sub_8028ACE8((Pd_8028ACE8 *)(boss5_pillar_demo_ptr), a0); }

void TObjBoss5PillarDemo__sub_8028ADB0(u32 arg0) {
    if (arg0 != 0U) {
        set_model_node_callback(0);
    }
}

struct O_8028AE1C { u8 pad[0x1c]; s32 count; void **a; void **b; };

extern "C" {
extern s32 boss5_pillar_demo_index;
extern u8 lbl_80450CD0[];
void fn_8028AE1C(O_8028AE1C *arg0);
void fn_8028ADDC(void *p) {
    if (p) {
        boss5_pillar_demo_index = 0;
        boss5_pillar_demo_ptr = p;
        set_model_node_callback((s32)TObjBoss5PillarDemo__sub_8028AD88);
    }
}
void fn_8028AE1C(O_8028AE1C *arg0) {
    s32 i;
    for (i = 0; i < arg0->count; i++) {
        if (arg0->a[i] != 0) {
            ((TParticleCtrl *)arg0->a[i])->set_position(lbl_80450CD0);
        }
        if (arg0->b[i] != 0) {
            ((TParticleCtrl *)arg0->b[i])->set_position(lbl_80450CD0);
        }
    }
}

}
