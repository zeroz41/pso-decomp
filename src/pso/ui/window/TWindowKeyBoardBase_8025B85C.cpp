#include "types.h"
#include "pso/ui/window/TWindowCtrl_8024B7D4.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/Language.h"

#pragma readonly_strings on

extern "C" {
s32 is_chat_shortcut_set(int);
s32 TWindowKeyBoardSoft__sub_803E67D4(void *, void *);
saddr get_shared_text_buffer();

int TWindowKeyBoardBase::is_alnum(u16 code) {
    if ((s32) code < 0x30) {
        return 0;
    }
    if ((s32) code <= 0x39) {
        return 1;
    }
    if ((s32) code < 0x41) {
        return 0;
    }
    if ((s32) code <= 0x5A) {
        return 1;
    }
    if ((s32) code < 0x61) {
        return 0;
    }
    if ((s32) code <= 0x7A) {
        return 1;
    }
    return 0;
}

s32 TWindowKeyBoardBase::get_state() { return m_text.cursor; }

void TWindowKeyBoardBase::vt2() {
    if (*(u16 *)((s8 *)this + 0x60) & 2) {
        init();
    }
    if ((u32) *(u32 *)((s8 *)this + 0x7C) != 0U) {
        this->m_text.reset_state();
    }
    *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x20);
}

void TWindowKeyBoardBase::sub_8025B928() {  }

void TWindowKeyBoardBase::sub_8025B92C() {
    s8 sp108[0x100];
    s8 sp8[0x100];
    s32 var_r3;
    u16 temp_r4;
    temp_r4 = *(u16 *)((s8 *)this + 0x60);
    if (temp_r4 & 2) {
        if (!(temp_r4 & 4)) {
            convert_input_text();
            var_r3 = this->candidate_count;
            if (!(*(u16 *)((s8 *)this + 0x60) & 0x10)) {
                do {
                    this->candidate_count = var_r3;
                    var_r3 = TWindowKeyBoardSoft__sub_803E67D4(sp8, sp108);
                } while (var_r3 != 0);
                sub_8025CFA8((s32 *)sp8);
                sp8[0] = 0;
                write_name_and_text((char *)sp8, (char *)sp8);
                goto block_5;
            }
        } else {
block_5:
            if ((s32) this->candidate_index != 0xF1) {
                set_kana_mode();
                return;
            }
            set_kanji_mode();
        }
    }
}

void TWindowKeyBoardBase::update_input_state() {
    u16 temp_r4;

    temp_r4 = *(u16 *)((s8 *)this + 0x60);
    if (temp_r4 & 4) {
        if (*(s32 *)((s8 *)this + 0xB4) & 0x20) {
            update();
            return;
        }
        select_next();
        return;
    }
    if (temp_r4 & 2) {
        convert_input_text();
    }
}

void TWindowKeyBoardBase::sub_8025BA28() {
    u8 *temp_r3;
    if (!(*(u16 *)((s8 *)this + 0x60) & 4)) {
        temp_r3 = *(u8 **)((s8 *)this + 0x68);
        *(s32 *)((s8 *)temp_r3 + 4) = (s32) *(s32 *)((s8 *)temp_r3 + 0x10);
    }
}

void TWindowKeyBoardBase::sub_8025BA44() {
    if (!(*(u16 *)((s8 *)this + 0x60) & 4)) {
        *(s32 *)((s8 *)(*(void **)((s8 *)this + 0x68)) + 4) = 0;
    }
}

void TWindowKeyBoardBase::vt14() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8) && !(*(s32 *)((s8 *)this + 0xB4) & 0x20) && !(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(0x13) != 0)) {
        *(s8 *)((s8 *)this + 0x65) = 0x13;
        *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
    }
}

void TWindowKeyBoardBase::vt13() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8) && !(*(s32 *)((s8 *)this + 0xB4) & 0x20) && !(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(0x12) != 0)) {
        *(s8 *)((s8 *)this + 0x65) = 0x12;
        *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
    }
}

