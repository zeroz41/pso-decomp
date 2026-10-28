#include "types.h"
#include "pso/system/vector.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/object/TObjDoorJung.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdVIConfigGC.h"
#include "pso/TObject.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/TObjWarpString.h"
#include "pso/object/TObjMapWarpForest.h"
#include "pso/misc/TKeyBoardControl.h"
#include "pso/object/TObjAreaWarp.h"
#include "pso/object/TObjAreaWarpEnding.h"
#include "pso/object/TObjAreaWarpEndingJung.h"
#include "pso/object/TObjAreaWarpForest.h"
#include "pso/object/TObjAreaWarpQuest.h"
#include "pso/object/TObjMapForceWarp.h"
#include "pso/object/TObjMapWarp.h"
#include "pso/TAdStorySelectGC.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNpcPlayer.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/misc/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/MenuText.h"
#include "pso/object/TObjCityMainWarp.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjLuker.h"
#include "pso/object/TObjWarpJung.h"
#include "pso/ui/TAdChrSelASlotGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/object/TObjWarpBase.h"
#include "pso/misc/TTecLuker.h"
#include "pso/object/TObjMotion.h"

// The original TU was built with deferred codegen: functions below are in reverse
// address order, and the pool (three {3, 2} initializers, then the float literals
// and "%xF" in first-use order) comes out exactly as in the original .sdata2.
#pragma defer_codegen on
#pragma readonly_strings on

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

struct Obj_8019B978 {
    u8 pad0[0x8C];
    s32 f8c;
    u8 pad90[0xFC - 0x90];
    s32 ffc;
};

struct RecoveredGlobal_8019C828___vt__18TObjAreaWarpForest { s32 value; u8 remaining[0x50]; };

typedef char RecoveredGlobal_8019C828___vt__18TObjAreaWarpForest_size[sizeof(RecoveredGlobal_8019C828___vt__18TObjAreaWarpForest) == 0x54 ? 1 : -1];

struct RecoveredGlobal_8019BF88___vt__18TObjAreaWarpEnding { s32 value; u8 remaining[0x50]; };

typedef char RecoveredGlobal_8019BF88___vt__18TObjAreaWarpEnding_size[sizeof(RecoveredGlobal_8019BF88___vt__18TObjAreaWarpEnding) == 0x54 ? 1 : -1];

struct RecoveredGlobal_8019C454___vt__17TObjAreaWarpQuest { s32 value; u8 remaining[0x50]; };

typedef char RecoveredGlobal_8019C454___vt__17TObjAreaWarpQuest_size[sizeof(RecoveredGlobal_8019C454___vt__17TObjAreaWarpQuest) == 0x54 ? 1 : -1];

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

struct Warp_8019C05C { u8 pad0[0xBC]; s32 fBC; u8 padC0[4]; s32 fC4; };

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

struct RecoveredGlobal_8019D030___vt__17TObjMapWarpForest { s32 value; u8 remaining[0x50]; };

typedef char RecoveredGlobal_8019D030___vt__17TObjMapWarpForest_size[sizeof(RecoveredGlobal_8019D030___vt__17TObjMapWarpForest) == 0x54 ? 1 : -1];

