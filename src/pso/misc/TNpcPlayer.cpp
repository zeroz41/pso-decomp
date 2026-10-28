#include "pso/misc/TLobby_801E43E4.h"
#include "types.h"
#include "pso/TObject.h"
#include "pso/object/TUnk_804AF7B0.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TNpcPlayer.h"
#include "pso/object/TObjMotion.h"
extern "C" void render__10TNpcPlayerFv();
#include "pso/object/TObjFogCollisionPoison.h"

#include "pso/enemy/TObjEneDD.h"
#include "pso/item/TItemProShield.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/object/TObjFogCollision.h"
#include "pso/protocol/protocol_types.h"

extern "C" {
s32 VecCopy__FP3VecPC3Vec(void *, int);
void fn_8002B630(u8 *arg0, u8 *arg1);
void rotate_matrix_y(s32, s32);
s32 push_matrix_from(void *src);
s32 pop_matrices(s32 arg0);
extern u8 identity_matrix[];
extern const f32 TNpcPlayer__data_805DB1F0;
extern const f32 lbl_805DB1FC;
extern const f32 TNpcPlayer__data_805DB204;
struct Stack_8014F728 {
    s32 sp8;
    f32 spC;
};

struct Text_8014E250 { char text[0x36]; };

struct Owner_8014E250 { u8 pad[0x94]; void *obj; };

struct Npc_8014E250 {
    u8 pad[0x24];
    s32 state;
    u8 pad28[0x5C - 0x28];
    u8 timer[0x78 - 0x5C];
    Owner_8014E250 *owner;
    u8 pad7c[4];
    u32 flags;
};

struct Actor_8014F140 {
    u8 pad0[0x30];
    u32 flags30;
    u8 pad1[0x60 - 0x34];
    s32 field_0x60;
};

struct Contact_8014F140 {
    u8 pad0[0x18];
    u32 flags18;
};

struct Probe_8014F140 {
    u8 pad0[0x38];
    u8 pos38[0x60 - 0x38];
    s32 field_0x60;
};

struct View_8014F140 {
    u8 pad0[0x8C];
    u32 flags8c;
    u8 pad1[0x94 - 0x90];
    Probe_8014F140 *target94;
    s32 field_0x98;
    u8 pad2[0xA8 - 0x9C];
    Probe_8014F140 *probe;
    u8 pad3[0xD8 - 0xAC];
    u8 hit_d8[0x104 - 0xD8];
    s32 field_0x104;
};

struct Cand_8014F424 { u32 id; s32 idx; f32 dist; };

struct View_8014F424 { s32 count; Cand_8014F424 c[10]; };

struct Actor_8014F424 { u8 pad[0xA4]; u8 *cols; s32 ncols; };

struct Col_8014F57C { u8 pad[0x18]; u32 flags; u8 pos[0x2C - 0x1C]; };

struct Actor_8014F57C { u8 pad0[0x30]; u32 flags30; u8 pad1[0xA4 - 0x34]; Col_8014F57C *cols; s32 ncols; };

struct View_8014F57C { s32 count; Cand_8014F424 c[10]; u8 pad[0x94 - 0x7C]; void *f94; };

typedef struct Vec_8014E3B0 { f32 x, y, z; } Vec_8014E3B0;

struct Ent_8014F28C { s32 a; s32 b; f32 key; };

typedef struct Obj_8014EE98 { u8 pad[0x2FC]; Vec_8014E3B0 pos; } Obj_8014EE98;

typedef struct Owner_8014EE98 { u8 pad[0x94]; Obj_8014EE98 *obj; } Owner_8014EE98;

typedef struct Self_8014EE98 {
    u8 pad[0x74];
    Owner_8014EE98 *f74;
    Owner_8014EE98 *f78;
    u8 pad7C[0xDC - 0x7C];
    u8 fDC[4];
} Self_8014EE98;

typedef struct Line_8014EE98 { Vec_8014E3B0 p; Vec_8014E3B0 d; } Line_8014EE98;

struct Stack_8014FEAC {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct Rec_8014F844 { s32 id; s32 f4; f32 dist; };

struct Npc_8014F844 {
    s32 f0;
    Rec_8014F844 recs[10];
    s32 f7C;
    s32 f80;
    s32 f84;
    s16 f88;
    u16 f8A;
    s32 f8C;
    s32 f90;
    s32 f94;
    s32 f98;
    f32 f9C;
    f32 fA0;
    f32 fA4;
    void *fA8;
    f32 fAC;
    f32 fB0;
    f32 fB4;
    f32 fB8;
    f32 fBC;
    s32 fC0;
    s32 fC4;
    u8 padC8[0x104 - 0xC8];
    s32 f104;
};

struct Stack_801515E0 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct Msg_80150DE8 { u8 hdr[2]; u16 type; f32 x; f32 z; };

struct Npc_80150DE8 { u8 pad[0x78]; void *owner; u8 pad7c[0xAC - 0x7C]; f32 x; f32 y; f32 z; };

struct Msg_80150E44 { u8 hdr[2]; u16 type; f32 x; f32 z; u32 flags; };

struct Obj_80150E44 { u8 pad[0x30]; u32 flags; };

struct Owner_80150E44 { u8 pad[0x94]; Obj_80150E44 *obj; };

struct Npc_80150E44 { u8 pad[0x78]; Owner_80150E44 *owner; u8 pad7c[0xAC - 0x7C]; f32 x; f32 y; f32 z; };

struct V3_80150050 { f32 x, y, z; };

struct Tgt_80150050 { u8 pad[0x38]; V3_80150050 pos; };

struct Mid_80150050 { u8 pad[0x94]; Tgt_80150050 *tgt; };

struct Npc_80150050 { u8 pad0[0x74]; Mid_80150050 *mid; u8 pad78[0x34]; V3_80150050 pos; u8 pad_b8[0x18]; V3_80150050 dst; };

struct Msg_80150A34 {
    u8 pad0[2];
    u16 type;
    s8 kind;
    u8 pad5;
    s8 e;
    s8 one;
    u8 sub[0x2C];
};

struct Owner_80150A34 { u8 pad[0x94]; u8 *actor; };

struct Npc_80150A34 { u8 pad[0x74]; void *p74; Owner_80150A34 *p78; u8 pad7C[4]; u32 flags; };

struct Npc_801518A4 {
    u8 pad0[0x44];
    f32 f44;
    f32 f48;
    u8 pad4C[0x58 - 0x4C];
    f32 f58;
    u8 a5C[0x74 - 0x5C];
    void *p74;
    u8 *p78;
    u8 pad7C[4];
    u32 flags;
};

struct Tgt_801518A4 { s32 a; s32 b; };

struct Cand_80151708 { u32 id; s32 idx; f32 dist; };

struct View_80151708 { s32 count; Cand_80151708 c[10]; };

struct Pos_80151708 { u8 pad[0x38]; f32 x; f32 y; f32 z; };

struct Obj_80151708 { u8 pad[0x38]; f32 pos[0x300 / 4 - 0x38 / 4]; f32 f300; };

struct Owner_80151708 { u8 pad[0x94]; Obj_80151708 *obj; };

struct Npc_80151708 {
    u8 pad0[0x4C];
    f32 f4C;
    u8 pad50[0x5C - 0x50];
    u8 f5C[0x78 - 0x5C];
    Owner_80151708 *f78;
    u8 pad7C[4];
    u32 f80;
    u8 pad84[0xDC - 0x84];
    f32 dst[3];
};

struct Tgt_801510F8 { s32 a; s32 b; };

struct Obj_801510F8 { u8 pad[0x94]; u8 *obj; };

struct Npc_801510F8 {
    u8 pad0[0x34];
    s32 f34;
    u8 pad38[0x48 - 0x38];
    f32 f48;
    u8 pad4C[0x5C - 0x4C];
    u8 counters[0x74 - 0x5C];
    Obj_801510F8 *f74;
    Obj_801510F8 *f78;
    u8 pad7C[0x80 - 0x7C];
    s32 f80;
    s32 f84;
    u8 pad88[0x92 - 0x88];
    s16 f92;
    u8 pad94[0xDC - 0x94];
    u8 dst[0xC];
};

struct Own_80152168 { u8 pad[0x94]; u8 *obj; };

struct Npc_80152168 {
    s32 f0;
    u8 pad4[0x14];
    s32 *vt;
    s32 f1C;
    s32 f20;
    s32 f24;
    u8 pad28[4];
    s16 f2C;
    u8 pad2E[2];
    u8 f30[0x28];
    f32 f58;
    u8 f5C[0x74 - 0x5C];
    void *f74;
    Own_80152168 *f78;
    s32 f7C;
    s32 f80;
    s32 f84;
    f32 f88;
    s8 f8C;
    s8 f8D;
    s16 f8E;
    u8 pad90[0xAC - 0x90];
    f32 fAC;
    f32 fB0;
    f32 fB4;
    u8 padB8[0xC4 - 0xB8];
    s32 fC4;
    s32 fC8;
    s32 fCC;
    f32 fD0;
    f32 fD4;
    f32 fD8;
    f32 fDC;
    f32 fE0;
    f32 fE4;
};

struct Own_80152330 { u8 pad[0x94]; u8 *obj; };

struct Npc_80152330 {
    s32 f0;
    u8 pad4[0x14];
    s32 *vt;
    s32 f1C;
    s32 f20;
    s32 f24;
    u8 pad28[4];
    s16 f2C;
    u8 pad2E[2];
    u8 f30[0x28];
    f32 f58;
    u8 f5C[0x74 - 0x5C];
    void *f74;
    Own_80152330 *f78;
    s32 f7C;
    s32 f80;
    s32 f84;
    f32 f88;
    s8 f8C;
    s8 f8D;
    s16 f8E;
    u8 pad90[0xAC - 0x90];
    f32 fAC;
    f32 fB0;
    f32 fB4;
    u8 padB8[0xC4 - 0xB8];
    s32 fC4;
    s32 fC8;
    s32 fCC;
    f32 fD0;
    f32 fD4;
    f32 fD8;
    f32 fDC;
    f32 fE0;
    f32 fE4;
};

struct Obj_801528A8 { u8 pad[0x5c]; u8 arr[1]; };

struct Vec_801501A0 {
    f32 x, y, z;
};

struct Actor_801501A0 {
    u8 pad0[0x38];
    Vec_801501A0 pos;
    u8 pad44[0x2FC - 0x44];
    Vec_801501A0 anchor;
};

struct View_801501A0 {
    u8 pad0[0x94];
    Actor_801501A0 *actor;
    u8 pad98[4];
    Vec_801501A0 v9c;
};

struct Self_801501A0 {
    u8 pad0[0x78];
    View_801501A0 *view;
    u8 pad7c[4];
    u32 flags;
    u8 pad84[8];
    s8 s8c;
    s8 s8d;
    u8 pad8e[2];
    s16 s90;
    u8 pad92[2];
    Vec_801501A0 dir;
    Vec_801501A0 wp;
    u8 padac[0xD0 - 0xAC];
    Vec_801501A0 target;
    Vec_801501A0 dest;
};

struct Obj_80150B90;

struct Owner_80150B90 { u8 pad[0x94]; Obj_80150B90 *obj; };

struct Npc_80150B90 {
    u8 pad0[0x34];
    u32 f34;
    u8 pad38[0x50 - 0x38];
    s8 f50;
    u8 pad51[2];
    u8 f53;
    u8 pad54[0x78 - 0x54];
    Owner_80150B90 *f78;
    u8 pad7C[4];
    u32 f80;
};

struct Tec_80150B90 { u8 pad[0x10]; s16 f10; };

typedef u8 Row28_804ABC90[0x28];

struct Npc_801510F8;

struct Npc_80151708;

struct Npc_801518A4;

struct Obj_80152F28 { u16 a; u16 b; };

struct N_80152C8C { u8 pad0[7]; s8 count; u32 pos[1]; };

struct Line_8014E488 { Vec_8014E3B0 p; Vec_8014E3B0 d; };

s16 get_actor_tp(u8 *p);
s16 obj_getS16_2BA(u8 *p);
s16 get_actor_hp(u8 *p);
int get_player_data__10TObjPlayerFi(int a0);
s32 get_entity_id(void *obj);
f32 fabs_float(f32);
f64 atan2_float(int, f32, f32, f32);
void queue_destruction__7TObjectFv(void *arg0);
s32 __dt__12TPlyCharDataFv(s32 arg0, s16 arg1);
void * __ct__12TPlyCharDataFv(void *self);
u8 * csnVector(s32, s32, s32);
s32 is_alive__9TObjEneDDFv(void *);
s32 find_active_entity_by_id(void *);
f32 horizontal_distance_squared(void *, void *);
void *mem_alloc(u32 size);
void TNpcPlayer__sub_8014DC3C(void *, s32);
void deliver_partner_chatter(Npc_8014E250 *self);
void partner_compute_stalled_detour(u8 *self, Vec_8014E3B0 *from, Vec_8014E3B0 *to, Vec_8014E3B0 *d, Vec_8014E3B0 *out);
s32 partner_route_around_wall(Self_8014EE98 *self, Vec_8014E3B0 *from, Vec_8014E3B0 *to, Vec_8014E3B0 *d, Vec_8014E3B0 *out, Vec_8014E3B0 *out2);
s32 partner_probe_obstacles(View_8014F140 *view);
s32 partition_sort_entries__10TNpcPlayerFiPvii(s32 self, Ent_8014F28C *a, s32 lo, s32 hi);
s32 find_parts_in_range__10TNpcPlayerFPvPvif(View_8014F424 *view, void *pos, s32 id, f32 range);
s32 scan_nearby_enemies__10TNpcPlayerFPvPvf(View_8014F57C *view, void *pos, f32 range);
bool is_target_line_clear__10TNpcPlayerFPvUs(u8 *arg0, u16 arg1);
Npc_8014F844 * init_ai_state__10TNpcPlayerFPvi(Npc_8014F844 *self, s32 id);
s32 try_update_target_flag__10TNpcPlayerFPvi(void *arg0, s32 arg1);
s32 check_and_set_reached__10TNpcPlayerFPv(void *arg0);
s32 needs_movement__10TNpcPlayerFPvPvi(u8 *arg0, void * _w1, int _w2);
void select_path_waypoint__10TNpcPlayerFv(Self_801501A0 *self);
void request_technique_cast__10TNpcPlayerFPvi(Npc_80150A34 *self, s32 kind);
s32 select_recovery_action__10TNpcPlayerFv(Npc_801510F8 *self, s32 arg1);
void run_task__10TNpcPlayerFv(u8 *arg0);
u8 * __dt__10TNpcPlayerFv(u8 *arg0, s16 arg1);
Npc_80152168 * TNpcPlayer__ct(Npc_80152168 *self, s32 a, s32 b, s16 kind, s32 arg4, void *parent);
Npc_80152330 * construct_partner__10TNpcPlayerFPviisPv(Npc_80152330 *self, s32 a, s32 b, s16 kind, void *parent);
void set_technique_seed_level(Obj_801528A8 *self, s16 i, u8 v);
void reset_partner_counter(s32 arg0, s32 arg1);
void increment_partner_counter(s32 arg0, s32 arg1);
s32 TNpcPlayer__sub_801528DC(void* p);
u16 get_npc_type__10TNpcPlayerFPv(void* p);
int get_partner_counter(s32 arg0, s32 arg1);
s32 npc_counter_reset_if_reached(s32 arg0, s32 arg1);
s32 TNpcPlayer__sub_80152978(void* p);
void copy_transform_second__10TNpcPlayerFPvPvPv(void* p, void* a1, void* a2);
void copy_transform__10TNpcPlayerFPvPv(void* p, void* q);
void TNpcPlayer__sub_80152A30(void);
void TNpcPlayer__sub_80152A34(u8 *arg0, s32 arg1, s32 arg2);
void TNpcPlayer__sub_80152A78(s16 *self);
void init_6x45_attack_packet(u8 *arg0);
void init_6x44_attack_packet(u8 *arg0);
void init_6x43_attack_packet(u8 *arg0);
void TNpcPlayer__sub_80152D64(void* p);
void set_state__10TNpcPlayerFPvs(void* p, s16 v);
void set_type__10TNpcPlayerFPvs(void* p, s16 v);
void* fn_80152EF8(void* p);
void TFontSmallLobby__sub_80152F28(Obj_80152F28 *self);
s32 check_switch__22TObjFogCollisionPoisonFv(s32);
void TObjFogCollisionPoison__sub_80153520(s32 arg0);
void TObjFogCollisionPoison__sub_801535D0(s32 arg0);
Actor_8014F424 * find_entity_by_id(s32);
s32 free_collision_body_parts(u32);
void init_collision_body_parts(void *, void *, s32);
void * __ct__13TUnk_804AF8A0FP7TObject(void *, void *);
s32 is_any_teammate_in_state__10TObjPlayerFv(void *self);
s32 try_send_6x27_use_item(s32, s32, void *);
void *get_player_by_client_id(s32 i);
s8 get_cast_technique_level(void *, s16);
int bswap_16__FPUs(void*);
int bswap_32__FPUl(void*);
void update_players__6TLobbyFv(s32 arg0);
void __dl__7TObjectFPv(s32);
void * __nw__7TObjectFUl(u32);
s32 __dt__7TObjectFv(void *, int);
void __ct__7TObjectFP7TObject(void *, void *);
Tec_80150B90 * calc_technique_parameters(s32, s32, s32);
}
s32 partner_clip_path_point(void *self, f32 *from, f32 *to, f32 *out);
s32 partner_find_wall_segment(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 refresh_npc_view_actor_lost(void *arg0);
s32 partner_view_update_hp_change(void *arg0);
s32 partner_view_update_conditions(u8 *arg0);
s32 partner_view_check_moved(u8 *arg0);
void partner_observe_surroundings(TNpcPlayer *arg0);
int is_partner_counter_reached(s16 *table, s32 idx, s32 value);
void set_partner_counter(s32 arg0, s32 arg1, s16 arg2);
s32 clamp_partner_counter(s32 arg0, s32 arg1, s16 arg2);
void bswap_6x45_packet(void* p);
void bswap_6x44_packet(void* p);
void bswap_6x43_packet(void* p);
u8 get_6x47_cast_packet_size(u8 *arg0);
void init_6x40_walk_packet(void* a0);
int get_registered_object_count(void);
const char *get_partner_custom_text(s32 kind, u16 player);
extern "C" {
s32 is_active__12TTecReverserFv(void *);
void __register_global_object(void *obj, void *dtor, void *link);
void __construct_array(void *, void *, int, int, int);
s32 rand(void);
void matrix_mult_vec(s32, Vec_8014E3B0 *, Vec_8014E3B0 *);
f32 vec3_dot(Vec_8014E3B0 *, Vec_8014E3B0 *);
f32 vector_length(Vec_8014E3B0 *);
void normalize_vector(Vec_8014E3B0 *);
void project_point_onto_line(void *, Line_8014EE98 *, Vec_8014E3B0 *);
f32 xyz_distance(Vec_8014E3B0 *, Vec_8014E3B0 *);

extern const f32 TNpcPlayer__data_805DB1F4;
extern const f32 TNpcPlayer__data_805DB20C;
extern f32 TNpcPlayer__data_805DB218;
extern const f32 TNpcPlayer__data_805DB22C;
extern const f32 TNpcPlayer__data_805DB23C;
extern int registered_entity_count;
extern V3_80150050 lbl_8043FFAC;
extern const f64 lbl_8043FFD8;
extern Text_8014E250 npc_partner_dialogue_state[];
extern s32 lbl_805D2E74;
extern u32 lbl_805D5860;
extern const f32 lbl_805DB1F8;
extern const f32 lbl_805DB208;
extern const f32 lbl_805DB210;
extern const f32 lbl_805DB214;
extern const f32 lbl_805DB21C;
extern const f32 lbl_805DB220;
extern const f32 lbl_805DB224;
extern const f32 lbl_805DB228;
extern const f32 lbl_805DB230;
extern const f32 lbl_805DB234;
extern const f32 lbl_805DB238;
extern const f32 lbl_805DB240;
extern const f32 lbl_805DB244;
extern const f32 lbl_805DB248;
extern const f32 lbl_805DB24C;
extern void *tl_05;

void copy_player_visual_record(void *, void *);
void bswap__15disp_data_part2Fv(s32 arg0);
void mem_free(void *);
extern s32 game_difficulty_selection;
extern s32 TNpcPlayer__data_805D5864;

u32 lbl_8050CF68[20];
u32 npc_player_ply_char_data_global[3];
u32 lbl_8050CFC4[263];
u32 lbl_8050D3E0[20];
extern "C" void render_shadows__7TObjectFv();
extern void *lbl_804AC690[35];
extern void *lbl_804AC71C[35];
extern void *lbl_804AC7A8[35];
extern void *lbl_804AC834[35];
extern void *lbl_804AC8C0[35];
extern void *lbl_804AC94C[70];
extern void *lbl_804ACA64[28];
extern void *lbl_804ACAD4[35];
extern void *lbl_804ACB60[35];
extern void *lbl_804ACBEC[35];
extern void *lbl_804ACC78[35];
extern void *lbl_804ACD04[35];
extern void *lbl_804ACD90[35];
extern void *lbl_804ACE1C[35];
extern void *lbl_804ACEA8[35];
extern void *lbl_804ACF34[35];
extern void *lbl_804ACFC0[35];
extern void *lbl_804AD04C[35];
extern void *lbl_804AD0D8[35];
extern void *lbl_804AD164[35];
extern void *lbl_804AD1F0[70];
extern void *lbl_804AD308[35];
extern void *lbl_804AD394[35];
extern void *lbl_804AD420[35];
extern void *lbl_804AD4AC[35];
extern void *lbl_804AD538[35];
extern void *lbl_804AD5C4[35];
extern void *lbl_804AD650[35];
extern void *lbl_804AD6DC[35];
extern void *lbl_804AD768[35];
extern void *lbl_804AD7F4[35];
extern void *lbl_804AD880[35];
extern void *lbl_804AD90C[35];
extern void *lbl_804AD998[35];
extern void *lbl_804ADA24[35];
extern void *lbl_804ADAB0[35];
extern void *lbl_804ADB3C[35];
extern void *lbl_804ADBC8[35];
extern void *lbl_804ADC54[35];
extern void *lbl_804ADCE0[35];
extern void *lbl_804ADD6C[70];
extern void *lbl_804ADE84[28];
extern void *lbl_804ADEF4[35];
extern void *lbl_804ADF80[35];
extern void *lbl_804AE00C[35];
extern void *lbl_804AE098[35];
extern void *lbl_804AE124[35];
extern void *lbl_804AE1B0[35];
extern void *lbl_804AE23C[35];
extern void *lbl_804AE2C8[70];
extern void *lbl_804AE3E0[35];
extern void *lbl_804AE46C[35];
extern void *lbl_804AE4F8[35];
extern void *lbl_804AE584[35];
extern void *lbl_804AE610[70];
extern void *lbl_804AE728[35];
extern void *lbl_804AE7B4[35];
extern void *lbl_804AE840[35];
extern void *lbl_804AE8CC[35];
extern void *lbl_804AE958[35];
extern void *lbl_804AE9E4[35];
extern void *lbl_804AEA70[35];
extern void *lbl_804AEAFC[35];
extern void *lbl_804AEB88[35];
extern void *lbl_804AEC14[35];
extern void *lbl_804AECA0[35];
extern void *lbl_804AED2C[35];
extern void *lbl_804AEDB8[35];
extern void *lbl_804AEE44[35];
extern void *lbl_804AEED0[35];
extern void *lbl_804AEF5C[35];
extern void *lbl_804AEFE8[35];
extern void *lbl_804AF074[35];
extern void *lbl_804AF100[35];
extern void *lbl_804AF18C[35];
extern void *lbl_804AF218[35];
extern void *npc_player_template_table[35];
struct Row_80152674 { u16 f0; u16 f2; u32 w[9]; };
Row_80152674 TNpcPlayer__template_table[64] = {
    {0x0, 0x4, {0x40, 0x42c80000, 0x41200000, 0x41500000, 0x41f00000, 0x41f00000, 0x42c80000, 0x90f00, 0x42480000}},
    {0x1, 0xc, {0x8, 0x42c80000, 0x41200000, 0x41700000, 0x420c0000, 0x41c80000, 0x42c80000, 0x9195a, 0x42480000}},
    {0x2, 0x14, {0x8, 0x42c80000, 0x41200000, 0x41700000, 0x42200000, 0x41f00000, 0x42c80000, 0x2091e50, 0x42480000}},
    {0x3, 0x12, {0x4, 0x42f00000, 0x41200000, 0x41900000, 0x42200000, 0x41f00000, 0x42c80000, 0x93c28, 0x42480000}},
    {0x4, 0xe, {0x40, 0x42c80000, 0x41200000, 0x41700000, 0x42200000, 0x41f00000, 0x42f00000, 0x91400, 0x42480000}},
    {0x5, 0x18, {0x40, 0x42c80000, 0x41200000, 0x41700000, 0x41f00000, 0x41f00000, 0x42c80000, 0x93c00, 0x42480000}},
    {0x6, 0x19, {0x40, 0x42a00000, 0x41200000, 0x41900000, 0x42700000, 0x41f00000, 0x41f00000, 0x95028, 0x42480000}},
    {0x7, 0xb, {0x40, 0x42c80000, 0x41200000, 0x41500000, 0x42200000, 0x41f00000, 0x42c80000, 0x91400, 0x42480000}},
    {0x8, 0x11, {0x8, 0x42c80000, 0x41200000, 0x41700000, 0x42200000, 0x41f00000, 0x42c80000, 0x6091e46, 0x42480000}},
    {0x9, 0x1b, {0x40, 0x42a00000, 0x41200000, 0x41900000, 0x428c0000, 0x41f00000, 0x41f00000, 0x93700, 0x42480000}},
    {0xa, 0x12, {0x40, 0x42a00000, 0x41200000, 0x41900000, 0x428c0000, 0x41f00000, 0x41f00000, 0x93c00, 0x42480000}},
    {0xb, 0x11, {0x10, 0x42a00000, 0x41200000, 0x41900000, 0x42700000, 0x41f00000, 0x41f00000, 0x4092d37, 0x42480000}},
    {0xc, 0x23, {0x40, 0x42a00000, 0x41200000, 0x41900000, 0x428c0000, 0x41f00000, 0x41f00000, 0x2d00, 0x42480000}},
    {0xd, 0xf, {0x4, 0x42c80000, 0x41200000, 0x41700000, 0x42480000, 0x41f00000, 0x42c80000, 0x93714, 0x42480000}},
    {0xe, 0x22, {0x40, 0x42f00000, 0x41200000, 0x41700000, 0x42480000, 0x41f00000, 0x42c80000, 0x93200, 0x42480000}},
    {0xf, 0xb, {0x40, 0x42f00000, 0x41200000, 0x41700000, 0x42200000, 0x41f00000, 0x42c80000, 0x92800, 0x42480000}},
    {0x10, 0x9, {0x8, 0x42c80000, 0x41200000, 0x41700000, 0x42200000, 0x41f00000, 0x42a00000, 0x2090a50, 0x42480000}},
    {0x11, 0x2a, {0x10, 0x43160000, 0x41200000, 0x41700000, 0x42340000, 0x41f00000, 0x42f00000, 0xb0b3246, 0x42480000}},
    {0x12, 0x20, {0x4, 0x42c80000, 0x41200000, 0x41700000, 0x41f00000, 0x41f00000, 0x42f00000, 0x909325a, 0x42480000}},
    {0x13, 0x7, {0x4, 0x42c80000, 0x41200000, 0x41700000, 0x41f00000, 0x41f00000, 0x42c80000, 0xb0a50, 0x42480000}},
    {0x14, 0x17, {0x4, 0x43960000, 0x41200000, 0x41f00000, 0x42200000, 0x41c80000, 0x41c80000, 0x2001e28, 0x42480000}},
    {0x15, 0x18, {0x40, 0x43480000, 0x41200000, 0x42a00000, 0x42700000, 0x42200000, 0x420c0000, 0x3200, 0x42480000}},
    {0x16, 0x14, {0x88, 0x43960000, 0x41200000, 0x41f00000, 0x41f00000, 0x41a00000, 0x42700000, 0x400324b, 0x42340000}},
    {0x17, 0xb, {0xc0, 0x43960000, 0x41200000, 0x42480000, 0x42480000, 0x41a00000, 0x42c80000, 0x90f00, 0x428c0000}},
    {0x18, 0xc, {0x40, 0x43480000, 0x41200000, 0x42200000, 0x42200000, 0x41f00000, 0x42a00000, 0x92d00, 0x42700000}},
    {0x19, 0x13, {0x40, 0x43480000, 0x41200000, 0x42200000, 0x42200000, 0x41f00000, 0x42a00000, 0x93700, 0x42700000}},
    {0x1a, 0x11, {0x40, 0x42a00000, 0x41200000, 0x41900000, 0x428c0000, 0x41f00000, 0x41f00000, 0x4093200, 0x42480000}},
    {0x1b, 0xd, {0x40, 0x42c80000, 0x41200000, 0x41700000, 0x42480000, 0x41f00000, 0x42a00000, 0x91e00, 0x42480000}},
    {0x1c, 0x14, {0x10, 0x428c0000, 0x41200000, 0x41700000, 0x41a00000, 0x41f00000, 0x42480000, 0x93232, 0x42480000}},
    {0x1d, 0xd, {0x40, 0x42c80000, 0x41200000, 0x41700000, 0x42480000, 0x41f00000, 0x42a00000, 0x91e00, 0x42480000}},
    {0x1e, 0x18, {0x8, 0x42a00000, 0x41200000, 0x41700000, 0x42480000, 0x41f00000, 0x42700000, 0x609321e, 0x42480000}},
    {0x1f, 0x1e, {0x88, 0x43960000, 0x41200000, 0x42200000, 0x42200000, 0x41a00000, 0x42c80000, 0x8092350, 0x42340000}},
    {0x20, 0xa, {0x40, 0x42a00000, 0x41200000, 0x41900000, 0x428c0000, 0x41f00000, 0x41f00000, 0x93200, 0x42480000}},
    {0x21, 0xf, {0x40, 0x42a00000, 0x41200000, 0x41900000, 0x428c0000, 0x41f00000, 0x41f00000, 0x93200, 0x42480000}},
    {0x22, 0x2a, {0x4, 0x42a00000, 0x41200000, 0x41900000, 0x428c0000, 0x41f00000, 0x41f00000, 0x93c1e, 0x42480000}},
    {0x23, 0x21, {0x10, 0x42a00000, 0x41200000, 0x41900000, 0x428c0000, 0x41f00000, 0x41f00000, 0x6093c32, 0x42480000}},
    {0x24, 0xb, {0x40, 0x42c80000, 0x41200000, 0x41700000, 0x42200000, 0x41f00000, 0x42480000, 0x96432, 0x42480000}},
    {0x25, 0x1a, {0x40, 0x42c80000, 0x41200000, 0x41700000, 0x42200000, 0x41f00000, 0x42c80000, 0x93c00, 0x42480000}},
    {0x26, 0x23, {0x40, 0x43480000, 0x41200000, 0x41700000, 0x42700000, 0x41f00000, 0x41f00000, 0x3c00, 0x42480000}},
    {0x27, 0x1c, {0x4, 0x42f00000, 0x41200000, 0x41700000, 0x42480000, 0x41f00000, 0x42c80000, 0x7093c1e, 0x42480000}},
    {0x28, 0x14, {0x8, 0x43480000, 0x41200000, 0x41900000, 0x42700000, 0x41f00000, 0x41f00000, 0x4093c1e, 0x42480000}},
    {0x29, 0x1b, {0x4, 0x42a00000, 0x41200000, 0x41900000, 0x42700000, 0x41f00000, 0x41f00000, 0x4093c32, 0x42480000}},
    {0x2a, 0x1d, {0x4, 0x42700000, 0x41200000, 0x41c80000, 0x42340000, 0x41f00000, 0x41f00000, 0x9096432, 0x42480000}},
    {0x2b, 0x22, {0x40, 0x42f00000, 0x41200000, 0x41700000, 0x41f00000, 0x41f00000, 0x42c80000, 0x93c00, 0x42480000}},
    {0x2c, 0x9, {0x10, 0x42a00000, 0x41200000, 0x41900000, 0x42700000, 0x41f00000, 0x41f00000, 0x9096432, 0x42480000}},
    {0x2d, 0x9, {0x84, 0x43960000, 0x41200000, 0x41700000, 0x41f00000, 0x41f00000, 0x42c80000, 0x9321e, 0x42480000}},
    {0x2e, 0x9, {0x40, 0x43480000, 0x41200000, 0x41700000, 0x42700000, 0x41f00000, 0x41f00000, 0x94600, 0x42480000}},
    {0x2f, 0x9, {0x40, 0x42a00000, 0x41200000, 0x41900000, 0x42700000, 0x41f00000, 0x41f00000, 0x93200, 0x42480000}},
    {0x30, 0x9, {0x40, 0x42f00000, 0x41200000, 0x41700000, 0x41f00000, 0x41f00000, 0x42c80000, 0x93700, 0x42480000}},
    {0x31, 0x9, {0x40, 0x42f00000, 0x41200000, 0x41700000, 0x41f00000, 0x41f00000, 0x42c80000, 0x94600, 0x42480000}},
    {0x32, 0x9, {0x40, 0x42f00000, 0x41200000, 0x41700000, 0x42480000, 0x41f00000, 0x42c80000, 0x94100, 0x42480000}},
    {0x33, 0x9, {0xc0, 0x43480000, 0x41200000, 0x41a00000, 0x41a00000, 0x41f00000, 0x42a00000, 0x91900, 0x41f00000}},
    {0x34, 0x9, {0xc0, 0x43480000, 0x41200000, 0x42200000, 0x42200000, 0x41f00000, 0x42a00000, 0x92300, 0x428c0000}},
    {0x35, 0x9, {0x10, 0x43480000, 0x41200000, 0x41700000, 0x42700000, 0x41f00000, 0x41f00000, 0x4093c1e, 0x42480000}},
    {0x36, 0x9, {0xc0, 0x43480000, 0x41200000, 0x42200000, 0x42200000, 0x41f00000, 0x42a00000, 0x93c00, 0x42480000}},
    {0x37, 0x9, {0x88, 0x43160000, 0x41200000, 0x41c80000, 0x42340000, 0x41f00000, 0x42f00000, 0x6093250, 0x42480000}},
    {0x38, 0x23, {0x88, 0x43960000, 0x41200000, 0x42200000, 0x42200000, 0x41a00000, 0x43160000, 0xc0c3c46, 0x42480000}},
    {0x39, 0x9, {0x4, 0x42c80000, 0x41200000, 0x41c80000, 0x42340000, 0x41f00000, 0x42a00000, 0x93250, 0x42480000}},
    {0x3a, 0x9, {0x40, 0x42f00000, 0x41200000, 0x41700000, 0x41f00000, 0x41f00000, 0x42c80000, 0x91e00, 0x42480000}},
    {0x3b, 0x9, {0x4, 0x42700000, 0x41200000, 0x41c80000, 0x42340000, 0x41f00000, 0x42480000, 0x96432, 0x42480000}},
    {0x3c, 0x9, {0x4, 0x42700000, 0x41200000, 0x41500000, 0x42340000, 0x41f00000, 0x42480000, 0x96432, 0x42480000}},
    {0x3d, 0x9, {0x4, 0x42700000, 0x41200000, 0x41700000, 0x42340000, 0x41f00000, 0x41f00000, 0x96432, 0x42480000}},
    {0x3e, 0x9, {0x4, 0x42700000, 0x41200000, 0x41c80000, 0x42340000, 0x41f00000, 0x41f00000, 0x9093250, 0x42480000}},
    {0x3f, 0x9, {0x4, 0x42700000, 0x41200000, 0x41c80000, 0x42340000, 0x41f00000, 0x41f00000, 0x1091e32, 0x42480000}},
};
void *lbl_804AC690[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x60000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010200, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020200, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000000,
    (void *)0x70000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x70000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AC71C[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x10000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010500, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020500, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000000,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AC7A8[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xa0100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010300, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020300, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000000,
    (void *)0x70000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x50000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AC834[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x70100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010500, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020500, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000000,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x50000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AC8C0[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xc0100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010600, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020700, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AC94C[70] = {
    (void *)0x1000000, (void *)0x8, (void *)0x20100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010900, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020900, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0x30000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x80200, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1011a00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x8, (void *)0x1021800,
    (void *)0x0, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3000100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x0, (void *)0x3010100, (void *)0x30000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ACA64[28] = {
    (void *)0x1000000, (void *)0x8, (void *)0xc0100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010900, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020900, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3010000,
    (void *)0x30000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ACAD4[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xd0200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010b00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020b00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x30000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ACB60[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xe0100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011400, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021400, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x50000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ACBEC[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x110000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010d00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020d00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0x30000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ACC78[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x150000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010600, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020600, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0x50000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x30000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ACD04[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x30100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020a00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000000,
    (void *)0x10000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ACD90[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x100100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010900, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020900, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0x30000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x30000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ACE1C[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xf0000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010e00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020e00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ACEA8[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x90100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020800, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0x10000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x30000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ACF34[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x70100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010e00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020e00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000200,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010200, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ACFC0[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xa0200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011700, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021700, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AD04C[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x60200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010c00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020c00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0x50000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x50000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AD0D8[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x1b0000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011700, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021900, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AD164[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x50200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011400, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021600, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AD1F0[70] = {
    (void *)0x1000000, (void *)0x8, (void *)0x70100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010200, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020400, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000000,
    (void *)0x20000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x30000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x40200, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1011300, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x8, (void *)0x1021300,
    (void *)0x0, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3000100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x0, (void *)0x3010100, (void *)0x50000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AD308[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x10100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011300, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021300, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x50000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AD394[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x70200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011300, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021300, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x50000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AD420[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x20200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011500, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021800, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x50000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AD4AC[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x40100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010300, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020800, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000000,
    (void *)0x20000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x30000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AD538[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x160000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010400, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020400, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0x50000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x50000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AD5C4[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x140000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010e00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020e00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x50000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AD650[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x200000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010900, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020900, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0x30000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x30000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AD6DC[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x80100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010400, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020900, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0x20000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x20000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AD768[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x10000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010100, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020100, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000000,
    (void *)0x10000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AD7F4[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xa0100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010600, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020600, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0x10000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AD880[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xd0200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011700, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021800, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x50000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AD90C[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x30200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011600, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021600, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0x50000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AD998[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x110000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011a00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020400, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000200,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ADA24[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xc0100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010400, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020400, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000000,
    (void *)0x10000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x10000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ADAB0[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x60100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010900, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020900, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0x50000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x50000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ADB3C[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x10100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010900, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020900, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ADBC8[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xa0200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010b00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020b00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ADC54[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x70100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010900, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020900, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x50000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ADCE0[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xc0200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010d00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020d00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ADD6C[70] = {
    (void *)0x1000000, (void *)0x8, (void *)0x20200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010d00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020d00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0x50000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x80300, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1011a00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x8, (void *)0x1021d00,
    (void *)0x0, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3000100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x0, (void *)0x3010100, (void *)0x30000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ADE84[28] = {
    (void *)0x1000000, (void *)0x8, (void *)0xc0100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010d00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020d00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3010100,
    (void *)0x30000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ADEF4[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xd0200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010c00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020d00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x50000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804ADF80[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xe0200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011800, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021d00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000200,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010200, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AE00C[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x110100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011300, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021300, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0x50000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AE098[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x150000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010b00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020b00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x30000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AE124[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x30200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010200, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020e00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000000,
    (void *)0x50000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AE1B0[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x100100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010c00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020c00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0x50000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x30000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AE23C[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xf0000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011300, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021300, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AE2C8[70] = {
    (void *)0x1000000, (void *)0x8, (void *)0x90200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010200, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020a00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0x30000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x30000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x90300, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1011a00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x8, (void *)0x1021d00,
    (void *)0x0, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3000100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x0, (void *)0x3010100, (void *)0x50000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AE3E0[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xa0200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011b00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021b00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AE46C[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x60300, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011400, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021400, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AE4F8[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x1b0000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011b00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021d00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AE584[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x50300, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011900, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021a00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AE610[70] = {
    (void *)0x1000000, (void *)0x8, (void *)0x70200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010600, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020600, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000000,
    (void *)0x50000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x30000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x40300, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1011900, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x8, (void *)0x1021900,
    (void *)0x0, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3000100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x0, (void *)0x3010100, (void *)0x50000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AE728[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x10200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011800, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021800, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AE7B4[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x70300, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011900, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021a00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x50000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AE840[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x20300, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011b00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021d00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x50000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AE8CC[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x40200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010600, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020900, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000000,
    (void *)0x50000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x30000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AE958[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x160000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010900, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020900, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x50000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AE9E4[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x140000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011400, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021400, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x50000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AEA70[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x200100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010c00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020c00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0x50000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x30000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AEAFC[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x80200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010600, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020b00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0x50000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0x20000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AEB88[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x10200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010500, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020500, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000000,
    (void *)0x30000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AEC14[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xa0200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010800, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020800, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000000,
    (void *)0x30000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x10000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AECA0[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xd0200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011b00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021d00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010100, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AED2C[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x30300, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011a00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021a00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000100,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x50000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AEDB8[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x110100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011a00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020900, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000200,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AEE44[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xc0100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1010900, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1020900, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000000,
    (void *)0x10000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010000, (void *)0x10000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AEED0[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x80600, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011900, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021c00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000200,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010200, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AEF5C[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xc0500, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011a00, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021b00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000200,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010200, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AEFE8[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x970000, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011800, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021d00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000200,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010200, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AF074[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x8b0200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011900, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021c00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000200,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010200, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AF100[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x150100, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011900, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021c00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000200,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010200, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AF18C[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0xd0200, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011800, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021d00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000200,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010200, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AF218[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x70400, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011900, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021c00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000200,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010200, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *npc_player_template_table[35] = {
    (void *)0x1000000, (void *)0x8, (void *)0x890300, (void *)0x0,
    (void *)0x0, (void *)0xffffffff, (void *)0x0, (void *)0x1000000,
    (void *)0x8, (void *)0x1011900, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x1000000, (void *)0x8,
    (void *)0x1021c00, (void *)0x0, (void *)0x0, (void *)0xffffffff,
    (void *)0x0, (void *)0x1000000, (void *)0x0, (void *)0x3000200,
    (void *)0xa0000, (void *)0x0, (void *)0xffffffff, (void *)0x0,
    (void *)0x1000000, (void *)0x0, (void *)0x3010200, (void *)0xa0000,
    (void *)0x0, (void *)0xffffffff, (void *)0x0,
};
void *lbl_804AF330[64] = {
    (void *)&lbl_804AC690, (void *)&lbl_804ACA64, (void *)&lbl_804ACFC0, (void *)&lbl_804AD5C4,
    (void *)&lbl_804AD04C, (void *)&lbl_804AEED0, (void *)&lbl_804AEFE8, (void *)&lbl_804AD04C,
    (void *)&lbl_804ACFC0, (void *)&lbl_804ACB60, (void *)&lbl_804AC71C, (void *)&lbl_804ACAD4,
    (void *)&lbl_804AD998, (void *)&lbl_804ACC78, (void *)&lbl_804AD5C4, (void *)&lbl_804AC834,
    (void *)&lbl_804AC7A8, (void *)&lbl_804AD0D8, (void *)&lbl_804ACFC0, (void *)&lbl_804AC8C0,
    (void *)&lbl_804ACD04, (void *)&lbl_804AD4AC, (void *)&lbl_804AD768, (void *)&lbl_804AD1F0,
    (void *)&lbl_804AD1F0, (void *)&lbl_804ACEA8, (void *)&lbl_804AC71C, (void *)&lbl_804AC690,
    (void *)&lbl_804AC8C0, (void *)&lbl_804AC834, (void *)&lbl_804AD164, (void *)&lbl_804AD7F4,
    (void *)&lbl_804ACE1C, (void *)&lbl_804ACE1C, (void *)&npc_player_template_table, (void *)&lbl_804AD880,
    (void *)&lbl_804ADA24, (void *)&lbl_804AF074, (void *)&lbl_804ACBEC, (void *)&lbl_804ACC78,
    (void *)&lbl_804AC94C, (void *)&lbl_804AD308, (void *)&lbl_804ACFC0, (void *)&lbl_804AD394,
    (void *)&lbl_804AD308, (void *)&lbl_804AD04C, (void *)&lbl_804AD90C, (void *)&lbl_804AD650,
    (void *)&lbl_804AD394, (void *)&lbl_804AC834, (void *)&lbl_804AD0D8, (void *)&lbl_804AD6DC,
    (void *)&lbl_804AD6DC, (void *)&lbl_804ACD90, (void *)&lbl_804AD6DC, (void *)&lbl_804AD5C4,
    (void *)&lbl_804AD0D8, (void *)&lbl_804AD538, (void *)&lbl_804AD04C, (void *)&lbl_804AC94C,
    (void *)&lbl_804AD420, (void *)&lbl_804AD420, (void *)&lbl_804ACEA8, (void *)&lbl_804AD538,
};
void *lbl_804AF430[64] = {
    (void *)&lbl_804ADAB0, (void *)&lbl_804ADE84, (void *)&lbl_804AE3E0, (void *)&lbl_804AE9E4,
    (void *)&lbl_804AE46C, (void *)&lbl_804AEED0, (void *)&lbl_804AEFE8, (void *)&lbl_804AE46C,
    (void *)&lbl_804AE3E0, (void *)&lbl_804ADF80, (void *)&lbl_804ADB3C, (void *)&lbl_804ADEF4,
    (void *)&lbl_804AEDB8, (void *)&lbl_804AE098, (void *)&lbl_804AE9E4, (void *)&lbl_804ACF34,
    (void *)&lbl_804ADBC8, (void *)&lbl_804AE4F8, (void *)&lbl_804AE3E0, (void *)&lbl_804ADCE0,
    (void *)&lbl_804AE124, (void *)&lbl_804AE8CC, (void *)&lbl_804AEB88, (void *)&lbl_804AE610,
    (void *)&lbl_804AE610, (void *)&lbl_804AE2C8, (void *)&lbl_804ADB3C, (void *)&lbl_804ADAB0,
    (void *)&lbl_804ADCE0, (void *)&lbl_804ADC54, (void *)&lbl_804AE584, (void *)&lbl_804AEC14,
    (void *)&lbl_804AE23C, (void *)&lbl_804AE23C, (void *)&npc_player_template_table, (void *)&lbl_804AECA0,
    (void *)&lbl_804AEE44, (void *)&lbl_804AF074, (void *)&lbl_804AE00C, (void *)&lbl_804AE098,
    (void *)&lbl_804ADD6C, (void *)&lbl_804AE728, (void *)&lbl_804AE3E0, (void *)&lbl_804AE7B4,
    (void *)&lbl_804AE728, (void *)&lbl_804AE46C, (void *)&lbl_804AED2C, (void *)&lbl_804AEA70,
    (void *)&lbl_804AE7B4, (void *)&lbl_804AE7B4, (void *)&lbl_804AE4F8, (void *)&lbl_804AEAFC,
    (void *)&lbl_804AEAFC, (void *)&lbl_804AE1B0, (void *)&lbl_804AEAFC, (void *)&lbl_804AE9E4,
    (void *)&lbl_804AE3E0, (void *)&lbl_804AE958, (void *)&lbl_804AE46C, (void *)&lbl_804ADD6C,
    (void *)&lbl_804AE840, (void *)&lbl_804AE840, (void *)&lbl_804AE2C8, (void *)&lbl_804AE958,
};
void *lbl_804AF530[64] = {
    (void *)&lbl_804ADAB0, (void *)&lbl_804ADE84, (void *)&lbl_804AE3E0, (void *)&lbl_804AE9E4,
    (void *)&lbl_804AE46C, (void *)&lbl_804AEED0, (void *)&lbl_804AEFE8, (void *)&lbl_804AE46C,
    (void *)&lbl_804AEF5C, (void *)&lbl_804ADF80, (void *)&lbl_804ADB3C, (void *)&lbl_804AF18C,
    (void *)&lbl_804AEDB8, (void *)&lbl_804AF100, (void *)&lbl_804AE9E4, (void *)&lbl_804AF218,
    (void *)&lbl_804AEF5C, (void *)&lbl_804AE4F8, (void *)&lbl_804AE3E0, (void *)&lbl_804ADCE0,
    (void *)&lbl_804AE124, (void *)&lbl_804AE8CC, (void *)&lbl_804AEB88, (void *)&lbl_804AE610,
    (void *)&lbl_804AE610, (void *)&lbl_804AE2C8, (void *)&lbl_804ADB3C, (void *)&lbl_804ADAB0,
    (void *)&lbl_804ADCE0, (void *)&lbl_804ADC54, (void *)&lbl_804AE584, (void *)&lbl_804AEC14,
    (void *)&lbl_804AE23C, (void *)&lbl_804AE23C, (void *)&npc_player_template_table, (void *)&lbl_804AF18C,
    (void *)&lbl_804AEE44, (void *)&lbl_804AF074, (void *)&lbl_804AE00C, (void *)&lbl_804AF100,
    (void *)&lbl_804ADD6C, (void *)&lbl_804AE728, (void *)&lbl_804AE3E0, (void *)&lbl_804AE7B4,
    (void *)&lbl_804AE728, (void *)&lbl_804AE46C, (void *)&lbl_804AED2C, (void *)&lbl_804AEA70,
    (void *)&lbl_804AE7B4, (void *)&lbl_804AE7B4, (void *)&lbl_804AE4F8, (void *)&lbl_804AEAFC,
    (void *)&lbl_804AEAFC, (void *)&lbl_804AE1B0, (void *)&lbl_804AEAFC, (void *)&lbl_804AE9E4,
    (void *)&lbl_804AE4F8, (void *)&lbl_804AE958, (void *)&lbl_804AE46C, (void *)&lbl_804ADD6C,
    (void *)&lbl_804AE840, (void *)&lbl_804AE840, (void *)&lbl_804AE2C8, (void *)&lbl_804AE958,
};
void *lbl_804AF630[64] = {
    (void *)&lbl_804ADAB0, (void *)&lbl_804ADE84, (void *)&lbl_804AE3E0, (void *)&lbl_804AE9E4,
    (void *)&lbl_804AE46C, (void *)&lbl_804AEED0, (void *)&lbl_804AEFE8, (void *)&lbl_804AE46C,
    (void *)&lbl_804AEF5C, (void *)&lbl_804ADF80, (void *)&lbl_804ADB3C, (void *)&lbl_804AF18C,
    (void *)&lbl_804AEDB8, (void *)&lbl_804AF100, (void *)&lbl_804AE9E4, (void *)&lbl_804AF218,
    (void *)&lbl_804AEF5C, (void *)&lbl_804AE4F8, (void *)&lbl_804AE3E0, (void *)&lbl_804ADCE0,
    (void *)&lbl_804AE124, (void *)&lbl_804AE8CC, (void *)&lbl_804AEB88, (void *)&lbl_804AE610,
    (void *)&lbl_804AE610, (void *)&lbl_804AE2C8, (void *)&lbl_804ADB3C, (void *)&lbl_804ADAB0,
    (void *)&lbl_804ADCE0, (void *)&lbl_804ADC54, (void *)&lbl_804AE584, (void *)&lbl_804AEC14,
    (void *)&lbl_804AE23C, (void *)&lbl_804AE23C, (void *)&npc_player_template_table, (void *)&lbl_804AF18C,
    (void *)&lbl_804AEE44, (void *)&lbl_804AF074, (void *)&lbl_804AE00C, (void *)&lbl_804AF100,
    (void *)&lbl_804ADD6C, (void *)&lbl_804AE728, (void *)&lbl_804AE3E0, (void *)&lbl_804AE7B4,
    (void *)&lbl_804AE728, (void *)&lbl_804AE46C, (void *)&lbl_804AED2C, (void *)&lbl_804AEA70,
    (void *)&lbl_804AE7B4, (void *)&lbl_804AE7B4, (void *)&lbl_804AE4F8, (void *)&lbl_804AEAFC,
    (void *)&lbl_804AEAFC, (void *)&lbl_804AE1B0, (void *)&lbl_804AEAFC, (void *)&lbl_804AE9E4,
    (void *)&lbl_804AE4F8, (void *)&lbl_804AE958, (void *)&lbl_804AE46C, (void *)&lbl_804ADD6C,
    (void *)&lbl_804AE840, (void *)&lbl_804AE840, (void *)&lbl_804AE2C8, (void *)&lbl_804AE958,
};
void *__vt__10TNpcPlayer[6] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__10TNpcPlayerFv, (void *)&run_task__10TNpcPlayerFv,
    (void *)&render__10TNpcPlayerFv, (void *)&render_shadows__7TObjectFv,
};

struct Info_8014E7A0 {
    u8 pad0[0xC];
    f32 w;
    f32 h;
    s32 type;
    u8 pad18[4];
    Vec_8014E3B0 pos;
};

struct Target_8014E7A0 { u8 pad0[0x38]; Vec_8014E3B0 pos; u8 pad44[0x2FC - 0x44]; Vec_8014E3B0 wpos; };

struct Owner_8014E7A0 { u8 pad0[0x94]; Target_8014E7A0 *obj; u8 pad98[0xD8 - 0x98]; u8 shape[0x104 - 0xD8]; s32 rot_y; };

struct Self_8014E7A0 {
    u8 pad0[0x74];
    Owner_8014E7A0 *f74;
    Owner_8014E7A0 *f78;
    u8 pad7C[0x8C - 0x7C];
    s8 level;
    u8 pad8D[0xDC - 0x8D];
    Vec_8014E3B0 pos;
};

extern "C" {
void calc_box_escape_axis__10TNpcPlayerFv(void *, Vec_8014E3B0 *, Vec_8014E3B0 *, Vec_8014E3B0 *, Vec_8014E3B0 *, Vec_8014E3B0 *, Vec_8014E3B0 *, f32 *);
extern Vec_8014E3B0 lbl_8043FFB8;
extern Vec_8014E3B0 lbl_8043FFC4;
s32 route_around_object__10TNpcPlayerFv(Self_8014E7A0 *self, Vec_8014E3B0 *out);
}

void TNpcPlayer::dispatch_action(s32 arg1) {
    switch (arg1) {
    case 0:
        if (((TNpcPlayer *)(*(s32 *)((s8 *)this + 0x78)))->get_condition() & 0x20) {
            handle_action((s32)(arg1));
        } else {
            ((s32 (*)(void *, s32))request_technique_cast__10TNpcPlayerFPvi)(this, 0xF);
        }
        if (*(s32 *)((s8 *)this + 0x80) & 0x200) {
            request_chatter((u32)(0x13));
        }
        return;
    case 1:
        if (((TNpcPlayer *)(*(s32 *)((s8 *)this + 0x78)))->get_condition() & 0x20) {
            handle_action((s32)(arg1));
            return;
        }
        break;
    case 2:
        if (((TNpcPlayer *)(*(s32 *)((s8 *)this + 0x78)))->get_condition() & 0x20) {
            handle_action((s32)(arg1));
            return;
        }
        ((s32 (*)(void *, s32))request_technique_cast__10TNpcPlayerFPvi)(this, 0x10);
        return;
    case 3:
        if (((TNpcPlayer *)(*(s32 *)((s8 *)this + 0x78)))->get_condition() & 0x20) {
            handle_action((s32)(arg1));
            return;
        }
        ((s32 (*)(void *, s32))request_technique_cast__10TNpcPlayerFPvi)(this, 0x11);
        break;
    }
}

void TNpcPlayer::change_ai_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    *(u32 *)((s8 *)arg0 + 0x7C) = arg1;
    *(s32 *)((s8 *)arg0 + 0x80) = (s32) (*(s32 *)((s8 *)arg0 + 0x80) & 0xFFFFEFFF);
    switch (arg1) {
    case 0:
        *(s32 *)((s8 *)arg0 + 0x80) = (s32) (*(s32 *)((s8 *)arg0 + 0x80) & 0xFFFFFFCF);
        VecCopy__FP3VecPC3Vec((void *)((void *) ((u8 *)(arg0) + 0xDC)), (int)((void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x78)) + 0x94) + 0x2FC)));
        return;
    case 1:
        *(s32 *)((s8 *)arg0 + 0x80) = (s32) (*(s32 *)((s8 *)arg0 + 0x80) & 0xFFFFFFEF);
        *(s32 *)((s8 *)arg0 + 0x80) = (s32) (*(s32 *)((s8 *)arg0 + 0x80) | 0x20);
        return;
    case 2:
        *(s32 *)((s8 *)arg0 + 0x80) = (s32) (*(s32 *)((s8 *)arg0 + 0x80) & 0xFFFFFFDF);
        *(s32 *)((s8 *)arg0 + 0x80) = (s32) (*(s32 *)((s8 *)arg0 + 0x80) | 0x10);
        return;
    case 8:
        VecCopy__FP3VecPC3Vec((void *)((void *) ((u8 *)(arg0) + 0xDC)), (int)((void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x78)) + 0x94) + 0x2FC)));
        return;
    case 16:
        *(s32 *)((s8 *)arg0 + 0x80) = (s32) (*(s32 *)((s8 *)arg0 + 0x80) & 0xFFFFFFEF);
        *(s32 *)((s8 *)arg0 + 0x80) = (s32) (*(s32 *)((s8 *)arg0 + 0x80) | 0x20);
    default:
        return;
    }
}

void TNpcPlayer::handle_action(s32 arg1) {
    s32 player;
    s32 temp_r3_2;
    s32 temp_r3_3;
    void *temp_r5;
    void *temp_r5_2;
    void *temp_r5_3;

    switch (arg1) {
    case 0:
        player = ((TObjPlayer *)(*(s32 *)((s8 *)(*(void **)((s8 *)this + 0x78)) + 0x94)))->find_inventory_item_id(3, 0);
        if (player != -1) {
            temp_r5 = *(void **)((s8 *)this + 0x78);
            try_send_6x27_use_item(*(s32 *)((s8 *)temp_r5 + 0x94), player, temp_r5);
            *(s32 *)((s8 *)this + 0x80) = (s32) (*(s32 *)((s8 *)this + 0x80) | 0x10000);
        }
        break;
    case 1:
        temp_r3_2 = ((TObjPlayer *)(*(s32 *)((s8 *)(*(void **)((s8 *)this + 0x78)) + 0x94)))->find_inventory_item_id(3, 1);
        if (temp_r3_2 != -1) {
            temp_r5_2 = *(void **)((s8 *)this + 0x78);
            try_send_6x27_use_item(*(s32 *)((s8 *)temp_r5_2 + 0x94), temp_r3_2, temp_r5_2);
            return;
        }
        break;
    case 2:
        temp_r3_3 = ((TObjPlayer *)(*(s32 *)((s8 *)(*(void **)((s8 *)this + 0x78)) + 0x94)))->find_inventory_item_id(3, 6);
        if (temp_r3_3 != -1) {
            temp_r5_3 = *(void **)((s8 *)this + 0x78);
            try_send_6x27_use_item(*(s32 *)((s8 *)temp_r5_3 + 0x94), temp_r3_3, temp_r5_3);
        }
        break;
    }
}

void deliver_partner_chatter(Npc_8014E250 *self) {
    u16 id;
    char *text;
    if (self->state >= 0x19) {
        self->flags &= ~4;
        self->state = 0x19;
        return;
    }
    if (is_any_teammate_in_state__10TObjPlayerFv(self) != 0) {
        return;
    }
    id = get_entity_id(self->owner->obj);
    if (id != 0xFFFF) {
        text = (char *)get_partner_custom_text(self->state, id);
        if (text != 0) {
            TWindowCtrl::open((s32)id, (s32)text, 0x1B);
        } else {
            text = npc_partner_dialogue_state[self->state].text;
            if (text[0] != 0) {
                TWindowCtrl::open((s32)id, (s32)text, 0x1B);
            }
        }
    }
    self->flags &= ~4;
    if (((s32 (*)(void *, s32, s32))npc_counter_reset_if_reached)(self->timer, 0, 0x190) != 0) {
        self->state = 0x19;
    }
}

void TNpcPlayer::request_chatter(u32 arg1) {
    u8 *arg0 = (u8 *)this;
  u32 *new_var;
  int new_var2;
  new_var = (u32 *) (((s8 *) arg0) + 0x24);
  if (((s32) (*((s32 *) (((s8 *) arg0) + 0x84)))) != 0)
  {
    if (arg1 != 4U)
    {
      if (arg1 == 0x11U)
      {
        return;
      }
      goto block_4;
    }
  }
  else
  {
    new_var2 = 0x24;
    block_4:
    reset_partner_counter((s32) (arg0 + 0x5C), 0);
    if (arg1 != ((u32) (*((u32 *) (((s8 *) arg0) + new_var2)))))
    {
      *new_var = arg1;
      *((s32 *) (((s8 *) arg0) + 0x80)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x80))) | 4);
    }
  }
}
}

#pragma push
#pragma fp_contract on
s32 partner_clip_path_point(void *self, f32 *from, f32 *to, f32 *out) {
    Vec_8014E3B0 dir;
    u8 *contact;
    contact = csnVector((s32) from, (s32) to, 0x2100);
    if (contact != NULL) {
        dir.x = to[0] - from[0];
        dir.y = TNpcPlayer__data_805DB1F0;
        dir.z = to[2] - from[2];
        if (TNpcPlayer__data_805DB1F0 != vector_length(&dir)) {
            normalize_vector(&dir);
        }
        VecCopy__FP3VecPC3Vec(out, *(s32 *)((s8 *)contact + 4));
        out[0] = -((TNpcPlayer__data_805DB1F4 * dir.x) - out[0]);
        out[1] = -((TNpcPlayer__data_805DB1F4 * dir.y) - out[1]);
        out[2] = -((TNpcPlayer__data_805DB1F4 * dir.z) - out[2]);
        return 1;
    }
    return 0;
}
#pragma pop
extern "C" {

void calc_box_escape_axis__10TNpcPlayerFv(void *self, Vec_8014E3B0 *a, Vec_8014E3B0 *b, Vec_8014E3B0 *c,
                                          Vec_8014E3B0 *d, Vec_8014E3B0 *pos, Vec_8014E3B0 *axis, f32 *reach) {
    Vec_8014E3B0 point1;
    Vec_8014E3B0 point2;
    Vec_8014E3B0 first;
    Vec_8014E3B0 second;
    Vec_8014E3B0 center1;
    Vec_8014E3B0 center2;
    Line_8014E488 line1;
    Line_8014E488 line2;
    f32 len1;
    f32 len2;
    f32 dist1;
    f32 dist2;
    f32 reach1;
    f32 reach2;

    first.x = a->x - b->x;
    first.y = a->y - b->y;
    first.z = a->z - b->z;
    len1 = vector_length(&first);
    if (len1 != 0.0f) {
        normalize_vector(&first);
    }
    second.x = c->x - d->x;
    second.y = c->y - d->y;
    second.z = c->z - d->z;
    len2 = vector_length(&second);
    if (len2 != 0.0f) {
        normalize_vector(&second);
    }
    line1.p.x = b->x;
    line1.p.y = b->y;
    line1.p.z = b->z;
    line1.d.x = first.x;
    line1.d.y = first.y;
    line1.d.z = first.z;
    dist1 = ((f32 (*)(Vec_8014E3B0 *, Line_8014E488 *, Vec_8014E3B0 *))project_point_onto_line)(pos, &line1, &point1);
    center1.x = 0.5f * (a->x + b->x);
    center1.y = 0.5f * (a->y + b->y);
    center1.z = 0.5f * (a->z + b->z);
    reach1 = (10.0f + 0.5f * len1) - xyz_distance(&center1, &point1);
    if (reach1 < 0.0f) {
        reach1 = 0.5f * len1;
    }
    line2.p.x = d->x;
    line2.p.y = d->y;
    line2.p.z = d->z;
    line2.d.x = second.x;
    line2.d.y = second.y;
    line2.d.z = second.z;
    dist2 = ((f32 (*)(Vec_8014E3B0 *, Line_8014E488 *, Vec_8014E3B0 *))project_point_onto_line)(pos, &line2, &point2);
    center2.x = 0.5f * (a->x + b->x);
    center2.y = 0.5f * (a->y + b->y);
    center2.z = 0.5f * (a->z + b->z);
    reach2 = (10.0f + 0.5f * len2) - xyz_distance(&center2, &point2);
    if (reach2 < 0.0f) {
        reach2 = 0.5f * len2;
    }
    if (dist2 < dist1) {
        *reach = 10.0f + reach1;
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(axis, &first);
    } else if (dist2 == dist1) {
        *reach = 7.0f;
        axis->x = 0.5f * (first.x + second.x);
        axis->y = 0.5f * (first.y + second.y);
        axis->z = 0.5f * (first.z + second.z);
    } else {
        *reach = 10.0f + reach2;
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(axis, &second);
    }
}

#pragma push
#pragma fp_contract on
s32 route_around_object__10TNpcPlayerFv(Self_8014E7A0 *self, Vec_8014E3B0 *out) {
    Info_8014E7A0 info;
    Vec_8014E3B0 perp;
    Vec_8014E3B0 to;
    Vec_8014E3B0 toSelf;
    f32 r;
    fn_8002B630((u8 *)&info, (u8 *)self->f78->shape);
    if (info.type == 0 || info.type == 0 ||
        (info.h <= lbl_805DB1FC && info.type == 1 && info.h == info.w)) {
        Target_8014E7A0 *t = self->f78->obj;
        r = TNpcPlayer__data_805DB204 + info.w;
        to.x = t->pos.x - info.pos.x;
        to.y = 0.0f;
        to.z = t->pos.z - info.pos.z;
        perp.x = to.z;
        perp.y = 0.0f;
        perp.z = -to.x;
        if (TNpcPlayer__data_805DB1F0 != vector_length(&perp)) {
            normalize_vector(&perp);
        }
        toSelf.x = self->pos.x - info.pos.x;
        toSelf.y = TNpcPlayer__data_805DB1F0;
        toSelf.z = self->pos.z - info.pos.z;
        if (TNpcPlayer__data_805DB1F0 != vector_length(&toSelf)) {
            normalize_vector(&toSelf);
        }
        if (vec3_dot(&perp, &toSelf) < TNpcPlayer__data_805DB1F0) {
            perp.x = -perp.x;
            perp.z = -perp.z;
        }
        if (TNpcPlayer__data_805DB1F0 != vector_length(&to)) {
            normalize_vector(&to);
        }
        perp.x += to.x;
        perp.y += to.y;
        perp.z += to.z;
        if (TNpcPlayer__data_805DB1F0 != vector_length(&perp)) {
            normalize_vector(&perp);
        }
        out->x = r * perp.x + info.pos.x;
        out->y = r * perp.y + info.pos.y;
        out->z = r * perp.z + info.pos.z;
        if (self->level > 10) {
            out->x = info.pos.x - r * perp.x;
            out->y = info.pos.y - r * perp.y;
            out->z = info.pos.z - r * perp.z;
        }
    } else {
        Vec_8014E3B0 a = lbl_8043FFB8;
        Vec_8014E3B0 b = lbl_8043FFC4;
        Vec_8014E3B0 c0;
        Vec_8014E3B0 c2;
        Vec_8014E3B0 c1;
        Vec_8014E3B0 c3;
        Vec_8014E3B0 esc;
        Vec_8014E3B0 dir;
        Vec_8014E3B0 axis;
        Vec_8014E3B0 clip;
        Vec_8014E3B0 alt;
        f32 dist;
        a.x *= info.w;
        b.z *= info.h;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, self->f78->rot_y + 0x4000);
        matrix_mult_vec(0, &a, &a);
        matrix_mult_vec(0, &b, &b);
        pop_matrices(1);
        c0.x = info.pos.x + a.x;
        c0.y = info.pos.y + a.y;
        c0.z = info.pos.z + a.z;
        c1.x = info.pos.x - a.x;
        c1.y = info.pos.y - a.y;
        c1.z = info.pos.z - a.z;
        c2.x = info.pos.x + b.x;
        c2.y = info.pos.y + b.y;
        c2.z = info.pos.z + b.z;
        c3.x = info.pos.x - b.x;
        c3.y = info.pos.y - b.y;
        c3.z = info.pos.z - b.z;
        dir.x = self->f74->obj->pos.x - info.pos.x;
        dir.y = self->f74->obj->pos.y - info.pos.y;
        dir.z = self->f74->obj->pos.z - info.pos.z;
        if (TNpcPlayer__data_805DB1F0 != vector_length(&dir)) {
            normalize_vector(&dir);
        }
        calc_box_escape_axis__10TNpcPlayerFv(self, &c0, &c1, &c2, &c3, &self->f78->obj->pos, &axis, &dist);
        VecCopy__FP3VecPC3Vec(&esc, (int) &axis);
        if (vec3_dot(&dir, &esc) < TNpcPlayer__data_805DB1F0) {
            esc.x = -esc.x;
            esc.z = -esc.z;
        }
        r = dist;
        out->x = r * esc.x + self->f78->obj->pos.x;
        out->y = r * esc.y + self->f78->obj->wpos.y;
        out->z = r * esc.z + self->f78->obj->pos.z;
        if (partner_clip_path_point(self, &self->f78->obj->wpos.x, &out->x, &clip.x) != 0) {
            out->x = clip.x;
            out->y = clip.y;
            out->z = clip.z;
        }
        if (self->level > 15) {
            alt.x = esc.z;
            alt.y = TNpcPlayer__data_805DB1F0;
            alt.z = esc.x;
            if (vec3_dot(&dir, &alt) < TNpcPlayer__data_805DB1F0) {
                alt.x = -alt.x;
                alt.z = -alt.z;
            }
            out->x = r * alt.x + self->f78->obj->pos.x;
            out->y = self->f78->obj->wpos.y;
            out->z = r * alt.z + self->f78->obj->pos.z;
        }
    }
    return 1;
}
#pragma pop

#pragma push
#pragma fp_contract on
void partner_compute_stalled_detour(u8 *self, Vec_8014E3B0 *from, Vec_8014E3B0 *to, Vec_8014E3B0 *d, Vec_8014E3B0 *out) {
    Vec_8014E3B0 dir;
    Vec_8014E3B0 save;
    Vec_8014E3B0 a;
    Vec_8014E3B0 b;
    Vec_8014E3B0 diff;
    dir.x = -d->x;
    dir.y = TNpcPlayer__data_805DB1F0;
    dir.z = -d->z;
    if (TNpcPlayer__data_805DB1F0 != vector_length(&dir)) {
        normalize_vector(&dir);
    }
    VecCopy__FP3VecPC3Vec(&save, (int)&dir);
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, 0x4000);
    matrix_mult_vec(0, &dir, &a);
    pop_matrices(1);
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, -0x4000);
    matrix_mult_vec(0, &dir, &b);
    pop_matrices(1);
    diff.x = to->x - from->x;
    diff.y = TNpcPlayer__data_805DB1F0;
    diff.z = to->z - from->z;
    if (TNpcPlayer__data_805DB1F0 != vector_length(&diff)) {
        normalize_vector(&diff);
    }
    if (vec3_dot(&diff, &a) > TNpcPlayer__data_805DB1F0) {
        VecCopy__FP3VecPC3Vec(&dir, (int)&b);
    } else {
        VecCopy__FP3VecPC3Vec(&dir, (int)&a);
    }
    if ((s8)self[0x8C] >= 0x14) {
        out->x = -((TNpcPlayer__data_805DB204 * dir.x) - from->x);
        out->y = from->y;
        out->z = -((TNpcPlayer__data_805DB204 * dir.z) - from->z);
    } else {
        out->x = TNpcPlayer__data_805DB204 * dir.x + from->x;
        out->y = from->y;
        out->z = TNpcPlayer__data_805DB204 * dir.z + from->z;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
s32 partner_route_around_wall(Self_8014EE98 *self, Vec_8014E3B0 *from, Vec_8014E3B0 *to, Vec_8014E3B0 *d, Vec_8014E3B0 *out, Vec_8014E3B0 *out2) {
    Line_8014EE98 line;
    Vec_8014E3B0 dir;
    Vec_8014E3B0 perp;
    Vec_8014E3B0 hit;
    Vec_8014E3B0 tmp;
    Vec_8014E3B0 v;
    f32 len;
    f32 s;
    dir.x = to->x - from->x;
    dir.y = TNpcPlayer__data_805DB1F0;
    dir.z = to->z - from->z;
    len = vector_length(&dir);
    if (TNpcPlayer__data_805DB1F0 != len) {
        normalize_vector(&dir);
    }
    perp.x = d->z;
    perp.y = TNpcPlayer__data_805DB1F0;
    perp.z = -d->x;
    if (vec3_dot(&dir, &perp) < TNpcPlayer__data_805DB1F0) {
        perp.x = -perp.x;
        perp.z = -perp.z;
    }
    line.p.x = self->f78->obj->pos.x;
    line.p.y = self->f78->obj->pos.y;
    line.p.z = self->f78->obj->pos.z;
    line.d.x = perp.x;
    line.d.y = TNpcPlayer__data_805DB1F0;
    line.d.z = perp.z;
    project_point_onto_line(self->fDC, &line, &hit);
    s = lbl_805DB208 * len;
    if (s <= TNpcPlayer__data_805DB204) {
        s = TNpcPlayer__data_805DB204;
    }
    out->x = perp.x * s + from->x;
    out->y = from->y;
    out->z = perp.z * s + from->z;
    VecCopy__FP3VecPC3Vec(&tmp, (int)&self->f74->obj->pos);
    if (csnVector((s32)((s32)&tmp), (s32)((s32)&hit), 0x2100) != 0) {
        hit.x = TNpcPlayer__data_805DB20C * perp.x + hit.x;
        hit.z = TNpcPlayer__data_805DB20C * perp.z + hit.z;
        return 0;
    }
    v.x = self->f74->obj->pos.x - hit.x;
    v.z = self->f74->obj->pos.z - hit.z;
    v.y = TNpcPlayer__data_805DB1F0;
    if (TNpcPlayer__data_805DB1F0 != vector_length(&v)) {
        normalize_vector(&v);
    }
    out2->x = TNpcPlayer__data_805DB20C * perp.x + hit.x;
    out2->z = TNpcPlayer__data_805DB20C * perp.z + hit.z;
    out2->y = TNpcPlayer__data_805DB1F0;
    return 1;
}
}
#pragma pop

s32 partner_find_wall_segment(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *temp_r3;
    temp_r3 = (u8 *)(csnVector(arg1, arg2, 0x2100));
    if (temp_r3 != NULL) {
        VecCopy__FP3VecPC3Vec((void *) (arg3), (int) (*(s32 *)((s8 *)temp_r3 + 4)));
        VecCopy__FP3VecPC3Vec((void *) (arg4), (int) (*(s32 *)((s8 *)temp_r3 + 4) + 0xC));
        return 1;
    }
    return 0;
}

s32 partner_probe_obstacles(View_8014F140 *view) {
    s32 i;
    Actor_8014F140 *actor;
    Contact_8014F140 *contact;
    Probe_8014F140 *probe;
    probe = view->probe;
    if (probe == NULL) {
        return 0;
    }
    VecCopy__FP3VecPC3Vec(probe->pos38, (int)(*(s32 *)((s8 *)view + 0x94) + 0x38));
    view->probe->field_0x60 = view->field_0x98;
    for (i = TLobby::get_game_mode(); i < TLobby::get_game_mode() + TObjEneDD::get_enemy_count() + ((s32 (*)(void))get_registered_object_count)(); i++) {
        actor = (Actor_8014F140 *)get_player_data__10TObjPlayerFi(i);
        if ((actor != NULL) && !(actor->flags30 & 0x80000000)) {
            contact = (Contact_8014F140 *)((TUnk_804AF8A0 *)((u8 *)view->probe))->find_actor_body_contact((u8 *)actor, (f32)lbl_805DB210);
            if (contact != NULL) {
                if (actor->flags30 & 0x40000000) {
                    if (!(contact->flags18 & 8) && !(contact->flags18 & 0x100) && !(contact->flags18 & 0x200)) {
                        fn_8002B630((u8 *)view->hit_d8, (u8 *)contact);
                        view->field_0x104 = actor->field_0x60;
                        view->flags8c |= 0x20;
                        return 1;
                    }
                } else if (actor->flags30 & 0x20000000) {
                    if (!(contact->flags18 & 8) && !(contact->flags18 & 0x100) && !(contact->flags18 & 0x200)) {
                        view->flags8c |= 0x80;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

s32 partition_sort_entries__10TNpcPlayerFiPvii(s32 self, Ent_8014F28C *a, s32 lo, s32 hi) {
    Ent_8014F28C tmp;
    f32 pivot;
    s32 i;
    s32 j;

    j = hi;
    i = lo - 1;
    pivot = a[hi].key;
    for (;;) {
        while (a[++i].key < pivot) {
        }
        while (i < --j && pivot < a[j].key) {
        }
        if (i >= j || i >= 10 || j >= 10) {
            break;
        }
        ((s32 (*)(s32, Ent_8014F28C *, Ent_8014F28C *))copy_transform_second__10TNpcPlayerFPvPvPv)(self, &a[i], &tmp);
        ((s32 (*)(s32, Ent_8014F28C *, Ent_8014F28C *))copy_transform_second__10TNpcPlayerFPvPvPv)(self, &a[j], &a[i]);
        ((s32 (*)(s32, Ent_8014F28C *, Ent_8014F28C *))copy_transform_second__10TNpcPlayerFPvPvPv)(self, &tmp, &a[j]);
    }
    ((s32 (*)(s32, Ent_8014F28C *, Ent_8014F28C *))copy_transform_second__10TNpcPlayerFPvPvPv)(self, &a[i], &tmp);
    ((s32 (*)(s32, Ent_8014F28C *, Ent_8014F28C *))copy_transform_second__10TNpcPlayerFPvPvPv)(self, &a[hi], &a[i]);
    ((s32 (*)(s32, Ent_8014F28C *, Ent_8014F28C *))copy_transform_second__10TNpcPlayerFPvPvPv)(self, &tmp, &a[hi]);
    return i;
}

void TNpcPlayer::quick_sort(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;

    if (arg2 < arg3) {
        temp_r3 = ((s32 (*)(void))partition_sort_entries__10TNpcPlayerFiPvii)();
        TNpcPlayer::quick_sort((s32)(arg0), (s32)(arg1), (s32)(arg2), (s32)(temp_r3 - 1));
        TNpcPlayer::quick_sort((s32)(arg0), (s32)(arg1), (s32)(temp_r3 + 1), (s32)(arg3));
    }
}

s32 find_parts_in_range__10TNpcPlayerFPvPvif(View_8014F424 *view, void *pos, s32 id, f32 range) {
    Actor_8014F424 *actor;
    s32 found;
    s32 i;
    f32 d;
    s32 j;

    view->count = 0;
    found = 0;
    for (j = 0; j < 10; j++) {
        view->c[j].id = 0xFFFF;
        view->c[j].dist = TNpcPlayer__data_805DB1F0;
    }
    actor = find_entity_by_id(id);
    if (is_alive__9TObjEneDDFv(actor) != 0) {
        range = range * range;
        for (i = 0; i < actor->ncols; i++) {
            if (actor->cols == 0) {
                break;
            }
            d = horizontal_distance_squared(pos, actor->cols + i * 0x2C + 0x1C);
            if (d < range) {
                found = 1;
                view->c[view->count].id = (u16)get_entity_id(actor);
                view->c[view->count].dist = d;
                view->c[view->count].idx = i;
                if (view->count >= 9) {
                    break;
                }
                view->count++;
            }
        }
    }
    TNpcPlayer::quick_sort((s32)view, (s32)&view->c[0], 0, view->count - 1);
    return found;
}

s32 scan_nearby_enemies__10TNpcPlayerFPvPvf(View_8014F57C *view, void *pos, f32 range) {
    f32 origin[3];
    Actor_8014F57C *actor;
    s32 found;
    s32 i;
    s32 c;
    s32 j;
    f32 d;
    found = 0;
    ((TUnk_804B9870 *)(view->f94))->get_stat_by_key_state();
    VecCopy__FP3VecPC3Vec(origin, (int)pos);
    view->count = 0;
    for (j = 0; j < 10; j++) {
        view->c[j].id = 0xFFFF;
        view->c[j].dist = TNpcPlayer__data_805DB1F0;
    }
    i = TLobby::get_game_mode();
    range = range * range;
    for (; i < TLobby::get_game_mode() + TObjEneDD::get_enemy_count(); i++) {
        actor = (Actor_8014F57C *)get_player_data__10TObjPlayerFi(i);
        if (is_active__12TTecReverserFv(actor) == 0 || !(actor->flags30 & 0x20000000)) {
            continue;
        }
        for (c = 0; c < actor->ncols; c++) {
            if (actor->cols == 0) {
                break;
            }
            if (!(actor->cols[c].flags & 0x8000)) {
                continue;
            }
            d = horizontal_distance_squared(origin, actor->cols[c].pos);
            if (d < range) {
                found = 1;
                view->c[view->count].id = (u16)get_entity_id(actor);
                view->c[view->count].dist = d;
                view->c[view->count].idx = c;
                if (view->count >= 9) {
                    break;
                }
                view->count++;
            }
        }
    }
    TNpcPlayer::quick_sort((s32)view, (s32)&view->c[0], 0, view->count - 1);
    return found;
}

bool is_target_line_clear__10TNpcPlayerFPvUs(u8 *arg0, u16 arg1) {
    Stack_8014F728 stack;
    u8 *temp_r3;
    VecCopy__FP3VecPC3Vec((void *)((void *) (&stack.sp8)), (int)((void *) (find_active_entity_by_id((void *) (arg1)) + 0x2FC)));
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x94));
    stack.spC = *(f32 *)((s8 *)temp_r3 + 0x300);
    return ((s32)csnVector((s32)((void *) (temp_r3 + 0x2FC)), (s32)((void *) (&stack.sp8)), 0x2100)) == 0;
}

void *TNpcPlayer::dt(s16 arg1) {
    if (this != NULL) {
        if ((u32) *(u32 *)((s8 *)this + 0xA8) != 0U) {
            free_collision_body_parts(*(u32 *)((s8 *)this + 0xA8));
            queue_destruction__7TObjectFv((void *)(*(u32 *)((s8 *)this + 0xA8)));
            *(u32 *)((s8 *)this + 0xA8) = 0U;
        }
        if (arg1 > 0) {
            ::operator delete(this);
        }
    }
    return this;
}

#pragma push
#pragma fp_contract on
s32 refresh_npc_view_actor_lost(void *arg0) {
    u32 v;
    *(u32 *)((s8 *)arg0 + 0x94) = (u32)get_player_by_client_id(*(u16 *)((s8 *)arg0 + 0x8A));
    v = *(u32 *)((s8 *)arg0 + 0x94);
    if (v == 0U) {
        return 1;
    }
    return (u32) __cntlzw(((TObject *)v)->all_parents_unqueued_for_destruction()) >> 5;
}
#pragma pop

Npc_8014F844 *init_ai_state__10TNpcPlayerFPvi(Npc_8014F844 *self, s32 id) {
    s32 i;
    void *p;
    self->f94 = ((s32 (*)(u16))find_entity_by_id)(id);
    self->f9C = TNpcPlayer__data_805DB1F0;
    self->fA0 = TNpcPlayer__data_805DB1F0;
    self->fA4 = TNpcPlayer__data_805DB1F0;
    self->f8C = 0;
    self->f90 = 0;
    self->f8A = id;
    self->f88 = -1;
    self->f84 = 0;
    self->f0 = 0;
    for (i = 0; i < 10; i++) {
        self->recs[i].id = 0xFFFF;
        self->recs[i].dist = TNpcPlayer__data_805DB1F0;
    }
    self->f104 = 0;
    self->fAC = TNpcPlayer__data_805DB1F0;
    self->fB0 = TNpcPlayer__data_805DB1F0;
    self->fB4 = TNpcPlayer__data_805DB20C;
    self->fB8 = lbl_805DB214;
    self->fBC = TNpcPlayer__data_805DB20C;
    self->fC0 = 0;
    self->fC4 = 0x1103;
    p = __nw__7TObjectFUl(0xAC);
    if (p != 0) {
        p = __ct__13TUnk_804AF8A0FP7TObject(p, tl_05);
    }
    self->fA8 = p;
    if (self->fA8 != 0) {
        init_collision_body_parts(self->fA8, &self->fAC, 1);
    }
    self->f7C = 0xFFFF;
    self->f80 = 0xFFFF;
    return self;
}

s32 partner_view_update_hp_change(void *arg0) {
    s16 temp_r0;
    s16 temp_r31;
    s16 temp_r3;
    s16 temp_r4;
    temp_r31 = get_actor_hp((u8 *)(*(s32 *)((s8 *)arg0 + 0x94)));
    temp_r3 = ((TItemProShield *)(*(s32 *)((s8 *)arg0 + 0x94)))->get_field_2b8();
    if (*(s16 *)((s8 *)arg0 + 0x88) <= 0) {
        *(s16 *)((s8 *)arg0 + 0x88) = temp_r31;
        return 0;
    }
    temp_r4 = *(s16 *)((s8 *)arg0 + 0x88);
    temp_r0 = (s16)(temp_r4 - temp_r31);
    if (temp_r4 >= (s32) (temp_r31 - 1)) {
        if ((f32) temp_r0 > (lbl_805DB21C * (f32) temp_r3)) {
            *(s32 *)((s8 *)arg0 + 0x90) = (s32) (*(s32 *)((s8 *)arg0 + 0x90) | 0x40);
        } else if ((f32) temp_r0 > ((*(const f32 *)&TNpcPlayer__data_805DB218) * (f32) temp_r3)) {
            *(s32 *)((s8 *)arg0 + 0x90) = (s32) (*(s32 *)((s8 *)arg0 + 0x90) | 0x80);
        } else if ((f32) temp_r0 > (lbl_805DB220 * (f32) temp_r3)) {
            *(s32 *)((s8 *)arg0 + 0x90) = (s32) (*(s32 *)((s8 *)arg0 + 0x90) | 0x100);
        }
    } else {
        *(s32 *)((s8 *)arg0 + 0x90) = (s32) (*(s32 *)((s8 *)arg0 + 0x90) | 0x200);
    }
    *(s16 *)((s8 *)arg0 + 0x88) = temp_r31;
    return temp_r0 ? 1 : 0;
}

s32 partner_view_update_conditions(u8 *arg0) {
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f31;
    f32 temp_f31_2;
    s32 temp_r3;
    s32 var_r31;
    var_r31 = 0;
    temp_f31 = (f32) get_actor_hp(*(u8 **)((s8 *)arg0 + 0x94));
    temp_f1 = temp_f31 / (f32) ((TItemProShield *)(*(u8 **)((s8 *)arg0 + 0x94)))->get_field_2b8();
    if (*(s32 *)((s8 *)arg0 + 0x8C) & 2) {
        if (temp_f1 <= lbl_805DB224) {
            var_r31 = 1;
            *(s32 *)((s8 *)arg0 + 0x90) = (s32) (*(s32 *)((s8 *)arg0 + 0x90) | 8);
            *(s32 *)((s8 *)arg0 + 0x8C) = (s32) (*(s32 *)((s8 *)arg0 + 0x8C) | 4);
        }
        if (temp_f1 <= lbl_805DB228) {
            var_r31 = 1;
            *(s32 *)((s8 *)arg0 + 0x90) = (s32) (*(s32 *)((s8 *)arg0 + 0x90) | 0x1000);
        }
    } else if (temp_f1 <= lbl_805DB228) {
        var_r31 = 1;
        *(s32 *)((s8 *)arg0 + 0x90) = (s32) (*(s32 *)((s8 *)arg0 + 0x90) | 8);
        *(s32 *)((s8 *)arg0 + 0x8C) = (s32) (*(s32 *)((s8 *)arg0 + 0x8C) | 4);
    }
    if (temp_f1 <= TNpcPlayer__data_805DB22C) {
        var_r31 = 1;
        *(s32 *)((s8 *)arg0 + 0x90) = (s32) (*(s32 *)((s8 *)arg0 + 0x90) | 0x800);
        *(s32 *)((s8 *)arg0 + 0x8C) = (s32) (*(s32 *)((s8 *)arg0 + 0x8C) | 4);
    }
    temp_r3 = *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x94)) + 0x30);
    if ((temp_r3 & 1) || (temp_r3 & 2) || (temp_r3 & 0x10)) {
        var_r31 = 1;
        *(s32 *)((s8 *)arg0 + 0x90) = (s32) (*(s32 *)((s8 *)arg0 + 0x90) | 2);
        *(s32 *)((s8 *)arg0 + 0x8C) = (s32) (*(s32 *)((s8 *)arg0 + 0x8C) | 4);
    }
    temp_f31_2 = (f32) get_actor_tp(*(u8 **)((s8 *)arg0 + 0x94));
    temp_f2 = (f32) obj_getS16_2BA(*(u8 **)((s8 *)arg0 + 0x94));
    if (((temp_f31_2 / temp_f2) <= TNpcPlayer__data_805DB218) && (TNpcPlayer__data_805DB1F0 != temp_f2)) {
        *(s32 *)((s8 *)arg0 + 0x8C) = (s32) (*(s32 *)((s8 *)arg0 + 0x8C) | 4);
        *(s32 *)((s8 *)arg0 + 0x90) = (s32) (*(s32 *)((s8 *)arg0 + 0x90) | 0x10);
    }
    return var_r31;
}

s32 try_update_target_flag__10TNpcPlayerFPvi(void *arg0, s32 arg1) {
    s32 temp_r6;

    temp_r6 = *(s32 *)((s8 *)arg0 + 0x94);
    if (((s32 (*)(void *, s32, s32, s32))find_parts_in_range__10TNpcPlayerFPvPvif)(arg0, temp_r6 + 0x38, arg1, temp_r6) != 0) {
        *(s32 *)((s8 *)arg0 + 0x8C) = (s32) (*(s32 *)((s8 *)arg0 + 0x8C) | 2);
        return 1;
    }
    return 0;
}

s32 check_and_set_reached__10TNpcPlayerFPv(void *arg0) {
    if (((s32 (*)(void *, s32))scan_nearby_enemies__10TNpcPlayerFPvPvf)(arg0, *(s32 *)((s8 *)arg0 + 0x94) + 0x38) != 0) {
        *(s32 *)((s8 *)arg0 + 0x8C) = (s32) (*(s32 *)((s8 *)arg0 + 0x8C) | 2);
        return 1;
    }
    return 0;
}

s32 TNpcPlayer::try_attack(s32 arg1, s32 arg2) {
    switch (arg1) {
    case 0:
        if ((arg2 != 0) && (((TObjPlayer *)(*(s32 *)((s8 *)this + 0x94)))->find_inventory_item_id(3, 0) != -1)) {
            *(s32 *)((s8 *)this + 0x90) = (s32) (*(s32 *)((s8 *)this + 0x90) | 0x20);
            return 1;
        }
        if (TObjPlayer::try_camera_action((s32)(*(s32 *)((s8 *)this + 0x94)), 0xF) != 0) {
            return 1;
        }
        break;
    case 1:
        if (((TObjPlayer *)(*(s32 *)((s8 *)this + 0x94)))->find_inventory_item_id(3, 1) != -1) {
            *(s32 *)((s8 *)this + 0x90) = (s32) (*(s32 *)((s8 *)this + 0x90) | 0x20);
            return 1;
        }
        break;
    case 2:
        if (TObjPlayer::try_camera_action((s32)(*(s32 *)((s8 *)this + 0x94)), 0x10) != 0) {
            return 1;
        }
        break;
    case 3:
        if (((TObjPlayer *)(*(s32 *)((s8 *)this + 0x94)))->find_inventory_item_id(3, 6) != -1) {
            *(s32 *)((s8 *)this + 0x90) = (s32) (*(s32 *)((s8 *)this + 0x90) | 0x20);
            return 1;
        }
        if (TObjPlayer::try_camera_action((s32)(*(s32 *)((s8 *)this + 0x94)), 0x11) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

s32 partner_view_check_moved(u8 *arg0) {
    Stack_8014FEAC stack;
    f32 temp_f1;
    u8 *temp_r31;
    u8 *temp_r3;
    temp_r31 = (u8 *)(((TCameraCtrl *)(*(s32 *)((s8 *)arg0 + 0x94)))->get_target_ptr());
    temp_r3 = (u8 *)(((TObjPlayer *)(*(s32 *)((s8 *)arg0 + 0x94)))->get_position_ptr());
    if ((temp_r31 == NULL) || (temp_r3 == NULL)) {
        return 0;
    }
    stack.sp8 = *(f32 *)((s8 *)temp_r3 + 0) - *(f32 *)((s8 *)temp_r31 + 0);
    stack.spC = *(f32 *)((s8 *)temp_r3 + 4) - *(f32 *)((s8 *)temp_r31 + 4);
    temp_f1 = *(f32 *)((s8 *)temp_r3 + 8);
    stack.sp10 = temp_f1 - *(f32 *)((s8 *)temp_r31 + 8);
    if (((f32 (*)(void *, f32))vector_length)((void *) (&stack.sp8), (f32) (temp_f1)) > lbl_805DB230) {
        *(s32 *)((s8 *)arg0 + 0x8C) = (s32) (*(s32 *)((s8 *)arg0 + 0x8C) | 1);
        return 1;
    }
    return 0;
}

#pragma push
#pragma fp_contract on

s32 TNpcPlayer::check_movement_progress() {
    u8 *arg0 = (u8 *)this;
    s8 temp_r3;
    if (((f32 (*)(void *, void *))horizontal_distance_squared)((void *) (arg0 + 0xAC), (void *) (arg0 + 0xD0)) <= lbl_805DB234) {
        return 0;
    }
    temp_r3 = *(s8 *)((s8 *)arg0 + 0x8C);
    if (temp_r3 > 0x1E) {
        *(u8 *)((s8 *)arg0 + 0x8C) = 0x1EU;
        *(s32 *)((s8 *)arg0 + 0x80) = (s32) (*(s32 *)((s8 *)arg0 + 0x80) | 0x4000);
        if (((s16 (*)(void *, int))get_partner_counter)((void *) (arg0 + 0x5C), 7) == 0) {
            request_chatter(7);
        }
        ((s32 (*)(void *, int))increment_partner_counter)((void *) (arg0 + 0x5C), 7);
        ((s32 (*)(void *, int, int))npc_counter_reset_if_reached)((void *) (arg0 + 0x5C), 7, 0x12C);
        return 0;
    }
    if ((temp_r3 == 0) && (*(s32 *)((s8 *)arg0 + 0x80) & 0x4000)) {
        ((s32 (*)(void *, int))reset_partner_counter)((void *) (arg0 + 0x5C), 7);
        request_chatter(0x18);
        *(s32 *)((s8 *)arg0 + 0x80) = (s32) (*(s32 *)((s8 *)arg0 + 0x80) & 0xFFFFBFFF);
    }
    return 1;
}
#pragma pop

void TNpcPlayer::render() {  }

void TNpcPlayer::init_follow_target() {
    Npc_80150050 *arg0 = (Npc_80150050 *)this;
    Tgt_80150050 *t = arg0->mid->tgt;
    V3_80150050 off = lbl_8043FFAC;
    if (t != NULL) {
        arg0->dst.x = arg0->mid->tgt->pos.x + off.x;
        arg0->dst.y = arg0->mid->tgt->pos.y + off.y;
        arg0->dst.z = arg0->mid->tgt->pos.z + off.z;
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&arg0->pos, &arg0->mid->tgt->pos);
    }
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
s32 needs_movement__10TNpcPlayerFPvPvi(u8 *arg0, void * _w1, int _w2) {
    f32 temp_f1;
    f32 var_f31;
    if (*(s32 *)((s8 *)arg0 + 0x80) & 0x10) {
        return 1;
    }
    var_f31 = lbl_805DB1FC + *(f32 *)((s8 *)arg0 + 0x40);
    if (var_f31 >= lbl_805DB238) {
        var_f31 = lbl_805DB238;
    }
    temp_f1 = ((f32 (*)(void *, void *, int))horizontal_distance_squared)((void *)((void *) ((u8 *)(arg0) + 0xDC)), (void *)((void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x78)) + 0x94) + 0x38)), (int)(_w2));
    *(f32 *)((s8 *)arg0 + 0x88) = temp_f1;
    if (temp_f1 >= (var_f31 * var_f31)) {
        return 1;
    }
    *(s32 *)((s8 *)arg0 + 0x80) = (s32) (*(s32 *)((s8 *)arg0 + 0x80) & 0xFFFFFEFF);
    return 0;
}
#pragma pop

#pragma push
#pragma fp_contract on
void select_path_waypoint__10TNpcPlayerFv(Self_801501A0 *self) {
    Vec_801501A0 midpoint;
    Vec_801501A0 hit;
    Vec_801501A0 route;
    Vec_801501A0 dir;
    Vec_801501A0 normal;
    Actor_801501A0 *actor;
    f32 len;
    f32 half;
    s32 clear;

    actor = self->view->actor;
    dir.x = self->dest.x - actor->anchor.x;
    dir.y = self->dest.y - actor->anchor.y;
    dir.z = self->dest.z - actor->anchor.z;
    len = ((f32 (*)(void *))vector_length)(&dir);
    if (TNpcPlayer__data_805DB1F0 != len) {
        ((s32 (*)(void *))normalize_vector)(&dir);
    }
    actor = self->view->actor;
    half = len * lbl_805DB1F8;
    midpoint.x = half * dir.x + actor->anchor.x;
    midpoint.y = half * dir.y + actor->anchor.y;
    midpoint.z = half * dir.z + actor->anchor.z;
    if (((s32 (*)(void *, Vec_801501A0 *, Vec_801501A0 *, Vec_801501A0 *, Vec_801501A0 *))partner_find_wall_segment)(self, &actor->anchor, &self->dest, &hit, &normal) != 0) {
        Vec_801501A0 shortcut = {0.0f, 0.0f, 0.0f};
        clear = ((s32 (*)(void *, Vec_801501A0 *, Vec_801501A0 *, Vec_801501A0 *, Vec_801501A0 *, Vec_801501A0 *))partner_route_around_wall)(self, &self->view->actor->anchor, &hit, &normal, &route, &shortcut);
        if (!(self->flags & 1)) {
            if (clear != 0) {
                ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->wp, &shortcut);
            } else {
                ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->wp, &route);
                self->wp.y = self->dest.y;
                Vec_801501A0 clipped;
                if (((s32 (*)(void *, Vec_801501A0 *, Vec_801501A0 *, Vec_801501A0 *))partner_clip_path_point)(self, &self->dest, &self->wp, &clipped) != 0) {
                    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->wp, &clipped);
                }
            }
            self->dir.x = self->dest.x - self->wp.x;
            self->dir.y = TNpcPlayer__data_805DB1F0;
            self->dir.z = self->dest.z - self->wp.z;
            if (TNpcPlayer__data_805DB1F0 != ((f32 (*)(void *))vector_length)(&self->dir)) {
                ((s32 (*)(void *))normalize_vector)(&self->dir);
            }
            self->flags |= 1;
        }
        if (clear != 0) {
            self->s90 = 0;
            if (self->flags & 2) {
                Vec_801501A0 d1;
                actor = self->view->actor;
                d1.x = self->target.x - actor->pos.x;
                d1.y = TNpcPlayer__data_805DB1F0;
                d1.z = self->target.z - actor->pos.z;
                if (((f32 (*)(void *))vector_length)(&d1) <= lbl_805DB208) {
                    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->target, &shortcut);
                    self->flags &= ~2;
                }
            } else {
                ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->target, &shortcut);
            }
        } else if (self->flags & 2) {
            Vec_801501A0 d2;
            actor = self->view->actor;
            d2.x = self->target.x - actor->pos.x;
            d2.y = TNpcPlayer__data_805DB1F0;
            d2.z = self->target.z - actor->pos.z;
            if (((f32 (*)(void *))vector_length)(&d2) <= TNpcPlayer__data_805DB20C) {
                Vec_801501A0 clipped2;
                if (((s32 (*)(void *, Vec_801501A0 *, Vec_801501A0 *, Vec_801501A0 *))partner_clip_path_point)(self, &self->view->actor->anchor, &route, &clipped2) != 0) {
                    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->target, &clipped2);
                } else {
                    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->target, &route);
                }
                self->flags &= ~2;
                self->s90 = 0;
            }
            self->s90++;
            if (self->s90 >= 100) {
                self->s90 = 100;
            }
        } else {
            Vec_801501A0 d3;
            self->s90 = 0;
            actor = self->view->actor;
            d3.x = self->target.x - actor->pos.x;
            d3.y = TNpcPlayer__data_805DB1F0;
            d3.z = self->target.z - actor->pos.z;
            self->target.x = self->wp.x;
            self->target.y = self->wp.y;
            self->target.z = self->wp.z;
            if (((f32 (*)(void *))vector_length)(&d3) < TNpcPlayer__data_805DB23C) {
                self->s90 = 0;
                self->target.x = lbl_805DB238 * self->dir.x + self->wp.x;
                self->target.y = lbl_805DB238 * self->dir.y + self->wp.y;
                self->target.z = lbl_805DB238 * self->dir.z + self->wp.z;
                self->flags |= 2;
                self->flags &= ~1;
            }
        }
        return;
    }
    if (((TNpcPlayer *)(self->view))->get_action_state() & 0x20) {
        if (route_around_object__10TNpcPlayerFv((Self_8014E7A0 *)(self), (Vec_8014E3B0 *)(&route)) != 0 && self->s8c < 30) {
            ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->target, &route);
        } else {
            if (self->s8d > 15) {
                self->s8c = 0;
            }
            ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->target, &midpoint);
        }
    } else if (((TNpcPlayer *)(self->view))->get_action_state() & 0x80) {
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->target, &midpoint);
    } else if (self->s8c >= 15 && self->s8c < 30) {
        Vec_801501A0 d4;
        Vec_801501A0 detour;
        View_801501A0 *view = self->view;
        actor = view->actor;
        d4.x = actor->pos.x - view->v9c.x;
        d4.y = actor->pos.y - view->v9c.y;
        d4.z = actor->pos.z - view->v9c.z;
        ((void (*)(void *, Vec_801501A0 *, Vec_801501A0 *, Vec_801501A0 *, Vec_801501A0 *))partner_compute_stalled_detour)(self, &actor->pos, &self->dest, &d4, &detour);
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->target, &detour);
    } else {
        if (self->s8d > 15) {
            self->s8c = 0;
        }
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->target, &midpoint);
    }
    self->flags &= ~1;
    self->s90 = 0;
}
#pragma pop

#pragma push
#pragma fp_contract on
void partner_observe_surroundings(TNpcPlayer *npc_player) {
    f32 temp_f3;
    s32 temp_r3_2;
    s32 temp_r5;
    u8 *temp_r3;
    u8 *temp_r3_3;
    temp_r5 = *(s32 *)((s8 *)(*(u8 **)((s8 *)npc_player + 0x74)) + 0x94);
    *(f32 *)((s8 *)npc_player + 0x58) = ((f32 (*)(void *, void *, int))horizontal_distance_squared)((void *) (temp_r5 + 0x38), (void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)npc_player + 0x78)) + 0x94) + 0x38), (int) (temp_r5));
    if ((s32) *(s32 *)((s8 *)npc_player + 0x84) != 0) {
        ((s32 (*)(void *, void *, f32))try_update_target_flag__10TNpcPlayerFPvi)((void *) (*(u8 **)((s8 *)npc_player + 0x78)), (void *) (get_npc_type__10TNpcPlayerFPv((void *) (*(u8 **)((s8 *)npc_player + 0x74)))), (f32) (*(f32 *)((s8 *)npc_player + 0x38)));
    } else {
        ((s32 (*)(s32, f32))check_and_set_reached__10TNpcPlayerFPv)((s32)((void *) (*(u8 **)((s8 *)npc_player + 0x78))), (f32) (*(f32 *)((s8 *)npc_player + 0x38)));
    }
    ((s32 (*)(s32))partner_view_update_conditions)((s32)((void *) (*(u8 **)((s8 *)npc_player + 0x78))));
    temp_f3 = *(f32 *)((s8 *)npc_player + 0xDC);
    temp_r3 = (u8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)npc_player + 0x78)) + 0x94));
    *(s32 *)((s8 *)(*(u8 **)((s8 *)npc_player + 0x78)) + 0x98) = (s32) (lbl_8043FFD8 * atan2_float((int) (temp_r3), (f32) (temp_f3 - *(f32 *)((s8 *)temp_r3 + 0x38)), (f32) (*(f32 *)((s8 *)npc_player + 0xE4) - *(f32 *)((s8 *)temp_r3 + 0x40)), (f32) (temp_f3)));
    ((s32 (*)(void *))partner_probe_obstacles)((void *) (*(u8 **)((s8 *)npc_player + 0x78)));
    if (partner_view_update_hp_change((void *) (*(u8 **)((s8 *)npc_player + 0x78))) != 0) {
        if (((TNpcPlayer *)(*(u8 **)((s8 *)npc_player + 0x78)))->get_condition() & 0x40) {
            npc_player->request_chatter(0xE);
        } else if (((TNpcPlayer *)(*(u8 **)((s8 *)npc_player + 0x78)))->get_condition() & 0x80) {
            npc_player->request_chatter(0xF);
        } else if (((TNpcPlayer *)(*(u8 **)((s8 *)npc_player + 0x78)))->get_condition() & 0x200) {
            if ((u32) *(u32 *)((s8 *)npc_player + 0x7C) != 8U) {
                temp_r3_2 = *(s32 *)((s8 *)npc_player + 0x80);
                if (temp_r3_2 & 0x10000) {
                    *(s32 *)((s8 *)npc_player + 0x80) = (s32) (temp_r3_2 & 0xFFFEFFFF);
                } else {
                    npc_player->request_chatter(0x11);
                }
            }
        } else {
            npc_player->request_chatter(0x10);
        }
    }
    if (((s32)((s32 (*)(s32))partner_view_check_moved)((s32)((void *) (*(u8 **)((s8 *)npc_player + 0x78))))) == 0) {
        if ((u32) *(u32 *)((s8 *)npc_player + 0x7C) == 1U) {
            if (((TNpcPlayer *)(*(u8 **)((s8 *)npc_player + 0x78)))->get_action_state() & 0x80) {
                *(u8 *)((s8 *)npc_player + 0x8C) = 0U;
                *(u8 *)((s8 *)npc_player + 0x8D) = 0U;
                return;
            }
            *(u8 *)((s8 *)npc_player + 0x8D) = (u8) (*(u8 *)((s8 *)npc_player + 0x8D) + 1);
            if ((s8) *(u8 *)((s8 *)npc_player + 0x8D) > 0x1E) {
                *(u8 *)((s8 *)npc_player + 0x8D) = 0x1EU;
            }
            *(u8 *)((s8 *)npc_player + 0x8C) = (u8) (*(u8 *)((s8 *)npc_player + 0x8C) + 1);
        }
    } else {
        temp_r3_3 = (u8 *)(*(u8 **)((s8 *)npc_player + 0x78));
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((void *) (temp_r3_3 + 0x9C), (void *) (*(u8 **)((s8 *)temp_r3_3 + 0x94) + 0x44));
        *(u8 *)((s8 *)npc_player + 0x8C) = 0U;
        *(u8 *)((s8 *)npc_player + 0x8D) = 0U;
    }
}
#pragma pop

void TNpcPlayer::update_condition_flags() {
    u8 *arg0 = (u8 *)this;
    ((s32 (*)(s32))partner_view_check_moved)(*(s32 *)((s8 *)arg0 + 0x74));
    ((s32 (*)(s32))partner_view_update_conditions)(*(s32 *)((s8 *)arg0 + 0x74));
    if (((TNpcPlayer *)(*(s32 *)((s8 *)arg0 + 0x74)))->get_condition() & 2) {
        if (((s16 (*)(void *, int))get_partner_counter)(arg0 + 0x5C, 0xA) == 0) {
            request_chatter(9);
        }
        ((s32 (*)(void *, s32))increment_partner_counter)(arg0 + 0x5C, 0xA);
    } else {
        ((s32 (*)(void *, s32))reset_partner_counter)(arg0 + 0x5C, 0xA);
    }
    if (((s32 (*)(s32, f32))check_and_set_reached__10TNpcPlayerFPv)(*(s32 *)((s8 *)arg0 + 0x74), lbl_805DB240) != 0) {
        if (((TNpcPlayer *)(*(s32 *)((s8 *)arg0 + 0x74)))->get_condition() & 8) {
            if (((s16 (*)(void *, int))get_partner_counter)(arg0 + 0x5C, 9) == 0) {
                request_chatter(0xC);
            }
            ((s32 (*)(void *, s32))increment_partner_counter)(arg0 + 0x5C, 8);
            ((s32 (*)(void *, int, int))npc_counter_reset_if_reached)(arg0 + 0x5C, 9, 0x2BC);
            return;
        }
        ((s32 (*)(void *, s32))reset_partner_counter)(arg0 + 0x5C, 9);
    }
}

void TNpcPlayer::init_state() {

    ((TNpcPlayer *)(*(s32 *)((s8 *)this + 0x74)))->reset_fields_8c();
    ((TNpcPlayer *)(*(s32 *)((s8 *)this + 0x78)))->reset_fields_8c();
    switch (*(s32 *)((s8 *)this + 0x28)) {
    case 0:
        init_follow_target();
        *(s32 *)((s8 *)this + 0x28) = 1;
    case 1:
        return;
    }
}

void request_technique_cast__10TNpcPlayerFPvi(Npc_80150A34 *self, s32 kind) {
    Msg_80150A34 m;
    u8 *actor;

    ((TNpcPlayer *)(&m))->init_cast_technique_cmd();
    actor = self->p78->actor;
    if (kind == 15 || kind == 16) {
        ((TNpcPlayer *)self)->request_chatter(0x16);
    } else if (kind == 0 || kind == 3 || kind == 6) {
        ((TNpcPlayer *)self)->request_chatter(0x17);
    } else {
        ((TNpcPlayer *)self)->request_chatter(2);
    }
    if (TObjPlayer::try_camera_action((s32)actor, (s32)kind) != 0) {
        m.type = get_npc_type__10TNpcPlayerFPv(self->p78);
        m.kind = kind;
        m.one = 1;
        if (kind == 15 || kind == 16) {
            if (kind == 15) {
                self->flags |= 0x10000;
            }
            m.e = get_cast_technique_level(actor + 0x428, kind);
            ((void (*)(void *, u16))set_type__10TNpcPlayerFPvs)(m.sub, ((s32 (*)(void *))get_npc_type__10TNpcPlayerFPv)(self->p74));
            set_state__10TNpcPlayerFPvs(m.sub, 0);
        } else {
            m.e = get_cast_technique_level(actor + 0x428, kind);
            ((void (*)(void *, u16))set_type__10TNpcPlayerFPvs)(m.sub, ((TNpcPlayer *)(self->p78))->get_npc_state());
            set_state__10TNpcPlayerFPvs(m.sub, TNpcPlayer__sub_801528DC(self->p78));
        }
        ((TNpcPlayer *)(&m))->finalize_and_send_packet();
    }
}

void TNpcPlayer::update_combat_action() {
    static const s32 tbl_80150B90[3][2] = {{0, 1}, {3, 4}, {6, 8}};
    s32 tier;
    s32 alt;
    s32 id;
    Tec_80150B90 *tec;
    u32 fl;
    f32 diff;
    f32 mx;

    if (((u32 (*)(void *))TNpcPlayer__sub_80152978)(((Npc_80150B90 *)this)->f78) == 0xFFFF) {
        return;
    }
    if (((TObjPlayer *)(((Npc_80150B90 *)this)->f78->obj))->can_perform_physical_action() == 0) {
        return;
    }
    if (!(((Npc_80150B90 *)this)->f34 & 0x40) && !(((TNpcPlayer *)((s32)((Npc_80150B90 *)this)->f78))->get_condition() & 0x10)) {
        fl = ((Npc_80150B90 *)this)->f34;
        if (fl & 4) {
            tier = 0;
        } else if (fl & 8) {
            tier = 1;
        } else if (fl & 0x10) {
            tier = 2;
        } else {
            tier = 0;
        }
        if ((((Npc_80150B90 *)this)->f80 & 0x2000) && (((TNpcPlayer *)((s32)((Npc_80150B90 *)this)->f78))->get_condition() & 0x1000)) {
            alt = 1;
        } else {
            alt = 0;
        }
        if (alt == 0) {
            if (fabs_float(TNpcPlayer__data_805DB1F4 * (lbl_805DB244 * (f32)rand())) >
                (*(const f32 *)&TNpcPlayer__data_805DB22C) * (f32)((Npc_80150B90 *)this)->f53) {
                ((TNpcPlayer *)((Npc_80150B90 *)this))->partner_request_physical_attack();
                return;
            }
        }
        id = tbl_80150B90[tier][alt];
        tec = calc_technique_parameters(id, ((Npc_80150B90 *)this)->f50, 0xFFFF);
        diff = (f32)(get_actor_tp((u8 *)(((Npc_80150B90 *)this)->f78->obj)) - tec->f10);
        mx = (f32)obj_getS16_2BA((u8 *)(((Npc_80150B90 *)this)->f78->obj));
        if (diff / mx <= (*(const f32 *)&TNpcPlayer__data_805DB218) && TNpcPlayer__data_805DB1F0 != mx) {
            ((TNpcPlayer *)((Npc_80150B90 *)this))->request_chatter(3);
        }
        ((Npc_80150B90 *)this)->f80 &= ~0x2000;
        if (TObjPlayer::try_camera_action((s32)(((Npc_80150B90 *)this)->f78->obj), (s32)id) != 0) {
            TNpcPlayer__sub_8014DC3C(((Npc_80150B90 *)this), id);
            return;
        }
    }
    ((TNpcPlayer *)((Npc_80150B90 *)this))->partner_request_physical_attack();
}

void TNpcPlayer::send_run_request() {
    Npc_80150DE8 *self = (Npc_80150DE8 *)this;
    Msg_80150DE8 m;
    ((TNpcPlayer *)(&m))->reset_move_state();
    if (self->owner != 0) {
        m.type = get_npc_type__10TNpcPlayerFPv(self->owner);
        m.x = self->x;
        m.z = self->z;
        ((TNpcPlayer *)(&m))->reset_model();
    }
}

void TNpcPlayer::send_walk_request() {
    Npc_80150E44 *self = (Npc_80150E44 *)this;
    Msg_80150E44 m;
    init_6x40_walk_packet(&m);
    if (self->owner != 0) {
        m.type = get_npc_type__10TNpcPlayerFPv(self->owner);
        m.x = self->x;
        m.z = self->z;
        m.flags = 0;
        if (self->owner->obj->flags & 0x100000) {
            m.flags |= 8;
        }
        ((TNpcPlayer *)(&m))->sync_from_lobby();
    }
}

s32 select_recovery_action__10TNpcPlayerFv(Npc_801510F8 *self, s32 arg1) {
    u8 flags = 0;
    Tgt_801510F8 *tgt;
    u8 *ent;
    if (((TNpcPlayer *)(self->f78))->get_action_state() & 4) {
        flags |= 1;
    }
    if (arg1 != 0 && (((TNpcPlayer *)(self->f74))->get_action_state() & 4) && self->f84 == 0) {
        flags |= 2;
    }
    tgt = ((Tgt_801510F8 *)((Tgt_801518A4 * (*)(void *))TNpcPlayer__sub_80152A30)(self->f78));
    if (arg1 != 0 && tgt->a != 0 && (flags & 2)) {
        ((s32 (*)(void *, s32))increment_partner_counter)(self->counters, 5);
        if (((s32 (*)(void *, int, int))npc_counter_reset_if_reached)(self->counters, 5, 0x1E) != 0) {
            ent = ((u8 * (*)(int))find_active_entity_by_id)((u16)tgt->b);
            self->f80 &= ~0x8000;
            if (ent != NULL) {
                if (((f32 (*)(void *, void *))horizontal_distance_squared)(ent + 0x38, self->f78->obj + 0x38) < self->f48 * self->f48) {
                    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(self->dst, ent + 0x38);
                    self->f80 |= 0x8080;
                    return 1;
                }
            }
        }
    }
    if (flags == 3) {
        self->f80 |= 0x200;
        if (((TNpcPlayer *)((s32)self->f78))->get_condition() & 2) {
            if (((TNpcPlayer *)(self->f78))->try_attack(2, 1) != 0) {
                if (((TNpcPlayer *)((s32)self->f78))->get_condition() & 0x20) {
                    self->f92 = 2;
                    return 1;
                }
                if (!(self->f34 & 0x40)) {
                    self->f92 = 2;
                    return 1;
                }
            }
        } else if (((TNpcPlayer *)((s32)self->f78))->get_condition() & 8) {
            if (((TNpcPlayer *)(self->f78))->try_attack(0, 1) != 0) {
                if (((TNpcPlayer *)((s32)self->f78))->get_condition() & 0x20) {
                    self->f92 = 0;
                    return 1;
                }
                if (!(self->f34 & 0x40)) {
                    self->f92 = 0;
                    return 1;
                }
            } else {
                if (((s16 (*)(void *, int))get_partner_counter)(self->counters, 8) == 0) {
                    ((TNpcPlayer *)self)->request_chatter(0x14);
                }
                ((s32 (*)(void *, s32))increment_partner_counter)(self->counters, 8);
                ((s32 (*)(void *, int, int))npc_counter_reset_if_reached)(self->counters, 8, 0x5DC);
            }
        } else if (((TNpcPlayer *)((s32)self->f78))->get_condition() & 0x10) {
            if (((TNpcPlayer *)(self->f78))->try_attack(1, 1) != 0) {
                self->f92 = 1;
                return 1;
            }
        } else {
            flags = 2;
        }
    }
    if (flags == 2) {
        if (((TNpcPlayer *)(self->f78))->get_action_state() & 2) {
            return 0;
        }
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(self->dst, self->f74->obj + 0x2FC);
        self->f80 |= 0x20;
        if (((TNpcPlayer *)((s32)self->f74))->get_condition() & 2) {
            if (((TNpcPlayer *)(self->f78))->try_attack(2, 0) != 0) {
                if (((TNpcPlayer *)((s32)self->f78))->get_condition() & 0x20) {
                    self->f92 = 2;
                    return 1;
                }
                if (!(self->f34 & 0x40)) {
                    self->f92 = 2;
                    return 1;
                }
            }
        } else if (((TNpcPlayer *)((s32)self->f74))->get_condition() & 0x800) {
            if (((TNpcPlayer *)(self->f78))->try_attack(0, 0) != 0) {
                if (((TNpcPlayer *)((s32)self->f78))->get_condition() & 0x20) {
                    self->f92 = 0;
                    return 1;
                }
                if (!(self->f34 & 0x40)) {
                    self->f92 = 0;
                    return 1;
                }
            }
        }
    }
    if (flags == 1) {
        self->f80 |= 0x200;
        if (((TNpcPlayer *)((s32)self->f78))->get_condition() & 2) {
            if (((TNpcPlayer *)(self->f78))->try_attack(2, 1) != 0) {
                if (((TNpcPlayer *)((s32)self->f78))->get_condition() & 0x20) {
                    self->f92 = 2;
                    return 1;
                }
                if (!(self->f34 & 0x40)) {
                    self->f92 = 2;
                    return 1;
                }
            }
        } else if (((TNpcPlayer *)((s32)self->f78))->get_condition() & 8) {
            if (((TNpcPlayer *)(self->f78))->try_attack(0, 1) != 0) {
                if (((TNpcPlayer *)((s32)self->f78))->get_condition() & 0x20) {
                    self->f92 = 0;
                    return 1;
                }
                if (!(self->f34 & 0x40)) {
                    self->f92 = 0;
                    return 1;
                }
            } else {
                if (((s16 (*)(void *, int))get_partner_counter)(self->counters, 8) == 0) {
                    ((TNpcPlayer *)self)->request_chatter(0x14);
                }
                ((s32 (*)(void *, s32))increment_partner_counter)(self->counters, 8);
                ((s32 (*)(void *, int, int))npc_counter_reset_if_reached)(self->counters, 8, 0x5DC);
            }
        } else if (((TNpcPlayer *)((s32)self->f78))->get_condition() & 0x10) {
            if (((TNpcPlayer *)(self->f78))->try_attack(1, 1) != 0) {
                self->f92 = 1;
                return 1;
            }
        }
    }
    return 0;
}

#pragma push
#pragma fp_contract on
s32 TNpcPlayer::calc_follow_goal() {
    u8 *arg0 = (u8 *)this;
    Stack_801515E0 stack;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    u8 *temp_r4;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x84) != 0) {
        if (*(s32 *)((s8 *)arg0 + 0x34) & 0x80) {
            temp_f0 = *(f32 *)((s8 *)arg0 + 0x54);
            if (*(f32 *)((s8 *)arg0 + 0x88) <= (temp_f0 * temp_f0)) {
                temp_r4 = (u8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)arg0 + 0x78)) + 0x94));
                stack.sp8 = *(f32 *)((s8 *)arg0 + 0xDC) - *(f32 *)((s8 *)temp_r4 + 0x38);
                temp_f2 = *(f32 *)((s8 *)arg0 + 0xE4);
                temp_f1 = temp_f2 - *(f32 *)((s8 *)temp_r4 + 0x40);
                stack.spC = TNpcPlayer__data_805DB1F0;
                stack.sp10 = temp_f1;
                if (TNpcPlayer__data_805DB1F0 != ((f32 (*)(void *, int, f32, f32))vector_length)((void *) (&stack.sp8), (int) (temp_r4), (f32) (temp_f1), (f32) (temp_f2))) {
                    ((s32 (*)(void *))normalize_vector)((void *) (&stack.sp8));
                }
                *(f32 *)((s8 *)arg0 + 0xDC) = (f32) -((*(f32 *)((s8 *)arg0 + 0x54) * stack.sp8) - *(f32 *)((s8 *)arg0 + 0xDC));
                *(f32 *)((s8 *)arg0 + 0xE4) = (f32) -((*(f32 *)((s8 *)arg0 + 0x54) * stack.sp10) - *(f32 *)((s8 *)arg0 + 0xE4));
                *(f32 *)((s8 *)arg0 + 0xE0) = (f32) *(f32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)arg0 + 0x78)) + 0x94)) + 0x300);
            } else {
                ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((void *) (arg0 + 0xDC), (void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x74)) + 0x94) + 0x2FC));
            }
        } else {
            ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((void *) (arg0 + 0xDC), (void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x74)) + 0x94) + 0x2FC));
        }
    } else {
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((void *) (arg0 + 0xDC), (void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x74)) + 0x94) + 0x2FC));
    }
    return 1;
}
#pragma pop

s32 TNpcPlayer::choose_attack_target() {
    Npc_80151708 *self = (Npc_80151708 *)this;
    s32 i;
    View_80151708 *view;
    Pos_80151708 *tgt;
    view = (View_80151708 *)((Tgt_801518A4 * (*)(void *))TNpcPlayer__sub_80152A30)(self->f78);
    if (view->count >= 3) {
        self->f80 |= 0x2000;
        ((s32 (*)(void *, s32))increment_partner_counter)(self->f5C, 6);
        if (((s32 (*)(void *, int, int))npc_counter_reset_if_reached)(self->f5C, 6, 100) != 0) {
            if (((TNpcPlayer *)((s32)self->f78))->get_condition() & 8) {
                request_chatter(1);
            } else {
                request_chatter(0);
            }
        }
    } else {
        self->f80 &= ~0x2000;
    }
    if (view->count != 0) {
        for (i = 0; i < view->count; i++) {
            if (((s32 (*)(void *, u32))is_target_line_clear__10TNpcPlayerFPvUs)(self->f78, view->c[i].id) != 0) {
                tgt = (Pos_80151708 *)((u8 * (*)(int))find_active_entity_by_id)((u16)view->c[0].id);
                ((void (*)(void *, u32, s32))TNpcPlayer__sub_80152A34)(self->f78, view->c[i].id, view->c[i].idx);
                self->dst[0] = tgt->x;
                self->dst[1] = self->f78->obj->f300;
                self->dst[2] = tgt->z;
                if (((f32 (*)(void *, void *))horizontal_distance_squared)(self->dst, self->f78->obj->pos) < (TNpcPlayer__data_805DB1F4 + self->f4C) * (TNpcPlayer__data_805DB1F4 + self->f4C)) {
                    self->f80 |= 0x1000;
                }
                self->f80 &= ~0x40;
                return 1;
            }
        }
        request_chatter(8);
        self->f80 |= 0x40;
    }
    return 0;
}

s32 TNpcPlayer::check_return_to_leader() {
    Npc_801518A4 *arg0 = (Npc_801518A4 *)this;
    Tgt_801518A4 *t;
    u8 *o;
    f32 r2;

    t = ((Tgt_801518A4 * (*)(void *))TNpcPlayer__sub_80152A30)(arg0->p78);
    r2 = arg0->f44 * arg0->f44;
    if (((TNpcPlayer *)(arg0->p74))->get_action_state() & 2) {
        arg0->flags &= ~0x100;
        return 0;
    }
    if (((TNpcPlayer *)((s32)arg0->p78))->get_condition() & 8) {
        arg0->flags |= 0x100;
        return 1;
    }
    if (arg0->f58 >= r2) {
        arg0->flags |= 0x100;
        if (t->a != 0) {
            ((s32 (*)(void *, s32))increment_partner_counter)(arg0->a5C, 5);
            if (((s32 (*)(void *, int, int))npc_counter_reset_if_reached)(arg0->a5C, 5, 3) != 0) {
                o = ((u8 * (*)(int))find_active_entity_by_id)((u16)t->b);
                arg0->flags &= ~0x8000;
                if (o != 0) {
                    if (((f32 (*)(void *, void *))horizontal_distance_squared)(o + 0x38, *(u8 **)(arg0->p78 + 0x94) + 0x38) < arg0->f48 * arg0->f48) {
                        arg0->flags |= 0x8080;
                    }
                }
            }
        }
        return 1;
    }
    if (arg0->flags & 0x100) {
        return 1;
    }
    arg0->flags &= ~0x100;
    return 0;
}

s32 TNpcPlayer::update_follow_target() {
    u8 *arg0 = (u8 *)this;
    if (((s32 (*)())needs_movement__10TNpcPlayerFPvPvi)() != 0) {
        ((s32 (*)(void *))select_path_waypoint__10TNpcPlayerFv)((void *) (arg0));
        if (check_movement_progress() != 0) {
            ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((void *) (arg0 + 0xAC), (void *) (arg0 + 0xD0));
            if ((u32) *(u32 *)((s8 *)arg0 + 0x7C) != 2U) {
                change_ai_state(1);
            }
        } else {
            ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((void *) (arg0 + 0xAC), (void *) (*(s32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x78)) + 0x94) + 0x38));
        }
        return 1;
    }
    if ((*(s32 *)((s8 *)arg0 + 0x80) & 0x20) && ((u32) *(u32 *)((s8 *)arg0 + 0x7C) != 8U)) {
        change_ai_state(0);
    }
    return 0;
}

void TNpcPlayer::decide_action() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 var_f31;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    if ((TOKeyMachine01::get_global_state() == 0) || (TOKeyMachine01::get_global_state() == 0x12)) {
        calc_follow_goal();
        change_ai_state(1);
        return;
    }
    switch (*(s32 *)((s8 *)arg0 + 0x1C)) {
    case 0:
        if (((TNpcPlayer *)(*(u8 **)((s8 *)arg0 + 0x78)))->get_action_state() & 2) {
            *(s32 *)((s8 *)arg0 + 0x1C) = 1;
            change_ai_state(0);
            return;
        }
        *(s32 *)((s8 *)arg0 + 0x80) = (s32) (*(s32 *)((s8 *)arg0 + 0x80) & 0xFFFFFEFF);
        if (select_recovery_action__10TNpcPlayerFv((Npc_801510F8 *) (arg0), 1) != 0) {
            temp_r3 = *(s32 *)((s8 *)arg0 + 0x80);
            if (temp_r3 & 0x200) {
                request_chatter(0x13);
                change_ai_state(8);
                return;
            }
            *(s32 *)((s8 *)arg0 + 0x80) = (s32) (temp_r3 & 0xFFFFFDFF);
            if (((f32 (*)(void *, void *))horizontal_distance_squared)((void *) (arg0 + 0xDC), (void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x78)) + 0x94) + 0x38)) < lbl_805DB248) {
                change_ai_state(8);
                return;
            }
            calc_follow_goal();
            change_ai_state(1);
            return;
        }
        calc_follow_goal();
        change_ai_state(1);
        *(s16 *)((s8 *)arg0 + 0x8E) = 0;
        return;
    case 1:
        var_f31 = TNpcPlayer__data_805DB23C;
        if (*(s32 *)((s8 *)arg0 + 0x80) & 0x8000) {
            var_f31 = lbl_805DB24C;
        }
        if ((((TObjPlayer *)(*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x78)) + 0x94)))->can_perform_physical_action() != 0) && (*(s16 *)((s8 *)arg0 + 0x8E) == 0)) {
            temp_f1 = fabs_float(TNpcPlayer__data_805DB1F4 * (lbl_805DB244 * (f32) rand()));
            temp_f0 = TNpcPlayer__data_805DB22C * (f32) *(u8 *)((s8 *)arg0 + 0x52);
            temp_f0 *= var_f31;
            if (temp_f1 < temp_f0) {
                *(s16 *)((s8 *)arg0 + 0x8E) = 0;
            } else {
                *(s16 *)((s8 *)arg0 + 0x8E) = (s16) (TNpcPlayer__data_805DB1F4 * (temp_f1 - temp_f0));
            }
        }
        *(s16 *)((s8 *)arg0 + 0x8E) = (s16) (*(s16 *)((s8 *)arg0 + 0x8E) - 1);
        if (*(s16 *)((s8 *)arg0 + 0x8E) < 0) {
            *(s16 *)((s8 *)arg0 + 0x8E) = 0;
        }
        if ((check_return_to_leader() != 0) && ((s32) *(s32 *)((s8 *)arg0 + 0x84) == 0)) {
            if (select_recovery_action__10TNpcPlayerFv((Npc_801510F8 *) (arg0), 0) != 0) {
                request_chatter(0x13);
                change_ai_state(8);
                *(s32 *)((s8 *)arg0 + 0x80) = (s32) (*(s32 *)((s8 *)arg0 + 0x80) & 0xFFFFFF7F);
            } else {
                temp_r3_2 = *(s32 *)((s8 *)arg0 + 0x80);
                if (temp_r3_2 & 0x80) {
                    *(s32 *)((s8 *)arg0 + 0x80) = (s32) (temp_r3_2 & 0xFFFFFF7F);
                    if (*(s16 *)((s8 *)arg0 + 0x8E) == 0) {
                        change_ai_state(2);
                    }
                } else {
                    calc_follow_goal();
                    change_ai_state(1);
                }
            }
        } else if (select_recovery_action__10TNpcPlayerFv((Npc_801510F8 *) (arg0), 1) != 0) {
            ((s32 (*)(void *, int))reset_partner_counter)((void *) (arg0 + 0x5C), 8);
            temp_r3_3 = *(s32 *)((s8 *)arg0 + 0x80);
            if (temp_r3_3 & 0x200) {
                request_chatter(0x13);
                change_ai_state(8);
            } else if (temp_r3_3 & 0x80) {
                *(s32 *)((s8 *)arg0 + 0x80) = (s32) (temp_r3_3 & ~0x280);
                if (*(s16 *)((s8 *)arg0 + 0x8E) == 0) {
                    change_ai_state(2);
                }
            } else {
                *(s32 *)((s8 *)arg0 + 0x80) = (s32) (temp_r3_3 & 0xFFFFFDFF);
                if (((f32 (*)(void *, void *))horizontal_distance_squared)((void *) (arg0 + 0xDC), (void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x78)) + 0x94) + 0x38)) < lbl_805DB248) {
                    change_ai_state(8);
                } else if ((s32) *(s32 *)((s8 *)arg0 + 0x84) != 0) {
                    if (*(s16 *)((s8 *)arg0 + 0x8E) == 0) {
                        change_ai_state(2);
                    }
                } else {
                    calc_follow_goal();
                    change_ai_state(1);
                }
            }
        } else if ((choose_attack_target() != 0) && (*(s16 *)((s8 *)arg0 + 0x8E) == 0)) {
            if (*(s32 *)((s8 *)arg0 + 0x80) & 0x1000) {
                change_ai_state(2);
                *(s32 *)((s8 *)arg0 + 0x80) = (s32) (*(s32 *)((s8 *)arg0 + 0x80) & 0xFFFFEFFF);
            } else {
                change_ai_state(1);
            }
            *(s32 *)((s8 *)arg0 + 0x80) = (s32) (*(s32 *)((s8 *)arg0 + 0x80) & 0xFFFFEFFF);
        } else {
            if ((s32) *(s32 *)((s8 *)arg0 + 0x84) != 0) {
                calc_follow_goal();
            } else {
                ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((void *) (arg0 + 0xDC), (void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x78)) + 0x94) + 0x38));
            }
            change_ai_state(1);
        }
        if (!(((TNpcPlayer *)(*(u8 **)((s8 *)arg0 + 0x78)))->get_action_state() & 2)) {
            *(s32 *)((s8 *)arg0 + 0x1C) = 0;
        }
        return;
    }
}

void TNpcPlayer::run_task() {
    u8 *arg0 = (u8 *)this;
    u8 *owner;
    owner = *(u8 **)((s8 *)arg0 + 0x74);
    if (owner == NULL || (void *) *(u8 **)((s8 *)arg0 + 0x78) == NULL) {
        return;
    }
    {
        {
        if (refresh_npc_view_actor_lost((void *) (owner)) != 0) {
            queue_destruction__7TObjectFv((arg0));
            return;
        }
        if (refresh_npc_view_actor_lost((void *) (*(u8 **)((s8 *)arg0 + 0x78))) != 0) {
            queue_destruction__7TObjectFv((arg0));
            return;
        }
        if ((((TObjPlayer *)(*(void **)((s8 *)(*(u8 **)((s8 *)arg0 + 0x78)) + 0x94)))->is_inactive() != 0) && (((void *) *(void **)((s8 *)(*(u8 **)((s8 *)arg0 + 0x78)) + 0x94) == NULL) || (((TNpcPlayer *)((void *) *(void **)((s8 *)(*(u8 **)((s8 *)arg0 + 0x78)) + 0x94)))->get_action_flags() != 0xFFFF))) {
            ((TNpcPlayer *)arg0)->init_state();
            if (!(*(s32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)arg0 + 0x74)) + 0x94)) + 0x30) & 0x800)) {
                if (*(s32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)arg0 + 0x78)) + 0x94)) + 0x30) & 0x800) {
                    if (((s32 (*)(void *, int, int))clamp_partner_counter)((void *) (arg0 + 0x5C), 3, 0x400) != 0) {
                        ((TNpcPlayer *)arg0)->request_chatter(5);
                    } else if (((s32 (*)(void *, int, int))is_partner_counter_reached)((void *) (arg0 + 0x5C), 3, 0) != 0) {
                        ((TNpcPlayer *)arg0)->request_chatter(4);
                    }
                    increment_partner_counter((s32) (arg0 + 0x5C), 3);
                    ((TNpcPlayer *)arg0)->change_ai_state(0);
                } else {
                    reset_partner_counter((s32) (arg0 + 0x5C), 3);
                    ((TNpcPlayer *)arg0)->update_condition_flags();
                    ((s32 (*)(void *))partner_observe_surroundings)((void *) (arg0));
                    ((TNpcPlayer *)arg0)->decide_action();
                    ((TNpcPlayer *)arg0)->update_follow_target();
                }
                ((TNpcPlayer *)arg0)->deliver_partner_action();
            }
        }
        }
    }
}

u8 *__dt__10TNpcPlayerFv(u8 *arg0, s16 arg1) {
    u32 player;
    u8 *npc_player;
    u8 *temp_r3_2;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = ((s32 *)__vt__10TNpcPlayer);
        npc_player = (u8 *)(*(u8 **)((s8 *)arg0 + 0x74));
        if (npc_player != NULL) {
            ((TNpcPlayer *)npc_player)->dt(1);
            *(u8 **)((s8 *)arg0 + 0x74) = NULL;
        }
        temp_r3_2 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x78));
        if (temp_r3_2 != NULL) {
            player = (u32)get_player_by_client_id((get_npc_type__10TNpcPlayerFPv((void*)(temp_r3_2))));
            if (player != 0U) {
                TObjPlayer::send_item_pickup_request((s32) player);
            }
            ((TNpcPlayer *)(*(u8 **)((s8 *)arg0 + 0x78)))->dt(1);
            *(u8 **)((s8 *)arg0 + 0x78) = NULL;
        }
        __dt__7TObjectFv((void *) (arg0), 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

Npc_80152168 *TNpcPlayer__ct(Npc_80152168 *self, s32 a, s32 b, s16 kind, s32 arg4, void *parent) {
    void *p;

    __ct__7TObjectFP7TObject(self, parent);
    self->vt = ((s32 *)__vt__10TNpcPlayer);
    ((TNpcPlayer *)(self->f5C))->init();
    self->f0 = lbl_805D2E74;
    self->f24 = 0x19;
    self->f1C = 0;
    self->f20 = 0;
    self->fAC = TNpcPlayer__data_805DB1F0;
    self->fB0 = TNpcPlayer__data_805DB1F0;
    self->fB4 = TNpcPlayer__data_805DB1F0;
    self->fD0 = TNpcPlayer__data_805DB1F0;
    self->fD4 = TNpcPlayer__data_805DB1F0;
    self->fD8 = TNpcPlayer__data_805DB1F0;
    self->fDC = TNpcPlayer__data_805DB1F0;
    self->fE0 = TNpcPlayer__data_805DB1F0;
    self->fE4 = TNpcPlayer__data_805DB1F0;
    self->fC4 = 0;
    self->fC8 = 0;
    self->fCC = 0;
    self->f2C = kind;
    self->f80 = 0;
    self->f7C = 0;
    self->f88 = TNpcPlayer__data_805DB1F0;
    self->f58 = TNpcPlayer__data_805DB1F0;
    self->f8C = 0;
    self->f8E = 0;
    self->f8D = 0;
    p = ::operator new(0x108);
    if (p != 0) {
        p = ((void *(*)(void *, u16))init_ai_state__10TNpcPlayerFPvi)(p, a);
    }
    self->f74 = p;
    p = ::operator new(0x108);
    if (p != 0) {
        p = ((void *(*)(void *, u16))init_ai_state__10TNpcPlayerFPvi)(p, b);
    }
    self->f78 = (Own_80152168 *)p;
    ((TNpcPlayer *)(self->f30))->copy((u8 *)&TNpcPlayer__template_table[self->f2C]);
    if (self->f78 != 0 && self->f78->obj != 0) {
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->fDC, self->f78->obj + 0x38);
        ((TNpcPlayer *)self)->init_equipment();
    }
    self->f84 = arg4;
    return self;
}

void TNpcPlayer::copy(void* q) { *(u16*)((char*)this + 0x0) = *(u16*)((char*)q + 0x0); *(u16*)((char*)this + 0x2) = *(u16*)((char*)q + 0x2); *(u32*)((char*)this + 0x4) = *(u32*)((char*)q + 0x4); *(f32*)((char*)this + 0x8) = *(f32*)((char*)q + 0x8); *(f32*)((char*)this + 0xc) = *(f32*)((char*)q + 0xc); *(f32*)((char*)this + 0x10) = *(f32*)((char*)q + 0x10); *(f32*)((char*)this + 0x14) = *(f32*)((char*)q + 0x14); *(f32*)((char*)this + 0x18) = *(f32*)((char*)q + 0x18); *(f32*)((char*)this + 0x1c) = *(f32*)((char*)q + 0x1c); *(u8*)((char*)this + 0x20) = *(u8*)((char*)q + 0x20); *(u8*)((char*)this + 0x21) = *(u8*)((char*)q + 0x21); *(u8*)((char*)this + 0x22) = *(u8*)((char*)q + 0x22); *(u8*)((char*)this + 0x23) = *(u8*)((char*)q + 0x23); *(f32*)((char*)this + 0x24) = *(f32*)((char*)q + 0x24); }

Npc_80152330 *construct_partner__10TNpcPlayerFPviisPv(Npc_80152330 *self, s32 a, s32 b, s16 kind, void *parent) {
    void *p;

    __ct__7TObjectFP7TObject(self, parent);
    self->vt = ((s32 *)__vt__10TNpcPlayer);
    ((TNpcPlayer *)(self->f5C))->init();
    self->f0 = lbl_805D2E74;
    self->f24 = 0x19;
    self->f1C = 0;
    self->f20 = 0;
    self->fAC = TNpcPlayer__data_805DB1F0;
    self->fB0 = TNpcPlayer__data_805DB1F0;
    self->fB4 = TNpcPlayer__data_805DB1F0;
    self->fD0 = TNpcPlayer__data_805DB1F0;
    self->fD4 = TNpcPlayer__data_805DB1F0;
    self->fD8 = TNpcPlayer__data_805DB1F0;
    self->fDC = TNpcPlayer__data_805DB1F0;
    self->fE0 = TNpcPlayer__data_805DB1F0;
    self->fE4 = TNpcPlayer__data_805DB1F0;
    self->fC4 = 0;
    self->fC8 = 0;
    self->fCC = 0;
    self->f2C = kind;
    self->f80 = 0;
    self->f7C = 0;
    self->f88 = TNpcPlayer__data_805DB1F0;
    self->f58 = TNpcPlayer__data_805DB1F0;
    self->f8C = 0;
    self->f8E = 0;
    self->f8D = 0;
    p = ::operator new(0x108);
    if (p != 0) {
        p = ((void *(*)(void *, u16))init_ai_state__10TNpcPlayerFPvi)(p, a);
    }
    self->f74 = p;
    p = ::operator new(0x108);
    if (p != 0) {
        p = ((void *(*)(void *, u16))init_ai_state__10TNpcPlayerFPvi)(p, b);
    }
    self->f78 = (Own_80152330 *)p;
    ((TNpcPlayer *)(self->f30))->copy((u8 *)&TNpcPlayer__template_table[self->f2C]);
    if (self->f78 != 0 && self->f78->obj != 0) {
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->fDC, self->f78->obj + 0x38);
        ((TNpcPlayer *)self)->init_equipment();
    }
    self->f84 = 0;
    return self;
}

