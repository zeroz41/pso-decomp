#include "types.h"
#include "pso/quest/TQuestVmDownLoadServer_803E6970.h"
#include "pso/quest/TQuestVmDownLoadServer.h"

struct RecoveredGlobal_803EE2E4_lbl_8058DC98 {
    s8 value;
    u8 remaining[0x4F];
};

struct RecoveredGlobal_803E6ACC_lbl_805A0470 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_803E6ACC_lbl_805A0498 {
    s32 value;
    u8 remaining[0x134];
};

struct RecoveredGlobal_803E6ACC_lbl_805A05D0 {
    s32 value;
    u8 remaining[0xC4];
};

struct RecoveredGlobal_803E8710_lbl_8058DE08 {
    s32 value;
    u8 remaining[0x40];
};

struct RecoveredGlobal_803E875C_lbl_8058DE08 {
    s32 value;
    u8 remaining[0x40];
};

struct RecoveredGlobal_803E9764_lbl_80591EC8 {
    s32 value;
    u8 remaining[0x1FFC];
};

struct RecoveredGlobal_803E9F20_lbl_80595998 {
    s32 value;
    u8 remaining[0x8BC];
};

struct RecoveredGlobal_803E6ED0_lbl_805A0470 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_803E6ED0_lbl_805A0498 {
    s32 value;
    u8 remaining[0x134];
};

struct RecoveredGlobal_803E6ED0_lbl_805A05D0 {
    s32 value;
    u8 remaining[0xC4];
};

struct RecoveredGlobal_803E721C_lbl_8047E698 {
    s32 value;
    u8 remaining[0x1FC];
};

struct RecoveredGlobal_803E9594_lbl_80591EC8 {
    s32 value;
    u8 remaining[0x1FFC];
};

struct RecoveredGlobal_803E8084_lbl_8058DE08
{
  s32 value;
  u8 remaining[0x40];
};

struct RecoveredGlobal_803E8084_lbl_80590AC4
{
  s32 value;
  u8 remaining[0xFFC];
};

struct Node_803EB894 { u8 flags; u8 pad[0xF]; Node_803EB894 *next; };

struct Node_803EB794 { u8 flags; u8 pad[0xF]; Node_803EB794 *next; };

struct Node_803ECD54 { u8 pad[0x10]; Node_803ECD54 *next; };

struct Node_803EB878 { u8 flags; u8 pad[0xF]; Node_803EB878 *next; };

struct Node_803EB844 { u8 flags; u8 pad[0xF]; Node_803EB844 *next; };

struct Node_803ECD1C { u8 pad[0xC]; Node_803ECD1C *next; };

struct Node_803ECD8C { s32 *link; u8 pad[8]; Node_803ECD8C *next; };

struct Node_803ECE5C { s32 *link; u8 pad[4]; Node_803ECE5C *next; };

struct E_803E6F48 { u16 key; u8 val; u8 pad; };

struct R_803E76A4 { u8 cnt; u8 pad[7]; };

struct R_803E773C { u8 a; u8 b; u16 c; s16 d; s16 e; };

struct R_803E779C { u8 a; u8 b; u16 c; s16 d; s16 e; };

struct R_803E9F54 { u8 pad[0x14]; s8 a; u8 b; u8 pad2[6]; };

struct N_803E9FA4 { s16 key; u8 pad[0xA]; N_803E9FA4 *next; };

struct Msg_803E92C0 {
    u8 pad0[4];
    s16 len;
    u8 pad6;
    u8 x7;
    u8 x8;
    u8 pad9[3];
    u8 *text;
};

struct Msg_803E9348 {
    u8 pad0[4];
    s16 len;
    u8 pad6;
    u8 x7;
    u8 x8;
    u8 pad9[3];
    u8 *text;
};

struct Item_803EA384 { u8 a; u8 b; u8 pad2[2]; u16 c; };

struct Hdr_803EA384 {
    s16 id;
    u8 pad2[2];
    s32 x4;
    u8 pad8[4];
    s16 count;
    Item_803EA384 items[1];
};

struct Node_803EA384 {
    s16 id;
    u8 a;
    u8 b;
    s32 x4;
    u16 c;
    u8 pada[2];
    Node_803EA384 *next;
};

struct Obj_803EA960 { u8 pad[2]; u8 type; };

struct Ent_803EA960 {
    u8 pad0[8];
    Obj_803EA960 *obj;
    u8 padc[9];
    s8 count;
    u8 pad16[6];
};

struct Node_803ECDC4 { s32 *link; u32 id; u8 pad[4]; Node_803ECDC4 *next; };

struct Obj_803EADD4 {
    s32 x0;
    Node_803ECDC4 *x4;
    Node_803ECD8C *x8;
    Node_803ECD54 *xc;
    s32 x10;
    s8 x14;
    s8 x15;
    s8 x16;
    s8 x17;
    s8 x18;
    s8 x19;
};

struct Node_803EB420 { u8 flags; u8 data[5]; u8 len; u8 pad[9]; Node_803EB420 *next; };

struct Ent_803EDB90 { s32 a; s32 size; };

struct Req_803EEF2C {
    char *name;
    s16 len;
    u8 pad6;
    u8 x7;
    u8 x8;
    u8 pad9[3];
    u8 *text;
};

struct File_803F09FC {
    s32 remain;
    s32 pos;
};

struct RecoveredGlobal_803E8150_lbl_8058DE08 {
    s32 value;
    u8 remaining[0x40];
};

struct Msg_803E90A8 {
    char *name;
    s16 len;
    u8 pad6;
    u8 x7;
    u8 x8;
    u8 pad9[3];
    u8 *text;
};

struct Node_803EB328 { u8 flags; char name[5]; u8 x6; u8 pad[9]; Node_803EB328 *next; };

struct Node_803EBA98 { u8 flags; u8 data[5]; u8 len; u8 pad[9]; Node_803EBA98 *next; };

struct Info_803F0138 {
    s16 id;
    s16 off;
    u8 pad4[8];
    u8 *p;
};

struct R_803EAE84 { u8 pad[0x1C]; };

struct Node_803EB0D8 { u8 flags; u8 pad[0xF]; Node_803EB0D8 *next; };

struct Node_803EB7C0 { u8 flags; char text[5]; u8 len; u8 pad[9]; Node_803EB7C0 *next; };

struct Ent_803F03B4 { u8 a; u8 b; u8 c; u8 pad; u16 key; };

struct Out_803F0268 {
    s16 len;
    u32 x4;
    s16 len2;
    s16 xa;
    s16 count;
    Ent_803F03B4 ents[1];
};

struct Ent_803E6970 {
    u16 ch;
    u8 pad[6];
};

struct R_803E77F0 { u8 a; u8 b; u16 c; s16 d; s16 e; };

struct Tok_803E9FFC { s16 off; u8 a; u8 b; };

struct Seg_803E9FFC { s16 off; u8 pad[2]; u8 a; u8 b; u8 pad2[2]; Seg_803E9FFC *next; };

struct Out_803E9FFC {
    s16 off; u8 a; u8 b;
    Tok_803E9FFC *src;
    s16 x8; s16 xa;
    Out_803E9FFC *next;
};

struct Src_803EBD38 { u16 x0; u16 x2; u8 x4; u8 text[1]; };

struct N_803EBD38 {
    u8 flags;
    u8 text[5];
    u8 x6;
    u8 x7;
    s32 x8;
    u16 xc;
    u16 xe;
    N_803EBD38 *next;
};

struct Page_803E840C {
    s32 page;
    s32 dirty;
    Page_803E840C *next;
    u8 data[0x400];
};

struct Ent_803E840C { u8 a; u8 b; u16 c; s16 d; s16 e; };

struct Cache_803E840C {
    u8 name[0x44];
    Ent_803E840C ents[128];
    Page_803E840C pages[10];
};

struct Ent_803E8C2C { u8 pad[2]; u8 len; char name[1]; };

struct Node_803E8C2C { Ent_803E8C2C *ent; Node_803E8C2C *next; };

struct Out_803E8C2C { s16 a; s16 id; s16 len; s16 pre; u8 pad[4]; Ent_803E8C2C *ent; };

struct Buf_803E82AC {
    u8 name[0x3CBC];
    u8 hdr[0x400];
};

struct Ent_803E9DE0 { u8 a; u8 b; u8 off; u8 d; };

struct Msg_803E9190 {
    char *name;
    s16 len;
    u8 pad6;
    u8 x7;
    u8 x8;
    u8 pad9[3];
    u8 *text;
};

struct Ent_803E8B1C { u8 pad[2]; u8 len; char name[1]; };

struct Node_803E8B1C { Ent_803E8B1C *ent; Node_803E8B1C *next; };

struct Out_803E8B1C { s16 a; s16 id; u8 pad[8]; Ent_803E8B1C *ent; };

struct Ent_803E7ACC {
    s32 index;
    s32 state;
    Ent_803E7ACC *next;
};

