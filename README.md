# AIR 4TH ONE - Mini FORTH Interpreter

![Logo](./Air4TH1.jpg)

AIR 4TH ONE is a minimalist FORTH interpreter designed to be robust, flexible, and easy to use.
Inspired by the principles of FORTH, this project is a great introduction to the power and simplicity of this unique language.
`main.c` is an example of usage to embed it in your own C/C++ programs.
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
git clone https://github.com/your-username/mini-forth-interpreter.git
cd mini-forth-interpreter
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
