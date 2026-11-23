#ifndef PSO_UI_FONT_TFONTSMALLTASK_H
#define PSO_UI_FONT_TFONTSMALLTASK_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx.h>

class TFontSmallTask : public TObject {
public:
    TFontSmallTask(Vec *pos, u32 color, s32 life, s32 delay, const char *text, u16 view);
    virtual ~TFontSmallTask();
    virtual void render();
    virtual void run_task();
    f32 calc_small_font_scale();

    Vec position;
    f32 offset_x, offset_y;
    f32 text_width;
    char text[16];
    u32 rgb;
    s32 age, lifetime, delay;
    s16 active;
    u16 view;
};

extern "C" {
void TBoss3Volopt__sub_800FD344(s32 arg0, s32 arg1, s32 arg2, void *str, void *arg4);
s32 create_font_small_task(Vec *pos, s32 arg1, s32 arg2, s32 arg3, s32 *str, s32 arg5, u16 view);
s32 create_font_small_task_default_color(Vec *pos, s32 arg1, s32 arg2, s32 arg3, s32 *str, s32 arg5);
void fn_800FCCC8(saddr client_id, s32 card_status_bits);
s32 fn_800FCCF4(void *p);
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
