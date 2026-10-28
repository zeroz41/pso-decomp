#include "types.h"
#include "pso/TObject.h"
#include "pso/misc/TOTrapChainSawEdge.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TOTrapChainSawDamage.h"
#include "pso/misc/TOTrapChainSawKey.h"
#include "pso/misc/TOTrapChainSaw.h"
#include "pso/object/TObjMotion.h"
extern "C" void vfunc_28__20TOTrapChainSawDamageFv();
extern "C" void vfunc_16__18TOTrapChainSawEdgeFv();
extern "C" void vfunc_25__18TOTrapChainSawEdgeFv();
extern "C" void vfunc_25__17TOTrapChainSawKeyFv();
extern "C" void update_extension__14TOTrapChainSawFv();

#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKey.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/TObjFish.h"

#pragma readonly_strings on

extern "C" {
u8 *fn_802C9924(s32 arg0);
s32 get_motion__17TOTrapChainSawKeyFl(s32);
s32 get_model__17TOTrapChainSawKeyFl(int, f32);
void vfunc_16__17TOTrapChainSawKeyFv(u8 *arg0);
typedef struct S_802C86D4 { u8 pad0[0xE8]; s32 fE8; } S_802C86D4;

typedef struct P_802C86D4 {
    u8 pad0[2];
    u16 sA;
    s16 sC;
    u8 pad6[2];
    s16 s10;
    s8 b12;
    s8 b13;
} P_802C86D4;

struct RecoveredGlobal_802C8910_lbl_804E0CC0 {
    s32 value;
    u8 remaining[0xDC];
};

typedef char RecoveredGlobal_802C8910_lbl_804E0CC0_size[sizeof(RecoveredGlobal_802C8910_lbl_804E0CC0) == 0xE0 ? 1 : -1];

struct VBase_18_62e3d5 { char pad[0x18]; };

struct VObj_18_62e3d5 : VBase_18_62e3d5 {
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
    virtual s32 m21(void *, s32 *, s32, s32, s32);
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual f32 m28(f32);
};

struct Pair_802C80F0 { s32 v[2]; };
struct P_802C8BD0 { s32 a; f32 b; };

struct T_802C8F68 { s32 r[3][3]; };

struct Copy_802C8E24 { u32 a; struct { u32 w[14]; } b; };

struct Ent_802C8E24 { u8 b[0x58]; };

struct Pair_802C8C60 { s32 v[2]; };

struct Obj_802C8C60 {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x70 - 0x28];
    f32 f70;
    u8 pad74[0xB4 - 0x74];
    f32 fB4;
    f32 fB8;
    s32 fBC;
    u8 padC0[0xC8 - 0xC0];
    s32 fC8;
    u8 padCC[0xF8 - 0xCC];
    s32 fF8;
};

struct Base_802C9600 { char pad[0x18]; };
struct VObj_802C9600 : Base_802C9600 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21();
};
typedef void (VObj_802C9600::*Act_802C9600)();

struct VBase_18_52534d { char pad[0x18]; };

struct VObj_18_52534d : VBase_18_52534d {
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
    virtual s32 m23();
};

struct RecoveredGlobal_802C9890___vt__14TOTrapChainSaw {
    s32 value;
    u8 remaining[0x78];
};

typedef struct F4_802C8FF8 { f32 v[4]; } F4_802C8FF8;

typedef struct S_802C9124 { u8 pad0[0xD8]; s32 f[4]; } S_802C9124;

typedef struct S_802C9174 { u8 pad0[0xD8]; s32 f[4]; } S_802C9174;

struct Base_802C91DC { char pad[0x18]; };

struct VObj_802C91DC : Base_802C91DC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(s32);
    virtual s32 m17(s32);
    virtual void m18(s32);
};

typedef char RecoveredGlobal_802C9890___vt__14TOTrapChainSaw_size[sizeof(RecoveredGlobal_802C9890___vt__14TOTrapChainSaw) == 0x7C ? 1 : -1];

struct Base_802C936C { char pad[0x18]; };

struct VObj_802C936C : Base_802C936C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
};

int memset(void*, int, int);
u16 obj_getField1c(void *);
s32 obj_setFlags30(void *, int);
s8 get_current_floor(int);
f32 fabs_float(f32);
s32 TOTrapAncient02R__sub_80154D78(void *);
void free_collision_body_parts(void *);
s32 init_collision_body_parts(void *, int, int);
s32 init_map_object_base(void *, void *);
void *get_player_by_client_id(s32 i);
void draw_ginja_model__10TObjPlayerFl(void *, void *, f32);
s32 play_persistent_sound(void *, void *, void *, int, int);
u8 is_current_floor_switch_set(u16);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);
void update_sweep__18TOTrapChainSawEdgeFv(void *arg0);
void update_extension__18TOTrapChainSawEdgeFv(void *arg0);
void * __dt__18TOTrapChainSawEdgeFv(void *arg0, s16 arg1);
u8 * TOTrapChainSawEdge__ct(u8 *arg0);
void TParticleCtrl__sub_802C8464(u32 arg0);
void vfunc_27__17TOTrapChainSawKeyFv(void);
void check_player_contact__17TOTrapChainSawKeyFv(void* p);
void vfunc_14__17TOTrapChainSawKeyFv(void);
void update_state__17TOTrapChainSawKeyFv(u8 *arg0);
void vfunc_18__17TOTrapChainSawKeyFv(S_802C86D4 *arg0);
int decode_params__17TOTrapChainSawKeyFv(void* p);
void * __dt__17TOTrapChainSawKeyFv(void *arg0, s16 arg1);
u8 * TOTrapChainSawKey__ct(u8 *arg0, void * _w1, void * _w2);
void vfunc_27__20TOTrapChainSawDamageFv(u8 *arg0);
void vfunc_26__20TOTrapChainSawDamageFv(void* p);
void vfunc_14__20TOTrapChainSawDamageFv(void);
void vfunc_25__20TOTrapChainSawDamageFv(void *arg0);
void update_state__20TOTrapChainSawDamageFv(void *arg0);
void TOTrapChainSawDamage__vt16(u8 *arg0, u8 *arg1);
void TOTrapChainSawDamage__vt14(Obj_802C8C60 *arg0, f32 _w1);
void decode_params__20TOTrapChainSawDamageFv(void *arg0);
void * __dt__20TOTrapChainSawDamageFv(void *arg0, s16 arg1);
void * TOTrapChainSawDamage__ct(void *arg0, void *arg1, void *arg2);
s32 get_area_table_value__17TOTrapChainSawKeyFii(s32 arg0, s32 arg1);
void vfunc_14__14TOTrapChainSawFv(void);
void render__14TOTrapChainSawFv(u8 *arg0);
int clear_field_d8__14TOTrapChainSawFv(void* p);
void set_hit_cooldown_for_player__14TOTrapChainSawFPv(S_802C9124 *arg0, void *arg1);
s32 consume_counter__14TOTrapChainSawFPv(S_802C9174 *arg0, void *arg1);
int check_player_contact__14TOTrapChainSawFv(void *arg0);
void update_sweep__14TOTrapChainSawFv(void *arg0);
void update_state__14TOTrapChainSawFv(u8 *arg0);
void run_task__14TOTrapChainSawFv(void *arg0);
void decode_params__14TOTrapChainSawFv(void *arg0);
void * __dt__14TOTrapChainSawFv(void *arg0, s16 arg1);
u8 * TOTrapChainSaw__ct(u8 *arg0, s32 arg1, s32 arg2);
void TOTrapChainSawDamage__sub_802C9C00(u8 *arg0, s32 arg1);
void debug_printf_at(s32, const char *, ...);
void rotate_matrix_y(int, void *);
void push_matrix(void);
s32 pop_matrix(void);
void post_translate_matrix(void *);
void set_model_node_callback(s32 arg0);
void draw_ginja_model_with_motion(void *, void *, f32);

