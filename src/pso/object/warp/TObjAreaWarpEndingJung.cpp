#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/vector.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/object/door/TObjDoorJung.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdVIConfigGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/object/warp/TObjWarpString.h"
#include "pso/object/warp/TObjMapWarpForest.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/object/warp/TObjAreaWarp.h"
#include "pso/object/warp/TObjAreaWarpEnding.h"
#include "pso/object/warp/TObjAreaWarpEndingJung.h"
#include "pso/object/warp/TObjAreaWarpForest.h"
#include "pso/object/warp/TObjAreaWarpQuest.h"
#include "pso/object/warp/TObjMapForceWarp.h"
#include "pso/object/warp/TObjMapWarp.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/MenuText.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/TObjLuker.h"
#include "pso/object/warp/TObjWarpJung.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/object/warp/TObjWarpBase.h"
#include "pso/technique/TTecLuker.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjChara.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/object/warp/ForestWarpResources.h"
#include "pso/system/ControllerInputState.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/system/byteswap.h"

// The original TU was built with deferred codegen: functions below are in reverse
// address order, and the pool (three {3, 2} initializers, then the float literals
// and "%xF" in first-use order) comes out exactly as in the original .sdata2.
#pragma defer_codegen on

struct VObjBase_8019B124 { char pad[0x18]; };

struct VObj_8019B124 : VObjBase_8019B124 {
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

struct Warp_8019B170 { u8 pad0[0x8C]; s32 f8C; };

struct RecoveredGlobal_8019B854___vt__14TObjWarpString {
    s32 value;
    u8 remaining[0x14];
};

typedef char RecoveredGlobal_8019B854___vt__14TObjWarpString_size[sizeof(RecoveredGlobal_8019B854___vt__14TObjWarpString) == 0x18 ? 1 : -1];

struct Obj_8019B8D8 { u8 pad[0x88]; s32 id; };


struct Obj_8019C924 { u8 pad0[0x84]; s32 id; u8 pad1[0xbc - 0x88]; s32 saved_id; };

struct Pkt_8019C988 { u8 pad0[4]; s16 f4; };

struct ObjBase_8019BD84 { char pad[0x18]; };

struct Obj_8019BD84 : ObjBase_8019BD84 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 is_visible(f32, f32);
};

struct Node_8019BD84 { u32 flags; void *model; f32 pos[3]; s32 ang[3]; f32 scl[3]; Node_8019BD84 *child; Node_8019BD84 *sibling; };

struct Ids_8019BD84 { u16 id[2]; };

struct Warp_8019BD84 { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0x1C]; s32 f60; u8 pad64[0x28]; s32 f8C; u8 pad90[0x34]; f32 fC4; s32 fC8; Node_8019BD84 *fCC; Node_8019BD84 *fD0; s32 fD4; s32 fD8; };


struct VBase_8019C250 { char pad[0x18]; };

struct VObj_8019C250 : VBase_8019C250 {
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

struct Node_8019C250 {
    u8 pad0[4];
    void *f4;
    u8 f8[0xC];
    s32 f14;
    s32 f18;
    s32 f1C;
    u8 pad20[0x2C - 0x20];
    Node_8019C250 *next2C;
    Node_8019C250 *next30;
};

struct Obj_8019C250 {
    u8 pad0[0x38];
    u8 f38[0x60 - 0x38];
    s32 f60;
    u8 pad64[0x8C - 0x64];
    s32 f8C;
    u8 pad90[0xC8 - 0x90];
    f32 fC8;
    s32 fCC;
    Node_8019C250 *fD0;
    Node_8019C250 *fD4;
    s32 fD8;
    s32 fDC;
};

struct Colors_8019C250 { u16 c[2]; };

struct VBase_8019C604 { char pad[0x18]; };

struct VObj_8019C604 : VBase_8019C604 {
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

struct Node_8019C604 {
    u8 pad0[4];
    void *f4;
    u8 f8[0xC];
    s32 f14;
    s32 f18;
    s32 f1C;
    u8 pad20[0x2C - 0x20];
    Node_8019C604 *next2C;
    Node_8019C604 *next30;
};

struct Obj_8019C604 {
    u8 pad0[0x38];
    u8 f38[0x60 - 0x38];
    s32 f60;
    u8 pad64[0x8C - 0x64];
    s32 f8C;
    u8 pad90[0xC4 - 0x90];
    f32 fC8;
    s32 fCC;
    Node_8019C604 *fD0;
    Node_8019C604 *fD4;
    s32 fD8;
    s32 fDC;
};

struct Colors_8019C604 { u16 c[2]; };

struct Obj_8019BCBC {
    u8 pad0[0x8C];
    s32 f8C;
};

struct Obj_8019C53C {
    u8 pad0[0x8C];
    s32 f8C;
};

struct Obj_8019C144 {
    u8 pad0[0x68];
    f32 f68;
    u8 pad1[0x8C - 0x6C];
    s32 f8C;
    u8 pad2[0xC4 - 0x90];
    s32 fC4;
};

struct VBase8019CF38_8019CCF0 { char pad[0x18]; };

struct VObj8019CF38_8019CCF0 : VBase8019CF38_8019CCF0 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

struct RecoveredGlobal_8019CA24_lbl_80515BA0 {
    s32 value;
    u8 remaining[0x24];
};

struct Vec_8019D0A8 { f32 x, y, z; };


struct Warp_8019D0A8 {
    u8 pad0[0x60];
    s32 yaw;
    u8 pad64[0x68 - 0x64];
    Vec_8019D0A8 pos;
    u8 pad74[0x84 - 0x74];
    s32 yaw2;
    u8 pad88[0xBC - 0x88];
    Vec_8019D0A8 ends[4];
};

struct VBase_8019D250 { char pad[0x18]; };

struct VObj_8019D250 : VBase_8019D250 {
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
    virtual void m13(s32);
    virtual s32 m14();
    virtual void m15();
    virtual s32 m16(s32);
    virtual void m17();
    virtual void m18(u16);
};

struct Vec_8019D250 { f32 x, y, z; };

struct Data_8019D250 {
    u8 pad0[0x84];
    s32 f84;
    u8 pad88[0xAC - 0x88];
    f32 fAC;
    void *fB0;
    u8 padB4[0xBC - 0xB4];
    Vec_8019D250 ends[4];
    void *win[4];
};

struct VBase_8019CAB0 { char pad[0x18]; };

struct VObj_8019CAB0 : VBase_8019CAB0 {
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
    virtual void m13(s32);
    virtual s32 m14();
    virtual void m15();
    virtual s32 m16(s32);
    virtual void m17(void *);
};

struct Data_8019CAB0 {
    u8 pad0[0xAC];
    f32 fAC;
    void *fB0;
    u8 padB4[0xC0 - 0xB4];
    void *fC0;
};

typedef char RecoveredGlobal_8019CA24_lbl_80515BA0_size[sizeof(RecoveredGlobal_8019CA24_lbl_80515BA0) == 0x28 ? 1 : -1];


struct VObj_8019D250;
extern "C" {

s32 get_main_phase();
void mark_area_change_pending();
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
u16 get_entity_id(void *);
s32 is_split_screen();
s32 get_current_floor();
void queue_destruction__7TObjectFv(void *);
s32 get_split_screen_view_index__11TCameraCtrlFUs(void *);
u32 TLobby__sub_80070AD8(s32 arg0);
s32 get_floor_destination_name();
s32 get_localized_text_entry(s32, s32);
s32 debug_draw_line(void *, void *, u32, u32);
s32 fn_80141CB4(void *, f32);
s32 test_player_body_overlap_at(void *, void *, Vec_8019D250 *);
s32 TObjCityMainWarp__sub_80186AF4();
void * TObjAreaWarpEndingJung__create(void *arg0);
s64 fn_8019B480(void *arg0, void *arg1);
void fade_and_destroy__14TObjWarpStringFPv(u8 *arg0);
void TObjWarpString__sub_8019B728(void *arg0);
void update_fade_in__14TObjWarpStringFPv(u8 *arg0);
void sub_8019B77C__14TObjWarpStringFv(void *arg0);
u8 * __ct__14TObjWarpStringFv(u8 *arg0, u8 *arg1, s32 arg2, s16 arg3);
void handle_6x94_inter_level_warp(Pkt_8019C988 *arg0);
s32 can_warp__11TObjMapWarpFlUs(void *, u16);
void *find_warp_player_in_range(void *self, u16 client_id, f32 range);
void TObjAreaWarpQuest__sub_8019DCD8(void *, s32);
f32 get_static_field4_as_float__12TObjWarpJungFv(f32);
s32 TObjWarpJung__sub_801A0404(s32);
int check_flag_100__10TObjPlayerFPv(void *p);
void send_6x21_inter_level_warp(void *obj, s32 value);
void send_6x55_intra_map_warp(u16 id, void *pos, s32 c);
s32 init__23TAdSinglePlyChrSelectGCFv();
s32 get_floor_map_terrain(s32);
void set_area__6TLobbyFl(void *, int, int);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);
void __ct__7TObjectFP7TObject(void *, void *);
s32 align_menu_entry_positions(u32);
s32 get_window_layout_position(s32);
s32 find_active_player__12TObjAreaWarpFv(void *);
void *destroy__13TAdVIConfigGCFPvs(void *arg0, s16 arg1);
s32 init__13TAdVIConfigGCFf(int, void *, f32);
s32 get_game_play_mode(int);
void send_inter_level_warp_all__10TNpcPlayerFl();
s32 PPCSync();
int sprintf(char *, const char *, ...);
void strncpy(s32, s32, s32);
void debug_printf_at(s32 id, const char *fmt, ...);
s32 matrix_mult_vec(int, void *, void *);
void rotate_matrix_zyx(void *m, s32 x, s32 y, s32 z);
void rotate_matrix_x(int, s32);
void push_matrix();
s32 post_translate_matrix(void *);
void draw_ginja_model_with_motion(s32, s32, f32);

extern RecoveredGlobal_8019B854___vt__14TObjWarpString __vt__14TObjWarpString;
extern RecoveredGlobal_8019CA24_lbl_80515BA0 lbl_80515BA0;
extern u8 identity_matrix[];
extern s32 local_client_id;
}

void *create_TObjWarpString(char *text, u16 client_id);
void bswap_6x94_inter_level_warp(void *);
void mask_action_buttons(void *p, u32 v);
s32 should_record_episode1_quest_completion();union WarpStringPos {
    s64 packed;
    struct {
        f32 x;
        f32 y;
    } xy;
};
// The table is 4-aligned in the original, so its entries are float pairs, not s64.
struct WarpStringScreenPos { f32 x, y; };

struct Base_8019D4E4 { char pad[0x18]; };
struct VObj_8019D4E4 : Base_8019D4E4 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30();
    virtual s32 m31();
};
struct Base_8019D880_8019D4E4 { char pad[0x18]; };
struct VObj_8019D880_8019D4E4 : Base_8019D880_8019D4E4 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30();
    virtual s32 m31();
};

