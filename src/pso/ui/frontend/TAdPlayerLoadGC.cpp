// Built with -inline off,deferred: the functions are generated in reverse source order, so
// they are defined here from the last one in .text to the first.
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdSubPlyItemGC.h"
#include "types.h"

struct Entry_802D6DAC { s32 idx; const char *str; s32 id; NJS_POINT2 pos; };

extern "C" {
s32 TAdPlayerLoadGC__sub_801E1B50(int);
s32 TAdPlayerLoadGC__sub_801FD770();
s32 TAdPlayerLoadGC__sub_801FD814();
s32 check_system_load_result__23TAdSinglePlyChrSelectGCFv();
s32 load_system_file_flag__23TAdSinglePlyChrSelectGCFv();
extern char pso_character_card_filename[];
extern char pso_system_card_filename[];
void *memset(void *, int, u32);
char *strncpy(char *, const char *, u32);
s32 sprintf(void *, const void *, ...);
u32 calc_text_width(char *s);
void render_status_line__15TAdSubPlyItemGCFi(const char *, u32, f32, f32, f32);
extern const char *TAdPlayerLoadGC__class_name;
extern const char *TAdSubPlyItemGC__name;
extern const f32 lbl_805DE7C0;
extern const f32 lbl_805DE7C4;
extern const f32 lbl_805DE7C8;
extern const f32 lbl_805DE7CC;
extern const f32 lbl_805DE7D0;
extern s32 lbl_804E24F0[];
extern int TAdPlayerLoadGC__load_state;
extern int TAdChrSelBSlotGC__global_state;
}

u8 level_text_buffer[0x40];

#pragma push
#pragma opt_common_subs off
TAdSubPlyItemGC::TAdSubPlyItemGC(TObject *parent) : TObject(parent) {
    u32 i;
    m_name = TAdSubPlyItemGC__name;
    for (i = 0; i < 4; i++) {
        alpha[i] = 0;
        visible[i] = 0;
        memset(names[i], 0, 0xFF);
        levels[i] = 0;
    }
}
#pragma pop

TAdSubPlyItemGC::~TAdSubPlyItemGC() {}

void TAdSubPlyItemGC::run_task() {
    u32 i;
    for (i = 0; i < 4; i++) {
        level_pos[i].x = (lbl_805DE7CC + name_pos[i].x) - (f32)calc_text_width((char *)format_level_text(levels[i]));
        level_pos[i].y = lbl_805DE7D0 + name_pos[i].y;
        if (visible[i] != 0) {
            alpha[i] += 0xB;
            alpha[i] = (alpha[i] > 0xFF) ? 0xFF : alpha[i];
        }
    }
}

extern "C" {
void set_entry_text__15TAdSubPlyItemGCFPvPv(TAdSubPlyItemGC *self, Entry_802D6DAC *e) {
    s32 i = e->idx;
    strncpy(self->names[i], e->str, 0xFE);
    self->levels[i] = e->id;
    ((TWindowSubSymbolChatPartsSet *)(&self->name_pos[i]))->copy_vec2(&e->pos);
    self->level_pos[i].x = (lbl_805DE7CC + self->name_pos[i].x) -
                           (f32)calc_text_width((char *)self->format_level_text(self->levels[i]));
    self->level_pos[i].y = lbl_805DE7D0 + self->name_pos[i].y;
    self->alpha[i] = 0;
    self->visible[i] = 1;
}

void TAdSubPlyItemGC__sub_802D6D88(TAdSubPlyItemGC *self) {
    s32 i;
    for (i = 0; i < 4; i++) {
        self->visible[i] = 0;
    }
}
}

u8 *TAdSubPlyItemGC::format_level_text(int level) {
    memset(level_text_buffer, 0, 0x40);
    sprintf(level_text_buffer, "LV%d", level);
    return level_text_buffer;
}

void TAdSubPlyItemGC::render() {
    u32 i;
    NJS_POINT2 *pos;
    if (TMainTask::get_render_pass() != 1) {
        for (i = 0; i < 4; i++) {
            if (visible[i] != 0 && names[i][0] != 0) {
                pos = name_pos;
                render_status_line__15TAdSubPlyItemGCFi(names[i], (alpha[i] << 24) | 0x111111,
                    lbl_805DE7C0 + pos[i].x, name_pos[i].y, lbl_805DE7C4);
                render_status_line__15TAdSubPlyItemGCFi(names[i], (alpha[i] << 24) | 0xFFFFFF,
                    pos[i].x, pos[i].y, lbl_805DE7C8);
                if (levels[i] != 0) {
                    render_status_line__15TAdSubPlyItemGCFi((const char *)format_level_text(levels[i]),
                        (alpha[i] << 24) | 0x111111, lbl_805DE7C0 + level_pos[i].x, level_pos[i].y, lbl_805DE7C4);
                    render_status_line__15TAdSubPlyItemGCFi((const char *)format_level_text(levels[i]),
                        (alpha[i] << 24) | 0xFFFFFF, level_pos[i].x, level_pos[i].y, lbl_805DE7C8);
                }
            }
        }
    }
}

