#include "pso/system/memory.h"
#include "pso/system/BmlAccessors.h"
#include "pso/render/GinjaMaterialTextureSlot.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/object/base/CollisionBodySet.h"
#include "pso/render/GinjaTexture.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/WindowMenuFactory.h"
#include "types.h"
#include <string.h>
#include <stdio.h>

#include "pso/unk/TLobby_80070A00.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/vector.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/object/door/TObjDoorJung.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdVIConfigGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TUnk_804CC9D4.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/object/warp/TObjWarpString.h"
#include "pso/object/warp/TObjMapWarpForest.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/object/warp/TObjAreaWarp.h"
#include "pso/object/warp/TObjAreaWarpEnding.h"
#include "pso/object/warp/TObjAreaWarpEndingJung.h"
#include "pso/object/warp/TObjAreaWarpForest.h"
#include "pso/object/warp/TObjAreaWarpQuest.h"
#include "pso/object/warp/TObjMapForceWarp.h"
#include "pso/object/warp/TObjMapWarp.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/MenuText.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/TObjLuker.h"
#include "pso/object/warp/TObjWarpJung.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/object/warp/TObjWarpBase.h"
#include "pso/technique/TTecLuker.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/object/TObjLuker_801329B0.h"
#include "pso/render/render_util.h"
#include "pso/network/client_id.h"
#include "pso/quest/StoryQuestProgress.h"
#include <dolphin/base/PPCArch.h>
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/GinjaMaterial.h"

#include "pso/object/base/TObjChara.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/object/warp/ForestWarpResources.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/ControllerInputState.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/system/byteswap.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/object/warp/TObjCityMainWarp_801867F4.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/render/NinjaUtil.h"
#include "pso/object/base/TObjBase.h"
#include "pso/unk/TScreenFadeOut.h"
#include "pso/player/PlayerSlots.h"
#include "pso/npc/NpcPartnerControl.h"

// The original TU was built with deferred codegen: functions below are in reverse
// address order, and the pool (three {3, 2} initializers, then the float literals
// and "%xF" in first-use order) comes out exactly as in the original .sdata2.
#pragma defer_codegen on

struct Ids_8019BD84 { u16 id[2]; };

struct Colors_8019C250 { u16 c[2]; };

struct Colors_8019C604 { u16 c[2]; };

extern "C" {

s64 get_warp_string_screen_position(void *arg0, u16 client_id);
void TObjAreaWarpQuest__sub_8019DCD8(TObjPlayer *, s32);
}


union WarpStringPos {
    s64 packed;
    struct {
        f32 x;
        f32 y;
    } xy;
};
// The table is 4-aligned in the original, so its entries are float pairs, not s64.

extern "C" {


int is_flag_400_set__10TObjPlayerFPv(void *p);

extern s32 lbl_805D55C0;

}

BmlResource *forest_warp_bml_resource;
NJS_TEXLIST *forest_warp_texture_list;
// Set by TLobby while a quest is in progress; TObjAreaWarp's ctor reads it.
s32 lobby_quest_progress_flag;


// Function definitions in reverse address order (defer_codegen emits them reversed).

static __declspec(section ".rodata") const char forest_warp_model[] ATTRIBUTE_ALIGN(4) = "fs_obj_warp.gj";
static __declspec(section ".rodata") const char forest_warp_beam_model[] ATTRIBUTE_ALIGN(4) = "fs_obj_warp_beam.gj";
static __declspec(section ".rodata") const char forest_warp_base_model[] ATTRIBUTE_ALIGN(4) = "fs_obj_warp_dai.gj";
static __declspec(section ".rodata") const char forest_warp_base_beam_model[] ATTRIBUTE_ALIGN(4) = "fs_obj_warp_dai_beam.gj";
static __declspec(section ".rodata") const char forest_warp_alternate_model[] ATTRIBUTE_ALIGN(4) = "fs_obj_warp_n.gj";
static __declspec(section ".rodata") const char forest_warp_alternate_beam_model[] ATTRIBUTE_ALIGN(4) = "fs_obj_warp_n_beam.gj";
static __declspec(section ".rodata") const char forest_warp_beam_motion[] ATTRIBUTE_ALIGN(4) = "fs_obj_warp_beam.njm";
static __declspec(section ".rodata") const char forest_warp_base_beam_motion[] ATTRIBUTE_ALIGN(4) = "fs_obj_warp_dai_beam.njm";
static __declspec(section ".rodata") const char forest_warp_alternate_beam_motion[] ATTRIBUTE_ALIGN(4) = "fs_obj_warp_n_beam.njm";
static __declspec(section ".rodata") const char forest_warp_archive[] ATTRIBUTE_ALIGN(4) = "fs_obj_warp.bml";

const char *fs_obj_warp_model_names[] = {
    forest_warp_model, forest_warp_beam_model, forest_warp_base_model, forest_warp_base_beam_model,
    forest_warp_alternate_model, forest_warp_alternate_beam_model, NULL,
};
const char *fs_obj_warp_motion_names[] = {
    forest_warp_beam_motion, forest_warp_base_beam_motion, forest_warp_alternate_beam_motion, NULL,
};
BmlResourceDescriptor forest_warp_resource_descriptor = {
    forest_warp_archive, fs_obj_warp_model_names, fs_obj_warp_motion_names, 6, 3,
};

