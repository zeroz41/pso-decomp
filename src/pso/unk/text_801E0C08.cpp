#include "types.h"
#include "pso/network/TProtocol.h"
#include "pso/unk/text_801E0C08.h"

extern "C" {
s32 construct_guild_card_tag_array(s32);
void __sinit_text_801E0C08_cpp(void) {
    construct_guild_card_tag_array((s32)&meet_user_settings);
}

}

__declspec(section ".ctors") static void *const __sinit_text_801E0C08_cpp_ref = (void *)__sinit_text_801E0C08_cpp;
