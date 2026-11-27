#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponSBerillsHands.h"
#include "pso/system/movie/TEndingMovie.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/ui/frontend/EndingSequence.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/system/movie/TMovie.h"
#include "pso/system/main_loop.h"
#include "pso/ui/frontend/TAdEndText.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/network/TLobby.h"
#include "pso/system/ControllerInput.h"
#include "pso/render/gjSystem.h"
#include "pso/system/AsyncFileRead.h"
#include "pso/render/GinjaView.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/window/SmallFontText.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"
#include "pso/system/MallocLoadFilePrc.h"

// Built with -inline off,deferred: functions are written last to first.

s32 ending_sequence_active;
s32 ending_movie_active_flag;

void start_ending_sequence(void) {
    ending_sequence_active = 1;
    set_screen_size(1.0f, 0.85f);
    set_copy_clear_color_argb(0, 0, 0);
    reset_controller_input_state();
    set_queued_main_phase(2);
    set_fallback_main_phase(2);
    TAdEndText::load_ending_font();
    update_keyboard_menu();
    set_ending_callback();
    new TEndingMovie;
    render_tick();
}

void update_ending_sequence() {
    begin_gx_frame();
    controller_stuff();
    update_keyboard_input_frame();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render();
    main_task.render_screen_overlay();
    process_async_file_reads();
    if (static_cast<s8>(poll_reset_request()) != 0) {
        switch_to_fallback_main_phase();
    }
    if (is_ready() != 0) {
        request_main_phase(0);
    }
    render_tick();
}

void exit_ending_sequence() { ending_sequence_active = 0; main_task.delete_layer_children(); free_ending_callback(); free_keyboard_soft_resources(); TAdEndText::free_resources(); render_tick(); }

TEndingMovie::TEndingMovie() : TObject(tl_04) {
    ending_movie_active_flag = 0;
    switch (game_difficulty_selection) {
    case 0:
    case 1:
    case 2:
        new TMovie(tl_00, "ending_normal.sfd", TEndingMovie::finish_movie, 0, 1, 0);
        break;
    case 3:
        new TMovie(tl_00, "ending_normal.sfd", TEndingMovie::finish_movie, 0, 0, 0);
        break;
    }
}

TEndingMovie::~TEndingMovie() {}

void TEndingMovie::run_task() {}

void TEndingMovie::finish_movie(TMovie *movie) {
    movie->queue_destruction();
    if (ending_movie_active_flag != 0) {
        request_main_phase(2);
        return;
    }
    set_queued_main_phase(2);
    request_main_phase(0x12);
}

void TEndingMovie::render() {}

NJS_TEXLIST *get_shared_capture_texture_list(void) {
    return &shared_capture_texture_list;
}

TItemWeaponSBerillsHands::~TItemWeaponSBerillsHands() {}

TItem *create_s_berills_hands_weapon(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSBerillsHands(tl_05, item);
    }
    return NULL;
}

TItemWeaponSBerillsHands::TItemWeaponSBerillsHands(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(1);
    if (get_item_index() == 1) {
        set_weapon_flags(0x800);
    }
    charge_ticks = 5;
    sway_offset = 0;
    sway_angle = 0;
}

void TItemWeaponSBerillsHands::transform_model_node() {
    s32 player_list;
    if (charge_ticks == 0) {
        player_list = get_model_node_counter();
        begin_particle_tev();
        load_projection_tex(182.04445f * (f32)(sway_offset + player_list * 3));
    }
}

void TItemWeaponSBerillsHands::update_weapon() {
    if (charge_ticks > 0) {
        if (get_item_index() == 1) {
            charge_ticks--;
            if (charge_ticks == 0) {
                set_weapon_flags(0x800);
            }
        }
    } else {
        sway_angle += 0xB6;
        sway_offset = 182.0f * sin_table_lookup(sway_angle);
    }
}

void TItemWeaponSBerillsHands::draw_held_model() {
    NJS_OBJECT *model = item_model;
    draw_weapon_model();
    item_model = second_model;
    draw_weapon_at_joint(0x23);
    item_model = model;
}

void TItemWeaponSBerillsHands::emit_marker_effects() {
    charge_ticks = 5;
    clear_weapon_flags(0x800U);
}
