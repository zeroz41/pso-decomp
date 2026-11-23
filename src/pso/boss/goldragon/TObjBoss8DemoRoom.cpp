#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
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
#include "pso/boss/goldragon/TBoss8Dragon.h"

__declspec(section ".data") const char *bm_obj_boss8_demoroom_model_names[2] = { "fe_obj_cyl_soto.nj", NULL };
const char *bm_obj_boss8_demoroom_motion_names[1] = { NULL };
BmlResourceDescriptor TObjBoss8DemoRoom__resource_desc = {
    "bm_obj_boss8_demoroom.bml", bm_obj_boss8_demoroom_model_names, bm_obj_boss8_demoroom_motion_names, 1, 0
};
const char *TObjBoss8DemoRoom__name = "TObjBoss8DemoRoom";

extern "C" {

void * TObjBoss8DemoRoom__shared_resource_object;

void TObjBoss8DemoRoom::render() {
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(*(s32 *)((s8 *)(*(void **)((s8 *)TObjBoss8DemoRoom__shared_resource_object + 0x42C)) + 0xC)));
    push_matrix();
    draw_chunk_object((void *)(*(saddr *)((s8 *)(*(void **)((s8 *)TObjBoss8DemoRoom__shared_resource_object + 0x42C)) + 8)));
    set_default_alpha_blend();
    pop_matrix();
}

void TObjBoss8DemoRoom::run_task() {
    TObjPlayer__sub_8023DEE0((s16 *)(*(saddr *)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)TObjBoss8DemoRoom__shared_resource_object + 0x42C)) + 8)) + 0x2C)) + 4)) + 4)), 0, 1, 3);
    TObjPlayer__sub_8023DEE0((s16 *)(*(saddr *)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)TObjBoss8DemoRoom__shared_resource_object + 0x42C)) + 8)) + 0x2C)) + 0x30)) + 4)) + 4)), 0, 0x14, 1);
    TBoss8Dragon *leader = TBoss8Dragon::get_part(0);
    if ((leader != NULL) && (leader->has_appeared() != 0)) {
        this->queue_destruction();
    }
}
TObjBoss8DemoRoom::~TObjBoss8DemoRoom() {}

TObjBoss8DemoRoom::TObjBoss8DemoRoom(TObject *parent) : TObject(parent) {
    m_name = TObjBoss8DemoRoom__name;
}

void TObjBoss8DemoRoom::free_static_instance() {
    if (TObjBoss8DemoRoom__shared_resource_object != 0) {
        delete (BmlResource *)TObjBoss8DemoRoom__shared_resource_object;
        TObjBoss8DemoRoom__shared_resource_object = 0;
    }
}

void TObjBoss8DemoRoom::load_resource() {
    saddr var_r0;
    var_r0 = (saddr)new BmlResource(1, &TObjBoss8DemoRoom__resource_desc, 0, 0, NULL);
    TObjBoss8DemoRoom__shared_resource_object = (void *)var_r0;
}
}

s32 validate_6x0E_clear_negative_status_effects(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}
