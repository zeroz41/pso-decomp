#include "pso/TObject.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/ui/TAdPlayerLoadGC.h"
#include "pso/player/TObjPlayer.h"
class TAdPlayerLoadGC : public TObject {
public:
    virtual void vtable_key_TAdPlayerLoadGC();
    virtual ~TAdPlayerLoadGC();
};

#include "types.h"

struct Vec2_802D6FD4 { f32 x, y; };

struct W_802D6FD4 { s32 v; };

struct Item_802D6FD4 {
    u8 pad0[0x20];
    char names[4][0xFF];
    W_802D6FD4 ids[4];
    W_802D6FD4 alpha[4];
    W_802D6FD4 flags[4];
    Vec2_802D6FD4 base[4];
    Vec2_802D6FD4 pos[4];
};

extern "C" {
s32 get_instance__15TAdPlayerLoadGCFv();
void set_state__15TAdPlayerLoadGCFi(int);
s32 probe_and_check_card__15TAdPlayerLoadGCFv(int);
s32 get_load_result__15TAdPlayerLoadGCFPv(int);
s32 TAdPlayerLoadGC__sub_801E1B50(int);
s32 probe_card_slot__15TAdPlayerLoadGCFv(int);
s32 check_memcard_status__15TAdPlayerLoadGCFl(int);
s32 find_card_file__15TAdPlayerLoadGCFiPv(int, void *);
s32 TAdPlayerLoadGC__sub_801FD770();
s32 TAdPlayerLoadGC__sub_801FD814();
s32 check_system_load_result__23TAdSinglePlyChrSelectGCFv();
s32 load_system_file_flag__23TAdSinglePlyChrSelectGCFv();
extern s32 lbl_804C88C0[];
extern s32 pso_system_card_filename[];
void __ct__7TObjectFP7TObject(void *);
void *memset(void *, int, u32);
extern void *__vt__15TAdSubPlyItemGC[6];
extern s32 TAdSubPlyItemGC__name;
Item_802D6FD4 *__ct__15TAdSubPlyItemGCFv(Item_802D6FD4 *self);

extern s32 lbl_804E24F0[];

void *__dt__13TUnk_804E24F0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E24F0;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

void render__15TAdPlayerLoadGCFv(void) {  }

void __dt__15TAdPlayerLoadGCFv(void);
void render_shadows__7TObjectFv(void);
void *__vt__15TAdPlayerLoadGC[6] = {
    0, 0, (void *)__dt__15TAdPlayerLoadGCFv, (void *)run_task__15TAdPlayerLoadGCFv,
    (void *)render__15TAdPlayerLoadGCFv, (void *)render_shadows__7TObjectFv,
};
extern void *lbl_805D3F48;

void run_task__15TAdPlayerLoadGCFv(u8 *arg0) {
    set_character_select_b_slot_state((int) (*(u32 *)((s8 *)arg0 + 0x1C)));
    if (probe_card_slot__15TAdPlayerLoadGCFv(0) == 0) {
        *(u32 *)((s8 *)arg0 + 0x1C) = 0U;
    }
    switch (*(u32 *)((s8 *)arg0 + 0x1C)) {
    case 0:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x20) == 2) {
            if ((TAdPlayerLoadGC__sub_801E1B50(1) == 0) && (probe_card_slot__15TAdPlayerLoadGCFv(0) != 0)) {
                *(u32 *)((s8 *)arg0 + 0x1C) = 1U;
            }
        } else if (probe_card_slot__15TAdPlayerLoadGCFv(0) != 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 1U;
        }
        break;
    case 1:
        if ((probe_and_check_card__15TAdPlayerLoadGCFv(0) != 0) || ((u32)get_load_result__15TAdPlayerLoadGCFPv(0) != 0xFFFFFF83U)) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 2U;
        }
        break;
    case 2:
        if ((probe_and_check_card__15TAdPlayerLoadGCFv(0) != 0) || ((u32)get_load_result__15TAdPlayerLoadGCFPv(0) != 0xFFFFFF21U)) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 3U;
        }
    case 3:
        if (probe_and_check_card__15TAdPlayerLoadGCFv(0) != 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 4U;
        }
        break;
    case 4:
        if (check_memcard_status__15TAdPlayerLoadGCFl(0) == 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 5U;
        }
        break;
    case 5:
        if ((u32)find_card_file__15TAdPlayerLoadGCFiPv(0, lbl_804C88C0) != 0xFFFFFF41U) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 6U;
        }
        break;
    case 6:
        if ((find_card_file__15TAdPlayerLoadGCFiPv(0, lbl_804C88C0) == 0) && (get_instance__15TAdPlayerLoadGCFv() == 0)) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 7U;
        }
        break;
    case 7:
        if ((u32)find_card_file__15TAdPlayerLoadGCFiPv(0, pso_system_card_filename) != 0xFFFFFF41U) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 8U;
        }
        break;
    case 8:
        if ((u32)load_system_file_flag__23TAdSinglePlyChrSelectGCFv() != 0xFFFFFF05U) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 9U;
        }
        break;
    case 9:
        if (get_instance__15TAdPlayerLoadGCFv() == 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xAU;
        }
        break;
    case 10:
        if (TAdPlayerLoadGC__sub_801FD770() != 1) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xBU;
        }
        break;
    case 11:
        if (TAdPlayerLoadGC__sub_801FD770() != 5) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xCU;
        }
        break;
    case 12:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x20) == 1) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xDU;
        }
        break;
    case 13:
        if (probe_card_slot__15TAdPlayerLoadGCFv(1) == 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xDU;
        } else {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xEU;
        }
        break;
    case 14:
        if (probe_card_slot__15TAdPlayerLoadGCFv(1) == 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xDU;
        } else if ((probe_and_check_card__15TAdPlayerLoadGCFv(1) != 0) || ((u32)get_load_result__15TAdPlayerLoadGCFPv(1) != 0xFFFFFF83U)) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xFU;
        }
        break;
    case 15:
        if (probe_card_slot__15TAdPlayerLoadGCFv(1) == 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xDU;
        } else if ((probe_and_check_card__15TAdPlayerLoadGCFv(1) != 0) || ((u32)get_load_result__15TAdPlayerLoadGCFPv(1) != 0xFFFFFF21U)) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0x10U;
        }
    case 16:
        if (probe_card_slot__15TAdPlayerLoadGCFv(1) == 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xDU;
        } else if (probe_and_check_card__15TAdPlayerLoadGCFv(1) != 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0x11U;
        }
        break;
    case 17:
        if (probe_card_slot__15TAdPlayerLoadGCFv(1) == 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xDU;
        } else if (check_memcard_status__15TAdPlayerLoadGCFl(1) == 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0x12U;
        }
        break;
    case 18:
        if (probe_card_slot__15TAdPlayerLoadGCFv(1) == 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xDU;
        } else if ((u32)find_card_file__15TAdPlayerLoadGCFiPv(1, lbl_804C88C0) != 0xFFFFFF41U) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0x13U;
        }
        break;
    case 19:
        if (probe_card_slot__15TAdPlayerLoadGCFv(1) == 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xDU;
        } else if ((find_card_file__15TAdPlayerLoadGCFiPv(1, lbl_804C88C0) == 0) && (get_instance__15TAdPlayerLoadGCFv() == 0)) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0x14U;
        }
        break;
    case 20:
        if (probe_card_slot__15TAdPlayerLoadGCFv(1) == 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xDU;
        } else if ((u32)find_card_file__15TAdPlayerLoadGCFiPv(1, pso_system_card_filename) != 0xFFFFFF41U) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0x15U;
        }
        break;
    case 21:
        if (probe_card_slot__15TAdPlayerLoadGCFv(1) == 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xDU;
        } else if ((find_card_file__15TAdPlayerLoadGCFiPv(1, lbl_804C88C0) == 0) && ((u32)check_system_load_result__23TAdSinglePlyChrSelectGCFv() != 0xFFFFFF05U)) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0x16U;
        }
        break;
    case 22:
        if (probe_card_slot__15TAdPlayerLoadGCFv(1) == 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xDU;
        } else if (get_instance__15TAdPlayerLoadGCFv() == 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0x17U;
        }
        break;
    case 23:
        if (probe_card_slot__15TAdPlayerLoadGCFv(1) == 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xDU;
        } else if (TAdPlayerLoadGC__sub_801FD814() != 1) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0x18U;
        }
        break;
    case 24:
        if (probe_card_slot__15TAdPlayerLoadGCFv(1) == 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xDU;
        } else if (TAdPlayerLoadGC__sub_801FD814() != 5) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0x19U;
        }
        break;
    case 25:
        if (probe_card_slot__15TAdPlayerLoadGCFv(1) == 0) {
            *(u32 *)((s8 *)arg0 + 0x1C) = 0xDU;
        }
        break;
    }
    if (get_player_load_state() != 0) {
        set_state__15TAdPlayerLoadGCFi(0);
        *(u32 *)((s8 *)arg0 + 0x1C) = 0U;
    }
}

}
TAdPlayerLoadGC::~TAdPlayerLoadGC() {}

