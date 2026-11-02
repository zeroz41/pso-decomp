#include "types.h"
#include "pso/misc/TLobby.h"

extern "C" {

s32 memset(void *, int, int);
s32 lbl_805D75D0;
extern s32 lobby_adxf_current_file_id;
extern s32 lobby_adxf_open_file_handle;
extern s32 lobby_afs_toc_entry_index;
extern s32 adxf_log_write_index;
extern s32 lbl_805D75E4;
extern const char *const volatile lbl_805E0D80;

u8 lbl_8057B7B0[0x20];
u8 lbl_8057B7D0[0x1000];
u8 afs_archive_toc_table[0x400];
u8 adxf_file_handle_pool[0x1380];

void TLobby::dec_ref_and_reset_tables() {
    if (--lbl_805D75D0 == 0) {
        TLobby::release_used_slots();
        lobby_adxf_current_file_id = -1;
        lobby_adxf_open_file_handle = 0;
        lobby_afs_toc_entry_index = 0;
        lbl_805D75E4 = 0;
        adxf_log_write_index = 0;
        memset(lbl_8057B7B0, 0, 0x20);
        memset(lbl_8057B7D0, 0xFF, 0x1000);
        memset(afs_archive_toc_table, 0, 0x400);
        memset(adxf_file_handle_pool, 0, 0x1380);
    }
}

void TLobby::init_afs_adxf_state() {
    lbl_805E0D80;
    if (lbl_805D75D0 == 0) {
        memset(adxf_file_handle_pool, 0, 0x1380);
        memset(afs_archive_toc_table, 0, 0x400);
        memset(lbl_8057B7D0, 0xFF, 0x1000);
        memset(lbl_8057B7B0, 0, 0x20);
        adxf_log_write_index = 0;
        lbl_805D75E4 = 0;
        lobby_afs_toc_entry_index = 0;
        lobby_adxf_open_file_handle = 0;
        lobby_adxf_current_file_id = -1;
    }
    lbl_805D75D0++;
}

}
