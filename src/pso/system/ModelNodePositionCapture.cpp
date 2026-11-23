#include "pso/system/ModelNodePositionCapture.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/camera/TCameraCtrl.h"

struct ModelNodePositionCaptureState {
    s32 node_index;
    const ModelNodePositionEntry *entries;
    Vec *positions;
    s32 unknown_0c;
};

extern "C" {
ModelNodePositionCaptureState model_node_position_capture_state;
}

void ModelNodePositionCapture::capture_node(NJS_OBJECT *) {
    const ModelNodePositionEntry *entry = model_node_position_capture_state.entries;
    Vec *position = model_node_position_capture_state.positions;
    s32 index;
    while ((index = entry->node_index) != -1) {
        if (index == model_node_position_capture_state.node_index) {
            TCameraCtrl::transform_to_view(&entry->offset, position);
        }
        entry++;
        position++;
    }
    model_node_position_capture_state.node_index++;
}

void ModelNodePositionCapture::install() {
    model_node_position_capture_state.node_index = 0;
    model_node_position_capture_state.entries = entries;
    model_node_position_capture_state.positions = positions;
    set_chunk_model_node_callback(capture_node);
}

s32 ModelNodePositionCapture::is_valid(const ModelNodePositionEntry *entries) {
    const ModelNodePositionEntry *entry = entries;
    s32 count;
    if (entry == 0) {
        return 0;
    }
    for (count = 0; entry->node_index != -1; count++, entry++) {
        if (count >= 0x40) {
            return 0;
        }
    }
    return 1;
}

void ModelNodePositionCapture::destroy(ModelNodePositionCapture *capture) {
    delete capture;
}

ModelNodePositionCapture *ModelNodePositionCapture::create(const ModelNodePositionEntry *entries, Vec *positions) {
    if (is_valid(entries) != 0) {
        return new ModelNodePositionCapture(entries, positions);
    }
    return 0;
}

ModelNodePositionCapture::~ModelNodePositionCapture() {}
