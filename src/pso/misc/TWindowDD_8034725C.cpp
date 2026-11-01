#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowBase.h"

#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80228E98.h"
#include <string.h>
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"

struct O_80347940 { u8 pad[0x20]; s32 base; void *items[1]; };
struct E_803478DC { void *p; };
struct W_803478DC { u8 pad0[0x20]; s32 base; E_803478DC e[1]; };

struct M_80347758 { s16 n; s16 type; s16 a[8]; s32 f14; };

struct V2_80347E04 { f32 x, y; };

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
    s32 f88;
    s32 f8C;
    u8 pad90[0xB0 - 0x90];
    s32 fB0;
};

/* TWindowDD::dispatch_state forwards its four arguments to the formatter and returns its result;
   the header declares it static void(). */
typedef s32 (*DispatchStateFn_80347C50)(void *, s32, s32, s32);

struct W_80347B70 {
    u8 pad0[0x20];
    s32 idx;
    void *tbl[0x1D];
    s32 state;
    s32 cur;
    u8 pad_a0[0x24];
    u8 sub[4];
};

extern "C" {
void show_message_by_count__9TWindowDDFll(s32, void *);
void TWindowDD__sub_8034886C(s32, s32, void *);
void TWindowDD__sub_8034740C(u8 *arg0, s32 arg1, s32 arg2);
void TWindowDD__sub_803474CC(M_80347758 *entry, s16 id, char *word, s32 buf, s32 *pos);
s32 TWindowDD__sub_80348D88(M_80347758 *entry);
extern const s32 word_select_numeric_limits[];
extern const char lbl_804786A0[];
extern s32 TWindowDD__window_mode;
s32 TWindowDD__sub_80348B70(s32);
void TWindowDD__sub_80347474(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern const f32 lbl_805DFB54;
s32 TWindowDD__sub_80342384(s32 arg0, s32 arg1);
s32 TWindowDD__sub_80342158(void *);
void TWindowDD__sub_80347FA0(s32 arg0, s32 arg1);
s32 TWindowDD__sub_80348DD8(void *, int);
void TWindowDD__sub_80347A4C(u8 *arg0, s32 arg1);
extern const f32 lbl_805DFB94;
s32 TWindowDD_is_id_in_range_5AC_5F9(s16 arg0);
void TWindowDD__sub_80347758(M_80347758 *src, M_80347758 *dst);
s32 TWindowDD__sub_803412A0(u32);
s32 TWindowDD__sub_8034146C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 farg0);
extern s32 TWindowDD__data_805DFB50;
extern const f32 lbl_805DFB60;
extern const f32 lbl_805DFBDC;
extern const f32 lbl_805DFBE0;
extern const f32 lbl_805DFBE4;
extern const f32 lbl_805DFBE8;
extern const f32 lbl_805DFBEC;
extern const f32 lbl_805DFC28;
void TWindowDD__sub_80347E04(W_80347E04 *arg0, s32 arg1);
s32 update_state__9TWindowDDFv(void *, u32, u16);
E_80347CC8 *get_array_entry__11TWindowBaseFi(void *, s32);
s32 refresh_status_display__9TWindowDDFv(void *);
extern s32 local_client_id;
extern u32 TWindowDD__work_buffer;
extern const f32 TWindowDD__data_805DFB58;
extern const f32 lbl_805DFCD0;
extern const f32 lbl_805DFCD4;
void TWindowDD__sub_80347CC8(W_80347CC8 *arg0, void *arg1);
void TWindowDD__sub_80348D90(void *, int);
extern const f32 TWindowDD__data_805DFB6C;
extern const f32 TWindowDD__data_805DFB74;
void *get_player_by_client_id(s32 i);
s32 is_id_in_special_range__9TWindowDDFs(s16);
s32 TWindowDD__sub_80347238();
u8 TWindowDD__sub_80347858(s16 arg0);
void queue_destruction__7TObjectFv(void *);

s32 TWindowDD::classify_id(s16 arg0) {
    s32 var_r3;

    if (arg0 == 0x2E4) {
        return 0;
    }
    if (TWindowDD__sub_80347238() != 0) {
        return 1;
    }
    if (is_id_in_special_range__9TWindowDDFs(arg0) != 0) {
        return 2;
    }
    if (arg0 == 0x4F3) {
        return 3;
    }
    if (arg0 == 0x635) {
        return 4;
    }
    var_r3 = 7;
    if (arg0 == 0x650) {
        var_r3 = 5;
    }
    return var_r3;
}

s32 TWindowDD::get_player_battle_flag_state(u16 arg0) {
    s32 temp_r3_2;
    void *player;

    player = get_player_by_client_id((u16) arg0);
    if (player != NULL) {
        temp_r3_2 = ((TObjPlayer *)player)->class_flags;
        if (temp_r3_2 & CLASS_FLAG_MALE) {
            return 0;
        }
        if (temp_r3_2 & CLASS_FLAG_FEMALE) {
            return 2;
        }
        goto block_5;
    }
block_5:
    return 0;
}

void TWindowDD::format_type6_message(s32 arg1, void *pos) {
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
        TWindowDD__sub_8034886C(arg0->a[i], arg1, pos);
        show_message_by_count__9TWindowDDFll(arg1, pos);
    }
    TWindowDD__sub_8034886C(arg0->a[n - 1], arg1, pos);
    if (count > 3) {
        ((TWindowDD *)arg1)->append_prompt_newline((s32 *)pos);
        TWindowDD__sub_8034886C(arg0->a[3], arg1, pos);
    }
}

