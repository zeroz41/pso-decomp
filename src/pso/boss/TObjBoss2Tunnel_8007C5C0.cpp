#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/TMainTask.h"
#include "pso/boss/TObjBoss2Tunnel_8007C5C0.h"
#include "pso/boss/TObjBoss2Tunnel_8007CF0C.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/misc/TPlyJoinLobbyEntry.h"
#include "pso/player/TObjPlayer_80083B38.h"
#include "pso/unk/text_803DCDFC.h"
#include "pso/system/main_loop.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/misc/TDLGraph.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Stack_8007CBC4 {
    s32 sp8;
    u8 pad_C[0x54];
    s32 sp60;
};

struct Stack_8007CAE8 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
};

struct Load_8007CB50 { u8 pad[0x58]; s32 *data; u32 size; };

struct Card_8007CCD0 {
    char file[0x12];
    char title[0x22];
    u8 icon[0x10];
    u8 pad44[8];
    s16 f4c;
    s16 f4e;
    s32 f50;
    s16 f54;
    u8 pad56[2];
    s32 *data;
    s32 size;
};

struct VBase_8007C5C0 { char pad[0x18]; };

struct VObj_8007C5C0 : VBase_8007C5C0 {
    virtual ~VObj_8007C5C0();
    virtual void m1();
    virtual void m2();
};

struct VBase_8007C8AC { char pad[0x18]; };

struct VObj_8007C8AC : VBase_8007C8AC {
    virtual ~VObj_8007C8AC();
    virtual void m1();
    virtual void m2();
};

