#include "types.h"
#include "pso/ui/window/TWindowCtrl_8024B7D4.h"
#include "pso/ui/window/TWindowKeyBoardSoft_8025B85C.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/Language.h"

struct Field_8025C974 { u16 *buffer; s32 cursor; u32 width; u32 linePixels; s32 scroll; u32 capacity; };

struct Base_8025C974 { u8 pad[0x6c]; Field_8025C974 field; u8 pad2[0x30]; s32 fb4; };

struct Field_8025C804 { u16 *buffer; s32 cursor; };

struct Kbd_8025C804 {
    u8 pad0[0x60];
    u16 flags;
    u8 pad62[0x6C - 0x62];
    Field_8025C804 field;
    u8 pad74[0x84 - 0x74];
    u16 *buf;
    u8 pad88[0x94 - 0x88];
    u32 len;
    u32 max;
    s8 *src;
};

extern "C" {
s32 is_chat_shortcut_set(int);
s32 TWindowKeyBoardSoft__sub_8025D664();
s32 select_next__19TWindowKeyBoardSoftFv();
s32 TWindowKeyBoardSoft__sub_800808FC(int, int);
s32 TWindowKeyBoardSoft__sub_8025D8C8();
void TWindowKeyBoardSoft__sub_8025CFA8(void *, void *);
s32 TWindowKeyBoardSoft__sub_803E67D4(void *, void *);
s32 get_shared_text_buffer();
s32 append_text__19TWindowKeyBoardSoftFPvPv(void *, s32);
s32 TWindowKeyBoardSoft__sub_8025DBDC(void *, s32);
extern s32 lbl_805DD030;
extern s32 lbl_805DD034;
s32 TWindowKeyBoardSoft__sub_8025D7FC();
void export_keyboard_text(Base_8025C974 *base, char *out);
int set_text_from_string__19TWindowKeyBoardSoftFPc(void*);

int TWindowKeyBoardSoft::is_alnum(u16 arg0) {
    if ((s32) arg0 < 0x30) {
        return 0;
    }
    if ((s32) arg0 <= 0x39) {
        return 1;
    }
    if ((s32) arg0 < 0x41) {
        return 0;
    }
    if ((s32) arg0 <= 0x5A) {
        return 1;
    }
    if ((s32) arg0 < 0x61) {
        return 0;
    }
    if ((s32) arg0 <= 0x7A) {
        return 1;
    }
    return 0;
}

s32 TWindowKeyBoardSoft::get_state() { return *(s32*)((char*)this + 0x70); }

void TWindowKeyBoardSoft::vt2() {
    u8 *self = (u8 *)this;
    if (*(u16 *)((s8 *)this + 0x60) & 2) {
        init();
    }
    if ((u32) *(u32 *)((s8 *)this + 0x7C) != 0U) {
        ((TWindowKeyBoardSoft *)(self + 0x6C))->reset_state();
    }
    *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x20);
}

void TWindowKeyBoardSoft::sub_8025B928() {  }

void TWindowKeyBoardSoft::sub_8025B92C() {
    s8 sp108[0x100];
    s8 sp8[0x100];
    s32 var_r3;
    u16 temp_r4;
    temp_r4 = *(u16 *)((s8 *)this + 0x60);
    if (temp_r4 & 2) {
        if (!(temp_r4 & 4)) {
            convert_input_text();
            var_r3 = *(s32 *)((s8 *)this + 0xAC);
            if (!(*(u16 *)((s8 *)this + 0x60) & 0x10)) {
                do {
                    *(s32 *)((s8 *)this + 0xAC) = var_r3;
                    var_r3 = TWindowKeyBoardSoft__sub_803E67D4(sp8, sp108);
                } while (var_r3 != 0);
                TWindowKeyBoardSoft__sub_8025CFA8(this, sp8);
                sp8[0] = 0;
                write_name_and_text((char *)sp8, (char *)sp8);
                goto block_5;
            }
        } else {
block_5:
            if ((s32) *(s32 *)((s8 *)this + 0xA8) != 0xF1) {
                set_kana_mode();
                return;
            }
            set_kanji_mode();
        }
    }
}

