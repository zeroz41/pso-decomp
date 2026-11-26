#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/scene/OfflineGameScene.h"
#include "pso/unk/TQuestManager.h"
#include "types.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/object/warp/TObjLaboMapWarp_80185248.h"
#include "pso/network/TLobby.h"
#include "pso/unk/TLobbyAutoReply.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/technique/TTecLuker.h"
#include "pso/object/door/TObjDoor.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/frontend/TAdSelectGameModeGC.h"
#include "pso/network/client_id.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/main_loop.h"
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/scene/TScene.h"
#include "pso/system/TLoadCtrl.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayerCreate.h"
#include "pso/quest/TQuestThread.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/ui/frontend/TAdSelectGameModeGC_802C4748.h"
#include "pso/ui/frontend/TAdMultiSelGameModeGC.h"
#include "pso/unk/TLobby_80300098.h"
#include "pso/quest/challenge/TChallenge4P.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include "pso/object/base/TObjBase.h"
#include "pso/render/TFogCtrl.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8028D5D4.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/item/TItem.h"
#include "pso/unk/TLobby_8020B03C.h"
#include "pso/ui/window/TWindowKeyBoardHard_801A529C.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/chat/ShortMail.h"
#include "pso/ui/window/TSnapshotFileSetup.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/unk/TLobby_8023F734.h"
#include "pso/network/protocol/choice_search.h"
#include "pso/player/TPlayerBattleCtrl.h"
#include "pso/object/key/TOKeyJungleMain.h"
#include "pso/unk/TLobby_802D3970.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007CF0C.h"
#include "pso/ui/window/TWindowSubStatusDisp_8036D774.h"
#include "pso/boss/olgaflow/Boss6PlayerSnapshots.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/PlayerSlots.h"
#include "pso/object/warp/ForestWarpResources.h"
#include "pso/ui/frontend/TAdChrSelPlyPlateGC.h"
#include "pso/system/scene/TSceneSora.h"
#include "pso/map/TSetManager.h"
#include "pso/ui/chat/TWindowSubSymbolChat_80076F88.h"
#include "pso/ui/font/TFontSmallTask.h"
#include "pso/system/ControllerInput.h"
#include "pso/unk/TLobby_80228154.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/render/gjSystem.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"
#include "pso/map/area/AreaScene.h"
#include "pso/unk/text_801F3774.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/unk/text_800FA260.h"
#include "pso/unk/TLobby_801F3A24.h"
#include "pso/unk/text_800FA464.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/object/door/TODoorJungleMain.h"
#include "pso/network/TProtocol.h"
#include "pso/quest/QuestOpcodeHandlers.h"
#include "pso/object/door/TODoorBase.h"
#include "pso/unk/TLobby_800F8AA8.h"
#include "pso/npc/NpcPartnerControl.h"
#include "pso/player/PlayerActionProvider.h"
#include "pso/unk/TObjFreezeShell.h"
#include "pso/quest/QuestStoryFlags.h"


void TLobby::reset_keyboard_input() { TKeyBoardControl::reset(); switch_to_fallback_main_phase(); clear_keyboard_key_state(); clear_keyboard_input_flag(); TLobby::clear_counter(); }
void TLobby::shutdown_keyboard_control() { TKeyBoardControl::reset(); TLobby::reset_quest_state(); switch_to_fallback_main_phase(); clear_keyboard_key_state(); clear_keyboard_input_flag(); TLobby::clear_counter(); }
void TLobby__sub_801A2DF4(void) {  }
void TLobby__sub_801A2DF8(void) {  }
void TLobby__sub_801A2DFC(void) {  }

void recreate_split_screen_players(void) {
    if (TRaderMapCore::is_not_split_screen() == 1) {
        switch (get_game_play_mode()) {
        case 1:
        case 2: {
            s32 i;
            for (i = 0; i < 4; i++) {
                TObjPlayer *player = get_player_by_client_id(i);
                if (player != NULL) {
                    delete player;
                }
            }
            TLobby::apply_char_to_players();
            break;
        }
        }
    }
}

