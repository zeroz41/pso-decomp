#ifndef PSO_UI_WINDOW_TWINDOWHELPITEM_8025A12C_H
#define PSO_UI_WINDOW_TWINDOWHELPITEM_8025A12C_H

#include "types.h"
#include "pso/unk/TWindowLayoutEntry.h"
#include "pso/unk/WindowLayoutRecord.h"

// A stat line of the help item window: its label, ":", the value and, once a compare value is
// set, an arrow and the value the item on show would give (case 11 of init_window_layout_entries).
// Flag 4: value set, 8: compare value set, 0x10: compare enabled, 0x20: draw as a percentage.
// Inferred name: help item stat compare row.
class TUnk_804CF9F8 : public TWindowLayoutEntry {
public:
    f32 pos[2];
    s32 value_color;  // -1, or the colour of the last change while flash_timer runs
    s32 flash_timer;
    char *label;
    s32 value;
    s32 compare_value;

    TUnk_804CF9F8(PointLayoutRecord *rec, s32 client);
    virtual ~TUnk_804CF9F8();
    virtual void update();
    virtual void render(WindowDrawContext *context);
    void update_visible_flags();
    void draw_number_value(f32 *pos, s32 value, s32 color, s32 percent);
    void set_flag_0x10(s32 enable);
    void set_compare_value(s32 value);
    void set_compare_color(s32 count);
    void set_value(s32 value);
    void set_help_text(uaddr str);
    int is_flag20_set();
    void set_flag0_bit20();
    s32 get_value();
};

LAYOUT_ASSERT(TUnk_804CF9F8_size, sizeof(TUnk_804CF9F8) == 0x24);

extern "C" {
// TUnk_804CF9F8::TUnk_804CF9F8(PointLayoutRecord *, s32), called by init_window_layout_entries.
void *__ct__13TUnk_804CF9F8FP17PointLayoutRecordl(void *p, PointLayoutRecord *rec, s32 client);
}

#endif
