#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

    extern int character_save_file_block_count;
int TAdSinglePlyChrSelectGC::get_flag_count() {  return character_save_file_block_count; }

    extern int system_save_file_block_count;
int TAdSinglePlyChrSelectGC::get_selected_count() {  return system_save_file_block_count; }
