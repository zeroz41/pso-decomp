#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChatFaceType.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

void __dl__7TObjectFPv(void *);

extern s32 __vt__28TWindowSubSymbolChatFaceType[];

void *__dt__28TWindowSubSymbolChatFaceTypeFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__28TWindowSubSymbolChatFaceType;
        TWindowSubStatusDisp::destroy_status_display((s32)(*(void **)((s8 *)arg0 + 0x68)), (s16)1);
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}

struct RecoveredGlobal_802841FC_lbl_804D2CE0 {
    s32 value;
    u8 remaining[0x10];
};

extern "C" {
s32 construct_type1_heading__20TWindowSubStatusDispFll(s32, s32, s32);
s32 get_message_10__20TWindowSubStatusDispFl(int);
extern RecoveredGlobal_802841FC_lbl_804D2CE0 symbol_chat_face_type_window_layout;
extern s32 TWindowSubSymbolChatFaceType__name;
typedef char RecoveredGlobal_802841FC_lbl_804D2CE0_size[sizeof(RecoveredGlobal_802841FC_lbl_804D2CE0) == 0x14 ? 1 : -1];
u8 *TWindowSubSymbolChatFaceType__ct(TWindowSubSymbolChatFaceType *window_sub_symbol_chat_face_type, s32 arg1, s32 arg2) {
    s32 var_r31;
    ((TWindowDD *)window_sub_symbol_chat_face_type)->construct_base((u8 *)((s32) &symbol_chat_face_type_window_layout.value), (s16)4, (u8 *)arg1);
    *(s32 **)((s8 *)window_sub_symbol_chat_face_type + 0x18) = __vt__28TWindowSubSymbolChatFaceType;
    *(s32 *)((s8 *)window_sub_symbol_chat_face_type + 0) = (s32) TWindowSubSymbolChatFaceType__name;
    window_sub_symbol_chat_face_type->m_60 = 0;
    window_sub_symbol_chat_face_type->m_61 = 0;
    window_sub_symbol_chat_face_type->m_62 = 0;
    window_sub_symbol_chat_face_type->m_64 = arg2;
    var_r31 = (int)::operator new(0x24);
    if (var_r31 != 0) {
        var_r31 = construct_type1_heading__20TWindowSubStatusDispFll(var_r31, get_message_10__20TWindowSubStatusDispFl(0x33), (s32) window_sub_symbol_chat_face_type->m_20);
    }
    window_sub_symbol_chat_face_type->m_68 = var_r31;
    return (u8 *)window_sub_symbol_chat_face_type;
}

}
