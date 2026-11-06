#include "types.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void *get_player_by_client_id(s32 i);
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
