the const CPU_SEC in testHash.cpp should be tuned for your machine to get 1 second
delay, I had to do it since i programmed everything on a windows machine.

different cases are commented out in testHash.cpp, you can uncomment ONLY 1 CASE
make and run to get 100 averages of 1000 keys for that cases to std out, 

the RESULTS values I got are in csv files output_* linears is case1 for linear 
probing, quadratics is case1 for quadratic probing, linear_nf is case 2 for 
linear probing and quadratic_nf is case 2 for quadratic probing