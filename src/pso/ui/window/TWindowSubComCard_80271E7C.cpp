#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/keyboard/TKeyBoardControl.h"
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
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"

#include "types.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"

class TChCrTagPlBack;
#include "pso/ui/window/TWindowComCard.h"
#include "pso/network/TProtocol.h"
#include "pso/unk/GuildCardRecord.h"

#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TUnk_804D0658.h"
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

const char *TWindowSubComCard__class_name = "TWindowSubComCard";

// Window sizes {width, height} passed to TWindowMessage::create / the choice-setting window.
static const f32 com_card_layout_message_size[2] = {188.0f, 120.0f};
static const f32 com_card_choice_list_size[2] = {405.0f, 144.0f};
static const f32 com_card_entry_list_size[2] = {405.0f, 144.0f};
static const f32 com_card_mode4_message_size[2] = {206.0f, 122.0f};
static const f32 com_card_message_size[2] = {206.0f, 82.0f};
static const s32 com_card_help_message_ids[] = {0x47, 0x48, 0x49, 0x4A, 0x4B, 0xF9, 0};

struct Ent_80272034 { u16 a; u16 b; u8 rest[0x1c]; };

struct Tbl_80272034 { u8 pad0; u8 count; u8 pad2[2]; Ent_80272034 e[1]; };

struct Win_80272034 { u8 pad[0x58]; Tbl_80272034 *tbl; };

struct Key_80272034 { u32 a; u32 b; };

struct Ent_80271F04 {
    u32 id;
    u32 value;
};
extern "C" {
s32 *get_shared_text_buffer(void);
}
s32 *get_selected_guild_card_record(void);
extern "C" {
void set_value_by_key(void *, u16, s32);
s32 open_hard_keyboard__6TLobbyFPv(void *);
void get_message_10__17TWindowSubComCardFPvPv(void* p, void* a1);
void apply_selection__17TWindowSubComCardFi(s32 arg0);
void cleanup__17TWindowSubComCardFPv(void* p);
void init_layout__17TWindowSubComCardFv(void);
void send_cmd_133__17TWindowSubComCardFv(void);
void send_command__17TWindowSubComCardFi(s32 arg0);
int send_find_user_self_tag__6TLobbyFl(void);
int get_card_entry__17TWindowSubComCardFi(void);
int get_selected_value__11TWindowMenuFv(void*);
s32 get_window_layout_position(s32 a0 = 0);
int fn_802754EC(void);
int get_card_id__17TWindowSubComCardFv(void);
int get_message_10__20TWindowSubStatusDispFl(void*);

typedef void *(*GetMsg_80271F04)(void *, void *);
}

struct Rec_80272290 { s32 f0; u8 f4[0xD0]; };
extern "C" {
Rec_80272290 *get_com_count__17TWindowSubComCardFv();
void text_builder_append(u8 *str);
}
void text_builder_reset();
extern "C" {
void load_selected_guild_card_record(int, int);
void* TWindowSubComCard__sub_8027523C(void* p);

void update_selection__17TWindowSubComCardFUiUiPvi(u32 arg0, u32 arg1, s32 *arg2, s32 arg3);
void TWindowComCard__sub_80249920(s32 arg0, s32 arg1, s32 arg2);
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
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 draw_card_icon__17TWindowSubComCardFll(int, int, void *);
s32 align_menu_entry_positions(s32);
s32 create_menu_window__17TWindowSubComCardFv(void);
s32 create__14TWindowMessageFPvll(s32, s32 *, s32);
void open_mode4_window__17TWindowSubComCardFv(void);
void open_layout_window__17TWindowSubComCardFv(void);
s32 TWindowSubComCard__sub_80273004(void);
s32 get_character_save_record(u32 arg0);
s32 create_choice_setting_window__17TWindowSubComCardFiii(s32 arg0, s32 arg1, s32 arg2);
void create_sub_window__20TWindowChoiceSettingFPvi(void *arg0, s32 arg1);
s32 init_card__17TWindowSubComCardFv();
s32 TWindowSubComCard__sub_802728CC(void);
ChrSel_80272B60 *get_chr_select__17TWindowSubComCardFv();
void *get_player_by_client_id(s32 i);
extern s32 local_client_id;
s32 create_player_select_window__17TWindowSubComCardFv(void);
void rebuild_com_card_list__17TWindowSubComCardFii(s32 arg0, s32 arg1);
s32 create__17TWindowSubComCardFv(void);
s32 create_keyboard__17TWindowSubComCardFi(s32 arg0);
s32 create_keyboard__17TWindowSubComCardFii(s32 arg0, s32 arg1);
void update_display_value__17TWindowSubComCardFUiUiPv(u32 arg0, u32 arg1, s32 *arg2);
void update_selection__17TWindowSubComCardFiii(s32 arg0, s32 arg1, s32 arg2);
s32 __nw__7TObjectFUl(s32);
s32 set_depth__11TWindowBaseFf(f32);

struct ComCardRec_80272A98 { u32 id; char name[0xD0]; };

struct ComCardList_80272A98 { u8 pad0; u8 count; u8 pad2[2]; ComCardRec_80272A98 entries[1]; };

typedef void *(*GetMsg_80272CB0)(void *, void *);

s32 get_message_text(s32);
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
s32 check_room_seq_4__16TAdChrSelASlotGCFl(void *, int);
s32 create_single_entry_window__17TWindowSubComCardFv(void);
s32 TWindowSubComCard__sub_8027353C(void);
s32 TWindowSubComCard__sub_8027346C(void);
s32 TWindowSubComCard__sub_800778B4(void *, int);
void TWindowSubComCard__sub_8007AF10(s32 arg0);
s32 update_press__17TWindowSubComCardFv(int);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 play_sound_effect(int, int, int, int);
s32 TLobby__sub_8024259C();
s32 fn_80244958(int, int);
void fn_802449E0(u8 *arg0);
}
void window_request_show(void *arg0);
s32 is_com_card_active();
extern "C" {
void TWindowSubComCard__sub_80249144(void *arg0);
void fn_8024AB54(s32 arg0);
void TWindowSubComCard__sub_8024AB98(s32 arg0);
s32 update_selected_entry__17TWindowSubComCardFv(int);
s32 send_packet__6TLobbyFll(void *, void *);
u32 TWindowSubComCard__sub_80272640(void *);
u32 TWindowSubComCard__sub_80272A98(void *);
s32 open_menu__17TWindowSubComCardFv(void);
u32 TWindowSubComCard__sub_8027337C();
s32 create_menu__17TWindowSubComCardFv(void);
s32 open_confirm_prompt__19TWindowSubShortMailFPvi(void *arg0, s32 arg1);
s32 create_keyboard__19TWindowSubShortMailFv(void);
extern s32 controller_input_state[];
extern s32 TLobby__protocol_instance;
s32 free_member__17TWindowSubComCardFv(s32, s32);
s32 forward_slot_selection__16TAdChrSelASlotGCFPvPv(s32, s32, s32, f32);
s32 create__19TWindowMessageYesNoFPvPvPvPv(void *, s32, s32, s32);
void open_yes_no_prompt(TChCrTagPlBack *arg0, u32 arg1, s32 arg2, s32 arg3, f32 farg0);

void TWindowSubComCard__sub_80077980(void *);
}

struct SelectedGuildCardRecord { s32 value; u8 remaining[0xB8]; };
extern SelectedGuildCardRecord selected_guild_card_record;
extern "C" {
void fn_80247ED8(void *p);
}

void TWindowSubComCard::set_display_page() {
    s32 arg0 = (s32)this;
    set_page((s16)((int) (((s16 (*)(void))get_selected_value__11TWindowMenuFv)())));
}
void TWindowSubComCard::set_flag_10() { *(u16*)((char*)this + 0x70) |= 0x10; }
void TWindowSubComCard::set_page(s16 v) { *(s16*)((char*)this + 0x7a) = v; }
s16 TWindowSubComCardList::get_field_72() { return *(s16 *)&this->m_72; }
void TWindowSubComCard::destroy_keyboard() { void* m = *(void* *)&this->m_28; if (m) fn_80247ED8(m); }
void*TWindowSubComCard::get_sub_obj() { return (char*)this + 0x8; }
void*TWindowSubComCard::get_name() { return (char*)this + 0x19; }
void* TWindowSubComCard__sub_8027523C(void* p) { return (char*)p + 0x2a; }

void*TWindowSubComCard::get_card_data_ptr() { return (char*)this + 0x3b; }

