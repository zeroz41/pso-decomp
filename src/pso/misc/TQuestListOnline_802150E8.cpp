#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/system/main_loop.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/TMainTask.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestListOnline.h"
#include "pso/misc/TDLGraph.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_802155B4_TQuestListOnline__data_80513DE8 {
    s32 value;
    u8 remaining[0x38];
};

struct RecoveredGlobal_802155B4_TQuestListOnline__data_80513E24 {
    s32 value;
    u8 remaining[0x38];
};

struct RecoveredGlobal_80215498_TQuestListOnline__data_80513DE8 {
    s32 value;
    u8 remaining[0x38];
};

struct RecoveredGlobal_80215498_TQuestListOnline__data_80513E24 {
    s32 value;
    u8 remaining[0x38];
};

struct RecoveredGlobal_80215ABC_lbl_804CA0B8 {
    s32 value;
    u8 remaining[0x24];
};

struct Pair_802156E0 { s8 key; u8 val; };

struct G_802156E0 { u8 pad[0xc]; Pair_802156E0 *tbl; };

struct Pair_802156A0 { s8 key; u8 val; };

struct G_802156A0 { u8 pad[0x10]; Pair_802156A0 *tbl; };

struct Ent_8021587C { u8 id; u8 n1; u8 n2; };

struct Tbl_8021587C { Ent_8021587C *base; s32 count; };

struct G_8021587C { u8 pad[4]; Tbl_8021587C *t; };

struct Item_8021587C { u8 pad[3]; u8 f3; };

struct Ent_8021599C { u8 id; u8 n1; u8 n2; };

struct Tbl_8021599C { Ent_8021599C *base; s32 count; };

struct G_8021599C { Tbl_8021599C *t; };

struct Obj_8021599C { u8 pad[4]; u8 slot; };

struct G_802156E0;
struct Ent_80215720 { u8 id; u8 n1; u8 n2; };

struct Tbl_80215720 { Ent_80215720 *base; s32 count; };

struct G_80215720 { u8 pad[8]; Tbl_80215720 *t; };

struct Obj_80215720 { u8 pad[7]; s8 a; u8 p8; s8 b; u8 pa; s8 c; };

struct Ctr_80215720 { u8 buf[0x68]; };

struct Pair_802150E8 { s32 a; s32 b; };

struct Slot_802150E8 { char name[0x34]; s32 size; void *buf; };

struct Ent_802150E8 { u8 pad[0x28]; char name[0x10]; s32 size; };

struct Pair_80215380 { s32 a; s32 b; };

