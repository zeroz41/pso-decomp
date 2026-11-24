#include "types.h"
#include "pso/render/Draw2D.h"
#include "pso/unk/text_80349B8C.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma pool_data off
struct Item_80349C54 {
    u32 count;
    u32 color;
    const NJS_POINT2 *pos;
    const NJS_POINT2 *size;
};

static const NJS_POINT2 lbl_80478778[3] = { {31.0f, 73.0f}, {31.0f, 73.0f}, {31.0f, 405.0f} };
static const NJS_POINT2 lbl_80478790[3] = { {28.0f, 1.0f}, {1.0f, 333.0f}, {28.0f, 1.0f} };
static const NJS_POINT2 lbl_804787A8[3] = { {459.0f, 73.0f}, {486.0f, 73.0f}, {459.0f, 405.0f} };
static const NJS_POINT2 lbl_804787C0[3] = { {28.0f, 1.0f}, {1.0f, 333.0f}, {28.0f, 1.0f} };
static const NJS_POINT2 lbl_804787D8[3] = { {543.0f, 73.0f}, {543.0f, 73.0f}, {543.0f, 405.0f} };
static const NJS_POINT2 lbl_804787F0[3] = { {19.0f, 1.0f}, {1.0f, 333.0f}, {19.0f, 1.0f} };
static const NJS_POINT2 lbl_80478808[3] = { {595.0f, 73.0f}, {615.0f, 73.0f}, {595.0f, 405.0f} };
static const NJS_POINT2 lbl_80478820[3] = { {19.0f, 1.0f}, {1.0f, 333.0f}, {19.0f, 1.0f} };
static const NJS_POINT2 lbl_80478838[2] = { {543.0f, 241.0f}, {543.0f, 318.0f} };
static const NJS_POINT2 lbl_80478848[2] = { {19.0f, 1.0f}, {19.0f, 1.0f} };
static const NJS_POINT2 lbl_80478858[2] = { {595.0f, 241.0f}, {595.0f, 318.0f} };
static const NJS_POINT2 lbl_80478868[2] = { {19.0f, 1.0f}, {19.0f, 1.0f} };
static const NJS_POINT2 lbl_80478878[2] = { {0.0f, 55.0f}, {229.0f, 24.0f} };
static const NJS_POINT2 lbl_80478888[2] = { {213.0f, 1.0f}, {411.0f, 1.0f} };
static const NJS_POINT2 lbl_80478898[2] = { {0.0f, 456.0f}, {426.0f, 425.0f} };
static const NJS_POINT2 lbl_804788A8[2] = { {410.0f, 1.0f}, {214.0f, 1.0f} };
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

void draw_color_quad_2d(void *arg0, void *arg1p, int arg2) {
    NJS_POINT2 pos[4];
    NJS_POINT2COL d;
    NJS_COLOR col[4];
    f32 *arg1 = (f32 *)arg1p;
    f32 y;
    f32 x;
    NJS_POINT2COL *pd = &d;
    x = arg1[0];
    y = arg1[1];
    d.p = pos;
    d.col = col;
    d.tex = NULL;
    d.num = 4;
    d.p[0].x = x;
    d.p[0].y = y;
    d.col[0].color = arg2;
    d.p[1].x = arg1[2];
    d.p[1].y = arg1[3];
    d.col[1].color = arg2;
    d.p[2].x = arg1[4];
    d.p[2].y = arg1[5];
    d.col[2].color = arg2;
    d.p[3].x = arg1[6];
    d.p[3].y = arg1[7];
    d.col[3].color = arg2;
    draw_polygon_2d(pd, 4, 3, -1.0f);
}

void draw_filled_rects_2d(void *arg0, void *arg1, int arg2) {
    NJS_POINT2 pos[4];
    NJS_POINT2COL d;
    NJS_COLOR col[4];
    Item_80349C54 *item;
    u32 i;
    u32 c;
    u32 j;
    d.p = pos;
    d.col = col;
    d.tex = NULL;
    d.num = 4;
    for (i = 0; i < (u32) arg2; i++) {
        item = &((Item_80349C54 *) arg1)[i];
        c = item->color;
        for (j = 0; j < item->count; j++) {
            d.p[0].x = item->pos[j].x;
            d.p[0].y = item->pos[j].y;
            d.col[0].color = c;
            d.p[1].x = item->pos[j].x;
            d.p[1].y = d.p[0].y + item->size[j].y;
            d.col[1].color = c;
            d.p[2].x = item->pos[j].x + item->size[j].x;
            d.p[2].y = item->pos[j].y + item->size[j].y;
            d.col[2].color = c;
            d.p[3].x = item->pos[j].x + item->size[j].x;
            d.p[3].y = item->pos[j].y;
            d.col[3].color = c;
            draw_polygon_2d(&d, 4, 3, -1.0f);
        }
    }
}

void init_quest_line_draw_colors(void *arg0) {
    QuestLineRects2 rects = quest_line_color_entry_table;
    draw_filled_rects_2d(arg0, &rects, 2);
    draw_color_quad_2d(arg0, (void *)quest_line_color_quad_coordinates, 0x777777FF);
    draw_color_quad_2d(arg0, (void *)quest_line_quad_vertices, 0x777777FF);
}

void fn_80349E5C(void *arg0) {
    QuestLineRects6 rects = TAdLoadQuestLineGC__rectangle_groups;
    draw_filled_rects_2d(arg0, &rects, 6);
}
