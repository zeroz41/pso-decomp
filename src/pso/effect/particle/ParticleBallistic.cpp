#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/effect/sprite/TQuadSprite.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/effect/particle/ParticleBallistic.h"
#include "pso/render/render_util.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/unk/text_8023601C.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleOrbit.h"
#include "pso/effect/particle/TParticleRadial.h"
#include "pso/effect/particle/TParticle.h"
#include "pso/effect/particle/TParticleBallistic.h"

#include "types.h"
#include <stdlib.h>

#include "pso/effect/TEffIndirectSampler.h"
#include "pso/player/TObjPlayer_80083594.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraCtrl.h"
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#include "pso/unk/TLobby.h"
#include "pso/object/key/TOKeyMachine01.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixVector.h"
#include "pso/render/model_render_state.h"

static const Vec ballistic_camera_yaw_axis = { 0.0f, 0.0f, -1.0f };
static const Vec ballistic_camera_pitch_axis = { 0.0f, 0.0f, -1.0f };
static const Vec ballistic_facing_axis = { 0.0f, 0.0f, 1.0f };
static const ParticleAngles ballistic_zero_angles = { 0, 0, 0 };

TParticle *create_ballistic_particle(ParticleParam *entry, Vec *position, ParticleAngles *direction,
                                         TObject *parent, u16 flags, u16 target_id) {
    return new TParticleBallistic(entry, position, direction, parent, flags, target_id);
}

TParticle *TParticleCtrl::create_random_spread(void *param, void *pos, void *parent) {
    return new TParticleBallistic(param, pos, parent);
}

void TParticleBallistic::retire_ballistic_particle_if_done() {
    Vec offset;
    if (param->flags & 8) {
        offset.x = sprite.pos.x - origin.x;
        offset.y = sprite.pos.y - origin.y;
        offset.z = sprite.pos.z - origin.z;
        if (0.0f == vec_squared_length(&offset)) {
            queue_destruction();
            return;
        }
    }
    if (age >= 1.0f) {
        queue_destruction();
    }
}

