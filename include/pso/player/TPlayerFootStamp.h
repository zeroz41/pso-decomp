#ifndef PSO_PLAYER_TPLAYERFOOTSTAMP_H
#define PSO_PLAYER_TPLAYERFOOTSTAMP_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TPlayerFootStamp : public TObject {
public:
    virtual ~TPlayerFootStamp();
    void sub_802B0204(s32);
public:
    static void *create(void *arg0, void *arg1);
    static void free_instance();
    void render();
    void run_task();
};

#endif
