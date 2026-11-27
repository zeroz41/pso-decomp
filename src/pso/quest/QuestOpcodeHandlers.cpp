#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/TItemIdCounters.h"
#include "pso/math/CurvePathPoint.h"
#include "pso/enemy/BattleParameters.h"
#include "pso/quest/QuestOpcodeHandlers.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/ResourceFile.h"
#include "pso/system/GbaDownloadRuntime.h"
#include "pso/system/scene/TScene.h"
#include "pso/render/CameraCapture.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/player/PlayerState.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pso/system/byteswap.h"
#include "pso/network/FloorEventCommand.h"
#include "pso/player/LocalClientId.h"
#include "pso/unk/TQuestManager.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/ui/window/TWindowMessage.h"
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
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/font/TFontSmallLobby.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/player/PlayerSlots.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/item/drop/TItemDropSub.h"
#include "pso/network/TLobby.h"
#include "pso/map/FloorPopulation.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/ui/chat/SymbolChatPayload.h"
#include "pso/network/TProtocol.h"
#include "pso/map/TSetManager.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/enemy/BattleParamTables.h"
#include "pso/system/prs.h"
#include "pso/ui/keyboard/SystemBootInitInternal.h"
#include "pso/system/TColorOverlayFade.h"
#include "pso/object/door/TObjDoorGlobalState.h"
#include "pso/map/FloorMapSelection.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/base/TObjBase.h"
#include "pso/quest/QuestOpcodeTables.h"
#include "types.h"
#include "pso/player/TPlyCharData.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TWindowSubEquipKind.h"
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
#include "pso/player/TPlayerBattleCtrl.h"
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
#include "pso/object/quest/TObjQuestCol.h"
#include "pso/object/quest/TObjQuestColA.h"
#include "pso/object/quest/TObjQuestColALock.h"
#include "pso/object/quest/TObjQuestColApc.h"
#include "pso/object/quest/TObjQuestColApcIN.h"
#include "pso/quest/TQuestColCtrl.h"
#include "pso/object/TObjSinBoard.h"
#include "pso/object/TObjTombstone.h"
#include "pso/quest/TQuestDamageTask.h"
#include "pso/boss/dragon/TBoss1Dragon.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/ui/Language.h"
#include "pso/system/MemoryMove.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/player/TPlyItem.h"
#include "pso/item/TItemList.h"
#include "pso/camera/TCameraFollow.h"
#include "pso/camera/TCameraPan.h"
#include "pso/system/TTokenList.h"
#include "pso/system/TScreenFadeOut.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/player/TObjPlayerActions.h"
#include "pso/player/PlayerCommands.h"
#include "pso/item/item_create.h"
#include "pso/ui/window/TWindowMessageQuest.h"
#include "pso/quest/QuestScriptFormat.h"
#include "pso/system/data/FlagWord.h"
#include "pso/system/GbaAramCache.h"
#include "pso/object/warp/ForestWarpResources.h"
#include "pso/network/TGameProtocol.h"
#include "pso/object/TObjLuker.h"
#include "pso/map/AreaEventSet.h"
#include "pso/network/GbaJoybootState.h"
#include "pso/object/trap/TOMine.h"
#include "pso/player/Palettex.h"
#include "pso/quest/challenge/TChallenge4PItemSelect.h"
#include "pso/item/FloorItemSync.h"
#include "pso/quest/QuestFloorDesignation.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/quest/challenge/TChallenge4P.h"
#include "pso/quest/QuestStoryFlags.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/ui/window/TWindowComCardFollower.h"
#include "pso/object/warp/TObjLaboMapWarp.h"
#include "pso/boss/galgryphon/TBoss5GryphonDemo.h"
#include "pso/ui/chat/TSymbolChatCapture.h"
#include "pso/player/ClassTypeName.h"
#include "pso/ui/city/THunterGuildWarning.h"
#include "pso/boss/BossPhaseQuery.h"
#include "pso/map/MapSetData.h"


void qst_call_stack_push(s32 value);
s32 qst_call_stack_pop(void);
u8 *qst_label_address(int label);


u8 *qst_code;
s32 *qst_function_table;
QuestValue *qst_registers;

TWindowMessageQuest *qst_message_window;
TWindowMessage *qst_message_window_qb;
TWindowMenu *qst_list_window;
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
TObjItemNameEntry *qst_item_name_entry;
TObjItemNameSelect *qst_item_name_select;
TObjItemOKWindow *qst_item_ok_window;
TWindowMenuIconLine *qst_pack_select_window;
TWindowHelpItem *qst_pack_select_help_window;
u32 qst_flag_buf;
u16 qst_statistic_arg1;
u16 qst_statistic_arg2;
u16 qst_statistic_id;


void append_string(const char *s);
s32 is_message_source_exhausted(void);
void begin_message_substitution(u8 *source, char *result);
s32 parse_r_index(const char *text);
// The player name and class name qst_op_get_pl_name / qst_op_get_pl_job copy for the message tags.
extern char quest_player_class_name_buffer[16];
extern char quest_player_name_buffer[16];
void append_player_name(void);
void append_message_char(s8);
void append_team_name(void);
void append_episode_progress_string(void);
void append_entered_item_name_pair(void);
void append_challenge_title(void);
s32 parse_f_index(const char *a0);
void append_hero_name(void);
void append_hero_class_name(void);


const BaInitialFloorTable ba_initial_floor_table = { { 16, 17, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 } };

// inferred names: each qst_op_ba_* setter maps its argument through its own table into the battle_rules field
// The name gives (trap_count_slots maps qst_op_ba_set_trap_count's slot to the battle_rules.trap_counts index).
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

// qst_op_ba_forbid_scape_dolls maps its 0/1 argument through it
const s32 forbid_scape_dolls_values[2] = { 0, 1 };

const StartOrUpdateGbaJoybootTable lobby_index_identity_table_a = { { 0, 1, 2, 3, 4 } };

// The position qst_op_open_pack_select opens the equip kind window at
const NJS_POINT2 pack_select_window_pos = { 308.0f, 184.0f };

const InitialFloorTable lobby_index_identity_table_b = {
    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 }
};

// The <tag> names the message parser replaces, and their handlers.
const QuestCommandTable message_substitution_handlers = { {
    { "hero name", append_hero_name },
    { "hero job", append_hero_class_name },
    { "time", append_episode_progress_string },
    { "award item", append_entered_item_name_pair },
    { "challenge title", append_challenge_title },
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
    TOChatSensor::dispatch_chat_message_to_children((char *)message);
    TOChatSensorCapture::capture_message((u16)((u16) local_client_id), (const char *)message);
}

char *expand_message_substitutions(u8 *source, char *result) {
    begin_message_substitution(source, result);
    while (is_message_source_exhausted() == 0) {
        s8 c = TLobby::read_byte_advance();
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
    QuestCommandTable tbl = message_substitution_handlers;
    u32 i;
    s32 idx;
    s8 c;
    for (i = 0; i < 0x40 && is_message_source_exhausted() == 0; i++) {
        c = TLobby::read_byte_advance();
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
    s = get_chat_last_line();
    if (strcmp(s, "") == 0) {
        append_string("ERROR");
        return;
    }
    append_string(s);
}

// The "team_name" tag handler of message_substitution_handlers
void append_team_name(void) {
    char *s;
    s = get_lobby_name();
    if (strcmp(s, "") == 0) {
        append_string("ERROR");
        return;
    }
    append_string(s);
}

// The grave message of the character save record: qst_op_is_there_grave_message tests it and the
// "last_word" tag prints it.
void TLobby::append_card_window_text() {
    CharacterSaveRecord *record;

    record = (CharacterSaveRecord *)get_character_save_record(0xFFFF);
    if (record != NULL) {
        append_string(record->challenge.tombstone.unit_name);
        return;
    }
    append_string("Error");
}

void TLobby::append_default_string() {
    append_string(quest_player_class_name_buffer);
}

void append_player_name(void) {
    append_string(quest_player_name_buffer);
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


s32 parse_r_index(const char *text) {
    s32 index;

    index = -1;
    sscanf(text, "r%d", &index);
    if ((index < 0x100) && (index >= 0)) {
        return index;
    }
    return -1;
}

s8 *quest_script_read_ptr;

void append_challenge_title(void) {
    char buf[0x40];
    if (is_split_screen() == 1) {
        sprintf(buf, "%s", get_active_challenge_title());
    } else {
        sprintf(buf, "%s", decode_active_challenge_title());
    }
    buf[0x3F] = 0;
    append_string(buf);
}

void append_entered_item_name_pair(void) {
    char buf[64];
    s32 t = (saddr)TObjItemNameSelect::get_selected_name();
    sprintf(buf, "%s %s", get_entered_item_name(), t);
    buf[63] = 0;
    append_string(buf);
}

void TLobby::append_float_value(s32 reg) {
    char buf[64];
    sprintf(buf, "%f", qst_registers[reg].f);
    append_string(buf);
}

void TLobby::append_int_param(s32 reg) {
    char buf[64];
    sprintf(buf, "%d", qst_registers[reg].i);
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
        append_string((const char *)get_class_type_name(player->appearance.classFlags));
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
s32 is_message_source_exhausted(void) {
    return (u8) (*quest_script_read_ptr == 0);
}
s8 TLobby::read_byte_advance() {
    s8 *cursor;

    cursor = quest_script_read_ptr;
    quest_script_read_ptr = cursor + 1;
    return *cursor;
}

char *quest_string_append_cursor;

void append_string(const char *s) {
    u32 len = strlen(s);
    strcpy(quest_string_append_cursor, s);
    quest_string_append_cursor += len;
}


void append_message_char(s8 c) {
    char *write_ptr;

    write_ptr = quest_string_append_cursor;
    quest_string_append_cursor = write_ptr + 1;
    *write_ptr = c;
}
void begin_message_substitution(u8 *source, char *result) { quest_script_read_ptr = (s8 *)source; quest_string_append_cursor = result; }

void qst_op_olga_flow_is_dead(s32 reg) {
    if (TBoss6PlotFalz::is_phase_reached() != 0) {
        qst_registers[(u8)reg].i = 1;
        return;
    }
    qst_registers[(u8)reg].i = 0;
}

void qst_op_initial_floor(void) {
    InitialFloorTable t = lobby_index_identity_table_b;
    if (qst_args[0].i <= 0x11U) {
        initialize_floor_transition(&floor_transition_state, t.w[qst_args[0].i], 0);
    }
}

void qst_op_get_item_stackability() {
    u8 dest_reg;
    TItem *item;
    dest_reg = (u8) qst_args[1].i;
    item = find_item_by_id((int) (qst_args[0].i));
    if (item != NULL) {
        if (item->is_stackable() != 0) {
            qst_registers[dest_reg].i = 1;
            return;
        }
        qst_registers[dest_reg].i = 0;
        return;
    }
    qst_registers[dest_reg].i = -1;
}

void qst_op_create_symbol_chat_capture_buffer() { TSymbolChatCapture::create_singleton(tl_01); }

void qst_op_get_recent_symbol_chat() {
    SymbolChatPayload buf;
    u8 idx;
    idx = (u8) qst_args[1].i;
    send_slot_entity_or_local((u16) qst_args[0].i, &buf);
    memcpy(&qst_registers[idx].i, &buf, sizeof(buf));
}

void qst_op_get_guildcard_num(void) {
    u8 dest_reg;
    TObjPlayer *player;
    dest_reg = (u8) qst_args[1].i;
    player = get_player_by_client_id((s32) (u16) qst_args[0].i);
    if (player != NULL) {
        qst_registers[dest_reg].i = player->guild_card_tag.guildcard_number;
        return;
    }
    qst_registers[dest_reg].i = -1;
}
void qst_op_check_for_keyword(void) {
    u8 idx;
    idx = (u8) qst_args[0].i;
    if (TOChatSensorCapture::check_keyword((u16) qst_args[1].i, (const char *) qst_args[2].i) != 0) {
        qst_registers[idx].i = 1;
        return;
    }
    qst_registers[idx].i = 0;
}


void qst_op_enable_keyword_detect() { TOChatSensorCapture::create_instance(tl_01); }

void qst_op_prepare_statistic(void) {
    qst_statistic_id = (s16) qst_args[0].i;
    qst_statistic_arg1 = (s16) qst_args[1].i;
    qst_statistic_arg2 = (s16) qst_args[2].i;
}

void qst_op_send_statistic() {
    TLobby::protocol_instance->send_statistic(qst_statistic_id, qst_statistic_arg1, qst_statistic_arg2, (u32 *)qst_args);
}

void qst_op_arg_pushs(int a0) { int old = qst_arg_count; qst_arg_count = old + 1; qst_args[old].i = a0; }

void qst_op_arg_pusho(u16 a0) {
    qst_args[qst_arg_count++].p = &qst_function_table[a0];
}

void qst_op_arg_pusha(u8 a0) {
    qst_args[qst_arg_count++].p = &qst_registers[a0];
}

void qst_op_arg_pushw(u16 a0) {
    qst_args[qst_arg_count++].i = a0;
}

void qst_op_arg_pushb(u8 a0) {
    qst_args[qst_arg_count++].i = a0;
}

void qst_op_arg_pushl(int a0) {
    qst_args[qst_arg_count++].i = a0;
}
void qst_op_arg_pushr(u8 a0) {
    qst_args[qst_arg_count++].i = qst_registers[a0].i;
}

void qst_op_va_call(s32 label) {
  qst_arg_count = 0;
  qst_registers[1].i = qst_args[0].i;
  qst_registers[2].i = qst_args[1].i;
  qst_registers[3].i = qst_args[2].i;
  qst_registers[4].i = qst_args[3].i;
  qst_registers[5].i = qst_args[4].i;
  qst_registers[6].i = qst_args[5].i;
  qst_registers[7].i = qst_args[6].i;
  qst_call_stack_push(qst_pc);
  qst_pc = qst_function_table[(u16)label];
}
extern "C" {
}

int quest_active_flag;
int evt2_random_enemies_mode;
extern VaCallPair qb_message_window_size[];

void qst_op_va_end() {
    qst_op_stack_popm(1, 7);
}

void qst_op_va_start() { qst_arg_count = 0; qst_op_stack_pushm(1, 7); }

void qst_op_scroll_text() {
    NJS_POINT2 pos;
    NJS_POINT2 size;
    s32 x = qst_args[0].i;
    s32 y = qst_args[1].i;
    s32 cols = qst_args[2].i;
    s32 rows = qst_args[3].i;
    s32 frame_mode = qst_args[4].i;
    f32 timer = qst_args[5].f;
    s32 msg = qst_args[6].i;
    s32 arg = qst_args[7].i;
    TWindowMessageScroll *win;

    if (qst_message_window != NULL) {
        qst_message_window->close();
    }
    pos.x = x;
    pos.y = y;
    size.x = 8.0f + (f32)(cols * 0x12);
    size.y = (20.0f + (f32)(rows * 0x14)) - 2.0f;
    win = open_message_scroll_window(&pos, &size, &qst_registers[msg].i);
    win->set_frame_mode(frame_mode);
    dispatch_message_window_text(win, (const char *)arg, 0x13);
    win->set_scroll_speed(timer);
    qst_message_window = win;
}

void qst_op_item_create_multi_cm(u8 i) {
    TItemData item;
    s32 mode = qst_registers[i++].i;
    item.init();
    item.data1.data_u8[0] = qst_registers[i++].i;
    item.data1.data_u8[1] = qst_registers[i++].i;
    item.data1.data_u8[2] = qst_registers[i++].i;
    item.data1.data_u8[3] = qst_registers[i++].i;
    item.data1.data_u8[4] = qst_registers[i++].i;
    item.data1.data_u8[5] = qst_registers[i].i;
    item.id = advance_item_id_counter(local_client_id);
    switch (mode) {
    case 0:
        TChallenge4PResult::update_entries(&item, 2);
        break;
    case 1:
        TChallenge4PResult::update_entries(&item, 0);
        break;
    case 2:
        TChallenge4PResult::update_entries(&item, 1);
        break;
    }
}

void qst_op_delayed_switch_episode(s32 reg) {
    switch (qst_registers[(u8)reg].i) {
    case 0:
        request_story_select_state(0);
        return;
    case 1:
        request_story_select_state(1);
        return;
    }
}

void qst_op_chat_bubble(void) {
    s32 id = qst_args[0].i;
    const char *text = (const char *)qst_args[1].i;
    TObjPlayer *player;
    s32 start;
    s32 end;
    s32 i;
    s32 win;
    s32 v;
    if (id < 100) {
        TWindowCtrl::open_default(id, text);
        TWindowCtrl::set_window_id(id);
        return;
    }
    start = TLobby::get_game_mode();
    end = start + TLobby::get_lobby_flag();
    for (i = start; i < end; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player != NULL) {
            win = player->get_entity_id();
            if (win < 0x4000) {
                v = fn_get_field_3ac(player);
            } else {
                v = get_field_d4(player);
            }
            if (v == id) {
                TWindowCtrl::open_default(win, text);
                TWindowCtrl::set_window_id(win);
                return;
            }
        }
    }
}

void qst_op_chat_box() {
    NJS_POINT2 pos;
    NJS_POINT2 size;
    s32 x = qst_args[0].i;
    s32 y = qst_args[1].i;
    s32 cols = qst_args[2].i;
    s32 rows = qst_args[3].i;
    s32 frame_mode = qst_args[4].i;
    s32 arg = qst_args[5].i;

    if (qst_message_window != NULL) {
        qst_message_window->close();
    }
    pos.x = x;
    pos.y = y;
    size.x = 8.0f + (f32)(cols * 0x12);
    size.y = (20.0f + (f32)(rows * 0x14)) - 2.0f;
    qst_message_window = create_quest_message_window_at(&pos, &size);
    qst_message_window->set_frame_mode(frame_mode);
    dispatch_message_window_text(qst_message_window, (const char *)arg, 3);
    qst_suspend_reason = QST_WAIT_MESSAGE;
    TWindowCtrl::set_flag_bit2();
    close_window_if_active(local_client_id);
    request_active_window_close();
    TWindowCtrl::set_close_flag();
}

void qst_op_add_color_overlay() {
    s32 a = qst_args[0].i;
    s32 b = qst_args[1].i;
    s32 c = qst_args[2].i;
    s32 d = qst_args[3].i;
    s32 e = qst_args[4].i;
    new TColorOverlayFade(tl_01, 0, e, d, a, b, c);
}

void qst_op_get_chosen_item_id(int a0) { qst_registers[(unsigned char)(a0)].i = -1; qst_result_register = a0; qst_suspend_reason = QST_WAIT_ITEM_CHOICE; TWindowCtrl::set_flag_bit2(); close_window_if_active(local_client_id); request_active_window_close(); TWindowCtrl::set_close_flag(); }

void qst_op_prevent_item_select(s32 reg) {
    if (qst_pack_select_help_window != NULL) {
        disable_pack_item_rows(qst_pack_select_window, qst_registers[(u8)reg].i);
    }
}

void qst_op_open_pack_select() {
    qst_pack_select_window = (TWindowMenuIconLine *)create_equip_kind_window(get_window_layout_position(3), &pack_select_window_pos, local_client_id);
    qst_pack_select_window->refresh_judgment_item_list();
    qst_pack_select_help_window = new TWindowHelpItem(get_window_layout_position(2), local_client_id);
}

void qst_op_prepare_gba_rom_from_disk(void) {
    const char *filename = reinterpret_cast<const char *>(qst_args[0].i);
    TLobby::free_luker_object();
    gba_download_load_file(filename);
    gba_joyboot_set_send_buffer(gba_download_data_buffer, static_cast<s32>(gba_download_data_size));
    TLobby::clear_quest_vm_flag();
}

void qst_op_get_players_present(u8 out) {
    s32 p;
    for (p = 0; p < 4; p++, out++) {
        if (get_player_by_client_id(p) != NULL) {
            qst_registers[out].i = 1;
        } else {
            qst_registers[out].i = 0;
        }
    }
}

void qst_op_find_bank_item(u8 i, u8 out) {
    TItemData item;
    saddr card;
    qst_registers[out].i = -1;
    card = get_character_save_record(0xFFFF);
    if (card != 0) {
        item.init();
        item.data1.data_u8[0] = qst_registers[i++].i;
        item.data1.data_u8[1] = qst_registers[i++].i;
        item.data1.data_u8[2] = qst_registers[i++].i;
        item.data1.data_u8[4] = qst_registers[i].i;
        if (((CharacterSaveRecord *)card)->find_bank_item(&item) != 0) {
            qst_registers[out].i = 1;
        } else {
            qst_registers[out].i = 0;
        }
    }
}

void qst_op_write_counter() {
    s32 idx = qst_args[0].i;
    s32 val = qst_args[1].i;
    CharacterSaveRecord *record = (CharacterSaveRecord *)get_character_save_record(0xFFFFU);
    if (record != NULL && idx >= 0 && idx < 0x10) {
        record->quest_counters[idx] = val;
    }
}

void qst_op_read_counter(void) {
    s32 counter_index = qst_args[0].i;
    u8 dest_reg = (u8)qst_args[1].i;
    CharacterSaveRecord *record = (CharacterSaveRecord *)get_character_save_record(0xFFFFU);
    if (record != NULL) {
        if (counter_index >= 0 && counter_index < 0x10) {
            qst_registers[dest_reg].i = record->quest_counters[counter_index];
        }
    } else {
        qst_registers[dest_reg].i = -1;
    }
}

void qst_op_get_coord_player_detect(u8 i, u8 out) {
    Vec pos;
    f32 r;
    f32 r2;
    s32 p;
    TObjPlayer *player;

    pos.x = qst_registers[i++].i;
    pos.y = 0.0f;
    pos.z = qst_registers[i++].i;
    r = qst_registers[i].i;
    r2 = r * r;
    for (p = 0; p < 4; p++, out++) {
        qst_registers[out].i = 0;
        player = get_player_by_client_id(p);
        if (player != NULL) {
            if (xz_distance_squared(&player->position, &pos) < r2) {
                qst_registers[out].i = 1;
            }
        }
    }
}

void qst_op_get_player_room(void) {
    TObjPlayer *player = get_player_by_client_id(qst_args[0].i);
    u8 i = qst_args[1].i;
    if (player != NULL) {
        qst_registers[i++].i = player->get_floor();
        qst_registers[i].i = player->get_room();
    } else {
        qst_registers[i++].i = -1;
        qst_registers[i].i = -1;
    }
}

void qst_op_get_player_hp_tp(void) {
    TObjPlayer *player = get_player_by_client_id(qst_args[0].i);
    u8 i = qst_args[1].i;
    if (player != NULL) {
        qst_registers[i++].i = player->get_hpmax();
        qst_registers[i++].i = player->get_actor_hp();
        qst_registers[i++].i = player->get_tpmax();
        qst_registers[i].i = player->get_actor_tp();
    } else {
        qst_registers[i++].i = -1;
        qst_registers[i++].i = -1;
        qst_registers[i++].i = -1;
        qst_registers[i].i = -1;
    }
}

void qst_op_get_section_id() {
  uaddr player;
  u8 out_reg;
  player = ((uaddr)get_player_by_client_id((s32)((int) qst_args[0].i)));
  out_reg = (u8) qst_args[1].i;
  if (player != 0U)
  {
    qst_registers[out_reg].i = (volatile unsigned long)((TObjPlayer *)player)->get_section_id();
    return;
  }
  qst_registers[out_reg].i = -1;
}

void qst_op_gba_write_identifiers(void) {
    gba_set_identifiers((qst_args[0].i), (qst_args[1].i));
}

void qst_op_get_player_level(void) {
    u8 dest_reg;
    TObjPlayer *player;
    player = get_player_by_client_id(qst_args[0].i);
    dest_reg = (u8) qst_args[1].i;
    if (player != NULL) {
        qst_registers[dest_reg].i = player->get_actor_level_index() + 1;
        return;
    }
    qst_registers[dest_reg].i = -1;
}

void qst_op_get_slot_meseta(u8 i) {
    CharacterSaveRecord *w;
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        qst_registers[i].i = player->get_actor_meseta();
    } else {
        qst_registers[i].i = -1;
    }
    w = (CharacterSaveRecord *)get_character_save_record(0xFFFF);
    if (w != 0) {
        (&qst_registers[i].i)[1] = w->bank_meseta;
    } else {
        (&qst_registers[i].i)[1] = -1;
    }
}

void qst_op_get_guildcard_total(int a0) { qst_registers[(unsigned char)(a0)].i = TWindowSubComCard::count_active_cards(); }

void qst_op_get_time_played(s32 reg) {
    CharacterSaveRecord *character_save_record;
    character_save_record = (CharacterSaveRecord *)get_character_save_record(0xFFFFU);
    if (character_save_record != NULL) {
        qst_registers[(u8)reg].i = character_save_record->play_time;
        return;
    }
    qst_registers[(u8)reg].i = -1;
}
void qst_op_get_lang_setting(void) {
    qst_registers[qst_args[0].i].i = current_language;
}
void qst_op_wrap_item_with_color() {
    s32 id;
    s8 n;
    TObjPlayer *player;
    TItemData item;
    TItem *obj;
    id = ((s32 *)&qst_args)[0];
    n = ((s32 *)&qst_args)[1];
    obj = find_item_by_id(id);
    if (obj != NULL) {
        obj->copy_to_item_data(&item);
    } else {
        return;
    }
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        TObjPlayer::send_6x29_delete_item(player, (int)id, 1);
        item.set_wrapped();
        item.set_present_color(n);
        if (player->can_inventory_accept_item(&item) > 0) {
            player->request_inventory_item(&item);
        }
    }
}

void qst_op_wrap_item() {
    s32 id;
    TObjPlayer *player;
    TItemData item;
    TItem *obj;
    id = ((s32 *)&qst_args)[0];
    obj = find_item_by_id(id);
    if (obj != NULL) {
        obj->copy_to_item_data(&item);
    } else {
        return;
    }
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        TObjPlayer::send_6x29_delete_item(player, (int)id, 1);
        item.set_wrapped();
        if (player->can_inventory_accept_item(&item) > 0) {
            player->request_inventory_item(&item);
        }
    }
}

void qst_op_get_item_info() {
    s32 r;
    TItem *item;
    TItemData d;
    r = qst_args[1].i;
    item = find_item_by_id(qst_args[0].i);
    if (item != NULL) {
        item->copy_to_item_data(&d);
        qst_registers[r++].i = d.data1.data_u8[0];
        qst_registers[r++].i = d.data1.data_u8[1];
        qst_registers[r++].i = d.data1.data_u8[2];
        qst_registers[r++].i = d.data1.data_u8[3];
        qst_registers[r++].i = d.data1.data_u8[4];
        qst_registers[r++].i = d.data1.data_u8[5];
        qst_registers[r++].i = d.data1.data_u8[6];
        qst_registers[r++].i = d.data1.data_s8[7];
        qst_registers[r++].i = d.data1.data_u8[8];
        qst_registers[r++].i = d.data1.data_s8[9];
        qst_registers[r++].i = d.data1.data_u8[10];
        qst_registers[r++].i = d.data1.data_s8[11];
    } else {
        qst_registers[r].i = -1;
    }
}

void qst_op_item_delete_noreturn() {
    s32 item_index;
    TObjPlayer *player;

    item_index = qst_args[0].i;
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        TObjPlayer::send_6x29_delete_item(player, (int)item_index, 1);
    }
}

