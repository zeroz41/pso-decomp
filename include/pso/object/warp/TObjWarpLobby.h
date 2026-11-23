#ifndef PSO_OBJECT_WARP_TOBJWARPLOBBY_H
#define PSO_OBJECT_WARP_TOBJWARPLOBBY_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct AnimationMotion;

struct TObjWarpLobby : public TObjAreaWarp {
    static const char *class_name;
    TObjWarpLobby(TObject *parent, void *set_data);
    virtual ~TObjWarpLobby();
    virtual void debug_print_area_num();
    void run_task();
    static void release_static();
    static void load_resources();
    void open_lobby_menu();
    void render();
    f32 beam_phase;
    f32 beam_frame;
    s32 show_beam;
    s32 pad_D0;
    s32 pad_D4;
    AnimationMotion *beam_motion;
    s32 pad_DC;
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjWarpLobby_size, sizeof(TObjWarpLobby) == 0xE0);
#endif
