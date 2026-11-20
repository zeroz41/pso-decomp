#ifndef PSO_UI_CITY_TJUDGMENTSEQUENCE_H
#define PSO_UI_CITY_TJUDGMENTSEQUENCE_H

#include "types.h"
#include "pso/ui/city/TShopSequence.h"

struct TJudgmentSequence : public TShopSequence {
    TJudgmentSequence(TObject *parent, TObjPlayer *player);
    virtual ~TJudgmentSequence();
    virtual void restore_player_state();
    void vfunc_11();
    void handle_close_input();
    void handle_confirm();
    void setup_counter_camera();
    static void *create(void *arg0);
    s32 m_2c;
    TObject *counter_camera; // 0x30: set_service_counter_camera
    void open_judgment_window();
};

LAYOUT_ASSERT(TJudgmentSequence_size, sizeof(TJudgmentSequence) == 0x34);

extern "C" {
void TJudgmentSequence__sub_80215BA0(void *arg0);
void TJudgmentSequence__sub_80215BCC(void *arg0);
void TJudgmentSequence__sub_80215BF8(void *arg0);
void TJudgmentSequence__sub_80216030(void);
void TJudgmentSequence__sub_80216058(void);
u8 *__dt__17TJudgmentSequenceFv(u8 *arg0, s16 arg1);
}

// --- C functions defined in TJudgmentSequence.cpp ---
extern "C" {
void TJudgmentSequence__sub_80215BA0(void *shop_window_base);
void TJudgmentSequence__sub_80215BCC(void *shop_window_base);
void TJudgmentSequence__sub_80215BF8(void *shop_window_base);
void TJudgmentSequence__sub_80216030(void);
void TJudgmentSequence__sub_80216058(void);
u8 *__dt__17TJudgmentSequenceFv(u8 *arg0, s16 arg1);
}
// --- end of C functions

#endif