void qst_op_add_damage_to(void) {
    u16 client_id = qst_args[0].i;
    f32 damage = (f32)qst_args[1].i;
    new TQuestDamageTask(client_id, tl_03, damage);
}

void qst_op_gba_update_dl_graph(void) { gba_download_update_graph(); }

void qst_op_gba_destroy_dl_graph(void) { gba_download_destroy_graph(); }

void qst_op_gba_create_dl_graph(void) { gba_download_create_graph(); }

void qst_op_enable_movement2() {
    TObjPlayer *player = get_player_by_client_id((u16)qst_args[0].i);
    if (player != NULL) {
        player->init_local_pad_binding();
    }
}

void qst_op_disable_movement2() {
    TObjPlayer *player = get_player_by_client_id((u16)qst_args[0].i);
    if (player != NULL) {
        player->stop_force_if_alive();
    }
}
void qst_op_get_palettex_enabled(void) {
    u8 idx = qst_args[2].i;
    qst_registers[idx].i = is_palettex_enabled(qst_args[0].i);
}
void qst_op_get_palettex_activated(void) {
    u8 idx = qst_args[1].i;
    qst_registers[idx].i = is_palettex_activated(qst_args[0].i);
}

void qst_op_disable_palettex(void) {
    disable_palettex(((u16) qst_args[0].i));
}

void qst_op_restore_palettex(void) {
    restore_palettex(((u16) qst_args[0].i));
}

void qst_op_enable_palettex() {
    enable_palettex(((u16) qst_args[0].i));
}

void qst_op_activate_palettex() {
    activate_palettex(((u16) qst_args[0].i));
}
void qst_op_set_palettex_callback(void) {
    set_palettex_callback(qst_args[0].i, (u16)qst_args[1].i);
}

void qst_op_thaw_and_show_equip() {
    TObject *players = tl_03;
    if (players != NULL) {
        players->resume_update();
    }
}

void qst_op_toggle_freeze_and_hide_equip() {
    TObject *players = tl_03;
    if (players != NULL) {
        players->toggle_pause();
    }
}
void qst_op_get_stackable_item_count(s32 i, s32 dst) {
    u16 a = qst_registers[(u8)i++].i;
    u8 b = qst_registers[(u8)i++].i;
    u8 c = qst_registers[(u8)i++].i;
    u8 d = qst_registers[(u8)i].i;
    TObjPlayer *player = get_player_by_client_id(a);
    if (player != NULL) {
        qst_registers[(u8)dst].i = player->count_items_of_type(b, c, d);
    }
}

void qst_op_get_total_deaths() {
    u8 dest_reg;
    dest_reg = (u8) qst_args[1].i;
    TObjPlayer *player = get_player_by_client_id(qst_args[0].i);
    if (player != NULL) {
        qst_registers[dest_reg].i = player->get_total_deaths();
    }
}

void qst_op_atan2_int(void) {
    u8 dest_reg;
    dest_reg = (u8) qst_args[0].i;
    qst_registers[dest_reg].i = (s32) (10430.38043493439 * atan2_float(qst_args[1].f, qst_args[2].f));
}

void qst_op_tan() {
  s32 arg;
  u8 idx;
  idx = qst_args[0].i & 0xFFu;
  arg = qst_args[1].i;
  f32 v = sin_table_lookup(arg) / cos_table_lookup(arg);
  qst_registers[idx].i = *(s32 *)&v;
}

void qst_op_cos() {
    u8 idx = qst_args[0].i;
    f32 v = cos_table_lookup(qst_args[1].i);
    qst_registers[idx].i = *(s32 *)&v;
}

void qst_op_sin() {
    u8 idx = qst_args[0].i;
    f32 v = sin_table_lookup(qst_args[1].i);
    qst_registers[idx].i = *(s32 *)&v;
}

void qst_op_fdivi(u8 reg, s32 val) {
    IntFloat b;
    IntFloat a;
    a.i = val;
    b.f = qst_registers[reg].f;
    b.f /= a.f;
    qst_registers[reg].i = b.i;
}

void qst_op_fdiv(u8 reg, u8 src) {
    IntFloat b;
    b.f = qst_registers[reg].f;
    b.f /= qst_registers[src].f;
    qst_registers[reg].i = b.i;
}

void qst_op_fmuli(u8 reg, s32 val) {
    IntFloat b;
    IntFloat a;
    a.i = val;
    b.f = qst_registers[reg].f;
    b.f *= a.f;
    qst_registers[reg].i = b.i;
}

void qst_op_fmul(u8 reg, u8 src) {
    IntFloat b;
    b.f = qst_registers[reg].f;
    b.f *= qst_registers[src].f;
    qst_registers[reg].i = b.i;
}

void qst_op_fsubi(u8 reg, s32 val) {
    IntFloat b;
    IntFloat a;
    a.i = val;
    b.f = qst_registers[reg].f;
    b.f -= a.f;
    qst_registers[reg].i = b.i;
}

void qst_op_fsub(u8 reg, u8 src) {
    IntFloat b;
    b.f = qst_registers[reg].f;
    b.f -= qst_registers[src].f;
    qst_registers[reg].i = b.i;
}

void qst_op_faddi(u8 reg, s32 val) {
    IntFloat b;
    IntFloat a;
    a.i = val;
    b.f = qst_registers[reg].f;
    b.f += a.f;
    qst_registers[reg].i = b.i;
}

void qst_op_fadd(u8 reg, u8 src) {
    IntFloat b;
    b.f = qst_registers[reg].f;
    b.f += qst_registers[src].f;
    qst_registers[reg].i = b.i;
}

void qst_op_float2dec(s32 dst, s32 src) {
    qst_registers[(u8)dst].i = (s32) qst_registers[(u8)src].f;
}

void qst_op_dec2float(u8 reg, u8 src) {
    IntFloat b;
    b.f = (f32)qst_registers[src].i;
    qst_registers[reg].i = b.i;
}

void qst_op_check_npc_straggle_ex(u8 i, u8 slot) {
    u8 start = i;
    Vec v;
    ObjectSetData s;
    TObjQuestColApcINW *obj;

    init_object_set_data(&s);
    s.position.x = qst_registers[i++].i;
    s.position.y = qst_registers[i++].i;
    s.position.z = qst_registers[i++].i;
    s.scale.x = qst_registers[i++].i;
    s.set_params[0] = qst_registers[i++].i;
    s.scale.y = qst_registers[i++].i;
    obj = TLobby::create_quest_col_apc_inw(&s, &qst_registers[start].i);
    if (obj != NULL) {
        v.x = qst_registers[i++].i;
        v.y = qst_registers[i++].i;
        v.z = qst_registers[i].i;
        set_quest_col_warp_position(obj, &v);
        qst_registers[slot].i = obj->get_entity_id();
    }
}

void qst_op_set_obj_param_ex(u8 i, u8 out) {
    ObjectSetData s;
    TObjQuestColALock *obj;
    init_object_set_data(&s);
    s.position.x = qst_registers[i++].i;
    s.position.y = qst_registers[i++].i;
    s.position.z = qst_registers[i++].i;
    s.scale.x = qst_registers[i++].i;
    s.set_params[0] = qst_registers[i++].i;
    s.scale.y = qst_registers[i].i;
    obj = create_quest_col_alock(&s, &qst_registers[out].i);
    if (obj != NULL) {
        qst_registers[out].i = obj->get_entity_id();
    }
}

void qst_op_party_coords_call_ex(u8 i, u8 out) {
    ObjectSetData s;
    TObjQuestColApcIN *obj;
    u8 first = i;
    init_object_set_data(&s);
    s.position.x = qst_registers[i++].i;
    s.position.y = qst_registers[i++].i;
    s.position.z = qst_registers[i++].i;
    s.scale.x = qst_registers[i++].i;
    s.scale.y = qst_registers[i++].i;
    s.set_params[0] = qst_registers[i].i;
    obj = create_quest_col_apc_in(&s, &qst_registers[first].i);
    if (obj != NULL) {
        qst_registers[out].i = obj->get_entity_id();
    }
}

void qst_op_npc_coords_call_ex(u8 i, u8 out) {
    ObjectSetData s;
    TObjQuestColApc *obj;
    u8 first = i;
    init_object_set_data(&s);
    s.position.x = qst_registers[i++].i;
    s.position.y = qst_registers[i++].i;
    s.position.z = qst_registers[i++].i;
    s.scale.x = qst_registers[i++].i;
    s.set_params[0] = qst_registers[i].i;
    obj = create_quest_col_apc(&s, &qst_registers[first].i);
    if (obj != NULL) {
        qst_registers[out].i = obj->get_entity_id();
    }
}

void qst_op_at_coords_talk_ex(u8 i, u8 out) {
    ObjectSetData s;
    TObjQuestColA *obj;
    u8 first = i;
    init_object_set_data(&s);
    s.position.x = qst_registers[i++].i;
    s.position.y = qst_registers[i++].i;
    s.position.z = qst_registers[i++].i;
    s.scale.x = qst_registers[i++].i;
    s.set_params[0] = qst_registers[i].i;
    obj = create_quest_col_a(&s, &qst_registers[first].i);
    if (obj != NULL) {
        qst_registers[out].i = obj->get_entity_id();
    }
}

void qst_op_at_coords_call_ex(u8 i, u8 out) {
    ObjectSetData s;
    TObjQuestCol *obj;
    u8 first = i;
    init_object_set_data(&s);
    s.position.x = qst_registers[i++].i;
    s.position.y = qst_registers[i++].i;
    s.position.z = qst_registers[i++].i;
    s.scale.x = qst_registers[i++].i;
    s.set_params[0] = qst_registers[i].i;
    obj = create_quest_col(&s, &qst_registers[first].i);
    if (obj != NULL) {
        qst_registers[out].i = obj->get_entity_id();
    }
}

void qst_op_unfreeze_everything(void) {
    main_task.resume_game_layers();
}

void qst_op_toggle_freeze_everything(void) {
    main_task.toggle_pause_game_layers();
}

void qst_op_unfreeze_enemies() {
    TObject *enemies = tl_04;
    if (enemies != NULL) {
        enemies->resume_update();
    }
}

void qst_op_toggle_freeze_enemies() {
    TObject *enemies = tl_04;
    if (enemies != NULL) {
        enemies->toggle_pause();
    }
}

void qst_op_npc_text_id(u8 a0, u8 a1, void *a2) {
    s32 x = qst_registers[a0].i;
    s32 v = qst_registers[a1].i;
    u16 y = x;
    uaddr r = ((u32 (*)(void *, int))qst_label_address)(a2, x);
    if (r != 0U) {
        set_partner_dialogue_override((const char *)r, v, y);
    }
}

void qst_op_compute_bezier_curve_point() {
    Vec v;
    ComputeBezierCurvePointGlobals *g = (ComputeBezierCurvePointGlobals *)qst_args;
    s32 count = g->count;
    f32 scale = g->scale;
    f32 step = g->step;
    s32 closed = g->closed;
    s32 out = g->out;
    CurvePathPoint *pts;
    s32 i;
    s32 ret;
    s32 j;
    Vec *dst;
    pts = (CurvePathPoint *)qst_label_address((u16)g->id);
    if (pts == NULL) {
        return;
    }
    for (i = 0; i < count; i++) {
        pts[i].bswap();
    }
    ret = compute_bezier_curve_point(pts, scale, count, step, closed, &v, 100);
    dst = (Vec *)&qst_registers[out].i;
    dst->x = v.x;
    dst->y = v.y;
    dst->z = v.z;
    *(s32 *)&((f32 *)qst_registers)[out + 3] = ret;
    for (j = 0; j < count; j++) {
        pts[j].bswap();
    }
    return;
}

void qst_op_get_vector_from_path() {
    Vec v;
    GetVectorFromPathGlobals *g = (GetVectorFromPathGlobals *)qst_args;
    s32 count = g->count;
    f32 scale = g->scale;
    f32 step = g->step;
    s32 closed = g->closed;
    s32 out = g->out;
    CurvePathPoint *pts;
    s32 i;
    s32 ret;
    s32 j;
    Vec *dst;
    pts = (CurvePathPoint *)qst_label_address((u16)g->id);
    if (pts == NULL) {
        return;
    }
    for (i = 0; i < count; i++) {
        pts[i].bswap();
    }
    ret = get_vector_from_path(pts, scale, count, step, closed, &v);
    dst = (Vec *)&qst_registers[out].i;
    dst->x = v.x;
    dst->y = v.y;
    dst->z = v.z;
    *(s32 *)&((f32 *)qst_registers)[out + 3] = ret;
    for (j = 0; j < count; j++) {
        pts[j].bswap();
    }
    return;
}

