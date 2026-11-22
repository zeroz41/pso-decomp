#ifndef PSO_EFFECT_PARTICLE_TPARTICLECTRL_H
#define PSO_EFFECT_PARTICLE_TPARTICLECTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

struct ParticleParam;
struct NJS_OBJECT;
struct GinjaTextureList;

class TParticleCtrl : public TObject {
public:
    virtual ~TParticleCtrl();
    virtual void run_task();
public:
    // Moves the emitter.
    // pos points at a Vec.
    void set_position(void *pos);
    // Queues the emitter's destruction; nothing when it is NULL.
    static void release(void *emitter);
    // Who owns the effect; a client id of 0xFFFF leaves it unchanged.
    void set_owner_id(u16 id);
    void set_tint_color(s32 tint);
    void clear_active_flag();
    static void *create_random_spread(void *arg0, void *pos, void *parent);
    static u8 *create_particle_obj_90(s32 arg0);
    static u8 *create_particle_obj_ac(s32 arg0);
    void mark_active();
    static void free_heap();
    static void init_heap(u32 size);
    static void *generate_child_default(void *param, void *pos, void *parent);
    static NJS_OBJECT *get_particle_model(s32 model);
    // The particle texture list.
    static GinjaTextureList *get_instance();
    uaddr validate_ctrl();
    void destroy_particle();
    static void begin_effect_render();
    static void end_effect_render();
    static void reset_emitter_table();
    static void create_quad_sprites();
    static void reset_ind_tev_stages(void * _w0);
    void play_particle(s32 arg1, s16 arg2);
    static void reset_particles();
    static void setup_particle_draw(s32 arg0);
public:
    static void *alloc_child_particle(void *param, void *pos, void *dir, void *parent);
    u8 *construct_particle_obj(s32 arg1, saddr parent);
    u8 *init_particle_obj(s32 arg1, saddr parent);
    void enable();
    TParticleCtrl *initialize(const void *position, ParticleParam *entry, s32 field30, s32 field34, s32 field38, s32 use_self);
    void attach_model(s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
    static void free_system();
    static void free_all();
    static void init_particle_buffer();
    static ParticleParam *get_particle_by_index(s32 particle_index);

    void set_scale(f32, f32);
    // Restarts the emission with entry `index` of particleentry.dat
    // (0x200 and up: the area's entry file).
    void set_param_ptr(s32 index);
    // Copies the emission direction; dir points at three words.
    void set_direction(void *dir);
    void set_flags(u16 flags);
    u8 pad_1c[0xC];
    ParticleParam *emitter_entry;
    u8 pad_2c[0x14];
    f32 field_40;
    f32 field_44;
    u8 pad_48[0x18];
    Vec position;
};

extern "C" {
TParticleCtrl *initialize_flagged_particle(void *storage, const void *position, ParticleParam *entry,
                                           s32 mode, s32 delay, s32 duration, s32 use_self, s32 flags);
void *__dt__13TUnk_8048E6A8Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_8048E6DCFv(void *arg0, s16 arg1);
}

// Colour channel scaled by the fade alpha; nothing below zero, at most alpha.
inline f32 fade_particle_channel(f32 c, f32 alpha) {
    return (c < 0.0f) ? 0.0f : alpha * ((c < 1.0f) ? c : 1.0f);
}

// Colour channel limited to 0..1.
inline f32 clamp_particle_channel(f32 c) {
    return (c < 0.0f) ? 0.0f : ((c < 1.0f) ? c : 1.0f);
}

#endif
