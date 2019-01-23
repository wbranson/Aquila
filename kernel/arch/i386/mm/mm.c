/**********************************************************************
 *                  Physical Memory Manager
 *
 *
 *  This file is part of AquilaOS and is released under the terms of
 *  GNU GPLv3 - See LICENSE.
 *
 *  Copyright (C) Mohamed Anwar
 */

#include <core/system.h>
#include <core/string.h>
#include <core/panic.h>
#include <cpu/cpu.h>
#include <boot/multiboot.h>
#include <boot/boot.h>
#include <mm/mm.h>

void arch_mm_setup(void)
{
    /* Fix kernel heap pointer */
    extern char *lower_kernel_heap;
    extern char *kernel_heap;
    kernel_heap = VMA(lower_kernel_heap);

    arch_pmap_init();
}
