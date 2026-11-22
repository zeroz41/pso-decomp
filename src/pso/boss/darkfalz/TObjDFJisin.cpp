#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/darkfalz/TObjDFHorming.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"

struct NJS_OBJECT;
#include "pso/boss/darkfalz/TBoss4DarkFalz_8004C93C.h"
#include "pso/system/vector.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/PadRumble.h"
#include "pso/player/PlayerClassFlags.h"
#include "pso/boss/darkfalz/TObjDFTenchuFuru.h"
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
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TNowLoading.h"
#include "dolphin/mtx.h"
#include <stddef.h>
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer_80052374.h"
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

typedef struct Obj_8005063C {
    u8 pad0[0x2FC];
    Vec f2fc;
    u8 pad308[0x348 - 0x308];
    Vec dir;
    u8 pad354[0x364 - 0x354];
    f32 f364;
    s32 state;
    Vec f36c;
    f32 f378;
    f32 f37c;
} Obj_8005063C;

extern "C" {
f32 fabs_float(f32);
void queue_destruction__7TObjectFv(void *);
void steer_homing_direction(Obj_8005063C *self);



}



// The Jisin: a ring of fire that grows by 25 a frame around its centre (TBoss4Type2::create_jisin).
class TObjDFJisin : public TObject {
public:
    TObjDFJisin(TObject *parent, s32 angle);
    virtual ~TObjDFJisin();
    virtual void run_task();

    Vec center;
    f32 radius;
};
class TObjDFBeamCursor : public TObject {
public:
    TObjDFBeamCursor(TObject *parent, const Vec *position);
    virtual ~TObjDFBeamCursor();
    virtual void run_task();

    s32 timer;    // spawns its particle effect at position when it runs out
    Vec position;
};
class TObjDFRecBall : public TObject {
public:
    TObjDFRecBall(TObject *parent, const Vec *position, const Vec *target);
    virtual ~TObjDFRecBall();
    virtual void run_task();

    Vec pos;
    Vec target;
    Vec vel;
    f32 speed;
    void *model; // its particle emitter
    s32 timer;
};

struct Ang_80050808 { s32 x, y, z; };

extern "C" {
u16 find_nearest_visible_player(void *, int, f32);
int queue_destruction__13TObjDFHormingFPv(void* p);
}
void direction_to_rotation_xz(u8 *dir, s32 *rot_a, s32 *rot_b);
extern "C" {
s32 minimap_render_dot(void *, int, int, int);
void run_task__13TObjDFHormingFv(u8 *self);

typedef struct Hit_80050D74 {
    s32 type;
    f32 value;
} Hit_80050D74;

struct VBase_80050D74 { u8 pad[0x18]; };

struct VObj_80050D74 : VBase_80050D74 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21(s32, Hit_80050D74 *, s32, s32, s32);
};

struct Player_80050D74 : VObj_80050D74 {
    u8 pad1c[0x38 - 0x1c];
    Vec pos;
    u8 pad44[0x890 - 0x44];
    u32 class_flags;
};

typedef struct Obj_80050EB4 {
    u8 pad0[0x1C];
    f32 cx;
    f32 f20;
    f32 cz;
    f32 radius;
} Obj_80050EB4;

struct Ball_8005123C {
    u8 pad0[0x1C];
    Vec pos;
    Vec target;
    Vec vel;
    f32 speed;
    void *model;
    s32 timer;
};


u16 get_entity_id(void *);
f32 atan2_float(f32 y, f32 x);
f32 newton_sqrtf(f32);
}
void damage_players_near_point(s32 arg0, Vec *arg1);
extern "C" {
void fn_spawn_particle_f3_with_flags(s32 arg0, saddr arg1);
void * create__16TObjDFBeamCursorFPvPv(void *parent, void *arg1);
void * create__13TObjDFRecBallFPvPvPv(void *parent, void *position, void *arg2);




}


extern const char *TObjDFRecover__name;