void *__ct__15TAdPlayerLoadGCFv(void *object, void *arg1, void *arg2) {
    __ct__7TObjectFP7TObject(object);
    *(s32 **)((s8 *)object + 0x18) = (s32 *)__vt__15TAdPlayerLoadGC;
    *(void **)((s8 *)object + 0x0) = lbl_805D3F48;
    *(u32 *)((s8 *)object + 0x1C) = 0;
    *(void **)((s8 *)object + 0x20) = arg2;
    set_state__15TAdPlayerLoadGCFi(0);
    return object;
}

    extern int TAdPlayerLoadGC__load_state;
int get_player_load_state(void) {  return TAdPlayerLoadGC__load_state; }

    extern int TAdChrSelBSlotGC__global_state;
void set_character_select_b_slot_state(int a0) { TAdChrSelBSlotGC__global_state = a0; }

class TAdSubPlyItemGC : public TObject {
public:
    virtual void vtable_key_TAdSubPlyItemGC();
    virtual ~TAdSubPlyItemGC();
};

#include "pso/TMainTask.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/item/TItem.h"

struct Vec2_802D6E7C { f32 x, y; };

struct Self_802D6E7C {
    u8 pad[0x41C];
    s32 ids[4];
    u32 alpha[4];
    s32 flags[4];
    Vec2_802D6E7C base[4];
    Vec2_802D6E7C pos[4];
};

