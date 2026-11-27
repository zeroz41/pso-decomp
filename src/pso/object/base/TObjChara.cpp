#include "pso/math/MatrixTransforms.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/SoundEffect.h"
#include "pso/enemy/EnemyMovement.h"
#include "pso/object/TActorLight.h"
#include "pso/player/TPlyDispData.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/effect/particle/ParticleFactory.h"

#include "pso/map/CsnQuery.h"
#include "pso/system/MainPhaseState.h"
#include "pso/system/MainPhaseTable.h"
#include "pso/render/BlobShadow.h"

#include "pso/math/MatrixReflect.h"

#include "pso/player/PlayerAttackParams.h"

#include "pso/system/vector.h"

#include "pso/system/byteswap.h"
#include "pso/math/InverseTrig.h"
#include <stdlib.h>

#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/player/PlayerSubcommandHandlers.h"

#include "pso/network/TGameProtocol.h"

#include "types.h"
#include "pso/object/base/HitEligibility.h"
#include "pso/map/CsnGroundCandidates.h"

#include "pso/effect/particle/TParticleCtrl.h"

#include "pso/system/task/TObject.h"

#include "pso/player/TObjPlayer.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/enemy/TObjEnemy.h"

#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/font/TFontSmallTask.h"

#include "pso/ui/keyboard/SystemBootInit.h"


#include "pso/item/TItem.h"


#include "pso/enemy/lappy/TObjEneLappy.h"

#include "pso/player/DamageBookkeeping.h"
#include "pso/object/base/TObjCharaData.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/system/scene/TScene.h"

#include "dolphin/mtx.h"

#include <stddef.h>

#include "pso/effect/TEffClitical.h"

#include "pso/boss/derolle/TObjBoss2Tunnel.h"

#include "pso/network/TLobby.h"
#include "pso/system/SubtractiveRng.h"

#include "pso/enemy/dubchik/TOCtrlDubchik.h"

#include "pso/map/FloorArea.h"

#include "pso/ui/TLogo.h"

#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"



#include "pso/ui/keyboard/TKeyBoardControl.h"

#include "pso/ui/frontend/OpeningMovie.h"


#include "pso/system/MainFrame.h"

#include "pso/ui/frontend/TAdEndText.h"

#include "pso/ui/frontend/EndingSequence.h"

#include "pso/system/scene/TEnding.h"


#include "pso/system/scene/OfflineGameScene.h"

#include "pso/system/scene/OnlineLobbyScene.h"

#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"


#include "pso/ui/frontend/TAdTrialModemChkGC.h"
#include "pso/effect/TEffHit.h"

#include "pso/item/TItemReverseTech.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/ScratchVectors.h"
#include "pso/map/CsnQuery.h"
#include "pso/map/area/AreaScene.h"
#include "pso/render/render_util.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/technique/TechniqueBoost.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/unk/TObjFreezeShell.h"
#include "pso/player/PlayerCommands.h"
#include "pso/player/LocalClientId.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/DebugFont.h"


class TObjPlayer;

extern "C" {
void dispatch_weapon_special_effect(void *, void *, void *, s32);
}

s32 calc_freeze_chance(TObjPlayer *actor, TObjPlayer *attacker, TObjPlayer *target, f32 base_chance);
s32 calc_shock_chance(TObjPlayer *actor, TObjPlayer *attacker, TObjPlayer *target);
void obj_copyVec2_0(u8* d, u8* s);
s16 obj_getS16_118(u8* p);





struct CharaResetView {
    u8 pad0[0x104];
    Vec v104;
    u8 pad110[0x320 - 0x110];
    s32 f320;
    u8 pad324[6];
    s16 f32a;
};



extern "C" {
s32 select_destination_away_from(TObjChara *chara, Vec point);
s32 create_damage_font__19TObjEneEpsilonGuardFllll(u32, s32, s32, s16);
s32 record_damage_stats(void *, void *, void *);
void obj_setField96_1(TObjCollidable *p);
const f32 player_attack_stat_status_light_colors[4] = {1.0f, 0.9f, 0.5f, 0.2f};
const f32 player_defense_stat_status_light_colors[4] = {1.0f, 0.4f, 0.8f, 1.0f};
const f32 status_light_desired[3] = {0.0f, 1.0f, 0.0f};

// inferred: update_poison_status adds entry [game_difficulty_selection] to each poison tick's damage
const s16 poison_damage_bonus_by_difficulty[4] = {0, 2, 5, 10};

// inferred: the zero vector find_nearest_visible_player starts its player-distance vector from
const Vec nearest_player_zero_vec = {0.0f, 0.0f, 0.0f};

static const f32 subtractive_rng_ratio_divisor = 65536.0f;
}
void apply_actor_gravity(TObjEnemy *enemy, s32 *ground_position, f32 hover_height);
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
s32 is_entity_locally_controlled(u16 id);
f64 fabs_double(f64 x);
#pragma push
#pragma fp_contract on
#pragma push


#pragma pop

#pragma push
#pragma fp_contract on

#pragma pop


void CsnGroundCandidates::clear() {
    s32 i;
    for (i = 0; i < 16; i++) {
        this->groups[i] = NULL;
    }
}

CsnGroundCandidates::CsnGroundCandidates() {
    clear();
}

#pragma push
#pragma fp_contract on
f32 newton_sqrtf(f32 x) {
    volatile f32 y;
    if (x > (0.0f)) {
        f64 guess = __frsqrte(x);
        guess = newton_sqrt_half * guess * (newton_sqrt_three - (f64) x * (guess * guess));
        guess = newton_sqrt_half * guess * (newton_sqrt_three - (f64) x * (guess * guess));
        guess = newton_sqrt_half * guess * (newton_sqrt_three - (f64) x * (guess * guess));
        y = (f32) ((f64) x * guess);
        return y;
    }
    return x;
}

#pragma pop
f64 fabs_double(f64 x) { return __fabs(x); }

f32 atan2_float(f32 y, f32 x) {
    return (f32) atan2((f64) y, (f64) x);
}

f32 fabs_float(f32 x) {
    return (f32) fabs_double((f64) x);
}

s32 PlayerPkState::is_enabled() { return enabled; }

u8 TItem::get_item_group() { return this->item_group; }

TItem *TObjPlayer::get_equipped_weapon(void *player) { return (TItem *)get_slot_value(((TObjPlayer *)player)->equipped_items.items, 6); }

s32 TObjPlayer::get_player_count() {
    return lobby_player_count;
}

s32 TObjPlayer::get_floor() { return this->current_floor; }

s32 get_current_floor(void) {
    return current_floor_index;
}

f32 SubtractiveRng::next_ratio() {
    const u32 sample = static_cast<u32>(next());
    return (f32) (sample >> 16) / *(const volatile f32 *)&subtractive_rng_ratio_divisor;
}

BOOL is_split_screen(void) {
    if (camera_split_screen_selector == 1) {
        return FALSE;
    }
    return TRUE;
}

void G_UpdateEntityStat_6x9A::init() {
    entity_index = 0xFFFF;
    what = 0;
    amount = 0;
    header.subcommand = 0x9A;
    header.size = sizeof(G_UpdateEntityStat_6x9A) / 4;
}

void G_UpdateEntityStat_6x9A::send() {
    bswap();
    send_subcommand(this);
}

void G_ClientIDHeader::bswap() { bswap_16(&client_id); }

void G_UpdateEntityStat_6x9A::bswap() {
    header.bswap();
    bswap_16(&entity_index);
}

void TObjBase::set_actor_flags(s32 flags) {
    actorFlags |= flags;
}

void TObjBase::clear_actor_flags(u32 mask) {
    actorFlags &= ~mask;
}

u16 TObjBase::get_entity_id() {
    return entity_id;
}

s32 TObjCollidable::test_actor_flags(u32 mask) {
    return actorFlags & mask;
}

void obj_setField96_1(TObjCollidable *p) {
    p->hit_receive_state = 1;
}

TObjPlayer *TObjPlayer::get_player_data(int index) { return static_cast<TObjPlayer *>(entity_table[index]); }

s32 obj_is_hit_receivable(const TObjCollidable *target) {
    return target->hit_receive_state == 1;
}

void TObjCollidable::interact(u16 client) { this->interactor = client; }

StatusEffect::StatusEffect() { clear(); }

void TObjChara::add_flags_2e4(u32 v) { (this->target_attribute_mask) |= v; }

void TObjChara::clear_immunity_flags() { this->immunity_flags = 0; }

s16 AttackParams::get_atp_max() { return this->atp_max; }

s16 TObjChara::get_stats_atp_max() { return this->attack_params->get_atp_max(); }

s16 AttackParams::get_ata() { return this->ata; }

s16 TObjChara::get_attack_params_ata() { return this->attack_params->get_ata(); }

s32 TObjChara::add_status_effect_timer(s32 i, s32 v) {
    return this->status_effects[i].timer += v;
}

f32 AttackParams::get_attack_range() { return attack_range; }

f32 TObjChara::get_attack_range() { return this->attack_params->get_attack_range(); }

s32 AttackParams::get_attack_angle() { return attack_angle; }

s32 TObjChara::get_attack_angle() { return this->attack_params->get_attack_angle(); }

s16 TObjPlayer::get_ata() { return this->ata; }
#pragma push
#pragma scheduling off
s32 TObjChara::get_status_effect_timer(s32 i) {
    return this->status_effects[i].timer;
}
#pragma pop
s16 TObjChara::test_immunity_flags(s32 mask) {
    return (s16) (this->immunity_flags & mask);
}

void TObjChara::set_status_effect_amount(s32 i, f32 amount) {
    this->status_effects[i].amount = amount;
}

void TObjChara::set_status_effect_type(s32 i, s32 type) {
    this->status_effects[i].type = type;
}

void TObjChara::set_status_effect_timer(s32 i, s32 timer) {
    this->status_effects[i].timer = timer;
}

s16 AttackParams::get_atp_min() { return this->atp_min; }

s16 TObjChara::get_actor_attack_params_atp_min() { return this->attack_params->get_atp_min(); }

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off
void obj_copyVec2_0(u8* d, u8* s) {
    *(int*)(d + 0) = *(int*)(s + 0);
    *(f32*)(d + 4) = *(f32*)(s + 4);
}

s32 TObjChara::obj_isState3_324() {
    return this->control_state == 3;
}

s16 TObjPlayer::obj_getS16_116() {
    return this->special_kind;
}

s16 obj_getS16_118(u8* p) {
    return *(s16*)(p + 0x118);
}

s32 TObjChara::obj_testFlag_2E4(u32 mask) {
    return (u8)((this->target_attribute_mask & mask) != 0);
}

s16 TObjChara::get_actor_hp() {
    return this->hp;
}

s16 TObjChara::get_tpmax() {
    return this->tpmax;
}

int TObjChara::obj_getPtr2B0_1C() {
    return this->stat_block->exp;
}

s32 TObjChara::get_actor_meseta() {
    return this->stat_block->meseta;
}

s16 TObjChara::get_actor_tp() {
    return this->tp;
}

s32 TObjChara::obj_isState2_324() {
    return this->control_state == 2;
}

#pragma pop
#pragma push
#pragma scheduling off
#pragma scheduling on
void TObjChara::clear_attack_credit_slot(s32 index) {
    attack_credit_slots[index] = 0xFFFF;
}

#pragma pop
#pragma push
#pragma scheduling off
u16 TObjChara::get_attack_credit_slot(s32 index) {
    return attack_credit_slots[index];
}

void TObjChara::set_attack_credit_slot(s32 index, u16 id) {
    attack_credit_slots[index] = id;
}

s32 TObjChara::get_status_effect_type(s32 i) {
    return this->status_effects[i].type;
}

#pragma pop
void StatusEffect::clear() {
    this->type = 0;
    this->amount = 0.0f;
    this->timer = 0;
}

s16 TObjChara::get_base_evp() { return (this->base_evp); }

f32 TObjChara::get_status_effect_amount(s32 i) {
    return this->status_effects[i].amount;
}

void TObjChara::adjust_evp(int amount) { this->evp = (this->evp + amount); }

s16 TObjChara::get_base_atp() { return this->base_atp; }

void TObjChara::adjust_atp(int amount) { this->atp = (this->atp + amount); }

s16 TObjChara::get_base_atp_range() { return this->base_atp_range; }

void TObjChara::adjust_atp_range(int amount) { this->atp_range = (this->atp_range + amount); }

s16 TObjChara::get_base_dfp() { return this->base_dfp; }

void TObjChara::adjust_dfp(int amount) { this->dfp = (this->dfp + amount); }

s16 TObjPlayer::get_eth() { return this->element_resist[1]; }

s16 TObjPlayer::get_eic() { return this->element_resist[2]; }

#pragma push
#pragma scheduling off
s32 TObjChara::is_locally_controlled() {
    return (u8) (this->control_state == 1);
}

Vec *VecCopy(Vec* dst, const Vec* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    return dst;
}

#pragma pop
void TObjChara::get_pos(saddr out) {
    VecCopy((Vec *)out, &this->body_center);
}

#pragma push
#pragma opt_common_subs off
TObjChara::TObjChara(TObject *parent) : TObjMotion(parent) {
    s32 i;
    s32 j;
    this->ground_cache = &this->ground_candidates;
    this->mode = 0;
    reset_motion_fields();
    this->stat_block = NULL;
    this->target = NULL;
    this->controller_input = NULL;
    this->attack_params = NULL;
    this->param_block = NULL;
    this->tp_bonus = 0;
    this->hp_bonus = 0;
    this->tp = 0;
    this->hp = 0;
    this->tpmax = 0;
    this->hpmax = 0;
    this->kill_count = 0;
    this->atp = 0;
    this->base_atp = 0;
    this->atp_range = 0;
    this->base_atp_range = 0;
    this->evp = 0;
    this->base_evp = 0;
    this->dfp = 0;
    this->base_dfp = 0;
    this->lck = 0;
    this->ata = 0;
    *(s32 *)((s8 *)this + 0x2E0) = 0;
    this->element_attack[4] = 0;
    this->element_attack[3] = 0;
    this->element_attack[2] = 0;
    this->element_attack[1] = 0;
    this->element_attack[0] = 0;
    this->element_resist[4] = 0;
    this->element_resist[3] = 0;
    this->element_resist[2] = 0;
    this->element_resist[1] = 0;
    this->element_resist[0] = 0;
    this->rng.set_seed(this->entity_id);
    this->target_attribute_mask = 0;
    this->add_flags_2e4(0);
    this->control_state = 0;
    this->owner_entity_id = 0xFFFF;
    for (i = 0; i < 3; i++) {
        attack_attributes[i].area = 0;
        attack_attributes[i].percent = 0;
    }
    for (j = 0; j < 5; j++) {
        this->status_effects[j].clear();
    }
    special_kind = 0;
    special_power = 0;
    local_attacker_id = 0xFFFF;
    TObjPlayer::clear_s16_arrays(this);
    this->low_game_flags = 0;
    obj_setField96_1(this);
    clear_immunity_flags();
}

#pragma pop
TObjChara::~TObjChara() {}