extern "C" {

s32 TWindowShortListCtrl__check_controller_button(ControllerInputContext *context, s32 button);
void fn_8019DD24(void *p, u32 v);

int is_flag_400_set__10TObjPlayerFPv(void *p);

extern s32 lbl_805D55C0;

}

extern "C" {

f32 xz_distance_squared(void *, void *);

s32 release_texture_list(void*);
}

BmlResource *forest_warp_bml_resource;
u32 forest_warp_texture_list;
// Set by TLobby while a quest is in progress; TObjAreaWarp's ctor reads it.
s32 lobby_quest_progress_flag;


// Function definitions in reverse address order (defer_codegen emits them reversed).

const char *fs_obj_warp_model_names[] = {
    "fs_obj_warp.gj", "fs_obj_warp_beam.gj", "fs_obj_warp_dai.gj", "fs_obj_warp_dai_beam.gj",
    "fs_obj_warp_n.gj", "fs_obj_warp_n_beam.gj", NULL,
};
const char *fs_obj_warp_motion_names[] = {
    "fs_obj_warp_beam.njm", "fs_obj_warp_dai_beam.njm", "fs_obj_warp_n_beam.njm", NULL,
};
BmlResourceDescriptor forest_warp_resource_descriptor = {
    "fs_obj_warp.bml", fs_obj_warp_model_names, fs_obj_warp_motion_names, 6, 3,
};

Vec_8019D0A8 map_warp_destination_offsets[4] = {
    { 10.0f, 0.0f, 10.0f }, { 10.0f, 0.0f, -10.0f }, { -10.0f, 0.0f, 10.0f }, { -10.0f, 0.0f, -10.0f },
};

// Screen position of the warp id string: one entry for a single screen, then the
// split-screen views of camera 2 (1 entry), 3 (2) and 4 (4), see fn_8019B480.
WarpStringScreenPos warp_string_screen_position_table[10] = {
    { 320.0f, 200.0f },
    { 320.0f, 120.0f },
    { 320.0f, 260.0f }, { 160.0f, 120.0f },
    { 480.0f, 120.0f }, { 320.0f, 260.0f }, { 160.0f, 120.0f },
    { 480.0f, 120.0f }, { 160.0f, 260.0f }, { 480.0f, 260.0f },
};

// The tail after load_forest_warp_resources (the original's inline helpers and
// ~TObjMapWarpForest), in reverse address order like the rest.
void fn_8019DD24(void *p, u32 v) { *(u32 *)((char *)p + 0x8) |= v; }

void mask_action_buttons(void *p, u32 v) { *(u32 *)((char *)p + 0x8) &= ~v; }

void bswap_6x94_inter_level_warp(void *p) { ((G_ClientIDHeader *)p)->bswap(); bswap_16((u16 *)((char *)p + 0x4)); }

void TObjAreaWarpQuest__sub_8019DCD8(void *p, s32 v) { *(s32 *)((char *)p + 0x3c8) = v; }

s32 TObjAreaWarpQuest::get_dest_area() { return *(s32 *)&this->m_next; }

TObjMapWarpForest::~TObjMapWarpForest() {}

void TObjMapForceWarp::open_confirm_window(s32) {}

s32 get_forest_warp_model(s32 index) { return get_bml_model(forest_warp_bml_resource, index); }

AnimationMotion *get_forest_warp_motion(s32 index) { return get_bml_motion(forest_warp_bml_resource, index); }

u32 get_forest_warp_textures() { return forest_warp_texture_list; }

int TAdStorySelectGC::get_story_select() { return story_select_cursor; }

void load_forest_warp_resources(void) {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != 0) {
        resource = load_resource_from_descriptor(resource, 5, &forest_warp_resource_descriptor, 0, 0, 0);
    }
    forest_warp_bml_resource = resource;
    forest_warp_texture_list = (u32)load_gvm_texture_file((s32)"fs_obj_warp.gvm");
}

