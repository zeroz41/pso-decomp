// One original TU runs from calc_triangle_normal (0x801412D0) to the weak inline copies at
// 0x80142624-0x80142770, but its out-of-line copy of sqrt_double sits at the TU end while the
// copy's constants sit between the tev tables and the pulse constants. No compiler here emits
// that (a copy follows its first caller, its constants with it), so the TU is built as three
// units: this one (to set_tev_swap_channels), render_util.cpp and render_util_tail.cpp.

#include "pso/render/render_util.h"
#include <dolphin/gx.h>


struct TevChannelTable {
    GXTevColorChan chan[4];
};
struct TevSwapSelTable {
    GXTevSwapSel sel[4];
};
static const TevChannelTable tev_channel_table = {GX_CH_RED, GX_CH_GREEN, GX_CH_BLUE, GX_CH_ALPHA};
static const TevSwapSelTable tev_swap_sel_table = {GX_TEV_SWAP1, GX_TEV_SWAP2, GX_TEV_SWAP3, GX_TEV_SWAP0};

s32 calc_triangle_normal(const Vec *tri, Vec *out) {
    Vec a;
    Vec b;
    Vec n;
    f32 len_sq;
    f32 len;
    a.x = tri[1].x - tri[0].x;
    a.y = tri[1].y - tri[0].y;
    a.z = tri[1].z - tri[0].z;
    b.x = tri[2].x - tri[0].x;
    b.y = tri[2].y - tri[0].y;
    b.z = tri[2].z - tri[0].z;
    n.x = a.y * b.z - a.z * b.y;
    n.y = a.z * b.x - a.x * b.z;
    n.z = a.x * b.y - a.y * b.x;
    len_sq = n.x * n.x + n.y * n.y + n.z * n.z;
    if (is_near_zero(len_sq) != 0) {
        return 0;
    }
    len = sqrt_double(len_sq);
    out->x = n.x / len;
    out->y = n.y / len;
    out->z = n.z / len;
    return 1;
}

u32 calc_gx_tile_index(u32 x, u32 y, s16 width) {
    u32 index = ((x >> 2) << 4) + (x & 3);
    index += ((y >> 2) * width) << 2;
    index += (y & 3) << 2;
    return index;
}

void init_tev_swap() {
    GXSetTevSwapModeTable(GX_TEV_SWAP1, GX_CH_RED, GX_CH_RED, GX_CH_RED, GX_CH_ALPHA);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
}

void set_tev_swap_mode(u8 table) {
    if (table < 4) {
        TevSwapSelTable swaps = tev_swap_sel_table;
        GXSetTevSwapMode(GX_TEVSTAGE0, swaps.sel[table], swaps.sel[table]);
    }
}

void set_tev_swap_channels(u8 r, u8 g, u8 b, u8 a) {
    if (r >= 4) {
        return;
    }
    // The original tests g twice and never b or a.
    if (g >= 4 || g >= 4) {
        return;
    }
    {
        TevChannelTable chans = tev_channel_table;
        GXSetTevSwapModeTable(GX_TEV_SWAP1, chans.chan[r], chans.chan[g], chans.chan[b], chans.chan[a]);
        GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP1, GX_TEV_SWAP1);
    }
}
