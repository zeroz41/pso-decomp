#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD_WS_String.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/TWindowDD_8034435C.h"

struct TWindowDD_803431C0 {
    u8 pad0[0x20];
    s32 depth;
    void *child[7];
    s32 ids[13];
    void *objs[5];
    s32 f88;
    s32 f8C;
    s32 f90;
    u8 pad94[0xB0 - 0x94];
    s32 fB0;
    u8 padB4[0xBC - 0xB4];
    s32 fBC;
    u8 padC0[0xC6 - 0xC0];
    s16 fC6;
};

struct TWindowDD_8034330C {
    u8 pad0[0x20];
    s32 depth;
    u8 *child[7];
    s32 ids[13];
    void *objs[5];
    s32 f88;
    s32 f8C;
    s32 f90;
    u8 pad94[0xAC - 0x94];
    s32 fAC;
    s32 fB0;
    u8 padB4[0xBC - 0xB4];
    s32 fBC;
    u8 fC0[4];
    u8 fC4[4];
};



struct Sub_803438C4 { u8 pad[0x50]; u32 x50; };

struct Win_803438C4 {
    u8 pad0[0x1C];
    u8 input[4];
    s32 idx;
    Sub_803438C4 *subs[(0x7C - 0x24) / 4];
    u32 x7C;
    u32 x80;
    u8 pad84[0x94 - 0x84];
    s32 x94;
    u8 pad98[0xA8 - 0x98];
    s32 xA8;
    s32 xAC;
    s32 xB0;
    u8 padB4[0xB8 - 0xB4];
    s32 xB8;
    u8 padBC[0xC0 - 0xBC];
    void *xC0;
    s16 xC4;
    u8 padC6[0xE0 - 0xC6];
    s16 xE0;
};

struct R_80343BC0 { s16 a; s16 b; u32 w[6]; };

struct V2_80343C64
{
  f32 x;
  f32 y;
};

struct Win_80343C64
{
  u8 pad0[0x30];
  f32 f30;
  f32 f34;
  f32 f38;
  u8 pad3C[4];
  f32 f40;
  f32 f44;
  f32 f48;
};

struct Obj_80343C64
{
  s32 f0;
  u8 pad4[0x14];
  void *vt;
  s16 f1C;
  u8 pad1E[2];
  s32 f20;
  s32 a24[8];
  s32 a44[8];
  s32 a64[6];
  s32 f7C;
  s32 f80;
  s32 f84;
  s32 f88;
  s32 f8C;
  s32 f90;
  s32 f94;
  s32 f98;
  s32 f9C;
  s32 fA0;
  s32 fA4;
  s32 fA8;
  s32 fAC;
  s32 fB0;
  s32 fB4;
  s32 fB8;
  s32 fBC;
  void *fC0;
  u8 fC4[0x1C];
  u8 fE0[0x1C];
  s16 fFC;
  u8 padFE[2];
  s32 f100;
  s32 f104;
};

#include <stddef.h>
#include <string.h>
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
struct NumberWindow;
struct WordSelectPage;
struct WordSelectWindowState {
    u8 unknown00[0x20];
    s32 activePage;
    WordSelectPage* pages[7];
    u8 unknown40[0x84 - 0x40];
    NumberWindow* numberWindow;
};

struct WindowPosition { f32 x, y; };

