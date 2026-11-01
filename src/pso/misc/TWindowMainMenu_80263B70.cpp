#include "types.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/misc/TWindowBase.h"
#include "pso/map/FloorArea.h"
struct TWindowSubItem;
struct TWindowSubMag;
#include "pso/misc/TWindowSubEquip_80275C0C.h"
#include "pso/misc/TWindowSubEquip_80277E48.h"
#include "pso/misc/TWindowSubGameEnd.h"
#include "pso/misc/TWindowSubQuestBoard.h"
#include "pso/misc/TWindowSubSymbolChat_8028239C.h"
#include "pso/misc/TWindowSubTechnique.h"
#include "pso/unk/text_8027FCE4.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_80263A20.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowMainMenu.h"

extern "C" {

s32 get_player_by_client_id(s32);
struct Obj_80263D7C; struct Obj_80263DBC;
void destroy_submenu__15TWindowMainMenuFv(void* p);

void TWindowMainMenu::try_open_battle_menu(s16 arg1) {
    s32 spC;
    s16 sp8;
    s32 player;

    sp8 = arg1;
    player = get_player_by_client_id(*(s32 *)((s8 *)this + 0x54));
    if ((player != 0) && !(*(s32 *)((s8 *)this + 0x4C) & 1) && (filter_menu_entry(&sp8, &spC) != 0) && (spC != 0)) {
        *(s32 *)((s8 *)this + 0x4C) = (s32) (*(s32 *)((s8 *)this + 0x4C) | 1);
        *(s32 *)((s8 *)this + 0x5C) = 0;
        open_menu_with_entry(sp8);
        this->create_submenu(sp8);
        ((TObjPlayer *)player)->reset_equip_slots();
        this->vfunc_7();
    }
}

s32 TWindowMainMenu::close_active_submenu() {
    *(s32 *)((s8 *)this + 0x4C) = (s32) (*(s32 *)((s8 *)this + 0x4C) & 0xFFFFFFFB);
    ((s32 (*)())destroy_submenu__15TWindowMainMenuFv)();
    if ((u32) *(u32 *)((s8 *)this + 0x5C) == 0U) {
        this->vfunc_8();
        return 0;
    }
    *(s32 *)((s8 *)this + 0x48) = 0x1F;
    sub_80263D7C();
    update_selection_value();
    close_submenu((void*)(*(u32 *)((s8 *)this + 0x5C)));
    return 1;
}

}

struct Elt80263D94_80263d94_80263B70 { s16 f0; s16 f2; s32 f4; };

struct Obj_80263D7C { u8 pad[0x50]; s16 f50; u8 pad3[0x5c - 0x52]; s32 f5c; };

struct E_80263DBC { s16 a; s32 b; };

struct Obj_80263DBC { u8 pad[0x28]; E_80263DBC arr[4]; u8 pad2[0x50 - 0x48]; s16 f50; s16 f52; u8 pad3[0x5c - 0x54]; u32 f5c; };

