#ifndef PSO_OBJECT_COLLISION_TOBJBGMCOLCTRL_H
#define PSO_OBJECT_COLLISION_TOBJBGMCOLCTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TObjBgmColCtrl : public TObject {
    TObjBgmColCtrl(saddr parent);
    virtual ~TObjBgmColCtrl();
    u32 m_1c;
    static void play_lobby_theme_music();
    virtual void render();
    virtual void run_task();
    static void create_controller();
    static s32 is_active();
    static void update_all_zones(saddr arg0);
};

LAYOUT_ASSERT(TObjBgmColCtrl_size, sizeof(TObjBgmColCtrl) == 0x20);
#endif
