#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_8016CF5C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TOKeyGenericSw.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TContainerAncient01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TOKey.h"
#include "pso/map/FloorArea.h"

struct BmlResourceBlock_804B2CC0 { const char *model_filenames[2]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B2CC0_size[(sizeof(BmlResourceBlock_804B2CC0) == 0x18) ? 1 : -1];
typedef char BmlResourceBlock_804B2CC0_descriptor_offset[(offsetof(BmlResourceBlock_804B2CC0, descriptor) == 0x8) ? 1 : -1];
struct BmlResourceBlock_804B2CE0 { const char *motion_filenames[2]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B2CE0_size[(sizeof(BmlResourceBlock_804B2CE0) == 0x18) ? 1 : -1];
typedef char BmlResourceBlock_804B2CE0_descriptor_offset[(offsetof(BmlResourceBlock_804B2CE0, descriptor) == 0x8) ? 1 : -1];
struct BmlResourceBlock_804B2CF8 { const char *model_filenames[2]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B2CF8_size[(sizeof(BmlResourceBlock_804B2CF8) == 0x18) ? 1 : -1];
typedef char BmlResourceBlock_804B2CF8_descriptor_offset[(offsetof(BmlResourceBlock_804B2CF8, descriptor) == 0x8) ? 1 : -1];
struct BmlResourceBlock_804B2D18 { const char *motion_filenames[2]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B2D18_size[(sizeof(BmlResourceBlock_804B2D18) == 0x18) ? 1 : -1];
typedef char BmlResourceBlock_804B2D18_descriptor_offset[(offsetof(BmlResourceBlock_804B2D18, descriptor) == 0x8) ? 1 : -1];
extern char lbl_80441C30[];
extern char lbl_80441C4C[];
extern char lbl_80441C68[];
extern char lbl_80441C84[];
extern char lbl_80441CA0[];
extern char lbl_80441CBC[];
extern char lbl_80441CD8[];
extern BmlResourceBlock_804B2CC0 fs_obj_hanyousu_body1_resource_bundle;
extern const char *fs_obj_hanyousu_light_model_names[2];
extern BmlResourceBlock_804B2CE0 fs_obj_hanyousu_light_resource_bundle;
extern BmlResourceBlock_804B2CF8 fs_obj_hanyousu_body1_j_resource_bundle;
extern const char *fs_obj_hanyousu_light_j_model_names[2];
extern BmlResourceBlock_804B2D18 fs_obj_hanyousu_light_j_resource_bundle;
extern const char *fs_obj_hanyousu_body1_motion_names[1];
extern const char *fs_obj_hanyousu_body1_j_motion_names[1];

struct Base_8016CA64 { char pad[0x18]; };

struct Obj_8016CA64 : Base_8016CA64 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
    u8 pad1c[0x8];
    s32 x24;
    u8 pad28[0xC];
    s32 x34;
    u8 x38[0x28];
    s32 x60;
    u8 pad64[0x4C];
    f32 xb0;
    u8 padb4[0x8];
    s32 xbc;
    f32 xc0;
    f32 xc4;
    u8 padc8[0xC];
    s32 xd4;
};

struct Area_8016CA64 { u8 pad[8]; s32 x8; };

struct Map_8016CA64 { u8 pad[0x42C]; Area_8016CA64 *area; };

extern "C" {
s32 push_matrix();
s32 post_translate_matrix(void *);
s32 rotate_matrix_y(s32, s32);
s32 draw_ginja_model_with_motion(s32, s32, f32);
extern s32 *TOKeyGenericSw__texture_lists;
extern Map_8016CA64 *TOKeyGenericSw__shared_resource_ptrs[];
void TLobby__sub_8001FE7C(void *, s32);
void mem_free(void *);
void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void *mem_alloc(u32);
u8 *load_gvm_texture_file(s32 arg0);
extern char lbl_80441D04[];
extern char lbl_80441D24[];
void *__dt__14TOKeyGenericSwFv(void *arg0, s16 arg1);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
void *__dt__5TOKeyFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);
s32 update_anim_phase__13TObjMapObjectFv();
s32 init_collision_body_parts(void *, void *, s32);
void *__ct__5TOKeyFP7TObject(void *, void *);
extern s32 key_generic_sw_collision_body[];
extern s32 TOKeyGenericSw__name;

void TOKeyGenericSw::vfunc_25() {  }

void TOKeyGenericSw::render() {
    Obj_8016CA64 *self = (Obj_8016CA64 *)this;
    if (self->m8(self->xc0, self->xc4) == 0) return;
    push_matrix();
    self->x24 = TOKeyGenericSw__texture_lists[0];
    self->x34 = TOKeyGenericSw__shared_resource_ptrs[0]->area->x8;
    post_translate_matrix(self->x38);
    rotate_matrix_y(0, self->x60);
    TObjFish::set_global_param(self->x24);
    draw_ginja_object((void *)self->x34);
    pop_matrix();
    TParticleCtrl::begin_effect_render();
    push_matrix();
    switch (self->xd4) {
    case 0:
        self->x24 = TOKeyGenericSw__texture_lists[1];
        break;
    case 1:
        self->x24 = TOKeyGenericSw__texture_lists[2];
        break;
    }
    self->x34 = TOKeyGenericSw__shared_resource_ptrs[1]->area->x8;
    post_translate_matrix(self->x38);
    rotate_matrix_y(0, self->x60);
    TObjFish::set_global_param(self->x24);
    draw_ginja_model_with_motion(self->x34, self->xbc, self->xb0);
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

void TOKeyGenericSw::update_switch_off() {
    update_anim_phase__13TObjMapObjectFv();
    this->submit_cursor_target();
    this->m_f4 = 1;
    this->m_ec = 0;
    *(s32 *)((s8 *)this + 0xF0) = 0;
    *(s32 *)&this->unk_F8 = (s32) this->m_f4;
}

void TOKeyGenericSw::update_switch_on() {
    update_anim_phase__13TObjMapObjectFv();
    this->submit_cursor_target();
    this->m_ec = 1;
    this->m_f4 = 0;
    *(s32 *)&this->unk_F8 = 0;
    *(s32 *)((s8 *)this + 0xF0) = (s32) this->m_ec;
}

extern void *tl_05;

void *TOKeyGenericSw::create(void *source) {
    void *o = __nw__7TObjectFUl(0xFC);
    if (o != NULL) {
        o = TOKeyGenericSw__ct((TOKeyGenericSw *)o, tl_05, source);
    }
    return o;
}

extern s32 __vt__14TOKeyGenericSw[];

void TOKeyGenericSw::free_shared_resources() {
    if (TOKeyGenericSw__texture_lists != NULL) {
        TObjPlayer::free_if_valid(TOKeyGenericSw__texture_lists[2]);
        if (TOKeyGenericSw__texture_lists != NULL) {
            mem_free(TOKeyGenericSw__texture_lists);
            TOKeyGenericSw__texture_lists = NULL;
        }
    }
    if (TOKeyGenericSw__shared_resource_ptrs[1] != NULL) {
        TLobby__sub_8001FE7C(TOKeyGenericSw__shared_resource_ptrs[1], 1);
        TOKeyGenericSw__shared_resource_ptrs[1] = NULL;
    }
    if (TOKeyGenericSw__shared_resource_ptrs[0] != NULL) {
        TLobby__sub_8001FE7C(TOKeyGenericSw__shared_resource_ptrs[0], 1);
        TOKeyGenericSw__shared_resource_ptrs[0] = NULL;
    }
}

void TOKeyGenericSw::load_resources() {
    u8 *base = (u8 *)&fs_obj_hanyousu_body1_resource_bundle;
    s32 st = get_current_floor_area();
    void *p;
    if (TContainerAncient01::is_global_state_in_table() == 1 || st == AREA_SEABED_UPPER || st == AREA_SEABED_LOWER) {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, base + 0x40, 0, 0, 0);
        }
        TOKeyGenericSw__shared_resource_ptrs[0] = (Map_8016CA64 *)p;
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, base + 0x60, 0, 0, 0);
        }
        TOKeyGenericSw__shared_resource_ptrs[1] = (Map_8016CA64 *)p;
        TOKeyGenericSw__texture_lists = (s32 *)mem_alloc(0xC);
        TOKeyGenericSw__texture_lists[0] = *(s32 *)((s8 *)TOKeyGenericSw__shared_resource_ptrs[0]->area + 0xC);
        TOKeyGenericSw__texture_lists[1] = *(s32 *)((s8 *)TOKeyGenericSw__shared_resource_ptrs[1]->area + 0xC);
        TOKeyGenericSw__texture_lists[2] = (s32)load_gvm_texture_file((s32)lbl_80441D04);
    } else {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, base + 0x8, 0, 0, 0);
        }
        TOKeyGenericSw__shared_resource_ptrs[0] = (Map_8016CA64 *)p;
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, base + 0x28, 0, 0, 0);
        }
        TOKeyGenericSw__shared_resource_ptrs[1] = (Map_8016CA64 *)p;
        TOKeyGenericSw__texture_lists = (s32 *)mem_alloc(0xC);
        TOKeyGenericSw__texture_lists[0] = *(s32 *)((s8 *)TOKeyGenericSw__shared_resource_ptrs[0]->area + 0xC);
        TOKeyGenericSw__texture_lists[1] = *(s32 *)((s8 *)TOKeyGenericSw__shared_resource_ptrs[1]->area + 0xC);
        TOKeyGenericSw__texture_lists[2] = (s32)load_gvm_texture_file((s32)lbl_80441D24);
    }
}

