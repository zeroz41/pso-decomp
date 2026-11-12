#include "pso/animation/MotionContext.h"
#include "pso/enemy/shinowa/TObjEneMe3Shinowa.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/math/FloatRounding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/effect/TUnk_80494968.h"
#include "pso/system/vector.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/system/BmlResource.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/enemy/dd/TObjEneDD_800BB804.h"
#include "pso/npc/TObjNpcEnemy_803D8090.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaMirage.h"
#include "pso/enemy/saver/TObjEneSaver.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/render/TUnk_80494938.h"
#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/technique/TTecResta.h"
#include "pso/technique/TTecSifta.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaMirage_800E7A70.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_80087278.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/enemy/panarms/TObjEnePanarmsAtkColli.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/unk/TLobby.h"
#include "pso/render/NinjaUtil.h"
#include "pso/enemy/deldepth/DelDepthData.h"

struct VBase_18_f56c51
{
  char pad[0x18];
};

struct VObj_18_f56c51 : VBase_18_f56c51 {
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
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
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
    virtual s32 m100(f32);
};

struct RecoveredFields_800E3970_arg0
{
  u8 unknown_0[0x30];
  s32 field_30;
  u8 unknown_34[0x8];
  f32 field_3C;
  u8 unknown_40[0x8];
  f32 field_48;
  u8 unknown_4C[0x58];
  u8 *field_A4;
  u8 unknown_A8[0x31C];
  s32 field_3C4;
  u8 unknown_3C8[0x68];
  f32 field_430;
};

extern "C" {
s32 set_flag_0x100__23TObjEneMe3ShinowaMirageFv();

void TObjEneMe3ShinowaMirage__vt113(u8 *ene_me3_shinowa_mirage, s32 arg1) {
  f32 temp_f1;
  long new_var;
  switch (arg1)
  {
    case 4:
      ((RecoveredFields_800E3970_arg0 *) ene_me3_shinowa_mirage)->field_3C4 = (s32) (((RecoveredFields_800E3970_arg0 *) ene_me3_shinowa_mirage)->field_3C4 & 0xFFFFFFFC);
      ((RecoveredFields_800E3970_arg0 *) ene_me3_shinowa_mirage)->field_3C4 = (s32) (((RecoveredFields_800E3970_arg0 *) ene_me3_shinowa_mirage)->field_3C4 | 0x200);
      (((TObjEneMe3ShinowaMirage *)(ene_me3_shinowa_mirage))->vfunc_94());
      ((RecoveredFields_800E3970_arg0 *) ene_me3_shinowa_mirage)->field_430 = 0.0f;
      return;
    case 3:
      if (((RecoveredFields_800E3970_arg0 *) ene_me3_shinowa_mirage)->field_430 <= -1.0f)
    {
      new_var = ((RecoveredFields_800E3970_arg0 *) ene_me3_shinowa_mirage)->field_3C4 & 0xFFFFFDFF;
      ((RecoveredFields_800E3970_arg0 *) ene_me3_shinowa_mirage)->field_3C4 = (s32) new_var;
      set_flag_0x100__23TObjEneMe3ShinowaMirageFv();
      ((RecoveredFields_800E3970_arg0 *) ene_me3_shinowa_mirage)->field_3C = -500.0f;
      ((RecoveredFields_800E3970_arg0 *) ene_me3_shinowa_mirage)->field_48 = -500.0f;
      *((f32 *) (((s8 *) ((RecoveredFields_800E3970_arg0 *) ene_me3_shinowa_mirage)->field_A4) + 0x20)) = -500.0f;
      ((RecoveredFields_800E3970_arg0 *) ene_me3_shinowa_mirage)->field_30 = (s32) (((RecoveredFields_800E3970_arg0 *) ene_me3_shinowa_mirage)->field_30 | 0x800);
    }
    case 5:
      return;
    case 0:
      temp_f1 = ((RecoveredFields_800E3970_arg0 *) ene_me3_shinowa_mirage)->field_430;
      ((RecoveredFields_800E3970_arg0 *) ene_me3_shinowa_mirage)->field_430 = (f32) (temp_f1 - 0.1f);
      (((VObj_18_f56c51 *)(ene_me3_shinowa_mirage))->m100((temp_f1)));
      break;
  }
  return;
}

}



struct Base_800e3a88_800E3A58 { char pad[0x14]; };
struct VObj_800e3a88_800E3A58 : Base_800e3a88_800E3A58 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};
struct Base_800E3B34_800E3A58 { char pad[0x18]; };
struct VObj_800E3B34_800E3A58 : Base_800E3B34_800E3A58 {
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
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
};

struct VB14_800E3DFC { u8 pad[0x14]; };
struct Sub_800E3DFC : VB14_800E3DFC {
    virtual void v0();
    virtual void v1(s32, void *, f32);
    virtual void v2();
};
struct VB18_800E3DFC { u8 pad[0x18]; };
struct Self_800E3DFC : VB18_800E3DFC {
#define V(n) virtual void m##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84)
#undef V
    virtual void m85(s16, s32);
};

struct VBase_14_85ec0b { char pad[0x14]; };

struct VObj_14_85ec0b : VBase_14_85ec0b {
    virtual void m0();
    virtual void m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
};

struct Stack_800E3F8C {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct VBase_800E420C { char pad[0x18]; };

struct VObj_800E420C : VBase_800E420C {
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
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
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
    virtual s32 m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
};

struct Vec_800E420C { f32 x, y, z; };

extern "C" {
int transition_enemy_state__9TObjEneDDFl(void*, int);
s32 draw_model__23TObjEneMe3ShinowaMirageFv();
void run_task__17TObjEneMe3ShinowaFv(u8 *arg0);
s32 all_parents_unqueued_for_destruction__7TObjectFv();
s32 enemy_clear_target__12TObjEneDD_STFUs(void *);
s32 transform_relative_position__9TObjEneDDFPv(void *, void *);
s32 is_player_entity_id(u16);
void *__dt__23TObjEneMe3ShinowaMirageFv(void *arg0, s16 arg1);
s32 enemy_set_target_id(void *, u16);
u8 *TObjEneMe3ShinowaMirage__ct(u8 *, void *, u8 *, void *, void *);
void fn_800E762C(void *);
void *TObjEneMe3Shinowa__ct(void *, void *);
u16 TObjEneMe3ShinowaReal__sub_800E45CC(void *p);
extern s32 lbl_805D2AD0;
void __dl__7TObjectFPv(void *);
void *__dt__17TObjEneMe3ShinowaFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

void TObjEneMe3ShinowaMirage::render() {
    u8 *arg0 = (u8 *)this;
    if (!(*(s32 *)((s8 *)arg0 + 0x3C4) & 0x100)) {
        draw_model__23TObjEneMe3ShinowaMirageFv();
    }
}

void TObjEneMe3ShinowaMirage::apply_effect_pair() {  }

void TObjEneMe3ShinowaMirage::dispatch_if_active() {
    s32 arg0 = (s32)this;

    ((VObj_800e3a88_800E3A58 *) ((unsigned char *) (arg0 + 0x3E8)))->m7();
}

extern s32 model_render_flags;

s32 TObjEneMe3ShinowaMirage::update_effect() {
    s32 arg0 = (s32)this;
    model_render_flags |= 0x820;
    set_constant_material((const NJS_ARGB *)((arg0 + 0x430)));
    set_chunk_material_override_pair(0xFF00, 0x800);
    return 0;
}

void TObjEneMe3ShinowaMirage::clear_mirage() {
    *(s32 *)((s8 *)this + 0x3C4) = (s32) (*(s32 *)((s8 *)this + 0x3C4) & 0xFFFFFEFF);
    this->vfunc_93();
}

void TObjEneMe3ShinowaMirage::set_flag_0x100() {
    struct VObj_800E3B34_800E3A58 *o = (struct VObj_800E3B34_800E3A58 *)this;
    *(s32 *)((s8 *)this + 0x3C4) = (s32) (*(s32 *)((s8 *)this + 0x3C4) | 0x100);
    o->m92();
}

int TObjEneMe3ShinowaMirage::init_mirage() { return transition_enemy_state__9TObjEneDDFl(this, 15); }


void TObjEneMe3ShinowaMirage::activate_mirage(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 entity;
    s32 temp_r4;
    s32 temp_r4_2;

    entity = (s32)find_entity_by_id((*(u16 *)((s8 *)arg0 + 0x42C)));
    if (entity != 0) {
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(entity + 0x38));
        VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x38));
        VecCopy((Vec *)(*(s32 *)&this->bodies + 0x1C), (const Vec *)(arg0 + 0x38));
        copy_xyz(arg0 + 0x5C, (void *)(entity + 0x5C));
        temp_r4 = this->actorFlags & 0xFFFFF7FF;
        this->actorFlags = temp_r4;
        this->actorFlags = 0x20000000;
        this->hp = (s16) this->hpmax;
        *(s32 *)((s8 *)arg0 + 0x3D4) = arg1;
        enemy_set_target_id(arg0, TObjEneMe3ShinowaReal__sub_800E45CC((void *)entity));
        *(f32 *)((s8 *)arg0 + 0x430) = 0.0f;
        temp_r4_2 = *(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFDFF;
        *(s32 *)((s8 *)arg0 + 0x3C4) = temp_r4_2;
        this->requested_action = 0xA;
        ((TObjMotion *)arg0)->advance_animation();
        this->frame = (f32) (u32) (this->current_motion->nbFrame - 1);
        transition_enemy_state__9TObjEneDDFl(arg0, 8);
        clear_mirage();
    }
}

void TObjEneMe3ShinowaMirage::update_player_state_default() {  }
void TObjEneMe3ShinowaMirage::vfunc_107() { transition_enemy_state__9TObjEneDDFl(this, 4); }
u8 TObjEneMe3ShinowaMirage::can_hit_same_target() { return 0; }
void TObjEneMe3ShinowaMirage::vfunc_105() {  }

void TObjEneMe3ShinowaMirage::vfunc_62() {
    if (this->mode != 15) {
        transition_enemy_state__9TObjEneDDFl(this, 15);
    }
    clear_attack_receipts();
}

extern void *__vt__23TObjEneMe3ShinowaMirage[];

void TObjEneMe3ShinowaMirage::vfunc_63() {
    u8 *arg0 = (u8 *)this;
    if ((s16) this->mode != 0xF) {
        transition_enemy_state__9TObjEneDDFl(arg0, 0xF);
    }
}

void TObjEneMe3ShinowaMirage::run_task() {
    u8 *arg0 = (u8 *)this;
    if ((find_entity_by_id((*(u16 *)((s8 *)arg0 + 0x42C))) == 0U) || (all_parents_unqueued_for_destruction__7TObjectFv() == 0)) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    if (!(*(s32 *)((s8 *)arg0 + 0x3C4) & 0x100)) {
        run_task__17TObjEneMe3ShinowaFv((arg0));
    }
}

void *__dt__23TObjEneMe3ShinowaMirageFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void ***)((s8 *)arg0 + 0x18) = __vt__23TObjEneMe3ShinowaMirage;
        __dt__17TObjEneMe3ShinowaFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#define arg3 ((s16)(s32)a3)
