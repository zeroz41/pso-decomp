#include "pso/system/EnemyBmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/unk/text_800D8830.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/map/CsnQuery.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/mericarol/TObjEneBm9Mericarol.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/render_util.h"
#include "pso/render/model_render_state.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/map/FloorArea.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2F28.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/math/AngleUnits.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/enemy/mericarol/TObjEneBm9Mericarol_EffCurse3.h"
#include "pso/enemy/mericarol/TObjEneBm9Mericarol_Bomb.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/task/TObject.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/object/base/TObjChara.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/dd/TObjEneDD_800BB804.h"
#include "pso/unk/text_802D1C84.h"
#pragma defer_codegen on

extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
struct Sub_800ACA10 { u8 pad[0x18]; s32 level; };

extern "C" {
extern s32 game_difficulty_selection;
void vec3_add_to(Vec *dst, const Vec *src);
void TBoss8Dragon__sub_800BB7D4(void *self, int id);
s32 approach_angle_limited(s32 from, s32 to, s32 max_step);
s32 angle_difference_abs(s32 a, s32 b);
void fn_802CE510(TObjEneBm9Mericarol *owner);
s32 attack_target_history_add(AreaAttackHistory *history, TObjChara *target);
void create__9TTecKafunFllllllff(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 farg0, f32 farg1);
}

// The motion-binding block TLobby::spawn_npc_enemy takes (same layout as
// MojaAnimationBinding and GeeAnimationBinding).

extern "C" {
// Reached with a lis/addi each, never off a shared .rodata base like the TU's own tables: not defined here.
extern const s32 lbl_804722E8[];
extern const s32 lbl_804722F4[];
extern const s32 lbl_80472300[];
extern const s32 lbl_8047230C[];
extern void *tl_04;
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);
s32 free_collision_body_parts(void *);
void init_collision_body_parts(void *, void *, s32);
void TObjPlayer__sub_800F0928(void);
}

// inferred: the per-phase colour the constructor gives its two TUnk_80494968 effects.
static const u32 mericarol_phase_effect_colors[3] = { 0xFFFD42E3, 0xFF39374B, 0xFFDEFB46 };

TObjEneBm9MericarolMovementParameters lbl_804E1548 = {
    { 225.0f, 0.0f, 0x200 }, { 0, 0, 0, 0 },
};

CollisionBody lbl_804E1564[2] = {
    { { 0.0f, 0.0f, 0.0f }, 25.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 50.0f, 0.0f, 0, 0x9D03, { 0.0f, 0.0f, 0.0f }, 0.0f },
};

__declspec(section ".data") const char *lbl_804E15BC[2] = {
    "bm9_s_meri_body.nj", NULL,
};

const char *lbl_804E15C4[9] = {
    "atack_bm9_s_meri_body.njm", "damage_bm9_s_meri_body.njm", "dead_bm9_s_meri_body.njm", "fire_bm9_s_meri_body.njm",
    "laugh_bm9_s_meri_body.njm", "wait_bm9_s_meri_body.njm", "wait2_bm9_s_meri_body.njm", "wake_bm9_s_meri_body.njm",
    NULL,
};

BmlResourceDescriptor lbl_804E15E8 = {
    "bm_ene_bm9_s_mericarol.bml", lbl_804E15BC, lbl_804E15C4, 1, 8,
};

__declspec(section ".data") const char *lbl_804E15F8[2] = {
    "lo_bm9_s_meri_body.nj", NULL,
};

const char *lbl_804E1600[9] = {
    "atack_bm9_s_meri_body.njm", "damage_bm9_s_meri_body.njm", "dead_bm9_s_meri_body.njm", "fire_bm9_s_meri_body.njm",
    "laugh_bm9_s_meri_body.njm", "wait_bm9_s_meri_body.njm", "wait2_bm9_s_meri_body.njm", "wake_bm9_s_meri_body.njm",
    NULL,
};

BmlResourceDescriptor lbl_804E1624 = {
    "bm_ene_bm9_s_mericarol_low.bml", lbl_804E15F8, lbl_804E1600, 1, 8,
};

TObjMotionAction lbl_804E1634[9] = {
    { 3, 0, 3, 0.6f, 0 },
    { 1, 0, 5, 1.0f, 0 },
    { 1, 0, 6, 0.5f, 0 },
    { 1, 0, 5, 0.5f, 0 },
    { 2, 3, 7, 0.7f, 0 },
    { 3, 0, 1, 0.8f, 0 },
    { 3, 0, 2, 0.5f, 0 },
    { 1, 0, 4, 0.6f, 0 },
    { 1, 0, 0, 0.7f, 0 },
};

