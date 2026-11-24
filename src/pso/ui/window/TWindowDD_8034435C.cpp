#include "pso/ui/window/WordSelectMessage.h"
#include "types.h"
#include <string.h>
#include "pso/ui/window/TWindowDD_8034435C.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDD_80346A84.h"

struct List_803467CC {
    s16 *items;
    s32 count;
};

struct Buf_803467CC {
    s16 *a;
    s32 n4;
    s16 *b;
    s32 nC;
};


extern "C" {
u8 TWindowDD__sub_80347858(s16 arg0);
s32 TWindowDD__sub_8034740C(WordSelectMessage *, char *, s32 *);
s32 TWindowDD__sub_80347474(WordSelectMessage *, s32, char *, s32 *);
s32 append_word_select_token(s32, char *, s32 *);
s32 TWindowDD__sub_80347758(WordSelectMessage *, WordSelectMessage *);
s32 TWindowDD__sub_803474CC(WordSelectMessage *, s32, char *, char *, s32 *);
char fn_80228C54(char);
void TWindowDD__sub_8034694C(WordSelectMessage *, s32, char *, char *, char *, s32 *);
s32 TWindowDD__sub_8034435C(TWindowDD *window_dd, u32 arg1, s32 entry_id, s32 value_index) {
    s32 v;
    switch (arg1) {
    case 0:
        v = TWindowDD_read_indexed_value(TWindowDD__sub_80346DB8((saddr)window_dd), value_index);
        if (v == -0x1E) {
            switch (window_dd->get_word_select_context()) {
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
        if (((s32 (*)(s16))TWindowDD__sub_80347858)(resolved) != 0) {
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
            v = TWindowDD__ws_data_table[0xF].values[window_dd->selected_word - 0x37];
        } else {
            v = TWindowDD__ws_data_table[0x10].values[window_dd->selected_word - 0x37];
        }
        break;
    case 14:
        v = TWindowDD_read_indexed_value(0xF, window_dd->selected_word - 0x37);
        break;
    case 15:
        v = -0x32;
        break;
    case 17:
        v = TWindowDD_read_indexed_value(0x11, window_dd->selected_word - 0x37);
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
s32 TWindowDD__sub_80344568(TWindowDD *window_dd, u32 arg1, s32 entry_id, s32 value_index) {
    s32 v;
    switch (arg1) {
    case 0:
        v = TWindowDD_read_indexed_value(TWindowDD__sub_80346DB8((saddr)window_dd), value_index);
        if (v == -0x1E) {
            switch (window_dd->get_word_select_context()) {
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
        if (((s32 (*)(s16))TWindowDD__sub_80347858)(resolved) != 0) {
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
            v = TWindowDD__ws_data_table[0xF].values[window_dd->selected_word - 0x37];
        } else {
            v = TWindowDD__ws_data_table[0x10].values[window_dd->selected_word - 0x37];
        }
        break;
    case 14:
        v = TWindowDD_read_indexed_value(0xF, window_dd->selected_word - 0x37);
        break;
    case 15:
        v = -0x32;
        break;
    case 17:
        v = TWindowDD_read_indexed_value(0x11, window_dd->selected_word - 0x37);
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
s32 TWindowDD__sub_80344774(TWindowDD *window_dd, u32 arg1, s32 entry_id, s32 value_index) {
    s32 v;
    switch (arg1) {
    case 0:
        v = TWindowDD_read_indexed_value(TWindowDD__sub_80346DB8((saddr)window_dd), value_index);
        if (v == -0x1E) {
            switch (window_dd->get_word_select_context()) {
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
        if (((s32 (*)(s16))TWindowDD__sub_80347858)(resolved) != 0) {
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
            v = TWindowDD__ws_data_table[0xF].values[window_dd->selected_word - 0x37];
        } else {
            v = TWindowDD__ws_data_table[0x10].values[window_dd->selected_word - 0x37];
        }
        break;
    case 14:
        v = TWindowDD_read_indexed_value(0xF, window_dd->selected_word - 0x37);
        break;
    case 15:
        v = -0x32;
        break;
    case 17:
        v = TWindowDD_read_indexed_value(0x11, window_dd->selected_word - 0x37);
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
        TWindowDD__sub_8034740C(src, window_dd, &pos);
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
            struct { WordSelectMessage dd; u8 pad[0x10]; } tmp;
            TWindowDD__sub_80347758(src, &tmp.dd);
            pos = format_message_text__9TWindowDDFPvPvUs(&tmp.dd, window_dd, player);
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
            TWindowDD::append_string(TWindowDD__data_805D6E28[0xA58 / 4], window_dd, &pos);
            k = 2;
        } else if (id >= 0x68C && id <= 0x697) {
            append_word_select_token(id, window_dd, &pos);
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(TWindowDD__data_805D6E28[0xA4C / 4], window_dd, &pos);
            k = 1;
        } else if (id == 0x698) {
            TWindowDD::append_string(TWindowDD__data_805D6E28[0xA4C / 4], window_dd, &pos);
            k = 1;
        }
        if (n > 1) {
            i = src->ids[1];
            TWindowDD::show_message_by_count(window_dd, &pos);
            if (k == 0) {
                append_word_select_token(i, window_dd, &pos);
            } else {
                Pair_80344980 *p;
                if (k == 1) {
                    p = &TWindowDD__data_805D6E40[1];
                } else {
                    p = &TWindowDD__data_805D6E40[0];
                }
                TWindowDD::append_string(TWindowDD__data_805D6E28[p->list[i - 0x5AC]], window_dd, &pos);
            }
        }
        if (n > 2) {
            TWindowDD::show_message_by_count(window_dd, &pos);
            TWindowDD__sub_80347474(src, src->ids[2], window_dd, &pos);
        }
        if (n > 3) {
            append_word_select_token(src->ids[3], window_dd, &pos);
        }
        window_dd[0] = fn_80228C54(window_dd[0]);
        break;
    }
    case 5: {
        s32 mode;
        k = src->ids[0];
        TWindowDD__sub_80347474(src, k, window_dd, &pos);
        if (k == 0x2C4) {
            mode = 0;
            i = TWindowDD::get_player_battle_flag_state(player);
        } else if (k == 0x2C7) {
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(TWindowDD__data_805D6E28[0xA58 / 4], window_dd, &pos);
            mode = 2;
            if (TWindowDD::get_player_battle_flag_state(player) == 2) {
                i = 3;
            } else {
                i = 1;
            }
        } else if (k >= 0x68C && k <= 0x697) {
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(TWindowDD__data_805D6E28[0xA4C / 4], window_dd, &pos);
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
            for (j = 0; j < TWindowDD__data_805D6E44[3].n; j++) {
                if (k == TWindowDD__data_805D6E44[3].list[j]) {
                    found = 0;
                    break;
                }
            }
            if (found != 0) {
                switch (mode) {
                case 0:
                    TWindowDD::append_string(TWindowDD__data_805D6E28[0x1A8C / 4], window_dd, &pos);
                    break;
                case 1:
                    TWindowDD::append_string(TWindowDD__data_805D6E28[0x1A94 / 4], window_dd, &pos);
                    break;
                case 2:
                    TWindowDD::append_string(TWindowDD__data_805D6E28[0x1A90 / 4], window_dd, &pos);
                    break;
                case 3:
                    TWindowDD::append_string(TWindowDD__data_805D6E28[0x1A98 / 4], window_dd, &pos);
                    break;
                }
                TWindowDD::show_message_by_count(window_dd, &pos);
            }
            if (i == 0) {
                TWindowDD__sub_80347474(src, k, window_dd, &pos);
            } else {
                Pair_80344980 *p;
                if (i == 1) {
                    p = &TWindowDD__data_805D6E44[0];
                } else if (i == 2) {
                    p = &TWindowDD__data_805D6E44[1];
                } else {
                    p = &TWindowDD__data_805D6E44[2];
                }
                TWindowDD__sub_803474CC(src, k, TWindowDD__data_805D6E28[p->list[TWindowDD::clamp_range_5FA_682(k)]], window_dd, &pos);
            }
        }
        if (n > 2) {
            append_word_select_token(src->ids[2], window_dd, &pos);
        }
        window_dd[0] = fn_80228C54(window_dd[0]);
        break;
    }
    case 6:
        ((TWindowDD *)src)->format_type6_message((saddr)window_dd, (void *)(&pos));
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
        TWindowDD__sub_8034740C(src, window_dd, &pos);
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
            struct { WordSelectMessage dd; u8 pad[0x10]; } tmp;
            TWindowDD__sub_80347758(src, &tmp.dd);
            pos = format_german_message__9TWindowDDFPvPvUs(&tmp.dd, window_dd, player);
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
            s1 = TWindowDD__data_805D6E28[0x2A6];
        } else if (id4 >= 0x68C && id4 <= 0x697) {
            append_word_select_token(id4, window_dd, &pos);
            TWindowDD::append_char(0x2C, window_dd, &pos);
            k = 1;
            s1 = TWindowDD__data_805D6E28[0x2A3];
        } else if (id4 == 0x698) {
            k = 1;
            s1 = TWindowDD__data_805D6E28[0x2A3];
        }
        if (n > 1) {
            id1 = src->ids[1];
            kind = k;
            if (kind == 0) {
                s2 = (char *)get_word_select_token_text(id1);
            } else {
                Pair_80344980 *pp;
                if (kind == 1) {
                    pp = &TWindowDD__data_805D6E40[1];
                } else {
                    pp = &TWindowDD__data_805D6E40[0];
                }
                s2 = TWindowDD__data_805D6E28[pp->list[id1 - 0x5AC]];
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
            TWindowDD__sub_80347474(src, src->ids[2], window_dd, &pos);
        }
        if (n > 3) {
            append_word_select_token(src->ids[3], window_dd, &pos);
        }
        window_dd[0] = fn_80228C54(window_dd[0]);
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
            s1 = TWindowDD__data_805D6E28[0x2A6];
        } else if (id >= 0x68C && id <= 0x697) {
            append_word_select_token(id, window_dd, &pos);
            TWindowDD::append_char(0x2C, window_dd, &pos);
            mode = 1;
            kind = TWindowDD::get_player_battle_flag_state(id - 0x68C);
            s1 = TWindowDD__data_805D6E28[0x2A3];
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
            cnt = TWindowDD__data_805D6E44[4].n;
            {
            s32 i;
            for (i = 0; i < cnt; i++) {
                if (TWindowDD__data_805D6E44[4].list[i] == id) {
                    found = 0;
                    break;
                }
            }
            }
            if (found) {
                switch (mode) {
                case 0:
                    s3 = TWindowDD__data_805D6E28[0x6A6];
                    break;
                case 1:
                    s3 = TWindowDD__data_805D6E28[0x6A8];
                    break;
                case 2:
                    s3 = TWindowDD__data_805D6E28[0x6A7];
                    break;
                case 3:
                    s3 = TWindowDD__data_805D6E28[0x6A9];
                    break;
                }
                if (n > 2 && src->ids[2] == 0x685) {
                    if (s1 != 0 && s3 != 0) {
                        TWindowDD__sub_8034694C(src, src->ids[0], s1, s3, window_dd, &pos);
                    }
                } else {
                    TWindowDD__sub_803474CC(src, src->ids[0], s1, window_dd, &pos);
                    TWindowDD::show_message_by_count(window_dd, &pos);
                    TWindowDD::append_string(s3, window_dd, &pos);
                }
                TWindowDD::show_message_by_count(window_dd, &pos);
            } else {
                TWindowDD__sub_803474CC(src, src->ids[0], s1, window_dd, &pos);
                TWindowDD::show_message_by_count(window_dd, &pos);
            }
            if (kind == 0) {
                TWindowDD__sub_80347474(src, id, window_dd, &pos);
            } else {
                Pair_80344980 *pp;
                if (kind == 2) {
                    pp = &TWindowDD__data_805D6E44[0];
                } else if (kind == 4) {
                    pp = &TWindowDD__data_805D6E44[1];
                } else if (kind == 1) {
                    pp = &TWindowDD__data_805D6E44[2];
                } else {
                    pp = &TWindowDD__data_805D6E44[3];
                }
                TWindowDD__sub_803474CC(src, id, TWindowDD__data_805D6E28[pp->list[TWindowDD::clamp_range_5FA_682(id)]], window_dd, &pos);
            }
        } else if (src->ids[0] == 0x2C7) {
            TWindowDD::append_string(s1, window_dd, &pos);
        } else {
            TWindowDD__sub_80347474(src, src->ids[0], window_dd, &pos);
        }
        if (n > 2) {
            append_word_select_token(src->ids[2], window_dd, &pos);
        }
        window_dd[0] = fn_80228C54(window_dd[0]);
        break;
    }
    case 6:
        ((TWindowDD *)src)->format_type6_message((saddr)window_dd, (void *)(&pos));
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
        Pair_80344980 *p;
        if (mode == 1) {
            p = &TWindowDD__data_805D6E40[1];
        } else {
            p = &TWindowDD__data_805D6E40[0];
        }
        TWindowDD::append_string(TWindowDD__data_805D6E28[p->list[id - 0x5AC]], window_dd, pos);
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
        TWindowDD__sub_8034740C(src, window_dd, &pos);
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
            struct { WordSelectMessage dd; u8 pad[0x10]; } tmp;
            TWindowDD__sub_80347758(src, &tmp.dd);
            pos = TWindowDD__sub_80345608(&tmp.dd, window_dd, player);
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
            TWindowDD::append_string(TWindowDD__data_805D6E28[0xA8C / 4], window_dd, &pos);
            i = 2;
        } else if (s >= 0x68C && s <= 0x697) {
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(TWindowDD__data_805D6E28[0xA80 / 4], window_dd, &pos);
            i = 1;
        } else if (s == 0x698) {
            TWindowDD::append_string(TWindowDD__data_805D6E28[0xA80 / 4], window_dd, &pos);
            i = 1;
        }
        if (n > 1) {
            append_second_term(src->ids[1], i, window_dd, &pos);
        }
        if (n > 2) {
            TWindowDD::show_message_by_count(window_dd, &pos);
            TWindowDD__sub_80347474(src, src->ids[2], window_dd, &pos);
        }
        if (n > 3) {
            append_word_select_token(src->ids[3], window_dd, &pos);
        }
        window_dd[0] = fn_80228C54(window_dd[0]);
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
        TWindowDD__sub_80347474(src, k, window_dd, &pos);
        if (k == 0x2C4) {
            mode = 0;
            i = TWindowDD::get_player_battle_flag_state(player);
        } else if (k == 0x2C7) {
            mode = 2;
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(TWindowDD__data_805D6E28[0xA8C / 4], window_dd, &pos);
            if (TWindowDD::get_player_battle_flag_state(player) == 2) {
                i = 3;
            } else {
                i = 1;
            }
        } else if (k >= 0x68C && k <= 0x697) {
            mode = 1;
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(TWindowDD__data_805D6E28[0xA80 / 4], window_dd, &pos);
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
                TWindowDD::append_string(TWindowDD__data_805D6E28[s], window_dd, &pos);
                TWindowDD::show_message_by_count(window_dd, &pos);
            }
            if (i == 0) {
                TWindowDD__sub_80347474(src, k, window_dd, &pos);
            } else {
                Pair_80344980 *p;
                if (i == 1) {
                    p = &TWindowDD__data_805D6E44[0];
                } else if (i == 2) {
                    p = &TWindowDD__data_805D6E44[1];
                } else {
                    p = &TWindowDD__data_805D6E44[2];
                }
                TWindowDD__sub_803474CC(src, k, TWindowDD__data_805D6E28[p->list[TWindowDD::clamp_range_5FA_682(k)]], window_dd, &pos);
            }
        }
        if (n > 2) {
            append_word_select_token(src->ids[2], window_dd, &pos);
        }
        window_dd[0] = fn_80228C54(window_dd[0]);
        break;
    }
    case 6:
        ((TWindowDD *)src)->format_type6_message((saddr)window_dd, (void *)(&pos));
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
        TWindowDD__sub_8034740C(src, window_dd, &pos);
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
            struct { WordSelectMessage dd; u8 pad[0x10]; } tmp;
            TWindowDD__sub_80347758(src, &tmp.dd);
            pos = format_english_message__9TWindowDDFPvPvUs(&tmp.dd, window_dd, player);
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
            TWindowDD::append_string(TWindowDD__data_805D6E28[(0xA60 / 4)], window_dd, &pos);
            k = 2;
        } else if (id >= 1676 && id <= 1687) {
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(TWindowDD__data_805D6E28[(0xA54 / 4)], window_dd, &pos);
            k = 2;
        } else if (id == 1688) {
            TWindowDD::append_string(TWindowDD__data_805D6E28[(0xA54 / 4)], window_dd, &pos);
            k = 2;
        }
        if (n > 1) {
            i = src->ids[1];
            TWindowDD::show_message_by_count(window_dd, &pos);
            if (k == 0) {
                append_word_select_token(i, window_dd, &pos);
            } else {
                TWindowDD::append_string(TWindowDD__data_805D6E28[(TWindowDD__data_805D6E40->list[i - 1452])], window_dd, &pos);
            }
        }
        if (n > 2) {
            TWindowDD::show_message_by_count(window_dd, &pos);
            switch (TWindowDD__data_805D6E48[TWindowDD::clamp_range_2C9_552(src->ids[2])]) {
            case 1:
                TWindowDD::append_string(TWindowDD__data_805D6E28[(0x19E4 / 4)], window_dd, &pos);
                TWindowDD::append_char(0x20, window_dd, &pos);
                break;
            case 2:
                TWindowDD::append_string(TWindowDD__data_805D6E28[(0x19E8 / 4)], window_dd, &pos);
                TWindowDD::append_char(0x20, window_dd, &pos);
                break;
            }
            TWindowDD__sub_80347474(src, src->ids[2], window_dd, &pos);
        }
        if (n > 3) {
            append_word_select_token(src->ids[3], window_dd, &pos);
        }
        window_dd[0] = fn_80228C54(window_dd[0]);
        break;
    }
    case 5: {
        s32 kind;
        s32 id;
        id = src->ids[0];
        TWindowDD__sub_80347474(src, id, window_dd, &pos);
        if (id == 708) {
            kind = 0;
        } else if (id == 711) {
            kind = 2;
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(TWindowDD__data_805D6E28[(0xA60 / 4)], window_dd, &pos);
        } else if (id >= 1676 && id <= 1687) {
            kind = 1;
            TWindowDD::append_char(0x2C, window_dd, &pos);
            TWindowDD::append_string(TWindowDD__data_805D6E28[(0xA54 / 4)], window_dd, &pos);
        } else {
            kind = 3;
            window_dd[0] = fn_80228C54(window_dd[0]);
        }
        if (n > 1) {
            s32 notfound;
            char *str;
            TWindowDD::show_message_by_count(window_dd, &pos);
            b = src->ids[1];
            notfound = 1;
            for (i = 0; i < TWindowDD__data_805D6E44[0].n; i++) {
                if (b == TWindowDD__data_805D6E44[0].list[i]) {
                    notfound = 0;
                    break;
                }
            }
            if (notfound != 0) {
                switch (kind) {
                case 0:
                    TWindowDD::append_string(TWindowDD__data_805D6E28[(6012 / 4)], window_dd, &pos);
                    break;
                case 1:
                case 2:
                    TWindowDD::append_string(TWindowDD__data_805D6E28[(6016 / 4)], window_dd, &pos);
                    break;
                case 3:
                    TWindowDD::append_string(TWindowDD__data_805D6E28[(6020 / 4)], window_dd, &pos);
                    break;
                }
                TWindowDD::show_message_by_count(window_dd, &pos);
            }
            str = 0;
            if (kind == 2) {
                for (i = 0; i < TWindowDD__data_805D6E44[1].n; i++) {
                    if (b == TWindowDD__data_805D6E44[1].list[i]) {
                        str = TWindowDD__data_805D6E28[(TWindowDD__data_805D6E44[2].list[i])];
                        break;
                    }
                }
            }
            if (str != 0) {
                TWindowDD__sub_803474CC(src, b, str, window_dd, &pos);
            } else {
                TWindowDD__sub_80347474(src, b, window_dd, &pos);
            }
        }
        if (n > 2) {
            append_word_select_token(src->ids[2], window_dd, &pos);
        }
        window_dd[0] = fn_80228C54(window_dd[0]);
        break;
    }
    case 6:
        ((TWindowDD *)src)->format_type6_message((saddr)window_dd, (void *)(&pos));
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
        TWindowDD__sub_8034740C(entry, window_dd, &pos);
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
                ((TWindowDD *)window_dd)->maybe_scroll(&pos);
            }
            TWindowDD__sub_80347474(entry, entry->ids[i], window_dd, &pos);
        }
        }
        if (entry->count > 3) {
            ((TWindowDD *)window_dd)->append_prompt_newline(&pos);
            append_word_select_token(entry->ids[3], window_dd, &pos);
        }
        break;
    case 4:
        if (n > 2) {
            TWindowDD__sub_80347474(entry, entry->ids[2], window_dd, &pos);
        }
        if (n > 1) {
            ((TWindowDD *)window_dd)->maybe_scroll(&pos);
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
                ((TWindowDD *)window_dd)->maybe_scroll(&pos);
            }
            TWindowDD__sub_80347474(entry, entry->ids[i], window_dd, &pos);
        }
        }
        break;
    case 6:
        ((TWindowDD *)entry)->format_type6_message((saddr)window_dd, (void *)(&pos));
        break;
    }
    window_dd[pos++] = 0;
    return pos;
}