void TWindowKeyBoardSoft::update_input_state() {
    u16 temp_r4;

    temp_r4 = *(u16 *)((s8 *)this + 0x60);
    if (temp_r4 & 4) {
        if (*(s32 *)((s8 *)this + 0xB4) & 0x20) {
            update();
            return;
        }
        select_next__19TWindowKeyBoardSoftFv();
        return;
    }
    if (temp_r4 & 2) {
        convert_input_text();
    }
}

void TWindowKeyBoardSoft::sub_8025BA28() {
    u8 *temp_r3;
    if (!(*(u16 *)((s8 *)this + 0x60) & 4)) {
        temp_r3 = *(u8 **)((s8 *)this + 0x68);
        *(s32 *)((s8 *)temp_r3 + 4) = (s32) *(s32 *)((s8 *)temp_r3 + 0x10);
    }
}

void TWindowKeyBoardSoft::sub_8025BA44() {
    if (!(*(u16 *)((s8 *)this + 0x60) & 4)) {
        *(s32 *)((s8 *)(*(void **)((s8 *)this + 0x68)) + 4) = 0;
    }
}

void TWindowKeyBoardSoft::vt14() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8) && !(*(s32 *)((s8 *)this + 0xB4) & 0x20) && !(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(0x13) != 0)) {
        *(s8 *)((s8 *)this + 0x65) = 0x13;
        *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
    }
}

void TWindowKeyBoardSoft::vt13() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8) && !(*(s32 *)((s8 *)this + 0xB4) & 0x20) && !(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(0x12) != 0)) {
        *(s8 *)((s8 *)this + 0x65) = 0x12;
        *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
    }
}

void TWindowKeyBoardSoft::vt12() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8) && !(*(s32 *)((s8 *)this + 0xB4) & 0x20) && !(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(0x11) != 0)) {
        *(s8 *)((s8 *)this + 0x65) = 0x11;
        *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
    }
}

void TWindowKeyBoardSoft::vt11() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8) && !(*(s32 *)((s8 *)this + 0xB4) & 0x20) && !(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(0x10) != 0)) {
        *(s8 *)((s8 *)this + 0x65) = 0x10;
        *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
    }
}

void TWindowKeyBoardSoft::vt10() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8) && !(*(s32 *)((s8 *)this + 0xB4) & 0x20) && !(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(0xF) != 0)) {
        *(s8 *)((s8 *)this + 0x65) = 0xF;
        *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
    }
}

void TWindowKeyBoardSoft::vt9() {
    s8 sp108[0x100];
    s8 sp8[0x100];
    s32 var_r3;
    u16 temp_r4;
    if (!(*(s32 *)((s8 *)this + 0xB4) & 0x20)) {
        temp_r4 = *(u16 *)((s8 *)this + 0x60);
        if (temp_r4 & 2) {
            if (!(temp_r4 & 4)) {
                convert_input_text();
                var_r3 = *(s32 *)((s8 *)this + 0xAC);
                if (!(*(u16 *)((s8 *)this + 0x60) & 0x10)) {
                    do {
                        *(s32 *)((s8 *)this + 0xAC) = var_r3;
                        var_r3 = TWindowKeyBoardSoft__sub_803E67D4(sp8, sp108);
                    } while (var_r3 != 0);
                    TWindowKeyBoardSoft__sub_8025CFA8(this, sp8);
                    sp8[0] = 0;
                    write_name_and_text((char *)sp8, (char *)sp8);
                    goto block_6;
                }
            } else {
block_6:
                set_kana_mode();
            }
        } else if (!(*(u16 *)((s8 *)this + 0x62) & 8) && (is_chat_shortcut_set(0xE) != 0)) {
            *(s8 *)((s8 *)this + 0x65) = 0xE;
            *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
        }
    }
}