u8 *bm9_mericarol_phase_hp_table[3];
u8 *lbl_80540B64[3];
u8 *lbl_80540B70[3];
TObjEneBm9MericarolParams *mericarol_phase_param_table[3];
f32 lbl_80540B88[4];
const char *TObjEneBm9Mericarol__class_name = "TObjEneBm9Mericarol";
SampledMotionPoints *TBoss4Type3_shared_instance;
SampledMotionPoints *lbl_805D6864;
BmlResource *lbl_805D6868;
s32 lbl_805D686C;
u32 lbl_805D6870;
u32 lbl_805D6874;
u32 lbl_805D6878;
#pragma push
#pragma opt_common_subs off
#pragma pop
extern "C" void TBoss4Type3__sub_802D1130(void) {
    s32 i;

    if (is_split_screen() != 0) {
        lbl_805D6868 = load_enemy_bml_resource(&lbl_804E1624);
    } else {
        lbl_805D6868 = load_enemy_bml_resource(&lbl_804E15E8);
    }
    lbl_805D686C = 0;
    lbl_805D6870 = 0;
    lbl_80540B88[0] = 0.0f;
    lbl_80540B88[1] = 0.0f;
    lbl_80540B88[2] = 0.0f;
    lbl_805D6874 = 0;
    lbl_805D6878 = 0;
    fn_802D1CC8();
    TObjPlayer__sub_800F0928();
    for (i = 0; i < 3; i++) {
        bm9_mericarol_phase_hp_table[i] = (u8 *)TLobby::register_boss(lbl_804722E8[i]);
        lbl_80540B64[i] = (u8 *)TLobby::dispatch_shared_handler_b(lbl_804722F4[i]);
        lbl_80540B70[i] = (u8 *)TLobby::register_object(lbl_80472300[i]);
        mericarol_phase_param_table[i] = (TObjEneBm9MericarolParams *)TLobby::dispatch_shared_handler_a(lbl_8047230C[i]);
    }
    TBoss4Type3_shared_instance = new SampledMotionPoints(2, 0.0f, 20.0f, 0.7f);
    lbl_805D6864 = new SampledMotionPoints(2, 0.0f, 20.0f, 0.7f);
    set_motion_packed_rotation();
    TBoss4Type3_shared_instance->sample_two_nodes((NJS_OBJECT *)lbl_805D6868->models[0].model, (NJS_MOTION *)lbl_805D6868->motions[lbl_804E1634[8].motion].motion, 0x20, 0x21);
    lbl_805D6864->sample_two_nodes((NJS_OBJECT *)lbl_805D6868->models[0].model, (NJS_MOTION *)lbl_805D6868->motions[lbl_804E1634[8].motion].motion, 0x2A, 0x2B);
    clear_motion_packed_rotation();
    {
        NpcAnimationBinding params = { reinterpret_cast<BmlMotionEntry *>(lbl_805D6868->motions), reinterpret_cast<TObjMotionAction *>(lbl_804E1634), 3, 1, 9 };
        NpcModelRegistry::register_animated_chunk(0x42, reinterpret_cast<void *>(lbl_805D6868->models[0].model), reinterpret_cast<void *>(lbl_805D6868->models[0].m_c), &params,
            lbl_804E1564[0].radius, 0.0f);
    }
}

void *TObjEneBm9Mericarol::create(void *arg0) {
    return new TObjEneBm9Mericarol((TObject *)tl_04, arg0);
}

void TObjEneBm9Mericarol::free_shared_instances() {
    if (lbl_805D6864 != NULL) {
        delete lbl_805D6864;
        lbl_805D6864 = NULL;
    }
    if (TBoss4Type3_shared_instance != NULL) {
        delete TBoss4Type3_shared_instance;
        TBoss4Type3_shared_instance = NULL;
    }
    fn_802D1C84();
    if (lbl_805D6868 != NULL) {
        delete lbl_805D6868;
        lbl_805D6868 = NULL;
    }
}

TObjEneBm9Mericarol::TObjEneBm9Mericarol(TObject *parent, void *set_data) : TObjEneDD_ST(parent) {
    s32 ph;
    s32 i;

    m_name = TObjEneBm9Mericarol__class_name;
    invoke_initialization_hook(set_data);
    init_size_tier_and_offsets();
    m_438 = 0;
    if (random_ratio() <= 0.002f) {
        m_438 |= 0x400;
    }
    init_position_vectors();
    model = (void *)lbl_805D6868->models[0].model;
    texlist = (saddr)lbl_805D6868->models[0].m_c;
    init_model(lbl_804E1564, 1);
    set_field_d8((saddr)lbl_804E1634);
    set_field_dc((saddr)lbl_805D6868->motions);
    requested_action = 2;
    set_animation(requested_action);
    set_field_b8(requested_action);
    ph = get_phase();
    reset_hp(bm9_mericarol_phase_hp_table[ph], lbl_80540B64[ph], lbl_80540B70[ph]);
    m_3c0[0] = TUnk_80494968::create(0xA0303030, mericarol_phase_effect_colors[ph]);
    m_3c0[1] = TUnk_80494968::create(0xA0303030, mericarol_phase_effect_colors[ph]);
    add_flags_2e4(0x12);
    movementParameters = &lbl_804E1548;
    switch (get_phase()) {
    case 0:
        initialize_enemy_state(0x38);
        break;
    case 1:
        initialize_enemy_state(0x39);
        break;
    case 2:
        initialize_enemy_state(0x3A);
        break;
    }
    wall_reach = 5.0f;
    enemy_init_acquire_period(0x1E);
    enemy_init_validate_period(0x1E);
    m_43c = 0.0f;
    m_44c = 0;
    m_450 = 0;
    m_454 = 0;
    m_458 = 0;
    m_46c.reset_obstruction_fade();
    m_48c = new TObjCollidable(0);
    init_collision_body_parts(m_48c, &lbl_804E1564[1], 1);
    m_488 = new AreaAttackHistory(8);
    m_490 = 0;
    m_494 = 0;
    m_498 = 0;
    m_49c = 0;
    m_4a0 = 0;
    m_4a4 = 0.0f;
    m_4ac = 0;
    sync_center_position();
    update_body_colliders();
    transform_part_positions();
    mode = 0;
    dispatch_action(mode, 4);
    sub_8002AE64();
    for (i = 0; i < 4; i++) {
        m_3c8[i].activate_and_dispatch();
    }
}

TObjEneBm9Mericarol::~TObjEneBm9Mericarol() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (m_3c0[i] != NULL) {
            m_3c0[i]->queue_destruction();
            m_3c0[i] = NULL;
        }
    }
    if (m_488 != NULL) {
        delete m_488;
        m_488 = NULL;
    }
    if (m_48c != NULL) {
        free_collision_body_parts(m_48c);
        delete m_48c;
        m_48c = NULL;
    }
    if (m_4ac != NULL) {
        m_4ac->queue_destruction();
        m_4ac = NULL;
    }
    free_collision_body_parts(this);
}

