#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_80131C58.h"
#include "pso/unk/TLobby_80227AA0.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F764.h"
#include "pso/system/PadRumble.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/render/render_util.h"
#include "pso/effect/TEffect.h"
#include "pso/system/MainPhaseState.h"
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/ui/window/TWindowSnapShot.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"
#include "pso/render/BlobShadow.h"

extern "C" {
s32 disable_disconnected_ports__16TKeyBoardControlFv(void *);
int clear_split_screen_fog__8TFogCtrlFv(void*);
}
void update_music_sequencer(void);
extern "C" {
void TObjPlayer__sub_80083FB0(void);

extern s32 lbl_805D62B0;

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

}

u8 gx_default_light_obj[256];

typedef struct GXColor_8000FA00 { u8 r, g, b, a; } GXColor_8000FA00;

struct Cfg_8000FAE4 {
    void *rmode;
    s32 count;
    u32 fb[3];
    u32 fbsize;
    u32 heap;
    u32 heapsize;
};

extern "C" {
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
void fn_800FFE10(void);
void install_depth_alpha_state(void);
void init_char_select_globals__23TAdSinglePlyChrSelectGCFv(void);
void reset_story_select__6TLobbyFv(void);
void TLobby__sub_8020E3C0(void);
s32 TLobby__sub_80226BA4();
}
void init_adx_audio_system(void);
extern "C" {
void init_buffers(void);
}
void request_chara_making_archives(void);
extern "C" {
void TCharaMaking__sub_8028E790(void);
}
s32 verify_game_file_integrity();
extern "C" {
s32 TLobby__sub_8032C91C();
u32 OSInitAlloc(u32, u32, int);
s32 VIInit();
s32 PADInit();
s32 PADSetSpec(int);
s32 GXSetPixelFmt(int, int);
s32 init_debug_text_buffer(s32, int, int);
}
void set_debug_text_scale(u16 arg0);
extern "C" {
void set_matrix_identity(u8 *arg0);
}
void init_record_and_slot_arrays(s32 arg0, s32 arg1, void *arg2, void *arg3);
extern "C" {
u32 calc_framebuffer_size_bytes(int, void *);
}
void init_system_heap_and_global_allocator(u8 *start, s32 size);
extern "C" {
s32 xmalloc__FUl(u32);
s32 init_pad_slots_and_read__16TKeyBoardControlFv(int, int, int);
void TObjPlayer__sub_803E492C(s32 a, s32 b);
int OSResetSystem(void*, void*, void*);
void free_banner_buffers(void);
void release_all__23TAdSinglePlyChrSelectGCFv(void);
void TAdWarningBaseGC__sub_8032D188(void);
void TLobby__sub_80147978(void);
void TLobby__sub_8020E3BC(void);
}
extern u8 gx_default_light_obj[];
extern void *video_initial_draw_framebuffer;
extern void *video_initial_display_framebuffer;
extern GXColor_8000FA00 lbl_805E1200;
void init_disc_error_messages(void);
void load_menu_font(void);
void load_ply_level_tbl(void);
void init_particle_sprite_atlas(void);
void load_info_icon(void);
void init_video_and_gx(void *arg0);
extern u8 GXNtsc480IntDf[];
int lbl_805D49A0;
int lbl_805D49A4;
int player_matrix_stack_buffer;
s32 keyboard_input_buffer;
extern "C" {
void TLobby__sub_8022809C(void);
void TLobby__sub_802433A8(void);
void TObjBoss2Tunnel__sub_8036EF4C(void);
void TObjPlayer__sub_801D92A4(void);
void fn_800FFE0C(void);
void TWindowSnapShot__sub_802A7DA0(void);
void TWindowSubStatusDisp__sub_803386F0(void);
int VIWaitForRetrace(void);
int VIFlush(void);
int VISetBlack(void*);
int xfree__FPv(void*);

void TKeyBoardControl::update() {  }
int TKeyBoardControl__sub_8000F828(void) { return 0; }
}

u8 *resource_decompress_buffer;
s32 lbl_805D49B4;
s32 keyboard_key_state;
s32 keyboard_active_flag;
s32 lbl_805D49C0;
void shutdown_and_reset_system(void) {
    TLobby__sub_802433A8();
    fn_800FFE0C();
    init_depth_alpha_state();
    release_blob_shadow_texture();
    free_banner_buffers();
    TParticleCtrl::free_system();
    TParticleCtrl::reset_emitter_table();
    free_effect_resources();
    TAdSinglePlyChrSelectGC::free_resources();
    TObjPlayer__sub_801D92A4();
    TLobby__sub_8020E3BC();
    TWindowSnapShot__sub_802A7DA0();
    TAdWarningBaseGC__sub_8032D188();
    TLobby::destroy_game_heap();
    TLobby__sub_8022809C();
    TLobby::shutdown_buffers();
    release_all__23TAdSinglePlyChrSelectGCFv();
    TWindowSubStatusDisp__sub_803386F0();
    TObjBoss2Tunnel__sub_8036EF4C();
    TLobby__sub_80147978();
    xfree__FPv((void*)lbl_805D49A0);
    xfree__FPv((void*)lbl_805D49A4);
    xfree__FPv(resource_decompress_buffer);
    xfree__FPv((void*)lbl_805D5680);
    xfree__FPv((void*)anim_model_matrix_array);
    xfree__FPv((void*)player_matrix_stack_buffer);
    VISetBlack((void*)1);
    VIFlush();
    VIWaitForRetrace();
    OSResetSystem((void*)1, (void*)0, (void*)1);
}

