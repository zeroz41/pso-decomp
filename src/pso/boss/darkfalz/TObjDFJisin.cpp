#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/darkfalz/TObjDFHorming.h"
#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/camera/TCameraCtrl.h"

struct NJS_OBJECT;
#include "pso/boss/darkfalz/TBoss4DarkFalz_8004C93C.h"
#include "pso/system/vector.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/PadRumble.h"
#include "pso/player/PlayerClassFlags.h"
#include "pso/boss/darkfalz/TObjDFTenchuFuru.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TObjDFRecover.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/darkfalz/TOBoss4.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/enemy/BattleParameters.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TNowLoading.h"
#include "dolphin/mtx.h"
#include <stddef.h>
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/boss/darkfalz/TObjDFJisin.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/boss/darkfalz/TObjDFYutai.h"
#include "pso/boss/darkfalz/TBoss4Type3_800524E8.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D853C.h"
#include "pso/object/base/TObjBase.h"


const char *TObjDFUsoTower__name = "TObjDFUsoTower";
const char *TObjDFTenchuFuru__name = "TObjDFTenchuFuru";
const char *TObjDFRecover__name = "TObjDFRecover";
const char *TObjDFRecBall__name = "TObjDFRecBall";
const char *TObjDFBeamCursor__name = "TObjDFBeamCursor";
const char *TObjDFJisin__name = "TObjDFJisin";
const char *TObjDFHorming__name = "TObjDFHorming";
const char *TObjDFYutai__name = "TObjDFYutai";

// TObjDFYutai's lerp ranges over its fade (t, 0..1): render's height offset, scale and draw weight.
struct YutaiRange {
    f32 min;
    f32 max;
    f32 lerp(f32 t) const { return t * (max - min) + min; }
};

// The TU's .data opens with these (0x804858A8), ahead of the vtables.
Vec uso_tower_start_position = {0.0f, 0.0f, -81.0f}; // name inferred: TObjDFUsoTower's ctor copies it to its position
Vec dark_falz_jisin_zero_vec = {0.0f, 0.0f, 0.0f};
__declspec(section ".data") s32 TObjDFJisin__particle_emitter_id_table[2] = {0xE0, 0xF4};
__declspec(section ".data") YutaiRange yutai_height_range = {10.0f, 0.0f};
__declspec(section ".data") YutaiRange yutai_scale_range = {2.0f, 1.0f};
__declspec(section ".data") YutaiRange yutai_weight_range = {0.0f, 0.75f};

int TObjDFTenchuFuru::matrix_node_index;
// World positions transform_node_tree captures at player nodes 0x3B (where the head and hair are drawn)
// and 0x3A (the attachment part).
Vec dark_falz_head_node_position;
Vec dark_falz_part_node_position;
Mtx34 df_captured_matrix_pair[2];

#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803DC86C.h"
#include "pso/boss/darkfalz/TObjDFUsoTower.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/player/PlayerSlots.h"


// Written last to first: the unit is generated deferred (see configure.py).
#pragma fp_contract on

#pragma push
#pragma opt_common_subs off

TObjDFUsoTower *TObjDFUsoTower::create(TObject *parent) {
    return new TObjDFUsoTower(parent);
}

TObjDFUsoTower::TObjDFUsoTower(TObject *parent) : TObjBase(parent) {
    m_name = TObjDFUsoTower__name;
    model = (void *)(get_bml_model(TOBoss4::model_resource, 5));
    this->texlist = get_bml_texlist(TOBoss4::model_resource, 5);
    VecCopy(&position, &uso_tower_start_position);
    fade_alpha = 0.0f;
    fade_state = 0;
}

TObjDFUsoTower::~TObjDFUsoTower() {}