void TLobby::apply_char_to_players() {
    s32 slot;
    TPlyCharData *record;
    TPlyCharData *local_record;
    if (is_split_screen() != 0) {
        slot = 0;
        do {
            if (is_multiplayer_character_slot_selected(slot) != 0) {
                record = TAdSinglePlyChrSelectGC::get_char_index(slot);
                if (record != NULL) {
                    create_player_object(slot, player_control_role_base + slot, record);
                }
            }
            slot += 1;
        } while (slot < 4);
        return;
    }
    local_record = TAdSinglePlyChrSelectGC::get_char_index(local_client_id);
    if (local_record != NULL) {
        create_player_object(0, player_control_role_base, local_record);
    }
}
void TLobby::reset_quest_state() {
    TRaderMapCore::free_map_data();
    clear_switch_table();
    TTecLuker::apply_all_players();
    TLobby::reset_item_id_counters();
    TLobby::reset_floor_items();
    delete_npc_players();
    if (quest_mission_manager != NULL) {
        quest_mission_manager->queue_destruction();
    }
    clear_enabled_main_warps();
    THunterGuildSeqOffline::reset_quest_result_callbacks();
    TLobby::clear_counter();
    TLobby::reset_door_state();
    TObjDoor::reset_instance();
    TLobby::set_cleanup_flag();
    TLobby::reset_quest_counter();
    TLobby::clear_quest_state();
}


void TAdSelectGameModeGC::enable_camera() { set_view_count(1); TCameraCtrl::set_camera_id(1); TCameraCtrl::reset_mode(); }

void set_split_screen_views(int count) { set_view_count(count); TCameraCtrl::set_camera_id(count); }

s32 TCameraCtrl::get_camera_no() {
    if (is_split_screen() != 0) {
        return get_camera_mode();
    }
    return local_client_id;
}




// Load and release hooks of the offline game scene, in pairs: init_offline_game_scene runs
// each load front to back (run_load_callback_table), TLobby::teardown_scene each release
// back to front (TLobby::call_funcs_reverse).
FloorResourceCallbacks offline_game_scene_callbacks[48] = {
    {TAdSelectGameModeGC::setup_views, (FloorResourceCallback)TAdSelectGameModeGC::call_enable_camera},
    {init_game_player_actions, release_game_player_actions},
    {init_player_shared, finalize_player_shared},
    {apply_multi_sel_rule, reset_multi_sel_rule},
    {prepare_adventure_maps, release_adventure_maps},
    {clear_story_flag_list_and_reload, clear_story_flag_list},
    {start_challenge_mode, NULL},
    {load_tombstone_resources, destroy_tombstone},
    {TLobby::update_keyboard_menu, TLobby::free_keyboard_soft_resources},
    {TWindowCtrlMain::reset_windows, TWindowCtrlMain::free_all_windows},
    {TWindowCtrl::close, TWindowCtrl::shutdown},
    {reset_clock_bar_pulse, TLobby__sub_8001ED70},
    {TLobby::set_ending_callback, TLobby::free_ending_callback},
    {load_keyboard_resources, free_keyboard_resources},
    {alloc_battle_param_tables, free_battle_param_tables},
    {reset_id_counters, free_id_counters},
    {init_entity_tables, clear_entity_tables},
    {init_scene_fog_system, TFogCtrl::reset},
    {load_light_entry_file, TObjLight::free_shared_data},
    {alloc_quest_download_buffer, TLobby::free_chr_select_singleton},
    {TLobby::load_item_data, free_forest_rel_work_buffer},
    {init_item_drop_tables, free_item_drop_tables},
    {init_item_system, free_item_system},
    {TLobby::create_heap_8000, TLobby::free_heap},
    {TRaderMapCore::create_heap, TRaderMapCore::free_heap},
    {TLobby::load_set_gsl_files, clear_map_set_data},
    {TLobby::load_set_event_gsl, (FloorResourceCallback)TLobby::get_team_state},
    {alloc_work_buffer, free_deferred_packet_buffer},
    {TObjFreezeShell::load_freeze_ice_resource, TObjFreezeShell::free_freeze_ice_resource},
    {load_word_select_data, TWindowDD::free_buffers},
    {init_switch_table, clear_switch_table},
    {reset_shop_stock_and_params, clear_all_shop_stock},
    {THunterGuildSeqOffline::reset_quest_result_callbacks, THunterGuildSeqOffline__sub_80213410},
    {TQuestThread::clear_all_floor_handlers, TQuestThread__sub_801F5D88},
    {TObjCityMainWarp::reset, TObjCityMainWarp::free_resources},
    {(FloorResourceCallback)TLobby__sub_80225C64, (FloorResourceCallback)TLobby__sub_80225C44},
    {(FloorResourceCallback)TLobby__sub_8001DC04, (FloorResourceCallback)clear_auto_reply_flags},
    {reset_info_board_on_load, reset_info_board_on_unload},
    {(FloorResourceCallback)TWindowGetComCard__sub_8007B67C, (FloorResourceCallback)TWindowGetComCard__sub_8007B65C},
    {TLobby__sub_8024285C, TLobby::reset_state},
    {clear_received_symbol_chat, TLobby__sub_80077608},
    {reset_choice_search_data, free_choice_search_data},
    {init_char_slots, free_char_slots},
    {init_jungle_key_slots, unload_jungle_key_slots},
    {(FloorResourceCallback)TLobby__sub_802D39FC, (FloorResourceCallback)TLobby__sub_802D39DC},
    {TObjBoss2Tunnel::reset_state, TObjBoss2Tunnel::free_resources},
    {TBGMulti__ct, TLobby::release_bg_multi_textures},
    {clear_boss6_player_snapshots, NULL},
};

