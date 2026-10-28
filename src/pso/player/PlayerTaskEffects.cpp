#include "pso/system/NinjaTypes.h"
#include "pso/system/ChunkMaterialState.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/TPlyOnCountOver.h"
#include "pso/system/FlagWord.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TPlyOnCreated.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/player/TPlayerSoul.h"
#include "pso/player/TPlayerReadyCallback.h"
#include "pso/player/TPlayerLevelFeedback.h"
#include "pso/player/TPlayerLobbyMarker.h"
#include "types.h"
#include "pso/map/CurrentArea.h"

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
extern const f32 lbl_805DC338;
extern s32 tl_07;
void* __nw__7TObjectFUl(s32);

}

extern "C" {

s32 __ct__11TPlayerSoulFP7TObjectUs();

s32 is_script_controlled__10TObjPlayerFv(s32);

s32 check_flag_0x8000__10TObjPlayerFv();
s32 get_entity_id(s32);
s32 obj_isState3_324__13TUnk_804806E8Fv(s32);

extern s32 tl_06;

}

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/player/TPlayerParticleOwner.h"
#include "pso/TParticleCtrl.h"
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
f32 get_stat_f32__8TItemMagFv(s32);
void set_ring_action__10TObjPlayerFPvi(void*, s32);
void set_stat_scale__10TObjPlayerFPvf(void*, f32);
s32 test_flags_any(s32, s32);
}
#define apply_stat_multipliers__10TObjPlayerFiif ((int (*)(void*))apply_stat_multipliers__10TObjPlayerFiif)
#define set_stat_scale__10TObjPlayerFPvf ((int (*)(void*))set_stat_scale__10TObjPlayerFPvf)

extern "C" {

void apply_stat_multipliers_and_reset__10TObjPlayerFPv(void* p);
s32 get_slot_value__10TObjPlayerFPvi(s32 *arg0, s32 arg1);

}
#undef apply_stat_multipliers__10TObjPlayerFiif
#undef set_stat_scale__10TObjPlayerFPvf

#define TObjPlayer__sub_801C6FCC ((s32 (*)(s32, f32))TObjPlayer__sub_801C6FCC)
#define apply_stat_multipliers_default__10TObjPlayerFv ((int (*)(void*))apply_stat_multipliers_default__10TObjPlayerFv)
#define set_stat_scale__10TObjPlayerFPvf ((int (*)(void*))set_stat_scale__10TObjPlayerFPvf)

extern "C" {

f32 apply_stat_multipliers__10TObjPlayerFiif(s32 arg0, s32 arg1, f32 farg0);
void apply_stats_and_update__10TObjPlayerFPv(void* p);
s32 test_flags_any(s32, s32);
f32 get_stat_f32__8TItemMagFv(s32);
s32 is_flag30_8_set__10TObjPlayerFi(s32);

extern const f32 lbl_805DC33C;
extern const f32 lbl_805DC340;

}
#undef TObjPlayer__sub_801C6FCC
#undef apply_stat_multipliers_default__10TObjPlayerFv
#undef set_stat_scale__10TObjPlayerFPvf

#define TObjPlayer__sub_801C6FDC ((f32* (*)(f32*))TObjPlayer__sub_801C6FDC)
#define apply_stat_multipliers__10TObjPlayerFiif ((s32 (*)(f32))apply_stat_multipliers__10TObjPlayerFiif)
#define get_stat_f32__8TItemMagFv ((f32 (*)(PlayerScaleState*))get_stat_f32__8TItemMagFv)
#define set_stat_scale__10TObjPlayerFPvf ((s32 (*)(f32))set_stat_scale__10TObjPlayerFPvf)

extern "C" {
TObjPlayer* get_player_by_client_id(int);
int obj_isState2_324__13TUnk_804806E8Fv(TObjPlayer*);
extern s32 local_client_id;
void request_player_shrink(PlayerScaleState* state);
TObjPlayer* get_player_by_client_id(int);
int obj_isState2_324__13TUnk_804806E8Fv(TObjPlayer*);
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
int TFontSmallLobby__sub_801C01BC(void *p);
int validate_6x88_restore_shrunken_player(PlayerRestoreSizePacket*);
int clear_shrink_flag__10TObjPlayerFPv(void* p);
void handle_6x88_restore_shrunken_player(const PlayerRestoreSizePacket* input);
void request_follow_camera_offsets(f32*, f32*, u16);
extern const f32 lbl_805DC32C, lbl_805DC344, lbl_805DC348, lbl_805DC34C, lbl_805DC350, lbl_805DC354;
void update_player_scale_camera(PlayerScaleState *state);
}

extern "C" {

void apply_stat_multipliers_default__10TObjPlayerFv(void);
int clear_shrink_flag__10TObjPlayerFPv(void* p);
void handle_6x87_shrink__10TObjPlayerFPvf(u8 *arg0, f32 farg0);
void reset_stat_scale_and_ring__10TObjPlayerFi(s32 arg0);
int clear__8FlagWordFUl(void*, int);

extern const f32 lbl_805DC320;

extern const f32 lbl_805DC320;

}
#undef TObjPlayer__sub_801C6FDC
#undef apply_stat_multipliers__10TObjPlayerFiif
#undef get_stat_f32__8TItemMagFv
#undef set_stat_scale__10TObjPlayerFPvf

#define get_player_by_client_id ((s32 (*)(u16))get_player_by_client_id)
#define test_flags_any ((int (*)(void*, int))test_flags_any)

