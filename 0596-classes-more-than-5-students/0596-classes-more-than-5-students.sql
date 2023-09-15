# Write your MySQL query statement below
WITH cte AS
(Select class, count(student) AS Num
from Courses 
Group by class)

SELECT class 
FROM cte
WHERE Num >=5
