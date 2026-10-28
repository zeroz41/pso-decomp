#ifndef PSO_OBJECT_TOBJLAZERFENCENORM_H
#define PSO_OBJECT_TOBJLAZERFENCENORM_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjLazerFenceNorm : public TObjCollidable {
    virtual ~TObjLazerFenceNorm();
    void update_closed();
    void draw_animated_beam();
    u32 m_ac;
    u16 m_b0;
    u8 _padB2[0x2];
    u32 m_b4;
    virtual void run_task();
    static void free_resources();
    void draw_model();
    virtual void render();
    void reset_by_door();
    u8 unk_B8[0x4];
    void * m_bc;
    u8 unk_C0[0x4];
    s32 m_c4;
    u8 unk_C8[0x10];
    void select_models();
};

typedef char TObjLazerFenceNorm_size[sizeof(TObjLazerFenceNorm) == 0xD8 ? 1 : -1];

extern "C" {
void *TObjLazerFenceNorm__create(void *arg0);
u8 *TObjLazerFenceNorm__ct(TObjLazerFenceNorm *arg0, s32 arg1, s32 arg2);
void *__dt__18TObjLazerFenceNormFv(void *arg0, s16 arg1);
}

#endif
