#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjMotion.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
#include "pso/object/obj_band.h"
#include "pso/boss/TBoss4Type3.h"

#include "pso/player/TUnk_80490470.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"

#include "pso/enemy/TObjEnePanarms.h"
#include "pso/misc/TLobby.h"

#define CAT2(a, b) a##b
#define CAT(a, b) CAT2(a, b)
#define PADV virtual void CAT(pv, __LINE__)();
#define PADV4 virtual void CAT(pa, __LINE__)(); virtual void CAT(pb, __LINE__)(); virtual void CAT(pc, __LINE__)(); virtual void CAT(pd, __LINE__)();

struct Base_Sub_80094994 { char pad[0x14]; };

struct V_Sub_80094994 : Base_Sub_80094994 {
    PADV4
    PADV
    virtual s32 m5();
};

struct Base_80094BA4_80094994 { char pad[0x18]; };

struct VObj_80094BA4_80094994 : Base_80094BA4_80094994 {
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
    virtual s32  m97();
};

struct Obj_80094D3C { u8 pad[0x438]; void *parts[2]; };

struct O_8009518C { u8 pad[0x3f4]; s32 idx; u8 pad2[0x418 - 0x3f8]; u32 flags[1]; };

struct Node_8009503C {
    u32 flags;
    u8 pad4[0x2C - 0x4];
    struct Node_8009503C *child;
    struct Node_8009503C *next;
};

struct Mtx_8009503C { f32 m[3][4]; };

struct Vec_800951AC { f32 x, y, z; };

struct Player_800951AC {
    u8 pad0[0x38];
    Vec_800951AC pos38;
    u8 pad44[0x2FC - 0x44];
    Vec_800951AC pos;
};

struct Berura_800951AC {
    u8 pad0[0x60];
    s32 angle;
    u8 pad64[0x2FC - 0x64];
    Vec_800951AC pos;
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
    virtual s32 m83();
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
    virtual s32 m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual s32 m103();
};

struct PartBase_800954E8 { u8 pad[0x18]; };

struct Part_800954E8 : PartBase_800954E8 {
    virtual ~Part_800954E8();
};

struct Berura_800954E8 {
    u8 pad0[0x18];
    void *vtbl;
    u8 pad1C[0x3D8 - 0x1C];
    u8 motionA[0x3F8 - 0x3D8];
    void *effect;
    u8 motionB[0x440 - 0x3FC];
    Part_800954E8 *parts[2];
    u8 arr[4][0x1C];
};

struct Ent_800959F8 { s32 f0; u8 *f4; };

struct Res_800959F8 { u8 pad[0x42C]; u8 *f42C; Ent_800959F8 *f430; };

struct T16_800959F8 { s32 f0; s32 f4; s32 f8; s32 fC; };

struct Atk_800959F8 { s32 w[4]; };

struct V3_800959F8 { f32 x, y, z; };

struct Elem_800959F8 {
    u8 *buf;
    s32 f4;
    s32 f8;
    s32 fC;
    f32 f10;
    f32 f14;
    s32 *f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    f32 f28, f2C, f30;
    s32 f34, f38, f3C;
    f32 f40, f44, f48;
    s32 f4C;
    s32 f50;
    u8 pad54[0x10];
};

struct VBase_14_d2ec4b { char pad[0x14]; };

struct VObj_14_d2ec4b : VBase_14_d2ec4b {
    virtual void m0();
    virtual s32 m1(s32);
    virtual s32 m2();
};

struct VBase_18_b345b0 { char pad[0x18]; };

struct VObj_18_b345b0 : VBase_18_b345b0 {
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
    virtual s32 m85(s16, s32);
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual s32 m93();
};

struct Sub_800955E0 { u8 b[0x1C]; };

struct Vec_800955E0 { f32 x, y, z; };

struct Self_800955E0 { u8 pad[0x418]; s32 f418[2]; Vec_800955E0 v420[2]; s32 f438[2]; u8 pad440[8]; Sub_800955E0 subs[4]; };
extern "C" {

s32 VecCopy__FP3VecPC3Vec(void *, void *);
Player_800951AC * get_player_data__10TObjPlayerFi(s32);
u16 get_entity_id(void *);
void queue_destruction__7TObjectFv(void *);
s32 dispatch_shared_handler_a__6TLobbyFl(s32);
s32 register_object__6TLobbyFl(s32);
s32 dispatch_shared_handler_b__6TLobbyFl(s32);
s32 register_boss__6TLobbyFl(s32);
void TLobby__sub_8001FE7C(void*, int);
u32 csnLookAt(void *, void *);
void * alloc__23TAdSinglePlyChrSelectGCFv(int);
s32 TObjEneRe7Berura__sub_80093470(void *, void *);
void state_patrol__16TObjEneRe7BeruraFPvi(void *arg0, s32 arg1);
void TObjEneRe7Berura__sub_80093888(u8 *actor, s32 arg1);
void TObjEneRe7Berura__sub_80093C80(u8 *arg0, s32 arg1);
void TObjEneRe7Berura__sub_800940E8(TObjEneRe7Berura *arg0, s32 arg1);
void TObjEneRe7Berura__sub_80094624(u8 *arg0, s32 arg1);
void TObjEneRe7Berura__sub_8009472C(u8 *arg0, s32 arg1);
void TObjEneRe7Berura__vt85(s32 arg0, u32 arg1, s32 arg2);
void TObjEneRe7Berura__sub_80094C68(TObjEneRe7Berura *self);
void TObjEneRe7Berura__sub_80094D98(u8 *arg0);
s32 TObjEneRe7Berura__sub_80094DB4(void *arg0);
s32 get_field_3D4_shifted__16TObjEneRe7BeruraFPv(void *arg0);
void set_data_and_draw_node_tree__16TObjEneRe7BeruraFii(int a0, int a1);
void draw_node_tree__16TObjEneRe7BeruraFPv(void *arg0);
void apply_attack_params__16TObjEneRe7BeruraFiPv(s32 arg0, u8 *arg1);
u8 TObjEneRe7Berura__sub_8009518C(O_8009518C *self);
void TObjEneRe7Berura__sub_80095328(void);
void vfunc_88__16TObjEneRe7BeruraFv(void *arg0);
void vfunc_61__16TObjEneRe7BeruraFv(void);
void vfunc_62__16TObjEneRe7BeruraFv(u8 *arg0);
void vfunc_63__16TObjEneRe7BeruraFv(void* p);
void vfunc_28__16TObjEneRe7BeruraFv(void);
void run_task__16TObjEneRe7BeruraFv(TObjEneRe7Berura *arg0);
Berura_800954E8 * __dt__16TObjEneRe7BeruraFv(Berura_800954E8 *self, s16 flag);
void * TObjEneRe7Berura__ct(void *arg0, void *arg1, void *arg2);
void fn_80095DD0(u8 *arg0);
void fn_80095DF4(u8 *arg0);
s32 spawn_punch__16TObjEneRe7BeruraFPv(void *);
s32 TObjPlayer__sub_800A0554(void *);
void *__dt__13TUnk_80490470Fv(void *arg0, s16 arg1);
s32 enemy_set_target_id(void *, u16);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
int reload_stats_keep_hp_tp__9TObjEneDDFv(void *self, void *a, void *b, void *c);
void reset_hp__9TObjEneDDFv(void *, s32, s32, s32);
void initialize_enemy_state__9TObjEneDDFv(void *, int);
s32 is_alive__9TObjEneDDFv(void *);
void init_model__9TObjEneDDFv(void *, void *, int);
s32 clear_attack_receipts__9TObjEneDDFv();
void invoke_initialization_hook__9TObjEneDDFv(void *, void *);
Res_800959F8 * load_enemy_bml_resource_named(void *, void *);
s32 load_enemy_bml_resource(u8 *arg0);
s32 set_field_378__9TObjEneDDFl(void *, s32, s32);
s32 create__12TObjEneSaverFPvPv(s32, s32);
s32 *__dt__11TBoss4Type3FPvs(s32 *arg0, s16 arg1);
void * init_trail_buffer__11TBoss4Type3FPvifff(void *arg0, s32 segs, f32 start, f32 end, f32 step);
s32 copy_target_state__14TObjEnePanarmsFPv(void *, int);
s32 angle_diff_s16(s32);
void mem_free(void*);
void *mem_alloc(u32 size);
void free_collision_body_parts(void *);
s32 play_sound_effect(s32, u32, s16, s32);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);
void __destroy_arr(void *, void *, u32, u32);
void __construct_array(void *, void *, void *, int, int);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
void bind_motion_context(s32 arg0, f32 farg0);
void compose_motion_node_matrix(void *arg0);
s32 matrix_mult_vec(int, void *, void *);
void copy_matrix__10TObjPlayerFUlUl(int, void *);
s32 subtract_vector(void *, void *);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 concat_matrix__10TObjPlayerFUlUl(s32, s32);
s32 push_matrix_from(void *, int, int, int);
s32 push_matrix();
s32 pop_matrix();
s32 set_global_param__8TObjFishFl(s32, void *);
}
void *destroy_buffer_pair(void *arg0, s16 arg1);
void get_current_matrix(void *);
void draw_chunk_model(void *arg0);

