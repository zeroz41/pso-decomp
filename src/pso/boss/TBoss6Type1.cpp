#include "pso/protocol/protocol_types.h"
#include "pso/misc/TLobby_801E43E4.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/vector.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/boss/TBoss6Type1.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjMapCsn.h"
#include "pso/TParticleCtrl.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_802AA8FC.h"
#include "pso/unk/text_803D96A8.h"

extern const Vec boss6_map_csn_offset;
extern const Vec boss6_map_csn_scale;

struct RecoveredGlobal_802B5938_lbl_80470FFC {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_802B5938_lbl_80471008 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_802B5970_lbl_80470FE4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_802B5970_lbl_80470FF0 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_802B7E88_lbl_80470CEC {
    s32 value;
    u8 remaining[0x2C];
};

#include <stddef.h>
struct Stack_802B5140 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct RecoveredGlobal_802B5140_lbl_80470CD4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_802B5140_lbl_80470CE0 {
    const f32 value;
    u8 remaining[0x8];
};

struct Obj_802B4B34 { u8 pad[0x508]; s32 f508; s32 arr[1]; };

struct Obj_802B5E48 { u8 pad[0x498]; s32 f498; };

struct Obj_802B4D38 { u8 pad[0x4f8]; s32 arr[4]; };

struct Obj_802B5100 { u8 pad[0x3c]; f32 f3c; u8 pad2[0x424 - 0x40]; f32 f424; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Blk_802B8624 { s32 a; s32 b; s32 rest[14]; };

struct Obj_802B5DD4 { u8 pad[0x4e0]; s32 f4e0; s32 f4e4; };

struct V3_802B4BA8 { s32 x, y, z; };

struct T1_802B4BA8 {
    u8 pad0[0x38];
    V3_802B4BA8 pos;
};

struct Tbl_802B4BA8 { s32 a; s32 b; };

struct T1_802B529C {
    u8 pad0[0x378];
    s32 v[0x20];
};

struct V3_802B600C { s32 x; f32 y; s32 z; };

struct T1_802B600C { u8 pad0[0x38]; V3_802B600C pos; };

struct Ent_802B7944 { u8 pad0[0x18]; u32 f; u8 pad1c[0x10]; };

struct T1_802B7944 { u8 pad0[0xA4]; Ent_802B7944 *p; };

struct Vec_802B4C28 { s32 x, y, z; };
struct Obj_802B4C28 {
    u8 pad0[0x38];
    Vec_802B4C28 pos;
    u8 pad44[0x4F8 - 0x44];
    u32 parts[4];
    u8 pad508[0x578 - 0x508];
    Vec_802B4C28 pts[1];
};
struct Anim_802B82B8 { s32 id; f32 t; s32 f8; f32 blend; f32 f10; s32 prevId; f32 prevT; };
struct Boss_802B82B8 {
    u8 pad0[0x3FC];
    s32 f3FC;
    u8 pad400[0x43C - 0x400];
    s32 f43C;
    s32 f440;
    Anim_802B82B8 anim[2];
};
struct Tbl_802B82B8 { s32 f0; s32 f4; s32 ids[2]; };
struct Msg_802B9178 { u8 b[0x10]; };
struct S_802B8E1C { u8 a; s8 b; };

struct T1_802B8E1C { u8 pad0[0x3C]; f32 y; u8 pad40[0x438 - 0x40]; s32 f438; };

struct Boss_802B5434 { u8 pad[0x378]; s32 list[32]; };

struct Vec_802B54F0 { f32 x, y, z; };

struct Boss_802B54F0 { u8 pad[0x38]; Vec_802B54F0 pos; };

struct Boss_802B5648 { u8 pad0[0x3C]; f32 f3C; u8 pad40[0x374 - 0x40]; u32 f374; u8 pad378[0x41C - 0x378]; s8 f41C; };

struct Vec_802B5648 { f32 x, y, z; };

struct Vec_802B683C { f32 x, y, z; };

struct Boss_802B683C {
    u8 pad0[0x38];
    Vec_802B683C pos;
    u8 pad44[0x41C - 0x44];
    s8 f41C;
};

struct Vec_802B79DC { f32 x, y, z; };

struct Ent_802B79DC { Vec_802B79DC m; u8 padC[0x1C - 0xC]; Vec_802B79DC n; u8 pad28[0x2C - 0x28]; };

struct Tbl_802B79DC { s32 kind; s32 idx; };

struct Boss_802B79DC {
    u8 pad0[0x38];
    Vec_802B79DC pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0xA4 - 0x64];
    Ent_802B79DC *ents;
    u8 padA8[0x578 - 0xA8];
    Vec_802B79DC a578[11];
    Vec_802B79DC a5FC[1];
};

class Boss_802B865C;
union Action_802B865C { s32 words[3]; void (Boss_802B865C::*action)(); };

struct Entry_802B865C { s32 f0; s32 anim; s32 f8; s32 act[3]; s32 idle[3]; s32 update[3]; };

class Boss_802B865C {
public:
    u8 pad0[0x374];
    s32 state;
    s32 hist[32];
    u8 pad3F8[0x418 - 0x3F8];
    s32 f418;
    u8 pad41C[0x4B8 - 0x41C];
    s32 f4B8;
    s32 f4BC;
    s32 f4C0;
    s32 f4C4;
};

struct V3_802B6B34 { s32 x; f32 y; s32 z; };

union Val_802B6B34 { f32 f; s32 i; };

struct Arg_802B6B34 { s32 kind; Val_802B6B34 v; };

struct Base_802B6B34 { u8 pad[0x18]; };

struct Player_802B6B34 : Base_802B6B34 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(void *, Arg_802B6B34 *, s32, s32, s32);
    u8 pad1c[0x38 - 0x1C];
    V3_802B6B34 pos;
};

struct Boss_802B6B34 { u8 pad[0x488]; s32 f488; };

struct Vec_802B73AC { f32 x, y, z; };

struct Boss_802B73AC {
    u8 pad0[0x408];
    s32 f408;
    u8 pad40c[0x5D8 - 0x40C];
    Vec_802B73AC a;
    Vec_802B73AC b;
};

struct Vec_802B4D5C { f32 x, y, z; };

struct Vec_802B57D4 { f32 x, y, z; };

struct Vec_802B4EAC { f32 x, y, z; };

struct Boss_802B4EAC {
    u8 pad0[0x38];
    Vec_802B4EAC pos;
    u8 pad44[0x420 - 0x44];
    Vec_802B4EAC target;
};

struct T1_802B600C;
struct Boss_802B8EE0 {
    u8 pad0[0x60];
    s32 f60;
};

struct Atk_802B8EE0 {
    s8 b0;
    u8 b1;
    s8 b2;
};

struct Boss_802B7B44 {
    u8 pad0[0x374];
    s32 f374;
    u8 pad378[0x4E8 - 0x378];
    f32 f4E8;
    s32 f4EC;
    s32 f4F0;
    s32 f4F4;
};

struct Vec_802B57D4;
struct Player_802B6B34;

struct V3_802B6C30 { s32 x; f32 y; s32 z; };

union Val_802B6C30 { f32 f; s32 i; };

struct Arg_802B6C30 { s32 kind; Val_802B6C30 v; };

struct Base_802B6C30 { u8 pad[0x18]; };

struct Player_802B6C30 : Base_802B6C30 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(void *, Arg_802B6C30 *, s32, s32, s32);
    u8 pad1c[0x38 - 0x1C];
    V3_802B6C30 pos;
};

struct ArgPair_802B6C30 {
    Arg_802B6C30 a[2];
    inline ArgPair_802B6C30(s32 r) {
        a[0].kind = 0;
        a[1].kind = 0;
        a[1].v.f = (f32)r;
        a[0].v.i = a[1].v.i;
    }
};

struct Vec_802B6C30 { f32 x, y, z; };

struct Line_802B6C30 { Vec_802B6C30 p; Vec_802B6C30 d; };

struct Boss_802B6C30 {
    u8 pad0[0x60];
    s32 angle;
    u8 pad64[0x484 - 0x64];
    s32 f484;
    u8 pad488[0x4DC - 0x488];
    f32 f4DC;
    u8 pad4E0[0x5A8 - 0x4E0];
    Vec_802B6C30 a;
    u8 pad5B4[0x5C0 - 0x5B4];
    Vec_802B6C30 b;
};

struct Anim_802B81A4 { s32 id; f32 t; s32 f8; f32 blend; f32 f10; s32 prevId; f32 prevT; };

struct Boss_802B81A4 {
    u8 pad0[0x3FC];
    s32 f3FC;
    u8 pad400[0x444 - 0x400];
    Anim_802B81A4 anim[2];
    u8 pad47C[0x650 - 0x47C];
    u32 f650[2];
};

struct Blend_802B81A4 { s32 ids[2]; f32 ts[2]; };
struct Motion_802B8384 { s32 f0; u32 frames; };

struct Anim_802B8384 {
    Motion_802B8384 *motion;
    f32 t;
    f32 speed;
    f32 blend;
    f32 rate;
    s32 f14;
    f32 f18;
};

struct Boss_802B8384 {
    u8 pad0[0x43C];
    s32 f43C;
    s32 f440;
    Anim_802B8384 anims[2];
};

