#include "pso/math/CurvePathPoint.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/ResourceFile.h"
#include "pso/system/GbaDownloadRuntime.h"
#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/player/PlayerState.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pso/network/FloorEventCommand.h"
#include "pso/unk/TLobby_800FD78C.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TUnk_804C8678.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/ProgressMessageWindow.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/system/task/TMainTask.h"
#include "pso/quest/QuestVm.h"
#include "pso/ui/window/TWindowMessageScroll.h"
#include "pso/unk/TLobby_8026B06C.h"
#include "pso/npc/NpcPartnerControl.h"
#include "pso/player/PlayerTaskEffects.h"
#include "pso/quest/BattleRules.h"
#include "pso/quest/TQuestThread.h"
#include "pso/item/TObjItemNameSelect.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/item/TItemData.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"

#include "pso/item/TObjItemOKWindow.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/player/PlayerSlots.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/item/drop/TItemDropSub.h"
#include "pso/unk/TLobby.h"
#include "pso/map/TSetManager.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/unk/text_800F7DAC.h"
#include "pso/unk/TColorOverlayFade.h"
#include "pso/object/door/TObjDoor_801F3754.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/unk/text_8024AB18.h"
#include "pso/unk/text_8024AB98.h"
#include "pso/unk/text_80278460.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/base/TObjBase.h"

void qst_call_stack_push(s32 value);
s32 qst_call_stack_pop(void);
int qst_label_address(int label);
#include "pso/quest/QuestOpcodeTables.h"
#include "types.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/camera/CreationCamera.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/date.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/item/TItemMenuCtrl.h"

#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/item/TItem.h"

#include "pso/quest/TQuestBgmCtrl.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"

#include "pso/npc/TNpcPlayer.h"
#include "pso/npc/TNpcTalkTrigger.h"
#include "pso/camera/TCineCtrl.h"
#include "pso/object/switch/TOChatSensor.h"
#include "pso/object/collision/TOSymbolchatColli.h"
#include "pso/player/TPlayerBattleCtrl4P.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/technique/TTecLuker.h"
#include "pso/network/client_id.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/object/warp/TObjAreaWarpQuest.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/object/door/TObjDoor.h"
#include "pso/object/switch/TOChatSensorCapture.h"

#include "pso/quest/challenge/TChallenge4PResult.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/quest/TObjQuestColBase.h"
#include "pso/object/quest/TObjQuestColApcINW.h"
#include "pso/quest/TQuestColCtrl.h"
#include "pso/object/TObjSinBoard.h"
#include "pso/object/TObjTombstone.h"

#include "pso/quest/TQuestDamageTask.h"

#include "pso/boss/dragon/TBoss1Dragon.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/ui/Language.h"
#include "pso/unk/TLobby_803DE778.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/player/TPlyItem.h"
#include "pso/item/TItemList.h"
#include "pso/camera/TCameraFollow.h"
#include "pso/camera/TCameraPan.h"
#include "pso/system/TTokenList.h"
#include "pso/unk/TScreenFadeOut.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/player/TObjPlayer_801C7430.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
u8 *qst_code;
s32 *qst_function_table;
s32 *qst_registers;
TWindowMessageQuest *qst_message_window;
TWindowMessage *qst_message_window_qb;
void *qst_list_window;
u8 qst_result_register;
s32 qst_call_stack_depth;
saddr qst_pc;
s32 lbl_805D5E94;
quest_suspend_reason qst_suspend_reason;
s32 lbl_805D5E9C;
s32 qst_message_speaker;
s32 qst_arg_count;
u8 TLobby__data_805D5EA8;
u8 TLobby__data_805D5EA9;
u16 TLobby__data_805D5EAA;
u16 TLobby__data_805D5EAC;
void *qst_item_name_entry;
void *qst_item_name_select;
void *qst_item_ok_window;
void *qst_pack_select_window;
void *qst_pack_select_help_window;
u32 qst_flag_buf;
u16 qst_statistic_arg1;
u16 qst_statistic_arg2;
u16 qst_statistic_id;

struct RecoveredGlobal_8000F7FC_lbl_80515F48 {
    s32 value;
    u8 remaining[0x24];
};

struct Cmd_801E6604 {
    const char *name;
    void (*fn)(void);
};

struct CmdTable_801E6604 {
    Cmd_801E6604 e[12];
};

namespace pf2_p0 { extern "C" { s32 append_string(const char *); } }
#define append_string pf2_p0::append_string
namespace pf2_p0 { extern "C" { extern RecoveredGlobal_8000F7FC_lbl_80515F48 quest_player_class_name_buffer; } }
#define quest_player_class_name_buffer pf2_p0::quest_player_class_name_buffer
namespace pf2_p0 { extern "C" { extern RecoveredGlobal_8000F7FC_lbl_80515F48 quest_player_name_buffer; } }
#define quest_player_name_buffer pf2_p0::quest_player_name_buffer
void append_player_name(void);
extern "C" {
int sprintf(char *, const char *, ...);
}
namespace pf2_p0 { extern "C" { s32 is_message_source_exhausted(); } }
#define is_message_source_exhausted pf2_p0::is_message_source_exhausted
namespace pf2_p0 { extern "C" { s8 read_byte_advance__6TLobbyFv(); } }
#define read_byte_advance__6TLobbyFv pf2_p0::read_byte_advance__6TLobbyFv
void append_message_char(s8);
extern "C" {
namespace pf2_p0 { extern "C" { void begin_message_substitution(); } }
#define begin_message_substitution pf2_p0::begin_message_substitution
s32 expand_message_substitutions(s32 source, s32 result);
}
namespace pf2_p0 { extern "C" { s32 parse_r_index(const char *); } }
#define parse_r_index pf2_p0::parse_r_index
namespace pf2_p0 { extern "C" { int strcmp(const char *, const char *); } }
#define strcmp pf2_p0::strcmp
namespace pf2_p0 { extern "C" { char *TLobby__sub_80070ACC(); } }
#define TLobby__sub_80070ACC pf2_p0::TLobby__sub_80070ACC
void append_team_name(void);
extern "C" {
s32 dispatch_chat_message_to_children__12TOChatSensorFl();
}
void append_episode_progress_string(void);
void append_entered_item_name_pair(void);
void append_split_screen_hero_name(void);
s32 parse_f_index(const char *a0);
void append_hero_name(void);
void append_hero_class_name(void);
struct Tbl_801E9AF8 { s32 w[5]; };

struct Tbl_801E6CA4 { u32 w[18]; };

struct Tbl_801EDC98 { u32 w[18]; };

const Tbl_801EDC98 lobby_sub_801edc98_id_table = { { 16, 17, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 } };

// inferred names: each qst_op_ba_* setter maps its argument through its own table into the battle_rules field
// the name gives (trap_count_slots maps qst_op_ba_set_trap_count's slot to the battle_rules.trap_counts index).
const s32 tech_disk_mode_values[3] = { 1, 0, 2 };
const s32 lobby_menu_byte_1_map[4] = { 2, 0, 1, 3 };
const s32 mag_mode_values[2] = { 1, 0 };
const s32 tool_mode_values[3] = { 2, 0, 1 };
const s32 trap_mode_values[2] = { 0, 1 };
const s32 unused_F817_values[2] = { 0, 1 };
const s32 respawn_mode_values[3] = { 1, 0, 2 };
const s32 replace_char_values[2] = { 0, 1 };
const s32 drop_weapon_values[2] = { 1, 0 };
const s32 teams_values[2] = { 0, 1 };
const s32 trap_count_slots[4] = { 0, 2, 3, 1 };
const s32 meseta_mode_values[3] = { 0, 1, 2 };
const s32 enable_sonar_values[2] = { 0, 1 };

// inferred: qst_op_ba_forbid_scape_dolls maps its 0/1 argument through it
const s32 forbid_scape_dolls_values[2] = { 0, 1 };

const Tbl_801E9AF8 lobby_index_identity_table_a = { { 0, 1, 2, 3, 4 } };

// inferred: the position qst_op_open_pack_select opens the equip kind window at
const f32 pack_select_window_pos[2] = { 308.0f, 184.0f };

const Tbl_801E6CA4 lobby_index_identity_table_b = {
    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 }
};

// The <tag> names the message parser replaces, and their handlers.
const CmdTable_801E6604 message_substitution_handlers = { {
    { "hero name", append_hero_name },
    { "hero job", append_hero_class_name },
    { "time", append_episode_progress_string },
    { "award item", append_entered_item_name_pair },
    { "challenge title", append_split_screen_hero_name },
    { "pl_name", append_player_name },
    { "pl_job", TLobby::append_default_string },
    { "last_word", TLobby::append_card_window_text },
    { "team_name", append_team_name },
    { "last_chat", TLobby::append_unit_list_name },
    { "name hero", append_hero_name },
    { "name job", append_hero_class_name },
} };


void TLobby::capture_chat_sensor() {
    saddr message = (saddr)this;
    dispatch_chat_message_to_children__12TOChatSensorFl();
    TOChatSensorCapture::capture_message((u16)((u16) local_client_id), (const char *)message);
}

s32 expand_message_substitutions(s32 source, s32 result) {
    begin_message_substitution();
    while (is_message_source_exhausted() == 0) {
        s8 c = read_byte_advance__6TLobbyFv();
        switch (c) {
        case 0x3C:
            TLobby::parse_message_tag();
            break;
        case 0x3E:
            while (1) {
            }
        case 0x3D:
        default:
            append_message_char(c);
            break;
        }
    }
    append_message_char(0);
    return result;
}

void TLobby::parse_message_tag() {
    char buf[64];
    CmdTable_801E6604 tbl = message_substitution_handlers;
    u32 i;
    s32 idx;
    s8 c;
    for (i = 0; i < 0x40 && is_message_source_exhausted() == 0; i++) {
        c = read_byte_advance__6TLobbyFv();
        switch (c) {
        case 0x3E:
            buf[i] = 0;
            if ((idx = parse_r_index(buf)) != -1) {
                TLobby::append_int_param(idx);
                return;
            }
            if ((idx = parse_f_index(buf)) != -1) {
                TLobby::append_float_value(idx);
                return;
            }
            if ((idx = TLobby::parse_color_code((char *)(buf))) != -1) {
                TLobby::append_color_code(idx);
                return;
            }
            for (i = 0; i < 12; i++) {
                if (strcmp(tbl.e[i].name, buf) == 0) {
                    tbl.e[i].fn();
                }
            }
            return;
        default:
            buf[i] = c;
            break;
        }
    }
}

void TLobby::append_unit_list_name() {
    char *s;
    s = TLobby::get_unit_list();
    if (strcmp(s, "") == 0) {
        append_string("ERROR");
        return;
    }
    append_string(s);
}

// inferred: the "team_name" tag handler of message_substitution_handlers
void append_team_name(void) {
    char *s;
    s = TLobby__sub_80070ACC();
    if (strcmp(s, "") == 0) {
        append_string("ERROR");
        return;
    }
    append_string(s);
}

// The grave message of the character save record: qst_op_is_there_grave_message tests it and the
// "last_word" tag prints it.
struct CharacterSaveGraveMessage {
    u8 pad_0[0x2254];
    char grave_message[0x20];
};

void TLobby::append_card_window_text() {
    uaddr character_save_record;

    character_save_record = get_character_save_record(0xFFFF);
    if (character_save_record != 0U) {
        append_string(((CharacterSaveGraveMessage *)character_save_record)->grave_message);
        return;
    }
    append_string("Error");
}

LAYOUT_ASSERT(RecoveredGlobal_8000F7FC_lbl_80515F48_size, sizeof(RecoveredGlobal_8000F7FC_lbl_80515F48) == 0x28);
void TLobby::append_default_string() {
    append_string((const char *)&quest_player_class_name_buffer.value);
}

void append_player_name(void) {
    append_string((const char *)&quest_player_name_buffer.value);
}

void TLobby::append_color_code(s32 color) {
    char buf[64];
    sprintf(buf, "\tC%d", color);
    append_string(buf);
}

s32 TLobby::parse_color_code(char *s) {
    s32 v;
    v = -1;
    sscanf(s, "color %d", &v);
    if ((v <= 7) && (v >= 0)) {
        return v;
    }
    return -1;
}

s32 parse_f_index(const char *a0) {
    s32 index;

    index = -1;
    sscanf(a0, "f%d", &index);
    if ((index < 0x100) && (index >= 0)) {
        return index;
    }
    return -1;
}

#undef TLobby__sub_80070ACC
#undef is_message_source_exhausted
#undef begin_message_substitution
#undef append_string
#undef get_character_save_record
#undef parse_r_index
#undef read_byte_advance__6TLobbyFv
#undef strcmp
#undef quest_player_name_buffer
#undef quest_player_class_name_buffer

extern "C" {
void append_string(const char *s);
s32 TObjItemOKWindow__sub_801F3268();
s32 is_split_screen();
char *TLobby__sub_800713C8();
u8 is_message_source_exhausted(void);
s32 parse_r_index(const char *text);
u8 read_byte_advance__6TLobbyFv(void);

s32 parse_r_index(const char *text) {
    s32 index;

    index = -1;
    sscanf(text, "r%d", &index);
    if ((index < 0x100) && (index >= 0)) {
        return index;
    }
    return -1;
}
}

u8 *quest_script_read_ptr;

void append_split_screen_hero_name(void) {
    char buf[0x40];
    if (is_split_screen() == 1) {
        sprintf(buf, "%s", get_active_character_name());
    } else {
        sprintf(buf, "%s", TLobby__sub_800713C8());
    }
    buf[0x3F] = 0;
    append_string(buf);
}

void append_entered_item_name_pair(void) {
    char buf[64];
    s32 t = (saddr)TObjItemNameSelect::get_selected_name();
    sprintf(buf, "%s %s", TObjItemOKWindow__sub_801F3268(), t);
    buf[63] = 0;
    append_string(buf);
}

void TLobby::append_float_value(s32 reg) {
    char buf[64];
    sprintf(buf, "%f", ((f32 *)qst_registers)[reg]);
    append_string(buf);
}

void TLobby::append_int_param(s32 reg) {
    char buf[64];
    sprintf(buf, "%d", qst_registers[reg]);
    append_string(buf);
}

void append_episode_progress_string(void) {
    char buf[64];
    sprintf(buf, "%02d:%02d", 1, 12);
    append_string(buf);
}

void append_hero_class_name(void) {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        append_string((const char *)TLobby::get_class_type_name(player->class_flags));
    } else {
        append_string("Error Job");
    }
}

void append_hero_name(void) {
    TObjPlayer *player;
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        append_string(player->get_name());
    } else {
        append_string("Error Name");
    }
}
extern "C" {

u8 is_message_source_exhausted(void) {
    return (u8) ((s8) *quest_script_read_ptr == 0);
}

u8 read_byte_advance__6TLobbyFv(void) {
    u8 *temp_r3;

    temp_r3 = quest_script_read_ptr;
    quest_script_read_ptr = temp_r3 + 1;
    return *temp_r3;
}

char *quest_string_append_cursor;

void append_string(const char *s) {
    u32 len = strlen(s);
    strcpy(quest_string_append_cursor, s);
    quest_string_append_cursor += len;
}
}


void append_message_char(s8 c);

namespace pf2_p2 { extern "C" { extern s8 *quest_string_append_cursor; } }
#define quest_string_append_cursor pf2_p2::quest_string_append_cursor

void append_message_char(s8 c) {
    s8 *write_ptr;

    write_ptr = quest_string_append_cursor;
    quest_string_append_cursor = write_ptr + 1;
    *write_ptr = c;
}
#undef quest_string_append_cursor
extern "C" {
s32 TObjPlayer__sub_801C1AC8();
}
extern "C" {
void begin_message_substitution(u8 *a0, char *a1);

void begin_message_substitution(u8 *a0, char *a1) { quest_script_read_ptr = a0; quest_string_append_cursor = a1; }
}

void qst_op_olga_flow_is_dead(s32 reg) {
    if (TBoss6PlotFalz::is_phase_reached() != 0) {
        qst_registers[(u8)reg] = 1;
        return;
    }
    qst_registers[(u8)reg] = 0;
}

void qst_op_initial_floor(void) {
    Tbl_801E6CA4 t = lobby_index_identity_table_b;
    if (qst_args[0] <= 0x11U) {
        initialize_floor_transition(&floor_transition_state, t.w[qst_args[0]], 0);
    }
}

void qst_op_get_item_stackability() {
    u8 dest_reg;
    dest_reg = (u8) qst_args[1];
    if (find_item_by_id((int) (qst_args[0])) != 0U) {
        if (TObjPlayer__sub_801C1AC8() != 0) {
            qst_registers[(u8)dest_reg] = 1;
            return;
        }
        qst_registers[(u8)dest_reg] = 0;
        return;
    }
    qst_registers[(u8)dest_reg] = -1;
}

void qst_op_create_symbol_chat_capture_buffer() { TLobby::create_singleton((void *)tl_01); }

void qst_op_get_recent_symbol_chat() {
    u8 buf[0x3C];
    u8 idx;
    idx = (u8) qst_args[1];
    TLobby::send_slot_entity_or_local((u16) qst_args[0], (saddr) buf);
    memcpy(&qst_registers[(u8)idx], buf, 0x3C);
}

void qst_op_get_guildcard_num(void) {
    u8 dest_reg;
    u8 *player;
    dest_reg = (u8) qst_args[1];
    player = (u8 *)(get_player_by_client_id((s32) (u16) qst_args[0]));
    if (player != NULL) {
        qst_registers[(u8)dest_reg] = *(s32 *)((s8 *)player + 0xDB0);
        return;
    }
    qst_registers[(u8)dest_reg] = -1;
}
void qst_op_check_for_keyword(void) {
    u8 idx;
    idx = (u8) qst_args[0];
    if (TOChatSensorCapture::check_keyword((u16) qst_args[1], (const char *) qst_args[2]) != 0) {
        qst_registers[(u8)idx] = 1;
        return;
    }
    qst_registers[(u8)idx] = 0;
}

extern "C" {
s32 send_statistic_aa(TProtocol *, int, int, int, void *);
}

void qst_op_enable_keyword_detect() { TOChatSensorCapture::create_instance((void*)tl_01); }

void qst_op_prepare_statistic(void) {
    qst_statistic_id = (s16) qst_args[0];
    qst_statistic_arg1 = (s16) qst_args[1];
    qst_statistic_arg2 = (s16) qst_args[2];
}

void qst_op_send_statistic() {
    send_statistic_aa(TLobby::protocol_instance, qst_statistic_id, qst_statistic_arg1, qst_statistic_arg2, (void *) qst_args);
}

void qst_op_arg_pushs(int a0) { int old = qst_arg_count; qst_arg_count = old + 1; qst_args[old] = a0; }

void qst_op_arg_pusho(u16 a0) {
    qst_args[qst_arg_count++] = (saddr)&qst_function_table[a0];
}

void qst_op_arg_pusha(u8 a0) {
    qst_args[qst_arg_count++] = (saddr)(&qst_registers[a0]);
}

void qst_op_arg_pushw(u16 a0) {
    qst_args[qst_arg_count++] = a0;
}

void qst_op_arg_pushb(u8 a0) {
    qst_args[qst_arg_count++] = a0;
}

void qst_op_arg_pushl(int a0)
{
  unsigned long new_var3;
  int new_var;
  int *new_var2;
  new_var = qst_arg_count;
  new_var2 = &a0;
  new_var3 = *new_var2;
  qst_arg_count = qst_arg_count + 0x1;
  qst_args[new_var] = new_var3;
}
void qst_op_arg_pushr(u8 a0) {
    qst_args[qst_arg_count++] = qst_registers[a0];
}