extern "C" {
extern void *lbl_805D2E70;
void read_disc_file(void *name, void *buf);

u8 *load_npc_player_template(s32 index) {
    s32 mode;
    s32 diff;
    s32 lvl;
    u16 base;

    if (lbl_805D5860 != 0U) {
        return NULL;
    }
    lbl_805D5860 = (u32)mem_alloc(0x1400);
    if (TNpcPlayer__data_805D5864 != 0) {
        TNpcPlayer__data_805D5864 = 0;
        copy_player_visual_record(lbl_8050CF68, lbl_8050D3E0);
    } else {
        read_disc_file(lbl_805D2E70, (void *)lbl_805D5860);
        copy_player_visual_record(lbl_8050CF68, (u8 *)lbl_805D5860 + index * 0x50);
    }
    bswap__15disp_data_part2Fv((s32)lbl_8050CF68);
    mem_free((void *)lbl_805D5860);
    mode = game_difficulty_selection;
    lbl_805D5860 = 0;
    if (mode >= 0 && mode <= 2) {
        diff = mode;
    } else {
        diff = 2;
    }
    base = TNpcPlayer__template_table[index].f2;
    lvl = base + diff * 25;
    if (mode == 3) {
        lvl = base + 150;
    }
    if (lvl >= 198) {
        lvl = 198;
    }
    switch (mode) {
    case 0:
        TNpcPlayer::send_command((s32)(((u8 *)lbl_8050CF68)[0x31]), (s8)5, (s32)((int)lbl_804AF330[index]), (s32)lvl, (s8 *)lbl_8050CFC4);
        break;
    case 1:
        TNpcPlayer::send_command((s32)(((u8 *)lbl_8050CF68)[0x31]), (s8)5, (s32)((int)lbl_804AF430[index]), (s32)lvl, (s8 *)lbl_8050CFC4);
        break;
    case 2:
        TNpcPlayer::send_command((s32)(((u8 *)lbl_8050CF68)[0x31]), (s8)5, (s32)((int)lbl_804AF530[index]), (s32)lvl, (s8 *)lbl_8050CFC4);
        break;
    case 3:
        TNpcPlayer::send_command((s32)(((u8 *)lbl_8050CF68)[0x31]), (s8)5, (s32)((int)lbl_804AF630[index]), (s32)lvl, (s8 *)lbl_8050CFC4);
        break;
    default:
        TNpcPlayer::send_command((s32)(((u8 *)lbl_8050CF68)[0x31]), (s8)5, (s32)((int)lbl_804AF330[index]), (s32)lvl, (s8 *)lbl_8050CFC4);
        break;
    }
    copy_player_visual_record((u8 *)lbl_8050CFC4 + 0x370, lbl_8050CF68);
    return (u8 *)lbl_8050CFC4;
}
}

