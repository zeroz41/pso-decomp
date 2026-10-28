#include "types.h"
#include "pso/misc/TOHangceilingCave01Key.h"
#include "pso/misc/TOHangceilingCave01KeyQuick.h"
#include "pso/misc/TOHangceilingCave01Normal.h"
#include "pso/misc/TUnk_804B2578.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TUnk_804B1B80.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TOFenceAncient04.h"
#include "pso/misc/TOFenceAncient01.h"
#include "pso/misc/TOHangceilingCave01.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern const char lbl_80441648[];
extern const char lbl_80441660[];
extern const char lbl_80441678[];
extern const char *bm_fd_obj_n_saku_6x4_model_names[2];
extern const char *bm_fd_obj_n_saku_6x4_motion_names[2];
extern BmlResourceDescriptor TOFenceAncient04_resource_descriptor;

extern "C" {

struct RecoveredGlobal_80167878_lbl_804B1F80 {
    s32 value;
    u8 remaining[0x15C];
};

struct RecoveredGlobal_80167878___vt__16TOFenceAncient04 {
    s32 value;
    u8 remaining[0x44];
};

struct Inner_8016775C { u8 pad[0xC]; s32 f0C; };

struct Big_8016775C { u8 pad[0x42C]; Inner_8016775C *p; };

struct Buf_8016775C { s32 a; s32 b; s32 c; s32 d; };

typedef char RecoveredGlobal_80167878_lbl_804B1F80_size[sizeof(RecoveredGlobal_80167878_lbl_804B1F80) == 0x160 ? 1 : -1];

typedef char RecoveredGlobal_80167878___vt__16TOFenceAncient04_size[sizeof(RecoveredGlobal_80167878___vt__16TOFenceAncient04) == 0x48 ? 1 : -1];

struct RecoveredGlobal_80167C78___vt__27TOHangceilingCave01KeyQuick {
    s32 value;
    u8 remaining[0x144];
};

typedef char RecoveredGlobal_80167C78___vt__27TOHangceilingCave01KeyQuick_size[sizeof(RecoveredGlobal_80167C78___vt__27TOHangceilingCave01KeyQuick) == 0x148 ? 1 : -1];

void TLobby__sub_8001FE7C(void*, int);
Big_8016775C * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void mem_free(void *p);
void *mem_alloc(u32 size);
s32 free_collision_body_parts(void *);
s32 init_collision_body_parts(void *, void *, int, int, f32);
s32 init_fields__13TUnk_804B1B80Fv();
u8 *load_gvm_texture_file(s32 arg0);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);

extern s32 __vt__16TOFenceAncient04[];
extern RecoveredGlobal_80167878_lbl_804B1F80 ofence_ancient04_collision_parts;
extern s32 TOFenceAncient04__class_name;
extern u32 TOFenceAncient04__model_archive;
extern void *TOFenceAncient04__resource_bundle;
extern const f32 lbl_805DB640;
extern const f32 lbl_805DB644;
extern const f32 lbl_805DB648;
extern void *tl_05;

extern const char lbl_80441648[] = "fd_obj_n_saku_6x4.gj";
extern const char lbl_80441660[] = "fd_obj_n_saku_6x4.njm";
extern const char lbl_80441678[] = "bm_fd_obj_n_saku_6x4.bml";
extern const char TOFenceAncient04__class_name_string[] = "TOFenceAncient04";
__declspec(section ".rodata") extern const char lbl_804416A8[];
__declspec(section ".rodata") extern const char lbl_804416C0[];
__declspec(section ".rodata") extern const char lbl_804416D8[];

void TOFenceAncient04::vfunc_16() {  }

void TOFenceAncient04::vfunc_15() { *(int *)&this->m_ac = 0; *(int *)&this->unk_D0 = 0; { int i; for (i = 0; i < 4; i++) { this->clear_player_status_flag((s32)((void*)i), (u32)((void*)8)); } } }

void TOFenceAncient04::vfunc_14() { *(int *)&this->m_ac = 1; *(int *)&this->unk_D0 = 1; { int i; for (i = 0; i < 4; i++) { set_indexed_flags(i, (s32)((void*)8)); } } }

