#include <string.h>
#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/system/scene/TScene.h"
#include "pso/unk/SharedMemory.h"
#include "pso/unk/text_8042EAD4.h"
#include "pso/unk/text_8042EE4C.h"
#include "pso/unk/text_8007F8D0.h"
#include "pso/unk/text_8014618C.h"
#include "pso/unk/text_8007FA24.h"
#include "pso/ui/frontend/TAdDialingGC.h"
#include "pso/ui/frontend/TAdTrialModemChkGC.h"
#pragma pool_data off

extern "C" {
void VIWaitForRetrace(void);
void VIFlush(void);
void VISetBlack(s32);
void GXDrawDone(void);
s32 fn_8042EAD4(u8 *arg0, u32 arg1);
void fn_8042EBA4(DolHeader *, s32);
extern s32 resource_decompress_buffer;
}
// The switcher.dol pages: the modem check (TAdTrialModemChkGC__sub_8007FA24) and the dial screen
// (TAdDialingGC::select_dial_image) pick one by index. Defined first: they open the unit's .rodata and
// .data, ahead of the disc error texts.
const char sonic_index_url[] = "file:/sonic/index.html";
const char sonic_config_url[] = "file:/sonic/config.htm";
const char sonic_license_url[] = "file:/sonic/license.htm";
const char *trial_modem_check_urls[] = {sonic_index_url, sonic_config_url, sonic_config_url};
// Three slots, NULL-ended: the 12-byte table sits in .data (an 8-byte one would go to .sdata).
const char *dial_image_urls[] = {sonic_config_url, sonic_license_url, NULL};

void TAdDialingGC::select_dial_image(void *self, s32 x) {
    launch_switcher_dol(dial_image_urls[x ? 1 : 0]);
}

const char disc_error_message_text[] = "An error has occurred. \nTurn the power off and refer to \nthe Nintendo GameCube Instruction Booklet \nfor more information.";
const char disc_error_insert_disc_text[] = "Please insert the PSO Episode 1 & 2 Plus Game Disc.";
const char disc_error_cover_open_text[] = "The Disc Cover is Open. \nIf you want to continue the game,\nplease close the Disc Cover.";
const char disc_error_wrong_disc_text[] = "This is not the PSO Episode 1 & 2 Plus Game Disc.\nPlease insert the PSO Episode 1 & 2 Plus Game Disc.";
const char disc_error_read_failed_text[] = "The Game Disc could not be read.\nPlease read the Nintendo GameCube Instruction\nBooklet for more information.";
const char switcher_dol_filename[] = "switcher.dol";
s32 lbl_805D4EB8;
s16 lbl_805D4EBC;
s16 disc_error_code;
s32 lbl_805D4EC0;
s32 lbl_805D4EC4;
void init_disc_error_messages(void);
#pragma push
// O2 preserves the retail argument setup with the shared declarations.
#pragma optimization_level 2
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
    TAdTrialModemChkGC__sub_8042EC14();
    fn_8042EF48(0);
    fn_8042ED98(4, disc_error_message_text);
    fn_8042ED98(1, disc_error_insert_disc_text);
    fn_8042ED98(0, disc_error_cover_open_text);
    fn_8042ED98(2, disc_error_wrong_disc_text);
    fn_8042ED98(3, disc_error_read_failed_text);
}
#pragma pop


s32 launch_switcher_dol(const char *url) {
    char buf[0x100];
    s32 r;
    saddr v;
    r = get_resource_file_size(switcher_dol_filename);
    read_disc_file(switcher_dol_filename, (void *)(v = resource_decompress_buffer));
    VISetBlack(1);
    VIFlush();
    VIWaitForRetrace();
    VIWaitForRetrace();
    VIWaitForRetrace();
    VIWaitForRetrace();
    GXDrawDone();
    memset(buf, 0, 0xFF);
    strcpy(buf, url);
    fn_8042EAD4((u8 *)buf, strlen(buf) + 1);
    fn_8042EBA4((DolHeader *) v, r);
    return 1;
}

void TAdTrialModemChkGC__sub_8007FA24(s32 arg0) {
  s32 temp_r31;
  s32 var_r31;
  var_r31 = 0;
  TAdTrialModemChkGC::init_modem_check_params();
  if (TLobby__sub_8014618C() != 0)
  {
    var_r31 = 1;
  }
  temp_r31 = ~(0 - (arg0 == 0));
  temp_r31 = (var_r31 + 1) & temp_r31;
  if ((temp_r31 == 1) != 0)
  {
    TAdTrialModemChkGC::init_modem_check_params();
  }
  launch_switcher_dol(trial_modem_check_urls[temp_r31]);
}
