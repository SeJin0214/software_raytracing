

## 조명

Phong light model의 diffuse, ambient, specular를 구현 해야 합니다.  
color를 0 ~ 1이 아닌 0 ~ 255의 범위로 잡았습니다.  

카메라로 쏜 Ray가 교차되는 Object가 있다면, Object의 색상을 구했을 것입니다.  
색상을 이용해 아래의 코드처럼 각 조명을 계산하고 더해야 합니다.

diffuse + ambient + specular = pixel color
https://github.com/SeJin0214/software_raytracing/blob/aab4f628e9528c4f39fa238485b7db2cc978e1d4/bonus/render_bonus.c#L84-L100
<details><summary>diffuse and ambient</summary>
  ambient는 주변광이라 하며, 공간 전체에 은은하게 퍼져있는 빛을 말합니다. 
  그렇기에 밝기에 따라 
https://github.com/SeJin0214/software_raytracing/blob/d544078fce1685fb2c4598b6e944ffeddbe124da/bonus/light_bonus.h#L19-L31
https://github.com/SeJin0214/software_raytracing/blob/d544078fce1685fb2c4598b6e944ffeddbe124da/bonus/light_bonus.h#L33-L49
</details>
<details><summary>specular</summary>
https://github.com/SeJin0214/software_raytracing/blob/d544078fce1685fb2c4598b6e944ffeddbe124da/bonus/light_bonus.h#L69-L82
</details>  
  
  
## 그림자
https://github.com/SeJin0214/software_raytracing/blob/aab4f628e9528c4f39fa238485b7db2cc978e1d4/mandatory/shadow.h#L17-L45


### 참고 자료

[한정현 컴퓨터그래픽스](https://www.youtube.com/watch?v=_uIjVpAM9l8&list=PLYEC1V9tJOl03WLDoUEKbiYW_Xt4W6LTl&index=10)