u8 *TNpcPlayer::build_npc_player_record(s32 arg0) {
    s32 mode;
    s32 diff;
    s32 lvl;
    u16 base;

    if (TNpcPlayer__data_805D5864 != 0) {
        TNpcPlayer__data_805D5864 = 0;
        copy_player_visual_record(lbl_8050CF68, lbl_8050D3E0);
    } else {
        copy_player_visual_record(lbl_8050CF68, (u8 *)lbl_805D5860 + arg0 * 0x50);
    }
    bswap__15disp_data_part2Fv((s32)lbl_8050CF68);
    mem_free((void *)lbl_805D5860);
    mode = game_difficulty_selection;
    lbl_805D5860 = 0;
    if (mode >= 0 && mode <= 2) {
        diff = mode;
    } else {
        diff = 2;
    }
    base = TNpcPlayer__template_table[arg0].f2;
    lvl = base + diff * 25;
    if (mode == 3) {
        lvl = base + 150;
    }
    if (lvl >= 198) {
        lvl = 198;
    }
    switch (mode) {
    case 0:
        TNpcPlayer::send_command((s32)(((u8 *)lbl_8050CF68)[0x31]), (s8)5, (s32)((int)lbl_804AF330[arg0]), (s32)lvl, (s8 *)lbl_8050CFC4);
        break;
    case 1:
        TNpcPlayer::send_command((s32)(((u8 *)lbl_8050CF68)[0x31]), (s8)5, (s32)((int)lbl_804AF430[arg0]), (s32)lvl, (s8 *)lbl_8050CFC4);
        break;
    case 2:
        TNpcPlayer::send_command((s32)(((u8 *)lbl_8050CF68)[0x31]), (s8)5, (s32)((int)lbl_804AF530[arg0]), (s32)lvl, (s8 *)lbl_8050CFC4);
        break;
    case 3:
        TNpcPlayer::send_command((s32)(((u8 *)lbl_8050CF68)[0x31]), (s8)5, (s32)((int)lbl_804AF630[arg0]), (s32)lvl, (s8 *)lbl_8050CFC4);
        break;
    default:
        TNpcPlayer::send_command((s32)(((u8 *)lbl_8050CF68)[0x31]), (s8)5, (s32)((int)lbl_804AF530[arg0]), (s32)lvl, (s8 *)lbl_8050CFC4);
        break;
    }
    copy_player_visual_record((u8 *)lbl_8050CFC4 + 0x370, lbl_8050CF68);
    return (u8 *)lbl_8050CFC4;
}

