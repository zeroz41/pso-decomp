#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubLog.h"

extern "C" {

void *__dt__19TWindowSubTradeMainFv(TWindowSubTradeMain *arg0, s16 arg1);
void *get_player_by_client_id(s32 i);
void TWindowCtrl__sub_8024ADF0(s32 arg0);
void TWindowSubComCard__sub_8024AB98(s32 arg0);
s32 __dl__7TObjectFPv(void *);
s32 __dt__7TObjectFv(void *, s32);
s32 end_camera_pan__10TObjPlayerFv();
s32 TLobby__sub_802D29E8(u32 arg0);
void queue_destruction__7TObjectFv(void *arg0);

extern void* __vt__19TWindowSubTradeMain[];

void *__dt__19TWindowSubTradeMainFv(TWindowSubTradeMain *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void **)((s8 *)arg0 + 0x18) = (void *) __vt__19TWindowSubTradeMain;
        TLobby__sub_802D29E8((u32)arg0);
        TLobby::check_flags_and_proceed();
        if (get_player_by_client_id(arg0->m_28) != 0U) {
            end_camera_pan__10TObjPlayerFv();
        }
        if ((u32) arg0->m_50 != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x50));
            arg0->m_50 = 0U;
        }
        if ((u32) arg0->m_4c != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x4C)))->close();
            arg0->m_4c = 0U;
        }
        if ((u32) arg0->m_48 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x48)))->close();
            arg0->m_48 = 0U;
        }
        if ((u32) arg0->m_44 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x44)))->close();
            arg0->m_44 = 0U;
        }
        if ((u32) arg0->m_40 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x40)))->close();
            arg0->m_40 = 0U;
        }
        if ((u32) arg0->m_3c != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x3C)))->close();
            arg0->m_3c = 0U;
        }
        if ((u32) arg0->m_38 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x38)))->close();
            arg0->m_38 = 0U;
        }
        if ((u32) arg0->m_34 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x34)))->close();
            arg0->m_34 = 0U;
        }
        if ((u32) arg0->m_30 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x30)))->close();
            arg0->m_30 = 0U;
        }
        if ((u32) arg0->m_2c != 0U) {
            ((TWindowSubLog *)(*(void **)((s8 *)arg0 + 0x2C)))->cleanup();
        }
        TWindowCtrl__sub_8024ADF0(arg0->m_28);
        TWindowSubComCard__sub_8024AB98(arg0->m_28);
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
