#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_802C09E0_lbl_804E0878 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_802C09E0_lbl_804E0878_size[sizeof(RecoveredGlobal_802C09E0_lbl_804E0878) == 0x10 ? 1 : -1];

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_802C09E0_lbl_804E0878 bm_obj_lobby_pigeon_resource_descriptor;
extern s32 lobby_pigeon_bml_archive;
extern s32 lobby_pigeon_lobby_type;
void TObjPlayer::load_lobby_pigeon_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &bm_obj_lobby_pigeon_resource_descriptor.value, 0, 0, 0));
    }
    lobby_pigeon_bml_archive = var_r0;
    lobby_pigeon_lobby_type = TLobby::get_lobby_type();
}

}
