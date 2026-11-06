#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERJUNG_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERJUNG_H

#include "types.h"
#include "pso/player/TUnk_804B6C24.h"

struct TObjContainerJung : public TUnk_804B6C24 {
    virtual ~TObjContainerJung();
    virtual void vfunc_80();
    virtual void vfunc_81();
    virtual void vfunc_6(s16 *, s32);
    static u8 *get_model_by_index(s32 arg0);
    static void *create(void *arg0);
    static void release();
    static void load_resources();
};

typedef char TObjContainerJung_size[sizeof(TObjContainerJung) == 0x368 ? 1 : -1];

extern "C" {
u8 *TObjContainerJung__ct(u8 *arg0, s32 arg1, s32 _w2);
s32 TObjContainerJung__sub_8018D3B8(s32);
void *__dt__17TObjContainerJungFv(void *arg0, s16 arg1);
}

#endif
