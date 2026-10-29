#ifndef PSO_OBJECT_TOBJPARTICLELOBBY_H
#define PSO_OBJECT_TOBJPARTICLELOBBY_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

struct TObjParticleLobby : public TObjMapObject {
    virtual ~TObjParticleLobby();
    u32 m_c8;
    u8 _padCC[0x4];
    u32 m_d0;
    u32 m_d4;
    virtual void render();
    virtual void run_task();
    void setup_emitter();
    static void *create(void *arg0);
};

typedef char TObjParticleLobby_size[sizeof(TObjParticleLobby) == 0xD8 ? 1 : -1];

extern "C" {
u8 *TObjParticleLobby__ct(u8 *arg0, s32 arg1, s32 arg2);
void TObjParticleLobby__sub_80369698(void);
void TObjParticleLobby__sub_80369A60(void);
void TObjParticleLobby__sub_80369A64(void);
void *__dt__17TObjParticleLobbyFv(void *arg0, s16 arg1);
s32 get_event_theme_index__17TObjParticleLobbyFv(void);
}

#endif
