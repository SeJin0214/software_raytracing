

## 최적화

specular와 GI도 구현하기 전, 1회 렌더링 성능입니다.    

<img width="128" height="64" alt="diffuse" src="https://github.com/user-attachments/assets/ca96f31e-3c57-47e9-b389-06b19c72eaf4" />

렌더링 시간에 0.7초씩이나 소모되어 키 입력마다 뚝뚝 끊겨서 움직였습니다.  
최적화 할 수 있는 방법이 무엇이 있을까 고민하다가, 최적화 플래그 라는 것이 있다는 게 생각났습니다.  

<details>
  <summary>
    최적화 플래그 적용 전, 후
  </summary>
<img width="128" height="64" alt="image (1)" src="https://github.com/user-attachments/assets/2fabfaac-58e6-4170-8fd2-41ef65035355" />

  아쉬운 점 : disassembly를 보았을 때, 컴파일러 최적화 플래그로 SIMD 연산을 유도해봤으나 그러지 못한 연산들이 있었습니다.  
</details>




