#include "types.h"
#include "pso/system/memory.h"
#include "pso/effect/TEF_LensFlare.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/KeyboardTextBuffer.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"

extern "C" {
u32 __cvt_fp2unsigned(f32);
}

void KeyboardTextBuffer::init(u32 width, u32 lines) {
    if (buffer != NULL) {
        mem_free(buffer);
    }
    if (lines == 0) {
        capacity = width;
    } else {
        capacity = __cvt_fp2unsigned((f32) lines * TWindowSubStatusDisp::round_away_from_zero((f32) (width / 6U)));
    }
    if (capacity != 0) {
        buffer = (u16 *)mem_alloc((capacity + 1) * 2);
        *buffer = 0;
    } else {
        buffer = NULL;
    }
    cursor = 0;
    length = 0;
    this->width = width;
    line_pixels = lines * 0x14;
}

KeyboardTextBuffer::~KeyboardTextBuffer() {
    if (buffer != NULL) {
        mem_free(buffer);
    }
}

extern s32 local_client_id;

KeyboardTextBuffer::KeyboardTextBuffer() {
    buffer = NULL;
    init(0, 0);
}

int TEF_LensFlare::is_player_out_of_range(f32 range_sq) {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player == NULL) {
        return 0;
    }
    return (u32) __cntlzw(horizontal_distance_squared(&player->position, &position) < range_sq) >> 5;
}
void *TEF_LensFlare::create(void *set_data) {
    if (is_split_screen() != 0) {
        return NULL;
    }
    return new TEF_LensFlare(tl_05, set_data);
}
