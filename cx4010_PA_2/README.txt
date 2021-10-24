wordchain.c is a program that finds the shortest path between two 4-letter words 


Ran on Windows Subsystem Linux (WSL) and compile in Bash, the following are instruction on running this code:
    1. Load Vscode or any IDE that remotely connect WSL
    2. Use any WSL distro that uses Bash (This code was create on Ubuntu distro)
    3. cd the directory that holds wordchains.c, additional.c, and wordchains.h
    4. In the terminal: gcc -Wall wordchains.c additional.c -o run
    5. To output the code: ./run <start index> <end index>
        example: ./run 9 10 --> ball -> tall -> talk -> tank -> bank -> band