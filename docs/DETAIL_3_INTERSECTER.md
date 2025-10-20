

## 교차

카메라에서 쏘는 Ray와 교차하는 Object만이 화면에 Rendering 되는 것입니다.  

발사된 Ray에 어떤 구와 교차하는 지 판별해야 합니다.

<details>
  <summary>call stack 및 설명</summary>  
  https://github.com/SeJin0214/software_raytracing/blob/1edeffc7ce8ad6c8f460188826a69a7d20f27729/bonus/render_bonus.c#L27  
  https://github.com/SeJin0214/software_raytracing/blob/1edeffc7ce8ad6c8f460188826a69a7d20f27729/bonus/render_bonus.h#L52  
  https://github.com/SeJin0214/software_raytracing/blob/1edeffc7ce8ad6c8f460188826a69a7d20f27729/bonus/render_bonus.h#L34  
  <br>  
  모든 구 오브젝트를 직선의 벡터 방정식과 구의 방정식을 이용하여 판별합니다.  
  해가 2개라면 교차되는 것이고, 해가 양수여야 앞에 있어야 합니다. 또한 기존의 값보다 작아야 카메라에 제일 가까운 것으로 판별됩니다.  
  https://github.com/SeJin0214/software_raytracing/blob/1edeffc7ce8ad6c8f460188826a69a7d20f27729/bonus/sphere_bonus.c#L51-L76  

  > 평면, 원기둥, 원뿔 모두 각자의 방정식을 이용해 판별합니다.
  
  
</details>





