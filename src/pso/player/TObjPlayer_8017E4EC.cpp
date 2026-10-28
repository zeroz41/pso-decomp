#include "types.h"
#include "pso/misc/TLoadCtrl_80227390.h"
#include "pso/object/TObjBgmColCtrl_8017E8E4.h"
#include "pso/player/TObjPlayer_8017E4EC.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/map/FloorArea.h"

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
void *TObjBgmCol__ct(void *, s32, Set_8017E550 *);
void TLobby__sub_80207F30(Set_8017E550 *);
void *__nw__7TObjectFUl(u32);
extern s32 bgm_zone_category;
extern s32 TObjBgmColCtrl__instance;

extern s32 area_music_filename_table[];

void TObjPlayer::set_camera_mode(s32 arg0) {
    if ((get_quest_bgm_issued_flag() == 0) && (TRaderMapCore::is_not_split_screen() != 1) && (arg0 != (s32) bgm_zone_category)) {
        bgm_zone_category = arg0;
        play_area_music((char *)area_music_filename_table[arg0]);
    }
}
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
            p = __nw__7TObjectFUl(0xA0);
            if (p != NULL) {
                TObjBgmCol__ct(p, TObjBgmColCtrl__instance, &set);
            }
        }
        break;
    case AREA_PIONEER2_EP2:
        for (i = 0; i < 12; i++) {
            VecCopy((Vec *)&set.pos, (const Vec *)&lbl_80443780[i].pos);
            set.radius = lbl_80443780[i].radius;
            set.category = lbl_80443780[i].category;
            p = __nw__7TObjectFUl(0xA0);
            if (p != NULL) {
                TObjBgmCol__ct(p, TObjBgmColCtrl__instance, &set);
            }
        }
        break;
    }
}
