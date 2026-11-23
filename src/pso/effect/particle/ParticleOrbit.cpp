#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/unk/TUnk_804C57F0.h"
#include "pso/effect/particle/ParticleOrbit.h"
#include "pso/render/render_util.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/vector.h"
#include "pso/unk/TUnk_8048E778.h"
#include "pso/unk/TUnk_8048E7A8.h"
#include "pso/unk/TUnk_8048E728.h"
#include "pso/unk/TUnk_8048E790.h"

#include "types.h"
#include <stdlib.h>
#include "pso/effect/particle/TParticleCtrl_80327D30.h"
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
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_80086B64.h"
#include "pso/math/MatrixVector.h"
#include "pso/render/model_render_state.h"


u8 *create_orbit_particle(u8 *param, u8 *pos, u8 *dir, s32 parent, u16 flags, s16 target_id) {
    return (u8 *)new TUnk_8048E790(param, pos, dir, parent, flags, target_id);
}

void *TParticleCtrl::alloc_child_particle(void *param, void *pos, void *dir, void *parent) {
    return new TUnk_8048E790(param, pos, dir, parent);
}

void TUnk_8048E790::retire_orbit_particle() {
    if (age >= 1.0f) {
        queue_destruction();
    }
}

#pragma push
#pragma fp_contract on
void TUnk_8048E790::run_task() {
    NJS_COLOR col;
    Vec follow_lift;
    Vec ring;
    Vec lift;
    ParticleParam *p;
    f32 t[2]; // [0] age this frame, [1] fade alpha
    f32 fade_in;
    f32 fade_out;
    f32 ch[3];
    f32 tilt;
    s32 frames;

    orbit_angle += (s32)(182.04445f * step.x);
    if (flags & 0x10) {
        TObjCollidable *target_obj = find_entity_by_id(target_id);
        if (target_obj == NULL) {
            queue_destruction();
            return;
        }
        Vec *center = (Vec *)target_obj->get_center();
        if (unk_98 != 0 && m_9c != 0 && unk_A0 != 0) {
            attach.x = orbit_center_x - origin.x;
            attach.z = orbit_center_z - origin.z;
            pos.x = orbit_radius * cos_table_lookup(orbit_angle) + center->x;
            pos.z = orbit_radius * sin_table_lookup(orbit_angle) + center->z;
        } else {
            attach.x = orbit_center_x - origin.x;
            attach.z = orbit_center_z - origin.z;
            pos.x = orbit_radius * cos_table_lookup(orbit_angle) + center->x;
            pos.z = orbit_radius * sin_table_lookup(orbit_angle) + center->z;
            pos.y = center->y;
            orbit_height += step.y;
            follow_lift.x = 0.0f;
            follow_lift.z = 0.0f;
            follow_lift.y = orbit_height;
            push_matrix_from(&identity_matrix);
            rotate_matrix_x(0, unk_98);
            rotate_matrix_y(0, m_9c);
            rotate_matrix_z(0, unk_A0);
            rotate_vector_by_current_matrix(&follow_lift, &follow_lift);
            pop_matrix();
            pos.x += follow_lift.x;
            pos.y += follow_lift.y;
            pos.z += follow_lift.z;
        }
    } else if (unk_98 != 0 && m_9c != 0 && unk_A0 != 0) {
        pos.x = orbit_radius * cos_table_lookup(orbit_angle) + orbit_center_x;
        pos.z = orbit_radius * sin_table_lookup(orbit_angle) + orbit_center_z;
    } else {
        ring.x = orbit_radius * cos_table_lookup(orbit_angle);
        ring.z = orbit_radius * sin_table_lookup(orbit_angle);
        ring.y = 0.0f;
        orbit_height += step.y;
        lift.x = 0.0f;
        lift.z = 0.0f;
        lift.y = orbit_height;
        push_matrix_from(&identity_matrix);
        rotate_matrix_x(0, unk_98);
        rotate_matrix_y(0, m_9c);
        rotate_matrix_z(0, unk_A0);
        rotate_vector_by_current_matrix(&ring, &ring);
        rotate_vector_by_current_matrix(&lift, &lift);
        pop_matrix();
        pos.x = lift.x + (orbit_center_x + ring.x);
        pos.z = lift.z + (orbit_center_z + ring.z);
        pos.y = lift.y + (origin.y + ring.y);
    }
    if (unk_98 != 0 && m_9c != 0 && unk_A0 != 0) {
        pos.y += step.y;
    }
    m_28 *= param->scale_decay;
    unk_2C *= param->scale_decay;
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
            ch[0] = fade_particle_channel(p->orbit_red_rate * t[0] + color_base[0], t[1]);
            ch[1] = fade_particle_channel(p->orbit_green_rate * t[0] + color_base[1], t[1]);
            ch[2] = fade_particle_channel(p->orbit_blue_rate * t[0] + color_base[2], t[1]);
        } else {
            ch[0] = fade_particle_channel(p->orbit_red_rate * t[0] + p->color_base[0], t[1]);
            ch[1] = fade_particle_channel(p->orbit_green_rate * t[0] + p->color_base[1], t[1]);
            ch[2] = fade_particle_channel(p->orbit_blue_rate * t[0] + p->color_base[2], t[1]);
        }
        t[1] = 1.0f;
    } else {
        if (flags & 0x100) {
            ch[0] = clamp_particle_channel(p->orbit_red_rate * t[0] + color_base[0]);
            ch[1] = clamp_particle_channel(p->orbit_green_rate * t[0] + color_base[1]);
            ch[2] = clamp_particle_channel(p->orbit_blue_rate * t[0] + color_base[2]);
        } else {
            ch[0] = clamp_particle_channel(p->orbit_red_rate * t[0] + p->color_base[0]);
            ch[1] = clamp_particle_channel(p->orbit_green_rate * t[0] + p->color_base[1]);
            ch[2] = clamp_particle_channel(p->orbit_blue_rate * t[0] + p->color_base[2]);
        }
    }
    col.argb.a = 254.0f * t[1];
    col.argb.r = 254.0f * ch[0];
    col.argb.g = 254.0f * ch[1];
    col.argb.b = 254.0f * ch[2];
    color = col.color;
    pulse_angle += (s32)(182.04445f * param->orbit.spin_rate);
    age += age_rate;
    tilt = 8.0f * step.x * step.y;
    if (fabs_float(tilt) > 10.0f) {
        tilt = 10.0f;
    }
    if (speed < 0.0f) {
        m_96 += (s32)(182.04445f * tilt);
    } else {
        m_96 -= (s32)(182.04445f * tilt);
    }
    frames = particle_sprites[sprite_index]->definition->uv_count;
    if (param->flags & 0x10) {
        frame = age * (frames - 1);
    } else {
        frame++;
        if (frames <= frame) {
            frame = 0;
        }
    }
    m_28 *= m_a4;
    unk_2C *= unk_A8;
    if (motion != NULL) {
        motion_frame += motion_speed;
        if ((motion->nbFrame - 1) <= motion_frame) {
            motion_frame = motion->nbFrame - 1;
        }
    }
    retire_orbit_particle();
}
#pragma pop

