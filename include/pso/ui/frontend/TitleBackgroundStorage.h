#ifndef PSO_UI_FRONTEND_TITLE_BACKGROUND_STORAGE_H
#define PSO_UI_FRONTEND_TITLE_BACKGROUND_STORAGE_H

class TObject;
class TAdBackGC;
class TAdBackTxtGC;

// CodeWarrior constructor entry points for callers that allocate task storage separately.
extern "C" {
TAdBackGC *__ct__9TAdBackGCFP7TObject(void *storage, TObject *parent);
TAdBackTxtGC *__ct__12TAdBackTxtGCFP7TObject(void *storage, TObject *parent);
}

#endif