extern "C" {

s32 populate_menu__15TWindowMainMenuFPvPv(void *, s32);
void close_child_window__15TWindowMainMenuFv(void* p);

s32 init_parts__10TObjPlayerFv();
void update_keyboard_card_state__15TWindowMainMenuFv(void *arg0);

void TWindowMainMenu::close_and_clear_flags() {
    s32 temp_r4;

    temp_r4 = *(s32 *)((s8 *)this + 0x4C);
    *(s32 *)((s8 *)this + 0x4C) = (s32) (temp_r4 & ~5);
    ((s32 (*)(void *, s32))close_child_window__15TWindowMainMenuFv)(this, temp_r4);
    destroy_submenu__15TWindowMainMenuFv(this);
    close();
    if (get_player_by_client_id((s32)(*(s32 *)((s8 *)this + 0x54))) != 0U) {
        init_parts__10TObjPlayerFv();
    }
}

void TWindowMainMenu::open(s32 arg1) {
    s32 player;
    s32 temp_r4;

    player = get_player_by_client_id((s32)(*(s32 *)((s8 *)this + 0x54)));
    if (player != 0) {
        temp_r4 = *(s32 *)((s8 *)this + 0x4C) | 1;
        *(s32 *)((s8 *)this + 0x4C) = temp_r4;
        *(s32 *)((s8 *)this + 0x5C) = arg1;
        *(s16 *)((s8 *)this + 0x50) = 0;
        ((s32 (*)(void *, s32))update_keyboard_card_state__15TWindowMainMenuFv)(this, temp_r4);
        populate_menu__15TWindowMainMenuFPvPv(this, *(s32 *)((s8 *)this + 0x5C));
        ((TObjPlayer *)player)->reset_equip_slots();
    }
}

void TWindowMainMenu::sub_80263D7C() {
    ((Obj_80263D7C *)this)->f5c = *(s32 *)((u8 *)((Obj_80263D7C *)this) + ((Obj_80263D7C *)this)->f50 * 8 + 0x2c);
}

void TWindowMainMenu::add_menu_entry(s16 arg1) {
    struct Elt80263D94_80263d94_80263B70 *arr = (struct Elt80263D94_80263d94_80263B70 *)this;
    struct Elt80263D94_80263d94_80263B70 *e = (struct Elt80263D94_80263d94_80263B70 *)((char *)&arr[*(s16 *)((s8 *)((u8 *)this) + 0x50)] + 0x28);
    e->f0 = (s16) *(s16 *)((s8 *)((u8 *)this) + 0x52);
    e->f2 = arg1;
    e->f4 = (s32) *(s32 *)((s8 *)((u8 *)this) + 0x5C);
}
void TWindowMainMenu::update_selection_value() {
    Obj_80263DBC *o = (Obj_80263DBC *)this;
    E_80263DBC *e = &o->arr[o->f50];
    if (e->b != o->f5c) {
        o->f52 = 0;
    } else {
        o->f52 = e->a;
    }
}

s32 is_quest_active();

s32 get_short_mail_ctrl__6TLobbyFv();
s32 is_trade_range_bit_set(s32);
extern s32 local_client_id;
u32 create__14TWindowMessageFllUls(u32, s32 *, s32, s32);

u32 get_window_layout_position(s32);
s32 call_if_split_screen(u32, s32);
s32 select_main_menu_item_10(s32);

void TWindowMainMenu::update_keyboard_card_state() {
    if (test_keyboard_card_flag4((void *)(*(s32 *)((s8 *)this + 0x54))) != 0) {
        *(s16 *)((s8 *)this + 0x52) = 0;
        return;
    }
    update_selection_value();
}

s32 TWindowMainMenu::filter_menu_entry(s16 *arg1, s32 *arg2) {
    u8 *base;
    u8 *p;
    s32 area;
    base = ((u8 *(*)(s32))get_player_by_client_id)(*(s32 *)((s8 *)((u8 *)this) + 0x54));
    if (base == NULL) {
        return 0;
    }
    p = base + 0x85C;
    if (p == NULL) {
        return 0;
    }
    *arg2 = 1;
    area = get_current_floor_area();
    switch (*arg1) {
    case 0:
    case 9:
    case 23:
        if (area == AREA_LOBBY) {
            *arg2 = 0;
        }
        break;
    case 26:
        if (get_main_phase() != 0xF) {
            *arg1 += 1;
            *arg2 = 0;
        } else if (is_trade_range_bit_set(local_client_id) == 0) {
            *arg2 = 0;
        }
        break;
    case 15:
        if (is_quest_active() != 1) {
            *arg2 = 0;
        }
        break;
    case 3:
        if (*(s32 *)((s8 *)p + 0x34) & 0x10) {
            return 0;
        }
        if (area == AREA_LOBBY || area == AREA_PIONEER2_EP1 || area == AREA_PIONEER2_EP2) {
            *arg1 = 4;
        }
        break;
    case 12:
        if (area == AREA_LOBBY || area == AREA_PIONEER2_EP1 || area == AREA_PIONEER2_EP2) {
            *arg2 = 0;
        }
        break;
    case 19:
        if (get_main_phase() != 0xF && get_short_mail_ctrl__6TLobbyFv() <= 0) {
            *arg2 = 0;
        }
        break;
    case 7:
        if (get_main_phase() == 0xF) {
            *arg1 = 8;
        }
        break;
    }
    if (*arg2 == 0) {
        *arg1 += 1;
    }
    return 1;
}

void TWindowMainMenu::sub_80263FE0() {
    toggle_help_window_on_button(*(s32 *)((s8 *)this + 0x24), *(s32 *)((s8 *)this + 0x54));
}

void TWindowMainMenu::close_child_window() { if (*(unsigned int*)((char*)this + 0x24) != 0) { ((TWindowBase *)(*(void**)((char*)this + 0x24)))->close(); *(int*)((char*)this + 0x24) = 0; } }

extern s32 lbl_8044F2E0[];
extern const f32 lbl_805DD13C;

void TWindowMainMenu::update_description_text(s32 arg1) {
    if ((s32) *(s32 *)((s8 *)this + 0x48) != arg1) {
        *(s32 *)((s8 *)this + 0x48) = arg1;
        if ((u32) *(u32 *)((s8 *)this + 0x24) == 0U) {
            u32 tmp = get_window_layout_position(0x1B);
            *(u32 *)((s8 *)this + 0x24) = create__14TWindowMessageFllUls(tmp, lbl_8044F2E0, 1, *(s32 *)((s8 *)this + 0x54));
            ((TWindowBase *)(*(u32 *)((s8 *)this + 0x24)))->set_depth(lbl_805DD13C);
            call_if_split_screen(*(u32 *)((s8 *)this + 0x24), *(s32 *)((s8 *)this + 0x54));
        }
        ((TWindowMessage *)(*(u32 *)((s8 *)this + 0x24)))->append_line(select_main_menu_item_10(arg1), 0x80);
    }
}

void TWindowMainMenu::destroy_submenu() { if (*(unsigned int *)&this->m_20 != 0) { queue_destruction__7TObjectFv(*(void* *)&this->m_20); *(int *)&this->m_20 = 0; } }

}

