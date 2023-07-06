# Dante

## Table of Contents

1. [General Info](#general-info)
2. [Technologies](#technologies)
3. [Installation](#installation)
4. [Overview](#overview)

### General Info

***
The main objective of this project is to create a maze generator and a maze solver

The maze generator use the [hunt and kill algorithm](https://weblog.jamisbuck.org/2011/1/24/maze-generation-hunt-and-kill-algorithm)

The maze solver use the [A * algorithm](https://www.geeksforgeeks.org/a-search-algorithm/)
***

## Technologies

A list of technologies used within the project:

* [C](https://en.wikipedia.org/wiki/C_(programming_language))

## Installation

***
A little intro about the installation.

```c
git clone git@github.com:Tom-Mendy/Dante.git
cd Dante
make
```

### Docker

check : [hub.docker.com/r/tommendy/dante](https://hub.docker.com/r/tommendy/dante)

## Overview

***

```c
$> ./generator/generator -h
try : ./generator x y [perfect]
```

```c
$> ./solver/solver FILE
```

You can generate & solve a map like that:

```c
./generator/generator 100 100 > map_generated
./solver/solver map_generated > map_solved
```