void TObjDFUsoTower::run_task() {
    f32 d;
    f32 r;
    switch (fade_state) {
    case 0: {
        Vec v = camera_ctrl_instance->pos;
        subtract_vector(&v, &position);
        v.y = 0.0f;
        d = vector_length(&v);
        if (d <= 150.0f) {
            r = 0.0f;
        } else if (d >= 200.0f) {
            r = 1.0f;
        } else {
            r = (d - 150.0f) / 50.0f;
        }
        fade_alpha = 0.4f * r;
        break;
    }
    case 1:
        if ((fade_alpha += 0.033333335f) > 1.0f) {
            fade_alpha = 1.0f;
        }
        break;
    case 2:
        if ((fade_alpha += -0.033333335f) < 0.0f) {
            fade_alpha = 0.0f;
        }
        break;
    }
}

#pragma pop

void TObjDFUsoTower::render() {
    f32 alpha;

    alpha = fade_alpha;
    if (0.0f != alpha) {
        if (alpha < 1.0f) {
            TObjPlayer::begin_alpha_blend(alpha);
            set_color_blend_mode(1, 4, 5, 0);
        }
        push_matrix();
        post_translate_matrix(&this->position.x);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        draw_ginja_object(this->model);
        pop_matrix();
        if (fade_alpha < 1.0f) {
            TObjPlayer::sync_player_globals();
        }
    }
}

void TObjPlayer::draw_player_model_by_id(s32 client_id, f32 alpha) {
    TObjPlayer *player;
    void *head;
    void *hair;
    s32 head_textures;
    uaddr attachment;
    s32 attachment_textures;
    void *body;
    NJS_TEXLIST *body_textures;

    if (0.0f == alpha) {
        return;
    }
    if ((u16)client_id == 0xFFFF) {
        return;
    }
    player = get_player_by_client_id((u16)client_id);
    if (player == NULL || player->model_load_flags != 0) {
        return;
    }
    body = player->model;
    head_textures = (saddr)player->head_textures;
    head = player->head_model;
    attachment_textures = (saddr)player->attachment_textures;
    hair = player->hair_model;
    attachment = player->attachment_model;
    body_textures = &player->body_textures;
    TObjDFTenchuFuru::draw_node_tree((NJS_OBJECT *)body);
    if (alpha < 1.0f) {
        TObjPlayer::begin_alpha_blend(alpha);
    }
    TObjFish::set_global_param(body_textures);
    draw_chunk_object(body);
    if (attachment != 0U) {
        push_matrix();
        post_translate_matrix(&dark_falz_part_node_position.x);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(attachment_textures));
        draw_chunk_object((void *)attachment);
        pop_matrix();
    }
    if (head != NULL) {
        TCharaMaking::enable_making();
        push_matrix();
        post_translate_matrix(&dark_falz_head_node_position.x);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(head_textures));
        draw_chunk_object(head);
        pop_matrix();
        TCharaMaking::clear_flag_bit0();
    }
    if (alpha < 1.0f) {
        TObjPlayer::sync_player_globals();
    }
    if (hair != NULL) {
        TCharaMaking::enable_making();
        push_matrix();
        post_translate_matrix(&dark_falz_head_node_position.x);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(head_textures));
        TCharaMaking__draw_colored_hair(alpha, (saddr)hair, (CharacterAppearanceFields *)player->name, 0);
        pop_matrix();
        TCharaMaking::clear_flag_bit0();
    }
}

void boss6type2_draw_models(s32 body_texlist, s32 head_texlist, s32 part_texlist, uaddr body, uaddr head, u32 hair, uaddr part, saddr appearance, f32 alpha) {
    if (0.0f != alpha) {
        TObjDFTenchuFuru::draw_node_tree((NJS_OBJECT *)body);
        if (alpha < 1.0f) {
            TObjPlayer::begin_alpha_blend(alpha);
        }
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(body_texlist));
        draw_chunk_object((void *)body);
        if (part != 0U) {
            push_matrix();
            post_translate_matrix(&dark_falz_part_node_position.x);
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(part_texlist));
            draw_chunk_object((void *)part);
            pop_matrix();
        }
        if (head != 0U) {
            TCharaMaking::enable_making();
            push_matrix();
            post_translate_matrix(&dark_falz_head_node_position.x);
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(head_texlist));
            draw_chunk_object((void *)head);
            pop_matrix();
            TCharaMaking::clear_flag_bit0();
        }
        if (alpha < 1.0f) {
            TObjPlayer::sync_player_globals();
        }
        if (hair != 0U) {
            TCharaMaking::enable_making();
            push_matrix();
            post_translate_matrix(&dark_falz_head_node_position.x);
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(head_texlist));
            TCharaMaking__draw_colored_hair(alpha, (s32)hair, (CharacterAppearanceFields *)appearance, 0);
            pop_matrix();
            TCharaMaking::clear_flag_bit0();
        }
    }
}

