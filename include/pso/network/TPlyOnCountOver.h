#ifndef PSO_NETWORK_TPLYONCOUNTOVER_H
#define PSO_NETWORK_TPLYONCOUNTOVER_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TPlyOnCountOver : public TObject {
public:
    virtual ~TPlyOnCountOver();
    virtual void run_task();
public:
    static void *create(void *arg0, void *arg1, void *arg2);
};

#endif
