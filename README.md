# 🚗 4WD 스키드 스티어 차량 자율 기능 개발

이 리포지토리는 **Raspberry Pi 4 (ROS 2)**와 **Infineon AURIX TC375 (FreeRTOS)** 기반 4WD 스키드 스티어 차량의 자율 기능 개발을 위한 소스 코드와 문서를 관리합니다.

---

## 🎯 프로젝트 목표 (v6.2 기준)

1. **반응형 자율주차**  
   - 주행 중 측면 초음파 센서로 공간 감지  
   - 공간 발견 시 사전 정의된 후방 주차 기동 수행
2. **원격 제어**  
   - 조이스틱을 이용한 완전 수동 제어
3. **경로 복귀**  
   - 원격 제어 경로 기록  
   - 명령 시 자동 복귀

---

## 🛠️ 시스템 아키텍처

### 전체 구조

- **고수준 제어기 (MPU):**  
  - Raspberry Pi 4 Model B (8GB)  
  - **OS/Platform:** ROS 2 Humble (Docker)
  - **주요 역할:**  
    - 상태 관리 (Stateflow 기반)  
    - 의사 결정(주차, 경로 복귀)  
    - 경로 기록 및 추종  
    - 외부 통신(모바일 앱)
- **저수준 제어기 (MCU):**  
  - Infineon AURIX TC375  
  - **OS/Platform:** FreeRTOS
  - **주요 역할:**  
    - 실시간 모터 제어 (스키드 스티어 PID)  
    - 엔코더 펄스 카운팅/속도 계산  
    - ToF/초음파 센서 데이터 취득 및 전처리  
    - 긴급 제동 로직
- **통신:**  
  - **프로토콜:** CAN 버스  
  - **역할:** RPi와 TC375 간 제어 명령, 차량 상태, 센서 데이터 교환

> ![System Architecture Diagram](docs/images/system_architecture.png)  
> *(이미지는 docs/images에 추가 필요)*

---

## 🏗️ 개발 환경 설정

### Raspberry Pi (ROS 2)

- **Docker**로 ROS 2 개발 환경 관리
- **설치 및 빌드**
  1. Docker 설치: [공식 문서](https://docs.docker.com/engine/install/)
  2. ROS 2 Humble 컨테이너 실행 (명령어 추후 추가)
  3. 워크스페이스 빌드
     ```bash
     cd rpi_ws
     colcon build --symlink-install
     ```

### TC375 (FreeRTOS)

- **IDE:** AURIX™ Development Studio
- **컴파일러:** Tasking TriCore C/C++ Compiler
- **빌드 시스템:** CMake (예정)
- **핵심 라이브러리:**  
  - Infineon iLLD (Low-level drivers)  
  - FreeRTOS Kernel

---

## 📝 개발 로드맵

1. **기본 플랫폼 구축**
   - 하드웨어 조립 및 CAN 통신 구축
   - 완전 수동 원격 제어 기능 구현
2. **핵심 기능 개발**
   - 초음파 센서 기반 주차 공간 탐지
   - 후방 주차 기동 로직 구현
3. **추가 기능 개발**
   - 오도메트리 기반 경로 기록 및 추종

---

## 📁 리포지토리 구조

```
/
├── .github/           # GitHub Actions (CI/CD)
├── docs/              # 프로젝트 문서 (아키텍처, CAN 프로토콜 등)
├── rpi_ws/            # Raspberry Pi ROS 2 Workspace
├── tc375_fw/          # TC375 Firmware (FreeRTOS)
├── simulink_models/   # MATLAB/Simulink 모델
└── README.md
```

---

필요에 따라 각 섹션에 세부 설명이나 예시를 추가하면 더욱 완성도 높은 문서가 됩니다.  
원하는 스타일이나 추가 정보가 있다면 말씀해 주세요!