void TObjChara::reset_motion_fields() {
    CharaResetView *self = (CharaResetView *)this;
    self->v104.x = self->v104.y = self->v104.z = (0.0f);
    move_origin.x = move_origin.y = move_origin.z = (0.0f);
    move_destination.x = move_destination.y = move_destination.z = (0.0f);
    this->ground_normal.x = this->ground_normal.z = (0.0f);
    ground_normal.y = (1.0f);
    this->move_timer = 0;
    this->frame_timer = (0.0f);
    this->attacker_id = 0xFFFF;
    this->hit_flags = 0;
    this->phase = prev_mode = 0;
    this->mode_mask = 0;
    body_center.x = body_center.y = body_center.z = velocity.x = velocity.y = velocity.z = (0.0f);
}

void *TObjChara::get_center() { return &body_center; }

CsnHit *TObjChara::update_actor_ground_y() {
    Vec stack;
    f32 base_y;
    CsnHit *hit;
    player_stats *stats;
    stack.x = position.x;
    stats = this->stat_block;
    base_y = position.y;
    stack.y = base_y + stats->proportions;
    stack.z = position.z;
    hit = csnVectorUnder(&stack, ground_candidates.groups, 0x15);
    if (hit == NULL) {
        return NULL;
    }
    position.y = hit->contact->point.y;
    return hit;
}

CsnHit *TObjChara::update_actor_ground_y_at(Vec *pos) {
    Vec stack;
    f32 y;
    CsnHit *hit;
    player_stats *stat_block;
    stack.x = pos->x;
    stat_block = this->stat_block;
    y = pos->y;
    stack.y = y + stat_block->proportions;
    stack.z = pos->z;
    hit = csnVectorUnder(&stack, ground_candidates.groups, 0x15);
    if (hit == NULL) {
        return NULL;
    }
    position.y = hit->contact->point.y;
    return hit;
}

#pragma push
#pragma fp_contract on
void TObjChara::calc_attach_pos() {
    if ((void *) this->stat_block != NULL) {
        this->body_center.x = (f32) this->position.x;
        this->body_center.y = (f32) (((0.5f) * this->stat_block->proportions) + this->position.y);
        this->body_center.z = (f32) this->position.z;
        return;
    }
    VecCopy(&this->body_center, &this->position);
}

s32 TObjChara::recalc_combat_stats(player_stats *base_stats, AttackParams *attack_stats, ActorParamBlock *resistance_stats, f32 xscale, f32 yscale) {
    if (base_stats != NULL) {
        this->stat_block = base_stats;
        this->hpmax = (s16)(xscale * (f32)(this->stat_block->stats.hp + this->stat_block->level) + (f32)this->hp_bonus);
        this->hp = this->hpmax;
        if (this->obj_testFlag_2E4(4) != 0) {
            this->tpmax = 0;
            this->tp = 0;
        } else {
            this->tpmax = (s16)(yscale * (f32)(this->stat_block->stats.mst + this->stat_block->level) + (f32)this->tp_bonus);
            this->tp = this->tpmax;
        }
    } else if (this->stat_block != NULL) {
        this->hpmax = (s16)(xscale * (f32)(this->stat_block->stats.hp + this->stat_block->level) + (f32)this->hp_bonus);
        if (this->obj_testFlag_2E4(4) != 0) {
            this->tpmax = 0;
            this->tp = 0;
        } else {
            this->tpmax = (s16)(yscale * (f32)(this->stat_block->stats.mst + this->stat_block->level) + (f32)this->tp_bonus);
        }
    } else {
        return 0;
    }
    if (attack_stats != NULL) {
        this->attack_params = attack_stats;
    } else if (this->attack_params == NULL) {
        return 0;
    }
    if (resistance_stats != NULL) {
        this->param_block = resistance_stats;
    } else if (this->param_block == NULL) {
        return 0;
    }
    this->base_atp = this->atp = this->stat_block->stats.atp;
    this->base_atp_range = this->atp_range = this->get_stats_atp_max() - this->get_actor_attack_params_atp_min();
    this->base_evp = this->evp = this->stat_block->stats.evp + this->param_block->values[0];
    this->base_dfp = this->dfp = this->stat_block->stats.dfp + this->param_block->value_1c;
    this->ata = (s16)((0.1f) * (f32)(this->stat_block->stats.ata + get_attack_params_ata()));
    this->lck = this->stat_block->stats.lck;
    this->element_resist[0] = this->param_block->values[1];
    this->element_resist[1] = this->param_block->values[3];
    this->element_resist[2] = this->param_block->values[2];
    this->element_resist[4] = this->param_block->values[4];
    this->element_resist[3] = this->param_block->values[5];
    this->adjust_atp((f32)this->get_base_atp() * this->get_status_effect_amount(2));
    this->adjust_atp_range((f32)this->get_base_atp_range() * this->get_status_effect_amount(2));
    this->adjust_dfp((f32)this->get_base_dfp() * this->get_status_effect_amount(3));
    return 1;
}

#pragma pop
s32 TObjChara::set_motion_params(player_stats *base_stats) {
    if (base_stats != NULL) {
        this->stat_block = base_stats;
        this->hpmax = this->stat_block->stats.hp + this->stat_block->level + this->hp_bonus;
        this->tpmax = this->stat_block->stats.mst + this->stat_block->level + this->tp_bonus;
        this->hp = this->hpmax;
        this->tp = this->tpmax;
    } else if (this->stat_block != NULL) {
        this->hpmax = this->stat_block->stats.hp + this->stat_block->level + this->hp_bonus;
        this->tpmax = this->stat_block->stats.mst + this->stat_block->level + this->tp_bonus;
    } else {
        return 0;
    }
    this->base_atp = this->atp = this->stat_block->stats.atp;
    this->base_atp_range = this->atp_range = 0;
    this->base_evp = this->evp = this->stat_block->stats.evp;
    this->base_dfp = this->dfp = this->stat_block->stats.dfp;
    this->ata = (s16)((0.1f) * (f32)this->stat_block->stats.ata);
    this->lck = this->stat_block->stats.lck;
    this->element_attack[3] = 0;
    this->element_attack[4] = 0;
    this->element_attack[2] = 0;
    this->element_attack[1] = 0;
    this->element_attack[0] = 0;
    this->element_resist[3] = 0;
    this->element_resist[4] = 0;
    this->element_resist[2] = 0;
    this->element_resist[1] = 0;
    this->element_resist[0] = 0;
    return 1;
}

f32 TObjPlayer::calc_distance_to_client(const TObjBase *actor, u16 client, Vec *delta) {
    Vec direction;
    f32 distance = 1.0e8f;
    if (client < 0x1000U) {
        TObjPlayer *player = get_player_by_client_id(client);
        if (player != NULL && !(player->actorFlags & 0x800)) {
            if (player->get_floor() == get_current_floor()) {
                distance = calc_xz_distance_sq(actor, player, &direction);
                if (delta != NULL) {
                    VecCopy(delta, &direction);
                }
            }
        }
    }
    return distance;
}

f32 calc_xz_distance_sq(const TObjBase *actor, const TObjBase *target, Vec *offset) {
    Vec diff;
    f32 distance;
    if (target != NULL) {
        VecCopy(&diff, &target->position);
        subtract_vector(&diff, &actor->position);
        diff.y = 0.01f;
        distance = (diff.x * diff.x) + (diff.z * diff.z);
        if (offset != NULL) {
            VecCopy(offset, &diff);
        }
    } else {
        distance = 1.0e8f;
    }
    return distance;
}

s32 TObjEnemy::enemy_turn_toward_dest(s32 turn) {
    Vec d;
    s32 a;
    VecCopy(&d, &this->move_destination);
    subtract_vector(&d, &this->position);
    a = (s32)(angle_units_per_radian * atan2_float(d.x, d.z));
    this->rotation_y = approach_angle_limited(this->rotation_y, a, turn);
    return angle_difference_abs(this->rotation_y, a);
}

s32 TObjEnemy::turn_toward_direction(s32 max_step, Vec *direction) {
    s32 target_angle;

    target_angle = (s32) (angle_units_per_radian * atan2_float(direction->x, direction->z));
    this->rotation_y = approach_angle_limited(this->rotation_y, target_angle, max_step);
    return angle_difference_abs(this->rotation_y, target_angle);
}

void enemy_turn_half_toward_dest(TObjChara *chara) {
    Vec d;
    s32 a;
    VecCopy(&d, &chara->move_destination);
    subtract_vector(&d, &chara->position);
    a = (s32)(angle_units_per_radian * atan2_float(d.x, d.z));
    chara->rotation_y = lerp_angle_half(chara->rotation_y, a);
    angle_difference_abs(chara->rotation_y, a);
}

s32 copy_position_if_valid(TObjChara *chara, Vec pos) {
    if (project_actor_to_ground(chara, &pos, 0) != 0) {
        VecCopy(&chara->move_origin, &chara->position);
        return 1;
    }
    return 0;
}

s32 check_path_obstructed(TObjChara *chara, Vec *target) {
    Vec d;
    s32 a;
    VecCopy(&d, target);
    subtract_vector(&d, &chara->body_center);
    if ((9e+04f) < (d.x * d.x) + (d.z * d.z)) {
        a = (s32) (angle_units_per_radian * atan2_float(d.x, d.z));
        d.y = d.x = (0.0f);
        d.z = (3e+02f);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, a);
        rotate_vector_by_matrix(0, &d, &d);
        pop_matrix();
        vec3_add_to(&d, &chara->body_center);
    } else {
        VecCopy(&d, target);
    }
    if (csnLookAt(&chara->body_center, &d) != 0) {
        return 1;
    }
    return 0;
}

s32 select_enemy_destination(TObjChara *chara, Vec dest, s32 flags) {
    Vec d;
    s32 a;
    if (project_actor_to_ground(chara, &dest, 0) != 0) {
        VecCopy(&d, &dest);
        if (!(flags & 1)) {
            d.y = chara->body_center.y;
        } else {
            d.y += chara->body_center.y - chara->position.y;
        }
        if (chara->bodies != NULL) {
            subtract_vector(&d, &chara->body_center);
            a = (s32)(angle_units_per_radian * atan2_float(d.x, d.z));
            scratch_vec.x = scratch_vec.y = (0.0f);
            scratch_vec.z = chara->bodies->radius;
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, a);
            rotate_vector_by_matrix(0, &scratch_vec, &scratch_vec);
            pop_matrix();
            vec3_add_to(&d, &scratch_vec);
            vec3_add_to(&d, &chara->body_center);
        }
        if (!(flags & 2) && check_path_obstructed(chara, &d) != 0) {
            return 0;
        }
        if (!(flags & 4) && csnVector(&chara->body_center, &d, -1) != 0) {
            return 0;
        }
        VecCopy(&chara->move_destination, &dest);
    return 1;
    }
    return 0;
}

s32 select_destination_away_from(TObjChara *chara, Vec point) {
    Vec d;
    VecCopy(&d, &point);
    subtract_vector(&d, &chara->body_center);
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, 0x8000);
    rotate_vector_by_matrix(0, &d, &d);
    pop_matrix();
    if ((1e-05f) < vec_squared_length(&d)) {
        normalize_vector(&d);
        vec3_add_to(&d, &chara->body_center);
        return select_enemy_destination(chara, d, 1);
    }
    return 0;
}

void calc_velocity_toward_destination(TObjChara *chara, Vec from, Vec to, f32 speed) {
    Vec d;
    s32 a;
    VecCopy(&d, &to);
    subtract_vector(&d, &from);
    if (d.x * d.x + d.z * d.z < (1e-05f)) {
        chara->velocity.z = (0.0f);
        chara->velocity.x = (0.0f);
    } else {
        a = (s32)(angle_units_per_radian * atan2_float(d.x, d.z));
        d.z = speed;
        d.x = d.y = (0.0f);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, a);
        rotate_vector_by_matrix(0, &d, &d);
        pop_matrix();
        chara->velocity.x = d.x;
        chara->velocity.z = d.z;
    }
}

void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading) {
    Vec stack;
    stack.z = speed;
    stack.y = (0.0f);
    stack.x = (0.0f);
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, heading);
    rotate_vector_by_matrix(0, &stack, &stack);
    pop_matrix();
    enemy->velocity.x = stack.x;
    enemy->velocity.z = stack.z;
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void move_with_wall_slide(TObjChara *actor) {
    Vec next;
    Vec direction;
    Vec tangent;
    CsnHit *hit;
    CsnContact *contact;
    f32 speed;
    f32 tangent_x;
    f32 velocity_x_squared;
    f32 velocity_z_squared;

    VecCopy(&actor->prev_position, &actor->position);
    VecCopy(&next, &actor->body_center);
    vec3_add_to(&next, &actor->velocity);
    VecCopy(&direction, &actor->velocity);
    normalize_vector_xz(&direction);
    next.x = 5.0f * direction.x + next.x;
    next.z = 5.0f * direction.z + next.z;
    hit = csnVector(&actor->body_center, &next, 0x8FE0);
    if (hit != NULL) {
        contact = hit->contact;
        tangent.x = contact->normal.z;
        tangent.z = -contact->normal.x;
        normalize_vector_xz(&tangent);
        velocity_x_squared = actor->velocity.x * actor->velocity.x;
        velocity_z_squared = actor->velocity.z * actor->velocity.z;
        speed = newton_sqrtf(velocity_x_squared + velocity_z_squared);
        if ((actor->velocity.x * (tangent_x = tangent.x) + actor->velocity.z * tangent.z) >= 0.0f) {
            actor->velocity.x = tangent_x * speed;
            actor->velocity.z = tangent.z * speed;
        } else {
            actor->velocity.x = -tangent_x * speed;
            actor->velocity.z = -tangent.z * speed;
        }
        VecCopy(&next, &actor->body_center);
        vec3_add_to(&next, &actor->velocity);
        VecCopy(&direction, &actor->velocity);
        normalize_vector_xz(&direction);
        next.x = 5.0f * direction.x + next.x;
        next.z = 5.0f * direction.z + next.z;
        if (csnVector(&actor->body_center, &next, 0x8FE0) != NULL) {
            return;
        }
    }
    VecCopy(&next, &actor->body_center);
    vec3_add_to(&next, &actor->velocity);
    next.y += 10.0f;
    if (csnVecterUnder(&next, 0xE0) == NULL && project_actor_to_ground(actor, &next, NULL) != 0) {
        VecCopy(&actor->position, &next);
    }
}

#pragma pop
extern "C" {
f32 update_enemy_wander_move(TObjEnemy *enemy, Vec dest, s32 flags, f32 speed) {
    if (enemy->is_actor_cadence_frame(0x1E) != 0) {
        if (select_enemy_destination(enemy, dest, flags) != 0) {
            copy_position_if_valid(enemy, enemy->body_center);
        }
    }
    calc_velocity_toward_destination(enemy, enemy->move_origin, enemy->move_destination, speed);
    move_with_wall_slide(enemy);
    return horizontal_distance_squared(&dest, &enemy->position);
}

f32 TObjEnemy::enemy_wander_home(f32 speed, f32 range_x, f32 range_z, s32 turn) {
    Vec v;
    f32 dist_sq;
    s32 ang;
    dist_sq = horizontal_distance_squared(&this->body_center, &this->move_destination);
    if ((dist_sq < (speed * speed)) || (this->is_actor_cadence_frame(0x96) != 0)) {
        v.x = v.y = (0.0f);
        v.z = (1.0f);
        ang = (s32) ((182.04445f) * ((3.6e+02f) * this->random_ratio()));
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, ang);
        rotate_vector_by_matrix(0, &v, &v);
        pop_matrix();
        v.x *= range_x;
        v.z *= range_z;
        vec3_add_to(&v, &this->home_position);
        select_enemy_destination(this, v, 1);
        this->velocity.x = this->velocity.z = (0.0f);
        this->move_timer = 0;
    } else {
        this->enemy_turn_toward_dest(turn);
        enemy_set_heading_velocity(speed, this, this->rotation_y);
        move_with_wall_slide(this);
        dist_sq = horizontal_distance_squared(&this->move_destination, &this->body_center);
        this->move_timer = this->move_timer + 1;
    }
    return dist_sq;
}