s32 *get_selected_guild_card_record(void) {
    return &selected_guild_card_record.value;
}
extern "C" {

void TWindowSubComCard::set_com_param(s32 arg1) {
    s32 arg0 = (s32)this;
    TWindowKeyBoardHard::set_card_window_flags((void *)arg0, (s32)(arg1 << 0x12), (s32)0xFFFBFFFF);
}
}

TWindowSubComCard::TWindowSubComCard(TObject *object, void *arg2) : TObject(object) {
    this->m_name = TWindowSubComCard__class_name;
    *(void **)((s8 *)this + 0x5C) = object;
    *(void **)((s8 *)this + 0x20) = arg2;
    this->m_60 = 0;
    this->m_64 = 0;
    this->m_74 = 0;
    this->m_78 = 0;
    this->m_68 = 0;
    this->m_6c = 0;
    this->m_70 = 0;
    this->m_80 = 0;
    this->m_84 = 0;
    this->m_7c = 0;
    this->m_58 = 0;
    this->m_1d = 0;
    this->m_24 = -1;
    TWindowSubComCard__sub_80077980((void *)((char *)this + 48));
    this->m_1c = 0;
}
extern "C" {

TWindowSubComCard::~TWindowSubComCard() {
    handle_close_flag();
    send_state_if_dirty();
    if ((u8) m_1c == 0x26) {
        TWindowSubComCard__sub_8024AB98(m_20);
    }
    if (m_7c != 0U) {
        ((TWindowBase *)m_7c)->close();
        m_7c = 0U;
    }
    if (m_70 != 0U) {
        ((TWindowSubComCard *)m_70)->close();
        m_70 = 0U;
    }
    if (m_84 != 0U) {
        ((TWindowBase *)m_84)->close();
        m_84 = 0U;
    }
    if (m_80 != 0U) {
        ((TObject *)m_80)->queue_destruction();
        m_80 = 0U;
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
    if (m_6c != 0U) {
        ((TWindowBase *)m_6c)->close();
        m_6c = 0U;
    }
    if (m_60 != 0U) {
        ((TWindowBase *)m_60)->close();
        m_60 = 0U;
    }
}
void TWindowSubComCard::run_task() {
    s32 src;
    s32 character_save_record;
    s32 temp_r29_7;
    s32 temp_r29_8;
    s32 keyboard_mode;
    u32 temp_r30_2;
    s32 temp_r4;
    s32 var_r29;
    u8 temp_r0;
    s32 temp_r29_6;
    s32 temp_r30_3;
    u8 *temp_r3;
    u8 *temp_r3_2;
    temp_r0 = this->m_1c;
    switch (temp_r0) {
    case 0x0:
    case 0x1:
        this->send_state_if_dirty();
        if ((u32) this->m_80 != 0U) {
            ((TObject *)(*(void **)((s8 *)this + 0x80)))->queue_destruction();
            this->m_80 = 0U;
        }
        if ((u32) this->m_7c != 0U) {
            ((TWindowBase *)this->m_7c)->close();
            this->m_7c = 0U;
        }
        if ((u32) this->m_70 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x70)))->close();
            this->m_70 = 0U;
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
        if ((u32) this->m_6c != 0U) {
            ((TWindowBase *)this->m_6c)->close();
            this->m_6c = 0U;
        }
        if ((u32) this->m_60 == 0U) {
            this->m_60 = ((s32 (*)(void *)) create_menu__17TWindowSubComCardFv)((void *)this);
        }
        if ((u32) this->m_6c == 0U) {
            this->m_6c = ((u32 (*)(void*))open_layout_window__17TWindowSubComCardFv)((void *)this);
            this->m_28 = -1;
        }
        ((TWindowSubComCard *)(this->m_60))->clear_flag_and_release();
        this->m_1c = 2U;
    case 0x2:
        this->set_help_message((int) (((TWindowShortListCtrl *)(this->m_60))->get_cursor_pos()));
        if (((TWindowMenu *)(this->m_60))->is_cancelled() != 0) {
            temp_r3 = (u8 *)(*(u8 **)((s8 *)this + 0x5C));
            ((VObj_18_204a81 *)(temp_r3))->m7();
            this->m_1c = 0x4FU;
            return;
        }
        if (((TWindowMenu *)(this->m_60))->is_decided() != 0) {
            if ((u32) this->m_6c != 0U) {
                ((TWindowBase *)this->m_6c)->close();
                this->m_6c = 0U;
            }
            this->m_1c = ((TWindowMenu *)this->m_60)->get_selected_value();
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
        ((TWindowSubComCard *)(this->m_64))->clear_flag_and_release();
        ((TWindowSubComCard *)(this->m_64))->clear_transition_flag();
        this->m_1c = 4U;
    case 0x4:
        if (((TWindowMenu *)(this->m_64))->is_cancelled() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_64))->is_decided() != 0) {
            this->m_1c = ((TWindowMenu *)this->m_64)->get_selected_value();
            return;
        }
        break;
    case 0x5:
        if ((u32) this->m_68 == 0U) {
            this->m_68 = TWindowSubComCard__sub_8027337C();
        }
        ((TWindowOptionCtrl *)(this->m_64))->open();
        this->m_1c = 6U;
    case 0x6:
        if (((TWindowMenu *)(this->m_68))->is_cancelled() != 0) {
            this->m_1c = 3U;
            return;
        }
        if (((TWindowMenu *)(this->m_68))->is_decided() != 0) {
            TWindowSubComCard__sub_8007AF10(((TWindowMenu *)this->m_68)->get_selected_value());
            this->m_1c = 7U;
            return;
        }
        break;
    case 0x7:
        if ((u32) this->m_68 != 0U) {
            ((TWindowBase *)this->m_68)->close();
            this->m_68 = 0U;
        }
        if ((u32) this->m_68 == 0U) {
            this->m_68 = ((s32 (*)(void *)) create_single_entry_window__17TWindowSubComCardFv)((void *)this);
        }
        this->m_1c = 8U;
    case 0x8:
        if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)controller_input_state + 0x20), 6) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)controller_input_state + 0x160), 6) != 0)) {
            this->m_1c = 3U;
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
        this->m_80 = ((u32 (*)(void*))create_keyboard__17TWindowSubComCardFi)((void *)this);
        this->m_1c = 0xAU;
    case 0xA:
        if (((TKeyBoardControl *)(this->m_80))->is_cancelled() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TKeyBoardControl *)(this->m_80))->is_confirmed() != 0) {
            src = (s32)((TKeyBoardControl *)(this->m_80))->realloc_buffer();
            TWindowSubComCard::mask_profanity_words((char *)src, (char *)get_shared_text_buffer());
            keyboard_mode = TWindowSubComCard::get_keyboard_mode();
            ((TWindowSubComCard *)keyboard_mode)->set_text((void *)(get_shared_text_buffer()));
            mem_free((void *)src);
            this->m_1c = 1U;
            return;
        }
        break;
    case 0xB:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->m_6c == 0U) {
            this->m_6c = ((u32 (*)(void*))create__17TWindowSubComCardFv)((void *)this);
            fn_802449E0((u8 *)this->m_6c);
            this->m_28 = -1;
        }
        if ((u32) this->m_84 == 0U) {
            this->m_84 = ((u32 (*)(void))send_cmd_133__17TWindowSubComCardFv)();
        }
        if ((u32) this->m_74 == 0U) {
            this->m_24 = ((TWindowMenu *)this->m_84)->get_selected_value();
            this->m_74 = ((u32 (*)(int))send_command__17TWindowSubComCardFi)(this->m_24);
        }
        fn_80244958(this->m_6c, (int) (get_window_layout_position(0x99)));
        ((TWindowLockOn *)(this->m_6c))->request_close();
        ((TWindowSubComCard *)(this->m_84))->clear_flag_and_release();
        this->m_1c = 0xCU;
    case 0xC:
        ((s32 (*)(int, int, void*))update_display_value__17TWindowSubComCardFUiUiPv)(this->m_84, this->m_74, (void *) ((u8 *)this + 0x24));
        this->set_card_index((int) (((TWindowMenu *)this->m_84)->get_selected_value()));
        if (TWindowShortListCtrl__check_controller_button((void *) ((u8 *)controller_input_state + 0x20), 0x400) != 0) {
            if (((TWindowBase *)(this->m_6c))->sub_80244994() != 0) {
                ((TWindowLockOn *)(this->m_6c))->request_close();
            } else {
                window_request_show((void *)this->m_6c);
            }
        }
        if (((TWindowMenu *)(this->m_84))->is_cancelled() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_84))->is_decided() != 0) {
            this->m_1c = 0xDU;
            return;
        }
        break;
    case 0xD:
        if ((u32) this->m_6c != 0U) {
            ((TWindowBase *)this->m_6c)->close();
            this->m_6c = 0U;
        }
        if ((u32) this->m_70 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x70)))->close();
            this->m_70 = 0U;
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
            this->m_64 = ((s32 (*)(void *)) open_menu__17TWindowSubComCardFv)((void *)this);
        }
        ((TWindowSubComCard *)(this->m_64))->clear_transition_flag();
        ((TWindowSubComCard *)(this->m_64))->clear_flag_and_release();
        this->m_1c = 0xEU;
    case 0xE:
        if (((TWindowMenu *)(this->m_64))->is_cancelled() != 0) {
            this->m_1c = 0xBU;
            return;
        }
        if (((TWindowMenu *)(this->m_64))->is_decided() != 0) {
            this->m_1c = ((TWindowMenu *)this->m_64)->get_selected_value();
            return;
        }
        break;
    case 0xF:
        ((s32 (*)(void))cleanup__17TWindowSubComCardFPv)();
        this->m_1c = 0x10U;
    case 0x10:
        this->m_1c = 0xBU;
        return;
    case 0x11:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->m_6c == 0U) {
            this->m_6c = ((u32 (*)(void*))create__17TWindowSubComCardFv)((void *)this);
            this->m_28 = -1;
        }
        this->set_card_index((int) (((TWindowMenu *)this->m_84)->get_selected_value()));
        this->m_1c = 0x12U;
    case 0x12:
        if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)controller_input_state + 0x20), 6) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)controller_input_state + 0x160), 6) != 0)) {
            this->m_1c = 0xBU;
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
        this->m_80 = ((u32 (*)(void*, int))create_keyboard__17TWindowSubComCardFii)((void *)this, this->m_24);
        this->m_1c = 0x14U;
    case 0x14:
        if (((TKeyBoardControl *)(this->m_80))->is_cancelled() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TKeyBoardControl *)(this->m_80))->is_confirmed() != 0) {
            src = (s32)((TKeyBoardControl *)(this->m_80))->realloc_buffer();
            TWindowSubComCard::mask_profanity_words((char *)src, (char *)get_shared_text_buffer());
            ((TWindowSubComCard *)(this->m_24))->set_card_text((int) (get_shared_text_buffer()));
            mem_free((void *)src);
            this->m_1c = 1U;
            return;
        }
        break;
    case 0x15:
        ((TWindowOptionCtrl *)(this->m_64))->open();
        this->m_70 = this->confirm_and_free();
        this->m_1c = 0x16U;
    case 0x16:
        if (((TWindowSubComCard *)(this->m_70))->get_card_data() != 0) {
            this->m_1c = 0xDU;
            return;
        }
        if (((TWindowMessageYesNo *)(this->m_70))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(this->m_70))->get_slot_or_neg1() == 0) {
                TWindowSubComCard::remove_card_at(((TWindowMenu *)this->m_84)->get_selected_value());
                this->m_1c = 1U;
                return;
            }
            this->m_1c = 0xDU;
            return;
        }
        break;
    case 0x19:
        ((TWindowSubComCard *)(this->m_84))->clear_flag_and_release();
        this->m_1c = 0x1AU;
    case 0x1A:
        ((s32 (*)(int, int, void*))update_display_value__17TWindowSubComCardFUiUiPv)(this->m_84, this->m_74, (void *) ((u8 *)this + 0x24));
        if (((TWindowMenu *)(this->m_84))->is_cancelled() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_84))->is_decided() != 0) {
            this->m_1c = 0x1BU;
            return;
        }
        break;
    case 0x1B:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->m_84 == 0U) {
            this->m_84 = ((u32 (*)(void))send_cmd_133__17TWindowSubComCardFv)();
        }
        if ((u32) this->m_74 == 0U) {
            this->m_24 = ((TWindowMenu *)this->m_84)->get_selected_value();
            this->m_74 = ((u32 (*)(int))send_command__17TWindowSubComCardFi)(this->m_24);
        }
        ((TWindowSubComCard *)(this->m_84))->set_display_page();
        ((TWindowSubComCard *)(this->m_84))->clear_flag_and_release();
        this->m_1c = 0x1CU;
    case 0x1C:
        ((s32 (*)(int, int, void*))update_display_value__17TWindowSubComCardFUiUiPv)(this->m_84, this->m_74, (void *) ((u8 *)this + 0x24));
        if (((TWindowMenu *)(this->m_84))->is_cancelled() != 0) {
            ((TWindowMenu *)(this->m_84))->reset_selection();
            this->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_84))->is_decided() != 0) {
            TWindowSubComCard::swap_cards((int) (((TWindowSubComCardList *)(this->m_84))->get_selected_index()), (int) (((TWindowMenu *)this->m_84)->get_selected_value()));
            ((TWindowMenu *)(this->m_84))->reset_selection();
            ((TWindowSubComCardList *)(this->m_84))->sub_80275360();
            this->m_1c = 0x19U;
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
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)this->m_68, (int)"", 0x15, -1);
        ((s32 (*)(void*, int))rebuild_com_card_list__17TWindowSubComCardFii)((void *)this, this->m_68);
        this->m_1c = 0x1EU;
    case 0x1E:
        if (is_com_card_active() != 0) {
            ((s32 (*)(void*, int))rebuild_com_card_list__17TWindowSubComCardFii)((void *)this, this->m_68);
        }
        if (((TWindowMenu *)(this->m_68))->is_cancelled() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_68))->is_decided() != 0) {
            TLobby::find_and_load_com_card(((TWindowMenu *)this->m_68)->get_selected_value());
            this->m_1c = 0x1FU;
            return;
        }
        break;
    case 0x1F:
        if ((u32) this->m_68 != 0U) {
            ((TWindowBase *)this->m_68)->close();
            this->m_68 = 0U;
        }
        if ((u32) this->m_78 == 0U) {
            var_r29 = ((s32 (*)(void))get_selected_guild_card_record)();
            temp_r30_2 = (u32)new TWindowUserSort((get_window_layout_position(0x8A)), (var_r29));
            this->m_78 = temp_r30_2;
        }
        if ((u32) this->m_64 == 0U) {
            this->m_64 = ((s32 (*)(void *)) TWindowSubComCard__sub_8027346C)((void *)this);
        }
        this->m_1c = 0x20U;
    case 0x20:
        if (((TWindowMenu *)(this->m_64))->is_cancelled() != 0) {
            this->m_1c = 0x1DU;
            return;
        }
        if (((TWindowMenu *)(this->m_64))->is_decided() != 0) {
            this->m_1c = ((TWindowMenu *)this->m_64)->get_selected_value();
            return;
        }
        break;
    case 0x21:
        if ((u32) this->m_70 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x70)))->close();
            this->m_70 = 0U;
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
        if ((u32) this->m_80 == 0U) {
            this->m_80 = create_keyboard__19TWindowSubShortMailFv();
        }
        ((TKeyBoardControl *)(this->m_80))->set_position((void *)(get_window_layout_position(0xBB)));
        free_menu_object((void *)this->m_80);
        ((TKeyBoardControl *)(this->m_80))->show();
        this->m_1c = 0x22U;
    case 0x22:
        if (((TKeyBoardControl *)(this->m_80))->is_cancelled() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TKeyBoardControl *)(this->m_80))->is_confirmed() != 0) {
            this->m_1c = 0x23U;
            return;
        }
        break;
    case 0x23:
        ((TKeyBoardControl *)(this->m_80))->set_position((void *)(get_window_layout_position(0xBC)));
        ((TKeyBoardControl *)this->m_80)->hide();
        this->m_70 = open_confirm_prompt__19TWindowSubShortMailFPvi((this), (this->m_20));
        this->m_1c = 0x24U;
    case 0x24:
        if (((TWindowSubComCard *)(this->m_70))->get_card_data() != 0) {
            this->m_1c = 0x21U;
            return;
        }
        if (((TWindowMessageYesNo *)(this->m_70))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(this->m_70))->get_slot_or_neg1() == 0) {
                this->sub_802721D8();
                this->m_1c = 1U;
                return;
            }
            this->m_1c = 0x21U;
            return;
        }
        break;
    case 0x25:
        ((s32 (*)(void))get_selected_guild_card_record)();
        TLobby__sub_8024259C();
        fn_8024AB54((this->m_20));
        this->m_2c = 0;
        this->m_1c = 0x26U;
    case 0x26:
        temp_r4 = this->m_2c;
        this->m_2c = (temp_r4 + 1);
        if ((f32) temp_r4 > 450.0f) {
            TWindowSubComCard__sub_8024AB98((this->m_20));
            temp_r3_2 = (u8 *)(*(u8 **)((s8 *)this + 0x5C));
            ((VObj_18_204a81 *)(temp_r3_2))->m7();
            this->m_1c = 0x4FU;
            return;
        }
        break;
    case 0x27:
    case 0x33:
        if (((u32 (*)(void))get_chr_select__17TWindowSubComCardFv)() == 0U) {
            ((TProtocol *)TLobby__protocol_instance)->send_choice_search_options_request();
        }
        if ((u8) this->m_1c == 0x27) {
            this->m_1c = 0x28U;
        } else {
            this->m_1c = 0x34U;
        }
    case 0x28:
    case 0x34:
        if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)controller_input_state + 0x20), 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)controller_input_state + 0x160), 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            this->m_1c = 1U;
        }
        if (((u32 (*)(void))get_chr_select__17TWindowSubComCardFv)() != 0U) {
            if ((u32) this->m_58 == 0U) {
                this->m_58 = ((u32 (*)(void))get_chr_select__17TWindowSubComCardFv)();
                character_save_record = get_character_save_record(0xFFFF);
                TWindowSubComCard__sub_800778B4((void *) ((u8 *)this + 0x30), this->m_58);
                TWindowSubComCard__sub_800778B4((void *)(character_save_record + 0x22EC), (int)this->m_58);
            }
            if ((u8) this->m_1c == 0x28) {
                this->m_1c = 0x29U;
                return;
            }
            this->m_1c = 0x35U;
            return;
        }
        break;
    case 0x29:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->m_7c == 0U) {
            this->m_7c = ((TWindowSubComCard *)this)->sub_80272DE0();
        }
        ((TWindowSubComCard *)(this->m_7c))->begin_scroll(148.0f);
        ((TWindowSubComCard *)(this->m_7c))->clear_flag_and_release2();
        this->m_1c = 0x2AU;
    case 0x2A:
        if (((TWindowSubComCard *)(this->m_7c))->get_flag() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TUnk_804D0658 *)(this->m_7c))->is_open() != 0) {
            if (update_selected_entry__17TWindowSubComCardFv(this->m_7c) == 0) {
                this->m_1c = 0x2DU;
                return;
            }
            this->m_1c = 0x2BU;
            return;
        }
        break;
    case 0x2B:
        TWindowSubComCard__sub_80249144((void *)this->m_7c);
        this->m_64 = this->create_option_list_window((s32)((void *) ((u8 *)this + 0x30)), (s32)((int) (update_selected_entry__17TWindowSubComCardFv(this->m_7c))));
        this->m_1c = 0x2CU;
    case 0x2C:
        if (((TWindowMenu *)(this->m_64))->is_cancelled() != 0) {
            this->m_1c = 0x29U;
            return;
        }
        if (((TWindowMenu *)(this->m_64))->is_decided() != 0) {
            ((TWindowSubComCard *)this)->sub_80271F04((void *) ((u8 *)this + 0x30), (int) (update_selected_entry__17TWindowSubComCardFv(this->m_7c)), (int) (((TWindowMenu *)this->m_64)->get_selected_value()));
            this->m_1c = 0x29U;
            return;
        }
        break;
    case 0x2D:
        TWindowSubComCard::release();
        send_packet__6TLobbyFll((void *)this, (void *) ((u8 *)this + 0x30));
        this->m_1c = 0x2EU;
    case 0x2E:
        if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)controller_input_state + 0x20), 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)controller_input_state + 0x160), 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            this->m_1c = 0x29U;
        }
        if (((u32 (*)(void))get_com_count__17TWindowSubComCardFv)() != 0U) {
            this->m_1c = 0x2FU;
            return;
        }
        break;
    case 0x2F:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->m_7c != 0U) {
            ((TWindowBase *)this->m_7c)->close();
            this->m_7c = 0U;
        }
        if ((u32) this->m_68 == 0U) {
            this->m_68 = TWindowSubComCard__sub_80272A98((void *)this);
        }
        if ((u32) this->m_6c == 0U) {
            this->m_6c = ((u32 (*)(void*))open_mode4_window__17TWindowSubComCardFv)((void *)this);
            this->m_28 = -1;
        }
        ((TWindowSubComCard *)(this->m_68))->clear_flag_and_release();
        this->m_1c = 0x30U;
    case 0x30:
        this->set_selected_card((int) (((TWindowMenu *)this->m_68)->get_selected_value()));
        if (((TWindowMenu *)(this->m_68))->is_cancelled() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_68))->is_decided() != 0) {
            this->m_1c = 0x31U;
            return;
        }
        break;
    case 0x31:
        if ((u32) this->m_6c != 0U) {
            ((TWindowBase *)this->m_6c)->close();
            this->m_6c = 0U;
        }
        if ((u32) this->m_64 == 0U) {
            temp_r29_6 = ((TWindowMenu *)this->m_68)->get_selected_value();
            ComList_8027375C *cl = (ComList_8027375C *) ((u32 (*)(void))get_com_count__17TWindowSubComCardFv)();
            ((s32 (*)(void*))load_selected_guild_card_record)(&cl->entries[temp_r29_6]);
            this->m_64 = ((u32 (*)(void*))create_menu_window__17TWindowSubComCardFv)((void *)this);
        }
        this->m_1c = 0x32U;
    case 0x32:
        if (((TWindowMenu *)(this->m_64))->is_cancelled() != 0) {
            this->m_1c = 0x2FU;
            return;
        }
        if (((TWindowMenu *)(this->m_64))->is_decided() != 0) {
            this->m_1c = ((TWindowMenu *)this->m_64)->get_selected_value();
            return;
        }
        break;
    case 0x35:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->m_7c == 0U) {
            this->m_7c = this->create_entry_list_window();
        }
        ((TWindowSubComCard *)(this->m_7c))->begin_scroll(148.0f);
        ((TWindowSubComCard *)(this->m_7c))->clear_flag_and_release2();
        this->m_1c = 0x36U;
    case 0x36:
        if (((TWindowSubComCard *)(this->m_7c))->get_flag() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TUnk_804D0658 *)(this->m_7c))->is_open() != 0) {
            this->m_1c = 0x37U;
            return;
        }
        break;
    case 0x37:
        TWindowSubComCard__sub_80249144((void *)this->m_7c);
        temp_r29_7 = get_character_save_record(0xFFFF);
        this->m_64 = this->create_option_list_window(temp_r29_7 + 0x22EC, (s32)((int) (update_selected_entry__17TWindowSubComCardFv(this->m_7c))));
        this->m_1c = 0x38U;
    case 0x38:
        if (((TWindowMenu *)(this->m_64))->is_cancelled() != 0) {
            this->m_1c = 0x35U;
            return;
        }
        if (((TWindowMenu *)(this->m_64))->is_decided() != 0) {
            temp_r29_8 = get_character_save_record(0xFFFF);
            ((TWindowSubComCard *)this)->sub_80271F04((void *)(temp_r29_8 + 0x22EC), (int) (update_selected_entry__17TWindowSubComCardFv((int)this->m_7c)), (int) (((TWindowMenu *)this->m_64)->get_selected_value()));
            this->m_1c = 0x35U;
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
        ((TWindowSubComCard *)(this->m_64))->clear_flag_and_release();
        this->m_1c = 0x3AU;
    case 0x3A:
        if (((TWindowMenu *)(this->m_64))->is_cancelled() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_64))->is_decided() != 0) {
            this->m_1c = ((TWindowMenu *)this->m_64)->get_selected_value();
            return;
        }
        break;
    case 0x3B:
        if ((u32) this->m_70 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x70)))->close();
            this->m_70 = 0U;
        }
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
        if ((u32) this->m_6c != 0U) {
            ((TWindowBase *)this->m_6c)->close();
            this->m_6c = 0U;
        }
        if ((u32) this->m_84 == 0U) {
            this->m_84 = ((u32 (*)(void))init_layout__17TWindowSubComCardFv)();
        }
        if ((u32) this->m_74 == 0U) {
            this->m_24 = ((TWindowMenu *)this->m_84)->get_selected_value();
            this->m_74 = ((u32 (*)(int))apply_selection__17TWindowSubComCardFi)(this->m_24);
        }
        ((TWindowSubComCard *)(this->m_84))->clear_flag_and_release();
        this->m_1c = 0x3CU;
    case 0x3C:
        ((s32 (*)(int, int, void*))update_selection__17TWindowSubComCardFiii)(this->m_84, this->m_74, (void *) ((u8 *)this + 0x24));
        if (((TWindowMenu *)(this->m_84))->is_cancelled() != 0) {
            this->m_1c = 0x39U;
            return;
        }
        if (((TWindowMenu *)(this->m_84))->is_decided() != 0) {
            this->m_1c = 0x3DU;
            return;
        }
        break;
    case 0x3D:
        if ((u32) this->m_74 != 0U) {
            ((TWindowBase *)this->m_74)->close();
            this->m_74 = 0U;
        }
        if ((u32) this->m_70 == 0U) {
            this->m_70 = this->sub_802730E0();
        }
        this->m_1c = 0x3EU;
    case 0x3E:
        if (((TWindowSubComCard *)(this->m_70))->get_card_data() != 0) {
            this->m_1c = 0x3BU;
            return;
        }
        if (((TWindowMessageYesNo *)(this->m_70))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(this->m_70))->get_slot_or_neg1() == 0) {
                TWindowSubComCard::remove_entry(((TWindowMenu *)this->m_84)->get_selected_value());
                this->m_1d = (u8) (this->m_1d | 2);
                this->m_1c = 1U;
                return;
            }
            this->m_1c = 0x3BU;
            return;
        }
        break;
    case 0x3F:
        this->m_68 = TWindowSubComCard::create_card_action_window();
        this->m_1c = 0x40U;
    case 0x40:
        if (((TWindowMenu *)(this->m_68))->is_cancelled() != 0) {
            this->m_1c = 0x39U;
            return;
        }
        if (((TWindowMenu *)(this->m_68))->is_decided() != 0) {
            this->m_1c = ((TWindowMenu *)this->m_68)->get_selected_value();
            return;
        }
        break;
    case 0x41:
        if ((u32) this->m_70 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x70)))->close();
            this->m_70 = 0U;
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
            this->m_84 = ((u32 (*)(void))send_cmd_133__17TWindowSubComCardFv)();
        }
        if ((u32) this->m_74 == 0U) {
            this->m_24 = ((TWindowMenu *)this->m_84)->get_selected_value();
            this->m_74 = ((u32 (*)(int))send_command__17TWindowSubComCardFi)(this->m_24);
        }
        ((TWindowSubComCard *)(this->m_84))->clear_flag_and_release();
        this->m_1c = 0x42U;
    case 0x42:
        ((s32 (*)(int, int, void*))update_display_value__17TWindowSubComCardFUiUiPv)(this->m_84, this->m_74, (void *) ((u8 *)this + 0x24));
        if (((TWindowMenu *)(this->m_84))->is_cancelled() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_84))->is_decided() != 0) {
            this->m_1c = 0x43U;
            return;
        }
        break;
    case 0x43:
        if ((u32) this->m_74 != 0U) {
            ((TWindowBase *)this->m_74)->close();
            this->m_74 = 0U;
        }
        if ((u32) this->m_70 == 0U) {
            this->m_70 = this->open_yesno_dialog();
        }
        this->m_1c = 0x44U;
    case 0x44:
        if (((TWindowSubComCard *)(this->m_70))->get_card_data() != 0) {
            this->m_1c = 0x41U;
            return;
        }
        if (((TWindowMessageYesNo *)(this->m_70))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(this->m_70))->get_slot_or_neg1() == 0) {
                update_press__17TWindowSubComCardFv(((TWindowMenu *)this->m_84)->get_selected_value());
                this->m_1d = (u8) (this->m_1d | 2);
                this->m_1c = 1U;
                return;
            }
            this->m_1c = 0x41U;
            return;
        }
        break;
    case 0x45:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
    case 0x46:
        if ((u32) this->m_70 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x70)))->close();
            this->m_70 = 0U;
        }
        if ((u32) this->m_68 != 0U) {
            ((TWindowBase *)this->m_68)->close();
            this->m_68 = 0U;
        }
        if ((u32) this->m_64 == 0U) {
            this->m_64 = ((u32 (*)(void*))create_player_select_window__17TWindowSubComCardFv)((void *)this);
        }
        ((TWindowSubComCard *)(this->m_64))->clear_flag_and_release();
        this->m_1c = 0x47U;
    case 0x47:
        if (((TWindowMenu *)(this->m_64))->is_cancelled() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_64))->is_decided() != 0) {
            this->m_1c = 0x48U;
            return;
        }
        break;
    case 0x48:
        if ((u32) this->m_70 == 0U) {
            this->m_70 = this->open_yesno_dialog();
        }
        this->m_1c = 0x49U;
    case 0x49:
        if (((TWindowSubComCard *)(this->m_70))->get_card_data() != 0) {
            this->m_1c = 0x46U;
            return;
        }
        if (((TWindowMessageYesNo *)(this->m_70))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(this->m_70))->get_slot_or_neg1() == 0) {
                TWindowSubComCard::init_and_press_b(((TWindowMenu *)this->m_64)->get_selected_value());
                this->m_1d = (u8) (this->m_1d | 2);
                this->m_1c = 1U;
                return;
            }
            this->m_1c = 0x46U;
            return;
        }
        break;
    case 0x4A:
        if ((u32) this->m_64 != 0U) {
            ((TWindowBase *)this->m_64)->close();
            this->m_64 = 0U;
        }
    case 0x4B:
        if ((u32) this->m_70 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)this + 0x70)))->close();
            this->m_70 = 0U;
        }
        if ((u32) this->m_68 != 0U) {
            ((TWindowBase *)this->m_68)->close();
            this->m_68 = 0U;
        }
        if ((u32) this->m_64 == 0U) {
            this->m_64 = TWindowSubComCard__sub_80272640((void *)this);
        }
        ((TWindowSubComCard *)(this->m_64))->clear_flag_and_release();
        this->m_1c = 0x4CU;
    case 0x4C:
        if (((TWindowMenu *)(this->m_64))->is_cancelled() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TWindowMenu *)(this->m_64))->is_decided() != 0) {
            this->m_1c = 0x4DU;
            return;
        }
        break;
    case 0x4D:
        if ((u32) this->m_70 == 0U) {
            this->m_70 = this->open_yesno_dialog();
        }
        this->m_1c = 0x4EU;
    case 0x4E:
        if (((TWindowSubComCard *)(this->m_70))->get_card_data() != 0) {
            this->m_1c = 0x4BU;
            return;
        }
        if (((TWindowMessageYesNo *)(this->m_70))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(this->m_70))->get_slot_or_neg1() == 0) {
                TWindowSubComCard::init_and_press_a(((TWindowMenu *)this->m_64)->get_selected_value());
                this->m_1d = (u8) (this->m_1d | 2);
                this->m_1c = 1U;
                return;
            }
            this->m_1c = 0x4BU;
        }
        break;
    case 0x4F:
        break;
    }
}

