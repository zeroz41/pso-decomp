#include "types.h"
#include "pso/ui/window/TWindowKeyBoardHard_801A529C.h"
#include "pso/network/packet_copy.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/network/TPacket.h"

extern "C" {
u16 to_be_uint16_t__FUs(u16);
void handle_command__9TProtocolFP6packet(void *, void *);
extern void *TLobby__protocol_instance;
s32 deferred_packet_buffer;
s32 deferred_packet_buffer_used;
s32 lbl_805D5D00;
s32 lbl_805D5D04;
void *get_character_save_record();
s32 memcpy(s32, void *, u16);
s32 memset(s32, s32, s32);

s32 TWindowKeyBoardHard::test_card_flag(s32 arg1, s32 arg2) {
    void *character_save_record;

    character_save_record = get_character_save_record();
    if (character_save_record == NULL) {
        return 0;
    }
    return (*(s32 *)((s8 *)character_save_record + 0x10) & arg2) ? 1 : 0;
}

void TWindowKeyBoardHard::set_card_window_flags(void *arg0, s32 arg1, s32 arg2) {
    void *character_save_record;

    character_save_record = get_character_save_record();
    if (character_save_record != NULL) {
        *(s32 *)((s8 *)character_save_record + 0x10) = (s32) (*(s32 *)((s8 *)character_save_record + 0x10) & arg2);
        *(s32 *)((s8 *)character_save_record + 0x10) = (s32) (*(s32 *)((s8 *)character_save_record + 0x10) | arg1);
    }
}

void set_fresh_card_flag(void *arg0) {
    if (arg0 != NULL) {
        *(s32 *)((s8 *)arg0 + 0x10) = 0x40058;
    }
}

void TLobby::drain_deferred_packets() {
    deferred_packet_buffer_used = 0;
    lbl_805D5D04 = 2;
    s32 i;
    while ((i = deferred_packet_buffer_used) < 0x10000) {
        u8 *p;
        u16 n;
        p = (u8 *)(deferred_packet_buffer + i);
        n = (u16)to_be_uint16_t__FUs(*(u16 *)(p + 2));
        if (p[0] == 0) {
            break;
        }
        handle_command__9TProtocolFP6packet(TLobby__protocol_instance, p);
        deferred_packet_buffer_used += n;
    }
}

}
void copy_packet(packet *arg0) {
    s32 len;

    len = (u16) to_be_uint16_t__FUs(*(u16 *)((s8 *)arg0 + 2));
    if (deferred_packet_buffer_used + len <= 0x10000) {
        memcpy(deferred_packet_buffer + deferred_packet_buffer_used, arg0, len);
        deferred_packet_buffer_used += len;
    }
}

void buffer_reset(void) {
    deferred_packet_buffer_used = 0;
    lbl_805D5D00 = 0;
    memset(deferred_packet_buffer, 0, 0x10000);
    lbl_805D5D04 = 1;
}
extern "C" {

void mem_free(void *p);

void TLobby__sub_801A5478(void) { mem_free((void *)deferred_packet_buffer); deferred_packet_buffer = 0; }

void *mem_alloc(u32 size);

void alloc_work_buffer(void) {
    deferred_packet_buffer_used = 0;
    lbl_805D5D00 = 0;
    lbl_805D5D04 = 0;
    deferred_packet_buffer = (s32)mem_alloc(0x10000);
    memset(deferred_packet_buffer, 0, 0x10000);
}
}

struct VBase_801a54e8_801A529C { char pad[0x18]; };
struct VObj_801a54e8_801A529C : VBase_801a54e8_801A529C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8(void *, s32);
};

struct S_801A5544 { u8 pad[0x8B8]; s32 cnt; u8 buf[0x5B4]; };

extern "C" {
void append_command_to_batch_buffer(S_801A5544 *arg0, u8 *arg1);

void TLobby__sub_801A54E8(u8 *arg0) {
    s32 temp_r4;

    temp_r4 = *(s32 *)((s8 *)arg0 + 0x8B8);
    if (temp_r4 > 0) {
        if (temp_r4 & 3) {
            *(s32 *)((s8 *)arg0 + 0x8B8) = (temp_r4 + 3);
            *(s32 *)((s8 *)arg0 + 0x8B8) = (s32) (*(s32 *)((s8 *)arg0 + 0x8B8) & 0xFFFFFFFC);
        }
        ((VObj_801a54e8_801A529C *) arg0)->m8(arg0 + 0x8BC, *(s32 *)((s8 *)arg0 + 0x8B8));
    }
}
void append_command_to_batch_buffer(S_801A5544 *arg0, u8 *arg1) {
    s32 n;
    s32 i;
    if (arg0->cnt + arg1[1] * 4 > 0x5B4) {
        return;
    }
    n = arg1[1] * 4;
    for (i = 0; i < n; i++) {
        arg0->buf[arg0->cnt++] = *arg1++;
    }
}

}
