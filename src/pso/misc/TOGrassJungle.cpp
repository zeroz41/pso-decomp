#include "types.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/misc/TOGrassJungle_8029CD90.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResource.h"
#include "pso/misc/TOGrassJungle.h"
#include "pso/misc/TMotorcycle.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjMotion.h"

extern char lbl_80465938[];
extern char lbl_80465950[];
extern char lbl_80465964[];
extern char lbl_8046597C[];
extern const char *bm_o_grass_jungle_model_names[3];
extern BmlResourceDescriptor ograss_jungle_resource_descriptor;
extern const char *bm_o_grass_jungle_motion_names[1];

struct RecoveredGlobal_8029CD0C_lbl_8046598C { char value[0x13]; };
typedef char RecoveredGlobal_8029CD0C_lbl_8046598C_size[sizeof(RecoveredGlobal_8029CD0C_lbl_8046598C) == 0x13 ? 1 : -1];

struct RecoveredGlobal_8029CD0C_lbl_804DC534 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8029CD0C_lbl_804DC534_size[sizeof(RecoveredGlobal_8029CD0C_lbl_804DC534) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8029CE64___vt__13TOGrassJungle {
    s32 value;
    u8 remaining[0x30];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8029CD0C_lbl_8046598C lbl_8046598C;
BmlResource *TOGrassJungle__bml_resource;
u32 TOGrassJungle__grass_gvm_texture;
void TLobby__sub_8001FE7C(void*, int);
s32 release_texture_list(void*);
void *__nw__7TObjectFUl(int);

extern void *tl_05;

void *TOGrassJungle__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x94);
    if (o != NULL) {
        o = TOGrassJungle__ct((TOGrassJungle *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOGrassJungle::release_static_instance() {
    if ((u32) TOGrassJungle__grass_gvm_texture != 0U) {
        release_texture_list((void*)TOGrassJungle__grass_gvm_texture);
        TAdSinglePlyChrSelectGC::safe_free(TOGrassJungle__grass_gvm_texture);
        TOGrassJungle__grass_gvm_texture = 0U;
    }
    if ((u32) TOGrassJungle__bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOGrassJungle__bml_resource, 1);
        TOGrassJungle__bml_resource = 0U;
    }
}
void TOGrassJungle::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &ograss_jungle_resource_descriptor, 0, 0, 0));
    }
    (*(u8 * *)&TOGrassJungle__bml_resource) = (unsigned char *) ((void *) var_r0);
    (*(u8 * *)&TOGrassJungle__grass_gvm_texture) = load_gvm_texture_file((s32) &lbl_8046598C.value);
    TMotorcycle::add_entry(0x3F, (int) (get_bml_model(TOGrassJungle__bml_resource, 0)), (int) ((*(u8 * *)&TOGrassJungle__grass_gvm_texture)), 12.0f, -10.0f);
}

__declspec(section ".data") const char *bm_o_grass_jungle_model_names[3] = { lbl_80465938, lbl_80465950, NULL };
BmlResourceDescriptor ograss_jungle_resource_descriptor = { lbl_80465964, bm_o_grass_jungle_model_names, bm_o_grass_jungle_motion_names, 2, 0 };
__declspec(section ".sdata") const char *bm_o_grass_jungle_motion_names[1] = { NULL };
const char *grass_jungle_class_name = lbl_8046597C;

s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern s32 __vt__13TOGrassJungle[];
struct Base_8029CD90 { char pad[0x18]; };
struct VObj_8029CD90 : Base_8029CD90 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

s32 post_translate_matrix(void *);
s32 draw_ginja_object();
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
void __dl__7TObjectFPv(void *);

void TOGrassJungle::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_8029CD90 *)arg0)->m8(400.0f, 20.0f) == 1) {
        TObjFish::set_global_param(TOGrassJungle__grass_gvm_texture);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        get_bml_model(TOGrassJungle__bml_resource, this->m_90);
        draw_ginja_object();
        pop_matrix();
    }
}

}
TOGrassJungle::~TOGrassJungle() {

}
extern "C" {

typedef char RecoveredGlobal_8029CE64___vt__13TOGrassJungle_size[sizeof(RecoveredGlobal_8029CE64___vt__13TOGrassJungle) == 0x34 ? 1 : -1];
u8 *TOGrassJungle__ct(TOGrassJungle *grass_jungle, s32 parent, s32 arg2) {
    __ct__8TObjBaseFP7TObject((void *)grass_jungle, (void *)parent);
    *(s32 **)((s8 *)grass_jungle + 0x18) = &(*(RecoveredGlobal_8029CE64___vt__13TOGrassJungle *)&__vt__13TOGrassJungle).value;
    *(s32 *)((s8 *)grass_jungle + 0) = (s32) grass_jungle_class_name;
    ((TOGrassJungle *)(grass_jungle))->apply_object_set_data((void *)arg2);
    grass_jungle->m_90 = (s32) grass_jungle->set_params[0];
    if ((s32) grass_jungle->m_90 < 0) {
        grass_jungle->m_90 = 0;
    }
    if ((s32) grass_jungle->m_90 > 1) {
        grass_jungle->m_90 = 1;
    }
    return (u8 *)grass_jungle;
}

}