f32 enemy_backstep_from_point(TObjEnemy *enemy, Vec point, f32 speed) {
    if (select_destination_away_from(enemy, point) != 0) {
        copy_position_if_valid(enemy, enemy->body_center);
        calc_velocity_toward_destination(enemy, enemy->move_origin, enemy->move_destination, speed);
        move_with_wall_slide(enemy);
        return horizontal_distance_squared(&point, &enemy->position);
    }
    return (0.0f);
}

f32 enemy_pursue_point(TObjEnemy *enemy, s32 turn_speed, Vec point, f32 speed, f32 step) {
    f32 d0;
    f32 d1;
    f32 d2;
    s32 a;
    Vec d;
    d0 = horizontal_distance_squared(&enemy->body_center, &enemy->move_origin);
    d1 = horizontal_distance_squared(&enemy->move_origin, &enemy->move_destination);
    d2 = horizontal_distance_squared(&enemy->body_center, &enemy->move_destination);
    if (step * step <= d0 || d1 < (1e-05f) || d2 < (1e-05f) || enemy->is_actor_cadence_frame(0x96) != 0) {
        VecCopy(&d, &point);
        subtract_vector(&d, &enemy->body_center);
        a = (s32)(angle_units_per_radian * atan2_float(d.x, d.z));
        d.z = step;
        d.x = d.y = (0.0f);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, a);
        rotate_vector_by_matrix(0, &d, &d);
        pop_matrix();
        vec3_add_to(&d, &enemy->body_center);
        if (select_enemy_destination(enemy, d, 1) != 0) {
            copy_position_if_valid(enemy, enemy->body_center);
        }
    }
    enemy->enemy_turn_toward_dest(turn_speed);
    enemy_set_heading_velocity(speed, enemy, enemy->rotation_y);
    move_with_wall_slide(enemy);
    return horizontal_distance_squared(&point, &enemy->body_center);
}

f32 step_toward_destination(TObjChara *chara, Vec dest, f32 speed) {
    VecCopy(&chara->move_destination, &dest);
    VecCopy(&chara->move_origin, &chara->body_center);
    calc_velocity_toward_destination(chara, chara->move_origin, chara->move_destination, speed);
    chara->position.x += chara->velocity.x;
    chara->position.z += chara->velocity.z;
    return horizontal_distance_squared(&dest, &chara->position);
}

f32 enemy_move_toward(TObjEnemy *enemy, s32 turn_speed, Vec dest, s32 flags, f32 speed) {
    if (horizontal_distance_squared(&enemy->move_destination, &enemy->position) < (1e-05f) || enemy->is_actor_cadence_frame(0x1E) != 0) {
        if (select_enemy_destination(enemy, dest, flags) != 0) {
            copy_position_if_valid(enemy, enemy->body_center);
        }
    }
    enemy->enemy_turn_toward_dest(turn_speed);
    enemy_set_heading_velocity(speed, enemy, enemy->rotation_y);
    move_with_wall_slide(enemy);
    return horizontal_distance_squared(&dest, &enemy->position);
}

s32 TObjChara::is_target_in_attack_range() {
    Vec v;
    Vec base;
    Vec out;
    TObjChara *t;
    s32 i;
    s32 ang;
    f32 range;
    f32 dist;
    f32 prod;
    if (target != NULL && attack_params != NULL &&
        target->all_parents_unqueued_for_destruction() != 0 &&
        find_entity_by_id(target->get_entity_id()) != NULL) {
        t = target;
        if (!(t->actorFlags & 0x800)) {
            if (t->bodies != NULL) {
                VecCopy(&base, &t->position);
                for (i = 0; i < target->body_count; i++) {
                    if (!(target->bodies[i].flags & 0x02000000)) {
                        VecCopy(&v, &target->bodies[i].offset);
                        push_matrix_from(identity_matrix);
                        rotate_matrix_y(0, target->rotation_y);
                        rotate_vector_by_matrix(0, &v, &v);
                        pop_matrix();
                        vec3_add_to(&v, &base);
                        subtract_vector(&v, &position);
                        dist = v.x * v.x + v.z * v.z;
                        range = (target->bodies[i].radius + get_attack_range()) * (target->bodies[i].radius + get_attack_range());
                        ang = ((s32)angle_difference_abs(this->rotation_y, (s32)(angle_units_per_radian * atan2_float(v.x, v.z))));
                        if (dist < range && ang < get_attack_angle()) {
                            return 1;
                        }
                    }
                }
            } else {
                dist = calc_xz_distance_sq(this, reinterpret_cast<const TObjBase *>(t), &out);
                ang = ((s32)angle_difference_abs(this->rotation_y, (s32)(angle_units_per_radian * atan2_float(out.x, out.z))));
                if (target->bodies != NULL) {
                    prod = (target->bodies->radius + get_attack_range()) * (target->bodies->radius + get_attack_range());
                } else {
                    prod = get_attack_range() * get_attack_range();
                }
                if (dist <= prod && ang <= get_attack_angle()) {
                    return 1;
                }
            }
        } else {
            target = NULL;
        }
    }
    return 0;
}

