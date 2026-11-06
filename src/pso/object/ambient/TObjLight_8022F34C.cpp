#include "types.h"
#include "pso/object/TUnk_804CC74C.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/object/ambient/TObjLight_8022F34C.h"

#include "pso/system/vector.h"
#include "pso/technique/TTecDeband.h"
#include "pso/object/ambient/TObjLight.h"

struct Obj_8022F42C { u8 pad[0xA6]; s16 state; };

extern "C" {
s32 update_technique_slot__10TTecRaFoieFl(s32, s32, s32);
s32 play_sound_effect(int, void *, int, int);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

extern s32 __vt__13TUnk_804CC74C[];

void *TObjLight::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804CC74C;
        stop_sound_request(this->actorFlags);
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

}
TUnk_804CC74C::TUnk_804CC74C(s32 arg1, s32 arg2) : TObject((TObject *)((void *)arg2)) {
    *(s32 *)((s8 *)this + 0x1C) = arg1;
    VecCopy((Vec *)(((u8 *)this) + 0x20), (const Vec *)(*(s32 *)((s8 *)this + 0x1C) + 0x2FC));
    this->m_2c = 0;
    *(s32 *)((s8 *)this + 0x30) = play_sound_effect(0x4002BB1F, ((u8 *)this) + 0x20, 0, 0);
}

void TTecDeband::play_state_sound() {
    Obj_8022F42C *arg0 = (Obj_8022F42C *)this;
    s32 r;
    switch (*(s16 *)&this->m_a6) {
    case 0:
    case 1:
        r = play_sound_effect(0x4002AA16, (u8 *)arg0 + 0x20, 0, 0);
        if (r >= 0) {
            update_technique_slot__10TTecRaFoieFl(r, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002AA16, (u8 *)arg0 + 0x20, 0, 0);
        break;
    case 4:
    case 5:
        r = play_sound_effect(0x4002AA16, (u8 *)arg0 + 0x20, 0, 0);
        if (r >= 0) {
            update_technique_slot__10TTecRaFoieFl(r, -0x100, 0);
        }
        break;
    }
}

