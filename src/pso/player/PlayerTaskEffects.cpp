#include "pso/system/NinjaTypes.h"
#include "pso/render/ChunkMaterialState.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/network/TPlyOnCountOver.h"
#include "pso/system/data/FlagWord.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/TPlyOnCreated.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/player/TPlayerSoul.h"
#include "pso/player/TPlayerReadyCallback.h"
#include "pso/player/TPlayerLevelFeedback.h"
#include "pso/player/TPlayerLobbyMarker.h"
#include "types.h"
#include "pso/map/FloorArea.h"

extern "C" {

void *__ct__20TPlayerLevelFeedbackFP7TObjectUs(void *arg0, u16 arg1, u16 arg2);
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
u32 get_player_by_client_id(u16);
s32 __ct__7TObjectFP7TObject();
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

}
extern "C" {

extern s32 __vt__20TPlayerLevelFeedback[];

}
extern "C" {

extern s32 __vt__20TPlayerLevelFeedback[];

}
struct Vec_801C6408 { f32 x, y, z; };

struct VB_801C6408 { u8 pad[0x18]; };

struct VO_801C6408 : VB_801C6408 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62();
    virtual void get_pos(s32, Vec_801C6408 *);
};

extern "C" {
void *create_particle_emitter(void *pos, s32 id);
s32 test_action_mask__10TObjPlayerFl(VO_801C6408*, s32);
s32 is_on_current_floor__10TObjPlayerFi(VO_801C6408*);
extern s32 tl_07;
void* __nw__7TObjectFUl(s32);

}

extern "C" {

s32 __ct__11TPlayerSoulFP7TObjectUs();

s32 is_script_controlled__10TObjPlayerFv(s32);

s32 check_flag_0x8000__10TObjPlayerFv();
s32 get_entity_id(s32);
s32 obj_isState3_324__9TObjCharaFv(s32);

extern s32 tl_06;

}

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/player/TPlayerParticleOwner.h"
#include "pso/effect/particle/TParticleCtrl.h"
extern "C" int check_value_equals__13TUnk_804B6C24Fl(TParticleCtrl*, const char*);
extern "C" const char* TParticleCtrl__class_name_descriptor;

namespace accessors {
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/player/TPlayerParticleOwner.h"

#include "types.h"

#include "pso/player/TObjPlayer.h"

extern "C" {
void TObjPlayer__sub_801C6FCC(void*, f32);
void TObjPlayer__sub_801C6FDC(void);
void TObjPlayer__sub_801C6FE0(void*, f32, f32, f32);
f32 apply_stat_multipliers__10TObjPlayerFiif(s32, s32, f32);
void apply_stat_multipliers_default__10TObjPlayerFv(void);
u16 get_obj_type__10TObjPlayerFPv(void*);
TObjPlayer* get_player_by_client_id(int);
f32 get_scalar__16PlayerScaleStateFv(s32);
void set_ring_action__10TObjPlayerFPvi(void*, s32);
void set_stat_scale__10TObjPlayerFPvf(void*, f32);
s32 test_flags_any(s32, s32);
}

extern "C" {

void apply_stat_multipliers_and_reset__10TObjPlayerFPv(void* p);
s32 get_slot_value__10TObjPlayerFPvi(s32 *arg0, s32 arg1);

}


extern "C" {

f32 apply_stat_multipliers__10TObjPlayerFiif(s32 arg0, s32 arg1, f32 farg0);
void apply_stats_and_update__10TObjPlayerFPv(void* p);
s32 test_flags_any(s32, s32);
f32 get_scalar__16PlayerScaleStateFv(s32);
s32 is_flag30_8_set__10TObjPlayerFi(s32);


}


extern "C" {
TObjPlayer* get_player_by_client_id(int);
int obj_isState2_324__9TObjCharaFv(TObjPlayer*);
extern s32 local_client_id;
void request_player_shrink(PlayerScaleState* state);
TObjPlayer* get_player_by_client_id(int);
int obj_isState2_324__9TObjCharaFv(TObjPlayer*);
void request_player_size_restore(PlayerScaleState* state);
TObjPlayer* get_player_by_client_id(int);
int check_camera_mode__10TObjPlayerFv();
void *TObjPlayer__sub_801C7360(void *arg0, void *arg1);
int validate_6x87_shrink_player(PlayerShrinkPacket*);
void handle_6x87_shrink__10TObjPlayerFPvf(u8 *arg0, f32 farg0);
void handle_6x87_shrink_player(const PlayerShrinkPacket* input);
TObjPlayer* get_player_by_client_id(int);
int check_camera_mode__10TObjPlayerFv();
void restore_shrunken_font__10TObjPlayerFv(PlayerRestoreSizePacket*, const PlayerRestoreSizePacket*);
int bswap_g_client_id_header(void *p);
int validate_6x88_restore_shrunken_player(PlayerRestoreSizePacket*);
int clear_shrink_flag__10TObjPlayerFPv(void* p);
void handle_6x88_restore_shrunken_player(const PlayerRestoreSizePacket* input);
void request_follow_camera_offsets(f32*, f32*, u16);
void update_player_scale_camera(PlayerScaleState *state);
}

extern "C" {

void apply_stat_multipliers_default__10TObjPlayerFv(void);
int clear_shrink_flag__10TObjPlayerFPv(void* p);
void handle_6x87_shrink__10TObjPlayerFPvf(u8 *arg0, f32 farg0);
void reset_stat_scale_and_ring__10TObjPlayerFi(s32 arg0);
int clear__8FlagWordFUl(void*, int);



}


struct RecoveredGlobal_801C6FF8_lbl_804C4008 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
BOOL fn_801C6F2C(u8 *arg0);
int has_water_ground_flag(void *p);
int set_action_flag16__10TObjPlayerFPv(void* p);
int test_flag_8__10TObjPlayerFPv(void* p);
int TObjPlayer__sub_801C7098(void* p);
s32 get_contact_surface_type(s32 arg0);
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_801C6FF8_lbl_804C4008 __vt__18TPlayerLobbyMarker;
u8 *__ct__18TPlayerLobbyMarkerFP7TObjectsSc(u8 *arg0, u8 *arg1, s16 arg2, s8 arg3);
s32 TObjPlayer__sub_801BF914(s32);
s32 all_parents_unqueued_for_destruction__7TObjectFv();
s32 scale_matrix(s32, f32, f32, f32);
s32 translate_matrix_vec3(s32, s32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 pop_matrix();
s32 draw_chunk_object();
extern u8 shared_effect_texture_list[];
extern u8 saved_model_draw_color[];
extern u8 model_material_color[];
extern void *camera_ctrl_instance;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
u8 *__ct__18TPlayerLobbyMarkerFP7TObjectsSc(u8 *arg0, u8 *arg1, s16 arg2, s8 arg3);
void *__nw__7TObjectFUl(u32);
u8 *create_lobby_marker__10TObjPlayerFsc(s16 arg0, s8 arg1);
s32 TMainCursor__sub_8013E03C(void);
s32 TObjPlayer__sub_801C6DAC(u8 *arg0);
}

extern "C" {

int TObjPlayer__sub_801C6F90(void* p);
void TObjPlayer__sub_801C6FCC(void* p, f32 v);
void TObjPlayer__sub_801C6FDC(void);
void TObjPlayer__sub_801C6FE0(void* p, f32 a, f32 b, f32 c);
void *__dt__13TForceOperateFv(void *arg0, s16 arg1);
void clear_target_lock_flag__10TObjPlayerFPv(void* p);
void free__10TObjPlayerFPv(void* a0);
u16 get_obj_type__10TObjPlayerFPv(void* p);
void heap_alloc__10TObjPlayerFPv(void* a0);
int set_action_flag16__10TObjPlayerFPv(void* p);
int set_lock_flag__10TObjPlayerFPv(void* p);
void set_lock_timer__10TObjPlayerFPvi(void* p, s32 v);
void set_ring_action__10TObjPlayerFPvi(void* p, s32 v);
void set_stat_scale__10TObjPlayerFPvf(void* p, f32 v);
int test_flag_8__10TObjPlayerFPv(void* p);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
int clear__8FlagWordFUl(void*, int);

}
}
namespace accessors {
}

