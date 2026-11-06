#ifndef PSO_OBJECT_TOBJSINBOARD_H
#define PSO_OBJECT_TOBJSINBOARD_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjSinBoard : public TObjBase {
    TObjSinBoard(TObject *parent, void *set_data);
    virtual ~TObjSinBoard();
    virtual void render();
    virtual void run_task();
};

typedef char TObjSinBoard_size[sizeof(TObjSinBoard) == 0x90 ? 1 : -1];

extern "C" {
void *TObjSinBoard__create(void *set_data);
}

#endif
