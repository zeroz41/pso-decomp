#include "types.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/TWindowTradeRequest.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

struct RecoveredGlobal_802E0224___vt__19TWindowTradeRequest {
    s32 value;
    u8 remaining[0x14];
};

struct VBase_18_f23ffb
{
  char pad[0x18];
};

struct VObj_18_f23ffb : VBase_18_f23ffb {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual s32 m10();
};

struct RecoveredGlobal_802E02D4___vt__19TWindowTradeRequest
{
  s32 value;
  u8 remaining[0x14];
};

struct Obj_802E0174 { u8 pad[0x1C]; s32 state; void *card; };

extern "C" {
s32 __dt__7TObjectFv(void *, int);
s32 init_parts__10TObjPlayerFv();
void *get_player_by_client_id(s32 i);
s32 __dl__7TObjectFPv(void *);
void fn_8024AADC(s32 arg0, s32 arg1);
void TLobby__sub_8024AC20(s32 arg0);
void TWindowReturnCity__sub_8024ACA8(s32 arg0);
extern RecoveredGlobal_802E0224___vt__19TWindowTradeRequest __vt__19TWindowTradeRequest;
extern s32 local_client_id;
u8 *__dt__19TWindowTradeRequestFv(TWindowTradeRequest *arg0, s16 arg1);
s32 *get_shared_text_buffer(void);
u8 *get_window_layout_position(s32);
s32 create__19TWindowMessageYesNoFPvPvPvPv(s32, s32, s32, s32);
char get_trade_mode__6TLobbyFv(void);
s32 reset_equip_slots__10TObjPlayerFv();
s32 text_builder_append();
}
void text_builder_reset(void);
extern "C" {
s32 __ct__7TObjectFP7TObject();
void TObjPlayer__sub_8024ABDC(s32 arg0);
void fn_8024AC64(s32 arg0);
s32 forward_slot_selection__16TAdChrSelASlotGCFPvPv(int, int, int, f32);
extern s32 lbl_805D3F70;
u8 *TWindowTradeRequest__ct(TWindowTradeRequest *arg0);
void TWindowTradeRequest::render() {  }

typedef char RecoveredGlobal_802E0224___vt__19TWindowTradeRequest_size[sizeof(RecoveredGlobal_802E0224___vt__19TWindowTradeRequest) == 0x18 ? 1 : -1];

void TWindowTradeRequest::run_task() {
    Obj_802E0174 *arg0 = (Obj_802E0174 *)this;
    s32 slot;
    switch (arg0->state) {
    case 0:
    case 1:
        if (((TWindowSubComCard *)(arg0->card))->get_card_data() != 0) {
            TWindowTradeRequest::reset_trade();
            TWindowTradeRequest::close_request_window();
            arg0->state = 3;
            break;
        }
        if (((TWindowMessageYesNo *)(arg0->card))->is_child_visible() != 0) {
            slot = ((TWindowSubComCard *)(arg0->card))->get_slot_or_neg1();
            if (slot == 0) {
                TLobby::send_trade_proposal_modify();
                TWindowTradeRequest::close_request_window();
                arg0->state = 2;
            }
            if (slot == 1) {
                TWindowTradeRequest::reset_trade();
                TWindowTradeRequest::close_request_window();
                arg0->state = 3;
            }
        }
        break;
    case 2:
    case 3:
    default:
        break;
    }
}

u8 *__dt__19TWindowTradeRequestFv(TWindowTradeRequest *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__19TWindowTradeRequest.value;
        if ((u32) arg0->m_20 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x20)))->close();
            arg0->m_20 = 0U;
        }
        TWindowReturnCity__sub_8024ACA8((local_client_id));
        TLobby__sub_8024AC20((local_client_id));
        if (get_player_by_client_id((local_client_id)) != 0U) {
            init_parts__10TObjPlayerFv();
        }
        if ((u32) arg0->m_1c == 2U) {
            fn_8024AADC((local_client_id), 0x1D);
        }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return (u8 *)arg0;
}
typedef struct RecoveredGlobal_802E02D4___vt__19TWindowTradeRequest RecoveredGlobal_802E02D4___vt__19TWindowTradeRequest;
typedef struct VBase_18_f23ffb VBase_18_f23ffb;
typedef struct VObj_18_f23ffb VObj_18_f23ffb;
#pragma fp_contract on
#define PSO_VCALL_VObj_18_f23ffb_m10(_self) (((VObj_18_f23ffb *)(_self))->m10())
u8 *TWindowTradeRequest__ct(TWindowTradeRequest *window_trade_request) {
  u32 new_var;
  s32 player;
  s8 *new_var2;
  u8 *window_layout_position;
  __ct__7TObjectFP7TObject();
  *((s32 **) (((s8 *) window_trade_request) + 0x18)) = &(*(RecoveredGlobal_802E02D4___vt__19TWindowTradeRequest *)&__vt__19TWindowTradeRequest).value;
  *((s32 *) (((s8 *) window_trade_request) + 0)) = (s32) lbl_805D3F70;
  player = ((s32)get_player_by_client_id(((u32) get_trade_mode__6TLobbyFv())));
  text_builder_reset();
  new_var = (u32) player;
  if (new_var)
  {
    PSO_VCALL_VObj_18_f23ffb_m10(player);
    text_builder_append();
  }
  TWindowSubStatusDisp::get_message_10(0xD9);
  text_builder_append();
  window_trade_request->m_20 = create__19TWindowMessageYesNoFPvPvPvPv((s32) window_trade_request, local_client_id, 0, 0);
  window_layout_position = (u8 *) get_window_layout_position(0xB2);
  forward_slot_selection__16TAdChrSelASlotGCFPvPv(window_trade_request->m_20, (int) get_shared_text_buffer(), (int) window_layout_position, 260.0f);
  new_var2 = ((s8 *) window_trade_request) + 0x1C;
  ((TWindowSubShortMail *)(window_trade_request->m_20))->notify_warp_flag70();
  if (((s32)get_player_by_client_id(((u32) local_client_id))) != 0U)
  {
    reset_equip_slots__10TObjPlayerFv();
  }
  TObjPlayer__sub_8024ABDC(local_client_id);
  fn_8024AC64(local_client_id);
  *((s32 *) new_var2) = 0;
  return (u8 *)window_trade_request;
}
}
