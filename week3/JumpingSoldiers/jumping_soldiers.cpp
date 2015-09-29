/*
Jumping Soldiers:
Time limit: 1.0 second
Memory limit: 64 MB

The sergeant ordered that all the recruits stand in rows.
The recruits have formed K rows with N people in each,
but failed to stand according to their height.
The right way to stand in a row is as following:
the first soldier must be the highest,
the second must be the second highest and so on;
the last soldier in a row must be the shortest.
In order to teach the young people how to form rows,
the sergeant ordered that each of the recruits jump
as many times as there are recruits before him in
his row who are shorter than he.
Note that there are no two recruits of the same height.
The sergeant wants to find which of the rows will jump
the greatest total number of times in order to send
this row to work in the kitchen.
Help the sergeant to find this row.

Input:
The first line of the input contains two positive integers:
N and K (2 ≤ N ≤ 10000, 1 ≤ K ≤ 20).
The following K lines contain N integers each.
The recruits in each row are numbered according to their height
(1 — the highest, N — the shortest).
Each line shows the order in which the recruits stand in the corresponding row.
The first integer in a line is the number of the first recruit in a row and so on.
Therefore a recruit jumps as many times as there are numbers which are greater
than his number in the line before this number.

Output:
You should output the number of the row in which the
total amount of jumps is the greatest.
If there are several rows with the maximal total amount
of jumps you should output the minimal of their numbers.

Sample:
input:	output:
3 3     3
1 2 3
2 1 3
3 2 1
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.get();
    return 0;
}
