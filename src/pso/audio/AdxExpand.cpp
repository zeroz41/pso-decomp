#include <dolphin/os/OSThread.h>
#include "pso/unk/TLobby.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxmThreadStorage.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/SjRingBuffer.h"

#include "types.h"
#include "pso/unk/text_803D31A4.h"

extern "C" {
s32 memset(void *, int, int);
}

struct Ch_803CB5C4 {
    s32 used;
    s32 id;
    s32 f8;
    s32 fC;
    u8 pad10[0x18];
    u8 f28[8];
    s16 c0;
    s16 c1;
};

extern "C" {
s32 calc_adx_predictor_coeffs(void *, void *, void *, void *);
extern Ch_803CB5C4 adx_decoder_channel_pool[16];

void TLobby__sub_803CB4A4(u8 *arg0);
void TLobby__sub_803CB570(u8 *arg0, u8 *arg1, s16 *arg2);
u32 decode_adx_mono_blocks(int, int, int, void *, int, int);
u32 dispatch_receive_update__6TLobbyFv(int, int, int, void *, int, void *, int, int);

s32 lbl_805D7588;

}
extern "C" {

void TLobby::update_receive_check() {
    u8 *arg0 = (u8 *)this;
    u32 temp_r0;
    u32 temp_r3;

    if ((s32) this->m_next == 1) {
        *(s32 *)&this->m_next = 2;
    }
    if ((s32) this->m_next == 2) {
        if ((s32) this->m_down == 1) {
            *(u32 *)&this->m_up = decode_adx_mono_blocks((int) (*(s32 *)((s8 *)arg0 + 0x18)), (int) (*(s32 *)((s8 *)arg0 + 0x1C)), (int) (*(s32 *)((s8 *)arg0 + 0x20)), arg0 + 0x28, (int) (*(s16 *)((s8 *)arg0 + 0x30)), (int) (*(s16 *)((s8 *)arg0 + 0x32)));
        } else {
            *(u32 *)&this->m_up = dispatch_receive_update__6TLobbyFv((int) (*(s32 *)((s8 *)arg0 + 0x18)), (int) (*(s32 *)((s8 *)arg0 + 0x1C)), (int) (*(s32 *)((s8 *)arg0 + 0x20)), arg0 + 0x28, (int) (*(s32 *)((s8 *)arg0 + 0x24)), arg0 + 0x2C, (int) (*(s16 *)((s8 *)arg0 + 0x30)), (int) (*(s16 *)((s8 *)arg0 + 0x32)));
            temp_r0 = *(u32 *)&this->m_up;
            temp_r3 = temp_r0 >> 0x1FU;
            if ((s32) (((temp_r0 & 1) ^ temp_r3) - temp_r3) == 1) {
                lbl_805D7588 = 1;
            }
        }
        *(s32 *)&this->m_next = 3;
    }
}

s32 TLobby::get_size() {
    return *(s32 *)&this->m_up;
}

void TLobby::reset_field_0C() {
    if ((s32) this->m_next == 3) {
        this->m_next = 0;
    }
}

void TLobby::reset_client_state() {
    u8 *arg0 = (u8 *)this;
    this->m_next = 0;
    memset(arg0 + 0x28, 0, 8);
}

void TLobby__sub_803CB4A4(u8 *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0xC) == 0) {
        *(s32 *)((s8 *)arg0 + 0x10) = 0;
        *(s32 *)((s8 *)arg0 + 0xC) = 1;
    }
}

s32 TLobby::post_request(s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *arg0 = (u8 *)this;
    if ((s32) this->m_next == 0) {
        *(s32 *)&this->m_down = 2;
        *(s32 *)((s8 *)arg0 + 0x18) = arg1;
        *(s32 *)((s8 *)arg0 + 0x1C) = arg2;
        *(s32 *)((s8 *)arg0 + 0x20) = arg3;
        *(s32 *)((s8 *)arg0 + 0x24) = arg4;
        return 1;
    }
    return 0;
}

s32 TLobby::try_post_command(s32 arg1, s32 arg2, s32 arg3) {
    u8 *arg0 = (u8 *)this;
    if ((s32) this->m_next == 0) {
        *(s32 *)&this->m_down = 1;
        *(s32 *)((s8 *)arg0 + 0x18) = arg1;
        *(s32 *)((s8 *)arg0 + 0x1C) = arg2;
        *(s32 *)((s8 *)arg0 + 0x20) = arg3;
        *(s32 *)((s8 *)arg0 + 0x24) = 0;
        return 1;
    }
    return 0;
}

s32 TLobby::get_client_count() {
    return *(s32 *)&this->m_next;
}

void TLobby::clear_record_data() {
    s32 *arg0 = (s32 *)this;
    if (arg0 != NULL) {
        *arg0 = 0;
        memset(arg0, 0, 0x34);
    }
}

void TLobby__sub_803CB570(u8 *arg0, u8 *arg1, s16 *arg2) {
    *(s16 *)((s8 *)arg0 + 0x28) = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 0x2A) = (s16) *arg2;
    *(s16 *)((s8 *)arg0 + 0x2C) = (s16) *(s16 *)((s8 *)arg1 + 2);
    *(s16 *)((s8 *)arg0 + 0x2C) = (s16) *(s16 *)((s8 *)arg1 + 2);
}

#pragma push
#pragma fp_contract on
void TLobby::calc_adx_coeffs_at_offset(void *arg1, s32 arg2) {
    s32 arg0 = (s32)this;
    calc_adx_predictor_coeffs((void *)arg2, arg1, (void *)(arg0 + 0x30), (void *)(arg0 + 0x32));
}
#pragma pop

Ch_803CB5C4 *adx_allocate_decoder_channel(void) {
    s32 i;
    Ch_803CB5C4 *c;

    for (i = 0; i < 16; i++) {
        if (adx_decoder_channel_pool[i].used == 0) {
            break;
        }
    }
    if (i == 16) {
        return NULL;
    }
    c = &adx_decoder_channel_pool[i];
    memset(c, 0, sizeof(Ch_803CB5C4));
    c->used = 1;
    c->id = i;
    c->f8 = 0;
    c->fC = 0;
    calc_adx_predictor_coeffs((void *)500, (void *)44100, &c->c0, &c->c1);
    memset(c->f28, 0, 8);
    return c;
}

void TLobby::clear_buffer_340() {
    memset(adx_decoder_channel_pool, 0, 0x340);
}

}

Ch_803CB5C4 adx_decoder_channel_pool[16];
