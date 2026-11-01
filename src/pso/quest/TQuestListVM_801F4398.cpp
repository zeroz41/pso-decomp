#include "types.h"
#include "pso/misc/TQuestListOnline.h"
#include "pso/quest/TQuestListVM.h"

u8 *TQuestListVM::get_quest_dat() { return quest_data_output_cursor; }

    extern int online_quest_dat_buffer;
int TQuestListOnline::get_quest_list_flag() {  return online_quest_dat_buffer; }
