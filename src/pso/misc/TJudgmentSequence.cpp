#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TJudgmentSequence.h"
struct TShopJudgmentItemWindow;
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_8026934C.h"
#include "pso/misc/TShopSequence.h"

#include "pso/TShopWindowBase.h"

struct Base_80215BF8_80215BA0 { char pad[0x18]; };
struct VObj_80215BF8_80215BA0 : Base_80215BF8_80215BA0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6(int a, int b);
};
struct VBase_18_4a2792
{
  char pad[0x18];
};

struct VObj_18_4a2792 : VBase_18_4a2792 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6(s32, s32);
};

struct Stack_80215DA0
{
  f32 sp8;
  f32 spC;
};

struct RecoveredGlobal_80215EF8___vt__17TJudgmentSequence {
    s32 value;
    u8 remaining[0x34];
};

struct RecoveredGlobal_80215EF8_TJudgmentSequence__data_80513E80 {
    s32 value;
    u8 remaining[0xC];
};

struct Win_80215CB8 { u8 pad[0x16c]; void *cb0; void *cb1; void *cb2; };

struct Seq_80215CB8 { u8 pad[0x24]; s32 f24; };

extern "C" {
s32 set_service_counter_camera(void *, int);
s32 get_window_layout_position(int, f32);
extern const f32 lbl_805DC680;
extern const f32 lbl_805DC684;
void *__dt__13TShopSequenceFv(void *arg0, s16 arg1);
s32 sub_8022397C__15TShopWindowBaseFv(void *);
s32 __dl__7TObjectFPv(void *);
extern RecoveredGlobal_80215EF8___vt__17TJudgmentSequence __vt__17TJudgmentSequence;
extern RecoveredGlobal_80215EF8_TJudgmentSequence__data_80513E80 TJudgmentSequence__slot_flags;
extern s32 judgment_sequence_instance;
void *__nw__7TObjectFUl(u32);
void *TShopJudgmentItemWindow__ct(TShopJudgmentItemWindow *arg0, void *arg1, void *arg2, void *arg3);
extern void *tl_05;
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 sub_80223A48__15TShopWindowBaseFv(void *);
s32 close_window__13TShopSequenceFv(void *);
int restore_player_state__13TShopSequenceFv(void*);

void TJudgmentSequence__sub_80215BA0(void *shop_window_base) {
    if (shop_window_base != NULL) {
        ((TShopWindowBase *)shop_window_base)->set_field_20((s32)((void*)(4)));
    }
}

void TJudgmentSequence__sub_80215BCC(void *shop_window_base) {
    if (shop_window_base != NULL) {
        ((TShopWindowBase *)shop_window_base)->set_field_20((s32)((void*)(4)));
    }
}

void TJudgmentSequence__sub_80215BF8(void *shop_window_base) {
    struct VObj_80215BF8_80215BA0 *o = (struct VObj_80215BF8_80215BA0 *)shop_window_base;
    if (o != NULL) {
        o->m6(0xD, 1);
        ((TShopWindowBase *)shop_window_base)->set_field_20((s32)((void*)(4)));
    }
}

void TJudgmentSequence::handle_close_input() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(this) != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        close_window__13TShopSequenceFv(this);
        queue_destruction__7TObjectFv(this);
    }
}

void TJudgmentSequence::open_judgment_window() {
    Win_80215CB8 *o = (Win_80215CB8 *)__nw__7TObjectFUl(0x178);
    if (o != 0) {
        o = (Win_80215CB8 *)TShopJudgmentItemWindow__ct((TShopJudgmentItemWindow *)((void *)o), (void *)((void *)tl_05), (void *)((Seq_80215CB8 *)this), (void *)(((Seq_80215CB8 *)this)->f24));
    }
    o->cb0 = (void *)TJudgmentSequence__sub_80215BCC;
    o->cb2 = (void *)TJudgmentSequence__sub_80215BA0;
    o->cb1 = (void *)TJudgmentSequence__sub_80215BF8;
    this->set_field_20((s32)((void *)5));
}

void TJudgmentSequence::handle_confirm() {
    if ((this->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(this) != 0) || (sub_802239EC__13TShopSequenceFv(this) != 0))) {
        set_field_20((s32)((void*)(3)));
    }
}

