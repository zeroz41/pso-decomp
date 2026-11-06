#ifndef PSO_OBJECT_JUNGLE_TOROCKJUNGLES01_H
#define PSO_OBJECT_JUNGLE_TOROCKJUNGLES01_H

#include "types.h"
#include "pso/object/cave/TORockCaveBrakable.h"

struct TORockJungleS01 : public TORockCaveBrakable {
    virtual ~TORockJungleS01();
    virtual void vfunc_16();
    virtual void vfunc_18();
    u32 m_bc;
    static void *create(void *arg0);
    static u8 *get_model(s32 arg0);
    static void free_globals();
    static void load_resources();
};

typedef char TORockJungleS01_size[sizeof(TORockJungleS01) == 0xC0 ? 1 : -1];

extern "C" {
u8 *TORockJungleS01__ct(TORockJungleS01 *arg0, s32 arg1);
void *__dt__15TORockJungleS01Fv(void *arg0, s16 arg1);
s32 get_jungle_rock_texture_resource(s32 a);
}

#endif
