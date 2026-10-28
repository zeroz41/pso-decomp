#include "pso/object/TObjWarnChime.h"
#include "pso/TObject.h"
#include "pso/object/TObjSoloPlayWin.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/misc/TChallenge.h"
#include <stddef.h>
#include "pso/misc/TLobby.h"
#include "pso/TObjBagWarnWin.h"
#include "pso/misc/TQuestListOnline.h"
#include "pso/object/TObjTombstone.h"
#include "pso/map/FloorArea.h"
typedef char TChallenge_state_offset[(offsetof(TChallenge, state) == 0x1C) ? 1 : -1];
typedef char TChallenge_frame_offset[(offsetof(TChallenge, frame_count) == 0x20) ? 1 : -1];
typedef char TChallenge_size[(sizeof(TChallenge) == 0x30) ? 1 : -1];

s32 challenge_task;
s32 challenge_task_created;
s32 TLobby__data_805D4E30;

struct RecoveredGlobal_80070358_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct E_8007032C { u8 pad[0x104]; };

struct G_8007032C { u8 pad[0x270]; E_8007032C e[4]; };

struct G_80070024 { u8 pad[0x48]; s32 x48; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Blk5C_800703D0 { u32 w[23]; };

struct Blk50_800703D0 { u32 w[20]; };

struct Blk18_800703D0 { u32 w[6]; };

struct Blk14_800703D0 { u32 w[5]; };

struct Pair_800703D0 { u8 bytes[8]; };

struct Info_800703D0 {
    u16 a;
    s16 b;
    Blk5C_800703D0 c;
    Blk50_800703D0 d;
    Pair_800703D0 xB0;
    Pair_800703D0 xB8;
    Blk18_800703D0 e;
    Pair_800703D0 xD8;
    s32 xE0;
    Pair_800703D0 xE4;
    Blk14_800703D0 f;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_8 { u32 w[2]; };

struct ByteBlock_1C4 { u32 a; struct { u32 w[0x70]; } b; };

struct ByteBlock_10 { u8 bytes[0x10]; };

struct ByteBlock_54 { u8 bytes[0x54]; };

struct ByteBlock_410 { u8 bytes[0x410]; };

struct E_80070254 { u8 pad[0x104]; };

struct G_80070254 { u8 pad[0x270]; E_80070254 e[4]; };

struct L_80070254 { u8 pad[0x24]; s32 x24; };

typedef void (TChallenge::*Step_80070674)(void);
struct Q_80070078 { u8 pad[0x48]; s32 x48; };
struct L_80070078 { u8 pad[0x2C]; s32 x2C; };
extern "C" {
s32 get_character_save_record(u32);
extern s32 local_client_id;
void TLobby__sub_80070358(void);
void clear_four_slots__6TLobbyFv(void);
void TLobby__sub_800738F4(void *, s32);
s32 get_main_phase(void);
void queue_destruction__7TObjectFv(void *);
s32 get_current_floor(void);
}
void *create_obj_tag_challenge(void *arg0);
extern s32 tl_07;
void *create_ch_time_win(void *arg0);
extern "C" {
void TLobby__sub_80070170(void *arg0);
Info_800703D0 *TLobby__sub_800703D0(Info_800703D0 *dst, Info_800703D0 *src);
s32 send_6x7c_reset__6TLobbyFv(void *);
void *get_player_by_client_id(s32 i);
extern void *challenge_mode_state[];
void TLobby__sub_80070254(L_80070254 *arg0);
void render__10TChallengeFv(void);

int is_quest_active(void);
s32 update_card_save_info__6TLobbyFv(void *);
void TLobby__sub_800722AC(s32 arg0);
void TLobby__sub_80072618(void);
s32 TLobby__sub_800739BC(void *);
s32 TLobby__sub_8026A328();
s32 check_player_state_flag_2__6TLobbyFv();

s32 init__23TAdSinglePlyChrSelectGCFv();

extern "C" {
void run_task__10TChallengeFv(TChallenge *);
}
struct Obj_80070774 { u8 pad0[0x18]; void *vt; };
Obj_80070774 *TLobby__sub_80070774(Obj_80070774 *arg0, s16 arg1);
extern "C" {
extern u8 lbl_805D90D0[];
}
extern "C" {
extern u8 lbl_805D90D4[];
}
extern "C" {
extern u8 lbl_805D90D8[];
}
extern "C" {
extern u8 lbl_805D90DC[];
}
extern "C" {
extern u8 lbl_805D90E0[];
}
extern "C" {
extern u8 lbl_805D90E4[];
}
extern "C" {
extern u8 lbl_805D90E8[];
}
extern "C" {
extern u8 lbl_805D90EC[];
}
extern "C" {
extern u8 lbl_805D90F0[];
}
extern "C" {
extern u8 lbl_805D90F4[];
}
extern "C" {
extern u8 lbl_805D90F8[];
}
extern "C" {
extern u8 lbl_805D90FC[];
}
extern "C" {
void render_shadows__7TObjectFv();
}
void *challenge_settings_defaults[420] = {
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
void *challenge_mode_state[420] = {
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
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
};
#define challenge_mode_state (*(s32 (*)[466])challenge_mode_state)

void TLobby::create_time_window(void * _w0) {
    TLobby::spawn_player_tombstones();
    create_ch_time_win((void *)tl_07);
    ((TLobby *)tl_07)->create_new_floor_windows();
    if ((s32) *(s32 *)((s8 *)challenge_mode_state + 0x30) == 0) {
        TObjSoloPlayWin::create((TObject*)tl_07);
    }
}

void TLobby::update_battle_cleanup_flag() {
    if (get_player_by_client_id(local_client_id) == 0U) {
        *(s32 *)((s8 *)this + 0x28) = 0;
        return;
    }
    if (check_player_state_flag_2__6TLobbyFv() != 0) {
        if (((s32) *(s32 *)((s8 *)this + 0x28) != 0) && ((s32) *(s32 *)((s8 *)&challenge_mode_state + 0x34) == 0)) {
            update_card_save_info__6TLobbyFv(this);
            TLobby__sub_800722AC(local_client_id);
            TLobby__sub_80072618();
        }
        *(s32 *)((s8 *)this + 0x28) = 0;
    }
}

typedef char RecoveredGlobal_80070358_lbl_8048C9D8_size[sizeof(RecoveredGlobal_80070358_lbl_8048C9D8) == 0x748 ? 1 : -1];

void TLobby::set_challenge_record_page(s32 v) {
    if (v < 0 || v >= 0x11) {
        return;
    }
    if ((*(G_80070024 *)&challenge_mode_state).x48 != v) {
        TLobby__sub_800738F4(this, v);
        (*(G_80070024 *)&challenge_mode_state).x48 = v;
    }
}

s32 get_selected_quest_id__6TLobbyFv();
extern s32 TLobby__designated_client_id;

#define arg0 ((L_80070078 *)arg0_)
void TLobby::update_quest_challenge_state(void *arg0_) {
    s32 id;
    s32 n;

    n = 0;
    if (local_client_id == TLobby__designated_client_id) {
        switch (TQuestListOnline::get_list_state()) {
        case 1:
            break;
        case 2:
            id = get_selected_quest_id__6TLobbyFv();
            n = 1;
            if (id >= 0x33 && id <= 0x3B) {
                n = id - 0x30;
            }
            break;
        case 3:
            id = get_selected_quest_id__6TLobbyFv();
            n = 2;
            if (id >= 0x3D && id <= 0x41) {
                n = id - 0x31;
            }
            break;
        }
        if (n == 0) {
            if (--arg0->x2C < 0) {
                arg0->x2C = 0;
            }
        } else {
            arg0->x2C = 30;
        }
        if ((arg0->x2C <= 0 || n != 0) && n != ((Q_80070078 *)challenge_mode_state)->x48) {
            TLobby::send_challenge_with_value((s32)arg0, (s32)n);
        }
    }
}
#undef arg0

void TLobby__sub_80070170(void *arg0) {
    s32 old;
    s32 v;
    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1:
    case AREA_PIONEER2_EP2:
        old = challenge_mode_state[2];
        challenge_mode_state[2] = -1;
        if (old != -1) {
            create_obj_tag_challenge((void *)tl_07);
            if (challenge_mode_state[8] == 0) {
                create_ch_time_win((void *)tl_07);
            }
        }
        break;
    case AREA_LOBBY:
        challenge_mode_state[2] = -1;
        break;
    case AREA_BATTLE1:
    case AREA_BATTLE2:
        challenge_mode_state[2] = -1;
        break;
    default:
        v = get_current_floor();
        if (challenge_mode_state[2] != v) {
            challenge_mode_state[2] = v;
            TLobby::create_time_window(arg0);
        }
        break;
    }
}

void TLobby__sub_80070254(L_80070254 *arg0) {
    s32 found;
    s32 i;
    s32 *p;
    found = 0;
    for (i = 0; i < 4; i++) {
        if (i != local_client_id) {
            p = (s32 *)&((G_80070254 *)challenge_mode_state)->e[i];
            if (get_player_by_client_id(i) == 0) {
                if (*p != 0) {
                    *p = 0;
                }
            } else if (*p == 0) {
                found = 1;
            }
        }
    }
    if (found != 0) {
        arg0->x24++;
        if (arg0->x24 % 30 == 0) {
            send_6x7c_reset__6TLobbyFv(arg0);
        }
    } else {
        arg0->x24 = 0;
    }
}

void clear_four_slots__6TLobbyFv(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        *(s32 *)&(*(G_8007032C *)&challenge_mode_state).e[i] = 0;
    }
}

void TLobby__sub_80070358(void) {
    s32 *temp_r31;
    clear_four_slots__6TLobbyFv();
    temp_r31 = (s32 *)((u8 *)(((u8 *)(&(*(RecoveredGlobal_80070358_lbl_8048C9D8 *)&challenge_mode_state).value) + (local_client_id * 0x104))) + 0x270);
    if (get_character_save_record(0xFFFFU) != 0U) {
        *(s32 *)((s8 *)temp_r31 + 0) = 1;
        TLobby__sub_800703D0((Info_800703D0 *)((void *)((void *) ((u8 *)temp_r31 + 4))), (Info_800703D0 *)((void *)((void *) (get_character_save_record(0xFFFFU) + 0x21C4))));
    }
}

Info_800703D0 *TLobby__sub_800703D0(Info_800703D0 *dst, Info_800703D0 *src) {
    *dst = *src;
    return dst;
}

s32 TLobby::destroy_on_phase_change() {
    switch (get_main_phase()) {
    case 15:
        if (get_current_floor_area() == AREA_LOBBY) {
            queue_destruction__7TObjectFv(this);
            return 1;
        }
        break;
    case 14:
        queue_destruction__7TObjectFv(this);
        return 1;
    default:
        queue_destruction__7TObjectFv(this);
        return 1;
    }
    return 0;
}

void TChallenge::render() {  }
void TChallenge::update_active() { void *p = this; if (((TLobby *)p)->destroy_on_phase_change() == 0) { TLobby__sub_80070170(p); ((TLobby *)p)->update_battle_cleanup_flag(); } }
void TChallenge::wait_for_quest() {
    u8 *arg0 = (u8 *)this;
    if (((s32)((TLobby *)arg0)->destroy_on_phase_change()) == 0) {
        TLobby::update_quest_challenge_state(arg0);
        if (is_quest_active() != 0) {
            ((s32)init__23TAdSinglePlyChrSelectGCFv());
            ((s32)TLobby__sub_800739BC(arg0));
            ((s32)TLobby__sub_8026A328());
            TObjWarnChime::create((TObject*)arg0);
            this->state = 2;
        }
    }
}
void TChallenge::initialize_windows() {
    TChallenge *self = this;
    s32 flag = 0;
    switch (get_main_phase()) {
    case 0xf:
        if (get_current_floor_area() != AREA_LOBBY) {
            flag = 1;
        }
        break;
    default:
        flag = 1;
        break;
    }
    if (flag != 0) {
        create_obj_tag_challenge((void *)tl_07);
        TObjBagWarnWin::create((void *)tl_07);
        self->state = 1;
    }
}
s32 TAdPlayerLoadGC__sub_801E1510(void *);

void TChallenge::run_task() {
    TChallenge *self = this;
    if (TAdPlayerLoadGC__sub_801E1510(self) == 1) {
        return;
    }
    TLobby__sub_80070254((L_80070254 *)self);
    static Step_80070674 table[3] = {
        &TChallenge::initialize_windows,
        &TChallenge::wait_for_quest,
        &TChallenge::update_active,
    };
    Step_80070674 step = table[self->state];
    if (step) {
        (self->*step)();
    } else {
        return;
    }
    self->frame_count++;
}

void *lbl_8048D0B0[22] = {
    (void *)0x6368616c, (void *)0x6c656e67, (void *)0x65000000, (void *)0x53004300,
    (void *)0x51000000, (void *)&lbl_805D90D0, (void *)&lbl_805D90D4, (void *)&lbl_805D90D8,
    (void *)&lbl_805D90DC, (void *)&lbl_805D90E0, (void *)&lbl_805D90E4, (void *)&lbl_805D90E8,
    (void *)&lbl_805D90EC, (void *)&lbl_805D90F0, (void *)&lbl_805D90F4, (void *)&lbl_805D90F8,
    (void *)&lbl_805D90FC, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};
void *lbl_8048D108[6] = {
    (void *)0x0, (void *)0x0, (void *)&TLobby__sub_80070774, (void *)&run_task__10TChallengeFv,
    (void *)&render__10TChallengeFv, (void *)&render_shadows__7TObjectFv,
};

void __dt__7TObjectFv(void *, s32);
void __dl__7TObjectFPv(void *);
extern s32 challenge_task;

Obj_80070774 *TLobby__sub_80070774(Obj_80070774 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->vt = lbl_8048D108;
        TObjTombstone::destroy();
        ((void (*)(void *))clear_four_slots__6TLobbyFv)(arg0);
        ((TLobby *)challenge_mode_state)->copy_challenge_settings((u8 *)challenge_settings_defaults);
        challenge_task = 0;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TLobby::copy_challenge_settings(u8 *arg1) {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r6;
    u8 *temp_r8;
    *(s32 *)&this->m_name = (s32) *(s32 *)((s8 *)arg1 + 0);
    *(f32 *)&this->m_flags = (f32) *(f32 *)((s8 *)arg1 + 4);
    *(s32 *)&this->m_prev = (s32) *(s32 *)((s8 *)arg1 + 8);
    *(s32 *)&this->m_next = (s32) *(s32 *)((s8 *)arg1 + 0xC);
    *(s32 *)&this->m_up = (s32) *(s32 *)((s8 *)arg1 + 0x10);
    *(s32 *)&this->m_down = (s32) *(s32 *)((s8 *)arg1 + 0x14);
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) *(s32 *)((s8 *)arg1 + 0x18);
    *(s32 *)((s8 *)arg0 + 0x1C) = (s32) *(s32 *)((s8 *)arg1 + 0x1C);
    *(s32 *)((s8 *)arg0 + 0x20) = (s32) *(s32 *)((s8 *)arg1 + 0x20);
    *(s32 *)((s8 *)arg0 + 0x24) = (s32) *(s32 *)((s8 *)arg1 + 0x24);
    *(s32 *)((s8 *)arg0 + 0x28) = (s32) *(s32 *)((s8 *)arg1 + 0x28);
    *(s32 *)((s8 *)arg0 + 0x2C) = (s32) *(s32 *)((s8 *)arg1 + 0x2C);
    *(s32 *)((s8 *)arg0 + 0x30) = (s32) *(s32 *)((s8 *)arg1 + 0x30);
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)arg1 + 0x34);
    *(ByteBlock_10 *)((s32) arg0 + 0x38) = *(const ByteBlock_10 *)((s32) arg1 + 0x38);
    *(s32 *)((s8 *)arg0 + 0x48) = (s32) *(s32 *)((s8 *)arg1 + 0x48);
    *(s32 *)((s8 *)arg0 + 0x4C) = (s32) *(s32 *)((s8 *)arg1 + 0x4C);
    *(ByteBlock_8 *)((s32) arg0 + 0x50) = *(const ByteBlock_8 *)((s32) arg1 + 0x50);
    {
        const ByteBlock_1C4 *src = (const ByteBlock_1C4 *)(arg1 + 0x58);
        ByteBlock_1C4 *dst = (ByteBlock_1C4 *)(arg0 + 0x58);
        *dst = *src;
    }
    temp_r8 = (arg0 + 0x218);
    temp_r6 = (arg1 + 0x218);
    *(ByteBlock_54 *)((s32) temp_r8 + 4) = *(const ByteBlock_54 *)((s32) temp_r6 + 4);
    *(ByteBlock_410 *)((arg0 + 0x26C) + 4) = *(const ByteBlock_410 *)((arg1 + 0x26C) + 4);
    *(ByteBlock_10 *)((s32) arg0 + 0x680) = *(const ByteBlock_10 *)((s32) arg1 + 0x680);
}

struct Obj_80070944 { s32 f0; u8 pad4[0x14]; void *vt; s32 f1C, f20, f24, f28, f2C; };
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 lbl_805D2850;

Obj_80070944 *TChallenge__ct(Obj_80070944 *arg0, void *parent) {
    __ct__7TObjectFP7TObject(arg0, parent);
    arg0->vt = lbl_8048D108;
    arg0->f0 = lbl_805D2850;
    ((TLobby *)challenge_mode_state)->copy_challenge_settings((u8 *)challenge_settings_defaults);
    ((void (*)(void *))TLobby__sub_80070358)(arg0);
    TLobby::send_challenge_records((u32)arg0);
    arg0->f20 = 0;
    arg0->f24 = 0;
    arg0->f28 = 1;
    arg0->f2C = 0;
    arg0->f1C = 0;
    return arg0;
}
}