void TObjEneBm9Mericarol::run_task() {
    s16 state;
    s32 flags;
    if (TObjPlayer::check_demo_mode() != 0) {
        run_demo_task();
        return;
    }
    flags = m_438;
    if (flags & 0x10) {
        if (current_target == 0) {
            m_438 = flags & ~0x10;
        }
    } else if (current_target != 0) {
        m_438 = flags | 0x10;
    }
    if (update_status_effects() != 4) {
        update_action_state();
    } else {
        state = mode;
        if (state == 0 || state == 1) {
            m_46c.reset_color();
            transition_enemy_state(2);
        }
    }
    sync_center_position();
    submit_default_cursor_candidate();
    render_minimap_dot();
}

void TObjEneBm9Mericarol::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        handle_action(reason);
        return;
    case 1:
        sub_802D05BC(reason);
        return;
    case 2:
        handle_event(reason);
        return;
    case 3:
        sub_802D01D8(reason);
        return;
    case 4:
        handle_shot_state(reason);
        return;
    case 5:
        sub_802CFB64(reason);
        return;
    case 6:
        sub_802CF7B4(reason);
        return;
    case 10:
        sub_802CF368(reason);
        return;
    case 11:
        state_burrow(reason);
        return;
    case 7:
        sub_802CF4F8(reason);
        return;
    case 8:
        handle_motion_event(reason);
        return;
    case 9:
        sub_802CEDA0(reason);
        return;
    case 12:
        handle_state_message(reason);
    default:
        return;
    }
}

void TObjEneBm9Mericarol::refresh_target() {  }

void TObjEneBm9Mericarol::run_death_reaction() {
    s16 temp_r0;

    temp_r0 = this->mode;
    if ((temp_r0 != 0xB) && (temp_r0 != 0xC)) {
        transition_enemy_state(0xB);
    }
}

void TObjEneBm9Mericarol::run_hit_reaction() {
    if ((s16) this->mode != 0xA) {
        if (this->m_438 & 0x20) {
            clear_attack_receipts();
            return;
        }
        transition_enemy_state(0xA);
    }
}

void TObjEneBm9Mericarol::run_miss_reaction() {  }

void TObjEneBm9Mericarol::sync_center_position() {
    VecCopy(&body_center, &position);
    body_center.y += 20.0f;
    VecCopy(&center, &body_center);
}

void TObjEneBm9Mericarol::update_body_colliders() {
    bodies->offset.y = body_center.y - position.y;
}

void TObjEneBm9Mericarol::sub_802D0940() {  }

void TObjEneBm9Mericarol::sub_802D093C() {  }

s32 TObjEneBm9Mericarol::try_set_mode8_if_flag2() {
    if (this->m_438 & 2) {
        transition_enemy_state(8);
        return 1;
    }
    return 0;
}

TObjPlayer *TObjEneBm9Mericarol::find_nearby_target() {
    TObjPlayer *best = NULL;
    s32 n = TLobby::get_game_mode();
    TObjPlayer *pl;
    s32 i;
    for (i = 0; i < n; i++) {
        pl = TObjPlayer::get_player_data(i);
        if (((TObjEneDD *)pl)->is_valid_target() != 0 && pl->obj_isState2_324() == 0) {
            best = pl;
            break;
        }
    }
    if (((TObjEneDD *)best)->is_valid_target() != 0 && horizontal_distance_squared(&position, &best->position) < 10000.0f) {
        return best;
    }
    return NULL;
}

void TObjEneBm9Mericarol::init_size_tier_and_offsets() {
    f32 roll;
    s32 tier;
    m_45c = variant;
    tier = m_45c;
    if (tier < 0 || tier > 2) {
        roll = random_ratio();
        if (roll > 0.9f) {
            m_45c = 2;
        } else if (roll > 0.8f) {
            m_45c = 1;
        } else {
            m_45c = 0;
        }
    }
    m_440 = 0.5f + parameters[0];
    m_444 = 3.0f + parameters[1];
    if (m_444 < 1.0f) {
        m_444 = 1.0f;
    }
    m_448 = 0.1f + parameters[2];
}

s32 TObjEneBm9Mericarol::get_phase() { return m_45c; }

void TObjEneBm9Mericarol::sub_802D073C() {
    play_persistent_sound((s32)(remap_sound_for_area(0x3A810)), (saddr)this, (uaddr)&position, (s32)(0), (s32)(0));
}

void TObjEneBm9Mericarol::handle_action(s32 arg1) {
    switch (arg1) {
    case 4:
        set_intangible();
        return;
    case 3:
        transition_enemy_state(1);
    case 5:
    case 0:
        return;
    }
}

void TObjEneBm9Mericarol::sub_802D05BC(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 2;
        set_intangible();
        sub_802D093C();
        m_438 |= 0x28;
        m_438 &= ~0x10;
        set_field_378(2);
        this->enemy_clear_target();
        m_46c.start_fade_in();
        play_area_sound_effect(&position);
        return;
    case 3:
        if (m_46c.advance_toward_max() != 0) {
            transition_enemy_state(2);
        }
    case 1:
        return;
    case 0:
        advance_animation();
        update_ground_contact();
        update_body_colliders();
        return;
    case 5:
        m_438 &= ~0x28;
        break;
    }
}

