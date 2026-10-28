#include "types.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjTank.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
extern "C" void *__ct__14TObjCollidableFP7TObject(void *, s32);

struct RecoveredGlobal_8019A9B8_lbl_80446184 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8019A9B8_lbl_804B8F60 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8019A880_lbl_804B8F70 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8019A880___vt__8TObjTank {
    s32 value;
    u8 remaining[0x38];
};

extern "C" {
s32 get_bml_model(s32, s32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 post_translate_matrix(void *);
s32 draw_ginja_object();
extern u32 tank_bml_resource;
extern u32 TObjTank__texture_list;
extern const f32 lbl_805DBFA0;
extern const f32 lbl_805DBFA4;
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8019A9B8_lbl_80446184 lbl_80446184;
extern RecoveredGlobal_8019A9B8_lbl_804B8F60 fs_obj_tank_resource_descriptor;
s32 init_collision_body_parts(void *, void *, int);
extern RecoveredGlobal_8019A880_lbl_804B8F70 tobjtank_collision_body_parts;
extern s32 __vt__8TObjTank[];
extern s32 TObjTank__class_name;
void TLobby__sub_8001FE7C(void*, int);
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
    if ((((VObj *)arg0)->m8(lbl_805DBFA0, lbl_805DBFA4) != 0) && (p = (*(void * *)&TObjTank__texture_list))) {
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

void *__dt__8TObjTankFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__8TObjTank;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__14TObjCollidableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_05;

typedef char RecoveredGlobal_8019A880_lbl_804B8F70_size[sizeof(RecoveredGlobal_8019A880_lbl_804B8F70) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8019A880___vt__8TObjTank_size[sizeof(RecoveredGlobal_8019A880___vt__8TObjTank) == 0x3C ? 1 : -1];
u8 *TObjTank__ct(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__14TObjCollidableFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8019A880___vt__8TObjTank *)&__vt__8TObjTank).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjTank__class_name;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg2 + 0xC));
    ((TObjPlayer *)(arg0 + 0x5C))->copy_xyz((void *)(arg2 + 0x18));
    VecCopy((Vec *)(arg0 + 0x68), (const Vec *)(arg2 + 0x24));
    init_collision_body_parts(arg0, &tobjtank_collision_body_parts.value, 1);
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
        TLobby__sub_8001FE7C((void*)tank_bml_resource, 1);
        tank_bml_resource = 0U;
    }
}
typedef char RecoveredGlobal_8019A9B8_lbl_80446184_size[sizeof(RecoveredGlobal_8019A9B8_lbl_80446184) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_8019A9B8_lbl_804B8F60_size[sizeof(RecoveredGlobal_8019A9B8_lbl_804B8F60) == 0x10 ? 1 : -1];
void TObjTank::load_globals() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &fs_obj_tank_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&tank_bml_resource) = var_r0;
    (*(u8 * *)&TObjTank__texture_list) = load_gvm_texture_file((s32) &lbl_80446184.value);
}

}
