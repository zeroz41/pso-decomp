#include "pso/system/memory.h"
#include "types.h"
#include "pso/unk/TUnk_804F1C58.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"

TUnk_804F1C58::~TUnk_804F1C58() {
    mem_free(node_matrices);
}

TUnk_804F1C58::TUnk_804F1C58(TObject *parent, NJS_OBJECT *model) : TObject(parent) {
    this->model = model;
    motion = NULL;
    frame = 0.0f;
    draw_cursor = 0;
    node_count = count_tree_nodes(model);
    node_matrices = static_cast<GC_Mtx *>(mem_alloc(node_count * sizeof(*node_matrices)));
    draw_callback = NULL;
    node_callback = 0;
}
