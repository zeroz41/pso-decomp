#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TShopWindowBase.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObjFish_8001ED90.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdPlayerLoadGC_801E0C30.h"
#include "pso/ui/TObjBagWarnWin_8006EF24.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TShopArmorListWindow.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/Language.h"

struct VBase18_80218570 { char pad[0x18]; };
struct VObj18_80218570 : VBase18_80218570 {
    virtual void vpad0();
    virtual void vpad1();
    virtual void vpad2();
    virtual void vpad3();
    virtual void vpad4();
    virtual void vpad5();
    virtual void vpad6();
    virtual void vf24(int, int);
};

struct VBase_18_a70a39 { char pad[0x18]; };

struct VObj_18_a70a39 : VBase_18_a70a39 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32, s32);
};

struct RecoveredGlobal_80219A9C_TQuestListVM__data_8044BF20 { char value[0xE]; };
typedef char RecoveredGlobal_80219A9C_TQuestListVM__data_8044BF20_size[sizeof(RecoveredGlobal_80219A9C_TQuestListVM__data_8044BF20) == 0xE ? 1 : -1];

struct RecoveredGlobal_8033B9C4_lbl_80513910 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_80219DE0___vt__12TQuestListVM {
    s32 value;
    u8 remaining[0x2C];
};

struct Rec_80218AD4 { s32 num; s32 slot; u8 rest[0xbc - 8]; };

struct VBase_80218AD4 { char pad[0x18]; };

struct VM_80218AD4 : VBase_80218AD4 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6();
    virtual void m7(int a, int b);
};

struct QL_80218AD4 {
    u8 pad[0xd8];
    Rec_80218AD4 recs[1];
};

struct Rec_802193F0 { u8 pad[0x35]; char name[0xbc - 0x35]; };

struct QL_802193F0 { Rec_802193F0 recs[48]; u8 pad[0x2368 - 48 * 0xbc]; s32 count; };

struct Ent_802193F0 { u8 pad[0x10]; s8 a; s8 b; s8 c; u8 pad13; char name[1]; };

struct VBase_18_80218D40 { char pad[0x18]; };

struct VObj_80218D40 : VBase_18_80218D40 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(s32, s32);
};

struct Pair_80218D40 { s32 a; s32 b; };

struct Dl_80218E94 { u8 pad[0x58]; u8 *data; s32 size; };

struct VBase_80218BBC { char pad[0x18]; };

struct VObj_80218BBC : VBase_80218BBC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6();
    virtual void m7(s32, s32);
};

struct VBase_18_8021924C { char pad[0x18]; };

struct VObj_18_8021924C : VBase_18_8021924C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8();
};

struct VBase_80219064 { char pad[0x18]; };

struct VObj_80219064 : VBase_80219064 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6();
    virtual void m7(s32, s32);
};

struct Ent_80219064 { char data[0xB4]; s32 id; u8 pad[4]; };

struct Q_80219064 { u8 pad[0x28]; Ent_80219064 ents[1]; };

struct VBase_18_80219748 { char pad[0x18]; };

struct VObj_18_80219748 : VBase_18_80219748 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32, s32);
    virtual void m6();
    virtual void m7(int, int);
};

struct Rec_80219748 { char name[0xB0]; s32 num; s32 slot; u8 rest[0xBC - 0xB8]; };

struct QL_80219748 {
    u8 pad0[0x28];
    Rec_80219748 recs[48];
    s32 sel;
    u8 pad2[0x2398 - 0x236C];
    s32 cur;
    s32 slot;
    u8 pad3[0x23AC - 0x23A0];
    s32 flagA;
    s32 flagB;
};

struct Rec_8021969C { u8 data[0xB4]; s32 slot; s32 type; };

struct Obj_8021969C { u8 pad[0x28]; Rec_8021969C recs[48]; s32 sel; u8 pad2[0x1C]; u32 f2388; u8 pad3[0xC]; s32 f2398; };

struct Rec_8021916C { u8 pad[0x55]; char name[0xBC - 0x55]; };
struct Obj_8021916C {
    Rec_8021916C recs[48];
    u8 pad2340[0x236C - 0x2340];
    s32 f236C;
    s32 f2370;
    void *f2374;
    u8 pad2378[4];
    u32 f237C;
    void *f2380;
};
struct Rec_802194BC { u8 pad[0xD]; char name[0x20]; char desc[0x80]; u8 padAD[0xB4 - 0xAD]; s32 slot; s32 type; };
struct QL_802194BC { u8 pad[0x28]; Rec_802194BC recs[48]; s32 count; };
struct Dl_802194BC { u8 pad[0x58]; u8 *data; s32 size; };
struct Ent_802194BC { u8 pad[0x13]; s8 c; char name[0x20]; char desc[0x80]; };