extern s32 __vt__14TOTrapChainSaw[];
extern s32 __vt__17TOTrapChainSawKey[];
extern s32 __vt__18TOTrapChainSawEdge[];
extern s32 __vt__20TOTrapChainSawDamage[];
extern u32 seabed_suiso_linked_switch_counts[5];
extern u32 seabed_suiso_switch_counts[5];
extern s32 local_client_id;
extern s32 game_difficulty_selection;
extern void *tl_05;
void *chainsaw_ginja_model_filenames[6] = {
    (void *)"fe_obj_nokogiri_2m.gj", (void *)"fe_obj_nokogiri_4m.gj", (void *)"fe_obj_sekigai_light_moto.gj", (void *)"fe_obj_sekigai2m_moto.gj",
    (void *)"fe_obj_sekigai4m_moto.gj", (void *)0x0,
};
void *bm_obj_jungle_nokogiri_motion_names[6] = {
    (void *)"fe_obj_nokogiri_2m.njm", (void *)"fe_obj_nokogiri_4m.njm", (void *)"fe_obj_sekigai_light_moto.njm", (void *)"fe_obj_sekigai2m_moto.njm",
    (void *)"fe_obj_sekigai4m_moto.njm", (void *)0x0,
};
void *bm_obj_jungle_nokogiri_resource_descriptor[4] = {
    (void *)"bm_obj_jungle_nokogiri.bml", (void *)&chainsaw_ginja_model_filenames, (void *)&bm_obj_jungle_nokogiri_motion_names, (void *)0x50005,
};
const char *TOTrapChainSaw__name = "TOTrapChainSaw";
__declspec(section ".rodata") F4_802C8FF8 TOTrapChainSaw__level_scale_table = { 1.0f, 2.0f, 3.0f, 6.0f };
const T_802C8F68 chainsaw_area_table_values = { { { 0x4D01F, 0x4C122, 0x4BC21 }, { 0x4004D01F, 0x4004C122, 0x4004BC21 }, { 0x4004D01F, 0x4004C122, 0x4004BC21 } } };
const char *TOTrapChainSawDamage_class_name = "TOTrapChainSawDamage";
const s32 lbl_80471F28[2] = { 0, 1 };
const s32 lbl_80471F30[2] = { 0, 1 };
const char *lbl_805D3F08 = "TOTrapChainSawKey";
const s32 lbl_80471F4C[2] = { 3, 4 };
const s32 lbl_80471F54[2] = { 3, 4 };
const char *TOTrapChainSawEdge_class_name = "TOTrapChainSawEdge";
const s32 lbl_80471F70[2] = { 0, 1 };
const s32 lbl_80471F78[2] = { 0, 1 };
void *chain_saw_damage_collision_body_parts[44] = {
    (void *)0xc0a00000, (void *)0x0, (void *)0x0, (void *)0x40400000,
    (void *)0x0, (void *)0x0, (void *)0x10403, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0xc1400000,
    (void *)0x0, (void *)0x0, (void *)0x40000000, (void *)0x41000000,
    (void *)0x1, (void *)0x10503, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0xc0a00000, (void *)0x0,
    (void *)0x0, (void *)0x40400000, (void *)0x0, (void *)0x0,
    (void *)0x10403, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0xc1a00000, (void *)0x0, (void *)0x0,
    (void *)0x40000000, (void *)0x41800000, (void *)0x1, (void *)0x10503,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *chain_saw_collision_body_part_table[44] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x40400000,
    (void *)0x0, (void *)0x0, (void *)0x10403, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0xc1200000,
    (void *)0x0, (void *)0x0, (void *)0x40000000, (void *)0x41000000,
    (void *)0x1, (void *)0x10503, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x40400000, (void *)0x0, (void *)0x0,
    (void *)0x10403, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0xc1a00000, (void *)0x0, (void *)0x0,
    (void *)0x40000000, (void *)0x41900000, (void *)0x1, (void *)0x10503,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
};

void TOTrapChainSawEdge::vfunc_16() {
    Pair_802C80F0 a = *(Pair_802C80F0 *)lbl_80471F70;
    Pair_802C80F0 b = *(Pair_802C80F0 *)lbl_80471F78;
    s32 x;
    *(s32 *)((s8 *)this + 0xFC) = (s32) *(f32 *)((s8 *)this + 0x70);
    x = *(s32 *)((s8 *)this + 0xFC);
    *(s32 *)((s8 *)this + 0xFC) = x < 0 ? 0 : (x > 1 ? 1 : x);
    *(s32 *)((s8 *)this + 0xC8) = ((s32 (*)(s32))get_model__17TOTrapChainSawKeyFl)(a.v[*(s32 *)((s8 *)this + 0xFC)]);
    *(s32 *)((s8 *)this + 0xBC) = get_motion__17TOTrapChainSawKeyFl(b.v[*(s32 *)((s8 *)this + 0xFC)]);
    *(s32 *)((s8 *)this + 0x24) = (s32)fn_802C9924(0);
    *(f32 *)((s8 *)this + 0xB4) = (0.0f);
    *(f32 *)((s8 *)this + 0xB8) = (1.0f);
}

