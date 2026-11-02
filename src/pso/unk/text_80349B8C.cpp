#include "types.h"
#include "pso/unk/text_80349B8C.h"
#include "pso/TObjCMHairMenu.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_60 { u8 bytes[0x60]; };

struct RecoveredGlobal_80349E5C_lbl_8047890C {
    s32 value;
    u8 remaining[0x5C];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_20 { u8 bytes[0x20]; };

struct RecoveredGlobal_80349DC8_lbl_804788B8 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_80349DC8_lbl_804788D8 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_80349DC8_lbl_8047896C {
    s32 value;
    u8 remaining[0x20];
};

struct Desc_80349C54 {
    f32 *pos;
    s32 *col;
    s32 a;
    s32 b;
};

struct Item_80349C54 {
    u32 count;
    s32 color;
    f32 *pos;
    f32 *size;
};

extern RecoveredGlobal_80349E5C_lbl_8047890C TAdLoadQuestLineGC__rectangle_groups;
extern RecoveredGlobal_80349DC8_lbl_804788B8 quest_line_color_quad_coordinates;
extern RecoveredGlobal_80349DC8_lbl_804788D8 quest_line_quad_vertices;
extern RecoveredGlobal_80349DC8_lbl_8047896C quest_line_color_entry_table;
typedef char RecoveredGlobal_80349E5C_lbl_8047890C_size[sizeof(RecoveredGlobal_80349E5C_lbl_8047890C) == 0x60 ? 1 : -1];

typedef char RecoveredGlobal_80349DC8_lbl_804788B8_size[sizeof(RecoveredGlobal_80349DC8_lbl_804788B8) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_80349DC8_lbl_804788D8_size[sizeof(RecoveredGlobal_80349DC8_lbl_804788D8) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_80349DC8_lbl_8047896C_size[sizeof(RecoveredGlobal_80349DC8_lbl_8047896C) == 0x24 ? 1 : -1];

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
    ByteBlock_20 sp8;
    sp8 = *(const ByteBlock_20 *)((s32) ((u8 *)&quest_line_color_entry_table.value - 4) + 4);
    draw_filled_rects_2d((void *)arg0, (void *)((void *)&sp8), 2);
    draw_color_quad_2d((void *)arg0, (void *)((void *)&quest_line_color_quad_coordinates.value), 0x777777FF);
    draw_color_quad_2d((void *)arg0, (void *)((void *)&quest_line_quad_vertices.value), 0x777777FF);
}

void fn_80349E5C(s32 arg0) {
    ByteBlock_60 sp8;
    sp8 = *(const ByteBlock_60 *)((s32) ((u8 *)&TAdLoadQuestLineGC__rectangle_groups.value - 4) + 4);
    draw_filled_rects_2d((void *)arg0, (void *)((void *)&sp8), 6);
}
