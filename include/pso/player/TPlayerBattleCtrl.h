#ifndef PSO_PLAYER_TPLAYERBATTLECTRL_H
#define PSO_PLAYER_TPLAYERBATTLECTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TPlayerBattleCtrl : public TObject {
public:
    virtual ~TPlayerBattleCtrl();
    void init_battle_round();
    virtual void run_task();
    s32 state_1c;
    s32 state_20;
    s32 state_24;
    u8 unk_28[0x14];
    s32 m_3c;
    u8 unk_40[0xC];
    void *window_4c;
    void *window_50;
    void *window_54;

};

#include <stddef.h>
typedef char TPlayerBattleCtrl_state_1c_offset[offsetof(TPlayerBattleCtrl, state_1c) == 0x1c ? 1 : -1];
typedef char TPlayerBattleCtrl_state_20_offset[offsetof(TPlayerBattleCtrl, state_20) == 0x20 ? 1 : -1];
typedef char TPlayerBattleCtrl_state_24_offset[offsetof(TPlayerBattleCtrl, state_24) == 0x24 ? 1 : -1];
typedef char TPlayerBattleCtrl_window_4c_offset[offsetof(TPlayerBattleCtrl, window_4c) == 0x4c ? 1 : -1];
typedef char TPlayerBattleCtrl_window_50_offset[offsetof(TPlayerBattleCtrl, window_50) == 0x50 ? 1 : -1];
typedef char TPlayerBattleCtrl_window_54_offset[offsetof(TPlayerBattleCtrl, window_54) == 0x54 ? 1 : -1];

#endif
