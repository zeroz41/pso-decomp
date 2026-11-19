#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TUnk_804CF930.h"
#include "pso/unk/TUnk_804CF998.h"
#include "pso/unk/TUnk_804CF9C8.h"
#include "pso/unk/TUnk_804EF440.h"
#include "pso/ui/window/TWindowSubStatusDisp_80256B94.h"
#include "pso/ui/window/TWindowSubStatusDisp_80257BC0.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/item/TItemData.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/map/FloorArea.h"
#include "pso/render/render_util.h"
#include "pso/ui/ItemListRow.h"


extern "C" {

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

typedef void *(*Ctor_80257D44)(void *, void *, s32);

void mem_free(void *);
s32 mem_alloc(s32);
void* init_from__13TUnk_804CF930FPvi(void* a0, void* a1, int a2);
u8 * init_layout_entry_copy__20TWindowSubStatusDispFPUc(u8 *arg0, u8 *arg1);
void draw_visible_window_entries(void *self, List_80257BC0 *list, void *ctx);
void init_window_layout_entries(List_80257D44 *self, Desc_80257D44 *desc, s32 arg2);
void * TWindowHelpItem__sub_8025A594(void *, void *, s32);
void * TWindowHelpItem__sub_8025A95C(void *, void *, s32);
}
u8 *construct_text_entry(u8 *arg0, u8 *arg1, s32 arg2);
extern "C" {
void * init_part_direct__20TWindowSubStatusDispFPUcl(void *, void *, s32);
void * init_part_scaled__20TWindowSubStatusDispFPvPvi(void *, void *, s32);

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

void TWindowBase::update_window_entry_list(void *list_arg) {
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
    self->items = (void **)mem_alloc(self->count * 4);
    out = self->items;
    while (rows-- != 0) {
        cols = desc->cols;
        rec = desc->recs;
        while (cols-- != 0) {
            switch (*rec) {
            case 0:
                o = ::operator new(0x18);
                if (o != NULL) {
                    o = __ct__13TUnk_804CF998FPUcl(o, (u8 *)rec, arg2);
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
                    o = __ct__13TUnk_804CF9C8FPUcl(o, (u8 *)rec, arg2);
                }
                *out = o;
                rec += 0x1C / 4;
                break;
            case 5:
                o = ::operator new(0x30);
                if (o != NULL) {
                    o = __ct__13TUnk_804CF9E0FPUcl(o, (u8 *)rec, arg2);
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
                    o = __ct__11ItemListRowFPUcl(o, (u8 *)rec, arg2);
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
                    o = __ct__13TUnk_804EF440FPUcl(o, (u8 *)rec, arg2);
                }
                *out = o;
                rec += 1;
                break;
            }
            out++;
        }
    }
}
}