extern "C" {

void TObjWarpBase::free_globals() {
    if ((u32) forest_warp_texture_list != 0U) {
        release_texture_list((void*)forest_warp_texture_list);
        TAdSinglePlyChrSelectGC::safe_free(forest_warp_texture_list);
        forest_warp_texture_list = 0U;
    }
    free_bin_model_request(forest_warp_bml_resource, 1);
    forest_warp_bml_resource = 0;
}

// Read by is_warp_enabled and can_warp; TLobby sets and clears it.
s32 quest_warp_enabled = 1;
const char *TObjWarpBase__name = "TObjWarpBase";

TObjWarpBase::TObjWarpBase(TObject *parent, void *set_data) : TObjCollidable(parent) {
    void *collider;
    m_name = TObjWarpBase__name;
    apply_object_set_data(set_data);
    warp_range = 10.0f;
    menu_window = 0;
    collider = TObject::operator new(0xB4);
    if (collider != NULL) {
        collider = ((TTecLuker *)collider)->construct_field_collider((s32)&position, (s32)this, 1);
    }
    field_collider = collider;
    user_client_id = 0xFFFF;
}

TObjWarpBase::~TObjWarpBase() {
    vfunc_14();
}

void *find_warp_player_in_range(void *self, u16 client_id, f32 range) {
  u8 *player;
  player = (u8 *)get_player_by_client_id(client_id);
  if ((player != 0) && (xz_distance_squared((u8 *)self + 0x38, player + 0x38) < (range * range)))
  {
    if (check_flag_100__10TObjPlayerFPv(player) == 1)
    {
      return 0;
    }
    return player;
  }
  return 0;
}

void TObjWarpBase::vfunc_14() {
    u32 player;

    player = (u32) *(u32 *)((s8 *)this + 0xB0);
    if (player != 0U) {
        ((TWindowBase *)player)->close();
        *(u32 *)((s8 *)this + 0xB0) = 0U;
        player = (u32)get_player_by_client_id(*(u16 *)((s8 *)this + 0xB8));
        if (player != 0U) {
            fn_8019DD24((void *)(player + 0x550), 4);
        }
        *(u16 *)((s8 *)this + 0xB8) = 0xFFFFU;
    }
}

u8 TObjWarpBase::is_warp_enabled() {
    void *player;
    u32 id = *(u16 *)((s8 *)this + 0xB8);

    player = NULL;
    if ((id != 0xFFFF) && ((player = get_player_by_client_id(id), ((player == NULL) != 0)) || (check_flag_100__10TObjPlayerFPv(player) != 0))) {
        return 0U;
    }
    if ((s32) quest_warp_enabled == 0) {
        return 0U;
    }
    if ((s32) lbl_805D55C0 != 0) {
        return 0U;
    }
    if ((player != NULL) && (((VObj_8019D880_8019D4E4 *)player)->m31() != 0)) {
        return 0U;
    }
    if (player != NULL) {
        return (u8) (is_flag_400_set__10TObjPlayerFPv(player) == 0);
    }
    if ((player != NULL) && (((TObjPlayer *)player)->is_body_collision_inactive() != 0)) {
        return 0U;
    }
    return 1U;
}

s32 TObjWarpBase::vfunc_17() {
    return TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[0], 4);
}

s32 TObjWarpBase::vfunc_18(s32 client_id) {
    return TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[client_id], 4);
}

const char *TObjMapWarp__name = "TObjMapWarp";

// The set entry's scale holds the destination; each player gets a spot at its offset from it.
TObjMapWarp::TObjMapWarp(TObject *parent, void *set_data) : TObjWarpBase(parent, set_data) {
    s32 i;
    m_name = TObjMapWarp__name;
    for (i = 0; i < 4; i++) {
        push_matrix_from(identity_matrix);
        post_translate_matrix(&scale);
        rotate_matrix_y(0, rotation_y);
        matrix_mult_vec(0, &map_warp_destination_offsets[i], destinations[i]);
        pop_matrix();
        playerPopups[i] = 0;
    }
}

TObjMapWarp::~TObjMapWarp() {
    vfunc_14();
}

void TObjMapWarp::vfunc_14() {
    for(s32 slot=0;slot<4;++slot)closePlayerWindow((u16)slot);
}

#pragma push
#pragma opt_common_subs off
void TObjMapWarp::closePlayerWindow(u16 arg1) {
    s32 arg0 = (s32)this;
    u32 temp_r3;
    u32 player;
    u8 *temp_r31;
    temp_r31 = (u8 *)(arg0 + ((arg1 * 4) & 0x3FFFC));
    temp_r3 = *(u32 *)((s8 *)temp_r31 + 0xEC);
    if (temp_r3 != 0U) {
        ((TWindowBase *)temp_r3)->close();
        *(u32 *)((s8 *)temp_r31 + 0xEC) = 0U;
        player = ((u32)get_player_by_client_id((u32)((void *) ((s32) arg1))));
        if (player != 0U) {
            fn_8019DD24((void *)(player + 0x550), 4);
        }
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void TObjMapWarp::open_confirm_window(s32 arg1) {
    s32 arg0 = (s32)this;
    u8 *temp_r31;
    temp_r31 = (u8 *)(arg0 + (arg1 * 4));
    if ((u32) *(u32 *)((s8 *)temp_r31 + 0xEC) == 0U) {
        *(u32 *)((s8 *)temp_r31 + 0xEC) = ((s32 (*)(s32, s32, s32))create_window_menu)(get_window_layout_position(0x33), 1, arg1);
        ((TWindowSubTradeMain *)(*(u32 *)((s8 *)temp_r31 + 0xEC)))->add_text_entry(get_localized_text_entry(9, 0x25), 2, 0, -1);
        ((TWindowSubComCard *)(*(u32 *)((s8 *)temp_r31 + 0xEC)))->calc_window_size();
        align_menu_entry_positions((int) (*(u32 *)((s8 *)temp_r31 + 0xEC)));
        ((TWindowSubComCardList *)(*(u32 *)((s8 *)temp_r31 + 0xEC)))->set_flag70_bit10();
        ((TAdChrSelASlotGC *)(*(u32 *)((s8 *)temp_r31 + 0xEC)))->set_flag_40();
    }
}
#pragma pop

u8 TObjMapWarp::can_warp(s32 arg0, u16 arg1) {
    void *player;
    u32 id;

    id = arg1;
    player = NULL;
    if ((id != 0xFFFF) &&((player = get_player_by_client_id(id), ((player == NULL) != 0)) || (check_flag_100__10TObjPlayerFPv(player) != 0))) {
        return 0U;
    }
    if ((s32) quest_warp_enabled == 0) {
        return 0U;
    }
    if ((s32) lbl_805D55C0 != 0) {
        return 0U;
    }
    if ((player != NULL) && (((VObj_8019D4E4 *)player)->m31() != 0)) {
        return 0U;
    }
    if (player != NULL) {
        return (u8) (is_flag_400_set__10TObjPlayerFPv(player) == 0);
    }
    return 1U;
}

}

void TObjMapWarp::process_player_warps() {
    Data_8019D250 *d = (Data_8019D250 *)this;
    s32 i;
    void *t;
    s32 j;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        for (i = 0; i < 4; i++) {
            if (can_warp__11TObjMapWarpFlUs(this, i) == 0) {
                if (d->win[i] != NULL) {
                    ((TWindowBase *)(d->win[i]))->close();
                    d->win[i] = NULL;
                }
            } else {
                if (d->win[i] != NULL) {
                    ((TQuestVmDownLoadServer *)(d->win[i]))->clear_flag4_bit4();
                    ((TObject *)d->win[i])->allow_rendering();
                }
                t = find_warp_player_in_range(this, i, d->fAC);
                if (t != NULL) {
                    ((VObj_8019D250 *)this)->m13(get_entity_id(t));
                    if (((TObjPlayer *)t)->is_target_valid() != 0 && ((VObj_8019D250 *)this)->m16(((TRaderMapCore *)t)->get_map_id()) != 0) {
                        for (j = 0; j < 4; j++) {
                            if (test_player_body_overlap_at(this, t, &d->ends[j]) == 0) {
                                send_6x55_intra_map_warp(get_entity_id(t), &d->ends[j], this->set_params[0]);
                            }
                        }
                    }
                } else {
                    this->closePlayerWindow(i);
                }
            }
        }
        return;
    }
    if (((VObj_8019D250 *)this)->m14() == 0) {
        if (this->menu_window != NULL) {
            ((TWindowBase *)this->menu_window)->close();
            this->menu_window = NULL;
        }
    } else {
        void *t2;
        s32 j2;
        if (this->menu_window != NULL) {
            ((TQuestVmDownLoadServer *)(this->menu_window))->clear_flag4_bit4();
            ((TObject *)this->menu_window)->allow_rendering();
        }
        t2 = find_warp_player_in_range(((VObj_8019D250 *)this), local_client_id, d->fAC);
        if (t2 != NULL) {
            ((VObj_8019D250 *)this)->m13(local_client_id);
            if (((TObjPlayer *)t2)->is_target_valid() != 0 && ((VObj_8019D250 *)this)->m16(((TRaderMapCore *)t2)->get_map_id()) != 0) {
                for (j2 = 0; j2 < 4; j2++) {
                    if (test_player_body_overlap_at(((VObj_8019D250 *)this), t2, &d->ends[j2]) == 0) {
                        send_6x55_intra_map_warp(get_entity_id(t2), &d->ends[j2], this->set_params[0]);
                    }
                }
            }
        } else {
            this->vfunc_14();
        }
    }
}