struct RecoveredGlobal_801C6FF8_lbl_804C4008 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
u8 fn_801C6F2C(u8 *arg0);
int has_water_ground_flag(void *p);
int set_action_flag16__10TObjPlayerFPv(void* p);
int test_flag_8__10TObjPlayerFPv(void* p);
int TObjPlayer__sub_801C7098(void* p);
s32 get_contact_surface_type(s32 arg0);
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_801C6FF8_lbl_804C4008 __vt__18TPlayerLobbyMarker;
u8 *__ct__18TPlayerLobbyMarkerFP7TObjectsSc(u8 *arg0, u8 *arg1, s16 arg2, s8 arg3);
s32 test_flag_2000000__10TObjPlayerFPv(s32);
s32 TObjPlayer__sub_801BF914(s32);
s32 all_parents_unqueued_for_destruction__7TObjectFv();
s32 scale_matrix(s32, f32, f32, f32);
s32 translate_matrix_vec3(s32, s32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 pop_matrix();
s32 draw_chunk_object();
extern u8 player_lobby_marker_color_table[];
extern u8 shared_effect_texture_list[];
extern u8 saved_model_draw_color[];
extern u8 model_material_color[];
extern void *camera_ctrl_instance;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805DC358;
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
#undef get_player_by_client_id

#define get_player_by_client_id ((s32 (*)(u16))get_player_by_client_id)
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
#undef get_player_by_client_id
#undef test_flags_any

}

#include "pso/TPlyOnCountOver.h"

#include "pso/TPlyOnCreated.h"

#include "types.h"
#include "pso/THeap.h"
#include "pso/item/TItemMag.h"
#include "pso/misc/TForceOperate.h"
#include "pso/misc/TMainCursor.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"

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
u8 fn_801C6F2C(u8 *arg0);
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
u8 fn_801C6F2C(u8 *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 4) == 1);
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
    if ((temp_r3 != 0) && (all_parents_unqueued_for_destruction__7TObjectFv() != 0) && (get_material_index() != 0) && (test_flag_2000000__10TObjPlayerFPv(temp_r3) == 0)) {
        push_matrix();
        TParticleCtrl::begin_effect_render();
        saved_model_render_flags = model_render_flags;
        copy_argb((NJS_ARGB *)saved_model_draw_color, (NJS_ARGB *)model_material_color);
        TObjFish::set_global_param((s32)shared_effect_texture_list);
        model_render_flags |= 0x11;
        translate_matrix_vec3(0, TObjPlayer__sub_801BF914(temp_r3 + 0x84C));
        rotate_matrix_y(0, *(s32 *)((s8 *)camera_ctrl_instance + 0x194) + rotation);
        scale_matrix(0, lbl_805DC358, lbl_805DC358, lbl_805DC358);
        set_constant_material((const NJS_ARGB *)((player_lobby_marker_color_table + get_material_index() * 0x10)));
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
    if (!player || !obj_isState2_324__13TUnk_804806E8Fv(player)) {
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
    if (!player || !obj_isState2_324__13TUnk_804806E8Fv(player)) {
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
    TFontSmallLobby__sub_801C01BC(&packet);
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
  f32 z = lbl_805DC34C * ((f32 (*)(PlayerScaleState*))get_stat_f32__8TItemMagFv)(state);
  TObjPlayer__sub_801C6FE0(state->camera_position, lbl_805DC32C, lbl_805DC344 * (lbl_805DC348 * ((f32 (*)(PlayerScaleState*))get_stat_f32__8TItemMagFv)(state)), z);
  TObjPlayer__sub_801C6FE0(state->camera_target, lbl_805DC32C, lbl_805DC350 * ((f32 (*)(PlayerScaleState*))get_stat_f32__8TItemMagFv)(state), lbl_805DC354);
  request_follow_camera_offsets(((f32* (*)(f32*))TObjPlayer__sub_801C6FDC)(state->camera_target), ((f32* (*)(f32*))TObjPlayer__sub_801C6FDC)(state->camera_position), 0xFFFF);
}

}
}

namespace accessors {
extern "C" {
void reset_stat_scale_and_ring__10TObjPlayerFi(s32 arg0) {
    ((s32 (*)(f32))set_stat_scale__10TObjPlayerFPvf)(lbl_805DC320);
    set_ring_action__10TObjPlayerFPvi((void *)arg0, 0);
}

}
}

namespace accessors {
extern "C" {
void apply_stat_multipliers_default__10TObjPlayerFv(void) {
    ((s32 (*)(f32))apply_stat_multipliers__10TObjPlayerFiif)(lbl_805DC320);
}

}
}

namespace accessors {
extern "C" {
f32 apply_stat_multipliers__10TObjPlayerFiif(s32 arg0, s32 arg1, f32 farg0) {
    f32 var_f31;

    var_f31 = farg0;
    if (is_flag30_8_set__10TObjPlayerFi(arg1) != 0) {
        var_f31 *= lbl_805DC33C;
    } else if (test_flags_any(arg0 + 0xC, 8) != 0) {
        var_f31 *= lbl_805DC340;
    }
    ((s32 (*)(s32, f32))TObjPlayer__sub_801C6FCC)(arg0, var_f31);
    if (((TItemMag *)(arg1 + 0x5B0))->check_state_flag_1() != 0) {
        var_f31 *= get_stat_f32__8TItemMagFv(arg1 + 0x5B0);
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

    if ((check_flag_0x8000__10TObjPlayerFv() != 0) || (obj_isState3_324__13TUnk_804806E8Fv(player) != 0) || (is_script_controlled__10TObjPlayerFv(player) != 0)) {
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
    if (p != NULL && test_action_mask__10TObjPlayerFl(p, 0x8000) != 0 && are_items_enabled_here() != 0 &&
        is_on_current_floor__10TObjPlayerFi(p) != 0) {
        h = get_particle();
        if (h != 0) {
            p->get_pos(1, &v);
            v.y += lbl_805DC338;
            ((TNowLoading *)h)->copy_pos(&v);
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
