#include "types.h"
#include "pso/network/protocol/packet_classes.h"
#include "pso/network/TProtocol.h"
#include "pso/network/TTcpSocket.h"
#include "pso/player/TPlyGuildCardTag_8013ABCC.h"
#include "pso/system/GbaAramCache.h"
#include "pso/system/THeap.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/unk/TLobby_8013A874.h"

// These packet classes were built by an older compiler than TProtocol.cpp. Their copy
// constructors are the implicit ones, but the game links them as strong definitions from
// this object, ahead of TProtocol's weak copies. The copies of classes whose members are
// arrays of classes are defined and called by their linker names: a written copy
// constructor would default-construct those array members first.
extern "C" {
QuestListEntry *__ct__14QuestListEntryFRC14QuestListEntry(QuestListEntry *dst, const QuestListEntry *src);
LobbyListEntry *__ct__14LobbyListEntryFRC14LobbyListEntry(LobbyListEntry *dst, const LobbyListEntry *src);
GameListEntry *__ct__13GameListEntryFRC13GameListEntry(GameListEntry *dst, const GameListEntry *src);
TPlyJoinLobbyData *__ct__17TPlyJoinLobbyDataFRC17TPlyJoinLobbyData(TPlyJoinLobbyData *dst, const TPlyJoinLobbyData *src);
}

void TRegister::bswap() {
    header.bswap();
    smth.bswap();
    bswap_32(&sub_version);
}

TRegister::TRegister() {}

template <> void TPlyText<288>::bswap() {
    header.bswap();
}

// The menu list copies are strong here too, so the lists are specialized with byte storage
// for their entries: typed entry arrays would be default-constructed by the copy constructor.
template <> class TMenuList<QuestListEntry, 30, 0> {
public:
    TMenuList(const TMenuList &other);
    void bswap();

    packet_header header;
    u8 entries[30][sizeof(QuestListEntry)];
};

void TMenuList<QuestListEntry, 30, 0>::bswap() {
    header.bswap();
    for (int i = 0; i < 30; i++) {
        ((QuestListEntry *)entries[i])->bswap();
    }
}

void QuestListEntry::bswap() {
    tag.bswap();
}

TMenuList<QuestListEntry, 30, 0>::TMenuList(const TMenuList &other) : header(other.header) {
    QuestListEntry *end;
    QuestListEntry *dst;
    const QuestListEntry *src;
    dst = (QuestListEntry *)entries;
    src = (const QuestListEntry *)other.entries;
    end = (QuestListEntry *)entries[30];
    do {
        __ct__14QuestListEntryFRC14QuestListEntry(dst, src);
        dst++;
        src++;
    } while (dst < end);
}

QuestListEntry::QuestListEntry(const QuestListEntry &other) : tag(other.tag) {
    __memcpy(name, other.name, sizeof(name));
    __memcpy(short_description, other.short_description, sizeof(short_description));
}

void TUserAns::bswap() {
    header.bswap();
    tag.bswap();
    bswap_32(&found_guildcard);
    recv_port.bswap();
    extension.bswap();
}

void TRecvPort::bswap() {
    header.bswap();
    bswap_32(&ip_addr);
    bswap_16((u16 *)&port);
}

extern "C" TUserAns *__ct__8TUserAnsFRC8TUserAns(TUserAns *dst, TUserAns *src) {
    __memcpy(&dst->header, &src->header, sizeof(dst->header));
    __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&dst->tag, &src->tag);
    dst->found_guildcard = src->found_guildcard;
    __memcpy(&dst->recv_port, &src->recv_port, sizeof(dst->recv_port));
    __memcpy(dst->location, src->location, sizeof(dst->location));
    copy_ply_meet_user_extension(&dst->extension, &src->extension);
    return dst;
}

template <> class TMenuList<LobbyListEntry, 16, 0> {
public:
    TMenuList(const TMenuList &other);
    void bswap();

    packet_header header;
    u8 entries[16][sizeof(LobbyListEntry)];
};

void TMenuList<LobbyListEntry, 16, 0>::bswap() {
    header.bswap();
    for (int i = 0; i < 16; i++) {
        ((LobbyListEntry *)entries[i])->bswap();
    }
}

void LobbyListEntry::bswap() {
    tag.bswap();
    bswap_32(&smth);
}

