#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TScreenFadeOut.h"
#include "pso/unk/TScreenFadeIn.h"
#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_80131C58.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TitleSceneTables.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/camera/CameraViewParams.h"
#include "pso/unk/TLobby_803360CC.h"
#include "pso/unk/TUnk_804EE470.h"
#include "pso/ui/TUnk_804EE458.h"
#include "pso/ui/frontend/TAdTrialAgreementGC_80335958.h"
#include "pso/unk/TTitleScene.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/text_802A1144.h"
#include "pso/ui/frontend/TTitleBackground.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/item/TItemReverseTechCtrl.h"
#include "pso/enemy/dolmolm/TObjEneDolmOlm.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/object/TObjLuker.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/TLobby_80335E08.h"
#include "pso/unk/text_803369C8.h"
#include "pso/effect/particle/TParticleCtrl.h"


extern "C" {


    extern int lobby_game_mode_state;
int TAdSinglePlyChrSelectGC::get_data() {  return lobby_game_mode_state; }

s8 TAdSinglePlyChrSelectGC__sub_8033605C(void) { return 0; }


s32 TTitleScene::start_offline_seq() {
    if (!(transition_flags & 2)) {
        new TScreenFadeOut(tl_fade, TLobby::queue_destruction_and_cleanup);
        transition_flags |= 2;
    }
    return transition_flags & 4;
}

}

struct TCameraCtrl;


NJS_TEXNAME title_texture_entries[21] = {
    {(char *)"f256_ad", 0, 0},
    {(char *)"f256_psotitle", 0, 0},
    {(char *)"f256_psotitle02", 0, 0},
    {(char *)"f256_titlealpha01", 0, 0},
    {(char *)"f256_titlealpha02", 0, 0},
    {(char *)"f256_titlealpha03", 0, 0},
    {(char *)"f256_titlealpha04", 0, 0},
    {(char *)"f256_titlealpha05", 0, 0},
    {(char *)"f256_titlealpha06", 0, 0},
    {(char *)"f256_titlealpha07", 0, 0},
    {(char *)"f256_titlealpha08", 0, 0},
    {(char *)"f512_mahoujin", 0, 0},
    {(char *)"f512_mahoujin_b", 0, 0},
    {(char *)"s256_1st_title01", 0, 0},
    {(char *)"s256_1st_title02", 0, 0},
    {(char *)"s256_1st_title03", 0, 0},
    {(char *)"s256_1st_title04", 0, 0},
    {(char *)"s256_1st_title05", 0, 0},
    {(char *)"s256_1st_title06", 0, 0},
    {(char *)"s256_1st_title07", 0, 0},
    {(char *)"s256_1st_title08", 0, 0},
};

__declspec(section ".data") NJS_TEXLIST title_texture_list = {title_texture_entries, 21};

// One scene resource: load runs front to back (run_load_callback_table),
// release back to front (call_funcs_reverse); field names inferred from those.
struct LobbyLoadCallback {
    void (*load)(void);
    void (*release)(void);
};

LobbyLoadCallback lobby_load_callback_table[4] = {
    {TLobby__sub_80335E78, TLobby__sub_80335E74},
    {clear_lobby_global_flags, TLobby__sub_80336E44},
    {TLobby__sub_80335FE4, TLobby__sub_80335FE0},
    {TLobby__sub_80336E68, TLobby__sub_80336E64},
};

typedef void (TTitleScene::*TitleStateHandler)();

// Indexed by lobby_game_mode_state (each handler stores its own index).
TitleStateHandler state_handler_pmf_table[4] = {
    &TTitleScene::enter_chg_game_mode,
    &TTitleScene::enter_game_mode_change,
    &TTitleScene::request_change_game_mode,
    &TTitleScene::open_keyboard,
};

