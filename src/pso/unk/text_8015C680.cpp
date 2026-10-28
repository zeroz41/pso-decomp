#include "types.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/item/TObjContainerBase.h"
#include "pso/misc/TLanguage.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TOKeyMachine01.h"

struct BmlResourceBlock_804B0068 { const char *model_filenames[4]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B0068_size[(sizeof(BmlResourceBlock_804B0068) == 0x20) ? 1 : -1];
typedef char BmlResourceBlock_804B0068_descriptor_offset[(offsetof(BmlResourceBlock_804B0068, descriptor) == 0x10) ? 1 : -1];
struct BmlResourceBlock_804B0088 { const char *model_filenames[4]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B0088_size[(sizeof(BmlResourceBlock_804B0088) == 0x20) ? 1 : -1];
typedef char BmlResourceBlock_804B0088_descriptor_offset[(offsetof(BmlResourceBlock_804B0088, descriptor) == 0x10) ? 1 : -1];
struct BmlResourceBlock_804B00A8 { const char *model_filenames[4]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B00A8_size[(sizeof(BmlResourceBlock_804B00A8) == 0x20) ? 1 : -1];
typedef char BmlResourceBlock_804B00A8_descriptor_offset[(offsetof(BmlResourceBlock_804B00A8, descriptor) == 0x10) ? 1 : -1];
extern char lbl_80440508[];
extern char lbl_80440520[];
extern char lbl_80440540[];
extern char lbl_80440560[];
extern char lbl_8044057C[];
extern char lbl_8044059C[];
extern char lbl_804405BC[];
extern char lbl_804405D8[];
extern char lbl_804405F4[];
extern char lbl_80440608[];
extern char lbl_80440624[];
extern char lbl_80440640[];
extern BmlResourceBlock_804B0068 bm_o_container_ancient_resource_bundle;
extern BmlResourceBlock_804B0088 fe_obj_o_vs2container_resource_bundle;
extern BmlResourceBlock_804B00A8 fe_obj_ex_box1_resource_bundle;
extern const char *bm_o_container_ancient_motion_names[1];
extern const char *fe_obj_o_vs2container_motion_names[1];
extern const char *fe_obj_ex_box1_motion_names[1];

struct Obj_8015C88C {
    u8 pad[0x18];
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(s32 a, f32 b);
};

extern "C" {
extern const f32 lbl_805DB398;
extern const f32 lbl_805DB39C;
void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void *mem_alloc(u32 size);
u8 *load_gvm_texture_file(s32 arg0);
extern char lbl_8044083C[];
extern char lbl_80440850[];
extern char lbl_8044086C[];
extern char lbl_80440888[];
extern char lbl_804408A4[];
extern char lbl_804408C4[];
extern char lbl_804408E4[];
extern char lbl_80440900[];
extern char lbl_80440920[];
extern s32 enable_v2_features;
extern void *ancient_container_resource_bundle;
extern u32 *ancient_container_fragment_texture_lists;
void TLanguage::load_container_fragment_textures() {
    u8 *tbl = (u8 *)&bm_o_container_ancient_resource_bundle;
    s32 state = TOKeyMachine01::get_global_state();
    void *p;
    if (enable_v2_features == 1 &&
        (state == 0x10 || state == 0x15 || state == 0x16 || state == 0x21)) {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, tbl + 0x50, 0, 0, 0);
        }
        ancient_container_resource_bundle = p;
        ancient_container_fragment_texture_lists = (u32 *)mem_alloc(0xC);
        ancient_container_fragment_texture_lists[0] = (u32)load_gvm_texture_file((s32)lbl_8044083C);
        ancient_container_fragment_texture_lists[1] = (u32)load_gvm_texture_file((s32)lbl_80440850);
        ancient_container_fragment_texture_lists[2] = (u32)load_gvm_texture_file((s32)lbl_8044086C);
    } else if (enable_v2_features == 1 &&
               (state == 0x11 || state == 0x13 || state == 0x14 || state == 0x20)) {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, tbl + 0x30, 0, 0, 0);
        }
        ancient_container_resource_bundle = p;
        ancient_container_fragment_texture_lists = (u32 *)mem_alloc(0xC);
        ancient_container_fragment_texture_lists[0] = (u32)load_gvm_texture_file((s32)lbl_80440888);
        ancient_container_fragment_texture_lists[1] = (u32)load_gvm_texture_file((s32)lbl_804408A4);
        ancient_container_fragment_texture_lists[2] = (u32)load_gvm_texture_file((s32)lbl_804408C4);
    } else {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, tbl + 0x10, 0, 0, 0);
        }
        ancient_container_resource_bundle = p;
        ancient_container_fragment_texture_lists = (u32 *)mem_alloc(0xC);
        ancient_container_fragment_texture_lists[0] = (u32)load_gvm_texture_file((s32)lbl_804408E4);
        ancient_container_fragment_texture_lists[1] = (u32)load_gvm_texture_file((s32)lbl_80440900);
        ancient_container_fragment_texture_lists[2] = (u32)load_gvm_texture_file((s32)lbl_80440920);
    }
}

int TUnk_804B6C24::calc_distance_accuracy_penalty(void *, void *, void *, float) { return 1; }

f32 TUnk_804B6C24::receive_weapon_special_attack(void *, void *) {
    Obj_8015C88C *self = (Obj_8015C88C *)this;
    self->m20(0, lbl_805DB398);
    return lbl_805DB39C;
}

void TUnk_804B6C24::apply_knockback_from_attacker(u8 *) {  }
s32 TUnk_804B6C24::try_start_action(s32, s32) { return 1; }
s32 TUnk_804B6C24::roll_physical_accuracy(void *, s32, f32) { return 1; }

__declspec(section ".data") BmlResourceBlock_804B0068 bm_o_container_ancient_resource_bundle = { { lbl_80440508, lbl_80440520, lbl_80440540, NULL }, { lbl_80440560, bm_o_container_ancient_resource_bundle.model_filenames, bm_o_container_ancient_motion_names, 3, 0 } };
__declspec(section ".data") BmlResourceBlock_804B0088 fe_obj_o_vs2container_resource_bundle = { { lbl_8044057C, lbl_8044059C, lbl_804405BC, NULL }, { lbl_804405D8, fe_obj_o_vs2container_resource_bundle.model_filenames, fe_obj_o_vs2container_motion_names, 3, 0 } };
__declspec(section ".data") BmlResourceBlock_804B00A8 fe_obj_ex_box1_resource_bundle = { { lbl_804405F4, lbl_80440608, lbl_80440624, NULL }, { lbl_80440640, fe_obj_ex_box1_resource_bundle.model_filenames, fe_obj_ex_box1_motion_names, 3, 0 } };
__declspec(section ".sdata") const char *bm_o_container_ancient_motion_names[1] = { NULL };
__declspec(section ".sdata") const char *fe_obj_o_vs2container_motion_names[1] = { NULL };
__declspec(section ".sdata") const char *fe_obj_ex_box1_motion_names[1] = { NULL };
}
