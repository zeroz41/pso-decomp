#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

int TObjPlayer__sub_801C2114(void);
void bind_saved_inventory_equipment__10TObjPlayerFPvPvi(u8 *p, u8 *records, s32 count);
s32 create_inventory__10TObjPlayerFv();

u16 get_entity_id(void *);
extern s32 player_shared_buffer_base;

void TObjPlayer::init_from_source(u8 *arg1) {
    this->inventory_objects = 0;
    create_inventory__10TObjPlayerFv();
    set_action_provider_variant((s16) TObjPlayer__sub_801C2114());
    bind_saved_inventory_equipment__10TObjPlayerFPvPvi(((u8 *)this), arg1 + 0x140, *(s32 *)((s8 *)arg1 + 0x13C));
    this->m_db4 = (s32) (player_shared_buffer_base + (get_entity_id(this) * 0x600));
}

}
