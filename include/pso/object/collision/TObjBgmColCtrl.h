#ifndef PSO_OBJECT_COLLISION_TOBJBGMCOLCTRL_H
#define PSO_OBJECT_COLLISION_TOBJBGMCOLCTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

// A row of the Pioneer 2 music zone tables: a TObjBgmCol at pos with trigger radius radius playing
// area_music_filename_table[category] (4 is the lobby theme).
struct BgmZoneRow {
    Vec pos;
    f32 radius;
    s32 category;
};

struct TObjBgmColCtrl : public TObject {
    TObjBgmColCtrl(TObject *parent);
    virtual ~TObjBgmColCtrl();
    u32 start_delay; // frames run_task waits before it picks the music (3)
    static void play_lobby_theme_music();
    virtual void render();
    virtual void run_task();
    static void create_controller();
    static s32 is_active();
    static void update_all_zones(saddr filename);
};

LAYOUT_ASSERT(TObjBgmColCtrl_size, sizeof(TObjBgmColCtrl) == 0x20);

int get_quest_bgm_issued_flag(void);
#endif
