#include "pso/object/TObjWarnChime.h"
#include "pso/TObject.h"
#include "pso/system/vector.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjSoloPlayWin.h"
#include "types.h"
#include "pso/misc/TLobby.h"
#include "pso/TObjChallenge4PRetry.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/map/CurrentArea.h"

struct RecoveredGlobal_80291DC0_lbl_804DB1F0 {
    s32 value;
    u8 remaining[0x6AC];
};

struct RecoveredGlobal_80070ACC_lbl_8048D208 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8039994C_lbl_804F5800 {
    s32 value;
    u8 remaining[0xFC];
};

struct RecoveredGlobal_80399904_lbl_804F5A00 {
    s32 value;
    u8 remaining[0xFC];
};

struct RecoveredGlobal_80399928_lbl_804F5900 {
    s32 value;
    u8 remaining[0xFC];
};

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
int is_multi_ready__6TLobbyFv(void);

void TLobby::update_screen() { if (is_challenge_mode_active(this) != 0) { is_multi_ready__6TLobbyFv(); } }
typedef char RecoveredGlobal_80291DC0_lbl_804DB1F0_size[sizeof(RecoveredGlobal_80291DC0_lbl_804DB1F0) == 0x6B0 ? 1 : -1];
void TLobby::set_challenge_split_flag() {
    if (((s32)is_challenge_mode_active(this)) != 0) {
        *(s32 *)((s8 *)(&(*(RecoveredGlobal_80291DC0_lbl_804DB1F0 *)&lbl_804DB1F0).value) + 0x34) = 1;
    }
}
typedef char RecoveredGlobal_80070ACC_lbl_8048D208_size[sizeof(RecoveredGlobal_80070ACC_lbl_8048D208) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8039994C_lbl_804F5800_size[sizeof(RecoveredGlobal_8039994C_lbl_804F5800) == 0x100 ? 1 : -1];
typedef char RecoveredGlobal_80399904_lbl_804F5A00_size[sizeof(RecoveredGlobal_80399904_lbl_804F5A00) == 0x100 ? 1 : -1];
void TLobby__sub_80291DF8(s32 v) {
    if (((s32 (*)(void))is_challenge_mode_active)() != 0) {
        if (v < 0x3c || v > 0xe10) {
            return;
        }
        (*(G_80070B34 *)&(*(RecoveredGlobal_80291DC0_lbl_804DB1F0 *)&lbl_804DB1F0)).x10 = mix_seed_checked__6TLobbyFi(v);
    }
}
typedef char RecoveredGlobal_80399928_lbl_804F5900_size[sizeof(RecoveredGlobal_80399928_lbl_804F5900) == 0x100 ? 1 : -1];

}

struct RecoveredGlobal_80291EAC_lbl_804DB1F0 {
    s32 value;
    u8 remaining[0x6AC];
};

extern "C" {

#define lbl_804DB1F0 (*(s32 (*)[1])&lbl_804DB1F0)
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
typedef char RecoveredGlobal_80291EAC_lbl_804DB1F0_size[sizeof(RecoveredGlobal_80291EAC_lbl_804DB1F0) == 0x6B0 ? 1 : -1];
void TLobby__sub_80291EAC(s32 arg0) {
    s32 var_r31;
    var_r31 = arg0;
    if (((s32 (*)())is_challenge_mode_active)() == 0) {
        *(s32 *)((s8 *)(&(*(RecoveredGlobal_80291EAC_lbl_804DB1F0 *)&lbl_804DB1F0).value) + 0x2C) = 0;
        return;
    }
    if ((var_r31 != 1) && (var_r31 != 0)) {
        var_r31 = 0;
    }
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_80291EAC_lbl_804DB1F0 *)&lbl_804DB1F0).value) + 0x2C) = var_r31;
}

}

#undef lbl_804DB1F0

#undef is_challenge_mode_active

struct B_80291FC0 {
    u8 pad0[0x1C];
    s32 f1c;
    s32 f20;
    s32 f24;
};

struct RecoveredGlobal_80292574_lbl_804DB1F0 {
    s32 value;
    u8 remaining[0x6AC];
};

struct RecoveredGlobal_80291F9C_lbl_804DB1F0 {
    s32 value;
    u8 remaining[0x6AC];
};

struct RecoveredGlobal_802925C4_lbl_80540968 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_80292200_lbl_804DB1F0 {
    s32 value;
    u8 remaining[0x6AC];
};

struct RecoveredGlobal_80292604_lbl_804DB1F0 {
    s32 value;
    u8 remaining[0x6AC];
};

struct RecoveredGlobal_802924B4_lbl_804DB1F0
{
  s32 value;
  u8 remaining[0x6AC];
};

