#ifndef PSO_UI_WINDOW_TWINDOWLOCKON_H
#define PSO_UI_WINDOW_TWINDOWLOCKON_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/WindowLayoutRecord.h"

class TObjCollidable;
class TObjChara;
class TItem;

struct TWindowLockOn : public TWindowBase {
    static const char *class_name;
    TWindowLockOn(s32 player, u16 id);
    virtual ~TWindowLockOn();
    virtual void render();
    u16 target_id;  // entity id of the locked target, 0xFFFF for none
    u8 _pad62[0x2];
    s32 frames_left;  // the window closes when this runs out
    f32 scale;
    f32 height_scale;  // scales the window height when it is placed above its target
    void (TWindowLockOn::*refresh)();
    void validate_target();
    void refresh_ground_item();
    void update_photon_blast_marker();
    static TWindowLockOn *create_for_target(s32 player, u16 id);
    virtual void run_task();
    void refresh_enemy_statuses();
    static s32 is_lockable_target(TObjCollidable *actor);
    void bind_target(u16 id);
    void update_for_target(TObjCollidable *actor);
    void update_for_other_player(TObjCollidable *player);
    void update_for_item(TItem *item);
    void update_for_enemy(TObjChara *enemy);
};

LAYOUT_ASSERT(TWindowLockOn_size, sizeof(TWindowLockOn) == 0x7C);

// Other player: portrait sprite, name text.
struct LockOnPlayerLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    TextLayoutRecord rec_1;
};

// Ground item: item row, grade stars.
struct LockOnItemLayout {
    u32 cols;
    u32 rows;
    TypeLayoutRecord rec_0;
    PointLayoutRecord rec_1;
};

// Enemy: name, label, type, four status icons, two gauges.
struct LockOnEnemyLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    TextLayoutRecord rec_2;
    SpritePartLayoutRecord rec_3;
    SpritePartLayoutRecord rec_4;
    SpritePartLayoutRecord rec_5;
    SpritePartLayoutRecord rec_6;
    LayoutEntryCopyRecord rec_7;
    LayoutEntryCopyRecord rec_8;
};

#endif
