#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/effect/item/TItemEffOrgaFlowShot.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TUnk_804ED488.h"
#include "pso/weapon/TUnk_804ED390.h"
#include "pso/weapon/TUnk_804ED298.h"
#include "pso/weapon/TUnk_804ED0A8.h"
#include "pso/weapon/TUnk_804ECEB8.h"
#include "pso/weapon/TUnk_804ECDC0.h"
#include "pso/weapon/TUnk_804ED1A0.h"
#include "pso/weapon/TUnk_804ECFB0.h"
#include "pso/item/TItem.h"
#include "pso/map/FloorArea.h"
#include "pso/system/NinjaTypes.h"
#include <dolphin/mtx.h>
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/vector.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightning.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningHorn.h"
#include <stddef.h>
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/technique/TTecSlicer.h"
#include "pso/map/CsnQuery.h"

#pragma defer_codegen on

struct RecoveredGlobal_803268D8_lbl_804ECFB0 {
    s32 value;
    u8 remaining[0xF4];
};
struct Obj_80326D54 { u8 pad[0x1F8]; f32 x1F8; f32 x1FC; };
extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer__sub_803265C0(u8 *arg0);
void __ct__11TItemWeaponFP7TObjectPUc(void *, void *);
extern s32 lbl_804ECFB0[];
u8 *TObjPlayer__sub_803268D8(u8 *arg0, u8 *arg1, s32 _w2);
u8 *TItemTimerEvent__ct(void *, u32, s32, s32);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
extern const f32 lbl_805DF660;
void TObjPlayer__sub_80326D54(Obj_80326D54 *arg0);
void *__dt__13TUnk_804ECEB8Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804ECFB0Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804ED0A8Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804ED1A0Fv(void *arg0, s16 arg1);
void TObjPlayer__sub_80326794(void* p);
s32 rotate_matrix_x(s32, s32);
s32 add_actor_tp(u8 *arg0, s32 arg1);
int refresh_owner_stats__14TItemEquipBaseFv(void*);
void draw_weapon_at_joint(s32 arg0, s8 arg1);
void set_weapon_trail_joints(s32 arg0, s32 arg1, s8 arg2, s8 arg3);
s32 freeze_curse_timer_ct(s32, u32, s32, s32, f32);
s32 confusion_curse_timer_ct(s32, u32, s32, s32, f32);
s32 TObjectV8047c128_subtract_hp(u8 *arg0, s16 arg1);
s32 __nw__15TItemHeapObjectFUl(s32);
s32 get_owner_client__5TItemFv(void *);
s16 get_actor_tp(u8 *p);
extern s32 __vt__13TUnk_804ECDC0[];
extern s32 lbl_804ECEB8[];
extern s32 create__13TItemShootGunFlllf[];
}
u8 *dark_bridge_create(u8 *arg0);
void * morning_glory_ct(void *, s32, void *);
u8 *create_morning_glory(u8 *arg0);
extern void *lbl_804A0568[8];
u8 *paralysis_curse_timer_ct(u8 *self, u32 base_arg, s32 tag, s32 timer, f32 value);
void dark_bridge_start_timers(void *arg0);
extern const f32 lbl_805DF658;
typedef char RecoveredGlobal_803268D8_lbl_804ECFB0_size[sizeof(RecoveredGlobal_803268D8_lbl_804ECFB0) == 0xF8 ? 1 : -1];
extern s32 lbl_804ED0A8[];
extern s32 lbl_804ED1A0[];
extern "C" {
void *__dt__13TUnk_804ED298Fv(void *arg0, s16 arg1);
extern const f32 lbl_805DF664;
extern const f32 lbl_805DF668;
extern const f32 lbl_805DF66C;
extern const f32 lbl_805DF670;
extern const f32 lbl_805DF674;
extern s32 lbl_804ED298[];
}
struct O_80326F9C { u8 pad[0x1F8]; f32 f; };
extern "C" {
void scale_matrix(int, f32, f32, f32);
extern const f32 lbl_805DF680;
void TObjPlayer__sub_80326F9C(O_80326F9C *arg0);
void *__dt__13TUnk_804ED390Fv(void *arg0, s16 arg1);
extern const float lbl_805DF678;
extern const f32 lbl_805DF684;
extern const f32 lbl_805DF688;
extern const f32 lbl_805DF68C;
extern s32 lbl_804ED390[];
}
void config_dark_flow_attack_collider(int a0, void* a1);
extern "C" {
s32 play_sound_effect(s32, s32, s32, s32);
s16 get_actor_hp(u8 *p);
s32 update_active_game_effect__10TObjPlayerFv(void *);
extern const float lbl_805DF690;
void *__dt__13TUnk_804ED488Fv(void *arg0, s16 arg1);
void *construct_dark_flow(void *arg0);
extern s32 lbl_804ED488[];
}
struct RecoveredGlobal_8012DBF4_lbl_804A5B20 {
    s32 value;
    u8 remaining[0xF4];
};
typedef struct SlicerLaunchData_8012D9C8 {
    u16 player; u16 pad;
    void *textures; void *model; u32 weapon;
    s16 kind, stage; f32 multiplier; f32 color[4];
    s32 facing, spin; f32 first[3], second[3];
} SlicerLaunchData_8012D9C8;
extern "C" {
s32 TBoss5GryphonLightning__ct(f32);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int, f32, f32);
extern s32 __vt__26TBoss5GryphonLightningHorn[];
extern s32 lbl_805D41A0;
extern const f32 lbl_805DF630;
extern const f32 lbl_805DF634;
extern const f32 lbl_805DF644;
u8 *__ct__26TBoss5GryphonLightningHornFv(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 __nw__7TObjectFUl(int);
extern const f32 lbl_805D8D48;
void init_slicer_launch_state(void *arg0);
u16 get_entity_id(void *);
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);
s16 get_validated_attack_stage(u8 *arg0);
f32 query_extended_state__10TObjPlayerFv(void *);
void get_weapon_color__11TItemWeaponFPv(f32 *, void *);
void fn_80325F7C(void *arg0);
typedef char RecoveredGlobal_8012DBF4_lbl_804A5B20_size[sizeof(RecoveredGlobal_8012DBF4_lbl_804A5B20) == 0xF8 ? 1 : -1];
}

