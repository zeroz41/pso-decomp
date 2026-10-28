#include "pso/TAdRicoRing.h"
#include "pso/system/FlagWord.h"
#include "pso/menu/TAdRicoRing.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"

#include "types.h"
#include "pso/ui/TAdRicoRingCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8001BD0C___vt__11TAdRicoRing { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8001BD0C___vt__11TAdRicoRing_size[sizeof(RecoveredGlobal_8001BD0C___vt__11TAdRicoRing) == 0x18 ? 1 : -1];

extern "C" {
volatile int test_flags_any(void *, s32);
extern const f32 lbl_805D7E4C;
extern const f32 lbl_805D7E54;
s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
s32 __ct__7TObjectFP7TObject();
extern RecoveredGlobal_8001BD0C___vt__11TAdRicoRing __vt__11TAdRicoRing;
extern s32 TAdRicoRing__class_name;
extern s32 TAdRicoRing__resource_bundle;
int post_translate_matrix(void*);
int push_matrix(void*);

void TAdRicoRing::render() { push_matrix(this); TObjFish::set_global_param((s32)(*(void**)((char*)this + 0x50))); post_translate_matrix((char*)this + 0x58); rotate_matrix_zyx((void*)0, (s32)(*(void**)((char*)this + 0x64)), (s32)(*(void**)((char*)this + 0x68)), (s32)(*(void**)((char*)this + 0x6c))); set_chunk_render_flags((s32)((void*)1)); draw_chunk_object((void *)(*(void**)((char*)this + 0x4c))); set_chunk_render_flags((s32)((void*)2)); draw_chunk_object((void *)(*(void**)((char*)this + 0x4c))); clear_chunk_render_flags(); pop_matrix(); }

void TAdRicoRingCtrl::set_scale4(f32 farg0) {
    *(f32 *)&this->m_1c = farg0;
    *(f32 *)&this->m_20 = farg0;
    *(f32 *)&this->unk_24 = farg0;
    this->m_28 = farg0;
}

void TAdRicoRing::update_position() {
    *(f32 *)((s8 *)this + 0x1C) = (f32) (*(f32 *)((s8 *)this + 0x1C) + *(f32 *)((s8 *)this + 0x38));
    *(f32 *)((s8 *)this + 0x20) = (f32) (*(f32 *)((s8 *)this + 0x20) + *(f32 *)((s8 *)this + 0x3C));
    *(f32 *)((s8 *)this + 0x24) = (f32) *(f32 *)((s8 *)this + 0x20);
    *(f32 *)((s8 *)this + 0x28) = (f32) *(f32 *)((s8 *)this + 0x20);
}
void TAdRicoRing::run_task() {
    u8 *arg0 = (u8 *)this;
  f32 temp_f1;
  if (test_flags_any(arg0 + 0x2C, 1) != 0)
  {
    update_position();
    if ((*((f32 *) (((s8 *) arg0) + 0x1C))) <= lbl_805D7E54)
    {
      queue_destruction__7TObjectFv(arg0);
      return;
    }
  }
  if (test_flags_any(arg0 + 0x2C, 2) != 0)
  {
    update_position();
    temp_f1 = *((f32 *) (((s8 *) arg0) + 0x34));
    if (temp_f1 <= (*((f32 *) (((s8 *) arg0) + 0x1C))))
    {
      *((f32 *) (((s8 *) arg0) + 0x1C)) = temp_f1;
      *((f32 *) (((s8 *) arg0) + 0x28)) = (f32) lbl_805D7E4C;
      *((f32 *) (((s8 *) arg0) + 0x24)) = (f32) lbl_805D7E4C;
      *((f32 *) (((s8 *) arg0) + 0x20)) = (f32) lbl_805D7E4C;
      ((FlagWord *)(arg0 + 0x2C))->clear(2);
    }
  }
  *((s32 *) (((s8 *) arg0) + 0x68)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x68))) + (*((s32 *) (((s8 *) arg0) + 0x30))));
  if (test_flags_any(arg0 + 0x2C, 4) != 0)
  {
    *((s32 *) (((s8 *) arg0) + 0x30)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x30))) + (*((s32 *) (((s8 *) arg0) + 0x48))));
    if (((s32) (*((s32 *) (((s8 *) arg0) + 0x30)))) >= 0xCCC)
    {
      ((FlagWord *)(arg0 + 0x2C))->clear(4);
    }
  }
  else
  {
    *((s32 *) (((s8 *) arg0) + 0x30)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x30))) - (*((s32 *) (((s8 *) arg0) + 0x48))));
    if (((s32) (*((s32 *) (((s8 *) arg0) + 0x30)))) <= 0x5B0)
    {
      ((FlagWord *)(arg0 + 0x2C))->set(4);
    }
  }
}
TAdRicoRing::~TAdRicoRing() {}
u8 *__ct__11TAdRicoRingFv(u8 *arg0) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__11TAdRicoRing.value;
    __ct__8FlagWordFv((arg0 + 0x2C));
    *(s32 *)((s8 *)arg0 + 0) = (s32) TAdRicoRing__class_name;
    *(s32 *)((s8 *)arg0 + 0x4C) = get_bml_model((void *)TAdRicoRing__resource_bundle, 0);
    *(s32 *)((s8 *)arg0 + 0x50) = TObjFish__sub_8001EDB0((void *)TAdRicoRing__resource_bundle, 0);
    *(f32 *)((s8 *)arg0 + 0x28) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x24) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x20) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x1C) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x44) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x40) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x3C) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x38) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x60) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x5C) = (f32) lbl_805D7E4C;
    *(f32 *)((s8 *)arg0 + 0x58) = (f32) lbl_805D7E4C;
    *(s32 *)((s8 *)arg0 + 0x6C) = 0;
    *(s32 *)((s8 *)arg0 + 0x68) = 0;
    *(s32 *)((s8 *)arg0 + 0x64) = 0;
    *(f32 *)((s8 *)arg0 + 0x34) = (f32) lbl_805D7E4C;
    *(s32 *)((s8 *)arg0 + 0x30) = 0x5B0;
    ((FlagWord *)(arg0 + 0x2C))->set((s32)(4U));
    switch (TKeyBoardControl__sub_8000F828()) {
    case 0:
        *(s32 *)((s8 *)arg0 + 0x48) = 0x12;
        break;
    case 1:
        *(s32 *)((s8 *)arg0 + 0x48) = 0x15;
        break;
    }
    return arg0;
}

}
