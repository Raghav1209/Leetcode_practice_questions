# Write your MySQL query statement below

select ee.name as Employee from Employee ee JOIN Employee E ON ee.managerId=E.Id AND ee.salary>E.salary;
