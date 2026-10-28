#include "types.h"
#include "pso/system/PadRumble.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/unk/text_80121180.h"
#include "pso/player/TObjPlayer.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TItem.h"

#include <stddef.h>
#include "pso/map/CurrentArea.h"
struct VBase_18_f8c4e0 { char pad[0x18]; };

struct VObj_18_f8c4e0 : VBase_18_f8c4e0 {
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
    virtual s32 m19(void *, s32, s32, f32);
    virtual f32 m20(void *, f32);
    virtual void m21();
    virtual s32 m22(void *, s32);
    virtual s32 m23(void *, f32);
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual s32 m33();
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
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual s32 m73();
};

struct Stack_8011F7CC {
    s8 sp8;
    s8 sp9;
    u8 pad_A[0x2];
    u8 * spC;
    u8 pad_10[0x4];
    u8 * sp14;
    s32 sp18;
};

struct Item_8011F760 { u8 pad[0x10]; s32 count; };

#include "pso/boss/TBoss4Type3.h"
#include "pso/item/TItemMag.h"
#include "pso/item/TItemProShield.h"

struct Stats_8011F710 { u8 pad[0x16]; u8 max; };

struct Obj_8011F710 { u8 pad[0x1D1]; u8 cur; u8 pad2[0x1DC - 0x1D2]; Stats_8011F710 *stats; };

extern "C" {
s32 get_entity_id(void *);
s32 play_weapon_hit_sound(void *);
void apply_camera_shake__10TObjPlayerFiii(s32 arg0, s32 arg1, s32 arg2);
extern s32 tl_05;
extern const f32 lbl_805DAC94;
extern const f32 lbl_805DAC98;
Item_8011F760 *get_weapon_range_record(void *, s32);
void play_weapon_owner_sounds(void*);

s32 add_weapon_grind(Obj_8011F710 *arg0, s32 arg1);

s32 add_weapon_grind(Obj_8011F710 *arg0, s32 arg1) {
    if ((s32)(arg0->stats->max - (u8)arg1) < arg0->cur) {
        arg0->cur = arg0->stats->max;
    } else {
        arg0->cur += arg1;
    }
    ((TItemEquipBase *)arg0)->refresh_owner_stats();
    return 1;
}

u32 TItemWeapon::get_attack_flags() {
    u32 flags = 0;
    Item_8011F760 *it;
    if (((TItem *)this)->get_icon_index() == 3) {
        flags |= 2;
    } else {
        flags |= 1;
    }
    it = get_weapon_range_record(this, 0);
    if (it != 0 && it->count > 1) {
        flags |= 4;
    }
    return flags;
}

void TItemWeapon::deliver_hit(s32 arg1, u8 *arg2, s32 arg3, s32 arg4, f32 farg0) {
    typedef char sp8_offset[(offsetof(Stack_8011F7CC, sp8) == 0x0) ? 1 : -1];
    typedef char sp9_offset[(offsetof(Stack_8011F7CC, sp9) == 0x1) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8011F7CC, spC) == 0x4) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_8011F7CC, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_8011F7CC, sp18) == 0x10) ? 1 : -1];
    Stack_8011F7CC stack;
    f32 attack_accuracy_scale;
    f32 var_f31_2;
    s32 temp_r31;
    s32 temp_r31_2;
    u8 *temp_r3;
    if (get_mode() == 2) {
        temp_r3 = (u8 *)this->owner;
        if ((temp_r3 != NULL) && (arg2 != NULL)) {
            attack_accuracy_scale = get_attack_accuracy_scale((s16 *)(temp_r3 + 0x7CC));
            if ((arg3 == 2) && (((VObj_18_f8c4e0 *)(this))->m33() == 0)) {
                attack_accuracy_scale *= lbl_805DAC94;
            }
            temp_r31 = arg4 * 0x2C;
            if (((VObj_18_f8c4e0 *)(arg2))->m19(this->owner, *(s32 *)((s8 *)arg2 + 0xA4) + temp_r31, 0, attack_accuracy_scale) != 0) {
                var_f31_2 = lbl_805DAC98;
                switch (arg3) {
                case 0:
                    var_f31_2 = ((VObj_18_f8c4e0 *)(arg2))->m20(this->owner, farg0);
                    break;
                case 1:
                    var_f31_2 = ((VObj_18_f8c4e0 *)(arg2))->m20(this->owner, farg0);
                    ((VObj_18_f8c4e0 *)(arg2))->m23(this->owner, lbl_805DAC94 * var_f31_2);
                    break;
                case 2:
                    ((VObj_18_f8c4e0 *)(arg2))->m22(this->owner, *(s32 *)((s8 *)arg2 + 0xA4) + temp_r31);
                    break;
                }
                if (hit_callback != NULL) {
                    hit_callback(tl_05, this, get_entity_id(arg2), arg4);
                }
                temp_r31_2 = (s32) var_f31_2;
                TObjPlayer::calc_photon_blast_charge(this->owner, temp_r31_2);
                ((VObj_18_f8c4e0 *)(this->owner))->m73();
                apply_camera_shake__10TObjPlayerFiii((s32)this->owner, (s32)arg2, (s32)temp_r31_2);
                ((TObjPlayer *)(&stack.sp8))->reset_status_block();
                stack.sp8 = ((TItem *)((u8 *)this))->get_item_group();
                stack.sp9 = ((TItem *)((u8 *)this))->get_item_index();
                stack.spC = (u8 *)this->owner;
                stack.sp14 = arg2;
                stack.sp18 = arg4;
                play_weapon_hit_sound(&stack.sp8);
            }
        }
    }
}
}
void TItemWeapon::perform_action() {
    TItemWeapon* self=this;
    WeaponMarkerPacket packet;
    WeaponVector gun_point;
    WeaponVector fallback_point;
    if (((TItemWeapon *)self)->is_active_in_game() && !((TItem *)self)->is_hidden() && are_items_enabled_here()) {
        self->rotation_y=self->owner->rotation_y;
        self->stage=((TItemWeapon *)self)->get_attack_stage();
        ((TObjPlayer *)(&packet))->reset_status_block();
        packet.kind=((TItem *)self)->get_item_group();
        packet.variant=((TItem *)self)->get_item_index();
        packet.player=self->owner;
        play_weapon_owner_sounds(&packet);
        if(((TItemWeapon *)self)->test_weapon_flags(0x40000)) {
            start_pad_rumble_client(0x80, 5, (s16)get_entity_id(self->owner));
        } else if(((TItemWeapon *)self)->test_weapon_flags(0x80000) && ((TItemWeapon *)self)->is_mode_two_and_ready()) {
            start_pad_rumble_client(0x80, 5, (s16)get_entity_id(self->owner));
        }
        self->emit_marker_effects();
        ((TItemWeapon *)self)->set_weapon_flags(0x1000000);
        if(!((TItemWeapon *)self)->test_weapon_flags(2)) {
            if(((TItemWeapon *)self)->test_weapon_flags(0x8000)) {
                ((TItemWeapon *)self)->get_gun_point(&gun_point);
                ((TItemWeapon *)self)->fire_shot_at_target((void *)(&gun_point), (void *)(self->second_model), 0);
                return;
            }
            if(((TItemWeapon *)self)->test_weapon_flags(0x20000)) {
                ((TObjPlayer *)self)->update_active_game_effect();
                return;
            }
            ((TItemWeapon *)self)->get_gun_point(&fallback_point);
            self->launch_shot((u8 *)&fallback_point,0,0,1);
        }
    }
}
