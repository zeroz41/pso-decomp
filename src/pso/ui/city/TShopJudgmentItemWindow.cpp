#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/text_80104FCC.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/city/THunterGuildSeqOnlineTask_802156A0.h"
#include "pso/ui/window/TWindowShortListCtrl_80221828.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "types.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/item/TItem.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/TWindowLoadItemTexture.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/Language.h"
#include "pso/system/task/TObject.h"
#include <string.h>
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TPlyItem.h"
#include "pso/object/base/TObjBase.h"

const char *TShopJudgmentItemWindow__class_name = "TShopJudgmentItemWindow";
struct Ent_80221440 { s32 item; s32 idx; };

struct Win_80221440 {
    u8 pad00[0x1C];
    u8 pad1c[0x24 - 0x1C];
    u8 *player;
    u8 pad28[0x54 - 0x28];
    Ent_80221440 ents[30];
    u8 pad144[4];
    s32 count;
    u8 pad14c[0x154 - 0x14C];
    void *list;
};

extern "C" {
int obj_getPtr2B0_20(u8 *p);
}

s32 get_appraisal_text(s32 index);

extern "C" {
u8 *create_item_list_window(s32 arg0, s32 arg1, s32 arg2);
s32 try_spend_actor_meseta(u8 *player, s32 count);
void set_judgment_target_flag(void *window, void *arg1);

saddr get_window_layout_position(s32);
void send_6x25_equip_item(void *arg0, s32 arg1, s32 arg2);
void TItemData__clear_unidentified_flag(void *arg0);
u32 advance_item_id_counter(u16 client);
u32 __ct__15TWindowHelpItemFPvl(int, int, s32);
extern s32 local_client_id;
s32 play_sound_effect(s32, s32, s32, s32);
void __dl__7TObjectFPv(void *);
}

TShopJudgmentItemWindow::TShopJudgmentItemWindow(void *arg1, void *arg2, void *arg3) : TShopWindowBase((TObject *)arg1) {
    m_name = TShopJudgmentItemWindow__class_name;
    this->m_144 = 0;
    this->m_148 = 0;
    this->m_150 = 0;
    *(void **)((s8 *)this + 0x24) = arg3;
    this->m_154 = 0;
    this->m_158 = 0;
    this->m_15c = 0;
    this->m_160 = 0;
    this->m_50 = 0;
    this->sequence = (TShopWindowBase *)arg2;
    this->m_16c = 0;
    this->m_170 = 0;
    this->m_174 = 0;
}

extern "C" {
TShopJudgmentItemWindow::~TShopJudgmentItemWindow() {
    if (m_154 != NULL) { ((TWindowBase *)m_154)->close(); m_154 = 0; }
    if (m_160 != NULL) { ((TWindowBase *)m_160)->close(); m_160 = 0; }
    if (m_158 != NULL) { ((TWindowBase *)m_158)->close(); m_158 = 0; }
    if (m_50 != NULL) { ((TObject *)m_50)->queue_destruction(); m_50 = 0; }
}

void TShopJudgmentItemWindow::vfunc_11() {
    u8 *arg0 = (u8 *)this;
    switch (this->m_20) {
    case 0:
        ((TShopJudgmentItemWindow *)arg0)->close();
        TShopJudgmentItemWindow::build_item_list(arg0);
        return;
    case 1:
        ((TShopJudgmentItemWindow *)arg0)->handle_input();
        return;
    case 2:
        ((TShopJudgmentItemWindow *)arg0)->handle_judge_confirm();
        return;
    case 3:
        ((TShopJudgmentItemWindow *)arg0)->create_result_windows();
        return;
    case 4:
        ((TShopJudgmentItemWindow *)arg0)->update_judge_confirm();
        return;
    case 5:
        ((TShopJudgmentItemWindow *)arg0)->update();
        return;
    case 6:
        ((TShopJudgmentItemWindow *)arg0)->handle_pay_confirm();
        return;
    case 7:
        ((TShopJudgmentItemWindow *)arg0)->handle_equip_prompt();
        return;
    case 10:
        ((TShopJudgmentItemWindow *)arg0)->invoke_callback_170_and_destroy();
        return;
    case 8:
        ((TShopJudgmentItemWindow *)arg0)->invoke_callback_16C_and_destroy();
        return;
    case 11:
        ((TShopJudgmentItemWindow *)arg0)->invoke_callback_174_and_destroy();
    default:
        return;
    }
}

void TShopJudgmentItemWindow::close() { if (this->m_50 != 0) { ((TObject *)(this->m_50))->queue_destruction(); this->m_50 = 0; } }
}

