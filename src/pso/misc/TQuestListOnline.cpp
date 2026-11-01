#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TShopJudgmentItemWindow_8026DF00.h"
#include "pso/misc/TPlyGuildCardTag_8007B434.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObjFish_8001ED90.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_800F7DAC.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TShopArmorListWindow.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TQuestListOnline.h"

#include <stddef.h>
#include "pso/TProtocol.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubItem.h"
struct Stack_80217EC4 {
    s32 sp8;
    s32 spC;
};

struct RecoveredGlobal_80217EC4_lbl_8044BEDC { s32 value; u8 remaining[0x8]; };
typedef char RecoveredGlobal_80217EC4_lbl_8044BEDC_size[sizeof(RecoveredGlobal_80217EC4_lbl_8044BEDC) == 0xC ? 1 : -1];

struct VBase_18_80217F88 { char pad[0x18]; };

struct VObj_18_80217F88 : VBase_18_80217F88 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8();
};

struct VBase_18_802178E4 { char pad[0x18]; };

struct VObj_18_802178E4 : VBase_18_802178E4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(s32, s32);
};

#define QL_80217C1C ((QList_80217C1C *)TQuestListOnline__quest_list_buffer)
struct VBase_18_80217C1C { char pad[0x18]; };

struct VObj_18_80217C1C : VBase_18_80217C1C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(s32, s32);
    virtual s32 m8();
};

struct QEnt_80217C1C { u8 type; u8 pad1[0x27]; u8 name[0x98 - 0x28]; };

struct QList_80217C1C { u8 f0; u8 count; u8 pad2[2]; QEnt_80217C1C ents[1]; };

struct T_80217B30 { u8 pad[0x38]; s32 f38; };

extern "C" {
s32 get_entity_id(int);
int set_field_20__15TShopWindowBaseFl(void*, int);
s32 append_line__14TWindowMessageFii(int, void *, int);
u32 create__14TWindowMessageFllUls(int, void *, int, int);
s32 get_window_layout_position(int);
u32 create__14TWindowMessageFPvll(s32, void *, int);
extern Stack_80217EC4 lbl_8044BED4[];
extern u8 *TQuestListOnline__quest_list_buffer;

s32 send_action__9TProtocolFR13GameListEntryUcPcPc(void *, void *, int, void *, void *);

extern void *TLobby__protocol_instance;
extern u8 lbl_805DC6A0;

s32 get_unlocked_tier__16TQuestListOnlineFv(void *);
f32 get_scale__15TShopWindowBaseFv(void *);
u8 *create_yes_no_window(s32 arg0, s32 arg1, u32 arg2, u32 arg3);
s32 get_cursor_value__19TWindowMenuIconLineFv(u32);
}
extern RecoveredGlobal_80217EC4_lbl_8044BEDC lbl_8044BEDC;
extern u32 TQuestListOnline__selected_quest_info;
extern const f32 lbl_805DC6A4;
extern const f32 lbl_805DC6A8;

s32 get_guild_text(s32 arg0);
extern s32 online_quest_list_state;

extern T_80217B30 TQuestListOnline__bin_download_state;
extern T_80217B30 TQuestListOnline__dat_download_state;
extern s32 TQuestListOnline__decompression_cursor;
extern s32 online_quest_bin_data;
extern s32 online_quest_dat_buffer;
extern s32 quest_bin_decompressed_size;
extern s32 online_quest_list_decompressed_size;
void TQuestListOnline::invoke_callback_30_and_queue_destruction() {
    s32 (*temp_r12)();

    temp_r12 = callback30;
    if (temp_r12 != NULL) {
        temp_r12();
    }
    queue_destruction__7TObjectFv(this);
}
extern s32 lbl_8044BEB0[];

