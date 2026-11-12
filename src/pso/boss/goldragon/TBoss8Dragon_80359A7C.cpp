#include "pso/enemy/TObjEnemy.h"
#include "types.h"
#include "pso/enemy/dd/TObjEneDD_800B9B84.h"
#include "pso/boss/goldragon/TBoss8Dragon_80359A7C.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"


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
    virtual s32 m39();
    virtual s32 m40();
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
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual s32 m85(s16, s32);
    virtual s32 m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual s32 m103();
};

struct RecoveredGlobal_80359DC4_lbl_804F1A78 {
    s32 value;
    u8 remaining[0x1AC];
};

extern "C" {
s32 query_teammate_state__9TObjEneDDFv();
s32 is_main_phase_15__9TObjEneDDFv();
s32 add_radar_scaled_marker(void *, int, int, int, f32);
void release_grabbed_player__12TBoss8DragonFPv(TBoss8Dragon *arg0);
extern s32 local_client_id;
extern s32 TBoss8Dragon__data_805D69B8;
u8 *TBoss8Dragon__ct(u8 *arg0, void *arg1, void *arg2);
extern s32 boss8_dragon_attack_object_vtable[];
u8 *__dt__12TBoss8DragonFv(u8 *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);

void TBoss8Dragon__sub_80359A7C(u8 *boss8_dragon) {
    s16 temp_r0;
    s32 temp_r0_2;
    s32 temp_r30;
    s32 temp_r30_2;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((VObj_18 *)(boss8_dragon))->m103();
        return;
    }
    if (*(s32 *)((s8 *)boss8_dragon + 0x3C0) & 8) {
        ((TObjEnemy *)boss8_dragon)->send_entity_set_flags();
        queue_destruction__7TObjectFv((boss8_dragon));
        return;
    }
    if ((s32) *(s32 *)((s8 *)boss8_dragon + 0x74C) != 0) {
        ((TBoss8Dragon *)boss8_dragon)->freeze_player_at_self();
        *(s32 *)((s8 *)boss8_dragon + 0x754) = (s32) (*(s32 *)((s8 *)boss8_dragon + 0x754) + 1);
    } else if ((is_main_phase_15__9TObjEneDDFv() != 0) && ((s32) *(s32 *)((s8 *)boss8_dragon + 0x6D4) == 0)) {
        temp_r30 = *(s32 *)((s8 *)boss8_dragon + 0x3E0);
        if (((TObjEneDD *)boss8_dragon)->update_lobby_state() != 0) {
            *(s32 *)((s8 *)boss8_dragon + 0x3E0) = 0;
            if ((s32) *(s32 *)((s8 *)boss8_dragon + 0x3E0) != temp_r30) {
                *(s32 *)((s8 *)boss8_dragon + 0x8A0) = 1;
            }
        } else {
            *(s32 *)((s8 *)boss8_dragon + 0x3E0) = 1;
        }
    }
    temp_r30_2 = query_teammate_state__9TObjEneDDFv();
    ((VObj_18 *)(boss8_dragon))->m39();
    ((VObj_18 *)(boss8_dragon))->m40();
    if (temp_r30_2 == 0) {
        temp_r0 = *(s16 *)((s8 *)boss8_dragon + 0x326);
        if ((temp_r0 == 0x15) || (temp_r0 == 0x17)) {
            *(s32 *)((s8 *)boss8_dragon + 0x30) = (s32) (*(s32 *)((s8 *)boss8_dragon + 0x30) | 0x800);
        } else {
            *(s32 *)((s8 *)boss8_dragon + 0x30) = (s32) (*(s32 *)((s8 *)boss8_dragon + 0x30) & 0xFFFFF7FF);
        }
        if ((s32) *(s32 *)((s8 *)boss8_dragon + 0x74C) != 0) {
            if ((s32) *(u16 *)((s8 *)boss8_dragon + 0x750) == (s32) local_client_id) {
                if ((s32) TBoss8Dragon__data_805D69B8 == 0) {
                    release_grabbed_player__12TBoss8DragonFPv((TBoss8Dragon *)(boss8_dragon));
                } else {
                    ((TBoss8Dragon *)boss8_dragon)->check_death();
                }
                ((VObj_18 *)(boss8_dragon))->m85(*(s16 *)((s8 *)boss8_dragon + 0x326), 8);
                ((VObj_18 *)(boss8_dragon))->m85(*(s16 *)((s8 *)boss8_dragon + 0x326), 0);
            } else {
                if ((s32) TBoss8Dragon__data_805D69B8 == 0) {
                    release_grabbed_player__12TBoss8DragonFPv((TBoss8Dragon *)(boss8_dragon));
                }
                ((VObj_18 *)(boss8_dragon))->m85(*(s16 *)((s8 *)boss8_dragon + 0x326), 0);
            }
        } else {
            temp_r0_2 = *(s32 *)((s8 *)boss8_dragon + 0x3E0);
            if (temp_r0_2 != 1) {
                if (temp_r0_2 == 2) {
                    ((VObj_18 *)(boss8_dragon))->m85(*(s16 *)((s8 *)boss8_dragon + 0x326), 2);
                } else {
                    ((TBoss8Dragon *)boss8_dragon)->select_next_action();
                }
                ((VObj_18 *)(boss8_dragon))->m85(*(s16 *)((s8 *)boss8_dragon + 0x326), 8);
                ((VObj_18 *)(boss8_dragon))->m85(*(s16 *)((s8 *)boss8_dragon + 0x326), 0);
            } else {
                ((VObj_18 *)(boss8_dragon))->m85(*(s16 *)((s8 *)boss8_dragon + 0x326), 0);
            }
        }
    }
    ((TObjEneDD *)boss8_dragon)->sub_800BBA0C();
    ((VObj_18 *)(boss8_dragon))->m86();
    ((TBoss8Dragon *)boss8_dragon)->store_position();
    ((TObjEnemy *)boss8_dragon)->submit_default_cursor_candidate();
    add_radar_scaled_marker(boss8_dragon + 0x38, -0x5DB4, 1, 1, 2.0f);
    if (temp_r30_2 == 0) {
        ((TObject *)(boss8_dragon + 0x3C4))->run_tasks();
    }
    project_sound_origin_from_camera((s32)(boss8_dragon + 0x38), (u8 *)(boss8_dragon + 0x634), 0.4f);
}

void *__dt__13TUnk_804F1A78Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = boss8_dragon_attack_object_vtable;
        __dt__12TBoss8DragonFv((u8 *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80359DC4_lbl_804F1A78_size[sizeof(RecoveredGlobal_80359DC4_lbl_804F1A78) == 0x1B0 ? 1 : -1];
u8 *TBoss8Dragon::ct_attack_object(s32 arg1, s32 arg2, s32 arg3) {
    TBoss8Dragon__ct(((u8 *)this), (void *)arg1, (void *)arg2);
    *(void **)((u8 *)this + 0x18) = &(*(RecoveredGlobal_80359DC4_lbl_804F1A78 *)&boss8_dragon_attack_object_vtable).value;
    *(s32 *)&this->m_3c0 = (s32) (*(s32 *)&this->m_3c0 | 0x40);
    *(s16 *)&this->m_67a = -1;
    this->hp = arg3;
    this->hpmax = arg3;
    return ((u8 *)this);
}

}
