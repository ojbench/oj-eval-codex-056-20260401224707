# Problem 056 - m0ss1 的翘课系统

**ACMOJ Problem ID**: 2673

## Table of Contents

- [Problem 056 - m0ss1 的翘课系统](#problem-056-m0ss1-的翘课系统)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Background](#background)
  - [Assignment Description](#assignment-description)
    - [Grade Composition](#grade-composition)
  - [Assignment Requirements](#assignment-requirements)
    - [Input Format](#input-format)
    - [Output Format](#output-format)
    - [Samples](#samples)
    - [Data Constraints](#data-constraints)
  - [Per-Testcase Resource Limits](#per-testcase-resource-limits)
  - [Test Data](#test-data)
  - [Submission Requirements](#submission-requirements)
    - [OJ Git Repository Compilation Process](#oj-git-repository-compilation-process)
    - [Git Configuration Requirements](#git-configuration-requirements)
    - [Submission Guidelines](#submission-guidelines)
    - [Evaluation Notes](#evaluation-notes)
    - [Academic Integrity](#academic-integrity)

## Introduction

### Background

Implement course attendance management system with interval operations.

## Assignment Description

### Grade Composition

| Grading Component | Percentage |
| :--: | :--: |
| Pass **2673. m0ss1 的翘课系统** | 80% |
| Code Review | 20% |

Here are several points that need clarification:

- In the Code Review, we will **strictly examine your code style and repository organization structure, etc.**

- This assignment provides some sample data for testing, stored in the `/workspace/data/056/data_test/` directory. Note that these are not the test cases on the Online Judge. Passing all local test cases does not guarantee that you will pass the OJ tests.

- Besides the provided sample data, we also encourage you to design your own test data based on your program logic to assist debugging.

## Assignment Requirements

### Problem Description

翘课大师 m0ss1 喜欢大胆翘掉一些水课来摸鱼，因此他制定了详细的上课翘课计划。然而，m0ss1 近日饱受强制上课以及活平时分的干扰，有时候他需要删除自己的一些翘课计划，从而得到更高的分数。  

为了更好的安排自己的时间，请你帮助 m0ss1 建立翘课管理系统，这个系统应当执行以下两种操作：   

- 操作 A ; l ; r ：在 l 到 r 时间里有一个必上的水课，翘课系统需要删除所有与之冲突的活动，翘课系统应当返回被删除的活动的个数    

- 操作 B ：翘课系统需要返回当前可以进行的活动总数

### Input Format

第一行输入一个正整数 $n$，表示翘课系统的操作次数  

接下去 $n$ 行，每行一个操作,格式见题目描述

### Output Format

输出共 $n$ 行，对于每一次的操作的返回值换行并输出

### Samples

#### Sample 1

**Input:**
```
6
A 10 15
A 17 19
A 12 17
A 90 99
A 11 12
B
```

**Output:**
```
0
0
2
0
1
2
```

### Data Constraints

$1 \leq n \leq 2 \times 10^{5}$ ,  $1\leq l\leq r\leq 10^{5}$

## Per-Testcase Resource Limits

- **Time Limit (per test case)**: 1000 ms
- **Memory Limit (per test case)**: 125 MiB
- **Disk Usage**: No disk usage is permitted.

## Test Data

The test data for this problem is located at `/workspace/data/056/data_test/`.

## Submission Requirements

### OJ Git Repository Compilation Process

For Git compilation, we will first clone the repository using a command similar to:
```bash
git clone <repo_url> . --depth 1 --recurse-submodules --shallow-submodules --no-local
```

Then we check if there is a `CMakeLists.txt` file. If it exists, we run (if not, a warning message will be displayed):
```bash
cmake .
```

Finally, we check if there is any of `GNUmakefile`/`makefile`/`Makefile` (if cmake was run previously, this will be the generated Makefile). If it exists, we run (if not, a warning message will be displayed):
```bash
make
```

After this process is complete, we will use the `code` file in the project root directory as the compilation result.

A `CMakeLists.txt` file is provided in the project. You can use or modify it as needed. The local environment has gcc-13 and g++-13 available.

### Git Configuration Requirements

**IMPORTANT**: You must create a `.gitignore` file in your project root directory to avoid OJ evaluation conflicts.

The `.gitignore` file should include at least the following entries:

```gitignore
CMakeFiles/
CMakeCache.txt
```

### Submission Guidelines

- The submitted code must be able to compile successfully through the above compilation process
- The compiled executable file name must be `code`
- The program needs to be able to read data from standard input and write results to standard output
- Please ensure the code runs correctly within the given time and space limits
- **You must use C++ or C language** to implement this assignment

### Evaluation Notes

- The evaluation system will test your program using the provided test data
- The program output must exactly match the expected output (including format)
- Exceeding time or memory limits will be judged as the corresponding error type
- Please pay attention to the overall time performance of your code and the time complexity of each part of your algorithm.

### Academic Integrity

If any violations are found during evaluation or code review (including but not limited to using unconventional methods to pass test cases), your final score may be significantly reduced or become **0 points**.
