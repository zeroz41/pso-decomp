#ifndef PSO_UI_FONT_TFONTSMALLTASK_H
#define PSO_UI_FONT_TFONTSMALLTASK_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx.h>

class TFontSmallTask : public TObject {
public:
    TFontSmallTask(Vec *pos, u32 color, s32 life, s32 delay, const char *str, u16 view);
    virtual ~TFontSmallTask();
    virtual void render();
    virtual void run_task();
    // Text scale factor for the current camera view scale.
    f32 calc_font_scale();

    Vec position;
    f32 offset_x, offset_y;
    f32 text_width;
    char text[16];
    u32 rgb;
    s32 age, lifetime, delay;
    s16 active;
    u16 view;
};

// The screen-space corner/UV box build_small_font_glyph_quad fills for one glyph.
struct GlyphQuad {
    f32 x, y, right, bottom, u, v, u2, v2;
};

// One .ctors reverse-walk entry: a labelled function the lobby area tear-down calls.
struct LobbyFrameEntry {
    u32 id;
    void (*fn)(void);
};

// One forward-walk load callback entry: a function and its threshold id.
struct LoadFrameEntry {
    void (*fn)(void);
    u32 id;
};

extern "C" {
void build_small_font_glyph_quad(u8 c, GlyphQuad *q);
void create_boss_health_font(s32 pos, s32 color, s32 life, void *label, void *value);
s32 create_font_small_task(Vec *pos, s32 color, s32 life, s32 delay, s32 *str, s32 value, u16 view);
s32 create_font_small_task_default_color(Vec *pos, s32 color, s32 life, s32 delay, s32 *str, s32 value);
void update_card_window_flags(saddr client_id, s32 card_status_bits);
s32 get_player_status_color(void *player);
}

// The room leader's level and section id. The section id picks the item drop tables, the shop stock and the Tekker's
// model; the game join packet sets it online, find_leader_section_id reads it from the leader's player offline.
struct LeaderSelection {
    s32 level;
    s32 section_id;

    LeaderSelection();
    void set_section_id(s32 id);
    s32 get_section_id();
    void find_leader_section_id(s32 client_id);
};

__declspec(section ".data") extern LeaderSelection leader_selection;

#endif