extern "C" {
void *construct_dark_flow(void *player) {
    ((void (*)(void *))__ct__11TItemWeaponFP7TObjectPUc)(player);
    *(s32 **)((s8 *)player + 0x18) = lbl_804ED488;
    ((TItemWeapon *)player)->set_weapon_flags(34);
    return player;
}

void *__dt__13TUnk_804ED488Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804ED488;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

void TUnk_804ED488::update_weapon() {
    void *temp_r3;

    temp_r3 = (*(void * *)((u8 *)this + 0xF4));
    if (temp_r3 != NULL) {
        scroll_item_model_uvs(*(NJS_OBJECT **)((s8 *)(*(void **)((s8 *)temp_r3 + 0x2C)) + 0x30), 0x10, 0, 0);
    }
}

void TUnk_804ED488::emit_marker_effects() {

    if (is_mode_two_and_ready() != 0) {
        if ((s32) ((s16) get_actor_hp((u8 *)this->owner) * 8) < ((s16) ((TItemProShield *)(this->owner))->get_field_2b8())) {
            fire_shot_at_target((void *)(*(s32 *)&this->owner + 0x38), (void *)0, -0x238E);
            fire_shot_at_target((void *)(*(s32 *)&this->owner + 0x38), (void *)0, -0x11C7);
            fire_shot_at_target((void *)(*(s32 *)&this->owner + 0x38), (void *)0, 0);
            fire_shot_at_target((void *)(*(s32 *)&this->owner + 0x38), (void *)0, 0x11C7);
            fire_shot_at_target((void *)(*(s32 *)&this->owner + 0x38), (void *)0, 0x238E);
            play_sound_effect(0x4001A642, *(s32 *)&this->owner + 0x38, 0, 0);
            return;
        }
        update_active_game_effect__10TObjPlayerFv(this);
        return;
    }
    update_active_game_effect__10TObjPlayerFv(this);
}

}
void config_dark_flow_attack_collider(int a0, void* a1) { *(float*)((char*)a1 + 0x3c) = lbl_805DF690; *(int*)((char*)a1 + 0x78) = 474; }

extern "C" {
u8 *TObjPlayer::create_vtable_1f8_state() {
    u8 *temp_r3;
    u8 *var_r0;
    if (this != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)((TUnk_804ED390 *)temp_r3)->init_vtable_1f8(tl_05, this)));
        }
        return var_r0;
    }
    return NULL;
}

void*TUnk_804ED390::init_vtable_1f8(s32 _w1, void *_w2) { ((int (*)())__ct__11TItemWeaponFP7TObjectPUc)(); *(int*)((char*)this + 0x18) = (int)lbl_804ED390; *(float *)&this->unk_1F8 = (*(const float *)&lbl_805DF680); return this; }

