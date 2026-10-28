#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEneDellBiter.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
#include "pso/object/obj_band.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TUnk_804E6FA8.h"

#include "pso/player/TUnk_804928CC.h"
#include "pso/player/TUnk_80490470.h"
#include "pso/enemy/TObjEneDellBiter_Eff_Rush.h"
#include <stddef.h>

#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/boss/TBoss4Type3.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"

#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/enemy/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/item/TItemData.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjFish.h"

#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/item/TItem.h"

struct VBase_14_aa9368 { char pad[0x14]; };
struct VObj_14_aa9368 : VBase_14_aa9368 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
    virtual s32 m7();
};
struct VBase_18_1fdb47 { char pad[0x18]; };
struct VObj_18_1fdb47 : VBase_18_1fdb47 {
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
    virtual s32 m104();
};

struct Vec_80303574 { f32 x, y, z; };
struct Fade_80303574 { u8 b[0x1C]; };
struct Obj_80303574 { u8 pad[0x3F0]; Fade_80303574 arr[2]; };
struct VBase_14_80304B88 { char pad[0x14]; };

struct VObj_14_80304B88 : VBase_14_80304B88 {
    virtual void m0();
    virtual void m1();
    virtual s32 m2();
    virtual void m3();
    virtual s32 m4();
};

struct VB_803062D4 { u8 pad0[0x18]; };
struct VD_803062D4 : VB_803062D4 {
    virtual ~VD_803062D4();
};

struct VBase_14_0d3ae4 { char pad[0x14]; };

struct VObj_14_0d3ae4 : VBase_14_0d3ae4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual s32 m3();
    virtual void m4();
    virtual s32 m5();
};

struct VBase_18_eeb1dd { char pad[0x18]; };

struct VObj_18_eeb1dd : VBase_18_eeb1dd {
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
};

extern "C" {
f64 atan2_float(f32, f32);
s32 spawn_particle_effect(void *, int);
s32 transition_enemy_state__9TObjEneDDFs(void *, int);
s32 copy_target_state__14TObjEnePanarmsFPv(void *, void *);
s32 approach_angle_limited(int, int, int);
s32 advance_animation_playback(void *);
s32 play_sound_effect(int, void *, int, int);
void * __nw__7TObjectFUl(int);
s32 fn_80302FD8(void *, void *, void *, void *, int, int, f32);
void noop__16TObjEneDellBiterFv(void);
extern const f64 TObjEneDellBiter__data_80475328;
extern u8 *TObjEneDellBiter__movement_params;
extern const f32 lbl_805DEFCC;
extern const f32 lbl_805DEFD0;
extern const f32 lbl_805DEFD4;
extern const f32 TObjEneDellBiter__data_805DEFD8;
void TObjEneDellBiter__sub_80303BC0(u8 *arg0, s32 arg1);
s32 turn_toward_angle_limited__15TObjBoss2TunnelFlllll(int, int, int, int, int);
void clear_active_flag__16TObjEneDellBiterFPv(void *arg0);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
extern const f32 lbl_805DF004;
extern const f32 lbl_805DF008;
void TObjEneDellBiter__sub_8030492C(u8 *arg0, s32 arg1);
s32 update_linked_position__12TObjEneDD_STFf(f32);
extern const f32 TObjEneDellBiter__data_805DF00C;
void TObjEneDellBiter__sub_80304B88(u8 *arg0, s32 arg1);
void TObjEneDellBiter__sub_803058DC(s32 arg0);
void TObjEneDellBiter__sub_8030591C(s32 arg0);
s32 TObjEneDellBiter__sub_80305C40(u8 *arg0);
extern const f32 lbl_805DF000;
extern const f32 lbl_805DF010;
void TObjEneDellBiter__sub_80304D10(u8 *arg0, s32 arg1);
s32 fill_value_array(int);
s32 enemy_validate_retained_target();
u32 enemy_probe_wall_ahead__13TBoss5GryphonFfff(void *, f32, f32, f32);
s32 TObjEneDellBiter__sub_803054A8(u8 *arg0);
s32 TObjEneDellBiter__sub_803054FC(u8 *arg0);
f32 subtract_vector(void *, void *);
extern const f32 TObjEneDellBiter__data_805DEFE8;
extern const f32 TObjEneDellBiter__data_805DEFF4;
extern const f32 lbl_805DEFF8;
extern const f32 lbl_805DEFFC;
void TObjEneDellBiter__sub_803044AC(u8 *arg0, s32 arg1);
struct Stack_80303204 {
    s32 sp8;
    f32 spC;
    u8 trailing_storage[0x4];
};

struct RecoveredGlobal_80303204_lbl_804E6B54 { s32 value; u8 remaining[0x18]; };

typedef char RecoveredGlobal_80303204_lbl_804E6B54_size[sizeof(RecoveredGlobal_80303204_lbl_804E6B54) == 0x1C ? 1 : -1];

struct Stack_803040D0 {
    s32 sp8;
    f32 spC;
};

struct VBase_14_c1c33b { char pad[0x14]; };

struct VObj_14_c1c33b : VBase_14_c1c33b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};

struct RecoveredFields_8030390C_arg0 {
    u8 unknown_0[0xB8];
    s16 field_B8;
    u8 unknown_BA[0x306];
    s32 field_3C0;
    u8 unknown_3C4[0x108];
    s32 field_4CC;
};

struct RecoveredGlobal_80303894_lbl_80541E48 {
    s32 value;
    u8 remaining[0xC];
};

struct Vec_80303AA0 { f32 x; f32 y; f32 z; };

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Vec_8030338C { s32 x; s32 y; s32 z; };

typedef char RecoveredFields_8030390C_arg0_B8_offset[offsetof(RecoveredFields_8030390C_arg0, field_B8) == 0xB8 ? 1 : -1];

typedef char RecoveredFields_8030390C_arg0_3C0_offset[offsetof(RecoveredFields_8030390C_arg0, field_3C0) == 0x3C0 ? 1 : -1];

typedef char RecoveredFields_8030390C_arg0_4CC_offset[offsetof(RecoveredFields_8030390C_arg0, field_4CC) == 0x4CC ? 1 : -1];

typedef char RecoveredGlobal_80303894_lbl_80541E48_size[sizeof(RecoveredGlobal_80303894_lbl_80541E48) == 0x10 ? 1 : -1];

struct WBase_80305034 { char pad[0x14]; };

struct WObj_80305034 : WBase_80305034 {
    virtual s32 w0();virtual s32 w1();virtual s32 w2();virtual s32 w3();virtual s32 w4();virtual s32 w5();
};

struct Base_8030561C_8030535C { char pad[0x18]; };

struct VObj_8030561C_8030535C : Base_8030561C_8030535C {
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
};

struct Stack_80305B60 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct Obj_80098FF4 {
    u8 pad0[0x38];
    u8 pos[0x2FC - 0x38];
    u8 field2FC[4];
};

struct Vec_803059BC { f32 x, y, z; };

struct Hit_803059BC { u32 flags; u8 *obj; };

struct Base_80306994_80305BDC { char pad[0x18]; };

struct VObj_80306994_80305BDC : Base_80306994_80305BDC {
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
};

struct Stack_80305FDC {
    s32 sp8;
    f32 spC;
};

struct RecoveredGlobal_8031B170_lbl_804E8880
{
  s32 value;
  u8 remaining[0xCC];
};

struct VBase_18_cf2ce9 { char pad[0x18]; };

struct VObj_18_cf2ce9 : VBase_18_cf2ce9 {
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
    virtual void m15(void *, s32);
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
};

struct S_80305E1C { f32 f; s32 flags; };

struct Obj_80305E1C { u8 pad[0x46C]; u8 pos[0x28]; VObj_18_cf2ce9 *a; VObj_18_cf2ce9 *b; u8 pad2[4]; s32 v; };

struct VBase_18_257559 { char pad[0x18]; };

typedef struct Atk_80305C40 { s32 type; f32 val; } Atk_80305C40;

struct Obj_80305C40 : VBase_18_257559 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(void *, Atk_80305C40, s32, s32, s32);
};

typedef struct RecoveredGlobal_8031B170_lbl_804E8880 RecoveredGlobal_8031B170_lbl_804E8880;

typedef char RecoveredGlobal_8031B170_lbl_804E8880_size[((sizeof(RecoveredGlobal_8031B170_lbl_804E8880)) == 0xD0) ? (1) : (-1)];

struct Vec_80303F04 { f32 x; f32 y; f32 z; };

f32 calc_boss4_scale__10TObjPlayerFi(s32);
s32 obj_isState2_324__13TUnk_804806E8Fv(void *);
s16 get_attack_params_atp_min(void *p);
s32 obj_is_hit_receivable(void);
Obj_80098FF4 * get_player_data__10TObjPlayerFi(s32);
s32 obj_testFlags30__13TUnk_804AF8A0FUl(void *, s32);
s32 obj_getField1c(void *);
void obj_setFlags30(void *, s32);
void queue_destruction__7TObjectFv(void *arg0);
void TLobby__sub_8001FE7C(void*, int);
Obj_80305C40 * get_battle_param__10TObjPlayerFi(s32);
void attach_particle_model(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
s32 get_mode__11TCameraCtrlFPv(void *);
u32 csnLookAt(void *, void *);
s32 *csnVectorUnder(s32 arg0, u32 *arg1, s32 arg2);
s32 rotate_xz_pair_by_angle(void *, void *, int);
s32 is_vec_xz_cross_negative(void *, void *);
void *create_particle_emitter(void *pos, s32 id);
s32 TObjPlayer__sub_800A04F0(void *);
s32 spawn_part__14TObjEneEpsilonFi(void *, f32);
void enemy_clear_target__12TObjEneDD_STFUs(void *);
void enemy_set_target_id(void *, u16);
s32 update_player_state__9TObjEneDDFv(void *, void *, int);
s32 get_camera_ctrl__9TObjEneDDFv(void *, int);
s32 is_alive__9TObjEneDDFv(void *);
s32 is_player_entity_id();
s32 pack_debug_text_position(s32, s32);
void invoke_initialization_hook__9TObjEneDDFv(void *, void *);
s32 attack_target_history_add(s32, void *);
void fn_800D8830(void *owner, void *pos);
s32 TObjEneGibbles__sub_800D8988(s32);
void TItemObject__ct(void *);
void *__dt__11TItemObjectFv(void *arg0, s16 arg1);
f32 horizontal_distance_squared(void *, void *);
void *get_player_by_client_id(s32 i);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
s32 __ct__7TObjectFP7TObject(void *, void *);
void TObjPlayer__sub_8023DEE0(s16 *p, s16 a, s16 b, u16 id);
}
void restore_render_scissor(s32 arg0);
extern "C" {
void * __dt__25TObjEneDellBiter_Eff_RushFv(void *arg0, s16 arg1);
u8 * TObjEneDellBiter_Eff_Rush__ct(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, f32 farg0);
void vfunc_106__16TObjEneDellBiterFv(u8 *arg0);
void vfunc_83__16TObjEneDellBiterFv(void* p);
void state_death__16TObjEneDellBiterFPvi(u8 *arg0, s32 arg1);
void TObjEneDellBiter__sub_80303AA0(u8 *arg0, s32 arg1);
void TObjEneDellBiter__sub_80303F04(u8 *arg0, s32 arg1);
void TObjEneDellBiter__sub_803040D0(u8 *arg0, s32 arg1);
void handle_attack_event__16TObjEneDellBiterFPvi(u8 *arg0, s32 arg1);
void run_task__16TObjEneDellBiterFPvi(u8 *arg0, s32 arg1);
void handle_movement_event__16TObjEneDellBiterFPvi(u8 *arg0, s32 arg1);
void TObjEneDellBiter__vt85(s32 arg0, u32 arg1, s32 arg2);
void sub_803055C8__16TObjEneDellBiterFv(u8 *arg0);
void TObjEneDellBiter__vt102(void *arg0, f32 farg0);
s32 TObjEneDellBiter__sub_80305688(void *);
s32 TObjEneDellBiter__sub_80305788(Obj_80098FF4 *self);
s32 TObjEneDellBiter__sub_803059BC(void *arg0, void *arg1);
void TObjEneDellBiter__sub_80305E1C(u8 *arg0);
void vfunc_88__16TObjEneDellBiterFv(void);
void vfunc_61__16TObjEneDellBiterFv(void);
void vfunc_62__16TObjEneDellBiterFv(u8 *arg0);
void vfunc_63__16TObjEneDellBiterFv(void* p);
void vfunc_28__16TObjEneDellBiterFv(void);
void run_task__16TObjEneDellBiterFv(u8 *arg0);
void * TObjEneDellBiter__ct(void *arg0, void *arg1, void *arg2);
void * TObjEneDellBiter__create(void *arg0);
void * __dt__13TUnk_804E6FA8Fv(void *arg0, s16 arg1);
void * TItemObject__sub_80306A28(void *arg0);
void __construct_array(void *, void *, void *, int, int);
s32 debug_printf_at(s32, const char *, ...);
s32 vec3_add_to(void *, void *);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_chunk_object(void *child);

extern s32 TObjEneDellBiter__shared_handler_param;
extern u32 TObjEneDellBiter__shared_model_resource;
extern s32 TObjEneDellBiter__demo_script_step;
extern s32 TObjEneDellBiter__demo_rotate_x_angle;
extern s32 TObjEneDellBiter__demo_script_cursor;
extern const f32 TObjEneDellBiter__data_805DEFB8;
extern const f32 TObjEneDellBiter__data_805DEFC0;
extern const f32 TObjEneDellBiter__data_805DEFE0;
extern const f32 TObjEneDellBiter__data_805DEFE4;
void *__dt__13TUnk_80490470Fv(void *arg0, s16 arg1);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 delete_buffer__12TBoss8DragonFis(s32 arg0, s16 arg1);
void free_collision_body_parts(void *);
void __destroy_arr(void *, void *, s32, s32);
u8 *__dt__16TObjEneDellBiterFv(u8 *arg0, s16 arg1);
extern s32 __dt__13TUnk_804949A8Fv[];
extern s32 init_and_activate__10TObjPlayerFv[];
extern S_80305E1C lbl_8047528C[];
extern s32 lbl_804752A0[];
extern char lbl_804752AC[];
extern char lbl_804752BC[];
extern char lbl_804752D0[];
extern char lbl_804752E4[];
extern char lbl_804752F8[];
extern char lbl_8047530C[];
extern char lbl_80475318[];
extern s32 __vt__25TObjEneDellBiter_Eff_Rush[];
extern s32 lbl_804E6FA8[];
extern RecoveredGlobal_80303894_lbl_80541E48 dellbiter_demo_camera_vec;
extern s32 TObjEneDellBiter_Eff_Rush__name;
extern void *TObjEneDellBiter__class_name;
extern s32 actor_frame_tick;
extern s32 game_difficulty_selection;
extern s32 TObjEneDellBiter__scrolling_uv_polygon_list;
extern s32 TObjEneDellBiter__last_uv_scroll_tick;
extern const f32 lbl_805DEFAC;
extern const f32 lbl_805DEFB0;
extern const f32 lbl_805DEFB4;
extern const f32 lbl_805DEFBC;
extern const f32 lbl_805DEFC8;
extern const f32 lbl_805DEFDC;
extern const f32 lbl_805DEFEC;
extern const f32 lbl_805DEFF0;
extern const f32 lbl_805DF014;
extern const f32 lbl_805DF018;
extern const f32 lbl_805DF01C;
extern const f32 lbl_805DF020;
extern const f32 lbl_805DF024;
extern const f32 lbl_805DF028;
extern const f32 lbl_805DF02C;
extern const f32 lbl_805DF030;
extern const f32 lbl_805DF034;
extern const f32 lbl_805DF03C;
extern void *tl_04;

struct VB14_80306468 { u8 pad[0x14]; };
struct V3D4_80306468 : VB14_80306468 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
};

