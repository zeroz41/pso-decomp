#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/ui/window/TObjCHTimeWin.h"
#include "pso/object/TObjWarnChime.h"
#include "pso/network/client_id.h"
#include "pso/quest/challenge/ChallengeModeData.h"
#include "pso/unk/text_8026A328.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_80072230.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TObjSoloPlayWin.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/quest/challenge/TChallenge.h"
#include <stddef.h>
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TObjBagWarnWin.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/object/TObjTombstone.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/camera/TCameraCtrl.h"


LAYOUT_ASSERT(TChallenge_state_offset, offsetof(TChallenge, state) == 0x1C);
LAYOUT_ASSERT(TChallenge_frame_offset, offsetof(TChallenge, frame_count) == 0x20);
LAYOUT_ASSERT(TChallenge_size, sizeof(TChallenge) == 0x30);

TChallenge *challenge_task;
s32 challenge_task_created;
s32 TLobby__data_805D4E30;

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

typedef void (TChallenge::*Step_80070674)(void);
struct Q_80070078 { u8 pad[0x48]; s32 x48; };
struct L_80070078 { u8 pad[0x2C]; s32 x2C; };
void *create_obj_tag_challenge(void *arg0);
extern "C" {
Info_800703D0 *copy_challenge_info(Info_800703D0 *dst, Info_800703D0 *src);
void *get_player_by_client_id(s32 i);
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



// lbl_805D2850 holds "TChallenge", the task name (inferred: TChallenge's class name)
extern const char *lbl_805D2850;

#pragma defer_codegen on

TChallenge::TChallenge(TObject *parent) : TObject(parent) {
    m_name = lbl_805D2850;
    ((TLobby *)challenge_mode_state)->copy_challenge_settings((u8 *)challenge_settings_defaults);
    restore_challenge_from_save();
    TLobby::send_challenge_records((uaddr)this);
    frame_count = 0;
    missing_records_timer = 0;
    records_save_pending = 1;
    quest_send_timer = 0;
    state = 0;
}

void TLobby::copy_challenge_settings(u8 *settings) {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r6;
    u8 *temp_r8;
    *(s32 *)&this->m_name = (s32) *(s32 *)((s8 *)settings + 0);
    *(f32 *)&this->m_flags = (f32) *(f32 *)((s8 *)settings + 4);
    *(s32 *)&this->m_prev = (s32) *(s32 *)((s8 *)settings + 8);
    *(s32 *)&this->m_next = (s32) *(s32 *)((s8 *)settings + 0xC);
    *(s32 *)&this->m_up = (s32) *(s32 *)((s8 *)settings + 0x10);
    *(s32 *)&this->m_down = (s32) *(s32 *)((s8 *)settings + 0x14);
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) *(s32 *)((s8 *)settings + 0x18);
    *(s32 *)((s8 *)arg0 + 0x1C) = (s32) *(s32 *)((s8 *)settings + 0x1C);
    *(s32 *)((s8 *)arg0 + 0x20) = (s32) *(s32 *)((s8 *)settings + 0x20);
    *(s32 *)((s8 *)arg0 + 0x24) = (s32) *(s32 *)((s8 *)settings + 0x24);
    *(s32 *)((s8 *)arg0 + 0x28) = (s32) *(s32 *)((s8 *)settings + 0x28);
    *(s32 *)((s8 *)arg0 + 0x2C) = (s32) *(s32 *)((s8 *)settings + 0x2C);
    *(s32 *)((s8 *)arg0 + 0x30) = (s32) *(s32 *)((s8 *)settings + 0x30);
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)settings + 0x34);
    *(ByteBlock_10 *)((saddr) arg0 + 0x38) = *(const ByteBlock_10 *)((saddr) settings + 0x38);
    *(s32 *)((s8 *)arg0 + 0x48) = (s32) *(s32 *)((s8 *)settings + 0x48);
    *(s32 *)((s8 *)arg0 + 0x4C) = (s32) *(s32 *)((s8 *)settings + 0x4C);
    *(ByteBlock_8 *)((saddr) arg0 + 0x50) = *(const ByteBlock_8 *)((saddr) settings + 0x50);
    {
        const ByteBlock_1C4 *src = (const ByteBlock_1C4 *)(settings + 0x58);
        ByteBlock_1C4 *dst = (ByteBlock_1C4 *)(arg0 + 0x58);
        *dst = *src;
    }
    temp_r8 = (arg0 + 0x218);
    temp_r6 = (settings + 0x218);
    *(ByteBlock_54 *)((saddr) temp_r8 + 4) = *(const ByteBlock_54 *)((saddr) temp_r6 + 4);
    *(ByteBlock_410 *)((arg0 + 0x26C) + 4) = *(const ByteBlock_410 *)((settings + 0x26C) + 4);
    *(ByteBlock_10 *)((saddr) arg0 + 0x680) = *(const ByteBlock_10 *)((saddr) settings + 0x680);
}