extern "C" {
void TObjPlayer::draw_player_model_by_client(u16 client_id, saddr motion, f32 frame, f32 alpha) {
    TObjPlayer *player;
    void *head;
    void *hair;
    s32 head_textures;
    uaddr attachment;
    s32 attachment_textures;
    void *body;
    NJS_TEXLIST *body_textures;
    if (0.0f == alpha) {
        return;
    }
    if (client_id == 0xFFFF) {
        return;
    }
    player = get_player_by_client_id(client_id);
    if (player == NULL || player->model_load_flags != 0) {
        return;
    }
    head_textures = (saddr)player->head_textures;
    head = player->head_model;
    attachment_textures = (saddr)player->attachment_textures;
    hair = player->hair_model;
    attachment = player->attachment_model;
    body_textures = &player->body_textures;
    body = player->model;
    if (alpha < 1.0f) {
        TObjPlayer::begin_alpha_blend(alpha);
    }
    TObjFish::set_global_param(body_textures);
    TObjDFTenchuFuru::register_callback();
    draw_model_motion(body, (void *)motion, frame);
    TObjDFTenchuFuru::unregister_callback();
    if (attachment != 0) {
        push_matrix_from(df_captured_matrix_pair[1]);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(attachment_textures));
        draw_chunk_object((void *)attachment);
        pop_matrix();
    }
    if (head != NULL) {
        TCharaMaking::enable_making();
        push_matrix_from(df_captured_matrix_pair[0]);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(head_textures));
        draw_chunk_object(head);
        pop_matrix();
        TCharaMaking::clear_flag_bit0();
    }
    if (alpha < 1.0f) {
        TObjPlayer::sync_player_globals();
    }
    if (hair != NULL) {
        TCharaMaking::enable_making();
        push_matrix_from(df_captured_matrix_pair[0]);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(head_textures));
        TCharaMaking__draw_colored_hair(alpha, (saddr)hair, (CharacterAppearanceFields *)player->name, 0);
        pop_matrix();
        TCharaMaking::clear_flag_bit0();
    }
}
}

extern "C" {
void TObjDFTenchuFuru::draw_node_tree(NJS_OBJECT *node) { matrix_node_index = 0; push_matrix(); set_matrix_identity(NULL); transform_node_tree(node); pop_matrix(); }
}

extern "C" {
void TObjDFTenchuFuru::transform_node_tree(NJS_OBJECT *node) {
    do {
        push_matrix();
        post_translate_matrix(node->pos);
        rotate_matrix_by_node_angles(node->ang, node->evalflags & 0x20);
        scale_current_matrix(node->scl);
        switch (matrix_node_index) {
        case 0x3B:
            matrix_mult_vec(0, &dark_falz_jisin_zero_vec, &dark_falz_head_node_position);
            break;
        case 0x3A:
            matrix_mult_vec(0, &dark_falz_jisin_zero_vec, &dark_falz_part_node_position);
            break;
        }
        matrix_node_index += 1;
        if (node->child != NULL) {
            transform_node_tree(node->child);
        }
        pop_matrix();
        node = node->sibling;
    } while (node != NULL);
}
}

extern "C" {
void TObjDFTenchuFuru::register_callback() { matrix_node_index = 0; set_chunk_model_node_callback(TObjDFTenchuFuru::capture_matrix_by_frame); }
}

extern "C" {
void TObjDFTenchuFuru::unregister_callback() { set_chunk_model_node_callback(0); }
}

extern "C" {
void TObjDFTenchuFuru::capture_matrix_by_frame(NJS_OBJECT *) {
    switch (matrix_node_index) {
    case 0x3B:
        get_current_matrix(&df_captured_matrix_pair[0]);
        break;
    case 0x3A:
        get_current_matrix(&df_captured_matrix_pair[1]);
        break;
    }
    matrix_node_index += 1;
}
}

