#include "pso/render/GinjaMaterialState.h"
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/WordSelectMessage.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowDD_803488A8.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD_WS_String.h"
#include "pso/ui/window/TWindowDD_WS_Word.h"
#include "pso/ui/window/TWindowDD_80341A08.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80228E98.h"
#include <string.h>
#include "pso/unk/TLobby.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowDD_80347F34.h"
#include "pso/ui/window/TWindowDD_80348100.h"
#include "pso/ui/window/TWindowDD_80348304.h"
#include "pso/ui/window/TWindowDD_8034AF68.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"
#include "pso/player/PlayerSlots.h"

struct O_80347940 { u8 pad[0x20]; s32 base; void *items[1]; };
struct E_803478DC { void *p; };
struct W_803478DC { u8 pad0[0x20]; s32 base; E_803478DC e[1]; };

struct M_80347758 { s16 n; s16 type; s16 a[8]; s32 f14; };

struct W_80347E04 { u8 pad0[0x20]; s32 cur; void *pages[(0x74 - 0x24) / 4]; void *f74[2]; };

struct E_80347CC8 { u8 pad[8]; f32 f8; u8 padc[4]; f32 f10; };

struct S_80347CC8 { u8 pad[0x38]; f32 f38; };

struct W_80347CC8 { u8 pad[0x70]; S_80347CC8 *f70; };

/* View of the word-select window for the child-window helpers below (child windows at +0x24). */
struct W_80347AD4 {
    u8 pad0[0x20];
    s32 depth;
    u8 *child[8];
};

struct W_80347C50 {
    u8 pad0[0x20];
    s32 depth;
    TWindowDD *child[8];
    u8 pad44[0x88 - 0x44];
    s32 entry_id;
    saddr list_id;
    u8 pad90[0xB0 - 0x90];
    s32 window_mode;
};

struct W_80347B70 {
    u8 pad0[0x20];
    s32 idx;
    u8 *tbl[0x1D];
    s32 state;
    s32 cur;
    u8 pad_a0[0x24];
    u8 sub[4];
};