extern "C" { MainPhaseState main_phase_state; }
s32 get_previous_main_phase(void) {
    return main_phase_state.prev;
}

s32 get_main_phase(void) {
    return main_phase_state.cur;
}

void TKeyBoardControl__sub_8000F90C(s32 arg0) {
    main_phase_state.unkC = arg0;
}

void set_queued_main_phase(s32 arg0) {
    main_phase_state.unk8 = arg0;
}

s32 TKeyBoardControl__sub_8000F92C(void) {
    main_phase_state.result = 3;
    return main_phase_state.next = main_phase_state.unkC;
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

s32 request_queued_main_phase(void) {
    main_phase_state.result = 2;
    return main_phase_state.next = main_phase_state.unk8;
}

void request_main_phase(s32 arg0) {
    main_phase_state.next = arg0;
    main_phase_state.result = 1;
}

void TKeyBoardControl__sub_8000F9E4(void) {
    main_phase_state.cur = 1;
    main_phase_state.unk8 = 1;
    main_phase_state.unkC = 1;
    main_phase_state.prev = 1;
}
void init_gx_lighting_defaults(void) {
    const GXColor_8000FA00 ambientColor = {32, 32, 32, 255};
    const GXColor_8000FA00 materialColor = {255, 255, 255, 255};
    const GXColor_8000FA00 lightColor = {255, 255, 255, 255};
    GXSetCopyClear(lbl_805E1200, 0xFFFFFF);
    GXInitLightPos(gx_default_light_obj, 0.0f, 10000.0f, 0.0f);
    GXInitLightColor(gx_default_light_obj, lightColor);
    GXLoadLightObjImm(gx_default_light_obj, 1);
    GXSetChanAmbColor(0, ambientColor);
    GXSetChanAmbColor(2, lightColor);
    GXSetChanMatColor(4, materialColor);
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
    size = calc_framebuffer_size_bytes(0, GXNtsc480IntDf);
    cfg.fb[0] = (lo + 0x1F) & ~0x1F;
    cfg.fbsize = 0x40000;
    cfg.fb[1] = cfg.fb[0] + size;
    cfg.fb[2] = cfg.fb[1] + size;
    cfg.heap = OSInitAlloc(cfg.fb[2] + 0x40000, hi, 2);
    cfg.heapsize = 0x518000;
    start = cfg.heap + 0x518000;
    init_system_heap_and_global_allocator((u8 *)start, (s32)(hi - start));
    init_video_and_gx(&cfg);
    OSSetArenaLo(hi);
    lbl_805D49A0 = xmalloc__FUl(0x4560);
    lbl_805D49A4 = xmalloc__FUl(0x73A0);
    init_record_and_slot_arrays(lbl_805D49A0, 0x2E4, (void *)lbl_805D49A4, (void *)(0x2E4));
    init_light_globals(0, 0);
    set_model_render_flags(0x100000);
    resource_decompress_buffer = (u8 *)xmalloc__FUl(0x80000);
    lbl_805D5680 = (void *)xmalloc__FUl(0x6000);
    anim_model_matrix_array = (Mtx34 *)xmalloc__FUl(0x14A0);
    TObjPlayer__sub_803E492C((s32)resource_decompress_buffer, 0x2000);
    TKeyBoardControl::set_key_state((s32)TKeyBoardControl__sub_8000F764);
    player_matrix_stack_buffer = xmalloc__FUl(0x600);
    TObjPlayer::init_matrix_stack(player_matrix_stack_buffer, 0x20);
    set_matrix_identity(0);
    init_pad_slots_and_read__16TKeyBoardControlFv(0, 0, 0);
    TObjBoss2Tunnel::enable_and_trigger();
    init_pad_rumble();
    TKeyBoardControl::init_pad_state();
    TObjPlayer::set_global_7778((s32)lbl_805D5680);
    keyboard_input_buffer = xmalloc__FUl(0x1000);
    init_debug_text_buffer(keyboard_input_buffer, 0x80, 0x800);
    TObjNpcEnemy::set_global_count(-1);
    set_debug_text_scale(0xC);
    init_gx_lighting_defaults();
    install_depth_alpha_state();
    TKeyBoardControl::alloc_buffer();
    TKeyBoardControl__sub_8000F9E4();
    TKeyBoardControl::reset_input((s32)&TKeyBoardControl__global_key_state);
    init_buffers();
    ((TMainTask *)((u8 *)&main_task))->init_main_task();
    TLobby__sub_8007EB70();
    init_adx_audio_system();
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
    request_chara_making_archives();
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
    fn_800FFE10();
    reset_story_select__6TLobbyFv();
    TLobby__sub_8032C91C();
    load_ply_level_tbl();
    verify_game_file_integrity();
    TLobby::handle_flag2_request();
}
