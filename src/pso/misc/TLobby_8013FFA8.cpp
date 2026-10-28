#include "pso/map/FloorResourceCallbacks.h"
#include "pso/misc/TLobby_8013FFA8.h"
#include "pso/misc/TLobby_80207DA8.h"
#include "pso/misc/TLobby_802268F4.h"
#include "pso/misc/TShopGetItemWindow_8021EEE4.h"
#include "pso/unk/text_8006EBC4.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/misc/TLobby.h"
#include "pso/TBoss4CheckEmpty.h"
#include "pso/TObjBoss5Ctrl.h"
#include "pso/TObjRainCtrl.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/object/TObjLight_80133568.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/object/TObjBgmColCtrl.h"
#include "pso/map/FloorArea.h"

struct Light_801401D0 {
    f32 dir[3];
    f32 pad[3];
    f32 amb[3];
    f32 c[4];
    f32 d[4];
};

extern "C" {
s32 load_floor_sound_bank();
s32 play_area_music(s32 *);
s32 is_split_screen();
extern s32 lbl_8043F198[];
extern s32 lbl_8043F1A8[];
s32 call_funcs_reverse__6TLobbyFPvUi(s32 *, s32);
extern s32 dragon_area_scene_callbacks[];
extern s32 lbl_804A7360[];
s32 __ct__16TBoss3VoloptCtrlFv();
u32 __nw__7TObjectFUl(s32);
s32 run_load_callback_table(s32 *, s32);
extern s32 lbl_8043F1C8[];
s32 forward_floor_2CB44__6TLobbyFv();
}
void TLobby::set_range(int a1, int a2, int a3) { *(int*)((char*)this + 0x7220) = a1; *(int*)((char*)this + 0x7224) = a3; *(int*)((char*)this + 0x7228) = (a1 + a2); }
void TLobby::update_floor() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }
extern s32 lbl_8043F1B8[];

extern s32 lbl_8043F188[];

s32 ship_scene_update(void) {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    if (is_split_screen() != 0) {
        play_area_music(lbl_8043F188);
    } else {
        init_music_sequencer(3);
    }
    TBoss4DarkFalz::dispatch_by_main_phase(0x30);
    return 1;
}

void TLobby::update_floor_a() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }
s32 init_ship_scene(void) {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    if (is_split_screen() != 0) {
        play_area_music(lbl_8043F198);
    } else {
        init_music_sequencer(3);
    }
    return 1;
}

void TLobby::update_floor_state() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }
s32 load_scene_ship_b(void) {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    if (is_split_screen() != 0) {
        play_area_music(lbl_8043F1A8);
    } else {
        init_music_sequencer(3);
    }
    return 1;
}
void cleanup_dragon_area_scene(void) {
    TLobby::refresh_render_state();
    TLobby::stop_audio_streams();
    stop_cue_stream();
    call_funcs_reverse__6TLobbyFPvUi(dragon_area_scene_callbacks, 8);
    TLobby::update_current_floor();
    unload_current_floor_resources();
    TLobby::clear_session_buffers();
}

s32 init_dragon_area_scene(void) {
    Light_801401D0 l;
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    run_load_callback_table(dragon_area_scene_callbacks, 8);
    if (TObjEneDD::check_v2_mode() == 0) {
        l.dir[0] = -1.45f;
        l.dir[1] = 2.8f;
        l.dir[2] = -0.4f;
        l.amb[0] = 1.0f;
        l.amb[1] = 0.96f;
        l.amb[2] = 0.3f;
        l.d[0] = 1.0f;
        l.d[1] = 0.1f;
        l.d[2] = 0.24f;
        l.d[3] = 0.4f;
        l.c[0] = 1.0f;
        l.c[1] = 1.0f;
        l.c[2] = 0.51f;
        l.c[3] = 0.4f;
    } else {
        l.dir[0] = -1.45f;
        l.dir[1] = 2.8f;
        l.dir[2] = -0.4f;
        l.amb[0] = 1.0f;
        l.amb[1] = 0.96f;
        l.amb[2] = 0.75f;
        l.d[0] = 1.0f;
        l.d[1] = 0.1f;
        l.d[2] = 0.24f;
        l.d[3] = 0.4f;
        l.c[0] = 1.0f;
        l.c[1] = 0.85f;
        l.c[2] = 1.0f;
        l.c[3] = 1.0f;
    }
    init_map_lights((u8 *)&l);
    TLobby::create_tasks();
    forward_floor_2CB44__6TLobbyFv();
    play_area_music(lbl_8043F1B8);
    return 1;
}

void TLobby__sub_80140308(void) {
    TLobby::refresh_render_state();
    TLobby::stop_audio_streams();
    call_funcs_reverse__6TLobbyFPvUi(lbl_804A7360, 8);
    unload_current_floor_resources();
    TLobby::update_current_floor();
    TLobby::clear_session_buffers();
}

s32 TLobby::setup_area() {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    run_load_callback_table(lbl_804A7360, 8);
    init_area_lights();
    TLobby::create_tasks();
    TLobby::create_boss2_tunnel();
    TLobby__sub_801403B4(0);
    play_area_music(lbl_8043F1C8);
    return 1;
}

void TLobby__sub_801403B4(s32 _w0) {  }
void TLobby__sub_801403B8(void) { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); stop_cue_stream(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }
s32 TLobby::spawn_boss3_volopt_ctrl() {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    if (__nw__7TObjectFUl(0x24) != 0U) {
        __ct__16TBoss3VoloptCtrlFv();
    }
    return 1;
}
void TLobby::reset_subsystems() { TParticleCtrl::free_heap(); TLobby::refresh_render_state(); TLobby::stop_audio_streams(); stop_cue_stream(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }
s32 TLobby::init_lobby_scene() {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    TParticleCtrl::init_heap((void *)0x10000);
    TBoss4CheckEmpty::create();
    return 1;
}
