#ifndef PSO_UI_WINDOW_WINDOWCALLBACK_H
#define PSO_UI_WINDOW_WINDOWCALLBACK_H

// The callback receives the borrowed window and its draw context for the current frame.
typedef void (*WindowCallback)(void *window, void *frame_context);

#endif
