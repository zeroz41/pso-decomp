#include "types.h"
#include "pso/enemy/sorcerer/TObjEneRe4Bit.h"
#include "pso/enemy/sorcerer/TObjEneRe4Sorcerer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/system/task/TMainTask.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2F28.h"
#pragma defer_codegen on

extern "C" {
extern const f32 lbl_805D9E84;
extern const Vec re4_bit_render_vec;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
s32 TObjEneRe4Bit__model;
s32 re4_bit_texture_list;
extern const char *lbl_805D2AE8;
f32 calc_elapsed_scaled__9TObjEneDDFv(TObjEneDD *self);
s32 is_main_phase_15__9TObjEneDDFv(void);
extern BmlResource *sorcerer_bml_resource;
extern s32 lbl_8043D2B0[];
extern s32 lbl_8043D2B8[];
extern s32 lbl_8043D2C0[];
extern s32 lbl_8043D2C8[];
}

TObjEneRe4InitParams re4_bit_init_params = {225.0f, 0.0f, 0x600};
CollisionBody re4_bit_model_node_desc = {{0.0f, 0.0f, 0.0f}, 2.0f, 0.0f, 0, 0x8003};

extern "C" {
__declspec(section ".data") u8 *TObjEneRe4Bit_boss_handles[2];
__declspec(section ".data") u8 *lbl_80501058[2];
__declspec(section ".data") u8 *lbl_80501060[2];
__declspec(section ".data") void *lbl_80501068[2];
}

void TObjEneRe4Bit::apply_defense_stat_status(void *) {  }

void TObjEneRe4Bit::apply_attack_stat_status(void *) {  }

void TObjEneRe4Bit::clear_harmful_statuses() {  }

void TObjEneRe4Bit::apply_shock_status() {  }

void TObjEneRe4Bit::apply_movement_ailment(s32) {  }

void TObjEneRe4Bit::apply_confusion_status() {  }

void TObjEneRe4Bit::apply_slow_status() {  }

void TObjEneRe4Bit::apply_paralysis() {  }

void TObjEneRe4Bit::apply_poison_status() {  }

extern "C" void TObjEneRe4Bit__sub_800EDAB4(void) {
    s32 i;
    TObjEneRe4Bit__model = sorcerer_bml_resource->models[1].model;
    re4_bit_texture_list = sorcerer_bml_resource->models[0].m_c;
    for (i = 0; i < 2; i++) {
        TObjEneRe4Bit_boss_handles[i] = (u8 *)TLobby::register_boss(lbl_8043D2B0[i]);
        lbl_80501058[i] = (u8 *)TLobby::dispatch_shared_handler_b(lbl_8043D2B8[i]);
        lbl_80501060[i] = (u8 *)TLobby::register_object(lbl_8043D2C0[i]);
        lbl_80501068[i] = TLobby::dispatch_shared_handler_a(lbl_8043D2C8[i]);
    }
}

extern "C" void TObjEneRe4Bit__sub_800EDAB0(void) {  }

TObjEneRe4Bit *TObjEneRe4Bit::create(TObjEneRe4Sorcerer *owner, Vec *anchor, s32 enabled, u16 id, s32 set_index) {
    return new TObjEneRe4Bit(tl_04, owner, anchor, enabled, id, set_index);
}

void TObjEneRe4Sorcerer::create_disabled(Vec *anchor, u16 id, s32 set_index) {
    TObjEneRe4Bit::create(this, anchor, 0, id, set_index);
}

void TObjEneRe4Sorcerer::create_enabled(Vec *anchor, u16 id, s32 set_index) {
    TObjEneRe4Bit::create(this, anchor, 1, id, set_index);
}

TObjEneRe4Bit::TObjEneRe4Bit(TObject *parent, TObjEneRe4Sorcerer *owner, Vec *anchor, s32 enabled, u16 id, s32 set_index)
    : TObjEneDD_ST(parent) {
    m_name = lbl_805D2AE8;
    init_common_from((u8 *)owner);
    m_3c4 = get_entity_id((TObjBase *)owner);
    entity_id = id;
    this->set_index = set_index;
    m_3c0 = anchor;
    m_3c8 = enabled;
    VecCopy(&position, anchor);
    init();
}

