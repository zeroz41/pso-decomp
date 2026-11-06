#ifndef PSO_PLAYER_TPLYDISPDATA_H
#define PSO_PLAYER_TPLYDISPDATA_H

#include "types.h"
#include "pso/macros.h"
#include "pso/network/protocol/protocol.h"
#include "pso/math/TMath.h"
#include "pso/player/TPlyGuildCardTag.h"

#define bswap16(var) bswap_16(as(u16 *, var))
#define bswap32(var) bswap_32(as(u32 *, var))

#define bswap16_ref(var) bswap16(&var)
#define bswap32_ref(var) bswap32(&var)

struct stats {
    void bswap();

    short atp;
    short mst;
    short evp;
    short hp;
    short dfp;
    short ata;
    short lck;
};

struct player_stats {
    void bswap() {
        bswap16(&stats.atp);
        bswap16(&stats.mst);
        bswap16(&stats.evp);
        bswap16(&stats.hp);
        bswap16(&stats.dfp);
        bswap16(&stats.ata);
        bswap16(&stats.lck);
        bswap16(&mbr_0xe);
        bswap32(&proportions);
        bswap32(&mbr_0x14);
        bswap32(&level);
        bswap32(&exp);
        bswap32(&meseta);
    };

    struct stats stats;
    short mbr_0xe;
    float proportions;
    float mbr_0x14;
    int level;
    int exp;
    int meseta;
};

struct disp_data_part2 {
    void bswap() {
        bswap_32(&name_colour);
        bswap_32(&name_colour_checksum);
        bswap_32(&v1_flags);
        for (int i = 0; i < 8; ++i) {
            bswap_16(&appearance_data[i]);
        }
        bswap32(&proportions.x);
        bswap32(&proportions.y);
    };
    bool is_valid() {
        return false;
    };

    char name[16];
    u32 smth[2];
    u32 name_colour;
    u8 extra_model;
    u8 padding[15];
    u32 name_colour_checksum;
    u8 section_id;
    u8 char_class;
    u8 v2_flags;
    u8 version;
    u32 v1_flags;
    union {
        struct {
            u16 costume;
            u16 skin;
            u16 face;
            u16 head;
            u16 hair;
            u16 hair_r;
            u16 hair_g;
            u16 hair_b;
        } appearance;
        u16 appearance_data[8];
    };
    vec2f proportions;
};

class TPlyDispConfigSmth {
public:
    TPlyDispConfigSmth() { m_mbr_0x0 = 0; };
    void bswap() {
        bswap_32(&m_mbr_0x0);
        for (int i = 0; i < 4; ++i) {
            m_tags[i].bswap();
            m_tags1[i].bswap();
        }
    };
public:
    u32 m_mbr_0x0;
    gc_tag m_tags[4];
    gc_tag m_tags1[4];
};

class TPlyDispConfig {
public:
    void bswap() {
        m_smth.bswap();
        m_smth1.bswap();
    };
public:
    TPlyDispConfigSmth m_smth;
    TPlyDispConfigSmth m_smth1;
public:
    void bswap_pair();
    static s32 free_if_valid(s32 arg0, s16 arg1);
};

class TPlyDispData {
public:
    void bswap();
public:
    player_stats m_stats;
    disp_data_part2 m_disp_part2;
    TPlyDispConfig m_config;
    u8 m_tech_levels[20];
};

#endif
