#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/enemy/TObjEneDD_800BB804.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TUnk_80482C58.h"
#include "pso/boss/TBoss2Joint.h"
#include "pso/boss/TBoss2LaserLight.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/misc/TNowLoading.h"
#include "pso/player/TObjPlayer.h"

struct TBJ_8003688C { char pad[0x18]; };
struct VTbj_8003688C : TBJ_8003688C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29();
    virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34();
    virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44();
    virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49();
    virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54();
    virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64();
    virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69();
    virtual void m70(); virtual void m71(); virtual void m72(); virtual void m73(); virtual void m74();
    virtual void m75(); virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83(); virtual void m84();
    virtual void m85(); virtual void m86(); virtual void m87(); virtual void m88(); virtual void m89();
    virtual void m90(); virtual void m91(); virtual void m92(); virtual void m93(); virtual void m94();
    virtual void m95(); virtual void m96(); virtual void m97(); virtual void m98(); virtual void m99();
    virtual void m100(); virtual void m101();
    virtual void m102();
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
    virtual s32 m81();
    virtual void m82();
    virtual void m83();
    virtual s32 m84();
    virtual s32 m85(s16, s32);
    virtual s32 m86();
};

struct RecoveredGlobal_80036FC8___vt__11TBoss2Joint {
    s32 value;
    u8 remaining[0x1A4];
};

struct RecoveredGlobal_80036A90_lbl_80435A68 {
    s32 value;
    u8 remaining[0x1C];
};

struct V3_80037178 { f32 x, y, z; };

struct Obj_80037178 { u8 pad[0x1c]; V3_80037178 ring[20]; s32 idx; };

typedef struct Vec_80037074 {
    f32 x, y, z;
} Vec_80037074;

typedef struct Laser_80037074 {
    u8 pad0[0x1C];
    Vec_80037074 pts[20];
    s32 head;
    s32 cur;
    s32 limit;
    s32 unk118;
    void *ptcl;
    s32 state;
} Laser_80037074;

struct JBase_80036EA8 { char pad[0x18]; };

struct Joint_80036EA8 : JBase_80036EA8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29();
    virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34();
    virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44();
    virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49();
    virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54();
    virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64();
    virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69();
    virtual void m70(); virtual void m71(); virtual void m72(); virtual void m73(); virtual void m74();
    virtual void m75(); virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83(); virtual void m84();
    virtual void m85(s16, s32); virtual void m86(); virtual void m87(); virtual void m88(); virtual void m89();
    virtual void m90(); virtual void m91(); virtual void m92(); virtual void m93(); virtual void m94();
    u8 pad1C[0x24 - 0x1C];
    s32 unk24;
    u8 pad28[0x34 - 0x28];
    s32 unk34;
    u8 pad38[0x2B8 - 0x38];
    s16 hp2B8;
    u8 pad2BA[0x326 - 0x2BA];
    s16 unk326;
    u8 pad328[0x32C - 0x328];
    s16 hp32C;
    u8 pad32E[0x33E - 0x32E];
    s16 unk33E;
    u8 pad340[0x350 - 0x340];
    void *unk350;
    u8 pad354[0x37C - 0x354];
    f32 unk37C;
    u8 pad380[0x38C - 0x380];
    s32 unk38C;
    u8 pad390[4];
    s32 unk394;
    u8 pad398[0x3A0 - 0x398];
    s32 unk3A0;
    f32 unk3A4;
    f32 unk3A8;
    u8 unk3AC[0x10];
};

typedef struct Param_80036EA8 {
    s32 unk0;
    s32 pad4;
    s32 unk8;
    s32 padC;
    s32 unk10;
    s32 pad14;
    u8 unk18[0x1C];
    u8 unk34[1];
} Param_80036EA8;

