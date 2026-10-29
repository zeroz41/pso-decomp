#include "types.h"
#include "pso/render/render_util.h"
#include "pso/object/TObjMotion.h"
#include "pso/effect/TEffect.h"
#include "pso/system/PadRumble.h"
#include "pso/misc/TKeyBoardControl_803DE9C4.h"
#include "pso/object/TObjFish.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/TMainTask.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TKeyBoardControl.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneMe3Stelth.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSnapShot.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/TAdWarningBaseGC.h"

extern "C" {
u8 gx_default_light_obj[256];
}


struct RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270 {
    s32 value;
    u8 remaining[0xAC];
};

struct RecoveredGlobal_8000F9E4_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F90C_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F9CC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F8FC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F8EC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F91C_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct G_8000F92C { s32 f0; s32 f4; s32 f8; s32 fc; s32 f10; };

struct G_8000F9B0 { s32 f0; s32 f4; s32 f8; s32 fc; s32 f10; };

typedef struct GXColor_8000FA00 { u8 r, g, b, a; } GXColor_8000FA00;

struct Cfg_8000FAE4 {
    void *rmode;
    s32 count;
    u32 fb[3];
    u32 fbsize;
    u32 heap;
    u32 heapsize;
};

extern s32 lbl_805D49C0;
extern "C" {
void TKeyBoardControl__sub_8000F950(void);
void TKeyBoardControl__sub_8000F95C(void);
void mark_area_change_pending(void);
void clear_keyboard_key_state(void);
s32 disable_disconnected_ports__16TKeyBoardControlFv(void *);
void TKeyBoardControl__sub_8000F764(void);
void TKeyBoardControl__sub_8000F7FC(void);
extern RecoveredGlobal_8000F9E4_lbl_804FE120 main_phase_state;
void TKeyBoardControl__sub_8000F9E4(void);
void TKeyBoardControl__sub_8000F90C(s32 arg0);
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
s32 get_main_phase(void);
s32 TKeyBoardControl__sub_8000F8EC(void);
void TKeyBoardControl__sub_8000F91C(s32 arg0);
bool is_keyboard_active(void);
s32 TKeyBoardControl__sub_8000F92C(void);
s32 request_queued_main_phase(void);
void GXSetCopyClear(GXColor_8000FA00 clear_clr, u32 clear_z);
void GXCopyDisp(void *dest, int clear);
void GXInitLightPos(void *lt_obj, f32 x, f32 y, f32 z);
void GXInitLightColor(void *lt_obj, GXColor_8000FA00 color);
void GXLoadLightObjImm(void *lt_obj, int light);
void GXSetChanAmbColor(int chan, GXColor_8000FA00 amb_color);
void GXSetChanMatColor(int chan, GXColor_8000FA00 mat_color);
s32 DVDInit();
u32 OSGetArenaHi();
u32 OSGetArenaLo();
s32 OSInit();
s32 OSSetArenaLo(u32);
void TLobby__sub_8007EB70(void);
void TObjTailsTailsMove__sub_800FFE10(void);
void install_depth_alpha_state(void);
void init_char_select_globals__23TAdSinglePlyChrSelectGCFv(void);
void reset_story_select__6TLobbyFv(void);
void TLobby__sub_8020E3C0(void);
s32 TLobby__sub_80226BA4();
void TLobby__sub_8022780C(void);
void init_buffers(void);
void TCharaMaking__sub_8028E6B4(void);
void TCharaMaking__sub_8028E790(void);
s32 fn_802A1020();
s32 TLobby__sub_8032C91C();
u32 OSInitAlloc(u32, u32, int);
s32 VIInit();
s32 PADInit();
s32 PADSetSpec(int);
s32 GXSetPixelFmt(int, int);
s32 fn_803D8030(s32, int, int);
void fn_803D8064(u16 arg0);
void set_matrix_identity(u8 *arg0);
void fn_803DA754(s32 arg0, s32 arg1, void *arg2, void *arg3);
u32 fn_803DD3DC(int, void *);
void fn_803DE804(u8 *start, s32 size);
s32 xmalloc__FUl(u32);
s32 init_pad_slots_and_read__16TKeyBoardControlFv(int, int, int);
void TObjPlayer__sub_803E492C(s32 a, s32 b);
int TKeyBoardControl__sub_8000F828(void);
int OSResetSystem(void*, void*, void*);
void TAdPlayerLoadGC__sub_801E1350(void);
void release_all__23TAdSinglePlyChrSelectGCFv(void);
void TAdWarningBaseGC__sub_8032D188(void);
int clear_split_screen_fog__8TFogCtrlFv(void*);
void TLobby__sub_80147978(void);
void TLobby__sub_8020E3BC(void);
}
extern s32 keyboard_active_flag;
void activate_keyboard(void);
void deactivate_keyboard(void);
extern s32 keyboard_key_state;
extern RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270 TKeyBoardControl__global_key_state;
extern u8 gx_default_light_obj[];
extern void *video_initial_draw_framebuffer;
extern void *video_initial_display_framebuffer;
extern GXColor_8000FA00 lbl_805D7D00;
extern GXColor_8000FA00 lbl_805D7D04;
extern GXColor_8000FA00 lbl_805D7D08;
extern const f32 lbl_805D7D0C;
extern const f32 lbl_805D7D10;
extern GXColor_8000FA00 lbl_805E1200;
void init_gx_lighting_defaults(void);
void init_disc_error_messages(void);
void load_ha_u032_kage(void);
void load_menu_font(void);
void load_ply_level_tbl(void);
void init_particle_sprite_atlas(void);
void load_info_icon(void);
void init_video_and_gx(void *arg0);
extern u8 GXNtsc480IntDf[];
extern int lbl_805D49A0;
extern int lbl_805D49A4;
extern int player_matrix_stack_buffer;
extern s32 keyboard_input_buffer;
extern int resource_decompress_buffer;
void init_game_systems(void);
void shutdown_and_reset_system(void);
void update_music_sequencer(void);
extern "C" {
void update_global_sound_frame(void);
void TLobby__sub_8022809C(void);
void TLobby__sub_802433A8(void);
void TObjBoss2Tunnel__sub_8036EF4C(void);
void TObjPlayer__sub_80083FB0(void);
void TObjPlayer__sub_801D92A4(void);
void TObjTailsTailsMove__sub_800FFE0C(void);
void TWindowSnapShot__sub_802A7DA0(void);
void TWindowSubStatusDisp__sub_803386F0(void);
int VIWaitForRetrace(void);
int VIFlush(void);
int VISetBlack(void*);
int xfree__FPv(void*);

extern s32 lbl_805D62B0;

typedef char RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270_size[sizeof(RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270) == 0xB0 ? 1 : -1];
void TKeyBoardControl__sub_8000F764(void) {
    TKeyBoardControl::read_pads();
    disable_disconnected_ports__16TKeyBoardControlFv(&TKeyBoardControl__global_key_state.value);
    TKeyBoardControl::flush_input();
    update_pad_rumble();
    TLobby::reset_state_byte();
}

void TKeyBoardControl::run_tasks() {
    TObjPlayer__sub_80083FB0();
    update_global_sound_frame();
    if ((s32) lbl_805D62B0 != 0) {
        update_music_sequencer();
    }
    keyboard_task_object.run_tasks();
}

int TKeyBoardControl::get_fog_ctrl() { return clear_split_screen_fog__8TFogCtrlFv(this); }

void TKeyBoardControl__sub_8000F7FC(void) {
    end_of_render_root.run_tasks();
}

void TKeyBoardControl::update() {  }
int TKeyBoardControl__sub_8000F828(void) { return 0; }
}

