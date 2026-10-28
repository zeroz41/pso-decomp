#include "types.h"
#include "pso/boss/TObjBoss8DemoRoom_8036B654.h"
#include "pso/protocol/subcommand_validation.h"
#include "pso/TObjBoss8DemoRoom.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8036B6D0_lbl_804F3660 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8036B6D0_lbl_804F3660_size[sizeof(RecoveredGlobal_8036B6D0_lbl_804F3660) == 0x10 ? 1 : -1];

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8036B6D0_lbl_804F3660 TObjBoss8DemoRoom__resource_desc;
extern u32 TObjBoss8DemoRoom__shared_resource_object;
void TLobby__sub_8001FE7C(void*, int);
void __ct__7TObjectFP7TObject(void *);

extern s32 __vt__17TObjBoss8DemoRoom[];
extern void *lbl_805D44E4;

void *__ct__17TObjBoss8DemoRoomFv(void *boss8_demo_room) {
    __ct__7TObjectFP7TObject(boss8_demo_room);
    *(s32 **)((s8 *)boss8_demo_room + 0x18) = __vt__17TObjBoss8DemoRoom;
    *(void * *)&((TObjBoss8DemoRoom *)boss8_demo_room)->m_name = lbl_805D44E4;
    return boss8_demo_room;
}

void TObjBoss8DemoRoom::free_static_instance() {
    if ((u32) TObjBoss8DemoRoom__shared_resource_object != 0U) {
        TLobby__sub_8001FE7C((void*)TObjBoss8DemoRoom__shared_resource_object, 1);
        TObjBoss8DemoRoom__shared_resource_object = 0U;
    }
}

void TObjBoss8DemoRoom::load_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &TObjBoss8DemoRoom__resource_desc.value, 0, 0, 0));
    }
    (*(s32 *)&TObjBoss8DemoRoom__shared_resource_object) = var_r0;
}
}

s32 validate_6x0E_clear_negative_status_effects(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}
