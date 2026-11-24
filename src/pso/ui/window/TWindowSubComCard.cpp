#include "pso/player/GuildCardEntry.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/window/TWindowUserSort.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/system/ControllerInput.h"

#include "types.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/unk/text_8024AB54.h"
#include "pso/unk/text_8024AB98.h"

class TChCrTagPlBack;
#include "pso/ui/window/TWindowComCard.h"
#include "pso/network/TProtocol.h"
#include "pso/unk/GuildCardRecord.h"

#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenuInfomation.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"

#include "pso/ui/chat/ShortMail.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TPlyGuildCardTag_8007B7EC.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/window/TWindowSubComCard_802A5748.h"
#include "pso/unk/text_802754EC.h"
#include "pso/player/PlayerSlots.h"

const char *TWindowSubComCard::class_name = "TWindowSubComCard";

// Window sizes {width, height} passed to TWindowMessage::create / the choice-setting window.
static const f32 com_card_layout_message_size[2] = {188.0f, 120.0f};
static const f32 com_card_choice_list_size[2] = {405.0f, 144.0f};
static const f32 com_card_entry_list_size[2] = {405.0f, 144.0f};
static const f32 com_card_mode4_message_size[2] = {206.0f, 122.0f};
static const f32 com_card_message_size[2] = {206.0f, 82.0f};
static const saddr com_card_help_message_ids[] = {0x47, 0x48, 0x49, 0x4A, 0x4B, 0xF9, 0};

struct Ent_80272034 { u16 a; u16 b; u8 rest[0x1c]; };

struct Tbl_80272034 { u8 pad0; u8 count; u8 pad2[2]; Ent_80272034 e[1]; };

struct Win_80272034 { u8 pad[0x58]; Tbl_80272034 *tbl; };

struct Key_80272034 { u32 a; u32 b; };

struct Ent_80271F04 {
    u32 id;
    u32 value;
};
s32 *get_selected_guild_card_record(void);
extern "C" {
void set_value_by_key(void *, u16, s32);
saddr get_window_layout_position(s32 a0 = 0);

}

struct Rec_80272290 { s32 f0; u8 f4[0xD0]; };
void text_builder_reset();
extern "C" {
void load_selected_guild_card_record(int, int);

void update_selection__17TWindowSubComCardFUiUiPvi(uaddr list_window, uaddr card_window, s32 *last_selected, s32 cards);
void TWindowComCard__sub_80249920(saddr window, s32 card_index, s32 cards);
}

struct Ent_80272CB0 {
    u16 type;
    u16 id;
    u8 name[0x1C];
};

struct List_80272CB0 {
    u8 pad0;
    u8 count;
    u8 pad2[2];
    Ent_80272CB0 ents[1];
};

struct Entry_80272B60 { u16 id; u16 val; u8 name[0x1C]; };

struct ChrSel_80272B60 { u8 f0; u8 count; u8 pad[2]; Entry_80272B60 e[1]; };

struct VBase_18_80272714 { char pad[0x18]; };

struct VObj_18_80272714 : VBase_18_80272714 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void *m10();
};
extern "C" {
s32 create_titled_window_menu_default(int, int, void *);
s32 TWindowSubComCard__sub_80273004(void);
s32 TWindowSubComCard__sub_802728CC(void);
extern s32 local_client_id;
s32 create_keyboard__17TWindowSubComCardFi(saddr arg0);
s32 create_keyboard__17TWindowSubComCardFii(saddr parent, saddr card);
void update_selection__17TWindowSubComCardFiii(s32 list_window, s32 card_window, s32 last_selected);

struct ComCardRec_80272A98 { u32 id; char name[0xD0]; };

struct ComCardList_80272A98 { u8 pad0; u8 count; u8 pad2[2]; ComCardRec_80272A98 entries[1]; };


}

struct VBase_18_204a81 { char pad[0x18]; };

struct VObj_18_204a81 : VBase_18_204a81 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual s32 m7();
};

struct ComEntry_8027375C { u8 data[0xD4]; };

struct ComList_8027375C { u8 pad[4]; ComEntry_8027375C entries[1]; };
extern "C" {
s32 create_window_menu_default(void *, int);
s32 TWindowSubComCard__sub_8027353C(void);
s32 TWindowSubComCard__sub_8027346C(void);
s32 TWindowSubComCard__sub_800778B4(void *, int);
void TWindowSubComCard__sub_8007AF10(s32 client_id);
s32 play_sound_effect(int, int, int, int);
s32 TLobby__sub_8024259C();
void fn_802449E0(u8 *object);
}
s32 is_com_card_active();
extern "C" {
void TWindowSubComCard__sub_80249144(void *window_choice_setting);
u32 TWindowSubComCard__sub_80272640(void *);
u32 TWindowSubComCard__sub_80272A98(void *);
u32 TWindowSubComCard__sub_8027337C();

void TWindowSubComCard__sub_80077980(void *);
}

struct SelectedGuildCardRecord { s32 value; u8 remaining[0xB8]; };
extern SelectedGuildCardRecord selected_guild_card_record;

void TWindowSubComCard::set_display_page() {
    set_page((s16)((int) (((TWindowMenu *)this)->get_selected_value())));
}
void TWindowMenuInfomation::set_flag_10() { m_70 |= 0x10; }
void TWindowSubComCard::set_page(s16 v) { *(s16*)((char*)this + 0x7a) = v; }
s16 TWindowSubComCardList::get_field_72() { return entry_count; }
void TKeyBoardControl::set_soft_flag60_bit1() {
    if (m_soft != NULL) {
        m_soft->set_flag60_bit1();
    }
}
char *GuildCardRecord::get_sub_obj() { return name; }
char *GuildCardRecord::get_name() { return s19; }
char *TWindowSubComCard__sub_8027523C(GuildCardRecord *entry) { return entry->s2A; }

char *GuildCardRecord::get_card_data_ptr() { return s3B; }

s32 *get_selected_guild_card_record(void) {
    return &selected_guild_card_record.value;
}
extern "C" {

void TWindowSubComCard::set_com_param(s32 com_param) {
    saddr arg0 = (saddr)this;
    TWindowKeyBoardHard::set_card_window_flags((void *)arg0, (s32)(com_param << 0x12), (s32)0xFFFBFFFF);
}
}