void *__dt__13TUnk_804ED390Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804ED390;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

void TUnk_804ED390::update_attack() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)lbl_805DF68C, (f32)lbl_805DF680);
}

void TUnk_804ED390::update_idle() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)lbl_805DF684, (f32)lbl_805DF688);
}

void TObjPlayer__sub_80326F9C(O_80326F9C *arg0) {
    s32 n = TObjPlayer::get_player_list();
    switch (n) {
    case 1:
    case 2: {
        f32 f = arg0->f;
        scale_matrix(0, lbl_805DF680, f, f);
        TItem::begin_effect_render();
        break;
    }
    }
}

u8 *TObjPlayer::create_mode_floats_state() {
    u8 *temp_r3;
    u8 *var_r0;
    if (this != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x200));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)((TUnk_804ED298 *)temp_r3)->set_mode_floats(tl_05, this)));
        }
        return var_r0;
    }
    return NULL;
}

void*TUnk_804ED298::set_mode_floats(s32 _w1, void *_w2) { ((int (*)())__ct__11TItemWeaponFP7TObjectPUc)(); *(int*)((char*)this + 0x18) = (int)lbl_804ED298; *(float*)((char*)this + 0x1f8) = (*(const float *)&lbl_805DF660); this->m_1fc = lbl_805DF678; return this; }

void *__dt__13TUnk_804ED298Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804ED298;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

void TUnk_804ED298::update_attack() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)lbl_805DF670, (f32)lbl_805DF660);
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1FC), (f32)lbl_805DF674, (f32)lbl_805DF660);
}

void TUnk_804ED298::update_idle() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)lbl_805DF664, (f32)lbl_805DF668);
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1FC), (f32)lbl_805DF66C, (f32)lbl_805DF670);
}

void TObjPlayer__sub_80326D54(Obj_80326D54 *arg0) {
    switch (TObjPlayer::get_player_list()) {
    case 2: {
        NJS_ARGB color = { arg0->x1FC, 0.0f, 0.0f, 0.0f };
        TItem::begin_offset_material_color(&color);
        break;
    }
    case 3:
        translate_matrix(0, lbl_805DF660, lbl_805DF660, -arg0->x1F8);
        break;
    case 4:
        translate_matrix(0, lbl_805DF660, lbl_805DF660, arg0->x1F8);
        break;
    }
}

void *__dt__13TUnk_804ED1A0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804ED1A0;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

}
u8 *create_morning_glory(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)morning_glory_ct(temp_r3, tl_05, arg0)));
        }
        return var_r0;
    }
    return NULL;
}

void *morning_glory_ct(void *player, s32 _w1, void * _w2) {
    __ct__11TItemWeaponFP7TObjectPUc((void *)player, (void *)_w1);
    *(s32 **)((s8 *)player + 0x18) = lbl_804ED1A0;
    set_weapon_trail_joints((s32)player, 2, 6, 5);
    ((TItemWeapon *)player)->set_weapon_flags(1);
    return player;
}

void TUnk_804ED1A0::reserved_53() { draw_weapon_at_joint((s32)this, (s8)((void*)48)); update_trail_slot(0); update_trail_slot(1); update_trail_slot(2); }

void TUnk_804ED1A0::update_weapon() { refresh_owner_stats__14TItemEquipBaseFv(this); }

u8 *TObjPlayer::create_state_1536() {
    u8 *temp_r3;
    u8 *var_r0;
    if (this != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x200));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)((TUnk_804ED0A8 *)temp_r3)->init_state_1536(tl_05, this)));
        }
        return var_r0;
    }
    return NULL;
}

void *TUnk_804ED0A8::init_state_1536(s32 _w1, void *_w2) {
    __ct__11TItemWeaponFP7TObjectPUc((void *)this, (void *)_w1);
    *(s32 **)((s8 *)this + 0x18) = lbl_804ED0A8;
    set_weapon_flags(1536);
    *(u32 *)((s8 *)this + 0x1F8) = 0;
    this->m_1fc = 0;
    return this;
}

void *__dt__13TUnk_804ED0A8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804ED0A8;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

void TUnk_804ED0A8::update_attack() {
    u8 *arg0 = (u8 *)this;
    TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x1FC), -0xAAA, 0);
    if ((s32) this->m_1fc == 0) {
        TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x1F8), -0xAAA, 0);
    }
}