namespace accessors {
}
namespace accessors {
extern "C" {

    extern int obj_heap;

    extern int obj_heap;

extern s32 __vt__13TForceOperate[];

}
}
namespace accessors {
extern "C" {

typedef char RecoveredGlobal_801C6FF8_lbl_804C4008_size[sizeof(RecoveredGlobal_801C6FF8_lbl_804C4008) == 0x18 ? 1 : -1];

}

}

#include "pso/network/TPlyOnCountOver.h"

#include "pso/network/TPlyOnCreated.h"

#include "types.h"
#include "pso/system/THeap.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/player/TForceOperate.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/map/FloorArea.h"

extern "C" {

void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

}
extern "C" {

extern s32 __vt__18TPlayerLobbyMarker[];

}

#undef get_player_by_client_id

#undef test_flags_any

#undef apply_stat_multipliers__10TObjPlayerFiif

#undef apply_stat_multipliers_default__10TObjPlayerFv

#undef set_stat_scale__10TObjPlayerFPvf

#undef TObjPlayer__sub_801C6FCC

namespace accessors {
extern "C" {
s32 get_slot_value__10TObjPlayerFPvi(s32 *arg0, s32 arg1);
}
}

namespace accessors {
extern "C" {
void apply_stat_multipliers_and_reset__10TObjPlayerFPv(void* p);
}
}

namespace accessors {
extern "C" {
void apply_stats_and_update__10TObjPlayerFPv(void* p);
}
}

namespace accessors {
extern "C" {
f32 apply_stat_multipliers__10TObjPlayerFiif(s32 arg0, s32 arg1, f32 farg0);
}
}

namespace accessors {
extern "C" {
void apply_stat_multipliers_default__10TObjPlayerFv(void);
}
}

namespace accessors {
extern "C" {
void reset_stat_scale_and_ring__10TObjPlayerFi(s32 arg0);
}
}

namespace accessors {
extern "C" {
void update_player_scale_camera(PlayerScaleState *state);
}
}

namespace accessors {
extern "C" {
void handle_6x88_restore_shrunken_player(const PlayerRestoreSizePacket* input);
}
}

namespace accessors {
extern "C" {
int clear_shrink_flag__10TObjPlayerFPv(void* p);
}
}

namespace accessors {
extern "C" {
void request_player_size_restore(PlayerScaleState* state);
}
}

namespace accessors {
extern "C" {
void handle_6x87_shrink_player(const PlayerShrinkPacket* input);
}
}

namespace accessors {
extern "C" {
void handle_6x87_shrink__10TObjPlayerFPvf(u8 *arg0, f32 farg0);
}
}

namespace accessors {
extern "C" {
void request_player_shrink(PlayerScaleState* state);
}
}

namespace accessors {
extern "C" {
u8 *create_lobby_marker__10TObjPlayerFsc(s16 arg0, s8 arg1);
}
}

namespace accessors {
extern "C" {
s32 TObjPlayer__sub_801C6DAC(u8 *arg0);
}
}

namespace accessors {
extern "C" {
void free__10TObjPlayerFPv(void* a0);
}
}

namespace accessors {
extern "C" {
void heap_alloc__10TObjPlayerFPv(void* a0);
}
}

namespace accessors {
extern "C" {
s32 get_contact_surface_type(s32 arg0);
}
}

namespace accessors {
extern "C" {
void *__dt__13TForceOperateFv(void *arg0, s16 arg1);
}
}

namespace accessors {
extern "C" {
BOOL fn_801C6F2C(u8 *arg0);
}
}

namespace accessors {
extern "C" {
void set_lock_timer__10TObjPlayerFPvi(void* p, s32 v);
}
}

namespace accessors {
extern "C" {
void clear_target_lock_flag__10TObjPlayerFPv(void* p);
}
}

namespace accessors {
extern "C" {
int set_lock_flag__10TObjPlayerFPv(void* p);
}
}

namespace accessors {
extern "C" {
int TObjPlayer__sub_801C6F90(void* p);
}
}

namespace accessors {
extern "C" {
void set_stat_scale__10TObjPlayerFPvf(void* p, f32 v);
}
}

namespace accessors {
extern "C" {
void TObjPlayer__sub_801C6FCC(void* p, f32 v);
}
}

namespace accessors {
extern "C" {
void set_ring_action__10TObjPlayerFPvi(void* p, s32 v);
}
}

namespace accessors {
extern "C" {
void TObjPlayer__sub_801C6FDC(void);
}
}

namespace accessors {
extern "C" {
void TObjPlayer__sub_801C6FE0(void* p, f32 a, f32 b, f32 c);
}
}

namespace accessors {
extern "C" {
u16 get_obj_type__10TObjPlayerFPv(void* p);
}
}

namespace accessors {
extern "C" {
u8 *__ct__18TPlayerLobbyMarkerFP7TObjectsSc(u8 *arg0, u8 *arg1, s16 arg2, s8 arg3);
}
}

namespace accessors {
extern "C" {
int set_action_flag16__10TObjPlayerFPv(void* p);
}
}

namespace accessors {
extern "C" {
int test_flag_8__10TObjPlayerFPv(void* p);
}
}

