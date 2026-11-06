#ifndef PSO_UI_FRONTEND_TADGAMESTARTGC_H
#define PSO_UI_FRONTEND_TADGAMESTARTGC_H

#include "types.h"

extern "C" {
void TAdGameStartGC__sub_802E6368(void *p);
u8 *__ct__17TAdGameStartSubGCFv(u8 *arg0, void *arg1, u8 *arg2);
void bswap_6x92__14TAdGameStartGCFPv(void *p);
void create_effects__14TAdGameStartGCFPv(u8 *parent);
void destroy_instance__17TAdGameStartSubGCFv(void);
void draw_background__17TAdGameStartSubGCFPv(u8 *arg0);
}
void register_texture_f512_multiplay(void);
extern "C" {
void render__14TAdGameStartGCFv(void);
void render__17TAdGameStartSubGCFv(void *p);
void run_task__14TAdGameStartGCFv(u8 *arg0);
void run_task__17TAdGameStartSubGCFv(u8 *arg0);
void send_6x92__14TAdGameStartGCFPv(void *p);
}

#endif
