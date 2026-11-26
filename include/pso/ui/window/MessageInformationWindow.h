#ifndef PSO_UI_WINDOW_MESSAGEINFORMATIONWINDOW_H
#define PSO_UI_WINDOW_MESSAGEINFORMATIONWINDOW_H

#include "types.h"

struct NJS_POINT2;
struct TWindowMessageInfomation;

TWindowMessageInfomation *create_message_information_window(const NJS_POINT2 *position, const void *extent, saddr client);

#endif