void TWindowKeyBoardSoft::vt8() {
    s8 sp108[0x100];
    s8 sp8[0x100];
    s32 var_r3;
    u16 temp_r4;
    if (!(*(s32 *)((s8 *)this + 0xB4) & 0x20)) {
        temp_r4 = *(u16 *)((s8 *)this + 0x60);
        if (temp_r4 & 2) {
            if (!(temp_r4 & 4)) {
                convert_input_text();
                var_r3 = *(s32 *)((s8 *)this + 0xAC);
                if (!(*(u16 *)((s8 *)this + 0x60) & 0x10)) {
                    do {
                        *(s32 *)((s8 *)this + 0xAC) = var_r3;
                        var_r3 = TWindowKeyBoardSoft__sub_803E67D4(sp8, sp108);
                    } while (var_r3 != 0);
                    TWindowKeyBoardSoft__sub_8025CFA8(this, sp8);
                    sp8[0] = 0;
                    write_name_and_text((char *)sp8, (char *)sp8);
                    goto block_6;
                }
            } else {
block_6:
                set_kanji_mode();
            }
        } else if (!(*(u16 *)((s8 *)this + 0x62) & 8) && (is_chat_shortcut_set(0xD) != 0)) {
            *(s8 *)((s8 *)this + 0x65) = 0xD;
            *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
        }
    }
}

void TWindowKeyBoardSoft::vt7() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8) && !(*(s32 *)((s8 *)this + 0xB4) & 0x20) && !(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(0xC) != 0)) {
        *(s8 *)((s8 *)this + 0x65) = 0xC;
        *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
    }
}

void TWindowKeyBoardSoft::vt6() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8) && !(*(s32 *)((s8 *)this + 0xB4) & 0x20) && !(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(0xB) != 0)) {
        *(s8 *)((s8 *)this + 0x65) = 0xB;
        *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
    }
}

void TWindowKeyBoardSoft::vt5() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8)) {
        if (*(s32 *)((s8 *)this + 0xB4) & 0x20) {
            TWindowKeyBoardSoft__sub_8025C51C((u8 *)this, 2);
            return;
        }
        if (!(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(0xA) != 0)) {
            *(s8 *)((s8 *)this + 0x65) = 0xA;
            *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
        }
    }
}

void TWindowKeyBoardSoft::vt4() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8)) {
        if (*(s32 *)((s8 *)this + 0xB4) & 0x20) {
            TWindowKeyBoardSoft__sub_8025C51C((u8 *)this, 1);
            return;
        }
        if (!(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(9) != 0)) {
            *(s8 *)((s8 *)this + 0x65) = 9;
            *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
        }
    }
}

void TWindowKeyBoardSoft::vt3() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8)) {
        if (*(s32 *)((s8 *)this + 0xB4) & 0x20) {
            TWindowKeyBoardSoft__sub_8025C51C((u8 *)this, 0);
            return;
        }
        if (!(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(8) != 0)) {
            *(s8 *)((s8 *)this + 0x65) = 8;
            *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
        }
    }
}

void TWindowKeyBoardSoft::vt17() {
    if (*(u16 *)((s8 *)this + 0x60) & 4) {
        if (*(u16 *)((s8 *)this + 0x62) & 1) {
            update();
            return;
        }
        process_input();
    }
}

void TWindowKeyBoardSoft::vt18() {
    if (*(u16 *)((s8 *)this + 0x60) & 4) {
        if (*(u16 *)((s8 *)this + 0x62) & 1) {
            select_next__19TWindowKeyBoardSoftFv();
            return;
        }
        TWindowKeyBoardSoft__sub_8025D664();
    }
}