void TWindowSubComCard::render() {  }

s32 create_menu__17TWindowSubComCardFv(void) {
    s32 temp_r31;

    temp_r31 = ((s32 (*)(s32, s32, s32))draw_card_icon__17TWindowSubComCardFll)(get_window_layout_position(0x7F), 6, ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x1D));
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x52)), 6, 3);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x53)), 6, 0xB);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x54)), 6, 0x1D);
    if (get_main_phase() == 0xF) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_message_text(0x49)), 6, 0x27);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x6D)), 6, 0x33);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0xF8)), 6, 0x39);
    } else {
        TWindowSubComCard::draw_text_gray(temp_r31, get_message_text(0x49), 6, 0x27);
        TWindowSubComCard::draw_text_gray(temp_r31, ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x6D), 6, 0x33);
        TWindowSubComCard::draw_text_gray(temp_r31, ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0xF8), 6, 0x39);
    }
    ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
    ((TWindowSubComCardList *)temp_r31)->update_layout_height(179.0f);
    align_menu_entry_positions(temp_r31);
    return temp_r31;
}

s32 TWindowSubComCard__sub_8027353C(void) {
    s32 temp_r31;
    s32 temp_r31_2;
    temp_r31 = ((s32 (*)(s32, s32, s32))draw_card_icon__17TWindowSubComCardFll)((s32)(((s32)get_window_layout_position(0x82))), 2, (s32)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x1E)));
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)((int) (((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x55))), 6, 5);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)((int) (((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x56))), 6, 9);
    ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
    ((TWindowSubComCardList *)temp_r31)->update_layout_height(213.0f);
    align_menu_entry_positions(temp_r31);
    return temp_r31;
}

