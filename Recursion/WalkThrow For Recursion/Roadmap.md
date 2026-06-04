```
# Recursion & Backtracking Master Roadmap

> Goal: Build a strong foundation in recursion first, then transition naturally into backtracking, and finally solve advanced problems like N-Queens, Sudoku Solver, and Maze Problems.

---

# Phase 0: Recursion Mindset

Before solving any recursion problem, always ask:

## 1. What is my state?

Examples:

```cpp
index
```

```cpp
n
```

```cpp
row,col
```

The state tells recursion where it currently is.

---

## 2. What is my base case?

Example:

```cpp
if(index == n)
    return;
```

Without a base case recursion never stops.

---

## 3. What smaller problem am I giving to recursion?

Example:

```cpp
solve(index+1);
```

Trust that recursion solves the smaller problem.

This is called the **Faith Principle**.

---

## 4. What work am I doing before recursion?

Example:

```cpp
cout<<arr[index];
```

---

## 5. What work am I doing after recursion?

Example:

```cpp
cout<<"Backtracking";
```

This becomes important later.

---

# Level 1: Basic Recursion

Goal:

Learn:

* Base Cases
* Recursive Calls
* Faith Principle

---

## Questions

### 1. Print 1 to N

Example:

```cpp
1 2 3 4 5
```

Teaches:

* Recursion flow
* Base case

---

### 2. Print N to 1

Example:

```cpp
5 4 3 2 1
```

Teaches:

* Preorder recursion

---

### 3. Sum of N Numbers

Example:

```cpp
1+2+3+4+5
```

Teaches:

* Returning values

---

### 4. Factorial

Example:

```cpp
5! = 120
```

Teaches:

* Recursive multiplication

---

### 5. Power(x,n)

Example:

```cpp
2^5
```

Teaches:

* Recursive reduction

---

### 6. Fibonacci

Example:

```cpp
F(6)
```

Teaches:

* Multiple recursive calls

---

### 7. Count Digits

Example:

```cpp
12345
```

Output:

```cpp
5
```

Teaches:

* Recursive division

---

### 8. Sum of Digits

Example:

```cpp
123
```

Output:

```cpp
6
```

Teaches:

* Breaking numbers recursively

---

# Focus After Level 1

You should be comfortable answering:

```text
What is the state?
What is the base case?
What smaller problem am I giving recursion?
```

---

# Level 2: Recursion on Arrays & Strings

Goal:

Learn:

* Index Traversal
* Recursive Movement

---

## Questions

### 1. Reverse String

Example:

```cpp
ABC
```

Output:

```cpp
CBA
```

Teaches:

* Two-pointer recursion

---

### 2. Check Palindrome

Example:

```cpp
MADAM
```

Output:

```cpp
True
```

Teaches:

* Recursive comparisons

---

### 3. Find Maximum in Array

Example:

```cpp
[1,5,3,9]
```

Output:

```cpp
9
```

Teaches:

* Recursive aggregation

---

### 4. Find Minimum in Array

Teaches:

* Similar pattern

---

### 5. Linear Search

Teaches:

* Recursive scanning

---

### 6. Binary Search

Teaches:

* Divide & Conquer

---

# Focus After Level 2

Understand:

```cpp
index + 1
```

and

```cpp
start + end
```

movement.

You should now think:

```text
Current Position
→ Move
→ Base Case
```

---

# Level 3: Subsequence Generation (MOST IMPORTANT)

This level builds the foundation of backtracking.

---

## Question

Print all subsequences of:

```cpp
ABC
```

Output:

```cpp
ABC
AB
AC
BC
A
B
C
(empty)
```

---

# Core Idea

For every character:

```text
Take
Not Take
```

Decision Tree:

```text
             A
           /   \
       Take   Not Take
        /          \
       B            B
```

---

# What This Teaches

* Decision Making
* Binary Recursion Tree
* Choice Exploration

This single problem is the foundation for:

* Subsets
* Subsequence Sum
* Combination Sum
* Backtracking

Master this before moving ahead.

---

# Phase 2: Enter Backtracking

Now recursion becomes:

```text
Choose
Explore
Undo
```

Pattern:

```cpp
makeChoice();

solve();

undoChoice();
```

Example:

```cpp
ans.push_back(x);

solve();