void TOTrapChainSawEdge::vfunc_25() {
    TObjFish::set_global_param((s32)(*(void **)((s8 *)this + 0x24)));
    push_matrix();
    post_translate_matrix((void *)((char *)this + 56));
    push_matrix();
    rotate_matrix_y(0, *(void **)((s8 *)this + 0x60));
    rotate_matrix_y(0, *(void **)((s8 *)this + 0xD4));
    draw_ginja_model_with_motion(*(void **)((s8 *)this + 0xC8), *(void **)((s8 *)this + 0xBC), *(f32 *)((s8 *)this + 0xB4));
    pop_matrix();
    pop_matrix();
}

void TOTrapChainSawEdge::update_sweep() {
    s32 temp_r4;

    switch (*(s32 *)((s8 *)this + 0x104)) {
    case 0:
        temp_r4 = *(s32 *)((s8 *)this + 0x100);
        if (temp_r4 > 0) {
            *(s32 *)((s8 *)this + 0x100) = (temp_r4 - 1);
            *(s32 *)((s8 *)this + 0xF8) = (s32) *(s32 *)((s8 *)this + 0xCC);
            *(s32 *)((s8 *)this + 0x104) = 1;
        }
        return;
    case 1:
        *(s32 *)((s8 *)this + 0xD4) = (s32) (*(s32 *)((s8 *)this + 0xD4) + *(s32 *)((s8 *)this + 0xD0));
        return;
    }
}

extern const f32 lbl_805DE620 = -1.0f;
void TOTrapChainSawEdge::update_extension() {
    s32 temp_r4;
    s32 temp_r4_2;

    switch (*(s32 *)((s8 *)this + 0x104)) {
    case 0:
        temp_r4 = *(s32 *)((s8 *)this + 0x100);
        if (temp_r4 > 0) {
            *(s32 *)((s8 *)this + 0x100) = (temp_r4 - 1);
            *(s32 *)((s8 *)this + 0xF8) = (s32) *(s32 *)((s8 *)this + 0xCC);
            *(s32 *)((s8 *)this + 0x104) = 1;
        }
        break;
    case 1:
        *(s32 *)((s8 *)this + 0xD4) = (s32) (*(s32 *)((s8 *)this + 0xD4) + *(s32 *)((s8 *)this + 0xD0));
        if ((s32) *(s32 *)((s8 *)this + 0xD4) < 0) {
            *(s32 *)((s8 *)this + 0xD4) = 0;
            *(s32 *)((s8 *)this + 0xD0) = (s32) ((f32) *(s32 *)((s8 *)this + 0xD0) * *(const volatile f32 *)&lbl_805DE620);
            *(s32 *)((s8 *)this + 0x104) = 0;
        }
        if (*(s32 *)((s8 *)this + 0xD4) > (temp_r4_2 = *(s32 *)((s8 *)this + 0xCC))) {
            *(s32 *)((s8 *)this + 0xD4) = temp_r4_2;
            *(s32 *)((s8 *)this + 0xD0) = (s32) ((f32) *(s32 *)((s8 *)this + 0xD0) * *(const volatile f32 *)&lbl_805DE620);
        }
        break;
    }
}

void *__dt__18TOTrapChainSawEdgeFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TOTrapChainSawEdge;
        ((void (*)(void *, int))__dt__14TOTrapChainSawFv)(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TOTrapChainSawEdge__ct(u8 *trap_chain_saw_edge) {
    ((s32 (*)(void))TOTrapChainSaw__ct)();
    *(s32 **)((s8 *)trap_chain_saw_edge + 0x18) = __vt__18TOTrapChainSawEdge;
    *(s32 *)((s8 *)trap_chain_saw_edge + 0) = (s32) TOTrapChainSawEdge_class_name;
    ((TOTrapChainSawEdge *)(trap_chain_saw_edge))->decode_params();
    ((TOTrapChainSawEdge *)(trap_chain_saw_edge))->vfunc_16();
    *(s32 *)((s8 *)trap_chain_saw_edge + 0x100) = 0;
    *(s32 *)((s8 *)trap_chain_saw_edge + 0x104) = 0;
    return trap_chain_saw_edge;
}

void TParticleCtrl__sub_802C8464(u32 arg0) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (arg0 == seabed_suiso_linked_switch_counts[i]) {
            TParticleCtrl::begin_effect_render();
            return;
        }
    }
    for (i = 0; i < 5; i++) {
        if (arg0 == seabed_suiso_switch_counts[i]) {
            TParticleCtrl::begin_effect_render();
            return;
        }
    }
    TParticleCtrl::end_effect_render();
}

void TOTrapChainSawKey::vfunc_27() {  }

int TOTrapChainSawKey::check_player_contact() { if (*(int*)((char*)this + 0xf0) != 1) { check_player_contact__14TOTrapChainSawFv(this); } }

void TOTrapChainSawKey::vfunc_25() {
    TObjFish::set_global_param((s32)(*(void **)((s8 *)this + 0x24)));
    push_matrix();
    post_translate_matrix((void *)((char *)this + 56));
    push_matrix();
    rotate_matrix_y(0, *(void **)((s8 *)this + 0x60));
    rotate_matrix_y(0, *(void **)((s8 *)this + 0xD4));
    set_model_node_callback((s32)((s32 *)TParticleCtrl__sub_802C8464));
    draw_ginja_model__10TObjPlayerFl(*(void **)((s8 *)this + 0xC8), *(void **)((s8 *)this + 0xBC), *(f32 *)((s8 *)this + 0xB4));
    set_model_node_callback(0);
    if (*(s32 *)((s8 *)this + 0xF0) == 1) {
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion(*(void **)((s8 *)this + 0xFC), *(void **)((s8 *)this + 0x100), *(f32 *)((s8 *)this + 0x104));
        TParticleCtrl::end_effect_render();
    }
    pop_matrix();
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

void TOTrapChainSawKey::vfunc_14() {
    ((s32 (*)(void))vfunc_14__14TOTrapChainSawFv)();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x13001E, "<- SELECT A MODEL");
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TOTrapChainSawKey::update_state() {
    u8 *arg0 = (u8 *)this;
    ((s32 (*)())update_state__14TOTrapChainSawFv)();
    *(f32 *)((s8 *)arg0 + 0x104) = (f32) (*(f32 *)((s8 *)arg0 + 0x104) + *(f32 *)((s8 *)arg0 + 0x108));
    if (*(f32 *)((s8 *)arg0 + 0x104) > (f32) (u32) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x100)) + 4) - 1)) {
        *(f32 *)((s8 *)arg0 + 0x104) = (f32) (0.0f);
    }
    play_persistent_sound((void *) (((s32 (*)(void *, int))get_area_table_value__17TOTrapChainSawKeyFii)(arg0, 2)), arg0, arg0 + 0x38, 0, 0);
    if ((s32) *(s32 *)((s8 *)arg0 + 0xF0) == 1) {
        play_persistent_sound((void *) (((s32 (*)(void *, int))get_area_table_value__17TOTrapChainSawKeyFii)(arg0, 1)), arg0, arg0 + 0x38, 0, 0);
    }
}

