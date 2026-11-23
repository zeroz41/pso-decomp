#ifndef PSO_UI_CITY_TMEDICALCENTERSEQUENCE_H
#define PSO_UI_CITY_TMEDICALCENTERSEQUENCE_H

#include "types.h"
#include "pso/ui/city/TShopSequence.h"

struct TObjPlayer;
class TWindowBase;
struct TWindowMenu;

struct TMedicalCenterSequence : public TShopSequence {
    TMedicalCenterSequence(TObject *parent, TObjPlayer *player);
    virtual ~TMedicalCenterSequence();
    virtual void close_window();
    virtual void restore_player_state();
    void update_state();
    static void clear_window_slots();
    static void clear_slot_data();
    void open_greeting_window();
    void handle_confirm();
    void handle_window_result();
    void exec_heal();
    void show_declined();
    void show_already_healthy();
    void handle_window_input();
    TWindowBase *m_2c;       // meseta window
    TWindowMenu *m_30;       // yes or no
    TObject *counter_camera; // 0x34: set_service_counter_camera
    void show_fee_prompt();
};

LAYOUT_ASSERT(TMedicalCenterSequence_size, sizeof(TMedicalCenterSequence) == 0x38);

extern "C" {
void TMedicalCenterMes__sub_80216260(void);
u8 *__dt__22TMedicalCenterSequenceFv(TMedicalCenterSequence *arg0, s16 arg1);
}

// --- C functions defined in TMedicalCenterSequence.cpp ---
extern "C" {
void TMedicalCenterMes__sub_80216260(void);
u8 *__dt__22TMedicalCenterSequenceFv(TMedicalCenterSequence *arg0, s16 arg1);
}

#endif
