#ifndef PSO_OBJECT_WARP_TOBJWARPLOBBY_H
#define PSO_OBJECT_WARP_TOBJWARPLOBBY_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjWarpLobby : public TObjAreaWarp {
    TObjWarpLobby(TObject *parent, void *set_data);
    virtual ~TObjWarpLobby();
    virtual void debug_print_area_num();
    void run_task();
    static void release_static();
    void open_lobby_menu();
    void render();
    u8 unk_C4[0x4];
    f32 m_c8;
    u8 unk_CC[0x14];
};

typedef char TObjWarpLobby_size[sizeof(TObjWarpLobby) == 0xE0 ? 1 : -1];
#endif
