#include "pso/player/TObjPlayer_801AF2F0.h"
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/collision/TObjBgmColCtrl.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/unk/TLobby.h"

#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/collision/TObjBgmColCtrl_8017E498.h"
#include "pso/object/collision/TObjBgmColCtrl_8017E8E4.h"
#include "pso/player/TObjPlayer_8017E4EC.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/NinjaUtil.h"
#include "pso/object/collision/TObjBgmCol.h"
#include "pso/object/collision/TObjBgmCol_8017E7F0.h"

#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/PlayerSlots.h"


#pragma defer_codegen on

const char *area_music_filename_table[6] = {
    "SHOP.adx", "GUILD.adx", "MEDICAL.adx", "soutoku.adx", "city.adx", "labo.adx",
};

struct Names_8017E1E4 { const char *name[2]; };


s32 bgm_zone_category;
s32 lbl_805D5B04;
// The root the BGM collision zones hang under (created next to the controller).
TObject *TObjBgmColCtrl__instance;
u32 TObjBgmColCtrl__current_theme_id;

void create_bgm_col_zones(void);
extern s32 tl_05;
int get_quest_bgm_issued_flag(void);

extern s32 local_client_id;

struct Row_8017E550 { Vec pos; f32 radius; s32 category; };

const Row_8017E550 lbl_80443690[12] = {
    {{-2.11f, 0.0f, -0.24f}, 72.0f, 4},
    {{-165.09f, 0.0f, 100.0f}, 41.0f, 4},
    {{184.49f, 0.0f, 144.57f}, 38.0f, 4},
    {{206.61f, 0.0f, -104.79f}, 26.0f, 4},
    {{184.93f, 0.0f, 209.99f}, 28.0f, 1},
    {{285.81f, 0.0f, 234.67f}, 31.0f, 1},
    {{236.71f, 0.0f, 309.0f}, 80.0f, 1},
    {{-163.69f, 0.0f, 175.02f}, 33.0f, 0},
    {{213.35f, 0.0f, -181.0f}, 26.0f, 2},
    {{212.49f, 0.0f, -279.87f}, 25.0f, 2},
    {{0.66f, 0.0f, -1728.83f}, 52.0f, 3},
    {{0.0f, 0.0f, -2000.0f}, 81.0f, 3},
};
const Row_8017E550 lbl_80443780[12] = {
    {{160.7f, 0.0f, 40.87f}, 41.0f, 4},
    {{32.6f, 0.0f, 62.73f}, 28.0f, 4},
    {{-21.28f, 0.0f, -60.15f}, 27.0f, 4},
    {{-19.82f, 0.0f, -159.58f}, 30.0f, 4},
    {{42.22f, 0.0f, -151.92f}, 37.0f, 4},
    {{27.0f, 0.0f, 257.4f}, 37.0f, 1},
    {{27.0f, 0.0f, 125.99f}, 28.0f, 1},
    {{-74.8f, 0.0f, -61.64f}, 26.0f, 0},
    {{-75.8f, 0.0f, -160.94f}, 26.0f, 0},
    {{-10000.0f, 0.0f, 36.28f}, 52.0f, 5},
    {{-10000.0f, 30.0f, -187.68f}, 32.0f, 5},
    {{12.82f, 0.0f, -204.0f}, 26.0f, 2},
};

struct Zone_8017E748 { u8 pad[0x9C]; s32 category; };


const char *TObjBgmCol__name = "TObjBgmCol";
const char *TObjBgmColCtrl__name = "TObjBgmColCtrl";

extern s32 lbl_805D62E4;
extern int TQuestBgmCtrl__bgm_issued_flag;

int get_quest_bgm_issued_flag(void) {  return TQuestBgmCtrl__bgm_issued_flag; }

s32 TObjBgmColCtrl::is_active() {
    return (u8)((u8) (lbl_805D62E4 != 0));
}

TObjBgmCol::TObjBgmCol(TObject *parent, void *arg2) : TObjBase(parent) {
#define bgm_col this
    *(saddr *)((s8 *)bgm_col + 0) = (saddr) TObjBgmCol__name;
    bgm_col->apply_object_set_data(arg2);
    bgm_col->m_90 = 1;
    bgm_col->m_98 = (f32) bgm_col->scale.x;
    bgm_col->m_9c = (s32) (bgm_col->set_params[0] % 6);
    if ((s32) bgm_col->m_9c < 0) {
        bgm_col->m_9c = 0;
    }
#undef bgm_col
}

TObjBgmCol::~TObjBgmCol() {

}

void TObjBgmCol::run_task() {
    Zone_8017E748 *zone = (Zone_8017E748 *)this;
    if (get_quest_bgm_issued_flag() == 0) {
        switch (check()) {
        case 1:
            if (bgm_zone_category != zone->category) {
                if (zone->category == 4) {
                    TObjBgmColCtrl::play_lobby_theme_music();
                } else {
                    play_area_music((char *)area_music_filename_table[zone->category]);
                }
                bgm_zone_category = zone->category;
            }
            lbl_805D5B04 = 1;
            return;
        case 0:
            lbl_805D5B04 = 1;
            break;
        case 2:
            break;
        }
    }
}

