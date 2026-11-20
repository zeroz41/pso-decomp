#include "pso/boss/derolle/TBoss2Mine.h"
#include "pso/system/vector.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/boss/derolle/TUnk_80482EC0.h"
#include "pso/boss/derolle/TUnk_80482D04.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/particle/TParticleCtrl_800867E4.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/dd/TObjEneDD_800BA138.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/model_render_state.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803E2D70.h"

struct TBoss2MineMovement {
    f32 m_0;
    f32 m_4;
    s32 m_8;
    s32 m_c[4];
};

// The mine's attack template: vfunc_107 copies it, sets +0x04 and hands it to
// TObjEneDD__sub_800BA5A4, whose setup_instance installs +0x08 as the collision radius.
struct TBoss2MineCollisionDesc {
    s32 value;
    f32 pad_04;
    f32 pad_08;
    f32 pad_0c;
    s32 pad_10;
};

// Copied as five words, which gives the original's copy loop.
struct TBoss2MineCollisionWords {
    s32 w[5];
};

// TObjEneDD.h declares vfunc_86 as returning u8, but this caller tests the full word.
struct TBoss2MineStateCheck {
    u8 unk_0[0x18];
#define V(n) virtual void unused_##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38)
    V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57)
    V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76)
    V(77) V(78) V(79) V(80) V(81) V(82) V(83)
#undef V
    virtual s32 vfunc_86();
};

static const TBoss2MineCollisionDesc boss2_mine_collision_desc = { 1, 2.0f, 50.0f, 5.0f, 1 };

const char *TBoss2Mine__name = "TBoss2Mine";

const Vec lbl_80435AD0 = { 2.0f, 1.0f, 2.0f };

const NJS_ARGB boss2_mine_render_color = { 0.0f, 0.0f, 0.0f, 0.0f };

extern "C" {

f32 atan2_float(f32 y, f32 x);

f32 newton_sqrtf(s32, f32, f32, f32);

extern void *lbl_805D28BC;

extern u8 *lbl_805D4BA4;

void free_collision_body_parts(void *);

__declspec(section ".data") s32 boss2_mine_params[2] = { 0x11, 0x11 };

__declspec(section ".data") s32 lbl_80482C90[2] = { 0xF, 0xF };

__declspec(section ".data") s32 lbl_80482C98[2] = { 0x11, 0x11 };

TBoss2MineMovement lbl_80482CA0[2] = {
    { 225.0f, 0.0f, 0x600, { 0, 0, 0, 0 } },
    { 225.0f, 0.0f, 0x600, { 0, 0, 0, 0 } },
};

CollisionBody lbl_80482CD8 = {
    { 0.0f, 0.0f, 0.0f }, 5.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f,
};

}

#pragma inline_depth(1)

void TBoss2Mine::apply_defense_stat_status(void *) {  }

void TBoss2Mine::apply_attack_stat_status(void *) {  }

void TBoss2Mine::clear_harmful_statuses() {  }

void TBoss2Mine::apply_shock_status() {  }

void TBoss2Mine::apply_movement_ailment(s32) {  }

void TBoss2Mine::apply_confusion_status() {  }

void TBoss2Mine::apply_slow_status() {  }

void TBoss2Mine::apply_paralysis() {  }

void TBoss2Mine::apply_poison_status() {  }

extern "C" void TBoss2Mine__sub_80038D88(void) { TObjPlayer__sub_800F0928(); }

extern "C" void TBoss2Mine__sub_80038D84(void) {  }

TBoss2Mine::TBoss2Mine(TObject *parent, u16 entity_id, s32 set_index, s32 variant) : TObjEneDD(parent) {
    s32 boss;
    m_name = TBoss2Mine__name;
    boss = get_instance__13TBoss2DeRolLeFv();
    if (boss != 0) {
        init_common_from((u8 *)boss);
    }
    this->entity_id = entity_id;
    this->set_index = set_index;
    init__10TBoss2MineFPvi(this, variant);
}