TWindowSubComCard::TWindowSubComCard(TObject *object, void *arg2) : TObject(object) {
    m_name = class_name;
    *(void **)((s8 *)this + 0x5C) = object;
    *(void **)((s8 *)this + 0x20) = arg2;
    this->m_60 = 0;
    this->m_64 = 0;
    this->m_74 = 0;
    this->m_78 = 0;
    this->m_68 = 0;
    this->message_window = 0;
    this->confirm_window = 0;
    this->keyboard = 0;
    this->m_84 = 0;
    this->entry_list_window = 0;
    this->chr_select = 0;
    this->m_1d = 0;
    this->m_24 = -1;
    TWindowSubComCard__sub_80077980((void *)((char *)this + 48));
    this->state = 0;
}
extern "C" {

TWindowSubComCard::~TWindowSubComCard() {
    handle_close_flag();
    send_state_if_dirty();
    if ((u8) state == 0x26) {
        TWindowSubComCard__sub_8024AB98(m_20);
    }
    if (entry_list_window != 0U) {
        ((TWindowBase *)entry_list_window)->close();
        entry_list_window = 0U;
    }
    if (confirm_window != 0U) {
        ((TWindowMessageYesNo *)confirm_window)->close();
        confirm_window = 0U;
    }
    if (m_84 != 0U) {
        ((TWindowBase *)m_84)->close();
        m_84 = 0U;
    }
    if (keyboard != 0U) {
        ((TObject *)keyboard)->queue_destruction();
        keyboard = 0U;
    }
    if (m_68 != 0U) {
        ((TWindowBase *)m_68)->close();
        m_68 = 0U;
    }
    if (m_64 != 0U) {
        ((TWindowBase *)m_64)->close();
        m_64 = 0U;
    }
    if (m_78 != 0U) {
        ((TWindowBase *)m_78)->close();
        m_78 = 0U;
    }
    if (m_74 != 0U) {
        ((TWindowBase *)m_74)->close();
        m_74 = 0U;
    }
    if (message_window != 0U) {
        ((TWindowBase *)message_window)->close();
        message_window = 0U;
    }
    if (m_60 != 0U) {
        ((TWindowBase *)m_60)->close();
        m_60 = 0U;
    }
}
void TWindowSubComCard::run_task() {
    saddr src;
    saddr character_save_record;
    s32 temp_r29_7;
    saddr temp_r29_8;
    saddr keyboard_mode;
    s32 idle_ticks;
    s32 record;
    s32 selected_value;
    s32 temp_r30_3;
    switch (this->state) {
    case 0x0:
    case 0x1:
        this->send_state_if_dirty();
        if ((u32) this->keyboard != 0U) {
            ((TObject *)(*(void **)((s8 *)this + 0x80)))->queue_destruction();
            this->keyboard = 0U;
        }
        if ((u32) this->entry_list_window != 0U) {
            ((TWindowBase *)this->entry_list_window)->close();
            this->entry_list_window = 0U;
        }
        if ((u32) this->confirm_window != 0U) {
            ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x70)))->close();
            this->confirm_window = 0U;
        }
        if ((u32) this->m_84 != 0U) {
            ((TWindowBase *)this->m_84)->close();
            this->m_84 = 0U;
        }
        if ((u32) this->m_68 != 0U) {
            ((TWindowBase *)this->m_68)->close();
            this->m_68 = 0U;
        }
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->m_78 != 0U) {
            ((TWindowBase *)this->m_78)->close();
            this->m_78 = 0U;
        }
        if ((u32) this->m_74 != 0U) {
            ((TWindowBase *)this->m_74)->close();
            this->m_74 = 0U;
        }
        if ((u32) this->message_window != 0U) {
            ((TWindowBase *)this->message_window)->close();
            this->message_window = 0U;
        }
        if ((u32) this->m_60 == 0U) {
            this->m_60 = ((s32 (*)(void *)) TWindowSubComCard::create_menu)((void *)this);
        }
        if ((u32) this->message_window == 0U) {
            this->message_window = ((u32 (*)(void*))TWindowSubComCard::open_layout_window)((void *)this);
            this->m_28 = -1;
        }
        ((TWindowMenu *)(this->m_60))->clear_flag_and_release();
        this->state = 2U;
    case 0x2:
        this->set_help_message((int) (((TWindowShortListCtrl *)(this->m_60))->get_cursor_pos()));
        if (((TWindowMenu *)(this->m_60))->is_cancelled() != 0) {
            ((VObj_18_204a81 *)((u8 *)(*(u8 **)((s8 *)this + 0x5C))))->m7();
            this->state = 0x4FU;
            return;
        }
        if (((TWindowMenu *)(this->m_60))->is_decided() != 0) {
            if ((u32) this->message_window != 0U) {
                ((TWindowBase *)this->message_window)->close();
                this->message_window = 0U;
            }
            this->state = ((TWindowMenu *)this->m_60)->get_selected_value();
            return;
        }
        break;
    case 0x3:
        if ((u32) this->m_68 != 0U) {
            ((TWindowBase *)this->m_68)->close();
            this->m_68 = 0U;
        }
        if ((u32) this->m_74 == 0U) {
            this->m_74 = TWindowSubComCard::create_com_card_window(get_window_layout_position(0x81));
        }
        if ((u32) this->m_64 == 0U) {
            this->m_64 = ((s32 (*)(void *)) TWindowSubComCard__sub_8027353C)((void *)this);
        }
        ((TWindowMenu *)(this->m_64))->clear_flag_and_release();
        ((TWindowMenu *)(this->m_64))->clear_transition_flag();
        this->state = 4U;
    case 0x4:
        if (((TWindowMenu *)(this->m_64))->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_64))->is_decided() != 0) {
            this->state = ((TWindowMenu *)this->m_64)->get_selected_value();
            return;
        }
        break;
    case 0x5:
        if ((u32) this->m_68 == 0U) {
            this->m_68 = TWindowSubComCard__sub_8027337C();
        }
        ((TWindowMenu *)(this->m_64))->open();
        this->state = 6U;
    case 0x6:
        if (((TWindowMenu *)(this->m_68))->is_cancelled() != 0) {
            this->state = 3U;
            return;
        }
        if (((TWindowMenu *)(this->m_68))->is_decided() != 0) {
            TWindowSubComCard__sub_8007AF10(((TWindowMenu *)this->m_68)->get_selected_value());
            this->state = 7U;
            return;
        }
        break;
    case 0x7:
        if ((u32) this->m_68 != 0U) {
            ((TWindowBase *)this->m_68)->close();
            this->m_68 = 0U;
        }
        if ((u32) this->m_68 == 0U) {
            this->m_68 = ((s32 (*)(void *)) TWindowSubComCard::create_single_entry_window)((void *)this);
        }
        this->state = 8U;
    case 0x8:
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 6) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 6) != 0)) {
            this->state = 3U;
            return;
        }
        break;
    case 0x9:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->m_74 != 0U) {
            ((TWindowBase *)this->m_74)->close();
            this->m_74 = 0U;
        }
        if ((u32) this->m_60 != 0U) {
            ((TWindowBase *)this->m_60)->close();
            this->m_60 = 0U;
        }
        this->keyboard = ((u32 (*)(void*))create_keyboard__17TWindowSubComCardFi)((void *)this);
        this->state = 0xAU;
    case 0xA:
        if (((TKeyBoardControl *)(this->keyboard))->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (((TKeyBoardControl *)(this->keyboard))->is_confirmed() != 0) {
            src = (saddr)((TKeyBoardControl *)(this->keyboard))->realloc_buffer();
            TWindowSubComCard::mask_profanity_words((char *)src, (char *)get_shared_text_buffer());
            keyboard_mode = TWindowSubComCard::get_keyboard_mode();
            ((TWindowSubComCard *)keyboard_mode)->set_text((void *)(get_shared_text_buffer()));
            mem_free((void *)src);
            this->state = 1U;
            return;
        }
        break;
    case 0xB:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->message_window == 0U) {
            this->message_window = ((u32 (*)(void*))TWindowSubComCard::create)((void *)this);
            fn_802449E0((u8 *)this->message_window);
            this->m_28 = -1;
        }
        if ((u32) this->m_84 == 0U) {
            this->m_84 = (uaddr)TWindowSubComCard::send_cmd_133();
        }
        if ((u32) this->m_74 == 0U) {
            this->m_24 = ((TWindowMenu *)this->m_84)->get_selected_value();
            this->m_74 = (uaddr)send_command(this->m_24);
        }
        ((TWindowBase *)this->message_window)->snap_to((f32 *)get_window_layout_position(0x99));
        ((TWindowLockOn *)(this->message_window))->request_close();
        ((TWindowMenu *)(this->m_84))->clear_flag_and_release();
        this->state = 0xCU;
    case 0xC:
        TWindowSubComCard::update_display_value(this->m_84, this->m_74, (s32 *)&this->m_24);
        this->set_card_index((int) (((TWindowMenu *)this->m_84)->get_selected_value()));
        if (test_pressed_buttons_packed(&controller_input_state.controllers[0], 0x400) != 0) {
            if (((TWindowBase *)(this->message_window))->sub_80244994() != 0) {
                ((TWindowLockOn *)(this->message_window))->request_close();
            } else {
                window_request_show((void *)this->message_window);
            }
        }
        if (((TWindowMenu *)(this->m_84))->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_84))->is_decided() != 0) {
            this->state = 0xDU;
            return;
        }
        break;
    case 0xD:
        if ((u32) this->message_window != 0U) {
            ((TWindowBase *)this->message_window)->close();
            this->message_window = 0U;
        }
        if ((u32) this->confirm_window != 0U) {
            ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x70)))->close();
            this->confirm_window = 0U;
        }
        if ((u32) this->m_68 != 0U) {
            ((TWindowBase *)this->m_68)->close();
            this->m_68 = 0U;
        }
        if ((u32) this->m_74 != 0U) {
            ((TWindowBase *)this->m_74)->close();
            this->m_74 = 0U;
        }
        if ((u32) this->m_64 == 0U) {
            this->m_64 = ((s32 (*)(void *)) TWindowSubComCard::open_menu)((void *)this);
        }
        ((TWindowMenu *)(this->m_64))->clear_transition_flag();
        ((TWindowMenu *)(this->m_64))->clear_flag_and_release();
        this->state = 0xEU;
    case 0xE:
        if (((TWindowMenu *)(this->m_64))->is_cancelled() != 0) {
            this->state = 0xBU;
            return;
        }
        if (((TWindowMenu *)(this->m_64))->is_decided() != 0) {
            this->state = ((TWindowMenu *)this->m_64)->get_selected_value();
            return;
        }
        break;
    case 0xF:
        ((s32 (*)(void))TWindowSubComCard::cleanup)();
        this->state = 0x10U;
    case 0x10:
        this->state = 0xBU;
        return;
    case 0x11:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->message_window == 0U) {
            this->message_window = ((u32 (*)(void*))TWindowSubComCard::create)((void *)this);
            this->m_28 = -1;
        }
        this->set_card_index((int) (((TWindowMenu *)this->m_84)->get_selected_value()));
        this->state = 0x12U;
    case 0x12:
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 6) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 6) != 0)) {
            this->state = 0xBU;
            return;
        }
        break;
    case 0x13:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->m_84 != 0U) {
            this->m_24 = ((TWindowMenu *)this->m_84)->get_selected_value();
            ((TWindowBase *)this->m_84)->close();
            this->m_84 = 0U;
        }
        if ((u32) this->m_60 != 0U) {
            ((TWindowBase *)this->m_60)->close();
            this->m_60 = 0U;
        }
        this->keyboard = ((u32 (*)(void*, int))create_keyboard__17TWindowSubComCardFii)((void *)this, this->m_24);
        this->state = 0x14U;
    case 0x14:
        if (((TKeyBoardControl *)(this->keyboard))->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (((TKeyBoardControl *)(this->keyboard))->is_confirmed() != 0) {
            src = (saddr)((TKeyBoardControl *)(this->keyboard))->realloc_buffer();
            TWindowSubComCard::mask_profanity_words((char *)src, (char *)get_shared_text_buffer());
            ((TWindowSubComCard *)(this->m_24))->set_card_text((saddr) (get_shared_text_buffer()));
            mem_free((void *)src);
            this->state = 1U;
            return;
        }
        break;
    case 0x15:
        ((TWindowMenu *)(this->m_64))->open();
        this->confirm_window = this->confirm_and_free();
        this->state = 0x16U;
    case 0x16:
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_cancelled() != 0) {
            this->state = 0xDU;
            return;
        }
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_child_visible() != 0) {
            if (((TWindowMessageYesNo *)(this->confirm_window))->get_selected_value() == 0) {
                TWindowSubComCard::remove_card_at(((TWindowMenu *)this->m_84)->get_selected_value());
                this->state = 1U;
                return;
            }
            this->state = 0xDU;
            return;
        }
        break;
    case 0x19:
        ((TWindowMenu *)(this->m_84))->clear_flag_and_release();
        this->state = 0x1AU;
    case 0x1A:
        TWindowSubComCard::update_display_value(this->m_84, this->m_74, (s32 *)&this->m_24);
        if (((TWindowMenu *)(this->m_84))->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_84))->is_decided() != 0) {
            this->state = 0x1BU;
            return;
        }
        break;
    case 0x1B:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->m_84 == 0U) {
            this->m_84 = (uaddr)TWindowSubComCard::send_cmd_133();
        }
        if ((u32) this->m_74 == 0U) {
            this->m_24 = ((TWindowMenu *)this->m_84)->get_selected_value();
            this->m_74 = (uaddr)send_command(this->m_24);
        }
        ((TWindowSubComCard *)(this->m_84))->set_display_page();
        ((TWindowMenu *)(this->m_84))->clear_flag_and_release();
        this->state = 0x1CU;
    case 0x1C:
        TWindowSubComCard::update_display_value(this->m_84, this->m_74, (s32 *)&this->m_24);
        if (((TWindowMenu *)(this->m_84))->is_cancelled() != 0) {
            ((TWindowMenu *)(this->m_84))->reset_selection();
            this->state = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_84))->is_decided() != 0) {
            TWindowSubComCard::swap_cards((int) (((TWindowSubComCardList *)(this->m_84))->get_selected_index()), (int) (((TWindowMenu *)this->m_84)->get_selected_value()));
            ((TWindowMenu *)(this->m_84))->reset_selection();
            ((TWindowSubComCardList *)(this->m_84))->sub_80275360();
            this->state = 0x19U;
            return;
        }
        break;
    case 0x1D:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->m_78 != 0U) {
            ((TWindowBase *)this->m_78)->close();
            this->m_78 = 0U;
        }
        this->m_68 = ((u32 (*)(void*))TWindowSubComCard__sub_80273004)((void *)this);
        ((TWindowMenu *)this->m_68)->add_text_entry((saddr)(""), 0x15, -1);
        rebuild_com_card_list(this->m_68);
        this->state = 0x1EU;
    case 0x1E:
        if (is_com_card_active() != 0) {
            rebuild_com_card_list(this->m_68);
        }
        if (((TWindowMenu *)(this->m_68))->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_68))->is_decided() != 0) {
            TLobby::find_and_load_com_card(((TWindowMenu *)this->m_68)->get_selected_value());
            this->state = 0x1FU;
            return;
        }
        break;
    case 0x1F:
        if ((u32) this->m_68 != 0U) {
            ((TWindowBase *)this->m_68)->close();
            this->m_68 = 0U;
        }
        if ((u32) this->m_78 == 0U) {
            record = ((s32 (*)(void))get_selected_guild_card_record)();
            this->m_78 = (uaddr)new TWindowUserSort(get_window_layout_position(0x8A), reinterpret_cast<GuildCardRecord *>(record));
        }
        if ((u32) this->m_64 == 0U) {
            this->m_64 = ((s32 (*)(void *)) TWindowSubComCard__sub_8027346C)((void *)this);
        }
        this->state = 0x20U;
    case 0x20:
        if (((TWindowMenu *)(this->m_64))->is_cancelled() != 0) {
            this->state = 0x1DU;
            return;
        }
        if (((TWindowMenu *)(this->m_64))->is_decided() != 0) {
            this->state = ((TWindowMenu *)this->m_64)->get_selected_value();
            return;
        }
        break;
    case 0x21:
        if ((u32) this->confirm_window != 0U) {
            ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x70)))->close();
            this->confirm_window = 0U;
        }
        if ((u32) this->m_68 != 0U) {
            ((TWindowBase *)this->m_68)->close();
            this->m_68 = 0U;
        }
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->m_78 != 0U) {
            ((TWindowBase *)this->m_78)->close();
            this->m_78 = 0U;
        }
        if ((u32) this->m_60 != 0U) {
            ((TWindowBase *)this->m_60)->close();
            this->m_60 = 0U;
        }
        if ((u32) this->keyboard == 0U) {
            this->keyboard = reinterpret_cast<uaddr>(TWindowSubShortMail::create_keyboard());
        }
        ((TKeyBoardControl *)(this->keyboard))->set_position((void *)(get_window_layout_position(0xBB)));
        reinterpret_cast<TKeyBoardControl *>(keyboard)->clear_keyboard_flag60_bit1();
        ((TKeyBoardControl *)(this->keyboard))->show();
        this->state = 0x22U;
    case 0x22:
        if (((TKeyBoardControl *)(this->keyboard))->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (((TKeyBoardControl *)(this->keyboard))->is_confirmed() != 0) {
            this->state = 0x23U;
            return;
        }
        break;
    case 0x23:
        ((TKeyBoardControl *)(this->keyboard))->set_position((void *)(get_window_layout_position(0xBC)));
        ((TKeyBoardControl *)this->keyboard)->hide();
        this->confirm_window = TWindowSubShortMail::open_confirm_prompt(this, m_20);
        this->state = 0x24U;
    case 0x24:
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_cancelled() != 0) {
            this->state = 0x21U;
            return;
        }
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_child_visible() != 0) {
            if (((TWindowMessageYesNo *)(this->confirm_window))->get_selected_value() == 0) {
                this->sub_802721D8();
                this->state = 1U;
                return;
            }
            this->state = 0x21U;
            return;
        }
        break;
    case 0x25:
        ((s32 (*)(void))get_selected_guild_card_record)();
        TLobby__sub_8024259C();
        fn_8024AB54((this->m_20));
        this->m_2c = 0;
        this->state = 0x26U;
    case 0x26:
        idle_ticks = this->m_2c;
        this->m_2c = (idle_ticks + 1);
        if ((f32) idle_ticks > 450.0f) {
            TWindowSubComCard__sub_8024AB98((this->m_20));
            ((VObj_18_204a81 *)((u8 *)(*(u8 **)((s8 *)this + 0x5C))))->m7();
            this->state = 0x4FU;
            return;
        }
        break;
    case 0x27:
    case 0x33:
        if (TWindowSubComCard::get_chr_select() == 0U) {
            TLobby::protocol_instance->send_choice_search_options_request();
        }
        if ((u8) this->state == 0x27) {
            this->state = 0x28U;
        } else {
            this->state = 0x34U;
        }
    case 0x28:
    case 0x34:
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            this->state = 1U;
        }
        if (TWindowSubComCard::get_chr_select() != 0U) {
            if ((u32) this->chr_select == 0U) {
                this->chr_select = TWindowSubComCard::get_chr_select();
                character_save_record = get_character_save_record(0xFFFF);
                TWindowSubComCard__sub_800778B4((void *) ((u8 *)this + 0x30), this->chr_select);
                TWindowSubComCard__sub_800778B4((void *)(character_save_record + 0x22EC), (int)this->chr_select);
            }
            if ((u8) this->state == 0x28) {
                this->state = 0x29U;
                return;
            }
            this->state = 0x35U;
            return;
        }
        break;
    case 0x29:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->entry_list_window == 0U) {
            this->entry_list_window = ((TWindowSubComCard *)this)->sub_80272DE0();
        }
        ((TWindowChoiceSetting *)this->entry_list_window)->begin_scroll(148.0f);
        ((TWindowChoiceSetting *)this->entry_list_window)->clear_flag_and_release2();
        this->state = 0x2AU;
    case 0x2A:
        if (((TWindowChoiceSetting *)this->entry_list_window)->get_flag() != 0) {
            this->state = 1U;
            return;
        }
        if (((TWindowMenuInfomation *)(this->entry_list_window))->is_open() != 0) {
            if (((TWindowMenuInfomation *)(this->entry_list_window))->update_selected_entry() == 0) {
                this->state = 0x2DU;
                return;
            }
            this->state = 0x2BU;
            return;
        }
        break;
    case 0x2B:
        TWindowSubComCard__sub_80249144((void *)this->entry_list_window);
        this->m_64 = this->create_option_list_window((saddr)((void *) ((u8 *)this + 0x30)), (s32)((int) (((TWindowMenuInfomation *)(this->entry_list_window))->update_selected_entry())));
        this->state = 0x2CU;
    case 0x2C:
        if (((TWindowMenu *)(this->m_64))->is_cancelled() != 0) {
            this->state = 0x29U;
            return;
        }
        if (((TWindowMenu *)(this->m_64))->is_decided() != 0) {
            ((TWindowSubComCard *)this)->sub_80271F04((void *) ((u8 *)this + 0x30), (int) (((TWindowMenuInfomation *)(this->entry_list_window))->update_selected_entry()), (int) (((TWindowMenu *)this->m_64)->get_selected_value()));
            this->state = 0x29U;
            return;
        }
        break;
    case 0x2D:
        TWindowSubComCard::release();
        TLobby::send_packet((saddr)this, (saddr)((u8 *)this + 0x30));
        this->state = 0x2EU;
    case 0x2E:
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            this->state = 0x29U;
        }
        if (TWindowSubComCard::get_com_count() != 0U) {
            this->state = 0x2FU;
            return;
        }
        break;
    case 0x2F:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->entry_list_window != 0U) {
            ((TWindowBase *)this->entry_list_window)->close();
            this->entry_list_window = 0U;
        }
        if ((u32) this->m_68 == 0U) {
            this->m_68 = TWindowSubComCard__sub_80272A98((void *)this);
        }
        if ((u32) this->message_window == 0U) {
            this->message_window = ((u32 (*)(void*))TWindowSubComCard::open_mode4_window)((void *)this);
            this->m_28 = -1;
        }
        ((TWindowMenu *)(this->m_68))->clear_flag_and_release();
        this->state = 0x30U;
    case 0x30:
        this->set_selected_card((int) (((TWindowMenu *)this->m_68)->get_selected_value()));
        if (((TWindowMenu *)(this->m_68))->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_68))->is_decided() != 0) {
            this->state = 0x31U;
            return;
        }
        break;
    case 0x31:
        if ((u32) this->message_window != 0U) {
            ((TWindowBase *)this->message_window)->close();
            this->message_window = 0U;
        }
        if ((u32) this->m_64 == 0U) {
            selected_value = ((TWindowMenu *)this->m_68)->get_selected_value();
            ComList_8027375C *cl = (ComList_8027375C *) TWindowSubComCard::get_com_count();
            ((s32 (*)(void*))load_selected_guild_card_record)(&cl->entries[selected_value]);
            this->m_64 = ((u32 (*)(void*))TWindowSubComCard::create_menu_window)((void *)this);
        }
        this->state = 0x32U;
    case 0x32:
        if (((TWindowMenu *)(this->m_64))->is_cancelled() != 0) {
            this->state = 0x2FU;
            return;
        }
        if (((TWindowMenu *)(this->m_64))->is_decided() != 0) {
            this->state = ((TWindowMenu *)this->m_64)->get_selected_value();
            return;
        }
        break;
    case 0x35:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->entry_list_window == 0U) {
            this->entry_list_window = this->create_entry_list_window();
        }
        ((TWindowChoiceSetting *)this->entry_list_window)->begin_scroll(148.0f);
        ((TWindowChoiceSetting *)this->entry_list_window)->clear_flag_and_release2();
        this->state = 0x36U;
    case 0x36:
        if (((TWindowChoiceSetting *)this->entry_list_window)->get_flag() != 0) {
            this->state = 1U;
            return;
        }
        if (((TWindowMenuInfomation *)(this->entry_list_window))->is_open() != 0) {
            this->state = 0x37U;
            return;
        }
        break;
    case 0x37:
        TWindowSubComCard__sub_80249144((void *)this->entry_list_window);
        temp_r29_7 = get_character_save_record(0xFFFF);
        this->m_64 = this->create_option_list_window(temp_r29_7 + 0x22EC, (s32)((int) (((TWindowMenuInfomation *)(this->entry_list_window))->update_selected_entry())));
        this->state = 0x38U;
    case 0x38:
        if (((TWindowMenu *)(this->m_64))->is_cancelled() != 0) {
            this->state = 0x35U;
            return;
        }
        if (((TWindowMenu *)(this->m_64))->is_decided() != 0) {
            temp_r29_8 = get_character_save_record(0xFFFF);
            ((TWindowSubComCard *)this)->sub_80271F04((void *)(temp_r29_8 + 0x22EC), (int) (((TWindowMenuInfomation *)(this->entry_list_window))->update_selected_entry()), (int) (((TWindowMenu *)this->m_64)->get_selected_value()));
            this->state = 0x35U;
            return;
        }
        break;
    case 0x39:
        if ((u32) this->m_68 != 0U) {
            ((TWindowBase *)this->m_68)->close();
            this->m_68 = 0U;
        }
        if ((u32) this->m_74 != 0U) {
            ((TWindowBase *)this->m_74)->close();
            this->m_74 = 0U;
        }
        if ((u32) this->m_84 != 0U) {
            ((TWindowBase *)this->m_84)->close();
            this->m_84 = 0U;
        }
        if ((u32) this->m_64 == 0U) {
            this->m_64 = ((u32 (*)(void*))TWindowSubComCard__sub_802728CC)((void *)this);
        }
        ((TWindowMenu *)(this->m_64))->clear_flag_and_release();
        this->state = 0x3AU;
    case 0x3A:
        if (((TWindowMenu *)(this->m_64))->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_64))->is_decided() != 0) {
            this->state = ((TWindowMenu *)this->m_64)->get_selected_value();
            return;
        }
        break;
    case 0x3B:
        if ((u32) this->confirm_window != 0U) {
            ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x70)))->close();
            this->confirm_window = 0U;
        }
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->message_window != 0U) {
            ((TWindowBase *)this->message_window)->close();
            this->message_window = 0U;
        }
        if ((u32) this->m_84 == 0U) {
            this->m_84 = ((u32 (*)(void))TWindowSubComCard::init_layout)();
        }
        if ((u32) this->m_74 == 0U) {
            this->m_24 = ((TWindowMenu *)this->m_84)->get_selected_value();
            this->m_74 = (uaddr)apply_selection(this->m_24);
        }
        ((TWindowMenu *)(this->m_84))->clear_flag_and_release();
        this->state = 0x3CU;
    case 0x3C:
        ((s32 (*)(int, int, void*))update_selection__17TWindowSubComCardFiii)(this->m_84, this->m_74, (void *) ((u8 *)this + 0x24));
        if (((TWindowMenu *)(this->m_84))->is_cancelled() != 0) {
            this->state = 0x39U;
            return;
        }
        if (((TWindowMenu *)(this->m_84))->is_decided() != 0) {
            this->state = 0x3DU;
            return;
        }
        break;
    case 0x3D:
        if ((u32) this->m_74 != 0U) {
            ((TWindowBase *)this->m_74)->close();
            this->m_74 = 0U;
        }
        if ((u32) this->confirm_window == 0U) {
            this->confirm_window = this->sub_802730E0();
        }
        this->state = 0x3EU;
    case 0x3E:
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_cancelled() != 0) {
            this->state = 0x3BU;
            return;
        }
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_child_visible() != 0) {
            if (((TWindowMessageYesNo *)(this->confirm_window))->get_selected_value() == 0) {
                TWindowSubComCard::remove_entry(((TWindowMenu *)this->m_84)->get_selected_value());
                this->m_1d = (u8) (this->m_1d | 2);
                this->state = 1U;
                return;
            }
            this->state = 0x3BU;
            return;
        }
        break;
    case 0x3F:
        this->m_68 = TWindowSubComCard::create_card_action_window();
        this->state = 0x40U;
    case 0x40:
        if (((TWindowMenu *)(this->m_68))->is_cancelled() != 0) {
            this->state = 0x39U;
            return;
        }
        if (((TWindowMenu *)(this->m_68))->is_decided() != 0) {
            this->state = ((TWindowMenu *)this->m_68)->get_selected_value();
            return;
        }
        break;
    case 0x41:
        if ((u32) this->confirm_window != 0U) {
            ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x70)))->close();
            this->confirm_window = 0U;
        }
        if ((u32) this->m_68 != 0U) {
            ((TWindowBase *)this->m_68)->close();
            this->m_68 = 0U;
        }
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->m_84 == 0U) {
            this->m_84 = (uaddr)TWindowSubComCard::send_cmd_133();
        }
        if ((u32) this->m_74 == 0U) {
            this->m_24 = ((TWindowMenu *)this->m_84)->get_selected_value();
            this->m_74 = (uaddr)send_command(this->m_24);
        }
        ((TWindowMenu *)(this->m_84))->clear_flag_and_release();
        this->state = 0x42U;
    case 0x42:
        TWindowSubComCard::update_display_value(this->m_84, this->m_74, (s32 *)&this->m_24);
        if (((TWindowMenu *)(this->m_84))->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_84))->is_decided() != 0) {
            this->state = 0x43U;
            return;
        }
        break;
    case 0x43:
        if ((u32) this->m_74 != 0U) {
            ((TWindowBase *)this->m_74)->close();
            this->m_74 = 0U;
        }
        if ((u32) this->confirm_window == 0U) {
            this->confirm_window = this->open_yesno_dialog();
        }
        this->state = 0x44U;
    case 0x44:
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_cancelled() != 0) {
            this->state = 0x41U;
            return;
        }
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_child_visible() != 0) {
            if (((TWindowMessageYesNo *)(this->confirm_window))->get_selected_value() == 0) {
                ((TWindowSubComCard *)(saddr)(((TWindowMenu *)this->m_84)->get_selected_value()))->update_press();
                this->m_1d = (u8) (this->m_1d | 2);
                this->state = 1U;
                return;
            }
            this->state = 0x41U;
            return;
        }
        break;
    case 0x45:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
    case 0x46:
        if ((u32) this->confirm_window != 0U) {
            ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x70)))->close();
            this->confirm_window = 0U;
        }
        if ((u32) this->m_68 != 0U) {
            ((TWindowBase *)this->m_68)->close();
            this->m_68 = 0U;
        }
        if ((u32) this->m_64 == 0U) {
            this->m_64 = ((u32 (*)(void*))TWindowSubComCard::create_player_select_window)((void *)this);
        }
        ((TWindowMenu *)(this->m_64))->clear_flag_and_release();
        this->state = 0x47U;
    case 0x47:
        if (((TWindowMenu *)(this->m_64))->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_64))->is_decided() != 0) {
            this->state = 0x48U;
            return;
        }
        break;
    case 0x48:
        if ((u32) this->confirm_window == 0U) {
            this->confirm_window = this->open_yesno_dialog();
        }
        this->state = 0x49U;
    case 0x49:
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_cancelled() != 0) {
            this->state = 0x46U;
            return;
        }
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_child_visible() != 0) {
            if (((TWindowMessageYesNo *)(this->confirm_window))->get_selected_value() == 0) {
                TWindowSubComCard::init_and_press_b(((TWindowMenu *)this->m_64)->get_selected_value());
                this->m_1d = (u8) (this->m_1d | 2);
                this->state = 1U;
                return;
            }
            this->state = 0x46U;
            return;
        }
        break;
    case 0x4A:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
    case 0x4B:
        if ((u32) this->confirm_window != 0U) {
            ((TWindowMessageYesNo *)(*(void **)((s8 *)this + 0x70)))->close();
            this->confirm_window = 0U;
        }
        if ((u32) this->m_68 != 0U) {
            ((TWindowBase *)this->m_68)->close();
            this->m_68 = 0U;
        }
        if ((u32) this->m_64 == 0U) {
            this->m_64 = TWindowSubComCard__sub_80272640((void *)this);
        }
        ((TWindowMenu *)(this->m_64))->clear_flag_and_release();
        this->state = 0x4CU;
    case 0x4C:
        if (((TWindowMenu *)(this->m_64))->is_cancelled() != 0) {
            this->state = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_64))->is_decided() != 0) {
            this->state = 0x4DU;
            return;
        }
        break;
    case 0x4D:
        if ((u32) this->confirm_window == 0U) {
            this->confirm_window = this->open_yesno_dialog();
        }
        this->state = 0x4EU;
    case 0x4E:
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_cancelled() != 0) {
            this->state = 0x4BU;
            return;
        }
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_child_visible() != 0) {
            if (((TWindowMessageYesNo *)(this->confirm_window))->get_selected_value() == 0) {
                TWindowSubComCard::init_and_press_a(((TWindowMenu *)this->m_64)->get_selected_value());
                this->m_1d = (u8) (this->m_1d | 2);
                this->state = 1U;
                return;
            }
            this->state = 0x4BU;
        }
        break;
    case 0x4F:
        break;
    }
}

