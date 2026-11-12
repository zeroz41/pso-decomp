#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/object/TObjComputer.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/container/TObjContainerAbeEnemy.h"
#include "pso/map/FloorArea.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/object/key/TOKeyAncient01.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#define CAT2(a, b) a##b
#define CAT(a, b) CAT2(a, b)
#define PADV4 virtual void CAT(pa, __LINE__)(); virtual void CAT(pb, __LINE__)(); virtual void CAT(pc, __LINE__)(); virtual void CAT(pd, __LINE__)();
#include "pso/object/TObjChip.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/object/container/TObjContainerBase.h"
#include "pso/object/container/TObjContainerItem.h"
#include "pso/ui/window/TWindowKeyBoardHard_801FBA48.h"
#include "pso/unk/text_80087278.h"
#include "pso/object/container/TObjContainerNoItem.h"
#include "pso/object/container/TObjContainerEnemy.h"
#include "pso/unk/text_8018A150.h"
#include "pso/object/base/TObjChara.h"
#include "pso/item/TItem.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/task/TObject.h"
#include "pso/object/fence/TLazerFenceSw.h"
#include "pso/camera/CameraDistanceFade.h"
#include "pso/object/cave/TOAirconCave01.h"
#include "pso/unk/text_8018A3E0.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TMotorcycle.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/object/seabed/TObjSeabedSuisoBrakable.h"
#include "pso/object/container/TContainerAncient01.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/MatrixOps.h"
#include "pso/ui/window/TWindowKeyBoardHard_801FBA48.h"
#include "pso/unk/text_8018A150.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjChip.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/unk/text_803D853C.h"

struct Obj_80188884 { u8 pad0[0x38]; u8 pos[0x28]; s32 id; u8 pad1[0x326 - 0x64]; s16 state; };
struct Obj_80188814 { u8 pad0[0x38]; u8 pos[0x4c]; s32 id; };
struct Obj_80188768 { u8 pad0[0x1C]; u16 f1C; u8 pad1[0x62]; u32 f80; s32 f84; };
struct Pkt_80188768 { u16 a; u16 b; s32 c; s32 d; s32 e; };
struct Vec_8018860C { f32 x, y, z; };
struct Obj_8018860C {
    u8 pad[0x38];
    Vec_8018860C pos;
    u8 pad44[0x326 - 0x44];
    s16 state;
};
struct RecoveredGlobal_801889B8___vt__21TObjContainerAbeEnemy {
    s32 value;
    u8 remaining[0x148];
};
struct Obj_80188C8C { u8 pad0[0x38]; u8 pos[0x28]; s32 id; u8 pad1[0x326 - 0x64]; s16 state; };
struct Obj_80188B3C { u8 pad[0x38]; f32 x, y, z; };
struct RecoveredGlobal_80188DC0___vt__17TObjContainerBase {
    s32 value;
    u8 remaining[0x148];
};
struct RecoveredGlobal_801897A4___vt__18TObjContainerEnemy {
    s32 value;
    u8 remaining[0x148];
};
struct Obj_8018990C { u8 pad[0x38]; f32 x, y, z; u8 pad44[0x326 - 0x44]; s16 f326; };
struct RecoveredGlobal_8018925C___vt__19TObjContainerNoItem {
    s32 value;
    u8 remaining[0x148];
};
struct Obj_801895A4 { u8 pad0[0x38]; u8 pos[0x4c]; s32 id; };
struct Obj_801894F8 { u8 pad0[0x1C]; u16 f1C; u8 pad1[0x62]; u32 f80; s32 f84; };
struct Pkt_801894F8 { u16 a; u16 b; s32 c; s32 d; s32 e; };
struct CE_80189614 { u8 pad[0x34]; s32 f34; u8 f38[0x28]; s32 f60; u8 pad2[0x326 - 0x64]; s16 mode; };
struct Box_80189A50 {
    u8 pad00[0x34];
    s32 model;
    u8 pos[0x28];
    s32 rot;
    u8 pad64[0x326 - 0x64];
    s16 state;
};
struct RecoveredGlobal_80189BE0___vt__17TObjContainerItem {
    s32 value;
    u8 remaining[0x148];
};
struct Item_80189E3C { u8 pad[0x30]; s32 data[3]; };
struct Obj_80189E3C {
    u8 pad[0x68];
    f32 x68;
    u8 pad6c[0x84 - 0x6C];
    s32 data[3];
    u8 pad90[0x360 - 0x90];
    s32 x360;
};
struct Base_8018A0B4 { char pad[0x18]; };
struct VObj_8018A0B4 : Base_8018A0B4 {
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
    virtual void m20(s32, f32);
};
struct SubBase_80189F24 { u8 pad[0x14]; };
struct Sub_80189F24 : SubBase_80189F24 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    u8 pad[0x24 - 0x18];
};
struct VBase_80189F24 { u8 pad[0x18]; };
struct Obj_80189F24 : VBase_80189F24 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
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
    u8 pad1c[0x38 - 0x1C];
    f32 pos[3];
    u8 pad44[0x334 - 0x44];
    f32 x334;
    f32 x338;
    u8 pad33c[0x340 - 0x33C];
    Sub_80189F24 sub;
    s32 x364;
};
struct RecoveredGlobal_8018A150_lbl_804B6C24 { s32 value; u8 remaining[0x148]; };

struct ForestBoxCollisionBody {
    f32 center[3];
    f32 radius;
    f32 height;
    u32 unknown_14;
    u32 flags;
    u32 unknown_1c[4];
};
typedef char ForestBoxCollisionBody_size[sizeof(ForestBoxCollisionBody) == 0x2C ? 1 : -1];

#pragma push
#pragma readonly_strings on
static const char *fe_obj_hako01_hahen02_model_names[4] = {
    "fe_obj_hako01_hahen02.gj", "fs_obj_hako01.gj", "fs_obj_hako01_hahen01.gj", NULL,
};
const char *fe_obj_hako01_hahen02_motion_names[1] = { NULL };
static BmlResourceDescriptor fe_obj_hako01_hahen02_resource_descriptor = {
    "fe_obj_hako01_hahen02.bml", fe_obj_hako01_hahen02_model_names, fe_obj_hako01_hahen02_motion_names, 3, 0,
};

static const char *fe_obj_con_hahen1_model_names[5] = {
    "fe_obj_con_hahen1.gj", "fe_obj_con_hahen2.gj", "fs_obj_con_body.gj", "fs_obj_con_crush1.gj", NULL,
};
const char *fe_obj_con_hahen1_motion_names[1] = { NULL };
static BmlResourceDescriptor fe_obj_con_hahen1_resource_descriptor = {
    "fe_obj_con_hahen1.bml", fe_obj_con_hahen1_model_names, fe_obj_con_hahen1_motion_names, 4, 0,
};

