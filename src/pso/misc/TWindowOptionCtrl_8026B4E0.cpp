#include "types.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/unk/text_8013ADE4.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/misc/TWindowOptionCtrl.h"
#include "pso/ui/TAdEnterSerialAccessGC.h"

extern "C" {
u8 *get_window_layout_position(s32);
s32 create__19TWindowMessageYesNoFPvPvPvPv(s32, s32, s32, s32);
s32 free_member__17TWindowSubComCardFv(int, int);
s32 forward_slot_selection__16TAdChrSelASlotGCFPvPv(int, void *, int, f32);
extern const f32 lbl_805DD268;
s32 create__14TWindowMessageFPvll(void *, s32 *, s32);
s32 warn_if_empty__17TWindowOptionCtrlFPUc(void *);
void *get_chr_select_base_plus_1154c__17TWindowOptionCtrlFv();
extern s32 lbl_8044F4A4[];

s32 TWindowOptionCtrl::create_serial_info_window(s32 arg1) {
    s32 w;
    w = create__14TWindowMessageFPvll(this, lbl_8044F4A4, 3);
    switch (arg1) {
    case 0:
        ((TWindowOptionCtrl *)w)->add_label_value_line((const char *)(get_localized_text_entry(0xF, 0x16)), (const char *)(warn_if_empty__17TWindowOptionCtrlFPUc(TAdEnterSerialAccessGC__sub_80321874())), (u32)0);
        ((TWindowOptionCtrl *)w)->add_label_value_line((const char *)(get_localized_text_entry(0xF, 0x17)), (const char *)(warn_if_empty__17TWindowOptionCtrlFPUc(TAdEnterSerialAccessGC__sub_803217B8())), (u32)0);
        ((TWindowOptionCtrl *)w)->add_label_value_line((const char *)(get_localized_text_entry(0xF, 0x18)), (const char *)(warn_if_empty__17TWindowOptionCtrlFPUc(TAdEnterPasswordGC__sub_8013ADE4())), (u32)0);
        break;
    case 1:
        ((TWindowOptionCtrl *)w)->add_label_value_line((const char *)(get_localized_text_entry(0xF, 0x16)), (const char *)(warn_if_empty__17TWindowOptionCtrlFPUc(TAdEnterSerialAccessGC__sub_80321738())), (u32)0);
        ((TWindowOptionCtrl *)w)->add_label_value_line((const char *)(get_localized_text_entry(0xF, 0x17)), (const char *)(warn_if_empty__17TWindowOptionCtrlFPUc(TAdEnterSerialAccessGC::get_formatted_serial())), (u32)0);
        ((TWindowOptionCtrl *)w)->add_label_value_line((const char *)(get_localized_text_entry(0xF, 0x18)), (const char *)(warn_if_empty__17TWindowOptionCtrlFPUc(get_chr_select_base_plus_1154c__17TWindowOptionCtrlFv())), (u32)0);
        break;
    }
    ((TWindowMessage *)w)->complete_reveal();
    return w;
}

s32 TWindowOptionCtrl::open_yes_no_window(s32 arg0, s32 arg1, s32 arg2) {
  s32 temp_r30;
  u8 *temp_r31;
  temp_r30 = create__19TWindowMessageYesNoFPvPvPvPv(arg0, 6, arg0 * 0, 0);
  ;
  forward_slot_selection__16TAdChrSelASlotGCFPvPv((int) temp_r30, (void *) get_localized_text_entry(0xF, arg1), (int) ((u8 *) get_window_layout_position(arg2)), (f32) lbl_805DD268);
  free_member__17TWindowSubComCardFv((int) temp_r30, 1);
  return temp_r30;
}

}
