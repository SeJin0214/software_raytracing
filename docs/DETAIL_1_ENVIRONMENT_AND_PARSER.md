

## 환경  
1. 운영체제       : Ubuntu 22.04.3 LTS  
2. 언어 : C  
3. 빌드    : makefile
4. 라이브러리 : MiniLibX
6. 코딩 표준 : 42 norminette    
             함수 25줄 이하  
             한 라인 길이 80이하  

## 요구사항  
1. 허용 함수 및 라이브러리 목록  
  open, close, read, write, printf, malloc, free, perror, exit, math.h  
  
2. .rt 파일 형식에 맞춰서 파싱할 것(요소가 올바르지 않거나 .rt가 파일이 아니면 유효하지 않음)  
<img width="854" height="167" alt="image" src="https://github.com/user-attachments/assets/5385cea1-e4b8-41c1-8565-f8588d2f8ab3" />

3. 구, 평면, 원기둥, 원뿔 등의 오브젝트 구현 할 것  
4. 키 매핑에 따라 이동, 스케일, 회전 구현 할 것  
5. diffuse, ambient, specular, Multi right, shadow, texture, checkboard를 구현할 것  



## Parser
.rt 파일 형식에 맞춰 Object Init을 해야 한다.  
https://github.com/SeJin0214/software_raytracing/blob/e3334c43b6227cf48d3079cd3b6f320f2e70e4b9/bonus/main_bonus.c#L32