#define arg4 ((s16)(s32)a4)
u8 *TObjEneMe3ShinowaMirage__ct(u8 *ene_me3_shinowa_mirage, void *ene_me3_shinowa, u8 *arg2, void *a3, void *a4) {
    u8 *temp_r5;

    TObjEneMe3Shinowa__ct(ene_me3_shinowa_mirage, ene_me3_shinowa);
    *(void ***)((s8 *)ene_me3_shinowa_mirage + 0x18) = __vt__23TObjEneMe3ShinowaMirage;
    *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0) = (s32) lbl_805D2AD0;
    *(s16 *)((s8 *)ene_me3_shinowa_mirage + 0x42C) = get_entity_id((TObjBase *)arg2);
    ((TObjEneDD *)ene_me3_shinowa_mirage)->init_common_from((u8 *)arg2);
    *(f32 *)((s8 *)ene_me3_shinowa_mirage + 0x358) = (f32) *(f32 *)((s8 *)arg2 + 0x358);
    fn_800E762C(ene_me3_shinowa_mirage);
    ((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->entity_id = arg3;
    *(s16 *)((s8 *)ene_me3_shinowa_mirage + 0x2C) = arg4;
    ((TObjEneMe3Shinowa *)ene_me3_shinowa_mirage)->init_enemy();
    *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3D4) = 0;
    *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C4) = (s32) (*(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C4) | 0x1000);
    ((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->set_flag_0x100();
    *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3D0) = 0xB000FFB0;
    *(f32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C) = -500.0f;
    *(f32 *)((s8 *)ene_me3_shinowa_mirage + 0x48) = -500.0f;
    temp_r5 = (unsigned char *) (((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->bodies);
    *(f32 *)((s8 *)temp_r5 + 0x20) = -500.0f;
    ((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->actorFlags = (s32) (((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->actorFlags | 0x800);
    *(f32 *)((s8 *)ene_me3_shinowa_mirage + 0x430) = 0.0f;
    ((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->m_434 = 0.0f;
    *(f32 *)((s8 *)ene_me3_shinowa_mirage + 0x438) = 0.0f;
    ((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->m_43c = 0.0f;
    ((Sub_800E3DFC *)(ene_me3_shinowa_mirage + 0x3E8))->v1(0, temp_r5, -500.0f);
    ((Sub_800E3DFC *)(ene_me3_shinowa_mirage + 0x3E8))->v2();
    ((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->mode = 8;
    ((Self_800E3DFC *)ene_me3_shinowa_mirage)->m85(((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->mode, 4);
    return ene_me3_shinowa_mirage;
}
#undef arg3
#undef arg4

extern void *tl_04;

void *TObjEneMe3ShinowaMirage::create(void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0x440);
    if (o != NULL) {
        o = TObjEneMe3ShinowaMirage__ct((u8 *)o, tl_04, (u8 *)this, arg1, arg2);
    }
    return o;
}
#pragma push
#pragma fp_contract on
void TObjEneMe3ShinowaReal::vfunc_116(s32 arg1) {
    typedef char sp8_offset[(offsetof(Stack_800E3F8C, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800E3F8C, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800E3F8C, sp10) == 0x8) ? 1 : -1];
    Stack_800E3F8C stack;
    s32 temp_r3;
    u8 *particle_ctrl;
    u8 *object;
    switch (arg1) {
    case 4:
        this->requested_action = 7;
        this->set_field_378(0x10);
        this->vfunc_96();
        *(s32 *)((s8 *)((u8 *)this) + 0x3C4) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x3C4) & 0xFFFFFFFD);
        *(s32 *)((s8 *)((u8 *)this) + 0x3C4) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x3C4) | 1);
        *(s32 *)((s8 *)((u8 *)this) + 0x404) = 0;
        *(u8 **)((s8 *)((u8 *)this) + 0x424) = NULL;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x404) == 3) {
            this->try_spawn_mirages();
            transition_enemy_state__9TObjEneDDFl((void*)this, 4);
        }
        return;
    case 0:
        switch (*(s32 *)((s8 *)((u8 *)this) + 0x404)) {
        case 0:
            advance_animation();
            if (this->get_flag_b4() != 0) {
                temp_r3 = *(s32 *)((s8 *)((u8 *)this) + 0x3C4);
                if (temp_r3 & 0x80000) {
                    ((VObj_14_85ec0b *)((u8 *)this + (1000)))->m3();
                    *(s32 *)((s8 *)((u8 *)this) + 0x404) = 1;
                } else {
                    *(s32 *)((s8 *)((u8 *)this) + 0x3C4) = (s32) (temp_r3 | 0x80000);
                    ((VObj_14_85ec0b *)((u8 *)this + (1000)))->m2();
                    *(s32 *)((s8 *)((u8 *)this) + 0x404) = 2;
                }
            }
            if (this->frame >= 12.0f) {
                if ((void *) *(u8 **)((s8 *)((u8 *)this) + 0x424) == NULL) {
                    *(u8 **)((s8 *)((u8 *)this) + 0x424) = (unsigned char *) (create_particle_emitter((u8 *)this + 0x38, 0x114));
                    particle_ctrl = (u8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x424));
                    if (particle_ctrl != NULL) {
                        ((TParticleCtrl *)particle_ctrl)->enable();
                    }
                } else {
                    VecCopy((Vec *)&stack.sp8, (const Vec *)((u8 *)this + 0x38));
                    stack.sp8 += 15.0f * sin_table_lookup(this->rotation_y);
                    stack.spC += 17.0f;
                    stack.sp10 += 15.0f * cos_table_lookup(this->rotation_y);
                    ((TParticleCtrl *)*(u8 **)((s8 *)((u8 *)this) + 0x424))->set_position(&stack.sp8);
                }
            }
            break;
        case 1:
            if (((VObj_14_85ec0b *)((u8 *)this + (1000)))->m5() != 0) {
                *(s32 *)((s8 *)((u8 *)this) + 0x404) = 3;
                *(s32 *)((s8 *)((u8 *)this) + 0x3C4) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x3C4) & 0xFFF7FFFF);
            }
            break;
        case 2:
            if (((VObj_14_85ec0b *)((u8 *)this + (1000)))->m4() != 0) {
                *(s32 *)((s8 *)((u8 *)this) + 0x404) = 3;
            }
            break;
        }
        this->vfunc_102();
        this->vfunc_89();
        return;
    case 5:
        object = (u8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x424));
        if (object != NULL) {
            queue_destruction__7TObjectFv(object);
            *(u8 **)((s8 *)((u8 *)this) + 0x424) = NULL;
        }
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
#define I(o) (*(s32 *)((s8 *)(((u8 *)this)) + (o)))
#define R(o) (*(f32 *)((s8 *)(((u8 *)this)) + (o)))
#define P(o) (*(u8 **)((s8 *)(((u8 *)this)) + (o)))
#define V ((VObj_800E420C *)(((u8 *)this)))
void TObjEneMe3ShinowaReal::vfunc_114(s32 arg1) {
    s32 ok;
    s32 n;
    Vec_800E420C v;
    switch (arg1) {
    case 4:
        this->requested_action = 7;
        this->set_field_378(0xE);
        V->m94();
        I(0x3C4) &= ~3;
        I(0x424) = 0;
        break;
    case 3:
        if (this->get_flag_b4() != 0) {
            I(0x3B8) = I(0x3BC);
            ok = 0;
            if (V->m97() != 0 || is_player_entity_id(this->m_38c) != 0) {
                if (transform_relative_position__9TObjEneDDFPv(this, P(0x390)) != 0) {
                    ok = 1;
                }
            } else {
                enemy_clear_target__12TObjEneDD_STFUs(this);
            }
            if (ok == 1) {
                this->enemy_copy_target_destination();
                I(0x3D4) = (s32)(5.0f * random_ratio__9TObjCharaFv((s32)this));
                ok = 0;
                n = 0;
                for (; ok < 5; ok++) {
                    if (I(0x3D4) != ok) {
                        ((TObjEneMe3ShinowaMirage *)(this->get_or_create_mirage(n++)))->activate_mirage(ok);
                    }
                }
                transition_enemy_state__9TObjEneDDFl(this, 8);
                play_sound_effect(((TObjEnemy *)(this))->remap_sound_for_area((s32)(0x4003AD15)), ((u8 *)this) + 0x38, 0, 0);
            } else {
                this->try_spawn_mirages();
                transition_enemy_state__9TObjEneDDFl(this, 4);
            }
        }
        break;
    case 0:
        advance_animation();
        if (R(0xC0) >= 12.0f) {
            if (P(0x424) == NULL) {
                P(0x424) = (u8 *)create_particle_emitter((u8 *)this + 0x38, 0x114);
                if (P(0x424) != NULL) {
                    ((TParticleCtrl *)(P(0x424)))->enable();
                }
            } else {
                VecCopy((Vec *)&v, (const Vec *)(((u8 *)this) + 0x38));
                v.x = 15.0f * sin_table_lookup(I(0x60)) + v.x;
                v.y += 17.0f;
                v.z = 15.0f * cos_table_lookup(I(0x60)) + v.z;
                ((TParticleCtrl *)P(0x424))->set_position(&v);
            }
        }
        V->m100();
        V->m87();
        break;
    case 5:
        if (P(0x424) != NULL) {
            queue_destruction__7TObjectFv(P(0x424));
            P(0x424) = NULL;
        }
        break;
    }
}
#pragma pop

}



struct Obj_800E4554 { u8 pad0[0x1C]; u16 f1C; u8 pad1E[0xE]; s16 f2C; u8 pad2E[0x42C - 0x2E]; u16 slots[8]; };

struct Base_800E46D4 { s32 f0; u8 pad4[0x14]; };

struct Obj_800E46D4 : Base_800E46D4 {
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
    virtual void v21();
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
    virtual void m85(s16, s32);
    u8 pad1C[0x326 - 0x1C];
    s16 f326;
    u8 pad328[0x3C4 - 0x328];
    u32 f3C4;
    u8 pad3C8[0x3D4 - 0x3C8];
    s32 f3D4;
    u8 pad3D8[0x42C - 0x3D8];
    u16 slots[8];
};

extern "C" {
TObjEneMe3ShinowaMirage *create__23TObjEneMe3ShinowaMirageFPvPv(void *, s32, s32, s32);
void invoke_initialization_hook__9TObjEneDDFPv(void *, void *);
extern s32 TObjEneMe3ShinowaReal_class_name;
extern s32 __vt__21TObjEneMe3ShinowaReal[];
Obj_800E46D4 *TObjEneMe3ShinowaReal__ct(Obj_800E46D4 *arg0, void *arg1, void *arg2);
void *__dt__21TObjEneMe3ShinowaRealFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void *__dt__17TObjEneMe3ShinowaFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

void TObjEneMe3ShinowaReal::spawn_mirages() {
    int i;
    for (i = 0; i < 4; i++) {
        get_or_create_mirage(i)->init_mirage();
    }
}
void TObjEneMe3ShinowaReal::vfunc_111() { this->try_spawn_mirages(); }

void TObjEneMe3ShinowaReal::vfunc_107() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x3D8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3D8) + 1);
    if ((s32) *(s32 *)((s8 *)arg0 + 0x3D8) >= 2) {
        ((TObjEneMe3ShinowaReal *)arg0)->try_spawn_mirages();
        ((TObjEneDD *)arg0)->transition_enemy_state(7);
        return;
    }
    ((TObjEneDD *)arg0)->transition_enemy_state(4);
}

TObjEneMe3ShinowaMirage *TObjEneMe3ShinowaReal::get_or_create_mirage(s32 index) {
    Obj_800E4554 *arg0 = (Obj_800E4554 *)this;
    TObjEneMe3ShinowaMirage *r;
    if (arg0->slots[index] == 0xFFFF) {
        u16 t = this->entity_id;
        s32 n = index + 1;
        r = create__23TObjEneMe3ShinowaMirageFPvPv(arg0, (u16)(t + n), arg0->f2C + n, t);
        if (r != 0) {
            arg0->slots[index] = get_entity_id(r);
        }
    } else {
        r = (TObjEneMe3ShinowaMirage *)find_entity_by_id(arg0->slots[index]);
    }
    return r;
}

u16 TObjEneMe3ShinowaReal__sub_800E45CC(void* p) { return *(u16*)((char*)p + 0x38c); }

void TObjEneMe3ShinowaReal::try_spawn_mirages() {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)((s8 *)arg0 + 0x3C4) & 0x10) {
        sub_800E7250();
        spawn_mirages();
    }
}

void TObjEneMe3ShinowaReal::vfunc_62() {
    try_spawn_mirages();
    TObjEneMe3Shinowa::vfunc_62();
}
void TObjEneMe3ShinowaReal::vfunc_63() {
    try_spawn_mirages();
    TObjEneMe3Shinowa::vfunc_63();
}

void *__dt__21TObjEneMe3ShinowaRealFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__21TObjEneMe3ShinowaReal;
        __dt__17TObjEneMe3ShinowaFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_04;

Obj_800E46D4 *TObjEneMe3ShinowaReal__ct(Obj_800E46D4 *arg0, void *ene_me3_shinowa, void *arg2) {
    s32 i;
    TObjEneMe3Shinowa__ct(arg0, ene_me3_shinowa);
    *(void **) ((u8 *) arg0 + 0x18) = ((u8 *)&__vt__21TObjEneMe3ShinowaReal);
    arg0->f0 = TObjEneMe3ShinowaReal_class_name;
    invoke_initialization_hook__9TObjEneDDFPv(arg0, arg2);
    fn_800E762C(arg0);
    ((TObjEneMe3Shinowa *)arg0)->init_enemy();
    arg0->f3D4 = 0;
    arg0->f3C4 &= 0xFFFFEFFF;
    for (i = 0; i < 4; i++) {
        arg0->slots[i] = 0xFFFF;
    }
    arg0->f326 = 0;
    arg0->m85(arg0->f326, 4);
    return arg0;
}

void *TObjEneMe3ShinowaReal::create() {
    void *o = __nw__7TObjectFUl(0x434);
    if (o != NULL) {
        o = TObjEneMe3ShinowaReal__ct((Obj_800E46D4 *)(o), tl_04, this);
    }
    return o;
}

}



extern "C" void *__ct__12TObjEneDD_STFP7TObject(void *, void *);
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();

#define CAT2(a, b) a##b
#define CAT(a, b) CAT2(a, b)
#define PAD_VIRT virtual void CAT(pv, __LINE__)();
#define PADV virtual void CAT(pv, __LINE__)();
#define PADV4 virtual void CAT(pa, __LINE__)(); virtual void CAT(pb, __LINE__)(); virtual void CAT(pc, __LINE__)(); virtual void CAT(pd, __LINE__)();

struct VBase_18_2add4a { char pad[0x18]; };

struct VObj_18_2add4a : VBase_18_2add4a {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32 *, s32 *);
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
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual s32 m20(void *, f32);
    virtual void m21();
    virtual void m22();
    virtual s32 m23(void *, f32);
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
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual s32 m86();
    virtual s32 m87();
    virtual void m88();
    virtual s32 m89();
    virtual s32 m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual u32 m100();
};

struct VBase_18_a1ce10 { char pad[0x18]; };
struct VObj_18_a1ce10 : VBase_18_a1ce10 {
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
    virtual u32 m16(void *);
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
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual s32 m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual s32 m91();
    virtual s32 m92();
    virtual void m93();
    virtual s32 m94();
};

struct Vec_800E5F64 { f32 x, y, z; };

struct VBase_18_dc3190 { char pad[0x18]; };

struct VObj_18_dc3190 : VBase_18_dc3190 {
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
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual s32 m86();
    virtual s32 m87();
    virtual void m88();
    virtual s32 m89();
    virtual s32 m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
    virtual void m101();
    virtual s32 m102(f32);
};

struct VBase_18_4f5f2e { char pad[0x18]; };

struct VObj_18_4f5f2e : VBase_18_4f5f2e {
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
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual s32 m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
    virtual void m101();
    virtual void m102();
    virtual s32 m103();
    virtual void m104();
    virtual s32 m105();
    virtual void m106();
    virtual void m107();
    virtual void m108();
    virtual void m109();
    virtual s32 m110();
};

struct Info_800E5CE4 { u8 pad[0x8]; f32 f8; u8 pad2[0x14]; s32 f20; };


extern "C" {
u32 csnVecterUnder(void *, int);
s32 mult_vec_array__10TObjPlayerFUll(int, int, void *, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern SampledMotionPoints *TObjEneMe3ShinowaMirage__data_805D52AC;
void TObjEneMe3ShinowaMirage__sub_800E5F64(u8 *arg0, s32 arg1);
struct Tgt_800E54E8 { u16 id; u8 pad[6]; };
void rotate_xz_pair_by_angle(f32 *arg0, f32 *arg1, s32 arg2);
s32 transform_relative_position__9TObjEneDDFPv(void *, void *);
}
void calc_wall_clamped_destination(void *arg0, void *arg1, f32 dx, f32 dz, f32 dist);
extern "C" {
s32 collect_target_candidates__9TObjEneDDFlf(void *, f32);
s32 subtract_vector(void *, void *);
extern Tgt_800E54E8 enemy_target_candidate_table[];
s32 sub_800E6FE0__17TObjEneMe3ShinowaFv(u8 *arg0);
void TObjEneMe3ShinowaReal__sub_800E5950(u8 *arg0, s32 arg1);
s32 move_to_shot_position__9TObjEneDDFfff(void *, void *, f32, f32, f32);
void TObjEneMe3ShinowaMirage__sub_800E5CE4(u8 *arg0, s32 arg1);
struct Base_800E7034_800E47DC { char pad[0x18]; };

struct VObj_800E7034_800E47DC : Base_800E7034_800E47DC {
    virtual void m0();  virtual void m1();  virtual void m2();  virtual void m3();
    virtual void m4();  virtual void m5();  virtual void m6();  virtual void m7();
    virtual void m8();  virtual void m9();  virtual void m10(); virtual void m11();
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
    virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83();
    virtual void m84(); virtual void m85(); virtual void m86();
};

struct Base_800E707C_800E47DC { char pad[0x18]; };

struct VObj_800E707C_800E47DC : Base_800E707C_800E47DC {
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
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
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
};



struct Stack_800E6BB8 {
    s32 sp8;
    f32 spC;
};

struct VBase_14_948132 { char pad[0x14]; };

struct VObj_14_948132 : VBase_14_948132 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5();
};

struct VBase_18_4a41ce
{
  char pad[0x18];
};

struct VObj_18_4a41ce : VBase_18_4a41ce {
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
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual s32 m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
};

struct VBase_14_763762
{
  char pad[0x14];
};

struct VObj_14_763762 : VBase_14_763762 {
    virtual void m0();
    virtual void m1();
    virtual s32 m2();
    virtual void m3();
    virtual s32 m4();
};

struct RecoveredFields_800E50D8_arg0
{
  u8 unknown_0[0xB8];
  s16 field_B8;
  u8 unknown_BA[0x30A];
  s32 field_3C4;
  u8 unknown_3C8[0x3C];
  s32 field_404;
};

struct Info_800E6F0C { u8 pad_0[0xC]; f32 unk_C; f32 unk_10; u8 pad_14[4]; s32 frame; s32 frame_1C; };

struct VBase_18_800E530C { char pad[0x18]; };
struct VObj_18_800E530C : VBase_18_800E530C {
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
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
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
};

struct Obj_800E6F0C { u8 pad[0x38]; u8 pos[0x3c0 - 0x38]; s32 kind; };

typedef struct { f32 x, y, z; } Vec_800E4FE8;

struct Base_800E6DD8 { u8 pad[0x18]; };

struct Obj_800E6DD8 : Base_800E6DD8 {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p50();
    virtual void p51();
    virtual void p52();
    virtual void p53();
    virtual void p54();
    virtual void p55();
    virtual void p56();
    virtual void p57();
    virtual void p58();
    virtual void p59();
    virtual void p60();
    virtual void p61();
    virtual void p62();
    virtual void p63();
    virtual void p64();
    virtual void p65();
    virtual void p66();
    virtual void p67();
    virtual void p68();
    virtual void p69();
    virtual void p70();
    virtual void p71();
    virtual void p72();
    virtual void p73();
    virtual void p74();
    virtual void p75();
    virtual void p76();
    virtual void p77();
    virtual void p78();
    virtual void p79();
    virtual void p80();
    virtual void p81();
    virtual void p82();
    virtual void p83();
    virtual void p84();
    virtual void p85();
    virtual void p86();
    virtual void p87();
    virtual void p88();
    virtual void p89();
    virtual void p90();
    virtual void p91();
    virtual void p92();
    virtual void p93();
    virtual void p94();
    virtual void p95();
    virtual void p96();
    virtual void p97();
    virtual void p98();
    virtual void p99();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void v111(s32);
    virtual void v112(s32);
    virtual void v113(s32);
    virtual void v114(s32);
};

struct VBase_18_82072c { char pad[0x18]; };

struct VObj_18_82072c : VBase_18_82072c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
    virtual s32 m9(f32, f32, f32);
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
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
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
    virtual void m103();
    virtual void m104();
    virtual void m105();
    virtual s32 m106();
    virtual s32 m107();
    virtual s32 m108();
    virtual void m109();
    virtual void m110();
    virtual void m111();
    virtual void m112();
    virtual void m113();
    virtual void m114();
    virtual void m115();
    virtual s32 m116();
};

