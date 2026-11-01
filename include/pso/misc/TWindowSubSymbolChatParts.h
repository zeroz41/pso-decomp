#ifndef PSO_MISC_TWINDOWSUBSYMBOLCHATPARTS_H
#define PSO_MISC_TWINDOWSUBSYMBOLCHATPARTS_H

#include "types.h"
#include "pso/misc/TWindowAddition.h"

struct TWindowSubSymbolChatParts : public TWindowAddition {
    virtual ~TWindowSubSymbolChatParts();
    void sub_80285274(u8 *);
    void sub_80285054();
    s32 calc_symbol_index();
    s32 sub_80283974();
    virtual void render();
    virtual void run_task();
    u8 _pad1C[0x4];
    s16 m_20;
    u8 _pad22[0xA];
    u32 m_2c;
    u8 _pad30[0x2C];
    u32 m_5c;
    u8 _pad60[0x8];
    void* m_68;
    u8 _pad6C[0x4];
    u8 m_70;
    u8 m_71;
    u8 m_72;
    u8 m_73;
    u8 _pad74[0x2];
    u16 m_76;
    u8 _pad78[0x4];
    u32 m_7c;
    u32 m_80;
    u8 _pad84[0x4];
    u32 m_88;
    u32 m_8c;
    void handle_cancel();
    void add_part();
    void handle_add();
};

typedef char TWindowSubSymbolChatParts_size[sizeof(TWindowSubSymbolChatParts) == 0x90 ? 1 : -1];

extern "C" {
void *__dt__25TWindowSubSymbolChatPartsFv(void *arg0, s16 arg1);
void fn_80284C04(u8 *arg0);
void render__25TWindowSubSymbolChatPartsFv(u8 *arg0);
void select_symbol_chat_slot(TWindowSubSymbolChatParts *parts);
}

// --- C functions defined in TWindowSubSymbolChatParts.cpp ---
extern "C" {
void *__dt__25TWindowSubSymbolChatPartsFv(void *arg0, s16 arg1);
void fn_80284C04(u8 *arg0);
void fn_80284FB8(void *arg0);
void render__25TWindowSubSymbolChatPartsFv(u8 *arg0);
void select_symbol_chat_slot(TWindowSubSymbolChatParts *parts);
}
// --- end of C functions

#endif
