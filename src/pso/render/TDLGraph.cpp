#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/render/TDLGraph.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_8007ECF0.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject.h"

struct E_8007F4B8 { s32 a; f32 f; };

struct O_8007F4B8 { u8 pad[0x40]; s32 count; E_8007F4B8 e[4]; };

extern "C" {
s32 fn_8007F4B8(O_8007F4B8 *arg0, s32 arg1, f32 farg0);

s32 fn_8007F4B8(O_8007F4B8 *arg0, s32 arg1, f32 farg0) {
    s32 i;
    if (arg1 == arg0->e[0].a || farg0 == arg0->e[0].f) {
        return 0;
    }
    for (i = 3; i > 0; i--) {
        fn_8007F560(&arg0->e[i], &arg0->e[i - 1]);
    }
    arg0->e[0].a = arg1;
    arg0->e[0].f = farg0;
    arg0->count++;
    return 1;
}

void fn_8007F560(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(f32*)((char*)p + 0x4) = *(f32*)((char*)q + 0x4); }

}

struct E_8007F574 { s32 a; f32 b; };

struct O_8007F574 { u8 pad[0x40]; s32 x40; E_8007F574 e[4]; };

extern "C" {
f32 fabs_float();
s32 __cvt_fp2unsigned(f32, f32);
s32 sin_table_lookup(int);
extern const f32 lbl_805D929C;
extern const f32 lbl_805D92B8;
#pragma fp_contract on

void TDLGraph::init_dl_graph_entries() {
    O_8007F574 *self = (O_8007F574 *)this;
    s32 i;
    self->x40 = 0;
    for (i = 0; i < 4; i++) {
        self->e[i].a = -1;
        self->e[i].b = lbl_805D92B8;
    }
}

void TDLGraph::sub_8007F5A4() {
  int new_var;
  s32 temp_r3;
  s32 temp_r3_2;
  sin_table_lookup((int) ((this->m_3c) << 0xB));
  temp_r3 = __cvt_fp2unsigned((f32) ((32.0f * fabs_float()) + 64.0f), 32.0f);
  new_var = ~0xFF000000;
  this->m_34 = (s32) (((((temp_r3 << 0x10) & 0xFF0000) & new_var) | (temp_r3 << 0x18)) | 0xFFFF);
  sin_table_lookup((int) ((this->m_3c) << 7));
  temp_r3_2 = __cvt_fp2unsigned((f32) ((128.0f * (lbl_805D929C - fabs_float())) + 64.0f), 128.0f);
  this->m_38 = (s32) (((((((temp_r3_2 << 0x10) & 0xFF0000) & new_var) | (temp_r3_2 << 0x18)) & (~0xFF00)) | ((temp_r3_2 << 8) & 0xFF00)) | 0xFF);
  this->m_3c = (s32) ((this->m_3c) + 1);
}

}

struct TDLGraph_8007F66C { u8 pad[0x24]; s32 frame; };

extern "C" {
extern TDLGraph *TDLGraph__graph_object;
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

#define G ((u32) TDLGraph__graph_object)
void TDLGraph::update_graph(s32 arg0, s32 arg1) {
    if (arg0 < 0 || arg1 <= 0) {
        return;
    }
    if (arg0 == 0) {
        if (G != 0) {
            ((TObject *)TDLGraph__graph_object)->queue_destruction();
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

}

extern const f32 lbl_805D9298;
extern const char *TDLGraph__class_name;

TDLGraph::~TDLGraph() {
    TDLGraph__graph_object = NULL;
}

TDLGraph::TDLGraph(TObject *parent) : TObject(parent) {
    m_name = TDLGraph__class_name;
    m_1c = lbl_805D9298;
    m_24 = 0;
    m_28 = -1;
    m_2c = -1;
    m_30 = -1;
    sub_8007F644();
    init_dl_graph_entries();
    m_20 = 3;
    TDLGraph__graph_object = this;
}