void set_character_select_b_slot_state(int a0) { TAdChrSelBSlotGC__global_state = a0; }

int get_player_load_state(void) { return TAdPlayerLoadGC__load_state; }

TAdPlayerLoadGC::TAdPlayerLoadGC(TObject *parent, int mode) : TObject(parent) {
    m_name = TAdPlayerLoadGC__class_name;
    state = 0;
    this->mode = mode;
    set_state(0);
}

TAdPlayerLoadGC::~TAdPlayerLoadGC() {}

void TAdPlayerLoadGC::run_task() {
    set_character_select_b_slot_state((int)state);
    if (probe_card_slot(0) == 0) {
        state = 0U;
    }
    switch (state) {
    case 0:
        if (mode == 2) {
            if ((TAdPlayerLoadGC__sub_801E1B50(1) == 0) && (probe_card_slot(0) != 0)) {
                state = 1U;
            }
        } else if (probe_card_slot(0) != 0) {
            state = 1U;
        }
        break;
    case 1:
        if ((probe_and_check_card(0) != 0) || ((u32)get_load_result(0) != 0xFFFFFF83U)) {
            state = 2U;
        }
        break;
    case 2:
        if ((probe_and_check_card(0) != 0) || ((u32)get_load_result(0) != 0xFFFFFF21U)) {
            state = 3U;
        }
    case 3:
        if (probe_and_check_card(0) != 0) {
            state = 4U;
        }
        break;
    case 4:
        if (check_memcard_status(0) == 0) {
            state = 5U;
        }
        break;
    case 5:
        if ((u32)find_card_file(0, pso_character_card_filename) != 0xFFFFFF41U) {
            state = 6U;
        }
        break;
    case 6:
        if ((find_card_file(0, pso_character_card_filename) == 0) && (get_instance() == 0)) {
            state = 7U;
        }
        break;
    case 7:
        if ((u32)find_card_file(0, pso_system_card_filename) != 0xFFFFFF41U) {
            state = 8U;
        }
        break;
    case 8:
        if ((u32)load_system_file_flag__23TAdSinglePlyChrSelectGCFv() != 0xFFFFFF05U) {
            state = 9U;
        }
        break;
    case 9:
        if (get_instance() == 0) {
            state = 0xAU;
        }
        break;
    case 10:
        if (TAdPlayerLoadGC__sub_801FD770() != 1) {
            state = 0xBU;
        }
        break;
    case 11:
        if (TAdPlayerLoadGC__sub_801FD770() != 5) {
            state = 0xCU;
        }
        break;
    case 12:
        if (mode == 1) {
            state = 0xDU;
        }
        break;
    case 13:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else {
            state = 0xEU;
        }
        break;
    case 14:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if ((probe_and_check_card(1) != 0) || ((u32)get_load_result((void *)1) != 0xFFFFFF83U)) {
            state = 0xFU;
        }
        break;
    case 15:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if ((probe_and_check_card(1) != 0) || ((u32)get_load_result((void *)1) != 0xFFFFFF21U)) {
            state = 0x10U;
        }
    case 16:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if (probe_and_check_card(1) != 0) {
            state = 0x11U;
        }
        break;
    case 17:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if (check_memcard_status(1) == 0) {
            state = 0x12U;
        }
        break;
    case 18:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if ((u32)find_card_file(1, pso_character_card_filename) != 0xFFFFFF41U) {
            state = 0x13U;
        }
        break;
    case 19:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if ((find_card_file(1, pso_character_card_filename) == 0) && (get_instance() == 0)) {
            state = 0x14U;
        }
        break;
    case 20:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if ((u32)find_card_file(1, pso_system_card_filename) != 0xFFFFFF41U) {
            state = 0x15U;
        }
        break;
    case 21:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if ((find_card_file(1, pso_character_card_filename) == 0) && ((u32)check_system_load_result__23TAdSinglePlyChrSelectGCFv() != 0xFFFFFF05U)) {
            state = 0x16U;
        }
        break;
    case 22:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if (get_instance() == 0) {
            state = 0x17U;
        }
        break;
    case 23:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if (TAdPlayerLoadGC__sub_801FD814() != 1) {
            state = 0x18U;
        }
        break;
    case 24:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        } else if (TAdPlayerLoadGC__sub_801FD814() != 5) {
            state = 0x19U;
        }
        break;
    case 25:
        if (probe_card_slot(1) == 0) {
            state = 0xDU;
        }
        break;
    }
    if (get_player_load_state() != 0) {
        set_state(0);
        state = 0U;
    }
}

void TAdPlayerLoadGC::render() {}

// TUnk_804E24F0's dtor: the weapon class's vtable (lbl_804E24F0) sits right before this
// unit's data, so this copy probably belongs to the weapon unit's tail.
extern "C" void *__dt__13TUnk_804E24F0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E24F0;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
