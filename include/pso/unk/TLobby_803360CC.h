#ifndef PSO_UNK_TLOBBY_803360CC_H
#define PSO_UNK_TLOBBY_803360CC_H

#include "types.h"

class TTitleScene;

extern "C" {
void TAdMultiPlyChrSelectGC__sub_803367E8(void);
void TLobby__sub_803361FC(void);
void TLobby__sub_803362A4(TTitleScene *scene);
void render__11TTitleSceneFv(void);
void destroy_download_server__6TLobbyFPv(void *_w0);
}
void initialize_lobby_title_scene(void);

#endif