extern "C" {

void init__10TBoss2MineFPvi(TBoss2Mine *self, s32 variant) {
    u8 *res;
    self->init_position_vectors();
    self->model = *(void **)(*(u8 **)(lbl_805D4BA4 + 0x42C) + 0x38);
    res = *(u8 **)(lbl_805D4BA4 + 0x42C);
    self->texlist = *(s32 *)(res + 0x2C);
    self->init_model(&lbl_80482CD8, 1);
    self->reset_hp((u8 *)TLobby::register_boss(boss2_mine_params[variant]),
                   (u8 *)TLobby::dispatch_shared_handler_b(lbl_80482C90[variant]),
                   (u8 *)TLobby::register_object(lbl_80482C98[variant]));
    self->check_state_flag_2();
    self->movementParameters = &lbl_80482CA0[variant];
    self->m_37c = 3.0f;
    self->vfunc_95();
    self->m_38c = 0;
    self->m_390.x = 0.0f;
    self->m_390.y = 0.0f;
    self->m_390.z = 0.0f;
    self->m_39c.x = 0.0f;
    self->m_39c.y = 0.0f;
    self->m_39c.z = 0.0f;
    self->m_3a8 = 0;
    self->m_3ac = 0.0f;
    self->m_3b0 = 0;
    self->m_3b4 = 0.0f;
    self->m_3b8 = 0.0f;
    self->m_3bc = 0;
    self->m_3c0 = 0;
    self->m_3c4 = 2;
    self->m_3c8 = 0;
    self->m_3cc = 0;
    self->m_3d0 = 0;
    self->m_3d8 = 0;
    self->m_3dc = 0.0f;
    self->m_3e0 = 0.0f;
    self->m_3e4 = 0.0f;
    self->m_3e8 = 0.0f;
    self->m_3ec = 0.0f;
    self->mode = 0;
    self->dispatch_action(self->mode, 4);
}

}

TBoss2Mine::~TBoss2Mine() {
    free_collision_body_parts(this);
}

void TBoss2Mine::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        vfunc_109();
        return;
    }
    vfunc_83();
    if (((TBoss2MineStateCheck *)this)->vfunc_86() == 0) {
        dispatch_action(mode, 3);
    }
    dispatch_action(mode, 0);
    sub_800BBA0C();
    if (!(m_38c & 1)) {
        save_position();
        vfunc_88();
        submit_default_cursor_candidate();
        vfunc_100();
    }
    refresh_collision_body_centers();
}

void TBoss2Mine::vfunc_28() {  }

void TBoss2Mine::vfunc_63() {
    if (mode != 4) {
        transition_enemy_state(4);
    }
}

void TBoss2Mine::vfunc_62() { clear_attack_receipts(); }

void TBoss2Mine::vfunc_61() {  }

void TBoss2Mine::save_position() { VecCopy(&center, body_center()); }

void TBoss2Mine::update_move_flag() {
    position.x = m_2fc;
    position.z = m_304;
    if (vfunc_102() == 0) {
        m_38c &= ~2;
        return;
    }
    m_38c |= 2;
}

void TBoss2Mine::set_node_offsets() {
    NJS_OBJECT *node = ((NJS_OBJECT *)model)->child;
    s32 i;
    s32 angle = -m_3a8;
    for (i = 0; i < 4; i++) {
        node->ang[0] = angle;
        node = node->sibling;
    }
    angle = m_3a8;
    for (i = 0; i < 4; i++) {
        node->ang[0] = angle;
        node = node->sibling;
    }
}

void TBoss2Mine::init_params(s32 arg1, f32 farg0) {
    m_3b8 = farg0;
    m_3c0 = arg1;
    m_3c4 = 0;
    m_3b4 = 0.0f;
    m_3bc = 0;
}

void TBoss2Mine::set_state_by_distance(s32 arg1) {
    if (arg1 < 90) {
        f32 speed = 0.5f;
        m_3c0 = 3;
        m_3b8 = speed;
        return;
    }
    if (arg1 < 150) {
        m_3c0 = 5;
        return;
    }
    if (arg1 < 300) {
        m_3c0 = 10;
        return;
    }
    m_3c0 = 30;
}

void TBoss2Mine::update_pulse_state() {
    m_3bc++;
    switch (m_3c4) {
    case 2:
        if (m_3bc >= m_3c0) {
            m_3bc = 0;
            m_3b4 = 0.0f;
            m_3c4 = 0;
        } else {
            m_38c &= ~4;
            break;
        }
    case 0:
        m_3b4 += m_3b8;
        if (m_3b4 >= 1.0f) {
            m_3b4 = 1.0f;
            m_3c4 = 1;
        }
        m_3b0 = (s32)(255.0f * m_3b4) << 16;
        m_38c |= 4;
        break;
    case 1:
        m_3b4 -= m_3b8;
        if (m_3b4 <= 0.0f) {
            m_3b4 = 0.0f;
            m_3bc = 0;
            m_3c4 = 2;
        }
        m_3b0 = (s32)(255.0f * m_3b4) << 16;
        m_38c |= 4;
        break;
    case 3:
        break;
    }
}

void TBoss2Mine::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        vfunc_104(reason);
        return;
    case 1:
        vfunc_105(reason);
        return;
    case 2:
        vfunc_106(reason);
        return;
    case 3:
        vfunc_107(reason);
        return;
    case 4:
        vfunc_108(reason);
        return;
    }
}

