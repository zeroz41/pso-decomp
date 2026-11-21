#ifndef PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATPARTSSET_H
#define PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATPARTSSET_H

#include "types.h"
#include "pso/ui/chat/TWindowChatSymbol.h"

struct TWindowSubStatusDisp;

struct TWindowSubSymbolChatPartsSet : public TWindowChatSymbol {
    virtual ~TWindowSubSymbolChatPartsSet();
    void sub_8028625C();
    s32 is_active();
    void set_selection(u32);
    void update_visibility();
    virtual void render();
    u8 m_68;
    u8 _pad69[0x1];
    u16 m_6a;
    u16 m_6c;
    u16 m_6e;
    u32 m_70;
    u8 _pad74[0x8];
    u32 m_7c;
    u32 m_80;
    u8 _pad84[0x4];
    TWindowSubStatusDisp *m_88;
    s32 draw_selected_part_cursor(int arg1);
    void handle_cancel();
    void handle_decide();
    void toggle_selected_part();
    void handle_cursor_input();
    virtual void run_task();
    u8 unk_8C[0x4];
    f32 m_90;
    u8 unk_94[0x4];
    static int get_parts_entry(int a0);
    void set_pos(s16 arg1, s16 arg2);
    static void set_part_sprite(void *arg0, s16 id, s32 a, s32 b);
    u16 *get_entry_offset_d(s32 arg1);
    u16 *get_parts_entry(saddr arg1);
    static u16 *get_parts_entry(int arg0, int arg1);
};

LAYOUT_ASSERT(TWindowSubSymbolChatPartsSet_size, sizeof(TWindowSubSymbolChatPartsSet) == 0x98);
#endif