struct VB18_80306468 { u8 pad[0x18]; };
struct Self_80306468 : VB18_80306468 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
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
    virtual void m84();
    virtual void m85(s16, s32);
};

struct Part_80306468 { u8 pad[0x2C]; };

struct Vec_80306468 { f32 x, y, z; };
struct Sub3F0_80306468 { u8 pad[0x1C]; };

struct Cfg_80306468 { u8 pad[8]; s32 f8; s32 fC; };
struct Glob_80306468 { u8 pad[0x42C]; Cfg_80306468 *cfg; s32 f430; };

struct Obj_80306468 {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    s32 f34;
    Vec_80306468 pos;
    u8 pad44[0xA4 - 0x44];
    u8 *fA4;
    u8 padA8[0xB8 - 0xA8];
    s16 fB8;
    u8 padBA[0x326 - 0xBA];
    s16 f326;
    u8 pad328[0x350 - 0x328];
    void *f350;
    u8 pad354[0x37C - 0x354];
    f32 f37C;
    u8 pad380[0x3C0 - 0x380];
    s32 f3C0;
    s32 f3C4;
    Vec_80306468 v3C8;
    u8 sub3D4[0x1C];
    Sub3F0_80306468 arr3F0[4];
    Vec_80306468 v460[3];
    s32 f484;
    s32 f488;
    s32 f48C;
    s32 f490;
    void *f494;
    void *f498;
    void *f49C;
    void *f4A0;
    s32 f4A4;
    u8 pad4A8[0x4C0 - 0x4A8];
    s32 f4C0;
    s32 f4C4;
    s32 f4C8;
    s32 f4CC;
    s32 f4D0;
    s32 f4D4;
    s32 f4D8;
    f32 f4DC;
    f32 f4E0;
};
extern "C" {
s32 is_split_screen();
s32 reset_hp__9TObjEneDDFv(void *, int, int, int);
s32 initialize_enemy_state__9TObjEneDDFv(void *, int);
s32 init_model__9TObjEneDDFv(void *, void *, int);
u8 *TBoss8Dragon__sub_800BC5EC(u8 *arg0, s32 arg1);
s32 create__12TObjEneSaverFPvPv(s32, s32);
s32 init_collision_body_parts(void *, void *, int);
void *__ct__13TUnk_804AF8A0FP7TObject(void *, s32);
void *__nw__7TObjectFUl(int);
s32 get_camera_mode__11TCameraCtrlFv();
s32 is_main_phase_15__9TObjEneDDFv();
s32 update_obstruction_fade(void *);
s32 defer_render__7TObjectFv(void *);
extern Vec_80303574 lbl_80475294[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
}

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
extern "C" void vfunc_83__12TObjEneDD_STFv();
extern "C" void vfunc_29__13TUnk_804806E8Fv();
extern "C" void vfunc_73__13TUnk_804806E8Fv();
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
extern "C" void vfunc_13__13TUnk_804AF8A0Fl();
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
extern "C" void vfunc_12__9TObjEnemyFv();
extern "C" void get_pos__13TUnk_804806E8Fl();
extern "C" void is_actor_cadence_frame__13TUnk_804806E8Fl();
extern "C" void is_target_in_attack_range__13TUnk_804806E8Fv();
extern "C" u8 lbl_80475138[];
extern "C" u8 lbl_80475148[];
extern "C" u8 lbl_80475160[];
extern "C" u8 lbl_80475174[];
extern "C" u8 lbl_8047518C[];
extern "C" u8 lbl_804751A0[];
extern "C" u8 lbl_804751B8[];
extern "C" u8 lbl_804751CC[];
extern "C" u8 lbl_804751E0[];
extern "C" u8 lbl_804751F8[];
extern "C" u8 lbl_8047520C[];
extern "C" u8 lbl_80475220[];
extern "C" u8 lbl_80475238[];
extern "C" u8 lbl_8047524C[];
extern "C" void receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__13TUnk_804806E8FPvf();
extern "C" void receive_weapon_special_attack__13TUnk_804806E8FPvPv();
extern "C" void apply_defense_stat_status__13TUnk_804806E8FPv();
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
extern void *lbl_804E6C3C[2];
extern void *TObjEneDellBiter__resource_descriptor[11];
extern void *lbl_804E6C80[2];
extern void *lbl_804E6C88[11];
void render__16TObjEneDellBiterFv(u8 *arg0);
struct V3_80306858 { f32 x; f32 y; f32 z; };
struct S16_80306858 { s32 a; s32 b; s32 c; s32 d; };
struct L4_80306858 { u8 pad[4]; s32 v; };
struct L3_80306858 { u8 pad[4]; L4_80306858 *p; };
struct L2_80306858 { u8 pad[0x2C]; L3_80306858 *p; };
struct L1_80306858 { u8 pad[8]; L2_80306858 *p; s32 c; };
struct Obj_80306858 { u8 pad[0x42C]; L1_80306858 *p; s32 v; };
struct Ent_80306858 { u8 pad[0xC]; f32 f; };
struct G_80306858 { u8 pad[0x1C]; Ent_80306858 e; u8 pad2[0x100 - 0x2C]; u8 a[0x44]; u8 b[4]; };

extern "C" {
u8 *dispatch_shared_handler_a__6TLobbyFl(s32);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
void *load_enemy_bml_resource(void *);
extern S16_80306858 ene_dell_biter_attack_def;
}
void *TObjEneDellBiter__param_table[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804E6B8C[44] = {
    (void *)0x0, (void *)0x41400000, (void *)0x0, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41700000, (void *)0x0,
    (void *)0x0, (void *)0x9d03, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x41700000, (void *)0x0, (void *)0x0,
    (void *)0x9d03, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41400000, (void *)0x0,
    (void *)0x41700000, (void *)0x0, (void *)0x0, (void *)0x8003,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
};
__declspec(section ".data") void *lbl_804E6C3C[2] = {
    (void *)&lbl_80475138, (void *)0x0,
};
void *TObjEneDellBiter__resource_descriptor[11] = {
    (void *)&lbl_80475148, (void *)&lbl_80475160, (void *)&lbl_80475174, (void *)&lbl_8047518C,
    (void *)&lbl_804751A0, (void *)&lbl_804751B8, (void *)&lbl_804751CC, (void *)&lbl_804751E0,
    (void *)&lbl_804751F8, (void *)&lbl_8047520C, (void *)0x0,
};
void *lbl_804E6C70[4] = {
    (void *)&lbl_80475220, (void *)&lbl_804E6C3C, (void *)&TObjEneDellBiter__resource_descriptor, (void *)0x1000a,
};
__declspec(section ".data") void *lbl_804E6C80[2] = {
    (void *)&lbl_80475238, (void *)0x0,
};
void *lbl_804E6C88[11] = {
    (void *)&lbl_80475148, (void *)&lbl_80475160, (void *)&lbl_80475174, (void *)&lbl_8047518C,
    (void *)&lbl_804751A0, (void *)&lbl_804751B8, (void *)&lbl_804751CC, (void *)&lbl_804751E0,
    (void *)&lbl_804751F8, (void *)&lbl_8047520C, (void *)0x0,
};
void *lbl_804E6CB4[4] = {
    (void *)&lbl_8047524C, (void *)&lbl_804E6C80, (void *)&lbl_804E6C88, (void *)0x1000a,
};
void *dell_biter_param_table[40] = {
    (void *)0x10000, (void *)0x8, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0x9, (void *)0x3f333333, (void *)0x0,
    (void *)0x10000, (void *)0x5, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x6, (void *)0x3f666666, (void *)0x0,
    (void *)0x30000, (void *)0x0, (void *)0x3f19999a, (void *)0x0,
    (void *)0x30000, (void *)0x1, (void *)0x3f19999a, (void *)0x0,
    (void *)0x30000, (void *)0x2, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0x4, (void *)0x3f333333, (void *)0x0,
    (void *)0x30000, (void *)0x7, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0x3, (void *)0x3f333333, (void *)0x0,
};
void *__vt__16TObjEneDellBiter[107] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__16TObjEneDellBiterFv, (void *)&run_task__16TObjEneDellBiterFv,
    (void *)&render__16TObjEneDellBiterFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&vfunc_9__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&vfunc_12__9TObjEnemyFv, (void *)&vfunc_13__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&vfunc_28__16TObjEneDellBiterFv, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__13TUnk_804806E8Fv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_804806E8Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TUnk_804806E8Fv, (void *)&apply_paralysis__13TUnk_804806E8Fv, (void *)&apply_slow_status__13TUnk_804806E8Fv, (void *)&apply_confusion_status__13TUnk_804806E8Fv,
    (void *)&apply_movement_ailment__13TUnk_804806E8Fl, (void *)&apply_shock_status__13TUnk_804806E8Fv, (void *)&clear_harmful_statuses__13TUnk_804806E8Fv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__13TUnk_804806E8Fv, (void *)&vfunc_59__13TUnk_804806E8Fv,
    (void *)&vfunc_60__13TUnk_804806E8Fv, (void *)&vfunc_61__16TObjEneDellBiterFv, (void *)&vfunc_62__16TObjEneDellBiterFv, (void *)&vfunc_63__16TObjEneDellBiterFv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&vfunc_73__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__9TObjEneDDFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&TObjEneDD__vt82, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&TObjEneDellBiter__vt85,
    (void *)&vfunc_88__16TObjEneDellBiterFv, (void *)&vfunc_89__9TObjEneDDFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&TObjEneDellBiter__vt102, (void *)&vfunc_83__16TObjEneDellBiterFv, (void *)&vfunc_106__16TObjEneDellBiterFv,
};
#define dell_biter_param_table (*(RecoveredGlobal_8031B170_lbl_804E8880 *)dell_biter_param_table)
#define __vt__16TObjEneDellBiter ((s32 *)__vt__16TObjEneDellBiter)

void TObjEneDellBiter_Eff_Rush::render() {  }

void TObjEneDellBiter_Eff_Rush::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    obj_getField1c((void *) (*(u8 **)((s8 *)arg0 + 0x1C)));
    if (is_player_entity_id() != 0) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    if (is_alive__9TObjEneDDFv((void *) (*(u8 **)((s8 *)arg0 + 0x1C))) == 0) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    if (obj_isState2_324__13TUnk_804806E8Fv((void *) (*(u8 **)((s8 *)arg0 + 0x1C))) != 0) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x2C);
    if (temp_f1 <= lbl_805DEFB0) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x308) = (f32) (*(f32 *)((s8 *)arg0 + 0x20) * temp_f1);
    *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x1C)) + 0x310) = (f32) (*(f32 *)((s8 *)arg0 + 0x28) * *(f32 *)((s8 *)arg0 + 0x2C));
    *(f32 *)((s8 *)arg0 + 0x2C) = (f32) (*(f32 *)((s8 *)arg0 + 0x2C) * lbl_805DEFB4);
}

