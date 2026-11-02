#include "types.h"
#include "pso/player/TObjPlayer_8008DCF0_8008FC0C.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/TObjEneBalClawBody.h"
#include "pso/enemy/TObjEneBalClaw.h"
#include "pso/enemy/TObjEneBalClawClaw.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
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
    virtual s32 m17(s32);
};

extern "C" {
s32 TObjPlayer__sub_8008DD14();
s32 update_move_to_target__10TObjPlayerFv();
s32 TObjPlayer__sub_8008E254();
s32 TObjPlayer__sub_8008E310();
s32 TObjPlayer__sub_8008EC3C();
s32 TObjPlayer__sub_8008EDE8();
s32 TObjPlayer__sub_8008F1DC();
s32 run_death_sequence__10TObjPlayerFv();
s32 TObjPlayer__sub_8008F910();
s32 TObjPlayer__sub_8008FAD0();
f32 xz_distance_squared(void *, void *);
extern const f32 lbl_805D9644;

void TObjEneMe1GiGue__sub_8008FC0C(void) {  }

#define F(T, o) (*(T *)(((u8 *)this) + (o)))
#define VO ((VObj_18 *)(((u8 *)this)))
void TObjEneBalClawBody::sub_8008FC10() {
    f32 d;
    s32 old;
    if (F(s16, 0x326) != 0 && F(s16, 0x326) != 8) {
        F(s32, 0x3D4)++;
    }
    if (((TObjPlayer *)((u8 *)this))->get_flag_0x388_b24() != 0) {
        switch (F(s16, 0x326)) {
        case 0:
        case 1:
            if (F(s32, 0x3D4) > 0x708 || F(s16, 0x3DA) >= 2) {
                ((TObjEnemyCustom *)((u8 *)this))->update_if_active(0xB);
                return;
            }
            break;
        }
        if (VO->m17(0x1E) != 0) {
            ((TObjEnemyCustom *)((u8 *)this))->find_target_in_range(lbl_805D9644);
        }
        switch (F(s16, 0x326)) {
        case 0:
        case 8:
            if (F(u32, 0x2A8) != 0) {
                ((TObjEnemyCustom *)((u8 *)this))->update_if_active(1);
                F(s32, 0x38C) = 2;
            } else {
                ((TObjEnemyCustom *)((u8 *)this))->sub_800C73F4();
            }
            break;
        case 1:
            if (F(u32, 0x2A8) != 0) {
                d = xz_distance_squared((void *)(F(u32, 0x2A8) + 0x38), ((u8 *)this) + 0x38);
                old = F(s32, 0x38C);
                switch (old) {
                case 0:
                    if (d > 3600.0f) {
                        F(s32, 0x38C) = 1;
                    }
                    break;
                case 1:
                    if (d < 1600.0f) {
                        F(s32, 0x38C) = 0;
                    } else if (d > 14400.0f) {
                        F(s32, 0x38C) = 2;
                    }
                    break;
                case 2:
                    if (d < 10000.0f) {
                        F(s32, 0x38C) = 1;
                    }
                    break;
                }
                if (old != F(s32, 0x38C)) {
                    switch (F(s32, 0x38C)) {
                    case 0:
                        ((TObjEnemyCustom *)((u8 *)this))->update_if_active(9);
                        break;
                    case 1:
                        ((TObjEneBalClaw *)((u8 *)this))->clear_attack_flag();
                        break;
                    case 2:
                        ((TObjEneBalClaw *)((u8 *)this))->set_attack_distance_flag();
                        break;
                    }
                }
            } else {
                ((TObjEnemyCustom *)((u8 *)this))->update_if_active(8);
            }
            break;
        }
    } else {
        if (VO->m17(0x1E) != 0 && F(s16, 0x326) != 2) {
            ((TObjEnemyCustom *)((u8 *)this))->find_target_in_range(lbl_805D9644);
        }
        switch (F(s16, 0x326)) {
        case 0:
            if (VO->m17(0x1E) != 0 && F(u32, 0x2A8) == 0) {
                ((TObjEnemyCustom *)((u8 *)this))->update_if_active(0xA);
                return;
            }
            break;
        case 1:
        case 12:
            if (F(s32, 0x3D4) > 0x708) {
                ((TObjEnemyCustom *)((u8 *)this))->update_if_active(0xA);
                return;
            }
            break;
        }
        switch (F(s16, 0x326)) {
        case 0:
        case 8:
            if (F(u32, 0x2A8) != 0) {
                ((TObjEnemyCustom *)((u8 *)this))->update_if_active(0xC);
            } else {
                ((TObjEnemyCustom *)((u8 *)this))->sub_800C73F4();
            }
            break;
        case 1:
            if (F(u32, 0x2A8) == 0) {
                ((TObjEnemyCustom *)((u8 *)this))->update_if_active(8);
            }
            break;
        }
    }
}

void TObjEneBalClawBody::sub_8008FF50() {
  s16 temp_r0;
  temp_r0 = this->mode;
  {
    switch (temp_r0)
    {
      case 0:
        this->update_dragon_boss_state();
        return;
      case 1:
        TObjPlayer__sub_8008FAD0();
        return;
      case 2:
        TObjPlayer__sub_8008F1DC();
        return;
      case 9:
        TObjPlayer__sub_8008EDE8();
        return;
      case 4:
        TObjPlayer__sub_8008F910();
        return;
      case 5:
        run_death_sequence__10TObjPlayerFv();
        return;
      case 7:
        TObjPlayer__sub_8008EC3C();
        return;
      case 10:
        TObjPlayer__sub_8008E310();
        return;
      case 11:
        TObjPlayer__sub_8008E254();
        return;
      case 12:
        update_move_to_target__10TObjPlayerFv();
        return;
      case 8:
        TObjPlayer__sub_8008DD14();
        break;
    }
  }
}

}
