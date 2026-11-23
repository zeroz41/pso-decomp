#include "types.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/os.h>
#include <dolphin/os/OSAlloc.h>
#include <dolphin/os/OSArena.h>
#include <dolphin/os/OSReset.h>
#include <dolphin/dvd.h>
#include <dolphin/vi.h>
#include <dolphin/pad.h>
#include <dolphin/gx.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/ui/keyboard/TKeyBoardControl_8000F764.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/ui/keyboard/SystemBootInitInternal.h"
#include "pso/ui/keyboard/TKeyBoardControl_80131C58.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/system/PadRumble.h"
#include "pso/system/GbaDownloadRuntime.h"
#include "pso/system/GbaAramCache.h"
#include "pso/system/MainPhaseState.h"
#include "pso/system/MainPhaseTable.h"
#include "pso/system/memory.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/render_util.h"
#include "pso/render/TFogCtrl.h"
#include "pso/render/BlobShadow.h"
#include "pso/effect/TEffect.h"
#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8036EF0C.h"
#include "pso/item/TItemReverseTech.h"
#include "pso/map/TSetManager.h"
#include "pso/math/MatrixVector.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/PlayerLevelTable.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80083B38.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/system/scene/OfflineGameScene.h"
#include "pso/system/scene/TEnding.h"
#include "pso/ui/TCharSaveSequence.h"
#include "pso/ui/TLogo.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/ui/charcreate/TCharaMaking_8028E3F4.h"
#include "pso/ui/frontend/TAdEndText.h"
#include "pso/ui/frontend/TAdEndText_80307A34.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC_8023F4E4.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/frontend/TAdTrialModemChkGC.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"
#include "pso/ui/keyboard/TKeyBoardControl_802A1180.h"
#include "pso/ui/window/TWindowSnapShot.h"
#include "pso/ui/window/TWindowSnapShot_802A7D68.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/unk/TLobby_801461EC.h"
#include "pso/unk/TLobby_801A3C48.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/unk/TLobby_80227AA0.h"
#include "pso/unk/TLobby_80243370.h"
#include "pso/unk/TLobby_803382E4.h"
#include "pso/unk/text_8008C4F4.h"
#include "pso/unk/text_80145804.h"
#include "pso/unk/text_8023F3F8.h"
#include "pso/unk/text_80290BEC.h"
#include "pso/unk/text_802A1020.h"
#include "pso/unk/text_802A1154.h"
#include "pso/unk/text_803D8030.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803DA754.h"
#include "pso/unk/text_803DCDB0.h"
#include "pso/unk/text_803DE7E0.h"
#include "pso/unk/text_803E2F28.h"

GXLightObj gx_default_light_obj[4];
MainPhaseState main_phase_state;

saddr record_table_buffer;
saddr slot_table_buffer;
saddr player_matrix_stack_buffer;
DebugTextRecord *keyboard_input_buffer;
u8 *resource_decompress_buffer;
s32 lbl_805D49B4;
s32 keyboard_key_state;
s32 keyboard_active_flag;
s32 keyboard_input_flag;

void poll_input_devices_frame(void) {
    TKeyBoardControl::read_pads();
    hardware_keyboard_state.disable_disconnected_ports();
    TKeyBoardControl::flush_input();
    update_pad_rumble();
    TLobby::reset_state_byte();
}

void TKeyBoardControl::run_tasks() {
    TObjPlayer::clear_shadow_pass_request();
    update_global_sound_frame();
    if (lbl_805D62B0 != 0) {
        update_music_sequencer();
    }
    keyboard_task_object.run_tasks();
}

void forward_clear_split_screen_fog(void) {
    TFogCtrl::clear_split_screen_fog();
}

void TKeyBoardControl__sub_8000F7FC(void) {
    end_of_render_root.run_tasks();
}

void TKeyBoardControl::update() {
}

int TKeyBoardControl__sub_8000F828(void) {
    return 0;
}

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
    free_ply_level_tbl();
    free_item_drop_memory_pool();
    TWindowSnapShot__sub_802A7DA0();
    TAdWarningBaseGC__sub_8032D188();
    TLobby::destroy_game_heap();
    TLobby__sub_8022809C();
    TLobby::shutdown_buffers();
    TAdSinglePlyChrSelectGC::release_all();
    TWindowSubStatusDisp__sub_803386F0();
    reset_display_copy_filter();
    TLobby__sub_80147978();
    xfree((void *)record_table_buffer);
    xfree((void *)slot_table_buffer);
    xfree(resource_decompress_buffer);
    xfree(motion_blend_buffer);
    xfree(anim_model_matrix_array);
    xfree((void *)player_matrix_stack_buffer);
    VISetBlack(TRUE);
    VIFlush();
    VIWaitForRetrace();
    OSResetSystem(OS_RESET_HOTRESET, 0, TRUE);
}

