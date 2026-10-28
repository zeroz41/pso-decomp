#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TODoorFourLightBase.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjSeabedSuisoBrakable.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/misc/TODoorLabo.h"
#include "pso/misc/TODoorLaboNormal.h"
#include "pso/system/BmlResourceDescriptor.h"

extern "C" {
extern char lbl_80465EAC[];
extern char lbl_80465EC0[];
extern char lbl_80465ED8[];
extern char lbl_80465EF0[];
extern char lbl_80465F08[];
extern char lbl_80465F1C[];
extern char lbl_80465F30[];
__declspec(section ".data") const char *bm_obj_door_labo_model_names[3] = { lbl_80465EAC, lbl_80465EC0, NULL };
__declspec(section ".data") const char *bm_obj_door_labo_motion_names[2] = { lbl_80465ED8, NULL };
BmlResourceDescriptor labo_door_resource_descriptor = { lbl_80465EF0, bm_obj_door_labo_model_names, bm_obj_door_labo_motion_names, 2, 1 };
__declspec(section ".data") const char *bm_obj_labodoor_nrm_model_names[2] = { lbl_80465F08, NULL };
__declspec(section ".data") const char *bm_obj_labodoor_nrm_motion_names[2] = { lbl_80465F1C, NULL };
BmlResourceDescriptor labo_door_resource_descriptor_2 = { lbl_80465F30, bm_obj_labodoor_nrm_model_names, bm_obj_labodoor_nrm_motion_names, 1, 1 };
}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Tbl_8029F7E0 { s32 v[8]; };

struct Res_8029F7E0 { u32 f0; u32 f4; };

struct Self_8029F7E0 {
    s32 f0;
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
    s32 f0;
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

extern "C" {
Res_8029F7E0 *get_bml_motion(s32, s32);
void init_collision_body_parts(void *, void *, s32);
void TODoorFourLightBase__ct(void *);
extern Tbl_8029F7E0 lbl_80466014;
extern Tbl_8029FAE4 door_labo_link_table;
extern u8 labo_door_collision_body_parts[];
extern s32 __vt__16TODoorLaboNormal[];
extern s32 __vt__10TODoorLabo[];
extern s32 door_labo_normal_class_name;
extern s32 odoor_labo_class_name;
extern const f32 lbl_805DDDB8;
extern const f32 lbl_805DDDBC;
extern const f32 lbl_805DDDC0;
Self_8029F7E0 *TODoorLaboNormal__ct(Self_8029F7E0 *self);
s32 load_resource_from_descriptor(s32, int, void *, int, int, int);
u8 *load_gvm_texture_file(s32 arg0);
extern u8 lbl_80466040[];
extern u8 lbl_8046605C[];

extern u32 TODoorLabo__model_archive;
extern u32 TODoorLaboNormal__green_texture_list;
extern u32 TODoorLaboNormal__red_texture_list;
s32 get_bml_model(s32, s32);
extern s32 lbl_80465FF8[];
extern s32 TODoorLabo__bml_resource;
Door_8029FAE4 *TODoorLabo__ct(Door_8029FAE4 *arg0);
void TLobby__sub_8001FE7C(void*, int);
s32 release_texture_list(void*);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
void *__dt__19TODoorFourLightBaseFv(void *arg0, s16 arg1);

void TODoorLaboNormal::init_field_d4() { this->m_d4 = get_bml_model(TODoorLabo__model_archive, 0); }

s32 TODoorLaboNormal__vt20(void) {
    return TODoorLaboNormal__green_texture_list;
}

s32 TODoorLaboNormal__vt19(void) {
    return TODoorLaboNormal__red_texture_list;
}

void *__dt__16TODoorLaboNormalFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TODoorLaboNormal;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__19TODoorFourLightBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
Self_8029F7E0 *TODoorLaboNormal__ct(Self_8029F7E0 *self) {
    s32 i;
    TODoorFourLightBase__ct(self);
    self->vt = ((s32 *)&__vt__16TODoorLaboNormal);
    self->f0 = door_labo_normal_class_name;
    init_collision_body_parts(self, labo_door_collision_body_parts, 1);
    ((TUnk_804AF8A0 *)self)->refresh_collision_body_centers();
    ((TObjPlayer *)self)->reset_photon_effect();
    ((TODoorLaboNormal *)self)->init_field_d4();
    self->fBC = get_bml_motion((s32)TODoorLabo__model_archive, 0);
    self->fB4 = (f32)self->fBC->f4 - lbl_805DDDB8;
    self->fB8 = lbl_805DDDBC;
    {
        Tbl_8029F7E0 t = lbl_80466014;
        for (i = 0; i < 8; i++) {
            if (t.v[i] != -1) {
                self->fD8[i] = 0;
            }
        }
    }
    self->fF8 = 1;
    self->fC4 = lbl_805DDDC0;
    return self;
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
        TLobby__sub_8001FE7C((void*)TODoorLabo__model_archive, 1);
        TODoorLabo__model_archive = 0U;
    }
}

extern s32 TODoorLabo__green_texture_list;

void TODoorLabo::load_resources() {
    s32 r = (int)::operator new(0x440);
    if (r != 0) {
        r = load_resource_from_descriptor(r, 5, &labo_door_resource_descriptor_2, 0, 0, 0);
    }
    (*(s32 *)&TODoorLabo__model_archive) = r;
    (*(s32 *)&TODoorLaboNormal__green_texture_list) = (s32)load_gvm_texture_file((s32)lbl_80466040);
    (*(s32 *)&TODoorLaboNormal__red_texture_list) = (s32)load_gvm_texture_file((s32)lbl_8046605C);
}

void TODoorLabo::init_model_by_type() {
    s32 tbl[2];
    tbl[0] = lbl_80465FF8[0];
    tbl[1] = lbl_80465FF8[1];
    if (*(s32 *)&this->m_88 < 0) {
        this->m_88 = 0;
    }
    if (*(s32 *)&this->m_88 > 1) {
        *(s32 *)&this->m_88 = 1;
    }
    *(s32 *)&this->m_d4 = get_bml_model(TODoorLabo__bml_resource, tbl[*(s32 *)&this->m_88]);
}

s32 TODoorLabo__vt20(void) {
    return TODoorLabo__green_texture_list;
}

extern s32 labo_door_red_textures;

s32 TODoorLabo__vt19(void) {
    return labo_door_red_textures;
}

void *__dt__10TODoorLaboFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__10TODoorLabo;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__19TODoorFourLightBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

Door_8029FAE4 *TODoorLabo__ct(Door_8029FAE4 *arg0) {
    Tbl_8029FAE4 tbl;
    s32 i;

    TODoorFourLightBase__ct(arg0);
    arg0->vt = __vt__10TODoorLabo;
    arg0->f0 = odoor_labo_class_name;
    init_collision_body_parts(arg0, labo_door_collision_body_parts, 1);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->reset_photon_effect();
    ((TODoorLabo *)arg0)->init_model_by_type();
    arg0->fBC = (u8 *)get_bml_motion(TODoorLabo__bml_resource, 0);
    arg0->fB4 = (f32)*(u32 *)((s8 *)arg0->fBC + 4) - lbl_805DDDB8;
    arg0->fB8 = lbl_805DDDBC;
    tbl = door_labo_link_table;
    for (i = 0; i < 8; i++) {
        if (tbl.v[i] != -1) {
            arg0->sw[i] = (s32)find_object_node((NJS_OBJECT *)(arg0->fD4), tbl.v[i]);
        }
    }
    arg0->fF8 = 1;
    arg0->fC4 = lbl_805DDDC0;
    return arg0;
}

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
        TLobby__sub_8001FE7C((void*)TODoorLabo__bml_resource, 1);
        TODoorLabo__bml_resource = 0U;
    }
}
}

