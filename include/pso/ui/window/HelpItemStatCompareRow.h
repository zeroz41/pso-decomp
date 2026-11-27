#ifndef PSO_UI_WINDOW_HELPITEMSTATCOMPAREROW_H
#define PSO_UI_WINDOW_HELPITEMSTATCOMPAREROW_H

#include "types.h"
#include "pso/ui/window/TWindowLayoutEntry.h"
#include "pso/ui/window/WindowLayoutRecord.h"

// A stat line of the help item window: its label, ":", the value and, once a compare value is
// set, an arrow and the value the item on show would give (case 11 of init_window_layout_entries).
// Flag 4: value set, 8: compare value set, 0x10: compare enabled, 0x20: draw as a percentage.
// Help item stat compare row (class name from the window it serves).
class HelpItemStatCompareRow : public TWindowLayoutEntry {
public:
    f32 pos[2];
    s32 color;  // -1, or the colour of the last change while highlight_timer runs
    s32 highlight_timer;
    char *label;
    s32 value;
    s32 compare_value;

    HelpItemStatCompareRow(PointLayoutRecord *rec, s32 client);
    virtual ~HelpItemStatCompareRow();
    virtual void update();
    virtual void render(WindowDrawContext *context);
    void update_visible_flags();
    void draw_number_value(f32 *pos, s32 value, s32 color, s32 percent);
    void set_compare_enabled(s32 enable);
    void set_compare_value(s32 value);
    void set_compare_color(s32 count);
    void set_value(s32 value);
    void set_help_text(uaddr str);
    int is_flag20_set();
    void set_flag0_bit20();
    s32 get_value();
};

LAYOUT_ASSERT(HelpItemStatCompareRow_size, sizeof(HelpItemStatCompareRow) == 0x24);

extern "C" {
// HelpItemStatCompareRow::HelpItemStatCompareRow(PointLayoutRecord *, s32). init_window_layout_entries cannot use new: calc_bar_width
// stays pure (slot 0 of the vtable), so the class is abstract.
void *__ct__22HelpItemStatCompareRowFP17PointLayoutRecordl(void *p, PointLayoutRecord *rec, s32 client);
}

#endif
