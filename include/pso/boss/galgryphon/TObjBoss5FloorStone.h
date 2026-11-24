#ifndef PSO_BOSS_GALGRYPHON_TOBJBOSS5FLOORSTONE_H
#define PSO_BOSS_GALGRYPHON_TOBJBOSS5FLOORSTONE_H
#include "pso/system/task/TObject.h"
#include "types.h"

struct NJS_TEXLIST;
struct NJS_OBJECT;
struct Vec;
struct DragonAttackParams;

class TObjBoss5FloorStone : public TObject {
public:
    TObjBoss5FloorStone(TObject *parent);
    virtual ~TObjBoss5FloorStone();
    virtual void run_task();
    virtual void render();
public:
    static void *create();
    void trigger_switches_in_range(const Vec *pos, const DragonAttackParams *params);
};

#endif
