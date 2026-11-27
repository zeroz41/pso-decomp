#ifndef PSO_PLAYER_TPLYDISPDATA_H
#define PSO_PLAYER_TPLYDISPDATA_H

#include "types.h"
#include "pso/macros.h"
#include "pso/network/protocol/protocol.h"
#include "pso/math/TMath.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/player/PlayerStats.h"
#include "pso/player/TPlyDispConfig.h"

#define bswap16(var) bswap_16(as(u16 *, var))
#define bswap32(var) bswap_32(as(u32 *, var))

#define bswap16_ref(var) bswap16(&var)
#define bswap32_ref(var) bswap32(&var)

struct disp_data_part2 {
    void bswap();
    void clear();
    bool is_valid() {
        return false;
    };

    char name[16];
    u8 smth[8];
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
