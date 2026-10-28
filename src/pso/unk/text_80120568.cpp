#include "types.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItem.h"
#include "pso/items/TItemWeapon.h"
#include "pso/TItemAttacker.h"
#include "pso/TItemEffEquip.h"
#include "pso/item/TItemMag.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/CurrentArea.h"
struct Pair_801205F4 { u8 a; s8 b; };

struct Data_801205F4 { u8 pad[0x27]; u8 flags; };

struct Self_801205F4 { u8 pad[0xf0]; void *f0; u8 padf4[0x1a4 - 0xf4]; Pair_801205F4 pairs[3]; u8 pad1aa[0x1dc - 0x1aa]; Data_801205F4 *data; };

struct Ctl_80120568B { char pad[0x18]; };

struct Ctl_80120568 : Ctl_80120568B {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual u32 m64(s32);
};

struct Pl_80120568B { char pad[0x18]; };

struct Pl_80120568 : Pl_80120568B {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual s8 m31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void m56();
    u8 pad[0xF0-0x1C+0x0];
    Ctl_80120568 *ctl;
};

struct VBase_8012065C { u8 pad[0x18]; };

struct Player_8012065C : VBase_8012065C {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40();
    virtual u8 v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56();
    virtual void v57();
};

extern "C" {
void clear_technique_boosts__14TItemEquipBaseFv(s32 arg0);
s32 get_entity_id(s32);
s32 test_flags_any(void *, s32);
s32 obj_isState7_324(s32);
s32 update_technique_slot__10TTecRaFoieFl(s32, s32, s32);
s32 play_sound_effect(s32, s32, s32, s32);
void set_flag_8_if_check_passes__10TObjPlayerFv();
extern void *tl_05;

void TItemWeapon::on_unequip() {
    Pl_80120568 *arg0 = (Pl_80120568 *)this;
    if (arg0->ctl->m64(arg0->m31()) == 0) {
        ((TObjPlayer *)(arg0->ctl))->set_action_provider_variant(0);
    }
    arg0->m56();
    clear_technique_boosts__14TItemEquipBaseFv((s32)arg0);
    ((TItemWeapon *)arg0)->clear_weapon_flags(0x03000000);
}

void TItemWeapon::apply_owner_bonuses() {
    Self_801205F4 *self = (Self_801205F4 *)this;
    s32 i;
    ((TItemWeapon *)self)->apply_model_params();
    if (!(self->data->flags & 8)) {
        for (i = 0; i != 3; i++) {
            ((TObjPlayer *)(self->f0))->set_attribute_entry(i, &self->pairs[i]);
        }
    }
}
void TItemWeapon::on_equip() {
    Player_8012065C *arg0 = (Player_8012065C *)this;
    if (test_flags_any((u8 *)arg0 + 0x178, 1) != 0) {
        if (!(((TItem *)arg0)->get_item_flags() & 0x20) && are_items_enabled_here() != 0) {
            ((TObjPlayer *)(*(void **)((s8 *)arg0 + 0xF0)))->set_action_provider_variant(arg0->v41());
        }
        ((TItemWeapon *)arg0)->clear_weapon_flags(0x100);
        if (((TItem *)arg0)->is_hidden() != 0 || obj_isState7_324(*(s32 *)((s8 *)arg0 + 0xF0)) != 0) {
            ((TItemWeapon *)arg0)->set_weapon_flags(8);
        } else {
            TItemAttacker::spawn_item_timer((s32)arg0, (s32)((void *)&set_flag_8_if_check_passes__10TObjPlayerFv), 0x14);
            TItemEffEquip::create((void *)tl_05, (void *)(get_entity_id(*(s32 *)((s8 *)arg0 + 0xF0))), (void *)0x30, (void *)0x9D, (void *)0x9E);
            if (((TItemWeapon *)arg0)->test_weapon_flags(0x200) != 0U) {
                TItemEffEquip::create((void *)tl_05, (void *)(get_entity_id(*(s32 *)((s8 *)arg0 + 0xF0))), (void *)0x23, (void *)0x9D, (void *)0x9E);
            }
            update_technique_slot__10TTecRaFoieFl(play_sound_effect(0x4000B20A, *(s32 *)((s8 *)arg0 + 0xF0) + 0x38, 0, 0), 0x300, 0);
        }
    } else {
        ((TObjPlayer *)(*(void **)((s8 *)arg0 + 0xF0)))->set_action_provider_variant(0);
        ((TItemWeapon *)arg0)->set_weapon_flags(0x100);
        ((TItemWeapon *)arg0)->set_weapon_flags(8);
    }
    arg0->v55();
    ((TItemWeapon *)arg0)->clear_weapon_flags(0x03000000);
}

}
