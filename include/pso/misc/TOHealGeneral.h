#ifndef PSO_MISC_TOHEALGENERAL_H
#define PSO_MISC_TOHEALGENERAL_H

#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

struct TOHealGeneral : public TUnk_804AFBF8 {
    virtual ~TOHealGeneral();
    virtual void *get_center();
    u8 unk_C8[0x4];
    u32 m_cc;
    u8 _padD0[0x4];
    void* m_d4;
    u8 _padD8[0x8];
    void* m_e0;
    u8 _padE4[0x8];
    u32 m_ec;
    u32 m_f0;
    u16 m_f4;
    virtual void run_task();
    virtual void render();
    void *create();
    static void close_dialog_window();
    static void load_resources();
    void accept_player(u16 arg1);
    s32 update_active_state();
    void set_enable_count(s32 arg1);
    void set_script_entry(s32 arg1);
    s32 update_heal_gauge_state();
    void update_closing();
    void update_opening();
    void apply_heal_to_target();
    u8 unk_F6[0x2];
};

typedef char TOHealGeneral_size[sizeof(TOHealGeneral) == 0xF8 ? 1 : -1];

extern "C" {
void *TOHealGeneral__ct(void *arg0, void *arg1);
}

#endif
