#ifndef PSO_UI_CITY_TJUDGMENTSEQUENCE_H
#define PSO_UI_CITY_TJUDGMENTSEQUENCE_H

#include "types.h"
#include "pso/ui/city/TShopSequence.h"

struct TObjPlayer;
class TWindowBase;

struct TJudgmentSequence : public TShopSequence {
    static const char *class_name;
    static s32 slot_flags[4];
    TJudgmentSequence(TObject *parent, TObjPlayer *player);
    virtual ~TJudgmentSequence();
    virtual void restore_player_state();
    void update_state();
    void handle_close_input();
    void handle_confirm();
    void setup_counter_camera();
    static void *create(void *player);
    TWindowBase *meseta_window;       // meseta window
    TObject *counter_camera; // 0x30: set_service_counter_camera
    void open_judgment_window();
    static void on_judgment_closed(TShopWindowBase *window);
    static void on_judgment_cancelled(TShopWindowBase *window);
    static void release_slot_flags();
    static void init_slot_flags();
};

LAYOUT_ASSERT(TJudgmentSequence_size, sizeof(TJudgmentSequence) == 0x34);

// --- C functions defined in TJudgmentSequence.cpp ---
extern "C" {
void TJudgmentSequence__sub_80215BCC(TShopWindowBase *window);
}

#endif
