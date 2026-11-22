#include "pso/system/memory.h"
#include "types.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowGetComCard_8007B54C.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/ui/window/TWindowGetComCard.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"

GuildCardEntry TWindowGetComCard__received_guild_card_tags[4];

extern "C" {
void TWindowSubComCard__sub_8007B26C(GuildCardEntry *entry);
void __construct_array(void *ptr, void *ctor, void *dtor, u32 size, u32 n);

void TWindowGetComCard__sub_8007B54C(void) {
    TWindowGetComCard::remove_entry(0, TWindowGetComCard__received_guild_card_tags, 4);
    if (TWindowGetComCard__received_guild_card_tags[0].is_active() == 0) {
        TWindowCtrl__sub_8024A08C();
    }
}

GuildCardEntry *TWindowGetComCard__sub_8007B594(void) {
    return TWindowGetComCard__received_guild_card_tags;
}

void TWindowGetComCard::remove_entry(s32 index, GuildCardEntry *entries, s32 count) {
    if (index < count - 1) {
        GuildCardEntry *entry = &entries[index];
        move_words(entry, entry + 1, (u32)((count - index - 1) * sizeof(GuildCardEntry)) >> 2);
    }
    entries += count - 1;
    TWindowSubComCard__sub_8007B26C(entries);
}

void TWindowGetComCard__sub_8007B60C(s32 _w0) {
    TWindowCtrl__sub_8024A08C();
    for (s32 i = 0; i < 4; i++) {
        TWindowSubComCard__sub_8007B26C(&TWindowGetComCard__received_guild_card_tags[i]);
    }
}

void TWindowGetComCard__sub_8007B65C(void* p) { TWindowGetComCard__sub_8007B60C((saddr)p); }
void TWindowGetComCard__sub_8007B67C(void* p) { TWindowGetComCard__sub_8007B60C((saddr)p); }
void TWindowGetComCard::construct_card_tags() {
    __construct_array(TWindowGetComCard__received_guild_card_tags, (void *)init_guild_card_tag__17TWindowSubComCardFi, 0, sizeof(GuildCardEntry), 4);
}

}

__declspec(section ".ctors") static void *const __sinit_TWindowGetComCard_8007B54C_cpp_ref = (void *)TWindowGetComCard::construct_card_tags;