typedef struct Stack_80215DA0 Stack_80215DA0;
typedef struct VBase_18_4a2792 VBase_18_4a2792;
typedef struct VObj_18_4a2792 VObj_18_4a2792;
void TJudgmentSequence::setup_counter_camera() {
    u8 *arg0 = (u8 *)this;
  Stack_80215DA0 stack;
  f32 new_var;
  stack.sp8 = lbl_805DC680;
  stack.spC = lbl_805DC684;
  new_var = (f32) lbl_805DC680;
  ((TShopSequence *)arg0)->create_message_window(get_window_layout_position(0x2C, new_var), (s32)&stack.sp8);
  (((VObj_18_4a2792 *)(arg0))->m6(1, 1));
  this->m_2c = create_meseta_window(((s32) ((TShopSequence *)arg0)->get_child_field1c()) & 0xFFFF);
  ((TShopWindowBase *)arg0)->set_field_20((s32)((void*)(2)));
  *((s32 *) (((s8 *) arg0) + 0x30)) = set_service_counter_camera((void *) arg0, 2);
}

void TJudgmentSequence::restore_player_state() { restore_player_state__13TShopSequenceFv(this); set_field_20((s32)((void*)((void*)1))); }
typedef char RecoveredGlobal_80215EF8___vt__17TJudgmentSequence_size[sizeof(RecoveredGlobal_80215EF8___vt__17TJudgmentSequence) == 0x38 ? 1 : -1];
typedef char RecoveredGlobal_80215EF8_TJudgmentSequence__data_80513E80_size[sizeof(RecoveredGlobal_80215EF8_TJudgmentSequence__data_80513E80) == 0x10 ? 1 : -1];

struct Seq_80215CB8;
void TJudgmentSequence::vfunc_11() {
    switch (this->m_20) {
    case 0:
        this->restore_player_state();
        break;
    case 1:
        this->setup_counter_camera();
        break;
    case 2:
        this->handle_confirm();
        break;
    case 3:
        open_judgment_window();
        break;
    case 4:
        this->handle_close_input();
        break;
    case 5:
        break;
    }
}

u8 *__dt__17TJudgmentSequenceFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__17TJudgmentSequence.value;
        if ((u32) *(u32 *)((s8 *)arg0 + 0x30) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x30));
            *(u32 *)((s8 *)arg0 + 0x30) = 0U;
        }
        ((TShopSequence *)arg0)->close_message_window();
        if ((u32) ((TJudgmentSequence *)arg0)->m_2c != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x2C)))->close();
            ((TJudgmentSequence *)arg0)->m_2c = 0U;
        }
        judgment_sequence_instance = 0;
        *(s32 *)((s8 *)&TJudgmentSequence__slot_flags.value + (sub_8022397C__15TShopWindowBaseFv(arg0) * 4)) = 0;
        __dt__13TShopSequenceFv((arg0), 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TShopSequence__ct(u8 *arg0);
extern s32 TJudgmentSequence__class_name;

u8 *TJudgmentSequence__ct(u8 *judgment_sequence, s32 arg1, s32 arg2) {
    TShopSequence__ct((judgment_sequence));
    *(s32 **)((s8 *)judgment_sequence + 0x18) = &__vt__17TJudgmentSequence.value;
    *(s32 *)((s8 *)judgment_sequence + 0) = (s32) TJudgmentSequence__class_name;
    *(s32 *)((s8 *)judgment_sequence + 0x24) = arg2;
    ((TJudgmentSequence *)judgment_sequence)->m_2c = 0;
    *(s32 *)((s8 *)judgment_sequence + 0x30) = 0;
    judgment_sequence_instance = (s32) judgment_sequence;
    ((TShopWindowBase *)judgment_sequence)->set_field_20((s32)((void *) (0)));
    *(s32 *)((s8 *)&TJudgmentSequence__slot_flags.value + (sub_8022397C__15TShopWindowBaseFv(judgment_sequence) * 4)) = 1;
    return judgment_sequence;
}

void TJudgmentSequence__sub_80216030(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((s32 *)&TJudgmentSequence__slot_flags)[i] = 0;
    }
}

void TJudgmentSequence__sub_80216058(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((s32 *)&TJudgmentSequence__slot_flags)[i] = 0;
    }
}

void TShopWindowBase::vfunc_8() {  }
}