static const char *bm_obj_seabed_con_model_names[4] = {
    "obj_o_sea_container_hahen04.gj", "obj_o_sea_container.gj", "obj_o_sea_container_hahen03.gj", NULL,
};
const char *bm_obj_seabed_con_motion_names[1] = { NULL };
static BmlResourceDescriptor bm_obj_seabed_con_resource_descriptor = {
    "bm_obj_seabed_con.bml", bm_obj_seabed_con_model_names, bm_obj_seabed_con_motion_names, 3, 0,
};

static const char *bm_obj_seabed_con_rare_model_names[4] = {
    "obj_o_sea_container_hahen01_r.gj", "obj_o_sea_container_hahen02_r.gj", "obj_o_sea_container_r.gj", NULL,
};
const char *bm_obj_seabed_con_rare_motion_names[1] = { NULL };
static BmlResourceDescriptor bm_obj_seabed_con_rare_resource_descriptor = {
    "bm_obj_seabed_con_rare.bml", bm_obj_seabed_con_rare_model_names, bm_obj_seabed_con_rare_motion_names, 3, 0,
};

ForestBoxCollisionBody forest_box_collision_body_parts = {
    { 0.0f, 6.0f, 0.0f }, 9.0f, 9.0f, 0, 0x38003, { 0, 0, 0, 0 },
};

static TObjChipParams forest_box_break_params[4] = {
    { { 0.5f, 0.03f, 0.2f }, { 0.0f, 0.0f, 0.0f }, { 3.0f, 5.0f, 3.0f }, { 0x800, 0x100, 0x800 }, { 7, 0x32 }, { 0.0f, 1.0f }, 0, 0, 0x16 },
    { { 0.5f, 0.03f, 0.19f }, { 0.0f, 0.0f, 0.0f }, { 3.5f, 5.0f, 3.5f }, { 0x400, 0x100, 0x400 }, { 5, 0x32 }, { 0.0f, 1.0f }, 0, 0, 0x16 },
    { { 0.5f, 0.03f, 0.2f }, { 0.0f, 0.0f, 0.0f }, { 3.0f, 5.0f, 3.0f }, { 0x800, 0x100, 0x800 }, { 7, 0x32 }, { 0.0f, 0.5f }, 0, 0, 0x16 },
    { { 0.5f, 0.03f, 0.19f }, { 0.0f, 0.0f, 0.0f }, { 3.5f, 5.0f, 3.5f }, { 0x400, 0x100, 0x400 }, { 5, 0x32 }, { 0.0f, 0.5f }, 0, 0, 0x16 },
};

// TObjContainerBase's name (init_container_base and TObjContainerBase__ct install it)
const char *TObjContainerBase__name = "TObjContainerBase";
const char *TObjContainerItem__name = "TObjContainerItem";
const char *TObjContainerEnemy__name = "TObjContainerEnemy";
const char *TObjContainerNoItem__name = "TObjContainerNoItem";

extern const TObjChipParams container_break_particle_parameters = {
    { 0.5f, 0.07f, 0.26f }, { 0.0f, 0.0f, 0.0f }, { 5.0f, 5.0f, 5.0f }, { 0x400, 0x100, 0x400 }, { 5, 0x32 }, { 0.0f, 0.6f }, 0, 0, 0x14,
};
extern const TObjChipParams container_break_small_debris_parameters = {
    { 0.5f, 0.07f, 0.26f }, { 0.0f, 0.0f, 0.0f }, { 4.0f, 4.5f, 4.0f }, { 0x200, 0x100, 0x200 }, { 6, 0x32 }, { 0.0f, 0.5f }, 0, 0, 0x14,
};

const char *TObjContainerAbeEnemy__name = "TObjContainerAbeEnemy";

extern const TObjChipParams lbl_80444E5C = {
    { 0.5f, 0.07f, 0.26f }, { 0.0f, 0.0f, 0.0f }, { 5.0f, 5.0f, 5.0f }, { 0x400, 0x100, 0x400 }, { 5, 0x32 }, { 0.0f, 0.6f }, 0, 0, 0x14,
};
extern const TObjChipParams lbl_80444EA8 = {
    { 0.5f, 0.07f, 0.26f }, { 0.0f, 0.0f, 0.0f }, { 4.0f, 4.5f, 4.0f }, { 0x200, 0x100, 0x200 }, { 6, 0x32 }, { 0.0f, 0.5f }, 0, 0, 0x14,
};