struct Vec_800E4DD0 { f32 x, y, z; };

struct VBase_18_e66632 { char pad[0x18]; };

struct VObj_18_e66632 : VBase_18_e66632 {
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
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual s32 m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual s32 m104();
    virtual void m105();
    virtual void m106();
    virtual void m107();
    virtual void m108();
    virtual s32 m109();
};

struct VBase18b_800e70d4_800E47DC { char pad[0x18]; };

struct VObj18b_800e70d4_800E47DC : VBase18b_800e70d4_800E47DC {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4(void *, void *);
};


typedef struct RecoveredFields_800E50D8_arg0 RecoveredFields_800E50D8_arg0;

typedef struct VBase_14_763762 VBase_14_763762;

typedef struct VBase_18_4a41ce VBase_18_4a41ce;

typedef struct VObj_14_763762 VObj_14_763762;

typedef struct VObj_18_4a41ce VObj_18_4a41ce;

struct Info_800E6F0C;


struct E71ACBase_800e71ac_800E71A8 { char pad[0x14]; };

struct E71ACObj_800e71ac_800E71A8 : E71ACBase_800e71ac_800E71A8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

struct E71FCBase_800e71fc_800E71A8 { char pad[0x14]; };

struct E71FCObj_800e71fc_800E71A8 : E71FCBase_800e71fc_800E71A8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};

struct VBase_18_c44252 { char pad[0x18]; };

struct VObj_18_c44252 : VBase_18_c44252 {
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
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual s32 m20(void *, f32);
    virtual void m21();
    virtual void m22();
    virtual s32 m23(void *, f32);
};

struct Node_800E75AC { u8 pad[0x2c]; void *child; };

struct Sub_800E750C { f32 f0; u8 pad4[4]; f32 f8; f32 fC; f32 f10; s32 f14; s32 f18; };

struct Obj_800E750C { u8 pad0[0x60]; s32 f60; u8 pad1[0xA4 - 0x64]; Sub_800E750C *fA4; };

struct Obj_800E750C;

struct E_800E728C { u8 pad[0x60]; s32 f60; u8 pad64[0x390 - 0x64]; s32 f390; u8 pad394[0x3AC - 0x394]; f32 f3ac; u8 pad3b0[0x3C4 - 0x3B0]; s32 f3c4; };

struct VBase_800E7884 { u8 pad[0x14]; };

struct VObj_800E7884 : VBase_800E7884 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    u8 pad18[4];
};

struct Tbl_800E7884 { u8 pad[0xC]; s32 t[3][2]; };

struct Mirage_800E7884 {
    u8 pad0[0x34];
    s32 f34;
    u8 pad38[0x3C - 0x38];
    f32 f3C;
    u8 pad40[0xB0 - 0x40];
    s32 fB0;
    u8 padB4[0xB8 - 0xB4];
    s16 fB8;
    u8 padBA[0x2CC - 0xBA];
    s16 f2CC;
    u8 pad2CE[0x350 - 0x2CE];
    void *f350;
    u8 pad354[0x37C - 0x354];
    f32 f37C;
    u8 pad380[0x3C0 - 0x380];
    s32 f3C0;
    s32 f3C4;
    f32 f3C8;
    f32 f3CC;
    s32 f3D0;
    s32 f3D4;
    s32 f3D8;
    s16 f3DC;
    void *f3E0;
    void *f3E4;
    VObj_800E7884 sub;
    s32 f404;
    s32 f408;
    s32 f40C;
    f32 f410;
    f32 f414;
    f32 f418;
    f32 f41C;
    f32 f420;
    s32 f424;
    s32 f428;
};


s32 get_main_phase();
void queue_destruction__7TObjectFv(void *arg0);
}
void enemy_turn_and_move_on_ground(u8 *arg0, s32 arg1, f32 farg0);

extern "C" {
s32 enemy_validate_retained_target(void *, int);
s32 update_linked_position__12TObjEneDD_STFf(f32);
int select_and_apply_target__12TObjEneDD_STFf(void*);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 is_main_phase_15__9TObjEneDDFv();
s32 reset_hp__9TObjEneDDFPUcPUcPUc(void *, int, int, int);
void get_camera_ctrl__9TObjEneDDFv(s32, s32);
s32 initialize_enemy_state__9TObjEneDDFl(void *, int);
void TObjEneDD__sub_800BA438(s32 arg0, u8 *arg1);
void init_model__9TObjEneDDFP13CollisionBodyl(void *, void *, s32);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
s32 TBoss3Volopt__sub_800D8D88(void *, f32);
void update_mirage__17TObjEneMe3ShinowaFv(void* p);
void vfunc_116__17TObjEneMe3ShinowaFl(void);
void vfunc_114__17TObjEneMe3ShinowaFl(void);
void TObjEneMe3ShinowaMirage__sub_800E4FE8(u8 *arg0, s32 arg1);
void TObjEneMe3ShinowaMirage__sub_800E50D8(u8 *arg0, s32 arg1);
void TObjEneMe3ShinowaMirage__sub_800E5220(void *arg0, s32 arg1);
void TObjEneMe3ShinowaMirage__sub_800E54E8(void *, s32);
void TObjEneMe3ShinowaMirage__sub_800E66FC(u8 *, s32);
void TObjEneMe3ShinowaMirage__sub_800E69F0(u8 *arg0, s32 arg1);
void action__17TObjEneMe3ShinowaFl(u8 *arg0, s32 arg1);
void dispatch_action__23TObjEneMe3ShinowaMirageFPvUii(Obj_800E6DD8 *arg0, u32 arg1, s32 arg2);
void TObjEneMe3ShinowaMirage__sub_800E6F0C(Obj_800E6F0C *self);
int vfunc_104__17TObjEneMe3ShinowaFf(void* p);
void vfunc_89__17TObjEneMe3ShinowaFv(void *arg0);
void vfunc_111__17TObjEneMe3ShinowaFv(void);
void TObjEneMe3Shinowa__sub_800E7268(u8 *arg0);
s32 check_in_range__23TObjEneMe3ShinowaMirageFPv(void *arg0);
u8 check_body_collision_at__17TObjEneMe3ShinowaFlf(Obj_800E750C *arg0, s32 arg1, f32 farg0);
void vfunc_88__17TObjEneMe3ShinowaFv(u8 *arg0);
void vfunc_61__17TObjEneMe3ShinowaFv(void);
void vfunc_28__17TObjEneMe3ShinowaFv(void);
void * __dt__17TObjEneMe3ShinowaFv(void *arg0, s16 arg1);
s32 get_room__8TObjBaseFv(int);
s32 defer_render__7TObjectFv(void *);
void __dl__7TObjectFPv(void *);
s32 create__10TTecDebandFlll(void *, void *, s32);
void compose_motion_node_matrix(void *arg0);
s32 translate_matrix(int, f32, f32, f32);

extern BmlResource *TObjEneMe3ShinowaMirage__data_805D5298;
extern TUnk_8048FA00 *TObjEneMe3ShinowaMirage__data_805D52A0;
extern SampledMotionPoints *TObjEneMe3ShinowaMirage__data_805D52A4;
extern SampledMotionPoints *TObjEneMe3ShinowaMirage__data_805D52A8;
extern s32 __vt__17TObjEneMe3Shinowa[];
extern u8 shinowa_mirage_breakup_params[];
extern Vec lbl_8043CF94;

// Per-variant parameter tables fetched from TLobby (TObjEneMe3Stelth names the same four
// base/attack/resistance/behavior_params_by_variant).
Vec TObjEneMe3ShinowaMirage__data_80500FC0;
__declspec(section ".data") s32 lbl_80500FCC[2];
__declspec(section ".data") s32 lbl_80500FD4[2];
__declspec(section ".data") s32 lbl_80500FDC[2];
__declspec(section ".data") Info_800E6F0C *TObjEneMe3ShinowaMirage__mirage_info_table[2];
// Copy of the model's texture list (the mirage swaps the first three texture addresses).
__declspec(section ".data") NJS_TEXLIST lbl_80500FEC;
Vec lbl_80500FF4;
s32 *lbl_80501000[4];
extern void *TObjEneMe3Shinowa__name;
extern s32 TObjEneMe3ShinowaMirage__render_node_index;
extern s32 saved_model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
extern s32 model_render_flags;

#define PAD_VIRT virtual void CAT(pv, __LINE__)();
#define PADV virtual void CAT(pv, __LINE__)();
#define PADV4 virtual void CAT(pa, __LINE__)(); virtual void CAT(pb, __LINE__)(); virtual void CAT(pc, __LINE__)(); virtual void CAT(pd, __LINE__)();
extern "C" {
void vfunc_6__8TObjBaseFPsl();
}
extern "C" {
void vfunc_103__9TObjEneDDFPUc();
}
extern "C" {
void vfunc_79__9TObjEneDDFPl();
}
extern "C" {
void vfunc_84__9TObjEneDDFv();
}
extern "C" {
void vfunc_85__9TObjEneDDFv();
}
extern "C" {
void vfunc_86__9TObjEneDDFv();
}
extern "C" {
void vfunc_90__9TObjEneDDFv();
}
extern "C" {
void vfunc_91__9TObjEneDDFv();
}
extern "C" {
void vfunc_92__9TObjEneDDFv();
}
extern "C" {
void vfunc_93__9TObjEneDDFv();
}
extern "C" {
void vfunc_94__9TObjEneDDFv();
}
extern "C" {
void vfunc_95__9TObjEneDDFv();
}
extern "C" {
void vfunc_96__9TObjEneDDFv();
}
extern "C" {
void vfunc_97__9TObjEneDDFv();
}
extern "C" {
void vfunc_98__9TObjEneDDFv();
}
extern "C" {
void vfunc_99__9TObjEneDDFv();
}
extern "C" {
void vfunc_100__9TObjEneDDFv();
}
extern "C" {
void vfunc_101__9TObjEneDDFPUc();
}
extern "C" {
void vfunc_102__9TObjEneDDFv();
}
extern "C" {
void vfunc_83__12TObjEneDD_STFv();
}
extern "C" {
void vfunc_118__17TObjEneMe3ShinowaFv(TObjEneMe3Shinowa *self);
}
extern "C" {
void vfunc_105__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void can_hit_same_target__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void vfunc_107__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void update_player_state_default__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void update_effect__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void dispatch_if_active__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void apply_effect_pair__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void TObjEneMe3ShinowaMirage__vt113(u8 *arg0, s32 arg1);
}
extern "C" {
void vfunc_62__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void vfunc_63__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void vfunc_29__9TObjCharaFv();
}
extern "C" {
void recalc_stats__9TObjCharaFv();
}
extern "C" {
void consume_timer_field__9TObjCharaFl();
}
extern "C" {
void vfunc_67__9TObjCharaFf();
}
extern "C" {
void vfunc_66__9TObjCharaFv();
}
extern "C" {
void get_anim_node_position__9TObjCharaFlP3Vec();
}
extern "C" {
void vfunc_60__9TObjCharaFv();
}
extern "C" {
void vfunc_59__9TObjCharaFv();
}
extern "C" {
void vfunc_58__9TObjCharaFv();
}
extern "C" {
void apply_slow_status__9TObjCharaFv();
}
extern "C" {
void update_shock_clock__9TObjCharaFv();
}
extern "C" {
void vfunc_43__9TObjCharaFv();
}
extern "C" {
void vfunc_18__9TObjCharaFPUc();
}
extern "C" {
void interact__14TObjCollidableFl();
}
extern "C" {
void vfunc_74__9TObjEnemyFl();
}
extern "C" {
void apply_hit_message_flags__9TObjEnemyFPv();
}
extern "C" {
void *__dt__23TObjEneMe3ShinowaMirageFv(void *arg0, s16 arg1);
}
extern "C" {
void add_actor_exp__9TObjCharaFl();
}
extern "C" {
void apply_action_hold_status__9TObjCharaFf();
}
extern "C" {
void apply_anti_technique__9TObjCharaFl();
}
extern "C" {
void apply_attack_stat_status__9TObjCharaFPv();
}
extern "C" {
void apply_confusion_status__9TObjCharaFv();
}
extern "C" {
void apply_knockback_from_attacker__9TObjCharaFPUcf();
}
extern "C" {
void apply_movement_ailment__9TObjCharaFl();
}
extern "C" {
void apply_object_set_data__8TObjBaseFPv();
}
extern "C" {
void apply_paralysis__9TObjCharaFv();
}
extern "C" {
void apply_poison_status__9TObjCharaFv();
}
extern "C" {
void apply_set_data__9TObjEnemyFPv();
}
extern "C" {
void apply_shock_status__9TObjCharaFv();
}
extern "C" {
void apply_switch_attack__9TObjCharaFv();
}
extern "C" {
void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
}
extern "C" {
void classify_actor_view_detail__8TObjBaseFfff();
}
extern "C" {
void clear_all_status_effects__9TObjCharaFv();
}
extern "C" {
void clear_harmful_statuses__9TObjCharaFv();
}
extern "C" {
void cure_paralysis__9TObjCharaFv();
}
extern "C" {
void cure_poison_ailment__9TObjCharaFv();
}
extern "C" {
void enemy_spawn_jellen_effect__9TObjCharaFv();
}
extern "C" {
void enemy_spawn_zalure_effect__9TObjCharaFv();
}
extern "C" {
void vfunc_78__9TObjCharaFl();
}
extern "C" {
void vfunc_77__9TObjCharaFv();
}
extern "C" {
void vfunc_76__9TObjCharaFf();
}
extern "C" {
void vfunc_75__9TObjCharaFf();
}
extern "C" {
void clear_lobby_object_state__9TObjEnemyFv();
}
extern "C" {
void get_center__9TObjCharaFv();
}
extern "C" {
void get_actor_level_index__9TObjCharaFv();
}
extern "C" {
void get_name__9TObjEnemyFv();
}
extern "C" {
void get_pos__9TObjCharaFl();
}
extern "C" {
void is_actor_cadence_frame__9TObjCharaFl();
}
extern "C" {
void is_target_in_attack_range__9TObjCharaFv();
}
extern "C" {
extern u8 lbl_8043CE3C[];
}
extern "C" {
extern u8 lbl_8043CE4C[];
}
extern "C" {
extern u8 lbl_8043CE60[];
}
extern "C" {
extern u8 lbl_8043CE78[];
}
extern "C" {
extern u8 lbl_8043CE90[];
}
extern "C" {
extern u8 lbl_8043CEA4[];
}
extern "C" {
extern u8 lbl_8043CEBC[];
}
extern "C" {
extern u8 lbl_8043CED0[];
}
extern "C" {
extern u8 lbl_8043CEE8[];
}
extern "C" {
extern u8 lbl_8043CF00[];
}
extern "C" {
extern u8 lbl_8043CF14[];
}
extern "C" {
extern u8 lbl_8043CF28[];
}
extern "C" {
void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
}
extern "C" {
void receive_physical_attack__9TObjCharaFPvf();
}
extern "C" {
void receive_weapon_special_attack__9TObjCharaFPvPv();
void apply_defense_stat_status__9TObjCharaFPv();
}
extern "C" {
void render__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void render_shadows__9TObjEnemyFv(u8 *arg0);
}
extern "C" {
void reset_motion_fields__9TObjCharaFv();
}
extern "C" {
void reset_pose__9TObjCharaFv();
}
extern "C" {
void roll_physical_accuracy__9TObjCharaFPvlf();
}
extern "C" {
void run_task__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void select_melee_contact_body__9TObjCharaFPvf();
}
extern "C" {
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
}
extern "C" {
void try_start_action__9TObjCharaFll();
}
extern "C" {
void update_action_hold_status__9TObjCharaFv();
}
extern "C" {
void update_actor_ground_y__9TObjCharaFv();
}
extern "C" {
s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
}
extern "C" {
void update_flag30_timer__9TObjCharaFv();
}
extern "C" {
void update_movement_status__9TObjCharaFv();
}
extern "C" {
void update_object_view_visibility__8TObjBaseFff();
}
extern "C" {
void update_poison_status__9TObjCharaFv();
}
extern void *bm_ene_me3_shinowa_model_names[2];
extern void *bm_ene_me3_shinowa_motion_names[11];
void *TObjEneMe3ShinowaMirage__init_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *shinowa_mirage_model_init_data[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41000000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
__declspec(section ".data") void *bm_ene_me3_shinowa_model_names[2] = {
    (void *)&lbl_8043CE3C, (void *)0x0,
};
void *bm_ene_me3_shinowa_motion_names[11] = {
    (void *)&lbl_8043CE4C, (void *)&lbl_8043CE60, (void *)&lbl_8043CE78, (void *)&lbl_8043CE90,
    (void *)&lbl_8043CEA4, (void *)&lbl_8043CEBC, (void *)&lbl_8043CED0, (void *)&lbl_8043CEE8,
    (void *)&lbl_8043CF00, (void *)&lbl_8043CF14, (void *)0x0,
};
void *shinowa_mirage_resource_descriptor[4] = {
    (void *)&lbl_8043CF28, (void *)&bm_ene_me3_shinowa_model_names, (void *)&bm_ene_me3_shinowa_motion_names, (void *)0x1000a,
};
TObjMotionAction shinowa_mirage_motion_param_table[11] = {
    {1, 0, 7, 0.5f, ACTION_NO_BLEND_IN},
    {3, 0, 0, 1.5f, ACTION_NO_BLEND_IN},
    {3, 0, 1, 0.8f, 0},
    {3, 0, 2, 0.6f, 0},
    {3, 0, 3, 0.6f, 0},
    {3, 0, 4, 0.7f, 0},
    {3, 0, 5, 1.0f, 0},
    {3, 0, 6, 0.7f, 0},
    {1, 0, 8, 0.5f, 0},
    {1, 0, 9, 0.5f, 0},
    {3, 0, 6, 0.7f, ACTION_NO_BLEND_IN},
};
void *__vt__23TObjEneMe3ShinowaMirage[119] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__23TObjEneMe3ShinowaMirageFv, (void *)&run_task__23TObjEneMe3ShinowaMirageFv,
    (void *)&render__23TObjEneMe3ShinowaMirageFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&vfunc_28__17TObjEneMe3ShinowaFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__9TObjCharaFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__9TObjCharaFv, (void *)&vfunc_59__9TObjCharaFv,
    (void *)&vfunc_60__9TObjCharaFv, (void *)&vfunc_61__17TObjEneMe3ShinowaFv, (void *)&vfunc_62__23TObjEneMe3ShinowaMirageFv, (void *)&vfunc_63__23TObjEneMe3ShinowaMirageFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFf, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEneDDFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&vfunc_84__9TObjEneDDFv, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&dispatch_action__23TObjEneMe3ShinowaMirageFPvUii,
    (void *)&vfunc_88__17TObjEneMe3ShinowaFv, (void *)&vfunc_89__17TObjEneMe3ShinowaFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&vfunc_104__17TObjEneMe3ShinowaFf, (void *)&vfunc_105__23TObjEneMe3ShinowaMirageFv, (void *)&can_hit_same_target__23TObjEneMe3ShinowaMirageFv, (void *)&vfunc_107__23TObjEneMe3ShinowaMirageFv,
    (void *)&update_player_state_default__23TObjEneMe3ShinowaMirageFv, (void *)&update_effect__23TObjEneMe3ShinowaMirageFv, (void *)&dispatch_if_active__23TObjEneMe3ShinowaMirageFv, (void *)&vfunc_111__17TObjEneMe3ShinowaFv,
    (void *)&apply_effect_pair__23TObjEneMe3ShinowaMirageFv, (void *)&action__17TObjEneMe3ShinowaFl, (void *)&vfunc_114__17TObjEneMe3ShinowaFl, (void *)&TObjEneMe3ShinowaMirage__vt113,
    (void *)&vfunc_116__17TObjEneMe3ShinowaFl, (void *)&update_mirage__17TObjEneMe3ShinowaFv, (void *)&vfunc_118__17TObjEneMe3ShinowaFv,
};

// Debug viewer: the mirage and gold-texture switches, then the model posed in
// action parameters[2] at frame parameters[3] (unposed when mode is not 0).
void TObjEneMe3Shinowa::vfunc_118() {
    s32 gold;
    NJS_TEXNAME *textures;
    u32 saved_texaddr[3];
    s32 i;
    if (this->get_target_info() != 0) {
        if (this->sub_800E701C() != 0) {
            debug_printf_at(pack_debug_text_position(0, 0), "MIRAGE:ENABLE");
        } else {
            debug_printf_at(pack_debug_text_position(0, 0), "MIRAGE:DISABLE");
        }
        if (this->sub_800E6FE0() != 0) {
            debug_printf_at(pack_debug_text_position(0, 1), "TEX:GOLD");
        } else {
            debug_printf_at(pack_debug_text_position(0, 1), "TEX:NORMAL");
        }
    }
    gold = this->sub_800E6FE0();
    if (this->update_object_view_visibility(400.0f, 15.0f) != 0) {
        TObjFish::set_global_param(this->texlist);
        TObjPlayer::toggle_particle_effect();
        if (gold != 0) {
            textures = ((NJS_TEXLIST *)this->texlist)->textures;
            for (i = 0; i < 3; i++) {
                saved_texaddr[i] = textures[i + 3].texaddr;
            }
            for (i = 0; i < 3; i++) {
                textures[i + 3].texaddr = textures[i].texaddr;
            }
        }
        push_matrix();
        post_translate_matrix(&this->position);
        rotate_matrix_y(0, this->rotation_y);
        scale_matrix(0, 1.0f, 1.0f,
                     1.0f);
        for (i = 0; i < 3; i++) {
            if (lbl_80501000[i] != NULL) {
                *lbl_80501000[i] = 0xB000FFB0;
            }
        }
        if (this->mode == 0) {
            s32 action = (s32)this->parameters[2];
            AnimationMotion *motion;
            f32 at_frame;
            if (action < 0) {
                action = 0;
            } else if (action >= 11) {
                action = 10;
            }
            motion = this->motion_list[this->action_table[action].motion].motion;
            at_frame = this->parameters[3];
            if (at_frame < 0.0f) {
                at_frame = 0.0f;
            } else if (at_frame > (f32)(motion->frameCount - 1)) {
                at_frame = (f32)(motion->frameCount - 1);
            }
            set_motion_packed_rotation();
            draw_model_motion(this->model, motion, at_frame);
            clear_motion_packed_rotation();
            this->current_motion = (NJS_MOTION *)motion;
            this->frame = at_frame;
            print_float_padded(pack_debug_text_position(0, 4), 5, this->get_node_world_y());
        } else {
            model_render_flags &= ~0x400;
            draw_chunk_object(this->model);
        }
        pop_matrix();
        if (gold != 0) {
            textures = ((NJS_TEXLIST *)this->texlist)->textures;
            for (i = 0; i < 3; i++) {
                textures[i + 3].texaddr = saved_texaddr[i];
            }
        }
        TParticleCtrl::end_effect_render();
    }
}

void TObjEneMe3Shinowa::update_mirage() { if (get_target_info() != 0) { ((int (*)(void*))fn_800E762C)(this); sub_800E6F64(); } }

void TObjEneMe3ShinowaMirage::draw_model() {
    s32 var_r31;
    s32 var_r30;
    s32 i;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->vfunc_118();
        return;
    }
    sub_800E6FE0__17TObjEneMe3ShinowaFv(((u8 *)this));
    if (*(s32 *)((s8 *)((u8 *)this) + 0x3C4) & 2) {
        var_r31 = 0;
    } else if (is_main_phase_15__9TObjEneDDFv() != 0) {
        var_r31 = ((VObj_18_82072c *)(this))->m9(lbl_805D9E88, lbl_805D9E84, 15.0f);
    } else if (((VObj_18_82072c *)(this))->m8(400.0f, 15.0f) != 0) {
        var_r31 = 1;
    } else {
        var_r31 = 0;
    }
    if (var_r31 != 0) {
        this->update_player_state_default();
        TObjFish::set_global_param(this->texlist);
        this->update_secondary_light();
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        for (i = 0; i < 3; i++) {
            if (lbl_80501000[i] != NULL) {
                *lbl_80501000[i] = *(s32 *)((s8 *)((u8 *)this) + 0x3D0);
            }
        }
        var_r30 = 1;
        if ((this->update_effect() != 0) && (defer_render__7TObjectFv((void *)this) != 0)) {
            var_r30 = 0;
        }
        if (var_r30 != 0) {
            push_matrix();
            post_translate_matrix((void *) ((u8 *)this + 0x38));
            translate_matrix(0, 0.0f, (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x3CC)), 0.0f);
            rotate_matrix_y(0, this->rotation_y);
            TObjEneMe3ShinowaMirage__render_node_index = 0;
            set_chunk_model_node_callback((s32)((void *) (TObjEneMe3ShinowaMirage::advance_camera_ctrl_step)));
            if (var_r31 == 1) {
                ((TObjMotion *)((u8 *)this))->draw();
            } else {
                this->draw_motion_model();
            }
            set_chunk_model_node_callback(NULL);
            pop_matrix();
        }
        this->dispatch_if_active();
        model_render_flags = saved_model_render_flags;
        this->update_primary_light();
        VecCopy((Vec *)((u8 *)this + 0x2FC), &lbl_80500FF4);
    } else if ((get_main_phase() == 0xF) || (is_split_screen() == 0)) {
        VecCopy((Vec *)((u8 *)this + 0x2FC), (const Vec *)((u8 *)this + 0x38));
    }
    TParticleCtrl::end_effect_render();
}

