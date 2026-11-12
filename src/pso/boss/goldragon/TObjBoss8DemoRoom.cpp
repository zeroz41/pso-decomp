#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/goldragon/TObjBoss8DemoRoom.h"
#include "pso/object/mine/TOComputerMachine01_8023DD0C.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "types.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/boss/goldragon/TObjBoss8DemoRoom_8036B654.h"
#include "pso/network/protocol/subcommand_validation.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TObject.h"

__declspec(section ".data") const char *bm_obj_boss8_demoroom_model_names[2] = { "fe_obj_cyl_soto.nj", NULL };
const char *bm_obj_boss8_demoroom_motion_names[1] = { NULL };
BmlResourceDescriptor TObjBoss8DemoRoom__resource_desc = {
    "bm_obj_boss8_demoroom.bml", bm_obj_boss8_demoroom_model_names, bm_obj_boss8_demoroom_motion_names, 1, 0
};
const char *TObjBoss8DemoRoom__name = "TObjBoss8DemoRoom";

extern "C" {

u32 TBoss8Dragon__sub_802F3348(s32);
s32 TBoss8Dragon__sub_802FCCBC();

extern void *TObjBoss8DemoRoom__shared_resource_object;

void TObjBoss8DemoRoom::render() {
    TObjFish::set_global_param(*(s32 *)((s8 *)(*(void **)((s8 *)TObjBoss8DemoRoom__shared_resource_object + 0x42C)) + 0xC));
    push_matrix();
    draw_chunk_object((void *)(*(s32 *)((s8 *)(*(void **)((s8 *)TObjBoss8DemoRoom__shared_resource_object + 0x42C)) + 8)));
    set_default_alpha_blend();
    pop_matrix();
}

void run_task__17TObjBoss8DemoRoomFv(s32 arg0) {
    TObjPlayer__sub_8023DEE0((s16 *)(*(s32 *)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)TObjBoss8DemoRoom__shared_resource_object + 0x42C)) + 8)) + 0x2C)) + 4)) + 4)), 0, 1, 3);
    TObjPlayer__sub_8023DEE0((s16 *)(*(s32 *)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)TObjBoss8DemoRoom__shared_resource_object + 0x42C)) + 8)) + 0x2C)) + 0x30)) + 4)) + 4)), 0, 0x14, 1);
    if ((TBoss8Dragon__sub_802F3348(0) != 0U) && (TBoss8Dragon__sub_802FCCBC() != 0)) {
        ((TObject *)arg0)->queue_destruction();
    }
}
TObjBoss8DemoRoom::~TObjBoss8DemoRoom() {}

}


extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void free_bin_model_request(void*, int);
void __ct__7TObjectFP7TObject(void *);

extern s32 __vt__17TObjBoss8DemoRoom[];

void *__ct__17TObjBoss8DemoRoomFv(void *boss8_demo_room) {
    __ct__7TObjectFP7TObject(boss8_demo_room);
    *(s32 **)((s8 *)boss8_demo_room + 0x18) = __vt__17TObjBoss8DemoRoom;
    ((TObjBoss8DemoRoom *)boss8_demo_room)->m_name = TObjBoss8DemoRoom__name;
    return boss8_demo_room;
}

void TObjBoss8DemoRoom::free_static_instance() {
    if (TObjBoss8DemoRoom__shared_resource_object != 0) {
        free_bin_model_request(TObjBoss8DemoRoom__shared_resource_object, 1);
        TObjBoss8DemoRoom__shared_resource_object = 0;
    }
}

void TObjBoss8DemoRoom::load_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &TObjBoss8DemoRoom__resource_desc, 0, 0, 0));
    }
    TObjBoss8DemoRoom__shared_resource_object = (void *)var_r0;
}
}

s32 validate_6x0E_clear_negative_status_effects(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}
