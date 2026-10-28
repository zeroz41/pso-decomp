#include "types.h"
#include "pso/boss/TBoss1DragonColli.h"
#include "pso/boss/TBoss8Dragon_800BC53C.h"
#include "pso/enemy/TObjEneDD_800BA754.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/boss/TBoss1DragonEffTail.h"
#include "pso/boss/TBoss1Dragon.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDellBiter.h"
#include "pso/player/TObjPlayer.h"

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
    s32 unk0;
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

struct Pair_8002BD38 { s32 a, b; };

struct Vec_8002BD38 { f32 x, y, z; };

extern "C" {
void TBoss1Dragon__sub_8002AB6C(u8 *arg0);
extern const f32 lbl_805D8158;
extern u8 TBoss1DragonEffTail__collision_body_templates[];
extern s32 __vt__19TBoss1DragonEffTail[];
extern s32 TBoss1DragonEffTail__name;
extern const f32 lbl_805D8154;
EffTail_8002C06C *TBoss1DragonEffTail__ct(EffTail_8002C06C *arg0, s32 arg1, s32 arg2);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
s32 vec3_add_to(s32, s32, s32);
s32 matrix_mult_vec(int, void *, void *);
void set_matrix_identity(u8 *arg0);
s32 rotate_matrix_y(int, int);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 push_matrix(void);
s32 pop_matrix(void);
extern u8 lbl_80435454[];
extern const f32 lbl_805D8148;
extern const f32 lbl_805D814C;
extern const f32 lbl_805D8150;
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
    *(f32 *)((s8 *)boss1_dragon_eff_tail + 0x38) *= lbl_805D8148;
    *(f32 *)((s8 *)boss1_dragon_eff_tail + 0x40) *= lbl_805D8148;
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
        update_collider_contact_by_height(p, lbl_805D814C);
    }
    pop_matrix();
    if (*(s32 *)&((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->m_bc == 1) {
        *(f32 *)((s8 *)boss1_dragon_eff_tail + 0xC0) = lbl_805D8150 * cos_table_lookup(((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->rotation_y);
        *(f32 *)((s8 *)boss1_dragon_eff_tail + 0xC4) = lbl_805D8154;
        ((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->m_c8 = lbl_805D8150 * -sin_table_lookup(((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->rotation_y);
    } else {
        *(f32 *)((s8 *)boss1_dragon_eff_tail + 0xC0) = lbl_805D8150 * -cos_table_lookup(((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->rotation_y);
        *(f32 *)((s8 *)boss1_dragon_eff_tail + 0xC4) = lbl_805D8154;
        ((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->m_c8 = lbl_805D8150 * sin_table_lookup(((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->rotation_y);
    }
    {
        Pair_8002BD38 sp8 = *(Pair_8002BD38 *) lbl_80435454;
        ((TBoss1Dragon *)(*(void **)((s8 *)boss1_dragon_eff_tail + 0xB0)))->reset_tail_hp();
        ((TBoss1DragonEffTail *)boss1_dragon_eff_tail)->call_vt16_with_default(&sp8, *(void **)((s8 *)boss1_dragon_eff_tail + 0xB8));
    }
    ((TBoss1Dragon *)(*(void **)((s8 *)boss1_dragon_eff_tail + 0xB0)))->reload_difficulty_stats();
}

void TBoss1DragonEffTail__vt18(s32 arg0, s32 arg1) {
    vec3_add_to(arg1 + 0x308, arg0 + 0xC0, arg0);
}

void TBoss1DragonEffTail::apply_hit_if_active(void *arg1, f32 *) {
    ((VObj_18 *)(((u8 *)arg1)))->m20(this->m_ac, lbl_805D8158);
    if (TObjEneDD::check_v2_mode() != 0) {
        TBoss1Dragon__sub_8002AB6C((((u8 *)arg1)));
    }
}

void TBoss1DragonEffTail::enable() { this->m_bc = 1; is_visible(); }
void TBoss1DragonEffTail::disable() { this->m_bc = 0; is_visible(); }
int TBoss1DragonEffTail::is_visible() { return fill_value_array(*(void* *)&this->m_b8); }

void *__dt__19TBoss1DragonEffTailFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TBoss1DragonEffTail;
        delete_buffer__12TBoss8DragonFis((s32)(*(void **)((s8 *)arg0 + 0xB8)), 1);
        ((TBoss1DragonEffTail *)arg0)->m_b8 = 0;
        ((TUnk_804928CC *)arg0)->destroy_enemy_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
EffTail_8002C06C *TBoss1DragonEffTail__ct(EffTail_8002C06C *arg0, s32 arg1, s32 arg2) {
    void *data;
    s32 i;
    void *p;
    ((TUnk_804928CC *)arg0)->init_instance((void *)0, (void *)arg1, (void *)TBoss1DragonEffTail__collision_body_templates, (void *)0x11);
    arg0->vtbl = ((s32 *)&__vt__19TBoss1DragonEffTail);
    data = TBoss1DragonEffTail__collision_body_templates;
    arg0->unk0 = TBoss1DragonEffTail__name;
    for (i = 1; i < 0x11; i++) {
        fn_8002B630((u8 *)&arg0->spheres[i], (u8 *)data);
    }
    arg0->unkB0 = arg1;
    arg0->unkB4 = arg2;
    p = ::operator new(0x10);
    if (p != 0) {
        p = TBoss8Dragon__sub_800BC5EC((u8 *)p, 4);
    }
    arg0->unkB8 = p;
    arg0->unkBC = 0;
    arg0->unkC0 = lbl_805D8154;
    arg0->unkC4 = lbl_805D8154;
    arg0->unkC8 = lbl_805D8154;
    return arg0;
}

}
