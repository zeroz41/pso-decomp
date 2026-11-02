#include "types.h"
#include "pso/misc/TWindowReturnCity.h"
#include "pso/misc/TWindowMessageYesNo.h"

#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjAreaWarpQuest.h"

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

struct RecoveredGlobal_8026D18C_lbl_80515BA0 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_8026D40C___vt__17TWindowReturnCity
{
  s32 value;
  u8 remaining[0x14];
};

extern "C" {
void *get_player_by_client_id(s32);
s32 get_floor_map_terrain(s32);
void mark_area_change_pending(void);
s32 prepare_hospital_return__10TObjPlayerFv();
s32 set_area__6TLobbyFl(void *, int, int);
s32 send_inter_level_warp_all__10TNpcPlayerFl();
s32 __ct__7TObjectFP7TObject(void *, void *);
void fn_8024AC64(s32 arg0);
s32 get_window_layout_position(int);
void TWindowCtrl__sub_8026D4E8(void);
s32 free_member__17TWindowSubComCardFv(int, int);
s32 forward_slot_selection__16TAdChrSelASlotGCFPvPv(int, int, int, f32);
s32 create__19TWindowMessageYesNoFPvPvPvPv(void *, int, int, int);
extern s32 __vt__17TWindowReturnCity[];
extern s32 TWindowReturnCity__class_name;
u8 *TWindowReturnCity__ct(TWindowReturnCity *arg0, s32 arg1, s32 arg2);
void queue_destruction__7TObjectFv(void *arg0);
u32 __nw__7TObjectFUl(s32);
void TWindowReturnCity__sub_8024ACA8(s32 arg0);
extern s32 tl_00;
void TWindowReturnCity__sub_8026D4BC(void);
void TWindowReturnCity__sub_8026D4C0(void);
}
extern RecoveredGlobal_8026D18C_lbl_80515BA0 lbl_80515BA0;
extern s32 lbl_805D55C0;
int TWindowReturnCity__client_scan_index;
void return_to_city_after_defeat(void);
typedef char RecoveredGlobal_8026D18C_lbl_80515BA0_size[sizeof(RecoveredGlobal_8026D18C_lbl_80515BA0) == 0x28 ? 1 : -1];
void return_to_city_after_defeat(void) {
    if (((s32) lbl_805D55C0 != 1) && ((s32) (*(s32 *)&TWindowReturnCity__client_scan_index) < 4)) {
        if (((s32)get_player_by_client_id((s32)((u32) (*(s32 *)&TWindowReturnCity__client_scan_index)))) != 0U) {
            prepare_hospital_return__10TObjPlayerFv();
        }
        set_area__6TLobbyFl(&lbl_80515BA0.value, 0, (int) (get_floor_map_terrain(0)));
        mark_area_change_pending();
        ((TObjAreaWarpQuest *)(&lbl_80515BA0.value))->get_dest_area();
        send_inter_level_warp_all__10TNpcPlayerFl();
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
                queue_destruction__7TObjectFv(this);
                this->m_20 = 2;
                return;
            }
            if (((TWindowSubComCard *)(this->m_1c))->get_card_data() != 0) {
                TWindowReturnCity::clear_flag_bit5();
                TWindowReturnCity__sub_8024ACA8(this->m_24);
                TWindowCtrl::clear_flag_2();
                queue_destruction__7TObjectFv(this);
                this->m_20 = 2;
                return;
            }
            if (((TWindowMessageYesNo *)(this->m_1c))->is_child_visible() != 0) {
                temp_r3 = ((TWindowSubComCard *)(this->m_1c))->get_slot_or_neg1();
                if (temp_r3 == 0) {
                    TWindowReturnCity__client_scan_index = this->m_24;
                    u32 task = __nw__7TObjectFUl(0x28);
                    if (task != 0U) {
                        ((THunterGuildSeqOffline *)task)->init((void *)tl_00, (void *)return_to_city_after_defeat);
                    }
                    this->m_20 = 2;
                }
                if (temp_r3 == 1) {
                    TWindowReturnCity::clear_flag_bit5();
                    TWindowReturnCity__sub_8024ACA8(this->m_24);
                    TWindowCtrl::clear_flag_2();
                    queue_destruction__7TObjectFv(this);
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

typedef struct RecoveredGlobal_8026D40C___vt__17TWindowReturnCity RecoveredGlobal_8026D40C___vt__17TWindowReturnCity;
typedef char RecoveredGlobal_8026D40C___vt__17TWindowReturnCity_size[((sizeof(RecoveredGlobal_8026D40C___vt__17TWindowReturnCity)) == 0x18) ? (1) : (-1)];
u8 *TWindowReturnCity__ct(TWindowReturnCity *window_return_city, s32 arg1, s32 arg2) {
  s32 temp_r31;
  __ct__7TObjectFP7TObject((void *) window_return_city, (void *) arg1);
  *((s32 **) (((s8 *) window_return_city) + 0x18)) = &(*(RecoveredGlobal_8026D40C___vt__17TWindowReturnCity *)&__vt__17TWindowReturnCity).value;
  *((s32 *) (((s8 *) window_return_city) + 0)) = (s32) TWindowReturnCity__class_name;
  window_return_city->m_24 = arg2;
  temp_r31 = create__19TWindowMessageYesNoFPvPvPvPv((void *) window_return_city, window_return_city->m_24, 0, 0);
  window_return_city->m_1c = temp_r31;
  if (window_return_city)
  {
  }
  temp_r31 = get_window_layout_position(0x23);
  forward_slot_selection__16TAdChrSelASlotGCFPvPv(window_return_city->m_1c, (int) TWindowSubStatusDisp::get_message_10(0x43), (int) temp_r31, 206.0f);
  free_member__17TWindowSubComCardFv(window_return_city->m_1c, 1);
  fn_8024AC64((window_return_city->m_24));
  TWindowCtrl::set_close_flag();
  TWindowCtrl__sub_8026D4E8();
  window_return_city->m_20 = 0;
  return (u8 *)window_return_city;
}

void TWindowReturnCity__sub_8026D4BC(void) {  }

void TWindowReturnCity__sub_8026D4C0(void) { TWindowReturnCity__client_scan_index = 4; }

extern void *TWindowCtrl__active_window;

void TWindowReturnCity::clear_flag_bit5() {
    if ((void *) TWindowCtrl__active_window != NULL) {
        *(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) = (u16) (*(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) & 0xFFFFFFDF);
    }
}

void TWindowCtrl__sub_8026D4E8(void) {
    if ((void *) TWindowCtrl__active_window != NULL) {
        *(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) = (u16) (*(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) | 0x20);
    }
}
