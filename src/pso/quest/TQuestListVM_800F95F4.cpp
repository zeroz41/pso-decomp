#include "types.h"
#include "pso/misc/TLobby_8007C550.h"
#include "pso/unk/text_800F7DAC.h"
#include "pso/system/byteswap.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/quest/TQuestListVM.h"

extern "C" {
s32 subtractive_rng_seed(s32 *, u32);
}

u32 decrypt_quest_data(void *src, s32 size, void *dst, u32 capacity) {
    QuestDownloadFile *file = (QuestDownloadFile *)src;
    s32 rng[60];
    u32 decompressed_size;
    u32 seed;

    decompressed_size = file->decompressed_size;
    seed = file->seed;
    bswap_32(&decompressed_size);
    bswap_32(&seed);
    if (decompressed_size > capacity) {
        return 0U;
    }
    __ct__14SubtractiveRngFv(&rng[0]);
    subtractive_rng_seed(&rng[0], seed);
    ((TAdSinglePlyChrSelectGC *)(&rng[0]))->crypt_data_be((u32 *)file->data, (s32)(size - 8));
    prs_decompress_buffer((s32)file->data, (s32)dst);
    return decompressed_size;
}
