#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/ui/charcreate/CharacterLoadBuffer.h"
#include "pso/ui/charcreate/TChCrLoadGmNjReq.h"
#include "pso/system/BmlAccessors.h"
#include "pso/network/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby_8001EF5C.h"


void TChCrLoadGmNjReq::start_character_load_task() {
    BmlResource *request;

    if ((TLobby::tmp_buf_is_free() != 0) && (this->try_acquire_slot() != 0)) {
        request = static_cast<BmlResource *>(::operator new(sizeof(BmlResource)));
        if (request != NULL) {
            request = init_bin_model_request(request, 6, model_ids, &model_ids[1], NULL, NULL, get_character_load_buffer(load_slot));
        }
        loaded_bml = request;
        if (request != NULL) {
            load_timer = 0x12C;
            state = 1;
        }
    }
}

