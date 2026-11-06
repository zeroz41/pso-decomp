#include "types.h"
#include "pso/ui/city/THunterGuildSeqOffline_801F3718.h"

struct RecoveredGlobal_801F3728_THunterGuildSeqOffline__data_80513DC8 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801F3738_THunterGuildSeqOffline__data_80513DC8 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801F3748_THunterGuildSeqOffline__data_80513DC8 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801F3718_THunterGuildSeqOffline__data_80513DC8 {
    s32 value;
    u8 remaining[0xC];
};

extern RecoveredGlobal_801F3728_THunterGuildSeqOffline__data_80513DC8 THunterGuildSeqOffline__quest_result_callbacks;
typedef char RecoveredGlobal_801F3728_THunterGuildSeqOffline__data_80513DC8_size[sizeof(RecoveredGlobal_801F3728_THunterGuildSeqOffline__data_80513DC8) == 0x10 ? 1 : -1];

typedef char RecoveredGlobal_801F3718_THunterGuildSeqOffline__data_80513DC8_size[sizeof(RecoveredGlobal_801F3718_THunterGuildSeqOffline__data_80513DC8) == 0x10 ? 1 : -1];
void set_quest_exit_callback(s32 arg0) {
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_801F3718_THunterGuildSeqOffline__data_80513DC8 *)&THunterGuildSeqOffline__quest_result_callbacks).value) + 0xC) = arg0;
}

void set_quest_cancel_callback(s32 arg0) {
    *(s32 *)((s8 *)&THunterGuildSeqOffline__quest_result_callbacks.value + 8) = arg0;
}
typedef char RecoveredGlobal_801F3738_THunterGuildSeqOffline__data_80513DC8_size[sizeof(RecoveredGlobal_801F3738_THunterGuildSeqOffline__data_80513DC8) == 0x10 ? 1 : -1];
void set_quest_success_callback(s32 arg0) {
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_801F3738_THunterGuildSeqOffline__data_80513DC8 *)&THunterGuildSeqOffline__quest_result_callbacks).value) + 4) = arg0;
}
typedef char RecoveredGlobal_801F3748_THunterGuildSeqOffline__data_80513DC8_size[sizeof(RecoveredGlobal_801F3748_THunterGuildSeqOffline__data_80513DC8) == 0x10 ? 1 : -1];
void THunterGuildSeqOffline__sub_801F3748(s32 arg0) {
    (*(RecoveredGlobal_801F3748_THunterGuildSeqOffline__data_80513DC8 *)&THunterGuildSeqOffline__quest_result_callbacks).value = arg0;
}