TObjDFTenchuFuru *TObjDFTenchuFuru::create(TObject *parent, const Vec *position) {
    return new TObjDFTenchuFuru(parent, position);
}

TObjDFTenchuFuru::TObjDFTenchuFuru(TObject *parent, const Vec *position) : TObject(parent) {
    m_name = TObjDFTenchuFuru__name;
    timer = 5;
    VecCopy(&pos, position);
    pos.y += 300.0f;
    if ((effect = create_particle_emitter(&pos, 0x134)) != NULL) {
        effect->set_flags(0x40);
    }
}

TObjDFTenchuFuru::~TObjDFTenchuFuru() {
    if (effect != NULL) TParticleCtrl::release(effect);
}

#pragma push
#pragma fp_contract on
void TObjDFTenchuFuru::run_task() {
    pos.y += -60.0f;
    if (effect != NULL) {
        effect->set_position(&pos);
    }
    if (--timer < 0 || (TBoss4DarkFalz::is_active() == 0 && TBoss4DarkFalz::is_state_ready() == 0)) {
        queue_destruction();
    }
}
#pragma pop

TObjDFRecover *TObjDFRecover::create(TObject *parent, u16 id, const Vec *position) {
    return new TObjDFRecover(parent, id, position);
}

TObjDFRecover::TObjDFRecover(TObject *parent, u16 id, const Vec *position) : TObject(parent) {
    m_name = TObjDFRecover__name;
    target_id = id;
    effect = NULL;
    VecCopy(&cached_position, position);
    phase = 0;
    countdown = 5;
}

TObjDFRecover::~TObjDFRecover() {
    if (effect != 0) TParticleCtrl::release(effect);
}

#pragma push
#pragma fp_contract on
void TObjDFRecover::run_task() {
    Vec position;
    s32 current_phase;
    TObjPlayer *target;
    uaddr effect_address;
    u16 id;
    if (TBoss4DarkFalz::is_state_ready() == 0) {
        queue_destruction();
        return;
    }
    id = target_id;
    if ((id == 0xFFFF) || ((target = get_player_by_client_id(id)) == NULL)) {
        queue_destruction();
        return;
    }
    VecCopy(&position, &target->body_center);
    countdown = countdown - 1;
    current_phase = phase;
    switch (current_phase) {
    case 0:
        if (countdown <= 0) {
            effect_address = (uaddr)create_particle_emitter(&position, 0xEB);
            effect = (void*)effect_address;
            if (effect_address == 0U) {
                queue_destruction();
                return;
            }
            ((TParticleCtrl *)effect)->set_flags(0x40);
            countdown = 0xA;
            phase = 1;
        }
        break;
    case 1:
        ((TParticleCtrl *)effect)->set_position(&position);
        if (countdown <= 0) {
            TParticleCtrl::release(effect);
            effect = NULL;
            start_pad_rumble_client(0xC0, 0xF, (int) ((s16) target_id));
            countdown = 0xB;
            phase = 2;
            return;
        }
        break;
    case 2:
        if ((countdown % 5) == 0) {
            play_sound_effect(0x4003AD19, 0, 0, 0);
            TObjDFRecBall::create(m_up, &position, &cached_position);
        }
        if (countdown <= 0) {
            queue_destruction();
        }
        break;
    }
}
#pragma pop

TObjDFRecBall *TObjDFRecBall::create(TObject *parent, const Vec *position, const Vec *target) {
    return new TObjDFRecBall(parent, position, target);
}

TObjDFRecBall::TObjDFRecBall(TObject *parent, const Vec *position, const Vec *target_position) : TObject(parent) {
    s32 angle;
    m_name = TObjDFRecBall__name;
    VecCopy(&pos, position);
    VecCopy(&target, target_position);
    angle = (s32) (65536.0f * (0.000030517578f * (f32) rand()));
    vel.x = sin_table_lookup(angle);
    vel.y = 0.0f;
    vel.z = cos_table_lookup(angle);
    speed = 1.0f;
    timer = 150;
    if ((model = create_particle_emitter(&pos, 0xAF)) != NULL) {
        ((TParticleCtrl *)model)->set_flags(0x40);
    }
}

