#include "pso/enemy/EnemyStateRecord.h"
#include "pso/enemy/BattleParameters.h"
#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"

#include "pso/system/vector.h"

#include "pso/object/base/TObjChara.h"

#include "pso/enemy/TObjEneBeastBase.h"

#include "pso/object/TObjControl.h"

#include "pso/enemy/TObjEnemy.h"

#include "pso/player/TObjPlayer.h"

#include "pso/system/task/TObject.h"

#include "pso/network/TLobby.h"
#include "pso/quest/challenge/ChallengeMode.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/ui/keyboard/SystemBootInit.h"


#include "pso/system/ControllerInputState.h"

#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/quest/challenge/TChallenge4P.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/TPlyDispData.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/network/protocol/SubcommandHandlers.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/enemy/EnemyStateSync.h"
#include "pso/player/PlayerCommands.h"
#include "pso/ui/font/TFontSmallTask.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/model_render_state.h"
#include "pso/render/render_util.h"
#include "pso/enemy/AreaSoundRemap.h"
#include "pso/object/TObjLukerNames.h"


extern "C" {


int send_6x60_standard_drop_item_request(void*);

s32 draw_player_status(void *, void *, const char *);

}


s32 area_random_seed;


#define FIND_LIST_TAIL(q) \
    if (this->next == NULL && tail == NULL) { \
        while (q->next != NULL) { \
            q = q->next; \
        } \
        tail = q; \
    }


#pragma push
#pragma readonly_strings on
const char *TObjEnemy_class_name = "TObjEnemy";
const char *control_name = "TObjControl";
#pragma pop

void TObject::resume_update() { m_flags &= ~PAUSE_UPDATE; }

void TObjCollidable::set_shadow_flag() { this->m_flags |= 0x400; }

void TObjCollidable::clear_shadow_flag() { this->m_flags &= 0xfffffbff; }

int TObjEnemy::apply_player_54a00() { return unregister_object_by_id(); }

s32 TObjEnemy::apply_by_index(s16 index, const EnemyStateRecord *record) {
    if (index > 0xB4F) {
        return 0;
    }
    enemy_state_records[index].copy_header(record);
    return 1;
}

TObjEnemy::TObjEnemy(TObject *parent) : TObjChara(parent) {
    m_name = TObjEnemy_class_name;
    targetId = 0xFFFF;
    variant = 0;
    state36C = 0;
    rt_index = 0;
    subtype = 0;
    group = 0;
    previous = 0;
    next = 0;
    children = 0;
    movementParameters = 0;
    resetTimer = 0;
    timer = 0;
    referenceHp = hp;
    for (int i = 0; i < 5; ++i) {
        parameters[i] = 0.0f;
    }
    actorFlags |= 0x20000000;
    this->motion_flags |= 1;
}

TObjEnemy::~TObjEnemy() {
    u16 entity_id;
    this->apply_player_54a00();
    if ((u32) (u32)this->set_entry != 0U) {
        entity_id = this->entity_id;
        if ((entity_id >= 0x1000U) && (entity_id < 0x4000U)) {
            this->mask_sub_flags(-3);
            this->set_entry = NULL;
        }
    }
}

void TLobby::clear_flag_on_phase_e() {
    if (get_main_phase() == 0xE) {
        area_random_seed = 0;
    }
}

void object_control_on_floor_free_stub(void) {  }

