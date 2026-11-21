#include "types.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/quest/TQuestListVM.h"

u8 *TQuestListVM::get_quest_dat() { return quest_data_output_cursor; }

extern u8 *online_quest_dat_buffer;
u8 *TQuestListOnline::get_quest_list_flag() { return online_quest_dat_buffer; }
