#include "types.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TODoorBase.h"
#include "pso/misc/TODoorFourLightBase.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TODoorAncient01.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjFish.h"

struct VBase_18_721d61 { char pad[0x18]; };

struct VObj_18_721d61 : VBase_18_721d61 {
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
    virtual s32 m19();
    virtual s32 m20();
};

struct DPre_802A0994 { s32 f0; u8 pad[0x14]; };

struct Door_802A0994 : DPre_802A0994 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(s32);
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
    u8 pad1c[0xD8 - 0x1C];
    s32 a[8];
    s32 f;
};

struct Door_802A0670 {
    u8 pad0[0x38];
    u8 f38[0x60 - 0x38];
    s32 f60;
    u8 pad64[0xC8 - 0x64];
    s32 fC8;
    u8 padCC[0xD0 - 0xCC];
    s32 fD0;
    u8 *fD4;
    u32 *a[4];
    u32 *b[4];
    s32 fF8;
};

struct VBase_802A07E0 { char pad[0x18]; };

struct VObj_802A07E0 : VBase_802A07E0 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
    virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12();
    virtual void m13(); virtual void m14(); virtual void m15(); virtual void m16();
    virtual void m17(); virtual void m18(); virtual void m19();
    virtual s32 m20();
};

extern "C" {
f32 rotate_matrix_by_node_angles(void *, void *);
s32 push_matrix();
s32 scale_current_matrix(void *);
f32 post_translate_matrix(void *);
void __ct__10TODoorBaseFP7TObject(void *, void *);
extern s32 __vt__19TODoorFourLightBase[];
extern s32 TODoorFourLightBase__class_name;
Door_802A0994 *TODoorFourLightBase__ct(Door_802A0994 *arg0, void *arg1, s32 arg2);
u8 is_current_floor_switch_set(int);
s32 rotate_matrix_y(int, int);
s32 draw_ginja_model_with_motion(s32, s32, f32);
void render__19TODoorFourLightBaseFv(TODoorFourLightBase *arg0);
void *__dt__19TODoorFourLightBaseFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);

s32 TODoorFourLightBase::init_door_switch_binding() {
    s32 temp_r0;

    this->switch_id = (s32) this->set_params[0];
    temp_r0 = this->switch_id;
    if (temp_r0 > 0x100) {
        this->lock_mode = 0;
    } else if (temp_r0 < 0) {
        this->lock_mode = 1;
    } else if ((s32) this->set_params[2] < 0) {
        if ((get_main_phase() == 0xF) || (TRaderMapCore::is_not_split_screen() == 1)) {
            this->lock_mode = 3;
        } else {
            this->lock_mode = 2;
        }
    } else {
        this->lock_mode = 2;
    }
    return this->switch_id;
}

void TODoorFourLightBase::vfunc_6(s16 *arg1, s32) {
    if ((s16) *arg1 == 1) {
        this->door_flags = (s32) (this->door_flags | 1);
    }
}

void TODoorFourLightBase::update_door_switch_state() {
    u8 *arg0 = (u8 *)this;
    s16 sp8;
    switch (this->lock_mode) {
    case 1:
        ((TODoorBase *)arg0)->play_door_sound();
        this->door_flags |= 1;
        break;
    case 2: {
        s32 found = 0;
        s32 i;
        for (i = 0; i < *(s32 *)&this->m_f8; i++) {
            if (((u8 (*)(u16))is_current_floor_switch_set)(this->switch_id + i) == 0) {
                found = 1;
            }
        }
        if (found != 0) {
            this->door_flags &= ~1;
        } else {
            ((TODoorBase *)arg0)->play_door_sound();
            this->door_flags |= 1;
        }
        break;
    }
    case 3: {
        s32 found;
        s32 i;
        if (this->door_flags & 1) {
            break;
        }
        found = 0;
        for (i = 0; i < *(s32 *)&this->m_f8; i++) {
            if (((u8 (*)(u16))is_current_floor_switch_set)(this->switch_id + i) == 0) {
                found = 1;
            }
        }
        if (found != 0) {
            this->door_flags &= ~1;
        } else {
            ((TODoorBase *)arg0)->play_door_sound();
            this->door_flags |= 1;
        }
        if (found == 0 && this->set_entry != NULL && ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 1) == 1) {
            sp8 = 1;
            ((TObjCollidable *)arg0)->send_object_state_update(&sp8);
            ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 0);
        }
        break;
    }
    default:
        this->door_flags &= ~1;
        break;
    }
}

