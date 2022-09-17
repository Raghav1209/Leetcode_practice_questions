# Write your MySQL query statement below

select d.name as Department,e.name as Employee,e.salary as Salary from Employee e INNER JOIN 
Department d ON e.departmentId=d.id where (e.departmentId,e.salary) IN 
(select DepartmentId,max(salary) from employee group by departmentId)