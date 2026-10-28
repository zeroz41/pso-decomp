#include "types.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TOExplosiveMachine.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/object/TObjMotion.h"

struct Base1_80166568 { char pad[0x18]; };
struct VObj1_80166568 : Base1_80166568 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};
struct Base_A_801668cc_80166568 { char pad[0x18]; };
struct V_A_801668cc_80166568 : Base_A_801668cc_80166568 {
    virtual void f0();
    virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6();
    virtual void f7(); virtual void f8(); virtual void f9();
    virtual void f10(); virtual void f11(); virtual void f12();
    virtual void f13();
    virtual void m14();
};

struct RecoveredGlobal_80166614_lbl_804B1AA0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80166614_lbl_804B1AA0_size[sizeof(RecoveredGlobal_80166614_lbl_804B1AA0) == 0x10 ? 1 : -1];

struct O_80166664 { u8 pad[0x18]; void *vt; u8 pad1c[0x9C - 0x1C]; s32 a[2]; s32 b[2]; };

struct O_801666E8 { s32 id; u8 pad4[0x14]; void *vt; u8 pad1c[0x68 - 0x1C]; f32 f68; u8 pad6c[0x90 - 0x6C]; f32 f90; f32 f94; f32 f98; s32 a[2]; s32 b[2]; };

struct VBase_80166778 { char pad[0x18]; };

struct VObj_80166778 : VBase_80166778 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual s32 m12();
};

struct VBase_80166814 { char pad[0x18]; };

struct VObj_80166814 : VBase_80166814 {
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
    virtual s32 m13();
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80166614_lbl_804B1AA0 explosive_machine_resource_desc;
extern u32 explosive_machine_model_archive;
void __dl__7TObjectFPv(void *);
extern char __vt__18TOExplosiveMachine[];
O_80166664 *__dt__18TOExplosiveMachineFv(O_80166664 *arg0, s16 arg1);
void __ct__13TUnk_804B9870FP7TObject(void *, s32);
extern s32 TOExplosiveMachine__class_name;
extern s32 tl_05;
extern const f32 lbl_805DB5F0;
extern const f32 lbl_805DB5F4;
extern const f32 lbl_805DB5F8;
O_801666E8 *TOExplosiveMachine__ct(O_801666E8 *arg0);
s32 is_any_player_within_radius_xz(f32);
u8 is_current_floor_switch_set(u16);
extern const f32 lbl_805DB600;
extern const f32 lbl_805DB604;
void TLobby__sub_8001FE7C(void*, int);
s32 post_translate_matrix(void *);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();

void TOExplosiveMachine::explode() {
    u8 *arg0 = (u8 *)this;
    VObj1_80166568 *self = (VObj1_80166568 *)arg0;
    if (self->m8(*(f32 *)&this->unk_90, this->m_94) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texture_id);
        draw_ginja_object(this->model);
        pop_matrix();
    }
}

void TOExplosiveMachine::destroy_static_lobby() {
    if ((u32) explosive_machine_model_archive != 0U) {
        TLobby__sub_8001FE7C((void*)explosive_machine_model_archive, 1);
        explosive_machine_model_archive = 0U;
    }
}

extern const f32 lbl_805DB608;

void TOExplosiveMachine::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &explosive_machine_resource_desc.value, 0, 0, 0));
    }
    (*(s32 *)&explosive_machine_model_archive) = var_r0;
}

O_80166664 *__dt__18TOExplosiveMachineFv(O_80166664 *arg0, s16 arg1) {
    s32 i;
    if (arg0 != NULL) {
        arg0->vt = __vt__18TOExplosiveMachine;
        for (i = 0; i < 2; i++) {
            arg0->a[i] = 0;
            arg0->b[i] = 0;
        }
        __dt__13TUnk_804B9870Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

O_801666E8 *TOExplosiveMachine__ct(O_801666E8 *arg0) {
    s32 i;
    __ct__13TUnk_804B9870FP7TObject(arg0, tl_05);
    arg0->vt = __vt__18TOExplosiveMachine;
    arg0->id = TOExplosiveMachine__class_name;
    arg0->f90 = lbl_805DB5F0;
    arg0->f94 = lbl_805DB5F4;
    arg0->f98 = lbl_805DB5F8 + arg0->f68;
    for (i = 0; i < 2; i++) {
        arg0->a[i] = 0;
        arg0->b[i] = 0;
    }
    return arg0;
}

s32 TOExplosiveMachine::check_trigger() {
    switch (*(s32 *)((s8 *)this + 0xC8)) {
    case 0:
        break;
    case 1:
        if (is_any_player_within_radius_xz(lbl_805DB600) == 1) {
            ((VObj_80166778 *)this)->m12();
        }
        break;
    case 2:
        if (is_current_floor_switch_set(*(s32 *)((s8 *)this + 0xCC)) == 1) {
            ((VObj_80166778 *)this)->m12();
        }
        break;
    }
}

s32 TOExplosiveMachine::update_trigger() {
    switch (*(s32 *)((s8 *)this + 0xC8)) {
    case 0:
        break;
    case 1:
        if (is_any_player_within_radius_xz(lbl_805DB604) != 1) {
            ((VObj_80166814 *)(this))->m13();
        }
        break;
    case 2:
        if (is_current_floor_switch_set(*(s32 *)((s8 *)this + 0xCC)) != 1) {
            ((VObj_80166814 *)(this))->m13();
        }
        break;
    }
    play_persistent_sound(0x4004C10F, (s32)this, (u32)((u8 *)this + 0x38), 0, 0);
}

void TOExplosiveMachine::update() {
    f32 temp_f0;
    f32 temp_f1;

    if (TObjPlayer::check_demo_mode() == 1) {
        ((V_A_801668cc_80166568 *)this)->m14();
        return;
    }
    switch (*(s32 *)((s8 *)this + 0xAC)) {
    case 0:
        check_trigger();
        break;
    case 1:
        update_trigger();
        break;
    }
    *(f32 *)((s8 *)this + 0xB0) = (f32) (*(f32 *)((s8 *)this + 0xB0) + lbl_805DB608);
    temp_f1 = *(f32 *)((s8 *)this + 0xB4);
    temp_f0 = *(f32 *)((s8 *)this + 0xB0);
    if (temp_f1 < temp_f0) {
        *(f32 *)((s8 *)this + 0xB0) = (f32) (temp_f0 - temp_f1);
    }
}

}
