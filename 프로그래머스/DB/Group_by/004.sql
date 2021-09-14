-- 입양 시각 구하기(2)
with recursive time as
(select 0 as hour 
    union all 
    select hour+1 from time where hour < 23)
select hour, count(animal_id) count
from time
    left outer join animal_outs on (hour = date_format(datetime, "%H"))
group by hour
-- order by hour