void TWindowKeyBoardBase::vt12() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8) && !(*(s32 *)((s8 *)this + 0xB4) & 0x20) && !(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(0x11) != 0)) {
        *(s8 *)((s8 *)this + 0x65) = 0x11;
        *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
    }
}

void TWindowKeyBoardBase::vt11() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8) && !(*(s32 *)((s8 *)this + 0xB4) & 0x20) && !(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(0x10) != 0)) {
        *(s8 *)((s8 *)this + 0x65) = 0x10;
        *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
    }
}

void TWindowKeyBoardBase::vt10() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8) && !(*(s32 *)((s8 *)this + 0xB4) & 0x20) && !(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(0xF) != 0)) {
        *(s8 *)((s8 *)this + 0x65) = 0xF;
        *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
    }
}

void TWindowKeyBoardBase::vt9() {
    s8 sp108[0x100];
    s8 sp8[0x100];
    s32 var_r3;
    u16 temp_r4;
    if (!(*(s32 *)((s8 *)this + 0xB4) & 0x20)) {
        temp_r4 = *(u16 *)((s8 *)this + 0x60);
        if (temp_r4 & 2) {
            if (!(temp_r4 & 4)) {
                convert_input_text();
                var_r3 = this->candidate_count;
                if (!(*(u16 *)((s8 *)this + 0x60) & 0x10)) {
                    do {
                        this->candidate_count = var_r3;
                        var_r3 = TWindowKeyBoardSoft__sub_803E67D4(sp8, sp108);
                    } while (var_r3 != 0);
                    sub_8025CFA8((s32 *)sp8);
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

void TWindowKeyBoardBase::vt8() {
    s8 sp108[0x100];
    s8 sp8[0x100];
    s32 var_r3;
    u16 temp_r4;
    if (!(*(s32 *)((s8 *)this + 0xB4) & 0x20)) {
        temp_r4 = *(u16 *)((s8 *)this + 0x60);
        if (temp_r4 & 2) {
            if (!(temp_r4 & 4)) {
                convert_input_text();
                var_r3 = this->candidate_count;
                if (!(*(u16 *)((s8 *)this + 0x60) & 0x10)) {
                    do {
                        this->candidate_count = var_r3;
                        var_r3 = TWindowKeyBoardSoft__sub_803E67D4(sp8, sp108);
                    } while (var_r3 != 0);
                    sub_8025CFA8((s32 *)sp8);
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

void TWindowKeyBoardBase::vt7() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8) && !(*(s32 *)((s8 *)this + 0xB4) & 0x20) && !(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(0xC) != 0)) {
        *(s8 *)((s8 *)this + 0x65) = 0xC;
        *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
    }
}

void TWindowKeyBoardBase::vt6() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8) && !(*(s32 *)((s8 *)this + 0xB4) & 0x20) && !(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(0xB) != 0)) {
        *(s8 *)((s8 *)this + 0x65) = 0xB;
        *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
    }
}

void TWindowKeyBoardBase::vt5() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8)) {
        if (*(s32 *)((s8 *)this + 0xB4) & 0x20) {
            sub_8025C51C(2);
            return;
        }
        if (!(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(0xA) != 0)) {
            *(s8 *)((s8 *)this + 0x65) = 0xA;
            *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
        }
    }
}

void TWindowKeyBoardBase::vt4() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8)) {
        if (*(s32 *)((s8 *)this + 0xB4) & 0x20) {
            sub_8025C51C(1);
            return;
        }
        if (!(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(9) != 0)) {
            *(s8 *)((s8 *)this + 0x65) = 9;
            *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
        }
    }
}

void TWindowKeyBoardBase::vt3() {
    if (!(*(u16 *)((s8 *)this + 0x62) & 8)) {
        if (*(s32 *)((s8 *)this + 0xB4) & 0x20) {
            sub_8025C51C(0);
            return;
        }
        if (!(*(u16 *)((s8 *)this + 0x60) & 2) && (is_chat_shortcut_set(8) != 0)) {
            *(s8 *)((s8 *)this + 0x65) = 8;
            *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x41);
        }
    }
}

