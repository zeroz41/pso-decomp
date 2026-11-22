#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/boss/dragon/ObjBoss1CommonJResource.h"
#include "pso/boss/dragon/TBoss1DragonColli.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"
#include "pso/enemy/dd/TObjEneDD_800BA754.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/boss/goldragon/TBoss8DragonEffTail.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/enemy/dellbiter/TObjEneDellBiter.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/enemy/dd/TObjEneDD_800BB804.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/enemy/AttackTargetHistory.h"

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

struct P8_802FE494 { f32 a; s32 b; };

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
    Vec *xB4;
    s32 xB8;
    s32 xBC;
    f32 xC0;
    f32 xC4;
    f32 xC8;
};

const char *TBoss8DragonEffTail__name = "TBoss8DragonEffTail";
extern const P8_802FE494 lbl_80474BBC = { 3.0f, 1 };
// The 17 collision bodies the constructor sets up: the first a radius-10 sphere, the rest copies of it.
CollisionBody boss8_dragon_eff_tail_init_data[17] = { { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003 } };
BmlResource *boss8_eff_tail_bml_resource;
uaddr dragon_tail_gvm_texture_handle;

extern s32 __vt__19TBoss8DragonEffTail[];
extern "C" {
EffTail_8002C06C *TBoss8DragonEffTail__ct(EffTail_8002C06C *arg0, saddr arg1, s32 arg2);
void matrix_mult_vec(s32, void *, void *);
s32 release_texture_list(void*);

void fn_802FE48C(void) {  }
void TBoss8DragonEffTail::render() {  }

void run_task__19TBoss8DragonEffTailFv(u8 *arg0p) {
    s32 off;
    u8 *e;
    Vec *p;
    s32 i;
    Obj_802FE494 *self = (Obj_802FE494 *)arg0p;
    VecCopy((Vec *)(arg0p + 0x38), (const Vec *)((u8 *)self->xB4 + 0x24));
    vec3_add_to((Vec *)(arg0p + 0x38), (Vec *)((u8 *)self->xB4 + 0x78));
    self->x38 *= 0.5f;
    self->x40 *= 0.5f;
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
        update_collider_contact_by_height(e, 30.0f);
    }
    pop_matrix();
    if (self->xBC == 1) {
        self->xC0 = 5.0f * cos_table_lookup(self->x60);
        self->xC4 = 0.0f;
        self->xC8 = 5.0f * -sin_table_lookup(self->x60);
    } else {
        self->xC0 = 5.0f * -cos_table_lookup(self->x60);
        self->xC4 = 0.0f;
        self->xC8 = 5.0f * sin_table_lookup(self->x60);
    }
    {
        P8_802FE494 sp = lbl_80474BBC;
        ((TBoss8Dragon *)(self->xB0))->reset_tail_hp();
        self->m15(&sp, self->xB8);
    }
    ((TBoss8Dragon *)(self->xB0))->reload_boss_stats();
}

void TBoss8DragonEffTail::area_attack_apply_recoil(void *target, f32) {
    vec3_add_to((Vec *)((u8 *)target + 0x308), &m_c0);
}

void TBoss8DragonEffTail::apply_hit_if_active(void *arg1_arg, f32 *) {
    u8 *arg1 = (u8 *)arg1_arg;
    ((VObj_18 *)(arg1))->m20(this->owner, this, 1.0f);
}

void TBoss8DragonEffTail::enable() { this->m_bc = 1; get_state(); }
void TBoss8DragonEffTail::disable() { this->m_bc = 0; get_state(); }
void TBoss8DragonEffTail::get_state() { fill_value_array(attack_history); }

TBoss8DragonEffTail::~TBoss8DragonEffTail() {
    delete attack_history;
    attack_history = NULL;
}

EffTail_8002C06C *TBoss8DragonEffTail__ct(EffTail_8002C06C *arg0, saddr arg1, s32 arg2) {
    void *data;
    s32 i;
    void *p;
    __ct__13TUnk_804928CCFP7TObjectP8TObjBasePC13CollisionBodyl(arg0, (void *)0, (void *)arg1, (void *)boss8_dragon_eff_tail_init_data, 0x11);
    arg0->vtbl = ((s32 *)&__vt__19TBoss8DragonEffTail);
    data = boss8_dragon_eff_tail_init_data;
    arg0->name = TBoss8DragonEffTail__name;
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

void TBoss8DragonEffTail::free_statics() {
    if ((u32) dragon_tail_gvm_texture_handle != 0U) {
        release_texture_list((void*)dragon_tail_gvm_texture_handle);
        TAdSinglePlyChrSelectGC::safe_free(dragon_tail_gvm_texture_handle);
        dragon_tail_gvm_texture_handle = 0U;
    }
    delete boss8_eff_tail_bml_resource;
    boss8_eff_tail_bml_resource = 0;
}

u8 *load_gvm_texture_file(saddr arg0);

void TBoss8DragonEffTail::load_statics() {
    boss8_eff_tail_bml_resource = load_enemy_bml_resource((BmlResourceDescriptor *)&bm_obj_boss1_common_j_resource_descriptor);
    dragon_tail_gvm_texture_handle = (saddr)load_gvm_texture_file((saddr)obj_boss1_common_j_texture_filename);
}
