#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/misc/TOComputerMachine01_8023DD0C.h"
#include "pso/player/TObjPlayer_800A0408.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TUnk_80490470.h"
#include "pso/enemy/TObjEneBalClaw.h"
#include "pso/enemy/TObjEneBalClawClaw.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/misc/TLobby.h"
#include "pso/system/BmlResourceDescriptor.h"

struct RecoveredGlobal_8008DB6C___vt__14TObjEneBalClaw { s32 value; u8 remaining[0x148]; };
typedef char RecoveredGlobal_8008DB6C___vt__14TObjEneBalClaw_size[sizeof(RecoveredGlobal_8008DB6C___vt__14TObjEneBalClaw) == 0x14C ? 1 : -1];

struct Ent_8008D68C { s16 *plist; s16 model_index; s16 part_index; s16 a; s16 b; s16 c; s16 d; };

struct BalClawModelEntry { u32 flags; u32 m_4; u32 model; u32 m_c; };
struct BalClawResource { u8 pad0[0x42C]; BalClawModelEntry *models; };
struct BalClawModel { void *vlist; s16 *plist; };
struct BalClawObject { u32 evalflags; BalClawModel *model; };

static const char balclaw_body_model[] = "re6_b_bal_body.nj";
static const char balclaw_bcbody_model[] = "re6_b_bcbody.nj";
static const char balclaw_claw_body_model[] = "re6_b_claw_body.nj";
static const char balclaw_bal_attack_motion[] = "balattack_re6_b_bal_body.njm";
static const char balclaw_bal_comb_motion[] = "balcomb_re6_b_bal_body.njm";
static const char balclaw_bal_damage_motion[] = "baldamage_re6_b_bal_body.njm";
static const char balclaw_bal_die_motion[] = "baldie_re6_b_bal_body.njm";
static const char balclaw_bal_shout_motion[] = "balshout_re6_b_bal_body.njm";
static const char balclaw_bal_wait_motion[] = "balwait_re6_b_bal_body.njm";
static const char balclaw_bc_attack_motion[] = "bcattack_re6_b_bcbody.njm";
static const char balclaw_bc_damage_motion[] = "bcdamage_re6_b_bcbody.njm";
static const char balclaw_bc_die_motion[] = "bcdie_re6_b_bcbody.njm";
static const char balclaw_bc_wait_motion[] = "bcwait_re6_b_bcbody.njm";
static const char balclaw_cl_attack_motion[] = "clattack_re6_b_claw_body.njm";
static const char balclaw_cl_damage_motion[] = "cldamage_re6_b_claw_body.njm";
static const char balclaw_cl_die_motion[] = "cldie_re6_b_claw_body.njm";
static const char balclaw_cl_lturn_motion[] = "cllturn_re6_b_claw_body.njm";
static const char balclaw_cl_rturn_motion[] = "clrturn_re6_b_claw_body.njm";
static const char balclaw_cl_wait_motion[] = "clwait_re6_b_claw_body.njm";
static const char balclaw_bml[] = "bm_ene_balclaw.bml";
static const char balclaw_class_name_text[] = "TObjEneBalClaw";

static const char *balclaw_model_names[] = {
    balclaw_body_model, balclaw_bcbody_model, balclaw_claw_body_model, NULL,
};
static const char *balclaw_motion_names[] = {
    balclaw_bal_attack_motion, balclaw_bal_comb_motion, balclaw_bal_damage_motion, balclaw_bal_die_motion,
    balclaw_bal_shout_motion, balclaw_bal_wait_motion, balclaw_bc_attack_motion, balclaw_bc_damage_motion,
    balclaw_bc_die_motion, balclaw_bc_wait_motion, balclaw_cl_attack_motion, balclaw_cl_damage_motion,
    balclaw_cl_die_motion, balclaw_cl_lturn_motion, balclaw_cl_rturn_motion, balclaw_cl_wait_motion,
    NULL,
};
static BmlResourceDescriptor balclaw_resource_descriptor = {
    balclaw_bml, balclaw_model_names, balclaw_motion_names, 3, 16,
};
s32 balclaw_motion_model_index[16] = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2 };
static Ent_8008D68C balclaw_parts[7] = {
    { NULL, 0, 1, 8, 0, 1, 0 },
    { NULL, 1, 1, 8, 0, 2, 0 },
    { NULL, 1, 0x1D, 8, 0, 2, 0 },
    { NULL, 1, 0x27, 8, 0, 2, 0 },
    { NULL, 1, 0x31, 8, 0, 2, 0 },
    { NULL, 1, 0x3B, 8, 0, 2, 0 },
    { NULL, 2, 1, 8, 0, 1, 0 },
};
static s32 balclaw_part_base[4] = { 0x1C, 0x26, 0x30, 0x3A };
const char *balclaw_class_name = balclaw_class_name_text;