s32 TObjChara::update_evp_status() {
    if (this->test_actor_flags(0x40) != 0) {
        this->clear_harmful_statuses();
        return 1;
    }
    if (this->obj_isState2_324() != 0) {
        if (this->test_actor_flags(3) == 0) {
            switch (this->get_status_effect_type(0)) {
            case 0x10:
                adjust_evp((s32)(this->get_base_evp() * -this->get_status_effect_amount(0)));
                break;
            }
            this->status_effects[0].clear();
        }
        if (this->test_actor_flags(0x3C) == 0) {
            switch (this->get_status_effect_type(1)) {
            case 2:
            case 3:
                adjust_evp((s32)(this->get_base_evp() * -this->get_status_effect_amount(1)));
                break;
            }
            this->status_effects[1].clear();
        }
    }
    return 0;
}
s32 TObjChara::update_poison_status() {
    s32 dmg;

    if (this->test_actor_flags(1) != 0) {
        if ((this->add_status_effect_timer(0, 1) % 45) == 0) {
            this->spawn_poison_effect(1);
            this->set_status_effect_timer(0, 0);
            dmg = (s32) ((0.006666667f) * (f32) get_actor_hp());
            if ((s16) dmg < 1) {
                dmg = 1;
            }
            ((s32 (*)(TObjChara *, s32, const s16 *))subtract_actor_hp)(this, dmg + poison_damage_bonus_by_difficulty[game_difficulty_selection], poison_damage_bonus_by_difficulty);
            if (this->clamp_hp() <= 0) {
                if (this->test_actor_flags(0x800) == 0) {
                    ((TObjPlayer *)((u8 *)this))->set_hp_clamped(1);
                }
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

s32 TObjChara::update_action_hold_status() {
    f32 evp_scale;
    s32 timer_left;

    if ((this->test_actor_flags(0x4000) != 0) && ((u16) this->entity_id >= 0x1000U)) {
        if (this->add_status_effect_timer(4, -1) <= 0) {
            this->status_effects[4].clear();
            this->clear_actor_flags(0x4000);
        }
        return 1;
    }
    if (this->test_actor_flags(2) != 0) {
        timer_left = this->add_status_effect_timer(0, -1);
        if ((u16) this->entity_id < 0x1000U) {
            if (timer_left <= 0) {
                this->spawn_paralysis_feedback_effect(1);
                this->set_status_effect_timer(0, 0x2D);
            }
            return 1;
        }
        if (timer_left > 0) {
            this->clear_actor_flags(3);
            set_actor_flags(2);
            if ((timer_left % 45) == 0) {
                this->spawn_paralysis_feedback_effect(1);
            }
            return 1;
        }
        this->clear_actor_flags(3);
        low_game_flags = actorFlags & 0x3F;
        evp_scale = -this->get_status_effect_amount(0);
        {
            f32 v = this->get_base_evp();
            v *= evp_scale;
            this->adjust_evp((s32) v);
        }
        this->status_effects[0].clear();
    }
    return 0;
}

s32 TObjChara::update_slow_status() {
    s32 remaining;

    if ((this->test_actor_flags(8) != 0) && ((u16) this->entity_id < 0x1000U)) {
        remaining = this->add_status_effect_timer(1, -1);
        if (remaining > 0) {
            if ((remaining % 45) == 0) {
                this->spawn_slow_effect(1);
            }
            return 1;
        }
        this->clear_actor_flags(0x3C);
        low_game_flags = actorFlags & 0x3F;
        this->status_effects[1].clear();
    }
    return 0;
}

s32 TObjChara::update_flag30_timer() {
    s32 remaining;

    if (this->test_actor_flags(0x10) != 0) {
        remaining = this->add_status_effect_timer(1, -1);
        if (remaining > 0) {
            this->clear_actor_flags(0x3C);
            set_actor_flags(0x10);
            if ((remaining % 45) == 0) {
                this->spawn_confusion_feedback_effect(1);
            }
            return 1;
        }
        this->clear_actor_flags(0x3C);
        low_game_flags = actorFlags & 0x3F;
        this->status_effects[1].clear();
    }
    return 0;
}

s32 TObjChara::update_movement_status() {
    f32 evp_scale;
    f32 fv;
    s32 remaining;

    if (this->test_actor_flags(0x20) != 0) {
        remaining = this->add_status_effect_timer(1, -1);
        if (remaining > 0) {
            this->clear_actor_flags(0x3C);
            set_actor_flags(0x20);
            if ((remaining % 45) == 0) {
                play_sound_effect(0xB20F, &position, 0, 0);
            }
            return 1;
        }
        this->clear_actor_flags(0x3C);
        low_game_flags = actorFlags & 0x3F;
        evp_scale = -this->get_status_effect_amount(1);
        fv = (f32) this->get_base_evp();
        this->adjust_evp((s32) (fv * evp_scale));
        this->status_effects[1].clear();
    }
    return 0;
}

s32 TObjChara::update_shock_clock() {
    f32 evp_scale;
    f32 fv;
    s32 remaining;
    if (this->test_actor_flags(4) != 0) {
        remaining = this->add_status_effect_timer(1, -1);
        if (remaining > 0) {
            this->clear_actor_flags(0x3C);
            set_actor_flags(4);
            if ((remaining % 45) == 0) {
                this->play_shock_feedback(1);
            }
            return 1;
        }
        this->clear_actor_flags(0x3C);
        low_game_flags = actorFlags & 0x3F;
        if ((u16) this->entity_id >= 0x1000U) {
            evp_scale = -this->get_status_effect_amount(1);
            fv = (f32) this->get_base_evp();
            this->adjust_evp((s32) (fv * evp_scale));
        }
        this->status_effects[1].clear();
    }
    return 0;
}

s32 TObjChara::update_attack_stat_status() {
    s32 remaining;

    if (this->get_status_effect_timer(2) > 0) {
        remaining = this->add_status_effect_timer(2, -1);
        if (remaining > 0) {
            if (((remaining % 45) == 0) && (this->test_actor_flags(0x02000000) == 0)) {
                switch (this->get_status_effect_type(2)) {
                case 10:
                    break;
                case 9:
                    this->apply_switch_attack();
                    if ((this->test_actor_flags(0x10000000) == 0) || (this->is_locally_controlled() != 0)) {
                        play_sound_effect(0x4002462A, &position, 0, 0);
                    }
                    break;
                case 11:
                    this->enemy_spawn_jellen_effect();
                    if ((this->test_actor_flags(0x10000000) == 0) || (this->is_locally_controlled() != 0)) {
                        play_sound_effect(0x4002442B, &position, 0, 0);
                    }
                    break;
                }
                new TActorLight(0.1f, (NJS_ARGB *)player_attack_stat_status_light_colors, (Vec *)status_light_desired, 0x2D, this, tl_07);
            }
            return 1;
        }
        this->adjust_atp((s32) ((f32) this->get_base_atp() * -this->get_status_effect_amount(2)));
        this->adjust_atp_range((s32) ((f32) this->get_base_atp_range() * -this->get_status_effect_amount(2)));
        this->status_effects[2].clear();
    } else if (this->obj_isState2_324() != 0) {
        this->adjust_atp((s32) ((f32) this->get_base_atp() * -this->get_status_effect_amount(2)));
        this->adjust_atp_range((s32) ((f32) this->get_base_atp_range() * -this->get_status_effect_amount(2)));
        this->status_effects[2].clear();
    }
    return 0;
}

s32 TObjChara::update_defense_stat_status() {
    s32 remaining;

    if (this->get_status_effect_timer(3) > 0) {
        remaining = this->add_status_effect_timer(3, -1);
        if (remaining > 0) {
            if (((remaining % 45) == 0) && (this->test_actor_flags(0x02000000) == 0)) {
                switch (this->get_status_effect_type(3)) {
                case 11:
                    break;
                case 10:
                    this->trigger_switch_attack();
                    if ((this->test_actor_flags(0x10000000) == 0) || (this->is_locally_controlled() != 0)) {
                        play_sound_effect(0x40022C2C, &position, 0, 0);
                    }
                    break;
                case 12:
                    this->enemy_spawn_zalure_effect();
                    if ((this->test_actor_flags(0x10000000) == 0) || (this->is_locally_controlled() != 0)) {
                        play_sound_effect(0x4002362D, &position, 0, 0);
                    }
                    break;
                }
                new TActorLight(0.1f, (NJS_ARGB *)player_defense_stat_status_light_colors, (Vec *)status_light_desired, 0x2D, this, tl_07);
            }
            return 1;
        }
        this->adjust_dfp((s32) ((f32) this->get_base_dfp() * -this->get_status_effect_amount(3)));
        this->status_effects[3].clear();
    } else if (this->obj_isState2_324() != 0) {
        this->adjust_dfp((s32) ((f32) this->get_base_dfp() * -this->get_status_effect_amount(3)));
        this->status_effects[3].clear();
    }
    return 0;
}

s32 TObjChara::select_melee_contact_body(TObjChara *attacker, f32 factor) {
    s32 selected = -1;
    Vec point;
    s32 i;
    s32 diff;
    f32 dist2;
    f32 r2;
    f32 dist;
    f32 r;
    if (attacker != NULL) {
    if (bodies != NULL) {
        push_matrix();
        set_matrix_identity(0);
        translate_matrix(0, -attacker->position.x, -attacker->position.y, -attacker->position.z);
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        for (i = 0; i < body_count; i++) {
            if (!(bodies[i].flags & 0x02000000)) {
                VecCopy(&point, &bodies[i].offset);
                matrix_mult_vec(NULL, &point, &point);
            }
            dist = point.x * point.x + point.z * point.z;
            r = (bodies[i].radius + attacker->get_attack_range()) * (bodies[i].radius + attacker->get_attack_range());
            diff = angle_difference_abs(attacker->rotation_y, (s32)(angle_units_per_radian * atan2_float(point.x, point.z)));
            if (dist < r && diff < attacker->get_attack_angle()) {
                selected = i;
                break;
            }
        }
        pop_matrix();
        if (selected == -1) {
            return 0;
        }
    } else {
        VecCopy(&point, &position);
        subtract_vector(&point, &attacker->position);
        dist2 = point.x * point.x + point.z * point.z;
        r2 = attacker->get_attack_range() * attacker->get_attack_range();
        r2 = r2 * r2;
        diff = angle_difference_abs(attacker->rotation_y, (s32)(angle_units_per_radian * atan2_float(point.x, point.z)));
        if (r2 < dist2 || attacker->get_attack_angle() < diff) {
            return 0;
        }
    }
    if (try_start_action(attacker, selected, factor) != 0) {
        return 1;
    }
    }
    return 0;
}

s32 TObjChara::try_start_action(TObjChara *attacker, s32 collider, f32 accuracy) {
    if (roll_physical_accuracy(attacker, collider, accuracy) != 0) {
        return 1;
    }
    ((TObjPlayer *)this)->show_miss_for_collider(collider);
    return 0;
}
#pragma push
#pragma fp_contract on
s32 TObjChara::roll_physical_accuracy(TObjChara *attacker, s32 collider, f32 accuracy) {
    f32 v;

    if (attacker == NULL) {
        return 0;
    }
    if (this->test_actor_flags(0x04000800) == 0) {
        v = (0.01f) * ((accuracy * (f32) ((TObjPlayer *)attacker)->get_ata()) - ((0.2f) * (f32) evp));
        if ((0.0f) < v && this->random_ratio() <= v) {
            bodies[collider].flags |= 0x04000000;
            hit_flags |= 1;
            return 1;
        }
        actorFlags |= 0x100;
    }
    return 0;
}
}

#pragma pop
void TObjPlayer::show_miss_for_collider(s32 collider) {
    this->show_miss_popup((const float*)((*(uaddr *)&this->bodies) + collider*0x2C + 0x1C));
}

void TObjChara::show_miss_popup(const float *pos) {
    if (this->test_actor_flags(0x02000000) == 0 && this->is_locally_controlled() == 0 && pos != NULL) {
        if (TObjPlayer::get_player_count() == 0 || this->entity_id >= 0x1000) {
            TOCtrlDubchik::create_font((saddr)pos, 0xFFFF0000, 0x14, miss_label_text);
        }
    }
}

void TObjChara::try_apply_damage(const Vec *pos, s32 damage) {
    if ((this->test_actor_flags(0x02000000) == 0) && (this->is_locally_controlled() == 0) && (pos != NULL) && ((s16) damage >= 0) && ((TObjPlayer::get_player_count() == 0) || ((u16) this->entity_id >= 0x1000U))) {
        create_damage_font__19TObjEneEpsilonGuardFllll((uaddr)pos, -1, 0x14, (s16) damage);
    }
}

void draw_hp_label(TObjChara *chara, Vec *pos, s32 delay, s16 value) {
    if ((chara->test_actor_flags(0x02000000) == 0) && (chara->is_locally_controlled() == 0) && (pos != NULL)) {
        create_font_small_task_default_color(pos, 0xFF00FF00, 0x14, delay, "HP", value);
    }
}

void show_tp_font(TObjChara *chara, Vec *pos, s32 delay, s16 value) {
    if ((chara->test_actor_flags(0x02000000) == 0) && (chara->is_locally_controlled() == 0) && (pos != NULL)) {
        create_font_small_task_default_color(pos, 0xFF00B2FF, 0x14, delay, "TP", value);
    }
}

void show_meseta_label(TObjChara *chara, Vec *pos, s32 delay, s16 value) {
    s32 size;
    if (chara->test_actor_flags(0x02000000) == 0 && pos != NULL) {
        size = 0x14;
        if (chara->is_locally_controlled() != 0) {
            size <<= 1;
        }
        create_font_small_task(pos, -0x100, size, delay, meseta_label_text, value, chara->get_entity_id());
    }
}

void display_exp_gain(TObjChara *chara, Vec *pos, s32 delay, s16 value) {
    if ((chara->test_actor_flags(0x02000000) == 0) && (chara->is_locally_controlled() == 0) && (pos != NULL)) {
        create_font_small_task(pos, 0xFFFF00FF, 0x14, delay, "EXP", value, chara->get_entity_id());
    }
}

#pragma push
#pragma fp_contract on
int TObjChara::calc_distance_accuracy_penalty(TObjChara *attacker, CollisionBody *body, const Vec *origin, float multiplier) {
    Vec delta;
    if (attacker && body && !(this->actorFlags & 0x04000000)) {
        float chance = 0.01f * (multiplier * (float)((TObjPlayer *)attacker)->get_ata() - 0.2f * (float)this->evp);
        VecCopy(&delta, &body->center);
        if (!attacker->obj_testFlag_2E4(0x20)) {
            if (origin) {
                subtract_vector(&delta, origin);
            } else {
                subtract_vector(&delta, &attacker->position);
            }
            const float squared = delta.x * delta.x + delta.z * delta.z;
            const float dist = newton_sqrtf(squared);
            float pen = (float)(dist * accuracy_distance_penalty_scale);
            pen *= 0.33333334f;
            chance -= pen;
        }
        if (0.0f < chance && this->random_ratio() <= chance) {
            body->flags |= 0x04000000;
            attach_mine_trap(attacker);
            this->hit_flags |= 2;
            return 1;
        }
        this->actorFlags |= 0x100;
        VecCopy(&delta, &body->center);
        this->show_miss_popup((const float *)&delta);
    }
    return 0;
}

#pragma pop
WeaponAttribute *TObjPlayer::get_attribute_entry(s32 i) {
    if (i < 3) {
        return &attack_attributes[i];
    }
    return 0;
}

void WeaponAttribute::copy(WeaponAttribute *src) {
    area = src->area;
    percent = src->percent;
}

void TObjPlayer::set_attribute_entry(s32 i, WeaponAttribute *attribute) {
    if (i < 3) {
        attack_attributes[i].copy(attribute);
    }
}

void TObjChara::trigger_switch_attack(const Vec *pos) {
    if (this->test_actor_flags(0x02000000) == 0) {
        switch (this->target_attribute_mask) {
        case 1:
            spawn_particle_effect_with_flags(pos, 0xF1, 0x40);
            return;
        case 2:
            spawn_particle_effect_with_flags(pos, 0xF2, 0x40);
            return;
        case 4:
            spawn_particle_effect_with_flags(pos, 0xE3, 0x40);
            return;
        case 8:
            spawn_particle_effect_with_flags(pos, 0x10D, 0x40);
            break;
        }
    }
}

void TObjPlayer::spawn_recovery_effect() {
    if (this->test_actor_flags(0x02000000) == 0) {
        create_timed_particle_emitter_with_flags(&body_center, 0x10A, 0, 0xA, 0x40);
    }
}

void TObjChara::apply_poison_status() {
    f32 evp_scale;

    if ((this->obj_testFlag_2E4(4) == 0) && ((u16) this->entity_id < 0x1000U) && (this->test_immunity_flags(1) == 0)) {
        this->spawn_poison_effect(0);
        if (this->get_status_effect_type(0) == 0x10) {
            f32 base_evp;
            evp_scale = -this->get_status_effect_amount(0);
            base_evp = (f32) this->get_base_evp();
            adjust_evp((s32) (base_evp * evp_scale));
        }
        this->set_status_effect_type(0, 0xF);
        this->set_status_effect_amount(0, (0.0f));
        this->set_status_effect_timer(0, 0x2D);
        actorFlags &= ~3;
        actorFlags |= 1;
    }
}

void TObjChara::apply_paralysis() {
    if ((this->obj_testFlag_2E4(4U) == 0) && (this->test_actor_flags(0x01000000U) == 0) && (this->test_immunity_flags(2) == 0)) {
        this->spawn_paralysis_feedback_effect(0);
        if (this->get_status_effect_type(0) == 0x10) {
            adjust_evp((s32) ((f32) this->get_base_evp() * -this->get_status_effect_amount(0)));
        }
        this->set_status_effect_type(0, 0x10);
        if ((u16) this->entity_id >= 0x1000U) {
            this->set_status_effect_amount(0, -0.15f);
            adjust_evp((s32) ((-0.15f) * (f32) this->get_base_evp()));
            this->set_status_effect_timer(0, 0xD2);
        } else {
            this->set_status_effect_amount(0, 0.0f);
            this->set_status_effect_timer(0, 0);
        }
        actorFlags &= ~3;
        actorFlags |= 2;
    }
}

void TObjChara::apply_slow_status() {
    if (((u16) this->entity_id <= 0x1000U) && (this->test_immunity_flags(8) == 0)) {
        this->spawn_slow_effect(0);
        switch (this->get_status_effect_type(1)) {
        case 2:
        case 3:
            adjust_evp((s32) ((f32) this->get_base_evp() * -this->get_status_effect_amount(1)));
            break;
        }
        this->set_status_effect_type(1, 0x11);
        this->set_status_effect_amount(1, (0.0f));
        this->set_status_effect_timer(1, 0xD2);
        actorFlags &= ~0x3C;
        actorFlags |= 8;
    }
}

void TObjChara::apply_confusion_status() {

    if ((this->obj_testFlag_2E4(0x10) == 0) && (this->test_immunity_flags(0x10) == 0)) {
        this->spawn_confusion_feedback_effect(0);
        switch (this->get_status_effect_type(1)) {
        case 2:
        case 3:
            adjust_evp((s32) ((f32) this->get_base_evp() * -this->get_status_effect_amount(1)));
            break;
        }
        this->set_status_effect_type(1, 0x12);
        this->set_status_effect_amount(1, (0.0f));
        this->set_status_effect_timer(1, 0x12C);
        actorFlags &= ~0x3C;
        actorFlags |= 0x10;
    }
}

void TObjChara::apply_movement_ailment(CollisionBody *body) {

    if ((this->test_actor_flags(0x8000U) == 0) && (this->test_actor_flags(0x01000000U) == 0) && (this->test_immunity_flags(0x20) == 0) && ((this->test_actor_flags(0x20U) == 0) || (this->get_status_effect_timer(1) <= 0))) {
        spawn_freeze_shell_effect(body, 1);
        switch (this->get_status_effect_type(1)) {
        case 2:
        case 3:
            adjust_evp((s32)((f32)this->get_base_evp() * -this->get_status_effect_amount(1)));
            break;
        }
        this->set_status_effect_type(1, 2);
        this->set_status_effect_amount(1, (f32) ((-0.3f)));
        this->set_status_effect_timer(1, 0x96);
        actorFlags &= ~0x3C;
        actorFlags |= 0x20;
        adjust_evp((s32) ((-0.3f) * (f32) this->get_base_evp()));
    }
}

void TObjChara::apply_shock_status() {
    s32 ok;
    f32 k;
    f32 v;

    ok = 0;
    if (this->get_entity_id() >= 0x1000 && this->get_entity_id() < 0x4000 &&
        this->obj_testFlag_2E4(4) != 0 && this->test_actor_flags(0x01000000) == 0 &&
        this->test_immunity_flags(4) == 0) {
        ok = 1;
    }
    if (this->get_entity_id() < 0x1000 && this->test_immunity_flags(4) == 0) {
        ok = 1;
    }
    if (ok != 0) {
        if (this->test_actor_flags(0x02000000) == 0) {
            this->play_shock_feedback(1);
        }
        switch (this->get_status_effect_type(1)) {
        case 2:
        case 3:
            k = -this->get_status_effect_amount(1);
            v = (f32)this->get_base_evp();
            v *= k;
            adjust_evp((s32)v);
            break;
        }
        this->set_status_effect_type(1, 3);
        if (this->get_entity_id() < 0x1000) {
            this->set_status_effect_amount(1, (0.0f));
        } else {
            this->set_status_effect_amount(1, (-0.15f));
        }
        this->set_status_effect_timer(1, 0x12C);
        this->actorFlags &= ~0x3C;
        this->actorFlags |= 4;
        if (this->entity_id >= 0x1000) {
            adjust_evp((s32)((-0.15f) * (f32)this->get_base_evp()));
        }
    }
}

void TObjChara::clear_harmful_statuses() {
    switch (this->get_status_effect_type(0)) {
    case 0x10:
        adjust_evp((s32)((f32)this->get_base_evp() * -this->get_status_effect_amount(0)));
        break;
    }
    switch (this->get_status_effect_type(1)) {
    case 2:
    case 3:
        adjust_evp((s32)((f32)this->get_base_evp() * -this->get_status_effect_amount(1)));
        break;
    }
    this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFC0);
    this->low_game_flags = this->actorFlags & 0x3F;
    this->status_effects[0].clear();
    this->status_effects[1].clear();
    switch (this->get_status_effect_type(2)) {
    case 0xB:
        this->adjust_atp((s32)((f32)this->get_base_atp() * -this->get_status_effect_amount(2)));
        this->adjust_atp_range((s32)((f32)this->get_base_atp_range() * -this->get_status_effect_amount(2)));
        this->status_effects[2].clear();
        break;
    }
    switch (this->get_status_effect_type(3)) {
    case 0xC:
        this->adjust_dfp((s32)((f32)this->get_base_dfp() * -this->get_status_effect_amount(3)));
        this->status_effects[3].clear();
        break;
    }
}

#pragma push
#pragma fp_contract on
void TObjChara::apply_attack_stat_status(StatStatusReceipt *receipt) {
    f32 new_amount;
    f32 scale;
    f32 status_effect_amount;

    if ((s32) receipt->kind != 0xB) {
        new_amount = (0.01f) * ((1.3f) * receipt->power + (1e+01f));
    } else {
        new_amount = (-0.01f) * ((1.3f) * receipt->power + (1e+01f));
    }
    status_effect_amount = this->get_status_effect_amount(2);
    scale = fabs_float(new_amount);
    if (!(fabs_float(status_effect_amount) > scale)) {
        scale = -this->get_status_effect_amount(2);
        {
            f32 v = this->get_base_atp();
            v *= scale;
            this->adjust_atp((s32) v);
        }
        scale = -this->get_status_effect_amount(2);
        {
            f32 v = this->get_base_atp_range();
            v *= scale;
            this->adjust_atp_range((s32) v);
        }
        this->set_status_effect_type(2, receipt->kind);
        this->set_status_effect_amount(2, new_amount);
        this->adjust_atp((s32) (new_amount * (f32) this->get_base_atp()));
        this->adjust_atp_range((s32) (new_amount * (f32) this->get_base_atp_range()));
        this->set_status_effect_timer(2, (s32) ((3e+01f) * ((1e+01f) * receipt->power + (4e+01f))));
        if (this->test_actor_flags(0x02000000) == 0) {
            new TActorLight(0.1f, (NJS_ARGB *)player_attack_stat_status_light_colors, (Vec *)status_light_desired, 0x2D, this, tl_07);
        }
    }
}

void TObjChara::apply_defense_stat_status(StatStatusReceipt *receipt) {
    f32 scale;
    f32 new_amount;
    f32 status_effect_amount;

    if (receipt->kind != 0xC) {
        new_amount = (0.01f) * ((1.3f) * receipt->power + (1e+01f));
    } else {
        new_amount = (-0.01f) * ((1.3f) * receipt->power + (1e+01f));
    }
    status_effect_amount = this->get_status_effect_amount(3);
    scale = fabs_float(new_amount);
    if (!(fabs_float(status_effect_amount) > scale)) {
        scale = -this->get_status_effect_amount(3);
        {
            f32 v = this->get_base_dfp();
            v *= scale;
            this->adjust_dfp((s32) v);
        }
        this->set_status_effect_type(3, receipt->kind);
        this->set_status_effect_amount(3, new_amount);
        this->adjust_dfp((s32) (new_amount * (f32) this->get_base_dfp()));
        this->set_status_effect_timer(3, (s32) ((3e+01f) * ((1e+01f) * receipt->power + (4e+01f))));
        if (this->test_actor_flags(0x02000000) == 0) {
            new TActorLight(0.1f, (NJS_ARGB *)player_defense_stat_status_light_colors, (Vec *)status_light_desired, 0x2D, this, tl_07);
        }
    }
}

#pragma pop
void TObjChara::cure_poison_ailment() {
    switch (this->get_status_effect_type(0)) {
    case 0xf:
        actorFlags &= ~3;
        low_game_flags = actorFlags & 0x3f;
        this->status_effects[0].clear();
        break;
    }
}

void TObjChara::cure_paralysis() {
    switch (this->get_status_effect_type(0)) {
    case 0x10:
        adjust_evp((s32) ((f32) this->get_base_evp() * -this->get_status_effect_amount(0)));
        actorFlags &= ~3;
        low_game_flags = actorFlags & 0x3f;
        this->status_effects[0].clear();
        break;
    }
}

void TObjChara::clear_all_status_effects() {
    switch (this->get_status_effect_type(0)) {
    case 0x10:
        this->adjust_evp((s32) ((f32) this->get_base_evp() * -this->get_status_effect_amount(0)));
        break;
    }
    switch (this->get_status_effect_type(1)) {
    case 2:
    case 3:
        this->adjust_evp((s32) ((f32) this->get_base_evp() * -this->get_status_effect_amount(1)));
        break;
    }
    this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFC0);
    low_game_flags = actorFlags & 0x3F;
    this->status_effects[0].clear();
    this->status_effects[1].clear();
    this->adjust_atp((s32) ((f32) this->get_base_atp() * -this->get_status_effect_amount(2)));
    this->adjust_atp_range((s32) ((f32) this->get_base_atp_range() * -this->get_status_effect_amount(2)));
    this->status_effects[2].clear();
    this->adjust_dfp((s32) ((f32) this->get_base_dfp() * -this->get_status_effect_amount(3)));
    this->status_effects[3].clear();
    clear_actor_flags((u32)0x4000U);
    this->status_effects[4].clear();
}

void TObjChara::apply_action_hold_status(f32 power) {
    set_status_effect_type(4, 0x14);
    set_status_effect_timer(4, (s32) power);
    set_actor_flags(0x4000U);
}

void TObjChara::run_idle_action() {  }

void TObjChara::run_move_action() {  }

void TObjChara::run_attack_action() {  }

void TObjChara::run_miss_reaction() {  }

void TObjChara::run_hit_reaction() {  }

void TObjChara::run_death_reaction() {  }

void TObjChara::reset_pose() { clear_actor_flags((uaddr)((void*)2048)); this->hp = this->hpmax; this->tp = this->tpmax; }

void TObjChara::get_anim_node_position(s32, Vec *) {  }

u32 TObjChara::vfunc_66(s32) { return 0; }

int TObjChara::deliver_attack_hits(f32) { return 0; }

#pragma push
#pragma fp_contract on
#pragma opt_loop_invariants off
f32 TObjChara::receive_physical_attack(TObjChara *attacker, f32 scale) {
    Vec hit;
    s32 immune;
    s32 i;
    s32 j;
    f32 scl0;
    f32 dmg;
    f32 elem;
    f32 total;
    f32 d;
    f32 crit;
    f32 lck;
    f32 boss;

    if (attacker == NULL || attacker->get_entity_id() == 0xFFFF || this->test_actor_flags(0x800) != 0) {
        return 0.0f;
    }
    if (this->test_actor_flags(0x04000000) != 0 && this->test_actor_flags(0x02000000) == 0) {
        this->try_apply_damage(&body_center, 0);
        return 0.0f;
    }
    attach_mine_trap(attacker);
    if (this->obj_isState2_324() != 0) {
        immune = 1;
    } else if (attacker->obj_isState2_324() != 0) {
        if (this->is_locally_controlled() != 0 && ((TObjPlayer *)attacker)->pk_state.is_enabled() != 0) {
            immune = 0;
        } else {
            immune = 1;
        }
    } else {
        immune = 0;
    }
    scl0 = this->random_ratio();
    dmg = 0.2f * (attacker->atp_range * scl0 + attacker->atp);
    elem = 0.2f * attacker->get_actor_attack_params_atp_min();
    for (j = 0; j < 3; j++) {
        switch (this->target_attribute_mask) {
        case 1:
            if (attacker->attack_attributes[j].area == 1) {
                elem *= 0.01f * attacker->attack_attributes[j].percent + 1.0f;
            }
            break;
        case 2:
            if (attacker->attack_attributes[j].area == 2) {
                elem *= 0.01f * attacker->attack_attributes[j].percent + 1.0f;
            }
            break;
        case 4:
            if (attacker->attack_attributes[j].area == 3) {
                elem *= 0.01f * attacker->attack_attributes[j].percent + 1.0f;
            }
            break;
        case 8:
            if (attacker->attack_attributes[j].area == 4) {
                elem *= 0.01f * attacker->attack_attributes[j].percent + 1.0f;
            }
            break;
        }
    }
    dmg += elem;
    dmg += attacker->element_attack[0] * (0.01f * (f32)(100 - element_resist[0]));
    dmg += attacker->element_attack[1] * (0.01f * (f32)(100 - element_resist[1]));
    dmg += attacker->element_attack[2] * (0.01f * (f32)(100 - element_resist[2]));
    dmg += attacker->element_attack[3] * (0.01f * (f32)(100 - element_resist[3]));
    dmg += attacker->element_attack[4] * (0.01f * (f32)(100 - element_resist[4]));
    total = 0.0f;
    for (i = 0; i < this->body_count; i++) {
        if (bodies[i].flags & 0x04000000) {
            bodies[i].flags &= ~0x04000000;
            VecCopy(&hit, &bodies[i].center);
            d = dmg - 0.2f * this->dfp - bodies[i].defense;
            if (d < 0.0f) {
                d = 0.0f;
                this->try_apply_damage(&hit, (s32)d);
            } else {
                d *= scale;
                if (this->test_actor_flags(0x02000000) == 0) {
                    boss = this->random_ratio();
                    if (attacker->get_entity_id() < 0x1000) {
                        crit = boss; crit *= (5e+02f);
                    } else {
                        crit = boss; crit *= (2e+02f);
                    }
                    lck = attacker->lck;
                    if (100.0f < lck) {
                        lck = 100.0f;
                    }
                    if (crit <= lck) {
                        TEffClitical::create(&hit);
                        play_sound_effect(0x4001A31F, &hit, 0, 0);
                        d *= (1.5f);
                    } else {
                        TEffHit::create(&hit);
                    }
                    this->trigger_switch_attack(&hit);
                    this->try_apply_damage(&hit, (s32)d);
                }
                total += d;
            }
        }
    }
    if (total <= 0.0f) {
        this->actorFlags |= 0x100;
        return 0.0f;
    }
    set_actor_flags(0x200);
    this->check_heavy_damage_flag(total);
    if (immune == 0) {
        subtract_actor_hp(this, total);
        if (this->hp <= 0) {
            this->actorFlags |= 0x800;
        }
    }
    if (immune == 0) {
        this->sync_enemy_state(0);
    }
    if (this->is_locally_controlled() != 0) {
        gain_photon_blast_charge(TObjPlayer::calc_photon_blast_charge(this, (s32)(20.0f * total)));
    }
    record_local_damage_if_enabled(this, attacker, (s32)total);
    empty_post_damage_hook(this, attacker);
    return total;
}

#pragma pop
#undef play_sound_effect
void TObjChara::apply_knockback_from_attacker(TObjBase *attacker, f32) {
    Vec diff;
    f32 scale;
    if (this->obj_isState2_324() != 1 && this->test_actor_flags(0x04000000) == 0) {
    VecCopy(&diff, &attacker->position);
    subtract_vector(&diff, &position);
    if ((diff.x * diff.x) + (diff.z * diff.z) < (1e-05f)) {
        velocity.x = (0.0f);
        this->velocity.z = (0.0f);
        return;
    }
    scale = 10.0f + (10.0f - this->stat_block->knockback_resist);
    if (scale < 0.0f) {
        scale = 0.0f;
    }
    normalize_vector_safe(&diff);
    velocity.x = -scale * diff.x;
    this->velocity.z = -scale * diff.z;
    }
}

#pragma push
#pragma fp_contract on
f32 TObjChara::receive_direct_attack(TObjBase *att, DirectAttackPayload payload, CollisionBody *coll, s32 tech, s32 anti_level) {
    StatStatusReceipt info;
    Vec pos;
    s32 immune;
    u16 aid;
    f32 mst;
    f32 dmg;
    f32 f;
    f32 heal;
    ((void (*)(StatStatusReceipt *, StatStatusReceipt *))obj_copyVec2_0)(&info, (StatStatusReceipt *)&payload);
    if (info.power < 0.0f) {
        info.power = 0.0f;
    }
    if (coll != NULL) {
        VecCopy(&pos, &coll->center);
    } else {
        VecCopy(&pos, &body_center);
    }
    if (att == NULL || att->get_entity_id() == 0xFFFF || (info.kind != 8 && test_actor_flags(0x800) != 0)) {
        return (0.0f);
    }
    if (info.kind != 6 && info.kind != 7 && info.kind != 8 && info.kind != 9 && info.kind != 10 && info.kind != 20 &&
        (test_actor_flags(0x04000000) != 0 || (coll != NULL && (coll->flags & 0x02000080)))) {
        if (obj_isState2_324() == 0) {
            try_apply_damage(&pos, 0);
        }
        return (0.0f);
    }
    attach_mine_trap(att);
    if (obj_isState2_324() != 0) {
        if ((u32)(info.kind - 6) <= 3 || info.kind == 10) {
            immune = 0;
        } else {
            immune = 1;
        }
    } else if (this->attacker_id < 0x1000 && get_main_phase() == 15) {
        if (((TObjChara *)att)->obj_isState2_324() != 0) {
            if (this->is_locally_controlled() != 0 || obj_isState3_324() != 0) {
                if ((u32)(info.kind - 6) <= 4 || ((TObjPlayer *)att)->pk_state.is_enabled() != 0) {
                    immune = 0;
                } else {
                    immune = 1;
                }
            } else {
                immune = 1;
            }
        } else {
            immune = 0;
        }
    } else {
        immune = 0;
    }
    if (this->attacker_id < 0x4000) {
        mst = ((TObjChara *)att)->stat_block->stats.mst;
        if (mst < 0.0f) {
            mst = 0.0f;
        }
    } else {
        mst = (0.0f);
    }
    aid = att->get_entity_id();
    if (aid < 12) {
        dmg = info.power + mst;
        if (tech != -1) {
            dmg *= (1.0f) + calc_technique_boost(tech, aid);
        }
    } else {
        dmg = (0.5f) * mst + info.power;
    }
    switch (info.kind) {
    case 0:
        if (test_actor_flags(0x10000000) == 0 || obj_isState2_324() == 0) {
            dmg *= (0.2f);
            if (immune == 0) {
                subtract_actor_hp(this, dmg);
                if (clamp_hp() <= 0) {
                    set_actor_flags(0x800);
                }
            }
            set_actor_flags(0x200);
            this->check_heavy_damage_flag(dmg);
            this->hit_flags |= 4;
            if (test_actor_flags(0x02000000) == 0) {
                TEffHit::create(&pos);
                trigger_switch_attack(&pos);
                try_apply_damage(&pos, (s32)dmg);
            }
        }
        break;
    case 1:
        if (test_actor_flags(0x10000000) == 0 || obj_isState2_324() == 0) {
            dmg *= (0.002f) * (f32)(100 - this->element_resist[0]);
            if (immune == 0) {
                subtract_actor_hp(this, dmg);
                if (clamp_hp() <= 0) {
                    set_actor_flags(0x800);
                }
            }
            set_actor_flags(0x200);
            this->check_heavy_damage_flag(dmg);
            this->hit_flags |= 4;
            if (test_actor_flags(0x02000000) == 0) {
                TEffHit::create(&pos);
                trigger_switch_attack(&pos);
                try_apply_damage(&pos, (s32)dmg);
            }
        }
        break;
    case 2:
        if (test_actor_flags(0x10000000) == 0 || obj_isState2_324() == 0) {
            dmg *= (0.002f) * (f32)(100 - this->element_resist[2]);
            if (immune == 0) {
                subtract_actor_hp(this, dmg);
                if (clamp_hp() <= 0) {
                    set_actor_flags(0x800);
                }
            }
            set_actor_flags(0x200);
            this->hit_flags |= 4;
            if (this->is_locally_controlled() != 0 || ((TObjPlayer *)att)->is_local_player() != 0) {
                f = info.power - (2.5e+02f);
                if (f < 0.0f) {
                    f = 0.0f;
                }
                if (((s32 (*)(TObjChara *, TObjChara *, TObjChara *, f32))calc_freeze_chance)(this, ((TObjChara *)att), this, (0.025f) * ((0.025f) * f + (5.0f))) != 0) {
                    this->apply_movement_ailment(coll);
                }
            }
            if (test_actor_flags(0x02000000) == 0) {
                TEffHit::create(&pos);
                trigger_switch_attack(&pos);
                try_apply_damage(&pos, (s32)dmg);
            }
        }
        break;
    case 3:
        if (test_actor_flags(0x10000000) == 0 || obj_isState2_324() == 0) {
            dmg *= (0.002f) * (f32)(100 - this->element_resist[1]);
            if (immune == 0) {
                subtract_actor_hp(this, dmg);
                if (clamp_hp() <= 0) {
                    set_actor_flags(0x800);
                }
            }
            set_actor_flags(0x200);
            this->check_heavy_damage_flag(dmg);
            this->hit_flags |= 4;
            if ((this->is_locally_controlled() != 0 || ((TObjPlayer *)att)->is_local_player() != 0) &&
                ((s32 (*)(TObjChara *, TObjChara *, TObjChara *, f32))calc_shock_chance)(this, ((TObjChara *)att), this, info.power) != 0) {
                this->apply_shock_status();
            }
            activate_switch_attacks(&pos);
            if (test_actor_flags(0x02000000) == 0) {
                try_apply_damage(&pos, (s32)dmg);
            }
        }
        break;
    case 4:
        if (test_actor_flags(0x10000000) == 0 || obj_isState2_324() == 0) {
            dmg *= (0.002f) * (f32)(100 - this->element_resist[4]);
            if (immune == 0) {
                subtract_actor_hp(this, dmg);
                if (clamp_hp() <= 0) {
                    set_actor_flags(0x800);
                }
            }
            set_actor_flags(0x200);
            this->check_heavy_damage_flag(dmg);
            this->hit_flags |= 4;
            if (test_actor_flags(0x02000000) == 0) {
                TEffHit::create(&pos);
                trigger_switch_attack(&pos);
                try_apply_damage(&pos, (s32)dmg);
            }
        }
        break;
    case 5:
        if (test_actor_flags(0x10000000) == 0 || obj_isState2_324() == 0) {
            if (is_boss_area() == 0 || (game_difficulty_selection == 3 && this->attacker_id >= 0x1000)) {
                if (test_actor_flags(0x02000000) == 0) {
                    TEffHit::create(&pos);
                }
                this->hit_flags |= 4;
                dmg = (0.01f) * (info.power - (f32)this->element_resist[3]);
                if (immune == 0 && this->random_ratio() < dmg) {
                    ((TObjPlayer *)this)->set_hp_clamped(0);
                    set_actor_flags(0xA00);
                }
            } else {
                dmg = (0.0f);
            }
        }
        break;
    case 6:
        heal = (0.5f) * mst + info.power;
        if (immune == 0) {
            add_actor_hp(this, heal);
            clamp_hp();
        }
        draw_hp_label(this, &pos, 0, heal);
        dmg = (0.0f);
        break;
    case 7:
        dmg = (0.0f);
        if (obj_isState3_324() != 0) {
            this->clear_harmful_statuses();
        } else {
            this->apply_anti_technique(anti_level);
        }
        break;
    case 9:
        dmg = (0.0f);
        if (test_actor_flags(0x02000000) == 0) {
            this->apply_switch_attack();
        }
        { StatStatusReceipt copy = info; apply_attack_stat_status(&copy); }
        if (this->entity_id <= 0x1000 && this->entity_id > 0x4000) {
            this->sync_enemy_state(info.kind);
        }
        break;
    case 10:
        dmg = (0.0f);
        if (test_actor_flags(0x02000000) == 0) {
            this->trigger_switch_attack();
        }
        { StatStatusReceipt copy = info; apply_defense_stat_status(&copy); }
        if (this->entity_id <= 0x1000 && this->entity_id > 0x4000) {
            this->sync_enemy_state(info.kind);
        }
        break;
    case 11:
        dmg = (0.0f);
        if (test_actor_flags(0x02000000) == 0) {
            this->enemy_spawn_jellen_effect();
        }
        { StatStatusReceipt copy = info; apply_attack_stat_status(&copy); }
        if (this->entity_id <= 0x1000 && this->entity_id > 0x4000) {
            this->sync_enemy_state(info.kind);
        }
        break;
    case 12:
        dmg = (0.0f);
        if (test_actor_flags(0x02000000) == 0) {
            this->enemy_spawn_zalure_effect();
        }
        { StatStatusReceipt copy = info; apply_defense_stat_status(&copy); }
        if (this->entity_id <= 0x1000 && this->entity_id > 0x4000) {
            this->sync_enemy_state(info.kind);
        }
        break;
    case 15:
        dmg = (0.0f);
        if (immune == 0) {
            this->apply_poison_status();
        }
        break;
    case 16:
        dmg = (0.0f);
        if (immune == 0) {
            this->apply_paralysis();
        }
        break;
    case 17:
        dmg = (0.0f);
        if (immune == 0) {
            this->apply_slow_status();
        }
        break;
    case 18:
        dmg = (0.0f);
        if (immune == 0) {
            this->apply_confusion_status();
        }
        break;
    case 19:
        if (test_actor_flags(0x10000000) == 0 || obj_isState2_324() == 0) {
            dmg *= (0.002f) * (f32)(100 - this->element_resist[2]);
            if (immune == 0) {
                subtract_actor_hp(this, dmg);
                if (clamp_hp() <= 0) {
                    this->actorFlags |= 0x800;
                }
            }
            this->actorFlags |= 0x200;
            this->check_heavy_damage_flag(dmg);
            this->hit_flags |= 4;
            if (test_actor_flags(0x02000000) == 0) {
                TEffHit::create(&pos);
                trigger_switch_attack(&pos);
                try_apply_damage(&pos, (s32)dmg);
            }
        }
        break;
    case 20:
        dmg = (0.0f);
        this->apply_action_hold_status(info.power);
        break;
    case 8:
        dmg = (0.0f);
        this->reset_pose();
        break;
    case 21:
        if (test_actor_flags(0x10000000) == 0 || obj_isState2_324() == 0) {
            dmg = info.power;
            if (immune == 0) {
                subtract_actor_hp(this, dmg);
                if (clamp_hp() <= 0) {
                    set_actor_flags(0x800);
                }
            }
            set_actor_flags(0x200);
            this->check_heavy_damage_flag(dmg);
            this->hit_flags |= 4;
            if (test_actor_flags(0x02000000) == 0) {
                TEffHit::create(&pos);
                trigger_switch_attack(&pos);
                try_apply_damage(&pos, (s32)dmg);
            }
        }
        break;
    default:
        dmg = (0.0f);
        break;
    }
    if (immune == 0) {
        this->sync_enemy_state(0);
    }
    if (this->is_locally_controlled() != 0) {
        gain_photon_blast_charge(TObjPlayer::calc_photon_blast_charge(this, (s32)((2e+01f) * dmg)));
    }
    record_local_damage_if_enabled(this, ((TObjChara *)att), (s32)dmg);
    empty_post_damage_hook(this, ((TObjChara *)att));
    return dmg;
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
f32 TObjChara::receive_weapon_special_attack(TObjChara *att, CollisionBody *coll) {
    DirectAttackPayload rec;
    Vec pos;
    s16 kind;
    s16 power;
    s32 blocked;
    s32 immune;
    f32 dmg;
    f32 mul;
    f32 cap;
    f32 amt;
    f32 chance;
    if (coll != NULL) {
        VecCopy(&pos, &coll->center);
    } else {
        VecCopy(&pos, &body_center);
    }
    if (att == NULL) {
        return (0.0f);
    }
    if (att->get_entity_id() == 0xFFFF) {
        return (0.0f);
    }
    kind = ((TObjPlayer *)att)->obj_getS16_116();
    power = ((s16 (*)(void *))obj_getS16_118)(att);
    blocked = 0;
    if (test_actor_flags(0x04000000) != 0) {
        blocked = 1;
    }
    if (coll != NULL && (coll->flags & 0x02000000)) {
        blocked = 1;
    }
    if (blocked != 0) {
        switch (kind) {
        case 0:
            break;
        case 1:
        case 2:
        case 5:
        case 6:
        case 7:
        case 9:
        case 10:
            try_apply_damage(&pos, 0);
            break;
        case 3:
        case 4:
        case 8:
        case 11:
        case 12:
        case 13:
            show_miss_popup(&pos.x);
            break;
        }
        if (coll != NULL) {
            coll->flags &= ~0x04000000;
        }
        return (0.0f);
    }
    attach_mine_trap(att);
    if (obj_isState2_324() != 0) {
        immune = 1;
    } else if (att->obj_isState2_324() != 0) {
        if (this->is_locally_controlled() != 0 && ((TObjPlayer *)att)->pk_state.is_enabled() != 0) {
            immune = 0;
        } else {
            immune = 1;
        }
    } else {
        immune = 0;
    }
    if (game_difficulty_selection == 3 && attacker_id < 0x1000 && att->obj_testFlag_2E4(4) != 0 &&
        kind != 11 && kind != 9 && kind != 10) {
        power += 30;
    }
    dmg = (0.0f);
    rec.kind = 0;
    rec.power = dmg;
    if (attacker_id < 0x1000) {
        TItem *item = TObjPlayer::get_equipped_weapon(att);
        if (item == NULL) {
            mul = (1.0f);
        } else {
            switch (item->get_item_group()) {
            case 2:
            case 3:
            case 4:
                mul = (0.5f);
                break;
            case 5:
            case 8:
            case 9:
                mul = (0.33f);
                break;
            default:
                mul = (1.0f);
                break;
            }
        }
    } else {
        mul = (1.0f);
    }
    switch (kind) {
    case 1:
        dmg = (0.01f) * (f32)(power * this->get_actor_hp());
        cap = (3e+01f) * (game_difficulty_selection + 1);
        if (cap < dmg) {
            dmg = cap;
        }
        dmg *= mul;
        if (dmg < (1.0f)) {
            dmg = (1.0f);
        }
        if (TObjPlayer::get_player_count() != 0) {
            if (this->is_locally_controlled() != 0 && att->obj_isState2_324() != 0) {
                att->send_update_entity_stat(attacker_id, 3, (s32)dmg);
                this->send_update_entity_stat(attacker_id, 0, (s32)dmg);
                receive_physical_attack(att, (0.6f));
            } else if (obj_isState2_324() == 0 || att->get_entity_id() >= 0x1000) {
                if (att->is_locally_controlled() != 0) {
                    att->send_update_entity_stat(attacker_id, 3, (s32)dmg);
                    draw_hp_label(this, &pos, 10, dmg);
                    subtract_actor_hp(this, dmg);
                } else if (att->obj_isState2_324() == 0) {
                    add_actor_hp(att, dmg);
                    dispatch_weapon_special_effect(att, this, &pos, 1);
                    subtract_actor_hp(this, dmg);
                }
                receive_physical_attack(att, (0.6f));
            }
        } else {
            if (att->is_locally_controlled() != 0) {
                att->send_update_entity_stat(attacker_id, 3, (s32)dmg);
                draw_hp_label(this, &pos, 10, dmg);
                subtract_actor_hp(this, dmg);
            } else if (att->obj_isState2_324() == 0) {
                add_actor_hp(att, dmg);
                dispatch_weapon_special_effect(att, this, &pos, 1);
                subtract_actor_hp(this, dmg);
            }
            receive_physical_attack(att, (0.6f));
        }
        if (this->clamp_hp() <= 0) {
            set_actor_flags(0xA00);
            empty_post_damage_hook(this, att);
        } else {
            set_actor_flags(0x200);
        }
        if (test_actor_flags(0x02000000) == 0) {
            TEffHit::create(&pos);
        }
        break;
    case 2:
        if (att->obj_testFlag_2E4(4) != 0) {
            dmg = (0.0f);
            if (coll != NULL) {
                coll->flags &= ~0x04000000;
            }
        } else {
            dmg = (0.01f) * (f32)(power * att->get_tpmax());
            cap = (25.0f) * (game_difficulty_selection + 1);
            if (cap < dmg) {
                dmg = cap;
            }
            dmg *= mul;
            if (dmg < (1.0f)) {
                dmg = (1.0f);
            }
            if (TObjPlayer::get_player_count() != 0) {
                if (this->is_locally_controlled() != 0 && att->obj_isState2_324() != 0) {
                    att->send_update_entity_stat(attacker_id, 4, (s32)dmg);
                    this->send_update_entity_stat(attacker_id, 1, (s32)dmg);
                    receive_physical_attack(att, (0.6f));
                } else if (obj_isState2_324() == 0 || att->get_entity_id() >= 0x1000) {
                    if (att->is_locally_controlled() != 0) {
                        att->send_update_entity_stat(attacker_id, 4, (s32)dmg);
                        show_tp_font(this, &pos, 10, dmg);
                        subtract_actor_tp((s32)dmg);
                    } else if (att->obj_isState2_324() == 0) {
                        add_actor_tp(att, dmg);
                        dispatch_weapon_special_effect(att, this, &pos, 1);
                        subtract_actor_tp((s32)dmg);
                    }
                    receive_physical_attack(att, (0.6f));
                }
            } else {
                if (att->is_locally_controlled() != 0) {
                    att->send_update_entity_stat(attacker_id, 4, (s32)dmg);
                    show_tp_font(this, &pos, 10, dmg);
                    subtract_actor_tp((s32)dmg);
                } else if (att->obj_isState2_324() == 0) {
                    add_actor_tp(att, dmg);
                    dispatch_weapon_special_effect(att, this, &pos, 1);
                    subtract_actor_tp((s32)dmg);
                }
                receive_physical_attack(att, (0.6f));
            }
        }
        set_actor_flags(0x200);
        if (test_actor_flags(0x02000000) == 0) {
            TEffHit::create(&pos);
        }
        break;
    case 3:
        if (is_boss_area() != 0) {
            if (coll != NULL) {
                coll->flags &= ~0x04000000;
            }
        } else if (entity_id < 0x1000) {
            dmg = (0.0f);
            show_miss_popup(&pos.x);
            if (coll != NULL) {
                coll->flags &= ~0x04000000;
            }
        } else {
            dmg = (0.01f) * (f32)(power * this->obj_getPtr2B0_1C());
            cap = (2e+01f) * (game_difficulty_selection + 1);
            if (cap < dmg) {
                dmg = cap;
            }
            dmg *= mul;
            if (dmg < (1.0f)) {
                dmg = (1.0f);
            }
            if (immune == 0) {
                if (this->is_locally_controlled() != 0) {
                    consume_timer_field((s32)dmg);
                }
                att->add_actor_exp((s32)dmg);
            }
            set_actor_flags(0x200);
            dispatch_weapon_special_effect(att, this, &pos, 1);
            if (test_actor_flags(0x02000000) == 0) {
                TEffHit::create(&pos);
                display_exp_gain(this, &pos, 10, dmg);
            }
        }
        receive_physical_attack(att, (0.6f));
        break;
    case 4: {
        f32 cost = (2e+02f);
        if (test_actor_flags(0x02000000) == 0) {
            dispatch_weapon_special_effect(att, this, &pos, 1);
        }
        if (cost <= (f32)att->get_actor_meseta()) {
            if (TObjPlayer::get_player_count() != 0) {
                if (this->is_locally_controlled() != 0 && att->obj_isState2_324() != 0) {
                    att->send_update_entity_stat(attacker_id, 2, (s32)cost);
                    receive_physical_attack(att, (3.0f));
                } else if (obj_isState2_324() == 0 || att->get_entity_id() >= 0x1000) {
                    att->try_spend_actor_meseta((s32)cost);
                    show_meseta_label(att, &att->body_center, 0, -cost);
                    receive_physical_attack(att, (3.0f));
                }
            } else {
                if (immune == 0) {
                    att->try_spend_actor_meseta((s32)cost);
                    show_meseta_label(att, &att->body_center, 0, -cost);
                }
                receive_physical_attack(att, (3.0f));
            }
        } else {
            actorFlags |= 0x100;
            show_miss_popup(&pos.x);
            if (coll != NULL) {
                coll->flags &= ~0x04000000;
            }
        }
        dmg = (0.0f);
        break;
    }
    case 5:
        if (test_actor_flags(0x02000000) == 0) {
            dispatch_weapon_special_effect(att, this, &pos, 1);
        }
        amt = (0.2f) * (f32)att->get_actor_tp();
        if ((1e+01f) <= (f32)att->get_actor_tp()) {
            if (TObjPlayer::get_player_count() != 0) {
                if (this->is_locally_controlled() != 0 && att->obj_isState2_324() != 0) {
                    att->send_update_entity_stat(attacker_id, 1, (s32)amt);
                    receive_physical_attack(att, (3.0f));
                } else if (obj_isState2_324() == 0 || att->get_entity_id() >= 0x1000) {
                    att->subtract_actor_tp((s32)amt);
                    receive_physical_attack(att, (3.0f));
                }
            } else {
                att->subtract_actor_tp((s32)amt);
                receive_physical_attack(att, (3.0f));
            }
        } else {
            actorFlags |= 0x100;
            show_miss_popup(&pos.x);
            if (coll != NULL) {
                coll->flags &= ~0x04000000;
            }
        }
        dmg = (0.0f);
        break;
    case 6:
        if (test_actor_flags(0x02000000) == 0) {
            dispatch_weapon_special_effect(att, this, &pos, 1);
        }
        amt = (0.25f) * (f32)att->get_actor_hp();
        if ((1.0f) < (f32)att->get_actor_hp()) {
            if (TObjPlayer::get_player_count() != 0) {
                if (this->is_locally_controlled() != 0 && att->obj_isState2_324() != 0) {
                    att->send_update_entity_stat(attacker_id, 0, (s32)amt);
                    receive_physical_attack(att, (3.0f));
                } else if (obj_isState2_324() == 0 || att->get_entity_id() >= 0x1000) {
                    subtract_actor_hp(att, amt);
                    receive_physical_attack(att, (3.0f));
                }
            } else {
                att->damage_hp((s32)amt);
                if (att->is_locally_controlled() != 0) {
                    u16 id = att->get_entity_id();
                    send_6x2F_change_player_hp(id, id, att->get_actor_hp());
                }
                receive_physical_attack(att, (3.0f));
            }
        } else {
            actorFlags |= 0x100;
            show_miss_popup(&pos.x);
            if (coll != NULL) {
                coll->flags &= ~0x04000000;
            }
        }
        dmg = (0.0f);
        break;
    case 7:
        chance = mul * ((0.01f) * (f32)(power - stat_block->esp));
        if (chance < (0.0f)) {
            chance = (0.0f);
        }
        if (((s32 (*)(void *, void *, void *, f32))calc_freeze_chance)(this, att, this, chance) != 0) {
            if (test_actor_flags(0x02000000) == 0) {
                TEffHit::create(&pos);
                dispatch_weapon_special_effect(att, this, &pos, 1);
            }
            if (immune == 0) {
                apply_movement_ailment(0);
                receive_physical_attack(att, (0.6f));
            }
        } else {
            show_miss_popup(&pos.x);
            if (coll != NULL) {
                coll->flags &= ~0x04000000;
            }
        }
        dmg = (0.0f);
        break;
    case 8:
        if (random_ratio() < mul * ((0.01f) * (f32)(power - stat_block->esp))) {
            if (test_actor_flags(0x02000000) == 0) {
                TEffHit::create(&pos);
                dispatch_weapon_special_effect(att, this, &pos, 1);
            }
            if (immune == 0) {
                if (entity_id >= 0x1000) {
                    apply_paralysis();
                }
                receive_physical_attack(att, (0.6f));
            }
        } else {
            show_miss_popup(&pos.x);
            if (coll != NULL) {
                coll->flags &= ~0x04000000;
            }
        }
        dmg = (0.0f);
        break;
    case 9:
        rec.kind = 1;
        rec.power = (5.0f) *
                    ((2e+01f) * ((1.0f) + (f32)power) +
                     (f32)att->get_actor_level_index() / ((5.0f) - (f32)power));
        dmg = rec.power * ((0.002f) * (f32)(100 - element_resist[0]));
        if (immune == 0) {
            subtract_actor_hp(this, dmg);
            if (this->clamp_hp() <= 0) {
                set_actor_flags(0x800);
                empty_post_damage_hook(this, att);
            }
        }
        set_actor_flags(0x200);
        this->check_heavy_damage_flag(dmg);
        hit_flags |= 4;
        if (test_actor_flags(0x02000000) == 0) {
            TEffHit::create(&pos);
            this->trigger_switch_attack(&pos);
            try_apply_damage(&pos, (s32)dmg);
            dispatch_weapon_special_effect(att, this, &pos, 1);
        }
        break;
    case 10:
        rec.kind = 3;
        rec.power = (5.0f) *
                    ((2e+01f) * ((1.0f) + (f32)power) +
                     (f32)att->get_actor_level_index() / ((5.0f) - (f32)power));
        dmg = rec.power * ((0.002f) * (f32)(100 - element_resist[1]));
        if (immune == 0) {
            subtract_actor_hp(this, dmg);
            if (this->clamp_hp() <= 0) {
                set_actor_flags(0x800);
                empty_post_damage_hook(this, att);
            }
        }
        set_actor_flags(0x200);
        this->check_heavy_damage_flag(dmg);
        hit_flags |= 4;
        if ((this->is_locally_controlled() != 0 || ((TObjPlayer *)att)->is_local_player() != 0) &&
            ((s32 (*)(void *, void *, void *, f32))calc_shock_chance)(this, att, this, dmg) != 0) {
            apply_shock_status();
        }
        if (test_actor_flags(0x02000000) == 0) {
            dispatch_weapon_special_effect(att, this, &pos, 1);
            activate_switch_attacks(&pos);
            try_apply_damage(&pos, (s32)dmg);
        }
        break;
    case 11:
        mul *= (0.01f) * (f32)(power - element_resist[3]);
        if (entity_id < 0x1000) {
            mul -= (0.5f);
        }
        if (random_ratio() < mul && is_boss_area() == 0) {
            if (test_actor_flags(0x02000000) == 0) {
                dispatch_weapon_special_effect(att, this, &pos, 1);
            }
            if (immune == 0) {
                this->get_actor_hp();
                ((TObjPlayer *)this)->set_hp_clamped(0);
                set_actor_flags(0xA00);
                empty_post_damage_hook(this, att);
            }
        } else {
            show_miss_popup(&pos.x);
            if (coll != NULL) {
                coll->flags &= ~0x04000000;
            }
        }
        dmg = (0.0f);
        break;
    case 12:
        if (random_ratio() < mul * ((0.01f) * (f32)(power - stat_block->esp))) {
            rec.kind = 18;
            rec.power = (0.0f);
            receive_direct_attack(att, rec, coll, -1, -1);
            if (test_actor_flags(0x02000000) == 0) {
                dispatch_weapon_special_effect(att, this, &pos, 1);
            }
        }
        receive_physical_attack(att, (0.6f));
        dmg = (0.0f);
        break;
    case 13:
        if (is_boss_area() != 0) {
            dmg = (0.0f);
            show_miss_popup(&pos.x);
            if (coll != NULL) {
                coll->flags &= ~0x04000000;
            }
        } else if (entity_id < 0x1000) {
            dmg = (0.0f);
            show_miss_popup(&pos.x);
            if (coll != NULL) {
                coll->flags &= ~0x04000000;
            }
        } else if (random_ratio() < (0.5f)) {
            dmg = mul * (((1.0f) - (0.01f) * (f32)power) *
                         (f32)this->get_actor_hp());
            if (dmg < (1.0f)) {
                dmg = (1.0f);
            }
            if (immune == 0) {
                subtract_actor_hp(this, dmg);
                if (this->clamp_hp() <= 0) {
                    set_actor_flags(0x800);
                    empty_post_damage_hook(this, att);
                }
            }
            set_actor_flags(0x200);
            if (test_actor_flags(0x02000000) == 0) {
                dispatch_weapon_special_effect(att, this, &pos, 1);
            }
        } else {
            dmg = (0.0f);
            show_miss_popup(&pos.x);
            if (coll != NULL) {
                coll->flags &= ~0x04000000;
            }
        }
        break;
    default:
        dmg = (0.0f);
        break;
    }
    if (immune == 0) {
        sync_enemy_state(0);
    }
    if (this->is_locally_controlled() != 0) {
        gain_photon_blast_charge(TObjPlayer::calc_photon_blast_charge(this, (s32)((2e+01f) * dmg)));
    }
    record_local_damage_if_enabled(this, att, (s32)dmg);
    return dmg;
}

#pragma pop
#pragma pop
void apply_actor_gravity(TObjEnemy *enemy, s32 *ground_position, f32 hover_height) {
    Vec position;
    f32 y;
    s32 grounded;
    VecCopy(&position, &enemy->position);
    grounded = project_actor_to_ground(enemy, &position, &enemy->ground_normal);
    if (ground_position != NULL) {
        VecCopy((Vec *)ground_position, &position);
    }
    if (grounded != 0) {
        enemy->velocity.y += (-0.10888889f);
        enemy->position.y += enemy->velocity.y;
        y = position.y + hover_height;
        position.y = y;
        if (enemy->position.y <= y) {
            enemy->position.y = y;
            enemy->velocity.y = 0.0f;
            enemy->actorFlags = (s32) (enemy->actorFlags | 0x800000);
            return;
        }
        enemy->actorFlags = (s32) (enemy->actorFlags & 0xFF7FFFFF);
        return;
    }
    enemy->actorFlags = (s32) (enemy->actorFlags & 0xFF7FFFFF);
}

s32 TObjChara::is_actor_cadence_frame(s32 x) {
    s32 g = actor_frame_tick % x;
    if ((this->entity_id % x) == g) {
        return 1;
    }
    return 0;
}
extern "C" {
u16 find_nearest_visible_player(TObjChara *searcher, Vec *direction, f32 range) {
    f32 best = range * range;
    u16 result = 0xFFFF;
    Vec diff = nearest_player_zero_vec;
    f32 dist;
    TObjPlayer *player;
    s32 i;
    for (i = 0; i < registered_player_count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player != NULL && player->entity_id < 0x1000 && !(player->actorFlags & 0x02000800)) {
            if (player->get_floor() == get_current_floor()) {
                VecCopy(&diff, &player->body_center);
                subtract_vector(&diff, &searcher->body_center);
                dist = (diff.x * diff.x) + (diff.z * diff.z);
                if (dist < best && check_path_obstructed(searcher, &player->body_center) == 0) {
                    best = dist;
                    result = player->entity_id;
                    if (direction != NULL) {
                        VecCopy(direction, &diff);
                    }
                }
            }
        }
    }
    return result;
}

}
u16 find_nearest_hittable_enemy(TObjBase *searcher, Vec *direction, f32 range) {
    Vec pos;
    f32 best;
    f32 dist;
    u16 result;
    s32 i;
    TObjCollidable *p;
    best = range * range;
    result = 0xFFFF;
    for (i = registered_player_count; i < registered_player_count + registered_enemy_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p == NULL) {
            break;
        }
        if (obj_is_hit_receivable(p) != 0) {
            u16 id = p->get_entity_id();
            if (id >= 0x1000 && id < 0x4000 && !(p->actorFlags & 0x02000800)) {
                dist = calc_xz_distance_sq(searcher, p, &pos);
                if (dist < best) {
                    best = dist;
                    result = p->entity_id;
                    if (direction != NULL) {
                        VecCopy(direction, &pos);
                    }
                }
            }
        }
    }
    return result;
}

