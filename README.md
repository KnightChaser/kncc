# kncc

## Build & run

```bash
meson setup builddir --native-file=clang.ini
meson compile -C builddir
./builddir/kncc
```

Install:

```bash
meson install -C builddir
```

Run input: Suppose `input` is located in the build directory as well as compiled `kncc`.

```bash
./src/kncc input
bat ./out.s

nasm -f elf64 out.s -o out.o
gcc -no-pie out.o -o out
echo "Assembly and linking finished."

./out
```