void TWindowKeyBoardBase::vt17() {
    if (*(u16 *)((s8 *)this + 0x60) & 4) {
        if (*(u16 *)((s8 *)this + 0x62) & 1) {
            update();
            return;
        }
        process_input();
    }
}

void TWindowKeyBoardBase::vt18() {
    if (*(u16 *)((s8 *)this + 0x60) & 4) {
        if (*(u16 *)((s8 *)this + 0x62) & 1) {
            select_next();
            return;
        }
        sub_8025D664();
    }
}

void TWindowKeyBoardBase::vt16() {
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
    sub_8025D7FC();
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

void TWindowKeyBoardBase::vt15() {
    u32 temp_r3;
    u8 *temp_r4;
    if (*(u16 *)((s8 *)this + 0x60) & 4) {
        if ((*(u16 *)((s8 *)this + 0x62) & 1) && !(*(s32 *)((s8 *)this + 0xB4) & 0x20)) {
            sub_8025D664();
            return;
        }
        sub_8025D8C8();
        return;
    }
    temp_r4 = *(u8 **)((s8 *)this + 0x68);
    temp_r3 = *(u32 *)((s8 *)temp_r4 + 4);
    if (temp_r3 < (u32) *(u32 *)((s8 *)temp_r4 + 0x10)) {
        *(u32 *)((s8 *)temp_r4 + 4) = (temp_r3 + 1);
    }
}

void TWindowKeyBoardBase::vt20() {
    u16 temp_r3;
    temp_r3 = *(u16 *)((s8 *)this + 0x60);
    if (temp_r3 & 4) {
        *(u16 *)((s8 *)this + 0x60) = (u16) (temp_r3 & 0xFFFFFFFB);
        return;
    }
    ((KeyboardTextBuffer *)(*(void **)((s8 *)this + 0x68)))->delete_char();
    if ((*(u16 *)((s8 *)this + 0x60) & 2) && ((u32) *(u32 *)((s8 *)(*(void **)((s8 *)this + 0x68)) + 0x10) == 0U)) {
        init();
    }
}

void TWindowKeyBoardBase::handle_backspace() {
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
      ((TWindowKeyBoardBase *)arg0)->update();
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
  ((KeyboardTextBuffer *)(*((u8 **) (((s8 *) arg0) + 0x68))))->delete_char();
  if (((*((u16 *) (((s8 *) arg0) + 0x60))) & 2) && (((u32) (*((u32 *) (((s8 *) (*((u8 **) (((s8 *) arg0) + 0x68)))) + 0x10)))) == 0U))
  {
    init();
  }
}

void TWindowKeyBoardBase::vt1() {
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
        ((KeyboardTextBuffer *)(*(u8 **)((s8 *)this + 0x68)))->delete_char();
        if ((*(u16 *)((s8 *)this + 0x60) & 2) && ((u32) *(u32 *)((s8 *)(*(u8 **)((s8 *)this + 0x68)) + 0x10) == 0U)) {
            init();
        }
    }
}

void TWindowKeyBoardBase::vt21() {
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
        this->m_text.reset_state();
        return;
    }
    *(u16 *)((s8 *)this + 0x60) = (u16) (temp_r4 | 0x20);
}

void TWindowKeyBoardBase::update_input_state2() {
    u16 temp_r4;

    temp_r4 = *(u16 *)((s8 *)this + 0x60);
    if (temp_r4 & 4) {
        if (*(s32 *)((s8 *)this + 0xB4) & 0x20) {
            update();
            return;
        }
        select_next();
        return;
    }
    if (temp_r4 & 2) {
        convert_input_text();
    }
}