void shutdown_and_reset_system(void) { TLobby__sub_802433A8(); TObjTailsTailsMove__sub_800FFE0C(); init_depth_alpha_state(); TObjEneMe3Stelth::destroy_resources(); TAdPlayerLoadGC__sub_801E1350(); TParticleCtrl::free_system(); TParticleCtrl::reset_emitter_table(); free_effect_resources(); TAdSinglePlyChrSelectGC::free_resources(); TObjPlayer__sub_801D92A4(); TLobby__sub_8020E3BC(); TWindowSnapShot__sub_802A7DA0(); TAdWarningBaseGC__sub_8032D188(); TLobby::destroy_game_heap(); TLobby__sub_8022809C(); TLobby::shutdown_buffers(); release_all__23TAdSinglePlyChrSelectGCFv(); TWindowSubStatusDisp__sub_803386F0(); TObjBoss2Tunnel__sub_8036EF4C(); TLobby__sub_80147978(); xfree__FPv((void*)lbl_805D49A0); xfree__FPv((void*)lbl_805D49A4); xfree__FPv((void*)resource_decompress_buffer); xfree__FPv((void*)lbl_805D5680); xfree__FPv((void*)anim_model_matrix_array); xfree__FPv((void*)player_matrix_stack_buffer); VISetBlack((void*)1); VIFlush(); VIWaitForRetrace(); OSResetSystem((void*)1, (void*)0, (void*)1); }

