#include "pso/unk/TUnk_804F1C58.h"

void TUnk_804F1C58::draw_node_tree_if_visible() {
    if (motion != NULL) {
        draw_cursor = 0;
        draw_node_tree(model);
    }
}
