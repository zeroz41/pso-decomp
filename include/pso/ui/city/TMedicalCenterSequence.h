#ifndef PSO_UI_CITY_TMEDICALCENTERSEQUENCE_H
#define PSO_UI_CITY_TMEDICALCENTERSEQUENCE_H

#include "types.h"
#include "pso/ui/city/TShopSequence.h"

struct TMedicalCenterSequence : public TShopSequence {
    virtual ~TMedicalCenterSequence();
    virtual void close_window();
    virtual void restore_player_state();
    void vfunc_11();
    static void clear_window_slots();
    static void clear_slot_data();
    s32 open_greeting_window();
    void handle_confirm();
    void handle_window_result();
    void exec_heal();
    void show_declined();
    void show_already_healthy();
    s32 handle_window_input();
    u8 unk_1C[0x4];
    u32 m_20;
    u8 unk_24[0x8];
    s32 m_2c;
    u32 m_30;
    u8 unk_34[0x4];
    void show_fee_prompt();
};

typedef char TMedicalCenterSequence_size[sizeof(TMedicalCenterSequence) == 0x38 ? 1 : -1];

extern "C" {
void TMedicalCenterMes__sub_80216260(void);
u8 *TMedicalCenterSequence__ct(u8 *medical_center_sequence, s32 arg1, s32 arg2);
u8 *__dt__22TMedicalCenterSequenceFv(TMedicalCenterSequence *arg0, s16 arg1);
}

// --- C functions defined in TMedicalCenterSequence.cpp ---
extern "C" {
void TMedicalCenterMes__sub_80216260(void);
u8 *TMedicalCenterSequence__ct(u8 *medical_center_sequence, s32 arg1, s32 arg2);
u8 *__dt__22TMedicalCenterSequenceFv(TMedicalCenterSequence *arg0, s16 arg1);
}
// --- end of C functions

#endif
