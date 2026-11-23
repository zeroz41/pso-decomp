#include "types.h"
#include "pso/audio/AdxStreamScrollOffset.h"
#include "pso/unk/TLobby.h"

static inline s32 adx_get_scroll_offset_impl(void *self_ptr) {
    return static_cast<AdxStreamScrollState *>(self_ptr)->scroll_offset;
}

s32 TLobby::get_scroll_offset() {
    return adx_get_scroll_offset_impl(this);
}
