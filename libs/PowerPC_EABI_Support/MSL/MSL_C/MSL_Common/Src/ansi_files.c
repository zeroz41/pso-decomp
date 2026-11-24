#include "MSL_C/ansi_files.h"

char stdin_buff[0x100];
char stdout_buff[0x100];
char stderr_buff[0x100];

files __files = {
    {
        0,
        0,
        1,
        1,
        2,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        { 0, 0 },
        { 0, 0 },
        0,
        (unsigned char*)&stdin_buff,
        0x100,
        (unsigned char*)&stdin_buff,
        0,
        0,
        0,
        0,
        NULL,
        __read_console,
        __write_console,
        __close_console,
        NULL,
        &__files._stdout,
    },
    {
        1,
        0,
        2,
        1,
        2,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        { 0, 0 },
        { 0, 0 },
        0,
        (unsigned char*)&stdout_buff,
        0x100,
        (unsigned char*)&stdout_buff,
        0,
        0,
        0,
        0,
        NULL,
        __read_console,
        __write_console,
        __close_console,
        NULL,
        &__files._stderr,
    },
    {
        2,
        0,
        2,
        0,
        2,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        { 0, 0 },
        { 0, 0 },
        0,
        (unsigned char*)&stderr_buff,
        0x100,
        (unsigned char*)&stderr_buff,
        0,
        0,
        0,
        0,
        NULL,
        __read_console,
        __write_console,
        __close_console,
        NULL,
        &__files.empty,
    },
};

void __close_all(void) {
    FILE* p = &__files._stdin;
    FILE* plast;

	while(p != NULL)
	{
		if (p->file_mode.file_kind != __closed_file)
		{
			fclose(p);
		}

		plast = p;
		p     = p->next_file;
		if (plast->is_dynamically_allocated)
			free(plast);
		else
		{
			plast->file_mode.file_kind = __unavailable_file;
			if ((p != NULL) && p->is_dynamically_allocated)
				plast->next_file = NULL;
		}
	}
}

unsigned int __flush_all(void)
{
    unsigned int retval = 0;
    FILE* __stream;
    __stream = &__files._stdin;
    while (__stream) {
        if ((__stream->file_mode.file_kind) && (fflush(__stream))) {
        retval = -1;
        }
        __stream = __stream->next_file;
    };
    return retval;
}
