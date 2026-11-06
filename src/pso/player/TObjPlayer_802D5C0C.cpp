#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/weapon/TUnk_804E23F0.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include <stddef.h>
#include "pso/item/TItemEquipBase.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/weapon/TUnk_804E1BB0.h"

namespace P802D5C0C {

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
    virtual s32 m60(s32 *);
    virtual void m61();
    virtual void m62();
    virtual s32 m63(s32, s32 *);
};

struct VBase_18_f1aa6a { char pad[0x18]; };

struct VObj_18_f1aa6a : VBase_18_f1aa6a {
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
    virtual s32 m63(s32, s32 *);
};

extern "C" {
s16 get_validated_attack_stage(u8 *arg0);
void fire_spread_shot__10TObjPlayerFPv(u8 *arg0);
void reserved_53__13TUnk_804E23F0Fv(u8 *arg0);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
s32 pop_matrix();
f32 post_translate_matrix(void *);
void TObjPlayer__sub_802D5DE0(u8 *arg0);
void create_cane_effect_from_state__10TObjPlayerFPv(void *arg0);
void* init_state_445__10TObjPlayerFPv(void* a0);
void set_radar_marker_params__10TObjPlayerFPvPv(u8 *arg0, u8 *arg1);
void update_weapon__13TUnk_804E23F0Fv(void *arg0);
s32 get_weapon_color__11TItemWeaponFPv(s32 *, void *);
int __ct__11TItemWeaponFP7TObjectPUc(void);

void set_radar_marker_params__10TObjPlayerFPvPv(u8 *weapon, u8 *arg1) {
    s32 sp8;

    *(f32 *)((s8 *)arg1 + 0x4C) = (f32) *(f32 *)((s8 *)weapon + 0x200);
    *(s32 *)((s8 *)arg1 + 0x58) = 0xC000;
    *(s32 *)((s8 *)arg1 + 0x40) = (s32) (*(s32 *)((s8 *)arg1 + 0x40) | 2);
    get_weapon_color__11TItemWeaponFPv(&sp8, weapon);
    copy_argb((NJS_ARGB *)(arg1 + 0x60), (NJS_ARGB *)&sp8);
    *(s32 *)((s8 *)arg1 + 0x74) = (s32) *(s32 *)((s8 *)weapon + 0x208);
    *(s32 *)((s8 *)arg1 + 0x70) = (s32) *(s32 *)((s8 *)weapon + 0x204);
}

void TUnk_804E23F0::update_weapon() {
    if (((TItemWeapon *)this)->get_attack_stage() == 2) {
        *(s32 *)((s8 *)this + 0x1F8) = (s32) (*(s32 *)((s8 *)this + 0x1F8) | 1);
        return;
    }
    *(s32 *)((s8 *)this + 0x1F8) = (s32) (*(s32 *)((s8 *)this + 0x1F8) & 0xFFFFFFFE);
}

extern s32 tl_05;

void create_cane_effect_from_state__10TObjPlayerFPv(void *item) {
    if (((TItemWeapon *)item)->get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->create_item_eff_cane((TItem*)item, -1, (s32)(((TUnk_804E23F0 *)item)->m_1fc));
    }
}

    extern unsigned char TObjPlayer__sub_8032E648[];
    extern unsigned char create_network_object__10TObjPlayerFlPUll[];
    extern unsigned char lbl_804E23F0[];

void fire_spread_shot__10TObjPlayerFPv(u8 *arg0) {
    s32 sp8;
    ((VObj_18 *)(((TUnk_804E23F0 *)arg0)->owner))->m63(0x30, &sp8);
    if (get_validated_attack_stage((*(u8 * *)&((TUnk_804E23F0 *)arg0)->owner + 0x7CC)) == 2) {
        ((TItemWeapon *)arg0)->fire_shot_at_target((void *)(&sp8), (void *)(*(s32 *)((s8 *)arg0 + 0xF4)), 0);
        ((TItemWeapon *)arg0)->fire_shot_at_target((void *)(&sp8), (void *)(*(s32 *)((s8 *)arg0 + 0xF4)), 0x1555);
        ((TItemWeapon *)arg0)->fire_shot_at_target((void *)(&sp8), (void *)(*(s32 *)((s8 *)arg0 + 0xF4)), -0x1555);
    } else {
        ((TItemWeapon *)arg0)->fire_shot_at_target((void *)(&sp8), (void *)(*(s32 *)((s8 *)arg0 + 0xF4)), 0);
    }
    ((VObj_18 *)(arg0))->m60(&sp8);
}

const NJS_POINT3 lbl_80472590 = { 0.0f, 0.0f, 0.5f };

void TObjPlayer__sub_802D5DE0(u8 *item_weapon) {
    if (TObjPlayer::get_player_list() == 0) {
        NJS_POINT3 offset = lbl_80472590;
        post_translate_matrix(&offset);
        rotate_matrix_x(0, 0x18E3);
        if (*(s32 *)((s8 *)item_weapon + 0x1f8) & 1) {
            push_matrix();
            rotate_matrix_x(0, 0x2AAA);
            ((TItem *)item_weapon)->draw_model();
            pop_matrix();
            push_matrix();
            rotate_matrix_x(0, -0x2AAA);
            ((TItem *)item_weapon)->draw_model();
            pop_matrix();
        }
    }
}

void TUnk_804E23F0::reserved_53() {
    if (((TItemWeapon *)((u8 *)this))->test_weapon_flags(0x01000000U) == 0U) {
        ((TItemWeapon *)((u8 *)this))->draw_weapon_model();
    }
}

void* init_state_445__10TObjPlayerFPv(void* a0) { __ct__11TItemWeaponFP7TObjectPUc(); *(int*)((char*)a0 + 0x18) = (int)lbl_804E23F0; ((TItemWeapon *)a0)->set_weapon_flags(3); *(int*)((char*)a0 + 0x1f8) = 0; ((TUnk_804E23F0 *)a0)->m_1fc = 445; *(int*)((char*)a0 + 0x204) = (int)TObjPlayer__sub_8032E648; *(int*)((char*)a0 + 0x208) = (int)create_network_object__10TObjPlayerFlPUll; *(float*)((char*)a0 + 0x200) = 4.0f; return a0; }

}

}

