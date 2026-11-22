#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/TWindowSubTrade.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/window/TWindowSubTradeMessage.h"
#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowMainMenu_80263AB0.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/window/TWindowMainMenu_802AD538.h"

struct TWindowSubItem;

struct TWindowSubMag;

#include "pso/unk/TUnk_804D1160.h"
#include "pso/ui/window/TWindowSubEquip_80277E48.h"
#include "pso/ui/window/TWindowSubGameEnd.h"
#include "pso/ui/window/TWindowSubQuestBoard.h"
#include "pso/ui/chat/TWindowSubSymbolChat_8028239C.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/window/TWindowSubTechnique.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/unk/TUnk_804D1AD0.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80263A20.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubEquip_80263AB0.h"
#include "pso/ui/window/TWindowSubEquip.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/ui/window/TWindowMenuMainMenu.h"
#include "pso/ui/window/TWindowMainMenu4P.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"

const char *TWindowMainMenu__name = "TWindowMainMenu";

extern const f32 lbl_8044F2E0[2] = {206.0f, 140.0f};
#include "pso/player/TObjPlayer_801AF2F0.h"

extern "C" {
s32 __ct__19TWindowSubShortMailFP7TObjectPv(int, void *, int);
struct Obj_80263D7C; struct Obj_80263DBC;
}

struct Elt80263D94_80263d94_80263B70 { s16 f0; s16 f2; s32 f4; };

struct Obj_80263D7C { u8 pad[0x50]; s16 f50; u8 pad3[0x5c - 0x52]; s32 f5c; };

struct E_80263DBC { s16 a; s32 b; };

struct Obj_80263DBC { u8 pad[0x28]; E_80263DBC arr[4]; u8 pad2[0x50 - 0x48]; s16 f50; s16 f52; u8 pad3[0x5c - 0x54]; u32 f5c; };
extern "C" {
s32 is_quest_active();
s32 is_trade_range_bit_set(s32);
extern s32 local_client_id;
uaddr get_window_layout_position(s32);
s32 select_main_menu_item_10(s32);
}

#include "pso/ui/window/TWindowMainMenu1P.h"
extern "C" {
s32 __ct__17TWindowSubAreaMapFP7TObjectPv(int, void *, int);
s32 __ct__17TWindowSubComCardFP7TObjectPv(int, void *, int);
void *TWindowSubItem__ct(TWindowSubItem *arg0, s32 arg1, s32 arg2);
s32 __ct__13TWindowSubLogFP7TObjectPv(int, void *, int);
void *TWindowSubMag__ct(TWindowSubMag *arg0, s32 arg1, s32 arg2);
s32 __ct__20TWindowSubQuestBoardFP7TObjectPv(int, void *, int);
s32 __ct__18TWindowSubShortCutFP7TObjectPv(int, void *, int);
s32 __ct__26TWindowSubInformationBoardFP7TObjectPv(int, void *, int);
void *__ct__13TUnk_804E0B28FP7TObjectl(void *, void *, void *);
}

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

extern "C" {
s32 TWindowMainMenu__sub_802ADADC(void *, int);
s32 append_child_rows__15TWindowMainMenuFPvi(void *, s32);
u32 create_menu__15TWindowMainMenuFPvPv(void *, int);
void populate_menu__15TWindowMainMenuFPvPv(u8 *arg0, TWindowMainMenuEntry *arg1);
int park_selection__15TWindowMainMenuFPv(void*);
}

int test_keyboard_card_flag4(void* p) { return TWindowKeyBoardHard::test_card_flag((saddr)p, 4); }
extern "C" {
void TWindowMainMenu::vfunc_9() {  }

void TWindowMainMenu::vfunc_7() {  }

TWindowMainMenu::TWindowMainMenu(TObject *parent, s32 client) : TObject(parent) {
    s32 i;
    m_name = TWindowMainMenu__name;
    client_index = client;
    m_4c = 0;
    m_50 = 0;
    m_52 = 0;
    m_48 = 0x1F;
    for (i = 0; i < 4; i++) {
        slots[i].first = 0;
        slots[i].second = 0;
        slots[i].value = 0;
    }
    m_1c = NULL;
    m_20 = 0;
    help_window = NULL;
    active_entries = NULL;
    set_scale_f();
}
}