void play_container_break_sound(s32 arg0);
extern s32 lbl_805D5B7C;
extern "C" {
s32 push_matrix(void);
void post_translate_matrix(const void *);
extern BmlResource *container_breakup_model_archive;
extern s32 lbl_805D5B8C;
extern const f32 lbl_805DBCF8;
u32 init_collision_body_parts(void *, void *, s32);
u8 *load_gvm_texture_file(s32 arg0);
extern s32 local_client_id;
extern const f32 lbl_805DBCF4;
u8 *__ct__8TObjChipFP7TObjectP14TObjChipParams(u8 *arg0, u8 *arg1, u8 *arg2);
s32 dispatch_fish_event__6TLobbyFPv(void *a0);
void *__nw__7TObjectFUl(int);
extern void *tl_05;
void TObjContainerAbeEnemy__vt77(const Obj_8018860C *self);
s32 release_texture_list(void*);
s32 free_collision_body_parts(void *);
extern void *__vt__21TObjContainerAbeEnemy[];
u8 *TObjContainerAbeEnemy__ct(u8 *arg0, s32 arg1, s32 arg2);
void TObjContainerBase__vt77(const Obj_80188B3C *self);
void *TObjContainerBase__create(void *arg0);
void *__dt__21TObjContainerAbeEnemyFv(void *arg0, s16 arg1);
u8 *TObjContainerBase__ct(u8 *arg0, s32 arg1, s32 arg2);
s32 __dl__7TObjectFPv(void *);
extern s32 __vt__17TObjContainerBase[];
s32 get_container_param(s32 index);
extern TObjChipParams *lbl_805D5B80;
extern TObjChipParams *lbl_805D5B84;
extern BmlResource *lbl_805D5B78;
extern const f32 lbl_805DBCFC;
void *__dt__17TObjContainerBaseFv(void *arg0, s16 arg1);
extern s32 __vt__19TObjContainerNoItem[];
u8 *TObjContainerNoItem__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__19TObjContainerNoItemFv(void *arg0, s16 arg1);
extern s32 __vt__18TObjContainerEnemy[];
extern const f32 lbl_805DBD0C;
extern s32 __vt__17TObjContainerItem[];
u8 *TObjContainerItem__ct(u8 *arg0, s32 arg1, s32 arg2);
void run_task__13TUnk_804B6C24Fv();
void render__13TUnk_804B6C24Fv();
void render_shadows__7TObjectFv();
void vfunc_6__21TObjContainerAbeEnemyFPsl();
void apply_object_set_data__8TObjBaseFPv();
void reset_motion_fields__9TObjCharaFv();
void get_center__9TObjCharaFv();
void update_object_view_visibility__8TObjBaseFff();
void classify_actor_view_detail__8TObjBaseFfff();
void get_name__8TObjBaseFv();
void interact__14TObjCollidableFl();
void add_actor_exp__9TObjCharaFl();
void consume_timer_field__9TObjCharaFl();
void get_actor_level_index__9TObjCharaFv();
void update_actor_ground_y__9TObjCharaFv();
void vfunc_18__9TObjCharaFPUc();
void is_actor_cadence_frame__9TObjCharaFl();
void select_melee_contact_body__13TUnk_804B6C24FPvf();
void calc_distance_accuracy_penalty__13TUnk_804B6C24FPvPvPvf();
void receive_physical_attack__21TObjContainerAbeEnemyFPvf();
void receive_direct_attack__13TUnk_804B6C24FPv19DirectAttackPayloadPvll();
void receive_weapon_special_attack__13TUnk_804B6C24FPvPv();
void apply_knockback_from_attacker__13TUnk_804B6C24FPUcf();
void try_start_action__13TUnk_804B6C24Fll();
void vfunc_28__9TObjCharaFv();
void vfunc_29__9TObjCharaFv();
void is_target_in_attack_range__9TObjCharaFv();
void update_poison_status__9TObjCharaFv();
void update_action_hold_status__9TObjCharaFv();
void update_flag30_timer__9TObjCharaFv();
void update_movement_status__9TObjCharaFv();
void update_shock_clock__9TObjCharaFv();
s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
void vfunc_43__9TObjCharaFv();
void apply_poison_status__9TObjCharaFv();
void apply_paralysis__9TObjCharaFv();
void apply_slow_status__9TObjCharaFv();
void apply_confusion_status__9TObjCharaFv();
void apply_movement_ailment__9TObjCharaFl();
void apply_shock_status__9TObjCharaFv();
void clear_harmful_statuses__9TObjCharaFv();
void apply_attack_stat_status__9TObjCharaFPv();
void cure_poison_ailment__9TObjCharaFv();
void apply_defense_stat_status__9TObjCharaFPv();
void cure_paralysis__9TObjCharaFv();
void clear_all_status_effects__9TObjCharaFv();
void apply_action_hold_status__9TObjCharaFf();
void apply_anti_technique__9TObjCharaFl();
void vfunc_58__9TObjCharaFv();
void vfunc_59__9TObjCharaFv();
void vfunc_60__9TObjCharaFv();
void vfunc_61__9TObjCharaFv();
void vfunc_62__9TObjCharaFv();
void vfunc_63__9TObjCharaFv();
void reset_pose__9TObjCharaFv();
void get_anim_node_position__9TObjCharaFlP3Vec();
void vfunc_66__9TObjCharaFv();
void vfunc_67__9TObjCharaFf();
void get_pos__9TObjCharaFl();
void apply_switch_attack__9TObjCharaFv();
void enemy_spawn_jellen_effect__9TObjCharaFv();
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
void enemy_spawn_zalure_effect__9TObjCharaFv();
void recalc_stats__9TObjCharaFv();
void vfunc_74__9TObjCharaFl();
void vfunc_75__9TObjCharaFf();
void vfunc_76__9TObjCharaFf();
void vfunc_77__9TObjCharaFv();
void vfunc_78__9TObjCharaFl();
void vfunc_80__21TObjContainerAbeEnemyFv();
void vfunc_81__21TObjContainerAbeEnemyFv();
void debug_print_item_box_info__21TObjContainerAbeEnemyFv();
void *__dt__17TObjContainerItemFv(void *arg0, s16 arg1);
s32 request_box_item_drop__9TObjCharaFPvs(s32, void *, s32, void *);
void *__ct__18CameraDistanceFadeFv(void *self);
extern const f32 lbl_805DBCF0;
u8 * __ct__9TObjCharaFP7TObject(void *);
extern RecoveredGlobal_8018A150_lbl_804B6C24 lbl_804B6C24;
extern const f32 lbl_805DBD00;
extern const f32 lbl_805DBD04;
extern const f32 lbl_805DBD08;
}

// ---- TObjComputer













void TObjContainerAbeEnemy::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            this->vfunc_79();
            ((TObjCollidable *)arg0)->set_flag8();
            ((TObject *)arg0)->queue_destruction();
            this->mode = 1;
        }
    } else if ((s16) *arg1 == 1) {
        ((TObjCollidable *)arg0)->set_flag8();
        ((TObject *)arg0)->queue_destruction();
        this->mode = 1;
    }
}

#pragma push
#pragma opt_propagation off
void TObjContainerAbeEnemy__vt77(const Obj_8018860C *self) {
    if (self->state != 1) {
        TObjChipParams a = lbl_80444E5C;
        f32 za;
        f32 ya;
        f32 xa;
        xa = self->pos.x;
        ya = self->pos.y;
        za = self->pos.z;
        a.pos[0] = xa;
        a.pos[1] = ya;
        a.pos[2] = za;
        a.pad_38[0] = ya;
        a.model = dispatch_fish_event__6TLobbyFPv((void *)0);
        a.textures = lbl_805D5B8C;
        TObjChipParams b = lbl_80444EA8;
        f32 zb;
        f32 yb;
        f32 xb;
        xb = self->pos.x;
        yb = self->pos.y;
        zb = self->pos.z;
        b.pos[0] = xb;
        b.pos[1] = yb;
        b.pos[2] = zb;
        b.pad_38[0] = yb;
        b.model = dispatch_fish_event__6TLobbyFPv((void *)1);
        b.textures = lbl_805D5B8C;
        spawn_particle_effect_with_flags((void *)&self->pos, 0x45, 0x40);
        spawn_particle_effect_with_flags((void *)&self->pos, 0x46, 0x40);
        void *o = __nw__7TObjectFUl(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&a);
        }
        o = __nw__7TObjectFUl(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&b);
        }
        play_container_break_sound((s32)self);
    }
}
#pragma pop