void TWindowKeyBoardBase::vt19() {
    s32 temp_r4_2;
    u16 temp_r4;
    temp_r4 = *(u16 *)((s8 *)this + 0x60);
    if (temp_r4 & 4) {
        if (*(s32 *)((s8 *)this + 0xB4) & 0x20) {
            update();
            return;
        }
        select_next();
        return;
    }
    if (temp_r4 & 2) {
        convert_input_text();
        return;
    }
    temp_r4_2 = *(s32 *)((s8 *)this + 0xB4);
    if (!(temp_r4_2 & 0x80) && !(temp_r4_2 & 0x100) && !(temp_r4_2 & 0x200)) {
        ((KeyboardTextBuffer *)(*(saddr *)((s8 *)this + 0x68)))->insert_char(0x20);
    }
}

void TWindowKeyBoardBase::vt0() {
    if (!(*(u16 *)((s8 *)this + 0x60) & 2)) {
        if (!(*(u16 *)((s8 *)this + 0x62) & 4) || (this->m_text.is_buffer_blank() == 0)) {
            *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 1);
        }
    } else {
        commit_composition_text();
    }
}

#define window_key_board_soft ((u8 *)this)
void TWindowKeyBoardBase::sub_8025C51C(s32 arg1) {
    s32 *str;
    u16 temp_r4;
    u32 temp_r3_2;
    temp_r4 = *(u16 *)((s8 *)window_key_board_soft + 0x60);
    if (temp_r4 & 2) {
        if (temp_r4 & 4) {
            ((TWindowKeyBoardBase *)window_key_board_soft)->sub_8025DBDC(1);
        }
        ((TWindowKeyBoardBase *)window_key_board_soft)->commit_composition_text();
    }
    str = (s32 *)TWindowCtrl__sub_8024B7D4(arg1);
    if (str != NULL) {
        text_builder_reset();
        temp_r3_2 = *(u32 *)((s8 *)window_key_board_soft + 0x70);
        if (temp_r3_2 != 0U) {
            if (temp_r3_2 == (u32) *(u32 *)((s8 *)window_key_board_soft + 0x7C)) {
                text_builder_append((u8 *)" > ");
                text_builder_append((u8 *)str);
            } else {
                text_builder_append((u8 *)" ");
                text_builder_append((u8 *)str);
                text_builder_append((u8 *)" ");
            }
        } else {
            text_builder_append((u8 *)str);
            if ((u32) *(u32 *)((s8 *)window_key_board_soft + 0x7C) != 0U) {
                text_builder_append((u8 *)" ");
            }
        }
        ((KeyboardTextBuffer *)(window_key_board_soft + 0x6C))->append_text((u8 *)get_shared_text_buffer());
    }
}
#undef window_key_board_soft

void TWindowKeyBoardBase::set_text(char *s) { m_text.set_text_from_string(s); }

void TWindowKeyBoardBase::insert_character(u16 code) {
    s32 f;
    if (current_language == LANGUAGE_JAPANESE && code >= 0x80U && code < 0x100U) {
        return;
    }
    if (!(*(u16 *)((s8 *)((u8 *)this) + 0x60) & 0x80) && this->m_input_mode >= 1U) {
        sub_8025DBDC(1);
        if (this->m_input_mode == 2) {
            *(u16 *)((s8 *)((u8 *)this) + 0x60) |= 0x80;
        }
        if (this->m_input_mode == 3 && (*(u16 *)((s8 *)((u8 *)this) + 0x60) & 2)) {
            ((TWindowKeyBoardBase *)((u8 *)this))->commit_composition_text();
        }
    }
    if ((*(u16 *)((s8 *)((u8 *)this) + 0x60) & 4) || (*(s32 *)((s8 *)((u8 *)this) + 0xB4) & 0x40)) {
        ((TWindowKeyBoardBase *)((u8 *)this))->commit_composition_text();
    }
    f = *(s32 *)((s8 *)((u8 *)this) + 0xB4);
    if ((f & 0x10) && code >= 0x80U) {
        return;
    }
    if ((f & 0x80) && !((s32)code >= 0x41 && (s32)code <= 0x5A)) {
        return;
    }
    if ((f & 0x100) && TWindowKeyBoardBase::is_alnum(code) == 0) {
        return;
    }
    f = *(s32 *)((s8 *)((u8 *)this) + 0xB4);
    if ((f & 0x200) && !((s32)code >= 0x30 && (s32)code <= 0x39)) {
        return;
    }
    if (!(f & 1)) {
        ((KeyboardTextBuffer *)(*(saddr *)((s8 *)((u8 *)this) + 0x68)))->insert_char(code);
        return;
    }
    if (!(*(u16 *)((s8 *)((u8 *)this) + 0x60) & 2)) {
        *(void **)((s8 *)((u8 *)this) + 0x68) = (void *)(((u8 *)this) + 0x84);
        *(u16 *)((s8 *)((u8 *)this) + 0x60) |= 2;
    }
    ((KeyboardTextBuffer *)(*(saddr *)((s8 *)((u8 *)this) + 0x68)))->insert_char(code);
    if (this->m_input_mode == 0 && !(*(u16 *)((s8 *)((u8 *)this) + 0x60) & 0x80)) {
        sub_8025DBDC(0);
    }
}

