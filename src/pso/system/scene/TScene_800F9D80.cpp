#include "types.h"
#include "pso/system/scene/TScene.h"
#include "pso/unk/TLobby.h"

extern "C" {

int get_resource_file_size__6TLobbyFv(void*);

int TScene::update_lobby_scene() { return get_resource_file_size__6TLobbyFv(this); }

}
