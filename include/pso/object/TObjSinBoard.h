#ifndef PSO_OBJECT_TOBJSINBOARD_H
#define PSO_OBJECT_TOBJSINBOARD_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjSinBoard : public TObjBase {
    virtual ~TObjSinBoard();
    virtual void render();
    virtual void run_task();
};

typedef char TObjSinBoard_size[sizeof(TObjSinBoard) == 0x90 ? 1 : -1];

extern "C" {
void *TObjSinBoard__create(void *arg0);
u8 *TObjSinBoard__ct(u8 *arg0, s32 parent, s32 arg2);
void *__dt__12TObjSinBoardFv(void *arg0, s16 arg1);
}

#endif
