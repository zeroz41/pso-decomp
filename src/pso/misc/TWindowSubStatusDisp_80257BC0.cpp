#include "types.h"
#include "pso/misc/TUnk_804CF930.h"
#include "pso/misc/TWindowSubStatusDisp_80256B94.h"
#include "pso/misc/TWindowSubStatusDisp_80257BC0.h"
#include "pso/system/memory.h"
#include "pso/misc/TUnk_804CE018.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TTecRaFoie.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdChrMoveEffectGC.h"

struct Bar_80256C00 {
    u8 pad0[0x14];
    f32 scale;
    u8 pad1[4];
    f32 width;
    f32 max;
    f32 target;
};

struct Gauge_802571B4 {
    u16 flags;
    u8 pad2[0x12];
    f32 scale;
    u8 pad18[4];
    f32 cur;
    f32 max;
    f32 val;
};

struct Gauge_80256E0C { u8 p0[0x14]; f32 max; };

struct Pos_80256E0C { f32 x; f32 y; };

extern "C" {
void sub_80256BDC__13TUnk_804CF930Fs(u8 *arg0, s16 arg1);
void calc_bar_width__20TWindowSubStatusDispFPv(struct Bar_80256C00 *bar);
extern const f32 lbl_805DCE58;
void step_gauge_bar_width(Gauge_802571B4 *g);
void draw_status_gauge_bar__13TUnk_804CF930FPvPvff(Gauge_80256E0C *self, void *ctx, Pos_80256E0C *pos, f32 depth, f32 len);
void *destroy__13TUnk_804CF930Fs(void *arg0, s16 arg1);

#define draw_status_gauge_bar__13TUnk_804CF930FPvPvff ((s32 (*)(void *, void *, void *, f32, f32))draw_status_gauge_bar__13TUnk_804CF930FPvPvff)
struct RecoveredGlobal_80257B4C_lbl_804CF948 {
    s32 value;
    u8 remaining[0x14];
};

struct Base_80257BC0 { u16 flags; u8 pad[2]; };

struct Item_80257BC0 : Base_80257BC0 {
    virtual void m0();
    virtual void m1();
    virtual void draw(void *ctx);
};

struct List_80257BC0 { u32 count; Item_80257BC0 **items; };

struct Base_80257C28 { u32 x0; };

struct Ent_80257C28 : Base_80257C28 { virtual void m0(); virtual void m1(); };

struct List_80257C28 { u32 count; Ent_80257C28 **items; };

struct Win_80257C28 { u8 pad[0x2C]; u32 flags; u8 pad2[0x2C]; s32 counter; };

struct B_80257CB8 { u8 pad[4]; };

struct Elem_80257CB8 : B_80257CB8 {
    virtual void dtor(s32 flag);
};

struct List_80257CB8 {
    u32 count;
    Elem_80257CB8 **items;
};

struct List_80257D44 {
    u32 count;
    void **items;
};

struct Desc_80257D44 {
    u32 cols;
    u32 rows;
    u32 recs[1];
};

typedef char RecoveredGlobal_80257B4C_lbl_804CF948_size[sizeof(RecoveredGlobal_80257B4C_lbl_804CF948) == 0x18 ? 1 : -1];

typedef void *(*Ctor_80257D44)(void *, void *, s32);

void mem_free(void *);
void ** mem_alloc(u32);
#define destroy__13TUnk_804CF930Fs ((s32 (*)(s32, s32 *))destroy__13TUnk_804CF930Fs)
#define sub_80256BDC__13TUnk_804CF930Fs ((int (*)(void*, int))sub_80256BDC__13TUnk_804CF930Fs)
#define calc_bar_width__20TWindowSubStatusDispFPv ((s32 (*)())calc_bar_width__20TWindowSubStatusDispFPv)
#define step_gauge_bar_width ((void (*)(void *))step_gauge_bar_width)
void* init_from__13TUnk_804CF930FPvi(void* a0, void* a1, int a2);
u8 * init_layout_entry_copy__20TWindowSubStatusDispFPUc(u8 *arg0, u8 *arg1);
void draw_visible_window_entries(void *self, List_80257BC0 *list, void *ctx);
void init_window_layout_entries(List_80257D44 *self, Desc_80257D44 *desc, s32 arg2);
void * init_layout_entry_rect__20TWindowSubStatusDispFPUcs(void *, void *, s32);
void * TWindowSubStatusDisp__sub_80259D3C(void *, void *, s32);
void * init_layout_entry_scaled__20TWindowSubStatusDispFPUcl(void *, void *, s32);
void * TWindowHelpItem__sub_8025A594(void *, void *, s32);
void * TWindowHelpItem__sub_8025A95C(void *, void *, s32);
}
u8 *construct_text_entry(u8 *arg0, u8 *arg1, s32 arg2);
extern "C" {
void * init_part_direct__20TWindowSubStatusDispFPUcl(void *, void *, s32);
void * init_part_scaled__20TWindowSubStatusDispFPvPvi(void *, void *, s32);

#define lbl_804CF930 (*(unsigned char (*)[1])&lbl_804CF930)
extern s32 lbl_804CF998[];
extern const float lbl_805DCE58;
__declspec(section ".sdata2") f32 lbl_805DCEF0 = 7.5f;

void draw_visible_window_entries(void *self, List_80257BC0 *list, void *ctx) {
    Item_80257BC0 **p;
    u32 n;
    for (n = list->count, p = list->items; n != 0; n--, p++) {
        if (!((*p)->flags & 2)) {
            (*p)->draw(ctx);
        }
    }
}

void TUnk_804CE018::update_window_entry_list(void *list_arg) {
    List_80257C28 *list = (List_80257C28 *)list_arg;
    Ent_80257C28 **p;
    u32 n;
    if (!(((Win_80257C28 *)this)->flags & 0x2000) && (f32)((Win_80257C28 *)this)->counter < lbl_805DCEF0) return;
    n = list->count;
    p = list->items;
    while (n-- != 0) {
        (*p)->m1();
        p++;
    }
}

void TWindowSubStatusDisp::destroy_all_items() {
    List_80257CB8 *arg0 = (List_80257CB8 *)this;
    Elem_80257CB8 **p;
    u32 n;
    n = arg0->count;
    if (n != 0) {
        p = arg0->items;
        p += n - 1;
        while (n-- != 0) {
            if (*p != 0) {
                (*p)->dtor(1);
            }
            p--;
        }
        mem_free(arg0->items);
        arg0->count = 0;
        arg0->items = 0;
    }
}

void init_window_layout_entries(List_80257D44 *self, Desc_80257D44 *desc, s32 arg2) {
    u32 cols;
    u32 rows;
    u32 *rec;
    void **out;
    void *o;
    if (desc == NULL) {
        self->count = 0;
        self->items = NULL;
        return;
    }
    rows = desc->rows;
    self->count = desc->cols * rows;
    if (self->count == 0) {
        self->count = 0;
        self->items = NULL;
        return;
    }
    self->items = mem_alloc(self->count * 4);
    out = self->items;
    while (rows-- != 0) {
        cols = desc->cols;
        rec = desc->recs;
        while (cols-- != 0) {
            switch (*rec) {
            case 0:
                o = ::operator new(0x18);
                if (o != NULL) {
                    o = init_layout_entry_rect__20TWindowSubStatusDispFPUcs(o, rec, arg2);
                }
                *out = o;
                rec += 0x14 / 4;
                break;
            case 1:
                o = ::operator new(0x28);
                if (o != NULL) {
                    o = ((Ctor_80257D44)init_from__13TUnk_804CF930FPvi)(o, rec, arg2);
                }
                *out = o;
                rec += 0x24 / 4;
                break;
            case 2:
                o = ::operator new(0x68);
                if (o != NULL) {
                    o = ((Ctor_80257D44)init_layout_entry_copy__20TWindowSubStatusDispFPUc)(o, rec, arg2);
                }
                *out = o;
                rec += 0x2C / 4;
                break;
            case 3:
                o = ::operator new(0x2C);
                if (o != NULL) {
                    o = construct_text_entry((u8 *)o, (u8 *)rec, arg2);
                }
                *out = o;
                rec += 0x1C / 4;
                break;
            case 4:
                o = ::operator new(0x24);
                if (o != NULL) {
                    o = TWindowSubStatusDisp__sub_80259D3C(o, rec, arg2);
                }
                *out = o;
                rec += 0x1C / 4;
                break;
            case 5:
                o = ::operator new(0x30);
                if (o != NULL) {
                    o = init_layout_entry_scaled__20TWindowSubStatusDispFPUcl(o, rec, arg2);
                }
                *out = o;
                rec += 0x1C / 4;
                break;
            case 6:
                o = ::operator new(0x38);
                if (o != NULL) {
                    o = init_part_scaled__20TWindowSubStatusDispFPvPvi(o, rec, arg2);
                }
                *out = o;
                rec += 0x30 / 4;
                break;
            case 7:
                o = ::operator new(0x38);
                if (o != NULL) {
                    o = init_part_direct__20TWindowSubStatusDispFPUcl(o, rec, arg2);
                }
                *out = o;
                rec += 0x38 / 4;
                break;
            case 8:
                o = ::operator new(0x38);
                if (o != NULL) {
                    o = ((TWindowSubStatusDisp *)o)->reset_entry((int)rec, (int)arg2);
                }
                *out = o;
                rec += 1;
                break;
            case 9:
                o = ::operator new(0x28);
                if (o != NULL) {
                    o = ((TWindowSubComCard *)o)->init_fields((int)rec, (int)arg2);
                }
                *out = o;
                rec += 1;
                break;
            case 10:
                o = ::operator new(0x14);
                if (o != NULL) {
                    o = TWindowHelpItem__sub_8025A95C(o, rec, arg2);
                }
                *out = o;
                rec += 0xC / 4;
                break;
            case 11:
                o = ::operator new(0x24);
                if (o != NULL) {
                    o = TWindowHelpItem__sub_8025A594(o, rec, arg2);
                }
                *out = o;
                rec += 0xC / 4;
                break;
            case 12:
                o = ::operator new(0x28);
                if (o != NULL) {
                    o = ((TWindowSubStatusDisp *)o)->init_state((int)rec, (int)arg2);
                }
                *out = o;
                rec += 1;
                break;
            }
            out++;
        }
    }
}

void TWindowSubStatusDisp__sub_80258050(void) {  }

void TWindowSubStatusDisp__sub_80258054(void) {  }

void *TWindowSubStatusDisp::deleting_destructor(s16 arg1) {
    if (this != NULL) {
        *(s32 * *)&this->m_flags = lbl_804CF998;
        destroy__13TUnk_804CF930Fs((s32)this, 0);
        if (arg1 > 0) {
            ::operator delete(this);
        }
    }
    return this;
}
}

#undef draw_status_gauge_bar__13TUnk_804CF930FPvPvff
#undef destroy__13TUnk_804CF930Fs
#undef sub_80256BDC__13TUnk_804CF930Fs
#undef calc_bar_width__20TWindowSubStatusDispFPv
#undef step_gauge_bar_width
#undef lbl_804CF930
