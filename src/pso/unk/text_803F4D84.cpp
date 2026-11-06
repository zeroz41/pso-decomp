#include "types.h"
#include "pso/network/NetworkInfoLoader.h"
#include "pso/unk/text_803F4D84.h"
#include "pso/unk/TLobby.h"
typedef struct Ent_803F4D84 {
    s16 v;
    u8 pad[0x26];
} Ent_803F4D84;

typedef struct Rec_803F4D84 {
    char name[0x80];
    char name2[0x20];
    s32 f1B8;
    s32 f1BC;
    u8 padA8[0xEE - 0xA8];
    s16 kind;
    u8 f208;
    u8 padF1[3];
    char str20C[0x20];
    char strs[3][0x20];
    u8 pad174[4];
    char str290[0x20];
    u8 f2B0;
    u8 pad199[3];
    s32 f2B4;
    u8 pad1A0[0x210 - 0x1A0];
} Rec_803F4D84;

typedef struct Big_803F4D84 {
    s16 f0;
    s16 cur;
    u8 pad4[0x24];
    Ent_803F4D84 ent[6];
    Rec_803F4D84 rec[6];
} Big_803F4D84;

typedef struct Ent_803F4EBC {
    s16 v;
    u8 pad[0x26];
} Ent_803F4EBC;

typedef struct Rec_803F4EBC {
    char name[0x80];
    char name2[0x20];
    s32 f1B8;
    s32 f1BC;
    u8 padA8[0xEE - 0xA8];
    s16 kind;
    u8 f208;
    u8 padF1[3];
    char str20C[0x20];
    char strs[3][0x20];
    u8 pad174[4];
    char str290[0x20];
    u8 f2B0;
    u8 pad199[3];
    s32 f2B4;
    u8 pad1A0[0x210 - 0x1A0];
} Rec_803F4EBC;

typedef struct Big_803F4EBC {
    s16 f0;
    s16 cur;
    u8 pad4[0x24];
    Ent_803F4EBC ent[6];
    Rec_803F4EBC rec[6];
} Big_803F4EBC;

typedef struct Ent_803F4FF4 {
    s16 v;
    u8 pad[0x26];
} Ent_803F4FF4;

typedef struct Rec_803F4FF4 {
    char name[0x80];
    char name2[0x20];
    s32 f1B8;
    s32 f1BC;
    u8 padA8[0xEE - 0xA8];
    s16 kind;
    u8 f208;
    u8 padF1[3];
    char str20C[0x20];
    char strs[3][0x20];
    u8 pad174[4];
    char str290[0x20];
    u8 f2B0;
    u8 pad199[3];
    s32 f2B4;
    u8 pad1A0[0x210 - 0x1A0];
} Rec_803F4FF4;

typedef struct Big_803F4FF4 {
    s16 f0;
    s16 cur;
    u8 pad4[0x24];
    Ent_803F4FF4 ent[6];
    Rec_803F4FF4 rec[6];
} Big_803F4FF4;

typedef struct Ent_803F50B8 {
    s16 v;
    u8 pad[0x26];
} Ent_803F50B8;

typedef struct Rec_803F50B8 {
    char name[0x80];
    char name2[0x20];
    s32 f1B8;
    s32 f1BC;
    u8 padA8[0xEE - 0xA8];
    s16 kind;
    u8 f208;
    u8 padF1[3];
    char str20C[0x20];
    char strs[3][0x20];
    u8 pad174[4];
    char str290[0x20];
    u8 f2B0;
    u8 pad199[3];
    s32 f2B4;
    u8 pad1A0[0x210 - 0x1A0];
} Rec_803F50B8;

typedef struct Big_803F50B8 {
    s16 f0;
    s16 cur;
    u8 pad4[0x24];
    Ent_803F50B8 ent[6];
    Rec_803F50B8 rec[6];
} Big_803F50B8;

typedef struct Ent_803F517C {
    s16 v;
    u8 pad[0x26];
} Ent_803F517C;

