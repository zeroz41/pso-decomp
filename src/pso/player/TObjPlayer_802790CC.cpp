#include "types.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/player/PlayerSlots.h"

extern "C" {



void TObjPlayer::add_status_line(u8 category_icon, uaddr item, s32 arg3) {
    void *temp_r31;

    temp_r31 = (void *)((TWindowBase *)this)->get_array_entry(*(s16 *)((s8 *)this + 0x72));
    if (item == 0U) {
        ((ItemListRow *)temp_r31)->init_status_entry(category_icon, 0, arg3);
        *(f32 *)((s8 *)temp_r31 + 8) += 18.0f;
        reinterpret_cast<ItemListRow *>(temp_r31)->category_style = 0xFFAAAAAA;
    } else {
        ((ItemListRow *)temp_r31)->init_item_row((void *)item, (s32)arg3);
    }
    if (category_icon == 4) {
        *(f32 *)((s8 *)temp_r31 + 8) += 18.0f;
    }
    *(s16 *)((s8 *)this + 0x72) = (s16) (*(s16 *)((s8 *)this + 0x72) + 1);
}

#pragma push
#pragma cplusplus off
void add_status_line__10TObjPlayerFUcUll(void* self, s32 a, void* b, void* c);
void *get_slot_value__10TObjPlayerFPvi(s32 *arg0, s32 arg1);
void copy_to_item_data__5TItemFP9TItemData(void* p, void* out);
s32 get_class_weapon_icon_index__FPvPUc(void* a, u8* self);
#pragma pop
#pragma push
#pragma cplusplus off
#pragma dont_inline off

void build_equipment_list__15TWindowSubEquipFv(void* self) {
    u8 buf[0x18];
    void* q;
    saddr i;
    s32 n;
    s32 a;
    u8* p;

    p = (u8 *)get_player_by_client_id(*(s16 *)((u8 *)self + 0x20));
    if (p != NULL) {
        a = get_class_weapon_icon_index__FPvPUc(self, p);
        q = (void *)get_slot_value__10TObjPlayerFPvi((s32 *)(p + 0xd04), (s32)(6));
        add_status_line__10TObjPlayerFUcUll(self, a, q, (void*)6);
        q = (void *)get_slot_value__10TObjPlayerFPvi((s32 *)(p + 0xd04), (s32)(2));
        add_status_line__10TObjPlayerFUcUll(self, 0xb, q, (void*)2);
        if (q != NULL) {
            copy_to_item_data__5TItemFP9TItemData(q, buf);
            n = (s8)buf[5];
            for (i = 0; i < n; i++) {
                q = (void *)get_slot_value__10TObjPlayerFPvi((s32 *)(p + 0xd04), (s32)(i + 9));
                add_status_line__10TObjPlayerFUcUll(self, 4, q, (void*)(i + 9));
            }
        }
        q = (void *)get_slot_value__10TObjPlayerFPvi((s32 *)(p + 0xd04), (s32)(3));
        add_status_line__10TObjPlayerFUcUll(self, 0xa, q, (void*)3);
        q = (void *)get_slot_value__10TObjPlayerFPvi((s32 *)(p + 0xd04), (s32)(1));
        add_status_line__10TObjPlayerFUcUll(self, 3, q, (void*)1);
    }
}
#pragma pop

}
