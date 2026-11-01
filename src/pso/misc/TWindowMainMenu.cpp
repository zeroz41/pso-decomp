#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TWindowLockOn.h"
#include "pso/misc/TWindowMenuMainMenu.h"
#include "pso/misc/TWindowMainMenu4P.h"
#include "pso/misc/TWindowMainMenu.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowKeyBoardHard.h"
#include "pso/misc/TWindowSubEquip.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubTradeMain.h"

struct RecoveredGlobal_8026492C___vt__15TWindowMainMenu { s32 value; u8 remaining[0x24]; };

struct VBase_802647CC { char pad[0x18]; };

struct VObj_802647CC : VBase_802647CC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};

struct Ent_802647CC { u32 a; void *next; };

struct Menu_802647CC {
    u8 pad0[0x1C];
    u32 node;
    u8 pad20[0x4C - 0x20];
    s32 flags;
    s16 depth;
    s16 sel;
    u8 pad54[0x5C - 0x54];
    Ent_802647CC *ents;
};

struct Ent_802646E4 {
    s16 id;
    s16 pad[3];
};

struct Slot_802649C0 { s16 a; s16 b; s32 c; };

struct Win_802649C0 {
    s32 x0;
    u8 pad4[0x18 - 0x4];
    void *vt;
    s32 x1C;
    s32 x20;
    s32 x24;
    Slot_802649C0 slots[4];
    s32 x48;
    s32 x4C;
    s16 x50;
    s16 x52;
    s32 x54;
    u8 pad58[4];
    s32 x5C;
};

extern "C" {
s32 get_window_layout_position(int);
s32 TWindowMainMenu__sub_802ADADC(int, int);
s32 append_child_rows__15TWindowMainMenuFPvi(int, void *);
u32 create_menu__15TWindowMainMenuFPvPv(void *, int);
u8 * __dt__7TObjectFv(void *, s16);
void *get_player_by_client_id(s32 i);
void __dl__7TObjectFPv(s32);
extern RecoveredGlobal_8026492C___vt__15TWindowMainMenu __vt__15TWindowMainMenu;
void sub_80263D7C__15TWindowMainMenuFv(void *, int);
void update_keyboard_card_state__15TWindowMainMenuFv(void *, int);
int TWindowMainMenu__sub_802ADB00(u8 *arg0);
void populate_menu__15TWindowMainMenuFPvPv(u8 *arg0, Ent_802646E4 *arg1);
void *__ct__7TObjectFP7TObject(void *);
extern s32 lbl_805D3950;
Win_802649C0 *TWindowMainMenu__ct(Win_802649C0 *arg0, void *arg1, s32 arg2);
int park_selection__15TWindowMainMenuFPv(void*);
s32 is_split_screen();

void TWindowMainMenu4P::show_child_window() { if (*(unsigned int*)((char*)this + 0x1c) != 0) { window_request_show(*(void**)((char*)this + 0x1c)); ((TWindowMainMenu *)(*(void**)((char*)this + 0x1c)))->update_scaled_position(); } }
void TWindowMainMenu::update_trade_submenu() { void* m = *(void**)((char*)this + 0x1c); if (m) ((TWindowLockOn *)m)->request_close(); }
void TWindowMainMenu::update_submenu() {
    if ((u32) *(u32 *)((s8 *)this + 0x1C) != 0U) {
        park_selection__15TWindowMainMenuFPv((void*)(*(void **)((s8 *)this + 0x1C)));
        ((TWindowMainMenu *)(*(u32 *)((s8 *)this + 0x1C)))->update_scaled_position();
    }
    if (is_split_screen() != 0) {
        update_trade_submenu();
    }
}
void TWindowMainMenu::close_submenu(void* a1) { if (*(unsigned int*)((char*)this + 0x1c) != 0) { ((TWindowMainMenu *)(*(void**)((char*)this + 0x1c)))->pop_level(); ((TWindowMainMenu *)(*(void**)((char*)this + 0x1c)))->clear_menu_flags(); populate_menu__15TWindowMainMenuFPvPv((u8 *)this, (Ent_802646E4 *)(a1)); } }
void TWindowMainMenu::refresh_submenu(void* a1) { if (*(unsigned int*)((char*)this + 0x1c) != 0) { park_selection__15TWindowMainMenuFPv(*(void**)((char*)this + 0x1c)); ((TWindowMainMenu *)(*(void**)((char*)this + 0x1c)))->clear_menu_flags(); populate_menu__15TWindowMainMenuFPvPv((u8 *)this, (Ent_802646E4 *)(a1)); } }

void TWindowMainMenu::close() { if (*(unsigned int*)((char*)this + 0x1c) != 0) { ((TWindowBase *)(*(void**)((char*)this + 0x1c)))->close(); *(int*)((char*)this + 0x1c) = 0; } }

void TWindowMainMenu::open_menu_with_entry(s16 arg1) {
    u32 temp_r31;
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x1C) == 0U) {
        *(u32 *)((s8 *)((u8 *)this) + 0x1C) = create_menu__15TWindowMainMenuFPvPv((void *)(get_window_layout_position(0x1A)), (int) (*(s32 *)((s8 *)((u8 *)this) + 0x54)));
    }
    temp_r31 = *(u32 *)((s8 *)((u8 *)this) + 0x1C);
    append_child_rows__15TWindowMainMenuFPvi((int)temp_r31, (void *)arg1);
    TWindowMainMenu__sub_802ADADC(temp_r31, 0);
    this->update_submenu();
}

