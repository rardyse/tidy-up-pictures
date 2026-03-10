# Tidy Up Your Pictures

the goal is to:

1. find all `.jpg` and `.png` images in a given folder
2. copy them into a single folder
3. sort them by date into folders structured as:

```
year/month/day-hour:minute.ext
```

example:

```
sorted_pictures/
└── 2022/
    └── 02/
        ├── 22-10:00.jpg
        └── 22-18:31.png
```

two implementations are provided:

* `pictures.sh` (Bash script)
* `pictures.c` (C program)

---

# Requirements

Linux / Unix environment (tested on Ubuntu).
an IDE (personally, I used VSCode)

---

# Bash version

make the script executable:

```
chmod +x pictures.sh
```

run it:

```
./pictures.sh folder_with_images
```

---

# C version

compile:

```
gcc pictures.c -o pictures
```

run it:

```
./pictures folder_with_images
```

---

# Output folders

the programs create two folders:

```
all_pictures/
```

--> temporary folder containing copied images

```
sorted_pictures/
```

--> final structure sorted by year and month.

do **not use real pictures without a backup**, use test images instead ;)


