#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlAccessors.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/particle/ParticleParam.h"
#include "pso/effect/particle/ParticleRadial.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticle.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/ParticleBallistic.h"
#include "pso/effect/particle/ParticleOrbit.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/system/TLoadCtrl.h"

ParticleParam *particle_global_entry_table;
ParticleParam *particle_area_entry_table;
BmlResource *TParticleCtrl::regular_bml_resource;
NJS_TEXLIST *TParticleCtrl::texture_list;

NJS_OBJECT *TParticleCtrl::get_particle_model(s32 model) {
    if (model < 3) {
        return get_bml_model(regular_bml_resource, model);
    }
    return 0;
}

NJS_TEXLIST *TParticleCtrl::get_instance() { return texture_list; }

TParticleCtrl *create_timed_particle_emitter_with_flags(void *pos, s32 id, s32 delay, s32 duration, u16 flags) {
    if (particle_pool_limit > id) {
        return new TParticleCtrl(static_cast<const Vec *>(pos), &particle_global_entry_table[id], 0, delay, duration, 0, flags);
    }
    if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(pos), &particle_area_entry_table[idx], 0, delay, duration, 0, flags);
    }
    return 0;
}

TParticleCtrl *create_timed_particle_emitter(const void *pos, s32 id, s32 delay, s32 duration) {
    if (particle_pool_limit > id) {
        return new TParticleCtrl(static_cast<const Vec *>(pos), &particle_global_entry_table[id], 0, delay, duration, 0);
    }
    if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(pos), &particle_area_entry_table[idx], 0, delay, duration, 0);
    }
    return 0;
}

TParticleCtrl *create_timed_particle_emitter_with_angles(void *pos, void *dir, s32 id, s32 delay, s32 duration, u16 flags) {
    if (particle_pool_limit > id) {
        return new TParticleCtrl(static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir), &particle_global_entry_table[id], 0, delay, duration, 0, flags);
    }
    if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir), &particle_area_entry_table[idx], 0, delay, duration, 0, flags);
    }
    return 0;
}

TParticleCtrl *create_particle_controller_with_rotation(Vec *pos, ParticleAngles *dir, s32 id, s32 a, s32 b) {
    if (particle_pool_limit > id) {
        return new TParticleCtrl(pos, dir, &particle_global_entry_table[id], 0, a, b, 0);
    }
    if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        return new TParticleCtrl(pos, dir, &particle_area_entry_table[idx], 0, a, b, 0);
    }
    return 0;
}

void TParticleCtrl::release(void *emitter) {
    if (emitter != NULL) {
        ((TParticleCtrl *)emitter)->queue_destruction();
    }
}
TParticleCtrl *create_oneshot_particle_emitter(void *pos, void *dir, s32 id, u16 flags) {
    if (particle_pool_limit > id) {
        return new TParticleCtrl(static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir), &particle_global_entry_table[id], 1, 0, 0, 0, flags);
    }
    if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir), &particle_area_entry_table[idx], 1, 0, 0, 0, flags);
    }
    return 0;
}

TParticleCtrl *spawn_directional_particle(void *pos, void *dir, s32 id) {
    if (particle_pool_limit > id) {
        return new TParticleCtrl(static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir), &particle_global_entry_table[id], 1, 0, 0, 0);
    }
    if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir), &particle_area_entry_table[idx], 1, 0, 0, 0);
    }
    return 0;
}

TParticleCtrl *create_particle_controller(void *pos, s32 id, s32 use_self) {
    if (particle_pool_limit > id) {
        return new TParticleCtrl(static_cast<const Vec *>(pos), &particle_global_entry_table[id], 0, 0, 0, use_self);
    }
    if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(pos), &particle_area_entry_table[idx], 0, 0, 0, use_self);
    }
    return NULL;
}

TParticleCtrl *create_particle_controller_with_angles(void *pos, void *dir, s32 id, s32 use_self, u16 flags) {
    if (particle_pool_limit > id) {
        return new TParticleCtrl(static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir), &particle_global_entry_table[id], 0, 0, 0, use_self, flags);
    }
    if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir), &particle_area_entry_table[idx], 0, 0, 0, use_self, flags);
    }
    return NULL;
}

