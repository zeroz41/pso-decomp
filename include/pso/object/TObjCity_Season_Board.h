#ifndef PSO_OBJECT_TOBJCITY_SEASON_BOARD_H
#define PSO_OBJECT_TOBJCITY_SEASON_BOARD_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjCity_Season_Board : public TObjBase {
    virtual ~TObjCity_Season_Board();
    virtual void render();
    virtual void run_task();

    u8 unk_90[0x4];
    void *dt(s16 arg1);
};

typedef char TObjCity_Season_Board_size[sizeof(TObjCity_Season_Board) == 0x94 ? 1 : -1];
#endif
