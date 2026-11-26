// TWindowDD calls TObject::queue_destruction out of line (bl to the TAdADXlogo copy).
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/WordSelectMessage.h"
#include "types.h"
#include <string.h>
#include "pso/ui/window/TWindowDD_8034435C.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDD_80346A84.h"
#include "pso/ui/window/TWindowDD_80346F48.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"
#include "pso/ui/window/TWindowDD_803471C0.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/WindowVertexBufferAbi.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowDD_803488A8.h"
#include "pso/ui/window/TWindowDD_WS_ScrollBar.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD_WS_String.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/ui/window/TWindowWordSelectMode.h"
#include "pso/ui/window/TWindowDD_WS_Word.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/network/TLobby.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowDD_80348304.h"
#include "pso/ui/window/TWindowDD_8034AF68.h"
#include "pso/map/FloorArea.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/TWindowDD_80348BF4.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/ui/window/TWindowDD_80348D0C.h"
#include "pso/system/byteswap.h"



extern "C" {
s32 TWindowDD__sub_80347858(s16 id);
void append_word_select_entry_words(WordSelectMessage *entry, char *buf, s32 *pos);
void append_word_select_word(WordSelectMessage *entry, s16 id, char *buf, s32 *pos);
void append_word_select_token(s16 id, char *buf, s32 *pos);
void TWindowDD__sub_80347758(WordSelectMessage *src, WordSelectMessage *dst);
void append_word_select_word_with_number(WordSelectMessage *entry, s16 id, char *word, char *buf, s32 *pos);
char to_upper_latin1(char);
void TWindowDD__sub_8034694C(WordSelectMessage *, s16, char *, char *, char *, s32 *);
s32 TWindowDD::get_entry_value_french(u32 mode, s32 entry_id, s32 value_index) {
    s32 v;
    switch (mode) {
    case 0:
        v = TWindowDD_read_indexed_value(get_initial_word_select_list(this), value_index);
        if (v == -0x1E) {
            switch (this->get_word_select_context()) {
            case 1:
                v = 0x10;
                break;
            case 0:
                v = 0xF;
                break;
            case 3:
                v = 0x12;
                break;
            case 2:
                v = 0x11;
                break;
            case 4:
                v = 0x13;
                break;
            case 5:
                v = 0x14;
                break;
            }
        }
        break;
    case 1:
    case 2:
    case 6:
        v = -0x3C;
        break;
    case 3: {
        s16 resolved = TWindowDD_read_resolved_value(entry_id, value_index);
        if (TWindowDD__sub_80347858(resolved) != 0) {
            if (resolved == 0x43) {
                v = -0x46;
            } else if (resolved == 0x44) {
                v = -0x5A;
            } else {
                v = -0x50;
            }
        } else {
            v = -0x3C;
        }
        break;
    }
    case 5:
        v = TWindowDD_read_indexed_value(0xE, value_index);
        break;
    case 12:
        {
            s16 t = TWindowDD_read_resolved_value(0xF9, value_index);
            if (t == 0x43) {
                v = -0x46;
            } else if (t == 0x44) {
                v = -0x5A;
            } else {
                v = -0x50;
            }
        }
        break;
    case 13:
        if (TWindowDD_read_resolved_value(-0x50, value_index) == 0x2C8) {
            v = TWindowDD::ws_data_table[0xF].values[this->selected_word - 0x37];
        } else {
            v = TWindowDD::ws_data_table[0x10].values[this->selected_word - 0x37];
        }
        break;
    case 14:
        v = TWindowDD_read_indexed_value(0xF, this->selected_word - 0x37);
        break;
    case 15:
        v = -0x32;
        break;
    case 17:
        v = TWindowDD_read_indexed_value(0x11, this->selected_word - 0x37);
        break;
    case 18:
        v = -0x32;
        break;
    default:
        v = -1;
        break;
    }
    return v;
}
s32 TWindowDD::get_entry_value_german(u32 mode, s32 entry_id, s32 value_index) {
    s32 v;
    switch (mode) {
    case 0:
        v = TWindowDD_read_indexed_value(get_initial_word_select_list(this), value_index);
        if (v == -0x1E) {
            switch (this->get_word_select_context()) {
            case 1:
                v = 0x10;
                break;
            case 0:
                v = 0xF;
                break;
            case 3:
                v = 0x12;
                break;
            case 2:
                v = 0x11;
                break;
            case 4:
                v = 0x13;
                break;
            case 5:
                v = 0x14;
                break;
            }
        }
        break;
    case 1:
    case 2:
    case 6:
        v = -0x3C;
        break;
    case 3: {
        s16 resolved = TWindowDD_read_resolved_value(entry_id, value_index);
        if (TWindowDD__sub_80347858(resolved) != 0) {
            if (resolved == 0x43) {
                v = -0x46;
            } else if (resolved == 0x44) {
                v = -0x5A;
            } else {
                v = -0x50;
            }
        } else {
            v = -0x3C;
        }
        break;
    }
    case 5:
        v = TWindowDD_read_indexed_value(0xE, value_index);
        break;
    case 12:
        {
            s16 t = TWindowDD_read_resolved_value(0xF9, value_index);
            if (t == 0x43) {
                v = -0x46;
            } else if (t == 0x44) {
                v = -0x5A;
            } else {
                v = -0x50;
            }
        }
        break;
    case 13:
        if (TWindowDD_read_resolved_value(-0x50, value_index) == 0x2C8) {
            v = TWindowDD::ws_data_table[0xF].values[this->selected_word - 0x37];
        } else {
            v = TWindowDD::ws_data_table[0x10].values[this->selected_word - 0x37];
        }
        break;
    case 14:
        v = TWindowDD_read_indexed_value(0xF, this->selected_word - 0x37);
        break;
    case 15:
        v = -0x32;
        break;
    case 17:
        v = TWindowDD_read_indexed_value(0x11, this->selected_word - 0x37);
        break;
    case 18:
        v = -0x32;
        break;
    default:
        v = -1;
        break;
    }
    return v;
}
s32 TWindowDD::get_entry_value_spanish(u32 mode, s32 entry_id, s32 value_index) {
    s32 v;
    switch (mode) {
    case 0:
        v = TWindowDD_read_indexed_value(get_initial_word_select_list(this), value_index);
        if (v == -0x1E) {
            switch (this->get_word_select_context()) {
            case 1:
                v = 0x10;
                break;
            case 0:
                v = 0xF;
                break;
            case 3:
                v = 0x12;
                break;
            case 2:
                v = 0x11;
                break;
            case 4:
                v = 0x13;
                break;
            case 5:
                v = 0x14;
                break;
            }
        }
        break;
    case 1:
    case 2:
    case 6:
        v = -0x3C;
        break;
    case 3: {
        s16 resolved = TWindowDD_read_resolved_value(entry_id, value_index);
        if (TWindowDD__sub_80347858(resolved) != 0) {
            if (resolved == 0x43) {
                v = -0x46;
            } else if (resolved == 0x44) {
                v = -0x5A;
            } else {
                v = -0x50;
            }
        } else {
            v = -0x3C;
        }
        break;
    }
    case 5:
        v = TWindowDD_read_indexed_value(0xE, value_index);
        break;
    case 12:
        {
            s16 t = TWindowDD_read_resolved_value(0xF9, value_index);
            if (t == 0x43) {
                v = -0x46;
            } else if (t == 0x44) {
                v = -0x5A;
            } else {
                v = -0x50;
            }
        }
        break;
    case 13:
        if (TWindowDD_read_resolved_value(-0x50, value_index) == 0x2C8) {
            v = TWindowDD::ws_data_table[0xF].values[this->selected_word - 0x37];
        } else {
            v = TWindowDD::ws_data_table[0x10].values[this->selected_word - 0x37];
        }
        break;
    case 14:
        v = TWindowDD_read_indexed_value(0xF, this->selected_word - 0x37);
        break;
    case 15:
        v = -0x32;
        break;
    case 17:
        v = TWindowDD_read_indexed_value(0x11, this->selected_word - 0x37);
        break;
    case 18:
        v = -0x32;
        break;
    default:
        v = -1;
        break;
    }
    return v;
}

s32 format_message_text__9TWindowDDFPvPvUs(WordSelectMessage *src, char *window_dd, u16 player) {
    s32 k;
    s32 n;
    s32 m;
    s32 i;
    s32 pos;
    i = 0;
    pos = i;
    n = src->count;
    if (n == 0) {
        window_dd[0] = i;
        return 1;
    }
    switch (src->type) {
    case 1:
        append_word_select_entry_words(src, window_dd, &pos);
        break;
    case 2:
        if (n > 2) {
            n = 2;
        }
        for (m = 0; m < n; m++) {
            if (m == 1) {
                TWindowDD::append_char(0x20, window_dd, &pos);
            }
            append_word_select_token(src->ids[m], window_dd, &pos);
        }
        TWindowDD::append_char(0x3F, window_dd, &pos);
        if (src->count > 2) {
            ((TWindowDD *)window_dd)->append_prompt_newline(&pos);
            append_word_select_token(src->ids[2], window_dd, &pos);
        }
        break;
    case 3:
        if (n > 1) {
            WordSelectMessage copy;
            TWindowDD__sub_80347758(src, &copy);
            pos = format_message_text__9TWindowDDFPvPvUs(&copy, window_dd, player);
        } else {
            append_word_select_token(src->ids[0], window_dd, &pos);
        }
        break;
    case 4: {
        s32 id = src->ids[0];
        k = 0;
        if (id == 0x2C4) {
            append_word_select_token(id, window_dd, &pos);
        } else if (id == 0x2C7) {
            append_word_select_token(id, window_dd, &pos);
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(ws_word_strings[0xA58 / 4], window_dd, &pos);
            k = 2;
        } else if (id >= 0x68C && id <= 0x697) {
            append_word_select_token(id, window_dd, &pos);
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(ws_word_strings[0xA4C / 4], window_dd, &pos);
            k = 1;
        } else if (id == 0x698) {
            TWindowDD::append_string(ws_word_strings[0xA4C / 4], window_dd, &pos);
            k = 1;
        }
        if (n > 1) {
            i = src->ids[1];
            TWindowDD::show_message_by_count(window_dd, &pos);
            if (k == 0) {
                append_word_select_token(i, window_dd, &pos);
            } else {
                TWindowDDValueList *p;
                if (k == 1) {
                    p = &TWindowDD__data_805D6E40[1];
                } else {
                    p = &TWindowDD__data_805D6E40[0];
                }
                TWindowDD::append_string(ws_word_strings[p->values[i - 0x5AC]], window_dd, &pos);
            }
        }
        if (n > 2) {
            TWindowDD::show_message_by_count(window_dd, &pos);
            append_word_select_word(src, src->ids[2], window_dd, &pos);
        }
        if (n > 3) {
            append_word_select_token(src->ids[3], window_dd, &pos);
        }
        window_dd[0] = to_upper_latin1(window_dd[0]);
        break;
    }
    case 5: {
        s32 mode;
        k = src->ids[0];
        append_word_select_word(src, k, window_dd, &pos);
        if (k == 0x2C4) {
            mode = 0;
            i = TWindowDD::get_player_battle_flag_state(player);
        } else if (k == 0x2C7) {
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(ws_word_strings[0xA58 / 4], window_dd, &pos);
            mode = 2;
            if (TWindowDD::get_player_battle_flag_state(player) == 2) {
                i = 3;
            } else {
                i = 1;
            }
        } else if (k >= 0x68C && k <= 0x697) {
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(ws_word_strings[0xA4C / 4], window_dd, &pos);
            mode = 1;
            i = TWindowDD::get_player_battle_flag_state(k - 0x68C);
        } else {
            mode = 3;
            if (k == 0x2C5) {
                i = 0;
            } else if (k == 0x2C6) {
                i = 2;
            } else {
                switch (TWindowDD__data_805D6E48[TWindowDD::clamp_range_2C9_552(k)]) {
                case 0:
                    i = 0;
                    break;
                case 1:
                    i = 1;
                    break;
                case 2:
                    i = 2;
                    break;
                case 3:
                    i = 3;
                    break;
                }
            }
        }
        if (n > 1) {
            s32 found;
            s32 j;
            TWindowDD::show_message_by_count(window_dd, &pos);
            found = 1;
            k = src->ids[1];
            for (j = 0; j < TWindowDD__data_805D6E44[3].count; j++) {
                if (k == TWindowDD__data_805D6E44[3].values[j]) {
                    found = 0;
                    break;
                }
            }
            if (found != 0) {
                switch (mode) {
                case 0:
                    TWindowDD::append_string(ws_word_strings[0x1A8C / 4], window_dd, &pos);
                    break;
                case 1:
                    TWindowDD::append_string(ws_word_strings[0x1A94 / 4], window_dd, &pos);
                    break;
                case 2:
                    TWindowDD::append_string(ws_word_strings[0x1A90 / 4], window_dd, &pos);
                    break;
                case 3:
                    TWindowDD::append_string(ws_word_strings[0x1A98 / 4], window_dd, &pos);
                    break;
                }
                TWindowDD::show_message_by_count(window_dd, &pos);
            }
            if (i == 0) {
                append_word_select_word(src, k, window_dd, &pos);
            } else {
                TWindowDDValueList *p;
                if (i == 1) {
                    p = &TWindowDD__data_805D6E44[0];
                } else if (i == 2) {
                    p = &TWindowDD__data_805D6E44[1];
                } else {
                    p = &TWindowDD__data_805D6E44[2];
                }
                append_word_select_word_with_number(src, k, ws_word_strings[p->values[TWindowDD::clamp_range_5FA_682(k)]], window_dd, &pos);
            }
        }
        if (n > 2) {
            append_word_select_token(src->ids[2], window_dd, &pos);
        }
        window_dd[0] = to_upper_latin1(window_dd[0]);
        break;
    }
    case 6:
        src->format_type6_message((saddr)window_dd, (&pos));
        break;
    }
    window_dd[pos++] = 0;
    return pos;
}

s32 format_german_message__9TWindowDDFPvPvUs(WordSelectMessage *src, char *window_dd, u16 player) {
    s32 pos;
    s32 id;
    s32 kind;
    s32 n;
    pos = 0;
    n = src->count;
    if (n == 0) {
        window_dd[0] = 0;
        return 1;
    }
    switch (src->type) {
    case 1:
        append_word_select_entry_words(src, window_dd, &pos);
        break;
    case 2:
        if (n > 2) {
            n = 2;
        }
        {
        s32 i;
        for (i = 0; i < n; i++) {
            if (i == 1) {
                TWindowDD::append_char(0x20, window_dd, &pos);
            }
            append_word_select_token(src->ids[i], window_dd, &pos);
        }
        }
        TWindowDD::append_char(0x3F, window_dd, &pos);
        if (src->count > 2) {
            ((TWindowDD *)window_dd)->append_prompt_newline(&pos);
            append_word_select_token(src->ids[2], window_dd, &pos);
        }
        break;
    case 3:
        if (n > 1) {
            WordSelectMessage copy;
            TWindowDD__sub_80347758(src, &copy);
            pos = format_german_message__9TWindowDDFPvPvUs(&copy, window_dd, player);
        } else {
            append_word_select_token(src->ids[0], window_dd, &pos);
        }
        break;
    case 4: {
        s32 id1;
        s32 k;
        char *s1;
        char *s2;
        s32 id4;
        id4 = src->ids[0];
        s1 = 0;
        k = 0;
        if (id4 == 0x2C4) {
            s1 = (char *)get_word_select_token_text(0x2C4);
        } else if (id4 == 0x2C7) {
            append_word_select_token(id4, window_dd, &pos);
            TWindowDD::append_char(0x2C, window_dd, &pos);
            k = 2;
            s1 = ws_word_strings[0x2A6];
        } else if (id4 >= 0x68C && id4 <= 0x697) {
            append_word_select_token(id4, window_dd, &pos);
            TWindowDD::append_char(0x2C, window_dd, &pos);
            k = 1;
            s1 = ws_word_strings[0x2A3];
        } else if (id4 == 0x698) {
            k = 1;
            s1 = ws_word_strings[0x2A3];
        }
        if (n > 1) {
            id1 = src->ids[1];
            kind = k;
            if (kind == 0) {
                s2 = (char *)get_word_select_token_text(id1);
            } else {
                TWindowDDValueList *pp;
                if (kind == 1) {
                    pp = &TWindowDD__data_805D6E40[1];
                } else {
                    pp = &TWindowDD__data_805D6E40[0];
                }
                s2 = ws_word_strings[pp->values[id1 - 0x5AC]];
            }
            if (n > 3 && src->ids[3] == 0x685) {
                if (s1 != 0 && s2 != 0) {
                    TWindowDD__sub_8034694C(src, id1, s1, s2, window_dd, &pos);
                }
            } else {
                TWindowDD::append_string(s1, window_dd, &pos);
                TWindowDD::show_message_by_count(window_dd, &pos);
                TWindowDD::append_string(s2, window_dd, &pos);
            }
        } else {
            TWindowDD::append_string(s1, window_dd, &pos);
        }
        if (n > 2) {
            TWindowDD::show_message_by_count(window_dd, &pos);
            append_word_select_word(src, src->ids[2], window_dd, &pos);
        }
        if (n > 3) {
            append_word_select_token(src->ids[3], window_dd, &pos);
        }
        window_dd[0] = to_upper_latin1(window_dd[0]);
        break;
    }
    case 5: {
        s32 mode;
        char *s3;
        char *s1;
        id = src->ids[0];
        s3 = 0;
        if (id == 0x2C4) {
            mode = 0;
            kind = TWindowDD::get_player_battle_flag_state(player);
            s1 = (char *)get_word_select_token_text(id);
        } else if (id == 0x2C7) {
            append_word_select_token(id, window_dd, &pos);
            TWindowDD::append_char(0x2C, window_dd, &pos);
            mode = 2;
            {
            s32 st = TWindowDD::get_player_battle_flag_state(player);
            kind = 1;
            if (st == 2) {
                kind = 3;
            }
            }
            s1 = ws_word_strings[0x2A6];
        } else if (id >= 0x68C && id <= 0x697) {
            append_word_select_token(id, window_dd, &pos);
            TWindowDD::append_char(0x2C, window_dd, &pos);
            mode = 1;
            kind = TWindowDD::get_player_battle_flag_state(id - 0x68C);
            s1 = ws_word_strings[0x2A3];
        } else {
            mode = 3;
            if (id == 0x2C5) {
                kind = 0;
            } else if (id == 0x2C6) {
                kind = 2;
            } else {
                switch (TWindowDD__data_805D6E48[TWindowDD::clamp_range_2C9_552(id)]) {
                case 0:
                default:
                    kind = 0;
                    break;
                case 1:
                    kind = 2;
                    break;
                case 2:
                    kind = 4;
                    break;
                }
            }
            s1 = (char *)get_word_select_token_text(id);
        }
        if (n > 1) {
            s32 found;
            s32 cnt;
            found = 1;
            id = src->ids[1];
            cnt = TWindowDD__data_805D6E44[4].count;
            {
            s32 i;
            for (i = 0; i < cnt; i++) {
                if (TWindowDD__data_805D6E44[4].values[i] == id) {
                    found = 0;
                    break;
                }
            }
            }
            if (found) {
                switch (mode) {
                case 0:
                    s3 = ws_word_strings[0x6A6];
                    break;
                case 1:
                    s3 = ws_word_strings[0x6A8];
                    break;
                case 2:
                    s3 = ws_word_strings[0x6A7];
                    break;
                case 3:
                    s3 = ws_word_strings[0x6A9];
                    break;
                }
                if (n > 2 && src->ids[2] == 0x685) {
                    if (s1 != 0 && s3 != 0) {
                        TWindowDD__sub_8034694C(src, src->ids[0], s1, s3, window_dd, &pos);
                    }
                } else {
                    append_word_select_word_with_number(src, src->ids[0], s1, window_dd, &pos);
                    TWindowDD::show_message_by_count(window_dd, &pos);
                    TWindowDD::append_string(s3, window_dd, &pos);
                }
                TWindowDD::show_message_by_count(window_dd, &pos);
            } else {
                append_word_select_word_with_number(src, src->ids[0], s1, window_dd, &pos);
                TWindowDD::show_message_by_count(window_dd, &pos);
            }
            if (kind == 0) {
                append_word_select_word(src, id, window_dd, &pos);
            } else {
                TWindowDDValueList *pp;
                if (kind == 2) {
                    pp = &TWindowDD__data_805D6E44[0];
                } else if (kind == 4) {
                    pp = &TWindowDD__data_805D6E44[1];
                } else if (kind == 1) {
                    pp = &TWindowDD__data_805D6E44[2];
                } else {
                    pp = &TWindowDD__data_805D6E44[3];
                }
                append_word_select_word_with_number(src, id, ws_word_strings[pp->values[TWindowDD::clamp_range_5FA_682(id)]], window_dd, &pos);
            }
        } else if (src->ids[0] == 0x2C7) {
            TWindowDD::append_string(s1, window_dd, &pos);
        } else {
            append_word_select_word(src, src->ids[0], window_dd, &pos);
        }
        if (n > 2) {
            append_word_select_token(src->ids[2], window_dd, &pos);
        }
        window_dd[0] = to_upper_latin1(window_dd[0]);
        break;
    }
    case 6:
        src->format_type6_message((saddr)window_dd, (&pos));
        break;
    }
    window_dd[pos++] = 0;
    return pos;
}

/* Spanish word-select formatter (window mode 4; inferred: format_spanish_message, from the
   leading "\xBF"/"\xA1" marks for the ?/! ids 0x685/0x686). */
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
// inferred: appends the term after the count word, chosen by the mode the first term set
static inline void append_second_term(s32 id, s32 mode, char *window_dd, s32 *pos) {
    TWindowDD::show_message_by_count(window_dd, pos);
    if (mode == 0) {
        append_word_select_token(id, window_dd, pos);
    } else {
        TWindowDDValueList *p;
        if (mode == 1) {
            p = &TWindowDD__data_805D6E40[1];
        } else {
            p = &TWindowDD__data_805D6E40[0];
        }
        TWindowDD::append_string(ws_word_strings[p->values[id - 0x5AC]], window_dd, pos);
    }
}

s32 TWindowDD__sub_80345608(WordSelectMessage *src, char *window_dd, u16 player) {
    s32 k;
    s32 n;
    s32 i;
    s32 pos;
    s32 s;
    pos = i = 0;
    n = src->count;
    if (n == 0) {
        window_dd[0] = i;
        return 1;
    }
    switch (src->type) {
    case 1:
        append_word_select_entry_words(src, window_dd, &pos);
        break;
    case 2:
        if (n > 2) {
            n = 2;
        }
        for (k = 0; k < n; k++) {
            if (k == 1) {
                TWindowDD::append_char(0x20, window_dd, &pos);
            }
            append_word_select_token(src->ids[k], window_dd, &pos);
        }
        TWindowDD::append_char(0x3F, window_dd, &pos);
        if (src->count > 2) {
            ((TWindowDD *)window_dd)->append_prompt_newline(&pos);
            append_word_select_token(src->ids[2], window_dd, &pos);
        }
        break;
    case 3:
        if (n > 1) {
            WordSelectMessage copy;
            TWindowDD__sub_80347758(src, &copy);
            pos = TWindowDD__sub_80345608(&copy, window_dd, player);
        } else {
            append_word_select_token(src->ids[0], window_dd, &pos);
        }
        break;
    case 4: {
        if (n > 3) {
            if (src->ids[3] == 0x685) {
                TWindowDD::append_string("\xBF", window_dd, &pos);
            } else if (src->ids[3] == 0x686) {
                TWindowDD::append_string("\xA1", window_dd, &pos);
            }
        }
        s = src->ids[0];
        if (s != 0x2C8) {
            append_word_select_token(s, window_dd, &pos);
        }
        i = 0;
        if (s == 0x2C7) {
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(ws_word_strings[0xA8C / 4], window_dd, &pos);
            i = 2;
        } else if (s >= 0x68C && s <= 0x697) {
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(ws_word_strings[0xA80 / 4], window_dd, &pos);
            i = 1;
        } else if (s == 0x698) {
            TWindowDD::append_string(ws_word_strings[0xA80 / 4], window_dd, &pos);
            i = 1;
        }
        if (n > 1) {
            append_second_term(src->ids[1], i, window_dd, &pos);
        }
        if (n > 2) {
            TWindowDD::show_message_by_count(window_dd, &pos);
            append_word_select_word(src, src->ids[2], window_dd, &pos);
        }
        if (n > 3) {
            append_word_select_token(src->ids[3], window_dd, &pos);
        }
        window_dd[0] = to_upper_latin1(window_dd[0]);
        break;
    }
    case 5: {
        s32 mode;
        if (n > 2) {
            if (src->ids[2] == 0x685) {
                TWindowDD::append_string("\xBF", window_dd, &pos);
            } else if (src->ids[2] == 0x686) {
                TWindowDD::append_string("\xA1", window_dd, &pos);
            }
        }
        k = src->ids[0];
        append_word_select_word(src, k, window_dd, &pos);
        if (k == 0x2C4) {
            mode = 0;
            i = TWindowDD::get_player_battle_flag_state(player);
        } else if (k == 0x2C7) {
            mode = 2;
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(ws_word_strings[0xA8C / 4], window_dd, &pos);
            if (TWindowDD::get_player_battle_flag_state(player) == 2) {
                i = 3;
            } else {
                i = 1;
            }
        } else if (k >= 0x68C && k <= 0x697) {
            mode = 1;
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(ws_word_strings[0xA80 / 4], window_dd, &pos);
            i = TWindowDD::get_player_battle_flag_state(k - 0x68C);
        } else {
            mode = 3;
            if (k == 0x2C5) {
                i = 0;
            } else if (k == 0x2C6) {
                i = 2;
            } else {
                switch (TWindowDD__data_805D6E48[TWindowDD::clamp_range_2C9_552(k)]) {
                case 0:
                    i = 0;
                    break;
                case 1:
                    i = 1;
                    break;
                case 2:
                    i = 2;
                    break;
                case 3:
                    i = 3;
                    break;
                }
            }
        }
        if (n > 1) {
            s32 found;
            TWindowDD::show_message_by_count(window_dd, &pos);
            k = src->ids[1];
            switch (lbl_805D6E4C[TWindowDD::clamp_range_5FA_682(k)]) {
            case 0:
                found = 1;
                switch (mode) {
                case 0:
                    s = 0x697;
                    break;
                case 1:
                    s = 0x699;
                    break;
                case 2:
                    s = 0x698;
                    break;
                case 3:
                    s = 0x69A;
                    break;
                }
                break;
            case 1:
                found = 1;
                switch (mode) {
                case 0:
                    s = 0x69B;
                    break;
                case 1:
                    s = 0x279;
                    break;
                case 2:
                    s = 0x69C;
                    break;
                case 3:
                    s = 0x69D;
                    break;
                }
                break;
            case 2:
            default:
                found = 0;
                break;
            }
            if (found != 0) {
                TWindowDD::append_string(ws_word_strings[s], window_dd, &pos);
                TWindowDD::show_message_by_count(window_dd, &pos);
            }
            if (i == 0) {
                append_word_select_word(src, k, window_dd, &pos);
            } else {
                TWindowDDValueList *p;
                if (i == 1) {
                    p = &TWindowDD__data_805D6E44[0];
                } else if (i == 2) {
                    p = &TWindowDD__data_805D6E44[1];
                } else {
                    p = &TWindowDD__data_805D6E44[2];
                }
                append_word_select_word_with_number(src, k, ws_word_strings[p->values[TWindowDD::clamp_range_5FA_682(k)]], window_dd, &pos);
            }
        }
        if (n > 2) {
            append_word_select_token(src->ids[2], window_dd, &pos);
        }
        window_dd[0] = to_upper_latin1(window_dd[0]);
        break;
    }
    case 6:
        src->format_type6_message((saddr)window_dd, (&pos));
        break;
    }
    window_dd[pos++] = 0;
    return pos;
}

s32 format_english_message__9TWindowDDFPvPvUs(WordSelectMessage *src, char *window_dd, u16 player) {
    s32 b;
    s32 n;
    s32 i;
    s32 pos;
    pos = 0;
    n = src->count;
    if (n == 0) {
        window_dd[0] = 0;
        return 1;
    }
    switch (src->type) {
    case 1:
        append_word_select_entry_words(src, window_dd, &pos);
        break;
    case 2:
        if (n > 2) {
            n = 2;
        }
        {
        for (i = 0; i < n; i++) {
            if (i == 1) {
                TWindowDD::append_char(0x20, window_dd, &pos);
            }
            append_word_select_token(src->ids[i], window_dd, &pos);
        }
        }
        TWindowDD::append_char(0x3F, window_dd, &pos);
        if (src->count > 2) {
            ((TWindowDD *)window_dd)->append_prompt_newline(&pos);
            append_word_select_token(src->ids[2], window_dd, &pos);
        }
        break;
    case 3:
        if (n > 1) {
            WordSelectMessage copy;
            TWindowDD__sub_80347758(src, &copy);
            pos = format_english_message__9TWindowDDFPvPvUs(&copy, window_dd, player);
        } else {
            append_word_select_token(src->ids[0], window_dd, &pos);
        }
        break;
    case 4: {
        s32 id;
        s32 k;
        id = src->ids[0];
        if (id != 712) {
            append_word_select_token(id, window_dd, &pos);
        }
        k = 0;
        if (id == 711) {
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(ws_word_strings[(0xA60 / 4)], window_dd, &pos);
            k = 2;
        } else if (id >= 1676 && id <= 1687) {
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(ws_word_strings[(0xA54 / 4)], window_dd, &pos);
            k = 2;
        } else if (id == 1688) {
            TWindowDD::append_string(ws_word_strings[(0xA54 / 4)], window_dd, &pos);
            k = 2;
        }
        if (n > 1) {
            i = src->ids[1];
            TWindowDD::show_message_by_count(window_dd, &pos);
            if (k == 0) {
                append_word_select_token(i, window_dd, &pos);
            } else {
                TWindowDD::append_string(ws_word_strings[(TWindowDD__data_805D6E40->values[i - 1452])], window_dd, &pos);
            }
        }
        if (n > 2) {
            TWindowDD::show_message_by_count(window_dd, &pos);
            switch (TWindowDD__data_805D6E48[TWindowDD::clamp_range_2C9_552(src->ids[2])]) {
            case 1:
                TWindowDD::append_string(ws_word_strings[(0x19E4 / 4)], window_dd, &pos);
                TWindowDD::append_char(0x20, window_dd, &pos);
                break;
            case 2:
                TWindowDD::append_string(ws_word_strings[(0x19E8 / 4)], window_dd, &pos);
                TWindowDD::append_char(0x20, window_dd, &pos);
                break;
            }
            append_word_select_word(src, src->ids[2], window_dd, &pos);
        }
        if (n > 3) {
            append_word_select_token(src->ids[3], window_dd, &pos);
        }
        window_dd[0] = to_upper_latin1(window_dd[0]);
        break;
    }
    case 5: {
        s32 kind;
        s32 id;
        id = src->ids[0];
        append_word_select_word(src, id, window_dd, &pos);
        if (id == 708) {
            kind = 0;
        } else if (id == 711) {
            kind = 2;
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(ws_word_strings[(0xA60 / 4)], window_dd, &pos);
        } else if (id >= 1676 && id <= 1687) {
            kind = 1;
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(ws_word_strings[(0xA54 / 4)], window_dd, &pos);
        } else {
            kind = 3;
            window_dd[0] = to_upper_latin1(window_dd[0]);
        }
        if (n > 1) {
            s32 notfound;
            char *str;
            TWindowDD::show_message_by_count(window_dd, &pos);
            b = src->ids[1];
            notfound = 1;
            for (i = 0; i < TWindowDD__data_805D6E44[0].count; i++) {
                if (b == TWindowDD__data_805D6E44[0].values[i]) {
                    notfound = 0;
                    break;
                }
            }
            if (notfound != 0) {
                switch (kind) {
                case 0:
                    TWindowDD::append_string(ws_word_strings[(6012 / 4)], window_dd, &pos);
                    break;
                case 1:
                case 2:
                    TWindowDD::append_string(ws_word_strings[(6016 / 4)], window_dd, &pos);
                    break;
                case 3:
                    TWindowDD::append_string(ws_word_strings[(6020 / 4)], window_dd, &pos);
                    break;
                }
                TWindowDD::show_message_by_count(window_dd, &pos);
            }
            str = 0;
            if (kind == 2) {
                for (i = 0; i < TWindowDD__data_805D6E44[1].count; i++) {
                    if (b == TWindowDD__data_805D6E44[1].values[i]) {
                        str = ws_word_strings[(TWindowDD__data_805D6E44[2].values[i])];
                        break;
                    }
                }
            }
            if (str != 0) {
                append_word_select_word_with_number(src, b, str, window_dd, &pos);
            } else {
                append_word_select_word(src, b, window_dd, &pos);
            }
        }
        if (n > 2) {
            append_word_select_token(src->ids[2], window_dd, &pos);
        }
        window_dd[0] = to_upper_latin1(window_dd[0]);
        break;
    }
    case 6:
        src->format_type6_message((saddr)window_dd, (&pos));
        break;
    }
    window_dd[pos++] = 0;
    return pos;
}
#pragma pop

s32 format_entry_text__9TWindowDDFPvPv(WordSelectMessage *entry, char *window_dd) {
    s32 pos;
    s32 n;
    pos = 0;
    n = entry->count;
    if (n == 0) {
        window_dd[0] = 0;
        return 1;
    }
    switch (entry->type) {
    case 1:
        append_word_select_entry_words(entry, window_dd, &pos);
        break;
    case 2:
        if (n > 2) {
            n = 2;
        }
        {
        s32 i;
        for (i = 0; i < n; i++) {
            append_word_select_token(entry->ids[i], window_dd, &pos);
        }
        }
        TWindowDD::append_char(0x3F, window_dd, &pos);
        if (entry->count > 2) {
            ((TWindowDD *)window_dd)->append_prompt_newline(&pos);
            append_word_select_token(entry->ids[2], window_dd, &pos);
        }
        break;
    case 3:
        if (n > 3) {
            n = 3;
        }
        {
        s32 i;
        for (i = 0; i < n; i++) {
            if (i != 2) {
                TWindowDD::maybe_scroll(window_dd, &pos);
            }
            append_word_select_word(entry, entry->ids[i], window_dd, &pos);
        }
        }
        if (entry->count > 3) {
            ((TWindowDD *)window_dd)->append_prompt_newline(&pos);
            append_word_select_token(entry->ids[3], window_dd, &pos);
        }
        break;
    case 4:
        if (n > 2) {
            append_word_select_word(entry, entry->ids[2], window_dd, &pos);
        }
        if (n > 1) {
            TWindowDD::maybe_scroll(window_dd, &pos);
            append_word_select_token(entry->ids[1], window_dd, &pos);
        }
        if (n > 3) {
            append_word_select_token(entry->ids[3], window_dd, &pos);
        }
        ((TWindowDD *)window_dd)->append_prompt_newline(&pos);
        append_word_select_token(entry->ids[0], window_dd, &pos);
        break;
    case 5:
        {
        s32 i;
        for (i = 0; i < n; i++) {
            if (i != 2) {
                TWindowDD::maybe_scroll(window_dd, &pos);
            }
            append_word_select_word(entry, entry->ids[i], window_dd, &pos);
        }
        }
        break;
    case 6:
        entry->format_type6_message((saddr)window_dd, (&pos));
        break;
    }
    window_dd[pos++] = 0;
    return pos;
}

s32 TWindowDD::get_entry_value_english(u32 mode, s32 entry_id, s32 value_index) {
    s32 v;
    switch (mode) {
    case 0:
        v = TWindowDD_read_indexed_value(get_initial_word_select_list(this), value_index);
        if (v == -0x1E) {
            switch (this->get_word_select_context()) {
            case 1:
                v = 0x10;
                break;
            case 0:
                v = 0xF;
                break;
            case 3:
                v = 0x12;
                break;
            case 2:
                v = 0x11;
                break;
            case 4:
                v = 0x13;
                break;
            case 5:
                v = 0x14;
                break;
            }
        }
        break;
    case 1:
    case 2:
    case 6:
        v = -0x3C;
        break;
    case 3: {
        s16 resolved = TWindowDD_read_resolved_value(entry_id, value_index);
        if (TWindowDD__sub_80347858(resolved) != 0) {
            if (resolved == 0x43) {
                v = -0x46;
            } else if (resolved == 0x44) {
                v = -0x5A;
            } else {
                v = -0x50;
            }
        } else {
            v = -0x3C;
        }
        break;
    }
    case 5:
        v = TWindowDD_read_indexed_value(0xE, value_index);
        break;
    case 12:
        {
            s16 t = TWindowDD_read_resolved_value(0xF9, value_index);
            if (t == 0x43) {
                v = -0x46;
            } else if (t == 0x44) {
                v = -0x5A;
            } else {
                v = -0x50;
            }
        }
        break;
    case 13:
        if (TWindowDD_read_resolved_value(-0x50, value_index) == 0x2C8) {
            v = TWindowDD::ws_data_table[0xF].values[this->selected_word - 0x37];
        } else {
            v = TWindowDD::ws_data_table[0x10].values[this->selected_word - 0x37];
        }
        break;
    case 14:
        v = TWindowDD_read_indexed_value(0xF, this->selected_word - 0x37);
        break;
    case 15:
        v = -0x32;
        break;
    case 17:
        v = TWindowDD_read_indexed_value(0x11, this->selected_word - 0x37);
        break;
    case 18:
        v = -0x32;
        break;
    default:
        v = -1;
        break;
    }
    return v;
}
s32 TWindowDD::get_entry_value_japanese(u32 mode, s32 entry_id, s32 value_index) {
    s32 value;
    s16 resolved_id;

    switch (mode) {
    case 0:
        value = ((s16 (*)(s32, s32))TWindowDD_read_indexed_value)(get_initial_word_select_list(this), value_index);
        if (value == -0x1E) {
            switch (this->get_word_select_context()) {
            case 1:
                value = 0x10;
                break;
            case 0:
                value = 0xF;
                break;
            case 3:
                value = 0x12;
                break;
            case 2:
                value = 0x11;
                break;
            case 4:
                value = 0x13;
                break;
            case 5:
                value = 0x14;
                break;
            }
        }
        break;
    case 1:
    case 2:
    case 6:
        value = -0x3C;
        break;
    case 3:
        resolved_id = TWindowDD_read_resolved_value(entry_id, value_index);
        if (TWindowDD__sub_80347858(resolved_id) != 0) {
            value = ((s16 (*)(s32, s32))TWindowDD_read_indexed_value)(0xF, resolved_id - 0x37);
        } else {
            value = -0x3C;
        }
        break;
    case 5:
        value = ((s16 (*)(s32, s32))TWindowDD_read_indexed_value)(0xE, value_index);
        break;
    case 7:
        value = ((s16 (*)(s32, s32))TWindowDD_read_indexed_value)(0xF, value_index);
        break;
    case 8:
        value = ((s16 (*)(s32, s32))TWindowDD_read_indexed_value)(0x10, this->selected_word - 0x37);
        break;
    case 9:
        value = -0x32;
        break;
    case 10:
        if (TWindowDD_read_resolved_value(0x118, value_index) == 0x685) {
            value = -0x3C;
        } else {
            value = -1;
        }
        break;
    default:
        value = -1;
        break;
    }
    return value;
}
void TWindowDD::build_item_list() {
    s32 kind;
    s32 id;
    TWindowDDValueList *sel;
    s32 idx;
    TWindowDDValueList *entry;
    TWindowDDValueList *extra;
    s32 n;
    s16 *a;
    s16 *b;
    s32 i;
    s32 j;
    switch (TWindowDD::window_mode) {
    case 0:
        kind = 0x11;
        id = 0xE;
        break;
    default:
        kind = 0x12;
        id = 0xE;
        break;
    case 4:
        kind = 0x12;
        id = 0xE;
        break;
    case 2:
        kind = 0x12;
        id = 0xE;
        break;
    case 3:
        kind = 0x12;
        id = 0xE;
        break;
    }
    sel = NULL;
    idx = this->menu_index - 0x7F;
    entry = TWindowDD::get_entry(kind);
    if (entry != NULL && idx >= 0 && idx < entry->count) {
        sel = TWindowDD::get_element_ptr(entry->values[idx]);
    }
    extra = TWindowDD::get_element_ptr(id);
    n = 0;
    a = TWindowDD__word_select_lists[0].values;
    b = TWindowDD__word_select_lists[1].values;
    if (sel != NULL) {
        for (i = 0; i < sel->count && n < 0x20; n++, i++) {
            a[n] = b[n] = sel->values[i];
        }
    }
    TWindowDD__word_select_lists[1].count = n;
    for (j = 0; j < extra->count && n < 0x20; j++, n++) {
        a[n] = extra->values[j];
    }
    TWindowDD__word_select_lists[0].count = n;
}

void TWindowDD__sub_8034694C(WordSelectMessage *src, s16 id, char *verb, char *phrase, char *window_dd, s32 *pos) {
    s32 n;
    s32 len;
    s32 i;

    len = strlen(phrase);
    strlen(verb);
    n = len;
    for (i = 1; i < len; i++) {
        if (phrase[i] == ' ') {
            n = i;
            break;
        }
    }
    if (TWindowDD::can_append_chars(n, pos) != 0) {
        strncpy(window_dd + *pos, phrase, n);
        window_dd[*pos] = to_upper_latin1(window_dd[*pos]);
        *pos += n;
        TWindowDD::show_message_by_count(window_dd, pos);
        append_word_select_word_with_number(src, id, verb, window_dd, pos);
        len -= n;
        if (len > 0 && TWindowDD::can_append_chars(len, pos) != 0) {
            strncpy(window_dd + *pos, phrase + n, len);
            *pos += len;
        }
    }
}
}