void TObjEneMe3ShinowaMirage::advance_camera_ctrl_step() {
    if ((s32) TObjEneMe3ShinowaMirage__render_node_index == 1) {
        get_camera_ctrl__9TObjEneDDFv((s32) &TObjEneMe3ShinowaMirage__data_80500FC0, (s32) &lbl_80500FF4);
    }
    TObjEneMe3ShinowaMirage__render_node_index += 1;
}

void TObjEneMe3Shinowa::vfunc_116(s32) {  }

void TObjEneMe3Shinowa::vfunc_115() {  }

void TObjEneMe3Shinowa::vfunc_114(s32) {  }

#pragma push
#pragma fp_contract on
void TObjEneMe3ShinowaMirage::state_break_apart(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    Vec_800E4DD0 sp14;
    Vec_800E4DD0 sp8;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 4;
        ((TObjEnemy *)arg0)->refresh_and_send_entity_flags();
        this->vfunc_94();
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFFC);
        *(s32 *)((s8 *)arg0 + 0x404) = 0;
        break;
    case 3:
    case 5:
        break;
    case 0:
        switch (*(s32 *)((s8 *)arg0 + 0x404)) {
        case 0:
            advance_animation();
            if ((((TObjMotion *)arg0)->is_passing_frame((f32)13.0f) != 0) || (((TObjMotion *)arg0)->is_passing_frame((f32)(25.0f)) != 0)) {
                play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003AD12)), arg0 + 0x38, 0, 0);
            }
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)arg0 + 0x404) = 1;
                *(s32 *)((s8 *)arg0 + 0x408) = 0;
                sp14.x = 0.0f;
                sp14.y = 10.0f;
                sp14.z = 20.0f;
                ((TObjBoss2Tunnel *)(&sp14))->init_zako(arg0 + 0x38, *(s32 *)((s8 *)arg0 + 0x60));
                TObjPlayer::spawn_effect_f8((s32)&sp14, 0x14);
            }
            break;
        case 1:
            (*(s32 *)((s8 *)arg0 + 0x408))++;
            if (*(s32 *)((s8 *)arg0 + 0x408) >= 0x14) {
                *(s32 *)((s8 *)arg0 + 0x404) = 2;
                *(s32 *)((s8 *)arg0 + 0x3C4) |= 2;
                TBoss3Volopt::create_breakup_mdl((s32)TObjEneMe3ShinowaMirage__data_805D52A0, (s32)shinowa_mirage_breakup_params, (s32)(*(s32 *)((s8 *)arg0 + 0x24)), (s32)(arg0 + 0x38), (s32)(*(s32 *)((s8 *)arg0 + 0x60)));
                VecCopy((Vec *)&sp8, (const Vec *)(arg0 + 0x38));
                sp8.x += 20.0f * sin_table_lookup(*(s32 *)((s8 *)arg0 + 0x60));
                sp8.z += 20.0f * cos_table_lookup(*(s32 *)((s8 *)arg0 + 0x60));
                ((TObjPlayer *)(&sp8))->trigger_dell_biter_events();
                play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003AD16)), arg0 + 0x38, 0, 0);
            }
            this->vfunc_102();
            break;
        case 2:
            queue_destruction__7TObjectFv(arg0);
            break;
        }
        break;
    }
}
#pragma pop

void TObjEneMe3ShinowaMirage__sub_800E4FE8(u8 *ene_dd_st, s32 arg1) {
    Vec_800E4FE8 v;
    f32 c;
    switch (arg1) {
    case 4:
        ((TObjEneDD_ST *)ene_dd_st)->requested_action = 3;
        ((TObjMotion *)ene_dd_st)->advance_animation();
        ((TObjEneDD_ST *)ene_dd_st)->set_active();
        break;
    case 3:
        if (((TObjEneDD *)ene_dd_st)->get_flag_b4() != 0) {
            transition_enemy_state__9TObjEneDDFl(ene_dd_st, *(s32 *)((s8 *)ene_dd_st + 0x378));
        }
        break;
    case 0:
        ((TObjMotion *)ene_dd_st)->advance_animation();
        VecCopy((Vec *)&v, (const Vec *)(ene_dd_st + 0x308));
        c = normalize_vector_xz((Vec *)(&v));
        ((TObjEneDD *)ene_dd_st)->move_clamped_on_ground(v.x, v.z, c);
        *(f32 *)((s8 *)ene_dd_st + 0x308) *= 0.8f;
        ((TObjEneDD_ST *)ene_dd_st)->m_310 *= 0.8f;
        ((TObjEneDD *)ene_dd_st)->vfunc_89();
        break;
    case 5:
        ((TObjEneDD *)ene_dd_st)->clear_attack_receipts();
        ((TObjEneDD *)ene_dd_st)->clear_field_388();
        break;
    }
}

