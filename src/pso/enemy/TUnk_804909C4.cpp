#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/enemy/TUnk_804909C4.h"
#include "pso/enemy/TUnk_804909C4.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEneDarkGunCenter.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneDarkGunner.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_80490470.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjGyaranzoMissile.h"
#include "pso/misc/TEneEffHamon.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/enemy/SaverLifecycle.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/TParticleCtrl.h"

struct VBase_18_4a35f9 { char pad[0x18]; };

struct VObj_18_4a35f9 : VBase_18_4a35f9 {
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
    virtual s32 m21(void *, void *, s32, s32, s32);
    virtual void m22();
    virtual s32 m23(void *, f32);
};

struct Pair_800A3290 { s32 a; f32 b; };

struct Sub_800A3290 { u8 pad0[0x18]; u32 flags; };

struct Obj_800A3290 { u8 pad0[0xA4]; Sub_800A3290 *sub; };

struct Vec_800A34E8 { f32 x, y, z; };

extern "C" {
Obj_800A3290 *find_entity_by_id(s32);
void check_enemy_body_collisions(void *arg0);
VObj_18_4a35f9 *get_battle_param__10TObjPlayerFi(s32);
s32 obj_is_hit_receivable();
s32 TObjPlayer__sub_800A3210(s32 i, s32 _w1, s32 _w2);
s32 vec3_add_to(void *, void *);
void queue_destruction__7TObjectFv(void *arg0);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
s32 __ct__14TObjCollidableFP7TObject(void *, void *);
s32 init_collision_body_parts(void *, void *, int);
s16 get_entity_id(void *, f32);
s32 subtract_vector(void *, void *);
f32 atan2_float(f32, f32);
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e);
u8 *csnVector(void *, Vec_800A34E8 *, s32);
extern void *tl_04;
extern f32 player_scale_factor;
extern s32 __vt__13TUnk_804909C4[];
extern s32 lbl_80490998[];
void *__dt__13TUnk_804909C4Fv(void *arg0, s16 arg1);

s32 TUnk_804909C4::sub_800A3290(s32 id) {
    Obj_800A3290 *other;
    s32 result = 0;
    s32 i;
    VObj_18_4a35f9 *p;
    other = find_entity_by_id(id);
    if (other == NULL) {
        return 0;
    }
    other->sub->flags &= ~1;
    TObjPlayer::init_all_slots();
    ((TObjPlayer *)this)->check_object_collisions();
    check_enemy_body_collisions(this);
    other->sub->flags |= 1;
    if (((Obj_800A3290 *)this)->sub->flags & 0x180000) {
        for (i = 0; i < 16; i++) {
            p = get_battle_param__10TObjPlayerFi(i);
            if (p == NULL) {
                break;
            }
            if (obj_is_hit_receivable() != 0 && p != (VObj_18_4a35f9 *)other) {
                Pair_800A3290 t = {0, 0.0f};
                t.b = ((s32 (*)(s32))TObjPlayer__sub_800A3210)(3);
                Pair_800A3290 u = t;
                p->m21(other, &u, 0, -1, -1);
                p->m23(other, 3.0f);
                result = 1;
            }
        }
    }
    return result;
}

void TUnk_804909C4::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x38));
    vec3_add_to((u8 *)&this->position, (u8 *)&this->unk_AC);
    {
        void *p = (void *) this->m_d0;
        if (p != NULL) {
            ((TNowLoading *)p)->copy_pos((u8 *)&this->position);
        }
    }
    if (((TUnk_804909C4 *)arg0)->sub_800A3290((s32)((int) (*(u16 *)((s8 *)arg0 + 0xC8)))) != 0) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    temp_r0 = this->m_c4 - 1;
    this->m_c4 = temp_r0;
    if (temp_r0 <= 0) {
        queue_destruction__7TObjectFv((arg0));
    }
}

}
TUnk_804909C4::~TUnk_804909C4() {
    free_collision_body_parts(this);
    if ((u32) *(u32 *)((s8 *)this + 0xD0) != 0U) {
        queue_destruction__7TObjectFv(this->m_d0);
    }
}
extern "C" {

}
TUnk_804909C4::TUnk_804909C4(u8 *player, s32 arg2, s32 arg3) : TObjCollidable((TObject *)tl_04) {
    s32 var_r0;
    u8 *temp_r3;
    init_collision_body_parts(((u8 *)this), lbl_80490998, 1);
    *(f32 *)((s8 *)(this->bodies) + 0xC) = 0.75f * player_scale_factor;
    *(s16 *)((s8 *)this + 0xC8) = get_entity_id(player, 0.75f);
    if (((TObjPlayer *)player)->is_flag_set_388_bit26() != 0) {
        var_r0 = 0xDA;
    } else {
        var_r0 = 0xD5;
    }
    this->m_cc = var_r0;
    *(s16 *)((s8 *)this + 0x28) = *(s16 *)((s8 *)player + 0x28);
    VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)(arg2));
    VecCopy((Vec *)(((u8 *)this) + 0xAC), (const Vec *)(arg3));
    subtract_vector(((u8 *)this) + 0xAC, (void *)arg2);
    this->m_b0 = 0.0f;
    vec_set_length((Vec *)(((u8 *)this) + 0xAC), player_scale_factor);
    this->m_b8 = 0;
    *(s32 *)((s8 *)this + 0xBC) = (s32) (10430.38043493439 * atan2_float(*(f32 *)((s8 *)this + 0xAC), *(f32 *)((s8 *)this + 0xB4))) + 0x4000;
    this->m_c0 = 0x4000;
    *(s32 *)((s8 *)this + 0xD0) = (s32)spawn_particle_effect_with_rotation((((u8 *)this) + 0x38), (((u8 *)this) + 0xB8), this->m_cc, 0x42);
    {
    Vec_800A34E8 v = *(Vec_800A34E8 *)(((u8 *)this) + 0xAC);
    vec_set_length((Vec *)(&v), 500.0f);
    vec3_add_to(&v, ((u8 *)this) + 0x38);
    temp_r3 = csnVector(((u8 *)this) + 0x38, &v, -1);
    }
    if (temp_r3 != NULL) {
        this->m_c4 = (s32) (vec_xz_distance((Vec *)(((u8 *)this) + 0x38), *(Vec **)((s8 *)temp_r3 + 4)) / player_scale_factor);
    } else {
        this->m_c4 = (s32) (500.0f / player_scale_factor);
    }
}
extern "C" {
}