void *load_encrypted_archive_data(const char *);
s32 window_dd_element_count;

TWindowDDValueList *TWindowDD::get_element_ptr(s32 index) {
    if (index == -1) {
        return NULL;
    }
    if (index == -0x32) {
        switch ((s32) TWindowDD::window_mode) {
        case 0:
            return &TWindowDD::ws_data_base[0x118];
        default:
            return &TWindowDD::ws_data_base[0x124];
        case 4:
            return &TWindowDD::ws_data_base[0x124];
        case 2:
            return &TWindowDD::ws_data_base[0x124];
        case 3:
            return &TWindowDD::ws_data_base[0x125];
        }
    } else {
        if ((index >= 0) && (index < (s32) window_dd_element_count)) {
            return &TWindowDD::ws_data_base[index];
        }
        switch (index) {
        default:
            return NULL;
        case -60:
            return &TWindowDD__word_select_lists[2];
        case -70:
            return &TWindowDD__word_select_lists[3];
        case -40:
            return &TWindowDD__word_select_lists[0];
        case -45:
            return &TWindowDD__word_select_lists[1];
        case -80:
            return &TWindowDD__word_select_lists[4];
        case -90:
            return &TWindowDD__word_select_lists[5];
        }
    }
}

s32 twindowdd_entry_count;
TWindowDDValueList *TWindowDD__data_805D6E40;
TWindowDDValueList *TWindowDD__data_805D6E44;
u8 *TWindowDD__data_805D6E48;
u8 *lbl_805D6E4C;
// inferred: ws_word_strings and ws_word_string_index are words 0 and 3 of the ws_data archive (id -> string).
// inferred: the loaded ws_data_<lang>.bin archives ws_data_load keeps per language
void *ws_data_jp;
void *ws_data_us;
void *ws_data_es;
void *ws_data_de;
void *TWindowDD::ws_data_buffer;
char *word_page_select_label;
s8 word_page_select_label_set;
char *word_page_next_label;
s8 word_page_next_label_set;

