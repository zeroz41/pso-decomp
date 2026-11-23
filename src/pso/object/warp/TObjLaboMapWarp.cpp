#include "pso/system/BmlAccessors.h"
#include "pso/ui/frontend/TAdVIConfigGC.h"
#include "pso/system/BmlResource.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/object/city/CityTraffic.h"
#include "types.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/unk/TLobby_8006F278.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/system/task/TMainTask.h"

#include "pso/object/warp/TObjMapWarp.h"

#include "pso/object/warp/TObjCityMainWarp_801867F4.h"

#include "pso/object/warp/TObjAreaWarp.h"

#include "pso/ui/window/TWindowMenu.h"

#include "pso/ui/window/TWindowSubComCardList.h"

#include "pso/object/warp/TObjCityAreaWarp.h"

#include "pso/object/warp/TObjCityMainWarp.h"

#include "pso/object/warp/TObjCityMapWarp.h"

#include "pso/object/warp/TObjLaboMapWarp.h"

#include "pso/effect/particle/TParticleCtrl.h"

#include "pso/boss/darkfalz/TBoss4DarkFalz.h"

#include "pso/unk/TLobby.h"

#include "pso/ui/window/TWindowCtrl.h"

#include "pso/ui/window/TWindowSubComCard.h"

#include "pso/enemy/morfos/TWindowSubTradeMain.h"

#include "pso/npc/TObjNpcEnemy.h"

#include "pso/ui/frontend/TAdChrSelASlotGC.h"

#include "pso/object/warp/TObjCityMainWarpChallenge.h"

#include "pso/player/TObjPlayer.h"

#include "pso/unk/TLobby_80207644.h"

#include "pso/map/FloorArea.h"

#include "pso/system/SoundEffect.h"

#include "pso/player/TObjPlayer_801AF2F0.h"

#include "pso/player/TObjPlayer_80011014.h"

#include "pso/unk/text_803D853C.h"

#include "pso/unk/text_803D96A8.h"

#include "pso/object/ambient/TObjFish.h"

#include "pso/object/warp/TObjWarpBase.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/network/client_id.h"
#include "pso/object/warp/TObjLaboMapWarp_80185248.h"
#include "pso/player/PlayerSlots.h"

s32 get_story_flag(s32);

s32 TObjCityMainWarp__enabled_destinations;

s32 TObjCityMainWarp__visible_destination_mask;

BmlResource *TObjLaboMapWarp__resource_bundle;

struct Obj_80185664 { u8 pad[0x8C]; s32 dest; };

struct Obj_80185824 { u8 pad[0xFC]; f32 fFC; };

struct Obj_80185BE8 { u8 pad[0xC4]; f32 t; };

extern "C" {



void unlock_main_warp_destination(s32 id);

void clear_enabled_main_warps(void);


s32 get_window_layout_position(s32);


s32 rotate_matrix_y(s32, s32);


s32 post_translate_matrix(void *);


extern void request_active_window_close();


extern s16 TLobby__data_805D5CE8;


}

struct Obj_80186B34 { u8 pad[0x38]; u8 pos[0xAC - 0x38]; f32 range; };

extern "C" {

f32 xz_distance_squared(s32, s32);


extern s32 lbl_805D55C0;

s32 *TObjCityMainWarp__sub_80186AF4(void);


}

const char *bm_obj_warp_labo_model_names[3] = {
    "warp_citybeam.gj",
    "warp_obj01.gj",
    NULL,
};

const char *bm_obj_warp_labo_motion_names[2] = {
    "warp_citybeam.njm",
    NULL,
};

BmlResourceDescriptor bm_obj_warp_labo_resource_descriptor = {
    "bm_obj_warp_labo.bml", bm_obj_warp_labo_model_names, bm_obj_warp_labo_motion_names, 2, 1,
};

const s32 city_warp_group9_text_table[16] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
};

const s32 city_warp_group9_text_table_b[17] = {
    0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21,
};

const s32 city_warp_floor_destination_table[16] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 17,
};

// inferred: the lobby counterpart of city_warp_floor_destination_table; TObjCityMainWarp::is_choice_confirmed reads it
// when TLobby::get_instance() != 0, indexed by the f10C list the lobby branch of __vt13 fills.
const s32 city_warp_floor_destination_table_b[17] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
};

