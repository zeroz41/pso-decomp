#define TOBJECT_OUT_OF_LINE_HELPERS
#include <string.h>
#include "pso/ui/window/TObjCHTimeWin.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/object/TObjWarnChime.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_80071774.h"
#include "pso/ui/window/TObjSoloPlayWin.h"
#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/object/TObjChallenge4PRetry.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TObjPlayer_801BDF5C.h"
#include "pso/object/TObjTombstone.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"

struct G_80070B34 { u8 pad[0x10]; s32 x10; };

struct A_80291FC0 {
    u8 pad0[0xC];
    s32 f0c;
    u8 pad10[0x10];
    s32 f20;
    s32 f24;
    s32 f28;
    u8 pad2c[4];
    s32 f30;
    u8 pad34[4];
    s32 a38[4];
    u8 pad48[0x680 - 0x48];
    s32 a680[4];
    u32 tail[2];
};
extern "C" {
void *TLobby__sub_802936AC(void *arg0, s16 arg1);
void update_destruction_countdown__6TLobbyFPv(TLobby *arg0);
void render__7TObjectFv();
void render_shadows__7TObjectFv();
void *challenge_default_settings[420] = {
    (void *)0xffffffff, (void *)0x3f800000, (void *)0xffffffff, (void *)0x0,
    (void *)0x39383814, (void *)0xfffffff6, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
};
A_80291FC0 lbl_804DB1F0[1] = { { {0}, 0, {0}, 0, 0, 0, {0}, 0, {0}, {0}, {0}, {0}, {0x74686542, 0x65737400} } };
void *lbl_804DB888[6] = {
    (void *)0x0, (void *)0x0, (void *)&TLobby__sub_802936AC, (void *)&update_destruction_countdown__6TLobbyFPv,
    (void *)&render__7TObjectFv, (void *)&render_shadows__7TObjectFv,
};
s32 is_challenge_mode_active(void);
#define is_challenge_mode_active ((int (*)(void*))is_challenge_mode_active)
s32 mix_seed_checked__6TLobbyFi(s32);
void TLobby__sub_80291DF8(s32 v);

void TLobby::update_screen() { if (is_challenge_mode_active(this) != 0) { TLobby::is_multi_ready(); } }
void TLobby::set_challenge_split_flag() {
    if (((s32)is_challenge_mode_active(this)) != 0) {
        *(s32 *)((s8 *)&lbl_804DB1F0 + 0x34) = 1;
    }
}
void TLobby__sub_80291DF8(s32 v) {
    if (((s32 (*)(void))is_challenge_mode_active)() != 0) {
        if (v < 0x3c || v > 0xe10) {
            return;
        }
        (*(G_80070B34 *)&lbl_804DB1F0).x10 = mix_seed_checked__6TLobbyFi(v);
    }
}

void TLobby__sub_80291EAC(s32 arg0);
s32 TLobby::get_normalized_mode() {
    if (((s32 (*)())is_challenge_mode_active)() == 0) {
        return 0;
    }
    if (((s32) *(s32 *)((s8 *)lbl_804DB1F0 + 0x2C) != 1) && ((s32) *(s32 *)((s8 *)lbl_804DB1F0 + 0x2C) != 0)) {
        *(s32 *)((s8 *)lbl_804DB1F0 + 0x2C) = 0;
    }
    return *(s32 *)((s8 *)lbl_804DB1F0 + 0x2C);
}
void TLobby__sub_80291EAC(s32 arg0) {
    s32 var_r31;
    var_r31 = arg0;
    if (((s32 (*)())is_challenge_mode_active)() == 0) {
        *(s32 *)((s8 *)&lbl_804DB1F0 + 0x2C) = 0;
        return;
    }
    if ((var_r31 != 1) && (var_r31 != 0)) {
        var_r31 = 0;
    }
    *(s32 *)((s8 *)&lbl_804DB1F0 + 0x2C) = var_r31;
}

}


#undef is_challenge_mode_active

struct B_80291FC0 {
    u8 pad0[0x1C];
    s32 f1c;
    s32 f20;
    s32 f24;
};

struct Entry_800712D8 {
    s32 value;
    s32 arg;
    u8 pad[0x14];
};

struct Table_800712D8 {
    u8 pad[0x21C];
    Entry_800712D8 entries[3];
};

