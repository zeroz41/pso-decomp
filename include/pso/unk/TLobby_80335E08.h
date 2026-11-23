#ifndef PSO_UNK_TLOBBY_80335E08_H
#define PSO_UNK_TLOBBY_80335E08_H

#include "types.h"

class TTitleScene;
struct NJS_TEXLIST;

extern "C" {
void TLobby__sub_80335E74(void);
void TLobby__sub_80335E78(void);
void TLobby__sub_80335FE0(void);
void TLobby__sub_80335FE4(void);
int TLobby__sub_80336030(TTitleScene *scene);
}
void bind_title_texture_list(void);
NJS_TEXLIST *get_title_texture_list(void);


#endif
