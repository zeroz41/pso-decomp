#include "types.h"
#include "pso/TObjSuisoChip.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSnapShot.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803D8F74.h"

int TLobby::get_max_players() { return 8; }

s32 TObjSuisoChip::vfunc_8() {
    return TObjChip::vfunc_8();
}

s32 TObjSuisoChip::vfunc_10(Vec *center) {
    return TObjChip::vfunc_10(&origin);
}

void TObjSuisoChip::vfunc_12() {
    TObjChipPiece *piece;
    s32 i;

    if (pad_244 != 1) {
        piece = pieces;
        push_matrix();
        post_translate_matrix(&origin.x);
        rotate_matrix_y(NULL, rotation_y);
        for (i = 0; i < params.pad_30[0]; i++, piece++) {
            push_matrix();
            post_translate_matrix(&piece->pos.x);
            rotate_matrix_yxz(NULL, piece->rotation[0], piece->rotation[1], piece->rotation[2]);
            draw_ginja_object((void *)params.model);
            pop_matrix();
        }
        pop_matrix();
    }
}
