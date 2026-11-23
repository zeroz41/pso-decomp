#ifndef PSO_PLAYER_TPLAYERBATTLECTRL_H
#define PSO_PLAYER_TPLAYERBATTLECTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TPlayerBattleCtrl : public TObject {
public:
    TPlayerBattleCtrl(TObject *parent);
    virtual ~TPlayerBattleCtrl();
    void init_battle_round();
    virtual void run_task();
    s32 state_1c;
    s32 state_20;
    s32 state_24;
    s32 unk_28;
    u8 pad_2c[0x10];
    s32 m_3c;
    u8 *text;
    u8 pad_44[0x8];
    void *window_4c;
    void *window_50;
    void *window_54;
    u8 pad_58[0xC];
    s32 pad_64;
    u8 pad_68[0x210];
};

#include <stddef.h>
LAYOUT_ASSERT(TPlayerBattleCtrl_state_1c_offset, offsetof(TPlayerBattleCtrl, state_1c) == 0x1c);
LAYOUT_ASSERT(TPlayerBattleCtrl_state_20_offset, offsetof(TPlayerBattleCtrl, state_20) == 0x20);
LAYOUT_ASSERT(TPlayerBattleCtrl_state_24_offset, offsetof(TPlayerBattleCtrl, state_24) == 0x24);
LAYOUT_ASSERT(TPlayerBattleCtrl_window_4c_offset, offsetof(TPlayerBattleCtrl, window_4c) == 0x4c);
LAYOUT_ASSERT(TPlayerBattleCtrl_window_50_offset, offsetof(TPlayerBattleCtrl, window_50) == 0x50);
LAYOUT_ASSERT(TPlayerBattleCtrl_window_54_offset, offsetof(TPlayerBattleCtrl, window_54) == 0x54);
LAYOUT_ASSERT(TPlayerBattleCtrl_size, sizeof(TPlayerBattleCtrl) == 0x278);

#endif
