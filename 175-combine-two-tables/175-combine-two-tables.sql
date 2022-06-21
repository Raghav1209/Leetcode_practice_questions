# Write your MySQL query statement below

select p.firstName,p.lastName,A.city,A.state from Person as p LEFT JOIN Address as a ON p.personId = a.personId;