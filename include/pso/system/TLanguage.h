#ifndef PSO_SYSTEM_TLANGUAGE_H
#define PSO_SYSTEM_TLANGUAGE_H

#include "types.h"

struct TLanguage
{
    static void free_alphabet_textures();
    static void free_text_resources();
    static void load_fonts(s32 language);
    static void load_text_resources(s32 language);
    static s32 set_language(s8 language);
    static s8 get_default_language();
    static void draw_string(void *arg0, void *arg1, s32 arg2);
    static void decode_font_data(void *arg0, void *arg1, s32 arg2, s32 arg3);
    static void read_into_buffer(s32 arg0, s32 arg1);
    static s32 read_u32_le();
    static s32 read_u16_le();
    void set_index(s32 arg1);
    static void set_entry_index(s32 i, s32 x);
    static void load_container_fragment_textures();
    static void load_lobby_textures();
};

#endif
