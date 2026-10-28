#ifndef PSO_MISC_TOVS2WALL01_H
#define PSO_MISC_TOVS2WALL01_H

#include "types.h"
#include "pso/player/TObjChara.h"

struct TOVS2Wall01 : public TObjChara {
    virtual ~TOVS2Wall01();
    virtual void vfunc_6(s16 *, s32);
    u8 unk_334[0x4];
    f32 m_338;
    u32 m_33c;
    void* m_340;
    u8 _pad344[0x10];
    u32 m_354;
    u8 _pad358[0x4];
    u32 m_35c;
    void spawn_debris(s32 arg1);
    void release();
    int interact_player_neg1();
    virtual void run_task();
    virtual void render();
    void *create();
    static void release_model();
    static void load_resources();
    void *destroy(s16 arg1);
    void byteswap_hit_packet();
    void update_and_send();
    void*init();
    u8 *init_wreck_object(s32 arg1, s32 arg2);
    void save_and_send_state(u16 arg1);
};

typedef char TOVS2Wall01_size[sizeof(TOVS2Wall01) == 0x360 ? 1 : -1];
#endif
