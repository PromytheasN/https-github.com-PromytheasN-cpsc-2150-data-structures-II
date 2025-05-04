# Assignment 2 – Hashing and Skip Lists

## Part 1 – Hashing with Linear Probing  
Implements a hash table using linear probing for collision resolution, with automatic rehashing once the load factor threshold is exceeded. Includes a console test and a pair-finding utility using a hash table.

**Files:**
- `HashingLinearProbingDemo.h` – linear probing hash table implementation  
- `HashingLinearProbingDemoTester.cpp` – test and rehashing demo  
- `FindSum.h` – finds pair of numbers that sum to a target  
- `FindSumTester.cpp` – test cases for pair finding  

---

## Part 2 – Hashing with Skip Lists (Separate Chaining)  
Implements a hash table using skip lists for separate chaining. Demonstrates insertion, deletion, search, and rehashing with a max level system.

**Files:**
- `SkipList.h` – skip list implementation  
- `Node.h` – skip list node structure  
- `HashingSkipListTester.cpp` – test of hash table with skip list chaining  

---

## How to Compile and Run

### Linear Probing
```bash
g++ HashingLinearProbingDemoTester.cpp -o linear_hash
./linear_hash