f32 TObjContainerAbeEnemy::receive_physical_attack(void *, f32) {
    Obj_80188768 *arg0 = (Obj_80188768 *)this;
    s16 sp8;
    Pkt_80188768 pkt;
    if ((this->entity_id >= 0x1000U) && (arg0->f80 != 0U) && (((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 1) != 0)) {
        sp8 = 1;
        ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 0);
        ((TObjCollidable *)arg0)->send_object_state_update(&sp8);
        ((TLobby *)(&pkt))->init_packet_67_04();
        pkt.b = this->entity_id;
        pkt.c = get_current_floor();
        pkt.d = this->set_params[0];
        pkt.e = local_client_id;
        ((TLobby *)(&pkt))->byteswap_and_send();
    }
    return lbl_805DBCF4;
}

void TObjContainerAbeEnemy::debug_print_item_box_info() {
    Obj_80188814 *self = (Obj_80188814 *)this;
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, "EVT NO : %d", this->set_params[0]);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    debug_draw_sphere((const Vec *)self->pos, &debug_color_blue_alpha30, lbl_805DBCF8);
}

void TObjContainerAbeEnemy::vfunc_81() {
    Obj_80188884 *self = (Obj_80188884 *)this;
    if (container_breakup_model_archive != 0) {
        switch (this->mode) {
        case 0:
            TObjFish::set_global_param(lbl_805D5B8C);
            push_matrix();
            post_translate_matrix(self->pos);
            rotate_matrix_y(0, this->rotation_y);
            draw_ginja_box_tree((u8 *)dispatch_fish_event__6TLobbyFPv((void *)2));
            pop_matrix();
            break;
        case 1:
            break;
        }
    }
}
// ---- TObjContainerAbeEnemy






extern "C" {

void TObjContainerAbeEnemy::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->m_364 != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void *__dt__21TObjContainerAbeEnemyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)__vt__21TObjContainerAbeEnemy;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B6C24 *)arg0)->destroy_container_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_801889B8___vt__21TObjContainerAbeEnemy_size[sizeof(RecoveredGlobal_801889B8___vt__21TObjContainerAbeEnemy) == 0x14C ? 1 : -1];
u8 *TObjContainerAbeEnemy__ct(u8 *arg0, s32 arg1, s32 arg2) {
    init_container_base(arg0, arg1, arg2);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_801889B8___vt__21TObjContainerAbeEnemy *)&__vt__21TObjContainerAbeEnemy).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjContainerAbeEnemy__name;
    ((TObjContainerAbeEnemy *)arg0)->mode = 0;
    ((TObjContainerAbeEnemy *)arg0)->actorFlags = (s32) (((TObjContainerAbeEnemy *)arg0)->actorFlags | 0x60000000);
    init_collision_body_parts(arg0, &forest_box_collision_body_parts, 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x78) = (f32) (*(f32 *)((s8 *)arg0 + 0x78) + forest_box_collision_body_parts.center[1]);
    return arg0;
}

void *TObjContainerBase__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x368);
    if (o != NULL) {
        o = TObjContainerBase__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}
void TObjContainerBase::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            this->vfunc_79();
            ((TUnk_804B6C24 *)arg0)->spawn_item((s32)arg0);
            ((TObjCollidable *)arg0)->set_flag8();
            ((TObject *)arg0)->queue_destruction();
            this->mode = 1;
        }
    } else if ((s16) *arg1 == 1) {
        ((TObjCollidable *)arg0)->set_flag8();
        ((TObject *)arg0)->queue_destruction();
        this->mode = 1;
    }
}

#pragma push
#pragma opt_propagation off
void TObjContainerBase__vt77(const Obj_80188B3C *self) {
    TObjChipParams a = container_break_particle_parameters;
    f32 za;
    f32 ya;
    f32 xa;
    xa = self->x;
    ya = self->y;
    za = self->z;
    a.pos[0] = xa;
    a.pos[1] = ya;
    a.pos[2] = za;
    a.pad_38[0] = ya;
    a.model = dispatch_fish_event__6TLobbyFPv((void *)0);
    a.textures = lbl_805D5B8C;
    TObjChipParams b = container_break_small_debris_parameters;
    f32 zb;
    f32 yb;
    f32 xb;
    xb = self->x;
    yb = self->y;
    zb = self->z;
    b.pos[0] = xb;
    b.pos[1] = yb;
    b.pos[2] = zb;
    b.pad_38[0] = yb;
    b.model = dispatch_fish_event__6TLobbyFPv((void *)1);
    b.textures = lbl_805D5B8C;
    spawn_particle_effect_with_flags((void *)&self->x, 0x45, 0x40);
    spawn_particle_effect_with_flags((void *)&self->x, 0x46, 0x40);
    void *o = __nw__7TObjectFUl(0x234);
    if (o != NULL) {
        __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&a);
    }
    o = __nw__7TObjectFUl(0x234);
    if (o != NULL) {
        __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&b);
    }
    play_container_break_sound((s32)self);
}
#pragma pop

void TObjContainerBase::vfunc_81() {
    Obj_80188C8C *self = (Obj_80188C8C *)this;
    if (container_breakup_model_archive != 0) {
        switch (this->mode) {
        case 0:
            TObjFish::set_global_param(lbl_805D5B8C);
            push_matrix();
            post_translate_matrix(self->pos);
            rotate_matrix_y(0, this->rotation_y);
            draw_ginja_box_tree((u8 *)dispatch_fish_event__6TLobbyFPv((void *)2));
            pop_matrix();
            break;
        case 1:
            break;
        }
    }
}
}

// ---- TObjContainerBase







extern "C" {

void TObjContainerBase::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->m_364 != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void *__dt__17TObjContainerBaseFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TObjContainerBase;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B6C24 *)arg0)->destroy_container_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80188DC0___vt__17TObjContainerBase_size[sizeof(RecoveredGlobal_80188DC0___vt__17TObjContainerBase) == 0x14C ? 1 : -1];
u8 *TObjContainerBase__ct(u8 *arg0, s32 arg1, s32 arg2) {
    init_container_base(arg0, arg1, arg2);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80188DC0___vt__17TObjContainerBase *)&__vt__17TObjContainerBase).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjContainerBase__name;
    ((TObjContainerBase *)arg0)->mode = 0;
    ((TObjContainerBase *)arg0)->actorFlags = (s32) (((TObjContainerBase *)arg0)->actorFlags | 0x60000000);
    init_collision_body_parts(arg0, &forest_box_collision_body_parts, 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x78) = (f32) (*(f32 *)((s8 *)arg0 + 0x78) + forest_box_collision_body_parts.center[1]);
    return arg0;
}

void TObjContainerNoItem::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            this->vfunc_79();
            ((TObjCollidable *)arg0)->clear_player_status_flag(0, 1);
            ((TObjCollidable *)arg0)->set_flag8();
            ((TObject *)arg0)->queue_destruction();
            this->mode = 1;
        }
    } else if ((s16) *arg1 == 1) {
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 1);
        ((TObjCollidable *)arg0)->set_flag8();
        ((TObject *)arg0)->queue_destruction();
        this->mode = 1;
    }
}

