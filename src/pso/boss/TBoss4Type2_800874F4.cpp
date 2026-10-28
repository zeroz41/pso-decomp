#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/misc/TNowLoading.h"
#include "pso/TObject.h"
#include "pso/misc/TUnk_8048E728.h"
#include "pso/misc/TUnk_8048E778.h"
#include "pso/misc/TUnk_8048E790.h"
#include "pso/misc/TUnk_8048E7A8.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct O_80087638 { u8 pad[0x2e]; u16 x2e; };

struct Ent_800874F4 { u8 data[0x98]; };

extern "C" {
extern s32 particle_pool_limit;
extern s32 particle_global_entry_table;
extern s32 particle_area_entry_table;
void *__nw__7TObjectFUl(int);

void *create_particle_emitter(void *pos, s32 id) {
    void *p;
    if (particle_pool_limit > id) {
        p = __nw__7TObjectFUl(0x78);
        if (p != 0) {
            p = ((TParticleCtrl *)p)->initialize((const void *)pos, (s32)(&(*(Ent_800874F4 * *)&particle_global_entry_table)[id]), 0, 0, 0, 0);
        }
        return p;
    }
    if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        p = __nw__7TObjectFUl(0x78);
        if (p != 0) {
            p = ((TParticleCtrl *)p)->initialize((const void *)pos, (s32)(&(*(Ent_800874F4 * *)&particle_area_entry_table)[idx]), 0, 0, 0, 0);
        }
        return p;
    }
    return 0;
}

void TBoss4Type2::set_param_ptr(s32 arg1) {
    *(f32 *)((s8 *)this + 0x1C) = 0.0f;
    *(s32 *)((s8 *)this + 0x20) = 0;
    *(f32 *)((s8 *)this + 0x24) = 1.0f;
    if (arg1 >= 0x200) {
        *(s32 *)((s8 *)this + 0x28) = (s32) (particle_area_entry_table + ((arg1 - 0x200) * 0x98));
        return;
    }
    *(s32 *)((s8 *)this + 0x28) = (s32) (particle_global_entry_table + (arg1 * 0x98));
}

void TBoss4Type2::copy_vec3(void* q) { *(u32*)((char*)this + 0x6c) = *(u32*)((char*)q + 0x0); *(u32*)((char*)this + 0x70) = *(u32*)((char*)q + 0x4); *(u32*)((char*)this + 0x74) = *(u32*)((char*)q + 0x8); }
void TBoss4Type2::set_flags(u32 v) { *(u16*)((char*)this + 0x2c) |= v; }

void TParticleCtrl::set_owner_id(u16 id) {
    O_80087638 *self = (O_80087638 *)this;
    if (id != 0xFFFF) {
        self->x2e = id;
    }
}

void TParticleCtrl::set_tint_color(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    *(u16 *)((s8 *)arg0 + 0x2C) = (u16) (*(u16 *)((s8 *)arg0 + 0x2C) | 0x100);
    *(s32 *)((s8 *)arg0 + 0x48) = arg1;
}

}

void TNowLoading::copy_pos(void* q) { *(f32*)((char*)this + 0x60) = *(f32*)((char*)q + 0x0); *(f32*)((char*)this + 0x64) = *(f32*)((char*)q + 0x4); *(f32*)((char*)this + 0x68) = *(f32*)((char*)q + 0x8); }

#pragma readonly_strings on

const char *TParticleCtrl__class_name_descriptor[2] = {"TParticleCtrl", 0};
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

typedef u8 *(*Gen_8008767C)(void *, void *, u32);
struct Vec_8008767C { f32 x, y, z; };

struct Color_8008767C { u8 r, g, b, a; };

struct Def_8008767C {
    u8 pad0[0x10];
    s32 kind;
    u8 pad14[0x40 - 0x14];
    f32 freq;
    f32 amp;
};

struct Ctrl_8008767C {
    u8 pad0[0x1C];
    f32 accum;
    s32 angle;
    f32 rate;
    Def_8008767C *def;
    u16 flags;
    u16 f2E;
    s32 f30;
    s32 delay;
    s32 lifetime;
    s32 age;
    f32 sx;
    f32 sy;
    Color_8008767C color;
    s32 model;
    s32 texlist;
    s32 motion;
    u32 tex;
    f32 frame;
    Vec_8008767C pos;
    Vec_8008767C dir;
};