namespace accessors {
extern "C" {
int TObjPlayer__sub_801C7098(void* p);
}
}


#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/system/vector.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/player/TObjPlayer_801C721C.h"

extern s32 chunk_polygon_flags_and_mask;
extern s32 chunk_polygon_flags_or_mask;

struct Base_801C57D0 { char pad[0x18]; };
struct VObj_801C57D0 : Base_801C57D0 {
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
    virtual void m11(s32);
};

struct Actor_801C58CC : VO_801C6408 {
    u8 pad1C[0x20];
    f32 f3c;
};

typedef struct Out_801C58CC {
    u8 pad0[4];
    f32 v;
} Out_801C58CC;

struct Obj_801C5C38 { u8 pad[4]; s32 n; };

struct Arrival_801C5F84 {
    s32 active;
    s32 yaw;
    Vec_801C6408 pos;
};

struct Pair_801C5FCC { f32 a; f32 b; };

struct Obj_801C5FCC { s32 n; Pair_801C5FCC e[16]; };

extern "C" {
void calc_death_pose_height_offset(Out_801C58CC *arg0, Actor_801C58CC *arg1);
s32 obj_testFlags30__14TObjCollidableFUl(int, int);
s32 is_inactive__10TObjPlayerFv();
s32 check_flag_40000__10TObjPlayerFv(int);
s32 set_flag_2000000_alt__10TObjPlayerFv();
void *TForceOperate__ct(void *arg0, void *arg1, void *arg2);
void *find_entity_by_id();
void fn_8013E020(void *);
void *get_state__11TMainCursorFv(s32);
s32 is_target_valid__10TObjPlayerFv();
void queue_destruction__7TObjectFv(void *arg0);
void set_field_0__13TForceOperateFs(void *, void *);
s32 tick_battle_music_timer(Obj_801C5C38 *p);
s32 get_current_floor();
s32 is_room_free_of_active_enemies(s32, s32);
s32 get_room__8TObjBaseFv(s32);
void set_params__10TObjPlayerFPvPvPviPv(void *arg0, void *arg1, void *arg2, s32 arg3, void *arg4);
s16 obj_getS16_2BA(u8 *p);
extern Arrival_801C5F84 TObjPlayer__arrival_override_table[12];
void set_arrival_override_coords(u16 arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2);
void set_arrival_override_pos(u16 idx, s32 yaw, void *pos);
void clear_movement_history(Obj_801C5FCC *p);
s16 TObjPlayer__sub_800194E8(s32, s16);
s16 get_attack_params_atp_max(void *p);
u8 *__ct__15TPlyOnCountOverFv(u8 *object, s32 arg1, s32 arg2, s32 arg3);
u8 *__ct__13TPlyOnCreatedFv(u8 *object, s32 arg1, s32 arg2);
extern s32 __vt__15TPlyOnCountOver[];
extern s32 __vt__13TPlyOnCreated[];
int TFontSmallLobby__sub_801C0228(void *);
}
void calc_death_sink_offset(void *arg0);
void update_player_appear_fade(u8 *arg0);
void reset_player_appearance_opacity(void *a0);
void save_render_material_state(u8 *arg0);