s32 TObjEnemy::bind_enemy_combat_stats(player_stats *base_stats, AttackParams *attack_stats, ActorParamBlock *resistance_stats) {
    s16 atp;
    s16 atp_range;
    s16 evp;
    s16 dfp;
    s16 attack_params_atp_max;
    const player_stats *bound_stats_for_tp;
    const player_stats *bound_stats_for_hp;

    if (base_stats != NULL) {
        stat_block = base_stats;
        bound_stats_for_hp = stat_block;
        this->hpmax = (s16) (bound_stats_for_hp->stats.hp + bound_stats_for_hp->level);
        this->hp = (s16) this->hpmax;
        if (obj_testFlag_2E4(4U) != 0) {
            this->tpmax = 0;
            this->tp = 0;
        } else {
            bound_stats_for_tp = stat_block;
            this->tpmax = (s16) (bound_stats_for_tp->stats.mst + bound_stats_for_tp->level);
            this->tp = (s16) this->tpmax;
        }
        goto block_6;
    }
    if (stat_block == NULL) {
        return 0;
    }
block_6:
    if (attack_stats != NULL) {
        attack_params = attack_stats;
        goto block_10;
    }
    if (attack_params == NULL) {
        return 0;
    }
block_10:
    if (resistance_stats != NULL) {
        param_block = resistance_stats;
        goto block_14;
    }
    if (param_block == NULL) {
        return 0;
    }
block_14:
    atp = stat_block->stats.atp;
    this->atp = atp;
    this->base_atp = atp;
    attack_params_atp_max = attack_params->get_atp_max();
    atp_range = attack_params_atp_max - attack_params->get_atp_min();
    this->atp_range = atp_range;
    this->base_atp_range = atp_range;
    evp = stat_block->stats.evp + param_block->values[0];
    this->evp = evp;
    this->base_evp = evp;
    dfp = stat_block->stats.dfp + param_block->value_1c;
    this->dfp = dfp;
    this->base_dfp = dfp;
    this->ata = (s16) (stat_block->stats.ata + attack_params->get_ata());
    this->lck = (s16) stat_block->stats.lck;
    this->element_resist[0] = (s16) param_block->values[1];
    this->element_resist[1] = (s16) param_block->values[3];
    element_resist[2] = (s16) param_block->values[2];
    this->element_resist[3] = (s16) param_block->values[5];
    element_resist[4] = (s16) param_block->values[4];
    this->adjust_atp((s32)((f32)this->get_base_atp() * this->get_status_effect_amount(2)));
    this->adjust_atp_range((s32)((f32)this->get_base_atp_range() * this->get_status_effect_amount(2)));
    this->adjust_dfp((s32)((f32)this->get_base_dfp() * this->get_status_effect_amount(3)));
    return 1;
}

TObjEnemy* TObjEnemy::groupRoot() {
    TObjEnemy* current=this;
    while(current->previous) current=current->previous;
    TObjEnemy* group=current->group;
    if(group) return group;
    return 0;
}

s32 TObjEnemy::has_group() {
    return reinterpret_cast<saddr>(groupRoot()) ? 1 : 0;
}

s32 TObjEneBeastBase::countChildren() {
    TObjEnemy* child = children;
    s32 count = 0;
    if (child) {
        TObjEnemy* cur = child;
        while ((child = cur->next) != NULL) {
            cur = child;
            ++count;
        }
        ++count;
    }
    return count;
}

void TObjEneBeastBase::link_into_group_chain() {
    TObjEnemy *p;
    TObjEnemy *head;
    TObjEnemy *tail;
    s32 i;
    TObjEnemy *q;
    TObjEnemy *r;
    u16 id;
    if ((s32)state36C > 0 && this->group == NULL && this->previous == NULL) {
        head = NULL;
        tail = NULL;
        for (i = registered_player_count; i < registered_player_count + registered_enemy_count; i++) {
            p = (TObjEnemy *)TObjPlayer::get_player_data(i);
            if (p == NULL || p == this) {
                continue;
            }
            id = ((TObjBase *)(p))->get_entity_id();
            if (id < 0x1000 || id >= 0x4000) {
                continue;
            }
            if (p->actorFlags & 0x800) {
                continue;
            }
            if ((s32)p->state36C != (s32)state36C || p->room != room) {
                continue;
            }
            switch (subtype) {
            case 2:
                switch (p->subtype) {
                case 2:
                    FIND_LIST_TAIL(p);
                    break;
                }
                break;
            case 1:
                switch (p->subtype) {
                case 2:
                    if (head == NULL) {
                        q = p->children;
                        if (q == NULL) {
                            head = p;
                        } else FIND_LIST_TAIL(q);
                    }
                    break;
                case 1:
                    FIND_LIST_TAIL(p);
                    break;
                }
                break;
            case 0:
                switch (p->subtype) {
                case 2:
                    if (head == NULL) {
                        q = p->children;
                        if (q == NULL) {
                            head = p;
                        } else {
                            r = q->children;
                            if (r == NULL) {
                                head = q;
                            } else FIND_LIST_TAIL(r);
                        }
                    }
                    break;
                case 1:
                    q = p->children;
                    if (q == NULL) {
                        head = p;
                    } else FIND_LIST_TAIL(q);
                    break;
                default:
                    FIND_LIST_TAIL(p);
                    break;
                }
                break;
            }
        }
        if (head != NULL) {
            this->group = head;
            head->children = this;
        } else if (tail != NULL) {
            this->previous = tail;
            tail->next = this;
        }
    }
}

