#ifndef PSO_OBJECT_ENDING_TOBJONLINEENDINGHEXLINE_H
#define PSO_OBJECT_ENDING_TOBJONLINEENDINGHEXLINE_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TObjOnlineEndingHexLine : public TObject {
public:
    virtual ~TObjOnlineEndingHexLine();
    virtual void render();
    virtual void run_task();
public:
    void step_line();
    static void *create(void *arg0, void *arg1);
};

#endif