void ws_data_load(void) {
    void *jp_data;
    void *us_data;
    void *es_data;
    void *de_data;
    void *fr_data;

    switch ((s32) TWindowDD::window_mode) {
    case 0:
        jp_data = load_encrypted_archive_data("ws_data_jp.bin");
        ws_data_jp = jp_data;
        ws_word_strings = reinterpret_cast<char ***>(jp_data)[0];
        TWindowDD::ws_data_base = reinterpret_cast<TWindowDDValueList **>(jp_data)[1];
        TWindowDD::ws_data_table = reinterpret_cast<TWindowDDValueList **>(jp_data)[2];
        ws_word_string_index = reinterpret_cast<s16 **>(jp_data)[3];
        window_dd_element_count = 0x11A;
        twindowdd_entry_count = 0x12;
        return;
    default:
        us_data = load_encrypted_archive_data("ws_data_us.bin");
        ws_data_us = us_data;
        ws_word_strings = reinterpret_cast<char ***>(us_data)[0];
        TWindowDD::ws_data_base = reinterpret_cast<TWindowDDValueList **>(us_data)[1];
        TWindowDD::ws_data_table = reinterpret_cast<TWindowDDValueList **>(us_data)[2];
        ws_word_string_index = reinterpret_cast<s16 **>(us_data)[3];
        TWindowDD__data_805D6E40 = reinterpret_cast<TWindowDDValueList **>(us_data)[4];
        TWindowDD__data_805D6E48 = reinterpret_cast<u8 **>(us_data)[5];
        TWindowDD__data_805D6E44 = reinterpret_cast<TWindowDDValueList **>(us_data)[6];
        window_dd_element_count = 0x126;
        twindowdd_entry_count = 0x13;
        return;
    case 4:
        es_data = load_encrypted_archive_data("ws_data_es.bin");
        ws_data_es = es_data;
        ws_word_strings = reinterpret_cast<char ***>(es_data)[0];
        TWindowDD::ws_data_base = reinterpret_cast<TWindowDDValueList **>(es_data)[1];
        TWindowDD::ws_data_table = reinterpret_cast<TWindowDDValueList **>(es_data)[2];
        ws_word_string_index = reinterpret_cast<s16 **>(es_data)[3];
        TWindowDD__data_805D6E40 = reinterpret_cast<TWindowDDValueList **>(es_data)[4];
        TWindowDD__data_805D6E48 = reinterpret_cast<u8 **>(es_data)[6];
        TWindowDD__data_805D6E44 = reinterpret_cast<TWindowDDValueList **>(es_data)[5];
        lbl_805D6E4C = reinterpret_cast<u8 **>(es_data)[8];
        window_dd_element_count = 0x126;
        twindowdd_entry_count = 0x13;
        return;
    case 2:
        de_data = load_encrypted_archive_data("ws_data_de.bin");
        ws_data_de = de_data;
        ws_word_strings = reinterpret_cast<char ***>(de_data)[0];
        TWindowDD::ws_data_base = reinterpret_cast<TWindowDDValueList **>(de_data)[1];
        TWindowDD::ws_data_table = reinterpret_cast<TWindowDDValueList **>(de_data)[2];
        ws_word_string_index = reinterpret_cast<s16 **>(de_data)[3];
        TWindowDD__data_805D6E40 = reinterpret_cast<TWindowDDValueList **>(de_data)[4];
        TWindowDD__data_805D6E44 = reinterpret_cast<TWindowDDValueList **>(de_data)[5];
        TWindowDD__data_805D6E48 = reinterpret_cast<u8 **>(de_data)[6];
        window_dd_element_count = 0x126;
        twindowdd_entry_count = 0x13;
        return;
    case 3:
        fr_data = load_encrypted_archive_data("ws_data_fr.bin");
        TWindowDD::ws_data_buffer = fr_data;
        ws_word_strings = reinterpret_cast<char ***>(fr_data)[0];
        TWindowDD::ws_data_base = reinterpret_cast<TWindowDDValueList **>(fr_data)[1];
        TWindowDD::ws_data_table = reinterpret_cast<TWindowDDValueList **>(fr_data)[2];
        ws_word_string_index = reinterpret_cast<s16 **>(fr_data)[3];
        TWindowDD__data_805D6E40 = reinterpret_cast<TWindowDDValueList **>(fr_data)[4];
        TWindowDD__data_805D6E48 = reinterpret_cast<u8 **>(fr_data)[6];
        TWindowDD__data_805D6E44 = reinterpret_cast<TWindowDDValueList **>(fr_data)[5];
        window_dd_element_count = 0x127;
        twindowdd_entry_count = 0x13;
        return;
    }
}

