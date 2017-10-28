+ create a *.o file

+ check

    `objdump -ht test.o`

+ copy another file into this *.o file

    `objcopy -I binary -O elf32-i386 -B i386 image.png test.o`

+ check again

    `objdump -ht test.o`

    ```
        test.o:     file format elf32-i386

        Sections:
        Idx Name          Size      VMA       LMA       File off  Algn
        0 .data         0000498d  00000000  00000000  00000034  2**0
                        CONTENTS, ALLOC, LOAD, DATA
        SYMBOL TABLE:
        00000000 l    d  .data  00000000 .data
        00000000 g       .data  00000000 _binary_image_png_start
        0000498d g       .data  00000000 _binary_image_png_end
        0000498d g       *ABS*  00000000 _binary_image_png_size
    ```