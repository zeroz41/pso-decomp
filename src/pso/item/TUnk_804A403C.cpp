#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/item/TUnk_804A403C.h"
#include "pso/item/SpecialProjectileWeapons.h"
#include "pso/player/TObjPlayer_80128A70.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_80128CE8.h"
#include "pso/TAdRicoRing.h"
#include "pso/TItemAttacker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80128E80.h"
#include "pso/unk/text_80120908.h"
#include "pso/item/TItemEquipVariant_8012A82C.h"
#include "pso/item/TItem.h"

struct Obj_80128E08 { u8 pad[0x184]; void *f184; void *f188; u8 pad2[0x1fc - 0x18c]; u8 f1fc[4]; };

struct VBase_18 { char pad[0x18]; };

struct VObj_18 : VBase_18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual s32 m49(void *, s32, s32, s32);
};

extern "C" {
s32 test_flags_any(void *p, s32 n);
void clear_rico_ring_flag__10TObjPlayerFv(u32);

void TUnk_804A403C::emit_marker_effects() {
    s32 temp_r31;
    s32 var_r30;
    u32 temp_r3;
    u8 *arg0 = (u8 *)this;
    TObjPlayer__sub_80128A70();
    temp_r3 = *(u32 *)((s8 *)arg0 + 0xF0);
    if (temp_r3 == 0U) return;
    temp_r31 = temp_r3 + 0x7CC;
    if (get_burst_counter((void *)temp_r31) == 0) {
        var_r30 = 0;
        do {
            increment_burst_counter((u8 *)temp_r31);
            var_r30 += 1;
        } while (var_r30 != 2);
        ((FlagWord *)(arg0 + 0x1FC))->set(2);
        TItemAttacker::spawn_item_timer((TObject *)arg0, (ItemTimerCallback)clear_rico_ring_flag__10TObjPlayerFv, 0x3C);
        ((FlagWord *)(arg0 + 0x1FC))->set(4);
        if (((VObj_18 *)(arg0))->m49(arg0 + 0x200, 0, 0, 1) == 1) {
            ((FlagWord *)(arg0 + 0x1FC))->clear(4);
            ((VObj_18 *)(arg0))->m49(arg0 + 0x20C, 0, 0, 0);
            return;
        }
        ((FlagWord *)(arg0 + 0x1FC))->clear(4);
        ((VObj_18 *)(arg0))->m49(arg0 + 0x20C, 0, 0, 1);
    }
}

void TUnk_804A403C::vfunc_60() {
    void *p;
    Obj_80128E08 *self = (Obj_80128E08 *)this;
    switch (TObjPlayer::get_player_list()) {
    case 1:
        if (test_flags_any(self->f1fc, 2) == 0) {
            if (test_flags_any(self->f1fc, 1)) {
                p = self->f188;
            } else {
                p = self->f184;
            }
            if (p) {
                draw_ginja_object(p);
            }
        }
        break;
    }
}

}

void TUnk_804A403C::reserved_53() {
    s32 temp_r31;
    u8 *arg0 = (u8 *)this;

    temp_r31 = *(s32 *)((s8 *)arg0 + 0xF4);
    ((FlagWord *)(arg0 + 0x1FC))->set(1);
    draw_weapon_at_joint((s32)arg0, 0x30);
    ((TItemWeapon *)arg0)->get_joint_position(1, (arg0 + 0x200));
    *(s32 *)((s8 *)arg0 + 0xF4) = (s32) *(s32 *)((s8 *)arg0 + 0x180);
    ((FlagWord *)(arg0 + 0x1FC))->clear(1);
    draw_weapon_at_joint((s32)arg0, 0x23);
    ((TItemWeapon *)arg0)->get_joint_position(1, (arg0 + 0x20C));
    *(s32 *)((s8 *)arg0 + 0xF4) = temp_r31;
}

extern s32 lbl_804A403C[];

void *__dt__13TUnk_804A403CFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A403C;
        __dt__13TUnk_804A4948Fv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

void construct_srank_weapon(void *);

extern s32 notify_hit_target__10TObjPlayerFUlUlUlUl[];
extern s32 TObjPlayer__sub_80128A74[];
extern s32 spawn_shot_effect__10TObjPlayerFlllf[];
struct VOff_80128F60_arg0_80128f60 { char pad_0[0x1FC]; char f_1FC[1]; };

void *TUnk_804A403C::init_event_callbacks() {
    struct VOff_80128F60_arg0_80128f60 *self = (struct VOff_80128F60_arg0_80128f60 *)this;
    construct_srank_weapon(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A403C;
    __ct__8FlagWordFv((self->f_1FC));
    ((FlagWord *)((char *)this + 376))->set(32);
    ((TItemWeapon *)this)->set_weapon_flags(515);
    (*(s32 * *)((u8 *)this + 0x1EC)) = notify_hit_target__10TObjPlayerFUlUlUlUl;
    (*(s32 * *)((u8 *)this + 0x1F4)) = TObjPlayer__sub_80128A74;
    *(s32 **)((s8 *)this + 0x1F0) = spawn_shot_effect__10TObjPlayerFlllf;
    *(f32 *)&(*(float *)((u8 *)this + 0x1E4)) = 10.0f;
    ((FlagWord *)(self->f_1FC))->reset();
    return this;
}

}

extern "C" {
u8 * init_event_callbacks__13TUnk_804A403CFv(void *, s32, s32);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_event_callbacks_state(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x218));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_event_callbacks__13TUnk_804A403CFv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
