#include "pso/item/TItemData.h"
#include "types.h"
#include "pso/item/TUnk_804C4498.h"
#include "pso/item/TUnk_804C4468.h"
#include "pso/system/vector.h"
#include "pso/item/TUnk_804C4480.h"
#include "pso/object/TObjMotion.h"

#include "pso/TItemList.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/item/TItem.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_801D401C_lbl_804C4498 { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_801D401C_lbl_804C4498_size[sizeof(RecoveredGlobal_801D401C_lbl_804C4498) == 0x18 ? 1 : -1];

struct RecoveredGlobal_801D39C8_lbl_804C4468 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_801D3BD4_lbl_804C4480 {
    s32 value;
    u8 remaining[0x14];
};

struct Vec_801D3E20 { f32 x, y, z; };

struct Body_801D3E20 { void *colliders; s32 count; Vec_801D3E20 position; s32 facing; };

struct Actor_801D3E20 {
    u8 pad[0x30];
    u32 flags;
    u8 pad34[4];
    Vec_801D3E20 pos;
    u8 pad44[0x1c];
    s32 facing;
    u8 pad64[0x40];
    void *colliders;
    s32 count;
};

struct Search_801D3F3C {
    u8 pad[0x1d];
    s8 ring;
    s8 sample;
    s8 count;
    u8 pad20[8];
    u32 heading;
    s32 step;
    u32 angle;
    f32 radius;
};

struct Req_801D3780 {
    u32 status;
    s32 source;
    u8 item[0xc];
    s32 id;
    s32 extra;
};

struct Shape_801D3C38 {
    u8 pad0[0xC];
    f32 radius;
    u8 pad10[4];
    s32 f14;
    s32 mask;
};

struct Ground_801D3C38 { u8 pad0[4]; Vec_801D3E20 *pos; };

struct Search_801D3C38 {
    u8 pad[0x1d];
    s8 ring;
    s8 sample;
    s8 count;
    u8 pad20[0xC];
    s32 step;
    s32 angle;
    f32 radius;
    Vec_801D3E20 origin;
    Vec_801D3E20 candidate;
    s32 online;
};

