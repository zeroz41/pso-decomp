// Built with -inline off,deferred: the functions are generated in reverse source order, so
// they are defined here from the last one in .text to the first.
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/frontend/TAdSubPlyItemGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include <string.h>
#include <stdio.h>
#include "pso/system/vector.h"

const char *TAdSubPlyItemGC__name = "TAdSubPlyItemGC";

struct Entry_802D6DAC { s32 idx; const char *str; s32 id; NJS_POINT2 pos; };

u8 level_text_buffer[0x40];

#pragma push
#pragma opt_common_subs off
TAdSubPlyItemGC::TAdSubPlyItemGC(TObject *parent) : TObject(parent) {
    u32 i;
    m_name = TAdSubPlyItemGC__name;
    for (i = 0; i < 4; i++) {
        alpha[i] = 0;
        visible[i] = 0;
        memset(names[i], 0, 0xFF);
        levels[i] = 0;
    }
}
#pragma pop

TAdSubPlyItemGC::~TAdSubPlyItemGC() {}

void TAdSubPlyItemGC::run_task() {
    u32 i;
    for (i = 0; i < 4; i++) {
        level_pos[i].x = (180.0f + name_pos[i].x) - (f32)calc_text_width((char *)format_level_text(levels[i]));
        level_pos[i].y = 20.0f + name_pos[i].y;
        if (visible[i] != 0) {
            alpha[i] += 0xB;
            alpha[i] = (alpha[i] > 0xFF) ? 0xFF : alpha[i];
        }
    }
}

extern "C" {
void set_entry_text__15TAdSubPlyItemGCFPvPv(TAdSubPlyItemGC *self, PlayerSlotLabel *e) {
    s32 i = e->slot;
    strncpy(self->names[i], e->name, 0xFE);
    self->levels[i] = e->level;
    copy_vec2(&self->name_pos[i], &e->position);
    self->level_pos[i].x = (180.0f + self->name_pos[i].x) -
                           (f32)calc_text_width((char *)self->format_level_text(self->levels[i]));
    self->level_pos[i].y = 20.0f + self->name_pos[i].y;
    self->alpha[i] = 0;
    self->visible[i] = 1;
}
}

void TAdSubPlyItemGC::sub_802D6D88() {
    s32 i;
    for (i = 0; i < 4; i++) {
        visible[i] = 0;
    }
}

u8 *TAdSubPlyItemGC::format_level_text(int level) {
    memset(level_text_buffer, 0, 0x40);
    sprintf((char *)level_text_buffer, "LV%d", level);
    return level_text_buffer;
}

void TAdSubPlyItemGC::render() {
    u32 i;
    NJS_POINT2 *pos;
    if (TMainTask::get_render_pass() != 1) {
        for (i = 0; i < 4; i++) {
            if (visible[i] != 0 && names[i][0] != 0) {
                pos = name_pos;
                TAdSubPlyItemGC::render_status_line(1.0f + pos[i].x, name_pos[i].y, 0.39f,
                        names[i], (alpha[i] << 24) | 0x111111);
                TAdSubPlyItemGC::render_status_line(pos[i].x, pos[i].y, 0.4f,
                        names[i], (alpha[i] << 24) | 0xFFFFFF);
                if (levels[i] != 0) {
                    TAdSubPlyItemGC::render_status_line(1.0f + level_pos[i].x, level_pos[i].y, 0.39f,
                        (const char *)format_level_text(levels[i]), (alpha[i] << 24) | 0x111111);
                    TAdSubPlyItemGC::render_status_line(level_pos[i].x, level_pos[i].y, 0.4f,
                        (const char *)format_level_text(levels[i]), (alpha[i] << 24) | 0xFFFFFF);
                }
            }
        }
    }
}