#define W ((Win_80221440 *)arg0)

extern "C" {
void TShopJudgmentItemWindow::build_item_list(void *arg0) {
    TItem *items[32];
    s32 n;
    s32 i;
    TItem *it;
    s32 j;
    s32 k;
    memset(W->ents, 0, 0xF0);
    n = ((TPlyItem *)(*(saddr *)(W->player + 0xD00)))->apply_shop_judgment(items);
    W->count = 0;
    for (i = 0; i < n; i++) {
        it = items[i];
        if (it != NULL && it->is_identified() == 0) {
            fn_80221838((u8 *)&W->ents[W->count++], (saddr)items[i], i);
        }
    }
    if (W->count != 0) {
        ((TShopWindowBase *)W)->set_field_20(1);
    } else {
        ((TShopJudgmentItemWindow *)arg0)->send_message(2, 1);
        ((TShopWindowBase *)W)->set_field_20(0xB);
        return;
    }
    if (W->list == NULL) {
        W->list = create_item_list_window(get_appraisal_text(0), W->count, ((TObjBase *)((saddr)W->player))->get_entity_id());
        for (j = 0; j < W->count; j++) {
            ((TShopJudgmentItemWindow *)(W->list))->add_list_entry(W->ents[j].item, j);
        }
        ((TWindowMenuIconLine *)W->list)->calc_content_extent();
        return;
    }
    ((TWindowMenuIconLine *)(W->list))->reset_list();
    for (k = 0; k < W->count; k++) {
        ((TShopJudgmentItemWindow *)(W->list))->add_list_entry(W->ents[k].item, k);
    }
    ((TWindowMenuIconLine *)W->list)->calc_content_extent();
    ((TWindowMenuIconLine *)((saddr)W->list))->clear_decided();
}
}

#undef W

extern "C" {
void TShopJudgmentItemWindow::handle_input() {

    if (sub_802239EC() != 0) {
        set_field_20(0xA);
        play_sound_effect(0x52D01, 0, 0, 0);
        return;
    }
    if (this->TShopWindowBase::sub_80223A48() != 0) {
        this->m_158 = (saddr)create_yes_no_window((const NJS_POINT2 *)get_window_layout_position(0x2B), ((TObjBase *)(this->m_24))->get_entity_id(), NULL, NULL);
        ((TWindowAddition *)(this->m_158))->set_position_xy(this->TShopWindowBase::get_scale(), this->TShopWindowBase::get_scale());
        send_message(3, 1);
        set_field_20(2);
        play_sound_effect(0x52D01, 0, 0, 0);
    }
}
}

#pragma push
#pragma fp_contract on