void *__dt__25TObjEneDellBiter_Eff_RushFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__25TObjEneDellBiter_Eff_Rush;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TObjEneDellBiter_Eff_Rush__ct(u8 *object, s32 arg1, u8 *arg2, s32 arg3, f32 farg0) {
    typedef char sp8_offset[(offsetof(Stack_80303204, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80303204, spC) == 0x4) ? 1 : -1];
    Stack_80303204 stack;
    __ct__7TObjectFP7TObject((void *)object, (void *)arg1);
    *(s32 **)((s8 *)object + 0x18) = &(*(RecoveredGlobal_80303204_lbl_804E6B54 *)&__vt__25TObjEneDellBiter_Eff_Rush).value;
    *(s32 *)((s8 *)object + 0) = (s32) TObjEneDellBiter_Eff_Rush__name;
    *(s32 *)((s8 *)object + 0x1C) = arg3;
    *(f32 *)((s8 *)object + 0x2C) = farg0;
    *(s32 *)((s8 *)object + 0x30) = 0;
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg3 + 0x38));
    subtract_vector(&stack.sp8, arg2 + 0x38);
    stack.spC = lbl_805DEFAC;
    *(f32 *)((s8 *)object + 0x20) = sin_table_lookup((int) (*(s32 *)((s8 *)arg2 + 0x60)));
    *(f32 *)((s8 *)object + 0x24) = (f32) lbl_805DEFAC;
    *(f32 *)((s8 *)object + 0x28) = cos_table_lookup((int) (*(s32 *)((s8 *)arg2 + 0x60)));
    if (is_vec_xz_cross_negative(object + 0x20, &stack.sp8) != 0) {
        rotate_xz_pair_by_angle(object + 0x20, object + 0x28, -0x1800);
    } else {
        rotate_xz_pair_by_angle(object + 0x20, object + 0x28, 0x1800);
    }
    return object;
}

s32 TObjEneDellBiter::render_model_if_visible() {
    if (get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x20) {
        if (((TObjEneRecon *)(((u8 *)this) + 0x3C8))->push_reflect_matrix() != 0) {
            TObjFish::set_global_param((int) (*(s32 *)((s8 *)((u8 *)this) + 0x24)));
            push_matrix();
            post_translate_matrix((void *) (((u8 *)this) + 0x38));
            rotate_matrix_y(0, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x60)));
            scale_matrix(0, TObjEneDellBiter__data_805DEFB8, TObjEneDellBiter__data_805DEFB8, TObjEneDellBiter__data_805DEFB8);
            this->draw();
            pop_matrix();
            restore_render_scissor(1);
        }
        return 1;
    }
    return 0;
}

void TObjEneDellBiter::vfunc_106() {
    u8 *arg0 = (u8 *)this;
    if (((TObjEneDD *)arg0)->get_target_info() != 0) {
        debug_printf_at(pack_debug_text_position(0, 2), lbl_804752AC);
        debug_printf_at(pack_debug_text_position(0, 3), lbl_804752BC);
        debug_printf_at(pack_debug_text_position(0, 4), lbl_804752D0);
        debug_printf_at(pack_debug_text_position(0, 5), lbl_804752E4);
        debug_printf_at(pack_debug_text_position(0, 6), lbl_804752F8);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x4BC) == 1) {
            debug_printf_at(pack_debug_text_position(0, 9), lbl_8047530C);
        } else {
            debug_printf_at(pack_debug_text_position(0, 9), lbl_80475318);
        }
    }
    if (((VObj_18_26a62c *)(arg0))->m8(lbl_805DEFBC, TObjEneDellBiter__data_805DEFC0) != 0) {
        Vec_8030338C v = *(Vec_8030338C *)lbl_804752A0;
        update_player_state__9TObjEneDDFv(arg0, &v, 0);
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param((int) (*(s32 *)((s8 *)arg0 + 0x24)));
        push_matrix();
        post_translate_matrix(arg0 + 0x38);
        rotate_matrix_y(0, (int) (*(s32 *)((s8 *)arg0 + 0x60)));
        scale_matrix(0, TObjEneDellBiter__data_805DEFB8, TObjEneDellBiter__data_805DEFB8, TObjEneDellBiter__data_805DEFB8);
        TObjPlayer::set_global_flag();
        draw_chunk_object((void *)(*(s32 *)((s8 *)arg0 + 0x34)));
        TObjPlayer::clear_global_state();
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

s32 TObjEneDellBiter::vfunc_83() { if (get_target_info() != 0) { this->init_target_offsets(); } }

#define F(t, o) (*(t *)(arg0 + (o)))
#define VO ((VObj_18_1fdb47 *)(arg0))

void render__16TObjEneDellBiterFv(u8 *arg0) {
    s32 cam;
    s32 vis;
    u8 *fade;
    s32 draw;
    s32 i;

    if (TObjPlayer::check_demo_mode() != 0) {
        VO->m104();
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = get_camera_mode__11TCameraCtrlFv();
    }
    if (F(s32, 0x3C0) & 1) {
        vis = 0;
    } else if (is_main_phase_15__9TObjEneDDFv() != 0) {
        if (TOKeyMachine01::get_global_state() == 0x23) {
            vis = VO->m9(600.0f, 600.0f, 15.0f);
        } else {
            vis = VO->m9(lbl_805D9E88, lbl_805D9E84, TObjEneDellBiter__data_805DEFC0);
        }
    } else if (VO->m8(lbl_805DEFBC, TObjEneDellBiter__data_805DEFC0) != 0) {
        vis = 1;
    } else {
        vis = 0;
    }
    if (vis != 0) {
        if (((TObjEneDellBiter *)arg0)->render_model_if_visible() != 0) {
            return;
        }
        if (!(F(s32, 0x3C4) & 0x4000)) {
            Vec_80303574 v = lbl_80475294[0];
            update_player_state__9TObjEneDDFv(arg0, &v, 0);
        }
        ((TObjEneDD *)arg0)->update_secondary_light();
        TObjEneDellBiter__demo_script_step = 0;
        TObjEneDellBiter__demo_rotate_x_angle = F(s32, 0x484);
        TObjEneDellBiter__demo_script_cursor = (s32)(arg0 + 0x460);
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        draw = 1;
        fade = ((Obj_80303574 *)arg0)->arr[cam].b;
        update_obstruction_fade(fade);
        cam = ((RenderFadeState *)fade)->updateFromCamera((const f32*)(arg0 + 0x2FC));
        if (F(s32, 0x3C0) & 2) {
            ((VObj_14_aa9368 *)(arg0 + 0x3D4))->m6();
            if (defer_render__7TObjectFv(arg0) != 0) {
                draw = 0;
            }
        } else if (cam != 0) {
            ((VObj_14_aa9368 *)fade)->m6();
            if (defer_render__7TObjectFv(arg0) != 0) {
                draw = 0;
            }
        }
        TObjFish::set_global_param(F(s32, 0x24));
        if (draw != 0) {
            push_matrix();
            post_translate_matrix(arg0 + 0x38);
            rotate_matrix_y(0, F(s32, 0x60));
            scale_matrix(0, TObjEneDellBiter__data_805DEFB8, TObjEneDellBiter__data_805DEFB8, TObjEneDellBiter__data_805DEFB8);
            TObjEneRe7Berura::set_global_state((s32)((void *)TObjEneDellBiter::step_demo_script));
            if (vis == 1) {
                ((TObjMotion *)arg0)->draw();
            } else {
                ((TObjEnemy *)arg0)->render_world_model();
            }
            TObjEneRe7Berura::set_global_state((s32)NULL);
            pop_matrix();
        }
        if (F(s32, 0x3C0) & 2) {
            ((VObj_14_aa9368 *)(arg0 + 0x3D4))->m7();
        } else if (cam != 0) {
            ((VObj_14_aa9368 *)fade)->m7();
        }
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        ((TObjEneDD *)arg0)->update_primary_light();
    } else if (is_split_screen() == 0) {
        for (i = 0; i < 3; i++) {
            VecCopy((Vec *)(arg0 + i * 0xC + 0x460), (const Vec *)(arg0 + 0x2FC));
        }
    }
}
#undef F
#undef VO

void TObjEneDellBiter::step_demo_script() {
    s32 pos;
    switch (TObjEneDellBiter__demo_script_step) {
    case 9:
    case 10:
    case 11:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
        break;
    case 8:
        rotate_matrix_x(0, TObjEneDellBiter__demo_rotate_x_angle);
        break;
    case 12:
    case 22:
    case 32:
        pos = TObjEneDellBiter__demo_script_cursor;
        TObjEneDellBiter__demo_script_cursor = pos + 0xC;
        get_camera_ctrl__9TObjEneDDFv(&dellbiter_demo_camera_vec.value, pos);
        break;
    }
    TObjEneDellBiter__demo_script_step += 1;
}

void state_death__16TObjEneDellBiterFPvi(u8 *arg0, s32 arg1) {
    switch (arg1) {
    case 4:
        ((RecoveredFields_8030390C_arg0 *)arg0)->field_B8 = 9;
        ((RecoveredFields_8030390C_arg0 *)arg0)->field_3C0 = (s32) (((RecoveredFields_8030390C_arg0 *)arg0)->field_3C0 & 0xFFFFFFFC);
        ((RecoveredFields_8030390C_arg0 *)arg0)->field_3C0 = (s32) (((RecoveredFields_8030390C_arg0 *)arg0)->field_3C0 | 2);
        ((TObjEneDellBiter *)(arg0))->vfunc_94();
        ((TBoss8Dragon *)arg0)->refresh_and_send_entity_flags();
        TObjPlayer__sub_800A04F0(arg0 + 0x3D4);
        if (TOKeyMachine01::get_global_state() == 0x23) {
            play_sound_effect(0x4003A358, arg0 + 0x38, 0, 0);
        } else {
            play_sound_effect((int)(copy_target_state__14TObjEnePanarmsFPv(arg0, (void *)(0x4003A31A))), arg0 + 0x38, 0, 0);
        }
        ((RecoveredFields_8030390C_arg0 *)arg0)->field_4CC = 0;
        return;
    case 3:
        if ((s32) ((RecoveredFields_8030390C_arg0 *)arg0)->field_4CC == 2) {
            queue_destruction__7TObjectFv((arg0));
        }
        return;
    case 0:
        advance_animation_playback(arg0);
        switch (((RecoveredFields_8030390C_arg0 *)arg0)->field_4CC) {
        case 0:
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                ((TObjPlayer *)(arg0 + 0x2FC))->request_two_effects();
                play_sound_effect(0x4003A830, arg0 + 0x2FC, 0, 0);
                ((RecoveredFields_8030390C_arg0 *)arg0)->field_4CC = 1;
                return;
            }
            break;
        case 1:
            if (((VObj_14_c1c33b *)(arg0 + (980)))->m4() != 0) {
                TObjPlayer::apply_effect_variant_b((s32)(arg0 + 0x38), 0);
                ((RecoveredFields_8030390C_arg0 *)arg0)->field_4CC = 2;
                return;
            }
            break;
        default:
            ((RecoveredFields_8030390C_arg0 *)arg0)->field_4CC = 2;
            return;
        }
        break;
    case 5:
        queue_destruction__7TObjectFv((arg0));
        break;
    }
}