TWindowMainMenu::~TWindowMainMenu() {
    TObjPlayer *player;
    if (*(s32 *)((s8 *)this + 0x4C) & 1) {
        player = get_player_by_client_id(*(u32 *)((s8 *)this + 0x54));
        if (player != 0) {
            player->init_parts();
        }
    }
    close_child_window();
    destroy_submenu();
    close();
}
extern "C" {
void TWindowMainMenu::run_task() {  }

void TWindowMainMenu::render() {  }

void TWindowMainMenu::handle_menu_selection() {
    s32 id;
    uaddr node;
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
                ((Menu_802647CC *)this)->depth++;
                update_keyboard_card_state();
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
            ((Menu_802647CC *)this)->depth--;
            sub_80263D7C();
            update_selection_value();
            ((TWindowMainMenu *)((Menu_802647CC *)this))->close_submenu(((Menu_802647CC *)this)->ents);
        }
    }
}

void populate_menu__15TWindowMainMenuFPvPv(u8 *window_main_menu, TWindowMainMenuEntry *arg1) {
    s32 flag;
    s16 id;
    s32 i;
    saddr w;
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
                append_child_rows__15TWindowMainMenuFPvi((void *)w, (s32)id);
            } else {
                ((TWindowMainMenu *)w)->update_if_active(id);
            }
        }
    }
    reinterpret_cast<TWindowMenuMainMenu *>(w)->update_scaled_position();
    TWindowMainMenu__sub_802ADADC(reinterpret_cast<void *>(w), *(s16 *)(window_main_menu + 0x52));
    d = ((TWindowMainMenu *)w)->get_selected_item_type();
    ((TWindowMainMenu *)window_main_menu)->update_description_text(d);
}

void TWindowMainMenu::open_menu_with_entry(s16 id) {
    u32 temp_r31;
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x1C) == 0U) {
        *(u32 *)((s8 *)((u8 *)this) + 0x1C) = create_menu__15TWindowMainMenuFPvPv((void *)(get_window_layout_position(0x1A)), (int) this->client_index);
    }
    temp_r31 = *(u32 *)((s8 *)((u8 *)this) + 0x1C);
    append_child_rows__15TWindowMainMenuFPvi((void *)(uaddr)temp_r31, (s32)id);
    TWindowMainMenu__sub_802ADADC((void *)(uaddr)temp_r31, 0);
    this->update_submenu();
}

void TWindowMainMenu::close() { if (*(unsigned int*)((char*)this + 0x1c) != 0) { ((TWindowBase *)(*(void**)((char*)this + 0x1c)))->close(); *(int*)((char*)this + 0x1c) = 0; } }

void TWindowMainMenu::refresh_submenu(void* a1) { if (*(unsigned int*)((char*)this + 0x1c) != 0) { park_selection__15TWindowMainMenuFPv(*(void**)((char*)this + 0x1c)); ((TWindowMainMenu *)(*(void**)((char*)this + 0x1c)))->clear_menu_flags(); populate_menu__15TWindowMainMenuFPvPv((u8 *)this, (TWindowMainMenuEntry *)(a1)); } }

void TWindowMainMenu::close_submenu(void* a1) { if (*(unsigned int*)((char*)this + 0x1c) != 0) { ((TWindowMainMenu *)(*(void**)((char*)this + 0x1c)))->pop_level(); ((TWindowMainMenu *)(*(void**)((char*)this + 0x1c)))->clear_menu_flags(); populate_menu__15TWindowMainMenuFPvPv((u8 *)this, (TWindowMainMenuEntry *)(a1)); } }

void TWindowMainMenu::update_submenu() {
    if ((u32) *(u32 *)((s8 *)this + 0x1C) != 0U) {
        park_selection__15TWindowMainMenuFPv((void*)(*(void **)((s8 *)this + 0x1C)));
        m_1c->update_scaled_position();
    }
    if (is_split_screen() != 0) {
        update_trade_submenu();
    }
}

void TWindowMainMenu::update_trade_submenu() { void* m = *(void**)((char*)this + 0x1c); if (m) ((TWindowLockOn *)m)->request_close(); }

void TWindowMainMenu::show_child_window() {
    if (m_1c != NULL) {
        window_request_show(m_1c);
        m_1c->update_scaled_position();
    }
}