// inferred: group-9 text ids of the three map warp destinations ("GOVERNOR", "CITY", "LABO" in the debug
// name tables), indexed by set_params[2] in TObjLaboMapWarp__vt13 and TObjCityMapWarp__vt13.
const s32 map_warp_dest_text_ids[3] = {0x22, 0x23, 0x10};

const char *TObjCityMainWarp::class_name = "TObjCityMainWarp";
const char *TObjCityAreaWarp::class_name = "TObjCityAreaWarp";
const char *TObjCityMapWarp::class_name = "TObjCityMapWarp";
const char *TObjLaboMapWarp::class_name = "TObjLaboMapWarp";

extern "C" {

void update_main_warp_visible_mask(s32 select_type);

void TObjCityMainWarp__sub_80186AB8(void);


#pragma push
#pragma fp_contract on
TObjPlayer *find_local_city_warp_player(TObjAreaWarp *warp, f32 range) {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        s32 current_floor = get_current_floor();
        s32 player_floor = player->get_floor();
        if ((player_floor == current_floor) && (xz_distance_squared((saddr)&warp->position, (saddr)&player->position) < (range * range))) {
            return player;
        }
    }
    return NULL;
}
#pragma pop

s32 TObjCityMainWarpChallenge::are_all_players_in_range() {
    Obj_80186B34 *arg0 = (Obj_80186B34 *)this;
    s32 r;
    s32 i;
    u8 *p;
    r = 1;
    for (i = 0; i < 4; i++) {
        p = (u8 *)get_player_by_client_id(i);
        if (p != 0) {
            if (((TObjPlayer *)p)->get_floor() != get_current_floor() || ((f32 (*)(void *, void *))xz_distance_squared)(p + 0x38, arg0->pos) > this->warp_range * this->warp_range) {
                r = 0;
            }
        }
    }
    return r;
}

s32 TObjCityMainWarp::get_phase_flag() {
    return ((get_main_phase() - 0xF) == 0) ? lbl_805D55C0 : 0;
}

s32 *TObjCityMainWarp__sub_80186AF4(void) {
    return &lobby_name_string_buffer.value;
}

void TWindowMenu::set_flag70_bit10() { this->m_70 |= 0x10; }

void TObjCityMainWarp::reset() { clear_enabled_main_warps(); update_main_warp_visible_mask(0); }

void TObjCityMainWarp__sub_80186AB8(void) {  }

s32 TObjCityMainWarp::get_floor_warp_bit(s32 floor) {
    s32 bit = -1;
    s32 bits[36] = {
        -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
        -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
    };
    if (is_warp_excluded_area(get_floor_area(floor)) == 0) {
        bit = bits[floor];
    }
    return bit;
}

void TObjCityMainWarp::set_active_bit(s32 floor) {
    s32 floor_warp_bit;

    floor_warp_bit = TObjCityMainWarp::get_floor_warp_bit(floor);
    if (floor_warp_bit >= 0) {
        TObjCityMainWarp__enabled_destinations |= 1 << floor_warp_bit;
    }
}

void update_main_warp_visible_mask(s32 select_type) {
    s32 b;
    s32 c;
    s32 a;
    s32 i;
    TObjCityMainWarp__visible_destination_mask = TObjCityMainWarp__enabled_destinations;
    if (TLobby::get_instance() == 0) {
        TObjCityMainWarp__visible_destination_mask |= 1;
        if ((TObjEneDD::is_main_phase_15() != 0) || (is_split_screen() != 0)) {
            a = 0x17;
            b = 0x20;
            c = 0x2A;
        } else {
            a = 0x18;
            b = 0x21;
            c = 0x30;
        }
        if (get_story_flag(a) != 0) {
            TObjCityMainWarp__visible_destination_mask |= 4;
        }
        if (get_story_flag(b) != 0) {
            TObjCityMainWarp__visible_destination_mask |= 0x20;
        }
        if (get_story_flag(c) != 0) {
            TObjCityMainWarp__visible_destination_mask |= 0x80;
        }
        for (i = 10; i < 17; i++) {
            TObjCityMainWarp__visible_destination_mask &= ~(1 << i);
        }
        return;
    }
    switch (select_type) {
    case 0:
        TObjCityMainWarp::update_unlock_flags();
        break;
    case 1:
        TObjCityMainWarp::init_visible_mask();
        break;
    case 2:
        TObjCityMainWarp::update_warp_flags_from_story();
        break;
    }
    for (i = 11; i < 15; i++) {
        TObjCityMainWarp__visible_destination_mask &= ~(1 << i);
    }
}