struct V3_802B5AD4 { f32 x, y, z; };
struct Boss_802B5AD4 {
    u8 pad0[0x38];
    V3_802B5AD4 pos;
    u8 pad44[0x438 - 0x44];
    s32 f438;
};
void handle_6xA4_olga_flow_boss_actions(void *arg);
extern "C" {
u8 *get_enemy_entity(u16 arg0);
f32 vector_length(void *, f32);
f32 subtract_vector(void *, void *);
Player_802B6B34 *get_player_data__10TObjPlayerFi(s32);
f32 fabs_float(f32);
s32 get_entity_id(void *);
extern const Vec_802B57D4 TBoss6Type1__data_80470FB4;
extern const f32 TBoss6Type1__data_805DE2D0;
extern const f32 TBoss6Type1__data_805DE2E4;
extern const f32 TBoss6Type1__data_805DE310;
extern const f32 TBoss6Type1__data_805DE338;
extern const float TBoss6Type1__data_805DE344;
extern const f32 lbl_805DE330;
s32 TBoss6Type1__sub_802B5FDC(u8 *arg0);
s32 TBoss6Type1__sub_802B5FF4(u8 *arg0);
s32 TBoss6Type1__sub_802B600C(T1_802B600C *arg0, f32 _w1);
void randomize_attack__11TBoss6Type1FPvPv(Boss_802B8EE0 *self, Atk_802B8EE0 *atk);
void send_flow_action_if_idle__11TBoss6Type1FPvc(TBoss6Type1 *arg0, s8 arg1);
s32 rand();
extern u8 boss6_type1_random_action_table[];
extern const f32 TBoss6Type1__data_805DE304;
extern const f32 lbl_805DE3D8;
extern const f32 lbl_805DE3D4;
void TBoss6Type1__sub_802B8BB4(u8 *arg0);
s32 project_actor_to_ground(void *, void *, s32);
s32 is_active__14TBoss6PlotFalzFv();
void TBoss6PlotFalz__sub_802AC724(void *, void *);
f32 vec3_add_to(void *, void *);
void vec3_cross(void *, void *, void *);
void normalize_vector(void *);
f32 project_point_onto_line(void *, void *, void *);
f32 xyz_distance(void *, void *);
extern const f32 TBoss6Type1__data_805DE2E0;
extern const f32 lbl_805DE378;
extern const f32 lbl_805DE388;
extern const f32 lbl_805DE38C;
void TBoss6Type1__sub_802B6C30(Boss_802B6C30 *self);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
void clear_render_callback__8TObjFishFv(u32);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
extern s32 lbl_804DF614[];
extern const s32 lbl_805DE3C8;
extern s32 lbl_80470FAC[];

void TBoss6Type1__sub_802B4B04(u8 *arg0);
extern const f32 lbl_805DE314;
extern const f32 TBoss6Type1__data_805DE318;
extern const f32 lbl_805DE31C;
void TBoss6Type1__sub_802B5598(void *arg0, void *arg1);
extern const f32 lbl_805DE354;
extern const f32 lbl_805DE358;
s32 TBoss6Type1__sub_802B6060(u8 *arg0);
extern const f32 lbl_805DE300;
extern const f32 lbl_805DE34C;
extern const f32 lbl_805DE308;
extern RecoveredGlobal_802B5938_lbl_80470FFC lbl_80470FFC;
extern RecoveredGlobal_802B5938_lbl_80471008 lbl_80471008;
extern RecoveredGlobal_802B5970_lbl_80470FE4 lbl_80470FE4;
extern RecoveredGlobal_802B5970_lbl_80470FF0 lbl_80470FF0;
void TBoss6Type1__sub_802B5970(s32 arg0);
extern RecoveredGlobal_802B7E88_lbl_80470CEC TBoss6Type1__param_table;
extern const s32 lbl_805DE3A8;
extern const s32 lbl_805DE3B0;
void TBoss6Type1__sub_802B7D50(u8 *arg0);
extern RecoveredGlobal_802B5140_lbl_80470CD4 lbl_80470CD4;
extern RecoveredGlobal_802B5140_lbl_80470CE0 lbl_80470CE0;
extern const f32 lbl_805DE2F4;
extern const f32 lbl_805DE2F8;
extern const f32 lbl_805DE2FC;
void TBoss6Type1__sub_802B5140(s32 arg0, s32 arg1, s32 arg2);
extern const f32 lbl_805DE370;
extern const f32 lbl_805DE374;
void TBoss6Type1__sub_802B4CF4(s32 arg0);
void TBoss6Type1__sub_802B59A8(void);
void TBoss6Type1__sub_802B59CC(TBoss6Type1 *self);
void TBoss6Type1__sub_802B5AB0(void);
extern const f32 lbl_805DE348;
extern const s32 lbl_805DE2D4;
void TBoss6Type1__sub_802B4D38(Obj_802B4D38 *self);
extern const f32 lbl_805DE2F0;
extern const f32 lbl_805DE2EC;
Blk_802B8624 *copy_block__11TBoss6Type1FPvPv(Blk_802B8624 *d, Blk_802B8624 *s);
void TBoss6Type1__sub_802B5DD4(Obj_802B5DD4 *self);
void *create_particle_emitter(void *pos, s32 id);
extern Tbl_802B4BA8 TBoss6Type1__effect_slot_table[];
extern u8 lbl_80471014[];
s32 get_bml_motion(s32, s32);
extern Tbl_802B82B8 TBoss6Type1__motion_set_table[];
extern const s32 TBoss6Type1__data_805DE3C4;
extern const f32 lbl_805DE35C;
s32 TBoss6Type1__sub_802B909C(void *, s32 *);
extern const f32 lbl_805DE3DC;
void TBoss6Type1__sub_802B8E1C(T1_802B8E1C *arg0);
extern const f32 TBoss6Type1__data_805DE30C;
void clamp_to_arena_radius__11TBoss6Type1FPvPvf(Boss_802B54F0 *o, Vec_802B54F0 *out, f32 _w2);
extern const f32 lbl_805DE320;
extern const f32 lbl_805DE324;
void calc_grid_cell_position__11TBoss6Type1FPvPv(Boss_802B5648 *o, Vec_802B5648 *out);
void *get_player_by_client_id(s32 i);
extern const f32 TBoss6Type1__data_805DE32C;
extern const f32 TBoss6Type1__data_805DE360;
s32 matrix_mult_vec(int, void *, void *);
void set_matrix_identity(u8 *arg0);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
void post_translate_matrix(Vec *pos);
void rotate_matrix_x(int matrix, int angle);
void rotate_vector_by_matrix(int matrix, const Vec *in, Vec *out);
extern Tbl_802B79DC TBoss6Type1__part_position_sources[];
extern Entry_802B865C boss6_type1_action_table[];
s32 play_sound_effect(int, void *, int, int, void *);

u8 *fn_8035648C(s32 arg0, s32 arg1, s32 arg2, f32 farg0);
extern f32 TBoss6Type1__sword_shot_hit_radii[];
extern s32 game_difficulty_selection;
extern const f32 lbl_805DE394;
void TBoss6Type1__sub_802B73AC(Boss_802B73AC *self);
f32 atan2_float(f64, f64);
extern const f64 TBoss6Type1__data_80471038;
void request_follow_camera_offsets(void *, void *, int);
extern const Vec_802B57D4 lbl_80470FC0;
s32 angle_diff_s16(s32, s32);
extern const f32 lbl_805DE2DC;
extern const f32 lbl_805DE2E8;
extern const s8 lbl_805DE2C8[2];
extern const s8 lbl_805DE2CC[2];
extern const f32 lbl_805DE3E0;
extern const f32 lbl_805DE3E4;
extern const s32 lbl_805DE3AC;
extern const s32 lbl_805DE3B4;
extern const f32 lbl_805DE3B8;
int TBoss6Type1__sub_802B4A70(void* p);
void TBoss6Type1__sub_802B4A90(void *p);
void TBoss6Type1__sub_802B4B14(void* p);
void TBoss6Type1__sub_802B4A9C(void*);
struct Boss_802B5AD4;
void fire_at_all_players__11TBoss6Type1FPvf(Boss_802B5AD4 *, f32);

int release_object__11TBoss6Type1FPv(void*);

void TBoss6Type1::draw_model() {
    TObjPlayer::toggle_particle_effect();
    push_matrix();
    Vec pos = *&position;
    pos.y = pos.y + m_4e8;
    post_translate_matrix(&pos);
    rotate_matrix_y(0, rotation_y);
    rotate_matrix_x(0, rotation_x);
    TBoss6PlotFalz__sub_802AC008(m_4d4, m_4d8);
    draw_part_motions();
    TBoss6PlotFalz::update_camera_target();
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

void TBoss6Type1::render() {
    draw_model();
    TBoss6Type1__sub_802B626C(this);
}

void TBoss6Type1::release_object(void *) {
    if (map_csn != 0) {
        map_csn->queue_destruction();
        map_csn = 0;
    }
}

void TBoss6Type1::spawn_map_csn() {
    MapCsnSetData data;
    Vec offset;
    VecCopy(&data.position, &position);
    push_matrix();
    set_matrix_identity(0);
    rotate_matrix_y(0, rotation_y);
    rotate_vector_by_matrix(0, &boss6_map_csn_offset, &offset);
    data.position.x += offset.x;
    data.position.y = TBoss6Type1__data_805DE2D0;
    data.position.z += offset.z;
    pop_matrix();
    data.rotation_x = 0;
    data.rotation_y = rotation_y;
    data.rotation_z = 0;
    VecCopy(&data.scale, &boss6_map_csn_scale);
    data.params[0] = 2;
    data.params[1] = 0;
    map_csn = (TObject *)TObjMapCsn::create((s32)&data);
}

int TBoss6Type1__sub_802B4A70(void* p) { return release_object__11TBoss6Type1FPv(p); }
void TBoss6Type1__sub_802B4A90(void *p) { ((TBoss6Type1 *)p)->map_csn = 0; }

void TBoss6Type1__sub_802B4A9C(void *p) {
    TBoss6Type1 *boss = (TBoss6Type1 *)p;
    s32 i;
    boss->m_508 = 0;
    for (i = 0; i < lbl_805DE2D4; i++) {
        u32 slot = ((Obj_802B4B34 *)boss)->arr[i];
        if (slot != 0U) {
            TBoss4Type2::request_destroy(slot);
            ((Obj_802B4B34 *)boss)->arr[i] = 0;
        }
    }
}

void TBoss6Type1__sub_802B4B04(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x508) = (s32) (*(s32 *)((s8 *)arg0 + 0x508) + 1);
}

void TBoss6Type1__sub_802B4B14(void* p) { TBoss6Type1__sub_802B4A9C(p); }

void TBoss6Type1::clear_slot_array() {
    Obj_802B4B34 *self = (Obj_802B4B34 *)this;
    s32 i;
    this->m_508 = 0;
    for (i = 0; i < lbl_805DE2D4; i++) self->arr[i] = 0;
}

#pragma push
#pragma opt_common_subs off
void TBoss6Type1::release_effect_slot(s32 arg1) {
    s32 arg0 = (s32)this;
    u32 temp_r3;
    u8 *temp_r31;
    temp_r31 = (u8 *)(arg0 + (arg1 * 4));
    temp_r3 = *(u32 *)((s8 *)temp_r31 + 0x4F8);
    if (temp_r3 != 0U) {
        TBoss4Type2::request_destroy(temp_r3);
        *(u32 *)((s8 *)temp_r31 + 0x4F8) = 0U;
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma fp_contract on
typedef char RecoveredGlobal_802B5140_lbl_80470CD4_size[sizeof(RecoveredGlobal_802B5140_lbl_80470CD4) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_802B5140_lbl_80470CE0_size[sizeof(RecoveredGlobal_802B5140_lbl_80470CE0) == 0xC ? 1 : -1];

void TBoss6Type1::spawn_effect_slot(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    u8 *p = arg0 + arg1 * 4;
    if (*(u32 *)(p + 0x4F8) == 0U) {
        V3_802B4BA8 v = ((T1_802B4BA8 *)arg0)->pos;
        *(u32 *)(p + 0x4F8) = (u32)create_particle_emitter(&v, TBoss6Type1__effect_slot_table[arg1].a);
        if (*(u32 *)(p + 0x4F8) != 0U) {
            ((TBoss4Type2 *)(*(u32 *)(p + 0x4F8)))->set_flags(0x40);
        }
    }
}

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation on
void TBoss6Type1::sub_802B4C28() {
    Obj_802B4C28 *o = (Obj_802B4C28 *)this;
    s32 i;
    Tbl_802B4BA8 *t = TBoss6Type1__effect_slot_table;
    for (i = 0; i < 4; i++) {
        Vec_802B4C28 v = o->pos;
        Tbl_802B4BA8 *e = &t[i];
        if (o->parts[i] != 0) {
            s32 k = e->b;
            if (k >= 0) {
                VecCopy((Vec *)&v, (const Vec *)&o->pts[k]);
            }
            ((TNowLoading *)(o->parts[i]))->copy_pos(&v);
            switch (i) {
            case 0:
            case 1:
                ((TBoss4Type2 *)(o->parts[i]))->copy_vec3(lbl_80471014);
                break;
            }
        }
    }
}
#pragma pop

void TBoss6Type1__sub_802B4CF4(s32 arg0) {
    s32 var_r31;
    var_r31 = 0;
    do {
        ((TBoss6Type1 *)arg0)->release_effect_slot(var_r31);
        var_r31 += 1;
    } while (var_r31 < 4);
}

void TBoss6Type1__sub_802B4D38(Obj_802B4D38 *self) {
    s32 i;
    for (i = 0; i < 4; i++) self->arr[i] = 0;
}

void TBoss6Type1::rotate_around_center(s32 num, s32 den) {
    u8 *self = (u8 *)this;
    Vec_802B4D5C v;
    f32 dist;
    s32 angle;
    s32 off;
    if (den <= 0 || num <= 0) {
        return;
    }
    {
    {
        VecCopy((Vec *)&v, &this->position);
        v.y = TBoss6Type1__data_805DE2D0;
        dist = ((f32 (*)(void *))vector_length)(&v);
        angle = (s32)(TBoss6Type1__data_80471038 * atan2_float(v.x, v.z));
        off = (s32)(40960.0f * sin_table_lookup((s32)(32768.0f * ((f32)num / (f32)den))) / (f32)num);
        if (self[0x41C] & 1) {
            off *= -1;
        }
        angle += off;
        *(f32 *)(self + 0x38) = dist * sin_table_lookup(angle);
        *(f32 *)(self + 0x40) = dist * cos_table_lookup(angle);
        }
    }
}

#pragma push
#pragma fp_contract on
void TBoss6Type1::interpolate_pos_to_target(s32 step, s32 total) {
    Boss_802B4EAC *self = (Boss_802B4EAC *)this;
    Vec_802B4EAC v;
    s32 a0;
    s32 a1;
    f32 r0;
    f32 r1;
    f32 t;
    f32 k;
    f32 r;
    s32 a;
    if (total <= 0) return;
    if (step <= 0) {
        VecCopy((Vec *)&self->pos, (const Vec *)&self->target);
        return;
    }
    VecCopy((Vec *)&v, (const Vec *)&self->pos);
    v.y = TBoss6Type1__data_805DE2D0;
    r0 = ((f32 (*)(void *))vector_length)(&v);
    a0 = ((const f64 *)&TBoss6Type1__data_80471038)[0] * atan2_float(v.x, v.z);
    VecCopy((Vec *)&v, (const Vec *)&self->target);
    v.y = TBoss6Type1__data_805DE2D0;
    r1 = ((f32 (*)(void *))vector_length)(&v);
    a1 = ((const f64 *)&TBoss6Type1__data_80471038)[0] * atan2_float(v.x, v.z);
    t = (f32)step / (f32)total;
    if (total <= 10 || t <= TBoss6Type1__data_805DE2E0) {
        k = TBoss6Type1__data_805DE2E4 / (f32)step;
    } else {
        k = lbl_805DE2E8 * sin_table_lookup(lbl_805DE2DC * t) / (f32)step;
    }
    r = k * (r1 - r0) + r0;
    a = k * (f32)angle_diff_s16(a0, a1) + (f32)a0;
    self->pos.x = r * sin_table_lookup(a);
    self->pos.z = r * cos_table_lookup(a);
    self->pos.y += k * (self->target.y - self->pos.y);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TBoss6Type1::ease_toward_target(s32 a, s32 b) {
    Obj_802B5100 *self = (Obj_802B5100 *)this;
    s32 h = b / 2;
    if (b <= 0 || a <= h) return;
    self->f3c += lbl_805DE2EC * ((lbl_805DE2F0 + self->f424) - self->f3c);
}
#pragma pop

void TBoss6Type1__sub_802B5140(s32 arg0, s32 arg1, s32 arg2) {
    typedef char sp8_offset[(offsetof(Stack_802B5140, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802B5140, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_802B5140, sp10) == 0x8) ? 1 : -1];
    Stack_802B5140 stack;
    f32 temp_f31;
    f32 var_f30;
    f32 var_f31;
    s32 temp_r31;
    var_f30 = TBoss6Type1__data_805DE2E4 - ((f32) arg1 / (f32) arg2);
    if (var_f30 < TBoss6Type1__data_805DE2D0) {
        var_f30 = TBoss6Type1__data_805DE2D0;
    } else if (var_f30 > TBoss6Type1__data_805DE2E4) {
        var_f30 = TBoss6Type1__data_805DE2E4;
    }
    temp_r31 = (s32) (lbl_805DE2F4 * var_f30);
    temp_f31 = sin_table_lookup(0x6000);
    var_f31 = sin_table_lookup(temp_r31) / temp_f31;
    if (temp_r31 > 0x4000) {
        var_f31 += (TBoss6Type1__data_805DE2E4 - var_f31) * TBoss6PlotFalz::cosine_ease((var_f30 - lbl_805DE2F8) / lbl_805DE2FC);
    }
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(&lbl_80470CE0.value));
    subtract_vector(&stack.sp8, &lbl_80470CD4.value);
    stack.sp8 *= var_f31;
    stack.spC *= var_f31;
    stack.sp10 *= var_f31;
    vec3_add_to(&stack.sp8, &lbl_80470CD4.value);
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(&stack.sp8));
}
#pragma pop

s32 TBoss6Type1::count_matches(s32 arg1, s32 arg2) {
    T1_802B529C *arg0 = (T1_802B529C *)this;
    s32 i;
    s32 cnt;
    if (arg2 > 0x20) {
        arg2 = 0x20;
    }
    cnt = 0;
    for (i = 0; i < arg2; i++) {
        if (arg0->v[i] == arg1) {
            cnt++;
        }
    }
    return cnt;
}

s32 TBoss6Type1::pick_random_entry(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r0;
    var_r0 = (s32) (((f32) arg2 - lbl_805DE300) * ((*(const f32 *)&TBoss6Type1__data_805DE304) * (f32) rand()));
    if (var_r0 >= arg2) {
        var_r0 = 0;
    }
    return *(s32 *)((s8 *)arg1 + (var_r0 * 4));
}

#pragma push
#pragma fp_contract on
int TBoss6Type1::rand_range_inclusive(s32 arg0, int arg1, int arg2) {
    if (arg1 >= arg2) {
        return arg1;
    }
    return (int) (((lbl_805DE308 + ((f32) arg2 - (f32) arg1)) * ((*(const f32 *)&TBoss6Type1__data_805DE304) * (f32) rand())) + (f32) arg1);
}
#pragma pop

s32 TBoss6Type1::pick_remapped_list_value(s32 a, s32 b, s32 n) {
    Boss_802B5434 *o = (Boss_802B5434 *)this;
    s32 i;
    if (n > 0x20) {
        n = 0x20;
    }
    for (i = 0; i < n; i++) {
        s32 v = o->list[i];
        if (v == a) {
            return b;
        }
        if (v == b) {
            return a;
        }
    }
    if (TBoss6Type1__data_805DE304 * (f32)rand() < TBoss6Type1__data_805DE30C) {
        return a;
    }
    return b;
}

void clamp_to_arena_radius__11TBoss6Type1FPvPvf(Boss_802B54F0 *o, Vec_802B54F0 *out, f32 _w2) {
    Vec_802B54F0 v = o->pos;
    f32 len;
    f32 s;
    v.y = TBoss6Type1__data_805DE2D0;
    len = vector_length(&v, _w2);
    if (len <= TBoss6Type1__data_805DE310) {
        VecCopy((Vec *)(out), (const Vec *)(&o->pos));
        return;
    }
    s = lbl_805DE314 / len;
    v.x = v.x * s;
    v.z = v.z * s;
    out->x = v.x;
    out->y = TBoss6Type1__data_805DE318;
    out->z = v.z;
}

#pragma push
#pragma fp_contract on
void TBoss6Type1__sub_802B5598(void *arg0, void *arg1) {
    f32 var_f31;
    s32 temp_r31;
    s32 var_r4;
    u32 temp_r5;
    u32 var_r5;
    {
        s32 k = *(s32 *)((s8 *)arg0 + 0x374) * 0x12D687;
        s8 c = *(s8 *)((s8 *)arg0 + 0x41C);
        temp_r5 = c * k;
    }
    var_r4 = ((temp_r5 & 3) * 0x1800) + 0x2000;
    var_r5 = (temp_r5 >> 3U) & 1;
    if ((temp_r5 >> 2U) & 1) {
        var_r4 = -var_r4;
    }
    var_f31 = lbl_805DE314;
    temp_r31 = *(s32 *)((s8 *)arg0 + 0x60) + var_r4;
    if ((s32) var_r5 != 0) {
        var_f31 = lbl_805DE31C;
    }
    *(f32 *)((s8 *)arg1 + 0) = (var_f31 * sin_table_lookup(temp_r31));
    *(f32 *)((s8 *)arg1 + 4) = (f32) TBoss6Type1__data_805DE318;
    *(f32 *)((s8 *)arg1 + 8) = (f32) (var_f31 * cos_table_lookup(temp_r31));
}
#pragma pop

#pragma push
#pragma fp_contract on
void calc_grid_cell_position__11TBoss6Type1FPvPv(Boss_802B5648 *o, Vec_802B5648 *out) {
    u32 t = o->f374;
    s8 b = o->f41C;
    s32 sh = (t >> 1) & 3;
    s32 a = (b >> sh) & 0xF;
    s32 c = (b >> ((sh + 2) & 3)) & 0xF;
    if (t & 1) {
        a = ~a & 0xF;
        c = ~c & 0xF;
    }
    out->x = lbl_805DE320 * (f32)a - lbl_805DE324;
    out->y = o->f3C;
    out->z = lbl_805DE320 * (f32)c - lbl_805DE324;
}
#pragma pop

void TBoss6Type1::handle_6xa4_action(u8 * _w1) { ((TBoss6Type1 *)((char*)this + 0x1))->decode_polar_position(_w1); }

void TBoss6Type1::decode_polar_position(u8 *arg1) {
    u8 *arg0 = (u8 *)this;
  f32 temp_f31;
  f32 temp_f30;
  s32 temp_r31;
  temp_r31 = ((s8) (*((u8 *) (((s8 *) arg0) + 0)))) << 8;
  temp_f31 = (f32) (((s8) (*((u8 *) (((s8 *) arg0) + 1)))) * 0xA);
  temp_f30 = (f32) (((s8) (*((u8 *) (((s8 *) arg0) + 2)))) * 0xA);
  *((f32 *) (((s8 *) arg1) + 0)) = (f32) (temp_f31 * sin_table_lookup(temp_r31));
  *((f32 *) (((s8 *) arg1) + 8)) = (f32) (temp_f31 * cos_table_lookup(temp_r31));
  *((f32 *) (((s8 *) arg1) + 4)) = temp_f30;
}

typedef char RecoveredGlobal_802B5938_lbl_80470FFC_size[sizeof(RecoveredGlobal_802B5938_lbl_80470FFC) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_802B5938_lbl_80471008_size[sizeof(RecoveredGlobal_802B5938_lbl_80471008) == 0xC ? 1 : -1];

#pragma push
#pragma fp_contract on
s32 TBoss6Type1::request_jittered_camera(void *arg0, void *arg1, void *arg2, int arg3) {
    f32 dist;
    Vec_802B57D4 off;
    if (arg1 == NULL) {
        arg1 = (void *)&TBoss6Type1__data_80470FB4;
    }
    if (arg2 == NULL) {
        arg2 = (void *)&lbl_80470FC0;
    }
    dist = TBoss6Type1__data_805DE2E0 * xyz_distance(arg1, arg2);
    if (dist < 4.0f) {
        dist = 4.0f;
    }
    off.x = dist * (TBoss6Type1__data_805DE304 * (f32)rand() - TBoss6Type1__data_805DE30C);
    off.y = dist * (TBoss6Type1__data_805DE304 * (f32)rand() - TBoss6Type1__data_805DE30C);
    off.z = dist * (TBoss6Type1__data_805DE304 * (f32)rand() - TBoss6Type1__data_805DE30C);
    {
        Vec_802B57D4 p = *(Vec_802B57D4 *)arg1;
        vec3_add_to(&p, &off);
        request_follow_camera_offsets(&p, arg2, arg3);
    }
}
#pragma pop

void TBoss6Type1::request_default_jittered_camera() {
    s32 arg0 = (s32)this;
    TBoss6Type1::request_jittered_camera((void *)arg0, (void *)((void *)&lbl_80470FFC.value), (void *)((void *)&lbl_80471008.value), 0xFFFF);
}

typedef char RecoveredGlobal_802B5970_lbl_80470FE4_size[sizeof(RecoveredGlobal_802B5970_lbl_80470FE4) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_802B5970_lbl_80470FF0_size[sizeof(RecoveredGlobal_802B5970_lbl_80470FF0) == 0xC ? 1 : -1];
void TBoss6Type1__sub_802B5970(s32 arg0) {
    TBoss6Type1::request_jittered_camera((void *)arg0, (void *)((void *)&lbl_80470FE4.value), (void *)((void *)&lbl_80470FF0.value), 0xFFFF);
}

void TBoss6Type1__sub_802B59A8(void) {
    ((s32 (*)(f32))fire_at_all_players__11TBoss6Type1FPvf)(TBoss6Type1__data_805DE2D0);
}

extern const Vec_802B57D4 lbl_80470FCC;
extern const Vec_802B57D4 lbl_80470FD8;

#pragma push
#pragma fp_contract on
void TBoss6Type1__sub_802B59CC(TBoss6Type1 *self) {
    Vec_802B57D4 eye = TBoss6Type1__data_80470FB4;
    Vec_802B57D4 target = lbl_80470FC0;
    f32 t = *(f32 *)&self->unk_4DC;
    if (t > TBoss6Type1__data_805DE2D0) {
        eye.x += t * lbl_80470FCC.x;
        eye.y += t * lbl_80470FCC.y;
        eye.z += t * lbl_80470FCC.z;
        target.x += t * lbl_80470FD8.x;
        target.y += t * lbl_80470FD8.y;
        target.z += t * lbl_80470FD8.z;
    }
    TBoss6Type1::request_jittered_camera(self, &eye, &target, 0xFFFF);
}
#pragma pop

void TBoss6Type1__sub_802B5AB0(void) {
    ((s32 (*)(f32))fire_at_all_players__11TBoss6Type1FPvf)(TBoss6Type1__data_805DE32C);
}

#pragma push
#pragma fp_contract on
void fire_at_all_players__11TBoss6Type1FPvf(Boss_802B5AD4 *self, f32 dy) {
    V3_802B5AD4 me;
    V3_802B5AD4 pp;
    V3_802B5AD4 ofs;
    V3_802B5AD4 d;
    V3_802B5AD4 out;
    s32 n;
    s32 i;
    Player_802B6B34 *p;
    f32 h;
    f32 dist;
    f32 a;
    f32 b;
    f32 c;

    n = TLobby::get_game_mode();
    VecCopy((Vec *)&me, (const Vec *)&self->pos);
    if (self->f438 != 0) {
        me.y -= dy;
    } else {
        me.y += dy;
    }
    for (i = 0; i < n; i++) {
        p = get_player_data__10TObjPlayerFi(i);
        VecCopy((Vec *)&ofs, (const Vec *)&TBoss6Type1__data_80470FB4);
        if (p == 0) continue;
        VecCopy((Vec *)&pp, (const Vec *)((u8 *)p + 0x38));
        pp.y += ofs.y;
        VecCopy((Vec *)&d, (const Vec *)&me);
        subtract_vector(&d, &pp);
        h = d.y;
        d.y = 0.0f;
        dist = ofs.z + ((f32 (*)(void *))vector_length)(&d);
        if (dist <= 1.0f) dist = 1.0f;
        out.x = 0.0f;
        out.z = lbl_805DE330;
        out.y = 25.43f - h * lbl_805DE330 / dist;
        if (out.y < 5.0f) {
            out.y = 5.0f;
            if (h > 1e-5f) {
                a = 14.799999f * dist;
                out.z = a / h;
                if (out.z < 35.42f) {
                    b = 35.42f + dist;
                    out.z = 35.42f;
                    c = 35.42f * h - a;
                    if (fabs_float(b) > 1e-5f) {
                        a = c / b;
                        if (a > 10.0f) a = 10.0f;
                        ofs.y += a;
                    }
                }
            }
        }
        TBoss6Type1::request_jittered_camera(self, &ofs, &out, get_entity_id(p));
    }
}
#pragma pop

void TBoss6Type1::sub_802B5CB4() {
    switch (this->m_374) {
    case 1:
    case 2:
    case 4:
    case 24:
    case 25:
        TBoss6Type1__sub_802B5AB0();
        break;
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        TBoss6Type1__sub_802B5970((s32) this);
        break;
    case 22:
        TBoss6Type1__sub_802B59CC(this);
        break;
    case 21:
        TBoss6Type1__sub_802B59A8();
        break;
    case 26:
        TBoss6Type1__sub_802B5AB0();
        break;
    case 30:
    case 31:
        TBoss6Type1__sub_802B5970((s32) this);
        break;
    case 27:
        TBoss6Type1__sub_802B5970((s32) this);
        break;
    case 32:
        TBoss6Type1__sub_802B5970((s32) this);
        break;
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 34:
    case 35:
    case 36:
        this->request_default_jittered_camera();
        break;
    case 37:
        if (this->action_timer > (s32) ((f32) this->m_40c - lbl_805DE348)) {
            this->request_default_jittered_camera();
            break;
        }
        break;
    default:
        TBoss6Type1::request_jittered_camera((void *)((void *)((s32) this)), NULL, NULL, 0xFFFF);
        break;
    }
}

u8 TBoss6Type1::is_timer_expired() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    s32 temp_r5;
    temp_r5 = this->m_4e0;
    if ((temp_r5 <= 0) || (temp_r0 = *(s32 *)((s8 *)arg0 + 0x4E4), ((temp_r0 < 0) != 0))) {
        return 1U;
    }
    return (u8) (temp_r5 <= temp_r0);
}

void TBoss6Type1__sub_802B5DD4(Obj_802B5DD4 *self) {
    if (self->f4e0 <= 0 || self->f4e4 < 0) return;
    self->f4e4++;
}

void TBoss6Type1::reset_fields_4e0() { this->m_4e0 = 0; *(s32*)((char*)this + 0x4e4) = 0; }
s32 TBoss6Type1::is_field3F8_over_0x20() {
    return TBoss6PlotFalz__sub_802AAC74((u8 *)this->m_3f8) > 0x20;
}

int TBoss6Type1::is_field4b0_delta_reached() {
    Obj_802B5E48 *self = (Obj_802B5E48 *)this;
    return calc_field4b0_delta() >= self->f498 ? 1 : 0;
}

s32 TBoss6Type1::is_ready() {
    if (((s32) this->m_414 == 0) && (calc_field4b0_delta() >= (s32) this->m_48c)) {
        return 1;
    }
    return 0;
}

s32 TBoss6Type1::check_field4b0_threshold() {
    s32 temp_r31;
    temp_r31 = (s32) (this->m_4b4 * (f32) this->m_494);
    if (calc_field4b0_delta() >= temp_r31) {
        this->m_4b4 = (f32) (this->m_4b4 * lbl_805DE34C);
        return 1;
    }
    return 0;
}

int TBoss6Type1::is_time_up() {
    if ((s32) this->m_414 == 0) {
        return 0;
    }
    return calc_field4b0_delta() >= (s32) *(s32 *)&this->unk_490 ? 1 : 0;
}

extern f32 lbl_805DE350;

void TBoss6Type1::set_flag_on_threshold() {
    if (((s32) this->m_4ac == 0) && (this->m_4d8 < lbl_805DE350)) {
        this->m_4ac = 1;
    }
}

s32 TBoss6Type1__sub_802B5FDC(u8 *arg0) {
    return *(f32 *)((s8 *)arg0 + 0x3C) < lbl_805DE354;
}

s32 TBoss6Type1__sub_802B5FF4(u8 *arg0) {
    return *(f32 *)((s8 *)arg0 + 0x3C) > lbl_805DE358;
}

s32 TBoss6Type1__sub_802B600C(T1_802B600C *arg0, f32 _w1) {
    V3_802B600C v = arg0->pos;
    v.y = TBoss6Type1__data_805DE2D0;
    return vector_length(&v, _w1) < lbl_805DE35C;
}

s32 TBoss6Type1__sub_802B6060(u8 *arg0) {
    return *(f32 *)((s8 *)arg0 + 0x3C) > TBoss6Type1__data_805DE318;
}
}

void TBoss6Type1::set_part_default_value(int a0, void* a1) { *(float*)((char*)a1 + 0x4) = TBoss6Type1__data_805DE344; }
void draw_model_blend_motion(void *arg0, void *arg1, f32 farg0);

void TBoss6Type1::update_effect_points() {
    Boss6EffectPoint points[2];
    VecCopy((Vec *)&points[0], (const Vec *)&effect_points[0]);
    VecCopy((Vec *)&points[1], (const Vec *)&effect_points[1]);
    TBoss6Type1::set_part_default_value((int)this, &points[1]);
    ((TBoss6Type1 *)effect_point_receiver)->set_effect_points((f32 *)points, (u32 *)lbl_80470FAC);
}

 extern u32 boss6_type1_trail_point_offsets[];

void TBoss6Type1::update_trail_points() {
    Boss6EffectPoint points[7];
    Boss6EffectPoint delta;
    VecCopy((Vec *)&points[0], (const Vec *)&trail_points[0]);
    VecCopy((Vec *)&points[3], (const Vec *)&trail_points[1]);
    VecCopy((Vec *)&delta, (const Vec *)&trail_points[2]);
    subtract_vector(&delta,&points[3]);
    f32 length=((f32 (*)(const Boss6EffectPoint*))vector_length)(&delta);
    if(length <= TBoss6Type1__data_805DE310) length=TBoss6Type1__data_805DE2E4;
    f32 scale=TBoss6Type1__data_805DE360/length;
    delta.x*=scale;delta.y*=scale;delta.z*=scale;
    VecCopy((Vec *)&points[1], (const Vec *)&points[0]);
    VecCopy((Vec *)&points[5], (const Vec *)&points[0]);
    subtract_vector(&points[1],&delta);
    vec3_add_to(&points[5],&delta);
    VecCopy((Vec *)&points[2], (const Vec *)&points[1]);
    VecCopy((Vec *)&points[4], (const Vec *)&points[1]);
    subtract_vector(&points[2],&delta);
    vec3_add_to(&points[4],&delta);
    VecCopy((Vec *)&points[6], (const Vec *)&points[0]);
    ((TBoss6Type1 *)trail_point_receiver)->set_effect_points((f32 *)points, (u32 *)boss6_type1_trail_point_offsets);
}

void TBoss6Type1::init_parts() { TBoss6Type1::set_part_default_value((int)this, (void*)((char*)this + 0x5d8)); TBoss6Type1::set_part_default_value((int)this, (void*)((char*)this + 0x5e4)); TBoss6Type1::set_part_default_value((int)this, (void*)((char*)this + 0x5f0)); this->update_trail_points(); }

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_C_boss6_1 { u8 bytes[0xc]; };

struct Stack_802B7D74_boss6_1
{
  f32 sp8;
  f32 spC;
  f32 sp10;
};

#include <stddef.h>
#include "pso/boss/TBoss3Volopt.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
extern "C" TObjEnemy *__ct__9TObjEnemyFP7TObject(void *, void *);
struct Stack_802B9204_boss6_1 {
    s32 sp8;
    s8 spC;
    u8 trailing_storage[0xF];
};

extern "C" {
u8 * TBoss6Type1__sub_802B96C0(s32 arg0, s32 arg1);
s32 render_shadows__9TObjEnemyFv();
extern const f32 lbl_805DE3D0;
s32 angle_difference_abs(int, int);
s32 approach_angle_limited(int, int, int);
s32 TBoss6Type1__ct(s32, s32, s32);
s32 TObjControl__ct(s32, s32);
s32 __nw__7TObjectFUl(s32);

void TBoss6Type1::reset_param() {
    *(f32 *)&this->unk_4DC = (f32) TBoss6Type1__data_805DE2D0;
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TBoss6Type1::decrease_field_clamped_min() {
    *(f32 *)&this->unk_4DC = (f32) (*(f32 *)&this->unk_4DC + lbl_805DE370);
    if (*(f32 *)&this->unk_4DC < TBoss6Type1__data_805DE2D0) {
        *(f32 *)&this->unk_4DC = (f32) TBoss6Type1__data_805DE2D0;
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void TBoss6Type1::increase_field_clamped_max() {
    *(f32 *)&this->unk_4DC = (f32) (*(f32 *)&this->unk_4DC + lbl_805DE374);
    if (*(f32 *)&this->unk_4DC > TBoss6Type1__data_805DE2E4) {
        *(f32 *)&this->unk_4DC = (f32) TBoss6Type1__data_805DE2E4;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TBoss6Type1::spawn_grav_ball() {
    Vec_802B683C v;
    s32 flag;
    u8 *pl;
    s8 b;
    s32 ang;
    f32 r;
    flag = 1;
    pl = (u8 *)get_player_by_client_id(((Boss_802B683C *)this)->f41C & 3);
    if (is_active__14TBoss6PlotFalzFv() != 0) {
        VecCopy((Vec *)&v, (const Vec *)(pl + 0x38));
        flag = 0;
        v.y = ((Boss_802B683C *)this)->pos.y;
    }
    b = ((Boss_802B683C *)this)->f41C;
    if (b & 0x40) {
        flag = 1;
    }
    if (flag != 0) {
        ang = (b & 0xF) << 12;
        r = TBoss6Type1__data_805DE32C * ((f32)((b >> 3) & 0xF) / TBoss6Type1__data_805DE360) + (*(const f32 *)&TBoss6Type1__data_805DE344);
        VecCopy((Vec *)&v, (const Vec *)(&((Boss_802B683C *)this)->pos));
        v.x += r * sin_table_lookup(ang);
        v.z += r * cos_table_lookup(ang);
    }
    TBoss6Type1::create_grav_ball(this, &v);
}
#pragma pop

void TBoss6Type1::damage_players_in_range() {
    s32 n;
    s32 i;
    Player_802B6B34 *p;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        p = get_player_data__10TObjPlayerFi(i);
        if (is_active__14TBoss6PlotFalzFv() != 0) {
            V3_802B6B34 v = p->pos;
            v.y = TBoss6Type1__data_805DE2D0;
            if (!(((f32 (*)(void *))vector_length)(&v) > (*(const f32 *)&TBoss6Type1__data_805DE344))) {
                Arg_802B6B34 a[2];
                s32 r = TBoss6PlotFalz::rand_vary_count(((Boss_802B6B34 *)this)->f488, TBoss6Type1__data_805DE2E0);
                a[0].kind = 1;
                a[1].kind = 1;
                a[1].v.f = (f32)r;
                a[0].v.i = a[1].v.i;
                p->m21(this, a, 0, -1, -1);
            }
        }
    }
}

#define VLEN(p) ((f32 (*)(void *))vector_length)(p)
#pragma push
#pragma fp_contract on
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss6Type1__sub_802B6C30(Boss_802B6C30 *self) {
    s32 n;
    Vec_802B6C30 *p4;
    Vec_802B6C30 *p3;
    Vec_802B6C30 *p2;
    Vec_802B6C30 *p1;
    Vec_802B6C30 *pA;
    Vec_802B6C30 *pB;
    s32 i;
    Player_802B6C30 *pl;
    s32 inside;
    Vec_802B6C30 *a;
    Vec_802B6C30 *b;
    s32 j;
    f32 prev;
    f32 t;
    Vec_802B6C30 pts[5];
    Line_802B6C30 line;
    Vec_802B6C30 A;
    Vec_802B6C30 B;
    Vec_802B6C30 mid;
    Vec_802B6C30 off;
    Vec_802B6C30 e;
    Vec_802B6C30 f;
    Vec_802B6C30 c;
    Vec_802B6C30 m;
    Vec_802B6C30 d3;
    Vec_802B6C30 d0;
    Vec_802B6C30 q2;
    Vec_802B6C30 q1;
    if (0.0f == self->f4DC) {
        return;
    }
    n = TLobby::get_game_mode();
    b = &self->b;
    a = &self->a;
    if (xyz_distance(a, b) < TBoss6Type1__data_805DE344) {
        return;
    }
    VecCopy((Vec *)&mid, (const Vec *)a);
    vec3_add_to(&mid, b);
    mid.x *= 0.5f;
    mid.y *= 0.5f;
    mid.z *= 0.5f;
    pA = &A;
    pB = &B;
    p4 = &pts[4];
    p3 = &pts[3];
    p2 = &pts[2];
    p1 = &pts[1];
    A.x = self->f4DC * (a->x - mid.x) + mid.x;
    A.y = self->f4DC * (a->y - mid.y) + mid.y;
    A.z = self->f4DC * (a->z - mid.z) + mid.z;
    B.x = self->f4DC * (b->x - mid.x) + mid.x;
    B.y = self->f4DC * (b->y - mid.y) + mid.y;
    B.z = self->f4DC * (b->z - mid.z) + mid.z;
    for (i = 0; i < n; i++) {
        pl = ((Player_802B6C30 *)get_player_data__10TObjPlayerFi(i));
        if (is_active__14TBoss6PlotFalzFv() == 0) {
            continue;
        }
        inside = 1;
        VecCopy((Vec *)&pts[0], (const Vec *)((void *)VecCopy((Vec *)((Vec *)p3), (const Vec *)((void *)VecCopy((Vec *)((Vec *)p4), (const Vec *)((const Vec *)pA))))));
        VecCopy((Vec *)p1, (const Vec *)((void *)VecCopy((Vec *)((Vec *)p2), (const Vec *)((const Vec *)pB))));
        off.x = lbl_805DE388 * sin_table_lookup(self->angle);
        off.y = 0.0f;
        off.z = lbl_805DE388 * cos_table_lookup(self->angle);
        vec3_add_to(p2, &off);
        vec3_add_to(p3, &off);
        for (j = 0; j < 4; j++) {
            VecCopy((Vec *)&e, (const Vec *)&pts[j + 1]);
            subtract_vector(&e, &pts[j]);
            e.y = 0.0f;
            VecCopy((Vec *)&f, (const Vec *)&pl->pos);
            subtract_vector(&f, &pts[j]);
            e.y = 0.0f;
            vec3_cross(&e, &f, &c);
            if (j > 0 && ((prev < 0.0f && c.y >= 0.0f)
                          || (prev > 0.0f && c.y <= 0.0f))) {
                inside = 0;
                break;
            }
            prev = c.y;
        }
        if (inside == 0) {
            continue;
        }
        pl->m21(self, ArgPair_802B6C30(TBoss6PlotFalz::rand_vary_count(self->f484, TBoss6Type1__data_805DE2E0)).a, 0, -1, -1);
        VecCopy((Vec *)&d0, (const Vec *)pA);
        subtract_vector(&d0, pB);
        d0.y = 0.0f;
        VecCopy((Vec *)&d3, (const Vec *)&pl->pos);
        d3.y = 0.0f;
        line.p.x = 0.5f * (A.x + B.x);
        line.p.y = 0.0f;
        line.p.z = 0.5f * (A.z + B.z);
        line.d.x = -sin_table_lookup(self->angle);
        line.d.y = 0.0f;
        line.d.z = -cos_table_lookup(self->angle);
        t = project_point_onto_line(&d3, &line, NULL);
        t = 0.5f * VLEN(&d0) - t;
        if (t <= 0.0f) {
            continue;
        }
        VecCopy((Vec *)&m, (const Vec *)pA);
        subtract_vector(&m, pB);
        m.y = 0.0f;
        if (VLEN(&m) <= TBoss6Type1__data_805DE310) {
            continue;
        }
        normalize_vector(&m);
        m.x *= t;
        m.z *= t;
        VecCopy((Vec *)&q2, (const Vec *)pA);
        subtract_vector(&q2, &pl->pos);
        q2.y = 0.0f;
        VecCopy((Vec *)&q1, (const Vec *)pB);
        subtract_vector(&q1, &pl->pos);
        q1.y = 0.0f;
        t = VLEN(&q1);
        if (VLEN(&q2) > t) {
            m.x *= lbl_805DE38C;
            m.z *= lbl_805DE38C;
        }
        vec3_add_to(&m, &pl->pos);
        if (project_actor_to_ground(self, &m, 0) == 0) {
            m.y = 0.0f;
            if (VLEN(&m) <= TBoss6Type1__data_805DE310) {
                continue;
            }
            normalize_vector(&m);
            m.x *= lbl_805DE378;
            m.z *= lbl_805DE378;
        }
        TBoss6PlotFalz__sub_802AC724(pl, &m);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TBoss6Type1__sub_802B73AC(Boss_802B73AC *self) {
    Vec_802B73AC *a;
    Vec_802B73AC *b;
    s32 ok;
    s32 flag;
    Vec_802B73AC p;
    Vec_802B73AC d;
    f32 sc;
    f32 t;
    s32 idx;
    ((TBoss6Type1*)self)->update_trail_points();
    a = &self->a;
    b = &self->b;
    ok = 0;
    if ((b->y < a->y && b->y < TBoss6Type1__data_805DE2D0) || (b->y > a->y && b->y > TBoss6Type1__data_805DE2D0)) {
        ok = 1;
    }
    if (fabs_float(a->y) > lbl_805DE394 || fabs_float(b->y) > lbl_805DE394) {
        ok = 0;
    }
    if (ok != 0) {
        VecCopy((Vec *)&d, (const Vec *)b);
        subtract_vector(&d, a);
        if (d.y <= TBoss6Type1__data_805DE310) {
            t = TBoss6Type1__data_805DE2E4;
        } else {
            t = -a->y / d.y;
        }
        p.x = t * d.x + a->x;
        p.y = TBoss6Type1__data_805DE2D0;
        p.z = t * d.z + a->z;
        idx = game_difficulty_selection;
        if (idx < 0 || idx >= 4) {
            idx = 0;
        }
        sc = TBoss6Type1__sword_shot_hit_radii[idx];
        flag = 0;
        if ((self->f408 & 3) == 0) {
            flag = 1;
        }
        fn_8035648C((s32)self, (s32)&p, flag, sc);
        if (flag != 0) {
            ((s32 (*)(int, void *, int, int))play_sound_effect)(0x4003B210, &p, 0, 0);
            TBoss6PlotFalz::apply_radial_effect_to_players(&p, 0xC0, 0xF, TBoss6Type1__data_805DE318);
        }
    }
}
#pragma pop

struct ArgPair_802B7530 {
    Arg_802B6B34 a[2];
    inline ArgPair_802B7530(s32 r) {
        a[0].kind = 0;
        a[1].kind = 0;
        a[1].v.f = (f32)r;
        a[0].v.i = a[1].v.i;
    }
};
struct Vec_802B7530 { f32 x, y, z; };
struct W3_802B7530 { s32 x, y, z; };
struct Line_802B7530 { Vec_802B7530 p; Vec_802B7530 d; };
struct Boss_802B7530 {
    u8 pad0[0x3FC];
    s32 f3FC;
    u8 pad400[0x408 - 0x400];
    u32 f408;
    u8 pad40C[0x460 - 0x40C];
    u32 f460;
    f32 f464;
    f32 f468;
    u8 pad46C[0x47C - 0x46C];
    s32 f47C;
    u8 pad480[0x56C - 0x480];
    Vec_802B7530 f56C;
    u8 pad578[0x5D8 - 0x578];
    Vec_802B7530 a;
    Vec_802B7530 b;
};

f32 vec3_dot(void *, void *);
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
extern const f32 lbl_805DE398;
extern const f32 lbl_805DE39C;
extern const f32 lbl_805DE3A0;
#pragma push
#pragma fp_contract on
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss6Type1::update_beam_attack() {
    Boss_802B7530 *self = (Boss_802B7530 *)this;
    Line_802B7530 line;
    Vec_802B7530 v;
    Vec_802B7530 w;
    Vec_802B7530 out;
    Vec_802B7530 A;
    Vec_802B7530 B;
    f32 t = self->f464;
    u32 motion = self->f460;
    s32 n;
    s32 i;

    if (motion != get_bml_motion(self->f3FC, TBoss6Type1__motion_set_table[13].ids[1])) return;
    if (t < lbl_805DE398 || t > lbl_805DE39C) return;
    {
    f32 end = lbl_805DE398 + self->f468;
    if (t >= lbl_805DE398 && t < end) {
        ((s32 (*)(int, void *, int, int))play_sound_effect)(0x40039209, &self->b, 0, 0);
    }
    }
    ((TBoss6Type1 *)self)->init_parts();
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        Player_802B6B34 *p = get_player_data__10TObjPlayerFi(i);
        if (is_active__14TBoss6PlotFalzFv() != 0) {
            Vec_802B7530 *a = &self->a;
            VecCopy((Vec *)&v, (const Vec *)&p->pos);
            v.y = TBoss6Type1__data_805DE2D0;
            VecCopy((Vec *)&w, (const Vec *)&self->b);
            subtract_vector(&w, a);
            line.p.x = a->x;
            line.p.y = TBoss6Type1__data_805DE2D0;
            line.p.z = a->z;
            line.d.x = w.x;
            line.d.y = TBoss6Type1__data_805DE2D0;
            line.d.z = w.z;
            if (!(project_point_onto_line(&v, &line, &out) > TBoss6Type1__data_805DE360)) {
                A.x = line.p.x;
                A.y = line.p.z;
                B.x = line.p.x + line.d.x;
                B.z = line.p.z + line.d.z;
                subtract_vector(&A, &out);
                subtract_vector(&B, &out);
                A.y = TBoss6Type1__data_805DE2D0;
                B.y = TBoss6Type1__data_805DE2D0;
                if (!(vec3_dot(&A, &B) > TBoss6Type1__data_805DE2D0)) {
                    p->m21(self, ArgPair_802B7530(TBoss6PlotFalz::rand_vary_count(self->f47C, TBoss6Type1__data_805DE2E0)).a, 0, -1, -1);
                }
            }
        }
    }
    if (self->f408 & 1) return;
    W3_802B7530 c = *(W3_802B7530 *)&self->b;
    W3_802B7530 e;
    Vec_802B7530 dlt;
    f32 dist;
    *(f32 *)&c.y = TBoss6Type1__data_805DE2D0;
    dist = xyz_distance(&c, &self->f56C);
    if (!(dist < lbl_805DE3A0)) {
        f32 r = dist / lbl_805DE3A0;
        s32 cnt;
        f32 s;
        s32 j;
        e.x = c.x;
        e.y = c.y;
        e.z = c.z;
        cnt = (s32)(1.0f + r);
        if (cnt > 4) cnt = 4;
        s = 1.0f / (f32)cnt;
        VecCopy((Vec *)&dlt, (const Vec *)&self->f56C);
        subtract_vector(&dlt, &c);
        dlt.x *= s;
        dlt.y *= s;
        dlt.z *= s;
        for (j = 0; j < cnt; j++) {
            spawn_particle_effect_with_flags(&e, 0x212, 0x40);
            spawn_particle_effect_with_flags(&e, 0x213, 0x40);
            vec3_add_to(&e, &dlt);
        }
        VecCopy((Vec *)&self->f56C, (const Vec *)&c);
    }
    {
        ((s32 (*)(int, void *, int, int))play_sound_effect)(0x4003B00A, &c, 0, 0);
        TBoss6PlotFalz::apply_radial_effect_to_players(&c, 0xC0, 0xF, TBoss6Type1__data_805DE318);
    }
}
#pragma pop

void TBoss6Type1::enable_parts() {
    void *temp_r3;
    void *temp_r4;
    void *temp_r4_2;
    void *temp_r4_3;
    void *temp_r4_4;

    temp_r4 = this->m_a4;
    if (temp_r4 != NULL) {
        *(s32 *)((s8 *)temp_r4 + 0x70) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x70) | 1);
        temp_r4_2 = this->m_a4;
        *(s32 *)((s8 *)temp_r4_2 + 0x9C) = (s32) (*(s32 *)((s8 *)temp_r4_2 + 0x9C) | 1);
        temp_r4_3 = this->m_a4;
        *(s32 *)((s8 *)temp_r4_3 + 0xC8) = (s32) (*(s32 *)((s8 *)temp_r4_3 + 0xC8) | 1);
        temp_r4_4 = this->m_a4;
        *(s32 *)((s8 *)temp_r4_4 + 0xF4) = (s32) (*(s32 *)((s8 *)temp_r4_4 + 0xF4) | 1);
        temp_r3 = this->m_a4;
        *(s32 *)((s8 *)temp_r3 + 0x120) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x120) | 1);
    }
}

void TBoss6Type1::set_child_flags() {
    void *temp_r3;
    void *temp_r4;

    temp_r4 = this->m_a4;
    if (temp_r4 != NULL) {
        *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) | 1);
        temp_r3 = this->m_a4;
        *(s32 *)((s8 *)temp_r3 + 0x44) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x44) | 1);
    }
}

void TBoss6Type1::clear_part_flag_bit0() {
    T1_802B7944 *arg0 = (T1_802B7944 *)this;
    Ent_802B7944 *p = arg0->p;
    if (p != NULL) {
        Ent_802B7944 *end = (Ent_802B7944 *)((u8 *)p + 0x134);
        for (; p < end; p++) {
            p->f &= ~1;
        }
    }
}

void TBoss6Type1::update_parts_flags() {
    clear_part_flag_bit0();
    if (*(s32 *)&this->unk_418 & 1) {
        set_child_flags();
    }
    if (*(s32 *)&this->unk_418 & 2) {
        enable_parts();
    }
}

extern const f32 lbl_805DE3A4;

void TBoss6Type1::update_part_positions() {
    Boss_802B79DC *arg0 = (Boss_802B79DC *)this;
    Vec_802B79DC v;
    s32 i;
    Vec_802B79DC *base;
    Ent_802B79DC *e;
    if (this->m_a4 != NULL) {
        for (i = 0; i < 7; i++) {
            Tbl_802B79DC *t;
            e = &arg0->ents[i];
            t = &TBoss6Type1__part_position_sources[i];
            base = NULL;
            switch (t->kind) {
            case 1:
                base = arg0->a578;
                break;
            case 0:
                base = arg0->a5FC;
                break;
            }
            if (base == NULL) {
                return;
            }
            VecCopy((Vec *)&v, (const Vec *)&base[t->idx]);
            subtract_vector(&v, &arg0->pos);
            push_matrix();
            set_matrix_identity(0);
            rotate_matrix_y(0, -this->rotation_y);
            matrix_mult_vec(0, &v, e);
            pop_matrix();
            VecCopy((Vec *)&e->n, (const Vec *)e);
            vec3_add_to(&e->n, &arg0->pos);
        }
    }
}

void TBoss6Type1::update_position() {
    VecCopy((Vec *)&this->m_2fc, &this->position);
    if ((s32) this->m_438 != 0) {
        this->m_300 = (f32) (this->m_300 - lbl_805DE3A4);
        return;
    }
    this->m_300 = (f32) (this->m_300 - lbl_805DE3A0);
}

typedef struct Stack_802B7D74_boss6_1 Stack_802B7D74_boss6_1;

#pragma push
#pragma fp_contract on
void TBoss6Type1::update_sway() {
    Boss_802B7B44 *self = (Boss_802B7B44 *)this;
    f32 d;
    f32 target;
    s32 v;
    if (--self->f4F4 < 0) {
        self->f4F0 = (f32)lbl_805DE3AC * (TBoss6Type1__data_805DE304 * (f32)rand()) + (f32)lbl_805DE3A8;
        self->f4F4 = (f32)lbl_805DE3B4 * (TBoss6Type1__data_805DE304 * (f32)rand()) + (f32)lbl_805DE3B0;
    }
    target = 0.0f;
    switch (self->f374) {
    case 29:
    case 30:
    case 31:
    case 32:
    case 37:
        break;
    case 23:
        target = self->f4E8 - lbl_805DE3B8 * fabs_float(sin_table_lookup(self->f4EC));
        break;
    default:
        v = self->f4F0;
        if (self->f4E8 < 0.0f) {
            v = TBoss6Type1__data_805DE338 * (f32)v;
        }
        self->f4EC += v;
        target = TBoss6Type1__data_805DE360 * sin_table_lookup(self->f4EC);
        break;
    }
    d = 0.75f * (target - self->f4E8);
    if (d < -5.0f) {
        d = -5.0f;
    } else if (d > 5.0f) {
        d = 5.0f;
    }
    self->f4E8 += d;
}
#pragma pop

void TBoss6Type1__sub_802B7D50(u8 *arg0) {
    *(f32 *)((s8 *)arg0 + 0x4E8) = (f32) TBoss6Type1__data_805DE2D0;
    *(s32 *)((s8 *)arg0 + 0x4EC) = 0;
    *(s32 *)((s8 *)arg0 + 0x4F0) = (s32) lbl_805DE3A8;
    *(s32 *)((s8 *)arg0 + 0x4F4) = (s32) lbl_805DE3B0;
}

void TBoss6Type1::update_turn_to_center() {
    u8 *arg0 = (u8 *)this;
  Stack_802B7D74_boss6_1 stack;
  s32 var_r5;
  int new_var;
  f32 temp_f1;
  s32 var_r31;
  s32 var_r4;
  var_r31 = 0;
  if ((this->m_438) != 0)
  {
    var_r31 = 0x8000;
  }
  if (angle_difference_abs((int) (*((s32 *) (((s8 *) arg0) + 0x5C))), (int) var_r31) < 0x666)
  {
    *((s32 *) (((s8 *) arg0) + 0x5C)) = var_r31;
  }
  else
  {
    *((s32 *) (((s8 *) arg0) + 0x5C)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x5C))) + 0x666);
  }
  stack.sp8 = -(*((f32 *) (((s8 *) arg0) + 0x38)));
  temp_f1 = -(*((f32 *) (((s8 *) arg0) + 0x40)));
  stack.spC = (*(const f32 *)&TBoss6Type1__data_805DE2D0);
  stack.sp10 = temp_f1;
  if (!(vector_length(&stack.sp8, (f32) temp_f1) <= TBoss6Type1__data_805DE310))
  {
    var_r4 = (s32) (TBoss6Type1__data_80471038 * atan2_float((f64) stack.sp8, (f64) stack.sp10));
    if ((this->m_438) != 0)
    {
      var_r4 += 0x8000;
    }
    var_r5 = 0x1555;
    new_var = this->rotation_y;
    if ((this->m_414) == 0)
    {
      var_r5 = 0x1B4;
    }
    this->rotation_y = approach_angle_limited(new_var, (int) var_r4, (int) var_r5);
  }
}