void TWindowKeyBoardBase::init() {
    u8 *arg0 = (u8 *)this;
    this->m_text2.reset_state();
    *(s32 *)((s8 *)arg0 + 0x68) = (saddr)(arg0 + 0x6C);
    *(u16 *)((s8 *)arg0 + 0x60) = (u16) (*(u16 *)((s8 *)arg0 + 0x60) & ~0x86);
}

#pragma push
#pragma opt_propagation off
void TWindowKeyBoardBase::commit_composition_text() {
    TWindowKeyBoardBase *arg0 = this;
    s32 n;
    s32 nx;
    s8 *src;
    u16 *dst;
    u16 c;
    u32 cnt;
    u32 i;
    u16 *s;
    u16 *d;
    if (arg0->m_60 & 4) {
        arg0->sub_8025DBDC(1);
        src = reinterpret_cast<s8 *>(arg0->candidate_buffer);
        i = 0;
        dst = arg0->m_text2.buffer;
        while (*src != 0) {
            cnt = src[1];
            src += 3;
            while (cnt-- != 0 && i < arg0->m_text2.capacity) {
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
        arg0->m_text2.length = i;
        arg0->m_60 &= ~4;
    }
    arg0->m_text.check_text_overflow(arg0->m_text2.buffer);
    s = arg0->m_text2.buffer;
    n = 0;
    while ((s32)*s != 0) {
        s++;
        n++;
    }
    if (n > 0) {
        arg0->m_text.make_room_in_buffer(arg0->m_text.cursor, n);
        s = arg0->m_text2.buffer;
        d = arg0->m_text.buffer + arg0->m_text.cursor;
        while ((s32)*s != 0) {
            *d++ = *s++;
        }
        arg0->m_text.cursor += n;
    }
    arg0->init();
}
#pragma pop

void TWindowKeyBoardBase::export_text(char *out) {
    TWindowKeyBoardBase *base = this;
    u32 a = 0;
    u32 b = 0;
    u32 c = 0;
    u16 code;
    u16 *in = base->m_text.buffer;
    if (!(base->composition_flags & 0x10) && (s32)*in != 0) {
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
        if (base->m_text.measure_char_overflow(code, &a, &b, &c)) {
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

s32 TWindowKeyBoardBase::measure_text_overflow() {
    TWindowKeyBoardBase *arg0 = this;
    u32 a = 0;
    u32 b = 0;
    u32 c = 0;
    u16 ch;
    u16 *p = arg0->m_text.buffer;
    while ((s32)*p != 0) {
        ch = *p++;
        if (arg0->m_text.measure_char_overflow(ch, &a, &b, &c) != 0) {
            break;
        }
    }
    c += 1;
    if (!(arg0->composition_flags & 0x10)) {
        c += 2;
    }
    return c;
}

int TWindowKeyBoardBase::is_key_state_2() { return (m_60 >> 2) & 1; }

}