extern "C" {
void TQuestListOnline__sub_8013ACF4(s32);
s32 memcpy(int, void *, int);
extern u32 TQuestListOnline__quest_list_buffer;
int memset(void*, void*, void*);
extern unsigned char TQuestListOnline__dat_download_state[];
extern unsigned char TQuestListOnline__bin_download_state[];
extern s32 TQuestListOnline__selected_quest_info;
extern int TQuestListOnline__bin_download_complete;
extern int TQuestListOnline__dat_download_complete;
extern int TQuestListOnline__download_window;
extern int TQuestListOnline__quest_info_window;
extern int TQuestListOnline__download_barrier_window;
extern int quest_download_active;
extern s32 TQuestListOnline__instance;
void mem_free(void *p);
extern RecoveredGlobal_80215ABC_lbl_804CA0B8 section_id_favored_grind_table;
extern s32 lbl_805D6238;
extern G_802156E0 *item_appraisal_rules;
u8 lookup_key_value__6TLobbyFc(s8 x);
s32 is_rare_item__9TItemDataFPv(Item_8021587C *);
u8 get_entry_field16__9TItemDataFv(Item_8021587C *);
void shuffle_shop_pool_n_times(void *, s32);
void push_shop_pool_entry(void *, u8);
extern s8 lbl_8044BD30[];
extern s32 item_appraisal_favored_weapon;
extern s32 item_appraisal_score;
void adjust_appraisal_special(Obj_8021599C *obj);
void adjust_appraisal_percentages(Obj_80215720 *arg0);
void *mem_alloc(u32 size);
}
s32 get_guild_text(s32);
extern "C" {
int update_window_mode_from_progress__6TLobbyFPv(s32, Pair_802150E8 *);
s32 get_window_layout_position(s32);
char *strtok(char *, const char *);
s32 strncmp(const char *, const char *, u32);
char *strncpy(char *, const char *, u32);
extern Pair_802150E8 lbl_8044BCC0[];
extern s32 local_client_id;
extern int quest_download_received_bytes;
extern int quest_download_graph_current_bytes;
extern const f32 lbl_805DC664;
extern char lbl_805DC668[4];
extern char lbl_805DC66C[4];
extern char lbl_805DC670[4];
extern char lbl_805DC674[4];
s32 THunterGuildSeqOffline__sub_80212074();
int create__14TWindowMessageFllUls(s32, Pair_80215380 *, s32, s32);
extern Pair_80215380 lbl_8044BCB8[];
extern const f32 lbl_805DC678;

void TQuestListOnline::begin_file_download() {
    Ent_802150E8 *arg0 = (Ent_802150E8 *)this;
    Pair_802150E8 p;
    char buf[0x10];
    char *tok;
    Slot_802150E8 *s;
    if ((u32) TQuestListOnline__download_window == 0U) {
        p.a = lbl_8044BCC0[0].a;
        p.b = lbl_8044BCC0[0].b;
        TQuestListOnline__download_window = update_window_mode_from_progress__6TLobbyFPv(get_window_layout_position(0x2C), &p);
        ((TWindowMessage *)TQuestListOnline__download_window)->append_line(get_guild_text(0x14), 1);
        ((TWindowMessage *)TQuestListOnline__download_window)->complete_reveal();
        ((TWindowBase *)TQuestListOnline__download_window)->set_depth(lbl_805DC664);
        main_task.begin_frame();
        ((TMainTask *)((u8 *)&main_task))->run_tl_camera_tasks();
        main_task.render();
        main_task.render_screen_overlay();
        render_tick();
        main_task.begin_frame();
        ((TMainTask *)((u8 *)&main_task))->run_tl_camera_tasks();
        main_task.render();
        main_task.render_screen_overlay();
        render_tick();
        main_task.begin_frame();
        ((TMainTask *)((u8 *)&main_task))->run_tl_camera_tasks();
        main_task.render();
        main_task.render_screen_overlay();
        render_tick();
        ((TWindowCtrl *)local_client_id)->suppress_slot();
        main_task.toggle_pause_layers();
        quest_download_active = 1;
        quest_download_received_bytes = 0;
        quest_download_graph_current_bytes = 0;
    }
    if (arg0 == NULL) {
        return;
    }
    memset(buf, 0, (void *)0x10);
    strncpy(buf, arg0->name, 0x10);
    if (strtok(buf, lbl_805DC668) == NULL) {
        return;
    }
    tok = strtok(NULL, lbl_805DC66C);
    if (tok == NULL) {
        return;
    }
    if (strncmp(tok, lbl_805DC670, 4) == 0) {
        s = (Slot_802150E8 *)TQuestListOnline__dat_download_state;
        if (s->buf == NULL) {
            strncpy(s->name, arg0->name, 0x10);
            ((Slot_802150E8 *)TQuestListOnline__dat_download_state)->size = arg0->size;
            s->buf = mem_alloc(arg0->size);
            memset(s->buf, 0, (void *)arg0->size);
            TQuestListOnline__dat_download_complete = 0;
            quest_download_received_bytes += arg0->size;
        }
    } else if (strncmp(tok, lbl_805DC674, 4) == 0) {
        s = (Slot_802150E8 *)TQuestListOnline__bin_download_state;
        if (s->buf == NULL) {
            strncpy(s->name, arg0->name, 0x10);
            ((Slot_802150E8 *)TQuestListOnline__bin_download_state)->size = arg0->size;
            s->buf = mem_alloc(arg0->size);
            memset(s->buf, 0, (void *)arg0->size);
            TQuestListOnline__bin_download_complete = 0;
            TDLGraph::update_graph(quest_download_graph_current_bytes, quest_download_received_bytes += arg0->size);
        }
    }
}

void TQuestListOnline::receive_quest_info(void *arg0) {
    Pair_80215380 p;
    if ((u32) TQuestListOnline__selected_quest_info != 0U) {
        memcpy(TQuestListOnline__selected_quest_info, arg0, 0x124);
        TQuestListOnline__sub_8013ACF4(2);
        if (THunterGuildSeqOffline__sub_80212074() != 0) {
            ((TWindowCtrl *)local_client_id)->suppress_slot();
            if ((u32) TQuestListOnline__quest_info_window != 0U) {
                ((TWindowBase *)TQuestListOnline__quest_info_window)->close();
                TQuestListOnline__quest_info_window = 0;
            }
            p.a = lbl_8044BCB8[0].a;
            p.b = lbl_8044BCB8[0].b;
            TQuestListOnline__quest_info_window = create__14TWindowMessageFllUls(get_window_layout_position(0x2E), &p, 1, local_client_id);
            ((TWindowBase *)TQuestListOnline__quest_info_window)->set_depth(lbl_805DC664);
            ((TWindowMessage *)TQuestListOnline__quest_info_window)->append_line(TQuestListOnline__selected_quest_info + 4, 0x80);
            if (TCameraCtrl::get_camera_id() >= 2) {
                ((TWindowAddition *)TQuestListOnline__quest_info_window)->set_position_xy(lbl_805DC678, lbl_805DC678);
            }
        }
    }
}

void TQuestListOnline::copy_quest_list_data() {
    s32 arg0 = (s32)this;
    if ((u32) TQuestListOnline__quest_list_buffer != 0U) {
        memcpy((int)TQuestListOnline__quest_list_buffer, (void *)arg0, 0x11D4);
        TQuestListOnline__sub_8013ACF4(1);
    }
}

typedef char RecoveredGlobal_802155B4_TQuestListOnline__data_80513DE8_size[sizeof(RecoveredGlobal_802155B4_TQuestListOnline__data_80513DE8) == 0x3C ? 1 : -1];
typedef char RecoveredGlobal_802155B4_TQuestListOnline__data_80513E24_size[sizeof(RecoveredGlobal_802155B4_TQuestListOnline__data_80513E24) == 0x3C ? 1 : -1];

typedef char RecoveredGlobal_80215498_TQuestListOnline__data_80513DE8_size[sizeof(RecoveredGlobal_80215498_TQuestListOnline__data_80513DE8) == 0x3C ? 1 : -1];
typedef char RecoveredGlobal_80215498_TQuestListOnline__data_80513E24_size[sizeof(RecoveredGlobal_80215498_TQuestListOnline__data_80513E24) == 0x3C ? 1 : -1];
void TQuestListOnline::release_resources() {
    if ((u32) *(u32 *)((s8 *)(&(*(RecoveredGlobal_80215498_TQuestListOnline__data_80513E24 *)&TQuestListOnline__bin_download_state).value) + 0x38) != 0U) {
        mem_free((void *)(*(u32 *)((s8 *)(&(*(RecoveredGlobal_80215498_TQuestListOnline__data_80513E24 *)&TQuestListOnline__bin_download_state).value) + 0x38)));
        *(u32 *)((s8 *)(&(*(RecoveredGlobal_80215498_TQuestListOnline__data_80513E24 *)&TQuestListOnline__bin_download_state).value) + 0x38) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)(&(*(RecoveredGlobal_80215498_TQuestListOnline__data_80513DE8 *)&TQuestListOnline__dat_download_state).value) + 0x38) != 0U) {
        mem_free((void *)(*(u32 *)((s8 *)(&(*(RecoveredGlobal_80215498_TQuestListOnline__data_80513DE8 *)&TQuestListOnline__dat_download_state).value) + 0x38)));
        *(u32 *)((s8 *)(&(*(RecoveredGlobal_80215498_TQuestListOnline__data_80513DE8 *)&TQuestListOnline__dat_download_state).value) + 0x38) = 0U;
    }
    if ((u32) (*(u32 *)&TQuestListOnline__selected_quest_info) != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((int) ((*(u32 *)&TQuestListOnline__selected_quest_info)));
        (*(u32 *)&TQuestListOnline__selected_quest_info) = 0U;
    }
    if ((u32) TQuestListOnline__quest_list_buffer != 0U) {
        TAdSinglePlyChrSelectGC::safe_free(TQuestListOnline__quest_list_buffer);
        TQuestListOnline__quest_list_buffer = 0U;
    }
    if ((u32) (*(u32 *)&TQuestListOnline__download_window) != 0U) {
        ((TWindowBase *)(*(u32 *)&TQuestListOnline__download_window))->close();
        (*(u32 *)&TQuestListOnline__download_window) = 0U;
    }
    if ((u32) (*(u32 *)&TQuestListOnline__quest_info_window) != 0U) {
        ((TWindowBase *)(*(u32 *)&TQuestListOnline__quest_info_window))->close();
        (*(u32 *)&TQuestListOnline__quest_info_window) = 0U;
    }
    if ((u32) (*(u32 *)&TQuestListOnline__download_barrier_window) != 0U) {
        ((TWindowBase *)(*(u32 *)&TQuestListOnline__download_barrier_window))->close();
        (*(u32 *)&TQuestListOnline__download_barrier_window) = 0U;
    }
    (*(s32 *)&quest_download_active) = 0;
    memset((void*)((void *) (&(*(RecoveredGlobal_80215498_TQuestListOnline__data_80513DE8 *)&TQuestListOnline__dat_download_state).value)), (void*)(0), (void*)(0x3C));
    memset((void*)((void *) (&(*(RecoveredGlobal_80215498_TQuestListOnline__data_80513E24 *)&TQuestListOnline__bin_download_state).value)), (void*)(0), (void*)(0x3C));
    (*(s32 *)&TQuestListOnline__bin_download_complete) = 0;
    (*(s32 *)&TQuestListOnline__dat_download_complete) = 0;
    TQuestListOnline__instance = 0;
}