extern const s32 TObjEneRe7Berura__data_80439DA8[];
extern const s32 TObjEneRe7Berura__data_80439DB0[];
extern const s32 TObjEneRe7Berura__data_80439DB8[];
extern s32 TObjEneRe7Berura__data_805007D4[];
extern Elem_800959F8 TObjEneRe7Berura__detached_part_states[];
extern s32 TObjEneRe7Berura__stat_handle_table[1];
extern s32 TObjEneRe7Berura__shared_object_handles[1];
extern u32 TObjEneRe7Berura__shared_resource;
extern s32 TObjEneRe7Berura__node_matrix_cursor;
extern const f32 TObjEneRe7Berura__data_805D9724;
extern const f32 TObjEneRe7Berura__data_805D972C;
extern const f32 TObjEneRe7Berura__data_805D9730;
extern const f32 TObjEneRe7Berura__data_805D9738;
extern const f32 TObjEneRe7Berura__data_805D9740;
extern const f32 TObjEneRe7Berura__data_805D9764;
extern s32 __dt__13TUnk_804949A8Fv[];
extern s32 init_and_activate__10TObjPlayerFv[];
extern s32 lbl_80439DA0[];
extern Atk_800959F8 ene_re7_berura_attack_def;
extern u8 lbl_80439EF8[];
extern s32 identity_matrix[];
extern void *lbl_805D2988;
extern s32 TObjEneRe7Berura__handler_table_a[1];
extern s32 re7_berura_demo_state;
extern s32 lbl_805D4F6C;
extern s32 re7_berura_demo_camera_ptr;
extern s32 berura_demo_flag;
extern s32 re7_berura_demo_flag;
extern s32 TObjEneRe7Berura__demo_target;
extern u32 re7_berura_static_buffer;
extern s32 berura_node_matrix_ptr_a;
extern s32 berura_node_matrix_ptr_b;
extern u32 belra_uv_animation_buffer;
extern s32 berura_attack_node_range_start;
extern s32 berura_attack_node_range_end;
extern s32 berura_attack_node_vec_ptr;
extern u32 belra_trail_buffer;
extern const s32 lbl_805D9718[1];
extern const s32 lbl_805D971C[1];
extern const s32 lbl_805D9720[1];
extern const f32 lbl_805D974C;
extern const f32 lbl_805D9770;
extern const f32 lbl_805D9774;
extern const f32 lbl_805D9778;
extern const f32 lbl_805D977C;
extern const f32 lbl_805D9780;
extern const f32 lbl_805D9784;
extern const f32 lbl_805D9788;
extern void *tl_04;