TObjDFRecBall::~TObjDFRecBall() {
    if (model != nullptr) TParticleCtrl::release(model);
}

#pragma push
#pragma fp_contract on
void TObjDFRecBall::run_task() {
    Vec d;

    if (--timer < 0 || model == 0) {
        queue_destruction();
        return;
    }
    if ((speed += 0.26666668f) > 9.0f) {
        speed = 9.0f;
    }
    VecCopy(&d, &target);
    subtract_vector(&d, &pos);
    if (vector_length(&d) > 0.01f) {
        normalize_vector(&d);
    } else {
        d.x = 1.0f;
        d.z = d.y = 0.0f;
    }
    if (vector_length(&vel) > 0.01f) {
        normalize_vector(&vel);
    } else {
        vel.x = 1.0f;
        vel.y = 0.0f;
        vel.z = 0.0f;
    }
    vel.x = speed * (0.9f * vel.x + 0.100000024f * d.x);
    vel.y = speed * (0.9f * vel.y + 0.100000024f * d.y);
    vel.z = speed * (0.9f * vel.z + 0.100000024f * d.z);
    vec3_add_to(&pos, &vel);
    ((TParticleCtrl *)model)->set_position(&pos);
    if (xyz_distance(&pos, &target) <= speed) {
        queue_destruction();
    }
}
#pragma pop

TObjDFBeamCursor *TObjDFBeamCursor::create(TObject *parent, const Vec *position) {
    return new TObjDFBeamCursor(parent, position);
}

TObjDFBeamCursor::TObjDFBeamCursor(TObject *parent, const Vec *pos) : TObject(parent) {
    m_name = TObjDFBeamCursor__name;
    timer = 32;
    VecCopy(&position, pos);
}

TObjDFBeamCursor::~TObjDFBeamCursor() {}

void TObjDFBeamCursor::run_task() {
    if (--timer <= 0) {
        spawn_particle_effect(&position, 0x38);
        queue_destruction();
    }
}

TObjDFJisin *TBoss4Type2::create_jisin(TObject *parent, s32 angle) {
    return new TObjDFJisin(parent, angle);
}

TObjDFJisin::TObjDFJisin(TObject *parent, s32 angle) : TObject(parent) {
    m_name = TObjDFJisin__name;
    center.x = 300.0f * sin_table_lookup(angle);
    center.y = 0.0f;
    center.z = -300.0f * cos_table_lookup(angle);
    radius = 25.0f;
}

TObjDFJisin::~TObjDFJisin() {}

#pragma push
#pragma fp_contract on
void TObjDFJisin::run_task() {
    Vec v;
    s32 ang;
    s32 step;
    s32 count;
    f32 max;

    step = (s32)(1638400.0f / (6.28f * radius));
    count = 0;
    v.y = 0.0f;
    max = 255.0f;
    for (ang = 0; ang < 0x10000; ang += step) {
        v.x = radius * sin_table_lookup(ang) + center.x;
        v.z = radius * cos_table_lookup(ang) + center.z;
        if (!(vector_length(&v) > max)) {
            spawn_particle_f3(&v);
            damage_players_near_point(&v);
            count++;
        }
    }
    if (radius > 300.0f && count == 0) {
        queue_destruction();
        return;
    }
    radius += 25.0f;
}
#pragma pop

void TObjDFJisin::spawn_particle_f3(const Vec *point) {
    Vec position;
    TParticleCtrl *effect;
    VecCopy(&position, point);
    position.y += 2.0f;
    effect = spawn_particle_effect(&position, 0xF3);
    if (effect != NULL) {
        effect->set_flags(0x40);
    }
}

