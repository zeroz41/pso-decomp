// ---- pso/unk/TLobby_8020EED8
#include "types.h"
#include "pso/unk/TLobby.h"

s32 TLobby::pop_byte() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    s32 temp_r4;

    temp_r4 = *(s32 *)((s8 *)arg0 + 0x64);
    if (temp_r4 > 0) {
        temp_r0 = temp_r4 - 1;
        *(s32 *)((s8 *)arg0 + 0x64) = temp_r0;
        return (u8)*(arg0 + temp_r0);
    }
    return -1;
}

// ---- pso/unk/text_8020EEFC
#include "types.h"
#include "pso/unk/text_8020EEFC.h"

struct Deck_8020EF40 {
    u8 buf[0x64];
    s32 n;
};

extern "C" {
s32 rand();
void shuffle_shop_pool_n_times(void *arg0_, s32 arg1) {
    while (arg1-- > 0) {
        shuffle_shop_pool(arg0_);
    }
}
}
void shuffle_shop_pool(void *arg0_) {
    Deck_8020EF40 *arg0 = (Deck_8020EF40 *)arg0_;
    s32 i;
    s32 k;
    u8 t;
    for (i = 0; i < arg0->n; i++) {
        k = (s32)((f32)arg0->n * (3.0517578e-05f * (f32)rand()));
        t = arg0->buf[i];
        arg0->buf[i] = arg0->buf[k];
        arg0->buf[k] = t;
    }
}

// ---- pso/unk/TLobby_8020F00C
#include "types.h"
#include "pso/unk/TLobby_8020F00C.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TRaderMapCore.h"

void push_shop_pool_entry(u8 *arg0, s8 arg1) {
    s32 temp_r5;
    temp_r5 = *(s32 *)((s8 *)arg0 + 0x64);
    if (temp_r5 < 0x64) {
        *(s32 *)((s8 *)arg0 + 0x64) = (temp_r5 + 1);
        *(arg0 + temp_r5) = arg1;
    }
}

void TLobby::reset_counter_64() { *(s32*)((char*)this + 0x64) = 0; }