struct RecoveredGlobal_80070F4C_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct RecoveredGlobal_80070FD8_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct RecoveredGlobal_800713C8_lbl_804FF82C {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80070DA8_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct RecoveredGlobal_80071064_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct RecoveredGlobal_80070EE4_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct RecoveredGlobal_8007119C_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct RecoveredGlobal_800710D8_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
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
s32 strncpy(void *, void *, int);
extern RecoveredGlobal_802925C4_lbl_80540968 split_screen_player_name;
void set_split_screen_name__6TLobbyFi(s32 arg0);
f32 fabs_float(f32);
void TLobby__sub_80292200(s32 arg0);
}
void set_challenge_time_window_timer(int);
#define is_challenge_mode_active ((s32 (*)())is_challenge_mode_active)
extern "C" {
s32 TWindowSubStatusDisp__sub_8006F134(s32, s32);
s32 get_character_save_record(s32);
s32 TLobby__sub_802924B4(s32 arg0, u16 arg1);
u32 get_player_by_client_id(s32);
s32 calc_layout_hash__20TWindowSubStatusDispFv(int);
s32 calc_entry_offset__20TWindowSubStatusDispFv(int);
s32 TLobby__sub_802923C4(s32 idx, s32 value, s32 arg);
s32 is_level_capped__23TAdSinglePlyChrSelectGCFv();
s32 TLobby__sub_80292DA0(s32 seed, u16 card);
#define TLobby__sub_80292DA0 ((s32 (*)(s32, s32))TLobby__sub_80292DA0)
s32 TLobby__sub_80292270(s32 arg0, s32 arg1);
extern s32 lbl_805D6578;
extern s8 lbl_805D657C;
s32 TLobby__sub_8029204C(void);
void TLobby__sub_8026A328(void *);
int TLobby__sub_80292268(void);
#define is_multi_ready__6TLobbyFv ((s32 (*)())is_multi_ready__6TLobbyFv)

void TLobby::draw_if_ready2() {
    extern u32 challenge_retry_object;
    if ((is_challenge_mode_active() != 0) && (is_multi_ready__6TLobbyFv() != 0) && ((u32) challenge_retry_object != 0U)) {
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

typedef char RecoveredGlobal_80291F9C_lbl_804DB1F0_size[sizeof(RecoveredGlobal_80291F9C_lbl_804DB1F0) == 0x6B0 ? 1 : -1];
s32 TLobby__sub_80291F9C(void) {
    if ((s32) *(s32 *)((s8 *)(&(*(RecoveredGlobal_80291F9C_lbl_804DB1F0 *)&lbl_804DB1F0).value) + 0x20) != 0) {
        return *(s32 *)((s8 *)(&(*(RecoveredGlobal_80291F9C_lbl_804DB1F0 *)&lbl_804DB1F0).value) + 0x24);
    }
    return 0;
}

#define G_A lbl_804DB1F0
#define G_B challenge_retry_object
void TLobby::reset_menu_state_globals() {
    extern B_80291FC0 *challenge_retry_object;
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

typedef char RecoveredGlobal_80292200_lbl_804DB1F0_size[sizeof(RecoveredGlobal_80292200_lbl_804DB1F0) == 0x6B0 ? 1 : -1];

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
    if (lbl_805D657C == 0) {
        lbl_805D6578 = TLobby::get_clamped_time_limit() - 1;
        lbl_805D657C = 1;
    }
    best = lbl_805D6578;
    for (i = 0; i < 4; i++) {
        if (arr[i] != 0 && best < arr[i]) {
            best = arr[i];
        }
    }
    if (best == lbl_805D6578) {
        return -2;
    }
    return best;
}

void TLobby::store_challenge_seeds(s32 arg0) {
    s32 i;
    if (is_challenge_mode_active() != 0) {
        for (i = 0; i < 4; i++) {
            if (get_player_by_client_id(i) != 0) {
                s32 v = mix_seed_checked__6TLobbyFi(arg0);
                if (TLobby::is_value_out_of_range(arg0) != 0) {
                    v = mix_seed_checked__6TLobbyFi(0x8C9F);
                }
                (((s32 *)&lbl_804DB1F0) + 0x1A0)[i] = v;
            }
        }
    }
}

void TLobby__sub_80292200(s32 arg0) {
    TLobby::is_value_out_of_range(arg0);
    fabs_float((f32) (arg0 - *(s32 *)((s8 *)(&(*(RecoveredGlobal_80292200_lbl_804DB1F0 *)&lbl_804DB1F0).value) + 0xC)));
    TLobby::store_challenge_seeds(arg0);
}

int TLobby__sub_80292268(void) { return 1; }
typedef char RecoveredGlobal_80292574_lbl_804DB1F0_size[sizeof(RecoveredGlobal_80292574_lbl_804DB1F0) == 0x6B0 ? 1 : -1];

typedef struct RecoveredGlobal_802924B4_lbl_804DB1F0 RecoveredGlobal_802924B4_lbl_804DB1F0;
typedef char RecoveredGlobal_802924B4_lbl_804DB1F0_size[((sizeof(RecoveredGlobal_802924B4_lbl_804DB1F0)) == 0x6B0) ? (1) : (-1)];

typedef char RecoveredGlobal_80070F4C_lbl_8048C9D8_size[sizeof(RecoveredGlobal_80070F4C_lbl_8048C9D8) == 0x748 ? 1 : -1];
typedef char RecoveredGlobal_80070DA8_lbl_8048C9D8_size[sizeof(RecoveredGlobal_80070DA8_lbl_8048C9D8) == 0x748 ? 1 : -1];
typedef char RecoveredGlobal_80070EE4_lbl_8048C9D8_size[sizeof(RecoveredGlobal_80070EE4_lbl_8048C9D8) == 0x748 ? 1 : -1];
typedef char RecoveredGlobal_80070FD8_lbl_8048C9D8_size[sizeof(RecoveredGlobal_80070FD8_lbl_8048C9D8) == 0x748 ? 1 : -1];
typedef char RecoveredGlobal_800713C8_lbl_804FF82C_size[sizeof(RecoveredGlobal_800713C8_lbl_804FF82C) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80071064_lbl_8048C9D8_size[sizeof(RecoveredGlobal_80071064_lbl_8048C9D8) == 0x748 ? 1 : -1];
typedef char RecoveredGlobal_8007119C_lbl_8048C9D8_size[sizeof(RecoveredGlobal_8007119C_lbl_8048C9D8) == 0x748 ? 1 : -1];
typedef char RecoveredGlobal_800710D8_lbl_8048C9D8_size[sizeof(RecoveredGlobal_800710D8_lbl_8048C9D8) == 0x748 ? 1 : -1];
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
    if ((u32)get_character_save_record((u16)card) != 0 && is_level_capped__23TAdSinglePlyChrSelectGCFv() != 0) {
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
    if (idx < 0 || idx >= 3 || value < calc_entry_offset__20TWindowSubStatusDispFv(-1)) {
        return 0;
    }
    if (idx == 0) {
        value = calc_layout_hash__20TWindowSubStatusDispFv(-1);
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

s32 TLobby__sub_802924B4(s32 arg0, u16 arg1) {
  s32 new_var2;
  s32 character_save_record;
  u8 *temp_r30;
  int new_var;
  if ((((s32) (*((s32 *) (((s8 *) (&(*(RecoveredGlobal_802924B4_lbl_804DB1F0 *)&lbl_804DB1F0).value)) + 0x14)))) < 0) || (((s32) (*((s32 *) (((s8 *) (&(*(RecoveredGlobal_802924B4_lbl_804DB1F0 *)&lbl_804DB1F0).value)) + 0x14)))) > 2))
  {
    return 0;
  }
  character_save_record = get_character_save_record((s32) arg1);
  new_var = 0;
  if (character_save_record == new_var)
  {
    return new_var;
  }
  if (((TAdSinglePlyChrSelectGC *)(character_save_record & 0xFFFFFFFFFFFFFFFFu))->register_in_free_room_slot(arg0) != 0)
  {
    temp_r30 = (((u8 *) (&(*(RecoveredGlobal_802924B4_lbl_804DB1F0 *)&lbl_804DB1F0).value)) + ((*((s32 *) (((s8 *) (&(*(RecoveredGlobal_802924B4_lbl_804DB1F0 *)&lbl_804DB1F0).value)) + 0x14))) * 0x1C)) + 0x21C;
    new_var2 = TWindowSubStatusDisp::resolve_player_slot(-1);
    *((s32 *) TWindowSubStatusDisp__sub_8006F134(character_save_record + 0x21C4, new_var2)) |= *((s32 *) (((s8 *) temp_r30) + 4));
    return 1;
  }
  return 0;
  arg0 = arg0;
}

void TLobby::set_encoded_name_and_color(u8 *arg0, s32 arg1) {
    TLobby::encode_name_xor((u8 *)&(*(RecoveredGlobal_80292574_lbl_804DB1F0 *)&lbl_804DB1F0).value + 0x50, arg0, 0xC);
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_80292574_lbl_804DB1F0 *)&lbl_804DB1F0).value) + 0x18) = (s32) (arg1 | 0xFF000000);
}
typedef char RecoveredGlobal_802925C4_lbl_80540968_size[sizeof(RecoveredGlobal_802925C4_lbl_80540968) == 0x20 ? 1 : -1];
void set_split_screen_name__6TLobbyFi(s32 arg0) {
    strncpy((void *)&split_screen_player_name.value, (void *)arg0, 0x20);
    *(s8 *)((s8 *)&split_screen_player_name.value + 0x1F) = 0;
}
typedef char RecoveredGlobal_80292604_lbl_804DB1F0_size[sizeof(RecoveredGlobal_80292604_lbl_804DB1F0) == 0x6B0 ? 1 : -1];
void TLobby::update_challenge_timer(s32 arg0) {
    if (is_challenge_mode_active() != 0) {
        fabs_float((f32) (arg0 - *(s32 *)((s8 *)(&(*(RecoveredGlobal_80292604_lbl_804DB1F0 *)&lbl_804DB1F0).value) + 0xC)));
        *(s32 *)((s8 *)(&(*(RecoveredGlobal_80292604_lbl_804DB1F0 *)&lbl_804DB1F0).value) + 0xC) = arg0;
        set_challenge_time_window_timer(arg0);
    }
}
}

#undef lbl_804DB1F0
#undef is_challenge_mode_active
#undef is_multi_ready__6TLobbyFv
#undef TLobby__sub_80292DA0

struct PBase_80292730 { u8 pad[0x18]; };

struct Pl_80292730 : PBase_80292730 {
    virtual void v0(int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

struct Vec_80292730 { f32 x, y, z; };

struct Hdr_80292730 { u32 w[2]; };

struct Info_80292730 { u8 pad0[0x31]; u8 cls; u8 pad32[2]; u32 flags; u8 pad38[0x50 - 0x38]; };

struct CharData_80292730 { u8 pad0[0x370]; Info_80292730 info; u8 pad3C0[0x41C - 0x3C0]; };

struct Entry_80292730 { s32 val; s32 id; };

struct Tbl_80292730 { s32 f0; s32 f4; s32 f8; Entry_80292730 *entries; };

extern "C" {
Tbl_80292730 *get_stage_table_entry__6TLobbyFll(s32, s32);
void __dt__12TPlyCharDataFv(void *, int);
void copy_player_visual_record(void *, void *);
void __ct__12TPlyCharDataFv(void *);
#define get_player_by_client_id ((Pl_80292730 * (*)(s32))get_player_by_client_id)
Pl_80292730 *create_player_object(s32, s32, void *);
void clamp_and_set_unit_value__10TObjPlayerFiUci(void *, u8, s16);
void begin_action_state__10TObjPlayerFPv(void *);
void send_command__10TNpcPlayerFlScllPSc(u8, s32, s32, s32, void *);
#define is_challenge_mode_active ((s32 (*)())is_challenge_mode_active)

#define lbl_804DB1F0 (*(s32 (*)[1])&lbl_804DB1F0)
extern f32 lbl_805DD9D0;
extern f32 lbl_805DD9D4;

s32 TLobby::set_camera_height_if_valid(f32 farg0) {
    if (is_challenge_mode_active() == 0) {
        return 0;
    }
    if ((farg0 < lbl_805DD9D0) || (farg0 > lbl_805DD9D4)) {
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
    CharData_80292730 cd;
    Info_80292730 info;
    Vec_80292730 pos;
    Hdr_80292730 hdr;
    s32 i;
    Pl_80292730 *p;
    Tbl_80292730 *tbl;
    s32 map;
    Entry_80292730 *e;
    if (arg0 < 0 || arg0 >= 0x10) {
        return;
    }
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        ((TObjPlayer *)(&hdr))->clear_header_struct();
        if (p != NULL) {
            VecCopy((Vec *)&pos, (const Vec *)((u8 *)p + 0x38));
            copy_player_visual_record(&info, (u8 *)p + 0x85C);
            ((TLobby *)(&hdr))->copy_header_struct((u8 *)p + 0xDAC);
            map = ((TRaderMapCore *)p)->get_map_id();
            if (p != NULL) {
                p->v0(1);
            }
            switch (info.flags & 0xE0) {
            case 0x20:
                tbl = get_stage_table_entry__6TLobbyFll(0, arg0);
                break;
            case 0x40:
                tbl = get_stage_table_entry__6TLobbyFll(1, arg0);
                break;
            case 0x80:
                tbl = get_stage_table_entry__6TLobbyFll(2, arg0);
                break;
            default:
                tbl = get_stage_table_entry__6TLobbyFll(0, arg0);
                break;
            }
            __ct__12TPlyCharDataFv(&cd);
            copy_player_visual_record(&cd.info, &info);
            begin_action_state__10TObjPlayerFPv(&cd);
            send_command__10TNpcPlayerFlScllPSc(info.cls, tbl->f4, tbl->f8, tbl->f0, &cd);
            p = create_player_object(i, map, &cd);
            if (p == NULL) {
                __dt__12TPlyCharDataFv(&cd, -1);
                return;
            }
            __dt__12TPlyCharDataFv(&cd, -1);
            ((TLobby *)((u8 *)p + 0xDAC))->copy_header_struct(&hdr);
            ((TUnk_804B9870 *)p)->set_position_from(&pos);
            ((TBoss4DarkFalz *)p)->save_position();
            p->v6();
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

#undef get_player_by_client_id
#undef is_challenge_mode_active
#undef lbl_804DB1F0

struct RecoveredGlobal_80292A34_lbl_804DB1F0 {
    s32 value;
    u8 remaining[0x6AC];
};

struct RecoveredGlobal_8029299C_lbl_804DB1F0 {
    s32 value;
    u8 remaining[0x6AC];
};

struct Ent_80292AB4 { s32 id; s32 mask; u8 pad[0x14]; };

extern "C" {
#define get_player_by_client_id ((u32 (*)(int))get_player_by_client_id)
#define lbl_804DB1F0 (*(s32 (*)[1])&lbl_804DB1F0)
extern u32 challenge_retry_object;
void TLobby__sub_80293218(s32);
s32 TLobby__sub_8029299C(void);
s32 TLobby__sub_80292A34(void);
s32 get_layout_id__20TWindowSubStatusDispFv(s32);
s32 *TWindowSubStatusDisp__sub_8006F0D8(void *, s32);
#define get_character_save_record ((u8 * (*)())get_character_save_record)
s32 count_card_layout_entries__6TLobbyFv(void);
s32 TLobby__sub_80292F34(s32 arg0);
s32 TLobby__sub_80292BB8(s32 seed, u16 card, s32 id);
#define calc_layout_hash__20TWindowSubStatusDispFv ((s32 (*)(s32))calc_layout_hash__20TWindowSubStatusDispFv)
#define calc_entry_offset__20TWindowSubStatusDispFv ((s32 (*)(s32))calc_entry_offset__20TWindowSubStatusDispFv)
#define TWindowSubStatusDisp__sub_8006F134 ((s32 * (*)(u8 *, s32))TWindowSubStatusDisp__sub_8006F134)
s32 TLobby__sub_80292AB4(s32 arg0, s32 arg1, s32 arg2);

void TLobby::clamp_and_store_layout_index(s32 arg0) {
    s32 temp_r3;
    s32 var_r31;

    var_r31 = arg0;
    temp_r3 = get_layout_id__20TWindowSubStatusDispFv(-1);
    if ((var_r31 < 0) || (var_r31 >= temp_r3)) {
        var_r31 = 0;
    }
    lbl_804DB1F0[0] = var_r31;
}
typedef char RecoveredGlobal_80292A34_lbl_804DB1F0_size[sizeof(RecoveredGlobal_80292A34_lbl_804DB1F0) == 0x6B0 ? 1 : -1];

typedef char RecoveredGlobal_8029299C_lbl_804DB1F0_size[sizeof(RecoveredGlobal_8029299C_lbl_804DB1F0) == 0x6B0 ? 1 : -1];
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
        player = (u8 *)(((s32)get_player_by_client_id(var_r30)));
        if ((player != NULL) && (((int)((TLobby *)player)->check_player_state_flag_2()) != 0)) {
            TLobby__sub_80293218((s32) var_r30);
            var_r31 = 1;
        }
        var_r30 += 1;
    } while ((s32) var_r30 < 4);
    if (var_r31 != 0) {
        *(s32 *)((s8 *)(&(*(RecoveredGlobal_8029299C_lbl_804DB1F0 *)&lbl_804DB1F0).value) + 0x20) = 1;
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

#define GCW_80292AB4 ((u8 *(*)(u32))get_character_save_record)
s32 TLobby__sub_80292AB4(s32 arg0, s32 arg1, s32 slot) {
    s32 lo;
    s32 hi;
    s32 *flags;
    s32 i;
    Ent_80292AB4 *e;
    s32 w;
    lo = calc_entry_offset__20TWindowSubStatusDispFv(slot);
    hi = calc_layout_hash__20TWindowSubStatusDispFv(slot);
    if (GCW_80292AB4((u16)arg1) == NULL) {
        return -4;
    }
    if (arg0 < lo || arg0 > hi) {
        return -4;
    }
    w = ((s32 (*)(u32))get_character_save_record)((u16)arg1) + 0x21C4;
    flags = TWindowSubStatusDisp__sub_8006F134((u8 *)w, slot);
    e = (Ent_80292AB4 *)((u8 *)lbl_804DB1F0 + 0x254);
    for (i = 2; i >= 0; i--, e--) {
        if (e->id != 0 && e->id >= arg0) {
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
    s32 layout = get_layout_id__20TWindowSubStatusDispFv(id);
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

s32 count_card_layout_entries__6TLobbyFv(void) {
    u8 *win = get_character_save_record();
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
    layout = get_layout_id__20TWindowSubStatusDispFv(id);
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

#undef get_player_by_client_id
#undef lbl_804DB1F0
#undef get_character_save_record
#undef calc_layout_hash__20TWindowSubStatusDispFv
#undef calc_entry_offset__20TWindowSubStatusDispFv
#undef TWindowSubStatusDisp__sub_8006F134

struct E_80292DA0 {
    s32 a;
    s32 seed;
};

extern "C" {
#define TWindowSubStatusDisp__sub_8006F134 ((E_80292DA0 * (*)(void *, s32))TWindowSubStatusDisp__sub_8006F134)
s32 get_slot_clamped__6TLobbyFv(s32);
s32 mix_seed__6TLobbyFUs(s32);
s32 TWindowSubStatusDisp__sub_80071988(u16, s32);
#define get_character_save_record ((u8 * (*)(u32))get_character_save_record)
#define TLobby__sub_80292AB4 ((s32 (*)(s32, u16, s32))TLobby__sub_80292AB4)
s32 TLobby__sub_80292BB8(s32, u16, s32);
#define lbl_804DB1F0 (*(s32 (*)[1])&lbl_804DB1F0)
#define count_card_layout_entries__6TLobbyFv ((s32 (*)(s32))count_card_layout_entries__6TLobbyFv)
#define get_layout_id__20TWindowSubStatusDispFv ((s32 (*)())get_layout_id__20TWindowSubStatusDispFv)

s32 TLobby::calc_min_challenge_progress() {
    s32 temp_r3;
    s32 var_r31;
    s32 var_r30;

    TWindowSubStatusDisp::resolve_player_slot(-1);
    var_r31 = get_layout_id__20TWindowSubStatusDispFv();
    var_r30 = 0;
    do {
        if (get_player_by_client_id(var_r30) != 0U) {
            temp_r3 = count_card_layout_entries__6TLobbyFv(var_r30);
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
    id = ((s32)TWindowSubStatusDisp::resolve_player_slot(-1));
    result = -4;
    TLobby__sub_80292BB8(seed, card, id);
    total = TWindowSubStatusDisp__sub_80071988(card, id);
    if (total != 0) {
        base = get_character_save_record(card) + 0x21C4;
        total -= TLobby::get_valid_slot(TWindowSubStatusDisp__sub_8006F0D8(base, id)[lbl_804DB1F0[0]]);
        total += seed;
        result = TLobby__sub_80292AB4(total, card, id);
        next = result + 1;
        e = TWindowSubStatusDisp__sub_8006F134(base, id);
        if (get_slot_clamped__6TLobbyFv(e->seed) < next) {
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
#undef get_character_save_record
#undef TLobby__sub_80292AB4
#undef lbl_804DB1F0
#undef count_card_layout_entries__6TLobbyFv
#undef get_layout_id__20TWindowSubStatusDispFv
#define is_challenge_mode_active ((s32 (*)())is_challenge_mode_active)

#define lbl_804DB1F0 (*(s32 (*)[1])&lbl_804DB1F0)

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

#undef is_challenge_mode_active
#undef lbl_804DB1F0

struct RecoveredGlobal_8006F23C_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct G_8006F2CC { u8 pad[0x28]; s32 x28; };

extern "C" {
#define is_challenge_mode_active ((s32 (*)())is_challenge_mode_active)
int TLobby__sub_80292F5C(void* p);
int get_instance__11TCameraCtrlFv(void*);

s32 TLobby::is_value_out_of_range(s32 arg0) {
    if ((arg0 < TLobby::get_clamped_time_limit()) || (arg0 > 0x8C9F)) {
        return 1;
    }
    return 0;
}
s32 TLobby__sub_80292F34(s32 arg0) {
    if ((arg0 < 0x3C) || (arg0 > 0x8C9F)) {
        return 1;
    }
    return 0;
}
int TLobby__sub_80292F5C(void* p) { return get_instance__11TCameraCtrlFv(p); }
#pragma push
#pragma fp_contract on
typedef char RecoveredGlobal_8006F23C_lbl_8048C9D8_size[sizeof(RecoveredGlobal_8006F23C_lbl_8048C9D8) == 0x748 ? 1 : -1];
s32 TLobby::get_challenge_mode_flag() {
    if (is_challenge_mode_active() != 0) {
        return *(s32 *)((s8 *)(&(*(RecoveredGlobal_8006F23C_lbl_8048C9D8 *)&lbl_804DB1F0).value) + 0x34);
    }
    return 0;
}
#pragma pop

void TLobby::start_challenge_countdown() {
    if (is_challenge_mode_active() != 0) {
        switch ((*(G_8006F2CC *)&(*(RecoveredGlobal_8006F23C_lbl_8048C9D8 *)&lbl_804DB1F0)).x28) {
        case 0:
            (*(G_8006F2CC *)&(*(RecoveredGlobal_8006F23C_lbl_8048C9D8 *)&lbl_804DB1F0)).x28 = 1;
            break;
        }
    }
}

#undef is_challenge_mode_active
#define is_challenge_mode_active ((s32 (*)())is_challenge_mode_active)
s32 queue_destruction__7TObjectFv(void*);

#define lbl_804DB1F0 (*(s32 (*)[1])&lbl_804DB1F0)

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
        queue_destruction__7TObjectFv((void*)challenge_retry_object);
    }
}

#undef is_challenge_mode_active
#undef lbl_804DB1F0
extern s32 challenge_mode_active_flag;

s32 is_challenge_mode_active(void) {
    if (((s32) challenge_mode_active_flag == 1) || ((u32) challenge_retry_object != 0U)) {
        return 1;
    }
    return 0;
}

void TLobby__sub_802930A8(void);
void enable_split_screen_challenge_mode(void);

    extern int split_screen_flag;
void TLobby__sub_802930A8(void) { (*(int *)&challenge_mode_active_flag) = 0; split_screen_flag = 0; }

void enable_split_screen_challenge_mode(void) { (*(int *)&challenge_mode_active_flag) = 1; split_screen_flag = 1; }

int TLobby__sub_80293124(void* p);
void *create_challenge4p__6TLobbyFv(void);
struct C_80293720;
C_80293720 *TChallenge4P__ct(C_80293720 *arg0, void *parent);
#define TChallenge4P__ct ((void * (*)(void *, void *))TChallenge4P__ct)
int load_resources__13TObjTombstoneFv(void*);
void *__nw__7TObjectFUl(int);
int destroy__13TObjTombstoneFv(void*);

extern void *tl_su;

void *create_challenge4p__6TLobbyFv(void) {
    void *o = __nw__7TObjectFUl(0x2C);
    if (o != NULL) {
        o = TChallenge4P__ct(o, tl_su);
    }
    return o;
}

int TLobby::destroy_tombstone() { return destroy__13TObjTombstoneFv(this); }
int TLobby__sub_80293124(void* p) { return load_resources__13TObjTombstoneFv(p); }

}

#undef TChallenge4P__ct

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_C { u8 bytes[0xc]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_690 { u8 bytes[0x690]; };

struct RecoveredGlobal_8029379C_lbl_804DAB60 {
    s32 value;
    u8 remaining[0x68C];
};

struct RecoveredGlobal_8029379C_lbl_804DB1F0 {
    s32 value;
    u8 remaining[0x6AC];
};

struct Rec_802934E0 { s32 f; u8 pad[0x100]; };

struct G_802934E0 { u8 pad[0x270]; Rec_802934E0 r[4]; };

struct Rec_80293218 {
    s32 f0;
    u8 pad[0xB0];
    u8 out[0x50];
};

struct G_80293218 {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 pad[0x270 - 0xC];
    Rec_80293218 r[4];
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
struct RecoveredGlobal_80070358_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct Tag_802932EC {
    s8 phase;
    s8 layout;
    s8 slot;
};

struct Rec_802932EC {
    s32 active;
    u8 pad[0xB0];
    Tag_802932EC tag;
    u8 pad2[0x104 - 0xB7];
};

struct G_802932EC {
    s32 layout;
    s32 f4;
    s32 slot;
    u8 pad[0x270 - 0xC];
    Rec_802932EC recs[4];
};

extern "C" {
s32 get_main_phase();
s32 is_split_screen();
s32 queue_destruction__7TObjectFv(void *);
#define get_player_by_client_id ((u32 (*)(u32))get_player_by_client_id)
#define get_character_save_record ((u8 * (*)(s32))get_character_save_record)
void TLobby__sub_80293218(s32 arg0);
void TLobby__sub_800703D0(void *, void *);
void snapshot_player_card_status__6TLobbyFv(void);
s32 get_current_floor(void);
void TLobby__sub_802933FC(void *arg0);
int TAdPlayerLoadGC__sub_801E1510(void);
#define set_split_screen_name__6TLobbyFi ((s32 (*)(void *))set_split_screen_name__6TLobbyFi)
s32 export_character_data__10TObjPlayerFPvPv(u32, u32);
#define create_challenge4p__6TLobbyFv ((u32 (*)())create_challenge4p__6TLobbyFv)

u32 get_char_index__23TAdSinglePlyChrSelectGCFUi(u32);
}
void *create_obj_tag_challenge(void *arg0);
extern s32 tl_07;
void *create_ch_time_win(void *arg0);
void setup_split_screen(void);
extern s32 lbl_80464E58[];
extern s32 lbl_805D6584;

#define challenge_default_settings (*(RecoveredGlobal_8029379C_lbl_804DAB60 *)challenge_default_settings)
#define lbl_804DB1F0 (*(s32 (*)[422])lbl_804DB1F0)

void setup_split_screen(void) {
    u32 var_r31;
    u32 player;
    u32 temp_r4;

    (*(s32 *)&split_screen_flag) = 1;
    lbl_805D6584 = 0;
    if ((u32) challenge_retry_object != 0U) {
        (*(s32 *)&split_screen_flag) = 0;
        return;
    }
    if (is_split_screen() == 0) {
        (*(s32 *)&split_screen_flag) = 0;
        return;
    }
    if ((s32) (*(s32 *)&split_screen_flag) != 0) {
        challenge_retry_object = create_challenge4p__6TLobbyFv();
        lbl_805D6584 = 1;
        (*(s32 *)&split_screen_flag) = 0;
        set_split_screen_name__6TLobbyFi(lbl_80464E58);
        var_r31 = 0U;
        do {
            player = get_player_by_client_id(var_r31);
            temp_r4 = get_char_index__23TAdSinglePlyChrSelectGCFUi(var_r31);
            if ((player != 0U) && (temp_r4 != 0U)) {
                export_character_data__10TObjPlayerFPvPv(player, temp_r4);
            }
            var_r31 += 1;
        } while (var_r31 != 4U);
    }
}
extern "C" {

void TLobby__sub_80293218(s32 arg0) {
    u8 *p = (u8 *)get_player_by_client_id(arg0);
    if (p != NULL) {
        Rec_80293218 *r = &(*(G_80293218 *)&lbl_804DB1F0).r[arg0];
        if (r->f0 != 0) {
            u8 *o = r->out;
            o[0] = TWindowSubStatusDisp::resolve_player_slot(-1);
            o[1] = (*(G_80293218 *)&lbl_804DB1F0).f0;
            o[2] = (*(G_80293218 *)&lbl_804DB1F0).f8;
            VecCopy((Vec *)(o + 4), (const Vec *)(p + 0x38));
            u8 *w = get_character_save_record(arg0) + 0x2274;
            ((TLobby *)w)->copy_struct(o);
        }
    }
}

void TLobby::copy_struct(u8 *arg1) {
    u8 *arg0 = (u8 *)this;
    *(u8 *)&this->m_name = (u8) *(u8 *)((s8 *)arg1 + 0);
    *(u8 *)((s8 *)arg0 + 1) = (u8) *(u8 *)((s8 *)arg1 + 1);
    *(u8 *)((s8 *)arg0 + 2) = (u8) *(u8 *)((s8 *)arg1 + 2);
    *(u8 *)((s8 *)arg0 + 3) = (u8) *(u8 *)((s8 *)arg1 + 3);
    *(ByteBlock_C *)((s32) (u8 *)&this->m_flags) = *(const ByteBlock_C *)((s32) arg1 + 4);
}

void TLobby::spawn_player_tombstones2() {
    s32 i;
    Rec_802932EC *r;
    Tag_802932EC *t;
    TLobby::reset_tombstone_values();
    for (i = 0; i < 4; i++) {
        r = &((G_802932EC *)lbl_804DB1F0)->recs[i];
        if (r->active != 0 && get_player_by_client_id(i) != 0) {
            t = &r->tag;
            if (t->phase == TWindowSubStatusDisp::resolve_player_slot(-1) &&
                t->layout == ((G_802932EC *)lbl_804DB1F0)->layout &&
                t->slot == ((G_802932EC *)lbl_804DB1F0)->slot) {
                TLobby::create_tombstone((void *)tl_07, (void *)i, (void *)t);
            }
        }
    }
}

void TLobby::create_time_window2(void * _w0) {
    TLobby::spawn_player_tombstones2();
    create_ch_time_win((void *)tl_07);
    ((TLobby *)tl_07)->create_new_floor_windows();
    if ((s32) *(s32 *)((s8 *)lbl_804DB1F0 + 0x30) == 0) {
        TObjSoloPlayWin::create((TObject*)tl_07);
    }
}

typedef char RecoveredGlobal_80070358_lbl_8048C9D8_size[sizeof(RecoveredGlobal_80070358_lbl_8048C9D8) == 0x748 ? 1 : -1];
void TLobby__sub_802933FC(void *arg0) {
    s32 old;
    s32 v;
    switch (get_current_area()) {
    case 0:
    case 18:
        old = lbl_804DB1F0[2];
        lbl_804DB1F0[2] = -1;
        if (old != -1) {
            create_obj_tag_challenge((void *)tl_07);
            if (lbl_804DB1F0[8] == 0) {
                create_ch_time_win((void *)tl_07);
            }
        }
        break;
    case 15:
        lbl_804DB1F0[2] = -1;
        break;
    case 16:
    case 17:
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
        if (get_player_by_client_id(i) != 0 && get_character_save_record(i) != NULL) {
            Rec_8029350C *r = &(*(G_8029350C *)&lbl_804DB1F0).r[i];
            r->f0 = 1;
            TLobby__sub_800703D0((u8 *)r + 4, get_character_save_record(i) + 0x21C4);
        }
    }
}

s32 TLobby::check_destruction_by_phase() {
    switch (get_main_phase()) {
    case 15:
        queue_destruction__7TObjectFv(this);
        return 1;
    case 14:
        return is_split_screen() != 1 ? 1 : 0;
    default:
        queue_destruction__7TObjectFv(this);
        return 1;
    }
}

void TLobby::maybe_handle_destruction() { if (check_destruction_by_phase() == 0) { TLobby__sub_802933FC(this); } }

void update_destruction_countdown__6TLobbyFPv(TLobby *lobby) {
    if (TAdPlayerLoadGC__sub_801E1510() != 1) {
        if (lobby->check_destruction_by_phase() == 1) {
            queue_destruction__7TObjectFv(lobby);
        }
        lobby->maybe_handle_destruction();
        *(s32 *)((s8 *)lobby + 0x1C) = (s32) (*(s32 *)((s8 *)lobby + 0x1C) + 1);
    }
}
s32 __dt__7TObjectFv(void *, s32);
s32 __dl__7TObjectFPv(void *);
void *TLobby__sub_802936AC(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void **)((u8 *)arg0 + 0x18) = (void *)lbl_804DB888;
        ((TLobby *)lbl_804DB1F0)->copy_challenge_settings((u8 *)&challenge_default_settings);
        challenge_retry_object = 0;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
struct C_80293720 { s32 f0; u8 pad4[0x14]; void *f18; s32 f1c; s32 f20; s32 f24; s32 f28; };
void __ct__7TObjectFP7TObject(void *, void *);

extern s32 lbl_805D3CA8;
C_80293720 *TChallenge4P__ct(C_80293720 *arg0, void *parent) {
    __ct__7TObjectFP7TObject(arg0, parent);
    arg0->f18 = lbl_804DB888;
    arg0->f0 = lbl_805D3CA8;
    ((TLobby *)lbl_804DB1F0)->copy_challenge_settings((u8 *)&challenge_default_settings);
    ((void (*)(void *))snapshot_player_card_status__6TLobbyFv)(arg0);
    arg0->f1c = 0;
    arg0->f20 = 0;
    arg0->f24 = 1;
    arg0->f28 = 0;
    TObjWarnChime::create((TObject*)arg0);
    return arg0;
}
typedef char RecoveredGlobal_8029379C_lbl_804DAB60_size[sizeof(RecoveredGlobal_8029379C_lbl_804DAB60) == 0x690 ? 1 : -1];
typedef char RecoveredGlobal_8029379C_lbl_804DB1F0_size[sizeof(RecoveredGlobal_8029379C_lbl_804DB1F0) == 0x6B0 ? 1 : -1];
void TLobby::copy_global_value_block() {
    *(ByteBlock_690 *)(&(*(RecoveredGlobal_8029379C_lbl_804DB1F0 *)&lbl_804DB1F0).value) = *(const ByteBlock_690 *)(&challenge_default_settings.value);
}
}

#undef get_player_by_client_id
#undef get_character_save_record
#undef set_split_screen_name__6TLobbyFi
#undef create_challenge4p__6TLobbyFv
__declspec(section ".ctors") static void *const __sinit_TLobby_80291D94_cpp_ref = (void *)TLobby::copy_global_value_block;