#include "pso/misc/TWindowMainMenu1P.h"

extern "C" {
void *__nw__7TObjectFUl(int);
void destroy_submenu__15TWindowMainMenuFv(void *);
s32 __ct__17TWindowSubAreaMapFP7TObjectPv(int, void *, int);
s32 __ct__17TWindowSubComCardFP7TObjectPv(int, void *, int);
void *TWindowSubItem__ct(TWindowSubItem *arg0, s32 arg1, s32 arg2);
s32 __ct__13TWindowSubLogFP7TObjectPv(int, void *, int);
void *TWindowSubMag__ct(TWindowSubMag *arg0, s32 arg1, s32 arg2);
s32 __ct__20TWindowSubQuestBoardFP7TObjectPv(int, void *, int);
s32 __ct__18TWindowSubShortCutFP7TObjectPv(int, void *, int);
s32 __ct__19TWindowSubShortMailFP7TObjectPv(int, void *, int);
s32 __ct__15TWindowSubTradeFP7TObjectPv(int, void *, int);
s32 __ct__19TWindowSubTradeMainFP7TObjectPv(int, void *, int);
s32 __ct__22TWindowSubTradeMessageFP7TObjectl(int, void *, int);
s32 __ct__26TWindowSubInformationBoardFP7TObjectPv(int, void *, int);
void *__ct__13TUnk_804E0B28FP7TObjectl(void *, void *, void *);

void TWindowMainMenu1P::create_char_select_slot() {
    void *o;
    destroy_submenu__15TWindowMainMenuFv(this);
    set_scale_f();
    o = __nw__7TObjectFUl(0x50);
    if (o != NULL) {
        o = __ct__13TUnk_804E0B28FP7TObjectl(o, this, this->m_54);
    }
    *(void * *)&this->m_20 = o;
}
void TWindowMainMenu::create_submenu(u32 arg1) {
    s32 temp_r3;
    s32 temp_r3_10;
    s32 window_sub_technique;
    s32 window_sub_symbol_chat;
    s32 temp_r3_13;
    s32 temp_r3_14;
    s32 temp_r3_15;
    s32 temp_r3_16;
    s32 temp_r3_17;
    s32 temp_r3_18;
    s32 window_sub_game_end;
    s32 temp_r3_2;
    s32 window_sub_equip;
    s32 window_sub_item;
    s32 window_sub_mag;
    s32 temp_r3_6;
    s32 temp_r3_7;
    s32 temp_r3_8;
    s32 temp_r3_9;
    s32 var_r0;
    s32 var_r0_10;
    s32 var_r0_11;
    s32 var_r0_12;
    s32 var_r0_13;
    s32 var_r0_14;
    s32 var_r0_15;
    s32 var_r0_16;
    s32 var_r0_17;
    s32 var_r0_18;
    s32 var_r0_19;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    s32 var_r0_6;
    s32 var_r0_7;
    s32 var_r0_8;
    s32 var_r0_9;
    *(s32 *)((s8 *)((u8 *)this) + 0x4C) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x4C) | 4);
    destroy_submenu__15TWindowMainMenuFv(this);
    set_scale_f();
    switch (arg1) {
    case 25:
        temp_r3 = ((s32)__nw__7TObjectFUl(0x2C));
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = (s32)construct_status_category_window((u8 *)temp_r3, (s32)this, (s32)(*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0;
        return;
    case 0:
    case 1:
        temp_r3_2 = ((s32)__nw__7TObjectFUl(0x38));
        var_r0_2 = temp_r3_2;
        if (var_r0_2 != 0) {
            var_r0_2 = (s32)TWindowSubEquip__sub_80275CB0((void *)temp_r3_2, (this), (*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0_2;
        return;
    case 9:
    case 10:
        window_sub_equip = ((s32)__nw__7TObjectFUl(0x3C));
        var_r0_3 = window_sub_equip;
        if (var_r0_3 != 0) {
            var_r0_3 = (s32)__ct__15TWindowSubEquipFll((TWindowSubEquip *)((u8 *)window_sub_equip), (s32)this, (*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0_3;
        return;
    case 11:
        window_sub_item = ((s32)__nw__7TObjectFUl(0x44));
        var_r0_4 = window_sub_item;
        if (var_r0_4 != 0) {
            var_r0_4 = (s32)TWindowSubItem__ct((TWindowSubItem *)((void *)window_sub_item), (s32)this, (*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0_4;
        return;
    case 23:
    case 24:
        window_sub_mag = ((s32)__nw__7TObjectFUl(0x50));
        var_r0_5 = window_sub_mag;
        if (var_r0_5 != 0) {
            var_r0_5 = (s32)TWindowSubMag__ct((TWindowSubMag *)((void *)window_sub_mag), (s32)this, (*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0_5;
        return;
    case 26:
    case 27:
    case 28:
        temp_r3_6 = ((s32)__nw__7TObjectFUl(0x38));
        var_r0_6 = temp_r3_6;
        if (var_r0_6 != 0) {
            var_r0_6 = __ct__15TWindowSubTradeFP7TObjectPv(temp_r3_6, this, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0_6;
        return;
    case 29:
        temp_r3_7 = ((s32)__nw__7TObjectFUl(0xA8));
        var_r0_7 = temp_r3_7;
        if (var_r0_7 != 0) {
            var_r0_7 = __ct__19TWindowSubTradeMainFP7TObjectPv(temp_r3_7, this, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0_7;
        return;
    case 30:
        temp_r3_8 = ((s32)__nw__7TObjectFUl(0x2C));
        var_r0_8 = temp_r3_8;
        if (var_r0_8 != 0) {
            var_r0_8 = __ct__22TWindowSubTradeMessageFP7TObjectl(temp_r3_8, this, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0_8;
        return;
    case 12:
    case 13:
        temp_r3_9 = ((s32)__nw__7TObjectFUl(0x28));
        var_r0_9 = temp_r3_9;
        if (var_r0_9 != 0) {
            var_r0_9 = __ct__17TWindowSubAreaMapFP7TObjectPv(temp_r3_9, this, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0_9;
        return;
    case 15:
    case 16:
        temp_r3_10 = ((s32)__nw__7TObjectFUl(0x30));
        var_r0_10 = temp_r3_10;
        if (var_r0_10 != 0) {
            var_r0_10 = __ct__20TWindowSubQuestBoardFP7TObjectPv(temp_r3_10, this, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0_10;
        return;
    case 3:
    case 4:
        window_sub_technique = ((s32)__nw__7TObjectFUl(0x40));
        var_r0_11 = window_sub_technique;
        if (var_r0_11 != 0) {
            var_r0_11 = (s32)TWindowSubTechnique__ct((TWindowSubTechnique *)((void *)window_sub_technique), (s32)this, (*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0_11;
        return;
    case 18:
        window_sub_symbol_chat = ((s32)__nw__7TObjectFUl(0x60));
        var_r0_12 = window_sub_symbol_chat;
        if (var_r0_12 != 0) {
            var_r0_12 = (s32)TWindowSubSymbolChat__ct((TWindowSubSymbolChat *)((void *)window_sub_symbol_chat), (s32)this, (*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0_12;
        return;
    case 14:
        temp_r3_13 = ((s32)__nw__7TObjectFUl(0x88));
        var_r0_13 = temp_r3_13;
        if (var_r0_13 != 0) {
            var_r0_13 = __ct__17TWindowSubComCardFP7TObjectPv(temp_r3_13, this, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0_13;
        return;
    case 21:
        temp_r3_14 = ((s32)__nw__7TObjectFUl(0x80));
        var_r0_14 = temp_r3_14;
        if (var_r0_14 != 0) {
            var_r0_14 = __ct__13TWindowSubLogFP7TObjectPv(temp_r3_14, this, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0_14;
        return;
    case 6:
        temp_r3_15 = ((s32)__nw__7TObjectFUl(0x30));
        var_r0_15 = temp_r3_15;
        if (var_r0_15 != 0) {
            var_r0_15 = (s32)TWindowSubQuestBoard__sub_8027CE74((u8 *)temp_r3_15, (u8 *)this, (s32)(*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0_15;
        return;
    case 19:
    case 20:
        temp_r3_16 = ((s32)__nw__7TObjectFUl(0x60));
        var_r0_16 = temp_r3_16;
        if (var_r0_16 != 0) {
            var_r0_16 = __ct__19TWindowSubShortMailFP7TObjectPv(temp_r3_16, this, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0_16;
        return;
    case 22:
        temp_r3_17 = ((s32)__nw__7TObjectFUl(0x914));
        var_r0_17 = temp_r3_17;
        if (var_r0_17 != 0) {
            var_r0_17 = __ct__26TWindowSubInformationBoardFP7TObjectPv(temp_r3_17, this, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0_17;
        return;
    case 17:
        temp_r3_18 = ((s32)__nw__7TObjectFUl(0x94));
        var_r0_18 = temp_r3_18;
        if (var_r0_18 != 0) {
            var_r0_18 = __ct__18TWindowSubShortCutFP7TObjectPv(temp_r3_18, this, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0_18;
        return;
    case 7:
    case 8:
        window_sub_game_end = ((s32)__nw__7TObjectFUl(0x2C));
        var_r0_19 = window_sub_game_end;
        if (var_r0_19 != 0) {
            var_r0_19 = (s32)TWindowSubGameEnd__ct((TWindowSubGameEnd *)((void *)window_sub_game_end), (s32)this, (*(s32 *)((s8 *)((u8 *)this) + 0x54)));
        }
        this->m_20 = var_r0_19;
    default:
        return;
    }
}

}
