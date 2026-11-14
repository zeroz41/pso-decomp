#include "types.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_8013FFA8.h"
#include "pso/system/TLoadCtrl_80227390.h"

extern "C" {
s32 is_split_screen();
s32 load_floor_sound_bank();
s32 create_instance__10TSceneSoraFPv(void*, s32);
void fn_802F105C(void);
s32 fn_802F1084();
}
void init_area_lights(void);
s32 init_scene_delo2(void);
void stop_cue_stream(void);
void init_scene_boss2_tunnel(void);

extern s32 tl_particlemodel;

void TLobby::update_subsystems() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); stop_cue_stream(); fn_802F105C(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }

s32 init_scene_delo2(void) {
    void *obj;
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_scene_boss2_tunnel();
    init_area_lights();
    TLobby::create_tasks();
    fn_802F1084();
    TLobby__sub_801403B4(0);
    play_area_music("delo2.adx");
    if ((is_split_screen() == 0) && ((obj = TObject::operator new(0x3C)) != 0)) {
        create_instance__10TSceneSoraFPv(obj, tl_particlemodel);
    }
    return 1;
}
