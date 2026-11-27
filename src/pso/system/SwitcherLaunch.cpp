#include <string.h>
#include "pso/system/SwitcherLaunch.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXManage.h>
#include <dolphin/vi.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/system/scene/TScene.h"
#include "pso/unk/SharedMemory.h"
#include "pso/network/NetworkSettings.h"
#include "pso/ui/frontend/TAdDialingGC.h"
#include "pso/ui/frontend/TAdTrialModemChkGC.h"
#include "pso/ui/keyboard/SystemBootInitInternal.h"
#pragma pool_data off

// The switcher.dol pages: the modem check and the dial screen
// (select_dial_image) pick one by index. Defined first: they open the unit's .rodata and
// .data, ahead of the disc error texts.
const char sonic_index_url[] = "file:/sonic/index.html";
const char sonic_config_url[] = "file:/sonic/config.htm";
const char sonic_license_url[] = "file:/sonic/license.htm";
const char *trial_modem_check_urls[] = {sonic_index_url, sonic_config_url, sonic_config_url};
// Three slots, NULL-ended: the 12-byte table sits in .data (an 8-byte one would go to .sdata).
const char *dial_image_urls[] = {sonic_config_url, sonic_license_url, NULL};

void select_dial_image(s32, s32 x) {
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
    init_shared_memory();
    set_disc_messages_byte0(0);
    set_disc_error_message(4, disc_error_message_text);
    set_disc_error_message(1, disc_error_insert_disc_text);
    set_disc_error_message(0, disc_error_cover_open_text);
    set_disc_error_message(2, disc_error_wrong_disc_text);
    set_disc_error_message(3, disc_error_read_failed_text);
}
#pragma pop


s32 launch_switcher_dol(const char *url) {
    char buf[0x100];
    s32 r;
    u8 *v;
    r = get_resource_file_size(switcher_dol_filename);
    read_disc_file(switcher_dol_filename, v = resource_decompress_buffer);
    VISetBlack(1);
    VIFlush();
    VIWaitForRetrace();
    VIWaitForRetrace();
    VIWaitForRetrace();
    VIWaitForRetrace();
    GXDrawDone();
    memset(buf, 0, 0xFF);
    strcpy(buf, url);
    set_shared_memory_data((u8 *)buf, strlen(buf) + 1);
    launch_iwanaga_dol((DolHeader *) v, r);
    return 1;
}

void launch_browser(s32 use_modem_url) {
  s32 url_index;
  s32 modem_ready;
  modem_ready = 0;
  init_modem_check_params();
  if (has_broadband_adapter() != 0)
  {
    modem_ready = 1;
  }
  url_index = ~(0 - (use_modem_url == 0));
  url_index = (modem_ready + 1) & url_index;
  if ((url_index == 1) != 0)
  {
    init_modem_check_params();
  }
  launch_switcher_dol(trial_modem_check_urls[url_index]);
}