s32 TBoss6Type1::calc_field4b0_delta() {
    return *(s32 *)&this->unk_4B0 - this->hp;
}

void TBoss6Type1::latch_phase_counter() {
    *(s32 *)&this->unk_4B0 = (s32) this->hp;
}

typedef char RecoveredGlobal_802B7E88_lbl_80470CEC_size[sizeof(RecoveredGlobal_802B7E88_lbl_80470CEC) == 0x30 ? 1 : -1];
void TBoss6Type1::load_params_from_table() {
    u8 *temp_r3;
    temp_r3 = (u8 *)(TLobby::dispatch_shared_handler_a(0x2B));
    this->m_47c = (s32) *(f32 *)((s8 *)temp_r3 + 0);
    if ((f32) this->m_47c <= TBoss6Type1__data_805DE2D0) {
        this->m_47c = (s32) *(s32 *)((s8 *)&TBoss6Type1__param_table.value + 0);
    }
    *(s32 *)&this->unk_480 = (s32) *(f32 *)((s8 *)temp_r3 + 8);
    if ((f32) *(s32 *)&this->unk_480 <= TBoss6Type1__data_805DE2D0) {
        *(s32 *)&this->unk_480 = (s32) *(s32 *)((s8 *)&TBoss6Type1__param_table.value + 4);
    }
    this->m_484 = (s32) *(f32 *)((s8 *)temp_r3 + 0xC);
    if ((f32) this->m_484 <= TBoss6Type1__data_805DE2D0) {
        this->m_484 = (s32) *(s32 *)((s8 *)&TBoss6Type1__param_table.value + 8);
    }
    *(s32 *)&this->unk_488 = (s32) *(f32 *)((s8 *)temp_r3 + 0x10);
    if ((f32) *(s32 *)&this->unk_488 <= TBoss6Type1__data_805DE2D0) {
        *(s32 *)&this->unk_488 = (s32) *(s32 *)((s8 *)&TBoss6Type1__param_table.value + 0xC);
    }
    this->m_4a4 = (s32) *(f32 *)((s8 *)temp_r3 + 0x14);
    if ((f32) this->m_4a4 <= TBoss6Type1__data_805DE2D0) {
        this->m_4a4 = (s32) *(s32 *)((s8 *)&TBoss6Type1__param_table.value + 0x28);
    }
    this->m_48c = (s32) *(s32 *)((s8 *)temp_r3 + 0x18);
    if ((s32) this->m_48c <= 0) {
        this->m_48c = (s32) *(s32 *)((s8 *)&TBoss6Type1__param_table.value + 0x10);
    }
    *(s32 *)&this->unk_490 = (s32) *(s32 *)((s8 *)temp_r3 + 0x1C);
    if ((s32) *(s32 *)&this->unk_490 <= 0) {
        *(s32 *)&this->unk_490 = (s32) *(s32 *)((s8 *)&TBoss6Type1__param_table.value + 0x14);
    }
    this->m_494 = (s32) *(s32 *)((s8 *)temp_r3 + 0x20);
    if ((s32) this->m_494 <= 0) {
        this->m_494 = (s32) *(s32 *)((s8 *)&TBoss6Type1__param_table.value + 0x18);
    }
    *(s32 *)&this->unk_498 = (s32) *(s32 *)((s8 *)temp_r3 + 0x24);
    if ((s32) *(s32 *)&this->unk_498 <= 0) {
        *(s32 *)&this->unk_498 = (s32) *(s32 *)((s8 *)&TBoss6Type1__param_table.value + 0x1C);
    }
    this->m_49c = (s32) *(s32 *)((s8 *)temp_r3 + 0x28);
    if ((s32) this->m_49c <= 0) {
        this->m_49c = (s32) *(s32 *)((s8 *)&TBoss6Type1__param_table.value + 0x20);
    }
    this->laser_fire_time = (s32) *(s32 *)((s8 *)temp_r3 + 0x2C);
    if (this->laser_fire_time <= 0) {
        this->laser_fire_time = (s32) *(s32 *)((s8 *)&TBoss6Type1__param_table.value + 0x24);
    }
    *(s32 *)&this->unk_4A8 = (s32) *(f32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x2F)) + 0x14);
    if ((f32) *(s32 *)&this->unk_4A8 <= TBoss6Type1__data_805DE2D0) {
        *(s32 *)&this->unk_4A8 = (s32) *(s32 *)((s8 *)&TBoss6Type1__param_table.value + 0x2C);
    }
}

