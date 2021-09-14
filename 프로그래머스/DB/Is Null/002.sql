-- 이름이 있는 동물의 아이디

-- 코드를 입력하세요
SELECT animal_id
from animal_ins
where name is not null
order by animal_id