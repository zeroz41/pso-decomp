#ifndef PSO_OBJECT_TOBJLIGHT_H
#define PSO_OBJECT_TOBJLIGHT_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjLight : public TObjBase {
    virtual ~TObjLight();
    void *init_from_source(void *, int, int);
    u32 m_90;
    u32 m_94;
    u8 _pad98[0x4];
    u32 m_9c;
    u32 m_a0;
    u32 m_a4;
    u8 _padA8[0x14];
    void* m_bc;
    u8 _padC0[0xC];
    void* m_cc;
    u8 _padD0[0x8];
    void* m_d8;
    virtual void render();
    virtual void run_task();
    void*init_light(int a1);
    void unregister_and_free();
    static u32 alloc_light_slot();
    void *init_map_light(int _w1);
    static void init_directional_light();
    void *dt(s16 arg1);
    void *init(int _w1);
    static void free_shared_data();
    void *dt2(s16 arg1);
    void *init_object();
    static void apply_distant_light();
    void set_light(void *arg1, f32 farg0);
    static void find_light_params(f32 *dir, f32 *color, u32 id);
    static void init_light_tables();
    void bswap_data();
    void *destroy(s16 arg1);
    static void assert_light_id(s32 arg0);
    u8 unk_DC[0x8];
    f32 m_e4;
    u8 unk_E8[0x4];
    f32 m_ec;
    u8 unk_F0[0x4];
    f32 m_f4;
    u8 unk_F8[0x4];
    f32 m_fc;
    u8 *construct_actor_light(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 farg0, f32 farg1, f32 farg2, s32 arg_sp0);
};

typedef char TObjLight_size[sizeof(TObjLight) == 0x100 ? 1 : -1];

extern "C" {
u8 *TObjLight__create(u8 *arg0);
u8 *TObjLight__ct(TObjLight *arg0, s32 arg1, u8 *arg2);
void *__dt__9TObjLightFv(void *arg0, s16 arg1);
}

#endif
