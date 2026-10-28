#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/object/TObjMotion.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_8011892C.h"
#include "pso/item/TItemProUnit.h"
#include "pso/item/TItemData.h"
#include "pso/player/TObjPlayer.h"

struct Base_80118A48_8011892C { char pad[0x18]; };
struct VObj_80118A48_8011892C : Base_80118A48_8011892C {
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
    virtual void m17(int);
};

struct Base_80118958 { char pad[0x18]; };

struct VObj_80118958 : Base_80118958 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30();
    virtual s32 m31();
};

struct Self_80118958 : VObj_80118958 { u8 pad[0x1bc - 0x1c]; s16 s1bc; };

struct Out_80118958 { u8 pad[4]; s8 b4; };

struct Data_80118A78 { u8 pad[0x7cc]; u8 unit[4]; };

struct Self_80118A78 { u8 pad[0xf0]; Data_80118A78 *data; u8 padf4[0x18c - 0xf4]; s16 s18c; u8 pad18e[0x1b8 - 0x18e]; f32 evp; };

struct Owner_80118AD4 { u8 pad0[0x428]; u8 f428[0x88D - 0x428]; u8 f88d; };

struct Unit_80118AD4 { u8 pad0[0xF0]; Owner_80118AD4 *owner; u8 padF4[0x190 - 0xF4]; s16 f190; s16 arr[19]; };

struct PU_801189AC { u8 pad[0x192]; s16 arr[0x13]; };

extern "C" {
void update_owned__12TItemProUnitFv(u8 *arg0);
s32 get_owner_client__5TItemFv(void *);
s32 construct_timer_event__13TUnk_804A0628Fv(int, int, void *, int);
s32 init_item_timer_event__13TUnk_804A0648Fv(int, int, void *, int);
s32 init_timer_event__13TUnk_804A0608Fv(int, int, void *, int);
s32 __nw__15TItemHeapObjectFUl(int);
extern const f32 lbl_805DABFC;
void vfunc_44__12TItemProUnitFv(u8 *arg0);
extern const f32 TItemProUnit__data_805DABF8;
extern const f32 lbl_805DAC00;
void TItemProUnit__vt16(Self_80118958 *self, Out_80118958 *out);
f32 TItemProUnit__sub_8011901C(void *);
void update_equipped__12TItemProUnitFv(Self_80118A78 *self);
u8 get_technique_learn_limit(u8, u8);
u8 get_cast_technique_level(void *, s16);
void set_technique_level_entry(void *, s16, u8);
void vfunc_48__12TItemProUnitFv(Unit_80118AD4 *self);
s32 memset(void *, s32, s32);
void vfunc_49__12TItemProUnitFv(u8 *arg0);
void vfunc_45__12TItemProUnitFv(void *arg0);
void *lookup_item_pmt_record(u8 *item);
s32 TItemEquipBase__ct();
s16 get_field6_bswap__9TItemDataFPv(void *);

void TItemProUnit::carry_over_stats(TItemData *, TItem *) {}

void TItemProUnit::update_owned() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r0;
    s16 temp_r4;
    temp_r0 = *(s16 *)((s8 *)arg0 + 0x1BE);
    temp_r4 = *(s16 *)((s8 *)arg0 + 0x1BC);
    if ((temp_r0 < temp_r4) || (temp_r4 < -temp_r0)) {
        *(s16 *)((s8 *)arg0 + 0x1BC) = 0;
    }
}

void TItemProUnit__vt16(Self_80118958 *self, Out_80118958 *out) {
    out->b4 = (s8)self->m31() - 9;
    ((TItemData *)out)->set_unit_modifier(self->s1bc);
}

