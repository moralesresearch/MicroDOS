ENTRY(_start)

SECTIONS
{
    . = 0x80000; /* Set the start address of the memory */

    .text : {
        *(.text.boot)    /* Bootloader code */
        *(.text*)        /* Kernel code */
        *(.rodata*)      /* Read-only data */
    }

    .data : {
        *(.data*)        /* Initialized data */
    }

    .bss : {
        __bss_start = .; /* Start address of BSS section */
        *(.bss*)         /* Uninitialized data */
        __bss_end = .;   /* End address of BSS section */
    }

    .heap (NOLOAD) : {
        _heap_start = .; /* Start address of the heap */
        . = . + 0x100000; /* Define the heap size, e.g., 1 MB */
        _heap_end = .;   /* End address of the heap */
    }

    /DISCARD/ : {
        *(.note*)
        *(.comment*)
        *(.debug*)
        *(.gnu*)
    }
}