#pragma opt_propagation off
void TBoss6Type1::draw_part_motions() {
    Boss_802B81A4 *arg0 = (Boss_802B81A4 *)this;
    Blend_802B81A4 b;
    s32 i;
    s32 id;
    s32 p;
    Anim_802B81A4 *a;
    u32 cb;
    TObjPlayer::set_global_flag();
    for (i = 0; i < 2; i++) {
        {
            s32 t = lbl_804DF614[i];
            id = t;
            p = TObjFish__sub_8001EDB0(arg0->f3FC, t);
        }
        id = get_bml_model(arg0->f3FC, id);
        cb = arg0->f650[i];
        a = &arg0->anim[i];
        if (cb != 0) {
            TObjFish::set_global_param(p);
            if (TBoss6Type1__data_805DE2D0 == a->blend) {
                ((TObjFish *)cb)->set_draw_callback_list();
                draw_model_motion((void *)id, (void *)a->id, a->t);
                clear_render_callback__8TObjFishFv(cb);
            } else {
                b.ids[0] = a->prevId;
                b.ts[0] = a->prevT;
                b.ids[1] = a->id;
                b.ts[1] = a->t;
                ((TObjFish *)cb)->set_draw_callback_list();
                draw_model_blend_motion((void *)id, &b, a->blend);
                clear_render_callback__8TObjFishFv(cb);
            }
        }
    }
    TObjPlayer::clear_global_state();
}