s32 TObjChara::damage_hp(s32 amount) {
    if (obj_isState2_324() != 0) {
        return 0;
    }
    return ((s32 (*)(TObjChara *, s32))subtract_actor_hp)(this, amount);
}

s32 subtract_actor_hp(TObjChara *actor, s16 amount) {
    if (amount < 0) {
        return 0;
    }
    actor->hp = static_cast<s16>(actor->hp - amount);
    if (actor->hp < 0) {
        actor->hp = 0;
        return 0;
    }
    return 1;
}
#pragma push
#pragma scheduling off
s32 add_actor_hp(TObjChara *actor, s16 amount) {
    if (amount < 0) {
        return 0;
    }
    actor->hp = static_cast<s16>(actor->hp + amount);
    if (actor->hp > actor->hpmax) {
        actor->hp = actor->hpmax;
        return 0;
    }
    return 1;
}
#pragma pop
void TObjPlayer::set_hp_clamped(s16 value) {
    this->hp = value;
    clamp_hp_value(&this->hp);
}

s32 TObjPlayer::clamp_hp_value(s16 *value) {
    s16 hpmax;
    s16 current;
    current = *value;
    if (current < 0) {
        *value = 0;
        return 0;
    }
    hpmax = this->hpmax;
    if (current > hpmax) {
        *value = hpmax;
        return 0;
    }
    return 1;
}