extern "C" {
u16 get_entity_id(void *);
void __ct__7TObjectFP7TObject(void *, void *);
s32 check_player_action_allowed(void);
s32 fn_801D4270(s32);
s32 load_character_from_card__23TAdSinglePlyChrSelectGCFv(void);
s32 queue_destruction__7TObjectFv(void *);
void remove_list_entry_by_id(s32 arg0);
void sub_801D5884__13TUnk_804C4498FUc(void *p, u8 v);
u8 *run_item_count_update__9TItemListFv(void *);
extern s32 item_drop_search_task_vtable[];
u8 *TItemList__sub_801D39C8(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4, s8 arg5);
extern s32 placement_search_task_vtable[];
int get_player_data__10TObjPlayerFi(int a0);
f32 horizontal_distance_squared(void *, void *);
void *refresh_actor_body_spheres(Body_801D3E20, Body_801D3E20);
extern const f32 lbl_805DC3D0;
void *find_placement_obstruction(void *self, Body_801D3E20 *s);
extern const f32 lbl_805DC3C8;
void TItemList__sub_801D59A0(void *, int);
void send_6x29_delete_item__10TObjPlayerFPvii(void *, s32, s32);
void *get_player_by_client_id(u16);
void *get_ptr_0x44__9TItemListFPv(void *);
s8 get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
s32 *csnVecterUnder(s32 origin, s32 mask);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern Shape_801D3C38 placement_search_collision_body;
extern Body_801D3E20 placement_search_collision_probe;
extern const f32 lbl_805DC3CC;
void * TItemList__sub_801D3B00(void *arg0, void *arg1, void *arg2, s8 arg3);
void *__dt__13TUnk_804C4480Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804C4498Fv(void *arg0, s16 arg1);
}
extern s32 __vt__13TUnk_804C4498[];
extern const f32 lbl_805DC3D4;
u8 *construct_placement_search_base(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, s8 arg4);
void decrement_placement_search_pending(void *p, void *a1);
void clear_placement_search_slot(TItemList *arg0, s32 arg1);
extern "C" {
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

extern void *tl_07;

void TUnk_804C4468::run_task() {
    Req_801D3780 *r;
    void *player;
    switch (this->step_placement_search()) {
    case 0:
        return;
    case 1:
        TItemList__sub_801D59A0(this, *(s32 *)(((u8 *)this) + 0x54));
        sub_801D591C();
        r = (Req_801D3780 *)run_item_count_update__9TItemListFv(this);
        player = get_player_by_client_id(get_client_id());
        if (player != NULL) {
            if (r->id == -1) {
                if (r->source == -1) {
                    ((void (*)(TItemData *, s32, f32 *))drop_stacked_item)((TItemData *)r->item, get_client_id(), (f32 *)get_ptr_0x44__9TItemListFPv(this));
                    send_6x29_delete_item__10TObjPlayerFPvii(player, r->source, r->extra);
                    TObjPlayer::send_code_45_1((s32)player);
                } else {
                    ((void (*)(TItemData *, s32, f32 *))drop_stacked_item)((TItemData *)r->item, get_client_id(), (f32 *)get_ptr_0x44__9TItemListFPv(this));
                    send_6x29_delete_item__10TObjPlayerFPvii(player, r->source, ((TItemData *)r->item)->get_stack_count());
                    TObjPlayer::send_code_45_1((s32)player);
                }
            } else {
                TObjPlayer::send_6x2A_drop_item(player, r->source, get_ptr_0x44__9TItemListFPv(this), ((TItemData *)r->item)->get_stack_count());
                TObjPlayer::send_code_45_1((s32)player);
            }
        }
        break;
    case 2:
        ((TItemList *)((u8 *)this))->lookup_entry_by_count(*(s32 *)(((u8 *)this) + 0x54));
        break;
    }
    queue_destruction__7TObjectFv(this);
}

void *TItemList::create_node(void *arg0, void *arg1, void *arg2, s8 arg3) {
    void *o;
    o = __nw__7TObjectFUl(0x58);
    if (o != NULL) {
        o = TItemList__sub_801D39C8((u8 *)o, (s32)tl_07, (s32)arg0, (u8 *)arg1, (s32)arg2, arg3);
    }
    return o;
}

void *TItemList::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = item_drop_search_task_vtable;
        clear_placement_search_slot((TItemList *)this, *(s32 *)((s8 *)this + 0x54));
        decrement_placement_search_pending(this, (void *)(*(s32 *)((s8 *)this + 0x54)));
        __dt__13TUnk_804C4498Fv(this, (s16)(0));
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

typedef char RecoveredGlobal_801D39C8_lbl_804C4468_size[sizeof(RecoveredGlobal_801D39C8_lbl_804C4468) == 0x18 ? 1 : -1];
u8 *TItemList__sub_801D39C8(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4, s8 arg5) {
    u8 *temp_r3;
    construct_placement_search_base((u8 *)arg0, (u8 *)arg1, (u8 *)arg3, (u8 *)arg4, arg5);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_801D39C8_lbl_804C4468 *)&item_drop_search_task_vtable).value;
    *(s32 *)((s8 *)arg0 + 0x54) = arg2;
    sub_801D5884__13TUnk_804C4498FUc((arg0), 1);
    ((TUnk_804C4498 *)arg0)->reset_placement_search_ring();
    if (check_player_action_allowed() != 0) {
        temp_r3 = (u8 *)(run_item_count_update__9TItemListFv(arg0));
        if (fn_801D4270(*(s32 *)((s8 *)temp_r3 + 4)) != 0) {
            remove_list_entry_by_id((*(s32 *)((s8 *)temp_r3 + 4)));
            if (load_character_from_card__23TAdSinglePlyChrSelectGCFv() != 0) {
                queue_destruction__7TObjectFv(arg0);
                return arg0;
            }
            *(s32 *)((s8 *)arg0 + 0x50) = 1;
            goto block_5;
        }
    }
block_5:
    return arg0;
}

void TUnk_804C4480::run_task() {
    switch (this->step_placement_search()) {
    case 0:
        return;
    case 1:
        TItemList__sub_801D59A0(this, *(s32 *)((s8 *)((u8 *)this) + 0x54));
        this->sub_801D5A70();
        break;
    case 2:
        ((TItemList *)((u8 *)this))->lookup_entry_by_count(*(s32 *)((s8 *)((u8 *)this) + 0x54));
        break;
    }
    queue_destruction__7TObjectFv(this);
}

void * TItemList__sub_801D3B00(void *arg0, void *arg1, void *arg2, s8 arg3) {
    void *o;
    o = __nw__7TObjectFUl(0x58);
    if (o != NULL) {
        o = ((TItemList *)o)->ct_init_placement_ring((u8 *)tl_07, (s32)arg0, (u8 *)arg1, (u8 *)arg2, arg3);
    }
    return o;
}

void *__dt__13TUnk_804C4480Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = placement_search_task_vtable;
        clear_placement_search_slot((TItemList *)((u8 *)arg0), *(s32 *)((s8 *)arg0 + 0x54));
        decrement_placement_search_pending(arg0, (void *)(*(s32 *)((s8 *)arg0 + 0x54)));
        __dt__13TUnk_804C4498Fv(arg0, (s16)(0));
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_801D3BD4_lbl_804C4480_size[sizeof(RecoveredGlobal_801D3BD4_lbl_804C4480) == 0x18 ? 1 : -1];
u8 *TItemList::ct_init_placement_ring(u8 *arg1, s32 arg2, u8 *arg3, u8 *arg4, s8 arg5) {
    construct_placement_search_base((u8 *)this, arg1, arg3, arg4, arg5);
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = &(*(RecoveredGlobal_801D3BD4_lbl_804C4480 *)&placement_search_task_vtable).value;
    *(s32 *)((s8 *)((u8 *)this) + 0x54) = arg2;
    sub_801D5884__13TUnk_804C4498FUc((this), (0U));
    ((TUnk_804C4498 *)((u8 *)this))->reset_placement_search_ring();
    return ((u8 *)this);
}