void qst_op_get_pressed_buttons(u8 a0, u8 a1) {
    qst_registers[a1].i = controller_input_state.controllers[qst_registers[a0].i].pressed_buttons;
}

void qst_op_get_held_buttons(u8 src, u8 dst) {
    qst_registers[dst].i = controller_input_state.controllers[qst_registers[src].i].buttons;
}

void qst_op_default_camera_pos2(void* p) { reset_camera_to_local_player(); }

void qst_op_fleti_locked_camera(void) {
    Vec *p = (Vec *)(qst_registers + qst_args[1].i);
    Vec v;
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    set_locked_camera_override(&v, qst_args[0].i);
}

void qst_op_fleti_fixed_camera() {
    Vec a;
    Vec b;
    Vec *p = (Vec *)(qst_registers + qst_args[0].i);
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
    v.x = qst_registers[(u8)k++].i;
    v.y = qst_registers[(u8)k++].i;
    v.z = qst_registers[(u8)k].i;
    TObjQuestColBase *trigger = TQuestColCtrl::find_by_id((u16)qst_registers[(u8)i].i);
    if (trigger != NULL) {
        trigger->set_position_from(&v);
    }
}

void qst_op_close_chat_bubble(s32 reg) {
    TWindowCtrl::close_windows_by_flags(qst_registers[(u8)reg].i);
}

void qst_op_set_screen_bw() { set_screen_bw(); }

void qst_op_set_motion_blur() { set_camera_capture_overlay_alpha(143); }

void qst_op_restore_tp(s32 reg) {
    apply_player_slot_status(qst_registers[(u8)reg].i, 0xB);
}

void qst_op_restore_hp(s32 reg) {
    apply_player_slot_status(qst_registers[(u8)reg].i, 0xA);
}

void qst_op_set_slot_zalure(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg].i, 9);
}

void qst_op_set_slot_jellen(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg].i, 8);
}

void qst_op_set_slot_deband(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg].i, 7);
}

void qst_op_set_slot_shifta(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg].i, 6);
}

void qst_op_set_slot_confuse(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg].i, 5);
}

void qst_op_set_slot_slow(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg].i, 4);
}

void qst_op_set_slot_freeze(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg].i, 3);
}

void qst_op_set_slot_shock(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg].i, 2);
}

void qst_op_set_slot_paralyze(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg].i, 1);
}

void qst_op_set_slot_poison(s32 slot_reg) {
    apply_player_slot_status(qst_registers[(u8)slot_reg].i, 0);
}

void qst_op_clear_slot_invincible(s32 slot_reg) {
    reset_player_lobby_model(qst_registers[(u8)slot_reg].i);
}

void qst_op_set_slot_invincible(s32 slot_reg, s32 value_reg) {
    update_player_field(qst_registers[(u8)slot_reg].i, qst_registers[(u8)value_reg].i);
}

void qst_op_run_to_coord(u8 regs) {
    RunToCoordMove m;
    f32 x;
    f32 z;
    u16 id;
    s32 i;

    i = regs;
    x = qst_registers[i++].i;
    i++;
    z = qst_registers[i++].i;
    id = qst_registers[i].i;
    if (get_player_by_client_id(id) != 0) {
        ((G_MoveToPosition_6x41_6x42 *)&m)->init();
        m.id = id;
        m.x = x;
        m.z = z;
        ((G_MoveToPosition_6x41_6x42 *)&m)->send();
    }
}

void qst_op_stop_animation(s32 reg) {
    end_camera_pan_for_client(qst_registers[(u8)reg].i);
}

void qst_op_use_animation(s32 slot_reg, s32 anim_reg) {
    apply_to_battle_player_slot(qst_registers[(u8)slot_reg].i, qst_registers[(u8)anim_reg].i);
}
void TLobby::reset_random_enemies_mode(TObject *) { TLobby::clear_counter(); evt2_random_enemies_mode = 0; set_keyboard_input_flag(); }

void qst_op_qexit() {
    if (is_quest_active() == 1) {
        new TScreenFadeOut(tl_00, TLobby::reset_random_enemies_mode);
    }
}

void qst_op_results_window_visible_multi_cm(s32 reg) {
    if (update_challenge_result_player_locks() != 0) {
        qst_registers[(u8)reg].i = 1;
        return;
    }
    qst_registers[(u8)reg].i = 0;
}

void qst_op_congrats_msg_multi_cm(u8 reg) {
    s32 i;
    TChallenge4PResult::clear_slot_entries();
    i = 0;
    do {
        TChallenge4PResult::create((u16)i, qst_registers[reg].i);
        i += 1;
    } while (i < 4);
}

void qst_op_start_or_update_gba_joyboot(s32 idx) {
    s32 tbl[5];
    s32 n;
    *(StartOrUpdateGbaJoybootTable *)tbl = lobby_index_identity_table_a;
    update_gba_joyboot_transfer();
    n = get_gba_download_state();
    if (n >= 0 && n < 5) {
        qst_registers[(u8)idx].i = tbl[n];
    } else {
        qst_registers[(u8)idx].i = 2;
    }
}

void qst_op_prepare_gba_rom_from_download() { ((TLobby *)0)->update_alloc_size(); gba_joyboot_set_send_buffer(gba_download_data_buffer, static_cast<s32>(gba_download_data_size)); }

void qst_op_get_dl_status(s32 reg) {
    if (TLobby::get_lobby_count() != 0) {
        qst_registers[(u8)reg].i = 0;
        return;
    }
    if (TLobby::is_warning_aram_load_done() != 0) {
        qst_registers[(u8)reg].i = 2;
        return;
    }
    qst_registers[(u8)reg].i = 1;
}

void qst_op_file_dl_req(void) {
    TLobby::protocol_instance->send_download_head(qst_args[0].i, (const char *)qst_args[1].i);
    clear_lobby_count();
    reset_warning_aram_cache();
}

void qst_op_set_episode(s32 episode) {
    switch (episode) {
    case 0:
        select_episode(0);
        return;
    case 1:
        select_episode(1);
        return;
    default:
        select_episode(0);
        return;
    }
}

void qst_op_write_flag_buf_to_event_flags2(u8 reg) { qst_op_write_flag_buf_to_event_flags(reg); }

void qst_op_load_guild_card_file_creation_time_to_flag_buf() {
    s32 creation_time;
    void *state;

    state = (void *)(saddr)TAdSinglePlyChrSelectGC::get_state();
    if (state != NULL) {
        creation_time = *(s32 *)((s8 *)state + 0xE284);
    } else {
        creation_time = 0;
    }
    qst_flag_buf = creation_time;
}

void qst_op_chl_show_dead_player_list() {
    if (is_split_screen() == 1) {
        update_screen();
        return;
    }
    show_challenge_dead_player_list();
}

void qst_op_disable_retry_menu() {
    if (is_split_screen() == 1) {
        set_challenge_split_flag();
        return;
    }
    disable_challenge_retry_menu();
}

void qst_op_chl_set_min_time_online(s32 reg) {
    if (is_split_screen() == 1) {
        challenge_set_min_clear_time((qst_registers[(u8)reg].i));
        return;
    }
    set_challenge_min_clear_time((int) (qst_registers[(u8)reg].i));
}

void qst_op_check_for_hacking(u8 out) {
    u32 *p;
    s16 i;
    TObjPlayer *player;
    qst_registers[out].i = 0;
    p = (u32 *)0x8C007220;
    for (i = 0; i < 0xC0U; i++) {
        if (*p++ != 0) {
            qst_registers[out].i |= 1;
        }
    }
    if (quest_hack_check_a_stub() == 1) {
        qst_registers[out].i |= 2;
    }
    if (quest_hack_check_b_stub() == 1) {
        qst_registers[out].i |= 4;
    }
    if (get_drop_flag() == 1) {
        qst_registers[out].i |= 8;
    }
    player = get_player_by_client_id(local_client_id);
    if (player != NULL && static_cast<u32>(player->pending_actions.get_bits()) != 0) {
        qst_registers[out].i |= 0x10;
    }
}

void qst_op_write4(void) {
    *((s32 *)qst_args[0].p) = qst_args[1].i;
}

void qst_op_write2(void) {
    *((s16 *)qst_args[0].p) = (s16) qst_args[1].i;
}

void qst_op_write1(void) {
    *((s8 *)qst_args[0].p) = (s8) qst_args[1].i;
}

void qst_op_read4(void) {
    qst_registers[(u8)qst_args[0].i].i = *(s32 *)((s8 *)(((s32 *)qst_args[1].p)) + 0);
}

void qst_op_read2(void) {
    qst_registers[(u8)qst_args[0].i].i = (s32) *(s16 *)((s8 *)(((s16 *)qst_args[1].p)) + 0);
}

void qst_op_read1() {
    qst_registers[(u8)qst_args[0].i].i = (s32) (s8) *(u8 *)((s8 *)(((u8 *)qst_args[1].p)) + 0);
}

void qst_op_someone_has_spoken(s32 reg) {
    if (strcmp(get_chat_last_line(), "") == 0) {
        qst_registers[(u8)reg].i = 0;
        return;
    }
    qst_registers[(u8)reg].i = 1;
}

void qst_op_party_has_name(s32 reg) {
    if (strcmp(get_lobby_name(), "") == 0) {
        qst_registers[(u8)reg].i = 0;
        return;
    }
    qst_registers[(u8)reg].i = 1;
}

void qst_op_get_number_of_players2(int a0) { qst_registers[(unsigned char)(a0)].i = TLobby::get_game_mode(); }
void qst_op_get_cmode_prize_rank(s32 reg) {
    CharacterSaveRecord *record;

    record = (CharacterSaveRecord *)get_character_save_record(0xFFFF);
    if (record != NULL) {
        qst_registers[(u8)reg].i = decode_challenge_count(challenge_set_rank(&record->challenge, RECORD_SET_CURRENT)->rank);
    }
}

void qst_op_get_ba_record(u8 i) {
    CharacterSaveRecord *card = (CharacterSaveRecord *)get_character_save_record(0xFFFF);
    if (card != NULL) {
        qst_registers[i++].i = card->online_battle.place_counts[0];
        qst_registers[i++].i = card->online_battle.place_counts[1];
        qst_registers[i++].i = card->online_battle.place_counts[2];
        qst_registers[i++].i = card->online_battle.place_counts[3];
        qst_registers[i++].i = card->online_battle.disconnect_count;
        qst_registers[i++].i = card->online_battle.reserved_counts[0];
        qst_registers[i].i = card->online_battle.reserved_counts[1];
    }
}

void qst_op_is_there_grave_message(s32 reg) {
    CharacterSaveRecord *record;
    record = (CharacterSaveRecord *)get_character_save_record(0xFFFFU);
    if (record != NULL) {
        if (strncmp(record->challenge.tombstone.unit_name, "", 0x20) == 0) {
            qst_registers[(u8)reg].i = 0;
            return;
        }
        qst_registers[(u8)reg].i = 1;
        return;
    }
    qst_registers[(u8)reg].i = 0;
}

void qst_op_vol_opt_is_dead(s32 reg) {
    if ((s32) volopt_death_active != 0) {
        qst_registers[(u8)reg].i = 1;
        return;
    }
    qst_registers[(u8)reg].i = 0;
}

void qst_op_ba_death_tech_level_up(void) {
    if ((u32)qst_args[0].i <= 0x1DU) {
        battle_rules.death_tech_level_up = (s16) (u32)qst_args[0].i;
    }
}

void qst_op_set_shrink_size(s32 player_variable, saddr size_variable) {
    TObjPlayer* player = get_player_by_client_id(qst_registers[(u8)player_variable].i);
    if (player && !player->obj_isState2_324()) {
        s32 whole = qst_registers[(u8)size_variable++].i;
        s32 numerator = qst_registers[(u8)size_variable++].i;
        s32 denominator = qst_registers[(u8)size_variable].i;
        player->scale_state.set_scalar(denominator > 0 ? (f32)whole + (f32)numerator / (f32)denominator : (f32)whole);
    }
}

void qst_op_set_symbol_chat_collision(u8 i) {
    ObjectSetData s;
    init_object_set_data(&s);
    s.position.x = qst_registers[i++].i;
    s.position.y = qst_registers[i++].i;
    s.position.z = qst_registers[i++].i;
    s.scale.x = qst_registers[i++].i;
    s.set_params[0] = qst_registers[i++].i;
    s.set_params[1] = qst_registers[i++].i;
    s.set_params[2] = qst_registers[i++].i;
    symbolchat_colli_param_table[0] = qst_label_address((u16)qst_registers[i++].i);
    symbolchat_colli_param_table[1] = qst_label_address((u16)qst_registers[i++].i);
    symbolchat_colli_param_table[2] = qst_label_address((u16)qst_registers[i].i);
    TOSymbolchatColli::create(&s);
    symbolchat_colli_param_table[1] = 0;
    symbolchat_colli_param_table[0] = 0;
    symbolchat_colli_param_table[2] = 0;
}

void qst_op_set_chat_callback_no_filter(u8 i) {
    ObjectSetData s;
    init_object_set_data(&s);
    s.rotation[0] = 0;
    s.rotation[1] = 1;
    s.position.x = qst_registers[i++].i;
    s.position.y = qst_registers[i++].i;
    s.position.z = qst_registers[i++].i;
    s.scale.x = qst_registers[i++].i;
    s.set_params[0] = qst_registers[i].i;
    TOChatSensor::create(&s);
}

void qst_op_write_flag_buf_to_event_flags(u8 reg) {
    s32 idx = qst_registers[reg].i;
    QuestEventFlagRecord *w = (QuestEventFlagRecord *)TAdSinglePlyChrSelectGC::get_global_state();
    if (w != NULL && idx >= 0 && idx < 0xFD) {
        move_data(((&w->event_flags[idx])), (&qst_flag_buf), 4);
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
        if (get_normalized_mode() != 0) {
            qst_registers[(u8)reg].i = 1;
            return;
        }
        qst_registers[(u8)reg].i = 0;
        return;
    }
    if (is_challenge_boss_warp_disabled() != 0) {
        qst_registers[(u8)reg].i = 1;
        return;
    }
    qst_registers[(u8)reg].i = 0;
}

void qst_op_enable_bosswarp_option() {
    if (is_split_screen() == 1) {
        challenge_set_boss_warp_disabled(0);
        return;
    }
    set_challenge_boss_warp_disabled(0);
}

void qst_op_disable_bosswarp_option() {
    if (is_split_screen() == 1) {
        challenge_set_boss_warp_disabled(1);
        return;
    }
    set_challenge_boss_warp_disabled(1);
}

void qst_op_player_recovery(s32 reg) {
    TObjPlayer *player;
    player = get_player_by_client_id(qst_registers[(u8)reg].i);
    if (player != NULL) {
        player->send_use_medical_center();
        player->send_medical_center_revive_all_players();
    }
}

void qst_op_ba_forbid_scape_dolls() {
    u32 v = (u32)qst_args[0].i;
    if (v < 2) {
        battle_rules.forbid_scape_dolls = forbid_scape_dolls_values[v];
    }
}

void qst_op_chl_create_retry_menu() {
    if (is_split_screen() == 1) {
        draw_if_ready2();
        return;
    }
    create_challenge_retry_menu();
}

void qst_op_get_chl_retry_choice(s32 reg) {
    s32 retry_choice;
    if (is_split_screen() == 1) {
        retry_choice = check_ready_status();
    } else {
        retry_choice = get_challenge_retry_choice();
    }
    switch (retry_choice) {
    case -1:
        qst_registers[(u8)reg].i = 0;
        return;
    case 0:
        qst_registers[(u8)reg].i = 1;
        return;
    case 1:
        qst_registers[(u8)reg].i = 2;
        return;
    }
}

void qst_op_reset_map(void) {
    reset_map();
    if (quest_mission_manager != NULL) {
        TQuestThread::clear_buffer(quest_mission_manager);
    }
    TQuestThread::destroy_all_in(tl_00);
    init_sub_objects();
    reset_id_tables();
    clear_floor_event_flags();
    init_switch_table();
    TRaderMapCore::free_map_data();
    if (is_split_screen() == 1) {
        reset_menu_state_globals();
        return;
    }
    reset_challenge_map();
}

void qst_op_get_random(s32 regs, s32 dst) {
  s32 min_value;
  s32 value;
  s32 span;
  min_value = qst_registers[(u8)regs].i;
  span = qst_registers[(u8)(regs + 1)].i;
  value = (s32) (((f32) span) * (3.0517578125e-05f * ((f32) rand())));
  if (value < min_value)
  {
    value = min_value;
  }
  qst_registers[(u8)dst].i = value;
}

void qst_op_shift_right(s32 dst, s32 src) {
    qst_registers[(u8)dst].i >>= qst_registers[(u8)src].i;
}

void qst_op_shift_left(s32 dst, s32 src) {
    qst_registers[(u8)dst].i <<= qst_registers[(u8)src].i;
}

void qst_op_get_eventflag32(u8 a0, u8 a1) {
    s32 v;
    qst_registers[a1].i = 0;
    QuestEventFlagRecord *w = ((QuestEventFlagRecord *)TAdSinglePlyChrSelectGC::get_global_state());
    if (w != NULL) {
        s32 i = qst_registers[a0].i;
        if (i >= 0 && i < 0xFD) {
            memcpy(&v, &w->event_flags[i], 4);
            qst_registers[a1].i = v;
        }
    }
}

void qst_op_get_eventflag16(u8 a0, u8 a1) {
    s16 v;
    qst_registers[a1].i = 0;
    QuestEventFlagRecord *w = ((QuestEventFlagRecord *)TAdSinglePlyChrSelectGC::get_global_state());
    if (w != NULL) {
        s32 i = qst_registers[a0].i;
        if (i >= 0 && i < 0xFF) {
            memcpy(&v, &w->event_flags[i], 2);
            qst_registers[a1].i = v;
        }
    }
}

void qst_op_set_enemy_movement_data(s32 label) {
    BattleMovementParams params;
    const BattleMovementParams *data;
    data = (const BattleMovementParams *)qst_label_address(label);
    if (data != NULL) {
        params = *data;
        params.bswap();
        set_enemy_movement_data(&params);
    }
}

void qst_op_set_enemy_resist_data(s32 label) {
    const ActorParamBlock *data;
    data = (const ActorParamBlock *)qst_label_address(label);
    if (data != NULL) {
        ActorParamBlock params = *data;
        params.swap_endian();
        set_enemy_resist_data(&params);
    }
}

void qst_op_set_enemy_attack_data(s32 label) {
    const AttackParams *data;
    data = (const AttackParams *)qst_label_address(label);
    if (data != NULL) {
        AttackParams params = *data;
        params.byteswap_packet();
        set_enemy_attack_data(&params);
    }
}

void qst_op_set_enemy_physical_data(int label) {
    const player_stats *data;
    data = (const player_stats *)qst_label_address(label);
    if (data != NULL) {
        player_stats stats = *data;
        stats.bswap();
        set_enemy_physical_data(&stats);
    }
}

void qst_op_set_override_enemy_bp_index() {
    set_override_enemy_bp_index(qst_args[0].i);
}

void qst_op_set_chat_callback() {
    ObjectSetData s;
    u8 i = (u32)qst_args[0].i;
    saddr arg = qst_args[1].i;
    TOChatSensor *sensor;
    init_object_set_data(&s);
    s.position.x = qst_registers[i++].i;
    s.position.y = qst_registers[i++].i;
    s.position.z = qst_registers[i++].i;
    s.scale.x = qst_registers[i++].i;
    s.set_params[0] = qst_registers[i].i;
    sensor = static_cast<TOChatSensor *>(TOChatSensor::create(&s));
    if (sensor != NULL) {
        sensor->set_trigger_text((void *)arg);
    }
}

