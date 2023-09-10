# Write your MySQL query statement below
select Email from Person group by email having count(DISTINCT id)>1