typedef char RecoveredGlobal_801897A4___vt__18TObjContainerEnemy_size[sizeof(RecoveredGlobal_801897A4___vt__18TObjContainerEnemy) == 0x14C ? 1 : -1];
void TObjContainerNoItem::vfunc_79() {
    Obj_8018990C *self = (Obj_8018990C *)this;
    void *o;
    if (this->mode != 1) {
        TObjChipParams a = *lbl_805D5B80;
        TObjChipParams b = *lbl_805D5B84;
        VecCopy((Vec *)a.pos, (const Vec *)&self->x);
        a.pad_38[0] = self->y;
        a.model = get_container_param(2);
        a.textures = lbl_805D5B7C;
        VecCopy((Vec *)b.pos, (const Vec *)&self->x);
        b.pad_38[0] = self->y;
        b.model = get_container_param(0);
        b.textures = lbl_805D5B7C;
        spawn_particle_effect_with_flags(&self->x, 0x45, 0x40);
        spawn_particle_effect_with_flags(&self->x, 0x46, 0x40);
        o = __nw__7TObjectFUl(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&a);
        }
        o = __nw__7TObjectFUl(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&b);
        }
        play_container_break_sound((s32)self);
    }
}

f32 TObjContainerNoItem::receive_physical_attack(void *, f32) {
    u8 *arg0 = (u8 *)this;
    s16 sp8;
    if (((u16) this->entity_id >= 0x1000U) && ((u32) *(u32 *)((s8 *)arg0 + 0x80) != 0U) && (((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 1) != 0)) {
        sp8 = 1;
        ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 0);
        ((TObjCollidable *)arg0)->send_object_state_update(&sp8);
    }
    return lbl_805DBCF4;
}
void TObjContainerNoItem::vfunc_81() {
    u8 *arg0 = (u8 *)this;
    if (lbl_805D5B78 != 0U) {
        switch (this->mode) {
        case 1:
            break;
        case 0:
        TObjFish::set_global_param(lbl_805D5B7C);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        scale_matrix(0, lbl_805DBCFC, lbl_805DBCFC, lbl_805DBCFC);
        draw_ginja_box_tree((u8 *)(*(s32 *)((s8 *)arg0 + 0x34)));
        pop_matrix();
            break;
        }
    }
}
}

// ---- TObjContainerNoItem











extern "C" {

void TObjContainerNoItem::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->m_364 != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void *TObjContainerNoItem::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x368);
    if (o != NULL) {
        o = TObjContainerNoItem__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void *__dt__19TObjContainerNoItemFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TObjContainerNoItem;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B6C24 *)arg0)->destroy_container_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_8018925C___vt__19TObjContainerNoItem_size[sizeof(RecoveredGlobal_8018925C___vt__19TObjContainerNoItem) == 0x14C ? 1 : -1];
u8 *TObjContainerNoItem__ct(u8 *arg0, s32 arg1, s32 arg2) {
    init_container_base((arg0), (arg1), (arg2));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8018925C___vt__19TObjContainerNoItem *)&__vt__19TObjContainerNoItem).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjContainerNoItem__name;
    *(s32 *)((s8 *)arg0 + 0x34) = get_container_param(1);
    ((TObjContainerNoItem *)arg0)->mode = 0;
    ((TObjContainerNoItem *)arg0)->actorFlags = (s32) (((TObjContainerNoItem *)arg0)->actorFlags | 0x60000000);
    init_collision_body_parts(arg0, &forest_box_collision_body_parts, 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x78) = (f32) (*(f32 *)((s8 *)arg0 + 0x78) + forest_box_collision_body_parts.center[1]);
    return arg0;
}

void TObjContainerEnemy::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            this->vfunc_79();
            ((TObjCollidable *)arg0)->clear_player_status_flag(0, 1);
            ((TObjCollidable *)arg0)->set_flag8();
            ((TObject *)arg0)->queue_destruction();
            this->mode = 1;
        }
    } else if ((s16) *arg1 == 1) {
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 1);
        ((TObjCollidable *)arg0)->set_flag8();
        ((TObject *)arg0)->queue_destruction();
        this->mode = 1;
    }
}

typedef char RecoveredGlobal_801897A4___vt__18TObjContainerEnemy_size[sizeof(RecoveredGlobal_801897A4___vt__18TObjContainerEnemy) == 0x14C ? 1 : -1];
void TObjContainerEnemy::vfunc_79() {
    Obj_8018990C *self = (Obj_8018990C *)this;
    void *o;
    if (this->mode != 1) {
        TObjChipParams a = *lbl_805D5B80;
        TObjChipParams b = *lbl_805D5B84;
        VecCopy((Vec *)a.pos, (const Vec *)&self->x);
        a.pad_38[0] = self->y;
        a.model = get_container_param(2);
        a.textures = lbl_805D5B7C;
        VecCopy((Vec *)b.pos, (const Vec *)&self->x);
        b.pad_38[0] = self->y;
        b.model = get_container_param(0);
        b.textures = lbl_805D5B7C;
        spawn_particle_effect_with_flags(&self->x, 0x45, 0x40);
        spawn_particle_effect_with_flags(&self->x, 0x46, 0x40);
        o = __nw__7TObjectFUl(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&a);
        }
        o = __nw__7TObjectFUl(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&b);
        }
        play_container_break_sound((s32)self);
    }
}

f32 TObjContainerEnemy::receive_physical_attack(void *, f32) {
    Obj_801894F8 *arg0 = (Obj_801894F8 *)this;
    s16 sp8;
    Pkt_801894F8 pkt;
    if ((this->entity_id >= 0x1000U) && (arg0->f80 != 0U) && (((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 1) != 0)) {
        sp8 = 1;
        ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 0);
        ((TObjCollidable *)arg0)->send_object_state_update(&sp8);
        ((TLobby *)(&pkt))->init_packet_67_04();
        pkt.b = this->entity_id;
        pkt.c = get_current_floor();
        pkt.d = this->set_params[0];
        pkt.e = local_client_id;
        ((TLobby *)(&pkt))->byteswap_and_send();
    }
    return lbl_805DBCF4;
}