void TOTrapChainSawKey::vfunc_18() {
    P_802C86D4 p;
    ((TLobby *)(&p))->init_6x05_switch_changed();
    p.sC = 0;
    p.sA = 0xFFFF;
    p.s10 = ((S_802C86D4 *)this)->fE8;
    p.b12 = get_current_floor(0xFFFF);
    p.b13 = 1;
    ((TLobby *)(&p))->finalize_and_send_60();
}

void TOTrapChainSawKey::vfunc_16() {
    Pair_802C80F0 a = *(Pair_802C80F0 *)lbl_80471F4C;
    Pair_802C80F0 b = *(Pair_802C80F0 *)lbl_80471F54;
    s32 x;
    *(s32 *)((s8 *)((u8 *)this) + 0xF8) = (s32) *(f32 *)((s8 *)((u8 *)this) + 0x70);
    x = *(s32 *)((s8 *)((u8 *)this) + 0xF8);
    *(s32 *)((s8 *)((u8 *)this) + 0xF8) = (x < 0) ? 0 : ((x > 1) ? 1 : x);
    *(s32 *)((s8 *)((u8 *)this) + 0xC8) = ((s32 (*)(int))get_model__17TOTrapChainSawKeyFl)(a.v[*(s32 *)((s8 *)((u8 *)this) + 0xF8)]);
    *(s32 *)((s8 *)((u8 *)this) + 0xBC) = get_motion__17TOTrapChainSawKeyFl((s32)(b.v[*(s32 *)((s8 *)((u8 *)this) + 0xF8)]));
    *(s32 *)((s8 *)((u8 *)this) + 0x24) = (s32)fn_802C9924(3);
    *(f32 *)((s8 *)((u8 *)this) + 0xB4) = (0.0f);
    *(f32 *)((s8 *)((u8 *)this) + 0xB8) = (1.0f);
    *(s32 *)((s8 *)((u8 *)this) + 0xFC) = get_model__17TOTrapChainSawKeyFl(2, (0.0f));
    *(s32 *)((s8 *)((u8 *)this) + 0x100) = get_motion__17TOTrapChainSawKeyFl(2);
    *(f32 *)((s8 *)((u8 *)this) + 0x104) = (0.0f);
    *(f32 *)((s8 *)((u8 *)this) + 0x108) = (1.0f);
}

void TOTrapChainSawKey::decode_params() { ((int (*)(void*))decode_params__14TOTrapChainSawFv)(this); }

void *TOTrapChainSawKey::create() {
    void *o = __nw__7TObjectFUl(0x10C);
    if (o != NULL) {
        o = TOTrapChainSawKey__ct((u8 *)o, (void *)tl_05, (void *)this);
    }
    return o;
}

void *__dt__17TOTrapChainSawKeyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TOTrapChainSawKey;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((void (*)(void *, int))__dt__14TOTrapChainSawFv)(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TOTrapChainSawKey__ct(u8 *arg0, void * _w1, void * _w2) {
    ((s32 (*)(void))TOTrapChainSaw__ct)();
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TOTrapChainSawKey;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D3F08;
    ((TOTrapChainSawKey *)(arg0))->decode_params();
    ((TOTrapChainSawKey *)(arg0))->vfunc_16();
    init_collision_body_parts(arg0, (int) ((u8 *)(&((RecoveredGlobal_802C8910_lbl_804E0CC0 *)chain_saw_collision_body_part_table)->value) + (*(s32 *)((s8 *)arg0 + 0xF8) * 0x58)), 2);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->reset_photon_effect();
    return arg0;
}

void TOTrapChainSawDamage::vfunc_28() {
    if (*(void **)((s8 *)this + 0x104) != NULL) {
        ((TOTrapChainSawDamage *)(*(void **)((s8 *)this + 0x104)))->set_damage((s32)(*(void **)((s8 *)this + 0xD4)));
    }
    if (*(void **)((s8 *)this + 0x108) != NULL) {
        ((TOTrapChainSawDamage *)(*(void **)((s8 *)this + 0x108)))->set_damage((s32)(*(void **)((s8 *)this + 0xD4)));
    }
}

#pragma push
#pragma fp_contract on
void TOTrapChainSawDamage::vfunc_27() {
    *(s32 *)((s8 *)((u8 *)this) + 0x100) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x100) + 1);
    void *p;
    if (((s32) *(s32 *)((s8 *)((u8 *)this) + 0x100) == 5) && ((p = *(void **)((s8 *)((u8 *)this) + 0x104)) != NULL)) {
        TOTrapChainSawDamage__sub_802C9C00((u8 *)p, 1);
    }
    if (((s32) *(s32 *)((s8 *)((u8 *)this) + 0x100) == 0xA) && ((p = *(void **)((s8 *)((u8 *)this) + 0x108)) != NULL)) {
        TOTrapChainSawDamage__sub_802C9C00((u8 *)p, 1);
    }
    ((s32 (*)(s32, void *, void *, int, int))play_persistent_sound)(((s32 (*)(void *, int))get_area_table_value__17TOTrapChainSawKeyFii)(this, 0), this, (void *) (((u8 *)this) + 0x38), 0, 0);
}
#pragma pop

void TOTrapChainSawDamage::vfunc_26() { *(s32*)((char*)this + 0x100) = 0; }

