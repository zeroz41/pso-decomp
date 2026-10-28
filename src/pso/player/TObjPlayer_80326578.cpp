#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/item/TItemProShield.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804ED488.h"
#include "pso/player/TUnk_804ED390.h"
#include "pso/player/TUnk_804ED298.h"
#include "pso/player/TUnk_804ED0A8.h"
#include "pso/player/TUnk_804ECEB8.h"
#include "pso/boss/TUnk_804ECDC0.h"
#include "pso/player/TUnk_804ED1A0.h"
#include "pso/player/TUnk_804ECFB0.h"
#include "pso/item/TItem.h"
#include "pso/map/CurrentArea.h"

struct RecoveredGlobal_803268D8_lbl_804ECFB0 {
    s32 value;
    u8 remaining[0xF4];
};

struct Rec_80326D54 { f32 a; s32 b; s32 c; s32 d; };

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
extern Rec_80326D54 lbl_80476760;
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

extern s32 lbl_804ECDC0[];

void *TUnk_804ECDC0::set_vtable_mode2_alt(s32 _w1, void *_w2) {
    __ct__11TItemWeaponFP7TObjectPUc((void *)this, (void *)_w1);
    *(s32 **)((s8 *)this + 0x18) = lbl_804ECDC0;
    set_weapon_flags(2);
    return this;
}

extern s32 lbl_804ECEB8[];

extern s32 create__13TItemShootGunFlllf[];

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
void *TUnk_804ECEB8::init_vtable_variant(s32 _w1, void *_w2) {
    __ct__11TItemWeaponFP7TObjectPUc((void *)this, (void *)_w1);
    *(s32 **)((s8 *)this + 0x18) = lbl_804ECEB8;
    *(s32 **)((s8 *)this + 0x1F0) = create__13TItemShootGunFlllf;
    return this;
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

void TUnk_804ECFB0::update_weapon() {
    s16 temp_r0;
    s16 temp_r3;
    s32 temp_r31;

    if (are_items_enabled_here() != 0) {
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
void TObjPlayer__sub_80326794(void* p) { ((TUnk_804ECFB0 *)p)->m_1fc = -1; *(s32*)((char*)p + 0x1f8) = 0; }
}
u8 *dark_bridge_create(u8 *arg0);
void * morning_glory_ct(void *, s32, void *);
u8 *create_morning_glory(u8 *arg0);
extern void *lbl_804A0568[8];
u8 *paralysis_curse_timer_ct(u8 *self, u32 base_arg, s32 tag, s32 timer, f32 value);
void dark_bridge_start_timers(void *arg0);

extern const f32 lbl_805DF658;

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

typedef char RecoveredGlobal_803268D8_lbl_804ECFB0_size[sizeof(RecoveredGlobal_803268D8_lbl_804ECFB0) == 0xF8 ? 1 : -1];
u8 *TObjPlayer__sub_803268D8(u8 *arg0, u8 *arg1, s32 _w2) {
    __ct__11TItemWeaponFP7TObjectPUc(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_803268D8_lbl_804ECFB0 *)&lbl_804ECFB0).value;
    ((TUnk_804ECFB0 *)arg0)->m_1fc = -1;
    *(s32 *)((s8 *)arg0 + 0x1F8) = 0;
    return arg0;
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

u8 *paralysis_curse_timer_ct(u8 *self, u32 base_arg, s32 tag, s32 timer, f32 value) {
    TItemTimerEvent__ct(self, base_arg, tag, timer);
    *(void ***)((s8 *)self + 0x18) = lbl_804A0568;
    *(f32 *)((s8 *)self + 0x2C) = value;
    return self;
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

void TUnk_804ED0A8::update_idle() {
    u8 *arg0 = (u8 *)this;
    TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x1F8), 0x71C, 0x4000);
    if ((s32) *(s32 *)&this->unk_1F8 == 0x4000) {
        TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x1FC), 0x71C, 0x4000);
    }
}

void TUnk_804ED0A8::update_attack() {
    u8 *arg0 = (u8 *)this;
    TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x1FC), -0xAAA, 0);
    if ((s32) this->m_1fc == 0) {
        TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x1F8), -0xAAA, 0);
    }
}

extern s32 lbl_804ED0A8[];

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

void *TUnk_804ED0A8::init_state_1536(s32 _w1, void *_w2) {
    __ct__11TItemWeaponFP7TObjectPUc((void *)this, (void *)_w1);
    *(s32 **)((s8 *)this + 0x18) = lbl_804ED0A8;
    set_weapon_flags(1536);
    *(u32 *)((s8 *)this + 0x1F8) = 0;
    this->m_1fc = 0;
    return this;
}

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

