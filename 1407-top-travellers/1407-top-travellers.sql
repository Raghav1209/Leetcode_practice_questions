# Write your MySQL query statement below

select u.name,ifnull(sum(r.distance),0)

as travelled_distance from Users u LEFT JOIN Rides r ON u.id=r.user_id group by r.user_id order by travelled_distance DESC,u.name