extern s32 TQuestListVM__data_8044BF20[];
extern s32 TQuestListVM__decrypted_quest_buffer;
extern s32 TQuestListVM__decompression_capacity;
extern RecoveredGlobal_8033B9C4_lbl_80513910 download_rng_seed_pair;
void seed_download_rng(s32 arg0);
extern int evt2_random_enemies_mode;
extern s32 __vt__12TQuestListVM[];
extern s32 TQuestListVM__class_name;
extern s32 TQuestListVM__quest_data_output_cursor;
extern s32 TQuestListVM__quest_decrypt_result_size;
extern s32 quest_list_vm_instance;
extern "C" {
u8 *TQuestListVM__ct(TQuestListVM *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 TQuestListVM__sub_8021884C(void *);
int memset(void*, void*, void*);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
s32 get_cursor_value__19TWindowMenuIconLineFv(u32);
int sprintf(char *, const char *, ...);
extern char lbl_8044BEE8[];
extern char lbl_8044BF50[];
s32 strcmp(const char *, const char *);
s32 is_downloadable_new_entry__12TQuestListVMFPvPv(QL_802193F0 *q, Ent_802193F0 *e);
int get_entity_id(int);
f32 get_scale__15TShopWindowBaseFv(void *);
u8 *create_yes_no_window(s32 arg0, s32 arg1, u32 arg2, u32 arg3);
void append_line__14TWindowMessageFii(u32, void *, int);
u32 create__14TWindowMessageFllUls(int, Pair_80218D40 *, int, u16);
int get_window_layout_position(int);
extern Pair_80218D40 lbl_8044BF48[];
extern const f32 lbl_805DC6B8;
extern const f32 lbl_805DC6BC;
s32 TAdPlayerLoadGC__sub_801E1538(Dl_80218E94 *, s32);
s32 poll_download__12TQuestListVMFv(void *);
u32 create__14TWindowMessageFPvll(int, void *, int);
u32 create_item_list_window(void *, int, u16);
extern char lbl_8044BF04[];
extern char lbl_8044BF14[];
extern Pair_80218D40 lbl_8044BF40[];
char *strcpy(char *, const char *);
void *memcpy(void *, const void *, unsigned long);
struct Base_802186E4_80218570 { char pad[0x18]; };
struct VObj_802186E4_80218570 : Base_802186E4_80218570 {
    virtual void m0();virtual void m1();virtual void m2();virtual void m3();
    virtual void m4();virtual void m5();virtual void m6();
    virtual void m7(int a, int b);
    virtual int m8();
};

void TQuestVmDownLoadServer__sub_80219EC4(void* p);
void *__dt__12TQuestListVMFv(TQuestListVM *arg0, s16 arg1);
s32 __dl__7TObjectFPv(void *);

s32 TQuestListVM::update_load_status() {
    s32 temp_r3;
    s32 var_r30;

    var_r30 = 0;
    this->m_23a4 = 0;
    do {
        if (TAdPlayerLoadGC::probe_card_slot(var_r30) != 0) {
            this->m_23a4 = (s32) (this->m_23a4 | (1 << var_r30));
        }
        var_r30 += 1;
    } while (var_r30 < 2);
    temp_r3 = this->m_23a4;
    if (temp_r3 != (s32) this->m_23a8) {
        this->m_23a8 = temp_r3;
        return 1;
    }
    return 0;
}

void TQuestListVM::close_windows() {
    if ((u32) this->m_2378 != 0U) {
        ((TWindowBase *)this->m_2378)->close();
        this->m_2378 = 0U;
    }
    if ((u32) this->m_2380 != 0U) {
        ((TWindowBase *)this->m_2380)->close();
        this->m_2380 = 0U;
    }
    if ((u32) this->m_237c != 0U) {
        ((TWindowBase *)this->m_237c)->close();
        this->m_237c = 0U;
    }
    if ((u32) this->m_2374 != 0U) {
        ((TWindowBase *)this->m_2374)->close();
        this->m_2374 = 0U;
    }
}

void TQuestListVM::set_enemy_mode_3() { TLobby::set_enemy_mode_flag(); evt2_random_enemies_mode = 3; TKeyBoardControl__sub_8000F950(); }

void TQuestListVM::load_vm() {
    if (TLobby::tmp_buf_is_free() == 0) {
        TLobby::tmp_buf_release((const char *)TQuestListVM__data_8044BF20);
    }
    (*(s32 *)&evt2_random_enemies_mode) = 0;
}

s32 TQuestListVM::handle_click() {
    VObj_802186E4_80218570 *obj = (VObj_802186E4_80218570 *) this;
    if (obj->m8() != 0) {
        obj->m7(0x19, 1);
        set_field_20(this->m_23b4);
    }
}

s32 TQuestListVM::invoke_callback_and_queue_destruction() {
    s32 (*temp_r12)();

    temp_r12 = *(s32 (**)())((s8 *)this + 0x23C0);
    if (temp_r12 != NULL) {
        temp_r12();
    }
    queue_destruction__7TObjectFv(this);
}

s32 TQuestListVM::close_and_destroy() {
    s32 (*temp_r12)();

    temp_r12 = *(s32 (**)())((s8 *)this + 0x23BC);
    if (temp_r12 != NULL) {
        temp_r12();
    }
    if (TLobby::tmp_buf_is_free() == 0) {
        TLobby::tmp_buf_release((const char *)TQuestListVM__data_8044BF20);
    }
    queue_destruction__7TObjectFv(this);
}

s32 TQuestListVM::close() {
    s32 (*temp_r12)();

    temp_r12 = *(s32 (**)())((s8 *)this + 0x23B8);
    if (temp_r12 != NULL) {
        temp_r12();
    }
    if (TLobby::tmp_buf_is_free() == 0) {
        TLobby::tmp_buf_release((const char *)TQuestListVM__data_8044BF20);
    }
    TQuestListVM::reset();
    queue_destruction__7TObjectFv(this);
}

s32 TQuestListVM__sub_8021884C(void * _w0) {  }

void TQuestListVM::update_close() {
    void *p;

    p = *(void * *)&this->m_2374;
    if ((p != NULL) && (((TWindowMenuIconLine *)p)->is_cancelled() != 0)) {
        if ((u32) this->m_2380 != 0U) {
            ((TWindowBase *)this->m_2380)->close();
            this->m_2380 = 0U;
        }
        if ((u32) this->m_2374 != 0U) {
            ((TWindowMenuIconLine *)(this->m_2374))->clear_decided();
            TQuestVmDownLoadServer__sub_80219EC4((void*)this->m_2374);
        }
        ((VObj18_80218570 *) this)->vf24(0x19, 1);
        close_windows();
        set_field_20((s32)((void*)(5)));
        return;
    }
    p = *(void * *)&this->m_2374;
    if ((p != NULL) && (((TWindowMenuIconLine *)p)->is_decided() != 0)) {
        set_field_20((s32)((void*)(0x11)));
    }
}

void TQuestListVM::load_downloaded_quest() {
    u8 *arg0 = (u8 *)this;
    Dl_80218E94 dl;
    u32 r;
    u32 win = *(u32 *)(arg0 + 0x2374);
    if (win != 0) {
    u8 *e = arg0 + get_cursor_value__19TWindowMenuIconLineFv(win) * 0xBC;
    if (TAdPlayerLoadGC__sub_801E1B50(*(s32 *)(e + 0xDC)) == 0) {
    switch (TAdPlayerLoadGC__sub_801E1538(&dl, *(s32 *)(arg0 + 0x2388))) {
    case 0:
        seed_download_rng(poll_download__12TQuestListVMFv(arg0));
        TQuestVmDownLoadServer::unshuffle_and_decrypt(dl.data, dl.size);
        if (TQuestVmDownLoadServer::verify_checksum(dl.data, dl.size) == 0) {
            *(s32 *)(arg0 + 0x2398) += 2;
            ((VObj_802186E4_80218570 *)arg0)->m7(0x1A, 1);
            ((TQuestListVM *)arg0)->set_selected_entry((void *)5);
            ((TQuestListVM *)arg0)->close_windows();
        } else {
            r = decrypt_quest_data(dl.data + 8, dl.size - 8, (void *)TQuestListVM__quest_data_output_cursor, TQuestListVM__quest_decrypt_result_size);
            if (r != 0) {
                TQuestListVM__quest_decrypt_result_size = r;
                ((TShopWindowBase *)arg0)->set_field_20((s32)((void *)0xD));
            } else {
                ((VObj_802186E4_80218570 *)arg0)->m7(0x1A, 1);
                ((TQuestListVM *)arg0)->set_selected_entry((void *)5);
                ((TQuestListVM *)arg0)->close_windows();
            }
        }
        break;
    case -0xDF:
        ((VObj_802186E4_80218570 *)arg0)->m7(0x1A, 1);
        ((TQuestListVM *)arg0)->close_windows();
        ((TShopWindowBase *)arg0)->set_field_20((s32)((void *)5));
        break;
    case -0xE0:
        ((VObj_802186E4_80218570 *)arg0)->m7(0x1A, 1);
        ((TQuestListVM *)arg0)->close_windows();
        ((TShopWindowBase *)arg0)->set_field_20((s32)((void *)5));
        break;
    }
    }
    }
}

void TQuestListVM::load_selected_slot() {
    char buf[0xd];
    s32 i;
    QL_80218AD4 *q = (QL_80218AD4 *)this;
    memset(buf, (void *)0, (void *)0xd);
    if (this->m_2374 != 0 && this->m_2388 != 0) {
        i = get_cursor_value__19TWindowMenuIconLineFv(this->m_2374);
        if (TAdPlayerLoadGC__sub_801E1B50(q->recs[i].slot) == 0) {
            sprintf(buf, lbl_8044BF50, lbl_8044BEE8, q->recs[i].num + 1);
            if (TAdSinglePlyChrSelectGC::load_player_slot(q->recs[i].slot, buf, (void *)this->m_2388) == 0) {
                this->set_field_20((s32)((void *)0xc));
                return;
            }
            ((VM_80218AD4 *)((u8 *)this))->m7(0x19, 1);
            this->close_windows();
            this->set_field_20((s32)((void *)5));
        }
    }
}

void TQuestListVM::handle_confirm_window() {
    u8 *arg0 = (u8 *)this;
    if (this->m_2378 != NULL) {
        if (((TWindowMenu *)(this->m_2378))->is_decided() != 0) {
            switch (((TWindowMenu *)(*(void * *)&this->m_2378))->get_selected_value()) {
            case 0:
                ((TWindowBase *)this->m_2378)->close();
                this->m_2378 = NULL;
                ((TShopWindowBase *)arg0)->set_field_20(0xB);
                return;
            case 1:
                ((TWindowBase *)this->m_2378)->close();
                this->m_2378 = NULL;
                if (this->m_2380 != NULL) {
                    ((TWindowBase *)this->m_2380)->close();
                    this->m_2380 = NULL;
                }
                if (this->m_2374 != NULL) {
                    ((TWindowMenuIconLine *)(this->m_2374))->clear_decided();
                }
                TQuestListVM__decrypted_quest_buffer = this->m_2384;
                TQuestListVM__decompression_capacity = 0x40000;
                ((VObj_80218BBC *)arg0)->m7(0x19, 1);
                close_windows();
                ((TShopWindowBase *)arg0)->set_field_20(5);
                return;
            }
        }
        if (((TWindowMenu *)(this->m_2378))->is_cancelled() != 0) {
            ((TWindowBase *)this->m_2378)->close();
            this->m_2378 = NULL;
            if (this->m_2380 != NULL) {
                ((TWindowBase *)this->m_2380)->close();
                this->m_2380 = NULL;
            }
            if (this->m_2374 != NULL) {
                ((TWindowMenuIconLine *)(this->m_2374))->clear_decided();
            }
            TQuestListVM__decrypted_quest_buffer = this->m_2384;
            TQuestListVM__decompression_capacity = 0x40000;
            ((VObj_80218BBC *)arg0)->m7(0x19, 1);
            close_windows();
            ((TShopWindowBase *)arg0)->set_field_20(5);
        }
    }
}

void TQuestListVM::open_confirm_window() {
    if (this->m_2380 == 0U) {
        Pair_80218D40 sp8 = lbl_8044BF48[0];
        u16 id = get_entity_id(*(s32 *)&this->m_24);
        this->m_2380 = create__14TWindowMessageFllUls(get_window_layout_position(0x2E), &sp8, 1, id);
        append_line__14TWindowMessageFii(this->m_2380, (void *)(TQuestListVM__decrypted_quest_buffer + 0xB4), 1);
        ((TWindowBase *)(this->m_2380))->set_depth(lbl_805DC6B8);
        if (TCameraCtrl::get_camera_id() >= 2) {
            ((TWindowAddition *)(this->m_2380))->set_position_xy(lbl_805DC6BC, lbl_805DC6BC);
        }
    }
    if (this->m_2380 != 0U) {
        if (*(s32 *)&this->m_2370 != 0xA) {
            this->set_field_20((s32)((void *)*(s32 *)&this->m_2370));
            return;
        }
        {
            u16 id = get_entity_id(*(s32 *)&this->m_24);
            this->m_2378 = (u32)create_yes_no_window(get_window_layout_position(0x2B), id, 0, 0);
        }
        ((TWindowAddition *)(this->m_2378))->set_position_xy(get_scale__15TShopWindowBaseFv(this), get_scale__15TShopWindowBaseFv(this));
        ((VObj_80218D40 *)(this))->m7(5, 1);
        this->set_field_20((s32)((void *)*(s32 *)&this->m_2370));
    }
}

#define arg0 ((u8 *)p)
void TQuestListVM::poll_quest_download(void *p) {
    Dl_80218E94 dl;
    u32 r;
    u32 win = *(u32 *)(arg0 + 0x2374);
    if (win != 0U) {
    u8 *e = arg0 + get_cursor_value__19TWindowMenuIconLineFv(win) * 0xBC;
    if (TAdPlayerLoadGC__sub_801E1B50(*(s32 *)(e + 0xDC)) == 0) {
    switch (TAdPlayerLoadGC__sub_801E1538(&dl, *(s32 *)(arg0 + 0x2388))) {
    case 0:
        seed_download_rng(poll_download__12TQuestListVMFv(arg0));
        TQuestVmDownLoadServer::unshuffle_and_decrypt(dl.data, dl.size);
        if (TQuestVmDownLoadServer::verify_checksum(dl.data, dl.size) == 0) {
            *(s32 *)(arg0 + 0x2398) += 2;
            ((VObj_802186E4_80218570 *)arg0)->m7(0x1A, 1);
            ((TQuestListVM *)arg0)->set_selected_entry((void *)5);
            ((TQuestListVM *)arg0)->close_windows();
        } else {
            r = decrypt_quest_data(dl.data + 8, dl.size - 8, (void *)TQuestListVM__decrypted_quest_buffer, TQuestListVM__decompression_capacity);
            if (r != 0) {
                TQuestListVM__quest_data_output_cursor = TQuestListVM__decrypted_quest_buffer + r;
                TQuestListVM__quest_decrypt_result_size = TQuestListVM__decompression_capacity - r;
                ((TShopWindowBase *)arg0)->set_field_20((s32)((void *)0xF));
            } else {
                ((VObj_802186E4_80218570 *)arg0)->m7(0x1A, 1);
                ((TQuestListVM *)arg0)->set_selected_entry((void *)5);
                ((TQuestListVM *)arg0)->close_windows();
            }
        }
        break;
    case -0xDF:
        ((VObj_802186E4_80218570 *)arg0)->m7(0x1A, 1);
        ((TQuestListVM *)arg0)->close_windows();
        ((TShopWindowBase *)arg0)->set_field_20((s32)((void *)5));
        break;
    case -0xE0:
        ((VObj_802186E4_80218570 *)arg0)->m7(0x1A, 1);
        ((TQuestListVM *)arg0)->close_windows();
        ((TShopWindowBase *)arg0)->set_field_20((s32)((void *)5));
        break;
    }
    }
    }
}
#undef arg0

void TQuestListVM::sub_80219064() {
    s32 i;
    Q_80219064 *q = (Q_80219064 *)this;
    if (this->m_2374 != 0 && this->m_2388 != 0) {
        i = get_cursor_value__19TWindowMenuIconLineFv(this->m_2374);
        if (TAdPlayerLoadGC__sub_801E1B50(q->ents[i].id) == 0) {
            if (TAdSinglePlyChrSelectGC::load_player_slot(q->ents[i].id, q->ents[i].data, (void *)this->m_2388) == 0) {
                this->set_field_20((s32)((void *)9));
                return;
            }
            ((VObj_80219064 *)((u8 *)this))->m7(0x19, 1);
            this->close_windows();
            this->set_field_20((s32)((void *)5));
        }
    }
}

s32 TQuestListVM::quest_vm_load() {
    if (TLobby::tmp_buf_is_free() != 0) {
        this->m_2384 = TLobby::tmp_buf_use_req((const char *)TQuestListVM__data_8044BF20);
        this->set_field_20(this->m_2370);
    }
}

#define arg0 ((Obj_8021916C *)arg0_)
void TQuestListVM::update_lobby_selection(void *arg0_) {
    s32 sel;

    if (arg0->f2374 != NULL && ((TWindowMenuIconLine *)(arg0->f2374))->is_cancelled() != 0) {
        ((TShopWindowBase *)arg0)->set_field_20((s32)((void *)0x10));
        return;
    }
    if (arg0->f2374 != NULL && ((TWindowMenuIconLine *)(arg0->f2374))->is_decided() != 0) {
        arg0->f2370 = 0xA;
        ((TShopWindowBase *)arg0)->set_field_20((s32)((void *)8));
        return;
    }
    if (arg0->f2374 != NULL && arg0->f237C != 0) {
        sel = ((TWindowMenuIconLine *)arg0->f2374)->get_cursor_value();
        if (sel != arg0->f236C) {
            append_line__14TWindowMessageFii(arg0->f237C, arg0->recs[sel].name, 0x80);
            arg0->f236C = sel;
            if (arg0->f2380 != NULL) {
                ((TWindowBase *)arg0->f2380)->close();
                arg0->f2380 = NULL;
            }
        }
    }
}
#undef arg0

#define arg0 ((u8 *)p)
s32 TQuestListVM::build_download_list(void *p) {
    s32 off;
    s32 i;
    u8 *e;
    if (((VObj_18_8021924C *)(arg0))->m8() != 0) {
        if (*(u32 *)(arg0 + 0x2374) != 0U) {
            ((TWindowMenuIconLine *)(*(void **)(arg0 + 0x2374)))->reset_list();
        } else {
            switch (current_language) {
            case LANGUAGE_JAPANESE:
                *(u32 *)(arg0 + 0x2374) = create_item_list_window(lbl_8044BF04, 0x40, get_entity_id(*(s32 *)(arg0 + 0x24)));
                break;
            case LANGUAGE_ENGLISH:
            case LANGUAGE_GERMAN:
            case LANGUAGE_FRENCH:
            case LANGUAGE_SPANISH:
            default:
                *(u32 *)(arg0 + 0x2374) = create_item_list_window(lbl_8044BF14, 0x40, get_entity_id(*(s32 *)(arg0 + 0x24)));
                break;
            }
        }
        if (*(u32 *)(arg0 + 0x2374) != 0U) {
            for (i = 0, off = 0; i < *(s32 *)(arg0 + 0x2368); i++, off += 0xBC) {
                e = arg0 + off;
                switch (*(s32 *)(e + 0xE0)) {
                case 0:
                    ((TWindowMenuIconLine *)(*(u32 *)(arg0 + 0x2374)))->add_list_entry(0x17, (s32)(e + 0x35), (s32)i);
                    break;
                case 1:
                    ((TWindowMenuIconLine *)(*(u32 *)(arg0 + 0x2374)))->add_list_entry(0x31, (s32)(e + 0x35), (s32)i);
                    break;
                default:
                    ((TWindowMenuIconLine *)(*(u32 *)(arg0 + 0x2374)))->add_list_entry(0x17, (s32)(e + 0x35), (s32)i);
                    break;
                }
            }
            ((TWindowMenuIconLine *)(*(void **)(arg0 + 0x2374)))->calc_content_extent();
            ((TShopWindowBase *)arg0)->set_field_20((s32)((void *)6));
        }
        if (*(u32 *)(arg0 + 0x237C) == 0U) {
            Pair_80218D40 sp8 = lbl_8044BF40[0];
            *(u32 *)(arg0 + 0x237C) = create__14TWindowMessageFPvll(get_window_layout_position(0x2D), &sp8, 1);
            append_line__14TWindowMessageFii(*(u32 *)(arg0 + 0x237C), arg0 + 0x55, 0x80);
            *(s32 *)(arg0 + 0x236C) = 0;
        }
    }
}
#undef arg0

s32 is_downloadable_new_entry__12TQuestListVMFPvPv(QL_802193F0 *q, Ent_802193F0 *e) {
    s32 i;
    if (e->a == -1 || e->c == -1) {
        return 0;
    }
    if (e->a != current_language) {
        return 0;
    }
    if (e->b != 0 && e->b != 2) {
        return 0;
    }
    for (i = 0; i < q->count; i++) {
        if (strcmp(q->recs[i].name, e->name) == 0) {
            return 0;
        }
    }
    return 1;
}

#define arg0 ((u8 *)q)
#define count (q->count)
void TQuestListVM::process_download_entry() {
    QL_802194BC *q = (QL_802194BC *)this;
    Dl_802194BC dl;
    Ent_802194BC *e;

    if (TAdPlayerLoadGC__sub_801E1B50(q->recs[count].slot) == 0) {
        switch (TAdPlayerLoadGC__sub_801E1538((Dl_80218E94 *)&dl, *(s32 *)(arg0 + 0x2388))) {
        case 0:
            seed_download_rng(poll_download__12TQuestListVMFv(arg0));
            TQuestVmDownLoadServer::unshuffle_and_decrypt(dl.data, dl.size);
            if (TQuestVmDownLoadServer::verify_checksum(dl.data, dl.size) == 0) {
                *(s32 *)(arg0 + 0x23B0) = 1;
                *(s32 *)(arg0 + 0x2398) += 2;
                ((TShopWindowBase *)arg0)->set_field_20((s32)((void *)2));
            } else if (decrypt_quest_data(dl.data + 8, dl.size - 8, (void *)TQuestListVM__decrypted_quest_buffer, TQuestListVM__decompression_capacity) != 0) {
                e = (Ent_802194BC *)TQuestListVM__decrypted_quest_buffer;
                if (is_downloadable_new_entry__12TQuestListVMFPvPv((QL_802193F0 *)arg0, (Ent_802193F0 *)e) != 0) {
                    memcpy(q->recs[count].name, e->name, 0x20);
                    memcpy(q->recs[count].desc, e->desc, 0x80);
                    q->recs[count].type = e->c;
                    count++;
                }
                *(s32 *)(arg0 + 0x2398) += 2;
                ((TShopWindowBase *)arg0)->set_field_20((s32)((void *)2));
            } else {
                *(s32 *)(arg0 + 0x23B0) = 1;
                *(s32 *)(arg0 + 0x2398) += 2;
                ((TShopWindowBase *)arg0)->set_field_20((s32)((void *)2));
            }
            break;
        case -0xDF:
            *(s32 *)(arg0 + 0x23B0) = 1;
            *(s32 *)(arg0 + 0x2398) += 2;
            ((TShopWindowBase *)arg0)->set_field_20((s32)((void *)2));
            break;
        case -0xE0:
            *(s32 *)(arg0 + 0x23B0) = 1;
            *(s32 *)(arg0 + 0x2398) += 2;
            ((TShopWindowBase *)arg0)->set_field_20((s32)((void *)2));
            break;
        }
    }
}
#undef count
#undef q
#undef arg0

#define q ((QL_80219748 *)arg0)

void TQuestListVM::load_selected_player_slot() {
    Obj_8021969C *arg0 = (Obj_8021969C *)this;
    if (this->m_2388 != 0) {
        if (TAdPlayerLoadGC__sub_801E1B50(arg0->recs[this->m_2368].slot) == 0) {
            if (TAdSinglePlyChrSelectGC::load_player_slot(arg0->recs[this->m_2368].slot, (char *)&arg0->recs[this->m_2368], (void *)this->m_2388) == 0) {
                ((TShopWindowBase *)arg0)->set_field_20((s32)((void*)((void *)4)));
                return;
            }
            this->m_2398 += 2;
            ((TShopWindowBase *)arg0)->set_field_20((s32)((void*)((void *)2)));
        }
    } else {
        ((TShopWindowBase *)arg0)->set_field_20((s32)((void*)((void *)0x12)));
    }
}

void TQuestListVM::scan_memcard_quest_files(void *arg0) {
    char buf[13];
    s32 ok;
    while (q->cur < 0x5F) {
        memset(buf, (void *)0, (void *)0xD);
        sprintf(buf, lbl_8044BF50, lbl_8044BEE8, q->cur + 1);
        switch (TAdPlayerLoadGC::find_card_file(q->slot, buf)) {
        case 0:
            ok = 1;
            break;
        case -191:
            ok = 0;
            q->flagA = 1;
            break;
        case -255:
        case -253:
        case -251:
        case -1:
        default:
            ok = 0;
            break;
        }
        memset(buf, (void *)0, (void *)0xD);
        sprintf(buf, lbl_8044BF50, lbl_8044BEE8, q->cur);
        switch (TAdPlayerLoadGC::find_card_file(q->slot, buf)) {
        case 0:
            if (ok == 0) {
                q->flagA = 1;
                break;
            }
            strcpy(q->recs[q->sel].name, buf);
            {
            QL_80219748 *p = q;
            p->recs[p->sel].num = p->cur;
            p->recs[p->sel].slot = p->slot;
            }
            ((TShopWindowBase *)q)->set_field_20((s32)((void *)3));
            return;
        case -191:
            q->flagA = 1;
            break;
        case -251:
            if (ok != 0) {
                q->flagA = 1;
            }
            break;
        case -255:
        case -253:
        case -1:
        default:
            break;
        }
        q->cur += 2;
    }
    if (q->slot < 7) {
        q->slot++;
        q->cur = 0;
        return;
    }
    if (q->sel != 0) {
        if (q->flagB != 0) {
            ((VObj_18_80219748 *)q)->m7(0x1B, 1);
            ((TQuestListVM *)q)->set_selected_entry((void *)5);
            return;
        }
        if (q->flagA != 0) {
            ((VObj_18_80219748 *)q)->m5(TQuestVmDownLoadServer__sub_8006EF6C(0x66), 1);
            ((TQuestListVM *)q)->set_selected_entry((void *)5);
            return;
        }
        ((VObj_18_80219748 *)q)->m7(0x19, 1);
        ((TShopWindowBase *)q)->set_field_20((s32)((void *)5));
        return;
    }
    if (q->flagB != 0) {
        ((VObj_18_80219748 *)q)->m7(0x1B, 1);
        ((TShopWindowBase *)q)->set_field_20((s32)((void *)0x12));
        return;
    }
    if (q->flagA != 0) {
        ((VObj_18_80219748 *)q)->m5(TQuestVmDownLoadServer__sub_8006EF6C(0x66), 1);
        ((TShopWindowBase *)q)->set_field_20((s32)((void *)0x12));
        return;
    }
    ((VObj_18_80219748 *)q)->m5(TQuestVmDownLoadServer__sub_8006EF6C(0x44), 1);
    ((TShopWindowBase *)q)->set_field_20((s32)((void *)0x12));
}
#undef q

s32 TQuestListVM::load_quest_vm() {
    u8 *arg0 = (u8 *)this;
    if (TLobby::tmp_buf_is_free() != 0) {
        this->m_2384 = TLobby::tmp_buf_use_req((const char *)((s32) &(*(RecoveredGlobal_80219A9C_TQuestListVM__data_8044BF20 *)&TQuestListVM__data_8044BF20).value));
        TQuestListVM__decrypted_quest_buffer = this->m_2384;
        TQuestListVM__decompression_capacity = 0x40000;
        ((TShopWindowBase *)arg0)->set_field_20((s32)((void*)(2)));
        ((VObj_18_a70a39 *)(arg0))->m5(TQuestVmDownLoadServer__sub_8006EF6C(0x3F), 1);
    }
}

s32 TQuestListVM::init() { memset((char*)this + 0x28, (void*)0, (void*)9024); *(int *)&this->m_2398 = 4; *(int *)&this->m_2368 = 0; *(int *)&this->m_239c = 0; *(int *)&this->_pad236C = 0; *(int *)&this->m_23ac = 0; *(int *)&this->m_23b0 = 0; set_field_20((s32)((void*)((void*)1))); }

void TQuestListVM::vfunc_11() {
    u8 *arg0 = (u8 *)this;
    if (((TQuestListVM *)arg0)->update_load_status() != 0) {
        ((VObj_18_a70a39 *)(arg0))->m5(TQuestVmDownLoadServer__sub_8006EF6C(0x44), 1);
        ((TShopWindowBase *)arg0)->set_field_20((s32)((void*)(0x12)));
    }
    switch (this->m_20) {
    case 0:
        ((TQuestListVM *)arg0)->init();
        return;
    case 1:
        ((TQuestListVM *)arg0)->load_quest_vm();
        return;
    case 2:
        TQuestListVM::scan_memcard_quest_files(arg0);
        return;
    case 3:
        ((TQuestListVM *)arg0)->load_selected_player_slot();
        return;
    case 4:
        ((TQuestListVM *)arg0)->process_download_entry();
        return;
    case 5:
        TQuestListVM::build_download_list(arg0);
        return;
    case 6:
        TQuestListVM::update_lobby_selection(arg0);
        return;
    case 7:
        ((TQuestListVM *)arg0)->quest_vm_load();
        return;
    case 8:
        ((TQuestListVM *)arg0)->sub_80219064();
        return;
    case 9:
        TQuestListVM::poll_quest_download(arg0);
        return;
    case 15:
        ((TQuestListVM *)arg0)->open_confirm_window();
        return;
    case 10:
        ((TQuestListVM *)arg0)->handle_confirm_window();
        return;
    case 11:
        ((TQuestListVM *)arg0)->load_selected_slot();
        return;
    case 12:
        ((TQuestListVM *)arg0)->load_downloaded_quest();
        return;
    case 13:
        ((TQuestListVM *)arg0)->update_close();
        return;
    case 14:
        TQuestListVM__sub_8021884C(arg0);
        return;
    case 16:
        ((TQuestListVM *)arg0)->close();
        return;
    case 18:
        ((TQuestListVM *)arg0)->close_and_destroy();
        return;
    case 17:
        ((TQuestListVM *)arg0)->invoke_callback_and_queue_destruction();
        return;
    case 20:
        ((TQuestListVM *)arg0)->handle_click();
    default:
        return;
    }
}

void *__dt__12TQuestListVMFv(TQuestListVM *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void **) ((s8 *) arg0 + 0x18) = __vt__12TQuestListVM;
        if ((u32) arg0->m_2380 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x2380)))->close();
            arg0->m_2380 = 0U;
        }
        if ((u32) arg0->m_237c != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x237C)))->close();
            arg0->m_237c = 0U;
        }
        if ((u32) arg0->m_2378 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x2378)))->close();
            arg0->m_2378 = 0U;
        }
        if ((u32) arg0->m_2374 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x2374)))->close();
            arg0->m_2374 = 0U;
        }
        if ((u32) arg0->m_2388 != 0U) {
            TAdSinglePlyChrSelectGC::safe_free((u32)(*(void **)((s8 *)arg0 + 0x2388)));
            arg0->m_2388 = 0U;
        }
        quest_list_vm_instance = 0;
        TLobby::tmp_buf_release_if_owner((const char *)TQuestListVM__data_8044BF20);
        __dt__15TShopWindowBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80219DE0___vt__12TQuestListVM_size[sizeof(RecoveredGlobal_80219DE0___vt__12TQuestListVM) == 0x30 ? 1 : -1];
