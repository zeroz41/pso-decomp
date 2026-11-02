#include "types.h"
#include "pso/misc/TWindowChatSymbol_802486A8.h"
#include "pso/misc/TWindowSubSymbolChat_80076F88.h"
#include "pso/unk/text_80248840.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubSymbolChat.h"
#include "pso/object/TObjCityMainWarp.h"

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