void TOTrapChainSawDamage::vfunc_14() {
    vfunc_14__14TOTrapChainSawFv();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    ((void (*)(int, void *, ...))debug_printf_at)(0x13001D, (void *)"<- DAMAGE POWER");
    ((void (*)(int, void *, ...))debug_printf_at)(0x13001E, (void *)"<- SELECT A MODEL");
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TOTrapChainSawDamage::vfunc_25() {
    TObjFish::set_global_param((s32)(*(void **)((s8 *)this + 0x24)));
    push_matrix();
    post_translate_matrix((void *)((char *)this + 56));
    push_matrix();
    rotate_matrix_y(0, *(void **)((s8 *)this + 0x60));
    rotate_matrix_y(0, *(void **)((s8 *)this + 0xD4));
    draw_ginja_model_with_motion(*(void **)((s8 *)this + 0xC8), *(void **)((s8 *)this + 0xBC), *(f32 *)((s8 *)this + 0xB4));
    pop_matrix();
    pop_matrix();
}

#pragma push
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
void TOTrapChainSawDamage::update_state() {
    ((s32 (*)())update_state__14TOTrapChainSawFv)();
    if ((s32) *(s32 *)((s8 *)this + 0xF0) == 1) {
        this->clear_player_status_flag(1, 0x100);
        return;
    }
    set_indexed_flags(1, 0x100);
}
#pragma pop

#pragma push
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
void TOTrapChainSawDamage__vt16(u8 *trap_chain_saw_damage, u8 *arg1) {
    P_802C8BD0 p;
    p.a = 0;
    p.b = ((TOTrapChainSawDamage *)(trap_chain_saw_damage))->vfunc_30(*(f32 *)((s8 *)trap_chain_saw_damage + 0xFC));
    P_802C8BD0 q = p;
    ((VObj_18_62e3d5 *)(arg1))->m21(trap_chain_saw_damage, (s32 *)&q, 0, -1, -1);
    obj_setFlags30(arg1, 0x400);
}
#pragma pop

#pragma push
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
void TOTrapChainSawDamage__vt14(Obj_802C8C60 *arg0, f32 _w1) {
    Pair_802C8C60 a = *(Pair_802C8C60 *)lbl_80471F28;
    Pair_802C8C60 b = *(Pair_802C8C60 *)lbl_80471F30;
    s32 v;
    arg0->fF8 = (s32)arg0->f70;
    v = arg0->fF8;
    arg0->fF8 = v < 0 ? 0 : (v > 1 ? 1 : v);
    arg0->fC8 = get_model__17TOTrapChainSawKeyFl(a.v[arg0->fF8], _w1);
    arg0->fBC = get_motion__17TOTrapChainSawKeyFl(b.v[arg0->fF8]);
    arg0->f24 = (s32)fn_802C9924(0);
    arg0->fB4 = (0.0f);
    arg0->fB8 = (1.0f);
}
#pragma pop

#pragma push
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
void TOTrapChainSawDamage::decode_params() {
    ((s32 (*)(void))decode_params__14TOTrapChainSawFv)();
    *(f32 *)((s8 *)this + 0xFC) = (f32) *(f32 *)((s8 *)this + 0x6C);
}
#pragma pop

#pragma push
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
void *TOTrapChainSawDamage::create() {
    void *o = __nw__7TObjectFUl(0x10C);
    if (o != NULL) {
        o = TOTrapChainSawDamage__ct(o, tl_05, this);
    }
    return o;
}
#pragma pop

#pragma push
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
void *__dt__20TOTrapChainSawDamageFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__20TOTrapChainSawDamage;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((void (*)(void *, int))__dt__14TOTrapChainSawFv)(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma pop

#pragma push
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
void *TOTrapChainSawDamage__ct(void *arg0, void *arg1, void *arg2) {
    void *o;
    ((void * (*)(void *, void *, void *))TOTrapChainSaw__ct)(arg0, arg1, arg2);
    *(s32 **)(((u8 *)arg0) + 0x18) = __vt__20TOTrapChainSawDamage;
    *(s32 *)(((u8 *)arg0) + 0) = (s32) TOTrapChainSawDamage_class_name;
    ((TOTrapChainSawDamage *)arg0)->decode_params();
    ((TOTrapChainSawDamage *)arg0)->vfunc_16();
    ((s32 (*)(void *, void *, int))init_collision_body_parts)(arg0, &((Ent_802C8E24 *)chain_saw_damage_collision_body_parts)[*(s32 *)(((u8 *)arg0) + 0xF8)], 2);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->reset_photon_effect();
    *(f32 *)(((u8 *)arg0) + 0x3C) += (5.0f);
    {
        Copy_802C8E24 c = *(Copy_802C8E24 *)arg2;
        *(f32 *)((u8 *)&c + 0x10) += (1e+01f);
        o = __nw__7TObjectFUl(0x108);
        if (o != NULL) {
            o = ((void * (*)(void *, void *, void *))TOTrapChainSawEdge__ct)(o, arg0, &c);
        }
        *(void **)(((u8 *)arg0) + 0x104) = o;
        *(f32 *)((u8 *)&c + 0x10) += (5.0f);
        o = __nw__7TObjectFUl(0x108);
        if (o != NULL) {
            o = ((void * (*)(void *, void *, void *))TOTrapChainSawEdge__ct)(o, arg0, &c);
        }
        *(void **)(((u8 *)arg0) + 0x108) = o;
    }
    return arg0;
}
#pragma pop

#pragma push
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
s32 get_area_table_value__17TOTrapChainSawKeyFii(s32 arg0, s32 arg1) {
    T_802C8F68 t = chainsaw_area_table_values;
    s32 *p = t.r[0];
    switch (TOKeyMachine01::get_global_state()) {
    case 34:
        p = t.r[1];
        break;
    case 35:
        p = t.r[2];
        break;
    }
    return p[arg1];
}
#pragma pop

f32 TOTrapChainSaw::scale_by_level(f32 farg0) {
    F4_802C8FF8 t = TOTrapChainSaw__level_scale_table;
    return farg0 * t.v[game_difficulty_selection];
}

void TOTrapChainSaw::update_demo() {
    s32 temp_r31;

    if (TObjPlayer::check_demo_mode() == 1) {
        temp_r31 = *(s32 *)((s8 *)this + 0x60);
        *(s32 *)((s8 *)this + 0x60) = (s32) (temp_r31 + *(s32 *)((s8 *)this + 0xD4));
        TOTrapAncient02R__sub_80154D78(this);
        *(s32 *)((s8 *)this + 0x60) = temp_r31;
    }
}

void TOTrapChainSaw::vfunc_14() {  }

void TOTrapChainSaw::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_18_52534d *)(arg0))->m8((4e+02f), (5e+01f)) == 1) {
        this->vfunc_25();
        ((TOTrapChainSaw *)arg0)->update_demo();
    }
}

int TOTrapChainSaw::clear_field_d8() { return memset((char*)this + 0xd8, 0, 16); }

