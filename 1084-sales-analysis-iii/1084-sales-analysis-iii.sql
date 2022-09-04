 # Write your MySQL query statement below

select p.product_id,p.product_name from Product p INNER JOIN Sales s on p.Product_id=s.Product_id group by s.product_id having min(s.sale_date)>='2019-01-01' and max(s.sale_date)<='2019-03-31';