s32 get_initial_word_select_list(TWindowDD *window_dd) {
  s32 list_base;
  s32 offset;
  list_base = 0;
  switch (window_dd->get_word_select_context())
  {
    case 0:
      list_base = 1;
      break;
    case 1:
      list_base = 3;
      break;
    case 2:
      list_base = 5;
      break;
    case 3:
      list_base = 7;
      break;
    case 4:
      list_base = 9;
      break;
    case 5:
      list_base = 0xB;
      break;
  }
  offset = 0;
  if (has_menu_selection(window_dd) != 0)
  {
    offset = 1;
  }
  return list_base + offset;
}

void TWindowDD::render() {  }

s16 TWindowDD_read_indexed_value(s32 entry_index, s32 value_index) {
    s16 result;
    TWindowDDValueList *entry;
    result = -1;
    entry = TWindowDD::get_entry(entry_index);
    if (entry != NULL) {
        if ((value_index < 0) || (value_index >= entry->count)) {
            result = -1;
        } else {
            result = entry->values[value_index];
        }
    }
    return result;
}

s16 TWindowDD_read_resolved_value(s32 entry_id, s32 value_index) {
    s16 result;
    TWindowDDValueList *entry;
    result = -1;
    entry = TWindowDD::get_element_ptr(entry_id);
    if (entry != NULL) {
        if ((value_index < 0) || (value_index >= entry->count)) {
            result = -1;
        } else {
            result = entry->values[value_index];
        }
    }
    return result;
}

