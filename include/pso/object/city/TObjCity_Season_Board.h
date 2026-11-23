#ifndef PSO_OBJECT_CITY_TOBJCITY_SEASON_BOARD_H
#define PSO_OBJECT_CITY_TOBJCITY_SEASON_BOARD_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjCity_Season_Board : public TObjBase {
    TObjCity_Season_Board(TObject *parent, void *set_data);
    virtual ~TObjCity_Season_Board();
    virtual void render();
    virtual void run_task();

    // UV offset of the board strip: run_task steps it by 2 and wraps at 0x100,
    // render hands it to StripBufferPair::scroll_uvs.
    s32 uv_scroll;
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjCity_Season_Board_size, sizeof(TObjCity_Season_Board) == 0x94);
#endif
