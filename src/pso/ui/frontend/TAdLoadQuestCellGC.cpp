#include "types.h"
#include "pso/render/ColorLineList.h"
#include "pso/render/Draw2D.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdLoadQuestCellGC.h"
#include "pso/ui/frontend/TAdLoadQuestGC.h"

// Top-left corner and size of the two black bars draw_quest_load_letterbox_bars fills
// (quest_load_letterbox_bar_positions and _sizes are inferred names).
static const NJS_POINT2 quest_load_letterbox_bar_positions[2] = {{0.0f, 0.0f}, {0.0f, 416.0f}};
static const NJS_POINT2 quest_load_letterbox_bar_sizes[2] = {{640.0f, 64.0f}, {640.0f, 64.0f}};
// Top-left corner and size of the two panels draw_quest_load_panel_overlays shades
// (quest_load_panel_overlay_positions is an inferred name).
static const NJS_POINT2 quest_load_panel_overlay_positions[2] = {{31.0f, 73.0f}, {543.0f, 75.0f}};
static const NJS_POINT2 quest_load_panel_overlay_offsets[2] = {{455.0f, 332.0f}, {72.0f, 332.0f}};

// The class name; its string sits after the tables above in .rodata.
const char *load_quest_cell_name = "TAdLoadQuestCellGC";

static void draw_quest_load_panel_overlays(void) {
    NJS_POINT2 pos[4];
    NJS_POINT2COL d;
    NJS_COLOR col[4];
    u32 i;
    d.p = pos;
    d.col = col;
    d.tex = NULL;
    d.num = 4;
    i = 0;
    do {
        d.p[0].x = quest_load_panel_overlay_positions[i].x;
        d.p[0].y = quest_load_panel_overlay_positions[i].y;
        d.col[0].color = 0x77;
        d.p[1].x = quest_load_panel_overlay_positions[i].x;
        d.p[1].y = d.p[0].y + quest_load_panel_overlay_offsets[i].y;
        d.col[1].color = 0x77;
        d.p[2].x = d.p[0].x + quest_load_panel_overlay_offsets[i].x;
        d.p[2].y = d.p[0].y + quest_load_panel_overlay_offsets[i].y;
        d.col[2].color = 0x77;
        d.p[3].x = d.p[0].x + quest_load_panel_overlay_offsets[i].x;
        d.p[3].y = d.p[0].y;
        d.col[3].color = 0x77;
        draw_polygon_2d(&d, 4, 7, (-490.0f));
        i++;
    } while (i < 2);
}

static void draw_quest_load_letterbox_bars(void) {
    NJS_POINT2 pos[4];
    NJS_POINT2COL d;
    NJS_COLOR col[4];
    u32 i;
    d.p = pos;
    d.col = col;
    d.tex = NULL;
    d.num = 4;
    i = 0;
    do {
        d.p[0].x = quest_load_letterbox_bar_positions[i].x;
        d.p[0].y = quest_load_letterbox_bar_positions[i].y;
        d.col[0].color = 0xFF;
        d.p[1].x = quest_load_letterbox_bar_positions[i].x;
        d.p[1].y = d.p[0].y + quest_load_letterbox_bar_sizes[i].y;
        d.col[1].color = 0xFF;
        d.p[2].x = d.p[0].x + quest_load_letterbox_bar_sizes[i].x;
        d.p[2].y = d.p[0].y + quest_load_letterbox_bar_sizes[i].y;
        d.col[2].color = 0xFF;
        d.p[3].x = d.p[0].x + quest_load_letterbox_bar_sizes[i].x;
        d.p[3].y = d.p[0].y;
        d.col[3].color = 0xFF;
        draw_polygon_2d(&d, 4, 3, (-490.0f));
        i++;
    } while (i < 2);
}

// Fills the screen with dark blue stripes, 4 pixels on and 4 off, 120 rows deep.
static void draw_quest_load_scanlines(void) {
    ColorLineVertex pos[4];
    ColorLineList d;
    u32 col[4];
    u32 i;
    f32 y;
    f32 y2;
    d.verts = pos;
    d.colors = col;
    d.tex = NULL;
    d.count = 4;
    for (i = 0; i < 0x78; i++) {
        d.verts[0].x = 0.0f;
        y = 8.0f * (f32) i;
        d.verts[0].y = y;
        d.colors[0] = 0xFF001A36;
        d.verts[1].x = 640.0f;
        y2 = 4.0f + y;
        d.verts[1].y = y;
        d.colors[1] = 0xFF001A36;
        d.verts[2].x = 640.0f;
        d.verts[2].y = y2;
        d.colors[2] = 0xFF001A36;
        d.verts[3].x = 640.0f;
        d.verts[3].y = y2;
        d.colors[3] = 0xFF001A36;
        draw_color_lines(&d, 4, 3, (-500.0f));
    }
}

__declspec(section ".data") TAdLoadQuestCellGC *ad_load_quest_cell_table[3] = { 0, 0, 0 };

void TAdLoadQuestCellGC::render_state() {
    switch (this->m_state) {
    case 0:
        draw_quest_load_scanlines();
        return;
    case 1:
        draw_quest_load_letterbox_bars();
        return;
    case 2:
        draw_quest_load_panel_overlays();
        return;
    }
}

void TAdLoadQuestCellGC::render() {
    if (TMainTask::get_render_pass() != 1) {
        ++m_frameCount;
        if (m_frameCount >= 2) {
            render_state();
        }
    }
}

void TAdLoadQuestCellGC::run_task() {}

TAdLoadQuestCellGC::~TAdLoadQuestCellGC() {
    if (ad_load_quest_cell_table[m_state] != NULL) {
        ad_load_quest_cell_table[m_state] = NULL;
    }
}

TAdLoadQuestCellGC::TAdLoadQuestCellGC(TObject *parent, s32 state) : TObject(parent) {
    this->m_name = load_quest_cell_name;
    m_state = state;
    this->m_frameCount = -1;
}

TAdLoadQuestCellGC *TAdLoadQuestGC::get_or_create_cell(int slot) {
    if (ad_load_quest_cell_table[slot] == NULL) {
        ad_load_quest_cell_table[slot] = new TAdLoadQuestCellGC(this, slot);
    }
    return ad_load_quest_cell_table[slot];
}
