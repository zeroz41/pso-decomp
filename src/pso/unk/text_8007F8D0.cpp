#include "types.h"
#include "pso/misc/TScene.h"
#pragma pool_data off

extern "C" {
void TAdTrialModemChkGC__sub_8042EC14(int, int);
void fn_8042ED98(int, const char *);
void fn_8042EF48(int);
void read_disc_file(const char *, s32);
void VIWaitForRetrace(void);
void VIFlush(void);
void VISetBlack(s32);
void GXDrawDone(void);
char *strcpy(char *, const char *);
s32 fn_8042EAD4(u8 *arg0, u32 arg1);
void fn_8042EBA4(s32, s32);
void *memset(void *, s32, u32);
u32 strlen(const char *);
extern s32 resource_decompress_buffer;
s32 launch_switcher_dol(const char *arg0);
}
const char disc_error_message_text[] = "An error has occurred. \nTurn the power off and refer to \nthe Nintendo GameCube Instruction Booklet \nfor more information.";
const char lbl_80438BBC[] = "Please insert the PSO Episode 1 & 2 Plus Game Disc.";
const char lbl_80438BF0[] = "The Disc Cover is Open. \nIf you want to continue the game,\nplease close the Disc Cover.";
const char lbl_80438C48[] = "This is not the PSO Episode 1 & 2 Plus Game Disc.\nPlease insert the PSO Episode 1 & 2 Plus Game Disc.";
const char lbl_80438CB0[] = "The Game Disc could not be read.\nPlease read the Nintendo GameCube Instruction\nBooklet for more information.";
const char lbl_80438D20[] = "switcher.dol";
extern s32 lbl_805D4EB8;
extern s16 lbl_805D4EBC;
extern s16 disc_error_code;
extern s32 lbl_805D4EC0;
extern s32 lbl_805D4EC4;
void init_disc_error_messages(void);
#pragma push
#pragma optimization_level 1
#pragma dont_inline on
void init_disc_error_messages(void) {
    s32 z = 0;
    u8 *p = (u8 *)0x80010000;
    lbl_805D4EB8 = z;
    lbl_805D4EBC = -1;
    lbl_805D4EC0 = z;
    lbl_805D4EC4 = z;
    disc_error_code = p[-0x55d0];
    p[-0x55d0] = z;
    TAdTrialModemChkGC__sub_8042EC14((int)p, z);
    fn_8042EF48(0);
    fn_8042ED98(4, disc_error_message_text);
    fn_8042ED98(1, lbl_80438BBC);
    fn_8042ED98(0, lbl_80438BF0);
    fn_8042ED98(2, lbl_80438C48);
    fn_8042ED98(3, lbl_80438CB0);
}
#pragma pop


s32 launch_switcher_dol(const char *arg0) {
    char buf[0x100];
    s32 r;
    s32 v;
    r = ((TScene *)lbl_80438D20)->update_lobby_scene();
    read_disc_file(lbl_80438D20, v = resource_decompress_buffer);
    VISetBlack(1);
    VIFlush();
    VIWaitForRetrace();
    VIWaitForRetrace();
    VIWaitForRetrace();
    VIWaitForRetrace();
    GXDrawDone();
    memset(buf, 0, 0xFF);
    strcpy(buf, arg0);
    fn_8042EAD4((u8 *)buf, strlen(buf) + 1);
    fn_8042EBA4(v, r);
    return 1;
}

