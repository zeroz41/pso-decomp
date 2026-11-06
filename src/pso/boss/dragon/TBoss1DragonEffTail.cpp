#include "types.h"
#include "pso/boss/dragon/TBoss1DragonColli.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"
#include "pso/enemy/dd/TObjEneDD_800BA754.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/boss/dragon/TBoss1DragonEffTail.h"
#include "pso/boss/dragon/TBoss1Dragon.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/dellbiter/TObjEneDellBiter.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixOps.h"
#include "pso/enemy/AttackTargetHistory.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"

struct VBase_18 { char pad[0x18]; };
struct VObj_18 : VBase_18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual s32 m20(s32, f32);
};

typedef struct EffTail_8002C06C {
    const char *name;
    u8 pad4[0x14];
    s32 *vtbl;
    u8 pad1C[0xA4 - 0x1C];
    struct { u8 b[0x2C]; } *spheres;
    u8 padA8[8];
    s32 unkB0;
    s32 unkB4;
    void *unkB8;
    s32 unkBC;
    f32 unkC0;
    f32 unkC4;
    f32 unkC8;
} EffTail_8002C06C;

struct Pair_8002BD38 { f32 a; s32 b; };

struct Vec_8002BD38 { f32 x, y, z; };

#pragma readonly_strings on

extern "C" {
const char *TBoss1DragonEffTail__name = "TBoss1DragonEffTail";
CollisionBody TBoss1DragonEffTail__collision_body_templates[17] = {
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003 },
};
}

extern "C" {
void TBoss1Dragon__sub_8002AB6C(u8 *arg0);
extern s32 __vt__19TBoss1DragonEffTail[];
EffTail_8002C06C *TBoss1DragonEffTail__ct(EffTail_8002C06C *arg0, s32 arg1, s32 arg2);
s32 matrix_mult_vec(int, void *, void *);
void __dl__7TObjectFPv(void *);
int fill_value_array(void*);

void TBoss1DragonEffTail::render() {  }

void run_task__19TBoss1DragonEffTailFv(u8 *boss1_dragon_eff_tail) {
    u8 *p;
    Vec_8002BD38 *src;
    s32 i;
    f32 f;
    VecCopy((Vec *)(boss1_dragon_eff_tail + 0x38), (const Vec *)(*(u8 **)((s8 *)boss1_dragon_eff_tail + 0xB4) + 0x24));
    ((s32 (*)(void *, void *)) vec3_add_to)(boss1_dragon_eff_tail + 0x38, *(u8 **)((s8 *)boss1_dragon_eff_tail + 0xB4) + 0x78);
    *(f32 *)((s8 *)boss1_dragon_eff_tail + 0x38) *= 0.5f;
    *(f32 *)((s8 *)boss1_dragon_eff_tail + 0x40) *= 0.5f;
    *(f32 *)((s8 *)boss1_dragon_eff_tail + 0x3C) = *(f32 *)((s8 *)(*(u8 **)((s8 *)boss1_dragon_eff_tail + 0xB0)) + 0x3C);
    ((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->rotation_y = *(s32 *)((s8 *)(*(u8 **)((s8 *)boss1_dragon_eff_tail + 0xB0)) + 0x60);
    src = *(Vec_8002BD38 **)((s8 *)boss1_dragon_eff_tail + 0xB4);
    push_matrix();
    set_matrix_identity(0);
    rotate_matrix_y(0, -((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->rotation_y);
    translate_matrix(0, -*(f32 *)((s8 *)boss1_dragon_eff_tail + 0x38), -*(f32 *)((s8 *)boss1_dragon_eff_tail + 0x3C), -*(f32 *)((s8 *)boss1_dragon_eff_tail + 0x40));
    for (i = 0; i < 0x11; i++) {
        p = *(u8 * *)&((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->bodies + i * 0x2C;
        VecCopy((Vec *)(p + 0x1C), (const Vec *)src);
        matrix_mult_vec(0, src++, p);
        update_collider_contact_by_height(p, 30.0f);
    }
    pop_matrix();
    if (*(s32 *)&((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->m_bc == 1) {
        *(f32 *)((s8 *)boss1_dragon_eff_tail + 0xC0) = 5.0f * cos_table_lookup(((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->rotation_y);
        *(f32 *)((s8 *)boss1_dragon_eff_tail + 0xC4) = 0.0f;
        ((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->m_c0.z = 5.0f * -sin_table_lookup(((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->rotation_y);
    } else {
        *(f32 *)((s8 *)boss1_dragon_eff_tail + 0xC0) = 5.0f * -cos_table_lookup(((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->rotation_y);
        *(f32 *)((s8 *)boss1_dragon_eff_tail + 0xC4) = 0.0f;
        ((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->m_c0.z = 5.0f * sin_table_lookup(((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->rotation_y);
    }
    {
        Pair_8002BD38 sp8 = { 3.0f, 1 };
        ((TBoss1Dragon *)(*(void **)((s8 *)boss1_dragon_eff_tail + 0xB0)))->reset_tail_hp();
        ((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->call_vt16_with_default(&sp8, *(void **)((s8 *)boss1_dragon_eff_tail + 0xB8));
    }
    ((TBoss1Dragon *)(*(void **)((s8 *)boss1_dragon_eff_tail + 0xB0)))->reload_difficulty_stats();
}

// Pushes the hit object along this tail's sweep vector (+0x308 of the target, the field the base
// TUnk_804928CC::area_attack_apply_recoil also moves).
void TBoss1DragonEffTail::area_attack_apply_recoil(void *target, f32) {
    vec3_add_to((Vec *)((u8 *)target + 0x308), &m_c0);
}

void TBoss1DragonEffTail::apply_hit_if_active(void *arg1, f32 *) {
    ((VObj_18 *)(((u8 *)arg1)))->m20(this->owner, 1.0f);
    if (TObjEneDD::check_v2_mode() != 0) {
        TBoss1Dragon__sub_8002AB6C((((u8 *)arg1)));
    }
}

void TBoss1DragonEffTail::enable() { this->m_bc = 1; is_visible(); }
void TBoss1DragonEffTail::disable() { this->m_bc = 0; is_visible(); }
int TBoss1DragonEffTail::is_visible() { return fill_value_array(attack_history); }

TBoss1DragonEffTail::~TBoss1DragonEffTail() {
    delete attack_history;
    attack_history = NULL;
}
EffTail_8002C06C *TBoss1DragonEffTail__ct(EffTail_8002C06C *arg0, s32 arg1, s32 arg2) {
    void *data;
    s32 i;
    void *p;
    __ct__13TUnk_804928CCFP7TObjectP8TObjBasePC13CollisionBodyl(arg0, (void *)0, (void *)arg1, (void *)TBoss1DragonEffTail__collision_body_templates, 0x11);
    arg0->vtbl = ((s32 *)&__vt__19TBoss1DragonEffTail);
    data = TBoss1DragonEffTail__collision_body_templates;
    arg0->name = TBoss1DragonEffTail__name;
    for (i = 1; i < 0x11; i++) {
        copy_collision_body((CollisionBody *)&arg0->spheres[i], (const CollisionBody *)data);
    }
    arg0->unkB0 = arg1;
    arg0->unkB4 = arg2;
    p = ::operator new(0x10);
    if (p != 0) {
        p = __ct__17AreaAttackHistoryFl((u8 *)p, 4);
    }
    arg0->unkB8 = p;
    arg0->unkBC = 0;
    arg0->unkC0 = 0.0f;
    arg0->unkC4 = 0.0f;
    arg0->unkC8 = 0.0f;
    return arg0;
}

}
