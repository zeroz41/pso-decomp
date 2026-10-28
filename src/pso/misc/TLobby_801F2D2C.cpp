#include "pso/protocol/protocol_types.h"
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

struct Ctx_801F3124 {
    u8 *p0;
    u32 *p4;
    u8 *p8;
    s32 x0C;
    s32 x10;
    u8 x14;
    u8 pad15[7];
    s32 x1C;
    s32 x20;
    s32 x24;
    s32 x28;
    s32 pad2C;
    s32 x30;
    u8 x34[0x20];
    u8 x54[0x100];
    u8 pad154[8];
    s32 x15C;
    s32 x160;
    s32 x164;
    s32 x168;
    s32 x16C;
    s16 x170;
    s16 x172;
};

extern "C" {
int bswap_32__FPUl(void*);
s32 memcpy(void *, void *, int);
extern u32 TLobby__quest_message_window;
extern u32 TLobby__quest_choice_window;
extern u8 TLobby__active_window_index;
extern s32 lbl_805D5E94;
extern s32 lbl_805D5E9C;
extern s32 quest_message_speaker_id;
extern u8 TLobby__data_805D5EA8;
extern u8 TLobby__data_805D5EA9;
extern u16 TLobby__data_805D5EAA;
extern u16 TLobby__data_805D5EAC;
extern u32 TLobby__data_805D5EB0;
extern u32 TLobby__quest_window_object;
extern u32 TLobby__menu_state_object;
extern u32 TLobby__quest_state_object_168;
extern u32 TLobby__quest_state_object_16c;
extern u16 TLobby__quest_state_word_170;
extern u16 TLobby__quest_state_word_172;
extern RecoveredGlobal_801F3268_lbl_80512B18 lbl_80512B18;
extern struct Op_801F2E64 qst_opcode_table[];
extern s32 TLobby__quest_window_state;
int bswap_16__FPUs(void*);
void *memset(void *, int, u32);
extern s16 TLobby__data_805D5ECC;
void init_quest_script_context(Hdr_801F3124 *h, Ctx_801F3124 *c);
int test_action_mask__10TObjPlayerFl(void*, int);
int VecCopy__FP3VecPC3Vec(void*);
void queue_destruction__7TObjectFv(void *arg0);
int set__8FlagWordFUl(void*, int);

unsigned char TLobby::read_packet_byte() { return qst_code[qst_pc++]; }

s32 TLobby::dispatch_quest() {
    s32 arg0 = (s32)this;
    s32 temp_r31;

    load_quest_globals();
    temp_r31 = dispatch_quest_opcode();
    save_quest_state_to_record();
    return temp_r31;
}

extern u32 TLobby__quest_secondary_window;

void TLobby::close_windows() {
    if ((u32) TLobby__quest_message_window != 0U) {
        TWindow__close((u8 *)TLobby__quest_message_window);
        TLobby__quest_message_window = 0U;
    }
    if ((u32) TLobby__quest_secondary_window != 0U) {
        TWindow__close((u8 *)TLobby__quest_secondary_window);
        TLobby__quest_secondary_window = 0U;
    }
    if ((u32) TLobby__quest_choice_window != 0U) {
        TWindow__close((u8 *)TLobby__quest_choice_window);
        TLobby__quest_choice_window = 0U;
    }
    if ((u32) TLobby__data_805D5EB0 != 0U) {
        queue_destruction__7TObjectFv((void *)TLobby__data_805D5EB0);
        TLobby__data_805D5EB0 = 0U;
    }
    if ((u32) TLobby__quest_window_object != 0U) {
        queue_destruction__7TObjectFv((void *)TLobby__quest_window_object);
        TLobby__quest_window_object = 0U;
    }
    if ((u32) TLobby__menu_state_object != 0U) {
        queue_destruction__7TObjectFv((void *)TLobby__menu_state_object);
        TLobby__menu_state_object = 0U;
    }
    if ((u32) TLobby__quest_state_object_168 != 0U) {
        queue_destruction__7TObjectFv((void *)TLobby__quest_state_object_168);
        TLobby__quest_state_object_168 = 0U;
    }
    if ((u32) TLobby__quest_state_object_16c != 0U) {
        queue_destruction__7TObjectFv((void *)TLobby__quest_state_object_16c);
        TLobby__quest_state_object_16c = 0U;
    }
}
}

