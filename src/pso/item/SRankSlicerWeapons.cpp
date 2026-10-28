#include "types.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TUnk_804A4238.h"
#include "pso/item/TUnk_804A4338.h"
#include "pso/items/TItemWeapon.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
struct TItemEquipBase;

#include "pso/misc/TTecSlicer.h"
#include "pso/TItemAttacker.h"

 extern void *s_rank_j_cutter_weapon_vtable[64]; extern void *s_rank_slicer_weapon_vtable[64];
struct Owner_801293FC { u8 pad[0x60]; s32 f60; };

struct Self_801293FC { u8 pad0[0x24]; s32 f24; u8 pad28[0xF0 - 0x28]; Owner_801293FC *owner; u8 padF4[0x188 - 0xF4]; s32 f188; };

struct Vec_801293FC { f32 x, y, z; };

struct Tec_801293FC {
    s16 id;
    u8 pad2[2];
    s32 f4;
    s32 f8;
    s32 fC;
    s16 f10;
    s16 f12;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    s32 f28;
    u8 pad2C[4];
    Vec_801293FC pos;
    Vec_801293FC dir;
};

extern "C" {
s16 get_entity_id(void *);
f32 query_extended_state__10TObjPlayerFv(void *);
void TObjPlayer__sub_80128A70(void);
void init_slicer_launch_state(void *);
s16 get_validated_attack_stage(u8 *arg0);
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);
}
void enlarge_s_rank_j_cutter_blade(void *);
extern const f32 lbl_805DAE18;
extern const f32 lbl_805DAE1C;
extern const f32 lbl_805DAE20;
extern const f32 lbl_805DAE24;
extern "C" {
void emit_marker_effects__13TUnk_804A4238Fv(Self_801293FC *self);
void TUnk_804A4238::emit_marker_effects() {
    Self_801293FC *self = (Self_801293FC *)this;
    Tec_801293FC tec;
    TObjPlayer__sub_80128A70();
    init_slicer_launch_state(&tec);
    tec.id = get_entity_id(self->owner);
    tec.fC = ((TItem *)self)->get_item_id();
    tec.f4 = self->f24;
    tec.f8 = self->f188;
    tec.f10 = TObjPlayer__sub_801D2F4C((s16 *)((u8 *)self->owner + 0x7CC));
    tec.f12 = get_validated_attack_stage((u8 *)self->owner + 0x7CC);
    tec.f14 = query_extended_state__10TObjPlayerFv(self->owner);
    tec.f18 = lbl_805DAE18;
    tec.f1C = lbl_805DAE1C;
    tec.f20 = lbl_805DAE20;
    tec.f24 = lbl_805DAE24;
    tec.f28 = self->owner->f60;
    ((TObjPlayer *)self)->draw_icon(3, (s32)&tec.pos);
    ((TObjPlayer *)self)->draw_icon(2, (s32)&tec.dir);
    TItemAttacker::spawn_item_timer((s32)(TTecSlicer::create((u16*)&tec)), (s32)enlarge_s_rank_j_cutter_blade, 3);
}

void *__dt__13TUnk_804A4238Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804A4948Fv(void *arg0, s16 arg1);

void *__dt__13TUnk_804A4238Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void ***)((s8 *)arg0 + 0x18) = s_rank_j_cutter_weapon_vtable;
        __dt__13TUnk_804A4948Fv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
void construct_srank_weapon(void *);
}
void *construct_s_rank_j_cutter_weapon(void *arg0, s32 task_root, void *owner);
void *construct_s_rank_j_cutter_weapon(void *player, s32 task_root, void *owner) {
    construct_srank_weapon(player);
    *(void ***)((s8 *)player + 0x18) = s_rank_j_cutter_weapon_vtable;
    ((TObjPlayer *)player)->set_status_flags(2);
    return player;
}

void *construct_s_rank_j_cutter_weapon(void *, s32, void *);
extern "C" {
u8 *__nw__5TItemFUl(s32);
}
extern s32 tl_05;
u8 *create_s_rank_j_cutter_weapon(u8 *arg0);
u8 *create_s_rank_j_cutter_weapon(u8 *owner) {
    u8 *temp_r3;
    u8 *var_r0;
    if (owner != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(construct_s_rank_j_cutter_weapon(temp_r3, tl_05, owner));
        }
        return var_r0;
    }
    return NULL;
}

void enlarge_s_rank_j_cutter_blade(void *arg0);

extern const f32 lbl_805DAE28;

void enlarge_s_rank_j_cutter_blade(void *arg0) {
    if (arg0 != NULL) {
        *(f32 *)((s8 *)arg0 + 0x68) = (f32) lbl_805DAE28;
        *(f32 *)((s8 *)arg0 + 0x6C) = (f32) lbl_805DAE28;
        *(f32 *)((s8 *)arg0 + 0x70) = (f32) lbl_805DAE28;
    }
}

struct SlicerState_801295FC {
    u16 id;
    u8 pad0[2];
    s32 count;
    u8 pad1[4];
    s32 owner;
    s16 a;
    s16 b;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    u8 pad2[4];
    s32 angle;
};