void TOTrapChainSaw::set_hit_cooldown_for_player(void *arg1) {
    S_802C9124 *arg0 = (S_802C9124 *)this;
    s32 i = obj_getField1c(arg1);
    if (i >= 0 && i < 4) {
        arg0->f[i] = 0x96;
    }
}

s32 TOTrapChainSaw::consume_counter(void *arg1) {
    S_802C9174 *arg0 = (S_802C9174 *)this;
    s32 i = obj_getField1c(arg1);
    if (i >= 0 && i < 4) {
        if (arg0->f[i] > 0) {
            arg0->f[i] = arg0->f[i] - 1;
            return 1;
        }
    }
    return 0;
}

int TOTrapChainSaw::check_player_contact() {
    s32 i;
    s32 p;
    s32 t;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        for (i = 0; i < 4; i++) {
            p = (s32)get_player_by_client_id(i);
            if (p != 0 && this->consume_counter((void *)p) == 0) {
                if (((TObjPlayer *)p)->get_field_3e4() == ((s32 (*)(void))get_current_floor)()) {
                    t = *(s32 *)((s8 *)this + 0x60);
                    *(s32 *)((s8 *)this + 0x60) = t + *(s32 *)((s8 *)this + 0xD4);
                    if (check_actor_body_contact((void *)p, (f32)((1e+02f))) != 0) {
                        ((VObj_802C91DC *)this)->m16(p);
                        this->set_hit_cooldown_for_player((void *)p);
                    }
                    *(s32 *)((s8 *)this + 0x60) = t;
                }
            }
        }
    } else {
        s32 q;
        s32 t2;
        q = (s32)get_player_by_client_id(local_client_id);
        if (q != 0 && this->consume_counter((void *)q) == 0) {
            if (((TObjPlayer *)q)->get_field_3e4() == ((s32 (*)(void))get_current_floor)()) {
                t2 = *(s32 *)((s8 *)this + 0x60);
                *(s32 *)((s8 *)this + 0x60) = t2 + *(s32 *)((s8 *)this + 0xD4);
                if (check_actor_body_contact((void *)q, (f32)((1e+02f))) != 0) {
                    ((VObj_802C91DC *)this)->m16(q);
                    this->set_hit_cooldown_for_player((void *)q);
                }
                *(s32 *)((s8 *)this + 0x60) = t2;
            }
        }
    }
}

void TOTrapChainSaw::update_extension() {
    VObj_802C936C *self = (VObj_802C936C *)this;

    if (*(s32 *)((s8 *)((u8 *)this) + 0xF0) == 0) {
        if (*(s32 *)((s8 *)((u8 *)this) + 0xEC) > 0) {
            *(s32 *)((s8 *)((u8 *)this) + 0xEC) = *(s32 *)((s8 *)((u8 *)this) + 0xEC) - 1;
            return;
        }
        if (*(s32 *)((s8 *)((u8 *)this) + 0xD4) == 0) {
            self->m24();
        }
        self->m25();
        *(s32 *)((s8 *)((u8 *)this) + 0xD4) = *(s32 *)((s8 *)((u8 *)this) + 0xD4) + *(s32 *)((s8 *)((u8 *)this) + 0xD0);
        if (*(s32 *)((s8 *)((u8 *)this) + 0xD4) < 0) {
            *(s32 *)((s8 *)((u8 *)this) + 0xD4) = 0;
            *(s32 *)((s8 *)((u8 *)this) + 0xD0) = (s32)((f32)*(s32 *)((s8 *)((u8 *)this) + 0xD0) * *(const volatile f32 *)&lbl_805DE620);
            *(s32 *)((s8 *)((u8 *)this) + 0xEC) = (s32)(30.0f * (f32)(u16)*(s32 *)((s8 *)((u8 *)this) + 0x8C));
            self->m27();
        }
        if (*(s32 *)((s8 *)((u8 *)this) + 0xD4) > *(s32 *)((s8 *)((u8 *)this) + 0xCC)) {
            *(s32 *)((s8 *)((u8 *)this) + 0xD4) = *(s32 *)((s8 *)((u8 *)this) + 0xCC);
            *(s32 *)((s8 *)((u8 *)this) + 0xD0) = (s32)((f32)*(s32 *)((s8 *)((u8 *)this) + 0xD0) * *(const volatile f32 *)&lbl_805DE620);
            self->m26();
        }
    } else {
        *(s32 *)((s8 *)((u8 *)this) + 0xD0) = (s32)fabs_float((f32)*(s32 *)((s8 *)((u8 *)this) + 0xD0));
        *(s32 *)((s8 *)((u8 *)this) + 0xD4) = *(s32 *)((s8 *)((u8 *)this) + 0xD4) - *(s32 *)((s8 *)((u8 *)this) + 0xD0);
        if (*(s32 *)((s8 *)((u8 *)this) + 0xD4) < 0) {
            *(s32 *)((s8 *)((u8 *)this) + 0xD4) = 0;
        }
    }
}

void TOTrapChainSaw::update_sweep() {
    if ((s32) *(s32 *)((s8 *)this + 0xF0) == 0) {
        if ((s32) *(s32 *)((s8 *)this + 0xD4) == 0) {
            this->vfunc_26();
        }
        this->vfunc_27();
        *(s32 *)((s8 *)this + 0xD4) = (s32) (*(s32 *)((s8 *)this + 0xD4) + *(s32 *)((s8 *)this + 0xD0));
        return;
    }
    *(s32 *)((s8 *)this + 0xD4) = (s32) (*(s32 *)((s8 *)this + 0xD4) - *(s32 *)((s8 *)this + 0xD0));
    if ((s32) *(s32 *)((s8 *)this + 0xD4) < 0) {
        *(s32 *)((s8 *)this + 0xD4) = 0;
    }
}
extern "C" { u8 *lbl_805D6808; }

#pragma push
#pragma opt_propagation off
void TOTrapChainSaw::update_state() {
    u8 *arg0 = (u8 *)this;
    static Act_802C9600 tbl[2] = { &VObj_802C9600::m20, &VObj_802C9600::m21 };
    (((VObj_802C9600 *)arg0)->*tbl[*(s32 *)((s8 *)arg0 + 0xF4)])();
    if (*(u8 **)((s8 *)arg0 + 0xBC) != NULL) {
        *(f32 *)((s8 *)arg0 + 0xB4) = *(f32 *)((s8 *)arg0 + 0xB4) + *(f32 *)((s8 *)arg0 + 0xB8);
        if (*(f32 *)((s8 *)arg0 + 0xB4) > (f32) (u32) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xBC)) + 4) - 1)) {
            *(f32 *)((s8 *)arg0 + 0xB4) = (0.0f);
        }
    }
}
#pragma pop

