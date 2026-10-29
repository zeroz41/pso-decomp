#include "types.h"
#include "pso/unk/text_80166B6C.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOFenceAncient02.h"
#include "pso/player/TUnk_804B1B80.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TOFenceAncient01.h"
#include "pso/player/TObjPlayer.h"

extern char lbl_80441438[];
extern char lbl_80441450[];
extern char lbl_80441468[];
extern const char *bm_fd_obj_n_saku_4x2_model_names[2];
extern const char *bm_fd_obj_n_saku_4x2_motion_names[2];
extern BmlResourceDescriptor ofence_ancient01_resource_descriptor;

struct RecoveredGlobal_80166D5C_lbl_804B1BE8 {
    s32 value;
    u8 remaining[0x80];
};

struct RecoveredGlobal_80166D5C___vt__16TOFenceAncient01 {
    s32 value;
    u8 remaining[0x40];
};

struct Sub_80166C40 { u8 pad[0xC]; void *c; };

struct O_80166C40 { u8 pad[0x42C]; Sub_80166C40 *sub; };

struct Arr_80166C40 { void *a; s32 b; s32 c; s32 d; };

extern "C" {
u8 *TLobby__sub_8001FE7C(void *, s16);
void mem_free(void *p);
extern u8 *TOFenceAncient01__model_resource;
extern u32 TOFenceAncient01__resource_pointer_array;
s32 init_collision_body_parts(void *, void *, int, int, f32);
s32 __ct__13TUnk_804B1B80FP7TObject();
extern RecoveredGlobal_80166D5C_lbl_804B1BE8 fence_ancient01_collision_parts;
extern s32 __vt__16TOFenceAncient01[];
extern s32 TOFenceAncient01__class_name;
extern const f32 lbl_805DB610;
extern const f32 lbl_805DB614;
extern const f32 lbl_805DB618;
O_80166C40 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void *mem_alloc(u32 size);
u8 *load_gvm_texture_file(s32 arg0);
extern char lbl_80441498[];
extern char lbl_804414B0[];
extern char lbl_804414C8[];
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

extern void *tl_05;

void *TOFenceAncient01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD8);
    if (o != NULL) {
        o = TOFenceAncient01__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOFenceAncient01::free_resources() {
  s32 var_r31;
  s32 var_r30;
  if (((u32) TOFenceAncient01__resource_pointer_array) != 0)
  {
    var_r30 = 1;
    var_r31 = 4;
    do
    {
      TObjPlayer::free_if_valid(*((s32 *) (((s8 *) TOFenceAncient01__resource_pointer_array) + var_r31)));
      var_r30 += 1;
      var_r31 += 4;
    }
    while (var_r30 < 4);
    if (((u32) TOFenceAncient01__resource_pointer_array) != 0)
    {
      mem_free((void *)TOFenceAncient01__resource_pointer_array);
      TOFenceAncient01__resource_pointer_array = 0;
    }
  }
  if (((void *) TOFenceAncient01__model_resource) != 0)
  {
    TLobby__sub_8001FE7C(TOFenceAncient01__model_resource, 1);
    TOFenceAncient01__model_resource = 0;
  }
}

void TOFenceAncient01::load_resources() {
    O_80166C40 *o;
    Arr_80166C40 *r;
    o = (O_80166C40 *)::operator new(0x440);
    if (o != NULL) {
        o = load_resource_from_descriptor(o, 1, &ofence_ancient01_resource_descriptor, 0, 0, 0);
    }
    (*(O_80166C40 * *)&TOFenceAncient01__model_resource) = o;
    r = (Arr_80166C40 *)mem_alloc(0x10);
    (*(Arr_80166C40 * *)&TOFenceAncient01__resource_pointer_array) = r;
    r->a = (*(O_80166C40 * *)&TOFenceAncient01__model_resource)->sub->c;
    (*(Arr_80166C40 * *)&TOFenceAncient01__resource_pointer_array)->b = (s32)load_gvm_texture_file((s32)lbl_80441498);
    (*(Arr_80166C40 * *)&TOFenceAncient01__resource_pointer_array)->c = (s32)load_gvm_texture_file((s32)lbl_804414B0);
    (*(Arr_80166C40 * *)&TOFenceAncient01__resource_pointer_array)->d = (s32)load_gvm_texture_file((s32)lbl_804414C8);
}

void *__dt__16TOFenceAncient01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TOFenceAncient01;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__13TUnk_804B1B80Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80166D5C_lbl_804B1BE8_size[sizeof(RecoveredGlobal_80166D5C_lbl_804B1BE8) == 0x84 ? 1 : -1];
typedef char RecoveredGlobal_80166D5C___vt__16TOFenceAncient01_size[sizeof(RecoveredGlobal_80166D5C___vt__16TOFenceAncient01) == 0x44 ? 1 : -1];
u8 *TOFenceAncient01__ct(u8 *arg0, s32 arg1, s32 arg2) {
    f32 temp_f1;
    u8 *temp_r4;
    u8 *temp_r6;
    __ct__13TUnk_804B1B80FP7TObject();
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80166D5C___vt__16TOFenceAncient01 *)&__vt__16TOFenceAncient01).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TOFenceAncient01__class_name;
    ((TOFenceAncient01 *)(arg0))->apply_object_set_data((void *)arg2);
    temp_r4 = (u8 *)(*(u8 **)((s8 *)TOFenceAncient01__model_resource + 0x42C));
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)temp_r4 + 8);
    ((TOFenceAncient01 *)arg0)->texlist = (s32) *(s32 *)((s8 *)((*(s32 *)&TOFenceAncient01__resource_pointer_array) + (((TUnk_804B1B80 *)arg0)->sub_80166EA8((int)temp_r4) * 4)) + 0);
    *(u8 **)((s8 *)arg0 + 0xBC) = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)TOFenceAncient01__model_resource + 0x430)) + 4));
    temp_r6 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xBC));
    temp_f1 = (f32) *(u32 *)((s8 *)temp_r6 + 4);
    *(f32 *)((s8 *)arg0 + 0xB4) = (f32) (temp_f1 - lbl_805DB610);
    init_collision_body_parts((void *)arg0, &fence_ancient01_collision_parts.value, 3, (int)temp_r6, (f32)temp_f1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TUnk_804B1B80 *)arg0)->sub_80166E64();
    ((TOFenceAncient01 *)arg0)->view_range = (f32) lbl_805DB614;
    *(f32 *)((s8 *)arg0 + 0xC4) = (f32) lbl_805DB618;
    return arg0;
}