s32 TWindowDD__sub_80346434(TWindowDD *window_dd, u32 arg1, s32 entry_id, s32 value_index) {
    s32 v;
    switch (arg1) {
    case 0:
        v = TWindowDD_read_indexed_value(TWindowDD__sub_80346DB8((saddr)window_dd), value_index);
        if (v == -0x1E) {
            switch (window_dd->get_word_select_context()) {
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
        if (((s32 (*)(s16))TWindowDD__sub_80347858)(resolved) != 0) {
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
            v = TWindowDD__ws_data_table[0xF].values[window_dd->selected_word - 0x37];
        } else {
            v = TWindowDD__ws_data_table[0x10].values[window_dd->selected_word - 0x37];
        }
        break;
    case 14:
        v = TWindowDD_read_indexed_value(0xF, window_dd->selected_word - 0x37);
        break;
    case 15:
        v = -0x32;
        break;
    case 17:
        v = TWindowDD_read_indexed_value(0x11, window_dd->selected_word - 0x37);
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
s32 TWindowDD__sub_80346640(TWindowDD *window_dd, u32 arg1, s32 entry_id, s32 value_index) {
    s32 var_r31;
    s16 temp_r31;

    switch (arg1) {
    case 0:
        var_r31 = ((s16 (*)(s32, s32))TWindowDD_read_indexed_value)(TWindowDD__sub_80346DB8((saddr) window_dd), value_index);
        if (var_r31 == -0x1E) {
            switch (window_dd->get_word_select_context()) {
            case 1:
                var_r31 = 0x10;
                break;
            case 0:
                var_r31 = 0xF;
                break;
            case 3:
                var_r31 = 0x12;
                break;
            case 2:
                var_r31 = 0x11;
                break;
            case 4:
                var_r31 = 0x13;
                break;
            case 5:
                var_r31 = 0x14;
                break;
            }
        }
        break;
    case 1:
    case 2:
    case 6:
        var_r31 = -0x3C;
        break;
    case 3:
        temp_r31 = TWindowDD_read_resolved_value(entry_id, value_index);
        if (((s32 (*)(s16)) TWindowDD__sub_80347858)(temp_r31) != 0) {
            var_r31 = ((s16 (*)(s32, s32))TWindowDD_read_indexed_value)(0xF, temp_r31 - 0x37);
        } else {
            var_r31 = -0x3C;
        }
        break;
    case 5:
        var_r31 = ((s16 (*)(s32, s32))TWindowDD_read_indexed_value)(0xE, value_index);
        break;
    case 7:
        var_r31 = ((s16 (*)(s32, s32))TWindowDD_read_indexed_value)(0xF, value_index);
        break;
    case 8:
        var_r31 = ((s16 (*)(s32, s32))TWindowDD_read_indexed_value)(0x10, window_dd->selected_word - 0x37);
        break;
    case 9:
        var_r31 = -0x32;
        break;
    case 10:
        if (TWindowDD_read_resolved_value(0x118, value_index) == 0x685) {
            var_r31 = -0x3C;
        } else {
            var_r31 = -1;
        }
        break;
    default:
        var_r31 = -1;
        break;
    }
    return var_r31;
}
#define BUF_803467CC ((Buf_803467CC *)TWindowDD__word_select_lists)
void build_item_list__9TWindowDDFPv(TWindowDD *window) {
    s32 kind;
    s32 id;
    List_803467CC *sel;
    s32 idx;
    List_803467CC *entry;
    List_803467CC *extra;
    s32 n;
    s16 *a;
    s16 *b;
    s32 i;
    s32 j;
    switch (TWindowDD__window_mode) {
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
    idx = window->menu_index - 0x7F;
    entry = (List_803467CC *)TWindowDD::get_entry(kind);
    if (entry != NULL && idx >= 0 && idx < entry->count) {
        sel = (List_803467CC *)TWindowDD::get_element_ptr(entry->items[idx]);
    }
    extra = (List_803467CC *)TWindowDD::get_element_ptr(id);
    n = 0;
    a = BUF_803467CC->a;
    b = BUF_803467CC->b;
    if (sel != NULL) {
        for (i = 0; i < sel->count && n < 0x20; n++, i++) {
            a[n] = b[n] = sel->items[i];
        }
    }
    BUF_803467CC->nC = n;
    for (j = 0; j < extra->count && n < 0x20; j++, n++) {
        a[n] = extra->items[j];
    }
    BUF_803467CC->n4 = n;
}

void TWindowDD__sub_8034694C(WordSelectMessage *src, s32 id, char *verb, char *phrase, char *window_dd, s32 *pos) {
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
        window_dd[*pos] = fn_80228C54(window_dd[*pos]);
        *pos += n;
        TWindowDD::show_message_by_count(window_dd, pos);
        TWindowDD__sub_803474CC(src, id, verb, window_dd, pos);
        len -= n;
        if (len > 0 && TWindowDD::can_append_chars(len, pos) != 0) {
            strncpy(window_dd + *pos, phrase + n, len);
            *pos += len;
        }
    }
}
}
