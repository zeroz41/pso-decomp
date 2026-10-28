#include "types.h"
#include "pso/player/TObjPlayer_801C1FF8.h"
#include "pso/player/TObjPlayer.h"

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
