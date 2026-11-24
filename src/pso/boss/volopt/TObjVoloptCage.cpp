#pragma readonly_strings on
#pragma fp_contract on

#include "pso/effect/particle/ParticleFactory.h"
#include "pso/boss/volopt/TObjVoloptCage.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/math/AngleLookup.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/render/GinjaTextureMatrices.h"
#include "pso/system/vector.h"
#include "pso/boss/volopt/TBoss3VoloptP02.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include <stdlib.h>
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

extern BmlResource *volopt_p02_resources;


static const char *TObjVoloptCage_name = "TObjVoloptCage";


static CollisionBody volopt_cage_collision_body[1] = {
    {{0.0f, 18.0f, 0.0f}, 20.0f, 0.0f, 0, 0x8003},
};

BreakUpParamRow volopt_cage_breakup_params = {
    20, 0.06f, 1.5f, 0.9f, 0.12f, 0.55f, 0.5f,
};

player_stats *volopt_cage_combat_stats;
VoloptCageParams *volopt_cage_params;
static TBreakUpMdlData *volopt_cage_breakup_model;
static NJS_OBJECT *volopt_cage_model;
static NJS_TEXLIST *volopt_cage_textures;

void TObjVoloptCage::damage_caged_player() {
    DirectAttackPayload attack = {0, 0.0f};
    TObjPlayer *player;
    attack.power = TBoss3VoloptP02::get_int_param(2);
    player = get_player_by_client_id(targetId);
    if (player != NULL) {
        player->receive_direct_attack(m_up, attack, NULL, -1, -1);
    }
    status = 15;
    set_actor_flags(0x800);
    run_death_reaction();
}

void TObjVoloptCage::update_breakup() {
    Vec pos;
    s32 angle;
    switch (state) {
    case -1:
        break;
    case 0:
        play_sound_effect(0x4001C112, &position, 0, 0);
        TBoss3Volopt::create_breakup_mdl(volopt_cage_breakup_model, &volopt_cage_breakup_params,
                           volopt_cage_textures, &body_center, rotation_y);
        TBoss3Volopt::create_breakup_mdl(volopt_cage_breakup_model, &volopt_cage_breakup_params,
                           volopt_cage_textures, &body_center, rotation_y);
        trigger_dell_biter_events(&body_center);
        timer = 12;
        disallow_rendering();
        state = 1;
        break;
    case 1:
        if (timer & 1) {
            angle = (s32)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand())));
            pos.x = 20.0f * cos_table_lookup(angle) + body_center.x;
            pos.y = 20.0f * (3.0517578e-05f * (f32)rand()) + body_center.y;
            pos.z = 20.0f * sin_table_lookup(angle) + body_center.z;
            spawn_particle_effect(&pos, 0xFB);
        }
        if ((timer -= 1) <= 0) {
            queue_destruction();
        }
        break;
    }
}

void TObjVoloptCage::update_collision_state() {
    s32 count;
    switch (state) {
    case -1:
        break;
    case 0:
        actorFlags &= ~0x200000;
        timer = 30;
        state = 1;
    case 1:
        count = countdown;
        countdown = count - 1;
        this->check_object_collisions();
        if ((timer -= 1) <= 0) {
            actorFlags &= ~0x200;
            referenceHp = hp;
            behavior_flags &= ~1;
            run_move_action();
        }
        break;
    default:
        break;
    }
}

void TObjVoloptCage::update_capture() {
    TObjPlayer *player;
    switch (state) {
    case -1:
        break;
    case 0:
        player = get_player_by_client_id(targetId);
        if (player != NULL) {
            if (TObjPlayer::is_locally_controlled(player) != 0) {
                send_6x2C_impose_hold(player, &position, -1, 0, 10.0f);
                obj_set_flag_20000(player);
            }
            set_volopt_cage_flag();
        }
        state = 1;
    case 1:
        if (--countdown <= 0) {
            set_actor_flags(0x800);
            run_death_reaction();
        }
        break;
    }
}

