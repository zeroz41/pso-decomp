#ifndef PSO_SYSTEM_TLANGUAGE_H
#define PSO_SYSTEM_TLANGUAGE_H

#include "types.h"

struct GvmFileHeader;
struct GvplPalette;

struct TLanguage
{
    static void free_alphabet_textures();
    static void free_text_resources();
    static void load_fonts(s32 language);
    static void load_text_resources(s32 language);
    static s32 set_language(s8 language);
    static s8 get_default_language();
    // Loads a GVPL palette file into `palette` and from it the TLUT `tlut_name`.
    static void load_palette_tlut(const char *filename, GvplPalette *palette, s32 tlut_name);
    static void decode_font_data(const char *filename, GvplPalette *palette, s32 tlut_name, s32 inverted_tlut_name);
    static int read_file_header(u8 *cursor, GvmFileHeader *header);
    static void read_into_buffer(void *destination, s32 length);
    static s32 read_u32_le();
    static s32 read_u16_le();

    // The loaded language's text file: two words, the language text resources and the group table.
    static void **text_resource;

    // Tag of the temporary buffer load_fonts borrows.
    static const char class_name[];
};

// The loaded text resource's string groups: text_language_group_table[group][id] is one string.
extern char ***text_language_group_table;
// The loaded text resource's soft keyboard layout (its first word).
extern u8 *soft_keyboard_layouts;

#endif