struct Owner_80129648 { u8 pad[0x60]; s32 f60; };

struct Self_80129648 { u8 pad0[0x24]; s32 f24; u8 pad28[0xF0 - 0x28]; Owner_80129648 *owner; u8 padF4[0x188 - 0xF4]; s32 f188; };

struct Vec_80129648 { f32 x, y, z; };

struct Tec_80129648 {
    s16 id;
    u8 pad2[2];
    s32 f4;
    s32 f8;
    s32 fC;
    s16 f10;
    s16 f12;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    s32 f28;
    u8 pad2C[4];
    Vec_80129648 pos;
    Vec_80129648 dir;
};

extern const f32 lbl_805DAE2C;
extern const f32 lbl_805DAE30;
extern const f32 lbl_805DAE34;
extern const f32 lbl_805DAE38;
extern const f32 lbl_805DAE3C;
extern "C" {
void emit_marker_effects__13TUnk_804A4338Fv(Self_80129648 *self);
void init_slicer_launch_state(void *arg0) {
    SlicerState_801295FC *s = (SlicerState_801295FC *)arg0;
    s->id = 0xFFFF;
    s->owner = -1;
    s->count = 0;
    s->a = -1;
    s->b = -1;
    s->f14 = lbl_805DAE18;
    s->f24 = lbl_805DAE2C;
    s->f20 = lbl_805DAE2C;
    s->f1C = lbl_805DAE2C;
    s->f18 = lbl_805DAE2C;
    s->angle = -0x2AAA;
}
struct SlicerState_801295FC;
void TUnk_804A4338::emit_marker_effects() {
    Self_80129648 *self = (Self_80129648 *)this;
    Tec_80129648 tec;
    TObjPlayer__sub_80128A70();
    init_slicer_launch_state((struct SlicerState_801295FC *)((SlicerState_801295FC *)&tec));
    tec.id = get_entity_id(self->owner);
    tec.fC = ((TItem *)self)->get_item_id();
    tec.f4 = self->f24;
    tec.f8 = self->f188;
    tec.f10 = TObjPlayer__sub_801D2F4C((s16 *)((u8 *)self->owner + 0x7CC));
    tec.f12 = get_validated_attack_stage((u8 *)self->owner + 0x7CC);
    tec.f14 = query_extended_state__10TObjPlayerFv(self->owner);
    tec.f18 = lbl_805DAE30;
    tec.f1C = lbl_805DAE34;
    tec.f20 = lbl_805DAE38;
    tec.f24 = lbl_805DAE3C;
    tec.f28 = self->owner->f60;
    ((TObjPlayer *)self)->draw_icon(1, (s32)&tec.pos);
    ((TObjPlayer *)self)->draw_icon(2, (s32)&tec.dir);
    TTecSlicer::create((u16*)&tec);
}
}

void *construct_s_rank_slicer_weapon(void *arg0, s32 task_root, void *owner);

void *construct_s_rank_slicer_weapon(void *player, s32 task_root, void *owner) {
    construct_srank_weapon(player);
    *(void ***)((s8 *)player + 0x18) = s_rank_slicer_weapon_vtable;
    ((TObjPlayer *)player)->set_status_flags(2);
    return player;
}

void *construct_s_rank_slicer_weapon(void *, s32, void *);
u8 *create_s_rank_slicer_weapon(u8 *arg0);
u8 *create_s_rank_slicer_weapon(u8 *owner) {
    u8 *temp_r3;
    u8 *var_r0;
    if (owner != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(construct_s_rank_slicer_weapon(temp_r3, tl_05, owner));
        }
        return var_r0;
    }
    return NULL;
}

extern "C" {

void *__dt__13TUnk_804A4338Fv(void *arg0, s16 arg1);

void *__dt__13TUnk_804A4338Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void ***)((s8 *)arg0 + 0x18) = s_rank_slicer_weapon_vtable;
        __dt__13TUnk_804A4948Fv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

}

