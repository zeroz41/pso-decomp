#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERJUNGEX_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERJUNGEX_H

#include "types.h"
#include "pso/player/TUnk_804B6C24.h"

struct TObjContainerJungEx : public TUnk_804B6C24 {
    virtual ~TObjContainerJungEx();
    virtual void vfunc_80();
    virtual void vfunc_81();
    virtual void vfunc_6(s16 *, s32);
    static void *create(void *arg0);
    static u8 *get_model(s32 arg0);
    static void free_data();
    static void load_resource_instance();
};

typedef char TObjContainerJungEx_size[sizeof(TObjContainerJungEx) == 0x368 ? 1 : -1];

extern "C" {
u8 *TObjContainerJungEx__ct(u8 *arg0, s32 arg1, s32 _w2);
void *__dt__19TObjContainerJungExFv(void *arg0, s16 arg1);
}

#endif