void TObjCityMainWarp::update_unlock_flags() {
    s32 var_r31;
    s32 var_r30;
    s32 flag;

    TObjCityMainWarp__visible_destination_mask |= 1;
    if ((TObjEneDD::is_main_phase_15() != 0) || (is_split_screen() != 0)) {
        flag = 0x4C;
        var_r31 = 0x4F;
        var_r30 = 0x52;
    } else {
        flag = 0x4D;
        var_r31 = 0x50;
        var_r30 = 0x53;
    }
    if (get_story_flag(flag) != 0) {
        TObjCityMainWarp__visible_destination_mask |= 4;
    }
    if (get_story_flag(var_r31) != 0) {
        TObjCityMainWarp__visible_destination_mask |= 0x10;
    }
    if (get_story_flag(var_r30) != 0) {
        TObjCityMainWarp__visible_destination_mask |= 0x200;
    }
}

void TObjCityMainWarp::init_visible_mask() {
    s32 flag;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 var_ctr;
    s32 var_ctr_2;
    s32 var_r4;
    s32 i;
    s32 var_r5_2;
    TObjCityMainWarp__visible_destination_mask |= 1;
    if ((TObjEneDD::is_main_phase_15() != 0) || (is_split_screen() != 0)) {
        flag = 0x4C;
    } else {
        flag = 0x4D;
    }
    if (get_story_flag(flag) != 0) {
        TObjCityMainWarp__visible_destination_mask |= 4;
    }
    for (i = 4; i < 11; i++) {
        TObjCityMainWarp__visible_destination_mask &= ~(1 << i);
    }
    for (i = 0xF; i < 0x11; i++) {
        TObjCityMainWarp__visible_destination_mask &= ~(1 << i);
    }
}

void TObjCityMainWarp::update_warp_flags_from_story() {
    s32 var_r31;
    s32 flag;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 var_ctr;
    s32 var_ctr_2;
    s32 var_r4;
    s32 i;
    s32 var_r5_2;
    if ((TObjEneDD::is_main_phase_15() != 0) || (is_split_screen() != 0)) {
        flag = 0x4F;
        var_r31 = 0x52;
    } else {
        flag = 0x50;
        var_r31 = 0x53;
    }
    if (get_story_flag(flag) != 0) {
        TObjCityMainWarp__visible_destination_mask |= 0x10;
    }
    if (get_story_flag(var_r31) != 0) {
        TObjCityMainWarp__visible_destination_mask |= 0x200;
    }
    for (i = 0; i < 4; i++) {
        TObjCityMainWarp__visible_destination_mask &= ~(1 << i);
    }
    for (i = 0xF; i < 0x11; i++) {
        TObjCityMainWarp__visible_destination_mask &= ~(1 << i);
    }
}

void TObjCityMainWarp::clear_active_bit(s32 floor) {
    saddr floor_warp_bit;

    floor_warp_bit = TObjCityMainWarp::get_floor_warp_bit(floor);
    if (floor_warp_bit >= 0) {
        TObjCityMainWarp__enabled_destinations &= ~(1 << floor_warp_bit);
    }
}

void clear_enabled_main_warps(void) { TObjCityMainWarp__enabled_destinations = 0; }

void unlock_main_warp_destination(s32 id) {
    if (TLobby::get_instance() == 0) {
        TObjCityMainWarp::set_active_bit(id);
        if (id == 8) {
            set_story_flag_or_send_quest_flag(0x30);
        }
    } else {
        switch (id) {
        case 5: case 6: case 7: case 8: case 9:
        case 12: case 13: case 14: case 15:
            break;
        default:
            TObjCityMainWarp::set_active_bit(id);
            break;
        }
    }
}

