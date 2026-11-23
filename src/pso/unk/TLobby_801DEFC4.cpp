#include "types.h"
#include "pso/network/TProtocol_801E08CC.h"
#include "pso/network/TProtocol.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/item/TItemData.h"
#include "pso/network/protocol/protocol.h"


void TTradeList::bswap() {
    header.bswap();
    bswap_16(&target_client_id);
    bswap_16(&item_count);
    for (int i = 0; i < 32; i++) {
        items[i].bswap();
    }
}
template <> void TPlyText<172>::bswap() { header.bswap(); }
void TRecvInfoBoard::bswap() { header.bswap(); }
template <> void TPlyText<512>::bswap() { header.bswap(); }
void TBlockedSenders::bswap() {
    header.bswap();
    for (int i = 0; i < 30; ++i) {
        bswap_32(&blocked_senders[i]);
    }
}
void TRecvChallengeData::bswap() {
    header.bswap();
    for (int i = 0; i < 12; i++) {
        records[i].bswap();
    }
}
void TPlyChallenge::bswap() {
    bswap_32(&client_id);
    ((TLobby *)&challenge)->bswap_challenge_battle_records();
    bswap_16(&battle_place_count_1);
    bswap_16(&battle_place_count_2);
    bswap_16(&battle_place_count_3);
    bswap_16(&battle_place_count_4);
    bswap_16(&battle_disconnect_count);
    bswap_16(&pad_10E);
    bswap_16(&pad_110);
    bswap_16(&pad_112);
    bswap_32(&pad_114);
    bswap_32(&pad_118);
}
void TSendLogin::bswap() {
    header.bswap();
    tag.bswap();
    bswap_ply_smth_pair(&hardware_id);
    bswap_32(&sub_version);
    extension.bswap();
}

