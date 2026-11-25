#ifndef PSO_UNK_TSYMBOLCHATMENU_H
#define PSO_UNK_TSYMBOLCHATMENU_H
#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowChatSymbol;
struct TWindowSubComCardList;

class TSymbolChatMenu : public TObject {
public:
    TSymbolChatMenu(TObject *parent);
    virtual ~TSymbolChatMenu();
    virtual void render();
    virtual void run_task();
    int get_selected_index();
    int is_decided();
    int is_cancelled();
    TWindowSubComCardList *preset_list;  // the 12 symbol chat presets (inferred)
    TWindowChatSymbol *chat_symbol;  // the symbol chat editor it opens (inferred)
};
LAYOUT_ASSERT(TSymbolChatMenu_size, sizeof(TSymbolChatMenu) == 0x24);

#endif
