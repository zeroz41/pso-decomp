#include "types.h"
#include "pso/misc/TORockCave.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TOSensor.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TORockCave.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/object/TObjChip.h"
#include <dolphin/mtx.h>

struct BmlResourceBlock_804B3AB8 { const char *model_filenames[4]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B3AB8_size[(sizeof(BmlResourceBlock_804B3AB8) == 0x20) ? 1 : -1];
typedef char BmlResourceBlock_804B3AB8_descriptor_offset[(offsetof(BmlResourceBlock_804B3AB8, descriptor) == 0x10) ? 1 : -1];
struct BmlResourceBlock_804B3AD8 { const char *model_filenames[7]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B3AD8_size[(sizeof(BmlResourceBlock_804B3AD8) == 0x2c) ? 1 : -1];
typedef char BmlResourceBlock_804B3AD8_descriptor_offset[(offsetof(BmlResourceBlock_804B3AD8, descriptor) == 0x1c) ? 1 : -1];
struct BmlResourceBlock_804B3B04 { const char *model_filenames[4]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B3B04_size[(sizeof(BmlResourceBlock_804B3B04) == 0x20) ? 1 : -1];
typedef char BmlResourceBlock_804B3B04_descriptor_offset[(offsetof(BmlResourceBlock_804B3B04, descriptor) == 0x10) ? 1 : -1];
struct BmlResourceBlock_804B3B24 { const char *model_filenames[7]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B3B24_size[(sizeof(BmlResourceBlock_804B3B24) == 0x2c) ? 1 : -1];
typedef char BmlResourceBlock_804B3B24_descriptor_offset[(offsetof(BmlResourceBlock_804B3B24, descriptor) == 0x1c) ? 1 : -1];
struct BmlResourceBlock_804B3B50 { const char *model_filenames[7]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B3B50_size[(sizeof(BmlResourceBlock_804B3B50) == 0x2c) ? 1 : -1];
typedef char BmlResourceBlock_804B3B50_descriptor_offset[(offsetof(BmlResourceBlock_804B3B50, descriptor) == 0x1c) ? 1 : -1];
struct BmlResourceBlock_804B3B7C { const char *model_filenames[7]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B3B7C_size[(sizeof(BmlResourceBlock_804B3B7C) == 0x2c) ? 1 : -1];
typedef char BmlResourceBlock_804B3B7C_descriptor_offset[(offsetof(BmlResourceBlock_804B3B7C, descriptor) == 0x1c) ? 1 : -1];
extern BmlResourceBlock_804B3AB8 rock_cave_resource_table;
extern BmlResourceBlock_804B3AD8 bm_o_rock_cave02_resource_bundle;
extern BmlResourceBlock_804B3B04 bm_o_rock_cave03_resource_bundle;
extern BmlResourceBlock_804B3B24 bm_fe_obj_rb_liwa_resource_bundle;
extern BmlResourceBlock_804B3B50 bm_fe_obj_rb2_liwa_resource_bundle;
extern BmlResourceBlock_804B3B7C bm_fe_obj_rb3_liwa_resource_bundle;
extern const char *bm_o_rock_cave01_motion_names[1];
extern const char *bm_o_rock_cave02_motion_names[1];
extern const char *bm_o_rock_cave03_motion_names[1];
extern const char *bm_fe_obj_rb_liwa_motion_names[1];
extern const char *bm_fe_obj_rb2_liwa_motion_names[1];
extern const char *bm_fe_obj_rb3_liwa_motion_names[1];

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
    virtual s32 m8(f32, f32);
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual s32 m12();
    virtual s32 m13();
};

extern "C" {
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
u32 load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern u32 cave_rock_resource_bundle;
extern u32 rock_cave_model_resource;
void *__dt__10TORockCaveFv(void *arg0, s16 arg1);
void TLobby__sub_8001FE7C(void*, int);
void __ct__14TObjCollidableFP7TObject(void *, void *);
void __dl__7TObjectFPv(void *);

void TORockCave::draw_model() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_18 *)(arg0))->m8(*(f32 *)&this->unk_AC, this->m_b0) != 0) {
        this->vfunc_14();
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        draw_ginja_object(this->model);
        pop_matrix();
        this->vfunc_15();
    }
}

void TORockCave::free_instances() {
    if ((u32) rock_cave_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)rock_cave_model_resource, 1);
        rock_cave_model_resource = 0U;
    }
    if ((u32) cave_rock_resource_bundle != 0U) {
        TLobby__sub_8001FE7C((void*)cave_rock_resource_bundle, 1);
        cave_rock_resource_bundle = 0U;
    }
}