#define PADV virtual void CAT(pv, __LINE__)();
#define PADV4 virtual void CAT(pa, __LINE__)(); virtual void CAT(pb, __LINE__)(); virtual void CAT(pc, __LINE__)(); virtual void CAT(pd, __LINE__)();
extern "C" {
extern "C" void vfunc_6__13TUnk_804B9870FPsl();
extern "C" void vfunc_103__9TObjEneDDFPUc();
extern "C" void vfunc_79__9TObjEneDDFv();
extern "C" void TObjEneDD__vt82();
extern "C" void vfunc_85__9TObjEneDDFv();
extern "C" void vfunc_86__9TObjEneDDFv();
extern "C" void vfunc_89__9TObjEneDDFv();
extern "C" void vfunc_90__9TObjEneDDFv();
extern "C" void vfunc_91__9TObjEneDDFv();
extern "C" void vfunc_92__9TObjEneDDFv();
extern "C" void vfunc_93__9TObjEneDDFv();
extern "C" void vfunc_94__9TObjEneDDFv();
extern "C" void vfunc_95__9TObjEneDDFv();
extern "C" void vfunc_96__9TObjEneDDFv();
extern "C" void vfunc_97__9TObjEneDDFv();
extern "C" void vfunc_98__9TObjEneDDFv();
extern "C" void vfunc_99__9TObjEneDDFv();
extern "C" void vfunc_100__9TObjEneDDFv();
extern "C" void vfunc_101__9TObjEneDDFPUc();
extern "C" void vfunc_102__9TObjEneDDFv();
extern "C" int TObjEneEpsilon__vt101(void *p);
extern "C" void vfunc_83__12TObjEneDD_STFv();
extern "C" void vfunc_83__16TObjEneRe7BeruraFv();
extern "C" void vfunc_105__16TObjEneRe7BeruraFv();
extern "C" void vfunc_29__13TUnk_804806E8Fv();
extern "C" void recalc_stats__13TUnk_804806E8Fv();
extern "C" void consume_timer_field__13TUnk_804806E8Fl();
extern "C" void vfunc_67__13TUnk_804806E8Ff();
extern "C" void vfunc_66__13TUnk_804806E8Fv();
extern "C" void get_anim_node_position__13TUnk_804806E8FlP3Vec();
extern "C" void vfunc_60__13TUnk_804806E8Fv();
extern "C" void vfunc_59__13TUnk_804806E8Fv();
extern "C" void vfunc_58__13TUnk_804806E8Fv();
extern "C" void apply_slow_status__13TUnk_804806E8Fv();
extern "C" void update_shock_clock__13TUnk_804806E8Fv();
extern "C" void vfunc_43__13TUnk_804806E8Fv();
extern "C" void vfunc_18__13TUnk_804806E8FPUc();
extern "C" void interact__13TUnk_804AF8A0Fl();
extern "C" void vfunc_74__9TObjEnemyFl();
extern "C" void apply_hit_message_flags__9TObjEnemyFPv();
extern "C" void add_actor_exp__13TUnk_804806E8Fl();
extern "C" void apply_action_hold_status__13TUnk_804806E8Ff();
extern "C" void apply_anti_technique__13TUnk_804806E8Fl();
extern "C" void apply_attack_stat_status__13TUnk_804806E8FPv();
extern "C" void apply_confusion_status__13TUnk_804806E8Fv();
extern "C" void apply_knockback_from_attacker__13TUnk_804806E8FPUc();
extern "C" void apply_movement_ailment__13TUnk_804806E8Fl();
extern "C" void apply_object_set_data__13TUnk_804B9870FPv();
extern "C" void apply_paralysis__13TUnk_804806E8Fv();
extern "C" void apply_poison_status__13TUnk_804806E8Fv();
extern "C" void apply_set_data__9TObjEnemyFPv();
extern "C" void apply_shock_status__13TUnk_804806E8Fv();
extern "C" void apply_switch_attack__13TUnk_804806E8Fv();
extern "C" void calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf();
extern "C" void classify_actor_view_detail__13TUnk_804B9870Ffff();
extern "C" void clear_all_status_effects__13TUnk_804806E8Fv();
extern "C" void clear_harmful_statuses__13TUnk_804806E8Fv();
extern "C" void cure_paralysis__13TUnk_804806E8Fv();
extern "C" void cure_poison_ailment__13TUnk_804806E8Fv();
extern "C" void enemy_spawn_jellen_effect__13TUnk_804806E8Fv();
extern "C" void enemy_spawn_zalure_effect__13TUnk_804806E8Fv();
extern "C" void vfunc_78__13TUnk_804806E8Fl();
extern "C" void vfunc_77__13TUnk_804806E8Fv();
extern "C" void vfunc_76__13TUnk_804806E8Fv();
extern "C" void vfunc_75__13TUnk_804806E8Ff();
extern "C" void clear_lobby_object_state__9TObjEnemyFv();
extern "C" void vfunc_9__13TUnk_804806E8Fv();
extern "C" void get_actor_level_index__13TUnk_804806E8Fv();
extern "C" void get_name__9TObjEnemyFv();
extern "C" void get_pos__13TUnk_804806E8Fl();
extern "C" void is_actor_cadence_frame__13TUnk_804806E8Fl();
extern "C" void is_target_in_attack_range__13TUnk_804806E8Fv();
extern "C" u8 lbl_80439DC0[];
extern "C" u8 lbl_80439DD4[];
extern "C" u8 lbl_80439DEC[];
extern "C" u8 lbl_80439E04[];
extern "C" u8 lbl_80439E18[];
extern "C" u8 lbl_80439E30[];
extern "C" u8 lbl_80439E48[];
extern "C" u8 lbl_80439E60[];
extern "C" u8 lbl_80439E74[];
extern "C" u8 lbl_80439E88[];
extern "C" void receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__13TUnk_804806E8FPvf();
extern "C" void receive_weapon_special_attack__13TUnk_804806E8FPvPv();
extern "C" void apply_defense_stat_status__13TUnk_804806E8FPv();
extern "C" void render__16TObjEneRe7BeruraFv();
extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);
extern "C" void reset_motion_fields__13TUnk_804806E8Fv();
extern "C" void reset_pose__13TUnk_804806E8Fv();
extern "C" void roll_physical_accuracy__13TUnk_804806E8FPvlf();
extern "C" void select_melee_contact_body__13TUnk_804806E8FPvf();
extern "C" void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
extern "C" void try_start_action__13TUnk_804806E8Fll();
extern "C" void update_action_hold_status__13TUnk_804806E8Fv();
extern "C" s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void update_actor_ground_y__13TUnk_804806E8Fv();
extern "C" s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
extern "C" s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
extern "C" void update_flag30_timer__13TUnk_804806E8Fv();
extern "C" void update_movement_status__13TUnk_804806E8Fv();
extern "C" void update_object_view_visibility__13TUnk_804B9870Fff();
extern "C" void update_poison_status__13TUnk_804806E8Fv();
extern void *bm_ene_re7_berura_model_names[2];
extern void *bm_ene_re7_berura_motion_names[9];
void *berura_init_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8048F66C[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41000000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
__declspec(section ".data") void *bm_ene_re7_berura_model_names[2] = {
    (void *)&lbl_80439DC0, (void *)0x0,
};
void *bm_ene_re7_berura_motion_names[9] = {
    (void *)&lbl_80439DD4, (void *)&lbl_80439DEC, (void *)&lbl_80439E04, (void *)&lbl_80439E18,
    (void *)&lbl_80439E30, (void *)&lbl_80439E48, (void *)&lbl_80439E60, (void *)&lbl_80439E74,
    (void *)0x0,
};
void *ene_berura_bml_descriptor[4] = {
    (void *)&lbl_80439E88, (void *)&bm_ene_re7_berura_model_names, (void *)&bm_ene_re7_berura_motion_names, (void *)0x10008,
};
void *TObjEneRe7Berura__animation_definitions[32] = {
    (void *)0x10000, (void *)0x6, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x10000, (void *)0x7, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x0, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x20000, (void *)0x3, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x20000, (void *)0x5, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x10000, (void *)0x4, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x1, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x2, (void *)0x3f4ccccd, (void *)0x0,
};
void *__vt__16TObjEneRe7Berura[107] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__16TObjEneRe7BeruraFv, (void *)&run_task__16TObjEneRe7BeruraFv,
    (void *)&render__16TObjEneRe7BeruraFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&vfunc_9__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&vfunc_28__16TObjEneRe7BeruraFv, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__13TUnk_804806E8Fv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_804806E8Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TUnk_804806E8Fv, (void *)&apply_paralysis__13TUnk_804806E8Fv, (void *)&apply_slow_status__13TUnk_804806E8Fv, (void *)&apply_confusion_status__13TUnk_804806E8Fv,
    (void *)&apply_movement_ailment__13TUnk_804806E8Fl, (void *)&apply_shock_status__13TUnk_804806E8Fv, (void *)&clear_harmful_statuses__13TUnk_804806E8Fv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__13TUnk_804806E8Fv, (void *)&vfunc_59__13TUnk_804806E8Fv,
    (void *)&vfunc_60__13TUnk_804806E8Fv, (void *)&vfunc_61__16TObjEneRe7BeruraFv, (void *)&vfunc_62__16TObjEneRe7BeruraFv, (void *)&vfunc_63__16TObjEneRe7BeruraFv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&recalc_stats__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__9TObjEneDDFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&TObjEneDD__vt82, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&TObjEneRe7Berura__vt85,
    (void *)&vfunc_88__16TObjEneRe7BeruraFv, (void *)&vfunc_89__9TObjEneDDFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&TObjEneEpsilon__vt101, (void *)&vfunc_83__16TObjEneRe7BeruraFv, (void *)&vfunc_105__16TObjEneRe7BeruraFv,
};
#define berura_init_params ((u8 *)berura_init_params)
#define lbl_8048F66C ((u8 *)lbl_8048F66C)
#define ene_berura_bml_descriptor ((u8 *)ene_berura_bml_descriptor)
#define TObjEneRe7Berura__animation_definitions ((T16_800959F8 *)TObjEneRe7Berura__animation_definitions)
#define __vt__16TObjEneRe7Berura ((s32 *)__vt__16TObjEneRe7Berura)

