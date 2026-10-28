#include "types.h"
#include "pso/object/TObjBgmColCtrl.h"
#include "pso/TObject.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/map/CurrentArea.h"

struct B_8017E410 { u8 pad[0x18]; };

struct V_8017E410 : B_8017E410 { virtual ~V_8017E410(); };

extern "C" {
s32 TObjBgmColCtrl__ct(int, int);
}
void create_bgm_col_zones(void);
extern "C" {
u32 __nw__7TObjectFUl(int);
u32 __ct__7TObjectFP7TObject(int, int);
extern u32 TObjBgmColCtrl__instance;
extern s32 tl_05;
s32 __dt__7TObjectFv(void *, s32);
s32 __dl__7TObjectFPv(void *);
extern void *__vt__14TObjBgmColCtrl[];
void *__dt__14TObjBgmColCtrlFv(void *arg0, s16 arg1);
s32 is_active__14TObjBgmColCtrlFv();
void *get_player_by_client_id(s32 i);
int get_quest_bgm_issued_flag(void);

extern s32 local_client_id;
extern s32 TLobby__event_theme_id;
extern s32 lbl_805D5B04;
extern s32 TObjBgmColCtrl__current_theme_id;

void TObjBgmColCtrl::run_task() {
    s32 temp_r4;

    temp_r4 = this->m_1c;
    this->m_1c = (temp_r4 - 1);
    if ((temp_r4 <= 0) && ((get_current_area() == 0xF) || (get_player_by_client_id(local_client_id) != 0U)) && (get_quest_bgm_issued_flag() == 0)) {
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
                if ((get_current_area() == 0xF) && ((s32) TLobby__event_theme_id != (s32) TObjBgmColCtrl__current_theme_id)) {
                    TObjBgmColCtrl::play_lobby_theme_music();
                }
            }
        }
    }
}
void TObjBgmColCtrl::create_controller() {
    u32 temp_r3;
    u32 temp_r3_2;
    u32 var_r0;
    temp_r3 = __nw__7TObjectFUl(0x1C);
    var_r0 = temp_r3;
    if (var_r0 != 0U) {
        var_r0 = __ct__7TObjectFP7TObject(temp_r3, 0);
    }
    TObjBgmColCtrl__instance = var_r0;
    temp_r3_2 = __nw__7TObjectFUl(0x20);
    if (temp_r3_2 != 0U) {
        TObjBgmColCtrl__ct(temp_r3_2, tl_05);
    }
    create_bgm_col_zones();
}
void *__dt__14TObjBgmColCtrlFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void ***)((s8 *)arg0 + 0x18) = __vt__14TObjBgmColCtrl;
        if (TObjBgmColCtrl__instance != 0) {
            delete (V_8017E410 *)TObjBgmColCtrl__instance;
            TObjBgmColCtrl__instance = 0;
        }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
}
