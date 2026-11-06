#ifndef PSO_BOSS_GALGRYPHON_TOBJBOSS5FLOORGRASS_H
#define PSO_BOSS_GALGRYPHON_TOBJBOSS5FLOORGRASS_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TObjBoss5FloorGrass : public TObject {
public:
    TObjBoss5FloorGrass(TObject *parent);
    virtual ~TObjBoss5FloorGrass();
    virtual void run_task();
    virtual void render();
public:
    static void *create();
    static void render();
    static void run_task();
};

#endif
