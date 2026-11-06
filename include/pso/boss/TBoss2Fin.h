#ifndef PSO_BOSS_TBOSS2FIN_H
#define PSO_BOSS_TBOSS2FIN_H
#include "pso/object/TObjEZRopeBase.h"
#include "types.h"

class TBoss2Fin : public TObjEZRopeBase {
public:
    virtual ~TBoss2Fin();
    virtual void run_task();
    virtual void render();
public:
    void init_link_points();
    static void init_effect_table();
};

#endif
