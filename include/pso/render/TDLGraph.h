#ifndef PSO_RENDER_TDLGRAPH_H
#define PSO_RENDER_TDLGRAPH_H

#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"

// One progress reading: the graph's frame count when the progress last changed.
struct TDLGraphSample {
    s32 frame;
    f32 progress;
};

void copy_graph_sample(TDLGraphSample *dst, TDLGraphSample *src);

// Download progress graph: a pulsing bar, a percentage and an estimated time left.
struct TDLGraph : public TObject {
    TDLGraph(TObject *parent);
    virtual ~TDLGraph();
    void set_progress(s32 done, s32 total);
    void draw_outlined_string_right_aligned(s32 x, s32 y, char *str);
    void draw_percent_text(f32 x, f32 y);
    void draw_countdown_timer(f32 x, f32 y);
    void draw_progress_bar(const NJS_POINT2 &pos, const NJS_POINT2 &size);
    s32 estimate_remaining_frames(f32 progress);
    s32 push_sample(s32 frame, f32 progress);
    void init_dl_graph_entries();
    void update_bar_colors();
    void reset_bar_colors();
    virtual void render();
    virtual void run_task();
    void set_graph_param(s32 flags);
    static void update_graph(s32 done, s32 total);
    static void *create();

    static const char *class_name;
    static TDLGraph *graph_object;

    f32 m_progress;     // 0.0 to 1.0
    u32 m_flags;        // bit 0 draws the time left, bit 1 the percentage
    s32 m_frame;        // frames rendered
    s32 m_eta_state;    // -1 until the first estimate of 10 s or more, 1 while shown, 0 never
    s32 m_eta;          // frames left, counted down while drawn
    s32 m_eta_frame;    // m_frame when m_eta was last set
    u32 m_fill_color;   // bar fill, pulsing
    u32 m_empty_color;  // rest of the bar, pulsing
    s32 m_pulse;        // colour pulse phase
    s32 m_sample_count;
    TDLGraphSample m_samples[4]; // newest first
};

LAYOUT_ASSERT(TDLGraph_size, sizeof(TDLGraph) == 0x64);

#endif
