#ifndef PSO_MISC_TSCENESORA_H
#define PSO_MISC_TSCENESORA_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TSceneSora : public TObjBase {
    virtual ~TSceneSora();
    u32 m_90;
    u32 m_94;
    u32 m_98;
    virtual void render();
    virtual void run_task();
    static void create_instance();
    static void load_sky_resources();
    u8 unk_9C[0x4];
    f32 m_a0;
    static void update(s32 _w0);
    s32 get_state();
    static void set_scene_flag(int a0);
    static void copy_reflection_vec(u8 *arg0);
};

typedef char TSceneSora_size[sizeof(TSceneSora) == 0xA4 ? 1 : -1];
#endif