s32 lbl_805D5CE0;

void TLobby::reload_offline_area() {
    TObject holder;
    TObjPlayer *p;
    s32 i;
    s32 j;
    process_pending_resources();
    reset_controller_input_state();
    render_tick();
    render_tick();
    recreate_split_screen_players();
    for (i = 0; i < TLobby::get_game_mode(); i++) {
        TObjPlayer *q = TObjPlayer::get_player_data(i);
        if (q != NULL) {
            q->set_parent(&holder);
        }
    }
    if (TRaderMapCore::is_not_split_screen() == 1) {
        switch (get_game_play_mode()) {
        case 0:
            break;
        case 1:
            TLobby::destroy_global();
            break;
        case 2:
            break;
        }
    }
    TLobby::reset_quest_state();
    main_task.delete_layer_children();
    promote_area_floor(&floor_transition_state);
    TLobby::backup_story_select();
    TKeyBoardControl::update();
    TLobby::get_team_state();
    clear_floor_population();
    TLobby__sub_80207E48();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    apply_phase_keyboard_mode();
    TLoadCtrl::start_loading(1);
    reset_enemy_and_object_ids();
    TLobby::load_set_gsl_files();
    TLobby::load_set_event_gsl();
    load_battle_param_entry();
    initialize_floor_transition(&floor_transition_state, 0, 0);
    load_area_scene_and_init((u8 *)&floor_transition_state);
    TLoadCtrl::cleanup_scene();
    if (is_area_transfer_pending() != 0) {
        TLobby::reset_keyboard_state();
        TLobby::clear_callback_and_reset_keyboard();
    }
    TLobby::clear_callback_and_reset_keyboard();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    for (j = 0; j < TLobby::get_game_mode(); j++) {
        p = TObjPlayer::get_player_data(j);
        if (p != NULL) {
            p->set_parent(tl_03);
            p->reset_motion_fields();
            rebuild_player_inventory(p);
            TObjPlayer::for_each_player_slot(TObjPlayer::recover_player_full);
        }
    }
    load_battle_param_entry();
    update_main_warp_visible_mask(0);
}

