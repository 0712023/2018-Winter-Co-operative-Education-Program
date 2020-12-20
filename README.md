# Edge X Foundry-Opensource IoT Platform

## Project Synopsis
- 행사명 : 2018년도 동계 현장실습프로그램(Co-operative Education Program, Co-op)
- 주최 : <a href=https://linc.skku.edu/>성균관대학교 LINC+사업단</a>, <a href=http://www.cyberwin.co.kr/>CyberTechFriend</a>
- 진행 기간 : '19.1.2 ~ '19.2.28
- 내용
  - 현장실습프로그램(Co-operative Education Program)은 학교와 기업이 공동으로 산업체 현장에서 필요한 실무교육 및 실습을 실시하는 산학협력 교육과정입니다. 상장기업, 공공기관, 연구기관 등 다양한 기업에서 현업 역량 잠재력이 뛰어난 본교 학생들을 직접 선발하여 지도교수와 함께 기업에서 제시한 다양한 프로젝트를 수행했습니다.
  - 이 프로젝트에서 저는 EdgeX라는 Opensource IoT 플랫폼을 스마트팩토리 솔루션 기업인 CyberTechFriend에서 활용할 수 있는지 연구하는 과제를 수행했습니다. Linux 기반의 운영체제의 노트북에 서버를 설치하고, 라즈베리파이 edge 디바이스에 endpoint SDK 배포를 통해 데이터를 수집 후 DB에 저장하였고, 궁극적으로는 Foolproof 기계를 연결하여 IoT service를 구현해냈습니다.
### Purpose
스마트팩토리의 구축에 필수적인 IoT 플랫폼을 연구하여 기업과 기업을 이어주는 서비스의 필요성이 증가하고 있습니다. 산업현장에는 다양한 디바이스가 사용되고 있고 이 디바이스들을 연결하는 IoT 플랫폼을 통해 그들의 효율적인 관리를 가능하게 합니다. 이를 위해 다양한 Opensource IoT 플랫폼을 사용하고 이에 대한 각각의 기술적 차이 이해 및 이를 이용한 플랫폼 구현이 목표입니다.
### Necessity
일반적인 중소 기업에서 IoT 플랫폼을 도입하는 비용과 그에 대한 제반 시설을 도입하는 과정에서의 인력 수급등에 있어 어려움이 많습니다. 따라서 proprietary IoT 플랫폼이 아닌 Opensource 기반의 IoT 플랫폼을 활용하고 이를 활요하기 위한 지식이 필요합니다. 또한, 이러한 Opensource 플랫폼은 기존의 수요만을 대상으로 하는 플랫폼이 아니라 공급자를 연계할 수 있는 기술 과정이 필요합니다. 따라서 밴더, 모델에 해당하는 스키마를 연구하고 이를 IoT 플랫폼에 누적 시키는 등의 과정을 통해 도입할 필요가 존재합니다. 이러한 과정은 Edge IoT 플랫폼과 Cloud 분석 과정을 도입하여야 가능하고 현 연구의 목표는 Edge 에서의 IoT 플랫폼 연구에 국한하되 Web 표현이 가능하게 하는 것을 목표로 합니다.
### Background Knowledge
- IoT : 사물인터넷 기술은 현재 지속적 성장과 함께 보급, 확산되는 추세입니다. Cisco는 세계사물인터넷 시장이 2022년까지 14조4000억 달러 규모로 성장할 것이라고 예측하였으며 특히 제조업 시장과 관련된 사물인터넷 시장의 규모는 2015년 42억 달러에서 2020년까지 140억 달러 규모로 성장할 것으로 예측되며, 매년 평균 약 27%의 성장률을 보여줄 것으로 전망하였습니다. 현재 제공되고 있는 대다수의 IoT 서비스는 사물이 인터넷에 연결되어 수집된 데이터를 전달해주거나 데이터를 기반으로 사전 설정된 조건에 따라 사용자가 사물을 제어하는 형태입니다. 이러한 IoT 서비스에 적용 가능한 가전, 로봇, 웨어러블 기기 등 다양한 사물이 보급되고 있습니다. 산업 측면의 IoT 인 Industrial IoT의 경우 일반적으로 다양한 기기에서 제공하는 RS485, 232, Modbus 등의 통신 규약에 따른 기존의 데이터를 사물 인터넷 컨버팅 디바이스에 네트워크를 사용하여 Database로 전달하는 것이 일반적인 상황입니다.
중소기업 IT 환경은 일반적으로 시간에 따라 조직 전반에 걸쳐 배치되고 점점 그 네트워크 망의 중요도는 증가되고 있지만 서로 연계되어 있지 않은 경우가 많습니다. 별도의 자동화 시스템으로 구성되어 있어 시설 도처에 고립된 형태로 데이터를 취급하는 형태가 빈번히 발생하게 되고 또 그 고립된 자동화 시스템은 일반적으로 전용 하드웨어에 상주하는 형태여서 개선이 필요한 상황입니다.
- 국내 IoT 기술 개발 현황
    - 국내 IoT 사업체는 1,991개(2016년 기준)이며, 종사자 수 50인 미만의 중·소형 사업체가 80% 이상을 차지하고 있으며 분야별 사업체 수는 서비스 분야가 1,089개 (전체 54.7%)로 가장 많고 그 다음으로 디바이스(24.7%), 네트워크(11.3%), 플랫폼(9.4%) 순서로 조사되고 있습니다.<br>
    - 종사자 규모별 사업체 수는 10 ~ 49인 규모의 사업체가 1,148개(전체 57.7%)로 가장 많고 그 다음으로 1 ~ 9인 규모의 사업체가 472개(전체 23.7%)인 상황이라 기술 개발에 있어서 선진국 대비 부족한 수준을 가지고 있다. 전체적인 기술은 미국 대비 82.9% 수준입니다.  
  
    <p align="center">
    <img src=https://i.imgur.com/rGhWcjI.png><img src=https://i.imgur.com/CdbcF9D.png><br>
	</p>