TMenuList<LobbyListEntry, 16, 0>::TMenuList(const TMenuList &other) : header(other.header) {
    LobbyListEntry *end;
    LobbyListEntry *dst;
    const LobbyListEntry *src;
    dst = (LobbyListEntry *)entries;
    src = (const LobbyListEntry *)other.entries;
    end = (LobbyListEntry *)entries[16];
    do {
        __ct__14LobbyListEntryFRC14LobbyListEntry(dst, src);
        dst++;
        src++;
    } while (dst < end);
}

LobbyListEntry::LobbyListEntry(const LobbyListEntry &other) : tag(other.tag), smth(other.smth) {}

void TRecvDownload::bswap() {
    header.bswap();
    bswap_32(&data_size);
}

void TRecvDownloadHead::bswap() {
    header.bswap();
    bswap_32(&file_size);
}

void TPlyJoinGame::bswap() {
    header.bswap();
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 2; j++) {
            bswap_32(&variations[i][j]);
        }
    }
    bswap_32(&rare_seed);
}

extern "C" TPlyJoinGame *__ct__12TPlyJoinGameFRC12TPlyJoinGame(TPlyJoinGame *dst, const TPlyJoinGame *src) {
    __memcpy(&dst->header, &src->header, sizeof(dst->header));
    __memcpy(dst->variations, src->variations, sizeof(dst->variations));
    __ct__17TPlyJoinLobbyDataFRC17TPlyJoinLobbyData(&dst->lobby_data[0], &src->lobby_data[0]);
    __ct__17TPlyJoinLobbyDataFRC17TPlyJoinLobbyData(&dst->lobby_data[1], &src->lobby_data[1]);
    __ct__17TPlyJoinLobbyDataFRC17TPlyJoinLobbyData(&dst->lobby_data[2], &src->lobby_data[2]);
    __ct__17TPlyJoinLobbyDataFRC17TPlyJoinLobbyData(&dst->lobby_data[3], &src->lobby_data[3]);
    dst->client_id = src->client_id;
    dst->leader_id = src->leader_id;
    dst->disable_udp = src->disable_udp;
    dst->difficulty = src->difficulty;
    dst->battle_mode = src->battle_mode;
    dst->event = src->event;
    dst->section_id = src->section_id;
    dst->challenge_mode = src->challenge_mode;
    dst->rare_seed = src->rare_seed;
    dst->episode = src->episode;
    dst->unused1 = src->unused1;
    dst->solo_mode = src->solo_mode;
    dst->unused2 = src->unused2;
    return dst;
}

TPlyJoinLobbyData::TPlyJoinLobbyData(const TPlyJoinLobbyData &other)
    : tag(other.tag), ip_addr(other.ip_addr), client_id(other.client_id) {
    __memcpy(name, other.name, sizeof(name));
}

void TPlyStartGame::bswap() {
    header.bswap();
    for (int i = 0; i < 4; i++) {
        lobby_data[i].bswap();
    }
    extension.bswap();
}

void TPlyJoinLobbyData::bswap() {
    tag.bswap();
    bswap_32(&ip_addr);
    bswap_32(&client_id);
}

extern "C" TPlyStartGame *__ct__13TPlyStartGameFRC13TPlyStartGame(TPlyStartGame *dst, TPlyStartGame *src) {
    __memcpy(&dst->header, &src->header, sizeof(dst->header));
    __ct__17TPlyJoinLobbyDataFRC17TPlyJoinLobbyData(&dst->lobby_data[0], &src->lobby_data[0]);
    __ct__17TPlyJoinLobbyDataFRC17TPlyJoinLobbyData(&dst->lobby_data[1], &src->lobby_data[1]);
    __ct__17TPlyJoinLobbyDataFRC17TPlyJoinLobbyData(&dst->lobby_data[2], &src->lobby_data[2]);
    __ct__17TPlyJoinLobbyDataFRC17TPlyJoinLobbyData(&dst->lobby_data[3], &src->lobby_data[3]);
    copy_ply_meet_user_extension(&dst->extension, &src->extension);
    dst->unused[0] = src->unused[0];
    dst->unused[1] = src->unused[1];
    dst->unused[2] = src->unused[2];
    dst->unused[3] = src->unused[3];
    return dst;
}

template <> class TMenuList<GameListEntry, 64, 1> {
public:
    TMenuList(const TMenuList &other);
    void bswap();

    packet_header header;
    u8 pad_entries[1][sizeof(GameListEntry)];
    u8 entries[64][sizeof(GameListEntry)];
};