s32 get_previous_main_phase(void) {
    return main_phase_state.prev;
}

s32 get_main_phase(void) {
    return main_phase_state.cur;
}

void TKeyBoardControl__sub_8000F90C(s32 phase) {
    main_phase_state.fallback = phase;
}

void set_queued_main_phase(s32 phase) {
    main_phase_state.queued_main_phase = phase;
}

s32 TKeyBoardControl__sub_8000F92C(void) {
    main_phase_state.result = 3;
    return main_phase_state.next = main_phase_state.fallback;
}

s32 TKeyBoardControl::get_input() {
    return keyboard_input_flag;
}

void TKeyBoardControl__sub_8000F950(void) {
    keyboard_input_flag = 1;
}

void TKeyBoardControl__sub_8000F95C(void) {
    keyboard_input_flag = 0;
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
    return main_phase_state.next = main_phase_state.queued_main_phase;
}

void request_main_phase(s32 phase) {
    main_phase_state.next = phase;
    main_phase_state.result = 1;
}

void reset_main_phase_state(void) {
    main_phase_state.cur = 1;
    main_phase_state.queued_main_phase = 1;
    main_phase_state.fallback = 1;
    main_phase_state.prev = 1;
}

void init_gx_lighting_defaults(void) {
    GXColor ambient = {0x20, 0x20, 0x20, 0xFF};
    GXColor material = {0xFF, 0xFF, 0xFF, 0xFF};
    GXColor light = {0xFF, 0xFF, 0xFF, 0xFF};
    GXColor clear = {0x00, 0x00, 0x00, 0x00};

    GXSetCopyClear(clear, 0xFFFFFF);
    GXInitLightPos(gx_default_light_obj, 0.0f, 10000.0f, 0.0f);
    GXInitLightColor(gx_default_light_obj, light);
    GXLoadLightObjImm(gx_default_light_obj, GX_LIGHT0);
    GXSetChanAmbColor(GX_COLOR0, ambient);
    GXSetChanAmbColor(GX_ALPHA0, light);
    GXSetChanMatColor(GX_COLOR0A0, material);
    GXCopyDisp(video_initial_display_framebuffer, GX_TRUE);
    GXCopyDisp(video_initial_draw_framebuffer, GX_TRUE);
    set_cull_none();
}

void init_game_systems(void) {
    SystemVideoInitConfig cfg;
    u32 lo;
    u32 hi;
    u32 size;
    uaddr start;

    PADSetSpec(5);
    OSInit();
    DVDInit();
    VIInit();
    PADInit();
    TKeyBoardControl::update_camera();
    lo = (u32)OSGetArenaLo();
    hi = (u32)OSGetArenaHi();
    cfg.rmode = NULL;
    cfg.rmode = &GXNtsc480IntDf;
    cfg.count = 2;
    size = calc_framebuffer_size_bytes(0, &GXNtsc480IntDf);
    cfg.fb[0] = (lo + 0x1F) & ~0x1F;
    cfg.fbsize = 0x40000;
    cfg.fb[1] = cfg.fb[0] + size;
    cfg.fb[2] = cfg.fb[1] + size;
    cfg.heap = (u32)OSInitAlloc((void *)(cfg.fb[2] + 0x40000), (void *)hi, 2);
    cfg.heapsize = 0x518000;
    start = cfg.heap + 0x518000;
    init_system_heap_and_global_allocator((u8 *)start, (s32)(hi - start));
    init_video_and_gx(&cfg);
    OSSetArenaLo((void *)hi);
    record_table_buffer = (saddr)xmalloc(0x4560);
    slot_table_buffer = (saddr)xmalloc(0x73A0);
    init_record_and_slot_arrays(record_table_buffer, 0x2E4, (void *)slot_table_buffer, (void *)0x2E4);
    init_light_globals(0, 0);
    set_model_render_flags(0x100000);
    resource_decompress_buffer = (u8 *)xmalloc(0x80000);
    motion_blend_buffer = (void *)xmalloc(0x6000);
    anim_model_matrix_array = (Mtx34 *)xmalloc(0x14A0);
    TObjPlayer__sub_803E492C((saddr)resource_decompress_buffer, 0x2000);
    TKeyBoardControl::set_key_state((saddr)poll_input_devices_frame);
    player_matrix_stack_buffer = (saddr)xmalloc(0x600);
    TObjPlayer::init_matrix_stack(player_matrix_stack_buffer, 0x20);
    set_matrix_identity(0);
    TKeyBoardControl::init_pad_slots_and_read(0, 0, 0);
    TObjBoss2Tunnel::enable_and_trigger();
    init_pad_rumble();
    TKeyBoardControl::init_pad_state();
    TObjPlayer::set_global_7778((saddr)motion_blend_buffer);
    keyboard_input_buffer = (DebugTextRecord *)xmalloc(0x1000);
    init_debug_text_buffer(keyboard_input_buffer, 0x80, 0x800);
    TObjNpcEnemy::set_global_count(-1);
    set_debug_text_scale(0xC);
    init_gx_lighting_defaults();
    install_depth_alpha_state();
    TKeyBoardControl::alloc_buffer();
    reset_main_phase_state();
    hardware_keyboard_state.reset_input();
    init_buffers();
    main_task.init_main_task();
    TLobby__sub_8007EB70();
    init_adx_audio_system();
    TLobby::init_download_state();
    load_menu_font();
    TLobby::load_now_loading_texture();
    TCharaMaking__sub_8028E790();
    TAdSinglePlyChrSelectGC::init_char_select_globals();
    TLobby__sub_80226BA4();
    TLobby::wait_for_sound_init();
    load_info_icon();
    alloc_item_drop_memory_pool();
    TWindowSnapShot::alloc_buffer();
    TAdWarningBaseGC::init_heap();
    TLobby::load_ask_dictionary();
    request_chara_making_archives();
    load_effect_resources();
    init_particle_sprite_atlas();
    TParticleCtrl::init_particle_buffer();
    GXSetPixelFmt(GX_PF_RGBA6_Z24, GX_ZC_LINEAR);
    init_disc_error_messages();
    TLobby::init_keyboard_buffer();
    TAdPlayerLoadGC::load_banner_files();
    TLobby::load_player_data();
    TLobby::init_account_entries();
    load_ha_u032_kage();
    fn_800FFE10();
    TLobby::reset_story_select();
    gba_init();
    load_ply_level_tbl();
    verify_game_file_integrity();
    TLobby::handle_flag2_request();
}

