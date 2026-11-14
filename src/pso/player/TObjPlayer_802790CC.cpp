#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 init_status_entry__20TWindowSubStatusDispFPvcUii(void *, u8, s32, s32);
void *get_array_entry__11TWindowBaseFi(void *, s16);


void TObjPlayer::add_status_line(u8 arg1, u32 arg2, s32 arg3) {
    void *temp_r31;

    temp_r31 = get_array_entry__11TWindowBaseFi(this, *(s16 *)((s8 *)this + 0x72));
    if (arg2 == 0U) {
        init_status_entry__20TWindowSubStatusDispFPvcUii(temp_r31, arg1, 0, arg3);
        *(f32 *)((s8 *)temp_r31 + 8) += 18.0f;
        ((TWindowSubStatusDisp *)temp_r31)->m_2c = 0xFFAAAAAA;
    } else {
        ((TWindowSubStatusDisp *)temp_r31)->init_item_row((void *)arg2, (s32)arg3);
    }
    if (arg1 == 4) {
        *(f32 *)((s8 *)temp_r31 + 8) += 18.0f;
    }
    *(s16 *)((s8 *)this + 0x72) = (s16) (*(s16 *)((s8 *)this + 0x72) + 1);
}

#pragma push
#pragma cplusplus off
void add_status_line__10TObjPlayerFUcUll(void* self, s32 a, void* b, void* c);
void* get_player_by_client_id(s32 index);
void* get_slot_value__10TObjPlayerFPvi(void* p, s32 n);
void copy_to_item_data__5TItemFP9TItemData(void* p, void* out);
s32 get_class_weapon_icon_index__FPvPUc(void* a, u8* self);
#pragma pop
#pragma push
#pragma cplusplus off
#pragma dont_inline off

void build_equipment_list__15TWindowSubEquipFv(void* self) {
    u8 buf[0x18];
    void* q;
    s32 i;
    s32 n;
    s32 a;
    u8* p;

    p = get_player_by_client_id(*(s16 *)((u8 *)self + 0x20));
    if (p != NULL) {
        a = get_class_weapon_icon_index__FPvPUc(self, p);
        q = get_slot_value__10TObjPlayerFPvi(p + 0xd04, 6);
        add_status_line__10TObjPlayerFUcUll(self, a, q, (void*)6);
        q = get_slot_value__10TObjPlayerFPvi(p + 0xd04, 2);
        add_status_line__10TObjPlayerFUcUll(self, 0xb, q, (void*)2);
        if (q != NULL) {
            copy_to_item_data__5TItemFP9TItemData(q, buf);
            n = (s8)buf[5];
            for (i = 0; i < n; i++) {
                q = get_slot_value__10TObjPlayerFPvi(p + 0xd04, i + 9);
                add_status_line__10TObjPlayerFUcUll(self, 4, q, (void*)(i + 9));
            }
        }
        q = get_slot_value__10TObjPlayerFPvi(p + 0xd04, 3);
        add_status_line__10TObjPlayerFUcUll(self, 0xa, q, (void*)3);
        q = get_slot_value__10TObjPlayerFPvi(p + 0xd04, 1);
        add_status_line__10TObjPlayerFUcUll(self, 3, q, (void*)1);
    }
}
#pragma pop

}
