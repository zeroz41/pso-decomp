#include "types.h"
#include "pso/object/TObjTank.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/TObjTank.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/BmlResourceDescriptor.h"
extern "C" void *__ct__14TObjCollidableFP7TObject(void *, s32);

__declspec(section ".data") const char *fs_obj_tank_model_names[2] = { "fs_obj_tank.gj", NULL };
const char *fs_obj_tank_motion_names[1] = { NULL };
BmlResourceDescriptor fs_obj_tank_resource_descriptor = {
    "fs_obj_tank.bml", fs_obj_tank_model_names, fs_obj_tank_motion_names, 1, 0
};
const char *TObjTank__class_name = "TObjTank";

CollisionBody tobjtank_collision_body_parts = {{0.0f, 0.0f, 0.0f}, 20.0f, 10.0f, 0, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};

struct RecoveredGlobal_8019A880___vt__8TObjTank {
    s32 value;
    u8 remaining[0x38];
};

extern "C" {
s32 get_bml_model(s32, s32);
s32 push_matrix();
s32 post_translate_matrix(void *);
s32 draw_ginja_object();
extern u32 tank_bml_resource;
extern u32 TObjTank__texture_list;
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
s32 init_collision_body_parts(void *, void *, int);
extern s32 __vt__8TObjTank[];
void free_bin_model_request(void*, int);
s32 release_texture_list(void*);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

struct Base { char pad[0x18]; };
struct VObj : Base {
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
void TObjTank::render() {
    u8 *arg0 = (u8 *)this;
    void *p;
    if ((((VObj *)arg0)->m8(400.0f, 20.0f) != 0) && (p = (*(void * *)&TObjTank__texture_list))) {
        TObjFish::set_global_param((u32)p);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        get_bml_model((*(s32 *)&tank_bml_resource), 0);
        draw_ginja_object();
        pop_matrix();
    }
}

void TObjTank::run_task() {  }

}
TObjTank::~TObjTank() {
    ((TObjCollidable *)this)->unregister_object_by_id();
    free_collision_body_parts(this);
}
extern "C" {

extern void *tl_05;

typedef char RecoveredGlobal_8019A880___vt__8TObjTank_size[sizeof(RecoveredGlobal_8019A880___vt__8TObjTank) == 0x3C ? 1 : -1];
u8 *TObjTank__ct(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__14TObjCollidableFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8019A880___vt__8TObjTank *)&__vt__8TObjTank).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjTank__class_name;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg2 + 0xC));
    copy_xyz(arg0 + 0x5C, (void *)(arg2 + 0x18));
    VecCopy((Vec *)(arg0 + 0x68), (const Vec *)(arg2 + 0x24));
    init_collision_body_parts(arg0, &tobjtank_collision_body_parts, 1);
    ((TObjTank *)arg0)->actorFlags = (s32) (((TObjTank *)arg0)->actorFlags | 0x40000000);
    ((TObjPlayer *)arg0)->register_object_by_id();
    return arg0;
}

void *TObjTank__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xAC);
    if (o != NULL) {
        o = TObjTank__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TObjTank::free_globals() {
    if ((u32) TObjTank__texture_list != 0U) {
        release_texture_list((void*)TObjTank__texture_list);
        TAdSinglePlyChrSelectGC::safe_free(TObjTank__texture_list);
        TObjTank__texture_list = 0U;
    }
    if ((u32) tank_bml_resource != 0U) {
        free_bin_model_request((void*)tank_bml_resource, 1);
        tank_bml_resource = 0U;
    }
}
void TObjTank::load_globals() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &fs_obj_tank_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&tank_bml_resource) = var_r0;
    (*(u8 * *)&TObjTank__texture_list) = load_gvm_texture_file((s32)"fs_obj_tank.GVM");
}

}