extern __declspec(section ".data") const Vec map_warp_destination_offsets[4] = {
    { 10.0f, 0.0f, 10.0f }, { 10.0f, 0.0f, -10.0f }, { -10.0f, 0.0f, 10.0f }, { -10.0f, 0.0f, -10.0f },
};

// Screen position of the warp id string: one entry for a single screen, then the
// split-screen views of camera 2 (1 entry), 3 (2) and 4 (4), see get_warp_string_screen_position.
extern __declspec(section ".data") const WarpStringScreenPosition warp_string_screen_position_table[10] = {
    {{320.0f}, {200.0f}},
    {{320.0f}, {120.0f}},
    {{320.0f}, {260.0f}}, {{160.0f}, {120.0f}},
    {{480.0f}, {120.0f}}, {{320.0f}, {260.0f}}, {{160.0f}, {120.0f}},
    {{480.0f}, {120.0f}}, {{160.0f}, {260.0f}}, {{480.0f}, {260.0f}},
};

// The tail after load_forest_warp_resources (the original's inline helpers and
// ~TObjMapWarpForest), in reverse address order like the rest.
void PlayerPadBinding::enable_buttons(u32 mask) { enabled_buttons |= mask; }

void PlayerPadBinding::disable_buttons(u32 mask) { enabled_buttons &= ~mask; }

void bswap_6x94_inter_level_warp(G_InterLevelWarp_6x94 *packet) {
    packet->header.bswap();
    bswap_16(reinterpret_cast<u16 *>(&packet->floor));
}

void TObjAreaWarpQuest__sub_8019DCD8(TObjPlayer *p, s32 v) { *(s32 *)((char *)p + 0x3c8) = v; }

s32 Obj_80515BA0::get_next_floor() { return next_floor; }

TObjMapWarpForest::~TObjMapWarpForest() {}

void TObjMapForceWarp::open_confirm_window(s32) {}

NJS_OBJECT *get_forest_warp_model(s32 index) { return (NJS_OBJECT *)get_bml_model((BmlResource *)forest_warp_bml_resource, index); }

AnimationMotion *get_forest_warp_motion(s32 index) { return get_bml_motion(forest_warp_bml_resource, index); }

NJS_TEXLIST *get_forest_warp_textures() { return forest_warp_texture_list; }

int TAdStorySelectGC::get_story_select() { return story_select_cursor; }

void load_forest_warp_resources(void) {
    BmlResource *resource = new BmlResource(5, &forest_warp_resource_descriptor, 0, 0, NULL);
    forest_warp_bml_resource = resource;
    forest_warp_texture_list = load_gvm_texture_file("fs_obj_warp.gvm");
}


void TObjWarpBase::free_globals() {
    if (forest_warp_texture_list != NULL) {
        release_texture_list(forest_warp_texture_list);
        safe_free(forest_warp_texture_list);
        forest_warp_texture_list = NULL;
    }
    delete forest_warp_bml_resource;
    forest_warp_bml_resource = 0;
}

// Read by is_warp_enabled and can_warp; TLobby sets and clears it.
s32 quest_warp_enabled = 1;
const char *TObjWarpBase::class_name = "TObjWarpBase";

TObjWarpBase::TObjWarpBase(TObject *parent, void *set_data) : TObjCollidable(parent) {
    m_name = class_name;
    apply_object_set_data(set_data);
    warp_range = 10.0f;
    menu_window = 0;
    field_collider = new TUnk_804CC9D4(&position, this, 1);
    user_client_id = 0xFFFF;
}

TObjWarpBase::~TObjWarpBase() {
    close_menu();
}

TObjPlayer *find_warp_player_in_range(TObjWarpBase *warp, u16 client_id, f32 range) {
    TObjPlayer *player = get_player_by_client_id(client_id);
    if ((player != NULL) && (xz_distance_squared(&warp->position, &player->position) < (range * range))) {
        if (player->is_controls_locked() == 1) {
            return NULL;
        }
        return player;
    }
    return NULL;
}

void TObjWarpBase::close_menu() {
    uaddr player;

    player = (u32) this->menu_window;
    if (player != 0U) {
        ((TWindowBase *)player)->close();
        this->menu_window = 0U;
        player = (uaddr)get_player_by_client_id(this->user_client_id);
        if (player != 0U) {
            ((TObjPlayer *)player)->pad_binding.enable_buttons(4);
        }
        this->user_client_id = 0xFFFFU;
    }
}

s32 TObjWarpBase::is_warp_enabled() {
    TObjPlayer *player;
    u32 id = this->user_client_id;

    player = NULL;
    if ((id != 0xFFFF) && ((player = get_player_by_client_id(id)) == NULL || (player->is_controls_locked() != 0))) {
        return 0;
    }
    if (quest_warp_enabled == 0) {
        return 0;
    }
    if (lbl_805D55C0 != 0) {
        return 0;
    }
    if ((player != NULL) && (player->has_flag_0x800() != 0)) {
        return 0;
    }
    if (player != NULL) {
        return is_flag_400_set__10TObjPlayerFPv(player) == 0;
    }
    if ((player != NULL) && (player->is_body_collision_inactive() != 0)) {
        return 0;
    }
    return 1;
}