extern "C" {
void TShopJudgmentItemWindow::handle_judge_confirm() {
    s32 selected_menu_value;
    u8 *temp_r31;
    u8 *arg0 = (u8 *)this;
    if (((TShopJudgmentItemWindow *)arg0)->vfunc_10() != 0) {
        if ((*(void **)((s8 *)arg0 + 0x158) != NULL) && (((TWindowMenu *)(*(void **)((s8 *)arg0 + 0x158)))->is_decided() != 0)) {
            selected_menu_value = ((TWindowMenu *)this->m_158)->get_selected_value();
            if ((selected_menu_value == 0) && ((u32) this->m_154 != 0U)) {
                if (obj_getPtr2B0_20((u8 *)this->m_24) < 0x64) {
                    ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x158)))->close();
                    this->m_158 = 0U;
                    send_message(5, 1);
                    ((TShopWindowBase *)arg0)->set_field_20(0xB);
                    return;
                }
                temp_r31 = arg0 + (((TWindowMenuIconLine *)this->m_154)->get_cursor_value() * 8);
                if (((TItem *)(*(saddr *)((s8 *)temp_r31 + 0x54)))->copy_to_item_data((TItemData *)(arg0 + 0x3C)) != 0) {
                    *(s32 *)((s8 *)arg0 + 0x168) = ((TItem *)(*(saddr *)((s8 *)temp_r31 + 0x54)))->is_at_tekker();
                    ((TItemData *)(arg0 + 0x28))->copy_from((TItemData *)(arg0 + 0x3C));
                    update_item_appraisal((saddr)(arg0 + 0x28));
                    *(s32 *)((s8 *)arg0 + 0x14C) = 0x5F;
                    if (*(void **)((s8 *)arg0 + 0x154) != NULL) {
                        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x154)))->close();
                        this->m_154 = 0U;
                    }
                    play_cue_stream_file("j_kantei.adx");
                }
                ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x158)))->close();
                this->m_158 = 0U;
                send_message(6, 1);
                ((TShopWindowBase *)arg0)->set_field_20(3);
                return;
            }
            if (selected_menu_value == 1) {
                ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x158)))->close();
                this->m_158 = 0U;
                send_message(4, 1);
                ((TShopWindowBase *)arg0)->set_field_20(1);
                ((TWindowMenuIconLine *)(this->m_154))->clear_decided();
                return;
            }
            goto block_14;
        }
block_14:
        if ((*(void **)((s8 *)arg0 + 0x158) != NULL) && (((TWindowMenu *)(*(void **)((s8 *)arg0 + 0x158)))->is_cancelled() != 0)) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x158)))->close();
            this->m_158 = 0U;
            send_message(4, 1);
            ((TShopWindowBase *)arg0)->set_field_20(1);
            ((TWindowMenuIconLine *)(this->m_154))->clear_decided();
        }
    }
}
}

#pragma pop

extern "C" {
void TShopJudgmentItemWindow::create_result_windows() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    u32 var_r29;
    temp_r0 = *(s32 *)&this->_pad14C - 1;
    *(s32 *)&this->_pad14C = temp_r0;
    if (temp_r0 <= 0) {
        if ((u32) this->m_154 == 0U) {
            switch (current_language) {
            case LANGUAGE_JAPANESE:
                this->m_154 = (uaddr) create_item_list_window((saddr)"\x8A\xD3\x92\xE8\x8C\x8B\x89\xCA", 1, (((TObjBase *)(this->m_24))->get_entity_id()));
                break;
            case LANGUAGE_ENGLISH:
            case LANGUAGE_GERMAN:
            case LANGUAGE_FRENCH:
            case LANGUAGE_SPANISH:
            default:
                this->m_154 = (uaddr) create_item_list_window((saddr)"Result", 1, (((TObjBase *)(this->m_24))->get_entity_id()));
                break;
            }
            TItemData__clear_unidentified_flag(((u8 *)&this->unk_28));
            this->m_34 = advance_item_id_counter(((u16) local_client_id));
            this->m_50 = (uaddr)construct_item((TItemData *)(arg0 + 0x28));
            ((TShopJudgmentItemWindow *)(this->m_154))->add_list_entry(this->m_50, 0);
            ((TWindowSubShortCutList *)(this->m_154))->set_flag70_bit10();
            ((TWindowSubTradeMain *)(this->m_154))->set_visible();
            ((TWindowSubTradeMain *)(this->m_154))->set_close_flag();
            ((TWindowMenuIconLine *)this->m_154)->calc_content_extent();
        }
        if ((u32) this->m_160 == 0U) {
            this->m_160 = (uaddr)TWindowLoadItemTexture::create((void *)get_window_layout_position(0x30), ((TObjBase *)(this->m_24))->get_entity_id());
            ((TWindowLoadItemTexture *)this->m_160)->set_mag_slot_state((TItemData *)(arg0 + 0x28));
        }
        if ((u32) this->m_15c == 0U) {
            var_r29 = (uaddr)TObject::operator new(0xBC);
            if (var_r29 != 0U) {
                var_r29 = __ct__15TWindowHelpItemFPvl(var_r29, (int) (get_window_layout_position(0x27)), ((TObjBase *)(this->m_24))->get_entity_id());
            }
            this->m_15c = var_r29;
            if (((u32) this->m_15c != 0U) && (TLobby::is_camera_ctrl_active() > 2)) {
                ((TLobby *)(this->m_15c))->set_position(0.75f, 0.75f);
            }
            ((TWindowHelpItem *)(this->m_15c))->set_displayed_item_colored((uaddr)(arg0 + 0x28));
        }
        send_message(8, 1);
        ((TShopWindowBase *)arg0)->set_field_20(4);
    }
}

