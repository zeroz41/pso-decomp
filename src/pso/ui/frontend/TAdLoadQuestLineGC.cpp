#include "pso/ui/frontend/TAdLoadQuestGC.h"
#include "pso/ui/frontend/TAdLoadQuestLineGC.h"

#include "types.h"
#include "pso/render/Draw2D.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma pool_data off
static const NJS_POINT2 quest_line_rect1_origins[3] = { {31.0f, 73.0f}, {31.0f, 73.0f}, {31.0f, 405.0f} };
static const NJS_POINT2 quest_line_rect1_sizes[3] = { {28.0f, 1.0f}, {1.0f, 333.0f}, {28.0f, 1.0f} };
static const NJS_POINT2 quest_line_rect2_origins[3] = { {459.0f, 73.0f}, {486.0f, 73.0f}, {459.0f, 405.0f} };
static const NJS_POINT2 quest_line_rect2_sizes[3] = { {28.0f, 1.0f}, {1.0f, 333.0f}, {28.0f, 1.0f} };
static const NJS_POINT2 quest_line_rect3_origins[3] = { {543.0f, 73.0f}, {543.0f, 73.0f}, {543.0f, 405.0f} };
static const NJS_POINT2 quest_line_rect3_sizes[3] = { {19.0f, 1.0f}, {1.0f, 333.0f}, {19.0f, 1.0f} };
static const NJS_POINT2 quest_line_rect4_origins[3] = { {595.0f, 73.0f}, {615.0f, 73.0f}, {595.0f, 405.0f} };
static const NJS_POINT2 quest_line_rect4_sizes[3] = { {19.0f, 1.0f}, {1.0f, 333.0f}, {19.0f, 1.0f} };
static const NJS_POINT2 quest_line_rect5_origins[2] = { {543.0f, 241.0f}, {543.0f, 318.0f} };
static const NJS_POINT2 quest_line_rect5_sizes[2] = { {19.0f, 1.0f}, {19.0f, 1.0f} };
static const NJS_POINT2 quest_line_rect6_origins[2] = { {595.0f, 241.0f}, {595.0f, 318.0f} };
static const NJS_POINT2 quest_line_rect6_sizes[2] = { {19.0f, 1.0f}, {19.0f, 1.0f} };
static const NJS_POINT2 quest_line_rect7_origins[2] = { {0.0f, 55.0f}, {229.0f, 24.0f} };
static const NJS_POINT2 quest_line_rect7_sizes[2] = { {213.0f, 1.0f}, {411.0f, 1.0f} };
static const NJS_POINT2 quest_line_rect8_origins[2] = { {0.0f, 456.0f}, {426.0f, 425.0f} };
static const NJS_POINT2 quest_line_rect8_sizes[2] = { {410.0f, 1.0f}, {214.0f, 1.0f} };
static const f32 quest_line_color_quad_coordinates[8] = { 212.0f, 55.0f, 212.0f, 56.0f, 229.0f, 25.0f, 229.0f, 24.0f };
static const f32 quest_line_quad_vertices[8] = { 409.0f, 456.0f, 409.0f, 457.0f, 426.0f, 426.0f, 426.0f, 425.0f };
extern const char load_quest_line_class_name_string[] = "TAdLoadQuestLineGC";


static const QuestLineRects6 load_quest_line_rectangle_groups = { {
    { 3, 0x777777FF, quest_line_rect1_origins, quest_line_rect1_sizes },
    { 3, 0x777777FF, quest_line_rect2_origins, quest_line_rect2_sizes },
    { 3, 0x777777FF, quest_line_rect3_origins, quest_line_rect3_sizes },
    { 3, 0x777777FF, quest_line_rect4_origins, quest_line_rect4_sizes },
    { 2, 0x777777FF, quest_line_rect5_origins, quest_line_rect5_sizes },
    { 2, 0x777777FF, quest_line_rect6_origins, quest_line_rect6_sizes },
} };
static const QuestLineRects2 quest_line_color_entry_table = { {
    { 2, 0x777777FF, quest_line_rect7_origins, quest_line_rect7_sizes },
    { 2, 0x777777FF, quest_line_rect8_origins, quest_line_rect8_sizes },
} };