#pragma push
#pragma fp_contract on
void TParticleBallistic::run_task() {
    NJS_COLOR col;
    Vec toward_camera;
    ParticleParam *p;
    f32 t[2]; // [0] age this sprite.uv_index, [1] fade alpha
    f32 fade_in;
    f32 fade_out;
    f32 ch[3];
    f32 tilt;
    s32 frames;

    if (param->flags & 8) {
        if (age >= 0.5f) {
            approach_camera_vector(&sprite.pos, &origin, fabs_float(step.y));
        } else {
            vec3_add_to(&sprite.pos, &step);
            VecCopy(&velocity, &step);
        }
    } else {
        if (flags & 2) {
            push_matrix_from(&identity_matrix);
            rotate_matrix_x(0, rot_x);
            rotate_matrix_y(0, rot_y);
            rotate_matrix_z(0, rot_z);
            rotate_vector_by_current_matrix(&step, &velocity);
            pop_matrix();
        } else if (rot_x == 0 && rot_y == 0 && rot_z == 0) {
            VecCopy(&velocity, &step);
        } else {
            push_matrix_from(&identity_matrix);
            rotate_matrix_z(0, rot_z);
            rotate_matrix_x(0, rot_x);
            rotate_matrix_y(0, rot_y);
            rotate_vector_by_current_matrix(&step, &velocity);
            pop_matrix();
        }
        vec3_add_to(&sprite.pos, &velocity);
    }
    p = param;
    if ((p->flags & 2) && origin.y > sprite.pos.y) {
        step.y = p->bounce * (p->rise_range * (3.0517578e-05f * rand()) + p->rise_min);
    }
    step.x *= param->speed_decay;
    step.z *= param->speed_decay;
    step.y += param->gravity;
    size_x *= param->scale_decay;
    size_y *= param->scale_decay;
    age += age_rate;
    p = param;
    t[0] = age;
    fade_in = 1.0f;
    fade_out = 1.0f;
    if (p->fade_in_end > t[0]) {
        fade_in = t[0] * fade_in_scale;
    }
    if (1.0f - t[0] < p->fade_out_start) {
        fade_out = (1.0f - t[0]) * fade_out_scale;
    }
    if (fade_in < fade_out) {
        t[1] = fade_in;
    } else {
        t[1] = fade_out;
    }
    if (particle_sprites[sprite_index]->definition->flags & 1) {
        if (flags & 0x100) {
            ch[0] = fade_particle_channel(p->color_rate[0] * t[0] + tint.r, t[1]);
            ch[1] = fade_particle_channel(p->color_rate[1] * t[0] + tint.g, t[1]);
            ch[2] = fade_particle_channel(p->color_rate[2] * t[0] + tint.b, t[1]);
        } else {
            ch[0] = fade_particle_channel(p->color_rate[0] * t[0] + p->color_base[0], t[1]);
            ch[1] = fade_particle_channel(p->color_rate[1] * t[0] + p->color_base[1], t[1]);
            ch[2] = fade_particle_channel(p->color_rate[2] * t[0] + p->color_base[2], t[1]);
        }
        t[1] = 1.0f;
    } else {
        if (flags & 0x100) {
            ch[0] = clamp_particle_channel(p->color_rate[0] * t[0] + tint.r);
            ch[1] = clamp_particle_channel(p->color_rate[1] * t[0] + tint.g);
            ch[2] = clamp_particle_channel(p->color_rate[2] * t[0] + tint.b);
        } else {
            ch[0] = clamp_particle_channel(p->color_rate[0] * t[0] + p->color_base[0]);
            ch[1] = clamp_particle_channel(p->color_rate[1] * t[0] + p->color_base[1]);
            ch[2] = clamp_particle_channel(p->color_rate[2] * t[0] + p->color_base[2]);
        }
    }
    col.argb.a = 254.0f * t[1];
    col.argb.r = 254.0f * ch[0];
    col.argb.g = 254.0f * ch[1];
    col.argb.b = 254.0f * ch[2];
    sprite.color = col.color;
    p = param;
    if (0.0f == p->gravity && 0.0f == p->rise_min && 0.0f == p->speed_min) {
        sprite.angle += (s32)(182.04445f * p->bounce);
    } else if (!(p->flags & 4)) {
        tilt = step.y * (p->tilt * step.x);
        if (fabs_float(tilt) > 20.0f) {
            tilt = 20.0f;
        }
        if (speed < 0.0f) {
            sprite.angle += (s32)(182.04445f * tilt);
        } else {
            sprite.angle -= (s32)(182.04445f * tilt);
        }
    }
    frames = particle_sprites[sprite_index]->definition->uv_count;
    if (param->flags & 0x10) {
        sprite.uv_index = age * (frames - 1);
    } else {
        sprite.uv_index++;
        if (frames <= sprite.uv_index) {
            sprite.uv_index = 0;
        }
    }
    if (flags & 0x10) {
        TObjCollidable *target_obj = find_entity_by_id(target_id);
        if (target_obj == NULL) {
            queue_destruction();
            return;
        }
        Vec *center = (Vec *)target_obj->get_center();
        if (center != NULL) {
            if (flags & 0x20) {
                offset_point_toward_camera(center, &toward_camera, 8.0f);
                sprite.offset.x = toward_camera.x - origin.x;
                sprite.offset.y = toward_camera.y - origin.y;
                sprite.offset.z = toward_camera.z - origin.z;
            } else {
                sprite.offset.x = center->x - origin.x;
                sprite.offset.y = center->y - origin.y;
                sprite.offset.z = center->z - origin.z;
            }
        }
    }
    motion_frame += motion_speed;
    if (motion != NULL && (motion->nbFrame - 1) <= motion_frame) {
        motion_frame = motion->nbFrame - 1;
    }
    retire_ballistic_particle_if_done();
}
#pragma pop

