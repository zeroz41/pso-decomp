#include "pso/player/TPlyDispData.h"
#include "pso/ui/window/TWindowFukidasi.h"
#include "pso/ui/window/TWindowCtrl_8024A1A8.h"
#include "pso/ui/window/WindowCtrlCallback.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/object/base/TObjChara.h"

#include <stddef.h>
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowTimer.h"
#include "pso/ui/window/TWindowArea.h"
#include "pso/object/switch/TOChatSensorCapture.h"

#include "pso/player/TObjPlayer.h"
struct RecoveredFields_8024A688_arg1
{
  u8 unknown_0[0x38];
  f32 field_38;
  f32 field_3C;
  f32 field_40;
};

struct RecoveredFields_8024A688_temp_r3
{
  u8 unknown_0[0x38];
  f32 field_38;
  f32 field_3C;
  f32 field_40;
};

struct Ctrl_8024A928 { u8 pad[0x84]; void *slots[4]; };

struct Ctrl_8024A714 { u8 pad[0x84]; void *arr[4]; };

struct Obj_8024A7CC { u8 pad[0x84]; void *arr[4]; };


struct Obj_8024AA08 { u8 pad[4]; u32 f4; };

struct Ply_8024AA08 { u8 pad[0xDB0]; u32 f; };

extern "C" {
s32 TWindowCtrl__sub_8024A314(void);
void TLobby__sub_8024AAA0(s32 arg0, s32 arg1);
u32 get_window__11TWindowCtrlFl(void);
s32 update_field28__15TWindowCtrlMainFv(u32 a0 = 0, s32 a1 = 0);
extern PlayerWindowQuery window_ctrl_main_callback_desc;
void TWindowCtrl__sub_8024A228(saddr arg0);
extern PlayerWindowCommand window_ctrl_default_call_args;
bool TWindowCtrl__sub_8024A1A8(void);
u8 *find_entity_by_id(u16);
extern const f32 lbl_805DCBE0;
f32 get_entity_distance_or_default__11TWindowCtrlFiPvUs(s32 arg0, RecoveredFields_8024A688_arg1 *arg1, u16 arg2);
s32 check_card_match_enabled__15TWindowFukidasiFl(void *, void *);
void *get_player_by_client_id(s32);
extern s32 local_client_id;
s32 obj_is_hit_receivable();
void get_speaker_balloon_anchor__11TWindowCtrlFPviPvPv(Ctrl_8024A928 *arg0, s32 arg1, f32 *arg2, s32 *arg3);
}