void TBoss6Type1::set_motion_set(s32 arg1) {
    Boss_802B82B8 *arg0 = (Boss_802B82B8 *)this;
    f32 z;
    s32 n;
    Tbl_802B82B8 *t;
    s32 i;
    Anim_802B82B8 *a;

    if (arg1 != -1 && arg1 != arg0->f43C) {
    arg0->f43C = arg1;
    z = TBoss6Type1__data_805DE2D0;
    n = TBoss6Type1__data_805DE3C4;
    t = &TBoss6Type1__motion_set_table[arg1];
    this->m_440 = t->f0;
    for (i = 0; i < n; i++) {
        a = &arg0->anim[i];
        s32 id = get_bml_motion(arg0->f3FC, t->ids[i]);
        a->blend = a->f10;
        a->prevId = a->id;
        a->prevT = a->t;
        a->id = id;
        a->t = z;
    }
    }
}

void TBoss6Type1::advance_animations() {
    Boss_802B8384 *self = (Boss_802B8384 *)this;
    s32 cur;
    s32 i;
    Anim_802B8384 *a;
    f32 len;
    f32 b;
    f32 lim;
    s32 n;
    cur = lbl_805DE3C8;
    n = TBoss6Type1__data_805DE3C4;
    for (i = 0; i < n; i++) {
        if (i == cur) continue;
        a = &self->anims[i];
        len = a->motion->frames;
        a->t += a->speed;
        if (a->t >= len) a->t -= len;
        if (TBoss6Type1__data_805DE2D0 != a->blend) {
            if ((a->blend += a->rate) >= TBoss6Type1__data_805DE2E4) a->blend = TBoss6Type1__data_805DE2D0;
        }
    }
    a = &self->anims[lbl_805DE3C8];
    len = a->motion->frames;
    a->t += a->speed;
    switch (this->m_440) {
    case 0:
        if (a->t >= len) a->t -= len;
        break;
    case 1:
        break;
    case 2:
        lim = len - TBoss6Type1__data_805DE2E4;
        if (a->t >= lim) {
            a->t = lim;
            set_motion_set(TBoss6Type1__motion_set_table[self->f43C].f4);
        }
        break;
    }
    if (TBoss6Type1__data_805DE2D0 != a->blend) {
        if ((a->blend += a->rate) >= TBoss6Type1__data_805DE2E4) a->blend = TBoss6Type1__data_805DE2D0;
    }
}

