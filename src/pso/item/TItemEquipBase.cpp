#include "types.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemData.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/item/TItemLoad_80110010.h"
#include "pso/item/TItemTimerEvent.h"
#include "pso/menu/TAdRicoRing_8001BEE8.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TQuestListVM.h"
#include "pso/misc/TechniqueBoost.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/system/FlagWord.h"
#include "pso/map/CurrentArea.h"
#include "pso/system/vector.h"
#include "pso/unk/text_80087278.h"
#include "pso/TItemLoad.h"
#include "pso/TItemLockCountCtrl.h"

// A loaded item model as TItemLoad::find_node_by_id hands it out.
struct ItemModelResource {
    NJS_OBJECT *model;
    NJS_OBJECT *second_model;
    void *data[2];
    s32 texture_id;
    void *motion;
};

const char *item_equip_base_class_name = "TItemEquipBase";

// The owner joint each attach slot hangs the equipped model from.
extern s16 item_equip_attach_equip_flag_table[];

extern "C" {
// The attack parameter getters (TObjPlayer_80011014.cpp), seen here as
// returning int: the stat helpers take the values without re-extending them.
s32 get_attack_params_atp_min(AttackParams *params);
s32 get_attack_params_atp_max(AttackParams *params);
s32 TObjPlayer__sub_800194E8(AttackParams *params);
void *resolve_hittable_target(u16 actor_id, s32 collider);
s32 add_actor_hp_bonus(void *actor, s32 amount);
s32 add_actor_tp_bonus(void *actor, s32 amount);
s16 add_stat__10TObjPlayerFl(void *player, s32 amount);
s16 add_mst__10TObjPlayerFl(void *player, s32 amount);
s16 add_evp__10TObjPlayerFl(void *player, s32 amount);
s16 add_hp__10TObjPlayerFl(void *player, s32 amount);
s16 add_dfp__10TObjPlayerFl(void *player, s32 amount);
s16 add_ata__10TObjPlayerFl(void *player, s32 amount);
s16 add_lck__10TObjPlayerFl(void *player, s32 amount);
void *memset(void *dst, int value, unsigned long size);
}

void play_target_impact_effect(s32 unused0, s32 unused1, u16 actor_id, s16 collider) {
    Vec pos;
    TUnk_804806E8 *target = (TUnk_804806E8 *)resolve_hittable_target(actor_id, collider);
    if (target != NULL) {
        VecCopy(&pos, &target->position);
        pos.y = target->m_300;
    }
    spawn_particle_effect(&pos, 0x45);
}

EquipHpTpBonus *TItemEquipBase::get_stat_bonus_ptr() { return &hp_tp_bonus; }

s8 TItemEquipBase::get_attach_joint() { return attach_joint; }

s8 TItemEquipBase::get_attach_slot() { return attach_slot; }

void TItemEquipBase::on_model_loaded() {}

void TItemEquipBase::bind_loaded_resources() {
    ItemModelResource *resource;
    if (item_model == NULL) {
        s16 id = model_resource_id;
        if ((id != -1) && (TItemLoad::has_resource_id(id) == 1)) {
            resource = (ItemModelResource *)TItemLoad::find_node_by_id(model_resource_id);
            if (resource != NULL) {
                item_model = resource->model;
                second_model = resource->second_model;
                texture_id = resource->texture_id;
                model_motion = resource->motion;
                model_data[0] = resource->data[0];
                model_data[1] = resource->data[1];
                on_model_loaded();
            }
        }
    }
}

void TItemEquipBase::clear_technique_boosts() {
    s32 first = (get_item_type() != 0) ? 3 : 0;
    TechniqueBoost boost;
    s32 i = 0;
    do {
        set_technique_boost(&boost, get_owner_client(), first + i);
        i++;
    } while (i != 3);
}

void TItemEquipBase::register_technique_boosts(const TechniqueBoostParam *params) {
    s32 first;
    const TechniqueBoostParam *param;
    s32 i;

    if (params == NULL) {
        return;
    }
    first = (get_item_type() != 0) ? 3 : 0;
    param = params;
    i = 0;
    do {
        TechniqueBoost boost;
        boost.technique = param->technique;
        boost.flags = param->flags;
        boost.amount = param->amount;
        set_technique_boost(&boost, get_owner_client(), first + i);
        i++;
        param++;
    } while (i != 3);
}