extern "C" {
void TBoss2Joint__sub_80036940(void *);
extern const f32 lbl_80435A58[4];
extern const u32 lbl_805D8468;
extern const f32 lbl_805D8470;
extern const f32 lbl_805D8478;
s32 add_radar_scaled_marker(void *, int, int, int, f32);
extern const f32 lbl_805D848C;
s32 vfunc_94__9TObjEneDDFv(void *);
s32 vfunc_93__9TObjEneDDFv(void *);
extern const f32 lbl_805D8258;
extern const f32 lbl_805D847C;
extern const f32 lbl_805D8480;
void initialize_enemy_state__9TObjEneDDFv(void *, s32);
extern s32 __vt__11TBoss2Joint[];
extern s32 TBoss2Joint__name;
extern RecoveredGlobal_80036A90_lbl_80435A68 TBoss2Joint__joint_offset_vec4_table;
extern const f32 TBoss2Joint__data_805D8474;
extern const f32 lbl_805D8498;
void push_trail_position__13TBoss2DeRolLeFPvPv(Obj_80037178 *self, V3_80037178 *src);
void *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
s32 register_object__6TLobbyFl(s32);
s32 dispatch_shared_handler_b__6TLobbyFl(s32);
s32 register_boss__6TLobbyFl(s32);
s32 TBoss2Joint_get_shell_max_hp(void);
void reset_hp__9TObjEneDDFv(void *, s32, s32, s32);
void init_model__9TObjEneDDFv(void *, void *, s32);
extern const f32 lbl_805D846C;
extern const f32 lbl_805D8490;
void spawn_offset_particle__13TBoss2DeRolLeFiff(s32 arg0, f32 farg0, f32 farg1);
s32 apply_hp_damage_with_sound__13TBoss2DeRolLeFPvi(s32, s32, u16);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);

__declspec(section ".data") void *TBoss2Joint__param_table[2] = {
    (void *)0x10, (void *)0x10,
};
__declspec(section ".data") void *lbl_80482A58[2] = {
    (void *)0xf, (void *)0xf,
};
void *lbl_80482A60[20] = {
    (void *)0x10, (void *)0x10, (void *)0x43610000, (void *)0x0,
    (void *)0x600, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x42480000, (void *)0x0, (void *)0x0, (void *)0x8003,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
};
#define TBoss2Joint__param_table (*(Param_80036EA8 *)TBoss2Joint__param_table)

void TBoss2Joint__sub_8003688C(u8 *arg0) {
  u32 temp_r5;
  s32 *temp_r4;
  u32 temp_r5_2;
  u8 *temp_r6;
  int new_var;
  u8 *temp_r6_2;
  new_var = ~0xFF000000;
  if ((*((s32 *) (((s8 *) arg0) + 0x38C))) & 1)
  {
    temp_r5 = *((u32 *) (((s8 *) arg0) + 0x3A0));
    temp_r6 = (u8 *) (*((u8 **) (((s8 *) arg0) + 0x398)));
    *((s32 *) (((s8 *) temp_r6) + 0)) = (s32) (((((temp_r5 >> 0x10U) & new_var) | ((temp_r5 << 0x10) & 0xFF000000)) & (~0xFF0000)) | ((temp_r5 << 0x10) & 0xFF0000));
    *((u16 *) (((s8 *) temp_r6) + 0x10)) = (u16) ((*((u16 *) (((s8 *) temp_r6) + 0x10))) | 0x800);
    *((s16 *) (((s8 *) temp_r6) + (-4))) = 0x2517;
    temp_r4 = (s32 *) (*((s32 **) (((s8 *) arg0) + 0x39C)));
    *temp_r4 = ((*temp_r4) & (~0xFF00)) | ((((u32) (*((u32 *) (((s8 *) arg0) + 0x3A0)))) >> 0x10U) & 0xFF00);
    return;
  }
  temp_r5_2 = *((u32 *) (((s8 *) arg0) + 0x3A0));
  temp_r6_2 = (u8 *) (*((u8 **) (((s8 *) arg0) + 0x398)));
  *((s32 *) (((s8 *) temp_r6_2) + 0)) = (s32) (((((temp_r5_2 >> 0x10U) & new_var) | ((temp_r5_2 << 0x10) & 0xFF000000)) & (~0xFF0000)) | ((temp_r5_2 << 0x10) & 0xFF0000));
  *((u16 *) (((s8 *) temp_r6_2) + 0x10)) = (u16) ((*((u16 *) (((s8 *) temp_r6_2) + 0x10))) & 0xFFFFF7FF);
  *((s16 *) (((s8 *) temp_r6_2) + (-4))) = 0x2517;
  *((s32 *) (*((s32 **) (((s8 *) arg0) + 0x39C)))) |= 0xFF00;
}