s32 add_actor_hp_bonus(TObjChara *actor, s32 amount) {
    actor->hp_bonus = static_cast<s16>(static_cast<u32>(actor->hp_bonus) + static_cast<u32>(amount));
    if (actor->hp_bonus < 0) {
        actor->hp_bonus = 0;
        return 0;
    }
    return 1;
}

int TObjPlayer::get_hp_material_points() {
    int raw_bonus;
    s16 bonus;
    raw_bonus = this->hp_bonus;
    bonus = raw_bonus;
    if (bonus < 0) {
        return 0U;
    }
    if (bonus <= 0xFA) {
        return (u8) bonus;
    }
    return 0xFAU;
}

s32 TObjChara::check_can_act(s32 dmg) {
    if (obj_isState2_324() != 0) {
        return 0;
    }
    return subtract_actor_tp(dmg);
}

s32 TObjChara::subtract_actor_tp(s32 amount) {
    tp = static_cast<s16>(static_cast<u32>(tp) - static_cast<u32>(amount));
    if (tp < 0) {
        tp = 0;
        return 0;
    }
    return 1;
}

s32 add_actor_tp(TObjChara *actor, s16 amount) {
    actor->tp += amount;
    if (actor->tp > actor->tpmax) {
        actor->tp = actor->tpmax;
        return 0;
    }
    return 1;
}