void qst_op_va_call(s32 label) {
  int new_var;
  qst_arg_count = 0;
  qst_registers[1] = qst_args[0];
  qst_registers[2] = qst_args[1];
  qst_registers[3] = qst_args[2];
  qst_registers[4] = qst_args[3];
  qst_registers[5] = qst_args[4];
  qst_registers[6] = qst_args[5];
  qst_registers[7] = qst_args[6];
  qst_call_stack_push(qst_pc);
  qst_pc = qst_function_table[(u16)label];
}
extern "C" {

struct ItemData_801E72B4 {
    u8 data1[12];
    u32 id;
    u8 data2[4];
};

struct Win_801E78D4 { u8 pad[0x2314]; s32 t[16]; };

struct Card_801E7D7C {
    u8 pad[0x24C];
    s32 v;
};

struct ItemData_801E7810 {
    u8 data1[12];
    u32 id;
    u8 data2[4];
};

struct ItemData_801E8000 {
    u8 b0, b1, b2, b3, b4, b5, b6;
    s8 b7;
    u8 b8;
    s8 b9;
    u8 b10;
    s8 b11;
    u32 id;
    u32 extra;
};

LAYOUT_ASSERT(RecoveredGlobal_8000F7FC_lbl_80515F48_size, sizeof(RecoveredGlobal_8000F7FC_lbl_80515F48) == 0x28);

union U_801E8784 { s32 i; f32 f; };

union U_801E871C { s32 i; f32 f; };

union U_801E8750 { s32 i; f32 f; };

union U_801E87EC { s32 i; f32 f; };

union U_801E8854 { s32 i; f32 f; };

union U_801E87B8 { s32 i; f32 f; };


union U_801E8888 { s32 i; f32 f; };

union U_801E8820 { s32 i; f32 f; };

struct Glob_801E915C {
    s32 count;
    f32 f4;
    f32 f8;
    s32 fC;
    s32 out;
    u32 id;
};

struct Glob_801E9274 {
    s32 count;
    f32 f4;
    f32 f8;
    s32 fC;
    s32 out;
    u32 id;
};

struct ByteBlock_30 { u8 bytes[0x30]; };

struct ByteBlock_20 { u8 bytes[0x20]; };

struct ByteBlock_24 { u8 bytes[0x24]; };

struct Ctx_801EA5FC { u8 pad[0x10]; u8 buf[0xFD]; };

struct Ctx_801EAA34 { u8 pad[0x10]; u8 buf[0xFD]; };

struct Ctx_801EAAB4 { u8 pad[0x10]; u8 buf[0xFF]; };

struct Card_801EA0F0 {
    u8 pad[0x21A8];
    u16 stats[7];
};

struct Tag_801EB10C {
    u8 pad0[8];
    s32 id;
    char name[0x10];
    u8 pad1c[4];
    char text[0x200];
};

struct Item_801EBF30 {
    u8 data[12];
    s32 id;
    u32 f10;
};

struct E_801EB484 { s32 a; s32 b; };

struct Pkt_801ED300 {
    u8 cmd;
    u8 size;
    u16 a;
    u16 b;
    u16 pad;
    u16 c;
    u8 d;
    u8 e;
};

struct Pkt_801ED360 {
    u8 cmd;
    u8 size;
    u16 a;
    u16 b;
    u16 pad;
    u16 c;
    u8 d;
    u8 e;
};

struct E_801EB4C4 { s16 a; s16 b; s32 c; };

struct Ctx_801EB508 { u8 pad[0x10]; u8 buf[0xFD]; };

struct Ctx_801EB658 { u8 pad[0x10]; u8 buf[0xFF]; };

struct Item_801EC720 { s8 a; s8 b; s8 c; u8 pad[0x1D]; };

struct Item_801ED7BC {
    u8 data[12];
    s32 id;
    u32 f10;
};

struct Item_801EE0BC {
    u8 data[12];
    s32 id;
    u32 f10;
};

struct Pkt_801EDF64 {
    u8 cmd;
    u8 size;
    u16 a;
    u16 b;
    u16 pad;
    u16 c;
    u8 d;
    u8 e;
};

struct Pkt_801EE330 {
    u8 cmd;
    u8 size;
    u16 pad0;
    u16 a;
    u16 pad1;
    s32 b;
};

struct Ent_801EE5EC {
    u8 name[0x20];
    s32 v;
};

struct Item_801EE77C {
    u8 data[12];
    s32 id;
    u32 f10;
};

struct Player_801EE77C {
    u8 pad[0xD00];
    void *fD00;
};

struct Item_801EEE68 {
    u8 data[12];
    s32 id;
    u32 f10;
};

struct Item_801EE77C;

struct Pair_801F1838 { s32 a; s32 b; };

struct WalkCmd_801F09EC {
    u16 f0;
    u16 player;
    f32 x;
    f32 z;
    u32 flags;
};

struct Obj_801F09EC {
    u8 pad[0x30];
    u32 f30;
};

void VecCopy__FP3VecPC3Vec(Vec *, const void *);
s16 get_actor_tp(u8 *);
s32 obj_getPtr2B0_20();
s16 obj_getS16_2BA(u8 *);
s32 get_current_floor();
f64 atan2_float(void *, f32, f32);
void TLobby__sub_8001DE30(void *);
s32 setControlOverride__12TBoss1DragonFs(int, void *);
int set_camera_capture_overlay_alpha(void*);
saddr TLobby__sub_80070ACC();
s32 set_challenge_mode_split_flag();
s32 TLobby__sub_80070B34(int);
s32 TLobby__sub_80070BE8(s32);
s32 TLobby__sub_80070C50();
s32 TLobby__sub_80070EE4(int);
s32 TLobby__sub_80070F4C();
s32 TLobby__sub_80070FD8();
s32 TLobby__sub_80071064(int);
s32 TLobby__sub_800710D8(Item_801EBF30 *);
s32 TLobby__sub_8007119C(s32);
void add_entry__6TLobbyFiii(void *, void *, s32);
s32 copy_player_visual_record(void *, int);
s32 fn_80077788(void);
s32 fn_80077790(void);
s32 __ct__16TPlyGuildCardTagFv(s32);
s32 TLobby__sub_801036CC();
void init__9TItemDataFv(Item_801EE77C *);
s32 advance_item_id_counter(u16);
void *find_entity_by_id(u16 id);
void TOMineTrap__sub_80171368(f32);
int clear_enabled_main_warps(void*);
int set_hashi_versus2_flag(void*);
int clear_hashi_versus2_flag(void*);
s32 TObjPlayer__sub_801AF904();
void draw_small_label__15TFontSmallLobbyFi(saddr player);
void TLobby__sub_801B1254(saddr player);
s32 foreach_player__10TObjPlayerFv(s32 *);
s32 prepare_guild_return__10TObjPlayerFPv(void *player, s32);
s32 player_flag_1__6TLobbyFv();
s32 enable_action_input__10TObjPlayerFPv();
s32 TObjPlayer__sub_801B3FD8();
s32 TObjPlayer__sub_801B4044();
void send_code50_packet__10TObjPlayerFi(s32 player);
s32 send_code_49_1__10TObjPlayerFi();
void delete_item(void *, s32, s32);
void send_6x29_delete_item__10TObjPlayerFPvii(void *obj, s32 a, s32 b);
void TFontSmallLobby__sub_801C013C(void *p);
s32 send_download_head_d7(TProtocol *, int, int);
}
void play_cue_stream_file(const char *name);
extern "C" {
s32 TLobby__sub_801F3314(int);
int TLobby__sub_801F3384(void *p);
int TLobby__sub_801F33A8(void *p);
int TLobby__sub_801F33CC(void *p);
int TLobby__sub_801F33F0(void *p);
s32 TLobby__sub_801F345C();
void fn_801F34A0(void *p);
s32 fn_get_field_3ac(void *);
void TLobby__sub_801F34E8(int a0, int a1);
int TLobby__sub_801F34F8(void);
int TLobby__sub_801F3568(void*);
s32 TLobby__sub_801F3614();
void copy_position__6TLobbyFv(void *, Vec *);
void TLobby__sub_801F3694(void *p);
int TLobby__sub_801F36BC(void*);
int TLobby__sub_801F36D8(void*);
int TLobby__sub_801F36E4(void*);
s32 TLobby__sub_801F36F0(int);
void TLobby__sub_801F36F8(s32, s32, s32, Item_801ED7BC *);
s32 TLobby__sub_801F3700(int);
void TLobby__sub_801F3708(s32, s32, s32, Item_801ED7BC *);
int set_quest_exit_callback(void*);
int set_quest_cancel_callback(void*);
int set_quest_success_callback(void*);
int THunterGuildSeqOffline__sub_801F3748(void*);
s32 clear_floor_event_flags();
s32 is_room_enemy_set_cleared(int, int, void *);
void unhide_room_set_objects(s32 a, s16 b, s16 c, s32 d);
s32 TCheckRoomSequence__delete_bank_item(u8 *item, s32 slot);
void try_close__6TLobbyFPv(void *p);
int TLobby__sub_802272B4(void*);
int TLobby__sub_8022733C(void*);
void request_active_window_close(void);
s32 unhide_enemies_at__6TLobbyFlll(s32, s32, s32, s32);
}
s32 get_field_d4(void *);
void build_6x77_sync_quest_register(void* p);
void set_quest_floor_designation_ex(s16, s32, s32, s32, s32);
void set_quest_floor_designation(s16, s32, s32, s32);
s32 get_story_flag(s32 flag);
void clear_story_flag(s32 flag);
s32 request_story_select_state(s32 state);
u8 is_floor_switch_set(u32 id, s16 floor);
void clear_current_floor_switch(s32 id);
void set_current_floor_switch(s32 id);
void init_switch_table(void);
extern "C" {
saddr get_window_layout_position(s32);
saddr create_equip_kind_window(saddr, const f32 *, s32);
s32 update_screen__6TLobbyFv();
s32 set_challenge_split_flag__6TLobbyFv();
s32 TLobby__sub_80291DF8(int);
s32 TLobby__sub_80291EAC(s32);
s32 TLobby__sub_8029204C();
s32 TLobby__sub_80292200(int);
void TLobby__sub_80292268(void *, void *, s32);
s32 TLobby__sub_80292270(s32, s32);
s32 TLobby__sub_802924B4(Item_801EBF30 *, u16);
s32 TLobby__sub_8029299C();
s32 TLobby__sub_80292A34();
s32 TLobby__sub_8032CDEC();
int update_alloc_size__6TLobbyFv(void*);
void TObjPlayer__sub_80354CCC(u16 client_index);
void TObjPlayer__sub_80354D14(u16 client_index);
void TObjPlayer__sub_80354DAC(u16 client_index);
void activate_palettex(u16 client_index);
}

extern E_801EB484 duel_result_table[];
extern int battle_ctrl_default_value;
int quest_active_flag;
int evt2_random_enemies_mode;
extern RecoveredGlobal_8000F7FC_lbl_80515F48 fn_801F3480;
extern Pair_801F1838 lbl_80449A38[];
struct RecoveredGlobal_lbl_8050D3E0 { s32 value; u8 remaining[0x4C]; };
extern RecoveredGlobal_lbl_8050D3E0 quest_npc_visual_record;
extern s32 symbolchat_colli_param_table[];
extern s16 battle_event_second_table[];
struct QuestPlayerNameBuffer { s32 value; u8 remaining[0xC]; };
extern QuestPlayerNameBuffer quest_player_name_buffer;
struct QuestPlayerClassNameBuffer { s32 value; u8 remaining[0xC]; };
extern QuestPlayerClassNameBuffer quest_player_class_name_buffer;
extern u8 quest_board_handlers[];
extern f32 lbl_805D3538;
extern f32 lbl_805D353C;
extern f32 lbl_805D3540;
extern f32 lbl_805D3544;
extern f32 lbl_805D3548;
extern saddr resource_decompress_buffer;
extern s32 game_difficulty_selection;
extern f32 lbl_805D5DC4;

void qst_op_va_end() {
    qst_op_stack_popm(1, 7);
}

void qst_op_va_start() { qst_arg_count = 0; qst_op_stack_pushm(1, 7); }

void qst_op_scroll_text() {
    NJS_POINT2 pos;
    NJS_POINT2 size;
    s32 x = qst_args[0];
    s32 y = qst_args[1];
    s32 cols = qst_args[2];
    s32 rows = qst_args[3];
    s32 field90 = qst_args[4];
    f32 timer = *(f32 *)&qst_args[5];
    s32 msg = qst_args[6];
    s32 arg = qst_args[7];
    TWindowMessageScroll *win;

    if (qst_message_window != NULL) {
        qst_message_window->close();
    }
    pos.x = x;
    pos.y = y;
    size.x = 8.0f + (f32)(cols * 0x12);
    size.y = (20.0f + (f32)(rows * 0x14)) - 2.0f;
    win = open_message_scroll_window(&pos, &size, &qst_registers[msg]);
    win->set_frame_mode(field90);
    dispatch_message_window_text(win, arg, 0x13);
    win->set_scroll_speed(timer);
    qst_message_window = win;
}

void qst_op_item_create_multi_cm(u8 i) {
    ItemData_801E72B4 item;
    s32 mode = qst_registers[i++];
    ((void (*)(ItemData_801E72B4 *))init__9TItemDataFv)(&item);
    item.data1[0] = qst_registers[i++];
    item.data1[1] = qst_registers[i++];
    item.data1[2] = qst_registers[i++];
    item.data1[3] = qst_registers[i++];
    item.data1[4] = qst_registers[i++];
    item.data1[5] = qst_registers[i];
    item.id = ((u32 (*)(u16))advance_item_id_counter)(local_client_id);
    switch (mode) {
    case 0:
        TChallenge4PResult::update_entries((saddr)&item, 2);
        break;
    case 1:
        TChallenge4PResult::update_entries((saddr)&item, 0);
        break;
    case 2:
        TChallenge4PResult::update_entries((saddr)&item, 1);
        break;
    }
}

void qst_op_delayed_switch_episode(s32 reg) {
    switch (qst_registers[(u8)reg]) {
    case 0:
        request_story_select_state(0);
        return;
    case 1:
        request_story_select_state(1);
        return;
    }
}

void qst_op_chat_bubble(void) {
    s32 id = qst_args[0];
    const char *text = (const char *)qst_args[1];
    void *player;
    s32 start;
    s32 end;
    s32 i;
    s32 win;
    s32 v;
    if (id < 100) {
        TWindowCtrl::open_default(id, text);
        TWindowCtrl::set_field28(id);
        return;
    }
    start = TLobby::get_game_mode();
    end = start + TLobby::get_lobby_flag();
    for (i = start; i < end; i++) {
        player = (void *)TObjPlayer::get_player_data(i);
        if (player != NULL) {
            win = ((TObjBase *)(player))->get_entity_id();
            if (win < 0x4000) {
                v = fn_get_field_3ac(player);
            } else {
                v = get_field_d4(player);
            }
            if (v == id) {
                TWindowCtrl::open_default(win, text);
                TWindowCtrl::set_field28(win);
                return;
            }
        }
    }
}

void qst_op_chat_box() {
    NJS_POINT2 pos;
    NJS_POINT2 size;
    s32 x = qst_args[0];
    s32 y = qst_args[1];
    s32 cols = qst_args[2];
    s32 rows = qst_args[3];
    s32 field90 = qst_args[4];
    s32 arg = qst_args[5];

    if (qst_message_window != NULL) {
        qst_message_window->close();
    }
    pos.x = x;
    pos.y = y;
    size.x = 8.0f + (f32)(cols * 0x12);
    size.y = (20.0f + (f32)(rows * 0x14)) - 2.0f;
    qst_message_window = create_quest_message_window_at(&pos, &size);
    qst_message_window->set_frame_mode(field90);
    dispatch_message_window_text(qst_message_window, arg, 3);
    qst_suspend_reason = QST_WAIT_MESSAGE;
    TWindowCtrl::set_flag_bit2();
    close_window_if_active(local_client_id);
    request_active_window_close();
    TWindowCtrl::set_close_flag();
}

void qst_op_add_color_overlay() {
    s32 a = qst_args[0];
    s32 b = qst_args[1];
    s32 c = qst_args[2];
    s32 d = qst_args[3];
    s32 e = qst_args[4];
    new TColorOverlayFade(tl_01, 0, e, d, a, b, c);
}

void qst_op_get_chosen_item_id(int a0) { qst_registers[(unsigned char)(a0)] = -1; qst_result_register = a0; qst_suspend_reason = QST_WAIT_ITEM_CHOICE; TWindowCtrl::set_flag_bit2(); close_window_if_active(local_client_id); request_active_window_close(); TWindowCtrl::set_close_flag(); }

void qst_op_prevent_item_select(s32 reg) {
    if (qst_pack_select_help_window != NULL) {
        fn_80278518(qst_pack_select_window, (qst_registers[(u8)reg]));
    }
}

void qst_op_open_pack_select() {
    qst_pack_select_window = (void *)create_equip_kind_window(get_window_layout_position(3), pack_select_window_pos, local_client_id);
    ((TWindowMenuIconLine *)qst_pack_select_window)->refresh_judgment_item_list();
    qst_pack_select_help_window = new TWindowHelpItem((void *)get_window_layout_position(2), local_client_id);
}

void qst_op_prepare_gba_rom_from_disk(void) {
    const char *filename = reinterpret_cast<const char *>(qst_args[0]);
    TLobby::free_luker_object();
    TLobby::send_data(filename);
    TLobby::set_send_buffer(gba_download_data_buffer, static_cast<s32>(gba_download_data_size));
    TLobby::clear_quest_vm_flag();
}

void qst_op_get_players_present(u8 out) {
    s32 p;
    for (p = 0; p < 4; p++, out++) {
        if (get_player_by_client_id(p) != NULL) {
            qst_registers[out] = 1;
        } else {
            qst_registers[out] = 0;
        }
    }
}

void qst_op_find_bank_item(u8 i, u8 out) {
    ItemData_801E7810 item;
    saddr card;
    qst_registers[out] = -1;
    card = get_character_save_record(0xFFFF);
    if (card != 0) {
        ((void (*)(ItemData_801E7810 *))init__9TItemDataFv)(&item);
        item.data1[0] = qst_registers[i++];
        item.data1[1] = qst_registers[i++];
        item.data1[2] = qst_registers[i++];
        item.data1[4] = qst_registers[i];
        if (((CharacterSaveRecord *)card)->find_bank_item((saddr)&item) != 0) {
            qst_registers[out] = 1;
        } else {
            qst_registers[out] = 0;
        }
    }
}

void qst_op_write_counter() {
    s32 idx = qst_args[0];
    s32 val = qst_args[1];
    Win_801E78D4 *w = ((Win_801E78D4 *)get_character_save_record(0xFFFFU));
    if (w != NULL && idx >= 0 && idx < 0x10) {
        w->t[idx] = val;
    }
}

void qst_op_read_counter(void) {
  long long new_var;
  s32 counter_index;
  u32 character_save_record;
  u8 dest_reg;
  counter_index = qst_args[0];
  dest_reg = (u8) qst_args[1];
  character_save_record = get_character_save_record(0xFFFFU);
  if (character_save_record != 0U)
  {
    if ((counter_index >= 0) && (counter_index < 0x10))
    {
      new_var = character_save_record + (counter_index * 4);
      qst_registers[(u8)dest_reg] = *((s32 *) (((s8 *) new_var) + 0x2314));
    }
  }
  else
  {
    qst_registers[(u8)dest_reg] = -1;
  }
}

void qst_op_get_coord_player_detect(u8 i, u8 out) {
    Vec pos;
    f32 r;
    f32 r2;
    s32 p;
    u8 *player;

    pos.x = qst_registers[i++];
    pos.y = 0.0f;
    pos.z = qst_registers[i++];
    r = qst_registers[i];
    r2 = r * r;
    for (p = 0; p < 4; p++, out++) {
        qst_registers[out] = 0;
        player = (u8 *)get_player_by_client_id(p);
        if (player != NULL) {
            if (xz_distance_squared((Vec *)(player + 0x38), &pos) < r2) {
                qst_registers[out] = 1;
            }
        }
    }
}

void qst_op_get_player_room(void) {
    TObjPlayer *player = get_player_by_client_id(qst_args[0]);
    u8 i = qst_args[1];
    if (player != NULL) {
        qst_registers[i++] = player->get_floor();
        qst_registers[i] = player->get_room();
    } else {
        qst_registers[i++] = -1;
        qst_registers[i] = -1;
    }
}

void qst_op_get_player_hp_tp(void) {
    u8 *player = (u8 *)get_player_by_client_id(qst_args[0]);
    u8 i = qst_args[1];
    if (player != NULL) {
        qst_registers[i++] = ((TObjChara *)player)->get_hpmax();
        qst_registers[i++] = ((TObjChara *)player)->get_actor_hp();
        qst_registers[i++] = obj_getS16_2BA(player);
        qst_registers[i] = get_actor_tp(player);
    } else {
        qst_registers[i++] = -1;
        qst_registers[i++] = -1;
        qst_registers[i++] = -1;
        qst_registers[i] = -1;
    }
}

void qst_op_get_section_id() {
  uaddr player;
  u8 temp_r31;
  player = ((uaddr)get_player_by_client_id((s32)((int) qst_args[0])));
  temp_r31 = (u8) qst_args[1];
  if (player != 0U)
  {
    qst_registers[(u8)temp_r31] = (volatile unsigned long)((TPlyPhotonChair *)player)->get_actor_section_id();
    return;
  }
  qst_registers[(u8)temp_r31] = -1;
}

void qst_op_gba_write_identifiers(void) {
    TLobby__sub_801F34E8((qst_args[0]), (qst_args[1]));
}

void qst_op_get_player_level(void) {
    u8 dest_reg;
    TObjPlayer *player;
    player = get_player_by_client_id(qst_args[0]);
    dest_reg = (u8) qst_args[1];
    if (player != NULL) {
        qst_registers[(u8)dest_reg] = player->get_actor_level_index() + 1;
        return;
    }
    qst_registers[(u8)dest_reg] = -1;
}

void qst_op_get_slot_meseta(u8 i) {
    Card_801E7D7C *w;
    if (get_player_by_client_id(local_client_id) != NULL) {
        qst_registers[i] = obj_getPtr2B0_20();
    } else {
        qst_registers[i] = -1;
    }
    w = ((Card_801E7D7C *)get_character_save_record(0xFFFF));
    if (w != 0) {
        (&qst_registers[i])[1] = w->v;
    } else {
        (&qst_registers[i])[1] = -1;
    }
}

void qst_op_get_guildcard_total(int a0) { qst_registers[(unsigned char)(a0)] = TWindowSubComCard::count_active_cards(); }

void qst_op_get_time_played(s32 reg) {
    u8 *character_save_record;
    character_save_record = (u8 *)(get_character_save_record(0xFFFFU));
    if (character_save_record != NULL) {
        qst_registers[(u8)reg] = *(s32 *)((s8 *)character_save_record + 0xC);
        return;
    }
    qst_registers[(u8)reg] = -1;
}
void update_gba_joyboot_transfer();
s32 update_challenge_result_player_locks();
void qst_op_get_lang_setting(void) {
    qst_registers[qst_args[0]] = current_language;
}
void qst_op_wrap_item_with_color() {
    s32 id;
    s8 n;
    TObjPlayer *player;
    Item_801EE77C item;
    void *obj;
    id = ((s32 *)&qst_args)[0];
    n = ((s32 *)&qst_args)[1];
    obj = find_item_by_id(id);
    if (obj != NULL) {
        ((TItem *)obj)->copy_to_item_data((TItemData *)&item);
    } else {
        return;
    }
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        send_6x29_delete_item__10TObjPlayerFPvii(player, (s32)id, 1);
        ((TItemData *)(&item))->set_wrapped();
        ((TItemData *)(&item))->set_present_color(n);
        if (player->can_inventory_accept_item((u8 *)((Item_801EEE68 *)&item)) > 0) {
            player->request_inventory_item((TItemData*)((Item_801EEE68 *)&item));
        }
    }
}

void qst_op_wrap_item() {
    s32 id;
    TObjPlayer *player;
    Item_801EE77C item;
    void *obj;
    id = ((s32 *)&qst_args)[0];
    obj = find_item_by_id(id);
    if (obj != NULL) {
        ((TItem *)obj)->copy_to_item_data((TItemData *)&item);
    } else {
        return;
    }
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        send_6x29_delete_item__10TObjPlayerFPvii(player, (s32)id, 1);
        ((TItemData *)(&item))->set_wrapped();
        if (player->can_inventory_accept_item((u8 *)((Item_801EEE68 *)&item)) > 0) {
            player->request_inventory_item((TItemData*)((Item_801EEE68 *)&item));
        }
    }
}

void qst_op_get_item_info() {
    s32 r;
    void *item;
    ItemData_801E8000 d;
    r = qst_args[1];
    item = find_item_by_id(qst_args[0]);
    if (item != NULL) {
        ((TItem *)item)->copy_to_item_data((TItemData *)&d);
        qst_registers[r++] = d.b0;
        qst_registers[r++] = d.b1;
        qst_registers[r++] = d.b2;
        qst_registers[r++] = d.b3;
        qst_registers[r++] = d.b4;
        qst_registers[r++] = d.b5;
        qst_registers[r++] = d.b6;
        qst_registers[r++] = d.b7;
        qst_registers[r++] = d.b8;
        qst_registers[r++] = d.b9;
        qst_registers[r++] = d.b10;
        qst_registers[r++] = d.b11;
    } else {
        qst_registers[r] = -1;
    }
}

void qst_op_item_delete_noreturn() {
    s32 item_index;
    TObjPlayer *player;

    item_index = qst_args[0];
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        send_6x29_delete_item__10TObjPlayerFPvii(player, (s32)item_index, 1);
    }
}

void qst_op_add_damage_to(void) {
    u16 client_id = qst_args[0];
    f32 damage = (f32)qst_args[1];
    new TQuestDamageTask(client_id, tl_03, damage);
}

void qst_op_gba_update_dl_graph(void) { TLobby::get_selected_slot(); }

void qst_op_gba_destroy_dl_graph(void) { TLobby::destroy_singleton(); }

void qst_op_gba_create_dl_graph(void) { TLobby::init_graph(); }

void qst_op_enable_movement2() {
    TObjPlayer *player = get_player_by_client_id((u16)qst_args[0]);
    if (player != NULL) {
        player->init_local_pad_binding();
    }
}

