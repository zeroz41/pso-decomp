#include "types.h"
#include "pso/quest/TQuestVmDownLoadServer_803E6970.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/quest/QuestDownloadServer.h"

extern "C" {
char quest_vm_download_server_file_info[0x44] ATTRIBUTE_ALIGN(4);
QuestDownloadFileCache quest_download_slot_table;
u8 quest_name_index_table[1024][4] ATTRIBUTE_ALIGN(4);
u8 lbl_80591AC4[0x404];
s32 quest_download_ask_header_size;
s32 quest_download_header_name_index_hi_count;
QuestDownloadCachePage *file_page_cache_head;
s32 quest_download_name_search_lo;
s32 quest_download_name_search_hi;

s32 TQuestVmDownLoadServer__sub_803E6970(s32 start, s32 count, u16 *buf, s32 flag) {
    QuestDownloadInputEntry *e;
    u16 *dst;
    QuestDownloadInputEntry *end;
    u16 *q;
    s32 hit;
    u16 c;
    s32 n;
    e = quest_download_entry_table + start;
    end = quest_download_entry_table + (start + count);
    dst = buf;
    hit = 0;
    while (e < end) {
        if (e == lbl_805D78C8) {
            for (q = quest_download_buffer_start; q < quest_vm_download_buffer_end; q++) {
                c = *q;
                if (c & 0x4000) {
                    c = TQuestVmDownLoadServer__sub_803E721C(c);
                } else {
                    c = (u8)c;
                }
                if (flag != 0 && q == lbl_805D78D0) {
                    n = TQuestVmDownLoadServer::encode_char_with_attr(dst, c, 8);
                    flag = 0;
                } else {
                    n = TQuestVmDownLoadServer::encode_char_with_attr(dst, c, 4);
                }
                dst += n;
            }
            hit = 1;
        }
        if (e >= lbl_805D78C4) {
            break;
        }
        if (flag != 0 && hit != 0) {
            n = TQuestVmDownLoadServer::encode_char_with_attr(dst, e->ch, 8);
            flag = 0;
        } else {
            n = TQuestVmDownLoadServer::encode_char_with_attr(dst, e->ch, 4);
        }
        dst += n;
        hit = 0;
        e++;
    }
    if (flag != 0) {
        dst += TQuestVmDownLoadServer::encode_char_with_attr(dst, 0x20, 8);
    }
    return dst - buf;
}

void TQuestVmDownLoadServer__sub_803E6ACC(s32 arg0) {
    quest_download_server_state = TQuestVmDownLoadServer::get_download_state();
    TQuestVmDownLoadServer::init_block_free_list();
    TQuestVmDownLoadServer::init_entries();
    quest_download_buffer_ptr = quest_download_buffer_storage;
    lbl_805D78D0 = quest_download_buffer_storage;
    quest_download_buffer_start = quest_download_buffer_storage;
    quest_vm_download_buffer_end = quest_download_buffer_storage;
    lbl_805D78C4 = quest_download_entry_table;
    lbl_805D78C8 = quest_download_entry_table;
    lbl_805D78B8 = quest_download_scratch_storage;
    lbl_805D78BC = quest_download_scratch_storage;
    quest_text_end = 0;
    TQuestVmDownLoadServer__sub_803EAE84(0, 0x50, 0);
    reset_entry_text_accumulator();
    if (arg0 == 1) {
        quest_download_match_length_limit = 0x23;
        lbl_805D7848 = 1;
    }
}

void TQuestVmDownLoadServer__sub_803E6B70(u8 *dst, s32 start, s32 count, s32 mode) {
    QuestDownloadInputEntry *e;
    QuestDownloadInputEntry *end;
    u16 c;
    u16 prev;
    s32 i;
    s32 last;
    u16 *p;

    if (mode >= 5) {
        s32 j;
        e = quest_download_entry_table;
        i = 0;
        j = 0;
        while (j < start) {
            i += e->len;
            j++;
            e++;
        }
        last = i;
        j = 0;
        while (j < count) {
            last += e->len;
            j++;
            e++;
        }
        p = quest_download_buffer_storage + i;
        for (; i < last; i++) {
            if (mode == 5) {
                u16 k = TQuestVmDownLoadServer::jis_to_sjis(TQuestVmDownLoadServer__sub_803E721C(*p++ | 0x100));
                dst[0] = k >> 8;
                dst[1] = k;
                dst += 2;
            } else if (mode == 6) {
                *dst++ = *p++;
            }
        }
        *dst = 0;
        return;
    }
    e = quest_download_entry_table + start;
    end = e + count;
    prev = 0;
    for (; e < end; e++) {
        c = e->ch;
        if (mode == 1) {
            if (!(c & 0xFF00)) {
                if (c == 0xDE && TQuestVmDownLoadServer__sub_803E7018(prev) != 0) {
                    dst -= 2;
                    if (prev == 0x2426) {
                        c = 0x2474;
                    } else {
                        c = prev + 1;
                    }
                } else if (c == 0xDF && TQuestVmDownLoadServer__sub_803E6F98(prev) != 0) {
                    dst -= 2;
                    c = prev + 2;
                } else {
                    c = TQuestVmDownLoadServer__sub_803E721C(c);
                }
            }
            if ((c & 0xFF00) == 0x2500) {
                c &= 0x24FF;
            }
        } else if (mode == 2) {
            if (!(c & 0xFF00)) {
                if (c == 0xDE && TQuestVmDownLoadServer__sub_803E7018(prev) != 0) {
                    dst -= 2;
                    if (prev == 0x2526) {
                        c = 0x2574;
                    } else {
                        c = prev + 1;
                    }
                } else if (c == 0xDF && TQuestVmDownLoadServer__sub_803E6F98(prev) != 0) {
                    dst -= 2;
                    c = prev + 2;
                } else {
                    c = TQuestVmDownLoadServer__sub_803E721C(c | 0x100);
                }
            }
            if ((c & 0xFF00) == 0x2400) {
                c |= 0x2500;
            }
        } else if (mode == 3) {
            dst += TQuestVmDownLoadServer__sub_803E7098(dst, c);
            continue;
        } else if (mode == 4) {
            if (!(c & 0xFF00)) {
                c = TQuestVmDownLoadServer__sub_803E721C(c | 0x100);
            }
        }
        prev = c;
        if (c & 0xFF00) {
            u16 k = TQuestVmDownLoadServer::jis_to_sjis(c);
            *dst++ = k >> 8;
            c = k;
        }
        *dst++ = c;
    }
    *dst = 0;
}

#pragma push
#pragma opt_common_subs off
void TQuestVmDownLoadServer::init_buffer_pointers() {
    quest_download_buffer_ptr = quest_download_buffer_storage;
    lbl_805D78D0 = quest_download_buffer_storage;
    quest_download_buffer_start = quest_download_buffer_storage;
    quest_vm_download_buffer_end = quest_download_buffer_storage;
    lbl_805D78C4 = quest_download_entry_table;
    lbl_805D78C8 = quest_download_entry_table;
    lbl_805D78B8 = quest_download_scratch_storage;
    lbl_805D78BC = quest_download_scratch_storage;
    quest_text_end = 0;
    TQuestVmDownLoadServer__sub_803EAE84(0, 0x50, 0);
    reset_entry_text_accumulator();
}
#pragma pop

s32 TQuestVmDownLoadServer::get_buffer_size() {
    return 0x48;
}


u8 TQuestVmDownLoadServer::lookup_value_by_key(u16 key) {
    const JisSymbolEntry *p;
    for (p = jis_to_single_byte_symbol_table; p < jis_to_single_byte_symbol_table + 45; p++) {
        if (p->key == key) {
            return p->val;
        }
        if (p->key > key) {
            break;
        }
    }
    return 0;
}

#pragma push
#pragma bool off

s32 TQuestVmDownLoadServer__sub_803E6F98(u16 ch) {
    u8 decoded[2];
    u16 code;
    code = ch;
    if (TQuestVmDownLoadServer__is_sjis_double_byte(ch) != 0) {
        code = TQuestVmDownLoadServer__sub_803EC69C(code);
    }
    if (TQuestVmDownLoadServer__sub_803E7098(decoded, code) != 1) {
        return 0;
    }
    return (romaji_kana_char_class_table[decoded[0]] & 0xF) == 0xB;
}

s32 TQuestVmDownLoadServer__sub_803E7018(u16 ch) {
    u8 decoded[2];
    u16 code;
    code = ch;
    if (TQuestVmDownLoadServer__is_sjis_double_byte(ch) != 0) {
        code = TQuestVmDownLoadServer__sub_803EC69C(code);
    }
    if (TQuestVmDownLoadServer__sub_803E7098(decoded, code) != 1) {
        return 0;
    }
    return (romaji_kana_char_class_table[decoded[0]] & 0xF) == 0xA;
}

#pragma pop

s32 TQuestVmDownLoadServer__sub_803E7098(u8 *p, u16 code) {
    u8 c;
    s32 w = code;

    switch (code & 0xFF00) {
    case 0x2300:
    case 0x0:
        *p = w;
        return 1;
    case 0x2500:
        code &= 0x24FF;
    case 0x2400:
    case 0x2100:
        c = TQuestVmDownLoadServer__sub_803EC8D8(code);
        if ((u8)c < 0x98 || (u8)c >= 0xF7) {
            *p = c;
            return 1;
        }
        code = quest_download_char_code_table[(u8)c - 0x98];
        *p++ = code;
        if (code & 0x8000) {
            *p = 0xDE;
            return 2;
        }
        if (code & 0x4000) {
            *p = 0xDF;
            return 2;
        }
        return 1;
    default:
        *p = 0x20;
        return 1;
    }
}

s32 TQuestVmDownLoadServer__sub_803E719C(u8 ch, s32 jis) {
    return ch | ((jis & 0x100) + 0x2400);
}

u16 TQuestVmDownLoadServer::map_key_to_code(u32 ch) {
    const u8 *k;
    const u16 *v;
    k = key_symbol_chars;
    v = key_symbol_jis;
    while (*k != 0) {
        if (*k == (u8)ch) {
            u16 t = *v;
            if ((t & 0xFF00) == 0x2500 && !(ch & 0x100)) {
                return (u8)t | 0x2400;
            }
            return t;
        }
        k++;
        v++;
    }
    return 0;
}

u16 TQuestVmDownLoadServer__sub_803E721C(u16 ch) {
    u16 jis;
    jis = single_byte_to_jis_table[ch & 0xFF];
    if (((s32) (jis & 0xFF00) == 0x2500) && !(ch & 0x100)) {
        return (u8) jis | 0x2400;
    }
    return jis;
}

s32 TQuestVmDownLoadServer::is_valid_item_for_slot(u8 c, u8 k) {
    if (c >= 0xC0) {
        return 1;
    }
    if (c < 0x80) {
        if (c < 0x2D && k != 0) {
            if (c >= 1 && c <= 0xD) {
                c += 0x7F;
            } else {
                c = 0;
            }
            if (c == 0) {
                return 0;
            }
        } else {
            if (c == 0xD || (c >= 0x13 && c <= 0x34) || c == 0x38) {
                return 1;
            }
            return 0;
        }
    }
    switch (c) {
    case 0x8B:
    case 0x8D:
    case 0x93:
    case 0x96:
    case 0x99:
    case 0x9A:
    case 0x9B:
    case 0x9E:
    case 0xA1:
    case 0xA2:
    case 0xA7:
    case 0xA8:
    case 0xB1:
        if ((k >= 5 && k <= 8) || k >= 0xA) {
            return 1;
        }
        break;
    case 0x97:
        if (k == 8) {
            return 0;
        }
    case 0x8E:
    case 0x92:
    case 0x94:
    case 0x95:
    case 0x98:
    case 0xA0:
        if (k >= 5) {
            return 1;
        }
        break;
    default:
        if (k == 4 || (u8)(k - 7) <= 1 || k >= 0xA) {
            return 1;
        }
        break;
    }
    return 0;
}

struct Row_803E7390 { s16 single; s16 pair; };

static const u8 glyph_bits[0x3E0] = {
    0x00, 0x08, 0x76, 0xE8, 0x4F, 0xEE, 0xDC, 0x00, 0x08, 0x76, 0xF8, 0xFF, 0xFF, 0xDD, 0x00, 0x08,
    0x76, 0xF8, 0xEF, 0xFF, 0xDD, 0x00, 0x08, 0x76, 0xF8, 0xCF, 0xFF, 0xCC, 0x00, 0x08, 0x76, 0xE8,
    0xCF, 0xEB, 0x5D, 0x00, 0x04, 0x38, 0xF4, 0x27, 0x77, 0x2E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x58,
    0x10, 0x00, 0x81, 0x0E, 0x30, 0x01, 0x8C, 0x0A, 0x80, 0x40, 0x87, 0xFE, 0x64, 0x4E, 0x05, 0x40,
    0xA0, 0x03, 0x6C, 0x04, 0xA3, 0x02, 0x20, 0xD0, 0x01, 0x00, 0x80, 0x51, 0x01, 0x10, 0xE8, 0xD0,
    0x97, 0xDD, 0xBB, 0x00, 0x08, 0x74, 0x00, 0x01, 0x20, 0x40, 0x00, 0x04, 0x3A, 0xF4, 0x67, 0x31,
    0x2E, 0x00, 0x02, 0x1D, 0xFA, 0xB3, 0x19, 0x15, 0x00, 0x01, 0x0E, 0x3D, 0x09, 0x8C, 0x0A, 0x80,
    0x40, 0x87, 0xBC, 0x68, 0x56, 0x05, 0x40, 0xA0, 0x43, 0x1B, 0x36, 0xAF, 0x02, 0x20, 0xD0, 0x01,
    0x26, 0x81, 0x77, 0x01, 0x10, 0xE8, 0x40, 0x90, 0xCC, 0xAA, 0x00, 0x08, 0x74, 0x28, 0x08, 0x60,
    0x54, 0x00, 0x04, 0x3A, 0xC4, 0x2C, 0xF3, 0x3F, 0x00, 0x02, 0x1D, 0x6A, 0x92, 0x79, 0x17, 0x00,
    0x00, 0x00, 0xFF, 0xFD, 0xBF, 0x03, 0x00, 0x00, 0xC0, 0x0A, 0x00, 0x3B, 0x00, 0x00, 0x00, 0xA4,
    0x60, 0xB3, 0x03, 0x20, 0x00, 0x40, 0x02, 0x06, 0x3B, 0x00, 0xFE, 0x01, 0x00, 0x20, 0x00, 0x00,
    0x01, 0x48, 0x50, 0x60, 0x00, 0x00, 0x02, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x1F,
    0x00, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0xA0,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x00, 0x00, 0x81, 0x0E, 0x00, 0x01,
    0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x02, 0x1D, 0x00, 0x20, 0x18, 0x15, 0x89, 0x40, 0x00, 0x02,
    0x10, 0x80, 0x00, 0x37, 0x20, 0x00, 0x01, 0x08, 0x40, 0x40, 0x02, 0x18, 0x80, 0x40, 0x04, 0x20,
    0x00, 0x03, 0x00, 0x20, 0x00, 0x00, 0x01, 0x08, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x08, 0x20, 0x10, 0x01,
    0x18, 0xC0, 0x00, 0x10, 0x00, 0x00, 0x02, 0x00, 0x00, 0x01, 0x04, 0x08, 0x00, 0x03, 0x12, 0x00,
    0x80, 0x40, 0x00, 0x02, 0x00, 0x43, 0x11, 0x80, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x20, 0x00,
    0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x08, 0x04, 0x40, 0x00, 0x00, 0x80, 0x00, 0x04,
    0x20, 0x00, 0x01, 0x08, 0x40, 0x00, 0x02, 0x10, 0x80, 0x00, 0x00, 0x20, 0x00, 0x01, 0x08, 0x40,
    0x00, 0x02, 0x10, 0x80, 0x00, 0x04, 0x28, 0x00, 0x00, 0x08, 0x40, 0x00, 0x02, 0x10, 0x80, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x01,
    0x11, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
    0x10, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x20, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x14, 0x41, 0x00, 0x02, 0x10, 0x80, 0x00, 0x04, 0x08, 0x80, 0x03, 0x00, 0x40, 0x00,
    0x00, 0x10, 0x80, 0x00, 0x02, 0x50, 0x40, 0x00, 0x06, 0x30, 0x80, 0x00, 0x08, 0xC0, 0x00, 0x04,
    0x00, 0x00, 0x01, 0x00, 0x90, 0x00, 0x03, 0x10, 0x80, 0x00, 0x05, 0xA0, 0x00, 0x06, 0x30, 0x00,
    0x00, 0x00, 0x80, 0x08, 0x02, 0x34, 0xC0, 0x00, 0x08, 0x20, 0x40, 0x00, 0x08, 0x00, 0x00, 0x02,
    0x24, 0x00, 0x01, 0x0C, 0x40, 0x00, 0x02, 0x10, 0x80, 0x00, 0x04, 0x20, 0x00, 0x01, 0x08, 0x60,
    0x00, 0x02, 0x10, 0x80, 0x00, 0x02, 0x22, 0x80, 0x01, 0x0C, 0x40, 0x00, 0x02, 0x10, 0x20, 0x00,
    0x04, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x09, 0x40, 0x00, 0x02, 0x10, 0x80, 0x00, 0x00,
    0x00, 0x80, 0x00, 0x08, 0x00, 0x00, 0x02, 0x18, 0x40, 0x00, 0x02, 0x30, 0x80, 0x02, 0x08, 0xC0,
    0x50, 0x04, 0x20, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x20, 0x00, 0x01, 0x0A, 0x40, 0x00, 0x02, 0x10, 0x00, 0x00, 0x04, 0x20, 0x00, 0x01, 0x08, 0x40,
    0x00, 0x02, 0x00, 0xA0, 0x20, 0x01, 0x08, 0x40, 0x00, 0x20, 0x00, 0x01, 0x09, 0x40, 0x00, 0x02,
    0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0x02, 0x18, 0x00, 0x00, 0x00, 0x22,
    0x00, 0x01, 0x08, 0x40, 0x00, 0x02, 0x10, 0x80, 0x00, 0x04, 0x20, 0x00, 0x00, 0x08, 0x40, 0x00,
    0x02, 0x10, 0x80, 0x00, 0x04, 0x20, 0x00, 0x01, 0x09, 0x40, 0x00, 0x02, 0x10, 0x80, 0x00, 0x03,
    0x20, 0x00, 0x00, 0x08, 0x00, 0x40, 0x00, 0x18, 0x88, 0x40, 0x00, 0x22, 0x10, 0x80, 0x00, 0x04,
    0x20, 0x00, 0x01, 0x09, 0x40, 0x00, 0x02, 0x10, 0x80, 0x00, 0x22, 0x20, 0x00, 0x00, 0x08, 0x00,
    0x40, 0x02, 0x18, 0x80, 0x00, 0x04, 0x20, 0x50, 0x82, 0x10, 0x84, 0x20, 0x00, 0x40, 0x00, 0x02,
    0x10, 0x80, 0x00, 0x04, 0x20, 0x00, 0x00, 0x00, 0x41, 0x00, 0x40, 0x10, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x80, 0x50, 0x04, 0x20, 0x00, 0x01, 0x10, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x08,
    0x20, 0x01, 0x06, 0x00, 0x00, 0x00, 0x02, 0x01, 0x08, 0x40, 0x00, 0x02, 0x10, 0x80, 0x00, 0x04,
    0x20, 0x00, 0x01, 0x08, 0x40, 0x00, 0x02, 0x18, 0x80, 0x00, 0x04, 0x00, 0x00, 0x00, 0x84, 0x22,
    0x00, 0x01, 0x08, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x04, 0x20, 0x00, 0x00,
    0x00, 0x10, 0x48, 0x40, 0x02, 0x10, 0x90, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x40, 0x00, 0x00,
    0x02, 0x40, 0x00, 0x04, 0x20, 0x20, 0x41, 0x02, 0x10, 0x80, 0x00, 0x04, 0x20, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x46, 0x2A, 0x90, 0x80, 0x0C, 0x24, 0x20, 0xC0, 0x0D, 0x08,
    0x40, 0x00, 0x02, 0x10, 0x90, 0x00, 0x06, 0x20, 0x01, 0x01, 0x48, 0xA4, 0x22, 0x01, 0x09, 0x48,
    0x20, 0x02, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x01, 0x08, 0x60, 0x00, 0x00, 0x00, 0x90, 0x48,
    0x00, 0x02, 0x10, 0x80, 0x00, 0x04, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x12, 0xC0, 0x00,
    0x04, 0x00, 0x00, 0x41, 0x02, 0x10, 0x80, 0x00, 0x04, 0x20, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x04, 0x80, 0x00, 0x06, 0x20, 0x00, 0x00, 0x08, 0x12, 0x80, 0x00, 0x04, 0x20, 0x40, 0x01, 0x04,
    0x00, 0x00, 0x00, 0x10, 0x00, 0x80, 0x04, 0x38, 0x00, 0x01, 0x00, 0x40, 0x90, 0x00, 0x04, 0x20,
    0x00, 0x01, 0x08, 0x00, 0x02, 0x02, 0x10, 0x80, 0x00, 0x00, 0x24, 0x80, 0x01, 0x08, 0x40, 0x00,
    0x02, 0x24, 0x00, 0x01, 0x08, 0x40, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x08,
    0x60, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0x00, 0x04, 0x3A, 0xF4, 0x67, 0xB3, 0x6A, 0x00,
};

static const Row_803E7390 glyph_rows[0x72] = {
    { 2086, 4095 }, { 1214, 4095 }, { 1159, 2141 }, { 1104, 3370 }, { 1049, 6416 }, { 1104, 3370 },
    { 1104, 6579 }, { 994, 3370 }, { 939, 7032 }, { 884, 3554 }, { 2375, 5221 }, { 2375, 5221 },
    { 2375, 5221 }, { 2375, 5221 }, { 1899, 3600 }, { 2375, 2790 }, { 1899, 3987 }, { 2375, 3201 },
    { 1899, 3987 }, { 7871, 3120 }, { 2005, 2538 }, { 1927, 2276 }, { 2375, 4734 }, { 2375, 4734 },
    { 2375, 2919 }, { 1807, 2920 }, { 829, 5110 }, { 774, 5908 }, { 774, 5908 }, { 774, 7195 },
    { 774, 7032 }, { 719, 5309 }, { 664, 7032 }, { 609, 3763 }, { 774, 7032 }, { 554, 7032 },
    { 499, 6579 }, { 444, 3897 }, { 389, 7358 }, { 774, 4547 }, { 774, 4957 }, { 168, 7521 },
    { 168, 7521 }, { 112, 5525 }, { 2375, 6066 }, { 1940, 5221 }, { 334, 5221 }, { 1269, 5437 },
    { 1269, 5437 }, { 56, 2141 }, { 56, 2141 }, { 56, 6707 }, { 2375, 4194 }, { 1807, 2920 },
    { 1807, 3030 }, { 1852, 2856 }, { 1775, 2318 }, { 1731, 2318 }, { 1688, 2837 }, { 1642, 2837 },
    { 1915, 2318 }, { 1914, 2318 }, { 1913, 2318 }, { 1596, 2318 }, { 1595, 2318 }, { 1594, 4341 },
    { 1593, 2318 }, { 1592, 2318 }, { 1591, 2318 }, { 1590, 2318 }, { 1589, 2318 }, { 1588, 2318 },
    { 1527, 2463 }, { 1575, 2318 }, { 1871, 2318 }, { 1927, 2325 }, { 1688, 2318 }, { 2042, 2318 },
    { 2375, 3701 }, { 1927, 2680 }, { 2375, 4341 }, { 1478, 6871 }, { 1478, 6871 }, { 1899, 3600 },
    { 2375, 2790 }, { 1899, 2726 }, { 279, 3370 }, { 279, 4413 }, { 0, 2437 }, { 0, 4413 },
    { 1426, 4893 }, { 1927, 4265 }, { 1899, 5686 }, { 1899, 2726 }, { 1927, 2341 }, { 1959, 5735 },
    { 1959, 5735 }, { 224, 7687 }, { 1899, 3427 }, { 2375, 4341 }, { 1927, 4265 }, { 1374, 2768 },
    { 1374, 2318 }, { 1871, 2318 }, { 1871, 2318 }, { 1871, 2318 }, { 1478, 6255 }, { 1852, 2856 },
    { 1899, 4604 }, { 2375, 6187 }, { 1919, 2318 }, { 1322, 3272 }, { 1574, 3370 }, { 1927, 3427 },
};

static const u8 glyph_col[0x100] = {
    0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0xFF, 0x0B, 0x0C, 0x0D,
    0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x14, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
    0xFF, 0xFF, 0xFF, 0x17, 0x18, 0x19, 0x1A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x16, 0x14, 0x12, 0x0C, 0x00, 0x07, 0x16, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0B, 0x0B, 0x16, 0x21, 0x2C, 0x37, 0x42,
    0x21, 0x21, 0x37, 0x4D, 0x58, 0x58, 0x2C, 0x63, 0x6E, 0x4D, 0x6E, 0x79, 0x6E, 0x42, 0x84, 0x8F,
    0x37, 0x4D, 0x2C, 0x21, 0x21, 0x6E, 0x9A, 0x21, 0x21, 0x9A, 0x9A, 0x21, 0x9A, 0x9A, 0xA5, 0xB0,
    0x9A, 0x2C, 0x9A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x25, 0x25, 0x25, 0x26, 0x26,
    0x27, 0x27, 0x28, 0x28, 0x29, 0x2A, 0x2B, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x2F, 0x2F, 0x2E, 0x2E,
    0x30, 0x31, 0x2E, 0x32, 0x32, 0x33, 0x32, 0x32, 0x32, 0x34, 0x24, 0x35, 0x35, 0x35, 0x35, 0x35,
    0x35, 0x35, 0x35, 0x24, 0x24, 0x36, 0x36, 0x37, 0x36, 0x36, 0x38, 0x36, 0x09, 0x09, 0x39, 0xFF,
};

s32 TQuestVmDownLoadServer__sub_803E7390(u8 a, u8 b, u8 c) {
    static const u8 bit_mask[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
    u8 col;
    const Row_803E7390 *row;
    s16 bit;
    if (c < 0x80) {
        return 0;
    }
    if (a < 0x2D && b != 0) {
        if (a >= 1 && a <= 0xD) {
            a += 0x7F;
        } else {
            a = 0;
        }
        if (a == 0) {
            return 0;
        }
    }
    col = glyph_col[a];
    if ((s16)col == 0xFF) {
        return 0;
    }
    if (c >= 0xC0) {
        row = &glyph_rows[c - 0xC0];
    } else {
        row = &glyph_rows[c - 0x41];
    }
    if (a < 0x80 || a >= 0xC0) {
        bit = row->single + col;
        return glyph_bits[bit >> 3] & bit_mask[bit & 7];
    }
    bit = row->pair + col + b - 1;
    return glyph_bits[bit >> 3] & bit_mask[bit & 7];
}

void TQuestVmDownLoadServer::invalidate_entries_by_id(s32 id) {
    s32 i;
    for (i = 0; i < 128; i++) {
        if (id == quest_download_slot_table.entries[i].cachedId) {
            quest_download_slot_table.entries[i].cachedId = -1;
        }
    }
}

void TQuestVmDownLoadServer::clear_entries_by_id(s32 id) {
    s32 i;
    for (i = 0; i < 128; i++) {
        if (id == (s16)(quest_download_slot_table.entries[i].cachedId >> 12)) {
            quest_download_slot_table.entries[i].cachedId = -1;
        }
    }
}

s32 TQuestVmDownLoadServer::release_ref_slot(u32 index) {
    QuestDownloadCacheEntry *r;
    if (index >= 0x80U) {
        return -1;
    }
    r = &quest_download_slot_table.entries[index];
    if (r->referenceCount == 0) {
        return -1;
    }
    r->referenceCount--;
    return 0;
}

s32 TQuestVmDownLoadServer::set_slot_values_for_indices(s32 *ids, s32 count, u32 value) {
    s32 i;
    for (i = 0; i < count; i++, ids++) {
        s32 idx = *ids;
        if (idx >= 0 && idx < 0x80 && quest_download_slot_table.entries[idx].referenceCount != 0) {
            quest_download_slot_table.entries[idx].value = (u8)value;
        }
    }
    return 0;
}

s32 TQuestVmDownLoadServer::get_max_size_of_indices(s32 count) {
    s32 *ids = (s32 *)this;
    s32 i;
    s32 max = 0;
    for (i = 0; i < count; i++) {
        s32 idx = ids[i];
        if (idx >= 0 && idx < 0x80) {
            QuestDownloadCacheEntry *r = &quest_download_slot_table.entries[idx];
            if (r->referenceCount != 0) {
                if (max < r->value) {
                    max = r->value;
                }
            }
        }
    }
    return max;
}

s32 TQuestVmDownLoadServer__sub_803E779C(u32 id, s32 *file_offset, s32 *cached_id, s32 *value) {
    QuestDownloadCacheEntry *r;
    if (id >= 0x80U) {
        return -1;
    }
    r = &quest_download_slot_table.entries[id];
    if (r->referenceCount == 0) {
        return -1;
    }
    *file_offset = r->fileOffset;
    *cached_id = r->cachedId;
    *value = r->value;
    return r->pageIndex;
}

u32 TQuestVmDownLoadServer::acquire_slot_entry(s32 page_index, s32 file_offset, s32 cached_id, s32 value) {
    s32 i;
    QuestDownloadCacheEntry *r;
    s32 free_idx;
    r = quest_download_slot_table.entries;
    free_idx = -1;
    for (i = 0; i < 128; i++, r++) {
        if (r->referenceCount == 0) {
            if (free_idx == -1) {
                free_idx = i;
            }
        } else if (r->pageIndex == page_index && r->fileOffset == file_offset && r->cachedId == cached_id) {
            r->referenceCount++;
            return i;
        }
    }
    if (free_idx == -1) {
        return -1;
    }
    r = &quest_download_slot_table.entries[free_idx];
    r->referenceCount = 1;
    r->pageIndex = page_index;
    r->fileOffset = file_offset;
    r->cachedId = cached_id;
    r->value = value;
    return free_idx;
}

void TQuestVmDownLoadServer__sub_803E79AC(void) {
    int i;
    for (i = 0; i < 0x80; i++) {
        quest_download_slot_table.entries[i].referenceCount = 0;
    }
}


#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
inline s32 Open_803E7B9C(void) {
    s32 h = aram_open(quest_vm_download_server_file_info, lbl_805D78F8);
    if (h == -1) {
        quest_download_file_handle = -1;
        return -1;
    }
    quest_download_file_handle = h;
    return 0;
}
inline s32 Seek_803E7B9C(s32 pos) {
    if (aram_seek(quest_download_file_handle, pos, 0) == -1) {
        if (Open_803E7B9C() != 0) {
            return -1;
        }
        if (aram_seek(quest_download_file_handle, pos, 0) == -1) {
            return -1;
        }
    }
    return 0;
}
inline s32 Write_803E7B9C(void) {
    return -1;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 Open_803E7ACC(void) {
    s32 mode = lbl_805D78F8;
    s32 h = aram_open(quest_vm_download_server_file_info, mode);
    if (h == -1) {
        quest_download_file_handle = -1;
        return -1;
    }
    quest_download_file_handle = h;
    return 0;
}
inline s32 Seek_803E7ACC(s32 handle, s32 pos, s32 whence) {
    return aram_seek(handle, pos, whence);
}
inline s32 SeekRetry_803E7ACC(s32 pos) {
    if (Seek_803E7ACC(quest_download_file_handle, pos, 0) == -1) {
        if (Open_803E7ACC() != 0) {
            return -1;
        }
        if (Seek_803E7ACC(quest_download_file_handle, pos, 0) == -1) {
            return -1;
        }
    }
    return 0;
}
void TQuestVmDownLoadServer::retry_seek_active_entries() {
    QuestDownloadCachePage *e;
    u8 unused[0x18];
    for (e = file_page_cache_head; e != NULL; e = e->next) {
        if (e->state == 1) {
            SeekRetry_803E7ACC((e->pageIndex << 10) + 0x3400);
        }
    }
}
#pragma pop

void TQuestVmDownLoadServer::set_active() {
    file_page_cache_head->state = 1;
}

u8 *TQuestVmDownLoadServer::get_cached_page(s32 page) {
    u8 unused[0x38];
    QuestDownloadCachePage *prev = NULL;
    QuestDownloadCachePage *p = file_page_cache_head;

    for (;;) {
        if (p->pageIndex == page) {
            if (prev != NULL) {
                prev->next = p->next;
                p->next = file_page_cache_head;
                file_page_cache_head = p;
            }
            return p->bytes;
        }
        if (p->next == NULL) {
            break;
        }
        prev = p;
        p = p->next;
    }
    prev->next = NULL;
    p->next = file_page_cache_head;
    file_page_cache_head = p;
    if (p->state == 1) {
        if (Seek_803E7B9C(p->pageIndex * 0x400 + 0x3400) != -1) {
            Write_803E7B9C();
        }
    }
    p->pageIndex = page;
    p->state = 0;
    if (Seek_803E7B9C(p->pageIndex * 0x400 + 0x3400) != -1) {
        TQuestVmDownLoadServer::aram_dma_read(quest_download_file_handle, p->bytes, 0x400);
    }
    return p->bytes;
}
#pragma pop

LAYOUT_ASSERT(QuestDownloadFileNameSize, sizeof(quest_vm_download_server_file_info) == 0x44);
LAYOUT_ASSERT(QuestDownloadNameIndexSize, sizeof(quest_name_index_table) == 0x1000);

s32 TQuestVmDownLoadServer::match_prefix_length(const u8 *a, const u8 *b, s32 n) {
    s32 i;
    for (i = 0; i < n; i++, a++, b++) {
        if (*a != *b) {
            break;
        }
        if (*a == 0) {
            break;
        }
    }
    return i;
}


#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline s32 match_803E7E3C(u8 *p, u8 *q) {
    s32 i;
    u8 c;
    for (i = 0; i < 4; i++, p++, q++) {
        c = *p;
        if (c != *q || c == 0) {
            break;
        }
    }
    return i;
}

#pragma push
#pragma opt_common_subs off
s32 TQuestVmDownLoadServer::count_matching_name_prefix(s32 idx, u8 *name) {
    u8 *p;
    u8 *q;
    s32 i;
    q = name;
    p = quest_name_index_table[idx];
    for (i = 0; i < 4; i++, p++, q++) {
        u8 c = *p;
        if (c != *q || c == 0) {
            break;
        }
    }
    if (i < 4 && name[i] != 0) {
        i++;
    }
    return i;
}
#pragma pop

s32 TQuestVmDownLoadServer::has_name_mismatch(s32 row, u8 *key) {
    s32 i = match_803E7E3C(quest_name_index_table[row + 1], key);
    if (key[i] == 0) {
        return 0;
    }
    return 1;
}
#pragma pop

s32 TQuestVmDownLoadServer::find_name_index(const char *key) {
    s32 mid;
    s32 hi;
    s32 lo;
    int r;
    hi = quest_download_name_search_hi;
    lo = quest_download_name_search_lo;
    while (lo + 1 < hi) {
        mid = (hi + lo) / 2;
        r = strncmp(key, reinterpret_cast<const char *>(quest_name_index_table[mid]), 4);
        if (r == 0) {
            return mid;
        }
        if (r > 0) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    if (strncmp(key, reinterpret_cast<const char *>(quest_name_index_table[lo]), 4) < 0) {
        return lo - 1;
    }
    return lo;
}

void TQuestVmDownLoadServer__sub_803E7F9C(u8 *text, s16 mode) {
    u8 c = *text;
    s32 col;
    s32 row;
    u8 *p;
    s32 index;
    if (c < 0xA1) {
        return;
    }
    p = text + 1;
    row = c - 0xA1;
    if (mode == 1) {
        col = 0;
    } else {
        u8 d = *p;
        if (d < 0xA1) {
            return;
        }
        col = d - 0xA0;
    }
    index = row * 11 + (col >> 3);
    lbl_805D7824[index] |= 1 << (col & 7);
    lbl_805D7820 = 1;
}

s32 TQuestVmDownLoadServer::is_char_allowed(const u8 *self_bytes, s16 len) {
  int new_var;
  u8 c = *self_bytes;
  s32 bit;
  s32 rowi;
  const u8 *p;
  if (c < 0xA1)
  {
    return 0;
  }
  p = self_bytes + 1;
  rowi = c - 0xA1;
  if (len == 1)
  {
    bit = 0;
  }
  else
  {
    u8 d = *p;
    if (1)
    {
      if (d < 0xA1)
      {
        return 0;
      }
    }
    bit = d - 0xA0;
  }
  new_var = (rowi * 0xB) + (bit >> 3);
  if ((1 << (bit & 7)) & lbl_805D7824[new_var])
  {
    return 0;
  }
  return 1;
}

s32 TQuestVmDownLoadServer__sub_803E8084(void) {
  s32 handle;
  s32 open_status;
  s32 status;
  status = 0;
  if (aram_seek(quest_download_file_handle, 0x400, (int)status) == (-1))
  {
    handle = aram_open(quest_vm_download_server_file_info, lbl_805D78F8);
    if (handle == (-1))
    {
      quest_download_file_handle = (open_status = -1);
    }
    else
    {
      quest_download_file_handle = handle;
      open_status = 0;
    }
    if (open_status != 0)
    {
      status = -1;
    }
    else
    {
      if (lbl_805D78F8)
      {
      }
      if (aram_seek(quest_download_file_handle, 0x400, 0) == (-1))
      {
        status = -1;
      }
      else
      {
        goto block_8;
      }
    }
  }
  else
  {
    block_8:
    status = 0;
  }
  if (status == (-1))
  {
    return -1;
  }
  if (((s32)TQuestVmDownLoadServer::aram_dma_read(quest_download_file_handle, quest_name_index_table, 0x1000)) != 0x1000)
  {
    return -1;
  }
  return 0;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 Open_803E8624(void) {
    s32 h = aram_open(quest_vm_download_server_file_info, lbl_805D78F8);
    if (h == -1) {
        quest_download_file_handle = -1;
        return -1;
    }
    quest_download_file_handle = h;
    return 0;
}
inline s32 Seek_803E8624(s32 handle, s32 pos, s32 whence) {
    return aram_seek(handle, pos, whence);
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
inline s32 Open_803E8150(void) {
    s32 h = aram_open(quest_vm_download_server_file_info, lbl_805D78F8);
    if (h == -1) {
        quest_download_file_handle = -1;
        return -1;
    }
    quest_download_file_handle = h;
    return 0;
}
inline s32 Seek_803E8150(s32 pos) {
    if (aram_seek(quest_download_file_handle, pos, 0) == -1) {
        if (Open_803E8150() != 0) {
            return -1;
        }
        if (aram_seek(quest_download_file_handle, pos, 0) == -1) {
            return -1;
        }
    }
    return 0;
}
inline s32 Write_803E8150(void) {
    return -1;
}
s32 TQuestVmDownLoadServer__sub_803E8150(void) {
    u8 *p = lbl_80591AC4 + 0x30;
    if (lbl_805D7874 == quest_download_ask_header_size && lbl_805D78FC == quest_download_header_name_index_hi_count && lbl_805D7820 == 0) {
        return 0;
    }
    p[0] = lbl_805D7874 % 256;
    p[1] = lbl_805D7874 / 256;
    p[2] = lbl_805D7900 % 256;
    p[3] = lbl_805D7900 / 256;
    p[4] = lbl_805D78FC % 256;
    p[5] = lbl_805D78FC / 256;
    if (Seek_803E8150(0) == -1) {
        return -1;
    }
    return Write_803E8150();
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
inline s32 Open_803E82AC(const char *filename) {
    s32 mode = lbl_805D78F8;
    s32 h = aram_open(filename, mode);
    if (h == -1) {
        quest_download_file_handle = -1;
        return -1;
    }
    quest_download_file_handle = h;
    return 0;
}
inline s32 Seek_803E82AC(const char *filename, s32 pos) {
    if (aram_seek(quest_download_file_handle, pos, 0) == -1) {
        if (Open_803E82AC(filename) != 0) {
            return -1;
        }
        if (aram_seek(quest_download_file_handle, pos, 0) == -1) {
            return -1;
        }
    }
    return 0;
}
s32 TQuestVmDownLoadServer::read_ask_header() {
    u8 *h;
    u8 unused[0x18];
    if (Seek_803E82AC(quest_vm_download_server_file_info, 0) == -1) {
        return -1;
    }
    if ((s32)TQuestVmDownLoadServer::aram_dma_read(quest_download_file_handle, lbl_80591AC4, 0x400) != 0x400) {
        return -1;
    }
    h = lbl_80591AC4;
    if (strncmp((char *)h, ask_header_signature, strlen(ask_header_signature)) != 0) {
        return -1;
    }
    quest_download_name_search_lo = 0;
    quest_download_name_search_hi = h[0x2E] + (h[0x2F] << 8);
    quest_download_ask_header_size = lbl_805D7874 = h[0x30] + (h[0x31] << 8);
    quest_download_header_name_index_hi_count = lbl_805D78FC = h[0x34] + (h[0x35] << 8);
    lbl_805D7820 = 0;
    return 0;
}
#pragma pop

void TQuestVmDownLoadServer::init_page_cache() {
    QuestDownloadCachePage *p;
    QuestDownloadCacheEntry *e;
    u32 i;
    file_page_cache_head = p = quest_download_slot_table.pages;
    for (; p < &quest_download_slot_table.pages[9]; p++) {
        p->pageIndex = -1;
        p->state = 0;
        p->next = p + 1;
    }
    p->pageIndex = -1;
    p->state = 0;
    p->next = NULL;
    e = quest_download_slot_table.entries;
    for (i = 0; i < 128; i++) {
        e[i].referenceCount = 0;
    }
}

s32 TQuestVmDownLoadServer::seek_or_reopen(int pos) {
    u8 unused[8];
    if (Seek_803E8624(quest_download_file_handle, pos, 0) == -1) {
        if (Open_803E8624() != 0) {
            return -1;
        }
        if (Seek_803E8624(quest_download_file_handle, pos, 0) == -1) {
            return -1;
        }
    }
    return 0;
}
#pragma pop

s32 TQuestVmDownLoadServer__sub_803E86C8(void) {
    if (aram_close(quest_download_file_handle) == -1) {
        quest_download_file_handle = -1;
        return -1;
    }
    quest_download_file_handle = -1;
    return 0;
}

s32 TQuestVmDownLoadServer::find_file_info_index() {
    s32 handle;
    handle = aram_open(quest_vm_download_server_file_info, lbl_805D78F8);
    if (handle == -1) {
        quest_download_file_handle = -1;
        return -1;
    }
    quest_download_file_handle = handle;
    return 0;
}


#pragma push
#pragma opt_common_subs off
void TQuestVmDownLoadServer::set_file_info_name(const char *filename) {
    strcpy(quest_vm_download_server_file_info, filename);
}
#pragma pop

s32 TQuestVmDownLoadServer__sub_803E8788(s32 handle, const void *src, s32 size) {
    return -1;
}

s32 TQuestVmDownLoadServer::aram_read_thunk(s32 handle, void *dst, s32 size) {
    return aram_dma_read(handle, dst, size);
}

void TQuestVmDownLoadServer::unescape_copy_string(u8 *dst, u8 *src, u8 *end) {
    while (src < end && *src > 0x38) {
        if (*src == 0xFF) {
            src++;
        } else {
            *dst++ = *src++;
        }
        *dst++ = *src++;
    }
    *dst = 0;
}

s32 TQuestVmDownLoadServer::count_entries_until_terminator(const u8 *p, const u8 *end) {
    s32 n = 0;
    while (p < end && *p > 0x38) {
        if (*p == 0xFF) {
            n += 1;
        } else {
            n += 2;
        }
        p += 2;
    }
    return n;
}

void TQuestVmDownLoadServer::copy_sjis_string(u8 *src, u8 *dst) {
    while (*src != 0) {
        u8 c = *src;
        s32 lead;
        if ((c >= 0x80 && c <= 0x9F) || (c >= 0xE0 && c <= 0xFC)) {
            lead = 1;
        } else {
            lead = 0;
        }
        if (lead) {
            *dst++ = *src++;
        } else {
            *dst++ = 0xFF;
        }
        *dst++ = *src++;
    }
}

s32 TQuestVmDownLoadServer::calc_sjis_string_width(u8 *text) {
    s32 n = 0;
    while (*text != 0) {
        u8 c = *text;
        s32 lead;
        if ((c >= 0x80 && c <= 0x9F) || (c >= 0xE0 && c <= 0xFC)) {
            lead = 1;
        } else {
            lead = 0;
        }
        if (lead) {
            text += 2;
        } else {
            text += 1;
        }
        n += 2;
    }
    return n;
}


__declspec(section ".rodata") const char ask_header_signature[] = "ASK Copyright (C) ACCESS CO.,LTD.";
}
