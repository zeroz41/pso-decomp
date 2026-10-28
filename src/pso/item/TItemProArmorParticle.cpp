#include "types.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804A05C8.h"
#include "pso/item/TItemProArmorParticle.h"
#include "pso/item/TItemProShield.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/CurrentArea.h"

struct RecoveredGlobal_803646F0_lbl_8047A020 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_803646F0___vt__21TItemProArmorParticle {
    s32 value;
    u8 remaining[0xCC];
};

extern "C" {
u8 * TItemProArmor__ct(void *, void *);
extern RecoveredGlobal_803646F0_lbl_8047A020 TItemProArmorParticle__particle_id_table;
extern s32 __vt__21TItemProArmorParticle[];
extern s32 TItemProArmorParticle__class_name;
u8 *TItemProArmorParticle__ct(TItemProArmorParticle *arg0, u8 *arg1);
void *__dt__21TItemProArmorParticleFv(void *arg0, s16 arg1);
s32 __ct__21TItemEffArmorParticleFP7TObjectlll(u32, s32, s32, s32, s32);
s32 on_unequip__14TItemEquipBaseFv();
s32 on_equip__13TItemProArmorFv();
void TItemTimerEvent__ct(void *);
s32 is_item_area_enabled();
void *__dt__13TItemProArmorFv(void *arg0, s16 arg1);
u32 __nw__7TObjectFUl(s32);
s32 __nw__15TItemHeapObjectFUl(s32);
s32 get_owner_client__5TItemFv(void *);

void TItemProArmorParticle::create(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 obj;
    if ((arg0 != 0) && ((obj = __nw__7TObjectFUl(0x2C)) != 0U)) {
        __ct__21TItemEffArmorParticleFP7TObjectlll(obj, arg0, arg1, arg2, arg3);
    }
}

extern s32 tl_05;

void TItemProArmorParticle::update_equipped() {
    s32 temp_r3;
    s32 temp_r31;

    if ((s32) this->m_1a0 == 2) {
        temp_r3 = get_current_area();
        if (temp_r3 != (s32) this->m_198) {
            this->m_198 = temp_r3;
            if (is_item_area_enabled() != 0) {
                TItemProArmorParticle::create(tl_05, (s32)(this->get_item_id()), (s32)(get_owner_client__5TItemFv(this)), this->m_19c);
            }
        }
    }
}

void TItemProArmorParticle::on_unequip() {
    if ((s32) this->m_1a0 == 2) {
        this->m_198 = -1;
    }
    on_unequip__14TItemEquipBaseFv();
}

void TItemProArmorParticle::on_equip() {
    s32 temp_r3;

    on_equip__13TItemProArmorFv();
    if (((s32) this->m_1a0 == 1) && ((u32) this->effect_objects != 0U)) {
        temp_r3 = __nw__15TItemHeapObjectFUl(0x30);
        if (temp_r3 != 0) {
            ((TUnk_804A05C8 *)temp_r3)->initialize((void *)this->effect_objects, (void *)(get_owner_client__5TItemFv(this)), (void *)(0x78), (void *)this->m_19c);
        }
    }
}

extern s32 lbl_804A05C8[];

typedef char RecoveredGlobal_803646F0_lbl_8047A020_size[sizeof(RecoveredGlobal_803646F0_lbl_8047A020) == 0x30 ? 1 : -1];
typedef char RecoveredGlobal_803646F0___vt__21TItemProArmorParticle_size[sizeof(RecoveredGlobal_803646F0___vt__21TItemProArmorParticle) == 0xD0 ? 1 : -1];
u8 *TItemProArmorParticle__ct(TItemProArmorParticle *item_pro_armor_particle, u8 *arg1) {
    u8 temp_r0;
    TItemProArmor__ct(item_pro_armor_particle, arg1);
    *(s32 **)((s8 *)item_pro_armor_particle + 0x18) = &(*(RecoveredGlobal_803646F0___vt__21TItemProArmorParticle *)&__vt__21TItemProArmorParticle).value;
    *(s32 *)((s8 *)item_pro_armor_particle + 0) = (s32) TItemProArmorParticle__class_name;
    item_pro_armor_particle->m_198 = -1;
    temp_r0 = ((TItem *)item_pro_armor_particle)->get_item_index() - 0x29;
    if (temp_r0 < 0xCU) {
        item_pro_armor_particle->m_19c = (s32) *(s32 *)((s8 *)&TItemProArmorParticle__particle_id_table.value + ((temp_r0 * 4) & 0x3FC));
        if (temp_r0 < 5U) {
            item_pro_armor_particle->m_1a0 = 1;
        } else {
            item_pro_armor_particle->m_1a0 = 2;
        }
    } else {
        item_pro_armor_particle->m_19c = 0;
        item_pro_armor_particle->m_1a0 = 0;
    }
    return (u8 *)item_pro_armor_particle;
}

void *TUnk_804A05C8::initialize(void *arg1, void *arg2, void *arg3, void *arg4) {
    TItemTimerEvent__ct(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A05C8;
    (*(void * *)&this->unk_2C) = arg4;
    return this;
}

void *__dt__21TItemProArmorParticleFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__21TItemProArmorParticle;
        __dt__13TItemProArmorFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

}
