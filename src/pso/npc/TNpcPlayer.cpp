#include "pso/player/TPlyDispData.h"
#include "pso/player/TPlyCharData.h"
#include <stdlib.h>
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/system/ResourceFile.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/object/base/TObjChara.h"
#include "pso/npc/TNpcPlayer.h"
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/TUnk_804AF7B0.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"

#include "pso/object/base/TObjMotion.h"
#include "pso/map/FloorArea.h"
#include "pso/map/CsnQuery.h"

#include "pso/object/collision/TObjFogCollisionPoison.h"

#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/object/collision/TObjFogCollision.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/network/protocol/protocol.h"
#include "pso/technique/TTecReverser.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/unk/TLobby_8013A874.h"

extern "C" {
void rotate_matrix_y(s32, s32);
}
extern u8 identity_matrix[];

struct Text_8014E250 { char text[0x36]; };


typedef struct Line_8014EE98 { Vec p; Vec d; } Line_8014EE98;


struct Msg_80150DE8 { u8 hdr[2]; u16 type; f32 x; f32 z; };


struct Msg_80150E44 { u8 hdr[2]; u16 type; f32 x; f32 z; u32 flags; };


struct Msg_80150A34 {
    u8 pad0[2];
    u16 type;
    s8 kind;
    u8 pad5;
    s8 e;
    s8 one;
    u8 sub[0x2C];
};
extern "C" {


struct Obj_801528A8 { u8 pad[0x5c]; u8 arr[1]; };


struct Tec_80150B90 { u8 pad[0x10]; s16 f10; };


struct Obj_80152F28 { u16 a; u16 b; };

struct N_80152C8C { u8 pad0[7]; s8 count; u32 pos[1]; };
disp_data_part2 *npc_player_char_data_buffer;
s32 TNpcPlayer__data_805D5864;


f32 atan2_float(f32 y, f32 x);
s16 get_actor_tp(u8 *p);
s16 obj_getS16_2BA(u8 *p);
s32 get_entity_id(void *obj);
f32 fabs_float(f32);
s32 __dt__12TPlyCharDataFv(s32 arg0, s16 arg1);
void * __ct__12TPlyCharDataFv(void *self);
f32 horizontal_distance_squared(void *, void *);
void TNpcPlayer__sub_8014DC3C(void *, s32);
void deliver_partner_chatter(TNpcPlayer *self);
void partner_compute_stalled_detour(TNpcPlayer *self, Vec *from, Vec *to, Vec *d, Vec *out);
s32 partner_route_around_wall(TNpcPlayer *self, Vec *from, Vec *to, Vec *d, Vec *out, Vec *out2);
s32 partner_probe_obstacles(Unk_8014F844 *view);
s32 partition_sort_entries__10TNpcPlayerFiPvii(s32 self, Unk_8014F844Entry *a, s32 lo, s32 hi);
s32 find_parts_in_range__10TNpcPlayerFPvPvif(Unk_8014F844 *view, void *pos, s32 id, f32 range);
s32 scan_nearby_enemies__10TNpcPlayerFPvPvf(Unk_8014F844 *view, void *pos, f32 range);
bool is_target_line_clear__10TNpcPlayerFPvUs(u8 *arg0, u32 arg1);
Unk_8014F844 * init_ai_state__10TNpcPlayerFPvi(Unk_8014F844 *self, s32 id);
s32 try_update_target_flag__10TNpcPlayerFPvi(void *arg0, s32 arg1);
s32 check_and_set_reached__10TNpcPlayerFPv(void *arg0);
s32 needs_movement__10TNpcPlayerFPvPvi(TNpcPlayer *self, void *_w1, int _w2);
void select_path_waypoint__10TNpcPlayerFv(TNpcPlayer *self);
TNpcPlayer *TNpcPlayer__ct(TNpcPlayer *self, s32 a, s32 b, s16 kind, s32 arg4, void *parent);
TNpcPlayer *construct_partner__10TNpcPlayerFPviisPv(TNpcPlayer *self, s32 a, s32 b, s16 kind, void *parent);
void set_technique_seed_level(Obj_801528A8 *self, s16 i, u8 v);
void reset_partner_counter(saddr arg0, s32 arg1);
void increment_partner_counter(saddr arg0, s32 arg1);
s32 TNpcPlayer__sub_801528DC(void* p);
u16 get_npc_type__10TNpcPlayerFPv(void* p);
int get_partner_counter(saddr arg0, s32 arg1);
s32 npc_counter_reset_if_reached(saddr arg0, s32 arg1);
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
TObjCollidable * find_entity_by_id(s32);
s32 free_collision_body_parts(u32);
void init_collision_body_parts(void *, void *, s32);
void * __ct__14TObjCollidableFP7TObject(void *, void *);
s32 try_send_6x27_use_item(s32, s32, void *);
void *get_player_by_client_id(s32 i);
s8 get_cast_technique_level(void *, s16);
void __ct__7TObjectFP7TObject(void *, void *);
Tec_80150B90 * calc_technique_parameters(s32, s32, s32);
void __register_global_object(void *obj, void *dtor, void *link);
void __construct_array(void *array, void *(*ctor)(void *), void *dtor, u32 size, u32 count);
void matrix_mult_vec(s32, Vec *, Vec *);
f32 vec3_dot(Vec *, Vec *);
f32 vector_length(Vec *);
void project_point_onto_line(void *, Line_8014EE98 *, Vec *);

extern int registered_entity_count;
extern Text_8014E250 npc_partner_dialogue_state[];

void copy_player_visual_record(void *, void *);
extern s32 TNpcPlayer__data_805D5864;

disp_data_part2 lbl_8050CF68;
u32 npc_player_ply_char_data_global[3];
u32 lbl_8050CFC4[263];
disp_data_part2 lbl_8050D3E0;

// Combat action ids by tier, read by TNpcPlayer::update_combat_action.
static const s32 npc_player_combat_action_table[3][2] = {{0, 1}, {3, 4}, {6, 8}};

const char *lbl_805D2E70 = "npcplayerchar.dat";
const char *TNpcPlayer__name = "TNpcPlayer";

// lbl_8050CFC4 is constructed by __sinit_TNpcPlayer_cpp, spelled out below because
// the original's static initializer precedes the out-of-line helpers at the end
// of this file, which no compiler-generated __sinit reproduces.
void __sinit_TNpcPlayer_cpp();
__declspec(section ".ctors") static void *const npc_player_global_initializer = (void *)__sinit_TNpcPlayer_cpp;
}
s32 partner_clip_path_point(void *self, f32 *from, f32 *to, f32 *out);
s32 partner_find_wall_segment(saddr arg0, saddr arg1, saddr arg2, saddr arg3, saddr arg4);
s32 refresh_npc_view_actor_lost(void *arg0);
s32 partner_view_update_hp_change(void *arg0);
s32 partner_view_update_conditions(u8 *arg0);
s32 partner_view_check_moved(u8 *arg0);
void partner_observe_surroundings(TNpcPlayer *arg0);
int is_partner_counter_reached(s16 *table, s32 idx, s32 value);
void set_partner_counter(saddr arg0, s32 arg1, s16 arg2);
s32 clamp_partner_counter(saddr arg0, s32 arg1, s16 arg2);
void bswap_6x45_packet(void* p);
void bswap_6x44_packet(void* p);
void bswap_6x43_packet(void* p);
u8 get_6x47_cast_packet_size(u8 *arg0);
void init_6x40_walk_packet(void* a0);
int get_registered_object_count(void);
const char *get_partner_custom_text(s32 kind, u16 player);
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
TNpcPlayer::AiParams TNpcPlayer__template_table[64] = {
    {0x0, 0x4, TECHNIQUE_FLAGS_NONE, 100.0f, 10.0f, 13.0f, 30.0f, 30.0f, 100.0f, 0x0, 0x9, 0xf, 0x0, 50.0f},
    {0x1, 0xc, TECHNIQUE_FLAGS_BARTA_GIBARTA, 100.0f, 10.0f, 15.0f, 35.0f, 25.0f, 100.0f, 0x0, 0x9, 0x19, 0x5a, 50.0f},
    {0x2, 0x14, TECHNIQUE_FLAGS_BARTA_GIBARTA, 100.0f, 10.0f, 15.0f, 40.0f, 30.0f, 100.0f, 0x2, 0x9, 0x1e, 0x50, 50.0f},
    {0x3, 0x12, TECHNIQUE_FLAGS_FOIE_GIFOIE, 120.0f, 10.0f, 18.0f, 40.0f, 30.0f, 100.0f, 0x0, 0x9, 0x3c, 0x28, 50.0f},
    {0x4, 0xe, TECHNIQUE_FLAGS_NONE, 100.0f, 10.0f, 15.0f, 40.0f, 30.0f, 120.0f, 0x0, 0x9, 0x14, 0x0, 50.0f},
    {0x5, 0x18, TECHNIQUE_FLAGS_NONE, 100.0f, 10.0f, 15.0f, 30.0f, 30.0f, 100.0f, 0x0, 0x9, 0x3c, 0x0, 50.0f},
    {0x6, 0x19, TECHNIQUE_FLAGS_NONE, 80.0f, 10.0f, 18.0f, 60.0f, 30.0f, 30.0f, 0x0, 0x9, 0x50, 0x28, 50.0f},
    {0x7, 0xb, TECHNIQUE_FLAGS_NONE, 100.0f, 10.0f, 13.0f, 40.0f, 30.0f, 100.0f, 0x0, 0x9, 0x14, 0x0, 50.0f},
    {0x8, 0x11, TECHNIQUE_FLAGS_BARTA_GIBARTA, 100.0f, 10.0f, 15.0f, 40.0f, 30.0f, 100.0f, 0x6, 0x9, 0x1e, 0x46, 50.0f},
    {0x9, 0x1b, TECHNIQUE_FLAGS_NONE, 80.0f, 10.0f, 18.0f, 70.0f, 30.0f, 30.0f, 0x0, 0x9, 0x37, 0x0, 50.0f},
    {0xa, 0x12, TECHNIQUE_FLAGS_NONE, 80.0f, 10.0f, 18.0f, 70.0f, 30.0f, 30.0f, 0x0, 0x9, 0x3c, 0x0, 50.0f},
    {0xb, 0x11, TECHNIQUE_FLAGS_ZONDE_RAZONDE, 80.0f, 10.0f, 18.0f, 60.0f, 30.0f, 30.0f, 0x4, 0x9, 0x2d, 0x37, 50.0f},
    {0xc, 0x23, TECHNIQUE_FLAGS_NONE, 80.0f, 10.0f, 18.0f, 70.0f, 30.0f, 30.0f, 0x0, 0x0, 0x2d, 0x0, 50.0f},
    {0xd, 0xf, TECHNIQUE_FLAGS_FOIE_GIFOIE, 100.0f, 10.0f, 15.0f, 50.0f, 30.0f, 100.0f, 0x0, 0x9, 0x37, 0x14, 50.0f},
    {0xe, 0x22, TECHNIQUE_FLAGS_NONE, 120.0f, 10.0f, 15.0f, 50.0f, 30.0f, 100.0f, 0x0, 0x9, 0x32, 0x0, 50.0f},
    {0xf, 0xb, TECHNIQUE_FLAGS_NONE, 120.0f, 10.0f, 15.0f, 40.0f, 30.0f, 100.0f, 0x0, 0x9, 0x28, 0x0, 50.0f},
    {0x10, 0x9, TECHNIQUE_FLAGS_BARTA_GIBARTA, 100.0f, 10.0f, 15.0f, 40.0f, 30.0f, 80.0f, 0x2, 0x9, 0xa, 0x50, 50.0f},
    {0x11, 0x2a, TECHNIQUE_FLAGS_ZONDE_RAZONDE, 150.0f, 10.0f, 15.0f, 45.0f, 30.0f, 120.0f, 0xb, 0xb, 0x32, 0x46, 50.0f},
    {0x12, 0x20, TECHNIQUE_FLAGS_FOIE_GIFOIE, 100.0f, 10.0f, 15.0f, 30.0f, 30.0f, 120.0f, 0x9, 0x9, 0x32, 0x5a, 50.0f},
    {0x13, 0x7, TECHNIQUE_FLAGS_FOIE_GIFOIE, 100.0f, 10.0f, 15.0f, 30.0f, 30.0f, 100.0f, 0x0, 0xb, 0xa, 0x50, 50.0f},
    {0x14, 0x17, TECHNIQUE_FLAGS_FOIE_GIFOIE, 300.0f, 10.0f, 30.0f, 40.0f, 25.0f, 25.0f, 0x2, 0x0, 0x1e, 0x28, 50.0f},
    {0x15, 0x18, TECHNIQUE_FLAGS_NONE, 200.0f, 10.0f, 80.0f, 60.0f, 40.0f, 35.0f, 0x0, 0x0, 0x32, 0x0, 50.0f},
    {0x16, 0x14, TECHNIQUE_FLAGS_BARTA_GIBARTA_NO_BACKOFF, 300.0f, 10.0f, 30.0f, 30.0f, 20.0f, 60.0f, 0x4, 0x0, 0x32, 0x4b, 45.0f},
    {0x17, 0xb, TECHNIQUE_FLAGS_NONE_NO_BACKOFF, 300.0f, 10.0f, 50.0f, 50.0f, 20.0f, 100.0f, 0x0, 0x9, 0xf, 0x0, 70.0f},
    {0x18, 0xc, TECHNIQUE_FLAGS_NONE, 200.0f, 10.0f, 40.0f, 40.0f, 30.0f, 80.0f, 0x0, 0x9, 0x2d, 0x0, 60.0f},
    {0x19, 0x13, TECHNIQUE_FLAGS_NONE, 200.0f, 10.0f, 40.0f, 40.0f, 30.0f, 80.0f, 0x0, 0x9, 0x37, 0x0, 60.0f},
    {0x1a, 0x11, TECHNIQUE_FLAGS_NONE, 80.0f, 10.0f, 18.0f, 70.0f, 30.0f, 30.0f, 0x4, 0x9, 0x32, 0x0, 50.0f},
    {0x1b, 0xd, TECHNIQUE_FLAGS_NONE, 100.0f, 10.0f, 15.0f, 50.0f, 30.0f, 80.0f, 0x0, 0x9, 0x1e, 0x0, 50.0f},
    {0x1c, 0x14, TECHNIQUE_FLAGS_ZONDE_RAZONDE, 70.0f, 10.0f, 15.0f, 20.0f, 30.0f, 50.0f, 0x0, 0x9, 0x32, 0x32, 50.0f},
    {0x1d, 0xd, TECHNIQUE_FLAGS_NONE, 100.0f, 10.0f, 15.0f, 50.0f, 30.0f, 80.0f, 0x0, 0x9, 0x1e, 0x0, 50.0f},
    {0x1e, 0x18, TECHNIQUE_FLAGS_BARTA_GIBARTA, 80.0f, 10.0f, 15.0f, 50.0f, 30.0f, 60.0f, 0x6, 0x9, 0x32, 0x1e, 50.0f},
    {0x1f, 0x1e, TECHNIQUE_FLAGS_BARTA_GIBARTA_NO_BACKOFF, 300.0f, 10.0f, 40.0f, 40.0f, 20.0f, 100.0f, 0x8, 0x9, 0x23, 0x50, 45.0f},
    {0x20, 0xa, TECHNIQUE_FLAGS_NONE, 80.0f, 10.0f, 18.0f, 70.0f, 30.0f, 30.0f, 0x0, 0x9, 0x32, 0x0, 50.0f},
    {0x21, 0xf, TECHNIQUE_FLAGS_NONE, 80.0f, 10.0f, 18.0f, 70.0f, 30.0f, 30.0f, 0x0, 0x9, 0x32, 0x0, 50.0f},
    {0x22, 0x2a, TECHNIQUE_FLAGS_FOIE_GIFOIE, 80.0f, 10.0f, 18.0f, 70.0f, 30.0f, 30.0f, 0x0, 0x9, 0x3c, 0x1e, 50.0f},
    {0x23, 0x21, TECHNIQUE_FLAGS_ZONDE_RAZONDE, 80.0f, 10.0f, 18.0f, 70.0f, 30.0f, 30.0f, 0x6, 0x9, 0x3c, 0x32, 50.0f},
    {0x24, 0xb, TECHNIQUE_FLAGS_NONE, 100.0f, 10.0f, 15.0f, 40.0f, 30.0f, 50.0f, 0x0, 0x9, 0x64, 0x32, 50.0f},
    {0x25, 0x1a, TECHNIQUE_FLAGS_NONE, 100.0f, 10.0f, 15.0f, 40.0f, 30.0f, 100.0f, 0x0, 0x9, 0x3c, 0x0, 50.0f},
    {0x26, 0x23, TECHNIQUE_FLAGS_NONE, 200.0f, 10.0f, 15.0f, 60.0f, 30.0f, 30.0f, 0x0, 0x0, 0x3c, 0x0, 50.0f},
    {0x27, 0x1c, TECHNIQUE_FLAGS_FOIE_GIFOIE, 120.0f, 10.0f, 15.0f, 50.0f, 30.0f, 100.0f, 0x7, 0x9, 0x3c, 0x1e, 50.0f},
    {0x28, 0x14, TECHNIQUE_FLAGS_BARTA_GIBARTA, 200.0f, 10.0f, 18.0f, 60.0f, 30.0f, 30.0f, 0x4, 0x9, 0x3c, 0x1e, 50.0f},
    {0x29, 0x1b, TECHNIQUE_FLAGS_FOIE_GIFOIE, 80.0f, 10.0f, 18.0f, 60.0f, 30.0f, 30.0f, 0x4, 0x9, 0x3c, 0x32, 50.0f},
    {0x2a, 0x1d, TECHNIQUE_FLAGS_FOIE_GIFOIE, 60.0f, 10.0f, 25.0f, 45.0f, 30.0f, 30.0f, 0x9, 0x9, 0x64, 0x32, 50.0f},
    {0x2b, 0x22, TECHNIQUE_FLAGS_NONE, 120.0f, 10.0f, 15.0f, 30.0f, 30.0f, 100.0f, 0x0, 0x9, 0x3c, 0x0, 50.0f},
    {0x2c, 0x9, TECHNIQUE_FLAGS_ZONDE_RAZONDE, 80.0f, 10.0f, 18.0f, 60.0f, 30.0f, 30.0f, 0x9, 0x9, 0x64, 0x32, 50.0f},
    {0x2d, 0x9, TECHNIQUE_FLAGS_FOIE_GIFOIE_NO_BACKOFF, 300.0f, 10.0f, 15.0f, 30.0f, 30.0f, 100.0f, 0x0, 0x9, 0x32, 0x1e, 50.0f},
    {0x2e, 0x9, TECHNIQUE_FLAGS_NONE, 200.0f, 10.0f, 15.0f, 60.0f, 30.0f, 30.0f, 0x0, 0x9, 0x46, 0x0, 50.0f},
    {0x2f, 0x9, TECHNIQUE_FLAGS_NONE, 80.0f, 10.0f, 18.0f, 60.0f, 30.0f, 30.0f, 0x0, 0x9, 0x32, 0x0, 50.0f},
    {0x30, 0x9, TECHNIQUE_FLAGS_NONE, 120.0f, 10.0f, 15.0f, 30.0f, 30.0f, 100.0f, 0x0, 0x9, 0x37, 0x0, 50.0f},
    {0x31, 0x9, TECHNIQUE_FLAGS_NONE, 120.0f, 10.0f, 15.0f, 30.0f, 30.0f, 100.0f, 0x0, 0x9, 0x46, 0x0, 50.0f},
    {0x32, 0x9, TECHNIQUE_FLAGS_NONE, 120.0f, 10.0f, 15.0f, 50.0f, 30.0f, 100.0f, 0x0, 0x9, 0x41, 0x0, 50.0f},
    {0x33, 0x9, TECHNIQUE_FLAGS_NONE_NO_BACKOFF, 200.0f, 10.0f, 20.0f, 20.0f, 30.0f, 80.0f, 0x0, 0x9, 0x19, 0x0, 30.0f},
    {0x34, 0x9, TECHNIQUE_FLAGS_NONE_NO_BACKOFF, 200.0f, 10.0f, 40.0f, 40.0f, 30.0f, 80.0f, 0x0, 0x9, 0x23, 0x0, 70.0f},
    {0x35, 0x9, TECHNIQUE_FLAGS_ZONDE_RAZONDE, 200.0f, 10.0f, 15.0f, 60.0f, 30.0f, 30.0f, 0x4, 0x9, 0x3c, 0x1e, 50.0f},
    {0x36, 0x9, TECHNIQUE_FLAGS_NONE_NO_BACKOFF, 200.0f, 10.0f, 40.0f, 40.0f, 30.0f, 80.0f, 0x0, 0x9, 0x3c, 0x0, 50.0f},
    {0x37, 0x9, TECHNIQUE_FLAGS_BARTA_GIBARTA_NO_BACKOFF, 150.0f, 10.0f, 25.0f, 45.0f, 30.0f, 120.0f, 0x6, 0x9, 0x32, 0x50, 50.0f},
    {0x38, 0x23, TECHNIQUE_FLAGS_BARTA_GIBARTA_NO_BACKOFF, 300.0f, 10.0f, 40.0f, 40.0f, 20.0f, 150.0f, 0xc, 0xc, 0x3c, 0x46, 50.0f},
    {0x39, 0x9, TECHNIQUE_FLAGS_FOIE_GIFOIE, 100.0f, 10.0f, 25.0f, 45.0f, 30.0f, 80.0f, 0x0, 0x9, 0x32, 0x50, 50.0f},
    {0x3a, 0x9, TECHNIQUE_FLAGS_NONE, 120.0f, 10.0f, 15.0f, 30.0f, 30.0f, 100.0f, 0x0, 0x9, 0x1e, 0x0, 50.0f},
    {0x3b, 0x9, TECHNIQUE_FLAGS_FOIE_GIFOIE, 60.0f, 10.0f, 25.0f, 45.0f, 30.0f, 50.0f, 0x0, 0x9, 0x64, 0x32, 50.0f},
    {0x3c, 0x9, TECHNIQUE_FLAGS_FOIE_GIFOIE, 60.0f, 10.0f, 13.0f, 45.0f, 30.0f, 50.0f, 0x0, 0x9, 0x64, 0x32, 50.0f},
    {0x3d, 0x9, TECHNIQUE_FLAGS_FOIE_GIFOIE, 60.0f, 10.0f, 15.0f, 45.0f, 30.0f, 30.0f, 0x0, 0x9, 0x64, 0x32, 50.0f},
    {0x3e, 0x9, TECHNIQUE_FLAGS_FOIE_GIFOIE, 60.0f, 10.0f, 25.0f, 45.0f, 30.0f, 30.0f, 0x9, 0x9, 0x32, 0x50, 50.0f},
    {0x3f, 0x9, TECHNIQUE_FLAGS_FOIE_GIFOIE, 60.0f, 10.0f, 25.0f, 45.0f, 30.0f, 30.0f, 0x1, 0x9, 0x1e, 0x32, 50.0f},
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
extern void *__vt__10TNpcPlayer[];


extern s32 lbl_805D6EA0;


void TUnk_804AF7B0::run_task() {
    s32 temp_r0;
    saddr temp_r31;

    temp_r31 = (saddr)m_up;
    if (((TObjFogCollisionPoison *)temp_r31)->check_switch() != 0) {
        if (((TObjFogCollision *)temp_r31)->check_collision(client) != 0) {
            ((TObjFogCollisionPoison *)temp_r31)->record_poison_hit(client);
            damage_timer++;
            if (damage_timer >= damage_interval) {
                ((TObjFogCollisionPoison *)temp_r31)->apply_poison_damage(client);
                damage_timer = 0;
                damage_interval = 0x1E;
            }
            contact_ticks++;
        } else {
            damage_interval = 0x96;
            contact_ticks = 0;
        }
        temp_r0 = contact_ticks;
        if (temp_r0 == 1) {
            TObjFogCollisionPoison__sub_801535D0(temp_r31);
            return;
        }
        if (temp_r0 > 0x3C) {
            TObjFogCollisionPoison__sub_80153520(temp_r31);
        }
    }
}

u16 TObjPlayer::get_npc_controller() { return npc_control.controller_client_id; }

int get_registered_object_count(void) {  return registered_entity_count; }

void TFontSmallLobby__sub_80152F28(Obj_80152F28 *self) {
    self->a = 0xFFFF;
    self->b = 0;
}

void* fn_80152EF8(void* p) { TFontSmallLobby__sub_80152F28((Obj_80152F28 *)(p)); return p; }

void set_type__10TNpcPlayerFPvs(void* p, s16 v) { *(s16*)((char*)p + 0x0) = v; }

void set_state__10TNpcPlayerFPvs(void* p, s16 v) { *(s16*)((char*)p + 0x2) = v; }

void TNpcPlayer::byteswap_pos() { bswap_16((u16 *)this); bswap_16((u16 *)((char*)this + 0x2)); }

void TNpcPlayer::set_state(s32 v) { *(s32*)((char*)this + 0x0) = v; }

void TNpcPlayer::set_field_0(s16 v) { *(s16*)((char*)this + 0x0) = v; }

void TNpcPlayer::set_field2(s16 v) { *(s16*)((char*)this + 0x2) = v; }

void init_6x40_walk_packet(void* a0) { *(float*)((char*)a0 + 0x8) = 0.0f; *(float*)((char*)a0 + 0x4) = 0.0f; *(int*)((char*)a0 + 0xc) = 0; *(unsigned char*)((char*)a0 + 0x0) = 64; *(unsigned char*)((char*)a0 + 0x1) = 4; }

void TNpcPlayer::swap_endian() { ((G_ClientIDHeader *)this)->bswap(); ((VectorXZF *)((char*)this + 0x4))->bswap(); bswap_32((u32 *)((char*)this + 0xc)); }

void TNpcPlayer::sync_from_lobby() { swap_endian(); ((TLobby *)this)->update_players(); }

void TNpcPlayer::reset_move_state() { *(float*)((char*)this + 0x8) = 0.0f; *(float*)((char*)this + 0x4) = 0.0f; *(unsigned char*)((char*)this + 0x0) = 66; *(unsigned char*)((char*)this + 0x1) = 3; }

void TNpcPlayer::init_model() { ((G_ClientIDHeader *)this)->bswap(); ((VectorXZF *)((char*)this + 0x4))->bswap(); }

void TNpcPlayer::reset_model() { init_model(); ((TLobby *)this)->update_players(); }

void TNpcPlayer__sub_80152D64(void* p) { *(u8*)((char*)p + 0x3) = 0; *(u8*)((char*)p + 0x2) = 0; *(u8*)((char*)p + 0x1) = 0; *(u8*)((char*)p + 0x0) = 0; }

void *TNpcPlayer::init_cast_technique_cmd() {
    TNpcPlayer__sub_80152D64((void*)((void *)((char *)this + 4)));
    __construct_array((void *)((char *)this + 8), fn_80152EF8, 0, 4, 10);
    *(u8 *)((s8 *)this + 0x0) = 71;
    *(u8 *)((s8 *)this + 0x1) = 12;
    return this;
}

u8 get_6x47_cast_packet_size(u8 *arg0) {
    return (u8) (0x30 - ((0xA - (s8) *(u8 *)((s8 *)arg0 + 7)) * 4));
}

void TNpcPlayer::byteswap_positions() {
    N_80152C8C *arg0 = (N_80152C8C *)this;
    s32 i;
    ((G_ClientIDHeader *)arg0)->bswap();
    for (i = 0; i < arg0->count; i++) {
        ((TNpcPlayer *)(&arg0->pos[i]))->byteswap_pos();
    }
}

void TNpcPlayer::finalize_and_send_packet() {
    u8 *arg0 = (u8 *)this;
    *(s8 *)((s8 *)arg0 + 1) = (s8) ((((u32)get_6x47_cast_packet_size(arg0)) >> 2U) & 0x3F);
    byteswap_positions();
    send_subcommand((u8 *)(arg0));
}

void init_6x43_attack_packet(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 4) = 0;
    *(s16 *)((s8 *)arg0 + 6) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x43;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void bswap_6x43_packet(void* p) { ((G_ClientIDHeader *)p)->bswap(); bswap_16((u16 *)((char*)p + 0x4)); bswap_16((u16 *)((char*)p + 0x6)); }

void TNpcPlayer::update_lobby() { bswap_6x43_packet(this); ((TLobby *)this)->update_players(); }

void init_6x44_attack_packet(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 4) = 0;
    *(s16 *)((s8 *)arg0 + 6) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x44;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void bswap_6x44_packet(void* p) { ((G_ClientIDHeader *)p)->bswap(); bswap_16((u16 *)((char*)p + 0x4)); bswap_16((u16 *)((char*)p + 0x6)); }

void TNpcPlayer::update_players() { bswap_6x44_packet(this); ((TLobby *)this)->update_players(); }

void init_6x45_attack_packet(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 4) = 0;
    *(s16 *)((s8 *)arg0 + 6) = 0;
    *(s8 *)((s8 *)arg0 + 0) = 0x45;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void bswap_6x45_packet(void* p) { ((G_ClientIDHeader *)p)->bswap(); bswap_16((u16 *)((char*)p + 0x4)); bswap_16((u16 *)((char*)p + 0x6)); }

void TNpcPlayer::update() { bswap_6x45_packet(this); ((TLobby *)this)->update_players(); }

void TNpcPlayer__sub_80152A78(s16 *self) {
    s32 i;
    for (i = 0; i < 11; i++) {
        self[i] = 0;
    }
}

void*TNpcPlayer::init() { TNpcPlayer__sub_80152A78((s16 *)this); return this; }

void TNpcPlayer__sub_80152A34(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)arg0 + 0x80) = (s32) *(s32 *)((s8 *)arg0 + 0x7C);
    *(s32 *)((s8 *)arg0 + 0x7C) = arg1;
    *(s32 *)((s8 *)arg0 + 0x84) = arg2;
}