extern s32 __vt__10TORockCave[];

#define MK_80175224(dst, off)                                                   \
    {                                                                           \
        void *p = ::operator new(0x440);                   \
        u32 r = (u32)p;                                                         \
        if (p != 0) {                                                           \
            r = load_resource_from_descriptor(p, 1, tbl + (off), 0, 0, 0);               \
        }                                                                       \
        dst = r;                                                                \
    }
void TORockCave::load_resources() {
    u8 *tbl = (u8 *)&rock_cave_resource_table;
    switch (get_current_floor_area()) {
    case AREA_CAVE1:
        MK_80175224(cave_rock_resource_bundle, 0x10)
        MK_80175224(rock_cave_model_resource, 0x88)
        break;
    case AREA_CAVE2:
        MK_80175224(cave_rock_resource_bundle, 0x3C)
        MK_80175224(rock_cave_model_resource, 0xB4)
        break;
    case AREA_CAVE3:
        MK_80175224(cave_rock_resource_bundle, 0x5C)
        MK_80175224(rock_cave_model_resource, 0xE0)
        break;
    default:
        cave_rock_resource_bundle = 0;
        rock_cave_model_resource = 0;
        break;
    }
}

void *__dt__10TORockCaveFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__10TORockCave;
        __dt__14TObjCollidableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_05;
