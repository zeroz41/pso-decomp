#include "types.h"
#include "pso/unk/TWindowLayoutEntry.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/HelpItemStatCompareRow.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/system/memory.h"
#include "pso/unk/TWindowStatusGauge.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/system/NinjaTypes.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/vector.h"
#include <string.h>
#pragma readonly_strings on

void HelpItemStatCompareRow::update_visible_flags() {
    if ((flags & 4) || (flags & 8)) {
        if (!(flags & 4)) {
            set_value(0);
        }
        if (!(flags & 8)) {
            set_compare_value(0);
        }
    }
}

void HelpItemStatCompareRow::draw_number_value(f32 *pos, s32 value, s32 color, s32 percent) {
    f32 xy[2];

    text_builder_reset();
    text_builder_append_int(value);
    if (percent) {
        text_builder_append("%");
    }
    xy[0] = pos[0] - (f32)calc_text_width(get_shared_text_buffer());
    xy[1] = pos[1];
    draw_window_text(xy, get_shared_text_buffer(), color, 0, 1000000.0f);
}

void HelpItemStatCompareRow::set_compare_enabled(s32 enable) {
    if (enable != 0) {
        flags |= 0x10;
        return;
    }
    flags &= ~0x10;
}

void HelpItemStatCompareRow::set_compare_value(s32 value) {
    flags |= 8;
    compare_value = value;
}

void HelpItemStatCompareRow::set_compare_color(s32 new_value) {
    if (value == new_value) {
        color = -1;
        return;
    }
    if (value > new_value) {
        color = 0xFF77E8FF;
    } else {
        color = 0xFFDD8C41;
    }
    highlight_timer = 30;
    set_value(new_value);
}

void HelpItemStatCompareRow::set_value(s32 value) {
    flags |= 4;
    this->value = value;
}

void HelpItemStatCompareRow::set_help_text(uaddr str) {
    s32 len;

    mem_free(label);
    label = NULL;
    if (str != 0U) {
        len = (s32)measure_string_len((const char *)str);
        label = (char *)mem_alloc(len + 1);
        strncpy(label, (const char *)str, (u32)len + 1);
    }
}

void HelpItemStatCompareRow::render(WindowDrawContext *context) {
    NJS_POINT2 text_pos;
    s32 compare_color;

    if (context->open_tick < 0) {
        return;
    }
    if (!(flags & 4) && !(flags & 8)) {
        return;
    }
    text_pos.x = context->inner_x + pos[0];
    text_pos.y = context->inner_y + pos[1];
    set_text_draw_params(context, 1, 0, -1.0f / (0.0897f + context->depth), 100000.0f);
    draw_window_text((f32 *)&text_pos, label, -1, 1, 100000.0f);
    text_pos.x += 86.0f;
    draw_window_text((f32 *)&text_pos, ":", -1, 0, 100000.0f);
    text_pos.x += 64.0f;
    if (flags & 4) {
        draw_number_value((f32 *)&text_pos, value, color, is_flag20_set());
    }
    if (flags & 8) {
        draw_window_text((f32 *)&text_pos, "\tJ\x81\xA8", -1, 0, 100000.0f);
        text_pos.x += 70.0f;
        if (!(flags & 0x10)) {
            compare_color = 0xFF909090;
        } else if (value == compare_value) {
            compare_color = -1;
        } else if (value > compare_value) {
            compare_color = 0xFF77E8FF;
        } else {
            compare_color = 0xFFDD8C41;
        }
        draw_number_value((f32 *)&text_pos, compare_value, compare_color, is_flag20_set());
    }
}

void HelpItemStatCompareRow::update() {
    if (highlight_timer > 0) {
        highlight_timer--;
        if (highlight_timer <= 0) {
            color = -1;
        }
    }
}

HelpItemStatCompareRow::~HelpItemStatCompareRow() {
    mem_free(label);
}

HelpItemStatCompareRow::HelpItemStatCompareRow(PointLayoutRecord *rec, s32 client) : TWindowLayoutEntry(client) {
    copy_vec2(pos, rec->pos);
    color = -1;
    highlight_timer = 0;
    label = NULL;
    value = 0;
    compare_value = 0;
}

int HelpItemStatCompareRow::is_flag20_set() {
    return flags & 0x20;
}
