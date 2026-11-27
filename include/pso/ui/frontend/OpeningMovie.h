#ifndef PSO_UI_FRONTEND_OPENINGMOVIE_H
#define PSO_UI_FRONTEND_OPENINGMOVIE_H

#include "types.h"

struct TMovie;

// Set by verify_game_file_integrity when a disc file's size or CRC differs from file_integrity_table.
extern s32 game_files_modified_flag;

s32 verify_game_file_integrity(void);

// Also the TMovie end callback of the opening movie: takes the callback's argument.
void set_movie_finished_flag(TMovie *);

// Main phase 3 (the opening movie): init, per-frame update and exit slots of main_phase_table.
void init_movie_phase(void);
void update_movie_phase(void);
void exit_movie_phase(void);

s8 get_opening_movie_purpose(void);
void set_opening_movie_purpose(int a0);

typedef struct FileIntegrityEntry {
    const char *file;
    u32 size;
    u32 crc;
} FileIntegrityEntry;

extern s32 opening_movie_selector;

#endif