void TObjContainerEnemy::debug_print_item_box_info() {
    Obj_801895A4 *self = (Obj_801895A4 *)this;
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, "EVT NO : %d", this->set_params[0]);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    debug_draw_sphere((const Vec *)self->pos, &debug_color_blue_alpha30, lbl_805DBCF8);
}
void TObjContainerEnemy::vfunc_81() {
    CE_80189614 *self = (CE_80189614 *)this;
    if (lbl_805D5B78 == 0) {
        return;
    }
    switch (self->mode) {
    case 0:
        TObjFish::set_global_param(lbl_805D5B7C);
        push_matrix();
        post_translate_matrix(self->f38);
        rotate_matrix_y(0, self->f60);
        scale_matrix(0, lbl_805DBCFC, lbl_805DBCFC, lbl_805DBCFC);
        draw_ginja_box_tree((u8 *)self->f34);
        pop_matrix();
        break;
    case 1:
        break;
    }
}
}

// ---- TObjContainerEnemy






extern "C" {

void TObjContainerEnemy::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->m_364 != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void *TObjContainerEnemy::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x368);
    if (o != NULL) {
        o = TObjContainerEnemy__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void *__dt__18TObjContainerEnemyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjContainerEnemy;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B6C24 *)arg0)->destroy_container_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_801897A4___vt__18TObjContainerEnemy_size[sizeof(RecoveredGlobal_801897A4___vt__18TObjContainerEnemy) == 0x14C ? 1 : -1];
u8 *TObjContainerEnemy__ct(u8 *arg0, s32 arg1, s32 arg2) {
    init_container_base((arg0), (arg1), (arg2));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_801897A4___vt__18TObjContainerEnemy *)&__vt__18TObjContainerEnemy).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjContainerEnemy__name;
    *(s32 *)((s8 *)arg0 + 0x34) = get_container_param(1);
    ((TObjContainerEnemy *)arg0)->mode = 0;
    ((TObjContainerEnemy *)arg0)->actorFlags = (s32) (((TObjContainerEnemy *)arg0)->actorFlags | 0x60000000);
    init_collision_body_parts(arg0, &forest_box_collision_body_parts, 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x78) = (f32) (*(f32 *)((s8 *)arg0 + 0x78) + forest_box_collision_body_parts.center[1]);
    return arg0;
}

void TObjContainerItem::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            this->vfunc_79();
            ((TObjChara *)arg0)->request_box_item_drop((u8 *)&this->position, 1);
            ((TObjCollidable *)arg0)->clear_player_status_flag(0, 1);
            ((TObjCollidable *)arg0)->set_flag8();
            ((TObject *)arg0)->queue_destruction();
            this->mode = 1;
        }
    } else if ((s16) *arg1 == 1) {
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 1);
        ((TObjCollidable *)arg0)->set_flag8();
        ((TObject *)arg0)->queue_destruction();
        this->mode = 1;
    }
}

void TObjContainerItem::vfunc_79() {
    Obj_8018990C *self = (Obj_8018990C *)this;
    void *o;
    if (this->mode != 1) {
        TObjChipParams a = *lbl_805D5B80;
        TObjChipParams b = *lbl_805D5B84;
        VecCopy((Vec *)a.pos, (const Vec *)&self->x);
        a.pad_38[0] = self->y;
        a.model = get_container_param(2);
        a.textures = lbl_805D5B7C;
        VecCopy((Vec *)b.pos, (const Vec *)&self->x);
        b.pad_38[0] = self->y;
        b.model = get_container_param(0);
        b.textures = lbl_805D5B7C;
        spawn_particle_effect_with_flags(&self->x, 0x45, 0x40);
        spawn_particle_effect_with_flags(&self->x, 0x46, 0x40);
        o = __nw__7TObjectFUl(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&a);
        }
        o = __nw__7TObjectFUl(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&b);
        }
        play_container_break_sound((s32)self);
    }
}

void TObjContainerItem::vfunc_81() {
    struct Box_80189A50 *self = (struct Box_80189A50 *)this;
    if (lbl_805D5B78 != 0) {
        switch (self->state) {
        case 0:
            TObjFish::set_global_param(lbl_805D5B7C);
            push_matrix();
            post_translate_matrix(self->pos);
            rotate_matrix_y(0, self->rot);
            scale_matrix(0, lbl_805DBCFC, lbl_805DBCFC, lbl_805DBCFC);
            draw_ginja_box_tree((u8 *)self->model);
            pop_matrix();
            break;
        case 1:
            break;
        }
    }
}
}


// ---- TObjContainerItem
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
extern "C" void roll_physical_accuracy__13TUnk_804B6C24FPvlf();