s32 add_actor_tp_bonus(TObjChara *actor, s32 amount) {
    actor->tp_bonus = static_cast<s16>(static_cast<u32>(actor->tp_bonus) + static_cast<u32>(amount));
    if (actor->tp_bonus < 0) {
        actor->tp_bonus = 0;
        return 0;
    }
    return 1;
}

int TObjPlayer::get_tp_materials_clamped() {
    int raw_bonus;
    s16 bonus;
    raw_bonus = this->tp_bonus;
    bonus = raw_bonus;
    if (bonus < 0) {
        return 0U;
    }
    if (bonus <= 0xFA) {
        return (u8) bonus;
    }
    return 0xFAU;
}

s32 TObjChara::add_actor_exp(s32 amount) {
    player_stats *stats;
    int max_exp;
    player_stats *first_stats;
    first_stats = this->stat_block;
    first_stats->exp = first_stats->exp + amount;
    stats = this->stat_block;
    max_exp = 99999999;
    if (max_exp < (s32)stats->exp) {
        stats->exp = max_exp;
        return 0;
    }
    return 1;
}

s32 TObjChara::consume_timer_field(s32 amount) {
    this->stat_block->exp -= amount;
    if (this->stat_block->exp < 0) {
        this->stat_block->exp = 0;
        return 0;
    }
    return 1;
}

s32 TObjPlayer::add_capped_counter_999(s32 amount) {
    this->kill_count = (s16) (this->kill_count + amount);
    if (this->kill_count > 999) {
        this->kill_count = 999;
        return 0;
    }
    return 1;
}

s32 TObjChara::get_actor_level_index() { return this->stat_block->level; }

s32 TObjPlayer::add_meseta(s32 amount) {
  s32 limit = 999999;
  int maximum;
  this->stat_block->meseta += amount;
  maximum = limit;
  if (maximum < (s32)this->stat_block->meseta)
  {
    this->stat_block->meseta = maximum;
    return 0;
  }
  return 1;
}

s32 TObjChara::try_spend_actor_meseta(s32 amount) {
    player_stats *stats = this->stat_block;
    s32 held = stats->meseta;
    if (held < amount) {
        return 0;
    }
    stats->meseta = held - amount;
    return 1;
}

void TObjEnemy::draw_ground_shadow(const Vec *scale, s32 forceDraw) {
    s32 rotationX;
    s32 rotationZ;

    (void)&subtractive_rng_ratio_divisor;
    push_matrix();
    direction_to_rotation_xz((u8 *)&ground_normal, &rotationX, &rotationZ);
    translate_matrix(0, position.x, 0.3f + position.y, position.z);
    rotate_matrix_z(0, rotationZ);
    rotate_matrix_x(0, rotationX);
    rotate_matrix_y(0, rotation_y);
    rotate_matrix_x(0, -0x4000);
    if (scale != NULL) {
        scale_matrix(0, scale->x, scale->z, 1.0f);
    }
    draw_blob_shadow(forceDraw);
    pop_matrix();
}

