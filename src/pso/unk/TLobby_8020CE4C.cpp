#include "types.h"
#include "pso/unk/text_8020CCF4.h"
#include "pso/unk/TLobby.h"

struct CE4C_VBase_8020ce4c { char pad[0x18]; };
struct CE4C_VObj_8020ce4c : CE4C_VBase_8020ce4c {
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
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m79(s32);
};

extern s32 TLobby__data_805D6144;

void TLobby::assign_display_objects(u8 *arg0, s32 arg1) {
    s16 temp_r3;
    s16 temp_r0;
    u8 *ptr;
    s32 i;
    u8 *temp_r3_2;

    ptr = arg0;
    for (i = 0; i < arg1; i++, ptr += 0x48) {
        temp_r3 = *(s16 *)((s8 *)ptr + 2);
        if (!(temp_r3 & 8) && !(temp_r3 & 2) && (*(s16 *)((s8 *)ptr + 0) != -1) && ((temp_r3 & 1) || (*(s16 *)((s8 *)ptr + 0xE) == 0))) {
            temp_r3_2 = (u8 *)construct_enemy_from_set_row(ptr);
            if (temp_r3_2 != NULL) {
                *(void **)((s8 *)ptr + 0x44) = temp_r3_2;
                *(s16 *)((s8 *)ptr + 2) = (s16) (*(s16 *)((s8 *)ptr + 2) | 2);
                *(s16 *)((s8 *)temp_r3_2 + 0x28) = (s16) *(s16 *)((s8 *)ptr + 0xC);
                *(s16 *)((s8 *)temp_r3_2 + 0x2A) = (s16) *(s16 *)((s8 *)ptr + 0xE);
                *(s16 *)((s8 *)temp_r3_2 + 0x2C) = (s16) *(s16 *)((s8 *)ptr + 4);
                *(void **)((s8 *)temp_r3_2 + 0x80) = ptr;
                temp_r0 = *(s16 *)((s8 *)temp_r3_2 + 0x2C);
                if (temp_r0 != -1) {
                    ((CE4C_VObj_8020ce4c *) temp_r3_2)->m79(TLobby__data_805D6144 + (temp_r0 * 0xC));
                }
            } else {
                *(void **)((s8 *)ptr + 0x44) = NULL;
            }
            *(s16 *)((s8 *)ptr + 2) = (s16) (*(s16 *)((s8 *)ptr + 2) & 0xFFFFFFFE);
        }
    }
}