void TObjVoloptCage::update_rise() {
    switch (state) {
    case 0:
        actorFlags |= 0x40000;
        state = 1;
        play_sound_effect(0x4003A80A, &position, 10, 0);
        break;
    case 1:
        position.y += 5.0f;
        if (position.y >= 0.0f) {
            position.y = 0.0f;
            countdown = TBoss3VoloptP02::get_int_param(4) + 450;
            behavior_flags &= ~1;
            run_move_action();
        }
        break;
    case -1:
        actorFlags &= ~0x40000;
        break;
    }
}

void TObjVoloptCage::destroy() {
    delete volopt_cage_breakup_model;
    volopt_cage_breakup_model = NULL;
}

void TObjVoloptCage::init_break_model() {
    volopt_cage_model = boss3_volopt_resources->models[0x12].model;
    volopt_cage_breakup_model = new TBreakUpMdlData(volopt_cage_model);
    volopt_cage_combat_stats = TLobby::register_boss(0x26);
    volopt_cage_params = (VoloptCageParams *)TLobby::dispatch_shared_handler_a(0x26);
}

void TObjVoloptCage::render() {
    if (update_object_view_visibility(400.0f, 40.0f) != 0) {
        TObjFish::set_global_param(volopt_cage_textures);
        push_matrix();
        model_render_flags &= ~0x400;
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        draw_chunk_object(volopt_cage_model);
        pop_matrix();
    }
}

void TObjVoloptCage::update_state() {
    switch (mode) {
    case 7:
        update_rise();
        return;
    case 1:
        update_capture();
        return;
    case 4:
        update_collision_state();
        return;
    case 5:
        update_breakup();
        return;
    }
}

void TObjVoloptCage::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        run_demo_task();
        return;
    }
    if (mode != 7) {
        if (has_flag_0x800() != 0) {
            run_death_reaction();
        } else if (test_flag30_512() != 0) {
            run_hit_reaction();
        }
    }
    if (mode != next_action) {
        if ((s32)state != -1) {
            state = -1;
            update_state();
        }
        mode = next_action;
        state = 0;
    }
    update_state();
    update_prev_position();
    copy_position();
    submit_cursor_candidate(this, -1);
}

TObjVoloptCage::~TObjVoloptCage() {
    TObjPlayer *player = get_player_by_client_id(targetId);
    if (player != NULL && TObjPlayer::is_locally_controlled(player) != 0) {
        if (player->check_player_flag1() != 0) {
            send_release_hold(player);
        }
        obj_clear_flag30_20000(player);
    }
    clear_volopt_cage_flag();
    free_collision_body_parts(this);
}

TObjVoloptCage::TObjVoloptCage(TObjEnemy *boss, u16 target, u16 id, s32 group) : TObjEnemyCustom(boss) {
    TObjPlayer *player;
    m_name = TObjVoloptCage_name;
    targetId = target;
    player = get_player_by_client_id(targetId);
    if (player != NULL) {
        VecCopy(&position, &player->position);
    } else {
        queue_destruction();
        return;
    }
    init_collision_body_parts(this, volopt_cage_collision_body, 1);
    entity_id = id;
    set_index = group;
    set_entry = 0;
    room = boss->room;
    set_group = boss->set_group;
    register_by_id();
    set_param(0x2E);
    position.y = -25.0f;
    recalc_combat_stats((player_stats *)volopt_cage_combat_stats, NULL, NULL, 1.0f, 1.0f);
    actorFlags |= 0x40000 | 0x8000;
    actorFlags &= ~0xA00;
    next_action = 7;
    mode = 7;
    volopt_cage_textures = volopt_p02_resources->models[0x12].texlist;
    status = 0;
}

void set_volopt_cage_flag() {
    boss3_volopt_cage_flag = 1;
}

void obj_set_flag_20000(TObjBase *actor) {
    actor->set_actor_flags(0x20000);
}

void obj_clear_flag30_20000(TObjBase *actor) {
    actor->clear_actor_flags(0x20000);
}

s32 TObjPlayer::check_player_flag1() {
    return check_flag(1);
}

s32 TObjPlayer::check_flag(s32 flag) {
    return (state_flags & flag) != 0;
}
