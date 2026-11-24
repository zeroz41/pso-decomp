#include "types.h"
#include "pso/player/TPlyGuildCardTag.h"

TPlyGuildCardTag::TPlyGuildCardTag(u16 tag2, u32 guildcard_number) {
    m_tag0 = 0;
    m_tag1 = 0;
    m_tag2 = tag2;
    m_guildcard_number = guildcard_number;
}
