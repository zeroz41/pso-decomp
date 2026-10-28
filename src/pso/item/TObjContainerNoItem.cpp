#include "types.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/item/TObjContainerEnemy.h"
#include "pso/item/TObjContainerNoItem.h"
#include "pso/misc/TLobby.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8018925C_lbl_804B63BC {
    s32 value;
    u8 remaining[0x158];
};

struct RecoveredGlobal_8018925C___vt__19TObjContainerNoItem {
    s32 value;
    u8 remaining[0x148];
};

struct Obj_801895A4 { u8 pad0[0x38]; u8 pos[0x4c]; s32 id; };

struct Obj_801894F8 { u8 pad0[0x1C]; u16 f1C; u8 pad1[0x62]; u32 f80; s32 f84; };

struct Pkt_801894F8 { u16 a; u16 b; s32 c; s32 d; s32 e; };

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

struct CE_80189614 { u8 pad[0x34]; s32 f34; u8 f38[0x28]; s32 f60; u8 pad2[0x326 - 0x64]; s16 mode; };

extern "C" {
void queue_destruction__7TObjectFv(void *arg0);
s32 init_collision_body_parts(void *, void *, int);
u8 *init_container_base(u8 *arg0, s32 arg1, s32 arg2);
s32 get_container_param(int);
extern RecoveredGlobal_8018925C_lbl_804B63BC forest_box_collision_body_parts;
extern s32 __vt__19TObjContainerNoItem[];
extern s32 TObjContainerNoItem__name;
u8 *TObjContainerNoItem__ct(u8 *arg0, s32 arg1, s32 arg2);
void debug_printf_at(s32 id, const char *fmt, ...);
void TObjRoomId__sub_80141CF4(void *dst, void *src, f32 t);
extern char lbl_80444EF4[];
extern u8 lbl_804A7448[];
extern const f32 lbl_805DBCF8;
s32 get_current_floor();
extern s32 local_client_id;
extern const f32 lbl_805DBCF4;
extern s32 lbl_805D5B7C;
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
u8 *construct_debris__8TObjChipFPvPvPv(u8 *arg0, u8 *arg1, u8 *arg2);
}
void play_container_break_sound(s32 arg0);
extern "C" {
void *__nw__7TObjectFUl(int);
extern Spawn_8018990C *const lbl_805D5B80;
extern Spawn_8018990C *const lbl_805D5B84;
extern void *tl_05;
void draw_ginja_box_tree(u8 *arg0);
void scale_matrix(s32, f32, f32, f32);
void rotate_matrix_y(s32, s32);
void push_matrix(void);
s32 pop_matrix(void);
void post_translate_matrix(void *);
extern u32 lbl_805D5B78;
extern const f32 lbl_805DBCFC;
void *__dt__19TObjContainerNoItemFv(void *arg0, s16 arg1);
s32 free_collision_body_parts(void *);
s32 submit_cursor_candidate(void *, s32);
s32 __dl__7TObjectFPv(void *);

void TObjContainerNoItem::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->m_364 != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void *TObjContainerNoItem::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x368);
    if (o != NULL) {
        o = TObjContainerNoItem__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void *__dt__19TObjContainerNoItemFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TObjContainerNoItem;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B6C24 *)arg0)->destroy_container_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_8018925C_lbl_804B63BC_size[sizeof(RecoveredGlobal_8018925C_lbl_804B63BC) == 0x15C ? 1 : -1];
typedef char RecoveredGlobal_8018925C___vt__19TObjContainerNoItem_size[sizeof(RecoveredGlobal_8018925C___vt__19TObjContainerNoItem) == 0x14C ? 1 : -1];
u8 *TObjContainerNoItem__ct(u8 *arg0, s32 arg1, s32 arg2) {
    init_container_base((arg0), (arg1), (arg2));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8018925C___vt__19TObjContainerNoItem *)&__vt__19TObjContainerNoItem).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjContainerNoItem__name;
    *(s32 *)((s8 *)arg0 + 0x34) = get_container_param(1);
    ((TObjContainerNoItem *)arg0)->mode = 0;
    ((TObjContainerNoItem *)arg0)->actorFlags = (s32) (((TObjContainerNoItem *)arg0)->actorFlags | 0x60000000);
    init_collision_body_parts(arg0, (void *)&forest_box_collision_body_parts.value, 1);
    ((TObjPlayer *)arg0)->reset_photon_effect();
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x78) = (f32) (*(f32 *)((s8 *)arg0 + 0x78) + *(f32 *)((s8 *)&forest_box_collision_body_parts.value + 4));
    return arg0;
}

void TObjContainerEnemy::vfunc_6(s16 *arg1, s32 arg2) {
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
void TObjContainerEnemy::vfunc_79() {
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

f32 TObjContainerEnemy::receive_physical_attack(void *, f32) {
    Obj_801894F8 *arg0 = (Obj_801894F8 *)this;
    s16 sp8;
    Pkt_801894F8 pkt;
    if ((this->entity_id >= 0x1000U) && (arg0->f80 != 0U) && (((TUnk_804AF8A0 *)arg0)->access_object_saved_state(&sp8, 1) != 0)) {
        sp8 = 1;
        ((TUnk_804AF8A0 *)arg0)->access_object_saved_state(&sp8, 0);
        ((TUnk_804AF8A0 *)arg0)->send_object_state_update(&sp8);
        ((TLobby *)(&pkt))->init_packet_67_04();
        pkt.b = this->entity_id;
        pkt.c = get_current_floor();
        pkt.d = this->set_params[0];
        pkt.e = local_client_id;
        ((TLobby *)(&pkt))->byteswap_and_send();
    }
    return lbl_805DBCF4;
}

void TObjContainerEnemy::debug_print_item_box_info() {
    Obj_801895A4 *self = (Obj_801895A4 *)this;
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, lbl_80444EF4, this->set_params[0]);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    TObjRoomId__sub_80141CF4(self->pos, lbl_804A7448, lbl_805DBCF8);
}
void TObjContainerEnemy::vfunc_81() {
    CE_80189614 *self = (CE_80189614 *)this;
    if (lbl_805D5B78 == 0) {
        return;
    }
    switch (self->mode) {
    case 0:
        TObjFish::set_global_param(lbl_805D5B7C);
        push_matrix();
        post_translate_matrix(self->f38);
        rotate_matrix_y(0, self->f60);
        scale_matrix(0, lbl_805DBCFC, lbl_805DBCFC, lbl_805DBCFC);
        draw_ginja_box_tree((u8 *)self->f34);
        pop_matrix();
        break;
    case 1:
        break;
    }
}
}
