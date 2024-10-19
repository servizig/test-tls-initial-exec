typedef void (*funcptr_t)(void);

extern __thread int bar_tls;

void set_bar_tls(int value);

void print_bar_tls();