s32 TObjBgmCol::check() {
    f32 temp_f0;

    temp_f0 = this->m_98;
    if (is_within_distance(temp_f0 * temp_f0) != 0) {
        if ((s32) this->m_90 != 0) {
            this->m_90 = 0;
            return 1;
        }
        return 0;
    }
    if ((s32) this->m_90 != 0) {
        return 2;
    }
    this->m_90 = 1;
    return 3;
}

s32 TObjBgmCol::is_within_distance(f32 farg0) {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if ((player != NULL) && (xyz_distance_squared(&player->position, &position) < farg0)) {
        return 1;
    }
    return 0;
}

void create_bgm_col_zones(void) {
    ObjectSetData set;
    s32 i;
    bgm_zone_category = 4;
    TLobby__sub_80207F30(&set);
    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1:
        for (i = 0; i < 12; i++) {
            VecCopy((Vec *)&set.position, (const Vec *)&lbl_80443690[i].pos);
            set.scale.x = lbl_80443690[i].radius;
            set.set_params[0] = lbl_80443690[i].category;
            new TObjBgmCol(TObjBgmColCtrl__instance, &set);
        }
        break;
    case AREA_PIONEER2_EP2:
        for (i = 0; i < 12; i++) {
            VecCopy((Vec *)&set.position, (const Vec *)&lbl_80443780[i].pos);
            set.scale.x = lbl_80443780[i].radius;
            set.set_params[0] = lbl_80443780[i].category;
            new TObjBgmCol(TObjBgmColCtrl__instance, &set);
        }
        break;
    }
}

void TObjPlayer::set_camera_mode(s32 camera_mode) {
    if ((get_quest_bgm_issued_flag() == 0) && (TRaderMapCore::is_not_split_screen() != 1) && (camera_mode != (s32) bgm_zone_category)) {
        bgm_zone_category = camera_mode;
        play_area_music((char *)area_music_filename_table[camera_mode]);
    }
}

TObjBgmColCtrl::TObjBgmColCtrl(saddr parent) : TObject((TObject *)parent) {
    this->m_name = TObjBgmColCtrl__name;
    this->m_1c = 3;
    TObjBgmColCtrl__current_theme_id = 0;
}

TObjBgmColCtrl::~TObjBgmColCtrl() {
    if (TObjBgmColCtrl__instance != NULL) {
        delete TObjBgmColCtrl__instance;
        TObjBgmColCtrl__instance = NULL;
    }
}

void TObjBgmColCtrl::create_controller() {
    TObjBgmColCtrl__instance = new TObject(NULL);
    new TObjBgmColCtrl(tl_05);
    create_bgm_col_zones();
}

void TObjBgmColCtrl::run_task() {
    s32 temp_r4;

    temp_r4 = this->m_1c;
    this->m_1c = (temp_r4 - 1);
    if ((temp_r4 <= 0) && ((get_current_floor_area() == AREA_LOBBY) || (get_player_by_client_id(local_client_id) != NULL)) && (get_quest_bgm_issued_flag() == 0)) {
        if (TRaderMapCore::is_not_split_screen() == 1) {
            if (TObjBgmColCtrl::is_active() == 0) {
                TObjBgmColCtrl::play_lobby_theme_music();
            }
        } else {
            lbl_805D5B04 = 0;
            TObject *root = TObjBgmColCtrl__instance;
            if (root != NULL) {
                root->run_tasks();
            }
            if ((s32) lbl_805D5B04 == 0) {
                if (TObjBgmColCtrl::is_active() == 0) {
                    TObjBgmColCtrl::play_lobby_theme_music();
                }
                if ((get_current_floor_area() == AREA_LOBBY) && ((s32) TLobby::event_theme_id != (s32) TObjBgmColCtrl__current_theme_id)) {
                    TObjBgmColCtrl::play_lobby_theme_music();
                }
            }
        }
    }
}

void TObjBgmColCtrl::render() {  }


void TObjBgmColCtrl::play_lobby_theme_music() {
    Names_8017E1E4 names = {{"city.adx", "LOBBY.ADX"}};
    const char *name;
    if (get_current_floor_area() == AREA_LOBBY) {
        name = names.name[1];
        TObjBgmColCtrl__current_theme_id = TLobby::event_theme_id;
    } else {
        name = names.name[0];
        TObjBgmColCtrl__current_theme_id = 0;
    }
    switch (TObjBgmColCtrl__current_theme_id) {
    case 1:
        play_area_music("Jinglebell.adx");
        break;
    case 7:
        play_area_music("Zarathustra.adx");
        break;
    case 3:
    case 9:
        play_area_music("Valentine.adx");
        break;
    case 4:
        play_area_music("Easter.adx");
        break;
    case 5:
        play_area_music("HALLOWEEN.adx");
        break;
    case 6:
        play_area_music("open.adx");
        break;
    case 12:
    case 14:
        play_area_music("Event.adx");
        break;
    case 10:
        play_area_music("WEDDING.adx");
        break;
    default:
        play_area_music((char *)name);
        break;
    }
}