void TObjEneDellBiter__sub_80303AA0(u8 *ene_dell_biter, s32 arg1) {
    Vec_80303AA0 v;
    f32 len;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_dell_biter + 0xB8) = 6;
        advance_animation_playback(ene_dell_biter);
        ((TObjEneDD_ST *)ene_dell_biter)->set_active();
        break;
    case 3:
        if (((TObjEneDD *)ene_dell_biter)->get_flag_b4() != 0 && ((TObjEneDellBiter *)ene_dell_biter)->check_low_hp_transition() == 0 &&
            ((s32 (*)(void *))TObjEneDellBiter__sub_803054A8)(ene_dell_biter) == 0 && ((s32 (*)(void *))TObjEneDellBiter__sub_803054FC)(ene_dell_biter) == 0) {
            transition_enemy_state__9TObjEneDDFs(ene_dell_biter, *(s32 *)((s8 *)ene_dell_biter + 0x378));
        }
        break;
    case 0:
        advance_animation_playback(ene_dell_biter);
        VecCopy((Vec *)&v, (const Vec *)(ene_dell_biter + 0x308));
        len = ((TObjBoss2Tunnel *)(&v))->clamp_velocity();
        ((TObjEneDD *)ene_dell_biter)->move_clamped_on_ground(v.x, v.z, len);
        *(f32 *)((s8 *)ene_dell_biter + 0x308) *= lbl_805DEFC8;
        *(f32 *)((s8 *)ene_dell_biter + 0x310) *= lbl_805DEFC8;
        ((TObjEneDD *)(ene_dell_biter))->vfunc_89();
        break;
    case 5:
        ((TObjEneDD *)ene_dell_biter)->clear_attack_receipts();
        ((TObjEneDD *)ene_dell_biter)->clear_field_388();
        break;
    }
}

struct Obj_80098FF4;
void TObjEneDellBiter__sub_80303BC0(u8 *arg0, s32 arg1) {
    f32 var_f31;
    s32 temp_r5;
    void *p;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        ((TObjEneDD *)arg0)->set_field_378(5);
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFFC);
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 4);
        *(s32 *)((s8 *)arg0 + 0x4CC) = 0;
        *(s32 *)((s8 *)arg0 + 0x4D0) = 0;
        *(s32 *)((s8 *)arg0 + 0x4D4) = 0;
        *(s32 *)((s8 *)arg0 + 0x4D8) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x4CC) == 4) {
            transition_enemy_state__9TObjEneDDFs(arg0, 5);
        }
        return;
    case 0:
        advance_animation_playback(arg0);
        switch (*(s32 *)((s8 *)arg0 + 0x4CC)) {
        case 0:
            if (TObjEneDellBiter__sub_80305788((Obj_80098FF4 *)arg0) != 0) {
                ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                ((TObjEneDD *)arg0)->update_velocity();
                *(s32 *)((s8 *)arg0 + 0x4D8) = (s32) (u16) (s32) (TObjEneDellBiter__data_80475328 * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 0x3A0)), (f32) (*(f32 *)((s8 *)arg0 + 0x3A8))));
                *(s32 *)((s8 *)arg0 + 0x4CC) = 1;
            } else {
                *(s32 *)((s8 *)arg0 + 0x4CC) = 4;
            }
            break;
        case 1:
            *(s32 *)((s8 *)arg0 + 0x60) = approach_angle_limited((int) (*(s32 *)((s8 *)arg0 + 0x60)), (int) (*(s32 *)((s8 *)arg0 + 0x4D8)), 0x300);
            if ((s32) (u16) *(s32 *)((s8 *)arg0 + 0x60) == (s32) *(s32 *)((s8 *)arg0 + 0x4D8)) {
                *(s32 *)((s8 *)arg0 + 0x4CC) = 2;
                *(s16 *)((s8 *)arg0 + 0xB8) = 5;
            }
            ((s32 (*)(void *))noop__16TObjEneDellBiterFv)(arg0);
            break;
        case 2:
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                if (TObjEneDD::check_v2_mode() != 0) {
                    *(s32 *)((s8 *)arg0 + 0x4D0) = (s32) (*(s32 *)((s8 *)arg0 + 0x4D0) + 1);
                    if ((s32) *(s32 *)((s8 *)arg0 + 0x4D0) < 3) {
                        if (TObjEneDellBiter__sub_80305788((Obj_80098FF4 *)arg0) != 0) {
                            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                            ((TObjEneDD *)arg0)->update_velocity();
                            *(s32 *)((s8 *)arg0 + 0x4D8) = (s32) (u16) (s32) (TObjEneDellBiter__data_80475328 * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 0x3A0)), (f32) (*(f32 *)((s8 *)arg0 + 0x3A8))));
                            *(s32 *)((s8 *)arg0 + 0x4CC) = 0;
                            *(s16 *)((s8 *)arg0 + 0xB8) = 1;
                        } else {
                            *(s32 *)((s8 *)arg0 + 0x4CC) = 4;
                        }
                    } else {
                        *(s32 *)((s8 *)arg0 + 0x4CC) = 4;
                    }
                } else {
                    *(s32 *)((s8 *)arg0 + 0x4CC) = 4;
                }
            }
            if (objInBand((GameObj *)(arg0), lbl_805DEFCC) != 0) {
                temp_r5 = *(s32 *)((s8 *)arg0 + 0x4D4);
                var_f31 = (f32) *(s32 *)((s8 *)TObjEneDellBiter__movement_params + 0x24);
                if (temp_r5 > 0x96) {
                    var_f31 *= lbl_805DEFD0;
                } else if (temp_r5 > 0x46) {
                    var_f31 *= lbl_805DEFD4;
                }
                p = __nw__7TObjectFUl(0xD0);
                if (p != NULL) {
                    fn_80302FD8(p, arg0, arg0, arg0 + 0x460, *(s32 *)((s8 *)arg0 + 0x4D8), *(s32 *)((s8 *)arg0 + 0x4A0), var_f31);
                }
                play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(arg0, (void *)0x40039F17), arg0 + 0x38, 0, 0);
            }
            if (objInBand((GameObj *)(arg0), TObjEneDellBiter__data_805DEFD8) != 0) {
                spawn_particle_effect(arg0 + 0x460, 0x21F);
            }
            break;
        }
        ((TObjEneDD *)arg0)->vfunc_102();
        ((TObjEneDD *)arg0)->vfunc_89();
        return;
    case 5:
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFF7);
        break;
    }
}

void TObjEneDellBiter__sub_80303F04(u8 *arg0, s32 arg1) {
    Vec_80303F04 sp8;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 8;
        ((TObjEneDD *)arg0)->set_field_378(5);
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFFC);
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 4);
        *(s32 *)((s8 *)arg0 + 0x4CC) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x4CC) == 1) {
            transition_enemy_state__9TObjEneDDFs(arg0, 5);
        }
    case 5:
        return;
    case 0:
        advance_animation_playback(arg0);
        if (objInBand((GameObj *)(arg0), lbl_805DEFDC) != 0) {
            VecCopy((Vec *)(&sp8), (const Vec *)(arg0 + 0x38));
            sp8.y += TObjEneDellBiter__data_805DEFE0;
            if ((s32) game_difficulty_selection == 3) {
                spawn_particle_effect(&sp8, 0x21D);
                spawn_particle_effect(&sp8, 0x21E);
            } else {
                spawn_particle_effect(&sp8, 0x21B);
                spawn_particle_effect(&sp8, 0x21C);
            }
        }
        if (objInBand((GameObj *)(arg0), TObjEneDellBiter__data_805DEFE4) != 0) {
            play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(arg0, (void *)0x40039E15), arg0 + 0x38, 0, 0);
        }
        if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
            *(s32 *)((s8 *)arg0 + 0x4CC) = 1;
            *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 0x10);
            *(s32 *)((s8 *)arg0 + 0x490) = (s32) (TObjEneDellBiter__data_805DEFE8 * (f32) *(s32 *)((s8 *)TObjEneDellBiter__movement_params + 0x2C));
        }
        ((TObjEneDD *)(arg0))->vfunc_102();
        ((TObjEneDD *)(arg0))->vfunc_89();
        break;
    }
}

void TObjEneDellBiter__sub_803040D0(u8 *arg0, s32 arg1) {
    typedef char sp8_offset[(offsetof(Stack_803040D0, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_803040D0, spC) == 0x4) ? 1 : -1];
    Stack_803040D0 stack;
    f32 temp_f1;
    u32 temp_r3;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 8;
        ((TObjEneDD *)arg0)->set_field_378(5);
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFFC);
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 4);
        *(s32 *)((s8 *)arg0 + 0x4CC) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x4CC) == 1) {
            transition_enemy_state__9TObjEneDDFs(arg0, 5);
        }
        return;
    case 0:
        ((s32)advance_animation_playback(arg0));
        if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
            *(s32 *)((s8 *)arg0 + 0x4CC) = 1;
        } else {
            if ((u32) *(u32 *)((s8 *)arg0 + 0x4C0) != 0U) {
                if (objInBand((GameObj *)(arg0), lbl_805DEFEC) != 0) {
                    queue_destruction__7TObjectFv(((void *)((int) (*(u32 *)((s8 *)arg0 + 0x4C0)))));
                    *(u32 *)((s8 *)arg0 + 0x4C0) = 0U;
                } else {
                    temp_f1 = *(f32 *)((s8 *)arg0 + 0xC0);
                    if ((temp_f1 >= TObjEneDellBiter__data_805DEFD8) && (temp_f1 <= lbl_805DEFEC)) {
                        VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x38));
                        stack.spC += TObjEneDellBiter__data_805DEFE0;
                        ((TNowLoading *)(*(u32 *)((s8 *)arg0 + 0x4C0)))->copy_pos(&stack.sp8);
                    }
                }
            } else if (objInBand((GameObj *)(arg0), TObjEneDellBiter__data_805DEFD8) != 0) {
                *(u32 *)((s8 *)arg0 + 0x4C0) = (u32)create_particle_emitter((arg0 + 0x38), 0x211);
            }
            if (objInBand((GameObj *)(arg0), TObjEneDellBiter__data_805DEFE4) != 0) {
                TObjEneDellBiter__sub_80305688(arg0);
                play_sound_effect((int)((void *) (copy_target_state__14TObjEnePanarmsFPv(arg0, (void *)(0x40039E15)))), arg0 + 0x38, 0, 0);
            }
        }
        ((TObjEneDD *)(arg0))->vfunc_102();
        ((TObjEneDD *)(arg0))->vfunc_89();
        return;
    case 5:
        temp_r3 = *(u32 *)((s8 *)arg0 + 0x4C0);
        if (temp_r3 != 0U) {
            queue_destruction__7TObjectFv(((void *)temp_r3));
            *(u32 *)((s8 *)arg0 + 0x4C0) = 0U;
        }
        break;
    }
}

void handle_attack_event__16TObjEneDellBiterFPvi(u8 *arg0, s32 arg1) {
    s32 temp_r3;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 4;
        ((TObjEneDD *)arg0)->set_field_378(5);
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFFC);
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 4);
        fill_value_array((int) (*(s32 *)((s8 *)arg0 + 0x4A0)));
        ((TBoss4Type3 *)(*(s32 *)((s8 *)arg0 + 0x4A4)))->reset_timer();
        *(s32 *)((s8 *)arg0 + 0x4CC) = 0;
        *(s32 *)((s8 *)arg0 + 0x4D0) = 0;
        *(s32 *)((s8 *)arg0 + 0x48C) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x4D0) == 2) {
            *(s32 *)((s8 *)arg0 + 0x488) = (s32) (*(s32 *)((s8 *)arg0 + 0x488) + 1);
            if ((s32) *(s32 *)((s8 *)arg0 + 0x488) >= 2) {
                *(s32 *)((s8 *)arg0 + 0x488) = 0;
                *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFF7);
            }
            if (((s32 (*)(void *))TObjEneDellBiter__sub_803054FC)(arg0) == 0) {
                transition_enemy_state__9TObjEneDDFs(arg0, 5);
            }
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        temp_r3 = *(s32 *)((s8 *)arg0 + 0x60);
        *(s32 *)((s8 *)arg0 + 0x484) = turn_toward_angle_limited__15TObjBoss2TunnelFlllll(temp_r3, (int) (*(s32 *)((s8 *)arg0 + 0x484)), temp_r3, 0x200, 0x2000);
        switch (*(s32 *)((s8 *)arg0 + 0x4D0)) {
        case 0:
            if (objInBand((GameObj *)(arg0), TObjEneDellBiter__data_805DEFE4) != 0) {
                ((TObjEneDellBiter *)arg0)->spawn_front_particle();
            }
            ((s32 (*)(void *))TObjEneDellBiter__sub_80305E1C)(arg0);
            if (objInBand((GameObj *)(arg0), lbl_805DEFF0) != 0) {
                play_sound_effect((int) (copy_target_state__14TObjEnePanarmsFPv(arg0, (void *) (0x40039E16))), arg0 + 0x38, 0, 0);
            }
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                *(s16 *)((s8 *)arg0 + 0xB8) = 0;
                *(s32 *)((s8 *)arg0 + 0x4D0) = 1;
                *(s32 *)((s8 *)arg0 + 0x4CC) = 0;
            }
            break;
        case 1:
            *(s32 *)((s8 *)arg0 + 0x4CC) = (s32) (*(s32 *)((s8 *)arg0 + 0x4CC) + 1);
            if ((s32) *(s32 *)((s8 *)arg0 + 0x4CC) >= (s32) *(s32 *)((s8 *)TObjEneDellBiter__movement_params + 0x18)) {
                *(s32 *)((s8 *)arg0 + 0x4D0) = 2;
            }
            break;
        }
        ((TObjEneDD *)arg0)->vfunc_102();
        ((TObjEneDD *)arg0)->vfunc_89();
        break;
    case 5:
        break;
    }
}