typedef struct Rec_803F517C {
    char name[0x80];
    char name2[0x20];
    s32 f1B8;
    s32 f1BC;
    u8 padA8[0xEE - 0xA8];
    s16 kind;
    u8 f208;
    u8 padF1[3];
    char str20C[0x20];
    char strs[3][0x20];
    u8 pad174[4];
    char str290[0x20];
    u8 f2B0;
    u8 pad199[3];
    s32 f2B4;
    u8 pad1A0[0x210 - 0x1A0];
} Rec_803F517C;

typedef struct Big_803F517C {
    s16 f0;
    s16 cur;
    u8 pad4[0x24];
    Ent_803F517C ent[6];
    Rec_803F517C rec[6];
} Big_803F517C;

typedef struct Ent_803F524C {
    s16 v;
    u8 pad[0x26];
} Ent_803F524C;

typedef struct Rec_803F524C {
    char name[0x80];
    char name2[0x20];
    s32 f1B8;
    s32 f1BC;
    u8 padA8[0xEE - 0xA8];
    s16 kind;
    u8 f208;
    u8 padF1[3];
    char str20C[0x20];
    char strs[3][0x20];
    u8 pad174[4];
    char str290[0x20];
    u8 f2B0;
    u8 pad199[3];
    s32 f2B4;
    u8 pad1A0[0x210 - 0x1A0];
} Rec_803F524C;

typedef struct Big_803F524C {
    s16 f0;
    s16 cur;
    u8 pad4[0x24];
    Ent_803F524C ent[6];
    Rec_803F524C rec[6];
} Big_803F524C;

typedef struct Ent_803F5524 {
    s16 v;
    u8 pad[0x26];
} Ent_803F5524;

typedef struct Rec_803F5524 {
    char name[0x80];
    char name2[0x20];
    s32 f1B8;
    s32 f1BC;
    u8 padA8[0xEE - 0xA8];
    s16 kind;
    u8 f208;
    u8 padF1[3];
    char str20C[0x20];
    char strs[3][0x20];
    u8 pad174[4];
    char str290[0x20];
    u8 f2B0;
    u8 pad199[3];
    s32 f2B4;
    u8 pad1A0[0x210 - 0x1A0];
} Rec_803F5524;

typedef struct Big_803F5524 {
    s16 f0;
    s16 cur;
    u8 pad4[0x24];
    Ent_803F5524 ent[6];
    Rec_803F5524 rec[6];
} Big_803F5524;

typedef struct Ent_803F5678 {
    s16 v;
    u8 pad[0x26];
} Ent_803F5678;

typedef struct Rec_803F5678 {
    char name[0x80];
    char name2[0x20];
    s32 f1B8;
    s32 f1BC;
    u8 padA8[0xEE - 0xA8];
    s16 kind;
    u8 f208;
    u8 padF1[3];
    char str20C[0x20];
    char strs[3][0x20];
    u8 pad174[4];
    char str290[0x20];
    u8 f2B0;
    u8 pad199[3];
    s32 f2B4;
    u8 pad1A0[0x210 - 0x1A0];
} Rec_803F5678;

typedef struct Big_803F5678 {
    s16 f0;
    s16 cur;
    u8 pad4[0x24];
    Ent_803F5678 ent[6];
    Rec_803F5678 rec[6];
} Big_803F5678;

typedef struct Ent_803F5748 {
    s16 v;
    u8 pad[0x26];
} Ent_803F5748;

typedef struct Rec_803F5748 {
    char name[0x80];
    char name2[0x20];
    s32 f1B8;
    s32 f1BC;
    u8 padA8[0xEE - 0xA8];
    s16 kind;
    u8 f208;
    u8 padF1[3];
    char str20C[0x20];
    char strs[3][0x20];
    u8 pad174[4];
    char str290[0x20];
    u8 f2B0;
    u8 pad199[3];
    s32 f2B4;
    u8 pad1A0[0x210 - 0x1A0];
} Rec_803F5748;

typedef struct Big_803F5748 {
    s16 f0;
    s16 cur;
    u8 pad4[0x24];
    Ent_803F5748 ent[6];
    Rec_803F5748 rec[6];
} Big_803F5748;

struct R28_803F5824 { s16 v; u8 pad[0x26]; };

struct E210_803F5824 { u8 pad[0xEE]; s16 state; u8 pad2[0xB0]; u8 data[4]; u8 pad3[0x210 - 0x1A4]; };