void TODoorFourLightBase::draw_node_tree(u8 *arg1) {
    s32 temp_r31;
    u8 *temp_r4;
    u8 *var_r30;
    var_r30 = arg1;
    do {
        temp_r31 = *(s32 *)((s8 *)var_r30 + 0);
        if (temp_r31 & 0x100000) {
            TObjFish::set_global_param((s32)((void *) (((VObj_18_721d61 *)(this))->m20())));
        } else {
            TObjFish::set_global_param((s32)((void *) (((VObj_18_721d61 *)(this))->m19())));
        }
        if (*(s32 *)((s8 *)var_r30 + 0) & 0x200000) {
            TParticleCtrl::begin_effect_render();
        } else {
            TParticleCtrl::end_effect_render();
        }
        push_matrix();
        if (!(temp_r31 & 1)) {
            post_translate_matrix(var_r30 + 8);
        }
        if (!(temp_r31 & 2)) {
            rotate_matrix_by_node_angles(var_r30 + 0x14, (void *) (temp_r31 & 0x20));
        }
        if (!(temp_r31 & 4)) {
            scale_current_matrix(var_r30 + 0x20);
        }
        if (!(temp_r31 & 8)) {
            draw_ginja_model((*(s32 *)((s8 *)var_r30 + 4)));
        }
        if (!(temp_r31 & 0x10)) {
            temp_r4 = (u8 *)(*(u8 **)((s8 *)var_r30 + 0x2C));
            if (temp_r4 != NULL) {
                draw_node_tree(temp_r4);
            }
        }
        pop_matrix();
        var_r30 = (u8 *)(*(u8 **)((s8 *)var_r30 + 0x30));
    } while (var_r30 != NULL);
}

void TODoorFourLightBase::render_lights() {
    Door_802A0670 *self = (Door_802A0670 *)this;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (self->a[i] != NULL) {
            *self->a[i] |= 0x100000;
            *self->a[i] |= 0x200000;
        }
        if (self->b[i] != NULL) {
            *self->b[i] |= 0x100000;
            *self->a[i] |= 0x200000;
        }
    }
    if (!(self->fD0 & 1)) {
        for (i = 0; i < self->fF8; i++) {
            if (is_current_floor_switch_set((u16)(self->fC8 + i)) == 1) {
                if (self->a[i] != NULL) {
                    *self->a[i] |= 0x100000;
                }
                if (self->b[i] != NULL) {
                    *self->b[i] |= 0x100000;
                }
            } else {
                if (self->a[i] != NULL) {
                    *self->a[i] &= ~0x100000;
                }
                if (self->b[i] != NULL) {
                    *self->b[i] &= ~0x100000;
                }
            }
        }
    }
    push_matrix();
    post_translate_matrix(self->f38);
    rotate_matrix_y(0, self->f60);
    ((TODoorFourLightBase *)self)->draw_node_tree(self->fD4);
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

struct Door_802A0670;
void render__19TODoorFourLightBaseFv(TODoorFourLightBase *door_four_light_base) {
    VObj_802A07E0 *self = (VObj_802A07E0 *)door_four_light_base;
    if (self->m8(door_four_light_base->m_c0, *(f32 *)((s8 *)door_four_light_base + 0xC4)) != 1) {
        return;
    }
    switch (door_four_light_base->m_ac) {
    case 1:
    case 3:
        push_matrix();
        TObjFish::set_global_param((s32)((void *)self->m20()));
        post_translate_matrix((u8 *)door_four_light_base + 0x38);
        rotate_matrix_y(0, door_four_light_base->rotation_y);
        draw_ginja_model_with_motion(door_four_light_base->m_d4, door_four_light_base->m_bc, door_four_light_base->m_b0);
        pop_matrix();
        break;
    case 2:
        push_matrix();
        TObjFish::set_global_param((s32)((void *)self->m20()));
        post_translate_matrix((u8 *)door_four_light_base + 0x38);
        rotate_matrix_y(0, door_four_light_base->rotation_y);
        draw_ginja_model_with_motion(door_four_light_base->m_d4, door_four_light_base->m_bc, *(f32 *)((s8 *)door_four_light_base + 0xB4));
        pop_matrix();
        break;
    case 0:
        if (door_four_light_base->lock_mode == 2 || door_four_light_base->lock_mode == 3) {
            door_four_light_base->render_lights();
            break;
        }
        push_matrix();
        TObjFish::set_global_param((s32)((void *)self->m20()));
        post_translate_matrix((u8 *)door_four_light_base + 0x38);
        rotate_matrix_y(0, door_four_light_base->rotation_y);
        draw_ginja_object((void *)door_four_light_base->m_d4);
        pop_matrix();
        break;
    }
}

void *__dt__19TODoorFourLightBaseFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TODoorFourLightBase;
        __dt__10TODoorBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
Door_802A0994 *TODoorFourLightBase__ct(Door_802A0994 *arg0, void *arg1, s32 arg2) {
    s32 i;
    __ct__10TODoorBaseFP7TObject(arg0, arg1);
    *(void **)((u8 *)arg0 + 0x18) = ((s32 *)&__vt__19TODoorFourLightBase);
    arg0->f0 = TODoorFourLightBase__class_name;
    arg0->m5(arg2);
    arg0->m17();
    for (i = 0; i < 8; i++) {
        arg0->a[i] = 0;
    }
    arg0->f = 0;
    return arg0;
}

}
