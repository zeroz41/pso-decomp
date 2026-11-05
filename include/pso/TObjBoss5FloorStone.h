#ifndef PSO_TOBJBOSS5FLOORSTONE_H
#define PSO_TOBJBOSS5FLOORSTONE_H
#include "pso/TObject.h"
#include "types.h"

class TObjBoss5FloorStone : public TObject {
public:
    TObjBoss5FloorStone(TObject *parent);
    virtual ~TObjBoss5FloorStone();
    virtual void run_task();
    virtual void render();
public:
    static void *create();
    static void render();
    static void run_task();
    void render_impl(void* a1);
};

#endif