void TItemEquipBase::remove_owner_bonuses() {}
void TItemEquipBase::apply_owner_bonuses() {}
void TItemEquipBase::on_unequip() {}
void TItemEquipBase::on_equip() {}

void TItemEquipBase::apply_equip_effects() {
    if (start_effect(0x2, 0x4)) {
        TItemTimerEvent::start_event_by_index(get_owner_client());
    }
    if (start_effect(0x8, 0x10)) {
        TItemLockCountCtrl::lock_effect(get_owner_client(), 0);
    }
    if (start_effect(0x20, 0x40)) {
        ((PlayerAttackState *)&owner->attack_state)->set_item_effect();
    }
    if (start_effect(0x80, 0x100)) {
        TItemLockCountCtrl::lock_effect(get_owner_client(), 1);
    }
    if (start_effect(0x200, 0x400)) {
        TItemLockCountCtrl::lock_effect(get_owner_client(), 2);
    }
    if (start_effect(0x800, 0x1000)) {
        TItemLockCountCtrl::lock_effect(get_owner_client(), 3);
    }
    if (start_effect(0x2000, 0x4000)) {
        TItemLockCountCtrl::lock_effect(get_owner_client(), 4);
    }
    if (start_effect(0x8000, 0x10000)) {
        TItemLockCountCtrl::lock_effect(get_owner_client(), 5);
    }
    if (start_effect(0x20000, 0x40000)) {
        TItemLockCountCtrl::lock_effect(get_owner_client(), 6);
    }
}

void TItemEquipBase::remove_equip_effects() {
    if (stop_effect(0x1)) {
        release_model();
    }
    if (stop_effect(0x4)) {
        TItemTimerEvent::clear_timer_slot(get_owner_client());
    }
    if (stop_effect(0x10)) {
        TItemLockCountCtrl::unlock_effect(get_owner_client(), 0);
    }
    if (stop_effect(0x40)) {
        TObjPlayer *player = owner;
        if (player != NULL) {
            ((PlayerAttackState *)&player->attack_state)->clear_item_effect();
        }
    }
    if (stop_effect(0x100)) {
        TItemLockCountCtrl::unlock_effect(get_owner_client(), 1);
    }
    if (stop_effect(0x400)) {
        TItemLockCountCtrl::unlock_effect(get_owner_client(), 2);
    }
    if (stop_effect(0x1000)) {
        TItemLockCountCtrl::unlock_effect(get_owner_client(), 3);
    }
    if (stop_effect(0x4000)) {
        TItemLockCountCtrl::unlock_effect(get_owner_client(), 4);
    }
    if (stop_effect(0x10000)) {
        TItemLockCountCtrl::unlock_effect(get_owner_client(), 5);
    }
    if (stop_effect(0x40000)) {
        TItemLockCountCtrl::unlock_effect(get_owner_client(), 6);
    }
}

s32 TItemEquipBase::start_effect(u32 wanted, u32 started) {
    if (test_flags_any(&effect_flags.bits, wanted) && !test_flags_any(&effect_flags.bits, started)) {
        effect_flags.set(started);
        return 1;
    }
    return 0;
}

s32 TItemEquipBase::stop_effect(u32 started) {
    if (test_flags_any(&effect_flags.bits, started)) {
        effect_flags.clear(started);
        return 1;
    }
    return 0;
}

void TItemEquipBase::set_attach_joint(s32 joint) { attach_joint = joint; }

void TItemEquipBase::set_attach_slot(s8 slot) {
    attach_slot = slot;
    set_attach_joint((s8)item_equip_attach_equip_flag_table[get_attach_slot()]);
}

void TItemEquipBase::deduct_cap_excess(s32 item, s16 *stat, s16 excess) {
    if (excess > 0) {
        *stat -= excess;
    }
}

void TItemEquipBase::subtract_equip_stats(void *atp, s16 *stats, s16 *stats2) {
    AttackParams *attack = (AttackParams *)atp;
    ActorParamBlock *params = (ActorParamBlock *)stats;
    EquipStatBonus *player_stats = (EquipStatBonus *)stats2;
    if (attack != NULL) {
        attack->sub_atp_min(get_attack_params_atp_min(&attack_bonus));
        attack->sub_atp_max(get_attack_params_atp_max(&attack_bonus));
        attack->sub_ata(TObjPlayer__sub_800194E8(&attack_bonus));
    }
    if (params != NULL) {
        params->values[0] -= param_bonus.values[0];
        params->value_1c -= param_bonus.value_1c;
        params->values[1] -= param_bonus.values[1];
        params->values[2] -= param_bonus.values[2];
        params->values[3] -= param_bonus.values[3];
        params->values[4] -= param_bonus.values[4];
        params->values[5] -= param_bonus.values[5];
    }
    if (player_stats != NULL) {
        player_stats->atp -= stat_bonus.atp;
        player_stats->mst -= stat_bonus.mst;
        player_stats->evp -= stat_bonus.evp;
        player_stats->hp -= stat_bonus.hp;
        player_stats->dfp -= stat_bonus.dfp;
        player_stats->ata -= stat_bonus.ata;
        player_stats->lck -= stat_bonus.lck;
    }
}

