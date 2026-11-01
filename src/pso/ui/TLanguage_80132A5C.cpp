#include "types.h"
#include "pso/misc/TLobby_800F9690.h"
#include "pso/misc/TLanguage.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/Language.h"
#include "pso/misc/TWindowSubStatusDisp.h"

struct GvmTextureInner { char pad8[0x8]; u32 f8; };
struct GvmTexture { struct GvmTextureInner *f0; };

extern const char TLanguage__class_name[];
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
int TWindowKeyBoardSoft__text_resource;
int text_language_group_table;
struct GvmTexture *localized_alphabet_list;
language current_language;
int TWindowKeyBoardSoft__language_text_resources;

extern "C" {
u8 *load_gvm_texture_file(s32 arg0);
s32 release_texture_list(void *);
}

void TLanguage::free_alphabet_textures() {
    if (localized_alphabet_list != NULL) {
        struct GvmTextureInner *inner = localized_alphabet_list->f0;
        if (inner->f8 != 0U) {
            release_texture_list(localized_alphabet_list);
        }
        TAdSinglePlyChrSelectGC::safe_free((u32)localized_alphabet_list);
        localized_alphabet_list = NULL;
    }
}

void TLanguage::free_text_resources() {
    TLobby::free_nodes_with_id(TWindowKeyBoardSoft__text_resource);
    TWindowKeyBoardSoft__language_text_resources = 0;
    text_language_group_table = 0;
    TWindowKeyBoardSoft__text_resource = 0;
}

void TLanguage::load_fonts(s32 language) {
    s32 sp8;
    GvmTexture *alphabet;
    sp8 = TLobby::tmp_buf_use_req(TLanguage__class_name);
    TLanguage::draw_string((void *)f256_alphabet_gvp, &sp8, 0x48);
    TLobby::tmp_buf_release((const char *)TLanguage__class_name);

    switch (language) {
        case LANGUAGE_JAPANESE:
            TLanguage::draw_string((void *)f256_symbolsetumei_jpn_gvp, &sp8, 0x49);
            TLanguage::draw_string((void *)f128_keyjpn_gvp, &sp8, 2);
            TLanguage::draw_string((void *)f064_wordmojitex_jpn_gvp, &sp8, 3);
            TLanguage::decode_font_data((void *)b256_menutext01_j_gvp, &sp8, 0x4B, 0x4C);
            alphabet = (GvmTexture *)load_gvm_texture_file((s32)TextureJapanese_gvm);
            localized_alphabet_list = alphabet;
            break;

        case LANGUAGE_GERMAN:
            TLanguage::draw_string((void *)f256_symbolsetumei_ger_gvp, &sp8, 0x49);
            TLanguage::draw_string((void *)f128_keyeng_gvp, &sp8, 2);
            TLanguage::draw_string((void *)f064_wordmojitex_ger_gvp, &sp8, 3);
            TLanguage::decode_font_data((void *)b256_menutext01_e_gvp, &sp8, 0x4B, 0x4C);
            alphabet = (GvmTexture *)load_gvm_texture_file((s32)TextureGerman_gvm);
            localized_alphabet_list = alphabet;
            break;

        case LANGUAGE_FRENCH:
            TLanguage::draw_string((void *)f256_symbolsetumei_fre_gvp, &sp8, 0x49);
            TLanguage::draw_string((void *)f128_keyeng_gvp, &sp8, 2);
            TLanguage::draw_string((void *)f064_wordmojitex_fre_gvp, &sp8, 3);
            TLanguage::decode_font_data((void *)b256_menutext01_e_gvp, &sp8, 0x4B, 0x4C);
            alphabet = (GvmTexture *)load_gvm_texture_file((s32)TextureFrench_gvm);
            localized_alphabet_list = alphabet;
            break;

        case LANGUAGE_SPANISH:
            TLanguage::draw_string((void *)f256_symbolsetumei_spa_gvp, &sp8, 0x49);
            TLanguage::draw_string((void *)f128_keyeng_gvp, &sp8, 2);
            TLanguage::draw_string((void *)f064_wordmojitex_spa_gvp, &sp8, 3);
            TLanguage::decode_font_data((void *)b256_menutext01_e_gvp, &sp8, 0x4B, 0x4C);
            alphabet = (GvmTexture *)load_gvm_texture_file((s32)TextureSpanish_gvm);
            localized_alphabet_list = alphabet;
            break;

        default:
            TLanguage::draw_string((void *)f256_symbolsetumei_eng_gvp, &sp8, 0x49);
            TLanguage::draw_string((void *)f128_keyeng_gvp, &sp8, 2);
            TLanguage::draw_string((void *)f064_wordmojitex_eng_gvp, &sp8, 3);
            TLanguage::decode_font_data((void *)b256_menutext01_e_gvp, &sp8, 0x4B, 0x4C);
            alphabet = (GvmTexture *)load_gvm_texture_file((s32)TextureEnglish_gvm);
            localized_alphabet_list = alphabet;
            break;
    }

    TWindowSubStatusDisp::begin_render((s32)alphabet);

    TLanguage::set_entry_index(LANGUAGE_JAPANESE, 0x48);
    TLanguage::set_entry_index(LANGUAGE_GERMAN, 0x4B);
    TLanguage::set_entry_index(LANGUAGE_ENGLISH, 0x49);
    TLanguage::set_entry_index(LANGUAGE_FRENCH, 2);
    TLanguage::set_entry_index(LANGUAGE_SPANISH, 3);
}

void TLanguage::load_text_resources(s32 arg0) {
    switch (arg0) {
    case LANGUAGE_JAPANESE:
        (*(u8 * *)&TWindowKeyBoardSoft__text_resource) = (u8 *)load_text_resource_pair((s32)TextJapanese);
        break;
    case LANGUAGE_GERMAN:
        (*(u8 * *)&TWindowKeyBoardSoft__text_resource) = (u8 *)load_text_resource_pair((s32)TextGerman);
        break;
    case LANGUAGE_FRENCH:
        (*(u8 * *)&TWindowKeyBoardSoft__text_resource) = (u8 *)load_text_resource_pair((s32)TextFrench);
        break;
    case LANGUAGE_SPANISH:
        (*(u8 * *)&TWindowKeyBoardSoft__text_resource) = (u8 *)load_text_resource_pair((s32)TextSpanish);
        break;
    default:
        (*(u8 * *)&TWindowKeyBoardSoft__text_resource) = (u8 *)load_text_resource_pair((s32)TextEnglish);
        break;
    }
    (*(s32 *)&TWindowKeyBoardSoft__language_text_resources) = *(s32 *)((s8 *)(*(u8 * *)&TWindowKeyBoardSoft__text_resource) + 0);
    (*(s32 *)&text_language_group_table) = *(s32 *)((s8 *)(*(u8 * *)&TWindowKeyBoardSoft__text_resource) + 4);
}

__declspec(section ".rodata") extern const char TLanguage__class_name[] = "TLanguage";
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
    u8 *save_payload;

    if ((s32) current_language == language) {
        return 0;
    }

    TLanguage::free_alphabet_textures();
    TLanguage::free_text_resources();

    save_payload = TAdSinglePlyChrSelectGC::get_global_state();
    if (save_payload != NULL) {
        *(s8 *)((s8 *)save_payload + 7) = language;
    }

    current_language = (enum language)(s8) language;
    TLanguage::load_text_resources((s8) current_language);
    TLanguage::load_fonts(current_language);

    return 1;
}

s8 TLanguage::get_default_language() {
    return LANGUAGE_ENGLISH;
}