extern Blk_802B8624 lbl_80470ECC;
extern u8 lbl_80470F0C[];

void TBoss6Type1__sub_802B854C(void *p) {
    Boss_802B82B8 *self = (Boss_802B82B8 *)p;
    s32 i;
    Anim_802B82B8 *a;
    copy_block__11TBoss6Type1FPvPv((Blk_802B8624 *)&self->f43C, &lbl_80470ECC);
    for (i = 0; i < TBoss6Type1__data_805DE3C4; i++) {
        a = &self->anim[i];
        ((TBoss6Type1 *)a)->copy_transform(lbl_80470F0C);
        a->id = a->prevId = get_bml_motion(self->f3FC, TBoss6Type1__motion_set_table[2].ids[i]);
    }
}

void TBoss6Type1::copy_transform(void* q) { *(u32 *)&this->m_name = *(u32*)((char*)q + 0x0); (*(f32 *)&this->m_flags) = *(f32*)((char*)q + 0x4); *(f32 *)&this->m_prev = *(f32*)((char*)q + 0x8); (*(f32 *)&this->m_next) = *(f32*)((char*)q + 0xc); *(f32 *)&this->m_up = *(f32*)((char*)q + 0x10); (*(u32 *)&this->m_down) = *(u32*)((char*)q + 0x14); *(f32*)((char*)this + 0x18) = *(f32*)((char*)q + 0x18); }