s32 TWindowSubComCard__sub_8027346C(void) {
  s32 temp_r31;
  s32 temp_r31_2;
  temp_r31_2 = (0, ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x1D));
  temp_r31 = ((s32 (*)(s32, s32, s32))draw_card_icon__17TWindowSubComCardFll)((s32)((int) get_window_layout_position(0x8B)), 2, (s32)((int) temp_r31_2));
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)((int) temp_r31), (int)((int) ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x57)), 6, 0x21);
  if (get_current_floor_area() == AREA_LOBBY)
  {
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)((int) temp_r31), (int)((int) ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x58)), 6, 0x25);
  }
  else
  {
    TWindowSubComCard::draw_text_gray((s32)((int) temp_r31), (s32)((int) ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x58)), 6, 0x25);
  }
  ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
  temp_r31_2 = temp_r31;
  ((TWindowSubComCardList *)temp_r31_2)->update_layout_height(186.0f);
  align_menu_entry_positions((s32)((int) temp_r31_2));
  return temp_r31_2;
}

u32 TWindowSubComCard__sub_8027337C() {
    s32 i;
    void *p;
    s32 w;
    u8 *name;
    w = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x83), 0xC, TWindowSubStatusDisp::get_message_10(0x1F));
    i = 0;
    do {
        if (i != local_client_id && (p = get_player_by_client_id(i)) != NULL &&
            ((TObjPlayer *)p)->is_script_controlled() == 0 && ((TObjChara *)p)->obj_isState3_324() == 0 &&
            (name = (u8 *)p + 0x85C) != NULL) {
            forward_trade_action_default__16TObjCityMainWarpFPviii((void *)w, (int)name, 7, (int)i);
        }
        i++;
    } while (i < 0xC);
    if (((TWindowSubComCardList *)w)->get_field_72() <= 0) {
        TWindowSubComCard::draw_text_gray(w, (s32)TWindowSubStatusDisp::get_message_10(0xD2), 7, 0);
    }
    ((TWindowSubComCardList *)w)->set_flag70_bit10();
    ((TWindowSubComCardList *)w)->set_scroll_target(213.0f, 124.0f);
    return w;
}

