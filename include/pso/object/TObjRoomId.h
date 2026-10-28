#ifndef PSO_OBJECT_TOBJROOMID_H
#define PSO_OBJECT_TOBJROOMID_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjRoomId : public TObjBase {
    virtual ~TObjRoomId();
    void *create(void *);
    virtual void render();
    virtual void run_task();
    void* m_90;
    static void draw_debug_line(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
    u8 unk_94[0x8];
};

typedef char TObjRoomId_size[sizeof(TObjRoomId) == 0x9C ? 1 : -1];
#endif