struct GenEntry_8008767C { s32 id; Gen_8008767C fn; };

extern "C" {
void set_particle_tint_color(u8 *arg0, void *arg1);
void TLobby__sub_8001FE7C(void*, int);
s32 release_texture_list(void*);
void mem_free(void *p);
extern s32 particle_area_entry_table;
extern u32 TParticleCtrl__regular_bml_resource;
extern u32 TParticleCtrl__texture_list;
s32 read_disc_file(s32, s32);
s32 mem_alloc(s32);
// particle_pool_limit: declared s32 above (part 1)
// particle_global_entry_table: declared s32 above (part 1)
u8 *create_ballistic_particle(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, u16 arg4, s16 arg5);
int queue_destruction__7TObjectFv(void *);
u8 *create_orbit_particle(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, u16 arg4, s16 arg5);
u8 *create_radial_particle(u8 *arg0, u8 *arg1, s32 arg2, u16 arg3, s16 arg4);
void *load_resource_from_descriptor(void *, int, void *, int, int, int);
void *alloc__23TAdSinglePlyChrSelectGCFv(int);
u8 *load_gvm_texture_file(s32 arg0);
int sprintf(char *, const char *, ...);
char *strcpy(char *, const char *);
void *memset(void *, int, u32);
s32 is_split_screen();
s32 all_parents_unqueued_for_destruction__7TObjectFv();
extern u8 *camera_ctrl_instance;
void VecCopy__FP3VecPC3Vec(void *, const void *);
int TParticleCtrl__sub_800884F0(void* p);
void set_particle_draw_scale(void* p, f32 a, f32 b);
s32 TLoadCtrl__sub_8001C60C();
f32 horizontal_distance_squared(void *, void *);
u8 *get_player_by_client_id(s32);
f32 sin_table_lookup(s32);
f32 fabs_float(f32);
extern GenEntry_8008767C particle_ctrl_generator_table[];
extern void *tl_07;
extern void *tl_particlemodel;
void run_task__13TParticleCtrlFv(Ctrl_8008767C *self);
}
void load_particle_entry_resources(void);
extern char lbl_80439494[];
extern char lbl_804394A4[];
extern char lbl_804394BC[];
extern char lbl_804394D4[];

