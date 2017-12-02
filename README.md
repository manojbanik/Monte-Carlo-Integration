# Monte-Carlo-Integration
Monte Carlo Integration (MCI). To evaluate an integral of the form  (where f(x) is a “nice” function), we can use Monte Carlo Simulation as follows. Note that:  .
Using antithetic variates is very similar to the above (Q. 2b) process. Here other than generating 1000 random numbers, I generated 500 and getting another 500 from these random numbers using the formula (3-Ui) [here Ui is a random number between 0 & 3].

So, the steps are...

1. Generated a random number U ~ (0, 3).
2. Got the value of Integral at U, which I say X1.
3. The, I got the value of Integral at (3-U), which I say X2.
4. Now getting the average of those two I got, X1 = (X1 + X2)/2
5. Similarly I found X2, X3, ...., X500 and find the confidence interval at 95% level as well.