void TOTrapChainSaw::run_task() {
    this->update_state();
    this->check_player_contact();
    if (is_current_floor_switch_set((u16) *(s32 *)((s8 *)this + 0xE8)) == 1) {
        *(s32 *)((s8 *)this + 0xF0) = 1;
        return;
    }
    *(s32 *)((s8 *)this + 0xF0) = 0;
}

void TOTrapChainSaw::decode_params() {
    s32 var_r0;
    s32 temp_r3;
    u32 var_r0_2;
    u32 temp_r3_2;

    *(s32 *)((s8 *)this + 0xE8) = (s32) (u16) *(s32 *)((s8 *)this + 0x84);
    temp_r3 = *(s32 *)((s8 *)this + 0xE8);
    if (temp_r3 < 0) {
        var_r0 = 0;
    } else {
        var_r0 = 0xFF;
        if (temp_r3 <= 0xFF) {
            var_r0 = temp_r3;
        }
    }
    *(s32 *)((s8 *)this + 0xE8) = var_r0;
    if (is_current_floor_switch_set((u16) *(s32 *)((s8 *)this + 0xE8)) == 1) {
        *(s32 *)((s8 *)this + 0xF0) = 1;
    } else {
        *(s32 *)((s8 *)this + 0xF0) = 0;
    }
    *(u32 *)((s8 *)this + 0xCC) = (u32) ((u32) *(u32 *)((s8 *)this + 0x88) >> 0x10U);
    *(s32 *)((s8 *)this + 0xD0) = (s32) (u16) *(u32 *)((s8 *)this + 0x88);
    *(u32 *)((s8 *)this + 0xF4) = (u32) ((u32) *(u32 *)((s8 *)this + 0x8C) >> 0x10U);
    temp_r3_2 = *(u32 *)((s8 *)this + 0xF4);
    if ((s32) temp_r3_2 < 0) {
        var_r0_2 = 0;
    } else {
        var_r0_2 = 1;
        if ((s32) temp_r3_2 <= 1) {
            var_r0_2 = temp_r3_2;
        }
    }
    *(u32 *)((s8 *)this + 0xF4) = var_r0_2;
}

void *__dt__14TOTrapChainSawFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TOTrapChainSaw;
        ((TUnk_804AFBF8 *)arg0)->destroy_key_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TOTrapChainSaw__ct(u8 *trap_chain_saw, s32 arg1, s32 arg2) {
    init_map_object_base((void *)trap_chain_saw, (void *)arg1);
    *(s32 **)((s8 *)trap_chain_saw + 0x18) = &(*(RecoveredGlobal_802C9890___vt__14TOTrapChainSaw *)&__vt__14TOTrapChainSaw).value;
    *(s32 *)((s8 *)trap_chain_saw + 0) = (s32) TOTrapChainSaw__name;
    ((TOTrapChainSaw *)(trap_chain_saw))->apply_object_set_data((void *)arg2);
    ((TOTrapChainSaw *)(trap_chain_saw))->clear_field_d8();
    *(s32 *)((s8 *)trap_chain_saw + 0xD4) = 0;
    *(s32 *)((s8 *)trap_chain_saw + 0xCC) = 0;
    *(s32 *)((s8 *)trap_chain_saw + 0xD0) = 0;
    *(s32 *)((s8 *)trap_chain_saw + 0xC8) = 0;
    *(s32 *)((s8 *)trap_chain_saw + 0xF4) = 0;
    *(s32 *)((s8 *)trap_chain_saw + 0xE8) = 0;
    *(s32 *)((s8 *)trap_chain_saw + 0xEC) = 0;
    return trap_chain_saw;
}

