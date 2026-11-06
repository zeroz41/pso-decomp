#ifndef PSO_BOSS_BARBARAY_TBOSS7DEROLLEC_H
#define PSO_BOSS_BARBARAY_TBOSS7DEROLLEC_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

struct TBoss7DeRolLeC : public TObjEneDD_ST {
    virtual ~TBoss7DeRolLeC();
    void update_projectile_spawns();
    virtual void run_task();
    virtual void render();
    void update_or_dispatch();
    void flee_if_disturbed();
    void set_state_and_send(s32);
    u8 sub_802ECB10();
    void sub_802ECAA4();
    void advance_action_sequence();
    void sub_802E8234();
    void set_flag_800();
    virtual void vfunc_88();
    virtual void render_shadows();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void clear_harmful_statuses();
    void apply_shock_status();
    void apply_movement_ailment(s32);
    void apply_confusion_status();
    void apply_slow_status();
    void apply_paralysis();
    void apply_poison_status();
    void vfunc_28();
    u8 pad_374[0x18];
    u16 unk_38C;
    u8 pad_38E[0x29A];
    s32 unk_628;                  // state flags (0x4, 0x8, 0x40, 0x80, 0x8000 tested)
    u8 pad_62C[0x64];             // 0x630/0x650/0x670: three 0x20 blocks (TBoss2DeRolLe::init_resources / free_if_positive)
    TObject unk_690;              // embedded task group: the ctor builds it with TObject(TObject *), run_task/render walk it
    s32 unk_6AC;
    u8 pad_6B0[0x4];
    s32 action_index;             // step in lbl_804E3C2C[difficulty][], advanced by advance_action_sequence
    s32 unk_6B8;
    u8 pad_6BC[0x8];
    s32 unk_6C4;
    u8 pad_6C8[0xC];
    s32 unk_6D4;                  // mem_alloc'd buffer (freed by the destructor)
    s32 unk_6D8;                  // mem_alloc'd buffer (freed by the destructor)
    u8 pad_6DC[0x10];             // TObject *[4], released by the destructor
    Vec unk_6EC;
    u8 pad_6F8[0x4];
    s32 unk_6FC;
    s32 unk_700;
    u8 pad_704[0xA0];             // 0x708/0x71C/0x720/0x784/0x788[6] TObject *, 0x718 AreaAttackHistory * (destructor)
    TObject *crawfish_parent;     // the group spawned crawfish are children of
    u8 pad_7A8[0x4];
    u32 unk_7AC;
    u8 pad_7B0[0x24];
    void set_field_38(s32 v);
    static void run_exit_callbacks();
    static void *create(void *arg0);
};

typedef char TBoss7DeRolLeC_size[sizeof(TBoss7DeRolLeC) == 0x7D4 ? 1 : -1];

// Light pool element (0x38 bytes): TObjPlayer__sub_802EE574 initialises 11 of them as a linked free list.
struct Light_802EE574 {
    s32 type;
    s32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    Light_802EE574 *next;
    s32 f30;
    u8 pad34[4];
};

// Globals of the De Rol Le C translation unit (802E7888-802EE814; .sbss/.bss).
extern "C" {
extern u8 *lbl_805D6918;              // resource bundle loaded by TObjPlayer__sub_802EE574
extern s32 boss7_derolle_c_motion_id;
extern s32 lbl_805D6920;
extern s32 lbl_805D6924;
extern s32 lbl_805D6928;
extern s32 lbl_805D692C;
extern s32 lbl_805D6930;
extern s32 lbl_805D6934;
extern u32 boss7_joint_state;         // the destructor clears it when it holds this object
extern u8 *lbl_805D693C;
extern s32 *lbl_805D6940;
extern Light_802EE574 boss7_derolle_light_pool[11];

void TObjPlayer__sub_802ED984(void);
void TObjPlayer__sub_802EE574(void);
}

// Functions defined in Boss7DeRolLeCBehavior.cpp.
struct TObjEneDD;
extern "C" {
void TBoss7DeRolLeC__dispatch_state(u8 *arg0, u32 arg1, u32 arg2);
void TBoss7DeRolLeC__handle_crawfish_spawn_state(u8 *self, u32 event, s32 variant);
void TBoss7DeRolLeC__sub_802EC994(void *p);
s32 TBoss7Joint_get_shell_max_hp(void);
void TBoss7LaserPtcl__sub_802E8FCC(u8 *arg0, u32 arg1);
void TBoss7LaserPtcl__sub_802ECE28(u8 *arg0);
void TBoss7PhotonBullet__sub_802ED5A0(void *arg0, int arg1);
void TObjFish__sub_802E8528(void *o, u32 k);
void TObjFish__sub_802E8584(void *o, u32 k);
void TObjFish__sub_802E85E0(u8 *arg0, u32 arg1, s32 arg2);
void TObjFish__sub_802E88F8(u8 *arg0, u32 arg1);
void TObjFish__sub_802E8990(u8 *arg0, u32 arg1);
void TObjFish__sub_802E8E34(u8 *arg0, u32 arg1);
void TObjFish__sub_802E8EEC(u8 *arg0, u32 arg1, s32 _w2);
void TObjFish__sub_802E9458(u8 *arg0, u32 arg1);
void TObjFish__sub_802E95F8(u8 *arg0, u32 arg1, s32 arg2);
void TObjFish__sub_802E9DBC(u8 *arg0, u32 arg1, s32 arg2);
void TObjFish__sub_802EA4D8(u8 *arg0, u32 arg1);
void TObjFish__sub_802EAAC8(u8 *arg0, u32 arg1, s32 arg2, s32 arg3);
void TObjFish__sub_802EBBC8(u8 *arg0, u32 arg1);
void TObjFish__sub_802EBE50(void *o, u32 k);
void TObjFish__sub_802EC32C(void);
void TObjFish__sub_802EC468(s32 arg0, f32 farg0, f32 farg1);
f32 TObjFish__sub_802ED3E4(u8 *arg0);
void TObjFish__sub_802ED4AC(u8 *arg0, s32 arg1);
void TObjPlayer__sub_802E7F30(void *unused, s32 arg1);
void TObjPlayer__sub_802E80A0(void);
void render__14TBoss7DeRolLeCFv(u8 *unused);
void TObjPlayer__sub_802E8274(void);
void fn_802EC52C(s32 arg0, s32 arg1);
void fn_802EC9A4(void *arg0, void *arg1);
void fn_802EC9F0(TObjEneDD *arg0, void *arg1);
void free_laser_light__15TBoss7LaserPtclFv(void *arg0);
}
void handle_6xA9_barba_ray_boss_actions(void *arg0);
void handle_6xAA_barba_ray_boss_actions(void *arg0);
extern "C" {
void queue_boss_effect__10TObjPlayerFPv(void *a0);
void release_laser_light__15TBoss7LaserPtclFPv(void *arg0);
void set_swim_direction__8TObjFishFPv(void *arg0);
void spawn_particle_201__8TObjFishFii(s32 arg1, s32 arg2);
}

#endif
