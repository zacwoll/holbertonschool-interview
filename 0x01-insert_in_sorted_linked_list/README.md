# Insert in sorted linked list
## Write a function in C that inserts a number into a sorted singly linked list.

### Test Case 0: insert in sorted singly linked list
```
$ gcc .\0-main.c .\0-insert_number.c .\linked_lists.c
$ .\a.exe
n = 27
0
1
2
3
4
98
402
1024
-----------------
0
1
2
3
4
27
98
402
1024
```

### Test Case 1: value less than initial value in list
```
$ gcc .\1-main.c .\0-insert_number.c .\linked_lists.c
$ .\a.exe
n = -1
0
1
2
3
4
98
402
1024
-----------------
-1
0
1
2
3
4
98
402
1024
```

### Test Case 2: duplicate value in list
```
$ gcc .\2-main.c .\0-insert_number.c .\linked_lists.c
$ .\a.exe
n = 1
0
1
2
3
4
98
402
1024
-----------------
0
1
1
2
3
4
98
402
1024
```

### Test Case 3: No existing value in list
```
$ gcc .\3-main.c .\0-insert_number.c .\linked_lists.c
$ .\a.exe
n = 27
-----------------
27
```

### Test Case 4: Single element in list
```
$ gcc .\4-main.c .\0-insert_number.c .\linked_lists.c
$ .\a.exe
n = 27
0
-----------------
0
27
```

### Test Case 5: value greater than max value in list
```
$ gcc .\5-main.c .\0-insert_number.c .\linked_lists.c
$ .\a.exe
n = 1025
0
1
2
3
4
98
402
1024
-----------------
0
1
2
3
4
98
402
1024
1025
```

Test Case # => #-main.c