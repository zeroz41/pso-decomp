#include "pso/system/BmlResource.h"
#include "pso/render/StripBufferPair.h"
#include "pso/unk/text_80184C2C.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/object/city/CitySeason.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/vector.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/TUnk_804B5E48.h"
#include "pso/object/city/TObjCity_Season_XmasWreath.h"
#include "pso/object/city/TObjCity_Season_EasterEgg.h"
#include "pso/object/city/TObjCity_Season_ValentineHeart.h"
#include "pso/object/city/TObjCity_Season_XmasTree.h"
#include "pso/object/city/TObjCity_Season_HalloweenPumpkin.h"
#include "pso/object/city/TObjCity_Season_21_21.h"
#include "pso/object/city/TObjCity_Season_SonicAdv2.h"
#include "pso/object/city/TObjCity_Season_Board.h"
#include "pso/object/city/TObjCity_Season_FireWorkCtrl.h"
#include "pso/object/city/TObjCity_Season_FireWork.h"
#include "pso/unk/text_803D8F74.h"
#include <stdlib.h>
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D853C.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/animation/ActorAnimationState.h"

const CollisionBody city_season_collision_template = {{0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};
const char TObjCity_Season_EasterEgg__class_name[] = "TObjCity_Season_EasterEgg";
const char TObjCity_Season_ValentineHeart__class_name[] = "TObjCity_Season_ValentineHeart";
const char TObjCity_Season_XmasTree__class_name[] = "TObjCity_Season_XmasTree";
const char TObjCity_Season_XmasWreath__class_name[] = "TObjCity_Season_XmasWreath";
const char TObjCity_Season_HalloweenPumpkin__class_name[] = "TObjCity_Season_HalloweenPumpkin";
const char TObjCity_Season_21_21__class_name[] = "TObjCity_Season_21_21";
const char TObjCity_Season_SonicAdv2__class_name[] = "TObjCity_Season_SonicAdv2";
const char TObjCity_Season_Board__class_name[] = "TObjCity_Season_Board";
const char TObjCity_Season_FireWorkCtrl__class_name[] = "TObjCity_Season_FireWorkCtrl";
const char TObjCity_Season_FireWork__class_name[] = "TObjCity_Season_FireWork";
// The firework area's debug box colour.
const NJS_ARGB lbl_804441FC = {0.8f, 0.2f, 1.0f, 0.9f};

const char *TObjCity_Season_EasterEgg__name = TObjCity_Season_EasterEgg__class_name;
const char *TObjCity_Season_ValentineHeart__name = TObjCity_Season_ValentineHeart__class_name;
const char *TObjCity_Season_XmasTree__name = TObjCity_Season_XmasTree__class_name;
const char *TObjCity_Season_XmasWreath__name = TObjCity_Season_XmasWreath__class_name;
const char *TObjCity_Season_HalloweenPumpkin__name = TObjCity_Season_HalloweenPumpkin__class_name;
const char *TObjCity_Season_21_21__name = TObjCity_Season_21_21__class_name;
const char *TObjCity_Season_SonicAdv2__name = TObjCity_Season_SonicAdv2__class_name;
const char *TObjCity_Season_Board__name = TObjCity_Season_Board__class_name;
const char *TObjCity_Season_FireWorkCtrl__name = TObjCity_Season_FireWorkCtrl__class_name;
const char *TObjCity_Season_FireWork__name = TObjCity_Season_FireWork__class_name;

TUnk_804B5E48::TUnk_804B5E48(TObject *parent, void *set_data, s32 kind, f32 radius) : TObjCollidable(parent) {
    apply_object_set_data(set_data);
    model_index = kind;
    if (get_anim_frame() != NULL) {
        CollisionBody body = city_season_collision_template;
        body.radius = radius;
        init_collision_body_parts(this, &body, 1);
        register_object_by_id();
    } else {
        bodies = NULL;
    }
    anim_time = 0.0f;
}

TUnk_804B5E48::~TUnk_804B5E48() {
    if (bodies != NULL) {
        unregister_object_by_id();
        free_collision_body_parts(this);
    }
}

BmlResource *TUnk_804B5E48::get_anim_frame() { return city_season_easter_egg_model_table[model_index]; }


s32 TUnk_804B5E48::advance_anim_time(s32 motion, f32 step) {
    BmlResource *resource;
    f32 last_frame;
    resource = get_anim_frame();
    if (resource != NULL) {
        last_frame = resource->motions[motion].motion->frameCount - 1;
        anim_time += step;
        if (anim_time >= last_frame) {
            anim_time -= last_frame;
        }
        return 1;
    }
    return 0;
}

TObjCity_Season_EasterEgg::TObjCity_Season_EasterEgg(TObject *parent, void *set_data)
    : TUnk_804B5E48(parent, set_data, 0, 13.0f) {
    Vec pos;
    m_name = TObjCity_Season_EasterEgg__name;
    unk_B4 = 0;
    if (get_anim_frame() != NULL) {
        VecCopy(&pos, &position);
        pos.y += 4.0f;
        emitter = create_particle_emitter(&pos, 0x90);
        VecCopy(&pos, &position);
        pos.y += 25.0f;
        upper_emitter = create_particle_emitter(&pos, 0x91);
    } else {
        emitter = NULL;
        upper_emitter = NULL;
    }
}

TObjCity_Season_EasterEgg::~TObjCity_Season_EasterEgg() {
    if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
    if (upper_emitter != NULL) {
        upper_emitter->queue_destruction();
        upper_emitter = NULL;
    }
}


void *TObjCity_Season_EasterEgg::create(void *set) {
    return new TObjCity_Season_EasterEgg(tl_05, set);
}
void TObjCity_Season_EasterEgg::run_task() {
    if (get_anim_frame() != NULL) {
        unk_B4 += 2;
        if (unk_B4 >= 0xFF) {
            unk_B4 -= 0xFF;
        }
    }
}
void TObjCity_Season_EasterEgg::render() {
    BmlResource *resource = get_anim_frame();
    if (resource != NULL && update_object_view_visibility(800.0f, 50.0f) != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(city_season_xmas_model_table[0]));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        draw_chunk_object(resource->models[1].model);
        draw_chunk_object(resource->models[0].model);
        pop_matrix();
    }
}

