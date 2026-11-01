#include "types.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowChatSymbol_802486A8.h"
#include "pso/misc/TWindowSubSymbolChat.h"
#include "pso/misc/TUnk_804CE7D0.h"
#include "pso/misc/TWindowChatSymbol.h"
#include "pso/misc/TWindowDD.h"

struct RecoveredGlobal_80248700_lbl_804CE7A0 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80248700___vt__17TWindowChatSymbol {
    s32 value;
    u8 remaining[0x18];
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
typedef char RecoveredGlobal_80248700___vt__17TWindowChatSymbol_size[sizeof(RecoveredGlobal_80248700___vt__17TWindowChatSymbol) == 0x1C ? 1 : -1];
u8 *TWindowChatSymbol__ct(TWindowChatSymbol *window_chat_symbol, s32 arg1, s32 arg2) {
    ((TWindowDD *)window_chat_symbol)->construct_base((u8 *)((s32) &window_chat_symbol_settings.value), (s16)4, (u8 *)arg1);
    *(s32 **)((s8 *)window_chat_symbol + 0x18) = &(*(RecoveredGlobal_80248700___vt__17TWindowChatSymbol *)&__vt__17TWindowChatSymbol).value;
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