void TWindowKeyBoardSoft::vt16() {
  s8 *new_var;
  u32 temp_r3;
  u8 *temp_r4;
  if ((*((u16 *) (((s8 *)this) + 0x60))) & 4)
  {
    if (((*((u16 *) (((s8 *)this) + 0x62))) & 1) && (!((*((s32 *) (((s8 *)this) + 0xB4))) & 0x20)))
    {
      process_input();
      return;
    }
    TWindowKeyBoardSoft__sub_8025D7FC();
    return;
  }
  temp_r4 = (u8 *) (*((u8 **) (((s8 *)this) + 0x68)));
  temp_r3 = *((u32 *) (((s8 *) temp_r4) + 4));
  new_var = (s8 *) temp_r4;
  if (temp_r3 != 0U)
  {
    *((u32 *)(new_var + 4)) = (u32)(temp_r3 - 1);
  }
}

void TWindowKeyBoardSoft::vt15() {
    u32 temp_r3;
    u8 *temp_r4;
    if (*(u16 *)((s8 *)this + 0x60) & 4) {
        if ((*(u16 *)((s8 *)this + 0x62) & 1) && !(*(s32 *)((s8 *)this + 0xB4) & 0x20)) {
            TWindowKeyBoardSoft__sub_8025D664();
            return;
        }
        TWindowKeyBoardSoft__sub_8025D8C8();
        return;
    }
    temp_r4 = *(u8 **)((s8 *)this + 0x68);
    temp_r3 = *(u32 *)((s8 *)temp_r4 + 4);
    if (temp_r3 < (u32) *(u32 *)((s8 *)temp_r4 + 0x10)) {
        *(u32 *)((s8 *)temp_r4 + 4) = (temp_r3 + 1);
    }
}

void TWindowKeyBoardSoft::vt20() {
    u16 temp_r3;
    temp_r3 = *(u16 *)((s8 *)this + 0x60);
    if (temp_r3 & 4) {
        *(u16 *)((s8 *)this + 0x60) = (u16) (temp_r3 & 0xFFFFFFFB);
        return;
    }
    ((TWindowKeyBoardSoft *)(*(void **)((s8 *)this + 0x68)))->delete_char();
    if ((*(u16 *)((s8 *)this + 0x60) & 2) && ((u32) *(u32 *)((s8 *)(*(void **)((s8 *)this + 0x68)) + 0x10) == 0U)) {
        init();
    }
}

void TWindowKeyBoardSoft::handle_backspace() {
    u8 *arg0 = (u8 *)this;
  s8 *new_var;
  u16 temp_r5;
  u32 temp_r3;
  u8 *temp_r4;
  temp_r5 = *((u16 *) (((s8 *) arg0) + 0x60));
  if (temp_r5 & 4)
  {
    if ((*((u16 *) (((s8 *) arg0) + 0x62))) & 1)
    {
      ((TWindowKeyBoardSoft *)arg0)->update();
      return;
    }
    *((u16 *) (((s8 *) arg0) + 0x60)) = (u16) (temp_r5 & 0xFFFFFFFB);
    return;
  }
  temp_r4 = *((u8 **) (((s8 *) arg0) + 0x68));
  ;
  new_var = ((s8 *) temp_r4) + 4;
  if ((*((u32 *) new_var)) == 0U)
  {
    *((u16 *) (((s8 *) arg0) + 0x60)) = (u16) (temp_r5 | 0x20);
    return;
  }
  *((u32 *) new_var) = (u32) ((*((u32 *) new_var)) - 1);
  ((TWindowKeyBoardSoft *)(*((u8 **) (((s8 *) arg0) + 0x68))))->delete_char();
  if (((*((u16 *) (((s8 *) arg0) + 0x60))) & 2) && (((u32) (*((u32 *) (((s8 *) (*((u8 **) (((s8 *) arg0) + 0x68)))) + 0x10)))) == 0U))
  {
    init();
  }
}

