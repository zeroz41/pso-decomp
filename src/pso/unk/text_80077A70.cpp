#include "types.h"
#include "pso/unk/text_80077A70.h"

extern "C" {

s32 construct_guild_card_tag_array(s32);

s32 fn_80077A70(s32 arg0) {
    construct_guild_card_tag_array(arg0 + 0x70);
    return arg0;
}

}
