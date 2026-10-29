#include "types.h"
#include "pso/object/TObjChip.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/item/TObjContainerAbeEnemy.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/item/TObjContainerBase.h"
#include "pso/item/TObjContainerItem.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_801889B8_lbl_804B63BC {
    s32 value;
    u8 remaining[0x158];
};

struct RecoveredGlobal_801889B8___vt__21TObjContainerAbeEnemy {
    s32 value;
    u8 remaining[0x148];
};

struct Obj_80188C8C { u8 pad0[0x38]; u8 pos[0x28]; s32 id; u8 pad1[0x326 - 0x64]; s16 state; };

struct Spawn_80188B3C {
    u8 pad0[0xC];
    f32 x, y, z;
    u8 pad18[0x38 - 0x18];
    f32 f38;
    u8 pad3c[4];
    s32 f40;
    s32 f44;
    u8 pad48[4];
};

struct Obj_80188B3C { u8 pad[0x38]; f32 x, y, z; };

extern "C" {
u32 init_collision_body_parts(void *, s32, s32);
u8 * init_container_base(void *, s32);
extern RecoveredGlobal_801889B8_lbl_804B63BC forest_box_collision_body_parts;
extern s32 __vt__21TObjContainerAbeEnemy[];
extern s32 TObjContainerAbeEnemy__name;
u8 *TObjContainerAbeEnemy__ct(u8 *arg0, s32 arg1);
s32 push_matrix();
s32 post_translate_matrix(void *);
s32 rotate_matrix_y(s32, s32);
void dispatch_fish_event__6TLobbyFPv(void *a0);
void draw_ginja_box_tree(void);
extern void *container_breakup_model_archive;
extern s32 lbl_805D5B8C;
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
}
void play_container_break_sound(s32 arg0);
extern "C" {
void *__nw__7TObjectFUl(int);
extern Spawn_80188B3C container_break_particle_parameters;
extern Spawn_80188B3C container_break_small_debris_parameters;
extern void *tl_05;
void TObjContainerBase__vt77(const Obj_80188B3C *self);
void *TObjContainerBase__create(void *arg0);
void *__dt__21TObjContainerAbeEnemyFv(void *arg0, s16 arg1);
void *TObjContainerBase__ct(void *, void *, void *);
s32 free_collision_body_parts(void *);
s32 submit_cursor_candidate(void *, s32);
s32 __dl__7TObjectFPv(void *);

void TObjContainerAbeEnemy::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->m_364 != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void *__dt__21TObjContainerAbeEnemyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__21TObjContainerAbeEnemy;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B6C24 *)arg0)->destroy_container_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_801889B8_lbl_804B63BC_size[sizeof(RecoveredGlobal_801889B8_lbl_804B63BC) == 0x15C ? 1 : -1];
typedef char RecoveredGlobal_801889B8___vt__21TObjContainerAbeEnemy_size[sizeof(RecoveredGlobal_801889B8___vt__21TObjContainerAbeEnemy) == 0x14C ? 1 : -1];
u8 *TObjContainerAbeEnemy__ct(u8 *arg0, s32 arg1) {
    init_container_base(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_801889B8___vt__21TObjContainerAbeEnemy *)&__vt__21TObjContainerAbeEnemy).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjContainerAbeEnemy__name;
    ((TObjContainerAbeEnemy *)arg0)->mode = 0;
    ((TObjContainerAbeEnemy *)arg0)->actorFlags = (s32) (((TObjContainerAbeEnemy *)arg0)->actorFlags | 0x60000000);
    init_collision_body_parts(arg0, (s32) &forest_box_collision_body_parts.value, 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x78) = (f32) (*(f32 *)((s8 *)arg0 + 0x78) + *(f32 *)((s8 *)&forest_box_collision_body_parts.value + 4));
    return arg0;
}

void *TObjContainerBase__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x368);
    if (o != NULL) {
        o = TObjContainerBase__ct(o, tl_05, arg0);
    }
    return o;
}
void TObjContainerBase::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            this->vfunc_79();
            ((TUnk_804B6C24 *)arg0)->spawn_item((s32)arg0);
            ((TObjCollidable *)arg0)->set_flag8();
            queue_destruction__7TObjectFv((arg0));
            this->mode = 1;
        }
    } else if ((s16) *arg1 == 1) {
        ((TObjCollidable *)arg0)->set_flag8();
        queue_destruction__7TObjectFv((arg0));
        this->mode = 1;
    }
}

#pragma push
#pragma opt_propagation off
void TObjContainerBase__vt77(const Obj_80188B3C *self) {
    Spawn_80188B3C a = container_break_particle_parameters;
    f32 za;
    f32 ya;
    f32 xa;
    xa = self->x;
    ya = self->y;
    za = self->z;
    a.x = xa;
    a.y = ya;
    a.z = za;
    a.f38 = ya;
    a.f40 = ((s32 (*)(void *))dispatch_fish_event__6TLobbyFPv)((void *)0);
    a.f44 = lbl_805D5B8C;
    Spawn_80188B3C b = container_break_small_debris_parameters;
    f32 zb;
    f32 yb;
    f32 xb;
    xb = self->x;
    yb = self->y;
    zb = self->z;
    b.x = xb;
    b.y = yb;
    b.z = zb;
    b.f38 = yb;
    b.f40 = ((s32 (*)(void *))dispatch_fish_event__6TLobbyFPv)((void *)1);
    b.f44 = lbl_805D5B8C;
    spawn_particle_effect_with_flags((void *)&self->x, 0x45, 0x40);
    spawn_particle_effect_with_flags((void *)&self->x, 0x46, 0x40);
    void *o = __nw__7TObjectFUl(0x234);
    if (o != NULL) {
        __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&a);
    }
    o = __nw__7TObjectFUl(0x234);
    if (o != NULL) {
        __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&b);
    }
    play_container_break_sound((s32)self);
}
#pragma pop

void TObjContainerBase::vfunc_81() {
    Obj_80188C8C *self = (Obj_80188C8C *)this;
    if (container_breakup_model_archive != 0) {
        switch (this->mode) {
        case 0:
            TObjFish::set_global_param(lbl_805D5B8C);
            push_matrix();
            post_translate_matrix(self->pos);
            rotate_matrix_y(0, this->rotation_y);
            dispatch_fish_event__6TLobbyFPv((void *)2);
            draw_ginja_box_tree();
            pop_matrix();
            break;
        case 1:
            break;
        }
    }
}
}
