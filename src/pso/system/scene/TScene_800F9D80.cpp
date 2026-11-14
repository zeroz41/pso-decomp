#include "types.h"
#include "pso/system/scene/TScene.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby.h"

extern "C" {

int TScene::update_lobby_scene() { return ((TLobby *)this)->get_resource_file_size(); }

}
