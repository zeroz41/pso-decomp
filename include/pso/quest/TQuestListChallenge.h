#ifndef PSO_QUEST_TQUESTLISTCHALLENGE_H
#define PSO_QUEST_TQUESTLISTCHALLENGE_H

#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"

struct TQuestListChallenge : public TShopWindowBase {
    virtual ~TQuestListChallenge();
    u32 m_38;
    u32 m_3c;
    u32 m_40;
    u32 m_44;
    u32 m_48;
    u8 _pad4C[0x4];
    u32 m_50;
    u32 m_54;
    u32 m_58;
    u8 unk_40[0x1C];
};

typedef char TQuestListChallenge_size[sizeof(TQuestListChallenge) == 0x5C ? 1 : -1];

extern "C" {
void *TObjNpcKenkyu__create(void *arg0);
u8 *TQuestListChallenge__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void TQuestListChallenge__vt9(TQuestListChallenge *arg0);
void *__dt__19TQuestListChallengeFv(void *arg0, s16 arg1);
void close_windows__19TQuestListChallengeFPv(void *arg0);
void destroy__19TQuestListChallengeFv(void *arg0);
s32 get_selected_quest_text__19TQuestListChallengeFv(void);
void handle_confirm_select__19TQuestListChallengeFv(void *arg0);
void invoke_callback_and_destroy__19TQuestListChallengeFv(void *arg0);
void reset_globals2__19TQuestListChallengeFv(void);
void reset_globals__19TQuestListChallengeFv(void);
void sub_80288BE4__19TQuestListChallengeFv(void);
}

#endif
