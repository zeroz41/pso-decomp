#ifndef PSO_QUEST_QUESTDOWNLOADSERVER_H
#define PSO_QUEST_QUESTDOWNLOADSERVER_H

// Record types and data shared by the three quest download server TUs (_803E6970, _803E8918, _803E9A24).

#include "types.h"
#include "pso/quest/TQuestVmDownLoadServer_803E6970.h"
#include "pso/quest/TQuestVmDownLoadServer.h"

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

struct Node_803EB794 { u8 flags; u8 data[5]; u8 len; u8 pad[9]; Node_803EB794 *next; };

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

struct Sub_803ED9AC;

struct Node_803EB420 {
    u8 flags;
    u8 data[5];
    u8 len;
    u8 pad7;
    Sub_803ED9AC *sub;
    u16 key;
    u8 padE[2];
    Node_803EB420 *next;
};

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

typedef Req_803EEF2C Msg_803E90A8;

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

struct Seg_803E9FFC { s16 off; u8 x2; u8 x3; u8 a; u8 b; u8 pad2[2]; Seg_803E9FFC *next; };

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


struct Buf_803E82AC {
    u8 name[0x3CBC];
    u8 hdr[0x400];
};

struct Ent_803E9DE0 { u8 a; u8 b; u8 off; u8 d; };

typedef Req_803EEF2C Msg_803E9190;

struct Ent_803E8B1C { u8 pad[2]; u8 len; char name[1]; };

struct Node_803E8B1C { Ent_803E8B1C *ent; Node_803E8B1C *next; };

struct Out_803E8C2C { s16 a; s16 id; s16 len; s16 pre; u8 pad[4]; Ent_803E8B1C *ent; };

typedef Out_803E8C2C Out_803E8B1C;

// Name cache: eight 0x400-byte record pages (lbl_80591EC8), then the hash buckets (lbl_80593EC8)
// and the free-list node pool that __VIRetraceHandler links up.
struct NameCache_80591EC8 {
    u8 pages[8][0x400];
};

struct NameHash_80593EC8 {
    Node_803E8B1C *hash[0x50];
    Node_803E8B1C nodes[0x200];
};

// lbl_80591EC8 and lbl_80593EC8 seen as the one area they form: three functions address both from one base.
struct NameCacheArea_80591EC8 {
    NameCache_80591EC8 cache;
    NameHash_80593EC8 names;
};

struct Ent_803E7ACC {
    s32 index;
    s32 state;
    Ent_803E7ACC *next;
};