void TNpcPlayer__sub_80152A30(void) {  }

s32 clamp_partner_counter(saddr arg0, s32 arg1, s16 arg2) {
    if (((s32 (*)(void))is_partner_counter_reached)() != 0) {
        *(s16 *)((s8 *)(arg0 + (arg1 * 2)) + 0) = arg2;
        return 1;
    }
    return 0;
}

void TNpcPlayer::reset_fields_8c() { *(s32*)((char*)this + 0x8c) = 0; *(s32*)((char*)this + 0x90) = 0; }

s32 TNpcPlayer::get_action_state() { return *(s32*)((char*)this + 0x8c); }

void copy_transform__10TNpcPlayerFPvPv(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); *(f32*)((char*)p + 0x8) = *(f32*)((char*)q + 0x8); }

void copy_transform_second__10TNpcPlayerFPvPvPv(void* p, void* a1, void* a2) { ((int (*)(void*))copy_transform__10TNpcPlayerFPvPv)(a2); }

s32 TNpcPlayer::get_condition() { return *(s32*)((char*)this + 0x90); }

s32 TNpcPlayer__sub_80152978(void* p) { return *(s32*)((char*)p + 0x80); }

void set_partner_counter(saddr arg0, s32 arg1, s16 arg2) {
    *(s16 *)((s8 *)(arg0 + (arg1 * 2)) + 0) = arg2;
}