void TWindowSubComCard::render() {  }

s32 TWindowSubComCard::create_menu(void) {
    saddr list;

    list = ((s32 (*)(s32, s32, s32))create_titled_window_menu_default)(get_window_layout_position(0x7F), 6, (saddr)TWindowSubStatusDisp::get_message_10(0x1D));
    ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x52)), 6, 3);
    ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x53)), 6, 0xB);
    ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x54)), 6, 0x1D);
    if (get_main_phase() == 0xF) {
        ((TWindowMenu *)list)->add_text_entry(get_message_text(0x49), 6, 0x27);
        ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x6D)), 6, 0x33);
        ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xF8)), 6, 0x39);
    } else {
        add_gray_text_entry((TWindowMenu *)list, (const char *)(get_message_text(0x49)), 6, 0x27);
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x6D)), 6, 0x33);
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0xF8)), 6, 0x39);
    }
    ((TWindowMenu *)list)->set_flag70_bit10();
    ((TWindowMenu *)list)->update_layout_height(179.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(list));
    return list;
}

s32 TWindowSubComCard__sub_8027353C(void) {
    saddr menu;
    saddr temp_r31_2;
    menu = ((s32 (*)(s32, s32, s32))create_titled_window_menu_default)((s32)(((s32)get_window_layout_position(0x82))), 2, (s32)((saddr)TWindowSubStatusDisp::get_message_10(0x1E)));
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x55)), 6, 5);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x56)), 6, 9);
    ((TWindowMenu *)menu)->set_flag70_bit10();
    ((TWindowMenu *)menu)->update_layout_height(213.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(menu));
    return menu;
}