s32 TObjWarpBase::is_choice_confirmed() {
    return test_pressed_buttons_packed(&controller_input_state.controllers[0], 4);
}

s32 TObjWarpBase::is_choice_confirmed_by(s32 client_id) {
    return test_pressed_buttons_packed(&controller_input_state.controllers[client_id], 4);
}

const char *TObjMapWarp::class_name = "TObjMapWarp";

// The set entry's scale holds the destination; each player gets a spot at its offset from it.
TObjMapWarp::TObjMapWarp(TObject *parent, void *set_data) : TObjWarpBase(parent, set_data) {
    s32 i;
    m_name = class_name;
    for (i = 0; i < 4; i++) {
        push_matrix_from(identity_matrix);
        post_translate_matrix(&scale.x);
        rotate_matrix_y(0, rotation_y);
        matrix_mult_vec(NULL, &map_warp_destination_offsets[i], &destinations[i]);
        pop_matrix();
        playerPopups[i] = 0;
    }
}

TObjMapWarp::~TObjMapWarp() {
    close_menu();
}

void TObjMapWarp::close_menu() {
    for(s32 slot=0;slot<4;++slot)closePlayerWindow((u16)slot);
}

void TObjMapWarp::closePlayerWindow(u16 slot) {
    TObjPlayer *player;
    if (playerPopups[slot] != NULL) {
        playerPopups[slot]->close();
        playerPopups[slot] = NULL;
        player = get_player_by_client_id(slot);
        if (player != NULL) {
            player->pad_binding.enable_buttons(4);
        }
    }
}

void TObjMapWarp::open_confirm_window(s32 client_id) {
    if (playerPopups[client_id] == NULL) {
        playerPopups[client_id] = create_window_menu((saddr)get_window_layout_position(0x33), 1, client_id);
        playerPopups[client_id]->add_text_entry(get_localized_text_entry(9, 0x25), 2, 0, -1);
        playerPopups[client_id]->calc_window_size();
        align_menu_entry_positions(playerPopups[client_id]);
        playerPopups[client_id]->set_flag70_bit10();
        playerPopups[client_id]->set_flag_40();
    }
}

s32 TObjMapWarp::can_warp(u16 client_id) {
    TObjPlayer *player;
    u32 id;

    id = client_id;
    player = NULL;
    if ((id != 0xFFFF) && ((player = get_player_by_client_id(id)) == NULL || (player->is_controls_locked() != 0))) {
        return 0;
    }
    if (quest_warp_enabled == 0) {
        return 0;
    }
    if (lbl_805D55C0 != 0) {
        return 0;
    }
    if ((player != NULL) && (player->has_flag_0x800() != 0)) {
        return 0;
    }
    if (player != NULL) {
        return is_flag_400_set__10TObjPlayerFPv(player) == 0;
    }
    return 1;
}


void TObjMapWarp::process_player_warps() {
    s32 i;
    TObjPlayer *t;
    s32 j;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        for (i = 0; i < 4; i++) {
            if (can_warp(i) == 0) {
                if (playerPopups[i] != NULL) {
                    ((TWindowBase *)(playerPopups[i]))->close();
                    playerPopups[i] = NULL;
                }
            } else {
                if (playerPopups[i] != NULL) {
                    ((TObject *)playerPopups[i])->clear_update_suspension();
                    ((TObject *)playerPopups[i])->allow_rendering();
                }
                t = find_warp_player_in_range(this, i, this->warp_range);
                if (t != NULL) {
                    this->open_confirm_window(t->get_entity_id());
                    if (t->is_target_valid() != 0 && this->is_choice_confirmed_by(t->get_controller_port()) != 0) {
                        for (j = 0; j < 4; j++) {
                            if (test_player_body_overlap_at(this, t, &destinations[j]) == 0) {
                                send_6x55_intra_map_warp(t->get_entity_id(), &destinations[j], this->set_params[0]);
                            }
                        }
                    }
                } else {
                    this->closePlayerWindow(i);
                }
            }
        }
        return;
    }
    if (is_warp_enabled() == 0) {
        if (this->menu_window != NULL) {
            ((TWindowBase *)this->menu_window)->close();
            this->menu_window = NULL;
        }
    } else {
        TObjPlayer *t2;
        s32 j2;
        if (this->menu_window != NULL) {
            ((TObject *)(this->menu_window))->clear_update_suspension();
            ((TObject *)this->menu_window)->allow_rendering();
        }
        t2 = find_warp_player_in_range(this, local_client_id, this->warp_range);
        if (t2 != NULL) {
            this->open_confirm_window(local_client_id);
            if (t2->is_target_valid() != 0 && this->is_choice_confirmed_by(t2->get_controller_port()) != 0) {
                for (j2 = 0; j2 < 4; j2++) {
                    if (test_player_body_overlap_at(this, t2, &destinations[j2]) == 0) {
                        send_6x55_intra_map_warp(t2->get_entity_id(), &destinations[j2], this->set_params[0]);
                    }
                }
            }
        } else {
            this->close_menu();
        }
    }
}

