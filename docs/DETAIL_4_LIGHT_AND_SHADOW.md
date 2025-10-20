

## 조명

Phong light model의 diffuse, ambient, specular를 구현 해야 합니다.  
color를 0 ~ 1이 아닌 0 ~ 255의 범위로 잡았습니다.  

카메라로 쏜 Ray가 교차되는 Object가 있다면, Object의 색상을 구했을 것입니다.  
각 조명을 계산하고 Object color와 더해줘야 합니다.  

object color + diffuse + ambient + specular = pixel color

https://github.com/SeJin0214/software_raytracing/blob/aab4f628e9528c4f39fa238485b7db2cc978e1d4/bonus/render_bonus.c#L84-L100


### 참고 자료

[한정현 컴퓨터그래픽스](https://www.youtube.com/watch?v=_uIjVpAM9l8&list=PLYEC1V9tJOl03WLDoUEKbiYW_Xt4W6LTl&index=10)

