# Subject: TS0101 Compute the square root
## Description:
The Babylonian algorithm to compute the square root of a positive number n is as follows:
1. Make a guess at the answer (you can pick n/2 as your initial guess).
2. Compute r = n / guess .
3. Set guess= (guess + r) / 2.
4. Go back to step 2 for as many iterations as necessary. The more steps 2 and 3 are repeated, the closer guess will become to the square root of n.

Write a program that inputs a double for n, iterates through the Babylonian algorithm until the guess subtract the previous guess smaller than 0.01, and outputs the answer as a double to two decimal places. Your answer should be accurate even for large values of n.

## Input:
391.00

## Output:
19.77

| Sample Input | Sample Output |
| ------------ | ------------- |
| 400.5        | 20.01         |
|65189451651.5192165|255322.25 |
|1894651654984.11318|1376463.46|
|...| |


- [x]  Eazy,Only basic programming syntax and structure are required.
- [ ]  Medium,Multiple programming grammars and structures are required.
- [ ] Hard,Need to use multiple program structures or complex data types.