void TWindowDD__sub_8034740C(u8 *arg0, s32 arg1, s32 pos) {
    TWindowDD__sub_80347474((s32)((s32) arg0), (s32)((s32) *(s16 *)((s8 *)arg0 + 4)), arg1, pos);
    if ((s16) *(s16 *)((s8 *)arg0 + 0) > 1) {
        ((TWindowDD *)arg1)->append_prompt_newline((s32 *)pos);
        TWindowDD__sub_8034886C((s32) *(s16 *)((s8 *)arg0 + 6), arg1, (void *) pos);
    }
}

void TWindowDD__sub_80347474(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
  s32 temp_r0;
  s32 var_r28;
  s32 var_r29;
  s32 var_r30;
  s32 var_r31;
  int var_r3;
  s32 var_r4;
  s32 var_r5;
  s32 var_r6;
  s32 pos;
  var_r29 = arg1;
  var_r28 = arg0;
  var_r30 = arg2;
  var_r31 = arg3;
  var_r3 = var_r29;
  var_r6 = TWindowDD__sub_80348B70((s32)((int) var_r3));
  temp_r0 = var_r6;
  var_r3 = var_r28;
  var_r5 = temp_r0;
  var_r4 = var_r29;
  var_r6 = var_r30;
  pos = var_r31;
  var_r30 = (int) var_r4;
  void TWindowDD__sub_803474CC(M_80347758 *, s32, char *, s32, s32 *);
  TWindowDD__sub_803474CC((M_80347758 *)var_r3, var_r30, (char *)var_r5, var_r6, (s32 *)pos);
}

void TWindowDD__sub_803474CC(M_80347758 *entry, s16 id, char *word, s32 buf, s32 *pos) {
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
            fn_80228E98(value, num);
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
                        strncpy((char *)(buf + *pos), word, split);
                        *pos += split;
                    }
                    TWindowDD::append_string((s32)num, buf, pos);
                    TWindowDD::show_message_by_count(buf, (s32)pos);
                    len -= split;
                    if (len > 0) {
                        strncpy((char *)(buf + *pos), word + split, len);
                        *pos += len;
                    }
                } else {
                    TWindowDD::append_string((s32)num, buf, pos);
                    if (TWindowDD__window_mode != 0) {
                        TWindowDD::append_char(' ', buf, pos);
                    }
                    TWindowDD::append_string((s32)word, buf, pos);
                }
                break;
            case 1:
                TWindowDD::append_string((s32)word, buf, pos);
                TWindowDD::append_char('+', buf, pos);
                TWindowDD::append_string((s32)num, buf, pos);
                break;
            case 2:
                TWindowDD::append_string((s32)word, buf, pos);
                TWindowDD::append_string((s32)lbl_804786A0, buf, pos);
                TWindowDD::append_string((s32)num, buf, pos);
                break;
            case 3:
            case 4:
                TWindowDD::append_string((s32)word, buf, pos);
                TWindowDD::append_string((s32)num, buf, pos);
                break;
            }
            return;
        }
    }
    TWindowDD::append_string((s32)word, buf, pos);
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

s32 TWindowDD::is_state_zero_unless_0x2C8(s32 arg0) {
    if ((s16)arg0 == 0x2C8) {
        return 0;
    }
    return (u32) __cntlzw((u32) ((s32 (*)(void))TWindowDD__sub_80347858)()) >> 5;
}

u8 TWindowDD__sub_80347858(s16 arg0) {
    s32 r = 0;
    if (arg0 >= 0x37 && arg0 <= 0x45) {
        r = 1;
    }
    return (u8)r;
}

s32 TWindowDD_is_id_in_range_5AC_5F9(s16 arg0) {
    u8 var_r3;
    var_r3 = 0;
    if ((arg0 >= 0x5ac) && (arg0 <= 0x5f9)) {
        var_r3 = 1;
    }
    return var_r3;
}

