#include "types.h"
#include "pso/enemy/TObjEneDD_800BA138.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"

struct Base_800BA138 { char pad[0x18]; };
struct VObj_800BA138 : Base_800BA138 {
    virtual void g0();
#define VM(n) virtual void m##n();
    VM(0) VM(1) VM(2) VM(3) VM(4) VM(5) VM(6) VM(7) VM(8) VM(9)
    VM(10) VM(11) VM(12) VM(13) VM(14) VM(15) VM(16) VM(17) VM(18) VM(19)
    VM(20) VM(21) VM(22) VM(23) VM(24) VM(25) VM(26) VM(27) VM(28) VM(29)
    VM(30) VM(31) VM(32) VM(33) VM(34) VM(35) VM(36) VM(37) VM(38) VM(39)
    VM(40) VM(41) VM(42) VM(43) VM(44) VM(45) VM(46) VM(47) VM(48) VM(49)
    VM(50) VM(51) VM(52) VM(53) VM(54) VM(55) VM(56) VM(57) VM(58) VM(59)
    VM(60) VM(61) VM(62) VM(63) VM(64) VM(65) VM(66) VM(67) VM(68) VM(69)
    VM(70) VM(71) VM(72) VM(73) VM(74) VM(75) VM(76) VM(77) VM(78) VM(79)
    VM(80) VM(81) VM(82) VM(83) VM(84) VM(85) VM(86) VM(87)
#undef VM
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
};

#include <stddef.h>
struct VBase_18_0c879f { char pad[0x18]; };

struct VObj_18_0c879f : VBase_18_0c879f {
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
    virtual s32 m21(s32, s32 *, s32, s32, s32);
};

struct Stack_800BA318 {
    s32 sp8;
    s32 spC;
};

struct RecoveredGlobal_800BA318_lbl_8043B68C {
    s32 value;
    u8 remaining[0x8];
};

struct E_800BA1C8 { u8 pad[0x18]; u32 flags; u8 pad2[0x10]; };

struct O_800BA1C8 { u8 pad[0xa4]; E_800BA1C8 *entries; s32 count; };

struct E_800BA190 { u8 pad[0x18]; u32 flags; u8 pad2[0x10]; };

struct O_800BA190 { u8 pad[0xa4]; E_800BA190 *entries; s32 count; };

struct Part_800BA200 { u8 pad[0x18]; u32 flags; u8 pad2[0x2c - 0x1c]; };

struct Obj_800BA200 { u8 pad[0x30]; u32 flags; u8 pad2[0xa4 - 0x34]; Part_800BA200 *parts; s32 count; };

struct Part_800BA244 { u8 pad[0x18]; u32 flags; u8 pad2[0x2c - 0x1c]; };

struct Obj_800BA244 { u8 pad[0x30]; u32 flags; u8 pad2[0xa4 - 0x34]; Part_800BA244 *parts; s32 count; };