void TNpcPlayer::ensure_rock_singleton() {
    if ((u32) lbl_805D5860 == 0U) {
        lbl_805D5860 = (u32)mem_alloc(0x1400);
    }
}

void TNpcPlayer::register_ply_char_data_global() {
    __register_global_object(__ct__12TPlyCharDataFv(lbl_8050CFC4), (void *)__dt__12TPlyCharDataFv, npc_player_ply_char_data_global);
}

void set_technique_seed_level(Obj_801528A8 *self, s16 i, u8 v) {
    self->arr[i] = v;
}

void reset_partner_counter(s32 arg0, s32 arg1) {
    *(s16 *)((s8 *)(arg0 + (arg1 * 2)) + 0) = 0;
}

void increment_partner_counter(s32 arg0, s32 arg1) {
    s32 temp_r5;
    temp_r5 = arg1 * 2;
    *(s16 *)((s8 *)(arg0 + temp_r5) + 0) = *(s16 *)((s8 *)(arg0 + temp_r5) + 0) + 1;
}

s32 TNpcPlayer__sub_801528DC(void* p) { return *(s32*)((char*)p + 0x84); }

s32 TNpcPlayer::get_npc_state() { return *(s32*)((char*)this + 0x7c); }

u16 get_npc_type__10TNpcPlayerFPv(void* p) { return *(u16*)((char*)p + 0x8a); }

