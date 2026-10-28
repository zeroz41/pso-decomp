#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/item/TUnk_804A535C.h"
#include "pso/item/SpecialProjectileWeapons.h"
#include "pso/player/TObjPlayer_8012C950.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_8012C5F8.h"
#include "pso/TAdRicoRing.h"
#include "pso/TItemAttacker.h"
#include "pso/player/TObjPlayer.h"
struct Obj_8012C714 { u8 pad[0x184]; void *f184; void *f188; u8 pad2[0x1f8 - 0x18c]; u8 f1f8[4]; };

struct VBase_18 { char pad[0x18]; };

struct VObj_18 : VBase_18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual s32 m49(void *, s32, s32, s32);
};

extern "C" {
s32 test_flags_any(void *p, s32 n);
void rocket_punch_node_callback(Obj_8012C714 *self);

void TUnk_804A535C::emit_marker_effects() {
    s32 temp_r31;
    s32 var_r30;
    u32 temp_r3;
    u8 *arg0 = (u8 *)this;
    temp_r3 = *(u32 *)((s8 *)arg0 + 0xF0);
    if (temp_r3 == 0U) return;
    temp_r31 = temp_r3 + 0x7CC;
    if (get_burst_counter((void *)temp_r31) == 0) {
        var_r30 = 0;
        do {
            increment_burst_counter((u8 *)temp_r31);
            var_r30 += 1;
        } while (var_r30 != 2);
        ((FlagWord *)(arg0 + 0x1F8))->set(2);
        TItemAttacker::spawn_item_timer((s32)arg0, (s32)rocket_punch_return_timer, 0x3C);
        ((FlagWord *)(arg0 + 0x1F8))->set(4);
        if (((VObj_18 *)(arg0))->m49(arg0 + 0x1FC, 0, 0, 1) == 1) {
            ((FlagWord *)(arg0 + 0x1F8))->clear(4);
            ((VObj_18 *)(arg0))->m49(arg0 + 0x208, 0, 0, 0);
            return;
        }
        ((FlagWord *)(arg0 + 0x1F8))->clear(4);
        ((VObj_18 *)(arg0))->m49(arg0 + 0x208, 0, 0, 1);
    }
}

void rocket_punch_node_callback(Obj_8012C714 *self) {
    void *p;
    switch (TObjPlayer::get_player_list()) {
    case 1:
        if (test_flags_any(self->f1f8, 2) == 0) {
            if (test_flags_any(self->f1f8, 1)) {
                p = self->f188;
            } else {
                p = self->f184;
            }
            if (p) {
                draw_ginja_object(p);
            }
        }
        break;
    }
}

}
