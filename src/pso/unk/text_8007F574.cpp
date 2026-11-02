#include "types.h"
#include "pso/misc/TDLGraph.h"

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
    u8 *arg0 = (u8 *)this;
  int new_var;
  s32 temp_r3;
  s32 temp_r3_2;
  sin_table_lookup((int) ((this->m_3c) << 0xB));
  temp_r3 = __cvt_fp2unsigned((f32) ((32.0f * fabs_float()) + 64.0f), 32.0f);
  new_var = ~0xFF000000;
  *((s32 *) (((s8 *) arg0) + 0x34)) = (s32) (((((temp_r3 << 0x10) & 0xFF0000) & new_var) | (temp_r3 << 0x18)) | 0xFFFF);
  sin_table_lookup((int) ((this->m_3c) << 7));
  temp_r3_2 = __cvt_fp2unsigned((f32) ((128.0f * (lbl_805D929C - fabs_float())) + 64.0f), 128.0f);
  this->m_38 = (s32) (((((((temp_r3_2 << 0x10) & 0xFF0000) & new_var) | (temp_r3_2 << 0x18)) & (~0xFF00)) | ((temp_r3_2 << 8) & 0xFF00)) | 0xFF);
  this->m_3c = (s32) ((this->m_3c) + 1);
}

}
