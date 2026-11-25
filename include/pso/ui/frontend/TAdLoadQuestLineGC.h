#ifndef PSO_UI_FRONTEND_TADLOADQUESTLINEGC_H
#define PSO_UI_FRONTEND_TADLOADQUESTLINEGC_H

#include "pso/system/task/TObject.h"
#include <stddef.h>
#include "pso/render/Draw2D.h"

// A run of `count` filled rectangles of one color: pos[i] is a corner, size[i] the extent.
struct QuestLineRect {
    u32 count;
    u32 color;
    const NJS_POINT2 *pos;
    const NJS_POINT2 *size;
};

// The rectangle lists of each state; the draw functions copy one to the stack before drawing it.
struct QuestLineRects6 { QuestLineRect items[6]; };
struct QuestLineRects2 { QuestLineRect items[2]; };

class TAdLoadQuestLineGC : public TObject {
public:
    TAdLoadQuestLineGC(TObject *parent, s32 state);
    virtual ~TAdLoadQuestLineGC();
    virtual void run_task();
    virtual void render();
    s32 m_state;
    s32 m_frameCount;
    static const char *name;

    void render_by_state();
    // State 0: the bracket lines around the quest list.
    void draw_frame_lines();
    // State 1: the two banner lines and the slanted quads joining them.
    void draw_banner_lines();
    void draw_rects(QuestLineRect *rects, s32 count);
    void draw_color_quad(f32 *coords, s32 color);
};

LAYOUT_ASSERT(TAdLoadQuestLineGCFrameOffset, offsetof(TAdLoadQuestLineGC, m_frameCount) == 0x20);
LAYOUT_ASSERT(TAdLoadQuestLineGCSize, sizeof(TAdLoadQuestLineGC) == 0x24);
LAYOUT_ASSERT(TAdLoadQuestLineGCStateOffset, offsetof(TAdLoadQuestLineGC, m_state) == 0x1C);

extern "C" __declspec(section ".data") TAdLoadQuestLineGC *ad_load_quest_line_instances[2];

#endif