struct RecoveredGlobal_8019CA24_lbl_80515BA0 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_8019CE40___vt__12TObjAreaWarp {
    s32 value;
    u8 remaining[0x50];
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

typedef char RecoveredGlobal_8019CE40___vt__12TObjAreaWarp_size[sizeof(RecoveredGlobal_8019CE40___vt__12TObjAreaWarp) == 0x54 ? 1 : -1];

struct VObj_8019D250;
extern "C" {

s32 get_main_phase();
void mark_area_change_pending();
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
s32 obj_isState3_324__13TUnk_804806E8Fv(void *);
u16 get_entity_id(void *);
s32 is_split_screen();
s32 get_current_floor();
void queue_destruction__7TObjectFv(void *);
void allow_rendering__7TObjectFv(TObject *);
void disallow_rendering__7TObjectFv(TObject *arg0);
s32 get_split_screen_view_index__11TCameraCtrlFUs(void *);
u32 TLobby__sub_80070AD8(s32 arg0);
s32 get_floor_destination_name();
s32 get_localized_text_entry(s32, s32);
s32 TObjMapWarp__sub_80141CB0(void *, void *, u32, u32);
s32 TObjMapWarp__sub_80141CB4(void *, f32);
s32 test_player_body_overlap_at(void *, void *, Vec_8019D250 *);
s32 TObjCityMainWarp__sub_80186AF4();
void * TObjAreaWarpEndingJung__create(void *arg0);
void * __dt__22TObjAreaWarpEndingJungFv(void *arg0, s16 arg1);
void * TObjAreaWarpEndingJung__ct(void *arg0, void *parent, void *set);
s64 fn_8019B480(void *arg0, void *arg1);
void fade_and_destroy__14TObjWarpStringFPv(u8 *arg0);
void TObjWarpString__sub_8019B728(void *arg0);
void update_fade_in__14TObjWarpStringFPv(u8 *arg0);
void sub_8019B77C__14TObjWarpStringFv(void *arg0);
u8 * __ct__14TObjWarpStringFv(u8 *arg0, u8 *arg1, s32 arg2, s16 arg3);
s32 TObjMapForceWarp__vt16(TObjMapForceWarp *arg0, u16 arg1);
void TObjMapForceWarp__vt17(Obj_8019B978 *arg0);
void * __dt__16TObjMapForceWarpFv(void *arg0, s16 arg1);
void * TObjMapForceWarp__ct(void *arg0, void *parent, void *set);
void * __dt__18TObjAreaWarpEndingFv(void *arg0, s16 arg1);
u8 * TObjAreaWarpEnding__ct(u8 *arg0, s32 arg1, s32 arg2);
void TObjAreaWarpQuest__vt17(Warp_8019C05C *arg0, void *arg1);
void * __dt__17TObjAreaWarpQuestFv(void *arg0, s16 arg1);
u8 * TObjAreaWarpQuest__ct(u8 *arg0, s32 arg1, s32 arg2);
void * __dt__18TObjAreaWarpForestFv(void *arg0, s16 arg1);
u8 * TObjAreaWarpForest__ct(u8 *arg0, s32 arg1, s32 arg2);
void handle_6x94_inter_level_warp(Pkt_8019C988 *arg0);
void confirm_area_transfer__12TObjAreaWarpFPvi(u8 *arg0, s32 arg1);
u8 * __dt__12TObjAreaWarpFv(u8 *arg0, s16 arg1);
void * TObjAreaWarp__ct(void *arg0, void *parent, void *set);
u8 * TObjMapWarpForest__ct(u8 *arg0, void *parent, void *set);
s32 can_warp__11TObjMapWarpFlUs(void *, u16);
void *__dt__11TObjMapWarpFv(void *arg0, s16 arg1);
s32 vfunc_16__12TObjWarpBaseFv(s32);
void *find_warp_player_in_range(void *self, u16 client_id, f32 range);
void *__dt__12TObjWarpBaseFv(void *arg0, s16 arg1);
int TAdStorySelectGC__sub_8019DC14(void);
s32 register_area_warp_object__16TAdStorySelectGCFPv(int);
s32 register_warp__16TObjMapForceWarpFPv(int);
void TObjAreaWarpQuest__sub_8019DCD8(void *, s32);
f32 get_static_field4_as_float__12TObjWarpJungFv(f32);
s32 TObjWarpJung__sub_801A0404(s32);
int check_flag_100__10TObjPlayerFPv(void *p);
void * get_player_by_client_id(s32);
void send_6x21_inter_level_warp(void *obj, s32 value);
void send_6x55_intra_map_warp(u16 id, void *pos, s32 c);
s32 init__23TAdSinglePlyChrSelectGCFv();
s32 get_floor_map_terrain(s32);
s32 play_sound_effect(s32, s32, s32, s32);
void set_area__6TLobbyFl(void *, int, int);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);
void __ct__7TObjectFP7TObject(void *, void *);
void TWindow__close(void *);
s32 align_menu_entry_positions(u32);
u32 create_window_menu(s32, s32, s16);
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
s32 rotate_matrix_y(s32, s32);
void rotate_matrix_x(int, s32);
s32 push_matrix_from(void *);
void push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_ginja_object(void *child);
void draw_ginja_model(s32 model);
void draw_ginja_model_with_motion(s32, s32, f32);

extern s32 __vt__12TObjAreaWarp[];
extern RecoveredGlobal_8019B854___vt__14TObjWarpString __vt__14TObjWarpString;
extern s32 __vt__16TObjMapForceWarp[];
extern s32 __vt__17TObjAreaWarpQuest[];
extern RecoveredGlobal_8019D030___vt__17TObjMapWarpForest __vt__17TObjMapWarpForest;
extern s32 __vt__18TObjAreaWarpEnding[];
extern s32 __vt__18TObjAreaWarpForest[];
extern s32 __vt__22TObjAreaWarpEndingJung[];
extern Vec_8019D0A8 lbl_804462FC;
extern char lbl_804463A4[];
extern char lbl_804463B4[];
extern char lbl_804463D0[];
extern char lbl_804463E0[];
extern char lbl_804463F0[];
extern char lbl_80446404[];
extern char lbl_8044641C[];
extern char lbl_80446430[];
extern char lbl_80446440[];
extern char lbl_80446450[];
extern char lbl_80446460[];
extern Vec_8019D0A8 map_warp_destination_offsets[];
extern s64 warp_string_screen_position_table[];
extern RecoveredGlobal_8019CA24_lbl_80515BA0 lbl_80515BA0;
extern u8 identity_matrix[];
extern s32 TObjMapWarpForest__name;
extern s32 TObjAreaWarp__name;
extern s32 TObjAreaWarpForest__name;
extern s32 TObjAreaWarpQuest__name;
extern s32 TObjAreaWarpEnding__name;
extern s32 TObjMapForceWarp__name;
extern s32 TObjWarpString__name;
extern s32 TObjAreaWarpEndingJung__name;
extern s32 local_client_id;
extern s32 lobby_quest_progress_flag;
extern s32 tl_00;
extern void *tl_05;
extern void *tl_clipout;
}

void * create_TObjWarpString(void *arg0, void *arg1);
void bswap_6x94_inter_level_warp(void *);
void mask_action_buttons(void *p, u32 v);
s32 should_record_episode1_quest_completion();union WarpStringPos {
    s64 packed;
    struct {
        f32 x;
        f32 y;
    } xy;
};

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

struct RecoveredGlobal_8019D850_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_8019D818_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct V3_8019D764 { f32 x, y, z; };

