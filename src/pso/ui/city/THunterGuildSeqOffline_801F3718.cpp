#include "types.h"
#include "pso/ui/city/THunterGuildSeqOffline_801F3718.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"

void set_quest_exit_callback(s32 quest_exit_callback) {
    quest_result_callbacks[3] = quest_exit_callback;
}

void set_quest_cancel_callback(s32 quest_cancel_callback) {
    quest_result_callbacks[2] = quest_cancel_callback;
}
void set_quest_success_callback(s32 quest_success_callback) {
    quest_result_callbacks[1] = quest_success_callback;
}
void set_quest_failure_callback(s32 quest_failure_callback) {
    quest_result_callbacks[0] = quest_failure_callback;
}
