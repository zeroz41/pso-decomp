#include "types.h"
#include "pso/object/TObjChip.h"
#include "pso/misc/TWindowKeyBoardHard_801FBA48.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/item/TObjContainerBase.h"
#include "pso/item/TObjContainerNoItem.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80188DC0_lbl_804B63BC {
    s32 value;
    u8 remaining[0x158];
};

struct RecoveredGlobal_80188DC0___vt__17TObjContainerBase {
    s32 value;
    u8 remaining[0x148];
};

struct RecoveredGlobal_801897A4_lbl_804B63BC {
    s32 value;
    u8 remaining[0x158];
};

struct RecoveredGlobal_801897A4___vt__18TObjContainerEnemy {
    s32 value;
    u8 remaining[0x148];
};

struct Spawn_8018990C {
    u8 pad0[0xC];
    u8 pos[0xC];
    u8 pad18[0x38 - 0x18];
    f32 f38;
    u8 pad3c[4];
    s32 f40;
    s32 f44;
    u8 pad48[4];
};

struct Obj_8018990C { u8 pad[0x38]; f32 x, y, z; u8 pad44[0x326 - 0x44]; s16 f326; };

extern const f32 lbl_805DBCF4;
extern "C" {
u32 init_collision_body_parts(void *, s32, s32);
u8 * init_container_base(void *, s32);
extern RecoveredGlobal_80188DC0_lbl_804B63BC forest_box_collision_body_parts;
extern s32 __vt__17TObjContainerBase[];
extern s32 lbl_805D32E8;
u8 *TObjContainerBase__ct(u8 *arg0, s32 arg1);
s32 get_container_param(int);
}
extern s32 lbl_805D5B7C;
void play_container_break_sound(s32 arg0);
extern "C" {
void *__nw__7TObjectFUl(int);
extern Spawn_8018990C *const lbl_805D5B80;
extern Spawn_8018990C *const lbl_805D5B84;
extern void *tl_05;
s32 scale_matrix(s32, f32, f32, f32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern u32 lbl_805D5B78;
extern const f32 lbl_805DBCFC;
void *__dt__17TObjContainerBaseFv(void *arg0, s16 arg1);
s32 free_collision_body_parts(void *);
s32 submit_cursor_candidate(void *, s32);
s32 __dl__7TObjectFPv(void *);

void TObjContainerBase::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->m_364 != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void *__dt__17TObjContainerBaseFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TObjContainerBase;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B6C24 *)arg0)->destroy_container_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80188DC0_lbl_804B63BC_size[sizeof(RecoveredGlobal_80188DC0_lbl_804B63BC) == 0x15C ? 1 : -1];
typedef char RecoveredGlobal_80188DC0___vt__17TObjContainerBase_size[sizeof(RecoveredGlobal_80188DC0___vt__17TObjContainerBase) == 0x14C ? 1 : -1];
u8 *TObjContainerBase__ct(u8 *arg0, s32 arg1) {
    init_container_base(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80188DC0___vt__17TObjContainerBase *)&__vt__17TObjContainerBase).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D32E8;
    ((TObjContainerBase *)arg0)->mode = 0;
    ((TObjContainerBase *)arg0)->actorFlags = (s32) (((TObjContainerBase *)arg0)->actorFlags | 0x60000000);
    init_collision_body_parts(arg0, (s32) &forest_box_collision_body_parts.value, 1);
    ((TObjPlayer *)arg0)->reset_photon_effect();
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x78) = (f32) (*(f32 *)((s8 *)arg0 + 0x78) + *(f32 *)((s8 *)&forest_box_collision_body_parts.value + 4));
    return arg0;
}

void TObjContainerNoItem::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            this->vfunc_79();
            ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 1);
            ((TUnk_804AF8A0 *)arg0)->set_flag8();
            queue_destruction__7TObjectFv((arg0));
            this->mode = 1;
        }
    } else if ((s16) *arg1 == 1) {
        ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 1);
        ((TUnk_804AF8A0 *)arg0)->set_flag8();
        queue_destruction__7TObjectFv((arg0));
        this->mode = 1;
    }
}

typedef char RecoveredGlobal_801897A4_lbl_804B63BC_size[sizeof(RecoveredGlobal_801897A4_lbl_804B63BC) == 0x15C ? 1 : -1];
typedef char RecoveredGlobal_801897A4___vt__18TObjContainerEnemy_size[sizeof(RecoveredGlobal_801897A4___vt__18TObjContainerEnemy) == 0x14C ? 1 : -1];
void TObjContainerNoItem::vfunc_79() {
    Obj_8018990C *self = (Obj_8018990C *)this;
    void *o;
    if (this->mode != 1) {
        Spawn_8018990C a = *lbl_805D5B80;
        Spawn_8018990C b = *lbl_805D5B84;
        VecCopy((Vec *)a.pos, (const Vec *)&self->x);
        a.f38 = self->y;
        a.f40 = get_container_param(2);
        a.f44 = lbl_805D5B7C;
        VecCopy((Vec *)b.pos, (const Vec *)&self->x);
        b.f38 = self->y;
        b.f40 = get_container_param(0);
        b.f44 = lbl_805D5B7C;
        spawn_particle_effect_with_flags(&self->x, 0x45, 0x40);
        spawn_particle_effect_with_flags(&self->x, 0x46, 0x40);
        o = __nw__7TObjectFUl(0x234);
        if (o != NULL) {
            construct_debris__8TObjChipFPvPvPv((u8 *)o, (u8 *)tl_05, (u8 *)&a);
        }
        o = __nw__7TObjectFUl(0x234);
        if (o != NULL) {
            construct_debris__8TObjChipFPvPvPv((u8 *)o, (u8 *)tl_05, (u8 *)&b);
        }
        play_container_break_sound((s32)self);
    }
}

f32 TObjContainerNoItem::receive_physical_attack(void *, f32) {
    u8 *arg0 = (u8 *)this;
    s16 sp8;
    if (((u16) this->entity_id >= 0x1000U) && ((u32) *(u32 *)((s8 *)arg0 + 0x80) != 0U) && (((TUnk_804AF8A0 *)arg0)->access_object_saved_state(&sp8, 1) != 0)) {
        sp8 = 1;
        ((TUnk_804AF8A0 *)arg0)->access_object_saved_state(&sp8, 0);
        ((TUnk_804AF8A0 *)arg0)->send_object_state_update(&sp8);
    }
    return lbl_805DBCF4;
}
void TObjContainerNoItem::vfunc_81() {
    u8 *arg0 = (u8 *)this;
    if (lbl_805D5B78 != 0U) {
        switch (this->mode) {
        case 1:
            break;
        case 0:
        TObjFish::set_global_param(lbl_805D5B7C);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        scale_matrix(0, lbl_805DBCFC, lbl_805DBCFC, lbl_805DBCFC);
        draw_ginja_box_tree((u8 *)(*(s32 *)((s8 *)arg0 + 0x34)));
        pop_matrix();
            break;
        }
    }
}
}
