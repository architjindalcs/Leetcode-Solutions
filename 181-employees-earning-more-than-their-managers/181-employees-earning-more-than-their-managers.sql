# Write your MySQL query statement below
select e1.name as "Employee" from employee e1 where e1.salary > (select salary from employee e2 where e1.managerId=e2.id);