void qst_op_disable_movement2() {
    TObjPlayer *player = get_player_by_client_id((u16)qst_args[0]);
    if (player != NULL) {
        player->stop_force_if_alive();
    }
}
extern "C" {

s32 TObjPlayer__sub_80354C7C(u16, void *);
}
void qst_op_get_palettex_enabled(void) {
    u8 idx = qst_args[2];
    qst_registers[idx] = TObjPlayer__sub_80354C7C(qst_args[0], qst_args);
}
extern "C" {

s32 is_palettex_activated(u16, void *);
}
void qst_op_get_palettex_activated(void) {
    u8 idx = qst_args[1];
    qst_registers[idx] = is_palettex_activated(qst_args[0], qst_args);
}

void qst_op_disable_palettex(void) {
    TObjPlayer__sub_80354CCC(((u16) qst_args[0]));
}

void qst_op_restore_palettex(void) {
    TObjPlayer__sub_80354DAC(((u16) qst_args[0]));
}

void qst_op_enable_palettex() {
    TObjPlayer__sub_80354D14(((u16) qst_args[0]));
}

void qst_op_activate_palettex() {
    activate_palettex(((u16) qst_args[0]));
}
extern "C" {

s32 set_palettex_callback(u16, int);
}
void qst_op_set_palettex_callback(void) {
    set_palettex_callback(qst_args[0], (u16)qst_args[1]);
}

void qst_op_thaw_and_show_equip() {
    void *self = tl_03;
    if (self != NULL) {
        ((TObject *)self)->resume_update();
    }
}

void qst_op_toggle_freeze_and_hide_equip() {
    void *temp = tl_03;
    if (temp != 0) {
        ((TObject *)temp)->toggle_pause();
    }
}
extern "C" {

s32 count_items_of_type__10TObjPlayerFScScSc(void *player, u8, u8, u8);
}
void qst_op_get_stackable_item_count(s32 i, s32 dst) {
    u16 a = qst_registers[(u8)i++];
    u8 b = qst_registers[(u8)i++];
    u8 c = qst_registers[(u8)i++];
    u8 d = qst_registers[(u8)i];
    TObjPlayer *player = get_player_by_client_id(a);
    if (player != NULL) {
        qst_registers[(u8)dst] = count_items_of_type__10TObjPlayerFScScSc(player, b, c, d);
    }
}

void qst_op_get_total_deaths() {
    u8 dest_reg;
    dest_reg = (u8) qst_args[1];
    TObjPlayer *player = get_player_by_client_id(qst_args[0]);
    if (player != NULL) {
        qst_registers[(u8)dest_reg] = player->get_card_window_field_244();
    }
}

void qst_op_atan2_int(void) {
    u8 dest_reg;
    dest_reg = (u8) qst_args[0];
    qst_registers[(u8)dest_reg] = (s32) (10430.38043493439 * atan2_float((void *) qst_args, (f32) (*(f32 *)&qst_args[1]), (f32) (*(f32 *)&qst_args[2])));
}

void qst_op_tan() {
  s32 arg;
  u8 idx;
  idx = qst_args[0] & 0xFFu;
  arg = qst_args[1];
  f32 v = sin_table_lookup(arg) / cos_table_lookup(arg);
  qst_registers[idx] = *((s32 *) (&v));
}

void qst_op_cos() {
    u8 idx = qst_args[0];
    f32 v = cos_table_lookup(qst_args[1]);
    qst_registers[idx] = *(s32 *)&v;
}

void qst_op_sin() {
    u8 idx = qst_args[0];
    f32 v = sin_table_lookup(qst_args[1]);
    qst_registers[idx] = *(s32 *)&v;
}

void qst_op_fdivi(u8 reg, s32 val) {
    U_801E871C b;
    U_801E871C a;
    a.i = val;
    b.f = *(f32 *)&qst_registers[reg];
    b.f /= a.f;
    qst_registers[reg] = b.i;
}

void qst_op_fdiv(u8 reg, u8 src) {
    U_801E8750 b;
    b.f = *(f32 *)&qst_registers[reg];
    b.f /= *(f32 *)&qst_registers[src];
    qst_registers[reg] = b.i;
}

void qst_op_fmuli(u8 reg, s32 val) {
    U_801E8784 b;
    U_801E8784 a;
    a.i = val;
    b.f = *(f32 *)&qst_registers[reg];
    b.f *= a.f;
    qst_registers[reg] = b.i;
}

void qst_op_fmul(u8 reg, u8 src) {
    U_801E87B8 b;
    b.f = *(f32 *)&qst_registers[reg];
    b.f *= *(f32 *)&qst_registers[src];
    qst_registers[reg] = b.i;
}

void qst_op_fsubi(u8 reg, s32 val) {
    U_801E87EC b;
    U_801E87EC a;
    a.i = val;
    b.f = *(f32 *)&qst_registers[reg];
    b.f -= a.f;
    qst_registers[reg] = b.i;
}

void qst_op_fsub(u8 reg, u8 src) {
    U_801E8820 b;
    b.f = *(f32 *)&qst_registers[reg];
    b.f -= *(f32 *)&qst_registers[src];
    qst_registers[reg] = b.i;
}

void qst_op_faddi(u8 reg, s32 val) {
    U_801E8854 b;
    U_801E8854 a;
    a.i = val;
    b.f = *(f32 *)&qst_registers[reg];
    b.f += a.f;
    qst_registers[reg] = b.i;
}

void qst_op_fadd(u8 reg, u8 src) {
    U_801E8888 b;
    b.f = *(f32 *)&qst_registers[reg];
    b.f += *(f32 *)&qst_registers[src];
    qst_registers[reg] = b.i;
}

void qst_op_float2dec(s32 dst, s32 src) {
    qst_registers[(u8)dst] = (s32) *(f32 *)&qst_registers[(u8)src];
}

void qst_op_dec2float(u8 reg, u8 src) {
    U_801E8888 b;
    b.f = (f32)qst_registers[src];
    qst_registers[reg] = b.i;
}

void qst_op_check_npc_straggle_ex(u8 i, u8 slot) {
    u8 start = i;
    Vec v;
    ObjectSetData s;
    TObjQuestColApcINW *obj;

    TLobby__sub_80207F30(&s);
    s.position.x = qst_registers[i++];
    s.position.y = qst_registers[i++];
    s.position.z = qst_registers[i++];
    s.scale.x = qst_registers[i++];
    s.set_params[0] = qst_registers[i++];
    s.scale.y = qst_registers[i++];
    obj = create_quest_col_apc_inw__6TLobbyFPvPv(&s, &qst_registers[start]);
    if (obj != NULL) {
        v.x = qst_registers[i++];
        v.y = qst_registers[i++];
        v.z = qst_registers[i];
        TLobby__sub_801F3500(obj, &v);
        qst_registers[slot] = obj->get_entity_id();
    }
}

void qst_op_set_obj_param_ex(u8 i, u8 out) {
    ObjectSetData s;
    void *obj;
    TLobby__sub_80207F30(&s);
    s.position.x = qst_registers[i++];
    s.position.y = qst_registers[i++];
    s.position.z = qst_registers[i++];
    s.scale.x = qst_registers[i++];
    s.set_params[0] = qst_registers[i++];
    s.scale.y = qst_registers[i];
    obj = create_quest_col_alock(&s, &qst_registers[out]);
    if (obj != NULL) {
        qst_registers[out] = ((TObjBase *)(obj))->get_entity_id();
    }
}

void qst_op_party_coords_call_ex(u8 i, u8 out) {
    ObjectSetData s;
    void *obj;
    u8 first = i;
    TLobby__sub_80207F30(&s);
    s.position.x = qst_registers[i++];
    s.position.y = qst_registers[i++];
    s.position.z = qst_registers[i++];
    s.scale.x = qst_registers[i++];
    s.scale.y = qst_registers[i++];
    s.set_params[0] = qst_registers[i];
    obj = fn_80196214(&s, &qst_registers[first]);
    if (obj != NULL) {
        qst_registers[out] = ((TObjBase *)(obj))->get_entity_id();
    }
}

void qst_op_npc_coords_call_ex(u8 i, u8 out) {
    ObjectSetData s;
    void *obj;
    u8 first = i;
    TLobby__sub_80207F30(&s);
    s.position.x = qst_registers[i++];
    s.position.y = qst_registers[i++];
    s.position.z = qst_registers[i++];
    s.scale.x = qst_registers[i++];
    s.set_params[0] = qst_registers[i];
    obj = fn_801963A8(&s, &qst_registers[first]);
    if (obj != NULL) {
        qst_registers[out] = ((TObjBase *)(obj))->get_entity_id();
    }
}

void qst_op_at_coords_talk_ex(u8 i, u8 out) {
    ObjectSetData s;
    void *obj;
    u8 first = i;
    TLobby__sub_80207F30(&s);
    s.position.x = qst_registers[i++];
    s.position.y = qst_registers[i++];
    s.position.z = qst_registers[i++];
    s.scale.x = qst_registers[i++];
    s.set_params[0] = qst_registers[i];
    obj = fn_80196814(&s, &qst_registers[first]);
    if (obj != NULL) {
        qst_registers[out] = ((TObjBase *)(obj))->get_entity_id();
    }
}

void qst_op_at_coords_call_ex(u8 i, u8 out) {
    ObjectSetData s;
    void *obj;
    u8 first = i;
    TLobby__sub_80207F30(&s);
    s.position.x = qst_registers[i++];
    s.position.y = qst_registers[i++];
    s.position.z = qst_registers[i++];
    s.scale.x = qst_registers[i++];
    s.set_params[0] = qst_registers[i];
    obj = create_quest_col(&s, &qst_registers[first]);
    if (obj != NULL) {
        qst_registers[out] = ((TObjBase *)(obj))->get_entity_id();
    }
}

void qst_op_unfreeze_everything(void) {
    main_task.resume_game_layers();
}

void qst_op_toggle_freeze_everything(void) {
    main_task.toggle_pause_game_layers();
}

void qst_op_unfreeze_enemies() {
    void *temp = tl_04;
    if (temp != 0) {
        ((TObject *)temp)->resume_update();
    }
}

void qst_op_toggle_freeze_enemies() {
    void *temp = tl_04;
    if (temp != 0) {
        ((TObject *)temp)->toggle_pause();
    }
}

void qst_op_npc_text_id(u8 a0, u8 a1, void *a2) {
    s32 x = qst_registers[a0];
    s32 v = qst_registers[a1];
    u16 y = x;
    uaddr r = ((u32 (*)(void *, int))qst_label_address)(a2, x);
    if (r != 0U) {
        set_partner_dialogue_override((const char *)r, v, (u16)y);
    }
}

void qst_op_compute_bezier_curve_point() {
    Vec v;
    Glob_801E915C *g = (Glob_801E915C *)qst_args;
    s32 count = g->count;
    f32 f4 = g->f4;
    f32 f8 = g->f8;
    s32 fC = g->fC;
    s32 out = g->out;
    CurvePathPoint *pts;
    s32 i;
    s32 ret;
    s32 j;
    Vec *dst;
    pts = (CurvePathPoint *)((uaddr (*)(void *, int))qst_label_address)((void *)(uaddr)(u16)g->id, (saddr)g);
    if (pts == NULL) {
        return;
    }
    for (i = 0; i < count; i++) {
        reinterpret_cast<TLobby *>(&pts[i])->bswap_4x32();
    }
    ret = fn_8034D3D0(pts, f4, count, f8, fC, &v, 100);
    dst = (Vec *)&qst_registers[out];
    dst->x = v.x;
    dst->y = v.y;
    dst->z = v.z;
    *(s32 *)&((f32 *)qst_registers)[out + 3] = ret;
    for (j = 0; j < count; j++) {
        reinterpret_cast<TLobby *>(&pts[j])->bswap_4x32();
    }
    return;
}

void qst_op_get_vector_from_path() {
    Vec v;
    Glob_801E9274 *g = (Glob_801E9274 *)qst_args;
    s32 count = g->count;
    f32 f4 = g->f4;
    f32 f8 = g->f8;
    s32 fC = g->fC;
    s32 out = g->out;
    CurvePathPoint *pts;
    s32 i;
    s32 ret;
    s32 j;
    Vec *dst;
    pts = (CurvePathPoint *)((uaddr (*)(void *, int))qst_label_address)((void *)(uaddr)(u16)g->id, (saddr)g);
    if (pts == NULL) {
        return;
    }
    for (i = 0; i < count; i++) {
        reinterpret_cast<TLobby *>(&pts[i])->bswap_4x32();
    }
    ret = fn_8034D790(pts, f4, count, f8, fC, &v);
    dst = (Vec *)&qst_registers[out];
    dst->x = v.x;
    dst->y = v.y;
    dst->z = v.z;
    *(s32 *)&((f32 *)qst_registers)[out + 3] = ret;
    for (j = 0; j < count; j++) {
        reinterpret_cast<TLobby *>(&pts[j])->bswap_4x32();
    }
    return;
}

void qst_op_get_pressed_buttons(u8 a0, u8 a1) {
    qst_registers[a1] = controller_input_state.controllers[qst_registers[a0]].pressed_buttons;
}

void qst_op_get_held_buttons(u8 src, u8 dst) {
    qst_registers[dst] = controller_input_state.controllers[qst_registers[src]].buttons;
}

void qst_op_default_camera_pos2(void* p) { reset_camera_to_local_player(); }

void qst_op_fleti_locked_camera(void) {
    Vec *p = (Vec *)(qst_registers + qst_args[1]);
    Vec v;
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    set_locked_camera_override(&v, qst_args[0]);
}

void qst_op_fleti_fixed_camera() {
    Vec a;
    Vec b;
    Vec *p = (Vec *)(qst_registers + qst_args[0]);
    a.x = p[0].x;
    a.y = p[0].y;
    a.z = p[0].z;
    b.x = p[1].x;
    b.y = p[1].y;
    b.z = p[1].z;
    set_fixed_camera_override(&a, &b);
}

void qst_op_move_coords_object(s32 i, s32 k) {
    Vec v;
    v.x = qst_registers[(u8)k++];
    v.y = qst_registers[(u8)k++];
    v.z = qst_registers[(u8)k];
    TObjQuestColBase *trigger = TQuestColCtrl::find_by_id((u16)qst_registers[(u8)i]);
    if (trigger != NULL) {
        trigger->set_position_from(&v);
    }
}

void qst_op_close_chat_bubble(s32 reg) {
    TWindowCtrl::close_windows_by_flags(qst_registers[(u8)reg]);
}

int qst_op_set_screen_bw(void* p) { return TLobby__sub_801F3568(p); }

int qst_op_set_motion_blur() { return set_camera_capture_overlay_alpha((void*)(143)); }

void qst_op_restore_tp(s32 reg) {
    apply_player_slot_status(qst_registers[(u8)reg], 0xB);
}

void qst_op_restore_hp(s32 reg) {
    apply_player_slot_status(qst_registers[(u8)reg], 0xA);
}

void qst_op_set_slot_zalure(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg], 9);
}

void qst_op_set_slot_jellen(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg], 8);
}

void qst_op_set_slot_deband(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg], 7);
}

void qst_op_set_slot_shifta(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg], 6);
}

void qst_op_set_slot_confuse(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg], 5);
}

void qst_op_set_slot_slow(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg], 4);
}

void qst_op_set_slot_freeze(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg], 3);
}

void qst_op_set_slot_shock(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg], 2);
}

void qst_op_set_slot_paralyze(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg], 1);
}

void qst_op_set_slot_poison(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg], 0);
}

void qst_op_clear_slot_invincible(s32 slot_reg) {
    reset_player_lobby_model(qst_registers[(u8)slot_reg]);
}

void qst_op_set_slot_invincible(s32 slot_reg, s32 value_reg) {
    update_player_field(qst_registers[(u8)slot_reg], qst_registers[(u8)value_reg]);
}

struct Move_801E989C {
    u16 f0;
    u16 id;
    f32 x;
    f32 z;
    u8 pad[4];
};
void qst_op_run_to_coord(u8 regs) {
    Move_801E989C m;
    f32 x;
    f32 z;
    u16 id;
    s32 i;

    i = regs;
    x = qst_registers[i++];
    i++;
    z = qst_registers[i++];
    id = qst_registers[i];
    if (get_player_by_client_id(id) != 0) {
        ((G_MoveToPosition_6x41_6x42 *)&m)->init();
        m.id = id;
        m.x = x;
        m.z = z;
        ((G_MoveToPosition_6x41_6x42 *)&m)->send();
    }
}

void qst_op_stop_animation(s32 reg) {
    end_camera_pan_for_client(qst_registers[(u8)reg]);
}

void qst_op_use_animation(s32 slot_reg, s32 anim_reg) {
    apply_to_battle_player_slot(qst_registers[(u8)slot_reg], qst_registers[(u8)anim_reg]);
}
void TLobby::reset_random_enemies_mode(TObject *) { TLobby::clear_counter(); evt2_random_enemies_mode = 0; TKeyBoardControl__sub_8000F950(); }

void qst_op_qexit() {
    if (is_quest_active() == 1) {
        new TScreenFadeOut(tl_00, TLobby::reset_random_enemies_mode);
    }
}

void qst_op_results_window_visible_multi_cm(s32 reg) {
    if (update_challenge_result_player_locks() != 0) {
        qst_registers[(u8)reg] = 1;
        return;
    }
    qst_registers[(u8)reg] = 0;
}

void qst_op_congrats_msg_multi_cm(u8 reg) {
    s32 i;
    TChallenge4PResult::clear_slot_entries();
    i = 0;
    do {
        TChallenge4PResult::create((u16)i, qst_registers[reg]);
        i += 1;
    } while (i < 4);
}

void qst_op_start_or_update_gba_joyboot(s32 idx) {
    s32 tbl[5];
    s32 n;
    *(Tbl_801E9AF8 *)tbl = lobby_index_identity_table_a;
    update_gba_joyboot_transfer();
    n = TLobby__sub_801F34F8();
    if (n >= 0 && n < 5) {
        qst_registers[(u8)idx] = tbl[n];
    } else {
        qst_registers[(u8)idx] = 2;
    }
}

void qst_op_prepare_gba_rom_from_download() { update_alloc_size__6TLobbyFv((void*)0); TLobby::set_send_buffer(gba_download_data_buffer, static_cast<s32>(gba_download_data_size)); }

void qst_op_get_dl_status(s32 reg) {
    if (TLobby::get_lobby_count() != 0) {
        qst_registers[(u8)reg] = 0;
        return;
    }
    if (TLobby::get_field_6CE8() != 0) {
        qst_registers[(u8)reg] = 2;
        return;
    }
    qst_registers[(u8)reg] = 1;
}

void qst_op_file_dl_req(void) {
    send_download_head_d7(TLobby::protocol_instance, (int) ((u8) qst_args[0]), (int) (qst_args[1]));
    TLobby__sub_801F3614();
    TLobby__sub_8032CDEC();
}

void qst_op_set_episode(s32 episode) {
    switch (episode) {
    case 0:
        TAdStorySelectGC::set_state(0);
        return;
    case 1:
        TAdStorySelectGC::set_state(1);
        return;
    default:
        TAdStorySelectGC::set_state(0);
        return;
    }
}

int qst_op_write_flag_buf_to_event_flags2(void* p) { return ((int (*)(void*))qst_op_write_flag_buf_to_event_flags)(p); }

void qst_op_load_guild_card_file_creation_time_to_flag_buf() {
    s32 var_r0;
    void *state;

    state = (void *)(saddr)TAdSinglePlyChrSelectGC::get_state();
    if (state != NULL) {
        var_r0 = *(s32 *)((s8 *)state + 0xE284);
    } else {
        var_r0 = 0;
    }
    qst_flag_buf = var_r0;
}

void qst_op_chl_show_dead_player_list() {
    if (is_split_screen() == 1) {
        update_screen__6TLobbyFv();
        return;
    }
    TLobby::update_dead_list_win();
}

void qst_op_disable_retry_menu() {
    if (is_split_screen() == 1) {
        set_challenge_split_flag__6TLobbyFv();
        return;
    }
    set_challenge_mode_split_flag();
}

void qst_op_chl_set_min_time_online(s32 reg) {
    if (is_split_screen() == 1) {
        TLobby__sub_80291DF8((int) (qst_registers[(u8)reg]));
        return;
    }
    TLobby__sub_80070B34((int) (qst_registers[(u8)reg]));
}

void qst_op_check_for_hacking(u8 out) {
    u32 *p;
    s16 i;
    u8 *player;
    qst_registers[out] = 0;
    p = (u32 *)0x8C007220;
    for (i = 0; i < 0xC0U; i++) {
        if (*p++ != 0) {
            qst_registers[out] |= 1;
        }
    }
    if (fn_80077790() == 1) {
        qst_registers[out] |= 2;
    }
    if (fn_80077788() == 1) {
        qst_registers[out] |= 4;
    }
    if (TLobby::get_drop_flag() == 1) {
        qst_registers[out] |= 8;
    }
    player = ((u8 *)get_player_by_client_id(local_client_id));
    if (player != NULL && static_cast<u32>(TObjPlayer__sub_801BFFA0(player + 0x41C)) != 0) {
        qst_registers[out] |= 0x10;
    }
}

void qst_op_write4(void) {
    **(s32 **)&qst_args[0] = qst_args[1];
}

void qst_op_write2(void) {
    **(s16 **)&qst_args[0] = (s16) qst_args[1];
}

void qst_op_write1(void) {
    **(s8 **)&qst_args[0] = (s8) qst_args[1];
}

void qst_op_read4(void) {
    qst_registers[(u8)qst_args[0]] = *(s32 *)((s8 *)(*(s32 **)&qst_args[1]) + 0);
}

void qst_op_read2(void) {
    qst_registers[(u8)qst_args[0]] = (s32) *(s16 *)((s8 *)(*(s16 **)&qst_args[1]) + 0);
}

void qst_op_read1() {
    qst_registers[(u8)qst_args[0]] = (s32) (s8) *(u8 *)((s8 *)(*(u8 **)&qst_args[1]) + 0);
}

void qst_op_someone_has_spoken(s32 reg) {
    if (strcmp((const char *)TLobby::get_unit_list(), "") == 0) {
        qst_registers[(u8)reg] = 0;
        return;
    }
    qst_registers[(u8)reg] = 1;
}

void qst_op_party_has_name(s32 reg) {
    if (strcmp((const char *)TLobby__sub_80070ACC(), "") == 0) {
        qst_registers[(u8)reg] = 0;
        return;
    }
    qst_registers[(u8)reg] = 1;
}

void qst_op_get_number_of_players2(int a0) { qst_registers[(unsigned char)(a0)] = TLobby::get_game_mode(); }
extern "C" {

u8 *TWindowSubStatusDisp__sub_8006F134(s32, s32);
}
void qst_op_get_cmode_prize_rank(s32 reg) {
    u32 character_save_record;

    character_save_record = get_character_save_record(0xFFFF);
    if (character_save_record != 0U) {
        qst_registers[(u8)reg] = (s32)TLobby::get_slot_clamped((u32)((int) (*(s32 *)((s8 *)(TWindowSubStatusDisp__sub_8006F134(character_save_record + 0x21C4, -1)) + 4))));
    }
}