void qst_op_set_cmode_grave_rates(s32 reg) {
    TObjTombstoneDropRates rates;
    s32 *p = &qst_registers[(u8)reg].i;
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
        qst_registers[(u8)reg].i = challenge_get_time_record();
        return;
    }
    qst_registers[(u8)reg].i = get_challenge_time_record();
}

void qst_op_chl_set_timerecord(s32 reg) {
    if (is_split_screen() == 1) {
        challenge_set_time_record((qst_registers[(u8)reg].i));
        return;
    }
    set_challenge_time_record((int) (qst_registers[(u8)reg].i));
}

void qst_op_get_game_version(s32 reg) {
    qst_registers[(u8)reg].i = 3;
}

void qst_op_send_mail(void) {
    u8 i = (u32)qst_args[0].i;
    char *src = ((char *)qst_args[1].p);
    TChatMessage mail;
    char buf[0x400];
    TTokenList *fields;
    fields = new TTokenList(NULL, 0, 0);
    strncpy(buf, src, 0x3FF);
    trim_whitespace(buf);
    fields->tokenize_args(buf);
    if (fields->count > 2) {
        delete fields;
    } else {
        mail.tag.m_guildcard_number = qst_registers[i].i;
        strncpy(mail.name, fields->tokens[0], 0xF);
        mail.name[0xF] = 0;
        strncpy(mail.text, fields->tokens[1], 0x1FF);
        mail.text[0x1FF] = 0;
        receive_short_mail(mail);
        delete fields;
    }
}

TChatMessage::TChatMessage() {}

void qst_op_get_player_state(s32 slot_reg, saddr dst) {
    TObjPlayer *player;
    player = get_player_by_client_id(qst_registers[(u8)slot_reg].i);
    if (player != NULL) {
        if (test_player_action_2(player) != 0) {
            qst_registers[(u8)dst].i = 1;
            return;
        }
        if (player->test_action_4() != 0) {
            qst_registers[(u8)dst].i = 2;
            return;
        }
        if (player->test_flag_16() != 0) {
            qst_registers[(u8)dst].i = 3;
            return;
        }
        if (test_player_action_E0(player) != 0) {
            qst_registers[(u8)dst].i = 4;
            return;
        }
        if (test_player_action_100(player) != 0) {
            qst_registers[(u8)dst].i = 5;
            return;
        }
        if (test_player_action_200(player) != 0) {
            qst_registers[(u8)dst].i = 6;
            return;
        }
        if (test_player_action_400(player) != 0) {
            qst_registers[(u8)dst].i = 7;
            return;
        }
        if (player->check_flag_24576() != 0) {
            qst_registers[(u8)dst].i = 8;
            return;
        }
        if (player->test_action_8000() != 0) {
            qst_registers[(u8)dst].i = 9;
            return;
        }
        if (test_player_action_10000(player) != 0) {
            qst_registers[(u8)dst].i = 0xA;
            return;
        }
        if (player->test_action_40000() != 0) {
            qst_registers[(u8)dst].i = 0xB;
            return;
        }
        if (player->test_action_80000() != 0) {
            qst_registers[(u8)dst].i = 0xC;
            return;
        }
        qst_registers[(u8)dst].i = 0;
        return;
    }
    qst_registers[(u8)dst].i = 0;
}

void qst_op_disable_win_pfx(void) { battle_ctrl_default_value = 0; }

void qst_op_enable_win_pfx(void) { battle_ctrl_default_value = 1; }

void qst_op_ba_get_score(u8 src, u8 dst) {
    BattleRanking e = duel_result_table[qst_registers[src].i];
    qst_registers[dst].i = e.score;
}

void qst_op_ba_get_place(u8 a0, u8 a1) {
    BattleRanking e = duel_result_table[qst_registers[a0].i];
    qst_registers[a1].i = e.place;
}

void qst_op_set_eventflag32() {
    u32 i = (u32)qst_args[0].i;
    s32 v = qst_args[1].i;
    QuestEventFlagRecord *w = (QuestEventFlagRecord *)TAdSinglePlyChrSelectGC::get_global_state();
    if (w != NULL && i < 0xFD) {
        move_data(((&w->event_flags[i])), (&v), 4);
    }
}

void qst_op_turn_on_bgm_p2() { turn_on_bgm_p2(); }

void qst_op_turn_off_bgm_p2() { turn_off_bgm_p2(); }

void qst_op_nop_F8EF(void) {  }

void qst_op_call_image_data() {
    s32 size;
    void *source_data;
    size = qst_args[0].i;
    source_data = qst_label_address((u16)qst_args[1].i);
    if (source_data != NULL) {
        prs_decompress_buffer(source_data, resource_decompress_buffer);
        load_sin_board_image(resource_decompress_buffer, size);
    }
}

void qst_op_animation_check(s32 slot_reg, s32 dst) {
    u8 *motion;
    motion = (u8 *)get_player_by_client_id((u16)qst_registers[(u8)slot_reg].i);
    if (motion != NULL) {
        qst_registers[(u8)dst].i = ((TObjMotion *)motion)->is_motion_held();
    }
}

void qst_op_set_eventflag16() {
    u32 i = (u32)qst_args[0].i;
    s16 v = qst_args[1].i;
    QuestEventFlagRecord *w = (QuestEventFlagRecord *)TAdSinglePlyChrSelectGC::get_global_state();
    if (w != NULL && i < 0xFF) {
        move_data(((&w->event_flags[i])), (&v), 2);
    }
}

void qst_op_get_pl_job(s32 reg) {
    TObjPlayer *player;
    player = get_player_by_client_id(qst_registers[(u8)reg].i);
    if (player != NULL) {
        strncpy(quest_player_class_name_buffer, (const char *)(get_class_type_name((int) (player->appearance.classFlags))), 0xF);
        quest_player_class_name_buffer[0xF] = 0;
        qst_registers[(u8)reg].i = 1;
        return;
    }
    qst_registers[(u8)reg].i = 0;
}

void qst_op_get_pl_name(s32 reg) {
    TObjPlayer *player;
    player = get_player_by_client_id(qst_registers[(u8)reg].i);
    if (player != NULL) {
        strncpy(quest_player_name_buffer, player->get_name(), 0xF);
        quest_player_name_buffer[0xF] = 0;
        qst_registers[(u8)reg].i = 1;
        return;
    }
    qst_registers[(u8)reg].i = 0;
}

void qst_op_set_trap_damage(s32 i) {
    s32 j = i + 1;
    set_mine_trap_damage((f32)qst_registers[(u8)i].i + (f32)qst_registers[(u8)j].i / (f32)qst_registers[(u8)++j].i);
}

void qst_op_get_eventflag(s32 index_reg, s32 dst) {
    u8 *flags;
    QuestValue *regs;
    s32 index;
    flags = (u8 *)TAdSinglePlyChrSelectGC::get_global_state();
    if (flags != NULL) {
        regs = qst_registers;
        index = regs[(u8)index_reg].i;
        if (index >= 0 && index < 0x100) {
            regs[(u8)dst].i = flags[index + 0x10];
        }
    }
}

void qst_op_get_serial_number(u8 reg) {
    qst_registers[reg].i = TQuestVmDownLoadServer::get_serial_access();
    if (qst_registers[reg].i == 0) {
        qst_registers[reg].i = TQuestVmDownLoadServer::poll_serial_access();
    }
}
void qst_op_kill_player(s32 slot_reg) {
    TObjPlayer *player = get_player_by_client_id(qst_registers[(u8)slot_reg].i);
    if (player != NULL) {
        queue_player_kill(player);
    }
}

void qst_op_get_guild_card_file_creation_time(s32 reg) {
    u8 *state;
    state = (u8 *)(saddr)TAdSinglePlyChrSelectGC::get_state();
    if (state != NULL) {
        qst_registers[(u8)reg].i = *(s32 *)((s8 *)state + 0xE284);
        return;
    }
    qst_registers[(u8)reg].i = 0;
}

void qst_op_take_slot_meseta(s32 regs, s32 dst) {
    TObjPlayer *player = get_player_by_client_id(qst_registers[(u8)regs++].i);
    if (player != NULL) {
        if (player->try_spend_actor_meseta(qst_registers[(u8)regs].i) != 0) {
            qst_registers[(u8)dst].i = 1;
        } else {
            qst_registers[(u8)dst].i = 0;
        }
    } else {
        qst_registers[(u8)((u8)dst + 1)].i = 0;
    }
}

void qst_op_get_chara_class(s32 slot_reg, s32 dst) {
    TObjPlayer *player = get_player_by_client_id(qst_registers[(u8)slot_reg].i);
    if (player != NULL) {
        s32 f = player->appearance.classFlags;
        if (f & CLASS_FLAG_HUMAN) {
            qst_registers[(u8)dst].i = RACE_HUMAN;
        } else if (f & CLASS_FLAG_NEWMAN) {
            qst_registers[(u8)dst].i = RACE_NEWMAN;
        } else if (f & CLASS_FLAG_ANDROID) {
            qst_registers[(u8)dst].i = RACE_ANDROID;
        } else {
            qst_registers[(u8)dst].i = RACE_NONE;
        }
        if (f & CLASS_FLAG_HUNTER) {
            qst_registers[(u8)(dst + 1)].i = CLASS_TYPE_HUNTER;
        } else if (f & CLASS_FLAG_RANGER) {
            qst_registers[(u8)(dst + 1)].i = CLASS_TYPE_RANGER;
        } else if (f & CLASS_FLAG_FORCE) {
            qst_registers[(u8)(dst + 1)].i = CLASS_TYPE_FORCE;
        } else {
            qst_registers[(u8)(dst + 1)].i = CLASS_TYPE_NONE;
        }
    } else {
        qst_registers[(u8)dst++].i = RACE_NONE;
        qst_registers[(u8)dst].i = CLASS_TYPE_NONE;
    }
}

void qst_op_get_gender(s32 slot_reg, s32 dst) {
    s32 class_flags;
    TObjPlayer *player;
    player = get_player_by_client_id(qst_registers[(u8)slot_reg].i);
    if (player != NULL) {
        class_flags = player->appearance.classFlags;
        if (class_flags & CLASS_FLAG_MALE) {
            qst_registers[(u8)dst].i = GENDER_MALE;
            return;
        }
        if (class_flags & CLASS_FLAG_FEMALE) {
            qst_registers[(u8)dst].i = GENDER_FEMALE;
            return;
        }
        qst_registers[(u8)dst].i = GENDER_NONE;
        return;
    }
    qst_registers[(u8)dst].i = GENDER_NONE;
}

void qst_op_disable_techs(s32 slot_reg) {
    TObjPlayer *player = get_player_by_client_id(qst_registers[(u8)slot_reg].i);
    if (player != NULL) {
        player->technique_state.disable_techniques();
    }
}

void qst_op_enable_techs(s32 slot_reg) {
    TObjPlayer *player = get_player_by_client_id(qst_registers[(u8)slot_reg].i);
    if (player != NULL) {
        player->technique_state.enable_techniques();
    }
}

void qst_op_disable_stealth_suit_effect(s32 slot_reg) {
    TObjPlayer *player;
    player = get_player_by_client_id((int)(qst_registers[(u8)slot_reg].i));
    if ((player != NULL) && (player->is_local_or_split_screen() != 0)) {
        player->send_disable_stealth_suit_effect();
    }
}

void qst_op_enable_stealth_suit_effect(s32 slot_reg) {
    TObjPlayer *player;
    player = get_player_by_client_id((int)(qst_registers[(u8)slot_reg].i));
    if ((player != NULL) && (player->is_local_or_split_screen() != 0)) {
        player->send_enable_stealth_suit_effect();
    }
}

void qst_op_set_cmode_rank_override(void) {
    char buf[0x200];
    TTokenList *fields;
    s32 arg = (u32)qst_args[0].i;
    char *src = ((char *)qst_args[1].p);
    fields = new TTokenList(NULL, 0, 0);
    strncpy(buf, src, 0x1FF);
    trim_whitespace(buf);
    fields->tokenize_args(buf);
    if (fields->count == 2) {
        if (is_split_screen() == 1) {
            challenge_set_rank_override(fields->tokens[0], fields->tokens[1], arg);
        } else {
            add_challenge_rank_override(fields->tokens[0], fields->tokens[1], arg);
        }
    }
    delete fields;
}

void qst_op_dark_falz_is_dead(s32 reg) {
    if (is_boss_phase_reached() != 0) {
        qst_registers[(u8)reg].i = 1;
        return;
    }
    qst_registers[(u8)reg].i = 0;
}

int qst_op_ba_clear_trapself(void) { return TOMineTrap::set_trap_count(0); }

int qst_op_ba_set_trapself() { return TOMineTrap::set_trap_count(1); }

void qst_op_award_item_ok(int a0) { qst_item_ok_window = TObjItemOKWindow::create(tl_01); qst_registers[(unsigned char)(a0)].i = 0; qst_result_register = a0; qst_suspend_reason = QST_WAIT_ITEM_OK; }

void qst_op_ba_set_box_drop_area(s32 reg) {
    TItemDropSub::create_instance((int) (qst_registers[(u8)reg].i));
}

void qst_op_item_create_cmode(u8 regs, u8 dst) {
    TItemData item;
    item.init();
    item.data1.data_u8[0] = qst_registers[(u8)regs++].i;
    item.data1.data_u8[1] = qst_registers[(u8)regs++].i;
    item.data1.data_u8[2] = qst_registers[(u8)regs++].i;
    item.data1.data_u8[3] = qst_registers[(u8)regs++].i;
    item.data1.data_u8[4] = qst_registers[(u8)regs++].i;
    item.data1.data_u8[5] = qst_registers[regs].i;
    item.id = advance_item_id_counter(local_client_id);
    if (is_split_screen() == 1) {
        if (challenge_create_reward_item(&item, 0) != 0) {
            qst_registers[dst].i = 1;
        } else {
            qst_registers[dst].i = 0;
        }
    } else {
        if (award_challenge_item(&item) != 0) {
            qst_registers[dst].i = 1;
        } else {
            qst_registers[dst].i = 0;
        }
    }
}

void qst_op_check_rank_time(u8 src, u8 dst) {
    s32 r;
    if (is_split_screen() == 1) {
        r = challenge_check_rank_time(qst_registers[src].i, 0);
    } else {
        r = check_challenge_rank_time(qst_registers[src].i);
    }
    switch (r) {
    case 2:
        qst_registers[dst].i = 2;
        break;
    case 1:
        qst_registers[dst].i = 1;
        break;
    case 0:
        qst_registers[dst].i = 0;
        break;
    case -1:
        qst_registers[dst].i = 3;
        break;
    case -2:
        qst_registers[dst].i = 4;
        break;
    case -3:
        qst_registers[dst].i = 5;
        break;
    case -4:
    default:
        qst_registers[dst].i = 6;
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
    idx = qst_registers[regs++].i;
    range = qst_registers[regs].i;
    qst_registers[dst].i = 0;
    self = get_player_by_client_id(idx);
    if (self != NULL) {
        field = self->get_floor();
        for (i = 0; i < 12; i++) {
            if (i != idx) {
                other = get_player_by_client_id(i);
                if (other != NULL && field == other->get_floor() &&
                    xyz_distance_squared(&self->position, &other->position) < range * range) {
                    qst_registers[dst].i++;
                }
            }
        }
    }
}
void qst_op_set_cmode_rank_threshold(u8 regs, u8 dst) {
    s32 a = qst_registers[(u8)regs++].i;
    s32 b = qst_registers[(u8)regs++].i;
    s32 c = qst_registers[regs].i;
    if (is_split_screen() == 1) {
        if (challenge_set_rank_threshold(a, b, c) != 0) {
            qst_registers[dst].i = 1;
        } else {
            qst_registers[dst].i = 0;
        }
    } else {
        if (set_challenge_rank_threshold(a, b, c) != 0) {
            qst_registers[dst].i = 1;
        } else {
            qst_registers[dst].i = 0;
        }
    }
}
void qst_op_award_item_give(u8 reg) {
    TItemData item;
    u8 t = TObjItemNameSelect::get_selected_value();
    init_srank_weapon_item(&item, get_entered_item_name(), t);
    if (is_split_screen() == 1) {
        if (challenge_create_reward_item(&item, 0) != 0) {
            qst_registers[reg].i = 1;
        } else {
            qst_registers[reg].i = 0;
        }
    } else {
        if (award_challenge_item(&item) != 0) {
            qst_registers[reg].i = 1;
        } else {
            qst_registers[reg].i = 0;
        }
    }
}

void qst_op_award_item_select() { qst_item_name_select = TObjItemNameSelect::create(tl_01); qst_suspend_reason = QST_WAIT_ITEM_NAME_SELECT; }

void qst_op_award_item_name() { qst_item_name_entry = TObjItemNameEntry::create(tl_01); qst_suspend_reason = QST_WAIT_ITEM_NAME_ENTRY; }

void qst_op_set_cmode_rank_result(void) {
    s32 color;
    const char *title;
    color = qst_args[0].i;
    title = ((const char *)qst_args[1].p);
    if (is_split_screen() == 1) {
        set_challenge4p_rank_result(title, color);
        return;
    }
    set_challenge_rank_result(title, color);
}

void qst_op_get_mag_levels(s32 i) {
    TItemMag *mag;
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        mag = (TItemMag *)player->get_equipped_mag();
        if (mag != NULL) {
            qst_registers[(u8)i++].i = mag->get_def_level();
            qst_registers[(u8)i++].i = mag->get_pow_level();
            qst_registers[(u8)i++].i = mag->get_dex_level();
            qst_registers[(u8)i].i = mag->get_mind_level();
        }
    }
}

void qst_op_give_s_rank_weapon() {
    TItemData item;
    u8 r = qst_args[1].i;
    saddr a = qst_args[2].i;
    u16 id = qst_args[0].i;
    if (id == local_client_id) {
        TObjPlayer *player = get_player_by_client_id(id);
        if (player != NULL) {
            init_srank_weapon_item(&item, (const char *)a, (u8)qst_registers[r].i);
            if (item.isValidGroundDrop() == 1 && player->can_inventory_accept_item(&item) > 0) {
                player->request_inventory_item(&item);
            }
        }
    }
}

void qst_op_set_score_announce() {
    s32 i;
    s32 v = qst_args[0].i;
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
    battle_rules.sonar_count = (s8) qst_args[0].i;
}

void qst_op_ba_enable_sonar() {
    if ((u32)qst_args[0].i <= 0x1U) {
        battle_rules.enable_sonar = (s8) enable_sonar_values[(u32)qst_args[0].i];
    }
}

void qst_op_set_allow_item_flags(void) {
    TItemMenuCtrl::open_menu((int) (qst_args[0].i));
}

void qst_op_p_talk_guild_local(int _w0, int _w1) {
    u32 player = ((uaddr)get_player_by_client_id((int)(local_client_id)));
    if (player != 0U) {
        handle_main_phase(player);
    }
}

void qst_op_unequip_item() {
    handle_player_event((int) ((u16) qst_args[0].i), (int) (qst_args[1].i));
}

void qst_op_equip_item(u8 i) {
    TItemData item;
    u16 id = qst_registers[i++].i;
    item.init();
    item.data1.data_u8[0] = qst_registers[i++].i;
    item.data1.data_u8[1] = qst_registers[i++].i;
    item.data1.data_u8[2] = qst_registers[i++].i;
    forward_to_player(id, &item);
}

int qst_op_ba_hide_self_traps(void) { return TOMineTrap::set_instance(0); }

int qst_op_ba_show_self_traps(void) { return TOMineTrap::set_instance(1); }

void qst_op_set_area_title() {
    const char *title;

    title = (const char *)qst_args[0].i;
    if (is_split_screen() == 1) {
        set_area_title(title);
        return;
    }
    set_area_title(title);
}

void qst_op_unset_ult_map(void) { TLobby::clear_quest_state(); }

void qst_op_set_ult_map() { set_ult_map(); }

void qst_op_restore_warp_dest_floor(void) { TLobby::reset_quest_counter(); }

void qst_op_override_warp_dest_floor() { override_warp_dest_floor(); }