void TObjEneBm9Mericarol::handle_event(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 2;
        clear_intangible();
        sub_802D093C();
        m_438 &= ~0x28;
        set_field_378(2);
        this->enemy_clear_target();
        return;
    case 3:
        if (try_set_mode8_if_flag2() == 0 && update_linked_position(250.0f) != 0) {
            transition_enemy_state(3);
        }
    case 5:
    case 1:
        return;
    case 0:
        advance_animation();
        update_ground_contact();
        update_body_colliders();
        break;
    }
}

void TObjEneBm9Mericarol::sub_802D01D8(s32 arg1) {
    f32 distance;
    u16 target;
    switch (arg1) {
    case 4:
        if (mode == 2) {
            requested_action = 4;
            play_sound_effect(remap_sound_for_area(0x3AD0E), &position, 0, 0);
        } else {
            requested_action = 3;
        }
        clear_intangible();
        sub_802D0940();
        m_438 &= ~0x28;
        set_field_378(3);
        m_494 = 0;
        m_4a0 = 0;
        break;
    case 3:
        if (try_set_mode8_if_flag2() != 0) {
            break;
        }
        distance = destination_distance;
        if (distance > 300.0f || current_target == 0) {
            transition_enemy_state(2);
            break;
        }
        if (distance < 50.0f) {
            if (angle_difference_abs(rotation_y, m_4a0) < 0x4000) {
                if (random_ratio() <= m_448) {
                    transition_enemy_state(9);
                    break;
                }
                transition_enemy_state(5);
            }
        } else if (m_494 > mericarol_phase_param_table[get_phase()]->m_20) {
            transition_enemy_state(4);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        target = 0xFFFF;
        if (tick_period_counter((saddr)this, &m_450, 0x14) != 0) {
            if (destination_distance > 30.0f) {
                if (is_confused() != 0) {
                    target = enemy_nearest_visible_enemy(this, destination_distance - 30.0f);
                }
                if (target == 0xFFFF) {
                    target = enemy_find_nearest_player_in_range((u8 *)this, (f32)(destination_distance - 30.0f));
                }
                if (target != 0xFFFF) {
                    enemy_set_target_id(this, target);
                }
            }
        } else if (((TObjEneEpsilon *)this)->update_death_check() == 0) {
            break;
        }
        enemy_copy_target_destination();
        update_velocity();
        m_494++;
        m_4a0 = (s32)(RADIANS_TO_ANGLE * atan2_float(destination_direction.x, destination_direction.z));
        rotation_y = approach_angle_limited(rotation_y, m_4a0, ((TObjEneBm9MericarolMovementParameters *)movementParameters)->move.turn_speed);
        rotation_y = (s16)rotation_y;
        update_ground_contact();
        update_body_colliders();
        sub_802D073C();
        break;
    }
}

void TObjEneBm9Mericarol::handle_shot_state(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 0;
        clear_intangible();
        sub_802D0940();
        m_438 &= ~8;
        m_438 |= 0x20;
        set_field_378(3);
        m_4ac = 0;
        break;
    case 3:
        if (try_set_mode8_if_flag2() == 0 && get_flag_b4() != 0) {
            transition_enemy_state(3);
        }
        break;
    case 1:
        break;
    case 0:
        advance_animation();
        if (is_passing_frame(10.0f) != 0) {
            sub_802CE68C(&m_460, 0x43);
            new TObjEneBm9Mericarol_Bomb(this, &m_460, &current_target->position,
                mericarol_phase_param_table[get_phase()]->m_8, mericarol_phase_param_table[get_phase()]->m_c,
                random_ratio() <= (f32)mericarol_phase_param_table[get_phase()]->m_2c / 100.0f);
            play_sound_effect(remap_sound_for_area(0x3A307), &m_460, 0, 0);
        }
        enemy_copy_target_destination();
        update_velocity();
        m_4a0 = (s32)(RADIANS_TO_ANGLE * atan2_float(destination_direction.x, destination_direction.z));
        rotation_y = approach_angle_limited(rotation_y, m_4a0, ((TObjEneBm9MericarolMovementParameters *)movementParameters)->move.turn_speed);
        rotation_y = (s16)rotation_y;
        update_ground_contact();
        update_body_colliders();
        sub_802D073C();
        break;
    case 5:
        if (m_4ac != 0) {
            m_4ac->queue_destruction();
            m_4ac = 0;
        }
        break;
    }
}

