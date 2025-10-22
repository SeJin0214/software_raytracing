
## 텍스처

텍스처를 입히고 bump map을 입혀야 합니다.  

<details>
  <summary>
    call stack and description
  </summary>

매핑된 키에 따라 texture 타입을 변경합니다.  
https://github.com/SeJin0214/software_raytracing/blob/d241ea963ac7fb185d98b1f6f365e270ceed0816/bonus/solid_shape_bonus.c#L75-L85

https://github.com/SeJin0214/software_raytracing/blob/7438b74905f9bfbb46bd6ae0f7109aed1b41ab39/bonus/render_bonus.c#L27
https://github.com/SeJin0214/software_raytracing/blob/7438b74905f9bfbb46bd6ae0f7109aed1b41ab39/bonus/render_bonus.h#L52
https://github.com/SeJin0214/software_raytracing/blob/7438b74905f9bfbb46bd6ae0f7109aed1b41ab39/bonus/render_bonus.h#L34
https://github.com/SeJin0214/software_raytracing/blob/7438b74905f9bfbb46bd6ae0f7109aed1b41ab39/bonus/solid_shape_getter_bonus.h#L59-L78
https://github.com/SeJin0214/software_raytracing/blob/7438b74905f9bfbb46bd6ae0f7109aed1b41ab39/bonus/render_bonus.h#L46
  <br>
sphere의 경우  
https://github.com/SeJin0214/software_raytracing/blob/a8509ea4d3c6e71d1d3177496a27a5171c9cdc29/bonus/sphere_bonus.c#L51
https://github.com/SeJin0214/software_raytracing/blob/a8509ea4d3c6e71d1d3177496a27a5171c9cdc29/bonus/sphere_bonus.h#L50-L51
https://github.com/SeJin0214/software_raytracing/blob/a8509ea4d3c6e71d1d3177496a27a5171c9cdc29/bonus/solid_shape_getter_bonus.h#L59-L60
https://github.com/SeJin0214/software_raytracing/blob/a8509ea4d3c6e71d1d3177496a27a5171c9cdc29/bonus/solid_shape_getter_bonus.h#L48-L49
https://github.com/SeJin0214/software_raytracing/blob/a8509ea4d3c6e71d1d3177496a27a5171c9cdc29/bonus/solid_shape_getter_bonus.h#L52

uv 좌표를 구하는 공식은 가져다 사용했습니다.  
https://github.com/SeJin0214/software_raytracing/blob/7438b74905f9bfbb46bd6ae0f7109aed1b41ab39/bonus/sphere_bonus.h#L33-L47
  
</details>