void render_shadows__7TObjectFv();
void vfunc_6__13TUnk_804B9870FPsl();
void apply_object_set_data__13TUnk_804B9870FPv();
void reset_motion_fields__13TUnk_804AF8A0Fv();
void vfunc_9__13TUnk_804B9870Fv();
void update_object_view_visibility__13TUnk_804B9870Fff();
void classify_actor_view_detail__13TUnk_804B9870Ffff();
void get_name__13TUnk_804B9870Fv();
void interact__13TUnk_804AF8A0Fl();
void check_player_contact__18TOTrapChainSawEdgeFv();
void vfunc_18__14TOTrapChainSawFv();
void vfunc_26__14TOTrapChainSawFv();
void vfunc_27__14TOTrapChainSawFv();
void vfunc_28__14TOTrapChainSawFv();
void vfunc_29__14TOTrapChainSawFv();
void vfunc_16__14TOTrapChainSawFv();
void vfunc_25__14TOTrapChainSawFv();
s32 __vt__18TOTrapChainSawEdge[31] = {
    0,
    0,
    (s32)&__dt__18TOTrapChainSawEdgeFv,
    (s32)&run_task__14TOTrapChainSawFv,
    (s32)&render__14TOTrapChainSawFv,
    (s32)&render_shadows__7TObjectFv,
    (s32)&vfunc_6__13TUnk_804B9870FPsl,
    (s32)&apply_object_set_data__13TUnk_804B9870FPv,
    (s32)&reset_motion_fields__13TUnk_804AF8A0Fv,
    (s32)&vfunc_9__13TUnk_804B9870Fv,
    (s32)&update_object_view_visibility__13TUnk_804B9870Fff,
    (s32)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (s32)&get_name__13TUnk_804B9870Fv,
    (s32)&interact__13TUnk_804AF8A0Fl,
    (s32)&vfunc_14__14TOTrapChainSawFv,
    (s32)&decode_params__14TOTrapChainSawFv,
    (s32)&vfunc_16__18TOTrapChainSawEdgeFv,
    (s32)&check_player_contact__18TOTrapChainSawEdgeFv,
    (s32)&vfunc_18__14TOTrapChainSawFv,
    (s32)&consume_counter__14TOTrapChainSawFPv,
    (s32)&set_hit_cooldown_for_player__14TOTrapChainSawFPv,
    (s32)&clear_field_d8__14TOTrapChainSawFv,
    (s32)&update_extension__18TOTrapChainSawEdgeFv,
    (s32)&update_sweep__18TOTrapChainSawEdgeFv,
    (s32)&update_state__14TOTrapChainSawFv,
    (s32)&vfunc_25__18TOTrapChainSawEdgeFv,
    (s32)&vfunc_26__14TOTrapChainSawFv,
    (s32)&vfunc_27__14TOTrapChainSawFv,
    (s32)&vfunc_28__14TOTrapChainSawFv,
    (s32)&vfunc_29__14TOTrapChainSawFv,
    (s32)&TOTrapChainSaw::scale_by_level
};
s32 __vt__17TOTrapChainSawKey[31] = {
    0,
    0,
    (s32)&__dt__17TOTrapChainSawKeyFv,
    (s32)&run_task__14TOTrapChainSawFv,
    (s32)&render__14TOTrapChainSawFv,
    (s32)&render_shadows__7TObjectFv,
    (s32)&vfunc_6__13TUnk_804B9870FPsl,
    (s32)&apply_object_set_data__13TUnk_804B9870FPv,
    (s32)&reset_motion_fields__13TUnk_804AF8A0Fv,
    (s32)&vfunc_9__13TUnk_804B9870Fv,
    (s32)&update_object_view_visibility__13TUnk_804B9870Fff,
    (s32)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (s32)&get_name__13TUnk_804B9870Fv,
    (s32)&interact__13TUnk_804AF8A0Fl,
    (s32)&vfunc_14__17TOTrapChainSawKeyFv,
    (s32)&decode_params__17TOTrapChainSawKeyFv,
    (s32)&vfunc_16__17TOTrapChainSawKeyFv,
    (s32)&check_player_contact__17TOTrapChainSawKeyFv,
    (s32)&vfunc_18__17TOTrapChainSawKeyFv,
    (s32)&consume_counter__14TOTrapChainSawFPv,
    (s32)&set_hit_cooldown_for_player__14TOTrapChainSawFPv,
    (s32)&clear_field_d8__14TOTrapChainSawFv,
    (s32)&update_extension__14TOTrapChainSawFv,
    (s32)&update_sweep__14TOTrapChainSawFv,
    (s32)&update_state__17TOTrapChainSawKeyFv,
    (s32)&vfunc_25__17TOTrapChainSawKeyFv,
    (s32)&vfunc_26__14TOTrapChainSawFv,
    (s32)&vfunc_27__17TOTrapChainSawKeyFv,
    (s32)&vfunc_28__14TOTrapChainSawFv,
    (s32)&vfunc_29__14TOTrapChainSawFv,
    (s32)&TOTrapChainSaw::scale_by_level
};
s32 __vt__20TOTrapChainSawDamage[31] = {
    0,
    0,
    (s32)&__dt__20TOTrapChainSawDamageFv,
    (s32)&run_task__14TOTrapChainSawFv,
    (s32)&render__14TOTrapChainSawFv,
    (s32)&render_shadows__7TObjectFv,
    (s32)&vfunc_6__13TUnk_804B9870FPsl,
    (s32)&apply_object_set_data__13TUnk_804B9870FPv,
    (s32)&reset_motion_fields__13TUnk_804AF8A0Fv,
    (s32)&vfunc_9__13TUnk_804B9870Fv,
    (s32)&update_object_view_visibility__13TUnk_804B9870Fff,
    (s32)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (s32)&get_name__13TUnk_804B9870Fv,
    (s32)&interact__13TUnk_804AF8A0Fl,
    (s32)&vfunc_14__20TOTrapChainSawDamageFv,
    (s32)&decode_params__20TOTrapChainSawDamageFv,
    (s32)&TOTrapChainSawDamage__vt14,
    (s32)&check_player_contact__14TOTrapChainSawFv,
    (s32)&TOTrapChainSawDamage__vt16,
    (s32)&consume_counter__14TOTrapChainSawFPv,
    (s32)&set_hit_cooldown_for_player__14TOTrapChainSawFPv,
    (s32)&clear_field_d8__14TOTrapChainSawFv,
    (s32)&update_extension__14TOTrapChainSawFv,
    (s32)&update_sweep__14TOTrapChainSawFv,
    (s32)&update_state__20TOTrapChainSawDamageFv,
    (s32)&vfunc_25__20TOTrapChainSawDamageFv,
    (s32)&vfunc_26__20TOTrapChainSawDamageFv,
    (s32)&vfunc_27__20TOTrapChainSawDamageFv,
    (s32)&vfunc_28__20TOTrapChainSawDamageFv,
    (s32)&vfunc_29__14TOTrapChainSawFv,
    (s32)&TOTrapChainSaw::scale_by_level
};
s32 __vt__14TOTrapChainSaw[31] = {
    0,
    0,
    (s32)&__dt__14TOTrapChainSawFv,
    (s32)&run_task__14TOTrapChainSawFv,
    (s32)&render__14TOTrapChainSawFv,
    (s32)&render_shadows__7TObjectFv,
    (s32)&vfunc_6__13TUnk_804B9870FPsl,
    (s32)&apply_object_set_data__13TUnk_804B9870FPv,
    (s32)&reset_motion_fields__13TUnk_804AF8A0Fv,
    (s32)&vfunc_9__13TUnk_804B9870Fv,
    (s32)&update_object_view_visibility__13TUnk_804B9870Fff,
    (s32)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (s32)&get_name__13TUnk_804B9870Fv,
    (s32)&interact__13TUnk_804AF8A0Fl,
    (s32)&vfunc_14__14TOTrapChainSawFv,
    (s32)&decode_params__14TOTrapChainSawFv,
    (s32)&vfunc_16__14TOTrapChainSawFv,
    (s32)&check_player_contact__14TOTrapChainSawFv,
    (s32)&vfunc_18__14TOTrapChainSawFv,
    (s32)&consume_counter__14TOTrapChainSawFPv,
    (s32)&set_hit_cooldown_for_player__14TOTrapChainSawFPv,
    (s32)&clear_field_d8__14TOTrapChainSawFv,
    (s32)&update_extension__14TOTrapChainSawFv,
    (s32)&update_sweep__14TOTrapChainSawFv,
    (s32)&update_state__14TOTrapChainSawFv,
    (s32)&vfunc_25__14TOTrapChainSawFv,
    (s32)&vfunc_26__14TOTrapChainSawFv,
    (s32)&vfunc_27__14TOTrapChainSawFv,
    (s32)&vfunc_28__14TOTrapChainSawFv,
    (s32)&vfunc_29__14TOTrapChainSawFv,
    (s32)&TOTrapChainSaw::scale_by_level
};

}