struct RecoveredFields_80051AD0_var_r31 {
    s32 field_0;
    u8 unknown_4[0x28];
    u8 * field_2C;
    u8 * field_30;
};

void get_current_matrix(void *m);
int TObjDFTenchuFuru__matrix_node_index;
extern "C" {
Vec lbl_804FF228;
Vec lbl_804FF234;
Mtx34 df_captured_matrix_pair[2];
void TObjDFTenchuFuru__sub_80051A7C(void);






LAYOUT_ASSERT(RecoveredFields_80051AD0_var_r31_0_offset, offsetof(RecoveredFields_80051AD0_var_r31, field_0) == 0x0);
LAYOUT_ASSERT(RecoveredFields_80051AD0_var_r31_2C_offset, offsetof(RecoveredFields_80051AD0_var_r31, field_2C) == 0x2C);
LAYOUT_ASSERT(RecoveredFields_80051AD0_var_r31_30_offset, offsetof(RecoveredFields_80051AD0_var_r31, field_30) == 0x30);

}



#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803DC86C.h"
#include "pso/boss/darkfalz/TObjDFUsoTower.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/unk/text_803D853C.h"

extern u8 *camera_ctrl_instance;


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
    this->texlist = (saddr)get_bml_texlist(TOBoss4::model_resource, 5);
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
        Vec v = *(Vec *)(camera_ctrl_instance + 0x178);
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
    f32 temp_f1;

    temp_f1 = fade_alpha;
    if (0.0f != temp_f1) {
        if (temp_f1 < 1.0f) {
            TObjPlayer__sub_80052390(temp_f1);
            set_color_blend_mode(1, 4, 5, 0);
        }
        push_matrix();
        post_translate_matrix(&this->position.x);
        TObjFish::set_global_param(this->texlist);
        draw_ginja_object(this->model);
        pop_matrix();
        if (fade_alpha < 1.0f) {
            TObjPlayer::sync_player_globals();
        }
    }
}

void TObjPlayer::draw_player_model_by_id(s32 arg0, f32 alpha) {
    u8 *p;
    uaddr m8b0;
    u32 m8ac;
    s32 a1c;
    uaddr m8b4;
    s32 b88;
    uaddr m34;
    s32 cf4;

    if (0.0f == alpha) {
        return;
    }
    if ((u16)arg0 == 0xFFFF) {
        return;
    }
    p = (u8 *)get_player_by_client_id((u16)arg0);
    if (p == NULL || *(s32 *)((s8 *)p + 0xCFC) != 0) {
        return;
    }
    m34 = *(u32 *)((s8 *)p + 0x34);
    a1c = (saddr)(p + 0xA1C);
    m8b0 = *(u32 *)((s8 *)p + 0x8B0);
    b88 = (saddr)(p + 0xB88);
    m8ac = *(u32 *)((s8 *)p + 0x8AC);
    m8b4 = *(u32 *)((s8 *)p + 0x8B4);
    cf4 = (saddr)(p + 0xCF4);
    ((TObjDFTenchuFuru *)m34)->draw_node_tree();
    if (alpha < 1.0f) {
        TObjPlayer__sub_80052390(alpha);
    }
    TObjFish::set_global_param(cf4);
    draw_chunk_object((void *)m34);
    if (m8b4 != 0U) {
        push_matrix();
        post_translate_matrix(&lbl_804FF234.x);
        TObjFish::set_global_param(b88);
        draw_chunk_object((void *)m8b4);
        pop_matrix();
    }
    if (m8b0 != 0U) {
        TCharaMaking::enable_making();
        push_matrix();
        post_translate_matrix(&lbl_804FF228.x);
        TObjFish::set_global_param(a1c);
        draw_chunk_object((void *)m8b0);
        pop_matrix();
        TCharaMaking::clear_flag_bit0();
    }
    if (alpha < 1.0f) {
        TObjPlayer::sync_player_globals();
    }
    if (m8ac != 0U) {
        TCharaMaking::enable_making();
        push_matrix();
        post_translate_matrix(&lbl_804FF228.x);
        TObjFish::set_global_param(a1c);
        TCharaMaking__draw_colored_hair(alpha, (s32)m8ac, (CharacterAppearanceFields *)(p + 0x85C), 0);
        pop_matrix();
        TCharaMaking::clear_flag_bit0();
    }
}

