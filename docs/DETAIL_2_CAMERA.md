
## 좌표계
DirectX로 학습 전이를 위해 왼손 좌표계를 사용했습니다.  
<img width="245" height="290" alt="image" src="https://github.com/user-attachments/assets/c904ef1b-84b3-41df-9294-750fd2f5ccf1" />



## Render  
카메라로 렌더링 하기 위해 그림과 같이 픽셀에 Ray를 매핑하여 발사했습니다.  
<img width="381" height="202" alt="image" src="https://github.com/user-attachments/assets/e5a52c8a-926e-4429-b14c-29c4bc9adb0b" />

발사된 Ray로 해당 Pixel의 Color 값을 가져오고, Image buffer에 값을 넣습니다.  
https://github.com/SeJin0214/software_raytracing/blob/404ea5975b53e841f67571cd5a40ba96f3e82728/bonus/render_bonus.c#L47-L50

<details><summary>mappied_ray</summary>
https://github.com/SeJin0214/software_raytracing/blob/404ea5975b53e841f67571cd5a40ba96f3e82728/bonus/render_bonus.c#L36-L46
https://github.com/SeJin0214/software_raytracing/blob/404ea5975b53e841f67571cd5a40ba96f3e82728/bonus/render_bonus.c#L56-L71
</details>










