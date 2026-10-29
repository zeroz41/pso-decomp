#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TUnk_804B1B80.h"
#include "pso/misc/TOFenceAncient02.h"
#include "pso/misc/TOFenceAncient01.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8016713C_lbl_804B1CD0 {
    s32 value;
    u8 remaining[0x80];
};

struct RecoveredGlobal_8016713C___vt__16TOFenceAncient02 {
    s32 value;
    u8 remaining[0x40];
};

struct Sub_80167020 { u8 pad[0xC]; void *c; };

struct O_80167020 { u8 pad[0x42C]; Sub_80167020 *sub; };

struct Arr_80167020 { void *a; s32 b; s32 c; s32 d; };

extern "C" {
u8 *TLobby__sub_8001FE7C(void *, s16);
void mem_free(void *p);
extern u8 *TOFenceAncient02__model_resource;
extern u32 TOFenceAncient02__texture_variants;
s32 init_collision_body_parts(void *, void *, int, int, f32);
s32 __ct__13TUnk_804B1B80FP7TObject();
extern RecoveredGlobal_8016713C_lbl_804B1CD0 fence_ancient02_collision_body_parts;
extern s32 __vt__16TOFenceAncient02[];
extern s32 TOFenceAncient02__class_name;
extern const f32 lbl_805DB620;
extern const f32 lbl_805DB624;
extern const f32 lbl_805DB628;
O_80167020 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void *mem_alloc(u32 size);
u8 *load_gvm_texture_file(s32 arg0);
extern char lbl_80441548[];
extern char lbl_80441560[];
extern char lbl_80441578[];
extern char bm_fd_obj_n_saku_6x2_resource_descriptor[];
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

extern void *tl_05;

void *TOFenceAncient02::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD8);
    if (o != NULL) {
        o = TOFenceAncient02__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOFenceAncient02::free_resources() {
  s32 var_r31;
  s32 var_r30;
  int new_var;
  if (((u32) TOFenceAncient02__texture_variants) != 0)
  {
    var_r30 = 1;
    var_r31 = 4;
    do
    {
      TObjPlayer::free_if_valid(*((s32 *) (((s8 *) TOFenceAncient02__texture_variants) + var_r31)));
      var_r30 += 1;
      var_r31 += 4;
    }
    while (var_r30 < 4);
    if (((u32) TOFenceAncient02__texture_variants) != 0)
    {
      mem_free((void *)TOFenceAncient02__texture_variants);
      TOFenceAncient02__texture_variants = 0;
    }
  }
  new_var = ((void *) TOFenceAncient02__model_resource) != 0;
  if (new_var)
  {
    TLobby__sub_8001FE7C(TOFenceAncient02__model_resource, 1);
    TOFenceAncient02__model_resource = 0;
  }
}

void TOFenceAncient02::load_assets() {
    O_80167020 *o;
    Arr_80167020 *r;
    o = (O_80167020 *)::operator new(0x440);
    if (o != NULL) {
        o = load_resource_from_descriptor(o, 1, bm_fd_obj_n_saku_6x2_resource_descriptor, 0, 0, 0);
    }
    (*(O_80167020 * *)&TOFenceAncient02__model_resource) = o;
    r = (Arr_80167020 *)mem_alloc(0x10);
    (*(Arr_80167020 * *)&TOFenceAncient02__texture_variants) = r;
    r->a = (*(O_80167020 * *)&TOFenceAncient02__model_resource)->sub->c;
    (*(Arr_80167020 * *)&TOFenceAncient02__texture_variants)->b = (s32)load_gvm_texture_file((s32)lbl_80441548);
    (*(Arr_80167020 * *)&TOFenceAncient02__texture_variants)->c = (s32)load_gvm_texture_file((s32)lbl_80441560);
    (*(Arr_80167020 * *)&TOFenceAncient02__texture_variants)->d = (s32)load_gvm_texture_file((s32)lbl_80441578);
}

void *__dt__16TOFenceAncient02Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TOFenceAncient02;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__13TUnk_804B1B80Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8016713C_lbl_804B1CD0_size[sizeof(RecoveredGlobal_8016713C_lbl_804B1CD0) == 0x84 ? 1 : -1];
typedef char RecoveredGlobal_8016713C___vt__16TOFenceAncient02_size[sizeof(RecoveredGlobal_8016713C___vt__16TOFenceAncient02) == 0x44 ? 1 : -1];
u8 *TOFenceAncient02__ct(u8 *arg0, s32 arg1, s32 arg2) {
    f32 temp_f1;
    u8 *temp_r4;
    u8 *temp_r6;
    __ct__13TUnk_804B1B80FP7TObject();
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8016713C___vt__16TOFenceAncient02 *)&__vt__16TOFenceAncient02).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TOFenceAncient02__class_name;
    ((TOFenceAncient02 *)(arg0))->apply_object_set_data((void *)arg2);
    temp_r4 = (u8 *)(*(u8 **)((s8 *)TOFenceAncient02__model_resource + 0x42C));
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)temp_r4 + 8);
    ((TOFenceAncient02 *)arg0)->texlist = (s32) *(s32 *)((s8 *)((*(s32 *)&TOFenceAncient02__texture_variants) + (((TUnk_804B1B80 *)arg0)->sub_80166EA8((int)temp_r4) * 4)) + 0);
    *(u8 **)((s8 *)arg0 + 0xBC) = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)TOFenceAncient02__model_resource + 0x430)) + 4));
    temp_r6 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xBC));
    temp_f1 = (f32) *(u32 *)((s8 *)temp_r6 + 4);
    *(f32 *)((s8 *)arg0 + 0xB4) = (f32) (temp_f1 - lbl_805DB620);
    init_collision_body_parts((void *)arg0, &fence_ancient02_collision_body_parts.value, 3, (int)temp_r6, (f32)temp_f1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TUnk_804B1B80 *)arg0)->sub_80166E64();
    ((TOFenceAncient02 *)arg0)->view_range = (f32) lbl_805DB624;
    *(f32 *)((s8 *)arg0 + 0xC4) = (f32) lbl_805DB628;
    return arg0;
}

}