extern u32 quest_mission_manager;

s32 dispatch_quest_opcode(void) {
    s32 op;
    TLobby__quest_window_state = 0;
    while (TLobby__quest_window_state == 0) {
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
    return TLobby__quest_window_state;
}

void TLobby::save_quest_state_to_record() {
    *(u8 **)&this->m_name = qst_code;
    *(s32 **)&this->m_flags = qst_function_table;
    *(s32 **)&this->m_prev = qst_registers;
    *(s32 *)&this->m_next = (s32) (*(s32 *)&TLobby__quest_message_window);
    *(s32 *)&this->m_up = (s32) (*(s32 *)&TLobby__quest_choice_window);
    *(u8 *)&this->m_down = (u8) TLobby__active_window_index;
    *(s32 *)((s8 *)((u8 *)this) + 0x1C) = qst_call_stack_depth;
    *(s32 *)((s8 *)((u8 *)this) + 0x20) = qst_pc;
    *(s32 *)((s8 *)((u8 *)this) + 0x24) = (s32) lbl_805D5E94;
    *(s32 *)((s8 *)((u8 *)this) + 0x28) = (s32) lbl_805D5E9C;
    *(s32 *)((s8 *)((u8 *)this) + 0x2C) = (s32) quest_message_speaker_id;
    *(s32 *)((s8 *)((u8 *)this) + 0x30) = qst_arg_count;
    memcpy((void *) (((u8 *)this) + 0x34), qst_args, 0x20);
    memcpy((void *) (((u8 *)this) + 0x54), qst_call_stack, 0x100);
    (*(s32 *)&TLobby__quest_message_window) = 0;
    (*(s32 *)&TLobby__quest_choice_window) = 0;
    *(u8 *)((s8 *)((u8 *)this) + 0x154) = (u8) TLobby__data_805D5EA8;
    *(u8 *)((s8 *)((u8 *)this) + 0x155) = (u8) TLobby__data_805D5EA9;
    *(u16 *)((s8 *)((u8 *)this) + 0x156) = (u16) TLobby__data_805D5EAA;
    *(u16 *)((s8 *)((u8 *)this) + 0x158) = (u16) TLobby__data_805D5EAC;
    *(s32 *)((s8 *)((u8 *)this) + 0x15C) = (s32) (*(s32 *)&TLobby__data_805D5EB0);
    (*(s32 *)&TLobby__data_805D5EB0) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x160) = (s32) (*(s32 *)&TLobby__quest_window_object);
    (*(s32 *)&TLobby__quest_window_object) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x164) = (s32) (*(s32 *)&TLobby__menu_state_object);
    (*(s32 *)&TLobby__menu_state_object) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x168) = (s32) (*(s32 *)&TLobby__quest_state_object_168);
    (*(s32 *)&TLobby__quest_state_object_168) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x16C) = (s32) (*(s32 *)&TLobby__quest_state_object_16c);
    (*(s32 *)&TLobby__quest_state_object_16c) = 0;
    *(u16 *)((s8 *)((u8 *)this) + 0x170) = (u16) TLobby__quest_state_word_170;
    *(u16 *)((s8 *)((u8 *)this) + 0x172) = (u16) TLobby__quest_state_word_172;
}

