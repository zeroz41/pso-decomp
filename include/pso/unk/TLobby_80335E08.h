#ifndef PSO_UNK_TLOBBY_80335E08_H
#define PSO_UNK_TLOBBY_80335E08_H

#include "types.h"

class TTitleScene;
struct NJS_TEXLIST;

// The title texture list's release and load hooks in lobby_load_callback_table; both do nothing.
void free_title_texture_resources();
void load_title_texture_resources();
int get_transition_cursor(TTitleScene *scene);
void bind_title_texture_list(void);
NJS_TEXLIST *get_title_texture_list(void);


#endif
