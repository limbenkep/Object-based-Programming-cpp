# Laboration 4

## Environment & Tools
Operating system: windows,
IDE: CLion 2019.3.3
compiler: Microsoft C++ (MSVC) compiler
CMake version: 3.15.6
Git version: 2.25.0.windows.1
microsoft office 365 excel

## Purpose
The first purpose of this lab is to learn about the different sorting methods and how they vary in complexity. The second purpose is to compare the complexity of four sorting algorithms; quick sort, selection sort, insertion sort and Bubble sort sorting methods
 and show how well they practical results fit with the theoretical conclusions of the Big 'O'notation by writing a program that sorts arrays of different sizes with the four different sorting methods and plotting the sorting time alongside the theotical values gotten from the big 'O' notation to see how well they fit.

## Procedures
A program was designed according to instructions of Lab 4. Sorting algorithm codes was gotten from lecture example sample of 
sorting with modifiaations to suit the lab. Results from sorting was stored in a text file with file name result.txt and exported to excel for 
statistical analysis and graphs were plot from the data to compare the different sorting methods and their theoretical big *o
 data.
 
 ## Discussion
 I used the lecture notes and the links provided in the forum to learn about sorting and the big 'O' notation and applied the knowledge in carrying out the comparision of the sorting methods.
 I achieved the second goal of the lab by writing a working program that sorts the arrays as specified in the instructions and collected the data composed of algorithm name, array size and average sort time for all four sort methoad 
 of sort time for the different sorting methods and sizes, computed the theoretical data from the big 'O' notations and plotted the results.
 The results of the investigation showed that the test plot and the theoretical plots for the different sorting method match well for sizes up to 25000 showing a trend of increase in sorting time with increasing time. After size 25,000 the practical sorting time turns to increase at a lower rate than the theoretical values.
 A comparison of all four sorting methods shows that bubble sort has a much higher increase in sorting time with increasing size compare to insertion and selection sort even though they all have the same Big 'O' notation.
 Quick sort show that least sorting time as suggest by the big  'O' notations.
 From this investigation, I conclude that the theoretical and practical data matches well but gradually deviates as sort sizes exceed 25000