#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void free_bin_model_request(void*, int);

extern u32 lobby_pigeon_bml_archive;

void TObjPlayer::free_static_instance() {
    if ((u32) lobby_pigeon_bml_archive != 0U) {
        free_bin_model_request((void*)lobby_pigeon_bml_archive, 1);
        lobby_pigeon_bml_archive = 0U;
    }
}

}
