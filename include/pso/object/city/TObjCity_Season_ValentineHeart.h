#ifndef PSO_OBJECT_CITY_TOBJCITY_SEASON_VALENTINEHEART_H
#define PSO_OBJECT_CITY_TOBJCITY_SEASON_VALENTINEHEART_H

#include "types.h"
#include "pso/object/TUnk_804B5E48.h"

struct TObjCity_Season_ValentineHeart : public TUnk_804B5E48 {
    virtual ~TObjCity_Season_ValentineHeart();
    virtual void render();
    virtual void run_task();

    u8 unk_B4[0x4];
};

typedef char TObjCity_Season_ValentineHeart_size[sizeof(TObjCity_Season_ValentineHeart) == 0xB8 ? 1 : -1];
#endif