s32 has_menu_selection(TWindowDD *window_dd) {
    return window_dd->menu_index != -1;
}



// The caller passes its message; the body does not read it.
void TWindowDD::reset_selection(WordSelectMessage *message) {
    menu_index = -1;
    remembered_word_select_id = -1;
    build_item_list();
}

void WordSelectMessage::remember_selected_id() {
    if ((type == 1) && (TWindowDD__sub_80346FC0(ids[0]) != 0)) {
        remembered_word_select_id = ids[0];
    }
}
s32 TWindowDD__sub_80346FC0(s16 id) {
    u8 var_r3;
    var_r3 = 0;
    if ((id >= 0x7F) && (id <= 0x138)) {
        var_r3 = 1;
    }
    return var_r3;
}
void TWindowDD::build_player_word_lists() {
    s32 i;
    s32 n;
    s16 *list;
    s32 j;
    s32 j2;
    s32 k;
    s16 *l1;
    s16 *l2;
    s16 *l3;
    uaddr p;
    s16 v;
    n = 0;
    list = TWindowDD__word_select_lists[2].values;
    list[n++] = 0x2c7;
    for (i = 0; i < 12; i++) {
        p = (uaddr)get_player_by_client_id(i);
        if (p != 0) {
            strncpy(TWindowDD__player_name_buffers[i], (char *)(p + 0x85c), 0x18);
            if (i != local_client_id) {
                list[n++] = i + 0x68c;
                if (n >= 16) {
                    break;
                }
            }
        } else {
            TWindowDD__player_name_buffers[i][0] = 0;
        }
    }
    TWindowDD__word_select_lists[2].count = n;
    j = 0;
    l1 = TWindowDD__word_select_lists[3].values;
    l1[j++] = 0x2c4;
    for (k = 0; k < n - 1; k++) {
        l1[j++] = list[k + 1];
    }
    l1[j++] = 0x2c5;
    l1[j++] = 0x2c6;
    l1[j++] = 0x2c7;
    TWindowDD__word_select_lists[3].count = j;
    j2 = 0;
    l2 = TWindowDD__word_select_lists[4].values;
    l3 = TWindowDD__word_select_lists[5].values;
    l2[j2++] = 0x2c4;
    *l3++ = 0x2c4;
    for (k = 0; k < n - 1; k++) {
        v = list[k + 1];
        l2[j2++] = v;
        *l3++ = v;
    }
    l2[j2++] = 0x2c7;
    *l3 = 0x2c7;
    l2[j2++] = 0x2c8;
    TWindowDD__word_select_lists[4].count = j2;
    TWindowDD__word_select_lists[5].count = j2 - 1;
}


