#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TUnk_804B1B80.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TOFenceAncient03.h"
#include "pso/misc/TOFenceAncient01.h"
#include "pso/player/TObjPlayer.h"

extern char lbl_80441598[];
extern char lbl_804415B0[];
extern char lbl_804415C8[];
extern const char *bm_fd_obj_n_saku_4x4_model_names[2];
extern const char *bm_fd_obj_n_saku_4x4_motion_names[2];
extern BmlResourceDescriptor TOFenceAncient03_resource_descriptor;

struct RecoveredGlobal_801674E0_lbl_804B1DB8 {
    s32 value;
    u8 remaining[0x15C];
};

struct RecoveredGlobal_801674E0___vt__16TOFenceAncient03 {
    s32 value;
    u8 remaining[0x44];
};

struct Sub_801673C4 { u8 pad[0xC]; void *c; };

struct O_801673C4 { u8 pad[0x42C]; Sub_801673C4 *sub; };

struct Arr_801673C4 { void *a; s32 b; s32 c; s32 d; };

extern "C" {
u8 *TLobby__sub_8001FE7C(void *, s16);
void mem_free(void *p);
extern u8 *TOFenceAncient03__shared_resource_object;
extern u32 TOFenceAncient03__texture_lists;
s32 init_collision_body_parts(void *, void *, int, int, f32);
s32 init_fields__13TUnk_804B1B80Fv();
extern RecoveredGlobal_801674E0_lbl_804B1DB8 TOFenceAncient03_collision_body_parts;
extern s32 __vt__16TOFenceAncient03[];
extern s32 TOFenceAncient03__class_name;
extern const f32 lbl_805DB630;
extern const f32 lbl_805DB634;
extern const f32 lbl_805DB638;
O_801673C4 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void *mem_alloc(u32 size);
u8 *load_gvm_texture_file(s32 arg0);
extern char lbl_804415F8[];
extern char lbl_80441610[];
extern char lbl_80441628[];
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TOFenceAncient03::vfunc_16() {  }
void TOFenceAncient03::vfunc_15() { *(int *)&this->m_ac = 0; *(int *)&this->unk_D0 = 0; { int i; for (i = 0; i < 4; i++) { this->clear_player_status_flag((s32)((void*)i), (u32)((void*)8)); } } }
void TOFenceAncient03::vfunc_14() { *(int *)&this->m_ac = 1; *(int *)&this->unk_D0 = 1; { int i; for (i = 0; i < 4; i++) { set_indexed_flags(i, (s32)((void*)8)); } } }

extern void *tl_05;

void *TOFenceAncient03::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD8);
    if (o != NULL) {
        o = TOFenceAncient03__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOFenceAncient03::free_shared_resources() {
  s32 var_r31;
  s32 var_r30;
  if (((u32) TOFenceAncient03__texture_lists) != 0)
  {
    var_r30 = 1;
    var_r31 = 4;
    do
    {
      TObjPlayer::free_if_valid(*((s32 *) (((s8 *) TOFenceAncient03__texture_lists) + var_r31)));
      var_r30 += 1;
      var_r31 += 4;
    }
    while (var_r30 < 4);
    if (((u32) TOFenceAncient03__texture_lists) != 0)
    {
      mem_free((void *)TOFenceAncient03__texture_lists);
      TOFenceAncient03__texture_lists = 0;
    }
  }
  if (((void *) TOFenceAncient03__shared_resource_object) != 0)
  {
    TLobby__sub_8001FE7C(TOFenceAncient03__shared_resource_object, 1);
    TOFenceAncient03__shared_resource_object = 0;
  }
}

void TOFenceAncient03::load_resources() {
    O_801673C4 *o;
    Arr_801673C4 *r;
    o = (O_801673C4 *)::operator new(0x440);
    if (o != NULL) {
        o = load_resource_from_descriptor(o, 1, &TOFenceAncient03_resource_descriptor, 0, 0, 0);
    }
    (*(O_801673C4 * *)&TOFenceAncient03__shared_resource_object) = o;
    r = (Arr_801673C4 *)mem_alloc(0x10);
    (*(Arr_801673C4 * *)&TOFenceAncient03__texture_lists) = r;
    r->a = (*(O_801673C4 * *)&TOFenceAncient03__shared_resource_object)->sub->c;
    (*(Arr_801673C4 * *)&TOFenceAncient03__texture_lists)->b = (s32)load_gvm_texture_file((s32)lbl_804415F8);
    (*(Arr_801673C4 * *)&TOFenceAncient03__texture_lists)->c = (s32)load_gvm_texture_file((s32)lbl_80441610);
    (*(Arr_801673C4 * *)&TOFenceAncient03__texture_lists)->d = (s32)load_gvm_texture_file((s32)lbl_80441628);
}

void *__dt__16TOFenceAncient03Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TOFenceAncient03;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B1B80 *)arg0)->destroy(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_801674E0_lbl_804B1DB8_size[sizeof(RecoveredGlobal_801674E0_lbl_804B1DB8) == 0x160 ? 1 : -1];
typedef char RecoveredGlobal_801674E0___vt__16TOFenceAncient03_size[sizeof(RecoveredGlobal_801674E0___vt__16TOFenceAncient03) == 0x48 ? 1 : -1];
u8 *TOFenceAncient03__ct(u8 *arg0, s32 arg1, s32 arg2) {
    f32 temp_f1;
    u8 *temp_r4;
    u8 *temp_r6;
    init_fields__13TUnk_804B1B80Fv();
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_801674E0___vt__16TOFenceAncient03 *)&__vt__16TOFenceAncient03).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TOFenceAncient03__class_name;
    ((TOFenceAncient03 *)(arg0))->apply_object_set_data((void *)arg2);
    temp_r4 = (u8 *)(*(u8 **)((s8 *)TOFenceAncient03__shared_resource_object + 0x42C));
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)temp_r4 + 8);
    ((TOFenceAncient03 *)arg0)->texture_id = (s32) *(s32 *)((s8 *)((*(s32 *)&TOFenceAncient03__texture_lists) + (((TUnk_804B1B80 *)arg0)->sub_80166EA8((int)temp_r4) * 4)) + 0);
    *(u8 **)((s8 *)arg0 + 0xBC) = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)TOFenceAncient03__shared_resource_object + 0x430)) + 4));
    temp_r6 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xBC));
    temp_f1 = (f32) *(u32 *)((s8 *)temp_r6 + 4);
    *(f32 *)((s8 *)arg0 + 0xB4) = (f32) (temp_f1 - lbl_805DB630);
    init_collision_body_parts((void *)arg0, &TOFenceAncient03_collision_body_parts.value, 8, (int)temp_r6, (f32)temp_f1);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->reset_photon_effect();
    ((TUnk_804B1B80 *)arg0)->sub_80166E64();
    ((TOFenceAncient03 *)arg0)->m_c0 = (f32) lbl_805DB634;
    *(f32 *)((s8 *)arg0 + 0xC4) = (f32) lbl_805DB638;
    return arg0;
}

__declspec(section ".data") const char *bm_fd_obj_n_saku_4x4_model_names[2] = { lbl_80441598, NULL };
__declspec(section ".data") const char *bm_fd_obj_n_saku_4x4_motion_names[2] = { lbl_804415B0, NULL };
BmlResourceDescriptor TOFenceAncient03_resource_descriptor = { lbl_804415C8, bm_fd_obj_n_saku_4x4_model_names, bm_fd_obj_n_saku_4x4_motion_names, 1, 1 };
}