void TObjMapWarp::draw_debug_destinations() {
    Vec *end;
    s32 i;
    TObjNpcEnemy::set_global_count(0xFF00FF);
    ((s32 (*)(s32, const char *, ...))debug_printf_at)(0x13001C, "<- DST POS X");
    ((s32 (*)(s32, const char *, ...))debug_printf_at)(0x13001D, "<- DST POS Y");
    ((s32 (*)(s32, const char *, ...))debug_printf_at)(0x13001E, "<- DST POS Z");
    ((s32 (*)(s32, const char *, ...))debug_printf_at)(0x130020, "<- DST ANG Y");
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    for (i = 0; i < 4; i++) {
        Vec b;
        Vec a = {0.0f, 0.0f, -3.0f};
        push_matrix_from(identity_matrix);
        post_translate_matrix(&scale.x);
        rotate_matrix_y(0, rotation_y);
        end = &destinations[i];
        matrix_mult_vec(NULL, &map_warp_destination_offsets[i], end);
        pop_matrix();
        push_matrix_from(identity_matrix);
        post_translate_matrix(&end->x);
        rotate_matrix_y(0, set_params[0]);
        matrix_mult_vec(NULL, &a, &a);
        pop_matrix();
        VecCopy((Vec *)&b, (const Vec *)end);
        b.y += 5.0f;
        a.y += 5.0f;
        debug_draw_line(&b, &a, 0xFFFF0000, 0xFFFF0000);
        fn_80141CB4(end, 15.0f);
    }
}

const char *TObjMapWarpForest::class_name = "TObjMapWarpForest";

TObjMapWarpForest::TObjMapWarpForest(TObject *parent, void *set_data) : TObjMapWarp(parent, set_data) {
    m_name = class_name;
    baseModel = get_forest_warp_model(4);
    beamModel = get_forest_warp_model(5);
    motion = get_forest_warp_motion(2);
    textures = get_forest_warp_textures();
    frame = 0.0f;
}

void TObjMapWarpForest::run_task() {
    this->frame+=4.0f;
    if((f32)(u32)(this->motion->frameCount-1)<this->frame)this->frame=0.0f;
    process_player_warps();
}

void TObjMapWarpForest::render() {
    if (this->update_object_view_visibility(400.0f, 20.0f) != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(textures));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, this->rotation_y);
        draw_ginja_object(baseModel);
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion(beamModel, motion, frame);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

const char *TObjAreaWarp::class_name = "TObjAreaWarp";

TObjAreaWarp::TObjAreaWarp(TObject *parent, void *set_data) : TObjWarpBase(parent, set_data) {
    m_name = class_name;
    dest_floor = set_params[0];
    if (lobby_quest_progress_flag != 0) {
        dest_floor = get_current_floor() + 1;
    }
    vi_config = NULL;
}

TObjAreaWarp::~TObjAreaWarp() {
    if (vi_config != NULL) {
        TAdVIConfigGC::destroy(vi_config, 1);
        vi_config = NULL;
    }
    close_menu();
}

void TObjAreaWarp::open_confirm_window(s32 client_id) {
    uaddr player;

    if ((u32) this->menu_window == 0U) {
        this->menu_window = (uaddr)create_window_menu((saddr)get_window_layout_position(0x33), 1, client_id);
        if (get_game_play_mode() == 1) {
            ((TWindowMenu *)(this->menu_window))->add_text_entry((saddr)TObjCityMainWarp__sub_80186AF4(), 2, 0, -1);
        } else {
            ((TWindowMenu *)(this->menu_window))->add_text_entry(get_floor_destination_name(get_floor_area(this->dest_floor)), 2, 0, -1);
        }
        ((TWindowMenu *)(this->menu_window))->calc_window_size();
        align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(this->menu_window));
        ((TWindowMenu *)(this->menu_window))->set_flag70_bit10();
        ((TWindowMenu *)(this->menu_window))->set_flag_40();
        this->user_client_id = client_id;
        player = (uaddr)get_player_by_client_id(this->user_client_id);
        if (player != 0U) {
            ((TObjPlayer *)player)->pad_binding.disable_buttons(4);
        }
    }
}

s32 TObjAreaWarp::is_warp_enabled() {
    if (TRaderMapCore::is_not_split_screen() == 1) {
        for (s32 i = 0; i < 4; i++) {
            TObjPlayer *player = get_player_by_client_id(i);
            if ((player != NULL) && (player->is_controls_locked() != 0)) {
                return 0;
            }
        }
    }
    return TObjWarpBase::is_warp_enabled();
}

void TObjAreaWarp::handle_area_selection() {
    s32 found;
    s32 i;
    TObjPlayer *t;
    if (is_warp_enabled() == 0) {
        if (menu_window != 0) {
            ((TWindowBase *)menu_window)->close();
            menu_window = 0;
        }
    } else {
        if (menu_window != 0) {
            ((TObject *)menu_window)->clear_update_suspension();
            ((TObject *)menu_window)->allow_rendering();
        }
        if (is_split_screen() != 0) {
            found = 0;
            if (vi_config != NULL) {
                vi_config->update_visibility();
                if (vi_config->get_field_14() == 0) {
                    this->close_menu();
                    return;
                }
            }
            for (i = 0; i < 4; i++) {
                t = find_warp_player_in_range(this, i, warp_range);
                if (t != NULL) {
                    found = 1;
                    if (vi_config != NULL) {
                        this->open_confirm_window(((TObjAreaWarp *)vi_config)->find_active_player());
                    } else {
                        this->open_confirm_window(t->get_entity_id());
                    }
                    if (this->is_choice_confirmed_by(i) != 0) {
                        this->close_menu();
                        this->confirm_area_transfer(t);
                    }
                }
            }
            if (found == 0) {
                this->close_menu();
            }
        } else {
            TObjPlayer *t2 = find_warp_player_in_range(this, local_client_id, warp_range);
            if (t2 != NULL) {
                this->open_confirm_window(local_client_id);
                if (this->is_choice_confirmed_by(t2->get_controller_port()) != 0) {
                    this->close_menu();
                    this->confirm_area_transfer(t2);
                }
            } else {
                this->close_menu();
            }
        }
    }
}

