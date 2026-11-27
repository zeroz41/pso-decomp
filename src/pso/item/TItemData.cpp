#include "pso/item/MagStats.h"
#include "types.h"
#include <stdio.h>
#include <string.h>
#include "pso/player/PlayerAttackParams.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/system/byteswap.h"
#include "pso/object/warp/TObjWarpBossMulti.h"
#include "pso/object/base/ObjectSetData.h"
#include "pso/item/TItemData.h"
#include "pso/network/TLobby.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/ui/city/TShopEquipmentListWindow.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/Language.h"
#include "pso/map/FloorArea.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/quest/challenge/TChallenge4P.h"
#include "pso/item/MaterialStats.h"
#include "pso/ui/chat/SymbolChatCommand.h"
#include "pso/object/base/TObjBase.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/item/TItemMenuCtrl.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/item/armor/TItemProArmor.h"
#include "pso/item/armor/TItemProUnit.h"
#include "pso/item/TItemObject.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/item/item_create.h"
#include "pso/item/item_pmt.h"
#include "pso/network/client_id.h"
#include "pso/item/item_param.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TPlyDispData.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/system/MallocLoadFilePrc.h"
#include "pso/enemy/BattleParamTables.h"
#include "pso/system/TLanguage.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"

extern "C" {
u8 get_cast_technique_level(void *, int);
}


