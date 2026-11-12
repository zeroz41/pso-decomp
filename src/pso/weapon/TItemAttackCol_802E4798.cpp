#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/weapon/TItemAttackCol_802E4798.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/item/TUnk_804E355C.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/object/ending/TObjOnlineEnding.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include <string.h>
#include "pso/system/task/TObject.h"

struct Hit_802E4798 { u8 *obj; s32 idx; };

struct Rec_802E4798 { u8 pad[0x18]; s32 flags; u8 pad2[0x2C - 0x1C]; };

extern "C" {
s32 obj_is_hit_receivable(void *);
s32 obj_testFlags30__14TObjCollidableFUl(void *, u32);
u16 get_entity_id(void *);
s32 is_technique_ready__8TTecCtrlFv();
s32 get_type__10TObjPlayerFPv(void *);
void TObjPlayer__sub_801542F4(s32 a);
void TObjPlayer__sub_8015431C(u8 *arg0);
void reset_global_table(void);
Hit_802E4798 *get_attack_entry__16TObjOnlineEndingFi(int);


s32 TUnk_804E355C::try_add_hit_target(void *arg1_arg) {
    Hit_802E4798 *arg1 = (Hit_802E4798 *)arg1_arg;
    s32 ok;
    Hit_802E4798 *e;
    s32 i;
    s32 flags;
    u8 *arg0 = (u8 *)this;
    if (((TUnk_804E355C *)arg0)->hit_count >= 8) {
        return 0;
    }
    if (((TUnk_804E355C *)arg0)->client_id == get_entity_id(arg1->obj)) {
        return 0;
    }
    ok = 1;
    if (is_technique_ready__8TTecCtrlFv() == 0 && obj_testFlags30__14TObjCollidableFUl(arg1->obj, 0x60000000) == 0x20000000
        && *(s16 *)((s8 *)arg0 + 0xAA) != ((TObjBase *)(arg1->obj))->get_room()) {
        ok = 0;
    }
    if (obj_testFlags30__14TObjCollidableFUl(arg1->obj, 0x04000000) != 0
        || ((flags = (*(Rec_802E4798 **)((s8 *)arg1->obj + 0xA4))[arg1->idx].flags) & 0x02000000)
        || (flags & 0x1000) || (flags & 0x80)) {
        ok = 0;
    }
    if (ok != 0) {
        e = (Hit_802E4798 *) (arg0 + 0x60);
        for (i = 0; i != ((TUnk_804E355C *)arg0)->hit_count; i++) {
            if (e->obj == arg1->obj && e->idx == arg1->idx) {
                return 0;
            }
            e++;
        }
        if (obj_is_hit_receivable(arg1->obj) != 0) {
            ((TItemAttackCol *)e)->copy_pos(arg1);
            ((TUnk_804E355C *)arg0)->hit_count += 1;
            return 1;
        }
    }
    return 0;
}

void TItemAttackCol::copy_pos(void* q) { *(u32 *)&this->m_name = *(u32*)((char*)q + 0x0); *(u32 *)&this->m_flags = *(u32*)((char*)q + 0x4); }


void TUnk_804E355C::check_hits() {
    s32 i;
    Hit_802E4798 *e;
    u8 *arg0 = (u8 *)this;
    reset_global_table();
    TObjPlayer__sub_801542F4((s32)&this->bodies);
    if (*(s32 *)((s8 *)arg0 + 0xC0) != 0) {
        TObjPlayer__sub_8015431C((u8 *)&this->bodies);
    }
    if (((TUnk_804E355C *)arg0)->pad_BC != 0) {
        TObjPlayer::apply_status_effect((s32)(arg0 + 0x1C));
    }
    for (i = 0; i != TObjOnlineEnding::get_instance(); i++) {
        e = get_attack_entry__16TObjOnlineEndingFi(i);
        if (((TUnk_804E355C *)arg0)->try_add_hit_target(e) != 0) {
            ((TUnk_804E355C *)arg0)->vfunc_6((s32 *)((s32)e));
            ((TUnk_804E355C *)arg0)->hits_left -= 1;
            if (((TUnk_804E355C *)arg0)->hits_left == 0) {
                ((TObject *)arg0)->queue_destruction();
                reset_global_table();
                return;
            }
        }
    }
    reset_global_table();
}

// ~TUnk_804E355C (vtable slot 2 of __vt__13TUnk_804E355C). Kept as a C body: a C++
// definition makes this file emit the vtable, and the original has it at 0x804E355C,
// 4-aligned right after __vt__14TItemAttackCol, i.e. in one translation unit with
// TItemAttackCol.cpp that the split still cuts in three (TItemAttackCol is unlinked).
extern "C" {
extern void *__vt__13TUnk_804E355C[];
void __dt__7TObjectFv(void *self, s16 flags);
void __dl__7TObjectFPv(void *p);

TUnk_804E355C *__dt__13TUnk_804E355CFv(TUnk_804E355C *self, s16 flags) {
    if (self != NULL) {
        *(void ***)((u8 *)self + 0x18) = __vt__13TUnk_804E355C;
        __dt__7TObjectFv(self, 0);
        if (flags > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
}

}

// 0.0f, shared with the TItemAttackCol unit's literal pool.
extern "C" const f32 lbl_805DE914;



TUnk_804E355C::TUnk_804E355C(TObject *parent, S_802E451C *params) : TObject(parent) {
    TObjPlayer *player;
    body.offset.x = lbl_805DE914;
    body.offset.y = lbl_805DE914;
    body.offset.z = lbl_805DE914;
    body.radius = params->radius;
    body.half_width = lbl_805DE914;
    body.shape = 0;
    body.flags = 0x41F07;
    body.center.x = lbl_805DE914;
    body.center.y = lbl_805DE914;
    body.center.z = lbl_805DE914;
    body.unk_28 = lbl_805DE914;
    bodies = &body;
    body_count = 1;
    VecCopy(&position, &params->position);
    memset(hits, 0, sizeof(hits));
    hit_count = 0;
    hits_left = params->hits;
    client_id = params->client_id;
    room = params->room;
    item_id = params->item_id;
    pad_B0 = params->pad_1C;
    pad_B4 = params->pad_20;
    pad_B8 = params->pad_24;
    pad_C0 = 1;
    player = get_player_by_client_id(params->client_id);
    if (player != NULL) {
        if (get_type__10TObjPlayerFPv(&player->m_828) != 0) {
            pad_BC = 1;
        } else {
            pad_BC = 0;
        }
    } else {
        pad_BC = 0;
    }
}
