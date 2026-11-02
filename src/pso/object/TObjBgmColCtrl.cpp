#include "types.h"
#include "pso/misc/TLoadCtrl_80227390.h"
#include "pso/object/TObjBgmColCtrl.h"
#include "pso/map/FloorArea.h"
#include "pso/TObject.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjBgmColCtrl_8017E498.h"
#include "pso/object/TObjBgmColCtrl_8017E8E4.h"
#include "pso/player/TObjPlayer_8017E4EC.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/NinjaUtil.h"
#include "pso/object/TObjBgmCol.h"
#include "pso/object/TObjBgmCol_8017E7F0.h"
#include "pso/object/TObjMotion.h"


#pragma defer_codegen on

const char *area_music_filename_table[6] = {
    "SHOP.adx", "GUILD.adx", "MEDICAL.adx", "soutoku.adx", "city.adx", "labo.adx",
};

struct Names_8017E1E4 { const char *name[2]; };

extern char lbl_804438A0[];
extern char lbl_804438B0[];
extern char lbl_804438C0[];
extern char lbl_804438D0[];
extern char lbl_804438DC[];
extern char lbl_804438EC[];
extern char lbl_804438F8[];
extern char lbl_80443904[];

extern u32 TLobby__event_theme_id;
extern u32 TObjBgmColCtrl__current_theme_id;

void create_bgm_col_zones(void);
extern "C" {
u32 __ct__7TObjectFP7TObject(int, int);
extern u32 TObjBgmColCtrl__instance;
extern s32 tl_05;
s32 is_active__14TObjBgmColCtrlFv();
void *get_player_by_client_id(s32 i);
int get_quest_bgm_issued_flag(void);

extern s32 local_client_id;
extern s32 lbl_805D5B04;

}

extern "C" {
extern s32 __vt__14TObjBgmColCtrl[];
}

struct Vec_8017E550 { f32 x, y, z; };

struct Row_8017E550 { Vec_8017E550 pos; f32 radius; s32 category; };

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

struct Set_8017E550 {
    u8 pad[0xC];
    Vec_8017E550 pos;
    u8 pad18[0x24 - 0x18];
    f32 radius;
    u8 pad28[0x30 - 0x28];
    s32 category;
    u8 pad34[0x40 - 0x34];
};

extern "C" {
void TLobby__sub_80207F30(Set_8017E550 *);
extern s32 bgm_zone_category;
}

struct Zone_8017E748 { u8 pad[0x9C]; s32 category; };

extern "C" {
s32 is_within_distance__10TObjBgmColFf(f32);
s32 __ct__8TObjBaseFP7TObject();
void __dl__7TObjectFPv(void *);

extern s32 __vt__10TObjBgmCol[];

const char *TObjBgmCol__name = "TObjBgmCol";
const char *TObjBgmColCtrl__name = "TObjBgmColCtrl";
}

extern s32 lbl_805D62E4;
extern int TQuestBgmCtrl__bgm_issued_flag;

int get_quest_bgm_issued_flag(void) {  return TQuestBgmCtrl__bgm_issued_flag; }

u8 TObjBgmColCtrl::is_active() {
    return (u8) (lbl_805D62E4 != 0);
}

void *TObjBgmCol__ct(TObjBgmCol *bgm_col, s32 arg1, void *arg2) {
    __ct__8TObjBaseFP7TObject();
    *(s32 **)((s8 *)bgm_col + 0x18) = __vt__10TObjBgmCol;
    *(s32 *)((s8 *)bgm_col + 0) = (s32) TObjBgmCol__name;
    bgm_col->apply_object_set_data(arg2);
    bgm_col->m_90 = 1;
    bgm_col->m_98 = (f32) bgm_col->scale.x;
    bgm_col->m_9c = (s32) (bgm_col->set_params[0] % 6);
    if ((s32) bgm_col->m_9c < 0) {
        bgm_col->m_9c = 0;
    }
    return bgm_col;
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
    if (is_within_distance__10TObjBgmColFf(temp_f0 * temp_f0) != 0) {
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
    s32 arg0 = (s32)this;
    u32 player;

    player = (u32)get_player_by_client_id(local_client_id);
    if ((player != 0U) && (xyz_distance_squared((Vec *)(player + 0x38), (Vec *)(arg0 + 0x38)) < farg0)) {
        return 1;
    }
    return 0;
}

void create_bgm_col_zones(void) {
    Set_8017E550 set;
    s32 i;
    void *p;
    bgm_zone_category = 4;
    TLobby__sub_80207F30(&set);
    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1:
        for (i = 0; i < 12; i++) {
            VecCopy((Vec *)&set.pos, (const Vec *)&lbl_80443690[i].pos);
            set.radius = lbl_80443690[i].radius;
            set.category = lbl_80443690[i].category;
            p = TObject::operator new(0xA0);
            if (p != NULL) {
                TObjBgmCol__ct((TObjBgmCol *)p, TObjBgmColCtrl__instance, &set);
            }
        }
        break;
    case AREA_PIONEER2_EP2:
        for (i = 0; i < 12; i++) {
            VecCopy((Vec *)&set.pos, (const Vec *)&lbl_80443780[i].pos);
            set.radius = lbl_80443780[i].radius;
            set.category = lbl_80443780[i].category;
            p = TObject::operator new(0xA0);
            if (p != NULL) {
                TObjBgmCol__ct((TObjBgmCol *)p, TObjBgmColCtrl__instance, &set);
            }
        }
        break;
    }
}

