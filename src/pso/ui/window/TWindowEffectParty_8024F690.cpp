#include "types.h"
#include "pso/ui/window/TWindowEffectParty.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"

extern "C" {
f32 atan2_float(f32 y, f32 x);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern const f64 lbl_8044ECF0;
extern const f32 lbl_805DCCB8;
extern const f32 lbl_805DCCBC;
void *__nw__7TObjectFUl(u32);
void *__ct__18TWindowEffectPartyFP7TObjectScScPv(void *, void *, u16, u16, s32);
extern s32 local_client_id;
void *TWindowCtrl__sub_8024FB80(s8);
s32 get_window_layout_position(s32);
f32 get_scale__15TWindowCtrlMainFv(s32);

extern f32 lbl_805DCCC0;

#pragma fp_contract on
s32 TWindowEffectParty::step_toward_target(f32 farg0, f32 farg1) {
    u8 *arg0 = (u8 *)this;
  f32 temp_f4;
  f32 temp_f5;
  s32 temp_r31;
  temp_f5 = farg1 - (*((f32 *) (((s8 *) arg0) + 0x24)));
  temp_f4 = *((f32 *) (((s8 *) arg0) + 0x20));
  temp_f4 = farg0 - temp_f4;
  if (((temp_f4 * temp_f4) + (temp_f5 * temp_f5)) < lbl_805DCCB8)
  {
    *((f32 *) (((s8 *) arg0) + 0x20)) = farg0;
 do { *((f32 *) (((s8 *) arg0) + 0x24)) = farg1; return 1; } while (0);
  }
  temp_r31 = (s32) (lbl_8044ECF0 * atan2_float((f64) temp_f5, (f64) temp_f4));
  *((f32 *) (((s8 *) arg0) + 0x20)) = (f32) ((lbl_805DCCBC * cos_table_lookup(temp_r31)) + (*((f32 *) (((s8 *) arg0) + 0x20))));
  *((f32 *) (((s8 *) arg0) + 0x24)) = (f32) ((lbl_805DCCBC * sin_table_lookup(temp_r31)) + (*((f32 *) (((s8 *) arg0) + 0x24))));
  return 0;
}

void TWindowEffectParty::calc_effect_position(void *arg1) {
    *(f32 *)((s8 *)arg1 + 0) = (f32) *(f32 *)&this->m_20;
    *(f32 *)((s8 *)arg1 + 4) = (f32) *(f32 *)&this->_pad24;
    *(f32 *)((s8 *)arg1 + 8) = (f32) (lbl_805DCCC0 / get_scale__15TWindowCtrlMainFv(local_client_id));
}

extern const f32 lbl_805DCCC4;
extern const f32 lbl_805DCCC8;
extern const f32 lbl_805DCCCC;
extern const f32 lbl_805DCCD0;

void TWindowEffectParty::set_slot_position(s32 arg0, s32 arg1, void *window_sub_symbol_chat_parts_set) {
    void *temp_r3;
    (void)arg0;

    if (arg1 <= 0) {
        ((TWindowSubSymbolChatPartsSet *)window_sub_symbol_chat_parts_set)->copy_vec2((void*)(get_window_layout_position(0x1C)));
        *(f32 *)((s8 *)window_sub_symbol_chat_parts_set + 0) = (f32) (*(f32 *)((s8 *)window_sub_symbol_chat_parts_set + 0) + lbl_805DCCC4);
        *(f32 *)((s8 *)window_sub_symbol_chat_parts_set + 4) = (f32) (*(f32 *)((s8 *)window_sub_symbol_chat_parts_set + 4) + lbl_805DCCC8);
        return;
    }
    temp_r3 = TWindowCtrl__sub_8024FB80(arg1 - 1);
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)window_sub_symbol_chat_parts_set + 0) = (f32) (lbl_805DCCCC + *(f32 *)((s8 *)temp_r3 + 0x30));
        *(f32 *)((s8 *)window_sub_symbol_chat_parts_set + 4) = (f32) (lbl_805DCCD0 + *(f32 *)((s8 *)temp_r3 + 0x34));
    }
}
void *TWindowEffectParty::create(void *owner, s32 from, s32 to, u32 kind) {
    s32 id;
    u16 b;
    u16 a;
    void *w;
    if ((u16)from == (u16)to) {
        return 0;
    }
    if ((u16)from >= 4) {
        return 0;
    }
    if ((u16)to >= 4) {
        return 0;
    }
    switch (kind) {
    case 6:
    case 8:
        id = 0x99;
        break;
    case 7:
        id = 0x98;
        break;
    case 9:
        id = 0x96;
        break;
    case 10:
        id = 0x95;
        break;
    case 0:
        id = 0x97;
        break;
    default:
        return 0;
    }
    a = from - local_client_id;
    if (a & 0xFFFC) {
        a += 4;
    }
    b = to - local_client_id;
    if (b & 0xFFFC) {
        b += 4;
    }
    w = __nw__7TObjectFUl(0x34);
    if (w != 0) {
        w = __ct__18TWindowEffectPartyFP7TObjectScScPv(w, owner, a, b, id);
    }
    return w;
}

}