extern "C" {
s32 TLobby__sub_80291F9C(void);
char split_screen_player_name[0x20];
void TLobby__sub_80292200(s32 arg0);
}
void set_challenge_time_window_timer(int);
extern "C" {
saddr TWindowSubStatusDisp__sub_8006F134(s32, s32);
s32 TLobby__sub_802924B4(s32 arg0, u16 arg1);
uaddr get_player_by_client_id(s32);
s32 TLobby__sub_802923C4(s32 idx, s32 value, s32 arg);
s32 TLobby__sub_80292DA0(s32 seed, u16 card);
#define TLobby__sub_80292DA0 ((s32 (*)(s32, s32))TLobby__sub_80292DA0)
s32 TLobby__sub_80292270(s32 arg0, s32 arg1);
s32 TLobby__sub_8029204C(void);
void TLobby__sub_8026A328(void *);
int TLobby__sub_80292268(void);

extern uaddr challenge_retry_object;

void TLobby::draw_if_ready2() {
    if ((is_challenge_mode_active() != 0) && (TLobby::is_multi_ready() != 0) && ((u32) challenge_retry_object != 0U)) {
        TObjChallenge4PRetry::create((void*)challenge_retry_object);
    }
}

s32 TLobby::check_ready_status() {
    s32 var_r3;

    var_r3 = TLobby__sub_80291F9C();
    if (var_r3 == 1) {
        var_r3 = -1;
        if ((s32) *(s32 *)((s8 *)lbl_804DB1F0 + 0x28) != 0) {
            var_r3 = 1;
        }
    }
    return var_r3;
}

s32 TLobby__sub_80291F9C(void) {
    if ((s32) *(s32 *)((s8 *)&lbl_804DB1F0 + 0x20) != 0) {
        return *(s32 *)((s8 *)&lbl_804DB1F0 + 0x24);
    }
    return 0;
}

#define G_A lbl_804DB1F0
#define G_B ((B_80291FC0 *)challenge_retry_object)
void TLobby::reset_menu_state_globals() {
    s32 i;
    s32 z;
    B_80291FC0 *q;
    if (G_B != NULL) {
        G_A->f0c = 0;
        G_A->f20 = 0;
        G_A->f24 = -1;
        G_A->f28 = 0;
        G_A->f30 = 0;
        for (i = 0; i < 4; i++) {
            G_A->a38[i] = 0;
            G_A->a680[i] = 0;
        }
        G_B->f20 = G_B->f1c = 0;
        q = G_B;
        q->f24 = 1;
        TLobby__sub_8026A328(q);
    }
}
#undef G_A
#undef G_B

s32 TLobby__sub_8029204C(void) {
    s32 arr[4];
    s32 i;
    s32 v;
    s32 best;
    for (i = 0; i < 4; i++) {
        arr[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        if (get_player_by_client_id(i) != 0) {
            v = ((s32 *)lbl_804DB1F0)[i + 0x1A0];
            if (v == 0) {
                return -1;
            }
            v = TLobby::get_valid_slot(v);
            if (TLobby::is_value_out_of_range(v) != 0) {
                return -2;
            }
            arr[i] = v;
        }
    }
    static s32 time_limit_floor = TLobby::get_clamped_time_limit() - 1; // inferred: only card values above it count
    best = time_limit_floor;
    for (i = 0; i < 4; i++) {
        if (arr[i] != 0 && best < arr[i]) {
            best = arr[i];
        }
    }
    if (best == time_limit_floor) {
        return -2;
    }
    return best;
}

uaddr challenge_retry_object;
s32 split_screen_challenge_created; // inferred: setup_split_screen sets it once it has created the TChallenge4P
s32 split_screen_flag;
s32 challenge_mode_active_flag;

void TLobby::store_challenge_seeds(s32 seed) {
    s32 i;
    if (is_challenge_mode_active() != 0) {
        for (i = 0; i < 4; i++) {
            if (get_player_by_client_id(i) != 0) {
                s32 v = mix_seed_checked__6TLobbyFi(seed);
                if (TLobby::is_value_out_of_range(seed) != 0) {
                    v = mix_seed_checked__6TLobbyFi(0x8C9F);
                }
                (((s32 *)&lbl_804DB1F0) + 0x1A0)[i] = v;
            }
        }
    }
}

void TLobby__sub_80292200(s32 seed) {
    TLobby::is_value_out_of_range(seed);
    fabs_float((f32) (seed - *(s32 *)((s8 *)&lbl_804DB1F0 + 0xC)));
    TLobby::store_challenge_seeds(seed);
}

int TLobby__sub_80292268(void) { return 1; }

#define TBL_800712D8 (*(Table_800712D8 *)lbl_804DB1F0)

s32 TLobby__sub_80292270(s32 seed, s32 card) {
    s32 r;
    if (is_challenge_mode_active() == 0 || *(s32 *)((s8 *)lbl_804DB1F0 + 0) == -1 ||
        (u32)get_character_save_record((u16)card) == 0) {
        *(s32 *)((s8 *)lbl_804DB1F0 + 0x14) = -4;
        return -4;
    }
    fabs_float(seed - *(s32 *)((s8 *)lbl_804DB1F0 + 0xC));
    if (TLobby::is_value_out_of_range(seed) != 0) {
        seed = 0x8C9F;
    }
    r = TLobby__sub_80292DA0(seed, card);
    if (r == -1) {
        *(s32 *)((s8 *)lbl_804DB1F0 + 0x14) = -1;
        return -1;
    }
    if (r < 0) {
        *(s32 *)((s8 *)lbl_804DB1F0 + 0x14) = -2;
        return -2;
    }
    TAdSinglePlyChrSelectGC *record = (TAdSinglePlyChrSelectGC *)get_character_save_record((u16)card);
    if ((uaddr)record != 0 && record->is_level_capped() != 0) {
        *(s32 *)((s8 *)lbl_804DB1F0 + 0x14) = -3;
        return -3;
    }
    *(s32 *)((s8 *)lbl_804DB1F0 + 0x14) = r;
    return r;
}

s32 TLobby__sub_802923C4(s32 idx, s32 value, s32 arg) {
    s32 prev;
    Entry_800712D8 *e;
    Entry_800712D8 *p;
    Entry_800712D8 *end;
    if (idx < 0 || idx >= 3 || value < TWindowSubStatusDisp::calc_entry_offset(-1)) {
        return 0;
    }
    if (idx == 0) {
        value = TWindowSubStatusDisp::calc_layout_hash(-1);
    }
    e = &TBL_800712D8.entries[idx];
    if (e->value != 0) {
        return 0;
    }
    e->value = value;
    e->arg = arg;
    prev = 0x7FFFFFFF;
    end = &TBL_800712D8.entries[3];
    for (p = TBL_800712D8.entries; p < end; p++) {
        s32 v = p->value;
        if (v != 0) {
            if (prev <= v) {
                return 0;
            }
            prev = v;
        }
    }
    return 1;
}

s32 TLobby__sub_802924B4(s32 arg0, u16 slot_index) {
  s32 new_var2;
  s32 character_save_record;
  u8 *temp_r30;
  int new_var;
  if ((((s32) (*((s32 *) ((s8 *)&lbl_804DB1F0 + 0x14)))) < 0) || (((s32) (*((s32 *) ((s8 *)&lbl_804DB1F0 + 0x14)))) > 2))
  {
    return 0;
  }
  character_save_record = get_character_save_record((s32) slot_index);
  new_var = 0;
  if (character_save_record == new_var)
  {
    return new_var;
  }
  if (((TAdSinglePlyChrSelectGC *)(character_save_record & 0xFFFFFFFFFFFFFFFFu))->register_in_free_room_slot(arg0) != 0)
  {
    temp_r30 = ((u8 *)&lbl_804DB1F0 + ((*((s32 *) ((s8 *)&lbl_804DB1F0 + 0x14))) * 0x1C)) + 0x21C;
    new_var2 = TWindowSubStatusDisp::resolve_player_slot(-1);
    *((s32 *) TWindowSubStatusDisp__sub_8006F134(character_save_record + 0x21C4, new_var2)) |= *((s32 *) (((s8 *) temp_r30) + 4));
    return 1;
  }
  return 0;
  arg0 = arg0;
}

void TLobby::set_encoded_name_and_color(u8 *arg0, s32 arg1) {
    TLobby::encode_name_xor((u8 *)&lbl_804DB1F0 + 0x50, arg0, 0xC);
    *(s32 *)((s8 *)&lbl_804DB1F0 + 0x18) = (s32) (arg1 | 0xFF000000);
}
void TLobby::set_split_screen_name() {
    saddr arg0 = (saddr)this;
    strncpy(split_screen_player_name, (const char *)arg0, 0x20);
    split_screen_player_name[0x1F] = 0;
}
void TLobby::update_challenge_timer(s32 arg0) {
    if (is_challenge_mode_active() != 0) {
        fabs_float((f32) (arg0 - *(s32 *)((s8 *)&lbl_804DB1F0 + 0xC)));
        *(s32 *)((s8 *)&lbl_804DB1F0 + 0xC) = arg0;
        set_challenge_time_window_timer(arg0);
    }
}
}

#undef lbl_804DB1F0
#undef TLobby__sub_80292DA0

struct Hdr_80292730 { u32 w[2]; };

struct Info_80292730 { u8 pad0[0x31]; u8 cls; u8 pad32[2]; u32 flags; u8 pad38[0x50 - 0x38]; };


struct Entry_80292730 { s32 val; s32 id; };

struct Tbl_80292730 { s32 f0; s32 f4; s32 f8; Entry_80292730 *entries; };

extern "C" {
void copy_player_visual_record(void *, void *);
void clamp_and_set_unit_value__10TObjPlayerFiUci(void *, u8, s16);
void send_command__10TNpcPlayerFlScllPSc(u8, s32, s32, s32, void *);


s32 TLobby::set_camera_height_if_valid(f32 farg0) {
    if (is_challenge_mode_active() == 0) {
        return 0;
    }
    if ((farg0 < 0.01f) || (farg0 > 10000.0f)) {
        return 0;
    }
    *(f32 *)((s8 *)&lbl_804DB1F0 + 4) = farg0;
    return 1;
}

extern s32 game_difficulty_selection;

s32 TLobby::try_set_split_screen(s32 arg0) {
    if (is_challenge_mode_active() == 0) {
        return 0;
    }
    game_difficulty_selection = arg0;
    return 1;
}
void TLobby::rebuild_players_for_stage(s32 arg0) {
    Info_80292730 info;
    Vec pos;
    Hdr_80292730 hdr;
    s32 i;
    TObjPlayer *p;
    Tbl_80292730 *tbl;
    s32 map;
    Entry_80292730 *e;
    if (arg0 < 0 || arg0 >= 0x10) {
        return;
    }
    for (i = 0; i < 4; i++) {
        p = (TObjPlayer *)get_player_by_client_id(i);
        ((TObjPlayer *)(&hdr))->clear_header_struct();
        if (p != NULL) {
            VecCopy((Vec *)&pos, (const Vec *)((u8 *)p + 0x38));
            copy_player_visual_record(&info, (u8 *)p + 0x85C);
            ((TLobby *)(&hdr))->copy_header_struct((u8 *)p + 0xDAC);
            map = ((TObjPlayer *)p)->get_controller_port();
            delete p;
            switch (info.flags & 0xE0) {
            case 0x20:
                tbl = (Tbl_80292730 *)TLobby::get_stage_table_entry(0, arg0);
                break;
            case 0x40:
                tbl = (Tbl_80292730 *)TLobby::get_stage_table_entry(1, arg0);
                break;
            case 0x80:
                tbl = (Tbl_80292730 *)TLobby::get_stage_table_entry(2, arg0);
                break;
            default:
                tbl = (Tbl_80292730 *)TLobby::get_stage_table_entry(0, arg0);
                break;
            }
            {
                TPlyCharData cd;
                copy_player_visual_record(&cd.m_disp_part2, &info);
                TObjPlayer::begin_action_state(&cd);
                send_command__10TNpcPlayerFlScllPSc(info.cls, tbl->f4, tbl->f8, tbl->f0, &cd);
                p = (TObjPlayer *)create_player_object(i, map, (u8 *)&cd);
                if (p == NULL) {
                    return;
                }
            }
            ((TLobby *)((u8 *)p + 0xDAC))->copy_header_struct(&hdr);
            p->set_position_from(&pos);
            p->save_previous_position();
            p->reset_motion_fields();
            ((TObjPlayer *)((u8 *)p + 0x428))->set_all_technique_levels((void *)0xFF);
            if (tbl->entries != NULL) {
                for (e = tbl->entries; e->id != 0xFF; e++) {
                    clamp_and_set_unit_value__10TObjPlayerFiUci(p, e->id, e->val);
                }
            }
            *(s32 *)((s8 *)p + 0xD58) = 0;
        }
    }
}

}

struct Ent_80292AB4 { s32 id; s32 mask; u8 pad[0x14]; };

extern "C" {
#define lbl_804DB1F0 (*(s32 (*)[1])&lbl_804DB1F0)
void TLobby__sub_80293218(s32);
s32 TLobby__sub_8029299C(void);
s32 TLobby__sub_80292A34(void);
s32 *TWindowSubStatusDisp__sub_8006F0D8(void *, s32);
s32 TLobby__sub_80292F34(s32 arg0);
s32 TLobby__sub_80292BB8(s32 seed, u16 card, s32 id);
#define TWindowSubStatusDisp__sub_8006F134 ((s32 * (*)(u8 *, s32))TWindowSubStatusDisp__sub_8006F134)
s32 TLobby__sub_80292AB4(s32 arg0, s32 arg1, s32 arg2);

void TLobby::clamp_and_store_layout_index(s32 arg0) {
    s32 temp_r3;
    s32 var_r31;

    var_r31 = arg0;
    temp_r3 = TWindowSubStatusDisp::get_layout_id(-1);
    if ((var_r31 < 0) || (var_r31 >= temp_r3)) {
        var_r31 = 0;
    }
    lbl_804DB1F0[0] = var_r31;
}

s32 TLobby__sub_8029299C(void) {
    s32 var_r31;
    u32 var_r30;
    u8 *player;
    if ((u32) challenge_retry_object == 0U) {
        return 0;
    }
    var_r31 = 0;
    var_r30 = 0;
    do {
        player = (u8 *)(((saddr)get_player_by_client_id(var_r30)));
        if ((player != NULL) && (((int)((TLobby *)player)->check_player_state_flag_2()) != 0)) {
            TLobby__sub_80293218((s32) var_r30);
            var_r31 = 1;
        }
        var_r30 += 1;
    } while ((s32) var_r30 < 4);
    if (var_r31 != 0) {
        *(s32 *)((s8 *)&lbl_804DB1F0 + 0x20) = 1;
        return 1;
    }
    return 0;
}
s32 TLobby__sub_80292A34(void) {
    s32 var_r31;
    u8 *player;
    if ((u32) challenge_retry_object == 0U) {
        return 0;
    }
    var_r31 = 0;
loop_3:
    player = (u8 *)(((u8 *)get_player_by_client_id(var_r31)));
    if ((player != NULL) && (((int)((TLobby *)player)->check_player_state_flag_2()) == 0)) {
        return 0;
    }
    var_r31 += 1;
    if (var_r31 >= 4) {
        *(s32 *)((s8 *)&lbl_804DB1F0 + 0x20) = 1;
        return 1;
    }
    goto loop_3;
}

s32 TLobby__sub_80292AB4(s32 total, s32 card, s32 slot) {
    s32 lo;
    s32 hi;
    s32 *flags;
    s32 i;
    Ent_80292AB4 *e;
    saddr w;
    lo = TWindowSubStatusDisp::calc_entry_offset(slot);
    hi = TWindowSubStatusDisp::calc_layout_hash(slot);
    if (reinterpret_cast<const void *>(get_character_save_record((u16)card)) == NULL) {
        return -4;
    }
    if (total < lo || total > hi) {
        return -4;
    }
    w = get_character_save_record((u16)card) + 0x21C4;
    flags = TWindowSubStatusDisp__sub_8006F134((u8 *)w, slot);
    e = (Ent_80292AB4 *)((u8 *)lbl_804DB1F0 + 0x254);
    for (i = 2; i >= 0; i--, e--) {
        if (e->id != 0 && e->id >= total) {
            if (e->id < lo || e->id > hi) {
                return -4;
            }
            if ((*flags & e->mask) == 0) {
                break;
            }
        }
    }
    if (i < 0) {
        return -2;
    }
    return i;
}

s32 TLobby__sub_80292BB8(s32 seed, u16 card, s32 id) {
    u8 *win = ((u8 *(*)(u32))get_character_save_record)(card);
    s32 layout = TWindowSubStatusDisp::get_layout_id(id);
    s32 *arr;
    s32 idx;
    s32 limit;
    s32 ok;
    if (win == NULL || lbl_804DB1F0[0] < 0 || lbl_804DB1F0[0] >= layout) {
        return 0;
    }
    arr = TWindowSubStatusDisp__sub_8006F0D8(win + 0x21C4, id);
    ok = 0;
    idx = lbl_804DB1F0[0] * 4;
    if (*(s32 *)((u8 *)arr + idx) == 0) {
        ok = 1;
    } else {
        limit = TLobby::get_valid_slot(*(s32 *)((u8 *)arr + idx));
        if (TLobby__sub_80292F34(limit) != 0) {
            *(s32 *)((u8 *)arr + idx) = 0;
            return 0;
        }
        if (seed < limit) {
            ok = 1;
        }
    }
    if (ok == 0) {
        return 0;
    }
    *(s32 *)((u8 *)arr + idx) = mix_seed_checked__6TLobbyFi(seed);
    return 1;
}

s32 count_card_layout_entries(s32 client) {
    u8 *win = (u8 *)get_character_save_record(client);
    s32 layout;
    s32 id;
    s32 *arr;
    s32 n;
    s32 i;
    if (win == NULL) {
        return 0;
    }
    id = TWindowSubStatusDisp::resolve_player_slot(-1);
    arr = TWindowSubStatusDisp__sub_8006F0D8(win + 0x21C4, id);
    layout = TWindowSubStatusDisp::get_layout_id(id);
    n = 0;
    for (i = 0; i < layout; i++) {
        if (arr[i] == 0) {
            break;
        }
        n++;
    }
    return n;
}

}

#undef lbl_804DB1F0
#undef get_character_save_record
#undef TWindowSubStatusDisp__sub_8006F134

struct E_80292DA0 {
    s32 a;
    s32 seed;
};

extern "C" {
#define TWindowSubStatusDisp__sub_8006F134 ((E_80292DA0 * (*)(void *, s32))TWindowSubStatusDisp__sub_8006F134)
s32 mix_seed__6TLobbyFUs(s32);
#define TLobby__sub_80292AB4 ((s32 (*)(s32, u16, s32))TLobby__sub_80292AB4)
s32 TLobby__sub_80292BB8(s32, u16, s32);
#define lbl_804DB1F0 (*(s32 (*)[1])&lbl_804DB1F0)
#define count_card_layout_entries__6TLobbyFv ((s32 (*)(s32))count_card_layout_entries__6TLobbyFv)

s32 TLobby::calc_min_challenge_progress() {
    s32 temp_r3;
    s32 var_r31;
    s32 var_r30;

    var_r31 = TWindowSubStatusDisp::get_layout_id(TWindowSubStatusDisp::resolve_player_slot(-1));
    var_r30 = 0;
    do {
        if (get_player_by_client_id(var_r30) != 0U) {
            temp_r3 = count_card_layout_entries(var_r30);
            if (var_r31 > temp_r3) {
                var_r31 = temp_r3;
            }
        }
        var_r30 += 1;
    } while (var_r30 < 4);
    return var_r31;
}
s32 TLobby__sub_80292DA0(s32 seed, u16 card) {
    s32 result;
    s32 total;
    s32 id;
    u8 *base;
    s32 next;
    E_80292DA0 *e;
    id = TWindowSubStatusDisp::resolve_player_slot(TWindowSubStatusDisp::RECORD_SET_CURRENT);
    result = -4;
    TLobby__sub_80292BB8(seed, card, id);
    total = TWindowSubStatusDisp__sub_80071988(card, id);
    if (total != 0) {
        base = (u8 *)get_character_save_record(card) + 0x21C4;
        total -= TLobby::get_valid_slot(TWindowSubStatusDisp__sub_8006F0D8(base, id)[lbl_804DB1F0[0]]);
        total += seed;
        result = TLobby__sub_80292AB4(total, card, id);
        next = result + 1;
        e = TWindowSubStatusDisp__sub_8006F134(base, id);
        if ((s32)TLobby::get_slot_clamped((u32)(e->seed)) < next) {
            e->seed = mix_seed__6TLobbyFUs(next);
        }
    }
    {
        s32 r = result;
        if (total == 0) {
            r = -1;
        }
        return r;
    }
}

#undef TWindowSubStatusDisp__sub_8006F134
#undef TLobby__sub_80292AB4
#undef lbl_804DB1F0
#undef count_card_layout_entries__6TLobbyFv


s32 TLobby::get_clamped_time_limit() {
    s32 valid_slot;

    if (is_challenge_mode_active() == 0) {
        return 0x12C;
    }
    valid_slot = TLobby::get_valid_slot(*(s32 *)((s8 *)lbl_804DB1F0 + 0x10));
    if ((valid_slot < 0x3C) || (valid_slot > 0xE10)) {
        valid_slot = 0x12C;
    }
    return valid_slot;
}

}


struct G_8006F2CC { u8 pad[0x28]; s32 x28; };

extern "C" {
int TLobby__sub_80292F5C(void* p);

s32 TLobby::is_value_out_of_range(s32 seed) {
    if ((seed < TLobby::get_clamped_time_limit()) || (seed > 0x8C9F)) {
        return 1;
    }
    return 0;
}
s32 TLobby__sub_80292F34(s32 limit) {
    if ((limit < 0x3C) || (limit > 0x8C9F)) {
        return 1;
    }
    return 0;
}
int TLobby__sub_80292F5C(void* p) { return TCameraCtrl::get_view_count(); }
#pragma push
#pragma fp_contract on
s32 TLobby::get_challenge_mode_flag() {
    if (is_challenge_mode_active() != 0) {
        return *(s32 *)((s8 *)&lbl_804DB1F0 + 0x34);
    }
    return 0;
}
#pragma pop

void TLobby::start_challenge_countdown() {
    if (is_challenge_mode_active() != 0) {
        switch ((*(G_8006F2CC *)&lbl_804DB1F0).x28) {
        case 0:
            (*(G_8006F2CC *)&lbl_804DB1F0).x28 = 1;
            break;
        }
    }
}


void TLobby::set_retry_selection(s32 arg0) {
    s32 var_r31;

    var_r31 = arg0;
    if (is_challenge_mode_active() != 0) {
        if ((var_r31 < 0) || (var_r31 > 1)) {
            var_r31 = 0;
        }
        *(s32 *)((s8 *)lbl_804DB1F0 + 0x24) = var_r31;
    }
}

void TLobby::destroy_global() {
    if ((u32) challenge_retry_object != 0U) {
        ((TObject *)challenge_retry_object)->queue_destruction();
    }
}

s32 is_challenge_mode_active(void) {
    if ((challenge_mode_active_flag == 1) || ((u32) challenge_retry_object != 0U)) {
        return 1;
    }
    return 0;
}

void TLobby__sub_802930A8(void);
void enable_split_screen_challenge_mode(void);

void TLobby__sub_802930A8(void) { challenge_mode_active_flag = 0; split_screen_flag = 0; }

void enable_split_screen_challenge_mode(void) { challenge_mode_active_flag = 1; split_screen_flag = 1; }

int TLobby__sub_80293124(void* p);
void *create_challenge4p__6TLobbyFv(void);
struct C_80293720;
C_80293720 *TChallenge4P__ct(C_80293720 *arg0, void *parent);
#define TChallenge4P__ct ((void * (*)(void *, void *))TChallenge4P__ct)
int load_resources__13TObjTombstoneFv(void*);

extern void *tl_su;

const char *TChallenge4P__class_name = "TChallenge4P";

void *create_challenge4p__6TLobbyFv(void) {
    void *o = TObject::operator new(0x2C);
    if (o != NULL) {
        o = TChallenge4P__ct(o, tl_su);
    }
    return o;
}

void TLobby::destroy_tombstone() { TObjTombstone::destroy(); }
int TLobby__sub_80293124(void* p) { return load_resources__13TObjTombstoneFv(p); }

}

#undef TChallenge4P__ct

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_690 { u8 bytes[0x690]; };

struct Rec_802934E0 { s32 f; u8 pad[0x100]; };

struct G_802934E0 { u8 pad[0x270]; Rec_802934E0 r[4]; };

struct G_80293218 {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 pad[0x270 - 0xC];
    ChallengeTombstonePlayerSlot r[4];
};

struct Rec_8029350C {
    s32 f0;
    u8 pad[0x100];
};

struct G_8029350C {
    u8 pad[0x270];
    Rec_8029350C r[4];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct G_802932EC {
    s32 layout;
    s32 f4;
    s32 slot;
    u8 pad[0x270 - 0xC];
    ChallengeTombstonePlayerSlot recs[4];
};

extern "C" {
void TLobby__sub_80293218(s32 arg0);
void copy_challenge_info(void *, void *);
void snapshot_player_card_status__6TLobbyFv(void);
void TLobby__sub_802933FC(void *arg0);
s32 export_character_data__10TObjPlayerFPvPv(u32, u32);
#define create_challenge4p__6TLobbyFv ((u32 (*)())create_challenge4p__6TLobbyFv)

}
void *create_obj_tag_challenge(void *arg0);
extern saddr tl_07;
void setup_split_screen(void);

#define lbl_804DB1F0 (*(s32 (*)[422])lbl_804DB1F0)

void setup_split_screen(void) {
    u32 var_r31;
    u32 player;
    u32 temp_r4;

    split_screen_flag = 1;
    split_screen_challenge_created = 0;
    if ((u32) challenge_retry_object != 0U) {
        split_screen_flag = 0;
        return;
    }
    if (is_split_screen() == 0) {
        split_screen_flag = 0;
        return;
    }
    if (split_screen_flag != 0) {
        challenge_retry_object = create_challenge4p__6TLobbyFv();
        split_screen_challenge_created = 1;
        split_screen_flag = 0;
        ((TLobby *)((saddr)"Area00"))->set_split_screen_name();
        var_r31 = 0U;
        do {
            player = get_player_by_client_id(var_r31);
            temp_r4 = (u32)TAdSinglePlyChrSelectGC::get_char_index(var_r31);
            if ((player != 0U) && (temp_r4 != 0U)) {
                export_character_data__10TObjPlayerFPvPv(player, temp_r4);
            }
            var_r31 += 1;
        } while (var_r31 != 4U);
    }
}
extern "C" {

void TLobby__sub_80293218(s32 arg0) {
    TObjPlayer *p = reinterpret_cast<TObjPlayer *>(get_player_by_client_id(arg0));
    if (p != NULL) {
        ChallengeTombstonePlayerSlot *r = &(*(G_80293218 *)&lbl_804DB1F0).r[arg0];
        if (r->active != 0) {
            TObjTombstoneSpot *spot = &r->spot;
            spot->phase = TWindowSubStatusDisp::resolve_player_slot(-1);
            spot->layout = (*(G_80293218 *)&lbl_804DB1F0).f0;
            spot->floor = (*(G_80293218 *)&lbl_804DB1F0).f8;
            VecCopy(&spot->position, &p->position);
            u8 *w = reinterpret_cast<u8 *>(get_character_save_record(arg0)) + 0x2274;
            copy_tombstone_spot(reinterpret_cast<TObjTombstoneSpot *>(w), spot);
        }
    }
}

#pragma push
#pragma scheduling off
extern "C++" void copy_tombstone_spot(TObjTombstoneSpot *destination, const TObjTombstoneSpot *source) {
    volatile TObjTombstoneSpot *output = destination;
    const volatile TObjTombstoneSpot *input = source;
    output->phase = input->phase;
    output->layout = input->layout;
    output->floor = input->floor;
    output->unk_3 = input->unk_3;
#ifdef __MWERKS__
    __memcpy(&destination->position, &source->position, sizeof(Vec));
#else
    destination->position = source->position;
#endif
}

#pragma pop

void TLobby::spawn_player_tombstones2() {
    saddr i;
    ChallengeTombstonePlayerSlot *r;
    const TObjTombstoneSpot *t;
    TLobby::reset_tombstone_values();
    for (i = 0; i < 4; i++) {
        r = &((G_802932EC *)lbl_804DB1F0)->recs[i];
        if (r->active != 0 && get_player_by_client_id(i) != 0) {
            t = &r->spot;
            if (t->phase == TWindowSubStatusDisp::resolve_player_slot(-1) &&
                t->layout == ((G_802932EC *)lbl_804DB1F0)->layout &&
                t->floor == ((G_802932EC *)lbl_804DB1F0)->slot) {
                TLobby::create_tombstone(reinterpret_cast<TObject *>(tl_07), i, t);
            }
        }
    }
}

void TLobby::create_time_window2(void * _w0) {
    TLobby::spawn_player_tombstones2();
    create_ch_time_win((TObject *)tl_07);
    ((TLobby *)tl_07)->create_new_floor_windows();
    if ((s32) *(s32 *)((s8 *)lbl_804DB1F0 + 0x30) == 0) {
        TObjSoloPlayWin::create((TObject*)tl_07);
    }
}

void TLobby__sub_802933FC(void *arg0) {
    s32 old;
    s32 v;
    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1:
    case AREA_PIONEER2_EP2:
        old = lbl_804DB1F0[2];
        lbl_804DB1F0[2] = -1;
        if (old != -1) {
            create_obj_tag_challenge((void *)tl_07);
            if (lbl_804DB1F0[8] == 0) {
                create_ch_time_win((TObject *)tl_07);
            }
        }
        break;
    case AREA_LOBBY:
        lbl_804DB1F0[2] = -1;
        break;
    case AREA_BATTLE1:
    case AREA_BATTLE2:
        lbl_804DB1F0[2] = -1;
        break;
    default:
        v = get_current_floor();
        if (lbl_804DB1F0[2] != v) {
            lbl_804DB1F0[2] = v;
            TLobby::create_time_window2(arg0);
        }
        break;
    }
}

void TLobby::clear_card_status_flags() {
    s32 i;
    for (i = 0; i < 4; i++) (*(G_802934E0 *)&lbl_804DB1F0).r[i].f = 0;
}

void snapshot_player_card_status__6TLobbyFv(void) {
    s32 i;
    TLobby::clear_card_status_flags();
    for (i = 0; i < 4; i++) {
        if (get_player_by_client_id(i) != 0 && (u8 *)get_character_save_record(i) != NULL) {
            Rec_8029350C *r = &(*(G_8029350C *)&lbl_804DB1F0).r[i];
            r->f0 = 1;
            copy_challenge_info((u8 *)r + 4, (u8 *)get_character_save_record(i) + 0x21C4);
        }
    }
}

s32 TLobby::check_destruction_by_phase() {
    switch (get_main_phase()) {
    case 15:
        queue_destruction();
        return 1;
    case 14:
        return is_split_screen() != 1 ? 1 : 0;
    default:
        queue_destruction();
        return 1;
    }
}

void TLobby::maybe_handle_destruction() { if (check_destruction_by_phase() == 0) { TLobby__sub_802933FC(this); } }

void update_destruction_countdown__6TLobbyFPv(TLobby *lobby) {
    if (fn_801E1510() != 1) {
        if (lobby->check_destruction_by_phase() == 1) {
            lobby->queue_destruction();
        }
        lobby->maybe_handle_destruction();
        *(s32 *)((s8 *)lobby + 0x1C) = (s32) (*(s32 *)((s8 *)lobby + 0x1C) + 1);
    }
}
s32 __dt__7TObjectFv(void *, s32);
void *TLobby__sub_802936AC(void *object, s16 arg1) {
    if (object != NULL) {
        *(void **)((u8 *)object + 0x18) = (void *)lbl_804DB888;
        ((TLobby *)lbl_804DB1F0)->copy_challenge_settings((u8 *)&challenge_default_settings);
        challenge_retry_object = 0;
        __dt__7TObjectFv(object, 0);
        if (arg1 > 0) {
            TObject::operator delete(object);
        }
    }
    return object;
}
struct C_80293720 { const char *m_name; u8 pad4[0x14]; void *f18; s32 f1c; s32 f20; s32 f24; s32 f28; };
void __ct__7TObjectFP7TObject(void *, void *);

C_80293720 *TChallenge4P__ct(C_80293720 *arg0, void *parent) {
    __ct__7TObjectFP7TObject(arg0, parent);
    arg0->f18 = lbl_804DB888;
    arg0->m_name = TChallenge4P__class_name;
    ((TLobby *)lbl_804DB1F0)->copy_challenge_settings((u8 *)&challenge_default_settings);
    ((void (*)(void *))snapshot_player_card_status__6TLobbyFv)(arg0);
    arg0->f1c = 0;
    arg0->f20 = 0;
    arg0->f24 = 1;
    arg0->f28 = 0;
    TObjWarnChime::create((TObject*)arg0);
    return arg0;
}
void TLobby::copy_global_value_block() {
    *(ByteBlock_690 *)&lbl_804DB1F0 = *(const ByteBlock_690 *)&challenge_default_settings;
}
}

#undef create_challenge4p__6TLobbyFv
__declspec(section ".ctors") static void *const __sinit_TLobby_80291D94_cpp_ref = (void *)TLobby::copy_global_value_block;
