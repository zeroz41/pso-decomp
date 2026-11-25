#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/unk/TWindowLayoutRect.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025B4A0.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/NinjaTypes.h"
#include <string.h>
#pragma readonly_strings on
#pragma fp_contract on

// A window part that shows a label and a value text after a layout rectangle.
class LabelValuePart : public TWindowLayoutRect {
public:
    s32 m_18;
    char *label;
    char *value;
    s32 color;
};

extern "C" {
u32 calc_text_width(u32);

void *window_label_value_part_vtable[6] = {
    0, 0,
    (void *)TWindowSubStatusDisp::destroy_free_buffers,
    (void *)TWindowSubStatusDisp__sub_8025B760,
    (void *)draw_label_value__20TWindowSubStatusDispFPvPv,
    0,
};

void TWindowSubStatusDisp::set_string(uaddr string) {
    LabelValuePart *part = (LabelValuePart *)this;
    s32 title_len;

    mem_free((void *)part->value);
    part->value = 0;
    if (string != 0U) {
        part->x = (f32) (0.0f);
        title_len = (s32)measure_string_len((const char *)(string));
        part->value = (char *)mem_alloc(title_len + 1);
        strncpy(part->value, (const char *)string, (u32)title_len + 1);
    }
}

void TWindowSubStatusDisp::set_text(uaddr label, s32 string, s32 value_18) {
    LabelValuePart *part = (LabelValuePart *)this;
    s32 title_len;

    mem_free((void *)part->label);
    part->label = 0;
    if (label != 0U) {
        title_len = (s32)measure_string_len((const char *)(label));
        part->label = (char *)mem_alloc(title_len + 1);
        strncpy(part->label, (const char *)label, (u32)title_len + 1);
    }
    part->m_18 = value_18;
    part->x = (f32) (0.0f);
    part->flags = part->flags | 5;
    set_string(string);
}

void TWindowSubStatusDisp::set_text(uaddr label, s32 value_18) {
    LabelValuePart *part = (LabelValuePart *)this;
    s32 title_len;
    f64 tmp;

    mem_free((void *)part->label);
    part->label = 0;
    if (label != 0U) {
        title_len = (s32)measure_string_len((const char *)(label));
        part->label = (char *)mem_alloc(title_len + 1);
        strncpy(part->label, (const char *)label, (u32)title_len + 1);
    }
    part->m_18 = value_18;
    part->flags = (u16) (part->flags | 0x15);
    part->x = (208.5f) - ((0.5f) * (f32) ::calc_text_width(label));
}
void draw_label_value__20TWindowSubStatusDispFPvPv(u8 *window_sub_com_card, u8 *draw_context) {
    NJS_POINT2 pos;
    LabelValuePart *part = (LabelValuePart *)window_sub_com_card;
    WindowDrawContext *context = (WindowDrawContext *)draw_context;
    if ((((TWindowSubComCard *)part)->is_flag_4_set() != 0) && (context->open_tick >= 0)) {
        pos.x = context->inner_x + part->x;
        pos.y = context->inner_y + part->y;
        set_text_draw_params(context, 1, 1, (-1.0f) / ((0.0897f) + context->depth), (1e+05f));
        draw_window_text(&pos.x, (const char *)part->label, part->color, 1, 1e+05f);
        if (!(part->flags & 0x10)) {
            pos.x += (154.0f);
            draw_window_text(&pos.x, ":", part->color, 0, (1e+05f));
        }
        pos.x += (12.0f);
        draw_window_text(&pos.x, (const char *)part->value, part->color, 1, 1e+05f);
    }
}
void TWindowSubStatusDisp__sub_8025B760(void *p) {
    if (((TWindowSubComCard *)p)->is_flag_4_set()) return;
}

void *TWindowSubStatusDisp::destroy_free_buffers(void *window_sub_status_disp, s16 delete_flag) {
    LabelValuePart *part = (LabelValuePart *)window_sub_status_disp;
    if (window_sub_status_disp != NULL) {
        *(void ***)((s8 *)window_sub_status_disp + 4) = window_label_value_part_vtable;
        mem_free((void *)part->value);
        mem_free((void *)part->label);
        __dt__17TWindowLayoutRectFv(window_sub_status_disp, 0);
        if (delete_flag > 0) {
            ::operator delete(window_sub_status_disp);
        }
    }
    return window_sub_status_disp;
}

void*TWindowSubComCard::init_fields(int rec, int client) { __ct__17TWindowLayoutRectFl(this, client); *(int*)((char*)this + 0x4) = (saddr)window_label_value_part_vtable; *(float*)((char*)this + 0x14) = (18.0f); this->selected_card = -1; *(int*)((char*)this + 0x1c) = 0; this->client_id = 0; *(int*)((char*)this + 0x18) = 0; return this; }

int TWindowSubComCard::is_flag_4_set() { return *(u16*)(this + 0x0) & 0x4; }

}