static const ItemIconIndexTable item_icon_index_by_category_table = {{1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 1, 1, 1, 1, 3, 2}};
static const f32 mag_stat_bonus_scale[4] = {2.0f, 0.5f, 1.0f, 2.0f};
extern "C" {
extern const u8 item_wrapped_flag = 0x40;
}
extern "C" {


void TItemData::set_present_color(s8 box_color) {
    switch (data1.data_u8[0]) {
    case 0:
        data1.data_u8[5] = (u8) (data1.data_u8[5] | (box_color & 0xF));
        return;
    case 1:
        data1.data_u8[4] = (u8) (data1.data_u8[4] | (box_color & 0xF));
        return;
    case 3:
        data1.data_u8[3] = (u8) (data1.data_u8[3] | (box_color & 0xF));
        return;
    case 2:
        return;
    }
}

s32 TItemData::get_type_nibble() {
    switch (data1.data_u8[0]) {
    case 0:
        return data1.data_u8[5] & 0xF;
    case 1:
        return data1.data_u8[4] & 0xF;
    case 3:
        return data1.data_u8[3] & 0xF;
    default:
    case 2:
        return 0;
    }
}

#pragma push
#pragma opt_common_subs off
void TItemData::apply_custom_shield_bonus(TObjPlayer *player, AttackParams *attack, ActorParamBlock *params,
                                          EquipStatBonus *stats, EquipHpTpBonus *hp_tp) {
    if (data1.data_u8[0] == 1 && data1.data_u8[1] == 2) {
        u8 id = data1.data_u8[2];
        if (id >= 0x53 && id <= 0x82) {
            s32 count = TObjPlayer::count_nearby_players_with_shield(player->get_entity_id(), data1.data_u8);
            u8 kind = (data1.data_u8[2] - 0x53) % 8;
            s16 bonus_per_player[8] = {0, 50, 25, 25, 100, 50, 50, 10};
            s16 amount = count * bonus_per_player[kind];
            switch (kind) {
            case 1:
                params->add_dfp(amount);
                break;
            case 2:
                params->add_evp(amount);
                break;
            case 3:
                stats->lck += amount;
                break;
            case 4:
                attack->add_ata(amount);
                break;
            case 5:
                attack->add_atp_min(amount);
                attack->add_atp_max(amount);
                break;
            case 6:
                stats->mst += amount;
                break;
            case 7:
                params->add_efr(amount);
                params->add_eic(amount);
                params->add_eth(amount);
                params->add_edk(amount);
                params->add_elt(amount);
                break;
            }
        }
    }
}
#pragma pop

void TItemData::apply_bonuses(TObjPlayer *player, AttackParams *attack, ActorParamBlock *params, EquipStatBonus *stats,
                              EquipHpTpBonus *hp_tp) {
    ItemStatBoost *boost;
    u8 type = data1.data_u8[0];
    switch (type) {
    case 0:
    case 1:
        boost = get_item_stat_boost_record(type, data1.data_u8[1], data1.data_u8[2]);
        if (boost != NULL && attack != NULL && params != NULL && stats != NULL)
        switch (boost->stat) {
        case 1:
            attack->add_atp_min(boost->amount);
            attack->add_atp_max(boost->amount);
            break;
        case 2:
            attack->add_ata((s16)(boost->amount * 10));
            break;
        case 3:
            params->add_evp(boost->amount);
            break;
        case 4:
            params->add_dfp(boost->amount);
            break;
        case 5:
            stats->mst += boost->amount;
            break;
        case 6:
            stats->hp += boost->amount;
            break;
        case 7:
            stats->lck += boost->amount;
            break;
        case 8:
            attack->add_atp_min(boost->amount);
            attack->add_atp_max(boost->amount);
            attack->add_ata((s16)(boost->amount * 10));
            params->add_evp(boost->amount);
            params->add_dfp(boost->amount);
            stats->mst += boost->amount;
            stats->lck += boost->amount;
            break;
        case 9:
            attack->sub_atp_min(boost->amount);
            attack->sub_atp_max(boost->amount);
            break;
        case 10:
            attack->sub_ata((s16)(boost->amount * 10));
            break;
        case 11:
            params->sub_evp(boost->amount);
            break;
        case 12:
            params->sub_dfp(boost->amount);
            break;
        case 13:
            stats->mst -= boost->amount;
            break;
        case 14:
            stats->hp -= boost->amount;
            break;
        case 15:
            stats->lck -= boost->amount;
            break;
        case 16:
            attack->sub_atp_min(boost->amount);
            attack->sub_atp_max(boost->amount);
            attack->sub_ata((s16)(boost->amount * 10));
            params->sub_evp(boost->amount);
            params->sub_dfp(boost->amount);
            stats->mst -= boost->amount;
            stats->lck -= boost->amount;
            break;
        }
        break;
    }
}

void TItemData::add_mag_stat_bonuses(TObjPlayer *player, AttackParams *attack, ActorParamBlock *params, EquipStatBonus *stats,
                                     EquipHpTpBonus *hp_tp) {
    MagStats mag;

    mag.init();
    deserialize_mag(&mag);
    if (stats != NULL && stats != NULL) {
        stats->atp += (s16)(mag_stat_bonus_scale[0] * (f32)mag.get_pow_level());
        stats->ata += (s16)(mag_stat_bonus_scale[1] * (f32)(mag.get_dex_level() * 10));
        stats->dfp += (s16)(mag_stat_bonus_scale[2] * (f32)mag.get_def_level());
        stats->mst += (s16)(mag_stat_bonus_scale[3] * (f32)mag.get_mind_level());
    }
}

void TItemData::apply_unit_stat_bonus(TObjPlayer *player, AttackParams *attack, ActorParamBlock *params, EquipStatBonus *stats,
                                      EquipHpTpBonus *hp_tp) {
    UnitPmtEntry *parm;
    s32 kind;
    s16 amount;
    parm = (UnitPmtEntry *)lookup_item_pmt_record(data1.data_u8);
    if (parm != NULL && stats != NULL && params != NULL) {
    kind = parm->stat;
    amount = parm->stat_amount + get_unit_modifier(data1.data_u8);
    switch (kind) {
    case 0:
        stats->atp += amount;
        break;
    case 1:
        stats->mst += amount;
        break;
    case 2:
        stats->ata += amount * 10;
        break;
    case 3:
        stats->evp += amount;
        break;
    case 4:
        if (hp_tp != NULL) {
            hp_tp->hp += amount;
        }
        break;
    case 5:
        if (hp_tp != NULL) {
            hp_tp->tp += amount;
        }
        break;
    case 6:
        stats->dfp += amount;
        break;
    case 7:
        stats->lck += amount;
        break;
    case 8:
        stats->atp += amount;
        stats->mst += amount;
        stats->ata += amount;
        stats->evp += amount;
        stats->dfp += amount;
        stats->lck += amount;
        break;
    case 9:
        params->add_efr(amount);
        break;
    case 10:
        params->add_eic(amount);
        break;
    case 11:
        params->add_eth(amount);
        break;
    case 12:
        params->add_elt(amount);
        break;
    case 13:
        params->add_edk(amount);
        break;
    case 14:
        params->add_efr(amount);
        params->add_eic(amount);
        params->add_eth(amount);
        params->add_elt(amount);
        params->add_edk(amount);
        break;
    }
    }
}

#pragma push
#pragma fp_contract on
void TItemData::add_shield_stat_contribution(TObjPlayer *player, AttackParams *attack, ActorParamBlock *params,
                                             EquipStatBonus *stats, EquipHpTpBonus *hp_tp) {
    s32 b06;
    ShieldPmtEntry *parm;
    f32 mult = get_set_bonus_multiplier(player);
    f32 add = calc_clock_bonus(player);
    parm = (ShieldPmtEntry *)lookup_item_pmt_record(data1.data_u8);
    if (parm != 0) {
        b06 = ((s32 (*)(void *))TItemData::get_dfp_bonus)(this);
        s32 b08 = ((s32 (*)(void *))TItemData::get_evp_bonus)(this);
        s32 v = (s32)(parm->evp * mult + add);
        if (params != 0) {
            params->add_evp((s16)(v + b08));
            params->add_dfp(parm->dfp + b06);
            params->add_efr(parm->efr);
            params->add_eic(parm->eic);
            params->add_eth(parm->eth);
            params->add_elt(parm->elt);
            params->add_edk(parm->edk);
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TItemData::add_armor_stat_contribution(TObjPlayer *player, AttackParams *attack, ActorParamBlock *params,
                                            EquipStatBonus *stats, EquipHpTpBonus *hp_tp) {
    s32 dfpBonus;
    ArmorPmtEntry *parm;
    f32 mult = get_set_bonus_multiplier(player);
    f32 add = calc_clock_bonus(player);
    parm = (ArmorPmtEntry *)lookup_item_pmt_record(data1.data_u8);
    if (parm != 0) {
        dfpBonus = ((s32 (*)(void *))TItemData::get_dfp_bonus)(this);
        s16 evpBonus = get_evp_bonus(data1.data_u8);
        s32 dfp = (s32)(parm->dfp * mult + add);
        if (params != 0) {
            params->add_evp((s16)(parm->evp + evpBonus));
            params->add_dfp(dfp + dfpBonus);
            params->add_efr(parm->efr);
            params->add_eic(parm->eic);
            params->add_eth(parm->eth);
            params->add_elt(parm->elt);
            params->add_edk(parm->edk);
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TItemData::add_weapon_stat_bonuses(TObjPlayer *player, AttackParams *attack, ActorParamBlock *params,
                                        EquipStatBonus *stats, EquipHpTpBonus *hp_tp) {
  s16 hi;
  s32 i;
  WeaponParams *parm;
  f32 mult = get_set_bonus_multiplier(player);
  f32 add = calc_clock_bonus(player);
  parm = (WeaponParams *)lookup_item_pmt_record(data1.data_u8);
  if (parm != 0)
  {
    if (attack != 0)
    {
      s16 grind = ((u8) (hi = data1.data_s8[3])) * 2;
      s16 lo = (mult * ((f32) (parm->atp_min + grind))) + add;
      hi = (mult * ((f32) (parm->atp_max + grind))) + add;
      attack->add_atp_min(lo);
      attack->add_atp_max(hi);
      attack->add_ata((s16) (parm->ata * 10));
      for (i = 0; i != 3; i++)
      {
        if (data1.data_u8[6 + (i * 2)] == 5)
        {
          attack->add_ata((s16) (data1.data_s8[7 + (i * 2)] * 10));
        }
      }
    }
    if (stats != 0)
    {
      stats->mst += parm->mst;
    }
  }
}
#pragma pop

void TItemData::set_wrapped() {
    switch (data1.data_u8[0]) {
    case 0:
    case 1:
        data1.data_u8[4] |= item_wrapped_flag;
        break;
    case 3:
        if (lookup_item_def() == 0) {
            data1.data_u8[3] |= item_wrapped_flag;
        }
        break;
    case 2:
        data2.data_u8[2] |= item_wrapped_flag;
        break;
    }
}


s32 TItemData::is_wrapped() {
    switch (data1.data_u8[0]) {
    case 0:
    case 1:
        return ((data1.data_u8[4] & 0x40) - 0x40) == 0;
    case 3:
        if (lookup_item_def() != 0) {
            return 0;
        }
        return ((data1.data_u8[3] & 0x40) - 0x40) == 0;
    case 2:
        return ((data2.data_u8[2] & 0x40) - 0x40) == 0;
    default:
        return 0;
    }
}

f32 TItemData::calc_clock_bonus(TObjPlayer *player) {
    f32 bonus = 0.0f;
    switch (data1.data_u8[1]) {
    case 0x94:
        bonus = (f32) (get_internet_beat() / 4);
        break;
    }
    return bonus;
}

void TItemData::set_packed_value(u16 kill_count) {
    this->data1.data_u8[10] = (u8) (kill_count >> 8U);
    this->data1.data_u8[11] = kill_count;
    this->data1.data_u8[10] = (u8) (this->data1.data_u8[10] | 0x80);
}

u16 TItemData::get_packed_value() {
    if (is_usable() != 0) {
        return (u16) (((this->data1.data_u8[10] << 8) & 0x7F00) | this->data1.data_u8[11]);
    }
    return 0U;
}

s32 get_item_icon_index(const u8 *q);

s32 TItemData::is_usable() {
    u8 kind;

    if (is_custom_name_srank() == 0) {
        kind = data1.data_u8[0];
        if ((kind != 2) && (kind != 4) && (data1.data_u8[10] & 0x80)) {
            return 1;
        }
    }
    return 0;
}

void TItemData::bswap() {
    bswap_32(&data2.data_u32);
    bswap_32(&id);
}

s32 TItemData::get_name_style() { return 0; }
void TItemData::convert_from_version(s32) {}

void TItemData::unpack_from_item(ObjectSetData *set) {
    MagStats mag;
    u8 item_kind;

    if (set != NULL) {
        init();
        this->data1.data_u8[0] = (u8) (((u32) set->set_params[0] >> 0x18U) & 0xF);
        this->data1.data_u8[1] = (u8) ((u32) set->set_params[0] >> 0x10U);
        item_kind = this->data1.data_u8[0];
        if ((item_kind == 0) || (item_kind == 1)) {
            this->data1.data_u8[1] = (u8) (this->data1.data_u8[1] + 1);
        }
        this->data1.data_u8[2] = (u8) ((u32) set->set_params[0] >> 8U);
        switch ((s32) (this->data1.data_u8[0])) {
        case 0:
            this->data1.data_u8[6] = (u8) ((u32) set->set_params[1] >> 8U);
            this->data1.data_u8[7] = (u8) set->set_params[1];
            this->data1.data_u8[8] = (u8) ((u32) set->set_params[2] >> 0x18U);
            this->data1.data_u8[9] = (u8) ((u32) set->set_params[2] >> 0x10U);
            this->data1.data_u8[10] = (u8) ((u32) set->set_params[2] >> 8U);
            this->data1.data_u8[11] = (u8) set->set_params[2];
            this->data1.data_u8[3] = (u8) ((u32) set->set_params[1] >> 0x18U);
            this->data1.data_u8[4] = (u8) set->set_params[0];
            return;
        case 3:
            if ((u8) this->data1.data_u8[1] == 2) {
                this->data1.data_u8[4] = (u8) set->set_params[0];
            }
            set_stack_count(1);
            return;
        case 4:
            this->data2.data_u32 = (s32) (((u32) set->set_params[1] >> 0x10U) * 0xA);
            return;
        case 1:
            this->data1.data_u8[5] = (u8) set->set_params[0];
            this->data1.data_u8[3] = (u8) ((u32) set->set_params[1] >> 0x18U);
            this->data1.data_u8[4] = (u8) ((u32) set->set_params[1] >> 0x10U);
            return;
        case 2:
            mag.init();
            serialize_mag(&mag);
            break;
        }
    }
}
s32 get_item_icon_index(const u8 *q) {
    u8 v;
    if (q[0] == 0) {
        ItemIconIndexTable t = item_icon_index_by_category_table;
        if ((v = q[1]) < 0xAA) {
            v = get_weapon_class_motion_type(v);
        }
        if (v < 0x13) {
            return t.w[v];
        }
    }
    return 0;
}

}
int TItemData::isValidGroundDrop() {
    u8 category;
    u8 group;
    if (find_item_by_id(id) == 0U) {
        category=data1.data_u8[0];
        switch ((s32)category) {
        case 3:
        case 0:
            if (lookup_item_pmt_record(data1.data_u8) == NULL) return 0;
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

void init_srank_weapon_item(TItemData *item_data, const char *name, u8 group) {
    s8 sp8[10];
    item_data->init();
    if ((name != NULL) && (((group >= 0x70U) && (group <= 0x88U)) || ((group >= 0xA5U) && (group <= 0xA9U)))) {
        item_data->data1.data_u8[0] = 0;
        item_data->data1.data_u8[1] = group;
        item_data->data1.data_u8[2] = 0;
        memset(sp8, 0, 0xA);
        sp8[0] = 0x41;
        strncpy((char *)&sp8[1], name, 8);
        item_data->pack_three_colors((u8 *)sp8);
    }
}

s8 TItemData::letter_index_to_char(s8 index) {
    return (index != 0) ? (s8)(index + 0x40) : (s8)0;
}

s8 TItemData::char_to_letter_index(s8 c) {
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
      u8 *q = &data1.data_u8[i * 2];
      u8 hi = q[6] & 0xFFFFFFFFFFFFFFFFu;
      u8 lo = q[7];
      h = lo | ((hi << 8) & 0x7F00);
      p[0] = letter_index_to_char((h >> 10) & 0x3F);
      p[1] = letter_index_to_char((h >> 5) & 0x1F);
      p[2] = letter_index_to_char(h & 0x1F);
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
      s8 a = char_to_letter_index((s8) in[(i * 3) + 0]);
      s8 b = char_to_letter_index((s8) in[(i * 3) + 1]);
      s8 c = char_to_letter_index((s8) in[(i * 3) + 2]);
      u32 v = c | (((a << 1) << 9) | (b << 5));
      u8 *o = &data1.data_u8[i * 2];
      a = ((u8) (v >> 8)) | 0x80;
      o[6] = a;
      o[7] = v;
    }
  }
}

s32 TItemData::is_custom_name_srank() {
    u8 kind;
    if (data1.data_u8[0] == 0) {
        kind = data1.data_u8[1];
        if ((kind >= 0x70U) && (kind <= 0x88U)) {
            return 1;
        }
        if ((kind >= 0xA5U) && (kind <= 0xA9U)) {
            return 1;
        }
    }
    return 0;
}

void TItemData::decode_from_network() {}
void TItemData::encode_for_network() {}
u8 TItemData::get_max_grind() {
    WeaponParams *weapon;

    weapon = (WeaponParams *)lookup_item_pmt_record(data1.data_u8);
    if (weapon != NULL) {
        return weapon->max_grind;
    }
    return 0U;
}
void TItemData::register_drop() { register_item_drop(this); }

s32 TItemData::get_max_stack_size() {
    if (lookup_item_def() != 0) {
        if (((u8) this->data1.data_u8[0] == 3) && ((u8) this->data1.data_u8[1] == 0x10)) {
            return 0x63;
        }
        return 0xA;
    }
    return 1;
}





extern "C" {

s32 TItemData::lookup_item_def() {
    return is_item_stackable(data1.data_u8[0], data1.data_u8[1]);
}
s16 TItemData::get_unit_modifier(void *data) {
    s16 value = *(s16 *)((u8 *)data + 6);
    bswap_16((u16 *)&value);
    return value;
}

void TItemData::set_unit_modifier(s16 modifier) {
    data1.data_u16[3] = modifier;
    bswap_16(&this->data1.data_u16[3]);
}

s16 TItemData::get_evp_bonus(void *data) {
    s16 value = *(s16 *)((u8 *)data + 8);
    bswap_16((u16 *)&value);
    return value;
}

void TItemData::set_evp_bonus(s16 evp_bonus) {
    data1.data_u16[4] = evp_bonus;
    bswap_16(&this->data1.data_u16[4]);
}

s16 TItemData::get_dfp_bonus(void *data) {
    s16 value = *(s16 *)((u8 *)data + 6);
    bswap_16((u16 *)&value);
    return value;
}

void TItemData::set_dfp_bonus(s16 dfp_bonus) {
    data1.data_u16[3] = dfp_bonus;
    bswap_16(&this->data1.data_u16[3]);
}

s16 TItemData::get_technique_level() {
    void *tech_params;

    if (((u8) this->data1.data_u8[0] == 3) && ((u8) this->data1.data_u8[1] == 2)) {
        tech_params = calc_technique_parameters(this->data1.data_u8[4], this->data1.data_u8[2], 0xFFFF);
        if (tech_params != NULL) {
            return *(s16 *)((s8 *)tech_params + 0x14);
        }
    }
    return 0;
}

s32 TItemData::has_bonus_stats() {
    s32 i;
    switch (data1.data_u8[0]) {
    case 0:
        for (i = 0; i < 3; i++) {
            if (data1.data_u8_pair[3 + i][0] != 0) {
                return 1;
            }
        }
        break;
    case 1:
        switch (data1.data_u8[1]) {
        case 1:
            if (data1.data_u8[5] != 0) {
                return 1;
            }
        case 2:
            if (get_dfp_bonus(this) > 0 || get_evp_bonus(this) > 0) {
                return 1;
            }
            break;
        case 3:
            if (get_unit_modifier(this) > 0) {
                return 1;
            }
            break;
        }
        break;
    case 2:
        switch (data1.data_u8[1]) {
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

s32 TItemData::calc_action_flags(s32 mask, TObjPlayer *player) {
  s32 result;
  u16 id;
  s32 hit;
  ItemToolPmt *tool;
  s32 flags;
  s32 lvl;
  TItemData weapon_data;
  result = 0;
  if (player == 0)
  {
    player = get_player_by_client_id(local_client_id);
    id = (u16) local_client_id;
  }
  else
  {
    id = player->get_entity_id();
  }
  if (player == 0)
  {
    return 0;
  }
  if (TItemData::is_item_usable(player, this) != 0)
  {
    result |= 2;
  }
  if (is_wrapped() != 0)
  {
    return result & mask;
  }
  if (data1.data_u8[0] != 3)
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
    tool = (ItemToolPmt *) lookup_item_pmt_record(data1.data_u8);
    perm = check_class_equip_permission(player, 0xD7);
    if (tool != 0)
    {
      flags = tool->flags;
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
      if ((!(flags & 0x10)) && (is_current_area_item_enabled() == 0))
      {
        result |= 1;
      }
      if ((!(flags & 0x20)) && (is_boss_area() != 0))
      {
        result |= 1;
      }
      if ((!(flags & 0x40)) && ((is_challenge_mode() != 0) || (is_challenge_mode_active() != 0)))
      {
        result |= 1;
      }
    }
    switch (data1.data_u8[1])
    {
      case 6:
        switch (data1.data_u8[2])
      {
        case 0:
          if (player->get_status_effect_type(0) != 0xF)
        {
          result |= 1;
        }
          break;
        case 1:
          if (player->get_status_effect_type(0) != 0x10)
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
        TechniqueParams *tech;
        u8 cur;
        u8 lim;
        lvl = data1.data_u8[2];
        tech = calc_technique_parameters(data1.data_u8[4], lvl, 0xFFFF);
        if (tech != 0)
        {
          if (player->get_stats()->stats.mst < tech->mental)
          {
            result |= 0x10001;
          }
          cur = get_cast_technique_level(&player->technique_state, (s16) data1.data_u8[4]);
          if ((TObjPlayer::is_invalid_slot(cur) == 0) && (data1.data_u8[2] <= cur))
          {
            result |= 0x10001;
          }
          // player->char_class (s8) schedules the this[4] load after it; the original reads the byte first.
          lim = get_technique_learn_limit(((u8 *)player)[0x88D], (short) data1.data_u8[4]);
          if ((lim == 0xFF) || (lim < lvl))
          {
            result |= 0x10001;
          }
        }
        break;
      }
      case 10:
      {
        TItem *weapon = TObjPlayer::get_equipped_weapon(player);
        if (weapon != 0)
        {
          WeaponParams *params;
          weapon->copy_to_item_data(&weapon_data);
          params = (WeaponParams *) lookup_item_pmt_record(weapon_data.data1.data_u8);
          if ((params != 0) && (params->max_grind <= weapon_data.data1.data_u8[3]))
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
        player_stats *stats = player->get_stats();
        if (stats != 0)
        {
          hit = 0;
          switch (data1.data_u8[2])
          {
            case 0:
              if ((player->get_class_stat_entry()->stats.atp <= stats->stats.atp) || (player->can_use_more_materials_for_class() != 0))
            {
              hit = 1;
            }
              break;
            case 1:
              if ((player->get_class_stat_entry()->stats.mst <= stats->stats.mst) || (player->can_use_more_materials_for_class() != 0))
            {
              hit = 1;
            }
              break;
            case 2:
              if ((player->get_class_stat_entry()->stats.evp <= stats->stats.evp) || (player->can_use_more_materials_for_class() != 0))
            {
              hit = 1;
            }
              break;
            case 3:
              if (calc_base_hp_bonus(id) >= 0xFA)
            {
              hit = 1;
            }
              break;
            case 4:
              if (calc_base_tp_bonus(id) >= 0xFA)
            {
              hit = 1;
            }
              break;
            case 5:
              if ((player->get_class_stat_entry()->stats.dfp <= stats->stats.dfp) || (player->can_use_more_materials_for_class() != 0))
            {
              hit = 1;
            }
              break;
            case 6:
              if ((player->get_class_stat_entry()->stats.lck <= stats->stats.lck) || (player->can_use_more_materials_for_class() != 0))
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
        if (TItemMag::check_evolution_cond(player, (s32)(data1.data_u8[2])) == 0)
      {
        result |= 1;
      }
        break;
      case 15:
      {
        TItem *armor = player->get_equipped_armor();
        if (armor != 0)
        {
          if (armor->get_slot_count() >= 4)
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
  if (((is_quest_active() != 0) && (data1.data_u8[0] == 3)) && (TItemMenuCtrl::query_flag(6) == 1))
  {
    result |= 0x10001;
  }
  return result & mask;
}

void TItemData::serialize_mag(const MagStats *mag) {
    TItemData copy;
    copy.data1.data_u8[0] = data1.data_u8[0];
    copy.data1.data_u8[1] = data1.data_u8[1];
    copy.data1.data_u8[2] = mag->get_level();
    copy.data1.data_u8[3] = mag->photon_blasts;
    copy.data1.data_s16[2] = mag->def & 0x7FFE;
    copy.data1.data_s16[3] = mag->pow & 0x7FFE;
    copy.data1.data_s16[4] = mag->dex & 0x7FFE;
    copy.data1.data_s16[5] = mag->mind & 0x7FFE;
    copy.id = id;
    copy.data2.data_u8[0] = mag->synchro;
    copy.data2.data_u8[1] = mag->iq;
    copy.data2.data_u8[2] = mag->photon_blast_flags;
    copy.data2.data_u8[3] = mag->color;
    copy.bswap_fields();
    copy_from(&copy);
}

void TItemData::bswap_fields() { bswap_16(&this->data1.data_u16[2]); bswap_16(&this->data1.data_u16[3]); bswap_16(&this->data1.data_u16[4]); bswap_16(&this->data1.data_u16[5]); }

void TItemData::deserialize_mag(MagStats *dst) {
    if (dst != 0) {
        TItemData tmp = *this;
        tmp.bswap_fields();
        dst->photon_blasts = tmp.data1.data_u8[3];
        dst->def = tmp.data1.data_u16[2] & 0x7ffe;
        dst->pow = tmp.data1.data_u16[3] & 0x7ffe;
        dst->dex = tmp.data1.data_u16[4] & 0x7ffe;
        dst->mind = tmp.data1.data_u16[5] & 0x7ffe;
        dst->synchro = tmp.data2.data_u8[0];
        dst->iq = tmp.data2.data_u8[1];
        dst->photon_blast_flags = tmp.data2.data_u8[2];
        dst->color = tmp.data2.data_u8[3];
    }
}

f32 TItemData::get_shield_set_multiplier(TObjPlayer *player) {
  TItem *item;
  f32 multiplier;
  TItem *partner;
  TItem *weapon_2;
  TItem *weapon_3;
  TItem *partner_2;
  TItem *partner_3;
  u8 set_id;
  TItem *weapon;
  set_id = this->data1.data_u8[2];
  multiplier = 1.0f;
  switch ((s32) set_id)
  {
    case 26:
      weapon = TObjPlayer::get_equipped_weapon(player);
      if ((weapon != 0) && (weapon->get_item_group() == 0x1A))
    {
      multiplier = 2.0f;
    }
      break;
    case 38:
      item = TObjPlayer::get_equipped_weapon(player);
      partner = player->get_equipped_armor();
      if (((((item != NULL) && (partner != NULL)) && (item->get_item_group() == 1)) && (item->get_item_index() == 5)) && (partner->get_item_index() == 0x28))
    {
      multiplier = 1.5f;
    }
      break;
    case 36:
      weapon_2 = TObjPlayer::get_equipped_weapon(player);
      partner_2 = player->get_equipped_armor();
      if (((((weapon_2 != NULL) && (partner_2 != NULL)) && (weapon_2->get_item_group() == 2)) && (weapon_2->get_item_index() == 5)) && (partner_2->get_item_index() == 0x26))
    {
      multiplier = 1.5f;
    }
      break;
    case 37:
      weapon_3 = TObjPlayer::get_equipped_weapon(player);
      partner_3 = player->get_equipped_armor();
      if (((((weapon_3 != NULL) && (partner_3 != NULL)) && (weapon_3->get_item_group() == 6)) && (weapon_3->get_item_index() == 6)) && (partner_3->get_item_index() == 0x27))
    {
      multiplier = 1.5f;
    }
      break;
  }
  return multiplier;
}

f32 TItemData::get_armor_set_multiplier(TObjPlayer *player) {
    f32 v;
    TItem *b1;
    TItem *a1;
    TItem *a2;
    TItem *b2;
    TItem *a3;
    TItem *b3;
    s32 i;
    s32 found;
    s32 hit;
    s32 j;
    s32 hit2;
    s32 k;
    TObjPlayer *other;
    TItem *armor;
    u8 c;
    v = 1.0f;
    switch (data1.data_u8[2]) {
    case 24:
        found = 0;
        for (i = 0; i != 12 && found != 1; i++) {
            other = get_player_by_client_id(i);
            if (other != NULL) {
                armor = other->get_equipped_armor();
                if (armor != NULL) {
                    c = armor->get_item_index();
                    if (c == 0x19 || c == 0x1A) {
                        v = 1.2f;
                        found = 1;
                    }
                }
            }
        }
        break;
    case 25:
        hit = 0;
        for (j = 0; j != 12 && hit != 1; j++) {
            other = get_player_by_client_id(j);
            if (other != NULL) {
                armor = other->get_equipped_armor();
                if (armor != NULL) {
                    c = armor->get_item_index();
                    if (c == 0x1A || c == 0x18) {
                        v = 1.2f;
                        hit = 1;
                    }
                }
            }
        }
        break;
    case 26:
        hit2 = 0;
        for (k = 0; k != 12 && hit2 != 1; k++) {
            other = get_player_by_client_id(k);
            if (other != NULL) {
                armor = other->get_equipped_armor();
                if (armor != NULL) {
                    c = armor->get_item_index();
                    if (c == 0x19 || c == 0x18) {
                        v = 1.2f;
                        hit2 = 1;
                    }
                }
            }
        }
        break;
    case 40:
        a1 = TObjPlayer::get_equipped_weapon(player);
        b1 = player->get_equipped_shield();
        if (a1 != NULL && b1 != NULL && a1->get_item_group() == 1 && a1->get_item_index() == 5 && b1->get_item_index() == 0x26) {
            v = 1.5f;
        }
        break;
    case 38:
        a2 = TObjPlayer::get_equipped_weapon(player);
        b2 = player->get_equipped_shield();
        if (a2 != NULL && b2 != NULL && a2->get_item_group() == 2 && a2->get_item_index() == 5 && b2->get_item_index() == 0x24) {
            v = 1.5f;
        }
        break;
    case 39:
        a3 = TObjPlayer::get_equipped_weapon(player);
        b3 = player->get_equipped_shield();
        if (a3 != NULL && b3 != NULL && a3->get_item_group() == 6 && a3->get_item_index() == 6 && b3->get_item_index() == 0x25) {
            v = 1.5f;
        }
        break;
    case 45:
        if (is_opposite_sex_player_near(player->get_entity_id()) != 0) {
            v = 1.5f;
        }
        break;
    }
    return v;
}

f32 TItemData::get_weapon_set_multiplier(TObjPlayer *player) {
  f32 multiplier;
  TItem *first;
  TItem *second;
  TItem *first_2;
  TItem *first_3;
  TItem *second_2;
  TItem *second_3;
  u8 weapon_type;
  TItem *item;
  weapon_type = this->data1.data_u8[1];
  multiplier = 1.0f;
  switch ((s32) weapon_type)
  {
    case 1:
      if (((u8) (this->data1.data_u8[2])) == 5)
    {
      first = player->get_equipped_shield();
      second = player->get_equipped_armor();
      if (((first != NULL) && (second != NULL)) && (first->get_item_index() == 0x26) && (second->get_item_index() == 0x28))
      {
        multiplier = 1.5f;
      }
    }
      break;
    case 2:
      if (((u8) (this->data1.data_u8[2])) == 5)
    {
      first_2 = player->get_equipped_shield();
      second_2 = player->get_equipped_armor();
      if (((first_2 != NULL) && (second_2 != NULL)) && (first_2->get_item_index() == 0x24) && (second_2->get_item_index() == 0x26))
      {
        multiplier = 1.5f;
      }
    }
      break;
    case 6:
      if (((u8) (this->data1.data_u8[2])) == 6)
    {
      first_3 = player->get_equipped_shield();
      second_3 = player->get_equipped_armor();
      if (((first_3 != NULL) && (second_3 != NULL)) && (first_3->get_item_index() == 0x25) && (second_3->get_item_index() == 0x27))
      {
        multiplier = 1.5f;
      }
    }
      break;
    case 26:
      item = player->get_equipped_shield();
      if ((item != 0) && (item->get_item_index() == 0x1A))
    {
      multiplier = 2.0f;
    }
      break;
  }
  return multiplier;
}

f32 TItemData::get_set_bonus_multiplier(TObjPlayer *player) {
    switch (data1.data_u8[0]) {
    case 0:
        return get_weapon_set_multiplier(player);
    case 1:
        switch (data1.data_u8[1]) {
        case 1:
            return get_armor_set_multiplier(player);
        case 2:
            return get_shield_set_multiplier(player);
        }
        break;
    }
    return 1.0f;
}

void TItemData::apply_equip_effects(TObjPlayer *owner, AttackParams *attack, ActorParamBlock *params, EquipStatBonus *stats,
                                    EquipHpTpBonus *hp_tp) {

    if ((owner != 0) || (owner = get_player_by_client_id(local_client_id), ((owner == 0) == 0))) {
        get_set_bonus_multiplier(owner);
        calc_clock_bonus(owner);
        switch ((s32) (this->data1.data_u8[0])) {
        case 0:
            add_weapon_stat_bonuses(owner, attack, params, stats, hp_tp);
            break;
        case 1:
            switch ((s32) (this->data1.data_u8[1])) {
            case 1:
                add_armor_stat_contribution(owner, attack, params, stats, hp_tp);
                break;
            case 2:
                add_shield_stat_contribution(owner, attack, params, stats, hp_tp);
                break;
            case 3:
                apply_unit_stat_bonus(owner, attack, params, stats, hp_tp);
                break;
            }
            break;
        case 2:
            add_mag_stat_bonuses(owner, attack, params, stats, hp_tp);
            break;
        }
        apply_bonuses(owner, attack, params, stats, hp_tp);
        apply_custom_shield_bonus(owner, attack, params, stats, hp_tp);
    }
}

s32 TItemData::is_rare_item() {
    return (u8) get_base_rarity() >= 9 ? 1 : 0;
}

#pragma push
#pragma fp_contract on
// A shop's price for the item, before the shop's own markup.
s32 TItemData::calc_price() {
  WeaponParams *weapon;
  ArmorPmtEntry *armor;
  s32 price;
  f32 coef;
  f32 power;
  f32 atp;
  f32 stars;
  s32 bonus;
  s32 i;
  price = 0;
  switch (data1.data_u8[0])
  {
    case 0:
      if (data1.data_u8[4] & 0x80)
    {
      price = 8;
    }
    else
      if (is_rare_item() != 0)
    {
      price = 0x50;
    }
    else
    {
      weapon = (WeaponParams *) lookup_item_pmt_record(data1.data_u8);
      coef = get_item_price_coefficient(data1.data_u8[0], (unsigned long) data1.data_u8[1]);
      if ((0.0f != coef) && (weapon != 0))
      {
        atp = ((f32) weapon->atp_max) + ((f32) data1.data_u8[3]);
        power = (atp * atp) / coef;
        bonus = 0;
        // The three percent attributes: (kind, value) pairs from byte 6.
        for (i = 0; i < 3; i++)
        {
          if ((data1.data_u8_pair[i + 3][0] != 0) && (data1.data_u8_pair[i + 3][0] <= 5))
          {
            bonus = (data1.data_s8[i * 2 + 7] + bonus) + 100;
          }
          else
          {
            bonus += 100;
          }
        }

        stars = (f32) (u8)get_weapon_special_star_count(data1.data_u8[4]);
        price = (s32) (((power * ((f32) bonus)) / 100.0f) + (1000.0f * (stars * stars)));
      }
    }
      break;

    case 1:
      if (is_rare_item() != 0)
    {
      price = 0x50;
    }
    else
      if (data1.data_u8[1] != 3)
    {
      coef = get_item_price_coefficient(data1.data_u8[0], data1.data_u8[1]);
      // A shield's record has the same DFP, EVP and level fields.
      armor = (ArmorPmtEntry *) lookup_item_pmt_record(data1.data_u8);
      if ((0.0f != coef) && (armor != 0))
      {
        s32 a = TItemData::get_dfp_bonus(this);
        atp = (f32) (((armor->dfp + armor->evp) + a) + TItemData::get_evp_bonus(this));
        {
          s32 dv = (s32) ((atp * atp) / coef);
          f32 sl = 70.0f * ((f32)(data1.data_u8[5] + 1));
          f32 lv = (f32)(armor->required_level + 1);
          price = (s32) ((sl * lv) + ((f32) dv));
        }
      }
    }
    else
    {
      coef = get_item_price_coefficient(data1.data_u8[0], data1.data_u8[1]);
      stars = (f32) ((u8) this->calc_display_grade());
      price = (s32) (stars * coef);
    }
      break;

    case 4:
      price = data2.meseta;
      break;

    case 3:
    {
      ItemToolPmt *tool = (ItemToolPmt *) lookup_item_pmt_record(data1.data_u8);
      if (tool != 0)
    {
      if (data1.data_u8[1] != 2)
      {
        price = tool->cost;
      }
      else
      {
        price = tool->cost * ((u8)(data1.data_u8[2] + 1));
      }
    }
      break;
    }

    case 2:
      price = (s32) (((f32)(data1.data_u8[2] + 1)) * get_item_price_coefficient(data1.data_u8[0], data1.data_u8[1]));
      break;

  }

  if (price < 0)
  {
    price = 0;
  }
  return price;
}
#pragma pop

void TItemData::init() {
    s32 i;
    data1.data_u8[0] = 0;
    data1.data_u8[1] = 0;
    data1.data_u8[2] = 0;
    data1.data_u8[3] = 0;
    data1.data_u8[4] = 0;
    data1.data_u8[5] = 0;
    data2.data_u32 = 0;
    for (i = 0; i < 3; i++) {
        data1.data_u8_pair[3 + i][0] = 0;
        data1.data_u8_pair[3 + i][1] = 0;
    }
    id = -1;
}

saddr TItemData::calc_buy_price() {
    u8 special;

    if ((u8) this->data1.data_u8[0] == 0) {
        special = this->data1.data_u8[4];
        if ((special != 0) && (special < 0x29U) && (is_rare_item() == 0)) {
            if (check_item_flags() == 1) {
                return get_item_description_text(this->data1.data_u8[4] + 0x1CB);
            }
            return get_item_description_text(0x1F4);
        }
    }
    return (saddr)empty_string;
}
}

const char *format_item_description(TItemData *item) {
    char *format;
    UnitPmtEntry *p;
    char *out;
    s32 name;
    p = (UnitPmtEntry *)lookup_item_pmt_record(item->data1.data_u8);
    out = (char *)get_item_chunk_buffer(0);
    if (p != NULL && out != NULL) {
        format = NULL;
        if (item->is_wrapped() != 0) {
            format = (char *)get_item_description_text(0x77);
        } else {
            name = p->id;
            if (name == 0x1F4) {
                return empty_string;
            }
            if (item->data1.data_u8[0] == 0) {
                if (item->is_rare_item() != 0 && item->check_item_flags() == 0) {
                    format = (char *)get_item_description_text(0x17E);
                } else {
                    format = (char *)get_item_description_text(name);
                }
            } else if (item->data1.data_u8[0] == 1 && item->data1.data_u8[1] == 3) {
                if (name < 0x2E2) {
                    if (p != NULL && out != NULL && p->stat != 0x1C) {
                        sprintf(out, (char *)get_item_description_text(name), p->stat_amount + TItemData::get_unit_modifier(item));
                        return out;
                    }
                } else {
                    format = (char *)get_item_description_text(name);
                }
            } else {
                format = (char *)get_item_description_text(name);
            }
        }
        if (format != NULL) {
            sprintf(out, format, item->get_packed_value());
        }
    return out;
    }
    return empty_string;
}

void TItemData::format_item_name(char *buf) {
    s8 *slot;
    const char *name;
    s32 *pmt;
    s8 tmp[10];
    s8 sign[3];
    s16 lim;
    s16 v;
    u8 t;
    if (buf == NULL) {
        return;
    }
    if (data1.data_u8[0] == 4) {
        sprintf(buf, "%d%s", data2.meseta, TWindowSubStatusDisp::get_meseta_unit());
        return;
    }
    pmt = (s32 *)lookup_item_pmt_record(data1.data_u8);
    if (pmt != NULL) {
        name = get_text_collection(*pmt);
    } else {
        name = get_text_collection(0x1F4);
    }
    if (is_wrapped() != 0) {
        sprintf(buf, "%s", get_text_collection(0x77));
        return;
    }
    t = data1.data_u8[0];
    if (t == 0) {
        if (is_custom_name_srank() != 0) {
            memset(tmp, 0, 10);
            decode_packed_name_chars(tmp);
            if (tmp[0] - 0x41 == 1) {
                if (data1.data_u8[3] != 0) {
                    sprintf(buf, "%s +%d", &tmp[1], data1.data_u8[3]);
                } else {
                    sprintf(buf, "%s", &tmp[1]);
                }
            } else if (data1.data_u8[3] != 0) {
                sprintf(buf, "%s %s +%d", &tmp[1], name, data1.data_u8[3]);
            } else {
                sprintf(buf, "%s %s", &tmp[1], name);
            }
            return;
        }
        slot = (s8 *)TObjPlayer::get_item_by_slot_flag(data1.data_u8[4]);
        if (is_rare_item() != 0) {
            if (check_item_flags() == 1) {
                if (data1.data_u8[3] != 0) {
                    sprintf(buf, "%s +%d", name, data1.data_u8[3]);
                } else {
                    sprintf(buf, "%s", name);
                }
            } else {
                sprintf(buf, "%s", get_text_collection(0x17E));
            }
            return;
        }
        if (*slot != 0) {
            if (data1.data_u8[3] != 0) {
                sprintf(buf, "%s %s +%d", slot, name, data1.data_u8[3]);
            } else {
                sprintf(buf, "%s %s", slot, name);
            }
        } else if (data1.data_u8[3] != 0) {
            sprintf(buf, "%s +%d", name, data1.data_u8[3]);
        } else {
            sprintf(buf, "%s", name);
        }
    } else if (t == 3 && data1.data_u8[1] == 2) {
        u8 f = data1.data_u8[4];
        if (f < 0x13) {
            switch (f) {
            case 0xE:
            case 0x11:
                if (current_language == LANGUAGE_JAPANESE) {
                    sprintf(buf, "%s%s", get_technique_name(f), name);
                } else {
                    sprintf(buf, "%s%s", name, get_technique_name(f));
                }
                break;
            default:
                if (current_language == LANGUAGE_JAPANESE) {
                    sprintf(buf, "%sLV%d%s", get_technique_name(f), data1.data_u8[2] + 1, name);
                } else {
                    sprintf(buf, "%s%s Lv.%d", name, get_technique_name(f), data1.data_u8[2] + 1);
                }
                break;
            }
        } else {
            sprintf(buf, name);
        }
    } else if (t == 1 && data1.data_u8[1] == 3) {
        memset(sign, 0, 3);
        pmt = (s32 *)lookup_item_pmt_record(data1.data_u8);
        if (pmt != NULL) {
            lim = *(s16 *)((u8 *)pmt + 0xC);
            v = get_unit_modifier(this);
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
        sprintf(buf, "%s%s", name, sign);
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
    s16 rarity_modifier;
    u8 temp_b;
    int base_rarity;

    base_rarity = get_base_rarity();
    switch ((s32) (u8) this->data1.data_u8[0]) {
    case 0:
        if ((u8) base_rarity < 9U) {
            temp_b = this->data1.data_u8[4];
            if (!(temp_b & 0x80)) {
                base_rarity += get_weapon_special_star_count(temp_b);
            }
        } else if (this->data1.data_u8[4] & 0x80) {
            base_rarity = 0;
        }
        break;
    case 1:
        if ((u8) this->data1.data_u8[1] == 3) {
            rarity_modifier = TItemData::get_unit_modifier(this);
            if (rarity_modifier < 0) {
                base_rarity -= 1;
            } else if (rarity_modifier > 0) {
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
    ItemToolPmt *p;
    switch (item[0]) {
    case 0:
    case 1:
        p = (ItemToolPmt *)lookup_item_pmt_record(item);
        if (p != NULL) {
            return get_item_star_count(p->id);
        }
        break;
    case 3:
        p = (ItemToolPmt *)lookup_item_pmt_record(item);
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

void TItemData::clear_unidentified_flag() {
    if (this->data1.data_u8[0] == 0) {
        this->data1.data_u8[4] &= 0x7F;
    }
}

s32 TItemData::check_item_flags() {
    if (((u8) this->data1.data_u8[0] == 0) && (this->data1.data_u8[4] & 0x80)) {
        return is_wrapped() != 0 ? 1 : 0;
    }
    return 1;
}

void TItemData::init_meseta(s32 amount) {
    init();
    data1.data_u8[0] = 4;
    data2.data_u32 = amount;
}

s32 TItemData::get_stack_count() {
    u8 count;

    if (lookup_item_def() != 0) {
        count = data1.data_u8[5];
        if (count != 0) {
            return count;
        }
    }
    return 1;
}

void TItemData::set_stack_count(u8 count) {
    if (lookup_item_def() != 0) {
        data1.data_u8[5] = count;
        return;
    }
    if (data1.data_u8[0] == 3) {
        data1.data_u8[5] = 0;
    }
}

void ActorParamBlock::add_elt(s32 amount) {
    values[4] = values[4] + amount;
}

void ActorParamBlock::add_edk(s32 amount) {
    values[5] = values[5] + amount;
}

void ActorParamBlock::add_eth(s32 amount) {
    values[3] = values[3] + amount;
}

void ActorParamBlock::add_eic(s32 amount) {
    values[2] = values[2] + amount;
}

void ActorParamBlock::add_efr(s32 amount) {
    values[1] = values[1] + amount;
}

void ActorParamBlock::add_evp(s32 amount) {
    values[0] += amount;
}

void ActorParamBlock::add_dfp(s16 amount) {
    value_1c = value_1c + amount;
}

void ActorParamBlock::sub_dfp(s16 amount) {
    value_1c = value_1c - amount;
}
void ActorParamBlock::sub_evp(s32 amount) {
    values[0] -= amount;
}

s16 MagStats::get_mind_level() const {
    return mind / 100;
}

s16 MagStats::get_def_level() const {
    return def / 100;
}

s16 MagStats::get_dex_level() const {
    return dex / 100;
}

s16 MagStats::get_pow_level() const {
    return pow / 100;
}

s32 TObjPlayer::can_use_more_materials_for_class() {
    return this->materials.can_use_more_materials(get_class_index());
}
saddr get_item_description_text(s32 name) {
    return (saddr)text_language_group_table[1][name];
}
const char *get_text_collection(s32 index) {
    return text_language_group_table[0][index];
}

const char *TWindowSubStatusDisp::get_meseta_unit() { return get_message_text(0); }
