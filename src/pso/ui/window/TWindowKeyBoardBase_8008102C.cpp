#include "types.h"
#include "pso/ui/window/TWindowKeyBoardBase_8008102C.h"
#include "pso/system/memory.h"
#include "pso/effect/TEF_LensFlare.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/KeyboardTextBuffer.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

extern "C" {
u8 * __ct__13TEF_LensFlareFP7TObjectPv(void *, saddr, saddr);
extern saddr tl_05;
u32 __cvt_fp2unsigned(f32);
f32 horizontal_distance_squared(s32, s32);
void *get_player_by_client_id(s32 i);
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

int TEF_LensFlare::is_player_near(f32 farg0) {
    s32 arg0 = (saddr)this;
    u32 player;

    player = (uaddr)get_player_by_client_id(local_client_id);
    if (player == 0U) {
        return 0;
    }
    return (u32) __cntlzw(horizontal_distance_squared(player + 0x38, arg0 + 0x38) < farg0) >> 5;
}
u8 *TEF_LensFlare__create(s32 arg0) {
    u8 *ef_lens_flare;
    u8 *var_r0;
    if (is_split_screen() != 0) {
        return NULL;
    }
    ef_lens_flare = (u8 *)(TObject::operator new(0x94));
    var_r0 = ef_lens_flare;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(__ct__13TEF_LensFlareFP7TObjectPv(ef_lens_flare, tl_05, arg0));
    }
    return var_r0;
}
