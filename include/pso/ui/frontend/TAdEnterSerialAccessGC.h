#ifndef PSO_UI_FRONTEND_TADENTERSERIALACCESSGC_H
#define PSO_UI_FRONTEND_TADENTERSERIALACCESSGC_H

#include "types.h"
#include "pso/ui/frontend/TAdEnterBaseGC.h"

struct TAdEnterSerialAccessGC : public TAdEnterBaseGC {
    virtual ~TAdEnterSerialAccessGC();
    virtual void run_task();
    u8 unk_38[0x4];
    s32 m_3c; // 0x3C
    u32 m_40;
    u32 m_44;
    u32 m_48;
    u32 m_4c;
    u32 m_50;
    u32 m_54;
    u32 m_58;
    u32 m_5c;
    u32 m_60;
    u32 m_64;
    static void render(void *self);
    static void draw_screen(void *arg0, void *arg1);
    static void draw_serial_separators();
    static void draw_serial_plates();
    void format_dashed_serial(u8 *src, u32 count, u32 *lens);
    static s32 *get_formatted_serial();
    static s32 parse_serial_value();
    static char *convert_serial_hex_to_decimal(int arg0);
    static char *hex_to_decimal_string(int arg0);
    static s32 open_message_window(void *arg0, void *arg1);
    s32 get_field20_state();
    void set_state_3();
    static void init_state();
    static void *create_callback(void *arg0, void *arg1, void *arg2);
    void set_active();
    static void create_default_callback();
    static s32 show_message_window(void *arg0, void *arg1);
    static void clear_serial_buffer();
    static void store_serial_access_key(s32 arg0, s32 arg1, s32 arg2);
    static char *serial_to_hex_string(int arg0);
    static int forward_input(void* p);
    void reset_input_state();
    static void draw_serial_chars(s32 arg0);
    static u32 create_keyboard_control(s32 arg0, s32 arg1);
};

typedef char TAdEnterSerialAccessGC_size[sizeof(TAdEnterSerialAccessGC) == 0x68 ? 1 : -1];

extern "C" {
u8 *TAdEnterSerialAccessGC__ct(TAdEnterSerialAccessGC *arg0);
u8 *TAdEnterSerialAccessGC__sub_80321738(void);
s32 *TAdEnterSerialAccessGC__sub_803217B8(void);
s32 *TAdEnterSerialAccessGC__sub_80321874(void);
void TAdEnterSerialAccessGC__sub_8032190C(s32 arg0);
void TAdEnterSerialAccessGC__sub_8032195C(s32 arg0);
void TAdEnterSerialAccessGC__sub_80321B28(u8 *arg0, int arg1);
void TAdEnterSerialAccessGC__sub_80321F18(void *p);
void TAdEnterSerialAccessGC__sub_80321F3C(void *p);
void TAdEnterSerialAccessGC__sub_80322418(s32 arg0, s32 arg1);
void *__dt__22TAdEnterSerialAccessGCFv(TAdEnterSerialAccessGC *arg0, s16 arg1);
void create_draw_callback__22TAdEnterSerialAccessGCFv(void);
void init__22TAdEnterSerialAccessGCFv(void);
}

// --- C functions defined in TAdEnterSerialAccessGC.cpp ---
extern "C" {
u8 *TAdEnterSerialAccessGC__ct(TAdEnterSerialAccessGC *ad_enter_serial_access_gc);
u8 *TAdEnterSerialAccessGC__sub_80321738(void);
s32 *TAdEnterSerialAccessGC__sub_803217B8(void);
s32 *TAdEnterSerialAccessGC__sub_80321874(void);
void TAdEnterSerialAccessGC__sub_8032190C(s32 arg0);
void TAdEnterSerialAccessGC__sub_8032195C(s32 arg0);
void TAdEnterSerialAccessGC__sub_80321B28(u8 *ad_enter_serial_access_gc, int arg1);
void TAdEnterSerialAccessGC__sub_80321F18(void *p);
void TAdEnterSerialAccessGC__sub_80321F3C(void *p);
void TAdEnterSerialAccessGC__sub_80322418(s32 arg0, s32 arg1);
void *__dt__22TAdEnterSerialAccessGCFv(TAdEnterSerialAccessGC *arg0, s16 arg1);
void create_draw_callback__22TAdEnterSerialAccessGCFv(void);
void init__22TAdEnterSerialAccessGCFv(void);
}
// --- end of C functions

#endif
