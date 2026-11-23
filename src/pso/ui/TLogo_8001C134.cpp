#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/ui/TLogo_8001C134.h"
#include "pso/ui/TLogo.h"
#include "pso/system/task/TObject.h"

#include "pso/render/GinjaTexture.h"

void TLogo::free_held_object() {
    if (logo_texture_e_handle != NULL) {
        release_texture_list(logo_texture_e_handle);
        logo_texture_e_handle = NULL;
    }
}
void register_texture_logo_e(void) {
    logo_texture_e_handle = &texture_logo_e_descriptor;
    load_streamed_prs_texture((saddr)"logo_e", (saddr)&texture_logo_e_descriptor);
}

void TLogo::request_exit(TObject *fade) {
    fade->queue_destruction();
    TLogo__exit_requested_flag = 1;
}
