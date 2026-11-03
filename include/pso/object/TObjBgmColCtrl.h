#ifndef PSO_OBJECT_TOBJBGMCOLCTRL_H
#define PSO_OBJECT_TOBJBGMCOLCTRL_H

#include "types.h"
#include "pso/TObject.h"

struct TObjBgmColCtrl : public TObject {
    TObjBgmColCtrl(s32 parent);
    virtual ~TObjBgmColCtrl();
    u32 m_1c;
    static void play_lobby_theme_music();
    virtual void render();
    virtual void run_task();
    static void create_controller();
    static u8 is_active();
    static void update_all_zones(s32 arg0);
};

typedef char TObjBgmColCtrl_size[sizeof(TObjBgmColCtrl) == 0x20 ? 1 : -1];
#endif