void TObjEneRe4Bit::init() {
    s32 i;

    init_position_vectors();
    model = (void *)TObjEneRe4Bit__model;
    texlist = re4_bit_texture_list;
    init_model(&re4_bit_model_node_desc, 1);
    i = m_3c8 == 1 ? 0 : 1;
    reset_hp(TObjEneRe4Bit_boss_handles[i], lbl_80501058[i], lbl_80501060[i]);
    set_state_8();
    movementParameters = &re4_bit_init_params;
    if (m_3c8 == 1) {
        initialize_enemy_state(0x20);
    } else {
        initialize_enemy_state(0x21);
    }
    m_37c = 3.0f;
    m_3cc = 0;
    m_3d0 = 3;
    m_3d4 = 3;
    m_3d8 = 0.0f;
    fade.reset_obstruction_fade();
    m_3f8.x = 0.0f;
    m_3f8.y = 0.0f;
    m_3f8.z = 0.0f;
    m_404 = 0;
    m_408 = 0;
    m_40c = 0;
    sub_800ED408();
    call_vt_90_91();
    mode = 0;
    dispatch_action(mode, 4);
}

TObjEneRe4Bit::~TObjEneRe4Bit() {
    free_collision_body_parts(this);
}

void TObjEneRe4Bit::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        vfunc_105();
        return;
    }
    if (vfunc_83() == 1 || (m_3cc & 0x2000) == 0) {
        vfunc_85();
        clear_state_flags_when_done();
    } else {
        m_3cc &= ~0x2000;
    }
    copy_pos();
    vfunc_88();
    submit_default_cursor_candidate();
}

void TObjEneRe4Bit::vfunc_28() {  }

void TObjEneRe4Bit::vfunc_63() {
    s16 m = mode;
    if (m != 6) {
        if (m == 2) {
            transition_enemy_state(6);
            m_404 = 3;
            return;
        }
        transition_enemy_state(6);
    }
}

void TObjEneRe4Bit::vfunc_62() {
    if (mode != 5) {
        if (m_3cc & 0x1000) {
            clear_attack_receipts();
            return;
        }
        transition_enemy_state(5);
    }
}

void TObjEneRe4Bit::vfunc_61() {  }

void TObjEneRe4Bit::copy_pos() { VecCopy(&center, (Vec *)&m_2fc); }

void TObjEneRe4Bit::vfunc_88() {
    bodies->offset.y = m_300 - position.y;
}

void TObjEneRe4Bit::update_position_flag() {
    Vec pos;

    VecCopy(&pos, (Vec *)&m_2fc);
    if (vfunc_101((u8 *)&pos) == 0) {
        m_3cc &= ~0x800;
        return;
    }
    m_3cc |= 0x800;
}

#pragma push
#pragma fp_contract on
void TObjEneRe4Bit::update_homing_velocity() {
    Vec dir;
    f32 s;
    VecCopy(&dir, m_3c0);
    dir.y = dir.y + m_3d8;
    subtract_vector(&dir, (Vec *)&m_2fc);
    s = 0.01f * ((TObjBoss2Tunnel *)&dir)->update_scale();
    m_3f8.x = 0.9f * (dir.x * s + m_3f8.x);
    m_3f8.y = 0.9f * (dir.y * s + m_3f8.y);
    m_3f8.z = 0.9f * (dir.z * s + m_3f8.z);
    vec3_add_to((Vec *)&m_2fc, &m_3f8);
    position.x = m_2fc;
    position.z = m_304;
}
#pragma pop

s32 TObjEneRe4Bit::sub_800ED498() {
    s16 m;
    u8 result;
    m = mode;
    result = 0;
    if ((m != 5) && (m != 6)) {
        result = 1;
    }
    return result;
}

s32 TObjEneRe4Bit::get_state() { return m_404; }

Vec *TObjEneRe4Bit::get_spell_data() { return (Vec *)&m_2fc; }

void TObjEneRe4Bit::sub_800ED47C() { m_3d0 = 3; }

void TObjEneRe4Bit::set_state_flag_and_mode(s32 kind) {
    m_3cc |= 0x1;
    switch (kind) {
    case 0:
        m_3d4 = 4;
        return;
    case 1:
        m_3d4 = 5;
        return;
    case 2:
        m_3d4 = 6;
        return;
    }
}

void TObjEneRe4Bit::set_attack_flag() { m_3cc |= 0x2; }

void TObjEneRe4Bit::sub_800ED408() { m_3cc &= ~0x100; }