struct Item_802D6BEC {
    u8 pad0[0x20];
    char names[4][0xFF];
    u32 ids[4];
    u32 alpha[4];
    s32 flags[4];
    Vec2_802D6E7C base[4];
    Vec2_802D6E7C pos[4];
};
struct Entry_802D6DAC { s32 idx; const char *str; s32 id; Vec2_802D6E7C pos; };
extern "C" {
void render_status_line__15TAdSubPlyItemGCFi(const char *, u32, f32, f32, f32);
extern const f32 lbl_805DE7C0;
extern const f32 lbl_805DE7C4;
extern const f32 lbl_805DE7C8;
char *strncpy(char *, const char *, u32);
u32 calc_text_width(char *s);
extern const f32 lbl_805DE7CC;
extern const f32 lbl_805DE7D0;
void run_task__15TAdSubPlyItemGCFv(Self_802D6E7C *self);
extern u8 level_text_buffer[];
extern u8 lbl_804725E0[];
s32 sprintf(void *, const void *, ...);
typedef struct S_802D6D88 { u8 pad0[0x43C]; s32 f[4]; } S_802D6D88;

void render__15TAdSubPlyItemGCFv(Item_802D6BEC *self) {
    u32 i;
    Vec2_802D6E7C *base;
    if (TMainTask::get_render_pass() != 1) {
        for (i = 0; i < 4; i++) {
            if (self->flags[i] != 0 && self->names[i][0] != 0) {
                base = self->base;
                render_status_line__15TAdSubPlyItemGCFi(self->names[i], (self->alpha[i] << 24) | 0x111111,
                    lbl_805DE7C0 + base[i].x, self->base[i].y, lbl_805DE7C4);
                render_status_line__15TAdSubPlyItemGCFi(self->names[i], (self->alpha[i] << 24) | 0xFFFFFF,
                    base[i].x, base[i].y, lbl_805DE7C8);
                if (self->ids[i] != 0) {
                    render_status_line__15TAdSubPlyItemGCFi((const char *)format_level_text__15TAdSubPlyItemGCFii((s32)self, self->ids[i]),
                        (self->alpha[i] << 24) | 0x111111, lbl_805DE7C0 + self->pos[i].x, self->pos[i].y, lbl_805DE7C4);
                    render_status_line__15TAdSubPlyItemGCFi((const char *)format_level_text__15TAdSubPlyItemGCFii((s32)self, self->ids[i]),
                        (self->alpha[i] << 24) | 0xFFFFFF, self->pos[i].x, self->pos[i].y, lbl_805DE7C8);
                }
            }
        }
    }
}

u8 *format_level_text__15TAdSubPlyItemGCFii(s32 arg0, s32 arg1) {
    memset(level_text_buffer, 0, 0x40);
    sprintf(level_text_buffer, lbl_804725E0, arg1);
    return level_text_buffer;
}

void TAdSubPlyItemGC__sub_802D6D88(S_802D6D88 *arg0) {
    s32 i;
    for (i = 0; i < 4; i++) {
        arg0->f[i] = 0;
    }
}
void set_entry_text__15TAdSubPlyItemGCFPvPv(Item_802D6BEC *self, Entry_802D6DAC *e) {
    s32 i = e->idx;
    strncpy(self->names[i], e->str, 0xFE);
    self->ids[i] = e->id;
    ((TWindowSubSymbolChatPartsSet *)(&self->base[i]))->copy_vec2(&e->pos);
    self->pos[i].x = (lbl_805DE7CC + self->base[i].x) -
                     (f32)calc_text_width((char *)((const char *)format_level_text__15TAdSubPlyItemGCFii((s32)self, self->ids[i])));
    self->pos[i].y = lbl_805DE7D0 + self->base[i].y;
    self->alpha[i] = 0;
    self->flags[i] = 1;
}

void run_task__15TAdSubPlyItemGCFv(Self_802D6E7C *self) {
    u32 i;
    for (i = 0; i < 4; i++) {
        self->pos[i].x = (lbl_805DE7CC + self->base[i].x) -
                         (f32)calc_text_width((char *)(((const char *(*)(void *, s32))format_level_text__15TAdSubPlyItemGCFii)(self, self->ids[i])));
        self->pos[i].y = lbl_805DE7D0 + self->base[i].y;
        if (self->flags[i] != 0) {
            self->alpha[i] += 0xB;
            self->alpha[i] = (self->alpha[i] > 0xFF) ? 0xFF : self->alpha[i];
        }
    }
}
}

TAdSubPlyItemGC::~TAdSubPlyItemGC() {}

extern "C" {
#pragma push
#pragma opt_common_subs off
Item_802D6FD4 *__ct__15TAdSubPlyItemGCFv(Item_802D6FD4 *self) {
    u32 i;
    __ct__7TObjectFP7TObject(self);
    *(void **)((s8 *)self + 0x18) = __vt__15TAdSubPlyItemGC;
    *(s32 *)((s8 *)self + 0) = TAdSubPlyItemGC__name;
    for (i = 0; i < 4; i++) {
        self->alpha[i].v = 0;
        self->flags[i].v = 0;
        memset(self->names[i], 0, 0xFF);
        self->ids[i].v = 0;
    }
    return self;
}
#pragma pop

}

extern "C" {
void __dt__15TAdSubPlyItemGCFv(void);
void render__15TAdSubPlyItemGCFv(Item_802D6BEC *self);
void *__vt__15TAdSubPlyItemGC[6] = {
    0, 0, (void *)__dt__15TAdSubPlyItemGCFv, (void *)run_task__15TAdSubPlyItemGCFv,
    (void *)render__15TAdSubPlyItemGCFv, (void *)render_shadows__7TObjectFv,
};

}
