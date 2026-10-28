#include "types.h"
#include "pso/enemy/TObjEneRe2Flower_EffCurse3.h"

#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneRe2Flower.h"
#include "pso/player/TObjPlayer.h"

struct Pair_800C2E64 { s32 a, b; };
struct Obj_800C2E64;
struct Obj_800C2E64Base { u8 pad[0x18]; };
struct Obj_800C2E64 : Obj_800C2E64Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void hit(Obj_800C2E64 *src, Pair_800C2E64 *p, s32 a, s32 b, s32 c);
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void s160();
    virtual void v87();
    virtual void v88();
    virtual void s16c();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void s180();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void s198(s32);
};

extern "C" {
u16 get_entity_id(void *);
s32 is_alive__9TObjEneDDFv(void *);
s32 is_player_entity_id(u16);
void send_6x2F_change_player_hp(s32, u16, s32);
extern Pair_800C2E64 lbl_8043BA60[];
void TObjEneRe2Flower__sub_800C2E64(Obj_800C2E64 *self, s32 state);
f32 calc_boss4_scale__10TObjPlayerFi(s32 arg0);
s32 get_flag_b4__9TObjEneDDFv();
s32 TBoss8Dragon__sub_800BB7D4(void *, int);
s32 transition_enemy_state__9TObjEneDDFs(void *, s32);
s32 noop__9TObjEneDDFv(void *, s32);
s32 fn_800C3A60(void *, s32);
s32 advance_animation_playback();
s32 play_sound_effect(s32, void *, s32, s32);
extern const f32 lbl_805D9FD0;
#define F(T, o) (*(T *)((s8 *)(arg0) + (o)))
void TObjEneDD::state_damaged(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 4;
        this->vfunc_96();
        ((TObjEneRe2Flower *)arg0)->clear_child_flags();
        F(s32, 0x3C4) &= ~8;
        TBoss8Dragon__sub_800BB7D4(arg0, 0xF2);
        play_sound_effect(fn_800C3A60(arg0, 0x4003AB13), (u8 *)&this->position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x200);
        break;
    case 3:
        if (get_flag_b4__9TObjEneDDFv() != 0) {
            if (F(s32, 0x378) == 8) {
                transition_enemy_state__9TObjEneDDFs(arg0, F(s32, 0x378));
            } else if (F(s16, 0x32C) < F(s16, 0x2B8) / 4) {
                transition_enemy_state__9TObjEneDDFs(arg0, 8);
            } else if (calc_boss4_scale__10TObjPlayerFi((s32)arg0) < lbl_805D9FD0) {
                transition_enemy_state__9TObjEneDDFs(arg0, 6);
            } else {
                transition_enemy_state__9TObjEneDDFs(arg0, F(s32, 0x378));
            }
        }
        break;
    case 0:
        advance_animation_playback();
        this->vfunc_102();
        this->vfunc_88();
        ((s32 (*)(void *))noop__9TObjEneDDFv)(arg0);
        break;
    case 5:
        F(s32, 0x30) &= ~0x200;
        F(s32, 0x3C4) &= ~2;
        ((TObjEneDD *)arg0)->clear_attack_receipts();
        break;
    }
}
#undef F

#define F(o, T, off) (*(T *)((u8 *)(o) + (off)))
void TObjEneRe2Flower__sub_800C2E64(Obj_800C2E64 *self, s32 state) {
    u8 *t;
    switch (state) {
    case 4:
        F(self, s16, 0xB8) = 1;
        self->s180();
        self->s16c();
        ((TObjEneRe2Flower *)self)->clear_child_flags();
        F(self, u32, 0x3C4) &= ~8;
        F(self, s32, 0x410) = 0;
        F(self, s32, 0x414) = 0;
        break;
    case 3:
        if (F(self, s32, 0x410) >= 0x1E) {
            transition_enemy_state__9TObjEneDDFs(self, 3);
        }
        break;
    case 0:
        ((void (*)(void *))advance_animation_playback)(self);
        if (F(self, s32, 0x410) == 6) {
            t = ((TObjEneRe2Flower *)self)->find_target_in_range();
            if (t != NULL) {
                void *m = (void *)new TObjEneRe2Flower_EffCurse3((s32)self, (s32)t);
                F(self, u8 *, 0x390) = t;
                F(self, s32, 0x414) = 1;
                play_sound_effect(fn_800C3A60(self, 0x4003A50F), (u8 *)self + 0x38, 0, 0);
                TObjPlayer::play_effect_if_v2(-0x200);
            }
        } else if (F(self, s32, 0x410) == 0x19 && F(self, s32, 0x414) != 0 &&
                   is_alive__9TObjEneDDFv(F(self, void *, 0x390)) != 0) {
            if (((TObjEneRe2Flower *)self)->get_flag_11() != 0) {
                if (is_player_entity_id(get_entity_id(F(self, void *, 0x390))) != 0) {
                    send_6x2F_change_player_hp(F(self, u16, 0x1C), get_entity_id(F(self, void *, 0x390)), 1);
                }
            } else {
                Pair_800C2E64 p = lbl_8043BA60[0];
                Obj_800C2E64 *o = F(self, Obj_800C2E64 *, 0x390);
                o->hit(self, &p, F(o, s32, 0xA4), -1, -1);
            }
        }
        self->s198(F(self, s32, 0x410)++);
        self->s160();
        ((void (*)(void *))noop__9TObjEneDDFv)(self);
        break;
    case 5:
        F(self, u32, 0x30) &= ~0x04000000;
        F(self, u32, 0x3C4) &= ~2;
        break;
    }
}
#undef F

}
