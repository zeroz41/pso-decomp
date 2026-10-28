#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/player/TObjPlayer_80105874.h"
#include "pso/unk/text_80103674.h"
#include "pso/unk/text_8010F168.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TItemLoad.h"
#include "pso/item/TItemBuff.h"
#include "pso/item/TItemData.h"
#include "pso/misc/TWindowSubStatusDisp.h"

struct RecoveredGlobal_801058AC_lbl_8049EE60 {
    s32 value;
    u8 remaining[0x74];
};

extern "C" {
s32 fn_8010F210(s32);
extern RecoveredGlobal_801058AC_lbl_8049EE60 item_class_load_unload_table;
extern s32 lbl_805D5440;
extern int item_class_load_handle;
s32 get_slot_value__10TObjPlayerFPvi(s32 *arg0, s32 arg1);

void TObjPlayer::free_item_globals() { TItemDrop__sub_8010F168((void *)item_class_load_handle, (s16)((void*)1)); item_class_load_handle = 0; TItemLoad::free_all(); TItemBuff::free_all_and_init(); }

typedef char RecoveredGlobal_801058AC_lbl_8049EE60_size[sizeof(RecoveredGlobal_801058AC_lbl_8049EE60) == 0x78 ? 1 : -1];
void TObjPlayer::init_game_resources() {
    fn_80103674();
    TItemLoad::init_resources();
    (*(s32 *)&item_class_load_handle) = fn_8010F210((s32) &item_class_load_unload_table.value);
    ((FlagWord *)(&lbl_805D5440))->reset();
}

void fn_801058E8(void* p) { *(u8*)((char*)p + 0x7) |= 0x1; }

u8 TObjPlayer::is_script_controlled() {
    return (u8) (this->m_324 == 6);
}

int TObjPlayer::activate_d04_slot() { return get_slot_value__10TObjPlayerFPvi((s32 *)((char*)this + 0xd04), 1); }

}