extern "C" {
s32 DCFlushRange(int, int);
s32 TAdPlayerLoadGC__sub_801E1538(void *, int);
s32 TAdPlayerLoadGC__sub_801E1B50(int);
s32 memcpy(int, void *, int);
extern s32 lbl_805D49B4;
extern s16 TObjBoss2Tunnel__snapshot_state;
extern s32 TObjBoss2Tunnel__snapshot_buffer;
s32 draw_textured_screen_quad__10TObjPlayerFUlPfPfl(int, void *, void *, int, f32);
extern const f32 lbl_805D9224;
extern const f32 lbl_805D9228;
extern const f32 lbl_805D922C;
extern const f32 lbl_805D9230;
extern s32 TObjBoss2Tunnel__data_80438A08[];
void poll_load_status__15TAdPlayerLoadGCFl(s32 a, void *b);
u32 TAdSinglePlyChrSelectGC__sub_80201204(u8 *arg0, u32 arg1);
void TAdPlayerLoadGC__sub_801E14E4(void *);
void TAdPlayerLoadGC__sub_801E14E8(u8 *arg0, s32 arg1);
void build_save_file_image__15TAdPlayerLoadGCFPvPv(s32, void *, void *);
s32 load_player__23TAdSinglePlyChrSelectGCFllll(s32, void *, s32, s32);
char *strcpy(char *, const char *);
void *memset(void *, int, u32);
extern char lbl_80438A28[];
extern u8 lbl_80438A4C[];
extern char lbl_804C8974[];
extern s32 *boss2_tunnel_snapshot_buffer;
VObj_8007C5C0 *create__8TDLGraphFv(void);
s8 func_801A5E54__Fv(void);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
extern f32 lbl_80438A78[];
extern f32 lbl_80438A80[];
extern f32 lbl_8048DF4C[];
extern u8 controller_physical_port_bank[];
extern u32 camera_ctrl_instance;
extern s8 boss2_tunnel_confirm_loop_flag;
extern f32 lbl_805D4EA4;
extern s8 lbl_805D4EA8;
extern const f32 TObjBoss2Tunnel__data_805D9210;
extern const f32 lbl_805D9214;
extern const f32 lbl_805D9218;
extern const f32 lbl_805D921C;
extern f32 lbl_80438A68[];
extern f32 lbl_80438A70[];
extern f32 lbl_8048DF44[];
extern s8 lbl_805D4E98;
extern f32 lbl_805D4E9C;
extern s8 boss2_tunnel_message_shown_flag;
extern const f32 lbl_805D9220;

s32 TObjBoss2Tunnel::run_confirm_message_loop() {
    s32 result;
    u8 *pad;
    VObj_8007C5C0 *win;
    VObj_8007C5C0 *graph;
    s32 frames;
    result = 0;
    if (boss2_tunnel_confirm_loop_flag == 0) {
        lbl_8048DF4C[0] = TObjBoss2Tunnel__data_805D9210 + lbl_80438A78[0];
        lbl_8048DF4C[1] = lbl_805D9214 + (lbl_80438A78[1] + lbl_80438A80[1]);
        boss2_tunnel_confirm_loop_flag = 1;
    }
    if (lbl_805D4EA8 == 0) {
        lbl_805D4EA4 = lbl_80438A80[0] - lbl_805D9218;
        lbl_805D4EA8 = 1;
    }
    win = (VObj_8007C5C0 *)TWindowMessage::create((s32)lbl_80438A78, (s32)lbl_80438A80, (u32)1, 4);
    if (win != NULL) {
        ((TWindowMessage *)win)->append_line(get_localized_text_entry(0x24, 0xB), 3);
        ((TWindowBase *)win)->set_depth(lbl_805D921C);
    }
    ((TWindowMessage *)win)->complete_reveal();
    graph = create__8TDLGraphFv();
    if (graph != NULL) {
        ((TDLGraph *)graph)->set_graph_param(2);
    }
    frames = 0;
    if (get_main_phase() == 0xF) {
        reset_state_flags__6TLobbyFv();
    }
    pad = controller_physical_port_bank + 0x110;
    for (;;) {
        frames++;
        func_803DCDFC__Fv();
        controller_stuff();
        if (camera_ctrl_instance != 0U) {
            ((TCameraCtrl *)camera_ctrl_instance)->setup_default_view(0);
        }
        main_task.render();
        draw_snapshot_capture_overlay();
        TLobby::wait_ready_loop();
        if (func_801A5E54__Fv() != 0) {
            break;
        }
        TParticleCtrl::begin_effect_render();
        if (graph != NULL) {
            TDLGraph::update_graph(frames, 0x78);
            graph->m1();
            graph->m2();
        }
        win->m2();
        TParticleCtrl::end_effect_render();
        if (frames >= 6.0) {
            if (TWindowShortListCtrl__check_controller_button(pad, 2) != 0 || frames >= 0x78) {
                result = 0;
                break;
            }
            if (TWindowShortListCtrl__check_controller_button(pad, 4) != 0) {
                result = 1;
                break;
            }
        }
        render_tick();
    }
    if (graph != NULL) {
        delete graph;
    }
    if (get_main_phase() == 0xF) {
        process_deferred_player_setup__6TLobbyFv();
    }
    if (win != NULL) {
        delete win;
    }
    return result;
}

void TObjBoss2Tunnel::poll_pso_screen_load() {
    poll_load_status__15TAdPlayerLoadGCFl(1, ((u8 *)&TObjBoss2Tunnel__data_80438A08));
}

void TObjBoss2Tunnel::show_message_and_wait(s32 arg0) {
    VObj_8007C8AC *win;
    s32 frames;
    if (lbl_805D4E98 == 0) {
        lbl_8048DF44[0] = TObjBoss2Tunnel__data_805D9210 + lbl_80438A68[0];
        lbl_8048DF44[1] = lbl_805D9214 + (lbl_80438A68[1] + lbl_80438A70[1]);
        lbl_805D4E98 = 1;
    }
    if (boss2_tunnel_message_shown_flag == 0) {
        lbl_805D4E9C = lbl_80438A70[0] - lbl_805D9218;
        boss2_tunnel_message_shown_flag = 1;
    }
    win = (VObj_8007C8AC *)TWindowMessage::create((s32)lbl_80438A68, (s32)lbl_80438A70, (u32)1, 4);
    if (win != NULL) {
        switch (arg0) {
        case -2:
        case -9:
            ((TWindowMessage *)win)->append_line(get_localized_text_entry(0x24, 3), 3);
            break;
        case -4:
            ((TWindowMessage *)win)->append_line(get_localized_text_entry(0x24, 0xD), 3);
            break;
        default:
            ((TWindowMessage *)win)->append_line(get_localized_text_entry(0x24, 0xC), 3);
            break;
        }
        ((TWindowBase *)win)->set_depth(lbl_805D921C);
        ((TWindowMessage *)win)->complete_reveal();
    }
    if (get_main_phase() == 0xF) {
        reset_state_flags__6TLobbyFv();
    }
    frames = 0;
    for (;;) {
        frames++;
        func_803DCDFC__Fv();
        controller_stuff();
        if (camera_ctrl_instance != 0U) {
            ((TCameraCtrl *)camera_ctrl_instance)->setup_default_view(0);
        }
        main_task.render();
        if ((f32)frames >= lbl_805D9220) {
            break;
        }
        TLobby::wait_ready_loop();
        if (func_801A5E54__Fv() != 0) {
            break;
        }
        render_tick();
    }
    if (get_main_phase() == 0xF) {
        process_deferred_player_setup__6TLobbyFv();
    }
    if (win != NULL) {
        delete win;
    }
}

void TObjBoss2Tunnel__sub_8007CAE8(u32 arg0) {
    Stack_8007CAE8 stack;
    if (arg0 == 0U) {
        stack.sp10 = lbl_805D9224;
        stack.sp14 = lbl_805D9228;
    } else {
        ((TWindowSubSymbolChatPartsSet *)(&stack.sp10))->copy_vec2((void *)arg0);
    }
    stack.sp8 = lbl_805D922C;
    stack.spC = lbl_805D9230;
    draw_textured_screen_quad__10TObjPlayerFUlPfPfl(-1, &stack.sp10, &stack.sp8, 1, lbl_805D922C);
}

bool TObjBoss2Tunnel::verify_snapshot_checksum() {
    Load_8007CB50 ld;
    s32 *p;
    s32 saved;
    s32 sum;
    if ((u32)TAdPlayerLoadGC__sub_801E1538(&ld, TObjBoss2Tunnel__snapshot_buffer) == 0xFFFFFF20) {
        return false;
    }
    p = ld.data;
    saved = *p;
    *p = 0;
    sum = TAdSinglePlyChrSelectGC__sub_80201204((u8 *)ld.data, 0x1818C);
    *p = saved;
    return sum == saved;
}

s32 TObjBoss2Tunnel::load_snapshot() {
    Stack_8007CBC4 stack;
    s32 buf;
    if (TAdPlayerLoadGC__sub_801E1B50(1) == 0) {
        if (((s32) (*(u16 *)&TObjBoss2Tunnel__snapshot_state) != 0) && ((s32) (*(u16 *)&TObjBoss2Tunnel__snapshot_state) >= 0) && ((s32) (*(u16 *)&TObjBoss2Tunnel__snapshot_state) < 3)) {
            buf = TObjPlayer__sub_800845F8();
            if (TAdPlayerLoadGC__sub_801E1538(&stack.sp8, TObjBoss2Tunnel__snapshot_buffer) == 0) {
                memcpy(buf, (void *)(stack.sp60 + 8), 0x1818C);
                DCFlushRange(buf, 0x1818C);
            }
            lbl_805D49B4 = 0;
        }
        return 1;
    }
    return 0;
}
}

