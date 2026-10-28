#include "types.h"
#include "pso/object/TObjMesBase.h"
#include "pso/misc/TMotorcycle.h"
#include "pso/object/TObjMesBase.h"
#include "pso/object/TObjMotion.h"

#include "pso/TObject.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/player/TObjPlayer.h"

struct Mc_80194EC4 { u8 pad0[0x68]; f32 f68; u8 pad6C[0x50]; s32 fBC; };

struct Pair_80194AEC { const char *s[2]; };

struct Mes_80194AEC { u8 pad0[0x84]; s32 f84; u8 pad88[4]; s32 f8C; u8 pad90[0x24]; s32 fB4; s32 fB8; };

extern "C" {
extern void* quest_mission_manager;
extern void* quest_area_manager;
extern void* tl_00;
void* __nw__7TObjectFUl(unsigned long);
u8 *__ct__12TQuestThreadFv(u8 *arg0, s32 arg1, s32 arg2);
f32 fabs_float(f32);
void debug_printf_at(int, void *, ...);
extern s32 lbl_80445DF4[];
extern u8 lbl_80445E08[];
extern Pair_80194AEC lbl_80445D94[];
extern u8 lbl_80445D9C[];
extern u8 lbl_80445DAC[];
s32 TMotorcycle__vt8(s32 arg0, f32 farg0, f32 farg1);
void *TObjMesBase__ct(TObjMesBase *arg0, s32 arg1, s32 arg2);
void *__dt__11TObjMesBaseFv(void *arg0, s16 arg1);
s32 __ct__14TObjCollidableFP7TObject();
void __dl__7TObjectFPv(void *);
f32 xz_distance_squared(s32, s32);
s32 update_object_view_visibility__8TObjBaseFff(s32, f32, f32);

void TObjMesBase::debug_draw_label() {
    Mes_80194AEC *arg0 = (Mes_80194AEC *)this;
    arg0->fB4 = arg0->f84;
    arg0->fB8 = arg0->f8C;
    if (arg0->fB8 < 0) {
        arg0->fB8 = 0;
    }
    if (arg0->fB8 > 1) {
        arg0->fB8 = 1;
    }
    Pair_80194AEC names = lbl_80445D94[0];
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, lbl_80445D9C, arg0->fB4);
    debug_printf_at(0x130022, lbl_80445DAC, names.s[arg0->fB8]);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TObjMesBase::interact(s32) {
    s32 label = messageLabel;
    if (label != 0) {
        void* root = 0;
        switch (messageBank) {
        case 0: root = quest_mission_manager; break;
        case 1: root = quest_area_manager; break;
        }
        switch (messagePhase) {
        case 0:
            if (!messageChild && label != 0 && root) {
                void* child = __nw__7TObjectFUl(0x194);
                if (child) child = __ct__12TQuestThreadFv((u8 *)child, (s32)root, messageLabel);
                messageChild = child;
                if (messageChild) ((TObject *)messageChild)->set_parent((TObject *)tl_00);
                messagePhase = 1;
            }
            break;
        case 1: break;
        }
    }
}
void TObjMesBase::clear_ref_if_destroyed() {
    void *p = this->messageChild;
    if ((p != 0) && (((TObject *)p)->all_parents_unqueued_for_destruction() == 0)) {
        this->messageChild = 0U;
        this->messagePhase = 0;
    }
}
void TObjMesBase::vfunc_14() {  }

void TObjMesBase::run_task() {

    switch (this->messagePhase) {
    case 0:
        this->vfunc_14();
        return;
    case 1:
        this->clear_ref_if_destroyed();
        return;
    }
}

extern s32 __vt__11TObjMesBase[];

}
TObjMesBase::~TObjMesBase() {

}
extern "C" {

extern s32 TObjMesBase__class_name;

void *TObjMesBase__ct(TObjMesBase *mes_base, s32 arg1, s32 arg2) {
    __ct__14TObjCollidableFP7TObject();
    *(s32 **)((s8 *)mes_base + 0x18) = __vt__11TObjMesBase;
    *(s32 *)((s8 *)mes_base + 0) = (s32) TObjMesBase__class_name;
    mes_base->apply_object_set_data((void *)arg2);
    mes_base->messageLabel = (s32) mes_base->set_params[0];
    mes_base->messageBank = (s32) mes_base->set_params[2];
    if ((s32) mes_base->messageBank < 0) {
        mes_base->messageBank = 0;
    }
    if ((s32) mes_base->messageBank > 1) {
        mes_base->messageBank = 1;
    }
    *(s32 *)((s8 *)mes_base + 0xAC) = 0;
    mes_base->messagePhase = 0;
    return mes_base;
}

extern s32 camera_ctrl_instance;

s32 TMotorcycle__vt8(s32 arg0, f32 farg0, f32 farg1) {
    if (xz_distance_squared(camera_ctrl_instance + 0x178, arg0 + 0x38) < (farg1 * farg1)) {
        return 1;
    }
    return update_object_view_visibility__8TObjBaseFff(arg0, farg0, farg1);
}
void TMotorcycle::debug_draw_label() {
    Mc_80194EC4 *arg0 = (Mc_80194EC4 *)this;
    ((TObjMesBase *)arg0)->TObjMesBase::debug_draw_label();
    arg0->fBC = (s32)fabs_float(arg0->f68);
    arg0->fBC = arg0->fBC % 2;
    arg0->fBC = lbl_80445DF4[arg0->fBC];
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x13001C, lbl_80445E08);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

}
