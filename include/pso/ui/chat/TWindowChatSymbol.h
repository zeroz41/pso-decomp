#ifndef PSO_UI_CHAT_TWINDOWCHATSYMBOL_H
#define PSO_UI_CHAT_TWINDOWCHATSYMBOL_H

#include "types.h"

struct NJS_POINT2;
#include "pso/ui/window/TWindowBase.h"

struct SymbolChatPreset;

struct TWindowChatSymbol : public TWindowBase {
    TWindowChatSymbol(const NJS_POINT2 *position, saddr size);
    virtual ~TWindowChatSymbol();
    void set_selection(SymbolChatPreset *preset);
    void set_from_key(s32 index);
    void update_visibility();
    virtual void render();
    SymbolChatPreset *selected_preset;
    u32 always_visible;
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowChatSymbol_size, sizeof(TWindowChatSymbol) == 0x68);

struct WindowLayoutEntries;
class WindowSpritePart;
extern "C" {
void get_symbol_chat_frame_size(int a0, void *a1);
void apply_face_appearance_sprite(WindowLayoutEntries *entries, u8 appearance);
}
int set_symbol_chat_face_sprite(WindowSpritePart *sprite, u8 b);
void set_symbol_chat_parts(WindowLayoutEntries *entries, void *data);

#endif