extern "C" {
s32 free_child__9TWindowDDFv(int);
s32 apply_input__9TWindowDDFPvPv(int, int);
s32 update__9TWindowDDFl(int, int, int);
void TWindowDD__sub_803434F4(u8 *arg0);
void TWindowDD__sub_80342428(u8 *arg0);
void handle_input__9TWindowDDFi(s32 arg0);
s32 enter_state_19__9TWindowDDFv(void *);
s32 enter_state_18__9TWindowDDFv(void *);
void enter_state_16__9TWindowDDFPv(void *arg0);
void update_state__9TWindowDDFPv(void *arg0);
void TWindowDD__sub_80342800(u8 *arg0);
void update__9TWindowDDFi(s32 arg0);
void TWindowDD__sub_803429B0(u8 *arg0);
s32 enter_state_9__9TWindowDDFv(void *);
s32 update_dispatch__9TWindowDDFv(void *);
s32 update_layout__9TWindowDDFv(void *);
s32 update_transition__9TWindowDDFv(void *);
void TWindowDD__sub_80342D14(u8 *arg0);
s32 update__9TWindowDDFv(void *);
s32 handle_confirm_input__9TWindowDDFv(void *);
void run_state__9TWindowDDFPv(u8 *arg0);
void queue_destruction__7TObjectFv(void *);
s16 TWindowDD__sub_8034214C(u8 *arg0);
void destroy_menu_entry__9TWindowDDFl(void *, int);
void TWindowDD__sub_80347980(void *);
s32 *get_entry__9TWindowDDFii(void *, s32);
void update__9TWindowDDFPvPv(void *, void *);
void pop_menu_level__9TWindowDDFPv(TWindowDD_803431C0 *arg0);
void set_pos_and_data__9TWindowDDFf(void *, f32);
void set_item_pos__9TWindowDDFl(void *, int);
u8 *init_last_child__9TWindowDDFv(void *);
void TWindowDD__sub_80347CC8(void *, void *);
void setup_entry__9TWindowDDFl(void *, s32);
void TWindowDD__sub_80347F48(u8 *arg0);
void init_entry_field_64__9TWindowDDFl(void *, int);
void TWindowDD__sub_80347FA0(s32 arg0, s32 arg1);
void pop_entry__9TWindowDDFv(void *);
extern const s32 TWindowDD__data_805DFB50;
extern const f32 TWindowDD__data_805DFB74;
extern const f32 lbl_805DFB7C;
extern const f32 lbl_805DFB80;
extern const f32 lbl_805DFB88;
extern const f32 TWindowDD__data_805DFBFC;
extern const f32 lbl_805DFC0C;
extern const f32 TWindowDD__data_805DFC10;
void apply_entry_layout__9TWindowDDFPv(TWindowDD_8034330C *arg0);
s32 build_player_word_lists__9TWindowDDFv();
void TWindowDD__sub_80347A4C(u8 *arg0, s32 arg1);
u8 *TWindowDD__sub_80347AD4(void *, s32, s32);
s32 TWindowDD__sub_80347E04(void *, int);
s32 dispatch_state__9TWindowDDFv(void *, int, int, int);
s32 reset_index__9TWindowDDFv(void *);
extern const f32 TWindowDD__data_805DFB6C;
extern const f32 lbl_805DFB90;
void TWindowDD__sub_803435A0(u8 *arg0);
s32 apply_both_choices__9TWindowDDFll(void *, int);
s32 set_clamped_page__9TWindowDDFl(int, int);
s32 TWindowDD__sub_80340820(int);
s32 handle_input__9TWindowDDFv(int);
s32 TWindowDD__sub_80340910(int);
s32 set_clamped_selection__9TWindowDDFl(int, int);
s32 set_value_f32__9TWindowDDFl(int, int);
s32 TWindowDD__sub_80341AE0(int);
s32 TWindowDD__sub_80341AF8(int);
s32 TWindowDD__sub_8034217C(int);
s32 get_cursor_index__9TWindowDDFv(int);
s32 spawn_window__9TWindowDDFv();
s32 play_se__9TWindowDDFv();
s32 play_sound__9TWindowDDFv();
s32 TWindowDD__sub_803482B0(void *);
s32 test_input_flag_4__9TWindowDDFv(void *);
s32 set_state__9TWindowDDFv(void *);
s32 TWindowDD__sub_803484C4(void *);
void run_task__9TWindowDDFv(u8 *arg0);
void copy_chat_entry__9TWindowDDFPvPv(R_80343BC0 *arg0, R_80343BC0 *arg1);
void __ct__7TObjectFP7TObject(void *);
void *get_player_by_client_id(s32);
s32 get_current_floor(void);
s32 check_all_ready__9TWindowDDFl(s32);
s32 is_room_free_of_active_enemies(s32 floor, s16 room);
void init_item_slots__9TWindowDDFv(void *);
s32 TWindowDD__sub_80340F70(void);
s32 TWindowDD__sub_80342384(s32 arg0, s32 arg1);
void set_default_positions__9TWindowDDFiPv(void *, s32);
void init_layout__9TWindowDDFiPv(void *, s32);
s32 TWindowDD__sub_8034146C(V2_80343C64 *arg0, V2_80343C64 *arg1, s32 arg2, s32 arg3, f32 farg0);
void TWindowDD__sub_803412A0(u8 *arg0);
void update_state__9TWindowDDFv(void);
s32 create__9TWindowDDFv(void);
extern char lbl_8047863C[];
extern char lbl_80478644[];
extern s32 __vt__9TWindowDD[];
extern s32 word_select_type_name_pointer;
extern s32 local_client_id;
extern u32 TWindowDD__work_buffer;
extern s16 lbl_805D6E24;
extern char *lbl_805D6E64;
extern s8 lbl_805D6E68;
extern char *lbl_805D6E6C;
extern s8 lbl_805D6E70;
extern const f32 lbl_805DFB54;
extern const f32 lbl_805DFB60;
extern const f32 lbl_805DFB64;
extern const f32 lbl_805DFB68;
extern const f32 lbl_805DFBA4;
extern const f32 lbl_805DFBA8;
extern const f32 lbl_805DFBAC;
extern const f32 lbl_805DFBB0;
extern const f32 lbl_805DFBB4;
extern const f32 lbl_805DFBB8;
extern const f32 lbl_805DFBD0;
extern const f32 lbl_805DFBD4;
extern const f32 lbl_805DFBD8;
extern const f32 lbl_805DFBF0;
extern const f32 lbl_805DFBF4;
extern const f32 lbl_805DFBF8;
extern const f32 lbl_805DFCB8;
Obj_80343C64 *TWindowDD__ct(Obj_80343C64 *self, void *parent, void *arg2);
void* __nw__7TObjectFUl(u32 size);
extern const f32 lbl_805DFB70, lbl_805DFC28, lbl_805DFCB0, lbl_805DFCB4;
void open_numeric_parameter_input__9TWindowDDFPviii(WordSelectWindowState* self, s32 minimum, s32 maximum, s32 initial);
void *__dt__9TWindowDDFv(void *arg0, s16 arg1);
void free_buffers__9TWindowDDFv(void);
s32 update_close_flag__9TWindowDDFPv(void *arg0);
s32 get_current_child_index__9TWindowDDFv();
void close_all_windows__9TWindowDDFv(void *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
s32 classify_id__9TWindowDDFs();
}
s32 TWindowDD_check_input_mask(void *input_context, s32 arg1);
void clear_window_dd_nodes(void);
extern "C" {
void mem_free(void*);

s32 update_close_flag__9TWindowDDFPv(void *arg0) {
    get_current_child_index__9TWindowDDFv();
    if (classify_id__9TWindowDDFs() != 7) {
        *(s32 *)((s8 *)arg0 + 0xB8) = 1;
        return 1;
    }
    return 0;
}

NumberWindow* __ct__18TWindowInputNumberFPvllls(void* storage, const WindowPosition* position,
                                   s32 minimum, s32 maximum, s32 initial, s16 client);
void open_numeric_parameter_input__9TWindowDDFPviii(WordSelectWindowState* self, s32 minimum, s32 maximum, s32 initial) {
    WindowPosition position;
    position.x = lbl_805DFCB0 + TWindowDD__data_805DFB6C;
    position.y = lbl_805DFCB4 + lbl_805DFB70;
    NumberWindow* window = (NumberWindow*)__nw__7TObjectFUl(0x7C);
    if (window) {
        window = __ct__18TWindowInputNumberFPvllls(window, &position, minimum, maximum, initial,
                                      (s16)local_client_id);
    }
    self->numberWindow = window;
    if (self->numberWindow) {
        ((TWindowBase *)(self->numberWindow))->set_depth(lbl_805DFC28);
        ((TWindowSubItem *)(self->numberWindow))->set_flag60_bit10();
        TWindowDD__sub_80341AE0((int)self->pages[self->activePage]);
    }
}

void pop_menu_level__9TWindowDDFPv(TWindowDD_803431C0 *arg0) {
    s32 *entry;
    void *child;
    get_entry__9TWindowDDFii(arg0, arg0->fB0);
    entry = get_entry__9TWindowDDFii(arg0, arg0->ids[arg0->depth]);
    TWindowDD__sub_80347980(arg0);
    if (*entry & 8) {
        destroy_menu_entry__9TWindowDDFl(arg0, 0);
    } else if ((child = arg0->child[arg0->depth]) != NULL) {
        update__9TWindowDDFPvPv(arg0, child);
    }
    destroy_menu_entry__9TWindowDDFl(arg0, 1);
    arg0->depth--;
    if (*entry & 4) {
        arg0->fBC--;
        if (arg0->fBC >= 0 && arg0->objs[arg0->fBC] != NULL) {
            queue_destruction__7TObjectFv(arg0->objs[arg0->fBC]);
            arg0->objs[arg0->fBC] = NULL;
        }
    }
    arg0->f90 = arg0->f8C;
    arg0->f8C = arg0->f88;
    arg0->f88 = TWindowDD__sub_8034214C((u8 *)arg0->child[arg0->depth]);
    arg0->fB0 = arg0->ids[arg0->depth + 1];
    if (arg0->fB0 == 0xD) {
        arg0->fC6 = 4;
    }
}

void apply_entry_layout__9TWindowDDFPv(TWindowDD_8034330C *arg0) {
    s32 *prev;
    s32 *entry;
    u8 *w;
    u8 *child;
    s32 id;
    prev = get_entry__9TWindowDDFii(arg0, arg0->fB0);
    entry = get_entry__9TWindowDDFii(arg0, arg0->ids[arg0->depth]);
    w = init_last_child__9TWindowDDFv(arg0);
    if (w != NULL) {
        if (*entry & 1) {
            *(f32 *)((s8 *)w + 0x38) = lbl_805DFB7C;
            if (arg0->objs[3] != NULL) {
                *(f32 *)((s8 *)arg0->objs[3] + 0x30) = lbl_805DFC0C;
                *(s32 *)((s8 *)arg0->objs[3] + 0x50) = TWindowDD__data_805DFB50;
            }
        } else {
            *(f32 *)((s8 *)w + 0x38) = TWindowDD__data_805DFB74;
            if (arg0->objs[3] != NULL) {
                *(f32 *)((s8 *)arg0->objs[3] + 0x30) = TWindowDD__data_805DFBFC;
                *(s32 *)((s8 *)arg0->objs[3] + 0x50) = TWindowDD__data_805DFB50;
            }
        }
    }
    child = arg0->child[arg0->depth];
    if (child != NULL) {
        if (*entry & 8) {
            set_item_pos__9TWindowDDFl(arg0, 0);
            TWindowDD__sub_80347FA0((s32)arg0, 1);
        } else if (*entry & 1) {
            set_pos_and_data__9TWindowDDFf(child, TWindowDD__data_805DFC10);
            *(f32 *)((s8 *)child + 0x38) = lbl_805DFB88;
            TWindowDD__sub_80347F48((u8 *)arg0);
        } else {
            set_pos_and_data__9TWindowDDFf(child, lbl_805DFB80);
            *(f32 *)((s8 *)child + 0x38) = lbl_805DFB88;
            init_entry_field_64__9TWindowDDFl(arg0, 1);
        }
        if (*prev & 2) {
            pop_entry__9TWindowDDFv(arg0->fC4);
            TWindowDD__sub_80347CC8(arg0, arg0->fC4);
        }
    }
    set_item_pos__9TWindowDDFl(arg0, 1);
    if (!(*entry & 2)) {
        TWindowDD__sub_80347FA0((s32)arg0, 3);
    }
    if (*entry & 4) {
        if (arg0->fBC > 0) {
            TWindowDD__sub_80347FA0((s32)arg0, arg0->fBC + 3);
        }
    }
    id = ((s16 *)entry)[2];
    if (id == -1) {
        TWindowDD__sub_80347FA0((s32)arg0, 2);
    } else {
        setup_entry__9TWindowDDFl(arg0, id);
        init_entry_field_64__9TWindowDDFl(arg0, 2);
    }
    arg0->fAC = 2;
}

void TWindowDD__sub_803434F4(u8 *arg0) {
    u8 *var_r31;
    u8 *var_r3;
    u8 *var_r4;
    u8 *var_r5;
    var_r31 = arg0;
    var_r3 = (u8 *)(var_r31 + (*(s32 *)((s8 *)arg0 + 0x20) * 4));
    var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 0x24));
    free_child__9TWindowDDFv((int)var_r3);
    var_r3 = var_r31;
    var_r4 = (u8 *)(var_r31 + (*(s32 *)((s8 *)var_r31 + 0x20) * 4));
    var_r4 = (u8 *)(*(u8 **)((s8 *)var_r4 + 0x24));
    apply_input__9TWindowDDFPvPv((int)var_r3, (int)var_r4);
    var_r3 = var_r31;
    var_r5 = (u8 *)(*(u8 **)((s8 *)var_r31 + 0xB0));
    var_r4 = (u8 *)(var_r31 + (*(s32 *)((s8 *)var_r31 + 0x20) * 4));
    *(u8 **)((s8 *)var_r4 + 0x44) = var_r5;
    var_r4 = (u8 *)((void *) *(s32 *)((s8 *)var_r31 + 0x20));
    *(s32 *)((s8 *)var_r31 + 0x20) = (s32)(var_r4 + 1);
    var_r4 = (u8 *)(var_r31 + (*(s32 *)((s8 *)var_r31 + 0x20) * 4));
    var_r4 = (u8 *)(*(u8 **)((s8 *)var_r4 + 0x24));
    update__9TWindowDDFl((int)var_r3, (int)var_r4, (int)var_r5);
    var_r3 = (u8 *)(*(u8 **)((s8 *)var_r31 + 0xB4));
    *(u8 **)((s8 *)var_r31 + 0xB0) = var_r3;
    var_r3 = (u8 *)(*(u8 **)((s8 *)var_r31 + 0x8C));
    *(u8 **)((s8 *)var_r31 + 0x88) = var_r3;
    var_r3 = (u8 *)(*(u8 **)((s8 *)var_r31 + 0x90));
    *(u8 **)((s8 *)var_r31 + 0x8C) = var_r3;
    *(u8 **)((s8 *)var_r31 + 0x90) = (unsigned char *) ((void *)-1);
}