TObjCity_Season_ValentineHeart::TObjCity_Season_ValentineHeart(TObject *parent, void *set_data)
    : TUnk_804B5E48(parent, set_data, 1, 13.0f) {
    Vec pos;
    m_name = TObjCity_Season_ValentineHeart__name;
    if (get_anim_frame() != NULL) {
        VecCopy(&pos, &position);
        pos.y += 4.0f;
        emitter = create_particle_emitter(&pos, 0x90);
    } else {
        emitter = NULL;
    }
}

TObjCity_Season_ValentineHeart::~TObjCity_Season_ValentineHeart() {
    if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
}


void *TObjCity_Season_ValentineHeart::create(void *set) {
    return new TObjCity_Season_ValentineHeart(tl_05, set);
}
void TObjCity_Season_ValentineHeart::run_task() { advance_anim_time(1, 0.2f); }
void TObjCity_Season_ValentineHeart::render() {
    BmlResource *resource = get_anim_frame();
    if (resource != NULL && update_object_view_visibility(800.0f, 50.0f) != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(city_season_xmas_model_table[1]));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        draw_model_motion(resource->models[2].model, resource->motions[2].motion, anim_time);
        pop_matrix();
    }
}

TObjCity_Season_XmasTree::TObjCity_Season_XmasTree(TObject *parent, void *set_data)
    : TUnk_804B5E48(parent, set_data, 2, 22.5f) {
    Vec pos;
    m_name = TObjCity_Season_XmasTree__name;
    if (get_anim_frame() != NULL) {
        VecCopy(&pos, &position);
        pos.y += 4.0f;
        emitter = create_particle_emitter(&pos, 0x90);
    } else {
        emitter = NULL;
    }
}

