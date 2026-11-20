#ifndef PSO_NETWORK_NETWORK_INFO_CODEC_H
#define PSO_NETWORK_NETWORK_INFO_CODEC_H

#include "types.h"
#include "versions.h"
#include <stddef.h>

typedef struct NetworkInfoNamedConfig {
    char name[0x20];
    s16 v20, v22, v24, v26;
} NetworkInfoNamedConfig;

typedef struct NetworkInfoConnectionConfig {
    char s000[0x20];
    char s020[0x80];
    char s0A0[0x20];
    s32 v0C0;
    s32 v0C4;
    s32 v0C8;
    char s0CC[0x40];
    u16 v10C;
    s16 v10E;
    u8 v110;
    u8 v111;
#if VERSION == VERSION_GPOP8P
    u8 v112;
    u8 pad113;
#else
    u8 pad112[2];
#endif
    char s114[0x10];
    char s124[0x10];
    char s134[0x20];
    char s154[0x20];
    char s174[0x20];
    s16 v194;
    s16 v196;
    char s198[0x20];
    u8 v1B8;
    u8 v1B9;
    u8 pad1BA[2];
    s32 v1BC;
    s32 v1C0;
    s32 v1C4;
    char s1C8[0x40];
    s32 v208;
    s32 v20C;
} NetworkInfoConnectionConfig;

typedef struct NetworkInfoMailConfig {
    u8 v00;
    u8 v01;
    s16 v02;
    char s04[0x40];
    char s44[0x40];
    char s84[0x40];
    char sC4[0x20];
    char sE4[0x20];
    char s104[0x20];
} NetworkInfoMailConfig;

typedef struct NetworkInfoCredentialConfig {
    u8 v00;
    u8 pad01[3];
    char s04[0x20];
    char s24[0x20];
    char s44[0x20];
    char s64[0x20];
} NetworkInfoCredentialConfig;

typedef struct NetworkInfoConfigText400 {
    char s[0x190];
} NetworkInfoConfigText400;

typedef struct NetworkInfoConfigText256 {
    char s[0x100];
} NetworkInfoConfigText256;

typedef struct NetworkInfoConfig {
    u16 v0;
    s16 v2;
    s16 v4;
    s16 v6;
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
typedef char NetworkInfoCipherBlockExtent[sizeof(NetworkInfoCipherBlock) == 0x10 ? 1 : -1];
typedef char NetworkInfoCipherKeyExtent[sizeof(NetworkInfoCipherKey) == 0x44 ? 1 : -1];
typedef char NetworkInfoCipherWorkspaceExtent[sizeof(NetworkInfoCipherWorkspace) == 0x120 ? 1 : -1];
typedef char NetworkInfoCipherPoolBindingExtent[sizeof(NetworkInfoCipherPoolBinding) == 8 ? 1 : -1];

typedef char NetworkInfoNamedConfigExtent[sizeof(NetworkInfoNamedConfig) == 0x28 ? 1 : -1];
typedef char NetworkInfoConnectionConfigExtent[sizeof(NetworkInfoConnectionConfig) == 0x210 ? 1 : -1];
typedef char NetworkInfoMailConfigExtent[sizeof(NetworkInfoMailConfig) == 0x124 ? 1 : -1];
typedef char NetworkInfoCredentialConfigExtent[sizeof(NetworkInfoCredentialConfig) == 0x84 ? 1 : -1];
typedef char NetworkInfoConfigExtent[sizeof(NetworkInfoConfig) == 0x19D4 ? 1 : -1];
typedef char NetworkInfoConfigConnectionOffset[offsetof(NetworkInfoConfig, b) == 0xF8 ? 1 : -1];
typedef char NetworkInfoConfigMailOffset[offsetof(NetworkInfoConfig, c) == 0xD58 ? 1 : -1];
typedef char NetworkInfoConfigCredentialOffset[offsetof(NetworkInfoConfig, d) == 0x1430 ? 1 : -1];
typedef char NetworkInfoConfigText400Offset[offsetof(NetworkInfoConfig, e) == 0x14B4 ? 1 : -1];
typedef char NetworkInfoConfigText256Offset[offsetof(NetworkInfoConfig, f) == 0x17D4 ? 1 : -1];

s32 parse_netinfo(char *text, u32 size, NetworkInfoConfig *config);
s32 decode_network_info_payload(u8 *key, u8 *payload, u32 size, NetworkInfoConfig *config);

u32 *allocate_network_info_cipher_key(s32 src);
void bind_network_info_cipher_pool(u32 *p, s32 n);
void clear_network_info_cipher_pool(void);
void copy_network_info_cipher_block(u32 *dst, u32 *src);
s32 copy_network_info_config_string(char *arg0, char *arg1, u32 arg2, u32 arg3);
void decrypt_network_info_cipher_block(u32 *arg0, NetworkInfoCipherBlock *src, NetworkInfoCipherBlock *dst);
s32 decrypt_network_info_cipher_blocks(u32 *key, u8 *src, s32 len, u8 *dst);
void decrypt_network_info_cipher_round(u32 *arg0, u32 *arg1);
s32 parse_hex_string(char *s);
s32 parse_network_info_config_decimal(char *s, u32 n);
s32 parse_network_info_config_hex(char *s, u32 n);
void release_network_info_cipher_key(u32 *mask);

#endif