void qst_op_get_ba_record(u8 i) {
    Card_801EA0F0 *card = (Card_801EA0F0 *)get_character_save_record(0xFFFF);
    if (card != NULL) {
        qst_registers[i++] = card->stats[0];
        qst_registers[i++] = card->stats[1];
        qst_registers[i++] = card->stats[2];
        qst_registers[i++] = card->stats[3];
        qst_registers[i++] = card->stats[4];
        qst_registers[i++] = card->stats[5];
        qst_registers[i] = card->stats[6];
    }
}

void qst_op_is_there_grave_message(s32 reg) {
    uaddr character_save_record;
    character_save_record = get_character_save_record(0xFFFFU);
    if (character_save_record != 0U) {
        if (strncmp(((CharacterSaveGraveMessage *)character_save_record)->grave_message, "", 0x20) == 0) {
            qst_registers[(u8)reg] = 0;
            return;
        }
        qst_registers[(u8)reg] = 1;
        return;
    }
    qst_registers[(u8)reg] = 0;
}

void qst_op_vol_opt_is_dead(s32 reg) {
    if ((s32) volopt_death_active != 0) {
        qst_registers[(u8)reg] = 1;
        return;
    }
    qst_registers[(u8)reg] = 0;
}

void qst_op_ba_death_tech_level_up(void) {
    if ((u32)qst_args[0] <= 0x1DU) {
        battle_rules.death_tech_level_up = (s16) (u32)qst_args[0];
    }
}

void qst_op_set_shrink_size(s32 player_variable, saddr size_variable) {
    TObjPlayer* player = get_player_by_client_id(qst_registers[(u8)player_variable]);
    if (player && !player->obj_isState2_324()) {
        s32 whole = qst_registers[(u8)size_variable++];
        s32 numerator = qst_registers[(u8)size_variable++];
        s32 denominator = qst_registers[(u8)size_variable];
        player->scale_state.set_scalar(denominator > 0 ? (f32)whole + (f32)numerator / (f32)denominator : (f32)whole);
    }
}

void qst_op_set_symbol_chat_collision(u8 i) {
    ObjectSetData s;
    TLobby__sub_80207F30(&s);
    s.position.x = qst_registers[i++];
    s.position.y = qst_registers[i++];
    s.position.z = qst_registers[i++];
    s.scale.x = qst_registers[i++];
    s.set_params[0] = qst_registers[i++];
    s.set_params[1] = qst_registers[i++];
    s.set_params[2] = qst_registers[i++];
    symbolchat_colli_param_table[0] = ((int (*)(int))qst_label_address)((u16)qst_registers[i++]);
    symbolchat_colli_param_table[1] = ((int (*)(int))qst_label_address)((u16)qst_registers[i++]);
    symbolchat_colli_param_table[2] = ((int (*)(int))qst_label_address)((u16)qst_registers[i]);
    TOSymbolchatColli::create(&s);
    symbolchat_colli_param_table[1] = 0;
    symbolchat_colli_param_table[0] = 0;
    symbolchat_colli_param_table[2] = 0;
}

void qst_op_set_chat_callback_no_filter(u8 i) {
    ObjectSetData s;
    TLobby__sub_80207F30(&s);
    s.rotation[0] = 0;
    s.rotation[1] = 1;
    s.position.x = qst_registers[i++];
    s.position.y = qst_registers[i++];
    s.position.z = qst_registers[i++];
    s.scale.x = qst_registers[i++];
    s.set_params[0] = qst_registers[i];
    TOChatSensor::create(&s);
}

void qst_op_write_flag_buf_to_event_flags(u8 reg) {
    s32 idx = qst_registers[reg];
    Ctx_801EA5FC *w = (Ctx_801EA5FC *)TAdSinglePlyChrSelectGC::get_global_state();
    if (w != NULL && idx >= 0 && idx < 0xFD) {
        move_data((void *)((&w->buf[idx])), (const void *)(&qst_flag_buf), 4);
    }
}

void qst_op_load_serial_number_to_flag_buf() {
    u32 serial_access;

    serial_access = TQuestVmDownLoadServer::get_serial_access();
    qst_flag_buf = serial_access;
    if (serial_access == 0U) {
        qst_flag_buf = TQuestVmDownLoadServer::poll_serial_access();
    }
}

void qst_op_is_bosswarp_opt_disabled(s32 reg) {
    if (is_split_screen() == 1) {
        if (TLobby::get_normalized_mode() != 0) {
            qst_registers[(u8)reg] = 1;
            return;
        }
        qst_registers[(u8)reg] = 0;
        return;
    }
    if (TLobby::get_state() != 0) {
        qst_registers[(u8)reg] = 1;
        return;
    }
    qst_registers[(u8)reg] = 0;
}

void qst_op_enable_bosswarp_option() {
    if (is_split_screen() == 1) {
        TLobby__sub_80291EAC(0);
        return;
    }
    TLobby__sub_80070BE8(0);
}

void qst_op_disable_bosswarp_option() {
    if (is_split_screen() == 1) {
        TLobby__sub_80291EAC(1);
        return;
    }
    TLobby__sub_80070BE8(1);
}

void qst_op_player_recovery(s32 reg) {
    s32 player;
    player = (saddr)get_player_by_client_id(qst_registers[(u8)reg]);
    if (player != 0) {
        send_code_49_1__10TObjPlayerFi();
        send_code50_packet__10TObjPlayerFi((player));
    }
}

void qst_op_ba_forbid_scape_dolls() {
    u32 v = (u32)qst_args[0];
    if (v < 2) {
        battle_rules.forbid_scape_dolls = forbid_scape_dolls_values[v];
    }
}

void qst_op_chl_create_retry_menu() {
    if (is_split_screen() == 1) {
        TLobby::draw_if_ready2();
        return;
    }
    TLobby::draw_if_ready();
}

void qst_op_get_chl_retry_choice(s32 reg) {
    s32 retry_choice;
    if (is_split_screen() == 1) {
        retry_choice = TLobby::check_ready_status();
    } else {
        retry_choice = TLobby::check_ready_state();
    }
    switch (retry_choice) {
    case -1:
        qst_registers[(u8)reg] = 0;
        return;
    case 0:
        qst_registers[(u8)reg] = 1;
        return;
    case 1:
        qst_registers[(u8)reg] = 2;
        return;
    }
}

void qst_op_reset_map(void) {
    TLobby__sub_801036CC();
    if (quest_mission_manager != NULL) {
        TQuestThread::clear_buffer(quest_mission_manager);
    }
    TQuestThread::destroy_all_in((TObject *)tl_00);
    TLobby::init_sub_objects();
    reset_id_tables();
    clear_floor_event_flags();
    init_switch_table();
    TRaderMapCore::free_map_data();
    if (is_split_screen() == 1) {
        TLobby::reset_menu_state_globals();
        return;
    }
    TLobby__sub_80070C50();
}

void qst_op_get_random(s32 regs, s32 dst) {
  s32 min_value;
  s32 value;
  s32 span;
  min_value = qst_registers[(u8)regs];
  span = qst_registers[(u8)(regs + 1)];
  value = (s32) (((f32) span) * (3.0517578125e-05f * ((f32) rand())));
  if (value < min_value)
  {
    value = min_value;
  }
  qst_registers[(u8)dst] = value;
}

void qst_op_shift_right(s32 dst, s32 src) {
    qst_registers[(u8)dst] >>= qst_registers[(u8)src];
}

void qst_op_shift_left(s32 dst, s32 src) {
    qst_registers[(u8)dst] <<= qst_registers[(u8)src];
}

void qst_op_get_eventflag32(u8 a0, u8 a1) {
    s32 v;
    qst_registers[a1] = 0;
    Ctx_801EAA34 *w = ((Ctx_801EAA34 *)TAdSinglePlyChrSelectGC::get_global_state());
    if (w != NULL) {
        s32 i = qst_registers[a0];
        if (i >= 0 && i < 0xFD) {
            memcpy(&v, &w->buf[i], 4);
            qst_registers[a1] = v;
        }
    }
}

void qst_op_get_eventflag16(u8 a0, u8 a1) {
    s16 v;
    qst_registers[a1] = 0;
    Ctx_801EAAB4 *w = ((Ctx_801EAAB4 *)TAdSinglePlyChrSelectGC::get_global_state());
    if (w != NULL) {
        s32 i = qst_registers[a0];
        if (i >= 0 && i < 0xFF) {
            memcpy(&v, &w->buf[i], 2);
            qst_registers[a1] = v;
        }
    }
}

void qst_op_set_enemy_movement_data(s32 label) {
    ByteBlock_30 packet;
    uaddr data_addr;
    data_addr = ((int (*)(int))qst_label_address)(label);
    if (data_addr != 0U) {
        packet = *(const ByteBlock_30 *)(data_addr - 4 + 4);
        TLobby::bswap_entry_words((saddr) &packet);
        TLobby::broadcast(&packet);
    }
}

void qst_op_set_enemy_resist_data(s32 label) {
    ActorParamBlock packet;
    uaddr data_addr;
    data_addr = ((int (*)(int))qst_label_address)(label);
    if (data_addr != 0U) {
        *reinterpret_cast<ByteBlock_20 *>(&packet) = *reinterpret_cast<const ByteBlock_20 *>(data_addr);
        packet.swap_endian();
        TLobby__sub_8001DE30(&packet);
    }
}

void qst_op_set_enemy_attack_data(s32 label) {
    AttackParams packet;
    uaddr data_addr;
    data_addr = ((int (*)(int))qst_label_address)(label);
    if (data_addr != 0U) {
        *reinterpret_cast<ByteBlock_30 *>(&packet) = *reinterpret_cast<const ByteBlock_30 *>(data_addr);
        packet.byteswap_packet();
        TLobby::copy_all_entries(&packet);
    }
}

void qst_op_set_enemy_physical_data(int _w0) {
    struct CopyStack_801EAC48 { u8 bytes[0x24]; };
    CopyStack_801EAC48 copy_storage_801EAC48;
    uaddr data_addr;
    data_addr = ((u32)((int (*)(int))qst_label_address)(_w0));
    if (data_addr != 0U) {
        *(ByteBlock_24 *)(copy_storage_801EAC48.bytes) = *(const ByteBlock_24 *)((data_addr - 4) + 4);
        bswap__12player_statsFv(((copy_storage_801EAC48.bytes)));
        TLobby::copy_data((void *) ((copy_storage_801EAC48.bytes)));
    }
}

void qst_op_set_override_enemy_bp_index() {
    TLobby__sub_8001DEA8((qst_args[0]));
}

void qst_op_set_chat_callback() {
    ObjectSetData s;
    u8 i = (u32)qst_args[0];
    saddr arg = qst_args[1];
    TOChatSensor *sensor;
    TLobby__sub_80207F30(&s);
    s.position.x = qst_registers[i++];
    s.position.y = qst_registers[i++];
    s.position.z = qst_registers[i++];
    s.scale.x = qst_registers[i++];
    s.set_params[0] = qst_registers[i];
    sensor = static_cast<TOChatSensor *>(TOChatSensor::create(&s));
    if (sensor != NULL) {
        sensor->set_trigger_text((void *)arg);
    }
}

void qst_op_set_cmode_grave_rates(s32 reg) {
    TObjTombstoneDropRates rates;
    s32 *p = &qst_registers[(u8)reg];
    f32 num, den, ratio;
    num = p[0];
    den = p[1];
    ratio = num / den;
    rates.count[0] = ratio;
    num = p[2];
    den = p[3];
    ratio = num / den;
    rates.count[1] = ratio;
    num = p[4];
    den = p[5];
    ratio = num / den;
    rates.count[2] = ratio;
    num = p[6];
    den = p[7];
    ratio = num / den;
    rates.count[3] = ratio;
    num = p[8];
    den = p[9];
    ratio = num / den;
    rates.kind[0] = ratio;
    num = p[10];
    den = p[11];
    ratio = num / den;
    rates.kind[1] = ratio;
    num = p[12];
    den = p[13];
    ratio = num / den;
    rates.kind[2] = ratio;
    num = p[14];
    den = p[15];
    ratio = num / den;
    rates.kind[3] = ratio;
    num = p[16];
    den = p[17];
    ratio = num / den;
    rates.kind[4] = ratio;
    num = p[18];
    den = p[19];
    ratio = num / den;
    rates.kind[5] = ratio;
    set_tombstone_drop_rates(&rates);
}

void qst_op_chl_get_timerecord(s32 reg) {
    if (is_split_screen() == 1) {
        qst_registers[(u8)reg] = TLobby__sub_8029204C();
        return;
    }
    qst_registers[(u8)reg] = TLobby::get_max_challenge_time();
}

void qst_op_chl_set_timerecord(s32 reg) {
    if (is_split_screen() == 1) {
        TLobby__sub_80292200((int) (qst_registers[(u8)reg]));
        return;
    }
    TLobby__sub_80070EE4((int) (qst_registers[(u8)reg]));
}

void qst_op_get_game_version(s32 reg) {
    qst_registers[(u8)reg] = 3;
}

void qst_op_send_mail(void) {
    Tag_801EB10C tag;
    char buf[0x400];
    TTokenList *fields;
    u8 i = (u32)qst_args[0];
    char *src = *(char **)&qst_args[1];
    ((TLobby *)((saddr)&tag))->init_guild_card_tag();
    fields = new TTokenList(NULL, 0, 0);
    strncpy(buf, (const char *)src, 0x3FF);
    trim_whitespace(buf);
    fields->tokenize_args(buf);
    if (fields->count > 2) {
        delete fields;
    } else {
        tag.id = qst_registers[i];
        strncpy(tag.name, fields->tokens[0], 0xF);
        tag.name[0xF] = 0;
        strncpy(tag.text, fields->tokens[1], 0x1FF);
        tag.text[0x1FF] = 0;
        try_close__6TLobbyFPv(&tag);
        delete fields;
    }
}

s32 TLobby::init_guild_card_tag() {
    s32 self_addr = (saddr)this;
    __ct__16TPlyGuildCardTagFv(self_addr + 4);
    return self_addr;
}

void qst_op_get_player_state(s32 slot_reg, saddr dst) {
    saddr player;
    player = (saddr)get_player_by_client_id(qst_registers[(u8)slot_reg]);
    if (player != 0) {
        if (TLobby__sub_801F345C() != 0) {
            qst_registers[(u8)dst] = 1;
            return;
        }
        if (((TObjPlayer *)player)->test_action_4() != 0) {
            qst_registers[(u8)dst] = 2;
            return;
        }
        if (((TLobby *)player)->test_flag_16() != 0) {
            qst_registers[(u8)dst] = 3;
            return;
        }
        if (TLobby__sub_801F33F0((void *)player) != 0) {
            qst_registers[(u8)dst] = 4;
            return;
        }
        if (TLobby__sub_801F33CC((void *)player) != 0) {
            qst_registers[(u8)dst] = 5;
            return;
        }
        if (TLobby__sub_801F33A8((void *)player) != 0) {
            qst_registers[(u8)dst] = 6;
            return;
        }
        if (TLobby__sub_801F3384((void *)player) != 0) {
            qst_registers[(u8)dst] = 7;
            return;
        }
        if (((TLobby *)player)->check_flag_24576() != 0) {
            qst_registers[(u8)dst] = 8;
            return;
        }
        if (((TObjPlayer *)player)->test_action_8000() != 0) {
            qst_registers[(u8)dst] = 9;
            return;
        }
        if (TLobby__sub_801F3314(player) != 0) {
            qst_registers[(u8)dst] = 0xA;
            return;
        }
        if (((TObjPlayer *)player)->test_action_40000() != 0) {
            qst_registers[(u8)dst] = 0xB;
            return;
        }
        if (((TObjPlayer *)player)->test_action_80000() != 0) {
            qst_registers[(u8)dst] = 0xC;
            return;
        }
        qst_registers[(u8)dst] = 0;
        return;
    }
    qst_registers[(u8)dst] = 0;
}

void qst_op_disable_win_pfx(void) { battle_ctrl_default_value = 0; }

void qst_op_enable_win_pfx(void) { battle_ctrl_default_value = 1; }

void qst_op_ba_get_score(u8 src, u8 dst) {
    E_801EB484 e = duel_result_table[qst_registers[src]];
    qst_registers[dst] = e.b;
}

void qst_op_ba_get_place(u8 a0, u8 a1) {
    E_801EB4C4 e = ((E_801EB4C4 *)&duel_result_table)[qst_registers[a0]];
    qst_registers[a1] = e.b;
}

void qst_op_set_eventflag32() {
    u32 i = (u32)qst_args[0];
    s32 v = qst_args[1];
    Ctx_801EB508 *w = (Ctx_801EB508 *)TAdSinglePlyChrSelectGC::get_global_state();
    if (w != NULL && i < 0xFD) {
        move_data((void *)((&w->buf[i])), (const void *)(&v), 4);
    }
}

int qst_op_turn_on_bgm_p2(void *p) { return TLobby__sub_802272B4(p); }

int qst_op_turn_off_bgm_p2(void* p) { return TLobby__sub_8022733C(p); }

void qst_op_nop_F8EF(void) {  }

void qst_op_call_image_data() {
    s32 size;
    u32 source_data;
    size = qst_args[0];
    source_data = ((int)((u32 (*)(void *))qst_label_address)((void *)((saddr) (u16) qst_args[1])));
    if (source_data != 0U) {
        prs_decompress_buffer((s32) source_data, resource_decompress_buffer);
        fn_80197FD0((void *)resource_decompress_buffer, size);
    }
}

void qst_op_animation_check(s32 slot_reg, s32 dst) {
    u8 *motion;
    motion = (u8 *)get_player_by_client_id((u16)qst_registers[(u8)slot_reg]);
    if (motion != NULL) {
        qst_registers[(u8)dst] = ((TObjMotion *)motion)->is_motion_held();
    }
}

void qst_op_set_eventflag16() {
    u32 i = (u32)qst_args[0];
    s16 v = qst_args[1];
    Ctx_801EB658 *w = (Ctx_801EB658 *)TAdSinglePlyChrSelectGC::get_global_state();
    if (w != NULL && i < 0xFF) {
        move_data((void *)((&w->buf[i])), (const void *)(&v), 2);
    }
}

void qst_op_get_pl_job(s32 reg) {
    u8 *player;
    player = (u8 *)get_player_by_client_id(qst_registers[(u8)reg]);
    if (player != NULL) {
        strncpy((char *)&quest_player_class_name_buffer.value, (const char *)(TLobby::get_class_type_name((int) (((TObjPlayer *)player)->class_flags))), 0xF);
        *(s8 *)((s8 *)(&quest_player_class_name_buffer.value) + 0xF) = 0;
        qst_registers[(u8)reg] = 1;
        return;
    }
    qst_registers[(u8)reg] = 0;
}

void qst_op_get_pl_name(s32 reg) {
    u8 *player;
    player = (u8 *)get_player_by_client_id(qst_registers[(u8)reg]);
    if (player != NULL) {
        strncpy((char *)&quest_player_name_buffer.value, (const char *)((TObjPlayer *)player)->get_name(), 0xF);
        *(s8 *)((s8 *)(&quest_player_name_buffer.value) + 0xF) = 0;
        qst_registers[(u8)reg] = 1;
        return;
    }
    qst_registers[(u8)reg] = 0;
}

void qst_op_set_trap_damage(s32 i) {
    s32 j = i + 1;
    TOMineTrap__sub_80171368((f32)qst_registers[(u8)i] + (f32)qst_registers[(u8)j] / (f32)qst_registers[(u8)++j]);
}

void qst_op_get_eventflag(s32 index_reg, s32 dst) {
    u8 *flags;
    s32 *regs;
    s32 index;
    flags = (u8 *)TAdSinglePlyChrSelectGC::get_global_state();
    if (flags != NULL) {
        regs = qst_registers;
        index = regs[(u8)index_reg];
        if (index >= 0 && index < 0x100) {
            regs[(u8)dst] = flags[index + 0x10];
        }
    }
}

void qst_op_get_serial_number(u8 reg) {
    qst_registers[reg] = TQuestVmDownLoadServer::get_serial_access();
    if (qst_registers[reg] == 0) {
        qst_registers[reg] = TQuestVmDownLoadServer::poll_serial_access();
    }
}
void qst_op_kill_player(s32 slot_reg) {
    if (get_player_by_client_id(qst_registers[(u8)slot_reg]) != NULL) {
        TObjPlayer__sub_801AF904();
    }
}

void qst_op_get_guild_card_file_creation_time(s32 reg) {
    u8 *state;
    state = (u8 *)(saddr)TAdSinglePlyChrSelectGC::get_state();
    if (state != NULL) {
        qst_registers[(u8)reg] = *(s32 *)((s8 *)state + 0xE284);
        return;
    }
    qst_registers[(u8)reg] = 0;
}

extern "C" {
}
void qst_op_take_slot_meseta(s32 regs, s32 dst) {
    TObjPlayer *player = get_player_by_client_id(qst_registers[(u8)regs++]);
    if (player != NULL) {
        if (try_spend_actor_meseta(player, qst_registers[(u8)regs]) != 0) {
            qst_registers[(u8)dst] = 1;
        } else {
            qst_registers[(u8)dst] = 0;
        }
    } else {
        qst_registers[(u8)((u8)dst + 1)] = 0;
    }
}

void qst_op_get_chara_class(s32 slot_reg, s32 dst) {
    TObjPlayer *player = get_player_by_client_id(qst_registers[(u8)slot_reg]);
    if (player != NULL) {
        s32 f = player->class_flags;
        if (f & CLASS_FLAG_HUMAN) {
            qst_registers[(u8)dst] = RACE_HUMAN;
        } else if (f & CLASS_FLAG_NEWMAN) {
            qst_registers[(u8)dst] = RACE_NEWMAN;
        } else if (f & CLASS_FLAG_ANDROID) {
            qst_registers[(u8)dst] = RACE_ANDROID;
        } else {
            qst_registers[(u8)dst] = RACE_NONE;
        }
        if (f & CLASS_FLAG_HUNTER) {
            qst_registers[(u8)(dst + 1)] = CLASS_TYPE_HUNTER;
        } else if (f & CLASS_FLAG_RANGER) {
            qst_registers[(u8)(dst + 1)] = CLASS_TYPE_RANGER;
        } else if (f & CLASS_FLAG_FORCE) {
            qst_registers[(u8)(dst + 1)] = CLASS_TYPE_FORCE;
        } else {
            qst_registers[(u8)(dst + 1)] = CLASS_TYPE_NONE;
        }
    } else {
        qst_registers[(u8)dst++] = RACE_NONE;
        qst_registers[(u8)dst] = CLASS_TYPE_NONE;
    }
}

void qst_op_get_gender(s32 slot_reg, s32 dst) {
    s32 class_flags;
    u8 *player;
    player = (u8 *)get_player_by_client_id(qst_registers[(u8)slot_reg]);
    if (player != NULL) {
        class_flags = ((TObjPlayer *)player)->class_flags;
        if (class_flags & CLASS_FLAG_MALE) {
            qst_registers[(u8)dst] = GENDER_MALE;
            return;
        }
        if (class_flags & CLASS_FLAG_FEMALE) {
            qst_registers[(u8)dst] = GENDER_FEMALE;
            return;
        }
        qst_registers[(u8)dst] = GENDER_NONE;
        return;
    }
    qst_registers[(u8)dst] = GENDER_NONE;
}