void TObjEneRe7Berura::state_attack(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r5;

    switch (arg1) {
    case 4:
        this->m_b8 = 0;
        this->vfunc_95();
        temp_r5 = *(s32 *)((s8 *)arg0 + 0x3C0);
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (temp_r5 & ~5);
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 2);
        set_field_378__9TObjEneDDFl(arg0, 3, temp_r5);
        TObjPlayer__sub_800A0554(arg0 + 0x3D8);
        ((TBoss3Volopt *)(arg0 + 0x38))->play_area_se_with_particle();
        init_fields4B8();
        return;
    case 3:
        if (((V_Sub_80094994 *) (arg0 + 0x3D8))->m5() != 0) {
            ((TObjEneDD *)arg0)->transition_enemy_state((s16)3);
        }
        return;
    case 0:
        this->vfunc_102();
        this->vfunc_88();
        return;
    case 5:
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFFD);
        break;
    }
}

void TObjEneRe7Berura::handle_message_transition(s32 msg) {
    switch (msg) {
    case 0:
        return;
    case 3:
        transition_enemy_state((s16)1);
        break;
    }
}

void TObjEneRe7Berura__vt85(s32 arg0, u32 arg1, s32 mode) {
    switch (arg1) {
    case 0:
        ((TObjEneRe7Berura *)arg0)->handle_message_transition(mode);
        return;
    case 1:
        ((TObjEneRe7Berura *)arg0)->state_attack(mode);
        return;
    case 3:
        TObjEneRe7Berura__sub_8009472C((u8 *)arg0, (mode));
        return;
    case 2:
        TObjEneRe7Berura__sub_80094624((u8 *)arg0, (mode));
        return;
    case 8:
        ((TObjEneRe7Berura *)arg0)->handle_state(mode);
        return;
    case 4:
        TObjEneRe7Berura__sub_800940E8((TObjEneRe7Berura *)((u8 *)arg0), (mode));
        return;
    case 5:
        TObjEneRe7Berura__sub_80093C80((u8 *)arg0, (mode));
        return;
    case 6:
        TObjEneRe7Berura__sub_80093888((u8 *)arg0, (mode));
        return;
    case 7:
        ((TObjEneRe7Berura *)arg0)->run_flash_warning_state(mode);
        return;
    case 9:
        state_patrol__16TObjEneRe7BeruraFPvi((void *)arg0, (mode));
        return;
    case 10:
        TObjEneRe7Berura__sub_80093470((void *)arg0, (void *)mode);
        return;
    case 11:
        ((TObjEneRe7Berura *)arg0)->update_death_state(mode);
    default:
        return;
    }
}

s32 TObjEneRe7Berura::check_death_trigger() {
    struct VObj_80094BA4_80094994 *o = (struct VObj_80094BA4_80094994 *)this;
    if (o->m97() != 0) {
        transition_enemy_state((s16)9);
        return 1;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
void TObjEneRe7Berura::play_band_sound() {
    u8 *arg0 = (u8 *)this;
    if ((objInBand((GameObj *)arg0, (f32)lbl_805D9770) != 0) || (objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)TObjEneRe7Berura__data_805D9764)) != 0)) {
        play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003BC1F), (u32)(arg0 + 0x38), 0, 0);
    }
}
#pragma pop

void TObjEneRe7Berura__sub_80094C68(TObjEneRe7Berura *self) {
    reload_stats_keep_hp_tp__9TObjEneDDFv(self, ((void * *)TObjEneRe7Berura__stat_handle_table)[TObjEneRe7Berura__data_80439DA8[0]],
                            ((void * *)TObjEneRe7Berura__data_805007D4)[TObjEneRe7Berura__data_80439DB0[0]],
                            ((void * *)TObjEneRe7Berura__shared_object_handles)[TObjEneRe7Berura__data_80439DB8[0]]);
}

void TObjEneRe7Berura::reload_stats_from_tables() {
    reload_stats_keep_hp_tp__9TObjEneDDFv(this, ((void * *)TObjEneRe7Berura__stat_handle_table)[TObjEneRe7Berura__data_80439DA8[1]],
                            ((void * *)TObjEneRe7Berura__data_805007D4)[TObjEneRe7Berura__data_80439DB0[1]],
                            ((void * *)TObjEneRe7Berura__shared_object_handles)[TObjEneRe7Berura__data_80439DB8[1]]);
}