Blk_802B8624 *copy_block__11TBoss6Type1FPvPv(Blk_802B8624 *d, Blk_802B8624 *s) {
    *d = *s;
    return d;
}
}
void build_6xA4_olga_flow_boss_actions(void* p);
void TBoss6Type1::set_action_state(s32 arg1) {
    Action_802B865C a;
    Entry_802B865C *e;
    s32 i;
    ((Boss_802B865C *)this)->state = arg1;
    for (i = 31; i > 0; i--) {
        ((Boss_802B865C *)this)->hist[i] = ((Boss_802B865C *)this)->hist[i - 1];
    }
    ((Boss_802B865C *)this)->hist[0] = ((Boss_802B865C *)this)->state;
    switch (((Boss_802B865C *)this)->state) {
    case 24:
        ((Boss_802B865C *)this)->f4B8++;
        break;
    case 26:
        ((Boss_802B865C *)this)->f4BC++;
        ((Boss_802B865C *)this)->f4C0++;
        break;
    case 34:
        ((Boss_802B865C *)this)->f4BC++;
        ((Boss_802B865C *)this)->f4C4++;
        break;
    }
    e = &boss6_type1_action_table[((Boss_802B865C *)this)->state];
    ((TBoss6Type1 *)((Boss_802B865C *)this))->set_motion_set(e->anim);
    ((Boss_802B865C *)this)->f418 = e->f8;
    a.words[0] = e->act[0];
    a.words[1] = e->act[1];
    a.words[2] = e->act[2];
    if (a.action != 0) {
        (((Boss_802B865C *)this)->*a.action)();
    }
}

extern "C" {
s32 submit_cursor_candidate(void *, int);
s32 add_radar_scaled_marker(void *, int, int, int, f32);
}
extern const f32 lbl_805DE3CC;

void TBoss6Type1::run_task() {
    Action_802B865C a;
    a.words[0] = boss6_type1_action_table[this->m_374].update[0];
    a.words[1] = boss6_type1_action_table[this->m_374].update[1];
    a.words[2] = boss6_type1_action_table[this->m_374].update[2];
    if (a.action != 0) {
        (((Boss_802B865C *)this)->*a.action)();
    }
    if (((TBoss6Type1 *)this->m_3f8)->is_idle() != 0) {
        a.words[0] = boss6_type1_action_table[this->m_374].idle[0];
        a.words[1] = boss6_type1_action_table[this->m_374].idle[1];
        a.words[2] = boss6_type1_action_table[this->m_374].idle[2];
        if (a.action != 0) {
            (((Boss_802B865C *)this)->*a.action)();
        }
    }
    advance_animations();
    update_turn_to_center();
    update_position();
    update_part_positions();
    update_parts_flags();
    ((TObjPlayer *)this)->update_collisions();
    submit_cursor_candidate(this, -1);
    add_radar_scaled_marker((u8 *)this + 0x584, -0x5DB4, 1, 1, TBoss6Type1__data_805DE338);
    sub_802B5CB4();
    this->m_4d4 += lbl_805DE3CC;
    if (this->m_4d4 < 0.0f) {
        this->m_4d4 = 0.0f;
    }
    this->m_4d8 = (f32)this->hp / (f32)this->referenceHp;
    ((TBoss6PlotFalz *)((u8 *)this + 0x658))->scroll_strips_uv(8, 0);
    ((TBoss6PlotFalz *)((u8 *)this + 0x66C))->scroll_strips_uv(0, 0x22);
    update_sway();
    sub_802B4C28();
    *(s32 *)((u8 *)this + 0x408) += 1;
}

void TBoss6Type1::render_shadows() {
    if (this->position.y >= lbl_805DE3D0) {
        render_shadows__9TObjEnemyFv();
    }
}

void TBoss6Type1::vfunc_63() { if (*(int *)&this->m_374 != 40) { set_action_state((s32)((void*)40)); } }

void TBoss6Type1::vfunc_62() {
    this->actorFlags = (s32) (this->actorFlags & 0xFFFFFDFF);
    this->m_4d4 = (f32) TBoss6Type1__data_805DE2E4;
    play_sound_effect(0x39E01, ((u8 *)this) + 0x584, 0, 1, this);
}

/* 6xA4: the Olga Flow boss action sent by send_6xA4_action. */
struct OlgaFlowActionMsg {
    u8 command;
    u8 size;
    u16 entity_id;
    s8 action;
    u8 action_args[3];
    u8 sync_params[3];
};

void handle_6xA4_olga_flow_boss_actions(void *arg) {
    OlgaFlowActionMsg *msg = (OlgaFlowActionMsg *)arg;
    TBoss6Type1 *boss;
    s32 action;

    ((TBoss6Type1 *)msg)->read_be16_field2();
    boss = (TBoss6Type1 *)get_enemy_entity(msg->entity_id);
    if (boss == NULL) {
        return;
    }
    ((TBoss6Type1 *)&msg->action)->handle_6xa4_action((u8 *)boss + 0x420);
    boss->load_params(msg);
    action = msg->action;
    if (action < 0 || action >= 41) {
        return;
    }
    boss->set_action_state(action);
}

