#include "types.h"
#include "pso/object/seabed/TObjSuisoChip.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSnapShot.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803D8F74.h"

int TLobby::get_max_players() { return 8; }

s32 TObjSuisoChip::vfunc_8() {
    return TObjChip::vfunc_8();
}

s32 TObjSuisoChip::is_in_view(Vec *center, f32 max_depth, f32 radius) {
    return TObjChip::is_in_view(&origin, max_depth, radius);
}

void TObjSuisoChip::vfunc_12() {
    TObjChipPiece *piece;
    s32 i;

    if (pad_244 != 1) {
        piece = pieces;
        push_matrix();
        post_translate_matrix(&origin.x);
        rotate_matrix_y(NULL, rotation_y);
        for (i = 0; i < params.count; i++, piece++) {
            push_matrix();
            post_translate_matrix(&piece->pos.x);
            rotate_matrix_yxz(NULL, piece->rotation[0], piece->rotation[1], piece->rotation[2]);
            draw_ginja_object((void *)params.model);
            pop_matrix();
        }
        pop_matrix();
    }
}