void TObjMapWarp::draw_debug_destinations() {
    u8 *arg0 = (u8 *)this;
    Warp_8019D0A8 *self = (Warp_8019D0A8 *)arg0;
    Vec_8019D0A8 *end;
    s32 i;
    TObjNpcEnemy::set_global_count(0xFF00FF);
    ((s32 (*)(s32, const char *, ...))debug_printf_at)(0x13001C, "<- DST POS X");
    ((s32 (*)(s32, const char *, ...))debug_printf_at)(0x13001D, "<- DST POS Y");
    ((s32 (*)(s32, const char *, ...))debug_printf_at)(0x13001E, "<- DST POS Z");
    ((s32 (*)(s32, const char *, ...))debug_printf_at)(0x130020, "<- DST ANG Y");
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    for (i = 0; i < 4; i++) {
        Vec_8019D0A8 b;
        Vec_8019D0A8 a = {0.0f, 0.0f, -3.0f};
        push_matrix_from(identity_matrix);
        post_translate_matrix(&self->pos);
        rotate_matrix_y(0, self->yaw);
        end = &self->ends[i];
        matrix_mult_vec(0, &map_warp_destination_offsets[i], end);
        pop_matrix();
        push_matrix_from(identity_matrix);
        post_translate_matrix(end);
        rotate_matrix_y(0, self->yaw2);
        matrix_mult_vec(0, &a, &a);
        pop_matrix();
        VecCopy((Vec *)&b, (const Vec *)end);
        b.y += 5.0f;
        a.y += 5.0f;
        debug_draw_line(&b, &a, 0xFFFF0000, 0xFFFF0000);
        fn_80141CB4(end, 15.0f);
    }
}

const char *TObjMapWarpForest__name = "TObjMapWarpForest";

TObjMapWarpForest::TObjMapWarpForest(TObject *parent, void *set_data) : TObjMapWarp(parent, set_data) {
    m_name = TObjMapWarpForest__name;
    baseModel = get_forest_warp_model(4);
    beamModel = get_forest_warp_model(5);
    motion = get_forest_warp_motion(2);
    textures = get_forest_warp_textures();
    frame = 0.0f;
}

void TObjMapWarpForest::run_task() {
    this->frame+=4.0f;
    if((f32)(u32)(this->motion->frameCount-1)<this->frame)this->frame=0.0f;
    process_player_warps();
}

