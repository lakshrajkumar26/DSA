# 📘 C++ `unordered_map` – Complete Quick Revision Guide

---

## 🔹 What is `unordered_map`?

* A **hash table** (key → value pair)
* Stores **unique keys**
* Fast operations:

  * Insert → O(1)
  * Search → O(1)
  * Delete → O(1)

---

## 🔹 Basic Syntax

```cpp
#include <unordered_map>
using namespace std;

unordered_map<int, int> m;   // key=int, value=int
unordered_map<char, int> freq; // char frequency
unordered_map<string, int> mp; // string keys
```

---

## 🔹 Insertion

```cpp
m[3] = 2;
m['a'] = 1;
```

### Meaning:

```
Key → Value

3 → 2
'a' → 1
```

👉 If key doesn’t exist → it is created
👉 If key exists → value is updated

---

## 🔹 Access Values

```cpp
cout << m[3];   // prints 2
cout << m['a']; // prints 1
```

---

## 🔹 Frequency Count (Most Important for DSA)

```cpp
for(int x : arr){
    freq[x]++;
}
```

### Example:

```
arr = [1,2,2,3]

freq:
1 → 1
2 → 2
3 → 1
```

---

## 🔹 Iterating Map (VERY IMPORTANT)

### 🔹 Method 1 (Range-based loop)

```cpp
for(auto it : freq){
    cout << it.first << " -> " << it.second << endl;
}
```

### 🔹 Method 2 (Iterator)

```cpp
for(auto it = freq.begin(); it != freq.end(); it++){
    cout << it->first << " -> " << it->second << endl;
}
```

---

## 🔹 Diagram (How map stores data)

```
+-------------------+
| Key | Value       |
+-------------------+
|  1  |  1          |
|  2  |  2          |
|  3  |  1          |
+-------------------+
```

---

## 🔹 Important Functions

### 1. `.find()`

```cpp
if(freq.find(2) != freq.end()){
    cout << "Found";
}
```

👉 Returns iterator
👉 If not found → returns `freq.end()`

---

### 2. `.end()`

```cpp
freq.find(x) == freq.end()
```

👉 Means **element NOT present**

### Visual Diagram

## Map:
[a → 1]   [b → 2]

## Memory:
[a]   [b]   [END]
               ↑
            M.end()

## Example 

```auto it1 = M.find('a'); // points to 'a'
auto it2 = M.find('c'); // points to END```
---

### 3. `.clear()`

```cpp
freq.clear();
```

### ⚠️ Rule
```if (it == M.end())

👉 NOT FOUND
```
👉 Removes all elements

---

### 4. `.size()`

```cpp
cout << freq.size();
```

👉 Number of unique keys

---

## 🔹 `.first` and `.second`

Used when iterating:

```cpp
for(auto it : freq){
    cout << it.first;   // key
    cout << it.second;  // value
}
```

---

## 🔹 Difference (IMPORTANT)

| Expression   | Meaning          |
| ------------ | ---------------- |
| `freq[x]`    | value of key x   |
| `it.first`   | key              |
| `it.second`  | value            |
| `it->first`  | key (iterator)   |
| `it->second` | value (iterator) |

---

## 🔹 Common DSA Patterns

### ✅ 1. Frequency Count

```cpp
for(int x : arr){
    freq[x]++;
}
```

---

### ✅ 2. Check Subset

```cpp
for(int x : b){
    if(freq[x] == 0) return false;
    freq[x]--;
}
```

---

### ✅ 3. Count Distinct Elements

```cpp
unordered_map<int,int> m;

for(int x : arr){
    m[x]++;
}

cout << m.size();
```

---

### ✅ 4. Check Duplicate

```cpp
for(int x : arr){
    if(freq[x] == 1){
        cout << "Duplicate found";
    }
    freq[x]++;
}
```

---

## 🔹 Common Mistakes ❌

### ❌ 1. Using wrong type

```cpp
unordered_map<char,int> m; // wrong for int array
```

---

### ❌ 2. Confusing index & value

```cpp
for(int i : arr){
    cout << arr[i]; ❌
}
```

👉 `i` is value, not index

---

### ❌ 3. Using only `.find()` for duplicates

```cpp
if(freq.find(x) == freq.end()) ❌
```

👉 Doesn’t handle frequency

---

## 🔹 unordered_map vs map

| Feature | unordered_map | map          |
| ------- | ------------- | ------------ |
| Order   | No            | Sorted       |
| Time    | O(1)          | O(log n)     |
| Use     | Fast ops      | Ordered data |

---

## 🔹 Pro Tips 🚀

* Use `unordered_map` for **speed**
* Use `map` when **sorted order needed**
* Always think:
  👉 “Do I need frequency or just existence?”

---

## 🔹 Final Summary

✔ Key → Value storage
✔ Fast lookup (O(1))
✔ Best for:

* Frequency count
* Duplicates
* Subset problems
* Hashing-based problems

---

💡 **Golden Rule:**

```
freq[x]++  → counting
freq[x]--  → using
freq[x]==0 → not available
```

---

🔥 Done — revise this once before interview, you’re set.