void TLobby::rebuild_area_keep_players() {
    TObject holder;
    s32 i;
    s32 j;
    TObjPlayer *p;
    process_pending_resources();
    reset_controller_input_state();
    render_tick();
    render_tick();
    TObjPlayer::refresh_player_lobby_headers();
    TObjPlayer::create_active_players();
    for (i = 0; i < TLobby::get_game_mode(); i++) {
        TObjPlayer *q = TObjPlayer::get_player_data(i);
        if (q != NULL) {
            q->set_parent(&holder);
        }
    }
    main_task.delete_layer_children();
    promote_area_floor(&floor_transition_state);
    TLobby::sync_story_select();
    TAdStorySelectGC::set_state(0);
    TKeyBoardControl::update();
    TLobby::reset_quest_state();
    TLobby::get_team_state();
    clear_floor_population();
    TQuestThread::clear_all_floor_handlers();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        switch (get_game_play_mode()) {
        case 0:
            break;
        case 1:
            setup_split_screen();
            break;
        case 2:
            break;
        }
    }
    TLoadCtrl::start_loading(1);
    TQuestThread::create_by_mode();
    clear_quest_floor_designations();
    {
        TQuestThread *thread = new TQuestThread(quest_mission_manager, 0);
        thread->run_task();
    }
    TLobby::set_enemy_mode_flag();
    reset_enemy_and_object_ids();
    TLobby::setup_quest_list();
    TQuestListVM::load_vm();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        load_area_scene_and_init((u8 *)&floor_transition_state);
    } else {
        initialize_floor_transition(&floor_transition_state, 0, 0);
        load_area_scene_and_init((u8 *)&floor_transition_state);
    }
    TLoadCtrl::cleanup_scene();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    for (j = 0; j < TLobby::get_game_mode(); j++) {
        p = TObjPlayer::get_player_data(j);
        if (p != NULL) {
            p->set_parent(tl_03);
            p->reset_motion_fields();
            rebuild_player_inventory(p);
            TObjPlayer::for_each_player_slot(TObjPlayer::recover_player_full);
        }
    }
    TQuestThread::create_for_floor();
}

void run_offline_area_transfer(void) {
    TObject holder;
    s32 i;
    TObjPlayer *p;
    s32 j;
    process_pending_resources();
    reset_controller_input_state();
    render_tick();
    render_tick();
    for (i = 0; i < TLobby::get_game_mode(); i++) {
        TObjPlayer *q = TObjPlayer::get_player_data(i);
        if (q != NULL) {
            q->set_parent(&holder);
        }
    }
    main_task.delete_layer_children();
    promote_area_floor(&floor_transition_state);
    TKeyBoardControl::update();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    TLoadCtrl::start_loading(2);
    leader_selection.find_leader_section_id(designated_client_id);
    load_area_scene_and_init((u8 *)&floor_transition_state);
    unlock_main_warp_destination(get_current_floor());
    TLoadCtrl::cleanup_scene();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    for (j = 0; j < TLobby::get_game_mode(); j++) {
        p = TObjPlayer::get_player_data(j);
        if (p != NULL) {
            p->set_parent(tl_03);
            p->reset_motion_fields();
        }
    }
    TQuestThread::create_for_floor();
    if (quest_area_manager != NULL) {
        new TQuestThread(quest_area_manager, 0);
    }
}

void TLobby::teardown_scene() {
    if (is_split_screen() != 0) {
        TCameraCtrl::set_fullscreen_viewport();
    }
    reset_view_count();
    TAdSelectGameModeGC::enable_camera();
    TLobby::stop_audio_streams();
    TLobby::update_lobby_subsystems();
    TLobby::reset_quest_state();
    main_task.delete_layer_children();
    main_task.resume_layers();
    ((TObject *)tl_su)->delete_children();
    run_area_scene_cleanup(&floor_transition_state);
    TLobby::call_funcs_reverse(offline_game_scene_callbacks, sizeof(offline_game_scene_callbacks));
    clear_resource_load_tasks();
    TKeyBoardControl::update();
    render_tick();
}

void run_offline_game_frame(void) {
    begin_gx_frame();
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    debug_printf("Condition E%d", enemy_condition_count * 0xC);
    debug_printf("Condition O%d", object_condition_count * 4);
    if (is_split_screen() != 0) {
        run_split_screen_frame();
    } else {
        run_single_view_frame();
    }
    process_async_file_reads();
    update_sound_request_slots();
    TAdSinglePlyChrSelectGC::run_save_load_sequence();
    take_snapshot();
    if (static_cast<s8>(poll_reset_request()) != 0) {
        TLobby::shutdown_keyboard_control();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        request_main_phase(0);
    }
    if (TKeyBoardControl::get_key_state() != 0) {
        run_offline_area_transfer();
        clear_keyboard_key_state();
    }
    if (TKeyBoardControl::get_input() != 0) {
        TLobby::reload_offline_area();
        clear_keyboard_input_flag();
    }
    render_tick();
}