void boss6type2_draw_models(s32 arg0, s32 arg1, s32 arg2, uaddr arg3, uaddr arg4, u32 model, uaddr arg6, saddr appearance, f32 alpha) {
    if (0.0f != alpha) {
        ((TObjDFTenchuFuru *)arg3)->draw_node_tree();
        if (alpha < 1.0f) {
            TObjPlayer__sub_80052390(alpha);
        }
        TObjFish::set_global_param(arg0);
        draw_chunk_object((void *)arg3);
        if (arg6 != 0U) {
            push_matrix();
            post_translate_matrix(&lbl_804FF234.x);
            TObjFish::set_global_param(arg2);
            draw_chunk_object((void *)arg6);
            pop_matrix();
        }
        if (arg4 != 0U) {
            TCharaMaking::enable_making();
            push_matrix();
            post_translate_matrix(&lbl_804FF228.x);
            TObjFish::set_global_param(arg1);
            draw_chunk_object((void *)arg4);
            pop_matrix();
            TCharaMaking::clear_flag_bit0();
        }
        if (alpha < 1.0f) {
            TObjPlayer::sync_player_globals();
        }
        if (model != 0U) {
            TCharaMaking::enable_making();
            push_matrix();
            post_translate_matrix(&lbl_804FF228.x);
            TObjFish::set_global_param(arg1);
            TCharaMaking__draw_colored_hair(alpha, (s32)model, (CharacterAppearanceFields *)appearance, 0);
            pop_matrix();
            TCharaMaking::clear_flag_bit0();
        }
    }
}

extern "C" {
void TObjPlayer::draw_player_model_by_client(u16 arg0, saddr arg1, f32 farg0, f32 alpha) {
    u8 *p;
    uaddr a;
    u32 b;
    u8 *c;
    uaddr d;
    u8 *e;
    saddr f;
    u8 *g;
    if (0.0f == alpha) {
        return;
    }
    if (arg0 == 0xFFFF) {
        return;
    }
    p = (u8 *)get_player_by_client_id(arg0);
    if (p == NULL || *(s32 *)((s8 *)p + 0xCFC) != 0) {
        return;
    }
    c = p + 0xA1C;
    a = *(u32 *)((s8 *)p + 0x8B0);
    e = p + 0xB88;
    b = *(u32 *)((s8 *)p + 0x8AC);
    d = *(u32 *)((s8 *)p + 0x8B4);
    g = p + 0xCF4;
    f = *(s32 *)((s8 *)p + 0x34);
    if (alpha < 1.0f) {
        TObjPlayer__sub_80052390(alpha);
    }
    TObjFish::set_global_param((saddr)g);
    TObjDFTenchuFuru::register_callback();
    draw_model_motion((void *)f, (void *)arg1, farg0);
    TObjDFTenchuFuru__sub_80051A7C();
    if (d != 0) {
        push_matrix_from(df_captured_matrix_pair[1]);
        TObjFish::set_global_param((saddr)e);
        draw_chunk_object((void *)d);
        pop_matrix();
    }
    if (a != 0) {
        TCharaMaking::enable_making();
        push_matrix_from(df_captured_matrix_pair[0]);
        TObjFish::set_global_param((saddr)c);
        draw_chunk_object((void *)a);
        pop_matrix();
        TCharaMaking::clear_flag_bit0();
    }
    if (alpha < 1.0f) {
        TObjPlayer::sync_player_globals();
    }
    if (b != 0) {
        TCharaMaking::enable_making();
        push_matrix_from(df_captured_matrix_pair[0]);
        TObjFish::set_global_param((saddr)c);
        TCharaMaking__draw_colored_hair(alpha, b, (CharacterAppearanceFields *)(p + 0x85C), 0);
        pop_matrix();
        TCharaMaking::clear_flag_bit0();
    }
}
}