void TObjEneRe4Bit::set_flag_and_notify() {
    m_3cc |= 0x10;
    if (!(m_3cc & 0x4)) {
        set_hold_flags();
    }
}

void TObjEneRe4Bit::set_hold_flags() {
    m_3cc |= 0x204;
    m_3cc &= ~0x8;
    fade.reset_color();
}

void TObjEneRe4Bit::clear_state_flag_0x10() {
    m_3cc &= ~0x10;
    if (!(m_3cc & 0x408)) {
        set_state_flags();
    }
}

void TObjEneRe4Bit::set_state_flags() {
    m_3cc &= ~0x4;
    m_3cc |= 0x308;
    fade.reset_obstruction_fade();
}

void TObjEneRe4Bit::invoke_state_callbacks() {
    vfunc_91();
    vfunc_94();
}

void TObjEneRe4Bit::call_vt_90_91() {
    vfunc_92();
    vfunc_93();
}

void TObjEneRe4Bit::set_flag3cc_bit2000() { m_3cc |= 0x2000; }

void TObjEneRe4Bit::reset_transform() {
    VecCopy((Vec *)&m_2fc, m_3c0);
    m_3f8.x = 0.0f;
    m_3f8.y = 0.0f;
    m_3f8.z = 0.0f;
    update_position_flag();
    transform_part_positions();
}

void TObjEneRe4Bit::clear_state_flags_when_done() {
    u32 flags = m_3cc;
    if (flags & 0x4) {
        if (fade.decay_value_toward_floor() != 0) {
            m_3cc &= ~0x4;
            m_3cc &= ~0x200;
            m_3cc &= ~0x100;
        }
    } else if ((flags & 0x8) && fade.advance_toward_max() != 0) {
        m_3cc &= ~0x8;
        m_3cc &= ~0x200;
    }
}

void TObjEneRe4Bit::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        handle_state_message(reason);
        return;
    case 1:
        handle_event(reason);
        return;
    case 2:
        TObjEneRe4Bit__sub_800ECED0(this, reason);
        return;
    case 3:
        TObjEneRe4Bit__sub_800ECE04(this, reason);
        return;
    case 5:
        TObjEneRe4Bit__sub_800ECD28(this, reason);
        return;
    case 6:
        TObjEneRe4Bit__sub_800ECC14(this, reason);
    default:
        return;
    }
}

void TObjEneRe4Bit::handle_state_message(s32 msg) {
    switch (msg) {
    case 0:
        return;
    case 3:
        transition_enemy_state(1);
        return;
    }
}

