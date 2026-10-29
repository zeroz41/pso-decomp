#ifndef PSO_MISC_TORAINBOWCAVE01_H
#define PSO_MISC_TORAINBOWCAVE01_H

#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

class TORainbowCave01 : public TUnk_804AFBF8 {
public:
    TORainbowCave01(TObject *parent, void *set_data);
    virtual ~TORainbowCave01();
    virtual void run_task();
    virtual void render();
    s32 is_player_in_range(f32 farg0);
    void init_light_params(int _w1, f32 _w2, f32 _w3);
    static void *create(void *arg0);
    static void free_static_data();
    static void load_resource_instance();
    f32 m_c8;
    f32 m_cc;
    f32 m_d0;
    Vec m_d4;
};

typedef char TORainbowCave01_size[sizeof(TORainbowCave01) == 0xE0 ? 1 : -1];
#endif