void qst_op_disable_techs(s32 slot_reg) {
    TObjPlayer *player = get_player_by_client_id(qst_registers[(u8)slot_reg]);
    if (player != NULL) {
        TLobby__sub_801F3694(&player->technique_state);
    }
}

void qst_op_enable_techs(s32 slot_reg) {
    TObjPlayer *player = get_player_by_client_id(qst_registers[(u8)slot_reg]);
    if (player != NULL) {
        TFontSmallLobby__sub_801C013C(&player->technique_state);
    }
}

void qst_op_disable_stealth_suit_effect(s32 slot_reg) {
    saddr player;
    player = ((saddr)((uaddr)get_player_by_client_id((int)(qst_registers[(u8)slot_reg]))));
    if ((player != 0) && (((TObjPlayer *)player)->sub_801A1DDC() != 0)) {
        draw_small_label__15TFontSmallLobbyFi((player));
    }
}

void qst_op_enable_stealth_suit_effect(s32 slot_reg) {
    saddr player;
    player = ((saddr)((uaddr)get_player_by_client_id((int)(qst_registers[(u8)slot_reg]))));
    if ((player != 0) && (((TObjPlayer *)player)->sub_801A1DDC() != 0)) {
        TLobby__sub_801B1254((player));
    }
}

void qst_op_set_cmode_rank_override(void) {
    char buf[0x200];
    TTokenList *fields;
    s32 arg = (u32)qst_args[0];
    char *src = *(char **)&qst_args[1];
    fields = new TTokenList(NULL, 0, 0);
    strncpy(buf, (const char *)src, 0x1FF);
    trim_whitespace(buf);
    fields->tokenize_args(buf);
    if (fields->count == 2) {
        if (is_split_screen() == 1) {
            TLobby__sub_80292268(fields->tokens[0], fields->tokens[1], arg);
        } else {
            add_entry__6TLobbyFiii(fields->tokens[0], fields->tokens[1], arg);
        }
    }
    delete fields;
}

void qst_op_dark_falz_is_dead(s32 reg) {
    if (TLobby::is_boss_phase_reached() != 0) {
        qst_registers[(u8)reg] = 1;
        return;
    }
    qst_registers[(u8)reg] = 0;
}

int qst_op_ba_clear_trapself(void) { return TOMineTrap::set_trap_count(0); }

int qst_op_ba_set_trapself() { return TOMineTrap::set_trap_count(1); }

void qst_op_award_item_ok(int a0) { qst_item_ok_window = (void *)TObjItemOKWindow::create((void*)tl_01); qst_registers[(unsigned char)(a0)] = 0; qst_result_register = a0; qst_suspend_reason = QST_WAIT_ITEM_OK; }

void qst_op_ba_set_box_drop_area(s32 reg) {
    TItemDropSub::create_instance((int) (qst_registers[(u8)reg]));
}

void qst_op_item_create_cmode(u8 regs, u8 dst) {
    Item_801EBF30 item;
    ((s32 (*)(void *))init__9TItemDataFv)((void *)(&item));
    item.data[0] = qst_registers[(u8)regs++];
    item.data[1] = qst_registers[(u8)regs++];
    item.data[2] = qst_registers[(u8)regs++];
    item.data[3] = qst_registers[(u8)regs++];
    item.data[4] = qst_registers[(u8)regs++];
    item.data[5] = qst_registers[(u8)regs];
    item.id = advance_item_id_counter(local_client_id);
    if (is_split_screen() == 1) {
        if (TLobby__sub_802924B4(&item, 0) != 0) {
            qst_registers[dst] = 1;
        } else {
            qst_registers[dst] = 0;
        }
    } else {
        if (TLobby__sub_800710D8(&item) != 0) {
            qst_registers[dst] = 1;
        } else {
            qst_registers[dst] = 0;
        }
    }
}

void qst_op_check_rank_time(u8 src, u8 dst) {
    s32 r;
    if (is_split_screen() == 1) {
        r = TLobby__sub_80292270(qst_registers[src], 0);
    } else {
        r = TLobby__sub_8007119C(qst_registers[src]);
    }
    switch (r) {
    case 2:
        qst_registers[dst] = 2;
        break;
    case 1:
        qst_registers[dst] = 1;
        break;
    case 0:
        qst_registers[dst] = 0;
        break;
    case -1:
        qst_registers[dst] = 3;
        break;
    case -2:
        qst_registers[dst] = 4;
        break;
    case -3:
        qst_registers[dst] = 5;
        break;
    case -4:
    default:
        qst_registers[dst] = 6;
        break;
    }
}

void qst_op_get_player_proximity(u8 regs, u8 dst) {
    s32 idx;
    f32 range;
    TObjPlayer *self;
    TObjPlayer *other;
    s32 field;
    s32 i;
    idx = qst_registers[regs++];
    range = qst_registers[regs];
    qst_registers[dst] = 0;
    self = get_player_by_client_id(idx);
    if (self != NULL) {
        field = self->get_floor();
        for (i = 0; i < 12; i++) {
            if (i != idx) {
                other = get_player_by_client_id(i);
                if (other != NULL && field == other->get_floor() &&
                    xyz_distance_squared(&self->position, &other->position) < range * range) {
                    qst_registers[dst]++;
                }
            }
        }
    }
}
extern "C" {

s32 TLobby__sub_800712D8(s32, s32, s32);
s32 TLobby__sub_802923C4(s32, s32, s32);
}
void qst_op_set_cmode_rank_threshold(u8 regs, u8 dst) {
    s32 a = qst_registers[(u8)regs++];
    s32 b = qst_registers[(u8)regs++];
    s32 c = qst_registers[(u8)regs];
    if (is_split_screen() == 1) {
        if (TLobby__sub_802923C4(a, b, c) != 0) {
            qst_registers[dst] = 1;
        } else {
            qst_registers[dst] = 0;
        }
    } else {
        if (TLobby__sub_800712D8(a, b, c) != 0) {
            qst_registers[dst] = 1;
        } else {
            qst_registers[dst] = 0;
        }
    }
}
extern "C" {
s32 TObjItemOKWindow__sub_801F3268(void);
void TItemData__sub_8010CA08(Item_801EBF30 *, saddr, s32);
}
void qst_op_award_item_give(u8 reg) {
    Item_801EBF30 item;
    u8 t = TObjItemNameSelect::get_selected_value();
    TItemData__sub_8010CA08(&item, TObjItemOKWindow__sub_801F3268(), t);
    if (is_split_screen() == 1) {
        if (TLobby__sub_802924B4(&item, 0) != 0) {
            qst_registers[reg] = 1;
        } else {
            qst_registers[reg] = 0;
        }
    } else {
        if (TLobby__sub_800710D8(&item) != 0) {
            qst_registers[reg] = 1;
        } else {
            qst_registers[reg] = 0;
        }
    }
}

void qst_op_award_item_select() { qst_item_name_select = (void *)TObjItemNameSelect::create((void*)tl_01); qst_suspend_reason = QST_WAIT_ITEM_NAME_SELECT; }

void qst_op_award_item_name() { qst_item_name_entry = (void *)TObjItemNameEntry::create((void *)tl_01); qst_suspend_reason = QST_WAIT_ITEM_NAME_ENTRY; }

void qst_op_set_cmode_rank_result(void) {
    s32 rank;
    u8 *lobby;
    rank = qst_args[0];
    lobby = (u8 *)(*(u8 **)&qst_args[1]);
    if (is_split_screen() == 1) {
        TLobby::set_encoded_name_and_color(lobby, rank);
        return;
    }
    ((TLobby *)lobby)->set_player_name_and_color(rank);
}

void qst_op_get_mag_levels(s32 i) {
    saddr r;
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        r = player->activate_d04_slot();
        if (r != 0) {
            qst_registers[(u8)i++] = ((TItemMag *)r)->get_def_level();
            qst_registers[(u8)i++] = ((TItemMag *)r)->get_pow_level();
            qst_registers[(u8)i++] = ((TItemMag *)r)->get_dex_level();
            qst_registers[(u8)i] = ((TItemMag *)r)->get_mind_level();
        }
    }
}

void qst_op_give_s_rank_weapon() {
    Item_801EBF30 item;
    u8 r = qst_args[1];
    s32 a = qst_args[2];
    u16 id = qst_args[0];
    if (id == local_client_id) {
        TObjPlayer *player = get_player_by_client_id(id);
        if (player != NULL) {
            TItemData__sub_8010CA08(&item, a, (u8)qst_registers[r]);
            if (((TItemData *)(&item))->isValidGroundDrop() == 1 && player->can_inventory_accept_item((u8 *)((Item_801EEE68 *)&item)) > 0) {
                player->request_inventory_item((TItemData*)((Item_801EEE68 *)&item));
            }
        }
    }
}

void qst_op_set_score_announce() {
    s32 i;
    s32 v = qst_args[0];
    for (i = 0; i < 8; i++) {
        if (battle_event_second_table[i] == 0) {
            battle_event_second_table[i] = v;
            return;
        }
    }
}

void qst_op_clear_score_announce() {
    s32 i;
    for (i = 0; i < 8; i++) {
        battle_event_second_table[i] = 0;
    }
}

void qst_op_ba_sonar_count(void) {
    battle_rules.sonar_count = (s8) qst_args[0];
}

void qst_op_ba_enable_sonar() {
    if ((u32)qst_args[0] <= 0x1U) {
        battle_rules.enable_sonar = (s8) enable_sonar_values[(u32)qst_args[0]];
    }
}

void qst_op_set_allow_item_flags(void) {
    TItemMenuCtrl::open_menu((int) (qst_args[0]));
}

void qst_op_p_talk_guild_local(int _w0, int _w1) {
    u32 player = ((uaddr)get_player_by_client_id((int)(local_client_id)));
    if (player != 0U) {
        TLobby::handle_main_phase(player);
    }
}

void qst_op_unequip_item() {
    TLobby::handle_player_event((int) ((u16) qst_args[0]), (int) (qst_args[1]));
}

void qst_op_equip_item(u8 i) {
    Item_801EC720 item;
    u16 id = qst_registers[i++];
    ((s32 (*)(void *))init__9TItemDataFv)(&item);
    item.a = qst_registers[i++];
    item.b = qst_registers[i++];
    item.c = qst_registers[i++];
    TLobby::forward_to_player(id, &item);
}

int qst_op_ba_hide_self_traps(void) { return TOMineTrap::set_instance(0); }

int qst_op_ba_show_self_traps(void) { return TOMineTrap::set_instance(1); }

void qst_op_set_area_title() {
    saddr lobby_addr;

    lobby_addr = qst_args[0];
    if (is_split_screen() == 1) {
        ((TLobby *)lobby_addr)->set_name_string();
        return;
    }
    ((TLobby *)lobby_addr)->set_name_string();
}

void qst_op_unset_ult_map(void) { TLobby::clear_quest_state(); }

int qst_op_set_ult_map(void* p) { return TLobby__sub_801F36BC(p); }

void qst_op_restore_warp_dest_floor(void) { TLobby::reset_quest_counter(); }

int qst_op_override_warp_dest_floor(void *p) { return TLobby__sub_801F36D8(p); }

void qst_op_set_current_area_number(void) {
    TLobby::set_lobby_id((int) (qst_args[0]));
}

void qst_op_set_area_total() {
    TLobby::set_global_805D3614((int) (qst_args[0]));
}

void qst_op_ba_set_meseta_drop_mode(void) {
    if ((u32)qst_args[0] <= 2U) {
        battle_rules.meseta_mode = (s8) meseta_mode_values[(u32)qst_args[0]];
    }
}

void qst_op_ba_death_lvl_up(void) {
    battle_rules.death_level_up = (s8) qst_args[0];
}

void qst_op_ba_set_time_limit(void) {
    u32 time_limit;
    time_limit = (u32)qst_args[0];
    if (time_limit > 0x278D0U) {
        time_limit = 0U;
    }
    battle_rules.time_limit = time_limit;
}

void qst_op_ba_set_char_level(void) {
    u32 char_level;
    char_level = (u32)qst_args[0];
    if (char_level > TObjPlayer::get_max_level()) {
        char_level = 0U;
    }
    battle_rules.char_level = char_level;
}

void qst_op_ba_set_max_tech_level() {
    u32 max_level;
    max_level = (u32)qst_args[0];
    if ((max_level != 0xFFU) && (max_level > 0x1DU)) {
        max_level = 0U;
    }
    battle_rules.max_tech_level = max_level;
}

void qst_op_ba_set_lives(void) {
    u32 lives;
    lives = (u32)qst_args[0];
    if (lives > 0x63U) {
        lives = 0U;
    }
    battle_rules.lives = lives;
}

void qst_op_ba_hide_target_reticle(void) {
    if ((u32)qst_args[0] <= 1U) {
        battle_rules.hide_target_reticle = (s8) (u32)qst_args[0];
    }
}

void qst_op_ba_set_trap_count(s32 reg) {
    s32 slot = qst_registers[(u8)reg++];
    s32 value = qst_registers[(u8)reg];
    if (slot >= 0 && slot <= 3) {
        battle_rules.trap_counts[trap_count_slots[slot]] = value;
    }
}

extern f32 lbl_805D5DC8;
void qst_op_ba_meseta_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    lbl_805D5DC8 = v;
}

extern f32 lbl_805D3550;
void qst_op_ba_enemy_death_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    lbl_805D3550 = v;
}

extern f32 lbl_805D354C;
void qst_op_ba_enemy_kill_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    lbl_805D354C = v;
}

void qst_op_ba_player_death_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    lbl_805D3544 = v;
}

void qst_op_ba_player_kill_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    lbl_805D3540 = v;
}

void qst_op_ba_enemy_take_damage_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    lbl_805D5DC4 = v;
}

void qst_op_ba_enemy_give_damage_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    lbl_805D3548 = v;
}

void qst_op_ba_player_take_damage_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    lbl_805D353C = v;
}

void qst_op_ba_player_give_damage_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    lbl_805D3538 = v;
}

void qst_op_set_cmode_base_time(s32 reg) {
    if (is_split_screen() == 1) {
        TLobby::update_challenge_timer((int) (qst_registers[(u8)reg]));
        return;
    }
    TLobby__sub_80071064((int) (qst_registers[(u8)reg]));
}

void qst_op_prepare_npc_visual(saddr label) {
    u32 record_addr;
    record_addr = ((u32 (*)(void *))qst_label_address)((void *)label);
    if (record_addr != 0U) {
        copy_player_visual_record((void *) (&quest_npc_visual_record.value), record_addr);
    }
}

void qst_op_enable_npc_visual(void *p) { enable_quest_npc_visual(); }

void qst_op_set_shrink_cam2(u8 regs) {
    Vec pos;
    TObjPlayer *player;
    Vec *cur;
    player = get_player_by_client_id(qst_registers[regs++]);
    if (player != NULL) {
        cur = player->scale_state.camera.target.get();
        if (cur != NULL) {
            pos.x = cur->x + (f32)qst_registers[regs++];
            pos.y = cur->y + (f32)qst_registers[regs++];
            pos.z = cur->z + (f32)qst_registers[regs];
            copy_position__6TLobbyFv(&player->scale_state.camera.target, &pos);
        }
    }
}

void qst_op_set_shrink_cam1(u8 regs) {
    Vec pos;
    TObjPlayer *player;
    Vec *cur;
    player = get_player_by_client_id(qst_registers[regs++]);
    if (player != NULL) {
        cur = player->scale_state.camera.position.get();
        if (cur != NULL) {
            pos.x = cur->x + (f32)qst_registers[regs++];
            pos.y = cur->y + (f32)qst_registers[regs++];
            pos.z = cur->z + (f32)qst_registers[regs];
            copy_position__6TLobbyFv(&player->scale_state.camera.position, &pos);
        }
    }
}

void qst_op_unshrink(s32 slot_reg) {
    saddr player;
    player = ((s32)((uaddr)get_player_by_client_id((int)(qst_registers[(u8)slot_reg]))));
    if ((player != 0) && (((TObjChara *)player)->obj_isState2_324() == 0)) {
        ((TObjPlayer *)player)->scale_state.request_size_restore();
    }
}

void qst_op_shrink(s32 slot_reg) {
    saddr player;
    player = ((s32)((uaddr)get_player_by_client_id((int)(qst_registers[(u8)slot_reg]))));
    if ((player != 0) && (((TObjChara *)player)->obj_isState2_324() == 0)) {
        ((TObjPlayer *)player)->scale_state.request_shrink();
    }
}

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma opt_dead_assignments off
void qst_op_read_switch_flag_on_floor(s32 reg) {
    s32 reg_offset;
    saddr switch_value;
    u8 *id;
    reg_offset = (reg * 4) & 0x3FC;
    switch_value = ((saddr)qst_registers);
    id = (u8 *)(switch_value + reg_offset);
    id = (u8 *)(*(u8 **)((s8 *)id + 4));
    switch_value = (s32) (s16) *(s32 *)((s8 *)switch_value + reg_offset);
    id = (u8 *)((void *)(uaddr) (u16)(uaddr)(void *) id);
    switch_value = (s32) is_floor_switch_set((uaddr)id, (switch_value));
    id = (u8 *)(((saddr)qst_registers) + reg_offset);
    *(s32 *)((s8 *)id + 8) = switch_value;
}
#pragma pop

void qst_op_read_switch_flag(s32 reg) {
    qst_registers[(u8)reg + 1] = is_current_floor_switch_set((u16)qst_registers[(u8)reg]);
}

void qst_op_clear_switch_flag_sync() {
    Pkt_801ED300 pkt;
    s32 x = qst_args[0];
    s32 y = qst_args[1];
    ((G_SwitchStateChanged_6x05 *)(&pkt))->init();
    pkt.a = 0xFFFF;
    pkt.b = 0;
    pkt.c = y;
    pkt.d = x;
    pkt.e = 0;
    ((G_SwitchStateChanged_6x05 *)(&pkt))->send();
}

void qst_op_set_switch_flag_sync() {
    Pkt_801ED360 pkt;
    s32 x = qst_args[0];
    s32 y = qst_args[1];
    ((G_SwitchStateChanged_6x05 *)(&pkt))->init();
    pkt.a = 0xFFFF;
    pkt.b = 0;
    pkt.c = y;
    pkt.d = x;
    pkt.e = 1;
    ((G_SwitchStateChanged_6x05 *)(&pkt))->send();
}

void qst_op_reset_kills(s32 slot_reg) {
    u8 *lobby;
    lobby = (u8 *)(((u8 *)((uaddr)get_player_by_client_id((int)(qst_registers[(u8)slot_reg])))));
    if (lobby != NULL) {
        ((TLobby *)lobby)->set_floor(0);
    }
}

void qst_op_get_num_kills(s32 slot_reg, s32 dst) {
    u8 *player;
    player = (u8 *)(((saddr)((uaddr)get_player_by_client_id((int)(qst_registers[(u8)slot_reg])))));
    if (player != NULL) {
        qst_registers[(u8)dst] = (s32) ((TObjPlayer *)player)->get_kill_count();
        return;
    }
    qst_registers[(u8)dst] = 0;
}

void qst_op_go_floor(s32 a, s32 b) {
    TObjPlayer *player = get_player_by_client_id(qst_registers[(u8)a]);
    if (player != NULL && local_client_id == qst_registers[(u8)a]) {
        floor_transition_state.set_next_floor(qst_registers[(u8)b], get_floor_map_terrain(qst_registers[(u8)b]));
        mark_area_change_pending();
        send_inter_level_warp_all(floor_transition_state.get_next_floor());
        send_6x21_inter_level_warp(player, floor_transition_state.get_next_floor());
    }
}

void qst_op_release_dragon(void* p) { TBoss1Dragon::clearControlOverride(); }

void qst_op_control_dragon(s32 reg) {
    setControlOverride__12TBoss1DragonFs((int) ((u16) qst_registers[(u8)reg]), qst_registers);
}

void qst_op_cmode_check_any_player_dead(s32 reg) {
    if (is_split_screen() == 1) {
        qst_registers[(u8)reg] = TLobby__sub_8029299C();
        return;
    }
    qst_registers[(u8)reg] = TLobby__sub_80070F4C();
}

void qst_op_cmode_check_all_players_dead(s32 reg) {
    if (is_split_screen() == 1) {
        qst_registers[(u8)reg] = TLobby__sub_80292A34();
        return;
    }
    qst_registers[(u8)reg] = TLobby__sub_80070FD8();
}

void qst_op_exp_multiplication(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    if (is_split_screen() == 1) {
        TLobby::set_camera_height_if_valid(v);
        return;
    }
    TLobby::try_set_value(v);
}

void qst_op_set_cmode_difficulty() {
    s32 difficulty;

    difficulty = qst_args[0];
    if (is_split_screen() == 1) {
        TLobby::try_set_split_screen(difficulty);
        return;
    }
    TLobby::set_split_screen_flag(difficulty);
}

void qst_op_set_cmode_char_template() {
    s32 stage;

    stage = qst_args[0];
    if (is_split_screen() == 1) {
        TLobby::rebuild_players_for_stage(stage);
        return;
    }
    TObjPlayer::rebuild_players_for_stage(stage);
}

void qst_op_nop_F822(s32 reg) {
    if (is_split_screen() == 1) {
        TLobby__sub_801F3700((int) (qst_registers[(u8)reg]));
        return;
    }
    TLobby__sub_801F36F0((int) (qst_registers[(u8)reg]));
}

void qst_op_nop_F821(u8 regs) {
    Item_801ED7BC item;
    s32 a;
    s32 b;
    s32 c;
    a = qst_registers[(u8)regs++];
    b = qst_registers[(u8)regs++];
    c = qst_registers[(u8)regs++];
    ((void (*)(Item_801ED7BC *))init__9TItemDataFv)(&item);
    item.data[0] = qst_registers[(u8)regs++];
    item.data[1] = qst_registers[(u8)regs++];
    item.data[2] = qst_registers[(u8)regs++];
    item.data[3] = qst_registers[(u8)regs++];
    item.data[4] = qst_registers[(u8)regs++];
    item.data[5] = qst_registers[(u8)regs];
    item.id = advance_item_id_counter(local_client_id);
    if (is_split_screen() == 1) {
        TLobby__sub_801F3708(a, b, c, &item);
    } else {
        TLobby__sub_801F36F8(a, b, c, &item);
    }
}

void qst_op_cmode_stage() {
    u32 temp_r30;
    u32 layout_id;

    temp_r30 = (u32)qst_args[0];
    layout_id = TWindowSubStatusDisp::get_layout_id(-1);
    if (is_split_screen() == 1) {
        if (temp_r30 < layout_id) {
            TLobby::clamp_and_store_layout_index(temp_r30);
            return;
        }
        TLobby::clamp_and_store_layout_index(0U);
        return;
    }
    if (temp_r30 < layout_id) {
        TLobby::set_selected_layout(temp_r30);
        return;
    }
    TLobby::set_selected_layout(0U);
}

void qst_op_ba_start(void) {
    s32 src;
    src = qst_args[0];
    if (TRaderMapCore::is_not_split_screen() == 1) {
        TPlayerBattleCtrl4P::init_instance_with_text((saddr)&battle_rules, src);
        return;
    }
    TLobby::init_battle_ctrl((saddr)&battle_rules, src);
}

