#include "pso/system/memory.h"
#include "pso/unk/text_800FA464.h"
#include "types.h"
#include "pso/unk/text_800FA260.h"
#include "pso/network/TLobby.h"
#include "pso/system/THeap.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

void TLobby::destroy_game_heap() { process_pending_resources(); safe_free(async_file_read_sector_buffer); TLobby::free_chr_select_data(); delete game_heap; }