extern "C" {
void *__vt__21TObjContainerAbeEnemy[83] = {
    0,
    0,
    (void *)__dt__21TObjContainerAbeEnemyFv,
    (void *)run_task__13TUnk_804B6C24Fv,
    (void *)render__13TUnk_804B6C24Fv,
    (void *)render_shadows__7TObjectFv,
    (void *)vfunc_6__21TObjContainerAbeEnemyFPsl,
    (void *)apply_object_set_data__8TObjBaseFPv,
    (void *)reset_motion_fields__9TObjCharaFv,
    (void *)get_center__9TObjCharaFv,
    (void *)update_object_view_visibility__8TObjBaseFff,
    (void *)classify_actor_view_detail__8TObjBaseFfff,
    (void *)get_name__8TObjBaseFv,
    (void *)interact__14TObjCollidableFl,
    (void *)add_actor_exp__9TObjCharaFl,
    (void *)consume_timer_field__9TObjCharaFl,
    (void *)get_actor_level_index__9TObjCharaFv,
    (void *)update_actor_ground_y__9TObjCharaFv,
    (void *)vfunc_18__9TObjCharaFPUc,
    (void *)is_actor_cadence_frame__9TObjCharaFl,
    (void *)select_melee_contact_body__13TUnk_804B6C24FPvf,
    (void *)calc_distance_accuracy_penalty__13TUnk_804B6C24FPvPvPvf,
    (void *)receive_physical_attack__21TObjContainerAbeEnemyFPvf,
    (void *)receive_direct_attack__13TUnk_804B6C24FPv19DirectAttackPayloadPvll,
    (void *)receive_weapon_special_attack__13TUnk_804B6C24FPvPv,
    (void *)apply_knockback_from_attacker__13TUnk_804B6C24FPUcf,
    (void *)try_start_action__13TUnk_804B6C24Fll,
    (void *)&roll_physical_accuracy__13TUnk_804B6C24FPvlf,
    (void *)vfunc_28__9TObjCharaFv,
    (void *)vfunc_29__9TObjCharaFv,
    (void *)is_target_in_attack_range__9TObjCharaFv,
    (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv,
    (void *)&has_flag_0x800__9TObjCharaFv,
    (void *)&test_flag_1000__9TObjCharaFv,
    (void *)update_poison_status__9TObjCharaFv,
    (void *)update_action_hold_status__9TObjCharaFv,
    (void *)vfunc_37__9TObjCharaFv,
    (void *)update_flag30_timer__9TObjCharaFv,
    (void *)update_movement_status__9TObjCharaFv,
    (void *)update_shock_clock__9TObjCharaFv,
    (void *)update_attack_stat_status__9TObjCharaFv,
    (void *)update_defense_stat_status__9TObjCharaFv,
    (void *)vfunc_43__9TObjCharaFv,
    (void *)apply_poison_status__9TObjCharaFv,
    (void *)apply_paralysis__9TObjCharaFv,
    (void *)apply_slow_status__9TObjCharaFv,
    (void *)apply_confusion_status__9TObjCharaFv,
    (void *)apply_movement_ailment__9TObjCharaFl,
    (void *)apply_shock_status__9TObjCharaFv,
    (void *)clear_harmful_statuses__9TObjCharaFv,
    (void *)apply_attack_stat_status__9TObjCharaFPv,
    (void *)apply_defense_stat_status__9TObjCharaFPv,
    (void *)cure_poison_ailment__9TObjCharaFv,
    (void *)cure_paralysis__9TObjCharaFv,
    (void *)clear_all_status_effects__9TObjCharaFv,
    (void *)apply_action_hold_status__9TObjCharaFf,
    (void *)apply_anti_technique__9TObjCharaFl,
    (void *)vfunc_58__9TObjCharaFv,
    (void *)vfunc_59__9TObjCharaFv,
    (void *)vfunc_60__9TObjCharaFv,
    (void *)vfunc_61__9TObjCharaFv,
    (void *)vfunc_62__9TObjCharaFv,
    (void *)vfunc_63__9TObjCharaFv,
    (void *)reset_pose__9TObjCharaFv,
    (void *)get_anim_node_position__9TObjCharaFlP3Vec,
    (void *)vfunc_66__9TObjCharaFv,
    (void *)vfunc_67__9TObjCharaFf,
    (void *)get_pos__9TObjCharaFl,
    (void *)apply_switch_attack__9TObjCharaFv,
    (void *)enemy_spawn_jellen_effect__9TObjCharaFv,
    (void *)trigger_switch_attack__9TObjCharaFv,
    (void *)enemy_spawn_zalure_effect__9TObjCharaFv,
    (void *)recalc_stats__9TObjCharaFv,
    (void *)vfunc_74__9TObjCharaFl,
    (void *)vfunc_75__9TObjCharaFf,
    (void *)vfunc_76__9TObjCharaFf,
    (void *)vfunc_77__9TObjCharaFv,
    (void *)vfunc_78__9TObjCharaFl,
    (void *)TObjContainerAbeEnemy__vt77,
    (void *)vfunc_80__21TObjContainerAbeEnemyFv,
    (void *)vfunc_81__21TObjContainerAbeEnemyFv,
    (void *)debug_print_item_box_info__21TObjContainerAbeEnemyFv,
};

void TObjContainerItem::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->m_364 != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}


void *TObjContainerItem::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x368);
    if (o != NULL) {
        o = TObjContainerItem__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void *__dt__17TObjContainerItemFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TObjContainerItem;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B6C24 *)arg0)->destroy_container_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80189BE0___vt__17TObjContainerItem_size[sizeof(RecoveredGlobal_80189BE0___vt__17TObjContainerItem) == 0x14C ? 1 : -1];
u8 *TObjContainerItem__ct(u8 *arg0, s32 arg1, s32 arg2) {
    init_container_base((arg0), (arg1), (arg2));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80189BE0___vt__17TObjContainerItem *)&__vt__17TObjContainerItem).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjContainerItem__name;
    *(s32 *)((s8 *)arg0 + 0x34) = get_container_param(1);
    ((TObjContainerItem *)arg0)->mode = 0;
    ((TObjContainerItem *)arg0)->actorFlags = (s32) (((TObjContainerItem *)arg0)->actorFlags | 0x60000000);
    init_collision_body_parts(arg0, &forest_box_collision_body_parts, 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x78) = (f32) (*(f32 *)((s8 *)arg0 + 0x78) + forest_box_collision_body_parts.center[1]);
    return arg0;
}