extern "C" {
void append_word_select_token(s16, saddr, void *);
void TWindowDD__sub_8034740C(M_80347758 *entry, saddr window_dd, saddr pos);
void TWindowDD__sub_803474CC(M_80347758 *entry, s16 id, char *word, char *buf, s32 *pos);
saddr TWindowDD__sub_80348D88(void *p);
extern s32 TWindowDD__window_mode;
void TWindowDD__sub_80347474(M_80347758 *entry, s16 id, char *buf, s32 *pos);
extern const f32 lbl_805DFB54;
void TWindowDD__sub_80347FA0(saddr arg0, s32 arg1);
s32 TWindowDD__sub_80348DD8(void *, int);
void TWindowDD__sub_80347A4C(u8 *arg0, saddr arg1);
extern const f32 lbl_805DFB94;
void TWindowDD__sub_80347758(M_80347758 *src, M_80347758 *dst);
s32 TWindowDD__sub_803412A0(u32);
TWindowDD_WS_String *TWindowDD__sub_8034146C(f32 *pos, f32 *size, u32 str, s32 style, f32 width);
extern const saddr TWindowDD__data_805DFB50;
extern const f32 lbl_805DFB60;
extern const f32 lbl_805DFBDC;
extern const f32 lbl_805DFBE0;
extern const f32 lbl_805DFBE4;
extern const f32 lbl_805DFBE8;
extern const f32 lbl_805DFBEC;
extern const f32 lbl_805DFC28;
void TWindowDD__sub_80347E04(W_80347E04 *arg0, s32 arg1);
extern s32 local_client_id;
extern uaddr TWindowDD__work_buffer;
extern const f32 TWindowDD__data_805DFB58;
void TWindowDD__sub_80347CC8(W_80347CC8 *arg0, WordSelectMessage *message);
void TWindowDD__sub_80348D90(void *, int);
extern const f32 TWindowDD__data_805DFB6C;
extern const f32 TWindowDD__data_805DFB74;
s32 is_id_in_special_range__9TWindowDDFs(s16);
s32 TWindowDD__sub_80347238();
u8 TWindowDD__sub_80347858(s16 arg0);

s32 TWindowDD::classify_id(s16 id) {
    s32 var_r3;

    if (id == 0x2E4) {
        return 0;
    }
    if (TWindowDD__sub_80347238() != 0) {
        return 1;
    }
    if (is_id_in_special_range__9TWindowDDFs(id) != 0) {
        return 2;
    }
    if (id == 0x4F3) {
        return 3;
    }
    if (id == 0x635) {
        return 4;
    }
    var_r3 = 7;
    if (id == 0x650) {
        var_r3 = 5;
    }
    return var_r3;
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

void TWindowDD::format_type6_message(saddr window_dd, void *pos) {
    M_80347758 *arg0 = (M_80347758 *)this;
    s32 count;
    s32 n;
    s32 i;

    count = arg0->n;
    n = count;
    if (n > 3) {
        n = 3;
    }
    for (i = 0; i < n - 1; i++) {
        append_word_select_token(arg0->a[i], window_dd, pos);
        TWindowDD::show_message_by_count((char *)window_dd, (s32 *)pos);
    }
    append_word_select_token(arg0->a[n - 1], window_dd, pos);
    if (count > 3) {
        ((TWindowDD *)window_dd)->append_prompt_newline((s32 *)pos);
        append_word_select_token(arg0->a[3], window_dd, pos);
    }
}

void TWindowDD__sub_8034740C(M_80347758 *entry, saddr window_dd, saddr pos) {
    TWindowDD__sub_80347474(entry, entry->a[0], (char *)window_dd, (s32 *)pos);
    if (entry->n > 1) {
        ((TWindowDD *)window_dd)->append_prompt_newline((s32 *)pos);
        append_word_select_token(entry->a[1], window_dd, (void *) pos);
    }
}

void TWindowDD__sub_80347474(M_80347758 *entry, s16 id, char *buf, s32 *pos) {
    char *word = (char *)get_word_select_token_text(id);
    TWindowDD__sub_803474CC(entry, id, word, buf, pos);
}

void TWindowDD__sub_803474CC(M_80347758 *entry, s16 id, char *word, char *buf, s32 *pos) {
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
        value = TWindowDD__sub_80348D88(entry);
        limit = word_select_numeric_limits[kind];
        if (value > 0) {
            if (value > limit) {
                value = limit;
            }
            format_int_decimal(value, num);
            switch (kind) {
            case 0:
            case 5:
                if (kind == 5 && TWindowDD__window_mode == 2) {
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
                    if (TWindowDD__window_mode != 0) {
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

void TWindowDD__sub_80347758(M_80347758 *src, M_80347758 *dst) {
    s16 id;
    s16 n;
    n = src->n;
    if (n > 1) {
        id = src->a[1];
        if (TWindowDD_is_id_in_range_5AC_5F9(id) != 0) {
            dst->type = 4;
            if (n > 3) {
                dst->a[0] = src->a[3];
            } else if (n > 2 && src->a[2] == 0x685) {
                dst->a[0] = 0x698;
            } else {
                dst->a[0] = 0x2C4;
            }
            dst->a[1] = id;
            dst->a[2] = src->a[0];
            if (n > 2) {
                dst->a[3] = src->a[2];
                dst->n = 4;
            } else {
                dst->n = 3;
            }
        } else {
            s32 i;
            dst->type = 5;
            for (i = 0; i < n; i++) {
                dst->a[i] = src->a[i];
            }
            dst->n = src->n;
        }
    }
    dst->f14 = src->f14;
}

u8 TWindowDD__sub_80347858(s16 arg0) {
    s32 r = 0;
    if (arg0 >= 0x37 && arg0 <= 0x45) {
        r = 1;
    }
    return (u8)r;
}

s32 TWindowDD::is_state_zero_unless_0x2C8(s32 arg0) {
    if ((s16)arg0 == 0x2C8) {
        return 0;
    }
    return (u32) __cntlzw((u32) ((s32 (*)(void))TWindowDD__sub_80347858)()) >> 5;
}

s32 TWindowDD_is_id_in_range_5AC_5F9(s32 value) {
    u8 var_r3 = 0;
    if (static_cast<s16>(value) >= 0x5ac && static_cast<s16>(value) <= 0x5f9) {
        var_r3 = 1;
    }
    return var_r3;
}

void TWindowDD::destroy_menu_entry(s32 arg1) {
    W_803478DC *arg0 = (W_803478DC *)this;
    if (arg0->e[arg0->base + arg1].p != NULL) {
        ((TObject *)arg0->e[arg0->base + arg1].p)->queue_destruction();
        arg0->e[arg0->base + arg1].p = NULL;
    }
}

void TWindowDD::set_item_pos(s32 i) {
    O_80347940 *self = (O_80347940 *)this;
    void *p = self->items[self->base + i];
    if (p != NULL) {
        ((TWindowDD *)p)->set_pos_and_data(lbl_805DFB94);
    }
}

extern "C" {

TWindowDD *TWindowDD__sub_80347980(TWindowDD *self) {
    W_80347C50 *w = (W_80347C50 *)self;
    TWindowDD *child;
    if (w->depth > 0) {
        child = w->child[w->depth - 1];
        if (child != NULL) {
            self->update((saddr)child);
            w->entry_id = TWindowDD__sub_8034214C((u8 *)child);
        }
    }
    return child;
}
}

u8 *TWindowDD::init_last_child() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    u8 *var_r31;
    var_r31 = NULL;
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x20);
    if (temp_r0 > 0) {
        var_r31 = ((u8 **)(arg0 + 0x24))[temp_r0 - 1];
        if (var_r31 != NULL) {
            reinterpret_cast<TWindowDD_WS_Word *>(var_r31)->init_and_mark_field8C();
            ((TWindowDD *)var_r31)->set_pos_and_data(TWindowDD__data_805DFB6C);
            *(f32 *)((s8 *)var_r31 + 0x38) = (f32) TWindowDD__data_805DFB74;
        }
    }
    return var_r31;
}

void TWindowDD__sub_80347A4C(u8 *arg0, saddr window_dd) {
    s32 temp_r3;
    temp_r3 = TWindowDD__sub_80342158(reinterpret_cast<const TWindowDD_WS_Word *>(window_dd));
    if (TWindowDD::is_state_zero_unless_0x2C8(temp_r3) != 0) {
        TWindowDD__sub_80348DD8(arg0 + 0xC4, temp_r3);
        TWindowDD__sub_80347CC8((W_80347CC8 *)(arg0), reinterpret_cast<WordSelectMessage *>(arg0 + 0xC4));
        *(s32 *)((s8 *)arg0 + 0x98) = 1;
        *(s32 *)((s8 *)arg0 + 0x9C) = (s32) (s16) temp_r3;
        return;
    }
    TWindowDD__sub_80347FA0((saddr)arg0, 3);
    *(s32 *)((s8 *)arg0 + 0x98) = 0;
    *(s32 *)((s8 *)arg0 + 0x9C) = (s32) (s16) temp_r3;
}

u8 *TWindowDD__sub_80347AD4(W_80347AD4 *self, s32 offset, s32 id) {
    s32 i;
    u8 *win;

    i = self->depth + offset;
    if (i >= 8) {
        return NULL;
    }
    win = self->child[i];
    if (win == NULL) {
        win = (u8 *)TWindowDD__sub_80342384(id, (s32)lbl_805DFB54);
        TWindowDD::set_default_coords((saddr)self, (TWindowDD_WS_Word *)win);
        self->child[self->depth + offset] = win;
    }
    return win;
}

#pragma push
#pragma fp_contract on

struct W_80347CC8;
void TWindowDD::update_selection_state() {
    s32 v;
    W_80347B70 *arg0 = (W_80347B70 *)this;
    v = TWindowDD__sub_80342158(reinterpret_cast<TWindowDD_WS_Word *>(arg0->tbl[arg0->idx]));
    if ((s16)v != arg0->cur) {
        switch (arg0->state) {
        case 0:
            if (TWindowDD::is_state_zero_unless_0x2C8(v) != 0) {
                TWindowDD__sub_80348DD8(arg0->sub, v);
                arg0->state = 1;
            } else {
                TWindowDD__sub_80348D90(arg0->sub, v);
            }
            break;
        case 1:
            if (TWindowDD::is_state_zero_unless_0x2C8(v) != 0) {
                TWindowDD__sub_80348D90(arg0->sub, v);
            } else {
                ((TWindowDD *)(arg0->sub))->pop_entry();
                arg0->state = 0;
            }
            break;
        }
        TWindowDD__sub_80347CC8((W_80347CC8 *)arg0, reinterpret_cast<WordSelectMessage *>(arg0->sub));
        arg0->cur = (s16)v;
    }
}

void TWindowDD__sub_80347C50(W_80347C50 *self) {
    s32 next;

    next = dispatch_by_window_mode(reinterpret_cast<TWindowDD *>(self), self->window_mode, self->entry_id,
                                                                   self->child[self->depth]->get_field_68());
    if (next != self->list_id) {
        self->list_id = next;
        reinterpret_cast<TWindowDD_WS_Word *>(self->child[self->depth + 1])->init_child(self->list_id);
    }
}

void TWindowDD__sub_80347CC8(W_80347CC8 *arg0, WordSelectMessage *message) {
    S_80347CC8 *s;
    E_80347CC8 *e;
    f32 x;
    f32 c;
    f32 max;
    f32 f10;
    TWindowDD::format_message(message, reinterpret_cast<char *>(TWindowDD__work_buffer), local_client_id);
    s = arg0->f70;
    if (s != NULL) {
        e = (E_80347CC8 *)((TWindowBase *)s)->get_array_entry(0);
        if (e != NULL) {
            measure_message_text_width_default(e);
            x = 10.0f + e->f10;
            if (x >= 580.0f) {
                e->f8 = 580.0f - e->f10;
                x = 580.0f;
            } else {
                e->f8 = 0.0f;
            }
            s->f38 = 2.0f * TWindowDD__data_805DFB58 + x;
            if (x <= 0.0f) {
                ((TWindowDD_WS_String *)s)->update_position(TWindowDD__data_805DFB50);
            } else {
                ((TWindowDD_WS_String *)s)->init_and_set_field50((void *)TWindowDD__data_805DFB50);
            }
        }
    }
}

s32 TWindowDD::setup_entry(s16 id) {
    s32 var_r31;
    uaddr temp_r30;

    s32 str;
    var_r31 = 0;
    temp_r30 = this->m_64[2];
    if ((temp_r30 != 0U) && ((str = get_word_select_token_text(id)) != 0)) {
        ((TWindowDD_WS_String *)temp_r30)->set_first_entry_text(str);
        TWindowDD__sub_803412A0(temp_r30);
        ((TWindowDD_WS_String *)temp_r30)->init_and_set_field50((void *)TWindowDD__data_805DFB50);
        var_r31 = 1;
    }
    return var_r31;
}

void TWindowDD__sub_80347E04(W_80347E04 *arg0, s32 arg1) {
    NJS_POINT2 v;
    NJS_POINT2 a;
    NJS_POINT2 b;
    u32 r;
    u8 *o;
    static_cast<TWindowDD_WS_Word *>(arg0->pages[arg0->cur])->get_cursor_pos(&v);
    r = ((TWindowDD *)(arg0->pages[arg0->cur]))->update_if_field28_set();
    if (r != 0) {
        if (arg1 == 0) {
            a.x = lbl_805DFBDC;
            a.y = lbl_805DFBE0;
        } else {
            a.x = lbl_805DFBE8;
            a.y = lbl_805DFBEC;
        }
        b.x = lbl_805DFB60;
        b.y = a.y;
        o = (u8 *)TWindowDD__sub_8034146C((f32 *)&a, (f32 *)&b, (u32)r, (s32)(1), (f32)((f32)lbl_805DFBE4));
        if (o != NULL) {
            ((TWindowBase *)o)->set_depth(lbl_805DFC28);
            TWindowDD__sub_803412A0((uaddr)o);
            copy_vec2((o + 0x40), &v);
            ((TWindowDD_WS_String *)o)->init_and_set_field50((void *)TWindowDD__data_805DFB50);
            arg0->f74[arg1] = o;
        }
    }
}

s32 TWindowDD::get_current_child_index() {
    u8 *arg0 = (u8 *)this;
    u8 *var_r3;
    var_r3 = (u8 *)(arg0 + (*(s32 *)((s8 *)arg0 + 0x20) * 4));
    var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 0x24));
    if (var_r3 != NULL) {
        return TWindowDD__sub_80342158(reinterpret_cast<TWindowDD_WS_Word *>(var_r3));
    }
    var_r3 = (u8 *)((void *)-1U);
    return -1;
}

}
#pragma pop


extern const f32 TWindowDD__data_805DFC10;

    extern unsigned char lbl_804EFCA8[];
void *TWindowDD::get_entry(void *window, int index) {  return (char*)lbl_804EFCA8 + index * 8; }

void TWindowDD__sub_80347F48(u8 *window_dd) {
    u8 *temp_r3;
    temp_r3 = (u8 *)(*(u8 **)((s8 *)window_dd + 0x68));
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)temp_r3 + 0x30) = (f32) TWindowDD__data_805DFC10;
        *(s32 *)((s8 *)temp_r3 + 0x50) = (s32) TWindowDD__data_805DFB50;
    }
}