void TWindowKeyBoardSoft::vt1() {
    u16 temp_r4;
    u32 temp_r3;
    u8 *temp_r4_2;
    temp_r4 = *(u16 *)((s8 *)this + 0x60);
    if (temp_r4 & 4) {
        if (*(u16 *)((s8 *)this + 0x62) & 1) {
            update();
            return;
        }
        *(u16 *)((s8 *)this + 0x60) = (u16) (temp_r4 & 0xFFFFFFFB);
        return;
    }
    temp_r4_2 = *(u8 **)((s8 *)this + 0x68);
    temp_r3 = *(u32 *)((s8 *)temp_r4_2 + 4);
    if (temp_r3 != 0U) {
        *(u32 *)((s8 *)temp_r4_2 + 4) = (temp_r3 - 1);
        ((TWindowKeyBoardSoft *)(*(u8 **)((s8 *)this + 0x68)))->delete_char();
        if ((*(u16 *)((s8 *)this + 0x60) & 2) && ((u32) *(u32 *)((s8 *)(*(u8 **)((s8 *)this + 0x68)) + 0x10) == 0U)) {
            init();
        }
    }
}

void TWindowKeyBoardSoft::vt21() {
    u8 *self = (u8 *)this;
    u16 temp_r4;
    temp_r4 = *(u16 *)((s8 *)this + 0x60);
    if (temp_r4 & 4) {
        *(u16 *)((s8 *)this + 0x60) = (u16) (temp_r4 & 0xFFFFFFFB);
        return;
    }
    if (temp_r4 & 2) {
        init();
        return;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x7C) != 0U) {
        ((TWindowKeyBoardSoft *)(self + 0x6C))->reset_state();
        return;
    }
    *(u16 *)((s8 *)this + 0x60) = (u16) (temp_r4 | 0x20);
}

void TWindowKeyBoardSoft::update_input_state2() {
    u16 temp_r4;

    temp_r4 = *(u16 *)((s8 *)this + 0x60);
    if (temp_r4 & 4) {
        if (*(s32 *)((s8 *)this + 0xB4) & 0x20) {
            update();
            return;
        }
        select_next__19TWindowKeyBoardSoftFv();
        return;
    }
    if (temp_r4 & 2) {
        convert_input_text();
    }
}

void TWindowKeyBoardSoft::vt19() {
    s32 temp_r4_2;
    u16 temp_r4;
    temp_r4 = *(u16 *)((s8 *)this + 0x60);
    if (temp_r4 & 4) {
        if (*(s32 *)((s8 *)this + 0xB4) & 0x20) {
            update();
            return;
        }
        select_next__19TWindowKeyBoardSoftFv();
        return;
    }
    if (temp_r4 & 2) {
        convert_input_text();
        return;
    }
    temp_r4_2 = *(s32 *)((s8 *)this + 0xB4);
    if (!(temp_r4_2 & 0x80) && !(temp_r4_2 & 0x100) && !(temp_r4_2 & 0x200)) {
        TWindowKeyBoardSoft__sub_800808FC((int) (*(s32 *)((s8 *)this + 0x68)), 0x20);
    }
}

void TWindowKeyBoardSoft::vt0() {
    u8 *self = (u8 *)this;
    if (!(*(u16 *)((s8 *)this + 0x60) & 2)) {
        if (!(*(u16 *)((s8 *)this + 0x62) & 4) || (((TWindowKeyBoardSoft *)(self + 0x6C))->is_buffer_blank() == 0)) {
            *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 1);
        }
    } else {
        commit_composition_text();
    }
}

