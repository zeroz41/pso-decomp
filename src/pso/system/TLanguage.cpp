#include "pso/system/memory.h"
#include "pso/render/GinjaTextureHeader.h"
#include "types.h"
#include "pso/system/MallocLoadFilePrc.h"
#include "pso/system/TLanguage.h"
#include "pso/network/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/system/BmlResource.h"

extern const char f256_alphabet_gvp[];
extern const char f256_symbolsetumei_jpn_gvp[];
extern const char f128_keyjpn_gvp[];
extern const char f064_wordmojitex_jpn_gvp[];
extern const char b256_menutext01_j_gvp[];
extern const char TextureJapanese_gvm[];
extern const char f256_symbolsetumei_ger_gvp[];
extern const char f128_keyeng_gvp[];
extern const char f064_wordmojitex_ger_gvp[];
extern const char b256_menutext01_e_gvp[];
extern const char TextureGerman_gvm[];
extern const char f256_symbolsetumei_fre_gvp[];
extern const char f064_wordmojitex_fre_gvp[];
extern const char TextureFrench_gvm[];
extern const char f256_symbolsetumei_spa_gvp[];
extern const char f064_wordmojitex_spa_gvp[];
extern const char TextureSpanish_gvm[];
extern const char f256_symbolsetumei_eng_gvp[];
extern const char f064_wordmojitex_eng_gvp[];
extern const char TextureEnglish_gvm[];
extern const char TextJapanese[];
extern const char TextGerman[];
extern const char TextFrench[];
extern const char TextSpanish[];
extern const char TextEnglish[];
void **TLanguage::text_resource;
char ***text_language_group_table;
NJS_TEXLIST *localized_alphabet_list;
language current_language;
u8 *soft_keyboard_layouts;

void TLanguage::free_alphabet_textures() {
    if (localized_alphabet_list != NULL) {
        if (localized_alphabet_list->textures->texaddr != 0) {
            release_texture_list(localized_alphabet_list);
        }
        safe_free(localized_alphabet_list);
        localized_alphabet_list = NULL;
    }
}

void TLanguage::free_text_resources() {
    TLobby::free_nodes_with_id(text_resource);
    soft_keyboard_layouts = NULL;
    text_language_group_table = 0;
    text_resource = NULL;
}

void TLanguage::load_fonts(s32 language) {
    GvplPalette palette;
    palette.data = tmp_buf_use_req(class_name);
    TLanguage::load_palette_tlut(f256_alphabet_gvp, &palette, 0x48);
    tmp_buf_release(class_name);

    switch (language) {
        case LANGUAGE_JAPANESE:
            TLanguage::load_palette_tlut(f256_symbolsetumei_jpn_gvp, &palette, 0x49);
            TLanguage::load_palette_tlut(f128_keyjpn_gvp, &palette, 2);
            TLanguage::load_palette_tlut(f064_wordmojitex_jpn_gvp, &palette, 3);
            TLanguage::decode_font_data(b256_menutext01_j_gvp, &palette, 0x4B, 0x4C);
            localized_alphabet_list = LoadPvmFileTls(TextureJapanese_gvm);
            break;

        case LANGUAGE_GERMAN:
            TLanguage::load_palette_tlut(f256_symbolsetumei_ger_gvp, &palette, 0x49);
            TLanguage::load_palette_tlut(f128_keyeng_gvp, &palette, 2);
            TLanguage::load_palette_tlut(f064_wordmojitex_ger_gvp, &palette, 3);
            TLanguage::decode_font_data(b256_menutext01_e_gvp, &palette, 0x4B, 0x4C);
            localized_alphabet_list = LoadPvmFileTls(TextureGerman_gvm);
            break;

        case LANGUAGE_FRENCH:
            TLanguage::load_palette_tlut(f256_symbolsetumei_fre_gvp, &palette, 0x49);
            TLanguage::load_palette_tlut(f128_keyeng_gvp, &palette, 2);
            TLanguage::load_palette_tlut(f064_wordmojitex_fre_gvp, &palette, 3);
            TLanguage::decode_font_data(b256_menutext01_e_gvp, &palette, 0x4B, 0x4C);
            localized_alphabet_list = LoadPvmFileTls(TextureFrench_gvm);
            break;

        case LANGUAGE_SPANISH:
            TLanguage::load_palette_tlut(f256_symbolsetumei_spa_gvp, &palette, 0x49);
            TLanguage::load_palette_tlut(f128_keyeng_gvp, &palette, 2);
            TLanguage::load_palette_tlut(f064_wordmojitex_spa_gvp, &palette, 3);
            TLanguage::decode_font_data(b256_menutext01_e_gvp, &palette, 0x4B, 0x4C);
            localized_alphabet_list = LoadPvmFileTls(TextureSpanish_gvm);
            break;

        default:
            TLanguage::load_palette_tlut(f256_symbolsetumei_eng_gvp, &palette, 0x49);
            TLanguage::load_palette_tlut(f128_keyeng_gvp, &palette, 2);
            TLanguage::load_palette_tlut(f064_wordmojitex_eng_gvp, &palette, 3);
            TLanguage::decode_font_data(b256_menutext01_e_gvp, &palette, 0x4B, 0x4C);
            localized_alphabet_list = LoadPvmFileTls(TextureEnglish_gvm);
            break;
    }

    TWindowSubStatusDisp::begin_render();

    set_context_texture_palette_bank(LANGUAGE_JAPANESE, 0x48);
    set_context_texture_palette_bank(LANGUAGE_GERMAN, 0x4B);
    set_context_texture_palette_bank(LANGUAGE_ENGLISH, 0x49);
    set_context_texture_palette_bank(LANGUAGE_FRENCH, 2);
    set_context_texture_palette_bank(LANGUAGE_SPANISH, 3);
}