typedef char RecoveredGlobal_8000F90C_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F90C_lbl_804FE120) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_8000F8FC_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F8FC_lbl_804FE120) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_8000F8EC_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F8EC_lbl_804FE120) == 0x18 ? 1 : -1];

s32 TKeyBoardControl__sub_8000F8EC(void) {
    return *(s32 *)((s8 *)(&(*(RecoveredGlobal_8000F8EC_lbl_804FE120 *)&main_phase_state).value) + 0x14);
}

s32 get_main_phase(void) {
    return (*(RecoveredGlobal_8000F8FC_lbl_804FE120 *)&main_phase_state).value;
}

void TKeyBoardControl__sub_8000F90C(s32 arg0) {
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_8000F90C_lbl_804FE120 *)&main_phase_state).value) + 0xC) = arg0;
}

typedef char RecoveredGlobal_8000F91C_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F91C_lbl_804FE120) == 0x18 ? 1 : -1];
void TKeyBoardControl__sub_8000F91C(s32 arg0) {
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_8000F91C_lbl_804FE120 *)&main_phase_state).value) + 8) = arg0;
}

s32 TKeyBoardControl__sub_8000F92C(void) {
    (*(G_8000F92C *)&main_phase_state).f10 = 3;
    return (*(G_8000F92C *)&main_phase_state).f4 = (*(G_8000F92C *)&main_phase_state).fc;
}

s32 TKeyBoardControl::get_input() {
    return lbl_805D49C0;
}

void TKeyBoardControl__sub_8000F950(void) {
    lbl_805D49C0 = 1;
}

void TKeyBoardControl__sub_8000F95C(void) {
    lbl_805D49C0 = 0;
}

bool is_keyboard_active(void) {
    return keyboard_active_flag != 0;
}

void activate_keyboard(void) {
    keyboard_active_flag = 1;
}

void deactivate_keyboard(void) {
    keyboard_active_flag = 0;
}

s32 TKeyBoardControl::get_key_state() {
    return keyboard_key_state;
}

void mark_area_change_pending(void) {
    keyboard_key_state = 1;
}

void clear_keyboard_key_state(void) {
    keyboard_key_state = 0;
}
typedef char RecoveredGlobal_8000F9E4_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F9E4_lbl_804FE120) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_8000F9CC_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F9CC_lbl_804FE120) == 0x18 ? 1 : -1];

s32 request_queued_main_phase(void) {
    (*(G_8000F9B0 *)&main_phase_state).f10 = 2;
    return (*(G_8000F9B0 *)&main_phase_state).f4 = (*(G_8000F9B0 *)&main_phase_state).f8;
}

void TKeyBoardControl__sub_8000F9CC(s32 arg0) {
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_8000F9CC_lbl_804FE120 *)&main_phase_state).value) + 4) = arg0;
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_8000F9CC_lbl_804FE120 *)&main_phase_state).value) + 0x10) = 1;
}