void TWindowDD::init_entry_field_64(s32 arg1) {
    saddr arg0 = (saddr)this;
    u8 *var_r3;
    var_r3 = (u8 *)(arg0 + (arg1 * 4));
    var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 0x64));
    if (var_r3 != NULL) {
        ((TWindowDD_WS_String *)var_r3)->init_and_set_field50((void *)TWindowDD__data_805DFB50);
    }
}

void TWindowDD__sub_80347FA0(saddr window_dd, s32 arg1) {
    u8 *var_r3;
    var_r3 = (u8 *)(window_dd + (arg1 * 4));
    var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 0x64));
    if (var_r3 != NULL) {
        ((TWindowDD_WS_String *)var_r3)->update_position(TWindowDD__data_805DFB50);
    }
}

void TWindowDD::refresh_sub(void* p, void* a1) { TWindowDD__sub_80341AE0((u8 *)a1); ((TWindowDD *)a1)->set_mode_2(); }

void TWindowDD::apply_input(void* p, void* a1) { TWindowDD__sub_80341AE0((u8 *)a1); ((TWindowDD *)a1)->reset_cursor(); }

void TWindowDD::update(void* p, void* child) { TWindowDD__sub_80341AE0((u8 *)child); ((TWindowDD *)child)->set_mode_2(); }