struct S_803F5824 { u8 pad0[2]; s16 cur; u8 pad4[0x24]; R28_803F5824 recs[6]; E210_803F5824 ents[6]; };

struct R28_803F5900 { s16 v; s16 w; u8 pad[0x24]; };

struct E210_803F5900 {
    u8 pad0[0xEE];
    s16 state;
    u8 pad1[0xB0];
    u8 data0[4];
    u8 data1[4];
    char name[0x210 - 0x1A8];
};

struct E124_803F5900 {
    char s0[0x40];
    char s1[0x40];
    char s2[0x40];
    char s3[0x20];
    char s4[0x20];
    char s5[0x24];
};

struct S_803F5900 {
    u8 pad0[2];
    s16 cur;
    u8 pad4[0x24];
    R28_803F5900 recs[6];
    union {
        E210_803F5900 ents[6];
        struct {
            u8 pad[0xD5C - 0x118];
            E124_803F5900 ents2[6];
        } b;
    } u;
};

struct R28_803F59DC { s16 v; s16 w; u8 pad[0x24]; };

struct E210_803F59DC {
    u8 pad0[0xEE];
    s16 state;
    u8 pad1[0xB0];
    u8 data0[4];
    u8 data1[4];
    char name[0x210 - 0x1A8];
};

struct E124_803F59DC {
    char s0[0x40];
    char s1[0x40];
    char s2[0x40];
    char s3[0x20];
    char s4[0x20];
    char s5[0x24];
};

struct S_803F59DC {
    u8 pad0[2];
    s16 cur;
    u8 pad4[0x24];
    R28_803F59DC recs[6];
    union {
        E210_803F59DC ents[6];
        struct {
            u8 pad[0xD5C - 0x118];
            E124_803F59DC ents2[6];
        } b;
    } u;
};

struct R28_803F5B20 { s16 v; s16 w; u8 pad[0x24]; };

struct E210_803F5B20 {
    u8 pad0[0xEE];
    s16 state;
    u8 pad1[0xB0];
    u8 data0[4];
    u8 data1[4];
    char name[0x210 - 0x1A8];
};

struct E124_803F5B20 {
    char s0[0x40];
    char s1[0x40];
    char s2[0x40];
    char s3[0x20];
    char s4[0x20];
    char s5[0x24];
};

struct S_803F5B20 {
    u8 pad0[2];
    s16 cur;
    u8 pad4[0x24];
    R28_803F5B20 recs[6];
    union {
        E210_803F5B20 ents[6];
        struct {
            u8 pad[0xD5C - 0x118];
            E124_803F5B20 ents2[6];
        } b;
    } u;
};

struct R28_803F5C58 { s16 v; s16 w; u8 pad[0x24]; };

struct E210_803F5C58 {
    u8 pad0[0xEE];
    s16 state;
    u8 pad1[0xB0];
    u8 data0[4];
    u8 data1[4];
    char name[0x210 - 0x1A8];
};

struct E124_803F5C58 {
    char s0[0x40];
    char s1[0x40];
    char s2[0x40];
    char s3[0x20];
    char s4[0x20];
    char s5[0x24];
};

struct S_803F5C58 {
    u8 pad0[2];
    s16 cur;
    u8 pad4[0x24];
    R28_803F5C58 recs[6];
    union {
        E210_803F5C58 ents[6];
        struct {
            u8 pad[0xD5C - 0x118];
            E124_803F5C58 ents2[6];
        } b;
    } u;
};

struct R28_803F5D90 { s16 v; s16 w; u8 pad[0x24]; };

struct E210_803F5D90 {
    u8 pad0[0xEE];
    s16 state;
    u8 pad1[0xB0];
    u8 data0[4];
    u8 data1[4];
    char name[0x210 - 0x1A8];
};

struct E124_803F5D90 {
    char s0[0x40];
    char s1[0x40];
    char s2[0x40];
    char s3[0x20];
    char s4[0x20];
    char s5[0x24];
};

struct S_803F5D90 {
    u8 pad0[2];
    s16 cur;
    u8 pad4[0x24];
    R28_803F5D90 recs[6];
    union {
        E210_803F5D90 ents[6];
        struct {
            u8 pad[0xD5C - 0x118];
            E124_803F5D90 ents2[6];
        } b;
    } u;
};