TObjCityMainWarp::TObjCityMainWarp(TObject *parent, void *set_data) : TObjAreaWarp(parent, set_data) {
    s32 i;
    s32 j;
    void *p;
    m_name = class_name;
    warp_range = 25.0f;
    frame = 0.0f;
    for (i = 0; i < 17; i++) {
        menu_destinations[i] = 0;
    }
    for (j = 0; j < 17; j++) {
        lobby_menu_destinations[j] = 0;
    }
    if (is_split_screen() == 1) {
        p = ::operator new(0x88);
        if (p != NULL) {
            p = ((TAdVIConfigGC *)p)->init(&position, 25.0f);
        }
        vi_config = (TAdVIConfigGC *)p;
    } else {
        vi_config = NULL;
    }
    select_type = set_params[1];
    if (select_type < 0) {
        select_type = 0;
    }
    if (select_type > 2) {
        select_type = 2;
    }
}

TObjCityMainWarp::~TObjCityMainWarp() {}

void *TObjCityMainWarp::create(void *set_data) {
    return new TObjCityMainWarp(tl_05, set_data);
}

#pragma push
#pragma opt_lifetimes off
void TObjCityMainWarp::open_confirm_window(s32 client_id) {
    s32 i;
    s32 n;
    s32 j;
    s32 k;
    s32 j2;
    s32 k2;

    if (menu_window != 0) {
        return;
    }
    if (is_quest_active() == 0) {
        update_main_warp_visible_mask(select_type);
    } else {
        TObjCityMainWarp__visible_destination_mask = TObjCityMainWarp__enabled_destinations;
    }
    if (TLobby::get_instance() == 0) {
        for (i = 0; i < 17; i++) {
            menu_destinations[i] = 0;
        }
        n = 0;
        for (i = 0; i < 17; i++) {
            if (TObjCityMainWarp__visible_destination_mask & (1 << i)) {
                menu_destinations[n++] = i;
            }
        }
    } else {
        for (i = 0; i < 17; i++) {
            lobby_menu_destinations[i] = 0;
        }
        n = 0;
        for (i = 0; i < 17; i++) {
            if (TObjCityMainWarp__visible_destination_mask & (1 << i)) {
                lobby_menu_destinations[n++] = i;
            }
        }
    }
    if (n > 0) {
        menu_window = (saddr)create_window_menu((saddr)get_window_layout_position(0x32), n, client_id);
        if (menu_window != 0) {
            if (TLobby::get_instance() == 0) {
                for (j = 0, k = 0; j < 17; j++) {
                    if (TObjCityMainWarp__visible_destination_mask & (1 << j)) {
                        if (get_game_play_mode() == 1) {
                            ((TWindowMenu *)menu_window)->add_text_entry((saddr)TObjCityMainWarp__sub_80186AF4(), 0xE, k);
                        } else {
                            ((TWindowMenu *)menu_window)->add_text_entry(get_localized_text_entry(9, city_warp_group9_text_table[j]), 0xE, k);
                        }
                        k++;
                    }
                }
            } else {
                for (j2 = 0, k2 = 0; j2 < 17; j2++) {
                    if (TObjCityMainWarp__visible_destination_mask & (1 << j2)) {
                        if (get_game_play_mode() == 1) {
                            ((TWindowMenu *)menu_window)->add_text_entry((saddr)TObjCityMainWarp__sub_80186AF4(), 0xE, k2);
                        } else {
                            ((TWindowMenu *)menu_window)->add_text_entry(get_localized_text_entry(9, city_warp_group9_text_table_b[j2]), 0xE, k2);
                        }
                        k2++;
                    }
                }
            }
            ((TWindowMenu *)menu_window)->set_flag70_bit10();
            ((TWindowMenu *)menu_window)->set_loss_flag();
            ((TWindowMenu *)menu_window)->update_layout_height(288.0f);
            if (((TWindowSubComCardList *)menu_window)->target_size[1] > 160.0f) {
                ((TWindowSubComCardList *)menu_window)->set_scroll_target(288.0f, 160.0f);
            }
            align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(menu_window));
        }
    }
    request_active_window_close();
    user_client_id = client_id;
}
#pragma pop