extern "C" {

bool TWindowCtrl__sub_8024A1A8(void) {
    if (TWindowCtrl__active_window == NULL) {
        return 0;
    }
    return TWindowCtrl__active_window->m_3c != 0;
}

void TWindowCtrl::call_window_method_with_default_vec(s32 client_id) {
    PlayerWindowCommand callback = window_ctrl_default_call_args;
    call_window_method__11TWindowCtrlFPvi(client_id, callback);
}

void TWindowCtrl::set_field22() {
    if (TWindowCtrl__active_window != NULL) {
        TWindowCtrl__active_window->submit_cooldown = 0x2D;
    }
}

void TWindowCtrl__sub_8024A228(saddr client_id) {
    PlayerWindowQuery callback = window_ctrl_main_callback_desc;
    TWindowCtrl__sub_8024B098(client_id, callback);
}

bool TWindowCtrl::is_submit_cooldown_clear() {
    if (TWindowCtrl__active_window == NULL) {
        return 0;
    }
    return TWindowCtrl__active_window->submit_cooldown <= 0;
}

void TWindowCtrl::update_focused() {
    if ((TWindowCtrl__active_window != NULL) && (TWindowCtrl__active_window->m_38 != 0U)) {
        ((TWindowChat *)TWindowCtrl__active_window->m_38)->update();
    }
}

s32 TWindowCtrl::get_active_sub() {
    if (TWindowCtrl__active_window == NULL) {
        return 0;
    }
    if (TWindowCtrl__active_window->m_38 == 0U) {
        return 0;
    }
    return TWindowCtrl__sub_8024C5C4((TWindowChat *)TWindowCtrl__active_window->m_38);
}

s32 TWindowCtrl__sub_8024A314(void) {
    if (TWindowCtrl__active_window == NULL) {
        return 0;
    }
    if (TWindowCtrl__active_window->m_38 == 0U) {
        return 0;
    }
    return TWindowCtrl__sub_8024701C((TWindowChat *)TWindowCtrl__active_window->m_38);
}

void TWindowCtrl::open_status_111() {
    if ((TWindowCtrl__active_window != NULL) && (TWindowCtrl__active_window->m_34 == NULL)) {
        TWindowCtrl__active_window->m_34 = create_area_window(TWindowSubStatusDisp::get_message_10(0x111));
    }
}

void TWindowCtrl::open_status_112() {
    if ((TWindowCtrl__active_window != NULL) && (TWindowCtrl__active_window->m_34 == NULL)) {
        TWindowCtrl__active_window->m_34 = create_area_window(TWindowSubStatusDisp::get_message_10(0x112));
    }
}

void TWindowCtrl::close_active_window() {
    if ((TWindowCtrl__active_window != NULL) && (TWindowCtrl__active_window->m_34 != NULL)) {
        TWindowCtrl__active_window->m_34->close();
        TWindowCtrl__active_window->m_34 = NULL;
    }
}

void TWindowCtrl::ensure_initialized() {
    if ((TWindowCtrl__active_window != NULL) && (TWindowCtrl__active_window->m_34 == NULL)) {
        TWindowCtrl__active_window->m_34 = create_window_area();
    }
}

void TWindowCtrl::create_timer() {
    if ((TWindowCtrl__active_window != NULL) && (TWindowCtrl__active_window->m_30 == NULL)) {
        TWindowCtrl__active_window->m_30 = TWindowTimer::create();
    }
}

void TWindowCtrl::set_timer_window_time(u32 secs) {
    TWindowTimer *timer;
    if (TWindowCtrl__active_window != NULL) {
        timer = TWindowCtrl__active_window->m_30;
        if (timer != NULL) {
            timer->set_time(secs);
        }
    }
}

void TWindowCtrl::close_timer_window() {
    if ((TWindowCtrl__active_window != NULL) && (TWindowCtrl__active_window->m_30 != NULL)) {
        TWindowCtrl__active_window->m_30->close();
        TWindowCtrl__active_window->m_30 = NULL;
    }
}

void TWindowCtrl::create_alt_timer() {
    if ((TWindowCtrl__active_window != NULL) && (TWindowCtrl__active_window->m_30 == NULL)) {
        TWindowCtrl__active_window->m_30 = TWindowTimer::create_alt();
    }
}


char *TWindowCtrl::skip_name_prefix(void *self, char *s) {
    char *p;
    for (p = s; *p != '\0'; p++) {
        if (*p == '\t') break;
    }
    if (*p == '\0') return s;
    return p + 1;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline u8 *get_obj_8024A5AC(u16 id) {
    u8 *o = find_entity_by_id(id);
    if (o != NULL && obj_is_hit_receivable() == 1) {
        return o;
    }
    return NULL;
}
void TWindowCtrl::get_speaker_balloon_anchor(u16 id, f32 *arg2, s32 *arg3) {
    u8 *obj;
    player_stats *q;
    obj = get_obj_8024A5AC(id);
    if (obj == NULL) {
        *arg2 = 0.0f;
        *arg3 = 0;
        return;
    }
    q = reinterpret_cast<player_stats *>(((TObjChara *)obj)->get_stats());
    if (q == NULL) {
        *arg2 = 0.0f;
    } else {
        *arg2 = 0.92f * q->proportions;
    }
    if (((TObjChara *)obj)->obj_isState2_324() != 0 || TObjPlayer::is_locally_controlled(obj) != 0) {
        u8 *p = obj + 0x85C;
        if (p == NULL) {
            *arg3 = 0;
            return;
        }
        *arg3 = (saddr)p;
        return;
    }
    *arg3 = 0;
}
#pragma pop

f32 get_entity_distance_or_default__11TWindowCtrlFiPvUs(s32 arg0, RecoveredFields_8024A688_arg1 *arg1, u16 arg2) {
  f32 temp_f2;
  f32 temp_f3;
  f32 temp_f4;
  u8 *entity;
  if (arg2 == ((-1) & 0xFFFF))
  {
    return lbl_805DCBE0;
  }
  entity = (u8 *) find_entity_by_id(arg2);
  if (entity == 0)
  {
    return lbl_805DCBE0;
  }
  temp_f4 = arg1->field_38 - ((RecoveredFields_8024A688_temp_r3 *) entity)->field_38;
  temp_f3 = arg1->field_3C - ((RecoveredFields_8024A688_temp_r3 *) entity)->field_3C;
  temp_f2 = arg1->field_40 - ((RecoveredFields_8024A688_temp_r3 *) entity)->field_40;
  return (temp_f2 * temp_f2) + ((temp_f4 * temp_f4) + (temp_f3 * temp_f3));
}

s32 TWindowCtrl::find_farthest_balloon_slot(u16 speaker) {
    s32 i;
    s32 result;
    RecoveredFields_8024A688_arg1 *local;
    f32 farthest;
    f32 d;
    TWindowFukidasi *b;
    u16 id;

    local = (RecoveredFields_8024A688_arg1 *)get_player_by_client_id(local_client_id);
    if (local == NULL) {
        return 4;
    }
    result = 4;
    farthest = ((f32 (*)(void *, RecoveredFields_8024A688_arg1 *, u16))get_entity_distance_or_default__11TWindowCtrlFiPvUs)(this, local, speaker);
    for (i = 0; i < 4; i++) {
        b = balloons[i];
        if (b != NULL) {
            id = b->get_speaker_id();
            d = ((f32 (*)(void *, RecoveredFields_8024A688_arg1 *, u16))get_entity_distance_or_default__11TWindowCtrlFiPvUs)(this, local, id);
            if (!(farthest > d)) {
                farthest = d;
                result = i;
            }
        }
    }
    return result;
}

s32 TWindowCtrl::count_balloon_slots() {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (balloons[i] == 0) break;
        n++;
    }
    return n;
}

TWindowFukidasi *TWindowCtrl::acquire_balloon_slot(u16 player, s32 flags, s32 client) {
    f32 f;
    s32 n;
    u32 i;
    TWindowFukidasi *b;
    get_speaker_balloon_anchor(player, &f, &n);
    i = 4;
    if (!(flags & 0x10)) {
        for (i = 0; i < 4; i++) {
            b = balloons[i];
            if (b != 0 && b->all_parents_unqueued_for_destruction() != 0 &&
                player == b->get_speaker_id()) {
                break;
            }
        }
    }
    if (i >= 4) {
        i = count_balloon_slots();
        if (i >= 4) {
            i = find_farthest_balloon_slot(player);
        }
        if (i >= 4) {
            return 0;
        }
        if (balloons[i] != 0) {
            balloons[i]->close();
        }
        b = new TWindowFukidasi(player, n, client, f);
        balloons[i] = b;
    }
    return balloons[i];
}

TWindowFukidasi *TWindowCtrl::show_chat_balloon(u16 player, s32 flags, void *text, s32 client) {
    u32 i;
    if (TWindowCtrl__active_window == NULL) {
        return 0;
    }
    if (flags & 8) {
        for (i = 0; i < 4; i++) {
            TWindowFukidasi *b = balloons[i];
            if (b != 0 && b->all_parents_unqueued_for_destruction() != 0 &&
                player == b->get_speaker_id() &&
                check_card_match_enabled__15TWindowFukidasiFl(b, text) != 0) {
                b->rearm_balloon(flags);
                return 0;
            }
        }
    }
    return ((TWindowCtrl *)TWindowCtrl__active_window)->acquire_balloon_slot(player, flags, client);
}

void TWindowCtrl::handle_chat_message(char *arg1) {
    Obj_8024AA08 *arg0 = (Obj_8024AA08 *)this;
    s32 i;
    u32 key;
    char *v;
    Ply_8024AA08 *p;
    if (TWindowCtrl__active_window != NULL) {
        v = TWindowCtrl::skip_name_prefix(TWindowCtrl__active_window, arg1);
        key = arg0->f4;
        for (i = 0; i < 12; i++) {
            p = (Ply_8024AA08 *)get_player_by_client_id(i);
            if (p != NULL && p->f == key) {
                break;
            }
        }
        if (i < 12) {
            u16 slot = i;
            TOChatSensorCapture::capture_message(slot, v);
            TWindowCtrl::open(slot, (saddr)v, 0xCB);
        }
    }
}

void TLobby__sub_8024AAA0(s32 local_client_id, s32 arg1) {
    u32 temp_r3 = get_window__11TWindowCtrlFl();
    if (temp_r3 != 0U) {
        update_field28__15TWindowCtrlMainFv(temp_r3, arg1);
    }
}
}