void TKeyBoardControl__sub_8000F9E4(void) {
    *(s32 *)((s8 *)&main_phase_state.value + 0) = 1;
    *(s32 *)((s8 *)&main_phase_state.value + 8) = 1;
    *(s32 *)((s8 *)&main_phase_state.value + 0xC) = 1;
    *(s32 *)((s8 *)&main_phase_state.value + 0x14) = 1;
}
void init_gx_lighting_defaults(void) {
    GXColor_8000FA00 c0 = lbl_805D7D00;
    GXColor_8000FA00 c1 = lbl_805D7D04;
    GXColor_8000FA00 c2 = lbl_805D7D08;
    GXSetCopyClear(lbl_805E1200, 0xFFFFFF);
    GXInitLightPos(gx_default_light_obj, lbl_805D7D0C, lbl_805D7D10, lbl_805D7D0C);
    GXInitLightColor(gx_default_light_obj, c2);
    GXLoadLightObjImm(gx_default_light_obj, 1);
    GXSetChanAmbColor(0, c0);
    GXSetChanAmbColor(2, c2);
    GXSetChanMatColor(4, c1);
    GXCopyDisp(video_initial_display_framebuffer, 1);
    GXCopyDisp(video_initial_draw_framebuffer, 1);
    set_cull_none();
}
void init_game_systems(void) {
    Cfg_8000FAE4 cfg;
    u32 lo;
    u32 hi;
    u32 size;
    u32 start;
    s32 t;
    PADSetSpec(5);
    OSInit();
    DVDInit();
    VIInit();
    PADInit();
    TKeyBoardControl::update_camera();
    lo = OSGetArenaLo();
    hi = OSGetArenaHi();
    cfg.rmode = NULL;
    cfg.rmode = GXNtsc480IntDf;
    cfg.count = 2;
    size = fn_803DD3DC(0, GXNtsc480IntDf);
    cfg.fb[0] = (lo + 0x1F) & ~0x1F;
    cfg.fbsize = 0x40000;
    cfg.fb[1] = cfg.fb[0] + size;
    cfg.fb[2] = cfg.fb[1] + size;
    cfg.heap = OSInitAlloc(cfg.fb[2] + 0x40000, hi, 2);
    cfg.heapsize = 0x518000;
    start = cfg.heap + 0x518000;
    fn_803DE804((u8 *)start, hi - start);
    init_video_and_gx(&cfg);
    OSSetArenaLo(hi);
    (*(s32 *)&lbl_805D49A0) = xmalloc__FUl(0x4560);
    (*(s32 *)&lbl_805D49A4) = xmalloc__FUl(0x73A0);
    fn_803DA754((*(s32 *)&lbl_805D49A0), 0x2E4, (void *)(*(s32 *)&lbl_805D49A4), (void *)(0x2E4));
    init_light_globals(0, 0);
    set_model_render_flags(0x100000);
    (*(s32 *)&resource_decompress_buffer) = xmalloc__FUl(0x80000);
    (*(s32 *)&lbl_805D5680) = xmalloc__FUl(0x6000);
    (*(s32 *)&anim_model_matrix_array) = xmalloc__FUl(0x14A0);
    TObjPlayer__sub_803E492C(((*(s32 *)&resource_decompress_buffer)), 0x2000);
    TKeyBoardControl::set_key_state((s32)TKeyBoardControl__sub_8000F764);
    (*(s32 *)&player_matrix_stack_buffer) = xmalloc__FUl(0x600);
    TObjPlayer::init_matrix_stack((*(s32 *)&player_matrix_stack_buffer), 0x20);
    set_matrix_identity(0);
    init_pad_slots_and_read__16TKeyBoardControlFv(0, 0, 0);
    TObjBoss2Tunnel::enable_and_trigger();
    init_pad_rumble();
    TKeyBoardControl::init_pad_state();
    TObjPlayer::set_global_7778((s32)((void *)(*(s32 *)&lbl_805D5680)));
    keyboard_input_buffer = xmalloc__FUl(0x1000);
    fn_803D8030(keyboard_input_buffer, 0x80, 0x800);
    TObjNpcEnemy::set_global_count(-1);
    fn_803D8064(0xC);
    init_gx_lighting_defaults();
    install_depth_alpha_state();
    TKeyBoardControl::alloc_buffer();
    TKeyBoardControl__sub_8000F9E4();
    TKeyBoardControl::reset_input((s32)&TKeyBoardControl__global_key_state);
    init_buffers();
    ((TMainTask *)((u8 *)&main_task))->init_main_task();
    TLobby__sub_8007EB70();
    TLobby__sub_8022780C();
    TLobby::init_download_state();
    load_menu_font();
    TLobby::load_now_loading_texture();
    TCharaMaking__sub_8028E790();
    init_char_select_globals__23TAdSinglePlyChrSelectGCFv();
    TLobby__sub_80226BA4();
    TLobby::wait_for_sound_init();
    load_info_icon();
    TLobby__sub_8020E3C0();
    TWindowSnapShot::alloc_buffer();
    TAdWarningBaseGC::init_heap();
    TLobby::load_ask_dictionary();
    TCharaMaking__sub_8028E6B4();
    load_effect_resources();
    init_particle_sprite_atlas();
    TParticleCtrl::init_particle_buffer();
    GXSetPixelFmt(1, 0);
    init_disc_error_messages();
    TLobby::init_keyboard_buffer();
    TAdPlayerLoadGC::load_banner_files();
    TLobby::load_player_data();
    TLobby::init_account_entries();
    load_ha_u032_kage();
    TObjTailsTailsMove__sub_800FFE10();
    reset_story_select__6TLobbyFv();
    TLobby__sub_8032C91C();
    load_ply_level_tbl();
    fn_802A1020();
    TLobby::handle_flag2_request();
}