void TQuestListOnline::init_download_buffers() {
    (*(s32 *)&TQuestListOnline__quest_list_buffer) = (s32)TQuestVmDownLoadServer::alloc(0x11D4);
    TQuestListOnline__selected_quest_info = (s32)TQuestVmDownLoadServer::alloc(0x124);
    (*(s32 *)&TQuestListOnline__download_window) = 0;
    (*(s32 *)&TQuestListOnline__quest_info_window) = 0;
    (*(s32 *)&TQuestListOnline__download_barrier_window) = 0;
    (*(s32 *)&quest_download_active) = 0;
    memset((void*)((void *) (&(*(RecoveredGlobal_802155B4_TQuestListOnline__data_80513DE8 *)&TQuestListOnline__dat_download_state).value)), (void*)(0), (void*)(0x3C));
    memset((void*)((void *) (&(*(RecoveredGlobal_802155B4_TQuestListOnline__data_80513E24 *)&TQuestListOnline__bin_download_state).value)), (void*)(0), (void*)(0x3C));
    (*(s32 *)&TQuestListOnline__bin_download_complete) = 0;
    (*(s32 *)&TQuestListOnline__dat_download_complete) = 0;
    TQuestListOnline__instance = 0;
}

void reset_globals(void) { TQuestListOnline__download_window = 0; TQuestListOnline__quest_info_window = 0; TQuestListOnline__download_barrier_window = 0; quest_download_active = 0; memset(TQuestListOnline__dat_download_state, (void*)0, (void*)60); memset(TQuestListOnline__bin_download_state, (void*)0, (void*)60); TQuestListOnline__bin_download_complete = 0; TQuestListOnline__dat_download_complete = 0; quest_download_received_bytes = 0; quest_download_graph_current_bytes = 0; }
typedef char RecoveredGlobal_80215ABC_lbl_804CA0B8_size[sizeof(RecoveredGlobal_80215ABC_lbl_804CA0B8) == 0x28 ? 1 : -1];

