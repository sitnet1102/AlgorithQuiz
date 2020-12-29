-- 이름에 el 이 들어가는 동물 찾기

-- 코드를 입력하세요
SELECT animal_id, name
from animal_ins
where name like "%el%" and animal_type = "dog"
order by name