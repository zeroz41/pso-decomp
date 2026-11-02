#include "pso/network/NetworkInfoCodec.h"
extern "C" {
u32 strlen(const char *);
int strncmp(const char *, const char *, unsigned long);
char *strncpy(char *, const char *, unsigned long);
int atoi(const char *);
}
s32 parse_netinfo(char *, u32, NetworkInfoConfig *);
extern char network_info_unparsed_config_lines[0x400];
extern char network_info_config_key_iver[5];
extern char network_info_config_key_cnum[5];
extern char network_info_config_key_mnum[5];
extern char network_info_config_key_bnum[5];
extern char network_info_config_key_nam[4];
extern char network_info_config_key_pan[4];
extern char network_info_config_key_man[4];
extern char network_info_config_key_sgn[4];
extern char network_info_config_key_urn[4];
extern char network_info_config_key_pn[4];
extern char network_info_config_key_li[4];
extern char network_info_config_key_lp[4];
extern char network_info_config_key_d1[4];
extern char network_info_config_key_d2[4];
extern char network_info_config_key_it[4];
extern char network_info_config_key_pxs[4];
extern char network_info_config_key_pxp[4];
extern char network_info_config_key_at[4];
extern char network_info_config_key_dt[4];
extern char network_info_config_key_pa[4];
extern char network_info_config_key_ol[4];
extern char network_info_config_key_od[4];
extern char network_info_config_key_t1[4];
extern char network_info_config_key_t2[4];
extern char network_info_config_key_t3[4];
extern char network_info_config_key_rc[4];
extern char network_info_config_key_ri[4];
extern char network_info_config_key_mi[4];
extern char network_info_config_key_dy[4];
extern char network_info_config_key_py[4];
extern char network_info_config_key_ip[4];
extern char network_info_config_key_snm[4];
extern char network_info_config_key_g1[4];
extern char network_info_config_key_hn[4];
extern char network_info_config_key_mt[4];
extern char network_info_config_key_mr[4];
extern char network_info_config_key_sa[4];
extern char network_info_config_key_sd[4];
extern char network_info_config_key_iv[4];
extern char network_info_config_key_ma[4];
extern char network_info_config_key_ms[4];
extern char network_info_config_key_ps[4];
extern char network_info_config_key_pi[4];
extern char network_info_config_key_pp[4];
extern char network_info_config_key_mn[4];
extern char network_info_config_key_nm[4];
extern char network_info_config_key_cni[4];
extern char network_info_config_key_cnp[4];
extern char network_info_config_key_cmi[4];
extern char network_info_config_key_cmp[4];
extern char network_info_config_key_sg[4];
extern char network_info_config_key_url[4];
extern s32 network_info_config_field_handled;
extern u32 network_info_unparsed_config_length;
s32 parse_network_info_config_line(char *s, u32 n, NetworkInfoConfig *q);
#pragma push
#pragma use_lmw_stmw off
#pragma optimization_level 2
#pragma scheduling off
#pragma peephole off
s32 parse_netinfo(char *buf, u32 len, NetworkInfoConfig *arg2) {
    u32 i;
    u32 start;
    start = 0;
    network_info_unparsed_config_length = 0;
    if (strncmp(buf, "GAMECUBE_NETINFO\x0D\x0A", strlen("GAMECUBE_NETINFO\x0D\x0A")) != 0) {
        return -1;
    }
    for (i = 4; i < len; i++) {
        if (buf[i] == '\r') {
            if (buf[i + 1] == '\n') {
                parse_network_info_config_line(buf + start, i - start, arg2);
                start = i + 2;
            }
        }
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
#define GET(f) parse_network_info_config_decimal(s, n)
#define GETL() parse_network_info_config_hex(s, n)
#define CPY(dst, len) copy_network_info_config_string(dst, s, n, len)
s32 parse_network_info_config_line(char *s, u32 n, NetworkInfoConfig *q) {
    char buf[8];
    s32 i;
    network_info_config_field_handled = 0;
    if (n < 4) {
        return 0;
    }
    if (s[4] != '=') {
        return 0;
    }
    strncpy(buf, s, 4);
    buf[4] = 0;
    i = atoi(&buf[3]);
    if (strncmp(s, network_info_config_key_iver, 4) == 0) {
        q->v0 = parse_network_info_config_decimal((char *)(s), n);
    } else if (strncmp(s, network_info_config_key_cnum, 4) == 0) {
        q->v2 = parse_network_info_config_decimal((char *)(s), n);
    } else if (strncmp(s, network_info_config_key_mnum, 4) == 0) {
        q->v4 = parse_network_info_config_decimal((char *)(s), n);
    } else if (strncmp(s, network_info_config_key_bnum, 4) == 0) {
        q->v6 = parse_network_info_config_decimal((char *)(s), n);
    }
    if (network_info_config_field_handled == 0 && i < 6) {
        if (strncmp(s, network_info_config_key_nam, 3) == 0) {
            CPY(q->a[i].name, 0x20);
        } else if (strncmp(s, network_info_config_key_pan, 3) == 0) {
            q->a[i].v20 = GET();
        } else if (strncmp(s, network_info_config_key_man, 3) == 0) {
            q->a[i].v22 = GET();
        } else if (strncmp(s, network_info_config_key_sgn, 3) == 0) {
            q->a[i].v24 = GET();
        } else if (strncmp(s, network_info_config_key_urn, 3) == 0) {
            q->a[i].v26 = GET();
        }
    }
    if (network_info_config_field_handled == 0 && i < 6) {
        if (strncmp(s, network_info_config_key_pn, 3) == 0) {
            CPY(q->b[i].s000, 0x20);
        } else if (strncmp(s, network_info_config_key_li, 3) == 0) {
            CPY(q->b[i].s020, 0x80);
        } else if (strncmp(s, network_info_config_key_lp, 3) == 0) {
            CPY(q->b[i].s0A0, 0x20);
        } else if (strncmp(s, network_info_config_key_d1, 3) == 0) {
            q->b[i].v0C0 = GETL();
        } else if (strncmp(s, network_info_config_key_d2, 3) == 0) {
            q->b[i].v0C4 = GETL();
        } else if (strncmp(s, network_info_config_key_it, 3) == 0) {
            q->b[i].v0C8 = GET();
        } else if (strncmp(s, network_info_config_key_pxs, 3) == 0) {
            CPY(q->b[i].s0CC, 0x40);
        } else if (strncmp(s, network_info_config_key_pxp, 3) == 0) {
            q->b[i].v10C = GETL();
        } else if (strncmp(s, network_info_config_key_at, 3) == 0) {
            q->b[i].v10E = GET();
        } else if (strncmp(s, network_info_config_key_dt, 3) == 0) {
            q->b[i].v110 = GET();
        } else if (strncmp(s, network_info_config_key_pa, 3) == 0) {
            q->b[i].v111 = GET();
        } else if (strncmp(s, network_info_config_key_ol, 3) == 0) {
            CPY(q->b[i].s114, 0x10);
        } else if (strncmp(s, network_info_config_key_od, 3) == 0) {
            CPY(q->b[i].s124, 0x10);
        } else if (strncmp(s, network_info_config_key_t1, 3) == 0) {
            CPY(q->b[i].s134, 0x20);
        } else if (strncmp(s, network_info_config_key_t2, 3) == 0) {
            CPY(q->b[i].s154, 0x20);
        } else if (strncmp(s, network_info_config_key_t3, 3) == 0) {
            CPY(q->b[i].s174, 0x20);
        } else if (strncmp(s, network_info_config_key_rc, 3) == 0) {
            q->b[i].v194 = GET();
        } else if (strncmp(s, network_info_config_key_ri, 3) == 0) {
            q->b[i].v196 = GET();
        } else if (strncmp(s, network_info_config_key_mi, 3) == 0) {
            CPY(q->b[i].s198, 0x20);
        } else if (strncmp(s, network_info_config_key_dy, 3) == 0) {
            q->b[i].v1B8 = GET();
        } else if (strncmp(s, network_info_config_key_py, 3) == 0) {
            q->b[i].v1B9 = GET();
        } else if (strncmp(s, network_info_config_key_ip, 3) == 0) {
            q->b[i].v1BC = GETL();
        } else if (strncmp(s, network_info_config_key_snm, 3) == 0) {
            q->b[i].v1C0 = GETL();
        } else if (strncmp(s, network_info_config_key_g1, 3) == 0) {
            q->b[i].v1C4 = GETL();
        } else if (strncmp(s, network_info_config_key_hn, 3) == 0) {
            CPY(q->b[i].s1C8, 0x40);
        } else if (strncmp(s, network_info_config_key_mt, 3) == 0) {
            q->b[i].v208 = GET();
        } else if (strncmp(s, network_info_config_key_mr, 3) == 0) {
            q->b[i].v20C = GET();
        }
    }
    if (network_info_config_field_handled == 0 && i < 6) {
        if (strncmp(s, network_info_config_key_sa, 3) == 0) {
            q->c[i].v00 = GET();
        } else if (strncmp(s, network_info_config_key_sd, 3) == 0) {
            q->c[i].v01 = GET();
        } else if (strncmp(s, network_info_config_key_iv, 3) == 0) {
            q->c[i].v02 = GET();
        } else if (strncmp(s, network_info_config_key_ma, 3) == 0) {
            CPY(q->c[i].s04, 0x40);
        } else if (strncmp(s, network_info_config_key_ms, 3) == 0) {
            CPY(q->c[i].s44, 0x40);
        } else if (strncmp(s, network_info_config_key_ps, 3) == 0) {
            CPY(q->c[i].s84, 0x40);
        } else if (strncmp(s, network_info_config_key_pi, 3) == 0) {
            CPY(q->c[i].sC4, 0x20);
        } else if (strncmp(s, network_info_config_key_pp, 3) == 0) {
            CPY(q->c[i].sE4, 0x20);
        } else if (strncmp(s, network_info_config_key_mn, 3) == 0) {
            CPY(q->c[i].s104, 0x20);
        }
    }
    if (network_info_config_field_handled == 0 && i < 1) {
        if (strncmp(s, network_info_config_key_nm, 3) == 0) {
            q->d[i].v00 = GET();
        } else if (strncmp(s, network_info_config_key_cni, 3) == 0) {
            CPY(q->d[i].s04, 0x20);
        } else if (strncmp(s, network_info_config_key_cnp, 3) == 0) {
            CPY(q->d[i].s24, 0x20);
        } else if (strncmp(s, network_info_config_key_cmi, 3) == 0) {
            CPY(q->d[i].s44, 0x20);
        } else if (strncmp(s, network_info_config_key_cmp, 3) == 0) {
            CPY(q->d[i].s64, 0x20);
        }
    }
    if (network_info_config_field_handled == 0 && network_info_unparsed_config_length + n < 0x400) {
        if (strncmp(s, network_info_config_key_sg, 3) == 0) {
            CPY(q->e[i].s, 0x190);
        } else if (strncmp(s, network_info_config_key_url, 3) == 0) {
            CPY(q->f[i].s, 0x100);
        }
    }
    if (network_info_config_field_handled == 0 && network_info_unparsed_config_length + n < 0x400) {
        strncpy(network_info_unparsed_config_lines + network_info_unparsed_config_length, s, n + 2);
        network_info_unparsed_config_length += n + 2;
        network_info_unparsed_config_lines[network_info_unparsed_config_length] = 0;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 parse_network_info_config_decimal(char *s, u32 n) {
    char buf[0x20];
    s32 r;
    if (n > 0x20) {
        return 0;
    }
    strncpy(buf, s, n);
    buf[n] = 0;
    r = atoi(&buf[5]);
    network_info_config_field_handled = 1;
    return r;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 parse_network_info_config_hex(char *s, u32 n) {
    char buf[0x20];
    s32 r;
    if (n > 0x20) {
        return 0;
    }
    strncpy(buf, s, n);
    buf[n] = 0;
    r = parse_hex_string(&buf[5]);
    network_info_config_field_handled = 1;
    return r;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma scheduling off
#pragma peephole off
s32 copy_network_info_config_string(char *arg0, char *arg1, u32 arg2, u32 arg3) {
    if (arg2 <= 4) {
        *arg0 = 0;
    } else {
        arg2 -= 5;
        if (arg2 > arg3) {
            strncpy(arg0, arg1 + 5, arg3);
            char c = arg0[arg3 - 1];
            if ((u8)c >= 0x80) {
                arg0[arg3 - 1] = 0;
            }
        } else {
            strncpy(arg0, arg1 + 5, arg2);
        }
    }
    network_info_config_field_handled = 1;
    return 0;
}
#pragma pop

#include "types.h"

extern NetworkInfoCipherPoolBinding network_info_cipher_pool_binding;
extern NetworkInfoCipherWorkspace network_info_cipher_workspace;
s32 decode_network_info_payload(u8 *arg0, u8 *arg1, u32 arg2, NetworkInfoConfig *arg3);

#pragma push
#pragma scheduling off
#pragma peephole off
#pragma optimization_level 2
s32 parse_hex_string(char *s) {
    char c;
    s32 i;
    s32 v;
    v = 0;
    i = 0;
    while ((c = s[i]) >= '0' && c <= 'f') {
        if (c >= '0' && c <= '9') {
            v = c + (v << 4);
            v -= 0x30;
        } else if (c >= 'a' && c <= 'f') {
            v = c + (v << 4);
            v -= 0x57;
        } else if (c >= 'A' && c <= 'F') {
            v = c + (v << 4);
            v -= 0x37;
        }
        i++;
    }
    return v;
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling off
s32 decode_network_info_payload(u8 *src, u8 *arg1, u32 arg2, NetworkInfoConfig *config) {
    u32 *key;
    u32 i;
    s32 r;
    bind_network_info_cipher_pool((u32 *)&network_info_cipher_workspace, 1);
    key = allocate_network_info_cipher_key((s32)src);
    for (i = 0; i < arg2; i += 0x10) {
        if (decrypt_network_info_cipher_blocks(key, (u8 *)(arg1 + i), 0x10, (u8 *)(arg1 + i)) != 0) {
            return -1;
        }
    }
    r = parse_netinfo((char *)arg1, arg2, config);
    release_network_info_cipher_key(key);
    clear_network_info_cipher_pool();
    return r;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
#pragma optimization_level 2
void copy_network_info_cipher_block(u32 *dst, u32 *src) {
    s32 i;
    for (i = 0; i < 4; i++, dst++, src++) {
        *dst = *src;
    }
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
#pragma optimization_level 2
void decrypt_network_info_cipher_round(u32 *arg0, u32 *arg1) {
    u32 t = arg1[3];
    arg1[3] = ~(arg1[0] ^ ((arg0[1] - arg1[1]) >> 1));
    arg1[0] = arg0[3] ^ arg1[1];
    arg1[1] = ~(arg1[2] ^ ((arg0[2] + t) >> 1));
    arg1[2] = arg0[0] ^ t;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
#pragma optimization_level 2
void decrypt_network_info_cipher_block(u32 *arg0, NetworkInfoCipherBlock *src, NetworkInfoCipherBlock *dst) {
    u32 sp8[4];
    s32 i;
    copy_network_info_cipher_block(sp8, (u32 *)src);
    for (i = 4; i > 0; i--) {
        decrypt_network_info_cipher_round(arg0 + (i - 1) * 4 + 1, sp8);
    }
    copy_network_info_cipher_block((u32 *)dst, sp8);
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma optimization_level 1
void bind_network_info_cipher_pool(u32 *p, s32 n) {
    network_info_cipher_pool_binding.pool = p;
    if (n > 16) {
        n = 16;
    }
    *network_info_cipher_pool_binding.pool = n << 16;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
#pragma optimization_level 2
void clear_network_info_cipher_pool(void) {
    *network_info_cipher_pool_binding.pool = 0;
    network_info_cipher_pool_binding.pool = 0;
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling off
#pragma peephole off
#pragma optimization_level 2
s32 decrypt_network_info_cipher_blocks(u32 *key, u8 *src, s32 len, u8 *dst) {
    s32 i;
    NetworkInfoCipherBlock *p;
    NetworkInfoCipherBlock *q;
    if (key == NULL) {
        return -1;
    }
    if ((len & 0xF) != 0) {
        return -2;
    }
    p = (NetworkInfoCipherBlock *)src;
    q = (NetworkInfoCipherBlock *)dst;
    for (i = 0; i < (len >> 4); i++) {
        decrypt_network_info_cipher_block(key, (NetworkInfoCipherBlock *)(p++), (NetworkInfoCipherBlock *)(q++));
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
#pragma optimization_level 2
u32 *allocate_network_info_cipher_key(s32 src) {
    s32 i;
    u32 *b;
    u32 mask;
    u32 *a;
    u32 bit;
    s32 n;
    u32 *slot;
    n = *network_info_cipher_pool_binding.pool >> 16;
    for (i = 0; i <= n; i++) {
        if (i == n) {
            return NULL;
        }
        if ((*network_info_cipher_pool_binding.pool & (1 << i)) == 0) {
            *network_info_cipher_pool_binding.pool |= 1 << i;
            break;
        }
    }
    slot = (u32 *)&((NetworkInfoCipherPoolView *)network_info_cipher_pool_binding.pool)->slots[i];
    *slot = 1 << i;
    copy_network_info_cipher_block(slot + 1, (u32 *)src);
    for (i = 0; i < 3; i++) {
        a = &((NetworkInfoCipherKey *)slot)->keys[i][0];
        b = &((NetworkInfoCipherKey *)slot)->keys[i + 1][0];
        b[1] = ~((a[1] + a[3]) >> 1) + ~((a[0] - a[2]) << 1);
        b[2] = ~((a[2] + a[3]) >> 1) + ~((a[0] - a[1]) << 1);
        b[3] = ~((a[1] + a[2]) >> 1) + ~((a[0] - a[3]) << 1);
        b[0] = ~((a[2] + a[0]) >> 1) + ~((a[1] - a[3]) << 1);
    }
    return slot;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
#pragma optimization_level 2
void release_network_info_cipher_key(u32 *mask) {
    *network_info_cipher_pool_binding.pool &= ~*mask;
}
#pragma pop

NetworkInfoCipherWorkspace network_info_cipher_workspace;
char network_info_unparsed_config_lines[0x400];
s32 network_info_config_field_handled;
u32 network_info_unparsed_config_length;
NetworkInfoCipherPoolBinding network_info_cipher_pool_binding;
char network_info_config_key_iver[5] = "IVER";
char network_info_config_key_cnum[5] = "CNUM";
char network_info_config_key_mnum[5] = "MNUM";
char network_info_config_key_bnum[5] = "BNUM";
char network_info_config_key_nam[4] = "NAM";
char network_info_config_key_pan[4] = "PAN";
char network_info_config_key_man[4] = "MAN";
char network_info_config_key_sgn[4] = "SGN";
char network_info_config_key_urn[4] = "URN";
char network_info_config_key_pn[4] = "PN_";
char network_info_config_key_li[4] = "LI_";
char network_info_config_key_lp[4] = "LP_";
char network_info_config_key_d1[4] = "D1_";
char network_info_config_key_d2[4] = "D2_";
char network_info_config_key_it[4] = "IT_";
char network_info_config_key_pxs[4] = "PXS";
char network_info_config_key_pxp[4] = "PXP";
char network_info_config_key_at[4] = "AT_";
char network_info_config_key_dt[4] = "DT_";
char network_info_config_key_pa[4] = "PA_";
char network_info_config_key_ol[4] = "OL_";
char network_info_config_key_od[4] = "OD_";
char network_info_config_key_t1[4] = "T1_";
char network_info_config_key_t2[4] = "T2_";
char network_info_config_key_t3[4] = "T3_";
char network_info_config_key_rc[4] = "RC_";
char network_info_config_key_ri[4] = "RI_";
char network_info_config_key_mi[4] = "MI_";
char network_info_config_key_dy[4] = "DY_";
char network_info_config_key_py[4] = "PY_";
char network_info_config_key_ip[4] = "IP_";
char network_info_config_key_snm[4] = "SNM";
char network_info_config_key_g1[4] = "G1_";
char network_info_config_key_hn[4] = "HN_";
char network_info_config_key_mt[4] = "MT_";
char network_info_config_key_mr[4] = "MR_";
char network_info_config_key_sa[4] = "SA_";
char network_info_config_key_sd[4] = "SD_";
char network_info_config_key_iv[4] = "IV_";
char network_info_config_key_ma[4] = "MA_";
char network_info_config_key_ms[4] = "MS_";
char network_info_config_key_ps[4] = "PS_";
char network_info_config_key_pi[4] = "PI_";
char network_info_config_key_pp[4] = "PP_";
char network_info_config_key_mn[4] = "MN_";
char network_info_config_key_nm[4] = "NM_";
char network_info_config_key_cni[4] = "CNI";
char network_info_config_key_cnp[4] = "CNP";
char network_info_config_key_cmi[4] = "CMI";
char network_info_config_key_cmp[4] = "CMP";
char network_info_config_key_sg[4] = "SG_";
char network_info_config_key_url[4] = "URL";
