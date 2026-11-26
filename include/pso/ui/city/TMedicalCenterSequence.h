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
    TWindowBase *meseta_window;       // meseta window
    TWindowMenu *yes_no_menu;       // yes or no
    TObject *counter_camera; // 0x34: set_service_counter_camera
    void show_fee_prompt();
};

LAYOUT_ASSERT(TMedicalCenterSequence_size, sizeof(TMedicalCenterSequence) == 0x38);

// One flag per split-screen slot: set while that player uses the medical center counter.
extern s32 medical_center_slot_active_flags[4];

extern "C" {
void TMedicalCenterMes__sub_80216260(void);
}

// --- C functions defined in TMedicalCenterSequence.cpp ---
extern "C" {
void TMedicalCenterMes__sub_80216260(void);
}

#endif
