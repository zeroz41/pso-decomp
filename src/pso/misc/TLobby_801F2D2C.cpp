#include "pso/protocol/protocol_types.h"
#include "pso/misc/TWindowBase.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/quest/QuestVm.h"
#include "pso/system/FlagWord.h"
#include "types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/misc/TLobby_801F2D2C.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/misc/TLobby.h"
#include "pso/TObject.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/object/TObjLuker.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_801F2EF4_TLobby__data_80512220 { s32 value; u8 remaining[0x1C]; };
typedef char RecoveredGlobal_801F2EF4_TLobby__data_80512220_size[sizeof(RecoveredGlobal_801F2EF4_TLobby__data_80512220) == 0x20 ? 1 : -1];

struct RecoveredGlobal_801F3268_lbl_80512B18 {
    s32 value;
    u8 remaining[0xC];
};

struct Op_801F2E64 { void (*fn)(s32); u32 pad; };

struct Hdr_801F3124 {
    u32 off0;
    u32 off4;
    u32 off8;
    u16 hC;
    u16 hE;
    u16 h10;
    s8 b12;
};

extern "C" {
int bswap_32__FPUl(void*);
s32 memcpy(void *, void *, int);
extern s32 lbl_805D5E94;
extern s32 lbl_805D5E9C;
extern u8 TLobby__data_805D5EA8;
extern u8 TLobby__data_805D5EA9;
extern u16 TLobby__data_805D5EAA;
extern u16 TLobby__data_805D5EAC;
extern RecoveredGlobal_801F3268_lbl_80512B18 entered_item_name;
extern struct Op_801F2E64 qst_opcode_table[];
int bswap_16__FPUs(void*);
void *memset(void *, int, u32);
void init_quest_script_context(Hdr_801F3124 *h, QuestVmContext *c);
int test_action_mask__10TObjPlayerFl(void*, int);
int VecCopy__FP3VecPC3Vec(void*);
void queue_destruction__7TObjectFv(void *arg0);
int set__8FlagWordFUl(void*, int);

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
        ((TWindowBase *)qst_message_window)->close();
        qst_message_window = NULL;
    }
    if (qst_message_window_qb != NULL) {
        ((TWindowBase *)qst_message_window_qb)->close();
        qst_message_window_qb = NULL;
    }
    if (qst_list_window != NULL) {
        ((TWindowBase *)qst_list_window)->close();
        qst_list_window = NULL;
    }
    if (qst_item_name_entry != NULL) {
        queue_destruction__7TObjectFv(qst_item_name_entry);
        qst_item_name_entry = NULL;
    }
    if (qst_item_name_select != NULL) {
        queue_destruction__7TObjectFv(qst_item_name_select);
        qst_item_name_select = NULL;
    }
    if (qst_item_ok_window != NULL) {
        queue_destruction__7TObjectFv(qst_item_ok_window);
        qst_item_ok_window = NULL;
    }
    if (qst_pack_select_window != NULL) {
        queue_destruction__7TObjectFv(qst_pack_select_window);
        qst_pack_select_window = NULL;
    }
    if (qst_pack_select_help_window != NULL) {
        queue_destruction__7TObjectFv(qst_pack_select_help_window);
        qst_pack_select_help_window = NULL;
    }
}
}

extern u32 quest_mission_manager;

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

typedef char QuestVmContext_size[sizeof(QuestVmContext) == 0x174 ? 1 : -1];

typedef char RecoveredGlobal_801F3268_lbl_80512B18_size[sizeof(RecoveredGlobal_801F3268_lbl_80512B18) == 0x10 ? 1 : -1];

void init_quest_script_context(Hdr_801F3124 *h, QuestVmContext *c) {
    u32 n;
    u32 i;
    bswap_32__FPUl(&h->off0);
    bswap_32__FPUl(&h->off4);
    bswap_32__FPUl(&h->off8);
    bswap_16__FPUs(&h->hC);
    bswap_16__FPUs(&h->hE);
    bswap_16__FPUs((void*)((u8 *)h + 0x12));
    qst_statistic_id = h->b12;
    c->code = (u8 *)h + h->off0;
    c->function_table = (s32 *)((u8 *)h + h->off4);
    c->registers = (s32 *)((u8 *)h + h->off8);
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
    n = (h->off8 - h->off4) / 4;
    for (i = 0; i < n; i++) {
        bswap_32__FPUl(&c->function_table[i]);
    }
    (*(s8 *)&TLobby__data_805D5EA8) = 0;
    (*(s8 *)&TLobby__data_805D5EA9) = 0;
    (*(s16 *)&TLobby__data_805D5EAA) = 0;
    (*(s16 *)&TLobby__data_805D5EAC) = 0;
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
    if ((u32) quest_mission_manager != NULL) {
        ((TQuestVmDownLoadServer *)quest_mission_manager)->clear_flag4_bit4();
    }
}

void TLobby::free_luker_object() {
    if ((u32) quest_mission_manager != NULL) {
        ((TObject *)quest_mission_manager)->suspend_update();
    }
}