void run_offline_transfer_frame(void) {
    begin_gx_frame();
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    debug_printf("Condition E%d", enemy_condition_count * 0xC);
    debug_printf("Condition O%d", object_condition_count * 4);
    if (is_split_screen() != 0) {
        run_split_screen_frame();
    } else {
        run_single_view_frame();
    }
    process_async_file_reads();
    update_sound_request_slots();
    TAdSinglePlyChrSelectGC::run_save_load_sequence();
    TAdSinglePlyChrSelectGC::noop();
    take_snapshot();
    run_challenge_frame();
    if (static_cast<s8>(poll_reset_request()) != 0) {
        TLobby::reset_keyboard_input();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        request_main_phase(0);
    }
    if (TKeyBoardControl::get_input() != 0) {
        TLobby::rebuild_area_keep_players();
        clear_keyboard_input_flag();
    }
    if (TKeyBoardControl::get_key_state() != 0) {
        run_offline_area_transfer();
        clear_keyboard_key_state();
    }
    render_tick();
}

void run_single_view_frame(void) {
    main_task.begin_frame();
    TCameraCtrl::set_mode(0);
    main_task.run_task();
    main_task.render_shadows();
    main_task.render();
    main_task.render_screen_overlay();
}

void run_split_screen_frame(void) {
    s32 i;
    s8 id;
    main_task.begin_frame();
    id = TCameraCtrl::get_view_state();
    if (id >= 0) {
        TCameraCtrl::set_mode(id);
        main_task.run_task();
        forward_clear_split_screen_fog();
        TCameraCtrl::set_split_viewport(1, 0);
        main_task.render();
        if (camera_ctrl_instance != NULL) {
            camera_ctrl_instance->view_yaw[id] = camera_ctrl_instance->yaw;
            VecCopy(&camera_ctrl_instance->view_pos[id], &camera_ctrl_instance->pos);
        }
    } else {
        for (i = 0; i < TCameraCtrl::get_camera_id(); i++) {
            TCameraCtrl::set_mode(i);
            if (TCameraCtrl::get_active_controller() != 5 && TCameraCtrl::get_active_controller() != 9) {
                if (i == 0) {
                    main_task.run_task();
                    TWindowSubStatusDisp::draw_split_screen_hud();
                } else if (camera_ctrl_instance != NULL) {
                    camera_ctrl_instance->run_task();
                }
                TCameraCtrl::set_split_viewport(TCameraCtrl::get_camera_id(), i);
                forward_clear_split_screen_fog();
                main_task.render();
                TCameraCtrl::sync_split_view_slots(i, 0);
                TWindowCtrlMain::enable_display();
            } else {
                TWindowCtrlMain::disable_display();
                if (i == 0) {
                    main_task.run_task();
                }
                TCameraCtrl::set_split_viewport(1, 0);
                forward_clear_split_screen_fog();
                main_task.render();
                TCameraCtrl::sync_split_view_slots(i, 1);
                TWindowCtrlMain::disable_display();
                break;
            }
        }
    }
    TCameraCtrl::set_mode(0x64);
    TCameraCtrl::set_fullscreen_viewport();
    main_task.render_screen_overlay();
}

