select hour(datetime) as "hour", count("hour") 
from animal_outs
where hour(datetime) > 8 and hour(datetime) < 20
group by hour(datetime)
order by hour