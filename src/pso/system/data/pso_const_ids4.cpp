#include "types.h"
#include "pso/system/data/pso_const_ids4.h"
#include "pso/ui/window/TWindowActionPalette.h"

extern "C" {
void set_slot_mode__20TWindowActionPaletteFllll(void *, int, int, int);
void set_palette_entry__20TWindowActionPaletteFlllll(void *, s32, s32, s32, u16);
}

void assign_photon_blast_palette_slot(u8 *palettes, s32 arg1) {
    s32 ids[3] = {1, 2, 3};
    s32 id;
    s32 i;
    for (i = 0; i < 3; i++) {
        id = ids[i];
        if ((u16)TWindowActionPalette::get_slot_type((void *)(palettes + 0x24), 1, id) == 0) {
            set_palette_entry__20TWindowActionPaletteFlllll(palettes + 0x24, 1, id, 5, arg1);
            return;
        }
    }
}

void assign_default_photon_blast_palette_slots(u8 *palettes) {
    s32 tbl[3] = {1, 3, 2};
    s32 i;
    i = 0;
    do {
        set_slot_mode__20TWindowActionPaletteFllll(palettes + 0x24, 1, tbl[i], 0);
        i++;
    } while (i < 3);
}

extern "C" {
int ret_801D795C(void) { return 0; }
int ret_801D7954(void) { return 0; }
int ret_801D794C(void) { return 0; }
int ret_801D7944(void) { return 0; }
int ret_801D793C(void) { return 0; }
int ret_801D7934(void) { return 0; }
int ret_801D792C(void) { return 0; }
int ret_801D7924(void) { return 0; }
int ret_801D791C(void) { return 0; }
int ret_801D7914(void) { return 0; }
int ret_801D790C(void) { return 0; }
int ret_801D7904(void) { return 0; }
int ret_801D78FC(void) { return 0; }
int ret_801D78F4(void) { return 0; }
int ret_801D78EC(void) { return 0; }
int ret_801D78E4(void) { return 0; }
}
