#ifndef PSO_OBJECT_COLLISION_TOBJRADERCOL_H
#define PSO_OBJECT_COLLISION_TOBJRADERCOL_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjRaderCol : public TObjBase {
    TObjRaderCol(TObject *parent, void *set_data);
    virtual ~TObjRaderCol();
    f32 radius;        // scale.x: how near a player must come
    u32 id;            // set_params[0]: the radar region it reveals
    u32 state;         // 0 blocks its region, 1 waiting for a player
    s32 delay;         // frames to wait after spawning
    virtual void render();
    void check_local_player_in_range();
    void check_any_player_in_range();
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjRaderCol_size, sizeof(TObjRaderCol) == 0xA0);

extern "C" {
void *__dt__12TObjRaderColFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjRaderCol.cpp ---
extern "C" {
void *__dt__12TObjRaderColFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