#undef FIND_LIST_TAIL
void TObjEneBeastBase::unlink_enemy_group_relations() {
    TObjEnemy *head_next_children;
    TObjEnemy *children;
    TObjEnemy *mid_next_children;
    TObjEnemy *previous_children;
    TObjEnemy *root_next_children;
    TObjEnemy *head_next;
    TObjEnemy *mid_next;
    TObjEnemy *last_children;
    TObjEnemy *root_next;
    TObjEnemy *root_only_children;
    TObjEnemy *group;
    TObjEnemy *head_children;
    TObjEnemy *previous;
    TObjEnemy *mid_children;
    TObjEnemy *root_children;
    TObjEnemy *previous_tail;
    TObjEnemy *head_tail;
    TObjEnemy *mid_tail;
    TObjEnemy *root_tail;
    group = this->group;
    if (group != NULL) {
        head_next = this->next;
        if (head_next != NULL) {
            head_children = this->children;
            if (head_children != NULL) {
                head_next_children = head_next->children;
                if (head_next_children != NULL) {
                    head_tail = head_next_children;
                    while (head_tail->next != NULL) {
                        head_tail = head_tail->next;
                    }
                    head_tail->next = head_children;
                    this->children->group = NULL;
                    this->children->previous = head_tail;
                } else {
                    head_next->children = head_children;
                    this->children->group = this->next;
                }
            }
            this->group->children = this->next;
            this->next->group = this->group;
            this->next->previous = NULL;
        } else {
            children = this->children;
            if (children != NULL) {
                group->children = children;
                this->children->group = this->group;
            } else {
                group->children = NULL;
            }
        }
    } else {
        previous = this->previous;
        if (previous != NULL) {
            mid_next = this->next;
            if (mid_next != NULL) {
                mid_children = this->children;
                if (mid_children != NULL) {
                    mid_next_children = mid_next->children;
                    if (mid_next_children != NULL) {
                        mid_tail = mid_next_children;
                        while (mid_tail->next != NULL) {
                            mid_tail = mid_tail->next;
                        }
                        mid_tail->next = mid_children;
                        this->children->group = NULL;
                        this->children->previous = mid_tail;
                    } else {
                        mid_next->children = mid_children;
                        this->children->group = this->next;
                    }
                }
                this->previous->next = this->next;
                this->next->previous = this->previous;
            } else {
                last_children = this->children;
                if (last_children != NULL) {
                    previous_children = previous->children;
                    if (previous_children != NULL) {
                        previous_tail = previous_children;
                        while (previous_tail->next != NULL) {
                            previous_tail = previous_tail->next;
                        }
                        previous_tail->next = last_children;
                        this->children->group = NULL;
                        this->children->previous = previous_tail;
                    } else {
                        previous->children = last_children;
                        this->children->group = this->previous;
                    }
                }
                this->previous->next = NULL;
            }
        } else {
            root_next = this->next;
            if (root_next != NULL) {
                root_children = this->children;
                if (root_children != NULL) {
                    root_next_children = root_next->children;
                    if (root_next_children != NULL) {
                        root_tail = root_next_children;
                        while (root_tail->next != NULL) {
                            root_tail = root_tail->next;
                        }
                        root_tail->next = root_children;
                        this->children->group = NULL;
                        this->children->previous = root_tail;
                    } else {
                        root_next->children = root_children;
                        this->children->group = this->next;
                    }
                }
                this->next->previous = NULL;
            } else {
                root_only_children = this->children;
                if (root_only_children != NULL) {
                    root_only_children->group = NULL;
                }
            }
        }
    }
    this->group = NULL;
    this->previous = NULL;
    this->next = NULL;
    this->children = NULL;
}

