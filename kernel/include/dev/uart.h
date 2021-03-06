#ifndef _UART_H
#define _UART_H

#include <fs/vfs.h>
#include <dev/tty.h>

struct uart {
    char *name;

    struct ringbuf *in;
    struct ringbuf *out;

    struct tty   *tty;
    struct inode *inode;    /* Inode associated with uart device */

    void    (*init)    (struct uart *u);
    ssize_t (*transmit)(struct uart *u, char c);
    char    (*receive) (struct uart *u);
};

int  uart_register(int id, struct uart *u);
void uart_recieve_handler(struct uart *u, size_t size);
void uart_transmit_handler(struct uart *u, size_t size);

#endif /* ! _UART_H */
