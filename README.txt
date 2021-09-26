elevator.c is a program that simulates elevators in CODA for analysis their wait times 


Ran on Windows Subsystem Linux (WSL) and compile in Bash, the following are instruction on running this code:
    1. Load Vscode or any IDE that remotely connect WSL
    2. Use any WSL distro that uses Bash (This code was create on Ubuntu distro)
    3. cd the directory that holds elevator.c, additional.c, and elevator.h
    4. In the terminal: gcc -Wall elevator.c additional.c -o run
    5. To output the code: ./run 
