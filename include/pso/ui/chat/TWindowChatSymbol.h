#ifndef PSO_UI_CHAT_TWINDOWCHATSYMBOL_H
#define PSO_UI_CHAT_TWINDOWCHATSYMBOL_H

#include "types.h"

struct NJS_POINT2;
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/WindowLayoutRecord.h"

struct SymbolChatPreset;
struct SymbolChatPart;

struct TWindowChatSymbol : public TWindowBase {
    static const char *class_name;
    TWindowChatSymbol(const NJS_POINT2 *position, const NJS_POINT2 *size);
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
void get_symbol_chat_frame_size(WindowLayoutEntries *entries, f32 *size);
void apply_face_appearance_sprite(WindowLayoutEntries *entries, u8 appearance);
int set_symbol_chat_face_sprite(WindowSpritePart *sprite, u8 b);
void set_symbol_chat_parts(WindowLayoutEntries *entries, void *data);

struct SymbolChatSpriteLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord recs[25];
};

void apply_part_to_window(WindowLayoutEntries *entries, SymbolChatPart *part, s32 index);
// Lays a balloon's entries out as the symbol chat's sprite grid.
void init_symbol_chat_layout_entries(WindowLayoutEntries *entries, saddr player);

#endif