void TParticleBallistic::render() {
    u16 draw_flags;
    int id;
    if ((s32)all_parents_unqueued_for_destruction() == 0) {
        return;
    }
    if (param->flags & 4) {
        Vec end;
        Vec start;
        NJS_POINT2 start_screen;
        NJS_POINT2 end_screen;
        f32 len;
        if (flags & 0x10) {
            start.x = sprite.pos.x + sprite.offset.x;
            start.y = sprite.pos.y + sprite.offset.y;
            start.z = sprite.pos.z + sprite.offset.z;
        } else {
            VecCopy(&start, &sprite.pos);
        }
        end.x = start.x + velocity.x;
        end.y = start.y + velocity.y;
        end.z = start.z + velocity.z;
        len = vector_length(&velocity);
        project_world_to_screen(NULL, &start, &start_screen.x);
        project_world_to_screen(NULL, &end, &end_screen.x);
        end_screen.x -= start_screen.x;
        end_screen.y -= start_screen.y;
        sprite.angle = 10430.38043493439 * atan2_float(end_screen.y, end_screen.x);
        sprite.scale_x = param->tilt * len;
        sprite.scale_y = param->ballistic_streak_height * len;
    } else if (param->flags & 0x40) {
        Vec yaw_axis = ballistic_camera_yaw_axis;
        Vec pitch_axis = ballistic_camera_pitch_axis;
        Vec facing = ballistic_facing_axis;
        f32 yaw_dot;
        f32 pitch_dot;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, rot_y);
        rotate_vector_by_current_matrix(&facing, &facing);
        pop_matrix();
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, camera_ctrl_instance->yaw);
        rotate_vector_by_current_matrix(&yaw_axis, &yaw_axis);
        pop_matrix();
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, camera_ctrl_instance->pitch);
        rotate_vector_by_current_matrix(&pitch_axis, &pitch_axis);
        pop_matrix();
        yaw_dot = vec3_dot(&facing, &yaw_axis);
        pitch_dot = vec3_dot(&facing, &pitch_axis);
        if (pitch_dot < 0.0f) {
            pitch_dot *= -1.0f;
        }
        if (yaw_dot < 0.0f) {
            yaw_dot *= -1.0f;
        }
        draw_flags = flags;
        if (draw_flags & 8) {
            sprite.scale_x = size_x;
            sprite.scale_y = size_y * pitch_dot;
        } else if (draw_flags & 4) {
            sprite.scale_x = size_x * yaw_dot;
            sprite.scale_y = size_y;
        } else {
            sprite.scale_x = size_x * yaw_dot;
            sprite.scale_y = size_y * pitch_dot;
        }
    } else {
        sprite.scale_x = size_x;
        sprite.scale_y = size_y;
    }
    sprite.scale_x *= scale_x;
    sprite.scale_y *= scale_y;
    draw_flags = flags;
    if (draw_flags & 0x200) {
        Vec at;
        if (is_split_screen() != 0 && (flags & 0x400)) {
            return;
        }
        if (texlist == NULL) {
            return;
        }
        if (model == NULL) {
            return;
        }
        at.x = sprite.pos.x + sprite.offset.x;
        at.y = sprite.pos.y + sprite.offset.y;
        at.z = sprite.pos.z + sprite.offset.z;
        ParticleAngles angles = ballistic_zero_angles;
        direction_to_rotation_xz((u8 *)&velocity, &angles.x, &angles.z);
        push_matrix();
        post_translate_matrix(&at.x);
        scale_matrix(0, sprite.scale_x, sprite.scale_x, sprite.scale_x);
        rotate_matrix_z(0, angles.z);
        rotate_matrix_x(0, angles.x);
        if (flags & 0x1000) {
            if (camera_ctrl_instance != NULL) {
                rotate_matrix_y(0, camera_ctrl_instance->yaw);
            }
        } else {
            rotate_matrix_y(0, angles.y);
            rotate_matrix_y(0, sprite.angle);
        }
        if (flags & 0x400) {
            load_projected_texture_matrix(1.33f);
        }
        TParticleCtrl::begin_effect_render();
        if (flags & 0x400) {
            setup_particle_tev(0);
        } else {
            s32 render_flags = model_render_flags;
            saved_model_render_flags = render_flags;
            model_render_flags = render_flags | 0x8021;
            if (is_particle_sprite_additive(render_flags) != 0) {
                apply_particle_model_fade_color(1);
            } else {
                apply_particle_model_fade_color(0);
            }
        }
        TObjFish::set_global_param(texlist);
        set_draw_list_mask(3);
        if (motion != NULL) {
            draw_ginja_model_with_motion(model, motion, motion_frame);
        } else {
            draw_ginja_object(model);
        }
        if (flags & 0x400) {
            reset_particle_tev();
        } else {
            model_render_flags = saved_model_render_flags;
        }
        restore_draw_list_mask();
        TParticleCtrl::end_effect_render();
        pop_matrix();
    } else if (draw_flags & 0x2000) {
        draw_particle_refraction_quad();
    } else if (draw_flags & 0x800) {
        if (param->flags & 0x20) {
            id = sprite_index + 0x36;
        } else {
            id = sprite_index;
        }
        set_depth_buffer_settings_2();
        draw_sprite_quad(id);
        restore_saved_depth_alpha_state();
    } else if (param->flags & 0x20) {
        id = sprite_index + 0x36;
        particle_sprites[id]->append_node_to_tail(&sprite);
    } else {
        particle_sprites[sprite_index]->append_node_to_tail(&sprite);
    }
}

TParticleBallistic::~TParticleBallistic() {}

