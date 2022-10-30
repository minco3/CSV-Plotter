# CSV Plotter
Plots and renders a graph using SFML

## Description
Uses the first row of data as data labels and the first row as timestamps.

The first row is parsed as a string and all other rows and columns besides the date column and titles row are parsed as floating point integers

## What I Learned

- Managing data efficiently is hard
- Challenged my understanding of views
- Learned about VertexArrays and started to understand how translations work
- Further understanding of abstraction of components in a desktop app

## Screenshots

![view of 2999 data points * 20 graphs](/images/csv_plotter.png)

![detailed view of 400 data points * 20 graphs](/images/csv_plotter_detail.png)

## Getting Started

### Dependencies
- CMake
- SFML

### Setup
- The /resources directory is copied to /build/bin so `FONT_PATH` and `CSV_PATH` should be set accordingly
#### simple setup with CMake and GCC

```
mkdir build
cd build
cmake .. -G "Unix Makefiles"
cmake --build . --target main
main
```