TObjCity_Season_XmasTree::~TObjCity_Season_XmasTree() {
    if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
}


void *TObjCity_Season_XmasTree::create(void *set) {
    return new TObjCity_Season_XmasTree(tl_05, set);
}
void TObjCity_Season_XmasTree::run_task() { advance_anim_time(1, 0.2f); }

void TObjCity_Season_XmasTree::render() {
    BmlResource *resource = get_anim_frame();
    if (resource != NULL && update_object_view_visibility(800.0f, 50.0f) != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(city_season_xmas_model_table[2]));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        draw_model_motion(resource->models[7].model, resource->motions[1].motion, anim_time);
        draw_model_motion(resource->models[6].model, resource->motions[0].motion, anim_time);
        draw_chunk_object(resource->models[8].model);
        draw_chunk_object(resource->models[9].model);
        pop_matrix();
    }
}

TObjCity_Season_XmasWreath::TObjCity_Season_XmasWreath(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TObjCity_Season_XmasWreath__name;
    apply_object_set_data(set_data);
}

TObjCity_Season_XmasWreath::~TObjCity_Season_XmasWreath() {}


void *TObjCity_Season_XmasWreath::create(void *set) {
    return new TObjCity_Season_XmasWreath(tl_05, set);
}
void TObjCity_Season_XmasWreath::render() {
    BmlResource *resource;
    resource = city_season_easter_egg_model_table[2];
    if ((resource != NULL) && (update_object_view_visibility(400.0f, 20.0f) != 0)) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(city_season_xmas_model_table[2]));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        draw_chunk_object(resource->models[5].model);
        pop_matrix();
    }
}

TObjCity_Season_HalloweenPumpkin::TObjCity_Season_HalloweenPumpkin(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TObjCity_Season_HalloweenPumpkin__name;
    apply_object_set_data(set_data);
}

TObjCity_Season_HalloweenPumpkin::~TObjCity_Season_HalloweenPumpkin() {}


void *TObjCity_Season_HalloweenPumpkin::create(void *set) {
    return new TObjCity_Season_HalloweenPumpkin(tl_05, set);
}
void TObjCity_Season_HalloweenPumpkin::run_task() {
    if (city_season_easter_egg_model_table[3] != NULL) {
        this->rotation_y = (this->rotation_y + 0x40);
    }
}

void TObjCity_Season_HalloweenPumpkin::render() {
    BmlResource *resource;
    resource = city_season_easter_egg_model_table[3];
    if ((resource != NULL) && (update_object_view_visibility(800.0f, 80.0f) != 0)) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(city_season_xmas_model_table[3]));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        draw_chunk_object(resource->models[0].model);
        pop_matrix();
    }
}

TObjCity_Season_21_21::TObjCity_Season_21_21(TObject *parent, void *set_data)
    : TUnk_804B5E48(parent, set_data, 4, 23.0f) {
    Vec pos;
    m_name = TObjCity_Season_21_21__name;
    uv_scroll = 0;
    if (get_anim_frame() != NULL) {
        VecCopy(&pos, &position);
        pos.y += 20.0f;
        emitter = create_particle_emitter(&pos, 0x90);
    } else {
        emitter = NULL;
    }
}

TObjCity_Season_21_21::~TObjCity_Season_21_21() {
    if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
}


void *TObjCity_Season_21_21::create(void *set) {
    return new TObjCity_Season_21_21(tl_05, set);
}
void TObjCity_Season_21_21::run_task() {
    if (advance_anim_time(0, 0.3f) != 0) {
        uv_scroll += 2;
        if (uv_scroll >= 0xFF) {
            uv_scroll -= 0xFF;
        }
    }
}
void TObjCity_Season_21_21::render() {
    BmlResource *resource = get_anim_frame();
    if (resource != NULL) {
        if (update_object_view_visibility(800.0f, 60.0f) != 0) {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(city_season_xmas_model_table[4]));
            lbl_805D5B34->scroll_uvs(0, uv_scroll);
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_y(NULL, rotation_y);
            draw_chunk_object(resource->models[1].model);
            draw_model_motion(resource->models[0].model, resource->motions[0].motion, anim_time);
            pop_matrix();
        }
    }
}