extern "C" {
extern RecoveredGlobal_803EE2E4_lbl_8058DC98 lbl_8058DC98;
extern RecoveredGlobal_803E6ACC_lbl_805A0470 lbl_805A0470;
extern RecoveredGlobal_803E6ACC_lbl_805A0498 quest_download_entry_table;
extern RecoveredGlobal_803E6ACC_lbl_805A05D0 lbl_805A05D0;
extern s32 lbl_805D7848;
extern s32 *lbl_805D78B8;
extern s32 *lbl_805D78BC;
extern s32 lbl_805D78C0;
extern s32 *lbl_805D78C4;
extern s32 *lbl_805D78C8;
extern s32 *quest_download_buffer_ptr;
extern s32 *lbl_805D78D0;
extern s32 *quest_download_buffer_start;
extern s32 *quest_vm_download_buffer_end;
extern s32 quest_download_match_length_limit;
extern s32 quest_download_server_state;
extern s32 lbl_805D7904;
extern RecoveredGlobal_803E8710_lbl_8058DE08 quest_vm_download_server_file_info;
extern s32 lbl_805D78F8;
extern RecoveredGlobal_803E9764_lbl_80591EC8 lbl_80591EC8;
extern s8 lbl_805D7868;
struct Sub_803ED9AC { u8 pad[2]; u8 type; };
struct Elem_803ED9AC {
    s16 len;
    u8 kind;
    u8 pad3;
    Sub_803ED9AC *sub;
    u16 cost;
    u16 base;
    Elem_803ED9AC *next;
};
struct Slot_803ED9AC { u8 pad[8]; Elem_803ED9AC *head; u8 pad2[0x10]; };
extern Slot_803ED9AC quest_download_slot_chain_table[];
extern const u8 lbl_8047F8B8[0x100];
extern RecoveredGlobal_803E721C_lbl_8047E698 single_byte_to_jis_table;
s32 strcpy(void *, void *);
s32 dispatch_request_0x20__19TWindowKeyBoardSoftFll(void *, void *);
s32 dispatch_request_0x1c__19TWindowKeyBoardSoftFv();
extern s32 quest_download_initialized;
extern s32 lbl_805D7834;
extern s32 lbl_805D7908;
extern s32 lbl_805D790C;
extern s32 lbl_805E10D8;
extern s32 lbl_805E10E0;
extern s32 lbl_805D7888;
s32 TQuestVmDownLoadServer__sub_803E7098(u8 *p, u16 code);
extern u16 quest_download_char_code_table[];
s32 TQuestVmDownLoadServer__sub_803EC69C(u32);
extern RecoveredGlobal_803E8084_lbl_80590AC4 quest_name_index_table;
void __VIRetraceHandler(void);
Node_803EB894 *detach_node_chain__22TQuestVmDownLoadServerFPv(Node_803EB894 *p);
Node_803EB794 *advance_nodes__22TQuestVmDownLoadServerFPvi(Node_803EB794 *p, s32 n);
extern s32 lbl_805D78AC;
extern s32 *lbl_805D78B0;
Node_803EB878 *TQuestVmDownLoadServer__sub_803EB878(Node_803EB878 *p);
void TQuestVmDownLoadServer__sub_803ECD1C(Node_803ECD1C *p);
void TQuestVmDownLoadServer__sub_803ECD8C(Node_803ECD8C *p);
void TQuestVmDownLoadServer__sub_803ECE5C(Node_803ECE5C *p);
extern E_803E6F48 jis_to_single_byte_symbol_table[];
extern R_803E76A4 quest_download_slot_table[];
N_803E9FA4 *insert_sorted_node__22TQuestVmDownLoadServerFPvPv(N_803E9FA4 *arg0, N_803E9FA4 *arg1);
int strncmp(const char *, const char *, u32);
extern s32 quest_download_name_search_lo;
extern s32 quest_download_name_search_hi;
Node_803EA384 *TQuestVmDownLoadServer__sub_803ECF84(void);
Node_803EA384 *build_item_list__22TQuestVmDownLoadServerFiPv(s32 arg0, Hdr_803EA384 *arg1);
void TQuestVmDownLoadServer__sub_803EADD4(Obj_803EADD4 *arg0, s32 arg1);
s32 TQuestVmDownLoadServer__sub_803EC95C(u16 *, u8 *, int);
s32 TQuestVmDownLoadServer__sub_803EB420(s32 arg0, s32 arg1, Node_803EB420 *arg2, u16 *arg3);
extern u8 quest_download_keyword_table[];
char *strncpy(char *, const char *, u32);
s32 TQuestVmDownLoadServer__sub_803E8DA0(char *, Req_803EEF2C *, s32);
extern s32 lbl_805D7900;
s32 TQuestVmDownLoadServer__sub_803EEF2C(Req_803EEF2C *arg0);
void TQuestVmDownLoadServer__sub_803E8924(s32 id);
void TQuestVmDownLoadServer__sub_803EF8E0(u8 *p);
extern u32 lbl_805D7910;
extern File_803F09FC lbl_805D7914;
extern u8 lbl_80591AC4[];
extern s32 lbl_805D7820;
extern s32 quest_download_ask_header_size;
extern s32 quest_download_header_name_index_hi_count;
extern s32 lbl_805D7874;
extern s32 lbl_805D78FC;
void append_message_text__22TQuestVmDownLoadServerFPviPvUc(u8 *arg0, s32 arg1, Msg_803E90A8 *arg2, u8 arg3);
u32 strlen(const char *);
extern s32 lbl_805D78A4;
extern s32 lbl_805D78EC;
s32 count_fitting_entries__22TQuestVmDownLoadServerFPv(Node_803EB328 *arg0);
s32 TQuestVmDownLoadServer__sub_803EC71C(u16 *, u8 *, s32);
extern u8 quest_download_text_buffer[];
extern u16 lbl_805A0340[];
extern u8 *quest_download_text_write_ptr;
void TQuestVmDownLoadServer__sub_803EBA98(s32 arg0, Node_803EBA98 *arg1);
extern u16 lbl_805A02A8[];
extern s32 lbl_805D7898;
extern Node_803EB794 *lbl_805D78A0;
extern s32 lbl_805D78E8;
extern s32 lbl_805D78F0;
u8 *get_cached_page__22TQuestVmDownLoadServerFi(s32 page);
s32 find_symbol_entry__22TQuestVmDownLoadServerFPvsPv(const char *name, s16 len, Info_803F0138 *out);
void DCInvalidateRange(void *, u32);
void ARQPostRequest(void *req, u32 owner, u32 type, u32 prio, u32 src, u32 dst, u32 len, void (*cb)(u8 *));
u32 OSGetTick(void);
u32 __OSBusClock : 0x800000F8;
void *memcpy(void *, const void *, u32);
void OSReport(const char *, ...);
void ARQRemoveRequest(void *);
extern u8 quest_download_aram_dma_buffer[];
extern const char aram_dma_timeout_message[];
extern u32 lbl_805D791C;
extern u32 lbl_805D7920;
extern u32 lbl_805D7924;
extern s32 quest_download_aram_dma_pending;
extern u32 lbl_805D792C;
void TQuestVmDownLoadServer__sub_803EB4D4(void);
void TQuestVmDownLoadServer__sub_803EC284(s32, s32);
extern s32 lbl_805D789C;
s32 TQuestVmDownLoadServer__sub_803EB7C0(Node_803EB7C0 *arg0);
void release_node_chain__22TQuestVmDownLoadServerFPv(Node_803ECDC4 *p);
s32 TQuestVmDownLoadServer__sub_803F03B4(u8 *data, Ent_803F03B4 *ents, s32 n, s32 *max);
s32 TQuestVmDownLoadServer__sub_803F0268(const char *name, s16 len, Out_803F0268 *out);
s32 TQuestVmDownLoadServer__sub_803E7390(u8 a, u8 b, u8 c);
extern const u8 lbl_805E10C8[8];
Seg_803E9FFC *TQuestVmDownLoadServer__sub_803E9A74(s32, s32, u8, u8);
void *TQuestVmDownLoadServer__sub_803ECF48(void);
void *TQuestVmDownLoadServer__sub_803E9FFC(s32 arg0, s32 arg1, Tok_803E9FFC *t);
void *TQuestVmDownLoadServer__sub_803ECED0(void);
void *TQuestVmDownLoadServer__sub_803ECF0C(void);
extern u8 *file_page_cache_head;
extern Node_803E8C2C *lbl_80593EC8[];
s32 TQuestVmDownLoadServer__sub_803E8C2C(char *arg0, s16 arg1, Out_803E8C2C *arg2);
void TQuestVmDownLoadServer__sub_803EFF20(u8 *data, s32 a1, s32 a2, s32 *best, u8 *dst, s32 flags);
extern const char ask_header_signature[];
extern const s16 quest_download_lz_match_index_table[];
extern Ent_803E9DE0 quest_download_lz_match_entry_table[];
extern u8 lbl_8047F0F8[];
extern Tok_803E9FFC lbl_8047F8A8[4];
extern const u8 lbl_8047F9B8[49][11];
extern const u8 (*const lbl_8047FBD4[27])[11];
Ent_803E9DE0 *find_longest_match_entry__22TQuestVmDownLoadServerFPviPv(u8 *arg0, s32 arg1, s32 *arg2);
void build_message_packet__22TQuestVmDownLoadServerFPviPvUc(u8 *arg0, s32 arg1, Msg_803E9190 *arg2, u8 arg3);
s32 lookup_name_entry__22TQuestVmDownLoadServerFPvsPv(char *arg0, s16 arg1, Out_803E8B1C *arg2);
extern u8 lbl_8047E898[];
extern u16 lbl_8047E8A4[];
void TQuestVmDownLoadServer__sub_803EFCB4(u8 *data, s32 a1, s32 a2, s32 *cnt, s32 *total, u8 *buf, s32 flags);
extern u8 *lbl_805D7824;

typedef char RecoveredGlobal_803E6ACC_lbl_805A0470_size[sizeof(RecoveredGlobal_803E6ACC_lbl_805A0470) == 0x28 ? 1 : -1];
typedef char RecoveredGlobal_803E6ACC_lbl_805A0498_size[sizeof(RecoveredGlobal_803E6ACC_lbl_805A0498) == 0x138 ? 1 : -1];
typedef char RecoveredGlobal_803E6ACC_lbl_805A05D0_size[sizeof(RecoveredGlobal_803E6ACC_lbl_805A05D0) == 0xC8 ? 1 : -1];

s32 TQuestVmDownLoadServer__sub_803E6970(s32 start, s32 count, u16 *buf, s32 flag) {
    Ent_803E6970 *e;
    u16 *dst;
    Ent_803E6970 *end;
    u16 *q;
    s32 hit;
    u16 c;
    s32 n;
    e = (Ent_803E6970 *)&quest_download_entry_table + start;
    end = (Ent_803E6970 *)&quest_download_entry_table + (start + count);
    dst = buf;
    hit = 0;
    while (e < end) {
        if (e == (Ent_803E6970 *)lbl_805D78C8) {
            for (q = (u16 *)quest_download_buffer_start; q < (u16 *)quest_vm_download_buffer_end; q++) {
                c = *q;
                if (c & 0x4000) {
                    c = TQuestVmDownLoadServer__sub_803E721C(c);
                } else {
                    c = (u8)c;
                }
                if (flag != 0 && q == (u16 *)lbl_805D78D0) {
                    n = TQuestVmDownLoadServer::encode_char_with_attr(dst, c, 8);
                    flag = 0;
                } else {
                    n = TQuestVmDownLoadServer::encode_char_with_attr(dst, c, 4);
                }
                dst += n;
            }
            hit = 1;
        }
        if (e >= (Ent_803E6970 *)lbl_805D78C4) {
            break;
        }
        if (flag != 0 && hit != 0) {
            n = TQuestVmDownLoadServer::encode_char_with_attr(dst, e->ch, 8);
            flag = 0;
        } else {
            n = TQuestVmDownLoadServer::encode_char_with_attr(dst, e->ch, 4);
        }
        dst += n;
        hit = 0;
        e++;
    }
    if (flag != 0) {
        dst += TQuestVmDownLoadServer::encode_char_with_attr(dst, 0x20, 8);
    }
    return dst - buf;
}

void TQuestVmDownLoadServer__sub_803E6ACC(s32 arg0) {
    quest_download_server_state = TQuestVmDownLoadServer::get_download_state();
    TQuestVmDownLoadServer::init_block_free_list();
    TQuestVmDownLoadServer::init_entries();
    quest_download_buffer_ptr = &lbl_805A05D0.value;
    lbl_805D78D0 = &lbl_805A05D0.value;
    quest_download_buffer_start = &lbl_805A05D0.value;
    quest_vm_download_buffer_end = &lbl_805A05D0.value;
    lbl_805D78C4 = &quest_download_entry_table.value;
    lbl_805D78C8 = &quest_download_entry_table.value;
    lbl_805D78B8 = &lbl_805A0470.value;
    lbl_805D78BC = &lbl_805A0470.value;
    lbl_805D78C0 = 0;
    TQuestVmDownLoadServer__sub_803EAE84(0, 0x50, (void *)(0));
    TQuestVmDownLoadServer__sub_803EE2E4();
    if (arg0 == 1) {
        quest_download_match_length_limit = 0x23;
        lbl_805D7848 = 1;
    }
}

struct Ent_803E6B70 { u16 ch; u16 pad; s32 len; };
void TQuestVmDownLoadServer__sub_803E6B70(u8 *dst, s32 start, s32 count, s32 mode) {
    s32 TQuestVmDownLoadServer__sub_803E6F98(u16 arg0);
    s32 TQuestVmDownLoadServer__sub_803E7018(u16 arg0);
    Ent_803E6B70 *e;
    Ent_803E6B70 *end;
    u16 c;
    u16 prev;
    s32 i;
    s32 last;
    u16 *p;

    if (mode >= 5) {
        s32 j;
        e = (Ent_803E6B70 *)&quest_download_entry_table;
        i = 0;
        j = 0;
        while (j < start) {
            i += e->len;
            j++;
            e++;
        }
        last = i;
        j = 0;
        while (j < count) {
            last += e->len;
            j++;
            e++;
        }
        p = (u16 *)&lbl_805A05D0 + i;
        for (; i < last; i++) {
            if (mode == 5) {
                u16 k = TQuestVmDownLoadServer::jis_to_sjis(TQuestVmDownLoadServer__sub_803E721C(*p++ | 0x100));
                dst[0] = k >> 8;
                dst[1] = k;
                dst += 2;
            } else if (mode == 6) {
                *dst++ = *p++;
            }
        }
        *dst = 0;
        return;
    }
    e = (Ent_803E6B70 *)&quest_download_entry_table + start;
    end = e + count;
    prev = 0;
    for (; e < end; e++) {
        c = e->ch;
        if (mode == 1) {
            if (!(c & 0xFF00)) {
                if (c == 0xDE && TQuestVmDownLoadServer__sub_803E7018(prev) != 0) {
                    dst -= 2;
                    if (prev == 0x2426) {
                        c = 0x2474;
                    } else {
                        c = prev + 1;
                    }
                } else if (c == 0xDF && TQuestVmDownLoadServer__sub_803E6F98(prev) != 0) {
                    dst -= 2;
                    c = prev + 2;
                } else {
                    c = TQuestVmDownLoadServer__sub_803E721C(c);
                }
            }
            if ((c & 0xFF00) == 0x2500) {
                c &= 0x24FF;
            }
        } else if (mode == 2) {
            if (!(c & 0xFF00)) {
                if (c == 0xDE && TQuestVmDownLoadServer__sub_803E7018(prev) != 0) {
                    dst -= 2;
                    if (prev == 0x2526) {
                        c = 0x2574;
                    } else {
                        c = prev + 1;
                    }
                } else if (c == 0xDF && TQuestVmDownLoadServer__sub_803E6F98(prev) != 0) {
                    dst -= 2;
                    c = prev + 2;
                } else {
                    c = TQuestVmDownLoadServer__sub_803E721C(c | 0x100);
                }
            }
            if ((c & 0xFF00) == 0x2400) {
                c |= 0x2500;
            }
        } else if (mode == 3) {
            dst += TQuestVmDownLoadServer__sub_803E7098(dst, c);
            continue;
        } else if (mode == 4) {
            if (!(c & 0xFF00)) {
                c = TQuestVmDownLoadServer__sub_803E721C(c | 0x100);
            }
        }
        prev = c;
        if (c & 0xFF00) {
            u16 k = TQuestVmDownLoadServer::jis_to_sjis(c);
            *dst++ = k >> 8;
            c = k;
        }
        *dst++ = c;
    }
    *dst = 0;
}

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_803E6ED0_lbl_805A0470_size[sizeof(RecoveredGlobal_803E6ED0_lbl_805A0470) == 0x28 ? 1 : -1];
typedef char RecoveredGlobal_803E6ED0_lbl_805A0498_size[sizeof(RecoveredGlobal_803E6ED0_lbl_805A0498) == 0x138 ? 1 : -1];
typedef char RecoveredGlobal_803E6ED0_lbl_805A05D0_size[sizeof(RecoveredGlobal_803E6ED0_lbl_805A05D0) == 0xC8 ? 1 : -1];
void TQuestVmDownLoadServer::init_buffer_pointers() {
    quest_download_buffer_ptr = &(*(RecoveredGlobal_803E6ED0_lbl_805A05D0 *)&lbl_805A05D0).value;
    lbl_805D78D0 = &(*(RecoveredGlobal_803E6ED0_lbl_805A05D0 *)&lbl_805A05D0).value;
    quest_download_buffer_start = &(*(RecoveredGlobal_803E6ED0_lbl_805A05D0 *)&lbl_805A05D0).value;
    quest_vm_download_buffer_end = &(*(RecoveredGlobal_803E6ED0_lbl_805A05D0 *)&lbl_805A05D0).value;
    lbl_805D78C4 = &(*(RecoveredGlobal_803E6ED0_lbl_805A0498 *)&quest_download_entry_table).value;
    lbl_805D78C8 = &(*(RecoveredGlobal_803E6ED0_lbl_805A0498 *)&quest_download_entry_table).value;
    lbl_805D78B8 = &(*(RecoveredGlobal_803E6ED0_lbl_805A0470 *)&lbl_805A0470).value;
    lbl_805D78BC = &(*(RecoveredGlobal_803E6ED0_lbl_805A0470 *)&lbl_805A0470).value;
    lbl_805D78C0 = 0;
    TQuestVmDownLoadServer__sub_803EAE84(0, 0x50, (void *)(0));
    TQuestVmDownLoadServer__sub_803EE2E4();
}
#pragma pop

s32 TQuestVmDownLoadServer::get_buffer_size() {
    return 0x48;
}


s32 TQuestVmDownLoadServer::lookup_value_by_key(u16 arg0) {
    E_803E6F48 *p;
    for (p = jis_to_single_byte_symbol_table; p < jis_to_single_byte_symbol_table + 45; p++) {
        if (p->key == arg0) {
            return p->val;
        }
        if (p->key > arg0) {
            break;
        }
    }
    return 0;
}

bool TQuestVmDownLoadServer__sub_803E6F98(s32 arg0) {
    u8 spC;
    s32 code;
    s32 TQuestVmDownLoadServer__sub_803E7098(void *, int);
    code = arg0;
    if (TQuestVmDownLoadServer__sub_803ECC7C(arg0) != 0) {
        code = TQuestVmDownLoadServer__sub_803EC69C(code);
    }
    if (TQuestVmDownLoadServer__sub_803E7098(&spC, code) != 1) {
        return 0;
    }
    return (lbl_8047F8B8[spC] & 0xF) == 0xB;
}

bool TQuestVmDownLoadServer__sub_803E7018(s32 arg0) {
    u8 spC;
    s32 code;
    s32 TQuestVmDownLoadServer__sub_803E7098(void *, int);
    code = arg0;
    if (TQuestVmDownLoadServer__sub_803ECC7C(arg0) != 0) {
        code = TQuestVmDownLoadServer__sub_803EC69C(code);
    }
    if (TQuestVmDownLoadServer__sub_803E7098(&spC, code) != 1) {
        return 0;
    }
    return (lbl_8047F8B8[spC] & 0xF) == 0xA;
}

s32 TQuestVmDownLoadServer__sub_803E7098(u8 *p, u16 code) {
    u32 c;
    s32 w = code;

    switch (code & 0xFF00) {
    case 0x2300:
    case 0x0:
        *p = w;
        return 1;
    case 0x2500:
        code &= 0x24FF;
    case 0x2400:
    case 0x2100:
        c = TQuestVmDownLoadServer__sub_803EC8D8(code);
        if ((u8)c < 0x98 || (u8)c >= 0xF7) {
            *p = c;
            return 1;
        }
        code = quest_download_char_code_table[(u8)c - 0x98];
        *p++ = code;
        if (code & 0x8000) {
            *p = 0xDE;
            return 2;
        }
        if (code & 0x4000) {
            *p = 0xDF;
            return 2;
        }
        return 1;
    default:
        *p = 0x20;
        return 1;
    }
}

s32 TQuestVmDownLoadServer__sub_803E719C(u8 arg0, s32 arg1) {
    return arg0 | ((arg1 & 0x100) + 0x2400);
}

typedef char RecoveredGlobal_803E721C_lbl_8047E698_size[sizeof(RecoveredGlobal_803E721C_lbl_8047E698) == 0x200 ? 1 : -1];

u16 TQuestVmDownLoadServer::map_key_to_code(u32 arg0) {
    u8 *k;
    u16 *v;
    k = lbl_8047E898;
    v = lbl_8047E8A4;
    while (*k != 0) {
        if (*k == (u8)arg0) {
            u16 t = *v;
            if ((t & 0xFF00) == 0x2500 && !(arg0 & 0x100)) {
                return (u8)t | 0x2400;
            }
            return t;
        }
        k++;
        v++;
    }
    return 0;
}

u16 TQuestVmDownLoadServer__sub_803E721C(u16 arg0) {
    u16 temp_r3;
    temp_r3 = *(u16 *)((s8 *)((u8 *)&single_byte_to_jis_table.value + ((arg0 * 2) & 0x1FE)) + 0);
    if (((s32) (temp_r3 & 0xFF00) == 0x2500) && !(arg0 & 0x100)) {
        return (u8) temp_r3 | 0x2400;
    }
    return temp_r3;
}

s32 TQuestVmDownLoadServer::is_valid_item_for_slot(u8 c, u8 k) {
    if (c >= 0xC0) {
        return 1;
    }
    if (c < 0x80) {
        if (c < 0x2D && k != 0) {
            if (c >= 1 && c <= 0xD) {
                c += 0x7F;
            } else {
                c = 0;
            }
            if (c == 0) {
                return 0;
            }
        } else {
            if (c == 0xD || (c >= 0x13 && c <= 0x34) || c == 0x38) {
                return 1;
            }
            return 0;
        }
    }
    switch (c) {
    case 0x8B:
    case 0x8D:
    case 0x93:
    case 0x96:
    case 0x99:
    case 0x9A:
    case 0x9B:
    case 0x9E:
    case 0xA1:
    case 0xA2:
    case 0xA7:
    case 0xA8:
    case 0xB1:
        if ((k >= 5 && k <= 8) || k >= 0xA) {
            return 1;
        }
        break;
    case 0x97:
        if (k == 8) {
            return 0;
        }
    case 0x8E:
    case 0x92:
    case 0x94:
    case 0x95:
    case 0x98:
    case 0xA0:
        if (k >= 5) {
            return 1;
        }
        break;
    default:
        if (k == 4 || (u8)(k - 7) <= 1 || k >= 0xA) {
            return 1;
        }
        break;
    }
    return 0;
}

struct Row_803E7390 { s16 single; s16 pair; };

static const u8 glyph_bits[0x3E0] = {
    0x00, 0x08, 0x76, 0xE8, 0x4F, 0xEE, 0xDC, 0x00, 0x08, 0x76, 0xF8, 0xFF, 0xFF, 0xDD, 0x00, 0x08,
    0x76, 0xF8, 0xEF, 0xFF, 0xDD, 0x00, 0x08, 0x76, 0xF8, 0xCF, 0xFF, 0xCC, 0x00, 0x08, 0x76, 0xE8,
    0xCF, 0xEB, 0x5D, 0x00, 0x04, 0x38, 0xF4, 0x27, 0x77, 0x2E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x58,
    0x10, 0x00, 0x81, 0x0E, 0x30, 0x01, 0x8C, 0x0A, 0x80, 0x40, 0x87, 0xFE, 0x64, 0x4E, 0x05, 0x40,
    0xA0, 0x03, 0x6C, 0x04, 0xA3, 0x02, 0x20, 0xD0, 0x01, 0x00, 0x80, 0x51, 0x01, 0x10, 0xE8, 0xD0,
    0x97, 0xDD, 0xBB, 0x00, 0x08, 0x74, 0x00, 0x01, 0x20, 0x40, 0x00, 0x04, 0x3A, 0xF4, 0x67, 0x31,
    0x2E, 0x00, 0x02, 0x1D, 0xFA, 0xB3, 0x19, 0x15, 0x00, 0x01, 0x0E, 0x3D, 0x09, 0x8C, 0x0A, 0x80,
    0x40, 0x87, 0xBC, 0x68, 0x56, 0x05, 0x40, 0xA0, 0x43, 0x1B, 0x36, 0xAF, 0x02, 0x20, 0xD0, 0x01,
    0x26, 0x81, 0x77, 0x01, 0x10, 0xE8, 0x40, 0x90, 0xCC, 0xAA, 0x00, 0x08, 0x74, 0x28, 0x08, 0x60,
    0x54, 0x00, 0x04, 0x3A, 0xC4, 0x2C, 0xF3, 0x3F, 0x00, 0x02, 0x1D, 0x6A, 0x92, 0x79, 0x17, 0x00,
    0x00, 0x00, 0xFF, 0xFD, 0xBF, 0x03, 0x00, 0x00, 0xC0, 0x0A, 0x00, 0x3B, 0x00, 0x00, 0x00, 0xA4,
    0x60, 0xB3, 0x03, 0x20, 0x00, 0x40, 0x02, 0x06, 0x3B, 0x00, 0xFE, 0x01, 0x00, 0x20, 0x00, 0x00,
    0x01, 0x48, 0x50, 0x60, 0x00, 0x00, 0x02, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x1F,
    0x00, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0xA0,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x00, 0x00, 0x81, 0x0E, 0x00, 0x01,
    0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x02, 0x1D, 0x00, 0x20, 0x18, 0x15, 0x89, 0x40, 0x00, 0x02,
    0x10, 0x80, 0x00, 0x37, 0x20, 0x00, 0x01, 0x08, 0x40, 0x40, 0x02, 0x18, 0x80, 0x40, 0x04, 0x20,
    0x00, 0x03, 0x00, 0x20, 0x00, 0x00, 0x01, 0x08, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x08, 0x20, 0x10, 0x01,
    0x18, 0xC0, 0x00, 0x10, 0x00, 0x00, 0x02, 0x00, 0x00, 0x01, 0x04, 0x08, 0x00, 0x03, 0x12, 0x00,
    0x80, 0x40, 0x00, 0x02, 0x00, 0x43, 0x11, 0x80, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x20, 0x00,
    0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x08, 0x04, 0x40, 0x00, 0x00, 0x80, 0x00, 0x04,
    0x20, 0x00, 0x01, 0x08, 0x40, 0x00, 0x02, 0x10, 0x80, 0x00, 0x00, 0x20, 0x00, 0x01, 0x08, 0x40,
    0x00, 0x02, 0x10, 0x80, 0x00, 0x04, 0x28, 0x00, 0x00, 0x08, 0x40, 0x00, 0x02, 0x10, 0x80, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x01,
    0x11, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
    0x10, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x20, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x14, 0x41, 0x00, 0x02, 0x10, 0x80, 0x00, 0x04, 0x08, 0x80, 0x03, 0x00, 0x40, 0x00,
    0x00, 0x10, 0x80, 0x00, 0x02, 0x50, 0x40, 0x00, 0x06, 0x30, 0x80, 0x00, 0x08, 0xC0, 0x00, 0x04,
    0x00, 0x00, 0x01, 0x00, 0x90, 0x00, 0x03, 0x10, 0x80, 0x00, 0x05, 0xA0, 0x00, 0x06, 0x30, 0x00,
    0x00, 0x00, 0x80, 0x08, 0x02, 0x34, 0xC0, 0x00, 0x08, 0x20, 0x40, 0x00, 0x08, 0x00, 0x00, 0x02,
    0x24, 0x00, 0x01, 0x0C, 0x40, 0x00, 0x02, 0x10, 0x80, 0x00, 0x04, 0x20, 0x00, 0x01, 0x08, 0x60,
    0x00, 0x02, 0x10, 0x80, 0x00, 0x02, 0x22, 0x80, 0x01, 0x0C, 0x40, 0x00, 0x02, 0x10, 0x20, 0x00,
    0x04, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x09, 0x40, 0x00, 0x02, 0x10, 0x80, 0x00, 0x00,
    0x00, 0x80, 0x00, 0x08, 0x00, 0x00, 0x02, 0x18, 0x40, 0x00, 0x02, 0x30, 0x80, 0x02, 0x08, 0xC0,
    0x50, 0x04, 0x20, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x20, 0x00, 0x01, 0x0A, 0x40, 0x00, 0x02, 0x10, 0x00, 0x00, 0x04, 0x20, 0x00, 0x01, 0x08, 0x40,
    0x00, 0x02, 0x00, 0xA0, 0x20, 0x01, 0x08, 0x40, 0x00, 0x20, 0x00, 0x01, 0x09, 0x40, 0x00, 0x02,
    0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0x02, 0x18, 0x00, 0x00, 0x00, 0x22,
    0x00, 0x01, 0x08, 0x40, 0x00, 0x02, 0x10, 0x80, 0x00, 0x04, 0x20, 0x00, 0x00, 0x08, 0x40, 0x00,
    0x02, 0x10, 0x80, 0x00, 0x04, 0x20, 0x00, 0x01, 0x09, 0x40, 0x00, 0x02, 0x10, 0x80, 0x00, 0x03,
    0x20, 0x00, 0x00, 0x08, 0x00, 0x40, 0x00, 0x18, 0x88, 0x40, 0x00, 0x22, 0x10, 0x80, 0x00, 0x04,
    0x20, 0x00, 0x01, 0x09, 0x40, 0x00, 0x02, 0x10, 0x80, 0x00, 0x22, 0x20, 0x00, 0x00, 0x08, 0x00,
    0x40, 0x02, 0x18, 0x80, 0x00, 0x04, 0x20, 0x50, 0x82, 0x10, 0x84, 0x20, 0x00, 0x40, 0x00, 0x02,
    0x10, 0x80, 0x00, 0x04, 0x20, 0x00, 0x00, 0x00, 0x41, 0x00, 0x40, 0x10, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x80, 0x50, 0x04, 0x20, 0x00, 0x01, 0x10, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x08,
    0x20, 0x01, 0x06, 0x00, 0x00, 0x00, 0x02, 0x01, 0x08, 0x40, 0x00, 0x02, 0x10, 0x80, 0x00, 0x04,
    0x20, 0x00, 0x01, 0x08, 0x40, 0x00, 0x02, 0x18, 0x80, 0x00, 0x04, 0x00, 0x00, 0x00, 0x84, 0x22,
    0x00, 0x01, 0x08, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x04, 0x20, 0x00, 0x00,
    0x00, 0x10, 0x48, 0x40, 0x02, 0x10, 0x90, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x40, 0x00, 0x00,
    0x02, 0x40, 0x00, 0x04, 0x20, 0x20, 0x41, 0x02, 0x10, 0x80, 0x00, 0x04, 0x20, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x46, 0x2A, 0x90, 0x80, 0x0C, 0x24, 0x20, 0xC0, 0x0D, 0x08,
    0x40, 0x00, 0x02, 0x10, 0x90, 0x00, 0x06, 0x20, 0x01, 0x01, 0x48, 0xA4, 0x22, 0x01, 0x09, 0x48,
    0x20, 0x02, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x01, 0x08, 0x60, 0x00, 0x00, 0x00, 0x90, 0x48,
    0x00, 0x02, 0x10, 0x80, 0x00, 0x04, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x12, 0xC0, 0x00,
    0x04, 0x00, 0x00, 0x41, 0x02, 0x10, 0x80, 0x00, 0x04, 0x20, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x04, 0x80, 0x00, 0x06, 0x20, 0x00, 0x00, 0x08, 0x12, 0x80, 0x00, 0x04, 0x20, 0x40, 0x01, 0x04,
    0x00, 0x00, 0x00, 0x10, 0x00, 0x80, 0x04, 0x38, 0x00, 0x01, 0x00, 0x40, 0x90, 0x00, 0x04, 0x20,
    0x00, 0x01, 0x08, 0x00, 0x02, 0x02, 0x10, 0x80, 0x00, 0x00, 0x24, 0x80, 0x01, 0x08, 0x40, 0x00,
    0x02, 0x24, 0x00, 0x01, 0x08, 0x40, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x08,
    0x60, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0x00, 0x04, 0x3A, 0xF4, 0x67, 0xB3, 0x6A, 0x00,
};

static const Row_803E7390 glyph_rows[0x72] = {
    { 2086, 4095 }, { 1214, 4095 }, { 1159, 2141 }, { 1104, 3370 }, { 1049, 6416 }, { 1104, 3370 },
    { 1104, 6579 }, { 994, 3370 }, { 939, 7032 }, { 884, 3554 }, { 2375, 5221 }, { 2375, 5221 },
    { 2375, 5221 }, { 2375, 5221 }, { 1899, 3600 }, { 2375, 2790 }, { 1899, 3987 }, { 2375, 3201 },
    { 1899, 3987 }, { 7871, 3120 }, { 2005, 2538 }, { 1927, 2276 }, { 2375, 4734 }, { 2375, 4734 },
    { 2375, 2919 }, { 1807, 2920 }, { 829, 5110 }, { 774, 5908 }, { 774, 5908 }, { 774, 7195 },
    { 774, 7032 }, { 719, 5309 }, { 664, 7032 }, { 609, 3763 }, { 774, 7032 }, { 554, 7032 },
    { 499, 6579 }, { 444, 3897 }, { 389, 7358 }, { 774, 4547 }, { 774, 4957 }, { 168, 7521 },
    { 168, 7521 }, { 112, 5525 }, { 2375, 6066 }, { 1940, 5221 }, { 334, 5221 }, { 1269, 5437 },
    { 1269, 5437 }, { 56, 2141 }, { 56, 2141 }, { 56, 6707 }, { 2375, 4194 }, { 1807, 2920 },
    { 1807, 3030 }, { 1852, 2856 }, { 1775, 2318 }, { 1731, 2318 }, { 1688, 2837 }, { 1642, 2837 },
    { 1915, 2318 }, { 1914, 2318 }, { 1913, 2318 }, { 1596, 2318 }, { 1595, 2318 }, { 1594, 4341 },
    { 1593, 2318 }, { 1592, 2318 }, { 1591, 2318 }, { 1590, 2318 }, { 1589, 2318 }, { 1588, 2318 },
    { 1527, 2463 }, { 1575, 2318 }, { 1871, 2318 }, { 1927, 2325 }, { 1688, 2318 }, { 2042, 2318 },
    { 2375, 3701 }, { 1927, 2680 }, { 2375, 4341 }, { 1478, 6871 }, { 1478, 6871 }, { 1899, 3600 },
    { 2375, 2790 }, { 1899, 2726 }, { 279, 3370 }, { 279, 4413 }, { 0, 2437 }, { 0, 4413 },
    { 1426, 4893 }, { 1927, 4265 }, { 1899, 5686 }, { 1899, 2726 }, { 1927, 2341 }, { 1959, 5735 },
    { 1959, 5735 }, { 224, 7687 }, { 1899, 3427 }, { 2375, 4341 }, { 1927, 4265 }, { 1374, 2768 },
    { 1374, 2318 }, { 1871, 2318 }, { 1871, 2318 }, { 1871, 2318 }, { 1478, 6255 }, { 1852, 2856 },
    { 1899, 4604 }, { 2375, 6187 }, { 1919, 2318 }, { 1322, 3272 }, { 1574, 3370 }, { 1927, 3427 },
};

static const u8 glyph_col[0x100] = {
    0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0xFF, 0x0B, 0x0C, 0x0D,
    0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x14, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
    0xFF, 0xFF, 0xFF, 0x17, 0x18, 0x19, 0x1A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x16, 0x14, 0x12, 0x0C, 0x00, 0x07, 0x16, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0B, 0x0B, 0x16, 0x21, 0x2C, 0x37, 0x42,
    0x21, 0x21, 0x37, 0x4D, 0x58, 0x58, 0x2C, 0x63, 0x6E, 0x4D, 0x6E, 0x79, 0x6E, 0x42, 0x84, 0x8F,
    0x37, 0x4D, 0x2C, 0x21, 0x21, 0x6E, 0x9A, 0x21, 0x21, 0x9A, 0x9A, 0x21, 0x9A, 0x9A, 0xA5, 0xB0,
    0x9A, 0x2C, 0x9A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x25, 0x25, 0x25, 0x26, 0x26,
    0x27, 0x27, 0x28, 0x28, 0x29, 0x2A, 0x2B, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x2F, 0x2F, 0x2E, 0x2E,
    0x30, 0x31, 0x2E, 0x32, 0x32, 0x33, 0x32, 0x32, 0x32, 0x34, 0x24, 0x35, 0x35, 0x35, 0x35, 0x35,
    0x35, 0x35, 0x35, 0x24, 0x24, 0x36, 0x36, 0x37, 0x36, 0x36, 0x38, 0x36, 0x09, 0x09, 0x39, 0xFF,
};

s32 TQuestVmDownLoadServer__sub_803E7390(u8 a, u8 b, u8 c) {
    u8 col;
    const Row_803E7390 *row;
    s16 bit;
    if (c < 0x80) {
        return 0;
    }
    if (a < 0x2D && b != 0) {
        if (a >= 1 && a <= 0xD) {
            a += 0x7F;
        } else {
            a = 0;
        }
        if (a == 0) {
            return 0;
        }
    }
    col = glyph_col[a];
    if ((s16)col == 0xFF) {
        return 0;
    }
    if (c >= 0xC0) {
        row = &glyph_rows[c - 0xC0];
    } else {
        row = &glyph_rows[c - 0x41];
    }
    if (a < 0x80 || a >= 0xC0) {
        bit = row->single + col;
        return glyph_bits[bit >> 3] & lbl_805E10C8[bit & 7];
    }
    bit = row->pair + col + b - 1;
    return glyph_bits[bit >> 3] & lbl_805E10C8[bit & 7];
}

void TQuestVmDownLoadServer::invalidate_entries_by_id(s32 id) {
    s32 i;
    for (i = 0; i < 128; i++) {
        if (id == ((R_803E773C *)quest_download_slot_table)[i].e) {
            ((R_803E773C *)quest_download_slot_table)[i].e = -1;
        }
    }
}

void TQuestVmDownLoadServer::clear_entries_by_id(s32 id) {
    s32 i;
    for (i = 0; i < 128; i++) {
        if (id == (s16)(((R_803E773C *)quest_download_slot_table)[i].e >> 12)) {
            ((R_803E773C *)quest_download_slot_table)[i].e = -1;
        }
    }
}

s32 TQuestVmDownLoadServer::release_ref_slot(u32 arg0) {
    R_803E76A4 *r;
    if (arg0 >= 0x80U) {
        return -1;
    }
    r = &quest_download_slot_table[arg0];
    if (r->cnt == 0) {
        return -1;
    }
    r->cnt--;
    return 0;
}

s32 TQuestVmDownLoadServer::set_slot_values_for_indices(s32 *arg0, s32 arg1, u32 arg2) {
    s32 i;
    for (i = 0; i < arg1; i++, arg0++) {
        s32 idx = *arg0;
        if (idx >= 0 && idx < 0x80 && ((R_803E773C *)quest_download_slot_table)[idx].a != 0) {
            ((R_803E773C *)quest_download_slot_table)[idx].b = (u8)arg2;
        }
    }
    return 0;
}

s32 TQuestVmDownLoadServer::get_max_size_of_indices(s32 arg1) {
    s32 *arg0 = (s32 *)this;
    s32 i;
    s32 max = 0;
    for (i = 0; i < arg1; i++) {
        s32 idx = arg0[i];
        if (idx >= 0 && idx < 0x80) {
            R_803E773C *r = &((R_803E773C *)&quest_download_slot_table)[idx];
            if (r->a != 0) {
                if (max < r->b) {
                    max = r->b;
                }
            }
        }
    }
    return max;
}

s32 TQuestVmDownLoadServer__sub_803E779C(u32 arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    R_803E779C *r;
    if (arg0 >= 0x80U) {
        return -1;
    }
    r = &((R_803E779C *)&quest_download_slot_table)[arg0];
    if (r->a == 0) {
        return -1;
    }
    *arg1 = r->d;
    *arg2 = r->e;
    *arg3 = r->b;
    return r->c;
}

u32 TQuestVmDownLoadServer::acquire_slot_entry(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    R_803E77F0 *r;
    s32 free_idx;
    r = ((R_803E77F0 *)&quest_download_slot_table);
    free_idx = -1;
    for (i = 0; i < 128; i++, r++) {
        if (r->a == 0) {
            if (free_idx == -1) {
                free_idx = i;
            }
        } else if (r->c == arg0 && r->d == arg1 && r->e == arg2) {
            r->a++;
            return i;
        }
    }
    if (free_idx == -1) {
        return -1;
    }
    r = &((R_803E77F0 *)&quest_download_slot_table)[free_idx];
    r->a = 1;
    r->c = arg0;
    r->d = arg1;
    r->e = arg2;
    r->b = arg3;
    return free_idx;
}

void TQuestVmDownLoadServer__sub_803E79AC(void) {
    int i;
    for (i = 0; i < 0x80; i++) {
        quest_download_slot_table[i].cnt = 0;
    }
}

struct Page_803E7B9C {
    s32 page;
    s32 dirty;
    Page_803E7B9C *next;
    u8 data[0x400];
};
#define HEAD_803E7B9C (*(Page_803E7B9C **)&file_page_cache_head)

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
inline s32 Open_803E7B9C(void) {
    s32 h = TQuestVmDownLoadServer__sub_803F0BE0(&quest_vm_download_server_file_info.value, (void *)lbl_805D78F8);
    if (h == -1) {
        lbl_805D7904 = -1;
        return -1;
    }
    lbl_805D7904 = h;
    return 0;
}
inline s32 Seek_803E7B9C(s32 pos) {
    if (TQuestVmDownLoadServer__sub_803F09FC((void *)lbl_805D7904, pos, 0) == -1) {
        if (Open_803E7B9C() != 0) {
            return -1;
        }
        if (TQuestVmDownLoadServer__sub_803F09FC((void *)lbl_805D7904, pos, 0) == -1) {
            return -1;
        }
    }
    return 0;
}
inline s32 Write_803E7B9C(void) {
    return -1;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 Open_803E7ACC(void) {
    void *mode = (void *)lbl_805D78F8;
    s32 h = TQuestVmDownLoadServer__sub_803F0BE0(&quest_vm_download_server_file_info.value, mode);
    if (h == -1) {
        lbl_805D7904 = -1;
        return -1;
    }
    lbl_805D7904 = h;
    return 0;
}
inline s32 Seek_803E7ACC(s32 h, s32 pos, s32 whence) {
    return TQuestVmDownLoadServer__sub_803F09FC((void *)h, pos, whence);
}
inline s32 SeekRetry_803E7ACC(s32 pos) {
    if (Seek_803E7ACC(lbl_805D7904, pos, 0) == -1) {
        if (Open_803E7ACC() != 0) {
            return -1;
        }
        if (Seek_803E7ACC(lbl_805D7904, pos, 0) == -1) {
            return -1;
        }
    }
    return 0;
}
void TQuestVmDownLoadServer::retry_seek_active_entries() {
    Ent_803E7ACC *e;
    u8 unused[0x18];
    for (e = (Ent_803E7ACC *)file_page_cache_head; e != NULL; e = e->next) {
        if (e->state == 1) {
            SeekRetry_803E7ACC((e->index << 10) + 0x3400);
        }
    }
}
#pragma pop

u8 *get_cached_page__22TQuestVmDownLoadServerFi(s32 page) {
    u8 unused[0x38];
    Page_803E7B9C *prev = NULL;
    Page_803E7B9C *p = HEAD_803E7B9C;

    for (;;) {
        if (p->page == page) {
            if (prev != NULL) {
                prev->next = p->next;
                p->next = HEAD_803E7B9C;
                HEAD_803E7B9C = p;
            }
            return p->data;
        }
        if (p->next == NULL) {
            break;
        }
        prev = p;
        p = p->next;
    }
    prev->next = NULL;
    p->next = HEAD_803E7B9C;
    HEAD_803E7B9C = p;
    if (p->dirty == 1) {
        if (Seek_803E7B9C(p->page * 0x400 + 0x3400) != -1) {
            Write_803E7B9C();
        }
    }
    p->page = page;
    p->dirty = 0;
    if (Seek_803E7B9C(p->page * 0x400 + 0x3400) != -1) {
        TQuestVmDownLoadServer::aram_dma_read((void *)lbl_805D7904, p->data, 0x400);
    }
    return p->data;
}
#pragma pop

void TQuestVmDownLoadServer::set_active() {
    *(s32 *)((s8 *)file_page_cache_head + 4) = 1;
}

typedef struct RecoveredGlobal_803E8084_lbl_8058DE08 RecoveredGlobal_803E8084_lbl_8058DE08;
typedef struct RecoveredGlobal_803E8084_lbl_80590AC4 RecoveredGlobal_803E8084_lbl_80590AC4;
typedef char RecoveredGlobal_803E8084_lbl_8058DE08_size[((sizeof(RecoveredGlobal_803E8084_lbl_8058DE08)) == 0x44) ? (1) : (-1)];
typedef char RecoveredGlobal_803E8084_lbl_80590AC4_size[((sizeof(RecoveredGlobal_803E8084_lbl_80590AC4)) == 0x1000) ? (1) : (-1)];

s32 TQuestVmDownLoadServer::match_prefix_length(const u8 *a, const u8 *b, s32 n) {
    s32 i;
    for (i = 0; i < n; i++, a++, b++) {
        if (*a != *b) {
            break;
        }
        if (*a == 0) {
            break;
        }
    }
    return i;
}

typedef char Name_803E7EE4[4];

typedef u8 Name_803E7E3C[4];
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline s32 match_803E7E3C(u8 *p, u8 *q) {
    s32 i;
    u8 c;
    for (i = 0; i < 4; i++, p++, q++) {
        c = *p;
        if (c != *q || c == 0) {
            break;
        }
    }
    return i;
}

#pragma push
#pragma opt_common_subs off
typedef u8 Name_803E7D98[4];
s32 TQuestVmDownLoadServer::count_matching_name_prefix(s32 arg0, u8 *arg1) {
    u8 *p;
    u8 *q;
    s32 i;
    q = arg1;
    p = ((Name_803E7D98 *)&quest_name_index_table)[arg0];
    for (i = 0; i < 4; i++, p++, q++) {
        u8 c = *p;
        if (c != *q || c == 0) {
            break;
        }
    }
    if (i < 4 && arg1[i] != 0) {
        i++;
    }
    return i;
}
#pragma pop

s32 TQuestVmDownLoadServer::has_name_mismatch(u8 *arg1) {
    s32 arg0 = (s32)this;
    s32 i = match_803E7E3C(((Name_803E7E3C *)&quest_name_index_table)[arg0 + 1], arg1);
    if (arg1[i] == 0) {
        return 0;
    }
    return 1;
}
#pragma pop

s32 TQuestVmDownLoadServer::find_name_index() {
    s32 mid;
    s32 hi;
    s32 lo;
    int r;
    hi = quest_download_name_search_hi;
    lo = quest_download_name_search_lo;
    while (lo + 1 < hi) {
        mid = (hi + lo) / 2;
        r = strncmp(((const char *)this), ((Name_803E7EE4 *)&quest_name_index_table)[mid], 4);
        if (r == 0) {
            return mid;
        }
        if (r > 0) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    if (strncmp(((const char *)this), ((Name_803E7EE4 *)&quest_name_index_table)[lo], 4) < 0) {
        return lo - 1;
    }
    return lo;
}

void TQuestVmDownLoadServer__sub_803E7F9C(u8 *text, s16 mode) {
    u8 c = *text;
    s32 col;
    s32 row;
    u8 *p;
    s32 index;
    if (c < 0xA1) {
        return;
    }
    p = text + 1;
    row = c - 0xA1;
    if (mode == 1) {
        col = 0;
    } else {
        u8 d = *p;
        if (d < 0xA1) {
            return;
        }
        col = d - 0xA0;
    }
    index = row * 11 + (col >> 3);
    lbl_805D7824[index] |= 1 << (col & 7);
    lbl_805D7820 = 1;
}

s32 TQuestVmDownLoadServer::is_char_allowed(s16 arg1) {
    u8 *arg0 = (u8 *)this;
  int new_var;
  u8 c = *arg0;
  s32 bit;
  s32 rowi;
  u8 *p;
  if (c < 0xA1)
  {
    return 0;
  }
  p = arg0 + 1;
  rowi = c - 0xA1;
  if (arg1 == 1)
  {
    bit = 0;
  }
  else
  {
    u8 d = *p;
    if (1)
    {
      if (d < 0xA1)
      {
        return 0;
      }
    }
    bit = d - 0xA0;
  }
  new_var = (rowi * 0xB) + (bit >> 3);
  if ((1 << (bit & 7)) & lbl_805D7824[new_var])
  {
    return 0;
  }
  return 1;
}

s32 TQuestVmDownLoadServer__sub_803E8084(void) {
  s32 temp_r3;
  s32 var_r0;
  s32 var_r0_2;
  var_r0_2 = 0;
  if (TQuestVmDownLoadServer__sub_803F09FC((void *)((void *) lbl_805D7904), 0x400, (int)((int) var_r0_2)) == (-1))
  {
    temp_r3 = TQuestVmDownLoadServer__sub_803F0BE0((void *) (&(*(RecoveredGlobal_803E8084_lbl_8058DE08 *)&quest_vm_download_server_file_info).value), (void *) lbl_805D78F8);
    if (temp_r3 == (-1))
    {
      lbl_805D7904 = (var_r0 = -1);
    }
    else
    {
      lbl_805D7904 = temp_r3;
      var_r0 = 0;
    }
    if (var_r0 != 0)
    {
      var_r0_2 = -1;
    }
    else
    {
      if (lbl_805D78F8)
      {
      }
      if (TQuestVmDownLoadServer__sub_803F09FC((void *)((void *) lbl_805D7904), 0x400, 0) == (-1))
      {
        var_r0_2 = -1;
      }
      else
      {
        goto block_8;
      }
    }
  }
  else
  {
    block_8:
    var_r0_2 = 0;
  }
  if (var_r0_2 == (-1))
  {
    return -1;
  }
  if (((s32)TQuestVmDownLoadServer::aram_dma_read((void *)((void *)((void *) lbl_805D7904)), &quest_name_index_table.value, 0x1000)) != 0x1000)
  {
    return -1;
  }
  return 0;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 Open_803E8624(void) {
    s32 h = TQuestVmDownLoadServer__sub_803F0BE0(&quest_vm_download_server_file_info.value, (void *)lbl_805D78F8);
    if (h == -1) {
        lbl_805D7904 = -1;
        return -1;
    }
    lbl_805D7904 = h;
    return 0;
}
inline s32 Seek_803E8624(s32 h, s32 pos, s32 whence) {
    return TQuestVmDownLoadServer__sub_803F09FC((void *)((void *)h), pos, whence);
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
inline s32 Open_803E8150(void) {
    s32 h = TQuestVmDownLoadServer__sub_803F0BE0(&(*(RecoveredGlobal_803E8150_lbl_8058DE08 *)&quest_vm_download_server_file_info).value, (void *)lbl_805D78F8);
    if (h == -1) {
        lbl_805D7904 = -1;
        return -1;
    }
    lbl_805D7904 = h;
    return 0;
}
inline s32 Seek_803E8150(s32 pos) {
    if (TQuestVmDownLoadServer__sub_803F09FC((void *)lbl_805D7904, pos, 0) == -1) {
        if (Open_803E8150() != 0) {
            return -1;
        }
        if (TQuestVmDownLoadServer__sub_803F09FC((void *)lbl_805D7904, pos, 0) == -1) {
            return -1;
        }
    }
    return 0;
}
inline s32 Write_803E8150(void) {
    return -1;
}
s32 TQuestVmDownLoadServer__sub_803E8150(void) {
    u8 *p = lbl_80591AC4 + 0x30;
    if (lbl_805D7874 == quest_download_ask_header_size && lbl_805D78FC == quest_download_header_name_index_hi_count && lbl_805D7820 == 0) {
        return 0;
    }
    p[0] = lbl_805D7874 % 256;
    p[1] = lbl_805D7874 / 256;
    p[2] = lbl_805D7900 % 256;
    p[3] = lbl_805D7900 / 256;
    p[4] = lbl_805D78FC % 256;
    p[5] = lbl_805D78FC / 256;
    if (Seek_803E8150(0) == -1) {
        return -1;
    }
    return Write_803E8150();
}
#pragma pop

struct RecoveredGlobal_803E8710_lbl_8058DE08;
#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
inline s32 Open_803E82AC(Buf_803E82AC *b) {
    s32 h = TQuestVmDownLoadServer__sub_803F0BE0(b->name, (void *)lbl_805D78F8);
    if (h == -1) {
        lbl_805D7904 = -1;
        return -1;
    }
    lbl_805D7904 = h;
    return 0;
}
inline s32 Seek_803E82AC(Buf_803E82AC *b, s32 pos) {
    if (TQuestVmDownLoadServer__sub_803F09FC((void *)lbl_805D7904, pos, 0) == -1) {
        if (Open_803E82AC(b) != 0) {
            return -1;
        }
        if (TQuestVmDownLoadServer__sub_803F09FC((void *)lbl_805D7904, pos, 0) == -1) {
            return -1;
        }
    }
    return 0;
}
s32 TQuestVmDownLoadServer::read_ask_header() {
    Buf_803E82AC *b = (Buf_803E82AC *)&quest_vm_download_server_file_info;
    u8 *h;
    u8 unused[0x18];
    if (Seek_803E82AC((Buf_803E82AC *)&quest_vm_download_server_file_info, 0) == -1) {
        return -1;
    }
    if ((s32)TQuestVmDownLoadServer::aram_dma_read((void *)lbl_805D7904, (b)->hdr, 0x400) != 0x400) {
        return -1;
    }
    h = (b)->hdr;
    if (strncmp((char *)h, ask_header_signature, strlen(ask_header_signature)) != 0) {
        return -1;
    }
    quest_download_name_search_lo = 0;
    quest_download_name_search_hi = h[0x2E] + (h[0x2F] << 8);
    quest_download_ask_header_size = lbl_805D7874 = h[0x30] + (h[0x31] << 8);
    quest_download_header_name_index_hi_count = lbl_805D78FC = h[0x34] + (h[0x35] << 8);
    lbl_805D7820 = 0;
    return 0;
}
#pragma pop

void TQuestVmDownLoadServer::init_page_cache() {
    Cache_803E840C *c;
    Page_803E840C *p;
    Ent_803E840C *e;
    u32 i;
    c = (Cache_803E840C *)&quest_vm_download_server_file_info;
    *(Page_803E840C **)&file_page_cache_head = p = c->pages;
    for (; p < &c->pages[9]; p++) {
        p->page = -1;
        p->dirty = 0;
        p->next = p + 1;
    }
    p->page = -1;
    p->dirty = 0;
    p->next = NULL;
    e = c->ents;
    for (i = 0; i < 128; i++) {
        e[i].a = 0;
    }
}

s32 TQuestVmDownLoadServer::seek_or_reopen(int pos) {
    u8 unused[8];
    if (Seek_803E8624(lbl_805D7904, pos, 0) == -1) {
        if (Open_803E8624() != 0) {
            return -1;
        }
        if (Seek_803E8624(lbl_805D7904, pos, 0) == -1) {
            return -1;
        }
    }
    return 0;
}
#pragma pop

s32 TQuestVmDownLoadServer__sub_803E86C8(void) {
    if (TQuestVmDownLoadServer__sub_803F0BD8((void *)lbl_805D7904) == -1) {
        lbl_805D7904 = -1;
        return -1;
    }
    lbl_805D7904 = -1;
    return 0;
}

typedef char RecoveredGlobal_803E8710_lbl_8058DE08_size[sizeof(RecoveredGlobal_803E8710_lbl_8058DE08) == 0x44 ? 1 : -1];
s32 TQuestVmDownLoadServer::find_file_info_index() {
    s32 temp_r3;
    temp_r3 = TQuestVmDownLoadServer__sub_803F0BE0((void *)((void *)&quest_vm_download_server_file_info.value), (void *)lbl_805D78F8);
    if (temp_r3 == -1) {
        lbl_805D7904 = -1;
        return -1;
    }
    lbl_805D7904 = temp_r3;
    return 0;
}

typedef char RecoveredGlobal_803E875C_lbl_8058DE08_size[sizeof(RecoveredGlobal_803E875C_lbl_8058DE08) == 0x44 ? 1 : -1];

#pragma push
#pragma opt_common_subs off
void TQuestVmDownLoadServer::set_file_info_name() {
    s32 arg0 = (s32)this;
    strcpy((void *) (&(*(RecoveredGlobal_803E875C_lbl_8058DE08 *)&quest_vm_download_server_file_info).value), (void *)arg0);
}
#pragma pop

s32 TQuestVmDownLoadServer__sub_803E8788(int _w0, void * _w1, int _w2) {
    return -1;
}

u32 TQuestVmDownLoadServer::aram_read_thunk(u32 arg1, int _w2) {
    s32 arg0 = (s32)this;
    return TQuestVmDownLoadServer::aram_dma_read((void *)arg0, (void *)arg1, (int)_w2);
}

void TQuestVmDownLoadServer::unescape_copy_string(u8 *arg0, u8 *arg1, u8 *arg2) {
    while (arg1 < arg2 && *arg1 > 0x38) {
        if (*arg1 == 0xFF) {
            arg1++;
        } else {
            *arg0++ = *arg1++;
        }
        *arg0++ = *arg1++;
    }
    *arg0 = 0;
}

s32 TQuestVmDownLoadServer::count_entries_until_terminator(const u8 *p, const u8 *end) {
    s32 n = 0;
    while (p < end && *p > 0x38) {
        if (*p == 0xFF) {
            n += 1;
        } else {
            n += 2;
        }
        p += 2;
    }
    return n;
}

void TQuestVmDownLoadServer::copy_sjis_string(u8 *arg0, u8 *arg1) {
    while (*arg0 != 0) {
        u8 c = *arg0;
        s32 lead;
        if ((c >= 0x80 && c <= 0x9F) || (c >= 0xE0 && c <= 0xFC)) {
            lead = 1;
        } else {
            lead = 0;
        }
        if (lead) {
            *arg1++ = *arg0++;
        } else {
            *arg1++ = 0xFF;
        }
        *arg1++ = *arg0++;
    }
}

s32 TQuestVmDownLoadServer::calc_sjis_string_width(u8 *arg0) {
    s32 n = 0;
    while (*arg0 != 0) {
        u8 c = *arg0;
        s32 lead;
        if ((c >= 0x80 && c <= 0x9F) || (c >= 0xE0 && c <= 0xFC)) {
            lead = 1;
        } else {
            lead = 0;
        }
        if (lead) {
            arg0 += 2;
        } else {
            arg0 += 1;
        }
        n += 2;
    }
    return n;
}

void TQuestVmDownLoadServer__sub_803E8918(void) {
    lbl_805D7868 = 1;
}

typedef char RecoveredGlobal_803E9764_lbl_80591EC8_size[sizeof(RecoveredGlobal_803E9764_lbl_80591EC8) == 0x2000 ? 1 : -1];

typedef char RecoveredGlobal_803E9594_lbl_80591EC8_size[sizeof(RecoveredGlobal_803E9594_lbl_80591EC8) == 0x2000 ? 1 : -1];

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 IsSjisLead_803E92C0(u8 c) {
    if ((c >= 0x80 && c <= 0x9F) || (c >= 0xE0 && c <= 0xFC)) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 IsSjisLead_803E90A8(u8 c) {
    if ((c >= 0x80 && c <= 0x9F) || (c >= 0xE0 && c <= 0xFC)) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 Hash_803E8C2C(char *s) {
    s32 h;
    u8 c = s[0];
    if (c >= 0xA0 && c < 0xF0) {
        h = c - 0xA0;
    } else {
        h = 0;
    }
    return h;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 Hash_803E8B1C(char *s) {
    s32 h;
    u8 c = s[0];
    if (c >= 0xA0 && c < 0xF0) {
        h = c - 0xA0;
    } else {
        h = 0;
    }
    return h;
}
s32 lookup_name_entry__22TQuestVmDownLoadServerFPvsPv(char *arg0, s16 arg1, Out_803E8B1C *arg2) {
    Node_803E8B1C *n;
    s32 r;
    u8 len;
    s32 off;
    u8 unused[8];
    Ent_803E8B1C *e;
    for (n = ((Node_803E8B1C * *)&lbl_80593EC8)[Hash_803E8B1C(arg0)]; n != NULL; n = n->next) {
        e = n->ent;
        len = e->len;
        r = strncmp(e->name, arg0, (s16)len);
        if (r == 0) {
            if ((s16)len == arg1) {
                break;
            }
        } else if (r > 0) {
            arg2->id = -1;
            return 0;
        }
    }
    if (n == NULL) {
        arg2->id = -1;
        return 0;
    }
    off = (u8 *)e - (u8 *)&lbl_80591EC8;
    arg2->a = 0;
    arg2->id = ((off / 1024) << 12) | (off % 1024);
    arg2->ent = e;
    return 1;
}
#pragma pop

s32 TQuestVmDownLoadServer__sub_803E8C2C(char *arg0, s16 arg1, Out_803E8C2C *arg2) {
    Node_803E8C2C *n;
    Ent_803E8C2C *e;
    s16 len;
    Ent_803E8C2C *found;
    s16 pre;
    s16 blen;
    s32 r;
    s16 m;
    s32 off;
    u8 unused[8];
    blen = 0;
    pre = 0;
    arg2->pre = 0;
    arg2->len = 0;
    for (n = lbl_80593EC8[Hash_803E8C2C(arg0)]; n != NULL; n = n->next) {
        e = n->ent;
        len = e->len;
        m = TQuestVmDownLoadServer::match_prefix_length((u8 *)e->name, (u8 *)arg0, (s16)len);
        if (m >= pre) {
            pre = m + 1;
        }
        r = strncmp(e->name, arg0, (s16)len);
        if (r == 0) {
            if ((s16)len == arg1) {
                return 2;
            }
            blen = len;
            found = e;
        } else if (r > 0) {
            if (strncmp(e->name, arg0, arg1) == 0) {
                return 2;
            }
            break;
        }
    }
    if (blen == 0) {
        arg2->id = -1;
        return 0;
    }
    off = (u8 *)found - (u8 *)&lbl_80591EC8;
    arg2->a = 0;
    arg2->id = ((off / 1024) << 12) | (off % 1024);
    arg2->len = blen;
    arg2->pre = pre;
    arg2->ent = found;
    return 1;
}
#pragma pop

void append_message_text__22TQuestVmDownLoadServerFPviPvUc(u8 *arg0, s32 arg1, Msg_803E90A8 *arg2, u8 arg3) {
    u16 cur;
    s32 v;
    u8 *p;
    u8 *s;
    cur = arg0[0];
    cur += arg0[1] << 8;
    v = arg1 + cur;
    arg0[0] = v % 256;
    arg0[1] = v / 256;
    p = arg0 + cur;
    *p++ = arg2->x7;
    *p++ = arg3;
    if (arg2->x8 != 0 || arg2->x7 >= 0x2D) {
        *p++ = arg2->x8;
    }
    s = arg2->text;
    while (*s != 0) {
        if (IsSjisLead_803E90A8(*s)) {
            *p++ = *s++;
        } else {
            *p++ = 0xFF;
        }
        *p++ = *s++;
    }
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
inline s32 IsSjisLead_803E9190(u8 c) {
    if ((c >= 0x80 && c <= 0x9F) || (c >= 0xE0 && c <= 0xFC)) {
        return 1;
    }
    return 0;
}
inline void CopyText_803E9190(u8 *s, u8 *p) {
    while (*s != 0) {
        if (IsSjisLead_803E9190(*s)) {
            *p++ = *s++;
        } else {
            *p++ = 0xFF;
        }
        *p++ = *s++;
    }
}
void build_message_packet__22TQuestVmDownLoadServerFPviPvUc(u8 *arg0, s32 arg1, Msg_803E9190 *arg2, u8 arg3) {
    u8 unused[8];
    *arg0++ = arg1 % 256;
    *arg0++ = arg1 / 256;
    *arg0++ = arg2->len;
    strncpy((char *)arg0, arg2->name, arg2->len);
    arg0 += arg2->len;
    *arg0++ = arg2->x7;
    *arg0++ = arg3;
    if (arg2->x8 != 0 || arg2->x7 >= 0x2D) {
        *arg0++ = arg2->x8;
    }
    CopyText_803E9190(arg2->text, arg0);
}
#pragma pop

s32 TQuestVmDownLoadServer::calc_text_length() {
    Msg_803E92C0 *arg0 = (Msg_803E92C0 *)this;
    s32 n;
    u8 *p;
    s32 extra;
    if (arg0->x8 != 0 || arg0->x7 >= 0x2D) {
        extra = 3;
    } else {
        extra = 2;
    }
    p = arg0->text;
    n = 0;
    while (*p != 0) {
        if (IsSjisLead_803E92C0(*p)) {
            p += 2;
        } else {
            p += 1;
        }
        n += 2;
    }
    return extra + n;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 IsSjisLead_803E9348(u8 c) {
    if ((c >= 0x80 && c <= 0x9F) || (c >= 0xE0 && c <= 0xFC)) {
        return 1;
    }
    return 0;
}
s32 TQuestVmDownLoadServer::calc_message_length() {
    Msg_803E9348 *arg0 = (Msg_803E9348 *)this;
    s32 n;
    u8 *p;
    s32 extra;
    if (arg0->x8 != 0 || arg0->x7 >= 0x2D) {
        extra = 3;
    } else {
        extra = 2;
    }
    p = arg0->text;
    n = 0;
    while (*p != 0) {
        if (IsSjisLead_803E9348(*p)) {
            p += 2;
        } else {
            p += 1;
        }
        n += 2;
    }
    extra = arg0->len + extra;
    n = extra + n;
    return n + 3;
}
#pragma pop

u8 *TQuestVmDownLoadServer::get_buffer_ptr(s32 arg0) {
    return (u8 *)&(*(RecoveredGlobal_803E9594_lbl_80591EC8 *)&lbl_80591EC8).value + ((s16) (arg0 >> 0xC) << 0xA) + (s16) (arg0 & 0xFFF);
}

void TQuestVmDownLoadServer__sub_803E9764(void) {
    s32 *var_r4;
    s32 var_r3;
    s32 var_r5;
    if ((u8) (*(u8 *)&lbl_805D7868) != 0) {
        var_r3 = 0x1400;
        if (TQuestVmDownLoadServer::seek_or_reopen(0x1400) != -1) {
            var_r4 = &lbl_80591EC8.value;
            var_r3 = lbl_805D7904;
            var_r4 = &lbl_80591EC8.value;
            var_r5 = 0x2000;
            TQuestVmDownLoadServer__sub_803E8788(var_r3, &lbl_80591EC8.value, 0x2000);
        }
    }
}

typedef char RecoveredGlobal_803E9F20_lbl_80595998_size[sizeof(RecoveredGlobal_803E9F20_lbl_80595998) == 0x8C0 ? 1 : -1];

s32 TQuestVmDownLoadServer::is_download_cmd_allowed(u8 arg0) {
    if ((lbl_805D7888 - 1) <= 1U) {
        return 0;
    }
    switch (arg0) {
    case 0x9D:
    case 0xA1:
    case 0xA3:
    case 0xA5:
    case 0xA7:
    case 0xA9:
    case 0xC3:
    case 0xE3:
    case 0xE5:
    case 0xE7:
    case 0xEE:
    case 0xF2:
    case 0xF3:
        return 1;
    default:
        return 0;
    }
}

Ent_803E9DE0 *find_longest_match_entry__22TQuestVmDownLoadServerFPviPv(u8 *arg0, s32 arg1, s32 *arg2) {
    u8 *s;
    u8 *a;
    s32 k;
    s32 rem;
    Ent_803E9DE0 *p;
    s32 m;
    s32 best = 1;
    u8 c = arg0[0];
    if (c < 0xA0) {
        *arg2 = 1;
        return NULL;
    }
    c -= 0xA0;
    for (p = &quest_download_lz_match_entry_table[quest_download_lz_match_index_table[c + 1]] - 1; p >= &quest_download_lz_match_entry_table[quest_download_lz_match_index_table[c]]; p--) {
        a = arg0 + 1;
        rem = arg1 - 1;
        s = &lbl_8047F0F8[p->off];
        m = 1;
        k = *s++ - 1;
        while (1) {
            if (k == 0) {
                if (m > best) {
                    best = m;
                }
                *arg2 = best;
                return p;
            }
            if (rem == 0) {
                if (lbl_805D7888 >= 3) {
                    return (Ent_803E9DE0 *)-1;
                }
                break;
            }
            m++;
            if (*s != *a) {
                if (m > best) {
                    best = m;
                }
                break;
            }
            a++;
            s++;
            rem--;
            k--;
        }
    }
    *arg2 = best;
    return NULL;
}

void TQuestVmDownLoadServer::latch_slot_value(s32 arg0) {
    struct Fields_temp_r3 { u8 pad_0[20]; u8 field_14; u8 field_15; u8 field_16; };
    u8 *temp_r3;
    temp_r3 = (u8 *)quest_download_slot_chain_table + (arg0 * 0x1C);
    if (((s8) ((Fields_temp_r3*)temp_r3)->field_16 == 0) && ((s8) ((Fields_temp_r3*)temp_r3)->field_14 != 0)) {
        ((Fields_temp_r3*)temp_r3)->field_16 = (u8) ((Fields_temp_r3*)temp_r3)->field_15;
    }
}

s32 TQuestVmDownLoadServer__sub_803E9F54(s32 arg0) {
    R_803E9F54 *r;
    if (arg0 >= lbl_805D78C0) {
        return 0;
    }
    r = &((R_803E9F54 *)quest_download_slot_chain_table)[arg0];
    if (lbl_805D7848 == 2 && r->a == 0) {
        return 0;
    }
    return (s8)r->b;
}

N_803E9FA4 *insert_sorted_node__22TQuestVmDownLoadServerFPvPv(N_803E9FA4 *arg0, N_803E9FA4 *arg1) {
    N_803E9FA4 *cur;
    N_803E9FA4 *prev;
    s16 k = arg1->key;
    if (arg0 == NULL || arg0->key < k) {
        arg1->next = arg0;
        return arg1;
    }
    cur = arg0->next;
    prev = arg0;
    while (cur != NULL) {
        if (cur->key < k) {
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    prev->next = arg1;
    arg1->next = cur;
    return arg0;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 IsX_803E9FFC(u8 arg0) {
    if ((lbl_805D7888 - 1) <= 1U) {
        return 0;
    }
    switch (arg0) {
    case 0x9D:
    case 0xA1:
    case 0xA3:
    case 0xA5:
    case 0xA7:
    case 0xA9:
    case 0xC3:
    case 0xE3:
    case 0xE5:
    case 0xE7:
    case 0xEE:
    case 0xF2:
    case 0xF3:
        return 1;
    default:
        return 0;
    }
}
void *TQuestVmDownLoadServer__sub_803E9FFC(s32 arg0, s32 arg1, Tok_803E9FFC *t) {
    s32 off;
    Out_803E9FFC *head;
    Out_803E9FFC *tail;
    s32 pos;
    Seg_803E9FFC *s;
    Seg_803E9FFC *first;
    Out_803E9FFC *o;
    off = t->off;
    head = NULL;
    tail = NULL;
    pos = arg0 + off;
    s = TQuestVmDownLoadServer__sub_803E9A74(pos, arg1, t->a, t->b);
    if ((u32)s == 0xFFFFFFFFU) {
        return (void *)-1;
    }
    for (first = s; s != NULL; s = s->next) {
        o = (Out_803E9FFC *)TQuestVmDownLoadServer__sub_803ECF48();
        if (o == NULL) {
            break;
        }
        if (head == NULL) {
            head = o;
        }
        o->off = off + s->off;
        o->a = s->a;
        o->b = s->b;
        o->src = t;
        o->x8 = 0;
        o->xa = 0;
        o->next = NULL;
        if (tail != NULL) {
            tail->next = o;
        }
        tail = o;
    }
    TQuestVmDownLoadServer__sub_803ECE5C((Node_803ECE5C *)first);
    if (off > 0 && TQuestVmDownLoadServer::is_valid_item_for_slot(t->a, t->b) != 0) {
        if (pos >= arg1 || IsX_803E9FFC(((u8 *)&lbl_805A0470)[pos]) == 0) {
            o = (Out_803E9FFC *)TQuestVmDownLoadServer__sub_803ECF48();
            if (o != NULL) {
                if (head == NULL) {
                    head = o;
                }
                o->off = off;
                o->a = t->a;
                o->b = t->b;
                o->src = t;
                o->x8 = 0;
                o->xa = 0;
                o->next = NULL;
                if (tail != NULL) {
                    tail->next = o;
                }
            }
        }
    }
    return head;
}
#pragma pop

Node_803EA384 *build_item_list__22TQuestVmDownLoadServerFiPv(s32 arg0, Hdr_803EA384 *arg1) {
    s16 id;
    s32 x4;
    s32 n;
    Item_803EA384 *it;
    Node_803EA384 *head;
    Node_803EA384 *prev;
    Node_803EA384 *node;
    u8 unused[8];
    it = arg1->items;
    head = NULL;
    prev = NULL;
    id = arg1->id;
    x4 = arg1->x4;
    n = arg1->count;
    while (n-- != 0) {
        node = TQuestVmDownLoadServer__sub_803ECF84();
        if (node == NULL) {
            break;
        }
        if (head == NULL) {
            head = node;
        }
        node->id = id;
        node->a = it->a;
        node->b = it->b;
        node->x4 = x4;
        node->c = it->c;
        node->next = NULL;
        if (prev != NULL) {
            prev->next = node;
        }
        prev = node;
        it++;
    }
    return head;
}

s32 TQuestVmDownLoadServer::count_leading_entries(s32 i, s32 end) {
    Ent_803EA960 *e = &((Ent_803EA960 *)quest_download_slot_chain_table)[i];
    s32 n;
    s32 total = 0;
    while (i < end) {
        n = e->count;
        if (n == 0) {
            return -1;
        }
        if (e->obj != NULL && (u32)e->obj != 0xFFFFFFFF && e->obj->type != 0x28) {
            break;
        }
        total += n;
        i += n;
        e += n;
    }
    if (total == 0 || i >= end) {
        return total;
    }
    return total + n;
}

void TQuestVmDownLoadServer__sub_803EADD4(Obj_803EADD4 *arg0, s32 arg1) {
    if (arg1 == 0) {
        arg0->x0 = -1;
        arg0->x18 = -1;
        if ((u32)arg0->x4 != 0xFFFFFFFF) {
            release_node_chain__22TQuestVmDownLoadServerFPv((Node_803ECDC4 *)(arg0->x4));
        }
        arg0->x4 = NULL;
        arg0->x17 = -1;
        arg0->x19 = -1;
        arg0->x16 = 0;
    }
    if (arg0->x8 != NULL && (u32)arg0->x8 != 0xFFFFFFFF) {
        TQuestVmDownLoadServer__sub_803ECD8C(arg0->x8);
    }
    arg0->x8 = NULL;
    if (arg0->xc != NULL) {
        ((TQuestVmDownLoadServer *)(arg0->xc))->free_node_list();
    }
    arg0->xc = NULL;
    arg0->x10 = 0;
    arg0->x14 = 0;
    arg0->x15 = 0;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 Len_803EB328(Node_803EB328 *p) {
    s32 n;
    if (p->flags == 0x80) {
        return lbl_805D78EC * 2;
    }
    n = (lbl_805D78EC - p->x6) * 2;
    while (p->flags & 1) {
        n += strlen(p->name);
        p = p->next;
    }
    return n + strlen(p->name);
}
inline Node_803EB328 *Next_803EB328(Node_803EB328 *p) {
    while (p->flags & 1) {
        p = p->next;
    }
    return p->next;
}

void TQuestVmDownLoadServer__sub_803EAE84(s32 arg0, s32 arg1, void *arg2) {
    R_803EAE84 *p;
    R_803EAE84 *end;
    end = &((R_803EAE84 *)quest_download_slot_chain_table)[arg1];
    p = &((R_803EAE84 *)quest_download_slot_chain_table)[arg0];
    for (; p < end; p++) {
        TQuestVmDownLoadServer__sub_803EADD4((Obj_803EADD4 *)(p), (s32)arg2);
    }
}

struct Ent_803EAEF0 {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xc;
    s32 x10;
    u8 x14;
    u8 x15;
    u8 x16;
    s8 x17;
    s8 x18;
    s8 x19;
};

void TQuestVmDownLoadServer::init_entries() {
    Ent_803EAEF0 *p;

    for (p = (Ent_803EAEF0 *)quest_download_slot_chain_table; p < (Ent_803EAEF0 *)quest_download_slot_chain_table + 80; p++) {
        p->x0 = -1;
        p->x4 = 0;
        p->x8 = 0;
        p->xc = 0;
        p->x10 = 0;
        p->x14 = 0;
        p->x15 = 0;
        p->x16 = 0;
        p->x17 = -1;
        p->x18 = -1;
        p->x19 = -1;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline Node_803EB0D8 *Advance_803EB0D8(Node_803EB0D8 *p, s32 n) {
    s32 i;
    for (i = 0; i != n; i++) {
        while (p->flags & 1) {
            p = p->next;
        }
        p = p->next;
    }
    return p;
}
inline void Reload_803EB0D8(void) {
    s32 r = count_fitting_entries__22TQuestVmDownLoadServerFPv((Node_803EB328 *)((*(Node_803EB0D8 * *)&lbl_805D78A0)));
    if (r == 0) {
        TQuestVmDownLoadServer__sub_803EC284(0, 0);
    } else {
        lbl_805D789C = r;
    }
    lbl_805D7898 = 0;
}
s32 TQuestVmDownLoadServer__sub_803EB0D8(s32 arg0, s32 arg1) {
    Node_803EB0D8 *save = (*(Node_803EB0D8 * *)&lbl_805D78A0);
    s32 cnt = lbl_805D789C;
    u8 unused[8];
    TQuestVmDownLoadServer__sub_803EC284(0, 0);
    if (save == (*(Node_803EB0D8 * *)&lbl_805D78A0)) {
        if (arg1 == 0) {
            (*(Node_803EB0D8 * *)&lbl_805D78A0) = save;
            lbl_805D789C = cnt;
            lbl_805D7898 = 0;
            return 0;
        }
        save = NULL;
    }
    for (;;) {
        if (Advance_803EB0D8((*(Node_803EB0D8 * *)&lbl_805D78A0), lbl_805D789C) == save) {
            break;
        }
        (*(Node_803EB0D8 * *)&lbl_805D78A0) = Advance_803EB0D8((*(Node_803EB0D8 * *)&lbl_805D78A0), lbl_805D789C);
        Reload_803EB0D8();
    }
    if (arg0 == 1) {
        TQuestVmDownLoadServer__sub_803EB4D4();
    }
    return 1;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline Node_803EB794 *advance_entry_groups(Node_803EB794 *p, s32 n) {
    while (n-- != 0) {
        while (p->flags & 1) {
            p = p->next;
        }
        p = p->next;
    }
    return p;
}
inline s32 count_fitting_groups(Node_803EB794 *head) {
    Node_803EB794 *p;
    s32 n;
    s32 total;
    s32 limit;
    if (head == NULL) {
        return 0;
    }
    p = head;
    n = total = 0;
    limit = lbl_805D78A4 - 9;
    while (n < 9 && p != NULL) {
        total += TQuestVmDownLoadServer__sub_803EB7C0((Node_803EB7C0 *)p) + 3;
        if (total > limit) {
            break;
        }
        n++;
        while (p->flags & 1) {
            p = p->next;
        }
        p = p->next;
    }
    if (n == 0) {
        return 1;
    }
    return n;
}
s32 TQuestVmDownLoadServer__sub_803EB208(s32 mode, s32 force) {
    Node_803EB794 *save = lbl_805D78A0;
    s32 count;
    lbl_805D78A0 = advance_entry_groups(save, lbl_805D789C);
    count = count_fitting_groups(lbl_805D78A0);
    if (count == 0) {
        if (force == 0) {
            lbl_805D78A0 = save;
            return 0;
        }
        TQuestVmDownLoadServer__sub_803EC284(0, 0);
    } else {
        lbl_805D789C = count;
    }
    lbl_805D7898 = 0;
    if (mode == 1) {
        TQuestVmDownLoadServer__sub_803EB4D4();
    }
    return 1;
}
#pragma pop

s32 count_fitting_entries__22TQuestVmDownLoadServerFPv(Node_803EB328 *arg0) {
    s32 n;
    s32 total;
    s32 lim;
    Node_803EB328 *p;
    if (arg0 == NULL) {
        return 0;
    }
    p = arg0;
    total = 0;
    lim = lbl_805D78A4 - 9;
    n = 0;
    while (n < 9 && p != NULL) {
        total += Len_803EB328(p) + 3;
        if (total > lim) {
            break;
        }
        n++;
        p = Next_803EB328(p);
    }
    if (n == 0) {
        return 1;
    }
    return n;
}
#pragma pop

s32 TQuestVmDownLoadServer__sub_803EB420(s32 start, s32 count, Node_803EB420 *arg2, u16 *buf) {
    s32 n;
    Node_803EB420 *p;
    u8 unused[8];
    if (arg2 == NULL || (arg2->flags & 0x80)) {
        return TQuestVmDownLoadServer__sub_803E6970(start, count, buf, 0);
    }
    p = arg2;
    n = 0;
    for (;;) {
        n += TQuestVmDownLoadServer__sub_803EC95C(buf + n, &p->flags + 1, 6);
        if (!(p->flags & 1)) {
            break;
        }
        p = p->next;
    }
    buf += n;
    return n + TQuestVmDownLoadServer__sub_803E6970((s32)(start + arg2->len), (s32)(count - arg2->len), buf, 0);
}

Node_803EB794 *advance_nodes__22TQuestVmDownLoadServerFPvi(Node_803EB794 *p, s32 n) {
    s32 i;
    for (i = 0; i != n; i++) {
        while (p->flags & 1) {
            p = p->next;
        }
        p = p->next;
    }
    return p;
}

s32 TQuestVmDownLoadServer__sub_803EB7C0(Node_803EB7C0 *arg0) {
    s32 n;
    if (arg0->flags == 0x80) {
        return lbl_805D78EC * 2;
    }
    n = (lbl_805D78EC - arg0->len) * 2;
    while (arg0->flags & 1) {
        n += strlen(arg0->text);
        arg0 = arg0->next;
    }
    return n + strlen(arg0->text);
}

s32 TQuestVmDownLoadServer::count_chain_nodes() {
    Node_803EB844 *p = (Node_803EB844 *)this;
    s32 n = 0;
    while (p != NULL) {
        while (p->flags & 1) {
            p = p->next;
        }
        p = p->next;
        n++;
    }
    return n;
}

Node_803EB878 *TQuestVmDownLoadServer__sub_803EB878(Node_803EB878 *p) {
    while (p->flags & 1) {
        p = p->next;
    }
    return p->next;
}

Node_803EB894 *detach_node_chain__22TQuestVmDownLoadServerFPv(Node_803EB894 *p) {
    Node_803EB894 *next;
    while (p->flags & 1) {
        p = p->next;
    }
    next = p->next;
    p->next = NULL;
    return next;
}

struct Node_803EB8BC { u8 flags; u8 data[5]; u8 len; u8 pad[9]; Node_803EB8BC *next; };

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 Conv_803EB8BC(s32 start, s32 arg1, Node_803EB8BC *arg2, u16 *arg3) {
    s32 n;
    Node_803EB8BC *p;
    u16 *b = arg3;
    s32 lim = arg1;
    u8 unused[8];
    if (arg2 == NULL || (arg2->flags & 0x80)) {
        return TQuestVmDownLoadServer__sub_803E6970(start, lim, b, 0);
    }
    p = arg2;
    n = 0;
    for (;;) {
        n += TQuestVmDownLoadServer__sub_803EC95C(b + n, &p->flags + 1, 6);
        if (!(p->flags & 1)) {
            break;
        }
        p = p->next;
    }
    b += n;
    return n + TQuestVmDownLoadServer__sub_803E6970((s32)(start + arg2->len), (s32)(lim - arg2->len), b, 0);
}
inline s32 Find_803EB8BC(u8 *key, s32 len) {
    s32 l;
    u8 *p;
    for (p = quest_download_text_buffer; p < quest_download_text_write_ptr; p += l) {
        l = *p++;
        if (l == len && strncmp((const char *)p, (const char *)key, l) == 0) {
            return 1;
        }
    }
    return 0;
}
inline void Add_803EB8BC(u8 *key, s32 len) {
    if (quest_download_text_write_ptr + len + 1 <= quest_download_text_buffer + 0x400) {
        *quest_download_text_write_ptr++ = len;
        strncpy((char *)quest_download_text_write_ptr, (const char *)key, len);
        quest_download_text_write_ptr += len;
    }
}
inline Node_803EB8BC *Last_803EB8BC(Node_803EB8BC *p) {
    if (p == NULL) {
        return NULL;
    }
    for (;;) {
        if (p->next == NULL) {
            break;
        }
        p = p->next;
    }
    return p;
}

void append_unique_node__22TQuestVmDownLoadServerFiPvPvPv(s32 start, Node_803EB8BC **headp, Node_803EB8BC **tailp, Node_803EB8BC *n) {
    s32 len;

    len = Conv_803EB8BC(start, lbl_805D78EC, n, lbl_805A0340);
    len = TQuestVmDownLoadServer__sub_803EC71C(lbl_805A0340, (u8 *)lbl_805A02A8, len);
    if (Find_803EB8BC((u8 *)lbl_805A02A8, len)) {
        ((TQuestVmDownLoadServer *)n)->free_node_list();
        return;
    }
    Add_803EB8BC((u8 *)lbl_805A02A8, len);
    if (*headp == NULL) {
        *tailp = n;
        *headp = n;
    } else {
        (*tailp)->next = n;
    }
    *tailp = Last_803EB8BC(n);
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 Conv_803EBA98(s32 start, s32 arg1, Node_803EBA98 *arg2, u16 *arg3) {
    Node_803EBA98 *p;
    s32 n;
    u16 *b = arg3;
    s32 lim = arg1;
    u8 unused[8];
    if (arg2 == NULL || (arg2->flags & 0x80)) {
        return TQuestVmDownLoadServer__sub_803E6970(start, lim, b, 0);
    }
    p = arg2;
    n = 0;
    for (;;) {
        n += TQuestVmDownLoadServer__sub_803EC95C(b + n, &p->flags + 1, 6);
        if (!(p->flags & 1)) {
            break;
        }
        p = p->next;
    }
    b += n;
    return n + TQuestVmDownLoadServer__sub_803E6970((s32)(start + arg2->len), (s32)(lim - arg2->len), b, 0);
}
inline Node_803EBA98 *Next_803EBA98(Node_803EBA98 *p) {
    while (p->flags & 1) {
        p = p->next;
    }
    return p->next;
}
void TQuestVmDownLoadServer__sub_803EBA98(s32 start, Node_803EBA98 *arg1) {
    s32 n;
    s32 len;
    quest_download_text_write_ptr = quest_download_text_buffer;
    while (arg1 != NULL) {
        n = Conv_803EBA98(start, lbl_805D78EC, arg1, lbl_805A0340);
        len = TQuestVmDownLoadServer__sub_803EC71C(lbl_805A0340, quest_download_text_write_ptr + 1, n);
        *quest_download_text_write_ptr++ = len;
        quest_download_text_write_ptr += len;
        arg1 = Next_803EBA98(arg1);
    }
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline Node_803ECD54 *build_entry_text(s32 idx, s32 len, s32 mode) {
    void *first;
    void *tail;
    Src_803EBD38 *src = (Src_803EBD38 *)quest_download_text_buffer;
    src->x0 = 0xFFFF;
    src->x2 = 0;
    src->x4 = 0;
    TQuestVmDownLoadServer__sub_803E6B70(src->text, idx, len, mode);
    return (Node_803ECD54 *)TQuestVmDownLoadServer::build_text_node_chain(src, NULL, len, &first, &tail);
}

void TQuestVmDownLoadServer__sub_803EBC88(s32 mode) {
    Obj_803EADD4 *e = &((Obj_803EADD4 *)quest_download_slot_chain_table)[lbl_805D78F0];
    ((TQuestVmDownLoadServer *)e->xc)->free_node_list();
    e->xc = build_entry_text(lbl_805D78F0, lbl_805D78EC, mode);
}
#pragma pop

struct Tok_803EBEFC { s16 x0; u8 x2; u8 x3; s32 x4; };
struct Arg_803EBEFC { s16 x0; u8 pad[2]; Tok_803EBEFC *tok; };
struct N_803EBEFC {
    u8 flags;
    u8 text[5];
    u8 x6;
    u8 x7;
    s32 x8;
    u16 xc;
    u16 xe;
    N_803EBEFC *next;
};
extern u8 lbl_80596258[];

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline N_803EBEFC *Default_803EBEFC(s32 x) {
    N_803EBEFC *n = (N_803EBEFC *)TQuestVmDownLoadServer__sub_803ECED0();
    if (n != NULL) {
        n->flags = 0x80;
        n->text[0] = 0;
        n->x6 = x;
        n->x7 = 0;
        n->x8 = 0;
        n->xc = 0xFFFF;
        n->next = NULL;
    }
    return n;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 Copy_803EBD38(u8 *dst, u8 *src, s32 max) {
    s32 n = max;
    u8 *s = src;
    u8 *d = dst;
    while (*s != 0 && n > 0) {
        if (TQuestVmDownLoadServer::is_sjis_lead_byte(*s)) {
            if (n <= 1) {
                break;
            }
            *d++ = *s++;
            n--;
        }
        *d++ = *s++;
        n--;
    }
    *d = 0;
    return max - n;
}
#define s ((Src_803EBD38 *)sp)
#define headp ((N_803EBD38 **)hp)
#define tailp ((N_803EBD38 **)tp)
void *TQuestVmDownLoadServer::build_text_node_chain(void *sp, void *a1, s32 a2, void *hp, void *tp) {
    u8 *text;
    s32 rem;
    N_803EBD38 *n;
    N_803EBD38 *m;
    s32 c;
    u8 unused[8];
    text = s->text;
    rem = strlen((const char *)text);
    n = (N_803EBD38 *)TQuestVmDownLoadServer__sub_803ECED0();
    if (n == NULL) {
        return NULL;
    }
    n->flags = 0;
    c = Copy_803EBD38(n->text, text, 4);
    rem -= c;
    n->x6 = a2;
    text += c;
    n->x7 = s->x4;
    n->x8 = (s32)a1;
    n->xc = s->x0;
    n->xe = s->x2;
    n->next = NULL;
    *headp = n;
    while (rem > 0) {
        m = (N_803EBD38 *)TQuestVmDownLoadServer__sub_803ECED0();
        if (m == NULL) {
            ((TQuestVmDownLoadServer *)((Node_803ECD54 *)*headp))->free_node_list();
            return NULL;
        }
        n->flags |= 1;
        m->flags = 2;
        c = Copy_803EBD38(m->text, text, 14);
        rem -= c;
        text += c;
        m->next = NULL;
        n->next = m;
        n = m;
    }
    *tailp = n;
    return *headp;
}
#undef s
#undef headp
#undef tailp
#pragma pop

N_803EBEFC *TQuestVmDownLoadServer__sub_803EBEFC(Arg_803EBEFC *a) {
    s32 count;
    N_803EBEFC *first;
    N_803EBEFC *tl;
    s32 pad;
    N_803EBEFC *head;
    u8 *base;
    Tok_803EBEFC *t;
    N_803EBEFC *tail;
    u8 *p;

    base = lbl_80596258;
    t = a->tok;
    if (t == NULL || t->x0 == 0) {
def:
        return Default_803EBEFC(a->x0);
    }
    if ((u32)t->x4 == 0xFFFFFFFFU) {
        if (t->x2 != 0x1F) {
            goto def;
        }
        if (TQuestVmDownLoadServer__sub_803EEA48((s32)&lbl_805A0470 + lbl_805D78F0, t->x0, base + 0xC, &count) > 0) {
            goto build;
        }
        goto def;
    } else {
        if (TQuestVmDownLoadServer::read_quest_chunk(t->x4, t->x2, t->x3, base + 0xC, &count) <= 0) {
            goto def;
        }
    }
build:
    p = base + 0xC;
    tail = NULL;
    head = NULL;
    while (count > 0) {
        if (TQuestVmDownLoadServer::build_text_node_chain(p, t, t->x0, &first, &tl) == NULL) {
            ((TQuestVmDownLoadServer *)head)->free_node_list();
            return NULL;
        }
        if (head == NULL) {
            head = first;
            tail = tl;
        } else {
            tail->next = first;
            tail = tl;
        }
        p += 5;
        while (*p++ != 0) {
        }
        if ((u32)p & 1) {
            p++;
        }
        count--;
    }
    return head;
}
#pragma pop

struct N_803EC09C {
    u8 flags;
    u8 text[5];
    u8 x6;
    u8 x7;
    s32 x8;
    u16 xc;
    u16 xe;
    N_803EC09C *next;
};
struct Out_803EC09C {
    s16 off; u8 a; u8 b;
    void *src;
    s16 x8; s16 xa;
    Out_803EC09C *next;
};
struct Q_803EC09C {
    Out_803EC09C *o;
    u16 x4;
    u8 pad[2];
    N_803EC09C *x8;
    Q_803EC09C *next;
};
struct Ent_803EC09C {
    s32 x0;
    void *toks;
    Out_803EC09C *list;
    N_803EC09C *xc;
    u8 pad[0xC];
};
Q_803EC09C *TQuestVmDownLoadServer__sub_803ECE94(void);
N_803EC09C *get_next_node__22TQuestVmDownLoadServerFPv(Q_803EC09C *);

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline N_803EC09C *Default_803EC09C(s32 x) {
    N_803EC09C *n = (N_803EC09C *)TQuestVmDownLoadServer__sub_803ECED0();
    if (n != NULL) {
        n->flags = 0x80;
        n->text[0] = 0;
        n->x6 = x;
        n->x7 = 0;
        n->x8 = 0;
        n->xc = 0xFFFF;
        n->next = NULL;
    }
    return n;
}
inline N_803EC09C *Last_803EC09C(N_803EC09C *p) {
    if (p == NULL) {
        return NULL;
    }
    for (;;) {
        if (p->next == NULL) {
            break;
        }
        p = p->next;
    }
    return p;
}

void TQuestVmDownLoadServer__sub_803EC09C(void) {
    s32 idx;
    Ent_803EC09C *e;
    N_803EC09C *tail;
    N_803EC09C *head;
    Out_803EC09C *o;
    Q_803EC09C *qh;
    Q_803EC09C *q;
    Q_803EC09C *qt;
    N_803EC09C *r;
    N_803EC09C *n;

    if ((u32)(o = ((Ent_803EC09C *)quest_download_slot_chain_table)[lbl_805D78F0].list) == 0xFFFFFFFFU) {
        return;
    }
    qh = NULL;
    qt = NULL;
    for (; o != NULL; o = o->next) {
        if (o->off != lbl_805D78EC) {
            continue;
        }
        q = TQuestVmDownLoadServer__sub_803ECE94();
        if (q == NULL) {
            for (; qh != NULL; qh = qh->next) {
                TQuestVmDownLoadServer::push_download_entry((s32 *)qh->x8);
            }
            qh = NULL;
            break;
        }
        q->x8 = r = (N_803EC09C *)TQuestVmDownLoadServer__sub_803EBEFC((Arg_803EBEFC *)o);
        q->o = o;
        q->x4 = (r == NULL) ? 0 : TQuestVmDownLoadServer__sub_803ED0B4((u8 *)o, r->xe);
        q->next = NULL;
        if (qh == NULL) {
            qh = qt = q;
        } else {
            qt->next = q;
            qt = q;
        }
    }
    e = &((Ent_803EC09C *)quest_download_slot_chain_table)[idx = lbl_805D78F0];
    head = e->xc;
    tail = Last_803EC09C(head);
    TQuestVmDownLoadServer__sub_803EBA98(idx, (Node_803EBA98 *)head);
    while ((n = get_next_node__22TQuestVmDownLoadServerFPv(qh)) != NULL) {
        append_unique_node__22TQuestVmDownLoadServerFiPvPvPv(idx, (Node_803EB8BC **)&head, (Node_803EB8BC **)&tail, (Node_803EB8BC *)n);
    }
    if ((n = Default_803EC09C(lbl_805D78EC)) != NULL) {
        append_unique_node__22TQuestVmDownLoadServerFiPvPvPv(idx, (Node_803EB8BC **)&head, (Node_803EB8BC **)&tail, (Node_803EB8BC *)n);
    }
    e->xc = head;
    TQuestVmDownLoadServer__sub_803ECD1C((Node_803ECD1C *)qh);
}
#pragma pop

#pragma push
#pragma opt_dead_assignments off
#pragma dont_inline off
#pragma inline_depth(1)
inline N_803EC09C *Detach_803EBBBC(N_803EC09C *p) {
    N_803EC09C *next;
    while (p->flags & 1) {
        p = p->next;
    }
    next = p->next;
    p->next = NULL;
    return next;
}
N_803EC09C *get_next_node__22TQuestVmDownLoadServerFPv(Q_803EC09C *p) {
    Q_803EC09C *best = NULL;
    N_803EC09C *ret;
    u32 key;
    for (; p != NULL; p = p->next) {
        if (p->x8 != NULL && (best == NULL || p->x4 > key)) {
            best = p;
            key = p->x4;
        }
    }
    if (best == NULL) {
        return NULL;
    }
    ret = best->x8;
    best->x8 = Detach_803EBBBC(ret);
    best->x4 = best->x8 == NULL ? 0 : TQuestVmDownLoadServer__sub_803ED0B4((u8 *)best->o, best->x8->xe);
    return ret;
}
#pragma pop

struct Tok_803EC460 { s16 x0; u8 x2; u8 x3; s32 x4; u16 x8; };
struct Out_803EC460 {
    s16 off; u8 a; u8 b;
    Tok_803EC460 *src;
    s16 x8; s16 xa;
    Out_803EC460 *next;
};
struct N_803EC460 {
    u8 flags;
    u8 text[5];
    u8 x6;
    u8 x7;
    s32 x8;
    u16 xc;
    u16 xe;
    N_803EC460 *next;
};
struct Ent_803EC460 {
    s32 x0;
    void *toks;
    Out_803EC460 *list;
    N_803EC460 *xc;
    u8 pad[0xC];
};

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline N_803EC460 *Default_803EC460(s32 x) {
    N_803EC460 *n = (N_803EC460 *)TQuestVmDownLoadServer__sub_803ECED0();
    if (n != NULL) {
        n->flags = 0x80;
        n->text[0] = 0;
        n->x6 = x;
        n->x7 = 0;
        n->x8 = 0;
        n->xc = 0xFFFF;
        n->next = NULL;
    }
    return n;
}

void TQuestVmDownLoadServer__sub_803EC460(s32 pos, s32 x) {
    N_803EC460 *first;
    N_803EC460 *tl;
    Ent_803EC460 *e;
    u8 *base;
    Out_803EC460 *o;
    Out_803EC460 *best;
    u16 bestv;
    u16 v;
    Tok_803EC460 *t;

    e = &((Ent_803EC460 *)quest_download_slot_chain_table)[pos];
    base = lbl_80596258;
    best = NULL;
    bestv = 0;
    if (e->xc != NULL) {
        return;
    }
    if ((u32)(o = e->list) == 0xFFFFFFFFU) {
def:
        e->xc = Default_803EC460(x);
        return;
    }
    for (; o != NULL; o = o->next) {
        if (o->off != x) {
            continue;
        }
        v = (o->src == NULL) ? 0 : TQuestVmDownLoadServer__sub_803ED0B4((u8 *)o, o->src->x8);
        if (v > bestv || best == NULL) {
            bestv = v;
            best = o;
        }
    }
    if (best == NULL || (t = best->src) == NULL || t->x0 == 0) {
        goto def;
    }
    if ((u32)t->x4 == 0xFFFFFFFFU) {
        if (t->x2 != 0x1F) {
            goto def;
        }
        if (TQuestVmDownLoadServer__sub_803EED0C((s32)&lbl_805A0470 + pos, t->x0, (s32)(base + 0xC)) > 0) {
            goto build;
        }
        goto def;
    } else {
        if (TQuestVmDownLoadServer__sub_803F0048(t->x4, t->x2, t->x3, base + 0xC) <= 0) {
            goto def;
        }
    }
build:
    e->xc = (N_803EC460 *)TQuestVmDownLoadServer::build_text_node_chain(base + 0xC, t, t->x0, &first, &tl);
}
#pragma pop

u16 TQuestVmDownLoadServer::jis_to_sjis(u16 arg0) {
    u8 lo;
    u8 hi;
    hi = arg0 >> 8;
    lo = arg0;
    if (arg0 < 0x2121 || arg0 > 0x7E7E) {
        return 0;
    }
    if (lo < 0x21 || lo >= 0x7F) {
        return 0;
    }
    lo += 0x1F;
    if (hi & 1) {
        hi >>= 1;
    } else {
        hi >>= 1;
        hi--;
        lo += 0x5E;
    }
    if (lo >= 0x7F) {
        lo++;
    }
    if (hi < 0x2F) {
        hi += 0x71;
    } else {
        hi += 0xB1;
    }
    return (hi << 8) | lo;
}

s32 TQuestVmDownLoadServer__sub_803EC69C(u32 arg0) {
    u8 hi;
    u32 lo;
    u32 tr;
    u8 ld;
    hi = ((u16)arg0) >> 8;
    lo = (u8)arg0;
    if (lo < 0x40 || lo > 0xFC || lo == 0x7F) {
        return 0;
    }
    if (hi >= 0xE0) {
        hi -= 0x40;
    }
    ld = ((hi - 0x81) << 1) + 0x21;
    tr = (u8)lo;
    if (tr >= 0x9F) {
        ld++;
        tr = lo - 0x7E;
    } else if (tr >= 0x80) {
        tr = lo - 0x20;
    } else {
        tr = lo - 0x1F;
    }
    return (ld << 8) | (u8)tr;
}

s32 TQuestVmDownLoadServer::is_valid_sjis_code(u16 arg0) {
    s32 var_r0;
    if ((arg0 >= 0x2120U) && (arg0 < 0x3020U)) {
        if ((s32) (arg0 & 0xFF00) == 0x2500) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        if (var_r0 != 0) {
            return 0;
        }
        return 1;
    }
    return 0;
}

s32 TQuestVmDownLoadServer__sub_803EC884(u16 arg0) {
    if (arg0 >= 0x3020U) {
        return 1;
    }
    return 0;
}

s32 TQuestVmDownLoadServer::is_download_command(u16 arg0, s32 arg1) {
    if ((arg1 != 0) && (arg0 == 0x213C)) {
        return 1;
    }
    if ((s32) (arg0 & 0xFF00) == 0x2500) {
        return 1;
    }
    return 0;
}

s32 TQuestVmDownLoadServer__sub_803EC8D8(u16 arg0) {
    s32 temp_r0;
    s32 var_r3;
    u16 var_r4;
    if ((arg0 > 0x20U) && (arg0 < 0x7FU)) {
        var_r3 = 0;
        return 0;
    }
    var_r4 = arg0;
    temp_r0 = arg0 & 0xFF00;
    switch (temp_r0) {
    case 0x2300:
        var_r3 = var_r4 & 0x7F;
        return var_r3;
    case 0x2400:
        var_r3 = (var_r4 & 0x7F) | 0x80;
        return var_r3;
    case 0x2500:
        var_r3 = 0;
        return 0;
    default:
        return TQuestVmDownLoadServer::lookup_value_by_key(arg0);
    }
}

s32 TQuestVmDownLoadServer__sub_803EC95C(u16 *out, u8 *text, int attr) {
    u16 *dst = out;
    u8 c;
    while ((c = *text) != 0) {
        if (c < 0x80 || (c >= 0xA0 && c < 0xE0)) {
            dst += TQuestVmDownLoadServer::encode_char_with_attr(dst, *text++, attr);
        } else {
            u16 ch = (c << 8) | text[1];
            dst += TQuestVmDownLoadServer::encode_char_with_attr(dst, ch, attr);
            text += 2;
        }
    }
    return dst - out;
}

void TQuestVmDownLoadServer__sub_803ECA1C(u16 *arg0, s32 arg1, s32 arg2) {
    u16 a = arg2 << 12;
    while (arg1-- != 0) {
        *arg0 = (*arg0 & 0xFFF) | a;
        arg0++;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
inline s32 IsLead_803ECAE8(u32 c) {
  if (((c < 0x81) || (c > 0xFC)) || ((c >= 0xA0) && (c < 0xE0)))
  {
    return 0;
  }
  return 1;
}

inline s32 IsTrail_803ECAE8(u8 c) {
  if (((c < 0x40) || (c > 0xFC)) || (c == 0x7F))
  {
    return 0;
  }
  return 1;
}

inline s32 IsSjis_803ECAE8(s32 lo, s32 hi) {
  if (IsLead_803ECAE8(hi) == 0)
  {
    return 0;
  }
  return IsTrail_803ECAE8(lo);
}

inline s32 IsJis_803ECAE8(u8 c) {
  s32 r = 0;
  if ((c >= 0x21) && (c <= 0x7E))
  {
    r = 1;
  }
  return r;
}

inline s32 IsJisPair_803ECAE8(s32 lo, s32 hi) {
  s32 r = 0;
  if (IsJis_803ECAE8(hi) && IsJis_803ECAE8(lo))
  {
    r = 1;
  }
  return r;
}

inline s32 Kind_803ECAE8(u16 c, s32 lo) {
  switch (c & 0xFF00)
  {
    case 0x8000:

    case 0x8500:
      return 1;

    case 0x8600:
      if (lo < 0x9E)
    {
      return 1;
    }
      break;

  }

  return 2;
}

s32 TQuestVmDownLoadServer::encode_char_with_attr(u16 *out, u16 ch, s32 attr) {
  s32 hi;
  u16 c;
  s32 lo;
  int new_var;
  u16 a;
  c = ch;
  a = (attr & 0xF) << 12;
  new_var = ch & 0xFF;
  hi = (ch >> 8) & 0xFF;
  lo = new_var;
  if (IsSjis_803ECAE8(new_var, hi))
  {
    if (Kind_803ECAE8(c, new_var) == 1)
    {
      a |= 0x300;
    }
    else
    {
      a |= 0x700;
    }
  }
  else
    if (IsJisPair_803ECAE8(new_var, hi))
  {
    a |= 0x500;
    if (ch == 0x2474)
    {
      ch = 0x2574;
    }
  }
  else
  {
    *out = a | lo;
    return 1;
  }
  *(out++) = a | (ch >> 8);
  *out = (a + 0x100) | (ch & 0xFF);
  return 2;
}

#pragma pop

s32 TQuestVmDownLoadServer__sub_803ECC7C(u32 arg0) {
    u8 hi = (arg0 >> 8) & 0xFF;
    u8 lo = arg0;
    s32 lead;
    if (hi < 0x81 || hi > 0xFC || (hi >= 0xA0 && hi < 0xE0)) {
        lead = 0;
    } else {
        lead = 1;
    }
    if (lead == 0) {
        return 0;
    }
    if (lo < 0x40 || lo > 0xFC || lo == 0x7F) {
        return 0;
    }
    return 1;
}

s32 TQuestVmDownLoadServer::is_sjis_lead_byte(u8 arg0) {
    if ((arg0 < 0x81U) || (arg0 > 0xFCU) || ((arg0 >= 0xA0U) && (arg0 < 0xE0U))) {
        return 0;
    }
    return 1;
}

void TQuestVmDownLoadServer__sub_803ECD1C(Node_803ECD1C *p) {
    while (p != NULL) {
        Node_803ECD1C *next = p->next;
        if (p != NULL) {
            *(s32 *)p = (long)(*(s32 * *)&lbl_805D78B0);
            (*(s32 * *)&lbl_805D78B0) = (s32 *)p;
            lbl_805D78AC += 1;
        }
        p = next;
    }
}

void TQuestVmDownLoadServer::free_node_list() {
    Node_803ECD54 *p = (Node_803ECD54 *)this;
    while (p != NULL) {
        Node_803ECD54 *next = p->next;
        if (p != NULL) {
            *(s32 *)p = (long)(*(s32 * *)&lbl_805D78B0);
            (*(s32 * *)&lbl_805D78B0) = (s32 *)p;
            lbl_805D78AC += 1;
        }
        p = next;
    }
}

void TQuestVmDownLoadServer__sub_803ECD8C(Node_803ECD8C *p) {
    Node_803ECD8C *next;
    while (p != NULL) {
        next = p->next;
        if (p != NULL) {
            p->link = lbl_805D78B0;
            lbl_805D78B0 = (s32 *)p;
            lbl_805D78AC += 1;
        }
        p = next;
    }
}

void release_node_chain__22TQuestVmDownLoadServerFPv(Node_803ECDC4 *p) {
    u32 prev = 0xFFFFFFFF;
    Node_803ECDC4 *next;
    while (p != NULL) {
        next = p->next;
        if ((prev == 0xFFFFFFFF || p->id != prev) && p->id != 0xFFFFFFFF) {
            TQuestVmDownLoadServer__sub_803EED9C(p->id);
        }
        prev = p->id;
        if (p != NULL) {
            p->link = (*(s32 * *)&lbl_805D78B0);
            (*(s32 * *)&lbl_805D78B0) = (s32 *)p;
            lbl_805D78AC += 1;
        }
        p = next;
    }
}

void TQuestVmDownLoadServer__sub_803ECE5C(Node_803ECE5C *p) {
    Node_803ECE5C *next;
    while (p != NULL) {
        next = p->next;
        if (p != NULL) {
            p->link = lbl_805D78B0;
            lbl_805D78B0 = (s32 *)p;
            lbl_805D78AC += 1;
        }
        p = next;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 *pop_free_block() {
    s32 *p = lbl_805D78B0;
    if (p == NULL) {
        return NULL;
    }
    lbl_805D78B0 = (s32 *)*lbl_805D78B0;
    lbl_805D78AC--;
    return p;
}

Q_803EC09C *TQuestVmDownLoadServer__sub_803ECE94(void) {
    s32 *p = pop_free_block();
    if (p == NULL) {
        return NULL;
    }
    return (Q_803EC09C *)p;
}

void *TQuestVmDownLoadServer__sub_803ECED0(void) {
    s32 *p = pop_free_block();
    if (p == NULL) {
        return NULL;
    }
    return p;
}

void *TQuestVmDownLoadServer__sub_803ECF0C(void) {
    s32 *p = pop_free_block();
    if (p == NULL) {
        return NULL;
    }
    return p;
}

void *TQuestVmDownLoadServer__sub_803ECF48(void) {
    s32 *p = pop_free_block();
    if (p == NULL) {
        return NULL;
    }
    return p;
}

Node_803EA384 *TQuestVmDownLoadServer__sub_803ECF84(void) {
    s32 *p = pop_free_block();
    if (p == NULL) {
        return NULL;
    }
    return (Node_803EA384 *)p;
}
#pragma pop

void TQuestVmDownLoadServer::push_download_entry(s32 *arg0) {
    if (arg0 != NULL) {
        *arg0 = (long) (lbl_805D78B0);
        lbl_805D78B0 = arg0;
        lbl_805D78AC += 1;
    }
}

struct Blk_803ECFE4 { Blk_803ECFE4 *next; u8 pad[0x10]; };
Blk_803ECFE4 quest_download_block_pool[2000];
extern s32 quest_download_free_list_ready_flag;
void TQuestVmDownLoadServer::init_block_free_list() {
    Blk_803ECFE4 *p;
    if (quest_download_free_list_ready_flag == 0 && lbl_805D78AC == 2000) {
        return;
    }
    lbl_805D78B0 = (s32 *)quest_download_block_pool;
    for (p = quest_download_block_pool; p < &quest_download_block_pool[1999]; p++) {
        p->next = p + 1;
    }
    p->next = NULL;
    lbl_805D78AC = 2000;
    quest_download_free_list_ready_flag = 0;
}

typedef char RecoveredGlobal_803EE2E4_lbl_8058DC98_size[sizeof(RecoveredGlobal_803EE2E4_lbl_8058DC98) == 0x50 ? 1 : -1];

u16 TQuestVmDownLoadServer__sub_803ED0B4(u8 *arg0, u16 arg1) {
    struct Fields_arg0 { u8 pad_0[8]; u16 field_8; };
    if (arg1 != 0) {
        return arg1 + 0x3E8;
    }
    return ((Fields_arg0*)arg0)->field_8;
}

struct Sub_803ED26C { s16 x0; u8 x2; };
struct Arg_803ED26C { s16 x0; u8 pad[2]; Sub_803ED26C *x4; };

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 InRange_803ED26C(u8 v) {
    s32 r = 0;
    if (v >= 1 && v <= 0xD) {
        r = 1;
    }
    return r;
}

s32 TQuestVmDownLoadServer::calc_item_cost_bonus(u8 kind, u8 v, u8 w, s32 base, s32 add) {
    s32 r = 0;
    switch (kind) {
    case 0:
        if ((v >= 0x14 && v <= 0x19) || v == 0x32) {
            r = 0xF;
        }
        break;
    case 1:
        if (v == 0x1A) {
            r = 0x14;
        }
        break;
    case 2:
        if ((u8)(v - 0x1B) <= 1) {
            r = 0xF;
        }
        break;
    case 3:
        if (v == 0x1F || v == 0x38) {
            r = 0x14;
        }
        break;
    case 4:
        if (v == 0x16) {
            r = 0x14;
        }
        break;
    case 5:
        if (w == 0xFF) {
            if (v >= 1 && v <= 0xD) {
                r = 0xF;
            }
        } else if ((v >= 0x80 && v <= 0x8B && w == 4) || (v == 0xD && w == 0)) {
            r = 0xF;
        }
        break;
    case 6:
        if (v >= 0x14 && v <= 0x19) {
            r = 0xF;
        } else if (v == 0x1F || v == 0x38) {
            r = 0x14;
        }
        break;
    case 7:
        if (v == 0x1D) {
            r = 0xF;
        }
        break;
    case 8:
        if ((v >= 0x14 && v <= 0x19) || (v >= 1 && v <= 0xD)) {
            r = 0x14;
        }
        break;
    }
    if (r == 0) {
        return base;
    }
    return base + r + add;
}

s32 TQuestVmDownLoadServer::calc_item_entry_cost(u8 k, u8 v, s32 base) {
    Arg_803ED26C *a = (Arg_803ED26C *)this;
    s32 lvl = 0;
    Sub_803ED26C *s = a->x4;

    if (s != NULL && ((s->x2 >= 0x14 && s->x2 <= 0x19) || s->x2 == 0x32)) {
        lvl = 1;
        if (s->x0 + 1 == a->x0) {
            lvl = 2;
        }
    }
    if (k == 0xC7) {
        if (InRange_803ED26C(v)) {
            return base + 0x1E;
        }
        return base + 0x19;
    }
    if (k == 0xC8) {
        if (v == 0) {
            return base;
        }
        if (lvl == 2) {
            return base + 0x14;
        }
        return base + 5;
    }
    if (k == 0xC1 || k == 0xE1) {
        if (lvl == 2) {
            base += 5;
        }
        return base;
    }
    if ((u8)(k - 0xC4) <= 1 || (k >= 0xCE && k <= 0xD1)) {
        if ((v >= 1 && v <= 0xD) || (v >= 0x16 && v <= 0x17)) {
            return base + 5;
        }
        return base;
    }
    if (k == 0xC2) {
        if (v == 0) {
            return base;
        }
        if (lvl == 2) {
            base += 3;
        }
        return base;
    }
    if (k >= 0xFC && k <= 0xFD && v >= 1 && v <= 0x17) {
        return base + 0x12;
    }
    if ((k == 0xFA || k == 0xFE) && v >= 0x14 && v <= 0x18) {
        return base + 0x12;
    }
    return base;
}
#pragma pop


s32 TQuestVmDownLoadServer::calc_pair_cost_bonus(u8 arg0, u8 arg1, s32 arg2) {
    if (arg0 >= 0x14 && arg0 <= 0x18) {
        if (arg1 >= 0x14 && arg1 <= 0x18) {
            return arg2 + 3;
        }
        return arg2;
    }
    if (arg0 == 0x1F && arg1 == 0x1F) {
        return arg2 + 0xF;
    }
    if (arg0 == 0x21 || arg0 == 0x26 || arg0 == 0x27) {
        return arg2 + 0x14;
    }
    if (arg0 == 0x20 || arg0 == 0x22) {
        return arg2 + 0xF;
    }
    if (arg0 == 0x1B && arg1 == 0x1C) {
        return arg2 + 0x14;
    }
    if (arg0 == 0x1A && arg1 == 0x1A) {
        return arg2 + 5;
    }
    return arg2;
}

s32 TQuestVmDownLoadServer::calc_item_entry_cost_extra(u8 arg0, u8 arg1, u8 arg2, s32 arg3) {
    if ((arg0 == 0xD) && (arg1 == 0)) {
        if ((arg2 >= 1U) && (arg2 <= 0x17U)) {
            return arg3 + 3;
        }
    } else if ((arg1 >= 4U) && (arg1 <= 6U) && (arg2 >= 1U) && (arg2 <= 0x17U)) {
        if ((arg0 == 0x8D) || ((arg0 == 0x8E) && (arg1 == 6))) {
            return arg3 + 0xA;
        }
        if (arg0 <= 0x8CU) {
            return arg3 + 3;
        }
    } else if ((arg1 == 8) && (arg2 >= 0x14U) && (arg2 <= 0x18U)) {
        if (((arg0 >= 0x80U) && (arg0 <= 0x8EU)) || (arg0 == 0x92) || (arg0 == 0x94) || (arg0 == 0xA0) || (arg0 == 0xA2) || ((u8)(arg0 - 0xAE) <= 1U) || (arg0 == 0xB1) || (arg0 == 1) || ((arg0 >= 0xAU) && (arg0 <= 0xCU))) {
            return arg3 + 0xF;
        }
        return arg3 + 3;
    }
    return arg3;
}

struct Sub_803ED63C { s16 x0; u8 x2; u8 x3; s32 x4; };
struct Arg_803ED63C { s16 x0; u8 x2; u8 x3; Sub_803ED63C *x4; };

s32 calc_entry_cost__22TQuestVmDownLoadServerFPvPv(Arg_803ED63C *a, Arg_803ED63C *b) {
    Sub_803ED63C *s2;
    u8 k;
    u8 bk;
    s32 extra;
    Sub_803ED63C *s;
    u8 q;
    u8 p;

    extra = 0;
    p = 0;
    q = 0;
    if ((k = a->x2) >= 0x2D && k <= 0x38) {
        p = a->x3;
    } else {
        q = a->x3;
    }
    if (b == NULL) {
        bk = 0;
    } else if ((s = b->x4) == NULL) {
        bk = 0;
    } else {
        if ((bk = s->x2) == 0x28) {
            return 0;
        }
        if (bk == 0x29 || (bk == 0x19 && s->x0 > 0) || (bk == 0x1F && (u32)s->x4 == 0xFFFFFFFFU)) {
            extra = 0x14;
        }
    }
    if ((s2 = a->x4) != NULL) {
        if (s2->x2 == 0x19 && s2->x0 == 0) {
            extra += 10;
        } else if (s2->x2 <= 0x19 || s2->x2 >= 0x1F) {
            extra += 1;
        }
    }
    if (q != 0 || k == 0xD) {
        return TQuestVmDownLoadServer::calc_item_entry_cost_extra(k, q, bk, extra);
    }
    if (k == 0x2D) {
        return TQuestVmDownLoadServer::calc_item_cost_bonus(p, bk, 0xFF, extra, 0);
    }
    if (bk >= 0x32 && bk <= 0x38) {
        if (b->x4 != NULL) {
            p = b->x4->x3;
        } else {
            p = 0;
        }
        return TQuestVmDownLoadServer::calc_item_cost_bonus(p, k, q, extra, 2);
    }
    if (k >= 0x14 && k < 0xC0) {
        return TQuestVmDownLoadServer::calc_pair_cost_bonus(k, bk, extra);
    }
    if (k >= 0xC0) {
        return ((TQuestVmDownLoadServer *)a)->calc_item_entry_cost(k, bk, extra);
    }
    return extra;
}

struct N_803ED7F0 { s16 a; u8 kind; u8 pad0; N_803ED7F0 *link; u8 pad1[2]; s16 timer; N_803ED7F0 *next; };
struct T_803ED7F0 { u8 pad[8]; N_803ED7F0 *head; u8 pad2[0x10]; };

#pragma push
#pragma opt_common_subs off
void TQuestVmDownLoadServer::reset_slot_chain_timers(s32 arg0) {
    N_803ED7F0 *n;
    N_803ED7F0 *l;
    T_803ED7F0 *t = &((T_803ED7F0 *)quest_download_slot_chain_table)[arg0];
    for (n = t->head; n != NULL; n = n->next) {
        n->timer = 0;
        l = n->link;
        if (l != NULL && l->kind == 0x19 && l->a == 0) {
            n->timer = 10;
        }
    }
}
#pragma pop

s32 TQuestVmDownLoadServer__sub_803ED84C(void *, s32, s32);

#pragma push
#pragma opt_common_subs off

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
inline s32 IsSpecial_803ED9AC(Elem_803ED9AC *e) {
    if (e->sub != NULL && (e->sub->type == 0x28 || e->sub->type == 0x29)) {
        return 1;
    }
    return 0;
}
inline void Relax_803ED9AC(Elem_803ED9AC *best, s32 idx, s32 max) {
    Elem_803ED9AC *q;
    s32 v;
    s32 n = best->len;
    if (best->kind == 0xFF || idx + n >= max) {
        return;
    }
    q = quest_download_slot_chain_table[idx + n].head;
    if (q == NULL) {
        return;
    }
    for (; q != NULL; q = q->next) {
        q->base = 0;
        if (!IsSpecial_803ED9AC(q)) {
            v = calc_entry_cost__22TQuestVmDownLoadServerFPvPv((Arg_803ED63C *)best, (Arg_803ED63C *)q);
            if (v > 0) {
                q->base = v;
            }
        }
    }
}
s16 TQuestVmDownLoadServer::select_best_slot_entry(s32 idx, s32 max, s32 want) {
    Slot_803ED9AC *slot = &quest_download_slot_chain_table[idx];
    Elem_803ED9AC *e;
    Elem_803ED9AC *best;
    Elem_803ED9AC *q;
    for (e = slot->head; e != NULL; e = e->next) {
        if (want < 0 || e->len == want) {
            if (TQuestVmDownLoadServer__sub_803ED84C((void *)e, idx, max) == -1) {
                return -1;
            }
        }
    }
    if (slot == NULL || slot->head == NULL) {
        return -1;
    }
    best = slot->head;
    for (q = best->next; q != NULL; q = q->next) {
        if (q->cost > best->cost) {
            best = q;
        }
    }
    Relax_803ED9AC(best, idx, max);
    return best->len;
}
#pragma pop
#pragma pop

s32 TQuestVmDownLoadServer__sub_803EDB20(u8 arg0) {
    return lbl_8047F8B8[arg0] & 0x20;
}

s32 TQuestVmDownLoadServer__sub_803EDB3C(u8 arg0) {
    return lbl_8047F8B8[arg0] & 0x40;
}

s32 TQuestVmDownLoadServer__sub_803EDB58(u8 arg0) {
    return lbl_8047F8B8[arg0] & 0x80;
}

s32 TQuestVmDownLoadServer__sub_803EDB74(u8 arg0) {
    return lbl_8047F8B8[arg0] & 0xC0;
}

s32 TQuestVmDownLoadServer::sum_entry_sizes(s32 start, s32 n) {
    Ent_803EDB90 *e = &((Ent_803EDB90 *)&quest_download_entry_table)[start];
    s32 sum = 0;
    s32 i;
    for (i = n; i > 0; i--) {
        sum += e->size;
        e++;
    }
    return sum;
}

u8 *TQuestVmDownLoadServer::find_keyword_entry(u16 *start, u16 *end) {
    u8 c;
    u8 *p;
    u16 *s;
    s32 rem;
    s32 len;
    s32 n;
    len = end - start;
    p = quest_download_keyword_table;
    while (*p != 0) {
        n = *p++;
        if (len == n) {
            s = start;
            for (rem = len; rem > 0;) {
                c = *s++;
                if (c >= 0x61U && c <= 0x7AU) {
                    c -= 0x20;
                }
                if (*p != c) {
                    break;
                }
                rem--;
                p++;
            }
            if (rem == 0) {
                return p;
            }
            p += rem;
        } else {
            p += n;
        }
        while (*p++ != 0) {
        }
    }
    return NULL;
}

void TQuestVmDownLoadServer__sub_803EE2E4(void) {
    lbl_8058DC98.value = 0;
}

u16 *TQuestVmDownLoadServer__sub_803EE718(s32 i, s32 len) {
    u16 *out;
    s32 n;
    s32 end;
    s32 r;
    Node_803EB794 *node;
    out = lbl_805A0340;
    end = i + len;
    while (i < end && (n = TQuestVmDownLoadServer__sub_803E9F54(i)) != 0) {
        if (i == lbl_805D78F0) {
            if (lbl_805D78E8 == 1 || lbl_805D7834 >= 3) {
                node = advance_nodes__22TQuestVmDownLoadServerFPvi(lbl_805D78A0, lbl_805D7898);
            } else {
                node = advance_nodes__22TQuestVmDownLoadServerFPvi(*(Node_803EB794 **)((s8 *)((u8 *)quest_download_slot_chain_table + i * 0x1C) + 0xC), 0);
            }
            r = TQuestVmDownLoadServer__sub_803EB420(i, n, (Node_803EB420 *)node, out);
        } else {
            r = TQuestVmDownLoadServer__sub_803EB420(i, n, (Node_803EB420 *)*(Node_803EB794 **)((s8 *)((u8 *)quest_download_slot_chain_table + i * 0x1C) + 0xC), out);
        }
        out += r;
        i += n;
    }
    TQuestVmDownLoadServer__sub_803EC71C((u16 *)lbl_805A0340, (u8 *)lbl_805A02A8, (s32)(out - lbl_805A0340));
    return lbl_805A02A8;
}

u8 *TQuestVmDownLoadServer__sub_803EE828(void) {
    TQuestVmDownLoadServer__sub_803EC71C((u16 *)(((u8 *)&lbl_805A0340)), (u8 *)(((u8 *)&lbl_805A02A8)), (s32)(TQuestVmDownLoadServer__sub_803EE934()));
    return ((u8 *)&lbl_805A02A8);
}

s32 TQuestVmDownLoadServer__sub_803EE934(void) {
    s32 r;
    Node_803EB794 *node;
    u16 *out;
    s32 total;
    s32 i;
    s32 n;
    out = lbl_805A0340;
    i = 0;
    total = 0;
    while ((n = TQuestVmDownLoadServer__sub_803E9F54(i)) != 0) {
        if (i == lbl_805D78F0) {
            if (lbl_805D78E8 == 1 || lbl_805D7834 >= 3) {
                node = advance_nodes__22TQuestVmDownLoadServerFPvi(lbl_805D78A0, lbl_805D7898);
            } else {
                node = advance_nodes__22TQuestVmDownLoadServerFPvi(*(Node_803EB794 **)((s8 *)((u8 *)quest_download_slot_chain_table + i * 0x1C) + 0xC), 0);
            }
            r = TQuestVmDownLoadServer__sub_803EB420(i, n, (Node_803EB420 *)node, out);
            lbl_805D78EC = n;
            TQuestVmDownLoadServer__sub_803ECA1C(out, r, 7);
        } else {
            r = TQuestVmDownLoadServer__sub_803EB420(i, n, *(Node_803EB420 **)((s8 *)((u8 *)quest_download_slot_chain_table + i * 0x1C) + 0xC), out);
            TQuestVmDownLoadServer__sub_803ECA1C(out, r, 6);
        }
        out += r;
        i += n;
        total += r;
    }
    return total;
}

s32 TQuestVmDownLoadServer__sub_803EEA48(s32 arg0, s32 arg1, void *arg2, s32 *arg3) {
    s32 i;
    void *r;
    if (lbl_805D7904 == -1) {
        return -3;
    }
    *arg3 = 0;
    r = format_number_text__22TQuestVmDownLoadServerFiiPvi(arg0, arg1, arg2, lbl_805D78FC);
    if (r != 0) {
        arg2 = r;
        (*arg3)++;
    }
    for (i = 0; i < 4; i++) {
        if (i != lbl_805D78FC) {
            r = format_number_text__22TQuestVmDownLoadServerFiiPvi(arg0, arg1, arg2, i);
            if (r != 0) {
                arg2 = r;
                (*arg3)++;
            }
        }
    }
    return 1;
}

struct Tbl_803EEB10 {
    u8 units[0x14];
    u8 fullwidth_digits[0x18];
    u8 kanji_digits[0x18];
    u8 *sets[2];
    u8 *units_text;
};
struct Out_803EEB10 {
    u16 mode;
    s16 x2;
    u8 x4;
    u8 text[1];
};
extern Tbl_803EEB10 quest_download_number_text_table;

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 IsSmall_803EEB10(s32 d) {
    s32 r = 0;
    if (d >= 1 && d <= 3) {
        r = 1;
    }
    return r;
}

#define n ((s16)arg1)
void *format_number_text__22TQuestVmDownLoadServerFiiPvi(s32 arg0, s32 arg1, void *arg2, s32 mode) {
    u8 *s = (u8 *)arg0;
    Out_803EEB10 *o = (Out_803EEB10 *)arg2;
    Tbl_803EEB10 *t = &quest_download_number_text_table;
    s32 u;
    u8 **mp;
    u8 **up;
    u8 *p;
    u8 *mark;
    s32 i;
    s32 pos;
    s32 d;
    s32 rem;
    s32 set;

    if (mode >= 2 && n > 0xD) {
        return NULL;
    }
    o->mode = mode;
    o->x2 = 0;
    o->x4 = 0;
    p = o->text;
    mp = (u8 **)((u8 *)t->sets + mode * 4);
    mark = p;
    up = &t->units_text;
    for (i = 0; i < n; i++, s++) {
        d = *s - '0';
        if (mode < 2) {
            *p++ = (*mp)[d * 2];
            *p++ = (*mp)[d * 2 + 1];
            continue;
        }
        rem = n - i - 1;
        pos = rem % 4;
        if (d != 0 && !(mode == 2 && d == 1 && (u32)(pos - 1) <= 1)) {
            set = IsSmall_803EEB10(d) ? mode - 1 : 1;
            *p++ = (*(u8 **)((u8 *)t->sets + set * 4))[d * 2];
            *p++ = (*(u8 **)((u8 *)t->sets + set * 4))[d * 2 + 1];
        }
        if (rem == 0) {
            continue;
        }
        if (pos == 0 && mark == p) {
            continue;
        }
        if (pos != 0 && d == 0) {
            continue;
        }
        if (pos == 0) {
            u = rem / 4 + 6;
        } else if (pos == 1) {
            if (mode == 2) {
                u = 4;
            } else {
                u = 0;
            }
        } else {
            u = pos + 3;
        }
        *p++ = (*up)[u * 2];
        *p++ = (*up)[u * 2 + 1];
        if (pos == 0) {
            mark = p;
        }
    }
    if (p == o->text) {
        return NULL;
    }
    *p = 0;
    return p + 1;
}
#undef n
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs off
inline u32 Call_803EED0C(s32 a, s32 b, s32 c, s32 d) {
    return ((u32)format_number_text__22TQuestVmDownLoadServerFiiPvi((s32)a, (s32)b, (void *)c, (s32)d));
}
s32 TQuestVmDownLoadServer__sub_803EED0C(s32 arg0, s32 arg1, s32 arg2) {
    if (lbl_805D7904 == -1) {
        return -3;
    }
    if (Call_803EED0C(arg0, arg1, arg2, lbl_805D78FC) == 0) {
        Call_803EED0C(arg0, arg1, arg2, 0);
    }
    return 1;
}
#pragma pop

s32 TQuestVmDownLoadServer::get_download_state() {
    return lbl_805D7900;
}

s32 TQuestVmDownLoadServer__sub_803EED9C(u32 arg0) {
    TQuestVmDownLoadServer::release_ref_slot(arg0);
    return 3;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline void release_index_entries(s32 *ids, s32 n) {
    s32 i;
    s32 a;
    s32 b;
    s32 c;
    for (i = 0; i < n; i++) {
        s32 page = TQuestVmDownLoadServer__sub_803E779C(ids[i], &a, &b, &c);
        if (page != -1) {
            if (a != -1) {
                TQuestVmDownLoadServer__sub_803EF8E0(get_cached_page__22TQuestVmDownLoadServerFi(page) + a);
                TQuestVmDownLoadServer::set_active();
            }
            if (b != -1) {
                TQuestVmDownLoadServer__sub_803EF8E0(TQuestVmDownLoadServer::get_buffer_ptr(b));
                TQuestVmDownLoadServer__sub_803E8918();
            }
        }
    }
}
inline s32 is_digit_string(u8 *s) {
    for (; *s != 0; s++) {
        if (*s < 0x30 || *s > 0x39) {
            return 0;
        }
    }
    return 1;
}
s32 TQuestVmDownLoadServer__sub_803EEDC0(Req_803EEF2C *req, s32 *ids, s32 n) {
    char buf[0x50];
    s32 v;
    if (lbl_805D7900 == 0) {
        return 3;
    }
    if (lbl_805D7904 == -1) {
        return -3;
    }
    strncpy(buf, req->name, req->len);
    buf[req->len] = 0;
    if (is_digit_string((u8 *)buf)) {
        req->x7 = 0x1F;
    }
    v = ((TQuestVmDownLoadServer *)ids)->get_max_size_of_indices(n) + 1;
    if (v == 0xFF) {
        release_index_entries(ids, n);
        v = 1;
    }
    TQuestVmDownLoadServer__sub_803E8DA0(buf, req, v);
    TQuestVmDownLoadServer::set_slot_values_for_indices(ids, n, v);
    return 3;
}
#pragma pop

s32 TQuestVmDownLoadServer__sub_803EEF2C(Req_803EEF2C *arg0) {
    char buf[0x50];
    if (lbl_805D7900 == 0) {
        return 3;
    }
    if (lbl_805D7904 == -1) {
        return -3;
    }
    strncpy(buf, arg0->name, arg0->len);
    if (arg0->x7 == 0x28 || arg0->x7 == 0x29) {
        arg0->x7 = 0x27;
    }
    buf[arg0->len] = 0;
    TQuestVmDownLoadServer__sub_803E8DA0(buf, arg0, 1);
    return 3;
}

inline u8 *skip_entry_text(u8 *p, u8 *end) {
    for (; p < end; p += 2) {
        if (*p <= 0x38) {
            break;
        }
    }
    return p;
}

inline void shift_bytes(u8 *p, u8 *end, s32 delta) {
    u8 *s;
    if (delta > 0) {
        for (s = end - 1; p <= s; s--) {
            s[delta] = *s;
        }
    } else if (delta < 0) {
        for (; p < end; p++) {
            p[delta] = *p;
        }
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
s32 TQuestVmDownLoadServer__sub_803EEFC8(u8 *rec, Req_803EEF2C *msg) {
    s32 len;
    s32 size;
    u8 *data;
    u8 *end;
    u8 *start;
    u8 *text;
    s32 d;
    s32 n;
    u8 buf[0x80];
    TQuestVmDownLoadServer::copy_sjis_string(msg->text, buf);
    len = TQuestVmDownLoadServer::calc_sjis_string_width(msg->text);
    buf[len] = 0;
    data = rec;
    size = (u16)(rec[0] + (rec[1] << 8));
    end = rec + size;
    rec = rec + 3 + rec[2];
    while ((start = rec) < end) {
        rec += 2;
        if (*rec <= 0xB) {
            rec++;
        }
        text = rec;
        rec = skip_entry_text(rec, end);
        n = rec - text;
        if (start[0] == msg->x7 && n == len && strncmp((char *)text, (char *)buf, n) == 0) {
            break;
        }
    }
    d = rec - start;
    if (d > 0) {
        if (start == data + 3 + data[2] && rec == end) {
            return -1;
        }
        shift_bytes(rec, end, -d);
        data[0] = (size - d) % 256;
        data[1] = (size - d) / 256;
    }
    return d;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
inline void shift_tail_bytes(u8 *p, u8 *end, s32 delta) {
    if (delta > 0) {
        for (end--; p <= end; end--) {
            end[delta] = *end;
        }
    } else if (delta < 0) {
        for (; p < end; p++) {
            p[delta] = *p;
        }
    }
}

inline s32 max_entry_index(u8 *rec) {
    s32 max = 0;
    u8 *end = rec + (u16)(rec[0] + (rec[1] << 8));
    u8 *p = rec + 3 + rec[2];
    while (p < end) {
        if (max < p[1]) {
            max = p[1];
        }
        p += 2;
        if (*p <= 0xB) {
            p++;
        }
        p = skip_entry_text(p, end);
    }
    return max;
}

s32 TQuestVmDownLoadServer__sub_803EF538(Msg_803E9190 *msg) {
    u8 *end;
    u8 *page;
    u8 *p;
    s32 is_new = 1;
    u8 n;
    s32 c;
    s32 len;
    s32 size;
    char buf[0x50];
    if (lbl_805D7904 == -1) {
        return -3;
    }
    if (lbl_805D78F8 == 0x8000) {
        return -6;
    }
    strncpy(buf, msg->name, msg->len);
    buf[msg->len] = 0;
    page = get_cached_page__22TQuestVmDownLoadServerFi(((TQuestVmDownLoadServer *)buf)->find_name_index());
    for (end = page; (size = (u16)(end[0] + (end[1] << 8))) != 0; end += size) {
    }
    for (p = page; p < end; p += (u16)(p[0] + (p[1] << 8))) {
        n = p[2];
        c = strncmp((const char *)(p + 3), buf, (s16)n);
        if (c == 0) {
            if ((s16)n == msg->len) {
                is_new = 0;
                break;
            }
        } else if (c > 0) {
            break;
        }
    }
    len = is_new ? ((TQuestVmDownLoadServer *)msg)->calc_message_length() : ((TQuestVmDownLoadServer *)msg)->calc_text_length();
    if (end > page + 0x3FE - len) {
        return -5;
    }
    if (is_new) {
        shift_tail_bytes(p, end + 2, len);
        build_message_packet__22TQuestVmDownLoadServerFPviPvUc(p, len, msg, 0);
        if (msg->len <= 2) {
            TQuestVmDownLoadServer__sub_803E7F9C((u8 *)buf, msg->len);
        }
    } else {
        shift_tail_bytes(p + (u16)(p[0] + (p[1] << 8)), end + 2, len);
        append_message_text__22TQuestVmDownLoadServerFPviPvUc(p, len, (Msg_803E90A8 *)msg, max_entry_index(p) + 1);
    }
    TQuestVmDownLoadServer__sub_803E79AC();
    TQuestVmDownLoadServer::set_active();
    return 3;
}
#pragma pop

void TQuestVmDownLoadServer__sub_803EF8E0(u8 *p) {
    u8 *end = p + (u16)(p[0] + (p[1] << 8));
    p = p + 3 + p[2];
    while (p < end) {
        p[1] = 0;
        p += 2;
        if (*p <= 0xB) {
            p++;
        }
        for (; p < end; p += 2) {
            if (*p <= 0x38) {
                break;
            }
        }
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
s32 TQuestVmDownLoadServer__sub_803EF958(u32 id, u16 key, s32 *ids, s32 n) {
    s32 page;
    u8 *base;
    u8 *p;
    u16 off;
    if (lbl_805D7900 == 0) {
        return 3;
    }
    if (lbl_805D7904 == -1) {
        return -3;
    }
    if (id == 0xFFFFFFFF && key <= 3) {
        lbl_805D78FC = key;
        release_index_entries(ids, n);
        TQuestVmDownLoadServer::set_slot_values_for_indices(ids, n, 0);
        return 3;
    }
    {
        s32 a;
        s32 b;
        s32 v;
        page = TQuestVmDownLoadServer__sub_803E779C(id, &a, &b, &v);
        if (page == -1) {
            return 0;
        }
        off = key;
        if (key & 0x8000) {
            if (b == -1) {
                return 0;
            }
            base = TQuestVmDownLoadServer::get_buffer_ptr(b);
        } else {
            if (a == -1) {
                return 0;
            }
            base = get_cached_page__22TQuestVmDownLoadServerFi(page) + a;
        }
        v = ((TQuestVmDownLoadServer *)ids)->get_max_size_of_indices(n);
        p = base + (off & ~0x8000) + 1;
        if (*p != 0 && *p == v) {
            if (key & 0x8000) {
                TQuestVmDownLoadServer__sub_803E8924(b);
                TQuestVmDownLoadServer__sub_803E8918();
            }
            return 3;
        }
        if (++v == 0xFF) {
            release_index_entries(ids, n);
            v = 1;
        }
        *p = v;
        if (key & 0x8000) {
            TQuestVmDownLoadServer__sub_803E8924(b);
            TQuestVmDownLoadServer__sub_803E8918();
        } else {
            TQuestVmDownLoadServer::set_active();
        }
        TQuestVmDownLoadServer::set_slot_values_for_indices(ids, n, v);
        return 3;
    }
}
#pragma pop

u8 *TQuestVmDownLoadServer::find_insert_position(s32 key, s32 n, s32 len) {
    u8 *p = (u8 *)this;
    u8 *end = p + len;
    u8 *s;
    u8 *d;
    while (p < end) {
        if (*(u16 *)(p + 2) < key) {
            break;
        }
        p += 5;
        while (*p++ != 0) {
        }
        if ((u32)p & 1) {
            p++;
        }
    }
    if (p < end) {
        for (s = end - 1; s >= p; s--) {
            s[n] = *s;
        }
    }
    return p;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
void TQuestVmDownLoadServer__sub_803EFCB4(u8 *data, s32 key, s32 sub_key, s32 *cnt, s32 *total, u8 *buf, s32 flags) {
    u8 *p;
    u8 *end;
    u8 *rec;
    s32 size;
    u8 *text;
    Src_803EBD38 *out;
    s32 sub;
    s32 value;
    u8 unused[8];
    end = data + (u16)(data[0] + (data[1] << 8));
    p = data + 3 + data[2];
    while (p < end) {
        rec = p;
        value = p[1];
        p += 2;
        if (*p <= 0xB) {
            sub = *p;
            p++;
        } else {
            sub = 0;
        }
        if (key == rec[0] && sub_key == sub) {
            size = TQuestVmDownLoadServer::count_entries_until_terminator(p, end) + 6;
            if (size & 1) {
                size++;
            }
            out = (Src_803EBD38 *)((TQuestVmDownLoadServer *)buf)->find_insert_position(value, size, *total);
            out->x0 = flags | (rec - data);
            text = rec + 2;
            out->x2 = rec[1];
            out->x4 = 0;
            if (rec[2] <= 0xB) {
                text++;
            }
            TQuestVmDownLoadServer::unescape_copy_string(out->text, text, end);
            *total += size;
            (*cnt)++;
        }
        p = skip_entry_text(p, end);
    }
}
#pragma pop

s32 TQuestVmDownLoadServer::read_quest_chunk(u32 id, u8 a1, u8 a2, u8 *buf, s32 *out) {
    s32 a;
    s32 b;
    s32 cnt;
    s32 total;
    s32 r;
    s32 v;
    if (lbl_805D7904 == -1) {
        return -3;
    }
    r = TQuestVmDownLoadServer__sub_803E779C(id, &a, &b, &cnt);
    if (r == -1) {
        return 0;
    }
    cnt = 0;
    total = 0;
    if (a != -1) {
        TQuestVmDownLoadServer__sub_803EFCB4(get_cached_page__22TQuestVmDownLoadServerFi(r) + a, a1, a2, &cnt, &total, buf, 0);
    }
    if (b != -1) {
        TQuestVmDownLoadServer__sub_803EFCB4(TQuestVmDownLoadServer::get_buffer_ptr(b), a1, a2, &cnt, &total, buf, 0x8000);
    }
    v = cnt;
    *out = v;
    if (v == 0) {
        return 0;
    }
    return 1;
}

void TQuestVmDownLoadServer__sub_803EFF20(u8 *data, s32 key, s32 sub_key, s32 *best, u8 *dst, s32 flags) {
    u8 *p;
    u8 *rec;
    u8 *end;
    u8 *found;
    u8 *text;
    Src_803EBD38 *out;
    u8 unused[8];
    s32 start_best;
    s32 sub;
    s32 value;
    start_best = *best;
    end = data + (u16)(data[0] + (data[1] << 8));
    p = data + 3 + data[2];
    while (p < end) {
        rec = p;
        value = p[1];
        p += 2;
        if (*p <= 0xB) {
            sub = *p;
            p++;
        } else {
            sub = 0;
        }
        if (key == rec[0] && sub_key == sub && value > *best) {
            found = rec;
            *best = value;
        }
        for (; p < end; p += 2) {
            if (*p <= 0x38) {
                break;
            }
        }
    }
    if (*best > start_best) {
        out = (Src_803EBD38 *)dst;
        out->x0 = flags | (found - data);
        text = found + 2;
        out->x2 = found[1];
        out->x4 = 0;
        if (found[2] <= 0xB) {
            text++;
        }
        TQuestVmDownLoadServer::unescape_copy_string(out->text, text, end);
    }
}

s32 TQuestVmDownLoadServer__sub_803F0048(s32 id, u8 a1, u8 a2, void *dst) {
    s32 a;
    s32 b;
    s32 c;
    s32 best;
    s32 page;
    if (lbl_805D7904 == -1) {
        return -3;
    }
    page = TQuestVmDownLoadServer__sub_803E779C(id, &a, &b, &c);
    if (page == -1) {
        return 0;
    }
    best = -1;
    if (a != -1) {
        TQuestVmDownLoadServer__sub_803EFF20(get_cached_page__22TQuestVmDownLoadServerFi(page) + a, a1, a2, &best, (u8 *)dst, 0);
    }
    if (b != -1) {
        TQuestVmDownLoadServer__sub_803EFF20(TQuestVmDownLoadServer::get_buffer_ptr(b), a1, a2, &best, (u8 *)dst, 0x8000);
    }
    if (best == -1) {
        return 0;
    }
    return 1;
}

s32 find_symbol_entry__22TQuestVmDownLoadServerFPvsPv(const char *name, s16 len, Info_803F0138 *out) {
    u8 n;
    u8 *base;
    u8 *p;
    s32 id;
    s32 c;
    if (len <= 2 && ((TQuestVmDownLoadServer *)name)->is_char_allowed(len) != 0) {
        out->off = -1;
        return 0;
    }
    id = ((TQuestVmDownLoadServer *)name)->find_name_index();
    {
        u8 *get_cached_page__22TQuestVmDownLoadServerFi(void);
        base = get_cached_page__22TQuestVmDownLoadServerFi();
    }
    p = base;
    while ((u16)(p[0] + (p[1] << 8)) != 0) {
        n = p[2];
        c = strncmp((const char *)(p + 3), name, (s16)n);
        if (c == 0) {
            if ((s16)n == len) {
                break;
            }
        } else if (c > 0) {
            out->off = -1;
            return 0;
        }
        p += (u16)(p[0] + (p[1] << 8));
    }
    if ((u16)(p[0] + (p[1] << 8)) == 0) {
        out->off = -1;
        return 0;
    }
    out->id = id;
    out->off = p - base;
    out->p = p;
    return 1;
}

s32 TQuestVmDownLoadServer__sub_803F0268(const char *name, s16 len, Out_803F0268 *out) {
    char buf[0x50];
    Info_803F0138 i1;
    Info_803F0138 i2;
    s32 max;
    s32 r1;
    s32 r2;
    u32 r;
    if (lbl_805D7904 == -1) {
        return -3;
    }
    strncpy(buf, name, len);
    buf[len] = 0;
    r1 = find_symbol_entry__22TQuestVmDownLoadServerFPvsPv(buf, len, &i1);
    r2 = lookup_name_entry__22TQuestVmDownLoadServerFPvsPv((char *)(buf), len, (Out_803E8B1C *)(&i2));
    if (r1 == 0 && r2 == 0) {
        return 0;
    }
    out->len = len;
    out->len2 = len;
    out->xa = 1;
    out->count = 0;
    max = 0;
    if (r1 == 1) {
        out->count = TQuestVmDownLoadServer__sub_803F03B4(i1.p, out->ents, 0, &max);
    }
    if (r2 == 1) {
        out->count = TQuestVmDownLoadServer__sub_803F03B4(i2.p, out->ents, out->count, &max);
    }
    out->x4 = r = TQuestVmDownLoadServer::acquire_slot_entry(i1.id, i1.off, i2.off, max);
    if (r == 0xFFFFFFFF) {
        return 0;
    }
    return 1;
}

s32 TQuestVmDownLoadServer__sub_803F0500(u8 *name, s16 len, Out_803E8C2C *out) {
    s16 blen;
    s16 cnt;
    s16 pre;
    s32 idx;
    s32 first;
    u8 *page;
    u8 *p;
    u8 *found;
    u8 n;
    first = 1;
    out->pre = 0;
    out->len = 0;
    idx = ((TQuestVmDownLoadServer *)name)->find_name_index();
    if (((TQuestVmDownLoadServer *)idx)->has_name_mismatch(name) == 0) {
        return 2;
    }
    pre = 0;
    for (;;) {
        page = get_cached_page__22TQuestVmDownLoadServerFi(idx);
        p = page;
        cnt = TQuestVmDownLoadServer::count_matching_name_prefix(idx, name);
        blen = 0;
        for (; (u16)(p[0] + (p[1] << 8)) != 0; p += (u16)(p[0] + (p[1] << 8))) {
            s16 m;
            s32 r;
            Ent_803E8C2C *e = (Ent_803E8C2C *)p;
            n = e->len;
            m = TQuestVmDownLoadServer::match_prefix_length((u8 *)e->name, name, (s16)n);
            if (m >= pre) {
                pre = m + 1;
            }
            r = strncmp(e->name, (char *)name, (s16)n);
            if (r == 0) {
                if ((s16)n == len && first) {
                    return 2;
                }
                blen = n;
                found = p;
            } else if (r > 0) {
                if (strncmp(e->name, (char *)name, len) == 0 && first) {
                    return 2;
                }
                break;
            }
        }
        if (blen > 0) {
            break;
        }
        if (cnt <= 1) {
            out->id = -1;
            return 0;
        }
        len = cnt - 1;
        name[len] = 0;
        idx = ((TQuestVmDownLoadServer *)name)->find_name_index();
        first = 0;
    }
    out->a = idx;
    out->id = found - page;
    out->len = blen;
    out->pre = pre;
    out->ent = (Ent_803E8C2C *)found;
    return 1;
}

s32 TQuestVmDownLoadServer__sub_803F06B8(const char *name, s16 len, Out_803F0268 *out) {
    char buf[0x50];
    Out_803E8C2C o1;
    Out_803E8C2C o2;
    s32 max;
    s32 r1;
    s32 r2;
    s32 n;
    u32 r;
    if (lbl_805D7904 == -1) {
        return -3;
    }
    strncpy(buf, name, len);
    buf[len] = 0;
    r1 = TQuestVmDownLoadServer__sub_803F0500((u8 *)buf, len, &o1);
    if (r1 == 2) {
        return 2;
    }
    strncpy(buf, name, len);
    buf[len] = 0;
    r2 = TQuestVmDownLoadServer__sub_803E8C2C(buf, len, &o2);
    if (r2 == 2) {
        return 2;
    }
    if (r1 == 0 && r2 == 0) {
        return 0;
    }
    out->xa = 1;
    max = 0;
    out->len2 = o1.pre > o2.pre ? o1.pre : o2.pre;
    if (o1.len > o2.len) {
        out->len = o1.len;
        out->count = TQuestVmDownLoadServer__sub_803F03B4((u8 *)o1.ent, out->ents, 0, &max);
        o2.id = -1;
    } else if (o1.len < o2.len) {
        out->len = o2.len;
        out->count = TQuestVmDownLoadServer__sub_803F03B4((u8 *)o2.ent, out->ents, 0, &max);
        o1.id = -1;
    } else {
        out->len = o1.len;
        n = TQuestVmDownLoadServer__sub_803F03B4((u8 *)o1.ent, out->ents, 0, &max);
        out->count = TQuestVmDownLoadServer__sub_803F03B4((u8 *)o2.ent, out->ents, n, &max);
    }
    out->x4 = r = TQuestVmDownLoadServer::acquire_slot_entry(o1.a, o1.id, o2.id, max);
    if (r == 0xFFFFFFFF) {
        return 0;
    }
    return 1;
}

s32 TQuestVmDownLoadServer__sub_803F0890(void) {
    if ((s32) lbl_805D7904 == -1) {
        return -3;
    }
    TQuestVmDownLoadServer__sub_803E8150();
    TQuestVmDownLoadServer__sub_803E9764();
    TQuestVmDownLoadServer::retry_seek_active_entries();
    if (TQuestVmDownLoadServer__sub_803E86C8() == -1) {
        return -2;
    }
    return 3;
}

s32 TQuestVmDownLoadServer__sub_803F08E4(s8 *quest_vm_down_load_server) {
    s32 r;

    if (lbl_805D7904 != -1) {
        return -4;
    }
    if (*quest_vm_down_load_server == 0) {
        return -1;
    }
    ((TQuestVmDownLoadServer *)quest_vm_down_load_server)->set_file_info_name();
    r = TQuestVmDownLoadServer::find_file_info_index();
    if (r != 0) {
        if (r == -1) {
            return -7;
        }
        return -8;
    }
    if (TQuestVmDownLoadServer::read_ask_header() == -1) {
        TQuestVmDownLoadServer__sub_803E86C8();
        return -2;
    }
    if (TQuestVmDownLoadServer__sub_803E8084() == -1) {
        TQuestVmDownLoadServer__sub_803E86C8();
        return -2;
    }
    TQuestVmDownLoadServer::init_page_cache();
    __VIRetraceHandler();
    if (lbl_805D78F8 == 0x8000) {
        return -6;
    }
    return 3;
}

s32 TQuestVmDownLoadServer__sub_803F09A4(void) {
    s32 var_r3;
    lbl_805D7834 = 0;
    quest_download_initialized = 1;
    lbl_805D7908 = 0;
    lbl_805D790C = 0;
    var_r3 = dispatch_request_0x20__19TWindowKeyBoardSoftFll(&lbl_805E10D8, &lbl_805E10E0);
    if (var_r3 == 0) {
        var_r3 = dispatch_request_0x1c__19TWindowKeyBoardSoftFv();
    }
    if (var_r3 > 0) {
        var_r3 = -1;
    }
    return var_r3;
}

s32 TQuestVmDownLoadServer__sub_803F09FC(void *arg0, int arg1, int arg2) {
    s32 r;
    switch (arg2) {
    case 0:
        if (arg1 < 0) {
            return -1;
        }
        lbl_805D7914.remain = lbl_805D7910 - arg1;
        lbl_805D7914.pos = arg1;
        break;
    case 1:
        r = lbl_805D7914.remain - arg1;
        if (r < 0 || (u32)r > lbl_805D7910) {
            return -1;
        }
        lbl_805D7914.remain = r;
        lbl_805D7914.pos += arg1;
        break;
    case 2:
        if (arg1 > 0) {
            return -1;
        }
        lbl_805D7914.remain = -arg1;
        arg1 = lbl_805D7910 + arg1;
        lbl_805D7914.pos = arg1 - 1;
        break;
    }
    return lbl_805D7914.pos;
}

u32 TQuestVmDownLoadServer::aram_dma_read(void *h, void *dst, int size) {
    u32 n;
    u32 len;
    u32 start;
    u8 *base;
    base = quest_download_aram_dma_buffer;
    n = lbl_805D7914.remain;
    if ((u32)lbl_805D7914.remain >= (u32)size) {
        n = size;
    }
    len = n;
    if (n & 3) {
        len = (n | 3) + 1;
    }
    DCInvalidateRange(base + 0x40, 0x2000);
    (*(u32 *)&quest_download_aram_dma_pending) = 1;
    ARQPostRequest(base + 0x2040, lbl_805D7924, 1, lbl_805D7920, lbl_805D792C + lbl_805D7914.pos,
                   (u32)(base + 0x40), len, TQuestVmDownLoadServer__sub_803F0BE8);
    start = OSGetTick();
    for (;;) {
        if ((*(u32 *)&quest_download_aram_dma_pending) == 0) {
            memcpy(dst, base + 0x40, n);
            break;
        }
        if (OSGetTick() - start > lbl_805D791C) {
            (*(u32 *)&quest_download_aram_dma_pending) = 0;
            ARQRemoveRequest(base + 0x2040);
            OSReport(aram_dma_timeout_message);
            return -1;
        }
    }
    lbl_805D7914.remain -= n;
    lbl_805D7914.pos += n;
    return n;
}

s32 TQuestVmDownLoadServer__sub_803F0BD8(void * _w0) {
    return 0;
}

s32 TQuestVmDownLoadServer__sub_803F0BE0(void * _w0, void * _w1) {
    return 1;
}

void TQuestVmDownLoadServer__sub_803F0BE8(u8 *arg0) {
    if ((u32) *(u32 *)((s8 *)arg0 + 4) == (u32) lbl_805D7924) {
        quest_download_aram_dma_pending = 0;
    }
}

void TQuestVmDownLoadServer__sub_803F0C04(u32 aram_addr, s32 size, u32 owner, u32 priority, u32 timeout_ms) {
    lbl_805D792C = aram_addr;
    lbl_805D7914.remain = size;
    lbl_805D7914.pos = 0;
    lbl_805D7924 = owner;
    lbl_805D7910 = lbl_805D7914.remain;
    lbl_805D7920 = priority;
    lbl_805D791C = timeout_ms * (__OSBusClock / 4 / 1000);
}

__declspec(section ".rodata") const char ask_header_signature[] = "ASK Copyright (C) ACCESS CO.,LTD.";
}

u16 lbl_805A02A8[0x4C];
u16 lbl_805A0340[0x98];
RecoveredGlobal_803E6ACC_lbl_805A0470 lbl_805A0470;
RecoveredGlobal_803E6ACC_lbl_805A0498 quest_download_entry_table;
RecoveredGlobal_803E6ACC_lbl_805A05D0 lbl_805A05D0;
u8 lbl_805A0698[0x28];
u8 quest_download_aram_dma_buffer[0x2060];
