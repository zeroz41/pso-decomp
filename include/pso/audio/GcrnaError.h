#ifndef PSO_AUDIO_GCRNA_ERROR_H
#define PSO_AUDIO_GCRNA_ERROR_H

typedef void (*GcrnaErrorCallback)(void* context, const char* message);

#ifdef __cplusplus
extern "C" {
#endif

extern char gcrna_error_text[256];
extern GcrnaErrorCallback gcrna_error_callback;
extern void* gcrna_error_context;

void gcrna_report_error(const char* message);
void gcrna_error_set_callback(GcrnaErrorCallback callback, void* context);
void gcrna_error_shutdown(void);
void gcrna_error_initialize(void);

#ifdef __cplusplus
}
#endif

#endif