void TUnk_8048E790::render() {
    Vec at;
    f32 pulse;
    f32 size;
    s32 render_flags;
    u16 draw_flags;
    if ((s32)all_parents_unqueued_for_destruction() != 0) {
        pulse = param->orbit.pulse * cos_table_lookup(pulse_angle);
        m_88 = m_28 * (1.0f + pulse);
        unk_8C = unk_2C * (1.0f - pulse);
        m_88 = m_88 * m_a4;
        unk_8C = unk_8C * unk_A8;
        draw_flags = flags;
        if (draw_flags & 0x200) {
            if (((is_split_screen() == 0) || !(flags & 0x400)) && (unk_B4 != 0) && (model != NULL)) {
                at.x = pos.x + attach.x;
                at.y = pos.y + attach.y;
                at.z = pos.z + attach.z;
                push_matrix();
                post_translate_matrix(&at.x);
                size = m_88;
                scale_matrix(0, size, size, size);
                rotate_matrix_z(0, unk_A0);
                rotate_matrix_x(0, unk_98);
                rotate_matrix_y(0, m_9c);
                saved_model_render_flags = model_render_flags;
                if (flags & 0x400) {
                    TParticleCtrl::begin_effect_render();
                    load_projected_texture_matrix(1.33f);
                }
                rotate_matrix_y(0, m_96);
                if ((flags & 0x1000) && (camera_ctrl_instance != NULL)) {
                    rotate_matrix_y(0, camera_ctrl_instance->yaw);
                }
                TParticleCtrl::end_effect_render();
                if (flags & 0x400) {
                    setup_particle_tev(0);
                } else {
                    render_flags = model_render_flags;
                    saved_model_render_flags = render_flags;
                    model_render_flags = render_flags | 0x8021;
                    if (is_particle_sprite_additive(render_flags) != 0) {
                        apply_particle_model_fade_color(1);
                    } else {
                        apply_particle_model_fade_color(0);
                    }
                }
                TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(unk_B4));
                set_draw_list_mask(3);
                if (motion != NULL) {
                    draw_ginja_model_with_motion(model, motion, motion_frame);
                } else {
                    draw_ginja_object(model);
                }
                if (flags & 0x400) {
                    reset_particle_tev();
                }
                model_render_flags = saved_model_render_flags;
                TParticleCtrl::end_effect_render();
                pop_matrix();
            }
        } else {
            if (draw_flags & 0x2000) {
                draw_particle_refraction_quad();
                return;
            }
            if (param->flags & 0x20) {
                TParticleCtrl::append_node_to_tail((particle_sprites + 0x36)[sprite_index], &unk_6C);
                return;
            }
            TParticleCtrl::append_node_to_tail(particle_sprites[sprite_index], &unk_6C);
        }
    }
}

