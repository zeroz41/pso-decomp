#include "types.h"
#include <string.h>
#include "pso/audio/AdxfInternal.h"
#include "pso/system/Adxf.h"
 extern const char lbl_8047C7E8[46] = "\nADXF/GC Ver.6.24 Build:Jun 13 2002 19:00:56\n";
s32 lbl_805D75D0;
s32 lobby_adxf_current_file_id;
AdxfHandle *lobby_adxf_open_file_handle;
s32 lobby_afs_toc_entry_index;
s32 adxf_log_write_index;
s32 lbl_805D75E4;
/* points at the ADXF version/build banner above */
const char *const volatile adxf_build_string = lbl_8047C7E8;

AdxfLogHeader adxf_log_header;
AdxfLogEntry adxf_log_entries[256];
u8 afs_archive_toc_table[0x400];
AdxfHandle adxf_file_handle_pool[16];

void adxf_finish(void) {
    if (--lbl_805D75D0 == 0) {
        ADXF_CloseAll();
        lobby_adxf_current_file_id = -1;
        lobby_adxf_open_file_handle = 0;
        lobby_afs_toc_entry_index = 0;
        lbl_805D75E4 = 0;
        adxf_log_write_index = 0;
        memset(&adxf_log_header, 0, sizeof(adxf_log_header));
        memset(adxf_log_entries, 0xFF, sizeof(adxf_log_entries));
        memset(afs_archive_toc_table, 0, 0x400);
        memset(adxf_file_handle_pool, 0, sizeof(adxf_file_handle_pool));
    }
}

void adxf_init(void) {
    adxf_build_string;
    if (lbl_805D75D0 == 0) {
        memset(adxf_file_handle_pool, 0, sizeof(adxf_file_handle_pool));
        memset(afs_archive_toc_table, 0, 0x400);
        memset(adxf_log_entries, 0xFF, sizeof(adxf_log_entries));
        memset(&adxf_log_header, 0, sizeof(adxf_log_header));
        adxf_log_write_index = 0;
        lbl_805D75E4 = 0;
        lobby_afs_toc_entry_index = 0;
        lobby_adxf_open_file_handle = 0;
        lobby_adxf_current_file_id = -1;
    }
    lbl_805D75D0++;
}
