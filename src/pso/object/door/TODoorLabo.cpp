#include "types.h"
#include "pso/render/NinjaUtil.h"
#include "pso/unk/TLobby.h"
#include "pso/object/door/TODoorFourLightBase.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/seabed/TObjSeabedSuisoBrakable.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/door/TODoorLabo.h"
#include "pso/object/door/TODoorLaboNormal.h"
#include "pso/object/door/TODoorFourLightSeabedU.h"
#include "pso/object/door/TODoorFourLightSeabed.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/map/FloorArea.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/door/TODoorBase.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/door/TODoorAncient01.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/text_803D8F74.h"

#pragma defer_codegen on
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern "C" {
__declspec(section ".data") const char *bm_o_door_seabed01_model_names[2] = { "fs_obj_doorx4_atui.gj", NULL };
__declspec(section ".data") const char *bm_o_door_seabed01_motion_names[2] = { "fs_obj_doorx4_atui.njm", NULL };
BmlResourceDescriptor bm_o_door_seabed01_resource_descriptor = { "bm_o_door_seabed01.bml", bm_o_door_seabed01_model_names, bm_o_door_seabed01_motion_names, 1, 1 };
__declspec(section ".data") const char *bm_o_door_seabed01_u_model_names[2] = { "fs_obj_doorx4_u.gj", NULL };
__declspec(section ".data") const char *bm_o_door_seabed01_u_motion_names[2] = { "fs_obj_doorx4_u.njm", NULL };
BmlResourceDescriptor bm_o_door_seabed01_u_resource_descriptor = { "bm_o_door_seabed01_u.bml", bm_o_door_seabed01_u_model_names, bm_o_door_seabed01_u_motion_names, 1, 1 };
__declspec(section ".data") const char *bm_obj_door_labo_model_names[3] = { "obj_o_labodoor_l.gj", "obj_o_labodoor_l2.gj", NULL };
__declspec(section ".data") const char *bm_obj_door_labo_motion_names[2] = { "obj_o_labodoor_l.njm", NULL };
BmlResourceDescriptor labo_door_resource_descriptor = { "bm_obj_door_labo.bml", bm_obj_door_labo_model_names, bm_obj_door_labo_motion_names, 2, 1 };
__declspec(section ".data") const char *bm_obj_labodoor_nrm_model_names[2] = { "obj_m_cdoor_l.gj", NULL };
__declspec(section ".data") const char *bm_obj_labodoor_nrm_motion_names[2] = { "obj_m_cdoor_l.njm", NULL };
BmlResourceDescriptor labo_door_resource_descriptor_2 = { "bm_obj_labodoor_nrm.bml", bm_obj_labodoor_nrm_model_names, bm_obj_labodoor_nrm_motion_names, 1, 1 };
}
CollisionBody labo_door_collision_body_parts[] = {
    {{0.0f, 20.0f, 0.0f}, 10.0f, 20.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
// The BML archives and texture lists the door classes load and free (TODoorFourLightSeabed,
// TODoorFourLightSeabedU, TODoorLabo, TODoorLaboNormal), in address order.
s32 door_labo_bml_resource;
s32 lbl_805D6604;
s32 lbl_805D6608;
u32 seabed_four_light_door_bml_resource;
s32 seabed_four_light_door_textures;
s32 TODoorFourLightSeabedU__texture_list;
s32 TODoorLabo__bml_resource;
s32 TODoorLabo__green_texture_list;
s32 labo_door_red_textures;
u32 TODoorLabo__model_archive;
u32 TODoorLaboNormal__green_texture_list;
u32 TODoorLaboNormal__red_texture_list;
struct Tbl_8029F7E0 { s32 v[8]; };
struct Res_8029F7E0 { u32 f0; u32 f4; };
struct Self_8029F7E0 {
    const char *f0;
    u8 pad4[0x14];
    void *vt;
    u8 pad1c[0xB4 - 0x1C];
    f32 fB4;
    f32 fB8;
    Res_8029F7E0 *fBC;
    u8 padc0[4];
    f32 fC4;
    u8 padc8[0xD8 - 0xC8];
    s32 fD8[8];
    s32 fF8;
};
struct Tbl_8029FAE4 { s32 v[8]; };
struct Door_8029FAE4 {
    const char *f0;
    u8 pad4[0x18 - 0x4];
    void *vt;
    u8 pad1c[0xB4 - 0x1C];
    f32 fB4;
    f32 fB8;
    u8 *fBC;
    u8 padC0[0xC4 - 0xC0];
    f32 fC4;
    u8 padC8[0xD4 - 0xC8];
    s32 fD4;
    s32 sw[8];
    s32 fF8;
};
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
struct DPre_802A0994 { const char *f0; u8 pad[0x14]; };
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
Door_802A0994 *TODoorFourLightBase__ct(Door_802A0994 *arg0, void *arg1, s32 arg2);
u8 is_current_floor_switch_set(int);
s32 draw_ginja_model_with_motion(s32, s32, f32);
void render__19TODoorFourLightBaseFv(TODoorFourLightBase *arg0);
Res_8029F7E0 *get_bml_motion(s32, s32);
void init_collision_body_parts(void *, void *, s32);
extern s32 __vt__16TODoorLaboNormal[];
extern s32 __vt__10TODoorLabo[];
Self_8029F7E0 *TODoorLaboNormal__ct(Self_8029F7E0 *self, void *parent, s32 arg);
s32 load_resource_from_descriptor(s32, int, void *, int, int, int);
u8 *load_gvm_texture_file(const char *arg0);
s32 get_bml_model(s32, s32);
Door_8029FAE4 *TODoorLabo__ct(Door_8029FAE4 *arg0, void *parent, s32 arg);
void free_bin_model_request(void*, int);
s32 release_texture_list(void*);
void free_collision_body_parts(void *);
}
extern s32 __vt__22TODoorFourLightSeabedU[];
struct Tbl_8029FD70 { s32 w[8]; };
struct Info_8029FD70 { u8 pad[4]; u32 v4; };
struct Door_8029FD70 {
    const char *f0;
    u8 pad4[0x14];
    void *vt18;
    u8 pad1c[0xB4 - 0x1C];
    f32 fB4;
    f32 fB8;
    Info_8029FD70 *infoBC;
    u8 padC0[0xD4 - 0xC0];
    s32 fD4;
    s32 fD8[8];
};
extern s32 __vt__21TODoorFourLightSeabed[];
struct Tbl_802A0068 { s32 w[8]; };
struct Info_802A0068 { u8 pad[4]; u32 v4; };
struct Door_802A0068 {
    const char *f0;
    u8 pad4[0x14];
    void *vt18;
    u8 pad1c[0xB4 - 0x1C];
    f32 fB4;
    f32 fB8;
    Info_802A0068 *infoBC;
    u8 padC0[0xD4 - 0xC0];
    s32 fD4;
    s32 fD8[8];
};
extern "C" {
struct Door_802A0670;
}

const char *TODoorFourLightBase__class_name = "TODoorFourLightBase";

extern "C" {
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
TODoorFourLightBase::~TODoorFourLightBase() {

}

extern "C" {
void render__19TODoorFourLightBaseFv(TODoorFourLightBase *door_four_light_base) {
    VObj_802A07E0 *self = (VObj_802A07E0 *)door_four_light_base;
    if (self->m8(door_four_light_base->view_range, *(f32 *)((s8 *)door_four_light_base + 0xC4)) != 1) {
        return;
    }
    switch (door_four_light_base->object_state) {
    case 1:
    case 3:
        push_matrix();
        TObjFish::set_global_param((s32)((void *)self->m20()));
        post_translate_matrix((u8 *)door_four_light_base + 0x38);
        rotate_matrix_y(0, door_four_light_base->rotation_y);
        draw_ginja_model_with_motion(door_four_light_base->m_d4, (s32)door_four_light_base->motion, door_four_light_base->animation_frame);
        pop_matrix();
        break;
    case 2:
        push_matrix();
        TObjFish::set_global_param((s32)((void *)self->m20()));
        post_translate_matrix((u8 *)door_four_light_base + 0x38);
        rotate_matrix_y(0, door_four_light_base->rotation_y);
        draw_ginja_model_with_motion(door_four_light_base->m_d4, (s32)door_four_light_base->motion, door_four_light_base->animation_end_frame);
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

void TODoorFourLightBase::vfunc_6(s16 *arg1, s32) {
    if ((s16) *arg1 == 1) {
        this->door_flags = (s32) (this->door_flags | 1);
    }
}

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

void TODoorFourLightBase::clamp_light_index() {
    if ((s32) this->set_params[1] < 0) {
        this->set_params[1] = 0;
    }
    if ((s32) this->set_params[1] > 4) {
        *(s32 *)&this->set_params[1] = 4;
    }
    this->m_f8 = (s32) this->set_params[1];
}

void TLanguage__sub_802A0204(void) {
    s32 area;
    s32 var_r0;
    s32 var_r0_2;
    area = get_current_floor_area();
    switch (area) {
    case AREA_SEABED_UPPER:
        var_r0 = (int)::operator new(0x440);
        if (var_r0 != 0) {
            var_r0 = load_resource_from_descriptor(var_r0, 5, &bm_o_door_seabed01_resource_descriptor, 0, 0, 0);
        }
        door_labo_bml_resource = var_r0;
        lbl_805D6604 = (u32)load_gvm_texture_file("fs_obj_doorx4_atui_green.GVM");
        lbl_805D6608 = (u32)load_gvm_texture_file("fs_obj_doorx4_atui.GVM");
        return;
    case AREA_SEABED_LOWER:
        var_r0_2 = (int)::operator new(0x440);
        if (var_r0_2 != 0) {
            var_r0_2 = load_resource_from_descriptor(var_r0_2, 5, &bm_o_door_seabed01_resource_descriptor, 0, 0, 0);
        }
        door_labo_bml_resource = var_r0_2;
        lbl_805D6604 = (u32)load_gvm_texture_file("fs_obj_doorx4_atui_green_02.GVM");
        lbl_805D6608 = (u32)load_gvm_texture_file("fs_obj_doorx4_atui_02.GVM");
        return;
    }
}

void TLobby::free_chr_select_slots() {
    if ((u32) lbl_805D6608 != 0U) {
        release_texture_list((void*)lbl_805D6608);
        TAdSinglePlyChrSelectGC::safe_free(lbl_805D6608);
        lbl_805D6608 = 0U;
    }
    if ((u32) lbl_805D6604 != 0U) {
        release_texture_list((void*)lbl_805D6604);
        TAdSinglePlyChrSelectGC::safe_free(lbl_805D6604);
        lbl_805D6604 = 0U;
    }
    if ((u32) door_labo_bml_resource != 0U) {
        free_bin_model_request((void*)door_labo_bml_resource, 1);
        door_labo_bml_resource = 0U;
    }
}

}
const char *TODoorFourLightSeabed__class_name = "TODoorFourLightSeabed";
const Tbl_802A0068 door_four_light_seabed_index_table = {{2, 4, 9, 11, 3, 5, 10, 12}};

u8 *TODoorFourLightSeabed__ct(u8 *arg0, void *parent, s32 arg) {
    s32 i;
    TODoorFourLightBase__ct((Door_802A0994 *)arg0, parent, arg);
    ((Door_802A0068 *)arg0)->vt18 = __vt__21TODoorFourLightSeabed;
    ((Door_802A0068 *)arg0)->f0 = TODoorFourLightSeabed__class_name;
    init_collision_body_parts(arg0, labo_door_collision_body_parts, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((Door_802A0068 *)arg0)->fD4 = get_bml_model(door_labo_bml_resource, 0);
    ((Door_802A0068 *)arg0)->infoBC = (Info_802A0068 *)get_bml_motion(door_labo_bml_resource, 0);
    ((Door_802A0068 *)arg0)->fB4 = (f32)((Door_802A0068 *)arg0)->infoBC->v4 - 1.0f;
    ((Door_802A0068 *)arg0)->fB8 = 0.5f;
    {
        Tbl_802A0068 tbl = door_four_light_seabed_index_table;
        for (i = 0; i < 8; i++) {
            ((Door_802A0068 *)arg0)->fD8[i] = (s32)find_object_node((NJS_OBJECT *)(((Door_802A0068 *)arg0)->fD4), tbl.w[i]);
        }
    }
    ((TODoorFourLightBase *)arg0)->clamp_light_index();
    return arg0;
}


TODoorFourLightSeabed::~TODoorFourLightSeabed() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

s32 TODoorFourLightSeabed::vfunc_21() {
    return lbl_805D6608;
}

s32 TODoorFourLightSeabed::vfunc_22() {
    return lbl_805D6604;
}

void TLanguage__sub_8029FF0C(void) {
    s32 area;
    s32 var_r0;
    s32 var_r0_2;
    area = get_current_floor_area();
    switch (area) {
    case AREA_SEABED_UPPER:
        var_r0 = (int)::operator new(0x440);
        if (var_r0 != 0) {
            var_r0 = load_resource_from_descriptor(var_r0, 5, &bm_o_door_seabed01_u_resource_descriptor, 0, 0, 0);
        }
        seabed_four_light_door_bml_resource = var_r0;
        seabed_four_light_door_textures = (s32)load_gvm_texture_file("fs_obj_doorx4_u_green.GVM");
        TODoorFourLightSeabedU__texture_list = (s32)load_gvm_texture_file("fs_obj_doorx4_u.GVM");
        return;
    case AREA_SEABED_LOWER:
        var_r0_2 = (int)::operator new(0x440);
        if (var_r0_2 != 0) {
            var_r0_2 = load_resource_from_descriptor(var_r0_2, 5, &bm_o_door_seabed01_u_resource_descriptor, 0, 0, 0);
        }
        seabed_four_light_door_bml_resource = var_r0_2;
        seabed_four_light_door_textures = (s32)load_gvm_texture_file("fs_obj_doorx4_usui_green_02.GVM");
        TODoorFourLightSeabedU__texture_list = (s32)load_gvm_texture_file("fs_obj_doorx4_usui_02.GVM");
        return;
    }
}

void TLobby::free_global_buffers() {
    if ((u32) TODoorFourLightSeabedU__texture_list != 0U) {
        release_texture_list((void*)TODoorFourLightSeabedU__texture_list);
        TAdSinglePlyChrSelectGC::safe_free(TODoorFourLightSeabedU__texture_list);
        TODoorFourLightSeabedU__texture_list = 0U;
    }
    if ((u32) seabed_four_light_door_textures != 0U) {
        release_texture_list((void*)seabed_four_light_door_textures);
        TAdSinglePlyChrSelectGC::safe_free(seabed_four_light_door_textures);
        seabed_four_light_door_textures = 0U;
    }
    if ((u32) seabed_four_light_door_bml_resource != 0U) {
        free_bin_model_request((void*)seabed_four_light_door_bml_resource, 1);
        seabed_four_light_door_bml_resource = 0U;
    }
}

const char *odoor_four_light_seabed_u_class_name = "TODoorFourLightSeabedU";
const Tbl_8029FD70 door_four_light_seabed_u_table = {{2, 4, 7, 9, 3, 5, 8, 10}};

u8 *TODoorFourLightSeabedU__ct(u8 *arg0, void *parent, s32 arg) {
    s32 i;
    TODoorFourLightBase__ct((Door_802A0994 *)arg0, parent, arg);
    ((Door_8029FD70 *)arg0)->vt18 = __vt__22TODoorFourLightSeabedU;
    ((Door_8029FD70 *)arg0)->f0 = odoor_four_light_seabed_u_class_name;
    init_collision_body_parts(arg0, labo_door_collision_body_parts, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((Door_8029FD70 *)arg0)->fD4 = get_bml_model((s32)seabed_four_light_door_bml_resource, 0);
    ((Door_8029FD70 *)arg0)->infoBC = (Info_8029FD70 *)get_bml_motion((s32)seabed_four_light_door_bml_resource, 0);
    ((Door_8029FD70 *)arg0)->fB4 = (f32)((Door_8029FD70 *)arg0)->infoBC->v4 - 1.0f;
    ((Door_8029FD70 *)arg0)->fB8 = 0.5f;
    {
        Tbl_8029FD70 tbl = door_four_light_seabed_u_table;
        for (i = 0; i < 8; i++) {
            ((Door_8029FD70 *)arg0)->fD8[i] = (s32)find_object_node((NJS_OBJECT *)(((Door_8029FD70 *)arg0)->fD4), tbl.w[i]);
        }
    }
    ((TODoorFourLightBase *)arg0)->clamp_light_index();
    return arg0;
}


TODoorFourLightSeabedU::~TODoorFourLightSeabedU() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

s32 TODoorFourLightSeabedU::vfunc_21() {
    return TODoorFourLightSeabedU__texture_list;
}

s32 TODoorFourLightSeabedU::vfunc_22() {
    return seabed_four_light_door_textures;
}

void load_labo_door_resources(void) {
    s32 r = (int)::operator new(0x440);
    if (r != 0) {
        r = load_resource_from_descriptor(r, 5, &labo_door_resource_descriptor, 0, 0, 0);
    }
    TODoorLabo__bml_resource = r;
    TODoorLabo__green_texture_list = (s32)load_gvm_texture_file("obj_o_labodoor_l_grn.GVM");
    labo_door_red_textures = (s32)load_gvm_texture_file("obj_o_labodoor_l_red.GVM");
}

const char *odoor_labo_class_name = "TODoorLabo";
const Tbl_8029FAE4 door_labo_link_table = {{1, -1, -1, -1, 4, -1, -1, -1}};

extern "C" {
void TAdSinglePlyChrSelectGC::free_all_resources() {
    if ((u32) labo_door_red_textures != 0U) {
        release_texture_list((void*)labo_door_red_textures);
        TAdSinglePlyChrSelectGC::safe_free(labo_door_red_textures);
        labo_door_red_textures = 0U;
    }
    if ((u32) TODoorLabo__green_texture_list != 0U) {
        release_texture_list((void*)TODoorLabo__green_texture_list);
        TAdSinglePlyChrSelectGC::safe_free(TODoorLabo__green_texture_list);
        TODoorLabo__green_texture_list = 0U;
    }
    if ((u32) TODoorLabo__bml_resource != 0U) {
        free_bin_model_request((void*)TODoorLabo__bml_resource, 1);
        TODoorLabo__bml_resource = 0U;
    }
}

Door_8029FAE4 *TODoorLabo__ct(Door_8029FAE4 *arg0, void *parent, s32 arg) {
    Tbl_8029FAE4 tbl;
    s32 i;

    TODoorFourLightBase__ct((Door_802A0994 *)arg0, parent, arg);
    arg0->vt = __vt__10TODoorLabo;
    arg0->f0 = odoor_labo_class_name;
    init_collision_body_parts(arg0, labo_door_collision_body_parts, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TODoorLabo *)arg0)->init_model_by_type();
    arg0->fBC = (u8 *)get_bml_motion(TODoorLabo__bml_resource, 0);
    arg0->fB4 = (f32)*(u32 *)((s8 *)arg0->fBC + 4) - 1.0f;
    arg0->fB8 = 0.5f;
    tbl = door_labo_link_table;
    for (i = 0; i < 8; i++) {
        if (tbl.v[i] != -1) {
            arg0->sw[i] = (s32)find_object_node((NJS_OBJECT *)(arg0->fD4), tbl.v[i]);
        }
    }
    arg0->fF8 = 1;
    arg0->fC4 = 50.0f;
    return arg0;
}

TODoorLabo::~TODoorLabo() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

s32 TODoorLabo::vfunc_21() {
    return labo_door_red_textures;
}

s32 TODoorLabo::vfunc_22() {
    return TODoorLabo__green_texture_list;
}

void TODoorLabo::init_model_by_type() {
    s32 tbl[2] = {0, 1};
    if (*(s32 *)&this->set_params[1] < 0) {
        this->set_params[1] = 0;
    }
    if (*(s32 *)&this->set_params[1] > 1) {
        *(s32 *)&this->set_params[1] = 1;
    }
    *(s32 *)&this->m_d4 = get_bml_model(TODoorLabo__bml_resource, tbl[*(s32 *)&this->set_params[1]]);
}

void TODoorLabo::load_resources() {
    s32 r = (int)::operator new(0x440);
    if (r != 0) {
        r = load_resource_from_descriptor(r, 5, &labo_door_resource_descriptor_2, 0, 0, 0);
    }
    (*(s32 *)&TODoorLabo__model_archive) = r;
    (*(s32 *)&TODoorLaboNormal__green_texture_list) = (s32)load_gvm_texture_file("o_labodoor_nrm_green.GVM");
    (*(s32 *)&TODoorLaboNormal__red_texture_list) = (s32)load_gvm_texture_file("o_labodoor_nrm_red.GVM");
}

void TODoorLabo::free_resources() {
    if ((u32) TODoorLaboNormal__red_texture_list != 0U) {
        release_texture_list((void*)TODoorLaboNormal__red_texture_list);
        TAdSinglePlyChrSelectGC::safe_free(TODoorLaboNormal__red_texture_list);
        TODoorLaboNormal__red_texture_list = 0U;
    }
    if ((u32) TODoorLaboNormal__green_texture_list != 0U) {
        release_texture_list((void*)TODoorLaboNormal__green_texture_list);
        TAdSinglePlyChrSelectGC::safe_free(TODoorLaboNormal__green_texture_list);
        TODoorLaboNormal__green_texture_list = 0U;
    }
    if ((u32) TODoorLabo__model_archive != 0U) {
        free_bin_model_request((void*)TODoorLabo__model_archive, 1);
        TODoorLabo__model_archive = 0U;
    }
}

const char *door_labo_normal_class_name = "TODoorLaboNormal";

Self_8029F7E0 *TODoorLaboNormal__ct(Self_8029F7E0 *self, void *parent, s32 arg) {
    s32 i;
    TODoorFourLightBase__ct((Door_802A0994 *)self, parent, arg);
    self->vt = ((s32 *)&__vt__16TODoorLaboNormal);
    self->f0 = door_labo_normal_class_name;
    init_collision_body_parts(self, labo_door_collision_body_parts, 1);
    ((TObjCollidable *)self)->refresh_collision_body_centers();
    ((TObjPlayer *)self)->register_object_by_id();
    ((TODoorLaboNormal *)self)->init_field_d4();
    self->fBC = get_bml_motion((s32)TODoorLabo__model_archive, 0);
    self->fB4 = (f32)self->fBC->f4 - 1.0f;
    self->fB8 = 0.5f;
    {
        Tbl_8029F7E0 t = {{1, -1, -1, -1, 4, -1, -1, -1}};
        for (i = 0; i < 8; i++) {
            if (t.v[i] != -1) {
                self->fD8[i] = 0;
            }
        }
    }
    self->fF8 = 1;
    self->fC4 = 50.0f;
    return self;
}

TODoorLaboNormal::~TODoorLaboNormal() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

s32 TODoorLaboNormal::vfunc_21() {
    return TODoorLaboNormal__red_texture_list;
}

s32 TODoorLaboNormal::vfunc_22() {
    return TODoorLaboNormal__green_texture_list;
}

void TODoorLaboNormal::init_field_d4() { this->m_d4 = get_bml_model(TODoorLabo__model_archive, 0); }

}