- 국외 IoT 기술 개발 현황
  - 미국의 사물인터넷 기술 개발 및 투자 현황은 굉장히 활발한 것으로 나타나며, 인텔과 Qualcomm과 같은 대기업들이 가장 활발한 투자를 하고 있으며 많은 벤처 캐피털들의 투자활동도 활발하게 이루어지고 있습니다.<br>

  <p align="center">
  <img src=https://i.imgur.com/8wykhoJ.png><br>
	</p>

### Tools
- Ubuntu Laptop
  - IoT 플랫폼의 server역할을 수행하기 위한 노트북입니다. Server에 main IoT 플랫폼을 설치 후, 이 server에서 수집할 데이터의 타입, 환경변수 등등을 설정한 후 endpoint로 배포할 SDK를 제작했습니다. SDK의 배포는 보통 http post를 활용하여 전달했습니다.
- Raspberry Pi
  - Xenon Foolproof Temperature Request Timer로부터 일정한 주기로 rs485통신을 통해 데이터를 요청하고, 반환받은 데이터를 SDK를 전달받아 설치한 endpoint release를 통해 서버 전달하는 역할을 합니다.
- <a href=http://e-taesung.com/27>SmartQ Foolproof</a>
  - 정해진 통신 프로토콜을 통해 데이터를 반환하는 디바이스입니다.
  - 이 기기에 관한 자세한 내용은 CyberTechFriend에서 진행했던 프리랜서 <a href=https://github.com/CyberTechFriend-Outsourcing-Freelancer/FoolProof>repository</a>에서 확인할 수 있습니다.
- Golang
  - Kaa Opensource IoT 플랫폼에서 endpoint로의 SDK를 배포할 때 개발자가 원하는 로직을 수행하도록 하는 logic을 구현하는 파일인 device.go가 golang으로 프로그래밍되어 있었습니다. 이 파일을 분석하기 위해 개인적으로 golang의 기본적인 코딩 지식을 공부했습니다.