void TObjEneBm9Mericarol::sub_802CFB64(s32 arg1) {
    Vec trail0[2];
    Vec trail1[2];
    s32 i;
    Vec *points1;
    Vec *points0;
    TObjChara *p;
    switch (arg1) {
    case 4:
        requested_action = 8;
        clear_intangible();
        sub_802D0940();
        m_438 &= ~8;
        m_438 |= 0x20;
        set_field_378(3);
        m_490 = 0;
        m_494 = 0;
        break;
    case 3:
        if (m_490 == 2) {
            transition_enemy_state(3);
        }
        break;
    case 1:
        break;
    case 0:
        advance_animation();
        enemy_validate_retained_target(this);
        switch (m_490) {
        case 2:
            break;
        case 0:
            if (is_passing_frame(frame_count - 1.0f - play_speed) != 0) {
                m_490 = 1;
                m_438 &= ~0x20;
                requested_action = 3;
                m_494 = 0;
                play_speed = 0.0f;
            } else {
                if (is_passing_frame(8.0f) != 0) {
                    VecCopy(&m_48c->position, &position);
                    TObjPlayer::init_all_slots();
                    m_48c->check_object_collisions();
                    if (m_48c->bodies->flags & 0x80000) {
                        for (i = 0; i < 0x10; i++) {
                            p = (TObjChara *)TObjPlayer::get_battle_param(i);
                            if (p == NULL) {
                                break;
                            }
                            if (obj_is_hit_receivable((u8 *)p) != 0 && p->select_melee_contact_body(this, 1.0f) != 0) {
                                p->apply_knockback_from_attacker((u8 *)this, 1.0f);
                                p->receive_physical_attack(this, 1.0f);
                            }
                        }
                    }
                } else if (is_passing_frame(7.0f) != 0) {
                    play_sound_effect(remap_sound_for_area(0x3A40D), &position, 0, 0);
                }
                points0 = TBoss4Type3_shared_instance->lookup(frame);
                points1 = lbl_805D6864->lookup(frame);
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(&position.x);
                rotate_matrix_y(0, rotation_y);
                matrix_mult_vec_array(NULL, (const Vec *)points0, (Vec *)trail0, 2);
                matrix_mult_vec_array(NULL, (const Vec *)points1, (Vec *)trail1, 2);
                pop_matrix();
                if (m_3c0[0] != NULL) {
                    m_3c0[0]->vfunc_6(&trail0[0], &trail0[1]);
                }
                if (m_3c0[1] != NULL) {
                    m_3c0[1]->vfunc_6(&trail1[0], &trail1[1]);
                }
            }
            break;
        case 1:
            m_494++;
            if (m_494 >= mericarol_phase_param_table[get_phase()]->m_28) {
                m_490 = 2;
            }
            break;
        }
        enemy_copy_target_destination();
        update_velocity();
        m_4a0 = (s32)(RADIANS_TO_ANGLE * atan2_float(destination_direction.x, destination_direction.z));
        rotation_y = approach_angle_limited(rotation_y, m_4a0, ((TObjEneBm9MericarolMovementParameters *)movementParameters)->move.turn_speed);
        rotation_y = (s16)rotation_y;
        update_ground_contact();
        update_body_colliders();
        sub_802D073C();
        break;
    case 5:
        m_438 &= ~2;
        break;
    }
}

void TObjEneBm9Mericarol::sub_802CF7B4(s32 arg1) {
    s32 hit_wall;
    switch (arg1) {
    case 4:
        sync_center_position();
        if (this->enemy_probe_wall_ahead(destination_direction.x, destination_direction.z, 100.0f) != NULL) {
            requested_action = 3;
            m_490 = 3;
            return;
        }
        requested_action = 2;
        set_field_378(3);
        m_438 &= ~0x28;
        m_490 = 0;
        m_494 = 0;
        m_498 = 0xA;
        m_4a4 = m_444;
        m_4a8 = 0.0f;
        fill_value_array(m_488);
        set_active();
        return;
    case 3:
        if (m_490 == 3) {
            transition_enemy_state(3);
        }
        return;
    case 0:
        advance_animation();
        switch (m_490) {
        case 0:
            sync_center_position();
            if (this->enemy_probe_wall_ahead(destination_direction.x, destination_direction.z, 100.0f) != NULL) {
                requested_action = 3;
                m_490 = 3;
                play_sound_effect(remap_sound_for_area(0x3AD0E), &position, 0, 0);
                return;
            }
            m_498 = m_498 - 1;
            if (m_498 <= 0) {
                requested_action = 1;
                m_490 = 1;
                m_438 |= 0x20;
                bodies->flags |= 0x700;
                play_sound_effect(remap_sound_for_area(0x3AD0E), &position, 0, 0);
            }
            if (enemy_validate_retained_target(this) != 0) {
                enemy_copy_target_destination();
                update_velocity();
            }
            m_4a0 = (s32)(RADIANS_TO_ANGLE * atan2_float(destination_direction.x, destination_direction.z));
            rotation_y = approach_angle_limited(rotation_y, m_4a0, ((TObjEneBm9MericarolMovementParameters *)movementParameters)->move.turn_speed);
            check_collisions();
            return;
        case 1:
            fn_802CE510(this);
            hit_wall = 0;
            sync_center_position();
            if (this->enemy_probe_wall_ahead(destination_direction.x, destination_direction.z, 30.0f * m_444) != NULL) {
                hit_wall = 1;
            }
            move_clamped_on_ground(destination_direction.x, destination_direction.z, m_444);
            if (has_move_failures(1) != 0) {
                hit_wall = 1;
            }
            update_enemy_collision_flags();
            if (bodies->flags & 0x200000) {
                hit_wall = 1;
            }
            check_attack_hits();
            m_4a8 = m_4a8 + m_444;
            if (m_4a8 >= 200.0f) {
                hit_wall = 1;
            }
            if (hit_wall != 0) {
                m_490 = 2;
                m_494 = 0;
                m_438 &= ~0x20;
                set_field_378(3);
                return;
            }
            break;
        case 2:
            m_494 = m_494 + 1;
            m_4a4 *= 0.9f;
            if (m_494 >= 0xA) {
                requested_action = 3;
                m_490 = 3;
            }
            check_collisions();
            move_clamped_on_ground(destination_direction.x, destination_direction.z, m_4a4);
            return;
        }
        break;
    case 5:
        m_438 &= ~0x20;
        bodies->flags &= ~0x700;
        clear_field_388();
        break;
    }
}

s32 TObjEneBm9Mericarol::check_attack_hits() {
    s32 ret;
    s32 i;
    TObjChara *p;
    ret = 0;
    TObjPlayer::init_all_slots();
    check_object_collisions();
    if (bodies->flags & 0x80000) {
        ret = 1;
        for (i = 0; i < 16; i++) {
            p = (TObjChara *)TObjPlayer::get_battle_param(i);
            if (p == NULL) {
                break;
            }
            if (obj_is_hit_receivable((u8 *)p) != 0 && attack_target_history_add(m_488, p) != 0) {
                DirectAttackPayload t;
                t.kind = 0;
                t.power = mericarol_phase_param_table[get_phase()]->m_0;
                DirectAttackPayload payload = t;
                if (p->receive_direct_attack(this, payload, 0, -1, -1) > 0.0f) {
                    obj_setFlags30(p, 0x600);
                }
            }
        }
    }
    return ret;
}