void TWindowDD__sub_803435A0(u8 *arg0) {
    s32 *temp_r29;
    s32 *temp_r31;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r3_5;
    s32 temp_r4;
    u8 *temp_r3;
    u8 *window_dd;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    temp_r0 = *(s32 *)((s8 *)arg0 + 0xB4);
    if ((temp_r0 == 0x14) || (temp_r0 == 0xC)) {
        build_player_word_lists__9TWindowDDFv();
    }
    *(s32 *)((s8 *)arg0 + 0xB8) = 0;
    if (*(s32 *)((s8 *)arg0 + 0xB4) == 1 || *(s32 *)((s8 *)arg0 + 0xB4) == 2 || *(s32 *)((s8 *)arg0 + 0xB4) == 8 || *(s32 *)((s8 *)arg0 + 0xB4) == 0xF || *(s32 *)((s8 *)arg0 + 0xB4) == 0x11) {
        reset_index__9TWindowDDFv(arg0 + 0xC4);
    }
    temp_r29 = get_entry__9TWindowDDFii(arg0, *(s32 *)((s8 *)arg0 + 0xB0));
    temp_r31 = get_entry__9TWindowDDFii(arg0, *(s32 *)((s8 *)arg0 + 0xB4));
    temp_r3 = arg0 + *(s32 *)((s8 *)arg0 + 0x20) * 4;
    temp_r3 = *(u8 **)((s8 *)temp_r3 + 0x24);
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)temp_r3 + 0x30) = (f32) lbl_805DFB90;
        *(f32 *)((s8 *)temp_r3 + 0x38) = (f32) TWindowDD__data_805DFB74;
        *(s32 *)((s8 *)temp_r3 + 0x50) = (s32) TWindowDD__data_805DFB50;
        if (*temp_r29 & 4) {
            temp_r4 = *(s32 *)((s8 *)arg0 + 0xBC);
            *(s32 *)((s8 *)arg0 + 0xBC) = (temp_r4 + 1);
            TWindowDD__sub_80347E04(arg0, temp_r4);
        }
    }
    window_dd = TWindowDD__sub_80347AD4(arg0, 1, *(s32 *)((s8 *)arg0 + 0x8C));
    if (window_dd != NULL) {
        set_pos_and_data__9TWindowDDFf(window_dd, TWindowDD__data_805DFB6C);
        if (*(s32 *)((s8 *)temp_r31 + 0) & 1) {
            *(f32 *)((s8 *)window_dd + 0x38) = (f32) lbl_805DFB7C;
            temp_r3_3 = (unsigned char *) (*(void **)((s8 *)arg0 + 0x80));
            if (temp_r3_3 != NULL) {
                *(f32 *)((s8 *)temp_r3_3 + 0x30) = (f32) lbl_805DFC0C;
                *(s32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x80)) + 0x50) = (s32) TWindowDD__data_805DFB50;
            }
        } else {
            *(f32 *)((s8 *)window_dd + 0x38) = (f32) TWindowDD__data_805DFB74;
            temp_r3_4 = (unsigned char *) (*(void **)((s8 *)arg0 + 0x80));
            if (temp_r3_4 != NULL) {
                *(f32 *)((s8 *)temp_r3_4 + 0x30) = (f32) TWindowDD__data_805DFBFC;
                *(s32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x80)) + 0x50) = (s32) TWindowDD__data_805DFB50;
            }
        }
        if (*(s32 *)((s8 *)temp_r31 + 0) & 2) {
            TWindowDD__sub_80347A4C((arg0), (s32)window_dd);
        }
    }
    temp_r3_5 = *(s32 *)((s8 *)temp_r31 + 0);
    if (!(temp_r3_5 & 8)) {
        if (temp_r3_5 & 1) {
            *(s32 *)((s8 *)arg0 + 0x90) = dispatch_state__9TWindowDDFv(arg0, (int) (*(s32 *)((s8 *)arg0 + 0xB4)), (int) (*(s32 *)((s8 *)arg0 + 0x8C)), 0);
            if ((temp_r3 = TWindowDD__sub_80347AD4(arg0, 2, *(s32 *)((s8 *)arg0 + 0x90))) != NULL) {
                set_pos_and_data__9TWindowDDFf(temp_r3, TWindowDD__data_805DFC10);
            }
            TWindowDD__sub_80347F48((arg0));
        } else {
            *(s32 *)((s8 *)arg0 + 0x90) = dispatch_state__9TWindowDDFv(arg0, (int) (*(s32 *)((s8 *)arg0 + 0xB4)), (int) (*(s32 *)((s8 *)arg0 + 0x8C)), 0);
            if ((temp_r3 = TWindowDD__sub_80347AD4(arg0, 2, *(s32 *)((s8 *)arg0 + 0x90))) != NULL) {
                set_pos_and_data__9TWindowDDFf(temp_r3, lbl_805DFB80);
            }
            init_entry_field_64__9TWindowDDFl(arg0, 1);
        }
    } else {
        TWindowDD__sub_80347FA0((s32)arg0, 1);
    }
    if ((s16) *(s16 *)((s8 *)temp_r31 + 4) == -1) {
        TWindowDD__sub_80347FA0((s32)arg0, 2);
    } else {
        setup_entry__9TWindowDDFl(arg0, *(s16 *)((s8 *)temp_r31 + 4));
        init_entry_field_64__9TWindowDDFl(arg0, 2);
    }
    *(s32 *)((s8 *)arg0 + 0xAC) = 1;
}