void TObjDFJisin::damage_players_near_point(Vec *point) {
    Vec pos = *point;
    DirectAttackPayload hit;
    s32 i;
    TObjPlayer *p;
    if (TBoss4DarkFalz::is_state_ready() == 0) {
        return;
    }
    hit.kind = 0x11;
    hit.power = 0.0f;
    for (i = 0; i < TLobby::get_game_mode(); i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != NULL && is_player_in_boss_area(p->get_entity_id()) != 0 &&
            !(p->class_flags & CLASS_FLAG_ANDROID) &&
            !(xyz_distance(&pos, &p->position) > 20.0f)) {
            DirectAttackPayload h = hit;
            p->receive_direct_attack(TBoss4DarkFalz::get_type2_instance(), h, NULL, -1, -1);
        }
    }
}

TObjDFHorming *TBoss4Type3::create_horming(TObject *parent, const Vec *position, u16 target_id) {
    return new TObjDFHorming(parent, position, target_id);
}

#pragma push
#pragma fp_contract on
TObjDFHorming::TObjDFHorming(TObject *parent, const Vec *position, u16 target_id) : TObjChara(parent) {
    f32 scale;
    s32 ang;
    TObjPlayer *p;
    s32 i;

    m_name = TObjDFHorming__name;
    this->target_id = target_id;
    lifetime = 150;
    if (game_difficulty_selection == 3) {
        lifetime = 300;
    }
    VecCopy(&body_center, VecCopy(&prev_position, VecCopy(&spawn_position, position)));
    scale = newton_sqrtf(1.08f);
    ang = (s32)(16384.0f * (0.000030517578f * (f32)rand() - 0.5f));
    p = get_player_by_client_id(this->target_id);
    if (p != NULL) {
        ang = 0;
    } else {
        ang += (s32)(10430.38043493439 * atan2_float(p->position.x - 10000.0f, p->position.z));
    }
    velocity.x = 1.2f * sin_table_lookup(ang) / scale;
    velocity.z = 1.2f * cos_table_lookup(ang) / scale;
    velocity.y = -6.0f / scale;
    speed = 6.0f;
    damage = TLobby::dispatch_shared_handler_a(0x38)->values.integers[4];
    homing_rate = TLobby::dispatch_shared_handler_a(0x38)->values.floats[0];
    if (homing_rate < 0.0f || homing_rate > 1.0f) {
        homing_rate = 0.5f;
    }
    lock_distance = -50.0f * homing_rate + 60.0f;
    for (i = 0; i < 2; i++) {
        if ((effects[i] = create_particle_emitter(&body_center, TObjDFJisin__particle_emitter_id_table[i])) != NULL) {
            effects[i]->set_flags(0x40);
        }
    }
    state = 0;
}
#pragma pop

TObjDFHorming::~TObjDFHorming() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (effects[i] != NULL) {
            TParticleCtrl::release(effects[i]);
            effects[i] = NULL;
        }
    }
}