void TObjEneMe3ShinowaMirage__sub_800E50D8(u8 *ene_dd, s32 arg1) {
  s32 temp_r3;
  switch (arg1)
  {
    return;
    case 4:
      ((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_B8 = 7;
      ((TObjEneDD *)ene_dd)->set_field_378(4);
      (((TObjEneDD *)(ene_dd))->vfunc_95());
      ((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_3C4 = (s32) (((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_3C4 & 0xFFFFFFFC);
      temp_r3 = ((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_3C4;
      if (temp_r3 & 0x80000)
    {
      ((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_3C4 = (s32) (temp_r3 & 0xFFF7FFFF);
      ((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_404 = 2;
      return;
    }
      (((VObj_14_763762 *)(((u8 *) ene_dd) + 1000))->m2());
      ((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_404 = 1;
      return;
    case 3:
      if (((s32) ((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_404) == 2)
    {
      transition_enemy_state__9TObjEneDDFl(ene_dd, 0);
    }
    case 5:
      return;
    case 0:
      ((TObjMotion *)ene_dd)->advance_animation();
      switch (((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_404)
    {
      case 0:
        if (((TObjEneDD *)ene_dd)->get_flag_b4() != 0)
      {
        ((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_404 = 1;
      }
        break;
      case 1:
        if ((((VObj_14_763762 *)(((u8 *) ene_dd) + 1000))->m4()) != 0)
      {
        ((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_404 = 2;
      }
        break;
    }
      (((TObjEneDD *)(ene_dd))->vfunc_102());
      break;
  }
}

void TObjEneMe3ShinowaMirage__sub_800E5220(void *ene_dd, s32 arg1) {
    s32 temp_r4;

    switch (arg1) {
    case 4:
        ((TObjEneDD *)ene_dd)->requested_action = 8;
        ((TObjEneDD *)ene_dd)->set_field_378(0xB);
        *(s32 *)((s8 *)ene_dd + 0x3C4) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3C4) & 0xFFFFFFFC);
        ((TObjEneDD *)ene_dd)->vfunc_95();
        *(s32 *)((s8 *)ene_dd + 0x3D8) = 0;
        *(s32 *)((s8 *)ene_dd + 0x404) = 0;
        return;
    case 3:
        if (update_linked_position__12TObjEneDD_STFf(200.0f) != 0) {
            transition_enemy_state__9TObjEneDDFl(ene_dd, 4);
        } else if ((s32) *(s32 *)((s8 *)ene_dd + 0x404) >= 0x5A) {
            transition_enemy_state__9TObjEneDDFl(ene_dd, 9);
        }
        return;
    case 0:
        temp_r4 = *(s32 *)((s8 *)ene_dd + 0x404);
        *(s32 *)((s8 *)ene_dd + 0x404) = (temp_r4 + 1);
        ((TObjMotion *)ene_dd)->advance_animation();
        ((TObjEneDD *)ene_dd)->vfunc_102();
        break;
    case 5:
        break;
    }
}

void TObjEneMe3ShinowaMirage::state_cast_support(s32 arg1) {
#define arg0 ((u8 *)this)
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 7;
        ((TObjEneDD *)arg0)->set_field_378(0xA);
        ((VObj_18_800E530C *)arg0)->m94();
        *(s32 *)((s8 *)arg0 + 0x3C4) &= ~3;
        *(s32 *)((s8 *)arg0 + 0x404) = 0;
        *(s32 *)((s8 *)arg0 + 0x408) = 0;
        break;
    case 3:
        if (*(s32 *)((s8 *)arg0 + 0x408) > TObjEneMe3ShinowaMirage__mirage_info_table[*(s32 *)((s8 *)arg0 + 0x3C0)]->frame_1C) {
            transition_enemy_state__9TObjEneDDFl(arg0, 4);
        }
        break;
    case 5:
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        switch (*(s32 *)((s8 *)arg0 + 0x404)) {
        case 0:
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                TObjEneMe3ShinowaMirage__sub_800E6F0C((Obj_800E6F0C *)arg0);
                if (TObjEneDD::check_v2_mode() != 0) {
                    *(s32 *)((s8 *)arg0 + 0x404) = 2;
                } else {
                    *(s32 *)((s8 *)arg0 + 0x404) = 1;
                }
                *(s32 *)((s8 *)arg0 + 0x408) = 0;
            }
            break;
        case 1:
            (*(s32 *)((s8 *)arg0 + 0x408))++;
            break;
        case 2:
            (*(s32 *)((s8 *)arg0 + 0x408))++;
            if (*(s32 *)((s8 *)arg0 + 0x408) == 5) {
                TTecSifta::create((void *)arg0, arg0 + 0x38, (void *)(TObjEneDD::clamp_frame_index(TObjEneMe3ShinowaMirage__mirage_info_table[*(s32 *)((s8 *)arg0 + 0x3C0)]->frame)));
            } else if (*(s32 *)((s8 *)arg0 + 0x408) == 0xA) {
                create__10TTecDebandFlll(arg0, arg0 + 0x38, TObjEneDD::clamp_frame_index(TObjEneMe3ShinowaMirage__mirage_info_table[*(s32 *)((s8 *)arg0 + 0x3C0)]->frame));
                *(s32 *)((s8 *)arg0 + 0x404) = 1;
                *(s32 *)((s8 *)arg0 + 0x408) = 0;
            }
            break;
        }
        ((VObj_18_800E530C *)arg0)->m100();
        break;
    }
}
#undef arg0

#define arg0 ((u8 *)arg0_)
#define F(t, o) (*(t *)(arg0 + (o)))
#define VO ((VObj_18_a1ce10 *)(arg0))

#pragma push
#pragma opt_common_subs off
void TObjEneMe3ShinowaMirage__sub_800E54E8(void *arg0_, s32 arg1) {
    Vec_800E4FE8 savePos;
    Vec_800E4FE8 save2FC;
    Vec_800E4FE8 dest;
    s32 rot[3];
    f32 v;
    u8 *home = arg0 + 0x418;

    switch (arg1) {
    case 4: {
        F(s32, 0x3C4) &= ~3;
        VO->m94();
        VO->m92();
        F(s32, 0x404) = 0;
        F(s32, 0x408) = 0;
        F(f32, 0x410) = 1.0f;
        F(f32, 0x37C) = 30.0f;
        F(s32, 0x40C) = ((F(s32, 0x3D4) - (s32)floor_to_float(2.5f)) * 0x3333) / 40;
        VecCopy((Vec *)home, (const Vec *)(arg0 + 0x38));
        F(void *, 0x424) = 0;
        F(void *, 0x428) = 0;
        ((TObjEneDD_ST *)arg0)->set_active();
        break;
    }
    case 3: {
        if (F(s32, 0x404) >= 40) {
            TObjEneMe3Shinowa__sub_800E7268(arg0);
            s32 r = collect_target_candidates__9TObjEneDDFlf(arg0, 40000.0f);
            if (r > 0) {
                enemy_set_target_id(arg0, enemy_target_candidate_table[r - 1].id);
                transition_enemy_state__9TObjEneDDFl(arg0, 4);
            } else {
                transition_enemy_state__9TObjEneDDFl(arg0, 11);
            }
        }
        break;
    }
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        F(s32, 0x404)++;
        if (transform_relative_position__9TObjEneDDFPv(arg0, F(void *, 0x390)) != 0) {
            if ((s16)get_room__8TObjBaseFv((s32)arg0) == (s16)get_room__8TObjBaseFv(F(s32, 0x390))) {
                ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            }
        }
        ((TObjEneDD *)arg0)->update_velocity();
        rotate_xz_pair_by_angle((f32 *)(arg0 + 0x3A0), (f32 *)(arg0 + 0x3A8), (s32)(F(s32, 0x40C)));
        v = F(f32, 0x3AC);
        if (v > 80.0f) {
            v -= 3.0f;
            if (v < 80.0f) {
                v = 80.0f;
            }
        } else if (v < 80.0f) {
            v += 3.0f;
            if (v > 80.0f) {
                v = 80.0f;
            }
        }
        VecCopy((Vec *)&savePos, (const Vec *)(arg0 + 0x38));
        VecCopy((Vec *)&save2FC, (const Vec *)(arg0 + 0x2FC));
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg0 + 0x394));
        VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
        F(f32, 0x300) += 20.0f;
        v *= F(f32, 0x410);
        calc_wall_clamped_destination(arg0, &dest, -F(f32, 0x3A0), -F(f32, 0x3A8), v);
        if (VO->m16(&dest) == 0) {
            F(f32, 0x410) *= 0.8f;
            VecCopy((Vec *)(arg0 + 0x38), (const Vec *)&savePos);
            VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)&save2FC);
        } else {
            F(f32, 0x410) = 1.0f;
            VecCopy((Vec *)(arg0 + 0x38), (const Vec *)&savePos);
            VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)&save2FC);
            subtract_vector(&dest, arg0 + 0x38);
            f32 len = normalize_vector_xz((Vec *)(&dest));
            ((TObjEneDD *)arg0)->move_clamped_on_ground(dest.x, dest.z, len);
        }
        F(s32, 0x60) = (s32)(10430.38043493439 * atan2_float(F(f32, 0x3A0), F(f32, 0x3A8)));
        if (F(s32, 0x40C) != 0) {
            rot[0] = 0;
            if (F(s32, 0x40C) > 0) {
                rot[1] = F(s32, 0x60);
            } else {
                rot[1] = F(s32, 0x60) - 0x8000;
            }
            rot[2] = -0x4000;
            if (F(void *, 0x424) == 0) {
                F(void *, 0x424) = create_particle_emitter(arg0 + 0x38, 0x115);
                if (F(void *, 0x424) != 0) {
                    ((TParticleCtrl *)(F(void *, 0x424)))->enable();
                    ((TParticleCtrl *)(F(void *, 0x424)))->set_flags(2);
                }
            } else {
                ((TParticleCtrl *)(F(void *, 0x424)))->set_direction(rot);
                ((TParticleCtrl *)F(void *, 0x424))->set_position(arg0 + 0x38);
            }
            if (F(void *, 0x428) == 0) {
                F(void *, 0x428) = create_particle_emitter(arg0 + 0x38, 0x116);
                if (F(void *, 0x428) != 0) {
                    ((TParticleCtrl *)(F(void *, 0x428)))->enable();
                    ((TParticleCtrl *)(F(void *, 0x428)))->set_flags(2);
                }
            } else {
                ((TParticleCtrl *)(F(void *, 0x428)))->set_direction(rot);
                ((TParticleCtrl *)F(void *, 0x428))->set_position(arg0 + 0x38);
            }
        }
        VO->m86();
        break;
    case 5:
        VO->m91();
        F(f32, 0x37C) = 10.0f;
        if (F(void *, 0x424) != 0) {
            queue_destruction__7TObjectFv(F(void *, 0x424));
            F(void *, 0x424) = 0;
        }
        if (F(void *, 0x428) != 0) {
            queue_destruction__7TObjectFv(F(void *, 0x428));
            F(void *, 0x428) = 0;
        }
        ((TObjEneDD *)arg0)->clear_field_388();
        break;
    }
}

#pragma pop
#undef arg0
#undef F
#undef VO

void TObjEneMe3ShinowaReal__sub_800E5950(u8 *arg0, s32 arg1) {
    s32 temp_r5;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 2;
        ((TObjEneDD *)arg0)->set_field_378(7);
        ((TObjEneDD *)(arg0))->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x3C4) &= 0xFFFFFFFC;
        *(s32 *)((s8 *)arg0 + 0x3D8) = 0;
        *(s32 *)((s8 *)arg0 + 0x404) = 3;
        if (((VObj_18_dc3190 *)(arg0))->m102(200.0f) != 0) {
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            ((TObjEneDD *)arg0)->update_velocity();
            *(s32 *)((s8 *)arg0 + 0x40C) = (s32) (10430.38043493439 * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 0x3A0)), (f32) (*(f32 *)((s8 *)arg0 + 0x3A8))));
            if (((s32 (*)(void *, s32, f32))check_body_collision_at__17TObjEneMe3ShinowaFlf)(arg0, (int) (*(s32 *)((s8 *)arg0 + 0x40C) + 0x8000), 80.0f) == 0) {
                *(f32 *)((s8 *)arg0 + 0x3A0) *= -1.0f;
                *(f32 *)((s8 *)arg0 + 0x3A8) *= -1.0f;
                *(s32 *)((s8 *)arg0 + 0x404) = 0;
                *(f32 *)((s8 *)arg0 + 0x410) = 7.111111f;
            }
        }
        ((TObjEneDD_ST *)arg0)->set_active();
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x404) == 3) {
            if (((s32 (*)(void))sub_800E6FE0__17TObjEneMe3ShinowaFv)() != 0) {
                transition_enemy_state__9TObjEneDDFl(arg0, 0xA);
            } else if ((*(s32 *)((s8 *)arg0 + 0x3C4) & 0x20000) || (((TObjEneMe3Shinowa *)arg0)->sub_800E701C() == 0)) {
                *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFCFFFF);
                if ((TObjEneDD::check_v2_mode() != 0) && (((TObjEneMe3Shinowa *)arg0)->sub_800E701C() == 0)) {
                    transition_enemy_state__9TObjEneDDFl(arg0, 0x10);
                } else {
                    transition_enemy_state__9TObjEneDDFl(arg0, 4);
                }
            } else {
                *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) | 0x20000);
                transition_enemy_state__9TObjEneDDFl(arg0, 0xE);
            }
        }
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        switch (*(s32 *)((s8 *)arg0 + 0x404)) {
        case 0:
            *(s32 *)((s8 *)arg0 + 0x60) = approach_angle_limited((int) (*(s32 *)((s8 *)arg0 + 0x60)), (int) (*(s32 *)((s8 *)arg0 + 0x40C)), 0x31C7);
            if ((*(f32 *)((s8 *)arg0 + 0xC0) + *(f32 *)((s8 *)arg0 + 0xC8)) >= 15.0f) {
                *(s32 *)((s8 *)arg0 + 0x404) = 1;
                ((TObjEneDD *)(arg0))->vfunc_91();
                play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003AD11)), arg0 + 0x38, 0, 0);
            }
            ((TObjEneDD *)(arg0))->vfunc_102();
            ((TObjEneDD *)(arg0))->vfunc_89();
            return;
        case 1:
            if ((*(f32 *)((s8 *)arg0 + 0xC0) + *(f32 *)((s8 *)arg0 + 0xC8)) >= 24.0f) {
                *(s32 *)((s8 *)arg0 + 0x404) = 2;
                ((TObjEneDD *)(arg0))->vfunc_92();
                play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003AD12)), arg0 + 0x38, 0, 0);
                spawn_particle_effect(arg0 + 0x38, 0xF3);
            }
            ((TObjEneDD *)arg0)->move_clamped_on_ground((f32) (*(f32 *)((s8 *)arg0 + 0x3A0)), (f32) (*(f32 *)((s8 *)arg0 + 0x3A8)), (f32) (*(f32 *)((s8 *)arg0 + 0x410)));
            ((TObjEneDD *)(arg0))->vfunc_88();
            return;
        case 2:
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)arg0 + 0x404) = 3;
            }
            ((TObjEneDD *)(arg0))->vfunc_102();
            ((TObjEneDD *)(arg0))->vfunc_89();
            return;
        }
        break;
    case 5:
        ((TObjEneDD *)(arg0))->vfunc_92();
        ((TObjEneDD *)arg0)->clear_field_388();
        break;
    }
}

