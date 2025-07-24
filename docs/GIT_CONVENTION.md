브랜치 명명 규칙 (Branch Naming Convention)
우리 프로젝트는 Git-Flow의 기본 개념과 Jira 이슈 트래킹을 결합한 명명 규칙을 사용합니다. 모든 작업은 Jira 티켓 생성을 선행하며, 브랜치 이름에는 해당 티켓 번호가 반드시 포함되어야 합니다.

1. 주요 브랜치 (Main Branches)
- main: 최종 배포 버전. 직접적인 커밋은 금지됩니다.
- develop: 개발의 중심이 되는 브랜치. 모든 기능 개발은 이 브랜치에서 분기하여 시작하고, 완료 후 다시 이 브랜치로 병합(Pull Request)됩니다.

2. 보조 브랜치 (Supporting Branches) 패턴
- 모든 브랜치 이름은 소문자를 사용하며, 단어는 **하이픈(-)**으로 연결합니다.
- 가장 일반적으로 사용되는 브랜치 패턴입니다. 새로운 기능을 개발하거나 기존 기능을 개선할 때 사용합니다.
- 패턴: feature/SSP-[Jira-ID]-[short-description]

설명:
- feature/: 브랜치의 목적이 '기능 개발'임을 나타내는 접두사입니다. 슬래시(/)는 Git GUI 툴에서 브랜치를 폴더처럼 그룹화해주는 효과가 있습니다.
- SSP-[Jira-ID]: 이 브랜치가 어떤 Jira 티켓과 관련 있는지 명시합니다. (예: SSP-4)
- [short-description]: 티켓의 내용을 요약하는 2~4개의 영어 단어로 구성된 설명입니다. (예: can-bridge-node)

예시:
- Jira 티켓 SSP-4: "RPi CAN 브리지 노드 구현"
  브랜치 이름: feature/SSP-4-can-bridge-node
- Jira 티켓 SSP-3: "TC375 PID 제어 로직 구현"
  브랜치 이름: feature/SSP-3-pid-controller-logic

develop 브랜치에 병합된 기능에서 버그가 발견되었을 때 사용합니다.
- 패턴: bugfix/SSP-[Jira-ID]-[issue-summary]

예시:
- Jira 티켓 SSP-15: "저속 직진 시 차량이 좌측으로 쏠리는 현상 수정"
  브랜치 이름: bugfix/SSP-15-correct-veering-issue

main 브랜치에 배포된 버전에서 심각한 버그가 발생하여 즉시 수정해야 할 때 사용합니다. main 브랜치에서 직접 분기합니다.
- 패턴: hotfix/SSP-[Jira-ID]-[critical-issue]

예시:
- Jira 티켓 SSP-21: "원격 제어 통신 두절 시 비상 정지 로직 미동작"
  브랜치 이름: hotfix/SSP-21-emergency-stop-failure 