void TWindowMainMenu::create_submenu(u32 id) {
    s32 temp_r3_10;
    saddr window_sub_technique;
    s32 temp_r3_13;
    s32 temp_r3_14;
    saddr temp_r3_15;
    s32 temp_r3_16;
    s32 temp_r3_17;
    s32 temp_r3_18;
    saddr window_sub_game_end;
    saddr temp_r3_2;
    saddr window_sub_equip;
    saddr window_sub_item;
    saddr window_sub_mag;
    s32 temp_r3_9;
    s32 var_r0_10;
    s32 var_r0_11;
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
    s32 var_r0_9;
    *(s32 *)((s8 *)((u8 *)this) + 0x4C) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x4C) | 4);
    destroy_submenu();
    set_scale_f();
    switch (id) {
    case 25:
        this->m_20 = (saddr)new TUnk_804D1AD0(this, this->client_index);
        return;
    case 0:
    case 1:
        temp_r3_2 = ((saddr)TObject::operator new(0x38));
        var_r0_2 = temp_r3_2;
        if (var_r0_2 != 0) {
            var_r0_2 = (saddr)TWindowSubEquip__sub_80275CB0((void *)temp_r3_2, (this), this->client_index);
        }
        this->m_20 = var_r0_2;
        return;
    case 9:
    case 10:
        window_sub_equip = ((saddr)TObject::operator new(0x3C));
        var_r0_3 = window_sub_equip;
        if (var_r0_3 != 0) {
            var_r0_3 = (saddr)__ct__15TWindowSubEquipFll((TWindowSubEquip *)((u8 *)window_sub_equip), (saddr)this, this->client_index);
        }
        this->m_20 = var_r0_3;
        return;
    case 11:
        window_sub_item = ((saddr)TObject::operator new(0x44));
        var_r0_4 = window_sub_item;
        if (var_r0_4 != 0) {
            var_r0_4 = (saddr)TWindowSubItem__ct((TWindowSubItem *)((void *)window_sub_item), (saddr)this, this->client_index);
        }
        this->m_20 = var_r0_4;
        return;
    case 23:
    case 24:
        window_sub_mag = ((saddr)TObject::operator new(0x50));
        var_r0_5 = window_sub_mag;
        if (var_r0_5 != 0) {
            var_r0_5 = (saddr)TWindowSubMag__ct((TWindowSubMag *)((void *)window_sub_mag), (saddr)this, this->client_index);
        }
        this->m_20 = var_r0_5;
        return;
    case 26:
    case 27:
    case 28:
        m_20 = reinterpret_cast<saddr>(new TWindowSubTrade(this, client_index));
        return;
    case 29:
        m_20 = reinterpret_cast<saddr>(new TWindowSubTradeMain(this, client_index));
        return;
    case 30:
        m_20 = reinterpret_cast<saddr>(new TWindowSubTradeMessage(this, client_index));
        return;
    case 12:
    case 13:
        temp_r3_9 = ((saddr)TObject::operator new(0x28));
        var_r0_9 = temp_r3_9;
        if (var_r0_9 != 0) {
            var_r0_9 = __ct__17TWindowSubAreaMapFP7TObjectPv(temp_r3_9, this, (int) this->client_index);
        }
        this->m_20 = var_r0_9;
        return;
    case 15:
    case 16:
        temp_r3_10 = ((saddr)TObject::operator new(0x30));
        var_r0_10 = temp_r3_10;
        if (var_r0_10 != 0) {
            var_r0_10 = __ct__20TWindowSubQuestBoardFP7TObjectPv(temp_r3_10, this, (int) this->client_index);
        }
        this->m_20 = var_r0_10;
        return;
    case 3:
    case 4:
        window_sub_technique = ((saddr)TObject::operator new(0x40));
        var_r0_11 = window_sub_technique;
        if (var_r0_11 != 0) {
            var_r0_11 = (saddr)TWindowSubTechnique__ct((TWindowSubTechnique *)((void *)window_sub_technique), (saddr)this, this->client_index);
        }
        this->m_20 = var_r0_11;
        return;
    case 18:
        this->m_20 = (saddr)new TWindowSubSymbolChat(this, this->client_index);
        return;
    case 14:
        temp_r3_13 = ((saddr)TObject::operator new(0x88));
        var_r0_13 = temp_r3_13;
        if (var_r0_13 != 0) {
            var_r0_13 = __ct__17TWindowSubComCardFP7TObjectPv(temp_r3_13, this, (int) this->client_index);
        }
        this->m_20 = var_r0_13;
        return;
    case 21:
        temp_r3_14 = ((saddr)TObject::operator new(0x80));
        var_r0_14 = temp_r3_14;
        if (var_r0_14 != 0) {
            var_r0_14 = __ct__13TWindowSubLogFP7TObjectPv(temp_r3_14, this, (int) this->client_index);
        }
        this->m_20 = var_r0_14;
        return;
    case 6:
        temp_r3_15 = ((saddr)TObject::operator new(0x30));
        var_r0_15 = temp_r3_15;
        if (var_r0_15 != 0) {
            var_r0_15 = (saddr)TWindowSubQuestBoard__sub_8027CE74((u8 *)temp_r3_15, (u8 *)this, (s32)this->client_index);
        }
        this->m_20 = var_r0_15;
        return;
    case 19:
    case 20:
        temp_r3_16 = ((saddr)TObject::operator new(0x60));
        var_r0_16 = temp_r3_16;
        if (var_r0_16 != 0) {
            var_r0_16 = __ct__19TWindowSubShortMailFP7TObjectPv(temp_r3_16, this, (int) this->client_index);
        }
        this->m_20 = var_r0_16;
        return;
    case 22:
        temp_r3_17 = ((saddr)TObject::operator new(0x914));
        var_r0_17 = temp_r3_17;
        if (var_r0_17 != 0) {
            var_r0_17 = __ct__26TWindowSubInformationBoardFP7TObjectPv(temp_r3_17, this, (int) this->client_index);
        }
        this->m_20 = var_r0_17;
        return;
    case 17:
        temp_r3_18 = ((saddr)TObject::operator new(0x94));
        var_r0_18 = temp_r3_18;
        if (var_r0_18 != 0) {
            var_r0_18 = __ct__18TWindowSubShortCutFP7TObjectPv(temp_r3_18, this, (int) this->client_index);
        }
        this->m_20 = var_r0_18;
        return;
    case 7:
    case 8:
        window_sub_game_end = ((saddr)TObject::operator new(0x2C));
        var_r0_19 = window_sub_game_end;
        if (var_r0_19 != 0) {
            var_r0_19 = (saddr)TWindowSubGameEnd__ct((TWindowSubGameEnd *)((void *)window_sub_game_end), (saddr)this, this->client_index);
        }
        this->m_20 = var_r0_19;
    default:
        return;
    }
}