void TObjEnemy::link_chain_nodes(TObjEnemy *source, TObjEnemy *destination) {
    TObjEnemy *p = source->children;
    TObjEnemy *q = destination->children;
    if (p != NULL) {
        while (p->next != NULL) {
            p = p->next;
        }
        if (q == NULL) {
            if (p->previous != NULL) {
                p->previous->next = NULL;
                p->previous = NULL;
            }
            p->group = destination;
            destination->children = p;
            return;
        }
        while (q->next != NULL) {
            q = q->next;
        }
        if (p->previous != NULL) {
            p->previous->next = NULL;
        }
        p->previous = q;
        q->next = p;
    }
}

#pragma push
#pragma fp_contract on
void TObjEnemy::update_prev_position() {
    player_stats *stat_block;
    VecCopy(&this->body_center, &this->position);
    stat_block = this->stat_block;
    if (stat_block != NULL) {
        this->body_center.y = (f32) ((0.5f * stat_block->proportions) + this->body_center.y);
    }
}

#pragma pop
void TObjEnemy::award_enemy_experience(u16 client) {
    s32 val;
    TObjPlayer *p;

    if (client >= 0x1000 || (p = get_player_by_client_id(client)) == NULL ||
        p->test_actor_flags(0x800) != 0 || p->get_floor() != get_current_floor()) {
        return;
    }
    val = this->stat_block->exp;
    if (client == this->attacker_id) {
        if (lobby_rule_settings.get_rules_active() == 1) {
            p->record_kill(this, 1);
            draw_player_status(p, p, "\tC1");
            draw_player_status(p, this, "\tC4");
        }
        p->add_capped_counter_999(1);
    } else {
        val *= 0.8f;
    }
    if (is_quest_active() == 1) {
        if (is_challenge_mode() != 0) {
            val = (s32)((f32)val * get_challenge_exp_multiplier());
        } else if (is_challenge_mode_active() != 0) {
            val = (s32)((f32)val * get_challenge4p_exp_multiplier());
        }
    }
    p->add_actor_exp(val);
    create_font_small_task(&body_center, 0xFFFF00FF, 0x14, 0x14, "EXP", val, p->get_entity_id());
}

void TObjEnemy::distribute_experience() {
    s32 count;
    s32 i;
    u16 id;
    if (is_split_screen() == 0) {
        award_enemy_experience(local_attacker_id);
    } else {
        count = get_attack_credit_slot_count(this);
        for (i = 0; i < count; i++) {
            id = get_attack_credit_slot(i);
            if (id == 0xFFFF) {
                break;
            }
            award_enemy_experience(id);
        }
    }
}

int TObjEnemy::query_lobby_state() { return send_6x60_standard_drop_item_request(this); }

void TObjEnemy::refresh_lobby_state() { distribute_experience(); query_lobby_state(); }