void TBoss2Joint::call_36A90_with_1() { init_joint_offset(1); }

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TBoss2Joint__sub_80036940(void *arg) {
    Joint_80036EA8 *self = (Joint_80036EA8 *)arg;
    f32 t;
    if (self->unk38C & 1) {
        self->unk3A4 = lbl_805D846C;
        self->unk3A0 = 0;
        return;
    }
    self->unk3A0 = 0xFF000000;
    t = self->unk3A8;
    if (t > lbl_805D846C) {
        f32 a = lbl_805D8470 * t;
        f32 b = lbl_805D8470 * (TBoss2Joint__data_805D8474 - t);
        f32 *c = (f32 *)self->unk3AC;
        self->unk3A0 |= ((u32)(lbl_80435A58[1] * b + c[1] * a) << 16) & 0xFF0000;
        self->unk3A0 |= ((u32)(lbl_80435A58[2] * b + c[2] * a) << 8) & 0xFF00;
        self->unk3A0 |= (u8)(u32)(lbl_80435A58[3] * b + c[3] * a);
        self->unk3A8 -= lbl_805D8478;
        if (self->unk3A8 < lbl_805D846C) {
            self->unk3A8 = lbl_805D846C;
        }
    } else {
        self->unk3A0 |= lbl_805D8468;
    }
}
#pragma pop

typedef char RecoveredGlobal_80036A90_lbl_80435A68_size[sizeof(RecoveredGlobal_80036A90_lbl_80435A68) == 0x20 ? 1 : -1];
void TBoss2Joint::init_joint_offset(s32 arg1) {
    this->m_3a8 = (f32) TBoss2Joint__data_805D8474;
    copy_argb((NJS_ARGB *)((u8 *)&this->unk_3AC), (NJS_ARGB *)((u8 *)&TBoss2Joint__joint_offset_vec4_table.value + (arg1 * 0x10)));
}

struct Ent_80036ACC { s32 a; s32 b; };
struct Obj_80036ACC {
    u8 pad0[0x2B8];
    s16 f2B8;
    u8 pad1[0x32C - 0x2BA];
    s16 f32C;
    u8 pad2[0x38C - 0x32E];
    u32 f38C;
};
void TObjPlayer__sub_8002EA64(void *, void *, void *);
void reload_stats_keep_hp_tp__9TObjEneDDFv(void *, int, int, int);
void *__nw__7TObjectFUl(u32);
void TBoss2Joint__vt102(Obj_80036ACC *self) {
    self->f38C = self->f38C | 1;
    reload_stats_keep_hp_tp__9TObjEneDDFv(self,
        register_boss__6TLobbyFl(((Ent_80036ACC *)&TBoss2Joint__param_table)->b),
        dispatch_shared_handler_b__6TLobbyFl(((Ent_80036ACC *)lbl_80482A58)->b),
        register_object__6TLobbyFl(((Ent_80036ACC *)lbl_80482A60)->b));
    self->f32C = 0x4E20;
    self->f2B8 = 0x4E20;
    {
        void *o = __nw__7TObjectFUl(0x364);
        if (o != NULL) {
            TObjPlayer__sub_8002EA64(o, self, (u8 *)self + 0x38);
        }
    }
}

void TBoss2Joint::vfunc_93() {
    if (*(s32 *)((s8 *)this->m_a4 + 0x18) & 6) {
        vfunc_93__9TObjEneDDFv(this);
        return;
    }
    vfunc_94__9TObjEneDDFv(this);
}

