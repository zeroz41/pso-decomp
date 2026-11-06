#ifndef PSO_MAP_TSETMANAGER_H
#define PSO_MAP_TSETMANAGER_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TSetManager : public TObject {
public:
    virtual ~TSetManager();
    virtual void run_task();
public:
    static void create();
    void update_decoration_spawning();
    void apply_floor_set_rows();
};

extern "C" {
void *TSetManager__ct(void *set_manager, void *parent);
}


extern "C" {
void TSetManager__sub_8020D7D4(void);
}

#endif
