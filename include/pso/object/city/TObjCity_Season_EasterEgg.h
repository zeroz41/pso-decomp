#ifndef PSO_OBJECT_CITY_TOBJCITY_SEASON_EASTEREGG_H
#define PSO_OBJECT_CITY_TOBJCITY_SEASON_EASTEREGG_H

#include "types.h"
#include "pso/object/TUnk_804B5E48.h"

struct TObjCity_Season_EasterEgg : public TUnk_804B5E48 {
    virtual ~TObjCity_Season_EasterEgg();
    virtual void render();
    virtual void run_task();

    u8 unk_B4[0x4];

    s32 m_b8;

    u8 unk_BC[0x4];
};

typedef char TObjCity_Season_EasterEgg_size[sizeof(TObjCity_Season_EasterEgg) == 0xC0 ? 1 : -1];
#endif