void TWindowKeyBoardSoft__sub_8025C51C(u8 *window_key_board_soft, s32 arg1) {
    s32 *temp_r3;
    u16 temp_r4;
    u32 temp_r3_2;
    temp_r4 = *(u16 *)((s8 *)window_key_board_soft + 0x60);
    if (temp_r4 & 2) {
        if (temp_r4 & 4) {
            TWindowKeyBoardSoft__sub_8025DBDC(window_key_board_soft, 1);
        }
        ((TWindowKeyBoardSoft *)window_key_board_soft)->commit_composition_text();
    }
    temp_r3 = (s32 *)TWindowCtrl__sub_8024B7D4(arg1);
    if (temp_r3 != NULL) {
        text_builder_reset();
        temp_r3_2 = *(u32 *)((s8 *)window_key_board_soft + 0x70);
        if (temp_r3_2 != 0U) {
            if (temp_r3_2 == (u32) *(u32 *)((s8 *)window_key_board_soft + 0x7C)) {
                text_builder_append((u8 *)&lbl_805DD030);
                text_builder_append((u8 *)temp_r3);
            } else {
                text_builder_append((u8 *)&lbl_805DD034);
                text_builder_append((u8 *)temp_r3);
                text_builder_append((u8 *)&lbl_805DD034);
            }
        } else {
            text_builder_append((u8 *)temp_r3);
            if ((u32) *(u32 *)((s8 *)window_key_board_soft + 0x7C) != 0U) {
                text_builder_append((u8 *)&lbl_805DD034);
            }
        }
        append_text__19TWindowKeyBoardSoftFPvPv(window_key_board_soft + 0x6C, get_shared_text_buffer());
    }
}

int TWindowKeyBoardSoft::get_field_6c() { return set_text_from_string__19TWindowKeyBoardSoftFPc((char*)this + 0x6c); }

void TWindowKeyBoardBase::insert_character(u16 arg1) {
    s32 f;
    if (current_language == LANGUAGE_JAPANESE && arg1 >= 0x80U && arg1 < 0x100U) {
        return;
    }
    if (!(*(u16 *)((s8 *)((u8 *)this) + 0x60) & 0x80) && *(u8 *)((s8 *)((u8 *)this) + 0x64) >= 1U) {
        TWindowKeyBoardSoft__sub_8025DBDC(this, 1);
        if (*(u8 *)((s8 *)((u8 *)this) + 0x64) == 2) {
            *(u16 *)((s8 *)((u8 *)this) + 0x60) |= 0x80;
        }
        if (*(u8 *)((s8 *)((u8 *)this) + 0x64) == 3 && (*(u16 *)((s8 *)((u8 *)this) + 0x60) & 2)) {
            ((TWindowKeyBoardSoft *)((u8 *)this))->commit_composition_text();
        }
    }
    if ((*(u16 *)((s8 *)((u8 *)this) + 0x60) & 4) || (*(s32 *)((s8 *)((u8 *)this) + 0xB4) & 0x40)) {
        ((TWindowKeyBoardSoft *)((u8 *)this))->commit_composition_text();
    }
    f = *(s32 *)((s8 *)((u8 *)this) + 0xB4);
    if ((f & 0x10) && arg1 >= 0x80U) {
        return;
    }
    if ((f & 0x80) && !((s32)arg1 >= 0x41 && (s32)arg1 <= 0x5A)) {
        return;
    }
    if ((f & 0x100) && TWindowKeyBoardSoft::is_alnum(arg1) == 0) {
        return;
    }
    f = *(s32 *)((s8 *)((u8 *)this) + 0xB4);
    if ((f & 0x200) && !((s32)arg1 >= 0x30 && (s32)arg1 <= 0x39)) {
        return;
    }
    if (!(f & 1)) {
        ((s32 (*)(int, u16))TWindowKeyBoardSoft__sub_800808FC)(*(int *)((s8 *)((u8 *)this) + 0x68), arg1);
        return;
    }
    if (!(*(u16 *)((s8 *)((u8 *)this) + 0x60) & 2)) {
        *(void **)((s8 *)((u8 *)this) + 0x68) = (void *)(((u8 *)this) + 0x84);
        *(u16 *)((s8 *)((u8 *)this) + 0x60) |= 2;
    }
    ((s32 (*)(int, u16))TWindowKeyBoardSoft__sub_800808FC)(*(int *)((s8 *)((u8 *)this) + 0x68), arg1);
    if (*(u8 *)((s8 *)((u8 *)this) + 0x64) == 0 && !(*(u16 *)((s8 *)((u8 *)this) + 0x60) & 0x80)) {
        TWindowKeyBoardSoft__sub_8025DBDC(this, 0);
    }
}