int get_partner_counter(s32 arg0, s32 arg1) {
    return *(s16 *)((s8 *)(arg0 + (arg1 * 2)) + 0);
}

s32 npc_counter_reset_if_reached(s32 arg0, s32 arg1) {
    if (((s32 (*)(void))is_partner_counter_reached)() != 0) {
        *(s16 *)((s8 *)(arg0 + (arg1 * 2)) + 0) = 0;
        return 1;
    }
    return 0;
}

int is_partner_counter_reached(s16 *table, s32 idx, s32 value) {
    return value <= table[idx] ? 1 : 0;
}

void set_partner_counter(s32 arg0, s32 arg1, s16 arg2) {
    *(s16 *)((s8 *)(arg0 + (arg1 * 2)) + 0) = arg2;
}

s32 TNpcPlayer__sub_80152978(void* p) { return *(s32*)((char*)p + 0x80); }

s32 TNpcPlayer::get_condition() { return *(s32*)((char*)this + 0x90); }

void copy_transform_second__10TNpcPlayerFPvPvPv(void* p, void* a1, void* a2) { ((int (*)(void*))copy_transform__10TNpcPlayerFPvPv)(a2); }

void copy_transform__10TNpcPlayerFPvPv(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); *(f32*)((char*)p + 0x8) = *(f32*)((char*)q + 0x8); }

