#include "types.h"
#include <string.h>
#include "pso/audio/AdxfInternal.h"
#include "pso/unk/TLobby.h"
 extern const char lbl_8047C7E8[46] = "\nADXF/GC Ver.6.24 Build:Jun 13 2002 19:00:56\n";
s32 lbl_805D75D0;
s32 lobby_adxf_current_file_id;
AdxfHandle *lobby_adxf_open_file_handle;
s32 lobby_afs_toc_entry_index;
s32 adxf_log_write_index;
s32 lbl_805D75E4;
/* points at the ADXF version/build banner above */
const char *const volatile adxf_build_string = lbl_8047C7E8;

LogHdr_803CD16C lbl_8057B7B0;
LogEnt_803CD16C lbl_8057B7D0[256];
u8 afs_archive_toc_table[0x400];
AdxfHandle adxf_file_handle_pool[16];

void TLobby::dec_ref_and_reset_tables() {
    if (--lbl_805D75D0 == 0) {
        TLobby::release_used_slots();
        lobby_adxf_current_file_id = -1;
        lobby_adxf_open_file_handle = 0;
        lobby_afs_toc_entry_index = 0;
        lbl_805D75E4 = 0;
        adxf_log_write_index = 0;
        memset(&lbl_8057B7B0, 0, sizeof(lbl_8057B7B0));
        memset(lbl_8057B7D0, 0xFF, sizeof(lbl_8057B7D0));
        memset(afs_archive_toc_table, 0, 0x400);
        memset(adxf_file_handle_pool, 0, sizeof(adxf_file_handle_pool));
    }
}

void TLobby::init_afs_adxf_state() {
    adxf_build_string;
    if (lbl_805D75D0 == 0) {
        memset(adxf_file_handle_pool, 0, sizeof(adxf_file_handle_pool));
        memset(afs_archive_toc_table, 0, 0x400);
        memset(lbl_8057B7D0, 0xFF, sizeof(lbl_8057B7D0));
        memset(&lbl_8057B7B0, 0, sizeof(lbl_8057B7B0));
        adxf_log_write_index = 0;
        lbl_805D75E4 = 0;
        lobby_afs_toc_entry_index = 0;
        lobby_adxf_open_file_handle = 0;
        lobby_adxf_current_file_id = -1;
    }
    lbl_805D75D0++;
}
