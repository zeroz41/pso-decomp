#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/system/NinjaTypes.h"


void TAdSelectCurGC::reset_entries() {
    s32 i;
    selected_index = 0;
    entry_count = 0;
    confirmation = 0;
    frame = -1;
    pending_command = 0;
    for (i = 0; i < 16; i++) {
        entry_alpha[i] = 0;
    }
}

static const f32 cursor_end_cap_width = 16.0f;
static const f32 cursor_end_caps_width = 32.0f;

void TAdSelectCurGC::append_entry(const void *position) {
    if (entry_count < 16) {
        copy_vec2(&entry_positions[entry_count], const_cast<void *>(position));
        quads[entry_count].x0 = cursor_end_cap_width + entry_positions[entry_count].x;
        quads[entry_count].y0 = entry_positions[entry_count].y;
        quads[entry_count].x1 = quads[entry_count].x0 + (cursor_size.x - cursor_end_caps_width);
        quads[entry_count].y1 = quads[entry_count].y0 + cursor_size.y;
        (quads + 16)[entry_count].x0 = entry_positions[entry_count].x;
        (quads + 16)[entry_count].y0 = entry_positions[entry_count].y;
        (quads + 16)[entry_count].x1 = cursor_end_cap_width + (quads + 16)[entry_count].x0;
        (quads + 16)[entry_count].y1 = (quads + 16)[entry_count].y0 + cursor_size.y;
        (quads + 32)[entry_count].x0 = entry_positions[entry_count].x + (cursor_size.x - cursor_end_cap_width);
        (quads + 32)[entry_count].y0 = entry_positions[entry_count].y;
        (quads + 32)[entry_count].x1 = cursor_end_cap_width + (quads + 32)[entry_count].x0;
        (quads + 32)[entry_count].y1 = (quads + 32)[entry_count].y0 + cursor_size.y;
        entry_count++;
    }
}