void TMenuList<GameListEntry, 64, 1>::bswap() {
    header.bswap();
    ((GameListEntry *)pad_entries[0])->bswap();
    for (int i = 0; i < 64; i++) {
        ((GameListEntry *)entries[i])->bswap();
    }
}

void GameListEntry::bswap() {
    tag.bswap();
}

TMenuList<GameListEntry, 64, 1>::TMenuList(const TMenuList &other) : header(other.header) {
    GameListEntry *dst;
    const GameListEntry *src;
    __ct__13GameListEntryFRC13GameListEntry((GameListEntry *)pad_entries[0], (const GameListEntry *)other.pad_entries[0]);
    dst = (GameListEntry *)entries;
    src = (const GameListEntry *)other.entries;
    do {
        __ct__13GameListEntryFRC13GameListEntry(dst, src);
        dst++;
        src++;
    } while (dst < (GameListEntry *)entries[64]);
}

GameListEntry::GameListEntry(const GameListEntry &other) : tag(other.tag) {
    difficulty_tag = other.difficulty_tag;
    num_players = other.num_players;
    __memcpy(name, other.name, sizeof(name));
    episode = other.episode;
    flags = other.flags;
}

void TPlyRecvLogin::bswap() {
    header.bswap();
    tag.bswap();
}

TPlyRecvLogin::TPlyRecvLogin(const TPlyRecvLogin &other)
    : TPlyGuildCardTagPacket(other), client_config(other.client_config) {}

TPlyGuildCardTagPacket::TPlyGuildCardTagPacket(const TPlyGuildCardTagPacket &other)
    : header(other.header), tag(other.tag) {}

void TProtocol::operator delete(void *ptr) {
    obj_heap->heap_free(ptr);
}

void set_lobby_count_value() {
    lobby_count_value = 1;
}

void TPlySmth::bswap() {
    bswap_32((u32 *)m_smth);
    bswap_32((u32 *)m_smth1);
}

TPlySmth &TPlySmth::operator=(const TPlySmth &other) {
    __memcpy(this, &other, sizeof(TPlySmth));
    return *this;
}

TSendLogin::TSendLogin() {}

TPlySmth::TPlySmth() {}

TCreateGame::TCreateGame() {}

extern "C" u8 __eq__16TPlyGuildCardTagFR16TPlyGuildCardTag(TPlyGuildCardTag *tag, TPlyGuildCardTag *other) {
    return tag->m_tag1 == other->m_tag1 && tag->m_tag2 == other->m_tag2 &&
           tag->m_guildcard_number == other->m_guildcard_number;
}

void TPlyCharData::bswap() {
    for (int i = 0; i < 30; i++) {
        m_inventory.m_items[i].bswap();
    }
    bswap__15disp_data_part2Fv((saddr)&m_disp_part2);
    m_stats.bswap();
    m_config.bswap();
}

void TPlyDispConfig::bswap() {
    m_smth.bswap();
    m_smth1.bswap();
}

extern "C" TPlyJoinLobby *__ct__13TPlyJoinLobbyFRC13TPlyJoinLobby(TPlyJoinLobby *dst, const TPlyJoinLobby *src) {
    TPlyJoinLobbyEntry *d = dst->entries;
    const TPlyJoinLobbyEntry *s = src->entries;
    __memcpy(&dst->header, &src->header, sizeof(dst->header));
    dst->client_id = src->client_id;
    dst->leader_id = src->leader_id;
    dst->disable_udp = src->disable_udp;
    dst->lobby_number = src->lobby_number;
    dst->block_number = src->block_number;
    dst->enable_battle_mode = src->enable_battle_mode;
    dst->event = src->event;
    dst->enable_voice_chat = src->enable_voice_chat;
    dst->unused[0] = src->unused[0];
    dst->unused[1] = src->unused[1];
    dst->unused[2] = src->unused[2];
    dst->unused[3] = src->unused[3];
    do {
        copy_join_lobby_entry((u8 *)d, (u8 *)s);
        d++;
        s++;
    } while (d < dst->entries + 12);
    return dst;
}

TPlyJoinLobby::~TPlyJoinLobby() {}

TTcpSocket::TTcpSocket(TObject *parent) : TSocket(parent) {
    m_name = TTcpSocket_name;
}

TPlyMeetUserExtension meet_user_settings;
u32 game_variations[16][2];
