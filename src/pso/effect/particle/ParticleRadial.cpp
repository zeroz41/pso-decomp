#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/effect/sprite/TQuadSprite.h"
#include "pso/effect/particle/ParticleRadial.h"
#include "pso/render/render_util.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleBallistic.h"
#include "pso/effect/particle/TParticleOrbit.h"
#include "pso/effect/particle/TParticle.h"
#include "pso/effect/particle/TParticleRadial.h"

#include "types.h"
#include <stdlib.h>
#include "pso/effect/TEffIndirectSampler.h"
#include "pso/player/TObjPlayer_80083594.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
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
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixVector.h"
#include "pso/render/model_render_state.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"

static const ParticleAngles radial_particle_zero_angles = { 0, 0, 0 };


TParticle *create_radial_particle(ParticleParam *entry, Vec *position, TObject *parent, u16 flags,
                                      u16 target_id) {
    return new TParticleRadial(entry, position, parent, flags, target_id);
}

TParticle *create_random_particle(void *param, void *pos, void *parent) {
    return new TParticleRadial(param, pos, parent);
}

void TParticleRadial::check_radial_particle_retire() {
    if ((age >= 1.0f) || (0.0f == vec_squared_length(&step))) {
        queue_destruction();
    }
}

#pragma push
#pragma fp_contract on
void TParticleRadial::run_task() {
    NJS_COLOR col;
    Vec target;
    f32 t[2];                  // [0] age this sprite.uv_index, [1] fade alpha; kept in memory
    f32 fade_in;
    f32 fade_out;
    f32 rest;
    f32 ch[3];
    ParticleParam *p;
    s32 frames;
    u32 last;

    speed *= param->speed_decay;
    approach_vector_fixed_distance(&sprite.pos, &origin, &target, speed);
    step.x = target.x - sprite.pos.x;
    step.y = target.y - sprite.pos.y;
    step.z = target.z - sprite.pos.z;
    vec3_add_to(&sprite.pos, &step);
    fade_in = 1.0f;
    fade_out = fade_in;
    size_x *= param->scale_decay;
    size_y *= param->scale_decay;
    age += age_rate;
    p = param;
    t[0] = age;
    if (p->fade_in_end > t[0]) {
        fade_in = t[0] * fade_in_scale;
    }
    rest = 1.0f - t[0];
    if (rest < p->fade_out_start) {
        fade_out = rest * fade_out_scale;
    }
    t[1] = (fade_in < fade_out) ? fade_in : fade_out;
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
    } else if (flags & 0x100) {
        ch[0] = clamp_particle_channel(p->color_rate[0] * t[0] + tint.r);
        ch[1] = clamp_particle_channel(p->color_rate[1] * t[0] + tint.g);
        ch[2] = clamp_particle_channel(p->color_rate[2] * t[0] + tint.b);
    } else {
        ch[0] = clamp_particle_channel(p->color_rate[0] * t[0] + p->color_base[0]);
        ch[1] = clamp_particle_channel(p->color_rate[1] * t[0] + p->color_base[1]);
        ch[2] = clamp_particle_channel(p->color_rate[2] * t[0] + p->color_base[2]);
    }
    col.argb.a = 254.0f * t[1];
    col.argb.r = 254.0f * ch[0];
    col.argb.g = 254.0f * ch[1];
    col.argb.b = 254.0f * ch[2];
    sprite.color = col.color;
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
        sprite.offset.x = center->x - origin.x;
        sprite.offset.y = center->y - origin.y;
        sprite.offset.z = center->z - origin.z;
    }
    if (motion != NULL) {
        motion_frame += motion_speed;
        last = motion->nbFrame - 1;
        if ((f32)last <= motion_frame) {
            motion_frame = last;
        }
    }
    check_radial_particle_retire();
}
#pragma pop

