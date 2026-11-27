#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "pso/boss/goldragon/TObjBoss8DemoRoom.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/ProjectedStripDraw.h"
#include "types.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/network/protocol/subcommand_validation.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

__declspec(section ".data") const char *bm_obj_boss8_demoroom_model_names[2] = { "fe_obj_cyl_soto.nj", NULL };
const char *bm_obj_boss8_demoroom_motion_names[1] = { NULL };
BmlResourceDescriptor TObjBoss8DemoRoom::resource_desc = {
    "bm_obj_boss8_demoroom.bml", bm_obj_boss8_demoroom_model_names, bm_obj_boss8_demoroom_motion_names, 1, 0
};
const char *TObjBoss8DemoRoom::name = "TObjBoss8DemoRoom";


void * TObjBoss8DemoRoom::shared_resource_object;

extern "C" {
void TObjBoss8DemoRoom::render() {
    set_texture_list(reinterpret_cast<NJS_TEXLIST *>(*(s32 *)((s8 *)(*(void **)((s8 *)TObjBoss8DemoRoom::shared_resource_object + 0x42C)) + 0xC)));
    push_matrix();
    draw_chunk_object((void *)(*(saddr *)((s8 *)(*(void **)((s8 *)TObjBoss8DemoRoom::shared_resource_object + 0x42C)) + 8)));
    set_default_alpha_blend();
    pop_matrix();
}

void TObjBoss8DemoRoom::run_task() {
    scroll_chunk_plist_uvs((s16 *)(*(saddr *)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)TObjBoss8DemoRoom::shared_resource_object + 0x42C)) + 8)) + 0x2C)) + 4)) + 4)), 0, 1, 3);
    scroll_chunk_plist_uvs((s16 *)(*(saddr *)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)TObjBoss8DemoRoom::shared_resource_object + 0x42C)) + 8)) + 0x2C)) + 0x30)) + 4)) + 4)), 0, 0x14, 1);
    TBoss8Dragon *leader = get_boss8_dragon_part(0);
    if ((leader != NULL) && (leader->has_appeared() != 0)) {
        this->queue_destruction();
    }
}
TObjBoss8DemoRoom::~TObjBoss8DemoRoom() {}

TObjBoss8DemoRoom::TObjBoss8DemoRoom(TObject *parent) : TObject(parent) {
    m_name = TObjBoss8DemoRoom::name;
}

void TObjBoss8DemoRoom::free_static_instance() {
    if (TObjBoss8DemoRoom::shared_resource_object != 0) {
        delete (BmlResource *)TObjBoss8DemoRoom::shared_resource_object;
        TObjBoss8DemoRoom::shared_resource_object = 0;
    }
}

void TObjBoss8DemoRoom::load_resource() {
    saddr resource;
    resource = (saddr)new BmlResource(1, &TObjBoss8DemoRoom::resource_desc, 0, 0, NULL);
    TObjBoss8DemoRoom::shared_resource_object = (void *)resource;
}
}

s32 validate_6x0E_clear_negative_status_effects(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}
