#ifndef PSO_BOSS_TOBJBOSS7TUNNELCOL_H
#define PSO_BOSS_TOBJBOSS7TUNNELCOL_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjBoss7TunnelCol : public TObjCollidable {
    virtual ~TObjBoss7TunnelCol();
    void* m_ac;
    virtual void render();
    virtual void run_task();
    s32 is_in_camera_range();
    u8 unk_B0[0x28];
};

typedef char TObjBoss7TunnelCol_size[sizeof(TObjBoss7TunnelCol) == 0xD8 ? 1 : -1];

extern "C" {
void *TObjBoss7TunnelCol__ct(void *arg0, TObject *parent);
void *__dt__18TObjBoss7TunnelColFv(void *arg0, s16 arg1);
}

#endif