extern const f32 lbl_805DB974;
extern const f32 lbl_805DB978;
extern const char *TORockCave__class_name;

}
TORockCave::TORockCave() : TObjCollidable((TObject *)tl_05) {
    m_name = TORockCave__class_name;
    *(f32 *)((s8 *)this + 0xAC) = lbl_805DB974;
    this->m_b0 = lbl_805DB978;
}
extern "C" {

void TORockCave::vfunc_14() {  }
void TORockCave::vfunc_15() {  }

#pragma push
#pragma readonly_strings on
__declspec(section ".data") BmlResourceBlock_804B3AB8 rock_cave_resource_table = { { "fe_obj_liwa01.gj", "fe_obj_miwa01.gj", "fe_obj_siwa01.gj", NULL }, { "bm_o_rock_cave01.bml", rock_cave_resource_table.model_filenames, bm_o_rock_cave01_motion_names, 3, 0 } };
__declspec(section ".data") BmlResourceBlock_804B3AD8 bm_o_rock_cave02_resource_bundle = { { "fe_obj_liwa02.gj", "fe_obj_miwa02.gj", "fe_obj_siwa02.gj", "fs_obj_liwa025.gj", "fs_obj_miwa025.gj", "fs_obj_siwa025.gj", NULL }, { "bm_o_rock_cave02.bml", bm_o_rock_cave02_resource_bundle.model_filenames, bm_o_rock_cave02_motion_names, 6, 0 } };
__declspec(section ".data") BmlResourceBlock_804B3B04 bm_o_rock_cave03_resource_bundle = { { "fe_obj_liwa03.gj", "fe_obj_miwa03.gj", "fe_obj_siwa03.gj", NULL }, { "bm_o_rock_cave03.bml", bm_o_rock_cave03_resource_bundle.model_filenames, bm_o_rock_cave03_motion_names, 3, 0 } };
__declspec(section ".data") BmlResourceBlock_804B3B24 bm_fe_obj_rb_liwa_resource_bundle = { { "fe_obj_rb_liwa01.gj", "fe_obj_rb_liwa02.gj", "fe_obj_rb_liwa03.gj", "fe_obj_rb_liwa04.gj", "fe_obj_rb_liwa05.gj", "fe_obj_rb_liwa06.gj", NULL }, { "bm_fe_obj_rb_liwa.bml", bm_fe_obj_rb_liwa_resource_bundle.model_filenames, bm_fe_obj_rb_liwa_motion_names, 6, 0 } };
__declspec(section ".data") BmlResourceBlock_804B3B50 bm_fe_obj_rb2_liwa_resource_bundle = { { "fe_obj_rb2_liwa01.gj", "fe_obj_rb2_liwa02.gj", "fe_obj_rb2_liwa03.gj", "fe_obj_rb2_liwa04.gj", "fe_obj_rb2_liwa05.gj", "fe_obj_rb2_liwa06.gj", NULL }, { "bm_fe_obj_rb2_liwa.bml", bm_fe_obj_rb2_liwa_resource_bundle.model_filenames, bm_fe_obj_rb2_liwa_motion_names, 6, 0 } };
__declspec(section ".data") BmlResourceBlock_804B3B7C bm_fe_obj_rb3_liwa_resource_bundle = { { "fe_obj_rb3_liwa01.gj", "fe_obj_rb3_liwa02.gj", "fe_obj_rb3_liwa03.gj", "fe_obj_rb3_liwa04.gj", "fe_obj_rb3_liwa05.gj", "fe_obj_rb3_liwa06.gj", NULL }, { "bm_fe_obj_rb3_liwa.bml", bm_fe_obj_rb3_liwa_resource_bundle.model_filenames, bm_fe_obj_rb3_liwa_motion_names, 6, 0 } };
__declspec(section ".sdata") const char *bm_o_rock_cave01_motion_names[1] = { NULL };
__declspec(section ".sdata") const char *bm_o_rock_cave02_motion_names[1] = { NULL };
__declspec(section ".sdata") const char *bm_o_rock_cave03_motion_names[1] = { NULL };
__declspec(section ".sdata") const char *bm_fe_obj_rb_liwa_motion_names[1] = { NULL };
__declspec(section ".sdata") const char *bm_fe_obj_rb2_liwa_motion_names[1] = { NULL };
__declspec(section ".sdata") const char *bm_fe_obj_rb3_liwa_motion_names[1] = { NULL };

// Class names of the rock family (each subclass constructor stores its own).
const char *TORockCave__class_name = "TORockCave";
const char *TORockCaveSimple__class_name = "TORockCaveSimple";
const char *lbl_805D3100 = "TORockCaveBrakable";
const char *lbl_805D3104 = "TORockCaveS01";
const char *lbl_805D3108 = "TORockCaveS02";
const char *lbl_805D310C = "TORockCaveSS02";
const char *lbl_805D3110 = "TORockCaveS03";
const char *lbl_805D3114 = "TORockCaveM01";
const char *lbl_805D3118 = "TORockCaveM02";
const char *TORockCaveSM02__class_name = "TORockCaveSM02";
const char *lbl_805D3120 = "TORockCaveM03";
const char *TORockCaveL01_class_name = "TORockCaveL01";
const char *lbl_805D3128 = "TORockCaveL02";
const char *lbl_805D312C = "TORockCaveSL02";
const char *lbl_805D3130 = "TORockCaveL03";
const char *lbl_805D3134 = "TORockCaveBL01";
const char *lbl_805D3138 = "TORockCaveBL02";
const char *lbl_805D313C = "TORockCaveBL03";

// Debris of a breaking TORockCaveBrakable (TORockCaveBrakable::vfunc_16 copies
// both): six chip offsets from the rock, and the TObjChip parameters it passes
// to each chip (position, model and textures filled in per chip).
extern const Vec rock_cave_debris_offset_table[6];
extern const TObjChipParams rock_cave_debris_init_params;
const Vec rock_cave_debris_offset_table[6] = {
    { 12.0f, 7.0f, 12.0f }, { -14.0f, 16.0f, 13.0f }, { -3.0f, 51.0f, 11.0f },
    { 7.0f, 49.0f, -11.0f }, { -7.0f, 38.0f, -14.0f }, { 8.0f, 16.0f, -16.0f },
};
const TObjChipParams rock_cave_debris_init_params = {
    { 0.25f, 0.07f, 0.26f }, { 0.0f, 0.0f, 0.0f }, { 5.0f, 7.5f, 5.0f },
    { 1024, 256, 1024 }, { 1, 30 }, { 0.0f, 0.6f }, 0, 0, 22,
};
#pragma pop
}
