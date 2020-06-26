# emi
The module to be developed is a loan management system for any type loan.
The loan is to be considered as a high-level module. The objective of the program is to
provide the details of the loan once the loan is disbursed. It has to provide all the details
with the following components.
1. Principal amount
2. Loan creation date
3. No of EMI’s (should be an array)
4. Each EMI should have the following
a. Principal EMI amount
b. Interest EMI amount
c. Total EMI amount
d. EMI date (can consider a period 30 days for every EMI since the creation
date)
e. Principal amount remaining from the main loan account.
5. Total Payable amount
The input should be a command line executable, no graphical UI needed. The input can be
provided as command line parameters or a JSON file based on your convenience.
The inputs which needs to be passed is the loan amount and loan tenure(No of EMI’s). The
program should perform all computations and give an output of all the components
provided above.
Note : The interest for the loan can be a static value of 12% for one year. A difference of
+/- 10 Rs is exempted from calculation.