void TItemEquipBase::subtract_item_stat_bonus(s32 player, s32 unused, s16 *stats) {
    u32 hp_tp;
    TItemData data;
    EquipStatBonus bonus;
    copy_to_item_data(&data);
    memset(&bonus, 0, sizeof(bonus));
    memset(&hp_tp, 0, sizeof(hp_tp));
    data.apply_equip_effects((s32)owner, player, unused, (s32)&bonus, (s32)&hp_tp);
    if (stats != NULL) {
        stats[0] -= bonus.atp;
        stats[1] -= bonus.mst;
        stats[2] -= bonus.evp;
        stats[3] -= bonus.hp;
        stats[4] -= bonus.dfp;
        stats[5] -= bonus.ata;
        stats[6] -= bonus.lck;
    }
}

void TItemEquipBase::reset() {
    memset(&stat_bonus, 0, sizeof(stat_bonus));
    memset(&attack_bonus, 0, sizeof(attack_bonus));
    memset(&param_bonus, 0, sizeof(param_bonus));
    memset(&hp_tp_bonus, 0, sizeof(hp_tp_bonus));
}

void TItemEquipBase::destroy() {
    if (get_mode() == ITEM_MODE_EQUIPPED) {
        unequip();
    }
    TItem::destroy();
}

void TItemEquipBase::remove_equip_stats(s32 apply) {
    if (owner != NULL) {
        AttackParams *attack = get_actor_attack_params(owner);
        ActorParamBlock *params = get_actor_param_block(owner);
        s16 *stats = (s16 *)((TQuestListVM *)owner)->get_quest_id();
        subtract_equip_stats(attack, (s16 *)params, stats);
        if (apply) {
            add_actor_hp_bonus(owner, (s16)-hp_tp_bonus.hp);
            add_actor_tp_bonus(owner, (s16)-hp_tp_bonus.tp);
            remove_owner_bonuses();
            owner->recalc_stats();
            owner->clamp_hp();
            owner->clamp_tp();
        }
        reset();
    }
}

void TItemEquipBase::unequip() {
    if (owner != NULL) {
        set_mode(ITEM_MODE_OWNED);
        clear_item_flags(ITEM_FLAG_EQUIPPED | 0x20);
        remove_equip_stats(1);
        remove_equip_effects();
        on_unequip();
        if (effect_objects != NULL) {
            effect_objects->delete_children();
        }
    }
}

void TItemEquipBase::add_equip_stats(s32 apply) {
    TItemData data;
    AttackParams *attack;
    ActorParamBlock *params;
    s32 item = (s32)this;
    if (owner != NULL) {
        copy_to_item_data(&data);
        data.apply_equip_effects((s32)owner, (s32)&attack_bonus, (s32)&param_bonus, (s32)&stat_bonus,
                                 (s32)&hp_tp_bonus);
        attack = get_actor_attack_params(owner);
        if (attack != NULL) {
            attack->add_atp_min(get_attack_params_atp_min(&attack_bonus));
            attack->add_atp_max(get_attack_params_atp_max(&attack_bonus));
            attack->add_ata(TObjPlayer__sub_800194E8(&attack_bonus));
        }
        params = get_actor_param_block(owner);
        if (params != NULL) {
            params->values[0] += param_bonus.values[0];
            params->value_1c += param_bonus.value_1c;
            params->values[1] += param_bonus.values[1];
            params->values[2] += param_bonus.values[2];
            params->values[3] += param_bonus.values[3];
            params->values[4] += param_bonus.values[4];
            params->values[5] += param_bonus.values[5];
        }
        if ((s16 *)((TQuestListVM *)owner)->get_quest_id() != NULL) {
            s16 excess = add_stat__10TObjPlayerFl(owner, stat_bonus.atp);
            deduct_cap_excess(item, &stat_bonus.atp, excess);
            deduct_cap_excess(item, &stat_bonus.mst, add_mst__10TObjPlayerFl(owner, stat_bonus.mst));
            deduct_cap_excess(item, &stat_bonus.evp, add_evp__10TObjPlayerFl(owner, stat_bonus.evp));
            deduct_cap_excess(item, &stat_bonus.hp, add_hp__10TObjPlayerFl(owner, stat_bonus.hp));
            deduct_cap_excess(item, &stat_bonus.dfp, add_dfp__10TObjPlayerFl(owner, stat_bonus.dfp));
            deduct_cap_excess(item, &stat_bonus.ata, add_ata__10TObjPlayerFl(owner, stat_bonus.ata));
            deduct_cap_excess(item, &stat_bonus.lck, add_lck__10TObjPlayerFl(owner, stat_bonus.lck));
        }
        if (apply) {
            add_actor_hp_bonus(owner, hp_tp_bonus.hp);
            add_actor_tp_bonus(owner, hp_tp_bonus.tp);
            apply_owner_bonuses();
            owner->recalc_stats();
        }
    }
}