s32 TWindowSubComCard__sub_8027346C(void) {
  saddr list;
  saddr temp_r31_2;
  temp_r31_2 = (0, (saddr)TWindowSubStatusDisp::get_message_10(0x1D));
  list = ((s32 (*)(s32, s32, s32))create_titled_window_menu_default)((s32)((int) get_window_layout_position(0x8B)), 2, (s32)((int) temp_r31_2));
  ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x57)), 6, 0x21);
  if (get_current_floor_area() == AREA_LOBBY)
  {
    ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x58)), 6, 0x25);
  }
  else
  {
    add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x58)), 6, 0x25);
  }
  ((TWindowMenu *)list)->set_flag70_bit10();
  temp_r31_2 = list;
  ((TWindowMenu *)temp_r31_2)->update_layout_height(186.0f);
  align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(((int) temp_r31_2)));
  return temp_r31_2;
}

u32 TWindowSubComCard__sub_8027337C() {
    s32 i;
    void *p;
    saddr w;
    u8 *name;
    w = create_titled_window_menu_default(get_window_layout_position(0x83), 0xC, TWindowSubStatusDisp::get_message_10(0x1F));
    i = 0;
    do {
        if (i != local_client_id && (p = get_player_by_client_id(i)) != NULL &&
            ((TObjPlayer *)p)->is_script_controlled() == 0 && ((TObjChara *)p)->obj_isState3_324() == 0 &&
            (name = (u8 *)p + 0x85C) != NULL) {
            ((TWindowMenu *)w)->add_text_entry((saddr)name, 7, i);
        }
        i++;
    } while (i < 0xC);
    if (((TWindowSubComCardList *)w)->get_field_72() <= 0) {
        add_gray_text_entry((TWindowMenu *)w, (const char *)(TWindowSubStatusDisp::get_message_10(0xD2)), 7, 0);
    }
    ((TWindowMenu *)w)->set_flag70_bit10();
    ((TWindowSubComCardList *)w)->set_scroll_target(213.0f, 124.0f);
    return w;
}