TObjCity_Season_SonicAdv2::TObjCity_Season_SonicAdv2(TObject *parent, void *set_data)
    : TUnk_804B5E48(parent, set_data, 5, 3.0f) {
    m_name = TObjCity_Season_SonicAdv2__name;
}

TObjCity_Season_SonicAdv2::~TObjCity_Season_SonicAdv2() {}


void *TObjCity_Season_SonicAdv2::create(void *set) {
    return new TObjCity_Season_SonicAdv2(tl_05, set);
}
s32 TObjCity_Season_SonicAdv2::sub_80183C38() {
    if (this->set_params[0] < 0) {
        return 0;
    }
    if (this->set_params[0] < 4) {
        return this->set_params[0];
    }
    return 3;
}
void TObjCity_Season_SonicAdv2::run_task() { advance_anim_time(sub_80183C38(), 0.3f); }
void TObjCity_Season_SonicAdv2::render() {
    BmlResource *resource;
    s32 model;
    Vec pos;
    Vec normal;
    Vec scale;
    resource = get_anim_frame();
    if (resource != NULL && update_object_view_visibility(800.0f, 20.0f) != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(city_season_xmas_model_table[5]));
        model = sub_80183C38();
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        draw_model_motion(resource->models[model].model, resource->motions[model].motion, anim_time);
        pop_matrix();
        VecCopy(&pos, &position);
        pos.y += 0.037f;
        normal.x = 0.0f;
        normal.y = 1.0f;
        normal.z = 0.0f;
        scale.x = 1.0f;
        scale.y = 0.0f;
        scale.z = 1.3f;
        TObjEneDD::draw_oriented_shadow(&pos, &normal, rotation_y, &scale);
    }
}

void TObjCity_Season_SonicAdv2::debug_draw_model_index() {
    sub_80183C38();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, "<- MDL IDX");
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

TObjCity_Season_Board::TObjCity_Season_Board(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TObjCity_Season_Board__name;
    apply_object_set_data(set_data);
    uv_scroll = 0;
}

TObjCity_Season_Board::~TObjCity_Season_Board() {}


void *TObjCity_Season_Board::create(void *set) {
    return new TObjCity_Season_Board(tl_05, set);
}
void TObjCity_Season_Board::run_task() {
    uv_scroll += 2;
    if (uv_scroll >= 0x100) {
        uv_scroll -= 0x100;
    }
}
void TObjCity_Season_Board::render() {
    if ((lbl_805D5B38 != NULL) && (update_object_view_visibility(800.0f, 200.0f) != 0)) {
        TObjFish::set_global_param(lbl_805D5B44);
        lbl_805D5B48->scroll_uvs(uv_scroll, 0);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        draw_chunk_object((void *)lbl_805D5B3C);
        draw_chunk_object((void *)lbl_805D5B40);
        pop_matrix();
    }
}

TObjCity_Season_FireWorkCtrl::TObjCity_Season_FireWorkCtrl(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TObjCity_Season_FireWorkCtrl__name;
    apply_object_set_data(set_data);
    spawn_delay = 0;
}

TObjCity_Season_FireWorkCtrl::~TObjCity_Season_FireWorkCtrl() {}


