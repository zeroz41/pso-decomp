#include "pso/unk/SampledMotionPoints.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D853C.h"
#include "types.h"
#include "pso/camera/TCameraCtrl_803D6538.h"
#include "pso/unk/text_803D96A8.h"
extern "C" {
void push_matrix(void);
extern Vec lbl_80500F80;
extern Vec *lbl_805D5230;
extern s32 lbl_805D5234;
extern s32 motion_trail_node_index;
extern const s32 *lbl_805D523C;
extern const Vec *TBoss4Type3__motion_trail_points;
s32 transform_motion_node_points(SampledMotionPoints *arg0, NJS_OBJECT *node, s32 idx);
s32 transform_motion_node_points(SampledMotionPoints *arg0, NJS_OBJECT *node, s32 idx) {
    u32 flags;
    do {
        push_matrix();
        compose_motion_node_matrix(node);
        flags = node->evalflags;
        while (idx == lbl_805D523C[motion_trail_node_index]) {
            if (TBoss4Type3__motion_trail_points == NULL) {
                matrix_mult_vec(0, &lbl_80500F80, lbl_805D5230);
            } else {
                matrix_mult_vec(0, &TBoss4Type3__motion_trail_points[motion_trail_node_index], lbl_805D5230);
            }
            lbl_805D5230++;
            motion_trail_node_index++;
        }
        idx++;
        if (!(flags & 0x10)) {
            idx = transform_motion_node_points(arg0, node->child, idx);
        }
        pop_matrix();
        node = node->sibling;
    } while (node != NULL && motion_trail_node_index < lbl_805D5234);
    return idx;
}

}