void TWindowDD::update(saddr window_dd) {
    TWindowDD__sub_80341AF8((u8 *)window_dd);
    ((TWindowDD *)window_dd)->reset_cursor();
    if ((u32) this->m_7c != 0U) {
        ((TWindowDD *)(this->m_7c))->set_scale(((TWindowDD *)window_dd)->get_field_0x74(), (s32) lbl_805DFB54);
        ((TWindowDD *)(this->m_7c))->set_value_f32(TWindowDD__sub_8034217C((u8 *)window_dd));
    }
}

extern "C" {
int play_sound_effect(void*, void*, void*, void*);
int refresh_sub__9TWindowDDFPvPv(void);
int update__9TWindowDDFPvPv(void);
int update__9TWindowDDFl(void);

        extern const float lbl_805DFB98;
    extern const float lbl_805DFB9C;
    extern const float lbl_805DFBA0;
void TWindowDD::set_default_coords(int a0, TWindowDD_WS_Word *win) {
    refresh_sub__9TWindowDDFPvPv();
    win->target_position[0] = lbl_805DFB94;
    win->frame_position[0] = lbl_805DFB94;
    win->target_position[1] = lbl_805DFB98;
    win->frame_position[1] = lbl_805DFB98;
    win->target_size[0] = lbl_805DFB9C;
    win->frame_size[0] = lbl_805DFB9C;
    win->target_size[1] = lbl_805DFBA0;
    win->frame_size[1] = lbl_805DFBA0;
}

    extern const float lbl_805DFB80;
    extern const float lbl_805DFB84;
    extern const float lbl_805DFB88;
    extern const float lbl_805DFB8C;
void TWindowDD::init_layout(void *window, TWindowDD_WS_Word *child) {
    update__9TWindowDDFPvPv();
    child->target_position[0] = lbl_805DFB80;
    child->frame_position[0] = lbl_805DFB80;
    child->target_position[1] = lbl_805DFB84;
    child->frame_position[1] = lbl_805DFB84;
    child->target_size[0] = lbl_805DFB88;
    child->frame_size[0] = lbl_805DFB88;
    child->target_size[1] = lbl_805DFB8C;
    child->frame_size[1] = lbl_805DFB8C;
}

        extern const float lbl_805DFB70;
        extern const float lbl_805DFB78;
void TWindowDD::set_default_positions(void *window, TWindowDD_WS_Word *child) {
    update__9TWindowDDFl();
    child->target_position[0] = TWindowDD__data_805DFB6C;
    child->frame_position[0] = TWindowDD__data_805DFB6C;
    child->target_position[1] = lbl_805DFB70;
    child->frame_position[1] = lbl_805DFB70;
    child->target_size[0] = TWindowDD__data_805DFB74;
    child->frame_size[0] = TWindowDD__data_805DFB74;
    child->target_size[1] = lbl_805DFB78;
    child->frame_size[1] = lbl_805DFB78;
}

void TWindowDD::spawn_window() { play_sound_effect((void*)344320, (void*)0, (void*)0, (void*)0); }
void TWindowDD::play_se() { play_sound_effect((void*)339734, (void*)0, (void*)0, (void*)0); }
void TWindowDD::play_sound() { play_sound_effect((void*)339201, (void*)0, (void*)0, (void*)0); }
u8 TWindowDD__sub_803482B0(u8 *window_dd) {
    s32 var_r31;
    var_r31 = 0;
    if ((((s32)TWindowDD_check_input_mask(window_dd + 0x1C, 2)) != 0) || (*(s32 *)((s8 *)window_dd + 0x94) & 2)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

}


struct W_80348520 {
    u8 pad0[0x24];
    void *b[8];
    u8 pad44[0x64 - 0x44];
    void *a[6];
    void *f7c;
    void *f80;
    void *f84;
};

extern "C" {
s32 copy_chat_entry__9TWindowDDFPvPv(int, void *);
s32 reset_selection__9TWindowDDFv(void *, void *);

int TWindowDD::test_input_flag_4() { return TWindowDD_check_input_mask((char*)this + 0x1c, 4); }

extern s32 TWindowDD__window_mode;

s32 dispatch_by_window_mode(TWindowDD *window, u32 window_mode, s32 entry_id, s32 value_index) {
    switch ((s32) TWindowDD__window_mode) {
    case 0:
        return TWindowDD__sub_80346640(window, window_mode, entry_id, value_index);
    default:
        return TWindowDD__sub_80346434(window, window_mode, entry_id, value_index);
    case 4:
        return TWindowDD__sub_80344774(window, window_mode, entry_id, value_index);
    case 2:
        return TWindowDD__sub_80344568(window, window_mode, entry_id, value_index);
    case 3:
        return TWindowDD__sub_8034435C(window, window_mode, entry_id, value_index);
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
    if (TLobby::is_flag_set() != 0) {
        return 5;
    }
    return (this->m_a0 != 0 ? 1 : 0) + 2;
}

int TWindowDD__sub_80348424(s32 _w0, s32 _w1) { return TWindowDD__sub_8034B008((saddr)((void*)(1)), (_w1)); }

void TWindowDD__sub_80348448(s32 arg0, s16 id) {
    TWindowDD__sub_8034B008(0, ((s32) id));
}

s32 TWindowDD::get_mode_code() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;
    temp_r3 = *(s32 *)((s8 *)arg0 + 0xA8);
    if (temp_r3 == 2) {
        return 1;
    }
    return ((temp_r3 - 3) == 0) ? 2 : 0;
}

void TWindowDD::set_state() { *(int*)((char*)this + 0xa8) = 3; close_all_windows(); }

void TWindowDD__sub_803484C4(u8 *window_dd) {
    *(s32 *)((s8 *)window_dd + 0xA8) = 2;
    copy_chat_entry__9TWindowDDFPvPv((int) (*(s32 *)((s8 *)window_dd + 0xC0)), window_dd + 0xC4);
    if ((s32) ((TWindowDD *)window_dd)->m_a4 != 0) {
        reset_selection__9TWindowDDFv(window_dd, window_dd + 0xC4);
    }
    ((TWindowDD *)window_dd)->close_all_windows();
}

void TWindowDD::close_all_windows() {
    W_80348520 *w = (W_80348520 *)this;
    s32 i;
    if (w->f84 != NULL) {
        ((TWindowBase *)w->f84)->close();
        w->f84 = NULL;
    }
    if (w->f80 != NULL) {
        ((TWindowBase *)w->f80)->close();
        w->f80 = NULL;
    }
    if (w->f7c != NULL) {
        ((TWindowBase *)w->f7c)->close();
        w->f7c = NULL;
    }
    for (i = 0; i < 6; i++) {
        if (w->a[i] != NULL) {
            ((TWindowBase *)(w->a[i]))->close();
            w->a[i] = NULL;
        }
    }
    for (i = 7; i >= 0; i--) {
        if (w->b[i] != NULL) {
            ((TWindowBase *)(w->b[i]))->close();
            w->b[i] = NULL;
        }
    }
}

s32 TWindowDD::can_append_chars(s32 arg0, s32 *pos) {
    s32 t = *pos;
    return (arg0 + t + 1) < 0x80;
}

void TWindowDD::format_message(WordSelectMessage *message, char *text, u16 player) {
    switch ((s32) TWindowDD__window_mode) {
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
    u8 *arg0 = (u8 *)this;
    s32 p = *pos;
    if (((s32)TWindowDD::can_append_chars(3, pos)) != 0) {
        arg0[p++] = 0xA;
        arg0[p++] = 0x3E;
        arg0[p++] = 0x20;
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

}


extern "C" {

s32 count_chars_since_newline__9TWindowDDFPl();

void TWindowDD::show_message_by_count(char *buf, s32 *pos) {
    if (count_chars_since_newline__9TWindowDDFPl() > 0xF) {
        TWindowDD::append_char(0xA, buf, pos);
        return;
    }
    TWindowDD::append_char(0x20, buf, pos);
}

}


extern "C" {
void TWindowDD::maybe_scroll(void* a1) { if (count_chars_since_newline((s32 *)a1) > 15) { TWindowDD::append_char(10, (char *)this, (s32 *)a1); } }

s32 TWindowDD::count_chars_since_newline(s32 *len) {
    u8 *buf = (u8 *)this;
    s32 n = 0;
    s32 i;
    for (i = *len - 1; i >= 0; i--) {
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

void append_word_select_token(s16 id, saddr window_dd, void *pos) {
    TWindowDD::append_string((const char *)get_word_select_token_text(id), (char *)window_dd, (s32 *)pos);
}

}


struct Dst_80348A9C { u8 pad[0xc]; f32 x; f32 y; u8 pad2[4]; };

extern "C" {
extern f32 lbl_805DFB1C;
WindowTexturePoint TWindowDD__data_805434E8[7][8];
extern s32 *TWindowDD__player_name_buffers;
extern s32 *TWindowDD__data_805D6E28;
extern s16 *lbl_805D6E34;
extern const f32 TWindowDD__data_805DFB58;
extern const f32 lbl_805DFB5C;
extern const f32 TWindowDD__data_805DFB20;
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
    ((TWindowDD *)(&sp8))->reset_entries(TWindowDD__sub_80348AD4(draw_depth, offset), -1);
    ((TWindowDD *)(&sp8))->copy_point_table(idx);
    TWindowDD__sub_80348A2C(reinterpret_cast<WindowDrawContext *>(ctx), reinterpret_cast<WindowVertex *>(&sp8));
    TWindowDD__sub_803489B8(reinterpret_cast<WindowDrawContext *>(ctx), reinterpret_cast<WindowVertex *>(&sp8), 0);
    ((TWindowDD *)(&sp8))->draw_transformed_primitive(8, draw_count, 1);
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
    step = TWindowDD__data_805DFB20 * sc;
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
  f32 temp_f0;
  f32 temp_f0_2;
  f32 temp_f1;
  f32 temp_f1_2;
  s8 *new_var2;
  f32 temp_f2;
  f32 x;
  f32 temp_f4;
  s8 *new_var;
  f32 var_f0;
  temp_f2 = 0.5f * context->w;
  temp_f1 = temp_f2 * context->scale[0];
  temp_f0 = context->x + temp_f2;
  x = (0, temp_f0 - temp_f1);
  temp_f4 = temp_f0 + temp_f1;
  if (temp_f1 < lbl_805DFB1C)
  {
    var_f0 = (temp_f4 - x) / 3.0f;
  }
  else
  {
    var_f0 = lbl_805DFB1C;
  }
  new_var2 = ((s8 *) ((0, vertices))) + 0x90;
  *((f32 *) (((s8 *) vertices) + 0x18)) = x;
  temp_f1_2 = x + var_f0;
  temp_f0_2 = temp_f4 - var_f0;
  vertices->x = x;
  *((f32 *) (((s8 *) vertices) + 0x48)) = temp_f1_2;
  *((f32 *) (((s8 *) vertices) + 0x30)) = temp_f1_2;
  new_var = (s8 *) vertices;
  *((f32 *) (((s8 *) vertices) + 0x78)) = temp_f0_2;
  *((f32 *) (((s8 *) vertices) + 0x60)) = temp_f0_2;
  *((f32 *)(new_var + 0xA8)) = temp_f4;
  *((f32 *) new_var2) = temp_f4;
}

void TWindowDD::copy_point_table(s32 idx) {
    Dst_80348A9C *self = (Dst_80348A9C *)this;
    s32 i;
    const WindowTexturePoint *s = TWindowDD__data_805434E8[idx];
    for (i = 0; i < 8; i++) {
        self->x = s->x;
        self->y = s->y;
        s++;
        self++;
    }
}

#pragma push
#pragma fp_contract on
f32 TWindowDD__sub_80348AD4(f32 draw_depth, f32 offset) {
    return (-1.0f) / ((0.299f * offset) + draw_depth);
}
#pragma pop

s32 TWindowDD::get_draw_count(const NJS_TEXLIST *textures) {
    return textures->textures[2].texture->surface->id;
}

extern s32 twindowdd_entry_count;

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
    ky = lbl_805DFB5C;
    x0 = x + TWindowDD__data_805DFB58;
    w = frame_size[0];
    h = frame_size[1];
    y0 = y + ky;
    context->inner_x = x0;
    context->inner_y = y0;
    context->inner_w = w - 2.0f * TWindowDD__data_805DFB58;
    context->inner_h = h - 2.0f * ky;
    context->clip_x0 = x0;
    context->clip_y0 = y0;
    context->clip_x1 = (x + w) - TWindowDD__data_805DFB58;
    context->clip_y1 = (y + h) - ky;
    context->pivot[0] = 0.5f * w + x;
    context->pivot[1] = 0.5f * h + y;
}
#pragma pop

saddr get_word_select_token_text(s16 id) {
    s32 *t = TWindowDD__player_name_buffers;
    if (id >= 0x68C && id <= 0x697) {
        return t[id - 0x68C];
    }
    if (id == 0x698) {
        return 0;
    }
    return TWindowDD__data_805D6E28[lbl_805D6E34[id]];
}

saddr TWindowDD::get_entry(s32 arg0) {
    if ((arg0 < 0) || (arg0 >= (s32) twindowdd_entry_count)) {
        return 0;
    }
    return reinterpret_cast<saddr>(&TWindowDD__ws_data_table[arg0]);
}

}