void *__dt__14TOKeyGenericSwFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TOKeyGenericSw;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__5TOKeyFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *TOKeyGenericSw__ct(TOKeyGenericSw *key_generic_sw, void *parent, void *source) {
    __ct__5TOKeyFP7TObject(key_generic_sw, parent);
    *(void **)((s8 *)key_generic_sw + 0x18) = __vt__14TOKeyGenericSw;
    *(s32 *)((s8 *)key_generic_sw + 0) = TOKeyGenericSw__name;
    key_generic_sw->apply_object_set_data(source);
    ((TOKey *)key_generic_sw)->init_switch_id();
    *(s32 *)((s8 *)key_generic_sw + 0x34) = *(s32 *)((s8 *)(*(void **)((s8 *)TOKeyGenericSw__shared_resource_ptrs[1] + 0x42C)) + 8);
    *(void **)((s8 *)key_generic_sw + 0xBC) = *(void **)((s8 *)(*(void **)((s8 *)TOKeyGenericSw__shared_resource_ptrs[1] + 0x430)) + 4);
    *(f32 *)((s8 *)key_generic_sw + 0xB4) = (f32) *(u32 *)((s8 *)(*(void **)((s8 *)key_generic_sw + 0xBC)) + 4) - 1.0f;
    key_generic_sw->m_b8 = 2.0f;
    *(u32 *)&key_generic_sw->texlist = TOKeyGenericSw__texture_lists[1];
    init_collision_body_parts(key_generic_sw, key_generic_sw_collision_body, 1);
    ((TObjCollidable *)key_generic_sw)->refresh_collision_body_centers();
    ((TObjPlayer *)key_generic_sw)->register_object_by_id();
    key_generic_sw->m_c0 = 4e+02f;
    *(f32 *)((s8 *)key_generic_sw + 0xC4) = 4e+01f;
    if ((*(s32 *)&key_generic_sw->mode != 2) && (key_generic_sw->scale.x < 0.0f)) {
        *(s32 *)&key_generic_sw->mode = 1;
    } else {
        *(s32 *)&key_generic_sw->mode = 0;
    }
    key_generic_sw->m_e8 = get_current_floor_area();
    key_generic_sw->m_ec = 0;
    *(s32 *)((s8 *)key_generic_sw + 0xF0) = 0;
    key_generic_sw->m_f4 = 0;
    *(s32 *)((s8 *)key_generic_sw + 0xF8) = 0;
    return key_generic_sw;
}