extern u8 lbl_80466074[];
extern u8 lbl_80466090[];

void load_labo_door_resources(void) {
    s32 r = (int)::operator new(0x440);
    if (r != 0) {
        r = load_resource_from_descriptor(r, 5, &labo_door_resource_descriptor, 0, 0, 0);
    }
    TODoorLabo__bml_resource = r;
    TODoorLabo__green_texture_list = (s32)load_gvm_texture_file((s32)lbl_80466074);
    labo_door_red_textures = (s32)load_gvm_texture_file((s32)lbl_80466090);
}

extern s32 seabed_four_light_door_textures;

s32 TODoorFourLightSeabedU__vt20(void) {
    return seabed_four_light_door_textures;
}

extern s32 TODoorFourLightSeabedU__texture_list;

s32 TODoorFourLightSeabedU__vt19(void) {
    return TODoorFourLightSeabedU__texture_list;
}

extern s32 __vt__22TODoorFourLightSeabedU[];

void *__dt__22TODoorFourLightSeabedUFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__22TODoorFourLightSeabedU;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__19TODoorFourLightBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Tbl_8029FD70 { s32 w[8]; };
struct Info_8029FD70 { u8 pad[4]; u32 v4; };
struct Door_8029FD70 {
    s32 f0;
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

extern Tbl_8029FD70 door_four_light_seabed_u_table;
extern s32 odoor_four_light_seabed_u_class_name;
extern u32 seabed_four_light_door_bml_resource;

#define self ((Door_8029FD70 *)arg0)
u8 *TODoorFourLightSeabedU__ct(u8 *arg0) {
    s32 i;
    TODoorFourLightBase__ct(arg0);
    self->vt18 = __vt__22TODoorFourLightSeabedU;
    self->f0 = odoor_four_light_seabed_u_class_name;
    init_collision_body_parts(arg0, labo_door_collision_body_parts, 1);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->reset_photon_effect();
    self->fD4 = get_bml_model((s32)seabed_four_light_door_bml_resource, 0);
    self->infoBC = (Info_8029FD70 *)get_bml_motion((s32)seabed_four_light_door_bml_resource, 0);
    self->fB4 = (f32)self->infoBC->v4 - lbl_805DDDB8;
    self->fB8 = lbl_805DDDBC;
    {
        Tbl_8029FD70 tbl = door_four_light_seabed_u_table;
        for (i = 0; i < 8; i++) {
            self->fD8[i] = (s32)find_object_node((NJS_OBJECT *)(self->fD4), tbl.w[i]);
        }
    }
    ((TODoorFourLightBase *)arg0)->clamp_light_index();
    return arg0;
}
#undef self

#pragma pop

extern s32 lbl_804660AC[];
extern s32 lbl_804660C8[];
extern s32 lbl_804660DC[];
extern s32 lbl_804660FC[];
extern s32 bm_o_door_seabed01_u_resource_descriptor[];
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
        TLobby__sub_8001FE7C((void*)seabed_four_light_door_bml_resource, 1);
        seabed_four_light_door_bml_resource = 0U;
    }
}
void TLanguage__sub_8029FF0C(void) {
    s32 global_state;
    s32 var_r0;
    s32 var_r0_2;
    global_state = TOKeyMachine01::get_global_state();
    switch (global_state) {
    case 28:
        var_r0 = (int)::operator new(0x440);
        if (var_r0 != 0) {
            var_r0 = load_resource_from_descriptor(var_r0, 5, bm_o_door_seabed01_u_resource_descriptor, 0, 0, 0);
        }
        seabed_four_light_door_bml_resource = var_r0;
        seabed_four_light_door_textures = (s32)load_gvm_texture_file((s32)lbl_804660AC);
        TODoorFourLightSeabedU__texture_list = (s32)load_gvm_texture_file((s32)lbl_804660C8);
        return;
    case 29:
        var_r0_2 = (int)::operator new(0x440);
        if (var_r0_2 != 0) {
            var_r0_2 = load_resource_from_descriptor(var_r0_2, 5, bm_o_door_seabed01_u_resource_descriptor, 0, 0, 0);
        }
        seabed_four_light_door_bml_resource = var_r0_2;
        seabed_four_light_door_textures = (s32)load_gvm_texture_file((s32)lbl_804660DC);
        TODoorFourLightSeabedU__texture_list = (s32)load_gvm_texture_file((s32)lbl_804660FC);
        return;
    }
}

