#include "types.h"
#include "pso/unk/TUnk_804C57F0.h"

void TUnk_804C57F0::append_node_to_tail(QuadSpriteNode *node) {
    s32 i = node->uv_index;
    node->next = NULL;
    tails[i]->next = node;
    tails[i] = node;
    queued = 1;
}
