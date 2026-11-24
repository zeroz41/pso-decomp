#include "types.h"
#include "pso/player/TObjPlayer_8002E784.h"
#include "pso/boss/derolle/TBoss2Joint.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/boss/TUnk_80482C58.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TUnk_804820A8.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TRaderMapCore.h"

extern "C" {
}

// The movement parameters init_params installs.
struct TBoss2JointMovement {
    f32 pad_0;
    s32 pad_4;
    s32 pad_8;
    s32 pad_c[4];
};

// The colour a flash fades back to (update_flash_color reads r, g and b).
static const NJS_ARGB joint_base_color = {1.0f, 1.0f, 1.0f, 1.0f};
// The colours start_flash fades from: [0] a hit on the shell, [1] a photon pad spawning at the joint.
static const NJS_ARGB TBoss2Joint__joint_offset_vec4_table[2] = {
    {1.0f, 0.0f, 1.0f, 1.0f},
    {1.0f, 0.0f, 1.0f, 0.0f},
};
const char *TBoss2Joint__name = "TBoss2Joint";
static const u32 joint_white_rgb = 0x00FFFFFF;

// Lobby stat ids, [0] for the intact shell and [1] for the broken one: register_boss,
// dispatch_shared_handler_b and register_object read one table each.
__declspec(section ".data") s32 TBoss2Joint__param_table[2] = {0x10, 0x10};
__declspec(section ".data") s32 TBoss2Joint__attack_stats[2] = {0xF, 0xF};
__declspec(section ".data") s32 TBoss2Joint__resistance_stats[2] = {0x10, 0x10};
TBoss2JointMovement TBoss2Joint__movement = {225.0f, 0, 0x600};
CollisionBody TBoss2Joint__body = {{0.0f, 0.0f, 0.0f}, 50.0f, 0.0f, 0, 0x8003};

void TBoss2Joint::render() {}
void TBoss2Joint::handle_state_0(s32 reason) {}

void TBoss2Joint::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        handle_state_0(reason);
        break;
    }
}

// Writes color into the segment's materials; a broken shell draws with its alpha.
void TBoss2Joint::apply_flash_color() {
    u32 c;
    TBoss2JointMaterial *mat;
    u32 low_mask = ~0xFF000000;
    if (joint_flags & SHELL_BROKEN) {
        c = color;
        mat = body_material;
        mat->diffuse = ((((c >> 16) & low_mask) | ((c << 16) & 0xFF000000)) & ~0xFF0000) | ((c << 16) & 0xFF0000);
        mat->strip_head |= 0x800;
        ((s16 *)mat)[-2] = 0x2517;
        rim_material->diffuse = (rim_material->diffuse & ~0xFF00) | ((color >> 16) & 0xFF00);
        return;
    }
    c = color;
    mat = body_material;
    mat->diffuse = ((((c >> 16) & low_mask) | ((c << 16) & 0xFF000000)) & ~0xFF0000) | ((c << 16) & 0xFF0000);
    mat->strip_head &= ~0x800;
    ((s16 *)mat)[-2] = 0x2517;
    rim_material->diffuse |= 0xFF00;
}

void TBoss2Joint::start_pad_flash() { start_flash(1); }

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TBoss2Joint::update_flash_color() {
    f32 t;
    if (joint_flags & SHELL_BROKEN) {
        unk_3a4 = 0.0f;
        color = 0;
        return;
    }
    color = 0xFF000000;
    t = flash;
    if (t > 0.0f) {
        f32 a = 255.0f * t;
        f32 b = 255.0f * (1.0f - t);
        color |= ((u32)(joint_base_color.r * b + flash_color.r * a) << 16) & 0xFF0000;
        color |= ((u32)(joint_base_color.g * b + flash_color.g * a) << 8) & 0xFF00;
        color |= (u8)(u32)(joint_base_color.b * b + flash_color.b * a);
        flash -= 0.05f;
        if (flash < 0.0f) {
            flash = 0.0f;
        }
    } else {
        color |= joint_white_rgb;
    }
}
#pragma pop

void TBoss2Joint::start_flash(s32 kind) {
    flash = 1.0f;
    copy_argb(&flash_color, (NJS_ARGB *)&TBoss2Joint__joint_offset_vec4_table[kind]);
}

// Breaks the shell: marks it broken, reloads the broken stats and throws the breakup pieces.
void TBoss2Joint::break_shell() {
    joint_flags |= SHELL_BROKEN;
    reload_stats_keep_hp_tp(TLobby::register_boss(TBoss2Joint__param_table[1]),
                            TLobby::dispatch_shared_handler_b(TBoss2Joint__attack_stats[1]),
                            TLobby::register_object(TBoss2Joint__resistance_stats[1]));
    hp = 0x4E20;
    hpmax = 0x4E20;
    new TUnk_804820A8(this, &position);
}

