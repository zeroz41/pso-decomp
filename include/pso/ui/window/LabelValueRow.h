#ifndef PSO_UI_WINDOW_LABELVALUEROW_H
#define PSO_UI_WINDOW_LABELVALUEROW_H

#include "types.h"
#include "pso/unk/TWindowLayoutRect.h"

struct WindowDrawContext;

// A menu information line (case 9 of init_window_layout_entries): a label, ":" unless flag 0x10
// is set, and a value string, both owned copies. TWindowMenuInfomation finds lines by id.
// Flag 1: marked, 4: filled, 0x10: centred label without value.
// inferred: label/value row (class name from what render draws).
class LabelValueRow : public TWindowLayoutRect {
public:
    s32 id;
    char *label;
    char *value;
    s32 color;

    LabelValueRow(u8 *rec, s32 client);
    virtual ~LabelValueRow();
    virtual void update();
    virtual void render(WindowDrawContext *context);
    void set_string(void *string);
    void set_text(void *label_text, void *string, s32 id);
    void set_text(uaddr label_text, s32 id);
    s32 get_entry_id();
    int is_flag_4_set();
};

LAYOUT_ASSERT(LabelValueRow_size, sizeof(LabelValueRow) == 0x28);

extern "C" {
// LabelValueRow::LabelValueRow(u8 *, s32). init_window_layout_entries cannot use new: calc_bar_width
// stays pure (slot 0 of the vtable), so the class is abstract.
void *__ct__13LabelValueRowFPUcl(void *p, u8 *rec, s32 client);
}

#endif
