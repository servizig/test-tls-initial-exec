#include <stdio.h>

#ifdef DLOPEN
#include <dlfcn.h>
#endif

#ifdef LINK
#include "libfoo.h"
#endif

int
main(int argc, char *argv[])
{

#ifdef DLOPEN
	void *foo_handle;
	void *(*set_value)(void);
	void *(*print_value)(void);
	void *(*set_value_through_bar)(void);
	
	foo_handle = dlopen("./libfoo.so", RTLD_LAZY);
	if (foo_handle == NULL) {
		perror("dlopen");
		perror(dlerror());
		return (1);
	}

	set_value = dlsym(foo_handle, "set_value");
	if (set_value == NULL) {
		perror("dlsym");
		dlclose(foo_handle);
		return(1);
	}
	
	print_value = dlsym(foo_handle, "print_value");
	if (print_value == NULL) {
		perror("dlsym");
		dlclose(foo_handle);
		return(1);
	}

	set_value_through_bar = dlsym(foo_handle, "set_value_through_bar");
	if (set_value_through_bar == NULL) {
		perror("dlsym");
		dlclose(foo_handle);
		return(1);
	}

#endif

	set_value();
	print_value();
	set_value_through_bar();
	print_value();

#ifdef DLOPEN
	dlclose(foo_handle);
#endif

	return (0);
}