- Python
### IoT Platform
Opensource IoT 플랫폼 으로 Kaa, Thingsboard, Edge X를 비교하였습니다.
- <a href=https://www.kaaproject.org/>Kaa</a><br>
<img src=https://i.imgur.com/iVJLGhB.png width=100><br>
분산 처리 기반 Opensource 플랫폼으로 클러스터로 구성되어 있는 서비스를 기반으로 처리하며 각 End Point 에 대한 SDK를 제공하는 형태로 쉽게 디바이스를 붙일 수 있게 되어 있습니다.
- <a href=https://thingsboard.io/>Thingsboard</a><br>
<img src=https://thingsboard.io/images/thingsboard_logo.png width=150><br>
실시간 데이터에 대한 표현영역에서 강점을 가지는 Opensource IoT 플랫폼 으로서 위젯 형태로 구성된 플랫폼입니다.
- <a href=https://www.edgexfoundry.org/>Edge X Foundry</a><br>
<img src=https://www.pngitem.com/pimgs/m/466-4665404_edgex-foundry-logo-hd-png-download.png width=200><br>
마이크로서비스 기반 분산 처리 되는 형태로 구성되어 있으며 Edge 영역에서의 API를 기반으로한 통신과 데이터 전송을 기반으로 구성되어 있습니다.
### Architecture
- Kaa<br>

<p align="center">
<img src=https://i.imgur.com/FqPAAqF.png><br>
	</p>
  
- Thingsboard<br>

<p align="center">
<img src=https://i.imgur.com/ypql3zk.png width = 500><br>
	</p>
  
- Edge X Foundry<br>

<p align="center">
<img src=https://i.imgur.com/hqLyJrr.png width = 500><br>
	</p>

## Project Details
Kaa, Thingsboard, EdgeX 세 개의 Opensource IoT 플랫폼 중 CyberTechFriend 기업에 가장 적합하다고 판단한 플랫폼은 EdgeX이었습니다.
### Edge X 서버 문서 작성
EdgeX설치 가이드 사이트

1. Docker 및 Docker compose설치

2. https://github.com/edgexfoundry/developer-scripts/raw/master/compose-files/docker-compose-delhi-0.7.1.yml 파일 생성, 이름은 docker-compose.yml 로 저장.

3. 
```bash
docker-compose pull
docker-compose up -d
docker-compose ps
```
차례로 실행하기.

4. docker-compose.yml 에서 device-random 주석 삭제

5. 
```bash
docker-compose up -d device-random
curl http://localhost:48080/api/v1/event/device/Random-Integer-Generator01/10
```
명령어 입력해서 데이터 값 뜨는지 확인.(처음에는 안떳는데 시간이 지나니 되는경우가 있었음)<br>
6. MQTT 브로커 오픈.
```bash
curl -X POST -d '{
    "name":"QuickStartExport",
    "addressable":{
        "name":"HiveMQBroker",
        "protocol":"tcp",
        "address":"broker.hivemq.com",
        "port":1883,
        "publisher":"EdgeXExportPublisher",
        "topic":"EdgeXQuickStartGuide"
    },
    "format":"JSON",
    "filter":{
        "deviceIdentifiers":["Random-Integer-Generator01"]
    },
    "enable":true,
    "destination":"MQTT_TOPIC"
}' http://localhost:48071/api/v1/registration
```
을 터미널 창에 입력 후<br>
```bash
mosquitto_sub -h broker.hivemq.com -p 1883 -t EdgeXQuickStartGuide
```
를 입력후 데이터 오는지 확인,<br>
또한 http://www.hivemq.com/demos/websocket-client/ 에 들어가서<br>
1). connect 열기 <br>
2). subscription에서 add new topic 클릭 <br>
3). Topic을  EdgeXQuickStartGuide 입력하고 Subscribe. <br>
이후 값은 위의 명령어로 입력된 데이터값이 web상에 보이게 됨.

