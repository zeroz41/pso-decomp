#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/misc/TOCapsuleMachine01.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8015A814_lbl_804AFF10 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8015A814___vt__18TOCapsuleMachine01 {
    s32 value;
    u8 remaining[0x38];
};

struct RecoveredGlobal_8015A734_lbl_804AFF00
{
  s32 value;
  u8 remaining[0xC];
};

struct RecoveredFields_8015A734_var_r4
{
  u8 unknown_0[0x42C];
  u8 *field_42C;
};

extern "C" {
u8 * TLobby__sub_8001FE7C(void *, s16);
extern u8 *TOCapsuleMachine01__model_resource;
extern s32 lbl_805D58C4;
extern s32 TOCapsuleMachine01__last_update_frame_tick;
s32 init_collision_body_parts(void *, void *, int);
s32 init_map_object_base(void *, int);
extern RecoveredGlobal_8015A814_lbl_804AFF10 capsule_machine01_collision_body;
extern s32 __vt__18TOCapsuleMachine01[];
extern s32 lbl_805D2ED4;
extern s32 tl_05;
extern const f32 lbl_805DB380;
extern const f32 lbl_805DB384;
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8015A734_lbl_804AFF00 bm_fs_obj_cap_moto_resource_descriptor;
extern s32 capsule_machine_ginja_mesh_handle;
struct Base_8015A5E8 { char pad[0x18]; };
struct VObj_8015A5E8 : Base_8015A5E8 {
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

s32 PPCSync();
s32 scroll_ginja_mesh_uvs(s32, s32, s32, s32, s32);
s32 post_translate_matrix(void *);
s32 free_collision_body_parts(void *);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

extern s32 actor_frame_tick;

void TOCapsuleMachine01::run_task() {
    if ((s32) TOCapsuleMachine01__last_update_frame_tick != (s32) actor_frame_tick) {
        TOCapsuleMachine01__last_update_frame_tick = actor_frame_tick;
        scroll_ginja_mesh_uvs(capsule_machine_ginja_mesh_handle, 0, 5, 4, 1);
        PPCSync();
    }
}

void TOCapsuleMachine01::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_8015A5E8 *)arg0)->m8(this->m_c0, *(f32 *)&this->m_c4) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texture_id);
        draw_ginja_object((void *)(*(s32 *)&this->model));
        pop_matrix();
    }
}

void *TOCapsuleMachine01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xC8);
    if (o != NULL) {
        o = TOCapsuleMachine01__ct((u8 *)o, (s32)arg0);
    }
    return o;
}

void TOCapsuleMachine01::reset_static_state() {
    TOCapsuleMachine01__last_update_frame_tick = 0;
    lbl_805D58C4 = 0;
    if ((void *) TOCapsuleMachine01__model_resource != NULL) {
        TLobby__sub_8001FE7C(TOCapsuleMachine01__model_resource, 1);
        TOCapsuleMachine01__model_resource = NULL;
    }
}

typedef struct RecoveredFields_8015A734_var_r4 RecoveredFields_8015A734_var_r4;
typedef struct RecoveredGlobal_8015A734_lbl_804AFF00 RecoveredGlobal_8015A734_lbl_804AFF00;
void TOCapsuleMachine01::alloc_and_load_resource() {
  int temp_r3;
  long long new_var2;
  int var_r4;
  void **new_var;
  temp_r3 = (new_var2 = (int)::operator new(0x440));
  var_r4 = temp_r3;
  if (var_r4 != 0)
  {
    var_r4 = (long) load_resource_from_descriptor((void *) temp_r3, 1, &bm_fs_obj_cap_moto_resource_descriptor.value, 0, 0, 0);
  }
  TOCapsuleMachine01__model_resource = (unsigned char *) ((void *) var_r4);
  new_var = (void **) (((s8 *) (*((void **) (((s8 *) (*((void **) (((s8 *) ((RecoveredFields_8015A734_var_r4 *) var_r4)->field_42C) + 8)))) + 0x2C)))) + 0x30);
  capsule_machine_ginja_mesh_handle = *((int *) (((s8 *) (*((void **) (((s8 *) (*((void **) (((s8 *) (*new_var)) + 0x2C)))) + 0x30)))) + 4));
  TOCapsuleMachine01__last_update_frame_tick = 0;
}

void *__dt__18TOCapsuleMachine01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TOCapsuleMachine01;
        free_collision_body_parts(arg0);
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        ((TUnk_804AFBF8 *)arg0)->destroy_key_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8015A814_lbl_804AFF10_size[sizeof(RecoveredGlobal_8015A814_lbl_804AFF10) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8015A814___vt__18TOCapsuleMachine01_size[sizeof(RecoveredGlobal_8015A814___vt__18TOCapsuleMachine01) == 0x3C ? 1 : -1];
u8 *TOCapsuleMachine01__ct(u8 *arg0, s32 arg1) {
    init_map_object_base(arg0, tl_05);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8015A814___vt__18TOCapsuleMachine01 *)&__vt__18TOCapsuleMachine01).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D2ED4;
    ((TOCapsuleMachine01 *)(arg0))->apply_object_set_data((void *)arg1);
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TOCapsuleMachine01__model_resource + 0x42C)) + 8);
    ((TOCapsuleMachine01 *)arg0)->texture_id = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TOCapsuleMachine01__model_resource + 0x42C)) + 0xC);
    ((TOCapsuleMachine01 *)arg0)->m_c0 = (f32) lbl_805DB380;
    *(f32 *)((s8 *)arg0 + 0xC4) = (f32) lbl_805DB384;
    ((TOCapsuleMachine01 *)arg0)->actorFlags = (s32) (((TOCapsuleMachine01 *)arg0)->actorFlags | 0x40000000);
    init_collision_body_parts(arg0, &capsule_machine01_collision_body.value, 1);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->reset_photon_effect();
    return arg0;
}

}