struct T1_802B529C;
struct Boss_802B5434;
struct Boss_802B8EE0;
extern "C" {
#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
#pragma opt_lifetimes off
void TBoss6Type1__sub_802B8A70(TBoss6Type1 *self) {
    Atk_802B8EE0 atk;
    s8 v;
    f32 ratio;
    s32 total;
    v = ((u32)self->rotation_y >> 8) & 0xFF;
    v = lbl_805DE3D4 * (TBoss6Type1__data_805DE304 * (f32)rand() - TBoss6Type1__data_805DE30C) + v;
    ratio = TBoss6Type1__data_805DE30C;
    atk.b1 = 0x1C;
    atk.b0 = v;
    total = ((Boss_802B865C *)self)->f4C0 + ((Boss_802B865C *)self)->f4C4;
    if (total > 0) {
        ratio = (f32)((Boss_802B865C *)self)->f4C0 / (f32)total;
    }
    v = 20;
    if (TBoss6Type1__data_805DE304 * (f32)rand() < ratio) {
        v = -5;
    }
    atk.b2 = v;
    self->m_438 = 1;
    self->send_6xA4_action(0x18, (s32 *)&atk);
}
#pragma pop

void TBoss6Type1__sub_802B8BB4(u8 *arg0) {
    Atk_802B8EE0 s;
    s32 r4;
    s32 n;
    s32 id;
    switch (((TBoss6Type1 *)arg0)->m_414) {
    case 0:
        if (((s32 (*)(void *))TBoss6Type1__sub_802B600C)(arg0) != 0) {
            ((void (*)(u8 *, s32))send_flow_action_if_idle__11TBoss6Type1FPvc)(arg0, TBoss6Type1::rand_range_inclusive((s32)arg0, 5, 6));
            break;
        }
        switch (((TBoss6Type1 *)arg0)->pick_remapped_list_value(3, 5, 0x20)) {
        case 3:
            send_flow_action_if_idle__11TBoss6Type1FPvc((TBoss6Type1 *)arg0, (s8)(3));
            return;
        case 5:
            ((void (*)(u8 *, s32))send_flow_action_if_idle__11TBoss6Type1FPvc)(arg0, TBoss6Type1::rand_range_inclusive((s32)arg0, 5, 6));
            return;
        case 4:
            return;
        }
        break;
    case 1:
        randomize_attack__11TBoss6Type1FPvPv((Boss_802B8EE0 *)arg0, &s);
        if (TBoss6Type1__sub_802B5FDC(arg0) != 0) {
            id = 0x15;
            n = ((TBoss6Type1 *)arg0)->count_matches(0x15, 8);
            if (n == 0 || TBoss6Type1__data_805DE304 * (f32)rand() < lbl_805DE3D8 / (f32)n) {
                s.b2 = -2;
            } else {
                id = 2;
            }
            ((TBoss6Type1 *)arg0)->send_6xA4_action(id, (s32 *)&s);
            break;
        }
        if (TBoss6Type1__sub_802B5FF4(arg0) != 0) {
            ((TBoss6Type1 *)arg0)->send_6xA4_action(4, (s32 *)&s);
            break;
        }
        r4 = TBoss6Type1::pick_random_entry((s32)arg0, (s32)boss6_type1_random_action_table, 5);
        switch (r4) {
        case 4:
            if (s.b2 == -2) {
                r4 = 2;
            } else {
                s.b1 = 0x1C;
            }
            break;
        case 22:
            s.b2 = 10;
            break;
        case 5:
            s.b2 = 10;
            r4 = TBoss6Type1::rand_range_inclusive((s32)arg0, 6, 7);
            break;
        case 8:
            s.b2 = 10;
            r4 = TBoss6Type1::rand_range_inclusive((s32)arg0, 8, 10);
            break;
        }
        ((TBoss6Type1 *)arg0)->send_6xA4_action(r4, (s32 *)&s);
        break;
    }
}

void TBoss6Type1__sub_802B8E1C(T1_802B8E1C *arg0) {
    S_802B8E1C s;
    s32 r4;
    TBoss6Type1__sub_802B909C(arg0, (s32 *)((s32 *)&s));
    s.b = 0x1C;
    r4 = 0x21;
    arg0->f438 = 1;
    if (arg0->y < lbl_805DE3DC) {
        r4 = 0x26;
    }
    ((TBoss6Type1 *)arg0)->send_6xA4_action(r4, (s32 *)((s32 *)&s));
}

void TBoss6Type1::do_attack() {
    s32 sp8;

    if ((s32) this->m_414 == 0) {
        TBoss6Type1__sub_802B909C(this, &sp8);
    } else {
        randomize_attack__11TBoss6Type1FPvPv((Boss_802B8EE0 *)(this), (Atk_802B8EE0 *)(&sp8));
    }
    this->m_438 = 1;
    send_6xA4_action(2, &sp8);
}

#pragma push
#pragma fp_contract on
void randomize_attack__11TBoss6Type1FPvPv(Boss_802B8EE0 *self, Atk_802B8EE0 *atk) {
    const s8 *tab;
    s8 base;
    s8 v;
    f32 r;
    s8 w;
    s8 u;
    TBoss6Type1__sub_802B909C(self, (s32 *)atk);
    base = (u8)((u32)self->f60 >> 8);
    v = TBoss6Type1__data_805DE32C * (TBoss6Type1__data_805DE304 * (f32)rand()) + lbl_805DE3E0;
    if (TBoss6Type1__data_805DE304 * (f32)rand() < TBoss6Type1__data_805DE30C) {
        v = -v;
    }
    atk->b0 = base + v;
    if ((s32)atk->b1 == 0x12 && ((s32 (*)(void *))TBoss6Type1__sub_802B600C)(self) == 0) return;
    atk->b1 = 0x1C;
    if (TBoss6Type1__sub_802B5FF4((u8 *)self) != 0) {
        r = TBoss6Type1__data_805DE304 * (f32)rand();
        w = 0x12;
        if (r < TBoss6Type1__data_805DE2E0) {
            w = -2;
        } else if (r < lbl_805DE3E4) {
            w = 10;
        }
        atk->b2 = w;
        return;
    }
    tab = TBoss6Type1__sub_802B5FDC((u8 *)self) != 0 ? lbl_805DE2C8 : lbl_805DE2CC;
    u = tab[0];
    if (TBoss6Type1__data_805DE304 * (f32)rand() < TBoss6Type1__data_805DE30C) {
        u = tab[1];
    }
    atk->b2 = u;
}
#pragma pop

s32 TBoss6Type1::send_6xA4_action(s32 t, s32 *src) {
    Msg_802B9178 m;
    u8 *s;
    s32 i;
    if (((TBoss6Type1 *)(this->m_3f8))->is_idle() != 0) {
        build_6xA4_olga_flow_boss_actions(&m);
        set_sync_data(&m);
        m.b[4] = t;
        s = (u8 *)src;
        for (i = 1; i < 4; i++) {
            m.b[i + 4] = *s++;
        }
        ((TBoss6Type1 *)(&m))->step_and_send_60();
    }
}

void send_flow_action_if_idle__11TBoss6Type1FPvc(TBoss6Type1 *boss6_type1, s8 arg1) {
    typedef char sp8_offset[(offsetof(Stack_802B9204_boss6_1, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802B9204_boss6_1, spC) == 0x4) ? 1 : -1];
    Stack_802B9204_boss6_1 stack;
    if (((s32)((TBoss6Type1 *)(boss6_type1->m_3f8))->is_idle()) != 0) {
        build_6xA4_olga_flow_boss_actions(&stack.sp8);
        boss6_type1->set_sync_data(&stack.sp8);
        stack.spC = arg1;
        ((TBoss6Type1 *)(&stack.sp8))->step_and_send_60();
    }
}

void TBoss6Type1::load_params(void *arg1) {
    this->m_438 = (s32) (s8) *(u8 *)((s8 *)arg1 + 8);
    this->m_414 = (s32) (s8) *(u8 *)((s8 *)arg1 + 9);
    this->m_41c = (u8) *(u8 *)((s8 *)arg1 + 0xA);
}

extern f32 lbl_805DE3EC;

void TBoss6Type1::set_sync_data(void *arg1) {
    *(u16 *)((s8 *)arg1 + 2) = (u16) this->entity_id;
    *(s8 *)((s8 *)arg1 + 8) = (s8) this->m_438;
    *(s8 *)((s8 *)arg1 + 9) = (s8) this->m_414;
    *(s8 *)((s8 *)arg1 + 0xA) = (s8) (lbl_805DE3EC * (TBoss6Type1__data_805DE304 * (f32) rand()));
}


extern s32 tl_04;

struct VBase_18_f05d67 { char pad[0x18]; };
struct VObj_18_f05d67 : VBase_18_f05d67 {
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
    virtual s32 m79(void *);
};

struct Arr_802B93C4 { u8 pad[0x378]; s32 arr[32]; };
struct Tmp_802B93C4 { s32 a; s16 b; s16 c; u8 pad[0x10]; };

s32 TObjFish__sub_800E3124(u8 *list, s32 vecs);
s32 init_collision_body_parts(void *, void *, int);
void build_tables__14TBoss6PlotFalzFPvPvi(void *, void *, int);
void TBoss6Type1__sub_802B854C(void *);
s32 create_zanzo__11TBoss6Type1FPvPvPv(void *, int, int);
extern u8 lbl_80470D1C[];
extern u8 boss6_type1_model_node_desc[];
extern u8 boss6_type1_model_node_desc_b[];
extern u8 boss6_type1_build_table[];
extern u8 lbl_80470EA0[];
extern u8 lbl_80470EAC[];
extern u8 lbl_804DF4E0[];
extern u8 __vt__11TBoss6Type1[];
extern s32 lbl_805D3EB0;

#define arg0 ((u8 *)arg0_)
#define arg2 ((s32 *)arg2_)

#pragma push
#pragma opt_common_subs off
s32 TBoss6Type1__ct(s32 arg0_, s32 parent, s32 arg2_) {
    Tmp_802B93C4 tmp;
    s32 i;

    __ct__9TObjEnemyFP7TObject(arg0, (void*)parent);
    *(u8 **)((s8 *)arg0 + 0x18) = __vt__11TBoss6Type1;
    *(s32 *)((s8 *)arg0 + 0) = lbl_805D3EB0;
    ((TUnk_804806E8 *)arg0)->add_flags_2e4(8);
    *(s32 *)((s8 *)arg0 + 0x3F8) = arg2[0];
    ((VObj_18_f05d67 *)(arg0))->m79(arg2 + 1);
    if (((TObjEnemy *)arg0)->exchange_object_state((s32)&tmp, (s16)1) != 0) {
        tmp.a = 0;
        tmp.c = 0;
        ((TObjEnemy *)arg0)->exchange_object_state((s32)&tmp, (s16)0);
    }
    *(s32 *)((s8 *)arg0 + 0x3FC) = TObjFish::get_fish_count();
    *(s32 *)((s8 *)arg0 + 0x24) = 0;
    *(s32 *)((s8 *)arg0 + 0x34) = 0;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)&lbl_80470CD4);
    ((TObjPlayer *)(arg0 + 0x5C))->copy_xyz(lbl_80470D1C);
    VecCopy((Vec *)(arg0 + 0x44), (const Vec *)((void *)VecCopy((Vec *)(arg0 + 0x50), (const Vec *)((void *)VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38))))));
    init_collision_body_parts(arg0, lbl_804DF4E0, 7);
    ((TBoss6Type1 *)arg0)->update_position();
    *(f32 *)((s8 *)arg0 + 0x310) = TBoss6Type1__data_805DE2D0;
    *(f32 *)((s8 *)arg0 + 0x30C) = TBoss6Type1__data_805DE2D0;
    *(f32 *)((s8 *)arg0 + 0x308) = TBoss6Type1__data_805DE2D0;
    *(s32 *)((s8 *)arg0 + 0x2A8) = 0;
    ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)(TLobby::register_boss(0x2B)), (u8 *)(TLobby::dispatch_shared_handler_b(0x2B)), (u8 *)(TLobby::register_object(0x2B)));
    *(s16 *)((s8 *)arg0 + 0x33E) = *(s16 *)((s8 *)arg0 + 0x32C);
    ((TBoss3Volopt *)arg0)->reset_photon_effect();
    ((TObjEnemy *)arg0)->set_param(0x4E);
    TBoss6Type1__sub_802B854C(arg0);
    *(s32 *)((s8 *)arg0 + 0x654) = TObjFish__sub_800E3124((u8 *)boss6_type1_model_node_desc, (s32)(arg0 + 0x578));
    *(s32 *)((s8 *)arg0 + 0x650) = TObjFish__sub_800E3124((u8 *)boss6_type1_model_node_desc_b, (s32)(arg0 + 0x5FC));
    build_tables__14TBoss6PlotFalzFPvPvi(arg0 + 0x658, boss6_type1_build_table, 2);
    build_tables__14TBoss6PlotFalzFPvPvi(arg0 + 0x66C, lbl_80470EA0, 1);
    *(s32 *)((s8 *)arg0 + 0x400) = create_zanzo__11TBoss6Type1FPvPvPv(arg0, 7, 0xF);
    *(s32 *)((s8 *)arg0 + 0x404) = create_zanzo__11TBoss6Type1FPvPvPv(arg0, 2, 0xF);
    *(s32 *)((s8 *)arg0 + 0x414) = 0;
    *(s8 *)((s8 *)arg0 + 0x41C) = 0;
    TBoss6Type1__sub_802B96C0((s32)(arg0 + 0x420), (s32)lbl_80470EAC);
    VecCopy((Vec *)(arg0 + 0x420), (const Vec *)(arg0 + 0x38));
    TBoss6Type1__sub_802B96C0((s32)(arg0 + 0x42C), (s32)lbl_80470EAC);
    *(s32 *)((s8 *)arg0 + 0x438) = 1;
    *(s32 *)((s8 *)arg0 + 0x418) = 0;
    for (i = 0; i < 32; i++) {
        ((Arr_802B93C4 *)arg0)->arr[i] = 0;
    }
    ((TBoss6Type1 *)arg0)->load_params_from_table();
    *(s32 *)((s8 *)arg0 + 0x4AC) = 0;
    *(f32 *)((s8 *)arg0 + 0x4B4) = TBoss6Type1__data_805DE2E4;
    ((TBoss6Type1 *)arg0)->latch_phase_counter();
    *(s32 *)((s8 *)arg0 + 0x4B8) = 0;
    *(s32 *)((s8 *)arg0 + 0x4BC) = 0;
    *(s32 *)((s8 *)arg0 + 0x4C0) = 0;
    *(s32 *)((s8 *)arg0 + 0x4C4) = 0;
    *(f32 *)((s8 *)arg0 + 0x4D4) = TBoss6Type1__data_805DE2D0;
    *(f32 *)((s8 *)arg0 + 0x4D8) = TBoss6Type1__data_805DE2E4;
    ((TBoss6Type1 *)arg0)->reset_fields_4e0();
    ((TBoss6Type1 *)arg0)->reset_param();
    TBoss6Type1__sub_802B7D50(arg0);
    *(s32 *)((s8 *)arg0 + 0x408) = 0;
    TBoss6Type1__sub_802B4D38((Obj_802B4D38 *)arg0);
    ((TBoss6Type1 *)arg0)->clear_slot_array();
    TBoss6Type1__sub_802B4A90(arg0);
    VecCopy((Vec *)(arg0 + 0x56C), (const Vec *)(arg0 + 0x38));
    ((TBoss6Type1 *)arg0)->set_action_state(0);
    return arg0_;
}
#pragma pop
#undef arg2
#undef arg0

u8 * TBoss6Type1__sub_802B96C0(s32 arg0, s32 arg1) {
    *(ByteBlock_C_boss6_1 *)(arg0) = *(const ByteBlock_C_boss6_1 *)(arg1);
    return (u8 *)arg0;
}
}

s32 TBoss6Type1::create(s32 arg2_) {
    s32 arg0_;
    s32 var_r4;

    arg0_ = __nw__7TObjectFUl(0x684);
    if (arg0_ != 0) {
        var_r4 = __nw__7TObjectFUl(0x20);
        if (var_r4 != 0) {
            var_r4 = TObjControl__ct(var_r4, tl_04);
        }
        arg0_ = TBoss6Type1__ct(arg0_, var_r4, arg2_);
    }
    return arg0_;
}

void TBoss6Type1::apply_poison_status() {  }
void TBoss6Type1::apply_paralysis() {  }
void TBoss6Type1::apply_slow_status() {  }
void TBoss6Type1::apply_confusion_status() {  }
void TBoss6Type1::apply_movement_ailment(s32) {  }
void TBoss6Type1::apply_shock_status() {  }
void TBoss6Type1::clear_harmful_statuses() {  }
void*TBoss6Type1::get_mag_mine_ptr() { return (char*)this + 0x388; }
int TBoss6Type1::is_idle() { return this->m_374 == 0; }
void TBoss6Type1::read_be16_field2() { ((G_ClientIDHeader *)this)->bswap(); }
void TBoss6Type1::step_and_send_60() { read_be16_field2(); send_subcommand((u8 *)this); }
void build_6xA4_olga_flow_boss_actions(void* p) { *(u8*)((char*)p + 0x0) = 164; *(u8*)((char*)p + 0x1) = 5; }
