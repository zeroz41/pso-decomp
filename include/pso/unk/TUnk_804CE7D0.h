#ifndef PSO_UNK_TUNK_804CE7D0_H
#define PSO_UNK_TUNK_804CE7D0_H
#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowChatSymbol;
struct TWindowSubComCardList;

class TUnk_804CE7D0 : public TObject {
public:
    TUnk_804CE7D0(TObject *parent);
    virtual ~TUnk_804CE7D0();
    virtual void render();
    virtual void run_task();
    TWindowSubComCardList *preset_list;  // the 12 symbol chat presets (inferred)
    TWindowChatSymbol *chat_symbol;  // the symbol chat editor it opens (inferred)
};
LAYOUT_ASSERT(TUnk_804CE7D0_size, sizeof(TUnk_804CE7D0) == 0x24);

#endif