void TUnk_804ED0A8::update_idle() {
    u8 *arg0 = (u8 *)this;
    TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x1F8), 0x71C, 0x4000);
    if ((s32) *(s32 *)&this->unk_1F8 == 0x4000) {
        TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x1FC), 0x71C, 0x4000);
    }
}

void TObjPlayer::apply_container_item() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 1:
        rotate_matrix_x(0, *(s32 *)&this->unk_1F8);
        return;
    case 2:
        rotate_matrix_x(0, this->m_1fc);
        return;
    }
}

u8 *paralysis_curse_timer_ct(u8 *self, u32 base_arg, s32 tag, s32 timer, f32 value) {
    TItemTimerEvent__ct(self, base_arg, tag, timer);
    *(void ***)((s8 *)self + 0x18) = lbl_804A0568;
    *(f32 *)((s8 *)self + 0x2C) = value;
    return self;
}

u8 *dark_bridge_create(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x200));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TObjPlayer__sub_803268D8((u8 *)temp_r3, (u8 *)tl_05, (s32)arg0));
        }
        return var_r0;
    }
    return NULL;
}

u8 *TObjPlayer__sub_803268D8(u8 *arg0, u8 *arg1, s32 _w2) {
    __ct__11TItemWeaponFP7TObjectPUc(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_803268D8_lbl_804ECFB0 *)&lbl_804ECFB0).value;
    ((TUnk_804ECFB0 *)arg0)->m_1fc = -1;
    *(s32 *)((s8 *)arg0 + 0x1F8) = 0;
    return arg0;
}

void *__dt__13TUnk_804ECFB0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804ECFB0;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

void dark_bridge_start_timers(void *arg0) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;

    ((TUnk_804ECFB0 *)arg0)->m_1fc = get_actor_tp((u8 *)(*(s32 *)((s8 *)arg0 + 0xF0)));
    *(s32 *)((s8 *)arg0 + 0x1F8) = 0;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x174) != 0U) {
        temp_r3 = __nw__15TItemHeapObjectFUl(0x30);
        if (temp_r3 != 0) {
            freeze_curse_timer_ct(temp_r3, *(u32 *)((s8 *)arg0 + 0x174), get_owner_client__5TItemFv(arg0), 0x2328, lbl_805DF658);
        }
        temp_r3_2 = __nw__15TItemHeapObjectFUl(0x30);
        if (temp_r3_2 != 0) {
            confusion_curse_timer_ct(temp_r3_2, *(u32 *)((s8 *)arg0 + 0x174), get_owner_client__5TItemFv(arg0), 0x2328, lbl_805DF658);
        }
        temp_r3_3 = __nw__15TItemHeapObjectFUl(0x30);
        if (temp_r3_3 != 0) {
            paralysis_curse_timer_ct((u8 *)temp_r3_3, (u32)(*(u32 *)((s8 *)arg0 + 0x174)), (s32)(get_owner_client__5TItemFv(arg0)), 0x2328, lbl_805DF658);
        }
    }
}

extern "C" {
void TObjPlayer__sub_80326794(void* p) { ((TUnk_804ECFB0 *)p)->m_1fc = -1; *(s32*)((char*)p + 0x1f8) = 0; }

void TUnk_804ECFB0::update_weapon() {
    s16 temp_r0;
    s16 temp_r3;
    s32 temp_r31;

    if (is_current_area_item_enabled() != 0) {
        temp_r3 = get_actor_tp((u8 *)this->owner);
        temp_r0 = this->m_1fc - temp_r3;
        if (temp_r0 != 0) {
            this->m_1fc = temp_r3;
        }
        if (temp_r0 > 0) {
            temp_r31 = temp_r0 / 2;
            TObjectV8047c128_subtract_hp((u8 *)this->owner, (s16) temp_r31);
            add_actor_tp((u8 *)this->owner, (s16) temp_r31);
        }
    }
    *(s32 *)((s8 *)this + 0x1F8) = (s32) (*(s32 *)((s8 *)this + 0x1F8) + 1);
}

u8 *TObjPlayer::create_vtable_variant() {
    u8 *temp_r3;
    u8 *var_r0;
    if (this != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)((TUnk_804ECEB8 *)temp_r3)->init_vtable_variant(tl_05, this)));
        }
        return var_r0;
    }
    return NULL;
}

