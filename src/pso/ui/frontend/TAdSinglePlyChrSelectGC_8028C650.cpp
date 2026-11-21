#include "types.h"
#include "pso/ui/charcreate/CharacterLoadBuffer.h"
#include "pso/ui/charcreate/TChCrLoadGmNjReq.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

void *init_bin_model_request(void *, s32, void *, void *, saddr, saddr, s32);

void TChCrLoadGmNjReq::start_character_load_task() {
    void *request;

    if ((TLobby::tmp_buf_is_free() != 0) && (this->try_acquire_slot() != 0)) {
        request = ::operator new(0x440);
        if (request != NULL) {
            request = init_bin_model_request(request, 6, model_ids, &model_ids[1], 0, 0, (saddr)get_character_load_buffer(load_slot));
        }
        loaded_bml = (BmlResource *)request;
        if (request != NULL) {
            load_timer = 0x12C;
            state = 1;
        }
    }
}

}
