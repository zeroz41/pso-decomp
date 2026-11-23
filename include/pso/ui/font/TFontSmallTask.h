#ifndef PSO_UI_FONT_TFONTSMALLTASK_H
#define PSO_UI_FONT_TFONTSMALLTASK_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TFontSmallTask : public TObject {
public:
    TFontSmallTask(const f32 *pos, u32 color, s32 life, s32 delay, const char *str, s32 view);
    virtual ~TFontSmallTask();
    virtual void render();
    virtual void run_task();
    // Text scale factor for the current camera view scale.
    f32 calc_font_scale();
    f32 position[3];
    f32 offset_x, offset_y;
    f32 text_width;
    char text[16];
    u32 rgb;
    s32 age, lifetime, delay;
    s16 active;
    u16 view;
};

extern "C" {
void create_boss_health_font(s32 pos, s32 color, s32 life, void *label, void *value);
s32 create_font_small_task(s32 pos, s32 color, s32 life, s32 delay, s32 *str, s32 value, s32 view);
s32 create_font_small_task_default_color(s32 pos, s32 color, s32 life, s32 delay, s32 *str, s32 value);
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