void qst_op_ba_teams() {
    if ((u32)qst_args[0] <= 0x1U) {
        battle_rules.is_teams = (s8) teams_values[(u32)qst_args[0]];
        return;
    }
    battle_rules.is_teams = (s8) teams_values[0];
}

void qst_op_ba_dropwep() {
    if ((u32)qst_args[0] <= 0x1U) {
        battle_rules.drop_weapon = (s8) drop_weapon_values[(u32)qst_args[0]];
        return;
    }
    battle_rules.drop_weapon = (s8) drop_weapon_values[0];
}

void qst_op_ba_set_replace_char() {
    if ((u32)qst_args[0] <= 0x1U) {
        battle_rules.replace_char = (s8) replace_char_values[(u32)qst_args[0]];
        return;
    }
    battle_rules.replace_char = (s8) replace_char_values[1];
}

void qst_op_ba_set_respawn(void) {
    if ((u32)qst_args[0] <= 2U) {
        battle_rules.respawn_mode = (s8) respawn_mode_values[(u32)qst_args[0]];
        return;
    }
    battle_rules.respawn_mode = (s8) respawn_mode_values[2];
}

void qst_op_ba_set_unused_F817(void) {
    if ((u32)qst_args[0] <= 0x1U) {
        battle_rules.unused_F817 = (s8) unused_F817_values[(u32)qst_args[0]];
        return;
    }
    battle_rules.unused_F817 = (s8) unused_F817_values[0];
}

void qst_op_ba_set_trap_mode(void) {
    if ((u32)qst_args[0] <= 0x1U) {
        battle_rules.trap_mode = (s8) trap_mode_values[(u32)qst_args[0]];
        return;
    }
    battle_rules.trap_mode = (s8) trap_mode_values[0];
}

void qst_op_ba_set_tool_mode(void) {
    if ((u32)qst_args[0] <= 2U) {
        battle_rules.tool_mode = (s8) tool_mode_values[(u32)qst_args[0]];
        return;
    }
    battle_rules.tool_mode = (s8) tool_mode_values[0];
}

void qst_op_ba_set_forbid_mags() {
    if ((u32)qst_args[0] <= 0x1U) {
        battle_rules.mag_mode = (s8) mag_mode_values[(u32)qst_args[0]];
        return;
    }
    battle_rules.mag_mode = (s8) mag_mode_values[0];
}

void qst_op_ba_set_weapon_and_armor_mode() {
    if ((u32)qst_args[0] <= 3U) {
        battle_rules.weapon_and_armor_mode = (s8) lobby_menu_byte_1_map[(u32)qst_args[0]];
        return;
    }
    battle_rules.weapon_and_armor_mode = (s8) lobby_menu_byte_1_map[0];
}

void qst_op_ba_set_tech_disk_mode() {
    s8 tech_disk_mode;
    if ((u32)qst_args[0] <= 2U) {
        tech_disk_mode = (s8) tech_disk_mode_values[(u32)qst_args[0]];
    } else {
        tech_disk_mode = (s8) tech_disk_mode_values[2];
    }
    battle_rules.tech_disk_mode = tech_disk_mode;
}

void qst_op_clear_ba_rules() {
    memset(&battle_rules, 0, sizeof(BattleRules));
}

void qst_op_ba_initial_floor(void) {
    Tbl_801EDC98 t = lobby_sub_801edc98_id_table;
    if ((u32)qst_args[0] <= 0x11U) {
        initialize_floor_transition(&floor_transition_state, t.w[(u32)qst_args[0]], 0);
    }
}

void qst_op_enable_weapon_drop(int _w0, int _w1) {
    u32 pl = ((uaddr)get_player_by_client_id((int)(qst_args[0])));
    if (pl != 0U) {
        TLobby::send_field1c_packet((s32)pl);
    }
}

void qst_op_disable_weapon_drop(int _w0, int _w1) {
    u32 pl = ((uaddr)get_player_by_client_id((int)(qst_args[0])));
    if (pl != 0U) {
        TLobby::send_font_state((s32)pl);
    }
}

void qst_op_map_designate_ex(u32 first) {
    u32 i = first;
    s32 a = qst_registers[(u8)i++];
    s32 b = qst_registers[(u8)i++];
    s16 c = qst_registers[(u8)i++];
    s32 d = qst_registers[(u8)i++];
    s32 e = qst_registers[(u8)i];
    set_quest_floor_designation_ex(c, a, b, d, e);
}

void qst_op_disable_map(void) { TRaderMapCore::set_mode(0); }

void qst_op_enable_map(void) { TRaderMapCore::set_mode(1); }

void qst_op_get_coord_of_player(s32 a, s32 b) {
    uaddr player = ((uaddr)get_player_by_client_id((int)(qst_registers[(u8)b])));
    if (player != 0) {
        f32 *p = (f32 *)((TObjPlayer *)player)->get_position_ptr();
        if (p != NULL) {
            qst_registers[(u8)a++] = (s32)p[0];
            qst_registers[(u8)a++] = (s32)p[1];
            qst_registers[(u8)a] = (s32)p[2];
        }
    }
}

void qst_op_get_number_of_players(int a0) { qst_registers[(unsigned char)(a0)] = TLobby::count_members(); }

void qst_op_get_difficulty_level_v2(s32 reg) {
    s32 difficulty;
    difficulty = game_difficulty_selection;
    if (difficulty < 0) {
        difficulty = 0;
    }
    if (difficulty > 3) {
        difficulty = 3;
    }
    qst_registers[(u8)reg] = difficulty;
}

void qst_op_create_bgmctrl() {
    new TQuestBgmCtrl(tl_05);
}

void qst_op_update_switch_flag(s32 regs) {
    Pkt_801EDF64 pkt;
    ((G_SwitchStateChanged_6x05 *)(&pkt))->init();
    pkt.b = 0;
    pkt.a = 0xFFFF;
    pkt.c = qst_registers[(u8)regs++];
    pkt.d = qst_registers[(u8)regs++];
    pkt.e = qst_registers[(u8)regs];
    ((G_SwitchStateChanged_6x05 *)(&pkt))->send();
}

void qst_op_get_leader_id(u8 reg) {
    qst_registers[reg] = designated_client_id;
}

void qst_op_get_client_id(u8 reg) {
    qst_registers[reg] = local_client_id;
}

int qst_op_warp_off(void *p) { return TLobby__sub_801F36E4(p); }

void qst_op_warp_on(void) { TLobby::set_cleanup_flag(); }

void qst_op_start_setevt() {
    G_FloorEvent_6x67 pkt;
    s32 x = qst_args[0];
    s32 y = qst_args[1];
    pkt.init();
    pkt.floor = x;
    pkt.header.client_id = 0;
    pkt.event_id = y;
    pkt.sender_client_id = 0;
    pkt.send();
}

void qst_op_pad_dragon(void* p) { TBoss1Dragon::requestActionRefresh(); }

void qst_op_delete_bank_item(u8 regs, u8 dst) {
    Item_801EE0BC item;
    ((void (*)(Item_801EE0BC *))init__9TItemDataFv)(&item);
    item.data[0] = qst_registers[(u8)regs++];
    item.data[1] = qst_registers[(u8)regs++];
    item.data[2] = qst_registers[(u8)regs++];
    item.data[3] = qst_registers[(u8)regs++];
    item.data[4] = qst_registers[(u8)regs++];
    item.data[5] = qst_registers[(u8)regs];
    if (TCheckRoomSequence__delete_bank_item((u8 *)&item, 0) != 0) {
        qst_registers[dst] = 1;
    } else {
        qst_registers[dst] = 0;
    }
}

void qst_op_set_returncity() {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        player->stop_battle();
    }
}

void qst_op_set_returnhunter() {
    if (get_player_by_client_id(local_client_id) != NULL) {
        player_flag_1__6TLobbyFv();
    }
}

void qst_op_default_camera_pos1() {
    TObjPlayer *player;
    TCameraCtrl::reset_battle_camera();
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        reset_cameras_to_actor(player, 0);
    }
}

void qst_op_leti_fixed_camera(u8 regs) {
    Vec eye;
    Vec at;

    eye.x = qst_registers[(u8)regs++];
    eye.y = qst_registers[(u8)regs++];
    eye.z = qst_registers[(u8)regs++];
    at.x = qst_registers[(u8)regs++];
    at.y = qst_registers[(u8)regs++];
    at.z = qst_registers[(u8)regs];
    set_fixed_camera(&eye, &at);
}

void qst_op_sync_register(void) {
    Pkt_801EE330 pkt;
    build_6x77_sync_quest_register(&pkt);
    pkt.a = qst_args[0];
    pkt.b = qst_args[1];
    ((TLobby *)(&pkt))->sync_quest_register_and_send();
}

void qst_op_set_eventflag2(void) {
    u32 x = (u32)qst_args[0];
    u32 y = (u32)qst_args[1];
    u8* s = TAdSinglePlyChrSelectGC::get_global_state();
    if (s != 0 && x < 0x100) {
        s[x + 0x10] = y;
    }
}

void qst_op_set_eventflag(void) {
    u32 x = (u32)qst_args[0];
    u32 y = (u32)qst_args[1];
    u8* s = TAdSinglePlyChrSelectGC::get_global_state();
    if (s != 0 && x < 0x100) {
        s[x + 0x10] = y;
    }
}

void qst_op_end_battlebgm() {
    TObjPlayer *player;

    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        TObjPlayer__sub_801B3FD8();
        player->forward_1BF500_at_63c();
    }
}

void qst_op_start_battlebgm() {
    TObjPlayer *player;

    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        TObjPlayer__sub_801B4044();
        player->attach_battle_ctrl_sub();
    }
}

void qst_op_disable_mainmenu(void) { TWindowCtrl::disable_client_main_menu(local_client_id); }

void qst_op_enable_mainmenu() { TWindowCtrl::enable_client_main_menu(local_client_id); }

void qst_op_nop_BC(void) {  }

int qst_op_clr_qt_exit(void) { return set_quest_exit_callback((void*)(-1)); }

void qst_op_set_qt_exit(u16 label) {
    set_quest_exit_callback((void *)(uaddr)label);
}

void qst_op_get_difficulty_level_v1(s32 reg) {
    s32 difficulty;
    difficulty = game_difficulty_selection;
    if (difficulty < 0) {
        difficulty = 0;
    }
    if (difficulty > 2) {
        difficulty = 2;
    }
    qst_registers[(u8)reg] = difficulty;
}

void qst_op_setevt(void) {
    G_FloorEvent_6x67 pkt;
    s32 x = qst_args[0];
    pkt.init();
    pkt.header.client_id = 0;
    pkt.floor = get_current_floor();
    pkt.event_id = x;
    pkt.sender_client_id = 0;
    pkt.send();
}

void qst_op_clear_quest_board_handler(void) {
    if ((u32)qst_args[0] <= 5U) {
        memset((void *) ((u8 *)&quest_board_handlers + ((u32)qst_args[0] * 0x24)), 0, 0x24);
    }
}

void qst_op_set_quest_board_handler(void) {
    s32 i = qst_args[0];
    s32 v = qst_args[1];
    s32 n = qst_args[2];
    if (i <= 5) {
        Ent_801EE5EC* e = &((Ent_801EE5EC *)&quest_board_handlers)[i];
        e->v = v;
        ((void* (*)(void*, s32, s32))strncpy)(e, n, 0x20);
    }
}

void qst_op_getmtime(int a0) { qst_registers[(unsigned char)(a0)] = TLobby__sub_803DF1CC(); }

void qst_op_winset_time(s32 reg) {
    TWindowCtrl::set_timer_window_time(qst_registers[(u8)reg]);
}

void qst_op_winend_time(void* p) { TWindowCtrl::close_timer_window(); }

void qst_op_show_timer(void *p) { TWindowCtrl::create_alt_timer(); }

void qst_op_masterkey_off() { TLobby::reset_door_state(); TObjDoor::reset_instance(); }

void qst_op_masterkey_on() { TObjDoor__sub_801F3760(); TObjDoor__sub_801F3754(); }

void qst_op_map_designate(u32 first) {
    u32 i = first;
    s32 floor = qst_registers[(u8)i++];
    s16 mode = qst_registers[(u8)i++];
    s32 terrain = qst_registers[(u8)i++];
    s32 extra = qst_registers[(u8)i];
    set_quest_floor_designation(mode, floor, terrain, extra);
}

void qst_op_find_inventory_item_ex(u8 regs, u8 dst) {
    Item_801EE77C item;
    Player_801EE77C *player;
    void *obj;
    player = (Player_801EE77C *)get_player_by_client_id(local_client_id);
    if (player != NULL) {
        ((TItemData *)(&item))->init();
        item.data[0] = qst_registers[(u8)regs++];
        item.data[1] = qst_registers[(u8)regs++];
        item.data[2] = qst_registers[(u8)regs++];
        item.data[4] = qst_registers[(u8)regs];
        obj = ((TPlyItem *)((void *)player->fD00))->set_mode_and_refresh_object(&item);
        if (obj != NULL) {
            obj = (void *)((TItemList *)obj)->get_owner_if_alive();
            if (obj != NULL) {
                qst_registers[dst] = ((TItem *)obj)->get_item_id();
            } else {
                qst_registers[dst] = -1;
            }
        } else {
            qst_registers[dst] = -1;
        }
    } else {
        qst_registers[dst] = -1;
    }
}

void qst_op_item_check(u32 first, u32 destination) {
    Item_801EE77C item;
    TObjPlayer *player;
    void *slot;
    void *owner;
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        ((TItemData *)(&item))->init();
        item.data[0] = qst_registers[(u8)first++];
        item.data[1] = qst_registers[(u8)first++];
        item.data[2] = qst_registers[(u8)first];
        slot = ((TPlyItem *)(*(void **)((s8 *)player + 0xD00)))->set_mode_and_refresh_object(&item);
        if (slot != 0) {
            owner = (void *)((TItemList *)slot)->get_owner_if_alive();
            if (owner != 0) {
                qst_registers[(u8) destination] = ((TItem *)owner)->get_item_id();
                return;
            }
            qst_registers[(u8) destination] = -1;
            return;
        }
        qst_registers[(u8) destination] = -1;
        return;
    }
    qst_registers[(u8) destination] = -1;
}

void qst_op_item_delete2(u32 src, u32 dst) {
    Item_801EE77C item;
    TObjPlayer *player;
    void *slot;
    void *owner;
    if ((u8)dst > 0xF4) {
        return;
    }
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        ((TItemData *)(&item))->init();
        item.data[0] = qst_registers[(u8)src++];
        item.data[1] = qst_registers[(u8)src++];
        item.data[2] = qst_registers[(u8)src];
        slot = ((TPlyItem *)(*(void **)((s8 *)player + 0xD00)))->set_mode_and_refresh_object(&item);
        if (slot != 0) {
            owner = (void *)((TItemList *)slot)->get_owner_if_alive();
            if (owner != 0) {
                ((TItem *)owner)->copy_to_item_data((TItemData *)&item);
                qst_registers[(u8)dst++] = item.data[0];
                qst_registers[(u8)dst++] = item.data[1];
                qst_registers[(u8)dst++] = item.data[2];
                qst_registers[(u8)dst++] = item.data[3];
                qst_registers[(u8)dst++] = item.data[4];
                qst_registers[(u8)dst++] = item.data[5];
                qst_registers[(u8)dst++] = item.data[6];
                qst_registers[(u8)dst++] = (s8)item.data[7];
                qst_registers[(u8)dst++] = item.data[8];
                qst_registers[(u8)dst++] = (s8)item.data[9];
                qst_registers[(u8)dst++] = item.data[10];
                qst_registers[(u8)dst] = (s8)item.data[11];
                delete_item((void *)player, item.id, 1);
                return;
            }
            qst_registers[(u8)dst] = -1;
            return;
        }
        qst_registers[(u8)dst] = -1;
        return;
    }
    qst_registers[(u8)dst] = -1;
}

void qst_op_item_delete(u32 src, u32 dst) {
    Item_801EE77C item;
    TObjPlayer *player;
    void *slot;
    void *owner;
    if ((u8)dst > 0xF4) {
        return;
    }
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        slot = ((TPlyItem *)(*(void **)((s8 *)player + 0xD00)))->start_inventory_update(qst_registers[(u8)src]);
        if (slot != 0) {
            owner = (void *)((TItemList *)slot)->get_owner_if_alive();
            if (owner != 0) {
                ((TItem *)owner)->copy_to_item_data((TItemData *)&item);
                qst_registers[(u8)dst++] = item.data[0];
                qst_registers[(u8)dst++] = item.data[1];
                qst_registers[(u8)dst++] = item.data[2];
                qst_registers[(u8)dst++] = item.data[3];
                qst_registers[(u8)dst++] = item.data[4];
                qst_registers[(u8)dst++] = item.data[5];
                qst_registers[(u8)dst++] = item.data[6];
                qst_registers[(u8)dst++] = (s8)item.data[7];
                qst_registers[(u8)dst++] = item.data[8];
                qst_registers[(u8)dst++] = (s8)item.data[9];
                qst_registers[(u8)dst++] = item.data[10];
                qst_registers[(u8)dst] = (s8)item.data[11];
                delete_item((void *)player, qst_registers[(u8)src], 1);
                return;
            }
            qst_registers[(u8)dst] = -1;
            return;
        }
        qst_registers[(u8)dst] = -1;
        return;
    }
    qst_registers[(u8)dst] = -1;
}

void qst_op_item_create2(u8 regs, u8 dst) {
    Item_801EEE68 item;
    void *player;
    player = (void *)get_player_by_client_id(local_client_id);
    if (player != NULL) {
        ((TItemData *)((Item_801EE77C *)(&item)))->init();
        item.data[0] = qst_registers[regs++];
        item.data[1] = qst_registers[regs++];
        item.data[2] = qst_registers[regs++];
        item.data[3] = qst_registers[regs++];
        item.data[4] = qst_registers[regs++];
        item.data[5] = qst_registers[regs++];
        item.id = advance_item_id_counter(local_client_id);
        item.data[6] = qst_registers[regs++];
        item.data[7] = qst_registers[regs++];
        item.data[8] = qst_registers[regs++];
        item.data[9] = qst_registers[regs++];
        item.data[10] = qst_registers[regs++];
        item.data[11] = qst_registers[regs];
        if (((TObjPlayer *)player)->can_inventory_accept_item((u8 *)(&item)) > 0) {
            ((TObjPlayer *)player)->request_inventory_item((TItemData*)(&item));
            qst_registers[dst] = item.id;
        } else {
            qst_registers[dst] = -1;
        }
    } else {
        qst_registers[dst] = -1;
    }
}

void qst_op_item_create(u8 regs, u8 dst) {
    Item_801EEE68 item;
    void *player;
    player = (void *)get_player_by_client_id(local_client_id);
    if (player != NULL) {
        ((TItemData *)((Item_801EE77C *)(&item)))->init();
        item.data[0] = qst_registers[(u8)regs++];
        item.data[1] = qst_registers[(u8)regs++];
        item.data[2] = qst_registers[(u8)regs];
        item.id = advance_item_id_counter(local_client_id);
        if (((TObjPlayer *)player)->can_inventory_accept_item((u8 *)(&item)) > 0) {
            ((TObjPlayer *)player)->request_inventory_item((TItemData*)(&item));
            qst_registers[dst] = item.id;
        } else {
            qst_registers[dst] = -1;
        }
    } else {
        qst_registers[dst] = -1;
    }
}

void qst_op_del_obj_param(s32 reg) {
    TQuestColCtrl::delete_by_param(qst_registers[(u8)reg]);
}

void qst_op_pl_add_meseta2() {
    s32 amount;
    TObjPlayer *player;

    amount = qst_args[0];
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        player->add_meseta(amount);
    }
}

void qst_op_pl_add_meseta(void) {
    s32 amount;
    TObjPlayer *player;
    amount = qst_args[1];
    player = get_player_by_client_id(qst_args[0]);
    if (player != NULL) {
        player->add_meseta(amount);
    }
}

int qst_op_clr_qt_cancel(void) { return set_quest_cancel_callback((void*)(-1)); }

int qst_op_clr_qt_success(void) { return set_quest_success_callback((void*)(-1)); }

int qst_op_clr_qt_failure(void) { return THunterGuildSeqOffline__sub_801F3748((void*)(-1)); }

void qst_op_set_qt_cancel(u16 label) {
    set_quest_cancel_callback((void *)(uaddr)label);
}

void qst_op_set_qt_success(u16 label) {
    set_quest_success_callback((void *)(uaddr)label);
}

void qst_op_set_qt_failure(u16 label) {
    THunterGuildSeqOffline__sub_801F3748((void *)(uaddr)label);
}

void qst_op_clr_floor_handler(void) {
    TQuestThread::clear_floor_handler(qst_args[0]);
}

void qst_op_set_floor_handler(void) {
    TQuestThread::set_floor_handler(qst_args[0], (u16)qst_args[1]);
}

void qst_op_pcam_param(u8 regs) {
    s32 i = regs;
    Vec a;
    Vec b;

    a.x = qst_registers[i++];
    a.y = qst_registers[i++];
    a.z = qst_registers[i++];
    b.x = qst_registers[i++];
    b.y = qst_registers[i++];
    b.z = qst_registers[i];
    request_follow_camera_offsets(&a, &b, 0xFFFF);
}

int qst_op_clear_mainwarp_all(void* p) { return clear_enabled_main_warps(p); }

void qst_op_clear_mainwarp() {
    TObjCityMainWarp::clear_active_bit(qst_args[0]);
}

void qst_op_set_mainwarp(void) {
    s32 main_warp_id;
    main_warp_id = qst_args[0];
    TObjCityMainWarp::set_active_bit((int) (qst_args[0]));
    TObjDoor::set_main_warp_id(main_warp_id);
}

void qst_op_set_bgm() {
    TQuestBgmCtrl::force_bgm((int) (qst_args[0]));
}

void qst_op_playbgm_epi(void) {
    TQuestBgmCtrl::defer_bgm((int) (qst_args[0]));
}

void qst_op_switch_off(void) {
    clear_current_floor_switch(((u16) qst_args[0]));
}

void qst_op_switch_on(void) {
    set_current_floor_switch(((u16) qst_args[0]));
}

void qst_op_npc_talk_kill(void) {
    set_npc_proximity_target_id((qst_args[0]));
}
void qst_op_npc_talk_pl(u8 regs) {
    s32 i;
    ObjectSetData set;

    TLobby__sub_80207F30(&set);
    i = regs;
    set.position.x = qst_registers[i++];
    set.position.y = qst_registers[i++];
    set.position.z = qst_registers[i++];
    set.scale.x = qst_registers[i++];
    set.rotation[1] = 182.04445f * qst_registers[i++];
    set.set_params[0] = qst_registers[i++];
    set.set_params[1] = qst_registers[i++];
    set.set_params[2] = qst_registers[i];
    TLobby::create_npc(&set);
}

void qst_op_p_talk_guild(void) {
    TObjPlayer *player = get_player_by_client_id(qst_args[0]);
    if (player != NULL) {
        TLobby::handle_main_phase((saddr)player);
    }
}

void qst_op_p_return_guild(void) {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        prepare_guild_return__10TObjPlayerFPv(player, 0);
    }
}

