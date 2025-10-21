
## Action

아래의 표와 같은 Action을 할 수 있어야 합니다.  
|  | 오브젝트 | 카메라 | 조명 |  
|------|------|------|------|
| 이동   |    O   |    O   |   O  |  
| 회전   | O | O | X |  
| 스케일 | O | X | X |  
  

<details>
  <summary>
    키 매핑
  </summary>
  이미지와 같이 키보드를 매핑했습니다.
  <img width="840" height="528" alt="image" src="https://github.com/user-attachments/assets/8f56c910-2c95-4094-b40a-b295ba1074aa" />  
  mlx 라이브러리에 key 입력 시 실행할 이벤트를 등록해둡니다.  
  https://github.com/SeJin0214/software_raytracing/blob/f89a2f35d4aa5042f4379b0abed304923d055f59/bonus/main_bonus.c#L42
  <br>
  <br>
  단순하게 조건문으로 key input을 체크했습니다.  
https://github.com/SeJin0214/software_raytracing/blob/f89a2f35d4aa5042f4379b0abed304923d055f59/bonus/main_bonus.c#L49-L68
  <br>
  <br>
  다른 Action이나 오브젝트도 동일하게 해주었습니다.   https://github.com/SeJin0214/software_raytracing/blob/f89a2f35d4aa5042f4379b0abed304923d055f59/bonus/input_camera_bonus.c#L16-L36

  Enum과 define은 input_bonus.h 파일에서 볼 수 있습니다.  
  https://github.com/SeJin0214/software_raytracing/blob/f89a2f35d4aa5042f4379b0abed304923d055f59/bonus/input_bonus.h#L55
  
</details>




  

