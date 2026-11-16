#include "types.h"
#include "pso/unk/text_801F43A8.h"

struct OfflineQuestFilenameBufferB { s32 value; u8 remaining[0x1C]; };
extern OfflineQuestFilenameBufferB offline_quest_filename_buffer_b;
s32 *fn_801F43A8(void) {
    return &offline_quest_filename_buffer_b.value;
}