void TObjMapWarpForest::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj8019CF38_8019CCF0 *) arg0)->m8(400.0f, 20.0f) != 0) {
        TObjFish::set_global_param(textures);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_ginja_object((void *)baseModel);
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion(beamModel, (s32)motion, frame);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

const char *TObjAreaWarp__name = "TObjAreaWarp";

TObjAreaWarp::TObjAreaWarp(TObject *parent, void *set_data) : TObjWarpBase(parent, set_data) {
    m_name = TObjAreaWarp__name;
    dest_floor = set_params[0];
    if (lobby_quest_progress_flag != 0) {
        dest_floor = get_current_floor() + 1;
    }
    vi_config = NULL;
}

TObjAreaWarp::~TObjAreaWarp() {
    if (vi_config != NULL) {
        destroy__13TAdVIConfigGCFPvs(vi_config, 1);
        vi_config = NULL;
    }
    vfunc_14();
}

void TObjAreaWarp::open_confirm_window(s32 arg1) {
    u32 temp_r3;

    if ((u32) *(u32 *)((s8 *)this + 0xB0) == 0U) {
        *(u32 *)((s8 *)this + 0xB0) = ((u32 (*)(s32, s32, s32))create_window_menu)(get_window_layout_position(0x33), 1, arg1);
        if (((s32 (*)(void))get_game_play_mode)() == 1) {
            ((TWindowSubTradeMain *)(*(u32 *)((s8 *)this + 0xB0)))->add_text_entry(TObjCityMainWarp__sub_80186AF4(), 2, 0, -1);
        } else {
            get_floor_area(*(s32 *)((s8 *)this + 0xBC));
            ((TWindowSubTradeMain *)(*(u32 *)((s8 *)this + 0xB0)))->add_text_entry(get_floor_destination_name(), 2, 0, -1);
        }
        ((TWindowSubComCard *)(*(u32 *)((s8 *)this + 0xB0)))->calc_window_size();
        align_menu_entry_positions(*(u32 *)((s8 *)this + 0xB0));
        ((TWindowSubComCardList *)(*(u32 *)((s8 *)this + 0xB0)))->set_flag70_bit10();
        ((TAdChrSelASlotGC *)(*(u32 *)((s8 *)this + 0xB0)))->set_flag_40();
        *(u16 *)((s8 *)this + 0xB8) = arg1;
        temp_r3 = (u32)get_player_by_client_id(*(u16 *)((s8 *)this + 0xB8));
        if (temp_r3 != 0U) {
            mask_action_buttons((void *)(temp_r3 + 0x550), 4);
        }
    }
}

u8 TObjAreaWarp::is_warp_enabled() {
    s32 var_r31;
    void *player;

    if (TRaderMapCore::is_not_split_screen() == 1) {
        var_r31 = 0;
loop_2:
        if (((player = get_player_by_client_id(var_r31)) != 0) && (check_flag_100__10TObjPlayerFPv(player) != 0)) {
            return 0;
        }
        var_r31 += 1;
        if (var_r31 >= 4) {
            goto block_6;
        }
        goto loop_2;
    }
block_6:
    return TObjWarpBase::is_warp_enabled();
}

void TObjAreaWarp::handle_area_selection() {
    Data_8019CAB0 *d = (Data_8019CAB0 *)this;
    s32 found;
    s32 i;
    void *t;
    if (((VObj_8019CAB0 *)this)->m14() == 0) {
        if (d->fB0 != NULL) {
            ((TWindowBase *)d->fB0)->close();
            d->fB0 = NULL;
        }
    } else {
        if (d->fB0 != NULL) {
            ((TQuestVmDownLoadServer *)(d->fB0))->clear_flag4_bit4();
            ((TObject *)d->fB0)->allow_rendering();
        }
        if (is_split_screen() != 0) {
            found = 0;
            if (d->fC0 != NULL) {
                ((TAdVIConfigGC *)(d->fC0))->update_visibility();
                if (((TAdVIConfigGC *)(d->fC0))->get_field_14() == 0) {
                    this->vfunc_14();
                    return;
                }
            }
            for (i = 0; i < 4; i++) {
                t = find_warp_player_in_range(((VObj_8019CAB0 *)this), i, d->fAC);
                if (t != NULL) {
                    found = 1;
                    if (d->fC0 != NULL) {
                        ((VObj_8019CAB0 *)this)->m13(find_active_player__12TObjAreaWarpFv(d->fC0));
                    } else {
                        ((VObj_8019CAB0 *)this)->m13(get_entity_id(t));
                    }
                    if (((VObj_8019CAB0 *)this)->m16(i) != 0) {
                        this->vfunc_14();
                        this->confirm_area_transfer(t);
                    }
                }
            }
            if (found == 0) {
                this->vfunc_14();
            }
        } else {
            void *t2 = find_warp_player_in_range(((VObj_8019CAB0 *)this), local_client_id, d->fAC);
            if (t2 != NULL) {
                ((VObj_8019CAB0 *)this)->m13(local_client_id);
                if (((VObj_8019CAB0 *)this)->m16(((TRaderMapCore *)t2)->get_map_id()) != 0) {
                    this->vfunc_14();
                    this->confirm_area_transfer(t2);
                }
            } else {
                this->vfunc_14();
            }
        }
    }
}

void TObjAreaWarp::confirm_area_transfer(void *player) {
    ((s32 (*)(void *, int, int))set_area__6TLobbyFl)(&lbl_80515BA0.value, (int) (*(s32 *)((s8 *)this + 0xBC)), (int) (get_floor_map_terrain(*(s32 *)((s8 *)this + 0xBC))));
    ((s32 (*)(void))mark_area_change_pending)();
    ((TObjAreaWarpQuest *)(&lbl_80515BA0.value))->get_dest_area();
    ((s32 (*)(void))send_inter_level_warp_all__10TNpcPlayerFl)();
    send_6x21_inter_level_warp(player, (((TObjAreaWarpQuest *)(&lbl_80515BA0.value))->get_dest_area()));
    ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(0x40003205, 0U, 0, 0);
}

void handle_6x94_inter_level_warp(Pkt_8019C988 *arg0) {
    bswap_6x94_inter_level_warp(arg0);
    if (arg0->f4 != get_current_floor()) {
        set_area__6TLobbyFl(((u8 *)&lbl_80515BA0), arg0->f4, get_floor_map_terrain(arg0->f4));
        mark_area_change_pending();
        ((TWindowCtrl *)local_client_id)->suppress_slot();
        ((TObjAreaWarpQuest *)((u8 *)&lbl_80515BA0))->get_dest_area();
        send_inter_level_warp_all__10TNpcPlayerFl();
        void *p = get_player_by_client_id(local_client_id);
        if (p != 0) {
            send_6x21_inter_level_warp(p, (s32)(((TObjAreaWarpQuest *)((u8 *)&lbl_80515BA0))->get_dest_area()));
        }
    }
}

void TObjAreaWarp::debug_print_area_num() {
    Obj_8019C924 *self = (Obj_8019C924 *)this;
    self->saved_id = self->id;
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, "<- AREA NUM : %d", self->saved_id);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

const char *TObjAreaWarpForest__name = "TObjAreaWarpForest";

TObjAreaWarpForest::TObjAreaWarpForest(TObject *parent, void *set_data) : TObjAreaWarp(parent, set_data) {
    s32 temp_r3_2;
    s32 var_r0;
    u32 temp_r0;
    u32 temp_r3;
    m_name = TObjAreaWarpForest__name;
    m_c4 = 0.0f;
    *(s32 *)((s8 *)this + 0xC8) = 0;
    temp_r0 = set_params[2];
    temp_r3 = temp_r0 >> 0x1FU;
    set_params[2] = (u32) (((temp_r0 & 1) ^ temp_r3) - temp_r3);
    if ((get_game_play_mode(temp_r3) == 1) && ((s32) set_params[2] == 0)) {
        queue_destruction();
        return;
    }
    warp_model = get_forest_warp_model(0);
    beam_model = get_forest_warp_model(1);
    beam_motion = get_forest_warp_motion(0);
    textures = get_forest_warp_textures();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        temp_r3_2 = (int)::operator new(0x88);
        var_r0 = temp_r3_2;
        if (var_r0 != 0) {
            var_r0 = init__13TAdVIConfigGCFf(temp_r3_2, &position, 20.0f);
        }
        *(s32 *)((s8 *)this + 0xC0) = var_r0;
    } else {
        *(s32 *)((s8 *)this + 0xC0) = 0;
    }
}

TObjAreaWarpForest::~TObjAreaWarpForest() {}

void TObjAreaWarpForest::run_task() {
    u8 *arg0 = (u8 *)this;
  this->m_c4 += 4.0f;
  if (((f32) ((*((s32 *) (((s8 *) (*((u8 **) (((s8 *) arg0) + 0xD4)))) + 4))) - (1 & 0xFFu))) < (this->m_c4))
  {
    this->m_c4 = 0.0f;
  }
  *((s32 *) (((s8 *) arg0) + 0xC8)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0xC8))) + 0x150);
  ((TObjAreaWarp *)arg0)->handle_area_selection();
}

void TObjAreaWarpForest::confirm_area_transfer(void *player) { TObjAreaWarp::confirm_area_transfer(player); }

void TObjAreaWarpForest::render() {
    Obj_8019C604 *self = (Obj_8019C604 *)this;
    Node_8019C604 *m;
    Node_8019C604 *n;
    if (((VObj_8019C604 *)self)->m8(400.0f, 20.0f) != 0) {
        Colors_8019C604 cols = {3, 2};
        n = self->fD4->next2C;
        while (n != NULL) {
            if (n->f4 != 0) {
                ((TObjDoorJung *)(n->f4))->free_children((void *)cols.c[this->set_params[2]]);
            }
            n = n->next2C;
        }
        m = self->fD0;
        TObjFish::set_global_param(self->fDC);
        push_matrix();
        ((void (*)(void *))post_translate_matrix)(self->f38);
        ((void (*)(int, int))rotate_matrix_y)(0, this->rotation_y);
        push_matrix();
        ((void (*)(void *))post_translate_matrix)(m->f8);
        draw_ginja_model((s32)m->f4);
        TParticleCtrl::begin_effect_render();
        m = m->next2C;
        while (m != NULL) {
            push_matrix();
            ((void (*)(void *))post_translate_matrix)(m->f8);
            rotate_matrix_zyx(0, (m->f14), (m->f18), (m->f1C));
            rotate_matrix_x(0, self->fCC);
            draw_ginja_model((s32)m->f4);
            ((void (*)(void))pop_matrix)();
            m = m->next30;
        }
        TParticleCtrl::end_effect_render();
        ((void (*)(void))pop_matrix)();
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion((s32)self->fD4, (s32)self->fD8, this->m_c4);
        TParticleCtrl::end_effect_render();
        ((void (*)(void))pop_matrix)();
    }
}