u8 *TQuestListVM__ct(TQuestListVM *quest_list_vm, s32 arg1, s32 arg2, s32 arg3) {
    __ct__15TShopWindowBaseFv(quest_list_vm);
    *(s32 **)((s8 *)quest_list_vm + 0x18) = &(*(RecoveredGlobal_80219DE0___vt__12TQuestListVM *)&__vt__12TQuestListVM).value;
    *(s32 *)((s8 *)quest_list_vm + 0) = (s32) TQuestListVM__class_name;
    quest_list_vm->m_2368 = 0;
    quest_list_vm->m_2370 = 0;
    quest_list_vm->m_2374 = 0;
    quest_list_vm->m_237c = 0;
    quest_list_vm->m_2380 = 0;
    quest_list_vm->m_2378 = 0;
    quest_list_vm->m_2384 = 0;
    quest_list_vm->m_2388 = (u32)TQuestVmDownLoadServer::alloc(0x20000);
    quest_list_vm->m_2390 = 0;
    TQuestListVM__decrypted_quest_buffer = 0;
    TQuestListVM__decompression_capacity = 0;
    TQuestListVM__quest_data_output_cursor = 0;
    TQuestListVM__quest_decrypt_result_size = 0;
    quest_list_vm->m_2398 = 4;
    quest_list_vm->m_239c = 0;
    quest_list_vm->m_23a0 = arg2;
    quest_list_vm->m_23b8 = 0;
    quest_list_vm->m_23bc = 0;
    quest_list_vm->m_23c0 = 0;
    ((TShopWindowBase *)quest_list_vm)->set_field_20((s32)((void*)(0)));
    (*(u8 * *)&quest_list_vm_instance) = (u8 *)quest_list_vm;
    quest_list_vm->m_24 = arg3;
    quest_list_vm->m_23a8 = 0;
    quest_list_vm->m_23a4 = 0;
    quest_list_vm->update_load_status();
    quest_list_vm->m_23ac = 0;
    quest_list_vm->m_23b0 = 0;
    quest_list_vm->m_23b4 = 0;
    return (u8 *)quest_list_vm;
}

void TQuestVmDownLoadServer__sub_80219EC4(void* p) { *(u16*)((char*)p + 0x70) |= 0x8; }
}
typedef char RecoveredGlobal_8033B9C4_lbl_80513910_size[sizeof(RecoveredGlobal_8033B9C4_lbl_80513910) == 0x10 ? 1 : -1];
void seed_download_rng(s32 arg0) {
    *(s32 *)((s8 *)&download_rng_seed_pair.value + 4) = arg0;
    *(s32 *)((s8 *)&download_rng_seed_pair.value + 0) = arg0;
}
