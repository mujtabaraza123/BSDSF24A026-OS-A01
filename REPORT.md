# Operating Systems Programming Assignment 01

**Student Name:** Mujtaba Raza  
**Roll Number:** BSDSF24A026  
**Course:** Operating Systems  
**Instructor:** Muhammad Arif Butt, PhD  

---

# Part 2: Multi-file Project

## Question 1

The rule:

$(TARGET): $(OBJECTS)

means that the final executable depends on all the object files. The object files are compiled separately and then linked together to create the final executable `bin/client`.

In this project, the object files are:

- `obj/main.o`
- `obj/mystrfunctions.o`
- `obj/myfilefunctions.o`

In a library-based rule, the main object file is linked against a library such as `libmyutils.a`. Therefore, Part 2 directly links object files, while Part 3 links the main object file with a library.

## Question 2

A Git tag is a name given to a specific commit. It is useful for marking important versions of a project.

The tags used in this project include:

- `v0.1.1-multifile`
- `v0.2.1-static`
- `v0.3.1-dynamic`
- `v0.4.1-final`

A simple tag is a lightweight pointer to a commit.

An annotated tag is a complete Git object that contains additional information such as the tag message, tagger, and date. Annotated tags are useful for official project versions and releases.

## Question 3

A GitHub Release is used to publish a specific version of a project. It is normally associated with a Git tag and can contain a release title, description, and compiled files.

Attaching binaries such as `bin/client` allows users to download and run the compiled program without compiling the source code themselves.

---

# Part 3: Static Library

## Question 4

In Part 2, the Makefile directly links the object files to create `bin/client`.

In Part 3, additional variables and rules were added for the static library:

STATIC_LIB = lib/libmyutils.a

STATIC_TARGET = bin/client_static

The object files containing the utility functions are first combined into `libmyutils.a` using the `ar` command.

Then `main.o` is linked with the static library to create `bin/client_static`.

Therefore, Part 3 differs from Part 2 because the utility functions are packaged into a reusable static library before linking the final program.

## Question 5

The `ar` command is used to create and manage archive files.

In this project, it was used to create the static library:

ar rcs lib/libmyutils.a obj/mystrfunctions.o obj/myfilefunctions.o

The options mean:

- `r` = insert or replace files
- `c` = create the archive
- `s` = create a symbol index

`ranlib` is traditionally used to create or update the symbol index of a static library. In this project, the `s` option of `ar` already creates the symbol index, so a separate `ranlib` command is not required.

## Question 6

Yes, symbols for functions such as `mystrlen`, `mystrcpy`, `mystrncpy`, `mystrcat`, `wordCount`, and `mygrep` are present in the static executable.

This happens because static linking copies the required code from the static library into the final executable.

Therefore, the final executable contains the required library code and does not need `libmyutils.a` at runtime.

---

# Part 4: Dynamic Library

## Question 7

Position-Independent Code, or PIC, is code that can execute correctly regardless of where it is loaded into memory.

The `-fPIC` option was used when compiling the source files for the shared library.

For example:

gcc -fPIC -Iinclude -c src/mystrfunctions.c

Shared libraries can be loaded at different memory addresses. Therefore, their code needs to be position-independent.

The shared library created in this project is:

`lib/libmyutils.so`

## Question 8

The observed file sizes in this project were approximately:

`client_static` = 17K

`client_dynamic` = 16K

The static executable is slightly larger because the required utility code from the static library is included inside the executable.

The dynamic executable is slightly smaller because the utility code remains in the separate shared library `libmyutils.so` and is loaded at runtime.

Therefore, static linking includes library code in the executable, while dynamic linking keeps the library separate.

## Question 9

`LD_LIBRARY_PATH` is an environment variable that tells the dynamic loader where to search for shared libraries.

In this project, the shared library was located in the project's `lib` directory.

The following command was used:

export LD_LIBRARY_PATH=$PWD/lib:$LD_LIBRARY_PATH

After setting this variable, `client_dynamic` was able to find `libmyutils.so` and run successfully.

This shows that the dynamic loader is responsible for locating and loading the shared libraries required by a dynamically linked program.

---

# Conclusion

This assignment demonstrated the development of a C utility library through multiple stages.

The project was first developed as a multi-file C program, then converted into a static library and finally into a dynamic library.

Git branches, commits, tags, and GitHub Releases were used to manage the different development stages.

The final stage added manual pages and installation support.

The main concepts learned were:

- Multi-file compilation
- Object files
- Linking
- Makefiles
- Static libraries
- Dynamic libraries
- Position-Independent Code
- Git branches
- Git tags
- GitHub Releases
- Dynamic library loading
- Manual pages
- Linux installation