struct TItemEquipBase;

extern "C" {
void *__nw__5TItemFUl(u32);
void *setup_state__10TObjPlayerFPv(void *, s32, void *);
void *init_needle_effect__10TObjPlayerFPv(void *, s32, void *);
void *enter_state_341__13TUnk_804E2000Fv(void *, s32, void *);
void *init_mag_effect_state__10TObjPlayerFPv(void *, s32, void *);
void *init_type_447__13TUnk_804E22F4Fv(void *, s32, void *);
void *init_vtable_and_handlers_341__13TUnk_804E1F04Fv(void *, s32, void *);
void *init_vtable_and_field200__10TObjPlayerFPv(void *, s32, void *);
extern s32 tl_05;
void *__dt__13TUnk_804E1E08Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804E1F04Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804E2000Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804E20FCFv(void *arg0, s16 arg1);
void *__dt__13TUnk_804E21F8Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804E22F4Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804E23F0Fv(void *arg0, s16 arg1);

extern s32 lbl_804E1E08[];

extern "C" s8 get_attach_slot__14TItemEquipBaseFv(TItemEquipBase *arg0);
extern "C" void snap_to_owner__5TItemFv();
extern "C" void update_in_inventory__5TItemFv();
extern "C" int feed__5TItemFP9TItemData(void);
extern "C" void add_slot__5TItemFv();
extern "C" int update_object_view_visibility__5TItemFff(void *p);
extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void vfunc_60__11TItemWeaponFv();
extern "C" void init_weapon_effect_descriptor__11TItemWeaponFP13Desc_8011E5C4();
extern "C" void vfunc_58__11TItemWeaponFv();
extern "C" void vfunc_57__11TItemWeaponFv();
extern "C" void update_weapon__11TItemWeaponFv();
extern "C" void update_idle__11TItemWeaponFv();
extern "C" void update_attack__11TItemWeaponFv();
extern "C" void activate_effect__11TItemWeaponFl();
extern "C" void update_owned__11TItemWeaponFv();
extern "C" void on_model_loaded__11TItemWeaponFv();
extern "C" void write_item_data__11TItemWeaponFP9TItemData();
extern "C" void on_unequip__11TItemWeaponFv();
extern "C" u8 get_motion_type__11TItemWeaponFv(void *p);
extern "C" void TObjPlayer__sub_802D5DE0(u8 *arg0);
extern "C" void add_equip_stats__14TItemEquipBaseFl();
extern "C" void on_equip__11TItemWeaponFv();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void apply_owner_bonuses__11TItemWeaponFv();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void create_cane_effect_from_state__10TObjPlayerFPv(void *item);
extern "C" void deliver_hit__11TItemWeaponFlPUcllf();
extern "C" void perform_action__11TItemWeaponFv();
extern "C" void use__5TItemFv();
extern "C" void render__5TItemFv();
extern "C" void render_equipped_shadow__11TItemWeaponFv();
extern "C" void reserved_53__13TUnk_804E1BB0Fv(s32 arg0);
extern "C" void reserved_53__13TUnk_804E23F0Fv(u8 *arg0);
extern "C" void render_equipped__11TItemWeaponFv();
extern "C" void equip__14TItemEquipBaseFv();
extern "C" void fire_spread_shot__10TObjPlayerFPv(u8 *arg0);
extern "C" void get_attack_flags__11TItemWeaponFv();
extern "C" void get_center__11TItemWeaponFv();
extern "C" void *__dt__13TUnk_804E1BB0Fv(void *arg0, s16 arg1);
extern "C" void *__dt__13TUnk_804E1CA8Fv(void *arg0, s16 arg1);
extern "C" void launch_shot__11TItemWeaponFPUclll();
extern "C" void request_equipped_model__11TItemWeaponFv();
extern "C" void get_name__5TItemFv();
extern "C" void reset_motion_fields__14TObjCollidableFv();
extern "C" void remove_equip_stats__14TItemEquipBaseFl();
extern "C" void render_shadows__5TItemFv();
extern "C" void remove_owner_bonuses__11TItemWeaponFv();
extern "C" void release_model__11TItemWeaponFv();
extern "C" int get_slot_count__5TItemFv(void);
extern "C" int add_amount__5TItemFl(void);
extern "C" int remove_amount__5TItemFl(void);
extern "C" int get_amount__5TItemFv(void);
extern "C" void run_task__5TItemFv();
extern "C" void set_attach_slot__14TItemEquipBaseFSc();
extern "C" void setup_radar_marker__10TObjPlayerFPvPv(TObjPlayer *arg0, void *arg1);
extern "C" void subtract_equip_stats__14TItemEquipBaseFPvPsPs();
extern "C" void subtract_item_stat_bonus__14TItemEquipBaseFllPs();
extern "C" void interact__5TItemFl();
extern "C" void unequip__14TItemEquipBaseFv();
extern "C" void update_equipped__11TItemWeaponFv();
extern "C" void destroy__14TItemEquipBaseFv();
extern "C" void refresh_special__11TItemWeaponFv();
extern "C" void is_identified__11TItemWeaponFv();
extern "C" void update_weapon__13TUnk_804E23F0Fv(void *arg0);
extern "C" void render_equipped_deferred__11TItemWeaponFv();
extern "C" void emit_marker_effects__11TItemWeaponFv();
void *lbl_804E1BB0[62] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__13TUnk_804E1BB0Fv, (void *)&run_task__5TItemFv,
    (void *)&render__5TItemFv, (void *)&render_shadows__5TItemFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__14TObjCollidableFv, (void *)&get_center__11TItemWeaponFv, (void *)&update_object_view_visibility__5TItemFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__5TItemFv, (void *)&interact__5TItemFl, (void *)&update_owned__11TItemWeaponFv, (void *)&update_in_inventory__5TItemFv,
    (void *)&update_equipped__11TItemWeaponFv, (void *)&activate_effect__11TItemWeaponFl, (void *)&write_item_data__11TItemWeaponFP9TItemData, (void *)&set_attach_slot__14TItemEquipBaseFSc,
    (void *)&equip__14TItemEquipBaseFv, (void *)&unequip__14TItemEquipBaseFv, (void *)&add_equip_stats__14TItemEquipBaseFl, (void *)&remove_equip_stats__14TItemEquipBaseFl,
    (void *)&subtract_item_stat_bonus__14TItemEquipBaseFllPs, (void *)&subtract_equip_stats__14TItemEquipBaseFPvPsPs, (void *)&render_equipped__11TItemWeaponFv, (void *)&render_equipped_shadow__11TItemWeaponFv,
    (void *)&render_equipped_deferred__11TItemWeaponFv, (void *)&destroy__14TItemEquipBaseFv, (void *)&perform_action__11TItemWeaponFv, (void *)&use__5TItemFv,
    (void *)&get_attack_flags__11TItemWeaponFv, (void *)&get_attach_slot__14TItemEquipBaseFv, (void *)&refresh_special__11TItemWeaponFv, (void *)&is_identified__11TItemWeaponFv,
    (void *)&get_amount__5TItemFv, (void *)&remove_amount__5TItemFl, (void *)&add_amount__5TItemFl, (void *)&get_slot_count__5TItemFv,
    (void *)&add_slot__5TItemFv, (void *)&feed__5TItemFP9TItemData, (void *)&snap_to_owner__5TItemFv, (void *)&get_motion_type__11TItemWeaponFv,
    (void *)&on_equip__11TItemWeaponFv, (void *)&on_unequip__11TItemWeaponFv, (void *)&request_equipped_model__11TItemWeaponFv, (void *)&release_model__11TItemWeaponFv,
    (void *)&apply_owner_bonuses__11TItemWeaponFv, (void *)&remove_owner_bonuses__11TItemWeaponFv, (void *)&on_model_loaded__11TItemWeaponFv, (void *)&launch_shot__11TItemWeaponFPUclll,
    (void *)&emit_marker_effects__11TItemWeaponFv, (void *)&update_attack__11TItemWeaponFv, (void *)&update_idle__11TItemWeaponFv, (void *)&reserved_53__13TUnk_804E1BB0Fv,
    (void *)&update_weapon__11TItemWeaponFv, (void *)&vfunc_57__11TItemWeaponFv, (void *)&vfunc_58__11TItemWeaponFv, (void *)&init_weapon_effect_descriptor__11TItemWeaponFP13Desc_8011E5C4,
    (void *)&vfunc_60__11TItemWeaponFv, (void *)&deliver_hit__11TItemWeaponFlPUcllf,
};
void *lbl_804E1CA8[63] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__13TUnk_804E1CA8Fv, (void *)&run_task__5TItemFv,
    (void *)&render__5TItemFv, (void *)&render_shadows__5TItemFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__14TObjCollidableFv, (void *)&get_center__11TItemWeaponFv, (void *)&update_object_view_visibility__5TItemFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__5TItemFv, (void *)&interact__5TItemFl, (void *)&update_owned__11TItemWeaponFv, (void *)&update_in_inventory__5TItemFv,
    (void *)&update_equipped__11TItemWeaponFv, (void *)&activate_effect__11TItemWeaponFl, (void *)&write_item_data__11TItemWeaponFP9TItemData, (void *)&set_attach_slot__14TItemEquipBaseFSc,
    (void *)&equip__14TItemEquipBaseFv, (void *)&unequip__14TItemEquipBaseFv, (void *)&add_equip_stats__14TItemEquipBaseFl, (void *)&remove_equip_stats__14TItemEquipBaseFl,
    (void *)&subtract_item_stat_bonus__14TItemEquipBaseFllPs, (void *)&subtract_equip_stats__14TItemEquipBaseFPvPsPs, (void *)&render_equipped__11TItemWeaponFv, (void *)&render_equipped_shadow__11TItemWeaponFv,
    (void *)&render_equipped_deferred__11TItemWeaponFv, (void *)&destroy__14TItemEquipBaseFv, (void *)&perform_action__11TItemWeaponFv, (void *)&use__5TItemFv,
    (void *)&get_attack_flags__11TItemWeaponFv, (void *)&get_attach_slot__14TItemEquipBaseFv, (void *)&refresh_special__11TItemWeaponFv, (void *)&is_identified__11TItemWeaponFv,
    (void *)&get_amount__5TItemFv, (void *)&remove_amount__5TItemFl, (void *)&add_amount__5TItemFl, (void *)&get_slot_count__5TItemFv,
    (void *)&add_slot__5TItemFv, (void *)&feed__5TItemFP9TItemData, (void *)&snap_to_owner__5TItemFv, (void *)&get_motion_type__11TItemWeaponFv,
    (void *)&on_equip__11TItemWeaponFv, (void *)&on_unequip__11TItemWeaponFv, (void *)&request_equipped_model__11TItemWeaponFv, (void *)&release_model__11TItemWeaponFv,
    (void *)&apply_owner_bonuses__11TItemWeaponFv, (void *)&remove_owner_bonuses__11TItemWeaponFv, (void *)&on_model_loaded__11TItemWeaponFv, (void *)&launch_shot__11TItemWeaponFPUclll,
    (void *)&fire_spread_shot__10TObjPlayerFPv, (void *)&update_attack__11TItemWeaponFv, (void *)&update_idle__11TItemWeaponFv, (void *)&reserved_53__13TUnk_804E23F0Fv,
    (void *)&update_weapon__13TUnk_804E23F0Fv, (void *)&vfunc_57__11TItemWeaponFv, (void *)&vfunc_58__11TItemWeaponFv, (void *)&setup_radar_marker__10TObjPlayerFPvPv,
    (void *)&TObjPlayer__sub_802D5DE0, (void *)&deliver_hit__11TItemWeaponFlPUcllf, (void *)&create_cane_effect_from_state__10TObjPlayerFPv,
};

