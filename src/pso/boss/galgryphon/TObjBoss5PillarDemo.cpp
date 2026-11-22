#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5PillarDemo.h"
#include "pso/boss/galgryphon/TObjBoss5Pillar.h"
#include "pso/render/ModelDrawContext.h"

#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

extern "C" {
extern void *lbl_805D4DD8;
extern s32 __vt__19TObjBoss5PillarDemo[];
#pragma push
#pragma readonly_strings on
const char *TObjBoss5PillarDemo__name = "TObjBoss5PillarDemo";
#pragma pop
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

u8 *TObjBoss5PillarDemo__ct(TObjBoss5PillarDemo *boss5_pillar_demo, saddr parent, saddr arg2) {
    TObjBoss5Pillar__ct((boss5_pillar_demo), (u8 *)parent, (u8 *)arg2);
    *(s32 **)((s8 *)boss5_pillar_demo + 0x18) = __vt__19TObjBoss5PillarDemo;
    *(s32 *)((s8 *)boss5_pillar_demo + 0) = (saddr)TObjBoss5PillarDemo__name;
    boss5_pillar_demo->m_24 = 0.5f;
    boss5_pillar_demo->m_38 = *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&lbl_805D4DD8) + 0x42C)) + 0x38);
    boss5_pillar_demo->m_3c = *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&lbl_805D4DD8) + 0x42C)) + 0x48);
    boss5_pillar_demo->m_40 = *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&lbl_805D4DD8) + 0x430)) + 4);
    boss5_pillar_demo->m_44 = *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&lbl_805D4DD8) + 0x430)) + 0xC);
    return (u8 *)boss5_pillar_demo;
}

TObjBoss5PillarDemo *TObjBoss5PillarDemo::create() {
    s32 temp_r31;
    saddr boss5_pillar_demo;
    saddr var_r0;
    temp_r31 = *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&lbl_805D4DD8) + 0x42C)) + 0x38);
    boss5_pillar_demo = (saddr)TObject::operator new(0x4C);
    var_r0 = boss5_pillar_demo;
    if (var_r0 != 0) {
        var_r0 = ((saddr)TObjBoss5PillarDemo__ct((TObjBoss5PillarDemo *)((u8 *)boss5_pillar_demo), (saddr)tl_02, temp_r31 + 8));
    }
    return (TObjBoss5PillarDemo *)var_r0;
}

void TObjBoss5PillarDemo__sub_8028ACE0(void) {  }
void TObjBoss5PillarDemo__sub_8028ACE4(void) {  }