TObjChara *get_enemy_entity(u16 entity_id) {
    s32 low;
    s32 mid;
    s32 high;
    if (entity_id >= 0x1000 && entity_id < 0x4000) {
        high = (registered_player_count + registered_enemy_count) - 1;
        low = registered_player_count;
        while (low < high) {
            mid = (low + high) / 2;
            if (entity_table[mid]->get_entity_id() < entity_id) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        TObjChara *e = static_cast<TObjChara *>(entity_table[low]);
        if (e != 0 && entity_id == e->get_entity_id()) {
            return e;
        }
    }
    return 0;
}

void TObjEnemy::apply_set_data(void *set_data) {
    EnemySetData *data = (EnemySetData *)set_data;
    s32 i;
    entity_id = data->entity_id;
    VecCopy(&home_position, &data->position);
    VecCopy(&position, &home_position);
    copy_xyz(&rotation_x, &data->rotation);
    for (i = 0; i < 5; i++) {
        parameters[i] = data->parameters[i];
    }
    variant = data->variant;
    state36C = data->state;
    room = data->room;
    set_group = data->group;
    set_index = data->set_index;
    rng.set_seed(entity_id + area_random_seed);
}

void TObjEnemy::apply_enemy_state(s32 *state) {
    apply_hit_message_flags(state);
}

void TObjEnemy::apply_hit_message_flags(void *state_data) {
    EnemyStateRecord *record = (EnemyStateRecord *)state_data;
    s32 flags;
    StatStatusReceipt p;
    this->hp = this->hpmax - record->damage;
    if (game_difficulty_selection == 3) {
        flags = record->flags & ~0x3F;
    } else {
        flags = record->flags;
        if ((flags & 2) && test_actor_flags(2) == 0) {
            this->apply_paralysis();
        }
        if ((flags & 4) && test_actor_flags(4) == 0) {
            this->apply_shock_status();
        }
        if ((flags & 0x10) && test_actor_flags(0x10) == 0) {
            this->apply_confusion_status();
        }
        if ((flags & 0x20) && test_actor_flags(0x20) == 0) {
            this->apply_movement_ailment(0);
        }
    }
    set_actor_flags(flags);
    p.kind = record->attack_status;
    p.power = record->attack_status_level;
    record->attack_status = 0;
    record->attack_status_level = 0;
    switch (p.kind) {
    case 9:
    case 11: {
        StatStatusReceipt status = p;
        apply_attack_stat_status(&status);
        break;
    }
    }
    p.kind = record->defense_status;
    p.power = record->defense_status_level;
    record->defense_status = 0;
    record->defense_status_level = 0;
    switch (p.kind) {
    case 10:
    case 12: {
        StatStatusReceipt status = p;
        apply_defense_stat_status(&status);
        break;
    }
    }
}

s32 TObjEnemy::sync_enemy_state(s32 status) {
    EnemyStateRecord pkt;
    s32 ret;
    ret = 0;
    if (this->entity_id >= 0x1000 && this->entity_id < 0x4000) {
        this->exchange_object_state(&pkt, 1);
        pkt.damage = this->hpmax - this->hp;
        pkt.flags = this->actorFlags;
        switch (status) {
        case 9:
        case 11:
            pkt.attack_status = status;
            pkt.attack_status_level = 0.1f * ((f32)this->get_status_effect_timer(2) / 30.0f - 40.0f);
            break;
        case 10:
        case 12:
            pkt.defense_status = status;
            pkt.defense_status_level = 0.1f * ((f32)this->get_status_effect_timer(3) / 30.0f - 40.0f);
            break;
        }
        ret = this->exchange_object_state(&pkt, 0);
        if (ret != 0) {
            send_6x0A_enemy_state(&pkt);
        }
    }
    return ret;
}

void TObjEnemy::send_6x0A_enemy_state(void *state_in) {
    EnemyStateRecord state;
    G_UpdateEnemyState_6x0A msg;
    u32 new_flags;
    if (state_in != NULL) {
        state.copy_header(static_cast<const EnemyStateRecord *>(state_in));
    } else if (this->exchange_object_state(&state, 1) == 0) {
        return;
    }
    init_6x0A_enemy_state_packet(&msg);
    msg.header.entity_id = this->entity_id;
    msg.enemy_index = set_index;
    msg.total_damage = state.damage;
    if (game_difficulty_selection == 3) {
        msg.game_flags = state.flags & ~0x3F;
        new_flags = state.flags & 0x3F;
        new_flags &= ~low_game_flags;
        if (new_flags != 0) {
            this->send_6x9C_enemy_low_game_flags(new_flags);
            low_game_flags = state.flags & 0x3F;
        }
    } else {
        msg.game_flags = state.flags;
    }
    msg.send();
}

void handle_6x0A_update_enemy_state(G_UpdateEnemyState_6x0A *command) {
    EnemyStateRecord sp;
    u16 idx;
    TObjEnemy *e;
    command->bswap();
    idx = command->enemy_index;
    sp.copy_header(&enemy_state_records[idx]);
    sp.damage = command->total_damage;
    if (game_difficulty_selection == 3) {
        sp.flags &= 0x3F;
        sp.flags = (command->game_flags & ~0x3F) | sp.flags;
    } else {
        sp.flags = command->game_flags;
    }
    TObjEnemy::apply_by_index(idx, &sp);
    e = (TObjEnemy *)get_enemy_entity(command->header.entity_id);
    if (e != NULL) {
        e->apply_hit_message_flags(&sp);
    }
}

void TObjEnemy::send_6x9C_enemy_low_game_flags(s32 arg) {
    G_SetEnemyLowGameFlagsUltimate_6x9C msg;
    init_6x9C_enemy_low_game_flags_packet(&msg);
    msg.header.entity_id = entity_id;
    msg.status_effect_flags = arg;
    msg.send();
}

void handle_6x9C_set_enemy_low_game_flags_ultimate(G_SetEnemyLowGameFlagsUltimate_6x9C *command) {
    TObjChara *e;
    s32 flags;
    if (command == NULL) {
        return;
    }
    if (game_difficulty_selection != 3) {
        return;
    }
    command->bswap();
    if (command->header.entity_id < 0x1000) {
        return;
    }
    if (command->header.entity_id >= 0x4000) {
        return;
    }
    e = (TObjChara *)find_active_entity_by_id(command->header.entity_id);
    if (e == NULL) {
        return;
    }
    if (e->all_parents_unqueued_for_destruction() == 0) {
        return;
    }
    if (e->test_actor_flags(0x800) != 0) {
        return;
    }
    flags = command->status_effect_flags;
    if (e->test_actor_flags(flags) != 0) {
        return;
    }
    e->set_actor_flags(flags);
    switch (flags) {
    case 2:
        e->apply_paralysis();
        break;
    case 3:
        break;
    case 4:
        e->apply_shock_status();
        break;
    case 16:
        e->apply_confusion_status();
        break;
    case 32:
        e->apply_movement_ailment(0);
        break;
    }
}

TObjControl::TObjControl(TObject *parent) : TObject(parent) {
    m_name = control_name;
    m_decision_mode = 2;
    m_reserved = 0;
}

TObjControl::~TObjControl() {}

void TObjControl::run_task() {
    s16 mode;
    TObjChara *enemy;
    ControllerInputContext *input;

    enemy = (TObjChara *)m_down;
    if (enemy == NULL) {
        queue_destruction();
        return;
    }
    if (TObjPlayer::check_demo_mode() == 0) {
        if (enemy->is_actor_dead() != 0) {
            enemy->resume_update();
            enemy->run_death_reaction();
            return;
        }
        enemy->update_attack_stat_status();
        enemy->update_defense_stat_status();
        if (enemy->update_evp_status() == 0) {
            enemy->update_flag30_timer();
            if ((enemy->update_action_hold_status() != 0) || (enemy->update_shock_clock() != 0) || (enemy->update_movement_status() != 0)) {
                submit_cursor_candidate(enemy, -1);
                minimap_render_dot(&enemy->position, -0x5DB4, 1, 0);
                enemy->refresh_target();
                enemy->pause_update();
                return;
            }
            enemy->resume_update();
        }
        if (enemy->test_flag30_512() != 0) {
            enemy->run_hit_reaction();
            return;
        }
        if (enemy->test_flag_256() != 0) {
            enemy->run_miss_reaction();
            return;
        }
        if (!(enemy->actorFlags & 0x600000)) {
            if (enemy->controller_input != NULL) {
                m_decision_mode = 0;
            } else {
                m_decision_mode = 2;
            }
            mode = m_decision_mode;
            switch (mode) {
            case 0:
                input = enemy->controller_input;
                if (input->pressed_buttons & 4) {
                    enemy->run_attack_action();
                    return;
                }
                if (input->stick_magnitude > 0.1f) {
                    enemy->run_move_action();
                    return;
                }
                enemy->run_idle_action();
                break;
            case 1:
            case 2:
                enemy->refresh_target();
                if (enemy->has_no_target() != 0) {
                    enemy->run_idle_action();
                    return;
                }
                if (enemy->test_flag_1000() != 0) {
                    enemy->run_move_action();
                    return;
                }
                if (enemy->is_target_in_attack_range() != 0) {
                    enemy->run_attack_action();
                    return;
                }
                enemy->run_move_action();
                break;

            }
        }
    }
}

s32 TObjEnemy::remap_sound_for_area(s32 sound_id) { return ::remap_area_sound_id(sound_id, this->rt_index); }

const char *TObjEnemy::get_name() { return (const char *)enemy_name_for_rt_index(this->rt_index); }

void TObjEnemy::render_shadows() {
    if (test_actor_flags(0x800) == 0) {
        this->set_shadow_flag();
        model_render_flags |= 0xC10;
        set_chunk_material_override_pair(-1, 0x800);
        set_shadow_material_state();
        this->render();
        this->clear_shadow_flag();
        model_render_flags &= ~0xC10;
    }
}

void initialize_enemy_photon_effect(TObjEnemy *enemy) { enemy->register_by_id(); }

void TObjEnemy::set_param(s32 v) { this->rt_index = v; }