TParticleCtrl *create_particle_controller_with_angles(void *pos, void *dir, s32 id, s32 use_self) {
    if (particle_pool_limit > id) {
        return new TParticleCtrl(static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir), &particle_global_entry_table[id], 0, 0, 0, use_self);
    }
    if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir), &particle_area_entry_table[idx], 0, 0, 0, use_self);
    }
    return NULL;
}

TParticleCtrl *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, u16 flags) {
    if (particle_pool_limit > id) {
        return new TParticleCtrl(static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir), &particle_global_entry_table[id], 0, 0, 0, 0, flags);
    }
    if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir), &particle_area_entry_table[idx], 0, 0, 0, 0, flags);
    }
    return 0;
}

TParticleCtrl *spawn_continuous_particle_with_direction(void *pos, void *dir, s32 id) {
    if (particle_pool_limit > id) {
        return new TParticleCtrl(static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir), &particle_global_entry_table[id], 0x0, 0, 0, 0);
    }
    if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(pos), static_cast<ParticleAngles *>(dir), &particle_area_entry_table[idx], 0x0, 0, 0, 0);
    }
    return 0;
}

TParticleCtrl *spawn_particle_effect_with_flags(const Vec *pos, s32 id, u16 flags) {
    if (particle_pool_limit > id) {
        return new TParticleCtrl(pos, &particle_global_entry_table[id], 1, 0, 0, 0, flags);
    }
    if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        return new TParticleCtrl(pos, &particle_area_entry_table[idx], 1, 0, 0, 0, flags);
    }
    return 0;
}

TParticleCtrl *spawn_particle_effect(const Vec *pos, s32 id) {
    if (particle_pool_limit > id) {
        return new TParticleCtrl(pos, &particle_global_entry_table[id], 1, 0, 0, 0);
    }
    if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        return new TParticleCtrl(pos, &particle_area_entry_table[idx], 1, 0, 0, 0);
    }
    return 0;
}

TParticleCtrl *spawn_continuous_particle_effect_with_flags(void *pos, s32 id, u16 flags) {
    if (particle_pool_limit > id) {
        return new TParticleCtrl(static_cast<const Vec *>(pos), &particle_global_entry_table[id], 0, 0, 0, 0, flags);
    } else if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(pos), &particle_area_entry_table[idx], 0, 0, 0, 0, flags);
    } else {
        return 0;
    }
}

TParticleCtrl *create_particle_emitter(const void *pos, s32 id) {
    if (particle_pool_limit > id) {
        return new TParticleCtrl(static_cast<const Vec *>(pos), &particle_global_entry_table[id], 0, 0, 0, 0);
    }
    if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        return new TParticleCtrl(static_cast<const Vec *>(pos), &particle_area_entry_table[idx], 0, 0, 0, 0);
    }
    return 0;
}

void TParticleCtrl::set_param_ptr(s32 index) {
    emit_count = 0.0f;
    emit_phase = 0;
    emit_rate = 1.0f;
    if (index >= 0x200) {
        emitter_entry = &particle_area_entry_table[index - 0x200];
        return;
    }
    emitter_entry = &particle_global_entry_table[index];
}

void TParticleCtrl::set_direction(void *dir) {
    const ParticleAngles *angles = static_cast<const ParticleAngles *>(dir);
    direction.x = angles->x;
    direction.y = angles->y;
    direction.z = angles->z;
}

void TParticleCtrl::set_flags(u16 flags) { emit_flags |= flags; }

void TParticleCtrl::set_owner_id(u16 id) {
    if (id != 0xFFFF) {
        owner_id = id;
    }
}

void TParticleCtrl::set_tint_color(s32 color) {
    emit_flags |= 0x100;
    tint.color = color;
}

void TParticleCtrl::set_position(void *pos) {
    const Vec *p = static_cast<const Vec *>(pos);
    position.x = p->x;
    position.y = p->y;
    position.z = p->z;
}

#pragma readonly_strings on

const char *TParticleCtrl::class_name = "TParticleCtrl";

