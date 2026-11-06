#ifndef PSO_BOSS_GOLDRAGON_TOBJBOSS8PILLER_H
#define PSO_BOSS_GOLDRAGON_TOBJBOSS8PILLER_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TObjBoss8Piller : public TObject {
public:
    virtual ~TObjBoss8Piller();
    virtual void run_task();
    virtual void render();
public:
    static void free_held_object();
    static void load_resource_descriptor();
};

extern "C" {
u8 *__ct__15TObjBoss8PillerFv(u8 *object, u8 *arg1, u8 *arg2, s16 arg3);
}

#endif