void TBoss2Joint::vfunc_88() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    if (*(f32 *)((s8 *)arg0 + 0x3C) < (lbl_805D8258 - lbl_805D847C)) {
        vfunc_94__9TObjEneDDFv(arg0);
        temp_r3 = (u8 *)this->m_a4;
        *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) & 0xFFFFFFF9);
    } else {
        vfunc_93__9TObjEneDDFv(arg0);
        if (*(f32 *)((s8 *)arg0 + 0x3C) >= lbl_805D8480) {
            this->vfunc_97();
        } else {
            this->vfunc_98();
        }
    }
    ((TObjEneDD *)arg0)->transform_part_positions();
}

void TBoss2Joint::update_position_history() {
    s32 arg0 = (s32)this;
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x2FC));
}
void TBoss2Joint::vfunc_61() {  }

extern const f32 lbl_805D8484;
extern const f32 lbl_805D8488;

void TBoss2Joint::vfunc_62() {
    s32 temp_r31;
    struct TBJ_8003688C *self = (struct TBJ_8003688C *)this;

    temp_r31 = ((TBoss2Joint *)self)->hpmax - ((TBoss2Joint *)self)->hp;
    if (!(((TBoss2Joint *)self)->m_38c & 1)) {
        ((TBoss2Joint *)self)->init_joint_offset(0);
        *(s32 *)((s8 *)self + 0x394) = (s32) (*(s32 *)((s8 *)self + 0x394) - temp_r31);
        if ((s32) *(s32 *)((s8 *)self + 0x394) <= 0) {
            *(s32 *)((s8 *)self + 0x394) = 0;
            ((VTbj_8003688C *)self)->m102();
        }
    } else {
        spawn_offset_particle__13TBoss2DeRolLeFiff((s32)(((u8 *)this) + 0x38), (f32)lbl_805D8484, (f32)lbl_805D8488);
        apply_hp_damage_with_sound__13TBoss2DeRolLeFPvi(*(s32 *)((s8 *)self + 0x10), temp_r31, ((TBoss2Joint *)self)->m_2d4);
    }
    ((TBoss2Joint *)self)->hp = (s16) ((TBoss2Joint *)self)->hpmax;
    clear_attack_receipts();
}

void TBoss2Joint::vfunc_63() { this->actorFlags &= 0xfffff7ff; }
void TBoss2Joint::vfunc_28() {  }

void TBoss2Joint::run_task() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() == 0) {
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)((int) (*(s32 *)((s8 *)arg0 + 0x390))));
        this->vfunc_83();
        if (((VObj_18 *)(arg0))->m84() == 0) {
            ((VObj_18 *)(arg0))->m85(this->mode, 3);
        }
        ((VObj_18 *)(arg0))->m85(this->mode, 0);
        ((TObjEneDD *)arg0)->sub_800BBA0C();
        TBoss2Joint__sub_80036940(arg0);
        update_position_history();
        this->vfunc_88();
        ((TBoss8Dragon *)arg0)->set_player_state_default();
        add_radar_scaled_marker((u8 *)&this->position, -0x5DB4, 1, 1, lbl_805D848C);
    }
}

void *__dt__11TBoss2JointFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TBoss2Joint;
        free_collision_body_parts(arg0);
        __dt__9TObjEneDDFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80036FC8___vt__11TBoss2Joint_size[sizeof(RecoveredGlobal_80036FC8___vt__11TBoss2Joint) == 0x1A8 ? 1 : -1];

#pragma push
#pragma opt_propagation off
struct RecoveredGlobal_80036A90_lbl_80435A68;

