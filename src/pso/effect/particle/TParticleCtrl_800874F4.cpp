#include "pso/system/ResourceFile.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"
#include "pso/effect/particle/ParticleRadial.h"
#include "types.h"
#include <stdio.h>
#include <string.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TUnk_8048E728.h"
#include "pso/unk/TUnk_8048E778.h"
#include "pso/unk/TUnk_8048E790.h"
#include "pso/unk/TUnk_8048E7A8.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/ParticleBallistic.h"
#include "pso/effect/particle/ParticleOrbit.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/system/TLoadCtrl.h"

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

const char *TParticleCtrl__class_name_descriptor[2] = {"TParticleCtrl", 0};

#pragma push
#pragma fp_contract on
void TParticleCtrl::run_task() {
    s32 kind;
    u8 *p;
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
            if (TLoadCtrl__sub_8001C60C() == 0) {
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
        } else if (TLoadCtrl__sub_8001C60C() == 0) {
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
            u8 *q = ((u8 *(*)(void *, void *, void *, TObject *, u16, u16))create_ballistic_particle)(
                emitter_entry, &position, &direction, particle_parent, emit_flags, owner_id);
            if (q != NULL) {
                set_particle_draw_scale(q, scale_x, scale_y);
                if (emit_flags & 0x100) {
                    NJS_COLOR c = tint;
                    NJS_ARGB argb;
                    argb.a = c.argb.a / 255.0f;
                    argb.r = c.argb.r / 255.0f;
                    argb.g = c.argb.g / 255.0f;
                    argb.b = c.argb.b / 255.0f;
                    set_particle_tint_color(q, &argb);
                }
                if (emit_flags & 0x200) {
                    if (emit_flags & 0x400) {
                        ((TParticleCtrl *)q)->attach_model(model, texlist, motion, 1, motion_frame);
                    } else {
                        ((TParticleCtrl *)q)->attach_model(model, texlist, motion, 0, motion_frame);
                    }
                }
            }
        } else if (emit_flags & 0x10) {
            if (kind == 1) {
                p = ((u8 *(*)(void *, void *, void *, TObject *, u16, u16))create_orbit_particle)(
                    emitter_entry, &position, &direction, particle_parent, 0x10, owner_id);
                if (p != NULL) {
                    set_particle_draw_scale(p, scale_x, scale_y);
                    if (emit_flags & 0x100) {
                        NJS_COLOR c = tint;
                        NJS_ARGB argb;
                        argb.a = c.argb.a / 255.0f;
                        argb.r = c.argb.r / 255.0f;
                        argb.g = c.argb.g / 255.0f;
                        argb.b = c.argb.b / 255.0f;
                        set_particle_tint_color(p, &argb);
                    }
                    if (emit_flags & 0x200) {
                        if (emit_flags & 0x400) {
                            ((TParticleCtrl *)p)->attach_model(model, texlist, motion, 1, motion_frame);
                        } else {
                            ((TParticleCtrl *)p)->attach_model(model, texlist, motion, 0, motion_frame);
                        }
                    }
                }
            } else if (kind == 2) {
                p = ((u8 *(*)(void *, void *, TObject *, u16, u16))create_radial_particle)(
                    emitter_entry, &position, particle_parent, 0x10, owner_id);
                if (p != NULL) {
                    set_particle_draw_scale(p, scale_x, scale_y);
                    if (emit_flags & 0x100) {
                        NJS_COLOR c = tint;
                        NJS_ARGB argb;
                        argb.a = c.argb.a / 255.0f;
                        argb.r = c.argb.r / 255.0f;
                        argb.g = c.argb.b / 255.0f;
                        argb.b = c.argb.b / 255.0f;
                        set_particle_tint_color(p, &argb);
                    }
                    if (emit_flags & 0x200) {
                        if (emit_flags & 0x400) {
                            ((TParticleCtrl *)p)->attach_model(model, texlist, motion, 1, motion_frame);
                        } else {
                            ((TParticleCtrl *)p)->attach_model(model, texlist, motion, 0, motion_frame);
                        }
                    }
                }
            }
        } else if (emit_flags & 0x80) {
            if (kind == 1) {
                p = ((u8 *(*)(void *, void *, void *, TObject *, u16, u16))create_orbit_particle)(
                    emitter_entry, &position, &direction, particle_parent, 0x80, 0xFFFF);
                if (p != NULL) {
                    set_particle_draw_scale(p, scale_x, scale_y);
                    if (emit_flags & 0x100) {
                        NJS_COLOR c = tint;
                        NJS_ARGB argb;
                        argb.a = c.argb.a / 255.0f;
                        argb.r = c.argb.r / 255.0f;
                        argb.g = c.argb.g / 255.0f;
                        argb.b = c.argb.b / 255.0f;
                        set_particle_tint_color(p, &argb);
                    }
                    if (emit_flags & 0x200) {
                        if (emit_flags & 0x400) {
                            ((TParticleCtrl *)p)->attach_model(model, texlist, motion, 1, motion_frame);
                        } else {
                            ((TParticleCtrl *)p)->attach_model(model, texlist, motion, 0, motion_frame);
                        }
                    }
                }
            } else if (kind == 2) {
                p = ((u8 *(*)(void *, void *, TObject *, u16, u16))create_radial_particle)(
                    emitter_entry, &position, particle_parent, 0x80, 0xFFFF);
                if (p != NULL) {
                    set_particle_draw_scale(p, scale_x, scale_y);
                    if (emit_flags & 0x100) {
                        NJS_COLOR c = tint;
                        NJS_ARGB argb;
                        argb.a = c.argb.a / 255.0f;
                        argb.r = c.argb.r / 255.0f;
                        argb.g = c.argb.g / 255.0f;
                        argb.b = c.argb.b / 255.0f;
                        set_particle_tint_color(p, &argb);
                    }
                    if (emit_flags & 0x200) {
                        if (emit_flags & 0x400) {
                            ((TParticleCtrl *)p)->attach_model(model, texlist, motion, 1, motion_frame);
                        } else {
                            ((TParticleCtrl *)p)->attach_model(model, texlist, motion, 0, motion_frame);
                        }
                    }
                }
            }
        } else if (kind < 3) {
            p = (u8 *)particle_ctrl_generator_table[kind].create(emitter_entry, &position, particle_parent);
            if (p != NULL) {
                set_particle_draw_scale(p, scale_x, scale_y);
                TParticleCtrl__sub_800884F0(p, &direction);
                if (emit_flags & 0x100) {
                    NJS_COLOR c = tint;
                    NJS_ARGB argb;
                    argb.a = c.argb.a / 255.0f;
                    argb.r = c.argb.r / 255.0f;
                    argb.g = c.argb.g / 255.0f;
                    argb.b = c.argb.b / 255.0f;
                    set_particle_tint_color(p, &argb);
                }
                if (emit_flags & 0x200) {
                    if (emit_flags & 0x400) {
                        ((TParticleCtrl *)p)->attach_model(model, texlist, motion, 1, motion_frame);
                    } else {
                        ((TParticleCtrl *)p)->attach_model(model, texlist, motion, 0, motion_frame);
                    }
                }
                if (emit_flags & 0x2000) {
                    ((TParticleCtrl *)p)->mark_active();
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
    m_name = TParticleCtrl__class_name_descriptor[0];
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
    m_name = TParticleCtrl__class_name_descriptor[0];
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
    m_name = TParticleCtrl__class_name_descriptor[0];
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
    m_name = TParticleCtrl__class_name_descriptor[0];
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

extern "C" {
void TParticleCtrl__sub_800884F0(void *p, void *dir) { copy_xyz((char *)p + 0x98, dir); }

void TParticleCtrl::attach_model(s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0) {
    *(s32 *)((s8 *)((u8 *)this) + 0xB0) = arg1;
    *(s32 *)((s8 *)((u8 *)this) + 0xB4) = arg2;
    *(s32 *)((s8 *)((u8 *)this) + 0xB8) = arg3;
    *(f32 *)((s8 *)((u8 *)this) + 0xC0) = farg0;
    if (arg4 != 0) {
        *(u16 *)((s8 *)((u8 *)this) + 0x24) = (u16) (*(u16 *)((s8 *)((u8 *)this) + 0x24) | 0x400);
    }
    *(u16 *)((s8 *)((u8 *)this) + 0x24) = (u16) (*(u16 *)((s8 *)((u8 *)this) + 0x24) | 0x200);
}

void set_particle_tint_color(u8 *arg0, NJS_ARGB *rgba) {
    *(u16 *)((s8 *)arg0 + 0x24) = (u16) (*(u16 *)((s8 *)arg0 + 0x24) | 0x100);
    copy_argb((NJS_ARGB *)(arg0 + 0x48), rgba);
}

void set_particle_draw_scale(void* p, f32 a, f32 b) { *(f32*)((char*)p + 0xa4) = a; *(f32*)((char*)p + 0xa8) = b; }
}
