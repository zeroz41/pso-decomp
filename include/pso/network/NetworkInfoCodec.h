#ifndef PSO_NETWORK_NETWORK_INFO_CODEC_H
#define PSO_NETWORK_NETWORK_INFO_CODEC_H

#include "types.h"
#include <stddef.h>

// Fields are named after their GAMECUBE_NETINFO keys (NAM0=, PN_0=, SA_0=, ...).
typedef struct NetworkInfoNamedConfig {
    char name[0x20];
    s16 pan, man, sgn, urn;
} NetworkInfoNamedConfig;

typedef struct NetworkInfoConnectionConfig {
    char pn[0x20];
    char li[0x80];
    char lp[0x20];
    s32 d1;
    s32 d2;
    s32 it;
    char pxs[0x40];
    u16 pxp;
    s16 at;
    u8 dt;
    u8 pa;
    u8 pad112[2];
    char ol[0x10];
    char od[0x10];
    char t1[0x20];
    char t2[0x20];
    char t3[0x20];
    s16 rc;
    s16 ri;
    char mi[0x20];
    u8 dy;
    u8 py;
    u8 pad1BA[2];
    s32 ip;
    s32 snm;
    s32 g1;
    char hn[0x40];
    s32 mt;
    s32 mr;
} NetworkInfoConnectionConfig;

typedef struct NetworkInfoMailConfig {
    u8 sa;
    u8 sd;
    s16 iv;
    char ma[0x40];
    char ms[0x40];
    char ps[0x40];
    char pi[0x20];
    char pp[0x20];
    char mn[0x20];
} NetworkInfoMailConfig;

typedef struct NetworkInfoCredentialConfig {
    u8 nm;
    u8 pad01[3];
    char cni[0x20];
    char cnp[0x20];
    char cmi[0x20];
    char cmp[0x20];
} NetworkInfoCredentialConfig;

typedef struct NetworkInfoConfigText400 {
    char s[0x190];
} NetworkInfoConfigText400;

typedef struct NetworkInfoConfigText256 {
    char s[0x100];
} NetworkInfoConfigText256;

typedef struct NetworkInfoConfig {
    u16 iver;
    s16 cnum;
    s16 mnum;
    s16 bnum;
    NetworkInfoNamedConfig a[6];
    NetworkInfoConnectionConfig b[6];
    NetworkInfoMailConfig c[6];
    NetworkInfoCredentialConfig d[1];
    NetworkInfoConfigText400 e[2];
    NetworkInfoConfigText256 f[2];
} NetworkInfoConfig;

struct NetworkInfoCipherBlock { u8 b[0x10]; };

struct NetworkInfoCipherKey { u32 bit; u32 keys[4][4]; };

struct NetworkInfoCipherPoolView { u32 mask; NetworkInfoCipherKey slots[16]; };

struct NetworkInfoCipherWorkspace {
    u32 capacity_and_used_mask;
    NetworkInfoCipherKey first_key;
    u8 field_48[0xD8];
};
struct NetworkInfoCipherPoolBinding {
    u32 *pool;
    u32 field_04;
};
LAYOUT_ASSERT(NetworkInfoCipherBlockExtent, sizeof(NetworkInfoCipherBlock) == 0x10);
LAYOUT_ASSERT(NetworkInfoCipherKeyExtent, sizeof(NetworkInfoCipherKey) == 0x44);
LAYOUT_ASSERT(NetworkInfoCipherWorkspaceExtent, sizeof(NetworkInfoCipherWorkspace) == 0x120);
LAYOUT_ASSERT(NetworkInfoCipherPoolBindingExtent, sizeof(NetworkInfoCipherPoolBinding) == 8);

LAYOUT_ASSERT(NetworkInfoNamedConfigExtent, sizeof(NetworkInfoNamedConfig) == 0x28);
LAYOUT_ASSERT(NetworkInfoConnectionConfigExtent, sizeof(NetworkInfoConnectionConfig) == 0x210);
LAYOUT_ASSERT(NetworkInfoMailConfigExtent, sizeof(NetworkInfoMailConfig) == 0x124);
LAYOUT_ASSERT(NetworkInfoCredentialConfigExtent, sizeof(NetworkInfoCredentialConfig) == 0x84);
LAYOUT_ASSERT(NetworkInfoConfigExtent, sizeof(NetworkInfoConfig) == 0x19D4);
LAYOUT_ASSERT(NetworkInfoConfigConnectionOffset, offsetof(NetworkInfoConfig, b) == 0xF8);
LAYOUT_ASSERT(NetworkInfoConfigMailOffset, offsetof(NetworkInfoConfig, c) == 0xD58);
LAYOUT_ASSERT(NetworkInfoConfigCredentialOffset, offsetof(NetworkInfoConfig, d) == 0x1430);
LAYOUT_ASSERT(NetworkInfoConfigText400Offset, offsetof(NetworkInfoConfig, e) == 0x14B4);
LAYOUT_ASSERT(NetworkInfoConfigText256Offset, offsetof(NetworkInfoConfig, f) == 0x17D4);

s32 parse_netinfo(char *text, u32 size, NetworkInfoConfig *config);
s32 parse_network_info_config_line(char *s, u32 n, NetworkInfoConfig *q);
s32 decode_network_info_payload(u8 *key_data, u8 *payload, u32 size, NetworkInfoConfig *config);

u32 *allocate_network_info_cipher_key(u8 *key_data);
void bind_network_info_cipher_pool(u32 *p, s32 n);
void clear_network_info_cipher_pool(void);
void copy_network_info_cipher_block(u32 *dst, u32 *src);
s32 copy_network_info_config_string(char *dest, char *line, u32 num, u32 size);
void decrypt_network_info_cipher_block(u32 *key, NetworkInfoCipherBlock *src, NetworkInfoCipherBlock *dst);
s32 decrypt_network_info_cipher_blocks(u32 *key, u8 *src, s32 len, u8 *dst);
void decrypt_network_info_cipher_round(u32 *key, u32 *block);
s32 parse_hex_string(char *s);
s32 parse_network_info_config_decimal(char *s, u32 n);
s32 parse_network_info_config_hex(char *s, u32 n);
void release_network_info_cipher_key(u32 *mask);

#endif