void TParticleRadial::render() {
    NJS_POINT2 start_screen;
    NJS_POINT2 end_screen;
    Vec end;
    Vec start;
    f32 len;
    u16 draw_flags;
    if ((s32)all_parents_unqueued_for_destruction() == 0) {
        return;
    }
    if (param->flags & 4) {
        if (flags & 0x10) {
            start.x = sprite.pos.x + sprite.offset.x;
            start.y = sprite.pos.y + sprite.offset.y;
            start.z = sprite.pos.z + sprite.offset.z;
        } else {
            VecCopy(&start, &sprite.pos);
        }
        end.x = start.x + step.x;
        end.y = start.y + step.y;
        end.z = start.z + step.z;
        len = vector_length(&step);
        if (0.0f == len) {
            return;
        }
        project_world_to_screen(NULL, &start, &start_screen.x);
        project_world_to_screen(NULL, &end, &end_screen.x);
        end_screen.x = end_screen.x - start_screen.x;
        end_screen.y = end_screen.y - start_screen.y;
        sprite.angle = (s16)(10430.38043493439 * atan2_float(end_screen.y, end_screen.x));
        sprite.scale_x = param->streak_width * len;
        sprite.scale_y = param->streak_height * len;
    } else {
        sprite.scale_x = size_x;
        sprite.scale_y = size_y;
    }
    sprite.scale_x = sprite.scale_x * scale_x;
    sprite.scale_y = sprite.scale_y * scale_y;
    draw_flags = flags;
    if (draw_flags & 0x200) {
        if (((is_split_screen() == 0) || !(flags & 0x400)) && (texlist != NULL) && (model != NULL)) {
            ParticleAngles angles = radial_particle_zero_angles;
            Vec at;
            direction_to_rotation_xz((u8 *)&step, &angles.x, &angles.z);
            if (param->flags & 4) {
                at.x = sprite.pos.x + sprite.offset.x;
                at.y = sprite.pos.y + sprite.offset.y;
                at.z = sprite.pos.z + sprite.offset.z;
            } else {
                VecCopy(&at, &sprite.pos);
            }
            push_matrix();
            post_translate_matrix(&at.x);
            scale_matrix(0, sprite.scale_x, sprite.scale_x, sprite.scale_x);
            if (param->flags & 4) {
                rotate_matrix_z(0, angles.z);
                rotate_matrix_x(0, angles.x);
                rotate_matrix_y(0, angles.y);
            }
            if ((flags & 0x1000) && (camera_ctrl_instance != NULL)) {
                rotate_matrix_y(0, camera_ctrl_instance->yaw);
            }
            TParticleCtrl::begin_effect_render();
            if (flags & 0x400) {
                load_projected_texture_matrix(1.33f);
            }
            rotate_matrix_y(0, sprite.angle);
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
            TParticleCtrl::end_effect_render();
            pop_matrix();
        }
    } else {
        if (draw_flags & 0x2000) {
            draw_particle_refraction_quad();
            return;
        }
        if (param->flags & 0x20) {
            (particle_sprites + 0x36)[sprite_index]->append_node_to_tail(&sprite);
            return;
        }
        particle_sprites[sprite_index]->append_node_to_tail(&sprite);
    }
}

TParticleRadial::~TParticleRadial() {}

#pragma push
#pragma fp_contract on

#pragma push
#pragma fp_contract on
TParticleRadial::TParticleRadial(ParticleParam *entry, Vec *position, TObject *parent, u16 particle_flags,
                             u16 target)
    : TParticle(entry, parent) {
    s32 life;
    sprite.pos.x = (entry->spawn_spread.x * ((3.0517578e-05f * (f32)rand()) - 0.5f)) + position->x;
    sprite.pos.y = (entry->spawn_spread.y * ((3.0517578e-05f * (f32)rand()) - 0.5f)) + position->y;
    sprite.pos.z = (entry->spawn_spread.z * ((3.0517578e-05f * (f32)rand()) - 0.5f)) + position->z;
    flags = particle_flags;
    if (flags & 0x80) {
        sprite.type = 1;
    }
    target_id = target;
    origin.x = position->x;
    origin.y = position->y;
    origin.z = position->z;
    size_x = (entry->size_range * (3.0517578e-05f * (f32)rand())) + entry->size_min;
    size_y = size_x;
    life = (s32)(((f32)entry->life_range * (3.0517578e-05f * (f32)rand())) + (f32)entry->life_min);
    if (entry->flags & 1) {
        age_rate = 1.0f / (f32)particle_sprites[sprite_index]->definition->uv_count;
    } else {
        age_rate = 1.0f / (f32)life;
    }
    speed = (entry->speed_range * (3.0517578e-05f * (f32)rand())) + entry->speed_min;
    step.x = 0.0f;
    step.y = 0.0f;
    step.z = 0.0f;
    if (flags & 0x2000) {
        request_indirect_effect(0x1F);
    }
}
#pragma pop

TParticleRadial::TParticleRadial(void *entry, void *position, void *parent)
    : TParticle((ParticleParam *)entry, (TObject *)parent) {
    ParticleParam *src = (ParticleParam *)entry;
    Vec *at = (Vec *)position;
    s32 life;
    sprite.pos.x = (src->spawn_spread.x * ((3.0517578e-05f * (f32)rand()) - 0.5f)) + at->x;
    sprite.pos.y = (src->spawn_spread.y * ((3.0517578e-05f * (f32)rand()) - 0.5f)) + at->y;
    sprite.pos.z = (src->spawn_spread.z * ((3.0517578e-05f * (f32)rand()) - 0.5f)) + at->z;
    origin.x = at->x;
    origin.y = at->y;
    origin.z = at->z;
    size_x = (src->size_range * (3.0517578e-05f * (f32)rand())) + src->size_min;
    size_y = size_x;
    life = (s32)(((f32)src->life_range * (3.0517578e-05f * (f32)rand())) + (f32)src->life_min);
    if (src->flags & 1) {
        age_rate = 1.0f / (f32)particle_sprites[sprite_index]->definition->uv_count;
    } else {
        age_rate = 1.0f / (f32)life;
    }
    speed = (src->speed_range * (3.0517578e-05f * (f32)rand())) + src->speed_min;
    step.x = 0.0f;
    step.y = 0.0f;
    step.z = 0.0f;
    if (flags & 0x2000) {
        request_indirect_effect(0x1F);
    }
}
#pragma pop

// Queues object's destruction and returns to main phase 18 with the audio streams stopped.
void destroy_keyboard_objects(TObject *fade) {
    fade->queue_destruction();
    set_queued_main_phase(2);
    request_main_phase(18);
    TLobby::stop_audio_streams();
    stop_cue_stream();
}
