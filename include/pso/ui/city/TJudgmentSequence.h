#ifndef PSO_UI_CITY_TJUDGMENTSEQUENCE_H
#define PSO_UI_CITY_TJUDGMENTSEQUENCE_H

#include "types.h"
#include "pso/ui/city/TShopSequence.h"

struct TObjPlayer;
class TWindowBase;

struct TJudgmentSequence : public TShopSequence {
    TJudgmentSequence(TObject *parent, TObjPlayer *player);
    virtual ~TJudgmentSequence();
    virtual void restore_player_state();
    void update_state();
    void handle_close_input();
    void handle_confirm();
    void setup_counter_camera();
    static void *create(void *player);
    TWindowBase *m_2c;       // meseta window
    TObject *counter_camera; // 0x30: set_service_counter_camera
    void open_judgment_window();
};

LAYOUT_ASSERT(TJudgmentSequence_size, sizeof(TJudgmentSequence) == 0x34);

// --- C functions defined in TJudgmentSequence.cpp ---
extern "C" {
void TJudgmentSequence__sub_80215BA0(TShopWindowBase *window);
void TJudgmentSequence__sub_80215BCC(TShopWindowBase *window);
void TJudgmentSequence__sub_80215BF8(TShopWindowBase *window);
void TJudgmentSequence__sub_80216030(void);
void TJudgmentSequence__sub_80216058(void);
}

#endif
