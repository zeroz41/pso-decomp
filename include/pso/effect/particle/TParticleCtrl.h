#ifndef PSO_EFFECT_PARTICLE_TPARTICLECTRL_H
#define PSO_EFFECT_PARTICLE_TPARTICLECTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/NinjaTypes.h"
#include "pso/effect/particle/ParticleFactory.h"

struct ParticleParam;
struct NJS_OBJECT;
struct NJS_TEXLIST;
struct BmlResource;
class THeap;
class TParticle;

// Emission direction: three Ninja angles.
struct ParticleAngles { s32 x, y, z; };

// Spawns child particles from an entry of particleentry.dat at a position.
class TParticleCtrl : public TObject {
public:
    TParticleCtrl(const Vec *position, ParticleAngles *direction, ParticleParam *entry, s32 oneshot, s32 delay,
                  s32 lifetime, s32 use_self, u16 flags);
    TParticleCtrl(const Vec *position, ParticleAngles *direction, ParticleParam *entry, s32 oneshot, s32 delay,
                  s32 lifetime, s32 use_self);
    TParticleCtrl(const Vec *position, ParticleParam *entry, s32 oneshot, s32 delay, s32 lifetime, s32 use_self,
                  u16 flags);
    TParticleCtrl(const Vec *position, ParticleParam *entry, s32 oneshot, s32 delay, s32 lifetime, s32 use_self);
    virtual ~TParticleCtrl();
    virtual void run_task();
public:
    static const char *class_name;
    // The regular technique models (bm_tec_regurar.bml) and the particle textures.
    static BmlResource *regular_bml_resource;
    static NJS_TEXLIST *texture_list;
    // Moves the emitter.
    void set_position(void *pos);
    // Queues the emitter's destruction; nothing when it is NULL.
    static void release(void *emitter);
    // Who owns the effect; a client id of 0xFFFF leaves it unchanged.
    void set_owner_id(u16 id);
    void set_tint_color(s32 tint);
    void clear_active_flag();
    static TParticle *create_random_spread(void *param, void *pos, void *parent);
    // The fallback pool particles are allocated from when the alt heap is full.
    static THeap *heap;
    static void free_heap();
    static void init_heap(u32 size);
    static TParticle *generate_child_default(void *param, void *pos, void *parent);
    static NJS_OBJECT *get_particle_model(s32 model);
    // The particle texture list.
    static NJS_TEXLIST *get_instance();
    uaddr validate_ctrl();
    void destroy_particle();
    static void begin_effect_render();
    static void end_effect_render();
    static void reset_emitter_table();
    static void create_quad_sprites();
    static void reset_particles();
    static void setup_particle_draw(s32 blended);
public:
    static TParticle *alloc_child_particle(void *param, void *pos, void *dir, void *parent);
    void enable();
    static void free_system();
    static void free_all();
    static void init_particle_buffer();
    static ParticleParam *get_particle_by_index(s32 particle_index);

    void set_scale(f32 x, f32 y);
    // Restarts the emission with entry `index` of particleentry.dat
    // (0x200 and up: the area's entry file).
    void set_param_ptr(s32 index);
    // Copies the emission direction; dir points at three words.
    void set_direction(void *dir);
    void set_flags(u16 flags);
    f32 emit_count;               // 0x1C, a particle is spawned for every whole 1.0
    s32 emit_phase;               // 0x20, angle stepped by the entry's emission frequency
    f32 emit_rate;                // 0x24, scales the entry's emission rate
    ParticleParam *emitter_entry; // 0x28
    // 0x2C: 1 skips the next run, 0x10/0x80 spawn orbit and radial children in those modes, 0x40 emits at any
    // distance, 0x100 tints the children, 0x200 (0x400) attaches the model (looped), 0x800/0x4000 parent them
    // under tl_clipout, 0x2000 marks them active.
    u16 emit_flags;
    u16 owner_id;                 // 0x2E, 0xFFFF for none
    s32 oneshot;                  // 0x30, 1: destroyed after its first run
    s32 delay;                    // 0x34, frames before the first run
    s32 lifetime;                 // 0x38, frames; 0 runs until released
    s32 age;                      // 0x3C
    f32 scale_x;                  // 0x40
    f32 scale_y;                  // 0x44
    NJS_COLOR tint;               // 0x48, used when emit_flags & 0x100
    void *model;                  // 0x4C, given to the children (emit_flags & 0x200)
    NJS_TEXLIST *texlist;    // 0x50
    NJS_MOTION *motion;           // 0x54
    TObject *particle_parent;     // 0x58, task the children are created under
    f32 motion_frame;             // 0x5C
    Vec position;                 // 0x60
    ParticleAngles direction;     // 0x6C
};

