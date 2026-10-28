#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/item/TItemDisconnectCtrl.h"
#include "pso/TItemLoad.h"
#include "pso/item/TItemDrop.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"

extern "C" {

void cleanup_game_objects__9TMainTaskFv(void);
void TEnding__sub_8008C9F8(void);
s32 get_current_floor();
s32 get_game_play_mode();

s32 get_main_phase();
extern s32 item_ground_placement_enabled;
extern s32 lbl_805D5440;
extern s32 tl_item_equip;
extern s32 tl_particlemodel;

void cleanup_game_objects__9TMainTaskFv(void) {
    s32 temp_r29;
    s32 main_phase;
    s32 area;

    TEnding__sub_8008C9F8();
    TItemLoad::create();
    TObjPlayer::spawn_cleanup_helper((void *)tl_particlemodel);
    TObjPlayer::create_cleanup_object((void *)tl_item_equip);
    main_phase = get_main_phase();
    area = get_current_floor_area();
    temp_r29 = get_current_floor();
    item_ground_placement_enabled = 0;
    TLobby::clear_object_count();
    TLobby::respawn_missing_floor_items(temp_r29);
    if ((area == AREA_PIONEER2_EP1) || (area == AREA_PIONEER2_EP2)) {
        ((FlagWord *)(&lbl_805D5440))->set(1);
        if ((main_phase != 0xE) && (main_phase == 0xF)) {
            TItemDrop::refresh_drop_table_if_changed();
        }
    }
    if (get_game_play_mode() == 1) {
        TItemDrop::refresh_drop_table_if_changed();
    }
    if (main_phase == 0xF) {
        new TItemDisconnectCtrl;
    }
    item_ground_placement_enabled = 1;
}

}
