-- 코드를 입력하세요
SELECT i.name, i.datetime 
from animal_ins i
    left outer join animal_outs o using(animal_id)
where o.datetime is null
order by i.datetime
limit 3