// Sprite cells of the title textures (size, centre, uv rectangle, texture id),
// shared by every lobby_record_table sprite.
NJS_TEXANIM title_sprite_frames[46] = {
    {256, 256, 0, 0, 0, 0, 256, 256, 0, 0},
    {256, 256, 0, 0, 0, 0, 256, 256, 1, 0},
    {256, 256, 0, 0, 0, 0, 256, 256, 2, 0},
    {256, 256, 0, 0, 0, 0, 256, 256, 3, 0},
    {128, 128, 0, 0, 0, 0, 256, 256, 4, 0},
    {128, 128, 0, 0, 0, 0, 256, 256, 5, 0},
    {128, 128, 0, 0, 0, 0, 256, 256, 6, 0},
    {128, 128, 0, 0, 0, 0, 256, 256, 7, 0},
    {256, 96, 0, 0, 0, 0, 255, 95, 8, 0},
    {256, 160, 0, 0, 0, 96, 255, 255, 8, 0},
    {256, 32, 0, 0, 0, 0, 255, 31, 0, 0},
    {256, 32, 0, 0, 0, 32, 255, 63, 0, 0},
    {256, 32, 0, 0, 0, 64, 255, 95, 0, 0},
    {256, 32, 0, 0, 0, 96, 255, 127, 0, 0},
    {256, 32, 0, 0, 0, 128, 255, 159, 0, 0},
    {16, 18, 0, 0, 0, 224, 15, 241, 0, 0},
    {16, 18, 0, 0, 0, 224, 15, 241, 0, 0},
    {16, 18, 0, 0, 0, 224, 15, 241, 0, 0},
    {16, 18, 0, 0, 0, 224, 15, 241, 0, 0},
    {16, 18, 0, 0, 16, 224, 31, 241, 0, 0},
    {16, 18, 0, 0, 16, 224, 31, 241, 0, 0},
    {16, 18, 0, 0, 16, 224, 31, 241, 0, 0},
    {16, 18, 0, 0, 16, 224, 31, 241, 0, 0},
    {16, 18, 0, 0, 32, 224, 47, 241, 0, 0},
    {16, 18, 0, 0, 32, 224, 47, 241, 0, 0},
    {16, 18, 0, 0, 32, 224, 47, 241, 0, 0},
    {16, 18, 0, 0, 32, 224, 47, 241, 0, 0},
    {16, 18, 0, 0, 49, 224, 64, 241, 0, 0},
    {16, 18, 0, 0, 49, 224, 64, 241, 0, 0},
    {16, 18, 0, 0, 49, 224, 64, 241, 0, 0},
    {16, 18, 0, 0, 49, 224, 64, 241, 0, 0},
    {16, 18, 0, 0, 65, 224, 80, 241, 0, 0},
    {16, 18, 0, 0, 65, 224, 80, 241, 0, 0},
    {16, 18, 0, 0, 65, 224, 80, 241, 0, 0},
    {16, 18, 0, 0, 65, 224, 80, 241, 0, 0},
    {16, 18, 0, 0, 81, 224, 96, 241, 0, 0},
    {16, 18, 0, 0, 81, 224, 96, 241, 0, 0},
    {16, 18, 0, 0, 81, 224, 96, 241, 0, 0},
    {16, 18, 0, 0, 81, 224, 96, 241, 0, 0},
    {128, 24, 0, 0, 0, 128, 127, 151, 0, 0},
    {16, 18, 0, 0, 128, 32, 144, 50, 0, 0},
    {16, 18, 0, 0, 144, 32, 160, 50, 0, 0},
    {16, 18, 0, 0, 160, 32, 176, 50, 0, 0},
    {16, 18, 0, 0, 49, 224, 55, 242, 0, 0},
    {16, 18, 0, 0, 55, 224, 71, 242, 0, 0},
    {16, 18, 0, 0, 87, 224, 103, 242, 0, 0},
};

