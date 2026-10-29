#ifndef PSO_MISC_TOFENCEANCIENT02_H
#define PSO_MISC_TOFENCEANCIENT02_H

#include "types.h"
#include "pso/player/TUnk_804B1B80.h"

struct TOFenceAncient02 : public TUnk_804B1B80 {
    virtual ~TOFenceAncient02();
    virtual void open();
    virtual void close();
    virtual void update_demo();
    static void *create(void *arg0);
    static void unload_resources();
    static void load_resources();
};

typedef char TOFenceAncient02_size[sizeof(TOFenceAncient02) == 0xD8 ? 1 : -1];

extern "C" {
u8 *TOFenceAncient02__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__16TOFenceAncient02Fv(void *arg0, s16 arg1);
}

#endif