void TObjPlayer::set_camera_mode(s32 arg0) {
    if ((get_quest_bgm_issued_flag() == 0) && (TRaderMapCore::is_not_split_screen() != 1) && (arg0 != (s32) bgm_zone_category)) {
        bgm_zone_category = arg0;
        play_area_music((char *)area_music_filename_table[arg0]);
    }
}

void *TObjBgmColCtrl__ct(void *bgm_col_ctrl, s32 parent) {
    __ct__7TObjectFP7TObject((int)bgm_col_ctrl, parent);
    *(s32 **)((s8 *)bgm_col_ctrl + 0x18) = __vt__14TObjBgmColCtrl;
    ((TObjBgmColCtrl *)bgm_col_ctrl)->m_name = TObjBgmColCtrl__name;
    ((TObjBgmColCtrl *)bgm_col_ctrl)->m_1c = 3;
    TObjBgmColCtrl__current_theme_id = 0;
    return bgm_col_ctrl;
}

TObjBgmColCtrl::~TObjBgmColCtrl() {
    if (TObjBgmColCtrl__instance != 0) {
        delete (TObject *)TObjBgmColCtrl__instance;
        TObjBgmColCtrl__instance = 0;
    }
}

void TObjBgmColCtrl::create_controller() {
    u32 temp_r3;
    void *ctrl;
    u32 var_r0;
    temp_r3 = (u32)TObject::operator new(0x1C);
    var_r0 = temp_r3;
    if (var_r0 != 0U) {
        var_r0 = __ct__7TObjectFP7TObject(temp_r3, 0);
    }
    TObjBgmColCtrl__instance = var_r0;
    ctrl = TObject::operator new(0x20);
    if (ctrl != NULL) {
        TObjBgmColCtrl__ct(ctrl, tl_05);
    }
    create_bgm_col_zones();
}

void TObjBgmColCtrl::run_task() {
    s32 temp_r4;

    temp_r4 = this->m_1c;
    this->m_1c = (temp_r4 - 1);
    if ((temp_r4 <= 0) && ((get_current_floor_area() == AREA_LOBBY) || (get_player_by_client_id(local_client_id) != 0U)) && (get_quest_bgm_issued_flag() == 0)) {
        if (TRaderMapCore::is_not_split_screen() == 1) {
            if (is_active__14TObjBgmColCtrlFv() == 0) {
                TObjBgmColCtrl::play_lobby_theme_music();
            }
        } else {
            lbl_805D5B04 = 0;
            void *thisObj = (void *)(u32)TObjBgmColCtrl__instance;
            if (thisObj != NULL) {
                ((TObject *)thisObj)->run_tasks();
            }
            if ((s32) lbl_805D5B04 == 0) {
                if (is_active__14TObjBgmColCtrlFv() == 0) {
                    TObjBgmColCtrl::play_lobby_theme_music();
                }
                if ((get_current_floor_area() == AREA_LOBBY) && ((s32) TLobby__event_theme_id != (s32) TObjBgmColCtrl__current_theme_id)) {
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
        TObjBgmColCtrl__current_theme_id = TLobby__event_theme_id;
    } else {
        name = names.name[0];
        TObjBgmColCtrl__current_theme_id = 0;
    }
    switch (TObjBgmColCtrl__current_theme_id) {
    case 1:
        play_area_music(lbl_804438A0);
        break;
    case 7:
        play_area_music(lbl_804438B0);
        break;
    case 3:
    case 9:
        play_area_music(lbl_804438C0);
        break;
    case 4:
        play_area_music(lbl_804438D0);
        break;
    case 5:
        play_area_music(lbl_804438DC);
        break;
    case 6:
        play_area_music(lbl_804438EC);
        break;
    case 12:
    case 14:
        play_area_music(lbl_804438F8);
        break;
    case 10:
        play_area_music(lbl_80443904);
        break;
    default:
        play_area_music((char *)name);
        break;
    }
}