TUnk_8048E790::~TUnk_8048E790() {}

#pragma push
#pragma fp_contract on
TUnk_8048E790::TUnk_8048E790(u8 *entry, u8 *position, u8 *direction, saddr parent, u16 particle_flags, s16 target)
    : TUnk_8048E728((ParticleParam *)entry, (TObject *)parent) {
    ParticleParam *src = (ParticleParam *)entry;
    Vec *at = (Vec *)position;
    ParticleAngles *dir = (ParticleAngles *)direction;
    s32 life;
    unk_98 = dir->x;
    m_9c = dir->y;
    unk_A0 = dir->z;
    orbit_center_x = (2.0f * src->spawn_spread.x) * ((3.0517578e-05f * (f32)rand()) - 0.5f) + at->x;
    orbit_center_z = (2.0f * src->spawn_spread.z) * ((3.0517578e-05f * (f32)rand()) - 0.5f) + at->z;
    pos.y = (2.0f * src->spawn_spread.y) * ((3.0517578e-05f * (f32)rand()) - 0.5f) + at->y;
    origin.x = at->x;
    origin.z = at->z;
    origin.y = pos.y;
    flags = particle_flags;
    if (flags & 0x80) {
        unk_95 = 1;
    }
    target_id = target;
    m_28 = src->size_range * (3.0517578e-05f * (f32)rand()) + src->size_min;
    unk_2C = m_28;
    life = (s32)((f32)src->life_range * (3.0517578e-05f * (f32)rand()) + (f32)src->life_min);
    if (src->flags & 1) {
        age_rate = 1.0f / (f32)particle_sprites[sprite_index]->definition->uv_count;
    } else {
        age_rate = 1.0f / (f32)life;
    }
    step.x = src->orbit.angular_speed_range * (3.0517578e-05f * (f32)rand()) + src->speed_min;
    step.y = src->orbit_rise_range * (3.0517578e-05f * (f32)rand()) + src->rise_min;
    orbit_angle = (s32)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand())));
    orbit_radius = src->orbit_radius_range * (3.0517578e-05f * (f32)rand()) + src->orbit_radius_min;
    pulse_angle = (s32)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand())));
    m_96 = orbit_angle;
    speed = (3.0517578e-05f * (f32)rand()) - 0.5f;
    orbit_height = 0.0f;
    if (flags & 0x2000) {
        request_indirect_effect(0x1F);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
TUnk_8048E790::TUnk_8048E790(void *entry, void *position, void *direction, void *parent)
    : TUnk_8048E728((ParticleParam *)entry, (TObject *)parent) {
    ParticleParam *src = (ParticleParam *)entry;
    Vec *at = (Vec *)position;
    ParticleAngles *dir = (ParticleAngles *)direction;
    s32 life;
    unk_98 = dir->x;
    m_9c = dir->y;
    unk_A0 = dir->z;
    orbit_center_x = (2.0f * src->spawn_spread.x) * ((3.0517578e-05f * (f32)rand()) - 0.5f) + at->x;
    orbit_center_z = (2.0f * src->spawn_spread.z) * ((3.0517578e-05f * (f32)rand()) - 0.5f) + at->z;
    pos.y = (2.0f * src->spawn_spread.y) * ((3.0517578e-05f * (f32)rand()) - 0.5f) + at->y;
    origin.x = at->x;
    origin.z = at->z;
    origin.y = pos.y;
    m_28 = src->size_range * (3.0517578e-05f * (f32)rand()) + src->size_min;
    unk_2C = m_28;
    life = (s32)((f32)src->life_range * (3.0517578e-05f * (f32)rand()) + (f32)src->life_min);
    if (src->flags & 1) {
        age_rate = 1.0f / (f32)particle_sprites[sprite_index]->definition->uv_count;
    } else {
        age_rate = 1.0f / (f32)life;
    }
    step.x = src->orbit.angular_speed_range * (3.0517578e-05f * (f32)rand()) + src->speed_min;
    step.y = src->orbit_rise_range * (3.0517578e-05f * (f32)rand()) + src->rise_min;
    orbit_angle = (s32)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand())));
    orbit_radius = src->orbit_radius_range * (3.0517578e-05f * (f32)rand()) + src->orbit_radius_min;
    pulse_angle = (s32)(182.04445f * (360.0f * (3.0517578e-05f * (f32)rand())));
    m_96 = orbit_angle;
    speed = (3.0517578e-05f * (f32)rand()) - 0.5f;
    orbit_height = 0.0f;
    if (flags & 0x2000) {
        request_indirect_effect(0x1F);
    }
}
#pragma pop
