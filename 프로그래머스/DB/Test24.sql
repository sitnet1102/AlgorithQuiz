-- 코드를 입력하세요
/*
select cart_id
from (
    SELECT cart_id, count(cart_id) count
    from cart_products
    where name = "Milk" or name = "Yogurt"
    group by cart_id
)
where count(cart_id) = 2 
group by cart_id 

    
*/

select cart_id
from cart_products
where name = "Milk" and cart_id in (
    select cart_id 
    from cart_products
    where name = "Yogurt"
)
group by cart_id