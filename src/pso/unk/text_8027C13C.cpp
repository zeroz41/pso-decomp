#include "pso/item/MagStats.h"
#include "types.h"
#include "pso/misc/TWindowSubMagPhoton.h"
#include "pso/item/TItemData.h"
#include "pso/item/TItemMag.h"
#include "pso/misc/TWindowSubCustomEquip.h"
struct Win_8027C188 { u8 pad[0x64]; s32 pb[3]; void *mag; };

struct Win_8027C13C { u8 pad[0x61]; s8 sel; };

extern "C" {
void *get_array_entry__11TWindowBaseFi(void *w, s32 i);
void deserialize_mag__9TItemDataFPvPv(void *src, void *dst);
void draw_action_palette_icon(void *e, s32 a, u16 b);
extern s8 lbl_805DD678[3];
extern u8 lbl_805DD67C[3];

void TWindowSubMagPhoton::get_cursor_origin(void *xy) {
    Win_8027C13C *w = (Win_8027C13C *)this;
    void *e = get_array_entry__11TWindowBaseFi(w, lbl_805DD67C[w->sel]);
    ((TWindowSubCustomEquip *)xy)->set_relative_pos(e);
}

void TWindowSubMagPhoton::init_photon_blast_entries() {
    u8 mag[16];
    s32 i;
    ((MagStats *)mag)->init();
    deserialize_mag__9TItemDataFPvPv(((Win_8027C188 *)this)->mag, mag);
    for (i = 0; i < 3; i++) {
        s32 blast = ((MagStats *)mag)->get_photon_blast(i);
        ((Win_8027C188 *)this)->pb[lbl_805DD678[i]] = blast;
        void *e = get_array_entry__11TWindowBaseFi(this, i + 1);
        if (blast != -1) {
            draw_action_palette_icon(e, 5, blast);
        } else {
            draw_action_palette_icon(e, 0, 0);
        }
    }
}

}