void run_state__9TWindowDDFPv(u8 *window_dd) {
    switch (*(u32 *)((s8 *)window_dd + 0xB0)) {
    case 0:
        handle_confirm_input__9TWindowDDFv(window_dd);
        return;
    case 1:
    case 2:
        update__9TWindowDDFv(window_dd);
        return;
    case 3:
        TWindowDD__sub_80342D14((window_dd));
        return;
    case 5:
        update_transition__9TWindowDDFv(window_dd);
        return;
    case 6:
        update_layout__9TWindowDDFv(window_dd);
        return;
    case 7:
        update_dispatch__9TWindowDDFv(window_dd);
        return;
    case 8:
        enter_state_9__9TWindowDDFv(window_dd);
        return;
    case 9:
        TWindowDD__sub_803429B0((window_dd));
        return;
    case 12:
        update__9TWindowDDFi((s32)window_dd);
        return;
    case 13:
        TWindowDD__sub_80342800((window_dd));
        return;
    case 14:
        update_state__9TWindowDDFPv((window_dd));
        return;
    case 15:
        enter_state_16__9TWindowDDFPv((window_dd));
        return;
    case 17:
        enter_state_18__9TWindowDDFv(window_dd);
        return;
    case 18:
        enter_state_19__9TWindowDDFv(window_dd);
        return;
    case 20:
        handle_input__9TWindowDDFi((s32)window_dd);
        return;
    case 10:
    case 11:
    case 16:
    case 19:
        TWindowDD__sub_80342428((window_dd));
    default:
        return;
    }
}

