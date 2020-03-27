# rpncc
rpncc is a great, simple, easy to use reverse polish notation calculator. It is written in only about 200 lines of c-code.
You can easily modify it to your needs, but it allready comes with basic arithmetic operations and some usefull mathematical constants.
A more detailed description of the functions is given below. You can use all functions from the command line or in the prgramm.

## Commands
'+':	add

'-':	subtract

'*':	multiply

'/':	divide

'p':	constant pi

'e':	constant e

'^':	power

'r':	square root

'!':	clear stack

'?':	help

'.':	quit

(I will add more functions over time.)

## Installation
To install, first clone this repository (or download the zip).

Next you will need to compile the `main.c` file.
If you are running macos, just go into the directory of rpncc and run this `clang main.c` on your command line.
Before that, you may need to install clang.

When compiled, you will find a `a.out` file in this directory.
If you like, rename it by entering `mv a.out name` on your command line. Replace `name` with the name of your choice.

## Usage
You can start the programm with `./a.out`, or enter your calculation behind this command.
To do so, just enter `./a.out number1 number2 operator` on your commandline. Replace `number1` and `number2` with the numbers of your choice
and `operator` with one of the operators listed above. You can add as many numbers as you like. Simply seperate them with spaces.