void *TOFenceAncient04::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD8);
    if (o != NULL) {
        o = TOFenceAncient04__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOFenceAncient04::destroy() {
    if ((void *) TOFenceAncient04__resource_bundle != NULL) {
        TObjPlayer::free_if_valid(*(s32 *)((s8 *)TOFenceAncient04__resource_bundle + 4));
        TObjPlayer::free_if_valid(*(s32 *)((s8 *)TOFenceAncient04__resource_bundle + 8));
        TObjPlayer::free_if_valid(*(s32 *)((s8 *)TOFenceAncient04__resource_bundle + 0xC));
        if ((void *) TOFenceAncient04__resource_bundle != NULL) {
            mem_free(TOFenceAncient04__resource_bundle);
            TOFenceAncient04__resource_bundle = NULL;
        }
    }
    if ((u32) TOFenceAncient04__model_archive != 0U) {
        TLobby__sub_8001FE7C((void*)TOFenceAncient04__model_archive, 1);
        TOFenceAncient04__model_archive = 0U;
    }
}

void TOFenceAncient04::load_resources() {
    Big_8016775C *v = (Big_8016775C *)::operator new(0x440);
    if (v != NULL) {
        v = load_resource_from_descriptor(v, 1, &TOFenceAncient04_resource_descriptor, 0, 0, 0);
    }
    (*(Big_8016775C * *)&TOFenceAncient04__model_archive) = v;
    (*(Buf_8016775C * *)&TOFenceAncient04__resource_bundle) = (Buf_8016775C *)mem_alloc(0x10);
    (*(Buf_8016775C * *)&TOFenceAncient04__resource_bundle)->a = (*(Big_8016775C * *)&TOFenceAncient04__model_archive)->p->f0C;
    (*(Buf_8016775C * *)&TOFenceAncient04__resource_bundle)->b = (s32)load_gvm_texture_file((s32)lbl_804416A8);
    (*(Buf_8016775C * *)&TOFenceAncient04__resource_bundle)->c = (s32)load_gvm_texture_file((s32)lbl_804416C0);
    (*(Buf_8016775C * *)&TOFenceAncient04__resource_bundle)->d = (s32)load_gvm_texture_file((s32)lbl_804416D8);
}

__declspec(section ".rodata") extern const char lbl_804416A8[] = "o_fence_ancient_b.gvm";
__declspec(section ".rodata") extern const char lbl_804416C0[] = "o_fence_ancient_g.gvm";
__declspec(section ".rodata") extern const char lbl_804416D8[] = "o_fence_ancient_p.gvm";

void *__dt__16TOFenceAncient04Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TOFenceAncient04;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B1B80 *)arg0)->destroy(0);
        if (arg1 > 0) {
            ((s32 (*)(void *))__dl__7TObjectFPv)(arg0);
        }
    }
    return arg0;
}

u8 *TOFenceAncient04__ct(u8 *arg0, s32 arg1, s32 arg2) {
    f32 temp_f1;
    u8 *temp_r4;
    u8 *temp_r6;
    init_fields__13TUnk_804B1B80Fv();
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80167878___vt__16TOFenceAncient04 *)&__vt__16TOFenceAncient04).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TOFenceAncient04__class_name;
    ((TOFenceAncient04 *)(arg0))->apply_object_set_data((void *)arg2);
    temp_r4 = (u8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOFenceAncient04__model_archive) + 0x42C));
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)temp_r4 + 8);
    ((TOFenceAncient04 *)arg0)->texture_id = (s32) *(s32 *)((s8 *)((*(s32 *)&TOFenceAncient04__resource_bundle) + (((TUnk_804B1B80 *)arg0)->sub_80166EA8((int)temp_r4) * 4)) + 0);
    *(u8 **)((s8 *)arg0 + 0xBC) = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOFenceAncient04__model_archive) + 0x430)) + 4));
    temp_r6 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xBC));
    temp_f1 = (f32) *(u32 *)((s8 *)temp_r6 + 4);
    *(f32 *)((s8 *)arg0 + 0xB4) = (f32) (temp_f1 - lbl_805DB640);
    init_collision_body_parts((void *)arg0, &ofence_ancient04_collision_parts.value, 8, (int)temp_r6, (f32)temp_f1);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->reset_photon_effect();
    ((TUnk_804B1B80 *)arg0)->sub_80166E64();
    ((TOFenceAncient04 *)arg0)->m_c0 = (f32) lbl_805DB644;
    *(f32 *)((s8 *)arg0 + 0xC4) = (f32) lbl_805DB648;
    return arg0;
}

__declspec(section ".data") const char *bm_fd_obj_n_saku_6x4_model_names[2] = { (const char *)lbl_80441648, NULL };
__declspec(section ".data") const char *bm_fd_obj_n_saku_6x4_motion_names[2] = { (const char *)lbl_80441660, NULL };
BmlResourceDescriptor TOFenceAncient04_resource_descriptor = { (const char *)lbl_80441678, bm_fd_obj_n_saku_6x4_model_names, bm_fd_obj_n_saku_6x4_motion_names, 1, 1 };
}