void TObjEneBm9Mericarol::sub_802CF4F8(s32 arg1) {
    s32 count;
    TObjPlayer *target;
    switch (arg1) {
    case 4:
        requested_action = 2;
        clear_intangible();
        set_invulnerable();
        sub_802D093C();
        m_438 &= ~8;
        m_438 |= 0x20;
        m_490 = 0;
        m_494 = 0;
        return;
    case 3:
        if (m_490 >= 0x1E) {
            transition_enemy_state(3);
        }
        return;
    case 0:
        advance_animation();
        count = m_490;
        if (count == 6) {
            target = find_nearby_target();
            if (target != NULL) {
                new TObjEneBm9Mericarol_EffCurse3(this, target);
                current_target = target;
                m_494 = 1;
                play_sound_effect(remap_sound_for_area(0x3A808), &position, 0, 0);
            }
        } else if (count == 0x19 && m_494 != 0 && current_target->is_alive() != 0) {
            ((TObjPlayer *)current_target)->set_tp(0);
        }
        m_490++;
        update_ground_contact();
        update_body_colliders();
        sub_802D073C();
        return;
    case 5:
        actorFlags &= ~0x4000000;
        m_438 &= ~2;
        break;
    }
}

void TObjEneBm9Mericarol::sub_802CF368(s32 arg1) {
    s16 max;
    s16 cur;
    switch (arg1) {
    case 4:
        requested_action = 5;
        clear_intangible();
        sub_802D093C();
        m_438 &= ~0x28;
        TBoss8Dragon__sub_800BB7D4(this, 0xF2);
        play_sound_effect(remap_sound_for_area(0x3AA0C), &position, 0, 0);
        return;
    case 3:
        if (get_flag_b4() != 0) {
            max = hpmax;
            cur = hp;
            if (cur <= max / 2 && cur >= max / 5 && random_ratio() <= m_440) {
                transition_enemy_state(6);
                return;
            }
            if (random_ratio() < 0.05f) {
                transition_enemy_state(7);
                return;
            }
            transition_enemy_state(next_mode);
        }
        return;
    case 0:
        advance_animation();
        update_ground_contact();
        update_body_colliders();
        sub_802D073C();
        return;
    case 5:
        actorFlags &= ~0x200;
        m_438 &= ~2;
        clear_attack_receipts();
        break;
    }
}

void TObjEneBm9Mericarol::state_burrow(s32 arg1) {
    f32 x;
    Vec pos;
    switch (arg1) {
    case 4:
        requested_action = 6;
        clear_intangible();
        sub_802D093C();
        m_438 &= ~0x28;
        refresh_and_send_entity_flags();
        TBoss8Dragon__sub_800BB7D4(this, 0xF2);
        m_490 = 0;
        m_4a4 = 0.0f;
        play_sound_effect(remap_sound_for_area(0x3AA0B), &position, 0, 0);
        return;
    case 3:
        if (m_490 == 2) {
            transition_enemy_state(0xC);
        }
    case 5:
        return;
    case 0:
        switch (m_490) {
        case 0:
            advance_animation();
            if (get_flag_b4() != 0) {
                m_490 = 1;
                x = 10.0f * sin_table_lookup(rotation_y);
                pos.y = 0.0f;
                pos.x = x;
                pos.z = 10.0f * cos_table_lookup(rotation_y);
                vec3_add_to(&pos, &position);
                TObjPlayer::spawn_dead_spot_here((saddr)&pos, 0x32);
                ((TObjPlayer *)&pos)->spawn_ground_effect(0x46);
            }
            update_ground_contact();
            return;
        case 1:
            position.y -= 0.1f;
            m_4a4 += 0.1f;
            if (m_4a4 > 30.0f) {
                m_490 = 2;
            }
            break;
        }
        break;
    }
}

void TObjEneBm9Mericarol::handle_state_message(s32 msg) {
    switch (msg) {
    case 0:
        return;
    case 3:
        queue_destruction();
        return;
    }
}

void TObjEneBm9Mericarol::handle_motion_event(s32 arg1) {
    switch (arg1) {
    case 4:
        requested_action = 7;
        clear_intangible();
        sub_802D093C();
        m_438 &= ~0x28;
        set_field_378(3);
        m_490 = 0;
        play_sound_effect(remap_sound_for_area(0x3AD0F), &position, 0, 0);
        return;
    case 3:
        if (is_passing_frame(frame_count - 1.0f) != 0) {
            transition_enemy_state(3);
        }
        update_ground_contact();
        update_body_colliders();
        return;
    case 0:
        advance_animation();
        m_490 = m_490 + 1;
        sub_802D073C();
        return;
    case 5:
        m_438 &= ~2;
    case 1:
        return;
    }
}