void TLobby::set_flag_80000() {
    s32 arg0 = (s32)this;
    test_action_mask__10TObjPlayerFl((void*)arg0, 0x80000);
}
void TLobby::set_flag_40000() {
    test_action_mask__10TObjPlayerFl(this, 0x40000);
}
void TLobby__sub_801F3314(s32 arg0) {
    test_action_mask__10TObjPlayerFl((void*)arg0, 0x10000);
}
void TLobby::set_flag_8000() {
    s32 arg0 = (s32)this;
    test_action_mask__10TObjPlayerFl((void*)arg0, 0x8000);
}
int TLobby::check_flag_24576() { return test_action_mask__10TObjPlayerFl(this, 24576); }
int TLobby__sub_801F3384(void* p) { return test_action_mask__10TObjPlayerFl(p, 1024); }
int TLobby__sub_801F33A8(void* p) { return test_action_mask__10TObjPlayerFl(p, 512); }
int TLobby__sub_801F33CC(void* p) { return test_action_mask__10TObjPlayerFl(p, 256); }
int TLobby__sub_801F33F0(void* p) { return test_action_mask__10TObjPlayerFl(p, 224); }
int TLobby::test_flag_16() { return test_action_mask__10TObjPlayerFl(this, 16); }
int set_flag_4__6TLobbyFPv(void* p) { return test_action_mask__10TObjPlayerFl(p, 4); }

int TLobby__sub_801F345C(void* p) { return test_action_mask__10TObjPlayerFl(p, 2); }

int fn_801F3480(void* p) { return ((TObjPlayer *)p)->has_item_flag_4096(); }
int fn_801F34A0(void* p) { return ((TObjPlayer *)p)->check_technique_flag(); }
s32 get_field_d4(void* p) { return *(s32*)((char*)p + 0xd4); }
s32 fn_get_field_3ac(void* p) { return *(s32*)((char*)p + 0x3ac); }

void TObject::toggle_pause() { m_flags ^= PAUSE_UPDATE; }

void TLobby::set_floor(s16 v) { *(s16*)((char*)this + 0x11a) = v; }

    extern unsigned char lbl_805D6CD9;
    extern short lbl_805D6CDA;
void TLobby__sub_801F34E8(int a0, int a1) { lbl_805D6CD9 = a1; lbl_805D6CDA = (a0 + 0x1); }

    extern int TLobby__data_805D6CCC;
int TLobby__sub_801F34F8(void) {  return TLobby__data_805D6CCC; }

int TLobby__sub_801F3500(void* p) { return VecCopy__FP3VecPC3Vec((char*)p + 0xc0); }
void TLobby::bswap_4x32() { bswap_32__FPUl(this); bswap_32__FPUl((char*)this + 0x4); bswap_32__FPUl((char*)this + 0x8); bswap_32__FPUl((char*)this + 0xc); }

    extern unsigned char camera_capture_flags;
void TLobby__sub_801F3568(void) { camera_capture_flags = (camera_capture_flags | 0x10); }

void TLobby::sync_quest_register_and_send() { bswap_header__6TLobbyFPv(this); send_subcommand((u8 *)this); }
void bswap_header__6TLobbyFPv(void* p) { ((G_ClientIDHeader *)p)->bswap(); bswap_16__FPUs((char*)p + 0x4); bswap_16__FPUs((char*)p + 0x6); bswap_32__FPUl((char*)p + 0x8); }
void build_6x77_sync_quest_register(void* p) { *(u8*)((char*)p + 0x0) = 119; *(u8*)((char*)p + 0x1) = 3; }

    extern int warning_aram_load_done_flag;

int TLobby::get_field_6CE8() {  return warning_aram_load_done_flag; }

    extern int lobby_count_value;
int TLobby::get_lobby_count() {  return lobby_count_value; }

void TLobby__sub_801F3614(void) { lobby_count_value = 0; }

int TLobby::copy_position() { return VecCopy__FP3VecPC3Vec(this); }

#pragma push
#pragma fp_contract on
void TLobby::bswap_entry_words(s32 arg0) {
    s32 var_r31;
    s32 temp_r30;
    s32 var_r29;
    var_r29 = 0;
    var_r31 = 0;
    do {
        temp_r30 = arg0 + var_r31;
        bswap_32__FPUl((void*)temp_r30);
        bswap_32__FPUl((void*)(temp_r30 + 0x18));
        var_r29 += 1;
        var_r31 += 4;
    } while (var_r29 < 6);
}
#pragma pop

int TLobby__sub_801F3694(void* p) { return set__8FlagWordFUl((char*)p + 0x10, 2); }

    extern int lobby_online_ready_flag;
void TLobby__sub_801F36BC(void) { lobby_online_ready_flag = 1; }

    extern int current_lobby_id;
void TLobby::set_lobby_id(int a0) { current_lobby_id = a0; }

    extern int lbl_805D3614;
void TLobby::set_global_805D3614(int a0) { lbl_805D3614 = a0; }

    extern int lobby_quest_progress_flag;
void TLobby__sub_801F36D8(void) { lobby_quest_progress_flag = 1; }

    extern int quest_warp_enabled;
void TLobby__sub_801F36E4(void) { quest_warp_enabled = 0; }

int TLobby__sub_801F36F0(void) { return -1; }
int TLobby__sub_801F36F8(void) { return 0; }
int TLobby__sub_801F3700(void) { return -1; }
int TLobby__sub_801F3708(void) { return 0; }
