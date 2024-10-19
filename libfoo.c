#include <stdio.h>

#include "libfoo.h"
#include "libbar.h"

void
set_value(void)
{
	fprintf(stderr, "foo::set_value:before \t&bar_tls=%p bar_tls=%d\n", &bar_tls, bar_tls);
	bar_tls = 1303;
	fprintf(stderr, "foo::set_value:after  \t&bar_tls=%p bar_tls=%d\n", &bar_tls, bar_tls);
}

void
print_value(void)
{
	fprintf(stderr, "foo::print_value  \t&bar_tls=%p bar_tls=%d\n", &bar_tls, bar_tls);
	print_bar_tls();
}

void
set_value_through_bar(void)
{
	set_bar_tls(7);
}