#pragma push
#pragma fp_contract on
s32 TUnk_804C4498::step_placement_search() {
    Search_801D3C38 *s = (Search_801D3C38 *)this;
    Ground_801D3C38 *g;
    if (check_player_action_allowed() != 0 && s->online != 0 &&
        TAdPlayerLoadGC::probe_card_slot(get_chr_select_state__23TAdSinglePlyChrSelectGCFv()) != 1) {
        TLobby::disconnect_protocol();
        queue_destruction__7TObjectFv(s);
        return 2;
    }
    if (s->ring > 5) {
        s->ring = 1;
        ((TUnk_804C4498 *)s)->reset_placement_search_ring();
        return 2;
    }
    if (s->sample >= s->count) {
        s->ring++;
        ((TUnk_804C4498 *)s)->reset_placement_search_ring();
    }
    s->candidate.x = s->radius * sin_table_lookup(s->angle) + s->origin.x;
    s->candidate.y = s->origin.y;
    s->candidate.z = s->radius * cos_table_lookup(s->angle) + s->origin.z;
    g = (Ground_801D3C38 *)csnVecterUnder((s32)&s->candidate, 0x41);
    if (g == NULL) {
        s->angle += s->step;
        s->sample++;
        return 0;
    }
    s->candidate.y = lbl_805DC3C8 + g->pos->y;
    placement_search_collision_body.radius = lbl_805DC3CC;
    placement_search_collision_body.f14 = 0;
    placement_search_collision_body.mask = 0x31F03;
    VecCopy((Vec *)&placement_search_collision_probe.position, (const Vec *)&s->candidate);
    if (find_placement_obstruction(s, &placement_search_collision_probe) != NULL) {
        s->angle += s->step;
        s->sample++;
        return 0;
    }
    if (check_player_action_allowed() != 0 && s->online != 0 &&
        TAdPlayerLoadGC__sub_801E1B50(get_chr_select_state__23TAdSinglePlyChrSelectGCFv()) != 0) {
        return 0;
    }
    return 1;
}
#pragma pop

void *find_placement_obstruction(void *self, Body_801D3E20 *s) {
    s32 end = TLobby::get_lobby_flag();
    s32 i;
    for (i = TLobby::get_game_mode() + TObjEneDD::get_enemy_count(); i < end; i++) {
        Actor_801D3E20 *a = (Actor_801D3E20 *)get_player_data__10TObjPlayerFi(i);
        if (a != 0 && a->colliders != 0 && !(a->flags & 0x800)) {
            if (lbl_805DC3D0 > horizontal_distance_squared(&s->position, &a->pos)) {
                Body_801D3E20 b;
                void *r;
                b.colliders = a->colliders;
                b.count = a->count;
                VecCopy((Vec *)&b.position, (const Vec *)&a->pos);
                b.facing = a->facing;
                r = refresh_actor_body_spheres(*s, b);
                if (r != 0) {
                    return r;
                }
            }
        }
    }
    return 0;
}

s32 TUnk_804C4498::reset_placement_search_ring() {
    Search_801D3F3C *s = (Search_801D3F3C *)this;
    s->sample = 0;
    if (s->ring == 0) {
        s->count = 1;
    } else {
        s->count = s->ring * 4;
    }
    s->step = 0x10000 / s->count;
    s->angle = s->heading;
    s->radius = lbl_805DC3C8 * s->ring;
}

}
TUnk_804C4498::~TUnk_804C4498() {

}
u8 *construct_placement_search_base(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, s8 arg4) {
    __ct__7TObjectFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_801D401C_lbl_804C4498 *)&__vt__13TUnk_804C4498).value;
    if (arg2 == NULL) {
        ((TUnk_804C4498 *)arg0)->m_20 = 0xFFFFU;
        ((TUnk_804C4498 *)arg0)->m_24 = 0;
        *(s32 *)((s8 *)arg0 + 0x28) = 0;
    } else {
        ((TUnk_804C4498 *)arg0)->m_20 = get_entity_id(arg2);
        ((TUnk_804C4498 *)arg0)->m_24 = (s32) ((TObjBase *)arg2)->get_room();
        *(s32 *)((s8 *)arg0 + 0x28) = (s32) ((TObjBase *)arg2)->rotation_y;
    }
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)arg3);
    *(s8 *)&((TUnk_804C4498 *)arg0)->unk_1C = arg4;
    ((TUnk_804C4498 *)arg0)->m_4c = (f32) lbl_805DC3D4;
    *(f32 *)((s8 *)arg0 + 0x48) = (f32) lbl_805DC3D4;
    ((TUnk_804C4498 *)arg0)->m_44 = (f32) lbl_805DC3D4;
    *(s32 *)((s8 *)arg0 + 0x50) = 0;
    return arg0;
}
