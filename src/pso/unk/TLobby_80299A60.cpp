#include "types.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/map/FloorArea.h"
#include "pso/boss/olgaflow/TBoss6EmptyWarp.h"
#include "pso/unk/TLobby.h"
#include "pso/system/TLoadCtrl_80227390.h"

extern "C" {
s32 is_split_screen();
s32 load_floor_sound_bank();
s32 create_instance__10TSceneSoraFPv(void*, s32);
void fn_802FE9E0(void);
void fn_802FEA0C(void);
}
void init_area_lights(void);
s32 load_dragon2_scene(void);
void stop_cue_stream(void);
void create_boss8_demo_objects(void);

void TLobby::refresh_lobby_state() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); stop_cue_stream(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }

extern s32 tl_particlemodel;

s32 TLobby::init_particle_model() {
    void* obj;
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    if ((is_split_screen() == 0) && ((obj = TObject::operator new(0x3C)) != 0)) {
        create_instance__10TSceneSoraFPv(obj, tl_particlemodel);
    }
    TBoss6EmptyWarp::create();
    return 1;
}

void TLobby::update_field_state() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); stop_cue_stream(); fn_802FE9E0(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }

s32 load_dragon2_scene(void) {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    fn_802FEA0C();
    init_area_lights();
    TLobby::create_tasks();
    create_boss8_demo_objects();
    play_area_music("dragon2.adx");
    return 1;
}
