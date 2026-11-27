#ifndef PSO_SYSTEM_MALLOCLOADFILEPRC_H
#define PSO_SYSTEM_MALLOCLOADFILEPRC_H

#include "pso/system/ResourceFile.h"
#include "types.h"

struct AdxfHandle;
struct GslArchiveEntry;
struct RelFileTrailer;
class TRelDataFile;
class TObject;

// A disk error message and where run_disk_error_check draws it.
struct DiskErrorMsg {
    const char *str;
    f32 x;
    f32 y;
};

// The name copy_name last copied (16 characters, not terminated when full).
extern char player_name_copy_buffer[16];
// What __sinit stores into disc_read_filename: an empty file name.
extern const char *empty_string;
void flag_pending_area_transfer(void);
void reset_to_fallback_main_phase(void);
void request_pending_file_read_flush(void);
void set_lobby_state_byte_flag(void);

// The GSL archive close hook: hands the archive's entries to gsl_archive_close_stub.
void on_gsl_archive_close(char *filename, GslArchiveEntry *entries, s32 count);
// Reads and decrypts an encrypted archive; size receives its decompressed size.
void *load_encrypted_text_archive(char *name, s32 *size);
// Loads name.pr2 and its relocations name.pr3 as one named resource file; returns its root.
saddr load_text_resource_pair(saddr name);
// The named resource files: load, relocate and register under resource_load_task_root.
void *load_encrypted_archive_data(const char *name);
void *alloc_named_object(const char *name, u8 *data, s32 size, RelFileTrailer *relocs);
void *load_rel_data_file(const char *name, u8 *data, s32 size);
void *apply_pointer_relocations(TRelDataFile *file, RelFileTrailer *relocs);
void *apply_rel_relocations(TRelDataFile *file);
TObject *get_load_fade_task(void);

// Sets the keyboard callback that belongs to the current main phase.
void apply_phase_keyboard_mode();
s32 is_area_transfer_pending();

s32 *get_player_name_copy_buffer(void);

void copy_name(char *name);

void clear_player_name_copy_buffer(void);

void clear_resource_load_tasks(void);
void *create_named_object(const char *name);
void invoke_callback();
void reset_read_state();
void clear_player_slot_tables(s32 n);
void set_read_params(AdxfHandle **handle_ref, int sector_count, void *destination);
void draw_fullscreen_texture_quad(s32 texture);
void set_entry_params(AdxfHandle **handle, s32 index, s32 sector_count, void *buffer);
void release_menu_font();
void load_font_texture();
void reset_state_byte();
void wait_ready_loop();
void run_frame();
s32 run_disk_error_check();
void flush_pending();
void flush_checked_reads();

// Applies the REL relocations of a file already in memory; returns its root, or NULL when size is not positive.
void *relocate_rel_data(void *data, s32 size);

void free_data_file(void *p);
// Loads a whole file into a new buffer; free_data_file frees it.
void *load_data_file(const char *path);

#endif