void TObjAreaWarp::confirm_area_transfer(TObjPlayer *player) {
    floor_transition_state.set_next_floor((int) (this->dest_floor), (int) (get_floor_map_terrain(this->dest_floor)));
    ((s32 (*)(void))mark_area_change_pending)();
    send_inter_level_warp_all(floor_transition_state.get_next_floor());
    send_6x21_inter_level_warp(player, (floor_transition_state.get_next_floor()));
    ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(0x40003205, 0U, 0, 0);
}

void handle_6x94_inter_level_warp(game_command_header *command) {
    G_InterLevelWarp_6x94 *packet = reinterpret_cast<G_InterLevelWarp_6x94 *>(command);
    bswap_6x94_inter_level_warp(packet);
    if (packet->floor != get_current_floor()) {
        floor_transition_state.set_next_floor(packet->floor, get_floor_map_terrain(packet->floor));
        mark_area_change_pending();
        TWindowCtrl::suppress_slot(local_client_id);
        send_inter_level_warp_all(floor_transition_state.get_next_floor());
        TObjPlayer *p = get_player_by_client_id(local_client_id);
        if (p != 0) {
            send_6x21_inter_level_warp(p, (s32)(floor_transition_state.get_next_floor()));
        }
    }
}

void TObjAreaWarp::debug_print_area_num() {
    dest_floor = set_params[0];
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, "<- AREA NUM : %d", dest_floor);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

const char *TObjAreaWarpForest::class_name = "TObjAreaWarpForest";

TObjAreaWarpForest::TObjAreaWarpForest(TObject *parent, void *set_data) : TObjAreaWarp(parent, set_data) {
    m_name = class_name;
    m_c4 = 0.0f;
    beam_rotation = 0;
    set_params[2] %= 2;
    if ((get_game_play_mode() == 1) && (set_params[2] == 0)) {
        queue_destruction();
        return;
    }
    warp_model = get_forest_warp_model(0);
    beam_model = get_forest_warp_model(1);
    beam_motion = get_forest_warp_motion(0);
    textures = get_forest_warp_textures();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        void *p = ::operator new(0x88);
        if (p != NULL) {
            p = ((TAdVIConfigGC *)p)->init(&position, 20.0f);
        }
        vi_config = (TAdVIConfigGC *)p;
    } else {
        vi_config = NULL;
    }
}

TObjAreaWarpForest::~TObjAreaWarpForest() {}

void TObjAreaWarpForest::run_task() {
    m_c4 += 4.0f;
    if (static_cast<f32>(beam_motion->frameCount - 1) < m_c4) {
        m_c4 = 0.0f;
    }
    beam_rotation += 0x150;
    handle_area_selection();
}

void TObjAreaWarpForest::confirm_area_transfer(TObjPlayer *player) { TObjAreaWarp::confirm_area_transfer(player); }