void TItemEquipBase::equip() {
    if (owner != NULL) {
        update_owner_visibility();
        set_mode(ITEM_MODE_EQUIPPED);
        add_item_flags(ITEM_FLAG_EQUIPPED);
        add_equip_stats(1);
        if ((get_current_area() != 0xF) &&
            !test_flags_any(&effect_flags.bits, EQUIP_EFFECT_MODEL_REQUESTED)) {
            effect_flags.set(EQUIP_EFFECT_MODEL_REQUESTED);
            request_equipped_model();
        }
        apply_equip_effects();
        on_equip();
    }
}

void TItemEquipBase::release_model() {
    s16 id = model_resource_id;
    if (id != -1) {
        TItemLoad::release_resource_by_id(id);
        model_resource_id = -1;
        item_model = NULL;
        texture_id = 0;
        second_model = NULL;
        model_motion = NULL;
        model_data[0] = NULL;
        model_data[1] = NULL;
    }
}

void TItemEquipBase::request_model_load(u8 group) {
    TItemData data;
    data.init();
    data.data1.data_u8[0] = get_item_type();
    data.data1.data_u8[1] = group;
    data.data1.data_u8[2] = get_item_index();
    model_resource_id = request_item_model_load(&data.data1.data_u8[0]);
}

void TItemEquipBase::request_item_model() { request_model_load(get_item_group()); }

void TItemEquipBase::request_equipped_model() {}

TItemEquipBase::~TItemEquipBase() { remove_equip_effects(); }

TItemEquipBase::TItemEquipBase(TObject *parent, u8 *item) : TItem(parent, item) {
    m_name = item_equip_base_class_name;
    attach_slot = 0;
    attach_joint = 0;
    reset();
    model_resource_id = -1;
    effect_flags.reset();
    add_item_flags(ITEM_FLAG_EQUIPPABLE);
    effect_objects = new TItemHeapObject(this);
    model_motion = NULL;
    second_model = NULL;
    model_data[0] = NULL;
    model_data[1] = NULL;
}

// Out-of-line copies of inlines the functions above use, kept by the linker
// from this file because it calls them first.
u8 TItem::get_item_index() { return item_index; }

TechniqueBoost::TechniqueBoost() { clear(); }

void TechniqueBoost::clear() {
    technique = -1;
    flags = 0;
    amount = 0.0f;
}

void PlayerAttackState::set_item_effect() { flags.set(0x20); }

void PlayerAttackState::clear_item_effect() { flags.clear(0x20); }

void AttackParams::sub_ata(s32 amount) { ata -= amount; }

void AttackParams::sub_atp_max(s32 amount) { atp_max -= amount; }

void AttackParams::sub_atp_min(s32 amount) { atp_min -= amount; }

ActorParamBlock *get_actor_param_block(TUnk_804806E8 *actor) { return *(ActorParamBlock **)actor->unk_31C; }

AttackParams *get_actor_attack_params(TUnk_804806E8 *actor) { return (AttackParams *)actor->m_318; }

void AttackParams::add_ata(s32 amount) { ata += amount; }

void AttackParams::add_atp_max(s32 amount) { atp_max += amount; }

void AttackParams::add_atp_min(s32 amount) { atp_min += amount; }