#pragma push
#pragma fp_contract on
void TParticleCtrl::run_task() {
    s32 kind;
    TParticle *p;
    f32 step;
    if (all_parents_unqueued_for_destruction() == 0) {
        return;
    }
    if (delay-- <= 0) {
        delay = 0;
    } else {
        return;
    }
    age++;
    if (emit_flags & 1) {
        emit_flags &= ~1;
        return;
    }
    if (((emit_flags & 0x200) || (emit_flags & 0x2000)) && particle_parent == tl_07) {
        particle_parent = tl_particlemodel;
    }
    if (emitter_entry == NULL) {
        return;
    }
    if (0.0f == emitter_entry->emission_frequency) {
        emit_count += emitter_entry->emission_rate * emit_rate;
    } else {
        emit_phase += (s32)(182.04445f * emitter_entry->emission_frequency);
        emit_count += emit_rate * (emitter_entry->emission_rate * fabs_float(sin_table_lookup(emit_phase)));
    }
    if (camera_ctrl_instance != NULL && !(emit_flags & 0x40)) {
        if (is_split_screen() != 0) {
            if (TLoadCtrl::is_loading() == 0) {
                f32 lim = 10000.0f;
                s32 near = 0;
                s32 i;
                for (i = 0; i < 4; i++) {
                    TObjPlayer *pl = get_player_by_client_id(i);
                    if (pl != NULL && horizontal_distance_squared(&position, &pl->position) < lim) {
                        near = 1;
                    }
                }
                if (near == 0) {
                    emit_count = 0.0f;
                }
            }
        } else if (TLoadCtrl::is_loading() == 0) {
            if (!(horizontal_distance_squared(&position, &camera_ctrl_instance->pos) < 40000.0f)) {
                emit_count = 0.0f;
            }
        }
    }
    step = 1.0f;
    while (emit_count >= step) {
        emit_count -= step;
        kind = emitter_entry->generator_kind;
        if (kind == 0) {
            TParticle *q = create_ballistic_particle(
                emitter_entry, &position, &direction, particle_parent, emit_flags, owner_id);
            if (q != NULL) {
                q->set_draw_scale(scale_x, scale_y);
                if (emit_flags & 0x100) {
                    NJS_COLOR c = tint;
                    NJS_ARGB argb;
                    argb.a = c.argb.a / 255.0f;
                    argb.r = c.argb.r / 255.0f;
                    argb.g = c.argb.g / 255.0f;
                    argb.b = c.argb.b / 255.0f;
                    q->set_tint_color(&argb);
                }
                if (emit_flags & 0x200) {
                    if (emit_flags & 0x400) {
                        q->attach_model(model, texlist, motion, 1, motion_frame);
                    } else {
                        q->attach_model(model, texlist, motion, 0, motion_frame);
                    }
                }
            }
        } else if (emit_flags & 0x10) {
            if (kind == 1) {
                p = create_orbit_particle(
                    emitter_entry, &position, &direction, particle_parent, 0x10, owner_id);
                if (p != NULL) {
                    p->set_draw_scale(scale_x, scale_y);
                    if (emit_flags & 0x100) {
                        NJS_COLOR c = tint;
                        NJS_ARGB argb;
                        argb.a = c.argb.a / 255.0f;
                        argb.r = c.argb.r / 255.0f;
                        argb.g = c.argb.g / 255.0f;
                        argb.b = c.argb.b / 255.0f;
                        p->set_tint_color(&argb);
                    }
                    if (emit_flags & 0x200) {
                        if (emit_flags & 0x400) {
                            p->attach_model(model, texlist, motion, 1, motion_frame);
                        } else {
                            p->attach_model(model, texlist, motion, 0, motion_frame);
                        }
                    }
                }
            } else if (kind == 2) {
                p = create_radial_particle(
                    emitter_entry, &position, particle_parent, 0x10, owner_id);
                if (p != NULL) {
                    p->set_draw_scale(scale_x, scale_y);
                    if (emit_flags & 0x100) {
                        NJS_COLOR c = tint;
                        NJS_ARGB argb;
                        argb.a = c.argb.a / 255.0f;
                        argb.r = c.argb.r / 255.0f;
                        argb.g = c.argb.b / 255.0f;
                        argb.b = c.argb.b / 255.0f;
                        p->set_tint_color(&argb);
                    }
                    if (emit_flags & 0x200) {
                        if (emit_flags & 0x400) {
                            p->attach_model(model, texlist, motion, 1, motion_frame);
                        } else {
                            p->attach_model(model, texlist, motion, 0, motion_frame);
                        }
                    }
                }
            }
        } else if (emit_flags & 0x80) {
            if (kind == 1) {
                p = create_orbit_particle(
                    emitter_entry, &position, &direction, particle_parent, 0x80, 0xFFFF);
                if (p != NULL) {
                    p->set_draw_scale(scale_x, scale_y);
                    if (emit_flags & 0x100) {
                        NJS_COLOR c = tint;
                        NJS_ARGB argb;
                        argb.a = c.argb.a / 255.0f;
                        argb.r = c.argb.r / 255.0f;
                        argb.g = c.argb.g / 255.0f;
                        argb.b = c.argb.b / 255.0f;
                        p->set_tint_color(&argb);
                    }
                    if (emit_flags & 0x200) {
                        if (emit_flags & 0x400) {
                            p->attach_model(model, texlist, motion, 1, motion_frame);
                        } else {
                            p->attach_model(model, texlist, motion, 0, motion_frame);
                        }
                    }
                }
            } else if (kind == 2) {
                p = create_radial_particle(
                    emitter_entry, &position, particle_parent, 0x80, 0xFFFF);
                if (p != NULL) {
                    p->set_draw_scale(scale_x, scale_y);
                    if (emit_flags & 0x100) {
                        NJS_COLOR c = tint;
                        NJS_ARGB argb;
                        argb.a = c.argb.a / 255.0f;
                        argb.r = c.argb.r / 255.0f;
                        argb.g = c.argb.g / 255.0f;
                        argb.b = c.argb.b / 255.0f;
                        p->set_tint_color(&argb);
                    }
                    if (emit_flags & 0x200) {
                        if (emit_flags & 0x400) {
                            p->attach_model(model, texlist, motion, 1, motion_frame);
                        } else {
                            p->attach_model(model, texlist, motion, 0, motion_frame);
                        }
                    }
                }
            }
        } else if (kind < 3) {
            p = particle_ctrl_generator_table[kind].create(emitter_entry, &position, particle_parent);
            if (p != NULL) {
                p->set_draw_scale(scale_x, scale_y);
                p->set_rotation(&direction);
                if (emit_flags & 0x100) {
                    NJS_COLOR c = tint;
                    NJS_ARGB argb;
                    argb.a = c.argb.a / 255.0f;
                    argb.r = c.argb.r / 255.0f;
                    argb.g = c.argb.g / 255.0f;
                    argb.b = c.argb.b / 255.0f;
                    p->set_tint_color(&argb);
                }
                if (emit_flags & 0x200) {
                    if (emit_flags & 0x400) {
                        p->attach_model(model, texlist, motion, 1, motion_frame);
                    } else {
                        p->attach_model(model, texlist, motion, 0, motion_frame);
                    }
                }
                if (emit_flags & 0x2000) {
                    p->mark_active();
                }
            }
        }
    }
    if (oneshot == 1) {
        queue_destruction();
    }
    if (lifetime != 0 && age >= lifetime) {
        queue_destruction();
    }
}
#pragma pop