s32 TObjEneRe4Bit::handle_event(s32 arg1) {
    u32 flags;

    switch (arg1) {
    case 4:
        set_field_378(1);
        m_3cc &= ~0x1000;
        break;
    case 3:
        flags = m_3cc;
        if (flags & 0x1) {
            m_3cc = flags & ~0x1;
            transition_enemy_state(2);
            break;
        }
        if (flags & 0x2) {
            m_3cc = flags & ~0x2;
            transition_enemy_state(3);
        }
        break;
    case 5:
        break;
    case 0:
        update_homing_velocity();
        update_position_flag();
        break;
    }
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void TObjEneRe4Bit__sub_800ECED0(TObjEneRe4Bit *bit, s32 arg1) {
    u32 flags;
    switch (arg1) {
    case 4:
        bit->set_field_378(3);
        bit->m_3cc |= 0x1000;
        bit->m_408 = 0;
        bit->m_404 = 1;
        bit->m_3d0 = bit->m_3d4;
        return;
    case 3:
        flags = bit->m_3cc;
        if (flags & 0x2) {
            bit->m_3cc = flags & ~0x2;
            bit->transition_enemy_state(3);
        }
        return;
    case 0:
        switch (bit->m_408) {
        case 1:
            break;
        case 0:
            bit->m_3d8 += 0.8f;
            if (bit->m_3d8 > 20.0f) {
                bit->m_3d8 = 20.0f;
                bit->m_408 = 1;
                bit->m_404 = 2;
            }
            bit->rotation_y = bit->rotation_y + 0x1800;
            break;
        }
        bit->update_homing_velocity();
        bit->update_position_flag();
        return;
    case 5:
        bit->m_404 = 0;
        break;
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
extern "C" void TObjEneRe4Bit__sub_800ECE04(TObjEneRe4Bit *bit, s32 arg1) {
    switch (arg1) {
    case 4:
        bit->set_field_378(3);
        bit->m_3cc &= ~0x1000;
        bit->m_3d0 = 3;
        break;
    case 3:
        if (bit->m_3d8 <= 0.0f) {
            bit->transition_enemy_state(1);
            break;
        }
    case 5:
        break;
    case 0:
        bit->m_3d8 -= 0.8f;
        if (bit->m_3d8 < 0.0f) {
            bit->m_3d8 = 0.0f;
        }
        bit->rotation_y = bit->rotation_y - 0x1800;
        bit->update_homing_velocity();
        bit->update_position_flag();
        break;
    }
}
#pragma pop

extern "C" void TObjEneRe4Bit__sub_800ECD28(TObjEneRe4Bit *bit, s32 arg1) {
    switch (arg1) {
    case 4:
        bit->m_408 = 0;
        return;
    case 3:
        if (bit->m_408 > 0xF) {
            bit->transition_enemy_state(1);
        }
        return;
    case 0:
        bit->m_408 = bit->m_408 + 1;
        VecCopy((Vec *)&bit->m_2fc, bit->m_3c0);
        bit->m_300 = bit->m_300 + bit->m_3d8;
        bit->m_2fc = bit->m_2fc + calc_elapsed_scaled__9TObjEneDDFv(bit);
        bit->m_304 = bit->m_304 + calc_elapsed_scaled__9TObjEneDDFv(bit);
        bit->vfunc_102();
        return;
    case 5:
        bit->clear_attack_receipts();
        return;
    }
}

#pragma push
#pragma fp_contract on
extern "C" void TObjEneRe4Bit__sub_800ECC14(TObjEneRe4Bit *bit, s32 arg1) {
    u32 flags;
    switch (arg1) {
    case 4:
        bit->m_408 = 0;
        bit->set_hold_flags();
        bit->m_3cc |= 0x400;
        play_sound_effect(bit->remap_sound_for_area(0x4003A815), &bit->position, 0, 0);
        break;
    case 3:
        if (bit->m_3cc & 0x8) {
            play_sound_effect(bit->remap_sound_for_area(0x4003AD16), &bit->position, 0, 0);
            bit->transition_enemy_state(1);
        }
        break;
    case 0:
        bit->m_408 = bit->m_408 + 1;
        if (bit->m_408 >= 900) {
            flags = bit->m_3cc;
            if (!(flags & 0x10)) {
                bit->m_3cc = flags & ~0x400;
                bit->set_state_flags();
                return;
            }
        }
        break;
    case 5:
        bit->actorFlags &= ~0x800;
        bit->hp = bit->hpmax;
        bit->sub_800ED47C();
        bit->m_3d8 = 0.0f;
        break;
    }
}
#pragma pop

void TObjEneRe4Bit::render() {
    f32 range;
    s32 saved;
    s32 draw;
    NJS_TEXNAME *textures;
    if (TObjPlayer::check_demo_mode() != 0) {
        vfunc_106();
        return;
    }
    if (is_main_phase_15__9TObjEneDDFv() != 0) {
        range = lbl_805D9E84;
    } else {
        range = 400.0f;
    }
    if (!(m_3cc & 0x100)) {
        return;
    }
    if (update_object_view_visibility(range, 20.0f) == 0) {
        return;
    }
    if (m_3cc & 0x800) {
        Vec v = re4_bit_render_vec;
        TObjEnemy::draw_ground_shadow(&v, 0);
    }
    update_secondary_light();
    textures = ((NJS_TEXLIST *)texlist)->textures;
    saved = textures[3].texaddr;
    textures[3].texaddr = textures[m_3d0].texaddr;
    TObjFish::set_global_param(texlist);
    saved_model_render_flags = model_render_flags;
    TObjEneDD::clear_global_flag_400();
    TObjPlayer::toggle_particle_effect();
    draw = 1;
    if (m_3cc & 0x200) {
        fade.set_flags_and_apply_damage_color();
        if (defer_render() != 0) {
            draw = 0;
        }
    }
    if (draw != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        translate_matrix(0, 0.0f, m_300 - position.y, 0.0f);
        rotate_matrix_y(0, rotation_y);
        scale_matrix(0, 2.0f, 2.0f, 2.0f);
        draw_chunk_object(model);
        pop_matrix();
    }
    fade.clear_flag_and_notify();
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    update_primary_light();
    ((NJS_TEXLIST *)texlist)->textures[3].texaddr = saved;
}
