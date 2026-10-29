#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjMapObject.h"
#include "pso/misc/TOCapsuleMachine01.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8015A814_lbl_804AFF10 {
    s32 value;
    u8 remaining[0x28];
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
extern RecoveredGlobal_8015A814_lbl_804AFF10 capsule_machine01_collision_body;
extern const char *lbl_805D2ED4;
extern void *tl_05;
extern const f32 lbl_805DB380;
extern const f32 lbl_805DB384;
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8015A734_lbl_804AFF00 bm_fs_obj_cap_moto_resource_descriptor;
extern s32 capsule_machine_ginja_mesh_handle;

s32 PPCSync();
s32 scroll_ginja_mesh_uvs(s32, s32, s32, s32, s32);
s32 post_translate_matrix(void *);
s32 free_collision_body_parts(void *);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();

extern s32 actor_frame_tick;
}

void TOCapsuleMachine01::run_task() {
    if ((s32) TOCapsuleMachine01__last_update_frame_tick != (s32) actor_frame_tick) {
        TOCapsuleMachine01__last_update_frame_tick = actor_frame_tick;
        scroll_ginja_mesh_uvs(capsule_machine_ginja_mesh_handle, 0, 5, 4, 1);
        PPCSync();
    }
}

void TOCapsuleMachine01::render() {
    if (update_object_view_visibility(m_c0, model_radius) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        draw_ginja_object((void *)(*(s32 *)&this->model));
        pop_matrix();
    }
}

void *TOCapsuleMachine01::create(void *arg0) {
    return new TOCapsuleMachine01(arg0);
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

// The destructor is still written out by hand: compiled, its vtable would
// open the unit's .data, which the original fills first with the object's
// resource and collision tables (not owned by this unit yet).
extern "C" {
extern void *__vt__18TOCapsuleMachine01[];
void __dl__7TObjectFPv(void *);

void *__dt__18TOCapsuleMachine01Fv(void *self, s16 del) {
    if (self != NULL) {
        *(void **)((u8 *)self + 0x18) = __vt__18TOCapsuleMachine01;
        free_collision_body_parts((TOCapsuleMachine01 *)self);
        ((TOCapsuleMachine01 *)self)->unregister_object_by_id();
        __dt__13TObjMapObjectFv(self, 0);
        if (del > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
}

typedef char RecoveredGlobal_8015A814_lbl_804AFF10_size[sizeof(RecoveredGlobal_8015A814_lbl_804AFF10) == 0x2C ? 1 : -1];

TOCapsuleMachine01::TOCapsuleMachine01(void *set_data) : TObjMapObject((TObject *)tl_05) {
    m_name = lbl_805D2ED4;
    apply_object_set_data(set_data);
    model = (void *)*(s32 *)((s8 *)(*(u8 **)((s8 *)TOCapsuleMachine01__model_resource + 0x42C)) + 8);
    texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TOCapsuleMachine01__model_resource + 0x42C)) + 0xC);
    m_c0 = lbl_805DB380;
    model_radius = lbl_805DB384;
    actorFlags |= 0x40000000;
    init_collision_body_parts(this, &capsule_machine01_collision_body.value, 1);
    refresh_collision_body_centers();
    register_object_by_id();
}
