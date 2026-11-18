#include "pso/map/FloorResourceCallbacks.h"
#include "pso/unk/TLobby_801404CC.h"
#include "pso/unk/TLobby_8013FFA8.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/ui/city/TShopGetItemWindow_8021EEE4.h"
#include "pso/unk/text_8006EBC4.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/boss/galgryphon/TObjBoss5Ctrl.h"
#include "pso/object/ambient/TObjRainCtrl.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/object/collision/TObjBgmColCtrl.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/item/shop/ShopWeaponStock.h"
#include "pso/unk/text_8020EE2C.h"
#include "pso/item/shop/ShopToolStock.h"
#include "pso/object/city/CityTraffic.h"
#include "pso/quest/TQuestListChallenge.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdMcSelectGC.h"
#include "pso/ui/frontend/TAdBackGC_8029A6EC.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/unk/TLobby_802A0F3C.h"


struct Light_80140514 {
    f32 dir[3];
    f32 pad[3];
    f32 amb[3];
    f32 c[4];
    f32 d[4];
};

extern "C" {
s32 load_floor_sound_bank();
s32 play_area_music(s32 *);
extern void (*gryphon_area_cleanup_callbacks[])(void);
s32 is_quest_active();
extern s32 lbl_8043F1D8[];
extern s32 lbl_8043F1E8[];
extern s32 lbl_8043F1F8[];
extern s32 lbl_8043F208[];
void TTecRaFoie__sub_80226254(void);
extern void (*TLobby_scene_load_callback_table[])(void);
s32 run_load_callback_table(void *, s32);
s32 __ct__13TQuestBgmCtrlFP7TObject(void *, s32);
s32 construct_traffic_manager(void *, s32);
extern s32 lobby_rule_settings[];
extern s32 tl_05;
extern s32 tl_07;
extern s32 lbl_8043F218[];
extern s32 lbl_8043F228[];
extern void (*lobby_floor_scene_callbacks[])(void);
extern s32 lbl_8043F238[];
extern s32 lbl_8043F248[];
extern s32 lbl_8043F258[];
}
void TLobby::cleanup_floor_state() {
    TLobby::refresh_render_state();
    TLobby::stop_audio_streams();
    stop_cue_stream();
    TLobby::call_funcs_reverse(gryphon_area_cleanup_callbacks, 8);
    TParticleCtrl::free_heap();
    TLobby::update_current_floor();
    unload_current_floor_resources();
    TLobby::clear_session_buffers();
}

s32 TLobby::init_gryphon_area() {
    Light_80140514 l;
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    TParticleCtrl::init_heap((void *)0x100000);
    run_load_callback_table(gryphon_area_cleanup_callbacks, 8);
    l.dir[0] = -0.46f;
    l.dir[1] = 0.88f;
    l.dir[2] = -0.13f;
    l.amb[0] = 1.0f;
    l.amb[1] = 1.0f;
    l.amb[2] = 0.15f;
    l.d[0] = 1.0f;
    l.d[1] = 0.1f;
    l.d[2] = 0.24f;
    l.d[3] = 0.4f;
    l.c[0] = 1.0f;
    l.c[1] = 0.64f;
    l.c[2] = 0.7f;
    l.c[3] = 0.74f;
    init_map_lights((u8 *)&l);
    TLobby::create_tasks();
    TObjRainCtrl::create();
    TObjBoss5Ctrl::create();
    play_area_music(lbl_8043F1D8);
    return 1;
}

void TLobby::run_floor_update() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); TLobby::update_current_floor(); unload_current_floor_resources(); TLobby::clear_session_buffers(); }
s32 init_cave_b_stage(void) {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    TLobby__sub_801403B4(0);
    if (is_split_screen() != 0) {
        play_area_music(lbl_8043F1E8);
    } else {
        init_music_sequencer(1);
    }
    if ((get_main_phase() != 0xE) || (is_quest_active() == 0)) {
        TBoss4DarkFalz::dispatch_by_main_phase(0x1E);
    }
    return 1;
}

void TLobby::update_floor_and_windows() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); TLobby::update_current_floor(); unload_current_floor_resources(); TLobby::clear_session_buffers(); }
s32 load_scene_cave_b(void) {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    TLobby__sub_801403B4(0);
    if (is_split_screen() != 0) {
        play_area_music(lbl_8043F1F8);
    } else {
        init_music_sequencer(1);
    }
    return 1;
}

void TLobby::update_scene() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); TLobby::update_current_floor(); unload_current_floor_resources(); TLobby::clear_session_buffers(); }
s32 init_stage_cave_b(void) {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    TLobby__sub_801403B4(0);
    if (is_split_screen() != 0) {
        play_area_music(lbl_8043F208);
    } else {
        init_music_sequencer(1);
    }
    return 1;
}

void TLobby::cleanup_boss3_scene() {
    TLobby::refresh_render_state();
    TLobby::stop_audio_streams();
    TTecRaFoie__sub_80226254();
    TLobby::call_funcs_reverse(TLobby_scene_load_callback_table, 0x60);
    unload_current_floor_resources();
    TLobby::update_current_floor();
    TLobby::clear_session_buffers();
}
s32 TLobby::setup_scene() {
    void *obj;
    get_current_floor_area();
    load_floor_sound_bank();
    TLobby__sub_80207E44();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    init_shop_world_context();
    run_load_callback_table(TLobby_scene_load_callback_table, 0x60);
    ((TLobby *)lobby_rule_settings)->reset_settings_to_default();
    TLobby::create_tasks();
    TObjBgmColCtrl::create_controller();
    if (((s32)get_current_floor_area()) == AREA_PIONEER2_EP1) {
        obj = ((void *)TObject::operator new(0x78));
        if (obj != NULL) {
            construct_traffic_manager(obj, tl_05);
        }
    }
    obj = ((void *)TObject::operator new(0x1C));
    if (obj != NULL) {
        __ct__13TQuestBgmCtrlFP7TObject(obj, tl_05);
    }
    fn_8006EBC4(tl_07);
    return 1;
}
void TLobby::update_floor_objects() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }
s32 init_stage_forest_b(void) {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    if (is_split_screen() != 0) {
        play_area_music(lbl_8043F218);
    } else {
        init_music_sequencer(0);
    }
    TBoss4DarkFalz::dispatch_by_main_phase(0x14);
    return 1;
}

