-- 코드를 입력하세요
SELECT o.animal_id, o.name
from animal_outs o
left outer join animal_ins i using(animal_id)
where i.animal_id is null
order by animal_id