struct V_8008D700 { f32 x, y, z; };

struct O_8008D700 { u8 pad0[0x30]; u32 flags; u8 pad34[0x378]; f32 f3ac; f32 f3b0; f32 f3b4; u8 pad3b8[4]; f32 f3bc; };

struct Obj_8008D79C { u8 pad0[0x388]; s32 flags; u8 pad38C[0x3B8 - 0x38C]; s32 f3B8; f32 f3BC; };

extern "C" {
u8 *__ct__15TObjEnemyCustomFP7TObject(u8 *arg0);
extern s32 __vt__14TObjEneBalClaw[];
extern s32 balclaw_last_shared_update_frame;
extern s32 actor_frame_tick;
f32 sin_table_lookup(s32);
void TLobby__sub_8001FE7C(void*, int);
void __dl__7TObjectFPv(void *);
void *__dt__15TObjEnemyCustomFv(void *arg0, s16 arg1);

void TObjEneBalClaw__sub_8008D68C(void) {
    s32 i;
    if (balclaw_last_shared_update_frame != actor_frame_tick) {
        balclaw_last_shared_update_frame = actor_frame_tick;
        for (i = 0; i < 7; i++) {
            Ent_8008D68C *e = &balclaw_parts[i];
            TObjPlayer__sub_8023DEE0(e->plist, e->a, e->b, e->c);
        }
    }
}

void TObjEneBalClaw::render_scaled(s32 arg1) {
    O_8008D700 *arg0 = (O_8008D700 *)this;
    f32 a;
    f32 t;
    if (!(this->actorFlags & 0x800) && arg1 != 0) {
        a = this->m_3ac;
        t = 1.0f - (0.5f * ((this->m_3b4 + arg0->f3bc) - a)) * (1.0f / (arg0->f3b0 - a));
        V_8008D700 v = { 0.0f, 0.0f, 0.0f };
        v.x = t;
        v.y = t;
        v.z = t;
        ((TObjEnemy *)arg0)->render_with_position_override((u8 *)&v, 0);
    }
}

void TObjEneBalClaw::update_wobble() {
    Obj_8008D79C *arg0 = (Obj_8008D79C *)this;
    if (arg0->flags & 0x20000) {
        arg0->f3B8 = arg0->f3B8 + 0x200;
        arg0->f3BC = 5.0f * sin_table_lookup(arg0->f3B8);
        return;
    }
    arg0->f3BC = (arg0->f3BC - 0.2f > 0.0f) ? arg0->f3BC - 0.2f : 0.0f;
}

void TObjEneBalClaw::update_claw_angle() {
    f32 temp_f0_2;
    f32 temp_f1_2;
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r4;

    if (!(this->actorFlags & 0x800)) {
        temp_r4 = this->bodies;
        *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFFFFFFF9);
        if (this->m_388 & 0x10000) {
            if (this->m_3b4 < this->m_3b0) {
                this->m_3b4 += 1.0f;
                return;
            }
            this->m_3b4 = this->m_3b0;
            temp_r3 = this->bodies;
            *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) | 4);
            return;
        }
        temp_f1_2 = this->m_3b4;
        temp_f0_2 = this->m_3ac;
        if (temp_f1_2 > temp_f0_2) {
            this->m_3b4 = (f32) (temp_f1_2 - 1.0f);
            return;
        }
        this->m_3b4 = temp_f0_2;
        temp_r3_2 = this->bodies;
        *(s32 *)((s8 *)temp_r3_2 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3_2 + 0x18) | 2);
    }
}

extern u32 lbl_805D4F20;

void TObjEneBalClaw::vfunc_62() {
    u8 *arg0 = (u8 *)this;
    ((TObjEneMe1GiGue *)arg0)->set_state(4);
    this->m_388 = (s32) (this->m_388 | 1);
}

