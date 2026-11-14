#include "types.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowSubStatusDisp_80338740.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

extern "C" {
int get_field_38_ptr__16TEneParticleCtrlFv(void*);
    extern unsigned char lbl_804EF440[];
int reset_entry__20TWindowSubStatusDispFPv(void*, int);
s32 deleting_destructor__20TWindowSubStatusDispFs(void *, s32);
void mem_free(void *p);
extern u8 lbl_804EF440[];
s32 get_message_10__20TWindowSubStatusDispFl(s32);
void *mem_alloc(u32 size);
s32 measure_string_len__20TWindowSubStatusDispFv(void *);
s32 strncpy(int, void *, int);
typedef struct
{
  f32 x;
  f32 y;
} V2_80338890;
typedef struct
{
  u8 pad0[8];
  f32 x8;
  f32 xc;
  u8 pad10[4];
  f32 x14;
  u8 pad18[4];
  s8 c1c;
  s8 c1d;
  s8 c1e;
  s8 c1f;
  s8 c20;
  s8 c21;
  u8 pad22[2];
  s32 x24;
} Item_80338890;
typedef struct
{
  u8 pad0[0x10];
  f32 x10;
  f32 x14;
  u8 pad18[0x18];
  s32 x30;
  u8 pad34[4];
  f32 x38;
  u8 pad3c[4];
  f32 x40;
  u8 pad44[4];
  f32 x48;
} Win_80338890;
void draw_item_list_icon(Win_80338890 *, V2_80338890 *, s8, s32, f32);

void TWindowSubStatusDisp__sub_80338740(u8 *arg0, s32 arg1, s32 arg2, s8 arg3, s8 arg4, s8 arg5, s8 arg6, s8 arg7, s32 arg_sp8) {
    s32 temp_r3;
    if (arg1 != 0) {
        *(s8 *)((s8 *)arg0 + 0x1C) = 0x18;
    } else {
        *(s8 *)((s8 *)arg0 + 0x1C) = 0x33;
    }
    temp_r3 = measure_string_len__20TWindowSubStatusDispFv((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x24) = (s32)mem_alloc((temp_r3 + 1));
    strncpy((int) (*(s32 *)((s8 *)arg0 + 0x24)), (void *)arg2, (int)temp_r3);
    *(s8 *)((s8 *)temp_r3 + (*(s32 *)((s8 *)arg0 + 0x24))) = 0;
    *(s8 *)((s8 *)arg0 + 0x1D) = arg7;
    *(s8 *)((s8 *)arg0 + 0x1E) = arg6;
    *(s8 *)((s8 *)arg0 + 0x1F) = arg5;
    *(s8 *)((s8 *)arg0 + 0x20) = arg3;
    *(s8 *)((s8 *)arg0 + 0x21) = arg4;
    *(s32 *)((s8 *)arg0 + 0x18) = arg_sp8;
    *(u16 *)((s8 *)arg0 + 0) = (u16) (*(u16 *)((s8 *)arg0 + 0) | 5);
}

void TWindowSubStatusDisp__sub_803387F8(void *arg0, s8 arg1) {
    get_message_10__20TWindowSubStatusDispFl(arg1 + 0x113);
}
s32 TWindowSubStatusDisp::query_status_field(void *arg0, s8 arg1) {
    if (arg1 == 0) {
        return 0;
    }
    return get_message_10__20TWindowSubStatusDispFl(arg1 + 0x110);
}
s32 TWindowSubStatusDisp::get_flag_or_zero(void *arg0, s8 arg1) {
    if (arg1 == 0) {
        return 0;
    }
    return get_message_10__20TWindowSubStatusDispFl(arg1 + 0x10D);
}

void draw_item_row__20TWindowSubStatusDispFPvPv(Item_80338890 *arg0, Win_80338890 *arg1) {
  f32 scale;
  f32 y;
  V2_80338890 pos;
  static const char *separator = "/";
  if (TWindowSubStatusDisp__sub_80338B88(arg0) == 0)
  {
    return;
  }
  y = arg1->x14 + arg0->xc;
  if ((arg0->x14 + y) < arg1->x40)
  {
    return;
  }
  if ((arg1->x14 + arg0->xc) > arg1->x48)
  {
    return;
  }
  if (arg1->x30 < 0)
  {
    return;
  }
  pos.x = arg1->x10 + arg0->x8;
  pos.y = arg1->x14 + arg0->xc;
  scale = -1.0f / (0.1495f + arg1->x38);
  draw_item_list_icon(arg1, &pos, arg0->c1c, -1, scale);
  pos.x += 18.0f;
  set_text_draw_params((s32)arg1, 1, 1, (f32)scale, 100000.0f);
  draw_window_text((f32 *)&pos, (const char *)arg0->x24, -1, 1, 100000.0f);
  pos.x += 210.0f;
  draw_window_text((f32 *)&pos, (const char *)(TWindowSubStatusDisp::get_flag_or_zero(arg0, arg0->c1d)), -1, 0, 100000.0f);
  pos.x += 108.0f;
  draw_window_text((f32 *)&pos, (const char *)(TWindowSubStatusDisp::query_status_field(arg0, arg0->c1e)), -1, 0, 100000.0f);
  pos.x += 96.0f;
  draw_window_text((f32 *)&pos, (const char *)(((s32 (*)(void *, s8)) TWindowSubStatusDisp__sub_803387F8)(arg0, arg0->c1f)), -1, 0, 100000.0f);
  pos.x += 126.0f;
  text_builder_reset();
  TWindowSubStatusDisp__sub_80228F5C(arg0->c20);
  text_builder_append((u8 *)separator);
  TWindowSubStatusDisp__sub_80228F5C(arg0->c21);
  draw_window_text((f32 *)&pos, (const char *)(get_shared_text_buffer()), -1, 0, 100000.0f);
}

void TWindowSubStatusDisp__sub_80338A9C(void) {  }

void *TWindowSubStatusDisp::destroy_with_free(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 4) = (s32*)lbl_804EF440;
        if ((u32) *(u32 *)((s8 *)this + 0x24) != 0U) {
            mem_free(this->m_24);
            *(u32 *)((s8 *)this + 0x24) = 0U;
        }
        deleting_destructor__20TWindowSubStatusDispFs(this, 0);
        if (arg1 > 0) {
            ::operator delete(this);
        }
    }
    return this;
}

void*TWindowSubStatusDisp::init_state(int a1, int a2) { reset_entry__20TWindowSubStatusDispFPv(this, a2); *(int*)((char*)this + 0x4) = (int)lbl_804EF440; *(float*)((char*)this + 0x14) = 18.0f; *(unsigned char *)&this->unk_1C = 51; *(signed char *)&this->m_1d = -1; *(signed char *)&this->unk_1E = -1; this->m_1f = -1; *(signed char*)((char*)this + 0x20) = -1; *(signed char*)((char*)this + 0x21) = -1; *(int*)((char*)this + 0x24) = 0; *(int*)((char*)this + 0x18) = 0; return this; }

int TWindowSubStatusDisp__sub_80338B88(void* p) { return (*(u16*)((char*)p + 0x0) >> 2) & 0x1; }

int TEneParticleCtrl__vt7(void* p) { return get_field_38_ptr__16TEneParticleCtrlFv(p); }

}
