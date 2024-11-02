# AIR 4TH ONE - Mini FORTH Interpreter

![Logo](./Air4TH1.jpg)

**AIR 4TH ONE** is a highly modular and simple implementation of a mini FORTH interpreter. Designed with extensibility in mind, this project provides an excellent platform for learning and developing in C.

Creating or extending a small FORTH compiler is an outstanding theme for those who want to dive into C programming or enhance their existing skills. While this project doesn't aim to be as comprehensive as gForth, it serves as a practical tool for educational purposes and offers a robust starting point for exploring the fascinating world of FORTH interpreters.

Feel free to use it at a base to create your own Forth, or to have a look at it to create your own FORTH interpreter from scratch.

## Features

- Creation of simple variables and arrays
- Management of basic commands like `+`, `-`, `*`, `/`, `dup`, `drop`, `swap`, etc.
- Advanced stack manipulation with `rot`, `tuck`, `over`, etc.
- Support for defining and manipulating variables and arrays

## Requirements

- GCC or another C compiler
- Git to clone the repository

## Installation

Clone the repository and compile the project:

```bash
git clone https://github.com/majukarma/AIR4THONE.git
cd AIR4THONE
make all
```

## Usage

Run the interpreter with:
```bash
./forth_interpreter
```

Example commands:

```forth
1 2 + .
3 4 * .
2 cell * VAR array
array 2 cell + !
array 2 cell + @ .
```

## Contributing

Contributions are welcome! To report bugs, suggest features, or contribute code, please see our [contributing guidelines](https://contributing.md/).

## License

This project is released under the CC0 1.0 Universal (CC0 1.0) Public Domain Dedication.
While not required, we kindly request that you attribute this project to its original creators if you use it in your own work.
This project is intended for educational purposes only. The authors disclaim any responsibility for any damages or issues
that arise from its use in a production environment. See [LICENCE.md](./LICENCE.md) file in this project for more details.
