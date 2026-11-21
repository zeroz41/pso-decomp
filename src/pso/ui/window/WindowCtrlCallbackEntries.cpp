#include "types.h"

// Data-only unit split off TWindowCtrl callback entries at 0x804CE9C8; the referencing units keep these extern.

extern u8 TWindowCtrlMain__sub_8024D85C[];
extern u8 TWindowCtrlMain__sub_8024D868[];
extern u8 TWindowCtrl__sub_8024C6CC[];
extern u8 TWindowCtrl__sub_8024C6DC[];
extern u8 TWindowCtrl__sub_8024C6EC[];
extern u8 TWindowCtrl__sub_8024C6FC[];
extern u8 TWindowCtrl__sub_8024C70C[];
extern u8 TWindowCtrl__sub_8024C71C[];
extern u8 TWindowCtrl__sub_8024C72C[];
extern u8 TWindowCtrl__sub_8024C73C[];
extern u8 TWindowCtrl__sub_8024C74C[];
extern u8 TWindowCtrl__sub_8024C75C[];
extern u8 TWindowCtrl__sub_8024C7C4[];
extern u8 TWindowCtrl__sub_8024C7D4[];
extern u8 __dt__11TWindowCtrlFv[];
extern u8 clear_flag_bit0__11TWindowCtrlFv[];
extern u8 get_active_menu__11TWindowCtrlFv[];
extern u8 is_visible__11TWindowCtrlFv[];
extern u8 render__11TWindowCtrlFv[];
extern u8 render_shadows__7TObjectFv[];
extern u8 run_task__11TWindowCtrlFv[];
extern u8 set_radar_dirty_flag__11TWindowCtrlFv[];

__declspec(section ".data") extern u32 window_ctrl_is_visible_callback_entry[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)is_visible__11TWindowCtrlFv,
};

__declspec(section ".data") extern u32 lbl_804CE9D4[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowCtrl__sub_8024C7D4,
};

__declspec(section ".data") extern u32 window_ctrl_apply_default_vec_callback_entry[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowCtrl__sub_8024C7C4,
};

__declspec(section ".data") extern u32 TWindowCtrl__player_menu_query_cb[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)get_active_menu__11TWindowCtrlFv,
};

__declspec(section ".data") extern u32 TWindowCtrl__unsuppress_slot_cb[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)clear_flag_bit0__11TWindowCtrlFv,
};

__declspec(section ".data") extern u32 TWindowCtrl__suppress_slot_cb[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)set_radar_dirty_flag__11TWindowCtrlFv,
};

__declspec(section ".data") extern u32 lbl_804CEA10[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowCtrl__sub_8024C75C,
};

__declspec(section ".data") extern u32 lbl_804CEA1C[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowCtrl__sub_8024C74C,
};

__declspec(section ".data") extern u32 window_ctrl_end_keyboard_hold_callback_entry[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowCtrl__sub_8024C73C,
};

__declspec(section ".data") extern u32 player_keyboard_hold_cb[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowCtrl__sub_8024C72C,
};

__declspec(section ".data") extern u32 lbl_804CEA40[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowCtrl__sub_8024C71C,
};

__declspec(section ".data") extern u32 lbl_804CEA4C[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowCtrl__sub_8024C70C,
};

__declspec(section ".data") extern u32 lbl_804CEA58[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowCtrl__sub_8024C6FC,
};

__declspec(section ".data") extern u32 lbl_804CEA64[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowCtrl__sub_8024C6EC,
};

__declspec(section ".data") extern u32 TWindowSubComCard__window_ctrl_callback_pmf[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowCtrl__sub_8024C6DC,
};

__declspec(section ".data") extern u32 window_ctrl_init_params[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowCtrl__sub_8024C6CC,
};

__declspec(section ".data") extern u32 window_ctrl_main_callback_desc[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowCtrlMain__sub_8024D868,
};

__declspec(section ".data") extern u32 window_ctrl_default_call_args[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowCtrlMain__sub_8024D85C,
};
