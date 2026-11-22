#ifndef PSO_UNK_TLOBBY_800F8AA8_H
#define PSO_UNK_TLOBBY_800F8AA8_H

#include "pso/system/ResourceFile.h"
#include "types.h"

struct GslArchiveEntry;
struct RelFileTrailer;
class TUnk_8049C658;
class TObject;

extern "C" {
// The name copy_name last copied (16 characters, not terminated when full).
extern char player_name_copy_buffer[16];
// What __sinit stores into disc_read_filename: an empty file name.
extern const char *lbl_805D2B10;

void TLobby__sub_800F8AD0(void);
void TLobby__sub_800F8BD8(void);
void TLobby__sub_800F8DD8(void);
void TLobby__sub_800F8F34(void);

// The GSL archive close hook: hands the archive's entries to fn_800FFE14.
void fn_800F93B4(char *filename, GslArchiveEntry *entries, s32 count);
// Reads and decrypts an encrypted archive; size receives its decompressed size.
saddr load_encrypted_text_archive(char *name, s32 *size);
// Loads name.pr2 and its relocations name.pr3 as one named resource file; returns its root.
saddr load_text_resource_pair(saddr name);
// The named resource files: load, relocate and register under resource_load_task_root.
void *load_encrypted_archive_data(const char *name);
void *alloc_named_object(const char *name, u8 *data, s32 size, RelFileTrailer *relocs);
void *TLobby__sub_800F9A60(const char *name, u8 *data, s32 size);
void *apply_pointer_relocations(TUnk_8049C658 *file, RelFileTrailer *relocs);
void *apply_rel_relocations(TUnk_8049C658 *file);
TObject *TLoadCtrl__sub_800F9F00(void);
}

// Sets the keyboard callback that belongs to the current main phase.
void apply_phase_keyboard_mode();
s32 is_area_transfer_pending();

#endif