void TObjEneRe7Berura::destroy_parts() {
    Obj_80094D3C *self = (Obj_80094D3C *)this;
    s32 i;
    for (i = 0; i < 2; i++) {
        if (self->parts[i] != 0) {
            queue_destruction__7TObjectFv(self->parts[i]);
            self->parts[i] = 0;
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TObjEneRe7Berura__sub_80094D98(u8 *arg0) {
    u8 *temp_r3;
    temp_r3 = (u8 *)(arg0 + (*(s32 *)((s8 *)arg0 + 0x3F4) * 4));
    *(s32 *)((s8 *)temp_r3 + 0x418) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x418) & 0xFFFFFFFD);
}
#pragma pop

#undef PADV
#undef PADV4
s32 TObjEneRe7Berura__sub_80094DB4(void *arg0) {
    return *(s32 *)((s8 *)arg0 + 0x3D4) * 0x96;
}

u8 TObjEneRe7Berura::is_over_limit() {
    int var_r4;
    s32 temp_r5;
    s32 temp_r0;

    temp_r5 = this->m_4bc;
    var_r4 = 0;
    temp_r0 = this->m_4b8;
    if ((temp_r5 >= temp_r0) || (temp_r5 <= (s32) -temp_r0)) {
        var_r4 = 1;
    }
    return (u8) var_r4;
}

s32 TObjEneRe7Berura::step_toward_target(s32 arg1, s32 arg2) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r3;
    s32 var_r31;

    var_r31 = 0;
    temp_r3 = angle_diff_s16(this->rotation_y);
    if (temp_r3 > arg2) {
        this->rotation_y = (s32) (this->rotation_y + arg2);
        temp_r0 = this->m_4bc;
        if (temp_r0 < 0) {
            this->m_4bc = 0;
        } else {
            this->m_4bc = (s32) (temp_r0 + arg2);
        }
    } else if (temp_r3 < (s32) -arg2) {
        this->rotation_y = (s32) (this->rotation_y - arg2);
        temp_r0_2 = this->m_4bc;
        if (temp_r0_2 > 0) {
            this->m_4bc = 0;
        } else {
            this->m_4bc = (s32) (temp_r0_2 - arg2);
        }
    } else {
        this->rotation_y = arg1;
        var_r31 = 1;
    }
    return var_r31;
}

void TObjEneRe7Berura::init_fields4B8() {
    this->m_4b8 = ((s32 (*)(void))get_field_3D4_shifted__16TObjEneRe7BeruraFPv)();
    this->m_4bc = 0;
}

s32 get_field_3D4_shifted__16TObjEneRe7BeruraFPv(void *arg0) {
    return *(s32 *)((s8 *)arg0 + 0x3D4) << 0xF;
}

void TObjEneRe7Berura::init_part(s32 arg0) {
    s32 *temp_r3;

    set_global_param__8TObjFishFl(*(s32 *)((s8 *)(*(void **)((s8 *)(*(void * *)&TObjEneRe7Berura__shared_resource) + 0x42C)) + 0xC), (*(void * *)&TObjEneRe7Berura__shared_resource));
    temp_r3 = (s32 *)((s8 *)((s32 *)TObjEneRe7Berura__detached_part_states) + (arg0 * 0x64));
    ((s32 (*)(void *, s32))set_data_and_draw_node_tree__16TObjEneRe7BeruraFii)((s32 *)((s8 *)temp_r3 + 0x20), *temp_r3);
}

void set_data_and_draw_node_tree__16TObjEneRe7BeruraFii(int a0, int a1) { (*(int *)&TObjEneRe7Berura__node_matrix_cursor) = a1; ((int (*)(void))draw_node_tree__16TObjEneRe7BeruraFPv)(); }

void draw_node_tree__16TObjEneRe7BeruraFPv(void *arg0) {
    s32 temp_r31;
    s32 temp_r4;
    void *var_r30;

    var_r30 = arg0;
    do {
        push_matrix();
        temp_r4 = TObjEneRe7Berura__node_matrix_cursor;
        TObjEneRe7Berura__node_matrix_cursor = temp_r4 + 0x30;
        concat_matrix__10TObjPlayerFUlUl(0, temp_r4);
        temp_r31 = *(s32 *)((s8 *)var_r30 + 0);
        if (!(temp_r31 & 8)) {
            draw_chunk_model((void *)(*(s32 *)((s8 *)var_r30 + 4)));
        }
        pop_matrix();
        if (!(temp_r31 & 0x10)) {
            draw_node_tree__16TObjEneRe7BeruraFPv((void *)(*(void **)((s8 *)var_r30 + 0x2C)));
        }
        var_r30 = *(void **)((s8 *)var_r30 + 0x30);
    } while (var_r30 != NULL);
}

void apply_attack_params__16TObjEneRe7BeruraFiPv(s32 child, u8 *arg1) {
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;

    temp_r6 = *(s32 *)((s8 *)arg1 + 0);
    TObjEneRe7Berura__node_matrix_cursor = temp_r6;
    temp_r5 = *(s32 *)((s8 *)arg1 + 4);
    berura_attack_node_range_start = temp_r5;
    temp_r4 = *(s32 *)((s8 *)arg1 + 8);
    berura_attack_node_range_end = temp_r4;
    berura_attack_node_vec_ptr = (long) (arg1 + 0x58);
    push_matrix_from(identity_matrix, temp_r4, temp_r5, temp_r6);
    TObjEneRe7Berura::collect_node_matrices((void *)child, 0);
    pop_matrix();
}

#define V ((f32 *)berura_attack_node_vec_ptr)
#define node ((Node_8009503C *)arg0)
s32 TObjEneRe7Berura::collect_node_matrices(void *arg0, int idx) {
    Mtx_8009503C m;
    u32 flags;
    do {
        push_matrix();
        compose_motion_node_matrix(node);
        flags = node->flags;
        if (idx == berura_attack_node_range_start) {
            V[0] = TObjEneRe7Berura__data_805D972C;
            V[1] = TObjEneRe7Berura__data_805D972C;
            V[2] = TObjEneRe7Berura__data_805D972C;
            matrix_mult_vec(0, V, V);
            V[1] = V[1] + lbl_805D9774;
            V[2] = V[2] + TObjEneRe7Berura__data_805D9764;
            get_current_matrix(&m);
            ((s32 (*)(void *))push_matrix_from)(identity_matrix);
            translate_matrix(0, -V[0], -V[1], -V[2]);
            ((s32 (*)(s32, void *))concat_matrix__10TObjPlayerFUlUl)(0, &m);
            get_current_matrix(&m);
            pop_matrix();
            copy_matrix__10TObjPlayerFUlUl(0, &m);
        }
        if (idx >= berura_attack_node_range_start && idx <= berura_attack_node_range_end) {
            s32 p = TObjEneRe7Berura__node_matrix_cursor;
            TObjEneRe7Berura__node_matrix_cursor = p + 0x30;
            get_current_matrix((void *)p);
        }
        idx++;
        if (!(flags & 0x10)) {
            idx = TObjEneRe7Berura::collect_node_matrices(node->child, idx);
        }
        pop_matrix();
        arg0 = node->next;
    } while (arg0 != NULL);
    return idx;
}