s32 save_screen_snapshot(void) {
    if (memcard_check_snapshot(1, 0) == 0) {
        return 0;
    }
    if (TAdSinglePlyChrSelectGC::load_player_slot(1, (const char *)TObjBoss2Tunnel__data_80438A08, (void *)TObjBoss2Tunnel__snapshot_buffer) != 0) {
        return 0;
    }
    TObjBoss2Tunnel__snapshot_state = 2;
    return 1;
}

s32 TObjBoss2Tunnel::save_snapshot_to_card() {
    Card_8007CCD0 c;
    s32 *p;
    if (memcard_check_snapshot(1, 0) == 0) {
        return 0;
    }
    if ((u32)TObjBoss2Tunnel__snapshot_buffer == 0) {
        return 0;
    }
    memset((void *)TObjBoss2Tunnel__snapshot_buffer, 0, 4);
    memset(&c, 0, 0x60);
    strcpy(c.file, lbl_804C8974);
    strcpy(c.title, lbl_80438A28);
    memcpy((int)c.icon, lbl_80438A4C, 0x10);
    TAdPlayerLoadGC__sub_801E14E8((u8 *)&c, 4);
    c.f4c = 1;
    p = boss2_tunnel_snapshot_buffer;
    c.f4e = 1;
    c.f50 = 0;
    c.f54 = 0;
    *p = 0;
    *p = TAdSinglePlyChrSelectGC__sub_80201204((u8 *)boss2_tunnel_snapshot_buffer, 0x1818C);
    c.size = 0x1818C;
    c.data = boss2_tunnel_snapshot_buffer;
    build_save_file_image__15TAdPlayerLoadGCFPvPv(TObjBoss2Tunnel__snapshot_buffer, &c, boss2_tunnel_snapshot_buffer);
    TAdPlayerLoadGC__sub_801E14E4(&c);
    if (load_player__23TAdSinglePlyChrSelectGCFllll(1, TObjBoss2Tunnel__data_80438A08, TObjBoss2Tunnel__snapshot_buffer, 0xF) != 0) {
        return 0;
    }
    lbl_805D49B4 = 1;
    TObjBoss2Tunnel__snapshot_state = 1;
    return 1;
}
