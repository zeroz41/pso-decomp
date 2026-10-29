#include "types.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjDFDemo5.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/misc/TNowLoading.h"

struct V_8004F904 { f32 x, y, z; };

struct O_8004F904 { u8 pad[0xF0]; V_8004F904 arr[2]; };

extern "C" {
void *create_particle_emitter(void *pos, s32 id);
void TObjDFDemo5::update_particle_emitters() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    u32 *particle_emitter;
    s32 i;
    u32 temp_r3;
    u32 temp_r3_2;
    u32 temp_r3_3;
    u32 temp_r3_4;
    u32 temp_r3_5;
    u32 temp_r3_6;
    u32 temp_r3_7;
    u32 temp_r3_8;
    u8 *temp_r4;
    temp_r0 = this->m_e4;
    if (temp_r0 > 0x104) {
        temp_r3 = *(u32 *)((s8 *)arg0 + 0x90);
        if (temp_r3 != 0) {
            TParticleCtrl::release((void *)temp_r3);
            *(u32 *)((s8 *)arg0 + 0x90) = 0U;
        }
    } else if ((temp_r0 >= 0xA0) && ((u32) *(u32 *)((s8 *)arg0 + 0x90) == 0)) {
        *(u32 *)((s8 *)arg0 + 0x90) = (u32)create_particle_emitter(((u8 *)&this->m_d4), 0x178);
        temp_r3_2 = *(u32 *)((s8 *)arg0 + 0x90);
        if (temp_r3_2 != 0) {
            ((TParticleCtrl *)temp_r3_2)->set_flags(0x40U);
        }
    }
    if (((s32) this->m_e4 >= 0x104) && ((u32) this->m_94 == 0)) {
        this->m_94 = (u32)create_particle_emitter(((u8 *)&this->m_d4), 0x179);
        temp_r3_3 = this->m_94;
        if (temp_r3_3 != 0) {
            ((TParticleCtrl *)temp_r3_3)->set_flags(0x40U);
        }
    }
    if ((s32) this->m_e4 >= 0xB4) {
        temp_r3_4 = *(u32 *)((s8 *)arg0 + 0x98);
        if (temp_r3_4 == 0) {
            *(u32 *)((s8 *)arg0 + 0x98) = (u32)create_particle_emitter(((u8 *)&this->m_10c), 0x146);
            temp_r3_5 = *(u32 *)((s8 *)arg0 + 0x98);
            if (temp_r3_5 != 0) {
                ((TParticleCtrl *)temp_r3_5)->set_flags(0x40U);
            }
        } else {
            ((TParticleCtrl *)temp_r3_4)->set_position((u8 *)&this->m_10c);
        }
    }
    particle_emitter = (u32 *)(arg0 + 0x9C);
    for (i = 0; i < 2; i++) {
        if ((s32) this->m_e4 >= 0x2D) {
            temp_r3_6 = *particle_emitter;
            if (temp_r3_6 != 0) {
                TParticleCtrl::release((void *)temp_r3_6);
                *particle_emitter = 0;
            }
        } else {
            temp_r3_7 = *particle_emitter;
            temp_r4 = (u8 *)&((O_8004F904 *)arg0)->arr[i];
            if (temp_r3_7 == 0) {
                *particle_emitter = (u32)create_particle_emitter((temp_r4), 0x147);
                temp_r3_8 = *particle_emitter;
                if (temp_r3_8 != 0) {
                    ((TParticleCtrl *)temp_r3_8)->set_flags(0x40U);
                }
            } else {
                ((TParticleCtrl *)temp_r3_7)->set_position(temp_r4);
            }
        }
        particle_emitter = (u32 *)(arg0 + 0xA0);
    }
}

}