extern s32 lbl_805D6604;

s32 TODoorFourLightSeabed__vt20(void) {
    return lbl_805D6604;
}

extern s32 lbl_805D6608;

s32 TODoorFourLightSeabed__vt19(void) {
    return lbl_805D6608;
}

extern s32 __vt__21TODoorFourLightSeabed[];

void *__dt__21TODoorFourLightSeabedFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__21TODoorFourLightSeabed;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__19TODoorFourLightBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Tbl_802A0068 { s32 w[8]; };
struct Info_802A0068 { u8 pad[4]; u32 v4; };
struct Door_802A0068 {
    s32 f0;
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

extern Tbl_802A0068 door_four_light_seabed_index_table;
extern s32 TODoorFourLightSeabed__class_name;
extern s32 door_labo_bml_resource;

#define self ((Door_802A0068 *)arg0)
u8 *TODoorFourLightSeabed__ct(u8 *arg0) {
    s32 i;
    TODoorFourLightBase__ct(arg0);
    self->vt18 = __vt__21TODoorFourLightSeabed;
    self->f0 = TODoorFourLightSeabed__class_name;
    init_collision_body_parts(arg0, labo_door_collision_body_parts, 1);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->reset_photon_effect();
    self->fD4 = get_bml_model(door_labo_bml_resource, 0);
    self->infoBC = (Info_802A0068 *)get_bml_motion(door_labo_bml_resource, 0);
    self->fB4 = (f32)self->infoBC->v4 - lbl_805DDDB8;
    self->fB8 = lbl_805DDDBC;
    {
        Tbl_802A0068 tbl = door_four_light_seabed_index_table;
        for (i = 0; i < 8; i++) {
            self->fD8[i] = (s32)find_object_node((NJS_OBJECT *)(self->fD4), tbl.w[i]);
        }
    }
    ((TODoorFourLightBase *)arg0)->clamp_light_index();
    return arg0;
}
#undef self
#pragma pop