void qst_op_set_current_area_number(void) {
    TLobby::set_lobby_id((int) (qst_args[0].i));
}

void qst_op_set_area_total() {
    TLobby::set_area_total((int) (qst_args[0].i));
}

void qst_op_ba_set_meseta_drop_mode(void) {
    if ((u32)qst_args[0].i <= 2U) {
        battle_rules.meseta_mode = (s8) meseta_mode_values[(u32)qst_args[0].i];
    }
}

void qst_op_ba_death_lvl_up(void) {
    battle_rules.death_level_up = (s8) qst_args[0].i;
}

void qst_op_ba_set_time_limit(void) {
    u32 time_limit;
    time_limit = (u32)qst_args[0].i;
    if (time_limit > 0x278D0U) {
        time_limit = 0U;
    }
    battle_rules.time_limit = time_limit;
}

void qst_op_ba_set_char_level(void) {
    u32 char_level;
    char_level = (u32)qst_args[0].i;
    if (char_level > TObjPlayer::get_max_level()) {
        char_level = 0U;
    }
    battle_rules.char_level = char_level;
}

void qst_op_ba_set_max_tech_level() {
    u32 max_level;
    max_level = (u32)qst_args[0].i;
    if ((max_level != 0xFFU) && (max_level > 0x1DU)) {
        max_level = 0U;
    }
    battle_rules.max_tech_level = max_level;
}

void qst_op_ba_set_lives(void) {
    u32 lives;
    lives = (u32)qst_args[0].i;
    if (lives > 0x63U) {
        lives = 0U;
    }
    battle_rules.lives = lives;
}

void qst_op_ba_hide_target_reticle(void) {
    if ((u32)qst_args[0].i <= 1U) {
        battle_rules.hide_target_reticle = (s8) (u32)qst_args[0].i;
    }
}

void qst_op_ba_set_trap_count(s32 reg) {
    s32 slot = qst_registers[(u8)reg++].i;
    s32 value = qst_registers[(u8)reg].i;
    if (slot >= 0 && slot <= 3) {
        battle_rules.trap_counts[trap_count_slots[slot]] = value;
    }
}

void qst_op_ba_meseta_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a].i;
    v += (f32)qst_registers[(u8)b].i / (f32)qst_registers[(u8)++b].i;
    battle_meseta_score = v;
}

void qst_op_ba_enemy_death_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a].i;
    v += (f32)qst_registers[(u8)b].i / (f32)qst_registers[(u8)++b].i;
    battle_enemy_death_score = v;
}

void qst_op_ba_enemy_kill_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a].i;
    v += (f32)qst_registers[(u8)b].i / (f32)qst_registers[(u8)++b].i;
    battle_enemy_kill_score = v;
}

void qst_op_ba_player_death_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a].i;
    v += (f32)qst_registers[(u8)b].i / (f32)qst_registers[(u8)++b].i;
    battle_player_death_score = v;
}

void qst_op_ba_player_kill_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a].i;
    v += (f32)qst_registers[(u8)b].i / (f32)qst_registers[(u8)++b].i;
    battle_player_kill_score = v;
}

void qst_op_ba_enemy_take_damage_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a].i;
    v += (f32)qst_registers[(u8)b].i / (f32)qst_registers[(u8)++b].i;
    battle_enemy_take_damage_score = v;
}

void qst_op_ba_enemy_give_damage_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a].i;
    v += (f32)qst_registers[(u8)b].i / (f32)qst_registers[(u8)++b].i;
    battle_enemy_give_damage_score = v;
}

void qst_op_ba_player_take_damage_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a].i;
    v += (f32)qst_registers[(u8)b].i / (f32)qst_registers[(u8)++b].i;
    battle_player_take_damage_score = v;
}

void qst_op_ba_player_give_damage_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a].i;
    v += (f32)qst_registers[(u8)b].i / (f32)qst_registers[(u8)++b].i;
    battle_player_give_damage_score = v;
}

void qst_op_set_cmode_base_time(s32 reg) {
    if (is_split_screen() == 1) {
        update_challenge_timer((int) (qst_registers[(u8)reg].i));
        return;
    }
    set_challenge_base_time((int) (qst_registers[(u8)reg].i));
}

void qst_op_prepare_npc_visual(saddr label) {
    u8 *record;
    record = qst_label_address(label);
    if (record != NULL) {
        copy_player_visual_record((PlayerVisualRecord *)&quest_npc_visual_record, (PlayerVisualRecord *)record);
    }
}

void qst_op_enable_npc_visual(void *p) { enable_quest_npc_visual(); }

void qst_op_set_shrink_cam2(u8 regs) {
    Vec pos;
    TObjPlayer *player;
    Vec *cur;
    player = get_player_by_client_id(qst_registers[regs++].i);
    if (player != NULL) {
        cur = player->scale_state.camera.target.get();
        if (cur != NULL) {
            pos.x = cur->x + (f32)qst_registers[regs++].i;
            pos.y = cur->y + (f32)qst_registers[regs++].i;
            pos.z = cur->z + (f32)qst_registers[regs].i;
            copy_position(&player->scale_state.camera.target, &pos);
        }
    }
}

void qst_op_set_shrink_cam1(u8 regs) {
    Vec pos;
    TObjPlayer *player;
    Vec *cur;
    player = get_player_by_client_id(qst_registers[regs++].i);
    if (player != NULL) {
        cur = player->scale_state.camera.position.get();
        if (cur != NULL) {
            pos.x = cur->x + (f32)qst_registers[regs++].i;
            pos.y = cur->y + (f32)qst_registers[regs++].i;
            pos.z = cur->z + (f32)qst_registers[regs].i;
            copy_position(&player->scale_state.camera.position, &pos);
        }
    }
}

void qst_op_unshrink(s32 slot_reg) {
    TObjPlayer *player;
    player = get_player_by_client_id(qst_registers[(u8)slot_reg].i);
    if ((player != NULL) && (player->obj_isState2_324() == 0)) {
        player->scale_state.request_size_restore();
    }
}

void qst_op_shrink(s32 slot_reg) {
    TObjPlayer *player;
    player = get_player_by_client_id(qst_registers[(u8)slot_reg].i);
    if ((player != NULL) && (player->obj_isState2_324() == 0)) {
        player->scale_state.request_shrink();
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
    qst_registers[(u8)reg + 1].i = is_current_floor_switch_set((u16)qst_registers[(u8)reg].i);
}

void qst_op_clear_switch_flag_sync() {
    G_SwitchStateChanged_6x05 pkt;
    s32 x = qst_args[0].i;
    s32 y = qst_args[1].i;
    pkt.init();
    pkt.header.client_id = 0xFFFF;
    pkt.unused1 = 0;
    pkt.switch_id = y;
    pkt.floor = x;
    pkt.flags = 0;
    pkt.send();
}

void qst_op_set_switch_flag_sync() {
    G_SwitchStateChanged_6x05 pkt;
    s32 x = qst_args[0].i;
    s32 y = qst_args[1].i;
    pkt.init();
    pkt.header.client_id = 0xFFFF;
    pkt.unused1 = 0;
    pkt.switch_id = y;
    pkt.floor = x;
    pkt.flags = 1;
    pkt.send();
}

void qst_op_reset_kills(s32 slot_reg) {
    TObjPlayer *player;
    player = get_player_by_client_id(qst_registers[(u8)slot_reg].i);
    if (player != NULL) {
        player->set_kill_count(0);
    }
}

void qst_op_get_num_kills(s32 slot_reg, s32 dst) {
    TObjPlayer *player;
    player = get_player_by_client_id(qst_registers[(u8)slot_reg].i);
    if (player != NULL) {
        qst_registers[(u8)dst].i = player->get_kill_count();
        return;
    }
    qst_registers[(u8)dst].i = 0;
}

void qst_op_go_floor(s32 a, s32 b) {
    TObjPlayer *player = get_player_by_client_id(qst_registers[(u8)a].i);
    if (player != NULL && local_client_id == qst_registers[(u8)a].i) {
        floor_transition_state.set_next_floor(qst_registers[(u8)b].i, get_floor_map_terrain(qst_registers[(u8)b].i));
        mark_area_change_pending();
        send_inter_level_warp_all(floor_transition_state.get_next_floor());
        send_6x21_inter_level_warp(player, floor_transition_state.get_next_floor());
    }
}

void qst_op_release_dragon(void* p) { TBoss1Dragon::clearControlOverride(); }

void qst_op_control_dragon(s32 reg) {
    TBoss1Dragon::setControlOverride(qst_registers[(u8)reg].i);
}

void qst_op_cmode_check_any_player_dead(s32 reg) {
    if (is_split_screen() == 1) {
        qst_registers[(u8)reg].i = challenge_check_any_player_dead();
        return;
    }
    qst_registers[(u8)reg].i = challenge_any_player_dead();
}

void qst_op_cmode_check_all_players_dead(s32 reg) {
    if (is_split_screen() == 1) {
        qst_registers[(u8)reg].i = challenge_check_all_players_dead();
        return;
    }
    qst_registers[(u8)reg].i = challenge_all_players_dead();
}

void qst_op_exp_multiplication(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a].i;
    v += (f32)qst_registers[(u8)b].i / (f32)qst_registers[(u8)++b].i;
    if (is_split_screen() == 1) {
        set_camera_height_if_valid(v);
        return;
    }
    set_exp_multiplier(v);
}

void qst_op_set_cmode_difficulty() {
    s32 difficulty;

    difficulty = qst_args[0].i;
    if (is_split_screen() == 1) {
        try_set_split_screen(difficulty);
        return;
    }
    set_challenge_difficulty(difficulty);
}

void qst_op_set_cmode_char_template() {
    s32 stage;

    stage = qst_args[0].i;
    if (is_split_screen() == 1) {
        rebuild_players_for_stage(stage);
        return;
    }
    TObjPlayer::rebuild_players_for_stage(stage);
}

void qst_op_nop_F822(s32 reg) {
    if (is_split_screen() == 1) {
        quest_op_F822_split_screen_stub((int) (qst_registers[(u8)reg].i));
        return;
    }
    quest_op_F822_stub((int) (qst_registers[(u8)reg].i));
}

void qst_op_nop_F821(u8 regs) {
    TItemData item;
    s32 a;
    s32 b;
    s32 c;
    a = qst_registers[(u8)regs++].i;
    b = qst_registers[(u8)regs++].i;
    c = qst_registers[(u8)regs++].i;
    item.init();
    item.data1.data_u8[0] = qst_registers[(u8)regs++].i;
    item.data1.data_u8[1] = qst_registers[(u8)regs++].i;
    item.data1.data_u8[2] = qst_registers[(u8)regs++].i;
    item.data1.data_u8[3] = qst_registers[(u8)regs++].i;
    item.data1.data_u8[4] = qst_registers[(u8)regs++].i;
    item.data1.data_u8[5] = qst_registers[regs].i;
    item.id = advance_item_id_counter(local_client_id);
    if (is_split_screen() == 1) {
        quest_op_F821_split_screen_stub(a, b, c, &item);
    } else {
        quest_op_F821_stub(a, b, c, &item);
    }
}

void qst_op_cmode_stage() {
    u32 stage;
    u32 layout_id;

    stage = (u32)qst_args[0].i;
    layout_id = challenge_set_stage_count(-1);
    if (is_split_screen() == 1) {
        if (stage < layout_id) {
            clamp_and_store_layout_index(stage);
            return;
        }
        clamp_and_store_layout_index(0U);
        return;
    }
    if (stage < layout_id) {
        set_challenge_stage(stage);
        return;
    }
    set_challenge_stage(0U);
}

void qst_op_ba_start(void) {
    s32 src;
    src = qst_args[0].i;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        TPlayerBattleCtrl4P::init_instance_with_text((saddr)&battle_rules, src);
        return;
    }
    init_battle_ctrl((saddr)&battle_rules, src);
}

void qst_op_ba_teams() {
    if ((u32)qst_args[0].i <= 0x1U) {
        battle_rules.is_teams = (s8) teams_values[(u32)qst_args[0].i];
        return;
    }
    battle_rules.is_teams = (s8) teams_values[0];
}

void qst_op_ba_dropwep() {
    if ((u32)qst_args[0].i <= 0x1U) {
        battle_rules.drop_weapon = (s8) drop_weapon_values[(u32)qst_args[0].i];
        return;
    }
    battle_rules.drop_weapon = (s8) drop_weapon_values[0];
}

void qst_op_ba_set_replace_char() {
    if ((u32)qst_args[0].i <= 0x1U) {
        battle_rules.replace_char = (s8) replace_char_values[(u32)qst_args[0].i];
        return;
    }
    battle_rules.replace_char = (s8) replace_char_values[1];
}

void qst_op_ba_set_respawn(void) {
    if ((u32)qst_args[0].i <= 2U) {
        battle_rules.respawn_mode = (s8) respawn_mode_values[(u32)qst_args[0].i];
        return;
    }
    battle_rules.respawn_mode = (s8) respawn_mode_values[2];
}

void qst_op_ba_set_unused_F817(void) {
    if ((u32)qst_args[0].i <= 0x1U) {
        battle_rules.unused_F817 = (s8) unused_F817_values[(u32)qst_args[0].i];
        return;
    }
    battle_rules.unused_F817 = (s8) unused_F817_values[0];
}

void qst_op_ba_set_trap_mode(void) {
    if ((u32)qst_args[0].i <= 0x1U) {
        battle_rules.trap_mode = (s8) trap_mode_values[(u32)qst_args[0].i];
        return;
    }
    battle_rules.trap_mode = (s8) trap_mode_values[0];
}

void qst_op_ba_set_tool_mode(void) {
    if ((u32)qst_args[0].i <= 2U) {
        battle_rules.tool_mode = (s8) tool_mode_values[(u32)qst_args[0].i];
        return;
    }
    battle_rules.tool_mode = (s8) tool_mode_values[0];
}

void qst_op_ba_set_forbid_mags() {
    if ((u32)qst_args[0].i <= 0x1U) {
        battle_rules.mag_mode = (s8) mag_mode_values[(u32)qst_args[0].i];
        return;
    }
    battle_rules.mag_mode = (s8) mag_mode_values[0];
}

void qst_op_ba_set_weapon_and_armor_mode() {
    if ((u32)qst_args[0].i <= 3U) {
        battle_rules.weapon_and_armor_mode = (s8) lobby_menu_byte_1_map[(u32)qst_args[0].i];
        return;
    }
    battle_rules.weapon_and_armor_mode = (s8) lobby_menu_byte_1_map[0];
}

void qst_op_ba_set_tech_disk_mode() {
    s8 tech_disk_mode;
    if ((u32)qst_args[0].i <= 2U) {
        tech_disk_mode = (s8) tech_disk_mode_values[(u32)qst_args[0].i];
    } else {
        tech_disk_mode = (s8) tech_disk_mode_values[2];
    }
    battle_rules.tech_disk_mode = tech_disk_mode;
}

void qst_op_clear_ba_rules() {
    memset(&battle_rules, 0, sizeof(BattleRules));
}

void qst_op_ba_initial_floor(void) {
    BaInitialFloorTable t = ba_initial_floor_table;
    if ((u32)qst_args[0].i <= 0x11U) {
        initialize_floor_transition(&floor_transition_state, t.w[(u32)qst_args[0].i], 0);
    }
}

void qst_op_enable_weapon_drop(int _w0, int _w1) {
    TObjPlayer *pl = get_player_by_client_id((int)(qst_args[0].i));
    if (pl != NULL) {
        pl->send_enable_drop_weapon_on_death();
    }
}

void qst_op_disable_weapon_drop(int _w0, int _w1) {
    TObjPlayer *pl = get_player_by_client_id((int)(qst_args[0].i));
    if (pl != NULL) {
        pl->send_disable_drop_weapon_on_death();
    }
}

void qst_op_map_designate_ex(u32 first) {
    u32 i = first;
    s32 a = qst_registers[(u8)i++].i;
    s32 b = qst_registers[(u8)i++].i;
    s16 c = qst_registers[(u8)i++].i;
    s32 d = qst_registers[(u8)i++].i;
    s32 e = qst_registers[(u8)i].i;
    set_quest_floor_designation_ex(c, a, b, d, e);
}

void qst_op_disable_map(void) { TRaderMapCore::set_mode(0); }

void qst_op_enable_map(void) { TRaderMapCore::set_mode(1); }

void qst_op_get_coord_of_player(s32 a, s32 b) {
    TObjPlayer *player = get_player_by_client_id(qst_registers[(u8)b].i);
    if (player != NULL) {
        f32 *p = (f32 *)player->get_position_ptr();
        if (p != NULL) {
            qst_registers[(u8)a++].i = (s32)p[0];
            qst_registers[(u8)a++].i = (s32)p[1];
            qst_registers[(u8)a].i = (s32)p[2];
        }
    }
}

void qst_op_get_number_of_players(int a0) { qst_registers[(unsigned char)(a0)].i = TLobby::count_members(); }

void qst_op_get_difficulty_level_v2(s32 reg) {
    s32 difficulty;
    difficulty = game_difficulty_selection;
    if (difficulty < 0) {
        difficulty = 0;
    }
    if (difficulty > 3) {
        difficulty = 3;
    }
    qst_registers[(u8)reg].i = difficulty;
}

void qst_op_create_bgmctrl() {
    new TQuestBgmCtrl(tl_05);
}

void qst_op_update_switch_flag(s32 regs) {
    G_SwitchStateChanged_6x05 pkt;
    pkt.init();
    pkt.unused1 = 0;
    pkt.header.client_id = 0xFFFF;
    pkt.switch_id = qst_registers[(u8)regs++].i;
    pkt.floor = qst_registers[(u8)regs++].i;
    pkt.flags = qst_registers[(u8)regs].i;
    pkt.send();
}

void qst_op_get_leader_id(u8 reg) {
    qst_registers[reg].i = designated_client_id;
}

void qst_op_get_client_id(u8 reg) {
    qst_registers[reg].i = local_client_id;
}

void qst_op_warp_off() { disable_quest_warp(); }

void qst_op_warp_on(void) { TLobby::set_cleanup_flag(); }

void qst_op_start_setevt() {
    G_FloorEvent_6x67 pkt;
    s32 x = qst_args[0].i;
    s32 y = qst_args[1].i;
    pkt.init();
    pkt.floor = x;
    pkt.header.client_id = 0;
    pkt.event_id = y;
    pkt.sender_client_id = 0;
    pkt.send();
}

void qst_op_pad_dragon(void* p) { TBoss1Dragon::requestActionRefresh(); }

void qst_op_delete_bank_item(u8 regs, u8 dst) {
    TItemData item;
    item.init();
    item.data1.data_u8[0] = qst_registers[(u8)regs++].i;
    item.data1.data_u8[1] = qst_registers[(u8)regs++].i;
    item.data1.data_u8[2] = qst_registers[(u8)regs++].i;
    item.data1.data_u8[3] = qst_registers[(u8)regs++].i;
    item.data1.data_u8[4] = qst_registers[(u8)regs++].i;
    item.data1.data_u8[5] = qst_registers[regs].i;
    if (delete_bank_item((u8 *)&item, 0) != 0) {
        qst_registers[dst].i = 1;
    } else {
        qst_registers[dst].i = 0;
    }
}

void qst_op_set_returncity() {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        player->stop_battle();
    }
}

void qst_op_set_returnhunter() {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        player->set_return_hunter();
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

    eye.x = qst_registers[(u8)regs++].i;
    eye.y = qst_registers[(u8)regs++].i;
    eye.z = qst_registers[(u8)regs++].i;
    at.x = qst_registers[(u8)regs++].i;
    at.y = qst_registers[(u8)regs++].i;
    at.z = qst_registers[regs].i;
    set_fixed_camera(&eye, &at);
}

void qst_op_sync_register(void) {
    G_SyncQuestRegister_6x77 cmd;
    cmd.init();
    cmd.register_number = qst_args[0].i;
    cmd.value = qst_args[1].i;
    cmd.send();
}

