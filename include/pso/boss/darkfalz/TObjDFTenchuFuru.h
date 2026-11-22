#ifndef PSO_BOSS_DARKFALZ_TOBJDFTENCHUFURU_H
#define PSO_BOSS_DARKFALZ_TOBJDFTENCHUFURU_H

struct NJS_OBJECT;

#include "pso/system/task/TObject.h"

struct NJS_OBJECT;
#include "types.h"
#include <dolphin/mtx.h>
#include <stddef.h>

class TParticleCtrl;

class TObjDFTenchuFuru : public TObject {
public:
    Vec pos;               // starts 300 above the spawn point, falls 60 a frame
    s32 timer;             // frames left before it destroys itself
    TParticleCtrl *effect; // create_particle_emitter(&pos, 0x134)
public:
    TObjDFTenchuFuru(TObject *parent, const Vec *position);
    virtual ~TObjDFTenchuFuru();
    virtual void run_task();
public:
    static TObjDFTenchuFuru *create(TObject *parent, const Vec *position);
    static void capture_matrix_by_frame(NJS_OBJECT *);
    static void register_callback();
    static void unregister_callback();
    // Walks a Ninja node tree like the chunk drawer, capturing nodes 0x3B and 0x3A.
    static void transform_node_tree(NJS_OBJECT *node);
    static void draw_node_tree(NJS_OBJECT *node);

    // Node counter shared by transform_node_tree and capture_matrix_by_frame.
    static int matrix_node_index;
};

LAYOUT_ASSERT(TObjDFTenchuFuru_pos_offset, offsetof(TObjDFTenchuFuru, pos) == 0x1C);
LAYOUT_ASSERT(TObjDFTenchuFuru_timer_offset, offsetof(TObjDFTenchuFuru, timer) == 0x28);
LAYOUT_ASSERT(TObjDFTenchuFuru_effect_offset, offsetof(TObjDFTenchuFuru, effect) == 0x2C);
LAYOUT_ASSERT(TObjDFTenchuFuru_size, sizeof(TObjDFTenchuFuru) == 0x30);

// Shared by the first and second combat forms.
extern "C" {
void spawn_tenchu_furu(TObject *parent);
void apply_tenchu_hits(TObject *source);
}

#endif
