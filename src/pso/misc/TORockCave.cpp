#include "types.h"
#include "pso/misc/TORockCave.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TOSensor.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TORockCave.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

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
extern char lbl_804424A0[];
extern char lbl_804424B4[];
extern char lbl_804424C8[];
extern char lbl_804424DC[];
extern char lbl_804424F4[];
extern char lbl_80442508[];
extern char lbl_8044251C[];
extern char lbl_80442530[];
extern char lbl_80442544[];
extern char lbl_80442558[];
extern char lbl_8044256C[];
extern char lbl_80442584[];
extern char lbl_80442598[];
extern char lbl_804425AC[];
extern char lbl_804425C0[];
extern char lbl_804425D8[];
extern char lbl_804425EC[];
extern char lbl_80442600[];
extern char lbl_80442614[];
extern char lbl_80442628[];
extern char lbl_8044263C[];
extern char lbl_80442650[];
extern char lbl_80442668[];
extern char lbl_80442680[];
extern char lbl_80442698[];
extern char lbl_804426B0[];
extern char lbl_804426C8[];
extern char lbl_804426E0[];
extern char lbl_804426F8[];
extern char lbl_80442710[];
extern char lbl_80442728[];
extern char lbl_80442740[];
extern char lbl_80442758[];
extern char lbl_80442770[];
extern char lbl_80442788[];
extern char lbl_804427A0[];
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
void __ct__13TUnk_804AF8A0FP7TObject(void *, void *);
void __dl__7TObjectFPv(void *);

void TORockCave::draw_model() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_18 *)(arg0))->m8(*(f32 *)&this->unk_AC, this->m_b0) != 0) {
        this->vfunc_14();
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texture_id);
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
    switch (TOKeyMachine01::get_global_state()) {
    case 3:
        MK_80175224(cave_rock_resource_bundle, 0x10)
        MK_80175224(rock_cave_model_resource, 0x88)
        break;
    case 4:
        MK_80175224(cave_rock_resource_bundle, 0x3C)
        MK_80175224(rock_cave_model_resource, 0xB4)
        break;
    case 5:
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
        __dt__13TUnk_804AF8A0Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_05;
extern const f32 lbl_805DB974;
extern const f32 lbl_805DB978;
extern void *TORockCave__class_name;

}
TORockCave::TORockCave() : TUnk_804AF8A0((TObject *)tl_05) {
    *(void * *)&this->m_name = TORockCave__class_name;
    *(f32 *)((s8 *)this + 0xAC) = lbl_805DB974;
    this->m_b0 = lbl_805DB978;
}
extern "C" {

void TORockCave::vfunc_14() {  }
void TORockCave::vfunc_15() {  }

__declspec(section ".data") BmlResourceBlock_804B3AB8 rock_cave_resource_table = { { lbl_804424A0, lbl_804424B4, lbl_804424C8, NULL }, { lbl_804424DC, rock_cave_resource_table.model_filenames, bm_o_rock_cave01_motion_names, 3, 0 } };
__declspec(section ".data") BmlResourceBlock_804B3AD8 bm_o_rock_cave02_resource_bundle = { { lbl_804424F4, lbl_80442508, lbl_8044251C, lbl_80442530, lbl_80442544, lbl_80442558, NULL }, { lbl_8044256C, bm_o_rock_cave02_resource_bundle.model_filenames, bm_o_rock_cave02_motion_names, 6, 0 } };
__declspec(section ".data") BmlResourceBlock_804B3B04 bm_o_rock_cave03_resource_bundle = { { lbl_80442584, lbl_80442598, lbl_804425AC, NULL }, { lbl_804425C0, bm_o_rock_cave03_resource_bundle.model_filenames, bm_o_rock_cave03_motion_names, 3, 0 } };
__declspec(section ".data") BmlResourceBlock_804B3B24 bm_fe_obj_rb_liwa_resource_bundle = { { lbl_804425D8, lbl_804425EC, lbl_80442600, lbl_80442614, lbl_80442628, lbl_8044263C, NULL }, { lbl_80442650, bm_fe_obj_rb_liwa_resource_bundle.model_filenames, bm_fe_obj_rb_liwa_motion_names, 6, 0 } };
__declspec(section ".data") BmlResourceBlock_804B3B50 bm_fe_obj_rb2_liwa_resource_bundle = { { lbl_80442668, lbl_80442680, lbl_80442698, lbl_804426B0, lbl_804426C8, lbl_804426E0, NULL }, { lbl_804426F8, bm_fe_obj_rb2_liwa_resource_bundle.model_filenames, bm_fe_obj_rb2_liwa_motion_names, 6, 0 } };
__declspec(section ".data") BmlResourceBlock_804B3B7C bm_fe_obj_rb3_liwa_resource_bundle = { { lbl_80442710, lbl_80442728, lbl_80442740, lbl_80442758, lbl_80442770, lbl_80442788, NULL }, { lbl_804427A0, bm_fe_obj_rb3_liwa_resource_bundle.model_filenames, bm_fe_obj_rb3_liwa_motion_names, 6, 0 } };
__declspec(section ".sdata") const char *bm_o_rock_cave01_motion_names[1] = { NULL };
__declspec(section ".sdata") const char *bm_o_rock_cave02_motion_names[1] = { NULL };
__declspec(section ".sdata") const char *bm_o_rock_cave03_motion_names[1] = { NULL };
__declspec(section ".sdata") const char *bm_fe_obj_rb_liwa_motion_names[1] = { NULL };
__declspec(section ".sdata") const char *bm_fe_obj_rb2_liwa_motion_names[1] = { NULL };
__declspec(section ".sdata") const char *bm_fe_obj_rb3_liwa_motion_names[1] = { NULL };
}
