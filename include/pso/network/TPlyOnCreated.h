#ifndef PSO_NETWORK_TPLYONCREATED_H
#define PSO_NETWORK_TPLYONCREATED_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TPlyOnCreated : public TObject {
public:
    virtual void run_task();
    virtual ~TPlyOnCreated();
public:
    static void *create(void *arg0, void *arg1);
};

#endif
