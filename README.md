# File Handling Project in C

This is a program written completely in C which can perform resume parsing on a basic level, and generate a candidate score on the basis of the number of skills matched and the years of experience the candidate has relative to the number of years you would prefer (giving 80% weight-age to skills matched and 20% to years or experience). **The resume file must be plain text (.txt) and skills should NOT be comma separated**

This project heavily uses concepts of linear data structures like Linked List and Arrays for dynamic memory allocation and parsing.

Scores of the candidates are stored in a csv file called "record.csv". For the sake of simplicity and the constraint that this project had to be primarily in C, this csv file will act as a basic DataBase. 

The python file "data.py" creates a DataFrame out of the csv file and plots a the leader board of all the candidates recorded so far. Python is only being used for Data visualization.  

## Installation

Simply download zip and extract, or clone this git repo. Make sure you have matplotlib and pandas in python to run this.

## Usage

Just enter the following commands in your terminal window that you have opened in the directory containing these files
```bash
$ gcc main.c
$ ./a.out
```
Next, make sure to enter the candidate's name **with no space between first and last name**
```bash
Enter Name of Candidate: AtharvaMutsaddi
```
Now you can enter the file name (with .txt extension). I have provided a sample resume file under the name of **file.txt**
```bash
Enter Name of File: file.txt

Enter min years of experience you want: 4
```
The program will now alphabetically store all of the skills that you require in your candidate, and also try to find the number of years of experience in the resume file by searching for the word "years". **Please ensure while entering skill, do not put any spaces between the words**


## Aim of this Project
This was a simple project using only the C language and basic knowledge of Linear Data Structures. The objective was to show creative and innovative use of file handling and certain linear data structures.