struct R28_803F5EC8 { s16 v; s16 w; u8 pad[0x24]; };

struct E210_803F5EC8 {
    u8 pad0[0xEE];
    s16 state;
    u8 pad1[0xB0];
    u8 data0[4];
    u8 data1[4];
    char name[0x210 - 0x1A8];
};

struct E124_803F5EC8 {
    char s0[0x40];
    char s1[0x40];
    char s2[0x40];
    char s3[0x20];
    char s4[0x20];
    char s5[0x24];
};

struct S_803F5EC8 {
    u8 pad0[2];
    s16 cur;
    u8 pad4[0x24];
    R28_803F5EC8 recs[6];
    union {
        E210_803F5EC8 ents[6];
        struct {
            u8 pad[0xD5C - 0x118];
            E124_803F5EC8 ents2[6];
        } b;
    } u;
};

struct R28_803F6000 { s16 v; s16 w; u8 pad[0x24]; };

struct E210_803F6000 {
    u8 pad0[0xEE];
    s16 state;
    u8 pad1[0xB0];
    u8 data0[4];
    u8 data1[4];
    char name[0x210 - 0x1A8];
};

struct E124_803F6000 {
    char s0[0x40];
    char s1[0x40];
    char s2[0x40];
    char s3[0x20];
    char s4[0x20];
    char s5[0x24];
};

struct S_803F6000 {
    u8 pad0[2];
    s16 cur;
    u8 pad4[0x24];
    R28_803F6000 recs[6];
    union {
        E210_803F6000 ents[6];
        struct {
            u8 pad[0xD5C - 0x118];
            E124_803F6000 ents2[6];
        } b;
    } u;
};

struct R28_803F6138 { s16 v; s16 w; u8 pad[0x24]; };

struct E210_803F6138 {
    u8 pad0[0xEE];
    s16 state;
    u8 pad1[0xB0];
    u8 data0[4];
    u8 data1[4];
    char name[0x210 - 0x1A8];
};

struct E124_803F6138 {
    char s0[0x40];
    char s1[0x40];
    char s2[0x40];
    char s3[0x20];
    char s4[0x20];
    char s5[0x24];
};

struct S_803F6138 {
    u8 pad0[2];
    s16 cur;
    u8 pad4[0x24];
    R28_803F6138 recs[6];
    union {
        E210_803F6138 ents[6];
        struct {
            u8 pad[0xD5C - 0x118];
            E124_803F6138 ents2[6];
        } b;
    } u;
};

struct R28_803F6270 { s16 v; u8 pad[0x26]; };

struct E210_803F6270 { u8 pad[0xEC]; u16 v; s16 state; u8 pad2[0x210 - 0xF0]; };

struct S_803F6270 { u8 pad0[2]; s16 cur; u8 pad4[0x24]; R28_803F6270 recs[6]; E210_803F6270 ents[6]; };

typedef struct Ent_803F53A0 {
    s16 v;
    u8 pad[0x26];
} Ent_803F53A0;

typedef struct Rec_803F53A0 {
    char name[0x80];
    char name2[0x20];
    s32 f1B8;
    s32 f1BC;
    u8 padA8[0xEE - 0xA8];
    s16 kind;
    u8 f208;
    u8 padF1[3];
    char str20C[0x20];
    char strs[3][0x20];
    u8 pad174[4];
    char str290[0x20];
    u8 f2B0;
    u8 pad199[3];
    s32 f2B4;
    u8 pad1A0[0x210 - 0x1A0];
} Rec_803F53A0;

typedef struct Big_803F53A0 {
    s16 f0;
    s16 cur;
    u8 pad4[0x24];
    Ent_803F53A0 ent[6];
    Rec_803F53A0 rec[6];
} Big_803F53A0;