void TObjCityMainWarp::close_menu() { if (menu_window != 0) { TObjWarpBase::close_menu(); TWindowCtrl::clear_flag(); } }

s32 TObjCityMainWarp::is_choice_confirmed() {
    if (TLobby::get_instance() == 0) {
        if (menu_window != 0 && ((TWindowMenu *)menu_window)->is_decided() != 0) {
            dest_floor = city_warp_floor_destination_table[menu_destinations[((TWindowMenu *)menu_window)->get_selected_value()]];
            return 1;
        }
        return 0;
    }
    if (menu_window != 0 && ((TWindowMenu *)menu_window)->is_decided() != 0) {
        dest_floor = city_warp_floor_destination_table_b[lobby_menu_destinations[((TWindowMenu *)menu_window)->get_selected_value()]];
        return 1;
    }
    return 0;
}

s32 TObjCityMainWarp::is_choice_confirmed_by(s32) { return is_choice_confirmed(); }

s32 TObjCityMainWarp::is_warp_enabled() {
    if ((get_game_play_mode() == 1) && (is_quest_active() == 0)) {
        return 0;
    }
    return TObjAreaWarp::is_warp_enabled();
}

void TObjCityMainWarp::run_task() {
    f32 lim = (f32)(city_common_model_archive->motions[7].motion->frameCount - 1);

    frame += 4.0f;
    if (frame >= lim) {
        frame -= lim;
    }
    handle_area_selection();
}

void TObjCityMainWarp::render() {
    if (update_object_view_visibility(400.0f, 35.0f) != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(city_common_texture_list));
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_ginja_object((void *)city_common_model_archive->models[12].model);
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion((void *)city_common_model_archive->models[0].model, city_common_model_archive->motions[5].motion, this->frame);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TObjCityMainWarp::debug_print_area_num() {
    select_type = set_params[1];
    if (select_type < 0) {
        select_type = 0;
    }
    if (select_type > 2) {
        select_type = 2;
    }
    const char *type_names[3] = {"SELECT TYPE NORMAL", "SELECT TYPE VR", "SELECT TYPE CTRL CENTER"};
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130021, "%s", type_names[select_type]);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

TObjCityAreaWarp::TObjCityAreaWarp(TObject *parent, void *set_data) : TObjAreaWarp(parent, set_data) {
    this->m_name = class_name;
    warp_range = 23.0f;
    this->frame = 0.0f;
    this->dest_floor = 15;
}

TObjCityAreaWarp::~TObjCityAreaWarp() {}

void *TObjCityAreaWarp::create(void *set_data) {
    return new TObjCityAreaWarp(tl_05, set_data);
}

void TObjCityAreaWarp::open_confirm_window(s32 client_id) {
    if (menu_window == 0) {
        menu_window = (saddr)create_window_menu((saddr)get_window_layout_position(0x33), 1, client_id);
        ((TWindowMenu *)menu_window)->add_text_entry(get_localized_text_entry(9, 0x24), 0xA, 0, -1);
        ((TWindowMenu *)menu_window)->set_flag70_bit10();
        ((TWindowMenu *)menu_window)->set_flag_40();
        ((TWindowMenu *)menu_window)->calc_window_size();
        align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(menu_window));
        user_client_id = client_id;
    }
}

void TObjCityAreaWarp::run_task() {
    Obj_80185BE8 *arg0 = (Obj_80185BE8 *)this;
    f32 lim;
    if (TObjEneDD::is_main_phase_15() != 0) {
        lim = (f32)(city_common_model_archive->motions[7].motion->frameCount - 1);
        arg0->t += 4.0f;
        if (arg0->t >= lim) {
            arg0->t -= lim;
        }
        ((TObjAreaWarp *)arg0)->handle_area_selection();
    }
}

