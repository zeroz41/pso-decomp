#ifndef PSO_QUEST_TQUESTLISTOFFLINE_H
#define PSO_QUEST_TQUESTLISTOFFLINE_H
#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"

class TQuestListOffline : public TShopWindowBase {
public:
    virtual ~TQuestListOffline();
    void *close_shop_subwindows(s16);
    void init_quest_list_window();
    virtual void vfunc_11();
    u8 unk_1C[0x1C];
    void * m_38;
    u8 unk_3C[0x4];
    void * m_40;
    u8 unk_44[0x14];
public:
    void update_list_navigation();
};
typedef char TQuestListOffline_size[sizeof(TQuestListOffline) == 0x58 ? 1 : -1];

#endif
