#pragma readonly_strings on
#pragma fp_contract on

#include "pso/object/TObjVoloptCage.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/math/AngleLookup.h"
#include "pso/misc/TBreakUpMdl.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/GinjaTextureMatrices.h"
#include "pso/system/vector.h"
#include "pso/boss/TBoss3VoloptP02.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"

// TBreakUpMdl.h still derives TBreakUpMdl from TObject; the real class keeps
// its vtable at +0xC, which only this view of it can delete through.
class TBreakUpMdlPieces {
public:
    u8 pad_0[0xC];
    virtual ~TBreakUpMdlPieces();
};

extern "C" {
s32 push_matrix(void);
void post_translate_matrix(const Vec *v);
void rotate_matrix_y(s32 matrix, s32 angle);
s32 rand(void);
void play_sound_effect(s32 id, const Vec *pos, s32 a2, s32 a3);
TObjPlayer *get_player_by_client_id(s32 id);
s32 obj_setFlags30(TUnk_804B9870 *actor, s32 flags);
void send_6x2C_impose_hold(TObjPlayer *player, const Vec *pos, s32 a2, s32 a3, f32 time);
void submit_cursor_candidate(TObjVoloptCage *cage, s32 a1);
void init_collision_body_parts(TUnk_804AF8A0 *actor, const CollisionBody *bodies, s32 count);
void free_collision_body_parts(TUnk_804AF8A0 *actor);
void *alloc__23TAdSinglePlyChrSelectGCFv(u32 size);
void create_breakup_mdl__12TBoss3VoloptFlllll(TBreakUpMdlPieces *model, VoloptBreakUpParams *params, s32 textures,
                                              Vec *pos, s32 angle);
s32 check_flag__10TObjPlayerFl(void *player, s32 flag);
}

extern BmlResource *lbl_805D4CE4;


static const char *TObjVoloptCage_name = "TObjVoloptCage";


static CollisionBody volopt_cage_collision_body[1] = {
    {{0.0f, 18.0f, 0.0f}, 20.0f, {0}, 0x8003, {0}},
};

VoloptBreakUpParams volopt_cage_breakup_params = {
    20, {0.06f, 1.5f, 0.9f, 0.12f, 0.55f, 0.5f},
};

void *volopt_cage_combat_stats;
VoloptCageParams *volopt_cage_params;
static TBreakUpMdlPieces *volopt_cage_breakup_model;
static s32 volopt_cage_model;
static s32 volopt_cage_textures;

void fn_80048C04(TObjVoloptCage *cage) {
    DirectAttackPayload attack = {0, 0.0f};
    TObjPlayer *player;
    attack.power = TBoss3VoloptP02::get_int_param(2);
    player = get_player_by_client_id(cage->targetId);
    if (player != NULL) {
        player->receive_direct_attack(cage->m_up, attack, NULL, -1, -1);
    }
    cage->status = 15;
    obj_setFlags30(cage, 0x800);
    cage->vfunc_63();
}

void TObjVoloptCage::update_breakup() {
    Vec pos;
    s32 angle;
    switch (state) {
    case -1:
        break;
    case 0:
        play_sound_effect(0x4001C112, (Vec *)position, 0, 0);
        create_breakup_mdl__12TBoss3VoloptFlllll(volopt_cage_breakup_model, &volopt_cage_breakup_params,
                                                 volopt_cage_textures, (Vec *)&m_2fc, rotation_y);
        create_breakup_mdl__12TBoss3VoloptFlllll(volopt_cage_breakup_model, &volopt_cage_breakup_params,
                                                 volopt_cage_textures, (Vec *)&m_2fc, rotation_y);
        ((TObjPlayer *)&m_2fc)->trigger_dell_biter_events();
        timer = 12;
        disallow_rendering();
        state = 1;
        break;
    case 1:
        if (timer & 1) {
            angle = (s32)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand())));
            pos.x = 20.0f * cos_table_lookup(angle) + m_2fc;
            pos.y = 20.0f * (3.0517578e-05f * (f32)rand()) + m_300;
            pos.z = 20.0f * sin_table_lookup(angle) + m_304;
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
        ((TObjPlayer *)this)->check_object_collisions();
        if ((timer -= 1) <= 0) {
            actorFlags &= ~0x200;
            referenceHp = hp;
            m_388 &= ~1;
            vfunc_59();
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
                send_6x2C_impose_hold(player, (Vec *)position, -1, 0, 10.0f);
                obj_set_flag_20000(player);
            }
            set_volopt_cage_flag();
        }
        state = 1;
    case 1:
        if (--countdown <= 0) {
            obj_setFlags30(this, 0x800);
            vfunc_63();
        }
        break;
    }
}

