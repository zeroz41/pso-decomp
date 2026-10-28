#include "types.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TLobby_8030A6A8.h"
#include "pso/misc/TOKey_8015845C.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TOMonumentAncient02.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/misc/TOKey.h"
#include "pso/misc/TOKeyAncient01.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"

struct BmlResourceBlock_804B3960 { const char *model_filenames[2]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B3960_size[(sizeof(BmlResourceBlock_804B3960) == 0x18) ? 1 : -1];
typedef char BmlResourceBlock_804B3960_descriptor_offset[(offsetof(BmlResourceBlock_804B3960, descriptor) == 0x8) ? 1 : -1];
struct BmlResourceBlock_804B3978 { const char *model_filenames[2]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B3978_size[(sizeof(BmlResourceBlock_804B3978) == 0x18) ? 1 : -1];
typedef char BmlResourceBlock_804B3978_descriptor_offset[(offsetof(BmlResourceBlock_804B3978, descriptor) == 0x8) ? 1 : -1];
struct BmlResourceBlock_804B3990 { const char *model_filenames[2]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B3990_size[(sizeof(BmlResourceBlock_804B3990) == 0x18) ? 1 : -1];
typedef char BmlResourceBlock_804B3990_descriptor_offset[(offsetof(BmlResourceBlock_804B3990, descriptor) == 0x8) ? 1 : -1];
extern char lbl_80442330[];
extern char lbl_80442348[];
extern char lbl_80442364[];
extern char lbl_8044237C[];
extern char lbl_80442398[];
extern char lbl_804423B0[];
extern BmlResourceBlock_804B3960 monument_ancient02_resource_table;
extern BmlResourceBlock_804B3978 bm_fs_obj_o_monument02_resource_bundle;
extern BmlResourceBlock_804B3990 bm_fs_obj_o_monument03_resource_bundle;
extern const char *bm_fs_obj_o_monument01_motion_names[1];
extern const char *bm_fs_obj_o_monument02_motion_names[1];
extern const char *bm_fs_obj_o_monument03_motion_names[1];

struct RecoveredGlobal_80172EA0_lbl_804B39A8 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_80172EA0___vt__19TOMonumentAncient02 {
    s32 value;
    u8 remaining[0x38];
};

struct Node_80172AE0 { u8 pad0[4]; s32 f4; f32 x; f32 y; f32 z; u8 pad14[0x2C - 0x14]; Node_80172AE0 *child; };

struct Model_80172AE0 { u8 pad0[4]; s32 f4; u8 mtx[0x2C - 8]; Node_80172AE0 *child; };

struct VBase_80172AE0 { char pad[0x18]; };

struct VObj_80172AE0 : VBase_80172AE0 {
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

struct Mon_80172AE0 : VObj_80172AE0 {
    u8 pad1C[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    Model_80172AE0 *model;
    u8 pos38[0x60 - 0x38];
    s32 f60;
    u8 pad64[0x68 - 0x64];
    f32 f68;
    f32 f6C;
    f32 f70;
    u8 pad74[0xC0 - 0x74];
    f32 fC0;
    f32 fC4;
    s32 fC8;
    s32 fCC;
    u8 padD0[0xD8 - 0xD0];
    f32 fD8;
    u8 padDC[0xEC - 0xDC];
    s32 fEC;
};

extern "C" {
void *create_particle_emitter(void *pos, s32 id);
u32 init_collision_body_parts(void *, s32, s32);
extern RecoveredGlobal_80172EA0_lbl_804B39A8 monument_ancient02_collision_parts;
extern s32 __vt__19TOMonumentAncient02[];
extern s32 enable_v2_features;
extern s32 TOMonumentAncient02__name;
extern u32 TOMonumentAncient02__model_resource;
extern const f32 lbl_805DB92C;
extern const f32 lbl_805DB934;
extern const f32 lbl_805DB938;
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
s32 rand(void);
int rotate_matrix_y(int, int);
int push_matrix();
int post_translate_matrix(void *);
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern u8 chunk_material_color_half_alpha_f32[];
extern const f32 lbl_805DB920;
extern const f32 lbl_805DB924;
extern const f32 lbl_805DB928;
extern const f32 lbl_805DB930;
void TLobby__sub_8001FE7C(void*, int);
void free_collision_body_parts(void *);
s32 submit_cursor_candidate(void *, s32);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TOMonumentAncient02::run_task() {
    u8 *arg0 = (u8 *)this;

    switch (this->m_ac) {
    default:
        this->m_ac = 1;
        if ((u32) this->m_e8 != 0U) {
            ((TParticleCtrl *)(this->m_e8))->enable();
        }
        return;
    case 1:
        if ((TRaderMapCore::is_not_split_screen() != 1) && ((s32) this->m_ec == 1)) {
            submit_cursor_candidate(arg0, -1);
        }
        if ((u32) this->m_e8 != 0U) {
            ((TParticleCtrl *)(this->m_e8))->enable();
            return;
        }
        break;
    case 2:
        play_persistent_sound(this->m_d4, (s32)arg0, (u32)&this->position, 0, 0);
        break;
    }
}

extern void *tl_05;

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TOMonumentAncient02::render() {
    Mon_80172AE0 *self = (Mon_80172AE0 *)this;
    Model_80172AE0 *m;
    Node_80172AE0 *n;
    self->fEC = self->m8(self->fC0, self->fC4);
    if (self->fEC == 1) {
        push_matrix();
        if (self->fC8 == 1) {
            self->f68 = lbl_805DB920 * (lbl_805DB924 * (f32)rand()) - lbl_805DB928;
            self->f70 = lbl_805DB920 * (lbl_805DB924 * (f32)rand()) - lbl_805DB928;
            post_translate_matrix(&self->f68);
        }
        post_translate_matrix(self->pos38);
        rotate_matrix_y(0, self->f60);
        TObjFish::set_global_param(self->f24);
        m = self->model;
        post_translate_matrix(m->mtx);
        draw_ginja_model(m->f4);
        if (self->fC8 == 1) {
            if (self->fCC != 0) {
                self->fD8 += lbl_805DB928;
                if (lbl_805DB92C <= self->fD8) {
                    self->fD8 = lbl_805DB92C;
                    self->fCC = 0;
                }
            } else {
                self->fD8 -= lbl_805DB928;
                if (self->fD8 <= lbl_805DB930) {
                    self->fD8 = lbl_805DB930;
                    self->fCC = 1;
                }
            }
            n = m->child;
            push_matrix();
            translate_matrix(0, n->x, n->y, n->z);
            TParticleCtrl::begin_effect_render();
            saved_model_render_flags = model_render_flags;
            model_render_flags = model_render_flags | 0x20;
            set_constant_material((const NJS_ARGB *)((&self->fD8)));
            draw_ginja_model(n->f4);
            set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
            model_render_flags = saved_model_render_flags;
            TParticleCtrl::end_effect_render();
            pop_matrix();
        }
        pop_matrix();
    }
}
#pragma pop

void *TOMonumentAncient02::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xF0);
    if (o != NULL) {
        o = TOMonumentAncient02__ct((TOMonumentAncient02 *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOMonumentAncient02::free_shared_data() {
    if ((u32) TOMonumentAncient02__model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOMonumentAncient02__model_resource, 1);
        TOMonumentAncient02__model_resource = 0U;
    }
}

void TOMonumentAncient02::load_resources() {
    u8 *tbl = (u8 *)&monument_ancient02_resource_table;
    u8 *p;
    switch (get_current_floor_area()) {
    default:
        p = (u8 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, tbl + 0x8, 0, 0, 0);
        }
        TOMonumentAncient02__model_resource = (u32)p;
        break;
    case AREA_CAVE2:
        p = (u8 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, tbl + 0x20, 0, 0, 0);
        }
        TOMonumentAncient02__model_resource = (u32)p;
        break;
    case AREA_MINE2:
        p = (u8 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, tbl + 0x38, 0, 0, 0);
        }
        TOMonumentAncient02__model_resource = (u32)p;
        break;
    }
}

void *__dt__19TOMonumentAncient02Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TOMonumentAncient02;
        TBoss4Type2::request_destroy((u32)(*(void **)((s8 *)arg0 + 0xE8)));
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804AFBF8 *)arg0)->destroy_key_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80172EA0_lbl_804B39A8_size[sizeof(RecoveredGlobal_80172EA0_lbl_804B39A8) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_80172EA0___vt__19TOMonumentAncient02_size[sizeof(RecoveredGlobal_80172EA0___vt__19TOMonumentAncient02) == 0x3C ? 1 : -1];
u8 *TOMonumentAncient02__ct(TOMonumentAncient02 *arg0, s32 arg1, s32 arg2) {
    s32 area;
    init_map_object_base(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80172EA0___vt__19TOMonumentAncient02 *)&__vt__19TOMonumentAncient02).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TOMonumentAncient02__name;
    ((TOMonumentAncient02 *)(arg0))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOMonumentAncient02__model_resource) + 0x42C)) + 8);
    arg0->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOMonumentAncient02__model_resource) + 0x42C)) + 0xC);
    init_collision_body_parts(arg0, (s32) &monument_ancient02_collision_parts.value, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    area = get_current_floor_area();
    switch (area) {
    default:
        arg0->m_d0 = 0x2C;
        arg0->m_d4 = 0x4C119;
        break;
    case AREA_CAVE2:
        arg0->m_d0 = 0x2D;
        arg0->m_d4 = 0x44116;
        break;
    case AREA_MINE2:
        arg0->m_d0 = 0x2E;
        arg0->m_d4 = 0x4004C10F;
        break;
    }
    arg0->m_ac = 0;
    arg0->m_c8 = 0;
    arg0->m_cc = 0;
    ((TOMonumentAncient02 *)arg0)->cursor_action.set_use();
    arg0->m_c0 = (f32) lbl_805DB934;
    *(f32 *)((s8 *)arg0 + 0xC4) = (f32) lbl_805DB938;
    *(f32 *)((s8 *)arg0 + 0xD8) = (f32) lbl_805DB92C;
    *(f32 *)((s8 *)arg0 + 0xDC) = (f32) lbl_805DB92C;
    arg0->m_e0 = (f32) lbl_805DB92C;
    *(f32 *)((s8 *)arg0 + 0xE4) = (f32) lbl_805DB92C;
    arg0->m_e8 = (s32)create_particle_emitter(((u8 *)arg0 + 0x38), 0x7F);
    arg0->m_ec = 1;
    if ((s32) enable_v2_features == 1) {
        if (get_game_play_mode() == 1) {
            queue_destruction__7TObjectFv((arg0));
        }
    }
    return (u8 *)arg0;
}

__declspec(section ".data") BmlResourceBlock_804B3960 monument_ancient02_resource_table = { { lbl_80442330, NULL }, { lbl_80442348, monument_ancient02_resource_table.model_filenames, bm_fs_obj_o_monument01_motion_names, 1, 0 } };
__declspec(section ".data") BmlResourceBlock_804B3978 bm_fs_obj_o_monument02_resource_bundle = { { lbl_80442364, NULL }, { lbl_8044237C, bm_fs_obj_o_monument02_resource_bundle.model_filenames, bm_fs_obj_o_monument02_motion_names, 1, 0 } };
__declspec(section ".data") BmlResourceBlock_804B3990 bm_fs_obj_o_monument03_resource_bundle = { { lbl_80442398, NULL }, { lbl_804423B0, bm_fs_obj_o_monument03_resource_bundle.model_filenames, bm_fs_obj_o_monument03_motion_names, 1, 0 } };
__declspec(section ".sdata") const char *bm_fs_obj_o_monument01_motion_names[1] = { NULL };
__declspec(section ".sdata") const char *bm_fs_obj_o_monument02_motion_names[1] = { NULL };
__declspec(section ".sdata") const char *bm_fs_obj_o_monument03_motion_names[1] = { NULL };
}
