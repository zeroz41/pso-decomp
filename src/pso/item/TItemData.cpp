#include "types.h"
#include "pso/protocol/protocol_types.h"
#include "pso/system/byteswap.h"
#include "pso/object/TObjWarpBossMulti.h"
#include "pso/item/TItemData.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TShopEquipmentListWindow.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/Language.h"

struct Parm_8010C1E0;
struct Item_8010C498;
struct Item_8010C52C;
struct Parm_8010C0A4;
struct Stats2_8010BEC4;
struct Bonus_8010BA9C;
struct Stats_8010BA9C;
struct Tbl_8010C8B4;
struct Raw_8010D614;
struct Mag_8010D614;
struct Pair_8010E344;
struct TItemData_8010E344;
struct Mag_8010D510;
struct Item_8010D510;
struct Parm_8010EBD8;
struct Params_8010E414;
struct Item_8010E59C;
struct VBase_18_38db83
{
  char pad[0x18];
};

struct VObj_18_38db83 : VBase_18_38db83 {
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
    virtual u8 m37();
};

struct Parm_8010C320
{
  u8 pad[0xA];
  u16 atp_min;
  u16 atp_max;
  u8 padE[6];
  u16 x14;
  u8 pad16[3];
  u8 x19;
};

extern "C" {
s32 obj_getArrWord_254(void *, int);
u16 obj_getField1c(void *);
int get_item_field_6__10TObjPlayerFPv(void *);
s32 is_quest_active();
s32 is_flag_set__6TLobbyFv();
u8 *get_quest_id__12TQuestListVMFv(void *);
s32 is_item_usable__9TItemDataFlPUc(void *, void *);
s32 check_equip_requirements(void *, void *, int);
s32 check_class_equip_permission(void *, int);
void *lookup_item_pmt_record(u8 *item);
s32 update_player_field__9TItemDataFv(void *);
u8 get_technique_learn_limit(u8, u8);
s32 get_player_by_client_id(s32);
s16 *get_class_stat_entry__10TObjPlayerFPUc(void *);
u8 get_cast_technique_level(void *, int);
s32 is_invalid_slot__10TObjPlayerFUc();
s32 is_boss_area();
s32 reset_key_machine_state__10TObjPlayerFv();
void *calc_technique_parameters(u8, u8, s32);
s32 is_challenge_mode_active();
extern s32 local_client_id;
f32 calc_clock_bonus__9TItemDataFPv(u8 *arg0);
f32 get_set_bonus_multiplier__9TItemDataFPvi(void *self, s32 player);
void * lookup_item_pmt_record(u8 *item);
s16 getS16_06__9TItemDataFPv(void *arg0);
s16 get_bswap16_field8__9TItemDataFPv(void *arg0);
void add_armor_stat_contribution__9TItemDataFPviiPv(u8 *self, s32 player, s32 unused, s16 *out);
void lookup_item_def__9TItemDataFPv(void *arg0);
void add_shield_stat_contribution__9TItemDataFPviiPv(u8 *self, s32 player, s32 unused, s16 *out);
s16 get_field6_bswap__9TItemDataFPv(void *arg0);
void apply_unit_stat_bonus__9TItemDataFPviiPvPvPv(void *self, s32 arg1, s32 arg2, void *res, EquipStats *st, Stats2_8010BEC4 *st2);
void apply_bonuses(u8 *item, s32 arg1, u8 *a, u8 *b, Stats_8010BA9C *st);
s32 is_usable__9TItemDataFPv(void *arg0);
s32 is_custom_name_srank__9TItemDataFPv(u8 *arg0);
void serialize_mag__9TItemDataFPvPv(Item_8010D510 *item, const Mag_8010D510 *mag);
void init__9TItemDataFv(TItemData_8010E344 *self);
s32 memset(s8 *, s32, s32);
}
#define get_set_bonus_multiplier__9TItemDataFPvi ((f32 (*)(void *, s32))get_set_bonus_multiplier__9TItemDataFPvi)
#define lookup_item_pmt_record ((Parm_8010C1E0 * (*)(void *))lookup_item_pmt_record)
#define getS16_06__9TItemDataFPv ((s32 (*)(void *))getS16_06__9TItemDataFPv)
#define get_bswap16_field8__9TItemDataFPv ((s16 (*)(void *))get_bswap16_field8__9TItemDataFPv)
#define lookup_item_def__9TItemDataFPv ((s32 (*)(void *))lookup_item_def__9TItemDataFPv)
#define get_field6_bswap__9TItemDataFPv ((s32 (*)(void *))get_field6_bswap__9TItemDataFPv)
#define is_usable__9TItemDataFPv ((s32 (*)())is_usable__9TItemDataFPv)

struct Parm_8010C1E0 { u8 pad[8]; s16 dfp; s16 evp; u8 pad2[5]; s8 x11; s8 x12; s8 x13; s8 x14; s8 x15; };

struct Item_8010C498 {
    u8 kind;
    u8 b1, b2;
    u8 b3;
    u8 b4;
    u8 pad05[0xD];
    u8 b12;
};

struct Item_8010C52C { u8 kind; u8 pad1[2]; u8 b3; u8 b4; u8 pad5[0xD]; u8 b12; };

struct Parm_8010C0A4 { u8 pad[8]; s16 x8; s16 xa; u8 pad2[5]; s8 x11; s8 x12; s8 x13; s8 x14; s8 x15; };

struct Stats2_8010BEC4 { s16 s0; s16 s2; };

struct Raw_8010D614 { u8 b[4]; u16 s[4]; u32 id; u8 c[4]; };

struct Mag_8010D614 { u16 a0; u16 a2; u16 s[4]; u8 c; u8 d; u8 e; };

struct Bonus_8010BA9C { u8 kind; u8 pad; s16 val; };

struct Stats_8010BA9C { u8 pad0[2]; s16 x2; u8 pad4[2]; s16 x6; u8 pad8[4]; s16 xC; };

extern s32 lbl_8043E348;
extern const f32 lbl_805DAB6C;
struct Tbl_8010C8B4 { s32 w[19]; };