__declspec(section ".data") BmlResourceBlock_804B2CC0 fs_obj_hanyousu_body1_resource_bundle = { { lbl_80441C30, NULL }, { lbl_80441C4C, fs_obj_hanyousu_body1_resource_bundle.model_filenames, fs_obj_hanyousu_body1_motion_names, 1, 0 } };
__declspec(section ".data") const char *fs_obj_hanyousu_light_model_names[2] = { lbl_80441C68, NULL };
__declspec(section ".data") BmlResourceBlock_804B2CE0 fs_obj_hanyousu_light_resource_bundle = { { lbl_80441C84, NULL }, { lbl_80441CA0, fs_obj_hanyousu_light_model_names, fs_obj_hanyousu_light_resource_bundle.motion_filenames, 1, 1 } };
__declspec(section ".data") BmlResourceBlock_804B2CF8 fs_obj_hanyousu_body1_j_resource_bundle = { { lbl_80441C30, NULL }, { lbl_80441CBC, fs_obj_hanyousu_body1_j_resource_bundle.model_filenames, fs_obj_hanyousu_body1_j_motion_names, 1, 0 } };
__declspec(section ".data") const char *fs_obj_hanyousu_light_j_model_names[2] = { lbl_80441C68, NULL };
__declspec(section ".data") BmlResourceBlock_804B2D18 fs_obj_hanyousu_light_j_resource_bundle = { { lbl_80441C84, NULL }, { lbl_80441CD8, fs_obj_hanyousu_light_j_model_names, fs_obj_hanyousu_light_j_resource_bundle.motion_filenames, 1, 1 } };
__declspec(section ".sdata") const char *fs_obj_hanyousu_body1_motion_names[1] = { NULL };
__declspec(section ".sdata") const char *fs_obj_hanyousu_body1_j_motion_names[1] = { NULL };
}