void dispatch_offline_main_frame(void) {
    if (is_quest_active() != 0) {
        run_offline_game_frame();
        return;
    }
    run_offline_transfer_frame();
}
void init_offline_game_scene(void) {
    s32 game_mode;
    s32 i;
    TObjPlayer *player_data;
    lbl_805D5CE0 = 0;
    lobby_state_flags = 0;
    set_copy_clear_color_argb(0, 0, 0);
    TKeyBoardControl::update();
    reset_controller_input_state();
    clear_keyboard_key_state();
    clear_resource_load_tasks();
    TLobby::create_map_csn_ctrl();
    TParticleCtrl::create_quad_sprites();
    TLoadCtrl::poll_default();
    TObjPlayer::send_local_player_invisible();
    set_current_floor_area(0);
    TScene::set_scene(0);
    floor_transition_state.init_range(0);
    TLobby::reset_keyboard_state();
    apply_phase_keyboard_mode();
    run_load_callback_table(offline_game_scene_callbacks, sizeof(offline_game_scene_callbacks));
    if (is_area_transfer_pending() != 0) {
        TLobby::reset_keyboard_state();
        TLobby::invoke_callback();
        TLobby::clear_callback_and_reset_keyboard();
        TLoadCtrl::cleanup_scene();
        TObjPlayer::send_local_player_visible();
        return;
    }
    TLobby::clear_callback_and_reset_keyboard();
    TLobby__sub_801F3774();
    TLobby__sub_801A2DFC();
    TLobby::apply_char_to_players();
    TLobby__sub_801A2DF8();
    actor_frame_tick = 0;
    local_client_id = 0;
    designated_client_id = 0;
    TLobby__sub_801A2DF4();
    leader_selection.find_leader_section_id(designated_client_id);
    load_area_scene_and_init((u8 *)&floor_transition_state);
    TLoadCtrl::cleanup_scene();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render_screen_overlay();
    game_mode = TLobby::get_game_mode();
    for (i = 0; i < game_mode; i++) {
        player_data = TObjPlayer::get_player_data(i);
        if (player_data != NULL) {
            player_data->reset_motion_fields();
        }
    }
    TObjPlayer::send_local_player_visible();
    if (quest_area_manager != NULL) {
        new TQuestThread(quest_area_manager, 0);
    }
    if (TAdSinglePlyChrSelectGC::save_character_to_card() == 0) {
        if (is_quest_active() != 0) {
            TLobby::shutdown_keyboard_control();
        } else {
            TLobby::reset_keyboard_input();
        }
    }
    set_fallback_main_phase(2);
    set_queued_main_phase(0xE);
    render_tick();
}


void TLobby::clear_counter() { quest_active_flag = 0; }

int camera_split_screen_selector = 1;
void set_view_count(int count) { camera_split_screen_selector = count; }

void reset_view_count(void) { camera_split_screen_selector = 1; }

void TLobby::clear_quest_state() { lobby_online_ready_flag = 0; }

void TScene::set_scene(int scene) { scene_resource_index = scene; }


// The global character record. The original's static initializer precedes this
// file's inline copies, which a compiler-generated one never does, so the
// initializer is spelled out.
struct DestructorChain {
    DestructorChain *next;
    void *destructor;
    void *object;
};
extern "C" {
static void __sinit_OfflineGameScene_cpp();
TPlyCharData *__ct__12TPlyCharDataFv(TPlyCharData *self);
void __dt__12TPlyCharDataFv(TPlyCharData *self, s16 mode);
void *__register_global_object(void *object, void (*destructor)(TPlyCharData *, s16), void *chain);
}
#pragma push
#pragma suppress_init_code on
#pragma no_static_dtors on
static DestructorChain global_character_data_dtor_chain;
TPlyCharData TPlyCharData__global_character_data;
#pragma pop
__declspec(section ".ctors") static void *const offline_game_scene_initializer = (void *)__sinit_OfflineGameScene_cpp;

static void __sinit_OfflineGameScene_cpp() {
    __register_global_object(__ct__12TPlyCharDataFv(&TPlyCharData__global_character_data),
        __dt__12TPlyCharDataFv, &global_character_data_dtor_chain);
}

void TLobby::reset_quest_counter() { lobby_quest_progress_flag = 0; }

void TLobby::set_cleanup_flag() { quest_warp_enabled = 1; }

void TObjDoor::reset_instance() {
    door_masterkey_on = 0;
}

void TLobby::reset_door_state() { switch_doors_force_closed = 0; }

inline void TCameraCtrl::reset_mode() { camera_mode = 0; }

inline void TCameraCtrl::set_camera_id(int id) { camera_id = id; }

inline void TCameraCtrl::set_mode(int mode) { camera_mode = mode; }

inline s8 TCameraCtrl::get_view_state() { return active_view; }
