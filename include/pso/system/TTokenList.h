#ifndef PSO_SYSTEM_TTOKENLIST_H
#define PSO_SYSTEM_TTOKENLIST_H
#include "types.h"
#include "pso/system/task/TObject.h"

// Up to 128 text fields split out of one string (quest script arguments,
// menu entries); render prints each on its own debug-text row from (x, y).
class TTokenList : public TObject {
public:
    TTokenList(TObject *parent, s32 x, s32 y);
    // render is declared before the destructor: the vtable is emitted with
    // render, the destructor lives in another TU.
    virtual void render();
    virtual ~TTokenList();
    // Splits s in place at tabs and newlines; double quotes group a field.
    void tokenize_args(char *s);
    // tokenize_args that also splits at commas.
    void parse_csv_line(char *s);
    void add_token(const char *src);
    void clear();

    char tokens[128][0x20];
    u8 pad_101c[0x80];
    s32 count;
    s32 x;
    s32 y;
};
LAYOUT_ASSERT(TTokenList_size, sizeof(TTokenList) == 0x10A8);

void trim_whitespace(char *text);

#endif