void TLobby::update_all() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }
s32 init_forest_b(void) {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    TObjRainCtrl::create();
    TLobby__sub_801403B4(0);
    if (is_split_screen() != 0) {
        play_area_music(lbl_8043F228);
    } else {
        init_music_sequencer(0);
    }
    return 1;
}

void TLobby::update_floor_download() {
    TQuestVmDownLoadServer::free_download_buffers();
    unload_current_floor_resources();
    TLobby::update_current_floor();
    TLobby::call_funcs_reverse(lobby_floor_scene_callbacks, 0x30);
    TLobby::stop_audio_streams();
    TLobby::refresh_render_state();
    TLobby::stop_audio_streams();
    TLobby::clear_session_buffers();
}
s32 TLobby::init_lobby_floor_scene() {
    get_current_floor_area();
    load_floor_sound_bank();
    if (run_load_callback_table(lobby_floor_scene_callbacks, 0x30) == 0) {
        return 0;
    }
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TQuestVmDownLoadServer::reset_download_state();
    ((TLobby *)lobby_rule_settings)->reset_settings_to_default();
    TLobby::create_tasks();
    TObjBgmColCtrl::create_controller();
    TLobby__sub_801403B4(0);
    return 1;
}
void TLobby::update_floor_alt() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); TLobby::update_current_floor(); unload_current_floor_resources(); TLobby::clear_session_buffers(); }
s32 init_machine_scene(void) {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    TLobby__sub_801403B4(0);
    if (is_split_screen() != 0) {
        play_area_music(lbl_8043F238);
    } else {
        init_music_sequencer(2);
    }
    if ((get_main_phase() != 0xE) || (is_quest_active() == 0)) {
        TBoss4DarkFalz::dispatch_by_main_phase(0x28);
    }
    return 1;
}

void TLobby::update_floor_b() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); TLobby::update_current_floor(); unload_current_floor_resources(); TLobby::clear_session_buffers(); }
s32 init_machine_b_scene(void) {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    TLobby__sub_801403B4(0);
    if (is_split_screen() != 0) {
        play_area_music(lbl_8043F248);
    } else {
        init_music_sequencer(2);
    }
    return 1;
}

void TLobby::refresh_floor_state() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }

// inferred: the VERSUS01/SPACE01/SPACE02 init of area_initializer_dispatch_table
s32 init_spaceship_area(void) {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    if ((get_main_phase() != 0xE) || (is_quest_active() == 0)) {
        switch (get_current_floor_area()) {
        case AREA_VR_SPACESHIP_BETA:
            TBoss4DarkFalz::dispatch_by_main_phase(0x4E);
            break;
        }
    }
    if (is_split_screen() != 0) {
        play_area_music(lbl_8043F258);
    } else if (TLobby::get_instance() == 1) {
        init_music_sequencer(8);
    }
    return 1;
}
void TLobby::run_floor_update_2() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }


extern "C" {
void alloc_item_buffers__18TCheckRoomSequenceFv(void);
void TCheckRoomSequence__sub_80211284(void);
void TLobby__sub_80184DF4(void);
}
void load_judge_item(void);

void (*gryphon_area_cleanup_callbacks[2])(void) = {
    TLobby::cleanup_boss5_pillars, TLobby::cleanup_pillar_demo,
};

void (*TLobby_scene_load_callback_table[24])(void) = {
    TLobby::create_named_lobby_object, TLobby::free_singleton,
    load_weapon_random_tables, TLobby::free_lobby_resources,
    load_armor_random_table, TLobby::free_rocks,
    load_tool_random_rel, TLobby::free_all_rocks,
    load_judge_item, TLobby::free_window,
    TLobby::clear_flag_if_not_split_screen, TLobby::free_global,
    reset_globals2__19TQuestListChallengeFv, reset_globals__19TQuestListChallengeFv,
    TLobby__sub_80184DF4, TLobby::free_buffers,
    alloc_item_buffers__18TCheckRoomSequenceFv, TCheckRoomSequence__sub_80211284,
    measure_traffic_path_lengths, free_buffer_pair_table,
    TQuestVmDownLoadServer::reset_download_state, TQuestVmDownLoadServer::free_download_buffers,
    TLobby::alloc_buffer, TLobby::free_buffer,
};

void (*lobby_floor_scene_callbacks[12])(void) = {
    TLobby::update_photon_chair, TLobby::update_photon_chairs,
    TLobby::alloc_download_server, TLobby::free_single_player_chr_select,
    register_texture_f256_ad_pic_2, TAdSinglePlyChrSelectGC::free_global,
    register_texture_f256_backtext, TAdSinglePlyChrSelectGC::free_singleton_805D65C0,
    TLobby__sub_802A0F70, TLobby::free_dialog_global,
    TAdMcSelectGC::close, TAdMcSelectGC::open,
};