void TObjCityAreaWarp::do_warp() {
    if (this->update_object_view_visibility(400.0f, 32.0f) != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(city_common_texture_list));
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion((void *)city_common_model_archive->models[1].model, city_common_model_archive->motions[6].motion, this->frame);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TObjCityAreaWarp::render() { if (TObjEneDD::is_main_phase_15() != 0) { do_warp(); } }

void TObjCityAreaWarp::debug_print_area_num() { this->do_warp(); }

void TObjCityAreaWarp::confirm_area_transfer(TObjPlayer *) {
    play_sound_effect(0x40003205, 0, 0, 0);
    TLobby__data_805D5CE8 = 1;
}

TObjCityMapWarp::TObjCityMapWarp(TObject *parent, void *set_data) : TObjMapWarp(parent, set_data) {
    m_name = class_name;
    clamp_destination_index();
    warp_range = 23.0f;
    *(f32 *)((s8 *)this + 0xFC) = 0.0f;
}

TObjCityMapWarp::~TObjCityMapWarp() {}

void *TObjCityMapWarp::create(void *set_data) {
    return new TObjCityMapWarp(tl_05, set_data);
}

void TObjCityMapWarp::open_confirm_window(s32 client_id) {
    if (playerPopups[client_id] == NULL) {
        playerPopups[client_id] = (TWindowMenu *)create_window_menu((saddr)get_window_layout_position(0x33), 1, client_id);
        clamp_destination_index();
        ((TWindowMenu *)playerPopups[client_id])->add_text_entry(get_localized_text_entry(9, map_warp_dest_text_ids[set_params[2]]), 0xA, 0, -1);
        ((TWindowMenu *)playerPopups[client_id])->set_flag70_bit10();
        ((TWindowMenu *)playerPopups[client_id])->set_flag_40();
        ((TWindowMenu *)playerPopups[client_id])->calc_window_size();
        align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(playerPopups[client_id]));
    }
}

void TObjCityMapWarp::clamp_destination_index() {
    saddr var_r0;
    var_r0 = this->set_params[2];
    if (var_r0 < 0) {
        var_r0 = 0;
    } else if (var_r0 >= 3) {
        var_r0 = 1;
    }
    this->set_params[2] = var_r0;
}

int TObjCityMapWarp::is_field88_zero() { return *(u32*)((char*)this + 0x88) == 0; }

void TObjCityMapWarp::run_task() {
    Obj_80185824 *arg0 = (Obj_80185824 *)this;
    u32 n = city_common_model_archive->motions[7].motion->frameCount;
    f32 lim = (n - 1);
    arg0->fFC += 4.0f;
    if (arg0->fFC >= lim) {
        arg0->fFC -= lim;
    }
    if (TLobby::get_instance() == 0 && (get_game_play_mode() == 1 || get_game_play_mode() == 2)) {
        return;
    }
    ((TObjMapWarp *)arg0)->process_player_warps();
}

void TObjCityMapWarp::render() {
    if (this->update_object_view_visibility(400.0f, 32.0f) != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(city_common_texture_list));
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        if (is_field88_zero() != 0) {
            draw_ginja_object((void *)city_common_model_archive->models[13].model);
            TParticleCtrl::begin_effect_render();
            draw_ginja_model_with_motion((void *)city_common_model_archive->models[3].model, city_common_model_archive->motions[7].motion, this->animation_frame);
            TParticleCtrl::end_effect_render();
        } else {
            TParticleCtrl::begin_effect_render();
            draw_ginja_model_with_motion((void *)city_common_model_archive->models[1].model, city_common_model_archive->motions[6].motion, this->animation_frame);
            TParticleCtrl::end_effect_render();
        }
        pop_matrix();
    }
}

const char *labo_map_warp_dest_name_table_a[3] = {"GOVERNOR", "CITY", "LABO"};

void TObjCityMapWarp::draw_debug_destinations() {
    Obj_80185664 *self = (Obj_80185664 *)this;
    ((TObjCityMapWarp *)self)->clamp_destination_index();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x13001C, "<- DST POS X");
    debug_printf_at(0x13001D, "<- DST POS Y");
    debug_printf_at(0x13001E, "<- DST POS Z");
    debug_printf_at(0x130020, "<- DST ANG Y");
    debug_printf_at(0x130021, "<- MODEL TYPE");
    debug_printf_at(0x130022, "<- MESSAGE : %s", labo_map_warp_dest_name_table_a[self->dest]);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

TObjLaboMapWarp::TObjLaboMapWarp(TObject *parent, void *set_data) : TObjMapWarp(parent, set_data) {
    m_name = class_name;
    clamp_index();
    warp_range = 23.0f;
    animation_frame = 0.0f;
}