u8 TLobby::lookup_table_value(s8 x) {
    Pair_802156A0 *p = (*(G_802156A0 * *)&item_appraisal_rules)->tbl;
    while (p->key != -1) {
        if (p->key == x) {
            return p->val;
        }
        p++;
    }
    return 0;
}

u8 lookup_key_value__6TLobbyFc(s8 x) {
    Pair_802156E0 *p = item_appraisal_rules->tbl;
    while (p->key != -1) {
        if (p->key == x) {
            return p->val;
        }
        p++;
    }
    return 0;
}

struct G_802156E0;

void adjust_appraisal_percentages(Obj_80215720 *arg0) {
    Ctr_80215720 ctr;
    Ent_80215720 *e;
    s32 count;
    s32 n;
    s32 r;
    ((TLobby *)(&ctr))->reset_counter_64();
    count = ((G_80215720 *)item_appraisal_rules)->t->count;
    e = &((G_80215720 *)item_appraisal_rules)->t->base[count * lbl_805D6238];
    while (count-- > 0) {
        if (item_appraisal_favored_weapon != 0) {
            n = e->n2;
        } else {
            n = e->n1;
        }
        while (n-- != 0) {
            push_shop_pool_entry(&ctr, e->id);
        }
        e++;
    }
    shuffle_shop_pool_n_times(&ctr, 4);
    r = ((TLobby *)(&ctr))->pop_byte();
    if (r != -1) {
        s8 v = lbl_8044BD30[r];
        arg0->a += v;
        arg0->b += v;
        arg0->c += v;
    } else {
        arg0->a = 0;
        arg0->b = 0;
        arg0->c = 0;
    }
    if (arg0->a > 100) {
        arg0->a = 100;
    }
    if (arg0->b > 100) {
        arg0->b = 100;
    }
    if (arg0->c > 100) {
        arg0->c = 100;
    }
    item_appraisal_score += ((s8 (*)(s8))lookup_key_value__6TLobbyFc)(r);
}