extern "C" {

void clear_active_flag__13TParticleCtrlFv(void* p);
int copy_xyz__10TObjPlayerFPv(void*);

#pragma push
#pragma fp_contract on
#define CREATE6(fn) ((u8 *(*)(void *, void *, void *, u32, u32, u32))fn)
#define SETUP_8008767C(p, B)                                                            \
    set_particle_draw_scale(p, self->sx, self->sy);                                   \
    if (self->flags & 0x100) {                                                        \
        Color_8008767C c = self->color;                                               \
        f32 rgba[4];                                                                  \
        rgba[0] = c.r / 255.0f;                                                 \
        rgba[1] = c.g / 255.0f;                                                 \
        rgba[2] = c.B / 255.0f;                                                 \
        rgba[3] = c.a / 255.0f;                                                 \
        set_particle_tint_color(p, rgba);                                             \
    }                                                                                 \
    if (self->flags & 0x200) {                                                        \
        if (self->flags & 0x400) {                                                    \
            ((TParticleCtrl *)p)->attach_model(self->model, self->texlist, self->motion, 1, self->frame); \
        } else {                                                                      \
            ((TParticleCtrl *)p)->attach_model(self->model, self->texlist, self->motion, 0, self->frame); \
        }                                                                             \
    }
void run_task__13TParticleCtrlFv(Ctrl_8008767C *self) {
    Def_8008767C *def;
    s32 kind;
    u8 *p;
    f32 step;
    if (all_parents_unqueued_for_destruction__7TObjectFv() == 0) {
        return;
    }
    if (self->delay-- <= 0) {
        self->delay = 0;
    } else {
        return;
    }
    self->age++;
    if (self->flags & 1) {
        self->flags &= ~1;
        return;
    }
    if (((self->flags & 0x200) || (self->flags & 0x2000)) && self->tex == (u32)tl_07) {
        self->tex = (u32)tl_particlemodel;
    }
    def = self->def;
    if (def == NULL) {
        return;
    }
    if (0.0f == def->freq) {
        self->accum += def->amp * self->rate;
    } else {
        self->angle += (s32)(182.04445f * def->freq);
        self->accum += self->rate * (self->def->amp * fabs_float(sin_table_lookup(self->angle)));
    }
    if (camera_ctrl_instance != NULL && !(self->flags & 0x40)) {
        if (is_split_screen() != 0) {
            if (TLoadCtrl__sub_8001C60C() == 0) {
                f32 lim = 10000.0f;
                s32 near = 0;
                s32 i;
                for (i = 0; i < 4; i++) {
                    u8 *pl = get_player_by_client_id(i);
                    if (pl != NULL && horizontal_distance_squared(&self->pos, pl + 0x38) < lim) {
                        near = 1;
                    }
                }
                if (near == 0) {
                    self->accum = 0.0f;
                }
            }
        } else if (TLoadCtrl__sub_8001C60C() == 0) {
            if (!(horizontal_distance_squared(&self->pos, camera_ctrl_instance + 0x178) < 40000.0f)) {
                self->accum = 0.0f;
            }
        }
    }
    step = 1.0f;
    while (self->accum >= step) {
        self->accum -= step;
        kind = self->def->kind;
        if (kind == 0) {
            u8 *q = CREATE6(create_ballistic_particle)(self->def, &self->pos, &self->dir, self->tex, self->flags, self->f2E);
            if (q != NULL) {
                SETUP_8008767C(q, b)
            }
        } else if (self->flags & 0x10) {
            if (kind == 1) {
                p = CREATE6(create_orbit_particle)(self->def, &self->pos, &self->dir, self->tex, 0x10, self->f2E);
                if (p != NULL) {
                    SETUP_8008767C(p, b)
                }
            } else if (kind == 2) {
                p = ((u8 *(*)(void *, void *, u32, u32, u32))create_radial_particle)(self->def, &self->pos, self->tex, 0x10, self->f2E);
                if (p != NULL) {
                    SETUP_8008767C(p, a)
                }
            }
        } else if (self->flags & 0x80) {
            if (kind == 1) {
                p = CREATE6(create_orbit_particle)(self->def, &self->pos, &self->dir, self->tex, 0x80, 0xFFFF);
                if (p != NULL) {
                    SETUP_8008767C(p, b)
                }
            } else if (kind == 2) {
                p = ((u8 *(*)(void *, void *, u32, u32, u32))create_radial_particle)(self->def, &self->pos, self->tex, 0x80, 0xFFFF);
                if (p != NULL) {
                    SETUP_8008767C(p, b)
                }
            }
        } else if (kind < 3) {
            p = particle_ctrl_generator_table[kind].fn(self->def, &self->pos, self->tex);
            if (p != NULL) {
                set_particle_draw_scale(p, self->sx, self->sy);
                ((int (*)(void *, void *))TParticleCtrl__sub_800884F0)(p, &self->dir);
                if (self->flags & 0x100) {
                    Color_8008767C c = self->color;
                    f32 rgba[4];
                    rgba[0] = c.r / 255.0f;
                    rgba[1] = c.g / 255.0f;
                    rgba[2] = c.b / 255.0f;
                    rgba[3] = c.a / 255.0f;
                    set_particle_tint_color(p, rgba);
                }
                if (self->flags & 0x200) {
                    if (self->flags & 0x400) {
                        ((TParticleCtrl *)p)->attach_model(self->model, self->texlist, self->motion, 1, self->frame);
                    } else {
                        ((TParticleCtrl *)p)->attach_model(self->model, self->texlist, self->motion, 0, self->frame);
                    }
                }
                if (self->flags & 0x2000) {
                    ((TParticleCtrl *)p)->mark_active();
                }
            }
        }
    }
    if (self->f30 == 1) {
        queue_destruction__7TObjectFv(self);
    }
    if (self->lifetime != 0 && self->age >= self->lifetime) {
        queue_destruction__7TObjectFv(self);
    }
}
#pragma pop
extern "C" {
extern u32 bm_tec_regurar_motion_names[1];
extern const char *bm_tec_regurar_model_names[4];
extern void *particle_regular_bml_descriptor[4];
extern const char *TParticleCtrl__particle_entry_path;
}

void clear_active_flag__13TParticleCtrlFv(void* p) { *(u16*)((char*)p + 0x2c) &= 0xfffe; }
void TParticleCtrl::enable() { *(u16*)((char*)this + 0x2c) |= 0x1; }
extern "C" {
void __dt__7TObjectFv(void *, int);
void __dl__7TObjectFPv(void *);
void render__7TObjectFv(void);
void render_shadows__7TObjectFv(void);
void *__dt__13TParticleCtrlFv(void *self, s16 flag);
void *__vt__13TParticleCtrl[] = {
    0,
    0,
    (void *)__dt__13TParticleCtrlFv,
    (void *)run_task__13TParticleCtrlFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
};
void *__dt__13TParticleCtrlFv(void *self, s16 flag) {
    if (self != 0) {
        *(void **)((u8 *)self + 0x18) = __vt__13TParticleCtrl;
        __dt__7TObjectFv(self, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
}
extern "C" {
u32 bm_tec_regurar_motion_names[1] = {0};
const char *bm_tec_regurar_model_names[4] = {"eff_f_foie.gj", "eff_sinowahamon.gj", "jungle_hamon.gj", 0};
void *particle_regular_bml_descriptor[4] = {(void *)"bm_tec_regurar.bml", bm_tec_regurar_model_names, bm_tec_regurar_motion_names, (void *)0x30000};
const char *TParticleCtrl__particle_entry_path = "particleentry.dat";
}

extern "C" {

struct ParticleVec {
    s32 x;
    s32 y;
    s32 z;
};

struct ParticleCtrlData {
    s32 descriptor;
    u8 pad04[0x14];
    void *vtable;
    f32 field1C;
    s32 field20;
    f32 field24;
    s32 particle_index;
    u16 flags;
    u16 field2E;
    s32 field30;
    s32 field34;
    s32 field38;
    s32 field3C;
    f32 field40;
    f32 field44;
    s32 field48;
    s32 field4C;
    s32 field50;
    s32 field54;
    void *owner;
    u8 pad5C[4];
    ParticleVec position;
    ParticleVec direction;
};

void __ct__7TObjectFP7TObject(void *, void *);

extern void *__vt__13TParticleCtrl[];
extern void *tl_clipout;

#define COPY_PARTICLE_DIRECTION(particle, direction) do {                      \
    s32 component;                                                             \
    component = direction->x;                                                  \
    particle->direction.x = component;                                         \
    component = direction->z;                                                  \
    particle->direction.z = component;                                         \
    component = direction->y;                                                  \
    particle->direction.y = component;                                         \
} while (0)
#define CLEAR_PARTICLE_DIRECTION(particle, unused) do {                        \
    particle->direction.x = 0;                                                 \
    particle->direction.y = 0;                                                 \
    particle->direction.z = 0;                                                 \
} while (0)

#define INITIALIZE_PARTICLE(particle, position, particle_index, field30,       \
                            field34, field38, use_self, particle_flags,        \
                            direction_action, direction_source) do {           \
    __ct__7TObjectFP7TObject(particle, tl_07);                                 \
    particle->vtable = __vt__13TParticleCtrl;                                  \
    particle->descriptor = (s32)TParticleCtrl__class_name_descriptor[0];                       \
    particle->field4C = 0;                                                     \
    particle->field50 = 0;                                                     \
    particle->field54 = 0;                                                     \
    particle->field48 = 0;                                                     \
    particle->field40 = 1.0f;                          \
    particle->field44 = 1.0f;                          \
    particle->field1C = 0.0f;                          \
    particle->field20 = 0;                                                     \
    particle->field24 = 1.0f;                          \
    particle->particle_index = particle_index;                                 \
    VecCopy__FP3VecPC3Vec(&particle->position, position);                      \
    particle->flags = particle_flags;                                          \
    particle->field2E = 0xFFFF;                                                \
    direction_action(particle, direction_source);                              \
    particle->field30 = field30;                                               \
    particle->field34 = field34;                                               \
    particle->field38 = field38;                                               \
    particle->field3C = 0;                                                     \
    if (use_self != 0) {                                                       \
        particle->owner = particle;                                            \
    } else if (particle->flags & 0x800) {                                      \
        if (particle->flags & 0x4000) {                                        \
            particle->owner = tl_clipout;                                      \
        } else {                                                               \
            particle->owner = tl_07;                                           \
        }                                                                      \
    } else {                                                                   \
        particle->owner = tl_07;                                               \
    }                                                                          \
} while (0)

void *__ct__13TParticleCtrlFv(
    ParticleCtrlData *particle,
    const void *position,
    ParticleVec *direction,
    s32 particle_index,
    s32 field30,
    s32 field34,
    s32 field38,
    s32 use_self,
    u16 flags)
{
    __ct__7TObjectFP7TObject(particle, tl_07);
    particle->vtable = __vt__13TParticleCtrl;
    particle->descriptor = (s32)TParticleCtrl__class_name_descriptor[0];
    particle->field4C = 0;
    particle->field50 = 0;
    particle->field54 = 0;
    particle->field48 = 0;
    particle->field40 = 1.0f;
    particle->field44 = 1.0f;
    particle->field1C = 0.0f;
    particle->field20 = 0;
    particle->field24 = 1.0f;
    particle->particle_index = particle_index;
    VecCopy__FP3VecPC3Vec(&particle->position, position);
    particle->flags = flags;
    particle->field2E = 0xFFFF;
    {
        s32 component;
        component = direction->x;
        particle->direction.x = component;
        component = direction->z;
        particle->direction.z = component;
        component = direction->y;
        particle->direction.y = component;
    }
    particle->field30 = field30;
    particle->field34 = field34;
    particle->field38 = field38;
    particle->field3C = 0;
    if (use_self != 0) {
        particle->owner = particle;
    } else if (particle->flags & 0x800) {
        if (particle->flags & 0x4000) {
            particle->owner = tl_clipout;
        } else {
            particle->owner = tl_07;
        }
    } else {
        particle->owner = tl_07;
    }
    return particle;
}

void *initialize_with_direction__13TParticleCtrlFPvPvPviiiii(
    ParticleCtrlData *particle,
    const void *position,
    ParticleVec *direction,
    s32 particle_index,
    s32 field30,
    s32 field34,
    s32 field38,
    s32 use_self)
{
    __ct__7TObjectFP7TObject(particle, tl_07);
    particle->vtable = __vt__13TParticleCtrl;
    particle->descriptor = (s32)TParticleCtrl__class_name_descriptor[0];
    particle->field4C = 0;
    particle->field50 = 0;
    particle->field54 = 0;
    particle->field48 = 0;
    particle->field40 = 1.0f;
    particle->field44 = 1.0f;
    particle->field1C = 0.0f;
    particle->field20 = 0;
    particle->field24 = 1.0f;
    particle->particle_index = particle_index;
    VecCopy__FP3VecPC3Vec(&particle->position, position);
    particle->flags = 0;
    particle->field2E = 0xFFFF;
    {
        s32 component;
        component = direction->x;
        particle->direction.x = component;
        component = direction->z;
        particle->direction.z = component;
        component = direction->y;
        particle->direction.y = component;
    }
    particle->field30 = field30;
    particle->field34 = field34;
    particle->field38 = field38;
    particle->field3C = 0;
    if (use_self != 0) {
        particle->owner = particle;
    } else if (particle->flags & 0x800) {
        if (particle->flags & 0x4000) {
            particle->owner = tl_clipout;
        } else {
            particle->owner = tl_07;
        }
    } else {
        particle->owner = tl_07;
    }
    return particle;
}

void *TParticleCtrl::initialize_with_flags(const void *position, s32 particle_index, s32 field30, s32 field34, s32 field38, s32 use_self, u16 flags) {
    INITIALIZE_PARTICLE(((ParticleCtrlData *)this), position, particle_index, field30, field34,
                        field38, use_self, flags, CLEAR_PARTICLE_DIRECTION,
                        position);
    return ((ParticleCtrlData *)this);
}

void *TParticleCtrl::initialize(const void *position, s32 particle_index, s32 field30, s32 field34, s32 field38, s32 use_self) {
    INITIALIZE_PARTICLE(((ParticleCtrlData *)this), position, particle_index, field30, field34,
                        field38, use_self, 0, CLEAR_PARTICLE_DIRECTION,
                        position);
    return ((ParticleCtrlData *)this);
}

}

int TParticleCtrl__sub_800884F0(void* p) { return copy_xyz__10TObjPlayerFPv((char*)p + 0x98); }

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

void set_particle_tint_color(u8 *arg0, void *arg1) {
    *(u16 *)((s8 *)arg0 + 0x24) = (u16) (*(u16 *)((s8 *)arg0 + 0x24) | 0x100);
    ((void (*)(void *, void *, void *))copy_argb)(arg0 + 0x48, arg1, arg0);
}

void set_particle_draw_scale(void* p, f32 a, f32 b) { *(f32*)((char*)p + 0xa4) = a; *(f32*)((char*)p + 0xa8) = b; }

void TParticleCtrl::free_system() { mem_free((void *)particle_global_entry_table); particle_global_entry_table = 0; }
void TParticleCtrl::free_all() {
    mem_free((void *)particle_area_entry_table);
    particle_area_entry_table = 0;
    if ((u32) TParticleCtrl__regular_bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TParticleCtrl__regular_bml_resource, 1);
        TParticleCtrl__regular_bml_resource = 0U;
    }
    if ((u32) TParticleCtrl__texture_list != 0U) {
        release_texture_list((void*)TParticleCtrl__texture_list);
        TAdSinglePlyChrSelectGC::safe_free(TParticleCtrl__texture_list);
        TParticleCtrl__texture_list = 0U;
    }
}
void TParticleCtrl::init_particle_buffer() {
    s32 temp_r3;
    temp_r3 = read_disc_file((s32)TParticleCtrl__particle_entry_path, ((*(s32 *)&particle_global_entry_table) = mem_alloc(0x13000)));
    particle_pool_limit = 0;
    if (temp_r3 >= 0) {
        particle_pool_limit = (u32) temp_r3 / 152U;
    }
}
s32 TParticleCtrl::get_particle_by_index(s32 arg0) {
    if (arg0 >= 0x200) {
        return particle_area_entry_table + ((arg0 - 0x200) * 0x98);
    }
    return (*(s32 *)&particle_global_entry_table) + (arg0 * 0x98);
}
}

