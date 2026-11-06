#include "types.h"
#include "pso/camera/TCameraCtrl_8006B3D8.h"
#include "pso/unk/text_8022350C.h"
#include "pso/unk/TLobby.h"

struct RecoveredGlobal_8022350C_lbl_8044C350 {
    s32 value;
    u8 remaining[0x18];
};

struct RecoveredGlobal_8022350C_lbl_8044C36C {
    s32 value;
    u8 remaining[0x18];
};

extern RecoveredGlobal_8022350C_lbl_8044C350 service_counter_camera_table;
extern RecoveredGlobal_8022350C_lbl_8044C36C service_counter_camera_alt_table;
typedef char RecoveredGlobal_8022350C_lbl_8044C350_size[sizeof(RecoveredGlobal_8022350C_lbl_8044C350) == 0x1C ? 1 : -1];
typedef char RecoveredGlobal_8022350C_lbl_8044C36C_size[sizeof(RecoveredGlobal_8022350C_lbl_8044C36C) == 0x1C ? 1 : -1];
void set_service_counter_camera(s32 arg0, s32 arg1) {
    if (TLobby::get_instance() == 0) {
        create_conversation_camera((*(s32 *)((s8 *)&service_counter_camera_table.value + (arg1 * 4))));
        return;
    }
    create_conversation_camera((*(s32 *)((s8 *)&service_counter_camera_alt_table.value + (arg1 * 4))));
}
