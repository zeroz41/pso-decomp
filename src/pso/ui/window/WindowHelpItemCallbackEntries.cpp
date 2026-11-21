#include "types.h"

// Data-only unit split off TWindowHelpItem callback entries at 0x804CF868; the referencing units keep these extern.

extern u8 TWindowHelpItem__sub_802531A0[];
extern u8 TWindowHelpItem__sub_80253268[];
extern u8 update_stat_disp__15TWindowHelpItemFv[];

__declspec(section ".data") extern u32 item_help_resistance_stat_callback[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)update_stat_disp__15TWindowHelpItemFv,
};

__declspec(section ".data") extern u32 TWindowHelpItem__mag_growth_update_callback[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowHelpItem__sub_802531A0,
};

__declspec(section ".data") extern u32 TWindowHelpItem__photon_blast_update_callback[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowHelpItem__sub_802531A0,
};

__declspec(section ".data") extern u32 item_help_description_idle_callback[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowHelpItem__sub_802531A0,
};

__declspec(section ".data") extern u32 item_help_tech_disk_stats_callback[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowHelpItem__sub_80253268,
};

__declspec(section ".data") extern u32 TWindowHelpItem__description_update_callback[3] = {
    0x00000000, 0xFFFFFFFF, (uaddr)TWindowHelpItem__sub_802531A0,
};
