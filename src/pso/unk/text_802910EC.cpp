#include "pso/ui/UISpriteConstants.h"
#include "types.h"
#include "pso/unk/text_802910EC.h"
#include "pso/unk/text_80290D1C.h"
#include "pso/misc/TLobby.h"
#include "pso/TObjCMIcon.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/ui/Language.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off


extern "C" {
void queue_destruction__7TObjectFv(void *arg0);
s32 release_texture_list(void *);
u32 cmicon_instance;
s32 creation_sprite_table_index;
s32 create__10TObjCMIconFPv(int);
extern f32 ui_sprite_scale;
extern s32 tl_06;

void TCharaMaking__resolve_creation_sprite_table(u8 **table, s32 *id) {
  s32 index = *id;
  u8 *base = (u8 *)creation_chara_sprite_entries;
  if ((*id) < 143)
  {
    *table = base + 0xf8;
    return;
  }
  *id = (*id) - 143;
  if (creation_sprite_table_index == 0)
  {
    *table = base + 0xc24;
    return;
  }
  *table = base + 0xff8;
}

void fn_80291138(void) {
    if ((u32) cmicon_instance != 0U) {
        queue_destruction__7TObjectFv((void *)cmicon_instance);
    }
    cmicon_instance = 0U;
    release_texture_list(&creation_sprite_table);
}
#pragma push
#pragma fp_contract on

void fn_80291178(void) {
    creation_sprite_table_index = 0;
    ui_sprite_scale = ui_sprite_unit_scale;
    if (current_language != LANGUAGE_JAPANESE) {
        creation_sprite_table_index = 1;
    }
    TObjCMIcon::init_icon_table();
    (*(s32 *)&cmicon_instance) = create__10TObjCMIconFPv(tl_06);
    TLobby::load_texture_pvm_file(ccconsole_pvm_file_name_table[creation_sprite_table_index], (s32)&creation_sprite_table);
}
}

#pragma pop
