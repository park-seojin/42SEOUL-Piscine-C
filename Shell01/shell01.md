# 42Piscine / Shell01

#### **Exercise 01 : print_groups** 

- 환경변수 FT_USER에 포함된 login이 소속되어 있는 그룹의 목록을 표시하는 명령어를 작성하세요. 공백 없이 쉼표로 분리되어야 합니다.

```
 id -nG $FT_USER | tr ' ' ',' | tr -d '\n'
```



#### **Exercise 02 : find_sh** 

- 현재 디렉토리와 그 하위 디렉토리들에서 파일 이름이 ’.sh’로 끝나는(따옴표 제외) 모 든 파일을 찾는 명령어를 작성하세요. .sh를 제외한 파일 이름만을 표시해야 합니다. 

```
find . -name "*.sh" -type f -exec basename {} .sh \; 
```



#### **Exercise 03 : count_files** 

- 현재 디렉토리 및 그 하위의 모든 디렉토리에 있는 일반 파일 및 디렉토리의 개수를 세어 표시하는 명령어를 작성하세요. 여기에는 시작 디렉토리인 ’.’도 포함되어야 합니다. 

```
find . | wc -l | sed -e 's/^[ \t]*//'
```



#### **Exercise 04 : MAC** 

- 컴퓨터의 MAC 주소를 표시하는 명령어를 작성하세요. 각 주소 다음에는 줄바꿈이 나타나야 합니다. 

```
ifconfig | grep '\tether' | cut -c 8- | tr -d " "
```



#### **Exercise 05 : Can you create it ?** 

- 오직 "42"만 포함하고 그 밖의 어떠한 것도 포함하지 않는 파일을 작성하세요. 

- 파일 이름은 다음과 같아야 합니다: "\?$*'MaRViN'*$?\"

```
Echo -n “42” > [파일이름]
```

개행문자를 제거하고 파일 만드는 문제



#### **Exercise 06 : Skip** 

- ls -l 명령어의 첫 번째 행부터 시작하여 한 줄 걸러 보여주는 명령어를 작성하세요. 

```
ls -l | awk 'NR%2==1 {print}'
```



#### **Exercise 07 : r_dwssap** 

- cat /etc/passwd 명령어의 출력 결과에서 주석은 삭제하고 두 번째 행부터 시작하여 다른 모든 행들은 출력하되, 각 login들 거꾸로 반전시키고 알파벳 역순으로 정렬한 후, FT_LINE1 과 FT_LINE2 을 포함한 그 사이의 값들만 남겨두세요. 이 때, 각 login은 ","로 구분되어야 하며 출력 결과는 "."로 끝나야 합니다.(큰따옴표 없이) 

```
cat /etc/passwd | sed '/#/d' | sed 's/[:].*//' | awk 'NR%2==0' | rev | sort -r | awk '{if(NR>='$FT_LINE1' && NR<='$FT_LINE2’){print}}' | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./' | tr -d '\n'
```



#### **Exercise 08 : add_chelou** 

- ’\"?! 를 밑으로 하는 숫자를 FT_NBR1 에서 가져오고 mrdoc 를 밑으로 하는 숫자를 FT_NBR2 에서 가져온 후, 두 수의 합을 구해 gtaio luSnemf 이 밑인 숫자로 나타내 시오. 

```
echo $FT_NBR1 + $FT_NBR2 | tr "'"'\\"?!mrdoc' '0123401234' | xargs echo "obase=13;ibase=5;" | bc | tr '0123456789ABC' 'gtaio luSnemf'
```