void TWindowKeyBoardSoft::init() {
    u8 *arg0 = (u8 *)this;
    ((TWindowKeyBoardSoft *)(arg0 + 0x84))->reset_state();
    *(s32 *)((s8 *)arg0 + 0x68) = (s32)(arg0 + 0x6C);
    *(u16 *)((s8 *)arg0 + 0x60) = (u16) (*(u16 *)((s8 *)arg0 + 0x60) & ~0x86);
}

#pragma push
#pragma opt_propagation off
s32 TWindowKeyBoardSoft::commit_composition_text() {
    Kbd_8025C804 *arg0 = (Kbd_8025C804 *)this;
    s32 n;
    s32 nx;
    s8 *src;
    u16 *dst;
    u16 c;
    u32 cnt;
    u32 i;
    u16 *s;
    u16 *d;
    if (arg0->flags & 4) {
        TWindowKeyBoardSoft__sub_8025DBDC(arg0, 1);
        src = arg0->src;
        i = 0;
        dst = arg0->buf;
        while (*src != 0) {
            cnt = src[1];
            src += 3;
            while (cnt-- != 0 && i < arg0->max) {
                c = *src++;
                if ((c & 0xE0) == 0x80 || (c & 0xE0) == 0xE0) {
                    c = (u8)c << 8;
                    c |= *src & 0xFF;
                    cnt--;
                    src++;
                }
                *dst++ = c;
                i++;
            }
        }
        *dst = 0;
        arg0->len = i;
        arg0->flags &= ~4;
    }
    ((TWindowKeyBoardSoft *)(&arg0->field))->check_text_overflow(arg0->buf);
    s = arg0->buf;
    n = 0;
    while ((s32)*s != 0) {
        s++;
        n++;
    }
    if (n > 0) {
        ((TWindowKeyBoardSoft *)(&arg0->field))->make_room_in_buffer(arg0->field.cursor, n);
        s = arg0->buf;
        d = arg0->field.buffer + arg0->field.cursor;
        while ((s32)*s != 0) {
            *d++ = *s++;
        }
        arg0->field.cursor += n;
    }
    ((TWindowKeyBoardSoft *)arg0)->init();
}
#pragma pop

void export_keyboard_text(Base_8025C974 *base, char *out) {
    u32 a = 0;
    u32 b = 0;
    u32 c = 0;
    u16 code;
    u16 *in = base->field.buffer;
    if (!(base->fb4 & 0x10) && (s32)*in != 0) {
        out[0] = 9;
        if (current_language == LANGUAGE_JAPANESE) {
            out[1] = 'J';
            out += 2;
        } else {
            out[1] = 'E';
            out += 2;
        }
    }
    while ((s32)*in != 0) {
        code = *in++;
        get_font_char_advance(map_char_to_font_code(code));
        if (((TWindowKeyBoardSoft *)(&base->field))->measure_char_overflow(code, &a, &b, &c)) {
            *out = 0;
            return;
        }
        if (code & 0xFF00) {
            *out++ = (code >> 8) & 0xFF;
        }
        *out++ = code;
    }
    *out = 0;
}

s32 TWindowKeyBoardSoft::measure_text_overflow() {
    Base_8025C974 *arg0 = (Base_8025C974 *)this;
    u32 a = 0;
    u32 b = 0;
    u32 c = 0;
    u16 ch;
    u16 *p = arg0->field.buffer;
    while ((s32)*p != 0) {
        ch = *p++;
        if (((TWindowKeyBoardSoft *)(&arg0->field))->measure_char_overflow(ch, &a, &b, &c) != 0) {
            break;
        }
    }
    c += 1;
    if (!(arg0->fb4 & 0x10)) {
        c += 2;
    }
    return c;
}

int TWindowKeyBoardSoft::is_key_state_2() { return (*(u16*)((char*)this + 0x60) >> 2) & 0x1; }

}