void populate_menu__15TWindowMainMenuFPvPv(u8 *window_main_menu, Ent_802646E4 *arg1) {
    s32 flag;
    s16 id;
    s32 i;
    int w;
    s32 d;
    if (*(u32 *)(window_main_menu + 0x1C) == 0) {
        *(u32 *)(window_main_menu + 0x1C) = create_menu__15TWindowMainMenuFPvPv((void *)get_window_layout_position(0x1A), *(s32 *)(window_main_menu + 0x54));
        *(s32 *)(window_main_menu + 0x48) = 0x1F;
    }
    w = *(int *)(window_main_menu + 0x1C);
    for (i = 0; i < 8; i++, arg1++) {
        id = arg1->id;
        if (id == 0x1F) {
            break;
        }
        if (((TWindowMainMenu *)window_main_menu)->filter_menu_entry(&id, &flag) != 0) {
            if (flag != 0) {
                append_child_rows__15TWindowMainMenuFPvi(w, (void *)(s32)id);
            } else {
                ((TWindowMainMenu *)w)->update_if_active(id);
            }
        }
    }
    ((TWindowMainMenu *)w)->update_scaled_position();
    TWindowMainMenu__sub_802ADADC(w, *(s16 *)(window_main_menu + 0x52));
    d = ((TWindowMainMenu *)w)->get_selected_item_type();
    ((TWindowMainMenu *)window_main_menu)->update_description_text(d);
}

void TWindowMainMenu::handle_menu_selection() {
    s32 id;
    u32 node;
    void *e;
    if ((((Menu_802647CC *)this)->flags & 1) && !(((Menu_802647CC *)this)->flags & 4) && (node = ((Menu_802647CC *)this)->node) != 0) {
        ((Menu_802647CC *)this)->sel = TWindowMainMenu__sub_802ADB00((u8 *)node);
        id = ((TWindowMainMenu *)node)->get_selected_item_type();
        update_description_text(id);
        if (((TWindowMenuMainMenu *)node)->get_menu_flag() != 0) {
            add_menu_entry(id);
            e = ((Menu_802647CC *)this)->ents[((Menu_802647CC *)this)->sel].next;
            if (e != 0) {
                ((Menu_802647CC *)this)->ents = (Ent_802647CC *)e;
                update_keyboard_card_state__15TWindowMainMenuFv(((Menu_802647CC *)this), ((Menu_802647CC *)this)->depth++);
                ((TWindowMainMenu *)((Menu_802647CC *)this))->refresh_submenu(((Menu_802647CC *)this)->ents);
                return;
            }
            close_child_window();
            this->update_submenu();
            create_submenu(id);
            return;
        }
        if (((TWindowMenuMainMenu *)node)->is_flag_set() != 0) {
            if (((Menu_802647CC *)this)->depth <= 0) {
                ((VObj_802647CC *)((Menu_802647CC *)this))->m6();
                return;
            }
            add_menu_entry(id);
            sub_80263D7C__15TWindowMainMenuFv(((Menu_802647CC *)this), ((Menu_802647CC *)this)->depth--);
            update_selection_value();
            ((TWindowMainMenu *)((Menu_802647CC *)this))->close_submenu(((Menu_802647CC *)this)->ents);
        }
    }
}

void TWindowMainMenu::render() {  }
void TWindowMainMenu::run_task() {  }

u8 *__dt__15TWindowMainMenuFv(u8 *arg0, s16 arg1) {
    u32 player;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__15TWindowMainMenu.value;
        if (*(s32 *)((s8 *)arg0 + 0x4C) & 1) {
            player = (u32)get_player_by_client_id(*(u32 *)((s8 *)arg0 + 0x54));
            if (player != 0U) {
                ((TObjPlayer *)player)->init_parts();
            }
        }
        ((TWindowMainMenu *)arg0)->close_child_window();
        ((TWindowMainMenu *)arg0)->destroy_submenu();
        ((TWindowMainMenu *)arg0)->close();
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

Win_802649C0 *TWindowMainMenu__ct(Win_802649C0 *arg0, void *arg1, s32 arg2) {
    s32 i;
    __ct__7TObjectFP7TObject(arg0);
    arg0->vt = &__vt__15TWindowMainMenu.value;
    arg0->x0 = lbl_805D3950;
    arg0->x54 = arg2;
    arg0->x4C = 0;
    arg0->x50 = 0;
    arg0->x52 = 0;
    arg0->x48 = 0x1F;
    for (i = 0; i < 4; i++) {
        arg0->slots[i].a = 0;
        arg0->slots[i].b = 0;
        arg0->slots[i].c = 0;
    }
    arg0->x1C = 0;
    arg0->x20 = 0;
    arg0->x24 = 0;
    arg0->x5C = 0;
    ((TWindowMainMenu *)arg0)->set_scale_f();
    return arg0;
}

void TWindowMainMenu::vfunc_7() {  }
void TWindowMainMenu::vfunc_9() {  }
}
int test_keyboard_card_flag4(void* p) { return TWindowKeyBoardHard::test_card_flag((s32)p, 4); }