TChallenge::~TChallenge() {
    TObjTombstone::destroy();
    clear_four_slots();
    ((TLobby *)challenge_mode_state)->copy_challenge_settings((u8 *)challenge_settings_defaults);
    challenge_task = NULL;
}

void TChallenge::run_task() {
    TChallenge *self = this;
    if (TAdPlayerLoadGC__sub_801E1510() == 1) {
        return;
    }
    self->request_missing_challenge_records();
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

void TChallenge::wait_for_quest() {
    u8 *arg0 = (u8 *)this;
    if (((s32)((TLobby *)arg0)->destroy_on_phase_change()) == 0) {
        TLobby::update_quest_challenge_state(arg0);
        if (is_quest_active() != 0) {
            ((s32)TAdSinglePlyChrSelectGC::init());
            clear_challenge_record_window();
            TLobby__sub_8026A328();
            TObjWarnChime::create((TObject*)arg0);
            this->state = 2;
        }
    }
}

void TChallenge::update_active() { void *p = this; if (((TLobby *)p)->destroy_on_phase_change() == 0) { ((TChallenge *)p)->refresh_challenge_windows(); ((TLobby *)p)->update_battle_cleanup_flag(); } }

void TChallenge::render() {  }

s32 TLobby::destroy_on_phase_change() {
    switch (get_main_phase()) {
    case 15:
        if (get_current_floor_area() == AREA_LOBBY) {
            queue_destruction();
            return 1;
        }
        break;
    case 14:
        queue_destruction();
        return 1;
    default:
        queue_destruction();
        return 1;
    }
    return 0;
}

Info_800703D0 *copy_challenge_info(Info_800703D0 *dst, Info_800703D0 *src) {
    *dst = *src;
    return dst;
}

void TChallenge::restore_challenge_from_save() {
    s32 *temp_r31;
    clear_four_slots();
    temp_r31 = (s32 *)((u8 *)(((u8 *)&challenge_mode_state + (local_client_id * 0x104))) + 0x270);
    if (get_character_save_record(0xFFFFU) != 0U) {
        *(s32 *)((s8 *)temp_r31 + 0) = 1;
        copy_challenge_info((Info_800703D0 *)((void *)((void *) ((u8 *)temp_r31 + 4))), (Info_800703D0 *)((void *)((void *) (get_character_save_record(0xFFFFU) + 0x21C4))));
    }
}

void TChallenge::clear_four_slots() {
    s32 i;
    for (i = 0; i < 4; i++) {
        *(s32 *)&(*(G_8007032C *)&challenge_mode_state).e[i] = 0;
    }
}

void TChallenge::request_missing_challenge_records() {
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
        missing_records_timer++;
        if (missing_records_timer % 30 == 0) {
            ((TLobby *)this)->send_6x7c_reset();
        }
    } else {
        missing_records_timer = 0;
    }
}

void TChallenge::refresh_challenge_windows() {
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
                create_ch_time_win((TObject *)tl_07);
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
            TLobby::create_time_window(this);
        }
        break;
    }
}

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
            id = TLobby::get_selected_quest_id();
            n = 1;
            if (id >= 0x33 && id <= 0x3B) {
                n = id - 0x30;
            }
            break;
        case 3:
            id = TLobby::get_selected_quest_id();
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
            TLobby::send_challenge_with_value((saddr)arg0, (s32)n);
        }
    }
}
#undef arg0

void TChallenge::set_challenge_record_page(s32 v) {
    if (v < 0 || v >= 0x11) {
        return;
    }
    if ((*(G_80070024 *)&challenge_mode_state).x48 != v) {
        show_challenge_record_window(v);
        (*(G_80070024 *)&challenge_mode_state).x48 = v;
    }
}

void TLobby::update_battle_cleanup_flag() {
    void *player = get_player_by_client_id(local_client_id);
    if (player == 0U) {
        *(s32 *)((s8 *)this + 0x28) = 0;
        return;
    }
    if (((TLobby *)player)->check_player_state_flag_2() != 0) {
        if (((s32) *(s32 *)((s8 *)this + 0x28) != 0) && ((s32) *(s32 *)((s8 *)&challenge_mode_state + 0x34) == 0)) {
            update_card_save_info();
            TLobby__sub_800722AC(local_client_id);
            TLobby__sub_80072618();
        }
        *(s32 *)((s8 *)this + 0x28) = 0;
    }
}

void TLobby::create_time_window(void * _w0) {
    TLobby::spawn_player_tombstones();
    create_ch_time_win((TObject *)tl_07);
    ((TLobby *)tl_07)->create_new_floor_windows();
    if ((s32) *(s32 *)((s8 *)challenge_mode_state + 0x30) == 0) {
        TObjSoloPlayWin::create((TObject*)tl_07);
    }
}
