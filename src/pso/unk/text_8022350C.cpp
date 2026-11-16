#include "types.h"
#include "pso/camera/TCameraCtrl_8006B3D8.h"
#include "pso/unk/text_8022350C.h"
#include "pso/unk/TLobby.h"

struct ServiceCounterCameraTable { s32 value; u8 remaining[0x18]; };
extern ServiceCounterCameraTable service_counter_camera_table;
struct ServiceCounterCameraAltTable { s32 value; u8 remaining[0x18]; };
extern ServiceCounterCameraAltTable service_counter_camera_alt_table;
void set_service_counter_camera(s32 arg0, s32 arg1) {
    if (TLobby::get_instance() == 0) {
        create_conversation_camera((*(s32 *)((s8 *)&service_counter_camera_table.value + (arg1 * 4))));
        return;
    }
    create_conversation_camera((*(s32 *)((s8 *)&service_counter_camera_alt_table.value + (arg1 * 4))));
}