TObjLaboMapWarp::~TObjLaboMapWarp() {}

void *TObjLaboMapWarp::create(void *set_data) {
    return new TObjLaboMapWarp(tl_05, set_data);
}

void TObjLaboMapWarp::load_static_resource() {
    BmlResource *resource = new BmlResource(5, (BmlResourceDescriptor *)&bm_obj_warp_labo_resource_descriptor, 0, 0, NULL);
    TObjLaboMapWarp__resource_bundle = resource;
}

void TObjLaboMapWarp::release_static_resource() {
    if (TObjLaboMapWarp__resource_bundle != NULL) {
        delete (BmlResource *)TObjLaboMapWarp__resource_bundle;
        TObjLaboMapWarp__resource_bundle = NULL;
    }
}

void TObjLaboMapWarp::open_confirm_window(s32 client_id) {
    if (playerPopups[client_id] == NULL) {
        playerPopups[client_id] = (TWindowMenu *)create_window_menu((saddr)get_window_layout_position(0x33), 1, client_id);
        clamp_index();
        ((TWindowMenu *)playerPopups[client_id])->add_text_entry(get_localized_text_entry(9, map_warp_dest_text_ids[set_params[2]]), 0xA, 0, -1);
        ((TWindowMenu *)playerPopups[client_id])->set_flag70_bit10();
        ((TWindowMenu *)playerPopups[client_id])->set_flag_40();
        ((TWindowMenu *)playerPopups[client_id])->calc_window_size();
        align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(playerPopups[client_id]));
    }
}

void TObjLaboMapWarp::clamp_index() {
    saddr var_r0;
    var_r0 = this->set_params[2];
    if (var_r0 < 0) {
        var_r0 = 0;
    } else if (var_r0 >= 3) {
        var_r0 = 2;
    }
    this->set_params[2] = var_r0;
}

int TObjLaboMapWarp::is_field88_zero() { return set_params[1] == 0; }

void TObjLaboMapWarp::run_task() {
    f32 lim;
    lim = (f32)(get_bml_motion(TObjLaboMapWarp__resource_bundle, 0)->frameCount - 1);
    animation_frame += 4.0f;
    if (animation_frame >= lim) {
        animation_frame -= lim;
    }
    if (TLobby::get_instance() == 0 && (get_game_play_mode() == 1 || get_game_play_mode() == 2)) {
        return;
    }
    process_player_warps();
}

void TObjLaboMapWarp::render() {
    s32 temp_r31;

    if (this->update_object_view_visibility(400.0f, 32.0f) != 0) {
        TObjFish::set_global_param(get_bml_texlist((BmlResource *)TObjLaboMapWarp__resource_bundle, 1));
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        if (is_field88_zero() != 0) {
            draw_ginja_object((void *)get_bml_model((BmlResource *)TObjLaboMapWarp__resource_bundle, 1));
            TParticleCtrl::begin_effect_render();
            draw_ginja_model_with_motion((void *)get_bml_model((BmlResource *)TObjLaboMapWarp__resource_bundle, 0), get_bml_motion(TObjLaboMapWarp__resource_bundle, 0), animation_frame);
            TParticleCtrl::end_effect_render();
        } else {
            TParticleCtrl::begin_effect_render();
            draw_ginja_model_with_motion((void *)get_bml_model((BmlResource *)TObjLaboMapWarp__resource_bundle, 0), get_bml_motion(TObjLaboMapWarp__resource_bundle, 0), animation_frame);
            TParticleCtrl::end_effect_render();
        }
        pop_matrix();
    }
}

const char *labo_map_warp_dest_name_table_b[3] = {"GOVERNOR", "CITY", "LABO"};

void TObjLaboMapWarp::draw_debug_destinations() {
    clamp_index();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x13001C, "<- DST POS X");
    debug_printf_at(0x13001D, "<- DST POS Y");
    debug_printf_at(0x13001E, "<- DST POS Z");
    debug_printf_at(0x130020, "<- DST ANG Y");
    debug_printf_at(0x130021, "<- MODEL TYPE");
    debug_printf_at(0x130022, "<- MESSAGE : %s", labo_map_warp_dest_name_table_b[set_params[2]]);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

}

