#include "types.h"
#include "pso/item/TItemLoad_80110010.h"
#include "pso/system/vector.h"
#include "pso/item/TItemData.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/items/TItemWeapon.h"

struct Row_8010A89C { s8 id; u8 level; f32 amount; };
struct Slot_8010A89C { s16 id; s16 level; f32 amount; };

#include <stddef.h>
struct Stack_8010A710 {
    s32 sp8;
    f32 spC;
    u8 trailing_storage[0x4];
};

#include "pso/TAdRicoRing.h"
#include "pso/TItemLoad.h"
#include "pso/TObject.h"
#include "pso/item/TItemProShield.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TOSwitchItem.h"
#include "pso/misc/TQuestListVM.h"

struct VBase_18_8e31a0
{
  char pad[0x18];
};

struct VObj_18_8e31a0 : VBase_18_8e31a0 {
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
    virtual s32 m23(s32, s32, s32);
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
    virtual s32 m47();
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
    virtual s32 m71();
};

struct RecoveredFields_8010B0A8_arg0
{
  u8 unknown_0[0xF0];
  u8 *field_F0;
  u8 unknown_F4[0x78];
  s16 field_16C;
  s16 field_16E;
};

struct RecoveredGlobal_8010B684___vt__14TItemEquipBase { s32 value; u8 remaining[0xCC]; };
typedef char RecoveredGlobal_8010B684___vt__14TItemEquipBase_size[sizeof(RecoveredGlobal_8010B684___vt__14TItemEquipBase) == 0xD0 ? 1 : -1];

struct VBase_18_b34251 { char pad[0x18]; };

struct VObj_18_b34251 : VBase_18_b34251 {
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
    virtual s8 m31();
};

struct RecoveredGlobal_8010AD24_lbl_804C3BA8 {
    s32 value;
    u8 remaining[0x10];
};

struct ItemData_8010AEFC { u8 data[0x14]; };

struct Stats_8010AEFC { s16 v[7]; u8 pad[0x16]; };

struct Equip_8010AEFC { u8 pad0[0xF0]; s32 m_f0; };

struct ItemData_8010B224 { u8 data[0x14]; };

struct VBase_8010B224 { char pad[0x18]; };

struct VObj_8010B224 : VBase_8010B224 {
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
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
};

