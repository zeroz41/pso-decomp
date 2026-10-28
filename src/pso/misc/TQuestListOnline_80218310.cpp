#include "types.h"
#include "pso/misc/TPlyJoinLobbyEntry.h"
#include "pso/misc/TQuestListOnline_80218310.h"
#include "pso/misc/TShopWindowBase.h"
#include "pso/misc/TQuestListOnline.h"
#include "pso/TShopWindowBase.h"
#include "pso/quest/TQuestListVM.h"

extern "C" {

extern s32 __vt__16TQuestListOnline[];
extern void *TQuestListOnline__class_name;
void memset(void *, int, int);
extern void * TQuestListOnline__instance;
struct VOff_80218310_arg0 { char pad_0[0x4C]; char f_4C[1]; };

void *TQuestListOnline__ct(TQuestListOnline *quest_list_online, void *arg1, void *arg2, void *arg3) {
    struct VOff_80218310_arg0 *self = (struct VOff_80218310_arg0 *)quest_list_online;
    __ct__15TShopWindowBaseFv(quest_list_online);
    *(s32 **)((s8 *)quest_list_online + 0x18) = __vt__16TQuestListOnline;
    __ct__13GameListEntryFv((s32)self->f_4C);
    *(void * *)&quest_list_online->m_name = TQuestListOnline__class_name;
    quest_list_online->list_window = 0;
    quest_list_online->description_window = 0;
    quest_list_online->info_window = 0;
    quest_list_online->confirm_window = 0;
    quest_list_online->sequence = arg2;
    quest_list_online->selected_index = 0;
    *(u32 *)((s8 *)quest_list_online + 0x28) = 0;
    *(u32 *)((s8 *)quest_list_online + 0x2C) = 0;
    *(u32 *)((s8 *)quest_list_online + 0x34) = 0;
    quest_list_online->selection_stage = 0;
    *(void **)((s8 *)quest_list_online + 0x24) = arg3;
    memset(self->f_4C, 0, 28);
    ((TShopWindowBase *)quest_list_online)->set_field_20(0);
    TQuestListOnline__instance = quest_list_online;
    return quest_list_online;
}

}
