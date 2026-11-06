#include "types.h"
#include "pso/ui/window/TWindowDD_80348D0C.h"
#include "pso/system/byteswap.h"
#include "pso/ui/window/TWindowDD.h"

struct S_80348DAC { s16 count; s16 unk2; s16 items[8]; };

struct S_80348D90 { s16 count; s16 unk2; s16 items[8]; };

struct S_80348DFC { s16 count; s16 unk2; s16 items[8]; s32 a; s32 b; };

struct S_80348DD8 { s16 count; s16 unk2; s16 items[8]; };

struct S_80348D0C { u16 a; u16 b; u16 c[8]; u32 d; u32 e; };

extern "C" {
void TWindowDD__sub_80348D90(S_80348D90 *self, s16 v);
void TWindowDD__sub_80348DD8(S_80348DD8 *self, s16 v);

void TWindowDD::bswap_word_select() {
    S_80348D0C *arg0 = (S_80348D0C *)this;
    s32 i;
    bswap_16(&this->m_1c);
    bswap_16(&arg0->b);
    for (i = 0; i < 8; i++) {
        bswap_16(&arg0->c[i]);
    }
    bswap_32(&arg0->d);
    bswap_32(&arg0->e);
}

void TWindowDD::reset_index() { *(s32*)((char*)this + 0x14) = 0; }
void TWindowDD::set_field14(s32 v) { *(s32*)((char*)this + 0x14) = v; }
s32 TWindowDD__sub_80348D88(void* p) { return *(s32*)((char*)p + 0x14); }

void TWindowDD__sub_80348D90(S_80348D90 *self, s16 v) {
    if (self->count > 0) {
        self->items[self->count - 1] = v;
    }
}

void TWindowDD::pop_entry() {
    S_80348DAC *self = (S_80348DAC *)this;
    if (self->count > 0) {
        self->items[--self->count] = -1;
    }
}

void TWindowDD__sub_80348DD8(S_80348DD8 *self, s16 v) {
    if (self->count < 8) {
        self->items[self->count++] = v;
    }
}

void TWindowDD::init_item_slots() {
    S_80348DFC *self = (S_80348DFC *)this;
    s32 i;
    self->unk2 = 0;
    this->m_1c = 0;
    for (i = 0; i < 8; i++) {
        self->items[i] = -1;
    }
    self->a = 0;
    self->b = 0;
}

}
