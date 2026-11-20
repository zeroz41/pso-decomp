#include <string.h>
#include "pso/audio/GcrnaError.h"

extern "C" {

void gcrna_report_error(const char* message) {
    strncpy(gcrna_error_text, message, 255);
    if (gcrna_error_callback != 0) {
        gcrna_error_callback(gcrna_error_context, gcrna_error_text);
    }
}

void gcrna_error_set_callback(GcrnaErrorCallback callback, void* context) {
    gcrna_error_callback = callback;
    gcrna_error_context = context;
}

void gcrna_error_shutdown(void) {
    memset(gcrna_error_text, 0, sizeof(gcrna_error_text));
    gcrna_error_callback = 0;
    gcrna_error_context = 0;
}

void gcrna_error_initialize(void) {
    memset(gcrna_error_text, 0, sizeof(gcrna_error_text));
    gcrna_error_callback = 0;
    gcrna_error_context = 0;
}

char gcrna_error_text[256];
GcrnaErrorCallback gcrna_error_callback;
void* gcrna_error_context;
}
