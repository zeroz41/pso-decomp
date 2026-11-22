#ifndef PSO_ENEMY_TUNK_804F322C_H
#define PSO_ENEMY_TUNK_804F322C_H
#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct BmlResource;
class TParticleCtrl;

class TUnk_804F322C : public TObjEnemy {
public:
    TUnk_804F322C(TObject *parent, saddr set_data);
    virtual ~TUnk_804F322C();
    void update_linked_state();
    virtual void run_death_reaction();
    virtual void run_hit_reaction();
    virtual void render();
    virtual void run_task();
    BmlResource *archive;             // TBoss6PlotFalz::get_scene_archive(): texlist, model and motion
    Vec velocity;                     // towards destination at 4.166667 a frame, level
    Vec destination;                  // the set data's destination
    s32 state;                        // 4 once killed
    s32 state_timer;
    f32 motion_frame;                 // draw_model_motion's frame
    s32 attack_power;                 // the param table's +4 (20 when not positive), varied 10% per hit
    s32 status_chance;                // the param table's +8, 0..100
    s32 status_count;                 // compared below status_chance before a status hit
    f32 hit_flash;                    // 1.0 on a hit, passed to the draw tint
    s32 angle_y;                      // render's rotate_matrix_y angle
    TParticleCtrl *particle_emitter;  // create_particle_emitter(&position, 0x146)
};

LAYOUT_ASSERT(TUnk_804F322C_size, sizeof(TUnk_804F322C) == 0x3B4);

#endif