extern "C" {
void *memset(void *, int, u32);
char *strncpy(char *, const char *, u32);
u32 strlen(const char *);
extern Big_803F4D84 *lobby_net_config_buffer;
void *memcpy(void *, const void *, u32);
#pragma push
#pragma scheduling off
#pragma peephole off
s32 TLobby::copy_current_entry_name(s32 len) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = lobby_net_config_buffer->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(this, 0, len);
    strncpy(((char *)this), lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].name, len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].name)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 TLobby__sub_803F4EBC(char *dst, s32 len) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = (*(Big_803F4EBC * *)&lobby_net_config_buffer)->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = (*(Big_803F4EBC * *)&lobby_net_config_buffer)->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, (*(Big_803F4EBC * *)&lobby_net_config_buffer)->rec[(*(Big_803F4EBC * *)&lobby_net_config_buffer)->ent[(*(Big_803F4EBC * *)&lobby_net_config_buffer)->cur].v].name2, len - 1);
    if ((u32)len <= strlen((*(Big_803F4EBC * *)&lobby_net_config_buffer)->rec[(*(Big_803F4EBC * *)&lobby_net_config_buffer)->ent[(*(Big_803F4EBC * *)&lobby_net_config_buffer)->cur].v].name2)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 TLobby__sub_803F4FF4(void *dst) {
    Big_803F4FF4 *b;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    b = (*(Big_803F4FF4 * *)&lobby_net_config_buffer);
    i = b->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = b->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    memcpy(dst, &b->rec[i].f1B8, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 TLobby__sub_803F50B8(void *dst) {
    Big_803F50B8 *b;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    b = (*(Big_803F50B8 * *)&lobby_net_config_buffer);
    i = b->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = b->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    memcpy(dst, &b->rec[i].f1BC, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 TLobby__sub_803F517C(u8 *dst) {
    Big_803F517C *b;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    b = (*(Big_803F517C * *)&lobby_net_config_buffer);
    i = b->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = b->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (b->rec[i].kind != 1) {
        return -3;
    }
    *dst = b->rec[i].f208;
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 TLobby__sub_803F524C(char *dst, s32 len) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = (*(Big_803F524C * *)&lobby_net_config_buffer)->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = (*(Big_803F524C * *)&lobby_net_config_buffer)->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if ((*(Big_803F524C * *)&lobby_net_config_buffer)->rec[i].kind != 1) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, (*(Big_803F524C * *)&lobby_net_config_buffer)->rec[(*(Big_803F524C * *)&lobby_net_config_buffer)->ent[(*(Big_803F524C * *)&lobby_net_config_buffer)->cur].v].str20C, len - 1);
    if ((u32)len <= strlen((*(Big_803F524C * *)&lobby_net_config_buffer)->rec[(*(Big_803F524C * *)&lobby_net_config_buffer)->ent[(*(Big_803F524C * *)&lobby_net_config_buffer)->cur].v].str20C)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma optimize_for_size off
#pragma peephole off
s32 TLobby__sub_803F53A0(s32 n, char *dst, s32 len) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = (*(Big_803F53A0 * *)&lobby_net_config_buffer)->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = (*(Big_803F53A0 * *)&lobby_net_config_buffer)->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n < 0 || n >= 3) {
        return -2;
    }
    if ((*(Big_803F53A0 * *)&lobby_net_config_buffer)->rec[i].kind != 1) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, (*(Big_803F53A0 * *)&lobby_net_config_buffer)->rec[(*(Big_803F53A0 * *)&lobby_net_config_buffer)->ent[(*(Big_803F53A0 * *)&lobby_net_config_buffer)->cur].v].strs[0] + (n *= 0x20), len - 1);
    if ((u32)len <= strlen((*(Big_803F53A0 * *)&lobby_net_config_buffer)->rec[(*(Big_803F53A0 * *)&lobby_net_config_buffer)->ent[(*(Big_803F53A0 * *)&lobby_net_config_buffer)->cur].v].strs[0] + n)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 TLobby__sub_803F5524(char *dst, s32 len) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = (*(Big_803F5524 * *)&lobby_net_config_buffer)->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = (*(Big_803F5524 * *)&lobby_net_config_buffer)->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if ((*(Big_803F5524 * *)&lobby_net_config_buffer)->rec[i].kind != 1) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, (*(Big_803F5524 * *)&lobby_net_config_buffer)->rec[(*(Big_803F5524 * *)&lobby_net_config_buffer)->ent[(*(Big_803F5524 * *)&lobby_net_config_buffer)->cur].v].str290, len - 1);
    if ((u32)len <= strlen((*(Big_803F5524 * *)&lobby_net_config_buffer)->rec[(*(Big_803F5524 * *)&lobby_net_config_buffer)->ent[(*(Big_803F5524 * *)&lobby_net_config_buffer)->cur].v].str290)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 TLobby__sub_803F5678(u8 *dst) {
    Big_803F5678 *b;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    b = (*(Big_803F5678 * *)&lobby_net_config_buffer);
    i = b->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = b->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (b->rec[i].kind != 4) {
        return -3;
    }
    *dst = b->rec[i].f2B0;
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 TLobby__sub_803F5748(void *dst) {
    Big_803F5748 *b;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    b = (*(Big_803F5748 * *)&lobby_net_config_buffer);
    i = b->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = b->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (b->rec[i].kind != 4) {
        return -3;
    }
    memcpy(dst, &b->rec[i].f2B4, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 TLobby__sub_803F5824(void *arg0) {
    if (get_network_config_mode() == 0) return -1;
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) return -5;
    S_803F5824 *s = (*(S_803F5824 * *)&lobby_net_config_buffer); s16 i;
    i = s->cur;
    if (i < 0 || i >= 6) return -3;
    i = s->recs[i].v;
    if (i < 0 || i >= 6) return -3;
    if (s->ents[i].state != 4) return -3;
    memcpy(arg0, s->ents[i].data, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 TLobby__sub_803F5900(void *arg0) {
    S_803F5900 *s;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    s = (*(S_803F5900 * *)&lobby_net_config_buffer);
    i = s->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = s->recs[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (s->u.ents[i].state != 4) {
        return -3;
    }
    memcpy(arg0, s->u.ents[i].data1, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 TLobby__sub_803F59DC(char *buf, u32 n) {
    S_803F59DC *s;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    s = (*(S_803F59DC * *)&lobby_net_config_buffer);
    i = s->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = s->recs[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (s->u.ents[i].state != 4) {
        return -3;
    }
    memset(buf, 0, n);
    strncpy(buf, (*(S_803F59DC * *)&lobby_net_config_buffer)->u.ents[(*(S_803F59DC * *)&lobby_net_config_buffer)->recs[(*(S_803F59DC * *)&lobby_net_config_buffer)->cur].v].name, n - 1);
    if (n <= strlen((*(S_803F59DC * *)&lobby_net_config_buffer)->u.ents[(*(S_803F59DC * *)&lobby_net_config_buffer)->recs[(*(S_803F59DC * *)&lobby_net_config_buffer)->cur].v].name)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 TLobby__sub_803F5B20(char *buf, s32 n) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = (*(S_803F5B20 * *)&lobby_net_config_buffer)->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = (*(S_803F5B20 * *)&lobby_net_config_buffer)->recs[i].w;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n <= 0) {
        return -2;
    }
    memset(buf, 0, n);
    strncpy(buf, (*(S_803F5B20 * *)&lobby_net_config_buffer)->u.b.ents2[(*(S_803F5B20 * *)&lobby_net_config_buffer)->recs[(*(S_803F5B20 * *)&lobby_net_config_buffer)->cur].w].s5, n - 1);
    if ((u32)n <= strlen((*(S_803F5B20 * *)&lobby_net_config_buffer)->u.b.ents2[(*(S_803F5B20 * *)&lobby_net_config_buffer)->recs[(*(S_803F5B20 * *)&lobby_net_config_buffer)->cur].w].s5)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 TLobby__sub_803F5C58(char *buf, s32 n) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = (*(S_803F5C58 * *)&lobby_net_config_buffer)->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = (*(S_803F5C58 * *)&lobby_net_config_buffer)->recs[i].w;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n <= 0) {
        return -2;
    }
    memset(buf, 0, n);
    strncpy(buf, (*(S_803F5C58 * *)&lobby_net_config_buffer)->u.b.ents2[(*(S_803F5C58 * *)&lobby_net_config_buffer)->recs[(*(S_803F5C58 * *)&lobby_net_config_buffer)->cur].w].s0, n - 1);
    if ((u32)n <= strlen((*(S_803F5C58 * *)&lobby_net_config_buffer)->u.b.ents2[(*(S_803F5C58 * *)&lobby_net_config_buffer)->recs[(*(S_803F5C58 * *)&lobby_net_config_buffer)->cur].w].s0)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 TLobby__sub_803F5D90(char *buf, s32 n) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = (*(S_803F5D90 * *)&lobby_net_config_buffer)->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = (*(S_803F5D90 * *)&lobby_net_config_buffer)->recs[i].w;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n <= 0) {
        return -2;
    }
    memset(buf, 0, n);
    strncpy(buf, (*(S_803F5D90 * *)&lobby_net_config_buffer)->u.b.ents2[(*(S_803F5D90 * *)&lobby_net_config_buffer)->recs[(*(S_803F5D90 * *)&lobby_net_config_buffer)->cur].w].s1, n - 1);
    if ((u32)n <= strlen((*(S_803F5D90 * *)&lobby_net_config_buffer)->u.b.ents2[(*(S_803F5D90 * *)&lobby_net_config_buffer)->recs[(*(S_803F5D90 * *)&lobby_net_config_buffer)->cur].w].s1)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 TLobby__sub_803F5EC8(char *buf, s32 n) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = (*(S_803F5EC8 * *)&lobby_net_config_buffer)->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = (*(S_803F5EC8 * *)&lobby_net_config_buffer)->recs[i].w;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n <= 0) {
        return -2;
    }
    memset(buf, 0, n);
    strncpy(buf, (*(S_803F5EC8 * *)&lobby_net_config_buffer)->u.b.ents2[(*(S_803F5EC8 * *)&lobby_net_config_buffer)->recs[(*(S_803F5EC8 * *)&lobby_net_config_buffer)->cur].w].s2, n - 1);
    if ((u32)n <= strlen((*(S_803F5EC8 * *)&lobby_net_config_buffer)->u.b.ents2[(*(S_803F5EC8 * *)&lobby_net_config_buffer)->recs[(*(S_803F5EC8 * *)&lobby_net_config_buffer)->cur].w].s2)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 TLobby__sub_803F6000(char *buf, s32 n) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = (*(S_803F6000 * *)&lobby_net_config_buffer)->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = (*(S_803F6000 * *)&lobby_net_config_buffer)->recs[i].w;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n <= 0) {
        return -2;
    }
    memset(buf, 0, n);
    strncpy(buf, (*(S_803F6000 * *)&lobby_net_config_buffer)->u.b.ents2[(*(S_803F6000 * *)&lobby_net_config_buffer)->recs[(*(S_803F6000 * *)&lobby_net_config_buffer)->cur].w].s3, n - 1);
    if ((u32)n <= strlen((*(S_803F6000 * *)&lobby_net_config_buffer)->u.b.ents2[(*(S_803F6000 * *)&lobby_net_config_buffer)->recs[(*(S_803F6000 * *)&lobby_net_config_buffer)->cur].w].s3)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 TLobby__sub_803F6138(char *buf, s32 n) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = (*(S_803F6138 * *)&lobby_net_config_buffer)->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = (*(S_803F6138 * *)&lobby_net_config_buffer)->recs[i].w;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n <= 0) {
        return -2;
    }
    memset(buf, 0, n);
    strncpy(buf, (*(S_803F6138 * *)&lobby_net_config_buffer)->u.b.ents2[(*(S_803F6138 * *)&lobby_net_config_buffer)->recs[(*(S_803F6138 * *)&lobby_net_config_buffer)->cur].w].s4, n - 1);
    if ((u32)n <= strlen((*(S_803F6138 * *)&lobby_net_config_buffer)->u.b.ents2[(*(S_803F6138 * *)&lobby_net_config_buffer)->recs[(*(S_803F6138 * *)&lobby_net_config_buffer)->cur].w].s4)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 TLobby__sub_803F6270(u16 *arg0) {
    S_803F6270 *s;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    s = (*(S_803F6270 * *)&lobby_net_config_buffer);
    i = s->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = s->recs[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    *arg0 = s->ents[i].v;
    return 0;
}
#pragma pop

}