extern "C" s8 get_attach_slot__14TItemEquipBaseFv(TItemEquipBase *arg0);
extern "C" void vfunc_60__11TItemWeaponFv();
extern "C" void vfunc_59__11TItemWeaponFv();
extern "C" void vfunc_58__11TItemWeaponFv();
extern "C" void update_weapon__11TItemWeaponFv();
extern "C" void reserved_53__11TItemWeaponFv();
extern "C" void update_idle__11TItemWeaponFv();
extern "C" void update_attack__11TItemWeaponFv();
extern "C" void activate_effect__11TItemWeaponFl();
extern "C" void update_owned__11TItemWeaponFv();
extern "C" void on_model_loaded__11TItemWeaponFv();
extern "C" void on_unequip__11TItemWeaponFv();
extern "C" u8 get_motion_type__11TItemWeaponFv(void *p);
extern "C" void write_item_data__11TItemWeaponFP9TItemData();
extern "C" void snap_to_owner__5TItemFv();
extern "C" void update_in_inventory__5TItemFv();
extern "C" int feed__5TItemFP9TItemData(void);
extern "C" void add_slot__5TItemFv();
extern "C" int update_object_view_visibility__5TItemFff(void *p);
extern "C" void vfunc_6__13TUnk_804B9870FPsl();
extern "C" void srank_marker_noop();
void receive_srank_hit(TItemWeapon *arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4, f32 farg0);
extern "C" void add_equip_stats__14TItemEquipBaseFl();
extern "C" void on_equip__11TItemWeaponFv();
extern "C" void apply_object_set_data__13TUnk_804B9870FPv();
extern "C" void apply_owner_bonuses__11TItemWeaponFv();
extern "C" void classify_actor_view_detail__13TUnk_804B9870Ffff();
extern "C" void start_srank_regen_timer__10TObjPlayerFv();
extern "C" void perform_action__11TItemWeaponFv();
extern "C" void use__5TItemFv();
extern "C" void render__5TItemFv();
extern "C" void render_equipped_shadow__11TItemWeaponFv();
extern "C" void render_equipped__11TItemWeaponFv();
extern "C" void equip__14TItemEquipBaseFv();
extern "C" void get_attack_flags__11TItemWeaponFv();
extern "C" void get_center__11TItemWeaponFv();
extern "C" void launch_shot__11TItemWeaponFPUclll();
extern "C" void request_equipped_model__11TItemWeaponFv();
extern "C" void get_name__5TItemFv();
extern "C" void reset_motion_fields__13TUnk_804AF8A0Fv();
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
extern "C" void subtract_equip_stats__14TItemEquipBaseFPvPsPs();
extern "C" void subtract_item_stat_bonus__14TItemEquipBaseFllPs();
extern "C" void interact__5TItemFl();
extern "C" void unequip__14TItemEquipBaseFv();
extern "C" void update_equipped__11TItemWeaponFv();
extern "C" void destroy__14TItemEquipBaseFv();
extern "C" void refresh_special__11TItemWeaponFv();
extern "C" void is_identified__11TItemWeaponFv();
extern "C" void render_equipped_deferred__11TItemWeaponFv();
extern "C" {
void *s_rank_j_cutter_weapon_vtable[64] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__13TUnk_804A4238Fv, (void *)&run_task__5TItemFv,
    (void *)&render__5TItemFv, (void *)&render_shadows__5TItemFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804AF8A0Fv, (void *)&get_center__11TItemWeaponFv, (void *)&update_object_view_visibility__5TItemFff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
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
    (void *)&emit_marker_effects__13TUnk_804A4238Fv, (void *)&update_attack__11TItemWeaponFv, (void *)&update_idle__11TItemWeaponFv, (void *)&reserved_53__11TItemWeaponFv,
    (void *)&update_weapon__11TItemWeaponFv, (void *)&start_srank_regen_timer__10TObjPlayerFv, (void *)&vfunc_58__11TItemWeaponFv, (void *)&vfunc_59__11TItemWeaponFv,
    (void *)&vfunc_60__11TItemWeaponFv, (void *)&receive_srank_hit, (void *)&srank_marker_noop, (void *)0x0,
};
void *s_rank_slicer_weapon_vtable[64] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__13TUnk_804A4338Fv, (void *)&run_task__5TItemFv,
    (void *)&render__5TItemFv, (void *)&render_shadows__5TItemFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804AF8A0Fv, (void *)&get_center__11TItemWeaponFv, (void *)&update_object_view_visibility__5TItemFff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
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
    (void *)&emit_marker_effects__13TUnk_804A4338Fv, (void *)&update_attack__11TItemWeaponFv, (void *)&update_idle__11TItemWeaponFv, (void *)&reserved_53__11TItemWeaponFv,
    (void *)&update_weapon__11TItemWeaponFv, (void *)&start_srank_regen_timer__10TObjPlayerFv, (void *)&vfunc_58__11TItemWeaponFv, (void *)&vfunc_59__11TItemWeaponFv,
    (void *)&vfunc_60__11TItemWeaponFv, (void *)&receive_srank_hit, (void *)&srank_marker_noop, (void *)0x0,
};
#define s_rank_j_cutter_weapon_vtable ((s32 *)s_rank_j_cutter_weapon_vtable)
#define s_rank_slicer_weapon_vtable ((s32 *)s_rank_slicer_weapon_vtable)
__declspec(section ".sdata2") const f32 lbl_805DAE18 = 1.0f;
__declspec(section ".sdata2") const f32 lbl_805DAE1C = 0.6f;
__declspec(section ".sdata2") const f32 lbl_805DAE20 = 0.5f;
__declspec(section ".sdata2") const f32 lbl_805DAE24 = 0.3f;
__declspec(section ".sdata2") const f32 lbl_805DAE28 = 1.6f;
__declspec(section ".sdata2") const f32 lbl_805DAE2C = 0.0f;
__declspec(section ".sdata2") const f32 lbl_805DAE30 = 1.0f;
__declspec(section ".sdata2") const f32 lbl_805DAE34 = 0.6f;
__declspec(section ".sdata2") const f32 lbl_805DAE38 = 0.5f;
__declspec(section ".sdata2") const f32 lbl_805DAE3C = 0.3f;
}
