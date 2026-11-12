#ifndef PSO_UI_WINDOW_TWINDOWLOCKON_H
#define PSO_UI_WINDOW_TWINDOWLOCKON_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

class TObjCollidable;
class TObjChara;
class TItem;

struct TWindowLockOn : public TWindowBase {
    virtual ~TWindowLockOn();
    void request_close();
    virtual void render();
    u8 _pad1C[0x4];
    s16 m_20;
    u8 _pad22[0x2];
    void* m_24;
    u8 unk_28[0x4];
    u32 m_2c;
    f32 m_30;
    f32 m_34;
    f32 m_38;
    f32 m_3c;
    f32 m_40;
    f32 m_44;
    f32 m_48;
    f32 m_4c;
    u32 m_50;
    u8 _pad54[0x8];
    u32 m_5c;
    u16 m_60;
    u8 _pad62[0x2];
    s32 m_64;
    f32 m_68;
    f32 m_6c;
    void (TWindowLockOn::*m_70)();
    s32 get_target_id();
    static f32 get_target_distance();
    void validate_target();
    void refresh_ground_item();
    void update_photon_blast_marker();
    static void *create_for_target(s32 arg0, u16 arg1);
    virtual void run_task();
    void update_for_player_index(s32 arg1);
    void refresh_enemy_statuses();
    static s32 is_lockable_target(TObjCollidable *actor);
    void bind_target(u16 id);
    void update_for_target(TObjCollidable *actor);
    void update_for_other_player(TObjCollidable *player);
    void update_for_item(TItem *item);
    void update_for_enemy(TObjChara *enemy);
};

typedef char TWindowLockOn_size[sizeof(TWindowLockOn) == 0x7C ? 1 : -1];
#endif
