#include "pso/system/task/TMainTask.h"
#include "pso/system/scene/TEndingC.h"
#include "types.h"
#include "pso/render/gjSystem.h"
#include "pso/system/main_loop.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/network/TLobby.h"
#include "pso/system/scene/TEnding.h"
#include "pso/render/GinjaView.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/audio/BgmStream.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/MallocLoadFilePrc.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/TLobby_800FC3CC.h"
#include "pso/system/scene/TScene.h"
#include "pso/system/scene/TEndingAB.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8028D5D4.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjEndingPlayer.h"
#include "pso/ui/frontend/TAdEndText.h"
#include "pso/ui/frontend/TAdRicoRingCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/map/area/AreaScene.h"
#include "pso/player/PlayerActionProvider.h"
#include "pso/system/AsyncFileRead.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/system/TScreenFadeOut.h"
#include "pso/map/FloorArea.h"
#include "pso/system/scene/TEndingPicStage.h"
#include "pso/effect/particle/ParticleRadial.h"
#include "pso/system/scene/TEndingPic.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/window/SmallFontText.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"

const char TEnding::class_name_string[] = "TEnding";

// Load and release hooks of the ending scene, in pairs: run_load_callback_table
// calls the first of each pair, call_funcs_reverse the second, last pair first.
void (*ending_scene_callbacks[26])(void) = {
    TCameraCtrl::reset_view_state, TCameraCtrl::reset,
    TCameraCtrl::init_default_view, TCameraCtrl::reset_default_view,
    TLobby::update_keyboard_menu, free_keyboard_soft_resources,
    set_ending_callback, free_ending_callback,
    ending_scene_nop_load, ending_scene_nop_release,
    register_texture_ed_512kabe_c, TEndingC::release_lobby,
    TScene::bind_ending_wall_textures, TEndingAB::destroy_instance,
    alloc_quest_download_buffer, TLobby::free_chr_select_singleton,
    init_item_system, free_item_system,
    create_player_ending_motion, free_player_ending_motion,
    init_game_player_actions, release_game_player_actions,
    TAdEndText::load_ending_font, TAdEndText::free_resources,
    TAdRicoRingCtrl::load_static_resource, TAdRicoRingCtrl::release_global_805D4A00,
};

void release_ending_scene(void) {
    TLobby::stop_audio_streams();
    main_task.delete_layer_children();
    TLobby::call_funcs_reverse(ending_scene_callbacks, sizeof(ending_scene_callbacks));
    render_tick();
}
void run_game_frame(void) {
    begin_gx_frame();
    controller_stuff();
    update_keyboard_input_frame();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render();
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
    TAdSinglePlyChrSelectGC::noop();
    if (static_cast<s8>(poll_reset_request()) != 0) {
        switch_to_fallback_main_phase();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        request_main_phase(0);
    }
    render_tick();
}

void TEnding::set_flag_and_advance() {
    ending_scene_active = 1;
    TEnding::start_ending_scene();
}

void TEnding::start_ending_scene() {
    set_screen_size(1.0f, 0.85f);
    set_copy_clear_color_argb(0, 0, 0);
    reset_controller_input_state();
    init_map_lights(&default_scene_light_config);
    new TCameraCtrl(tl_camera);
    Vec a = {0.0f, 0.0f, 0.0f};
    Vec b = {0.0f, 0.0f, -100.0f};
    TCameraCtrl::select_active_controller(9);
    set_active_camera_pose(&a, &b);
    clear_resource_load_tasks();
    run_load_callback_table(ending_scene_callbacks, sizeof(ending_scene_callbacks));
    set_fallback_main_phase(2);
    set_queued_main_phase(2);
    play_area_music("ending.adx");
    TParticleCtrl::create_quad_sprites();
    new TEnding;
    render_tick();
}

// The empty load/unload pair in ending_scene_callbacks
void ending_scene_nop_release() {}
void ending_scene_nop_load() {}

void TEnding::render() {}

int get_ending_c_start_seconds(void) { return 140; }

u32 ending_frame_counter;
s32 ending_scene_active;

extern "C" {
u32 __cvt_fp2unsigned(f32);
}
const char *TEnding::class_name = TEnding::class_name_string;

void TEnding::run_task() {
    switch (phase) {
    case 0: {
        TAdMultiChgGameModeGC::set_default_camera();
        u32 ticks = ending_frame_counter + 1;
        ending_frame_counter = ticks;
        s32 rate = timing_rate;
        if (ticks > (u32)(rate * 140)) {
            new TEndingPicStage(this);
            phase = 1;
            return;
        }
        f32 duration = 2.0f * (f32)rate;
        if (ending_frame_counter > (u32)((rate * 139) - __cvt_fp2unsigned(duration)))
            ring_controller->start_rings_anim(duration);
        return;
    }
    case 2:
        break;
    case 1:
        if (get_end_text_font_loaded_flag() != 0) {
            s32 ticks = elapsed_ticks + 1;
            elapsed_ticks = ticks;
            if (ticks > timing_rate * 10) {
                new TScreenFadeOut(tl_fade, destroy_keyboard_objects);
                phase = 2;
            }
        }
        break;
    }
}

TEnding::~TEnding() {
    ending_scene_active = 0;
    TLobby::stop_audio_streams();
}

TEnding::TEnding() : TObject(tl_window) {
    m_name = TEnding::class_name;
    TEnding__sub_8008C9F8();
    TMainTask::cleanup_game_objects();
    set_current_floor_area(1);
    switch (get_video_standard()) {
    case 0: timing_rate = 30; break;
    case 1: timing_rate = 25; break;
    }
    new TEndingPic(tl_01);
    new TEndingAB(this);
    new TEndingC(this);
    ending_frame_counter = 0;
    phase = 0;
    elapsed_ticks = 0;
    TAdRicoRingCtrl *ring = new TAdRicoRingCtrl(this);
    ring_controller = ring;
    if (ring_controller != NULL)
        ring_controller->start_fade_all(2.0f * (f32)timing_rate);
    new TAdEndText(this);
}

void TEnding__sub_8008C9F8() {}