void TWindowDD::open(void *message, u16 speaker) {
    format_message(static_cast<WordSelectMessage *>(message), window_dd_buffer_a, speaker);
    TWindowCtrl::open(speaker, window_dd_buffer_a, 0x4F);
}

s32 TWindowDD::is_id_in_special_range(s16 id) {
    u8 r = 0;
    if (id >= 0x45d && id <= 0x46f && id != 0x46d && id != 0x46e) {
        r = 1;
    }
    return r;
}

s32 TWindowDD__sub_80347238(s16 id) {
    u8 var_r3;
    var_r3 = 0;
    if ((id >= 0x300) && (id <= 0x395)) {
        var_r3 = 1;
    }
    return var_r3;
}




extern "C" {

s32 TWindowDD::classify_id(s16 id) {
    s32 kind;

    if (id == 0x2E4) {
        return 0;
    }
    if (TWindowDD__sub_80347238(id) != 0) {
        return 1;
    }
    if (is_id_in_special_range(id) != 0) {
        return 2;
    }
    if (id == 0x4F3) {
        return 3;
    }
    if (id == 0x635) {
        return 4;
    }
    kind = 7;
    if (id == 0x650) {
        kind = 5;
    }
    return kind;
}

s32 TWindowDD::get_player_battle_flag_state(u16 client) {
    s32 class_flags;
    void *player;

    player = get_player_by_client_id((u16) client);
    if (player != NULL) {
        class_flags = ((TObjPlayer *)player)->class_flags;
        if (class_flags & CLASS_FLAG_MALE) {
            return 0;
        }
        if (class_flags & CLASS_FLAG_FEMALE) {
            return 2;
        }
        goto block_5;
    }
block_5:
    return 0;
}

void WordSelectMessage::format_type6_message(saddr window_dd, void *pos) {
    s32 n_tokens;
    s32 n;
    s32 i;

    n_tokens = count;
    n = n_tokens;
    if (n > 3) {
        n = 3;
    }
    for (i = 0; i < n - 1; i++) {
        append_word_select_token(ids[i], (char *)window_dd, (s32 *)pos);
        TWindowDD::show_message_by_count((char *)window_dd, (s32 *)pos);
    }
    append_word_select_token(ids[n - 1], (char *)window_dd, (s32 *)pos);
    if (n_tokens > 3) {
        ((TWindowDD *)window_dd)->append_prompt_newline((s32 *)pos);
        append_word_select_token(ids[3], (char *)window_dd, (s32 *)pos);
    }
}

void append_word_select_entry_words(WordSelectMessage *entry, char *buf, s32 *pos) {
    append_word_select_word(entry, entry->ids[0], buf, pos);
    if (entry->count > 1) {
        ((TWindowDD *)buf)->append_prompt_newline(pos);
        append_word_select_token(entry->ids[1], buf, pos);
    }
}

void append_word_select_word(WordSelectMessage *entry, s16 id, char *buf, s32 *pos) {
    char *word = (char *)get_word_select_token_text(id);
    append_word_select_word_with_number(entry, id, word, buf, pos);
}

void append_word_select_word_with_number(WordSelectMessage *entry, s16 id, char *word, char *buf, s32 *pos) {
    char num[20];
    s32 kind;
    s32 value;
    s32 limit;
    s32 len;
    s32 split;
    s32 next;
    s32 c;
    char *p;
    s32 i;

    kind = TWindowDD::classify_id(id);
    if (kind != 7) {
        value = entry->get_numeric_parameter();
        limit = word_select_numeric_limits[kind];
        if (value > 0) {
            if (value > limit) {
                value = limit;
            }
            format_int_decimal(value, num);
            switch (kind) {
            case 0:
            case 5:
                if (kind == 5 && TWindowDD::window_mode == 2) {
                    len = strlen(word);
                    s32 need = len + strlen(num) + 1;
                    if (TWindowDD::can_append_chars(need, pos) == 0) {
                        break;
                    }
                    split = len;
                    for (i = 0; i < len - 1; i++) {
                        p = word + i;
                        c = p[0];
                        next = p[1];
                        if ((c == 'J' || c == 'j') && next == 'a') {
                            split = i;
                            break;
                        }
                    }
                    if (split != 0) {
                        strncpy(buf + *pos, word, split);
                        *pos += split;
                    }
                    TWindowDD::append_string(num, buf, pos);
                    TWindowDD::show_message_by_count(buf, pos);
                    len -= split;
                    if (len > 0) {
                        strncpy(buf + *pos, word + split, len);
                        *pos += len;
                    }
                } else {
                    TWindowDD::append_string(num, buf, pos);
                    if (TWindowDD::window_mode != 0) {
                        TWindowDD::append_char(' ', buf, pos);
                    }
                    TWindowDD::append_string(word, buf, pos);
                }
                break;
            case 1:
                TWindowDD::append_string(word, buf, pos);
                TWindowDD::append_char('+', buf, pos);
                TWindowDD::append_string(num, buf, pos);
                break;
            case 2:
                TWindowDD::append_string(word, buf, pos);
                TWindowDD::append_string(" Lv.", buf, pos);
                TWindowDD::append_string(num, buf, pos);
                break;
            case 3:
            case 4:
                TWindowDD::append_string(word, buf, pos);
                TWindowDD::append_string(num, buf, pos);
                break;
            }
            return;
        }
    }
    TWindowDD::append_string(word, buf, pos);
}

void TWindowDD__sub_80347758(WordSelectMessage *src, WordSelectMessage *dst) {
    s16 id;
    s16 n;
    n = src->count;
    if (n > 1) {
        id = src->ids[1];
        if (TWindowDD_is_id_in_range_5AC_5F9(id) != 0) {
            dst->type = 4;
            if (n > 3) {
                dst->ids[0] = src->ids[3];
            } else if (n > 2 && src->ids[2] == 0x685) {
                dst->ids[0] = 0x698;
            } else {
                dst->ids[0] = 0x2C4;
            }
            dst->ids[1] = id;
            dst->ids[2] = src->ids[0];
            if (n > 2) {
                dst->ids[3] = src->ids[2];
                dst->count = 4;
            } else {
                dst->count = 3;
            }
        } else {
            s32 i;
            dst->type = 5;
            for (i = 0; i < n; i++) {
                dst->ids[i] = src->ids[i];
            }
            dst->count = src->count;
        }
    }
    dst->numeric_parameter = src->numeric_parameter;
}

s32 TWindowDD__sub_80347858(s16 id) {
    u8 r = 0;
    if (id >= 0x37 && id <= 0x45) {
        r = 1;
    }
    return r;
}
}

s32 TWindowDD::is_state_zero_unless_0x2C8(s32 id) {
    if ((s16)id == 0x2C8) {
        return 0;
    }
    return (u32) __cntlzw((u32) ((s32 (*)(void))TWindowDD__sub_80347858)()) >> 5;
}

s32 TWindowDD_is_id_in_range_5AC_5F9(s32 value) {
    u8 in_range = 0;
    if (static_cast<s16>(value) >= 0x5ac && static_cast<s16>(value) <= 0x5f9) {
        in_range = 1;
    }
    return in_range;
}

void TWindowDD::destroy_menu_entry(s32 offset) {
    if (word_windows[depth + offset] != NULL) {
        word_windows[depth + offset]->queue_destruction();
        word_windows[depth + offset] = NULL;
    }
}

void TWindowDD::set_item_pos(s32 i) {
    TWindowDD_WS_Word *page = word_windows[depth + i];
    if (page != NULL) {
        page->set_pos_and_data(last_word_page_x);
    }
}

extern "C" {

TWindowDD_WS_Word *TWindowDD::commit_word_select_level() {
    TWindowDD_WS_Word *child;
    if (depth > 0) {
        child = word_windows[depth - 1];
        if (child != NULL) {
            update(child);
            list_ids[0] = child->get_element_list_id();
        }
    }
    return child;
}
}

TWindowDD_WS_Word *TWindowDD::init_last_child() {
    s32 level;
    TWindowDD_WS_Word *child;
    child = NULL;
    level = depth;
    if (level > 0) {
        child = word_windows[level - 1];
        if (child != NULL) {
            child->init_and_mark_field8C();
            child->set_pos_and_data(word_page_x);
            child->target_size[0] = word_page_width;
        }
    }
    return child;
}