int is_partner_counter_reached(s16 *table, s32 idx, s32 value) {
    return value <= table[idx] ? 1 : 0;
}

s32 npc_counter_reset_if_reached(saddr arg0, s32 arg1) {
    if (((s32 (*)(void))is_partner_counter_reached)() != 0) {
        *(s16 *)((s8 *)(arg0 + (arg1 * 2)) + 0) = 0;
        return 1;
    }
    return 0;
}

int get_partner_counter(saddr arg0, s32 arg1) {
    return *(s16 *)((s8 *)(arg0 + (arg1 * 2)) + 0);
}

u16 get_npc_type__10TNpcPlayerFPv(void* p) { return *(u16*)((char*)p + 0x8a); }

s32 TNpcPlayer::get_npc_state() { return *(s32*)((char*)this + 0x7c); }

s32 TNpcPlayer__sub_801528DC(void* p) { return *(s32*)((char*)p + 0x84); }

void increment_partner_counter(saddr arg0, s32 arg1) {
    saddr temp_r5;
    temp_r5 = arg1 * 2;
    *(s16 *)((s8 *)(arg0 + temp_r5) + 0) = *(s16 *)((s8 *)(arg0 + temp_r5) + 0) + 1;
}

void reset_partner_counter(saddr arg0, s32 arg1) {
    *(s16 *)((s8 *)(arg0 + (arg1 * 2)) + 0) = 0;
}

void set_technique_seed_level(Obj_801528A8 *self, s16 i, u8 v) {
    self->arr[i] = v;
}

void __sinit_TNpcPlayer_cpp() {
    __register_global_object(__ct__12TPlyCharDataFv(lbl_8050CFC4), (void *)__dt__12TPlyCharDataFv, npc_player_ply_char_data_global);
}

void TNpcPlayer::ensure_rock_singleton() {
    if (npc_player_char_data_buffer == NULL) {
        npc_player_char_data_buffer = static_cast<disp_data_part2 *>(mem_alloc(64 * sizeof(disp_data_part2)));
    }
}

u8 *TNpcPlayer::build_npc_player_record(s32 arg0) {
    s32 mode;
    s32 diff;
    s32 lvl;
    u16 base;

    if (TNpcPlayer__data_805D5864 != 0) {
        TNpcPlayer__data_805D5864 = 0;
        copy_player_visual_record(&lbl_8050CF68, &lbl_8050D3E0);
    } else {
        copy_player_visual_record(&lbl_8050CF68, &npc_player_char_data_buffer[arg0]);
    }
    bswap__15disp_data_part2Fv((saddr)&lbl_8050CF68);
    mem_free(npc_player_char_data_buffer);
    mode = game_difficulty_selection;
    npc_player_char_data_buffer = NULL;
    if (mode >= 0 && mode <= 2) {
        diff = mode;
    } else {
        diff = 2;
    }
    base = TNpcPlayer__template_table[arg0].base_level;
    lvl = base + diff * 25;
    if (mode == 3) {
        lvl = base + 150;
    }
    if (lvl >= 198) {
        lvl = 198;
    }
    switch (mode) {
    case 0:
        TNpcPlayer::send_command(lbl_8050CF68.char_class, 5, (const TPlyInventoryItem *)lbl_804AF330[arg0], (s32)lvl, (TPlyCharData *)lbl_8050CFC4);
        break;
    case 1:
        TNpcPlayer::send_command(lbl_8050CF68.char_class, 5, (const TPlyInventoryItem *)lbl_804AF430[arg0], (s32)lvl, (TPlyCharData *)lbl_8050CFC4);
        break;
    case 2:
        TNpcPlayer::send_command(lbl_8050CF68.char_class, 5, (const TPlyInventoryItem *)lbl_804AF530[arg0], (s32)lvl, (TPlyCharData *)lbl_8050CFC4);
        break;
    case 3:
        TNpcPlayer::send_command(lbl_8050CF68.char_class, 5, (const TPlyInventoryItem *)lbl_804AF630[arg0], (s32)lvl, (TPlyCharData *)lbl_8050CFC4);
        break;
    default:
        TNpcPlayer::send_command(lbl_8050CF68.char_class, 5, (const TPlyInventoryItem *)lbl_804AF530[arg0], (s32)lvl, (TPlyCharData *)lbl_8050CFC4);
        break;
    }
    copy_player_visual_record(&reinterpret_cast<TPlyCharData *>(lbl_8050CFC4)->m_disp_part2, &lbl_8050CF68);
    return (u8 *)lbl_8050CFC4;
}

u8 *load_npc_player_template(s32 index) {
    s32 mode;
    s32 diff;
    s32 lvl;
    u16 base;

    if (npc_player_char_data_buffer != NULL) {
        return NULL;
    }
    npc_player_char_data_buffer = static_cast<disp_data_part2 *>(mem_alloc(64 * sizeof(disp_data_part2)));
    if (TNpcPlayer__data_805D5864 != 0) {
        TNpcPlayer__data_805D5864 = 0;
        copy_player_visual_record(&lbl_8050CF68, &lbl_8050D3E0);
    } else {
        read_disc_file(lbl_805D2E70, (void *)npc_player_char_data_buffer);
        copy_player_visual_record(&lbl_8050CF68, &npc_player_char_data_buffer[index]);
    }
    bswap__15disp_data_part2Fv((saddr)&lbl_8050CF68);
    mem_free(npc_player_char_data_buffer);
    mode = game_difficulty_selection;
    npc_player_char_data_buffer = NULL;
    if (mode >= 0 && mode <= 2) {
        diff = mode;
    } else {
        diff = 2;
    }
    base = TNpcPlayer__template_table[index].base_level;
    lvl = base + diff * 25;
    if (mode == 3) {
        lvl = base + 150;
    }
    if (lvl >= 198) {
        lvl = 198;
    }
    switch (mode) {
    case 0:
        TNpcPlayer::send_command(lbl_8050CF68.char_class, 5, (const TPlyInventoryItem *)lbl_804AF330[index], (s32)lvl, (TPlyCharData *)lbl_8050CFC4);
        break;
    case 1:
        TNpcPlayer::send_command(lbl_8050CF68.char_class, 5, (const TPlyInventoryItem *)lbl_804AF430[index], (s32)lvl, (TPlyCharData *)lbl_8050CFC4);
        break;
    case 2:
        TNpcPlayer::send_command(lbl_8050CF68.char_class, 5, (const TPlyInventoryItem *)lbl_804AF530[index], (s32)lvl, (TPlyCharData *)lbl_8050CFC4);
        break;
    case 3:
        TNpcPlayer::send_command(lbl_8050CF68.char_class, 5, (const TPlyInventoryItem *)lbl_804AF630[index], (s32)lvl, (TPlyCharData *)lbl_8050CFC4);
        break;
    default:
        TNpcPlayer::send_command(lbl_8050CF68.char_class, 5, (const TPlyInventoryItem *)lbl_804AF330[index], (s32)lvl, (TPlyCharData *)lbl_8050CFC4);
        break;
    }
    copy_player_visual_record(&reinterpret_cast<TPlyCharData *>(lbl_8050CFC4)->m_disp_part2, &lbl_8050CF68);
    return (u8 *)lbl_8050CFC4;
}

TNpcPlayer *construct_partner__10TNpcPlayerFPviisPv(TNpcPlayer *self, s32 a, s32 b, s16 kind, void *parent) {
    void *p;

    __ct__7TObjectFP7TObject(self, parent);
    *(void ***)((u8 *)self + 0x18) = __vt__10TNpcPlayer;
    ((TNpcPlayer *)self->m_5c)->init();
    self->m_name = TNpcPlayer__name;
    self->m_24 = 0x19;
    self->m_1c = 0;
    self->m_20 = 0;
    self->m_ac.x = 0.0f;
    self->m_ac.y = 0.0f;
    self->m_ac.z = 0.0f;
    self->m_d0.x = 0.0f;
    self->m_d0.y = 0.0f;
    self->m_d0.z = 0.0f;
    self->m_dc.x = 0.0f;
    self->m_dc.y = 0.0f;
    self->m_dc.z = 0.0f;
    self->m_c4 = 0;
    self->m_c8 = 0;
    self->m_cc = 0;
    self->m_2c = kind;
    self->m_80 = 0;
    self->m_7c = 0;
    self->m_88 = 0.0f;
    self->m_58 = 0.0f;
    self->m_8c = 0;
    self->m_8e = 0;
    self->m_8d = 0;
    p = ::operator new(0x108);
    if (p != 0) {
        p = ((void *(*)(void *, u16))init_ai_state__10TNpcPlayerFPvi)(p, a);
    }
    self->m_74 = (Unk_8014F844 *)p;
    p = ::operator new(0x108);
    if (p != 0) {
        p = ((void *(*)(void *, u16))init_ai_state__10TNpcPlayerFPvi)(p, b);
    }
    self->m_78 = (Unk_8014F844 *)p;
    self->ai_params.copy(&TNpcPlayer__template_table[self->m_2c]);
    if (self->m_78 != 0 && self->m_78->m_94 != 0) {
        VecCopy(&self->m_dc, &self->m_78->m_94->position);
        self->init_equipment();
    }
    self->m_84 = 0;
    return self;
}

void TNpcPlayer::AiParams::copy(AiParams *src) {
    npc_id = src->npc_id;
    base_level = src->base_level;
    technique_flags = src->technique_flags;
    enemy_lock_on_range = src->enemy_lock_on_range;
    unknown_0C = src->unknown_0C;
    max_distance_from_player = src->max_distance_from_player;
    enemy_unlock_range = src->enemy_unlock_range;
    block_range = src->block_range;
    attack_range = src->attack_range;
    attack_technique_level = src->attack_technique_level;
    support_technique_level = src->support_technique_level;
    attack_probability = src->attack_probability;
    attack_technique_probability = src->attack_technique_probability;
    unknown_24 = src->unknown_24;
}

