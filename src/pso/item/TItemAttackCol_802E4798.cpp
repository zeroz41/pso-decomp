#include "types.h"
#include "pso/item/TItemAttackCol_802E4798.h"
#include "pso/object/TObjMotion.h"
#include "pso/item/TUnk_804E355C.h"
#include "pso/item/TItemAttackCol.h"
#include "pso/object/TObjOnlineEnding.h"
#include "pso/player/TObjPlayer.h"

struct Hit_802E4798 { u8 *obj; s32 idx; };

struct Rec_802E4798 { u8 pad[0x18]; s32 flags; u8 pad2[0x2C - 0x1C]; };

extern "C" {
s32 obj_is_hit_receivable(void *);
s32 obj_testFlags30__14TObjCollidableFUl(void *, u32);
u16 get_entity_id(void *);
s32 is_technique_ready__8TTecCtrlFv();
void queue_destruction__7TObjectFv(void *arg0);
void TObjPlayer__sub_801542F4(s32 a);
void TObjPlayer__sub_8015431C(u8 *arg0);
void reset_global_table(void);
Hit_802E4798 *get_attack_entry__16TObjOnlineEndingFi(int);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

s32 TUnk_804E355C::try_add_hit_target(void *arg1_arg) {
    Hit_802E4798 *arg1 = (Hit_802E4798 *)arg1_arg;
    s32 ok;
    Hit_802E4798 *e;
    s32 i;
    s32 flags;
    u8 *arg0 = (u8 *)this;
    if (((TUnk_804E355C *)arg0)->m_a0 >= 8) {
        return 0;
    }
    if (((TUnk_804E355C *)arg0)->m_a8 == get_entity_id(arg1->obj)) {
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
        for (i = 0; i != ((TUnk_804E355C *)arg0)->m_a0; i++) {
            if (e->obj == arg1->obj && e->idx == arg1->idx) {
                return 0;
            }
            e++;
        }
        if (obj_is_hit_receivable(arg1->obj) != 0) {
            ((TItemAttackCol *)e)->copy_pos(arg1);
            ((TUnk_804E355C *)arg0)->m_a0 += 1;
            return 1;
        }
    }
    return 0;
}

void TItemAttackCol::copy_pos(void* q) { *(u32 *)&this->m_name = *(u32*)((char*)q + 0x0); *(u32 *)&this->m_flags = *(u32*)((char*)q + 0x4); }

extern s32 lbl_804E355C[];

void TUnk_804E355C::check_hits() {
    s32 i;
    Hit_802E4798 *e;
    u8 *arg0 = (u8 *)this;
    reset_global_table();
    TObjPlayer__sub_801542F4((s32)&this->unk_1C);
    if (*(s32 *)((s8 *)arg0 + 0xC0) != 0) {
        TObjPlayer__sub_8015431C((u8 *)&this->unk_1C);
    }
    if (((TUnk_804E355C *)arg0)->m_bc != 0) {
        TObjPlayer::apply_status_effect((s32)(arg0 + 0x1C));
    }
    for (i = 0; i != TObjOnlineEnding::get_instance(); i++) {
        e = get_attack_entry__16TObjOnlineEndingFi(i);
        if (((TUnk_804E355C *)arg0)->try_add_hit_target(e) != 0) {
            ((TUnk_804E355C *)arg0)->vfunc_6((s32 *)((s32)e));
            ((TUnk_804E355C *)arg0)->m_a4 -= 1;
            if (((TUnk_804E355C *)arg0)->m_a4 == 0) {
                queue_destruction__7TObjectFv(arg0);
                reset_global_table();
                return;
            }
        }
    }
    reset_global_table();
}

void *TUnk_804E355C::destroy_attack_collision(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804E355C;
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

}