s32 create_single_entry_window__17TWindowSubComCardFv(void) {
    s32 temp_r31;
    temp_r31 = check_room_seq_4__16TAdChrSelASlotGCFl((void *)(((s32)get_window_layout_position(0x84))), 1);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)((int) (((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x38))), 3, 0);
    ((TAdChrSelASlotGC *)temp_r31)->set_flag_40();
    ((TWindowSubComCardList *)temp_r31)->set_scroll_target(213.0f, 64.0f);
    return temp_r31;
}

s32 open_menu__17TWindowSubComCardFv(void) {
    s32 temp_r31;

    temp_r31 = ((s32 (*)(s32, s32, s32))draw_card_icon__17TWindowSubComCardFll)(get_window_layout_position(0x87), 5, ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x1D));
    if (get_main_phase() == 0xF) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x59)), 6, 0xF);
    } else {
        TWindowSubComCard::draw_text_gray(temp_r31, ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x59), 6, 0xF);
    }
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x101)), 6, 0x11);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x102)), 6, 0x13);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x63)), 6, 0x1B);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x5A)), 6, 0x15);
    ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
    ((TWindowSubComCardList *)temp_r31)->update_layout_height(206.0f);
    align_menu_entry_positions(temp_r31);
    return temp_r31;
}

s32 TWindowSubComCard::confirm_and_free() {
    s32 temp_r29;

    temp_r29 = create__19TWindowMessageYesNoFPvPvPvPv(this, this->m_20, 0, 0);
    open_yes_no_prompt((TChCrTagPlBack *)((u8 *)temp_r29), (u32)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x20)), (s32)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x39)), (s32)(get_window_layout_position(0x88)), 205.0f);
    free_member__17TWindowSubComCardFv(temp_r29, 1);
    ((TWindowSubShortMail *)temp_r29)->notify_warp_flag70();
    return temp_r29;
}

