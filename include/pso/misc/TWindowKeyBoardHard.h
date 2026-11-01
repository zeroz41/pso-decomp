#ifndef PSO_MISC_TWINDOWKEYBOARDHARD_H
#define PSO_MISC_TWINDOWKEYBOARDHARD_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct TWindowKeyBoardHard : public TWindowBase {
    virtual ~TWindowKeyBoardHard();
    void draw_status_text(void *);
    void update_modifier_flags();
    void process_all_key_states();
    void process_key_input(u8);
    s32 sub_8025F4A0(u8);
    s32 lookup_key_repeat_state(u8, u8);
    u8 sub_8025F2F8(u8);
    s32 poll_input();
    u16 lookup_key_char(u8);
    int sub_80260438();
    int sub_8026042C();
    u8 _pad1C[0x44];
    u32 m_60;
    u32 m_64;
    u32 m_68;
    u32 m_6c;
    u32 m_70;
    void release_keyboard();
    virtual void render();
    static s32 test_card_flag(s32 arg1, s32 arg2);
    static void set_card_window_flags(void *arg0, s32 arg1, s32 arg2);
    int is_card_flag_set();
    int test_card_flag_0x80();
    int test_card_flag_64();
    int call_1A529C_with_32();
    int test_card_flag_16();
    static s32 test_card_flag_8(s32 client_id);
    virtual void run_task();
    static void set_bits_shift7(s32 arg0, s32 arg1);
    static void update_card_window_page_flags(s32 arg0, s32 arg1);
    static void clear_card_window_flag(s32 arg0, s32 arg1);
    static void set_card_window_flag(s32 arg0, s32 arg1);
    int is_key_active();
};

typedef char TWindowKeyBoardHard_size[sizeof(TWindowKeyBoardHard) == 0x74 ? 1 : -1];
#endif