void TUnk_804ED1A0::update_weapon() { refresh_owner_stats__14TItemEquipBaseFv(this); }
void TUnk_804ED1A0::reserved_53() { draw_weapon_at_joint((s32)this, (s8)((void*)48)); update_trail_slot(0); update_trail_slot(1); update_trail_slot(2); }

extern s32 lbl_804ED1A0[];

void *morning_glory_ct(void *player, s32 _w1, void * _w2) {
    __ct__11TItemWeaponFP7TObjectPUc((void *)player, (void *)_w1);
    *(s32 **)((s8 *)player + 0x18) = lbl_804ED1A0;
    set_weapon_trail_joints((s32)player, 2, 6, 5);
    ((TItemWeapon *)player)->set_weapon_flags(1);
    return player;
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
extern "C" {

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
void TObjPlayer__sub_80326D54(Obj_80326D54 *arg0) {
    switch (TObjPlayer::get_player_list()) {
    case 2: {
        Rec_80326D54 r = lbl_80476760;
        r.a = arg0->x1FC;
        TItem::begin_offset_material_color((const NJS_ARGB *)&r);
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

void *__dt__13TUnk_804ED298Fv(void *arg0, s16 arg1);

extern const f32 lbl_805DF664;
extern const f32 lbl_805DF668;
extern const f32 lbl_805DF66C;
extern const f32 lbl_805DF670;

void TUnk_804ED298::update_idle() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)lbl_805DF664, (f32)lbl_805DF668);
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1FC), (f32)lbl_805DF66C, (f32)lbl_805DF670);
}

extern const f32 lbl_805DF674;

void TUnk_804ED298::update_attack() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)lbl_805DF670, (f32)lbl_805DF660);
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1FC), (f32)lbl_805DF674, (f32)lbl_805DF660);
}

extern s32 lbl_804ED298[];

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
}

struct O_80326F9C { u8 pad[0x1F8]; f32 f; };

extern "C" {
void scale_matrix(int, f32, f32, f32);
extern const f32 lbl_805DF680;
void TObjPlayer__sub_80326F9C(O_80326F9C *arg0);
void *__dt__13TUnk_804ED390Fv(void *arg0, s16 arg1);

#define lbl_804ED298 ((unsigned char *)lbl_804ED298)
    extern const float lbl_805DF678;
void*TUnk_804ED298::set_mode_floats(s32 _w1, void *_w2) { ((int (*)())__ct__11TItemWeaponFP7TObjectPUc)(); *(int*)((char*)this + 0x18) = (int)lbl_804ED298; *(float*)((char*)this + 0x1f8) = (*(const float *)&lbl_805DF660); this->m_1fc = lbl_805DF678; return this; }

extern const f32 lbl_805DF684;
extern const f32 lbl_805DF688;

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

void TUnk_804ED390::update_idle() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)lbl_805DF684, (f32)lbl_805DF688);
}

extern const f32 lbl_805DF68C;

void TUnk_804ED390::update_attack() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1F8), (f32)lbl_805DF68C, (f32)lbl_805DF680);
}

extern s32 lbl_804ED390[];

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
}

#undef lbl_804ED298
void config_dark_flow_attack_collider(int a0, void* a1);
extern "C" {
s32 play_sound_effect(s32, s32, s32, s32);

s16 get_actor_hp(u8 *p);
s32 update_active_game_effect__10TObjPlayerFv(void *);

#define lbl_804ED390 ((unsigned char *)lbl_804ED390)
void*TUnk_804ED390::init_vtable_1f8(s32 _w1, void *_w2) { ((int (*)())__ct__11TItemWeaponFP7TObjectPUc)(); *(int*)((char*)this + 0x18) = (int)lbl_804ED390; *(float *)&this->unk_1F8 = (*(const float *)&lbl_805DF680); return this; }

    extern const float lbl_805DF690;

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
}

void config_dark_flow_attack_collider(int a0, void* a1) { *(float*)((char*)a1 + 0x3c) = lbl_805DF690; *(int*)((char*)a1 + 0x78) = 474; }
extern "C" {

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

#undef lbl_804ED390
void *__dt__13TUnk_804ED488Fv(void *arg0, s16 arg1);
void *construct_dark_flow(void *arg0);


void TUnk_804ED488::update_weapon() {
    void *temp_r3;

    temp_r3 = (*(void * *)((u8 *)this + 0xF4));
    if (temp_r3 != NULL) {
        scroll_item_model_uvs(*(NJS_OBJECT **)((s8 *)(*(void **)((s8 *)temp_r3 + 0x2C)) + 0x30), 0x10, 0, 0);
    }
}

extern s32 lbl_804ED488[];

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

void *construct_dark_flow(void *player) {
    ((void (*)(void *))__ct__11TItemWeaponFP7TObjectPUc)(player);
    *(s32 **)((s8 *)player + 0x18) = lbl_804ED488;
    ((TItemWeapon *)player)->set_weapon_flags(34);
    return player;
}
}
