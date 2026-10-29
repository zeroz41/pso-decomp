#include "types.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEneBm9Mericarol_802D05BC.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneBm9Mericarol.h"
#include "pso/boss/TBoss3Volopt.h"

extern "C" {

struct SubBase_802d05bc { char pad[0x14]; };
struct SubObj_802d05bc : SubBase_802d05bc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual s32 v5();
    virtual void v6();
};
struct Base_802D06E0_802D05BC { char pad[0x18]; };
struct VObj_802D06E0_802D05BC : Base_802D06E0_802D05BC {
#define VM(n) virtual void m##n();
    VM(0)VM(1)VM(2)VM(3)VM(4)VM(5)VM(6)VM(7)VM(8)VM(9)
    VM(10)VM(11)VM(12)VM(13)VM(14)VM(15)VM(16)VM(17)VM(18)VM(19)
    VM(20)VM(21)VM(22)VM(23)VM(24)VM(25)VM(26)VM(27)VM(28)VM(29)
    VM(30)VM(31)VM(32)VM(33)VM(34)VM(35)VM(36)VM(37)VM(38)VM(39)
    VM(40)VM(41)VM(42)VM(43)VM(44)VM(45)VM(46)VM(47)VM(48)VM(49)
    VM(50)VM(51)VM(52)VM(53)VM(54)VM(55)VM(56)VM(57)VM(58)VM(59)
    VM(60)VM(61)VM(62)VM(63)VM(64)VM(65)VM(66)VM(67)VM(68)VM(69)
    VM(70)VM(71)VM(72)VM(73)VM(74)VM(75)VM(76)VM(77)VM(78)VM(79)
    VM(80)VM(81)VM(82)VM(83)VM(84)VM(85)VM(86)VM(87)VM(88)VM(89)
    VM(90)VM(91)VM(92)
    virtual void m93();
#undef VM
};

s32 advance_animation_playback();
s32 TObjEneBm9Mericarol__sub_802D093C(void *);
s32 TObjEneMe3SinowZoa__sub_800D758C(void *);
s32 enemy_clear_target__12TObjEneDD_STFUs(void *);

void TObjEneBm9Mericarol__sub_802D05BC(u8 *ene_dd_st, s32 arg1) {
    switch (arg1) {
    case 4:
        ((TObjEneDD_ST *)ene_dd_st)->requested_action = 2;
        ((TObjEneDD *)ene_dd_st)->vfunc_95();
        TObjEneBm9Mericarol__sub_802D093C(ene_dd_st);
        *(s32 *)((s8 *)ene_dd_st + 0x438) = (s32) (*(s32 *)((s8 *)ene_dd_st + 0x438) | 0x28);
        *(s32 *)((s8 *)ene_dd_st + 0x438) = (s32) (*(s32 *)((s8 *)ene_dd_st + 0x438) & 0xFFFFFFEF);
        ((TObjEneDD *)ene_dd_st)->set_field_378(2);
        enemy_clear_target__12TObjEneDD_STFUs(ene_dd_st);
        TObjEneMe3SinowZoa__sub_800D758C(ene_dd_st + 0x46C);
        ((TBoss3Volopt *)(ene_dd_st + 0x38))->play_area_sound_effect();
        return;
    case 3:
        if (((SubObj_802d05bc *)(ene_dd_st + 0x46C))->v5() != 0) {
            ((TObjEneDD *)ene_dd_st)->transition_enemy_state(2);
        }
    case 1:
        return;
    case 0:
        advance_animation_playback();
        ((TObjEneDD *)ene_dd_st)->vfunc_102();
        ((TObjEneDD *)ene_dd_st)->vfunc_88();
        return;
    case 5:
        *(s32 *)((s8 *)ene_dd_st + 0x438) = (s32) (*(s32 *)((s8 *)ene_dd_st + 0x438) & ~0x28);
        break;
    }
}

void TObjEneBm9Mericarol::handle_action(s32 arg1) {
    switch (arg1) {
    case 4:
        ((VObj_802D06E0_802D05BC *)this)->m93();
        return;
    case 3:
        transition_enemy_state(1);
    case 5:
    case 0:
        return;
    }
}

}