void TObjEneMe3ShinowaMirage__sub_800E5CE4(u8 *ene_epsilon, s32 arg1) {
    s32 var_r4;
    Info_800E5CE4 *info;
    switch (arg1) {
    case 4:
        ((TObjEneEpsilon *)ene_epsilon)->requested_action = 6;
        ((TObjEneDD *)ene_epsilon)->set_field_378(6);
        ((TObjEneEpsilon *)(ene_epsilon))->vfunc_96();
        *(s32 *)((s8 *)ene_epsilon + 0x3C4) = (s32) (*(s32 *)((s8 *)ene_epsilon + 0x3C4) & 0xFFFFFFFC);
        *(s32 *)((s8 *)ene_epsilon + 0x3C4) = (s32) (*(s32 *)((s8 *)ene_epsilon + 0x3C4) | 0x10000);
        *(s32 *)((s8 *)ene_epsilon + 0x404) = 0;
        *(s32 *)((s8 *)ene_epsilon + 0x408) = 0;
        ((TUnk_80494968 *)(*(void **)((s8 *)ene_epsilon + 0x3E0)))->clear_segments();
        ((TUnk_80494968 *)(*(void **)((s8 *)ene_epsilon + 0x3E4)))->clear_segments();
        break;
    case 3:
        if (((TObjEneDD *)ene_epsilon)->get_flag_b4() != 0) {
            ((VObj_18_4f5f2e *)(ene_epsilon))->m105();
        }
        break;
    case 5:
        break;
    case 0:
        ((TObjMotion *)ene_epsilon)->advance_animation();
        switch (*(s32 *)((s8 *)ene_epsilon + 0x404)) {
        case 0:
            ((VObj_18_4f5f2e *)(ene_epsilon))->m103();
            if (((TObjEneEpsilon *)ene_epsilon)->frame < 20.0f) {
                if (((TObjEneEpsilon *)ene_epsilon)->update_death_check() != 0) {
                    ((TObjEneDD_ST *)ene_epsilon)->enemy_copy_target_destination();
                    ((TObjEneDD *)ene_epsilon)->update_velocity();
                    var_r4 = (s32) (10430.38043493439 * atan2_float(((TObjEneEpsilon *)ene_epsilon)->m_3a0, *(f32 *)((s8 *)ene_epsilon + 0x3A8)));
                } else {
                    var_r4 = ((TObjEneEpsilon *)ene_epsilon)->rotation_y;
                }
                ((TObjEneEpsilon *)ene_epsilon)->rotation_y = approach_angle_limited(((TObjEneEpsilon *)ene_epsilon)->rotation_y, var_r4, 0x300);
                ((TObjEneEpsilon *)ene_epsilon)->m_3a0 = sin_table_lookup(((TObjEneEpsilon *)ene_epsilon)->rotation_y);
                *(f32 *)((s8 *)ene_epsilon + 0x3A8) = cos_table_lookup(((TObjEneEpsilon *)ene_epsilon)->rotation_y);
            }
            ((VObj_18_4f5f2e *)(ene_epsilon))->m110();
            if (((TObjEneEpsilon *)ene_epsilon)->frame >= 0.0f && ((TObjEneEpsilon *)ene_epsilon)->frame <= 5.0f) {
                info = ((Info_800E5CE4 * *)&TObjEneMe3ShinowaMirage__mirage_info_table)[*(s32 *)((s8 *)ene_epsilon + 0x3C0)];
                move_to_shot_position__9TObjEneDDFfff(ene_epsilon, info, ((TObjEneEpsilon *)ene_epsilon)->m_3a0, *(f32 *)((s8 *)ene_epsilon + 0x3A8), info->f8);
            } else {
                ((TObjEneEpsilon *)(ene_epsilon))->vfunc_102();
            }
            if (((TObjEneEpsilon *)ene_epsilon)->frame >= 25.0f) {
                ((TObjEneEpsilon *)ene_epsilon)->frame = 25.0f;
                *(s32 *)((s8 *)ene_epsilon + 0x404) = 1;
            }
            break;
        case 1:
            (*(s32 *)((s8 *)ene_epsilon + 0x408))++;
            if (*(s32 *)((s8 *)ene_epsilon + 0x408) <= ((Info_800E5CE4 * *)&TObjEneMe3ShinowaMirage__mirage_info_table)[*(s32 *)((s8 *)ene_epsilon + 0x3C0)]->f20) {
                ((TObjEneEpsilon *)ene_epsilon)->frame = 25.0f;
            }
            ((TObjEneEpsilon *)(ene_epsilon))->vfunc_102();
            break;
        }
        ((TObjEneEpsilon *)(ene_epsilon))->vfunc_89();
        break;
    }
}

#pragma push
#pragma fp_contract on

void TObjEneMe3ShinowaMirage__sub_800E5F64(u8 *arg0, s32 arg1) {
    Vec_800E5F64 sp20;
    Vec_800E5F64 sp14;
    Vec_800E5F64 v;
    f32 d;
    s32 var_r4;
    s32 entry;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 5;
        ((TObjEneDD *)arg0)->set_field_378(4);
        ((TObjEneDD *)(arg0))->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x3C4) &= ~3;
        *(s32 *)((s8 *)arg0 + 0x3C4) |= 0x10000;
        *(s32 *)((s8 *)arg0 + 0x404) = 0;
        *(f32 *)((s8 *)arg0 + 0x410) = 0.0f;
        ((TUnk_80494968 *)(*(u8 **)((s8 *)arg0 + 0x3E0)))->clear_segments();
        ((TObjEneDD_ST *)arg0)->set_active();
        break;
    case 3:
        if (*(s32 *)((s8 *)arg0 + 0x404) == 5 || ((int)((TObjEneDD *)arg0)->get_flag_b4()) != 0) {
            if (((TObjEneDD *)(arg0))->vfunc_102() == 0U) {
                transition_enemy_state__9TObjEneDDFl(arg0, 9);
            } else {
                transition_enemy_state__9TObjEneDDFl(arg0, 4);
            }
        }
        break;
    case 0:
        switch (*(s32 *)((s8 *)arg0 + 0x404)) {
        case 0:
            ((TObjMotion *)arg0)->advance_animation();
            if (*(s32 *)((s8 *)arg0 + 0xB0) & 8) {
                *(s32 *)((s8 *)arg0 + 0x404) = 1;
            }
            ((TObjEneDD *)(arg0))->vfunc_102();
            ((TObjEneDD *)(arg0))->vfunc_89();
            break;
        case 1:
            ((TObjMotion *)arg0)->advance_animation();
            if (((TObjEneEpsilon *)arg0)->update_death_check() != 0) {
                ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                ((TObjEneDD *)arg0)->update_velocity();
                var_r4 = (s32)(10430.38043493439 * atan2_float(*(f32 *)((s8 *)arg0 + 0x3A0), *(f32 *)((s8 *)arg0 + 0x3A8)));
            } else {
                var_r4 = *(s32 *)((s8 *)arg0 + 0x60);
            }
            *(s32 *)((s8 *)arg0 + 0x60) = approach_angle_limited(*(s32 *)((s8 *)arg0 + 0x60), var_r4, 0x1000);
            if (((TObjMotion *)arg0)->is_passing_frame(10.0f) != 0) {
                *(s32 *)((s8 *)arg0 + 0x404) = 2;
            }
            ((TObjEneDD *)(arg0))->vfunc_102();
            ((TObjEneDD *)(arg0))->vfunc_89();
            break;
        case 2:
            ((TObjMotion *)arg0)->advance_animation();
            if (((TObjEneEpsilon *)arg0)->update_death_check() != 0) {
                ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                ((TObjEneDD *)arg0)->update_velocity();
            }
            if (*(f32 *)((s8 *)arg0 + 0xC0) + *(f32 *)((s8 *)arg0 + 0xC8) >= 14.0f) {
                if (((s32 (*)(void *, s32, f32))check_body_collision_at__17TObjEneMe3ShinowaFlf)(arg0, *(s32 *)((s8 *)arg0 + 0x60), *(f32 *)((s8 *)arg0 + 0x3AC) - 20.0f) != 0) {
                    *(s32 *)((s8 *)arg0 + 0x404) = 5;
                } else {
                    d = *(f32 *)((s8 *)arg0 + 0x3AC) - 20.0f;
                    VecCopy((Vec *)&v, (const Vec *)(arg0 + 0x38));
                    v.x += *(f32 *)((s8 *)arg0 + 0x3A0) * d;
                    v.y += 20.0f;
                    v.z += *(f32 *)((s8 *)arg0 + 0x3A8) * d;
                    if (csnVecterUnder(&v, 0x15) != 0U) {
                        *(s32 *)((s8 *)arg0 + 0x404) = 3;
                        *(f32 *)((s8 *)arg0 + 0x414) = (*(f32 *)((s8 *)arg0 + 0x3AC) - 20.0f) / 12.857143f;
                        ((TObjEneDD *)(arg0))->vfunc_91();
                        play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003AD11)), arg0 + 0x38, 0, 0);
                    } else {
                        *(s32 *)((s8 *)arg0 + 0x404) = 5;
                    }
                }
            }
            ((TObjEneDD *)(arg0))->vfunc_102();
            ((TObjEneDD *)(arg0))->vfunc_89();
            break;
        case 3:
            ((TObjMotion *)arg0)->advance_animation();
            if (*(f32 *)((s8 *)arg0 + 0xC0) + *(f32 *)((s8 *)arg0 + 0xC8) >= 23.0f) {
                *(s32 *)((s8 *)arg0 + 0x404) = 4;
                ((TObjEneDD *)(arg0))->vfunc_92();
                play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003AD12)), arg0 + 0x38, 0, 0);
                spawn_particle_effect(arg0 + 0x38, 0xF3);
            }
            ((TObjEneDD *)arg0)->move_with_wall_slide_commit(*(f32 *)((s8 *)arg0 + 0x3A0), *(f32 *)((s8 *)arg0 + 0x3A8), *(f32 *)((s8 *)arg0 + 0x414));
            ((TObjEneDD *)(arg0))->vfunc_88();
            break;
        case 4:
            ((TObjMotion *)arg0)->advance_animation();
            if (((TObjMotion *)arg0)->is_passing_frame(25.0f) != 0) {
                if (((TObjEneDD_ST *)arg0)->enemy_check_target_valid() != 0) {
                    if (((VObj_18_2add4a *)*(u8 **)((s8 *)arg0 + 0x390))->m18(arg0, 1.0f) != 0) {
                        ((VObj_18_2add4a *)*(u8 **)((s8 *)arg0 + 0x390))->m20(arg0, 1.0f);
                        ((VObj_18_2add4a *)*(u8 **)((s8 *)arg0 + 0x390))->m23(arg0, 3.0f);
                    }
                }
                play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003AD13)), arg0 + 0x38, 0, 0);
            }
            *(f32 *)((s8 *)arg0 + 0x414) *= 0.85f;
            ((TObjEneDD *)arg0)->move_with_wall_slide_on_ground(*(f32 *)((s8 *)arg0 + 0x3A0), *(f32 *)((s8 *)arg0 + 0x3A8), *(f32 *)((s8 *)arg0 + 0x414));
            ((TObjEneDD *)(arg0))->vfunc_89();
            break;
        }
        if (*(s32 *)((s8 *)arg0 + 0x404) != 0) {
            entry = (s32)TObjEneMe3ShinowaMirage__data_805D52AC->lookup(*(f32 *)((s8 *)arg0 + 0xC0));
            if (entry != 0) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(arg0 + 0x38);
                rotate_matrix_y(0, *(s32 *)((s8 *)arg0 + 0x60));
                mult_vec_array__10TObjPlayerFUll(0, entry, &sp14, 2);
                pop_matrix();
                ((VObj_18_2add4a *)*(u8 **)((s8 *)arg0 + 0x3E0))->m4((s32 *)&sp14, (s32 *)&sp20);
            }
        }
        break;
    case 5:
        *(f32 *)((s8 *)arg0 + 0x3C8) = *(f32 *)((s8 *)arg0 + 0x3C);
        *(f32 *)((s8 *)arg0 + 0x3CC) = 0.0f;
        ((TObjEneDD *)(arg0))->vfunc_92();
        ((TObjEneDD *)arg0)->clear_field_388();
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneMe3ShinowaMirage::state_chase_target(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        this->requested_action = 9;
        ((TObjEneDD *)arg0)->set_field_378(4);
        this->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFFC);
        *(f32 *)((s8 *)arg0 + 0x3AC) = 300.0f;
        if (*(s32 *)((s8 *)arg0 + 0x3C4) & 0x10) {
            *(f32 *)((s8 *)arg0 + 0x410) = (f32) *(f32 *)((s8 *)TObjEneMe3ShinowaMirage__mirage_info_table[*(s32 *)((s8 *)arg0 + 0x3C0)] + 4);
        } else {
            *(f32 *)((s8 *)arg0 + 0x410) = (f32) *(f32 *)((s8 *)TObjEneMe3ShinowaMirage__mirage_info_table[*(s32 *)((s8 *)arg0 + 0x3C0)] + 0);
        }
        *(f32 *)((s8 *)arg0 + 0x414) = 0.0f;
        return;
    case 3:
        if ((u32) this->m_390 == 0U) {
            this->vfunc_111();
            transition_enemy_state__9TObjEneDDFl(arg0, 0xB);
        } else if (((s32 (*)(f32))check_in_range__23TObjEneMe3ShinowaMirageFPv)((f32) (*(f32 *)((s8 *)arg0 + 0x414))) != 0) {
            transition_enemy_state__9TObjEneDDFl(arg0, 6);
        } else if (((VObj_18_e66632 *)(arg0))->m104() != 0) {
            transition_enemy_state__9TObjEneDDFl(arg0, 5);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        if (((s32 (*)(void *, f32))update_linked_position__12TObjEneDD_STFf)(arg0, 200.0f) != 0) {
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            ((TObjEneDD *)arg0)->update_velocity();
            *(f32 *)((s8 *)arg0 + 0x414) = (f32) ((*(f32 *)((s8 *)arg0 + 0x3A0) * sin_table_lookup(this->rotation_y)) + (*(f32 *)((s8 *)arg0 + 0x3A8) * cos_table_lookup(this->rotation_y)));
            if (*(f32 *)((s8 *)arg0 + 0x414) < cos_table_lookup(0x1000)) {
                ((TObjEneDD *)arg0)->turn_toward_target_direction(0x500);
                this->vfunc_102();
            } else {
                enemy_turn_and_move_on_ground((arg0), 0x500, (f32) (*(f32 *)((s8 *)arg0 + 0x410)));
            }
            this->vfunc_89();
        }
        break;
    }
}
#pragma pop

void TObjEneMe3ShinowaMirage__sub_800E66FC(u8 *arg0, s32 arg1) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f31;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        ((TObjEneDD *)arg0)->set_field_378(0xB);
        ((TObjEneDD *)(arg0))->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFFD);
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) | 1);
        *(s32 *)((s8 *)arg0 + 0x404) = 0;
        *(f32 *)((s8 *)arg0 + 0x410) = 0.0f;
        if (((TObjEneDD_ST *)arg0)->enemy_has_live_target() != 0) {
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            ((TObjEneDD *)arg0)->update_velocity();
            *(s32 *)((s8 *)arg0 + 0x40C) = (s32) (10430.38043493439 * ((f32 (*)(f64, f64))atan2_float)((f64) *(f32 *)((s8 *)arg0 + 0x3A0), (f64) *(f32 *)((s8 *)arg0 + 0x3A8)));
            return;
        }
        *(s32 *)((s8 *)arg0 + 0x40C) = (s32) *(s32 *)((s8 *)arg0 + 0x60);
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x404) == 3) {
            transition_enemy_state__9TObjEneDDFl(arg0, 0xB);
        }
        return;
    case 0:
        switch (*(s32 *)((s8 *)arg0 + 0x404)) {
        case 0:
            temp_f31 = ((TObjEneMe3Shinowa *)arg0)->get_node_world_y();
            ((TObjMotion *)arg0)->advance_animation();
            *(f32 *)((s8 *)arg0 + 0x414) = ((TObjEneMe3Shinowa *)arg0)->get_node_world_y();
            *(f32 *)((s8 *)arg0 + 0x3C8) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C8) + (temp_f31 - *(f32 *)((s8 *)arg0 + 0x414)));
            *(s32 *)((s8 *)arg0 + 0x60) = (s32) (*(s32 *)((s8 *)arg0 + 0x60) + 0x8000);
            *(s32 *)((s8 *)arg0 + 0x404) = 1;
            *(f32 *)((s8 *)arg0 + 0x3CC) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C8) - *(f32 *)((s8 *)arg0 + 0x3C));
            break;
        case 1:
            ((TObjMotion *)arg0)->advance_animation();
            if (*(f32 *)((s8 *)arg0 + 0xC0) > 29.0f) {
                *(f32 *)((s8 *)arg0 + 0xC0) = 29.0f;
            }
            *(s32 *)((s8 *)arg0 + 0x60) = ((s32 (*)(s32, s32, s32))approach_angle_limited)(*(s32 *)((s8 *)arg0 + 0x60), *(s32 *)((s8 *)arg0 + 0x40C), 0x800);
            *(f32 *)((s8 *)arg0 + 0x410) = (f32) (*(f32 *)((s8 *)arg0 + 0x410) - 0.3f);
            if (*(f32 *)((s8 *)arg0 + 0x410) < -5.0f) {
                *(f32 *)((s8 *)arg0 + 0x410) = -5.0f;
            }
            *(f32 *)((s8 *)arg0 + 0x3C8) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C8) + *(f32 *)((s8 *)arg0 + 0x410));
            temp_f1 = ((TObjEneMe3Shinowa *)arg0)->get_node_world_y();
            *(f32 *)((s8 *)arg0 + 0x3C8) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C8) - (temp_f1 - *(f32 *)((s8 *)arg0 + 0x414)));
            *(f32 *)((s8 *)arg0 + 0x414) = temp_f1;
            if (*(f32 *)((s8 *)arg0 + 0x3C8) < *(f32 *)((s8 *)arg0 + 0x3C)) {
                *(f32 *)((s8 *)arg0 + 0x3C8) = *(f32 *)((s8 *)arg0 + 0x3C);
                *(s32 *)((s8 *)arg0 + 0x404) = 2;
                ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003AD12)), (u32)(arg0 + 0x38), 0, 0);
                ((s32 (*)(s32, s32))spawn_particle_effect)((s32)(arg0 + 0x38), 0xF3);
            }
            break;
        case 2:
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                *(s16 *)((s8 *)arg0 + 0xB8) = 8;
                *(s32 *)((s8 *)arg0 + 0x404) = 3;
                *(f32 *)((s8 *)arg0 + 0x3C8) = (f32) *(f32 *)((s8 *)arg0 + 0x3C);
                *(f32 *)((s8 *)arg0 + 0x3CC) = 0.0f;
            }
            ((TObjMotion *)arg0)->advance_animation();
            break;
        }
        ((TObjEneDD *)(arg0))->vfunc_102();
        ((TObjEneMe3ShinowaMirage *)arg0)->update_by_distance();
        ((TObjEneDD *)(arg0))->vfunc_89();
        *(f32 *)((s8 *)arg0 + 0x3CC) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C8) - *(f32 *)((s8 *)arg0 + 0x3C));
        return;
    case 5:
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFFE);
        *(f32 *)((s8 *)arg0 + 0x3CC) = 0.0f;
        break;
    }
}