void TQuestListOnline::handle_quest_confirm() {
    s32 v;
    s32 n;
    if (this->confirm_window != NULL && ((TWindowMenu *)(this->confirm_window))->is_decided() != 0) {
        v = ((TWindowMenu *)(*(void * *)&this->confirm_window))->get_selected_value();
        if (v == 0) {
            if (THunterGuildSeqOffline::check_party_gathered() == 1) {
                if (this->sequence != NULL) {
                    (*(VObj_18_802178E4 * *)&this->sequence)->m7(0x14, 1);
                }
                send_action__9TProtocolFR13GameListEntryUcPcPc(TLobby__protocol_instance, selected_entry, 0, &lbl_805DC6A0, &lbl_805DC6A0);
                queue_destruction__7TObjectFv(*(void * *)&this->confirm_window);
                this->confirm_window = NULL;
                if (this->info_window != NULL) {
                    queue_destruction__7TObjectFv(*(void * *)&this->info_window);
                    this->info_window = NULL;
                }
                if (this->description_window != NULL) {
                    queue_destruction__7TObjectFv(*(void * *)&this->description_window);
                    this->description_window = NULL;
                }
                if (this->list_window != NULL) {
                    queue_destruction__7TObjectFv(*(void * *)&this->list_window);
                    this->list_window = NULL;
                }
                set_field_20__15TShopWindowBaseFl(this, 0xC);
                return;
            }
            if (this->sequence != NULL) {
                (*(VObj_18_802178E4 * *)&this->sequence)->m7(0x10, 1);
            }
            ((TWindowSubComCard *)(this->confirm_window))->clear_flag_and_release();
            return;
        }
        if (v == 1) {
            ((TWindowBase *)this->confirm_window)->close();
            this->confirm_window = NULL;
            if (this->info_window != NULL) {
                ((TWindowBase *)this->info_window)->close();
                this->info_window = NULL;
            }
            if (this->list_window != NULL) {
                ((TWindowMenuIconLine *)(this->list_window))->clear_decided();
            }
            n = selection_stage;
            selection_stage = n - 1;
            close_windows();
            if (this->sequence != NULL) {
                (*(VObj_18_802178E4 * *)&this->sequence)->m7(0x19, 1);
            }
            set_field_20__15TShopWindowBaseFl(this, 1);
            return;
        }
    }
    if (this->confirm_window != NULL && ((TWindowMenu *)(this->confirm_window))->is_cancelled() != 0) {
        ((TWindowBase *)this->confirm_window)->close();
        this->confirm_window = NULL;
        if (this->info_window != NULL) {
            ((TWindowBase *)this->info_window)->close();
            this->info_window = NULL;
        }
        if (this->list_window != NULL) {
            ((TWindowMenuIconLine *)(this->list_window))->clear_decided();
        }
        n = selection_stage;
        selection_stage = n - 1;
        close_windows();
        if (this->sequence != NULL) {
            (*(VObj_18_802178E4 * *)&this->sequence)->m7(0x19, 1);
        }
        set_field_20__15TShopWindowBaseFl(this, 1);
    }
}

#pragma push
#pragma optimization_level 2
#pragma dont_inline on
void TQuestListOnline::decompress_quest_list_buffers() {
    quest_bin_decompressed_size = prs_decompress_buffer(TQuestListOnline__bin_download_state.f38, TQuestListOnline__decompression_cursor);
    online_quest_bin_data = TQuestListOnline__decompression_cursor;
    TQuestListOnline__decompression_cursor += quest_bin_decompressed_size;
    online_quest_list_decompressed_size = prs_decompress_buffer(TQuestListOnline__dat_download_state.f38, TQuestListOnline__decompression_cursor);
    online_quest_dat_buffer = TQuestListOnline__decompression_cursor;
    set_field_20__15TShopWindowBaseFl(this, (int)((void *)7));
}

#pragma pop

void TQuestListOnline::request_download_buffer() {
    if (TLobby::tmp_buf_is_free() != 0) {
        TQuestListOnline__decompression_cursor = TLobby::tmp_buf_use_req((const char *)lbl_8044BEB0);
        set_field_20__15TShopWindowBaseFl(this, 6);
    }
}
int TQuestListOnline::begin_buffer_request() { return set_field_20__15TShopWindowBaseFl(this, 5); }