s32 TUnk_804B1B80::sub_80166E64() {
    s32 temp_r0;
    this->switch_id = (s32) this->set_params[0];
    temp_r0 = this->switch_id;
    if (temp_r0 > 0x100) {
        this->trigger_mode = 0;
    } else if (temp_r0 < 0) {
        this->trigger_mode = 1;
    } else {
        this->trigger_mode = 2;
    }
    return this->switch_id;
}

s32 TUnk_804B1B80::sub_80166EA8(int _w1) {
    s32 temp_r0;
    this->m_d4 = (s32) this->set_params[1];
    temp_r0 = this->m_d4;
    if (temp_r0 < 0) {
        this->m_d4 = 0;
    } else if (temp_r0 >= 4) {
        this->m_d4 = 3;
    }
    return this->m_d4;
}

void TOFenceAncient02::update_demo() {  }
void TOFenceAncient02::close() { *(int *)&this->object_state = 0; this->is_open = 0; this->clear_player_status_flag((s32)((void*)0), (u32)((void*)8)); }
void TOFenceAncient02::open() { *(int *)&this->object_state = 1; this->is_open = 1; set_indexed_flags((s32)((void*)0), (s32)((void*)8)); }

__declspec(section ".data") const char *bm_fd_obj_n_saku_4x2_model_names[2] = { lbl_80441438, NULL };
__declspec(section ".data") const char *bm_fd_obj_n_saku_4x2_motion_names[2] = { lbl_80441450, NULL };
BmlResourceDescriptor ofence_ancient01_resource_descriptor = { lbl_80441468, bm_fd_obj_n_saku_4x2_model_names, bm_fd_obj_n_saku_4x2_motion_names, 1, 1 };
}
