#include "types.h"
#include "pso/render/TNodeMatrixRecorder.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/ChunkModelDraw.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/TLobby_801E2F94.h"
#include "pso/unk/text_803D853C.h"

s32 recorded_node_index;
s32 recorded_node_count;
GC_Mtx *recorded_node_matrices;
ChunkModelNodeCallback recorded_node_callback;

void TNodeMatrixRecorder::set_node_callback(ChunkModelNodeCallback callback) { node_callback = callback; }

void record_node_matrix(NJS_OBJECT *node) {
    if (recorded_node_index < recorded_node_count) {
        get_current_matrix(&recorded_node_matrices[recorded_node_index]);
    }
    if (recorded_node_callback != NULL) {
        recorded_node_callback(node);
    }
    recorded_node_index += 1;
}

void TNodeMatrixRecorder::draw_node_tree(NJS_OBJECT *node) {
    u32 flags;
    do {
        flags = node->evalflags;
        push_matrix();
        TObjPlayer::concat_matrix(0, reinterpret_cast<uaddr>(recorded_node_matrices[draw_node_index]));
        draw_node_index = draw_node_index + 1;
        if (draw_node_callback != NULL) {
            draw_node_callback(node);
        }
        if (!(flags & NJD_EVAL_HIDE)) {
            draw_chunk_model(node->model);
        }
        pop_matrix();
        if (!(flags & NJD_EVAL_BREAK)) {
            draw_node_tree(node->child);
        }
        node = node->sibling;
    } while (node != NULL);
}

void TNodeMatrixRecorder::draw_recorded_pose() {
    if (motion != NULL) {
        draw_node_index = 0;
        draw_node_tree(model);
    }
}

void TNodeMatrixRecorder::record_pose(NJS_MOTION *new_motion, f32 new_frame) {
    motion = new_motion;
    frame = new_frame;
    recorded_node_index = 0;
    recorded_node_count = node_count;
    recorded_node_matrices = node_matrices;
    recorded_node_callback = node_callback;
    set_chunk_model_node_callback(record_node_matrix);
    draw_motion(model, new_motion, new_frame);
    set_chunk_model_node_callback(NULL);
}

TNodeMatrixRecorder::~TNodeMatrixRecorder() {
    mem_free(node_matrices);
}

TNodeMatrixRecorder::TNodeMatrixRecorder(TObject *parent, NJS_OBJECT *model) : TObject(parent) {
    this->model = model;
    motion = NULL;
    frame = 0.0f;
    draw_node_index = 0;
    node_count = count_tree_nodes(model);
    node_matrices = static_cast<GC_Mtx *>(mem_alloc(node_count * sizeof(GC_Mtx)));
    draw_node_callback = NULL;
    node_callback = 0;
}