#pragma fp_contract on

#pragma push
#pragma fp_contract on
typedef struct { f32 x, y, z; } Vec_803044AC;
#define F(t, o) (*(t *)(arg0 + (o)))
#define G(t, o) (*(t *)(TObjEneDellBiter__movement_params + (o)))
void TObjEneDellBiter__sub_803044AC(u8 *arg0, s32 arg1) {
    s32 hit;
    f32 t;
    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 7;
        ((TObjEneDD *)arg0)->set_field_378(5);
        F(s32, 0x3C0) &= ~3;
        F(s32, 0x3C0) |= 4;
        F(s32, 0x4CC) = 0;
        F(s32, 0x4D0) = 0;
        F(f32, 0x4DC) = G(f32, 0);
        F(f32, 0x4E0) = TObjEneDellBiter__data_805DEFF4;
        fill_value_array(F(s32, 0x4A0));
        ((TObjEneDD_ST *)arg0)->set_active();
        break;
    case 3:
        if (F(s32, 0x4CC) == 3) {
            F(s32, 0x488) = 0;
            F(s32, 0x48C)++;
            F(s32, 0x3C0) &= ~8;
            if (TObjEneDellBiter__sub_803054A8(arg0) == 0 && TObjEneDellBiter__sub_803054FC(arg0) == 0) {
                transition_enemy_state__9TObjEneDDFs(arg0, 5);
            }
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        switch (F(s32, 0x4CC)) {
        case 0:
            if (objInBand((GameObj *)arg0, (f32)lbl_805DEFF8) != 0 || objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)lbl_805DEFFC)) != 0) {
                play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(arg0, (void *)0x40039E12), arg0 + 0x38, 0, 0);
                ((TObjEneDellBiter *)arg0)->spawn_front_particle();
            }
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                F(s16, 0xB8) = 2;
                F(s32, 0x4CC) = 1;
                *(s32 *)((s8 *)(F(u8 *, 0xA4)) + 0x18) |= 0x700;
            }
            if (((s32 (*)(void *))enemy_validate_retained_target)(arg0) != 0) {
                ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                ((TObjEneDD *)arg0)->update_velocity();
            }
            F(s32, 0x60) = approach_angle_limited(F(s32, 0x60), (s32)(TObjEneDellBiter__data_80475328 * atan2_float(F(f32, 0x3A0), F(f32, 0x3A8))), 0x280);
            F(s32, 0x484) = turn_toward_angle_limited__15TObjBoss2TunnelFlllll(F(s32, 0x60), F(s32, 0x484), F(s32, 0x60), 0x200, 0x2000);
            ((TObjEneDD *)(arg0))->vfunc_89();
            break;
        case 1:
            TObjEneDellBiter__sub_8030591C((s32)arg0);
            if (((s32 (*)(void *))clear_active_flag__16TObjEneDellBiterFPv)(arg0) != 0) {
                ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                ((TObjEneDD *)arg0)->update_velocity();
            }
            hit = 0;
            if (enemy_probe_wall_ahead__13TBoss5GryphonFfff(arg0, F(f32, 0x3A0), F(f32, 0x3A8), TObjEneDellBiter__data_805DEFE8 * G(f32, 0)) != 0) {
                hit = 1;
            }
            ((TObjEneDD *)arg0)->move_clamped_on_ground(F(f32, 0x3A0), F(f32, 0x3A8), G(f32, 0));
            F(f32, 0x4E0) += G(f32, 0);
            if (((TObjEneDD *)arg0)->has_move_failures(1) != 0) {
                hit = 1;
            }
            ((TObjPlayer *)arg0)->update_enemy_collision_flags();
            if (*(s32 *)((s8 *)(F(u8 *, 0xA4)) + 0x18) & 0x200000) {
                hit = 1;
            }
            if (TObjEneDellBiter__sub_80305C40(arg0) != 0) {
                hit = 1;
            }
            if (((s32 (*)(void *))enemy_validate_retained_target)(arg0) != 0) {
                Vec_803044AC v;
                VecCopy((Vec *)&v, (const Vec *)(F(u8 *, 0x390) + 0x38));
                subtract_vector(&v, arg0 + 0x38);
                if (((TObjBoss2Tunnel *)(&v))->clamp_velocity() >= TObjEneDellBiter__data_805DEFE8) {
                    if (v.x * sin_table_lookup(F(s32, 0x60)) + v.z * cos_table_lookup(F(s32, 0x60)) < TObjEneDellBiter__data_805DEFF4) {
                        hit = 1;
                    }
                }
            }
            if (hit != 0 || F(f32, 0x4E0) >= G(f32, 0x10)) {
                F(s32, 0x4CC) = 2;
                F(s32, 0x4D0) = 0;
                ((TObjEneDD *)arg0)->set_field_378(5);
                play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(arg0, (void *)0x40039B14), arg0 + 0x38, 0, 0);
            }
            break;
        case 2:
            F(s32, 0x4D0)++;
            if (F(s32, 0x4D0) >= 10) {
                F(s16, 0xB8) = 3;
                TObjEneDellBiter__sub_803058DC((s32)arg0);
                if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                    F(s32, 0x3C0) &= ~4;
                    F(s32, 0x4CC) = 3;
                }
                F(f32, 0x4DC) *= lbl_805DF000;
            }
            TObjEneDellBiter__sub_80305C40(arg0);
            ((TObjEneDD *)arg0)->move_clamped_on_ground(F(f32, 0x3A0), F(f32, 0x3A8), F(f32, 0x4DC));
            break;
        }
        break;
    case 5:
        F(s32, 0x3C0) &= ~4;
        *(s32 *)((s8 *)(F(u8 *, 0xA4)) + 0x18) &= ~0x700;
        ((TObjEneDD *)arg0)->clear_field_388();
        break;
    }
}
#pragma pop

void TObjEneDellBiter__sub_8030492C(u8 *arg0, s32 arg1) {
    f32 temp_f31_2;
    s32 temp_r30;
    u8 *temp_r30_2;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        ((TObjEneDD *)arg0)->set_field_378(5);
        ((TObjEneDD *)(arg0))->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFF8);
        *(s32 *)((s8 *)arg0 + 0x4CC) = 0;
        return;
    case 3:
        if ((u32) *(u32 *)((s8 *)arg0 + 0x390) == 0U) {
            transition_enemy_state__9TObjEneDDFs(arg0, 4);
        } else if ((*(f32 *)((s8 *)arg0 + 0x3AC) >= *(f32 *)((s8 *)TObjEneDellBiter__movement_params + 0x14)) && ((s32) *(s32 *)((s8 *)arg0 + 0x48C) < 2)) {
            transition_enemy_state__9TObjEneDDFs(arg0, 6);
        } else if ((s32) *(s32 *)((s8 *)arg0 + 0x4CC) == 1) {
            transition_enemy_state__9TObjEneDDFs(arg0, 7);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback(arg0);
        if (((s32 (*)(void *))clear_active_flag__16TObjEneDellBiterFPv)(arg0) != 0) {
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            ((TObjEneDD *)arg0)->update_velocity();
        }
        *(s32 *)((s8 *)arg0 + 0x60) = approach_angle_limited((int) (*(s32 *)((s8 *)arg0 + 0x60)), temp_r30 = (s32) (TObjEneDellBiter__data_80475328 * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 0x3A0)), (f32) (*(f32 *)((s8 *)arg0 + 0x3A8)))), 0x300);
        *(s32 *)((s8 *)arg0 + 0x484) = turn_toward_angle_limited__15TObjBoss2TunnelFlllll((int) (*(s32 *)((s8 *)arg0 + 0x60)), (int) (*(s32 *)((s8 *)arg0 + 0x484)), temp_r30, 0x200, 0x2000);
        temp_r30_2 = TObjEneDellBiter__movement_params;
        if (*(f32 *)((s8 *)arg0 + 0x3AC) <= (f32) *(s32 *)((s8 *)temp_r30_2 + 0x28)) {
            temp_f31_2 = (*(f32 *)((s8 *)arg0 + 0x3A0) * sin_table_lookup((int) (*(s32 *)((s8 *)arg0 + 0x60)))) + (*(f32 *)((s8 *)arg0 + 0x3A8) * cos_table_lookup((int) (*(s32 *)((s8 *)arg0 + 0x60))));
            if (temp_f31_2 >= cos_table_lookup(0x1800)) {
                *(s32 *)((s8 *)arg0 + 0x4CC) = 1;
            }
        } else {
            ((TObjEneDD *)arg0)->move_clamped_on_ground(sin_table_lookup((int) (*(s32 *)((s8 *)arg0 + 0x60))), cos_table_lookup((int) (*(s32 *)((s8 *)arg0 + 0x60))), *(f32 *)((s8 *)temp_r30_2 + 4));
        }
        ((TObjEneDD *)(arg0))->vfunc_89();
        ((s32 (*)(void *))noop__16TObjEneDellBiterFv)(arg0);
        if ((objInBand((GameObj *)(arg0), lbl_805DF004) != 0) || (objInBand((GameObj *)(arg0), lbl_805DF008) != 0)) {
            ((TObjEneDellBiter *)arg0)->update_attack_effect();
        }
        break;
    }
}

void TObjEneDellBiter__sub_80304B88(u8 *ene_dd, s32 arg1) {
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_dd + 0xB8) = 0;
        ((TObjEneDD *)ene_dd)->set_field_378(4);
        *(s32 *)((s8 *)ene_dd + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3C0) & 0xFFFFFFF8);
        ((TObjEneDD *)(ene_dd))->vfunc_95();
        *(s32 *)((s8 *)ene_dd + 0x4CC) = 0;
        *(s32 *)((s8 *)ene_dd + 0x4D0) = 0;
        break;
    case 3:
        if (*(s32 *)((s8 *)ene_dd + 0x4CC) == 2) {
            transition_enemy_state__9TObjEneDDFs(ene_dd, 5);
        } else if (*(s32 *)((s8 *)ene_dd + 0x4CC) == 3) {
            transition_enemy_state__9TObjEneDDFs(ene_dd, 1);
        }
        break;
    case 0:
        advance_animation_playback(ene_dd);
        switch (*(s32 *)((s8 *)ene_dd + 0x4CC)) {
        case 0:
            if (((s32 (*)(void *, f32))update_linked_position__12TObjEneDD_STFf)(ene_dd, TObjEneDellBiter__data_805DF00C) != 0) {
                *(s32 *)((s8 *)ene_dd + 0x4CC) = 2;
            } else {
                *(s32 *)((s8 *)ene_dd + 0x4D0) = *(s32 *)((s8 *)ene_dd + 0x4D0) + 1;
                if (*(s32 *)((s8 *)ene_dd + 0x4D0) >= 0x3C) {
                    *(s32 *)((s8 *)ene_dd + 0x4CC) = 1;
                    ((VObj_14_80304B88 *)(ene_dd + 0x3D4))->m2();
                    *(s32 *)((s8 *)ene_dd + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3C0) | 2);
                }
            }
            break;
        case 1:
            if (((VObj_14_80304B88 *)(ene_dd + 0x3D4))->m4() != 0) {
                *(s32 *)((s8 *)ene_dd + 0x4CC) = 3;
            }
            break;
        }
        ((TObjEneDD *)(ene_dd))->vfunc_102();
        ((TObjEneDD *)(ene_dd))->vfunc_89();
        break;
    case 5:
        break;
    }
}

