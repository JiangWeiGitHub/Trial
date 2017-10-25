+ create a *.o file

+ check

    `objdump -ht test.o`

+ copy another file into this *.o file

    `objcopy -I binary -O elf32-i386 -B i386 image.png test.o`

+ check again

    `objdump -ht test.o`