void TItemProUnit::vfunc_49() {
    u8 *arg0 = (u8 *)this;
    s32 i;
    if ((s16) *(s16 *)((s8 *)arg0 + 0x18C) == 0x13) {
        ((TItemProUnit *)&this->owner->attack_state)->set_evp(TItemProUnit__data_805DABF8);
    }
    i = 0;
    do {
        set_technique_level_entry(this->owner->technique_levels, (s16) i, (u8) (get_cast_technique_level(this->owner->technique_levels, (s16) i) - ((PU_801189AC *)arg0)->arr[i]));
        i += 1;
    } while (i != 0x13);
    memset(arg0 + 0x192, 0, 0x26);
}

void TItemProUnit::vfunc_45() {
    struct VObj_80118A48_8011892C *o = (struct VObj_80118A48_8011892C *)this;
    o->m17(9);
}

extern void *__vt__12TItemProUnit[];
extern s32 lbl_805D2C40;

void TItemProUnit::update_equipped() {
    Self_80118A78 *self = (Self_80118A78 *)this;
    if (self->s18c == 0x13) {
        if (TItemProUnit__sub_8011901C(self->data->unit) < self->evp) {
            ((TItemProUnit *)(self->data->unit))->set_evp(self->evp);
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TItemProUnit::vfunc_48() {
    Unit_80118AD4 *self = (Unit_80118AD4 *)this;
    u8 v;
    s16 i;
    u8 cap;
    s16 base;
    u8 tot;
    if (self->f190 != 0) {
        for (i = 0; i != 19; i++) {
            if (i == 14 || i == 17) {
                continue;
            }
            v = get_cast_technique_level(self->owner->f428, i);
            if (v != 0xFF) {
                cap = get_technique_learn_limit(self->owner->f88d, (u8)i);
                base = self->f190;
                tot = v + base;
                if (cap < tot) {
                    self->arr[i] = base + cap - tot;
                    tot = cap;
                } else {
                    self->arr[i] = base;
                }
                set_technique_level_entry(self->owner->f428, i, tot);
            }
        }
    }
}
#pragma pop

void TItemProUnit::vfunc_44() {
    u8 *arg0 = (u8 *)this;
  s32 temp_r3;
  s32 temp_r3_2;
  s32 temp_r3_3;
  switch (*((s16 *) (((s8 *) arg0) + 0x18C)))
  {
    case 15:
      if ((this->m_174) != 0U)
    {
      temp_r3 = __nw__15TItemHeapObjectFUl(0x2C);
      if (temp_r3 != 0)
      {
        init_item_timer_event__13TUnk_804A0648Fv((int) temp_r3, this->m_174, (void *) get_owner_client__5TItemFv((void *) arg0), (int) ((s32) (lbl_805DABFC * (this->m_18e))));
      }
    }
      return;
      return;
    case 16:
      if ((this->m_174) != 0U)
    {
      temp_r3_2 = __nw__15TItemHeapObjectFUl(0x2C);
      if (temp_r3_2 != 0)
      {
        construct_timer_event__13TUnk_804A0628Fv((int) temp_r3_2, this->m_174, (void *) get_owner_client__5TItemFv((void *) arg0), (int) ((s32) (lbl_805DABFC * (this->m_18e))));
        return;
      }
    }
      break;
    case 17:
      if ((this->m_174) != 0U)
    {
      temp_r3_3 = __nw__15TItemHeapObjectFUl(0x2C);
      if (temp_r3_3 != 0)
      {
        init_timer_event__13TUnk_804A0608Fv((int) temp_r3_3, this->m_174, (void *) get_owner_client__5TItemFv((void *) arg0), (int) ((s32) (lbl_805DABFC * (this->m_18e))));
      }
    }
      break;
  }
}

extern "C" {
void *__dt__12TItemProUnitFv(void *arg0, s16 arg1);
void run_task__5TItemFv();
void render__5TItemFv();
void render_shadows__5TItemFv();
void vfunc_6__13TUnk_804B9870FPsl();
void apply_object_set_data__13TUnk_804B9870FPv();
void reset_motion_fields__13TUnk_804AF8A0Fv();
void add_amount__5TItemFl();
void add_slot__5TItemFv();
void feed__5TItemFP9TItemData();
void get_amount__5TItemFv();
void get_slot_count__5TItemFv();
void remove_amount__5TItemFl();
void vfunc_42__5TItemFv();
void update_object_view_visibility__5TItemFff();
void update_in_inventory__5TItemFv();
void vfunc_9__13TUnk_804B9870Fv();
void classify_actor_view_detail__13TUnk_804B9870Ffff();
void vfunc_12__5TItemFv();
void vfunc_13__5TItemFl();
void activate_effect__5TItemFl();
void set_attach_slot__14TItemEquipBaseFSc();
void equip__14TItemEquipBaseFv();
void unequip__14TItemEquipBaseFv();
void add_equip_stats__14TItemEquipBaseFl();
void remove_equip_stats__14TItemEquipBaseFl();
void subtract_item_stat_bonus__14TItemEquipBaseFllPs();
void subtract_equip_stats__14TItemEquipBaseFlPUcPUc();
void render_equipped__5TItemFv();
void render_equipped_shadow__5TItemFv();
void render_equipped_deferred__5TItemFv();
void use__5TItemFv();
void update_equip__14TItemEquipBaseFv();
void vfunc_30__5TItemFv();
void get_attack_flags__5TItemFv();
s8 get_attach_slot__14TItemEquipBaseFv(TItemEquipBase *arg0);
void vfunc_34__5TItemFv();
void is_identified__5TItemFv();
void get_motion_type__5TItemFv();
void vfunc_46__14TItemEquipBaseFv();
void release__14TItemEquipBaseFv();
void vfunc_50__14TItemEquipBaseFv();
}

void *__vt__12TItemProUnit[51] = {
    0,
    0,
    (void *)__dt__12TItemProUnitFv,
    (void *)run_task__5TItemFv,
    (void *)render__5TItemFv,
    (void *)render_shadows__5TItemFv,
    (void *)vfunc_6__13TUnk_804B9870FPsl,
    (void *)apply_object_set_data__13TUnk_804B9870FPv,
    (void *)reset_motion_fields__13TUnk_804AF8A0Fv,
    (void *)vfunc_9__13TUnk_804B9870Fv,
    (void *)update_object_view_visibility__5TItemFff,
    (void *)classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)vfunc_12__5TItemFv,
    (void *)vfunc_13__5TItemFl,
    (void *)update_owned__12TItemProUnitFv,
    (void *)update_in_inventory__5TItemFv,
    (void *)update_equipped__12TItemProUnitFv,
    (void *)activate_effect__5TItemFl,
    (void *)TItemProUnit__vt16,
    (void *)set_attach_slot__14TItemEquipBaseFSc,
    (void *)equip__14TItemEquipBaseFv,
    (void *)unequip__14TItemEquipBaseFv,
    (void *)add_equip_stats__14TItemEquipBaseFl,
    (void *)remove_equip_stats__14TItemEquipBaseFl,
    (void *)subtract_item_stat_bonus__14TItemEquipBaseFllPs,
    (void *)subtract_equip_stats__14TItemEquipBaseFlPUcPUc,
    (void *)render_equipped__5TItemFv,
    (void *)render_equipped_shadow__5TItemFv,
    (void *)render_equipped_deferred__5TItemFv,
    (void *)update_equip__14TItemEquipBaseFv,
    (void *)vfunc_30__5TItemFv,
    (void *)&use__5TItemFv,
    (void *)get_attack_flags__5TItemFv,
    (void *)get_attach_slot__14TItemEquipBaseFv,
    (void *)vfunc_34__5TItemFv,
    (void *)is_identified__5TItemFv,
    (void *)get_amount__5TItemFv,
    (void *)remove_amount__5TItemFl,
    (void *)add_amount__5TItemFl,
    (void *)get_slot_count__5TItemFv,
    (void *)add_slot__5TItemFv,
    (void *)feed__5TItemFP9TItemData,
    (void *)vfunc_42__5TItemFv,
    (void *)get_motion_type__5TItemFv,
    (void *)vfunc_44__12TItemProUnitFv,
    (void *)vfunc_45__12TItemProUnitFv,
    (void *)vfunc_46__14TItemEquipBaseFv,
    (void *)release__14TItemEquipBaseFv,
    (void *)vfunc_48__12TItemProUnitFv,
    (void *)vfunc_49__12TItemProUnitFv,
    (void *)vfunc_50__14TItemEquipBaseFv,
};

void TItemProUnit::apply_unit_effect_flags() {
    u8 *arg0 = (u8 *)this;
    switch (*(s16 *)((s8 *)arg0 + 0x18C)) {
    case 18:
        *(s16 *)((s8 *)arg0 + 0x190) = (s16) this->m_18e;
        return;
    case 20:
        ((FlagWord *)(arg0 + 0x178))->set(8);
        return;
    case 21:
        ((FlagWord *)(arg0 + 0x178))->set(2);
        return;
    case 19:
        *(f32 *)((s8 *)arg0 + 0x1B8) = (f32) (TItemProUnit__data_805DABF8 + ((f32) this->m_18e / lbl_805DAC00));
        return;
    case 22:
        ((FlagWord *)(arg0 + 0x178))->set(0x80);
        return;
    case 23:
        ((FlagWord *)(arg0 + 0x178))->set(0x200);
        return;
    case 24:
        ((FlagWord *)(arg0 + 0x178))->set(0x800);
        return;
    case 25:
        ((FlagWord *)(arg0 + 0x178))->set(0x2000);
        return;
    case 26:
        ((FlagWord *)(arg0 + 0x178))->set(0x8000);
        return;
    case 27:
        ((FlagWord *)(arg0 + 0x178))->set(0x20000);
    default:
        return;
    }
}

u8 *TItemProUnit__ct(TItemProUnit *item_pro_unit, s32 arg1, u8 *item) {
    s16 temp_r0;
    u8 *item_pmt_record;

    TItemEquipBase__ct();
    *(s32 **)((s8 *)item_pro_unit + 0x18) = (s32 *)__vt__12TItemProUnit;
    *(s32 *)((s8 *)item_pro_unit + 0) = (s32) lbl_805D2C40;
    item_pro_unit->set_attach_slot((s8) (*(u8 *)((s8 *)item + 4) + 9));
    *(s16 *)((s8 *)item_pro_unit + 0x190) = 0;
    *(f32 *)((s8 *)item_pro_unit + 0x1B8) = (f32) TItemProUnit__data_805DABF8;
    item_pmt_record = (u8 *)lookup_item_pmt_record(item);
    if (item_pmt_record != NULL) {
        *(s16 *)((s8 *)item_pro_unit + 0x18C) = (s16) *(s16 *)((s8 *)item_pmt_record + 8);
        item_pro_unit->m_18e = (s16) *(s16 *)((s8 *)item_pmt_record + 0xA);
        *(s16 *)((s8 *)item_pro_unit + 0x1BE) = (s16) (*(s16 *)((s8 *)item_pmt_record + 0xC) * 2);
    } else {
        *(s16 *)((s8 *)item_pro_unit + 0x18C) = 0;
        item_pro_unit->m_18e = 0;
        *(s16 *)((s8 *)item_pro_unit + 0x1BE) = 0;
    }
    *(s16 *)((s8 *)item_pro_unit + 0x1BC) = get_field6_bswap__9TItemDataFPv(item);
    temp_r0 = *(s16 *)((s8 *)item_pro_unit + 0x1BC);
    if ((temp_r0 <= -0xA) || (temp_r0 >= 0xA)) {
        *(s16 *)((s8 *)item_pro_unit + 0x1BC) = 0;
    }
    memset((u8 *)item_pro_unit + 0x192, 0, 0x26);
    item_pro_unit->apply_unit_effect_flags();
    return (u8 *)item_pro_unit;
}

}
