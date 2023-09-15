# Write your MySQL query statement below
WITH cte AS (SELECT customer_number, count(order_number) as NumberOfOrders FROM Orders Group By customer_number)

SELECT customer_number FROM cte WHERE NumberOfOrders = (SELECT MAX(NumberOfOrders) FROM cte)