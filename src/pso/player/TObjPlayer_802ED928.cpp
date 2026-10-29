#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_802ED928.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/boss/TBoss7DeRolLeC.h"
#include "pso/player/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TObject.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/object/TObjFish.h"

struct Base_802ED928 { char pad[0x18]; };
struct VObj_802ED928 : Base_802ED928 {
    virtual void m0();    virtual void m1();    virtual void m2();    virtual void m3();
    virtual void m4();    virtual void m5();    virtual void m6();    virtual void m7();
    virtual void m8();    virtual void m9();    virtual void m10();    virtual void m11();
    virtual void m12();    virtual void m13();    virtual void m14();    virtual void m15();
    virtual void m16();    virtual void m17();    virtual void m18();    virtual void m19();
    virtual void m20();    virtual void m21();    virtual void m22();    virtual void m23();
    virtual void m24();    virtual void m25();    virtual void m26();    virtual void m27();
    virtual void m28();    virtual void m29();    virtual void m30();    virtual void m31();
    virtual void m32();    virtual void m33();    virtual void m34();    virtual void m35();
    virtual void m36();    virtual void m37();    virtual void m38();    virtual void m39();
    virtual void m40();    virtual void m41();    virtual void m42();    virtual void m43();
    virtual void m44();    virtual void m45();    virtual void m46();    virtual void m47();
    virtual void m48();    virtual void m49();    virtual void m50();    virtual void m51();
    virtual void m52();    virtual void m53();    virtual void m54();    virtual void m55();
    virtual void m56();    virtual void m57();    virtual void m58();    virtual void m59();
    virtual void m60();    virtual void m61();    virtual void m62();    virtual void m63();
    virtual void m64();    virtual void m65();    virtual void m66();    virtual void m67();
    virtual void m68();    virtual void m69();    virtual void m70();    virtual void m71();
    virtual void m72();    virtual void m73();    virtual void m74();    virtual void m75();
    virtual void m76();    virtual void m77();    virtual void m78();    virtual void m79();
    virtual void m80();    virtual void m81();    virtual void m82();    virtual void m83();
    virtual void m84();
    virtual void m85(s16, int);
};

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
    virtual s32 m30();
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
    virtual s32 m60();
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
};

extern "C" {
s32 query_teammate_state__9TObjEneDDFv();
s32 is_main_phase_15__9TObjEneDDFv();
u32 __nw__7TObjectFUl(int);
s32 fn_802E79B0(void *);
s32 TParticleCtrl__sub_802EC550(void *);
s32 sub_802ECB10__14TBoss7DeRolLeCFv();
s32 apply_with_callback__10TObjPlayerFlf(int, int);
s32 rotate_matrix_by_node_angles(void *, int);
s32 push_matrix();
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
extern s32 lbl_804E3BF0[];
void TBoss7DeRolLeC::update_or_dispatch() {
    if (sub_802ECB10__14TBoss7DeRolLeCFv() != 0) {
        sub_802ECAA4();
        return;
    }
    ((VObj_802ED928*)this)->m85((this->mode), 9);
}

void TObjPlayer__sub_802ED984(void) {  }
void TBoss7DeRolLeC::run_task() {
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r30;
    s32 temp_r3;
    TObjPlayer__sub_802ED984();
    temp_r3 = *(s32 *)((s8 *)((u8 *)this) + 0x628);
    if (temp_r3 & 0x8000) {
        this->send_entity_set_flags();
        queue_destruction__7TObjectFv((this));
        return;
    }
    if (temp_r3 & 0x80) {
        *(s32 *)((s8 *)((u8 *)this) + 0x628) = (s32) (temp_r3 & 0xFFFFFF7F);
        *(s32 *)((s8 *)((u8 *)this) + 0x628) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x628) | 0x40);
        {
            void *p = (void *) __nw__7TObjectFUl(0x3C);
            if (p != NULL) {
                ((TObjPlayer *)p)->init_breakup_pieces(this, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x6D4)));
            }
        }
    }
    if ((is_main_phase_15__9TObjEneDDFv() != 0) && ((s32) this->m_6c8 == 0)) {
        if (this->update_lobby_state() != 0) {
            this->m_6d4 = 0;
        } else {
            this->m_6d4 = 1;
        }
    }
    if (((s32) this->m_6c8 != 0) && (*(s32 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x624)) + 8) & 0x10000)) {
        switch (this->m_6d4) {
        case 1:
            this->m_6d4 = 0;
            this->advance_action_sequence();
            break;
        case 0:
            this->m_6d4 = 2;
            break;
        case 2:
            this->m_6d4 = 1;
            break;
        }
    }
    temp_r30 = query_teammate_state__9TObjEneDDFv();
    this->update_attack_stat_status();
    this->update_defense_stat_status();
    if (temp_r30 == 0) {
        if ((this->mode == 0x1C) || (this->mode == 0x1D) || (this->mode == 0x1B)) {
            this->actorFlags = (s32) (this->actorFlags | 0x800);
        } else {
            this->actorFlags = (s32) (this->actorFlags & 0xFFFFF7FF);
        }
        temp_r0_3 = this->m_6d4;
        if (temp_r0_3 != 1) {
            if (temp_r0_3 == 2) {
                if (((s32 (*)(void *))sub_802ECB10__14TBoss7DeRolLeCFv)(this) != 0) {
                    this->sub_802ECAA4();
                } else {
                    ((VObj_18 *)(this))->m85(this->mode, 2);
                }
            } else {
                this->update_or_dispatch();
            }
            if (this->test_flag30_512() != 0) {
                this->vfunc_62();
            }
            ((VObj_18 *)(this))->m85(this->mode, 8);
            ((VObj_18 *)(this))->m85(this->mode, 0);
        } else {
            if (this->test_flag30_512() != 0) {
                this->vfunc_62();
            }
            ((VObj_18 *)(this))->m85(this->mode, 0);
        }
        this->update_projectile_spawns();
    }
    this->sub_800BBA0C();
    this->vfunc_88();
    ((TObjFish *)((u8 *)this))->sync_position_vectors();
    this->flee_if_disturbed();
    TParticleCtrl__sub_802EC550(this);
    if (temp_r30 == 0) {
        ((TObject *)(((u8 *)this) + 0x690))->run_tasks();
    }
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x7AC) != 0U) {
        set_motion_packed_rotation();
        push_matrix();
        set_matrix_identity(0);
        post_translate_matrix(((u8 *)this) + 0x38);
        post_translate_matrix(((u8 *)this) + 0x6EC);
        rotate_matrix_by_node_angles(((u8 *)this) + 0x5C, 1);
        scale_current_matrix(lbl_804E3BF0);
        this->sub_802E8234();
        this->get_frame();
        apply_with_callback__10TObjPlayerFlf((int) (*(u32 *)((s8 *)((u8 *)this) + 0x7AC)), (s32)this->current_motion);
        pop_matrix();
        clear_motion_packed_rotation();
        fn_802E79B0(this);
    }
}

}
