#include <stdio.h>

#include "libbar.h"

__thread int bar_tls;

void
set_bar_tls(int value)
{
	fprintf(stderr, "bar::set_bar_tls:before &bar_tls=%p bar_tls=%d\n", &bar_tls, bar_tls);
	bar_tls = value;
	fprintf(stderr, "bar::set_bar_tls:after  &bar_tls=%p bar_tls=%d\n", &bar_tls, bar_tls);}

void
print_bar_tls()
{
	fprintf(stderr, "bar::print_bar_tls  \t&bar_tls=%p bar_tls=%d\n", &bar_tls, bar_tls);
}