void TObjDFHorming::run_task() {
    s32 rotation[3];
    Vec d;
    DirectAttackPayload s;
    TObjPlayer *p;
    s32 i;
    if (TObjEneDD::query_teammate_state() != 0) {
        return;
    }
    if (target_id == 0xFFFF || (p = get_player_by_client_id(target_id)) == NULL) {
        queue_destruction();
        return;
    }
    VecCopy(&target_position, &p->body_center);
    target_distance = xyz_distance(&body_center, &target_position);
    VecCopy(&prev_position, &body_center);
    switch (state) {
    case 0:
        approach_target_height();
        break;
    case 1:
        steer_homing_direction();
        break;
    case 2:
        check_attack_trigger();
        break;
    }
    normalize_vector(&velocity);
    velocity.x *= speed;
    velocity.y *= speed;
    velocity.z *= speed;
    vec3_add_to(&body_center, &velocity);
    {
        s32 id = find_nearest_visible_player(this, NULL, 7.5f);
        if (id != 0xFFFF && (p = get_player_by_client_id(id)) != NULL) {
            if (is_boss_active() != 0) {
                s.kind = 0;
                s.power = damage;
                {
                    DirectAttackPayload t = s;
                    p->receive_direct_attack(TBoss4DarkFalz::get_type3_instance(), t, NULL, -1, -1);
                }
            }
            queue_destruction(this);
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        if (effects[i] != NULL) {
            if (i == 1) {
                VecCopy(&d, &body_center);
                subtract_vector(&d, &prev_position);
                direction_to_rotation_xz((u8 *)&d, &rotation[0], &rotation[2]);
                rotation[1] = 0;
                effects[i]->set_direction(rotation);
            }
            effects[i]->set_position(&body_center);
        }
    }
    minimap_render_dot(&body_center, -0x5DB4, 1, 0);
    if (--lifetime < 0) {
        queue_destruction();
    }
}

void TObjDFHorming::queue_destruction(TObject *object) { object->queue_destruction(); }

void TObjDFHorming::approach_target_height() {
    f32 dy;
    dy = target_position.y - body_center.y;
    if (dy > 0.0f) {
        velocity.y += 0.05f;
    } else {
        velocity.y -= 0.05f;
    }
    if (fabs_float(dy) < 50.0f) {
        state = 1;
    }
}

void TObjDFHorming::steer_homing_direction() {
    Vec d;
    f32 k;
    f32 inv;
    VecCopy(&d, &target_position);
    subtract_vector(&d, &body_center);
    if (vector_length(&d) <= 0.01f ||
        vector_length(&velocity) <= 0.01f) {
        queue_destruction();
        return;
    }
    normalize_vector(&d);
    normalize_vector(&velocity);
    k = -0.3f * homing_rate + 0.8f;
    Vec prev = velocity;
    inv = 1.0f - k;
    velocity.x = k * velocity.x + inv * d.x;
    velocity.y = k * velocity.y + inv * d.y;
    velocity.z = k * velocity.z + inv * d.z;
    if (target_distance <= lock_distance && xyz_distance(&velocity, &prev) <= 0.001f) {
        state = 2;
    }
}

// TObjDFYutai, TBoss4Type3::create_yutai and TObjDFHorming::check_attack_trigger open the TU's text.
void TObjDFHorming::check_attack_trigger() {
    if (game_difficulty_selection == 3 && lifetime >= 0x78 && target_distance > 2.5f * lock_distance) {
        state = 1;
    }
}

TObjDFYutai *TBoss4Type3::create_yutai(TObject *parent, s32 kind, u16 player_id) {
    return new TObjDFYutai(parent, kind, player_id);
}

TObjDFYutai::TObjDFYutai(TObject *parent, s32 kind, u16 player_id) : TObject(parent) {
    m_name = TObjDFYutai__name;
    this->kind = kind;
    this->player_id = player_id;
    switch (this->kind) {
    case 0:
        t = 1.0f;
        rate = -0.011111111f;
        break;
    case 1:
        t = 0.0f;
        rate = 0.016666668f;
        break;
    case 2:
        t = 1.0f;
        rate = -0.11111111f;
        break;
    }
}

TObjDFYutai::~TObjDFYutai() {}

#pragma push
#pragma opt_common_subs off
void TObjDFYutai::run_task() {
    f32 progress;
    if (is_player_in_boss_area(player_id) == 0) {
        queue_destruction();
        return;
    }
    t = t + rate;
    progress = t;
    if (progress <= 0.0f) {
        t = 0.0f;
        queue_destruction();
        return;
    }
    if (progress >= 1.0f) {
        t = 1.0f;
        queue_destruction();
    }
}
#pragma pop

#pragma dont_inline off
#pragma inline_depth(1)
void TObjDFYutai::render() {
    Vec v;
    TObjPlayer *p;
    f32 s;
    f32 w;
    p = get_player_by_client_id(player_id);
    if (p == NULL || is_player_in_boss_area(player_id) == 0) {
        return;
    }
    s = yutai_scale_range.lerp(t);
    w = yutai_weight_range.lerp(t);
    VecCopy(&v, &p->position);
    v.y += yutai_height_range.min + t * (yutai_height_range.max - yutai_height_range.min);
    push_matrix();
    post_translate_matrix(&v.x);
    rotate_matrix_y(0, p->rotation_y);
    scale_matrix(0, s, s, s);
    TObjPlayer::draw_player_model_by_id(player_id, w);
    pop_matrix();
}