f32 TObjChara::random_ratio() {
    if (get_main_phase() == 0xE) {
        return (3.0517578e-05f) * (f32) rand();
    }
    return rng.next_ratio();
}

void TObjChara::refresh_target() {  }

void TObjChara::attach_mine_trap(TObjBase *attacker) {
    if (attacker != NULL) {
        record_attack_source(attacker->get_entity_id());
    }
}

void TObjChara::record_attack_source(u16 id) {
    if (id != 0xFFFF) {
        attacker_id = id;
        if (attacker_id < 0x1000 && is_entity_locally_controlled(attacker_id) != 0) {
            if (is_split_screen() == 0) {
                local_attacker_id = attacker_id;
            } else {
                add_id_to_slots(id);
            }
        }
    }
}

u16 TObjChara::get_local_attacker_id() { return this->local_attacker_id; }

void TObjChara::assign_slots_from_list(TObjChara *source) {
    s32 i;

    if (source != NULL) {
        if (is_split_screen() != 0) {
            i = 0;
            do {
                add_id_to_slots(source->get_attack_credit_slot(i));
                i += 1;
            } while (i != 4);
            return;
        }
        if (local_attacker_id == 0xFFFF) {
            local_attacker_id = source->get_local_attacker_id();
        }
    }
}

void TObjChara::gain_photon_blast_charge(f32) {  }

void TObjChara::spend_photon_blast_charge(f32) {  }

void TObjChara::gain_photon_blast_chain_charge(f32) {  }

void TObjChara::send_status_effect_add(StatStatusReceipt) {  }

#pragma push
#pragma opt_pointer_analysis on
void record_local_damage_if_enabled(TObjChara *mine_trap, void *att, saddr damage) {
  if ((((lobby_rule_settings.get_rules_active() == 1) && (mine_trap->is_locally_controlled() != 0)) && (damage > 0)) && (att != NULL))
  {
    record_damage_stats(mine_trap, att, (void *) damage);
  }
}

#pragma pop
void empty_post_damage_hook(void *defender, void *attacker) {  }

void TObjChara::send_update_entity_stat(u16 target, s32 which, s32 amount) {
    G_UpdateEntityStat_6x9A pkt;
    pkt.init();
    pkt.header.client_id = entity_id;
    pkt.entity_index = target;
    pkt.what = which;
    pkt.amount = amount;
    pkt.send();
}

void handle_6x9A_update_entity_stat(G_UpdateEntityStat_6x9A *command) {
    s16 v;
    TObjPlayer *player;
    s32 amount;
    if (command == NULL) {
        return;
    }
    command->bswap();
    if (command->header.client_id >= 0x1000U) {
        return;
    }
    player = get_player_by_client_id(command->header.client_id);
    if (player == NULL) {
        return;
    }
    amount = command->amount;
    switch (command->what) {
    case 0: {
        v = amount;
        subtract_actor_hp(player, v);
        if (is_entity_locally_controlled(command->entity_index) != 0) {
            draw_hp_label(player, &player->body_center, 0xA, v);
        } else {
            draw_hp_label(player, &player->body_center, 0xA, -amount);
        }
        break;
    }
    case 1: {
        v = amount;
        player->subtract_actor_tp(v);
        if (is_entity_locally_controlled(command->entity_index) != 0) {
            show_tp_font(player, &player->body_center, 0xA, v);
        } else {
            show_tp_font(player, &player->body_center, 0xA, -amount);
        }
        break;
    }
    case 2:
        player->try_spend_actor_meseta(amount);
        show_meseta_label(player, &player->body_center, 0xA, -amount);
        break;
    case 3: {
        v = amount;
        add_actor_hp(player, v);
        draw_hp_label(player, &player->body_center, 0xA, v);
        player->spawn_recovery_effect();
        break;
    }
    case 4: {
        v = amount;
        add_actor_tp(player, v);
        show_tp_font(player, &player->body_center, 0xA, v);
        player->spawn_recovery_effect();
        break;
    }
    }
}

s32 is_entity_locally_controlled(u16 id) {
    TObjCollidable *p;
    if (id == 0xFFFF || id >= 0x1000) {
        return 0;
    }
    p = find_entity_by_id(id);
    if (p == 0) {
        return 0;
    }
    return static_cast<TObjChara *>(p)->is_locally_controlled();
}

void TObjChara::apply_switch_attack() {
    TParticleCtrl *particle_effect_with_flags;

    particle_effect_with_flags = spawn_particle_effect_with_flags(&this->body_center, 0x1FD, 0x50);
    if (particle_effect_with_flags != 0) {
        particle_effect_with_flags->set_owner_id(((TObjBase *)this)->get_entity_id());
    }
}

void TObjChara::enemy_spawn_jellen_effect() {
    Angle3 rotation;
    TParticleCtrl *oneshot_particle_emitter;
    rotation.y = 0;
    rotation.x = 0;
    rotation.z = -0x8000;
    oneshot_particle_emitter = create_oneshot_particle_emitter(&this->body_center, &rotation, 0x1FD, 0x50);
    if (oneshot_particle_emitter != 0) {
        oneshot_particle_emitter->set_owner_id(((TObjBase *)this)->get_entity_id());
    }
}

void TObjChara::trigger_switch_attack() {
    TParticleCtrl *particle_effect_with_flags;

    particle_effect_with_flags = spawn_particle_effect_with_flags(&this->body_center, 0x1FE, 0x50);
    if (particle_effect_with_flags != 0) {
        particle_effect_with_flags->set_owner_id(((TObjBase *)this)->get_entity_id());
    }
}

void TObjChara::enemy_spawn_zalure_effect() {
    Angle3 rotation;
    TParticleCtrl *oneshot_particle_emitter;
    rotation.y = 0;
    rotation.x = 0;
    rotation.z = -0x8000;
    oneshot_particle_emitter = create_oneshot_particle_emitter(&this->body_center, &rotation, 0x1FE, 0x50);
    if (oneshot_particle_emitter != 0) {
        oneshot_particle_emitter->set_owner_id(((TObjBase *)this)->get_entity_id());
    }
}

void TObjChara::recalc_stats() {}

s32 TObjChara::sync_enemy_state(s32) { return 0; }

void TObjPlayer::clear_s16_arrays(TObjChara *p) {
    for (s32 i = 0; i < 4; i++) {
        p->clear_attack_credit_slot(i);
    }
}

void TObjChara::add_id_to_slots(u16 id) {
    s32 i;

    i = 0;
    do {
        if (id == get_attack_credit_slot(i)) {
            return;
        }
        if (get_attack_credit_slot(i) == 0xFFFF) {
            set_attack_credit_slot(i, id);
            return;
        }
        i++;
    } while (i < 4);
}

void TObjChara::apply_anti_technique(s32 level) {
    if (level >= 0) {
        switch (this->get_status_effect_type(0)) {
        case 0xF:
            this->actorFlags &= ~3;
            this->status_effects[0].clear();
        }
    }
    if (level >= 1) {
        switch (this->get_status_effect_type(1)) {
        case 3:
            adjust_evp((int)((f32)this->get_base_evp() * -this->get_status_effect_amount(1)));
            this->actorFlags &= ~0x3C;
            this->status_effects[1].clear();
        }
    }
    if (level >= 2) {
        switch (this->get_status_effect_type(0)) {
        case 0x10:
            adjust_evp((int)((f32)this->get_base_evp() * -this->get_status_effect_amount(0)));
            this->actorFlags &= ~3;
            this->status_effects[0].clear();
        }
    }
    if (level >= 3) {
        switch (this->get_status_effect_type(1)) {
        case 0x12:
            this->actorFlags &= ~0x3C;
            this->status_effects[1].clear();
        }
    }
    if (level >= 4) {
        switch (this->get_status_effect_type(1)) {
        case 0x11:
            this->actorFlags &= ~0x3C;
            this->status_effects[1].clear();
        }
    }
    if (level >= 5) {
        switch (this->get_status_effect_type(2)) {
        case 0xB:
            this->adjust_atp((int)((f32)this->get_base_atp() * -this->get_status_effect_amount(2)));
            this->adjust_atp_range((int)((f32)this->get_base_atp_range() * -this->get_status_effect_amount(2)));
            this->status_effects[2].clear();
        }
        switch (this->get_status_effect_type(3)) {
        case 0xC:
            this->adjust_dfp((int)((f32)this->get_base_dfp() * -this->get_status_effect_amount(3)));
            this->status_effects[3].clear();
        }
    }
    if (level >= 6) {
        switch (this->get_status_effect_type(1)) {
        case 2:
            adjust_evp((int)((f32)this->get_base_evp() * -this->get_status_effect_amount(1)));
            this->actorFlags &= ~0x3C;
            this->status_effects[1].clear();
        }
    }
    low_game_flags = actorFlags & 0x3F;
    clear_actor_flags(0x4000);
    this->status_effects[4].clear();
}

s16 TObjChara::clamp_hp() {
    s16 max_hp;
    s16 hp;

    hp = (this->hp);
    if (hp < 0) {
        (this->hp) = 0;
    } else {
        max_hp = (this->hpmax);
        if (max_hp < hp) {
            (this->hp) = max_hp;
        }
    }
    return (this->hp);
}

s16 TObjPlayer::clamp_tp() {
    s16 max_tp;
    s16 current;

    current = this->tp;
    if (current < 0) {
        this->tp = 0;
    } else {
        max_tp = this->tpmax;
        if (max_tp < current) {
            this->tp = max_tp;
        }
    }
    return this->tp;
}

void TObjPlayer::apply_velocity() {
    this->position.x = (f32) (this->position.x + this->velocity.x);
    this->position.y = (f32) (this->position.y + this->velocity.y);
    this->position.z = (f32) (this->position.z + this->velocity.z);
}

void TObjChara::clear_velocity() {
    velocity.z = 0.0f;
    velocity.y = 0.0f;
    velocity.x = 0.0f;
}

s32 calc_shock_chance(TObjPlayer *actor, TObjPlayer *attacker, TObjPlayer *target) {
    f32 chance;

    if ((attacker->get_entity_id() >= 0x1000U) && (target->get_entity_id() < 0x1000U)) {
        chance = 0.75f - ((f32) (actor)->get_eth() / 100.0f);
        if (chance < 0.0f) {
            chance = 0.0f;
        }
    } else if ((s32) game_difficulty_selection == 3) {
        chance = (0.025f);
    } else {
        chance = (0.06666667f);
    }
    return ((TObjChara *)actor)->random_ratio() < chance;
}

s32 calc_freeze_chance(TObjPlayer *actor, TObjPlayer *attacker, TObjPlayer *target, f32 base_chance) {
    f32 chance;

    chance = base_chance;
    if ((attacker->get_entity_id() >= 0x1000U) && (attacker->get_entity_id() < 0x4000U) && (target->get_entity_id() < 0x1000U)) {
        chance = 0.75f - ((f32) (actor)->get_eic() / 100.0f);
        if (chance < 0.0f) {
            chance = 0.0f;
        }
    } else if (((s32) game_difficulty_selection == 3) && ((0.2f) < chance)) {
        chance = (0.2f);
    } else if ((0.4f) < chance) {
        chance = (0.4f);
    }
    return ((TObjChara *)actor)->random_ratio() < chance;
}

void TObjChara::spawn_poison_effect(s32 play_sound) {
    TParticleCtrl *effect;
    if (this->test_actor_flags(0x02000000) == 0) {
        effect = spawn_particle_effect_with_flags(&this->body_center, 0x25, 0x50);
        if (effect != 0) {
            effect->set_owner_id(((TObjBase *)this)->get_entity_id());
        }
        if (play_sound != 0) {
            play_sound_effect(0xCD0B, &this->position, 0, 0);
        }
    }
}

void TObjChara::spawn_paralysis_feedback_effect(s32 play_sound) {
    TParticleCtrl *effect;
    if (this->test_actor_flags(0x02000000) == 0) {
        effect = spawn_particle_effect_with_flags(&this->body_center, 0x26, 0x50);
        if (effect != 0) {
            effect->set_owner_id(((TObjBase *)this)->get_entity_id());
        }
        if (play_sound != 0) {
            play_sound_effect(0xB20C, &this->position, 0, 0);
        }
    }
}

void TObjChara::spawn_slow_effect(s32 play_sound) {
    TParticleCtrl *effect;
    if (this->test_actor_flags(0x02000000) == 0) {
        effect = spawn_particle_effect_with_flags(&this->body_center, 0x27, 0x50);
        if (effect != 0) {
            effect->set_owner_id(((TObjBase *)this)->get_entity_id());
        }
        if (play_sound != 0) {
            play_sound_effect(0xB20D, &this->position, 0, 0);
        }
    }
}

void TObjChara::spawn_confusion_feedback_effect(s32 play_sound) {
    TParticleCtrl *effect;
    if (this->test_actor_flags(0x02000000) == 0) {
        effect = spawn_particle_effect_with_flags(&this->body_center, 0x24, 0x50);
        if (effect != 0) {
            effect->set_owner_id(((TObjBase *)this)->get_entity_id());
        }
        if (play_sound != 0) {
            play_sound_effect(0xB20E, &this->position, 0, 0);
        }
    }
}
extern "C" {
void TObjChara::play_shock_feedback(s32 play_sound) {
    TParticleCtrl *effect;
    if (this->test_actor_flags(0x02000000) == 0) {
        effect = spawn_particle_effect_with_flags(&this->body_center, 0x21, 0x50);
        if (effect != 0) {
            effect->set_owner_id(((TObjBase *)this)->get_entity_id());
        }
        if (play_sound != 0) {
            play_sound_effect(0xB210, &this->position, 0, 0);
        }
    }
}

void TObjChara::spawn_freeze_shell_effect(CollisionBody *body, s32 play_sound) {
    if (this->test_actor_flags(0x02000000) == 0) {
        if (body != NULL) {
            TObjFreezeShell::create(this, body, 0x96);
        } else if (this->bodies != NULL) {
            TObjFreezeShell::create(this, this->bodies, 0x96);
        }
        if (play_sound != 0) {
            play_sound_effect(0xB20F, &position, 0, 0);
        }
    }
}

void TObjChara::activate_switch_attacks(const Vec *pos) {
    if (test_actor_flags(0x02000000) == 0) {
        spawn_particle_effect_with_flags(pos, 0xB9, 0x40);
        spawn_particle_effect_with_flags(pos, 0xBA, 0x40);
        trigger_switch_attack(pos);
    }
}

s32 TObjPlayer::is_local_player() {
    if (this->get_entity_id() < 0x1000U) {
        return this->is_locally_controlled();
    }
    return 0;
}

u16 TObjPlayer::get_attacker_id() { return this->attacker_id; }

void TObjPlayer::set_attacker_id(u16 id) { this->attacker_id = id; }

int TObjChara::has_no_target() {
    if (this->target == NULL) {
        return TRUE;
    }
    return FALSE;
}

int TObjChara::test_flag_256() { return this->test_actor_flags(256); }

int TObjChara::test_flag30_512() { return this->test_actor_flags(512); }

int TObjChara::is_actor_dead() { return this->test_actor_flags(2048); }

int TObjChara::test_flag_1000() { return this->test_actor_flags(4096); }

s32 TObjChara::check_heavy_damage_flag(f32 dmg) {
    if (((0.25f) * (f32) this->hpmax) < dmg) {
        actorFlags |= 0x400;
        return 1;
    }
    return 0;
}

}
