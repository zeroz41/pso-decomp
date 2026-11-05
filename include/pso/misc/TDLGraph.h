#ifndef PSO_MISC_TDLGRAPH_H
#define PSO_MISC_TDLGRAPH_H

#include "types.h"
#include "pso/TObject.h"

struct TDLGraph : public TObject {
    TDLGraph(TObject *parent);
    virtual ~TDLGraph();
    void sub_8007F644();
    void sub_8007F5A4();
    void init_dl_graph_entries();
    void draw_countdown_timer(f32, f32);
    void draw_percent_text(f32, f32);
    f32 m_1c;
    u32 m_20;
    u32 m_24;
    u32 m_28;
    u32 m_2c;
    u32 m_30;
    virtual void render();
    virtual void run_task();
    void set_graph_param(s32 v);
    static void update_graph(s32 arg0, s32 arg1);
    static void *create();
    s32 m_34;
    s32 m_38;
    s32 m_3c;
    u8 unk_40[0x24];
};

typedef char TDLGraph_size[sizeof(TDLGraph) == 0x64 ? 1 : -1];

// --- C functions defined in TDLGraph.cpp ---
extern "C" {
void fn_8007F560(void *p, void *q);
}
// --- end of C functions

#endif