void TObjAreaWarpForest::debug_print_area_num() {
    this->TObjAreaWarp::debug_print_area_num();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    if (((Obj_8019C53C *)this)->f8C < 0) {
        ((Obj_8019C53C *)this)->f8C = 0;
    }
    ((Obj_8019C53C *)this)->f8C = ((Obj_8019C53C *)this)->f8C % 2;
    if (((Obj_8019C53C *)this)->f8C == 0) {
        TObjNpcEnemy::set_global_count(0xFFFFFF);
        debug_printf_at(0x130022, "<- COLOR : BLUE");
    } else {
        TObjNpcEnemy::set_global_count(0xFF0000FF);
        debug_printf_at(0x130022, "<- COLOR : RED");
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

const char *TObjAreaWarpQuest__name = "TObjAreaWarpQuest";

TObjAreaWarpQuest::TObjAreaWarpQuest(TObject *parent, void *set_data) : TObjAreaWarp(parent, set_data) {
    s32 temp_r3;
    s32 var_r0;
    u32 temp_r0;
    u32 temp_r4;
    m_name = TObjAreaWarpQuest__name;
    beam_frame = 0.0f;
    *(s32 *)((s8 *)this + 0xCC) = 0;
    temp_r0 = *(u32 *)((s8 *)this + 0x8C);
    temp_r4 = temp_r0 >> 0x1FU;
    *(u32 *)((s8 *)this + 0x8C) = (u32) (((temp_r0 & 1) ^ temp_r4) - temp_r4);
    *(s32 *)((s8 *)this + 0xC4) = (s32) *(f32 *)((s8 *)this + 0x68);
    warp_model = get_forest_warp_model(0);
    beam_model = get_forest_warp_model(1);
    beam_motion = get_forest_warp_motion(0);
    textures = get_forest_warp_textures();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        temp_r3 = (int)::operator new(0x88);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = init__13TAdVIConfigGCFf(temp_r3, &position, 20.0f);
        }
        *(s32 *)((s8 *)this + 0xC0) = var_r0;
    } else {
        *(s32 *)((s8 *)this + 0xC0) = 0;
    }
}

TObjAreaWarpQuest::~TObjAreaWarpQuest() {}

void TObjAreaWarpQuest::run_task() {
    u8 *arg0 = (u8 *)this;
  *((f32 *) (((s8 *) arg0) + 0xC8)) += 4.0f;
  if (((f32) ((unsigned long) ((*((s32 *) (((s8 *) (*((u8 **) (((s8 *) arg0) + 0xD8)))) + 4))) - 1))) < (*((f32 *) (((s8 *) arg0) + 0xC8))))
  {
    *((f32 *) (((s8 *) arg0) + 0xC8)) = 0.0f;
  }
  *((s32 *) (((s8 *) arg0) + 0xCC)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0xCC))) + 0x150);
  ((TObjAreaWarp *)arg0)->handle_area_selection();
}

void TObjAreaWarpQuest::render() {
    Obj_8019C250 *self = (Obj_8019C250 *)this;
    Node_8019C250 *m;
    Node_8019C250 *n;
    if (((VObj_8019C250 *)self)->m8(400.0f, 20.0f) != 0) {
        Colors_8019C250 cols = {3, 2};
        n = self->fD4->next2C;
        while (n != NULL) {
            if (n->f4 != 0) {
                ((TObjDoorJung *)(n->f4))->free_children((void *)cols.c[self->f8C]);
            }
            n = n->next2C;
        }
        m = self->fD0;
        TObjFish::set_global_param(self->fDC);
        push_matrix();
        ((void (*)(void *))post_translate_matrix)(self->f38);
        ((void (*)(int, int))rotate_matrix_y)(0, self->f60);
        push_matrix();
        ((void (*)(void *))post_translate_matrix)(m->f8);
        draw_ginja_model((s32)m->f4);
        TParticleCtrl::begin_effect_render();
        m = m->next2C;
        while (m != NULL) {
            push_matrix();
            ((void (*)(void *))post_translate_matrix)(m->f8);
            rotate_matrix_zyx(0, (m->f14), (m->f18), (m->f1C));
            rotate_matrix_x(0, self->fCC);
            draw_ginja_model((s32)m->f4);
            ((void (*)(void))pop_matrix)();
            m = m->next30;
        }
        TParticleCtrl::end_effect_render();
        ((void (*)(void))pop_matrix)();
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion((s32)self->fD4, (s32)self->fD8, self->fC8);
        TParticleCtrl::end_effect_render();
        ((void (*)(void))pop_matrix)();
    }
}

void TObjAreaWarpQuest::debug_print_area_num() {
    this->TObjAreaWarp::debug_print_area_num();
    if (((Obj_8019C144 *)this)->f68 < 0.0f) {
        ((Obj_8019C144 *)this)->f68 = 0.0f;
    }
    ((Obj_8019C144 *)this)->fC4 = (s32)((Obj_8019C144 *)this)->f68;
    if (((Obj_8019C144 *)this)->f8C < 0) {
        ((Obj_8019C144 *)this)->f8C = 0;
    }
    ((Obj_8019C144 *)this)->f8C = ((Obj_8019C144 *)this)->f8C % 2;
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x13001C, "<- PLAYER SET ID : %d", ((Obj_8019C144 *)this)->fC4);
    if (((Obj_8019C144 *)this)->f8C == 0) {
        TObjNpcEnemy::set_global_count(0xFFFFFF);
        debug_printf_at(0x130022, "<- COLOR : BLUE");
    } else {
        TObjNpcEnemy::set_global_count(0xFF0000FF);
        debug_printf_at(0x130022, "<- COLOR : RED");
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TObjAreaWarpQuest::confirm_area_transfer(void *player) {
    s32 i;
    void *p;
    set_area__6TLobbyFl(((u8 *)&lbl_80515BA0), dest_floor, get_floor_map_terrain(dest_floor));
    mark_area_change_pending();
    if (player != 0 && player_set_id > 1) {
        TObjAreaWarpQuest__sub_8019DCD8(player, player_set_id);
    }
    if (player_set_id > 1) {
        for (i = 0; i < 4; i++) {
            p = get_player_by_client_id(i);
            if (p != 0 && ((TObjChara *)p)->obj_isState3_324() != 0 && (u16)((TNpcPlayer *)p)->get_action_flags() != 0xFFFF) {
                TObjAreaWarpQuest__sub_8019DCD8(p, player_set_id);
            }
        }
    }
    ((TObjAreaWarpQuest *)((u8 *)&lbl_80515BA0))->get_dest_area();
    send_inter_level_warp_all__10TNpcPlayerFl();
    send_6x21_inter_level_warp(player, (s32)(((TObjAreaWarpQuest *)((u8 *)&lbl_80515BA0))->get_dest_area()));
}

const char *TObjAreaWarpEnding__name = "TObjAreaWarpEnding";

TObjAreaWarpEnding::TObjAreaWarpEnding(TObject *parent, void *set_data) : TObjAreaWarp(parent, set_data) {
    s32 temp_r3;
    s32 var_r0;
    u32 temp_r0;
    u32 temp_r4;
    m_name = TObjAreaWarpEnding__name;
    m_c4 = 0.0f;
    *(s32 *)((s8 *)this + 0xC8) = 0;
    temp_r0 = set_params[2];
    temp_r4 = temp_r0 >> 0x1FU;
    set_params[2] = (u32) (((temp_r0 & 1) ^ temp_r4) - temp_r4);
    warp_model = get_forest_warp_model(0);
    beam_model = get_forest_warp_model(1);
    beam_motion = get_forest_warp_motion(0);
    textures = get_forest_warp_textures();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        temp_r3 = (int)::operator new(0x88);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = init__13TAdVIConfigGCFf(temp_r3, &position, 20.0f);
        }
        *(s32 *)((s8 *)this + 0xC0) = var_r0;
    } else {
        *(s32 *)((s8 *)this + 0xC0) = 0;
    }
}

