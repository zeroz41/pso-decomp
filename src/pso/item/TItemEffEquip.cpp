#include "pso/player/TObjPlayer_80011014.h"
#include "pso/TItemEffEquip.h"
#include "pso/item/TUnk_8049F038.h"
#include "pso/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TBoss1DragonColli.h"
#include "pso/item/TItemEffEquip.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/unk/text_80087278.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/object/TObjMotion.h"
#include "pso/item/TUnk_8049F038.h"

struct Equip_Self { u8 pad0[0x18]; void *vt; void *m_1c; void *m_20; };
extern "C" {
extern void *__vt__13TItemEffEquip[];
void __dt__7TObjectFv(void *, s16);
s32 __dl__7TObjectFPv(void *);
void run_task__13TItemEffEquipFv(Equip_Self *self) {
    if (((TObject *)((TObject*)self->m_1c))->all_parents_unqueued_for_destruction() == 0) {
        self->m_1c = NULL;
        queue_destruction__7TObjectFv((TObject*)self);
    }
}

void *__dt__13TItemEffEquipFv(Equip_Self *self, s16 arg1) {
    if (self != NULL) {
        self->vt = __vt__13TItemEffEquip;
        TBoss4Type2::request_destroy((u32)self->m_20);
        __dt__7TObjectFv(self, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
}
#include "types.h"
#include "pso/unk/text_801036CC.h"

extern "C" {

void *destroy__13TUnk_8049F038Fs(void *arg0, s16 arg1);
void run_task__13TUnk_8049F038Fv(u8 *arg0);
u8 *get_center__13TUnk_8049F038Fv(u8 *arg0);
s32 set_entity_id__13TUnk_804B9870FUs(void *, s32);
void *get_player_by_client_id(s32 i);
struct Obj_80108C90 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1C[0xAC - 0x1C];
    s16 f_AC;
    u8 padAE[2];
    s32 f_B0;
    u8 sub[0x10];
};
void __ct__13TUnk_804AF8A0FP7TObject(void *, void *);
extern u8 lbl_8043E1A0[];

#include "pso/TItemEffFlame.h"
#include "pso/TItemAttacker.h"

extern "C" {

s32 play_sound_effect(s32, s32, s32, s32);
void *__nw__7TObjectFUl(int);
struct Equip_80108A20 { s32 x0; u8 pad4[0x18 - 4]; void *vt; void *src; s32 x20; void *x24; };
s32 __ct__7TObjectFP7TObject(void *, void *);
extern s32 retire_equipment_effect[];
extern s32 TItemEffEquip__sub_801088F8[];
extern s32 TItemEffEquip__class_name;
Obj_80108C90 *__ct__13TUnk_8049F038FP7TObjectsl(Obj_80108C90 *self, void *parent, s16 a, s32 b);

#define self ((Equip_80108A20 *)arg0)
void *TItemEffEquip__ct(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5) {
    void *mem;

    __ct__7TObjectFP7TObject(arg0, arg1);
    self->vt = __vt__13TItemEffEquip;
    self->x0 = TItemEffEquip__class_name;
    disallow_rendering__7TObjectFv((TObject *)arg0);
    mem = __nw__7TObjectFUl(0xE0);
    if (mem != NULL) {
        mem = ((void *(*)(void *, void *, void *, void *))__ct__13TUnk_8049F038FP7TObjectsl)(mem, arg0, arg2, arg3);
    }
    self->src = mem;
    self->x20 = 0;
    self->x24 = arg5;
    if (self->src != NULL) {
        ((TItemEffEquip *)arg0)->spawn_equip_particle_effect((s32)arg4);
        TItemAttacker::spawn_item_timer((s32)arg0, (s32)TItemEffEquip__sub_801088F8, 0xA);
        TItemAttacker::spawn_item_timer((s32)arg0, (s32)retire_equipment_effect, 0x14);
    } else {
        queue_destruction__7TObjectFv((TObject *)arg0);
    }
    return arg0;
}
#undef self

void TItemEffEquip::create(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    void *o;
    o = __nw__7TObjectFUl(0x28);
    if (o != NULL) {
        TItemEffEquip__ct(o, arg0, arg1, arg2, arg3, arg4);
    }
}
struct VBase0x18_80108b5c { char pad[0x18]; };
struct VObj80108B5C_80108b5c : VBase0x18_80108b5c {
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
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63(s32, void *);
};

void *TUnk_8049F038::get_center() {
    u8 *arg0 = (u8 *)this;
    u8 *player;

    player = (u8 *)get_player_by_client_id(*(u16 *)((s8 *)arg0 + 0xAC));
    if (player != NULL) {
        ((VObj80108B5C_80108b5c *)player)->m63(this->m_b0, (u8 *)&this->position);
    }
    return &this->position;
}

struct VBase0x18_2_80108bb0 { char pad[0x18]; };
struct VObj80108BB0_80108bb0 : VBase0x18_2_80108bb0 {
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
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63(s32, void *);
};

void TUnk_8049F038::run_task() {
    u8 *arg0 = (u8 *)this;
    u8 *player;

    player = (u8 *)get_player_by_client_id(*(u16 *)((s8 *)arg0 + 0xAC));
    if (player != NULL) {
        ((VObj80108BB0_80108bb0 *)player)->m63(this->m_b0, (u8 *)&this->position);
    }
}

extern void *__vt__13TUnk_8049F038[];

void *TUnk_8049F038::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = (s32 *)__vt__13TUnk_8049F038;
        if ((u32) this->bodies != 0U) {
            unregister_object_by_id();
            clear_collision_bodies();
            push_free_entity_id(get_entity_id(this));
            set_entity_id__13TUnk_804B9870FUs(this, 0xFFFF);
        }
        __dt__13TUnk_804AF8A0Fv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

}
TUnk_8049F038::TUnk_8049F038(TObject *parent, s16 a, s32 b) : TUnk_804AF8A0(parent) {
    ((Obj_80108C90 *)this)->f_AC = a;
    ((Obj_80108C90 *)this)->f_B0 = b;
    copy_collision_body((CollisionBody *)(((Obj_80108C90 *)this)->sub), (const CollisionBody *)lbl_8043E1A0);
    if (get_entity_id(this) == 0xFFFF) {
        set_entity_id(pop_free_entity_id());
    }
    ((TUnk_804AF8A0 *)this)->set_collision_body(((Obj_80108C90 *)this)->sub);
    ((TObjPlayer *)this)->register_object_by_id();
    disallow_rendering__7TObjectFv((TObject *)this);
}
extern "C" {

}

void TItemEffFlame::play_effect(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    spawn_particle_effect((void *)arg3, 0x45);
    play_sound_effect(0x4001C112, 0, 0, 0);
}

void render__7TObjectFv(void);
void render_shadows__7TObjectFv(void);
void vfunc_6__13TUnk_804B9870FPsl(void);
void apply_object_set_data__13TUnk_804B9870FPv(void);
void reset_motion_fields__13TUnk_804AF8A0Fv(void *);
void update_object_view_visibility__13TUnk_804B9870Fff(void);
void classify_actor_view_detail__13TUnk_804B9870Ffff(void);
void get_name__13TUnk_804B9870Fv(void);
void interact__13TUnk_804AF8A0Fl(void);

void *__vt__13TItemEffEquip[6] = {
    0, 0, (void *)__dt__13TItemEffEquipFv, (void *)run_task__13TItemEffEquipFv,
    (void *)render__7TObjectFv, (void *)render_shadows__7TObjectFv,
};
void *__vt__13TUnk_8049F038[14] = {
    0, 0, (void *)destroy__13TUnk_8049F038Fs, (void *)run_task__13TUnk_8049F038Fv,
    (void *)render__7TObjectFv, (void *)render_shadows__7TObjectFv,
    (void *)vfunc_6__13TUnk_804B9870FPsl, (void *)apply_object_set_data__13TUnk_804B9870FPv,
    (void *)reset_motion_fields__13TUnk_804AF8A0Fv, (void *)get_center__13TUnk_8049F038Fv,
    (void *)update_object_view_visibility__13TUnk_804B9870Fff, (void *)classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)get_name__13TUnk_804B9870Fv, (void *)interact__13TUnk_804AF8A0Fl,
};
}