void TUnk_804B6C24::spawn_item(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    request_box_item_drop__9TObjCharaFPvs(arg1, (u8 *)&this->position, this->m_360, arg0);
}
}
void play_container_break_sound(s32 arg0) {
    u32 area;
    area = get_current_floor_area();
    switch (area) {
    case AREA_FOREST1:
    case AREA_FOREST2:
        play_sound_effect(0x4BC10, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        play_sound_effect(0x43C0F, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_MINE1:
    case AREA_MINE2:
        play_sound_effect(0x4004BC09, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_RUINS1:
    case AREA_RUINS2:
    case AREA_RUINS3:
        play_sound_effect(0x4004BC10, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_BATTLE1:
    case AREA_BATTLE2:
        play_sound_effect(0x4004BC05, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        play_sound_effect(0x4BC05, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_sound_effect(0x4004BC05, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
        play_sound_effect(0x4BC16, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4004BC16, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_SEASIDE_NIGHT:
        play_sound_effect(0x4004BC16, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_TOWER:
        play_sound_effect(0x4004BC16, (void *)(arg0 + 0x38), 0, 0);
    default:
        return;
    }
}



extern "C" {
void TUnk_804B6C24::debug_print_item_box_info() {
    Obj_80189E3C *self = (Obj_80189E3C *)this;
    Item_80189E3C item;
    if (this->scale.x > lbl_805DBCF4) {
        this->m_360 = 1;
    } else {
        this->m_360 = 0;
    }
    if (this->m_360 != 0) {
        TObjNpcEnemy::set_global_count(0xFFFFFF);
        debug_printf_at(0x13001C, "<- RANDOM ITEM");
    } else {
        TObjNpcEnemy::set_global_count(0xFF00FF);
        debug_printf_at(0x13001C, "<- FIXED ITEM");
        debug_printf_at(0x130020, "<- ITEM PARAM");
        item.data[0] = self->data[0];
        item.data[1] = self->data[1];
        item.data[2] = self->data[2];
        debug_print_item_param(&item);
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

}






extern "C" {

void TUnk_804B6C24::render() {
    Obj_80189F24 *self = (Obj_80189F24 *)this;
    if (self->m8(self->x334, self->x338) != 1) {
        return;
    }
    self->x364 = 1;
    if (((CameraDistanceFade *)&self->sub)->update_visibility((Vec *)self->pos) != 1) {
        return;
    }
    if (((CameraDistanceFade *)&self->sub)->is_translucent() == 1) {
        self->sub.m6();
        self->m79();
        self->sub.m7();
    } else {
        self->m79();
    }
}

void TUnk_804B6C24::run_task() {
    u8 *arg0 = (u8 *)this;
    ((CameraDistanceFade *)(arg0 + 0x340))->step_fade();
    this->vfunc_80();
    this->m_364 = 0;
}

f32 TUnk_804B6C24::receive_physical_attack(void *, f32) {
    u8 *arg0 = (u8 *)this;
    s16 sp8;
    if (((u16) this->entity_id >= 0x1000U) && ((u32) *(u32 *)((s8 *)arg0 + 0x80) != 0U) && (((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 1) != 0)) {
        sp8 = 1;
        ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 0);
        ((TObjCollidable *)arg0)->send_object_state_update(&sp8);
    }
    return lbl_805DBCF4;
}

f32 TUnk_804B6C24::receive_direct_attack(void *arg1, DirectAttackPayload payload, void *, s32, s32) {
    s32 temp_r4;
    struct VObj_8018A0B4 *o = (struct VObj_8018A0B4 *)this;

    temp_r4 = payload.kind;
    if ((temp_r4 == 0) || ((temp_r4 - 1) <= 3U) || (temp_r4 == 0x13)) {
        o->m20(0, lbl_805DBCF0);
    }
    return lbl_805DBCF4;
}
s32 TUnk_804B6C24::select_melee_contact_body(void *target, f32) {
    return xyz_distance_squared(&((TObjBase *)target)->position, &position) < melee_range_sq;
}

}


extern "C" {
#pragma push
#pragma fp_contract on
u8 *init_container_base(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__9TObjCharaFP7TObject(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804B6C24.value;
    __ct__18CameraDistanceFadeFv(arg0 + 0x340);
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjContainerBase__name;
    ((TUnk_804B6C24 *)(arg0))->apply_object_set_data((void *)arg2);
    *(f32 *)((s8 *)arg0 + 0x334) = (f32) lbl_805DBD00;
    ((TUnk_804B6C24 *)arg0)->m_338 = (f32) lbl_805DBD04;
    ((TUnk_804B6C24 *)arg0)->melee_range_sq = (f32) lbl_805DBD00;
    if (((TUnk_804B6C24 *)arg0)->scale.x > lbl_805DBCF4) {
        ((TUnk_804B6C24 *)arg0)->m_360 = 1;
    } else {
        ((TUnk_804B6C24 *)arg0)->m_360 = 0;
    }
    ((CameraDistanceFade *)(arg0 + 0x340))->reset();
    TLazerFenceSw__sub_8018A554((arg0 + 0x340), lbl_805DBD08);
    ((TUnk_804B6C24 *)arg0)->m_364 = 0;
    return arg0;
}
#pragma pop

}

extern "C" {

void TLobby::dispatch_fish_event(void* a0) { get_bml_model(container_breakup_model_archive, (s32)a0); }


void TLobby::free_chr_select_slot() {
    if ((u32) lbl_805D5B8C != 0U) {
        release_texture_list((void*)lbl_805D5B8C);
        TAdSinglePlyChrSelectGC::safe_free(lbl_805D5B8C);
        lbl_805D5B8C = 0U;
    }
    if ((u32) container_breakup_model_archive != 0U) {
        free_bin_model_request(container_breakup_model_archive, 1);
        container_breakup_model_archive = NULL;
    }
}
void TLobby::load_console_resources() {
    void *p;
    container_breakup_model_archive = 0;
    switch (get_current_floor_area()) {
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
    case AREA_OLGA_FLOW:
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, &bm_obj_seabed_con_rare_resource_descriptor, 0, 0, 0);
        }
        container_breakup_model_archive = (BmlResource *)p;
        lbl_805D5B8C = (u32)load_gvm_texture_file((s32)"obj_seabed_con_rare.gvm");
        break;
    case AREA_GAL_GRYPHON:
    default:
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, &fe_obj_con_hahen1_resource_descriptor, 0, 0, 0);
        }
        container_breakup_model_archive = (BmlResource *)p;
        lbl_805D5B8C = (u32)load_gvm_texture_file((s32)"obj_abecon.gvm");
        break;
    }
}

s32 get_container_param(s32 index) { return get_bml_model(lbl_805D5B78, index); }

void TLobby::free_char_select_resources() {
    if ((u32) lbl_805D5B7C != 0U) {
        release_texture_list((void*)lbl_805D5B7C);
        TAdSinglePlyChrSelectGC::safe_free(lbl_805D5B7C);
        lbl_805D5B7C = 0U;
    }
    if ((u32) lbl_805D5B78 != 0U) {
        free_bin_model_request(lbl_805D5B78, 1);
        lbl_805D5B78 = NULL;
    }
}

}

void load_forest_box_resources(void) {
    void *bundle;
    u32 *node;
    lbl_805D5B78 = NULL;
    lbl_805D5B7C = 0;
    switch (get_current_floor_area()) {
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
    case AREA_OLGA_FLOW:
        bundle = (void *)::operator new(0x440);
        if (bundle != NULL) {
            bundle = load_resource_from_descriptor(bundle, 5, &bm_obj_seabed_con_resource_descriptor, 0, 0, 0);
        }
        lbl_805D5B78 = (BmlResource *)bundle;
        lbl_805D5B7C = (s32)load_gvm_texture_file((s32)"obj_seabed_con.GVM");
        lbl_805D5B80 = &forest_box_break_params[2];
        lbl_805D5B84 = &forest_box_break_params[3];
        node = (u32 *)find_object_node((NJS_OBJECT *)(get_bml_model(lbl_805D5B78, 1)), 2);
        if (node != NULL) {
            *node |= 0x100000;
        }
        break;
    default:
        bundle = (void *)::operator new(0x440);
        if (bundle != NULL) {
            bundle = load_resource_from_descriptor(bundle, 5, &fe_obj_hako01_hahen02_resource_descriptor, 0, 0, 0);
        }
        lbl_805D5B78 = (BmlResource *)bundle;
        lbl_805D5B7C = TLobby::is_online_ready() != 0 ? (s32)load_gvm_texture_file((s32)"fs_obj_hako01_a.gvm") : (s32)load_gvm_texture_file((s32)"fs_obj_hako01_n.gvm");
        lbl_805D5B80 = &forest_box_break_params[0];
        lbl_805D5B84 = &forest_box_break_params[1];
        break;
    }
    TMotorcycle::add_entry(1, get_container_param(1), lbl_805D5B7C, lbl_805DBD0C, lbl_805DBCF4);
}

// ---- TLazerFenceSw

void TUnk_804B6C24::vfunc_81() {  }
void TUnk_804B6C24::vfunc_80() {  }
void TUnk_804B6C24::vfunc_79() {  }
void TLazerFenceSw__sub_8018A554(void* p, f32 v) { *(f32*)((char*)p + 0x1c) = v; }
#pragma pop
