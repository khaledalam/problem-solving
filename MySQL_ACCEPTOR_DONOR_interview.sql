/*
Enter your query below.
Please append a semicolon ";" at the end of the query
*/

/*
select BG, (select sum(AMOUNT) from `ACCEPTOR`) - (select sum(AMOUNT) from `DONOR`) from `ACCEPTOR` group by `BG` ASC;
*/

/*
select BG, sum(AMOUNT) from DONOR group by BG ASC;
*/


select A.BG, ( sum(A.AMOUNT) - (select sum(B.AMOUNT) 
from `DONOR` B where B.BG = A.BG) ) as DIF
from `ACCEPTOR` A group by A.BG ASC
having DIF > 0;