extern "C" {
void TObjDFTenchuFuru::draw_node_tree() { TObjDFTenchuFuru__matrix_node_index = 0; push_matrix(); set_matrix_identity((u8 *)((void*)0)); transform_node_tree(); pop_matrix(); }
}

extern "C" {
void TObjDFTenchuFuru::transform_node_tree() {
    u8 *self = (u8 *)this;
    u8 *temp_r3;
    u8 *var_r31;
    var_r31 = self;
    do {
        push_matrix();
        post_translate_matrix((f32 *)(var_r31 + 8));
        rotate_matrix_by_node_angles((s32 *)(var_r31 + 0x14), (u32) (((RecoveredFields_80051AD0_var_r31 *)var_r31)->field_0 & 0x20));
        scale_current_matrix((f32 *)(var_r31 + 0x20));
        switch ((s32) (*(s32 *)&TObjDFTenchuFuru__matrix_node_index)) {
        case 0x3B:
            matrix_mult_vec(0, &dark_falz_jisin_zero_vec, &lbl_804FF228);
            break;
        case 0x3A:
            matrix_mult_vec(0, &dark_falz_jisin_zero_vec, &lbl_804FF234);
            break;
        }
        (*(s32 *)&TObjDFTenchuFuru__matrix_node_index) += 1;
        temp_r3 = (u8 *)(((RecoveredFields_80051AD0_var_r31 *)var_r31)->field_2C);
        if (temp_r3 != NULL) {
            ((TObjDFTenchuFuru *)temp_r3)->transform_node_tree();
        }
        pop_matrix();
        var_r31 = (u8 *)(((RecoveredFields_80051AD0_var_r31 *)var_r31)->field_30);
    } while (var_r31 != NULL);
}
}

extern "C" {
void TObjDFTenchuFuru::register_callback() { TObjDFTenchuFuru__matrix_node_index = 0; set_chunk_model_node_callback(TObjDFTenchuFuru::capture_matrix_by_frame); }
}

extern "C" {
void TObjDFTenchuFuru__sub_80051A7C(void) { set_chunk_model_node_callback(0); }
}