void TObjEneMe3ShinowaMirage__sub_800E69F0(u8 *ene_me3_shinowa_mirage, s32 arg1) {
    s32 temp_r3;
    s32 ene_dd_st;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_me3_shinowa_mirage + 0xB8) = 0;
        ((TObjEneDD *)ene_me3_shinowa_mirage)->set_field_378(3);
        ((TObjEneDD *)(ene_me3_shinowa_mirage))->vfunc_95();
        *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C4) = (s32) (*(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C4) & 0xFFFFFFFC);
        *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x404) = 0;
        *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x408) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x404) > 0x1E) {
            transition_enemy_state__9TObjEneDDFl(ene_me3_shinowa_mirage, 3);
        }
        return;
    case 0:
        ((TObjMotion *)ene_me3_shinowa_mirage)->advance_animation();
        temp_r3 = *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x404);
        if (temp_r3 == 0) {
            if (((s32 (*)(void *, f32))update_linked_position__12TObjEneDD_STFf)(ene_me3_shinowa_mirage, 200.0f) != 0) {
                static const u32 color_mask = 0xFFFF00FF; /* clears the second byte of the colour at 0x3D0 */
                *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x404) = 1;
                if (!(*(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C4) & 0x1000)) {
                    *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3D0) = 0x1C00FFFF;
                }
                *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3D0) &= color_mask;
                *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x408) = 0;
            }
        } else {
            *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x404) = (temp_r3 + 1);
            *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x408) = (s32) (*(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x408) + 0x10);
            if ((s32) *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x408) > 0xFF) {
                *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x408) = 0xFF;
            }
            ene_dd_st = *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x408);
            *(u32 *)((s8 *)ene_me3_shinowa_mirage + 0x3D0) = (ene_dd_st << 24) | (*(u32 *)((s8 *)ene_me3_shinowa_mirage + 0x3D0) & 0x00FFFFFF);
            if (enemy_validate_retained_target(ene_me3_shinowa_mirage, ene_dd_st) == 0) {
                *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x404) = 0;
                if (!(*(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C4) & 0x1000)) {
                    *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3D0) = 0;
                }
            }
        }
        ((TObjEneDD *)(ene_me3_shinowa_mirage))->vfunc_102();
        ((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->update_by_distance();
        ((TObjEneDD *)(ene_me3_shinowa_mirage))->vfunc_89();
        *(f32 *)((s8 *)ene_me3_shinowa_mirage + 0x3CC) = (f32) (*(f32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C8) - *(f32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C));
        return;
    case 5:
        if (!(*(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C4) & 0x1000)) {
            *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3D0) = 0x1C00FFFF;
        }
        *(f32 *)((s8 *)ene_me3_shinowa_mirage + 0x3CC) = 0.0f;
        break;
    }
}

void TObjEneMe3Shinowa::sub_800E6BB8(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    Stack_800E6BB8 stack;
    f32 temp_f1;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        ((TObjEneDD *)arg0)->set_field_378(0);
        this->vfunc_95();
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFFC);
        ((TUnk_80494938 *)(arg0 + 0x3E8))->start_fade_in();
        VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x38));
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x3C8);
        stack.spC = temp_f1 - 20.0f;
        TBoss3Volopt__sub_800D8D88(&stack.sp8, temp_f1);
        return;
    case 3:
        if (((VObj_14_948132 *)(arg0 + (1000)))->m5() != 0) {
            transition_enemy_state__9TObjEneDDFl(arg0, 2);
        }
    case 5:
    case 0:
        return;
    }
}

void TObjEneMe3Shinowa::action(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        ((TObjEneDD *)arg0)->set_field_378(1);
        this->vfunc_95();
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) | 2);
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFFE);
        if (TObjEneDD::check_v2_mode() != 0) {
            *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFCFFFF);
        }
        *(s32 *)((s8 *)arg0 + 0x404) = 0;
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg0 + 0x50));
        VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x50));
        VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x50));
        *(f32 *)((s8 *)arg0 + 0x3C8) = (f32) *(f32 *)((s8 *)arg0 + 0x3C);
        if (!(*(s32 *)((s8 *)arg0 + 0x3C4) & 0x1000)) {
            *(s32 *)((s8 *)arg0 + 0x3D0) = 0;
        }
        *(s32 *)((s8 *)arg0 + 0x3D8) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x404) > 5) {
            transition_enemy_state__9TObjEneDDFl(arg0, 1);
        }
    case 5:
        return;
    case 0:
        *(s32 *)((s8 *)arg0 + 0x404) = (s32) (*(s32 *)((s8 *)arg0 + 0x404) + 1);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x404) == 1) {
            *(f32 *)((s8 *)arg0 + 0x3C8) = (f32) *(f32 *)((s8 *)arg0 + 0x3C);
            this->vfunc_102();
            *(f32 *)((s8 *)arg0 + 0x3CC) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C8) - *(f32 *)((s8 *)arg0 + 0x3C));
        }
        break;
    }
}

void dispatch_action__23TObjEneMe3ShinowaMirageFPvUii(Obj_800E6DD8 *arg0_, u32 arg1, s32 arg2) {
    switch (arg1) {
    case 0:
        arg0_->v111(arg2);
        return;
    case 1:
        ((TObjEneMe3Shinowa *)arg0_)->sub_800E6BB8(arg2);
        return;
    case 2:
        TObjEneMe3ShinowaMirage__sub_800E69F0((u8 *)arg0_, (s32)arg2);
        return;
    case 3:
        TObjEneMe3ShinowaMirage__sub_800E66FC((u8 *)arg0_, arg2);
        return;
    case 4:
        ((TObjEneMe3ShinowaMirage *)arg0_)->state_chase_target(arg2);
        return;
    case 5:
        TObjEneMe3ShinowaMirage__sub_800E5F64((u8 *)arg0_, (s32)arg2);
        return;
    case 6:
        TObjEneMe3ShinowaMirage__sub_800E5CE4((u8 *)arg0_, (s32)arg2);
        return;
    case 7:
        TObjEneMe3ShinowaReal__sub_800E5950((u8 *)arg0_, (s32)arg2);
        return;
    case 8:
        TObjEneMe3ShinowaMirage__sub_800E54E8(arg0_, arg2);
        return;
    case 11:
        TObjEneMe3ShinowaMirage__sub_800E5220(arg0_, arg2);
        return;
    case 9:
        TObjEneMe3ShinowaMirage__sub_800E50D8((u8 *) arg0_, arg2);
        return;
    case 10:
        ((TObjEneMe3ShinowaMirage *)arg0_)->state_cast_support(arg2);
        return;
    case 12:
        TObjEneMe3ShinowaMirage__sub_800E4FE8((u8 *)arg0_, (s32)arg2);
        return;
    case 13:
        ((TObjEneMe3ShinowaMirage *)arg0_)->state_break_apart(arg2);
        return;
    case 14:
        arg0_->v112(arg2);
        return;
    case 15:
        arg0_->v113(arg2);
        return;
    case 16:
        arg0_->v114(arg2);
    default:
        return;
    }
}

void TObjEneMe3ShinowaMirage__sub_800E6F0C(Obj_800E6F0C *self) {
    s32 f = TObjEneDD::clamp_frame_index(TObjEneMe3ShinowaMirage__mirage_info_table[self->kind]->frame);
    TTecResta::create((void *)self, self->pos, (void *)f);
}

void TObjEneMe3Shinowa::sub_800E6F64() {
    u8 *arg0 = (u8 *)this;
    if (sub_800E6FE0__17TObjEneMe3ShinowaFv(arg0) != 0) {
        *(s32 **)((s8 *)arg0 + 0x24) = (s32 *)&lbl_80500FEC;
        initialize_enemy_state__9TObjEneDDFl(arg0, 0x1b);
        *(s32 *)((s8 *)arg0 + 0x3c0) = 1;
        return;
    }
    *(s32 **)((s8 *)arg0 + 0x24) = (s32 *)TObjEneMe3ShinowaMirage__data_805D5298->models->m_c;
    initialize_enemy_state__9TObjEneDDFl(arg0, 0x1a);
    *(s32 *)((s8 *)arg0 + 0x3c0) = 0;
}

s32 TObjEneMe3Shinowa::sub_800E6FE0() {
    u8 *arg0 = (u8 *)this;
    return *(f32 *)((s8 *)arg0 + 0x358) >= 1.0f;
}

s32 TObjEneMe3Shinowa::vfunc_104(f32) { return select_and_apply_target__12TObjEneDD_STFf(this); }

s32 TObjEneMe3Shinowa::sub_800E701C() {
    u8 *arg0 = (u8 *)this;
    return *(f32 *)((s8 *)arg0 + 0x354) < 1.0f;
}

void TObjEneMe3Shinowa::vfunc_89() {
    struct VObj_800E7034_800E47DC *o = (struct VObj_800E7034_800E47DC *)this;
    o->m86();
    ((TObjPlayer *)this)->check_object_collisions();
    check_enemy_body_collisions(this);
}

void TObjEneMe3ShinowaMirage::update_by_distance() {
    VObj_800E707C_800E47DC *o = (VObj_800E707C_800E47DC *)this;
    f32 lim = 30.0f;
    if ((*(f32 *)((s8 *)this + 0x3C8) - *(f32 *)((s8 *)this + 0x3C)) > lim) {
        o->m95();
        return;
    }
    o->m96();
}

void TObjEneMe3Shinowa::apply_effect_pair() {
    u8 *arg0 = (u8 *)this;
    s32 sp8[8];
    u32 entry;
    u32 temp_r3_3;

    push_matrix();
    set_matrix_identity(0);
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    entry = (s32)TObjEneMe3ShinowaMirage__data_805D52A4->lookup(this->frame);
    if (entry != 0U) {
        mult_vec_array__10TObjPlayerFUll(0, entry, &sp8, 2);
        ((VObj18b_800e70d4_800E47DC *) ((unsigned char *) (*(void **)((s8 *)arg0 + 0x3E0))))->m4(&sp8, &sp8[3]);
    }
    temp_r3_3 = (s32)TObjEneMe3ShinowaMirage__data_805D52A8->lookup(this->frame);
    if (temp_r3_3 != 0U) {
        mult_vec_array__10TObjPlayerFUll(0, temp_r3_3, &sp8, 2);
        ((VObj18b_800e70d4_800E47DC *) ((unsigned char *) (*(void **)((s8 *)arg0 + 0x3E4))))->m4(&sp8, &sp8[3]);
    }
    pop_matrix();
}

#undef PAD_VIRT
#undef PADV
#undef PADV4
void TObjEneMe3Shinowa::vfunc_111() {  }

void TObjEneMe3Shinowa::dispatch_if_active() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r0;

    temp_r0 = this->mode;
    if ((temp_r0 == 1) || (temp_r0 == 9) || (*(s32 *)((s8 *)arg0 + 0x3C4) & 0x80000)) {
        ((E71ACObj_800e71ac_800E71A8*)(arg0 + 0x3E8))->m7();
    }
}

s32 TObjEneMe3Shinowa::update_effect() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r0;

    temp_r0 = this->mode;
    if ((temp_r0 == 1) || (temp_r0 == 9) || (*(s32 *)((s8 *)arg0 + 0x3C4) & 0x80000)) {
        ((E71FCObj_800e71fc_800E71A8*)(arg0 + 0x3E8))->m6();
    }
    return 0;
}

void TObjEneMe3ShinowaReal::sub_800E7250() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFEF);
    this->m_2cc = (s16) *(s16 *)((s8 *)arg0 + 0x3DC);
}

void TObjEneMe3Shinowa__sub_800E7268(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) | 0x10);
    *(s16 *)((s8 *)arg0 + 0x2CC) = (s16) ((s16) *(s16 *)((s8 *)arg0 + 0x3DC) / 2);
}

void TObjEneMe3Shinowa::vfunc_107() {  }

#pragma push
#pragma fp_contract on
u8 TObjEneMe3Shinowa::can_hit_same_target() {
    s16 mine;
    s32 ret;
    s16 theirs;
    ret = 0;
    if (!(((E_800E728C *)this)->f3c4 & 0x10000)) {
        if (((E_800E728C *)this)->f3ac > 100.0f && ((E_800E728C *)this)->f3ac < 150.0f) {
            mine = get_room__8TObjBaseFv((int)((E_800E728C *)this));
            theirs = get_room__8TObjBaseFv(((E_800E728C *)this)->f390);
            if (theirs == mine && ((s32 (*)(void *, s32, f32))check_body_collision_at__17TObjEneMe3ShinowaFlf)(((E_800E728C *)this), ((E_800E728C *)this)->f60, ((E_800E728C *)this)->f3ac - 20.0f) == 0) {
                ret = 1;
            }
        }
    }
    return (u8)ret;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneMe3Shinowa::update_player_state_default() {
    u8 *arg0 = (u8 *)this;
    if (!(*(s32 *)((s8 *)arg0 + 0x3C4) & 0x80000)) {
        Vec stack = lbl_8043CF94;
        ((TObjEneDD *)(arg0))->draw_ground_shadow(&stack, 0);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma fp_contract on
void TObjEneMe3Shinowa::vfunc_105() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r31;
    temp_r31 = ((TObjMotion *)arg0)->is_passing_frame(19.0f);
    if ((((TObjMotion *)arg0)->is_passing_frame(9.0f) != 0) || (temp_r31 != 0)) {
        if (((TObjEneDD_ST *)arg0)->enemy_check_target_valid() != 0) {
            if (((VObj_18_c44252 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x390))))->m18(arg0, 1.0f) != 0) {
                ((VObj_18_c44252 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x390))))->m20(arg0, 1.0f);
                ((VObj_18_c44252 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x390))))->m23(arg0, 3.0f);
                if ((temp_r31 != 0) && (random_ratio__9TObjCharaFv((s32) arg0) <= 0.1666f)) {
                    TObjEneDD__sub_800BA438((s32)arg0, (*(u8 **)((s8 *)arg0 + 0x390)));
                }
            }
        }
        ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003AD13)), (u32)(arg0 + 0x38), 0, 0);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 check_in_range__23TObjEneMe3ShinowaMirageFPv(void *arg0) {
    f32 f31;

    if (*(f32 *)((s8 *)arg0 + 0x3AC) > 25.0f) {
        return 0;
    }
    f31 = *(f32 *)((s8 *)arg0 + 0x3A8) * ((f32 (*)(s32))cos_table_lookup)(*(s32 *)((s8 *)arg0 + 0x60));
    f31 += *(f32 *)((s8 *)arg0 + 0x3A0) * ((f32 (*)(s32))sin_table_lookup)(*(s32 *)((s8 *)arg0 + 0x60));
    return (s32)((u32)__cntlzw(f31 < ((f32 (*)(s32))cos_table_lookup)(0x1E00)) >> 5);
}
#pragma pop