void TQuestListOnline::handle_list_selection() {
    if (((VObj_18_80217C1C*)sequence)->m8() == 0) {
        return;
    }
    if (list_window != 0) {
        s32 sel = get_cursor_value__19TWindowMenuIconLineFv(list_window);
        if (description_window != 0 && sel != selected_index) {
            append_line__14TWindowMessageFii(description_window, QL_80217C1C->ents[sel].name, 0x80);
        }
        if (info_window != 0 && sel != selected_index) {
            ((TWindowBase *)info_window)->close();
            info_window = 0;
        }
        selected_index = sel;
    }
    if (list_window != 0 && ((TWindowMenuIconLine *)list_window)->is_decided() != 0) {
        if (selection_stage == 0) {
            s32 idx = get_cursor_value__19TWindowMenuIconLineFv(list_window);
            __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(selected_entry, &QL_80217C1C->ents[idx]);
            switch ((TQuestListOnline__quest_list_buffer + idx * 0x98)[4]) {
            case 1:
                online_quest_list_state = 0;
                break;
            case 2:
                online_quest_list_state = 1;
                break;
            default:
                online_quest_list_state = 0;
                break;
            }
            send_action__9TProtocolFR13GameListEntryUcPcPc(TLobby__protocol_instance, selected_entry, get_unlocked_tier__16TQuestListOnlineFv(this), &lbl_805DC6A0, &lbl_805DC6A0);
            if (description_window != 0) {
                ((TWindowBase *)description_window)->close();
                description_window = 0;
            }
            ((TWindowBase *)list_window)->close();
            list_window = 0;
            set_field_20__15TShopWindowBaseFl(this, 0xC);
            selection_stage++;
            return;
        } else if (selection_stage == 1) {
            s32 idx = get_cursor_value__19TWindowMenuIconLineFv(list_window);
            __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(selected_entry, &QL_80217C1C->ents[idx]);
            ((TProtocol *)TLobby__protocol_instance)->send_info((TPlyGuildCardTag &)selected_entry);
            set_field_20__15TShopWindowBaseFl(this, 0xC);
            selection_stage++;
            return;
        } else if (selection_stage == 2) {
            if (confirm_window == 0) {
                u16 id = get_entity_id(window_owner);
                confirm_window = (u32)create_yes_no_window(get_window_layout_position(0x2B), id, 0, 0);
                ((TWindowAddition *)confirm_window)->set_position_xy(get_scale__15TShopWindowBaseFv(this), get_scale__15TShopWindowBaseFv(this));
                if (sequence != NULL) {
                    ((VObj_18_80217C1C*)sequence)->m7(5, 1);
                }
                set_field_20__15TShopWindowBaseFl(this, 8);
            }
        }
    }
    if (list_window != 0 && ((TWindowMenuIconLine *)list_window)->is_cancelled() != 0) {
        set_field_20__15TShopWindowBaseFl(this, 9);
    }
}
void TQuestListOnline::show_info_window() {
    typedef char sp8_offset[(offsetof(Stack_80217EC4, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80217EC4, spC) == 0x4) ? 1 : -1];
    Stack_80217EC4 stack;
    u16 temp_r31;
    if ((u32) info_window == 0U) {
        stack.sp8 = *(s32 *)((s8 *)&lbl_8044BEDC.value + 0);
        stack.spC = *(s32 *)((s8 *)&lbl_8044BEDC.value + 4);
        temp_r31 = get_entity_id(window_owner);
        info_window = create__14TWindowMessageFllUls((int) (get_window_layout_position(0x2E)), (void *)&stack.sp8, 1, (int) ((s32) temp_r31));
        ((TWindowBase *)info_window)->set_depth(lbl_805DC6A4);
        if (TCameraCtrl::get_camera_id() >= 2) {
            ((TWindowAddition *)info_window)->set_position_xy(lbl_805DC6A8, lbl_805DC6A8);
        }
    }
    if ((u32) TQuestListOnline__selected_quest_info != 0U) {
        append_line__14TWindowMessageFii(info_window, (void *)(TQuestListOnline__selected_quest_info + 4), 0x80);
    }
    set_field_20__15TShopWindowBaseFl((void*)this, 3);
}

void TQuestListOnline::build_list_window() {
    u16 id;
    s32 off;
    s32 i;
    u8 *e;
    if (((VObj_18_80217F88 *)this->sequence)->m8() != 0) {
        if (list_window == 0U) {
            id = get_entity_id(window_owner);
            list_window = (u32)create_item_list_window(get_guild_text(0), 0x40, id);
        } else {
            ((TWindowMenuIconLine *)list_window)->reset_list();
        }
        if (TQuestListOnline__quest_list_buffer != NULL && TQuestListOnline__quest_list_buffer[1] == 0) {
            set_field_20__15TShopWindowBaseFl(this, 0xB);
            return;
        }
        if (TQuestListOnline__quest_list_buffer != NULL) {
            for (i = 0, off = 0; i < TQuestListOnline__quest_list_buffer[1]; i++, off += 0x98) {
                e = TQuestListOnline__quest_list_buffer + off;
                switch (e[5]) {
                case 0:
                    ((TWindowMenuIconLine *)list_window)->add_list_entry(0x2C, (s32)(e + 0xC), (s32)i);
                    break;
                case 1:
                    ((TWindowMenuIconLine *)list_window)->add_list_entry(0x17, (s32)(e + 0xC), (s32)i);
                    break;
                case 2:
                    ((TWindowMenuIconLine *)list_window)->add_list_entry(0x31, (s32)(e + 0xC), (s32)i);
                    break;
                default:
                    ((TWindowMenuIconLine *)list_window)->add_list_entry(0x17, (s32)(e + 0xC), (s32)i);
                    break;
                }
            }
            ((TWindowMenuIconLine *)list_window)->calc_content_extent();
        }
        if (description_window == 0U) {
            Stack_80217EC4 sp8 = lbl_8044BED4[0];
            description_window = create__14TWindowMessageFPvll(get_window_layout_position(0x2D), &sp8, 1);
            append_line__14TWindowMessageFii(description_window, TQuestListOnline__quest_list_buffer + 0x2C, 0x80);
        } else {
            append_line__14TWindowMessageFii(description_window, TQuestListOnline__quest_list_buffer + 0x2C, 0x80);
        }
        selected_index = 0;
        set_field_20__15TShopWindowBaseFl(this, 3);
    }
}