void TObjEneBalClaw::release_global_805D4F20() {
    if ((u32) lbl_805D4F20 != 0U) {
        TLobby__sub_8001FE7C((void*)lbl_805D4F20, 1);
        lbl_805D4F20 = 0U;
    }
}

extern BalClawObject *lbl_805006F8[4][11];
extern void *lbl_805007A8[];
extern void *lbl_805007B0[];
extern void *lbl_805007B8[];
extern void *lbl_805007C0[];
extern void *lbl_805D4F28[];
extern void *lbl_805D4F2C[];
extern void *lbl_805D4F30[];
extern void *lbl_805D4F34[];
u8 *load_resource_from_descriptor(void *, s32, BmlResourceDescriptor *, s32, s32, s32);
u32 get_bml_model(u32, s32);

void TObjEneBalClaw__sub_8008D924(void) {
    Ent_8008D68C *e;
    BalClawObject *part;
    u32 model;
    s32 k;
    s32 base;
    s32 count;
    u8 *p;
    s32 j;
    s32 m;
    s32 n;
    p = (u8 *)::operator new(0x440);
    if (p != NULL) {
        p = load_resource_from_descriptor(p, 1, &balclaw_resource_descriptor, 0, 0, 0);
    }
    lbl_805D4F20 = (u32)p;
    model = ((BalClawResource *)p)->models[1].model;
    for (k = 0; k < 4; k++) {
        base = balclaw_part_base[k];
        count = 0;
        for (j = 0; j < 10; j++) {
            part = (BalClawObject *)find_model_node(model, base + j);
            if (part != NULL && !(part->evalflags & 8)) {
                lbl_805006F8[k][count] = part;
                count++;
            }
        }
        lbl_805006F8[k][count] = NULL;
    }
    for (m = 0; m < 7; m++) {
        e = &balclaw_parts[m];
        e->plist = ((BalClawObject *)find_model_node(get_bml_model(lbl_805D4F20, e->model_index), e->part_index))->model->plist;
    }
    for (n = 0; n < 2; n++) {
        lbl_805007A8[n] = TLobby::register_boss(31);
        lbl_805007B0[n] = TLobby::dispatch_shared_handler_b(31);
        lbl_805007B8[n] = TLobby::register_object(31);
        lbl_805007C0[n] = TLobby::dispatch_shared_handler_a(31);
    }
    for (n = 0; n < 1; n++) {
        lbl_805D4F28[n] = TLobby::register_boss(32);
        lbl_805D4F2C[n] = TLobby::dispatch_shared_handler_b(32);
        lbl_805D4F30[n] = TLobby::register_object(32);
        lbl_805D4F34[n] = TLobby::dispatch_shared_handler_a(32);
    }
}

void *__dt__14TObjEneBalClawFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TObjEneBalClaw;
        __dt__13TUnk_80490470Fv((s8 *)arg0 + 0x390, -1);
        __dt__15TObjEnemyCustomFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TObjEneBalClaw__ct(TObjEneBalClaw *ene_bal_claw) {
    __ct__15TObjEnemyCustomFP7TObject((u8 *)ene_bal_claw);
    *(s32 **)((s8 *)ene_bal_claw + 0x18) = &(*(RecoveredGlobal_8008DB6C___vt__14TObjEneBalClaw *)&__vt__14TObjEneBalClaw).value;
    ((TUnk_80490470 *)((u8 *)ene_bal_claw + 0x390))->init_vtable_and_field18();
    ene_bal_claw->m_name = balclaw_class_name;
    ((TObjChara *)ene_bal_claw)->add_flags_2e4(8);
    ene_bal_claw->actorFlags = (s32) (ene_bal_claw->actorFlags | 0x40000);
    ene_bal_claw->m_3b8 = 0;
    ene_bal_claw->m_3bc = 0.0f;
    ene_bal_claw->clear_attack_flag();
    ene_bal_claw->m_388 = (s32) (ene_bal_claw->m_388 | 0x20000);
    return (u8 *)ene_bal_claw;
}

void TObjEneBalClaw::vfunc_61() {  }
void TObjEneBalClaw::vfunc_59() {  }
s32 TObjEneBalClaw::is_target_in_attack_range() { return 0; }
void TObjEneBalClaw::clear_attack_flag() { this->m_388 &= 0xfffeffff; }
void TObjEneBalClawClaw__sub_8008DC14(void) {  }

}
