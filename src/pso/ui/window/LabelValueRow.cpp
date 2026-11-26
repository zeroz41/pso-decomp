#include "types.h"
#include "pso/unk/TWindowLayoutRect.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/LabelValueRow.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/NinjaTypes.h"
#include <string.h>
#pragma readonly_strings on
#pragma fp_contract on

void LabelValueRow::set_string(const char *string) {
    s32 len;

    mem_free(value);
    value = NULL;
    if (string != NULL) {
        x = 0.0f;
        len = measure_string_len(string);
        value = (char *)mem_alloc(len + 1);
        strncpy(value, string, (u32)len + 1);
    }
}

void LabelValueRow::set_text(const char *label_text, const char *string, s32 id) {
    s32 len;

    mem_free(label);
    label = NULL;
    if (label_text != NULL) {
        len = measure_string_len(label_text);
        label = (char *)mem_alloc(len + 1);
        strncpy(label, label_text, (u32)len + 1);
    }
    this->id = id;
    x = 0.0f;
    flags |= 5;
    set_string(string);
}

void LabelValueRow::set_text(const char *label_text, s32 id) {
    s32 len;

    mem_free(label);
    label = NULL;
    if (label_text != 0U) {
        len = measure_string_len(label_text);
        label = (char *)mem_alloc(len + 1);
        strncpy(label, label_text, (u32)len + 1);
    }
    this->id = id;
    flags |= 0x15;
    x = 208.5f - 0.5f * (f32)calc_text_width((char *)label_text);
}

void LabelValueRow::render(WindowDrawContext *context) {
    NJS_POINT2 pos;
    if (is_flag_4_set() != 0 && context->open_tick >= 0) {
        pos.x = context->inner_x + x;
        pos.y = context->inner_y + y;
        set_text_draw_params(context, 1, 1, -1.0f / (0.0897f + context->depth), 1e+05f);
        draw_window_text(&pos.x, label, color, 1, 1e+05f);
        if (!(flags & 0x10)) {
            pos.x += 154.0f;
            draw_window_text(&pos.x, ":", color, 0, 1e+05f);
        }
        pos.x += 12.0f;
        draw_window_text(&pos.x, value, color, 1, 1e+05f);
    }
}

void LabelValueRow::update() {
    if (is_flag_4_set()) return;
}

LabelValueRow::~LabelValueRow() {
    mem_free(value);
    mem_free(label);
}

LabelValueRow::LabelValueRow(u8 *rec, s32 client) : TWindowLayoutRect(client) {
    height = 18.0f;
    color = -1;
    label = NULL;
    value = NULL;
    id = 0;
}

int LabelValueRow::is_flag_4_set() {
    return flags & 4;
}
