#include <string.h>
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TUnk_804C8678.h"
#include "pso/ui/window/TWindowMessageQuest.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/quest/QuestVm.h"
#include "pso/quest/TQuestColCtrl.h"
#include "pso/object/quest/TObjQuestColApcINW.h"
#include "pso/system/vector.h"
#include "pso/quest/QuestScriptFormat.h"
#include "pso/system/data/FlagWord.h"
#include "pso/system/GbaAramCache.h"
#include "types.h"
#include "pso/object/warp/ForestWarpResources.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/unk/TLobby_801F2D2C.h"
#include "pso/unk/TLobby.h"
#include "pso/system/task/TObject.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/object/TObjLuker.h"
#include "pso/player/TObjPlayer.h"

struct Op_801F2E64 { void (*fn)(s32); u32 pad; };

extern "C" {
int bswap_32__FPUl(void*);
extern s32 lbl_805D5E94;
extern s32 lbl_805D5E9C;
extern u8 TLobby__data_805D5EA8;
extern u8 TLobby__data_805D5EA9;
extern u16 TLobby__data_805D5EAA;
extern u16 TLobby__data_805D5EAC;
struct EnteredItemName { s32 value; u8 remaining[0xC]; };
extern EnteredItemName entered_item_name;
extern struct Op_801F2E64 qst_opcode_table[];
int bswap_16__FPUs(void*);
int VecCopy__FP3VecPC3Vec(void*);

unsigned char TLobby::read_packet_byte() { return qst_code[qst_pc++]; }

quest_suspend_reason QuestVmContext::dispatch() {
    quest_suspend_reason reason;

    load_globals();
    reason = dispatch_quest_opcode();
    save_globals();
    return reason;
}


void TLobby::close_windows() {
    if (qst_message_window != NULL) {
        qst_message_window->close();
        qst_message_window = NULL;
    }
    if (qst_message_window_qb != NULL) {
        qst_message_window_qb->close();
        qst_message_window_qb = NULL;
    }
    if (qst_list_window != NULL) {
        ((TWindowBase *)qst_list_window)->close();
        qst_list_window = NULL;
    }
    if (qst_item_name_entry != NULL) {
        ((TObject *)qst_item_name_entry)->queue_destruction();
        qst_item_name_entry = NULL;
    }
    if (qst_item_name_select != NULL) {
        ((TObject *)qst_item_name_select)->queue_destruction();
        qst_item_name_select = NULL;
    }
    if (qst_item_ok_window != NULL) {
        ((TObject *)qst_item_ok_window)->queue_destruction();
        qst_item_ok_window = NULL;
    }
    if (qst_pack_select_window != NULL) {
        ((TObject *)qst_pack_select_window)->queue_destruction();
        qst_pack_select_window = NULL;
    }
    if (qst_pack_select_help_window != NULL) {
        ((TObject *)qst_pack_select_help_window)->queue_destruction();
        qst_pack_select_help_window = NULL;
    }
}
}


