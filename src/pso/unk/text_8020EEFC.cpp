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
