#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TUnk_804A4948.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012A82C.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/object/TObjMotion.h"
#include "pso/item/WeaponAttackActions.h"
#include "pso/player/TObjPlayer_8012105C.h"
#include "pso/player/TObjPlayer_801283B8.h"
#include "pso/unk/text_8012A418.h"
#include "pso/unk/text_8012A884.h"
#include "pso/item/TItemProShield.h"

struct VBase_18_24931d
{
  char pad[0x18];
};

struct VObj_18_24931d : VBase_18_24931d {
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
    virtual s32 m30();
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
    virtual s32 m49(s32 *, s32, s32, s32);
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
    virtual s32 m60();
};

struct Param_8012A508 { s32 kind; f32 val; };

struct VBase_8012A508 { char pad[0x18]; };

struct VObj_8012A508 : VBase_8012A508 {
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
    virtual void m21(u32, Param_8012A508 *, u8 *, s32, s32);
    u8 pad1c[0xA4 - 0x1C];
    u8 *recs;
};

struct Self_8012A508 { u8 pad[0xF0]; u32 fF0; u8 padF4[0x1F8 - 0xF4]; s32 mode; };

typedef struct Pl_8012A470
{
  u8 pad[0xF0];
  void *f0;
} Pl_8012A470;

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
s32 get_extended_state__10TObjPlayerFv(void *);
s32 get_captured_target_collider_index(s32);
s32 get_captured_target_entry(s32, s32);
s32 get_captured_target_count(s32 *arg0);
s32 resolve_hittable_target(s32, s32);