// The marker colours, indexed by TPlayerLobbyMarker::get_material_index().
extern const NJS_ARGB player_lobby_marker_color_table[13] = {
    { 1.0f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 0.0f, 0.0f },
    { 1.0f, 0.0f, 0.0f, 1.0f },
    { 1.0f, 0.0f, 1.0f, 0.0f },
    { 1.0f, 1.0f, 1.0f, 0.0f },
    { 1.0f, 1.0f, 0.0f, 1.0f },
    { 1.0f, 0.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 0.5f, 0.0f },
    { 1.0f, 1.0f, 0.5f, 0.8f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
    { 1.0f, 0.0f, 0.0f, 0.0f },
};

extern const char TPlyOnCreated__class_name_string[] = "TPlyOnCreated";
extern const char TPlyOnCountOver__class_name_string[] = "TPlyOnCountOver";
extern const char TForceOperate__class_name_string[] = "TForceOperate";

const char *TPlyOnCreated__name = TPlyOnCreated__class_name_string;
const char *TPlyOnCountOver__name = TPlyOnCountOver__class_name_string;
const char *TForceOperate__name = TForceOperate__class_name_string;

#pragma defer_codegen on
namespace accessors {
extern "C" {
u8 *__ct__18TPlayerLobbyMarkerFP7TObjectsSc(u8 *player_lobby_marker, u8 *arg1, s16 arg2, s8 arg3) {
    __ct__7TObjectFP7TObject(player_lobby_marker, arg1);
    *(s32 **)((s8 *)player_lobby_marker + 0x18) = &__vt__18TPlayerLobbyMarker.value;
    *(s8 *)&((TPlayerLobbyMarker *)player_lobby_marker)->material_index = arg3;
    *(s8 *)&((TPlayerLobbyMarker *)player_lobby_marker)->flags = 0;
    *(s16 *)&((TPlayerLobbyMarker *)player_lobby_marker)->player_id = arg2;
    ((TPlayerLobbyMarker *)player_lobby_marker)->rotation = 0;
    return player_lobby_marker;
}

}
}

namespace accessors {
extern "C" {
u16 get_obj_type__10TObjPlayerFPv(void* p) { return *(u16*)((char*)p + 0x0); }

}
}

namespace accessors {
extern "C" {
void TObjPlayer__sub_801C6FE0(void* p, f32 a, f32 b, f32 c) { *(f32*)((char*)p + 0x0) = a; *(f32*)((char*)p + 0x4) = b; *(f32*)((char*)p + 0x8) = c; }

}
}

namespace accessors {
extern "C" {
void TObjPlayer__sub_801C6FDC(void) {  }

}
}

namespace accessors {
extern "C" {
void set_ring_action__10TObjPlayerFPvi(void* p, s32 v) { *(s32*)((char*)p + 0x4) = v; }

}
}

namespace accessors {
extern "C" {
void TObjPlayer__sub_801C6FCC(void* p, f32 v) { *(f32*)((char*)p + 0x8) = v; }

}
}

namespace accessors {
extern "C" {
void set_stat_scale__10TObjPlayerFPvf(void* p, f32 v) { *(f32*)((char*)p + 0x0) = v; }

}
}

void TPlayerSoul::set_player_id(u16 value) { player_id = value; }

void TPlayerSoul::set_particle(TParticleCtrl*value) { particle = value; }

namespace accessors {
extern "C" {
int TObjPlayer__sub_801C6F90(void* p) { return ((int (*)(void*, int))test_flags_any)(p, 2); }

}
}

namespace accessors {
extern "C" {
int set_lock_flag__10TObjPlayerFPv(void* p) { return ((int (*)(void*, int))test_flags_any)(p, 1); }

}
}

namespace accessors {
extern "C" {
void clear_target_lock_flag__10TObjPlayerFPv(void* p) { ((FlagWord *)p)->clear(1); }

}
}

namespace accessors {
extern "C" {
void set_lock_timer__10TObjPlayerFPvi(void* p, s32 v) { *(s32*)((char*)p + 0x4) = v; }

}
}

namespace accessors {
extern "C" {
BOOL fn_801C6F2C(u8 *arg0) {
    return *(s32 *)((s8 *)arg0 + 4) == 1;
}

}
}

namespace accessors {
extern "C" {
void *__dt__13TForceOperateFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TForceOperate;
        TForceOperate::destroy((s32)((s8 *)arg0 + 0x1C), (s16)(-1));
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
}

namespace accessors {
extern "C" {
s32 get_contact_surface_type(s32 arg0) {
    if (((s32)TObjPlayer__sub_801C7098((void*)arg0)) != 0) {
        return 1;
    }
    if (has_water_ground_flag((void *)arg0) != 0) {
        return 2;
    }
    if (((s32)test_flag_8__10TObjPlayerFPv((void*)arg0)) != 0) {
        return 3;
    }
    return (((s32)set_action_flag16__10TObjPlayerFPv((void*)arg0)) != 0) ? 4 : 0;
}

}
}

namespace accessors {
extern "C" {
void heap_alloc__10TObjPlayerFPv(void* a0) { ((THeap *)obj_heap)->heap_alloc((size_t)a0); }

}
}

namespace accessors {
extern "C" {
void free__10TObjPlayerFPv(void* a0) { ((THeap *)obj_heap)->heap_free(a0); }

}
}

namespace accessors {
extern "C" {
s32 TObjPlayer__sub_801C6DAC(u8 *arg0) {
    *(u8 **)((s8 *)arg0 + 4) = (u8 *)((s32 (*)(u16))get_player_by_client_id)(TMainCursor__sub_8013E03C());
    if (*(u8 **)((s8 *)arg0 + 4) != NULL) {
        return 1;
    }
    return 0;
}

}
}

namespace accessors {
extern "C" {
u8 *create_lobby_marker__10TObjPlayerFsc(s16 arg0, s8 arg1) {
    u8 *e;
    u8 *p;
    e = ((u8 *)((s32 (*)(u16))get_player_by_client_id)(arg0));
    if (e == NULL) {
        return NULL;
    }
    p = (u8 *)__nw__7TObjectFUl(0x24);
    if (p != NULL) {
        p = __ct__18TPlayerLobbyMarkerFP7TObjectsSc(p, e, arg0, arg1);
    }
    return p;
}

}
}

void TPlayerLobbyMarker::run_task() { rotation += 0x800; }

void TPlayerLobbyMarker::render() {
    using namespace accessors;
    s32 temp_r3;
    temp_r3 = ((s32 (*)(u16))accessors::get_player_by_client_id)(player_id);
    if ((temp_r3 != 0) && (all_parents_unqueued_for_destruction__7TObjectFv() != 0) && (get_material_index() != 0) && (((TObjPlayer *)temp_r3)->is_body_collision_inactive() == 0)) {
        push_matrix();
        TParticleCtrl::begin_effect_render();
        saved_model_render_flags = model_render_flags;
        copy_argb((NJS_ARGB *)saved_model_draw_color, (NJS_ARGB *)model_material_color);
        TObjFish::set_global_param((s32)shared_effect_texture_list);
        model_render_flags |= 0x11;
        translate_matrix_vec3(0, TObjPlayer__sub_801BF914(temp_r3 + 0x84C));
        rotate_matrix_y(0, *(s32 *)((s8 *)camera_ctrl_instance + 0x194) + rotation);
        scale_matrix(0, 1.3f, 1.3f, 1.3f);
        set_constant_material(&player_lobby_marker_color_table[get_material_index()]);
        TMainCursor::get_cursor_state();
        draw_chunk_object();
        copy_argb((NJS_ARGB *)model_material_color, (NJS_ARGB *)saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

u8 TPlayerLobbyMarker::get_material_index() {
    if (material_index >= 0xD) material_index = 0;
    return material_index;
}

namespace accessors {
extern "C" {
void request_player_shrink(PlayerScaleState* state) {
    TObjPlayer* player = get_player_by_client_id(get_obj_type__10TObjPlayerFPv(state));
    if (!player || !obj_isState2_324__9TObjCharaFv(player)) {
        if (local_client_id == get_obj_type__10TObjPlayerFPv(state))
            update_player_scale_camera((PlayerScaleState *)(state));
        PlayerShrinkPacket packet;
        ((TObjPlayer *)(&packet))->init_shrink_effect();
        packet.actor_id = get_obj_type__10TObjPlayerFPv(state);
        packet.scalar = state->scalar;
        ((TObjPlayer *)(&packet))->update_and_send_60();
    }
}

}
}

namespace accessors {
extern "C" {
void handle_6x87_shrink__10TObjPlayerFPvf(u8 *arg0, f32 farg0) {
    ((FlagWord *)(arg0 + 4))->set(1);
    *(f32 *)((s8 *)arg0 + 8) = farg0;
}

}
}

namespace accessors {
extern "C" {
void handle_6x87_shrink_player(const PlayerShrinkPacket* input) {
    PlayerShrinkPacket packet;
    ((TObjPlayer *)(&packet))->init_shrink_effect();
    TObjPlayer__sub_801C7360((void *)&packet, (void *)input);
    ((TObjPlayer *)(&packet))->bswap_shrink();
    if (validate_6x87_shrink_player(&packet)) {
        TObjPlayer* player = get_player_by_client_id(packet.actor_id);
        if (player && check_camera_mode__10TObjPlayerFv())
            handle_6x87_shrink__10TObjPlayerFPvf((u8 *)&player->scale_state, packet.scalar);
    }
}

}
}

namespace accessors {
extern "C" {
void request_player_size_restore(PlayerScaleState* state) {
    TObjPlayer* player = get_player_by_client_id(get_obj_type__10TObjPlayerFPv(state));
    if (!player || !obj_isState2_324__9TObjCharaFv(player)) {
        PlayerRestoreSizePacket packet;
        ((TObjPlayer *)(&packet))->init_6x88_packet();
        packet.actor_id = get_obj_type__10TObjPlayerFPv(state);
        ((TObjPlayer *)(&packet))->send_font_update_60();
    }
}

}
}

namespace accessors {
extern "C" {
int clear_shrink_flag__10TObjPlayerFPv(void* p) { return clear__8FlagWordFUl((char*)p + 0x4, 1); }

}
}

namespace accessors {
extern "C" {
void handle_6x88_restore_shrunken_player(const PlayerRestoreSizePacket* input) {
    PlayerRestoreSizePacket packet;
    ((TObjPlayer *)(&packet))->init_6x88_packet();
    restore_shrunken_font__10TObjPlayerFv(&packet, input);
    bswap_g_client_id_header(&packet);
    if (validate_6x88_restore_shrunken_player(&packet)) {
        TObjPlayer* player = get_player_by_client_id(packet.actor_id);
        if (player && check_camera_mode__10TObjPlayerFv())
            clear_shrink_flag__10TObjPlayerFPv(&player->scale_state);
    }
}

}
}

namespace accessors {
extern "C" {
void update_player_scale_camera(PlayerScaleState *state) {
  TObjPlayer__sub_801C6FE0(state->camera_position, 0.0f, 0.6f * (25.43f * state->get_scalar()), 45.42f * state->get_scalar());
  TObjPlayer__sub_801C6FE0(state->camera_target, 0.0f, 19.8f * state->get_scalar(), -5.0f);
  request_follow_camera_offsets(((f32* (*)(f32*))TObjPlayer__sub_801C6FDC)(state->camera_target), ((f32* (*)(f32*))TObjPlayer__sub_801C6FDC)(state->camera_position), 0xFFFF);
}

}
}

namespace accessors {
extern "C" {
void reset_stat_scale_and_ring__10TObjPlayerFi(s32 arg0) {
    ((s32 (*)(f32))set_stat_scale__10TObjPlayerFPvf)(1.0f);
    set_ring_action__10TObjPlayerFPvi((void *)arg0, 0);
}

}
}

namespace accessors {
extern "C" {
void apply_stat_multipliers_default__10TObjPlayerFv(void) {
    ((s32 (*)(f32))apply_stat_multipliers__10TObjPlayerFiif)(1.0f);
}

}
}

namespace accessors {
extern "C" {
f32 apply_stat_multipliers__10TObjPlayerFiif(s32 arg0, s32 arg1, f32 farg0) {
    f32 var_f31;

    var_f31 = farg0;
    if (is_flag30_8_set__10TObjPlayerFi(arg1) != 0) {
        var_f31 *= 0.5f;
    } else if (test_flags_any(arg0 + 0xC, 8) != 0) {
        var_f31 *= 0.75f;
    }
    ((s32 (*)(s32, f32))TObjPlayer__sub_801C6FCC)(arg0, var_f31);
    if (((PlayerScaleState *)(arg1  + 0x5B0))->is_scaled() != 0) {
        var_f31 *= get_scalar__16PlayerScaleStateFv(arg1 + 0x5B0);
    }
    return var_f31;
}

}
}

namespace accessors {
extern "C" {
void apply_stats_and_update__10TObjPlayerFPv(void* p) { ((int (*)(void*))apply_stat_multipliers_default__10TObjPlayerFv)(p); ((int (*)(void*))set_stat_scale__10TObjPlayerFPvf)(p); }

}
}

namespace accessors {
extern "C" {
void apply_stat_multipliers_and_reset__10TObjPlayerFPv(void* p) { ((int (*)(void*))apply_stat_multipliers__10TObjPlayerFiif)(p); ((int (*)(void*))set_stat_scale__10TObjPlayerFPvf)(p); }

}
}

namespace accessors {
extern "C" {
s32 get_slot_value__10TObjPlayerFPvi(s32 *arg0, s32 arg1) {
    if (arg1 < 0 || arg1 >= 13) {
        return 0;
    }
    return arg0[arg1];
}

}
}

TPlayerParticleOwner::TPlayerParticleOwner(TObject* parent) : TObject(parent) {
    player_id = 0xFFFF;
    particle = 0;
}

TPlayerParticleOwner::~TPlayerParticleOwner() {
    TParticleCtrl* value = get_particle();
    if (value != 0) {
        value->queue_destruction();
    }
}

TParticleCtrl* TPlayerParticleOwner::get_particle() {
    if (particle != 0 && check_value_equals__13TUnk_804B6C24Fl(particle, TParticleCtrl__class_name_descriptor) == 0) {
        particle = 0;
    }
    return particle;
}

TObjPlayer*TPlayerSoul::get_player() {
    return (TObjPlayer*)get_player_by_client_id(player_id);
}

extern "C" {
void TObjPlayer::revive_or_spawn_marker() {
    s32 temp_r3;
    s32 player = (s32)this;

    if ((check_flag_0x8000__10TObjPlayerFv() != 0) || (obj_isState3_324__9TObjCharaFv(player) != 0) || (is_script_controlled__10TObjPlayerFv(player) != 0)) {
        ((TObjPlayer *)player)->set_flag_0x8000();
        return;
    }
    temp_r3 = ((s32 (*)(s32)) __nw__7TObjectFUl)(0x24);
    if (temp_r3 != 0) {
        ((s32 (*)(s32, s32, s32)) __ct__11TPlayerSoulFP7TObjectUs)(temp_r3, tl_06, get_entity_id(player));
    }
}

}

TPlayerSoul::TPlayerSoul(TObject* parent, u16 id) : TPlayerParticleOwner(parent) {
    set_player_id(id);
    TObjPlayer* player = get_player();
    if (player != 0) {
        TParticleCtrl* value = (TParticleCtrl *)create_particle_emitter((char*)player + 0x2FC, 0xAF);
        if (value != 0) {
            set_particle(value);
        } else {
            queue_destruction();
            return;
        }
    }
}

TPlayerSoul::~TPlayerSoul() {}

void TPlayerSoul::run_task() {
    VO_801C6408* p;
    TParticleCtrl* h;
    Vec_801C6408 v;
    p = (VO_801C6408*)get_player();
    if (p != NULL && test_action_mask__10TObjPlayerFl(p, 0x8000) != 0 && is_current_area_item_enabled() != 0 &&
        is_on_current_floor__10TObjPlayerFi(p) != 0) {
        h = get_particle();
        if (h != 0) {
            p->get_pos(1, &v);
            v.y += 10.0f;
            ((TParticleCtrl *)h)->set_position(&v);
        }
    } else {
        queue_destruction();
    }
}

extern "C" {
void TObjPlayer::new_child_object(s32 arg0) {
    void* obj = __nw__7TObjectFUl(0x24);
    if (obj != 0) {
        ((void *(*)(void *, s32, s32)) __ct__20TPlayerLevelFeedbackFP7TObjectUs)(obj, tl_07, arg0);
    }
}

}

TPlayerLevelFeedback::TPlayerLevelFeedback(TObject* parent, u16 id) : TObject(parent) {
    u32 player;
    player_id = id;
    timer = 10;
    player = get_player_by_client_id(player_id);
    if (player != 0) {
        player = (u32)spawn_particle_effect_with_flags((void *)(player + 0x2FC), 0x23, 0x10);
        if (player != 0) ((TParticleCtrl *)player)->set_owner_id(player_id);
    }
}

TPlayerLevelFeedback::~TPlayerLevelFeedback() {}

void TPlayerLevelFeedback::run_task() {
    s32 remaining;
    u32 player;
    u32 emitter;
    remaining = timer - 1;
    timer = remaining;
    if (remaining < 0) {
        player = get_player_by_client_id(player_id);
        if (player != 0) {
            emitter = (u32)spawn_particle_effect_with_flags((void *)(player + 0x2FC), 0x20, 0x10);
            if (emitter != 0) ((TParticleCtrl *)emitter)->set_owner_id(player_id);
        }
        queue_destruction();
    }
}


void TPlayerReadyCallback::run_task() {
    TObjPlayer* player = (TObjPlayer*)get_player_by_client_id(player_id);
    if (player != NULL && player->m_cfc == 0) {
        void (*fn)(TObjPlayer*) = callback;
        if (fn != NULL) {
            fn(player);
        }
        queue_destruction();
    }
}

void *TPlyOnCreated::create(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x24);
    if (o != NULL) {
        o = __ct__13TPlyOnCreatedFv((u8 *)o, (s32)arg0, (s32)arg1);
    }
    return o;
}

u8 *__ct__13TPlyOnCreatedFv(u8 *object, s32 arg1, s32 arg2) {
    ((void (*)(void *, void *))__ct__7TObjectFP7TObject)(object, (void *)tl_06);
    *(s32 **)((s8 *)object + 0x18) = __vt__13TPlyOnCreated;
    *(s32 *)((s8 *)object + 0) = (s32) TPlyOnCreated__name;
    *(s16 *)((s8 *)object + 0x1C) = arg1;
    *(s32 *)((s8 *)object + 0x20) = arg2;
    return object;
}

void TPlyOnCreated::run_task() {
    s32 (*temp_r12)();
    if (get_player_by_client_id(*(u16 *)((s8 *)this + 0x1C)) != 0U) {
        temp_r12 = *(s32 (**)())((s8 *)this + 0x20);
        if (temp_r12 != NULL) {
            temp_r12();
        }
        queue_destruction();
    }
}

void *TPlyOnCountOver::create(void *arg0, void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0x24);
    if (o != NULL) {
        o = __ct__15TPlyOnCountOverFv((u8 *)o, (s32)arg0, (s32)arg1, (s32)arg2);
    }
    return o;
}

u8 *__ct__15TPlyOnCountOverFv(u8 *object, s32 arg1, s32 arg2, s32 arg3) {
    ((void (*)(void *, void *))__ct__7TObjectFP7TObject)(object, (void *)tl_06);
    *(s32 **)((s8 *)object + 0x18) = __vt__15TPlyOnCountOver;
    *(s32 *)((s8 *)object + 0) = (s32) TPlyOnCountOver__name;
    *(s16 *)((s8 *)object + 0x1C) = arg1;
    *(s16 *)((s8 *)object + 0x1E) = arg2;
    *(s32 *)((s8 *)object + 0x20) = arg3;
    return object;
}

void TPlyOnCountOver::run_task() {
    u8 *arg0 = (u8 *)this;
    void (*cb)(u32);
    u32 p;
    p = get_player_by_client_id(*(u16 *)((s8 *)arg0 + 0x1C));
    if (p == 0U) {
        queue_destruction();
        return;
    }
    if (--*(s16 *)((s8 *)arg0 + 0x1E) < 0) {
        cb = *(void (**)(u32))((s8 *)arg0 + 0x20);
        if (cb != NULL) {
            cb(p);
        }
        queue_destruction();
    }
}

void clear_movement_history(Obj_801C5FCC *p) {
    s32 i;
    Pair_801C5FCC *e;
    p->n = 0;
    e = p->e;
    for (i = 0; i < 16; i++) {
        e->b = 0.0f;
        e->a = 0.0f;
        e++;
    }
}

void set_arrival_override_pos(u16 idx, s32 yaw, void *pos) {
    TObjPlayer__arrival_override_table[idx].active = 1;
    TObjPlayer__arrival_override_table[idx].yaw = yaw;
    VecCopy((Vec *)&TObjPlayer__arrival_override_table[idx].pos, (const Vec *)pos);
}

#pragma push
#pragma opt_common_subs off
void set_arrival_override_coords(u16 arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2) {
    s32 temp_r5;
    u8 *temp_r3;
    temp_r5 = arg0 * 0x14;
    *(s32 *)((s8 *)((u8 *)TObjPlayer__arrival_override_table + temp_r5) + 0) = 1;
    temp_r3 = (u8 *)TObjPlayer__arrival_override_table + temp_r5;
    *(s32 *)((s8 *)temp_r3 + 4) = arg1;
    *(f32 *)((s8 *)temp_r3 + 8) = farg0;
    *(f32 *)((s8 *)temp_r3 + 0xC) = farg1;
    *(f32 *)((s8 *)temp_r3 + 0x10) = farg2;
}
#pragma pop

void set_params__10TObjPlayerFPvPvPviPv(void *arg0, void *arg1, void *arg2, s32 arg3, void *arg4) {
    s16 temp_r4;

    *(s16 *)((s8 *)arg0 + 0) = (s16) (*(s16 *)((s8 *)arg2 + 0) + get_attack_params_atp_max((void *)arg3));
    temp_r4 = *(s16 *)((s8 *)arg2 + 8);
    *(s16 *)((s8 *)arg0 + 2) = (s16) (temp_r4 + *(s32 *)((s8 *)arg4 + 0x1C));
    *(s16 *)((s8 *)arg0 + 4) = (s16) *(s16 *)((s8 *)arg2 + 2);
    *(s16 *)((s8 *)arg0 + 6) = (s16) (0.1f * (f32) (*(s16 *)((s8 *)arg2 + 0xA) + TObjPlayer__sub_800194E8(arg3, temp_r4)));
    *(s16 *)((s8 *)arg0 + 8) = (s16) (*(s16 *)((s8 *)arg2 + 4) + *(s16 *)((s8 *)arg4 + 0));
    *(s16 *)((s8 *)arg0 + 0xA) = (s16) *(s16 *)((s8 *)arg2 + 0xC);
    *(s16 *)((s8 *)arg0 + 0xC) = (s16) *(s16 *)((s8 *)arg4 + 2);
    *(s16 *)((s8 *)arg0 + 0xE) = (s16) *(s16 *)((s8 *)arg4 + 4);
    *(s16 *)((s8 *)arg0 + 0x10) = (s16) *(s16 *)((s8 *)arg4 + 6);
    *(s16 *)((s8 *)arg0 + 0x12) = (s16) *(s16 *)((s8 *)arg4 + 8);
    *(s16 *)((s8 *)arg0 + 0x14) = (s16) *(s16 *)((s8 *)arg4 + 0xA);
}

void TObjPlayer::init_shield_params(s32 arg1) {
    ((void (*)()) set_params__10TObjPlayerFPvPvPviPv)();
    *(s16 *)((s8 *)this + 0x16) = ((TItemProShield *)arg1)->get_field_2b8();
    *(s16 *)((s8 *)this + 0x18) = obj_getS16_2BA((u8 *)arg1);
}

void TObjPlayer::calc_pos_delta(void *arg1, void *arg2) {
    *(s16 *)((s8 *)arg2 + 0) = (s16) (*(s16 *)((s8 *)arg1 + 0) - *(s16 *)((s8 *)this + 0));
    *(s16 *)((s8 *)arg2 + 2) = (s16) (*(s16 *)((s8 *)arg1 + 2) - *(s16 *)((s8 *)this + 2));
    *(s16 *)((s8 *)arg2 + 4) = (s16) (*(s16 *)((s8 *)arg1 + 4) - *(s16 *)&this->m_flags);
    *(s16 *)((s8 *)arg2 + 6) = (s16) (*(s16 *)((s8 *)arg1 + 6) - *(s16 *)&this->m_id);
    *(s16 *)((s8 *)arg2 + 8) = (s16) (*(s16 *)((s8 *)arg1 + 8) - *(s16 *)((s8 *)this + 8));
    *(s16 *)((s8 *)arg2 + 0xA) = (s16) (*(s16 *)((s8 *)arg1 + 0xA) - *(s16 *)((s8 *)this + 0xA));
    *(s16 *)((s8 *)arg2 + 0x16) = (s16) (*(s16 *)((s8 *)arg1 + 0x16) - *(s16 *)((s8 *)this + 0x16));
    *(s16 *)((s8 *)arg2 + 0x18) = (s16) (*(s16 *)((s8 *)arg1 + 0x18) - *(s16 *)((s8 *)this + 0x18));
}

#pragma fp_contract on
void TObjPlayer::copy_offset_position(void *chara) {
    f32 temp_f2;

    temp_f2 = *(f32 *)((s8 *)(((TObjPlayer *)chara)->get_stats()) + 0x10);
    *(f32 *)((s8 *)this + 0) = (f32) ((TObjPlayer *)chara)->position.x;
    *(f32 *)((s8 *)this + 4) = (f32) ((1.2f * temp_f2) + ((TObjPlayer *)chara)->position.y);
    *(f32 *)((s8 *)this + 8) = (f32) ((TObjPlayer *)chara)->position.z;
}

s32 TObjPlayer::decrement_clamp(s32 *arg0, s32 arg1) {
    *arg0 -= arg1;
    if ((s32) *arg0 < 0) {
        *arg0 = 0;
        return 0;
    }
    return 1;
}

void update_target_lock__10TObjPlayerFii(s32 arg0, s32 player) {

    if (accessors::TObjPlayer__sub_801C6F90((void *)arg0) == 0) {
        if (is_room_free_of_active_enemies(get_current_floor(), get_room__8TObjBaseFv(player)) != 0) {
            if (accessors::set_lock_flag__10TObjPlayerFPv((void *)arg0) != 0) {
                accessors::clear_target_lock_flag__10TObjPlayerFPv((void *)arg0);
                accessors::set_lock_timer__10TObjPlayerFPvi((void *)arg0, 0x5A);
                return;
            }
            if (tick_battle_music_timer((Obj_801C5C38 *)(arg0)) == 0) {
                ((TObjPlayer *)arg0)->reset_ring();
            }
        } else if (accessors::set_lock_flag__10TObjPlayerFPv((void *)arg0) == 0) {
            ((TObjPlayer *)arg0)->clear_target_lock();
        }
    }
}

s32 tick_battle_music_timer(Obj_801C5C38 *p) {
    if (p->n < 0) {
        return 1;
    }
    return --p->n < 0 ? 0 : 1;
}

void TObjPlayer::clear_target_lock() { ((FlagWord *)this)->set((u32)((void*)1)); TLobby::set_target_id((s32)((void*)1)); }

void TObjPlayer::reset_ring() { accessors::clear__8FlagWordFUl(this, 1); accessors::set_lock_timer__10TObjPlayerFPvi(this, -1); TLobby::set_target_id((s32)((void*)0)); }

void TObjPlayer::set_vec4_const() { *(float*)((char*)this + 0x1c) = 1.0f; *(float *)&this->m_20 = 1.0f; *(float *)&this->texlist = 1.0f; *(float *)&this->room = 1.0f; }

void save_render_material_state(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0) = (s32) accessors::model_render_flags;
    *(s32 *)((s8 *)arg0 + 4) = (s32) chunk_polygon_flags_and_mask;
    *(s32 *)((s8 *)arg0 + 8) = (s32) chunk_polygon_flags_or_mask;
    copy_argb((NJS_ARGB *)(arg0 + 0xC), (NJS_ARGB *)accessors::model_material_color);
}

void TObjPlayer::write_ids() { set_model_render_flags((s32)this->m_name); set_chunk_material_override_pair((s32)(*(void**)((char*)this + 0x4)), (s32)this->m_prev); set_constant_material((const NJS_ARGB *)(((char*)this + 0xc))); }

void reset_player_appearance_opacity(void* a0) { *(float*)((char*)a0 + 0x1c) = 1.0f; }

void TObjPlayer::enter_battle_state() {
    s32 temp_r3;

    temp_r3 = ((s32 (*)(u16))get_player_by_client_id)(*(u16 *)((s8 *)this + 0));
    if ((temp_r3 != 0) && (accessors::fn_801C6F2C((u8 *)this) == 0)) {
        *(s32 *)((s8 *)this + 4) = 0;
        ((TObjPlayer *)temp_r3)->deactivate_body_collision();
        *(s16 *)((s8 *)this + 2) = 4;
    }
}

#pragma push
#pragma opt_common_subs off
void update_player_appear_fade(u8 *arg0) {
    f32 var_f31;
    u8 *temp_r3;
    temp_r3 = (u8 *)(get_player_by_client_id(*(u16 *)((s8 *)arg0 + 0)));
    if (temp_r3 != NULL) {
        switch (*(s32 *)((s8 *)arg0 + 4)) {
        case 2:
        default:
            break;
        case 0:
            if ((is_inactive__10TObjPlayerFv() != 0) && (check_flag_40000__10TObjPlayerFv((int)temp_r3) == 0) && (((TObjPlayer *)temp_r3)->check_flag_04000000() != 0) && (is_on_current_floor__10TObjPlayerFi((VO_801C6408 *)temp_r3) != 0)) {
                if (--*(s16 *)((s8 *)arg0 + 2) < 0) {
                    if (TCameraCtrl::get_mode() != 0) {
                        ((TObjPlayer *)temp_r3)->render_material_state.alpha = 1.0f;
                        *(s32 *)((s8 *)arg0 + 4) = 2;
                        return;
                    }
                    *(s32 *)((s8 *)arg0 + 4) = 1;
                    ((TObjPlayer *)temp_r3)->activate_body_collision();
                    if (obj_testFlags30__14TObjCollidableFUl((int)temp_r3, 0x800) == 0) {
                        TObjPlayer::spawn_appearance_effect((int) (*(u16 *)((s8 *)arg0 + 0)));
                    }
                    ((TObjPlayer *)temp_r3)->render_material_state.alpha = 0.0f;
                    ((TObjPlayer *)temp_r3)->refresh_equipment_slot();
                    return;
                }
            }
            break;
        case 1:
            var_f31 = ((TObjPlayer *)temp_r3)->render_material_state.alpha;
            var_f31 += 0.1f;
            if (var_f31 >= 1.0f) {
                var_f31 = 1.0f;
                *(s32 *)((s8 *)arg0 + 4) = 2;
                set_flag_2000000_alt__10TObjPlayerFv();
                ((TObjPlayer *)temp_r3)->activate_body_collision();
            }
            ((TObjPlayer *)temp_r3)->render_material_state.alpha = var_f31;
            break;
        }
    }
}
#pragma pop

void calc_death_sink_offset(void *arg0) {
    *(f32 *)((s8 *)arg0 + 0) = (f32) (*(f32 *)((s8 *)arg0 + 4) * *(f32 *)((s8 *)arg0 + 8));
}

#pragma push
#pragma opt_common_subs off
void calc_death_pose_height_offset(Out_801C58CC *arg0, Actor_801C58CC *arg1) {
    f32 sp[4];
    arg1->get_pos(1, (Vec_801C6408 *)sp);
    arg0->v = (1.0f + arg1->f3c) - sp[1];
    if (arg0->v > 3.0f) {
        arg0->v = 3.0f;
    }
    if (arg0->v < -4.0f) {
        arg0->v = -4.0f;
    }
}
#pragma pop

void *TForceOperate__ct(void *force_operate, void *arg1, void *arg2) {
    TForceOperate *self = (TForceOperate *)force_operate;
    ((void (*)(void *))__ct__7TObjectFP7TObject)(force_operate);
    *(s32 **)((s8 *)force_operate + 0x18) = accessors::__vt__13TForceOperate;
    fn_8013E020(&self->m_1c);
    self->m_name = TForceOperate__name;
    set_field_0__13TForceOperateFs(&self->m_1c, arg2);
    return force_operate;
}

void TForceOperate::run_task() {
    void *temp_r31;
    void *entity;

    if (accessors::TObjPlayer__sub_801C6DAC((u8 *)&m_1c) != 0) {
        temp_r31 = get_state__11TMainCursorFv((s32)&m_1c);
        if ((is_target_valid__10TObjPlayerFv() != 0) && (((TObjPlayer *)temp_r31)->has_action_palette_entry() != 0)) {
            ((TMainCursor *)(((TObjPlayer *)temp_r31)->m_424 + 0x4F8))->get_id();
            entity = find_entity_by_id();
            if (entity != NULL) {
                ((VObj_801C57D0 *)entity)->m11(get_entity_id((s32)temp_r31));
                queue_destruction();
            }
        }
    }
}

#pragma defer_codegen off
namespace accessors {
extern "C" {
int set_action_flag16__10TObjPlayerFPv(void* p) { return ((int (*)(void*, int))test_flags_any)(p, 16); }

}
}

namespace accessors {
extern "C" {
int test_flag_8__10TObjPlayerFPv(void* p) { return ((int (*)(void*, int))test_flags_any)(p, 8); }

}
}

namespace accessors {
extern "C" {
int TObjPlayer__sub_801C7098(void* p) { return ((int (*)(void*, int))test_flags_any)(p, 2); }

}
}

#pragma defer_codegen on
TPlayerReadyCallback::~TPlayerReadyCallback() {}

TPlyOnCreated::~TPlyOnCreated() {}

TPlyOnCountOver::~TPlyOnCountOver() {}

#pragma defer_codegen off

TPlayerLobbyMarker::~TPlayerLobbyMarker() {}

void TObjPlayer::set_flag_2000000_alt() { set_state_flags((u32)((void*)2097152)); }
s32 TObjPlayer::check_flag_04000000() { return check_flag((s32)((void*)4194304)); }
void TObjPlayer::set_flag_0x8000() { sub_8011E204((s32)((void*)32768)); }
void TObjPlayer::check_flag_0x8000() { check_flag((s32)((void*)32768)); }
void*TObjPlayer::restore_shrunken_font() { TFontSmallLobby__sub_801C0228(this); return this; }
void TObjPlayer::init_6x88_packet() { *(u8*)((char*)this + 0x0) = 136; *(u8*)((char*)this + 0x1) = 1; }
void TObjPlayer::send_font_update_60() { accessors::bswap_g_client_id_header(this); send_subcommand((u8 *)this); }
void TObjPlayer::bswap_shrink() { ((G_ClientIDHeader *)this)->bswap(); bswap_32((u32 *)((char*)this + 0x4)); }
void *TObjPlayer__sub_801C7360(void *arg0, void *arg1) {
    TFontSmallLobby__sub_801C0228(arg0);
    *(f32 *)((s8 *)arg0 + 0x4) = *(f32 *)((s8 *)arg1 + 0x4);
    return arg0;
}
void TObjPlayer::init_shrink_effect() { *(float*)((char*)this + 0x4) = 1.0f; *(unsigned char*)((char*)this + 0x0) = 135; *(unsigned char*)((char*)this + 0x1) = 2; }
void TObjPlayer::update_and_send_60() { bswap_shrink(); send_subcommand((u8 *)this); }
u16 TObjPlayer::interpolate_angle(void *arg0, u16 arg1, u16 arg2, s32 *arg3) {
    s16 temp_r0;
    s32 var_r3;
    temp_r0 = (s16) ((u16) arg2 - arg1);
    if ((temp_r0 > -0x3000) && (temp_r0 < 0x3000)) {
        var_r3 = (temp_r0 >> 4) - (temp_r0 >> 5);
    } else {
        var_r3 = temp_r0 >> 4;
    }
    *arg3 = var_r3;
    return (u16) (arg1 + var_r3);
}