void run_task__9TWindowDDFv(u8 *arg0) {
    Win_803438C4 *w = (Win_803438C4 *)arg0;
    Sub_803438C4 *cur;
    s32 done;
    if (w->x80 != 0) {
        if (w->xB0 == 0) {
            set_clamped_page__9TWindowDDFl(w->x80, 2);
        } else if (w->xC4 > 1) {
            set_clamped_page__9TWindowDDFl(w->x80, 0);
        } else {
            set_clamped_page__9TWindowDDFl(w->x80, 1);
        }
    }
    cur = w->subs[w->idx];
    if (w->x7C != 0 && cur != NULL) {
        set_value_f32__9TWindowDDFl(w->x7C, TWindowDD__sub_8034217C((int)cur));
    }
    switch (w->xA8) {
    case 2:
        break;
    case 1:
        handle_input__9TWindowDDFv(w->x80);
        done = 0;
        if (test_input_flag_4__9TWindowDDFv(w) != 0) {
            if (w->x80 != 0) {
                switch (TWindowDD__sub_80340820(w->x80)) {
                case 0:
                    play_sound__9TWindowDDFv();
                    TWindowDD__sub_803484C4(w);
                    copy_chat_entry__9TWindowDDFPvPv((R_80343BC0 *)(w->xC0), (R_80343BC0 *)(&w->xE0));
                    break;
                case 1:
                    play_se__9TWindowDDFv();
                    done = 1;
                    w->x94 |= 2;
                    break;
                case 2:
                    play_se__9TWindowDDFv();
                    set_state__9TWindowDDFv(w);
                    break;
                }
            }
        } else if (TWindowDD__sub_803482B0(w) != 0) {
            play_se__9TWindowDDFv();
            done = 1;
            w->x94 |= 2;
        } else if (apply_both_choices__9TWindowDDFll(w->input, 0x40) != 0) {
            spawn_window__9TWindowDDFv();
            done = 1;
        }
        if (done != 0) {
            w->xA8 = 0;
            TWindowDD__sub_80340910(w->x80);
            TWindowDD__sub_80341AF8((int)cur);
            if (w->xC4 > 0) {
                TWindowDD__sub_80347CC8(w, &w->xC4);
            }
        }
        break;
    case 0:
        switch (w->xAC) {
        case 0:
            if (w->xB8 != 1 && TWindowDD_check_input_mask(w->input, 0x80) != 0) {
                spawn_window__9TWindowDDFv();
                w->xA8 = 1;
                set_clamped_selection__9TWindowDDFl(w->x80, get_cursor_index__9TWindowDDFv((int)w->subs[w->idx]));
                TWindowDD__sub_80341AE0((int)cur);
                copy_chat_entry__9TWindowDDFPvPv((R_80343BC0 *)(&w->xE0), (R_80343BC0 *)(&w->xC4));
                if (w->xE0 > 0) {
                    w->xE0--;
                    TWindowDD__sub_80347CC8(w, &w->xE0);
                }
            } else {
                run_state__9TWindowDDFPv((u8 *)w);
                w->x94 = 0;
            }
            break;
        case 1:
            if (w->subs[w->idx + 1] != NULL && w->subs[w->idx + 1]->x50 == 0) {
                TWindowDD__sub_803434F4((u8 *)w);
                w->xAC = 0;
            }
            break;
        case 2:
            if (w->subs[w->idx]->x50 == 0) {
                pop_menu_level__9TWindowDDFPv((TWindowDD_803431C0 *)(w));
                w->xAC = 0;
            }
            break;
        }
        break;
    }
}