void TShopJudgmentItemWindow::update_judge_confirm() {
    u8 *arg0 = (u8 *)this;
    s32 selected_menu_value;
    if (((TShopWindowBase *)(arg0))->vfunc_10() != 0) {
        if ((u32) *(u32 *)((s8 *)arg0 + 0x158) == 0U) {
            *(s32 *)((s8 *)arg0 + 0x158) = (saddr)create_yes_no_window((const NJS_POINT2 *)get_window_layout_position(0x2B), ((TObjBase *)((saddr)(*(s32 *)((s8 *)arg0 + 0x24))))->get_entity_id(), NULL, NULL);
            ((TWindowAddition *)(*(saddr *)((s8 *)arg0 + 0x158)))->set_position_xy(((TShopWindowBase *)arg0)->get_scale(), ((TShopWindowBase *)arg0)->get_scale());
        }
        if (((u32) *(u32 *)((s8 *)arg0 + 0x158) != 0U) && (((TWindowMenu *)(*(void **)((s8 *)arg0 + 0x158)))->is_decided() != 0)) {
            selected_menu_value = ((TWindowMenu *)(*(uaddr *)((s8 *)arg0 + 0x158)))->get_selected_value();
            if (selected_menu_value == 0) {
                if ((u32) *(u32 *)((s8 *)arg0 + 0x160) != 0U) {
                    ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x160)))->close();
                    *(u32 *)((s8 *)arg0 + 0x160) = 0U;
                }
                if ((u32) *(u32 *)((s8 *)arg0 + 0x154) != 0U) {
                    ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x154)))->close();
                    *(u32 *)((s8 *)arg0 + 0x154) = 0U;
                }
                if ((u32) *(u32 *)((s8 *)arg0 + 0x15C) != 0U) {
                    ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x15C)))->close();
                    *(u32 *)((s8 *)arg0 + 0x15C) = 0U;
                }
                try_spend_actor_meseta((u8 *)(*(saddr *)((s8 *)arg0 + 0x24)), 0x64);
                if (check_equip_requirements(*(TObjPlayer **)((s8 *)arg0 + 0x24), (TItemData *)(arg0 + 0x28), NULL) != 0) {
                    send_message(0xC, 1);
                    ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x158)))->close();
                    *(u32 *)((s8 *)arg0 + 0x158) = 0U;
                    ((TShopWindowBase *)arg0)->set_field_20(7);
                    return;
                }
                delete_item(*(void **)((s8 *)arg0 + 0x24), *(s32 *)((s8 *)arg0 + 0x48), 1);
                *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)arg0 + 0x48);
                ((TObjPlayer *)(*(saddr *)((s8 *)arg0 + 0x24)))->request_inventory_item((TItemData*)(arg0 + 0x28));
                set_judgment_target_flag((arg0), ((u8 *)&this->unk_28));
                send_message(0xB, 1);
                ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x158)))->close();
                *(u32 *)((s8 *)arg0 + 0x158) = 0U;
                if (TLobby::get_shop_value() > 0) {
                    play_cue_stream_file("miniclear.adx");
                }
                ((TShopWindowBase *)arg0)->set_field_20(0);
                return;
            }
            if (selected_menu_value == 1) {
                ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x158)))->close();
                *(u32 *)((s8 *)arg0 + 0x158) = 0U;
                send_message(9, 1);
                ((TShopWindowBase *)arg0)->set_field_20(6);
                return;
            }
            goto block_19;
        }
block_19:
        if (((u32) *(u32 *)((s8 *)arg0 + 0x158) != 0U) && (((TWindowMenu *)(*(void **)((s8 *)arg0 + 0x158)))->is_cancelled() != 0)) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x158)))->close();
            *(u32 *)((s8 *)arg0 + 0x158) = 0U;
            send_message(9, 1);
            ((TShopWindowBase *)arg0)->set_field_20(6);
        }
    }
}
}

