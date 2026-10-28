#ifndef PSO_MISC_TENEPARTICLECTRL_H
#define PSO_MISC_TENEPARTICLECTRL_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TEneParticleCtrl : public TObjCollidable {
    virtual ~TEneParticleCtrl();
    u16 m_ac;
    u8 _padAE[0x2];
    u32 m_b0;
    void* m_b4;
    u8 _padB8[0x8];
    u32 m_c0;
    void set_param();
    void free_particle_ctrl();
    void*get_field_38_ptr();
};

typedef char TEneParticleCtrl_size[sizeof(TEneParticleCtrl) == 0xC4 ? 1 : -1];

extern "C" {
u8 *TEneParticleCtrl__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__16TEneParticleCtrlFv(void *arg0, s16 arg1);
}

#endif