void TLobby::roll_item_grind_bonus() {
    u8 buf[0x68];
    Ent_8021587C *e;
    s32 n;
    s32 c;
    s32 r;
    if (is_rare_item__9TItemDataFPv(((Item_8021587C *)this)) == 0) {
        ((TLobby *)buf)->reset_counter_64();
        Tbl_8021587C *t = (*(G_8021587C **)&item_appraisal_rules)->t;
        n = t->count;
        e = &t->base[n * lbl_805D6238];
        while (n-- > 0) {
            if (item_appraisal_favored_weapon != 0) {
                c = e->n2;
            } else {
                c = e->n1;
            }
            while (c-- != 0) {
                push_shop_pool_entry(buf, e->id);
            }
            e++;
        }
        shuffle_shop_pool_n_times(buf, 4);
        r = ((TLobby *)buf)->pop_byte();
        if (r != -1) {
            s32 v = ((Item_8021587C *)this)->f3 + lbl_8044BD30[r];
            if (v < 0) {
                v = 0;
            }
            ((Item_8021587C *)this)->f3 = v;
        }
        u8 m = get_entry_field16__9TItemDataFv(((Item_8021587C *)this));
        if (((Item_8021587C *)this)->f3 > m) {
            ((Item_8021587C *)this)->f3 = m;
        }
        item_appraisal_score += (s8)TLobby::lookup_table_value(r);
    }
}

void adjust_appraisal_special(Obj_8021599C *obj) {
    u8 buf[0x68];
    Ent_8021599C *e;
    s32 n;
    s32 c;
    s32 r;
    ((TLobby *)buf)->reset_counter_64();
    Tbl_8021599C *t = (*(G_8021599C **)&item_appraisal_rules)->t;
    n = t->count;
    e = &t->base[n * lbl_805D6238];
    while (n-- > 0) {
        if (item_appraisal_favored_weapon != 0) {
            c = e->n2;
        } else {
            c = e->n1;
        }
        while (c-- != 0) {
            push_shop_pool_entry(buf, e->id);
        }
        e++;
    }
    shuffle_shop_pool_n_times(buf, 4);
    r = ((TLobby *)buf)->pop_byte();
    if (r != -1) {
        switch (lbl_8044BD30[r]) {
        case -1:
            obj->slot = TObjPlayer::find_adjacent_matching_slot(obj->slot);
            break;
        case 1:
            obj->slot = TObjPlayer::get_next_matching_special_index(obj->slot);
            break;
        }
    }
    item_appraisal_score += (s8)lookup_key_value__6TLobbyFc(r);
}

bool TLobby::is_slot_match() {
    u8 *arg0 = (u8 *)this;
    return *(u8 *)((s8 *)arg0 + 1) == *(s32 *)((s8 *)&section_id_favored_grind_table.value + (lbl_805D6238 * 4));
}
}
