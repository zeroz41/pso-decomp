#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdGameStartGC.h"
#include "pso/system/byteswap.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/object/ending/TObjOnlineEndingHexLine.h"
#include "pso/system/ControllerInput.h"
#include "pso/render/GinjaTexture.h"
#include "pso/player/TObjPlayer_8023E480.h"

#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/vector.h"
#include "pso/math/TMath.h"
#include "pso/ui/frontend/TAdGameStartShadowGC.h"
#include "pso/ui/frontend/TAdGameStartBackGC.h"
#include "pso/ui/frontend/TAdGameStartLineGC.h"
#include "pso/ui/frontend/TAdGameStartShineGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"

extern void *ad_game_start_name_ptr[2];


void TAdGameStartGC::bswap_6x92(void *p) {
    G_Unknown_6x92 *cmd = (G_Unknown_6x92 *)p;
    ((G_ClientIDHeader *)&cmd->header)->bswap();
    bswap_32(&cmd->client_id);
    bswap_32((u32 *)&cmd->value);
}
void TAdGameStartGC::send_6x92(void *p) { bswap_6x92(p); send_subcommand((u8 *)p); }
void TAdGameStartGC::init_6x92(void *p) {
    G_Unknown_6x92 *cmd = (G_Unknown_6x92 *)p;
    cmd->header.subcommand = 0x92;
    cmd->header.size = 3;
}

void TAdGameStartGC::render() {  }

void TAdGameStartGC::destroy_windows() {
    u32 i;
    if (m_shadow != NULL) {
        m_shadow->queue_destruction();
        m_shadow = NULL;
    }
    if (m_back != NULL) {
        m_back->queue_destruction();
        m_back = NULL;
    }
    if (m_line != NULL) {
        m_line->queue_destruction();
        m_line = NULL;
    }
    if (m_shine != NULL) {
        m_shine->queue_destruction();
        m_shine = NULL;
    }
    for (i = 0; i < 8; i++) {
        if (m_letter_tasks[i] != NULL) {
            m_letter_tasks[i]->queue_destruction();
            m_letter_tasks[i] = NULL;
        }
    }
    m_active = 0;
    m_frame = -1;
}

void TAdGameStartGC::create_effects() {
    m_active = 1;
    if (m_shadow != NULL) {
        m_shadow->queue_destruction();
        m_shadow = NULL;
    }
    if (m_back != NULL) {
        m_back->queue_destruction();
        m_back = NULL;
    }
    if (m_line != NULL) {
        m_line->queue_destruction();
        m_line = NULL;
    }
    if (m_shine != NULL) {
        m_shine->queue_destruction();
        m_shine = NULL;
    }
    m_shadow = new TAdGameStartShadowGC(this);
    m_back = new TAdGameStartBackGC(this);
    m_line = new TAdGameStartLineGC(this);
    m_shine = new TAdGameStartShineGC(this);
}

void TAdGameStartGC::run_task() {
    ControllerInputContext *pad;
    if (m_active != 0) {
        m_frame++;
        if (m_frame < 8) {
            m_letter_tasks[m_frame] = new TAdGameStartSubGC(this, &m_letters[m_frame]);
        }
        if (m_frame > 0x3C) {
            destroy_windows();
            return;
        }
        pad = &controller_physical_port_bank.controllers[TAdMultiPlyChrSelectGC::get_clamped_cursor()];
        if (test_pressed_buttons_packed(pad, 4) != 0) {
            destroy_windows();
        }
        if (test_pressed_buttons_packed(pad, 2) != 0) {
            destroy_windows();
        }
        if (test_pressed_buttons_packed(pad, 8) != 0) {
            destroy_windows();
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)pad, 0x10, 6, 1) != 0) {
            destroy_windows();
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)pad, 0x20, 6, 1) != 0) {
            destroy_windows();
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)pad, 0x40, 6, 1) != 0) {
            destroy_windows();
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)pad, 0x80, 6, 1) != 0) {
            destroy_windows();
        }
    }
}

TAdGameStartGC::~TAdGameStartGC() {}

TAdGameStartGC::TAdGameStartGC(TObject *parent) : TObject(parent) {
    s32 i;
    m_name = (const char *)ad_game_start_name_ptr[0];
    m_frame = -1;
    m_active = 0;
    m_shadow = NULL;
    m_back = NULL;
    m_line = NULL;
    m_shine = NULL;
    for (i = 0; i < 8; i++) {
        m_letters[i].cell = i;
        m_letters[i].x = (94.0f);
        m_letters[i].y = (196.0f);
        m_letters[i].color = -1;
        m_letter_tasks[i] = NULL;
    }
}

void TAdGameStartSubGC::destroy_instance() {
    if (multiplay_texture_f512_handle != NULL) {
        release_texture_list(multiplay_texture_f512_handle);
        multiplay_texture_f512_handle = NULL;
    }
}
extern const unsigned char lbl_80472C28[];
__declspec(section ".data") extern NJS_TEXLIST texture_f512_multiplay_descriptor;
void register_texture_f512_multiplay(void) { multiplay_texture_f512_handle = &texture_f512_multiplay_descriptor; load_streamed_prs_texture((saddr)lbl_80472C28, (saddr)&texture_f512_multiplay_descriptor); }
__declspec(section ".rodata") extern const unsigned char lbl_80472C28[] = "f512_multiplay";
__declspec(section ".rodata") extern const char TAdGameStartGC__class_name_string[] = "TAdGameStartGC";
NJS_TEXNAME lbl_804E3B60[1] = {{(char *)lbl_80472C28, 0, {0}}};
__declspec(section ".data") NJS_TEXLIST texture_f512_multiplay_descriptor = {lbl_804E3B60, 1};
void *ad_game_start_name_ptr[2] = {(void *)TAdGameStartGC__class_name_string, 0};