void TWindowMainMenu1P::create_char_select_slot() {
    void *o;
    destroy_submenu();
    set_scale_f();
    o = TObject::operator new(0x50);
    if (o != NULL) {
        o = __ct__13TUnk_804E0B28FP7TObjectl(o, this, reinterpret_cast<void *>(client_index));
    }
    *(void * *)&this->m_20 = o;
}

void TWindowMainMenu::destroy_submenu() { if (*(unsigned int *)&this->m_20 != 0) { ((TObject *)(*(void* *)&this->m_20))->queue_destruction(); *(int *)&this->m_20 = 0; } }

void TWindowMainMenu::update_description_text(s32 id) {
    if ((s32) *(s32 *)((s8 *)this + 0x48) != id) {
        *(s32 *)((s8 *)this + 0x48) = id;
        if ((u32) *(u32 *)((s8 *)this + 0x24) == 0U) {
            u32 tmp = get_window_layout_position(0x1B);
            *(u32 *)((s8 *)this + 0x24) = (uaddr)TWindowMessage::create(tmp, lbl_8044F2E0, 1, this->client_index);
            ((TWindowBase *)(*(uaddr *)((s8 *)this + 0x24)))->set_depth(49999.0f);
            call_if_split_screen(*(u32 *)((s8 *)this + 0x24), this->client_index);
        }
        ((TWindowMessage *)(*(uaddr *)((s8 *)this + 0x24)))->append_line(select_main_menu_item_10(id), 0x80);
    }
}

void TWindowMainMenu::close_child_window() { if (*(unsigned int*)((char*)this + 0x24) != 0) { ((TWindowBase *)(*(void**)((char*)this + 0x24)))->close(); *(int*)((char*)this + 0x24) = 0; } }

void TWindowMainMenu::sub_80263FE0() {
    toggle_help_window_on_button(*(s32 *)((s8 *)this + 0x24), this->client_index);
}

