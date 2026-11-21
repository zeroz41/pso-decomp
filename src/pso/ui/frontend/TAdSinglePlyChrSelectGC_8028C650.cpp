#include "types.h"
#include "pso/ui/charcreate/CharacterLoadBuffer.h"
#include "pso/ui/charcreate/TChCrLoadGmNjReq.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

u32 init_bin_model_request(u32, s32, void *, void *, s32, s32, s32);

void TChCrLoadGmNjReq::start_character_load_task() {
    u32 var_r31;

    if ((TLobby::tmp_buf_is_free() != 0) && (this->try_acquire_slot() != 0)) {
        var_r31 = (saddr)::operator new(0x440);
        if (var_r31 != 0U) {
            var_r31 = init_bin_model_request(var_r31, 6, model_ids, &model_ids[1], 0, 0, (s32)get_character_load_buffer(load_slot));
        }
        loaded_bml = (BmlResource *)var_r31;
        if (var_r31 != 0U) {
            load_timer = 0x12C;
            state = 1;
        }
    }
}

}