#pragma push
#pragma fp_contract on
#define F(t, o) (*(t *)(arg0 + (o)))
#define VO ((VObj_18_eeb1dd *)(arg0))
#define FADE ((VObj_14_0d3ae4 *)(arg0 + 0x3D4))
void TObjEneDellBiter__sub_80304D10(u8 *arg0, s32 arg1) {
    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 2;
        ((TObjEneDD *)arg0)->set_field_378(5);
        F(s32, 0x3C0) &= ~1;
        F(s32, 0x3C0) |= 6;
        *(s32 *)((s8 *)(F(u8 *, 0xA4)) + 0x18) |= 0x700;
        VO->m94();
        FADE->m3();
        F(f32, 0x4DC) = *(f32 *)TObjEneDellBiter__movement_params;
        F(s32, 0x4D0) = 0;
        play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(arg0, (void *)0x40039E12), arg0 + 0x38, 0, 0);
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg0 + 0x50));
        VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x38));
        VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
        F(f32, 0x38) -= lbl_805DF010 * sin_table_lookup(F(s32, 0x60));
        F(f32, 0x40) -= lbl_805DF010 * cos_table_lookup(F(s32, 0x60));
        F(s32, 0x4CC) = (s32)(lbl_805DF010 / *(f32 *)TObjEneDellBiter__movement_params);
        F(s32, 0x488) = 0;
        F(s32, 0x48C) = 0;
        ((TObjEneDD_ST *)arg0)->set_active();
        break;
    case 3:
        if (F(s32, 0x4D0) == 2) {
            transition_enemy_state__9TObjEneDDFs(arg0, 5);
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        switch (F(s32, 0x4D0)) {
        case 0:
            TObjEneDellBiter__sub_8030591C((s32)arg0);
            F(f32, 0x38) = F(f32, 0x4DC) * sin_table_lookup(F(s32, 0x60)) + F(f32, 0x38);
            F(f32, 0x40) = F(f32, 0x4DC) * cos_table_lookup(F(s32, 0x60)) + F(f32, 0x40);
            TObjEneDellBiter__sub_80305C40(arg0);
            F(s32, 0x4CC)--;
            if (F(s32, 0x4CC) <= 0) {
                F(s32, 0x4D0) = 1;
                F(s32, 0x4CC) = 0;
                F(s32, 0x3C0) &= ~4;
                ((TObjEneDD *)arg0)->set_field_378(5);
                play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(arg0, (void *)0x40039B14), arg0 + 0x38, 0, 0);
            }
            VO->m100();
            break;
        case 1:
            F(s32, 0x4CC)++;
            if (F(s32, 0x4CC) >= 10) {
                F(s16, 0xB8) = 3;
                TObjEneDellBiter__sub_803058DC((s32)arg0);
                if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                    F(s32, 0x4D0) = 2;
                }
                F(f32, 0x4DC) *= lbl_805DF000;
            }
            TObjEneDellBiter__sub_80305C40(arg0);
            ((TObjEneDD *)arg0)->move_clamped_on_ground(F(f32, 0x3A0), F(f32, 0x3A8), F(f32, 0x4DC));
            break;
        }
        if (FADE->m5() != 0) {
            F(s32, 0x3C0) &= ~2;
            VO->m87();
        }
        break;
    case 5:
        F(s32, 0x3C0) &= ~4;
        *(s32 *)((s8 *)(F(u8 *, 0xA4)) + 0x18) &= ~0x700;
        ((TObjEneDD *)arg0)->clear_field_388();
        break;
    }
}
#pragma pop

void run_task__16TObjEneDellBiterFPvi(u8 *ene_dd, s32 arg1) {

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_dd + 0xB8) = 1;
        ((TObjEneDD *)ene_dd)->set_field_378(5);
        *(s32 *)((s8 *)ene_dd + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3C0) & 0xFFFFFFFE);
        *(s32 *)((s8 *)ene_dd + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3C0) | 2);
        ((TObjEneDD *)ene_dd)->vfunc_95();
        ((WObj_80305034 *) (ene_dd + 0x3D4))->w3();
        *(s32 *)((s8 *)ene_dd + 0x4CC) = 0;
        *(s32 *)((s8 *)ene_dd + 0x4D0) = 0;
        VecCopy((Vec *)(ene_dd + 0x38), (const Vec *)(ene_dd + 0x50));
        VecCopy((Vec *)(ene_dd + 0x44), (const Vec *)(ene_dd + 0x38));
        VecCopy((Vec *)(ene_dd + 0x2FC), (const Vec *)(ene_dd + 0x38));
        *(s32 *)((s8 *)ene_dd + 0x488) = 0;
        *(s32 *)((s8 *)ene_dd + 0x48C) = 0;
        ((s32 (*)(void *, void *, int, int))play_sound_effect)(((void * (*)(void *, int))copy_target_state__14TObjEnePanarmsFPv)(ene_dd, 0x40039E12), ene_dd + 0x38, 0, 0);
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)ene_dd + 0x4D0) == 2) {
            transition_enemy_state__9TObjEneDDFs(ene_dd, 5);
        }
        return;
    case 0:
        ((s32 (*)(void))advance_animation_playback)();
        ((s32 (*)(void *, f32))update_linked_position__12TObjEneDD_STFf)(ene_dd, TObjEneDellBiter__data_805DF00C);
        *(s32 *)((s8 *)ene_dd + 0x4CC) = (s32) (*(s32 *)((s8 *)ene_dd + 0x4CC) + 1);
        switch (*(s32 *)((s8 *)ene_dd + 0x4D0)) {
        case 0:
            if ((s32) *(s32 *)((s8 *)ene_dd + 0x4CC) > 0x14) {
                *(s32 *)((s8 *)ene_dd + 0x4D0) = 1;
                *(s16 *)((s8 *)ene_dd + 0xB8) = 3;
                ((s32 (*)(void *, void *, int, int))play_sound_effect)(((void * (*)(void *, int))copy_target_state__14TObjEnePanarmsFPv)(ene_dd, 0x40039B14), ene_dd + 0x38, 0, 0);
            }
            ((s32 (*)(void *))TObjEneDellBiter__sub_8030591C)(ene_dd);
            ((TObjEneDD *)ene_dd)->move_with_wall_slide_on_ground((f32) (*(f32 *)((s8 *)ene_dd + 0x3A0)), (f32) (*(f32 *)((s8 *)ene_dd + 0x3A8)), lbl_805DF014);
            ((s32 (*)(void *))noop__16TObjEneDellBiterFv)(ene_dd);
            break;
        case 1:
            ((s32 (*)(void *))TObjEneDellBiter__sub_803058DC)(ene_dd);
            if (((TObjEneDD *)ene_dd)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)ene_dd + 0x4D0) = 2;
            }
            break;
        }
        if (((WObj_80305034 *) (ene_dd + 0x3D4))->w5() != 0) {
            *(s32 *)((s8 *)ene_dd + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3C0) & 0xFFFFFFFD);
            ((TObjEneDD *)ene_dd)->vfunc_96();
            ((TObjEneDD *)ene_dd)->vfunc_89();
            return;
        }
        break;
    case 5:
        ((TObjEneDD *)ene_dd)->vfunc_96();
        break;
    }
}

void handle_movement_event__16TObjEneDellBiterFPvi(u8 *ene_dd_st, s32 arg1) {
    switch (arg1) {
    case 4:
        ((TObjEneDD *)ene_dd_st)->set_field_378(1);
        *(s32 *)((s8 *)ene_dd_st + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd_st + 0x3C0) | 1);
        ((TObjEneDD *)ene_dd_st)->vfunc_95();
        VecCopy((Vec *)(ene_dd_st + 0x38), (const Vec *)(ene_dd_st + 0x50));
        return;
    case 3:
        if (update_linked_position__12TObjEneDD_STFf(TObjEneDellBiter__data_805DF00C) != 0) {
            ((TObjEneDD_ST *)ene_dd_st)->enemy_copy_target_destination();
            ((TObjEneDD *)ene_dd_st)->update_velocity();
            *(s32 *)((s8 *)ene_dd_st + 0x60) = (s32) (TObjEneDellBiter__data_80475328 * atan2_float((f32) (*(f32 *)((s8 *)ene_dd_st + 0x3A0)), (f32) (*(f32 *)((s8 *)ene_dd_st + 0x3A8))));
            if ((s32) *(s32 *)((s8 *)ene_dd_st + 0x4BC) == 1) {
                transition_enemy_state__9TObjEneDDFs(ene_dd_st, 3);
                return;
            }
            transition_enemy_state__9TObjEneDDFs(ene_dd_st, 2);
        } else {
        case 5:
        case 0:
            return;
        }
        break;
    }
}

void TObjEneDellBiter::update_state(s32 arg1) {
    switch (arg1) {
    case 4:
        set_field_378(0);
        *(s32 *)((s8 *)this + 0x4CC) = 0;
        return;
    case 3:
        ((s32 (*)(void *, s32))transition_enemy_state__9TObjEneDDFs)(this, 1);
        return;
    case 0:
        *(s32 *)((s8 *)this + 0x4CC) = (s32) (*(s32 *)((s8 *)this + 0x4CC) + 1);
    case 5:
        return;
    }
}

void TObjEneDellBiter__vt85(s32 ene_dd, u32 arg1, s32 arg2) {
    switch (arg1) {
    case 0:
        ((TObjEneDellBiter *)ene_dd)->update_state(arg2);
        return;
    case 1:
        ((s32 (*)(void *, void *))handle_movement_event__16TObjEneDellBiterFPvi)((void *)ene_dd, (void *)arg2);
        return;
    case 2:
        ((s32 (*)(void *, void *))run_task__16TObjEneDellBiterFPvi)((void *)ene_dd, (void *)arg2);
        return;
    case 3:
        TObjEneDellBiter__sub_80304D10((u8 *)ene_dd, (s32)arg2);
        return;
    case 4:
        TObjEneDellBiter__sub_80304B88((u8 *)ene_dd, (s32)arg2);
        return;
    case 5:
        TObjEneDellBiter__sub_8030492C((u8 *)ene_dd, (s32)arg2);
        return;
    case 6:
        TObjEneDellBiter__sub_803044AC((u8 *)ene_dd, (s32)arg2);
        return;
    case 7:
        ((s32 (*)(void *, void *))handle_attack_event__16TObjEneDellBiterFPvi)((void *)ene_dd, (void *)arg2);
        return;
    case 8:
        ((s32 (*)(void *, void *))TObjEneDellBiter__sub_803040D0)((void *)ene_dd, (void *)arg2);
        return;
    case 9:
        TObjEneDellBiter__sub_80303BC0((u8 *)ene_dd, (s32)arg2);
        return;
    case 12:
        ((s32 (*)(void *, void *))TObjEneDellBiter__sub_80303F04)((void *)ene_dd, (void *)arg2);
        return;
    case 10:
        ((s32 (*)(void *, void *))TObjEneDellBiter__sub_80303AA0)((void *)ene_dd, (void *)arg2);
        return;
    case 11:
        ((s32 (*)(void *, void *))state_death__16TObjEneDellBiterFPvi)((void *)ene_dd, (void *)arg2);
    default:
        return;
    }
}

s32 TObjEneDellBiter__sub_803054A8(u8 *actor) {
    if (calc_boss4_scale__10TObjPlayerFi((s32)actor) <= *(f32 *)((s8 *)actor + 0x4A8)) {
        ((s32 (*)(void *, s32))transition_enemy_state__9TObjEneDDFs)(actor, 8);
        return 1;
    }
    return 0;
}

s32 TObjEneDellBiter__sub_803054FC(u8 *actor) {
    if (calc_boss4_scale__10TObjPlayerFi((s32)actor) <= *(f32 *)((s8 *)actor + 0x4B4)) {
        ((s32 (*)(void *, s32))transition_enemy_state__9TObjEneDDFs)(actor, 9);
        return 1;
    }
    return 0;
}

s32 TObjEneDellBiter::check_low_hp_transition() {
    u8 *arg0 = (u8 *)this;
    if (!(*(s32 *)((s8 *)arg0 + 0x3C0) & 0x10) && ((s16) *(s16 *)((s8 *)arg0 + 0x32C) <= (s32) ((s16) *(s16 *)((s8 *)arg0 + 0x2B8) / 2)) && (calc_boss4_scale__10TObjPlayerFi((s32)((s32) arg0)) <= *(f32 *)((s8 *)arg0 + 0x4B8))) {
        ((s32 (*)(void *, s32))transition_enemy_state__9TObjEneDDFs)(arg0, 0xC);
        return 1;
    }
    return 0;
}

void TObjEneDellBiter::sub_803055C8() {
    s32 player;
    u16 temp_r3;
    temp_r3 = *(u16 *)((s8 *)((u8 *)this) + 0x2D4);
    if (temp_r3 < 0x1000U) {
        player = (s32)get_player_by_client_id(temp_r3);
        if (player != 0) {
            this->set_target_player((void *)player);
        }
        *(s32 *)((s8 *)((u8 *)this) + 0x3C0) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x3C0) | 8);
    }
}

void TObjEneDellBiter__vt102(void *ene_epsilon, f32 farg0) {
    if (((VObj_8030561C_8030535C *)ene_epsilon)->m97() != 0) {
        ((TObjEneDD_ST *)ene_epsilon)->select_and_apply_target(farg0);
        return;
    }
    spawn_part__14TObjEneEpsilonFi(ene_epsilon, farg0);
}

void noop__16TObjEneDellBiterFv(void) {  }

s32 TObjEneDellBiter__sub_80305788(Obj_80098FF4 *self) {
    s32 count;
    Obj_80098FF4 *player;
    u16 id;
    s32 i;
    f32 dist;
    f32 best;
    best = TObjEneDellBiter__data_805DEFF4;
    id = 0xFFFF;
    count = TLobby::get_game_mode();
    for (i = 0; i < count; i++) {
        player = get_player_data__10TObjPlayerFi(i);
        if (is_alive__9TObjEneDDFv(player) != 0) {
            dist = horizontal_distance_squared(self->field2FC, player->pos);
            if (dist < lbl_805DF018 && dist > best &&
                csnLookAt(self->field2FC, player->field2FC) == 0) {
                id = ((u16 (*)(void *))obj_getField1c)(player);
                best = dist;
            }
        }
    }
    if (id != 0xFFFF) {
        enemy_set_target_id(self, id);
        return 1;
    }
    enemy_clear_target__12TObjEneDD_STFUs(self);
    return 0;
}