s32 TNpcPlayer::get_action_state() { return *(s32*)((char*)this + 0x8c); }

void TNpcPlayer::reset_fields_8c() { *(s32*)((char*)this + 0x8c) = 0; *(s32*)((char*)this + 0x90) = 0; }

s32 clamp_partner_counter(s32 arg0, s32 arg1, s16 arg2) {
    if (((s32 (*)(void))is_partner_counter_reached)() != 0) {
        *(s16 *)((s8 *)(arg0 + (arg1 * 2)) + 0) = arg2;
        return 1;
    }
    return 0;
}

void TNpcPlayer__sub_80152A30(void) {  }

void TNpcPlayer__sub_80152A34(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)arg0 + 0x80) = (s32) *(s32 *)((s8 *)arg0 + 0x7C);
    *(s32 *)((s8 *)arg0 + 0x7C) = arg1;
    *(s32 *)((s8 *)arg0 + 0x84) = arg2;
}

void*TNpcPlayer::init() { TNpcPlayer__sub_80152A78((s16 *)this); return this; }

void TNpcPlayer__sub_80152A78(s16 *self) {
    s32 i;
    for (i = 0; i < 11; i++) {
        self[i] = 0;
    }
}

void TNpcPlayer::update() { bswap_6x45_packet((void*)(this)); update_players__6TLobbyFv((s32)this); }