void qst_op_npc_text_clear_all() { clear_partner_dialogue_flags(); }

void qst_op_load_midi() { TLobby::free_luker_object(); TLobby__sub_80197F74(); TLobby::clear_quest_vm_flag(); }

void qst_op_load_pvr() { TLobby::free_luker_object(); load_memcard_file(); TLobby::clear_quest_vm_flag(); }

void qst_op_npc_text() {
    set_partner_common_remark((qst_args[0]), (const char *)(qst_args[1]));
}

void qst_op_nop_A0_debug(void) {
    char buf[0x200];
    TTokenList *fields;
    void *s = *(void **)&qst_args[1];
    fields = new TTokenList(NULL, 0, 0);
    buf[0x1FF] = 0;
    ((void (*)(void *, void *, int))strncpy)(buf, s, 0x1FF);
    trim_whitespace(buf);
    fields->parse_csv_line(buf);
    if (fields->count != 2) {
        while (1) {}
    }
    delete fields;
}
void qst_op_cine_disable(void) { TCineCtrl::begin_letterbox_hide(NULL); }

void qst_op_cine_enable(void) { TCineCtrl::begin_letterbox_show(NULL); }

void qst_op_hud_show(void) { TWindowCtrl::unsuppress_slot(local_client_id); TRaderMapCore::show_radar(); }

void qst_op_hud_hide(void) { TWindowCtrl::suppress_slot(local_client_id); TRaderMapCore::hide_radar(); }
void qst_op_pl_pkon(void *p) { enable_pk_mode_for_all_players(); }

void qst_op_pl_pkoff(void *p) { disable_pk_mode_for_all_players(); }

void qst_op_npc_chkwarp() { fn_8019608C(); }

void qst_op_check_npc_straggle(u8 i) {
    u8 start = i;
    Vec v;
    ObjectSetData s;
    TObjQuestColApcINW *obj;

    TLobby__sub_80207F30(&s);
    s.position.x = qst_registers[i++];
    s.position.y = qst_registers[i++];
    s.position.z = qst_registers[i++];
    s.scale.x = qst_registers[i++];
    s.set_params[0] = qst_registers[i++];
    s.scale.y = qst_registers[i++];
    obj = create_quest_col_apc_inw__6TLobbyFPvPv(&s, &qst_registers[start]);
    if (obj != NULL) {
        v.x = qst_registers[i++];
        v.y = qst_registers[i++];
        v.z = qst_registers[i];
        TLobby__sub_801F3500(obj, &v);
    }
}

void qst_op_set_obj_param(u8 regs, u8 reg) {
    ObjectSetData set;

    TLobby__sub_80207F30(&set);
    set.position.x = qst_registers[(u8)regs++];
    set.position.y = qst_registers[(u8)regs++];
    set.position.z = qst_registers[(u8)regs++];
    set.scale.x = qst_registers[(u8)regs++];
    set.set_params[0] = qst_registers[(u8)regs++];
    set.scale.y = qst_registers[(u8)regs];
    create_quest_col_alock(&set, &qst_registers[reg]);
}

void qst_op_col_npcinr(u8 regs) {
    ObjectSetData set;
    u8 first;

    TLobby__sub_80207F30(&set);
    first = regs;
    set.position.x = qst_registers[(u8)regs++];
    set.position.y = qst_registers[(u8)regs++];
    set.position.z = qst_registers[(u8)regs++];
    set.scale.x = qst_registers[(u8)regs++];
    set.scale.y = qst_registers[(u8)regs++];
    set.set_params[0] = qst_registers[(u8)regs];
    fn_80196214(&set, &qst_registers[first]);
}

void qst_op_npc_coords_call(u8 regs) {
    ObjectSetData set;
    u8 first;

    TLobby__sub_80207F30(&set);
    first = regs;
    set.position.x = qst_registers[(u8)regs++];
    set.position.y = qst_registers[(u8)regs++];
    set.position.z = qst_registers[(u8)regs++];
    set.scale.x = qst_registers[(u8)regs++];
    set.set_params[0] = qst_registers[(u8)regs];
    fn_801963A8(&set, &qst_registers[first]);
}

void qst_op_at_coords_talk(u8 regs) {
    ObjectSetData set;
    u8 first;

    TLobby__sub_80207F30(&set);
    first = regs;
    set.position.x = qst_registers[(u8)regs++];
    set.position.y = qst_registers[(u8)regs++];
    set.position.z = qst_registers[(u8)regs++];
    set.scale.x = qst_registers[(u8)regs++];
    set.set_params[0] = qst_registers[(u8)regs];
    fn_80196814(&set, &qst_registers[first]);
}

void qst_op_at_coords_call(u8 regs) {
    ObjectSetData set;
    u8 first;

    TLobby__sub_80207F30(&set);
    first = regs;
    set.position.x = qst_registers[(u8)regs++];
    set.position.y = qst_registers[(u8)regs++];
    set.position.z = qst_registers[(u8)regs++];
    set.scale.x = qst_registers[(u8)regs++];
    set.set_params[0] = qst_registers[(u8)regs];
    create_quest_col(&set, &qst_registers[first]);
}

#pragma push
#pragma fp_contract on
void qst_op_gettime(u8 reg) {
    s32 date;
    s32 seconds;
    getDateStamp((DateStamp *)(&date));
    DateToSeconds((DateStamp *)(&date), (int *)(&seconds));
    qst_registers[reg] = seconds;
}
#pragma pop

void qst_op_unhide_ene(s32 regs) {
    s32 v0 = qst_registers[(u8)regs];
    s32 v1 = qst_registers[(u8)++regs];
    s32 v2 = qst_registers[(u8)++regs];
    unhide_enemies_at__6TLobbyFlll(v0, (s16)v1, (s16)v2, regs);
}

void qst_op_unhide_obj(s32 regs) {
    s32 v0 = qst_registers[(u8)regs];
    s32 v1 = qst_registers[(u8)++regs];
    s32 v2 = qst_registers[(u8)++regs];
    unhide_room_set_objects(v0, (s16)v1, (s16)v2, regs);
}

void qst_op_chk_ene_num(int a0) { qst_registers[(unsigned char)(a0)] = TLobby::count_quest_enemies_flag8(); }

void qst_op_if_zone_clear(s32 dst, s32 regs) {
    if (is_room_enemy_set_cleared((int) (qst_registers[(u8)regs]), (int) ((s16) qst_registers[(u8)(regs + 1)]), qst_registers) != 0) {
        qst_registers[(u8)dst] = 1;
        return;
    }
    qst_registers[(u8)dst] = 0;
}

void qst_op_p_action_enable(void) {
    TObjPlayer *player;

    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        enable_action_input__10TObjPlayerFPv();
        player->action_enable_if_present();
    }
}

void qst_op_p_action_disable(void) {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        player->disable_action_input();
        player->release_attached_resource();
    }
}
void qst_op_pos_pipe(u8 regs) {
    s32 i = regs;
    Vec point;

    point.x = (f32)qst_registers[i++];
    point.y = (f32)qst_registers[i++];
    point.z = (f32)qst_registers[i++];
    TTecLuker::create_for_player((int)((u16)qst_registers[i]), (saddr)&point);
}

void qst_op_create_pipe(void) {
    create_quest_telepipe_for_client(((u16) qst_args[0]));
}

void qst_op_p_setpos(void) {
    Vec pos;
    u16 player;
    u8 reg;
    u8 i;
    TObjPlayer *obj;

    reg = qst_args[1];
    player = qst_args[0];
    i = reg;
    pos.x = qst_registers[i++];
    pos.y = qst_registers[i++];
    pos.z = qst_registers[i++];
    send_6x24_teleport_player(player, &pos, 182.04445f * qst_registers[i]);
    obj = get_player_by_client_id(player);
    if (obj != NULL && player == local_client_id) {
        reset_cameras_to_actor(obj, 0);
    }
}

void qst_op_p_enablewarp(void) {
    foreach_player__10TObjPlayerFv((s32 *)(&fn_801F3480.value));
}

void qst_op_p_disablewarp(void) {
    TTecLuker::apply_all_players();
    foreach_player__10TObjPlayerFv((s32 *)((void *) fn_801F34A0));
}

void qst_op_p_dead(void) {
    s32 dest_reg;
    u8 *lobby;
    dest_reg = qst_args[0];
    lobby = (u8 *)(((u8 *)get_player_by_client_id(qst_args[1])));
    if ((lobby != NULL) && (((TObjPlayer *)lobby)->is_script_controlled() == 0)) {
        if (((TObjChara *)lobby)->obj_isState3_324() != 0) {
            if (*(s32 *)((s8 *)lobby + 0x30) & 0x800) {
                qst_registers[dest_reg] = 1;
                return;
            }
            goto block_7;
        }
        if (((TLobby *)lobby)->check_player_state_flag_2() != 0) {
            qst_registers[dest_reg] = 1;
            return;
        }
        goto block_7;
    }
block_7:
    qst_registers[dest_reg] = 0;
}

#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
void qst_op_p_hpstat(void) {
    s32 reg;
    f32 pct;
    f32 limit;
    void *obj;
    f32 hp;
    s32 player;
    saddr *args = qst_args;
    s32 *regs = qst_registers;
    reg = args[0];
    pct = regs[reg];
    player = args[1];
    if (0.0f == pct) {
        qst_registers[reg] = 0;
        return;
    }
    limit = 1.0f / pct;
    obj = (void *)((saddr)get_player_by_client_id(player));
    if (obj != NULL) {
        hp = ((TObjChara *)obj)->get_actor_hp();
        if (hp / ((TObjChara *)obj)->get_hpmax() < limit) {
            qst_registers[reg] = 1;
            return;
        }
    }
    qst_registers[reg] = 0;
}
#pragma pop
void qst_op_p_move(u8 regs) {
    Vec pos;
    s32 i = regs;
    s32 yaw;
    u16 id;

    pos.x = (f32) qst_registers[i++];
    pos.y = (f32) qst_registers[i++];
    pos.z = (f32) qst_registers[i++];
    yaw = (s32) (182.04445f * (f32) qst_registers[i++]);
    id = qst_registers[i++];
    send_stop_at_position(id, &pos, yaw);
}

void qst_op_p_look_at(void) {
    quest_player_face_actor((u16) qst_args[0], (u16) qst_args[1]);
}

void qst_op_player_effect_nc(u8 regs) {
    Vec v;
    u16 id;
    s16 kind;
    s32 extra;
    f32 dy;
    u8 *p;
    uaddr r;
    s32 i;

    i = regs;
    kind = qst_registers[i++];
    extra = qst_registers[i++];
    id = qst_registers[i++];
    dy = qst_registers[i];
    p = (u8 *)find_entity_by_id(id);
    if (p != NULL) {
        VecCopy__FP3VecPC3Vec(&v, p + 0x38);
        v.y += dy;
        r = (uaddr)create_timed_particle_emitter(&v, kind, 0, extra);
        if (r != 0) {
            ((TParticleCtrl *)r)->set_flags(0x40);
        }
    }
}

void qst_op_has_ep3_save_file() {
    u8 reg = qst_args[0];
    s32 ok = 0;
    if (TAdPlayerLoadGC::probe_card_slot(0) != 0 && TAdPlayerLoadGC::find_card_file(0, "PSO3_CHARACTER") == 0 && TAdPlayerLoadGC::get_load_result(0) == 0) {
        ok = 1;
    }
    if (ok == 0 && TAdPlayerLoadGC::probe_card_slot(1) != 0 && TAdPlayerLoadGC::find_card_file(1, "PSO3_CHARACTER") == 0 && TAdPlayerLoadGC::get_load_result(1) == 0) {
        ok = 1;
    }
    qst_registers[reg] = ok;
}

void qst_op_particle_id(u8 first) {
    Vec point;
    s32 i = first;
    s16 effect = (s16) qst_registers[i++];
    s32 lifetime = qst_registers[i++];
    u16 id = (u16) qst_registers[i++];
    f32 height = (f32) qst_registers[i];
    saddr actor = (saddr)find_entity_by_id(id);
    if (actor != 0) {
        ((void (*)(Vec *, const Vec *))VecCopy__FP3VecPC3Vec)(&point, (const Vec *) (actor + 0x38));
        point.y += height;
        create_timed_particle_emitter(&point, effect, 0, lifetime);
    }
}
void qst_op_particle_effect_nc(u8 regs) {
    Vec v;
    s32 i;
    f32 x;
    f32 y;
    f32 z;
    s16 kind;
    s32 extra;
    uaddr r;

    i = regs;
    x = qst_registers[i++];
    y = qst_registers[i++];
    z = qst_registers[i++];
    kind = qst_registers[i++];
    extra = qst_registers[i];
    v.x = x;
    v.y = y;
    v.z = z;
    r = (uaddr)create_timed_particle_emitter(&v, kind, 0, extra);
    if (r != 0) {
        ((TParticleCtrl *)r)->set_flags(0x40);
    }
}

void qst_op_particle(u8 regs) {
    Vec v;
    s32 i;
    f32 x;
    f32 y;
    f32 z;
    s16 kind;
    s32 extra;

    i = regs;
    x = qst_registers[i++];
    y = qst_registers[i++];
    z = qst_registers[i++];
    kind = qst_registers[i++];
    extra = qst_registers[i];
    v.x = x;
    v.y = y;
    v.z = z;
    create_timed_particle_emitter(&v, kind, 0, extra);
}

void qst_op_particle2() {
    Vec v;
    f32* p = &((f32*)qst_registers)[qst_args[0]];
    v.x = p[0];
    v.y = p[1];
    v.z = p[2];
    uaddr r = (uaddr)create_timed_particle_emitter(&v, qst_args[1], 0, (s32)*(f32 *)&qst_args[2]);
    if (r != 0) {
        ((TParticleCtrl *)r)->set_flags(0x40);
    }
}

void qst_op_pl_walk(u8 regs) {
    WalkCmd_801F09EC cmd;
    f32 x;
    f32 z;
    u16 player;
    Obj_801F09EC *obj;
    s32 i;

    i = regs;
    x = qst_registers[i++];
    i++;
    z = qst_registers[i++];
    player = qst_registers[i];
    obj = (Obj_801F09EC *)get_player_by_client_id(player);
    if (obj != NULL) {
        ((G_WalkToPosition_6x40 *)&cmd)->init();
        cmd.player = player;
        cmd.x = x;
        cmd.z = z;
        cmd.flags = 0;
        if (obj->f30 & 0x100000) {
            cmd.flags |= 8;
        }
        ((G_WalkToPosition_6x40 *)&cmd)->send();
    }
}

void qst_op_p_look(void) {
    quest_player_look_at_partner((u16) qst_args[0]);
}
int qst_op_p_col(void* p) { return set_hashi_versus2_flag(p); }

int qst_op_p_noncol(void* p) { return clear_hashi_versus2_flag(p); }

void qst_op_enable_movement1(void) {
    send_code_45_to_player((u16) qst_args[0]);
}

void qst_op_disable_movement1(void) {
    play_effect((u16) qst_args[0]);
}
void qst_op_npc_talk(void) { enable_partner_chatter(); }

void qst_op_npc_nont(void) { disable_partner_chatter(); }

void qst_op_npc_kill(void) {
    quest_remove_npc_player(((u16) qst_args[0]));
}
void qst_op_cam_adj(void* p) { request_follow_camera_recenter(); }

void qst_op_cam_pan(u8 reg) {
    s32 r = reg;
    Vec pos;
    pos.x = qst_registers[r++];
    pos.y = qst_registers[r++];
    pos.z = qst_registers[r++];
    {
        s32 frames = qst_registers[r++];
        s32 hold_frames = qst_registers[r];
        TCameraPan::create(&pos, frames, hold_frames);
    }
}

void qst_op_nop_86(void) {  }

void qst_op_nop_85(void) {  }
void qst_op_cam_zmout(void *p) { end_conversation_camera(); }

void qst_op_cam_zmin(void *p) { begin_conversation_camera(); }

void qst_op_cam_quake(void) { TCameraCtrl::set_shake_preset(2); }

void qst_op_npc_play(void) {
    send_npc_control_6x69((s32) (u16) qst_args[0]);
}

void qst_op_npc_stop(void) {
    send_npc_stop_6x69((s32) (u16) qst_args[0]);
}
void qst_op_npc_crp_id(u8 first) {
    Vec pos;
    int heading;
    int leader;
    int appearance;
    int slot;
    int i = first;

    pos.x = (f32)qst_registers[i++];
    pos.y = (f32)qst_registers[i++];
    pos.z = (f32)qst_registers[i++];
    heading = (int)(182.04445f * (f32)qst_registers[i++]);
    leader = qst_registers[i++];
    slot = qst_registers[i++];
    appearance = qst_registers[i++];
    TLobby::free_luker_object();
    create_companion(leader, slot, appearance, &pos, heading);
    TLobby::clear_quest_vm_flag();
}

void qst_op_npc_crp(u8 first) {
    Vec pos;
    int heading;
    int leader;
    int appearance;
    int i = first;

    pos.x = (f32)qst_registers[i++];
    pos.y = (f32)qst_registers[i++];
    pos.z = (f32)qst_registers[i++];
    heading = (int)(182.04445f * (f32)qst_registers[i++]);
    leader = qst_registers[i++];
    appearance = qst_registers[i++];
    TLobby::free_luker_object();
    create_default_companion(leader, appearance, &pos, heading);
    TLobby::clear_quest_vm_flag();
}

void qst_op_npc_crptalk_id(u8 first) {
    Vec pos;
    TObjPlayer *player;
    int heading;
    int slot;
    int appearance;
    int i = first;
    u32 injured;

    pos.x = (f32)qst_registers[i++];
    pos.y = (f32)qst_registers[i++];
    pos.z = (f32)qst_registers[i++];
    heading = (int)(182.04445f * (f32)qst_registers[i++]);
    injured = qst_registers[i++];
    appearance = qst_registers[i++];
    slot = qst_registers[i++];
    TLobby::free_luker_object();
    player = new TObjPlayer((TObject *)tl_03, slot, 6, load_npc_player_template(appearance));
    if (player != NULL) {
        *(s16 *)((u8 *)player + 0x324) = 6;
        send_6x24_teleport_player(slot, &pos, heading);
        set_arrival_override_coords(slot, heading, pos.x, pos.y, pos.z);
        player->reset_motion_fields();
        if (injured == 1) {
            queue_player_injured_pose(player);
            set_player_quest_control_flag(player);
        }
    }
    TLobby::clear_quest_vm_flag();
}

void qst_op_npc_crptalk(u8 first) {
    Vec pos;
    TObjPlayer *player;
    int heading;
    int appearance;
    int i = first;
    u32 injured;

    pos.x = (f32)qst_registers[i++];
    pos.y = (f32)qst_registers[i++];
    pos.z = (f32)qst_registers[i++];
    heading = (int)(182.04445f * (f32)qst_registers[i++]);
    injured = qst_registers[i++];
    appearance = qst_registers[i++];
    TLobby::free_luker_object();
    player = new TObjPlayer((TObject *)tl_03, 3, 6, load_npc_player_template(appearance));
    if (player != NULL) {
        *(s16 *)((u8 *)player + 0x324) = 6;
        send_6x24_teleport_player(3, &pos, heading);
        set_arrival_override_coords(3, heading, pos.x, pos.y, pos.z);
        player->reset_motion_fields();
        if (injured == 1) {
            queue_player_injured_pose(player);
            set_player_quest_control_flag(player);
        }
    }
    TLobby::clear_quest_vm_flag();
}

void qst_op_npc_crppk(u8 regs) {
    Vec v;
    s32 angle;
    s32 a;
    s32 b;
    s32 c;
    s32 i;

    i = regs;
    v.x = qst_registers[i++];
    v.y = qst_registers[i++];
    v.z = qst_registers[i++];
    angle = 182.04445f * qst_registers[i++];
    a = qst_registers[i++];
    b = qst_registers[i++];
    c = qst_registers[i];
    TLobby::free_luker_object();
    send_npc_control_create(a, c, b, &v, angle);
    TLobby::clear_quest_vm_flag();
}

void qst_op_npc_crtpk(void) {
    s32 a = qst_args[0];
    s32 b = qst_args[1];
    TLobby::free_luker_object();
    send_npc_control_notify_players(a & 0xFFFF, 1, b);
    TLobby::clear_quest_vm_flag();
}

enum qst_npc_technique {
    QST_NPC_TECHNIQUE_NONE                       = 0x00,
    QST_NPC_TECHNIQUE_FOIE_GIFOIE                = 0x01,
    QST_NPC_TECHNIQUE_BARTA_GIBARTA              = 0x02,
    QST_NPC_TECHNIQUE_NONE_NO_BACKOFF            = 0x03,
    QST_NPC_TECHNIQUE_NONE_NO_BACKOFF_ALT        = 0x0A,
    QST_NPC_TECHNIQUE_FOIE_GIFOIE_NO_BACKOFF     = 0x0B,
    QST_NPC_TECHNIQUE_BARTA_GIBARTA_NO_BACKOFF   = 0x0C,
    QST_NPC_TECHNIQUE_ZONDE_RAZONDE_NO_BACKOFF   = 0x0D,
};

void qst_op_npc_param() {
    TNpcPlayer::AiParams s;
    u8 i;
    TechniqueFlags flags;
    s32 arg;

    i = qst_args[0];
    arg = qst_args[1];
    s.npc_id = qst_registers[i++];
    s.base_level = qst_registers[i++];

    switch (qst_registers[i++]) {
        case QST_NPC_TECHNIQUE_NONE:
            flags = TECHNIQUE_FLAGS_NONE;
            break;
        case QST_NPC_TECHNIQUE_FOIE_GIFOIE:
            flags = TECHNIQUE_FLAGS_FOIE_GIFOIE;
            break;
        case QST_NPC_TECHNIQUE_BARTA_GIBARTA:
            flags = TECHNIQUE_FLAGS_BARTA_GIBARTA;
            break;
        case QST_NPC_TECHNIQUE_NONE_NO_BACKOFF:
        case QST_NPC_TECHNIQUE_NONE_NO_BACKOFF_ALT:
            flags = TECHNIQUE_FLAGS_NONE_NO_BACKOFF;
            break;
        case QST_NPC_TECHNIQUE_FOIE_GIFOIE_NO_BACKOFF:
            flags = TECHNIQUE_FLAGS_FOIE_GIFOIE_NO_BACKOFF;
            break;
        case QST_NPC_TECHNIQUE_BARTA_GIBARTA_NO_BACKOFF:
            flags = TECHNIQUE_FLAGS_BARTA_GIBARTA_NO_BACKOFF;
            break;
        case QST_NPC_TECHNIQUE_ZONDE_RAZONDE_NO_BACKOFF:
            flags = TECHNIQUE_FLAGS_ZONDE_RAZONDE_NO_BACKOFF;
            break;
    }

    s.technique_flags = flags;
    s.enemy_lock_on_range = qst_registers[i++];
    s.min_distance_from_player = qst_registers[i++];
    s.max_distance_from_player = qst_registers[i++];
    s.enemy_unlock_range = qst_registers[i++];
    s.block_range = qst_registers[i++];
    s.attack_range = qst_registers[i++];
    s.attack_technique_level = qst_registers[i++];
    s.support_technique_level = qst_registers[i++];
    s.attack_probability = qst_registers[i++];
    s.attack_technique_probability = qst_registers[i++];
    s.escort_keep_distance = qst_registers[i];

    s.copy_entry_by_index(arg);
}