TNpcPlayer *TNpcPlayer__ct(TNpcPlayer *self, s32 a, s32 b, s16 kind, s32 arg4, void *parent) {
    void *p;

    __ct__7TObjectFP7TObject(self, parent);
    *(void ***)((u8 *)self + 0x18) = __vt__10TNpcPlayer;
    ((TNpcPlayer *)self->m_5c)->init();
    self->m_name = TNpcPlayer__name;
    self->m_24 = 0x19;
    self->m_1c = 0;
    self->m_20 = 0;
    self->m_ac.x = 0.0f;
    self->m_ac.y = 0.0f;
    self->m_ac.z = 0.0f;
    self->m_d0.x = 0.0f;
    self->m_d0.y = 0.0f;
    self->m_d0.z = 0.0f;
    self->m_dc.x = 0.0f;
    self->m_dc.y = 0.0f;
    self->m_dc.z = 0.0f;
    self->m_c4 = 0;
    self->m_c8 = 0;
    self->m_cc = 0;
    self->m_2c = kind;
    self->m_80 = 0;
    self->m_7c = 0;
    self->m_88 = 0.0f;
    self->m_58 = 0.0f;
    self->m_8c = 0;
    self->m_8e = 0;
    self->m_8d = 0;
    p = ::operator new(0x108);
    if (p != 0) {
        p = ((void *(*)(void *, u16))init_ai_state__10TNpcPlayerFPvi)(p, a);
    }
    self->m_74 = (Unk_8014F844 *)p;
    p = ::operator new(0x108);
    if (p != 0) {
        p = ((void *(*)(void *, u16))init_ai_state__10TNpcPlayerFPvi)(p, b);
    }
    self->m_78 = (Unk_8014F844 *)p;
    self->ai_params.copy(&TNpcPlayer__template_table[self->m_2c]);
    if (self->m_78 != 0 && self->m_78->m_94 != 0) {
        VecCopy(&self->m_dc, &self->m_78->m_94->position);
        self->init_equipment();
    }
    self->m_84 = arg4;
    return self;
}

TNpcPlayer::~TNpcPlayer() {
    uaddr player;
    Unk_8014F844 *view;
    Unk_8014F844 *partner;
    view = m_74;
    if (view != NULL) {
        ((TNpcPlayer *)view)->dt(1);
        m_74 = NULL;
    }
    partner = m_78;
    if (partner != NULL) {
        player = (uaddr)get_player_by_client_id(get_npc_type__10TNpcPlayerFPv(partner));
        if (player != 0U) {
            TObjPlayer::send_item_pickup_request((saddr)player);
        }
        ((TNpcPlayer *)m_78)->dt(1);
        m_78 = NULL;
    }
}

void TNpcPlayer::run_task() {
    Unk_8014F844 *owner;
    owner = m_74;
    if (owner == NULL || m_78 == NULL) {
        return;
    }
    if (refresh_npc_view_actor_lost(owner) != 0) {
        queue_destruction();
        return;
    }
    if (refresh_npc_view_actor_lost(m_78) != 0) {
        queue_destruction();
        return;
    }
    if ((m_78->m_94->is_inactive() != 0) && ((m_78->m_94 == NULL) || (((TObjPlayer *)m_78->m_94)->get_npc_controller() != 0xFFFF))) {
        init_state();
        if (!(m_74->m_94->actorFlags & 0x800)) {
            if (m_78->m_94->actorFlags & 0x800) {
                if (((s32 (*)(void *, int, int))clamp_partner_counter)(m_5c, 3, 0x400) != 0) {
                    request_chatter(5);
                } else if (((s32 (*)(void *, int, int))is_partner_counter_reached)(m_5c, 3, 0) != 0) {
                    request_chatter(4);
                }
                increment_partner_counter((saddr)m_5c, 3);
                change_ai_state(0);
            } else {
                reset_partner_counter((saddr)m_5c, 3);
                update_condition_flags();
                ((s32 (*)(void *))partner_observe_surroundings)(this);
                decide_action();
                update_follow_target();
            }
            deliver_partner_action();
        }
    }
}

void TNpcPlayer::decide_action() {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 var_f31;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    if ((get_current_floor_area() == AREA_PIONEER2_EP1) || (get_current_floor_area() == AREA_PIONEER2_EP2)) {
        calc_follow_goal();
        change_ai_state(1);
        return;
    }
    switch (m_1c) {
    case 0:
        if (((TNpcPlayer *)m_78)->get_action_state() & 2) {
            m_1c = 1;
            change_ai_state(0);
            return;
        }
        m_80 = m_80 & 0xFFFFFEFF;
        if (select_recovery_action(1) != 0) {
            temp_r3 = m_80;
            if (temp_r3 & 0x200) {
                request_chatter(0x13);
                change_ai_state(8);
                return;
            }
            m_80 = temp_r3 & 0xFFFFFDFF;
            if (((f32 (*)(void *, void *))horizontal_distance_squared)(&m_dc, &m_78->m_94->position) < 900.0f) {
                change_ai_state(8);
                return;
            }
            calc_follow_goal();
            change_ai_state(1);
            return;
        }
        calc_follow_goal();
        change_ai_state(1);
        m_8e = 0;
        return;
    case 1:
        var_f31 = 1.0f;
        if (m_80 & 0x8000) {
            var_f31 = 2.0f;
        }
        if ((m_78->m_94->can_perform_physical_action() != 0) && (m_8e == 0)) {
            temp_f1 = fabs_float(10.0f * (3.0517578125e-05f * (f32) rand()));
            temp_f0 = 0.1f * (f32) ai_params.attack_probability;
            temp_f0 *= var_f31;
            if (temp_f1 < temp_f0) {
                m_8e = 0;
            } else {
                m_8e = (s16) (10.0f * (temp_f1 - temp_f0));
            }
        }
        m_8e = (s16) (m_8e - 1);
        if (m_8e < 0) {
            m_8e = 0;
        }
        if ((check_return_to_leader() != 0) && (m_84 == 0)) {
            if (select_recovery_action(0) != 0) {
                request_chatter(0x13);
                change_ai_state(8);
                m_80 = m_80 & 0xFFFFFF7F;
            } else {
                temp_r3_2 = m_80;
                if (temp_r3_2 & 0x80) {
                    m_80 = temp_r3_2 & 0xFFFFFF7F;
                    if (m_8e == 0) {
                        change_ai_state(2);
                    }
                } else {
                    calc_follow_goal();
                    change_ai_state(1);
                }
            }
        } else if (select_recovery_action(1) != 0) {
            ((s32 (*)(void *, int))reset_partner_counter)((void *) (m_5c), 8);
            temp_r3_3 = m_80;
            if (temp_r3_3 & 0x200) {
                request_chatter(0x13);
                change_ai_state(8);
            } else if (temp_r3_3 & 0x80) {
                m_80 = temp_r3_3 & ~0x280;
                if (m_8e == 0) {
                    change_ai_state(2);
                }
            } else {
                m_80 = temp_r3_3 & 0xFFFFFDFF;
                if (((f32 (*)(void *, void *))horizontal_distance_squared)(&m_dc, &m_78->m_94->position) < 900.0f) {
                    change_ai_state(8);
                } else if (m_84 != 0) {
                    if (m_8e == 0) {
                        change_ai_state(2);
                    }
                } else {
                    calc_follow_goal();
                    change_ai_state(1);
                }
            }
        } else if ((choose_attack_target() != 0) && (m_8e == 0)) {
            if (m_80 & 0x1000) {
                change_ai_state(2);
                m_80 = m_80 & 0xFFFFEFFF;
            } else {
                change_ai_state(1);
            }
            m_80 = m_80 & 0xFFFFEFFF;
        } else {
            if (m_84 != 0) {
                calc_follow_goal();
            } else {
                VecCopy(&m_dc, &m_78->m_94->position);
            }
            change_ai_state(1);
        }
        if (!(((TNpcPlayer *)m_78)->get_action_state() & 2)) {
            m_1c = 0;
        }
        return;
    }
}

s32 TNpcPlayer::update_follow_target() {
    if (((s32 (*)())needs_movement__10TNpcPlayerFPvPvi)() != 0) {
        ((s32 (*)(void *))select_path_waypoint__10TNpcPlayerFv)(this);
        if (check_movement_progress() != 0) {
            VecCopy(&m_ac, &m_d0);
            if ((u32) m_7c != 2U) {
                change_ai_state(1);
            }
        } else {
            VecCopy(&m_ac, &m_78->m_94->position);
        }
        return 1;
    }
    if ((m_80 & 0x20) && ((u32) m_7c != 8U)) {
        change_ai_state(0);
    }
    return 0;
}

s32 TNpcPlayer::check_return_to_leader() {
    Unk_8014F844 *t;
    u8 *o;
    f32 r2;

    t = ((Unk_8014F844 *(*)(void *))TNpcPlayer__sub_80152A30)(m_78);
    r2 = ai_params.enemy_unlock_range * ai_params.enemy_unlock_range;
    if (((TNpcPlayer *)m_74)->get_action_state() & 2) {
        m_80 &= ~0x100;
        return 0;
    }
    if (((TNpcPlayer *)m_78)->get_condition() & 8) {
        m_80 |= 0x100;
        return 1;
    }
    if (m_58 >= r2) {
        m_80 |= 0x100;
        if (t->m_0 != 0) {
            ((s32 (*)(void *, s32))increment_partner_counter)(m_5c, 5);
            if (((s32 (*)(void *, int, int))npc_counter_reset_if_reached)(m_5c, 5, 3) != 0) {
                o = (u8 *)find_active_entity_by_id(t->m_4[0].m_0);
                m_80 &= ~0x8000;
                if (o != 0) {
                    if (((f32 (*)(void *, void *))horizontal_distance_squared)(o + 0x38, &m_78->m_94->position) < ai_params.block_range * ai_params.block_range) {
                        m_80 |= 0x8080;
                    }
                }
            }
        }
        return 1;
    }
    if (m_80 & 0x100) {
        return 1;
    }
    m_80 &= ~0x100;
    return 0;
}

