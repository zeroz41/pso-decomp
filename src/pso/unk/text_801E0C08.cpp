#include "types.h"
#include "pso/unk/text_801E0C08.h"

struct RecoveredGlobal_801E0C08_meet_user_settings {
    s32 value;
    u8 remaining[0x60];
};

extern "C" {
s32 construct_guild_card_tag_array(s32);
extern RecoveredGlobal_801E0C08_meet_user_settings meet_user_settings;
typedef char RecoveredGlobal_801E0C08_meet_user_settings_size[sizeof(RecoveredGlobal_801E0C08_meet_user_settings) == 0x64 ? 1 : -1];
void __sinit_text_801E0C08_cpp(void) {
    construct_guild_card_tag_array((s32) &meet_user_settings.value);
}

}

__declspec(section ".ctors") static void *const __sinit_text_801E0C08_cpp_ref = (void *)__sinit_text_801E0C08_cpp;