void TParticleCtrl::clear_active_flag() { emit_flags &= ~1; }

void TParticleCtrl::enable() { emit_flags |= 1; }

TParticleCtrl::~TParticleCtrl() {}

TParticleCtrl::TParticleCtrl(const Vec *pos, ParticleAngles *dir, ParticleParam *entry, s32 oneshot, s32 delay,
                             s32 lifetime, s32 use_self, u16 flags)
    : TObject(tl_07) {
    m_name = class_name;
    model = 0;
    texlist = 0;
    motion = 0;
    tint.color = 0;
    scale_x = 1.0f;
    scale_y = 1.0f;
    emit_count = 0.0f;
    emit_phase = 0;
    emit_rate = 1.0f;
    emitter_entry = entry;
    VecCopy(&position, pos);
    emit_flags = flags;
    owner_id = 0xFFFF;
    direction.x = dir->x;
    direction.z = dir->z;
    direction.y = dir->y;
    this->oneshot = oneshot;
    this->delay = delay;
    this->lifetime = lifetime;
    age = 0;
    if (use_self != 0) {
        particle_parent = this;
    } else if (emit_flags & 0x800) {
        if (emit_flags & 0x4000) {
            particle_parent = tl_clipout;
        } else {
            particle_parent = tl_07;
        }
    } else {
        particle_parent = tl_07;
    }
}