void clear_active_flag__16TObjEneDellBiterFPv(void *arg0) {
    if (!(*(s32 *)((s8 *)arg0 + 0x3C0) & 8)) {
        update_linked_position__12TObjEneDD_STFf((*(f32 *)&TObjEneDellBiter__data_805DF00C));
        return;
    }
    if (enemy_validate_retained_target() == 0) {
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFF7);
    }
}

void TObjEneDellBiter__sub_803058DC(s32 arg0) {
    if (objInBand((GameObj *)arg0, (f32)lbl_805DF008) != 0) {
        ((TObjEneDellBiter *)arg0)->spawn_front_particle();
    }
}

void TObjEneDellBiter__sub_8030591C(s32 arg0) {
    if ((objInBand((GameObj *)(arg0), TObjEneDellBiter__data_805DEFF4) != 0) || (objInBand((GameObj *)(arg0), lbl_805DF01C) != 0)) {
        if (TObjEneDellBiter__sub_803059BC((void *)arg0, (void *)(arg0 + 0x38)) != 0) {
            fn_800D8830((void *)arg0, (void *)(arg0 + 0x38));
            return;
        }
        play_persistent_sound((((s32 (*)(void *, int))copy_target_state__14TObjEnePanarmsFPv)((void *)arg0, 0x40039E13)), (arg0), (arg0 + 0x38), 0, 0);
        spawn_particle_effect((void *)(arg0 + 0x38), 0xF0);
    }
}

s32 TObjEneDellBiter__sub_803059BC(void *arg0, void *arg1) {
    Vec_803059BC pos;
    Hit_803059BC *hit;
    void *e;
    VecCopy((Vec *)&pos, (const Vec *)arg1);
    pos.y += TObjEneDellBiter__data_805DEFC0;
    hit = (Hit_803059BC *)csnVectorUnder((s32)&pos, (u32 *)((u8 *)arg0 + 0x120), 0x4007);
    if (hit != NULL) {
        *(u32 *)((s8 *)arg0 + 0x3C4) = *(u32 *)((s8 *)hit->obj + 0x18);
        if (*(u32 *)((s8 *)arg0 + 0x3C4) & 0x4000) {
            VecCopy((Vec *)((u8 *)arg0 + 0x3C8), (const Vec *)hit->obj);
        } else {
            VecCopy((Vec *)((u8 *)arg0 + 0x3C8), (const Vec *)((u8 *)arg0 + 0x38));
        }
        if (hit->flags & 4) {
            e = (void *)spawn_particle_effect(hit->obj + 0x38, 0x49);
            if (e != NULL) {
                attach_particle_model((u8 *)e, (s32)(TParticleCtrl::get_particle_model(2)), (s32)(TParticleCtrl::get_instance()), 0, 1, (f32)TObjEneDellBiter__data_805DEFD8);
                ((TObjPlayer *)e)->set_position_xy(lbl_805DF020, lbl_805DF020);
            }
            e = (void *)spawn_particle_effect(hit->obj + 0x38, 0xA4);
            if (e != NULL) {
                ((TObjPlayer *)e)->set_position_xy(lbl_805DF020, lbl_805DF020);
            }
            return 1;
        }
        if (hit->flags & 2) {
            e = (void *)spawn_particle_effect(hit->obj + 0x54, 0x49);
            if (e != NULL) {
                attach_particle_model((u8 *)e, (s32)(TParticleCtrl::get_particle_model(2)), (s32)(TParticleCtrl::get_instance()), 0, 1, (f32)TObjEneDellBiter__data_805DEFD8);
                ((TObjPlayer *)e)->set_position_xy(lbl_805DF020, lbl_805DF020);
            }
            e = (void *)spawn_particle_effect(hit->obj + 0x54, 0xA4);
            if (e != NULL) {
                ((TObjPlayer *)e)->set_position_xy(lbl_805DF020, lbl_805DF020);
            }
            return 1;
        }
    }
    return 0;
}

void TObjEneDellBiter::spawn_front_particle() {
    u8 *arg0 = (u8 *)this;
    Stack_80305B60 stack;
    stack.sp8 = lbl_805DF024;
    stack.spC = TObjEneDellBiter__data_805DEFF4;
    stack.sp10 = lbl_805DF004;
    ((s32 (*)(void *, void *, int, f32, f32))rotate_xz_pair_by_angle)(&stack.sp8, &stack.sp10, (int) (*(s32 *)((s8 *)arg0 + 0x60)), TObjEneDellBiter__data_805DEFF4, lbl_805DF024);
    vec3_add_to(&stack.sp8, arg0 + 0x38);
    if (TObjEneDellBiter__sub_803059BC(arg0, &stack.sp8) == 0) {
        spawn_particle_effect(&stack.sp8, 0xF3);
    }
}

void TObjEneDellBiter::update_attack_effect() {
    s32 arg0 = (s32)this;
    if (((s32 (*)(s32, s32))TObjEneDellBiter__sub_803059BC)(arg0, arg0 + 0x38) != 0) {
        TObjEneGibbles__sub_800D8988(arg0 + 0x38);
        return;
    }
    ((s32 (*)(s32, s32, s32, s32))play_sound_effect)((s32)((s32 (*)(s32, s32))copy_target_state__14TObjEnePanarmsFPv)(arg0, 0x40039E11), arg0 + 0x38, 0, 0);
}

s32 TObjEneDellBiter__sub_80305C40(u8 *arg0) {
    s32 hit;
    Obj_80305C40 *p;
    s32 i;
    Atk_80305C40 atk;
    void *n;
    hit = 0;
    VecCopy((Vec *)(*(u8 **)((s8 *)arg0 + 0x49C) + 0x38), (const Vec *)(arg0 + 0x38));
    TObjPlayer::init_all_slots();
    ((TObjPlayer *)(*(u8 **)((s8 *)arg0 + 0x49C)))->check_object_collisions();
    if (*(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 **)((s8 *)arg0 + 0x49C)) + 0xA4)) + 0x18) & 0x180000) {
        hit = 1;
        for (i = 0; i < 0x10; i++) {
            p = get_battle_param__10TObjPlayerFi(i);
            if (p == NULL) {
                break;
            }
            if (obj_is_hit_receivable() != 0 && attack_target_history_add(*(s32 *)((s8 *)arg0 + 0x4A0), p) != 0) {
                if (*(s32 *)((s8 *)arg0 + 0x3C0) & 0x10) {
                    if (game_difficulty_selection == 3) {
                        atk.type = 5;
                        atk.val = *(s32 *)((s8 *)TObjEneDellBiter__movement_params + 0x1C);
                    } else {
                        atk.type = 3;
                        atk.val = *(s32 *)((s8 *)TObjEneDellBiter__movement_params + 0x1C);
                    }
                } else {
                    atk.type = 0;
                    atk.val = *(s32 *)((s8 *)TObjEneDellBiter__movement_params + 0x20);
                }
                p->m21(arg0, atk, 0, -1, -1);
                if (obj_testFlags30__13TUnk_804AF8A0FUl(p, 0x04000000) == 0) {
                    obj_setFlags30(p, 0x600);
                }
                n = __nw__7TObjectFUl(0x34);
                if (n != NULL) {
                    ((void (*)(void *, void *, void *, void *, f32))TObjEneDellBiter_Eff_Rush__ct)(n, arg0, arg0, p, lbl_805DF028);
                }
            }
        }
    }
    return hit;
}

void TObjEneDellBiter__sub_80305E1C(u8 *arg0) {
    Obj_80305E1C *o = (Obj_80305E1C *)arg0;
    f32 f = *(f32 *)((s8 *)arg0 + 0xC0);
    if (f >= lbl_805DEFF0 && f <= lbl_805DF02C) {
        *(s32 *)((s8 *)o->a + 0x60) = *(s32 *)((s8 *)arg0 + 0x60);
        VecCopy((Vec *)((u8 *)o->a + 0x38), (const Vec *)o->pos);
        ((TUnk_804AF8A0 *)(o->a))->refresh_collision_body_centers();
        *(s32 *)((s8 *)o->b + 0x60) = *(s32 *)((s8 *)arg0 + 0x60);
        VecCopy((Vec *)((u8 *)o->b + 0x38), (const Vec *)o->pos);
        ((TUnk_804AF8A0 *)(o->b))->refresh_collision_body_centers();
        S_80305E1C sp = lbl_8047528C[0];
        sp.f = get_attack_params_atp_min((void *)TObjEneDellBiter__shared_handler_param);
        if (((VObj_18_cf2ce9 *)arg0)->m97() != 0) {
            sp.flags |= 2;
        }
        o->a->m15(&sp, o->v);
        o->b->m15(&sp, o->v);
    }
}

void TObjEneDellBiter::init_target_offsets() {
    u8 *arg0 = (u8 *)this;
  const f32 *new_var;
  *((f32 *) (((s8 *) arg0) + 0x4A8)) = (f32) (lbl_805DF030 + (*((f32 *) (((s8 *) arg0) + 0x354))));
  *((f32 *) (((s8 *) arg0) + 0x4AC)) = (f32) (lbl_805DF030 + (*((f32 *) (((s8 *) arg0) + 0x358))));
  *((f32 *) (((s8 *) arg0) + 0x4B0)) = (f32) (TObjEneDellBiter__data_805DEFE8 + (*((f32 *) (((s8 *) arg0) + 0x35C))));
  if ((*((f32 *) (((s8 *) arg0) + 0x4B0))) < (*(new_var = &TObjEneDellBiter__data_805DEFE0)))
  {
    *((f32 *) (((s8 *) arg0) + 0x4B0)) = (f32) (*new_var);
  }
  *((f32 *) (((s8 *) arg0) + 0x4B4)) = (f32) (lbl_805DF030 + (*((f32 *) (((s8 *) arg0) + 0x360))));
  *((f32 *) (((s8 *) arg0) + 0x4B8)) = (f32) (lbl_805DF034 + (*((f32 *) (((s8 *) arg0) + 0x364))));
  if (((s32) (*((s32 *) (((s8 *) arg0) + 0x368)))) >= 1)
  {
    *((s32 *) (((s8 *) arg0) + 0x4BC)) = 1;
    return;
  }
  *((s32 *) (((s8 *) arg0) + 0x4BC)) = 0;
}

void TObjEneDellBiter::update_particle_emitters() {
    u8 *arg0 = (u8 *)this;
    Stack_80305FDC stack;
    s32 temp_r3;
    u8 *temp_r3_2;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    u8 *temp_r3_5;
    u8 *temp_r3_6;
    temp_r3 = *(s32 *)((s8 *)arg0 + 0x3C0);
    if (temp_r3 & 0x10) {
        if ((s32) *(s32 *)((s8 *)arg0 + 0x490) <= 0) {
            *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (temp_r3 & 0xFFFFFFEF);
        } else {
            VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x38));
            stack.spC += TObjEneDellBiter__data_805DEFE0;
            if ((s32) game_difficulty_selection == 3) {
                temp_r3_2 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x4C4));
                if (temp_r3_2 == NULL) {
                    *(u8 **)((s8 *)arg0 + 0x4C4) = (u8 *)create_particle_emitter(&stack.sp8, 0x216);
                } else {
                    ((TNowLoading *)temp_r3_2)->copy_pos(&stack.sp8);
                }
            } else {
                temp_r3_3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x4C4));
                if (temp_r3_3 == NULL) {
                    *(u8 **)((s8 *)arg0 + 0x4C4) = (u8 *)create_particle_emitter(&stack.sp8, 0x215);
                } else {
                    ((TNowLoading *)temp_r3_3)->copy_pos(&stack.sp8);
                }
                temp_r3_4 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x4C8));
                if (temp_r3_4 == NULL) {
                    *(u8 **)((s8 *)arg0 + 0x4C8) = (u8 *)create_particle_emitter(&stack.sp8, 0x219);
                } else {
                    ((TNowLoading *)temp_r3_4)->copy_pos(&stack.sp8);
                }
            }
        }
        *(s32 *)((s8 *)arg0 + 0x490) = (s32) (*(s32 *)((s8 *)arg0 + 0x490) - 1);
        return;
    }
    temp_r3_5 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x4C4));
    if (temp_r3_5 != NULL) {
        queue_destruction__7TObjectFv(temp_r3_5);
        *(u8 **)((s8 *)arg0 + 0x4C4) = NULL;
    }
    temp_r3_6 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x4C8));
    if (temp_r3_6 != NULL) {
        queue_destruction__7TObjectFv(temp_r3_6);
        *(u8 **)((s8 *)arg0 + 0x4C8) = NULL;
    }
}

void TObjEneDellBiter::vfunc_88() {  }

