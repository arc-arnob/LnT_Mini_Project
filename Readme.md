# SDLC Activity Based Learning
![Banner](https://github.com/arc-arnob/LnT_Mini_Project/blob/main/1_Requirements/banner.png)


Build | Code Quality | Unity | Git Inspector
|---------|------------|-----------|----------------
[![C/C++ CI](https://github.com/arc-arnob/LnT_Mini_Project/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/arc-arnob/LnT_Mini_Project/actions/workflows/c-cpp.yml)|[![Static Check](https://github.com/arc-arnob/LnT_Mini_Project/actions/workflows/arc-cppcheck.yml/badge.svg)](https://github.com/arc-arnob/LnT_Mini_Project/actions/workflows/arc-cppcheck.yml) [![Valgrind-check](https://github.com/arc-arnob/LnT_Mini_Project/actions/workflows/arc-dynamic-code-quality.yml/badge.svg)](https://github.com/arc-arnob/LnT_Mini_Project/actions/workflows/arc-dynamic-code-quality.yml) [![Codacy Badge](https://app.codacy.com/project/badge/Grade/21c5cae1b5844158b9eb3d4c80125c89)](https://www.codacy.com/gh/arc-arnob/LnT_Mini_Project/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=arc-arnob/LnT_Mini_Project&amp;utm_campaign=Badge_Grade) [![Coverage Badge](https://img.shields.io/badge/coverage-98.71%25-blue)]()  | [![Unity-Check](https://github.com/arc-arnob/LnT_Mini_Project/actions/workflows/arc-unity.yml/badge.svg)](https://github.com/arc-arnob/LnT_Mini_Project/actions/workflows/arc-unity.yml) | [![git inspector CI](https://github.com/arc-arnob/LnT_Mini_Project/actions/workflows/arc-gitinspector.yml/badge.svg)](https://github.com/arc-arnob/LnT_Mini_Project/actions/workflows/arc-gitinspector.yml)


## Folder Structure
Folder             | Description
-------------------| -----------------------------------------
`1_Requirements`   | Documents detailing requirements and research
`2_Design`         | Documents specifying design details
`3_Implementation` | All code and documentation
`4_Test_plan`      | Documents with test plans and procedures

## Contributors List and Summary

SF Id. |  Name   |    Features    | Issuess Raised |Issues Resolved|No Test Cases|Test Case Pass
-------|---------|----------------|----------------|---------------|-------------|--------------
`256131` | Arnob Chowdhury  | F_01, F_02, F_03, F_04, F_05, F_06, F_07, F_08, F_09   | 14     | 7   |13  |13     
   

| Feature Id | Feature |
| -----------|---------|
|F_01| Option to load older saved data |
|F_02| Save data to file if only new data is added |
|F_03| Update data in list and file(if in file) |
|F_04| Deleting record automatically updates Record file and Index File |
|F_05| New records gets saved in file at program shut down |
|F_06| Before program shut down all memory is freed and clean |
|F_07| Used Binary File System for quick access to files |
|F_08| Search of Data is possible from both List and file |
|F_09| Dynamic memory allocation and deallocation implemented |

## Challenges Faced and How Was It Overcome
| No. | Challenge | Solution
|-----|-----------|--------
|1. | Code Crashed without any error message (Segmentation Fault) | GDB tool helped to pin point the Invalid Read 
|2. | After program shut down, there was no way to recover data | Implemented File System |
|3. | IOWITHOUTPOSITIONING Error | Check if fseek() != -1 between consecutive read and write calls
|4. | Structure Padding causing write to uninitialized location(Still Reachable code error) | Won't Fix, need help
|5. | Requirement gathering proved to be challenging, mainly ageing | Read multiple Research papers to find about history of management systems 
|6. | gcov generating *.gcda and *.gcno files in different directory than object file | added few extra steps in make file under coverage, made a copy of .c file in current directory and ran coverage then deleted all the unnecessary files.