extern "C" {

void TWindowDD::take_word_select_word(TWindowDD_WS_Word *word_window) {
    s32 id;
    id = word_window->get_selected_id();
    if (TWindowDD::is_state_zero_unless_0x2C8(id) != 0) {
        message.push_token(id);
        refresh_word_select_message(&message);
        token_pushed = 1;
        last_selected_id = (s16) id;
        return;
    }
    update_word_select_child_position(3);
    token_pushed = 0;
    last_selected_id = (s16) id;
}

TWindowDD_WS_Word *TWindowDD::get_or_create_word_select_child(s32 offset, s32 id) {
    s32 i;
    TWindowDD_WS_Word *win;

    i = depth + offset;
    if (i >= 8) {
        return NULL;
    }
    win = word_windows[i];
    if (win == NULL) {
        win = TWindowDD_WS_Word::create(id, (s32)window_dd_visible_rows);
        set_default_coords(win);
        word_windows[depth + offset] = win;
    }
    return win;
}

#pragma push
#pragma fp_contract on

void TWindowDD::update_selection_state() {
    s32 v;
    v = word_windows[depth]->get_selected_id();
    if ((s16)v != last_selected_id) {
        switch (token_pushed) {
        case 0:
            if (TWindowDD::is_state_zero_unless_0x2C8(v) != 0) {
                message.push_token(v);
                token_pushed = 1;
            } else {
                message.set_last_token(v);
            }
            break;
        case 1:
            if (TWindowDD::is_state_zero_unless_0x2C8(v) != 0) {
                message.set_last_token(v);
            } else {
                message.pop_token();
                token_pushed = 0;
            }
            break;
        }
        refresh_word_select_message(&message);
        last_selected_id = (s16)v;
    }
}

void TWindowDD::refresh_word_select_child_list() {
    s32 next;

    next = dispatch_by_window_mode(this, state, list_ids[0], word_windows[depth]->get_selected_token_index());
    if (next != list_ids[1]) {
        list_ids[1] = next;
        word_windows[depth + 1]->init_child(list_ids[1]);
    }
}

void TWindowDD::refresh_word_select_message(WordSelectMessage *message) {
    TWindowDD_WS_String *s;
    WindowTextEntry *e;
    f32 x;
    f32 c;
    f32 max;
    f32 f10;
    TWindowDD::format_message(message, reinterpret_cast<char *>(TWindowDD::work_buffer), local_client_id);
    s = labels[3];
    if (s != NULL) {
        e = (WindowTextEntry *)s->get_array_entry(0);
        if (e != NULL) {
            measure_message_text_width_default(e);
            x = 10.0f + e->width;
            if (x >= 580.0f) {
                e->x = 580.0f - e->width;
                x = 580.0f;
            } else {
                e->x = 0.0f;
            }
            s->target_size[0] = 2.0f * window_dd_frame_margin + x;
            if (x <= 0.0f) {
                s->update_position(window_dd_tween_ticks);
            } else {
                s->move_to_start(window_dd_tween_ticks);
            }
        }
    }
}
s32 TWindowDD::setup_entry(s16 id) {
    s32 result;
    TWindowDD_WS_String *label;

    s32 str;
    result = 0;
    label = labels[2];
    if ((label != NULL) && ((str = get_word_select_token_text(id)) != 0)) {
        label->set_first_entry_text(str);
        label->fit_width_to_text();
        label->move_to_start(window_dd_tween_ticks);
        result = 1;
    }
    return result;
}

void TWindowDD::create_word_select_cursor_label(s32 slot) {
    NJS_POINT2 v;
    NJS_POINT2 a;
    NJS_POINT2 b;
    u32 r;
    TWindowDD_WS_String *o;
    word_windows[depth]->get_cursor_pos(&v);
    r = word_windows[depth]->get_selected_row_text();
    if (r != 0) {
        if (slot == 0) {
            a.x = cursor_label_x;
            a.y = cursor_label_y;
        } else {
            a.x = cursor_label2_x;
            a.y = cursor_label2_y;
        }
        b.x = word_label_hidden_x;
        b.y = a.y;
        o = TWindowDD_WS_String::create(cursor_label_width, (f32 *)&a, (f32 *)&b, (u32)r, 1);
        if (o != NULL) {
            o->set_depth(word_cursor_depth);
            o->fit_width_to_text();
            copy_vec2(o->frame_position, &v);
            o->move_to_start(window_dd_tween_ticks);
            labels[slot + 4] = o;
        }
    }
}}

s32 TWindowDD::get_current_child_index() {
    TWindowDD_WS_Word *word_window;
    word_window = word_windows[depth];
    if (word_window != NULL) {
        return word_window->get_selected_id();
    }
    return -1;
}
#pragma pop



TWindowDDStateEntry *TWindowDD::get_state_entry(s32 state) { return &word_select_state_table[state]; }

void TWindowDD::move_next_label_after_wide_page() {
    TWindowDD_WS_String *label;
    label = labels[1];
    if (label != NULL) {
        label->target_position[0] = wide_next_word_page_x;
        label->tween_ticks = window_dd_tween_ticks;
    }
}

void TWindowDD::init_entry_field_64(s32 index) {
    TWindowDD_WS_String *label;
    label = labels[index];
    if (label != NULL) {
        label->move_to_start(window_dd_tween_ticks);
    }
}

void TWindowDD::update_word_select_child_position(s32 index) {
    TWindowDD_WS_String *label;
    label = labels[index];
    if (label != NULL) {
        label->update_position(window_dd_tween_ticks);
    }
}

void TWindowDD::refresh_sub(TWindowDD_WS_Word *page) {
    page->disable_input();
    page->use_dim_strips();
}

void TWindowDD::apply_input(TWindowDD_WS_Word *page) {
    page->disable_input();
    page->use_active_strips();
}

void TWindowDD::dim_next_page(TWindowDD_WS_Word *page) {
    page->disable_input();
    page->use_dim_strips();
}


void TWindowDD::update(TWindowDD_WS_Word *window_dd) {
    window_dd->enable_input();
    window_dd->use_active_strips();
    if (scroll_bar != NULL) {
        scroll_bar->set_range(window_dd->get_token_count(), (s32) window_dd_visible_rows);
        scroll_bar->set_first_index(window_dd->get_scroll_top());
    }
}

extern "C" {

void TWindowDD::set_default_coords(TWindowDD_WS_Word *win) {
    refresh_sub(win);
    win->target_position[0] = last_word_page_x;
    win->frame_position[0] = last_word_page_x;
    win->target_position[1] = last_word_page_y;
    win->frame_position[1] = last_word_page_y;
    win->target_size[0] = last_word_page_width;
    win->frame_size[0] = last_word_page_width;
    win->target_size[1] = last_word_page_height;
    win->frame_size[1] = last_word_page_height;
}

void TWindowDD::init_layout(TWindowDD_WS_Word *child) {
    dim_next_page(child);
    child->target_position[0] = next_word_page_x;
    child->frame_position[0] = next_word_page_x;
    child->target_position[1] = next_word_page_y;
    child->frame_position[1] = next_word_page_y;
    child->target_size[0] = next_word_page_width;
    child->frame_size[0] = next_word_page_width;
    child->target_size[1] = next_word_page_height;
    child->frame_size[1] = next_word_page_height;
}

void TWindowDD::set_default_positions(TWindowDD_WS_Word *child) {
    update(child);
    child->target_position[0] = word_page_x;
    child->frame_position[0] = word_page_x;
    child->target_position[1] = word_page_y;
    child->frame_position[1] = word_page_y;
    child->target_size[0] = word_page_width;
    child->frame_size[0] = word_page_width;
    child->target_size[1] = word_page_height;
    child->frame_size[1] = word_page_height;
}

void TWindowDD::spawn_window() { play_sound_effect(344320, 0, 0, 0); }
void TWindowDD::play_se() { play_sound_effect(339734, 0, 0, 0); }
void TWindowDD::play_sound() { play_sound_effect(339201, 0, 0, 0); }
s32 TWindowDD::is_word_select_cancel_input() {
    u8 cancel;
    cancel = 0;
    if (TWindowDD_check_input_mask(&menu_index, 2) != 0 || (result_flags & 2)) {
        cancel = 1;
    }
    return cancel;
}

}



int TWindowDD::test_input_flag_4() { return TWindowDD_check_input_mask((char*)this + 0x1c, 4); }

s32 dispatch_by_window_mode(TWindowDD *window, u32 window_mode, s32 entry_id, s32 value_index) {
    switch ((s32) TWindowDD::window_mode) {
    case 0:
        return window->get_entry_value_japanese(window_mode, entry_id, value_index);
    default:
        return window->get_entry_value_english(window_mode, entry_id, value_index);
    case 4:
        return window->get_entry_value_spanish(window_mode, entry_id, value_index);
    case 2:
        return window->get_entry_value_german(window_mode, entry_id, value_index);
    case 3:
        return window->get_entry_value_french(window_mode, entry_id, value_index);
    }
}

s32 TWindowDD::get_word_select_context() {
    s32 area;
    area = get_current_floor_area();
    if (area == AREA_PIONEER2_EP1 || area == AREA_PIONEER2_EP2) {
        return 1;
    }
    if (area == AREA_LOBBY) {
        return 0;
    }
    if (TObjPlayer::get_player_count() != 0) {
        return 4;
    }
    if (is_challenge_mode() != 0) {
        return 5;
    }
    return (enemies_active != 0 ? 1 : 0) + 2;
}

int TWindowDD__sub_80348424(s32 _w0, s32 _w1) { return get_word_select_type_state((saddr)((void*)(1)), (_w1)); }

void TWindowDD__sub_80348448(s32 unused, s16 id) {
    get_word_select_type_state(0, ((s32) id));
}

s32 TWindowDD::get_mode_code() {
    s32 mode;
    mode = dialog_state;
    if (mode == 2) {
        return 1;
    }
    return ((mode - 3) == 0) ? 2 : 0;
}

void TWindowDD::set_state() { dialog_state = 3; close_all_windows(); }

void TWindowDD::finish_word_select() {
    dialog_state = 2;
    copy_chat_entry(output, &message);
    if (selection_confirmed != 0) {
        reset_selection(&message);
    }
    close_all_windows();
}

void TWindowDD::close_all_windows() {
    s32 i;
    if (number_window != NULL) {
        number_window->close();
        number_window = NULL;
    }
    if (mode_window != NULL) {
        mode_window->close();
        mode_window = NULL;
    }
    if (scroll_bar != NULL) {
        scroll_bar->close();
        scroll_bar = NULL;
    }
    for (i = 0; i < 6; i++) {
        if (labels[i] != NULL) {
            labels[i]->close();
            labels[i] = NULL;
        }
    }
    for (i = 7; i >= 0; i--) {
        if (word_windows[i] != NULL) {
            word_windows[i]->close();
            word_windows[i] = NULL;
        }
    }
}

s32 TWindowDD::can_append_chars(s32 len, s32 *pos) {
    s32 t = *pos;
    return (len + t + 1) < 0x80;
}

