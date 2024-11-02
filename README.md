# AIR 4TH ONE - Mini FORTH Interpreter

![Logo](./Air4TH1.jpg)

**AIR 4TH ONE** is a highly modular and simple implementation of a mini FORTH interpreter. Designed with extensibility in mind, this project provides an excellent platform for learning and developing in C.

Embark on an exciting journey by creating or extending a small FORTH compiler. Whether you're diving into C programming for the first time or enhancing your existing skills, this project is your gateway to mastering the art of FORTH interpreters.

While AIR 4TH ONE doesn't aim to be as comprehensive as gForth, it serves as a practical tool for educational purposes, offering a robust starting point for exploring the fascinating world of FORTH.

Feel free to use it as a base to create your own FORTH, or to take inspiration and build your FORTH interpreter from scratch.


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
