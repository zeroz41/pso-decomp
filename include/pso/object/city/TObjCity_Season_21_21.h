#ifndef PSO_OBJECT_CITY_TOBJCITY_SEASON_21_21_H
#define PSO_OBJECT_CITY_TOBJCITY_SEASON_21_21_H

#include "types.h"
#include "pso/object/TUnk_804B5E48.h"

struct TObjCity_Season_21_21 : public TUnk_804B5E48 {
    virtual ~TObjCity_Season_21_21();
    virtual void render();
    virtual void run_task();

    u8 unk_B4[0x4];

    s32 m_b8;
};

typedef char TObjCity_Season_21_21_size[sizeof(TObjCity_Season_21_21) == 0xBC ? 1 : -1];
#endif