void *TObjPlayer::create_object_by_type() {
    u8 *arg0 = (u8 *)this;
    void *p;
    if (arg0 != NULL) {
    switch (arg0[1]) {
    case 0x8C:
        switch (arg0[2]) {
        case 0:
            break;
        case 1:
            p = __nw__5TItemFUl(0x20C);
            if (p != NULL) {
                p = init_vtable_and_handlers_341__13TUnk_804E1F04Fv(p, tl_05, arg0);
            }
            return p;
        case 2:
            p = __nw__5TItemFUl(0x20C);
            if (p != NULL) {
                p = init_type_447__13TUnk_804E22F4Fv(p, tl_05, arg0);
            }
            return p;
        case 3:
            p = __nw__5TItemFUl(0x254);
            if (p != NULL) {
                p = init_mag_effect_state__10TObjPlayerFPv(p, tl_05, arg0);
            }
            return p;
        }
        break;
    case 0x93:
        p = __nw__5TItemFUl(0x20C);
        if (p != NULL) {
            p = enter_state_341__13TUnk_804E2000Fv(p, tl_05, arg0);
        }
        return p;
    case 0xA4:
        p = __nw__5TItemFUl(0x20C);
        if (p != NULL) {
            p = init_needle_effect__10TObjPlayerFPv(p, tl_05, arg0);
        }
        return p;
    case 0x96:
        p = __nw__5TItemFUl(0x20C);
        if (p != NULL) {
            p = setup_state__10TObjPlayerFPv(p, tl_05, arg0);
        }
        return p;
    }
    p = __nw__5TItemFUl(0x20C);
    if (p != NULL) {
        p = init_vtable_and_field200__10TObjPlayerFPv(p, tl_05, arg0);
    }
    return p;
    }
    return NULL;
}

void *__dt__13TUnk_804E1E08Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E1E08;
        __dt__13TUnk_804E23F0Fv(arg0, (s16)(0));
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern s32 lbl_804E1F04[];

void *__dt__13TUnk_804E1F04Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E1F04;
        __dt__13TUnk_804E23F0Fv(arg0, (s16)(0));
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern s32 lbl_804E2000[];

void *__dt__13TUnk_804E2000Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E2000;
        __dt__13TUnk_804E23F0Fv(arg0, (s16)(0));
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern s32 lbl_804E20FC[];

void *__dt__13TUnk_804E20FCFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E20FC;
        __dt__13TUnk_804E23F0Fv(arg0, (s16)(0));
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern s32 lbl_804E21F8[];

void *__dt__13TUnk_804E21F8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E21F8;
        __dt__13TUnk_804E23F0Fv(arg0, (s16)(0));
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern s32 lbl_804E22F4[];

void *__dt__13TUnk_804E22F4Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E22F4;
        __dt__13TUnk_804E23F0Fv(arg0, (s16)(0));
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern s32 lbl_804E23F0[];

void *__dt__13TUnk_804E23F0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E23F0;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

}