u8 TObjEneRe7Berura__sub_8009518C(O_8009518C *self) {
    return !(self->flags[self->idx] & 2);
}

#pragma push
#pragma fp_contract on
s32 TObjEneRe7Berura::acquire_target_in_view() {
    Vec_800951AC v;
    s32 n;
    Player_800951AC *p;
    u16 id;
    s32 i;
    f32 c;
    f32 s;
    f32 limit;
    f32 d;
    f32 best;
    Berura_800951AC *self = (Berura_800951AC *)this;
    best = TObjEneRe7Berura__data_805D972C;
    id = 0xFFFF;
    limit = cos_table_lookup(0xAAA);
    s = sin_table_lookup(self->angle);
    c = cos_table_lookup(self->angle);
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        p = get_player_data__10TObjPlayerFi(i);
        if (is_alive__9TObjEneDDFv(p) != 0) {
            VecCopy__FP3VecPC3Vec(&v, &p->pos38);
            subtract_vector(&v, &self->pos);
            v.y = TObjEneRe7Berura__data_805D972C;
            d = ((TObjBoss2Tunnel *)(&v))->clamp_velocity();
            if (d < TObjEneRe7Berura__data_805D9724 && d > best &&
                s * v.x + c * v.z > limit &&
                csnLookAt(&self->pos, &p->pos) == 0) {
                id = get_entity_id(p);
                best = d;
            }
        }
    }
    if (id != 0xFFFF) {
        enemy_set_target_id(self, id);
        return 1;
    }
    return 0;
}
#pragma pop

#undef V
#undef node
void TObjEneRe7Berura__sub_80095328(void) {  }

void TObjEneRe7Berura::vfunc_88() {
    *(f32 *)((s8 *)this->m_a4 + 4) = (f32) (this->m_300 - *(f32 *)((s8 *)this + 0x3C));
}

void TObjEneRe7Berura::update_collision_center() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg0 + 0x2FC) = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    *(f32 *)((s8 *)arg0 + 0x300) = (f32) (TObjEneRe7Berura__data_805D9764 + *(f32 *)((s8 *)arg0 + 0x3C));
    *(f32 *)((s8 *)arg0 + 0x304) = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    ((s32 (*)(void *, void *, void *, f32))VecCopy__FP3VecPC3Vec)(arg0 + 0x74, arg0 + 0x2FC, arg0, TObjEneRe7Berura__data_805D9764);
}

void TObjEneRe7Berura::vfunc_61() {  }

void TObjEneRe7Berura::vfunc_62() {
    u8 *arg0 = (u8 *)this;
    if ((*(s32 *)((s8 *)arg0 + 0x3C0) & 4) || ((s32) (this->referenceHp - this->hp) < (s32) ((s16) this->hpmax / 5))) {
        clear_attack_receipts__9TObjEneDDFv();
        return;
    }
    if ((s16) this->mode != 0xA) {
        ((TObjEneDD *)arg0)->transition_enemy_state((s16)((void*)(0xA)));
    }
}

void TObjEneRe7Berura::vfunc_63() { if (this->mode != 11) { transition_enemy_state((s16)((void*)11)); } }

void TObjEneRe7Berura::vfunc_28() {  }

void run_task__16TObjEneRe7BeruraFv(TObjEneRe7Berura *ene_re7_berura) {
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TObjEneRe7Berura *)(ene_re7_berura))->vfunc_83();
        return;
    }
    if (((VObj_18 *)(ene_re7_berura))->m81() != 4) {
        ((TObjEneRe7Berura *)(ene_re7_berura))->vfunc_85();
        ene_re7_berura->m_3ec = (s32) (ene_re7_berura->m_3ec + *(s32 *)((s8 *)ene_re7_berura + 0x3CC));
        ene_re7_berura->m_3ec = (s32) (u8) ene_re7_berura->m_3ec;
    }
    ene_re7_berura->update_collision_center();
    ((TBoss8Dragon *)ene_re7_berura)->set_player_state_default();
    ((TObjEneRe7Berura *)(ene_re7_berura))->vfunc_100();
}

