#ifndef PSO_OBJECT_CITY_TOBJCITY_SEASON_XMASTREE_H
#define PSO_OBJECT_CITY_TOBJCITY_SEASON_XMASTREE_H

#include "types.h"
#include "pso/object/TUnk_804B5E48.h"

struct TObjCity_Season_XmasTree : public TUnk_804B5E48 {
    virtual ~TObjCity_Season_XmasTree();
    virtual void render();
    virtual void run_task();

    u8 unk_B4[0x4];
    void *dt(s16 arg1);
};

typedef char TObjCity_Season_XmasTree_size[sizeof(TObjCity_Season_XmasTree) == 0xB8 ? 1 : -1];
#endif
