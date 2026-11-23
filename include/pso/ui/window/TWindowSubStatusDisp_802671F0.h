#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_802671F0_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_802671F0_H

#include "types.h"

class TWindowBase;
class TWindowMenuIconLine;
struct NJS_POINT2;

extern "C" {
void TAdVIConfigGC__sub_80267704(s32 arg0);
void add_battle_stat_entry(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void advance_status_disp_entry(TWindowBase *window_base, s32 arg1);
TWindowMenuIconLine *fn_80267F38(saddr parent, saddr position, uaddr count, s16 client);
void push_status_disp_entry(void *arg0, s32 count, s32 id);
void TShopJudgmentItemWindow__sub_80267F9C(const NJS_POINT2 *size, s32 count);
}

#endif
