#include "pso/item/TItemLoad.h"
#include "pso/item/TUnk_8049F42C.h"

#include "types.h"

struct O_80110750 { u8 pad[0x2c]; s32 arr[1]; };

struct O_80110788 { s32 arr[4]; s32 f10; s32 f14; };

extern "C" {
s32 TItemLoad__sub_80110750(O_80110750 *self, s32 i);
int TLobby__sub_803CC4C0(void*);
int test_flags_any(void*, int);

s32 TItemLoad__sub_80110750(O_80110750 *self, s32 i) {
    return self->arr[i];
}

int TItemLoad::update_item() { return test_flags_any((char*)this + 0x1c, 2); }

void TItemLoad::clear_slots() {
    O_80110788 *self = (O_80110788 *)this;
    s32 i;
    for (i = 0; i < 4; i++) {
        self->arr[i] = 0;
    }
    self->f10 = 0;
    self->f14 = 0;
}

void TUnk_8049F42C::vfunc_3() {  }
int TItemLoad::get_ring_lobby() { return TLobby__sub_803CC4C0(*(void* *)&this->m_flags); }
s32 TItemLoad__sub_801107DC(void* p) { return *(s32*)((char*)p + 0xc); }
s32 TItemLoad__sub_801107E4(void* p) { return *(s32*)((char*)p + 0x1c); }
void* TItemLoad__sub_801107EC(void* p) { return (char*)p + 0x2c; }
int TItemLoad__sub_801107F4(void* p) { return *(u32*)((char*)p + 0x20) == 0; }
TItemLoad::~TItemLoad() {}

}
