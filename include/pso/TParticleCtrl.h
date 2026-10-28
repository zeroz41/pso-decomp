#ifndef PSO_TPARTICLECTRL_H
#define PSO_TPARTICLECTRL_H
#include "pso/TObject.h"
#include "types.h"

class TParticleCtrl : public TObject {
public:
    virtual ~TParticleCtrl();
    virtual void run_task();
public:
    // Who owns the effect; a client id of 0xFFFF leaves it unchanged.
    void set_owner_id(u16 id);
    void set_tint_color(s32 arg1);
    void clear_active_flag();
    static void *create_random_spread(void *arg0, void *arg1, void *arg2);
    static u8 *create_particle_obj_90(s32 arg0);
    static u8 *create_particle_obj_ac(s32 arg0);
    void mark_active();
    static void disable_if_single_screen();
    static void free_heap();
    static void init_heap(void *arg0);
    void generate_child_default(s32 arg1, s32 arg2);
    static s32 get_particle_model(s32 arg0);
    static int get_instance();
    u32 validate_ctrl();
    void destroy_particle();
    static void begin_effect_render();
    static void end_effect_render();
    static void reset_emitter_table();
    static void create_quad_sprites();
    static void set_tev_direct(s32 arg0);
    int get_object();
    static void reset_ind_tev_stages(void * _w0);
    void play_particle(s32 arg1, s16 arg2);
    static void reset_particles();
    static void setup_particle_draw(s32 arg0);
public:
    void *alloc_child_particle(void *arg1, void *arg2, void *arg3);
    u8 *init_random_particle(u8 *arg1, u8 *arg2, s32 arg3);
    u8 *construct_particle_obj(s32 arg1, s32 arg2);
    u8 *init_particle_obj(s32 arg1, s32 arg2);
    void enable();
    void *initialize_with_flags(const void *position, s32 particle_index, s32 field30, s32 field34, s32 field38, s32 use_self, u16 flags);
    void *initialize(const void *position, s32 particle_index, s32 field30, s32 field34, s32 field38, s32 use_self);
    void attach_model(s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
    static void free_system();
    static void free_all();
    static void init_particle_buffer();
    static s32 get_particle_by_index(s32 arg0);
};

#endif