MainPhaseEntry main_phase_table[] = {
    { NULL, NULL, NULL },
    { TLogo::init_logo_scene, TLogo::run_frame, TLogo__sub_8013F5AC },
    { TAdMultiChgGameModeGC__sub_8023F62C, run_game_mode_select_frame, TLobby::release_scene_resources },
    { TKeyBoardControl::update_menu_scene, update_movie_phase, fn_802A1154 },
    { TAdMultiChgGameModeGC__sub_8023F4E4, run_game_mode_select_frame, TLobby::release_scene_resources },
    { TKeyBoardControl::update_main_menu_scene, run_main_frame, fn_80290BEC },
    { TAdMultiChgGameModeGC::render_game_mode_change, run_game_mode_select_frame, TLobby::release_scene_resources },
    { TAdMultiChgGameModeGC__sub_8023F5B4, run_game_mode_select_frame, TLobby::release_scene_resources },
    { start_ending_sequence, TKeyBoardControl::run_main_frame, TAdEndText::cleanup },
    { TAdMultiChgGameModeGC::render_scene, run_game_mode_select_frame, TLobby::release_scene_resources },
    { TAdMultiChgGameModeGC__sub_8023F564, run_game_mode_select_frame, TLobby::release_scene_resources },
    { TAdMultiChgGameModeGC__sub_8023F58C, run_game_mode_select_frame, TLobby::release_scene_resources },
    { TEnding::set_flag_and_advance, run_game_frame, fn_8008C4F4 },
    { TAdMultiChgGameModeGC__sub_8023F50C, run_game_mode_select_frame, TLobby::release_scene_resources },
    { init_offline_game_scene, dispatch_offline_main_frame, TLobby::teardown_scene },
    { run_online_lobby_scene, TLobby::update_camera_state, cleanup_online_lobby_scene },
    { TEnding::start_ending_scene, run_game_frame, fn_8008C4F4 },
    { NULL, NULL, NULL },
    { init_single_player_char_select_scene, TAdSinglePlyChrSelectGC::run_frame, TAdSinglePlyChrSelectGC__sub_8033B264 },
    { TAdTrialModemChkGC__sub_803354E8, TAdTrialModemChkGC::check_modem_result, TAdTrialModemChkGC__sub_803354A4 },
    { NULL, NULL, NULL },
    { TItemReverseTech::init_scene, TItemReverseTech::run_frame, TItemReverseTech::run_cleanup_callbacks },
};

void main(void) {
    MainPhaseCallback fn;
    MainPhaseCallback update;

    init_game_systems();
    while (main_phase_state.cur != 0) {
        main_phase_state.result = 0;
        fn = main_phase_table[main_phase_state.cur].init;
        if (fn != NULL) {
            fn();
        }
        update = main_phase_table[main_phase_state.cur].update;
        while (main_phase_state.result == 0 && update != NULL) {
            update();
            actor_frame_tick++;
        }
        fn = main_phase_table[main_phase_state.cur].exit;
        if (fn != NULL) {
            fn();
        }
        switch (main_phase_state.result) {
        case 1:
        case 2:
        case 3:
            main_phase_state.prev = main_phase_state.cur;
            main_phase_state.cur = main_phase_state.next;
            break;
        }
    }
    shutdown_and_reset_system();
}