static const Tbl_8010C8B4 item_icon_index_by_category_table = {{1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 1, 1, 1, 1, 3, 2}};
static const f32 mag_stat_bonus_scale[4] = {2.0f, 0.5f, 1.0f, 2.0f};
extern "C" {
void deserialize_mag__9TItemDataFPvPv(Raw_8010D614 *src, Mag_8010D614 *dst);
void TItemData__sub_8010EDD8(void *arg0, s32 arg1);
void TItemData__sub_8010EDC8(void *arg0, s32 arg1);
void TItemData__sub_8010EDA8(void *arg0, s32 arg1);
extern u8 lbl_805DAB68;
void fn_8010B7D8(u8 *arg0, s32 arg1);
void fn_8010B7E8(u8 *arg0, s32 arg1);
void subtract_s16_stat(s16 *arg0, s32 arg1);
void TItemData__sub_8010EE1C(void *arg0, s16 arg1);
void TItemData__sub_8010EE30(s16 *arg0, s32 arg1);
}
s32 get_item_stat_boost_record(s32 arg0, s32 type, s32 id);
extern "C" {
s32 TItemData__sub_8010B808(void* p);
s32 TItemData__sub_8010B810(void* p);

extern "C" {
u8 is_wrapped__9TItemDataFPv(Item_8010C52C *it);
}

void subtract_s16_stat(s16 *arg0, s32 arg1) {
    *arg0 -= arg1;
}
s32 TItemData__sub_8010B808(void* p) { return *(s32*)((char*)p + 0x31c); }
s32 TItemData__sub_8010B810(void* p) { return *(s32*)((char*)p + 0x318); }

void TItemData::add_accuracy(s32 arg1) {
    *(s16 *)((s8 *)this + 4) = (s16) (*(s16 *)((s8 *)this + 4) + arg1);
}
void TItemData::add_stat(s32 arg1) {
    *(s16 *)((s8 *)this + 2) = (s16) (*(s16 *)((s8 *)this + 2) + arg1);
}
void TItemData::add_s16(s16 *arg0, s32 arg1) {
    *arg0 += arg1;
}

void TItemData::set_present_color(s8 arg1) {
    switch ((s32) (*(u8 *)((s8 *)((u8 *)this) + 0))) {
    case 0:
        *(u8 *)((s8 *)((u8 *)this) + 5) = (u8) (*(u8 *)((s8 *)((u8 *)this) + 5) | (arg1 & 0xF));
        return;
    case 1:
        *(u8 *)((s8 *)((u8 *)this) + 4) = (u8) (*(u8 *)((s8 *)((u8 *)this) + 4) | (arg1 & 0xF));
        return;
    case 3:
        *(u8 *)((s8 *)((u8 *)this) + 3) = (u8) (*(u8 *)((s8 *)((u8 *)this) + 3) | (arg1 & 0xF));
        return;
    case 2:
        return;
    }
}

s32 TItemData::get_type_nibble() {
    switch ((s32) (*(u8 *)((s8 *)((u8 *)this) + 0))) {
    case 0:
        return *(u8 *)((s8 *)((u8 *)this) + 5) & 0xF;
    case 1:
        return *(u8 *)((s8 *)((u8 *)this) + 4) & 0xF;
    case 3:
        return *(u8 *)((s8 *)((u8 *)this) + 3) & 0xF;
    default:
    case 2:
        return 0;
    }
}

#pragma push
#pragma opt_common_subs off
void TItemData::apply_custom_shield_bonus(s32 player, TItemData *a, TItemData *b, EquipStats *stats, s32) {
    if (data1.data_u8[0] == 1 && data1.data_u8[1] == 2) {
        u8 id = data1.data_u8[2];
        if (id >= 0x53 && id <= 0x82) {
            s32 count = TObjPlayer::count_nearby_players_with_shield(obj_getField1c((void *)player), data1.data_u8);
            u8 kind = (data1.data_u8[2] - 0x53) % 8;
            s16 bonus_per_player[8] = {0, 50, 25, 25, 100, 50, 50, 10};
            s16 amount = count * bonus_per_player[kind];
            switch (kind) {
            case 1:
                b->add_bonus(amount);
                break;
            case 2:
                TItemData::add_stat_ptr((s16 *)b, amount);
                break;
            case 3:
                stats->sC += amount;
                break;
            case 4:
                a->add_accuracy(amount);
                break;
            case 5:
                TItemData::add_s16((s16 *)a, amount);
                a->add_stat(amount);
                break;
            case 6:
                stats->s2 += amount;
                break;
            case 7:
                b->adjust_count(amount);
                TItemData__sub_8010EDD8(b, amount);
                TItemData__sub_8010EDC8(b, amount);
                b->add_quantity(amount);
                TItemData__sub_8010EDA8(b, amount);
                break;
            }
        }
    }
}
#pragma pop

void apply_bonuses(u8 *item, s32 arg1, u8 *a, u8 *b, Stats_8010BA9C *st) {
    Bonus_8010BA9C *bn;
    u8 t = item[0];
    switch (t) {
    case 0:
    case 1:
        bn = (Bonus_8010BA9C *)get_item_stat_boost_record(t, item[1], item[2]);
        if (bn != NULL && a != NULL && b != NULL && st != NULL)
        switch (bn->kind) {
        case 1:
            TItemData::add_s16((s16 *)a, bn->val);
            ((TItemData *)a)->add_stat(bn->val);
            break;
        case 2:
            ((TItemData *)a)->add_accuracy((s16)(bn->val * 10));
            break;
        case 3:
            TItemData::add_stat_ptr((s16 *)b, bn->val);
            break;
        case 4:
            ((TItemData *)b)->add_bonus(bn->val);
            break;
        case 5:
            st->x2 += bn->val;
            break;
        case 6:
            st->x6 += bn->val;
            break;
        case 7:
            st->xC += bn->val;
            break;
        case 8:
            TItemData::add_s16((s16 *)a, bn->val);
            ((TItemData *)a)->add_stat(bn->val);
            ((TItemData *)a)->add_accuracy((s16)(bn->val * 10));
            TItemData::add_stat_ptr((s16 *)b, bn->val);
            ((TItemData *)b)->add_bonus(bn->val);
            st->x2 += bn->val;
            st->xC += bn->val;
            break;
        case 9:
            subtract_s16_stat((s16 *)a, bn->val);
            fn_8010B7E8(a, bn->val);
            break;
        case 10:
            fn_8010B7D8(a, (s16)(bn->val * 10));
            break;
        case 11:
            TItemData__sub_8010EE30((s16 *)b, bn->val);
            break;
        case 12:
            TItemData__sub_8010EE1C(b, bn->val);
            break;
        case 13:
            st->x2 -= bn->val;
            break;
        case 14:
            st->x6 -= bn->val;
            break;
        case 15:
            st->xC -= bn->val;
            break;
        case 16:
            subtract_s16_stat((s16 *)a, bn->val);
            fn_8010B7E8(a, bn->val);
            fn_8010B7D8(a, (s16)(bn->val * 10));
            TItemData__sub_8010EE30((s16 *)b, bn->val);
            TItemData__sub_8010EE1C(b, bn->val);
            st->x2 -= bn->val;
            st->xC -= bn->val;
            break;
        }
        break;
    }
}

void add_mag_stat_bonuses__9TItemDataFv(u8 *item, s32 player, u8 *a, u8 *b, EquipStats *st, s32 w5) {
    Mag_8010D614 mag;

    ((TItemData *)&mag)->initialize_mag_data();
    deserialize_mag__9TItemDataFPvPv((Raw_8010D614 *)item, &mag);
    if (st != NULL && st != NULL) {
        st->s0 += (s16)(mag_stat_bonus_scale[0] * (f32)((TItemData *)&mag)->get_percent());
        st->sA += (s16)(mag_stat_bonus_scale[1] * (f32)(((TItemData *)&mag)->get_level() * 10));
        st->s8 += (s16)(mag_stat_bonus_scale[2] * (f32)((TItemData *)&mag)->get_stat_percent());
        st->s2 += (s16)(mag_stat_bonus_scale[3] * (f32)((TItemData *)&mag)->get_mag_mind_level());
    }
}

void apply_unit_stat_bonus__9TItemDataFPviiPvPvPv(void *self, s32 arg1, s32 arg2, void *res, EquipStats *st, Stats2_8010BEC4 *st2) {
    Parm_8010C1E0 *parm;
    s32 kind;
    s16 amount;
    parm = lookup_item_pmt_record(self);
    if (parm != NULL && st != NULL && res != NULL) {
    kind = parm->dfp;
    amount = parm->evp + get_field6_bswap__9TItemDataFPv(self);
    switch (kind) {
    case 0:
        st->s0 += amount;
        break;
    case 1:
        st->s2 += amount;
        break;
    case 2:
        st->sA += amount * 10;
        break;
    case 3:
        st->s4 += amount;
        break;
    case 4:
        if (st2 != NULL) {
            st2->s0 += amount;
        }
        break;
    case 5:
        if (st2 != NULL) {
            st2->s2 += amount;
        }
        break;
    case 6:
        st->s8 += amount;
        break;
    case 7:
        st->sC += amount;
        break;
    case 8:
        st->s0 += amount;
        st->s2 += amount;
        st->sA += amount;
        st->s4 += amount;
        st->s8 += amount;
        st->sC += amount;
        break;
    case 9:
        ((TItemData *)res)->adjust_count(amount);
        break;
    case 10:
        TItemData__sub_8010EDD8(res, amount);
        break;
    case 11:
        TItemData__sub_8010EDC8(res, amount);
        break;
    case 12:
        TItemData__sub_8010EDA8(res, amount);
        break;
    case 13:
        ((TItemData *)res)->add_quantity(amount);
        break;
    case 14:
        ((TItemData *)res)->adjust_count(amount);
        TItemData__sub_8010EDD8(res, amount);
        TItemData__sub_8010EDC8(res, amount);
        TItemData__sub_8010EDA8(res, amount);
        ((TItemData *)res)->add_quantity(amount);
        break;
    }
    }
}

#pragma push
#pragma fp_contract on
void add_shield_stat_contribution__9TItemDataFPviiPv(u8 *self, s32 player, s32 unused, s16 *out) {
    s32 b06;
    Parm_8010C0A4 *parm;
    f32 mult = get_set_bonus_multiplier__9TItemDataFPvi(self, player);
    f32 add = ((f32 (*)(u8 *, s32))calc_clock_bonus__9TItemDataFPv)(self, player);
    parm = ((Parm_8010C0A4 *)lookup_item_pmt_record(self));
    if (parm != 0) {
        b06 = getS16_06__9TItemDataFPv(self);
        s32 b08 = ((s32 (*)(void *))get_bswap16_field8__9TItemDataFPv)(self);
        s32 v = (s32)(parm->xa * mult + add);
        if (out != 0) {
            TItemData::add_stat_ptr(out, (s16)(v + b08));
            ((TItemData *)out)->add_bonus(parm->x8 + b06);
            ((TItemData *)out)->adjust_count(parm->x11);
            TItemData__sub_8010EDD8(out, parm->x13);
            TItemData__sub_8010EDC8(out, parm->x12);
            TItemData__sub_8010EDA8(out, parm->x15);
            ((TItemData *)out)->add_quantity(parm->x14);
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void add_armor_stat_contribution__9TItemDataFPviiPv(u8 *self, s32 player, s32 unused, s16 *out) {
    s32 dfpBonus;
    Parm_8010C1E0 *parm;
    f32 mult = get_set_bonus_multiplier__9TItemDataFPvi(self, player);
    f32 add = ((f32 (*)(u8 *, s32))calc_clock_bonus__9TItemDataFPv)(self, player);
    parm = lookup_item_pmt_record(self);
    if (parm != 0) {
        dfpBonus = getS16_06__9TItemDataFPv(self);
        s16 evpBonus = get_bswap16_field8__9TItemDataFPv(self);
        s32 dfp = (s32)(parm->dfp * mult + add);
        if (out != 0) {
            TItemData::add_stat_ptr(out, (s16)(parm->evp + evpBonus));
            ((TItemData *)out)->add_bonus(dfp + dfpBonus);
            ((TItemData *)out)->adjust_count(parm->x11);
            TItemData__sub_8010EDD8(out, parm->x13);
            TItemData__sub_8010EDC8(out, parm->x12);
            TItemData__sub_8010EDA8(out, parm->x15);
            ((TItemData *)out)->add_quantity(parm->x14);
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
typedef struct Parm_8010C1E0 Parm_8010C1E0;
typedef struct Parm_8010C320 Parm_8010C320;
void TItemData::add_weapon_stat_bonuses(s32 player, s16 *out, s32 unused, s16 *out2, s32 _w5) {
  s16 hi;
  s32 i;
  Parm_8010C320 *parm;
  f32 mult = get_set_bonus_multiplier__9TItemDataFPvi(this, player);
  f32 add = ((f32 (*)(u8 *, s32)) calc_clock_bonus__9TItemDataFPv)(((u8 *)this), player);
  parm = (Parm_8010C320 *) ((Parm_8010C1E0 *)lookup_item_pmt_record(this));
  if (parm != 0)
  {
    if (out != 0)
    {
      s16 grind = ((u8) (hi = ((s8 *) ((u8 *)this))[3])) * 2;
      s16 lo = (mult * ((f32) (parm->atp_min + grind))) + add;
      hi = (mult * ((f32) (parm->atp_max + grind))) + add;
      TItemData::add_s16(out, lo);
      ((TItemData *)out)->add_stat(hi);
      ((TItemData *)out)->add_accuracy((s16) (parm->x19 * 10));
      for (i = 0; i != 3; i++)
      {
        if (((u8 *)this)[6 + (i * 2)] == 5)
        {
          ((TItemData *)out)->add_accuracy((s16) (((s8) ((u8 *)this)[7 + (i * 2)]) * 10));
        }
      }
    }
    if (out2 != 0)
    {
      out2[1] += parm->x14;
    }
  }
}
#pragma pop

void TItemData::set_wrapped() {
    switch (((struct Item_8010C498 *)this)->kind) {
    case 0:
    case 1:
        ((struct Item_8010C498 *)this)->b4 |= lbl_805DAB68;
        break;
    case 3:
        if (lookup_item_def__9TItemDataFPv(this) == 0) {
            ((struct Item_8010C498 *)this)->b3 |= lbl_805DAB68;
        }
        break;
    case 2:
        ((struct Item_8010C498 *)this)->b12 |= lbl_805DAB68;
        break;
    }
}

u8 is_wrapped__9TItemDataFPv(Item_8010C52C *it) {
    switch (it->kind) {
    case 0:
    case 1:
        return ((it->b4 & 0x40) - 0x40) == 0;
    case 3:
        if (lookup_item_def__9TItemDataFPv(it) != 0) {
            return 0;
        }
        return ((it->b3 & 0x40) - 0x40) == 0;
    case 2:
        return ((it->b12 & 0x40) - 0x40) == 0;
    default:
        return 0;
    }
}

f32 calc_clock_bonus__9TItemDataFPv(u8 *arg0) {
    s32 *var_r4;
    f32 var_f1;
    s32 internet_beat;
    s32 temp_r3_2;
    s32 var_r3;
    var_f1 = lbl_805DAB6C;
    if ((s32) *(u8 *)((s8 *)arg0 + 1) != 0x94) {
        return var_f1;
    }
    internet_beat = TLobby::get_internet_beat();
    var_r3 = internet_beat >> 2;
    var_r3 = internet_beat / 4;
    var_r4 = &lbl_8043E348;
    temp_r3_2 = var_r3;
    var_r3 ^= 0x80000000;
    var_f1 = (f32) temp_r3_2;
    return var_f1;
}

void TItemData::set_packed_value(u16 arg1) {
    *(u8 *)((s8 *)this + 0xA) = (u8) (arg1 >> 8U);
    *(u8 *)((s8 *)this + 0xB) = arg1;
    *(u8 *)((s8 *)this + 0xA) = (u8) (*(u8 *)((s8 *)this + 0xA) | 0x80);
}

u16 TItemData::get_packed_value() {
    if (is_usable__9TItemDataFPv() != 0) {
        return (u16) (((*(u8 *)((s8 *)this + 0xA) << 8) & 0x7F00) | *(u8 *)((s8 *)this + 0xB));
    }
    return 0U;
}
}
#undef get_set_bonus_multiplier__9TItemDataFPvi
#undef lookup_item_pmt_record
#undef getS16_06__9TItemDataFPv
#undef get_bswap16_field8__9TItemDataFPv
#undef lookup_item_def__9TItemDataFPv
#undef get_field6_bswap__9TItemDataFPv
#undef is_usable__9TItemDataFPv

#define is_custom_name_srank__9TItemDataFPv ((s32 (*)())is_custom_name_srank__9TItemDataFPv)
#define serialize_mag__9TItemDataFPvPv ((s32 (*)(void *, s32 *))serialize_mag__9TItemDataFPvPv)
#define init__9TItemDataFv ((s32 (*)())init__9TItemDataFv)

extern "C" {
u8 get_weapon_class_motion_type(u8);
s32 get_item_icon_index(const u8 *q);
void bswap__9TItemDataFv(s32 arg0);

s32 is_usable__9TItemDataFPv(void *arg0) {
    u8 temp_r0;

    if (is_custom_name_srank__9TItemDataFPv() == 0) {
        temp_r0 = *(u8 *)((s8 *)arg0 + 0);
        if ((temp_r0 != 2) && (temp_r0 != 4) && (*(u8 *)((s8 *)arg0 + 0xA) & 0x80)) {
            return 1;
        }
    }
    return 0;
}

void bswap__9TItemDataFv(s32 arg0) {
    bswap_32((u32 *)(arg0 + 0x10));
    bswap_32((u32 *)(arg0 + 0xC));
}

s32 TItemData__sub_8010C738(TItemData *) { return 0; }
void TItemData::convert_from_version(s32) {}

void TItemData::unpack_from_item(void *arg1) {
    s32 sp8;
    u8 temp_r0;

    if (arg1 != NULL) {
        init__9TItemDataFv();
        *(u8 *)((s8 *)this + 0) = (u8) (((u32) *(u32 *)((s8 *)arg1 + 0x30) >> 0x18U) & 0xF);
        *(u8 *)((s8 *)this + 1) = (u8) ((u32) *(u32 *)((s8 *)arg1 + 0x30) >> 0x10U);
        temp_r0 = *(u8 *)((s8 *)this + 0);
        if ((temp_r0 == 0) || (temp_r0 == 1)) {
            *(u8 *)((s8 *)this + 1) = (u8) (*(u8 *)((s8 *)this + 1) + 1);
        }
        *(u8 *)((s8 *)this + 2) = (u8) ((u32) *(u32 *)((s8 *)arg1 + 0x30) >> 8U);
        switch ((s32) (*(u8 *)((s8 *)this + 0))) {
        case 0:
            *(u8 *)((s8 *)this + 6) = (u8) ((u32) *(u32 *)((s8 *)arg1 + 0x34) >> 8U);
            *(s8 *)((s8 *)this + 7) = (s8) *(u32 *)((s8 *)arg1 + 0x34);
            *(s8 *)((s8 *)this + 8) = (s8) ((u32) *(u32 *)((s8 *)arg1 + 0x38) >> 0x18U);
            *(u8 *)((s8 *)this + 9) = (u8) ((u32) *(u32 *)((s8 *)arg1 + 0x38) >> 0x10U);
            *(u8 *)((s8 *)this + 0xA) = (u8) ((u32) *(u32 *)((s8 *)arg1 + 0x38) >> 8U);
            *(s8 *)((s8 *)this + 0xB) = (s8) *(u32 *)((s8 *)arg1 + 0x38);
            *(s8 *)((s8 *)this + 3) = (s8) ((u32) *(u32 *)((s8 *)arg1 + 0x34) >> 0x18U);
            *(u8 *)((s8 *)this + 4) = (u8) *(u32 *)((s8 *)arg1 + 0x30);
            return;
        case 3:
            if ((u8) *(u8 *)((s8 *)this + 1) == 2) {
                *(u8 *)((s8 *)this + 4) = (u8) *(u32 *)((s8 *)arg1 + 0x30);
            }
            ((TShopEquipmentListWindow *)this)->set_stack_count(1);
            return;
        case 4:
            *(s32 *)((s8 *)this + 0x10) = (s32) (((u32) *(u32 *)((s8 *)arg1 + 0x34) >> 0x10U) * 0xA);
            return;
        case 1:
            *(s8 *)((s8 *)this + 5) = (s8) *(u32 *)((s8 *)arg1 + 0x30);
            *(s8 *)((s8 *)this + 3) = (s8) ((u32) *(u32 *)((s8 *)arg1 + 0x34) >> 0x18U);
            *(u8 *)((s8 *)this + 4) = (u8) ((u32) *(u32 *)((s8 *)arg1 + 0x34) >> 0x10U);
            return;
        case 2:
            ((TItemData *)(&sp8))->initialize_mag_data();
            serialize_mag__9TItemDataFPvPv(this, &sp8);
            break;
        }
    }
}
s32 get_item_icon_index(const u8 *q) {
    u8 v;
    if (q[0] == 0) {
        Tbl_8010C8B4 t = item_icon_index_by_category_table;
        if ((v = q[1]) < 0xAA) {
            v = get_weapon_class_motion_type(v);
        }
        if (v < 0x13) {
            return t.w[v];
        }
    }
    return 0;
}

#undef is_custom_name_srank__9TItemDataFPv
#undef serialize_mag__9TItemDataFPvPv
#undef init__9TItemDataFv

#define lookup_item_pmt_record ((void * (*)())lookup_item_pmt_record)
#define lookup_item_def__9TItemDataFPv ((s32 (*)())lookup_item_def__9TItemDataFPv)
#define init__9TItemDataFv ((s32 (*)())init__9TItemDataFv)
s32 strncpy(s8 *, u32, s32);
void TItemData__sub_8010CA08(TItemData *arg0, u32 arg1, u8 arg2);
s32 TItemData__sub_8010CAB0(s32 arg0, s8 arg1);
int register_item_drop__10TObjPlayerFv(void*);

}
int TItemData::isValidGroundDrop() {
    u8 category;
    u8 group;
    if (find_item_by_id(id) == 0U) {
        category=data1.data_u8[0];
        switch ((s32)category) {
        case 3:
        case 0:
            if (((u32 (*)(TItemData*))lookup_item_pmt_record)(this) == 0U) return 0;
            break;
        case 1:
            group=data1.data_u8[1];
            if ((group == 0) && (group >= 4U)) return 0;
            break;
        case 2:return 1;
        case 4:
            if ((s32)data2.data_u32 == 0) return 0;
            break;
        default:return 0;
        }
        return 1;
    } else return 0;
}

void TItemData__sub_8010CA08(TItemData *item_data, u32 arg1, u8 arg2) {
    s8 sp8[10];
    init__9TItemDataFv();
    if ((arg1 != 0U) && (((arg2 >= 0x70U) && (arg2 <= 0x88U)) || ((arg2 >= 0xA5U) && (arg2 <= 0xA9U)))) {
        *(s8 *)((s8 *)item_data + 0) = 0;
        *(u8 *)((s8 *)item_data + 1) = arg2;
        *(s8 *)((s8 *)item_data + 2) = 0;
        memset(sp8, 0, 0xA);
        sp8[0] = 0x41;
        strncpy(&sp8[1], arg1, 8);
        item_data->pack_three_colors((u8 *)sp8);
    }
}

s32 TItemData__sub_8010CAB0(s32 arg0, s8 arg1) {
    return (arg1 != 0) ? (s8)(arg1 + 0x40) : 0;
}

s8 TItemData::char_to_letter_index(void *self, s8 c) {
    s8 r = 0;
    if (c >= 'a' && c <= 'z') {
        r = c - 0x60;
    } else if (c >= 'A' && c <= 'Z') {
        r = c - 0x40;
    }
    return r;
}

void TItemData::decode_packed_name_chars(s8 *out) {
  u16 h;
  s8 *p;
  s32 i;
  if (out != 0)
  {
    p = out;
    i = 0;
    do
    {
      u8 *q = &((u8 *)this)[i * 2];
      u8 hi = q[6] & 0xFFFFFFFFFFFFFFFFu;
      u8 lo = q[7];
      h = lo | ((hi << 8) & 0x7F00);
      p[0] = ((s8 (*)(void *, s8)) TItemData__sub_8010CAB0)(this, (h >> 10) & 0x3F);
      p[1] = ((s8 (*)(void *, s8)) TItemData__sub_8010CAB0)(this, (h >> 5) & 0x1F);
      p[2] = ((s8 (*)(void *, s8)) TItemData__sub_8010CAB0)(this, h & 0x1F);
      i++;
      p += 3;
    }
    while (i != 3);
  }
}

void TItemData::pack_three_colors(u8 *in) {
  s32 i;
  if (in != 0)
  {
    for (i = 0; i != 3; i++)
    {
      s8 a = TItemData::char_to_letter_index(this, (s8) in[(i * 3) + 0]);
      s8 b = TItemData::char_to_letter_index(this, (s8) in[(i * 3) + 1]);
      s8 c = TItemData::char_to_letter_index(this, (s8) in[(i * 3) + 2]);
      u32 v = c | (((a << 1) << 9) | (b << 5));
      u8 *o = &((u8 *)this)[i * 2];
      a = ((u8) (v >> 8)) | 0x80;
      o[6] = a;
      o[7] = v;
    }
  }
}

s32 is_custom_name_srank__9TItemDataFPv(u8 *arg0) {
    u8 temp_r0;
    if ((u8) *(u8 *)((s8 *)arg0 + 0) == 0) {
        temp_r0 = *(u8 *)((s8 *)arg0 + 1);
        if ((temp_r0 >= 0x70U) && (temp_r0 <= 0x88U)) {
            return 1;
        }
        if ((temp_r0 >= 0xA5U) && (temp_r0 <= 0xA9U)) {
            return 1;
        }
    }
    return 0;
}

void TItemData::decode_from_network() {}
void TItemData::encode_for_network() {}
u8 TItemData::get_entry_field16() {
    void *item_pmt_record;

    item_pmt_record = lookup_item_pmt_record();
    if (item_pmt_record != NULL) {
        return *(u8 *)((s8 *)item_pmt_record + 0x16);
    }
    return 0U;
}
int TItemData::register_drop() { return register_item_drop__10TObjPlayerFv(this); }

s32 TItemData::get_max_stack_size() {
    u8 *arg0 = (u8 *)this;
    if (lookup_item_def__9TItemDataFPv() != 0) {
        if (((u8) *(u8 *)((s8 *)arg0 + 0) == 3) && ((u8) *(u8 *)((s8 *)arg0 + 1) == 0x10)) {
            return 0x63;
        }
        return 0xA;
    }
    return 1;
}

#undef lookup_item_pmt_record
#undef lookup_item_def__9TItemDataFPv
#undef init__9TItemDataFv

#include "pso/TAdRicoRing.h"
#include "pso/TItemMenuCtrl.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItemMag.h"
#include "pso/item/TItemProShield.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"

#define calc_clock_bonus__9TItemDataFPv ((s32 (*)(void *, s32))calc_clock_bonus__9TItemDataFPv)
#define add_armor_stat_contribution__9TItemDataFPviiPv ((s32 (*)(void *, s32, s32, s32, s32, s32))add_armor_stat_contribution__9TItemDataFPviiPv)
#define is_wrapped__9TItemDataFPv ((s32 (*)())is_wrapped__9TItemDataFPv)
#define add_shield_stat_contribution__9TItemDataFPviiPv ((s32 (*)(void *, s32, s32, s32, s32, s32))add_shield_stat_contribution__9TItemDataFPviiPv)
#define apply_unit_stat_bonus__9TItemDataFPviiPvPvPv ((s32 (*)(void *, s32, s32, s32, s32, s32))apply_unit_stat_bonus__9TItemDataFPviiPvPvPv)
#define apply_bonuses ((s32 (*)(void *, s32, s32, s32, s32, s32))apply_bonuses)
#define is_custom_name_srank__9TItemDataFPv ((s32 (*)(void *))is_custom_name_srank__9TItemDataFPv)
#define memset ((void * (*)(void *, int, int))memset)

struct Pair_8010E344 { u8 a; u8 b; };

struct TItemData_8010E344 { u8 data[6]; Pair_8010E344 stats[3]; s32 id; s32 data2; };

struct Mag_8010D510 { s16 f0; s16 f2; s16 stat[4]; u8 b0c; u8 b0d; u8 b0e; };

struct Item_8010D510 {
    u8 b0; u8 b1; u8 level; u8 b3;
    s16 stat[4];
    u32 word;
    u8 b16; u8 b17; u8 b18; u8 b19;
};

struct Parm_8010EBD8 { s32 name; u8 pad04[0xC]; u32 flags; };

struct Params_8010E414 { s32 name; u8 pad4[4]; s16 stat; s16 amount; };

struct Item_8010E59C {
    u8 type;
    u8 sub;
    u8 b2;
    u8 grind;
    u8 flags;
    u8 pad5[0xB];
    s32 meseta;
};

extern f32 TItemData__data_805DAB70;
extern const f32 lbl_805DAB74;
extern f32 TItemData__data_805DAB78;
extern "C" {
void deserialize_mag__9TItemDataFPvPv(Raw_8010D614 *src, Mag_8010D614 *dst);
void *get_armor_pmt_record(int type, int id);
s16 get_mag_total_level(void *mag);
s32 get_item_star_count(s32);
s32 is_rare_item__9TItemDataFPv(u8 *item);
int get_item_chunk_buffer(int a0);
s32 get_item_description_text(s32);
int sprintf(char *, const char *, ...);
}
extern s32 lbl_805D2B10;
s32 format_item_description(u8 *item);
extern "C" {
s32 TObjPlayer__sub_80117E50(u16);
extern const f32 lbl_805DAB7C;
s32 get_technique_name(s32 arg0);
s32 get_text_collection(s32 arg0);
s8 *get_item_by_slot_flag__10TObjPlayerFUc(u8);
extern char lbl_8043E358[];
extern char lbl_8043E360[];
extern char lbl_8043E368[];
extern char lbl_8043E374[];
extern char lbl_8043E37C[];
extern char lbl_8043E384[];
extern char lbl_8043E390[];
extern char lbl_805DAB8C;
void TItemData__clear_unidentified_flag(void *arg0);
void add_mag_stat_bonuses__9TItemDataFv(u8 *item, s32 player, u8 *a, u8 *b, EquipStats *st, s32 w5);
s32 get_unit_attribute_index__10TObjPlayerFUc(u8);

void lookup_item_def__9TItemDataFPv(void *arg0) {
    is_item_stackable(*(u8 *)((s8 *)arg0 + 0), *(u8 *)((s8 *)arg0 + 1));
}
s16 get_field6_bswap__9TItemDataFPv(void *arg0) {
    s16 sp8;

    sp8 = *(s16 *)((s8 *)arg0 + 6);
    bswap_16((u16 *)&sp8);
    return sp8;
}

void TItemData::set_unit_modifier(s16 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s16 *)((s8 *)arg0 + 6) = arg1;
    bswap_16((u16 *)(arg0 + 6));
}

s16 get_bswap16_field8__9TItemDataFPv(void *arg0) {
    s16 sp8;

    sp8 = *(s16 *)((s8 *)arg0 + 8);
    bswap_16((u16 *)&sp8);
    return sp8;
}

void TItemData::set_bswapped_field_8(s16 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s16 *)((s8 *)arg0 + 8) = arg1;
    bswap_16((u16 *)(arg0 + 8));
}

s16 getS16_06__9TItemDataFPv(void *arg0) {
    s16 sp8;

    sp8 = *(s16 *)((s8 *)arg0 + 6);
    bswap_16((u16 *)&sp8);
    return sp8;
}

void TItemData::set_dfp_bonus(s16 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s16 *)((s8 *)arg0 + 6) = arg1;
    bswap_16((u16 *)(arg0 + 6));
}

s16 TItemData::get_technique_level() {
    void *temp_r3;

    if (((u8) *(u8 *)((s8 *)this + 0) == 3) && ((u8) *(u8 *)((s8 *)this + 1) == 2)) {
        temp_r3 = calc_technique_parameters(*(u8 *)((s8 *)this + 4), *(u8 *)((s8 *)this + 2), 0xFFFF);
        if (temp_r3 != NULL) {
            return *(s16 *)((s8 *)temp_r3 + 0x14);
        }
    }
    return 0;
}

s32 TItemData::has_bonus_stats() {
    TItemData_8010E344 *item = (TItemData_8010E344 *)this;
    s32 i;
    switch (item->data[0]) {
    case 0:
        for (i = 0; i < 3; i++) {
            if (item->stats[i].a != 0) {
                return 1;
            }
        }
        break;
    case 1:
        switch (item->data[1]) {
        case 1:
            if (item->data[5] != 0) {
                return 1;
            }
        case 2:
            if (getS16_06__9TItemDataFPv(item) > 0 || get_bswap16_field8__9TItemDataFPv(item) > 0) {
                return 1;
            }
            break;
        case 3:
            if (((s16 (*)(void))get_field6_bswap__9TItemDataFPv)() > 0) {
                return 1;
            }
            break;
        }
        break;
    case 2:
        switch (item->data[1]) {
        case 0x1D:
        case 0x21:
        case 0x22:
        case 0x27:
            return 1;
        }
        break;
    }
    return 0;
}

typedef struct VBase_18_38db83 VBase_18_38db83;
typedef struct VObj_18_38db83 VObj_18_38db83;
#define PSO_VCALL_VObj_18_38db83_m37(_self) (((VObj_18_38db83 *)(_self))->m37())
s32 TItemData::calc_action_flags(s32 mask, u8 *player) {
  s32 result;
  u16 id;
  s32 hit;
  u8 *rec;
  s32 flags;
  s32 lvl;
  u8 buf[0x14];
  result = 0;
  if (player == 0)
  {
    player = (u8 *) get_player_by_client_id(local_client_id);
    id = (u16) local_client_id;
  }
  else
  {
    id = obj_getField1c(player);
  }
  if (player == 0)
  {
    return 0;
  }
  if (is_item_usable__9TItemDataFlPUc(player, this) != 0)
  {
    result |= 2;
  }
  if (((s32 (*)(void *)) is_wrapped__9TItemDataFPv)(this) != 0)
  {
    return result & mask;
  }
  if (((u8 *)this)[0] != 3)
  {
    result |= 8;
    if (check_equip_requirements(player, this, 0) == 0)
    {
      result |= 0x10000;
    }
  }
  else
  {
    s32 perm;
    rec = (u8 *) lookup_item_pmt_record(((u8 *)this));
    perm = check_class_equip_permission(player, 0xD7);
    if (rec != 0)
    {
      flags = *((s32 *)(rec + 0x10));
      if (!(flags & 2))
      {
        result |= 0x10;
      }
      if (flags & 4)
      {
        result |= 4;
      }
      if ((!(flags & 8)) && (perm != 0))
      {
        result |= 0x10001;
      }
      if ((!(flags & 0x10)) && (reset_key_machine_state__10TObjPlayerFv() == 0))
      {
        result |= 1;
      }
      if ((!(flags & 0x20)) && (is_boss_area() != 0))
      {
        result |= 1;
      }
      if ((!(flags & 0x40)) && ((is_flag_set__6TLobbyFv() != 0) || (is_challenge_mode_active() != 0)))
      {
        result |= 1;
      }
    }
    switch (((u8 *)this)[1])
    {
      case 6:
        switch (((u8 *)this)[2])
      {
        case 0:
          if (obj_getArrWord_254(player, 0) != 0xF)
        {
          result |= 1;
        }
          break;
        case 1:
          if (obj_getArrWord_254(player, 0) != 0x10)
        {
          result |= 1;
        }
          break;
      }
        break;
      case 7:
        if (TObjWarpBossMulti::is_flag_clear(player) == 0)
      {
        result |= 1;
      }
        break;
      case 2:
      {
        u8 *tech;
        u8 cur;
        u8 lim;
        lvl = ((u8 *)this)[2];
        tech = (u8 *) calc_technique_parameters(((u8 *)this)[4], lvl, 0xFFFF);
        if (tech != 0)
        {
          if ((*((s16 *) (get_quest_id__12TQuestListVMFv(player) + 2))) < (*((s16 *)(tech + 0x14))))
          {
            result |= 0x10001;
          }
          cur = get_cast_technique_level(player + 0x428, (s16) ((u8 *)this)[4]);
          if ((is_invalid_slot__10TObjPlayerFUc() == 0) && (((u8 *)this)[2] <= cur))
          {
            result |= 0x10001;
          }
          lim = get_technique_learn_limit(player[0x88D], (short) ((u8 *)this)[4]);
          if ((lim == 0xFF) || (lim < lvl))
          {
            result |= 0x10001;
          }
        }
        break;
      }
      case 10:
      {
        void *it = (void *) get_item_field_6__10TObjPlayerFPv(player);
        if (it != 0)
        {
          ((TItem *)it)->copy_to_item_data((TItemData *)buf);
          rec = (u8 *) lookup_item_pmt_record(buf);
          if ((rec != 0) && (rec[0x16] <= buf[3]))
          {
            result |= 1;
          }
        }
        else
        {
          result |= 1;
        }
        break;
      }
      case 11:
      {
        u8 *quest = get_quest_id__12TQuestListVMFv(player);
        if (quest != 0)
        {
          hit = 0;
          switch (((u8 *)this)[2])
          {
            case 0:
              if ((get_class_stat_entry__10TObjPlayerFPUc(player)[0 / 2] <= ((s16 *) quest)[0 / 2]) || (update_player_field__9TItemDataFv(player) != 0))
            {
              hit = 1;
            }
              break;
            case 1:
              if ((get_class_stat_entry__10TObjPlayerFPUc(player)[2 / 2] <= ((s16 *) quest)[2 / 2]) || (update_player_field__9TItemDataFv(player) != 0))
            {
              hit = 1;
            }
              break;
            case 2:
              if ((get_class_stat_entry__10TObjPlayerFPUc(player)[4 / 2] <= ((s16 *) quest)[4 / 2]) || (update_player_field__9TItemDataFv(player) != 0))
            {
              hit = 1;
            }
              break;
            case 3:
              if (calc_equip_bonus(id) >= 0xFA)
            {
              hit = 1;
            }
              break;
            case 4:
              if (calc_stat_bonus_sum(id) >= 0xFA)
            {
              hit = 1;
            }
              break;
            case 5:
              if ((get_class_stat_entry__10TObjPlayerFPUc(player)[8 / 2] <= ((s16 *) quest)[8 / 2]) || (update_player_field__9TItemDataFv(player) != 0))
            {
              hit = 1;
            }
              break;
            case 6:
              if ((get_class_stat_entry__10TObjPlayerFPUc(player)[0xC / 2] <= ((s16 *) quest)[0xC / 2]) || (update_player_field__9TItemDataFv(player) != 0))
            {
              hit = 1;
            }
              break;
          }
          if (hit != 0)
          {
            result |= 0x10001;
          }
        }
        break;
      }
      case 12:
        if (TItemMag::check_evolution_cond((u32)player, (s32)(((u8 *)this)[2])) == 0)
      {
        result |= 1;
      }
        break;
      case 15:
      {
        void *mag = (void *) ((TItemData *)player)->get_item_field_2();
        if (mag != 0)
        {
          if (PSO_VCALL_VObj_18_38db83_m37(mag) >= 4)
          {
            result |= 1;
          }
        }
        else
        {
          result |= 1;
        }
        break;
      }
    }
  }
  if (((is_quest_active() != 0) && (((u8 *)this)[0] == 3)) && (TItemMenuCtrl::query_flag(6) == 1))
  {
    result |= 0x10001;
  }
  return result & mask;
}

void serialize_mag__9TItemDataFPvPv(Item_8010D510 *item, const Mag_8010D510 *mag) {
    Item_8010D510 copy;
    copy.b0 = item->b0;
    copy.b1 = item->b1;
    copy.level = get_mag_total_level((void *)mag);
    copy.b3 = mag->b0d;
    copy.stat[0] = mag->stat[0] & 0x7FFE;
    copy.stat[1] = mag->stat[1] & 0x7FFE;
    copy.stat[2] = mag->stat[2] & 0x7FFE;
    copy.stat[3] = mag->stat[3] & 0x7FFE;
    copy.word = item->word;
    copy.b16 = mag->f2;
    copy.b17 = mag->f0;
    copy.b18 = mag->b0c;
    copy.b19 = mag->b0e;
    ((TItemData *)(&copy))->bswap_fields();
    ((ItemData *)item)->copy_from((ItemData *)(&copy));
}

void TItemData::bswap_fields() { bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_16((u16 *)((char*)this + 0x8)); bswap_16((u16 *)((char*)this + 0xa)); }

void deserialize_mag__9TItemDataFPvPv(Raw_8010D614 *src, Mag_8010D614 *dst) {
    if (dst != 0) {
        Raw_8010D614 tmp = *src;
        ((TItemData *)(&tmp))->bswap_fields();
        dst->d = tmp.b[3];
        dst->s[0] = tmp.s[0] & 0x7ffe;
        dst->s[1] = tmp.s[1] & 0x7ffe;
        dst->s[2] = tmp.s[2] & 0x7ffe;
        dst->s[3] = tmp.s[3] & 0x7ffe;
        dst->a2 = tmp.c[0];
        dst->a0 = tmp.c[1];
        dst->c = tmp.c[2];
        dst->e = tmp.c[3];
    }
}

f32 TItemData::get_shield_set_multiplier(u8 *arg1) {
    u8 *arg0 = (u8 *)this;
  s32 temp_r31;
  f32 var_f31;
  s32 temp_r30;
  s32 temp_r30_2;
  s32 temp_r30_3;
  s32 temp_r31_2;
  s32 temp_r31_3;
  u8 temp_r0;
  u8 *temp_r3;
  temp_r0 = *((u8 *) (((s8 *) arg0) + 2));
  var_f31 = TItemData__data_805DAB70;
  switch ((s32) temp_r0)
  {
    case 26:
      temp_r3 = (u8 *) get_item_field_6__10TObjPlayerFPv(arg1);
      if ((temp_r3 != 0) && (((TItem *)temp_r3)->get_item_group() == 0x1A))
    {
      var_f31 = lbl_805DAB74;
    }
      break;
    case 38:
      temp_r31 = get_item_field_6__10TObjPlayerFPv(arg1);
      temp_r30 = ((TItemData *)arg1)->get_item_field_2();
      if (((((((u32) temp_r31) != 0U) && (((u32) temp_r30) != 0U)) && (((TItem *)temp_r31)->get_item_group() == 1)) && (((TItem *)temp_r31)->get_item_index() == 5)) && (((TItem *)temp_r30)->get_item_index() == 0x28))
    {
      var_f31 = TItemData__data_805DAB78;
    }
      break;
    case 36:
      temp_r30_2 = get_item_field_6__10TObjPlayerFPv(arg1);
      temp_r31_2 = ((TItemData *)arg1)->get_item_field_2();
      if (((((((u32) temp_r30_2) != 0U) && (((u32) temp_r31_2) != 0U)) && (((TItem *)temp_r30_2)->get_item_group() == 2)) && (((TItem *)temp_r30_2)->get_item_index() == 5)) && (((TItem *)temp_r31_2)->get_item_index() == 0x26))
    {
      var_f31 = TItemData__data_805DAB78;
    }
      break;
    case 37:
      temp_r30_3 = get_item_field_6__10TObjPlayerFPv(arg1);
      temp_r31_3 = ((TItemData *)arg1)->get_item_field_2();
      if (((((((u32) temp_r30_3) != 0U) && (((u32) temp_r31_3) != 0U)) && (((TItem *)temp_r30_3)->get_item_group() == 6)) && (((TItem *)temp_r30_3)->get_item_index() == 6)) && (((TItem *)temp_r31_3)->get_item_index() == 0x27))
    {
      var_f31 = TItemData__data_805DAB78;
    }
      break;
  }
  return var_f31;
}

f32 TItemData::get_armor_set_multiplier(u8 *arg1) {
    u8 *arg0 = (u8 *)this;
    f32 v;
    s32 b1;
    s32 a1;
    s32 a2;
    s32 b2;
    s32 a3;
    s32 b3;
    s32 i;
    s32 found;
    s32 hit;
    s32 j;
    s32 hit2;
    s32 k;
    s32 p;
    u8 c;
    v = TItemData__data_805DAB70;
    switch (arg0[2]) {
    case 24:
        found = 0;
        for (i = 0; i != 12 && found != 1; i++) {
            p = get_player_by_client_id(i);
            if ((u32)p != 0) {
                p = ((TItemData *)p)->get_item_field_2();
                if ((u32)p != 0) {
                    c = ((TItem *)p)->get_item_index();
                    if (c == 0x19 || c == 0x1A) {
                        v = lbl_805DAB7C;
                        found = 1;
                    }
                }
            }
        }
        break;
    case 25:
        hit = 0;
        for (j = 0; j != 12 && hit != 1; j++) {
            p = get_player_by_client_id(j);
            if ((u32)p != 0) {
                p = ((TItemData *)p)->get_item_field_2();
                if ((u32)p != 0) {
                    c = ((TItem *)p)->get_item_index();
                    if (c == 0x1A || c == 0x18) {
                        v = lbl_805DAB7C;
                        hit = 1;
                    }
                }
            }
        }
        break;
    case 26:
        hit2 = 0;
        for (k = 0; k != 12 && hit2 != 1; k++) {
            p = get_player_by_client_id(k);
            if ((u32)p != 0) {
                p = ((TItemData *)p)->get_item_field_2();
                if ((u32)p != 0) {
                    c = ((TItem *)p)->get_item_index();
                    if (c == 0x19 || c == 0x18) {
                        v = lbl_805DAB7C;
                        hit2 = 1;
                    }
                }
            }
        }
        break;
    case 40:
        a1 = get_item_field_6__10TObjPlayerFPv(arg1);
        b1 = ((TItemData *)arg1)->test_flag3();
        if ((u32)a1 != 0 && (u32)b1 != 0 && ((TItem *)a1)->get_item_group() == 1 && ((TItem *)a1)->get_item_index() == 5 && ((TItem *)b1)->get_item_index() == 0x26) {
            v = TItemData__data_805DAB78;
        }
        break;
    case 38:
        a2 = get_item_field_6__10TObjPlayerFPv(arg1);
        b2 = ((TItemData *)arg1)->test_flag3();
        if ((u32)a2 != 0 && (u32)b2 != 0 && ((TItem *)a2)->get_item_group() == 2 && ((TItem *)a2)->get_item_index() == 5 && ((TItem *)b2)->get_item_index() == 0x24) {
            v = TItemData__data_805DAB78;
        }
        break;
    case 39:
        a3 = get_item_field_6__10TObjPlayerFPv(arg1);
        b3 = ((TItemData *)arg1)->test_flag3();
        if ((u32)a3 != 0 && (u32)b3 != 0 && ((TItem *)a3)->get_item_group() == 6 && ((TItem *)a3)->get_item_index() == 6 && ((TItem *)b3)->get_item_index() == 0x25) {
            v = TItemData__data_805DAB78;
        }
        break;
    case 45:
        if (TObjPlayer__sub_80117E50(obj_getField1c(arg1)) != 0) {
            v = TItemData__data_805DAB78;
        }
        break;
    }
    return v;
}

f32 TItemData::get_weapon_set_multiplier(u8 *item_data) {
    u8 *arg0 = (u8 *)this;
  f32 var_f31;
  s32 temp_r31;
  s32 temp_r30;
  s32 temp_r30_2;
  s32 temp_r30_3;
  s32 temp_r31_2;
  s32 temp_r31_3;
  u8 temp_r0;
  u8 *item;
  temp_r0 = *((u8 *) (((s8 *) arg0) + 1));
  var_f31 = TItemData__data_805DAB70;
  switch ((s32) temp_r0)
  {
    case 1:
      if (((u8) (*((u8 *) (((s8 *) arg0) + 2)))) == 5)
    {
      temp_r31 = ((TItemData *)item_data)->test_flag3();
      temp_r30 = ((TItemData *)item_data)->get_item_field_2();
      if ((((((u32) temp_r31) != 0U) && (((u32) temp_r30) != 0U)) && (((TItem *)temp_r31)->get_item_index() == 0x26)) && (((TItem *)temp_r30)->get_item_index() == 0x28))
      {
        var_f31 = TItemData__data_805DAB78;
      }
    }
      break;
    case 2:
      if (((u8) (*((u8 *) (((s8 *) arg0) + 2)))) == 5)
    {
      temp_r30_2 = ((TItemData *)item_data)->test_flag3();
      temp_r31_2 = ((TItemData *)item_data)->get_item_field_2();
      if ((((((u32) temp_r30_2) != 0U) && (((u32) temp_r31_2) != 0U)) && (((TItem *)temp_r30_2)->get_item_index() == 0x24)) && (((TItem *)temp_r31_2)->get_item_index() == 0x26))
      {
        var_f31 = TItemData__data_805DAB78;
      }
    }
      break;
    case 6:
      if (((u8) (*((u8 *) (((s8 *) arg0) + 2)))) == 6)
    {
      temp_r30_3 = ((TItemData *)item_data)->test_flag3();
      temp_r31_3 = ((TItemData *)item_data)->get_item_field_2();
      if ((((((u32) temp_r30_3) != 0U) && (((u32) temp_r31_3) != 0U)) && (((TItem *)temp_r30_3)->get_item_index() == 0x25)) && (((TItem *)temp_r31_3)->get_item_index() == 0x27))
      {
        var_f31 = TItemData__data_805DAB78;
      }
    }
      break;
    case 26:
      item = (u8 *) ((TItemData *)item_data)->test_flag3();
      if ((item != 0) && (((TItem *)item)->get_item_index() == 0x1A))
    {
      var_f31 = lbl_805DAB74;
    }
      break;
  }
  return var_f31;
}

f32 get_set_bonus_multiplier__9TItemDataFPvi(void *self, s32 player) {
    u8 *item = (u8 *)self;
    switch (item[0]) {
    case 0:
        return ((TItemData *)item)->get_weapon_set_multiplier((u8 *)player);
    case 1:
        switch (item[1]) {
        case 1:
            return ((TItemData *)item)->get_armor_set_multiplier((u8 *)((u8 *)player));
        case 2:
            return ((TItemData *)item)->get_shield_set_multiplier((u8 *)player);
        }
        break;
    }
    return TItemData__data_805DAB70;
}

void TItemData::apply_equip_effects(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {

    if ((arg1 != 0) || (arg1 = get_player_by_client_id(local_client_id), ((arg1 == 0) == 0))) {
        get_set_bonus_multiplier__9TItemDataFPvi(this, arg1);
        calc_clock_bonus__9TItemDataFPv(this, arg1);
        switch ((s32) (*(u8 *)((s8 *)this + 0))) {
        case 0:
            add_weapon_stat_bonuses((s32)arg1, (s16 *)arg2, (s32)arg3, (s16 *)arg4, (s32)arg5);
            break;
        case 1:
            switch ((s32) (*(u8 *)((s8 *)this + 1))) {
            case 1:
                add_armor_stat_contribution__9TItemDataFPviiPv(this, arg1, arg2, arg3, arg4, arg5);
                break;
            case 2:
                add_shield_stat_contribution__9TItemDataFPviiPv(this, arg1, arg2, arg3, arg4, arg5);
                break;
            case 3:
                apply_unit_stat_bonus__9TItemDataFPviiPvPvPv(this, arg1, arg2, arg3, arg4, arg5);
                break;
            }
            break;
        case 2:
            add_mag_stat_bonuses__9TItemDataFv((u8 *)this, arg1, (u8 *)arg2, (u8 *)arg3, (EquipStats *)arg4, arg5);
            break;
        }
        apply_bonuses(this, arg1, arg2, arg3, arg4, arg5);
        apply_custom_shield_bonus(arg1, (TItemData *)arg2, (TItemData *)arg3, (EquipStats *)arg4, arg5);
    }
}

s32 is_rare_item__9TItemDataFPv(u8 *item) {
    return (u8) ((TItemData *)item)->get_base_rarity() >= 9 ? 1 : 0;
}

#pragma push
#pragma fp_contract on
extern "C" {

typedef struct Item_8010DF9C Item_8010DF9C;
typedef struct Pct_8010DF9C Pct_8010DF9C;
typedef struct Pmt_8010DF9C Pmt_8010DF9C;
struct Pct_8010DF9C
{
  u8 type;
  s8 value;
};
struct Item_8010DF9C
{
  u8 type;
  u8 sub;
  u8 b2;
  u8 grind;
  u8 flags;
  u8 slots;
  Pct_8010DF9C pct[3];
  u8 pad_c[4];
  s32 meseta;
};
struct Pmt_8010DF9C
{
  u8 pad0[8];
  s16 dfp;
  s16 evp;
  u16 atp;
  u8 pad_e[2];
  u8 level;
};
f32 get_item_price_coefficient(u8 arg0, u8 arg1);
extern const f32 lbl_805DAB80;
extern const f32 lbl_805DAB84;
extern const f32 lbl_805DAB88;
s32 TItemData::calc_price() {
  Item_8010DF9C *item = (Item_8010DF9C *) this;
  Pmt_8010DF9C *pmt;
  s32 price;
  f32 coef;
  f32 power;
  f32 atp;
  f32 stars;
  s32 bonus;
  s32 i;
  price = 0;
  switch (item->type)
  {
    case 0:
      if (item->flags & 0x80)
    {
      price = 8;
    }
    else
      if (is_rare_item__9TItemDataFPv(((u8 *)this)) != 0)
    {
      price = 0x50;
    }
    else
    {
      pmt = (Pmt_8010DF9C *) lookup_item_pmt_record(((u8 *)this));
      coef = get_item_price_coefficient(item->type, (unsigned long) item->sub);
      if ((lbl_805DAB6C != coef) && (pmt != 0))
      {
        atp = ((f32) pmt->atp) + ((f32) item->grind);
        power = (atp * atp) / coef;
        bonus = 0;
        for (i = 0; i < 3; i++)
        {
          if ((item->pct[i].type != 0) && (item->pct[i].type <= 5))
          {
            bonus = (item->pct[i].value + bonus) + 100;
          }
          else
          {
            bonus += 100;
          }
        }

        stars = (f32) ((u8) get_unit_attribute_index__10TObjPlayerFUc(item->flags));
        price = (s32) ((lbl_805DAB84 * (stars * stars)) + ((power * ((f32) bonus)) / lbl_805DAB80));
      }
    }
      break;

    case 1:
      if (is_rare_item__9TItemDataFPv(((u8 *)this)) != 0)
    {
      price = 0x50;
    }
    else
      if (item->sub != 3)
    {
      coef = get_item_price_coefficient(item->type, item->sub);
      pmt = (Pmt_8010DF9C *) lookup_item_pmt_record(((u8 *)this));
      if ((lbl_805DAB6C != coef) && (pmt != 0))
      {
        s32 a = getS16_06__9TItemDataFPv(this);
        atp = (f32) (((pmt->dfp + pmt->evp) + a) + get_bswap16_field8__9TItemDataFPv(this));
        {
          s32 dv = (s32) ((atp * atp) / coef);
          f32 sl = lbl_805DAB88 * ((f32)(item->slots + 1));
          f32 lv = (f32)(pmt->level + 1);
          price = (s32) ((sl * lv) + ((f32) dv));
        }
      }
    }
    else
    {
      coef = get_item_price_coefficient(item->type, item->sub);
      stars = (f32) ((u8) this->calc_display_grade());
      price = (s32) (stars * coef);
    }
      break;

    case 4:
      price = item->meseta;
      break;

    case 3:
      pmt = (Pmt_8010DF9C *) lookup_item_pmt_record(((u8 *)this));
      if (pmt != 0)
    {
      if (item->sub != 2)
      {
        price = *((s32 *) (((u8 *) pmt) + 0xC));
      }
      else
      {
        price = (*((s32 *) (((u8 *) pmt) + 0xC))) * ((u8)(item->b2 + 1));
      }
    }
      break;

    case 2:
      price = (s32) (((f32)(item->b2 + 1)) * get_item_price_coefficient(item->type, item->sub));
      break;

  }

  if (price < 0)
  {
    price = 0;
  }
  return price;
}

}
#pragma pop

void init__9TItemDataFv(TItemData_8010E344 *self) {
    s32 i;
    self->data[0] = 0;
    self->data[1] = 0;
    self->data[2] = 0;
    self->data[3] = 0;
    self->data[4] = 0;
    self->data[5] = 0;
    self->data2 = 0;
    for (i = 0; i < 3; i++) {
        self->stats[i].a = 0;
        self->stats[i].b = 0;
    }
    self->id = -1;
}

s32 TItemData::calc_buy_price() {
    u8 temp_r0;

    if ((u8) *(u8 *)((s8 *)this + 0) == 0) {
        temp_r0 = *(u8 *)((s8 *)this + 4);
        if ((temp_r0 != 0) && (temp_r0 < 0x29U) && (((s32 (*)(void))is_rare_item__9TItemDataFPv)() == 0)) {
            if (check_item_flags() == 1) {
                return get_item_description_text(*(u8 *)((s8 *)this + 4) + 0x1CB);
            }
            return get_item_description_text(0x1F4);
        }
    }
    return lbl_805D2B10;
}
}

s32 format_item_description(u8 *item) {
    char *format;
    Params_8010E414 *p;
    char *out;
    s32 name;
    p = (Params_8010E414 *)lookup_item_pmt_record(item);
    out = (char *)get_item_chunk_buffer(0);
    if (p != NULL && out != NULL) {
        format = NULL;
        if (((s32 (*)(u8 *))is_wrapped__9TItemDataFPv)(item) != 0) {
            format = (char *)get_item_description_text(0x77);
        } else {
            name = p->name;
            if (name == 0x1F4) {
                return lbl_805D2B10;
            }
            if (item[0] == 0) {
                if (is_rare_item__9TItemDataFPv(item) != 0 && ((TItemData *)item)->check_item_flags() == 0) {
                    format = (char *)get_item_description_text(0x17E);
                } else {
                    format = (char *)get_item_description_text(name);
                }
            } else if (item[0] == 1 && item[1] == 3) {
                if (name < 0x2E2) {
                    if (p != NULL && out != NULL && p->stat != 0x1C) {
                        sprintf(out, (char *)get_item_description_text(name), p->amount + get_field6_bswap__9TItemDataFPv(item));
                        return (s32)out;
                    }
                } else {
                    format = (char *)get_item_description_text(name);
                }
            } else {
                format = (char *)get_item_description_text(name);
            }
        }
        if (format != NULL) {
            sprintf(out, format, ((TItemData *)item)->get_packed_value());
        }
    return (s32)out;
    }
    return lbl_805D2B10;
}

void TItemData::format_item_name(char *buf) {
    u8 *arg0 = (u8 *)this;
    Item_8010E59C *item = (Item_8010E59C *)arg0;
    s8 *slot;
    char *name;
    s32 *pmt;
    s8 tmp[10];
    s8 sign[3];
    s16 lim;
    s16 v;
    u8 t;
    if (buf == NULL) {
        return;
    }
    if (item->type == 4) {
        sprintf(buf, lbl_8043E358, item->meseta, TWindowSubStatusDisp::get_download_server());
        return;
    }
    pmt = (s32 *)lookup_item_pmt_record(arg0);
    if (pmt != NULL) {
        name = (char *)get_text_collection(*pmt);
    } else {
        name = (char *)get_text_collection(0x1F4);
    }
    if (((s32 (*)(void *))is_wrapped__9TItemDataFPv)(arg0) != 0) {
        sprintf(buf, &lbl_805DAB8C, get_text_collection(0x77));
        return;
    }
    t = item->type;
    if (t == 0) {
        if (is_custom_name_srank__9TItemDataFPv(arg0) != 0) {
            memset(tmp, 0, 10);
            ((TItemData *)arg0)->decode_packed_name_chars(tmp);
            if (tmp[0] - 0x41 == 1) {
                if (item->grind != 0) {
                    sprintf(buf, lbl_8043E360, &tmp[1], item->grind);
                } else {
                    sprintf(buf, &lbl_805DAB8C, &tmp[1]);
                }
            } else if (item->grind != 0) {
                sprintf(buf, lbl_8043E368, &tmp[1], name, item->grind);
            } else {
                sprintf(buf, lbl_8043E374, &tmp[1], name);
            }
            return;
        }
        slot = get_item_by_slot_flag__10TObjPlayerFUc(item->flags);
        if (is_rare_item__9TItemDataFPv(arg0) != 0) {
            if (check_item_flags() == 1) {
                if (item->grind != 0) {
                    sprintf(buf, lbl_8043E360, name, item->grind);
                } else {
                    sprintf(buf, &lbl_805DAB8C, name);
                }
            } else {
                sprintf(buf, &lbl_805DAB8C, get_text_collection(0x17E));
            }
            return;
        }
        if (*slot != 0) {
            if (item->grind != 0) {
                sprintf(buf, lbl_8043E368, slot, name, item->grind);
            } else {
                sprintf(buf, lbl_8043E374, slot, name);
            }
        } else if (item->grind != 0) {
            sprintf(buf, lbl_8043E360, name, item->grind);
        } else {
            sprintf(buf, &lbl_805DAB8C, name);
        }
    } else if (t == 3 && item->sub == 2) {
        u8 f = item->flags;
        if (f < 0x13) {
            switch (f) {
            case 0xE:
            case 0x11:
                if (current_language == LANGUAGE_JAPANESE) {
                    sprintf(buf, lbl_8043E37C, get_technique_name(f), name);
                } else {
                    sprintf(buf, lbl_8043E37C, name, get_technique_name(f));
                }
                break;
            default:
                if (current_language == LANGUAGE_JAPANESE) {
                    sprintf(buf, lbl_8043E384, get_technique_name(f), item->b2 + 1, name);
                } else {
                    sprintf(buf, lbl_8043E390, name, get_technique_name(f), item->b2 + 1);
                }
                break;
            }
        } else {
            sprintf(buf, name);
        }
    } else if (t == 1 && item->sub == 3) {
        memset(sign, 0, 3);
        pmt = (s32 *)lookup_item_pmt_record(arg0);
        if (pmt != NULL) {
            lim = *(s16 *)((u8 *)pmt + 0xC);
            v = get_field6_bswap__9TItemDataFPv(arg0);
            if (v < -lim) {
                sign[0] = '-';
                sign[1] = '-';
            } else if (v < 0) {
                sign[0] = '-';
            } else if (v == 0) {
                sign[0] = 0;
            } else if (v <= lim) {
                sign[0] = '+';
            } else if (lim < v) {
                sign[0] = '+';
                sign[1] = '+';
            }
        }
        sprintf(buf, lbl_8043E37C, name, sign);
    } else {
        sprintf(buf, name);
    }
}

void *lookup_item_pmt_record(u8 *item) {
    void *r = 0;
    switch (item[0]) {
    case 0:
        r = TObjPlayer::get_item_pmt_record(item[1], item[2]);
        break;
    case 1:
        switch (item[1]) {
        case 1:
        case 2:
            r = get_armor_pmt_record(item[1], item[2]);
            break;
        case 3:
            r = TObjPlayer::get_pmt_record_by_index(item[2]);
            break;
        }
        break;
    case 2:
        r = TObjPlayer::get_pmt_record(item[1]);
        break;
    case 3:
        if (item[1] == 2) {
            if (item[2] <= 0x1D) {
                r = TObjPlayer::get_pmt_record_by_type_id(item[1], item[4]);
            }
        } else {
            r = TObjPlayer::get_pmt_record_by_type_id(item[1], item[2]);
        }
        break;
    }
    return r;
}

int TItemData::calc_display_grade() {
    s16 temp_r3;
    u8 temp_b;
    int base_rarity;

    base_rarity = get_base_rarity();
    switch ((s32) (u8) *(u8 *)((s8 *)this + 0)) {
    case 0:
        if ((u8) base_rarity < 9U) {
            temp_b = *(u8 *)((s8 *)this + 4);
            if (!(temp_b & 0x80)) {
                base_rarity += get_unit_attribute_index__10TObjPlayerFUc(temp_b);
            }
        } else if (*(u8 *)((s8 *)this + 4) & 0x80) {
            base_rarity = 0;
        }
        break;
    case 1:
        if ((u8) *(u8 *)((s8 *)this + 1) == 3) {
            temp_r3 = get_field6_bswap__9TItemDataFPv(this);
            if (temp_r3 < 0) {
                base_rarity -= 1;
            } else if (temp_r3 > 0) {
                base_rarity += 1;
            }
        }
        break;
    }
    if ((u8) base_rarity > 0xCU) {
        base_rarity = 0xC;
    }
    return base_rarity;
}

s32 TItemData::get_base_rarity() {
    u8 *item = (u8 *)this;
    struct Parm_8010EBD8 *p;
    switch (item[0]) {
    case 0:
    case 1:
        p = (struct Parm_8010EBD8 *)lookup_item_pmt_record(item);
        if (p != NULL) {
            return get_item_star_count(p->name);
        }
        break;
    case 3:
        p = (struct Parm_8010EBD8 *)lookup_item_pmt_record(item);
        if (p != NULL && (p->flags & 0x80)) {
            return 0xC;
        }
        break;
    case 2:
        if (item[1] >= 0x28) {
            return 0xC;
        }
        break;
    }
    return 0;
}

void TItemData__clear_unidentified_flag(void *arg0) {
    if ((u8) *(u8 *)((s8 *)arg0 + 0) == 0) {
        *(u8 *)((s8 *)arg0 + 4) = (u8) (*(u8 *)((s8 *)arg0 + 4) & 0x7F);
    }
}

s32 TItemData::check_item_flags() {
    if (((u8) *(u8 *)((s8 *)this + 0) == 0) && (*(u8 *)((s8 *)this + 4) & 0x80)) {
        return is_wrapped__9TItemDataFPv() != 0 ? 1 : 0;
    }
    return 1;
}
#undef calc_clock_bonus__9TItemDataFPv
#undef add_armor_stat_contribution__9TItemDataFPviiPv
#undef is_wrapped__9TItemDataFPv
#undef add_shield_stat_contribution__9TItemDataFPviiPv
#undef apply_unit_stat_bonus__9TItemDataFPviiPvPvPv
#undef apply_bonuses
#undef is_custom_name_srank__9TItemDataFPv
#undef memset