void TWindowDD::format_message(WordSelectMessage *message, char *text, u16 player) {
    switch ((s32) TWindowDD::window_mode) {
    case LANGUAGE_JAPANESE:
        format_entry_text__9TWindowDDFPvPv(message, text);
        return;
    default:
        format_english_message__9TWindowDDFPvPvUs(message, text, player);
        return;
    case LANGUAGE_SPANISH:
        TWindowDD__sub_80345608(message, text, player);
        return;
    case LANGUAGE_GERMAN:
        format_german_message__9TWindowDDFPvPvUs(message, text, player);
        return;
    case LANGUAGE_FRENCH:
        format_message_text__9TWindowDDFPvPvUs(message, text, player);
        return;
    }
}

void TWindowDD::append_prompt_newline(s32 *pos) {
    u8 *buffer = (u8 *)this;
    s32 p = *pos;
    if (((s32)TWindowDD::can_append_chars(3, pos)) != 0) {
        buffer[p++] = 0xA;
        buffer[p++] = 0x3E;
        buffer[p++] = 0x20;
    }
    *pos = p;
}

s32 TWindowDD::clamp_range_5FA_682(s16 id) {
    if ((id >= 0x5FA) && (id <= 0x682)) {
        return id - 0x5FA;
    }
    return 0;
}

s32 TWindowDD::clamp_range_2C9_552(s16 id) {
    if ((id >= 0x2C9) && (id <= 0x552)) {
        return id - 0x2C9;
    }
    return 0;
}


extern "C" {

void TWindowDD::show_message_by_count(char *buf, s32 *pos) {
    if (TWindowDD::count_chars_since_newline(buf, pos) > 0xF) {
        TWindowDD::append_char(0xA, buf, pos);
        return;
    }
    TWindowDD::append_char(0x20, buf, pos);
}

}


void TWindowDD::maybe_scroll(char *buf, s32 *pos) {
    if (TWindowDD::count_chars_since_newline(buf, pos) > 15) {
        TWindowDD::append_char(10, buf, pos);
    }
}

s32 TWindowDD::count_chars_since_newline(const char *buf, s32 *pos) {
    s32 n = 0;
    s32 i;
    for (i = *pos - 1; i >= 0; i--) {
        if (buf[i] == '\n') {
            break;
        }
        n++;
    }
    return n;
}

void TWindowDD::append_char(s8 c, char *buf, s32 *pos) {
    s32 i;
    if (TWindowDD::can_append_chars(1, pos) != 0) {
        i = *pos;
        *pos = i + 1;
        buf[i] = c;
    }
}

void append_word_select_token(s16 id, char *buf, s32 *pos) {
    TWindowDD::append_string((const char *)get_word_select_token_text(id), buf, pos);
}




WindowTexturePoint word_select_quad_points[7][8];
typedef struct { char pad[0xBC]; } Buf;

void TWindowDD::append_string(const char *str, char *buf, s32 *pos) {
    s32 len;

    if (str != NULL) {
        len = strlen(str);
        if (TWindowDD::can_append_chars(len, pos) != 0) {
            strncpy(buf + *pos, str, len);
            *pos += len;
        }
    }
}


void TWindowDD_WS_String::draw(saddr ctx, s32 idx, f32 offset) {
    Buf sp8;
    s32 draw_count;

    draw_count = TWindowDD::get_draw_count(hud_texlist);
    reset_window_vertices((WindowVertex *)&sp8, word_select_inverse_depth(draw_depth, offset), -1);
    copy_window_point_table((WindowVertex *)&sp8, idx);
    TWindowDD__sub_80348A2C(reinterpret_cast<WindowDrawContext *>(ctx), reinterpret_cast<WindowVertex *>(&sp8));
    TWindowDD__sub_803489B8(reinterpret_cast<WindowDrawContext *>(ctx), reinterpret_cast<WindowVertex *>(&sp8), 0);
    draw_window_vertices((WindowVertex *)&sp8, 8, draw_count, 1);
}

#pragma push
#pragma fp_contract on
void TWindowDD__sub_803489B8(WindowDrawContext *context, WindowVertex *vertices, s32 row) {
    s32 i;
    f32 hs;
    f32 half;
    f32 v;
    f32 t0;
    f32 step;
    f32 sc;
    half = 0.5f * context->h;
    sc = context->scale[1];
    t0 = context->y + half;
    step = window_dd_row_height * sc;
    hs = half * sc;
    v = t0 - hs;
    v += step * (f32)row;
    for (i = 0; i < 4; i++) {
        vertices[0].y = v;
        vertices[1].y = v + step;
        vertices += 2;
    }
}
#pragma pop

void TWindowDD__sub_80348A2C(WindowDrawContext *context, WindowVertex *vertices) {
  f32 center_x;
  f32 inner_right;
  f32 half_scaled;
  f32 inner_left;
  s8 *right_vertex;
  f32 half_width;
  f32 x;
  f32 right;
  s8 *base_vertex;
  f32 edge;
  half_width = 0.5f * context->w;
  half_scaled = half_width * context->scale[0];
  center_x = context->x + half_width;
  x = (0, center_x - half_scaled);
  right = center_x + half_scaled;
  if (half_scaled < window_dd_cap_width)
  {
    edge = (right - x) / 3.0f;
  }
  else
  {
    edge = window_dd_cap_width;
  }
  right_vertex = ((s8 *) ((0, vertices))) + 0x90;
  *((f32 *) (((s8 *) vertices) + 0x18)) = x;
  inner_left = x + edge;
  inner_right = right - edge;
  vertices->x = x;
  *((f32 *) (((s8 *) vertices) + 0x48)) = inner_left;
  *((f32 *) (((s8 *) vertices) + 0x30)) = inner_left;
  base_vertex = (s8 *) vertices;
  *((f32 *) (((s8 *) vertices) + 0x78)) = inner_right;
  *((f32 *) (((s8 *) vertices) + 0x60)) = inner_right;
  *((f32 *)(base_vertex + 0xA8)) = right;
  *((f32 *) right_vertex) = right;
}

void copy_window_point_table(WindowVertex *vertices, s32 idx) {
    WindowVertex *self = vertices;
    s32 i;
    const WindowTexturePoint *s = word_select_quad_points[idx];
    for (i = 0; i < 8; i++) {
        self->u = s->x;
        self->v = s->y;
        s++;
        self++;
    }
}

#pragma push
#pragma fp_contract on
f32 word_select_inverse_depth(f32 draw_depth, f32 offset) {
    return (-1.0f) / ((0.299f * offset) + draw_depth);
}
#pragma pop

s32 TWindowDD::get_draw_count(const NJS_TEXLIST *textures) {
    return textures->textures[2].texture->surface->id;
}


#pragma push
#pragma fp_contract on
void TWindowBase::calc_inner_rect(WindowDrawContext *context) {
    f32 y0;
    f32 ky;
    f32 x0;
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    x = frame_position[0];
    y = frame_position[1];
    ky = window_dd_frame_margin_y;
    x0 = x + window_dd_frame_margin;
    w = frame_size[0];
    h = frame_size[1];
    y0 = y + ky;
    context->inner_x = x0;
    context->inner_y = y0;
    context->inner_w = w - 2.0f * window_dd_frame_margin;
    context->inner_h = h - 2.0f * ky;
    context->clip_x0 = x0;
    context->clip_y0 = y0;
    context->clip_x1 = (x + w) - window_dd_frame_margin;
    context->clip_y1 = (y + h) - ky;
    context->pivot[0] = 0.5f * w + x;
    context->pivot[1] = 0.5f * h + y;
}
#pragma pop

saddr get_word_select_token_text(s16 id) {
    char **names = TWindowDD__player_name_buffers;
    if (id >= 0x68C && id <= 0x697) {
        return (saddr)names[id - 0x68C];
    }
    if (id == 0x698) {
        return 0;
    }
    return (saddr)ws_word_strings[ws_word_string_index[id]];
}

TWindowDDValueList *TWindowDD::get_entry(s32 index) {
    if ((index < 0) || (index >= (s32) twindowdd_entry_count)) {
        return NULL;
    }
    return &TWindowDD::ws_data_table[index];
}

extern s32 local_client_id;

void handle_6x74_word_select(u8 *window_dd) {
    G_WordSelect_6x74 *cmd = (G_WordSelect_6x74 *)window_dd;
    cmd->bswap_message();
    if (TWindowDD__word_select_lists != NULL) {
        if ((s32) cmd->client_id != (s32) local_client_id) {
            cmd->message.remember_selected_id();
        }
        TWindowDD::build_player_word_lists();
        TWindowDD::open(&cmd->message, cmd->client_id);
    }
}

extern "C" {

void G_WordSelect_6x74::bswap_message() { message.bswap(); }

void G_WordSelect_6x74::send_message(WordSelectMessage *data) {
    G_WordSelect_6x74 pkt;
    pkt.init_header();
    pkt.client_id = local_client_id;
    TWindowDD::copy_chat_entry(&pkt.message, data);
    pkt.send();
}

void G_WordSelect_6x74::send() { bswap_message(); send_subcommand(this); }
void G_WordSelect_6x74::init_header() { subcommand = 116; size = 8; }

}

extern "C" {

void WordSelectMessage::bswap() {
    s32 i;
    bswap_16((u16 *)&count);
    bswap_16((u16 *)&type);
    for (i = 0; i < 8; i++) {
        bswap_16((u16 *)&ids[i]);
    }
    bswap_32((u32 *)&numeric_parameter);
    bswap_32((u32 *)&unknown_a4);
}

void WordSelectMessage::reset_numeric_parameter() { numeric_parameter = 0; }
void WordSelectMessage::set_numeric_parameter(s32 value) { numeric_parameter = value; }
s32 WordSelectMessage::get_numeric_parameter() { return numeric_parameter; }

void WordSelectMessage::set_last_token(s32 id) {
    if (count > 0) {
        ids[count - 1] = id;
    }
}

void WordSelectMessage::pop_token() {
    if (count > 0) {
        ids[--count] = -1;
    }
}

void WordSelectMessage::push_token(s32 id) {
    if (count < 8) {
        ids[count++] = id;
    }
}

void WordSelectMessage::init() {
    s32 i;
    type = 0;
    count = 0;
    for (i = 0; i < 8; i++) {
        ids[i] = -1;
    }
    numeric_parameter = 0;
    unknown_a4 = 0;
}

}
