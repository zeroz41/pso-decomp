#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/unk/text_8024AC64.h"
#include "pso/unk/text_8024ACA8.h"
#include "pso/ui/window/TWindowReturnCity.h"
#include "pso/ui/window/TWindowMessageYesNo.h"

#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/warp/TObjAreaWarpQuest.h"
#include "pso/system/task/TObject.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/ui/window/TWindowSubComCard_802A5748.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"

struct Base_8026D208 { char pad[0x18]; };
struct VObj_8026D208 : Base_8026D208 {
    virtual void m0();  virtual void m1();  virtual void m2();  virtual void m3();
    virtual void m4();  virtual void m5();  virtual void m6();  virtual void m7();
    virtual void m8();  virtual void m9();  virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30();
    virtual s32 m31();
};


extern "C" {
void *get_player_by_client_id(s32);
s32 prepare_hospital_return__10TObjPlayerFv();
s32 __ct__7TObjectFP7TObject(void *, void *);
saddr get_window_layout_position(int);
void TWindowCtrl__sub_8026D4E8(void);
extern s32 __vt__17TWindowReturnCity[];
#pragma push
#pragma readonly_strings on
const char *TWindowReturnCity__class_name = "TWindowReturnCity";
#pragma pop
u8 *TWindowReturnCity__ct(TWindowReturnCity *arg0, saddr arg1, s32 arg2);
extern saddr tl_00;
void TWindowReturnCity__sub_8026D4BC(void);
void TWindowReturnCity__sub_8026D4C0(void);
}
extern s32 lbl_805D55C0;
int TWindowReturnCity__client_scan_index;
void return_to_city_after_defeat(void);
void return_to_city_after_defeat(void) {
    if (((s32) lbl_805D55C0 != 1) && ((s32) (*(s32 *)&TWindowReturnCity__client_scan_index) < 4)) {
        if (((saddr)get_player_by_client_id((s32)((u32) (*(s32 *)&TWindowReturnCity__client_scan_index)))) != 0U) {
            prepare_hospital_return__10TObjPlayerFv();
        }
        floor_transition_state.set_next_floor(0, (int) (get_floor_map_terrain(0)));
        mark_area_change_pending();
        TNpcPlayer::send_inter_level_warp_all(floor_transition_state.get_next_floor());
        (*(s32 *)&TWindowReturnCity__client_scan_index) = 4;
    }
}

s32 TWindowReturnCity::query_battle_state() {
    struct VObj_8026D208 *o = (struct VObj_8026D208 *)get_player_by_client_id(this->m_24);
    if (o == NULL) {
        return 0;
    }
    return o->m31();
}

void TWindowReturnCity::render() {  }

void TWindowReturnCity::run_task() {
    s32 temp_r3;
    if ((s32) lbl_805D55C0 != 1) {
        switch (this->m_20) {
        case 2:
            break;
        case 0:
            this->m_20 = 1;
        case 1:
            if ((query_battle_state() == 0) || ((s32) TWindowReturnCity__client_scan_index != 4)) {
                TWindowReturnCity::clear_flag_bit5();
                TWindowReturnCity__sub_8024ACA8(this->m_24);
                TWindowCtrl::clear_flag_2();
                queue_destruction();
                this->m_20 = 2;
                return;
            }
            if (((TWindowSubComCard *)(this->m_1c))->get_card_data() != 0) {
                TWindowReturnCity::clear_flag_bit5();
                TWindowReturnCity__sub_8024ACA8(this->m_24);
                TWindowCtrl::clear_flag_2();
                queue_destruction();
                this->m_20 = 2;
                return;
            }
            if (((TWindowMessageYesNo *)(this->m_1c))->is_child_visible() != 0) {
                temp_r3 = ((TWindowSubComCard *)(this->m_1c))->get_slot_or_neg1();
                if (temp_r3 == 0) {
                    TWindowReturnCity__client_scan_index = this->m_24;
                    uaddr task = (uaddr)TObject::operator new(0x28);
                    if (task != 0U) {
                        ((THunterGuildSeqOffline *)task)->init((void *)tl_00, (void *)return_to_city_after_defeat);
                    }
                    this->m_20 = 2;
                }
                if (temp_r3 == 1) {
                    TWindowReturnCity::clear_flag_bit5();
                    TWindowReturnCity__sub_8024ACA8(this->m_24);
                    TWindowCtrl::clear_flag_2();
                    queue_destruction();
                    this->m_20 = 2;
                }
            }
            break;
        }
    }
}

TWindowReturnCity::~TWindowReturnCity() {
    if (*(void **)((s8 *)this + 0x1C) != NULL) { ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x1C)))->close(); this->m_1c = 0; }
}

u8 *TWindowReturnCity__ct(TWindowReturnCity *window_return_city, saddr parent, s32 arg2) {
  s32 window_layout_position;
  __ct__7TObjectFP7TObject((void *) window_return_city, (void *) parent);
  *((s32 **) (((s8 *) window_return_city) + 0x18)) = __vt__17TWindowReturnCity;
  *((s32 *) (((s8 *) window_return_city) + 0)) = (saddr) TWindowReturnCity__class_name;
  window_return_city->m_24 = arg2;
  window_layout_position = (saddr)TWindowMessageYesNo::create((void *)((void *) window_return_city), window_return_city->m_24, 0, 0);
  window_return_city->m_1c = window_layout_position;
  if (window_return_city)
  {
  }
  window_layout_position = get_window_layout_position(0x23);
  ((TWindowMessageYesNo *)window_return_city->m_1c)->open_yes_no_prompt_with_text((saddr)(TWindowSubStatusDisp::get_message_10(0x43)), (s32)window_layout_position, 206.0f);
  ((TWindowMessageYesNo *)window_return_city->m_1c)->set_menu_selected_index(1);
  fn_8024AC64((window_return_city->m_24));
  TWindowCtrl::set_close_flag();
  TWindowCtrl__sub_8026D4E8();
  window_return_city->m_20 = 0;
  return (u8 *)window_return_city;
}

void TWindowReturnCity__sub_8026D4BC(void) {  }

void TWindowReturnCity__sub_8026D4C0(void) { TWindowReturnCity__client_scan_index = 4; }


void TWindowReturnCity::clear_flag_bit5() {
    if (TWindowCtrl::instance != NULL) {
        TWindowCtrl::instance->flags &= ~0x20;
    }
}

void TWindowCtrl__sub_8026D4E8(void) {
    if (TWindowCtrl::instance != NULL) {
        TWindowCtrl::instance->flags |= 0x20;
    }
}