struct W_8019D764 {
    s32 type;
    u8 pad04[0x14];
    s32 *vt;
    u8 pad1c[0x60 - 0x1C];
    s32 sourceYaw;
    u8 pad64[4];
    f32 destination[3];
    u8 pad74[0xBC - 0x74];
    V3_8019D764 destinations[4];
    void *playerPopups[4];
};
extern "C" {

u8 TWindowShortListCtrl__check_controller_button(void *, int);
extern RecoveredGlobal_8019D850_lbl_8050E208 controller_input_state;
void fn_8019DD24(void *p, u32 v);
extern s32 __vt__11TObjMapWarp[];
extern s32 TObjMapWarp__name;
struct Base_8019D6F8_8019D4E4 { char pad[0x18]; };
struct VObj_8019D6F8_8019D4E4 : Base_8019D6F8_8019D4E4 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13();
};

int is_flag_400_set__10TObjPlayerFPv(void *p);
s32 test_flag_2000000__10TObjPlayerFPv(void *);

extern s32 quest_warp_enabled;
extern s32 lbl_805D55C0;

typedef char RecoveredGlobal_8019D850_lbl_8050E208_size[sizeof(RecoveredGlobal_8019D850_lbl_8050E208) == 0x1B0 ? 1 : -1];

typedef char RecoveredGlobal_8019D818_lbl_8050E208_size[sizeof(RecoveredGlobal_8019D818_lbl_8050E208) == 0x1B0 ? 1 : -1];

extern char lbl_804462F0[];
s32 TObjMapWarp__name = (s32)lbl_804462F0;
}

struct Base_8019DAC0 { s32 f0; u8 pad4[0x14]; };

struct Warp_8019DAC0 : Base_8019DAC0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(void *set);
    u8 pad1c[0x90];
    f32 fac;
    s32 fb0;
    void *fb4;
    u16 fb8;
};
extern "C" {

f32 xz_distance_squared(void *, void *);
void __ct__13TUnk_804AF8A0FP7TObject(Warp_8019DAC0 *, void *, void *);
extern s32 __vt__12TObjWarpBase[];
extern s32 TObjWarpBase__name;
struct Base_8019DA54_8019D964 { char pad[0x18]; };
struct VObj_8019DA54_8019D964 : Base_8019DA54_8019D964 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13();
};

s32 TLobby__sub_8001FE7C(s32, s32);
s32 release_texture_list(void*);

extern s32 forest_warp_bml_resource;
extern u32 forest_warp_texture_list;
}

// Function definitions in reverse address order (defer_codegen emits them reversed).

extern "C" {

void TObjWarpBase::free_globals() {
    if ((u32) forest_warp_texture_list != 0U) {
        release_texture_list((void*)forest_warp_texture_list);
        TAdSinglePlyChrSelectGC::safe_free(forest_warp_texture_list);
        forest_warp_texture_list = 0U;
    }
    TLobby__sub_8001FE7C(forest_warp_bml_resource, 1);
    forest_warp_bml_resource = 0;
}

Warp_8019DAC0 *TObjWarpBase__ct(Warp_8019DAC0 *self, void *parent, void *set) {
    void *o;
    __ct__13TUnk_804AF8A0FP7TObject(self, parent, set);
    *(void **)((u8 *)self + 0x18) = ((u8 *)&__vt__12TObjWarpBase);
    self->f0 = TObjWarpBase__name;
    self->m5(set);
    self->fac = 10.0f;
    self->fb0 = 0;
    o = __nw__7TObjectFUl(0xB4);
    if (o != 0) {
        o = ((TTecLuker *)o)->construct_field_collider((s32)((u8 *)self + 0x38), (s32)self, 1);
    }
    self->fb4 = o;
    self->fb8 = 0xFFFF;
    return self;
}

void *__dt__12TObjWarpBaseFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        struct VObj_8019DA54_8019D964 *o = (struct VObj_8019DA54_8019D964 *)arg0;
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjWarpBase;
        o->m12();
        __dt__13TUnk_804AF8A0Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
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
        TWindow__close((u8 *)player);
        *(u32 *)((s8 *)this + 0xB0) = 0U;
        player = (u32)get_player_by_client_id(*(u16 *)((s8 *)this + 0xB8));
        if (player != 0U) {
            fn_8019DD24((void *)(player + 0x550), 4);
        }
        *(u16 *)((s8 *)this + 0xB8) = 0xFFFFU;
    }
}

u8 TObjWarpBase::vfunc_16() {
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
    if ((player != NULL) && (test_flag_2000000__10TObjPlayerFPv(player) != 0)) {
        return 0U;
    }
    return 1U;
}

void TObjWarpBase::vfunc_17() {
    TWindowShortListCtrl__check_controller_button((void *) ((u8 *)&controller_input_state.value + 0x20), 4);
}

void TObjWarpBase::vfunc_18(s32 arg1) {
    TWindowShortListCtrl__check_controller_button((void *) ((u8 *)&(*(RecoveredGlobal_8019D818_lbl_8050E208 *)&controller_input_state).value + (arg1 * 0x50) + 0x20), 4);
}

void *TObjMapWarp__ct(void *map_warp, void *parent, void *set) {
    s32 i;
    W_8019D764 *self = (W_8019D764 *)map_warp;
    TObjWarpBase__ct((Warp_8019DAC0 *)self, parent, set);
    self->vt = __vt__11TObjMapWarp;
    self->type = TObjMapWarp__name;
    for (i = 0; i < 4; i++) {
        push_matrix_from(identity_matrix);
        post_translate_matrix(self->destination);
        rotate_matrix_y(0, self->sourceYaw);
        matrix_mult_vec(0, &map_warp_destination_offsets[i], &self->destinations[i]);
        pop_matrix();
        self->playerPopups[i] = 0;
    }
    return self;
}