void qst_op_set_eventflag2(void) {
    u32 x = (u32)qst_args[0].i;
    u32 y = (u32)qst_args[1].i;
    u8* s = TAdSinglePlyChrSelectGC::get_global_state();
    if (s != 0 && x < 0x100) {
        s[x + 0x10] = y;
    }
}

void qst_op_set_eventflag(void) {
    u32 x = (u32)qst_args[0].i;
    u32 y = (u32)qst_args[1].i;
    u8* s = TAdSinglePlyChrSelectGC::get_global_state();
    if (s != 0 && x < 0x100) {
        s[x + 0x10] = y;
    }
}

void qst_op_end_battlebgm() {
    TObjPlayer *player;

    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        player->stop_battle_music();
        player->release_battle_music();
    }
}

void qst_op_start_battlebgm() {
    TObjPlayer *player;

    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        player->hold_battle_music();
        player->start_battle_music();
    }
}

void qst_op_disable_mainmenu(void) { TWindowCtrl::disable_client_main_menu(local_client_id); }

void qst_op_enable_mainmenu() { TWindowCtrl::enable_client_main_menu(local_client_id); }

void qst_op_nop_BC(void) {  }

void qst_op_clr_qt_exit(void) { set_quest_exit_callback(-1); }

void qst_op_set_qt_exit(u16 label) {
    set_quest_exit_callback(label);
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
    qst_registers[(u8)reg].i = difficulty;
}

void qst_op_setevt(void) {
    G_FloorEvent_6x67 pkt;
    s32 x = qst_args[0].i;
    pkt.init();
    pkt.header.client_id = 0;
    pkt.floor = get_current_floor();
    pkt.event_id = x;
    pkt.sender_client_id = 0;
    pkt.send();
}

void qst_op_clear_quest_board_handler(void) {
    if ((u32)qst_args[0].i <= 5U) {
        memset(&quest_board_handlers[(u32)qst_args[0].i], 0, sizeof(QuestBoardHandler));
    }
}

void qst_op_set_quest_board_handler(void) {
    s32 i = qst_args[0].i;
    s32 v = qst_args[1].i;
    saddr n = qst_args[2].i;
    if (i <= 5) {
        QuestBoardHandler *e = &quest_board_handlers[i];
        e->label = v;
        strncpy(e->title, (const char *)n, 0x20);
    }
}

void qst_op_getmtime(int a0) { qst_registers[(unsigned char)(a0)].i = get_coarse_time(); }

void qst_op_winset_time(s32 reg) {
    TWindowCtrl::set_timer_window_time(qst_registers[(u8)reg].i);
}

void qst_op_winend_time(void* p) { TWindowCtrl::close_timer_window(); }

void qst_op_show_timer(void *p) { TWindowCtrl::create_alt_timer(); }

void qst_op_masterkey_off() { TLobby::reset_door_state(); TObjDoor::reset_instance(); }

void qst_op_masterkey_on() { force_switch_doors_closed(); enable_door_masterkey(); }

void qst_op_map_designate(u32 first) {
    u32 i = first;
    s32 floor = qst_registers[(u8)i++].i;
    s16 mode = qst_registers[(u8)i++].i;
    s32 terrain = qst_registers[(u8)i++].i;
    s32 extra = qst_registers[(u8)i].i;
    set_quest_floor_designation(mode, floor, terrain, extra);
}

void qst_op_find_inventory_item_ex(u8 regs, u8 dst) {
    TItemData item;
    TObjPlayer *player;
    TItemList *slot;
    TItem *owner;
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        item.init();
        item.data1.data_u8[0] = qst_registers[(u8)regs++].i;
        item.data1.data_u8[1] = qst_registers[(u8)regs++].i;
        item.data1.data_u8[2] = qst_registers[(u8)regs++].i;
        item.data1.data_u8[4] = qst_registers[regs].i;
        slot = player->inventory_objects->set_mode_and_refresh_object(&item);
        if (slot != NULL) {
            owner = slot->get_owner_if_alive();
            if (owner != NULL) {
                qst_registers[dst].i = owner->get_item_id();
            } else {
                qst_registers[dst].i = -1;
            }
        } else {
            qst_registers[dst].i = -1;
        }
    } else {
        qst_registers[dst].i = -1;
    }
}

void qst_op_item_check(u32 first, u32 destination) {
    TItemData item;
    TObjPlayer *player;
    TItemList *slot;
    TItem *owner;
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        item.init();
        item.data1.data_u8[0] = qst_registers[(u8)first++].i;
        item.data1.data_u8[1] = qst_registers[(u8)first++].i;
        item.data1.data_u8[2] = qst_registers[(u8)first].i;
        slot = player->inventory_objects->set_mode_and_refresh_object(&item);
        if (slot != 0) {
            owner = slot->get_owner_if_alive();
            if (owner != 0) {
                qst_registers[(u8) destination].i = owner->get_item_id();
                return;
            }
            qst_registers[(u8) destination].i = -1;
            return;
        }
        qst_registers[(u8) destination].i = -1;
        return;
    }
    qst_registers[(u8) destination].i = -1;
}

void qst_op_item_delete2(u32 src, u32 dst) {
    TItemData item;
    TObjPlayer *player;
    TItemList *slot;
    TItem *owner;
    if ((u8)dst > 0xF4) {
        return;
    }
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        item.init();
        item.data1.data_u8[0] = qst_registers[(u8)src++].i;
        item.data1.data_u8[1] = qst_registers[(u8)src++].i;
        item.data1.data_u8[2] = qst_registers[(u8)src].i;
        slot = player->inventory_objects->set_mode_and_refresh_object(&item);
        if (slot != 0) {
            owner = slot->get_owner_if_alive();
            if (owner != 0) {
                owner->copy_to_item_data(&item);
                qst_registers[(u8)dst++].i = item.data1.data_u8[0];
                qst_registers[(u8)dst++].i = item.data1.data_u8[1];
                qst_registers[(u8)dst++].i = item.data1.data_u8[2];
                qst_registers[(u8)dst++].i = item.data1.data_u8[3];
                qst_registers[(u8)dst++].i = item.data1.data_u8[4];
                qst_registers[(u8)dst++].i = item.data1.data_u8[5];
                qst_registers[(u8)dst++].i = item.data1.data_u8[6];
                qst_registers[(u8)dst++].i = item.data1.data_s8[7];
                qst_registers[(u8)dst++].i = item.data1.data_u8[8];
                qst_registers[(u8)dst++].i = item.data1.data_s8[9];
                qst_registers[(u8)dst++].i = item.data1.data_u8[10];
                qst_registers[(u8)dst].i = item.data1.data_s8[11];
                delete_item(player, item.id, 1);
                return;
            }
            qst_registers[(u8)dst].i = -1;
            return;
        }
        qst_registers[(u8)dst].i = -1;
        return;
    }
    qst_registers[(u8)dst].i = -1;
}

void qst_op_item_delete(u32 src, u32 dst) {
    TItemData item;
    TObjPlayer *player;
    TItemList *slot;
    TItem *owner;
    if ((u8)dst > 0xF4) {
        return;
    }
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        slot = player->inventory_objects->start_inventory_update(qst_registers[(u8)src].i);
        if (slot != 0) {
            owner = slot->get_owner_if_alive();
            if (owner != 0) {
                owner->copy_to_item_data(&item);
                qst_registers[(u8)dst++].i = item.data1.data_u8[0];
                qst_registers[(u8)dst++].i = item.data1.data_u8[1];
                qst_registers[(u8)dst++].i = item.data1.data_u8[2];
                qst_registers[(u8)dst++].i = item.data1.data_u8[3];
                qst_registers[(u8)dst++].i = item.data1.data_u8[4];
                qst_registers[(u8)dst++].i = item.data1.data_u8[5];
                qst_registers[(u8)dst++].i = item.data1.data_u8[6];
                qst_registers[(u8)dst++].i = item.data1.data_s8[7];
                qst_registers[(u8)dst++].i = item.data1.data_u8[8];
                qst_registers[(u8)dst++].i = item.data1.data_s8[9];
                qst_registers[(u8)dst++].i = item.data1.data_u8[10];
                qst_registers[(u8)dst].i = item.data1.data_s8[11];
                delete_item(player, qst_registers[(u8)src].i, 1);
                return;
            }
            qst_registers[(u8)dst].i = -1;
            return;
        }
        qst_registers[(u8)dst].i = -1;
        return;
    }
    qst_registers[(u8)dst].i = -1;
}

void qst_op_item_create2(u8 regs, u8 dst) {
    TItemData item;
    TObjPlayer *player;
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        item.init();
        item.data1.data_u8[0] = qst_registers[regs++].i;
        item.data1.data_u8[1] = qst_registers[regs++].i;
        item.data1.data_u8[2] = qst_registers[regs++].i;
        item.data1.data_u8[3] = qst_registers[regs++].i;
        item.data1.data_u8[4] = qst_registers[regs++].i;
        item.data1.data_u8[5] = qst_registers[regs++].i;
        item.id = advance_item_id_counter(local_client_id);
        item.data1.data_u8[6] = qst_registers[regs++].i;
        item.data1.data_u8[7] = qst_registers[regs++].i;
        item.data1.data_u8[8] = qst_registers[regs++].i;
        item.data1.data_u8[9] = qst_registers[regs++].i;
        item.data1.data_u8[10] = qst_registers[regs++].i;
        item.data1.data_u8[11] = qst_registers[regs].i;
        if (player->can_inventory_accept_item(&item) > 0) {
            player->request_inventory_item(&item);
            qst_registers[dst].i = item.id;
        } else {
            qst_registers[dst].i = -1;
        }
    } else {
        qst_registers[dst].i = -1;
    }
}

void qst_op_item_create(u8 regs, u8 dst) {
    TItemData item;
    TObjPlayer *player;
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        item.init();
        item.data1.data_u8[0] = qst_registers[(u8)regs++].i;
        item.data1.data_u8[1] = qst_registers[(u8)regs++].i;
        item.data1.data_u8[2] = qst_registers[regs].i;
        item.id = advance_item_id_counter(local_client_id);
        if (player->can_inventory_accept_item(&item) > 0) {
            player->request_inventory_item(&item);
            qst_registers[dst].i = item.id;
        } else {
            qst_registers[dst].i = -1;
        }
    } else {
        qst_registers[dst].i = -1;
    }
}

void qst_op_del_obj_param(s32 reg) {
    TQuestColCtrl::delete_by_param(qst_registers[(u8)reg].i);
}

void qst_op_pl_add_meseta2() {
    s32 amount;
    TObjPlayer *player;

    amount = qst_args[0].i;
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        player->add_meseta(amount);
    }
}

void qst_op_pl_add_meseta(void) {
    s32 amount;
    TObjPlayer *player;
    amount = qst_args[1].i;
    player = get_player_by_client_id(qst_args[0].i);
    if (player != NULL) {
        player->add_meseta(amount);
    }
}

void qst_op_clr_qt_cancel(void) { set_quest_cancel_callback(-1); }

void qst_op_clr_qt_success(void) { set_quest_success_callback(-1); }

void qst_op_clr_qt_failure(void) { set_quest_failure_callback(-1); }

void qst_op_set_qt_cancel(u16 label) {
    set_quest_cancel_callback(label);
}

void qst_op_set_qt_success(u16 label) {
    set_quest_success_callback(label);
}

void qst_op_set_qt_failure(u16 label) {
    set_quest_failure_callback(label);
}

void qst_op_clr_floor_handler(void) {
    TQuestThread::clear_floor_handler(qst_args[0].i);
}

void qst_op_set_floor_handler(void) {
    TQuestThread::set_floor_handler(qst_args[0].i, (u16)qst_args[1].i);
}

void qst_op_pcam_param(u8 regs) {
    s32 i = regs;
    Vec a;
    Vec b;

    a.x = qst_registers[i++].i;
    a.y = qst_registers[i++].i;
    a.z = qst_registers[i++].i;
    b.x = qst_registers[i++].i;
    b.y = qst_registers[i++].i;
    b.z = qst_registers[i].i;
    request_follow_camera_offsets(&a, &b, 0xFFFF);
}

void qst_op_clear_mainwarp_all() { clear_enabled_main_warps(); }

void qst_op_clear_mainwarp() {
    TObjCityMainWarp::clear_active_bit(qst_args[0].i);
}

void qst_op_set_mainwarp(void) {
    s32 main_warp_id;
    main_warp_id = qst_args[0].i;
    TObjCityMainWarp::set_active_bit((int) (qst_args[0].i));
    TObjDoor::set_main_warp_id(main_warp_id);
}

void qst_op_set_bgm() {
    TQuestBgmCtrl::force_bgm((int) (qst_args[0].i));
}

void qst_op_playbgm_epi(void) {
    TQuestBgmCtrl::defer_bgm((int) (qst_args[0].i));
}

void qst_op_switch_off(void) {
    clear_current_floor_switch(((u16) qst_args[0].i));
}

void qst_op_switch_on(void) {
    set_current_floor_switch(((u16) qst_args[0].i));
}

void qst_op_npc_talk_kill(void) {
    set_npc_proximity_target_id((qst_args[0].i));
}
void qst_op_npc_talk_pl(u8 regs) {
    s32 i;
    ObjectSetData set;

    init_object_set_data(&set);
    i = regs;
    set.position.x = qst_registers[i++].i;
    set.position.y = qst_registers[i++].i;
    set.position.z = qst_registers[i++].i;
    set.scale.x = qst_registers[i++].i;
    set.rotation[1] = 182.04445f * qst_registers[i++].i;
    set.set_params[0] = qst_registers[i++].i;
    set.set_params[1] = qst_registers[i++].i;
    set.set_params[2] = qst_registers[i].i;
    TLobby::create_npc(&set);
}

void qst_op_p_talk_guild(void) {
    TObjPlayer *player = get_player_by_client_id(qst_args[0].i);
    if (player != NULL) {
        handle_main_phase((saddr)player);
    }
}

void qst_op_p_return_guild(void) {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        player->prepare_guild_return(0);
    }
}

void qst_op_npc_text_clear_all() { clear_partner_dialogue_flags(); }

void qst_op_load_midi() { TLobby::free_luker_object(); load_midi_stub(); TLobby::clear_quest_vm_flag(); }

void qst_op_load_pvr() { TLobby::free_luker_object(); load_memcard_file(); TLobby::clear_quest_vm_flag(); }

void qst_op_npc_text() {
    set_partner_common_remark((qst_args[0].i), (const char *)(qst_args[1].i));
}

