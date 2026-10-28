#include "types.h"
#include "pso/unk/text_802841FC.h"
#include "pso/misc/TWindowSubSymbolChatFaceType.h"
#include "pso/misc/TWindowDD.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_802841FC_lbl_804D2CE0 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_802841FC___vt__28TWindowSubSymbolChatFaceType {
    s32 value;
    u8 remaining[0x18];
};

extern "C" {
s32 construct_type1_heading__20TWindowSubStatusDispFll(s32, s32, s32);
s32 get_message_10__20TWindowSubStatusDispFl(int);
extern RecoveredGlobal_802841FC_lbl_804D2CE0 symbol_chat_face_type_window_layout;
extern RecoveredGlobal_802841FC___vt__28TWindowSubSymbolChatFaceType __vt__28TWindowSubSymbolChatFaceType;
extern s32 TWindowSubSymbolChatFaceType__name;
typedef char RecoveredGlobal_802841FC_lbl_804D2CE0_size[sizeof(RecoveredGlobal_802841FC_lbl_804D2CE0) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_802841FC___vt__28TWindowSubSymbolChatFaceType_size[sizeof(RecoveredGlobal_802841FC___vt__28TWindowSubSymbolChatFaceType) == 0x1C ? 1 : -1];
u8 *TWindowSubSymbolChatFaceType__ct(TWindowSubSymbolChatFaceType *window_sub_symbol_chat_face_type, s32 arg1, s32 arg2) {
    s32 var_r31;
    ((TWindowDD *)window_sub_symbol_chat_face_type)->construct_base((u8 *)((s32) &symbol_chat_face_type_window_layout.value), (s16)4, (u8 *)arg1);
    *(s32 **)((s8 *)window_sub_symbol_chat_face_type + 0x18) = &__vt__28TWindowSubSymbolChatFaceType.value;
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