#pragma push
#pragma optimization_level 1
void copy_chat_entry__9TWindowDDFPvPv(R_80343BC0 *arg0, R_80343BC0 *arg1) {
    u32 a, b;
    arg0->a = arg1->a;
    arg0->b = arg1->b;
    b = arg1->w[0]; a = arg1->w[1]; arg0->w[0] = b; arg0->w[1] = a;
    b = arg1->w[2]; a = arg1->w[3]; arg0->w[2] = b; arg0->w[3] = a;
    arg0->w[4] = arg1->w[4];
    arg0->w[5] = arg1->w[5];
}
#pragma pop

void *__dt__9TWindowDDFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__9TWindowDD;
        close_all_windows__9TWindowDDFv(arg0);
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern u32 window_dd_buffer_a;
extern u32 window_dd_buffer_b;
extern u32 TWindowDD__player_name_buffers;
extern u32 lbl_805D6E20;
extern u32 lbl_805D6E50;
extern u32 lbl_805D6E54;
extern u32 lbl_805D6E58;
extern u32 lbl_805D6E5C;
extern u32 TWindowDD__ws_data_buffer;

typedef struct Obj_80343C64 Obj_80343C64;
typedef struct V2_80343C64 V2_80343C64;
typedef struct Win_80343C64 Win_80343C64;
#pragma opt_common_subs off
Obj_80343C64 *TWindowDD__ct(Obj_80343C64 *self, void *parent, void *arg2) {
  V2_80343C64 a;
  V2_80343C64 b;
  u8 *p;
  s32 floor;
  s32 v;
  __ct__7TObjectFP7TObject(self);
  self->vt = ((void * *)&__vt__9TWindowDD);
  self->f0 = word_select_type_name_pointer;
  self->f1C = (floor = lbl_805D6E24);
  build_item_list__9TWindowDDFPv((u8 *)self);
  *((u8 *) TWindowDD__work_buffer) = 0;
  self->fA0 = 0;
  {
    p = (u8 *) get_player_by_client_id(local_client_id);
    if (p != 0)
    {
      floor = get_current_floor();
      s32 r;
      v = ((TObjBase *)p)->get_room();
      if (is_boss_area() != 0)
      {
        r = check_all_ready__9TWindowDDFl(floor);
      }
      else
      {
        r = is_room_free_of_active_enemies(floor, v);
      }
      if (r == 0)
      {
        self->fA0 = 1;
      }
    }
  }
  build_player_word_lists__9TWindowDDFv();
  self->fC0 = arg2;
  init_item_slots__9TWindowDDFv(self->fC4);
  init_item_slots__9TWindowDDFv(self->fE0);
  self->f7C = TWindowDD__sub_80340F70();
  {
    s32 i;
    for (i = 0; i < 8; i++)
    {
      self->a24[i] = 0;
      self->a44[i] = 0;
    }
  }
  self->f20 = 0;
  self->f88 = TWindowDD__sub_80346DB8((s32) self);
  self->f8C = -1;
  self->f90 = -1;
  {
    s32 w = TWindowDD__sub_80342384(self->f88, (s32) lbl_805DFB54);
    if (w != 0)
    {
      set_default_positions__9TWindowDDFiPv(self, w);
      self->a24[0] = w;
    }
  }
  self->a44[0] = 0;
  p = (u8 *) TWindowDD__sub_80342384(self->f8C, (s32) lbl_805DFB54);
  if (p != 0)
  {
    init_layout__9TWindowDDFiPv(self, (s32) p);
    self->a24[1] = (s32) p;
  }
  if (!lbl_805D6E68)
  {
    lbl_805D6E64 = lbl_8047863C;
    lbl_805D6E68 = 1;
  }
  if (!lbl_805D6E70)
  {
    lbl_805D6E6C = lbl_80478644;
    lbl_805D6E70 = 1;
  }
  {
    s32 i;
    for (i = 0; i < 6; i++)
    {
      self->a64[i] = 0;
    }
  }
  {
    a.x = lbl_805DFBA4;
    a.y = lbl_805DFBA8;
    b.x = lbl_805DFB60;
    b.y = lbl_805DFBA8;
    self->a64[0] = ((s32 (*)(f32, V2_80343C64 *, V2_80343C64 *, s32, s32)) TWindowDD__sub_8034146C)(lbl_805DFBAC, &a, &b, (s32) lbl_805D6E64, 4);
  }
  {
    a.x = lbl_805DFBB0;
    a.y = lbl_805DFBB4;
    b.x = lbl_805DFB64;
    b.y = lbl_805DFBB4;
    self->a64[1] = ((s32 (*)(f32, V2_80343C64 *, V2_80343C64 *, s32, s32)) TWindowDD__sub_8034146C)(lbl_805DFBB8, &a, &b, (s32) lbl_805D6E6C, 4);
  }
  {
    a.x = lbl_805DFBD0;
    a.y = lbl_805DFBD4;
    b.x = lbl_805DFBD0;
    b.y = lbl_805DFB68;
    void *q = (void *) ((s32 (*)(f32, V2_80343C64 *, V2_80343C64 *, s32, s32)) TWindowDD__sub_8034146C)(lbl_805DFBD8, &a, &b, TWindowDD__sub_80348B70(0x687), 5);
    self->a64[2] = (s32) q;
    if (q != 0)
    {
      TWindowDD__sub_803412A0((u8 *)q);
    }
  }
  ((void (*)(void *, u32, u16)) update_state__9TWindowDDFv)(self->fC4, TWindowDD__work_buffer, local_client_id);
  {
    a.x = lbl_805DFBF0;
    a.y = lbl_805DFBF4;
    b.x = lbl_805DFB60;
    b.y = lbl_805DFBF4;
    p = (u8 *) ((s32 (*)(f32, V2_80343C64 *, V2_80343C64 *, s32, s32)) TWindowDD__sub_8034146C)(lbl_805DFBF8, &a, &b, TWindowDD__work_buffer, 0);
    self->a64[3] = (s32) p;
    if (p != 0)
    {
      TWindowDD__sub_803412A0(p);
      ((TWindowDD_WS_String *)p)->update_position(0);
      ((Win_80343C64 *) p)->f30 = lbl_805DFB60;
      ((Win_80343C64 *) p)->f40 = lbl_805DFB60;
      ((Win_80343C64 *) p)->f34 = lbl_805DFBF4;
      ((Win_80343C64 *) p)->f44 = lbl_805DFBF4;
      ((Win_80343C64 *) p)->f38 = lbl_805DFCB8;
      ((Win_80343C64 *) p)->f48 = lbl_805DFCB8;
    }
  }
  self->f80 = create__9TWindowDDFv();
  self->f84 = 0;
  self->fA8 = 0;
  self->fAC = 0;
  self->fB0 = 0;
  self->fB4 = 0;
  self->fB8 = 0;
  self->fBC = 0;
  self->fFC = 0x37;
  self->f100 = 0;
  self->f94 = 0;
  self->f98 = 0;
  self->f9C = -1;
  self->fA4 = 0;
  self->f104 = 0;
  return self;
}