TObjAreaWarpEnding::~TObjAreaWarpEnding() {}

void TObjAreaWarpEnding::run_task() {
    u8 *arg0 = (u8 *)this;
  unsigned int new_var;
  this->m_c4 += 4.0f;
  new_var = *((s32 *) (((s8 *) (*((u8 **) (((s8 *) arg0) + 0xD4)))) + 4));
  if ((new_var - 1) < (this->m_c4))
  {
    this->m_c4 = 0.0f;
  }
  *((s32 *) (((s8 *) arg0) + 0xC8)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0xC8))) + 0x150);
  ((TObjAreaWarp *)arg0)->handle_area_selection();
}

void TObjAreaWarpEnding::render() {
    Obj_8019BD84 *self = (Obj_8019BD84 *)this;
    Warp_8019BD84 *arg0 = (Warp_8019BD84 *)self;
    Node_8019BD84 *root;
    Node_8019BD84 *node;
    if (self->is_visible(400.0f, 20.0f) == 0) {
        return;
    }
    Ids_8019BD84 ids = {3, 2};
    for (node = arg0->fD0->child; node != 0; node = node->child) {
        if (node->model != 0) {
            ((TObjDoorJung *)(node->model))->free_children((void *)ids.id[arg0->f8C]);
        }
    }
    root = arg0->fCC;
    TObjFish::set_global_param(arg0->fD8);
    push_matrix();
    ((void (*)(void *))post_translate_matrix)(arg0->pos);
    ((void (*)(int, int))rotate_matrix_y)(0, arg0->f60);
    push_matrix();
    ((void (*)(void *))post_translate_matrix)(root->pos);
    draw_ginja_model((s32)root->model);
    TParticleCtrl::begin_effect_render();
    for (root = root->child; root != 0; root = root->sibling) {
        push_matrix();
        ((void (*)(void *))post_translate_matrix)(root->pos);
        rotate_matrix_zyx(0, root->ang[0], root->ang[1], root->ang[2]);
        rotate_matrix_x(0, arg0->fC8);
        draw_ginja_model((s32)root->model);
        ((void (*)(void))pop_matrix)();
    }
    TParticleCtrl::end_effect_render();
    ((void (*)(void))pop_matrix)();
    TParticleCtrl::begin_effect_render();
    draw_ginja_model_with_motion((s32)arg0->fD0, arg0->fD4, arg0->fC4);
    TParticleCtrl::end_effect_render();
    ((void (*)(void))pop_matrix)();
}