void TObjEneBm9Mericarol::sub_802CEDA0(s32 arg1) {
    Vec pos;
    switch (arg1) {
    case 4:
        requested_action = 2;
        set_field_378(3);
        m_438 &= ~8;
        m_438 |= 0x20;
        m_490 = 0;
        m_494 = mericarol_phase_param_table[get_phase()]->m_24;
        break;
    case 3:
        switch (m_490) {
        case 3:
            transition_enemy_state(3);
            break;
        case 2:
            transition_enemy_state(8);
            break;
        }
        break;
    case 0:
        advance_animation();
        switch (m_490) {
        case 0:
            m_494--;
            if (m_494 <= 0) {
                f32 lim = mericarol_phase_param_table[get_phase()]->m_14;
                if (random_ratio() <= lim) {
                    m_490 = 2;
                } else {
                    requested_action = 0;
                    m_490 = 1;
                }
            }
            if (enemy_validate_retained_target(this) != 0) {
                enemy_copy_target_destination();
                update_velocity();
            }
            check_collisions();
            if (m_494 % 14 == 0) {
                play_sound_effect(remap_sound_for_area(0x3A809), &position, 0, 0);
            }
            break;
        case 1:
            if (is_passing_frame(10.0f) != 0) {
                VecCopy(&pos, &position);
                pos.y += 20.0f;
                ((void (*)(void *, void *, s32, s32, s32, f32, s32, f32))create__9TTecKafunFllllllff)(this, &pos, 5, 0x20B, 0x20C,
                    mericarol_phase_param_table[get_phase()]->m_4, get_clamped_level(),
                    mericarol_phase_param_table[get_phase()]->m_10);
                play_sound_effect(remap_sound_for_area(0x3A80A), &position, 0, 0);
            }
            if (get_flag_b4() != 0) {
                m_490 = 3;
            }
            break;
        }
        break;
    case 5:
        break;
    }
}

s32 TObjEneBm9Mericarol::get_clamped_level() {
    Sub_800ACA10 *p = (Sub_800ACA10 *)m_2b0;
    s32 v = 0;
    if (p != 0) {
        v = p->level;
        if (v < 0) {
            return 0;
        }
        if (game_difficulty_selection == 3) {
            if (v > 0x1D) {
                v = 0x1D;
            }
            return v;
        }
        if (v > 0xE) {
            v = 0xE;
        }
    }
    return v;
}

void TObjEneBm9Mericarol::sub_802CED40() {
    m_438 |= 2;
}

void TObjEneBm9Mericarol::run_demo_task() {  }

void TObjEneBm9Mericarol::update_particle_effect(NJS_OBJECT *) {
    switch (lbl_805D686C) {
    case 0x21:
    case 0x2B:
    case 0x64:
        TParticleCtrl::begin_effect_render();
        break;
    default:
        TParticleCtrl::end_effect_render();
        break;
    }
    lbl_805D686C += 1;
}

void TObjEneBm9Mericarol::render() {
    s32 vis;
    RenderFadeState *fade;
    s16 saved;
    s32 detail;
    s32 cam;
    u32 s0;
    u32 s1;
    u32 s2;
    s16 *plist;
    if (TObjPlayer::check_demo_mode() != 0) {
        draw_color_variant();
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_mode();
    }
    fade = &m_3c8[cam];
    fade->update();
    vis = fade->updateFromCamera(&body_center.x);
    if (this->mode == 0xC) {
        return;
    }
    if (TObjEneDD::is_main_phase_15() != 0) {
        if (get_current_floor_area() == AREA_TOWER) {
            detail = classify_actor_view_detail(600.0f, 600.0f, 20.0f);
        } else {
            detail = classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, 20.0f);
        }
    } else if (update_object_view_visibility(400.0f, 20.0f) != 0) {
        detail = 1;
    } else {
        detail = 0;
    }
    if (detail == 0) {
        return;
    }
    if (this->mode != 0xB) {
        Vec v = { 2.0f, 1.0f, 2.0f };
        draw_ground_shadow(&v, 0);
    }
    update_secondary_light();
    switch (get_phase()) {
    case 1:
        s0 = ((NJS_TEXLIST *)texlist)->textures[0].texaddr;
        s1 = ((NJS_TEXLIST *)texlist)->textures[1].texaddr;
        s2 = ((NJS_TEXLIST *)texlist)->textures[2].texaddr;
        ((NJS_TEXLIST *)texlist)->textures[0].texaddr = ((NJS_TEXLIST *)texlist)->textures[3].texaddr;
        ((NJS_TEXLIST *)texlist)->textures[1].texaddr = ((NJS_TEXLIST *)texlist)->textures[4].texaddr;
        ((NJS_TEXLIST *)texlist)->textures[2].texaddr = ((NJS_TEXLIST *)texlist)->textures[5].texaddr;
        break;
    case 2:
        s0 = ((NJS_TEXLIST *)texlist)->textures[0].texaddr;
        s1 = ((NJS_TEXLIST *)texlist)->textures[1].texaddr;
        s2 = ((NJS_TEXLIST *)texlist)->textures[2].texaddr;
        ((NJS_TEXLIST *)texlist)->textures[0].texaddr = ((NJS_TEXLIST *)texlist)->textures[6].texaddr;
        ((NJS_TEXLIST *)texlist)->textures[1].texaddr = ((NJS_TEXLIST *)texlist)->textures[7].texaddr;
        ((NJS_TEXLIST *)texlist)->textures[2].texaddr = ((NJS_TEXLIST *)texlist)->textures[8].texaddr;
        break;
    }
    saved_model_render_flags = model_render_flags;
    TObjFish::set_global_param(texlist);
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    set_alpha_ref_override(0);
    TObjEneDD::clear_global_flag_400();
    translate_matrix(0, 0.0f, m_43c, 0.0f);
    lbl_805D686C = 0;
    TObjPlayer::toggle_particle_effect();
    if (!(m_438 & 0x10)) {
        plist = ((NJS_CNK_MODEL *)((NJS_OBJECT *)model)->child->sibling->sibling->sibling->model)->polygon_list;
        saved = plist[5];
        plist[5] = (u8)plist[5];
        set_chunk_model_node_callback(TObjEneBm9Mericarol::update_particle_effect);
    }
    if (m_438 & 8) {
        if (m_46c.has_visible_opacity() != 0) {
            m_46c.set_flags_and_apply_damage_color();
            if (defer_render() == 0) {
                draw();
            }
            m_46c.clear_flag_and_notify();
        }
    } else if (vis != 0) {
        fade->set_flags_and_apply_damage_color();
        if (defer_render() == 0) {
            if (detail == 1) {
                draw();
            } else {
                draw_motion_model();
            }
        }
        fade->clear_flag_and_notify();
    } else if (detail == 1) {
        draw();
    } else {
        draw_motion_model();
    }
    if (!(m_438 & 0x10)) {
        set_chunk_model_node_callback(NULL);
        ((NJS_CNK_MODEL *)((NJS_OBJECT *)model)->child->sibling->sibling->model)->polygon_list[5] = saved;
    }
    TParticleCtrl::end_effect_render();
    restore_alpha_ref();
    pop_matrix();
    model_render_flags = saved_model_render_flags;
    update_primary_light();
    if (get_phase() != 0) {
        ((NJS_TEXLIST *)texlist)->textures[0].texaddr = s0;
        ((NJS_TEXLIST *)texlist)->textures[1].texaddr = s1;
        ((NJS_TEXLIST *)texlist)->textures[2].texaddr = s2;
    }
}

