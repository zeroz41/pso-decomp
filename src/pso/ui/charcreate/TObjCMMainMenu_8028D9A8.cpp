#include "types.h"
#include "pso/player/TPlyCharData.h"
#include "pso/ui/charcreate/TObjCMMainMenu_8028D9A8.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/charcreate/TObjCMMainMenu.h"
#include "pso/ui/window/TWindowSubComCard.h"

struct RecoveredGlobal_8028D9B4_lbl_8051C094 { s32 value; u8 remaining[0x50]; };
typedef char RecoveredGlobal_8028D9B4_lbl_8051C094_size[sizeof(RecoveredGlobal_8028D9B4_lbl_8051C094) == 0x54 ? 1 : -1];

struct RecoveredGlobal_8028D9A8_lbl_8051C094 {
    s32 value;
    u8 remaining[0x50];
};

struct RecoveredGlobal_8028DA0C_lbl_8051C07C {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8028D9F8_lbl_8051C094 {
    s32 value;
    u8 remaining[0x50];
};

extern "C" {
u8 * copy_player_visual_record(void *, void *);
extern RecoveredGlobal_8028D9B4_lbl_8051C094 character_creation_visual_record;
s32 strncpy(void *, void *, int);
extern RecoveredGlobal_8028DA0C_lbl_8051C07C character_creation_name_buffer;
u8 *get_class_appearance_preset(s32 arg0);
s32 TAdEndText__sub_8001B3EC(s32);

typedef char RecoveredGlobal_8028D9A8_lbl_8051C094_size[sizeof(RecoveredGlobal_8028D9A8_lbl_8051C094) == 0x54 ? 1 : -1];
s32 *TObjCMMainMenu__sub_8028D9A8(void) {
    return &(*(RecoveredGlobal_8028D9A8_lbl_8051C094 *)&character_creation_visual_record).value;
}

void TObjCMMainMenu__sub_8028D9B4(u8 *arg0) {
    if ((s8) *(u8 *)((s8 *)arg0 + 0x32) & 0xA) {
        TObjCMMainMenu__sub_8028D9F8();
        return;
    }
    copy_player_visual_record(&character_creation_visual_record.value, arg0);
}

typedef char RecoveredGlobal_8028DA0C_lbl_8051C07C_size[sizeof(RecoveredGlobal_8028DA0C_lbl_8051C07C) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_8028D9F8_lbl_8051C094_size[sizeof(RecoveredGlobal_8028D9F8_lbl_8051C094) == 0x54 ? 1 : -1];
void TObjCMMainMenu__sub_8028D9F8(void) {
    *(s8 *)((s8 *)(&(*(RecoveredGlobal_8028D9F8_lbl_8051C094 *)&character_creation_visual_record).value) + 0x31) = -1;
}

void TObjCMMainMenu::copy_char_name() {
    s32 arg0 = (s32)this;
    strncpy((void *)&character_creation_name_buffer.value, (void *)arg0, 0xC);
    *(s8 *)((s8 *)&character_creation_name_buffer.value + 0xC) = 0;
}

void TObjCMMainMenu::select_char_menu() {
    ((TObjCMMainMenu *)&get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF)->m_disp_data.m_disp_part2)->copy_char_name();
}

s32 TObjCMMainMenu::validate_character_name(s8 *arg0) {
    s8 buf[13];
    s8 out[16];
    s32 found;
    s8 *p;
    s8 *q;
    strncpy(buf, arg0, 0xC);
    buf[12] = 0;
    found = 0;
    p = buf;
    while (*p != 0) {
        if (*p != 0x20) {
            found = 1;
            break;
        }
        p++;
    }
    if (found == 0) {
        *arg0 = 0;
        return 0;
    }
    if (TWindowSubComCard::contains_profanity((char *)buf) != 0) {
        *arg0 = 0;
        return 0;
    }
    p = buf;
    q = out;
    while (*p != 0) {
        if (TAdEndText__sub_8001B3EC(*p) != 0) {
            *q = *p;
            q++;
        }
        p++;
    }
    *q = 0;
    if (TWindowSubComCard::contains_profanity((char *)out) != 0) {
        *arg0 = 0;
        return 0;
    }
    return 1;
}

s32 TObjCMMainMenu::get_current_char_flag() {
    s32 x = (s8) *(u8 *)((s8 *)((void *)get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF)) + 0x3A0);
    return (u32) __cntlzw(-1 - x) >> 5;
}
void fn_8028DBC4(s32 _w0) {
    u8 *temp_r31;
    temp_r31 = (u8 *)(((s32)((void *)get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF))) + 0x370);
    copy_player_visual_record(temp_r31, (void *)((int) (get_class_appearance_preset(0))));
    *(s8 *)((s8 *)temp_r31 + 0x30) = -1;
}
int TAdSinglePlyChrSelectGC__sub_8028DC14(void) { return 1; }
int TAdSinglePlyChrSelectGC__sub_8028DC1C(void* p) { fn_8028DBC4((s32)p); return 1; }

}
