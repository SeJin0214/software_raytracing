
# software_raytracing
> C로 구현한 소프트웨어 레이 트레이서  
> 광원/카메라/ → 레이 생성 → 교차 판정 → 조명/그림자  

  
## 주요 구현 기능  
- [O] `.rt` 씬 파일 파서 (ambient, camera, light, objects)  
- [O] 조명, 카메라, 오브젝트 회전 및 이동  
- [O] 퐁 조명 모델(ambient + diffuse : 기본 요구사항 + specular (보너스 요구사항)) , 그림자  
- [O] 프리미티브: Sphere / Plane / Cylinder (기본 요구사항), Cone (보너스 요구사항)  
- [O] 텍스처/노멀맵 (보너스, `texture/` 활용)  
- [O] 로컬 좌표계 (요구사항 x)  
- [O] 전역 조명 (요구사항 x)  
- [O] 타일 렌더링(16분할 멀티쓰레딩, 요구사항 x)  




## 환경  
OS       : Ubuntu 22.04.3 LTS  
Language : C  
Build    : makefile  

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



  
  