void TObjAreaWarpForest::render() {

    NJS_OBJECT *m;
    NJS_OBJECT *n;
    if (this->update_object_view_visibility(400.0f, 20.0f) != 0) {
        Colors_8019C604 cols = {3, 2};
        n = beam_model->child;
        while (n != NULL) {
            if (n->model != 0) {
                set_ginja_model_texture_slot(reinterpret_cast<void *>((n->model)), cols.c[this->set_params[2]]);
            }
            n = n->child;
        }
        m = warp_model;
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(textures));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, this->rotation_y);
        push_matrix();
        post_translate_matrix(m->pos);
        draw_ginja_model(m->model);
        TParticleCtrl::begin_effect_render();
        m = m->child;
        while (m != NULL) {
            push_matrix();
            post_translate_matrix(m->pos);
            rotate_matrix_zyx(NULL, (m->ang[0]), (m->ang[1]), (m->ang[2]));
            rotate_matrix_x(NULL, static_cast<s32>(beam_rotation));
            draw_ginja_model(m->model);
            pop_matrix();
            m = m->sibling;
        }
        TParticleCtrl::end_effect_render();
        pop_matrix();
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion(beam_model, beam_motion, this->m_c4);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TObjAreaWarpForest::debug_print_area_num() {
    this->TObjAreaWarp::debug_print_area_num();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    if (set_params[2] < 0) {
        set_params[2] = 0;
    }
    set_params[2] = set_params[2] % 2;
    if (set_params[2] == 0) {
        TObjNpcEnemy::set_global_count(0xFFFFFF);
        debug_printf_at(0x130022, "<- COLOR : BLUE");
    } else {
        TObjNpcEnemy::set_global_count(0xFF0000FF);
        debug_printf_at(0x130022, "<- COLOR : RED");
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

const char *TObjAreaWarpQuest::class_name = "TObjAreaWarpQuest";

TObjAreaWarpQuest::TObjAreaWarpQuest(TObject *parent, void *set_data) : TObjAreaWarp(parent, set_data) {
    m_name = class_name;
    beam_frame = 0.0f;
    beam_rotation = 0;
    set_params[2] %= 2;
    this->player_set_id = (s32) this->scale.x;
    warp_model = get_forest_warp_model(0);
    beam_model = get_forest_warp_model(1);
    beam_motion = get_forest_warp_motion(0);
    textures = get_forest_warp_textures();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        void *p = ::operator new(0x88);
        if (p != NULL) {
            p = ((TAdVIConfigGC *)p)->init(&position, 20.0f);
        }
        vi_config = (TAdVIConfigGC *)p;
    } else {
        vi_config = NULL;
    }
}

TObjAreaWarpQuest::~TObjAreaWarpQuest() {}

void TObjAreaWarpQuest::run_task() {
    beam_frame += 4.0f;
    if (static_cast<f32>(beam_motion->frameCount - 1) < beam_frame) {
        beam_frame = 0.0f;
    }
    beam_rotation += 0x150;
    handle_area_selection();
}

void TObjAreaWarpQuest::render() {

    NJS_OBJECT *m;
    NJS_OBJECT *n;
    if (this->update_object_view_visibility(400.0f, 20.0f) != 0) {
        Colors_8019C250 cols = {3, 2};
        n = beam_model->child;
        while (n != NULL) {
            if (n->model != 0) {
                set_ginja_model_texture_slot(reinterpret_cast<void *>((n->model)), cols.c[set_params[2]]);
            }
            n = n->child;
        }
        m = warp_model;
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(textures));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, this->rotation_y);
        push_matrix();
        post_translate_matrix(m->pos);
        draw_ginja_model(m->model);
        TParticleCtrl::begin_effect_render();
        m = m->child;
        while (m != NULL) {
            push_matrix();
            post_translate_matrix(m->pos);
            rotate_matrix_zyx(NULL, (m->ang[0]), (m->ang[1]), (m->ang[2]));
            rotate_matrix_x(NULL, static_cast<s32>(beam_rotation));
            draw_ginja_model(m->model);
            pop_matrix();
            m = m->sibling;
        }
        TParticleCtrl::end_effect_render();
        pop_matrix();
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion(beam_model, beam_motion, this->beam_frame);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TObjAreaWarpQuest::debug_print_area_num() {
    this->TObjAreaWarp::debug_print_area_num();
    if (scale.x < 0.0f) {
        scale.x = 0.0f;
    }
    player_set_id = (s32)scale.x;
    if (set_params[2] < 0) {
        set_params[2] = 0;
    }
    set_params[2] = set_params[2] % 2;
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x13001C, "<- PLAYER SET ID : %d", player_set_id);
    if (set_params[2] == 0) {
        TObjNpcEnemy::set_global_count(0xFFFFFF);
        debug_printf_at(0x130022, "<- COLOR : BLUE");
    } else {
        TObjNpcEnemy::set_global_count(0xFF0000FF);
        debug_printf_at(0x130022, "<- COLOR : RED");
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TObjAreaWarpQuest::confirm_area_transfer(TObjPlayer *player) {
    s32 i;
    TObjPlayer *p;
    floor_transition_state.set_next_floor(dest_floor, get_floor_map_terrain(dest_floor));
    mark_area_change_pending();
    if (player != 0 && player_set_id > 1) {
        TObjAreaWarpQuest__sub_8019DCD8(player, player_set_id);
    }
    if (player_set_id > 1) {
        for (i = 0; i < 4; i++) {
            p = get_player_by_client_id(i);
            if (p != 0 && p->obj_isState3_324() != 0 && p->get_npc_controller() != 0xFFFF) {
                TObjAreaWarpQuest__sub_8019DCD8(p, player_set_id);
            }
        }
    }
    send_inter_level_warp_all(floor_transition_state.get_next_floor());
    send_6x21_inter_level_warp(player, (s32)(floor_transition_state.get_next_floor()));
}

const char *TObjAreaWarpEnding::class_name = "TObjAreaWarpEnding";

TObjAreaWarpEnding::TObjAreaWarpEnding(TObject *parent, void *set_data) : TObjAreaWarp(parent, set_data) {
    m_name = class_name;
    m_c4 = 0.0f;
    beam_rotation = 0;
    set_params[2] %= 2;
    warp_model = get_forest_warp_model(0);
    beam_model = get_forest_warp_model(1);
    beam_motion = get_forest_warp_motion(0);
    textures = get_forest_warp_textures();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        void *p = ::operator new(0x88);
        if (p != NULL) {
            p = ((TAdVIConfigGC *)p)->init(&position, 20.0f);
        }
        vi_config = (TAdVIConfigGC *)p;
    } else {
        vi_config = NULL;
    }
}

TObjAreaWarpEnding::~TObjAreaWarpEnding() {}

void TObjAreaWarpEnding::run_task() {
    m_c4 += 4.0f;
    if (static_cast<f32>(beam_motion->frameCount - 1) < m_c4) {
        m_c4 = 0.0f;
    }
    beam_rotation += 0x150;
    handle_area_selection();
}

void TObjAreaWarpEnding::render() {


    NJS_OBJECT *root;
    NJS_OBJECT *node;
    if (update_object_view_visibility(400.0f, 20.0f) == 0) {
        return;
    }
    Ids_8019BD84 ids = {3, 2};
    for (node = beam_model->child; node != 0; node = node->child) {
        if (node->model != 0) {
            set_ginja_model_texture_slot(reinterpret_cast<void *>((node->model)), ids.id[set_params[2]]);
        }
    }
    root = warp_model;
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(textures));
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, rotation_y);
    push_matrix();
    post_translate_matrix(root->pos);
    draw_ginja_model(root->model);
    TParticleCtrl::begin_effect_render();
    for (root = root->child; root != 0; root = root->sibling) {
        push_matrix();
        post_translate_matrix(root->pos);
        rotate_matrix_zyx(NULL, root->ang[0], root->ang[1], root->ang[2]);
        rotate_matrix_x(NULL, static_cast<s32>(beam_rotation));
        draw_ginja_model(root->model);
        pop_matrix();
    }
    TParticleCtrl::end_effect_render();
    pop_matrix();
    TParticleCtrl::begin_effect_render();
    draw_ginja_model_with_motion(beam_model, beam_motion, m_c4);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TObjAreaWarpEnding::debug_print_area_num() {
    this->TObjAreaWarp::debug_print_area_num();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    if (set_params[2] < 0) {
        set_params[2] = 0;
    }
    set_params[2] = set_params[2] % 2;
    if (set_params[2] == 0) {
        TObjNpcEnemy::set_global_count(0xFFFFFF);
        debug_printf_at(0x130022, "<- COLOR : BLUE");
    } else {
        TObjNpcEnemy::set_global_count(0xFF0000FF);
        debug_printf_at(0x130022, "<- COLOR : RED");
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TObjAreaWarpEnding::open_confirm_window(s32 client_id) {
    if ((u32) this->menu_window == 0U) {
        this->menu_window = (uaddr)create_window_menu((saddr)get_window_layout_position(0x33), 1, client_id);
        if (get_main_phase() == 0xE) {
            ((TWindowMenu *)(this->menu_window))->add_text_entry(get_localized_text_entry(9, 0x26), 3, 0, -1);
        } else {
            ((TWindowMenu *)(this->menu_window))->add_text_entry(get_localized_text_entry(9, 0x23), 2, 0, -1);
        }
        ((TWindowMenu *)(this->menu_window))->calc_window_size();
        align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(this->menu_window));
        ((TWindowMenu *)(this->menu_window))->set_flag70_bit10();
        ((TWindowMenu *)(this->menu_window))->set_flag_40();
        user_client_id = client_id;
    }
}

void TObjAreaWarpEnding::confirm_area_transfer(TObjPlayer *) {
    play_sound_effect(0x40003205, 0, 0, 0);
    new TScreenFadeOut(tl_00, TKeyBoardControl::dispatch_select_phase);
}

void TKeyBoardControl::dispatch_select_phase(TObject *) {

    switch (TAdStorySelectGC::get_story_select()) {
    case 0:
        if (should_record_episode1_quest_completion() != 0) {
            set_story_flag_or_send_quest_flag(0x3FE);
            request_main_phase(0xC);
        } else {
            request_main_phase(0x10);
        }
        break;
    case 1:
        request_main_phase(8);
        break;
    }
    TAdSinglePlyChrSelectGC::init();
}

const char *TObjMapForceWarp::class_name = "TObjMapForceWarp";

TObjMapForceWarp::TObjMapForceWarp(TObject *parent, void *set_data) : TObjMapWarp(parent, set_data) {
    m_name = class_name;
    if ((s32) set_params[2] > 0) {
        display_number = 0;
    } else {
        display_number = 1;
    }
    if (field_collider != NULL) {
        ((TObject *)field_collider)->disallow_rendering();
        ((TObject *)field_collider)->suspend_update();
    }
}

TObjMapForceWarp::~TObjMapForceWarp() {}

void TObjMapForceWarp::run_task() { process_player_warps(); }

void TObjMapForceWarp::render() {  }

void TObjMapForceWarp::draw_debug_destinations() {
    TObjMapWarp::draw_debug_destinations();
    if ((s32)set_params[2] > 0) {
        display_number = 0;
    } else {
        display_number = 1;
    }
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130021, "<- FLOOR NUMBER");
    if (display_number != 0) {
        debug_printf_at(0x130022, "<- DISP NUMBER");
    } else {
        debug_printf_at(0x130022, "<- NO DISP NUMBER");
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

s32 TObjMapForceWarp::is_choice_confirmed_by(s32 client_id) {
    if (display_number != 0) {
        create_warp_id_string(client_id);
    }
    return 1;
}

void TObjMapForceWarp::create_warp_id_string(u16 client_id) {
    char buf[32];
    char *p;
    sprintf(buf, "%xF", set_params[1]);
    for (p = buf; *p != 0; p++) {
        *p = TLobby__sub_80070AD8(*p);
    }
    create_TObjWarpString(buf, client_id);
}

const char *TObjWarpString::class_name = "TObjWarpString";

TObjWarpString::TObjWarpString(TObject *parent, char *src, u16 client_id) : TObject(parent) {
    m_name = class_name;
    strncpy(text, src, sizeof(text));
    text[sizeof(text) - 1] = 0;
    this->client_id = client_id;
    pad_3C = -1;
    alpha = 0.0f;
    timer = 0x18;
    state = 0;
}

TObjWarpString::~TObjWarpString() {}

void TObjWarpString::run_task() {
    switch (state) {
    case 0:
        delay_before_fade_in();
        return;
    case 1:
        update_fade_in();
        return;
    case 2:
        delay_before_fade_out();
        return;
    case 3:
        fade_and_destroy();
        return;
    }
}

void TObjWarpString::delay_before_fade_in() {
    if (--timer < 0) {
        state = 1;
    }
}

#pragma push
#pragma opt_common_subs off
void TObjWarpString::update_fade_in() {
    alpha += 10.0f;
    if (alpha > 255.0f) {
        alpha = 255.0f;
        state = 2;
        timer = 0x5A;
    }
}
#pragma pop

void TObjWarpString::delay_before_fade_out() {
    if (--timer < 0) {
        state = 3;
    }
}

void TObjWarpString::fade_and_destroy() {
    alpha -= 10.0f;
    if (alpha < 0.0f) {
        alpha = 0.0f;
        queue_destruction();
    }
}

#pragma push
#pragma opt_common_subs off

void TObjWarpString::render() {
    f32 xr;
    f32 y;
    f32 yt;
    f32 yb;
    WarpStringPos pos;
    u32 color;
    u32 width;

    pos.packed = get_warp_string_screen_position(this, client_id);
    width = calc_text_width(text) >> 1;
    pos.xy.x -= (f32)width;
    y = pos.xy.y;
    color = (u8)alpha << 24;
    draw_menu_text(pos.xy.x - 2.0f, yt = y - 2.0f, text, color);
    draw_menu_text(pos.xy.x, yt, text, color);
    draw_menu_text(xr = 2.0f + pos.xy.x, yt, text, color);
    draw_menu_text(pos.xy.x - 2.0f, y, text, color);
    draw_menu_text(xr, y, text, color);
    draw_menu_text(pos.xy.x - 2.0f, yb = 2.0f + y, text, color);
    draw_menu_text(pos.xy.x, yb, text, color);
    draw_menu_text(xr, yb, text, color);
    color = ((u8)alpha << 24) | 0xFFFFFF;
    TParticleCtrl::begin_effect_render();
    draw_menu_text(pos.xy.x, y, text, color);
    TParticleCtrl::end_effect_render();
}
#pragma pop

s64 get_warp_string_screen_position(void *arg0, u16 client_id) {
    const WarpStringScreenPosition *p = warp_string_screen_position_table;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        switch (TCameraCtrl::get_camera_id()) {
        case 2:
            p = warp_string_screen_position_table + 1;
            break;
        case 3:
            p = warp_string_screen_position_table + 3;
            break;
        case 4:
            p = warp_string_screen_position_table + 6;
            break;
        }
        p += TCameraCtrl::get_split_screen_view_index(client_id);
    }
    return *(const s64 *)p;
}

TObjWarpString *create_TObjWarpString(char *text, u16 client_id) {
    return new TObjWarpString(tl_clipout, text, client_id);
}


const char *TObjAreaWarpEndingJung::class_name = "TObjAreaWarpEndingJung";

TObjAreaWarpEndingJung::TObjAreaWarpEndingJung(TObject *parent, void *set_data) : TObjAreaWarpEnding(parent, set_data) {
    m_name = class_name;
    if (set_params[2] < 0) {
        set_params[2] = 0;
    }
    set_params[2] %= 2;
}

TObjAreaWarpEndingJung::~TObjAreaWarpEndingJung() {}

void TObjAreaWarpEndingJung::run_task() {
    this->m_c4 += 4.0f;
    if (this->m_c4 > (TObjWarpJung::get_static_field4_as_float() - 1.0f)) {
        this->m_c4 = 0.0f;
    }
    handle_area_selection();
}

void TObjAreaWarpEndingJung::render() {

    if (this->update_object_view_visibility(400.0f, 20.0f) != 0) {
        if (TObjWarpJung::update_warp_display() != 0) {
            PPCSync();
        }
        switch (this->set_params[2]) {
        case 0:
            TObjWarpJung__sub_801A0404(0);
            break;
        case 1:
            TObjWarpJung__sub_801A0404(1);
            break;
        }
        TObjWarpJung::set_global_render_param();
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, this->rotation_y);
        TObjWarpJung::render_warp(0);
        TParticleCtrl::begin_effect_render();
        TObjWarpJung::render_warp_effect(1, (s32) this->m_c4);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TObjAreaWarpEndingJung::debug_print_area_num() {
    TObjNpcEnemy::set_global_count(0xFF00FF);
    if (set_params[2] < 0) {
        set_params[2] = 0;
    }
    set_params[2] = set_params[2] % 2;
    if (set_params[2] == 0) {
        TObjNpcEnemy::set_global_count(0xFFFFFF);
        debug_printf_at(0x130022, "<- COLOR : RED");
    } else {
        TObjNpcEnemy::set_global_count(0xFF0000FF);
        debug_printf_at(0x130022, "<- COLOR : BLUE");
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void *TObjAreaWarpEndingJung::create(void *set_data) {
    return new TObjAreaWarpEndingJung(tl_05, set_data);
}