s32 TBoss2Joint::init_params() {
    Param_80036EA8 *prm;
    Joint_80036EA8 *self = (Joint_80036EA8 *)this;
    prm = &TBoss2Joint__param_table;
    ((TObjEneDD *)self)->init_position_vectors();
    self->unk34 = 0;
    self->unk24 = 0;
    init_model__9TObjEneDDFv(self, prm->unk34, 1);
    reset_hp__9TObjEneDDFv(self, register_boss__6TLobbyFl(prm->unk0), dispatch_shared_handler_b__6TLobbyFl(prm->unk8), register_object__6TLobbyFl(prm->unk10));
    self->hp32C = 0x4E20;
    self->hp2B8 = 0x4E20;
    ((TObjEneDD *)self)->check_state_flag_2();
    self->unk350 = prm->unk18;
    self->unk33E = self->hp2B8;
    self->unk37C = lbl_805D8490;
    self->m94();
    self->unk326 = 0;
    self->m85(self->unk326, 4);
    self->unk38C = 0;
    self->unk394 = TBoss2Joint_get_shell_max_hp();
    self->unk3A0 = -1;
    self->unk3A4 = TBoss2Joint__data_805D8474;
    self->unk3A8 = lbl_805D846C;
    copy_argb((NJS_ARGB *)self->unk3AC, (NJS_ARGB *)&TBoss2Joint__joint_offset_vec4_table);
}
#pragma pop

u8 *TBoss2Joint__ct(u8 *boss2_joint, u8 *arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6) {
    TObjEneDD__ct(boss2_joint);
    *(s32 **)((s8 *)boss2_joint + 0x18) = &(*(RecoveredGlobal_80036FC8___vt__11TBoss2Joint *)&__vt__11TBoss2Joint).value;
    *(s32 *)((s8 *)boss2_joint + 0) = (s32) TBoss2Joint__name;
    ((TObjEneDD *)boss2_joint)->init_common_from(arg1);
    ((TBoss2Joint *)boss2_joint)->entity_id = arg2;
    *(s16 *)((s8 *)boss2_joint + 0x2C) = arg3;
    *(s32 *)((s8 *)boss2_joint + 0x390) = arg4;
    *(s32 *)((s8 *)boss2_joint + 0x398) = arg5;
    *(s32 *)((s8 *)boss2_joint + 0x39C) = arg6;
    initialize_enemy_state__9TObjEneDDFv(boss2_joint, 0x2D);
    ((TBoss2Joint *)boss2_joint)->init_params();
    return boss2_joint;
}

void TBoss2Joint::apply_poison_status() {  }
void TBoss2Joint::apply_paralysis() {  }
void TBoss2Joint::apply_slow_status() {  }
void TBoss2Joint::apply_confusion_status() {  }
void TBoss2Joint::apply_movement_ailment(s32) {  }
void TBoss2Joint::apply_shock_status() {  }
void TBoss2Joint::clear_harmful_statuses() {  }

void TUnk_80482C58::run_task() {
    Laser_80037074 *self = (Laser_80037074 *)this;
    if (self->ptcl == NULL) {
        self->ptcl = spawn_continuous_particle_effect_with_flags(self->pts, self->unk118, 0x40);
        if (self->ptcl != NULL) {
            ((TParticleCtrl *)(self->ptcl))->enable();
        }
    } else {
        switch (self->state) {
        case 0:
            if (self->head >= self->limit) {
                self->state = 1;
                self->cur = 0;
            }
            ((TParticleCtrl *)(self->ptcl))->enable();
            break;
        case 1:
            ((TNowLoading *)(self->ptcl))->copy_pos(&self->pts[self->cur]);
            self->cur++;
            if (self->cur >= 20) {
                self->cur = 0;
            }
            if (self->cur == self->head) {
                self->state = 2;
            }
            break;
        case 2:
            ((TParticleCtrl *)(self->ptcl))->enable();
            break;
        }
    }
}

void push_trail_position__13TBoss2DeRolLeFPvPv(Obj_80037178 *self, V3_80037178 *src) {
    VecCopy((Vec *)&self->ring[self->idx], (const Vec *)src);
    self->ring[self->idx].y += lbl_805D8498;
    self->idx++;
    if (self->idx >= 20) {
        self->idx = 0;
    }
}

}