extern "C" {
void TObjDFTenchuFuru::capture_matrix_by_frame(NJS_OBJECT *) {
    switch ((s32) (*(s32 *)&TObjDFTenchuFuru__matrix_node_index)) {
    case 0x3B:
        get_current_matrix(df_captured_matrix_pair[0]);
        break;
    case 0x3A:
        get_current_matrix(df_captured_matrix_pair[1]);
        break;
    }
    (*(s32 *)&TObjDFTenchuFuru__matrix_node_index) += 1;
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

TObjDFRecover *TObjDFRecover::create(TObject *parent, u16 id, const f32 *position) {
    return new TObjDFRecover(parent, id, position);
}

TObjDFRecover::TObjDFRecover(TObject *parent, u16 id, const f32 *position) : TObject(parent) {
    m_name = TObjDFRecover__name;
    target_id = id;
    effect = NULL;
    VecCopy((Vec *)cached_position, (const Vec *)position);
    phase = 0;
    countdown = 5;
}

TObjDFRecover::~TObjDFRecover() {
    if (effect != 0) TParticleCtrl::release(effect);
}

#pragma push
#pragma fp_contract on
void TObjDFRecover::run_task() {
    f32 position[3];
    s32 current_phase;
    saddr target_address;
    uaddr effect_address;
    u16 id;
    if (TBoss4DarkFalz::is_state_ready() == 0) {
        queue_destruction();
        return;
    }
    id = target_id;
    if ((id == 0xFFFF) || ((target_address = (saddr)get_player_by_client_id(id)) == 0)) {
        queue_destruction();
        return;
    }
    VecCopy((Vec *)position, (const Vec *)(target_address + 0x2FC));
    countdown = countdown - 1;
    current_phase = phase;
    switch (current_phase) {
    case 0:
        if (countdown <= 0) {
            effect_address = (uaddr)create_particle_emitter(position, 0xEB);
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
        ((TParticleCtrl *)effect)->set_position(position);
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
            ((s32 (*)(int, void *, void *))create__13TObjDFRecBallFPvPvPv)((saddr)m_up, position, cached_position);
        }
        if (countdown <= 0) {
            queue_destruction();
        }
        break;
    }
}
#pragma pop

extern "C" {
void * create__13TObjDFRecBallFPvPvPv(void *parent, void *position, void *arg2) {
    return new TObjDFRecBall((TObject *)parent, (const Vec *)position, (const Vec *)arg2);
}
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
    Ball_8005123C *o = (Ball_8005123C *)this;
    Vec d;

    if (--o->timer < 0 || o->model == 0) {
        ((TObject *)o)->queue_destruction();
        return;
    }
    if ((o->speed += 0.26666668f) > 9.0f) {
        o->speed = 9.0f;
    }
    VecCopy((Vec *)&d, (const Vec *)&o->target);
    subtract_vector(&d, &o->pos);
    if (vector_length(&d) > 0.01f) {
        normalize_vector(&d);
    } else {
        d.x = 1.0f;
        d.z = d.y = 0.0f;
    }
    if (vector_length(&o->vel) > 0.01f) {
        normalize_vector(&o->vel);
    } else {
        o->vel.x = 1.0f;
        o->vel.y = 0.0f;
        o->vel.z = 0.0f;
    }
    o->vel.x = o->speed * (0.9f * o->vel.x + 0.100000024f * d.x);
    o->vel.y = o->speed * (0.9f * o->vel.y + 0.100000024f * d.y);
    o->vel.z = o->speed * (0.9f * o->vel.z + 0.100000024f * d.z);
    vec3_add_to(&o->pos, &o->vel);
    ((TParticleCtrl *)o->model)->set_position(&o->pos);
    if (xyz_distance(&o->pos, &o->target) <= o->speed) {
        ((TObject *)o)->queue_destruction();
    }
}
#pragma pop

void * create__16TObjDFBeamCursorFPvPv(void *parent, void *arg1) {
    return new TObjDFBeamCursor((TObject *)parent, (const Vec *)arg1);
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

    step = (s32)(1638400.0f / (6.28f * ((Obj_80050EB4 *)this)->radius));
    count = 0;
    v.y = 0.0f;
    max = 255.0f;
    for (ang = 0; ang < 0x10000; ang += step) {
        v.x = ((Obj_80050EB4 *)this)->radius * sin_table_lookup(ang) + ((Obj_80050EB4 *)this)->cx;
        v.z = ((Obj_80050EB4 *)this)->radius * cos_table_lookup(ang) + ((Obj_80050EB4 *)this)->cz;
        if (!(vector_length(&v) > max)) {
            ((void (*)(void *, Vec *))fn_spawn_particle_f3_with_flags)(this, &v);
            ((void (*)(void *, Vec *))damage_players_near_point)(this, &v);
            count++;
        }
    }
    if (((Obj_80050EB4 *)this)->radius > 300.0f && count == 0) {
        queue_destruction();
        return;
    }
    ((Obj_80050EB4 *)this)->radius += 25.0f;
}
#pragma pop

extern "C" {
void fn_spawn_particle_f3_with_flags(s32 arg0, saddr arg1) {
    Vec position;
    uaddr particle_effect;
    VecCopy((Vec *)(&position.x), (const Vec *)(arg1));
    position.y += 2.0f;
    particle_effect = (uaddr)spawn_particle_effect(&position, 0xF3);
    if (particle_effect != 0U) {
        ((TParticleCtrl *)particle_effect)->set_flags(0x40);
    }
}
}

void damage_players_near_point(s32 arg0, Vec *arg1) {
    Vec pos = *arg1;
    DirectAttackPayload hit;
    s32 i;
    Player_80050D74 *p;
    if (TBoss4DarkFalz::is_state_ready() == 0) {
        return;
    }
    hit.kind = 0x11;
    hit.power = 0.0f;
    for (i = 0; i < TLobby::get_game_mode(); i++) {
        p = (Player_80050D74 *)TObjPlayer::get_player_data(i);
        if (p != NULL && TBoss4Type3__sub_8005254C(get_entity_id(p)) != 0 &&
            !(p->class_flags & CLASS_FLAG_ANDROID) &&
            !(xyz_distance(&pos, &p->pos) > 20.0f)) {
            DirectAttackPayload h = hit;
            reinterpret_cast<TObjChara *>(p)->receive_direct_attack(TBoss4DarkFalz__sub_8004C1B4(), h, NULL, -1, -1);
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
    m_334 = target_id;
    m_338 = 150;
    if (game_difficulty_selection == 3) {
        m_338 = 300;
    }
    VecCopy(&body_center, VecCopy(&prev_position, VecCopy(&spawn_position, position)));
    scale = newton_sqrtf(1.08f);
    ang = (s32)(16384.0f * (0.000030517578f * (f32)rand() - 0.5f));
    p = get_player_by_client_id(m_334);
    if (p != NULL) {
        ang = 0;
    } else {
        ang += (s32)(10430.38043493439 * atan2_float(p->position.x - 10000.0f, p->position.z));
    }
    velocity.x = 1.2f * sin_table_lookup(ang) / scale;
    velocity.z = 1.2f * cos_table_lookup(ang) / scale;
    velocity.y = -6.0f / scale;
    speed = 6.0f;
    m_360 = *(s32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x38)) + 0x28);
    homing_rate = *(f32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x38)) + 0);
    if (homing_rate < 0.0f || homing_rate > 1.0f) {
        homing_rate = 0.5f;
    }
    m_378 = -50.0f * homing_rate + 60.0f;
    for (i = 0; i < 2; i++) {
        if ((effects[i] = create_particle_emitter(&body_center, TObjDFJisin__particle_emitter_id_table[i])) != NULL) {
            effects[i]->set_flags(0x40);
        }
    }
    m_368 = 0;
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

extern "C" {
void run_task__13TObjDFHormingFv(u8 *self) {
    Ang_80050808 rot;
    Vec d;
    DirectAttackPayload s;
    u8 *p;
    s32 i;
    if (TObjEneDD::query_teammate_state() != 0) {
        return;
    }
    if (((TObjDFHorming *)self)->m_334 == 0xFFFF || (p = (u8 *)get_player_by_client_id(((TObjDFHorming *)self)->m_334)) == NULL) {
        ((TObject *)self)->queue_destruction();
        return;
    }
    VecCopy((Vec *)(self + 0x36C), (const Vec *)(p + 0x2FC));
    *(f32 *)((s8 *)self + 0x37C) = xyz_distance((Vec *)(self + 0x2FC), (Vec *)(self + 0x36C));
    VecCopy((Vec *)(self + 0x44), (const Vec *)(self + 0x2FC));
    switch (*(s32 *)&((TObjDFHorming *)self)->m_368) {
    case 0:
        ((TObjDFHorming *)self)->sub_8005076C();
        break;
    case 1:
        steer_homing_direction((Obj_8005063C *)self);
        break;
    case 2:
        ((TObjDFHorming *)self)->check_attack_trigger();
        break;
    }
    normalize_vector((Vec *)(self + 0x348));
    *(f32 *)((s8 *)self + 0x348) *= *(f32 *)((s8 *)self + 0x354);
    *(f32 *)((s8 *)self + 0x34C) *= *(f32 *)((s8 *)self + 0x354);
    ((TObjDFHorming *)self)->velocity.z *= *(f32 *)((s8 *)self + 0x354);
    vec3_add_to((Vec *)(self + 0x2FC), &((TObjDFHorming *)self)->velocity);
    {
        s32 id = find_nearest_visible_player(self, 0, 7.5f);
        if (id != 0xFFFF && (p = (u8 *)get_player_by_client_id(id)) != NULL) {
            if (TObjDFHorming::is_boss_active() != 0) {
                s.kind = 0;
                s.power = static_cast<s32>(reinterpret_cast<TObjDFHorming *>(self)->m_360);
                {
                    DirectAttackPayload t = s;
                    reinterpret_cast<TObjChara *>(p)->receive_direct_attack(TBoss4DarkFalz__sub_8004C1AC(), t, NULL, -1, -1);
                }
            }
            queue_destruction__13TObjDFHormingFPv(self);
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        if (*(u32 *)((s8 *)(self + i * 4) + 0x358) != 0) {
            if (i == 1) {
                VecCopy((Vec *)&d, (const Vec *)(self + 0x2FC));
                subtract_vector(&d, (Vec *)(self + 0x44));
                direction_to_rotation_xz((u8 *)&d, &rot.x, &rot.z);
                rot.y = 0;
                ((TParticleCtrl *)((void *)*(uaddr *)((s8 *)(self + i * 4) + 0x358)))->set_direction(&rot);
            }
            ((TParticleCtrl *)(void *)*(uaddr *)((s8 *)(self + i * 4) + 0x358))->set_position(self + 0x2FC);
        }
    }
    minimap_render_dot(self + 0x2FC, -0x5DB4, 1, 0);
    if (--*(s32 *)&((TObjDFHorming *)self)->m_338 < 0) {
        ((TObject *)self)->queue_destruction();
    }
}
}

extern "C" {
int queue_destruction__13TObjDFHormingFPv(void* p) { return ((int (*)(void*))queue_destruction__7TObjectFv)(p); }
}

extern "C" {
void TObjDFHorming::sub_8005076C() {
    f32 temp_f1;
    temp_f1 = *(f32 *)((s8 *)((u8 *)this) + 0x370) - this->body_center.y;
    if (temp_f1 > 0.0f) {
        *(f32 *)((s8 *)((u8 *)this) + 0x34C) += 0.05f;
    } else {
        *(f32 *)((s8 *)((u8 *)this) + 0x34C) -= 0.05f;
    }
    if (fabs_float(temp_f1) < 50.0f) {
        this->m_368 = 1;
    }
}
}

extern "C" {
void steer_homing_direction(Obj_8005063C *self) {
    Vec d;
    f32 k;
    f32 inv;
    VecCopy((Vec *)&d, (const Vec *)&self->f36c);
    subtract_vector(&d, &self->f2fc);
    if (vector_length(&d) <= 0.01f ||
        vector_length(&self->dir) <= 0.01f) {
        ((TObject *)self)->queue_destruction();
        return;
    }
    normalize_vector(&d);
    normalize_vector(&self->dir);
    k = -0.3f * self->f364 + 0.8f;
    Vec prev = self->dir;
    inv = 1.0f - k;
    self->dir.x = k * self->dir.x + inv * d.x;
    self->dir.y = k * self->dir.y + inv * d.y;
    self->dir.z = k * self->dir.z + inv * d.z;
    if (self->f37c <= self->f378 && xyz_distance(&self->dir, &prev) <= 0.001f) {
        self->state = 2;
    }
}
}

// TObjDFYutai, TBoss4Type3::create_yutai and TObjDFHorming::check_attack_trigger open the TU's text.
void TObjDFHorming::check_attack_trigger() {
    if (((s32) game_difficulty_selection == 3) && ((s32) this->m_338 >= 0x78) && (*(f32 *)&this->unk_37C > (2.5f * *(f32 *)&(this->m_378)))) {
        this->m_368 = 1;
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
    f32 temp_f1;
    if (TBoss4Type3__sub_8005254C(player_id) == 0) {
        queue_destruction();
        return;
    }
    t = t + rate;
    temp_f1 = t;
    if (temp_f1 <= 0.0f) {
        t = 0.0f;
        queue_destruction();
        return;
    }
    if (temp_f1 >= 1.0f) {
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
    if (p == NULL || TBoss4Type3__sub_8005254C(player_id) == 0) {
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