#define F(o, t) (*(t *)(arg0 + (o)))

extern "C" {
void TShopJudgmentItemWindow::handle_equip_prompt() {
    u8 *arg0 = (u8 *)this;
    f32 y;
    s32 sel;
    s32 id;
    TItem *item;
    uaddr eq;

    if (this->vfunc_10() != 0) {
        if (F(0x158, void *) == NULL) {
            id = ((TObjBase *)(saddr)(F(0x24, s32)))->get_entity_id();
            F(0x158, s32) = (saddr)create_yes_no_window((const NJS_POINT2 *)get_window_layout_position(0x2B), id, NULL, NULL);
            ((TWindowSubComCardList *)(F(0x158, void *)))->set_selected_index(0);
            y = ((TShopWindowBase *)arg0)->get_scale();
            ((TWindowAddition *)(F(0x158, saddr)))->set_position_xy(((TShopWindowBase *)arg0)->get_scale(), y);
        }
        if (F(0x158, void *) != NULL && ((TWindowMenu *)(F(0x158, void *)))->is_decided() != 0) {
            sel = ((TWindowMenu *)(F(0x158, saddr)))->get_selected_value();
            if (sel == 0) {
                if (F(0x160, void *) != NULL) {
                    ((TWindowBase *)(F(0x160, void *)))->close();
                    F(0x160, void *) = NULL;
                }
                if (F(0x154, void *) != NULL) {
                    ((TWindowBase *)(F(0x154, void *)))->close();
                    F(0x154, void *) = NULL;
                }
                if (F(0x15C, void *) != NULL) {
                    ((TWindowBase *)(F(0x15C, void *)))->close();
                    F(0x15C, void *) = NULL;
                }
                ((TWindowBase *)(F(0x158, void *)))->close();
                F(0x158, void *) = NULL;
                delete_item(F(0x24, void *), F(0x48, s32), 1);
                F(0x34, s32) = F(0x48, s32);
                ((TObjPlayer *)(F(0x24, saddr)))->request_inventory_item((TItemData*)(arg0 + 0x28));
                set_judgment_target_flag(arg0, &this->unk_28);
                item = find_item_by_id(F(0x34, s32));
                if (item != NULL && (eq = (uaddr)((TObjPlayer *)(F(0x24, saddr)))->get_equipped_item(item->get_attach_slot())) != 0) {
                    TObjPlayer::send_6x26_unequip_item((void *)(F(0x24, saddr)), ((TItem *)eq)->get_item_id());
                }
                send_6x25_equip_item((void *)(F(0x24, saddr)), F(0x34, s32), 0);
                send_message(0xB, 1);
                if (TLobby::get_shop_value() > 0) {
                    play_cue_stream_file("miniclear.adx");
                }
                ((TShopWindowBase *)arg0)->set_field_20(0);
            }
            if (sel == 1) {
                ((TWindowBase *)(F(0x158, void *)))->close();
                F(0x158, void *) = NULL;
                delete_item(F(0x24, void *), F(0x48, s32), 1);
                F(0x34, s32) = F(0x48, s32);
                ((TObjPlayer *)(F(0x24, saddr)))->request_inventory_item((TItemData*)(arg0 + 0x28));
                set_judgment_target_flag(arg0, &this->unk_28);
                send_message(0xB, 1);
                if (TLobby::get_shop_value() > 0) {
                    play_cue_stream_file("miniclear.adx");
                }
                ((TShopWindowBase *)arg0)->set_field_20(0);
            }
        }
        if (F(0x158, void *) != NULL && ((TWindowMenu *)(F(0x158, void *)))->is_cancelled() != 0) {
            ((TWindowBase *)(F(0x158, void *)))->close();
            F(0x158, void *) = NULL;
            delete_item(F(0x24, void *), F(0x48, s32), 1);
            F(0x34, s32) = F(0x48, s32);
            ((TObjPlayer *)(F(0x24, saddr)))->request_inventory_item((TItemData*)(arg0 + 0x28));
            set_judgment_target_flag(arg0, &this->unk_28);
            send_message(0xB, 1);
            if (TLobby::get_shop_value() > 0) {
                play_cue_stream_file("miniclear.adx");
            }
            ((TShopWindowBase *)arg0)->set_field_20(0);
        }
    }
}
}