s32 TWindowSubComCard::sub_802730E0() {
    s32 temp_r30;
    temp_r30 = create__19TWindowMessageYesNoFPvPvPvPv(this, this->m_20, 0, 0);
    forward_slot_selection__16TAdChrSelASlotGCFPvPv(temp_r30, ((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0xFC), get_window_layout_position(0x96), 213.0f);
    free_member__17TWindowSubComCardFv(temp_r30, 1);
    ((TWindowSubShortMail *)temp_r30)->notify_warp_flag70();
    return temp_r30;
}

s32 TWindowSubComCard::open_yesno_dialog() {
    s32 temp_r29;

    temp_r29 = create__19TWindowMessageYesNoFPvPvPvPv(this, this->m_20, 0, 0);
    open_yes_no_prompt((TChCrTagPlBack *)((u8 *)temp_r29), (u32)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x20)), (s32)(((s32 (*)(s32))get_message_10__20TWindowSubStatusDispFl)(0x100)), (s32)(get_window_layout_position(0x97)), 213.0f);
    free_member__17TWindowSubComCardFv(temp_r29, 1);
    ((TWindowSubShortMail *)temp_r29)->notify_warp_flag70();
    return temp_r29;
}

s32 TWindowSubComCard__sub_80273004(void) {
    s32 r = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x89), 8, ((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0x21));
    ((TWindowSubComCardList *)r)->set_flag70_bit10();
    return r;
}
}
#pragma push
#pragma opt_loop_invariants off
extern "C" {
void rebuild_com_card_list__17TWindowSubComCardFii(s32 arg0, s32 arg1) {
    s32 n;
    u32 cur;
    s32 i;
    s16 sel;
    s16 pos;
    void *e;
    cur = ((TWindowMenu *)arg1)->get_selected_value();
    sel = -1;
    TLobby::clear_flag_bit2();
    pos = ((TWindowShortListCtrl *)arg1)->get_cursor_pos();
    ((TWindowSubComCardList *)arg1)->reset_entries();
    n = TLobby::get_com_card_data();
    for (i = n - 1; i >= 0; i--) {
        e = TLobby::get_com_card_entry(i);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)arg1, (int)(((TWindowSubComCard *)e)->get_sub_obj()), 7, (int)(((GuildCardRecord *)e)->get_serial()));
        if (cur == ((GuildCardRecord *)e)->get_serial()) {
            sel = (n - 1) - i;
        }
    }
    if (n <= 0) {
        TWindowSubComCard::draw_text_gray(arg1, (s32)((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0xD3), 6, -1);
    }
    ((TWindowSubComCardList *)arg1)->update_layout_height(243.0f);
    if (sel == -1) {
        ((TWindowSubComCardList *)arg1)->set_selected_index(pos);
    } else {
        ((TWindowSubComCardList *)arg1)->set_selected_index(sel);
    }
}
}
#pragma pop
extern "C" {

void open_layout_window__17TWindowSubComCardFv(void) {
    create__14TWindowMessageFPvll((s32)(get_window_layout_position(0x80)), (s32 *)com_card_layout_message_size, 1);
}
}
#pragma push
#pragma opt_loop_invariants off
extern "C" {
u32 TWindowSubComCard::sub_80272DE0() {
    s32 i;
    s32 count;
    s32 idx;
    s32 w;
    Ent_80272CB0 *e;
    List_80272CB0 *l;
    w = create_choice_setting_window__17TWindowSubComCardFiii((s32)(get_window_layout_position(0x8C)), (s32)com_card_choice_list_size, 6);
    create_sub_window__20TWindowChoiceSettingFPvi((void *)w, get_message_text(0x49));
    l = (List_80272CB0 *)this->m_58;
    idx = 0;
    count = l->count;
    e = l->ents;
    for (i = 0; i < count; i++, e++) {
        if (e->type == 0) {
            ((TWindowSubComCard *)w)->update_next_entry((s32)e->name, (s32)this->find_entry_rest(&this->m_30, idx), (s32)e->id);
            idx++;
        }
    }
    ((TWindowSubStatusDisp *)w)->add_text_entry(get_message_text(0x4A), 0);
    ((TWindowSubComCard *)w)->set_flag_10();
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
    s32 hard;
    s32 w;
    Ent_80272CB0 *e;
    List_80272CB0 *l;
    card = (u8 *)get_character_save_record(0xFFFF);
    hard = open_hard_keyboard__6TLobbyFPv(*(void **)(((u8 *)this) + 0x20));
    w = create_choice_setting_window__17TWindowSubComCardFiii((s32)(get_window_layout_position(0x8C)), (s32)com_card_entry_list_size, 6);
    create_sub_window__20TWindowChoiceSettingFPvi((void *)w, (s32)(((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0x6D)));
    ((TWindowSubComCard *)w)->update_next_entry((s32)(((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0x6D)), (s32)(((GetMsg_80272CB0)get_message_10__17TWindowSubComCardFPvPv)(this, (void *)hard)), 0);
    l = *(List_80272CB0 **)(((u8 *)this) + 0x58);
    idx = -1;
    n = l->count;
    e = l->ents;
    for (i = 0; i < n; i++, e++) {
        if (e->type == 0) {
            idx++;
            if (e->id >= 500) {
                ((TWindowSubComCard *)w)->update_next_entry((s32)e->name, (s32)(this->find_entry_rest(card + 0x22EC, idx)), (s32)e->id);
                if (hard != 0) {
                    ((TWindowSubComCard *)w)->disable_entry_by_id(e->id);
                }
            }
        }
    }
    ((TWindowSubComCard *)w)->set_flag_10();
    return w;
}
}
#pragma push
#pragma opt_loop_invariants off
extern "C" {
s32 TWindowSubComCard::create_option_list_window(s32 arg1, s32 key) {
    s32 i;
    s32 count;
    s32 idx;
    u16 val;
    u16 sel;
    s32 win;
    Entry_80272B60 *e;
    ChrSel_80272B60 *cs;
    win = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x8D), 0x20, (void *)((TWindowSubComCard *)this->m_7c)->find_entry_value_by_id(key));
    if (key == 0) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)win, (int)(((u8* (*)(void*, void*))get_message_10__17TWindowSubComCardFPvPv)(this, (void *)(0))), 6, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)win, (int)(((u8* (*)(void*, void*))get_message_10__17TWindowSubComCardFPvPv)(this, (void *)(1))), 6, 1);
        ((TWindowSubComCardList *)win)->set_selected_index(open_hard_keyboard__6TLobbyFPv((void *)this->m_20));
    } else {
        sel = ((TWindowSubComCard *)arg1)->find_value_by_key(key);
        cs = (ChrSel_80272B60 *)TWindowSubComCard::get_chr_select();
        count = cs->count;
        e = cs->e;
        idx = 0;
        i = 0;
        while (i < count) {
            if (e->id == key) {
                val = e->val;
                forward_trade_action_default__16TObjCityMainWarpFPviii((void *)win, (int)e->name, 6, (int)val);
                if (sel == val) {
                    ((TWindowSubComCardList *)win)->set_selected_index(idx);
                }
                idx++;
            }
            i++;
            e++;
        }
    }
    ((TWindowSubComCardList *)win)->set_flag70_bit10();
    ((TWindowSubComCardList *)win)->set_scroll_target(405.0f, 124.0f);
    align_menu_entry_positions(win);
    return win;
}
}
#pragma pop
extern "C" {

u32 TWindowSubComCard__sub_80272A98(void *) {
    s32 i;
    s32 count;
    s32 w;
    ComCardRec_80272A98 *e;
    ComCardList_80272A98 *l;
    w = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x8E), 0x20, TWindowSubStatusDisp::get_message_10(0x54));
    l = (ComCardList_80272A98 *)TWindowSubComCard::get_com_count();
    count = l->count;
    e = l->entries;
    for (i = 0; i < count; i++, e++) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)w, (int)e->name, 6, i);
    }
    if (((TWindowSubComCardList *)w)->get_field_72() <= 0) {
        TWindowSubComCard::draw_text_gray(w, (s32)TWindowSubStatusDisp::get_message_10(0xD2), 7, 0);
    }
    ((TWindowSubComCardList *)w)->set_flag70_bit10();
    ((TWindowSubComCardList *)w)->set_scroll_target(223.0f, 124.0f);
    return w;
}
void open_mode4_window__17TWindowSubComCardFv(void) {
    create__14TWindowMessageFPvll((s32)(get_window_layout_position(0x8f)), (s32 *)com_card_mode4_message_size, 1);
}