void qst_op_npc_crt(void) {
    s32 *npc_addr;
    s32 npc_type;
    TLobby::free_luker_object();
    npc_addr = (s32 *)qst_args;
    npc_addr = (s32 *)qst_args;
    npc_type = qst_args[1];
    npc_addr = (s32 *)((u8 *)((s32 *)(uaddr) (u16) qst_args[0]));
    send_npc_create((saddr)npc_addr, (s32)npc_type);
    TLobby::clear_quest_vm_flag();
}

void qst_op_winend(void) {
    if (qst_message_window != NULL) {
        qst_message_window->close();
        qst_message_window = NULL;
    }
    TWindowCtrl::clear_flag_bit2();
    TWindowCtrl::enable_client_main_menu(local_client_id);
    TWindowCtrl::clear_flag();
    TWindowCtrl::clear_flag_2();
}

void qst_op_mesend(void) {
    s32 id;
    void *p;
    s32 start;
    s32 end;
    s32 i;
    s32 f;
    s32 v;
    TWindowCtrl::enable_client_main_menu(local_client_id);
    TWindowCtrl::clear_flag();
    TWindowCtrl::clear_flag_2();
    id = qst_message_speaker;
    if (id < 100) {
        TWindowCtrl::close_windows_by_flags(id);
        return;
    }
    start = TLobby::get_game_mode();
    end = start + TLobby::get_lobby_flag();
    for (i = start; i < end; i++) {
        p = (void *)TObjPlayer::get_player_data(i);
        if (p != NULL) {
            f = ((TObjBase *)(p))->get_entity_id();
            if (f < 0x4000) {
                v = fn_get_field_3ac(p);
            } else {
                v = get_field_d4(p);
            }
            if (v == id) {
                TWindowCtrl::close_windows_by_flags(f);
                return;
            }
        }
    }
}

void qst_op_add_msg(void) {
    s32 x = qst_args[0];
    if (qst_message_window != NULL) {
        dispatch_message_window_text(qst_message_window, x, 3);
        qst_suspend_reason = QST_WAIT_MESSAGE;
        return;
    }
    if (qst_message_window_qb != 0) {
        qst_message_window_qb->append_line(x, 3);
        qst_suspend_reason = QST_WAIT_MESSAGE_QB;
        return;
    }
    qst_args[1] = x;
    qst_args[0] = qst_message_speaker;
    qst_op_message();
}

void qst_op_close_msg_qb(void) {
    if (qst_message_window_qb != NULL) {
        qst_message_window_qb->close();
        qst_message_window_qb = 0U;
    }
}

void qst_op_disp_msg_qb(void) {
    s32 t = qst_args[0];
    Pair_801F1838 pr = lbl_80449A38[0];
    if (qst_message_window_qb != 0) {
        qst_message_window_qb->close();
        qst_message_window_qb = 0;
    }
    qst_message_window_qb = reinterpret_cast<TWindowMessage *>(create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0x71), (NJS_POINT2 *)&pr));
    ((TWindowMessage *)qst_message_window_qb)->append_line(t, 3);
    ((TWindowBase *)qst_message_window_qb)->set_depth(50030.0f);
    qst_suspend_reason = QST_WAIT_MESSAGE_QB;
}

void qst_op_window_msg(void) {
    s32 text;
    TWindowMessageQuest *window;
    text = qst_args[0];
    if (qst_message_window != NULL) {
        qst_message_window->close();
    }
    window = create_quest_message_window();
    qst_message_window = window;
    dispatch_message_window_text(window, text, 3);
    qst_suspend_reason = QST_WAIT_MESSAGE;
    TWindowCtrl::set_flag_bit2();
    close_window_if_active(local_client_id);
    request_active_window_close();
    TWindowCtrl::set_close_flag();
}

void qst_op_bgm(void) {
    play_cue_stream_file(qst_bgm_filename_table[qst_args[0]]);
}

void qst_op_se(void) {
    play_sound_effect(quest_sound_effect_ids[qst_args[0]], 0, 0, 0);
}

void qst_op_fadeout(void) { TLobby::init_fadeout_state(NULL); qst_suspend_reason = QST_WAIT_FADE; }

void qst_op_fadein(void) { TLobby::set_fade_params(NULL); qst_suspend_reason = QST_WAIT_FADE; }

void qst_op_list(void) {
    char *text;
    TTokenList *list;
    u8 idx;
    s32 i;
    char buf[0x200];
    idx = (u32)qst_args[0];
    text = *(char **)&qst_args[1];
    list = new TTokenList(NULL, 0, 0);
    ((char * (*)(char *, const char *, u32))strncpy)(buf, text, 0x1FF);
    trim_whitespace(buf);
    list->tokenize_args(buf);
    qst_list_window = (void *)(saddr)create_window_menu_default(get_window_layout_position(0x37), list->count);
    for (i = 0; i < list->count; i++) {
        ((TWindowMenu *)qst_list_window)->add_text_entry((saddr)list->tokens[i], 7, i);
    }
    ((TWindowMenu *)qst_list_window)->calc_window_size();
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(qst_list_window));
    ((TWindowMenu *)qst_list_window)->set_ready_flag();
    ((TWindowBase *)qst_list_window)->set_depth(39000.0f);
    qst_registers[idx] = 0;
    qst_result_register = idx;
    qst_suspend_reason = QST_WAIT_LIST;
    close_window_if_active(local_client_id);
    request_active_window_close();
    TWindowCtrl::set_close_flag();
    delete list;
}

void qst_op_message(void) {
    s32 speaker = qst_args[0];
    const char *text = (const char *)qst_args[1];
    s32 first;
    void *actor;
    s32 end;
    s32 i;
    close_window_if_active(local_client_id);
    request_active_window_close();
    TWindowCtrl::set_close_flag();
    qst_message_speaker = speaker;
    if (speaker < 100) {
        TWindowCtrl::open(static_cast<u16>(speaker), text, 0x2D);
        TWindowCtrl::set_field28((u16)speaker);
        qst_suspend_reason = QST_WAIT_MESSAGE;
    } else {
        first = TLobby::get_game_mode();
        end = first + TLobby::get_lobby_flag();
        for (i = first; i < end; i++) {
            actor = (void *)TObjPlayer::get_player_data(i);
            if (actor != NULL) {
                s32 identity = ((TObjBase *)(actor))->get_entity_id();
                s32 entity;
                if (identity < 0x4000) {
                    entity = fn_get_field_3ac(actor);
                } else {
                    entity = get_field_d4(actor);
                }
                if (entity == speaker) {
                    TWindowCtrl::open(static_cast<u16>(identity), text, 0x2D);
                    TWindowCtrl::set_field28(identity);
                    qst_suspend_reason = QST_WAIT_MESSAGE;
                    break;
                }
            }
        }
    }
}

void qst_op_stack_popm(s32 regs, s32 count) {
    s32 n = count;
    u8 j = regs + count;
    while (n > 0) {
        int v = qst_call_stack_pop();
        j--;
        qst_registers[j] = v;
        n--;
    }
}

void qst_op_stack_pushm(s32 regs, s32 count) {
    s32 i;
    for (i = 0; i < count; i++) {
        qst_call_stack_push(qst_registers[(u8)regs++]);
    }
}

void qst_op_stack_pop(int a0) { qst_registers[(unsigned char)(a0)] = qst_call_stack_pop(); }

void qst_op_stack_push(s32 reg) {
    qst_call_stack_push((int) (qst_registers[(u8)reg]));
}

void qst_op_switch_call(s32 reg, u8 count, saddr labels) {
    s32 case_index;
    case_index = qst_registers[(u8)reg];
    if ((case_index < (s32) count) && (case_index >= 0)) {
        qst_op_call((u16)((int) (*(u16 *)((s8 *)(labels + (case_index * 2)) + 0))));
    }
}

void qst_op_switch_jmp(s32 reg, u8 count, saddr labels) {
    s32 case_index;
    case_index = qst_registers[(u8)reg];
    if ((case_index < (s32) count) && (case_index >= 0)) {
        qst_op_jmp((int) (*(u16 *)((s8 *)(labels + (case_index * 2)) + 0)));
    }
}

void qst_op_jmpi_le(s32 reg, s32 value, s32 label) {
    if ((s32) qst_registers[(u8)reg] <= value) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmp_le(s32 reg1, s32 reg2, s32 label) {
    if ((s32) qst_registers[(u8)reg1] <= (s32) qst_registers[(u8)reg2]) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_ujmpi_le(s32 reg, u32 value, s32 label) {
    if ((u32) qst_registers[(u8)reg] <= value) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_ujmp_le(s32 reg1, s32 reg2, s32 label) {
    if ((u32) qst_registers[(u8)reg1] <= (u32) qst_registers[(u8)reg2]) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmpi_ge(s32 reg, s32 value, s32 label) {
    if ((s32) qst_registers[(u8)reg] >= value) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmp_ge(s32 reg1, s32 reg2, s32 label) {
    if ((s32) qst_registers[(u8)reg1] >= (s32) qst_registers[(u8)reg2]) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_ujmpi_ge(s32 reg, u32 value, s32 label) {
    if ((u32) qst_registers[(u8)reg] >= value) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_ujmp_ge(s32 reg1, s32 reg2, s32 label) {
    if ((u32) qst_registers[(u8)reg1] >= (u32) qst_registers[(u8)reg2]) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmpi_lt(s32 reg, s32 value, s32 label) {
    if ((s32) qst_registers[(u8)reg] < value) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmp_lt(s32 reg1, s32 reg2, s32 label) {
    if ((s32) qst_registers[(u8)reg1] < (s32) qst_registers[(u8)reg2]) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_ujmpi_lt(s32 reg, u32 value, s32 label) {
    if ((u32) qst_registers[(u8)reg] < value) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_ujmp_lt(s32 reg1, s32 reg2, s32 label) {
    if ((u32) qst_registers[(u8)reg1] < (u32) qst_registers[(u8)reg2]) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmpi_gt(s32 reg, s32 value, s32 label) {
    if ((s32) qst_registers[(u8)reg] > value) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmp_gt(s32 reg1, s32 reg2, s32 label) {
    if ((s32) qst_registers[(u8)reg1] > (s32) qst_registers[(u8)reg2]) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_ujmpi_gt(s32 reg, u32 value, s32 label) {
    if ((u32) qst_registers[(u8)reg] > value) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_ujmp_gt(s32 reg1, s32 reg2, s32 label) {
    if ((u32) qst_registers[(u8)reg1] > (u32) qst_registers[(u8)reg2]) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmpi_ne(s32 reg, s32 value, s32 label) {
    if (value != (s32) qst_registers[(u8)reg]) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmp_ne(s32 reg1, s32 reg2, s32 label) {
    if ((s32) qst_registers[(u8)reg1] != (s32) qst_registers[(u8)reg2]) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmpi_eq(s32 reg, s32 value, s32 label) {
    if (value == (s32) qst_registers[(u8)reg]) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmp_eq(s32 reg1, s32 reg2, s32 label) {
    if ((s32) qst_registers[(u8)reg1] == (s32) qst_registers[(u8)reg2]) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmp_off(s32 label, u8 count, u8 *regs) {
    s32 all_off = 1;
    while (count != 0) {
        u8 reg = *regs;
        count--;
        regs++;
        all_off &= (u8) ((s32) qst_registers[(u8)reg] == 0);
    }
    if (all_off != 0) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmp_on(s32 label, u8 count, u8 *regs) {
    s32 i;
    for (i = 0; i < count; i++) {
        if ((s32) qst_registers[(u8)*regs++] == 0) {
            return;
        }
    }
    qst_pc = qst_function_table[(u16)label];
}

#pragma push
#pragma fp_contract on
void qst_op_call(u16 label) {
    qst_call_stack_push((saddr)((void *) (qst_pc)));
    qst_pc = qst_function_table[label];
}
#pragma pop

void qst_op_modi(s32 dst, u32 value) {
    qst_registers[(u8)dst] %= value;
}

void qst_op_mod(s32 dst, s32 src) {
    qst_registers[(u8)dst] %= qst_registers[(u8)src];
}

void qst_op_jmp(int a0) { qst_pc = qst_function_table[(u16)a0]; }

void qst_op_xori(s32 dst, s32 value) {
    qst_registers[(u8)dst] ^= value;
}

void qst_op_xor(s32 dst, s32 src) {
    qst_registers[(u8)dst] ^= qst_registers[(u8)src];
}

void qst_op_ori(s32 dst, s32 value) {
    qst_registers[(u8)dst] |= value;
}

void qst_op_or(s32 dst, s32 src) {
    qst_registers[(u8)dst] |= qst_registers[(u8)src];
}

void qst_op_andi(s32 dst, s32 value) {
    qst_registers[(u8)dst] &= value;
}

void qst_op_and(s32 dst, s32 src) {
    qst_registers[(u8)dst] &= qst_registers[(u8)src];
}

void qst_op_divi(s32 dst, s32 value) {
    qst_registers[(u8)dst] /= value;
}

void qst_op_div(s32 dst, s32 src) {
    qst_registers[(u8)dst] /= (s32) qst_registers[(u8)src];
}

void qst_op_muli(s32 dst, s32 value) {
    qst_registers[(u8)dst] *= value;
}

void qst_op_mul(s32 dst, s32 src) {
    qst_registers[(u8)dst] *= qst_registers[(u8)src];
}

void qst_op_subi(s32 dst, s32 value) {
    qst_registers[(u8)dst] -= value;
}

void qst_op_sub(s32 dst, s32 src) {
    qst_registers[(u8)dst] -= qst_registers[(u8)src];
}

void qst_op_addi(int a0, int a1) { qst_registers[(unsigned char)(a0)] += a1; }

void qst_op_add(s32 dst, s32 src) {
    qst_registers[(u8)dst] += qst_registers[(u8)src];
}

void qst_op_gget(u16 flag, s32 dst) {
    if (get_story_flag((flag)) != 0) {
        qst_registers[(u8)dst] = 1;
        return;
    }
    qst_registers[(u8)dst] = 0;
}

void qst_op_glet(u16 flag, s32 reg) {
    if ((s32) qst_registers[(u8)reg] != 0) {
        set_story_flag_or_send_quest_flag((s32)flag);
        return;
    }
    clear_story_flag((flag));
}

namespace pf2_p6 { extern "C" { s32 set_story_flag_or_send_quest_flag(s32); } }
#define set_story_flag_or_send_quest_flag pf2_p6::set_story_flag_or_send_quest_flag
void qst_op_grev(s32 flag) {
    u16 v = flag;
    if (get_story_flag(v) != 0) {
        clear_story_flag(v);
        return;
    }
    set_story_flag_or_send_quest_flag(v);
}
void qst_op_gclear(u16 flag) {
    clear_story_flag((flag));
}

void qst_op_gset(u16 flag) {
    set_story_flag_or_send_quest_flag((s32)flag);
}

void qst_op_rev(s32 reg) {
    qst_registers[(u8)reg] = qst_registers[(u8)reg] == 0;
}

void qst_op_clear(s32 reg) {
    qst_registers[(u8)reg] = 0;
}

void qst_op_set(s32 reg) {
    qst_registers[(u8)reg] = 1;
}

void qst_op_leto(s32 dst, s32 label) {
    qst_registers[(u8)dst] = (saddr)&qst_function_table[(u16)label];
}

void qst_op_leta(s32 dst, s32 src) {
    qst_registers[(u8)dst] = (saddr)&qst_registers[(u8)src];
}

void qst_op_letw(int a0, int a1) { qst_registers[(unsigned char)(a0)] = (a1 & 0xffff); }

void qst_op_letb(int a0, int a1) { qst_registers[(unsigned char)(a0)] = (a1 & 0xff); }

void qst_op_leti(int a0, int a1) { qst_registers[(unsigned char)(a0)] = a1; }

void qst_op_let(s32 dst, s32 src) {
    qst_registers[(u8)dst] = qst_registers[(u8)src];
}

void qst_op_thread_stg(u16 label) {
    TQuestThread::create(label);
}

void qst_op_thread(u16 label) {
    TQuestThread::create_in_root(label);
}

void qst_op_sync(void) { qst_suspend_reason = QST_SUSPEND_SYNC; }

void qst_op_exit(void) { qst_suspend_reason = QST_SUSPEND_EXIT; }

void qst_op_ret(void) {
    u32 nested = qst_call_stack_depth > 0;
    if (nested) {
        qst_pc = qst_call_stack_pop();
    }
    if (!nested) {
        qst_suspend_reason = QST_SUSPEND_RETURN;
    }
}

void qst_op_nop(void) {  }
u16 read_be_u16(void);
extern "C" {
s32 stream_read_be32(void);
}
void append_string_to_buffer(s32 dest);
extern char qst_cstring_buffer[];

void qst_getargs_u16_u8(s32 op) {
    void (*fn)(u16, u8) = (void (*)(u16, u8))qst_opcode_table[op].handler;
    u16 a = read_be_u16();
    fn(a, TLobby::read_packet_byte());
}

void qst_getargs_u16(s32 op) {
    void (*fn)(u16) = (void (*)(u16))qst_opcode_table[op].handler;
    fn(read_be_u16());
}

void qst_getargs_cstring(s32 op) {
    void (*fn)(char *) = (void (*)(char *))qst_opcode_table[op].handler;
    append_string_to_buffer((saddr)qst_cstring_buffer);
    fn(qst_cstring_buffer);
}

typedef void (*SwitchJumpHandler)(s32, u8, s16 *);
typedef void (*JumpOnHandler)(u16, u8, u8 *);

void qst_getargs_s32_u8_s16ptr(s32 op) {
    s16 buf[16];
    SwitchJumpHandler fn = (SwitchJumpHandler) qst_opcode_table[op].handler;
    s32 first = ((s32 (*)(void))TLobby::read_packet_byte)();
    u8 count = ((s32 (*)(void))TLobby::read_packet_byte)();
    s32 i;

    for (i = 0; i < count; i++) {
        buf[i] = ((s16 (*)(void))read_be_u16)();
    }
    fn(first, count, buf);
}

void qst_getargs_u16_u8_u8ptr(s32 op) {
    u8 buf[16];
    JumpOnHandler fn = (JumpOnHandler) qst_opcode_table[op].handler;
    u16 label = ((s32 (*)(void))read_be_u16)();
    u8 count = ((s32 (*)(void))TLobby::read_packet_byte)();
    s32 i;

    for (i = 0; i < count; i++) {
        buf[i] = ((s32 (*)(void))TLobby::read_packet_byte)();
    }
    fn(label, count, buf);
}

void qst_getargs_u8_s32_u16(s32 op) {
    void (*fn)(u8, s32, u16) = (void (*)(u8, s32, u16))qst_opcode_table[op].handler;
    u8 a = TLobby::read_packet_byte();
    s32 b = stream_read_be32();
    fn(a, b, read_be_u16());
}

void qst_getargs_u8_u8_u16(s32 op) {
    void (*fn)(u8, u8, u16) = (void (*)(u8, u8, u16))qst_opcode_table[op].handler;
    u8 a = TLobby::read_packet_byte();
    u8 b = TLobby::read_packet_byte();
    fn(a, b, read_be_u16());
}

void TLobby::dispatch_command(s32 op) {
    void (*fn)(u8, u16) = (void (*)(u8, u16))qst_opcode_table[op].handler;
    u8 a = TLobby::read_packet_byte();
    fn(a, read_be_u16());
}

void qst_getargs_u16_2(s32 op) {
    void (*fn)(u16) = (void (*)(u16))qst_opcode_table[op].handler;
    fn(read_be_u16());
}

void qst_getargs_s32(s32 op) {
    void (*fn)(s32) = (void (*)(s32))qst_opcode_table[op].handler;
    fn(stream_read_be32());
}

void qst_getargs_u8_s32(s32 op) {
    void (*fn)(u8, s32) = (void (*)(u8, s32))qst_opcode_table[op].handler;
    u8 a = TLobby::read_packet_byte();
    fn(a, stream_read_be32());
}

void qst_getargs_u8_u8(s32 op) {
    void (*fn)(u8, u8) = (void (*)(u8, u8))qst_opcode_table[op].handler;
    u8 a = TLobby::read_packet_byte();
    fn(a, TLobby::read_packet_byte());
}

void qst_getargs_u8(s32 op) {
    void (*fn)(u8) = (void (*)(u8))qst_opcode_table[op].handler;
    fn(TLobby::read_packet_byte());
}

void qst_getargs_void_reset(s32 op) {
    qst_opcode_table[op].handler();
    qst_arg_count = 0;
}

void qst_getargs_void(s32 op) {
    qst_opcode_table[op].handler();
}

s32 qst_call_stack_pop(void) {
    if (qst_call_stack_depth > 0) {
        return qst_call_stack[--qst_call_stack_depth];
    }
    return 0;
}

void qst_call_stack_push(s32 a0)
{
  qst_call_stack[qst_call_stack_depth++] = a0;
}
int qst_label_address(int label) {  return (saddr)(qst_code + qst_function_table[(u16)label]); }
extern "C" {

namespace pf2_p12 { extern "C" { s32 expand_message_substitutions(s32, s32, s32); } }
#define expand_message_substitutions pf2_p12::expand_message_substitutions
s32 bswap_32__FPUl(s32 *, s32);
}
namespace pf2_p12 { extern "C" { s32 memcpy(s32 *, s32, s32); } }
#define memcpy pf2_p12::memcpy
namespace pf2_p12 { extern "C" { s32 strlen(s32, s32); } }
#define strlen pf2_p12::strlen

void append_string_to_buffer(s32 dest) {
    s32 string_length;

    string_length = strlen((saddr)(qst_code + qst_pc), (saddr)qst_code);
    expand_message_substitutions((saddr)(qst_code + qst_pc), dest, (saddr)qst_code);
    qst_pc += string_length + 1;
}
extern "C" {

s32 stream_read_be32(void) {
    s32 value;
    s32 read_pc;

    memcpy(&value, (saddr)(qst_code + qst_pc), 4);
    read_pc = qst_pc;
    qst_pc = read_pc + 4;
    bswap_32__FPUl(&value, read_pc);
    return value;
}

#undef expand_message_substitutions
#undef memcpy
#undef strlen

s32 bswap_16__FPUs(u16 *, s32);
}
namespace pf2_p13 { extern "C" { s32 memcpy(u16 *, s32, s32); } }
#define memcpy pf2_p13::memcpy

u16 read_be_u16(void) {
    u16 value;
    s32 read_pc;

    memcpy(&value, (saddr)(qst_code + qst_pc), 2);
    read_pc = qst_pc;
    qst_pc = read_pc + 2;
    bswap_16__FPUs(&value, read_pc);
    return value;
}

#undef memcpy

saddr qst_args[8];
s32 qst_call_stack[64];
QuestPlayerNameBuffer quest_player_name_buffer;
QuestPlayerClassNameBuffer quest_player_class_name_buffer;
BattleRules battle_rules;
char qst_cstring_buffer[0x404];