extern "C" {
extern RecoveredGlobal_800BA318_lbl_8043B68C lbl_8043B68C;
extern RecoveredGlobal_800BA318_lbl_8043B68C lbl_8043B684;
extern RecoveredGlobal_800BA318_lbl_8043B68C lbl_8043B67C;
extern RecoveredGlobal_800BA318_lbl_8043B68C lbl_8043B674;
struct EneDDBase2_800BA138 { char pad[0x18]; };
struct EneDDObj2_800BA138 : EneDDBase2_800BA138 {
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
    virtual void m15(void *, void *);
    virtual void m16(void *, void *);
};
struct EneDDBase_800BA138 { char pad[0x18]; };
struct EneDDObj_800BA138 : EneDDBase_800BA138 {
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
    virtual void m12(void *, void *, void *);
    virtual void m13(void *, void *, void *);
};

int is_target_unobstructed__9TObjEneDDFl(void* a0 = 0, void* a1 = 0, void* a2 = 0);
int add_flags_2e4__9TObjCharaFUl(void*, int);
s32 all_parents_unqueued_for_destruction__7TObjectFv();
s32 get_position__12TBoss1DragonFv(void *, s32);

void TObjEneDD::vfunc_95() {
    struct VObj_800BA138 *o = (struct VObj_800BA138 *)this;
    o->m88();
    o->m91();
    this->actorFlags = (s32) (this->actorFlags | 0x04040000);
}

void TObjEneDD::vfunc_94() {
    O_800BA190 *self = (O_800BA190 *)this;
    s32 i;
    for (i = 0; i < self->count; i++) {
        self->entries[i].flags &= ~1;
    }
}

void TObjEneDD::vfunc_93() {
    O_800BA1C8 *self = (O_800BA1C8 *)this;
    s32 i;
    for (i = 0; i < self->count; i++) {
        self->entries[i].flags |= 1;
    }
}

void TObjEneDD::vfunc_92() {
    Obj_800BA200 *self = (Obj_800BA200 *)this;
    s32 i;
    this->actorFlags &= ~0x04000000;
    for (i = 0; i < self->count; i++) {
        self->parts[i].flags &= ~0x02000000;
    }
}

void TObjEneDD::vfunc_91() {
    Obj_800BA244 *self = (Obj_800BA244 *)this;
    s32 i;
    this->actorFlags |= 0x04000000;
    for (i = 0; i < self->count; i++) {
        self->parts[i].flags |= 0x02000000;
    }
}

int TObjEneDD::set_state_8() { return add_flags_2e4__9TObjCharaFUl(this, 8); }
int TObjEneDD::check_state_flag_4() { return add_flags_2e4__9TObjCharaFUl(this, 4); }
int TObjEneDD::check_state_flag_2() { return add_flags_2e4__9TObjCharaFUl(this, 2); }
int TObjEneDD::check_state_flag_1() { return add_flags_2e4__9TObjCharaFUl(this, 1); }

typedef char RecoveredGlobal_800BA318_lbl_8043B68C_size[sizeof(RecoveredGlobal_800BA318_lbl_8043B68C) == 0xC ? 1 : -1];
void TObjEneDD::send_damage_message(s32 arg0, u8 *arg1) {
    typedef char sp8_offset[(offsetof(Stack_800BA318, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800BA318, spC) == 0x4) ? 1 : -1];
    Stack_800BA318 stack;
    stack.sp8 = *(s32 *)((s8 *)&lbl_8043B68C.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_8043B68C.value + 4);
    ((VObj_18_0c879f *)(arg1))->m21(arg0, &stack.sp8, 0, -1, -1);
}

void TObjEneDD__sub_800BA378(s32 arg0, u8 *arg1) {
    typedef char sp8_offset[(offsetof(Stack_800BA318, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800BA318, spC) == 0x4) ? 1 : -1];
    Stack_800BA318 stack;
    stack.sp8 = *(s32 *)((s8 *)&lbl_8043B684.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_8043B684.value + 4);
    ((VObj_18_0c879f *)(arg1))->m21(arg0, &stack.sp8, 0, -1, -1);
}

void TObjEneDD::inflict_poison(s32 arg0, u8 *arg1) {
    typedef char sp8_offset[(offsetof(Stack_800BA318, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800BA318, spC) == 0x4) ? 1 : -1];
    Stack_800BA318 stack;
    stack.sp8 = *(s32 *)((s8 *)&lbl_8043B67C.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_8043B67C.value + 4);
    ((VObj_18_0c879f *)(arg1))->m21(arg0, &stack.sp8, 0, -1, -1);
}

void TObjEneDD__sub_800BA438(s32 arg0, u8 *arg1) {
    typedef char sp8_offset[(offsetof(Stack_800BA318, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800BA318, spC) == 0x4) ? 1 : -1];
    Stack_800BA318 stack;
    stack.sp8 = *(s32 *)((s8 *)&lbl_8043B674.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_8043B674.value + 4);
    ((VObj_18_0c879f *)(arg1))->m21(arg0, &stack.sp8, 0, -1, -1);
}

void TObjEneDD::emit_effect_at_position(void* a1) { TObjEneDD::emit_enemy_effect((s32)this, (s32)((char*)this + 0x38), (u8 *)a1, (s32)((void*)0)); }

void TObjEneDD::emit_effect(void* p, int a1, int a2) { TObjEneDD::emit_enemy_effect((s32)p, (s32)a1, (u8 *)a2, 0); }

extern u8 *obj_ene_dd_instance;
extern const f32 lbl_805D9EA0;

void TObjEneDD::emit_enemy_effect(s32 arg0, s32 arg1, u8 *arg2, s32 arg3) {
    ((TUnk_804928CC *)obj_ene_dd_instance)->sub_800BC3E8((u8 *)arg0);
    get_position__12TBoss1DragonFv(obj_ene_dd_instance, arg1);
    *(f32 *)((s8 *)(*(void **)((s8 *)obj_ene_dd_instance + 0xA4)) + 0xC) = (f32) *(f32 *)((s8 *)arg2 + 8);
    *(s32 *)((s8 *)(*(void **)((s8 *)obj_ene_dd_instance + 0xA4)) + 0x18) = 0x9D03;
    if (*(f32 *)((s8 *)arg2 + 8) > lbl_805D9EA0) {
        ((EneDDObj2_800BA138*)obj_ene_dd_instance)->m16(arg2 + 0xC, (void*)arg3);
        return;
    }
    ((EneDDObj2_800BA138*)obj_ene_dd_instance)->m15(arg2 + 0xC, (void*)arg3);
}

void TObjEneDD__sub_800BA5A4(void* p, void* a1) { TObjEneDD::setup_instance((s32)p, (s32)((char*)p + 0x38), (u8 *)a1, (s32)((void*)0)); }

void TObjEneDD::setup(void* p, int a1, int a2) { TObjEneDD::setup_instance((s32)p, (s32)a1, (u8 *)a2, 0); }

void TObjEneDD::setup_instance(s32 arg0, s32 arg1, u8 *arg2, s32 arg3) {
    ((TUnk_804928CC *)obj_ene_dd_instance)->sub_800BC3E8((u8 *)arg0);
    get_position__12TBoss1DragonFv(obj_ene_dd_instance, arg1);
    *(f32 *)((s8 *)(*(void **)((s8 *)obj_ene_dd_instance + 0xA4)) + 0xC) = (f32) *(f32 *)((s8 *)arg2 + 8);
    *(s32 *)((s8 *)(*(void **)((s8 *)obj_ene_dd_instance + 0xA4)) + 0x18) = 0x9D03;
    if (*(f32 *)((s8 *)arg2 + 8) > lbl_805D9EA0) {
        ((EneDDObj_800BA138*)obj_ene_dd_instance)->m13(arg2 + 0xC, (void*)arg2, (void*)arg3);
        return;
    }
    ((EneDDObj_800BA138*)obj_ene_dd_instance)->m12(arg2 + 0xC, (void*)arg2, (void*)arg3);
}

int is_target_android(void* p) { return (((TObjPlayer *)p)->class_flags & CLASS_FLAG_ANDROID) != 0; }
int is_target_ranger(void* p) { return (((TObjPlayer *)p)->class_flags & CLASS_FLAG_RANGER) != 0; }
u8 TObjEneDD::is_alive() {
    int var_r31;

    var_r31 = 0;
    if ((this != NULL) && (all_parents_unqueued_for_destruction__7TObjectFv() != 0) && !(this->actorFlags & 0x02040800)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}
void TObjEneDD::transform_relative_position(void* a1) { is_target_unobstructed__9TObjEneDDFl(a1, (char*)this + 0x2fc, this); }

}