Berura_800954E8 *__dt__16TObjEneRe7BeruraFv(Berura_800954E8 *self, s16 flag) {
    s32 i;
    if (self != 0) {
        self->vtbl = ((s32 *)&*__vt__16TObjEneRe7Berura);
        ((TObjEneRe7Berura *)self)->destroy_parts();
        for (i = 0; i < 2; i++) {
            if (self->parts[i] != 0) {
                delete self->parts[i];
                self->parts[i] = 0;
            }
        }
        if (self->effect != 0) {
            queue_destruction__7TObjectFv(self->effect);
            self->effect = 0;
        }
        free_collision_body_parts(self);
        __destroy_arr(self->arr, (void *)((s32 *)&__dt__13TUnk_804949A8Fv), 0x1C, 4);
        __dt__13TUnk_80490470Fv(self->motionB, -1);
        __dt__13TUnk_80490470Fv(self->motionA, -1);
        __dt__12TObjEneDD_STFv(self, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}

void TObjEneRe7Berura::init_enemy() {
    u8 *arg0 = (u8 *)this;
    Self_800955E0 *S = (Self_800955E0 *)arg0;
    s32 i;
    s32 j;
    ((TObjEneDD *)arg0)->init_position_vectors();
    *(s32 *)((s8 *)arg0 + 0x34) = *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjEneRe7Berura__shared_resource) + 0x42C)) + 8);
    *(s32 *)((s8 *)arg0 + 0x24) = *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjEneRe7Berura__shared_resource) + 0x42C)) + 0xC);
    init_model__9TObjEneDDFv(arg0, lbl_8048F66C, 1);
    ((TObjMotion *)arg0)->set_field_d8((s32)(((u8 *)TObjEneRe7Berura__animation_definitions)));
    ((TObjMotion *)arg0)->set_field_dc(*(s32 *)((s8 *)(*(u8 * *)&TObjEneRe7Berura__shared_resource) + 0x430));
    *(s16 *)((s8 *)arg0 + 0xB8) = 0;
    ((TObjMotion *)arg0)->set_animation(*(s16 *)((s8 *)arg0 + 0xB8));
    ((TObjMotion *)arg0)->set_field_b8(*(s16 *)((s8 *)arg0 + 0xB8));
    reset_hp__9TObjEneDDFv(arg0, TObjEneRe7Berura__stat_handle_table[TObjEneRe7Berura__data_80439DA8[0]],
        TObjEneRe7Berura__data_805007D4[TObjEneRe7Berura__data_80439DB0[0]],
        TObjEneRe7Berura__shared_object_handles[TObjEneRe7Berura__data_80439DB8[0]]);
    ((TObjEneDD *)arg0)->set_state_8();
    *(u8 **)((s8 *)arg0 + 0x350) = berura_init_params;
    initialize_enemy_state__9TObjEneDDFv(arg0, 0x25);
    *(f32 *)((s8 *)arg0 + 0x37C) = TObjEneRe7Berura__data_805D9730;
    ((TObjEneDD_ST *)arg0)->enemy_init_acquire_period(0x3C);
    ((TObjEneDD_ST *)arg0)->enemy_init_validate_period(0x3C);
    *(s32 *)((s8 *)arg0 + 0x3C0) = 0;
    *(s32 *)((s8 *)arg0 + 0x3C4) = -1;
    *(s32 *)((s8 *)arg0 + 0x3C8) = 0xFF000000;
    *(s32 *)((s8 *)arg0 + 0x3CC) = 0;
    *(s32 *)((s8 *)arg0 + 0x3D0) = 0;
    *(s32 *)((s8 *)arg0 + 0x3D4) = 1;
    ((VObj_14_d2ec4b *)(arg0 + 0x3D8))->m2();
    *(s32 *)((s8 *)arg0 + 0x3F4) = 1;
    *(s32 *)((s8 *)arg0 + 0x3F8) = spawn_punch__16TObjEneRe7BeruraFPv(arg0);
    ((VObj_14_d2ec4b *)(arg0 + 0x3FC))->m2();
    if (TObjEneDD::check_v2_mode() != 0) {
        ((VObj_14_d2ec4b *)(arg0 + 0x3FC))->m1(0xA);
    }
    for (i = 0; i < 2; i++) {
        S->f418[i] = 0;
        ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&S->v420[i], arg0 + 0x38);
        S->f438[i] = 0;
    }
    *(s32 *)((s8 *)arg0 + 0x440) = create__12TObjEneSaverFPvPv(0xFF00FF00, 0xA0703030);
    *(s32 *)((s8 *)arg0 + 0x444) = create__12TObjEneSaverFPvPv(0xFF00FF00, 0xA0703030);
    for (j = 0; j < 4; j++) {
        ((TObjPlayer *)(&S->subs[j]))->activate_and_dispatch();
    }
    *(s32 *)((s8 *)arg0 + 0x4B8) = 0;
    *(s32 *)((s8 *)arg0 + 0x4BC) = 0;
    *(s32 *)((s8 *)arg0 + 0x4C0) = 0;
    *(s32 *)((s8 *)arg0 + 0x4C4) = 0;
    *(s32 *)((s8 *)arg0 + 0x4C8) = 0;
    *(s32 *)((s8 *)arg0 + 0x4CC) = 0;
    *(f32 *)((s8 *)arg0 + 0x4D0) = TObjEneRe7Berura__data_805D972C;
    *(f32 *)((s8 *)arg0 + 0x4D4) = TObjEneRe7Berura__data_805D972C;
    *(f32 *)((s8 *)arg0 + 0x4D8) = TObjEneRe7Berura__data_805D972C;
    *(f32 *)((s8 *)arg0 + 0x4DC) = TObjEneRe7Berura__data_805D972C;
    *(f32 *)((s8 *)arg0 + 0x4E0) = TObjEneRe7Berura__data_805D972C;
    this->vfunc_95();
    *(s16 *)((s8 *)arg0 + 0x326) = 0;
    ((VObj_18_b345b0 *)arg0)->m85(*(s16 *)((s8 *)arg0 + 0x326), 4);
}

void *TObjEneRe7Berura__ct(void *ene_re7_berura, void *arg1, void *arg2) {
    ((TObjEneDD_ST *)ene_re7_berura)->init_object();
    *(s32 **)((s8 *)ene_re7_berura + 0x18) = __vt__16TObjEneRe7Berura;
    ((TUnk_80490470 *)((char *)ene_re7_berura + 984))->init_vtable_and_field18();
    ((TUnk_80490470 *)((char *)ene_re7_berura + 1020))->init_vtable_and_field18();
    __construct_array((void *)((char *)ene_re7_berura + 1096), init_and_activate__10TObjPlayerFv, __dt__13TUnk_804949A8Fv, 28, 4);
    *(void * *)&((TObjEneRe7Berura *)ene_re7_berura)->m_name = lbl_805D2988;
    invoke_initialization_hook__9TObjEneDDFv(ene_re7_berura, arg2);
    ((void (*)(void *))TObjEneRe7Berura__sub_80095328)(ene_re7_berura);
    ((TObjEneRe7Berura *)ene_re7_berura)->init_enemy();
    return ene_re7_berura;
}

void TObjEneRe7Berura::destroy_children() {
    if ((u32) belra_trail_buffer != 0U) {
        __dt__11TBoss4Type3FPvs((s32 *)belra_trail_buffer, 1);
        belra_trail_buffer = 0U;
    }
    if ((u32) belra_uv_animation_buffer != 0U) {
        destroy_buffer_pair((void *)belra_uv_animation_buffer, 1);
        belra_uv_animation_buffer = 0U;
    }
    if ((u32) re7_berura_static_buffer != 0U) {
        mem_free((void*)re7_berura_static_buffer);
        re7_berura_static_buffer = 0U;
    }
    if ((u32) TObjEneRe7Berura__shared_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjEneRe7Berura__shared_resource, 1);
        TObjEneRe7Berura__shared_resource = 0U;
    }
}

void *TObjEneRe7Berura::create() {
    void *o = __nw__7TObjectFUl(0x4E4);
    if (o != NULL) {
        o = TObjEneRe7Berura__ct(o, tl_04, this);
    }
    return o;
}

f32 lbl_805007C8[3];

__declspec(section ".data") s32 TObjEneRe7Berura__data_805007D4[2];

Elem_800959F8 TObjEneRe7Berura__detached_part_states[2];

