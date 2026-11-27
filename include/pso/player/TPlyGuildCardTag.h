#ifndef PSO_PLAYER_TPLYGUILDCARDTAG_H
#define PSO_PLAYER_TPLYGUILDCARDTAG_H

#include "pso/forward.h"
#include "pso/network/protocol/protocol.h"
#include "types.h"

/* TPlyGuildCardTag - Guild card identification tag.
 * Derived from pso-gc-reference decomp (mrb0nk500).
 *
 * Used throughout the protocol to identify players.
 * Contains a tag triplet + guild card number.
 */

class TObjPlayer;

struct gc_tag {
    gc_tag() { init(); };
    ~gc_tag() {};
    void init() {
        tag0 = 0;
        tag1 = 0;
        tag2 = 0;
    };
    void bswap() {
        bswap_16(&tag2);
    };
    // Out-of-line copy for the action palette tags (TPlyDispConfigSmth rows).
    void bswap_disp_config_field();
    // As an action palette tag: whether player can use the action of kind tag0, index tag1.
    s32 can_use_palette_action_for_entry(TObjPlayer *player);

    s8 tag0;
    u8 tag1;
    u16 tag2;
};

class TPlyGuildCardTag {
public:
    TPlyGuildCardTag();

    TPlyGuildCardTag(u16 tag2, u32 guildcard_number);

    int operator==(TPlyGuildCardTag &other) {
        return (m_tag1 == other.m_tag1) &&
               (m_tag2 == other.m_tag2) &&
               (m_guildcard_number == other.m_guildcard_number);
    };

    void bswap();

public:
    u8 m_tag0;
    u8 m_tag1;
    u16 m_tag2;
    u32 m_guildcard_number;
public:
    static void bswap_lobby_entry(void *entry);
};

#endif
