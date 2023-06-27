<div id="top"></div>

<!-- PROJECT SHIELDS -->
<br/>
<p align="center">
    <img src="https://github.com/chrisdelmoro/push_swap/blob/main/resources/repo/push_swape.png" alt="Logo" width="150" height="150">

  <p align="center">
    This project objective is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed the student has to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.
    <br/>
    <img src="https://img.shields.io/badge/Mandatory-OK-brightgreen"/>
    <img src="https://img.shields.io/badge/Final%20Score-86-blue"/>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project">About The Project</a></li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

[![Product Name Screen Shot][product-screenshot]](https://github.com/chrisdelmoro/so_long/blob/main/resources/repo/visualizer.gif)

The Push Swap project is a very simple and a highly straightforward algorithm project: data must be sorted.

You have at your disposal a set of integer values, 2 stacks, and a set of instructions
to manipulate both stacks.

The goal is to write a program in C called push_swap which calculates and displays
on the standard output the smallest program, made of Push Swap language instructions,
that sorts the integers received as arguments.

The instructions allowed are:
1. sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
2. sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
3. ss : sa and sb at the same time.
4. pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
5. pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
6. ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
7. rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
8. rr : ra and rb at the same time.
9. rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
10. rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
11. rrr : rra and rrb at the same time.

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- USAGE EXAMPLES -->
## Usage

Clone the repo and make it to compile. Run the binary located at the /bin folder with random number as parameters. The program will
print several instructions on the terminal representing each action that eventually will sort the stack of numbers you prodived as parameters.
You will probably need a visualizer program to actually validate the final stack order. There are several visualizers on github and even online ones.

Here's a few:
* https://github.com/o-reo/push_swap_visualizer
* https://push-swap-visualizer.vercel.app/


<p align="right">(<a href="#top">back to top</a>)</p>


<!-- LICENSE -->
## License

Distributed under the [GNU General Public License version 3 (GPLv3)](https://www.gnu.org/licenses/gpl-3.0.html).

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- CONTACT -->
## Contact

Christian C. Del Moro - christian.delmor@gmail.com

Project Link: [https://github.com/chrisdelmoro/push_swap](https://github.com/chrisdelmoro/push_swap)

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[product-screenshot]: https://github.com/chrisdelmoro/push_swap/blob/main/resources/repo/visualizer.gif