void TBoss2Joint::enable_body_collision() {
    if (bodies->flags & 6) {
        TObjEneDD::enable_body_collision();
        return;
    }
    TObjEneDD::disable_body_collision();
}

void TBoss2Joint::update_body_colliders() {
    if (position.y < boss2_water_level - 50.0f) {
        TObjEneDD::disable_body_collision();
        bodies->flags &= ~6;
    } else {
        TObjEneDD::enable_body_collision();
        if (position.y >= 30.0f) {
            set_colliders_contact_high();
        } else {
            set_colliders_contact_low();
        }
    }
    transform_part_positions();
}

void TBoss2Joint::update_position_history() {
    VecCopy(&body_center, &position);
    VecCopy(&center, &body_center);
}

void TBoss2Joint::run_miss_reaction() {}

void TBoss2Joint::run_hit_reaction() {
    s32 damage = hpmax - hp;
    if (!(joint_flags & SHELL_BROKEN)) {
        start_flash(0);
        shell_hp -= damage;
        if (shell_hp <= 0) {
            shell_hp = 0;
            break_shell();
        }
    } else {
        TBoss2DeRolLe::spawn_offset_particle(&position, 15.0f, 12.0f);
        ((TBoss2DeRolLe *)m_up)->apply_hp_damage_with_sound(damage, attacker_id);
    }
    hp = hpmax;
    clear_attack_receipts();
}

void TBoss2Joint::run_death_reaction() { actorFlags &= 0xfffff7ff; }
void TBoss2Joint::refresh_target() {}

void TBoss2Joint::run_task() {
    if (TObjPlayer::check_demo_mode() == 0) {
        VecCopy(&position, anchor);
        update_status_effects();
        if (has_action_state_changed() == 0) {
            dispatch_action(mode, 3);
        }
        dispatch_action(mode, 0);
        sub_800BBA0C();
        update_flash_color();
        update_position_history();
        update_body_colliders();
        submit_default_cursor_candidate();
        add_radar_scaled_marker(&position, -0x5DB4, 1, 1, 1.2f);
    }
}

TBoss2Joint::~TBoss2Joint() {
    free_collision_body_parts(this);
}

#pragma push
#pragma opt_propagation off
void TBoss2Joint::init_params() {
    init_position_vectors();
    model = NULL;
    texlist = 0;
    init_model(&TBoss2Joint__body, 1);
    reset_hp(TLobby::register_boss(TBoss2Joint__param_table[0]), TLobby::dispatch_shared_handler_b(TBoss2Joint__attack_stats[0]),
             TLobby::register_object(TBoss2Joint__resistance_stats[0]));
    hp = 0x4E20;
    hpmax = 0x4E20;
    set_state_flag_2();
    movementParameters = &TBoss2Joint__movement;
    referenceHp = hpmax;
    wall_reach = 3.0f;
    clear_intangible();
    mode = 0;
    dispatch_action(mode, 4);
    joint_flags = 0;
    shell_hp = TBoss2DeRolLe::get_shell_max_hp();
    color = 0xFFFFFFFF;
    unk_3a4 = 1.0f;
    flash = 0.0f;
    copy_argb(&flash_color, (NJS_ARGB *)TBoss2Joint__joint_offset_vec4_table);
}
#pragma pop

TBoss2Joint::TBoss2Joint(TObject *parent, u16 entity_id, s32 set_index, const Vec *anchor, saddr body_material,
                         saddr rim_material)
    : TObjEneDD(parent) {
    m_name = TBoss2Joint__name;
    init_common_from(static_cast<TObjBase *>(parent));
    this->entity_id = entity_id;
    this->set_index = set_index;
    this->anchor = anchor;
    this->body_material = (TBoss2JointMaterial *)body_material;
    this->rim_material = (TBoss2JointMaterial *)rim_material;
    initialize_enemy_state(0x2D);
    init_params();
}

void TBoss2Joint::apply_poison_status() {}
void TBoss2Joint::apply_paralysis() {}
void TBoss2Joint::apply_slow_status() {}
void TBoss2Joint::apply_confusion_status() {}
void TBoss2Joint::apply_movement_ailment(s32) {}
void TBoss2Joint::apply_shock_status() {}
void TBoss2Joint::clear_harmful_statuses() {}

void TUnk_80482C58::run_task() {
    if (m_particle == NULL) {
        m_particle = spawn_continuous_particle_effect_with_flags(m_points, m_effect_id, 0x40);
        if (m_particle != NULL) {
            m_particle->enable();
        }
    } else {
        switch (m_state) {
        case 0:
            if (m_head >= m_limit) {
                m_state = 1;
                m_cur = 0;
            }
            m_particle->enable();
            break;
        case 1:
            m_particle->set_position(&m_points[m_cur]);
            m_cur++;
            if (m_cur >= NUM_POINTS) {
                m_cur = 0;
            }
            if (m_cur == m_head) {
                m_state = 2;
            }
            break;
        case 2:
            m_particle->enable();
            break;
        }
    }
}