#pragma push
#pragma fp_contract on
TParticleBallistic::TParticleBallistic(ParticleParam *entry, Vec *position, ParticleAngles *direction, TObject *parent,
                             u16 particle_flags, u16 target)
    : TParticle(entry, parent) {
    s32 life;
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    velocity.z = 0.0f;
    flags = particle_flags;
    if (flags & 0x80) {
        sprite.type = 1;
    }
    target_id = target;
    rot_x = direction->x;
    rot_y = direction->y;
    rot_z = direction->z;
    sprite.pos.x = (entry->spawn_spread.x * ((3.0517578e-05f * (f32)rand()) - 0.5f)) + position->x;
    sprite.pos.z = (entry->spawn_spread.z * ((3.0517578e-05f * (f32)rand()) - 0.5f)) + position->z;
    if (entry->flags & 2) {
        sprite.pos.y = position->y + entry->spawn_spread.y;
    } else {
        sprite.pos.y = (entry->spawn_spread.y * ((3.0517578e-05f * (f32)rand()) - 0.5f)) + position->y;
    }
    origin.x = position->x;
    origin.z = position->z;
    if (entry->flags & 2) {
        origin.y = position->y;
    } else {
        origin.y = position->y;
    }
    size_x = (entry->size_range * (3.0517578e-05f * (f32)rand())) + entry->size_min;
    size_y = size_x;
    life = (s32)(((f32)entry->life_range * (3.0517578e-05f * (f32)rand())) + (f32)entry->life_min);
    if (entry->flags & 1) {
        age_rate = 1.0f / (f32)particle_sprites[sprite_index]->definition->uv_count;
    } else {
        age_rate = 1.0f / (f32)life;
    }
    step.x = (entry->speed_range * (3.0517578e-05f * (f32)rand())) + entry->speed_min;
    step.y = (entry->rise_range * (3.0517578e-05f * (f32)rand())) + entry->rise_min;
    step.z = 0.0f;
    rotate_vec_xz(&step, &step, (s32)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand()))));
    if (0.0f == entry->gravity && 0.0f == entry->rise_min && 0.0f == entry->speed_min) {
        sprite.angle = 0;
        speed = 0.0f;
    } else {
        sprite.angle = (s16)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand())));
        speed = (3.0517578e-05f * (f32)rand()) - 0.5f;
    }
    if (flags & 0x2000) {
        request_indirect_effect(0x1F);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
TParticleBallistic::TParticleBallistic(void *entry, void *position, void *parent)
    : TParticle((ParticleParam *)entry, (TObject *)parent) {
    ParticleParam *src = (ParticleParam *)entry;
    Vec *at = (Vec *)position;
    s32 life;
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    velocity.z = 0.0f;
    sprite.pos.x = (src->spawn_spread.x * ((3.0517578e-05f * (f32)rand()) - 0.5f)) + at->x;
    sprite.pos.z = (src->spawn_spread.z * ((3.0517578e-05f * (f32)rand()) - 0.5f)) + at->z;
    if (src->flags & 2) {
        sprite.pos.y = at->y + src->spawn_spread.y;
    } else {
        sprite.pos.y = (src->spawn_spread.y * ((3.0517578e-05f * (f32)rand()) - 0.5f)) + at->y;
    }
    origin.x = at->x;
    origin.z = at->z;
    if (src->flags & 2) {
        origin.y = at->y;
    } else {
        origin.y = at->y;
    }
    size_x = (src->size_range * (3.0517578e-05f * (f32)rand())) + src->size_min;
    size_y = size_x;
    life = (s32)(((f32)src->life_range * (3.0517578e-05f * (f32)rand())) + (f32)src->life_min);
    if (src->flags & 1) {
        age_rate = 1.0f / (f32)particle_sprites[sprite_index]->definition->uv_count;
    } else {
        age_rate = 1.0f / (f32)life;
    }
    step.x = (src->speed_range * (3.0517578e-05f * (f32)rand())) + src->speed_min;
    step.y = (src->rise_range * (3.0517578e-05f * (f32)rand())) + src->rise_min;
    step.z = 0.0f;
    rotate_vec_xz(&step, &step, (s32)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand()))));
    if (0.0f == src->gravity && 0.0f == src->rise_min && 0.0f == src->speed_min) {
        sprite.angle = 0;
        speed = 0.0f;
    } else {
        sprite.angle = (s16)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand())));
        speed = (3.0517578e-05f * (f32)rand()) - 0.5f;
    }
    if (flags & 0x2000) {
        request_indirect_effect(0x1F);
    }
}
#pragma pop
