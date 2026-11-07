#include "types.h"
#include "pso/unk/text_80349B8C.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma pool_data off
struct Desc_80349C54 {
    f32 *pos;
    s32 *col;
    s32 a;
    s32 b;
};

struct Item_80349C54 {
    u32 count;
    s32 color;
    const f32 *pos;
    const f32 *size;
};

static const f32 lbl_80478778[6] = { 31.0f, 73.0f, 31.0f, 73.0f, 31.0f, 405.0f };
static const f32 lbl_80478790[6] = { 28.0f, 1.0f, 1.0f, 333.0f, 28.0f, 1.0f };
static const f32 lbl_804787A8[6] = { 459.0f, 73.0f, 486.0f, 73.0f, 459.0f, 405.0f };
static const f32 lbl_804787C0[6] = { 28.0f, 1.0f, 1.0f, 333.0f, 28.0f, 1.0f };
static const f32 lbl_804787D8[6] = { 543.0f, 73.0f, 543.0f, 73.0f, 543.0f, 405.0f };
static const f32 lbl_804787F0[6] = { 19.0f, 1.0f, 1.0f, 333.0f, 19.0f, 1.0f };
static const f32 lbl_80478808[6] = { 595.0f, 73.0f, 615.0f, 73.0f, 595.0f, 405.0f };
static const f32 lbl_80478820[6] = { 19.0f, 1.0f, 1.0f, 333.0f, 19.0f, 1.0f };
static const f32 lbl_80478838[4] = { 543.0f, 241.0f, 543.0f, 318.0f };
static const f32 lbl_80478848[4] = { 19.0f, 1.0f, 19.0f, 1.0f };
static const f32 lbl_80478858[4] = { 595.0f, 241.0f, 595.0f, 318.0f };
static const f32 lbl_80478868[4] = { 19.0f, 1.0f, 19.0f, 1.0f };
static const f32 lbl_80478878[4] = { 0.0f, 55.0f, 229.0f, 24.0f };
static const f32 lbl_80478888[4] = { 213.0f, 1.0f, 411.0f, 1.0f };
static const f32 lbl_80478898[4] = { 0.0f, 456.0f, 426.0f, 425.0f };
static const f32 lbl_804788A8[4] = { 410.0f, 1.0f, 214.0f, 1.0f };
static const f32 quest_line_color_quad_coordinates[8] = { 212.0f, 55.0f, 212.0f, 56.0f, 229.0f, 25.0f, 229.0f, 24.0f };
static const f32 quest_line_quad_vertices[8] = { 409.0f, 456.0f, 409.0f, 457.0f, 426.0f, 426.0f, 426.0f, 425.0f };
// TAdLoadQuestLineGC::m_name (lbl_805D4300 in TAdLoadQuestLineGC.cpp) points here.
extern const char TAdLoadQuestLineGC__class_name_string[] = "TAdLoadQuestLineGC";

// Each function copies its rectangle list to the stack before drawing it.
struct QuestLineRects6 { Item_80349C54 items[6]; };
struct QuestLineRects2 { Item_80349C54 items[2]; };

static const QuestLineRects6 TAdLoadQuestLineGC__rectangle_groups = { {
    { 3, 0x777777FF, lbl_80478778, lbl_80478790 },
    { 3, 0x777777FF, lbl_804787A8, lbl_804787C0 },
    { 3, 0x777777FF, lbl_804787D8, lbl_804787F0 },
    { 3, 0x777777FF, lbl_80478808, lbl_80478820 },
    { 2, 0x777777FF, lbl_80478838, lbl_80478848 },
    { 2, 0x777777FF, lbl_80478858, lbl_80478868 },
} };
static const QuestLineRects2 quest_line_color_entry_table = { {
    { 2, 0x777777FF, lbl_80478878, lbl_80478888 },
    { 2, 0x777777FF, lbl_80478898, lbl_804788A8 },
} };

s32 draw_color_quad_2d(void *arg0, void *arg1p, int arg2) {
    f32 pos[8];
    Desc_80349C54 d;
    s32 col[4];
    f32 *arg1 = (f32 *)arg1p;
    f32 y;
    f32 x;
    Desc_80349C54 *pd = &d;
    x = arg1[0];
    y = arg1[1];
    d.pos = pos;
    d.col = col;
    d.a = 0;
    d.b = 4;
    d.pos[0] = x;
    d.pos[1] = y;
    d.col[0] = arg2;
    d.pos[2] = arg1[2];
    d.pos[3] = arg1[3];
    d.col[1] = arg2;
    d.pos[4] = arg1[4];
    d.pos[5] = arg1[5];
    d.col[2] = arg2;
    d.pos[6] = arg1[6];
    d.pos[7] = arg1[7];
    d.col[3] = arg2;
    ((TObjCMHairMenu *)pd)->draw_tri_fan_2d(4, 3, -1.0f);
}

void draw_filled_rects_2d(void *arg0, void *arg1, int arg2) {
    f32 pos[8];
    Desc_80349C54 d;
    s32 col[4];
    Item_80349C54 *item;
    u32 i;
    s32 c;
    u32 j;
    d.pos = pos;
    d.col = col;
    d.a = 0;
    d.b = 4;
    for (i = 0; i < (u32) arg2; i++) {
        item = &((Item_80349C54 *) arg1)[i];
        c = item->color;
        for (j = 0; j < item->count; j++) {
            d.pos[0] = item->pos[j * 2];
            d.pos[1] = item->pos[j * 2 + 1];
            d.col[0] = c;
            d.pos[2] = item->pos[j * 2];
            d.pos[3] = d.pos[1] + item->size[j * 2 + 1];
            d.col[1] = c;
            d.pos[4] = item->pos[j * 2] + item->size[j * 2];
            d.pos[5] = item->pos[j * 2 + 1] + item->size[j * 2 + 1];
            d.col[2] = c;
            d.pos[6] = item->pos[j * 2] + item->size[j * 2];
            d.pos[7] = item->pos[j * 2 + 1];
            d.col[3] = c;
            ((TObjCMHairMenu *)(&d))->draw_tri_fan_2d(4, 3, -1.0f);
        }
    }
}

void init_quest_line_draw_colors(s32 arg0) {
    QuestLineRects2 rects = quest_line_color_entry_table;
    draw_filled_rects_2d((void *)arg0, &rects, 2);
    draw_color_quad_2d((void *)arg0, (void *)quest_line_color_quad_coordinates, 0x777777FF);
    draw_color_quad_2d((void *)arg0, (void *)quest_line_quad_vertices, 0x777777FF);
}

void fn_80349E5C(s32 arg0) {
    QuestLineRects6 rects = TAdLoadQuestLineGC__rectangle_groups;
    draw_filled_rects_2d((void *)arg0, &rects, 6);
}