void bswap_6x45_packet(void* p) { ((G_ClientIDHeader *)p)->bswap(); bswap_16__FPUs((void*)((char*)p + 0x4)); bswap_16__FPUs((void*)((char*)p + 0x6)); }

void init_6x45_attack_packet(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 4) = 0;
    *(s16 *)((s8 *)arg0 + 6) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x45;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TNpcPlayer::update_players() { bswap_6x44_packet((void*)(this)); update_players__6TLobbyFv((s32)this); }

void bswap_6x44_packet(void* p) { ((G_ClientIDHeader *)p)->bswap(); bswap_16__FPUs((void*)((char*)p + 0x4)); bswap_16__FPUs((void*)((char*)p + 0x6)); }

void init_6x44_attack_packet(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 4) = 0;
    *(s16 *)((s8 *)arg0 + 6) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x44;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TNpcPlayer::update_lobby() { bswap_6x43_packet((void*)(this)); update_players__6TLobbyFv((s32)this); }

void bswap_6x43_packet(void* p) { ((G_ClientIDHeader *)p)->bswap(); bswap_16__FPUs((void*)((char*)p + 0x4)); bswap_16__FPUs((void*)((char*)p + 0x6)); }

void init_6x43_attack_packet(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 4) = 0;
    *(s16 *)((s8 *)arg0 + 6) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x43;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void TNpcPlayer::finalize_and_send_packet() {
    u8 *arg0 = (u8 *)this;
    *(s8 *)((s8 *)arg0 + 1) = (s8) ((((u32)get_6x47_cast_packet_size((u8 *)(arg0))) >> 2U) & 0x3F);
    byteswap_positions();
    send_subcommand((u8 *)((void *) (arg0)));
}

