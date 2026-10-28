#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_8007ECF0.h"
#include "pso/misc/TDLGraph.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80141D1C.h"

struct RecoveredGlobal_8007F77C___vt__8TDLGraph {
    s32 value;
    u8 remaining[0x14];
};

struct TDLGraph_8007F66C { u8 pad[0x24]; s32 frame; };

extern "C" {
u8 * __dt__7TObjectFv(void *, s16);
void __dl__7TObjectFPv(s32);
extern RecoveredGlobal_8007F77C___vt__8TDLGraph __vt__8TDLGraph;
extern s32 TDLGraph__graph_object;
void TCameraCtrl__sub_80068EF0(void);
void fn_8007F27C(TDLGraph_8007F66C *self, void *a, void *b);
extern u8 lbl_80438AA4[];
extern u8 lbl_80438AAC[];
extern const f32 lbl_805D92CC;
extern const f32 lbl_805D92D0;
extern const f32 lbl_805D92D4;
void TDLGraph::sub_8007F644() {
    this->m_3c = 0;
    sub_8007F5A4();
}

void TDLGraph::render() {
    TDLGraph_8007F66C *self = (TDLGraph_8007F66C *)this;
    set_default_alpha_blend();
    TCameraCtrl::restore_full_screen_view();
    fn_8007F27C(self, lbl_80438AA4, lbl_80438AAC);
    ((TDLGraph *)self)->draw_countdown_timer(lbl_805D92CC, lbl_805D92D0);
    ((TDLGraph *)self)->draw_percent_text(lbl_805D92D4, lbl_805D92D0);
    TCameraCtrl__sub_80068EF0();
    ((TDLGraph *)self)->sub_8007F5A4();
    self->frame++;
}

void TDLGraph::run_task() {  }
void TDLGraph::set_graph_param(s32 v) { this->m_20 = v; }
typedef char RecoveredGlobal_8007F77C___vt__8TDLGraph_size[sizeof(RecoveredGlobal_8007F77C___vt__8TDLGraph) == 0x18 ? 1 : -1];

#define G ((u32) TDLGraph__graph_object)
void TDLGraph::update_graph(s32 arg0, s32 arg1) {
    if (arg0 < 0 || arg1 <= 0) {
        return;
    }
    if (arg0 == 0) {
        if (G != 0) {
            queue_destruction__7TObjectFv((void *)TDLGraph__graph_object);
            return;
        }
        TDLGraph::create();
    } else if (G == 0) {
        return;
    }
    if (G != 0) {
        fn_8007ECF0((u8 *)TDLGraph__graph_object, arg0, arg1);
    }
}
#undef G

u8 *__dt__8TDLGraphFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__8TDLGraph.value;
        TDLGraph__graph_object = 0;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

}