void *TObjCity_Season_FireWorkCtrl::create(void *set) {
    return new TObjCity_Season_FireWorkCtrl(tl_05, set);
}
#pragma push
#pragma fp_contract on
void TObjCity_Season_FireWorkCtrl::run_task() {
    Vec to_camera;
    Vec pos;
    f32 dx;
    f32 dz;
    f32 rise;
    if (TLobby__sub_80184C54() != 0) {
        spawn_delay--;
        if (spawn_delay < 0) {
            VecCopy(&to_camera, &position);
            subtract_vector(&to_camera, (Vec *)&camera_ctrl_instance->pos.x);
            if (normalize_vector_safe(&to_camera) < 450.0f && vec3_dot(&to_camera, (Vec *)&ninja_camera.vx) > 0.0f) {
                dx = scale.x * rand_signed_unit();
                dz = scale.z * rand_signed_unit();
                rise = 50.0f * (3.0517578e-05f * rand()) + scale.y;
                VecCopy(&pos, &position);
                pos.x += dx;
                pos.z += dz;
                new TObjCity_Season_FireWork(this, &pos, rise);
            }
            spawn_delay = 3.0f * ((set_params[0] + 0x3C) * (3.0517578e-05f * rand()));
        }
    }
}
#pragma pop

void TObjCity_Season_FireWorkCtrl::sub_8018355C() {
    if (update_object_view_visibility(250.0f, 10.0f) != 0) {
        Vec size;
        NJS_ARGB color = lbl_804441FC;
        rotation_z = 0;
        rotation_x = 0;
        size.x = scale.x;
        size.y = 3.0f;
        size.z = scale.z;
        fn_80141CB8(&position, &rotation_x, &size, &color);
    }
}
void TObjCity_Season_FireWorkCtrl::vfunc_13(s32) {
    sub_8018355C();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x13001C, "<- AREA WIDTH");
    debug_printf_at(0x13001D, "<- RISE HEIGHT");
    debug_printf_at(0x13001E, "<- AREA DEPTH");
    debug_printf_at(0x130020, "<- FREQ");
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

TObjCity_Season_FireWork::TObjCity_Season_FireWork(TObject* parent, void* position, f32 riseHeight) : TObject(parent) {
    m_name = TObjCity_Season_FireWork__name;
    VecCopy(&pos, (const Vec *)position);
    state = 0;
    handle = NULL;
    limit = riseHeight;
    timer = 0;
    burstEffectId = 0;
    riseDistance = 0.0f;
}

TObjCity_Season_FireWork::~TObjCity_Season_FireWork() {
    if (handle != NULL) { handle->queue_destruction(); handle = NULL; }
}

void TObjCity_Season_FireWork::run_task() {
    switch (state) {
    case 0:
        if (handle == NULL) {
            handle = spawn_continuous_particle_effect_with_flags(&pos, 0x84, 0x40);
        }
        if (handle != NULL) {
            riseDistance += 4.0f;
            pos.y += 4.0f;
            if (riseDistance >= limit) {
                riseDistance = 0.0f;
                timer = 0;
                state = 1;
                handle->queue_destruction();
                handle = NULL;
            } else {
                handle->set_position(&pos);
            }
        }
        break;
    case 1:
        if (timer == 10) {
            spawn_particle_effect_with_flags(&pos, 0x85, 0x40);
            spawn_particle_effect_with_flags(&pos, 0x86, 0x40);
        }
        timer++;
        if (timer >= 15) {
            f32 r = 3.0517578e-05f * (f32)rand();
            timer = 0;
            if (r < 0.33f) {
                burstEffectId = 0x87;
                state = 2;
            } else if (r < 0.66f) {
                burstEffectId = 0x88;
                state = 2;
            } else {
                state = 3;
            }
        }
        break;
    case 2:
        if (timer == 0 || timer == 4 || timer == 8) {
            spawn_particle_effect_with_flags(&pos, burstEffectId, 0x40);
        }
        timer++;
        pos.y -= 0.8f;
        if (timer > 8) {
            state = 4;
        }
        break;
    case 3:
        if (timer == 0 || timer == 4 || timer == 8) {
            s32 angle[3];
            angle[0] = 0;
            angle[1] = TObjPlayer::calc_random_scaled();
            angle[2] = TObjPlayer::calc_random_scaled();
            create_oneshot_particle_emitter(&pos, angle, 0x89, 0x40);
        }
        timer++;
        pos.y -= 0.8f;
        if (timer > 8) {
            state = 4;
        }
        break;
    case 4:
        queue_destruction();
        break;
    }
}
