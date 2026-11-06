#include "types.h"
#include "pso/quest/TQuestVmDownLoadServer.h"

extern "C" {

int create_message_and_menu__17TWindowSubComCardFUllUlUl(void*, void*, void*, void*, void*);
int close_windows__17TWindowSubComCardFv(void*);

void TQuestVmDownLoadServer::init(void* a1, void* a2, void* a3, void* a4) { close_windows__17TWindowSubComCardFv(this); create_message_and_menu__17TWindowSubComCardFUllUlUl(this, a1, a2, a3, a4); }

}
