# TP5 IDM

## How to Compile my program

```bash
$ ./compile.sh
```

Dont forget to give permissions to the script

```bash
$ chmod +x compile.sh
```

Dont forget to change `CLHEP_DIR` variable in `compile.sh` to your CLHEP directory



## How to Run my program

```bash
$ ./TP5_BALLEJOS <question_number> <file_input_for_question_5>
e.g. ./TP5_BALLEJOS 5 /path/to/file
e.g. ./TP5_BALLEJOS 3
```

## How to Run Question 5

```bash
$ chmod +x question5.sh
$ ./question5.sh
```

## Time to build the library CLHEP

### Sequential

```bash
$ time make
> make  33,94s user 5,81s system 99% cpu 39,768 total
```

### Parallel

```bash
$ time make -j
> make --jobs  104,34s user 12,59s system 1108% cpu 10,552 total
```