void TBoss2Mine::vfunc_104(s32 reason) {
    u32 flags;

    switch (reason) {
    case 4:
        vfunc_95();
        m_38c |= 1;
        m_38c &= ~6;
        return;
    case 3:
        flags = m_38c;
        if (flags & 0x100) {
            m_38c = flags & ~0x100;
            transition_enemy_state(1);
        }
    case 5:
    case 0:
        return;
    }
}

void TBoss2Mine::vfunc_105(s32) {  }

void TBoss2Mine::vfunc_106(s32) {  }

void TBoss2Mine::vfunc_107(s32 reason) {
    TBoss2MineCollisionDesc hit;
    switch (reason) {
    case 4:
        vfunc_96();
        m_38c &= ~7;
        m_3b0 = 0;
        m_3c8 = 0;
        m_3cc = 0;
        create_timed_particle_emitter(&bodies->center, 0x16A, 0, 6);
        return;
    case 3:
        if (m_3cc == 2) {
            transition_enemy_state(0);
        }
    case 5:
        return;
    case 0:
        m_3c8++;
        if (m_3c8 > 30) {
            *(TBoss2MineCollisionWords *)&hit = *(const TBoss2MineCollisionWords *)&boss2_mine_collision_desc;
            hit.pad_04 = TBoss2DeRolLe__sub_80034CEC();
            TObjEneDD__sub_800BA5A4(this, &hit);
            spawn_particle_effect_with_flags(&bodies->center, 0x16B, 0x40);
            m_3cc = 2;
            play_sound_effect(0x4003AD05, body_center(), 0, 0);
        }
        break;
    }
}

void TBoss2Mine::vfunc_108(s32 reason) {
    switch (reason) {
    case 4:
        vfunc_96();
        m_38c &= ~7;
        return;
    case 3:
        transition_enemy_state(0);
        return;
    case 5:
        actorFlags &= ~0x800;
        hp = hpmax;
    case 0:
        return;
    }
}

void TBoss2Mine::render() {
    if (TObjPlayer::check_demo_mode() != 0) {
        vfunc_110();
        return;
    }
    if (m_38c & 1) {
        return;
    }
    if (update_object_view_visibility(400.0f, 20.0f) == 0) {
        return;
    }
    if (m_38c & 2) {
        Vec shadow_scale = lbl_80435AD0;
        TObjEnemy::draw_ground_shadow(&shadow_scale, 0);
    }
    TObjFish::set_global_param(texlist);
    saved_model_render_flags = model_render_flags;
    TObjEneDD::clear_global_flag_400();
    TObjPlayer::toggle_particle_effect();
    set_node_offsets();
    push_matrix();
    post_translate_matrix(&position.x);
    translate_matrix(0, 0.0f, m_300 - position.y, 0.0f);
    rotate_matrix_y(NULL, rotation_y);
    rotate_matrix_x(NULL, rotation_x);
    rotate_matrix_y(NULL, rotation_z);
    translate_matrix(0, 0.0f, -10.0f, 0.0f);
    if (m_38c & 4) {
        model_render_flags |= 0x20;
        NJS_ARGB color = boss2_mine_render_color;
        f32 f = -(f32)(m_3b0 >> 16) / 255.0f;
        color.b = f;
        color.g = f;
        color.r = -f;
        set_constant_material(&color);
        draw_chunk_object(model);
    } else {
        draw_chunk_object(model);
    }
    pop_matrix();
    if (mode == 3) {
        push_matrix();
        f32 s = 0.5f * m_3ac;
        post_translate_matrix(&position.x);
        scale_matrix(NULL, s, 3.0f, s);
        draw_chunk_object(lbl_805D28BC);
        pop_matrix();
    }
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
}

void TBoss2Mine::vfunc_109() {  }

void TBoss2Mine::vfunc_110() {  }

TUnk_80482EC0::TUnk_80482EC0(TObject *parent, u16 entity_id, s32 set_index)
    : TBoss2Mine(parent, entity_id, set_index, 0) {}

TUnk_80482EC0::~TUnk_80482EC0() {}

void TUnk_80482EC0::vfunc_88() {
    bodies->offset.y = 5.0f + (m_300 - position.y);
}

void TBoss2Mine::set_launch_position_velocity(u8 *arg1, u8 *arg2) {
    m_38c |= 0x100;
    VecCopy(body_center(), (const Vec *)arg1);
    VecCopy(&m_390, (const Vec *)arg2);
    m_390.y += 1.0f;
    VecCopy(&position, body_center());
    m_3a8 = 0;
    hp = hpmax;
    actorFlags &= ~0xA00;
}

