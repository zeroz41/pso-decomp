#include "types.h"
#include "pso/system/data/pso_const_ids4.h"

extern "C" {
void set_slot_mode__20TWindowActionPaletteFllll(void *, int, int, int);
extern s32 lbl_80447184[];
int ret_801D78E4(void) { return 0; }
int ret_801D78EC(void) { return 0; }
int ret_801D78F4(void) { return 0; }
int ret_801D78FC(void) { return 0; }
int ret_801D7904(void) { return 0; }
int ret_801D790C(void) { return 0; }
int ret_801D7914(void) { return 0; }
int ret_801D791C(void) { return 0; }
int ret_801D7924(void) { return 0; }
int ret_801D792C(void) { return 0; }
int ret_801D7934(void) { return 0; }
int ret_801D793C(void) { return 0; }
int ret_801D7944(void) { return 0; }
int ret_801D794C(void) { return 0; }
int ret_801D7954(void) { return 0; }
int ret_801D795C(void) { return 0; }
}
void assign_default_photon_blast_palette_slots(u8 *arg0) {
    s32 tbl[3];
    s32 i;
    i = 0;
    tbl[0] = lbl_80447184[0];
    tbl[1] = lbl_80447184[1];
    tbl[2] = lbl_80447184[2];
    do {
        set_slot_mode__20TWindowActionPaletteFllll(arg0 + 0x24, 1, tbl[i], 0);
        i++;
    } while (i < 3);
}