void TObjEneBm9Mericarol::draw_color_variant() {
    u32 s0;
    u32 s1;
    u32 s2;
    if (update_object_view_visibility(400.0f, 20.0f) != 0) {
        Vec v = { 2.0f, 1.0f, 2.0f };
        draw_ground_shadow(&v, 0);
        switch (variant) {
        case 1:
            s0 = ((NJS_TEXLIST *)texlist)->textures[0].texaddr;
            s1 = ((NJS_TEXLIST *)texlist)->textures[1].texaddr;
            s2 = ((NJS_TEXLIST *)texlist)->textures[2].texaddr;
            ((NJS_TEXLIST *)texlist)->textures[0].texaddr = ((NJS_TEXLIST *)texlist)->textures[3].texaddr;
            ((NJS_TEXLIST *)texlist)->textures[1].texaddr = ((NJS_TEXLIST *)texlist)->textures[4].texaddr;
            ((NJS_TEXLIST *)texlist)->textures[2].texaddr = ((NJS_TEXLIST *)texlist)->textures[5].texaddr;
            break;
        case 2:
            s0 = ((NJS_TEXLIST *)texlist)->textures[0].texaddr;
            s1 = ((NJS_TEXLIST *)texlist)->textures[1].texaddr;
            s2 = ((NJS_TEXLIST *)texlist)->textures[2].texaddr;
            ((NJS_TEXLIST *)texlist)->textures[0].texaddr = ((NJS_TEXLIST *)texlist)->textures[6].texaddr;
            ((NJS_TEXLIST *)texlist)->textures[1].texaddr = ((NJS_TEXLIST *)texlist)->textures[7].texaddr;
            ((NJS_TEXLIST *)texlist)->textures[2].texaddr = ((NJS_TEXLIST *)texlist)->textures[8].texaddr;
            break;
        }
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        set_alpha_ref_override(0);
        draw_chunk_object(model);
        restore_alpha_ref();
        TParticleCtrl::end_effect_render();
        pop_matrix();
        if (variant == 1 || variant == 2) {
            ((NJS_TEXLIST *)texlist)->textures[0].texaddr = s0;
            ((NJS_TEXLIST *)texlist)->textures[1].texaddr = s1;
            ((NJS_TEXLIST *)texlist)->textures[2].texaddr = s2;
        }
    }
}

void TObjEneBm9Mericarol::sub_802CE68C(Vec *out, s32 node) {
    set_motion_packed_rotation();
    push_matrix_from(&identity_matrix);
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    set_motion_packed_rotation();
    calc_joint_matrices(frame);
    clear_motion_packed_rotation();
    pop_matrix();
    push_matrix_from(anim_model_matrix_array[node]);
    Vec v = { 0.0f, 0.0f, 0.0f };
    matrix_mult_vec(0, &v, out);
    pop_matrix();
    clear_motion_packed_rotation();
}

void fn_802CE510(TObjEneBm9Mericarol *owner) {
    Vec origin;
    VecCopy(&origin, &owner->position);
    origin.y += 15.0f;

    CsnHit *hit = csnVectorUnder(&origin, (CsnGroup **)&owner->m_120, 0x15);
    if (hit != NULL) {
        u32 surface_mask = hit->hit_mask & 4;
        if (surface_mask != 0) {
            fn_800D8830(owner, &owner->position);
        } else {
            play_persistent_sound(owner->remap_sound_for_area(0x3B211), (saddr)owner, (uaddr)&owner->position, 0, 0);
        }
        if (owner->is_passing_frame(5.0f) != 0 || owner->is_passing_frame(15.0f) != 0 ||
            owner->is_passing_frame(25.0f) != 0) {
            if (surface_mask != 0) {
                TParticleCtrl *spray = (TParticleCtrl *)spawn_particle_effect(&hit->contact[2].point, 0x49);
                if (spray != NULL) {
                    attach_particle_model((u8 *)spray, TParticleCtrl::get_particle_model(2),
                                          TParticleCtrl::get_instance(), 0, 1, 1.0f);
                    spray->set_scale(5.0f, 1.0f);
                }
                TParticleCtrl *ripple = (TParticleCtrl *)spawn_particle_effect(&hit->contact[2].point, 0xA4);
                if (ripple != NULL) {
                    ripple->set_scale(5.0f, 1.5f);
                }
            } else {
                TParticleCtrl *dust = (TParticleCtrl *)spawn_particle_effect(&owner->position, 0xF3);
                if (dust != NULL) {
                    dust->set_scale(5.0f, 2.0f);
                }
            }
        }
    }
}
