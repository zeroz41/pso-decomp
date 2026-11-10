#include "types.h"
#include "pso/player/TObjPlayer_801C1FF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_801BE778.h"
#include "pso/map/FloorArea.h"

extern "C" {

s32 create_inventory__10TObjPlayerFv();

u16 get_entity_id(void *);
extern s32 player_shared_buffer_base;

void TObjPlayer::init_data_table_ptr() {
    create_inventory__10TObjPlayerFv();
    set_action_provider_variant(TObjPlayer__sub_801C2114());
    this->m_db4 = (s32) (player_shared_buffer_base + (get_entity_id(this) * 0x600));
}

}

extern "C" {

int TObjPlayer__sub_801C2114(void);
void bind_saved_inventory_equipment__10TObjPlayerFPvPvi(u8 *p, u8 *records, s32 count);


void TObjPlayer::init_from_source(u8 *arg1) {
    this->inventory_objects = 0;
    create_inventory__10TObjPlayerFv();
    set_action_provider_variant((s16) TObjPlayer__sub_801C2114());
    bind_saved_inventory_equipment__10TObjPlayerFPvPvi(((u8 *)this), arg1 + 0x140, *(s32 *)((s8 *)arg1 + 0x13C));
    this->m_db4 = (s32) (player_shared_buffer_base + (get_entity_id(this) * 0x600));
}

}

extern "C" {


void TObjPlayer::update_recobox(s32 arg0) {
    if (is_current_area_item_enabled() != 0) {
        ((TObjPlayer *)arg0)->sub_801BE9A8();
        return;
    }
    ((TObjPlayer *)arg0)->set_flag_20000();
}
void TObjPlayer::destroy_child() { void* m = this->inventory_objects; if (m) queue_destruction__7TObjectFv(m); }

}