TParticleCtrl::TParticleCtrl(const Vec *pos, ParticleAngles *dir, ParticleParam *entry, s32 oneshot, s32 delay,
                             s32 lifetime, s32 use_self)
    : TObject(tl_07) {
    m_name = class_name;
    model = 0;
    texlist = 0;
    motion = 0;
    tint.color = 0;
    scale_x = 1.0f;
    scale_y = 1.0f;
    emit_count = 0.0f;
    emit_phase = 0;
    emit_rate = 1.0f;
    emitter_entry = entry;
    VecCopy(&position, pos);
    emit_flags = 0;
    owner_id = 0xFFFF;
    direction.x = dir->x;
    direction.z = dir->z;
    direction.y = dir->y;
    this->oneshot = oneshot;
    this->delay = delay;
    this->lifetime = lifetime;
    age = 0;
    if (use_self != 0) {
        particle_parent = this;
    } else if (emit_flags & 0x800) {
        if (emit_flags & 0x4000) {
            particle_parent = tl_clipout;
        } else {
            particle_parent = tl_07;
        }
    } else {
        particle_parent = tl_07;
    }
}

TParticleCtrl::TParticleCtrl(const Vec *pos, ParticleParam *entry, s32 oneshot, s32 delay, s32 lifetime,
                             s32 use_self, u16 flags)
    : TObject(tl_07) {
    m_name = class_name;
    model = 0;
    texlist = 0;
    motion = 0;
    tint.color = 0;
    scale_x = 1.0f;
    scale_y = 1.0f;
    emit_count = 0.0f;
    emit_phase = 0;
    emit_rate = 1.0f;
    emitter_entry = entry;
    VecCopy(&position, pos);
    emit_flags = flags;
    owner_id = 0xFFFF;
    direction.x = 0;
    direction.y = 0;
    direction.z = 0;
    this->oneshot = oneshot;
    this->delay = delay;
    this->lifetime = lifetime;
    age = 0;
    if (use_self != 0) {
        particle_parent = this;
    } else if (emit_flags & 0x800) {
        if (emit_flags & 0x4000) {
            particle_parent = tl_clipout;
        } else {
            particle_parent = tl_07;
        }
    } else {
        particle_parent = tl_07;
    }
}

TParticleCtrl::TParticleCtrl(const Vec *pos, ParticleParam *entry, s32 oneshot, s32 delay, s32 lifetime,
                             s32 use_self)
    : TObject(tl_07) {
    m_name = class_name;
    model = 0;
    texlist = 0;
    motion = 0;
    tint.color = 0;
    scale_x = 1.0f;
    scale_y = 1.0f;
    emit_count = 0.0f;
    emit_phase = 0;
    emit_rate = 1.0f;
    emitter_entry = entry;
    VecCopy(&position, pos);
    emit_flags = 0;
    owner_id = 0xFFFF;
    direction.x = 0;
    direction.y = 0;
    direction.z = 0;
    this->oneshot = oneshot;
    this->delay = delay;
    this->lifetime = lifetime;
    age = 0;
    if (use_self != 0) {
        particle_parent = this;
    } else if (emit_flags & 0x800) {
        if (emit_flags & 0x4000) {
            particle_parent = tl_clipout;
        } else {
            particle_parent = tl_07;
        }
    } else {
        particle_parent = tl_07;
    }
}

void TParticle::set_rotation(ParticleAngles *rotation) { copy_xyz(&rot_x, rotation); }

void TParticle::attach_model(void *model, NJS_TEXLIST *texlist, NJS_MOTION *motion, s32 loop, f32 speed) {
    this->model = model;
    this->texlist = texlist;
    this->motion = motion;
    motion_speed = speed;
    if (loop != 0) {
        flags |= 0x400;
    }
    flags |= 0x200;
}

void TParticle::set_tint_color(NJS_ARGB *rgba) {
    flags |= 0x100;
    copy_argb(&tint, rgba);
}

void TParticle::set_draw_scale(f32 x, f32 y) {
    scale_x = x;
    scale_y = y;
}