extern "C" {
s32 get_owner_client__5TItemFv(void *);
s32 apply_equip_slot_effect__14TItemEquipBaseFUsUl(s32, int);
s32 start_event_by_index__15TItemTimerEventFUs();
void *TItemEquipBase__sub_8010B73C(void *p);
s32 TItemEquipBase__sub_8022C680(void *, void *, void *);
void TItemEquipBase__sub_8010A82C(s32 arg0);
s32 test_flags_any(void *, void *);
s32 TItemEquipBase__sub_8010AC60(s32 arg0, s32 arg1, s32 arg2);
s32 spawn_particle_effect(void *, int);
u8 *resolve_hittable_target(s32, s32);
void play_target_impact_effect(s32 arg0, s32 arg1, s32 arg2, s16 arg3);
s32 apply_equip_effect_slot__14TItemEquipBaseFUsUl(void *, int);
s32 clear_timer_slot__15TItemTimerEventFUs(void *);
s32 init__9TItemDataFv(void *);
s32 add_actor_tp_bonus(void *, int);
s32 add_actor_hp_bonus(void *, int);
s32 TItemData__sub_8010B808(void *);
s32 TItemData__sub_8010B810(int);
s32 __nw__15TItemHeapObjectFUl(int);
s32 __ct__15TItemHeapObjectFP7TObject(int, void *);
extern s32 __vt__14TItemEquipBase[];
extern s32 item_equip_base_class_name;
u8 *TItemEquipBase__ct(u8 *arg0, s32 arg1, s32 arg2);
extern RecoveredGlobal_8010AD24_lbl_804C3BA8 item_equip_attach_equip_flag_table;
int memset(void*, void*, void*);
s32 get_attack_params_atp_min(void *);
s32 TObjPlayer__sub_800194E8(void *);
s32 get_attack_params_atp_max(void *);
s16 add_lck__10TObjPlayerFl(void *, int);
s16 add_evp__10TObjPlayerFl(void *, int);
s16 add_ata__10TObjPlayerFl(void *, int);
s16 add_mst__10TObjPlayerFl(void *, int);
s16 add_hp__10TObjPlayerFl(void *, int);
s16 add_dfp__10TObjPlayerFl(void *, int);
s16 add_stat__10TObjPlayerFl(void *, int);
struct Base_8010B054_8010A710 { char pad[0x18]; };
struct VObj_8010B054_8010A710 : Base_8010B054_8010A710 {
    virtual void m0();
    virtual void m1();  virtual void m2();  virtual void m3();
    virtual void m4();  virtual void m5();  virtual void m6();
    virtual void m7();  virtual void m8();  virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12();
    virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18();
    virtual void m19();
};

void register_technique_boosts__14TItemEquipBaseFPvPv(void *arg0, Row_8010A89C *row);
void *__dt__14TItemEquipBaseFv(void *arg0, s16 arg1);
s32 subtract_s16_stat(void *, void *);
s8 get_mode__5TItemFv();
s32 destroy__5TItemFv(void *);
s32 fn_8010B7D8(void *, void *);
s32 fn_8010B7E8(void *, void *);
s32 get_item_group__5TItemFv(void*);

void play_target_impact_effect(s32 arg0, s32 arg1, s32 arg2, s16 arg3) {
    typedef char sp8_offset[(offsetof(Stack_8010A710, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8010A710, spC) == 0x4) ? 1 : -1];
    Stack_8010A710 stack;
    u8 *temp_r3;
    temp_r3 = (u8 *)(resolve_hittable_target(arg2, (s32) arg3));
    if (temp_r3 != NULL) {
        VecCopy((Vec *)(&stack.sp8), (const Vec *)(temp_r3 + 0x38));
        stack.spC = *(f32 *)((s8 *)temp_r3 + 0x300);
    }
    spawn_particle_effect(&stack.sp8, 0x45);
}

void*TItemEquipBase::get_stat_bonus_ptr() { return (char*)this + 0x16c; }

s8 TItemWeapon::get_attach_joint() {
    return (s8) (*(u8 *)((u8 *)this + 0x171));
}

s8 TItemEquipBase::get_attach_slot() {
    return m_170;
}

void TItemEquipBase::vfunc_50() {  }

void TItemEquipBase::bind_loaded_resources() {
    s16 temp_r3;
    u8 *node;
    if ((u32) this->m_f4 == 0U) {
        temp_r3 = *(s16 *)&this->m_172;
        if ((temp_r3 != -1) && (TItemLoad::has_resource_id((s32) temp_r3) == 1)) {
            node = (u8 *)(TItemLoad::find_node_by_id((s32) *(s16 *)&this->m_172));
            if (node != NULL) {
                this->m_f4 = (u32) *(u32 *)((s8 *)node + 0);
                *(s32 *)&this->m_188 = (s32) *(s32 *)((s8 *)node + 4);
                this->texture_id = (s32) *(s32 *)((s8 *)node + 0x10);
                *(s32 *)&this->m_17c = (s32) *(s32 *)((s8 *)node + 0x14);
                *(s32 *)&this->m_180 = (s32) *(s32 *)((s8 *)node + 8);
                *(s32 *)&this->m_184 = (s32) *(s32 *)((s8 *)node + 0xC);
                this->vfunc_50();
            }
        }
    }
}

void TItemEquipBase__sub_8010A82C(s32 arg0) {
    s32 sp8;
    s32 temp_r31;
    s32 var_r30;
    temp_r31 = (((TItem *)arg0)->get_item_type() != 0) ? 3 : 0;
    TItemEquipBase__sub_8010B73C((&sp8));
    var_r30 = 0;
    do {
        TItemEquipBase__sub_8022C680(&sp8, (void *) (((s32)get_owner_client__5TItemFv((void *)arg0))), (void *) (temp_r31 + var_r30));
        var_r30 += 1;
    } while (var_r30 != 3);
}

void register_technique_boosts__14TItemEquipBaseFPvPv(void *item, Row_8010A89C *row) {
    s32 base;
    Row_8010A89C *p;
    s32 i;
    Slot_8010A89C slot;
    s32 id;
    u8 lv;
    f32 amt;

    if (row == NULL) {
        return;
    }
    base = (((TItem *)item)->get_item_type() != 0) ? 3 : 0;
    p = row;
    i = 0;
    do {
        TItemEquipBase__sub_8010B73C(&slot);
        id = p->id;
        lv = p->level;
        amt = p->amount;
        slot.id = id;
        slot.level = lv;
        slot.amount = amt;
        TItemEquipBase__sub_8022C680((void *)&slot, (void *)((s32 (*)(void *, int))get_owner_client__5TItemFv)(item, id), (void *)(base + i));
        i++;
        p++;
    } while (i != 3);
}

void TItemEquipBase::vfunc_49() {  }
void TItemEquipBase::vfunc_48() {  }
void TItemEquipBase::vfunc_45() {  }

void TItemEquipBase::vfunc_44() {  }

void TItemEquipBase::sub_8010A948() {
    if (((s32)TItemEquipBase__sub_8010AC60((s32)this, 2, 4)) != 0) {
        get_owner_client__5TItemFv(this);
        start_event_by_index__15TItemTimerEventFUs();
    }
    if (((s32)TItemEquipBase__sub_8010AC60((s32)this, 8, 0x10)) != 0) {
        apply_equip_slot_effect__14TItemEquipBaseFUsUl(get_owner_client__5TItemFv(this), 0);
    }
    if (((s32)TItemEquipBase__sub_8010AC60((s32)this, 0x20, 0x40)) != 0) {
        ((TItemEquipBase *)(this->m_f0 + 0x7CC))->check_flag_32();
    }
    if (((s32)TItemEquipBase__sub_8010AC60((s32)this, 0x80, 0x100)) != 0) {
        apply_equip_slot_effect__14TItemEquipBaseFUsUl(get_owner_client__5TItemFv(this), 1);
    }
    if (((s32)TItemEquipBase__sub_8010AC60((s32)this, 0x200, 0x400)) != 0) {
        apply_equip_slot_effect__14TItemEquipBaseFUsUl(get_owner_client__5TItemFv(this), 2);
    }
    if (((s32)TItemEquipBase__sub_8010AC60((s32)this, 0x800, 0x1000)) != 0) {
        apply_equip_slot_effect__14TItemEquipBaseFUsUl(get_owner_client__5TItemFv(this), 3);
    }
    if (((s32)TItemEquipBase__sub_8010AC60((s32)this, 0x2000, 0x4000)) != 0) {
        apply_equip_slot_effect__14TItemEquipBaseFUsUl(get_owner_client__5TItemFv(this), 4);
    }
    if (((s32)TItemEquipBase__sub_8010AC60((s32)this, 0x8000, 0x10000)) != 0) {
        apply_equip_slot_effect__14TItemEquipBaseFUsUl(get_owner_client__5TItemFv(this), 5);
    }
    if (((s32)TItemEquipBase__sub_8010AC60((s32)this, 0x20000, 0x40000)) != 0) {
        apply_equip_slot_effect__14TItemEquipBaseFUsUl(get_owner_client__5TItemFv(this), 6);
    }
}

void TItemEquipBase::remove_equip_effects() {
    u8 *arg0 = (u8 *)this;
    u32 temp_r3;
    if (apply_ad_rico_ring(1) != 0) {
        this->release();
    }
    if (apply_ad_rico_ring(4) != 0) {
        clear_timer_slot__15TItemTimerEventFUs((void *) (((s32)get_owner_client__5TItemFv(arg0))));
    }
    if (apply_ad_rico_ring(0x10) != 0) {
        apply_equip_effect_slot__14TItemEquipBaseFUsUl((void *) (((s32)get_owner_client__5TItemFv(arg0))), 0);
    }
    if (apply_ad_rico_ring(0x40) != 0) {
        temp_r3 = this->m_f0;
        if (temp_r3 != 0U) {
            ((TItemEquipBase *)(temp_r3 + 0x7CC))->clear_flag_c_bit5();
        }
    }
    if (apply_ad_rico_ring(0x100) != 0) {
        apply_equip_effect_slot__14TItemEquipBaseFUsUl((void *) (((s32)get_owner_client__5TItemFv(arg0))), 1);
    }
    if (apply_ad_rico_ring(0x400) != 0) {
        apply_equip_effect_slot__14TItemEquipBaseFUsUl((void *) (((s32)get_owner_client__5TItemFv(arg0))), 2);
    }
    if (apply_ad_rico_ring(0x1000) != 0) {
        apply_equip_effect_slot__14TItemEquipBaseFUsUl((void *) (((s32)get_owner_client__5TItemFv(arg0))), 3);
    }
    if (apply_ad_rico_ring(0x4000) != 0) {
        apply_equip_effect_slot__14TItemEquipBaseFUsUl((void *) (((s32)get_owner_client__5TItemFv(arg0))), 4);
    }
    if (apply_ad_rico_ring(0x10000) != 0) {
        apply_equip_effect_slot__14TItemEquipBaseFUsUl((void *) (((s32)get_owner_client__5TItemFv(arg0))), 5);
    }
    if (apply_ad_rico_ring(0x40000) != 0) {
        apply_equip_effect_slot__14TItemEquipBaseFUsUl((void *) (((s32)get_owner_client__5TItemFv(arg0))), 6);
    }
}

s32 TItemEquipBase__sub_8010AC60(s32 arg0, s32 arg1, s32 arg2) {
    if ((test_flags_any((void *)(arg0 + 0x178), (void *)arg1) != 0) && (test_flags_any((void *)(arg0 + 0x178), (void *)arg2) == 0)) {
        ((TObjPlayer *)(arg0 + 0x178))->set_flags(arg2);
        return 1;
    }
    return 0;
}

s32 TItemEquipBase::apply_ad_rico_ring(s32 arg1) {
    s32 arg0 = (s32)this;
    if (test_flags_any((void *)(arg0 + 0x178), (void *)arg1) != 0) {
        ((TAdRicoRing *)(arg0 + 0x178))->clear_flags(arg1);
        return 1;
    }
    return 0;
}
void TItemEquipBase::set_equip_flag(s32 v) { this->m_171 = v; }

typedef char RecoveredGlobal_8010AD24_lbl_804C3BA8_size[sizeof(RecoveredGlobal_8010AD24_lbl_804C3BA8) == 0x14 ? 1 : -1];
void TItemEquipBase::set_attach_slot(s8 arg1) {
    u8 *arg0 = (u8 *)this;
    this->m_170 = arg1;
    set_equip_flag((s32)((int) ((s8) *(s16 *)((s8 *)((u8 *)&item_equip_attach_equip_flag_table.value + (((VObj_18_b34251 *)(arg0))->m31() * 2)) + 0))));
}

void TItemEquipBase::deduct_cap_excess(s32 unused, s16 *arg1, s16 arg2) {
    if (arg2 > 0) {
        *arg1 -= arg2;
    }
}

void TItemEquipBase::subtract_equip_stats(s32 arg1, u8 *arg2, u8 *arg3) {
    u8 *arg0 = (u8 *)this;
    if (arg1 != 0) {
        subtract_s16_stat((void *)arg1, (void *) (get_attack_params_atp_min(arg0 + 0x11C)));
        fn_8010B7E8((void *)arg1, (void *) (get_attack_params_atp_max(arg0 + 0x11C)));
        fn_8010B7D8((void *)arg1, (void *) (TObjPlayer__sub_800194E8(arg0 + 0x11C)));
    }
    if (arg2 != NULL) {
        *(s16 *)((s8 *)arg2 + 0) = (s16) (*(s16 *)((s8 *)arg2 + 0) - this->m_14c);
        *(s32 *)((s8 *)arg2 + 0x1C) = (s32) (*(s32 *)((s8 *)arg2 + 0x1C) - this->m_168);
        *(s16 *)((s8 *)arg2 + 2) = (s16) (*(s16 *)((s8 *)arg2 + 2) - *(s16 *)&this->unk_14E);
        *(s16 *)((s8 *)arg2 + 4) = (s16) (*(s16 *)((s8 *)arg2 + 4) - this->m_150);
        *(s16 *)((s8 *)arg2 + 6) = (s16) (*(s16 *)((s8 *)arg2 + 6) - *(s16 *)&this->unk_152);
        *(s16 *)((s8 *)arg2 + 8) = (s16) (*(s16 *)((s8 *)arg2 + 8) - this->m_154);
        *(s16 *)((s8 *)arg2 + 0xA) = (s16) (*(s16 *)((s8 *)arg2 + 0xA) - *(s16 *)&this->unk_156);
    }
    if (arg3 != NULL) {
        *(s16 *)((s8 *)arg3 + 0) = (s16) (*(s16 *)((s8 *)arg3 + 0) - *(s16 *)&this->unk_F8);
        *(s16 *)((s8 *)arg3 + 2) = (s16) (*(s16 *)((s8 *)arg3 + 2) - this->m_fa);
        *(s16 *)((s8 *)arg3 + 4) = (s16) (*(s16 *)((s8 *)arg3 + 4) - *(s16 *)&this->unk_FC);
        *(s16 *)((s8 *)arg3 + 6) = (s16) (*(s16 *)((s8 *)arg3 + 6) - this->m_fe);
        *(s16 *)((s8 *)arg3 + 8) = (s16) (*(s16 *)((s8 *)arg3 + 8) - *(s16 *)&this->unk_100);
        *(s16 *)((s8 *)arg3 + 0xA) = (s16) (*(s16 *)((s8 *)arg3 + 0xA) - this->m_102);
        *(s16 *)((s8 *)arg3 + 0xC) = (s16) (*(s16 *)((s8 *)arg3 + 0xC) - *(s16 *)((s8 *)arg0 + 0x104));
    }
}

void TItemEquipBase::subtract_item_stat_bonus(s32 arg1, s32 arg2, s16 *out) {
    Equip_8010AEFC *self = (Equip_8010AEFC *)this;
    u32 extra;
    ItemData_8010AEFC item;
    Stats_8010AEFC st;
    ((TItem *)self)->copy_to_item_data((TItemData *)&item);
    memset(&st, (void *)0, (void *)0x24);
    memset(&extra, (void *)0, (void *)4);
    ((TItemData *)(&item))->apply_equip_effects(self->m_f0, (s32)arg1, (s32)arg2, (s32)&st, (s32)&extra);
    if (out != NULL) {
        out[0] -= st.v[0];
        out[1] -= st.v[1];
        out[2] -= st.v[2];
        out[3] -= st.v[3];
        out[4] -= st.v[4];
        out[5] -= st.v[5];
        out[6] -= st.v[6];
    }
}

void TItemEquipBase::reset() { memset((char*)this + 0xf8, (void*)0, (void*)36); memset((char*)this + 0x11c, (void*)0, (void*)48); memset((char*)this + 0x14c, (void*)0, (void*)32); memset((char*)this + 0x16c, (void*)0, (void*)4); }

void TItemEquipBase::update_equip() {
    if (get_mode__5TItemFv() == 2) {
        ((VObj_8010B054_8010A710 *)this)->m19();
    }
    destroy__5TItemFv(this);
}

typedef struct RecoveredFields_8010B0A8_arg0 RecoveredFields_8010B0A8_arg0;
typedef struct VBase_18_8e31a0 VBase_18_8e31a0;
typedef struct VObj_18_8e31a0 VObj_18_8e31a0;
void TItemEquipBase::remove_equip_stats(s32 arg1) {
  u8 *temp_r3;
  s32 temp_r31;
  s32 player;
  int new_var;
  temp_r3 = (u8 *) ((RecoveredFields_8010B0A8_arg0 *) ((u8 *)this))->field_F0;
  if (temp_r3 != 0)
  {
    temp_r31 = TItemData__sub_8010B810((int) temp_r3);
    player = TItemData__sub_8010B808((void *) ((RecoveredFields_8010B0A8_arg0 *) ((u8 *)this))->field_F0);
    new_var = ((TQuestListVM *)((void *) ((RecoveredFields_8010B0A8_arg0 *) ((u8 *)this))->field_F0))->get_quest_id();
    (((VObj_18_8e31a0 *)(this))->m23((temp_r31), (player), (new_var)));
    if (arg1 != 0)
    {
      add_actor_hp_bonus((void *) ((RecoveredFields_8010B0A8_arg0 *) ((u8 *)this))->field_F0, (int) ((s32) ((s16) (-((RecoveredFields_8010B0A8_arg0 *) ((u8 *)this))->field_16C))));
      add_actor_tp_bonus((void *) ((RecoveredFields_8010B0A8_arg0 *) ((u8 *)this))->field_F0, (int) ((s32) ((s16) (-((RecoveredFields_8010B0A8_arg0 *) ((u8 *)this))->field_16E))));
      (this->vfunc_49());
      (((VObj_18_8e31a0 *)((u8 *) ((RecoveredFields_8010B0A8_arg0 *) ((u8 *)this))->field_F0))->m71());
      ((TUnk_804806E8 *)((void *) ((RecoveredFields_8010B0A8_arg0 *) ((u8 *)this))->field_F0))->clamp_value();
      ((TObjPlayer *)((void *) ((RecoveredFields_8010B0A8_arg0 *) ((u8 *)this))->field_F0))->clamp_field_32E();
    }
    this->reset();
  }
}

void TItemEquipBase::unequip() {
    u8 *arg0 = (u8 *)this;
    if ((u32) this->m_f0 != 0U) {
        ((TItem *)arg0)->set_mode(1);
        ((TItem *)arg0)->clear_item_flags(0x28);
        this->remove_equip_stats(1);
        remove_equip_effects();
        this->vfunc_45();
        if ((u32) this->m_174 != 0U) {
            ((TObject *)(this->m_174))->delete_children();
        }
    }
}

void TItemEquipBase::add_equip_stats(s32 arg1) {
    ItemData_8010B224 item;
    s32 t;
    u8 *p;
    u8 *arg0 = (u8 *)this;
    if (*(void **)((s8 *)arg0 + 0xF0) != NULL) {
        ((TItem *)arg0)->copy_to_item_data((TItemData *)&item);
        ((TItemData *)(&item))->apply_equip_effects((s32)this->m_f0, (s32)((s32)(arg0 + 0x11C)), (s32)((s32)(arg0 + 0x14C)), (s32)(arg0 + 0xF8), (s32)(arg0 + 0x16C));
        t = TItemData__sub_8010B810(this->m_f0);
        if (t != 0) {
            TItemData::add_s16((s16 *)t, (s32)(get_attack_params_atp_min(arg0 + 0x11C)));
            ((TItemData *)t)->add_stat(get_attack_params_atp_max(arg0 + 0x11C));
            ((TItemData *)t)->add_accuracy(TObjPlayer__sub_800194E8(arg0 + 0x11C));
        }
        p = (u8 *)TItemData__sub_8010B808(*(void **)((s8 *)arg0 + 0xF0));
        if (p != NULL) {
            *(s16 *)((s8 *)p + 0) += this->m_14c;
            *(s32 *)((s8 *)p + 0x1C) += this->m_168;
            *(s16 *)((s8 *)p + 2) += *(s16 *)((s8 *)arg0 + 0x14E);
            *(s16 *)((s8 *)p + 4) += this->m_150;
            *(s16 *)((s8 *)p + 6) += *(s16 *)((s8 *)arg0 + 0x152);
            *(s16 *)((s8 *)p + 8) += this->m_154;
            *(s16 *)((s8 *)p + 0xA) += *(s16 *)((s8 *)arg0 + 0x156);
        }
        if (((TQuestListVM *)(*(void **)((s8 *)arg0 + 0xF0)))->get_quest_id() != 0U) {
            s16 v = add_stat__10TObjPlayerFl(*(void **)((s8 *)arg0 + 0xF0), *(s16 *)((s8 *)arg0 + 0xF8));
            TItemEquipBase::deduct_cap_excess((s32)arg0, (s16 *)(arg0 + 0xF8), v);
            TItemEquipBase::deduct_cap_excess((s32)arg0, (s16 *)(arg0 + 0xFA), add_mst__10TObjPlayerFl(*(void **)((s8 *)arg0 + 0xF0), this->m_fa));
            TItemEquipBase::deduct_cap_excess((s32)arg0, (s16 *)(arg0 + 0xFC), add_evp__10TObjPlayerFl(*(void **)((s8 *)arg0 + 0xF0), *(s16 *)((s8 *)arg0 + 0xFC)));
            TItemEquipBase::deduct_cap_excess((s32)arg0, (s16 *)(arg0 + 0xFE), add_hp__10TObjPlayerFl(*(void **)((s8 *)arg0 + 0xF0), this->m_fe));
            TItemEquipBase::deduct_cap_excess((s32)arg0, (s16 *)(arg0 + 0x100), add_dfp__10TObjPlayerFl(*(void **)((s8 *)arg0 + 0xF0), *(s16 *)((s8 *)arg0 + 0x100)));
            TItemEquipBase::deduct_cap_excess((s32)arg0, (s16 *)(arg0 + 0x102), add_ata__10TObjPlayerFl(*(void **)((s8 *)arg0 + 0xF0), this->m_102));
            TItemEquipBase::deduct_cap_excess((s32)arg0, (s16 *)(arg0 + 0x104), add_lck__10TObjPlayerFl(*(void **)((s8 *)arg0 + 0xF0), *(s16 *)((s8 *)arg0 + 0x104)));
        }
        if (arg1 != 0) {
            add_actor_hp_bonus(*(void **)((s8 *)arg0 + 0xF0), *(s16 *)((s8 *)arg0 + 0x16C));
            add_actor_tp_bonus(*(void **)((s8 *)arg0 + 0xF0), this->m_16e);
            this->vfunc_48();
            ((VObj_8010B224 *)*(void **)((s8 *)arg0 + 0xF0))->m71();
        }
    }
}

void TItemEquipBase::equip() {
    u8 *arg0 = (u8 *)this;
    if ((u32) this->m_f0 != 0U) {
        ((TItem *)arg0)->update_owner_visibility();
        ((TItem *)arg0)->set_mode(2);
        ((TItem *)arg0)->add_item_flags(8);
        this->add_equip_stats(1);
        if ((TOKeyMachine01::get_global_state() != 0xF) && (test_flags_any((u8 *)&this->m_178, (void *)(1)) == 0)) {
            ((TObjPlayer *)(arg0 + 0x178))->set_flags((u32)((void *)(1)));
            this->vfunc_46();
        }
        ((TItemEquipBase *)arg0)->sub_8010A948();
        this->vfunc_44();
    }
}

void TItemEquipBase::release() {
    s16 temp = *(s16 *)&this->m_172;
    if (temp != -1) {
        TItemLoad::release_resource_by_id(temp);
        *(s16 *)&this->m_172 = -1;
        *(s32 *)&this->m_f4 = 0;
        this->texture_id = 0;
        *(s32 *)&this->m_188 = 0;
        *(s32 *)&this->m_17c = 0;
        *(s32 *)&this->m_180 = 0;
        *(s32 *)&this->m_184 = 0;
    }
}

void TItemEquipBase::request_model_load(s32 arg1) {
    TItemData item_data;
    init__9TItemDataFv(&item_data.data1.data_u8[0]);
    item_data.data1.data_u8[0] = this->get_item_type();
    item_data.data1.data_u8[1] = arg1;
    item_data.data1.data_u8[2] = this->get_item_index();
    this->m_172 = request_item_model_load((&item_data.data1.data_u8[0]));
}

void TItemEquipBase::update_with_player() {
    s32 object = (s32)this;
    ((TItemEquipBase *)object)->request_model_load(get_item_group__5TItemFv((void*)object));
}
void TItemEquipBase::vfunc_46() {  }

void *__dt__14TItemEquipBaseFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TItemEquipBase;
        ((TItemEquipBase *)arg0)->remove_equip_effects();
        __dt__5TItemFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
u8 *TItemEquipBase__ct(u8 *arg0, s32 parent, s32 item) {
    s32 temp_r3;
    s32 var_r0;
    __ct__5TItemFP7TObjectPUc((arg0), (void *)parent, (u8 *)item);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8010B684___vt__14TItemEquipBase *)&__vt__14TItemEquipBase).value;
    ((TObjPlayer *)(arg0 + 0x178))->init_forward();
    *(s32 *)((s8 *)arg0 + 0) = (s32) item_equip_base_class_name;
    *(s8 *)&((TItemEquipBase *)arg0)->m_170 = 0;
    *(s8 *)&((TItemEquipBase *)arg0)->m_171 = 0;
    ((TItemEquipBase *)arg0)->reset();
    *(s16 *)&((TItemEquipBase *)arg0)->m_172 = -1;
    ((TObjPlayer *)(arg0 + 0x178))->clear_id();
    ((TItem *)arg0)->add_item_flags(4);
    temp_r3 = __nw__15TItemHeapObjectFUl(0x1C);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = __ct__15TItemHeapObjectFP7TObject(temp_r3, arg0);
    }
    *(s32 *)&((TItemEquipBase *)arg0)->m_174 = var_r0;
    *(s32 *)&((TItemEquipBase *)arg0)->m_17c = 0;
    *(s32 *)&((TItemEquipBase *)arg0)->m_188 = 0;
    *(s32 *)&((TItemEquipBase *)arg0)->m_180 = 0;
    *(s32 *)&((TItemEquipBase *)arg0)->m_184 = 0;
    return arg0;
}

}