LAYOUT_ASSERT(TParticleCtrl_size, sizeof(TParticleCtrl) == 0x78);

// Child generators of an emitter: TParticleCtrl::run_task calls
// particle_ctrl_generator_table[kind].create(param, &pos, parent).
struct ParticleGenerator {
    const char *name;
    TParticle *(*create)(void *param, void *pos, void *parent);
};

extern ParticleGenerator particle_ctrl_generator_table[];

// Number of entries in particleentry.dat; ids from 0x200 index the area's entry file.
extern s32 particle_pool_limit;
// Loads the area's particle entries, the regular technique models and their textures.
void load_particle_entry_resources(void);

// Emitter spawners. `id` is an entry of particleentry.dat (0x200 and up: the area's entry file); each returns NULL
// for an id past both tables. A oneshot emitter is destroyed after its first run; `use_self` creates the particles
// under the emitter instead of tl_07. spawn_particle_effect and spawn_particle_effect_with_flags (oneshot) are
// declared in ParticleFactory.h.
TParticleCtrl *create_timed_particle_emitter_with_flags(void *pos, s32 id, s32 delay, s32 duration, u16 flags);
TParticleCtrl *create_timed_particle_emitter(const void *pos, s32 id, s32 delay, s32 duration);
TParticleCtrl *create_timed_particle_emitter_with_angles(void *pos, void *dir, s32 id, s32 delay, s32 duration, u16 flags);
TParticleCtrl *create_particle_controller_with_rotation(Vec *pos, ParticleAngles *dir, s32 id, s32 delay, s32 duration);
TParticleCtrl *create_oneshot_particle_emitter(void *pos, void *dir, s32 id, u16 flags);
TParticleCtrl *spawn_directional_particle(void *pos, void *dir, s32 id);
TParticleCtrl *create_particle_controller(void *pos, s32 id, s32 use_self);
TParticleCtrl *create_particle_controller_with_angles(void *pos, void *dir, s32 id, s32 use_self, u16 flags);
TParticleCtrl *create_particle_controller_with_angles(void *pos, void *dir, s32 id, s32 use_self);
TParticleCtrl *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, u16 flags);
TParticleCtrl *spawn_continuous_particle_with_direction(void *pos, void *dir, s32 id);
TParticleCtrl *spawn_continuous_particle_effect_with_flags(void *pos, s32 id, u16 flags);
TParticleCtrl *create_particle_emitter(const void *pos, s32 id);

// Sets the colour the frame is cleared to from a packed ARGB value, with depth cleared to the far plane. Only the
// colour is read.
void set_copy_clear_color_argb(u32 argb, s32, s32);

// Colour channel scaled by the fade alpha; nothing below zero, at most alpha.
inline f32 fade_particle_channel(f32 c, f32 alpha) {
    return (c < 0.0f) ? 0.0f : alpha * ((c < 1.0f) ? c : 1.0f);
}

// Colour channel limited to 0..1.
inline f32 clamp_particle_channel(f32 c) {
    return (c < 0.0f) ? 0.0f : ((c < 1.0f) ? c : 1.0f);
}

#endif
