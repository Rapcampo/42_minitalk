# Overview

This is one of the 3 projects needed to complete rank 2 of the common core for the 42 programming school, the goal of this project is to learn how signals works and how to communicate between programs through PID numbers.
Another important topic about this project is how to build stable programs that do not easily de-synchronize.

It follow  general guidelines that must be complient with the school ☠️[norm](#the-norm)☠️ for readability of the code. The following are the general rules for this project.
This project is an introduction to variadic functions in C and how they work. As such understanding the functionality of those functions is crucial for this projects as well as a well structured and adaptible code!

### written in C and accordance with the norm 
- Must be completely error free, no seg fault, bus error, double free... undefined is ok, if it happens once. 
- No memory leaks! always free heap memory properly!  
- Must submit a makefile if required, the make file must compile with the usual flags -Werror, -Wextra, -Wall, Makefile must not relink.  
- Must contain the rules $(name), all, clean, fclean and re.  
- If bonuses are wanted, must include a rule in the makefile.  
- Bonuses must be in a different file "_bonus.c or _bonus.h"  if your project allows you to use your libft folder with its makefile. your project makefile must compile the library by using its makefile then the project.
- It is encouraged to create your own test programs.  

## Mandatory part
 
 - Files: Makefile, *.h, */*.h, *.c, */*.c
 - Makefile: NAME, all, clean, fclean, re.
 - External functions:
  ```
  ◦ write 
  ◦ ft_printf and any equivalent YOU coded
  ◦ signal
  ◦ sigemptyset
  ◦ sigaddset
  ◦ sigaction
  ◦ kill
  ◦ getpid
  ◦ malloc
  ◦ free
  ◦ pause
  ◦ sleep
  ◦ usleep
  ◦ exit
```
   
## Technical considerations  
 
- Only one global variable is allowed per program, the use of this variable must be justified.
- Programs must be named Client and Server.
- If you need helper functions to split a more complex function, they must be defined as **static**. so their scope becomes limited to the appropriate file.
- Unused files are forbidden.  
- Every .c file must be compiled with the flags -Wall -Wextra -Werror.
- You can only use these two signals: SIGUSR1 and SIGUSR2.
- Your server should be able to receive strings from several clients in a row without
needing to restart.
- The communication between your client and your server has to be done only using
UNIX signals.
   
# The Norm

The norm is set of rules stipulated by 42 for the pedagogical needs of the school. It enforces these rules through an open source tool called "Norminette", which the students can run to check if their code is complaint. Some of these rules are:

```
- No for, do...while, switch, case, goto, ternary operators and variable-length arrays are allowed
- Each function must be a maximum of 25 lines, not counting the function's curly brackets
- Each line must be at most 80 columns wide, comments included
- A function can take 4 named parameters maximum
- No assigns and declarations in the same line (unless static)
- You can't declare more than 5 variables per function
- 4 space tabulations
- and so on...
```
- [Norminette](https://github.com/42School/norminette) - The tool to enforce the 42 style of coding.
- [42 Header](https://github.com/42Paris/42header) - The header used by 42. To be used with Vim (or Neovim).