void *TUnk_804ECEB8::init_vtable_variant(s32 _w1, void *_w2) {
    __ct__11TItemWeaponFP7TObjectPUc((void *)this, (void *)_w1);
    *(s32 **)((s8 *)this + 0x18) = lbl_804ECEB8;
    *(s32 **)((s8 *)this + 0x1F0) = create__13TItemShootGunFlllf;
    return this;
}

void *__dt__13TUnk_804ECEB8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804ECEB8;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

u8 *TObjPlayer__sub_803265C0(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)((TUnk_804ECDC0 *)temp_r3)->set_vtable_mode2_alt(tl_05, arg0)));
        }
        return var_r0;
    }
    return NULL;
}

void *TUnk_804ECDC0::set_vtable_mode2_alt(s32 _w1, void *_w2) {
    __ct__11TItemWeaponFP7TObjectPUc((void *)this, (void *)_w1);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804ECDC0;
    set_weapon_flags(2);
    return this;
}

TUnk_804ECDC0::~TUnk_804ECDC0() {}

void TUnk_804ECDC0::emit_marker_effects() {
    f32 tmp[4];
    SlicerLaunchData_8012D9C8 launch;
    init_slicer_launch_state(&launch);
    launch.player = get_entity_id(*(u8 * *)&owner);
    launch.weapon = this->get_item_id();
    launch.textures = *(void **)((s8 *)this + 0x24);
    launch.model = *(void **)((s8 *)this + 0x188);
    launch.kind = TObjPlayer__sub_801D2F4C((s16 *)(*(u8 * *)&owner + 0x7CC));
    launch.stage = get_validated_attack_stage(*(u8 * *)&owner + 0x7CC);
    launch.multiplier = query_extended_state__10TObjPlayerFv(*(u8 * *)&owner);
    get_weapon_color__11TItemWeaponFPv(tmp, this);
    copy_argb((NJS_ARGB *)launch.color, (NJS_ARGB *)tmp);
    launch.facing = *(s32 *)((s8 *)(*(u8 * *)&owner) + 0x60);
    this->get_joint_position(0x2, launch.first);
    this->get_joint_position(0x1, launch.second);
    TTecSlicer::create((u16*)&launch);
}

s32 TBoss8Dragon::spawn_ground_lightning(s32 arg0, s32 arg1, s32 arg2) {
    Vec position;
    f32 ground_height;
    s32 allocation;
    s32 effect;
    u8* collision;
    VecCopy(&position, (const Vec *)arg1);
    collision = (u8 *)csnVecterUnder((s32)((s32*)&position), 0x16EF);
    if (collision == NULL) {
        position.y = lbl_805D8D48;
    } else {
        ground_height = *(f32*)((s8 *)(*(u8**)((s8 *)collision + 4)) + 4);
        if (ground_height > lbl_805D8D48) {
            position.y = lbl_805D8D48;
        } else {
            position.y = ground_height;
        }
    }
    position.y += 12.0f;
    allocation = __nw__7TObjectFUl(0xA8);
    effect = allocation;
    if (effect != 0) {
        effect = (s32)__ct__26TBoss5GryphonLightningHornFv((u8*)allocation, arg0, (s32)&position, arg2);
    }
    return effect;
}

u8 *__ct__26TBoss5GryphonLightningHornFv(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 temp_f1;
    TBoss5GryphonLightning__ct(lbl_805DF644);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__26TBoss5GryphonLightningHorn;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D41A0;
    *(s32 *)((s8 *)arg0 + 0xA4) = arg3;
    temp_f1 = 5.0f * sin_table_lookup((int) (*(s32 *)((s8 *)arg0 + 0xA4)));
    *(f32 *)((s8 *)arg0 + 0x98) = temp_f1;
    *(f32 *)((s8 *)arg0 + 0x9C) = (f32) lbl_805DF630;
    *(f32 *)((s8 *)arg0 + 0xA0) = (f32) (5.0f * cos_table_lookup((int) (*(s32 *)((s8 *)arg0 + 0xA4)), temp_f1, 5.0f));
    *(f32 *)((s8 *)arg0 + 0x8C) = (f32) lbl_805DF634;
    *(s32 *)((s8 *)arg0 + 0x90) = 4;
    return arg0;
}

TBoss5GryphonLightningHorn::~TBoss5GryphonLightningHorn() {}

void TBoss5GryphonLightningHorn::run_task() { rebuild_lightning_segments(); fn_80325F7C(this); spawn_gryphon_lightning(); }

void TBoss5GryphonLightningHorn::render() {  }

}
