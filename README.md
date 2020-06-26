# turingMachine
This project was a personal challenge that arose from the curiosity to see, in practice, a Turing machine in operation.

This implementation allows you to code a "program" in "Turing language", that is, in the following mathematical notation:

The "commands" of the Turing machine are defined through quintuplets, which have the format (S, I, NS, O, M), where:

* S = It is the state with which an entry symbol must be matched.
* I = It is an input symbol.
* NS = It is the state resulting from the transition function, that is, the state that the machine will be in.
* O = It is an output symbol.
* M = It is the movement that will be performed by the Reading / Writing head, that is, moving to the right or to the left.

These "commands" are actually a function of state transition.

The following image is a representation of a Turing machine:
![representation of a Turing machine](/img/machine.png)

Initially, the Turing machine is in the S0 state and positioned on the leftmost non-white cell. If all cells are white (B), the control unit can be positioned over any one of them.

A Turing machine can be considered a very simple version of a computer, for the following reasons:

* Has a processing unit with finite memory (finite number of states);
* Has a second storage unit of infinite capacity (data tape);
* The transition function is the computer's “program”; it is a partial function.

Initially, I implemented a “Turing program” that was used as an example in the classroom, which aimed to add two positive integers, with the limitation that the sum must have only two plots (two numbers).

Turing machines can be used to implement functions whose domain are vectors of natural numbers and which return a natural number. For this, unary representation is used, in which a non-negative integer n is represented by n + 1 "1". The various components of the vector are separated from each other by a + sign.

During the implementation, I developed the “Turing program” that performed the sum of several numbers.

Any other “Turing program” can be implemented. To facilitate the writing of these "programs" I chose to keep the notation used in mathematics, the aforementioned quintuplets.

Below we can check the result of the sum: 2 + 2 + 1 + 2 = 7 (which is equivalent to a sequence of eight numbers 1).

![Sum of multiple numbers](/img/result.png)

If you want to see a physical implementation of a Turing machine, I leave you with two videos. The first is a digital version, while the second is a mechanical version:

* [A Turing Machine - Overview](https://www.youtube.com/watch?v=E3keLeMwfHY)
* [Mechanical Turing Machine in Wood](https://www.youtube.com/watch?v=vo8izCKHiF0)