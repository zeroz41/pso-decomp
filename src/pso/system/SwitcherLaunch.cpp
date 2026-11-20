#include "pso/system/ResourceFile.h"
#include "types.h"
#include "versions.h"
#include "pso/system/scene/TScene.h"
#include "pso/unk/SharedMemory.h"
#include "pso/unk/text_8007F8D0.h"
#include "pso/unk/text_8014618C.h"
#include "pso/unk/text_8007FA24.h"
#include "pso/ui/frontend/TAdDialingGC.h"
#include "pso/ui/frontend/TAdTrialModemChkGC.h"
#pragma pool_data off

extern "C" {
void TAdTrialModemChkGC__sub_8042EC14(int, int);
void fn_8042ED98(int, const char *);
void fn_8042EF48(int);
void VIWaitForRetrace(void);
void VIFlush(void);
void VISetBlack(s32);
void GXDrawDone(void);
char *strcpy(char *, const char *);
s32 fn_8042EAD4(u8 *arg0, u32 arg1);
void fn_8042EBA4(DolHeader *, s32);
void *memset(void *, s32, u32);
u32 strlen(const char *);
extern s32 resource_decompress_buffer;
#if VERSION == VERSION_GPOP8P
void fn_80145D2C(void);
s32 fn_8042E1EC(s32 v);
#endif
}
// The switcher.dol pages: the modem check (TAdTrialModemChkGC__sub_8007FA24) and the dial screen
// (TAdDialingGC::select_dial_image) pick one by index. Defined first: they open the unit's .rodata and
// .data, ahead of the disc error texts.
const char sonic_index_url[] = "file:/sonic/index.html";
const char sonic_config_url[] = "file:/sonic/config.htm";
#if VERSION == VERSION_GPOP8P
// The European disc defines the license page after its per-language disc texts.
extern const char sonic_license_url[];
#else
const char sonic_license_url[] = "file:/sonic/license.htm";
#endif
const char *trial_modem_check_urls[] = {sonic_index_url, sonic_config_url, sonic_config_url};
// Three slots, NULL-ended: the 12-byte table sits in .data (an 8-byte one would go to .sdata).
const char *dial_image_urls[] = {sonic_config_url, sonic_license_url, NULL};

void TAdDialingGC::select_dial_image(void *self, s32 x) {
    launch_switcher_dol(dial_image_urls[x ? 1 : 0]);
}

#if VERSION == VERSION_GPOP8P
// Disc messages per language: insert the disc, wrong disc (English, German, French, Spanish).
const char lbl_80437DC8[] = "Please insert the PSO Episode 1 & 2 Game Disc.";
const char lbl_80437DF8[] = "This is not the PSO Episode 1 & 2 Game Disc.\nPlease insert the PSO Episode 1 & 2 Game Disc.";
const char lbl_80437E54[] = "Bitte legen Sie die PSO Episode 1 & 2 Game Disc ein.";
const char lbl_80437E8C[] = "Diese Game Disc enth\xe4" "lt nicht PSO Episode 1 & 2. \nBitte legen Sie die PSO Episode 1&2 Game Disc ein.";
const char lbl_80437EF4[] = "Veuillez ins\xe9" "rer le disque: PSO Episode 1 & 2.";
const char lbl_80437F24[] = "Ceci n'est pas le disque: PSO Episode 1 & 2.\nVeuillez ins\xe9" "rer le disque: PSO Episode 1 & 2.";
const char lbl_80437F80_pal[] = "Coloca el disco de PSO Episode 1 & 2.";
const char lbl_80437FA8[] = "\xc9" "ste no es el disco de PSO Episode 1 & 2. \nColoca el disco de PSO Episode 1 & 2.";
// Indexed by current_language * 2: insert-disc text, wrong-disc text (Japanese uses the English pair).
const char *const lbl_80437FFC[10] = {
    lbl_80437DC8, lbl_80437DF8, lbl_80437DC8, lbl_80437DF8, lbl_80437E54,
    lbl_80437E8C, lbl_80437EF4, lbl_80437F24, lbl_80437F80_pal, lbl_80437FA8,
};
const char sonic_license_url[] = "file:/sonic/license.htm";
#else
const char disc_error_message_text[] = "An error has occurred. \nTurn the power off and refer to \nthe Nintendo GameCube Instruction Booklet \nfor more information.";
const char disc_error_insert_disc_text[] = "Please insert the PSO Episode 1 & 2 Plus Game Disc.";
const char disc_error_cover_open_text[] = "The Disc Cover is Open. \nIf you want to continue the game,\nplease close the Disc Cover.";
const char disc_error_wrong_disc_text[] = "This is not the PSO Episode 1 & 2 Plus Game Disc.\nPlease insert the PSO Episode 1 & 2 Plus Game Disc.";
const char disc_error_read_failed_text[] = "The Game Disc could not be read.\nPlease read the Nintendo GameCube Instruction\nBooklet for more information.";
#endif
const char switcher_dol_filename[] = "switcher.dol";
s32 lbl_805D4EB8;
s16 lbl_805D4EBC;
s16 disc_error_code;
s32 lbl_805D4EC0;
s32 lbl_805D4EC4;
void init_disc_error_messages(void);
#if VERSION == VERSION_GPOP8P
extern s32 current_language;
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma push
#pragma optimization_level 1
void init_disc_error_messages(void) {
    typedef struct {
        const char *v[10];
    } NameTbl;
    NameTbl names;
    s32 z = 0;
    u8 *p = (u8 *)0x80010000;
    lbl_805D4EB8 = z;
    lbl_805D4EBC = -1;
    lbl_805D4EC0 = z;
    lbl_805D4EC4 = z;
    disc_error_code = p[-0x55d0];
    p[-0x55d0] = z;
    TAdTrialModemChkGC__sub_8042EC14((int)p, z);
    fn_8042E1EC(0);
    names = *(NameTbl *)lbl_80437FFC;
    switch (current_language) {
    case 0:
        fn_8042ED98(1, names.v[0]);
        fn_8042ED98(2, names.v[1]);
        break;
    case 1:
        fn_8042ED98(1, names.v[2]);
        fn_8042ED98(2, names.v[3]);
        break;
    case 2:
        fn_8042ED98(1, names.v[4]);
        fn_8042ED98(2, names.v[5]);
        break;
    case 3:
        fn_8042ED98(1, names.v[6]);
        fn_8042ED98(2, names.v[7]);
        break;
    case 4:
        fn_8042ED98(1, names.v[8]);
        fn_8042ED98(2, names.v[9]);
        break;
    default:
        fn_8042ED98(1, names.v[2]);
        fn_8042ED98(2, names.v[3]);
        break;
    }
}
#pragma pop
#else
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
    fn_8042ED98(1, disc_error_insert_disc_text);
    fn_8042ED98(0, disc_error_cover_open_text);
    fn_8042ED98(2, disc_error_wrong_disc_text);
    fn_8042ED98(3, disc_error_read_failed_text);
}
#pragma pop
#endif


s32 launch_switcher_dol(const char *url) {
    char buf[0x100];
    s32 r;
    s32 v;
    r = get_resource_file_size(switcher_dol_filename);
#if VERSION == VERSION_GPOP8P
    fn_80145D2C();
#endif
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