#undef F

extern "C" {
void TShopJudgmentItemWindow::update() {
    s32 c = *(s32 *)&this->_pad14C - 1;
    *(s32 *)&this->_pad14C = c;
    if (c <= 0 && vfunc_10() != 0 && (sub_80223A48() != 0 || sub_802239EC() != 0)) {
        send_message(0xB, 1);
        set_field_20(0);
    }
}

void TShopJudgmentItemWindow::handle_pay_confirm() {
    s32 selected_menu_value;

    if (this->vfunc_10() != 0) {
        if ((u32) this->m_158 == 0U) {
            this->m_158 = (saddr)create_yes_no_window((const NJS_POINT2 *)get_window_layout_position(0x2B), ((TObjBase *)(this->m_24))->get_entity_id(), NULL, NULL);
            ((TWindowSubComCardList *)((void *)this->m_158))->set_selected_index(0);
            ((TWindowAddition *)(this->m_158))->set_position_xy(get_scale(), get_scale());
        }
        if (((u32) this->m_158 != 0U) && (((TWindowMenu *)(this->m_158))->is_decided() != 0)) {
            selected_menu_value = ((TWindowMenu *)this->m_158)->get_selected_value();
            if (selected_menu_value == 0) {
                if ((u32) this->m_160 != 0U) {
                    ((TWindowBase *)this->m_160)->close();
                    this->m_160 = 0U;
                }
                if ((u32) this->m_154 != 0U) {
                    ((TWindowBase *)this->m_154)->close();
                    this->m_154 = 0U;
                }
                if ((u32) this->m_15c != 0U) {
                    ((TWindowBase *)this->m_15c)->close();
                    this->m_15c = 0U;
                }
                if ((u32) this->m_50 != 0U) {
                    ((TObject *)(this->m_50))->queue_destruction();
                    this->m_50 = 0U;
                }
                *(s32 *)&this->_pad14C = 3;
                ((TWindowBase *)this->m_158)->close();
                this->m_158 = 0U;
                try_spend_actor_meseta((u8 *)this->m_24, 0x64);
                send_message(0xA, 1);
                this->set_field_20(5);
                return;
            }
            if (selected_menu_value == 1) {
                ((TWindowBase *)this->m_158)->close();
                this->m_158 = 0U;
                send_message(8, 1);
                this->set_field_20(4);
                return;
            }
            goto block_17;
        }
block_17:
        if (((u32) this->m_158 != 0U) && (((TWindowMenu *)(this->m_158))->is_cancelled() != 0)) {
            ((TWindowBase *)this->m_158)->close();
            this->m_158 = 0U;
            send_message(8, 1);
            this->set_field_20(4);
        }
    }
}

void TShopJudgmentItemWindow::invoke_callback_170_and_destroy() {
    void (*callback)(TShopWindowBase *);

    callback = this->m_170;
    if (callback != NULL) {
        callback(this->sequence);
        queue_destruction();
    }
}

void TShopJudgmentItemWindow::invoke_callback_16C_and_destroy() {
    void (*callback)(TShopWindowBase *);

    callback = this->m_16c;
    if (callback != NULL) {
        callback(this->sequence);
        queue_destruction();
    }
}

void TShopJudgmentItemWindow::invoke_callback_174_and_destroy() {
    void (*callback)(TShopWindowBase *);

    callback = this->m_174;
    if (callback != NULL) {
        callback(this->sequence);
        queue_destruction();
    }
}

void TShopJudgmentItemWindow::send_message(s32 id, s32 flags) {
    TShopWindowBase *sequence;

    sequence = this->sequence;
    if (sequence != NULL) {
        sequence->send_message(id, flags);
    }
}

void TShopJudgmentItemWindow::display_message(const char *text, s32 flags) {
    TShopWindowBase *sequence;

    sequence = this->sequence;
    if (sequence != NULL) {
        sequence->display_message(text, flags);
    }
}
}