s32 TWindowMainMenu::filter_menu_entry(s16 *arg1, s32 *arg2) {
    u8 *base;
    u8 *p;
    s32 area;
    base = (u8 *)get_player_by_client_id(this->client_index);
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
        if (get_main_phase() != 0xF && TLobby::get_short_mail_ctrl() <= 0) {
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

void TWindowMainMenu::update_keyboard_card_state() {
    if (test_keyboard_card_flag4((void *)(*(saddr *)((s8 *)this + 0x54))) != 0) {
        *(s16 *)((s8 *)this + 0x52) = 0;
        return;
    }
    update_selection_value();
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

void TWindowMainMenu::add_menu_entry(s16 id) {
    struct Elt80263D94_80263d94_80263B70 *arr = (struct Elt80263D94_80263d94_80263B70 *)this;
    struct Elt80263D94_80263d94_80263B70 *e = (struct Elt80263D94_80263d94_80263B70 *)((char *)&arr[*(s16 *)((s8 *)((u8 *)this) + 0x50)] + 0x28);
    e->f0 = (s16) *(s16 *)((s8 *)((u8 *)this) + 0x52);
    e->f2 = id;
    e->f4 = (s32) *(s32 *)((s8 *)((u8 *)this) + 0x5C);
}

void TWindowMainMenu::sub_80263D7C() {
    ((Obj_80263D7C *)this)->f5c = *(s32 *)((u8 *)((Obj_80263D7C *)this) + ((Obj_80263D7C *)this)->f50 * 8 + 0x2c);
}

void TWindowMainMenu::open(s32 arg1) {
    TObjPlayer *player;

    player = get_player_by_client_id((s32)this->client_index);
    if (player != 0) {
        *(s32 *)((s8 *)this + 0x4C) = *(s32 *)((s8 *)this + 0x4C) | 1;
        *(s32 *)((s8 *)this + 0x5C) = arg1;
        *(s16 *)((s8 *)this + 0x50) = 0;
        update_keyboard_card_state();
        populate_menu__15TWindowMainMenuFPvPv((u8 *)this, (TWindowMainMenuEntry *)*(saddr *)((s8 *)this + 0x5C));
        player->reset_equip_slots();
    }
}

void TWindowMainMenu::close_and_clear_flags() {
    void *player;

    *(s32 *)((s8 *)this + 0x4C) = (s32) (*(s32 *)((s8 *)this + 0x4C) & ~5);
    close_child_window();
    destroy_submenu();
    close();
    if ((player = (void *)get_player_by_client_id((s32)this->client_index)) != 0U) {
        ((TObjPlayer *)player)->init_parts();
    }
}

s32 TWindowMainMenu::close_active_submenu() {
    *(s32 *)((s8 *)this + 0x4C) = (s32) (*(s32 *)((s8 *)this + 0x4C) & 0xFFFFFFFB);
    destroy_submenu();
    if ((u32) *(u32 *)((s8 *)this + 0x5C) == 0U) {
        this->vfunc_8();
        return 0;
    }
    *(s32 *)((s8 *)this + 0x48) = 0x1F;
    sub_80263D7C();
    update_selection_value();
    close_submenu((void*)(*(uaddr *)((s8 *)this + 0x5C)));
    return 1;
}

void TWindowMainMenu::try_open_battle_menu(s16 key) {
    s32 spC;
    s16 sp8;
    TObjPlayer *player;

    sp8 = key;
    player = get_player_by_client_id(this->client_index);
    if ((player != 0) && !(*(s32 *)((s8 *)this + 0x4C) & 1) && (filter_menu_entry(&sp8, &spC) != 0) && (spC != 0)) {
        *(s32 *)((s8 *)this + 0x4C) = (s32) (*(s32 *)((s8 *)this + 0x4C) | 1);
        *(s32 *)((s8 *)this + 0x5C) = 0;
        open_menu_with_entry(sp8);
        this->create_submenu(sp8);
        ((TObjPlayer *)player)->reset_equip_slots();
        this->vfunc_7();
    }
}

void TWindowSubEquip::open_submenu(saddr arg0, s32 arg1) {
    s32 create_submenu__15TWindowMainMenuFUl(s32, s16);
    ((TWindowMainMenu *)arg0)->destroy_submenu();
    create_submenu__15TWindowMainMenuFUl(arg0, (s16)arg1);
}

void TWindowMainMenu::set_scale_f() { *(float*)((char*)this + 0x58) = 50300.0f; }

f32 TWindowSubEquip__sub_80263AF8(u8 *parent, u32 arg1) {
    return *(f32 *)((s8 *)parent + 0x58) - (f32) arg1;
}

void TWindowSubEquip__sub_80263AF4(void) {  }

void call_if_split_screen(uaddr object, s32 client_id) {
    if ((is_split_screen() != 0) && (object != 0U)) {
        fn_802449E0((u8 *)object);
    }
}
}
