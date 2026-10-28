#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/unk/TUnk_804E1BB0.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802D50A0.h"
#include "pso/unk/text_80120908.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/TAdMultiSelGameModeGC.h"

extern "C" {
void copy_vec2__28TWindowSubSymbolChatPartsSetFPv(void *);
s32 TAdMultiPlyChrSelectGC::get_player_index() { return this->m_24; }
void TAdMultiPlyChrSelectGC::set_cursor_index(s32 v) { this->m_24 = v; }
void TAdMultiPlyChrSelectGC::set_field_100(s32 v) { *(s32*)((char*)this + 0x100) = v; }

void fn_802D50B8(void *arg0, void *arg1, void *arg2, void *arg3) {
    copy_vec2__28TWindowSubSymbolChatPartsSetFPv((void *)((char *)arg0 + 132));
    ((void (*)(void *, void *))copy_vec2__28TWindowSubSymbolChatPartsSetFPv)((void *)((char *)arg0 + 140), arg2);
    ((void (*)(void *, void *))copy_vec2__28TWindowSubSymbolChatPartsSetFPv)((void *)((char *)arg0 + 148), arg3);
}
void TUnk_804E1BB0::reserved_53() {
    u32 temp_r0;
    u32 temp_r31;
    s32 arg0 = (s32)this;
    draw_weapon_at_joint(arg0, 0x30);
    ((TItemWeapon *)arg0)->update_trail_slot(0);
    temp_r0 = (u32)((TItemWeapon *)arg0)->second_model;
    temp_r31 = *(u32 *)((s8 *)arg0 + 0xF4);
    if (temp_r0 != 0U) {
        *(u32 *)((s8 *)arg0 + 0xF4) = temp_r0;
    }
    draw_weapon_at_joint(arg0, 0x23);
    ((TItemWeapon *)arg0)->update_trail_slot(1);
    *(u32 *)((s8 *)arg0 + 0xF4) = temp_r31;
}

}
