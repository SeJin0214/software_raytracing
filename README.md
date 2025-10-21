
# software_raytracing
> C로 구현한 소프트웨어 레이 트레이서  
> 광원/카메라/ → 레이 생성 → 교차 판정 → 조명/그림자  

  
## 주요 구현 기능  
- [DETAIL_1_ENVIRONMENT_AND_PARSER](docs/DETAIL_1_ENVIRONMENT_AND_PARSER.md)  
    - `.rt` 씬 파일 파서 (ambient, camera, light, objects)  
- [DETAIL_2_CAMERA](docs/DETAIL_2_CAMERA.md)  
    - 카메라     
- [DETAIL_3_INTERSECTER_AND_SCALABILITY](docs/DETAIL_3_INTERSECTER_AND_SCALABILITY.md)  
    - 교차 판별, Sphere / Plane / Cylinder / Cone
- [DETAIL_4_LIGHT_AND_SHADOW](docs/DETAIL_4_LIGHT_AND_SHADOW.md)   
    - 퐁 조명 모델(ambient + diffuse + specular) , 그림자  
- [DETAIL_5_GI](docs/DETAIL_5_GI.md)  
    - 전역 조명
- [DETAIL_6_ACTION](docs/DETAIL_6_ACTION.md)
    - 로컬 좌표계를 이용한 오브젝트 회전 및 이동  
- [DETAIL_7_OPTIMIZATION](docs/DETAIL_7_OPTIMIZATION.md)  
    - 최적화(타일 렌더링(4x4, 16분할 멀티쓰레딩 렌더링), 컴파일러 플래그, 인라인)  
- [DETAIL_8_TEXTURE](docs/DETAIL_8_TEXTURE.md)
    - 텍스처



## 실행  
  make bonus  
  ./miniRT scene.rt  



https://github.com/user-attachments/assets/ec823d54-804c-46b0-99a2-9c509b6be8e8




## 조작키
  <img width="3373" height="1127" alt="RT_Controls" src="https://github.com/user-attachments/assets/4aeab5d4-0435-497e-bb05-cb7d25032e91" />


## 실행 환경 세팅 (추후에 Docker 사용)  
<X11/Xlib.h> 없는 경우   
sudo apt update  
sudo apt install build-essential libx11-dev pkg-config  

<X11/extensions/XShm.h> 없는 경우  
sudo apt update  
sudo apt install libxext-dev libx11-dev pkg-config  

libbsd 없는 경우  
sudo apt update  
sudo apt install libbsd-dev  

#### 누수 확인  
valgrind --leak=check=full ./miniRT scene.rt (매우 느림)  

valgrind 없는 경우  
sudo apt install valgrind  



  
  
