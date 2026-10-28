#include "types.h"
#include "pso/boss/TBoss1DragonColli.h"
#include "pso/boss/TBoss8Dragon_800BC53C.h"
#include "pso/enemy/TObjEneDD_800BA754.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/boss/TBoss8DragonEffTail.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/enemy/TObjEneDellBiter.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

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
    virtual s32 m20(s32, void *, f32);
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

struct P8_802FE494 { s32 a; s32 b; };

struct V3_802FE494 { f32 x, y, z; };

struct VB_802FE494 { u8 pad0[0x18]; };

struct Obj_802FE494 : VB_802FE494 {
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
    virtual void m15(P8_802FE494 *, s32);
    u8 pad1C[0x38 - 0x1C];
    f32 x38;
    f32 x3C;
    f32 x40;
    u8 pad44[0x60 - 0x44];
    s32 x60;
    u8 pad64[0xA4 - 0x64];
    u8 *xA4;
    u8 padA8[0xB0 - 0xA8];
    u8 *xB0;
    V3_802FE494 *xB4;
    s32 xB8;
    s32 xBC;
    f32 xC0;
    f32 xC4;
    f32 xC8;
};

extern "C" {
extern const f32 lbl_805DEF18;
extern u8 boss8_dragon_eff_tail_init_data[];
extern s32 __vt__19TBoss8DragonEffTail[];
extern s32 TBoss8DragonEffTail__name;
extern const f32 lbl_805DEF14;
EffTail_8002C06C *TBoss8DragonEffTail__ct(EffTail_8002C06C *arg0, s32 arg1, s32 arg2);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
s32 vec3_add_to(s32, s32, s32);
void matrix_mult_vec(s32, void *, void *);
void set_matrix_identity(u8 *arg0);
void rotate_matrix_y(s32, s32);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
void push_matrix(void);
s32 pop_matrix(void);
extern P8_802FE494 lbl_80474BBC[];
extern const f32 lbl_805DEF08;
extern const f32 lbl_805DEF0C;
extern const f32 lbl_805DEF10;
s32 TLobby__sub_8001FE7C(s32, s32);
s32 release_texture_list(void*);
void __dl__7TObjectFPv(void *);
int fill_value_array(void*);

void fn_802FE48C(void) {  }
void TBoss8DragonEffTail::render() {  }

void run_task__19TBoss8DragonEffTailFv(u8 *arg0p) {
    s32 off;
    u8 *e;
    V3_802FE494 *p;
    s32 i;
    Obj_802FE494 *self = (Obj_802FE494 *)arg0p;
    VecCopy((Vec *)(arg0p + 0x38), (const Vec *)((u8 *)self->xB4 + 0x24));
    ((void (*)(void *, void *))vec3_add_to)(arg0p + 0x38, (u8 *)self->xB4 + 0x78);
    self->x38 *= lbl_805DEF08;
    self->x40 *= lbl_805DEF08;
    self->x3C = *(f32 *)(self->xB0 + 0x3C);
    self->x60 = *(s32 *)(self->xB0 + 0x60);
    p = self->xB4;
    push_matrix();
    set_matrix_identity(0);
    rotate_matrix_y(0, -self->x60);
    translate_matrix(0, -self->x38, -self->x3C, -self->x40);
    for (i = 0, off = 0; i < 0x11; i++, off += 0x2C) {
        e = self->xA4 + off;
        VecCopy((Vec *)(e + 0x1C), (const Vec *)p);
        matrix_mult_vec(0, p++, e);
        update_collider_contact_by_height(e, lbl_805DEF0C);
    }
    pop_matrix();
    if (self->xBC == 1) {
        self->xC0 = lbl_805DEF10 * cos_table_lookup(self->x60);
        self->xC4 = lbl_805DEF14;
        self->xC8 = lbl_805DEF10 * -sin_table_lookup(self->x60);
    } else {
        self->xC0 = lbl_805DEF10 * -cos_table_lookup(self->x60);
        self->xC4 = lbl_805DEF14;
        self->xC8 = lbl_805DEF10 * sin_table_lookup(self->x60);
    }
    {
        P8_802FE494 sp = lbl_80474BBC[0];
        ((TBoss8Dragon *)(self->xB0))->reset_tail_hp();
        self->m15(&sp, self->xB8);
    }
    ((TBoss8Dragon *)(self->xB0))->reload_boss_stats();
}

void TBoss8DragonEffTail__vt18(s32 arg0, s32 arg1) {
    vec3_add_to(arg1 + 0x308, arg0 + 0xC0, arg0);
}

void TBoss8DragonEffTail::apply_hit_if_active(void *arg1_arg, f32 *) {
    u8 *arg1 = (u8 *)arg1_arg;
    ((VObj_18 *)(arg1))->m20(this->m_ac, this, lbl_805DEF18);
}

void TBoss8DragonEffTail::enable() { this->m_bc = 1; get_state(); }
void TBoss8DragonEffTail::disable() { this->m_bc = 0; get_state(); }
int TBoss8DragonEffTail::get_state() { return fill_value_array(*(void* *)&this->m_b8); }

void *__dt__19TBoss8DragonEffTailFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TBoss8DragonEffTail;
        delete_buffer__12TBoss8DragonFis((s32)(*(void **)((s8 *)arg0 + 0xB8)), 1);
        ((TBoss8DragonEffTail *)arg0)->m_b8 = 0;
        ((TUnk_804928CC *)arg0)->destroy_enemy_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 boss8_eff_tail_bml_resource;
extern u32 dragon_tail_gvm_texture_handle;

EffTail_8002C06C *TBoss8DragonEffTail__ct(EffTail_8002C06C *arg0, s32 arg1, s32 arg2) {
    void *data;
    s32 i;
    void *p;
    ((TUnk_804928CC *)arg0)->init_instance((void *)0, (void *)arg1, (void *)boss8_dragon_eff_tail_init_data, (void *)0x11);
    arg0->vtbl = ((s32 *)&__vt__19TBoss8DragonEffTail);
    data = boss8_dragon_eff_tail_init_data;
    arg0->unk0 = TBoss8DragonEffTail__name;
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
    arg0->unkC0 = lbl_805DEF14;
    arg0->unkC4 = lbl_805DEF14;
    arg0->unkC8 = lbl_805DEF14;
    return arg0;
}

void TBoss8DragonEffTail::free_statics() {
    if ((u32) dragon_tail_gvm_texture_handle != 0U) {
        release_texture_list((void*)dragon_tail_gvm_texture_handle);
        TAdSinglePlyChrSelectGC::safe_free(dragon_tail_gvm_texture_handle);
        dragon_tail_gvm_texture_handle = 0U;
    }
    TLobby__sub_8001FE7C(boss8_eff_tail_bml_resource, 1);
    boss8_eff_tail_bml_resource = 0;
}

}