// Title screen sprites; TLobby::get_record hands one to draw_with_camera.
// The Ninja sprite table references the Ginja texture list at its original address.
#define TITLE_SPRITE_TEXTURE_LIST reinterpret_cast<NJS_TEXLIST *>(&title_texture_list)
NJS_SPRITE lobby_record_table[46] = {
    {{0.0f, -16.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{0.0f, 240.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{256.0f, -16.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{256.0f, 240.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{512.0f, -16.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{512.0f, 112.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{512.0f, 240.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{512.0f, 368.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{96.0f, 172.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{352.0f, 172.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{193.0f, 338.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{193.0f, 300.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{193.0f, 332.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{193.0f, 364.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{193.0f, 396.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{192.0f, 308.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{192.0f, 340.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{192.0f, 372.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{192.0f, 404.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{208.0f, 308.0f, 0.0f}, 14.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{208.0f, 340.0f, 0.0f}, 14.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{208.0f, 372.0f, 0.0f}, 14.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{208.0f, 404.0f, 0.0f}, 14.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{432.0f, 308.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{432.0f, 340.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{432.0f, 372.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{432.0f, 404.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{192.0f, 308.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{192.0f, 340.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{192.0f, 372.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{192.0f, 404.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{208.0f, 308.0f, 0.0f}, 14.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{208.0f, 340.0f, 0.0f}, 14.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{208.0f, 372.0f, 0.0f}, 14.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{208.0f, 404.0f, 0.0f}, 14.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{432.0f, 308.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{432.0f, 340.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{432.0f, 372.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{432.0f, 404.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{259.0f, 415.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{208.0f, 418.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{224.0f, 418.0f, 0.0f}, 12.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{416.0f, 418.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{192.0f, 418.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{208.0f, 418.0f, 0.0f}, 12.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
    {{432.0f, 418.0f, 0.0f}, 1.0f, 1.0f, 0, TITLE_SPRITE_TEXTURE_LIST, title_sprite_frames},
};
#undef TITLE_SPRITE_TEXTURE_LIST

// Texture archive per language (Japanese, then English for the others);
// initialize_lobby_title_scene copies the whole table before indexing it.
const TitleTextureFilenameTable title_texture_filename_table = {
    {"Title", "Title_eng", "Title_eng", "Title_eng", "Title_eng"},
};


typedef struct {
    s32 pad0[2];
    f32 f8, fC;
    s32 pad10[6];
    f32 f28, f2C, f30, f34, f38, f3C, f40, f44;
} Cam_80336520;

extern "C" {
void request_main_phase(s32 arg0);
TTitleScene *title_scene_instance;
int lobby_game_mode_state;
NJS_TEXLIST *lobby_title_texture_list;
    extern int lbl_805D68C8;
s32 release_texture_list(void *, s32);
u64 call_funcs_reverse__6TLobbyFPvUi(void *, int);
void hide_title_layers_and_release(TTitleScene *scene);
int TKeyBoardControl__sub_8000F828(void);
void TKeyBoardControl__sub_8000F90C(int);

void TWindowOptionCtrl__sub_802273B4(s32 arg0);
s32 run_load_callback_table(void *, int);
extern const s32 current_language;

void TLobby::queue_destruction_and_cleanup(TObject *fade) {
    fade->queue_destruction();
    if (title_scene_instance != NULL) {
        hide_title_layers_and_release(title_scene_instance);
    }
}

void TLobby::destroy_download_server(TObject *fade) {
    fade->queue_destruction();
    if (title_scene_instance != NULL) {
        title_scene_instance->set_flag_and_clear_download();
    }
}

void hide_title_layers_and_release(TTitleScene *scene) {
    scene->transition_flags |= 4;
    if (scene->title_layer != NULL) {
        scene->title_layer->disallow_rendering();
    }
    if (scene->transition_controller != NULL) {
        scene->transition_controller->disallow_rendering();
    }
    if (scene->overlay_layer != NULL) {
        scene->overlay_layer->disallow_rendering();
    }
    for (s32 i = 0; i != 3; i++) {
        if (scene->transition_children[i] != NULL) {
            scene->transition_children[i]->queue_destruction();
            scene->transition_children[i] = NULL;
        }
    }
}

void TTitleScene::set_flag_and_clear_download() {
    transition_flags |= 1;
    if (transition_controller != NULL) {
        // This shared out-of-line helper clears the common TObject update flag.
        transition_controller->clear_update_suspension();
    }
}

void TLobby__sub_803361FC(void) {  }
void TTitleScene::open_keyboard() { lobby_game_mode_state = 3; request_main_phase(19); }
void TTitleScene::request_change_game_mode() { lobby_game_mode_state = 2; TAdMultiChgGameModeGC::set_mode_change_state(); }
void TTitleScene::enter_game_mode_change() { lobby_game_mode_state = 1; TAdMultiChgGameModeGC::set_game_mode_state(); }
void TTitleScene::enter_chg_game_mode() { lobby_game_mode_state = 0; TAdMultiChgGameModeGC::set_mode_0x15(); }
void TLobby__sub_803362A4(TTitleScene *scene) {
    if (TAdTrialAgreementGC__sub_80335958(scene->transition_controller) != 0) {
        TKeyBoardControl__sub_8000F90C(2);
        if (scene->start_offline_seq() != 0) {
            ((void (*)(void *))TLobby__sub_803361FC)(scene);
            TitleStateHandler handler = state_handler_pmf_table[TLobby__sub_80336030(scene)];
            (scene->*handler)();
        }
    }
}
void TTitleScene::render() {  }

void TTitleScene::run_task() {
    TAdMultiChgGameModeGC::set_default_camera();
    if (TAdPlayerLoadGC::probe_card_slot(0) == 0) {
        for (s32 i = 0; i != 3; i++) {
            if (transition_children[i] != NULL) {
                transition_children[i]->queue_destruction();
                transition_children[i] = NULL;
            }
        }
        TAdMultiChgGameModeGC::request_scene_change();
        return;
    }
    if (attract_tick < m_38) {
        if ((hardware_keyboard_state.has_any_key_pressed() != 0) || (TKeyBoardControl::any_pad_input_active() != 0)) {
            attract_tick = 0;
        }
        TLobby__sub_803362A4(this);
    }
    if (m_38 == attract_tick) {
        transition_controller->suspend_update();
        TWindowOptionCtrl__sub_802273B4(0x1E);
    }
    if (m_38 < attract_tick && start_offline_seq() != 0) {
        TKeyBoardControl__sub_8000F90C(2);
        set_opening_movie_purpose(0);
        request_main_phase(3);
    }
    attract_tick++;
}

void TTitleScene::close_auxiliary_window() {
    if (auxiliary_window != NULL) {
        auxiliary_window->queue_destruction();
        auxiliary_window = NULL;
    }
}

TTitleScene::~TTitleScene() {
    title_scene_instance = NULL;
    if (overlay_layer != NULL) {
        overlay_layer->queue_destruction();
    }
    close_auxiliary_window();
    end_view_override();
    TLobby::stop_audio_streams();
}

TTitleScene::TTitleScene(TObject *parent) : TObject(parent) {

    title_scene_instance = this;
    m_30 = 0;
    attract_tick = 0;
    auxiliary_window = NULL;
    transition_flags = 0;
    TKeyBoardControl__sub_8000F90C(1);
    TAdMultiPlyChrSelectGC::reset_slot_selections();
    TObjEneDolmOlm::reset_count();
    TAdMultiPlyChrSelectGC__sub_803367E8();
    lobby_game_mode_state = 0;
    if (TKeyBoardControl__sub_8000F828() == 0) {
        m_38 = 0x4B0;
    } else {
        m_38 = 0x320;
    }
    title_layer = new TTitleBackground(this);
    transition_controller = new TUnk_804EE458(this);
    overlay_layer = new TUnk_804EE470(tl_clipout);
    m_28 = 0;
    if (transition_controller != NULL) {
        transition_controller->suspend_update();
    }
    TAdMultiChgGameModeGC::apply_bgm_col_ctrl("title.adx");
    {
        Cam_80336520 cam;
        cam.f8 = 320.0f;
        cam.fC = 200.0f;
        cam.f28 = 640.0f;
        cam.f2C = 480.0f;
        cam.f34 = cam.f30 = 0.0f;
        cam.f38 = 20.0f;
        cam.f3C = 15.0f;
        cam.f40 = 1.0f;
        cam.f44 = 0.85f;
        ((CameraViewParams *)&cam)->begin_override();
    }
    {
        NJS_POINT3 v = {0.0f, 0.0f, -47.0f};
        transition_children[0] = create_particle_controller(&v, 0x1E3, 1);
        transition_children[1] = create_particle_controller(&v, 0x1E4, 1);
        transition_children[2] = create_particle_controller(&v, 0x1E5, 1);
    }
    new TScreenFadeIn(tl_fade, TLobby::destroy_download_server);
    TItemReverseTechCtrl::create(this);
}

void TLobby::destroy_global_object() {
    u32 value;
    value = (u32) call_funcs_reverse__6TLobbyFPvUi(lobby_load_callback_table, sizeof(lobby_load_callback_table));
    if (lobby_title_texture_list != NULL) {
        release_texture_list(lobby_title_texture_list, (s32) value);
        lobby_title_texture_list = NULL;
    }
}
}

void initialize_lobby_title_scene(void) {
    title_scene_instance = NULL;
    TLobby::update_menu_cursor();
    TitleTextureFilenameTable names = title_texture_filename_table;
    lobby_title_texture_list = &title_texture_list;
    load_streamed_prs_texture((saddr)names.archive[current_language], (saddr)&title_texture_list);
    run_load_callback_table(lobby_load_callback_table, sizeof(lobby_load_callback_table));
    TLobby::reset_counter();
    set_current_floor_area(0);
}

void TAdMultiPlyChrSelectGC__sub_803367E8(void) { lbl_805D68C8 = 0; }