s32 create_menu_window__17TWindowSubComCardFv(void) {
  s32 temp_r31;
  s32 title;
  title = (0, ((s32)((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0x1D)));
  temp_r31 = draw_card_icon__17TWindowSubComCardFll((int)((s32)((int) get_window_layout_position(0x8f))), 2, (void *)((s32)((int) title)));
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)((s32)((int) temp_r31)), (int)((s32)((int) ((s32)((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0x57)))), 6, 0x21);
  if (get_current_floor_area() == AREA_LOBBY)
  {
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)((s32)((int) temp_r31)), (int)((s32)((int) ((s32)((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0x58)))), 6, 0x25);
  }
  else
  {
    TWindowSubComCard::draw_text_gray((s32)((int) temp_r31), (s32)((int) ((s32)((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0x58))), 6, 0x25);
  }
  ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
  title = temp_r31;
  ((TWindowSubComCardList *)title)->update_layout_height(206.0f);
  align_menu_entry_positions((s32)((int) title));
  return title;
}

s32 TWindowSubComCard__sub_802728CC(void) {
    void *msg;
    s32 w;
    w = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x90), 2, msg = ((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0xF8));
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)w, (int)(((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0xFA)), 6, 0x3B);
    if (init_card__17TWindowSubComCardFv() != 0) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)w, (int)(((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0xFB)), 6, 0x3F);
    } else {
        TWindowSubComCard::draw_text_gray(w, (s32)((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0xFB), 6, 0x3F);
    }
    ((TWindowSubComCardList *)w)->set_flag70_bit10();
    ((TWindowSubComCardList *)w)->update_layout_height(233.0f);
    return w;
}

s32 TWindowSubComCard::create_card_action_window() {
    s32 temp_r31;
    void *temp_r31_2;
    temp_r31 = draw_card_icon__17TWindowSubComCardFll(((s32)get_window_layout_position(0x93)), 3, ((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0x1D));
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0xFD)), 6, 0x41);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0xFE)), 6, 0x45);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0xFF)), 6, 0x4A);
    ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
    ((TWindowSubComCardList *)temp_r31)->update_layout_height(193.0f);
    return temp_r31;
}
}
#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
extern "C" {
s32 create_player_select_window__17TWindowSubComCardFv(void) {
    s32 i;
    VObj_18_80272714 *p;
    s32 w;
    w = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x94), 0xC, ((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0x2D));
    i = 0;
    do {
        if (i != local_client_id && (p = (VObj_18_80272714 *)get_player_by_client_id(i)) != NULL &&
            ((TObjPlayer *)p)->is_script_controlled() == 0 && ((TObjChara *)p)->obj_isState3_324() == 0) {
            forward_trade_action_default__16TObjCityMainWarpFPviii((void *)w, (int)(p->m10()), 7, (int)i);
        }
        i++;
    } while (i < 0xC);
    if (((TWindowSubComCardList *)w)->get_field_72() <= 0) {
        TWindowSubComCard::draw_text_gray(w, (s32)((void* (*)(int))get_message_10__20TWindowSubStatusDispFl)(0xD2), 7, 0);
    }
    ((TWindowSubComCardList *)w)->set_flag70_bit10();
    ((TWindowSubComCardList *)w)->set_scroll_target(223.0f, 184.0f);
    return w;
}
}
#pragma pop
extern "C" {

u32 TWindowSubComCard__sub_80272640(void *) {
    s32 n;
    s32 i;
    void *e;
    s32 w;
    w = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x95), 8, TWindowSubStatusDisp::get_message_10(0x2E));
    n = TLobby::get_short_mail_ctrl();
    for (i = n - 1; i >= 0; i--) {
        e = TLobby__sub_8022598C(i);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)w, (int)fn_8007B83C(e), 7, ((TLobby *)e)->get_lobby_id());
    }
    if (n <= 0) {
        TWindowSubComCard::draw_text_gray(w, (s32)TWindowSubStatusDisp::get_message_10(0xD1), 7, 0);
    }
    ((TWindowSubComCardList *)w)->set_flag70_bit10();
    ((TWindowSubComCardList *)w)->set_scroll_target(223.0f, 184.0f);
    return w;
}

s32 create__17TWindowSubComCardFv(void) {
    s32 temp_r31;
    s32 window_layout_position;

    window_layout_position = get_window_layout_position(0x98);
    temp_r31 = create__14TWindowMessageFPvll(window_layout_position, (s32 *)com_card_message_size, 1);
    set_depth__11TWindowBaseFf(50090.0f);
    return temp_r31;
}

s32 create_keyboard__17TWindowSubComCardFi(s32 parent) {
    s32 keyboard;
    s32 keyboard_mode;

    keyboard_mode = TWindowSubComCard::get_keyboard_mode();
    keyboard = (s32)new TKeyBoardControl((TObject *)parent, 0xC6, 3, 4, local_client_id);
    ((TKeyBoardControl *)keyboard)->set_text((char *)((TWindowComCard *)keyboard_mode)->get_kbd_ptr());
    ((TKeyBoardControl *)keyboard)->set_sub_position((u8 *)(get_window_layout_position(0xBB)));
    ((TKeyBoardControl *)keyboard)->set_flag62_bit2();
    ((TWindowSubComCard *)keyboard)->destroy_keyboard();
    return keyboard;
}