s32 TWindowSubComCard::create_single_entry_window(void) {
  saddr menu;
    menu = create_window_menu_default((void *)(((saddr)get_window_layout_position(0x84))), 1);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x38)), 3, 0);
    ((TWindowMenu *)menu)->set_flag_40();
    ((TWindowSubComCardList *)menu)->set_scroll_target(213.0f, 64.0f);
    return menu;
}

s32 TWindowSubComCard::open_menu(void) {
    saddr list;

    list = ((s32 (*)(s32, s32, s32))create_titled_window_menu_default)(get_window_layout_position(0x87), 5, (saddr)TWindowSubStatusDisp::get_message_10(0x1D));
    if (get_main_phase() == 0xF) {
        ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x59)), 6, 0xF);
    } else {
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x59)), 6, 0xF);
    }
    ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x101)), 6, 0x11);
    ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x102)), 6, 0x13);
    ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x63)), 6, 0x1B);
    ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x5A)), 6, 0x15);
    ((TWindowMenu *)list)->set_flag70_bit10();
    ((TWindowMenu *)list)->update_layout_height(206.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(list));
    return list;
}

s32 TWindowSubComCard::confirm_and_free() {
    saddr dialog;

    dialog = (saddr)TWindowMessageYesNo::create((void *)(this), this->m_20, 0, 0);
    open_yes_no_prompt(reinterpret_cast<TWindowMessageYesNo *>(dialog), (u32)((saddr)TWindowSubStatusDisp::get_message_10(0x20)), (s32)((saddr)TWindowSubStatusDisp::get_message_10(0x39)), (s32)(get_window_layout_position(0x88)), 205.0f);
    ((TWindowMessageYesNo *)dialog)->set_menu_selected_index(1);
    ((TWindowMessageYesNo *)dialog)->set_choice_menu_flag70_bit10();
    return dialog;
}