void *__dt__11TObjMapWarpFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        struct VObj_8019D6F8_8019D4E4 *o = (struct VObj_8019D6F8_8019D4E4 *)arg0;
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TObjMapWarp;
        o->m12();
        __dt__12TObjWarpBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
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
        TWindow__close((u8 *)temp_r3);
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
void TObjMapWarp::open_player_warp_window(s32 arg1) {
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
                    TWindow__close(d->win[i]);
                    d->win[i] = NULL;
                }
            } else {
                if (d->win[i] != NULL) {
                    ((TQuestVmDownLoadServer *)(d->win[i]))->clear_flag4_bit4();
                    allow_rendering__7TObjectFv((TObject *)d->win[i]);
                }
                t = find_warp_player_in_range(this, i, d->fAC);
                if (t != NULL) {
                    ((VObj_8019D250 *)this)->m13(get_entity_id(t));
                    if (((TObjPlayer *)t)->is_target_valid() != 0 && ((VObj_8019D250 *)this)->m16(((TRaderMapCore *)t)->get_map_id()) != 0) {
                        for (j = 0; j < 4; j++) {
                            if (test_player_body_overlap_at(this, t, &d->ends[j]) == 0) {
                                send_6x55_intra_map_warp(get_entity_id(t), &d->ends[j], this->m_84);
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
        if (this->m_b0 != NULL) {
            TWindow__close(this->m_b0);
            this->m_b0 = NULL;
        }
    } else {
        void *t2;
        s32 j2;
        if (this->m_b0 != NULL) {
            ((TQuestVmDownLoadServer *)(this->m_b0))->clear_flag4_bit4();
            allow_rendering__7TObjectFv((TObject *)this->m_b0);
        }
        t2 = find_warp_player_in_range(((VObj_8019D250 *)this), local_client_id, d->fAC);
        if (t2 != NULL) {
            ((VObj_8019D250 *)this)->m13(local_client_id);
            if (((TObjPlayer *)t2)->is_target_valid() != 0 && ((VObj_8019D250 *)this)->m16(((TRaderMapCore *)t2)->get_map_id()) != 0) {
                for (j2 = 0; j2 < 4; j2++) {
                    if (test_player_body_overlap_at(((VObj_8019D250 *)this), t2, &d->ends[j2]) == 0) {
                        send_6x55_intra_map_warp(get_entity_id(t2), &d->ends[j2], this->m_84);
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
    ((s32 (*)(s32, const char *, ...))debug_printf_at)(0x13001C, lbl_80446430);
    ((s32 (*)(s32, const char *, ...))debug_printf_at)(0x13001D, lbl_80446440);
    ((s32 (*)(s32, const char *, ...))debug_printf_at)(0x13001E, lbl_80446450);
    ((s32 (*)(s32, const char *, ...))debug_printf_at)(0x130020, lbl_80446460);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    for (i = 0; i < 4; i++) {
        Vec_8019D0A8 b;
        Vec_8019D0A8 a = lbl_804462FC;
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
        TObjMapWarp__sub_80141CB0(&b, &a, 0xFFFF0000, 0xFFFF0000);
        TObjMapWarp__sub_80141CB4(end, 15.0f);
    }
}

u8 *TObjMapWarpForest__ct(u8 *map_warp_forest, void *parent, void *set) {
    TObjMapWarp__ct(map_warp_forest, parent, set);
    *(s32 **)((s8 *)map_warp_forest + 0x18) = &__vt__17TObjMapWarpForest.value;
    *(s32 *)((s8 *)map_warp_forest + 0) = (s32) TObjMapWarpForest__name;
    *(s32 *)((s8 *)map_warp_forest + 0x100) = register_warp__16TObjMapForceWarpFPv(4);
    *(s32 *)((s8 *)map_warp_forest + 0x104) = register_warp__16TObjMapForceWarpFPv(5);
    *(s32 *)((s8 *)map_warp_forest + 0x108) = register_area_warp_object__16TAdStorySelectGCFPv(2);
    *(s32 *)((s8 *)map_warp_forest + 0x10C) = TAdStorySelectGC::get_story_select();
    ((TObjMapWarpForest *)map_warp_forest)->frame = (f32) 0.0f;
    return map_warp_forest;
}

void TObjMapWarpForest::run_task() {
    this->frame+=4.0f;
    if((f32)(u32)(this->motion->frameCount-1)<this->frame)this->frame=0.0f;
    process_player_warps();
}

void TObjMapWarpForest::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj8019CF38_8019CCF0 *) arg0)->m8(400.0f, 20.0f) != 0) {
        TObjFish::set_global_param(*(s32 *)&this->textures);
        ((s32 (*)(void))push_matrix)();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_ginja_object(this->baseModel);
        TParticleCtrl::begin_effect_render();
        ((s32 (*)(s32, s32, f32))draw_ginja_model_with_motion)(*(s32 *)&this->beamModel, *(s32 *)&this->motion, this->frame);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void *TObjAreaWarp__ct(void *area_warp, void *parent, void *set) {
    TObjWarpBase__ct((Warp_8019DAC0 *)area_warp, parent, set);
    *(s32 **)((s8 *)area_warp + 0x18) = __vt__12TObjAreaWarp;
    *(s32 *)((s8 *)area_warp + 0) = (s32) TObjAreaWarp__name;
    *(s32 *)((s8 *)area_warp + 0xBC) = (s32) ((TObjAreaWarp *)area_warp)->m_84;
    if ((s32) lobby_quest_progress_flag != 0) {
        *(s32 *)((s8 *)area_warp + 0xBC) = (s32) (get_current_floor() + 1);
    }
    *(s32 *)((s8 *)area_warp + 0xC0) = 0;
    return area_warp;
}

u8 *__dt__12TObjAreaWarpFv(u8 *area_warp, s16 arg1) {
    u8 *ad_vi_config_gc;
    if (area_warp != NULL) {
        *(s32 **)((s8 *)area_warp + 0x18) = &(*(RecoveredGlobal_8019CE40___vt__12TObjAreaWarp *)&__vt__12TObjAreaWarp).value;
        ad_vi_config_gc = (u8 *)(*(u8 **)((s8 *)area_warp + 0xC0));
        if (ad_vi_config_gc != NULL) {
            destroy__13TAdVIConfigGCFPvs(ad_vi_config_gc, 1);
            *(u8 **)((s8 *)area_warp + 0xC0) = NULL;
        }
        ((TObjAreaWarp *)(area_warp))->vfunc_14();
        __dt__12TObjWarpBaseFv(area_warp, 0);
        if (arg1 > 0) {
            ((s32 (*)(void *))__dl__7TObjectFPv)(area_warp);
        }
    }
    return area_warp;
}

void TObjAreaWarp::open_confirm_window(u16 arg1) {
    u32 temp_r3;

    if ((u32) *(u32 *)((s8 *)this + 0xB0) == 0U) {
        *(u32 *)((s8 *)this + 0xB0) = ((u32 (*)(s32, s32, u16))create_window_menu)(get_window_layout_position(0x33), 1, arg1);
        if (((s32 (*)(void))get_game_play_mode)() == 1) {
            ((TWindowSubTradeMain *)(*(u32 *)((s8 *)this + 0xB0)))->add_text_entry(TObjCityMainWarp__sub_80186AF4(), 2, 0, -1);
        } else {
            TLobby::get_player_floor(*(s32 *)((s8 *)this + 0xBC));
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

s32 TObjAreaWarp::is_warp_enabled(s32 arg0) {
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
    return vfunc_16__12TObjWarpBaseFv(arg0);
}

void TObjAreaWarp::handle_area_selection() {
    Data_8019CAB0 *d = (Data_8019CAB0 *)this;
    s32 found;
    s32 i;
    void *t;
    if (((VObj_8019CAB0 *)this)->m14() == 0) {
        if (d->fB0 != NULL) {
            TWindow__close(d->fB0);
            d->fB0 = NULL;
        }
    } else {
        if (d->fB0 != NULL) {
            ((TQuestVmDownLoadServer *)(d->fB0))->clear_flag4_bit4();
            allow_rendering__7TObjectFv((TObject *)d->fB0);
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
                        this->confirm_area_transfer((s32)t);
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
                    this->confirm_area_transfer((s32)t2);
                }
            } else {
                this->vfunc_14();
            }
        }
    }
}

void confirm_area_transfer__12TObjAreaWarpFPvi(u8 *arg0, s32 arg1) {
    ((s32 (*)(void *, int, int))set_area__6TLobbyFl)(&lbl_80515BA0.value, (int) (*(s32 *)((s8 *)arg0 + 0xBC)), (int) (get_floor_map_terrain(*(s32 *)((s8 *)arg0 + 0xBC))));
    ((s32 (*)(void))mark_area_change_pending)();
    ((TObjAreaWarpQuest *)(&lbl_80515BA0.value))->get_dest_area();
    ((s32 (*)(void))send_inter_level_warp_all__10TNpcPlayerFl)();
    send_6x21_inter_level_warp((void *)arg1, (((TObjAreaWarpQuest *)(&lbl_80515BA0.value))->get_dest_area()));
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
    debug_printf_at(0x130020, lbl_8044641C, self->saved_id);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

u8 *TObjAreaWarpForest__ct(u8 *area_warp_forest, s32 arg1, s32 arg2) {
    s32 temp_r3_2;
    s32 var_r0;
    u32 temp_r0;
    u32 temp_r3;
    TObjAreaWarp__ct((void *)area_warp_forest, (void *)arg1, (void *)arg2);
    *(s32 **)((s8 *)area_warp_forest + 0x18) = &(*(RecoveredGlobal_8019C828___vt__18TObjAreaWarpForest *)&__vt__18TObjAreaWarpForest).value;
    *(s32 *)((s8 *)area_warp_forest + 0) = (s32) TObjAreaWarpForest__name;
    ((TObjAreaWarpForest *)area_warp_forest)->m_c4 = (f32) 0.0f;
    *(s32 *)((s8 *)area_warp_forest + 0xC8) = 0;
    temp_r0 = ((TObjAreaWarpForest *)area_warp_forest)->m_8c;
    temp_r3 = temp_r0 >> 0x1FU;
    ((TObjAreaWarpForest *)area_warp_forest)->m_8c = (u32) (((temp_r0 & 1) ^ temp_r3) - temp_r3);
    if ((get_game_play_mode(temp_r3) == 1) && ((s32) ((TObjAreaWarpForest *)area_warp_forest)->m_8c == 0)) {
        ((s32 (*)(void *))queue_destruction__7TObjectFv)(area_warp_forest);
        return area_warp_forest;
    }
    *(s32 *)((s8 *)area_warp_forest + 0xCC) = register_warp__16TObjMapForceWarpFPv(0);
    *(s32 *)((s8 *)area_warp_forest + 0xD0) = register_warp__16TObjMapForceWarpFPv(1);
    *(s32 *)((s8 *)area_warp_forest + 0xD4) = register_area_warp_object__16TAdStorySelectGCFPv(0);
    *(s32 *)((s8 *)area_warp_forest + 0xD8) = TAdStorySelectGC::get_story_select();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        temp_r3_2 = (int)::operator new(0x88);
        var_r0 = temp_r3_2;
        if (var_r0 != 0) {
            var_r0 = init__13TAdVIConfigGCFf(temp_r3_2, area_warp_forest + 0x38, 20.0f);
        }
        *(s32 *)((s8 *)area_warp_forest + 0xC0) = var_r0;
    } else {
        *(s32 *)((s8 *)area_warp_forest + 0xC0) = 0;
    }
    return area_warp_forest;
}

void *__dt__18TObjAreaWarpForestFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjAreaWarpForest;
        ((void (*)(void *, int))__dt__12TObjAreaWarpFv)(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TObjAreaWarpForest::run_task() {
    u8 *arg0 = (u8 *)this;
  this->m_c4 += 4.0f;
  if (((f32) ((*((s32 *) (((s8 *) (*((u8 **) (((s8 *) arg0) + 0xD4)))) + 4))) - (1 & 0xFFu))) < (this->m_c4))
  {
    this->m_c4 = (f32) 0.0f;
  }
  *((s32 *) (((s8 *) arg0) + 0xC8)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0xC8))) + 0x150);
  ((TObjAreaWarp *)arg0)->handle_area_selection();
}

void TObjAreaWarpForest::confirm_area_transfer(s32) { ((int (*)(void*))confirm_area_transfer__12TObjAreaWarpFPvi)(this); }

void TObjAreaWarpForest::render() {
    Obj_8019C604 *self = (Obj_8019C604 *)this;
    Node_8019C604 *m;
    Node_8019C604 *n;
    if (((VObj_8019C604 *)self)->m8(400.0f, 20.0f) != 0) {
        Colors_8019C604 cols = {3, 2};
        n = self->fD4->next2C;
        while (n != NULL) {
            if (n->f4 != 0) {
                ((TObjDoorJung *)(n->f4))->free_children((void *)cols.c[this->m_8c]);
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
        debug_printf_at(0x130022, lbl_804463B4);
    } else {
        TObjNpcEnemy::set_global_count(0xFF0000FF);
        debug_printf_at(0x130022, lbl_804463A4);
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

u8 *TObjAreaWarpQuest__ct(u8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;
    s32 var_r0;
    u32 temp_r0;
    u32 temp_r4;
    TObjAreaWarp__ct((void *)arg0, (void *)arg1, (void *)arg2);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8019C454___vt__17TObjAreaWarpQuest *)&__vt__17TObjAreaWarpQuest).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjAreaWarpQuest__name;
    *(f32 *)((s8 *)arg0 + 0xC8) = (f32) 0.0f;
    *(s32 *)((s8 *)arg0 + 0xCC) = 0;
    temp_r0 = *(u32 *)((s8 *)arg0 + 0x8C);
    temp_r4 = temp_r0 >> 0x1FU;
    *(u32 *)((s8 *)arg0 + 0x8C) = (u32) (((temp_r0 & 1) ^ temp_r4) - temp_r4);
    *(s32 *)((s8 *)arg0 + 0xC4) = (s32) *(f32 *)((s8 *)arg0 + 0x68);
    *(s32 *)((s8 *)arg0 + 0xD0) = register_warp__16TObjMapForceWarpFPv(0);
    *(s32 *)((s8 *)arg0 + 0xD4) = register_warp__16TObjMapForceWarpFPv(1);
    *(s32 *)((s8 *)arg0 + 0xD8) = register_area_warp_object__16TAdStorySelectGCFPv(0);
    *(s32 *)((s8 *)arg0 + 0xDC) = TAdStorySelectGC::get_story_select();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        temp_r3 = (int)::operator new(0x88);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = init__13TAdVIConfigGCFf(temp_r3, arg0 + 0x38, 20.0f);
        }
        *(s32 *)((s8 *)arg0 + 0xC0) = var_r0;
    } else {
        *(s32 *)((s8 *)arg0 + 0xC0) = 0;
    }
    return arg0;
}

void *__dt__17TObjAreaWarpQuestFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TObjAreaWarpQuest;
        ((void (*)(void *, int))__dt__12TObjAreaWarpFv)(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TObjAreaWarpQuest::run_task() {
    u8 *arg0 = (u8 *)this;
  *((f32 *) (((s8 *) arg0) + 0xC8)) += 4.0f;
  if (((f32) ((unsigned long) ((*((s32 *) (((s8 *) (*((u8 **) (((s8 *) arg0) + 0xD8)))) + 4))) - 1))) < (*((f32 *) (((s8 *) arg0) + 0xC8))))
  {
    *((f32 *) (((s8 *) arg0) + 0xC8)) = (f32) 0.0f;
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
    debug_printf_at(0x13001C, lbl_80446404, ((Obj_8019C144 *)this)->fC4);
    if (((Obj_8019C144 *)this)->f8C == 0) {
        TObjNpcEnemy::set_global_count(0xFFFFFF);
        debug_printf_at(0x130022, lbl_804463B4);
    } else {
        TObjNpcEnemy::set_global_count(0xFF0000FF);
        debug_printf_at(0x130022, lbl_804463A4);
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TObjAreaWarpQuest__vt17(Warp_8019C05C *arg0, void *arg1) {
    s32 i;
    void *p;
    set_area__6TLobbyFl(((u8 *)&lbl_80515BA0), arg0->fBC, get_floor_map_terrain(arg0->fBC));
    mark_area_change_pending();
    if (arg1 != 0 && arg0->fC4 > 1) {
        TObjAreaWarpQuest__sub_8019DCD8(arg1, arg0->fC4);
    }
    if (arg0->fC4 > 1) {
        for (i = 0; i < 4; i++) {
            p = get_player_by_client_id(i);
            if (p != 0 && obj_isState3_324__13TUnk_804806E8Fv(p) != 0 && (u16)((TNpcPlayer *)p)->get_action_flags() != 0xFFFF) {
                TObjAreaWarpQuest__sub_8019DCD8(p, arg0->fC4);
            }
        }
    }
    ((TObjAreaWarpQuest *)((u8 *)&lbl_80515BA0))->get_dest_area();
    send_inter_level_warp_all__10TNpcPlayerFl();
    send_6x21_inter_level_warp(arg1, (s32)(((TObjAreaWarpQuest *)((u8 *)&lbl_80515BA0))->get_dest_area()));
}

u8 *TObjAreaWarpEnding__ct(u8 *area_warp_ending, s32 arg1, s32 arg2) {
    s32 temp_r3;
    s32 var_r0;
    u32 temp_r0;
    u32 temp_r4;
    TObjAreaWarp__ct((void *)area_warp_ending, (void *)arg1, (void *)arg2);
    *(s32 **)((s8 *)area_warp_ending + 0x18) = &(*(RecoveredGlobal_8019BF88___vt__18TObjAreaWarpEnding *)&__vt__18TObjAreaWarpEnding).value;
    *(s32 *)((s8 *)area_warp_ending + 0) = (s32) TObjAreaWarpEnding__name;
    ((TObjAreaWarpEnding *)area_warp_ending)->m_c4 = (f32) 0.0f;
    *(s32 *)((s8 *)area_warp_ending + 0xC8) = 0;
    temp_r0 = ((TObjAreaWarpEnding *)area_warp_ending)->m_8c;
    temp_r4 = temp_r0 >> 0x1FU;
    ((TObjAreaWarpEnding *)area_warp_ending)->m_8c = (u32) (((temp_r0 & 1) ^ temp_r4) - temp_r4);
    *(s32 *)((s8 *)area_warp_ending + 0xCC) = register_warp__16TObjMapForceWarpFPv(0);
    *(s32 *)((s8 *)area_warp_ending + 0xD0) = register_warp__16TObjMapForceWarpFPv(1);
    *(s32 *)((s8 *)area_warp_ending + 0xD4) = register_area_warp_object__16TAdStorySelectGCFPv(0);
    *(s32 *)((s8 *)area_warp_ending + 0xD8) = TAdStorySelectGC::get_story_select();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        temp_r3 = (int)::operator new(0x88);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = init__13TAdVIConfigGCFf(temp_r3, area_warp_ending + 0x38, 20.0f);
        }
        *(s32 *)((s8 *)area_warp_ending + 0xC0) = var_r0;
    } else {
        *(s32 *)((s8 *)area_warp_ending + 0xC0) = 0;
    }
    return area_warp_ending;
}

void *__dt__18TObjAreaWarpEndingFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjAreaWarpEnding;
        ((void (*)(void *, int))__dt__12TObjAreaWarpFv)(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TObjAreaWarpEnding::run_task() {
    u8 *arg0 = (u8 *)this;
  unsigned int new_var;
  this->m_c4 += 4.0f;
  new_var = *((s32 *) (((s8 *) (*((u8 **) (((s8 *) arg0) + 0xD4)))) + 4));
  if ((new_var - 1) < (this->m_c4))
  {
    this->m_c4 = (f32) 0.0f;
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
        debug_printf_at(0x130022, lbl_804463B4);
    } else {
        TObjNpcEnemy::set_global_count(0xFF0000FF);
        debug_printf_at(0x130022, lbl_804463A4);
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TObjAreaWarpEnding::open_confirm_window(s16 arg1) {
    if ((u32) this->m_cc == 0U) {
        this->m_cc = create_window_menu(get_window_layout_position(0x33), 1, arg1);
        if (get_main_phase() == 0xE) {
            ((TWindowSubTradeMain *)(this->m_cc))->add_text_entry(get_localized_text_entry(9, 0x26), 3, 0, -1);
        } else {
            ((TWindowSubTradeMain *)(this->m_cc))->add_text_entry(get_localized_text_entry(9, 0x23), 2, 0, -1);
        }
        ((TWindowSubComCard *)(this->m_cc))->calc_window_size();
        align_menu_entry_positions(this->m_cc);
        ((TWindowSubComCardList *)(this->m_cc))->set_flag70_bit10();
        ((TAdChrSelASlotGC *)(this->m_cc))->set_flag_40();
        *(s16 *)((s8 *)this + 0xB8) = arg1;
    }
}

void TObjAreaWarpEnding::confirm_area_transfer(s32) {
    play_sound_effect(0x40003205, 0, 0, 0);
    u32 obj = ((u32 (*)(s32))__nw__7TObjectFUl)(0x28);
    if (obj != 0U) {
        ((THunterGuildSeqOffline *)obj)->init((void *)tl_00, (void *)((s32 *)TKeyBoardControl::dispatch_select_phase));
    }
}

void TKeyBoardControl::dispatch_select_phase() {

    switch (TAdStorySelectGC__sub_8019DC14()) {
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

void *TObjMapForceWarp__ct(void *map_force_warp, void *parent, void *set) {
    TObjMapWarp__ct(map_force_warp, parent, set);
    *(s32 **)((s8 *)map_force_warp + 0x18) = __vt__16TObjMapForceWarp;
    *(s32 *)((s8 *)map_force_warp + 0) = (s32) TObjMapForceWarp__name;
    if ((s32) ((TObjMapForceWarp *)map_force_warp)->m_8c > 0) {
        ((TObjMapForceWarp *)map_force_warp)->m_fc = 0;
    } else {
        ((TObjMapForceWarp *)map_force_warp)->m_fc = 1;
    }
    if ((u32) ((TObjMapForceWarp *)map_force_warp)->m_b4 != 0U) {
        disallow_rendering__7TObjectFv((TObject *)(*(void **)((s8 *)map_force_warp + 0xB4)));
        ((TObject *)(((TObjMapForceWarp *)map_force_warp)->m_b4))->suspend_update();
    }
    return map_force_warp;
}

void *__dt__16TObjMapForceWarpFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TObjMapForceWarp;
        __dt__11TObjMapWarpFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TObjMapForceWarp::run_task() { process_player_warps(); }

void TObjMapForceWarp::render() {  }

void TObjMapForceWarp__vt17(Obj_8019B978 *arg0) {
    ((TObjMapWarp *)arg0)->draw_debug_destinations();
    if (arg0->f8c > 0) {
        arg0->ffc = 0;
    } else {
        arg0->ffc = 1;
    }
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130021, lbl_804463D0);
    if (arg0->ffc != 0) {
        debug_printf_at(0x130022, lbl_804463E0);
    } else {
        debug_printf_at(0x130022, lbl_804463F0);
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

s32 TObjMapForceWarp__vt16(TObjMapForceWarp *map_force_warp, u16 arg1) {
    if ((s32) ((TObjMapForceWarp *)map_force_warp)->m_fc != 0) {
        map_force_warp->create_warp_id_string((void *)arg1);
    }
    return 1;
}

void TObjMapForceWarp::create_warp_id_string(void *arg) {
    char buf[32];
    char *p;
    sprintf(buf, "%xF", ((Obj_8019B8D8 *)this)->id);
    for (p = buf; *p != 0; p++) {
        *p = TLobby__sub_80070AD8(*p);
    }
    create_TObjWarpString(buf, arg);
}

u8 *__ct__14TObjWarpStringFv(u8 *object, u8 *arg1, s32 arg2, s16 arg3) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__14TObjWarpString.value;
    *(s32 *)((s8 *)object + 0) = (s32) TObjWarpString__name;
    strncpy((s32)(object + 0x1C), arg2, 0x20);
    *(s8 *)((s8 *)object + 0x3B) = 0;
    *(s16 *)((s8 *)object + 0x48) = arg3;
    *(s32 *)((s8 *)object + 0x3C) = -1;
    *(f32 *)((s8 *)object + 0x44) = (f32) 0.0f;
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
        *(f32 *)((s8 *)arg0 + 0x44) = (f32) 255.0f;
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
    *((f32 *) (((s8 *) object) + 0x44)) = (f32) 0.0f;
    queue_destruction__7TObjectFv(object);
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
    s64 *p = warp_string_screen_position_table;
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
    return *p;
}

void * create_TObjWarpString(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x50);
    if (o != NULL) {
        o = ((void * (*)(void *, void *, void *, void *))__ct__14TObjWarpStringFv)(o, tl_clipout, arg0, arg1);
    }
    return o;
}

extern "C" {

void *TObjAreaWarpEndingJung__ct(void *area_warp_ending_jung, void *parent, void *set) {
    s32 temp_r0;
    u32 temp_r4;

    TObjAreaWarpEnding__ct((u8 *)area_warp_ending_jung, (s32)parent, (s32)set);
    *(s32 **)((s8 *)area_warp_ending_jung + 0x18) = __vt__22TObjAreaWarpEndingJung;
    *(s32 *)((s8 *)area_warp_ending_jung + 0) = (s32) TObjAreaWarpEndingJung__name;
    if ((s32) ((TObjAreaWarpEndingJung *)area_warp_ending_jung)->m_8c < 0) {
        ((TObjAreaWarpEndingJung *)area_warp_ending_jung)->m_8c = 0;
    }
    temp_r0 = ((TObjAreaWarpEndingJung *)area_warp_ending_jung)->m_8c;
    temp_r4 = (u32) temp_r0 >> 0x1FU;
    ((TObjAreaWarpEndingJung *)area_warp_ending_jung)->m_8c = (s32) (((temp_r0 & 1) ^ temp_r4) - temp_r4);
    return area_warp_ending_jung;
}

void *__dt__22TObjAreaWarpEndingJungFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__22TObjAreaWarpEndingJung;
        ((void (*)(void *, int))__dt__18TObjAreaWarpEndingFv)(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TObjAreaWarpEndingJung::run_task() {
    f32 temp_f1;

    temp_f1 = this->m_c4;
    this->m_c4 += 4.0f;
    if (this->m_c4 > (get_static_field4_as_float__12TObjWarpJungFv(temp_f1) - 1.0f)) {
        this->m_c4 = (f32) 0.0f;
    }
    handle_area_selection();
}

void TObjAreaWarpEndingJung::render() {
    u8 *arg0 = (u8 *)this;

    if (((VObj_8019B124*)arg0)->m8(400.0f, 20.0f) != 0) {
        if (TObjWarpJung::update_warp_display() != 0) {
            PPCSync();
        }
        switch (this->m_8c) {
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
        debug_printf_at(0x130022, lbl_804463A4);
    } else {
        TObjNpcEnemy::set_global_count(0xFF0000FF);
        debug_printf_at(0x130022, lbl_804463B4);
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void *TObjAreaWarpEndingJung__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xDC);
    if (o != NULL) {
        o = TObjAreaWarpEndingJung__ct(o, tl_05, arg0);
    }
    return o;
}

}
