#ifndef PSO_MISC_TOFENCEANCIENT03_H
#define PSO_MISC_TOFENCEANCIENT03_H

#include "types.h"
#include "pso/player/TUnk_804B1B80.h"

struct TOFenceAncient03 : public TUnk_804B1B80 {
    virtual ~TOFenceAncient03();
    virtual void open();
    virtual void close();
    virtual void update_demo();
    static void *create(void *arg0);
    static void unload_resources();
    static void load_resources();
};

typedef char TOFenceAncient03_size[sizeof(TOFenceAncient03) == 0xD8 ? 1 : -1];

extern "C" {
u8 *TOFenceAncient03__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__16TOFenceAncient03Fv(void *arg0, s16 arg1);
}

#endif