s32 TNpcPlayer::choose_attack_target() {
    s32 i;
    Unk_8014F844 *view;
    TObjBase *tgt;
    view = ((Unk_8014F844 *(*)(void *))TNpcPlayer__sub_80152A30)(m_78);
    if (view->m_0 >= 3) {
        m_80 |= 0x2000;
        ((s32 (*)(void *, s32))increment_partner_counter)(m_5c, 6);
        if (((s32 (*)(void *, int, int))npc_counter_reset_if_reached)(m_5c, 6, 100) != 0) {
            if (((TNpcPlayer *)m_78)->get_condition() & 8) {
                request_chatter(1);
            } else {
                request_chatter(0);
            }
        }
    } else {
        m_80 &= ~0x2000;
    }
    if (view->m_0 != 0) {
        for (i = 0; i < view->m_0; i++) {
            if (((s32 (*)(void *, u32))is_target_line_clear__10TNpcPlayerFPvUs)(m_78, view->m_4[i].m_0) != 0) {
                tgt = (TObjBase *)find_active_entity_by_id(view->m_4[0].m_0);
                ((void (*)(void *, u32, s32))TNpcPlayer__sub_80152A34)(m_78, view->m_4[i].m_0, view->m_4[i].m_4);
                m_dc.x = tgt->position.x;
                m_dc.y = m_78->m_94->body_center.y;
                m_dc.z = tgt->position.z;
                if (((f32 (*)(void *, void *))horizontal_distance_squared)(&m_dc, &m_78->m_94->position) < (10.0f + ai_params.attack_range) * (10.0f + ai_params.attack_range)) {
                    m_80 |= 0x1000;
                }
                m_80 &= ~0x40;
                return 1;
            }
        }
        request_chatter(8);
        m_80 |= 0x40;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
s32 TNpcPlayer::calc_follow_goal() {
    Vec dir;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    TObjPlayer *obj_player;
    if (m_84 != 0) {
        if (ai_params.technique_flags & 0x80) {
            temp_f0 = ai_params.unknown_24;
            if (m_88 <= (temp_f0 * temp_f0)) {
                obj_player = m_78->m_94;
                dir.x = m_dc.x - obj_player->position.x;
                temp_f2 = m_dc.z;
                temp_f1 = temp_f2 - obj_player->position.z;
                dir.y = 0.0f;
                dir.z = temp_f1;
                if (0.0f != vector_length(&dir)) {
                    normalize_vector(&dir);
                }
                m_dc.x = -((ai_params.unknown_24 * dir.x) - m_dc.x);
                m_dc.z = -((ai_params.unknown_24 * dir.z) - m_dc.z);
                m_dc.y = m_78->m_94->body_center.y;
            } else {
                VecCopy(&m_dc, &m_74->m_94->body_center);
            }
        } else {
            VecCopy(&m_dc, &m_74->m_94->body_center);
        }
    } else {
        VecCopy(&m_dc, &m_74->m_94->body_center);
    }
    return 1;
}
#pragma pop

s32 TNpcPlayer::select_recovery_action(s32 arg1) {
    TNpcPlayer * self = this;
    u8 flags = 0;
    Unk_8014F844 *tgt;
    TObjBase *ent;
    if (((TNpcPlayer *)self->m_78)->get_action_state() & 4) {
        flags |= 1;
    }
    if (arg1 != 0 && (((TNpcPlayer *)self->m_74)->get_action_state() & 4) && self->m_84 == 0) {
        flags |= 2;
    }
    tgt = ((Unk_8014F844 *(*)(void *))TNpcPlayer__sub_80152A30)(self->m_78);
    if (arg1 != 0 && tgt->m_0 != 0 && (flags & 2)) {
        ((s32 (*)(void *, s32))increment_partner_counter)(self->m_5c, 5);
        if (((s32 (*)(void *, int, int))npc_counter_reset_if_reached)(self->m_5c, 5, 0x1E) != 0) {
            ent = (TObjBase *)find_active_entity_by_id(tgt->m_4[0].m_0);
            self->m_80 &= ~0x8000;
            if (ent != NULL) {
                if (((f32 (*)(void *, void *))horizontal_distance_squared)(&ent->position, &self->m_78->m_94->position) < self->ai_params.block_range * self->ai_params.block_range) {
                    VecCopy(&self->m_dc, &ent->position);
                    self->m_80 |= 0x8080;
                    return 1;
                }
            }
        }
    }
    if (flags == 3) {
        self->m_80 |= 0x200;
        if (((TNpcPlayer *)self->m_78)->get_condition() & 2) {
            if (((TNpcPlayer *)self->m_78)->try_attack(2, 1) != 0) {
                if (((TNpcPlayer *)self->m_78)->get_condition() & 0x20) {
                    self->m_92 = 2;
                    return 1;
                }
                if (!(self->ai_params.technique_flags & 0x40)) {
                    self->m_92 = 2;
                    return 1;
                }
            }
        } else if (((TNpcPlayer *)self->m_78)->get_condition() & 8) {
            if (((TNpcPlayer *)self->m_78)->try_attack(0, 1) != 0) {
                if (((TNpcPlayer *)self->m_78)->get_condition() & 0x20) {
                    self->m_92 = 0;
                    return 1;
                }
                if (!(self->ai_params.technique_flags & 0x40)) {
                    self->m_92 = 0;
                    return 1;
                }
            } else {
                if (((s16 (*)(void *, int))get_partner_counter)(self->m_5c, 8) == 0) {
                    self->request_chatter(0x14);
                }
                ((s32 (*)(void *, s32))increment_partner_counter)(self->m_5c, 8);
                ((s32 (*)(void *, int, int))npc_counter_reset_if_reached)(self->m_5c, 8, 0x5DC);
            }
        } else if (((TNpcPlayer *)self->m_78)->get_condition() & 0x10) {
            if (((TNpcPlayer *)self->m_78)->try_attack(1, 1) != 0) {
                self->m_92 = 1;
                return 1;
            }
        } else {
            flags = 2;
        }
    }
    if (flags == 2) {
        if (((TNpcPlayer *)self->m_78)->get_action_state() & 2) {
            return 0;
        }
        VecCopy(&self->m_dc, &self->m_74->m_94->body_center);
        self->m_80 |= 0x20;
        if (((TNpcPlayer *)self->m_74)->get_condition() & 2) {
            if (((TNpcPlayer *)self->m_78)->try_attack(2, 0) != 0) {
                if (((TNpcPlayer *)self->m_78)->get_condition() & 0x20) {
                    self->m_92 = 2;
                    return 1;
                }
                if (!(self->ai_params.technique_flags & 0x40)) {
                    self->m_92 = 2;
                    return 1;
                }
            }
        } else if (((TNpcPlayer *)self->m_74)->get_condition() & 0x800) {
            if (((TNpcPlayer *)self->m_78)->try_attack(0, 0) != 0) {
                if (((TNpcPlayer *)self->m_78)->get_condition() & 0x20) {
                    self->m_92 = 0;
                    return 1;
                }
                if (!(self->ai_params.technique_flags & 0x40)) {
                    self->m_92 = 0;
                    return 1;
                }
            }
        }
    }
    if (flags == 1) {
        self->m_80 |= 0x200;
        if (((TNpcPlayer *)self->m_78)->get_condition() & 2) {
            if (((TNpcPlayer *)self->m_78)->try_attack(2, 1) != 0) {
                if (((TNpcPlayer *)self->m_78)->get_condition() & 0x20) {
                    self->m_92 = 2;
                    return 1;
                }
                if (!(self->ai_params.technique_flags & 0x40)) {
                    self->m_92 = 2;
                    return 1;
                }
            }
        } else if (((TNpcPlayer *)self->m_78)->get_condition() & 8) {
            if (((TNpcPlayer *)self->m_78)->try_attack(0, 1) != 0) {
                if (((TNpcPlayer *)self->m_78)->get_condition() & 0x20) {
                    self->m_92 = 0;
                    return 1;
                }
                if (!(self->ai_params.technique_flags & 0x40)) {
                    self->m_92 = 0;
                    return 1;
                }
            } else {
                if (((s16 (*)(void *, int))get_partner_counter)(self->m_5c, 8) == 0) {
                    self->request_chatter(0x14);
                }
                ((s32 (*)(void *, s32))increment_partner_counter)(self->m_5c, 8);
                ((s32 (*)(void *, int, int))npc_counter_reset_if_reached)(self->m_5c, 8, 0x5DC);
            }
        } else if (((TNpcPlayer *)self->m_78)->get_condition() & 0x10) {
            if (((TNpcPlayer *)self->m_78)->try_attack(1, 1) != 0) {
                self->m_92 = 1;
                return 1;
            }
        }
    }
    return 0;
}

#pragma push
#pragma opt_common_subs off
void TNpcPlayer::deliver_partner_action() {
    Vec d;
    f32 len;

    if ((m_80 & 4) && !(lbl_805D6EA0 & 2)) {
        deliver_partner_chatter(this);
    }
    if (m_78->m_94->test_action_mask(2) == 0) {
        return;
    }
    switch (m_7c) {
    case 0:
        VecCopy(&m_ac, VecCopy(&m_d0, &m_dc));
        increment_partner_counter((saddr)m_5c, 4);
        if ((s16)get_partner_counter((saddr)m_5c, 4) == 5401) {
            m_80 &= ~4;
            m_24 = 25;
            set_partner_counter((saddr)m_5c, 4, 0);
        }
        if (clamp_partner_counter((saddr)m_5c, 4, 5400) != 0) {
            request_chatter(11);
        }
        break;
    case 1:
        d.x = m_ac.x - m_78->m_94->position.x;
        d.y = 0.0f;
        d.z = m_ac.z - m_78->m_94->position.z;
        len = vector_length(&d);
        if (len <= 1.0f) {
            return;
        }
        if (m_78->m_94->actorFlags & 0x100000) {
            send_walk_request();
        } else if (len <= ai_params.max_distance_from_player) {
            if (!(m_80 & 8)) {
                send_walk_request();
            } else {
                send_run_request();
            }
        } else {
            m_80 |= 8;
            send_run_request();
        }
        break;
    case 2:
        update_combat_action();
        break;
    case 4:
        break;
    case 8:
        dispatch_action(m_92);
        break;
    }
    if (m_7c != 2) {
        reset_partner_counter((saddr)m_5c, 1);
        reset_partner_counter((saddr)m_5c, 5);
        m_80 &= ~0x8000;
    }
    if (m_7c != 1) {
        m_80 &= ~8;
    }
    if (m_7c != 0) {
        reset_partner_counter((saddr)m_5c, 4);
    }
}
#pragma pop

void TNpcPlayer::send_walk_request() {
    Msg_80150E44 m;
    init_6x40_walk_packet(&m);
    if (m_78 != 0) {
        m.type = get_npc_type__10TNpcPlayerFPv(m_78);
        m.x = m_ac.x;
        m.z = m_ac.z;
        m.flags = 0;
        if (m_78->m_94->actorFlags & 0x100000) {
            m.flags |= 8;
        }
        ((TNpcPlayer *)(&m))->sync_from_lobby();
    }
}

void TNpcPlayer::send_run_request() {
    Msg_80150DE8 m;
    ((TNpcPlayer *)(&m))->reset_move_state();
    if (m_78 != 0) {
        m.type = get_npc_type__10TNpcPlayerFPv(m_78);
        m.x = m_ac.x;
        m.z = m_ac.z;
        ((TNpcPlayer *)(&m))->reset_model();
    }
}

void TNpcPlayer::update_combat_action() {
    s32 tier;
    s32 alt;
    s32 id;
    Tec_80150B90 *tec;
    u32 fl;
    f32 diff;
    f32 mx;

    if (((u32 (*)(void *))TNpcPlayer__sub_80152978)(m_78) == 0xFFFF) {
        return;
    }
    if (m_78->m_94->can_perform_physical_action() == 0) {
        return;
    }
    if (!(ai_params.technique_flags & 0x40) && !(((TNpcPlayer *)m_78)->get_condition() & 0x10)) {
        fl = ai_params.technique_flags;
        if (fl & 4) {
            tier = 0;
        } else if (fl & 8) {
            tier = 1;
        } else if (fl & 0x10) {
            tier = 2;
        } else {
            tier = 0;
        }
        if ((m_80 & 0x2000) && (((TNpcPlayer *)m_78)->get_condition() & 0x1000)) {
            alt = 1;
        } else {
            alt = 0;
        }
        if (alt == 0) {
            if (fabs_float(10.0f * (3.0517578125e-05f * (f32)rand())) >
                0.1f * (f32)ai_params.attack_technique_probability) {
                partner_request_physical_attack();
                return;
            }
        }
        id = npc_player_combat_action_table[tier][alt];
        tec = calc_technique_parameters(id, *(s8 *)&ai_params.attack_technique_level, 0xFFFF);
        diff = (f32)(get_actor_tp((u8 *)m_78->m_94) - tec->f10);
        mx = (f32)obj_getS16_2BA((u8 *)m_78->m_94);
        if (diff / mx <= 0.2f && 0.0f != mx) {
            request_chatter(3);
        }
        m_80 &= ~0x2000;
        if (TObjPlayer::try_camera_action((saddr)m_78->m_94, (s32)id) != 0) {
            TNpcPlayer__sub_8014DC3C(this, id);
            return;
        }
    }
    partner_request_physical_attack();
}

void TNpcPlayer::request_technique_cast(s32 kind) {
    Msg_80150A34 m;
    u8 *actor;

    ((TNpcPlayer *)(&m))->init_cast_technique_cmd();
    actor = (u8 *)m_78->m_94;
    if (kind == 15 || kind == 16) {
        request_chatter(0x16);
    } else if (kind == 0 || kind == 3 || kind == 6) {
        request_chatter(0x17);
    } else {
        request_chatter(2);
    }
    if (TObjPlayer::try_camera_action((saddr)actor, (s32)kind) != 0) {
        m.type = get_npc_type__10TNpcPlayerFPv(m_78);
        m.kind = kind;
        m.one = 1;
        if (kind == 15 || kind == 16) {
            if (kind == 15) {
                m_80 |= 0x10000;
            }
            m.e = get_cast_technique_level(actor + 0x428, kind);
            ((void (*)(void *, u16))set_type__10TNpcPlayerFPvs)(m.sub, ((s32 (*)(void *))get_npc_type__10TNpcPlayerFPv)(m_74));
            set_state__10TNpcPlayerFPvs(m.sub, 0);
        } else {
            m.e = get_cast_technique_level(actor + 0x428, kind);
            ((void (*)(void *, u16))set_type__10TNpcPlayerFPvs)(m.sub, ((TNpcPlayer *)m_78)->get_npc_state());
            set_state__10TNpcPlayerFPvs(m.sub, TNpcPlayer__sub_801528DC(m_78));
        }
        ((TNpcPlayer *)(&m))->finalize_and_send_packet();
    }
}

void TNpcPlayer::init_state() {
    ((TNpcPlayer *)m_74)->reset_fields_8c();
    ((TNpcPlayer *)m_78)->reset_fields_8c();
    switch (m_28) {
    case 0:
        init_follow_target();
        m_28 = 1;
    case 1:
        return;
    }
}

void TNpcPlayer::update_condition_flags() {
    ((s32 (*)(s32))partner_view_check_moved)((saddr)m_74);
    ((s32 (*)(s32))partner_view_update_conditions)((saddr)m_74);
    if (((TNpcPlayer *)m_74)->get_condition() & 2) {
        if (((s16 (*)(void *, int))get_partner_counter)(m_5c, 0xA) == 0) {
            request_chatter(9);
        }
        ((s32 (*)(void *, s32))increment_partner_counter)(m_5c, 0xA);
    } else {
        ((s32 (*)(void *, s32))reset_partner_counter)(m_5c, 0xA);
    }
    if (((s32 (*)(s32, f32))check_and_set_reached__10TNpcPlayerFPv)((saddr)m_74, 30.0f) != 0) {
        if (((TNpcPlayer *)m_74)->get_condition() & 8) {
            if (((s16 (*)(void *, int))get_partner_counter)(m_5c, 9) == 0) {
                request_chatter(0xC);
            }
            ((s32 (*)(void *, s32))increment_partner_counter)(m_5c, 8);
            ((s32 (*)(void *, int, int))npc_counter_reset_if_reached)(m_5c, 9, 0x2BC);
            return;
        }
        ((s32 (*)(void *, s32))reset_partner_counter)(m_5c, 9);
    }
}

#pragma push
#pragma fp_contract on
void partner_observe_surroundings(TNpcPlayer *npc_player) {
    f32 temp_f3;
    s32 temp_r3_2;
    TObjPlayer *obj_player;
    TObjPlayer *temp_r3;
    Unk_8014F844 *temp_r3_3;
    obj_player = npc_player->m_74->m_94;
    npc_player->m_58 = horizontal_distance_squared(&obj_player->position, &npc_player->m_78->m_94->position);
    if (npc_player->m_84 != 0) {
        ((s32 (*)(void *, s32, f32))try_update_target_flag__10TNpcPlayerFPvi)(npc_player->m_78, get_npc_type__10TNpcPlayerFPv(npc_player->m_74), npc_player->ai_params.enemy_lock_on_range);
    } else {
        ((s32 (*)(s32, f32))check_and_set_reached__10TNpcPlayerFPv)((saddr)npc_player->m_78, npc_player->ai_params.enemy_lock_on_range);
    }
    ((s32 (*)(s32))partner_view_update_conditions)((saddr)npc_player->m_78);
    temp_f3 = npc_player->m_dc.x;
    temp_r3 = npc_player->m_78->m_94;
    npc_player->m_78->m_98 = (s32)(10430.38043493439 * atan2_float(temp_f3 - temp_r3->position.x, npc_player->m_dc.z - temp_r3->position.z));
    ((s32 (*)(void *))partner_probe_obstacles)(npc_player->m_78);
    if (partner_view_update_hp_change(npc_player->m_78) != 0) {
        if (((TNpcPlayer *)npc_player->m_78)->get_condition() & 0x40) {
            npc_player->request_chatter(0xE);
        } else if (((TNpcPlayer *)npc_player->m_78)->get_condition() & 0x80) {
            npc_player->request_chatter(0xF);
        } else if (((TNpcPlayer *)npc_player->m_78)->get_condition() & 0x200) {
            if (npc_player->m_7c != 8U) {
                temp_r3_2 = npc_player->m_80;
                if (temp_r3_2 & 0x10000) {
                    npc_player->m_80 = temp_r3_2 & 0xFFFEFFFF;
                } else {
                    npc_player->request_chatter(0x11);
                }
            }
        } else {
            npc_player->request_chatter(0x10);
        }
    }
    if (((s32 (*)(s32))partner_view_check_moved)((saddr)npc_player->m_78) == 0) {
        if (npc_player->m_7c == 1U) {
            if (((TNpcPlayer *)npc_player->m_78)->get_action_state() & 0x80) {
                npc_player->m_8c = 0;
                npc_player->m_8d = 0;
                return;
            }
            npc_player->m_8d = (s8)(npc_player->m_8d + 1);
            if (npc_player->m_8d > 0x1E) {
                npc_player->m_8d = 0x1E;
            }
            npc_player->m_8c = (s8)(npc_player->m_8c + 1);
        }
    } else {
        temp_r3_3 = npc_player->m_78;
        VecCopy(&temp_r3_3->m_9c, &temp_r3_3->m_94->prev_position);
        npc_player->m_8c = 0;
        npc_player->m_8d = 0;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void select_path_waypoint__10TNpcPlayerFv(TNpcPlayer *self) {
    Vec midpoint;
    Vec hit;
    Vec route;
    Vec dir;
    Vec normal;
    TObjPlayer *actor;
    f32 len;
    f32 half;
    s32 clear;

    actor = self->m_78->m_94;
    dir.x = self->m_dc.x - actor->body_center.x;
    dir.y = self->m_dc.y - actor->body_center.y;
    dir.z = self->m_dc.z - actor->body_center.z;
    len = ((f32 (*)(void *))vector_length)(&dir);
    if (0.0f != len) {
        normalize_vector(&dir);
    }
    actor = self->m_78->m_94;
    half = len / 2.0f;
    midpoint.x = half * dir.x + actor->body_center.x;
    midpoint.y = half * dir.y + actor->body_center.y;
    midpoint.z = half * dir.z + actor->body_center.z;
    if (((s32 (*)(void *, Vec *, Vec *, Vec *, Vec *))partner_find_wall_segment)(self, &actor->body_center, &self->m_dc, &hit, &normal) != 0) {
        Vec shortcut = {0.0f, 0.0f, 0.0f};
        clear = ((s32 (*)(void *, Vec *, Vec *, Vec *, Vec *, Vec *))partner_route_around_wall)(self, &self->m_78->m_94->body_center, &hit, &normal, &route, &shortcut);
        if (!(self->m_80 & 1)) {
            if (clear != 0) {
                VecCopy(&self->m_a0, &shortcut);
            } else {
                VecCopy(&self->m_a0, &route);
                self->m_a0.y = self->m_dc.y;
                Vec clipped;
                if (((s32 (*)(void *, Vec *, Vec *, Vec *))partner_clip_path_point)(self, &self->m_dc, &self->m_a0, &clipped) != 0) {
                    VecCopy(&self->m_a0, &clipped);
                }
            }
            self->m_94.x = self->m_dc.x - self->m_a0.x;
            self->m_94.y = 0.0f;
            self->m_94.z = self->m_dc.z - self->m_a0.z;
            if (0.0f != ((f32 (*)(void *))vector_length)(&self->m_94)) {
                normalize_vector(&self->m_94);
            }
            self->m_80 |= 1;
        }
        if (clear != 0) {
            self->m_90 = 0;
            if (self->m_80 & 2) {
                Vec d1;
                actor = self->m_78->m_94;
                d1.x = self->m_d0.x - actor->position.x;
                d1.y = 0.0f;
                d1.z = self->m_d0.z - actor->position.z;
                if (((f32 (*)(void *))vector_length)(&d1) <= 1.5f) {
                    VecCopy(&self->m_d0, &shortcut);
                    self->m_80 &= ~2;
                }
            } else {
                VecCopy(&self->m_d0, &shortcut);
            }
        } else if (self->m_80 & 2) {
            Vec d2;
            actor = self->m_78->m_94;
            d2.x = self->m_d0.x - actor->position.x;
            d2.y = 0.0f;
            d2.z = self->m_d0.z - actor->position.z;
            if (((f32 (*)(void *))vector_length)(&d2) <= 5.0f) {
                Vec clipped2;
                if (((s32 (*)(void *, Vec *, Vec *, Vec *))partner_clip_path_point)(self, &self->m_78->m_94->body_center, &route, &clipped2) != 0) {
                    VecCopy(&self->m_d0, &clipped2);
                } else {
                    VecCopy(&self->m_d0, &route);
                }
                self->m_80 &= ~2;
                self->m_90 = 0;
            }
            self->m_90++;
            if (self->m_90 >= 100) {
                self->m_90 = 100;
            }
        } else {
            Vec d3;
            self->m_90 = 0;
            actor = self->m_78->m_94;
            d3.x = self->m_d0.x - actor->position.x;
            d3.y = 0.0f;
            d3.z = self->m_d0.z - actor->position.z;
            self->m_d0.x = self->m_a0.x;
            self->m_d0.y = self->m_a0.y;
            self->m_d0.z = self->m_a0.z;
            if (((f32 (*)(void *))vector_length)(&d3) < 1.0f) {
                self->m_90 = 0;
                self->m_d0.x = 40.0f * self->m_94.x + self->m_a0.x;
                self->m_d0.y = 40.0f * self->m_94.y + self->m_a0.y;
                self->m_d0.z = 40.0f * self->m_94.z + self->m_a0.z;
                self->m_80 |= 2;
                self->m_80 &= ~1;
            }
        }
        return;
    }
    if (((TNpcPlayer *)self->m_78)->get_action_state() & 0x20) {
        if (self->route_around_object((Vec *)(&route)) != 0 && self->m_8c < 30) {
            VecCopy(&self->m_d0, &route);
        } else {
            if (self->m_8d > 15) {
                self->m_8c = 0;
            }
            VecCopy(&self->m_d0, &midpoint);
        }
    } else if (((TNpcPlayer *)self->m_78)->get_action_state() & 0x80) {
        VecCopy(&self->m_d0, &midpoint);
    } else if (self->m_8c >= 15 && self->m_8c < 30) {
        Vec d4;
        Vec detour;
        Unk_8014F844 *view = self->m_78;
        actor = view->m_94;
        d4.x = actor->position.x - view->m_9c.x;
        d4.y = actor->position.y - view->m_9c.y;
        d4.z = actor->position.z - view->m_9c.z;
        ((void (*)(void *, Vec *, Vec *, Vec *, Vec *))partner_compute_stalled_detour)(self, &actor->position, &self->m_dc, &d4, &detour);
        VecCopy(&self->m_d0, &detour);
    } else {
        if (self->m_8d > 15) {
            self->m_8c = 0;
        }
        VecCopy(&self->m_d0, &midpoint);
    }
    self->m_80 &= ~1;
    self->m_90 = 0;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
s32 needs_movement__10TNpcPlayerFPvPvi(TNpcPlayer *self, void *_w1, int _w2) {
    f32 temp_f1;
    f32 var_f31;
    if (self->m_80 & 0x10) {
        return 1;
    }
    var_f31 = 12.0f + self->ai_params.max_distance_from_player;
    if (var_f31 >= 40.0f) {
        var_f31 = 40.0f;
    }
    temp_f1 = ((f32 (*)(void *, void *, int))horizontal_distance_squared)(&self->m_dc, &self->m_78->m_94->position, _w2);
    self->m_88 = temp_f1;
    if (temp_f1 >= (var_f31 * var_f31)) {
        return 1;
    }
    self->m_80 = self->m_80 & 0xFFFFFEFF;
    return 0;
}
#pragma pop

void TNpcPlayer::init_follow_target() {
    TObjPlayer *t = m_74->m_94;
    Vec off = {0.0f, 0.0f, 18.0f};
    if (t != NULL) {
        m_d0.x = m_74->m_94->position.x + off.x;
        m_d0.y = m_74->m_94->position.y + off.y;
        m_d0.z = m_74->m_94->position.z + off.z;
        VecCopy(&m_ac, &m_74->m_94->position);
    }
}

void TNpcPlayer::render() {  }

#pragma push
#pragma fp_contract on
s32 TNpcPlayer::check_movement_progress() {
    s8 temp_r3;
    if (((f32 (*)(void *, void *))horizontal_distance_squared)(&m_ac, &m_d0) <= 100.0f) {
        return 0;
    }
    temp_r3 = m_8c;
    if (temp_r3 > 0x1E) {
        m_8c = 0x1EU;
        m_80 = m_80 | 0x4000;
        if (((s16 (*)(void *, int))get_partner_counter)(m_5c, 7) == 0) {
            request_chatter(7);
        }
        ((s32 (*)(void *, int))increment_partner_counter)(m_5c, 7);
        ((s32 (*)(void *, int, int))npc_counter_reset_if_reached)(m_5c, 7, 0x12C);
        return 0;
    }
    if ((temp_r3 == 0) && (m_80 & 0x4000)) {
        ((s32 (*)(void *, int))reset_partner_counter)(m_5c, 7);
        request_chatter(0x18);
        m_80 = m_80 & 0xFFFFBFFF;
    }
    return 1;
}
#pragma pop

s32 partner_view_check_moved(u8 *arg0) {
    Unk_8014F844 *view = (Unk_8014F844 *)arg0;
    Vec d;
    f32 temp_f1;
    f32 *temp_r31;
    f32 *temp_r3;
    temp_r31 = (f32 *)view->m_94->get_prev_position_ptr();
    temp_r3 = (f32 *)view->m_94->get_position_ptr();
    if ((temp_r31 == NULL) || (temp_r3 == NULL)) {
        return 0;
    }
    d.x = temp_r3[0] - temp_r31[0];
    d.y = temp_r3[1] - temp_r31[1];
    temp_f1 = temp_r3[2];
    d.z = temp_f1 - temp_r31[2];
    if (((f32 (*)(void *, f32))vector_length)(&d, temp_f1) > 0.4f) {
        view->m_8c = view->m_8c | 1;
        return 1;
    }
    return 0;
}

s32 TNpcPlayer::try_attack(s32 arg1, s32 arg2) {
    switch (arg1) {
    case 0:
        if ((arg2 != 0) && (((Unk_8014F844 *)this)->m_94->find_inventory_item_id(3, 0) != -1)) {
            ((Unk_8014F844 *)this)->m_90 = ((Unk_8014F844 *)this)->m_90 | 0x20;
            return 1;
        }
        if (TObjPlayer::try_camera_action((saddr)((Unk_8014F844 *)this)->m_94, 0xF) != 0) {
            return 1;
        }
        break;
    case 1:
        if (((Unk_8014F844 *)this)->m_94->find_inventory_item_id(3, 1) != -1) {
            ((Unk_8014F844 *)this)->m_90 = ((Unk_8014F844 *)this)->m_90 | 0x20;
            return 1;
        }
        break;
    case 2:
        if (TObjPlayer::try_camera_action((saddr)((Unk_8014F844 *)this)->m_94, 0x10) != 0) {
            return 1;
        }
        break;
    case 3:
        if (((Unk_8014F844 *)this)->m_94->find_inventory_item_id(3, 6) != -1) {
            ((Unk_8014F844 *)this)->m_90 = ((Unk_8014F844 *)this)->m_90 | 0x20;
            return 1;
        }
        if (TObjPlayer::try_camera_action((saddr)((Unk_8014F844 *)this)->m_94, 0x11) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

s32 check_and_set_reached__10TNpcPlayerFPv(void *arg0) {
    Unk_8014F844 *view = (Unk_8014F844 *)arg0;
    if (((s32 (*)(void *, void *))scan_nearby_enemies__10TNpcPlayerFPvPvf)(view, &view->m_94->position) != 0) {
        view->m_8c = view->m_8c | 2;
        return 1;
    }
    return 0;
}

s32 try_update_target_flag__10TNpcPlayerFPvi(void *arg0, s32 arg1) {
    Unk_8014F844 *view = (Unk_8014F844 *)arg0;
    TObjPlayer *obj_player;

    obj_player = view->m_94;
    if (((s32 (*)(void *, void *, s32, TObjPlayer *))find_parts_in_range__10TNpcPlayerFPvPvif)(view, &obj_player->position, arg1, obj_player) != 0) {
        view->m_8c = view->m_8c | 2;
        return 1;
    }
    return 0;
}

s32 partner_view_update_conditions(u8 *arg0) {
    Unk_8014F844 *view = (Unk_8014F844 *)arg0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f31;
    f32 actor_tp;
    s32 temp_r3;
    s32 var_r31;
    var_r31 = 0;
    temp_f31 = (f32)((TObjChara *)view->m_94)->get_actor_hp();
    temp_f1 = temp_f31 / (f32)((TObjChara *)view->m_94)->get_hpmax();
    if (view->m_8c & 2) {
        if (temp_f1 <= 0.25f) {
            var_r31 = 1;
            view->m_90 = view->m_90 | 8;
            view->m_8c = view->m_8c | 4;
        }
        if (temp_f1 <= 0.75f) {
            var_r31 = 1;
            view->m_90 = view->m_90 | 0x1000;
        }
    } else if (temp_f1 <= 0.75f) {
        var_r31 = 1;
        view->m_90 = view->m_90 | 8;
        view->m_8c = view->m_8c | 4;
    }
    if (temp_f1 <= 0.1f) {
        var_r31 = 1;
        view->m_90 = view->m_90 | 0x800;
        view->m_8c = view->m_8c | 4;
    }
    temp_r3 = view->m_94->actorFlags;
    if ((temp_r3 & 1) || (temp_r3 & 2) || (temp_r3 & 0x10)) {
        var_r31 = 1;
        view->m_90 = view->m_90 | 2;
        view->m_8c = view->m_8c | 4;
    }
    actor_tp = (f32)get_actor_tp((u8 *)view->m_94);
    temp_f2 = (f32)obj_getS16_2BA((u8 *)view->m_94);
    if (((actor_tp / temp_f2) <= 0.2f) && (0.0f != temp_f2)) {
        view->m_8c = view->m_8c | 4;
        view->m_90 = view->m_90 | 0x10;
    }
    return var_r31;
}

s32 partner_view_update_hp_change(void *arg0) {
    s16 temp_r0;
    s16 temp_r31;
    s16 temp_r3;
    s16 temp_r4;
    temp_r31 = ((TObjChara *)((Unk_8014F844 *)arg0)->m_94)->get_actor_hp();
    temp_r3 = ((TObjChara *)((Unk_8014F844 *)arg0)->m_94)->get_hpmax();
    if (((Unk_8014F844 *)arg0)->m_88 <= 0) {
        ((Unk_8014F844 *)arg0)->m_88 = temp_r31;
        return 0;
    }
    temp_r4 = ((Unk_8014F844 *)arg0)->m_88;
    temp_r0 = (s16)(temp_r4 - temp_r31);
    if (temp_r4 >= (s32)(temp_r31 - 1)) {
        if ((f32)temp_r0 > (0.3f * (f32)temp_r3)) {
            ((Unk_8014F844 *)arg0)->m_90 = ((Unk_8014F844 *)arg0)->m_90 | 0x40;
        } else if ((f32)temp_r0 > (0.2f * (f32)temp_r3)) {
            ((Unk_8014F844 *)arg0)->m_90 = ((Unk_8014F844 *)arg0)->m_90 | 0x80;
        } else if ((f32)temp_r0 > (0.01f * (f32)temp_r3)) {
            ((Unk_8014F844 *)arg0)->m_90 = ((Unk_8014F844 *)arg0)->m_90 | 0x100;
        }
    } else {
        ((Unk_8014F844 *)arg0)->m_90 = ((Unk_8014F844 *)arg0)->m_90 | 0x200;
    }
    ((Unk_8014F844 *)arg0)->m_88 = temp_r31;
    return temp_r0 ? 1 : 0;
}

// Dead-stripped from the DOL: no code of it survives, only its literal (0.2 at
// 0x805DB218, pooled between init_ai_state's 19.0 and partner_view_update_hp_change's
// 0.3). It is the low-HP test hp_change and partner_view_update_conditions make
// against a fifth of the maximum. Name inferred from that role.
bool TNpcPlayer::is_hp_low(f32 hp, f32 max_hp) {
    return hp <= 0.2f * max_hp;
}

Unk_8014F844 *init_ai_state__10TNpcPlayerFPvi(Unk_8014F844 *self, s32 id) {
    s32 i;
    void *p;
    self->m_94 = ((TObjPlayer *(*)(u16))find_entity_by_id)(id);
    self->m_9c.x = 0.0f;
    self->m_9c.y = 0.0f;
    self->m_9c.z = 0.0f;
    self->m_8c = 0;
    self->m_90 = 0;
    self->m_8a = id;
    self->m_88 = -1;
    self->m_84 = 0;
    self->m_0 = 0;
    for (i = 0; i < 10; i++) {
        self->m_4[i].m_0 = 0xFFFF;
        self->m_4[i].m_8 = 0.0f;
    }
    self->m_104 = 0;
    self->m_ac.offset.x = 0.0f;
    self->m_ac.offset.y = 0.0f;
    self->m_ac.offset.z = 5.0f;
    self->m_ac.radius = 19.0f;
    self->m_ac.half_width = 5.0f;
    self->m_ac.shape = 0;
    self->m_ac.flags = 0x1103;
    p = TObject::operator new(0xAC);
    if (p != 0) {
        p = __ct__14TObjCollidableFP7TObject(p, tl_05);
    }
    self->m_a8 = (TObjCollidable *)p;
    if (self->m_a8 != 0) {
        init_collision_body_parts(self->m_a8, &self->m_ac, 1);
    }
    self->m_7c = 0xFFFF;
    self->m_80 = 0xFFFF;
    return self;
}

#pragma push
#pragma fp_contract on
s32 refresh_npc_view_actor_lost(void *arg0) {
    Unk_8014F844 *view = (Unk_8014F844 *)arg0;
    TObjPlayer *v;
    view->m_94 = (TObjPlayer *)get_player_by_client_id(view->m_8a);
    v = view->m_94;
    if (v == NULL) {
        return 1;
    }
    return (u32)__cntlzw(v->all_parents_unqueued_for_destruction()) >> 5;
}
#pragma pop

void *TNpcPlayer::dt(s16 arg1) {
    if (this != NULL) {
        if (((Unk_8014F844 *)this)->m_a8 != NULL) {
            free_collision_body_parts((uaddr)((Unk_8014F844 *)this)->m_a8);
            ((TObject *)((Unk_8014F844 *)this)->m_a8)->queue_destruction();
            ((Unk_8014F844 *)this)->m_a8 = NULL;
        }
        if (arg1 > 0) {
            ::operator delete(this);
        }
    }
    return this;
}

bool is_target_line_clear__10TNpcPlayerFPvUs(u8 *arg0, u32 arg1) {
    Vec target;
    TObjPlayer *obj_player;
    VecCopy(&target, &((TObjChara *)find_active_entity_by_id(arg1))->body_center);
    obj_player = ((Unk_8014F844 *)arg0)->m_94;
    target.y = obj_player->body_center.y;
    return csnVector(&obj_player->body_center, &target, 0x2100) == NULL;
}

s32 scan_nearby_enemies__10TNpcPlayerFPvPvf(Unk_8014F844 *view, void *pos, f32 range) {
    Vec origin;
    TObjCollidable *actor;
    s32 found;
    s32 i;
    s32 c;
    s32 j;
    f32 d;
    found = 0;
    ((TObjBase *)(view->m_94))->get_room();
    VecCopy(&origin, (const Vec *)pos);
    view->m_0 = 0;
    for (j = 0; j < 10; j++) {
        view->m_4[j].m_0 = 0xFFFF;
        view->m_4[j].m_8 = 0.0f;
    }
    i = TLobby::get_game_mode();
    range = range * range;
    for (; i < TLobby::get_game_mode() + TObjEneDD::get_enemy_count(); i++) {
        actor = (TObjCollidable *)TObjPlayer::get_player_data(i);
        if (((TTecReverser *)actor)->is_active() == 0 || !(actor->actorFlags & 0x20000000)) {
            continue;
        }
        for (c = 0; c < actor->body_count; c++) {
            if (actor->bodies == 0) {
                break;
            }
            if (!(actor->bodies[c].flags & 0x8000)) {
                continue;
            }
            d = horizontal_distance_squared(&origin, &actor->bodies[c].center);
            if (d < range) {
                found = 1;
                view->m_4[view->m_0].m_0 = (u16)get_entity_id(actor);
                view->m_4[view->m_0].m_8 = d;
                view->m_4[view->m_0].m_4 = c;
                if (view->m_0 >= 9) {
                    break;
                }
                view->m_0++;
            }
        }
    }
    TNpcPlayer::quick_sort((saddr)view, (saddr)&view->m_4[0], 0, view->m_0 - 1);
    return found;
}

s32 find_parts_in_range__10TNpcPlayerFPvPvif(Unk_8014F844 *view, void *pos, s32 id, f32 range) {
    TObjCollidable *actor;
    s32 found;
    s32 i;
    f32 d;
    s32 j;

    view->m_0 = 0;
    found = 0;
    for (j = 0; j < 10; j++) {
        view->m_4[j].m_0 = 0xFFFF;
        view->m_4[j].m_8 = 0.0f;
    }
    actor = find_entity_by_id(id);
    if (((TObjBase *)actor)->is_alive() != 0) {
        range = range * range;
        for (i = 0; i < actor->body_count; i++) {
            if (actor->bodies == 0) {
                break;
            }
            d = horizontal_distance_squared(pos, &actor->bodies[i].center);
            if (d < range) {
                found = 1;
                view->m_4[view->m_0].m_0 = (u16)get_entity_id(actor);
                view->m_4[view->m_0].m_8 = d;
                view->m_4[view->m_0].m_4 = i;
                if (view->m_0 >= 9) {
                    break;
                }
                view->m_0++;
            }
        }
    }
    TNpcPlayer::quick_sort((saddr)view, (saddr)&view->m_4[0], 0, view->m_0 - 1);
    return found;
}

void TNpcPlayer::quick_sort(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;

    if (arg2 < arg3) {
        temp_r3 = ((s32 (*)(void))partition_sort_entries__10TNpcPlayerFiPvii)();
        TNpcPlayer::quick_sort(arg0, arg1, arg2, temp_r3 - 1);
        TNpcPlayer::quick_sort(arg0, arg1, temp_r3 + 1, arg3);
    }
}

s32 partition_sort_entries__10TNpcPlayerFiPvii(s32 self, Unk_8014F844Entry *a, s32 lo, s32 hi) {
    Unk_8014F844Entry tmp;
    f32 pivot;
    s32 i;
    s32 j;

    j = hi;
    i = lo - 1;
    pivot = a[hi].m_8;
    for (;;) {
        while (a[++i].m_8 < pivot) {
        }
        while (i < --j && pivot < a[j].m_8) {
        }
        if (i >= j || i >= 10 || j >= 10) {
            break;
        }
        ((s32 (*)(s32, Unk_8014F844Entry *, Unk_8014F844Entry *))copy_transform_second__10TNpcPlayerFPvPvPv)(self, &a[i], &tmp);
        ((s32 (*)(s32, Unk_8014F844Entry *, Unk_8014F844Entry *))copy_transform_second__10TNpcPlayerFPvPvPv)(self, &a[j], &a[i]);
        ((s32 (*)(s32, Unk_8014F844Entry *, Unk_8014F844Entry *))copy_transform_second__10TNpcPlayerFPvPvPv)(self, &tmp, &a[j]);
    }
    ((s32 (*)(s32, Unk_8014F844Entry *, Unk_8014F844Entry *))copy_transform_second__10TNpcPlayerFPvPvPv)(self, &a[i], &tmp);
    ((s32 (*)(s32, Unk_8014F844Entry *, Unk_8014F844Entry *))copy_transform_second__10TNpcPlayerFPvPvPv)(self, &a[hi], &a[i]);
    ((s32 (*)(s32, Unk_8014F844Entry *, Unk_8014F844Entry *))copy_transform_second__10TNpcPlayerFPvPvPv)(self, &tmp, &a[hi]);
    return i;
}

s32 partner_probe_obstacles(Unk_8014F844 *view) {
    s32 i;
    TObjCollidable *actor;
    CollisionBody *contact;
    TObjCollidable *probe;
    probe = view->m_a8;
    if (probe == NULL) {
        return 0;
    }
    VecCopy(&probe->position, &view->m_94->position);
    view->m_a8->rotation_y = view->m_98;
    for (i = TLobby::get_game_mode(); i < TLobby::get_game_mode() + TObjEneDD::get_enemy_count() + ((s32 (*)(void))get_registered_object_count)(); i++) {
        actor = (TObjCollidable *)TObjPlayer::get_player_data(i);
        if ((actor != NULL) && !(actor->actorFlags & 0x80000000)) {
            contact = (CollisionBody *)view->m_a8->find_actor_body_contact((u8 *)actor, 10000.0f);
            if (contact != NULL) {
                if (actor->actorFlags & 0x40000000) {
                    if (!(contact->flags & 8) && !(contact->flags & 0x100) && !(contact->flags & 0x200)) {
                        copy_collision_body(&view->m_d8, contact);
                        view->m_104 = actor->rotation_y;
                        view->m_8c |= 0x20;
                        return 1;
                    }
                } else if (actor->actorFlags & 0x20000000) {
                    if (!(contact->flags & 8) && !(contact->flags & 0x100) && !(contact->flags & 0x200)) {
                        view->m_8c |= 0x80;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

s32 partner_find_wall_segment(saddr arg0, saddr from, saddr to, saddr arg3, saddr arg4) {
    CsnHit *hit;
    hit = csnVector((const Vec *)from, (const Vec *)to, 0x2100);
    if (hit != NULL) {
        VecCopy((Vec *)arg3, &hit->contact->point);
        VecCopy((Vec *)arg4, &hit->contact->normal);
        return 1;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
s32 partner_route_around_wall(TNpcPlayer *self, Vec *from, Vec *to, Vec *d, Vec *out, Vec *out2) {
    Line_8014EE98 line;
    Vec dir;
    Vec perp;
    Vec hit;
    Vec tmp;
    Vec v;
    f32 len;
    f32 s;
    dir.x = to->x - from->x;
    dir.y = 0.0f;
    dir.z = to->z - from->z;
    len = vector_length(&dir);
    if (0.0f != len) {
        normalize_vector(&dir);
    }
    perp.x = d->z;
    perp.y = 0.0f;
    perp.z = -d->x;
    if (vec3_dot(&dir, &perp) < 0.0f) {
        perp.x = -perp.x;
        perp.z = -perp.z;
    }
    line.p.x = self->m_78->m_94->body_center.x;
    line.p.y = self->m_78->m_94->body_center.y;
    line.p.z = self->m_78->m_94->body_center.z;
    line.d.x = perp.x;
    line.d.y = 0.0f;
    line.d.z = perp.z;
    project_point_onto_line(&self->m_dc, &line, &hit);
    s = 1.5f * len;
    if (s <= 20.0f) {
        s = 20.0f;
    }
    out->x = perp.x * s + from->x;
    out->y = from->y;
    out->z = perp.z * s + from->z;
    VecCopy(&tmp, &self->m_74->m_94->body_center);
    if (csnVector(&tmp, &hit, 0x2100) != NULL) {
        hit.x = 5.0f * perp.x + hit.x;
        hit.z = 5.0f * perp.z + hit.z;
        return 0;
    }
    v.x = self->m_74->m_94->body_center.x - hit.x;
    v.z = self->m_74->m_94->body_center.z - hit.z;
    v.y = 0.0f;
    if (0.0f != vector_length(&v)) {
        normalize_vector(&v);
    }
    out2->x = 5.0f * perp.x + hit.x;
    out2->z = 5.0f * perp.z + hit.z;
    out2->y = 0.0f;
    return 1;
}
#pragma pop

#pragma push
#pragma fp_contract on
void partner_compute_stalled_detour(TNpcPlayer *self, Vec *from, Vec *to, Vec *d, Vec *out) {
    Vec dir;
    Vec save;
    Vec a;
    Vec b;
    Vec diff;
    dir.x = -d->x;
    dir.y = 0.0f;
    dir.z = -d->z;
    if (0.0f != vector_length(&dir)) {
        normalize_vector(&dir);
    }
    VecCopy(&save, &dir);
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, 0x4000);
    matrix_mult_vec(0, &dir, &a);
    pop_matrices(1);
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, -0x4000);
    matrix_mult_vec(0, &dir, &b);
    pop_matrices(1);
    diff.x = to->x - from->x;
    diff.y = 0.0f;
    diff.z = to->z - from->z;
    if (0.0f != vector_length(&diff)) {
        normalize_vector(&diff);
    }
    if (vec3_dot(&diff, &a) > 0.0f) {
        VecCopy(&dir, &b);
    } else {
        VecCopy(&dir, &a);
    }
    if (self->m_8c >= 0x14) {
        out->x = -((20.0f * dir.x) - from->x);
        out->y = from->y;
        out->z = -((20.0f * dir.z) - from->z);
    } else {
        out->x = 20.0f * dir.x + from->x;
        out->y = from->y;
        out->z = 20.0f * dir.z + from->z;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 TNpcPlayer::route_around_object(Vec *out) {
    TNpcPlayer * self = this;
    CollisionBody info;
    Vec perp;
    Vec to;
    Vec toSelf;
    f32 r;
    copy_collision_body(&info, &self->m_78->m_d8);
    if (info.shape == 0 || info.shape == 0 ||
        (info.half_width <= 12.0f && info.shape == 1 && info.half_width == info.radius)) {
        TObjPlayer *t = self->m_78->m_94;
        r = 20.0f + info.radius;
        to.x = t->position.x - info.center.x;
        to.y = 0.0f;
        to.z = t->position.z - info.center.z;
        perp.x = to.z;
        perp.y = 0.0f;
        perp.z = -to.x;
        if (0.0f != vector_length(&perp)) {
            normalize_vector(&perp);
        }
        toSelf.x = self->m_dc.x - info.center.x;
        toSelf.y = 0.0f;
        toSelf.z = self->m_dc.z - info.center.z;
        if (0.0f != vector_length(&toSelf)) {
            normalize_vector(&toSelf);
        }
        if (vec3_dot(&perp, &toSelf) < 0.0f) {
            perp.x = -perp.x;
            perp.z = -perp.z;
        }
        if (0.0f != vector_length(&to)) {
            normalize_vector(&to);
        }
        perp.x += to.x;
        perp.y += to.y;
        perp.z += to.z;
        if (0.0f != vector_length(&perp)) {
            normalize_vector(&perp);
        }
        out->x = r * perp.x + info.center.x;
        out->y = r * perp.y + info.center.y;
        out->z = r * perp.z + info.center.z;
        if (self->m_8c > 10) {
            out->x = info.center.x - r * perp.x;
            out->y = info.center.y - r * perp.y;
            out->z = info.center.z - r * perp.z;
        }
    } else {
        Vec a = {1.0f, 0.0f, 0.0f};
        Vec b = {0.0f, 0.0f, 1.0f};
        Vec c0;
        Vec c2;
        Vec c1;
        Vec c3;
        Vec esc;
        Vec dir;
        Vec axis;
        Vec clip;
        Vec alt;
        f32 dist;
        a.x *= info.radius;
        b.z *= info.half_width;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, self->m_78->m_104 + 0x4000);
        matrix_mult_vec(0, &a, &a);
        matrix_mult_vec(0, &b, &b);
        pop_matrices(1);
        c0.x = info.center.x + a.x;
        c0.y = info.center.y + a.y;
        c0.z = info.center.z + a.z;
        c1.x = info.center.x - a.x;
        c1.y = info.center.y - a.y;
        c1.z = info.center.z - a.z;
        c2.x = info.center.x + b.x;
        c2.y = info.center.y + b.y;
        c2.z = info.center.z + b.z;
        c3.x = info.center.x - b.x;
        c3.y = info.center.y - b.y;
        c3.z = info.center.z - b.z;
        dir.x = self->m_74->m_94->position.x - info.center.x;
        dir.y = self->m_74->m_94->position.y - info.center.y;
        dir.z = self->m_74->m_94->position.z - info.center.z;
        if (0.0f != vector_length(&dir)) {
            normalize_vector(&dir);
        }
        self->calc_box_escape_axis(&c0, &c1, &c2, &c3, &self->m_78->m_94->position, &axis, &dist);
        VecCopy(&esc, &axis);
        if (vec3_dot(&dir, &esc) < 0.0f) {
            esc.x = -esc.x;
            esc.z = -esc.z;
        }
        r = dist;
        out->x = r * esc.x + self->m_78->m_94->position.x;
        out->y = r * esc.y + self->m_78->m_94->body_center.y;
        out->z = r * esc.z + self->m_78->m_94->position.z;
        if (partner_clip_path_point(self, &self->m_78->m_94->body_center.x, &out->x, &clip.x) != 0) {
            out->x = clip.x;
            out->y = clip.y;
            out->z = clip.z;
        }
        if (self->m_8c > 15) {
            alt.x = esc.z;
            alt.y = 0.0f;
            alt.z = esc.x;
            if (vec3_dot(&dir, &alt) < 0.0f) {
                alt.x = -alt.x;
                alt.z = -alt.z;
            }
            out->x = r * alt.x + self->m_78->m_94->position.x;
            out->y = self->m_78->m_94->body_center.y;
            out->z = r * alt.z + self->m_78->m_94->position.z;
        }
    }
    return 1;
}
#pragma pop

void TNpcPlayer::calc_box_escape_axis(Vec *a, Vec *b, Vec *c, Vec *d, Vec *pos, Vec *axis, f32 *reach) {
    Vec point1;
    Vec point2;
    Vec first;
    Vec second;
    Vec center1;
    Vec center2;
    Line_8014EE98 line1;
    Line_8014EE98 line2;
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
    dist1 = ((f32 (*)(Vec *, Line_8014EE98 *, Vec *))project_point_onto_line)(pos, &line1, &point1);
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
    dist2 = ((f32 (*)(Vec *, Line_8014EE98 *, Vec *))project_point_onto_line)(pos, &line2, &point2);
    center2.x = 0.5f * (a->x + b->x);
    center2.y = 0.5f * (a->y + b->y);
    center2.z = 0.5f * (a->z + b->z);
    reach2 = (10.0f + 0.5f * len2) - xyz_distance(&center2, &point2);
    if (reach2 < 0.0f) {
        reach2 = 0.5f * len2;
    }
    if (dist2 < dist1) {
        *reach = 10.0f + reach1;
        VecCopy(axis, &first);
    } else if (dist2 == dist1) {
        *reach = 7.0f;
        axis->x = 0.5f * (first.x + second.x);
        axis->y = 0.5f * (first.y + second.y);
        axis->z = 0.5f * (first.z + second.z);
    } else {
        *reach = 10.0f + reach2;
        VecCopy(axis, &second);
    }
}

// Dead-stripped from the DOL: no code of it survives, only its literals (0.5 and
// 12.0 at 0x805DB1F8/0x805DB1FC, pooled between partner_clip_path_point's 10.0 and
// calc_box_escape_axis's 7.0). It is the half-size limit under which
// route_around_object walks around an obstacle instead of escaping its box.
// Name inferred from that role.
bool TNpcPlayer::is_small_obstacle(f32 size) {
    return 0.5f * size <= 12.0f;
}

#pragma push
#pragma fp_contract on
s32 partner_clip_path_point(void *self, f32 *from, f32 *to, f32 *out) {
    Vec dir;
    CsnHit *hit;
    hit = csnVector((const Vec *)from, (const Vec *)to, 0x2100);
    if (hit != NULL) {
        dir.x = to[0] - from[0];
        dir.y = 0.0f;
        dir.z = to[2] - from[2];
        if (0.0f != vector_length(&dir)) {
            normalize_vector(&dir);
        }
        VecCopy((Vec *)out, &hit->contact->point);
        out[0] = -((10.0f * dir.x) - out[0]);
        out[1] = -((10.0f * dir.y) - out[1]);
        out[2] = -((10.0f * dir.z) - out[2]);
        return 1;
    }
    return 0;
}
#pragma pop

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
    reset_partner_counter((saddr)(arg0 + 0x5C), 0);
    if (arg1 != ((u32) (*((u32 *) (((s8 *) arg0) + new_var2)))))
    {
      *new_var = arg1;
      *((s32 *) (((s8 *) arg0) + 0x80)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x80))) | 4);
    }
  }
}

void deliver_partner_chatter(TNpcPlayer *self) {
    u16 id;
    char *text;
    if (self->m_24 >= 0x19) {
        self->m_80 &= ~4;
        self->m_24 = 0x19;
        return;
    }
    if (TObjPlayer::is_any_teammate_in_state() != 0) {
        return;
    }
    id = get_entity_id(self->m_78->m_94);
    if (id != 0xFFFF) {
        text = (char *)get_partner_custom_text(self->m_24, id);
        if (text != 0) {
            TWindowCtrl::open((s32)id, (saddr)text, 0x1B);
        } else {
            text = npc_partner_dialogue_state[self->m_24].text;
            if (text[0] != 0) {
                TWindowCtrl::open((s32)id, (saddr)text, 0x1B);
            }
        }
    }
    self->m_80 &= ~4;
    if (((s32 (*)(void *, s32, s32))npc_counter_reset_if_reached)(self->m_5c, 0, 0x190) != 0) {
        self->m_24 = 0x19;
    }
}

void TNpcPlayer::handle_action(s32 arg1) {
    s32 player;
    s32 temp_r3_2;
    s32 temp_r3_3;
    Unk_8014F844 *temp_r5;
    Unk_8014F844 *temp_r5_2;
    Unk_8014F844 *temp_r5_3;

    switch (arg1) {
    case 0:
        player = m_78->m_94->find_inventory_item_id(3, 0);
        if (player != -1) {
            temp_r5 = m_78;
            try_send_6x27_use_item((saddr)temp_r5->m_94, player, temp_r5);
            m_80 = m_80 | 0x10000;
        }
        break;
    case 1:
        temp_r3_2 = m_78->m_94->find_inventory_item_id(3, 1);
        if (temp_r3_2 != -1) {
            temp_r5_2 = m_78;
            try_send_6x27_use_item((saddr)temp_r5_2->m_94, temp_r3_2, temp_r5_2);
            return;
        }
        break;
    case 2:
        temp_r3_3 = m_78->m_94->find_inventory_item_id(3, 6);
        if (temp_r3_3 != -1) {
            temp_r5_3 = m_78;
            try_send_6x27_use_item((saddr)temp_r5_3->m_94, temp_r3_3, temp_r5_3);
        }
        break;
    }
}

void TNpcPlayer::change_ai_state(u32 arg1) {
    m_7c = arg1;
    m_80 = m_80 & 0xFFFFEFFF;
    switch (arg1) {
    case 0:
        m_80 = m_80 & 0xFFFFFFCF;
        VecCopy(&m_dc, &m_78->m_94->body_center);
        return;
    case 1:
        m_80 = m_80 & 0xFFFFFFEF;
        m_80 = m_80 | 0x20;
        return;
    case 2:
        m_80 = m_80 & 0xFFFFFFDF;
        m_80 = m_80 | 0x10;
        return;
    case 8:
        VecCopy(&m_dc, &m_78->m_94->body_center);
        return;
    case 16:
        m_80 = m_80 & 0xFFFFFFEF;
        m_80 = m_80 | 0x20;
    default:
        return;
    }
}

void TNpcPlayer::dispatch_action(s32 arg1) {
    switch (arg1) {
    case 0:
        if (((TNpcPlayer *)m_78)->get_condition() & 0x20) {
            handle_action(arg1);
        } else {
            request_technique_cast(0xF);
        }
        if (m_80 & 0x200) {
            request_chatter(0x13);
        }
        return;
    case 1:
        if (((TNpcPlayer *)m_78)->get_condition() & 0x20) {
            handle_action(arg1);
            return;
        }
        break;
    case 2:
        if (((TNpcPlayer *)m_78)->get_condition() & 0x20) {
            handle_action(arg1);
            return;
        }
        request_technique_cast(0x10);
        return;
    case 3:
        if (((TNpcPlayer *)m_78)->get_condition() & 0x20) {
            handle_action(arg1);
            return;
        }
        request_technique_cast(0x11);
        break;
    }
}