void TAdLoadQuestLineGC::draw_color_quad(f32 *coords, s32 color) {
    NJS_POINT2 pos[4];
    NJS_POINT2COL quad;
    NJS_COLOR col[4];
    f32 y;
    f32 x;
    NJS_POINT2COL *poly = &quad;
    x = coords[0];
    y = coords[1];
    quad.p = pos;
    quad.col = col;
    quad.tex = NULL;
    quad.num = 4;
    quad.p[0].x = x;
    quad.p[0].y = y;
    quad.col[0].color = color;
    quad.p[1].x = coords[2];
    quad.p[1].y = coords[3];
    quad.col[1].color = color;
    quad.p[2].x = coords[4];
    quad.p[2].y = coords[5];
    quad.col[2].color = color;
    quad.p[3].x = coords[6];
    quad.p[3].y = coords[7];
    quad.col[3].color = color;
    draw_polygon_2d(poly, 4, 3, -1.0f);
}

void TAdLoadQuestLineGC::draw_rects(QuestLineRect *rects, s32 count) {
    NJS_POINT2 pos[4];
    NJS_POINT2COL quad;
    NJS_COLOR col[4];
    QuestLineRect *rect;
    u32 i;
    u32 color;
    u32 j;
    quad.p = pos;
    quad.col = col;
    quad.tex = NULL;
    quad.num = 4;
    for (i = 0; i < (u32)count; i++) {
        rect = &rects[i];
        color = rect->color;
        for (j = 0; j < rect->count; j++) {
            quad.p[0].x = rect->pos[j].x;
            quad.p[0].y = rect->pos[j].y;
            quad.col[0].color = color;
            quad.p[1].x = rect->pos[j].x;
            quad.p[1].y = quad.p[0].y + rect->size[j].y;
            quad.col[1].color = color;
            quad.p[2].x = rect->pos[j].x + rect->size[j].x;
            quad.p[2].y = rect->pos[j].y + rect->size[j].y;
            quad.col[2].color = color;
            quad.p[3].x = rect->pos[j].x + rect->size[j].x;
            quad.p[3].y = rect->pos[j].y;
            quad.col[3].color = color;
            draw_polygon_2d(&quad, 4, 3, -1.0f);
        }
    }
}

void TAdLoadQuestLineGC::draw_banner_lines() {
    QuestLineRects2 rects = quest_line_color_entry_table;
    draw_rects(rects.items, 2);
    draw_color_quad((f32 *)quest_line_color_quad_coordinates, 0x777777FF);
    draw_color_quad((f32 *)quest_line_quad_vertices, 0x777777FF);
}

void TAdLoadQuestLineGC::draw_frame_lines() {
    QuestLineRects6 rects = load_quest_line_rectangle_groups;
    draw_rects(rects.items, 6);
}
#pragma pop

void TAdLoadQuestLineGC::render_by_state() {
    switch (m_state) {
    case 0:
        draw_frame_lines();
        return;
    case 1:
        draw_banner_lines();
        return;
    }
}

void TAdLoadQuestLineGC::render() {
    if (TMainTask::get_render_pass() != 1) {
        ++m_frameCount;
        if (m_frameCount >= 2) {
            render_by_state();
        }
    }
}

void TAdLoadQuestLineGC::run_task() {}

TAdLoadQuestLineGC::~TAdLoadQuestLineGC() {
    if (ad_load_quest_line_instances[m_state] != NULL) {
        ad_load_quest_line_instances[m_state] = NULL;
    }
}

const char *TAdLoadQuestLineGC::name = load_quest_line_class_name_string;
TAdLoadQuestLineGC::TAdLoadQuestLineGC(TObject *parent, s32 state) : TObject(parent) {
    m_name = name;
    m_state = state;
    this->m_frameCount = -1;
}

TAdLoadQuestLineGC *TAdLoadQuestGC::get_or_create_line(int slot) {
    if (ad_load_quest_line_instances[slot] == NULL) {
        ad_load_quest_line_instances[slot] = new TAdLoadQuestLineGC(this, slot);
    }
    return ad_load_quest_line_instances[slot];
}

__declspec(section ".data") TAdLoadQuestLineGC *ad_load_quest_line_instances[2] = { NULL, NULL };
