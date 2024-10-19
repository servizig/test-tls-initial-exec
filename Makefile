.PHONY: all clean

all: app-link app-dlopen libfoo.so libbar.so

clean:
	rm -f app-link app-dlopen libfoo.so libbar.so *.core

test: all
	LD_LIBRARY_PATH=. ./app-link
	LD_LIBRARY_PATH=. ./app-dlopen

app-link: app.c libfoo.so libbar.so
	$(CC) -g -Wall -O0 -DLINK -I. -L. -lfoo -lbar -o $@ app.c

app-dlopen: app.c libfoo.h libfoo.so libbar.h libbar.so
	$(CC) -g -Wall -O0 -DDLOPEN -o $@ app.c

libfoo.so: libfoo.c libfoo.h libbar.h libbar.so
	$(CC) -g -Wall -O0 -shared -fPIC -I. -L. -lbar -ftls-model=initial-exec -o $@ libfoo.c

libbar.so: libbar.c libbar.h
	$(CC) -g -Wall -O0 -shared -fPIC -o $@ libbar.c
