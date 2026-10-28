#include "types.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/object/TObjMotion.h"
#include "pso/item/TItemEquipVariant_8012A82C.h"
#include "pso/item/TItem.h"
#include "pso/item/WeaponAttackActions.h"
#include "pso/player/TObjPlayer_8012105C.h"
#include "pso/player/TObjPlayer_801283B8.h"
#include "pso/unk/text_8012A418.h"
#include "pso/unk/text_8012A884.h"
#include "pso/unk/TUnk_804A4948.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemProShield.h"
#include "pso/items/TItemWeapon.h"

struct Self_8012A884 { u8 pad[0x18]; void *vt; u8 pad1C[0x1F8 - 0x1C]; u32 kind; };

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
void TItemWeapon__ct(void *);

struct Inc_8012A884;
extern "C" s8 get_attach_slot__14TItemEquipBaseFv(TItemEquipBase *arg0);
extern "C" void vfunc_6__13TUnk_804B9870FPsl();
extern "C" void update_weapon__11TItemWeaponFv();
extern "C" void reserved_53__11TItemWeaponFv();
extern "C" void update_attack__11TItemWeaponFv();
extern "C" void vfunc_17__11TItemWeaponFl();
extern "C" void vfunc_14__11TItemWeaponFv();
extern "C" void on_model_loaded__11TItemWeaponFv();
extern "C" void TItemWeapon__write_item_data();
extern "C" void on_unequip__11TItemWeaponFv();
extern "C" void emit_marker_effects__13TUnk_804A4948Fv();
extern "C" void add_equip_stats__14TItemEquipBaseFl();
extern "C" void on_equip__11TItemWeaponFv();
extern "C" void apply_object_set_data__13TUnk_804B9870FPv();
extern "C" void apply_owner_bonuses__11TItemWeaponFv();
extern "C" void classify_actor_view_detail__13TUnk_804B9870Ffff();
extern "C" void start_srank_regen_timer__10TObjPlayerFv();
extern "C" void perform_action__11TItemWeaponFv();
extern "C" void use__5TItemFv();
extern "C" void render__5TItemFv();
extern "C" void vfunc_27__11TItemWeaponFv();
extern "C" void vfunc_26__11TItemWeaponFv();
extern "C" void equip__14TItemEquipBaseFv();
extern "C" void get_attack_flags__11TItemWeaponFv();
extern "C" void get_motion_ptr__11TItemWeaponFv();
extern "C" void launch_shot__11TItemWeaponFPUclll();
extern "C" void request_equipped_model__11TItemWeaponFv();
extern "C" void get_name__5TItemFv();
extern "C" void reset_motion_fields__13TUnk_804AF8A0Fv();
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
extern "C" void vfunc_16__11TItemWeaponFv();
extern "C" void destroy__14TItemEquipBaseFv();
extern "C" void refresh_special__11TItemWeaponFv();
extern "C" void vfunc_28__11TItemWeaponFv();
void *s_rank_weapon_vtable[63] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__13TUnk_804A4948Fv, (void *)&run_task__5TItemFv,
    (void *)&render__5TItemFv, (void *)&render_shadows__5TItemFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804AF8A0Fv, (void *)&get_motion_ptr__11TItemWeaponFv, (void *)&update_object_view_visibility__5TItemFff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__5TItemFv, (void *)&interact__5TItemFl, (void *)&vfunc_14__11TItemWeaponFv, (void *)&update_in_inventory__5TItemFv,
    (void *)&vfunc_16__11TItemWeaponFv, (void *)&vfunc_17__11TItemWeaponFl, (void *)&TItemWeapon__write_item_data, (void *)&set_attach_slot__14TItemEquipBaseFSc,
    (void *)&equip__14TItemEquipBaseFv, (void *)&unequip__14TItemEquipBaseFv, (void *)&add_equip_stats__14TItemEquipBaseFl, (void *)&remove_equip_stats__14TItemEquipBaseFl,
    (void *)&subtract_item_stat_bonus__14TItemEquipBaseFllPs, (void *)&subtract_equip_stats__14TItemEquipBaseFPvPsPs, (void *)&vfunc_26__11TItemWeaponFv, (void *)&vfunc_27__11TItemWeaponFv,
    (void *)&vfunc_28__11TItemWeaponFv, (void *)&destroy__14TItemEquipBaseFv, (void *)&perform_action__11TItemWeaponFv, (void *)&use__5TItemFv,
    (void *)&get_attack_flags__11TItemWeaponFv, (void *)&get_attach_slot__14TItemEquipBaseFv, (void *)&refresh_special__11TItemWeaponFv, (void *)&TItemWeapon::copy_item_to_data,
    (void *)&get_amount__5TItemFv, (void *)&remove_amount__5TItemFl, (void *)&add_amount__5TItemFl, (void *)&get_slot_count__5TItemFv,
    (void *)&add_slot__5TItemFv, (void *)&feed__5TItemFP9TItemData, (void *)&snap_to_owner__5TItemFv, (void *)&TItemWeapon__sub_80121064,
    (void *)&on_equip__11TItemWeaponFv, (void *)&on_unequip__11TItemWeaponFv, (void *)&request_equipped_model__11TItemWeaponFv, (void *)&release_model__11TItemWeaponFv,
    (void *)&apply_owner_bonuses__11TItemWeaponFv, (void *)&remove_owner_bonuses__11TItemWeaponFv, (void *)&on_model_loaded__11TItemWeaponFv, (void *)&launch_shot__11TItemWeaponFPUclll,
    (void *)&emit_marker_effects__13TUnk_804A4948Fv, (void *)&update_attack__11TItemWeaponFv, (void *)&update_idle__11TItemWeaponFv, (void *)&reserved_53__11TItemWeaponFv,
    (void *)&update_weapon__11TItemWeaponFv, (void *)&start_srank_regen_timer__10TObjPlayerFv, (void *)&TItemWeapon__sub_8011E5C8, (void *)&TItemWeapon__sub_8011E5C4,
    (void *)&TItemWeapon__sub_8011E5C0, (void *)&receive_srank_hit, (void *)&srank_marker_noop,
};
#define s_rank_weapon_vtable ((u8 *)s_rank_weapon_vtable)

u8 *construct_srank_weapon(void *arg0, s32 arg1, void *arg2) {
    Self_8012A884 *self = (Self_8012A884 *)arg0;
    Inc_8012A884 *p;
    TItemWeapon__ct(self);
    self->vt = s_rank_weapon_vtable;
    ((TObjPlayer *)self)->set_status_flags(2);
    self->kind = ((TItem *)self)->get_item_index();
    p = (Inc_8012A884 *)arg0;
    switch (self->kind) {
    case 0:
    case 3:
    case 4:
        break;
    case 1:
    case 2:
        ((TObjPlayer *)p)->set_status_flags(0x400000);
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