void TObjAreaWarpEnding::debug_print_area_num() {
    this->TObjAreaWarp::debug_print_area_num();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    if (((Obj_8019BCBC *)this)->f8C < 0) {
        ((Obj_8019BCBC *)this)->f8C = 0;
    }
    ((Obj_8019BCBC *)this)->f8C = ((Obj_8019BCBC *)this)->f8C % 2;
    if (((Obj_8019BCBC *)this)->f8C == 0) {
        TObjNpcEnemy::set_global_count(0xFFFFFF);
        debug_printf_at(0x130022, "<- COLOR : BLUE");
    } else {
        TObjNpcEnemy::set_global_count(0xFF0000FF);
        debug_printf_at(0x130022, "<- COLOR : RED");
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TObjAreaWarpEnding::open_confirm_window(s32 client_id) {
    if ((u32) this->menu_window == 0U) {
        this->menu_window = create_window_menu(get_window_layout_position(0x33), 1, client_id);
        if (get_main_phase() == 0xE) {
            ((TWindowSubTradeMain *)(this->menu_window))->add_text_entry(get_localized_text_entry(9, 0x26), 3, 0, -1);
        } else {
            ((TWindowSubTradeMain *)(this->menu_window))->add_text_entry(get_localized_text_entry(9, 0x23), 2, 0, -1);
        }
        ((TWindowSubComCard *)(this->menu_window))->calc_window_size();
        align_menu_entry_positions(this->menu_window);
        ((TWindowSubComCardList *)(this->menu_window))->set_flag70_bit10();
        ((TAdChrSelASlotGC *)(this->menu_window))->set_flag_40();
        user_client_id = client_id;
    }
}

void TObjAreaWarpEnding::confirm_area_transfer(void *) {
    play_sound_effect(0x40003205, 0, 0, 0);
    u32 obj = ((u32 (*)(s32))__nw__7TObjectFUl)(0x28);
    if (obj != 0U) {
        ((THunterGuildSeqOffline *)obj)->init((void *)tl_00, (void *)((s32 *)TKeyBoardControl::dispatch_select_phase));
    }
}

void TKeyBoardControl::dispatch_select_phase() {

    switch (TAdStorySelectGC::get_story_select()) {
    case 0:
        if (should_record_episode1_quest_completion() != 0) {
            TBoss4DarkFalz::dispatch_by_main_phase(0x3FE);
            TKeyBoardControl__sub_8000F9CC(0xC);
        } else {
            TKeyBoardControl__sub_8000F9CC(0x10);
        }
        break;
    case 1:
        TKeyBoardControl__sub_8000F9CC(8);
        break;
    }
    init__23TAdSinglePlyChrSelectGCFv();
}

const char *TObjMapForceWarp__name = "TObjMapForceWarp";

TObjMapForceWarp::TObjMapForceWarp(TObject *parent, void *set_data) : TObjMapWarp(parent, set_data) {
    m_name = TObjMapForceWarp__name;
    if ((s32) set_params[2] > 0) {
        display_number = 0;
    } else {
        display_number = 1;
    }
    if (field_collider != NULL) {
        ((TObject *)field_collider)->disallow_rendering();
        ((TObject *)field_collider)->suspend_update();
    }
}

TObjMapForceWarp::~TObjMapForceWarp() {}

void TObjMapForceWarp::run_task() { process_player_warps(); }

void TObjMapForceWarp::render() {  }

void TObjMapForceWarp::draw_debug_destinations() {
    TObjMapWarp::draw_debug_destinations();
    if ((s32)set_params[2] > 0) {
        display_number = 0;
    } else {
        display_number = 1;
    }
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130021, "<- FLOOR NUMBER");
    if (display_number != 0) {
        debug_printf_at(0x130022, "<- DISP NUMBER");
    } else {
        debug_printf_at(0x130022, "<- NO DISP NUMBER");
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

s32 TObjMapForceWarp::vfunc_18(s32 client_id) {
    if (display_number != 0) {
        create_warp_id_string(client_id);
    }
    return 1;
}

void TObjMapForceWarp::create_warp_id_string(u16 client_id) {
    char buf[32];
    char *p;
    sprintf(buf, "%xF", ((Obj_8019B8D8 *)this)->id);
    for (p = buf; *p != 0; p++) {
        *p = TLobby__sub_80070AD8(*p);
    }
    create_TObjWarpString(buf, client_id);
}

const char *TObjWarpString__name = "TObjWarpString";

u8 *__ct__14TObjWarpStringFv(u8 *object, u8 *arg1, s32 arg2, s16 arg3) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__14TObjWarpString.value;
    *(s32 *)((s8 *)object + 0) = (s32)TObjWarpString__name;
    strncpy((s32)(object + 0x1C), arg2, 0x20);
    *(s8 *)((s8 *)object + 0x3B) = 0;
    *(s16 *)((s8 *)object + 0x48) = arg3;
    *(s32 *)((s8 *)object + 0x3C) = -1;
    *(f32 *)((s8 *)object + 0x44) = 0.0f;
    *(s32 *)((s8 *)object + 0x40) = 0x18;
    *(s32 *)((s8 *)object + 0x4C) = 0;
    return object;
}

TObjWarpString::~TObjWarpString() {}

void TObjWarpString::run_task() {

    switch (*(s32 *)((s8 *)this + 0x4C)) {
    case 0:
        ((s32 (*)(void))sub_8019B77C__14TObjWarpStringFv)();
        return;
    case 1:
        ((s32 (*)(void))update_fade_in__14TObjWarpStringFPv)();
        return;
    case 2:
        TObjWarpString__sub_8019B728(this);
        return;
    case 3:
        ((s32 (*)(void))fade_and_destroy__14TObjWarpStringFPv)();
        return;
    }
}

void TObjWarpString::sub_8019B77C() {
    s32 temp_r0;

    temp_r0 = *(s32 *)((s8 *)this + 0x40) - 1;
    *(s32 *)((s8 *)this + 0x40) = temp_r0;
    if (temp_r0 < 0) {
        *(s32 *)((s8 *)this + 0x4C) = 1;
    }
}

#pragma push
#pragma opt_common_subs off
void update_fade_in__14TObjWarpStringFPv(u8 *arg0) {
    *(f32 *)((s8 *)arg0 + 0x44) += 10.0f;
    if (*(f32 *)((s8 *)arg0 + 0x44) > 255.0f) {
        *(f32 *)((s8 *)arg0 + 0x44) = 255.0f;
        *(s32 *)((s8 *)arg0 + 0x4C) = 2;
        *(s32 *)((s8 *)arg0 + 0x40) = 0x5A;
    }
}
#pragma pop

void TObjWarpString__sub_8019B728(void *arg0) {
    s32 temp_r0;

    temp_r0 = *(s32 *)((s8 *)arg0 + 0x40) - 1;
    *(s32 *)((s8 *)arg0 + 0x40) = temp_r0;
    if (temp_r0 < 0) {
        *(s32 *)((s8 *)arg0 + 0x4C) = 3;
    }
}

void fade_and_destroy__14TObjWarpStringFPv(u8 *object) {
  *((f32 *) (((s8 *) object) + 0x44)) = (f32) ((*((f32 *) (((s8 *) object) + 0x44))) - 10.0f);
  if ((*((f32 *) (((s8 *) object) + 0x44))) < 0.0f)
  {
    *((f32 *) (((s8 *) object) + 0x44)) = 0.0f;
    ((TObject *)object)->queue_destruction();
  }
}

#pragma push
#pragma opt_common_subs off

void TObjWarpString::render() {
    f32 xr;
    f32 y;
    f32 yt;
    f32 yb;
    WarpStringPos pos;
    u32 color;
    u32 width;

    pos.packed = fn_8019B480(this, (void *)*(u16 *)((s8 *)this + 0x48));
    width = calc_text_width((char *)this + 0x1C) >> 1;
    pos.xy.x -= (f32)width;
    y = pos.xy.y;
    color = (u8)*(f32 *)((s8 *)this + 0x44) << 24;
    draw_menu_text(pos.xy.x - 2.0f, yt = y - 2.0f, (char *)this + 0x1C, color);
    draw_menu_text(pos.xy.x, yt, (char *)this + 0x1C, color);
    draw_menu_text(xr = 2.0f + pos.xy.x, yt, (char *)this + 0x1C, color);
    draw_menu_text(pos.xy.x - 2.0f, y, (char *)this + 0x1C, color);
    draw_menu_text(xr, y, (char *)this + 0x1C, color);
    draw_menu_text(pos.xy.x - 2.0f, yb = 2.0f + y, (char *)this + 0x1C, color);
    draw_menu_text(pos.xy.x, yb, (char *)this + 0x1C, color);
    draw_menu_text(xr, yb, (char *)this + 0x1C, color);
    color = ((u8)*(f32 *)((s8 *)this + 0x44) << 24) | 0xFFFFFF;
    TParticleCtrl::begin_effect_render();
    draw_menu_text(pos.xy.x, y, (char *)this + 0x1C, color);
    TParticleCtrl::end_effect_render();
}
#pragma pop

s64 fn_8019B480(void *arg0, void *camera_ctrl) {
    WarpStringScreenPos *p = warp_string_screen_position_table;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        switch (TCameraCtrl::get_camera_id()) {
        case 2:
            p = warp_string_screen_position_table + 1;
            break;
        case 3:
            p = warp_string_screen_position_table + 3;
            break;
        case 4:
            p = warp_string_screen_position_table + 6;
            break;
        }
        p += get_split_screen_view_index__11TCameraCtrlFUs(camera_ctrl);
    }
    return *(s64 *)p;
}

void *create_TObjWarpString(char *text, u16 client_id) {
    void *o;
    o = __nw__7TObjectFUl(0x50);
    if (o != NULL) {
        o = ((void * (*)(void *, void *, char *, u16))__ct__14TObjWarpStringFv)(o, tl_clipout, text, client_id);
    }
    return o;
}

extern "C" {

const char *TObjAreaWarpEndingJung__name = "TObjAreaWarpEndingJung";

TObjAreaWarpEndingJung::TObjAreaWarpEndingJung(TObject *parent, void *set_data) : TObjAreaWarpEnding(parent, set_data) {
    s32 temp_r0;
    u32 temp_r4;

    m_name = TObjAreaWarpEndingJung__name;
    if ((s32) set_params[2] < 0) {
        set_params[2] = 0;
    }
    temp_r0 = set_params[2];
    temp_r4 = (u32) temp_r0 >> 0x1FU;
    set_params[2] = (s32) (((temp_r0 & 1) ^ temp_r4) - temp_r4);
}

TObjAreaWarpEndingJung::~TObjAreaWarpEndingJung() {}

void TObjAreaWarpEndingJung::run_task() {
    f32 temp_f1;

    temp_f1 = this->m_c4;
    this->m_c4 += 4.0f;
    if (this->m_c4 > (get_static_field4_as_float__12TObjWarpJungFv(temp_f1) - 1.0f)) {
        this->m_c4 = 0.0f;
    }
    handle_area_selection();
}

void TObjAreaWarpEndingJung::render() {
    u8 *arg0 = (u8 *)this;

    if (((VObj_8019B124*)arg0)->m8(400.0f, 20.0f) != 0) {
        if (TObjWarpJung::update_warp_display() != 0) {
            PPCSync();
        }
        switch (this->set_params[2]) {
        case 0:
            TObjWarpJung__sub_801A0404(0);
            break;
        case 1:
            TObjWarpJung__sub_801A0404(1);
            break;
        }
        TObjWarpJung::set_global_render_param();
        ((s32 (*)(void))push_matrix)();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjWarpJung::render_warp(0);
        TParticleCtrl::begin_effect_render();
        TObjWarpJung::render_warp_effect(1, (s32) this->m_c4);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TObjAreaWarpEndingJung::debug_print_area_num() {
    TObjNpcEnemy::set_global_count(0xFF00FF);
    if (((Warp_8019B170 *)this)->f8C < 0) {
        ((Warp_8019B170 *)this)->f8C = 0;
    }
    ((Warp_8019B170 *)this)->f8C = ((Warp_8019B170 *)this)->f8C % 2;
    if (((Warp_8019B170 *)this)->f8C == 0) {
        TObjNpcEnemy::set_global_count(0xFFFFFF);
        debug_printf_at(0x130022, "<- COLOR : RED");
    } else {
        TObjNpcEnemy::set_global_count(0xFF0000FF);
        debug_printf_at(0x130022, "<- COLOR : BLUE");
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void *TObjAreaWarpEndingJung__create(void *arg0) {
    return new TObjAreaWarpEndingJung(tl_05, arg0);
}

}
