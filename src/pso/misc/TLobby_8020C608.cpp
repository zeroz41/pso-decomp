#include "types.h"
#include "pso/unk/text_8020CCF4.h"
#include "pso/unk/text_8020BC50.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"

s32 TObjEnemy::send_entity_set_flags() {
    if ((u32) this->set_entry != 0U) {
        send_6x76_set_entity_set_flags(this, 8);
        return 1;
    }
    return 0;
}

s32 TUnk_804AF8A0::set_flag8() {
    void *temp_r4;

    temp_r4 = this->set_entry;
    if (temp_r4 != NULL) {
        *(s16 *)((s8 *)temp_r4 + 2) = (s16) (*(s16 *)((s8 *)temp_r4 + 2) | 8);
        return 1;
    }
    return 0;
}

#include "pso/misc/TLobby.h"

struct VBase { char pad[0x18]; };
struct VObj : VBase {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75();
    virtual void m76(); virtual void m77(s32);
};

extern "C" {

u8 *resolve_matching_object__6TLobbyFv(s32);
s32 append_wave_member(s32, void *);

extern s32 TLobby__data_805D60FC;
extern s32 TLobby__data_805D6144;

s32 TLobby::spawn_matching_objects(s16 arg0, s16 arg1, s32 arg2) {
    s16 temp_r0;
    s16 temp_r3;
    s32 object_type;
    s32 var_r30;
    u8 *row;
    s32 var_r28;
    u8 *item;

    var_r30 = 0;
    if ((s32) TLobby__data_805D60FC < 0) {
        return 0;
    }
    row = resolve_matching_object__6TLobbyFv(TLobby__data_805D60FC);
    object_type = TLobby::get_object_type(TLobby__data_805D60FC);
    for (var_r28 = 0; var_r28 < object_type; var_r28 += 1, row += 0x48) {
        temp_r3 = *(s16 *)((s8 *)row + 2);
        if (!(temp_r3 & 8) && !(temp_r3 & 2) && ((s16) *(s16 *)((s8 *)row + 0xC) == arg0) && ((s16) *(s16 *)((s8 *)row + 0xE) == arg1)) {
            item = (u8 *)construct_enemy_from_set_row(row);
            if (item != NULL) {
                *(void **)((s8 *)row + 0x44) = item;
                *(s16 *)((s8 *)row + 2) = (s16) (*(s16 *)((s8 *)row + 2) | 2);
                *(s16 *)((s8 *)item + 0x28) = (s16) *(s16 *)((s8 *)row + 0xC);
                *(s16 *)((s8 *)item + 0x2A) = (s16) *(s16 *)((s8 *)row + 0xE);
                *(s16 *)((s8 *)item + 0x2C) = (s16) *(s16 *)((s8 *)row + 4);
                *(void **)((s8 *)item + 0x80) = row;
                temp_r0 = *(s16 *)((s8 *)item + 0x2C);
                if (temp_r0 != -1) {
                    ((VObj *)item)->m77(TLobby__data_805D6144 + (temp_r0 * 0xC));
                }
                append_wave_member(arg2, item);
                var_r30 += 1;
            } else {
                *(void **)((s8 *)row + 0x44) = NULL;
            }
        }
    }
    return var_r30;
}

}