void TWindowDD::destroy_menu_entry(s32 arg1) {
    W_803478DC *arg0 = (W_803478DC *)this;
    if (arg0->e[arg0->base + arg1].p != NULL) {
        queue_destruction__7TObjectFv(arg0->e[arg0->base + arg1].p);
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
s16 TWindowDD__sub_8034214C(u8 *arg0);

TWindowDD *TWindowDD__sub_80347980(TWindowDD *self) {
    W_80347C50 *w = (W_80347C50 *)self;
    TWindowDD *child;
    if (w->depth > 0) {
        child = w->child[w->depth - 1];
        if (child != NULL) {
            self->update((s32)child);
            w->f88 = TWindowDD__sub_8034214C((u8 *)child);
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
            ((TWindowDD *)var_r31)->init_and_mark_field8C();
            ((TWindowDD *)var_r31)->set_pos_and_data(TWindowDD__data_805DFB6C);
            *(f32 *)((s8 *)var_r31 + 0x38) = (f32) TWindowDD__data_805DFB74;
        }
    }
    return var_r31;
}

void TWindowDD__sub_80347A4C(u8 *arg0, s32 arg1) {
    s32 temp_r3;
    temp_r3 = TWindowDD__sub_80342158((void *)arg1);
    if (TWindowDD::is_state_zero_unless_0x2C8(temp_r3) != 0) {
        TWindowDD__sub_80348DD8(arg0 + 0xC4, temp_r3);
        TWindowDD__sub_80347CC8((W_80347CC8 *)(arg0), arg0 + 0xC4);
        *(s32 *)((s8 *)arg0 + 0x98) = 1;
        *(s32 *)((s8 *)arg0 + 0x9C) = (s32) (s16) temp_r3;
        return;
    }
    TWindowDD__sub_80347FA0((s32)arg0, 3);
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
        TWindowDD::set_default_coords((int)self, win);
        self->child[self->depth + offset] = win;
    }
    return win;
}

#pragma fp_contract on

struct W_80347CC8;
void TWindowDD::update_selection_state() {
    s32 v;
    W_80347B70 *arg0 = (W_80347B70 *)this;
    v = TWindowDD__sub_80342158(arg0->tbl[arg0->idx]);
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
        TWindowDD__sub_80347CC8((W_80347CC8 *)arg0, arg0->sub);
        arg0->cur = (s16)v;
    }
}

void TWindowDD__sub_80347C50(W_80347C50 *self) {
    s32 next;

    next = ((DispatchStateFn_80347C50)TWindowDD::dispatch_state)(self, self->fB0, self->f88,
                                                                   self->child[self->depth]->get_field_68());
    if (next != self->f8C) {
        self->f8C = next;
        self->child[self->depth + 1]->init_child((void *)self->f8C);
    }
}

void TWindowDD__sub_80347CC8(W_80347CC8 *arg0, void *window_dd) {
    S_80347CC8 *s;
    E_80347CC8 *e;
    f32 x;
    f32 c;
    f32 max;
    f32 f10;
    update_state__9TWindowDDFv(window_dd, TWindowDD__work_buffer, local_client_id);
    s = arg0->f70;
    if (s != NULL) {
        e = get_array_entry__11TWindowBaseFi(s, 0);
        if (e != NULL) {
            refresh_status_display__9TWindowDDFv(e);
            x = 10.0f + e->f10;
            if (x >= 580.0f) {
                e->f8 = 580.0f - e->f10;
                x = 580.0f;
            } else {
                e->f8 = lbl_805DFCD0;
            }
            s->f38 = lbl_805DFCD4 * TWindowDD__data_805DFB58 + x;
            if (x <= lbl_805DFCD0) {
                ((TWindowDD *)s)->update_position(TWindowDD__data_805DFB50);
            } else {
                ((TWindowDD *)s)->init_and_set_field50((void *)TWindowDD__data_805DFB50);
            }
        }
    }
}

s32 TWindowDD::setup_entry(s32 arg1) {
    s32 var_r31;
    u32 temp_r30;

    s32 str;
    var_r31 = 0;
    temp_r30 = this->m_88;
    if ((temp_r30 != 0U) && ((str = TWindowDD__sub_80348B70(arg1)) != 0)) {
        ((TWindowDD *)temp_r30)->set_first_entry_text(str);
        TWindowDD__sub_803412A0(temp_r30);
        ((TWindowDD *)temp_r30)->init_and_set_field50((void *)TWindowDD__data_805DFB50);
        var_r31 = 1;
    }
    return var_r31;
}

void TWindowDD__sub_80347E04(W_80347E04 *arg0, s32 arg1) {
    V2_80347E04 v;
    V2_80347E04 a;
    V2_80347E04 b;
    u32 r;
    u8 *o;
    ((TWindowDD *)(arg0->pages[arg0->cur]))->get_cursor_pos((u8 *)&v);
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
        o = (u8 *)TWindowDD__sub_8034146C((s32)&a, (s32)&b, (s32)r, 1, (f32)lbl_805DFBE4);
        if (o != NULL) {
            ((TWindowBase *)o)->set_depth(lbl_805DFC28);
            TWindowDD__sub_803412A0((u32)o);
            ((TWindowSubSymbolChatPartsSet *)(o + 0x40))->copy_vec2(&v);
            ((TWindowDD *)o)->init_and_set_field50((void *)TWindowDD__data_805DFB50);
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
        return TWindowDD__sub_80342158(var_r3);
    }
    var_r3 = (u8 *)((void *)-1U);
    return -1;
}

}
