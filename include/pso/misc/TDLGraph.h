#ifndef PSO_MISC_TDLGRAPH_H
#define PSO_MISC_TDLGRAPH_H

#include "types.h"
#include "pso/TObject.h"

struct TDLGraph : public TObject {
    virtual ~TDLGraph();
    void sub_8007F644();
    void sub_8007F5A4();
    void init_dl_graph_entries();
    void draw_countdown_timer(f32, f32);
    void draw_percent_text(f32, f32);
    u8 _pad1C[0x4];
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
    u8 unk_34[0x4];
    s32 m_38;
    s32 m_3c;
    u8 unk_40[0x24];
};

typedef char TDLGraph_size[sizeof(TDLGraph) == 0x64 ? 1 : -1];

// --- C functions defined in TDLGraph.cpp ---
extern "C" {
void fn_8007F560(void *p, void *q);
u8 *__dt__8TDLGraphFv(u8 *arg0, s16 arg1);
void *TDLGraph__ct(TDLGraph *dl_graph, TObject *parent);
}
// --- end of C functions

#endif