#pragma push
#pragma fp_contract on
u8 TObjEneMe3Shinowa::check_body_collision_at(s32 arg1, f32 farg0) {
    Obj_800E750C *arg0 = (Obj_800E750C *)this;
    farg0 *= 0.5f;
    Sub_800E750C *s = *(Sub_800E750C * *)&this->bodies;
    u8 res;
    s32 a = this->rotation_y;
    s32 b = s->f18;
    s->f0 = 0.0f;
    s->f8 = farg0;
    s->fC = farg0;
    s->f10 = 8.0f;
    s->f14 = 1;
    s->f18 = 0x9D01;
    this->rotation_y = arg1;
    ((void (*)(void *, s32, f32, f32))check_enemy_body_collisions)(arg0, arg1, 0.0f, farg0);
    res = (s->f18 & 0x380000) != 0;
    copy_collision_body((CollisionBody *)s, (const CollisionBody *)shinowa_mirage_model_init_data);
    s->f18 = b;
    this->rotation_y = a;
    return res;
}
#pragma pop

#pragma push
#pragma fp_contract on
f32 TObjEneMe3Shinowa::get_node_world_y() {
    TObjEneMe3Shinowa *self = this;
    Vec v;
    Node_800E75AC *node;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    push_matrix_from(identity_matrix);
    bind_motion_context((NJS_MOTION *)self->current_motion, self->frame);
    node = *(Node_800E75AC * *)&self->model;
    compose_motion_node_matrix(node);
    compose_motion_node_matrix(node->child);
    matrix_mult_vec(0, &v, &v);
    pop_matrix();
    return v.y;
}
#pragma pop

void fn_800E762C(void *) {  }

void TObjEneMe3Shinowa::vfunc_88() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)this->bodies + 4) = (f32) (*(f32 *)((s8 *)arg0 + 0x3CC) + (this->m_300 - *(f32 *)((s8 *)arg0 + 0x3C)));
}

void TObjEneMe3Shinowa::copy_position_vector() { VecCopy((Vec *)((char*)this + 0x74), (const Vec *)((char*)this + 0x2fc)); }

void TObjEneMe3Shinowa::vfunc_61() {  }

void TObjEneMe3Shinowa::vfunc_62() {
    u8 *arg0 = (u8 *)this;
    if (TObjEneDD::check_v2_mode() != 0) {
        ((TObjEneDD *)arg0)->clear_attack_receipts();
        return;
    }
    if (*(s32 *)((s8 *)arg0 + 0x3C4) & 1) {
        ((TObjEneDD *)arg0)->clear_attack_receipts();
        return;
    }
    if ((s16) this->mode != 0xC) {
        ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFl)(arg0, (void*)(0xC));
    }
}

void TObjEneMe3Shinowa::vfunc_63() { if (this->mode != 13) { ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFl)(this, (void*)13); } }

void TObjEneMe3Shinowa::vfunc_28() {  }

void TObjEneMe3Shinowa::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        this->update_mirage();
        return;
    }
    if (this->vfunc_83() != 4) {
        this->vfunc_85();
    }
    this->copy_position_vector();
    ((TObjEnemy *)((u8 *)this))->submit_default_cursor_candidate();
    this->vfunc_100();
}

void *__dt__17TObjEneMe3ShinowaFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TObjEneMe3Shinowa;
        queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x3E4));
        *(s32 *)((s8 *)arg0 + 0x3E4) = 0;
        queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x3E0));
        *(s32 *)((s8 *)arg0 + 0x3E0) = 0;
        if (*(void **)((s8 *)arg0 + 0x424) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x424)); *(s32 *)((s8 *)arg0 + 0x424) = 0; }
        if (*(void **)((s8 *)arg0 + 0x428) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x428)); *(s32 *)((s8 *)arg0 + 0x428) = 0; }
        free_collision_body_parts((TObjCollidable *)arg0);
        __dt__13TUnk_80494938Fv((s8 *)arg0 + 0x3E8, -1);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma opt_propagation off
void TObjEneMe3Shinowa::init_enemy() {
    Mirage_800E7884 *self = (Mirage_800E7884 *)this;
    Tbl_800E7884 *tbl = &(*(Tbl_800E7884 *)&TObjEneMe3ShinowaMirage__data_80500FC0);
    ((TObjEneDD *)self)->init_position_vectors();
    ((TObjEneMe3Shinowa *)self)->sub_800E6F64();
    self->f34 = TObjEneMe3ShinowaMirage__data_805D5298->models->model;
    init_model__9TObjEneDDFP13CollisionBodyl(self, ((void * *)shinowa_mirage_model_init_data), 1);
    self->fB0 = 0;
    ((TObjMotion *)self)->set_field_d8((s32)shinowa_mirage_motion_param_table);
    ((TObjMotion *)self)->set_field_dc((s32)TObjEneMe3ShinowaMirage__data_805D5298->motions);
    self->fB8 = 0;
    ((TObjMotion *)self)->set_animation(self->fB8);
    ((TObjMotion *)self)->set_field_b8(self->fB8);
    {
        s32 *a = tbl->t[0];
        s32 *b = tbl->t[1];
        s32 *c = tbl->t[2];
        s32 i = self->f3C0;
        reset_hp__9TObjEneDDFPUcPUcPUc(self, a[i], b[i], c[i]);
    }
    ((TObjEneDD *)self)->check_state_flag_4();
    self->f350 = TObjEneMe3ShinowaMirage__init_params;
    self->f37C = 10.0f;
    ((TObjEneDD_ST *)self)->enemy_init_acquire_period(0x1E);
    ((TObjEneDD_ST *)self)->enemy_init_validate_period(0x1E);
    self->f3C4 = 0;
    self->f3C8 = self->f3C;
    self->f3CC = 0.0f;
    self->f3D0 = 0;
    self->f3D8 = 0;
    self->f3D4 = 0;
    self->f3DC = self->f2CC;
    self->f3E0 = TUnk_80494968::create((u32)0xFF0000FF, (u32)0xA08000A0);
    self->f3E4 = TUnk_80494968::create((u32)0xFF0000FF, (u32)0xA08000A0);
    self->sub.m3();
    self->f404 = 0;
    self->f408 = 0;
    self->f40C = 0;
    self->f410 = 0.0f;
    self->f414 = 0.0f;
    self->f418 = 0.0f;
    self->f41C = 0.0f;
    self->f420 = 0.0f;
    self->f424 = 0;
    self->f428 = 0;
}
#pragma pop

void *TObjEneMe3Shinowa__ct(void *ene_me3_shinowa, void *parent) {
    __ct__12TObjEneDD_STFP7TObject(ene_me3_shinowa, parent);
    *(s32 **)((s8 *)ene_me3_shinowa + 0x18) = __vt__17TObjEneMe3Shinowa;
    __ct__13TUnk_80494938Fv(((char *)ene_me3_shinowa + 1000));
    *(void * *)&((TObjEneMe3Shinowa *)ene_me3_shinowa)->m_name = TObjEneMe3Shinowa__name;
    return ene_me3_shinowa;
}
}




extern "C" {
s32 free_bin_model_request(void *, s32);
void mem_free(void *p);
int create__21TObjEneMe3ShinowaRealFv(void*);

void TObjEneMe3ShinowaMirage::set_slot_min_clamped_value(s32 arg0, f32 farg0) {
    if (farg0 < 0.1f) {
        farg0 = 0.1f;
    }
    shinowa_mirage_motion_param_table[arg0].speed = farg0;
}

void TObjEneMe3ShinowaMirage::free_shared_resources() {
    if (TObjEneMe3ShinowaMirage__data_805D52A8 != 0) {
        delete TObjEneMe3ShinowaMirage__data_805D52A8;
        TObjEneMe3ShinowaMirage__data_805D52A8 = 0;
    }
    if (TObjEneMe3ShinowaMirage__data_805D52A4 != 0) {
        delete TObjEneMe3ShinowaMirage__data_805D52A4;
        TObjEneMe3ShinowaMirage__data_805D52A4 = 0;
    }
    if (TObjEneMe3ShinowaMirage__data_805D52AC != 0) {
        delete TObjEneMe3ShinowaMirage__data_805D52AC;
        TObjEneMe3ShinowaMirage__data_805D52AC = 0;
    }
    if (TObjEneMe3ShinowaMirage__data_805D52A0 != 0) {
        delete TObjEneMe3ShinowaMirage__data_805D52A0;
        TObjEneMe3ShinowaMirage__data_805D52A0 = 0;
    }
    if (lbl_80500FEC.textures != 0) {
        mem_free(lbl_80500FEC.textures);
        lbl_80500FEC.textures = 0;
    }
    if (TObjEneMe3ShinowaMirage__data_805D5298 != 0) {
        free_bin_model_request(TObjEneMe3ShinowaMirage__data_805D5298, 1);
        TObjEneMe3ShinowaMirage__data_805D5298 = 0;
    }
}

int TObjEneMe3ShinowaMirage__sub_800E7B74(void* p) { return create__21TObjEneMe3ShinowaRealFv(p); }

void *mem_alloc(u32 size);
extern s32 lbl_8043CE1C[];
extern s32 lbl_8043CE24[];
extern s32 lbl_8043CE2C[];
extern s32 lbl_8043CE34[];
extern DelDepthAnimationBinding lbl_8043CF84;

// Floor resource callback (inferred: load_shared_resources, the TObjEneMe3SinowZoa::load_resources twin):
// loads the shared Shinowa BML, a texture-list copy for the mirage, the per-variant parameter tables,
// the breakup model and the sampled claw-trail points.
void load_shinowa_mirage_resources() {
    NJS_TEXLIST *src;
    s32 n;
    s32 i;
    Info_800E6F0C *info;
    u32 root;
    NJS_CNK_MODEL *cnk;
    AnimationMotion *motion;
    NJS_OBJECT *model;
    f32 step;
    NJS_MOTION *trail;

    TObjEneMe3ShinowaMirage__data_80500FC0.x = 0.0f;
    TObjEneMe3ShinowaMirage__data_80500FC0.y = 0.0f;
    TObjEneMe3ShinowaMirage__data_80500FC0.z = 0.0f;
    if (TObjEneDD::check_v2_mode() != 0) {
        TObjEneMe3ShinowaMirage__data_805D5298 = (BmlResource *)load_enemy_bml_resource_named((s32)shinowa_mirage_resource_descriptor, (s32)"bm_ene_me3_shinowa_a.bml");
    } else {
        TObjEneMe3ShinowaMirage__data_805D5298 = (BmlResource *)load_enemy_bml_resource((u8 *)shinowa_mirage_resource_descriptor);
    }
    src = (NJS_TEXLIST *)TObjEneMe3ShinowaMirage__data_805D5298->models->m_c;
    n = src->nbTexture;
    lbl_80500FEC.nbTexture = n;
    lbl_80500FEC.textures = (NJS_TEXNAME *)mem_alloc(n * sizeof(NJS_TEXNAME));
    for (i = 0; i < n; i++) {
        ((TObjPlayer *)&lbl_80500FEC.textures[i])->copy_vec3(&src->textures[i]);
    }
    for (i = 0; i < 3; i++) {
        lbl_80500FEC.textures[i + 3].texaddr = lbl_80500FEC.textures[i].texaddr;
    }
    for (s32 j = 0; j < 2; j++) {
        lbl_80500FCC[j] = (s32)TLobby::register_boss(lbl_8043CE1C[j]);
    }
    for (s32 j = 0; j < 2; j++) {
        lbl_80500FD4[j] = (s32)TLobby::dispatch_shared_handler_b(lbl_8043CE24[j]);
    }
    for (s32 j = 0; j < 2; j++) {
        lbl_80500FDC[j] = (s32)TLobby::register_object(lbl_8043CE2C[j]);
    }
    for (s32 j = 0; j < 2; j++) {
        TObjEneMe3ShinowaMirage__mirage_info_table[j] = (Info_800E6F0C *)TLobby::dispatch_shared_handler_a(lbl_8043CE34[j]);
    }
    info = TObjEneMe3ShinowaMirage__mirage_info_table[0];
    TObjEneMe3ShinowaMirage::set_slot_min_clamped_value(6, info->unk_C);
    TObjEneMe3ShinowaMirage::set_slot_min_clamped_value(3, info->unk_10);
    TObjEneMe3ShinowaMirage__render_node_index = 0;
    lbl_80500FF4.x = 0.0f;
    lbl_80500FF4.y = 0.0f;
    lbl_80500FF4.z = 0.0f;
    root = TObjEneMe3ShinowaMirage__data_805D5298->models->model;
    cnk = (NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(root, 9))->model;
    if (cnk != NULL) {
        lbl_80501000[0] = (s32 *)(cnk->polygon_list + 2);
    } else {
        lbl_80501000[0] = NULL;
    }
    cnk = (NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(root, 13))->model;
    if (cnk != NULL) {
        lbl_80501000[1] = (s32 *)(cnk->polygon_list + 2);
    } else {
        lbl_80501000[1] = NULL;
    }
    cnk = (NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(root, 38))->model;
    if (cnk != NULL) {
        lbl_80501000[2] = (s32 *)(cnk->polygon_list + 2);
    } else {
        lbl_80501000[2] = NULL;
    }
    motion = TObjEneMe3ShinowaMirage__data_805D5298->motions[shinowa_mirage_motion_param_table[4].motion].motion;
    TUnk_8048FA00 *breakup = (TUnk_8048FA00 *)::operator new(0x10);
    if (breakup != NULL) {
        breakup = TBreakUpMdl::init(breakup, TObjEneMe3ShinowaMirage__data_805D5298->models->model, (s32)motion, motion->frameCount - 1);
    }
    TObjEneMe3ShinowaMirage__data_805D52A0 = breakup;
    {
        Vec first;
        Vec second;
        BmlResource *res = TObjEneMe3ShinowaMirage__data_805D5298;
        s32 idx = shinowa_mirage_motion_param_table[5].motion;
        model = (NJS_OBJECT *)res->models->model;
        first.x = 0.0f;
        first.y = 0.0f;
        first.z = 0.0f;
        second.x = -10.0f;
        second.y = 0.0f;
        second.z = 0.0f;
        trail = (NJS_MOTION *)res->motions[idx].motion;
        TObjEneMe3ShinowaMirage__data_805D52AC = new SampledMotionPoints(2, 16.0f, 26.0f, 0.7f);
        TObjEneMe3ShinowaMirage__data_805D52AC->sample_node_offsets(model, trail, 0x22, &first, &second);
        first.x = 0.0f;
        first.y = 0.0f;
        first.z = 0.0f;
        trail = (NJS_MOTION *)TObjEneMe3ShinowaMirage__data_805D5298->motions[shinowa_mirage_motion_param_table[6].motion].motion;
        step = TObjEneMe3ShinowaMirage__mirage_info_table[0]->unk_C;
        if (step < 0.1f) {
            step = 0.1f;
        }
        second.x = -10.0f;
        second.y = 0.0f;
        second.z = 0.0f;
        TObjEneMe3ShinowaMirage__data_805D52A4 = new SampledMotionPoints(2, 6.0f, 14.0f, step);
        TObjEneMe3ShinowaMirage__data_805D52A4->sample_node_offsets(model, trail, 0x22, &first, &second);
        second.x = 10.0f;
        second.y = 0.0f;
        second.z = 0.0f;
        TObjEneMe3ShinowaMirage__data_805D52A8 = new SampledMotionPoints(2, 17.0f, 23.0f, step);
        TObjEneMe3ShinowaMirage__data_805D52A8->sample_node_offsets(model, trail, 0x15, &first, &second);
    }
    {
        DelDepthAnimationBinding binding = lbl_8043CF84;
        binding.motions = TObjEneMe3ShinowaMirage__data_805D5298->motions;
        TLobby::spawn_npc_enemy(0x26, TObjEneMe3ShinowaMirage__data_805D5298->models->model, (NJS_TEXLIST *)TObjEneMe3ShinowaMirage__data_805D5298->models->m_c, &binding, 8.0f, 0.0f);
        TLobby::spawn_npc_enemy(0x27, TObjEneMe3ShinowaMirage__data_805D5298->models->model, &lbl_80500FEC, &binding, 8.0f, 0.0f);
    }
}

}
