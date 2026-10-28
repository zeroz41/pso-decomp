#include "types.h"
#include "pso/TMainTask.h"
#include "pso/item/TUnk_8049F8E0.h"
#include "pso/misc/TMainCursor.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
s32 get_entity_id(void *);
int get_type_id__10TObjPlayerFv();
s32 TObjPlayer__sub_80116620(s32, s32);
s32 sub_801A1DDC__10TObjPlayerFv(void *);
s32 send_6x33_revive_player(s32, s32);
}

#pragma push
#pragma scheduling off
void TUnk_8049F8E0::apply_use_effect() {
    s32 temp_r3;
    u32 temp_r424;
    if (sub_801A1DDC__10TObjPlayerFv(*(void * *)&this->owner) != 0) {
        temp_r424 = (u32)this->owner->m_424;
        if (temp_r424 != 0U) {
            temp_r3 = ((TMainCursor *)temp_r424)->find_by_pos(4, 9);
            if (temp_r3 != 0) {
                TObjPlayer__sub_80116620(temp_r3 + 0x9C, 0);
                if ((u16) get_type_id__10TObjPlayerFv() != 0xffffU) {
                    TObjPlayer__sub_80116620(temp_r3 + 0x9C, 0);
                    send_6x33_revive_player(get_entity_id(*(void * *)&this->owner), get_type_id__10TObjPlayerFv());
                }
            }
        }
    }
}
#pragma pop

TUnk_8049F8E0::~TUnk_8049F8E0() {}

TUnk_8049F8E0::TUnk_8049F8E0(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *create_moon_atomizer_item(u8 *item) {
    if (item != NULL) {
        return new TUnk_8049F8E0(tl_05, item);
    }
    return NULL;
}