void TLanguage::load_text_resources(s32 language) {
    switch (language) {
    case LANGUAGE_JAPANESE:
        text_resource = (void **)load_text_resource_pair((saddr)TextJapanese);
        break;
    case LANGUAGE_GERMAN:
        text_resource = (void **)load_text_resource_pair((saddr)TextGerman);
        break;
    case LANGUAGE_FRENCH:
        text_resource = (void **)load_text_resource_pair((saddr)TextFrench);
        break;
    case LANGUAGE_SPANISH:
        text_resource = (void **)load_text_resource_pair((saddr)TextSpanish);
        break;
    default:
        text_resource = (void **)load_text_resource_pair((saddr)TextEnglish);
        break;
    }
    soft_keyboard_layouts = (u8 *)text_resource[0];
    text_language_group_table = (char ***)text_resource[1];
}

__declspec(section ".rodata") const char TLanguage::class_name[] = "TLanguage";
__declspec(section ".rodata") extern const char f256_alphabet_gvp[] = "f256_alphabet.gvp";
__declspec(section ".rodata") extern const char f256_symbolsetumei_jpn_gvp[] = "f256_symbolsetumei_jpn.gvp";
__declspec(section ".rodata") extern const char f128_keyjpn_gvp[] = "f128_keyjpn.gvp";
__declspec(section ".rodata") extern const char f064_wordmojitex_jpn_gvp[] = "f064_wordmojitex_jpn.gvp";
__declspec(section ".rodata") extern const char b256_menutext01_j_gvp[] = "b256_menutext01_j.gvp";
__declspec(section ".rodata") extern const char TextureJapanese_gvm[] = "TextureJapanese.gvm";
__declspec(section ".rodata") extern const char f256_symbolsetumei_ger_gvp[] = "f256_symbolsetumei_ger.gvp";
__declspec(section ".rodata") extern const char f128_keyeng_gvp[] = "f128_keyeng.gvp";
__declspec(section ".rodata") extern const char f064_wordmojitex_ger_gvp[] = "f064_wordmojitex_ger.gvp";
__declspec(section ".rodata") extern const char b256_menutext01_e_gvp[] = "b256_menutext01_e.gvp";
__declspec(section ".rodata") extern const char TextureGerman_gvm[] = "TextureGerman.gvm";
__declspec(section ".rodata") extern const char f256_symbolsetumei_fre_gvp[] = "f256_symbolsetumei_fre.gvp";
__declspec(section ".rodata") extern const char f064_wordmojitex_fre_gvp[] = "f064_wordmojitex_fre.gvp";
__declspec(section ".rodata") extern const char TextureFrench_gvm[] = "TextureFrench.gvm";
__declspec(section ".rodata") extern const char f256_symbolsetumei_spa_gvp[] = "f256_symbolsetumei_spa.gvp";
__declspec(section ".rodata") extern const char f064_wordmojitex_spa_gvp[] = "f064_wordmojitex_spa.gvp";
__declspec(section ".rodata") extern const char TextureSpanish_gvm[] = "TextureSpanish.gvm";
__declspec(section ".rodata") extern const char f256_symbolsetumei_eng_gvp[] = "f256_symbolsetumei_eng.gvp";
__declspec(section ".rodata") extern const char f064_wordmojitex_eng_gvp[] = "f064_wordmojitex_eng.gvp";
__declspec(section ".rodata") extern const char TextureEnglish_gvm[] = "TextureEnglish.gvm";
__declspec(section ".rodata") extern const char TextJapanese[] = "TextJapanese";
__declspec(section ".rodata") extern const char TextGerman[] = "TextGerman";
__declspec(section ".rodata") extern const char TextFrench[] = "TextFrench";
__declspec(section ".rodata") extern const char TextSpanish[] = "TextSpanish";
__declspec(section ".rodata") extern const char TextEnglish[] = "TextEnglish";

s32 TLanguage::set_language(s8 language) {
    SystemSaveData *save_payload;

    if ((s32) current_language == language) {
        return 0;
    }

    TLanguage::free_alphabet_textures();
    TLanguage::free_text_resources();

    save_payload = TAdSinglePlyChrSelectGC::get_global_state();
    if (save_payload != NULL) {
        save_payload->language = language;
    }

    current_language = (enum language)(s8) language;
    TLanguage::load_text_resources((s8) current_language);
    TLanguage::load_fonts(current_language);

    return 1;
}

s8 TLanguage::get_default_language() {
    return LANGUAGE_ENGLISH;
}