void free_buffers__9TWindowDDFv(void) {
    clear_window_dd_nodes();
    if ((u32) TWindowDD__word_select_lists != 0U) {
        mem_free((void*)TWindowDD__word_select_lists);
        TWindowDD__word_select_lists = 0U;
    }
    if ((u32) lbl_805D6E20 != 0U) {
        mem_free((void*)lbl_805D6E20);
        lbl_805D6E20 = 0U;
    }
    if ((u32) TWindowDD__player_name_buffers != 0U) {
        mem_free((void*)TWindowDD__player_name_buffers);
        TWindowDD__player_name_buffers = 0U;
    }
    if ((u32) window_dd_buffer_b != 0U) {
        mem_free((void*)window_dd_buffer_b);
        window_dd_buffer_b = 0U;
    }
    if ((u32) window_dd_buffer_a != 0U) {
        mem_free((void*)window_dd_buffer_a);
        window_dd_buffer_a = 0U;
    }
    if ((u32) TWindowDD__work_buffer != 0U) {
        mem_free((void*)TWindowDD__work_buffer);
        TWindowDD__work_buffer = 0U;
    }
    if ((u32) TWindowDD__ws_data_buffer != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)TWindowDD__ws_data_buffer));
        TWindowDD__ws_data_buffer = 0U;
    }
    if ((u32) lbl_805D6E5C != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)lbl_805D6E5C));
        lbl_805D6E5C = 0U;
    }
    if ((u32) lbl_805D6E58 != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)lbl_805D6E58));
        lbl_805D6E58 = 0U;
    }
    if ((u32) lbl_805D6E54 != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)lbl_805D6E54));
        lbl_805D6E54 = 0U;
    }
    if ((u32) lbl_805D6E50 != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)lbl_805D6E50));
        lbl_805D6E50 = 0U;
    }
}
struct DDPoint_80344114 { f32 x; f32 y; };
struct WordList_80344114 { u8 *words; s32 count; };
extern "C++" void ws_data_load(void);
void *mem_alloc(u32 size);
void *memset(void *dst, int c, u32 n);
extern u32 TWindowDD__ws_data_base;
extern u32 lbl_805D6E34;
extern DDPoint_80344114 TWindowDD__data_805434E8[][8];
extern const DDPoint_80344114 lbl_80478568[];
extern const f32 lbl_804785A0[];
extern const f32 TWindowDD__data_805DFB18;
extern const f32 lbl_805DFB24;
extern const f32 lbl_805DFB28;
void set_quad_corners_scaled__9TWindowDDFfff(DDPoint_80344114 *quad, f32 x, f32 y, f32 size);
void init_ws_data_tables__9TWindowDDFv(void);