void TObjVoloptCage::sub_80049000() {
    switch (state) {
    case 0:
        actorFlags |= 0x40000;
        state = 1;
        play_sound_effect(0x4003A80A, (Vec *)position, 10, 0);
        break;
    case 1:
        position[1] += 5.0f;
        if (position[1] >= 0.0f) {
            position[1] = 0.0f;
            countdown = TBoss3VoloptP02::get_int_param(4) + 450;
            m_388 &= ~1;
            vfunc_59();
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
    TBreakUpMdl *model;
    volopt_cage_model = boss3_volopt_resources->models[0x12].model;
    model = (TBreakUpMdl *)alloc__23TAdSinglePlyChrSelectGCFv(0x10);
    if (model != NULL) {
        model = (TBreakUpMdl *)model->init_from_model(volopt_cage_model);
    }
    volopt_cage_breakup_model = (TBreakUpMdlPieces *)model;
    volopt_cage_combat_stats = TLobby::register_boss(0x26);
    volopt_cage_params = (VoloptCageParams *)TLobby::dispatch_shared_handler_a(0x26);
}

void TObjVoloptCage::render() {
    if (update_object_view_visibility(400.0f, 40.0f) != 0) {
        TObjFish::set_global_param(volopt_cage_textures);
        push_matrix();
        model_render_flags &= ~0x400;
        post_translate_matrix((Vec *)position);
        rotate_matrix_y(0, rotation_y);
        draw_chunk_object((void *)volopt_cage_model);
        pop_matrix();
    }
}

void TObjVoloptCage::update_state() {
    switch (mode) {
    case 7:
        sub_80049000();
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
            vfunc_63();
        } else if (test_flag30_512() != 0) {
            vfunc_62();
        }
    }
    if (mode != (s32)next_action) {
        if ((s32)state != -1) {
            state = -1;
            update_state();
        }
        mode = next_action;
        state = 0;
    }
    update_state();
    update_prev_position();
    ((TBoss3VoloptHiraisin *)this)->copy_position();
    submit_cursor_candidate(this, -1);
}

TObjVoloptCage::~TObjVoloptCage() {
    TObjPlayer *player = get_player_by_client_id(targetId);
    if (player != NULL && TObjPlayer::is_locally_controlled(player) != 0) {
        if (((TLobby *)player)->check_player_flag1() != 0) {
            TObjPlayer::send_code_45_1((s32)player);
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
        VecCopy((Vec *)position, (Vec *)player->position);
    } else {
        queue_destruction();
        return;
    }
    init_collision_body_parts(this, volopt_cage_collision_body, 1);
    m_1c = id;
    *(s16 *)&m_2c = group;
    m_80 = 0;
    *(s16 *)&m_28 = *(s16 *)&boss->m_28;
    *((s16 *)&m_28 + 1) = *((s16 *)&boss->m_28 + 1);
    ((TBoss3Volopt *)this)->reset_photon_effect();
    set_param(0x2E);
    position[1] = -25.0f;
    recalc_combat_stats(volopt_cage_combat_stats, NULL, NULL, 1.0f, 1.0f);
    actorFlags |= 0x40000 | 0x8000;
    actorFlags &= ~0xA00;
    next_action = 7;
    mode = 7;
    volopt_cage_textures = lbl_805D4CE4->models[0x12].m_c;
    status = 0;
}

void set_volopt_cage_flag() {
    boss3_volopt_cage_flag = 1;
}

void obj_set_flag_20000(TUnk_804B9870 *actor) {
    obj_setFlags30(actor, 0x20000);
}

void obj_clear_flag30_20000(TUnk_804B9870 *actor) {
    actor->obj_clearFlags30(0x20000);
}

s32 TLobby::check_player_flag1() {
    return check_flag__10TObjPlayerFl(this, 1);
}

s32 TObjPlayer::check_flag(s32 flag) {
    return (m_334 & flag) != 0;
}
