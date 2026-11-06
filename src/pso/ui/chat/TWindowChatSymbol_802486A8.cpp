#include "types.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/chat/TWindowChatSymbol_802486A8.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/unk/TUnk_804CE7D0.h"
#include "pso/ui/chat/TWindowChatSymbol.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/chat/TWindowSubSymbolChat_80076F88.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/object/warp/TObjCityMainWarp.h"

struct RecoveredGlobal_80248700_lbl_804CE7A0 {
    s32 value;
    u8 remaining[0x10];
};

extern "C" {
s32 fn_8024491C(void *, void *);
extern RecoveredGlobal_80248700_lbl_804CE7A0 window_chat_symbol_settings;
extern s32 __vt__17TWindowChatSymbol[];
extern s32 lbl_805D38A8;
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

void *__dt__17TWindowChatSymbolFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TWindowChatSymbol;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80248700_lbl_804CE7A0_size[sizeof(RecoveredGlobal_80248700_lbl_804CE7A0) == 0x14 ? 1 : -1];
u8 *TWindowChatSymbol__ct(TWindowChatSymbol *window_chat_symbol, s32 arg1, s32 arg2) {
    ((TWindowDD *)window_chat_symbol)->construct_base((u8 *)((s32) &window_chat_symbol_settings.value), (s16)4, (u8 *)arg1);
    *(s32 **)((s8 *)window_chat_symbol + 0x18) = __vt__17TWindowChatSymbol;
    *(s32 *)((s8 *)window_chat_symbol + 0) = (s32) lbl_805D38A8;
    fn_8024491C((void *)window_chat_symbol, (void *)arg2);
    window_chat_symbol->m_60 = 0;
    window_chat_symbol->m_64 = 0;
    return (u8 *)window_chat_symbol;
}

void TUnk_804CE7D0::render() {  }
void TUnk_804CE7D0::run_task() {
    ((TWindowSubSymbolChat *)(this->m_20))->set_from_key(((TWindowMenu *)(*(s32 *)&this->unk_1C))->get_selected_value());
}

extern s32 lbl_804CE7D0[];

void *TWindowChatSymbol::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804CE7D0;
        if (this->m_20 != NULL) { ((TWindowBase *)this->m_20)->close(); this->m_20 = 0; }
        if (*(void * *)&this->unk_1C != NULL) { ((TWindowBase *)(*(void * *)&this->unk_1C))->close(); *(s32 *)&this->unk_1C = 0; }
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

}

extern "C" {
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *, int, int, int);
u8 *__nw__7TObjectFUl(s32);
s32 __ct__7TObjectFP7TObject();
s32 align_menu_entry_positions(void *);
u8 *check_room_seq_4__16TAdChrSelASlotGCFl(s32 *, s32);
extern s32 lbl_8044EAC0[];
extern s32 lbl_8044EAC8[];
extern s32 lbl_8044EAD0[];
extern s32 lbl_804CE7D0[];
u8 *construct_symbol_chat_selection(u8 *arg0) {
    s32 i;
    u8 *temp_r30;
    u8 *symbol_chat_preset;
    u8 *window_chat_symbol;
    u8 *var_r0;
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)arg0 + 0x18) = lbl_804CE7D0;
    *(u8 **)((s8 *)arg0 + 0x1C) = check_room_seq_4__16TAdChrSelASlotGCFl(lbl_8044EAC0, 0xC);
    i = 0;
    do {
        symbol_chat_preset = (u8 *)(get_symbol_chat_preset(i));
        temp_r30 = (u8 *)(((TWindowSubSymbolChat *)symbol_chat_preset)->get_symbol_chat_data());
        if (is_symbol_chat_preset_in_use((u32 *)symbol_chat_preset) != 0) {
            forward_trade_action_default__16TObjCityMainWarpFPviii(*(u8 **)((s8 *)arg0 + 0x1C), (s32) temp_r30, 0x66, i);
        } else {
            TWindowSubComCard::draw_text_gray((s32)((void *) (*(u8 **)((s8 *)arg0 + 0x1C))), (s32)temp_r30, 0x46, (s32)i);
        }
        i += 1;
    } while (i < 0xC);
    ((TWindowSubComCardList *)(*(u8 **)((s8 *)arg0 + 0x1C)))->set_flag70_bit10();
    ((TWindowSubComCardList *)(*(u8 **)((s8 *)arg0 + 0x1C)))->set_scroll_target(220.0f, 120.0f);
    align_menu_entry_positions((void *) (*(u8 **)((s8 *)arg0 + 0x1C)));
    window_chat_symbol = (u8 *)(__nw__7TObjectFUl(0x68));
    var_r0 = window_chat_symbol;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(TWindowChatSymbol__ct((TWindowChatSymbol *)window_chat_symbol, (s32)lbl_8044EAC8, (s32)lbl_8044EAD0));
    }
    *(u8 **)((s8 *)arg0 + 0x20) = var_r0;
    return arg0;
}

}
