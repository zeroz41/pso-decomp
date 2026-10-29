#ifndef PSO_MISC_TOFENCEANCIENT04_H
#define PSO_MISC_TOFENCEANCIENT04_H

#include "types.h"
#include "pso/player/TUnk_804B1B80.h"

struct TOFenceAncient04 : public TUnk_804B1B80 {
    virtual ~TOFenceAncient04();
    virtual void open();
    virtual void close();
    virtual void update_demo();
    static void *create(void *arg0);
    static void destroy();
    static void load_resources();
};

typedef char TOFenceAncient04_size[sizeof(TOFenceAncient04) == 0xD8 ? 1 : -1];

extern "C" {
u8 *TOFenceAncient04__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__16TOFenceAncient04Fv(void *arg0, s16 arg1);
}

#endif
