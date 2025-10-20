

## 조명 및 그림자

Phong light model의 diffuse, ambient, specular를 구현 해야 합니다.  
color를 0 ~ 1이 아닌 0 ~ 255의 범위로 잡았습니다.  

카메라로 쏜 Ray가 교차되는 Object가 있다면, Object의 색상을 구했을 것입니다.  
아래의 코드처럼 각 조명을 계산하고 Object color와 더해줘야 합니다.  

object color + diffuse + ambient + specular = pixel color
https://github.com/SeJin0214/software_raytracing/blob/aab4f628e9528c4f39fa238485b7db2cc978e1d4/bonus/render_bonus.c#L84-L100
<details><summary>diffuse and ambient</summary>
https://github.com/SeJin0214/software_raytracing/blob/d544078fce1685fb2c4598b6e944ffeddbe124da/bonus/light_bonus.h#L19-L31
https://github.com/SeJin0214/software_raytracing/blob/d544078fce1685fb2c4598b6e944ffeddbe124da/bonus/light_bonus.h#L33-L49
</details>
<details><summary>specular</summary>
https://github.com/SeJin0214/software_raytracing/blob/d544078fce1685fb2c4598b6e944ffeddbe124da/bonus/light_bonus.h#L69-L82
</details>
  
https://github.com/SeJin0214/software_raytracing/blob/aab4f628e9528c4f39fa238485b7db2cc978e1d4/mandatory/shadow.h#L17-L45


### 참고 자료

[한정현 컴퓨터그래픽스](https://www.youtube.com/watch?v=_uIjVpAM9l8&list=PLYEC1V9tJOl03WLDoUEKbiYW_Xt4W6LTl&index=10)