s32 TWindowSubComCard::sub_802730E0() {
    saddr window;
    window = (saddr)TWindowMessageYesNo::create((void *)(this), this->m_20, 0, 0);
    ((TWindowMessageYesNo *)window)->open_yes_no_prompt_with_text((saddr)(TWindowSubStatusDisp::get_message_10(0xFC)), (s32)(get_window_layout_position(0x96)), 213.0f);
    ((TWindowMessageYesNo *)window)->set_menu_selected_index(1);
    ((TWindowMessageYesNo *)window)->set_choice_menu_flag70_bit10();
    return window;
}

s32 TWindowSubComCard::open_yesno_dialog() {
    saddr dialog;

    dialog = (saddr)TWindowMessageYesNo::create((void *)(this), this->m_20, 0, 0);
    open_yes_no_prompt(reinterpret_cast<TWindowMessageYesNo *>(dialog), (u32)((saddr)TWindowSubStatusDisp::get_message_10(0x20)), (s32)((saddr)TWindowSubStatusDisp::get_message_10(0x100)), (s32)(get_window_layout_position(0x97)), 213.0f);
    ((TWindowMessageYesNo *)dialog)->set_menu_selected_index(1);
    ((TWindowMessageYesNo *)dialog)->set_choice_menu_flag70_bit10();
    return dialog;
}

s32 TWindowSubComCard__sub_80273004(void) {
    saddr r = create_titled_window_menu_default(get_window_layout_position(0x89), 8, (void*)TWindowSubStatusDisp::get_message_10(0x21));
    ((TWindowMenu *)r)->set_flag70_bit10();
    return r;
}
}
#pragma push
#pragma opt_loop_invariants off
extern "C" {
void TWindowSubComCard::rebuild_com_card_list(saddr list_window) {
    s32 n;
    u32 cur;
    s32 i;
    s16 sel;
    s16 pos;
    void *e;
    cur = ((TWindowMenu *)list_window)->get_selected_value();
    sel = -1;
    TLobby::clear_flag_bit2();
    pos = ((TWindowShortListCtrl *)list_window)->get_cursor_pos();
    ((TWindowSubComCardList *)list_window)->reset_entries();
    n = TLobby::get_com_card_data();
    for (i = n - 1; i >= 0; i--) {
        e = TLobby::get_com_card_entry(i);
        ((TWindowMenu *)list_window)->add_text_entry((saddr)(reinterpret_cast<GuildCardRecord *>(e)->get_sub_obj()), 7, ((GuildCardRecord *)e)->get_serial());
        if (cur == ((GuildCardRecord *)e)->get_serial()) {
            sel = (n - 1) - i;
        }
    }
    if (n <= 0) {
        add_gray_text_entry((TWindowMenu *)list_window, (const char *)(TWindowSubStatusDisp::get_message_10(0xD3)), 6, -1);
    }
    ((TWindowMenu *)list_window)->update_layout_height(243.0f);
    if (sel == -1) {
        ((TWindowSubComCardList *)list_window)->set_selected_index(pos);
    } else {
        ((TWindowSubComCardList *)list_window)->set_selected_index(sel);
    }
}
}
#pragma pop
extern "C" {

void TWindowSubComCard::open_layout_window(void) {
    (saddr)TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0x80)), (const f32 *)com_card_layout_message_size, 1);
}
}
#pragma push
#pragma opt_loop_invariants off
extern "C" {
u32 TWindowSubComCard::sub_80272DE0() {
    s32 i;
    s32 count;
    s32 idx;
    saddr w;
    Ent_80272CB0 *e;
    List_80272CB0 *l;
    w = (saddr)create_choice_setting_window__17TWindowSubComCardFiii((const NJS_POINT2 *)get_window_layout_position(0x8C), (const NJS_POINT2 *)com_card_choice_list_size, 6);
    ((TWindowMenuInfomation *)w)->create_sub_window((const char *)get_message_text(0x49));
    l = (List_80272CB0 *)this->chr_select;
    idx = 0;
    count = l->count;
    e = l->ents;
    for (i = 0; i < count; i++, e++) {
        if (e->type == 0) {
            ((TWindowMenuInfomation *)w)->update_next_entry((saddr)e->name, (saddr)this->find_entry_rest(&this->m_30, idx), (s32)e->id);
            idx++;
        }
    }
    ((TWindowSubStatusDisp *)w)->add_text_entry(get_message_text(0x4A), 0);
    ((TWindowMenuInfomation *)w)->set_flag_10();
    return w;
}
}
#pragma pop
extern "C" {

s32 TWindowSubComCard::create_entry_list_window() {
    s32 i;
    u8 *card;
    u16 id;
    s32 n;
    s32 idx;
    saddr hard;
    saddr w;
    Ent_80272CB0 *e;
    List_80272CB0 *l;
    card = (u8 *)get_character_save_record(0xFFFF);
    hard = TLobby::open_hard_keyboard(*(void **)(((u8 *)this) + 0x20));
    w = (saddr)create_choice_setting_window__17TWindowSubComCardFiii((const NJS_POINT2 *)get_window_layout_position(0x8C), (const NJS_POINT2 *)com_card_entry_list_size, 6);
    ((TWindowMenuInfomation *)w)->create_sub_window((const char *)TWindowSubStatusDisp::get_message_10(0x6D));
    ((TWindowMenuInfomation *)w)->update_next_entry((saddr)((void*)TWindowSubStatusDisp::get_message_10(0x6D)), (saddr)this->get_message_10(hard), 0);
    l = *(List_80272CB0 **)(((u8 *)this) + 0x58);
    idx = -1;
    n = l->count;
    e = l->ents;
    for (i = 0; i < n; i++, e++) {
        if (e->type == 0) {
            idx++;
            if (e->id >= 500) {
                ((TWindowMenuInfomation *)w)->update_next_entry((saddr)e->name, (saddr)(this->find_entry_rest(card + 0x22EC, idx)), (s32)e->id);
                if (hard != 0) {
                    ((TWindowMenuInfomation *)w)->disable_entry_by_id(e->id);
                }
            }
        }
    }
    ((TWindowMenuInfomation *)w)->set_flag_10();
    return w;
}
}
#pragma push
#pragma opt_loop_invariants off
extern "C" {
s32 TWindowSubComCard::create_option_list_window(saddr entry_table, s32 key) {
    s32 i;
    s32 count;
    s32 idx;
    u16 val;
    u16 sel;
    saddr win;
    Entry_80272B60 *e;
    ChrSel_80272B60 *cs;
    win = create_titled_window_menu_default(get_window_layout_position(0x8D), 0x20, (void *)(saddr)((TWindowMenuInfomation *)this->entry_list_window)->find_entry_value_by_id(key));
    if (key == 0) {
        ((TWindowMenu *)win)->add_text_entry((saddr)this->get_message_10(0), 6, 0);
        ((TWindowMenu *)win)->add_text_entry((saddr)this->get_message_10(1), 6, 1);
        ((TWindowSubComCardList *)win)->set_selected_index(TLobby::open_hard_keyboard((void *)this->m_20));
    } else {
        sel = ((TWindowSubComCard *)entry_table)->find_value_by_key(key);
        cs = (ChrSel_80272B60 *)TWindowSubComCard::get_chr_select();
        count = cs->count;
        e = cs->e;
        idx = 0;
        i = 0;
        while (i < count) {
            if (e->id == key) {
                val = e->val;
                ((TWindowMenu *)win)->add_text_entry((saddr)e->name, 6, val);
                if (sel == val) {
                    ((TWindowSubComCardList *)win)->set_selected_index(idx);
                }
                idx++;
            }
            i++;
            e++;
        }
    }
    ((TWindowMenu *)win)->set_flag70_bit10();
    ((TWindowSubComCardList *)win)->set_scroll_target(405.0f, 124.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(win));
    return win;
}
}
#pragma pop
extern "C" {

u32 TWindowSubComCard__sub_80272A98(void *) {
    s32 i;
    s32 count;
    saddr w;
    ComCardRec_80272A98 *e;
    ComCardList_80272A98 *l;
    w = create_titled_window_menu_default(get_window_layout_position(0x8E), 0x20, TWindowSubStatusDisp::get_message_10(0x54));
    l = (ComCardList_80272A98 *)TWindowSubComCard::get_com_count();
    count = l->count;
    e = l->entries;
    for (i = 0; i < count; i++, e++) {
        ((TWindowMenu *)w)->add_text_entry((saddr)e->name, 6, i);
    }
    if (((TWindowSubComCardList *)w)->get_field_72() <= 0) {
        add_gray_text_entry((TWindowMenu *)w, (const char *)(TWindowSubStatusDisp::get_message_10(0xD2)), 7, 0);
    }
    ((TWindowMenu *)w)->set_flag70_bit10();
    ((TWindowSubComCardList *)w)->set_scroll_target(223.0f, 124.0f);
    return w;
}
void TWindowSubComCard::open_mode4_window(void) {
    (saddr)TWindowMessage::create((const NJS_POINT2 *)(get_window_layout_position(0x8f)), (const f32 *)com_card_mode4_message_size, 1);
}

s32 TWindowSubComCard::create_menu_window(void) {
  saddr list;
  saddr title;
  title = (0, ((saddr)(void*)TWindowSubStatusDisp::get_message_10(0x1D)));
  list = create_titled_window_menu_default((int)((s32)((int) get_window_layout_position(0x8f))), 2, (void *)((saddr) title));
  ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x57)), 6, 0x21);
  if (get_current_floor_area() == AREA_LOBBY)
  {
    ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x58)), 6, 0x25);
  }
  else
  {
    add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0x58)), 6, 0x25);
  }
  ((TWindowMenu *)list)->set_flag70_bit10();
  title = list;
  ((TWindowMenu *)title)->update_layout_height(206.0f);
  align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(((int) title)));
  return title;
}

