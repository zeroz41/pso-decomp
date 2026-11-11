#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubLog.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/player/TObjPlayer.h"

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

extern "C" {

void TWindowCtrl__sub_8024ADAC(s32 arg0);
void TWindowSubTradeMain__sub_802D2870(void);
void fn_8024AB54(s32 arg0);
int fn_8027B288(void *p);
void fn_8027B2A8(void *);
s32 TLobby__sub_802D2A0C(u32 arg0);

extern void *TWindowSubTradeMain__name;

}
TWindowSubTradeMain::TWindowSubTradeMain(TObject *object, void *arg2) : TObject(object) {
    void *o;
    void *x;
    *(void * *)&this->m_name = TWindowSubTradeMain__name;
    this->m_1c = 0;
    this->m_1d = 0;
    this->m_20 = 0;
    *(void **)((s8 *)this + 0x28) = arg2;
    *(void **)((s8 *)this + 0x2C) = object;
    this->m_30 = 0;
    this->m_34 = 0;
    this->m_38 = 0;
    this->m_3c = 0;
    this->m_40 = 0;
    this->m_44 = 0;
    this->m_48 = 0;
    this->m_4c = 0;
    this->m_24 = -1;
    fn_8024AB54((s32)(*(void **)((s8 *)this + 0x28)));
    TWindowCtrl__sub_8024ADAC((s32)(*(void **)((s8 *)this + 0x28)));
    TLobby__sub_802D2A0C((u32)this);
    TWindowSubTradeMain__sub_802D2870();
    fn_8027B288(*(void **)((s8 *)this + 0x2C));
    o = new TWindowChat(this, (void *)((char *)this + 84));
    *(void **)((s8 *)this + 0x50) = o;
    fn_8027B2A8(*(void **)((s8 *)this + 0x50));
    x = get_player_by_client_id((s32)(*(void **)((s8 *)this + 0x28)));
    if (x != NULL) {
        ((TObjPlayer *)x)->start_freeze();
    }
}