ans.pop_back();
```

This is Backtracking.

---

# Level 4: Subset & Sum Problems

---

## Question 1

Print All Subsets

Input:

```cpp
[1,2,3]
```

Output:

```cpp
[]
[1]
[2]
[3]
[1,2]
[1,3]
[2,3]
[1,2,3]
```

Teaches:

```text
Take
Not Take
```

on arrays.

---

## Question 2

Subset Sum

Input:

```cpp
[1,2,3]
```

Output:

```cpp
0
1
2
3
3
4
5
6
```

Teaches:

* Same recursion tree
* Different result generation

---

## Question 3

Print Subsequences with Sum K

Input:

```cpp
[1,2,1]
k = 2
```

Output:

```cpp
[2]
[1,1]
```

Teaches:

* Path Filtering

---

## Question 4

Print First Subsequence with Sum K

Teaches:

```cpp
return true;
```

Early stopping.

---

## Question 5

Count Subsequences with Sum K

Teaches:

```cpp
left + right
```

Returning counts.

---

# Focus After Level 4

You should now understand:

```text
State
Choice
Base Case
```

and

```text
Choose
Explore
Undo
```

---

# Level 5: Permutations

Input:

```cpp
[1,2,3]
```

Output:

```cpp
123
132
213
231
312
321
```

---

# New Concept

Instead of:

```cpp
Take
Not Take
```

You now have:

```cpp
for(all choices)
```

Example:

```cpp
for(int i=0;i<n;i++)
```

---

# Teaches

* Multiple Choices
* Visited Array
* State Tracking

---

# Level 6: Combination Problems

---

## Combination Sum

Input:

```cpp
[2,3,6,7]
Target = 7
```

Output:

```cpp
[2,2,3]
[7]
```

Teaches:

* Reusing elements
* Target reduction

---

## Combination Sum II

Teaches:

* Duplicate handling

Example:

```cpp
if(i>start && arr[i]==arr[i-1])
    continue;
```

---

# Focus After Level 6

You should understand:

```text
State Management
Target Reduction
Choice Trees
```

---

# Level 7: Constraint Backtracking

Now choices must obey rules.

---

## Generate Parentheses

Input:

```cpp
n=3
```

Output:

```cpp
((()))
(()())
(())()
()(())
()()()
```

Teaches:

* Valid state checking

---

## Letter Combinations of Phone Number

Teaches:

* Multiple branching choices

---

# Level 8: Grid Backtracking

---

## Count Paths in Grid

Teaches:

```cpp
row,col
```

state.

---

## Print All Paths

Teaches:

* Path tracking

---

## Rat in Maze

Teaches:

* Visited matrix
* Backtracking on grids

Pattern:

```cpp
mark visited

explore

unmark visited
```

---

# Level 9: Board Backtracking

---

## Place N Rooks

Teaches:

* Row-wise placement

---

## Place N Bishops

Teaches:

* Diagonal checking

---

## N Queens

Pattern:

```cpp
Place Queen

Solve Next Row

Remove Queen
```

This is pure backtracking.

---

# Level 10: Advanced Backtracking

After N-Queens:

---

## Sudoku Solver

Teaches:

* Constraint Satisfaction

---

## Word Search

Teaches:

* DFS + Backtracking

---

## Crossword Solver

Teaches:

* Heavy State Management

---

# Universal Backtracking Template

Whenever solving a problem:

```cpp
void solve(state){

    if(base_case){
        answer found;
        return;
    }

    for(all choices){

        makeChoice();

        solve(next_state);

        undoChoice();
    }
}
```

---

# Daily Practice Plan

Week 1

```text
Print 1-N
Print N-1
Factorial
Power
Fibonacci
Sum Digits
Count Digits
```

---

Week 2

```text
Reverse String
Palindrome
Max Array
Min Array
Linear Search
Binary Search
```

---

Week 3

```text
Subsequences
Subsets
Subset Sum
Sum K
Count Sum K
```

---

Week 4

```text
Permutations
Combination Sum
Combination Sum II
Generate Parentheses
```

---

Week 5

```text
Maze Paths
Rat in Maze
N Rooks
N Bishops
N Queens
```

---

Week 6

```text
Sudoku Solver
Word Search
Advanced Backtracking
```

---

# Golden Rule

Never ask:

```text
What code should I write?
```

Always ask:

```text
What is my state?
What is my base case?
What choices do I have?
What changes before recursion?
What must be undone after recursion?
```

If you can answer those five questions, you can solve most recursion and backtracking problems.

```