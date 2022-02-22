# Write your MySQL query statement below
select department.name as "Department",employee.name as "Employee",salary as "Salary" from employee join department on (employee.departmentId=department.id) where (employee.departmentId,salary) in 
(select employee.departmentId,max(salary) from employee group by (employee.departmentId));