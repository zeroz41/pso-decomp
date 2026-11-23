#ifndef PSO_SYSTEM_TLANGUAGE_H
#define PSO_SYSTEM_TLANGUAGE_H

#include "types.h"

struct GvmFileHeader;

struct TLanguage
{
    static void free_alphabet_textures();
    static void free_text_resources();
    static void load_fonts(s32 language);
    static void load_text_resources(s32 language);
    static s32 set_language(s8 language);
    static s8 get_default_language();
    static void draw_string(void *filename, void *palette, s32 tlut_name);
    static void decode_font_data(void *arg0, void *arg1, s32 arg2, s32 tlut_name);
    static int read_file_header(u8 *cursor, GvmFileHeader *header);
    static void read_into_buffer(void *destination, s32 length);
    static s32 read_u32_le();
    static s32 read_u16_le();
    void set_index(s32 x);
    static void set_entry_index(s32 i, s32 x);
    static void load_container_fragment_textures();
};

#endif
