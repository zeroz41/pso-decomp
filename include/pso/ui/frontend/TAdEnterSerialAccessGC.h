#ifndef PSO_UI_FRONTEND_TADENTERSERIALACCESSGC_H
#define PSO_UI_FRONTEND_TADENTERSERIALACCESSGC_H

#include "pso/ui/window/WindowCallback.h"
#include "types.h"
#include "pso/ui/frontend/TAdEnterBaseGC.h"

class TAdSelectCurGC;
class TWindowBase;

struct TAdEnterSerialAccessGC : public TAdEnterBaseGC {
    virtual ~TAdEnterSerialAccessGC();
    virtual void render();
    virtual void run_task();
    u8 unk_38[0x4];
    s32 m_3c; // 0x3C
    u32 m_40;
    u32 m_44;
    u32 m_48;
    u32 m_4c;
    TObject *m_50;
    TAdSelectCurGC *cursor;
    TWindowBase *m_58;
    TWindowBase *m_5c;
    u32 m_60;
    u32 m_64;
    static void draw_screen(void *arg0, void *arg1);
    static void draw_serial_separators();
    static void draw_serial_plates();
    void format_dashed_serial(u8 *src, u32 count, u32 *lens);
    static s32 *get_formatted_serial();
    static s32 parse_serial_value();
    static char *convert_serial_hex_to_decimal(const char *serial);
    static char *hex_to_decimal_string(const char *serial);
    static s32 open_message_window(void *arg0, void *arg1);
    static void init_state();
    static void *create_callback(void *position, void *scale, WindowCallback callback);
    void *create_default_callback();
    static s32 show_message_window(void *arg0, void *arg1);
    static void clear_serial_buffer();
    static void store_serial_access_key(saddr arg0, saddr arg1, saddr arg2);
    static char *serial_to_hex_string(const char *serial);
    static int forward_input(void *screen, s32 field, const char *text);
    static void draw_serial_chars(saddr arg0);
    static u32 create_keyboard_control(saddr arg0, s32 arg1);
};

LAYOUT_ASSERT(TAdEnterSerialAccessGC_size, sizeof(TAdEnterSerialAccessGC) == 0x68);

extern "C" {
u8 *TAdEnterSerialAccessGC__ct(TAdEnterSerialAccessGC *arg0, TObject *parent);
u8 *TAdEnterSerialAccessGC__sub_80321738(void);
s32 *TAdEnterSerialAccessGC__sub_803217B8(void);
s32 *TAdEnterSerialAccessGC__sub_80321874(void);
void TAdEnterSerialAccessGC__sub_8032190C(const char *key);
void TAdEnterSerialAccessGC__sub_8032195C(const char *serial);
void TAdEnterSerialAccessGC__sub_80321B28(u8 *arg0, int arg1);
void TAdEnterSerialAccessGC__sub_80321F18(void *p);
void TAdEnterSerialAccessGC__sub_80321F3C(void *p);
void TAdEnterSerialAccessGC__sub_80322418(s32 arg0, s32 arg1);
void *__dt__22TAdEnterSerialAccessGCFv(TAdEnterSerialAccessGC *arg0, s16 arg1);
void create_draw_callback__22TAdEnterSerialAccessGCFv(void);
void initialize_serial_input(const char *serial);
}
extern "C" void *create_callback_at_zero_vec2(WindowCallback callback);

// --- C functions defined in TAdEnterSerialAccessGC.cpp ---
extern "C" {
u8 *TAdEnterSerialAccessGC__ct(TAdEnterSerialAccessGC *ad_enter_serial_access_gc, TObject *parent);
u8 *TAdEnterSerialAccessGC__sub_80321738(void);
s32 *TAdEnterSerialAccessGC__sub_803217B8(void);
s32 *TAdEnterSerialAccessGC__sub_80321874(void);
void TAdEnterSerialAccessGC__sub_8032190C(const char *key);
void TAdEnterSerialAccessGC__sub_8032195C(const char *serial);
void TAdEnterSerialAccessGC__sub_80321B28(u8 *ad_enter_serial_access_gc, int arg1);
void TAdEnterSerialAccessGC__sub_80321F18(void *p);
void TAdEnterSerialAccessGC__sub_80321F3C(void *p);
void TAdEnterSerialAccessGC__sub_80322418(s32 arg0, s32 arg1);
void *__dt__22TAdEnterSerialAccessGCFv(TAdEnterSerialAccessGC *arg0, s16 arg1);
void create_draw_callback__22TAdEnterSerialAccessGCFv(void);
void initialize_serial_input(const char *serial);
}
// --- end of C functions

#endif