#pragma push
#pragma fp_contract on
void TUnk_80482EC0::vfunc_105(s32 reason) {
    f32 temp_f1;
    f32 y;
    s32 angle;
    switch (reason) {
    case 4:
        vfunc_95();
        m_38c &= ~7;
        VecCopy(&m_39c, &m_390);
        subtract_vector(&m_39c, body_center());
        m_3dc = normalize_vector_xz(&m_39c);
        angle = (s32)(10430.38043493439 * atan2_float(m_39c.x, m_39c.z));
        rotation_y = angle;
        rotation_x = 0x4000;
        y = m_300;
        temp_f1 = newton_sqrtf(angle, (2.0f * (y - m_390.y)) / 0.2f, y, 2.0f);
        m_3e4 = 10.0f * temp_f1;
        m_3ec = 10.0f;
        m_3e8 = 0.0f;
        m_3d8 = 0;
        m_3e0 = m_3dc;
        break;
    case 3:
        if (m_300 < m_390.y) {
            m_300 = m_390.y;
            transition_enemy_state(2);
        }
        break;
    case 5:
        break;
    case 0:
        m_2fc = m_39c.x * m_3ec + m_2fc;
        m_304 = m_39c.z * m_3ec + m_304;
        m_3e0 = m_3e0 - m_3ec;
        if (m_3e0 < m_3e4) {
            m_3e8 = m_3e8 - 0.2f;
            m_300 = m_300 + m_3e8;
            if (rotation_x >= 0x8000) {
                rotation_x = 0x8000;
            } else {
                m_3d8 = m_3d8 + 0x300;
                rotation_x = m_3d8 + 0x4000;
            }
        } else {
            rotation_x = 0x4000;
        }
        update_move_flag();
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TUnk_80482EC0::vfunc_106(s32 reason) {
    u32 flags;
    s32 extra;
    switch (reason) {
    case 4:
        vfunc_96();
        m_38c &= ~5;
        m_38c |= 2;
        rotation_x = 0x8000;
        m_3b0 = 0;
        m_3c8 = 0;
        extra = (s32)(30.0f * calc_elapsed_scaled());
        m_3cc = extra + 180;
        play_sound_effect(0x4003A804, body_center(), 0, 0);
        init_params(30, 0.25f);
        return;
    case 3:
        flags = m_38c;
        if (flags & 0x100) {
            m_38c = flags & ~0x100;
            transition_enemy_state(1);
        }
        if (m_3c8 == 2) {
            transition_enemy_state(3);
        }
        break;
    case 5:
        break;
    case 0:
        switch (m_3c8) {
        case 0:
            m_3a8 = m_3a8 + 0x280;
            if (m_3a8 >= 0x38E3) {
                m_3a8 = 0x38E3;
                m_3c8 = 1;
                return;
            }
            break;
        case 1:
            m_3cc = m_3cc - 1;
            if (m_3cc <= 0) {
                m_3c8 = 2;
            }
            set_state_by_distance(m_3cc);
            update_pulse_state();
            break;
        }
        break;
    }
}
#pragma pop

TUnk_80482D04::TUnk_80482D04(TObject *parent, u16 entity_id, s32 set_index)
    : TBoss2Mine(parent, entity_id, set_index, 1) {
    owner = NULL;
    slot = 0;
    owner_offset.x = 0.0f;
    owner_offset.y = 0.0f;
    owner_offset.z = 0.0f;
    direction.x = 0.0f;
    direction.y = 0.0f;
    direction.z = 0.0f;
}

TUnk_80482D04::~TUnk_80482D04() {}

void TUnk_80482D04::vfunc_88() {
    bodies->offset.y = 1.0f + (m_300 - position.y);
}

void TUnk_80482D04::move_mine() {
    if (owner->is_alive() != 0) {
        VecCopy(&m_390, &owner->position);
        vec3_add_to(&m_390, &owner_offset);
        m_390.y += 17.0f;
    }
}

extern "C" {

void init_launch__10TBoss2MineFPvPvii(TUnk_80482D04 *self, Vec *pos, TObjBase *owner, s32 slot) {
    s32 angle;
    s32 heading;
    self->m_38c |= 0x100;
    VecCopy(self->body_center(), pos);
    self->owner = owner;
    angle = slot * 0x5555;
    self->slot = slot;
    self->owner_offset.x = 20.0f * sin_table_lookup(angle);
    self->owner_offset.y = 0.0f;
    self->owner_offset.z = 20.0f * cos_table_lookup(angle);
    if (slot == 0) {
        heading = 0x8000;
    } else if (slot == 1) {
        heading = 0x6800;
    } else {
        heading = 0x9800;
    }
    self->direction.x = sin_table_lookup(heading);
    self->direction.y = 0.0f;
    self->direction.z = cos_table_lookup(heading);
    self->rotation_y = heading;
    self->m_390.x = 0.0f;
    self->m_390.y = 0.0f;
    self->m_390.z = 0.0f;
    self->move_mine();
    self->rotation_x = 0x4000;
    VecCopy(&self->position, self->body_center());
    self->m_3a8 = 0;
    self->hp = self->hpmax;
    self->actorFlags &= ~0xA00;
}

}

#pragma push
#pragma fp_contract on
void TUnk_80482D04::vfunc_105(s32 reason) {
    Vec to_target;
    f32 t;
    switch (reason) {
    case 4:
        vfunc_95();
        m_38c &= ~7;
        m_3a8 = 0;
        rotation_x = 0x4000;
        rotation_z = 0;
        m_3c8 = 1;
        m_3cc = 0;
        m_3dc = 8.0f;
        m_3e0 = 0.0f;
        break;
    case 3:
        if (m_3c8 == 3) {
            transition_enemy_state(2);
        }
        break;
    case 0:
        switch (m_3c8) {
        case 0:
            m_3cc++;
            if (m_3cc >= 15) {
                m_3c8 = 1;
                play_sound_effect(0x4003A804, body_center(), 0, 0);
            }
            m_2fc = direction.x * m_3dc + m_2fc;
            m_304 = direction.z * m_3dc + m_304;
            break;
        case 1:
            m_3a8 += 0x400;
            if (m_3a8 >= 0x38E3) {
                m_3a8 = 0x38E3;
                m_3c8 = 2;
            }
            m_2fc = direction.x * m_3dc + m_2fc;
            m_304 = direction.z * m_3dc + m_304;
            break;
        case 2:
            rotation_x -= 0x600;
            if (rotation_x < 0) {
                rotation_x = 0;
            }
            rotation_z += 2560.0f;
            m_3dc -= 0.2f;
            if (m_3dc <= 3.0f) {
                m_3dc = 3.0f;
            }
            move_mine();
            VecCopy(&to_target, &m_390);
            subtract_vector(&to_target, body_center());
            if (((TObjBoss2Tunnel *)&to_target)->update_scale() <= 4.5f) {
                m_3c8 = 3;
            }
            m_3e0 += 0.05f;
            if (m_3e0 > 3.0f) {
                m_3e0 = 3.0f;
            }
            t = m_3e0 / m_3dc;
            direction.x = to_target.x * t + direction.x;
            direction.y = to_target.y * t + direction.y;
            direction.z = to_target.z * t + direction.z;
            ((TObjBoss2Tunnel *)&direction)->update_scale();
            m_2fc = direction.x * m_3dc + m_2fc;
            m_300 = direction.y * m_3dc + m_300;
            m_304 = direction.z * m_3dc + m_304;
            break;
        }
        update_move_flag();
        break;
    case 5:
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TUnk_80482D04::vfunc_106(s32 reason) {
    Vec to_target;
    f32 s;
    switch (reason) {
    case 4:
        vfunc_96();
        m_38c &= ~5;
        m_38c |= 2;
        rotation_x = 0;
        m_3b0 = 0;
        m_3c8 = 0;
        m_3cc = (s32)(60.0f * calc_elapsed_scaled()) + 240;
        init_params(30, 0.25f);
        break;
    case 3:
        if (m_38c & 0x100) {
            m_38c &= ~0x100;
            transition_enemy_state(1);
        }
        if (m_3c8 == 1) {
            transition_enemy_state(3);
        }
        break;
    case 0:
        m_3cc--;
        if (m_3cc <= 0) {
            m_3c8 = 1;
        }
        rotation_z += 2560.0f;
        move_mine();
        VecCopy(&to_target, &m_390);
        subtract_vector(&to_target, body_center());
        s = normalize_vector_xz(&to_target);
        s *= 0.75f;
        if (s < 0.2f) {
            VecCopy(body_center(), &m_390);
        } else {
            if (s > 4.0f) {
                s = 4.0f;
            }
            m_2fc = to_target.x * s + m_2fc;
            m_300 = m_390.y;
            m_304 = to_target.z * s + m_304;
        }
        set_state_by_distance(m_3cc);
        update_pulse_state();
        position.x = m_2fc;
        position.z = m_304;
        vfunc_89();
        m_2fc = position.x;
        m_304 = position.z;
        update_move_flag();
        break;
    case 5:
        break;
    }
}
#pragma pop
