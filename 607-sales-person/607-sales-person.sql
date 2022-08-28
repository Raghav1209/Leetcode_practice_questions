# Write your MySQL query statement below

select s.name as name from Salesperson s where s.sales_id NOT IN
(select o.sales_id from orders o left join company c on o.com_id = c.com_id where c.name = "RED");