extern "C" {
extern u8 lbl_8058DC98[0x50];
extern RecoveredGlobal_803E6ACC_lbl_805A0470 quest_download_scratch_storage;
extern RecoveredGlobal_803E6ACC_lbl_805A0498 quest_download_entry_table;
extern RecoveredGlobal_803E6ACC_lbl_805A05D0 quest_download_buffer_storage;
extern s32 quest_download_state;
extern s32 lbl_805D7848;
extern s32 *lbl_805D78B8;
extern s32 *lbl_805D78BC;
extern s32 quest_text_end;
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
extern NameCache_80591EC8 lbl_80591EC8;
extern u8 lbl_805D7868;
struct Sub_803ED9AC { u8 pad[2]; u8 type; u8 x3; u32 id; };
struct Elem_803ED9AC {
    s16 len;
    u8 kind;
    u8 pad3;
    Sub_803ED9AC *sub;
    u16 cost;
    u16 base;
    Elem_803ED9AC *next;
};
struct Slot_803ED9AC {
    u8 pad[8];
    Elem_803ED9AC *head;
    Node_803EB794 *chain;
    u8 pad10[5];
    s8 x15;
    s8 x16;
    u8 pad17[5];
};
extern Slot_803ED9AC quest_download_slot_chain_table[];
extern const u8 lbl_8047F8B8[0x100];
extern RecoveredGlobal_803E721C_lbl_8047E698 single_byte_to_jis_table;
s32 strcpy(void *, void *);
s32 dispatch_request_0x20__19TWindowKeyBoardSoftFll(void *, void *);
s32 dispatch_request_0x1c__19TWindowKeyBoardSoftFv();
extern s32 quest_download_initialized;
extern s32 quest_download_state;
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
s32 TQuestVmDownLoadServer__sub_803EC95C(u16 *, const u8 *, int);
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
void append_message_text__22TQuestVmDownLoadServerFPviPvUc(u8 *arg0, s32 arg1, Req_803EEF2C *arg2, u8 arg3);
u32 strlen(const char *);
extern s32 lbl_805D78A4;
extern s32 quest_text_entry_len;
s32 count_fitting_entries__22TQuestVmDownLoadServerFPv(Node_803EB328 *arg0);
s32 TQuestVmDownLoadServer__sub_803EC71C(u16 *, u8 *, s32);
extern u8 quest_download_text_buffer[];
extern u16 lbl_805A0340[];
extern u8 *quest_download_text_write_ptr;
void TQuestVmDownLoadServer__sub_803EBA98(s32 arg0, Node_803EBA98 *arg1);
extern u16 lbl_805A02A8[];
extern s32 quest_page_node_index;
extern Node_803EB794 *lbl_805D78A0;
extern s32 lbl_805D78E8;
extern s32 quest_text_cursor_pos;
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
extern s32 quest_page_node_count;
s32 TQuestVmDownLoadServer__sub_803EB7C0(Node_803EB7C0 *arg0);
void release_node_chain__22TQuestVmDownLoadServerFPv(Node_803ECDC4 *p);
s32 TQuestVmDownLoadServer__sub_803F03B4(u8 *data, Ent_803F03B4 *ents, s32 n, s32 *max);
s32 TQuestVmDownLoadServer__sub_803F0268(const char *name, s16 len, Out_803F0268 *out);
s32 TQuestVmDownLoadServer__sub_803E7390(u8 a, u8 b, u8 c);
extern u8 lbl_80596258[];
extern u8 lbl_805D7894[4];
extern const u8 lbl_805E10D0[2];
s32 TQuestVmDownLoadServer__sub_803EC884(u16 arg0);
s32 TQuestVmDownLoadServer__sub_803EDB20(u8 arg0);
s32 TQuestVmDownLoadServer__sub_803EDB3C(u8 arg0);
s32 TQuestVmDownLoadServer__sub_803EDB58(u8 arg0);
s32 TQuestVmDownLoadServer__sub_803EDB74(u8 arg0);
s32 TQuestVmDownLoadServer__sub_803EED9C(u32 arg0);
s32 TQuestVmDownLoadServer__sub_803F06B8(const char *name, s16 len, Out_803F0268 *out);
void TQuestVmDownLoadServer__sub_803ECA1C(u16 *arg0, s32 arg1, s32 arg2);
Seg_803E9FFC *TQuestVmDownLoadServer__sub_803E9A74(s32, s32, u8, u8);
void *TQuestVmDownLoadServer__sub_803ECF48(void);
void *TQuestVmDownLoadServer__sub_803E9FFC(s32 arg0, s32 arg1, Tok_803E9FFC *t);
void *TQuestVmDownLoadServer__sub_803ECED0(void);
void *TQuestVmDownLoadServer__sub_803ECF0C(void);
extern u8 *file_page_cache_head;
extern NameHash_80593EC8 lbl_80593EC8;
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
void build_message_packet__22TQuestVmDownLoadServerFPviPvUc(u8 *arg0, s32 arg1, Req_803EEF2C *arg2, u8 arg3);
s32 lookup_name_entry__22TQuestVmDownLoadServerFPvsPv(char *arg0, s16 arg1, Out_803E8C2C *arg2);
extern u8 lbl_8047E898[];
extern u16 lbl_8047E8A4[];
void TQuestVmDownLoadServer__sub_803EFCB4(u8 *data, s32 a1, s32 a2, s32 *cnt, s32 *total, u8 *buf, s32 flags);
extern u8 *lbl_805D7824;

typedef char RecoveredGlobal_803E6ACC_lbl_805A0470_size[sizeof(RecoveredGlobal_803E6ACC_lbl_805A0470) == 0x28 ? 1 : -1];
typedef char RecoveredGlobal_803E6ACC_lbl_805A0498_size[sizeof(RecoveredGlobal_803E6ACC_lbl_805A0498) == 0x138 ? 1 : -1];
typedef char RecoveredGlobal_803E6ACC_lbl_805A05D0_size[sizeof(RecoveredGlobal_803E6ACC_lbl_805A05D0) == 0xC8 ? 1 : -1];
struct Ent_803E6B70 { u16 ch; u16 pad; s32 len; };
void TQuestVmDownLoadServer__sub_803E79AC(void);
void TQuestVmDownLoadServer__sub_803E7F9C(u8 *text, s16 mode);
}

#endif