void load_particle_entry_resources(void) {
    char name[0x20];
    s32 state;
    void *p;
    memset(name, 0, 0x20);
    strcpy(name, lbl_80439494);
    state = TOKeyMachine01::get_global_state();
    if (state < 10) {
        if (state < 0) {
            return;
        }
        sprintf(name, lbl_804394A4, state);
    } else {
        sprintf(name, lbl_804394BC, state);
    }
    read_disc_file((s32)name, particle_area_entry_table = mem_alloc(0x2600));
    p = alloc__23TAdSinglePlyChrSelectGCFv(0x440);
    if (p != 0) {
        p = load_resource_from_descriptor(p, 1, particle_regular_bml_descriptor, 0, 0, 0);
    }
    TParticleCtrl__regular_bml_resource = (u32)p;
    TParticleCtrl__texture_list = (u32)load_gvm_texture_file((s32)lbl_804394D4);
}
extern "C" {

__declspec(section ".rodata") extern char lbl_80439494[] = "particleentrya";
__declspec(section ".rodata") extern char lbl_804394A4[] = "particleentrya0%d.dat";
__declspec(section ".rodata") extern char lbl_804394BC[] = "particleentrya%d.dat";
__declspec(section ".rodata") extern char lbl_804394D4[] = "tecregular.gvm";
}