void TLobby::load_quest_globals() {
    qst_code = *(u8 **)&this->m_name;
    qst_function_table = *(s32 **)&this->m_flags;
    qst_registers = *(s32 **)&this->m_prev;
    (*(s32 *)&TLobby__quest_message_window) = *(s32 *)&this->m_next;
    (*(s32 *)&TLobby__quest_choice_window) = *(s32 *)&this->m_up;
    TLobby__active_window_index = *(u8 *)&this->m_down;
    qst_call_stack_depth = *(s32 *)((s8 *)((u8 *)this) + 0x1C);
    qst_pc = *(s32 *)((s8 *)((u8 *)this) + 0x20);
    lbl_805D5E94 = *(s32 *)((s8 *)((u8 *)this) + 0x24);
    lbl_805D5E9C = *(s32 *)((s8 *)((u8 *)this) + 0x28);
    quest_message_speaker_id = *(s32 *)((s8 *)((u8 *)this) + 0x2C);
    qst_arg_count = *(s32 *)((s8 *)((u8 *)this) + 0x30);
    memcpy(qst_args, (void *) (((u8 *)this) + 0x34), 0x20);
    memcpy(qst_call_stack, (void *) (((u8 *)this) + 0x54), 0x100);
    TLobby__data_805D5EA8 = *(u8 *)((s8 *)((u8 *)this) + 0x154);
    TLobby__data_805D5EA9 = *(u8 *)((s8 *)((u8 *)this) + 0x155);
    TLobby__data_805D5EAA = *(u16 *)((s8 *)((u8 *)this) + 0x156);
    TLobby__data_805D5EAC = *(u16 *)((s8 *)((u8 *)this) + 0x158);
    (*(s32 *)&TLobby__data_805D5EB0) = *(s32 *)((s8 *)((u8 *)this) + 0x15C);
    (*(s32 *)&TLobby__quest_window_object) = *(s32 *)((s8 *)((u8 *)this) + 0x160);
    (*(s32 *)&TLobby__menu_state_object) = *(s32 *)((s8 *)((u8 *)this) + 0x164);
    (*(s32 *)&TLobby__quest_state_object_168) = *(s32 *)((s8 *)((u8 *)this) + 0x168);
    (*(s32 *)&TLobby__quest_state_object_16c) = *(s32 *)((s8 *)((u8 *)this) + 0x16C);
    TLobby__quest_state_word_170 = *(u16 *)((s8 *)((u8 *)this) + 0x170);
    TLobby__quest_state_word_172 = *(u16 *)((s8 *)((u8 *)this) + 0x172);
}

typedef char RecoveredGlobal_801F3268_lbl_80512B18_size[sizeof(RecoveredGlobal_801F3268_lbl_80512B18) == 0x10 ? 1 : -1];

void init_quest_script_context(Hdr_801F3124 *h, Ctx_801F3124 *c) {
    u32 n;
    u32 i;
    bswap_32__FPUl(&h->off0);
    bswap_32__FPUl(&h->off4);
    bswap_32__FPUl(&h->off8);
    bswap_16__FPUs(&h->hC);
    bswap_16__FPUs(&h->hE);
    bswap_16__FPUs((void*)((u8 *)h + 0x12));
    TLobby__data_805D5ECC = h->b12;
    c->p0 = (u8 *)h + h->off0;
    c->p4 = (u32 *)((u8 *)h + h->off4);
    c->p8 = (u8 *)h + h->off8;
    c->x0C = 0;
    c->x10 = 0;
    c->x14 = 0;
    c->x1C = 0;
    c->x20 = 0;
    c->x24 = 0;
    c->x28 = 0;
    c->x30 = 0;
    memset(c->x34, 0, 0x20);
    memset(c->p8, 0, 0x400);
    memset(c->x54, 0, 0x100);
    n = (h->off8 - h->off4) / 4;
    for (i = 0; i < n; i++) {
        bswap_32__FPUl(&c->p4[i]);
    }
    (*(s8 *)&TLobby__data_805D5EA8) = 0;
    (*(s8 *)&TLobby__data_805D5EA9) = 0;
    (*(s16 *)&TLobby__data_805D5EAA) = 0;
    (*(s16 *)&TLobby__data_805D5EAC) = 0;
    c->x15C = 0;
    c->x160 = 0;
    c->x164 = 0;
    c->x168 = 0;
    c->x16C = 0;
    c->x170 = 0;
    c->x172 = 0;
}

s32 *TObjItemOKWindow__sub_801F3268(void) {
    return &lbl_80512B18.value;
}

void TLobby::clear_quest_vm_flag() {
    if ((u32) quest_mission_manager != 0U) {
        ((TQuestVmDownLoadServer *)quest_mission_manager)->clear_flag4_bit4();
    }
}

void TLobby::free_luker_object() {
    if ((u32) quest_mission_manager != 0U) {
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