7. device control하기 by command.<br>
```bash
curl http://localhost:48082/api/v1/device/name/Random-Integer-Generator01
```
명령어 창에 입력하면
```json
{
    "created":1544456741615,
    "modified":0,
    "origin":0,
    "id":"5c0e8a259f8fc20001a5d22b",
    "name":"GenerateRandomValue_Int8",
    "get":{
        "path":"/api/v1/device/{deviceId}/GenerateRandomValue_Int8",
        "responses":[
            {
                "code":"200",
                "description":null,
                "expectedValues":["RandomValue_Int8"]
            },
            {
                "code":"503",
                "description":"service unavailable",
                "expectedValues":[]
            }
        ],
        "url":"http://edgex-core-command:48082/api/v1/device/5c0e8a259f8fc20001a5d230/command/5c0e8a259f8fc20001a5d22b"
    },
    "put":{
        "path":"/api/v1/device/{deviceId}/GenerateRandomValue_Int8",
        "responses":[
            {
                "code":"200",
                "description":null,
                "expectedValues":[]
            },
            {
                "code":"503",
                "description":"service unavailable",
                "expectedValues":[]
            }
        ],
        "parameterNames":[
            "Min_Int8",
            "Max_Int8"
        ],
        "url":"http://edgex-core-command:48082/api/v1/device/5c0e8a259f8fc20001a5d230/command/5c0e8a259f8fc20001a5d22b"
    }
}
```
위와같은 형식의 데이터값이 들어오게됨. 또한 위의 ID에 해당하는 value가 아이디 값인데,
```bash
curl http://localhost:48082/api/v1/device/5c0e8a259f8fc20001a5d230/command/5c0e8a259f8fc20001a5d22b
```
위의 명령어에 이전에 얻은 아이디값을 넣은후 명령어를 입력해줘야됨(ID는 기계마다 다를수잇기에 확인해줘야함).
```json
{
    "id":"",
    "pushed":0,
    "device":"Random-Integer-Generator01",
    "created":0,
    "modified":0,
    "origin":1544457033233,
    "schedule":null,
    "event":null,
    "readings":[
        {
            "id":"",
            "pushed":0,
            "created":0,
            "origin":1544457033233,
            "modified":0,
            "device":"Random-Integer-Generator01",
            "name":"RandomValue_Int8",
            "value":"-92"
        }
    ]
}
```
이러면 위의 형식의 데이터가 들어오게됨. 이때의 데이터값은 -128부터 127까지 받아들이게 되며, 최소값과 최대값은 임의로 지정하여서 바꿀수 있음 이의 명령어 아래와 같음.
```bash
curl -X PUT -d '[{"Min_Int8": "0", "Max_Int8": "100"}]' http://localhost:48082/api/v1/device/5c0e8a259f8fc20001a5d230/command/5c0e8a259f8fc20001a5d22b
```
이때 0과 100은 최소값과 최대값을 지정하여서 입력해주면 되며, 위와 마친가지로 빨간색의 ID는 얻은 데이터 기기의 ID를 입력해야함.

Port 별 역할<br>
<p align="center">
<img src=https://i.imgur.com/gVnU7cy.png><br>
	</p>
  
### Edge X 디바이스 영역 문서 작성
*개발 환경 구축을 위해 아래에서 설정하는 환경변수를 고정할 수 있다. 아래 url 참고
http://jinyongjeong.github.io/2016/06/06/bash_shell_environment_variable/

1. golang 설치
```bash
curl -o./go1.11.5.linux-amd64.tar.gz https://dl.google.com/go/go1.11.5.linux-amd64.tar.gz
tar -C $HOME -xzf go1.11.5.linux-amd64.tar.gz
```
라즈베리파이의 경우
```bash
curl -o./go1.11.5.linux-armv6l.tar.gz https://dl.google.com/go/go1.11.5.linux-armv6l.tar.gz
tar -C $HOME -xzf go1.11.5.linux-armv6l.tar.gz
```

⇒ (/usr/local/ 설치시 나중에 관리자권한 문제생김)
```bash
export PATH=$HOME/edgeX/go/bin:$PATH
```
⇒ (환경변수 고정 필요)

-설치 여부 확인
```bash
mkdir $Home/go/src/hello
vim hello.go
```
hello.go
```go
package main
import "fmt"
func main() {
	fmt.Printf("hello, world\n")
}
```
```bash
go build
./hello e
```
⇒ 입력 후 hello, world 뜨는지 확인