s32 create_keyboard__17TWindowSubComCardFii(s32 parent, s32 arg1) {
    s32 keyboard;

    keyboard = (s32)new TKeyBoardControl((TObject *)parent, 0xC6, 3, 4, local_client_id);
    ((TKeyBoardControl *)keyboard)->set_text((char *)(s32)((TWindowSubComCard *)arg1)->get_card_entry_data());
    ((TKeyBoardControl *)keyboard)->set_sub_position((u8 *)(get_window_layout_position(0xBB)));
    ((TKeyBoardControl *)keyboard)->set_flag62_bit2();
    ((TWindowSubComCard *)keyboard)->destroy_keyboard();
    return keyboard;
}

void update_display_value__17TWindowSubComCardFUiUiPv(u32 arg0, u32 arg1, s32 *arg2) {
    s32 temp_r31;
    s32 temp_r3;

    temp_r31 = ((s32 (*)(s32))get_card_entry__17TWindowSubComCardFi)(0);
    if ((arg0 != 0U) && (arg1 != 0U)) {
        temp_r3 = ((TWindowMenu *)arg0)->get_selected_value();
        if (temp_r3 != (s32) *arg2) {
            *arg2 = temp_r3;
            ((TWindowComCard *)arg1)->set_display_value(temp_r3, temp_r31);
        }
    }
}

void update_selection__17TWindowSubComCardFiii(s32 arg0, s32 arg1, s32 arg2) {
    s32 tmp = TWindowSubComCard::get_card_slot(0);
    ((s32 (*)(s32, s32, s32, s32))update_selection__17TWindowSubComCardFUiUiPvi)(arg0, arg1, arg2, tmp);
}

void update_selection__17TWindowSubComCardFUiUiPvi(u32 arg0, u32 arg1, s32 *arg2, s32 arg3) {
    s32 temp_r3;

    if ((arg0 != 0U) && (arg1 != 0U)) {
        temp_r3 = ((s32 (*)(void))get_selected_value__11TWindowMenuFv)();
        if (temp_r3 != (s32) *arg2) {
            *arg2 = temp_r3;
            TWindowComCard__sub_80249920(arg1, temp_r3, arg3);
        }
    }
}

void TWindowSubComCard::set_help_message(s32 arg1) {
    if ((s32) this->m_28 != arg1) {
        this->m_28 = arg1;
        ((TWindowMessage *)(this->m_6c))->append_line((s32)get_message_10__20TWindowSubStatusDispFl((void *)com_card_help_message_ids[arg1]), 0x80);
    }
}

void TWindowSubComCard::set_selected_card(s32 arg1) {
    u8 *temp_r31;
    s32 temp_r30;
    Rec_80272290 *cnt;
    if (*(s32 *)&this->m_28 != arg1) {
        *(s32 *)&this->m_28 = arg1;
        cnt = (Rec_80272290 *)TWindowSubComCard::get_com_count();
        temp_r31 = cnt[arg1].f4;
        load_selected_guild_card_record((int)temp_r31, arg1 * 0xD4);
        temp_r30 = ((s32 (*)(void))get_selected_guild_card_record)();
        text_builder_reset();
        text_builder_append((temp_r31 + 0x14));
        text_builder_append((u8 *)(((TWindowSubComCard *)temp_r30)->get_name()));
        text_builder_append((u8 *)"\n");
        text_builder_append((u8 *)(((void* (*)(int))TWindowSubComCard__sub_8027523C)(temp_r30)));
        text_builder_append((u8 *)"\n");
        text_builder_append((u8 *)(((TWindowSubComCard *)temp_r30)->get_card_data_ptr()));
        ((TWindowMessage *)(*(s32 *)&this->m_6c))->append_line((int)get_shared_text_buffer(), 0x82);
    }
}

void TWindowSubComCard::set_card_index(s32 arg1) {
    if ((s32) this->m_28 != arg1) {
        this->m_28 = arg1;
        ((TWindowMessage *)(this->m_6c))->append_line((s32)((TWindowSubComCard *)arg1)->get_card_entry_data(), 0x82);
    }
}
}
#pragma push
#pragma scheduling off
extern "C" {
void TWindowSubComCard::sub_802721D8() {
  u8 *new_var;
  s32 temp_r30;
  u8 *lobby;
  u8 *message;
  temp_r30 = (s32)((TKeyBoardControl *)(*((u8 **) (((s8 *) ((u8 *)this)) + 0x80))))->realloc_buffer();
  lobby = (u8 *) ((u8* (*)(void))get_selected_guild_card_record)();
  TWindowSubComCard::mask_profanity_words((char *)temp_r30, (char *)get_shared_text_buffer());
  new_var = (u8 *)get_shared_text_buffer();
  message = (u8 *) new_var;
  TLobby::send_simple_mail(((TLobby *)lobby)->get_id(), message);
  mem_free((void *)temp_r30);
}
}
#pragma pop
extern "C" {
void cleanup__17TWindowSubComCardFPv(void* p) { ((TWindowMenu *)(*(void**)((char*)p + 0x84)))->get_selected_value(); get_card_entry__17TWindowSubComCardFi(); get_card_id__17TWindowSubComCardFv(); send_find_user_self_tag__6TLobbyFl(); }
void send_cmd_133__17TWindowSubComCardFv(void) { get_window_layout_position(133); fn_802754EC(); }
void init_layout__17TWindowSubComCardFv(void) {
    s32 card_slot;

    card_slot = TWindowSubComCard::get_card_slot(0);
    TWindowSubComCard::create_card_list(get_window_layout_position(0x91), card_slot, 0x1C, 1);
}
void send_command__17TWindowSubComCardFi(s32 arg0) {
    TWindowComCard::create((void *)(get_window_layout_position(0x86)), (void *)arg0);
}
void apply_selection__17TWindowSubComCardFi(s32 arg0) {
    s32 card_slot;

    card_slot = TWindowSubComCard::get_card_slot(0);
    TWindowComCard::create_for_card(get_window_layout_position(0x92), arg0, card_slot);
}

void get_message_10__17TWindowSubComCardFPvPv(void* p, void* a1) { get_message_10__20TWindowSubStatusDispFl((char*)a1 + 0xa6); }

u8 *TWindowSubComCard::find_entry_rest(void *arg1_arg, s32 arg2) {
    Key_80272034 *arg1 = (Key_80272034 *)arg1_arg;
    Tbl_80272034 *t = ((Win_80272034 *)this)->tbl;
    Ent_80272034 *e;
    Key_80272034 *k;
    s32 i;
    k = arg1 + arg2;
    e = t->e;
    for (i = 0; i < t->count; i++, e++) {
        if (e->a == k->a && e->b == k->b) return e->rest;
    }
    return 0;
}
void TWindowSubComCard::sub_80271F04(void *arr, s32 key, s32 arg3) {
    s32 i;
    if (key == 0) {
        if (arg3 != open_hard_keyboard__6TLobbyFPv(*(void **)(((u8 *)this) + 0x20))) {
            ((u8 *)this)[0x1D] |= 1;
            ((TWindowSubComCard *)(*(void **)(((u8 *)this) + 0x20)))->set_com_param(arg3);
            ((TWindowMakeTeam *)(*(void **)(((u8 *)this) + 0x7C)))->set_entry_string_by_id(((GetMsg_80271F04)get_message_10__17TWindowSubComCardFPvPv)(this, (void *)arg3), 0);
            if (arg3 != 0) {
                for (i = 0; i < 5; i++) {
                    if (((Ent_80271F04 *)arr)[i].id != 0) {
                        ((TWindowSubComCard *)(*(void **)(((u8 *)this) + 0x7C)))->disable_entry_by_id(((Ent_80271F04 *)arr)[i].id);
                    }
                }
            } else {
                for (i = 0; i < 5; i++) {
                    if (((Ent_80271F04 *)arr)[i].id != 0) {
                        ((TWindowSubComCard *)(*(void **)(((u8 *)this) + 0x7C)))->mark_entry_by_id(((Ent_80271F04 *)arr)[i].id);
                    }
                }
            }
        }
    } else if (arg3 != ((TWindowSubComCard *)((Ent_80271F04 *)arr))->find_value_by_key(key)) {
        ((u8 *)this)[0x1D] |= 1;
        set_value_by_key(((Ent_80271F04 *)arr), key, arg3);
        ((TWindowMakeTeam *)(*(void **)(((u8 *)this) + 0x7C)))->set_entry_string_by_id((void *)((TWindowSubComCard *)(((TWindowMenu *)(*(void **)(((u8 *)this) + 0x64)))->get_selected_entry()))->get_field_20(), key);
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
