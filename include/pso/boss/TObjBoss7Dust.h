#ifndef PSO_BOSS_TOBJBOSS7DUST_H
#define PSO_BOSS_TOBJBOSS7DUST_H

#include "pso/TObject.h"
#include "types.h"

class TObjBoss7Dust : public TObject {
public:
    virtual ~TObjBoss7Dust();
    virtual void run_task();
    virtual void render();
};

extern "C" {
u8 *__ct__13TObjBoss7DustFv(u8 *arg0, s32 arg1, s32 arg2);
void fn_802F105C(void);
void fn_802F1084(void);
}
void init_scene_boss2_tunnel(void);

#endif