s32 TWindowSubComCard__sub_802728CC(void) {
    void *msg;
    saddr w;
    w = create_titled_window_menu_default(get_window_layout_position(0x90), 2, msg = (void*)TWindowSubStatusDisp::get_message_10(0xF8));
    ((TWindowMenu *)w)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xFA)), 6, 0x3B);
    if (TWindowSubComCard::init_card() != 0) {
        ((TWindowMenu *)w)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xFB)), 6, 0x3F);
    } else {
        add_gray_text_entry((TWindowMenu *)w, (const char *)(TWindowSubStatusDisp::get_message_10(0xFB)), 6, 0x3F);
    }
    ((TWindowMenu *)w)->set_flag70_bit10();
    ((TWindowMenu *)w)->update_layout_height(233.0f);
    return w;
}

s32 TWindowSubComCard::create_card_action_window() {
    saddr menu;
    void *temp_r31_2;
    menu = create_titled_window_menu_default(((s32)get_window_layout_position(0x93)), 3, (void*)TWindowSubStatusDisp::get_message_10(0x1D));
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xFD)), 6, 0x41);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xFE)), 6, 0x45);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xFF)), 6, 0x4A);
    ((TWindowMenu *)menu)->set_flag70_bit10();
    ((TWindowMenu *)menu)->update_layout_height(193.0f);
    return menu;
}
}
#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
extern "C" {
s32 TWindowSubComCard::create_player_select_window(void) {
    s32 i;
    VObj_18_80272714 *p;
    saddr w;
    w = create_titled_window_menu_default(get_window_layout_position(0x94), 0xC, (void*)TWindowSubStatusDisp::get_message_10(0x2D));
    i = 0;
    do {
        if (i != local_client_id && (p = (VObj_18_80272714 *)get_player_by_client_id(i)) != NULL &&
            ((TObjPlayer *)p)->is_script_controlled() == 0 && ((TObjChara *)p)->obj_isState3_324() == 0) {
            ((TWindowMenu *)w)->add_text_entry((saddr)p->m10(), 7, i);
        }
        i++;
    } while (i < 0xC);
    if (((TWindowSubComCardList *)w)->get_field_72() <= 0) {
        add_gray_text_entry((TWindowMenu *)w, (const char *)(TWindowSubStatusDisp::get_message_10(0xD2)), 7, 0);
    }
    ((TWindowMenu *)w)->set_flag70_bit10();
    ((TWindowSubComCardList *)w)->set_scroll_target(223.0f, 184.0f);
    return w;
}
}
#pragma pop
extern "C" {

u32 TWindowSubComCard__sub_80272640(void *) {
    s32 n;
    s32 i;
    ShortMailEntry *e;
    saddr w;
    w = create_titled_window_menu_default(get_window_layout_position(0x95), 8, TWindowSubStatusDisp::get_message_10(0x2E));
    n = TLobby::get_short_mail_ctrl();
    for (i = n - 1; i >= 0; i--) {
        e = get_short_mail_entry(i);
        ((TWindowMenu *)w)->add_text_entry((saddr)e->get_sender_name(), 7, e->get_id());
    }
    if (n <= 0) {
        add_gray_text_entry((TWindowMenu *)w, (const char *)(TWindowSubStatusDisp::get_message_10(0xD1)), 7, 0);
    }
    ((TWindowMenu *)w)->set_flag70_bit10();
    ((TWindowSubComCardList *)w)->set_scroll_target(223.0f, 184.0f);
    return w;
}

saddr TWindowSubComCard::create(void) {
    saddr window;
    saddr window_layout_position;

    window_layout_position = get_window_layout_position(0x98);
    window = (saddr)TWindowMessage::create((const NJS_POINT2 *)window_layout_position, (const f32 *)com_card_message_size, 1);
    ((TWindowBase *)window)->set_depth(50090.0f);
    return window;
}

s32 create_keyboard__17TWindowSubComCardFi(saddr parent) {
    saddr keyboard;
    s32 keyboard_mode;

    keyboard_mode = TWindowSubComCard::get_keyboard_mode();
    keyboard = (saddr)new TKeyBoardControl((TObject *)parent, 0xC6, 3, 4, local_client_id);
    ((TKeyBoardControl *)keyboard)->set_text((char *)((TWindowComCard *)(saddr)keyboard_mode)->get_kbd_ptr());
    ((TKeyBoardControl *)keyboard)->set_sub_position((u8 *)(get_window_layout_position(0xBB)));
    ((TKeyBoardControl *)keyboard)->set_flag62_bit2();
    ((TKeyBoardControl *)keyboard)->set_soft_flag60_bit1();
    return keyboard;
}

s32 create_keyboard__17TWindowSubComCardFii(saddr parent, saddr card) {
    saddr keyboard;

    keyboard = (saddr)new TKeyBoardControl((TObject *)parent, 0xC6, 3, 4, local_client_id);
    ((TKeyBoardControl *)keyboard)->set_text((char *)(saddr)((TWindowSubComCard *)card)->get_card_entry_data());
    ((TKeyBoardControl *)keyboard)->set_sub_position((u8 *)(get_window_layout_position(0xBB)));
    ((TKeyBoardControl *)keyboard)->set_flag62_bit2();
    ((TKeyBoardControl *)keyboard)->set_soft_flag60_bit1();
    return keyboard;
}

void TWindowSubComCard::update_display_value(uaddr list_window, uaddr card_window, s32 *last_selected) {
  saddr card_entry;
    s32 selected_value;

    card_entry = reinterpret_cast<saddr>(TWindowSubComCard::get_card_entry(0));
    if ((list_window != 0U) && (card_window != 0U)) {
        selected_value = ((TWindowMenu *)list_window)->get_selected_value();
        if (selected_value != (s32) *last_selected) {
            *last_selected = selected_value;
            ((TWindowComCard *)card_window)->set_display_value(selected_value, card_entry);
        }
    }
}

void update_selection__17TWindowSubComCardFiii(s32 list_window, s32 card_window, s32 last_selected) {
    s32 tmp = TWindowSubComCard::get_card_slot(0);
    ((s32 (*)(s32, s32, s32, s32))update_selection__17TWindowSubComCardFUiUiPvi)(list_window, card_window, last_selected, tmp);
}

void update_selection__17TWindowSubComCardFUiUiPvi(uaddr list_window, uaddr card_window, s32 *last_selected, s32 cards) {
    s32 selected_value;

    if ((list_window != 0U) && (card_window != 0U)) {
        selected_value = ((TWindowMenu *)list_window)->get_selected_value();
        if (selected_value != (s32) *last_selected) {
            *last_selected = selected_value;
            TWindowComCard__sub_80249920(card_window, selected_value, cards);
        }
    }
}

void TWindowSubComCard::set_help_message(s32 help_index) {
    if ((s32) this->m_28 != help_index) {
        this->m_28 = help_index;
        ((TWindowMessage *)(this->message_window))->append_line((s32)(saddr)TWindowSubStatusDisp::get_message_10((saddr)((void *)com_card_help_message_ids[help_index])), 0x80);
    }
}

void TWindowSubComCard::set_selected_card(s32 card_index) {
    u8 *card_data;
    saddr guild_card_record;
    Rec_80272290 *cnt;
    if ((s32)this->m_28 != card_index) {
        this->m_28 = (uaddr)card_index;
        cnt = (Rec_80272290 *)TWindowSubComCard::get_com_count();
        card_data = cnt[card_index].f4;
        load_selected_guild_card_record((saddr)card_data, card_index * 0xD4);
        guild_card_record = ((s32 (*)(void))get_selected_guild_card_record)();
        text_builder_reset();
        text_builder_append((card_data + 0x14));
        text_builder_append((u8 *)(reinterpret_cast<GuildCardRecord *>(guild_card_record)->get_name()));
        text_builder_append((u8 *)"\n");
        text_builder_append((u8 *)(((void* (*)(int))TWindowSubComCard__sub_8027523C)(guild_card_record)));
        text_builder_append((u8 *)"\n");
        text_builder_append((u8 *)(reinterpret_cast<GuildCardRecord *>(guild_card_record)->get_card_data_ptr()));
        ((TWindowMessage *)this->message_window)->append_line((saddr)get_shared_text_buffer(), 0x82);
    }
}

void TWindowSubComCard::set_card_index(s32 card_index) {
    if ((s32) this->m_28 != card_index) {
        this->m_28 = card_index;
        ((TWindowMessage *)(this->message_window))->append_line((saddr)((TWindowSubComCard *)(saddr)card_index)->get_card_entry_data(), 0x82);
    }
}
}
#pragma push
#pragma scheduling off
extern "C" {
void TWindowSubComCard::sub_802721D8() {
  u8 *new_var;
  saddr src;
  u8 *lobby;
  u8 *message;
  src = (saddr)((TKeyBoardControl *)(*((u8 **) (((s8 *) ((u8 *)this)) + 0x80))))->realloc_buffer();
  lobby = (u8 *) ((u8* (*)(void))get_selected_guild_card_record)();
  TWindowSubComCard::mask_profanity_words((char *)src, (char *)get_shared_text_buffer());
  new_var = (u8 *)get_shared_text_buffer();
  message = (u8 *) new_var;
  TLobby::send_simple_mail(reinterpret_cast<GuildCardRecord *>(lobby)->get_id(), message);
  mem_free((void *)src);
}
}
#pragma pop
extern "C" {
void TWindowSubComCard::cleanup(void *p) {
    TWindowMenu *menu = *reinterpret_cast<TWindowMenu **>(static_cast<u8 *>(p) + 0x84);
    const GuildCardSlot *slot = TWindowSubComCard::get_card_entry(menu->get_selected_value());
    TLobby::send_find_user_self_tag(slot->entry.get_card_id());
}
u8 *TWindowSubComCard::send_cmd_133() { return fn_802754EC(get_window_layout_position(133)); }
void TWindowSubComCard::init_layout(void) {
    s32 card_slot;

    card_slot = TWindowSubComCard::get_card_slot(0);
    TWindowSubComCard::create_card_list(get_window_layout_position(0x91), card_slot, 0x1C, 1);
}
void *TWindowSubComCard::send_command(saddr index) {
    return TWindowComCard::create((void *)(get_window_layout_position(0x86)), (void *)index);
}
u8 *TWindowSubComCard::apply_selection(s32 index) {
    s32 card_slot;

    card_slot = TWindowSubComCard::get_card_slot(0);
    return TWindowComCard::create_for_card(get_window_layout_position(0x92), index, card_slot);
}

void *TWindowSubComCard::get_message_10(s32 index) { return TWindowSubStatusDisp::get_message_10(index + 0xa6); }

u8 *TWindowSubComCard::find_entry_rest(void *arg1_arg, s32 idx) {
    Key_80272034 *arg1 = (Key_80272034 *)arg1_arg;
    Tbl_80272034 *t = ((Win_80272034 *)this)->tbl;
    Ent_80272034 *e;
    Key_80272034 *k;
    s32 i;
    k = arg1 + idx;
    e = t->e;
    for (i = 0; i < t->count; i++, e++) {
        if (e->a == k->a && e->b == k->b) return e->rest;
    }
    return 0;
}
void TWindowSubComCard::sub_80271F04(void *arr, s32 key, saddr val) {
    s32 i;
    if (key == 0) {
        if (val != TLobby::open_hard_keyboard(*(void **)(((u8 *)this) + 0x20))) {
            ((u8 *)this)[0x1D] |= 1;
            ((TWindowSubComCard *)(*(void **)(((u8 *)this) + 0x20)))->set_com_param(val);
            ((TWindowMenuInfomation *)this->entry_list_window)->set_entry_string_by_id(this->get_message_10(val), 0);
            if (val != 0) {
                for (i = 0; i < 5; i++) {
                    if (((Ent_80271F04 *)arr)[i].id != 0) {
                        ((TWindowMenuInfomation *)(*(void **)(((u8 *)this) + 0x7C)))->disable_entry_by_id(((Ent_80271F04 *)arr)[i].id);
                    }
                }
            } else {
                for (i = 0; i < 5; i++) {
                    if (((Ent_80271F04 *)arr)[i].id != 0) {
                        ((TWindowMenuInfomation *)(*(void **)(((u8 *)this) + 0x7C)))->mark_entry_by_id(((Ent_80271F04 *)arr)[i].id);
                    }
                }
            }
        }
    } else if (val != ((TWindowSubComCard *)((Ent_80271F04 *)arr))->find_value_by_key(key)) {
        ((u8 *)this)[0x1D] |= 1;
        set_value_by_key(((Ent_80271F04 *)arr), key, val);
        ((TWindowMenuInfomation *)(*(void **)(((u8 *)this) + 0x7C)))->set_entry_string_by_id((void *)((TWindowSubComCard *)(((TWindowMenu *)(*(void **)(((u8 *)this) + 0x64)))->get_selected_entry()))->get_field_20(), key);
    }
}

void TWindowSubComCard::send_state_if_dirty() {
    if (this->m_1d & 1) {
        TLobby::send_card_window_state();
        this->m_1d = (s8) (this->m_1d & ~1);
    }
}

void TWindowSubComCard::handle_close_flag() {
    if (this->m_1d & 2) {
        TLobby::send_status_packet();
        this->m_1d = (u8) (this->m_1d & 0xFFFFFFFD);
    }
}
}
