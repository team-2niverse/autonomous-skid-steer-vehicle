# 🚗 4WD 스키드 스티어 차량 자율 기능 개발

이 리포지토리는 **Raspberry Pi 4 (ROS 2)**와 **Infineon AURIX TC375 (FreeRTOS)** 기반 4WD 스키드 스티어 차량의 자율 기능 개발을 위한 소스 코드와 문서를 관리합니다.

---

## 🎯 프로젝트 목표 (v7.2 기준)

1. **원격 제어**  
   - 조이스틱을 이용한 완전 수동 제어
2. **긴급 제동**
   - ToF 센서를 이용한 거리 기반 긴급 제동
3. **자율 주차**
   - 측후방 초음파 센서를 이용한 자율 주차
4. **스트리밍**
   - 스마트폰 어플과 카메라, 데이터 로깅에 기반한 스트리밍

---

## 🛠️ 시스템 아키텍처

### 전체 구조

- **고수준 제어기 (MPU):**  
  - Raspberry Pi 4 Model B (8GB)  
  - **OS/Platform:** ROS 2 Humble (Docker)
  - **주요 역할:**  
    - 상태 관리 (Stateflow 기반)
    - PWM 변환
    - 외부 통신(모바일 앱)
- **저수준 제어기 (MCU):**  
  - Infineon AURIX TC375  
  - **OS/Platform:** FreeRTOS
  - **주요 역할:**  
    - 실시간 모터 제어 (스키드 스티어 PID)  
    - 엔코더 펄스 카운팅/속도 계산  
    - ToF/초음파 센서 데이터 취득 및 전처리  
    - 긴급 제동 로직
    - 자율 후방 주차 로직
- **통신:**  
  - **프로토콜:** CAN 버스  
  - **역할:** RPi와 TC375 간 제어 명령, 차량 상태, 센서 데이터 교환

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
- **DEBUGINH:** UDE Visual Platform

---

## 📁 리포지토리 구조

```
/
├── .github/           # GitHub Actions (CI/CD)
├── docs/              # 프로젝트 문서 (아키텍처, CAN 프로토콜 등 → Jira Confluence 이용)
├── rpi_ws/            # Raspberry Pi ROS 2 Workspace
├── tc375_fw/          # TC375 Firmware (FreeRTOS)
├── simulink_models/   # MATLAB/Simulink 모델
└── README.md
```

---
