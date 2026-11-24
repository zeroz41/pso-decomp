#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/render/NinjaUtil.h"
#include "pso/render/StripBufferPair.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/ModelNodeTables.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/TLobby.h"

void ModelNodeTables::destroy() {
    s32 i;
    for (i = 0; i < count; i++) {
        if (items[i] != 0) {
            delete items[i];
            items[i] = 0;
        }
    }
    mem_free(items);
    items = 0;
}

void ModelNodeTables::init(const ModelNodeSpec *specs, s32 spec_count) {
    BmlResource *h;
    s32 i;
    const ModelNodeSpec *r;
    NJS_OBJECT *t;
    s32 j;
    h = TBoss4Uro::get_instance_count();
    if (h == 0 || specs == NULL || spec_count < 1) {
        return;
    }
    count = spec_count;
    items = NULL;
    items = (StripBufferPair **)mem_alloc(count * 4);
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
