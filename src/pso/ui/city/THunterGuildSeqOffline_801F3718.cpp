#include "types.h"
#include "pso/ui/city/THunterGuildSeqOffline_801F3718.h"

extern s32 THunterGuildSeqOffline__quest_result_callbacks[];

void set_quest_exit_callback(s32 quest_exit_callback) {
    *(s32 *)((s8 *)&THunterGuildSeqOffline__quest_result_callbacks + 0xC) = quest_exit_callback;
}

void set_quest_cancel_callback(s32 quest_cancel_callback) {
    *(s32 *)((s8 *)&THunterGuildSeqOffline__quest_result_callbacks + 8) = quest_cancel_callback;
}
void set_quest_success_callback(s32 quest_success_callback) {
    *(s32 *)((s8 *)&THunterGuildSeqOffline__quest_result_callbacks + 4) = quest_success_callback;
}
void THunterGuildSeqOffline__sub_801F3748(s32 arg0) {
    THunterGuildSeqOffline__quest_result_callbacks[0] = arg0;
}