void TNpcPlayer::byteswap_positions() {
    N_80152C8C *arg0 = (N_80152C8C *)this;
    s32 i;
    ((G_ClientIDHeader *)arg0)->bswap();
    for (i = 0; i < arg0->count; i++) {
        ((TNpcPlayer *)(&arg0->pos[i]))->byteswap_pos();
    }
}

u8 get_6x47_cast_packet_size(u8 *arg0) {
    return (u8) (0x30 - ((0xA - (s8) *(u8 *)((s8 *)arg0 + 7)) * 4));
}

void *TNpcPlayer::init_cast_technique_cmd() {
    TNpcPlayer__sub_80152D64((void*)((void *)((char *)this + 4)));
    __construct_array((void *)((char *)this + 8), fn_80152EF8, 0, 4, 10);
    *(u8 *)((s8 *)this + 0x0) = 71;
    *(u8 *)((s8 *)this + 0x1) = 12;
    return this;
}

void TNpcPlayer__sub_80152D64(void* p) { *(u8*)((char*)p + 0x3) = 0; *(u8*)((char*)p + 0x2) = 0; *(u8*)((char*)p + 0x1) = 0; *(u8*)((char*)p + 0x0) = 0; }

void TNpcPlayer::reset_model() { init_model(); update_players__6TLobbyFv((s32)this); }

void TNpcPlayer::init_model() { ((G_ClientIDHeader *)this)->bswap(); ((VectorXZF *)((char*)this + 0x4))->bswap(); }

void TNpcPlayer::reset_move_state() { *(float*)((char*)this + 0x8) = TNpcPlayer__data_805DB1F0; *(float*)((char*)this + 0x4) = TNpcPlayer__data_805DB1F0; *(unsigned char*)((char*)this + 0x0) = 66; *(unsigned char*)((char*)this + 0x1) = 3; }

void TNpcPlayer::sync_from_lobby() { swap_endian(); update_players__6TLobbyFv((s32)this); }

void TNpcPlayer::swap_endian() { ((G_ClientIDHeader *)this)->bswap(); ((VectorXZF *)((char*)this + 0x4))->bswap(); bswap_32__FPUl((char*)this + 0xc); }

void init_6x40_walk_packet(void* a0) { *(float*)((char*)a0 + 0x8) = TNpcPlayer__data_805DB1F0; *(float*)((char*)a0 + 0x4) = TNpcPlayer__data_805DB1F0; *(int*)((char*)a0 + 0xc) = 0; *(unsigned char*)((char*)a0 + 0x0) = 64; *(unsigned char*)((char*)a0 + 0x1) = 4; }

void TNpcPlayer::set_field2(s16 v) { *(s16*)((char*)this + 0x2) = v; }

void TNpcPlayer::set_field_0(s16 v) { *(s16*)((char*)this + 0x0) = v; }

void TNpcPlayer::set_state(s32 v) { *(s32*)((char*)this + 0x0) = v; }

void TNpcPlayer::byteswap_pos() { bswap_16__FPUs((void*)(this)); bswap_16__FPUs((void*)((char*)this + 0x2)); }

void set_state__10TNpcPlayerFPvs(void* p, s16 v) { *(s16*)((char*)p + 0x2) = v; }

void set_type__10TNpcPlayerFPvs(void* p, s16 v) { *(s16*)((char*)p + 0x0) = v; }

void* fn_80152EF8(void* p) { TFontSmallLobby__sub_80152F28((Obj_80152F28 *)((void*)(p))); return p; }

void TFontSmallLobby__sub_80152F28(Obj_80152F28 *self) {
    self->a = 0xFFFF;
    self->b = 0;
}

int get_registered_object_count(void) {  return registered_entity_count; }

u16 TNpcPlayer::get_action_flags() { return *(u16*)((char*)this + 0x678); }

void TUnk_804AF7B0::run_task() {
    s32 temp_r0;
    s32 temp_r31;

    temp_r31 = *(s32 *)((s8 *)this + 0x10);
    if (check_switch__22TObjFogCollisionPoisonFv(temp_r31) != 0) {
        if (((TObjFogCollision *)temp_r31)->check_collision(*(u16 *)((s8 *)this + 0x28)) != 0) {
            ((TObjFogCollisionPoison *)temp_r31)->record_poison_hit(*(u16 *)((s8 *)this + 0x28));
            *(s32 *)((s8 *)this + 0x20) = (s32) (*(s32 *)((s8 *)this + 0x20) + 1);
            if ((s32) *(s32 *)((s8 *)this + 0x20) >= (s32) *(s32 *)((s8 *)this + 0x1C)) {
                ((TObjFogCollisionPoison *)temp_r31)->apply_poison_damage(*(u16 *)((s8 *)this + 0x28));
                *(s32 *)((s8 *)this + 0x20) = 0;
                *(s32 *)((s8 *)this + 0x1C) = 0x1E;
            }
            *(s32 *)((s8 *)this + 0x24) = (s32) (*(s32 *)((s8 *)this + 0x24) + 1);
        } else {
            *(s32 *)((s8 *)this + 0x1C) = 0x96;
            *(s32 *)((s8 *)this + 0x24) = 0;
        }
        temp_r0 = *(s32 *)((s8 *)this + 0x24);
        if (temp_r0 == 1) {
            TObjFogCollisionPoison__sub_801535D0(temp_r31);
            return;
        }
        if (temp_r0 > 0x3C) {
            TObjFogCollisionPoison__sub_80153520(temp_r31);
        }
    }
}