#define RES ((Res_800959F8 *)TObjEneRe7Berura__shared_resource)
void TObjEneRe7Berura::load_static_resources() {
    s32 pair[4];
    V3_800959F8 vecs[4];
    Res_800959F8 *r;
    u32 m;
    u8 *buf;
    s32 i;
    void *p;
    if (TObjEneDD::check_v2_mode() != 0) {
        r = load_enemy_bml_resource_named(ene_berura_bml_descriptor, lbl_80439EF8);
    } else {
        r = (Res_800959F8 *)load_enemy_bml_resource(ene_berura_bml_descriptor);
    }
    TObjEneRe7Berura__shared_resource = (u32)r;
    lbl_805007C8[0] = TObjEneRe7Berura__data_805D972C;
    lbl_805007C8[1] = TObjEneRe7Berura__data_805D972C;
    lbl_805007C8[2] = TObjEneRe7Berura__data_805D972C;
    re7_berura_demo_state = 0;
    lbl_805D4F6C = 0;
    re7_berura_demo_camera_ptr = 0;
    berura_demo_flag = 0;
    re7_berura_demo_flag = 0;
    TObjEneRe7Berura__demo_target = 0;
    m = *(u32 *)(r->f42C + 8);
    buf = (u8 *)mem_alloc(0x660);
    re7_berura_static_buffer = (u32)buf;
    TObjEneRe7Berura__detached_part_states[0].buf = buf;
    TObjEneRe7Berura__detached_part_states[1].buf = buf + 0x330;
    TObjEneRe7Berura__detached_part_states[0].f4 = 0x21;
    TObjEneRe7Berura__detached_part_states[0].f8 = 0x31;
    TObjEneRe7Berura__detached_part_states[1].f4 = 0x38;
    TObjEneRe7Berura__detached_part_states[1].f8 = 0x48;
    TObjEneRe7Berura__detached_part_states[0].fC = 3;
    TObjEneRe7Berura__detached_part_states[0].f10 = TObjEneRe7Berura__data_805D9764;
    TObjEneRe7Berura__detached_part_states[0].f14 = TObjEneRe7Berura__data_805D9740;
    TObjEneRe7Berura__detached_part_states[1].fC = 4;
    TObjEneRe7Berura__detached_part_states[1].f10 = lbl_805D9778;
    TObjEneRe7Berura__detached_part_states[1].f14 = lbl_805D977C;
    for (i = 0; i < 2; i++) {
        Elem_800959F8 *e = &TObjEneRe7Berura__detached_part_states[i];
        u8 *ent = RES->f430[TObjEneRe7Berura__animation_definitions[e->fC].f4].f4;
        TObjPlayer::set_global_flag();
        bind_motion_context((s32)ent, e->f14);
        ((void (*)(u32, void *))apply_attack_params__16TObjEneRe7BeruraFiPv)(m, e);
        TObjPlayer::clear_global_state();
        e->f18 = (s32 *)find_model_node(m, e->f4);
        e->f1C = (s32)find_model_node(m, e->f8);
        e->f20 = 7;
        e->f24 = e->f18[1];
        e->f28 = TObjEneRe7Berura__data_805D972C;
        e->f2C = TObjEneRe7Berura__data_805D972C;
        e->f30 = TObjEneRe7Berura__data_805D972C;
        e->f34 = 0;
        e->f38 = 0;
        e->f3C = 0;
        e->f40 = lbl_805D974C;
        e->f44 = lbl_805D974C;
        e->f48 = lbl_805D974C;
        e->f4C = e->f18[0x2C / 4];
        e->f50 = 0;
    }
    berura_node_matrix_ptr_a = ((s32 *)((NJS_OBJECT *)find_model_node(m, 2))->model)[1] + 8;
    berura_node_matrix_ptr_b = ((s32 *)((NJS_OBJECT *)find_model_node(m, 1))->model)[1] + 8;
    p = alloc__23TAdSinglePlyChrSelectGCFv(0x14);
    if (p != NULL) {
        p = ((TLobby *)p)->alloc_tables(*(s32 *)(RES->f42C + 8), 2);
    }
    belra_uv_animation_buffer = (u32)p;
    p = alloc__23TAdSinglePlyChrSelectGCFv(0x18);
    if (p != NULL) {
        p = init_trail_buffer__11TBoss4Type3FPvifff(p, 4, lbl_805D9780, lbl_805D9784, TObjEneRe7Berura__data_805D9738);
    }
    belra_trail_buffer = (u32)p;
    pair[0] = 0x2E;
    pair[1] = 0x2E;
    pair[2] = 0x45;
    pair[3] = 0x45;
    for (i = 0; i < 4; i++) {
        vecs[i].x = TObjEneRe7Berura__data_805D972C;
        vecs[i].y = TObjEneRe7Berura__data_805D972C;
        vecs[i].z = TObjEneRe7Berura__data_805D972C;
    }
    vecs[0].x = TObjEneRe7Berura__data_805D9730;
    vecs[2].x = TObjEneRe7Berura__data_805D9730;
    ((TBoss4Type3 *)p)->draw_motion_trail((s32)(*(s32 *)(RES->f42C + 8)), (s32)((RES->f430 + TObjEneRe7Berura__animation_definitions[2].f4)->f4), (s32)pair, (s32)vecs);
    for (i = 0; i < 1; i++) {
        TObjEneRe7Berura__stat_handle_table[i] = register_boss__6TLobbyFl(lbl_805D9718[i]);
    }
    for (s32 j = 0; j < 2; j++) {
        TObjEneRe7Berura__data_805007D4[j] = dispatch_shared_handler_b__6TLobbyFl(lbl_80439DA0[j]);
    }
    for (i = 0; i < 1; i++) {
        TObjEneRe7Berura__shared_object_handles[i] = register_object__6TLobbyFl(lbl_805D971C[i]);
    }
    for (i = 0; i < 1; i++) {
        TObjEneRe7Berura__handler_table_a[i] = dispatch_shared_handler_a__6TLobbyFl(lbl_805D9720[i]);
    }
    {
        Atk_800959F8 atk = ene_re7_berura_attack_def;
        atk.w[0] = (s32)RES->f430;
        TLobby::spawn_npc_enemy(0x15, *(s32 *)(RES->f42C + 8), *(s32 *)(RES->f42C + 0xC), (s32)&atk, lbl_805D9788, TObjEneRe7Berura__data_805D972C);
    }
}

void fn_80095DD0(u8 *arg0) {
    *(*(s32 **)((s8 *)arg0 + 0x18)) &= 0xFFFFFFF7;
    *(*(s32 **)((s8 *)arg0 + 0x1C)) &= 0xFFFFFFF7;
}

void fn_80095DF4(u8 *arg0) {
    *(*(s32 **)((s8 *)arg0 + 0x18)) |= 8;
    *(*(s32 **)((s8 *)arg0 + 0x1C)) |= 8;
}
}

#undef RES
