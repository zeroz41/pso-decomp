#include "types.h"
#include "pso/render/NinjaUtil.h"
#include "pso/unk/text_800F5BC0.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/ModelNodeTables.h"

extern "C" {
void mem_free(void *p);
s32 get_bml_model(s32, s32);
s32 alloc_tables__6TLobbyFll(s32, s32, s32);
void *mem_alloc(u32 size);
}

void ModelNodeTables::destroy() {
    s32 i;
    for (i = 0; i < count; i++) {
        if (items[i] != 0) {
            destroy_buffer_pair(items[i], 1);
            items[i] = 0;
        }
    }
    mem_free(items);
    items = 0;
}

void ModelNodeTables::init(const ModelNodeSpec *specs, s32 spec_count) {
    s32 h;
    s32 i;
    const ModelNodeSpec *r;
    s32 t;
    s32 p;
    s32 j;
    h = TBoss4Uro::get_instance_count();
    if (h == 0 || specs == NULL || spec_count < 1) {
        return;
    }
    count = spec_count;
    items = NULL;
    items = (void **)mem_alloc(count * 4);
    scroll_u = 0;
    scroll_v = 0;
    for (j = 0; j < count; j++) {
        items[j] = 0;
    }
    for (i = 0; i < count; i++) {
        r = &specs[i];
        t = (s32)find_model_node(get_bml_model(h, r->model), r->node);
        p = (int)::operator new(0x14);
        if (p != 0) {
            p = alloc_tables__6TLobbyFll(p, t, r->count);
        }
        items[i] = (void *)p;
    }
}