quest_suspend_reason dispatch_quest_opcode(void) {
    s32 op;
    qst_suspend_reason = QST_RUNNING;
    while (qst_suspend_reason == QST_RUNNING) {
        op = TLobby::read_packet_byte();
        switch (op) {
        case 0xF8:
            op = TLobby::read_packet_byte() + 0x100;
            break;
        case 0xF9:
            op = TLobby::read_packet_byte() + 0x200;
            break;
        }
        qst_opcode_table[op].fn(op);
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
    bswap_32__FPUl(&h->code_offset);
    bswap_32__FPUl(&h->function_table_offset);
    bswap_32__FPUl(&h->size);
    bswap_16__FPUs((void *)((u8 *)h + 0x0C));
    bswap_16__FPUs((void *)((u8 *)h + 0x0E));
    bswap_16__FPUs((void*)((u8 *)h + 0x12));
    qst_statistic_id = h->quest_number;
    c->code = (u8 *)h + h->code_offset;
    c->function_table = (s32 *)((u8 *)h + h->function_table_offset);
    c->registers = (s32 *)((u8 *)h + h->size);
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
        bswap_32__FPUl(&c->function_table[i]);
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

s32 *TObjItemOKWindow__sub_801F3268(void) {
    return &entered_item_name.value;
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
void TLobby__sub_801F3314(saddr player) {
    ((TObjPlayer *)player)->test_action_mask(0x10000);
}
s32 TObjPlayer::test_action_8000() {
    return test_action_mask(0x8000);
}
int TLobby::check_flag_24576() { return ((TObjPlayer *)this)->test_action_mask(24576); }
int TLobby__sub_801F3384(void* p) { return ((TObjPlayer *)p)->test_action_mask(1024); }
int TLobby__sub_801F33A8(void* p) { return ((TObjPlayer *)p)->test_action_mask(512); }
int TLobby__sub_801F33CC(void* p) { return ((TObjPlayer *)p)->test_action_mask(256); }
int TLobby__sub_801F33F0(void* p) { return ((TObjPlayer *)p)->test_action_mask(224); }
int TLobby::test_flag_16() { return ((TObjPlayer *)this)->test_action_mask(16); }
s32 TObjPlayer::test_action_4() { return test_action_mask(4); }

int TLobby__sub_801F345C(void* p) { return ((TObjPlayer *)p)->test_action_mask(2); }

void fn_801F3480(void* p) { ((TObjPlayer *)p)->clear_flag_4096(); }
void fn_801F34A0(void* p) { ((TObjPlayer *)p)->set_flag_4096(); }
s32 get_field_d4(void* p) { return *(s32*)((char*)p + 0xd4); }
s32 fn_get_field_3ac(void* p) { return *(s32*)((char*)p + 0x3ac); }

void TObject::toggle_pause() { m_flags ^= PAUSE_UPDATE; }

void TLobby::set_floor(s16 v) { *(s16*)((char*)this + 0x11a) = v; }

    extern unsigned char lbl_805D6CD9;
    extern short lbl_805D6CDA;
void TLobby__sub_801F34E8(int a0, int a1) { lbl_805D6CD9 = a1; lbl_805D6CDA = (a0 + 0x1); }

    extern int TLobby__data_805D6CCC;
int TLobby__sub_801F34F8(void) {  return TLobby__data_805D6CCC; }

Vec *TLobby__sub_801F3500(TObjQuestColApcINW *trigger, const Vec *position) {
    return VecCopy(&trigger->warp_pos, position);
}
void TLobby::bswap_4x32() { bswap_32__FPUl(this); bswap_32__FPUl((char*)this + 0x4); bswap_32__FPUl((char*)this + 0x8); bswap_32__FPUl((char*)this + 0xc); }

    extern unsigned char camera_capture_flags;
void TLobby__sub_801F3568(void) { camera_capture_flags = (camera_capture_flags | 0x10); }

void TLobby::sync_quest_register_and_send() { TLobby::bswap_header(this); send_subcommand((u8 *)this); }
void TLobby::bswap_header(void* p) { ((G_ClientIDHeader *)p)->bswap(); bswap_16__FPUs((char*)p + 0x4); bswap_16__FPUs((char*)p + 0x6); bswap_32__FPUl((char*)p + 0x8); }
void build_6x77_sync_quest_register(void* p) { *(u8*)((char*)p + 0x0) = 119; *(u8*)((char*)p + 0x1) = 3; }

int TLobby::get_field_6CE8() {  return warning_aram_load_done_flag; }

int TLobby::get_lobby_count() {  return lobby_count_value; }

void TLobby__sub_801F3614(void) { lobby_count_value = 0; }

int TLobby::copy_position() { return VecCopy__FP3VecPC3Vec(this); }

#pragma push
#pragma fp_contract on
void TLobby::bswap_entry_words(s32 arg0) {
    s32 var_r31;
    saddr temp_r30;
    s32 i;
    i = 0;
    var_r31 = 0;
    do {
        temp_r30 = arg0 + var_r31;
        bswap_32__FPUl((void*)temp_r30);
        bswap_32__FPUl((void*)(temp_r30 + 0x18));
        i += 1;
        var_r31 += 4;
    } while (i < 6);
}
#pragma pop

void TLobby__sub_801F3694(void* p) { ((FlagWord *)((char*)p + 0x10))->set(2); }

    extern int lobby_online_ready_flag;
void TLobby__sub_801F36BC(void) { lobby_online_ready_flag = 1; }

    extern int current_lobby_id;
void TLobby::set_lobby_id(int a0) { current_lobby_id = a0; }

    extern int lbl_805D3614;
void TLobby::set_global_805D3614(int a0) { lbl_805D3614 = a0; }

void TLobby__sub_801F36D8(void) { lobby_quest_progress_flag = 1; }

void TLobby__sub_801F36E4(void) { quest_warp_enabled = 0; }

int TLobby__sub_801F36F0(void) { return -1; }
int TLobby__sub_801F36F8(void) { return 0; }
int TLobby__sub_801F3700(void) { return -1; }
int TLobby__sub_801F3708(void) { return 0; }