- 주의 사항: 설치 후 go version을 입력하면 깔려 있지 않다. 이 경우
```bash
sudo add-apt-repository ppa:longsleep/golang-backports
sudo apt-get update
sudo apt-get install -y golang-go
```
추후 emq 설치 진행과정에서 오류가 생기기 때문에 반드시 1.6 이상의 버전이 필요함.<br>
2. glide 설치 (밑과 다른 참고자료 https://glide.readthedocs.io/en/latest/getting-started/)<br>
GOROOT와 GOPATH는 서로 달라야함. GOROOT는 go 가 설치된 루트로 설정되어있으며, 이에 GOPATH설정을 위해서 새로운 폴더를 만들어준다<br>
현재 만들려는 GO 프로그램의 위치이다.<br>
아래의 경우 $HOME/edgeX/goroad<br>
$ GOPATH 설정 (필요하다면 환경변수 고정)<br>
참고주소 https://medium.com/chequer/goroot%EC%99%80-gopath-77f44cbaa1d8
```bash
export GOPATH=$HOME/edgeX/goroad
mkdir $GOPATH/bin
export PATH=$GOPATH/bin:$PATH
sudo curl https://glide.sh/get | sh
go get github.com/Masterminds/glide
cd $GOPATH/src/github.com/Masterminds/glide
make build
```
이후 glide create 명령어는 SDK 를 생성하고자하는 폴더에 명령어를 넣어줘야됨. 따라서 위의 과정까지만 진행.

glide 사용 명령어
 ```bash
$ glide create                                  
# Start a new workspace
$ open glide.yaml
# and edit away!
$ glide get github.com/Masterminds/cookoo
# Get a package and add to glide.yaml
$ glide install
# Install packages and dependencies
$ go build
# Go tools work normally
$ glide up   
# Update to newest versions of the package
```
3. git
```bash
sudo apt install git-all
git --version
```

4. EdgeX Device SDK for Go 설치
주의) 시작 시 도커 실행시켜줘야 함
```bash
sudo apt install build-essential
mkdir -p $GOPATH/src/github.com/edgexfoundry
cd $GOPATH/src/github.com/edgexfoundry
sudo git clone https://github.com/edgexfoundry/device-sdk-go.git
shdo p
sudo chmod 777 -R .
sudo mv device-sdk-go/ device-simple
cd device-simple/example
sudo mv */ ..
cd ..
grep -irl "device-sdk-go"
find .  -type f | xargs sed -i 's/device-sdk-go/device-simple/g'
cd cmd/device-simple
vim main.go
```
import의
"github.com/edgexfoundry/device-simple/example/driver"를
"github.com/edgexfoundry/device-simple/driver" 로 바꾸기
```bash
cd ../..
vim Makefile		#⇒ 아래와 같이 example 문자열을 제거
cd $GOPATH/src/github.com/edgexfoundry/device-simple
glide create
glide get github.com/Masterminds/cookoo
glide up
glide install
make build
```
이후
https://docs.edgexfoundry.org/Ch-GettingStartedSDK.html 에서
4.3.5. Customize your Device Service 부터 따라한다.

4.3.9  Run your Device Service 실행 확인 시
http://localhost:48080/api/v1/event/device/RandNum-Device01/100 로 확인하여야 한다.


## Review
S-hero 때 스마트팩토리를 주제로 불량품을 검출하는 시스템 구축을 해보았습니다. 라즈베리파이와 아두이노에 연결된 센서의 데이터를 서버로 보내고, 서버에서 다시 컨베이어벨트의 구동과 서보모터의 가동을 하게하는 시스템이 결국 IoT라는 것을 알게 되었고, 그것을 좀더 확장하여 IoT에 대해 배우고자 이렇게 연구를 하게 되었습니다. 하지만 생각과는 달리, IoT 시스템을 구축하는 것은 생각보다 복잡하였고 설명이 부족해서 사용하기에 쉽지 않았습니다. Kaa 플랫폼의 분석을 거의 완료한 시점에 기업의 입장에서 적합하지 않은 플랫폼임을 알게 되고 EdgeX 플랫폼으로 주제를 바꾸게 되면서 난관에 부딪히기도 했습니다.
결과적으로 이러한 어려움을 이겨내고 결국 IoT 플랫폼을 구축하는데 성공했습니다. 데이터의 실시간 전송과 확인, 여러 디바이스의 연결도 가능하게 되었습니다.
현재 4차 산업혁명과 관련하여 IoT 가 떠오르고 있는데 학부생 입장에서 이러한 연구주제를 가지고 직접 IoT를 경험해보았고, 분석&#183;적용해보았다는 점에서 뿌듯하고 이후로 저에게 많은 도움이 된 프로젝트였습니다.