void TUnk_804A4948::send_srank_stat_extra_to_locks() {
  s32 st;
  s32 i;
  s32 e;
  u16 uid;
  s32 r;
  s32 v;
  st = get_extended_state__10TObjPlayerFv(((Pl_8012A470 *)this)->f0);
  if (st != 0)
  {
    for (i = 0; i != get_captured_target_count((s32 *)((((((((((((st & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF)); i++)
    {
      e = get_captured_target_entry(st, i);
      uid = ((TObjPlayer *)e)->get_uid();
      r = resolve_hittable_target(uid, v = (s16) ((unsigned long long) get_captured_target_collider_index(e)));
      if (r != 0)
      {
        this->send_srank_stat_extra(r, v);
      }
    }
  }
}

s32 TUnk_804A4948::send_srank_stat_extra(u32 arg1, s32 arg2) {
    Self_8012A508 *self = (Self_8012A508 *)this;
    VObj_8012A508 *obj = (VObj_8012A508 *)arg1;
    u32 f;
    Param_8012A508 t1;
    Param_8012A508 t2;
    if (obj != NULL && (f = self->fF0) != 0) {
        switch (self->mode) {
        case 1: {
            t1.kind = 0xB;
            t1.val = 16.0f;
            Param_8012A508 p = t1;
            obj->m21(f, &p, obj->recs + arg2 * 0x2C, -1, -1);
            break;
        }
        case 2: {
            t2.kind = 0xC;
            t2.val = 32.0f;
            Param_8012A508 p = t2;
            obj->m21(f, &p, obj->recs + arg2 * 0x2C, -1, -1);
            break;
        }
        }
    }
}
}
void receive_srank_hit(TItemWeapon *arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4, f32 farg0);
void receive_srank_hit(TItemWeapon *item_weapon, s32 arg1, u32 arg2, s32 arg3, s32 arg4, f32 farg0) {
    u32 f;
    if (item_weapon->get_mode() == 2) {
        f = *(u32 *)((s8 *)item_weapon + 0xF0);
        if ((f != 0U) && (arg2 != 0U)) {
            switch (*(s32 *)((s8 *)item_weapon + 0x1F8)) {
            case 1:
            case 2:
                if (arg3 == 2) {
                    ((TUnk_804A4948 *)item_weapon)->send_srank_stat_extra(arg2, arg4);
                } else {
                    item_weapon->TItemWeapon::deliver_hit((s32)f, (u8 *)arg2, (s32)arg3, (s32)arg4, (f32)farg0);
                }
                break;
            default:
                item_weapon->TItemWeapon::deliver_hit((s32)f, (u8 *)arg2, (s32)arg3, (s32)arg4, (f32)farg0);
                break;
            }
        }
    }
}
typedef struct VBase_18_24931d VBase_18_24931d;
typedef struct VObj_18_24931d VObj_18_24931d;
#define PSO_VCALL_VObj_18_24931d_m60(_self) (((VObj_18_24931d *)(_self))->m60())
#define PSO_VCALL_VObj_18_24931d_m30(_self) (((VObj_18_24931d *)(_self))->m30())
#define PSO_VCALL_VObj_18_24931d_m49(_self, _arg0, _arg1, _arg2, _arg3) (((VObj_18_24931d *)(_self))->m49((_arg0), (_arg1), (_arg2), (_arg3)))

void TUnk_804A4948::emit_marker_effects() {
    u8 *arg0 = (u8 *)this;
  s32 sp8;
  s32 temp_r0;
  s32 temp_r3;
  s32 new_var;
  PSO_VCALL_VObj_18_24931d_m60(arg0);
  temp_r3 = PSO_VCALL_VObj_18_24931d_m30(arg0);
  if (temp_r3 & 1)
  {
    temp_r0 = *((s32 *) (((s8 *) arg0) + 0x1F8));
    if (temp_r0 < 3)
    {
      if (temp_r0 < 1)
      {
        if ((arg0 && arg0) && arg0)
        {
        }
        goto block_7;
      }
      if (((TItemWeapon *)arg0)->is_mode_two_and_ready() != 0)
      {
        ((TUnk_804A4948 *)arg0)->send_srank_stat_extra_to_locks();
        return;
      }
      ((TObjPlayer *)arg0)->update_active_game_effect();
      return;
    }
    block_7:
    ((TObjPlayer *)arg0)->update_active_game_effect();
    return;
  }
  if ((new_var = temp_r3) & 2)
  {
    ((TItemWeapon *)arg0)->get_gun_point(&sp8);
    PSO_VCALL_VObj_18_24931d_m49(arg0, &sp8, 0, 0, 1);
  }
}

extern "C" {

s32 get_owner_client__5TItemFv(void *);
s32 init_item_timer_event__13TUnk_804A0648Fv(s32, s32, s32, s32);
s32 __nw__15TItemHeapObjectFUl(s32);
s32 construct_timer_event__13TUnk_804A0628Fv(s32, s32, s32, s32);

void TObjPlayer::start_srank_regen_timer() {
    s32 temp_r3;
    s32 temp_r3_2;

    switch (*(s32 *)&this->unk_1F8) {
    case 3:
        temp_r3 = __nw__15TItemHeapObjectFUl(0x2C);
        if (temp_r3 != 0) {
            init_item_timer_event__13TUnk_804A0648Fv(temp_r3, *(s32 *)((s8 *)this + 0x174), get_owner_client__5TItemFv(this), 0x5A);
        }
        return;
    case 4:
        temp_r3_2 = __nw__15TItemHeapObjectFUl(0x2C);
        if (temp_r3_2 != 0) {
            construct_timer_event__13TUnk_804A0628Fv(temp_r3_2, *(s32 *)((s8 *)this + 0x174), get_owner_client__5TItemFv(this), 0x5A);
        }
        break;
    }
}

}

extern void *s_rank_weapon_vtable[];

void *__dt__13TUnk_804A4948Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)s_rank_weapon_vtable;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

struct Self_8012A884 { u8 pad[0x18]; void *vt; u8 pad1C[0x1F8 - 0x1C]; u32 kind; };

extern "C" {
void __ct__11TItemWeaponFP7TObjectPUc(void *);

struct Inc_8012A884;
extern "C" s8 get_attach_slot__14TItemEquipBaseFv(TItemEquipBase *arg0);
extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void update_weapon__11TItemWeaponFv();
extern "C" void reserved_53__11TItemWeaponFv();
extern "C" void update_attack__11TItemWeaponFv();
extern "C" void activate_effect__11TItemWeaponFl();
extern "C" void update_owned__11TItemWeaponFv();
extern "C" void on_model_loaded__11TItemWeaponFv();
extern "C" void write_item_data__11TItemWeaponFP9TItemData();
extern "C" void on_unequip__11TItemWeaponFv();
extern "C" void emit_marker_effects__13TUnk_804A4948Fv();
extern "C" void add_equip_stats__14TItemEquipBaseFl();
extern "C" void on_equip__11TItemWeaponFv();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void apply_owner_bonuses__11TItemWeaponFv();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
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
extern "C" void reset_motion_fields__14TObjCollidableFv();
extern "C" void add_amount__5TItemFl();
extern "C" void add_slot__5TItemFv();
extern "C" void feed__5TItemFP9TItemData();
extern "C" void get_amount__5TItemFv();
extern "C" void get_slot_count__5TItemFv();
extern "C" void remove_amount__5TItemFl();
extern "C" void snap_to_owner__5TItemFv();
extern "C" void update_object_view_visibility__5TItemFff();
extern "C" void update_in_inventory__5TItemFv();
extern "C" void remove_equip_stats__14TItemEquipBaseFl();
extern "C" void render_shadows__5TItemFv();
extern "C" void remove_owner_bonuses__11TItemWeaponFv();
extern "C" void release_model__11TItemWeaponFv();
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
void *s_rank_weapon_vtable[63] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__13TUnk_804A4948Fv, (void *)&run_task__5TItemFv,
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
    (void *)&emit_marker_effects__13TUnk_804A4948Fv, (void *)&update_attack__11TItemWeaponFv, (void *)&update_idle__11TItemWeaponFv, (void *)&reserved_53__11TItemWeaponFv,
    (void *)&update_weapon__11TItemWeaponFv, (void *)&start_srank_regen_timer__10TObjPlayerFv, (void *)&vfunc_58__11TItemWeaponFv, (void *)&vfunc_59__11TItemWeaponFv,
    (void *)&vfunc_60__11TItemWeaponFv, (void *)&receive_srank_hit, (void *)&srank_marker_noop,
};
#define s_rank_weapon_vtable ((u8 *)s_rank_weapon_vtable)

u8 *construct_srank_weapon(void *arg0, s32 arg1, void *arg2) {
    Self_8012A884 *self = (Self_8012A884 *)arg0;
    Inc_8012A884 *p;
    __ct__11TItemWeaponFP7TObjectPUc(self);
    self->vt = s_rank_weapon_vtable;
    ((TItemWeapon *)self)->set_weapon_flags(2);
    self->kind = ((TItem *)self)->get_item_index();
    p = (Inc_8012A884 *)arg0;
    switch (self->kind) {
    case 0:
    case 3:
    case 4:
        break;
    case 1:
    case 2:
        ((TItemWeapon *)p)->set_weapon_flags(0x400000);
        ((TUnk_804A4948 *)self)->set_special_selector(0x1A);
        break;
    case 5:
        ((TUnk_804A4948 *)p)->set_special_selector(0x1A);
        break;
    case 6:
        ((TUnk_804A4948 *)p)->set_special_selector(0x1E);
        break;
    case 7:
        ((TUnk_804A4948 *)p)->set_special_selector(0x12);
        break;
    case 8:
        ((TUnk_804A4948 *)p)->set_special_selector(0x16);
        break;
    case 9:
        ((TUnk_804A4948 *)p)->set_special_selector(0x26);
        break;
    case 10:
        ((TUnk_804A4948 *)p)->set_special_selector(0x22);
        break;
    case 11:
        ((TUnk_804A4948 *)p)->set_special_selector(0xD);
        break;
    case 12:
        ((TUnk_804A4948 *)p)->set_special_selector(0xE);
        break;
    case 13:
        ((TUnk_804A4948 *)p)->set_special_selector(0x28);
        break;
    case 14:
        ((TUnk_804A4948 *)p)->set_special_selector(4);
        break;
    case 15:
        ((TUnk_804A4948 *)p)->set_special_selector(8);
        break;
    case 16:
        ((TUnk_804A4948 *)p)->set_special_selector(0xB);
        break;
    default:
        ((TUnk_804A4948 *)p)->set_special_selector(0);
        break;
    }
    return (u8 *)self;
}

u8 *TObjPlayer::create_srank_common_weapon() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(construct_srank_weapon(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