void TWindowDD__sub_80344114(void) {
    s32 i;
    u8 *list;
    s32 j;
    WordList_80344114 *entry;
    const DDPoint_80344114 *src;
    DDPoint_80344114 *pt;
    f32 x;
    f32 y;
    f32 x2;
    f32 dy;

    TWindowDD__data_805D6E28 = 0;
    TWindowDD__ws_data_base = 0;
    TWindowDD__ws_data_table = 0;
    lbl_805D6E34 = 0;
    TWindowDD__data_805D6E40 = 0;
    TWindowDD__data_805D6E44 = 0;
    TWindowDD__data_805D6E48 = 0;
    lbl_805D6E4C = 0;
    lbl_805D6E50 = 0;
    lbl_805D6E54 = 0;
    lbl_805D6E58 = 0;
    lbl_805D6E5C = 0;
    TWindowDD__ws_data_buffer = 0;
    TWindowDD__window_mode = current_language;
    if (TWindowDD__window_mode < 0 || TWindowDD__window_mode >= 5) {
        TWindowDD__window_mode = 0;
    }
    ws_data_load();
    TWindowDD__work_buffer = (u32)mem_alloc(0x80);
    window_dd_buffer_a = (u32)mem_alloc(0x80);
    memset((void *)TWindowDD__work_buffer, 0, 0x80);
    memset((void *)window_dd_buffer_a, 0, 0x80);
    window_dd_buffer_b = (u32)mem_alloc(0x120);
    memset((void *)window_dd_buffer_b, 0, 0x120);
    TWindowDD__player_name_buffers = (u32)mem_alloc(0x30);
    for (i = 0; i < 12; i++) {
        ((char **)TWindowDD__player_name_buffers)[i] = (char *)window_dd_buffer_b + i * 0x18;
        ((char **)TWindowDD__player_name_buffers)[i][0] = 0;
    }
    lbl_805D6E20 = (u32)mem_alloc(0x100);
    TWindowDD__word_select_lists = (u32)mem_alloc(0x30);
    list = (u8 *)lbl_805D6E20;
    for (j = 0; j < 6; j++) {
        entry = &((WordList_80344114 *)TWindowDD__word_select_lists)[j];
        entry->words = list;
        entry->count = 0;
        switch (j) {
        case 0:
        case 1:
            list += 0x40;
            break;
        default:
            list += 0x20;
            break;
        }
    }
    lbl_805D6E24 = -1;
    for (i = 0; i < 6; i++) {
        src = &lbl_80478568[i];
        set_quad_corners_scaled__9TWindowDDFfff(TWindowDD__data_805434E8[i], src->x, src->y, lbl_804785A0[i]);
    }
    pt = TWindowDD__data_805434E8[6];
    x2 = lbl_80478568[6].x;
    y = lbl_80478568[6].y;
    x = x2 * TWindowDD__data_805DFB18;
    y *= TWindowDD__data_805DFB18;
    x2 = TWindowDD__data_805DFB18 * (x2 + lbl_805DFB24);
    dy = lbl_805DFB28 * TWindowDD__data_805DFB18;
    for (i = 0; i < 4; i++) {
        pt[0].x = x;
        pt[0].y = y;
        pt[1].x = x2;
        pt[1].y = y;
        y += dy;
        pt += 2;
    }
    init_ws_data_tables__9TWindowDDFv();
}

}
