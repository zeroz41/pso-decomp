#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/ModelNodeTables.h"
#include "pso/render/StripBufferPair.h"
#include "pso/system/BmlAccessors.h"
#include "pso/render/NinjaUtil.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/network/TLobby.h"

s32 TBoss4DarkFalz::has_instance() {
    return (u8)((u8) (dark_falz_controller_instance != 0));
}
void ModelNodeTables::scroll_strips() {
    s32 i;
    scroll_u += 8;
    for (i = 0; i < count; i++) {
        if (items[i] != 0) {
            items[i]->scroll_uvs(scroll_u, scroll_v);
        }
    }
}

void ModelNodeTables::destroy() {
    s32 i;
    for (i = 0; i < count; i++) {
        if (items[i] != 0) {
            delete items[i];
            items[i] = 0;
        }
    }
    delete[] items;
    items = 0;
}

void ModelNodeTables::init(const ModelNodeSpec *specs, s32 spec_count) {
    BmlResource *h;
    s32 i;
    const ModelNodeSpec *r;
    NJS_OBJECT *t;
    s32 j;
    h = TBoss4DarkFalz::get_dat_resource();
    if (h == 0 || specs == NULL || spec_count < 1) {
        return;
    }
    count = spec_count;
    items = NULL;
    items = new StripBufferPair *[count];
    scroll_u = 0;
    scroll_v = 0;
    for (j = 0; j < count; j++) {
        items[j] = 0;
    }
    for (i = 0; i < count; i++) {
        r = &specs[i];
        t = find_model_node(get_bml_model(h, r->model), r->node);
        items[i] = new StripBufferPair(t, r->texture_filter);
    }
}