void TObjEneDellBiter::set_effect_pos_above_self() {
    u8 *arg0 = (u8 *)this;
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x300) = (f32) (*(f32 *)((s8 *)arg0 + 0x300) + lbl_805DF028);
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x2FC));
}

void TObjEneDellBiter::vfunc_61() {  }

void TObjEneDellBiter::vfunc_62() {
    u8 *arg0 = (u8 *)this;
    if ((s16) *(s16 *)((s8 *)arg0 + 0x326) != 0xA) {
        ((s32 (*)(void))sub_803055C8__16TObjEneDellBiterFv)();
        if (*(s32 *)((s8 *)arg0 + 0x3C0) & 0x14) {
            ((TObjEneDD *)arg0)->clear_attack_receipts();
            return;
        }
        ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFs)(arg0, (void*)(0xA));
    }
}

void TObjEneDellBiter::vfunc_63() { if (*(short*)((char*)this + 0x326) != 11) { ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFs)(this, (void*)11); } }

void TObjEneDellBiter::vfunc_28() {  }

void run_task__16TObjEneDellBiterFv(u8 *arg0) {
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TObjEneDellBiter *)(arg0))->vfunc_106();
        return;
    }
    if (((TObjEneDellBiter *)(arg0))->vfunc_83() != 4) {
        ((TObjEneDellBiter *)(arg0))->vfunc_85();
        if ((s32) TObjEneDellBiter__last_uv_scroll_tick != (s32) actor_frame_tick) {
            TObjEneDellBiter__last_uv_scroll_tick = actor_frame_tick;
            TObjPlayer__sub_8023DEE0((s16 *)TObjEneDellBiter__scrolling_uv_polygon_list, 0xC, 0, 0);
        }
    }
    ((TObjEneDellBiter *)arg0)->update_particle_emitters();
    if (*(s32 *)((s8 *)arg0 + 0x3C4) & 0x4000) {
        TObjEneRecon::set_active();
    }
    ((TObjEneDellBiter *)arg0)->set_effect_pos_above_self();
    ((TBoss8Dragon *)arg0)->set_player_state_default();
    ((TObjEneDellBiter *)(arg0))->vfunc_100();
}

u8 *__dt__16TObjEneDellBiterFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TObjEneDellBiter;
        if (*(void **)((s8 *)arg0 + 0x4C0) != NULL) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x4C0));
            *(void **)((s8 *)arg0 + 0x4C0) = NULL;
        }
        if (*(void **)((s8 *)arg0 + 0x4C4) != NULL) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x4C4));
            *(void **)((s8 *)arg0 + 0x4C4) = NULL;
        }
        if (*(void **)((s8 *)arg0 + 0x4C8) != NULL) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x4C8));
            *(void **)((s8 *)arg0 + 0x4C8) = NULL;
        }
        if (*(void **)((s8 *)arg0 + 0x4A4) != NULL) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x4A4));
            *(void **)((s8 *)arg0 + 0x4A4) = NULL;
        }
        if (*(void **)((s8 *)arg0 + 0x4A0) != NULL) {
            delete_buffer__12TBoss8DragonFis((s32)(*(void **)((s8 *)arg0 + 0x4A0)), 1);
            *(void **)((s8 *)arg0 + 0x4A0) = NULL;
        }
        if (*(VD_803062D4 **)((s8 *)arg0 + 0x498) != NULL) {
            delete *(VD_803062D4 **)((s8 *)arg0 + 0x498);
            *(VD_803062D4 **)((s8 *)arg0 + 0x498) = NULL;
        }
        if (*(VD_803062D4 **)((s8 *)arg0 + 0x494) != NULL) {
            delete *(VD_803062D4 **)((s8 *)arg0 + 0x494);
            *(VD_803062D4 **)((s8 *)arg0 + 0x494) = NULL;
        }
        if (*(VD_803062D4 **)((s8 *)arg0 + 0x49C) != NULL) {
            free_collision_body_parts(*(VD_803062D4 **)((s8 *)arg0 + 0x49C));
            delete *(VD_803062D4 **)((s8 *)arg0 + 0x49C);
            *(VD_803062D4 **)((s8 *)arg0 + 0x49C) = NULL;
        }
        free_collision_body_parts(arg0);
        __destroy_arr(arg0 + 0x3F0, __dt__13TUnk_804949A8Fv, 0x1C, 4);
        __dt__13TUnk_80490470Fv(arg0 + 0x3D4, -1);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 dellbiter_boss_stat_handle;
extern s32 dellbiter_object_stat_handle;
extern const f32 lbl_805DF038;
void TObjEneDellBiter::init_params() {
    Obj_80306468 *self = (Obj_80306468 *)this;
    s32 i;
    void *n;

    ((TObjEneDD *)self)->init_position_vectors();
    self->f34 = ((Glob_80306468 *)TObjEneDellBiter__shared_model_resource)->cfg->f8;
    self->f24 = ((Glob_80306468 *)TObjEneDellBiter__shared_model_resource)->cfg->fC;
    init_model__9TObjEneDDFv(self, (Part_80306468 *)lbl_804E6B8C, 1);
    *(u32 *)(self->fA4 + 0x18) |= 0x400000;
    ((TObjMotion *)self)->set_field_d8((s32)&dell_biter_param_table);
    ((TObjMotion *)self)->set_field_dc(((Glob_80306468 *)TObjEneDellBiter__shared_model_resource)->f430);
    self->fB8 = 0;
    ((TObjMotion *)self)->set_animation(self->fB8);
    ((TObjMotion *)self)->set_field_b8(self->fB8);
    reset_hp__9TObjEneDDFv(self, dellbiter_boss_stat_handle, TObjEneDellBiter__shared_handler_param, dellbiter_object_stat_handle);
    ((TObjEneDD *)self)->set_state_8();
    self->f350 = TObjEneDellBiter__param_table;
    initialize_enemy_state__9TObjEneDDFv(self, 0x48);
    self->f37C = lbl_805DF038;
    ((TObjEneDD_ST *)self)->enemy_init_acquire_period(30);
    ((TObjEneDD_ST *)self)->enemy_init_validate_period(30);
    self->f3C0 = 0;
    self->f3C4 = 0;
    VecCopy((Vec *)&self->v3C8, (const Vec *)&self->pos);
    self->f3C0 |= 1;
    ((V3D4_80306468 *)self->sub3D4)->m3();
    for (i = 0; i < 4; i++) {
        ((TObjPlayer *)(&self->arr3F0[i]))->activate_and_dispatch();
    }
    for (i = 0; i < 3; i++) {
        VecCopy((Vec *)&self->v460[i], (const Vec *)&self->pos);
    }
    self->f484 = 0;
    self->f488 = 0;
    self->f48C = 0;
    self->f490 = 0;
    n = __nw__7TObjectFUl(0xB0);
    if (n != NULL) {
        n = ((TUnk_804928CC *)n)->init_instance((void *)self, (void *)self, (void *)(&((Part_80306468 *)lbl_804E6B8C)[1]), (void *)1);
    }
    self->f494 = n;
    n = __nw__7TObjectFUl(0xB0);
    if (n != NULL) {
        n = ((TUnk_804928CC *)n)->init_instance((void *)self, (void *)self, (void *)(&((Part_80306468 *)lbl_804E6B8C)[2]), (void *)1);
    }
    self->f498 = n;
    n = __nw__7TObjectFUl(0xAC);
    if (n != NULL) {
        n = __ct__13TUnk_804AF8A0FP7TObject(n, 0);
    }
    self->f49C = n;
    init_collision_body_parts(self->f49C, &((Part_80306468 *)lbl_804E6B8C)[3], 1);
    n = (void *)((TAdSinglePlyChrSelectGC *)0x10)->alloc();
    if (n != NULL) {
        n = TBoss8Dragon__sub_800BC5EC((u8 *)n, 8);
    }
    self->f4A0 = n;
    self->f4A4 = create__12TObjEneSaverFPvPv(0xFF5050FF, 0x80000080);
    self->f4CC = 0;
    self->f4D0 = 0;
    self->f4D4 = 0;
    self->f4D8 = 0;
    self->f4DC = TObjEneDellBiter__data_805DEFF4;
    self->f4E0 = TObjEneDellBiter__data_805DEFF4;
    self->f326 = 1;
    ((Self_80306468 *)self)->m85(self->f326, 4);
    self->f4C0 = 0;
    self->f4C4 = 0;
    self->f4C8 = 0;
}
void *TObjEneDellBiter__ct(void *ene_dell_biter, void *arg1, void *arg2) {
    ((TObjEneDD_ST *)ene_dell_biter)->init_object();
    *(s32 **)((s8 *)ene_dell_biter + 0x18) = __vt__16TObjEneDellBiter;
    ((TUnk_80490470 *)((char *)ene_dell_biter + 980))->init_vtable_and_field18();
    __construct_array((void *)((char *)ene_dell_biter + 1008), init_and_activate__10TObjPlayerFv, __dt__13TUnk_804949A8Fv, 28, 4);
    *(void **)((s8 *)ene_dell_biter + 0x0) = TObjEneDellBiter__class_name;
    invoke_initialization_hook__9TObjEneDDFv(ene_dell_biter, arg2);
    ((TObjEneDellBiter *)ene_dell_biter)->init_target_offsets();
    ((TObjEneDellBiter *)ene_dell_biter)->init_params();
    return ene_dell_biter;
}

void TObjEneDellBiter::set_min_clamped_entry_value(s32 arg0, f32 farg0) {
  u8 *new_var;
  f32 var_f1;
  var_f1 = farg0;
  if (var_f1 < lbl_805DF03C)
  {
    var_f1 = lbl_805DF03C;
  }
  new_var = (u8 *)&dell_biter_param_table.value;
  new_var = new_var + (arg0 * 0x10);
  *((f32 *) (((s8 *) new_var) + 8)) = var_f1;
}

void TObjEneDellBiter::destroy_static_instance() {
    if ((u32) TObjEneDellBiter__shared_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjEneDellBiter__shared_model_resource, 1);
        TObjEneDellBiter__shared_model_resource = 0U;
    }
}

void *TObjEneDellBiter__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x4E4);
    if (o != NULL) {
        o = TObjEneDellBiter__ct(o, tl_04, arg0);
    }
    return o;
}

#define G_80306858 (*(V3_80306858 *)&dellbiter_demo_camera_vec)
void TObjEneDellBiter::load_resources() {
    G_80306858.x = TObjEneDellBiter__data_805DEFF4;
    G_80306858.y = TObjEneDellBiter__data_805DEFF4;
    G_80306858.z = TObjEneDellBiter__data_805DEFF4;
    if (is_split_screen() != 0) {
        TObjEneDellBiter__shared_model_resource = (u32)load_enemy_bml_resource(lbl_804E6CB4);
    } else {
        TObjEneDellBiter__shared_model_resource = (u32)load_enemy_bml_resource(lbl_804E6C70);
    }
    dellbiter_boss_stat_handle = register_boss__6TLobbyFl(0xD);
    TObjEneDellBiter__shared_handler_param = dispatch_shared_handler_b__6TLobbyFl(0xD);
    dellbiter_object_stat_handle = register_object__6TLobbyFl(0xD);
    TObjEneDellBiter__movement_params = dispatch_shared_handler_a__6TLobbyFl(0xD);
    TObjEneDellBiter__demo_script_step = 0;
    TObjEneDellBiter__demo_rotate_x_angle = 0;
    TObjEneDellBiter__demo_script_cursor = 0;
    TObjEneDellBiter::set_min_clamped_entry_value(4, *(f32 *)((s8 *)TObjEneDellBiter__movement_params + 8));
    TObjEneDellBiter::set_min_clamped_entry_value(5, *(f32 *)((s8 *)TObjEneDellBiter__movement_params + 0xC));
    {
        Obj_80306858 *o = (Obj_80306858 *)TObjEneDellBiter__shared_model_resource;
        Ent_80306858 *ent = (Ent_80306858 *)lbl_804E6B8C;
        TObjEneDellBiter__scrolling_uv_polygon_list = o->p->p->p->p->v;
        TObjEneDellBiter__last_uv_scroll_tick = 0;
        S16_80306858 sp = ene_dell_biter_attack_def;
        sp.a = o->v;
        TLobby::spawn_npc_enemy((s16)0x46, (s32)((int)o->p->p), o->p->c, (s32)&sp, ent->f, (f32)TObjEneDellBiter__data_805DEFF4);
    }
}
#undef G_80306858

void TUnk_804E6FA8::vfunc_44() {
    struct VObj_80306994_80305BDC *o = (struct VObj_80306994_80305BDC *)((TItemData *)(*(s32 *)((s8 *)this + 0xF0)))->get_item_field_2();
    if (o != NULL) {
        o->m38();
    }
}

void *__dt__13TUnk_804E6FA8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E6FA8;
        __dt__11TItemObjectFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

void *TItemObject__sub_80306A28(void *arg0) {
    TItemObject__ct(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E6FA8;
    return arg0;
}
}