void qst_op_nop_A0_debug(void) {
    char buf[0x200];
    TTokenList *fields;
    const char *s = ((const char *)qst_args[1].p);
    fields = new TTokenList(NULL, 0, 0);
    buf[0x1FF] = 0;
    strncpy(buf, s, 0x1FF);
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

void qst_op_npc_chkwarp() { send_quest_collision_warp(); }

void qst_op_check_npc_straggle(u8 i) {
    u8 start = i;
    Vec v;
    ObjectSetData s;
    TObjQuestColApcINW *obj;

    init_object_set_data(&s);
    s.position.x = qst_registers[i++].i;
    s.position.y = qst_registers[i++].i;
    s.position.z = qst_registers[i++].i;
    s.scale.x = qst_registers[i++].i;
    s.set_params[0] = qst_registers[i++].i;
    s.scale.y = qst_registers[i++].i;
    obj = TLobby::create_quest_col_apc_inw(&s, &qst_registers[start].i);
    if (obj != NULL) {
        v.x = qst_registers[i++].i;
        v.y = qst_registers[i++].i;
        v.z = qst_registers[i].i;
        set_quest_col_warp_position(obj, &v);
    }
}

void qst_op_set_obj_param(u8 regs, u8 reg) {
    ObjectSetData set;

    init_object_set_data(&set);
    set.position.x = qst_registers[regs++].i;
    set.position.y = qst_registers[regs++].i;
    set.position.z = qst_registers[regs++].i;
    set.scale.x = qst_registers[regs++].i;
    set.set_params[0] = qst_registers[regs++].i;
    set.scale.y = qst_registers[regs].i;
    create_quest_col_alock(&set, &qst_registers[reg].i);
}

void qst_op_col_npcinr(u8 regs) {
    ObjectSetData set;
    u8 first;

    init_object_set_data(&set);
    first = regs;
    set.position.x = qst_registers[(u8)regs++].i;
    set.position.y = qst_registers[(u8)regs++].i;
    set.position.z = qst_registers[(u8)regs++].i;
    set.scale.x = qst_registers[(u8)regs++].i;
    set.scale.y = qst_registers[(u8)regs++].i;
    set.set_params[0] = qst_registers[regs].i;
    create_quest_col_apc_in(&set, &qst_registers[first].i);
}

void qst_op_npc_coords_call(u8 regs) {
    ObjectSetData set;
    u8 first;

    init_object_set_data(&set);
    first = regs;
    set.position.x = qst_registers[(u8)regs++].i;
    set.position.y = qst_registers[(u8)regs++].i;
    set.position.z = qst_registers[(u8)regs++].i;
    set.scale.x = qst_registers[(u8)regs++].i;
    set.set_params[0] = qst_registers[regs].i;
    create_quest_col_apc(&set, &qst_registers[first].i);
}

void qst_op_at_coords_talk(u8 regs) {
    ObjectSetData set;
    u8 first;

    init_object_set_data(&set);
    first = regs;
    set.position.x = qst_registers[(u8)regs++].i;
    set.position.y = qst_registers[(u8)regs++].i;
    set.position.z = qst_registers[(u8)regs++].i;
    set.scale.x = qst_registers[(u8)regs++].i;
    set.set_params[0] = qst_registers[regs].i;
    create_quest_col_a(&set, &qst_registers[first].i);
}

void qst_op_at_coords_call(u8 regs) {
    ObjectSetData set;
    u8 first;

    init_object_set_data(&set);
    first = regs;
    set.position.x = qst_registers[(u8)regs++].i;
    set.position.y = qst_registers[(u8)regs++].i;
    set.position.z = qst_registers[(u8)regs++].i;
    set.scale.x = qst_registers[(u8)regs++].i;
    set.set_params[0] = qst_registers[regs].i;
    create_quest_col(&set, &qst_registers[first].i);
}

#pragma push
#pragma fp_contract on
void qst_op_gettime(u8 reg) {
    s32 date;
    s32 seconds;
    getDateStamp((DateStamp *)(&date));
    DateToSeconds((DateStamp *)(&date), (int *)(&seconds));
    qst_registers[reg].i = seconds;
}
#pragma pop

void qst_op_unhide_ene(s32 regs) {
    s32 v0 = qst_registers[(u8)regs++].i;
    s32 v1 = qst_registers[(u8)regs++].i;
    s32 v2 = qst_registers[(u8)regs].i;
    unhide_enemies_at(v0, (s16)v1, (s16)v2);
}

void qst_op_unhide_obj(s32 regs) {
    s32 v0 = qst_registers[(u8)regs++].i;
    s32 v1 = qst_registers[(u8)regs++].i;
    s32 v2 = qst_registers[(u8)regs].i;
    unhide_room_set_objects(v0, (s16)v1, (s16)v2);
}

void qst_op_chk_ene_num(int a0) { qst_registers[(unsigned char)(a0)].i = TLobby::count_quest_enemies_flag8(); }

void qst_op_if_zone_clear(s32 dst, s32 regs) {
    if (is_room_enemy_set_cleared(qst_registers[(u8)regs].i, qst_registers[(u8)(regs + 1)].i) != 0) {
        qst_registers[(u8)dst].i = 1;
        return;
    }
    qst_registers[(u8)dst].i = 0;
}

void qst_op_p_action_enable(void) {
    TObjPlayer *player;

    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        player->enable_action_input();
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

    point.x = (f32)qst_registers[i++].i;
    point.y = (f32)qst_registers[i++].i;
    point.z = (f32)qst_registers[i++].i;
    TTecLuker::create_for_player((int)((u16)qst_registers[i].i), &point);
}

void qst_op_create_pipe(void) {
    create_quest_telepipe_for_client(((u16) qst_args[0].i));
}

void qst_op_p_setpos(void) {
    Vec pos;
    u16 player;
    u8 reg;
    u8 i;
    TObjPlayer *obj;

    reg = qst_args[1].i;
    player = qst_args[0].i;
    i = reg;
    pos.x = qst_registers[i++].i;
    pos.y = qst_registers[i++].i;
    pos.z = qst_registers[i++].i;
    send_6x24_teleport_player(player, &pos, 182.04445f * qst_registers[i].i);
    obj = get_player_by_client_id(player);
    if (obj != NULL && player == local_client_id) {
        reset_cameras_to_actor(obj, 0);
    }
}

void qst_op_p_enablewarp(void) {
    TObjPlayer::foreach_player(clear_player_flag_4096);
}

void qst_op_p_disablewarp(void) {
    TTecLuker::apply_all_players();
    TObjPlayer::foreach_player(set_player_flag_4096);
}

void qst_op_p_dead(void) {
    s32 dest_reg;
    TObjPlayer *player;
    dest_reg = qst_args[0].i;
    player = get_player_by_client_id(qst_args[1].i);
    if ((player != NULL) && (player->is_script_controlled() == 0)) {
        if (player->obj_isState3_324() != 0) {
            if (player->actorFlags & 0x800) {
                qst_registers[dest_reg].i = 1;
                return;
            }
        } else if (player->check_player_state_flag_2() != 0) {
            qst_registers[dest_reg].i = 1;
            return;
        }
    }
    qst_registers[dest_reg].i = 0;
}

#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
void qst_op_p_hpstat(void) {
    s32 reg;
    f32 pct;
    f32 limit;
    TObjChara *obj;
    f32 hp;
    s32 player;
    QuestValue *args = qst_args;
    QuestValue *regs = qst_registers;
    reg = args[0].i;
    pct = regs[reg].i;
    player = args[1].i;
    if (0.0f == pct) {
        qst_registers[reg].i = 0;
        return;
    }
    limit = 1.0f / pct;
    obj = get_player_by_client_id(player);
    if (obj != NULL) {
        hp = obj->get_actor_hp();
        if (hp / obj->get_hpmax() < limit) {
            qst_registers[reg].i = 1;
            return;
        }
    }
    qst_registers[reg].i = 0;
}
#pragma pop
void qst_op_p_move(u8 regs) {
    Vec pos;
    s32 i = regs;
    s32 yaw;
    u16 id;

    pos.x = (f32) qst_registers[i++].i;
    pos.y = (f32) qst_registers[i++].i;
    pos.z = (f32) qst_registers[i++].i;
    yaw = (s32) (182.04445f * (f32) qst_registers[i++].i);
    id = qst_registers[i++].i;
    send_stop_at_position(id, &pos, yaw);
}

void qst_op_p_look_at(void) {
    quest_player_face_actor((u16) qst_args[0].i, (u16) qst_args[1].i);
}

void qst_op_player_effect_nc(u8 regs) {
    Vec v;
    u16 id;
    s16 kind;
    s32 extra;
    f32 dy;
    TObjCollidable *actor;
    TParticleCtrl *r;
    s32 i;

    i = regs;
    kind = qst_registers[i++].i;
    extra = qst_registers[i++].i;
    id = qst_registers[i++].i;
    dy = qst_registers[i].i;
    actor = find_entity_by_id(id);
    if (actor != NULL) {
        VecCopy(&v, &actor->position);
        v.y += dy;
        r = create_timed_particle_emitter(&v, kind, 0, extra);
        if (r != 0) {
            r->set_flags(0x40);
        }
    }
}

void qst_op_has_ep3_save_file() {
    u8 reg = qst_args[0].i;
    s32 ok = 0;
    if (TAdPlayerLoadGC::probe_card_slot(0) != 0 && TAdPlayerLoadGC::find_card_file(0, "PSO3_CHARACTER") == 0 && TAdPlayerLoadGC::get_load_result(0) == 0) {
        ok = 1;
    }
    if (ok == 0 && TAdPlayerLoadGC::probe_card_slot(1) != 0 && TAdPlayerLoadGC::find_card_file(1, "PSO3_CHARACTER") == 0 && TAdPlayerLoadGC::get_load_result(1) == 0) {
        ok = 1;
    }
    qst_registers[reg].i = ok;
}

void qst_op_particle_id(u8 first) {
    Vec point;
    s32 i = first;
    s16 effect = (s16) qst_registers[i++].i;
    s32 lifetime = qst_registers[i++].i;
    u16 id = (u16) qst_registers[i++].i;
    f32 height = (f32) qst_registers[i].i;
    TObjCollidable *actor = find_entity_by_id(id);
    if (actor != NULL) {
        VecCopy(&point, &actor->position);
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
    TParticleCtrl *r;

    i = regs;
    x = qst_registers[i++].i;
    y = qst_registers[i++].i;
    z = qst_registers[i++].i;
    kind = qst_registers[i++].i;
    extra = qst_registers[i].i;
    v.x = x;
    v.y = y;
    v.z = z;
    r = create_timed_particle_emitter(&v, kind, 0, extra);
    if (r != 0) {
        r->set_flags(0x40);
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
    x = qst_registers[i++].i;
    y = qst_registers[i++].i;
    z = qst_registers[i++].i;
    kind = qst_registers[i++].i;
    extra = qst_registers[i].i;
    v.x = x;
    v.y = y;
    v.z = z;
    create_timed_particle_emitter(&v, kind, 0, extra);
}

void qst_op_particle2() {
    Vec v;
    QuestValue *p = &qst_registers[qst_args[0].i];
    v.x = p[0].f;
    v.y = p[1].f;
    v.z = p[2].f;
    uaddr r = (uaddr)create_timed_particle_emitter(&v, qst_args[1].i, 0, (s32)qst_args[2].f);
    if (r != 0) {
        ((TParticleCtrl *)r)->set_flags(0x40);
    }
}

void qst_op_pl_walk(u8 regs) {
    G_WalkToPosition_6x40 cmd;
    f32 x;
    f32 z;
    u16 player;
    TObjPlayer *obj;
    s32 i;

    i = regs;
    x = qst_registers[i++].i;
    i++;
    z = qst_registers[i++].i;
    player = qst_registers[i].i;
    obj = get_player_by_client_id(player);
    if (obj != NULL) {
        cmd.init();
        cmd.header.client_id = player;
        cmd.pos.x = x;
        cmd.pos.z = z;
        cmd.flags = 0;
        if (obj->actorFlags & 0x100000) {
            cmd.flags |= 8;
        }
        cmd.send();
    }
}

void qst_op_p_look(void) {
    quest_player_look_at_partner((u16) qst_args[0].i);
}
void qst_op_p_col() { set_hashi_versus2_flag(); }

void qst_op_p_noncol() { clear_hashi_versus2_flag(); }

void qst_op_enable_movement1(void) {
    send_code_45_to_player((u16) qst_args[0].i);
}

void qst_op_disable_movement1(void) {
    play_effect((u16) qst_args[0].i);
}
void qst_op_npc_talk(void) { enable_partner_chatter(); }

void qst_op_npc_nont(void) { disable_partner_chatter(); }

void qst_op_npc_kill(void) {
    quest_remove_npc_player(((u16) qst_args[0].i));
}
void qst_op_cam_adj(void* p) { request_follow_camera_recenter(); }

void qst_op_cam_pan(u8 reg) {
    s32 r = reg;
    Vec pos;
    pos.x = qst_registers[r++].i;
    pos.y = qst_registers[r++].i;
    pos.z = qst_registers[r++].i;
    {
        s32 frames = qst_registers[r++].i;
        s32 hold_frames = qst_registers[r].i;
        TCameraPan::create(&pos, frames, hold_frames);
    }
}

void qst_op_nop_86(void) {  }

void qst_op_nop_85(void) {  }
void qst_op_cam_zmout(void *p) { end_conversation_camera(); }

void qst_op_cam_zmin(void *p) { begin_conversation_camera(); }

void qst_op_cam_quake(void) { TCameraCtrl::set_shake_preset(2); }

void qst_op_npc_play(void) {
    send_npc_control_6x69((s32) (u16) qst_args[0].i);
}

void qst_op_npc_stop(void) {
    send_npc_stop_6x69((s32) (u16) qst_args[0].i);
}
void qst_op_npc_crp_id(u8 first) {
    Vec pos;
    int heading;
    int leader;
    int appearance;
    int slot;
    int i = first;

    pos.x = (f32)qst_registers[i++].i;
    pos.y = (f32)qst_registers[i++].i;
    pos.z = (f32)qst_registers[i++].i;
    heading = (int)(182.04445f * (f32)qst_registers[i++].i);
    leader = qst_registers[i++].i;
    slot = qst_registers[i++].i;
    appearance = qst_registers[i++].i;
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

    pos.x = (f32)qst_registers[i++].i;
    pos.y = (f32)qst_registers[i++].i;
    pos.z = (f32)qst_registers[i++].i;
    heading = (int)(182.04445f * (f32)qst_registers[i++].i);
    leader = qst_registers[i++].i;
    appearance = qst_registers[i++].i;
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

    pos.x = (f32)qst_registers[i++].i;
    pos.y = (f32)qst_registers[i++].i;
    pos.z = (f32)qst_registers[i++].i;
    heading = (int)(182.04445f * (f32)qst_registers[i++].i);
    injured = qst_registers[i++].i;
    appearance = qst_registers[i++].i;
    slot = qst_registers[i++].i;
    TLobby::free_luker_object();
    player = new TObjPlayer(tl_03, slot, 6, load_npc_player_template(appearance));
    if (player != NULL) {
        player->control_state = 6;
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

    pos.x = (f32)qst_registers[i++].i;
    pos.y = (f32)qst_registers[i++].i;
    pos.z = (f32)qst_registers[i++].i;
    heading = (int)(182.04445f * (f32)qst_registers[i++].i);
    injured = qst_registers[i++].i;
    appearance = qst_registers[i++].i;
    TLobby::free_luker_object();
    player = new TObjPlayer(tl_03, 3, 6, load_npc_player_template(appearance));
    if (player != NULL) {
        player->control_state = 6;
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
    v.x = qst_registers[i++].i;
    v.y = qst_registers[i++].i;
    v.z = qst_registers[i++].i;
    angle = 182.04445f * qst_registers[i++].i;
    a = qst_registers[i++].i;
    b = qst_registers[i++].i;
    c = qst_registers[i].i;
    TLobby::free_luker_object();
    send_npc_control_create(a, c, b, &v, angle);
    TLobby::clear_quest_vm_flag();
}

void qst_op_npc_crtpk(void) {
    s32 a = qst_args[0].i;
    s32 b = qst_args[1].i;
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

    i = qst_args[0].i;
    arg = qst_args[1].i;
    s.npc_id = qst_registers[i++].i;
    s.base_level = qst_registers[i++].i;

    switch (qst_registers[i++].i) {
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
    s.enemy_lock_on_range = qst_registers[i++].i;
    s.min_distance_from_player = qst_registers[i++].i;
    s.max_distance_from_player = qst_registers[i++].i;
    s.enemy_unlock_range = qst_registers[i++].i;
    s.block_range = qst_registers[i++].i;
    s.attack_range = qst_registers[i++].i;
    s.attack_technique_level = qst_registers[i++].i;
    s.support_technique_level = qst_registers[i++].i;
    s.attack_probability = qst_registers[i++].i;
    s.attack_technique_probability = qst_registers[i++].i;
    s.escort_keep_distance = qst_registers[i].i;

    s.copy_entry_by_index(arg);
}

void qst_op_npc_crt(void) {
    s32 *npc_addr;
    s32 npc_type;
    TLobby::free_luker_object();
    npc_addr = &qst_args[0].i;
    npc_addr = &qst_args[0].i;
    npc_type = qst_args[1].i;
    npc_addr = (s32 *)((u8 *)((s32 *)(uaddr) (u16) qst_args[0].i));
    send_npc_create((saddr)npc_addr, npc_type);
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
    TObjPlayer *p;
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
        p = TObjPlayer::get_player_data(i);
        if (p != NULL) {
            f = p->get_entity_id();
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
    s32 x = qst_args[0].i;
    if (qst_message_window != NULL) {
        dispatch_message_window_text(qst_message_window, (const char *)x, 3);
        qst_suspend_reason = QST_WAIT_MESSAGE;
        return;
    }
    if (qst_message_window_qb != 0) {
        qst_message_window_qb->append_line((const char *)x, 3);
        qst_suspend_reason = QST_WAIT_MESSAGE_QB;
        return;
    }
    qst_args[1].i = x;
    qst_args[0].i = qst_message_speaker;
    qst_op_message();
}

void qst_op_close_msg_qb(void) {
    if (qst_message_window_qb != NULL) {
        qst_message_window_qb->close();
        qst_message_window_qb = 0U;
    }
}

void qst_op_disp_msg_qb(void) {
    s32 t = qst_args[0].i;
    VaCallPair pr = qb_message_window_size[0];
    if (qst_message_window_qb != 0) {
        qst_message_window_qb->close();
        qst_message_window_qb = 0;
    }
    qst_message_window_qb = create_message_window_for_size((NJS_POINT2 *)get_window_layout_position(0x71), (NJS_POINT2 *)&pr);
    (qst_message_window_qb)->append_line((const char *)t, 3);
    ((TWindowBase *)qst_message_window_qb)->set_depth(50030.0f);
    qst_suspend_reason = QST_WAIT_MESSAGE_QB;
}

void qst_op_window_msg(void) {
    s32 text;
    TWindowMessageQuest *window;
    text = qst_args[0].i;
    if (qst_message_window != NULL) {
        qst_message_window->close();
    }
    window = create_quest_message_window();
    qst_message_window = window;
    dispatch_message_window_text(window, (const char *)text, 3);
    qst_suspend_reason = QST_WAIT_MESSAGE;
    TWindowCtrl::set_flag_bit2();
    close_window_if_active(local_client_id);
    request_active_window_close();
    TWindowCtrl::set_close_flag();
}

void qst_op_bgm(void) {
    play_cue_stream_file(qst_bgm_filename_table[qst_args[0].i]);
}

void qst_op_se(void) {
    play_sound_effect(quest_sound_effect_ids[qst_args[0].i], 0, 0, 0);
}

void qst_op_fadeout(void) { TLobby::init_fadeout_state(NULL); qst_suspend_reason = QST_WAIT_FADE; }

void qst_op_fadein(void) { TLobby::set_fade_params(NULL); qst_suspend_reason = QST_WAIT_FADE; }

void qst_op_list(void) {
    char *text;
    TTokenList *list;
    u8 idx;
    s32 i;
    char buf[0x200];
    idx = (u32)qst_args[0].i;
    text = ((char *)qst_args[1].p);
    list = new TTokenList(NULL, 0, 0);
    strncpy(buf, text, 0x1FF);
    trim_whitespace(buf);
    list->tokenize_args(buf);
    qst_list_window = create_window_menu_default(get_window_layout_position(0x37), list->count);
    for (i = 0; i < list->count; i++) {
        qst_list_window->add_text_entry(list->tokens[i], 7, i);
    }
    qst_list_window->calc_window_size();
    align_menu_entry_positions(qst_list_window);
    qst_list_window->set_ready_flag();
    qst_list_window->set_depth(39000.0f);
    qst_registers[idx].i = 0;
    qst_result_register = idx;
    qst_suspend_reason = QST_WAIT_LIST;
    close_window_if_active(local_client_id);
    request_active_window_close();
    TWindowCtrl::set_close_flag();
    delete list;
}

void qst_op_message(void) {
    s32 speaker = qst_args[0].i;
    const char *text = (const char *)qst_args[1].i;
    s32 first;
    TObjPlayer *actor;
    s32 end;
    s32 i;
    close_window_if_active(local_client_id);
    request_active_window_close();
    TWindowCtrl::set_close_flag();
    qst_message_speaker = speaker;
    if (speaker < 100) {
        TWindowCtrl::open(static_cast<u16>(speaker), text, 0x2D);
        TWindowCtrl::set_window_id((u16)speaker);
        qst_suspend_reason = QST_WAIT_MESSAGE;
    } else {
        first = TLobby::get_game_mode();
        end = first + TLobby::get_lobby_flag();
        for (i = first; i < end; i++) {
            actor = TObjPlayer::get_player_data(i);
            if (actor != NULL) {
                s32 identity = actor->get_entity_id();
                s32 entity;
                if (identity < 0x4000) {
                    entity = fn_get_field_3ac(actor);
                } else {
                    entity = get_field_d4(actor);
                }
                if (entity == speaker) {
                    TWindowCtrl::open(static_cast<u16>(identity), text, 0x2D);
                    TWindowCtrl::set_window_id(identity);
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
        qst_registers[j].i = v;
        n--;
    }
}

void qst_op_stack_pushm(s32 regs, s32 count) {
    s32 i;
    for (i = 0; i < count; i++) {
        qst_call_stack_push(qst_registers[(u8)regs++].i);
    }
}

void qst_op_stack_pop(int a0) { qst_registers[(unsigned char)(a0)].i = qst_call_stack_pop(); }

void qst_op_stack_push(s32 reg) {
    qst_call_stack_push((int) (qst_registers[(u8)reg].i));
}

void qst_op_switch_call(s32 reg, u8 count, saddr labels) {
    s32 case_index;
    case_index = qst_registers[(u8)reg].i;
    if ((case_index < (s32) count) && (case_index >= 0)) {
        qst_op_call((u16)((int) (*(u16 *)((s8 *)(labels + (case_index * 2)) + 0))));
    }
}

void qst_op_switch_jmp(s32 reg, u8 count, saddr labels) {
    s32 case_index;
    case_index = qst_registers[(u8)reg].i;
    if ((case_index < (s32) count) && (case_index >= 0)) {
        qst_op_jmp((int) (*(u16 *)((s8 *)(labels + (case_index * 2)) + 0)));
    }
}

void qst_op_jmpi_le(s32 reg, s32 value, s32 label) {
    if ((s32) qst_registers[(u8)reg].i <= value) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmp_le(s32 reg1, s32 reg2, s32 label) {
    if ((s32) qst_registers[(u8)reg1].i <= (s32) qst_registers[(u8)reg2].i) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_ujmpi_le(s32 reg, u32 value, s32 label) {
    if ((u32) qst_registers[(u8)reg].i <= value) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_ujmp_le(s32 reg1, s32 reg2, s32 label) {
    if ((u32) qst_registers[(u8)reg1].i <= (u32) qst_registers[(u8)reg2].i) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmpi_ge(s32 reg, s32 value, s32 label) {
    if ((s32) qst_registers[(u8)reg].i >= value) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmp_ge(s32 reg1, s32 reg2, s32 label) {
    if ((s32) qst_registers[(u8)reg1].i >= (s32) qst_registers[(u8)reg2].i) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_ujmpi_ge(s32 reg, u32 value, s32 label) {
    if ((u32) qst_registers[(u8)reg].i >= value) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_ujmp_ge(s32 reg1, s32 reg2, s32 label) {
    if ((u32) qst_registers[(u8)reg1].i >= (u32) qst_registers[(u8)reg2].i) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmpi_lt(s32 reg, s32 value, s32 label) {
    if ((s32) qst_registers[(u8)reg].i < value) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmp_lt(s32 reg1, s32 reg2, s32 label) {
    if ((s32) qst_registers[(u8)reg1].i < (s32) qst_registers[(u8)reg2].i) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_ujmpi_lt(s32 reg, u32 value, s32 label) {
    if ((u32) qst_registers[(u8)reg].i < value) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_ujmp_lt(s32 reg1, s32 reg2, s32 label) {
    if ((u32) qst_registers[(u8)reg1].i < (u32) qst_registers[(u8)reg2].i) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmpi_gt(s32 reg, s32 value, s32 label) {
    if ((s32) qst_registers[(u8)reg].i > value) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmp_gt(s32 reg1, s32 reg2, s32 label) {
    if ((s32) qst_registers[(u8)reg1].i > (s32) qst_registers[(u8)reg2].i) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_ujmpi_gt(s32 reg, u32 value, s32 label) {
    if ((u32) qst_registers[(u8)reg].i > value) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_ujmp_gt(s32 reg1, s32 reg2, s32 label) {
    if ((u32) qst_registers[(u8)reg1].i > (u32) qst_registers[(u8)reg2].i) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmpi_ne(s32 reg, s32 value, s32 label) {
    if (value != (s32) qst_registers[(u8)reg].i) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmp_ne(s32 reg1, s32 reg2, s32 label) {
    if ((s32) qst_registers[(u8)reg1].i != (s32) qst_registers[(u8)reg2].i) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmpi_eq(s32 reg, s32 value, s32 label) {
    if (value == (s32) qst_registers[(u8)reg].i) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmp_eq(s32 reg1, s32 reg2, s32 label) {
    if ((s32) qst_registers[(u8)reg1].i == (s32) qst_registers[(u8)reg2].i) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmp_off(s32 label, u8 count, u8 *regs) {
    s32 all_off = 1;
    while (count != 0) {
        u8 reg = *regs;
        count--;
        regs++;
        all_off &= (u8) ((s32) qst_registers[(u8)reg].i == 0);
    }
    if (all_off != 0) {
        qst_pc = qst_function_table[(u16)label];
    }
}

void qst_op_jmp_on(s32 label, u8 count, u8 *regs) {
    s32 i;
    for (i = 0; i < count; i++) {
        if ((s32) qst_registers[(u8)*regs++].i == 0) {
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
    qst_registers[(u8)dst].i %= value;
}

void qst_op_mod(s32 dst, s32 src) {
    qst_registers[(u8)dst].i %= qst_registers[(u8)src].i;
}

void qst_op_jmp(int a0) { qst_pc = qst_function_table[(u16)a0]; }

void qst_op_xori(s32 dst, s32 value) {
    qst_registers[(u8)dst].i ^= value;
}

void qst_op_xor(s32 dst, s32 src) {
    qst_registers[(u8)dst].i ^= qst_registers[(u8)src].i;
}

void qst_op_ori(s32 dst, s32 value) {
    qst_registers[(u8)dst].i |= value;
}

void qst_op_or(s32 dst, s32 src) {
    qst_registers[(u8)dst].i |= qst_registers[(u8)src].i;
}

void qst_op_andi(s32 dst, s32 value) {
    qst_registers[(u8)dst].i &= value;
}

void qst_op_and(s32 dst, s32 src) {
    qst_registers[(u8)dst].i &= qst_registers[(u8)src].i;
}

void qst_op_divi(s32 dst, s32 value) {
    qst_registers[(u8)dst].i /= value;
}

void qst_op_div(s32 dst, s32 src) {
    qst_registers[(u8)dst].i /= (s32) qst_registers[(u8)src].i;
}

void qst_op_muli(s32 dst, s32 value) {
    qst_registers[(u8)dst].i *= value;
}

void qst_op_mul(s32 dst, s32 src) {
    qst_registers[(u8)dst].i *= qst_registers[(u8)src].i;
}

void qst_op_subi(s32 dst, s32 value) {
    qst_registers[(u8)dst].i -= value;
}

void qst_op_sub(s32 dst, s32 src) {
    qst_registers[(u8)dst].i -= qst_registers[(u8)src].i;
}

void qst_op_addi(int a0, int a1) { qst_registers[(unsigned char)(a0)].i += a1; }

void qst_op_add(s32 dst, s32 src) {
    qst_registers[(u8)dst].i += qst_registers[(u8)src].i;
}

void qst_op_gget(u16 flag, s32 dst) {
    if (get_story_flag((flag)) != 0) {
        qst_registers[(u8)dst].i = 1;
        return;
    }
    qst_registers[(u8)dst].i = 0;
}

void qst_op_glet(u16 flag, s32 reg) {
    if ((s32) qst_registers[(u8)reg].i != 0) {
        set_story_flag_or_send_quest_flag(flag);
        return;
    }
    clear_story_flag((flag));
}

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
    set_story_flag_or_send_quest_flag(flag);
}

void qst_op_rev(s32 reg) {
    qst_registers[(u8)reg].i = qst_registers[(u8)reg].i == 0;
}

void qst_op_clear(s32 reg) {
    qst_registers[(u8)reg].i = 0;
}

void qst_op_set(s32 reg) {
    qst_registers[(u8)reg].i = 1;
}

void qst_op_leto(s32 dst, s32 label) {
    qst_registers[(u8)dst].p = &qst_function_table[(u16)label];
}

void qst_op_leta(s32 dst, s32 src) {
    qst_registers[(u8)dst].p = &qst_registers[(u8)src];
}

void qst_op_letw(int a0, int a1) { qst_registers[(unsigned char)(a0)].i = (a1 & 0xffff); }

void qst_op_letb(int a0, int a1) { qst_registers[(unsigned char)(a0)].i = (a1 & 0xff); }

void qst_op_leti(int a0, int a1) { qst_registers[(unsigned char)(a0)].i = a1; }

void qst_op_let(s32 dst, s32 src) {
    qst_registers[(u8)dst].i = qst_registers[(u8)src].i;
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
extern char qst_cstring_buffer[];

void qst_getargs_u16_u8(s32 op) {
    QuestHandlerU16U8 fn = (QuestHandlerU16U8)qst_opcode_table[op].handler;
    u16 a = read_be_u16();
    fn(a, read_u8());
}

void qst_getargs_u16(s32 op) {
    QuestHandlerU16 fn = (QuestHandlerU16)qst_opcode_table[op].handler;
    fn(read_be_u16());
}

void qst_getargs_cstring(s32 op) {
    QuestHandlerString fn = (QuestHandlerString)qst_opcode_table[op].handler;
    append_string_to_buffer(qst_cstring_buffer);
    fn(qst_cstring_buffer);
}

void qst_getargs_s32_u8_s16ptr(s32 op) {
    s16 buf[16];
    SwitchJumpHandler fn = (SwitchJumpHandler)qst_opcode_table[op].handler;
    s32 first = ((s32 (*)(void))read_u8)();
    u8 count = ((s32 (*)(void))read_u8)();
    s32 i;

    for (i = 0; i < count; i++) {
        buf[i] = ((s16 (*)(void))read_be_u16)();
    }
    fn(first, count, buf);
}

void qst_getargs_u16_u8_u8ptr(s32 op) {
    u8 buf[16];
    JumpOnHandler fn = (JumpOnHandler)qst_opcode_table[op].handler;
    u16 label = ((s32 (*)(void))read_be_u16)();
    u8 count = ((s32 (*)(void))read_u8)();
    s32 i;

    for (i = 0; i < count; i++) {
        buf[i] = ((s32 (*)(void))read_u8)();
    }
    fn(label, count, buf);
}

void qst_getargs_u8_s32_u16(s32 op) {
    QuestHandlerU8S32U16 fn = (QuestHandlerU8S32U16)qst_opcode_table[op].handler;
    u8 a = read_u8();
    s32 b = stream_read_be32();
    fn(a, b, read_be_u16());
}

void qst_getargs_u8_u8_u16(s32 op) {
    QuestHandlerU8U8U16 fn = (QuestHandlerU8U8U16)qst_opcode_table[op].handler;
    u8 a = read_u8();
    u8 b = read_u8();
    fn(a, b, read_be_u16());
}

void qst_getargs_u8_u16(s32 op) {
    QuestHandlerU8U16 fn = (QuestHandlerU8U16)qst_opcode_table[op].handler;
    u8 a = read_u8();
    fn(a, read_be_u16());
}

void qst_getargs_u16_2(s32 op) {
    QuestHandlerU16 fn = (QuestHandlerU16)qst_opcode_table[op].handler;
    fn(read_be_u16());
}

void qst_getargs_s32(s32 op) {
    QuestHandlerS32 fn = (QuestHandlerS32)qst_opcode_table[op].handler;
    fn(stream_read_be32());
}

void qst_getargs_u8_s32(s32 op) {
    QuestHandlerU8S32 fn = (QuestHandlerU8S32)qst_opcode_table[op].handler;
    u8 a = read_u8();
    fn(a, stream_read_be32());
}

void qst_getargs_u8_u8(s32 op) {
    QuestHandlerU8U8 fn = (QuestHandlerU8U8)qst_opcode_table[op].handler;
    u8 a = read_u8();
    fn(a, read_u8());
}

void qst_getargs_u8(s32 op) {
    QuestHandlerU8 fn = (QuestHandlerU8)qst_opcode_table[op].handler;
    fn(read_u8());
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

void qst_call_stack_push(s32 value)
{
  qst_call_stack[qst_call_stack_depth++] = value;
}
u8 *qst_label_address(int label) {  return qst_code + qst_function_table[(u16)label]; }
void append_string_to_buffer(char *dest) {
    s32 string_length;

    string_length = strlen((const char *)(qst_code + qst_pc));
    expand_message_substitutions(qst_code + qst_pc, dest);
    qst_pc += string_length + 1;
}

s32 stream_read_be32(void) {
    u32 value;

    memcpy(&value, qst_code + qst_pc, 4);
    qst_pc += 4;
    bswap_32(&value);
    return value;
}

u16 read_be_u16(void) {
    u16 value;

    memcpy(&value, qst_code + qst_pc, 2);
    qst_pc += 2;
    bswap_16(&value);
    return value;
}

QuestValue qst_args[8];
s32 qst_call_stack[64];
char quest_player_name_buffer[16];
char quest_player_class_name_buffer[16];
BattleRules battle_rules;
char qst_cstring_buffer[0x404];


unsigned char read_u8() { return qst_code[qst_pc++]; }

quest_suspend_reason QuestVmContext::dispatch() {
    quest_suspend_reason reason;

    load_globals();
    reason = dispatch_quest_opcode();
    save_globals();
    return reason;
}


void close_windows() {
    if (qst_message_window != NULL) {
        qst_message_window->close();
        qst_message_window = NULL;
    }
    if (qst_message_window_qb != NULL) {
        qst_message_window_qb->close();
        qst_message_window_qb = NULL;
    }
    if (qst_list_window != NULL) {
        qst_list_window->close();
        qst_list_window = NULL;
    }
    if (qst_item_name_entry != NULL) {
        qst_item_name_entry->queue_destruction();
        qst_item_name_entry = NULL;
    }
    if (qst_item_name_select != NULL) {
        qst_item_name_select->queue_destruction();
        qst_item_name_select = NULL;
    }
    if (qst_item_ok_window != NULL) {
        qst_item_ok_window->queue_destruction();
        qst_item_ok_window = NULL;
    }
    if (qst_pack_select_window != NULL) {
        qst_pack_select_window->queue_destruction();
        qst_pack_select_window = NULL;
    }
    if (qst_pack_select_help_window != NULL) {
        qst_pack_select_help_window->queue_destruction();
        qst_pack_select_help_window = NULL;
    }
}


quest_suspend_reason dispatch_quest_opcode(void) {
    s32 op;
    qst_suspend_reason = QST_RUNNING;
    while (qst_suspend_reason == QST_RUNNING) {
        op = read_u8();
        switch (op) {
        case 0xF8:
            op = read_u8() + 0x100;
            break;
        case 0xF9:
            op = read_u8() + 0x200;
            break;
        }
        qst_opcode_table[op].decode_arguments(op);
    }
    return qst_suspend_reason;
}

void QuestVmContext::save_globals() {
    code = qst_code;
    function_table = qst_function_table;
    registers = qst_registers;
    message_window = qst_message_window;
    list_window = qst_list_window;
    result_register = qst_result_register;
    call_stack_depth = qst_call_stack_depth;
    pc = qst_pc;
    unk24 = lbl_805D5E94;
    unk28 = lbl_805D5E9C;
    message_speaker = qst_message_speaker;
    arg_count = qst_arg_count;
    memcpy(args, qst_args, sizeof(args));
    memcpy(call_stack, qst_call_stack, sizeof(call_stack));
    qst_message_window = NULL;
    qst_list_window = NULL;
    unk154 = TLobby__data_805D5EA8;
    unk155 = TLobby__data_805D5EA9;
    unk156 = TLobby__data_805D5EAA;
    unk158 = TLobby__data_805D5EAC;
    item_name_entry = qst_item_name_entry;
    qst_item_name_entry = NULL;
    item_name_select = qst_item_name_select;
    qst_item_name_select = NULL;
    item_ok_window = qst_item_ok_window;
    qst_item_ok_window = NULL;
    pack_select_window = qst_pack_select_window;
    qst_pack_select_window = NULL;
    pack_select_help_window = qst_pack_select_help_window;
    qst_pack_select_help_window = NULL;
    statistic_arg1 = qst_statistic_arg1;
    statistic_arg2 = qst_statistic_arg2;
}

void QuestVmContext::load_globals() {
    qst_code = code;
    qst_function_table = function_table;
    qst_registers = registers;
    qst_message_window = message_window;
    qst_list_window = list_window;
    qst_result_register = result_register;
    qst_call_stack_depth = call_stack_depth;
    qst_pc = pc;
    lbl_805D5E94 = unk24;
    lbl_805D5E9C = unk28;
    qst_message_speaker = message_speaker;
    qst_arg_count = arg_count;
    memcpy(qst_args, args, sizeof(args));
    memcpy(qst_call_stack, call_stack, sizeof(call_stack));
    TLobby__data_805D5EA8 = unk154;
    TLobby__data_805D5EA9 = unk155;
    TLobby__data_805D5EAA = unk156;
    TLobby__data_805D5EAC = unk158;
    qst_item_name_entry = item_name_entry;
    qst_item_name_select = item_name_select;
    qst_item_ok_window = item_ok_window;
    qst_pack_select_window = pack_select_window;
    qst_pack_select_help_window = pack_select_help_window;
    qst_statistic_arg1 = statistic_arg1;
    qst_statistic_arg2 = statistic_arg2;
}

LAYOUT_ASSERT(QuestVmContext_size, sizeof(QuestVmContext) == 0x174);

void init_quest_script_context(QuestBinHeader *h, QuestVmContext *c) {
    u32 n;
    u32 i;
    bswap_32(&h->code_offset);
    bswap_32(&h->function_table_offset);
    bswap_32(&h->size);
    bswap_16(&h->unused[0]);
    bswap_16(&h->unused[1]);
    bswap_16((u16 *)&h->quest_number);
    qst_statistic_id = h->quest_number;
    c->code = (u8 *)h + h->code_offset;
    c->function_table = (s32 *)((u8 *)h + h->function_table_offset);
    c->registers = (QuestValue *)((u8 *)h + h->size);
    c->message_window = NULL;
    c->list_window = NULL;
    c->result_register = 0;
    c->call_stack_depth = 0;
    c->pc = 0;
    c->unk24 = 0;
    c->unk28 = 0;
    c->arg_count = 0;
    memset(c->args, 0, sizeof(c->args));
    memset(c->registers, 0, 0x400);
    memset(c->call_stack, 0, sizeof(c->call_stack));
    n = (h->size - h->function_table_offset) / 4;
    for (i = 0; i < n; i++) {
        bswap_32((u32 *)&c->function_table[i]);
    }
    TLobby__data_805D5EA8 = 0;
    TLobby__data_805D5EA9 = 0;
    TLobby__data_805D5EAA = 0;
    TLobby__data_805D5EAC = 0;
    c->item_name_entry = NULL;
    c->item_name_select = NULL;
    c->item_ok_window = NULL;
    c->pack_select_window = NULL;
    c->pack_select_help_window = NULL;
    c->statistic_arg1 = 0;
    c->statistic_arg2 = 0;
}

char *get_entered_item_name(void) {
    return entered_item_name;
}

void TLobby::clear_quest_vm_flag() {
    if (quest_mission_manager != NULL) {
        quest_mission_manager->clear_update_suspension();
    }
}

void TLobby::free_luker_object() {
    if (quest_mission_manager != NULL) {
        quest_mission_manager->suspend_update();
    }
}

s32 TObjPlayer::test_action_80000() {
    return test_action_mask(0x80000);
}
s32 TObjPlayer::test_action_40000() {
    return test_action_mask(0x40000);
}
int test_player_action_10000(TObjPlayer *p) {
    return p->test_action_mask(0x10000);
}
s32 TObjPlayer::test_action_8000() {
    return test_action_mask(0x8000);
}
int TObjPlayer::check_flag_24576() { return test_action_mask(24576); }
int test_player_action_400(TObjPlayer *p) { return p->test_action_mask(1024); }
int test_player_action_200(TObjPlayer *p) { return p->test_action_mask(512); }
int test_player_action_100(TObjPlayer *p) { return p->test_action_mask(256); }
int test_player_action_E0(TObjPlayer *p) { return p->test_action_mask(224); }
int TObjPlayer::test_flag_16() { return test_action_mask(16); }
s32 TObjPlayer::test_action_4() { return test_action_mask(4); }

int test_player_action_2(TObjPlayer *p) { return p->test_action_mask(2); }

void clear_player_flag_4096(TObjPlayer *p) { p->clear_flag_4096(); }
void set_player_flag_4096(TObjPlayer *p) { p->set_flag_4096(); }
s32 get_field_d4(void* p) { return *(s32*)((char*)p + 0xd4); }
s32 fn_get_field_3ac(void* p) { return *(s32*)((char*)p + 0x3ac); }

void TObject::toggle_pause() { m_flags ^= PAUSE_UPDATE; }

void TObjPlayer::set_kill_count(s16 count) { kill_count = count; }

void gba_set_identifiers(int a0, int a1) { gba_identifier_value = a1; gba_identifier_slot_plus_1 = (a0 + 0x1); }

int get_gba_download_state(void) {  return gba_download_state; }

Vec *set_quest_col_warp_position(TObjQuestColApcINW *trigger, const Vec *position) {
    return VecCopy(&trigger->warp_pos, position);
}
void CurvePathPoint::bswap() {
    bswap_32((u32 *)&pos.x);
    bswap_32((u32 *)&pos.y);
    bswap_32((u32 *)&pos.z);
    bswap_32((u32 *)&length);
}

void set_screen_bw(void) { camera_capture_flags = (camera_capture_flags | 0x10); }

void G_SyncQuestRegister_6x77::send() {
    bswap();
    send_subcommand((u8 *)this);
}

void G_SyncQuestRegister_6x77::bswap() {
    header.bswap();
    bswap_16(&register_number);
    bswap_16(&unused);
    bswap_32(&value);
}

void G_SyncQuestRegister_6x77::init() {
    header.subcommand = 0x77;
    header.size = 3;
}

int TLobby::is_warning_aram_load_done() {  return warning_aram_load_done_flag; }

int TLobby::get_lobby_count() {  return lobby_count_value; }

void clear_lobby_count(void) { lobby_count_value = 0; }

Vec *copy_position(Vec *dst, const Vec *src) { return VecCopy(dst, src); }

#pragma push
#pragma fp_contract on
void BattleMovementParams::bswap() {
    s32 i;
    for (i = 0; i < 6; i++) {
        bswap_32(&words.floats[i]);
        bswap_32(&words.integers[i]);
    }
}
#pragma pop

void PlayerTechniqueState::disable_techniques() { flags.set(2); }

void set_ult_map(void) { lobby_online_ready_flag = 1; }

void TLobby::set_lobby_id(int a0) { current_lobby_id = a0; }

void TLobby::set_area_total(int a0) { area_total = a0; }

void override_warp_dest_floor(void) { lobby_quest_progress_flag = 1; }

void disable_quest_warp(void) { quest_warp_enabled = 0; }

int quest_op_F822_stub(s32) { return -1; }
int quest_op_F821_stub(s32, s32, s32, TItemData *) { return 0; }
int quest_op_F822_split_screen_stub(s32) { return -1; }
int quest_op_F821_split_screen_stub(s32, s32, s32, TItemData *) { return 0; }
